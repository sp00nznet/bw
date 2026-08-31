// test_learning — the creature's decision-tree induction.
//
// The constants are the binary's and were read rather than inferred, so what
// this checks is that the machinery built on them behaves like learning:
// consistent evidence produces a confident opinion, contradictory evidence
// produces a split on the feature that actually explains the contradiction, and
// noise produces no split at all.

#include <black/CreatureLearner.h>

#include <cmath>
#include <cstdio>
#include <cstring>

using namespace creature;

static int g_fail = 0;
#define CHECK(cond, msg) do { if (!(cond)) { printf("FAIL: %s\n", msg); ++g_fail; } \
                              else printf("ok  : %s\n", msg); } while (0)

static bool Near(float a, float b, float eps = 1e-4f) { return std::fabs(a - b) < eps; }

// Feature 9 of the abode vector is OnFire (0/1); feature 7 is AbodeType.
enum : uint32_t { kFire = 9, kAbodeType = 7 };

static LearningEpisode Ep(uint8_t fire, float weight, uint8_t abode_type = 0) {
    LearningEpisode e;
    e.features[kFire] = fire;
    e.features[kAbodeType] = abode_type;
    e.weight = weight;
    return e;
}

int main() {
    // --- impurity -----------------------------------------------------------
    CHECK(Impurity(nullptr, 0) == 0.0f, "no evidence has no impurity");

    LearningEpisode same[4] = {Ep(0, 1.0f), Ep(0, 1.0f), Ep(0, 1.0f), Ep(0, 1.0f)};
    CHECK(Near(Impurity(same, 4), 0.0f), "evidence that all agrees is perfectly pure");
    CHECK(IsPureEnough(Impurity(same, 4)), "and pure enough to stop splitting");

    // One episode on each side of zero: the sign entropy is a full bit, and the
    // level entropy is a full bit too (two distinct levels), so the blend is
    // (2*1 + 1)/3 = 1.
    LearningEpisode split_evidence[2] = {Ep(0, 1.0f), Ep(0, -1.0f)};
    CHECK(Near(Impurity(split_evidence, 2), 1.0f),
          "flat disagreement scores exactly 1 under the 2:1 blend");
    CHECK(!IsPureEnough(Impurity(split_evidence, 2)), "and is not pure enough to stop");

    // Same feeling, different intensity: the coarse split is pure, only the
    // fine one is not. That is what weighting like/dislike double buys.
    LearningEpisode agree_ish[2] = {Ep(0, 1.0f), Ep(0, 0.4f)};
    const float mild = Impurity(agree_ish, 2);
    CHECK(mild > 0.0f && mild < Impurity(split_evidence, 2),
          "agreeing on the direction but not the degree is much purer than disagreeing");
    CHECK(Near(mild, 1.0f / 3.0f),
          "exactly a third: one bit of fine entropy, no coarse entropy, over three");

    // --- gain ratio ---------------------------------------------------------
    // Evidence that OnFire explains completely: burning houses are hated,
    // intact ones are liked.
    LearningEpisode explained[8] = {
        Ep(1, -1.0f), Ep(1, -1.0f), Ep(1, -1.0f), Ep(1, -1.0f),
        Ep(0,  1.0f), Ep(0,  1.0f), Ep(0,  1.0f), Ep(0,  1.0f),
    };
    const float fire_gain = GainRatio(explained, 8, kFire, 2);
    CHECK(fire_gain > 0.9f, "a feature that explains the split scores near the full gain");

    // A feature that is constant across the same evidence explains nothing.
    const float type_gain = GainRatio(explained, 8, kAbodeType, 24);
    CHECK(Near(type_gain, 0.0f),
          "a feature that never varies scores no gain at all");
    CHECK(fire_gain > type_gain, "so the explaining feature wins the split");

    CHECK(Near(GainRatio(explained, 8, kFire, 0), Impurity(explained, 8)),
          "a feature with no buckets returns the parent impurity undivided");

    // --- induction ----------------------------------------------------------
    DecisionTreeModel tree;

    tree.Induce(CREATURE_BELIEF_ABODE, same, 4);
    CHECK(tree.Depth() == 0, "evidence that all agrees induces a single leaf");
    CHECK(tree.nodes.size() == 1, "with no children");
    uint8_t probe[kMaxBeliefAttributes] = {0};
    CHECK(tree.Classify(probe, kMaxBeliefAttributes) == OpinionFromMean(1.0f),
          "and that leaf carries the opinion the evidence averages to");

    // The interesting case: the creature is shown burning and intact houses and
    // has opposite feelings about them. It should discover OnFire.
    tree.Induce(CREATURE_BELIEF_ABODE, explained, 8);
    CHECK(tree.Depth() >= 1, "contradictory evidence induces a split");
    CHECK(!tree.nodes[0].IsLeaf(), "the root is a branch");
    CHECK(tree.nodes[0].split_feature == static_cast<int32_t>(kFire),
          "and it split on OnFire -- the feature that explains the contradiction");

    uint8_t burning[kMaxBeliefAttributes] = {0};
    burning[kFire] = 1;
    uint8_t intact[kMaxBeliefAttributes] = {0};
    const int32_t on_fire_opinion = tree.Classify(burning, kMaxBeliefAttributes);
    const int32_t intact_opinion  = tree.Classify(intact, kMaxBeliefAttributes);
    CHECK(on_fire_opinion < kOpinionNeutral, "the creature now dislikes burning houses");
    CHECK(intact_opinion > on_fire_opinion, "and prefers intact ones");
    CHECK(OpinionValue(on_fire_opinion) < 0.0f && OpinionValue(intact_opinion) > 0.0f,
          "the two opinions land on opposite sides of neutral");

    // Evidence with no pattern: the same feature values, contradictory feelings.
    // There is nothing to split on, so the creature should form no distinction.
    LearningEpisode noise[6] = {
        Ep(0, 1.0f), Ep(0, -1.0f), Ep(0, 1.0f),
        Ep(0, -1.0f), Ep(0, 1.0f), Ep(0, -1.0f),
    };
    tree.Induce(CREATURE_BELIEF_ABODE, noise, 6);
    CHECK(tree.Depth() == 0,
          "evidence with no explaining feature induces no split, however impure");

    // No evidence at all.
    tree.Induce(CREATURE_BELIEF_ABODE, nullptr, 0);
    CHECK(tree.Classify(probe, kMaxBeliefAttributes) == kOpinionNeutral,
          "a creature that has seen nothing has no opinion");

    // --- classification robustness ------------------------------------------
    tree.Induce(CREATURE_BELIEF_ABODE, explained, 8);
    CHECK(tree.Classify(nullptr, 0) == tree.nodes[0].opinion,
          "classifying without a feature vector falls back to the node's own view");
    uint8_t out_of_range[kMaxBeliefAttributes] = {0};
    out_of_range[kFire] = 200;   // past the feature's bucket count
    const int32_t r = tree.Classify(out_of_range, kMaxBeliefAttributes);
    CHECK(r >= 0 && r < kOpinionLevels,
          "an out-of-range feature value still yields a valid opinion");

    DecisionTreeModel empty;
    CHECK(empty.Classify(probe, kMaxBeliefAttributes) == kOpinionNeutral,
          "an uninduced tree is neutral");
    CHECK(empty.Depth() == 0, "and has no depth");

    printf(g_fail ? "\n%d FAILURE(S)\n" : "\nALL PASS\n", g_fail);
    return g_fail ? 1 : 0;
}
