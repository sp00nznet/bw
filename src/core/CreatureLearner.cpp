// CreatureLearner — translated from runblack_decrypted.exe (v1.0).
// See CreatureLearner.h and work/decomp/creature_learning.md.

#include "black/CreatureLearner.h"

#include <cmath>

namespace creature {

namespace {

// sub_4B9BB0: fldlg2 / fyl2x / fmul 3.3219279368523034. The constant is
// 1/log10(2), so the whole thing is log base 2. Hex-Rays renders this call as a
// discarded result and leaves a stray `frac * frac` behind, which is why it had
// to be read as instructions before anything was built on it.
inline float Log2(float x) { return std::log2(x); }

// sub_4B9B30: which side of zero a feeling falls on. Note >= 0 counts as
// positive, so indifference is filed with approval.
inline uint32_t SignBucket(float weight) { return weight >= 0.0f ? 1u : 0u; }

// -sum p*log2(p) over a set of counts.
float Entropy(const uint32_t* counts, uint32_t n_classes, float total) {
    float e = 0.0f;
    for (uint32_t i = 0; i < n_classes; ++i) {
        const float frac = static_cast<float>(counts[i]) / total;
        if (frac > 0.0f) e -= frac * Log2(frac);
    }
    return e;
}

}  // namespace

// sub_4B99E0
float Impurity(const LearningEpisode* episodes, uint32_t count) {
    if (!episodes || count == 0) return 0.0f;   // flt_7EC2BC

    uint32_t sign_counts[2] = {0, 0};
    uint32_t level_counts[kOpinionLevels] = {0};

    for (uint32_t i = 0; i < count; ++i) {
        ++sign_counts[SignBucket(episodes[i].weight)];
        const int32_t level = OpinionFromMean(episodes[i].weight);
        // The original indexes the level array unguarded, so a weight outside
        // every band would write before it. That cannot happen for weights on
        // [-1, 1] -- the bands span [-1.25, 1.25] -- but a guard costs nothing
        // and a reproduced buffer underflow is worth nothing.
        if (level >= 0 && level < kOpinionLevels) ++level_counts[level];
    }

    const float total = static_cast<float>(count);
    const float sign_entropy  = Entropy(sign_counts, 2, total);
    const float level_entropy = Entropy(level_counts, kOpinionLevels, total);

    // flt_7ED194 = 1/3, applied to (2 * coarse + fine): approving consistently
    // counts for more than agreeing on exactly how much.
    return (sign_entropy * 2.0f + level_entropy) * (1.0f / 3.0f);
}

// sub_4B9820
float GainRatio(const LearningEpisode* episodes, uint32_t count,
                uint32_t feature, uint32_t buckets) {
    const float parent = Impurity(episodes, count);
    // A feature with no buckets cannot partition anything; the original returns
    // the parent impurity undivided.
    if (!episodes || count == 0 || buckets == 0 || feature >= kMaxBeliefAttributes)
        return parent;

    const float total = static_cast<float>(count);
    float weighted = 0.0f;
    float split_info = 0.0f;

    std::vector<LearningEpisode> subset;
    subset.reserve(count);

    for (uint32_t v = 0; v < buckets; ++v) {
        subset.clear();
        for (uint32_t i = 0; i < count; ++i)
            if (episodes[i].features[feature] == v) subset.push_back(episodes[i]);

        const float frac = static_cast<float>(subset.size()) / total;
        weighted += Impurity(subset.data(), static_cast<uint32_t>(subset.size())) * frac;
        if (frac > 0.0f) split_info -= frac * Log2(frac);
    }

    // Clamped up, not down: a split that barely partitions is passed through
    // undiscounted rather than divided by something near zero.
    if (split_info < 1.0f) split_info = 1.0f;
    return (parent - weighted) / split_info;
}

// -------------------------------------------------------------------------
// Induction (sub_4B78F0 / sub_4B81E0)
// -------------------------------------------------------------------------

namespace {

// sub_4B9410's leaf value, over an episode set rather than a linked list.
int32_t LeafOpinion(const LearningEpisode* episodes, uint32_t count) {
    if (!episodes || count == 0) return kOpinionNeutral;
    float sum = 0.0f;
    for (uint32_t i = 0; i < count; ++i) sum += episodes[i].weight;
    const int32_t level = OpinionFromMean(sum / static_cast<float>(count));
    return level >= 0 ? level : kOpinionNeutral;
}

struct Induction {
    DecisionTreeModel*    tree;
    const ATTRIBUTE_TYPE* types;
    uint32_t              type_count;

