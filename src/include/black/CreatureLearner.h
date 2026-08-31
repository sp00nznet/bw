#pragma once
// CreatureLearner — the creature's decision-tree induction.
//
// This is how a Black & White creature actually learns: it keeps episodes
// (what it saw, described as a feature vector, and how it felt about it) and
// periodically re-induces a decision tree over them, greedily, by gain ratio.
// C4.5, in 1999, per creature, at runtime.
//
// Not to be confused with `CreatureLearning` in CreatureLearning.h, which is
// the vendor struct for the 0x16168 learning block inside CreatureMental --
// the storage. This is the algorithm that runs over it.
//
// Translated from runblack_decrypted.exe (v1.0). Every constant here was read
// out of the binary rather than inferred -- see work/decomp/creature_learning.md
// for the trail, including the two places where reasoning from the Hex-Rays
// pseudocode alone gives the wrong answer:
//
//   sub_4B99E0  impurity      (2*sign entropy + level entropy) / 3
//   sub_4B9820  split score   gain ratio, divisor clamped to >= 1
//   sub_4B9BB0  log base 2    fldlg2/fyl2x * 3.3219279 -- Hex-Rays renders this
//                             as a discarded call and a stray square
//   sub_4B93F0  stop test     impurity < 0.01
//   sub_4B9410  leaf value    mean the weights, bucket onto the opinion scale
//
// What is ours rather than the binary's: the node representation. The original
// keeps a 148-byte node whose expansion path (sub_4B7E00 / sub_4B7D80) is not
// yet recovered, so the tree is stored here in the shape that suits us. The
// arithmetic, the ordering and the stopping rules are the binary's exactly,
// which is what decides how a creature behaves.

#include "Attribute.h"
#include "CreatureBeliefAttributes.h"
#include "CreatureOpinion.h"

#include <cstdint>
#include <vector>

namespace creature {

// One piece of evidence. `features` is the belief's attribute vector as
// produced by DescribeObject; `weight` is how the creature felt about it, on
// the same -1..+1 scale opinions live on.
struct LearningEpisode {
    uint8_t features[kMaxBeliefAttributes] = {0};
    float   weight = 0.0f;
};

// Impurity of a set of episodes (sub_4B99E0).
//
// Two entropies, blended: one over whether the creature liked the thing at all
// (two classes), one over exactly how much (the eleven opinion levels). The
// coarse like/dislike split counts double, so a creature that consistently
// approves scores as fairly pure even when it cannot agree with itself on how
// strongly. An empty set is 0.
float Impurity(const LearningEpisode* episodes, uint32_t count);

// Gain ratio for splitting `episodes` on one feature (sub_4B9820).
//
// (parent impurity - sum over buckets of frac * child impurity) / split info,
// where split info is the usual -sum frac*log2(frac) and the divisor is clamped
// up to 1.0 -- so a split that partitions barely at all has its gain passed
// through undiscounted rather than divided by something near zero.
float GainRatio(const LearningEpisode* episodes, uint32_t count,
                uint32_t feature, uint32_t buckets);

// sub_4B93F0: a branch stops growing once its impurity falls under a hundredth.
constexpr float kPurityThreshold = 0.01f;
inline bool IsPureEnough(float impurity) { return impurity < kPurityThreshold; }

// A node in an induced tree. Leaves carry an opinion level; branches carry the
// feature they split on and one child per bucket of that feature.
struct DecisionNode {
    int32_t  split_feature = -1;   // index into the belief's attribute vector; -1 = leaf
    int32_t  opinion = kOpinionNeutral;
    uint32_t first_child = 0;      // index into DecisionTreeModel::nodes
    uint32_t child_count = 0;

    bool IsLeaf() const { return split_feature < 0; }
};

// A tree induced over one belief kind's attribute vector.
struct DecisionTreeModel {
    CREATURE_BELIEF_KIND      kind = CREATURE_BELIEF_BASE;
    std::vector<DecisionNode> nodes;

    // Re-induce from scratch over `episodes`. The original rebuilds rather than
    // updating incrementally too (sub_4B78F0 allocates a fresh root each time).
    void Induce(CREATURE_BELIEF_KIND belief_kind,
                const LearningEpisode* episodes, uint32_t count);

    // Walk to a leaf and report its opinion. An unbuilt tree is neutral.
    int32_t Classify(const uint8_t* features, uint32_t feature_count) const;

    // How deep the induced tree got -- 0 for a single leaf. Useful for seeing
    // whether a creature has formed real distinctions or just an average.
    uint32_t Depth() const;
};

}  // namespace creature