    // One induction step, recursing into the children it creates. The original
    // drives this from a worklist (`while (node.pending) Step(node)`); the
    // recursion is the same traversal with the stack doing the bookkeeping.
    void Grow(uint32_t node_index, std::vector<LearningEpisode>& episodes,
              uint64_t used_features) {
        DecisionNode& node = tree->nodes[node_index];
        const uint32_t count = static_cast<uint32_t>(episodes.size());
        node.opinion = LeafOpinion(episodes.data(), count);

        if (IsPureEnough(Impurity(episodes.data(), count))) return;

        // sub_4B9490: score every candidate and take the best. A feature already
        // split on higher up cannot partition further, so it is not a candidate.
        int32_t  best_feature = -1;
        float    best_score = 0.0f;
        uint32_t best_buckets = 0;
        for (uint32_t f = 0; f < type_count && f < kMaxBeliefAttributes; ++f) {
            if (used_features & (1ull << f)) continue;
            Attribute* attr = GetAttribute(types[f]);
            const uint32_t buckets = attr ? attr->GetNumValues() : 0;
            if (buckets < 2) continue;
            const float score = GainRatio(episodes.data(), count, f, buckets);
            if (score > best_score) {
                best_score = score;
                best_feature = static_cast<int32_t>(f);
                best_buckets = buckets;
            }
        }

        // sub_4B81E0: no split scores above zero, so stay a leaf.
        if (best_feature < 0) return;

        // Partition before touching tree->nodes: growing the vector can move it.
        std::vector<std::vector<LearningEpisode>> parts(best_buckets);
        for (uint32_t i = 0; i < count; ++i) {
            const uint8_t v = episodes[i].features[best_feature];
            if (v < best_buckets) parts[v].push_back(episodes[i]);
        }

        const uint32_t first = static_cast<uint32_t>(tree->nodes.size());
        tree->nodes.resize(first + best_buckets);
        {
            DecisionNode& self = tree->nodes[node_index];
            self.split_feature = best_feature;
            self.first_child = first;
            self.child_count = best_buckets;
        }

        const uint64_t now_used = used_features | (1ull << best_feature);
        for (uint32_t v = 0; v < best_buckets; ++v) {
            // An empty bucket inherits the parent's opinion, matching the
            // original's walk up the parent chain for a leaf with no episodes.
            if (parts[v].empty()) {
                tree->nodes[first + v].opinion = node_index < tree->nodes.size()
                    ? tree->nodes[node_index].opinion : kOpinionNeutral;
                continue;
            }
            Grow(first + v, parts[v], now_used);
        }
    }
};

}  // namespace

void DecisionTreeModel::Induce(CREATURE_BELIEF_KIND belief_kind,
                               const LearningEpisode* episodes, uint32_t count) {
    kind = belief_kind;
    nodes.clear();
    nodes.resize(1);   // the root

    uint32_t type_count = 0;
    const ATTRIBUTE_TYPE* types = GetBeliefAttributes(belief_kind, type_count);
    if (!types || !episodes || count == 0) {
        nodes[0].opinion = kOpinionNeutral;
        return;
    }

    std::vector<LearningEpisode> all(episodes, episodes + count);
    Induction ind{this, types, type_count};
    ind.Grow(0, all, 0);
}

int32_t DecisionTreeModel::Classify(const uint8_t* features,
                                    uint32_t feature_count) const {
    if (nodes.empty()) return kOpinionNeutral;
    const DecisionNode* node = &nodes[0];
    // The tree is finite and children always live after their parent, so this
    // terminates; the bound is belt and braces against a malformed model.
    for (uint32_t guard = 0; guard < kMaxBeliefAttributes + 1; ++guard) {
        if (node->IsLeaf()) return node->opinion;
        const uint32_t f = static_cast<uint32_t>(node->split_feature);
        if (!features || f >= feature_count) return node->opinion;
        const uint8_t v = features[f];
        if (v >= node->child_count) return node->opinion;
        node = &nodes[node->first_child + v];
    }
    return node->opinion;
}

uint32_t DecisionTreeModel::Depth() const {
    if (nodes.empty()) return 0;
    // Children always follow their parent, so one pass in index order settles
    // every depth before it is needed.
    std::vector<uint32_t> depth(nodes.size(), 0);
    uint32_t deepest = 0;
    for (size_t i = 0; i < nodes.size(); ++i) {
        const DecisionNode& n = nodes[i];
        if (depth[i] > deepest) deepest = depth[i];
        if (n.IsLeaf()) continue;
        for (uint32_t c = 0; c < n.child_count; ++c) {
            const uint32_t ci = n.first_child + c;
            if (ci < depth.size()) depth[ci] = depth[i] + 1;
        }
    }
    return deepest;
}

}  // namespace creature
