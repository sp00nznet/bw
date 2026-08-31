// test_attribute — the creature's world-description vocabulary.
//
// The schema (names, ids, bucket counts) is generated from the binary and
// cross-checked against the CC0 chlasm enum, so what this checks is the part
// that could still be wrong: that the registry is complete and consistent, that
// the shared clamp saturates instead of wrapping, and that each recovered
// threshold falls where the binary puts it.

#include <black/Attribute.h>
#include <black/GameThingWithPos.h>
#include <black/CreatureBeliefAttributes.h>
#include <black/CreatureOpinion.h>

#include <cmath>
#include <cstdio>
#include <cstring>

static int g_fail = 0;
#define CHECK(cond, msg) do { if (!(cond)) { printf("FAIL: %s\n", msg); ++g_fail; } \
                              else printf("ok  : %s\n", msg); } while (0)

// The attributes that need subsystems core does not model reach them through
// AttributeWorld; these stubs stand in so the thresholds can be exercised.
static uint32_t g_forest = 0, g_town_pop = 0, g_carrying = 29;
static float    g_belief = 0.0f;

static uint32_t ForestSize(const GameThingWithPos*) { return g_forest; }
static uint32_t TownPop(const GameThingWithPos*) { return g_town_pop; }
static uint32_t Carrying(const Creature*) { return g_carrying; }
static float    Belief(const GameThingWithPos*, const Creature*) { return g_belief; }

// A real object, not a cast buffer: DescribeObject runs every attribute in a
// vector and several of them make virtual calls on their subject, so the test
// subject needs an actual vtable. GameThingWithPos has no pure virtuals, so it
// stands in directly.
struct TestThing : GameThingWithPos {};

int main() {
    // --- registry -----------------------------------------------------------
    int found = 0, concrete = 0;
    bool ids_match = true, names_present = true;
    for (uint32_t i = 0; i < _ATTRIBUTE_TYPE_COUNT; ++i) {
        Attribute* a = GetAttribute(static_cast<ATTRIBUTE_TYPE>(i));
        if (!a) continue;
        ++found;
        if (a->GetAttributeType() != static_cast<ATTRIBUTE_TYPE>(i)) ids_match = false;
        if (!a->GetName() || !*a->GetName()) names_present = false;
        if (a->IsConcrete()) ++concrete;
    }
    CHECK(found == 23, "every ATTRIBUTE_TYPE resolves to an attribute");
    CHECK(ids_match, "each attribute reports the id it is registered under");
    CHECK(names_present, "each attribute has a name");
    CHECK(concrete == 13, "13 of the 23 are ones the decision trees branch on");
    CHECK(GetAttribute(static_cast<ATTRIBUTE_TYPE>(_ATTRIBUTE_TYPE_COUNT)) == nullptr,
          "the error id resolves to nothing");

    // Bucket counts are what the trees index by, so a zero would silently
    // collapse an attribute to one branch.
    bool buckets_ok = true;
    for (uint32_t i = 0; i < _ATTRIBUTE_TYPE_COUNT; ++i) {
        Attribute* a = GetAttribute(static_cast<ATTRIBUTE_TYPE>(i));
        if (a && a->GetNumValues() == 0) buckets_ok = false;
    }
    CHECK(buckets_ok, "no attribute has zero buckets");

    // Spot-check the schema against the binary's constant slots.
    CHECK(!std::strcmp(GetAttribute(ATTRIBUTE_TYPE_LIFE)->GetName(), "Life"),
          "id 7 is Life");
    CHECK(GetAttribute(ATTRIBUTE_TYPE_LIFE)->GetNumValues() == 2, "Life has 2 buckets");
    CHECK(GetAttribute(ATTRIBUTE_TYPE_CREATURE_DOMINANT_DESIRE)->GetNumValues() == 41,
          "dominant-desire has a bucket per desire plus the invalid one");
    CHECK(GetAttribute(ATTRIBUTE_TYPE_CREATURE_CARRYING)->GetNumValues() == 45,
          "carrying has 45 buckets");
    CHECK(!GetAttribute(ATTRIBUTE_TYPE_SEX)->IsConcrete(),
          "Sex is not one the trees branch on");
    CHECK(GetAttribute(ATTRIBUTE_TYPE_ABODE_ON_FIRE)->IsConcrete(),
          "OnFire is");

    AttributeWorld w;
    w.forest_size = ForestSize;
    w.town_population = TownPop;
    w.creature_carrying = Carrying;
    w.town_belief_in = Belief;
    SetAttributeWorld(w);

    TestThing thing;
    GameThingWithPos* obj = &thing;

    // --- the clamp ----------------------------------------------------------
    // A feature bigger than the bucket count must saturate; wrapping would send
    // the tree down an unrelated branch.
    Attribute* forest = GetAttribute(ATTRIBUTE_TYPE_FOREST_SIZE);
    g_forest = 1000;
    CHECK(forest->Evaluate(obj, nullptr) == 2,
          "an out-of-range feature saturates at the last bucket");
    CHECK(forest->value == 2, "and is left in the attribute's value field");

    // --- recovered thresholds ----------------------------------------------
    // Forest: 10 and 20.
    g_forest = 0;  CHECK(forest->Evaluate(obj, nullptr) == 0, "0 trees is a small forest");
    g_forest = 9;  CHECK(forest->Evaluate(obj, nullptr) == 0, "9 trees is still small");
    g_forest = 10; CHECK(forest->Evaluate(obj, nullptr) == 1, "10 trees is medium");
    g_forest = 19; CHECK(forest->Evaluate(obj, nullptr) == 1, "19 is still medium");
    g_forest = 20; CHECK(forest->Evaluate(obj, nullptr) == 2, "20 trees is a big forest");

    // Town: 20 and 40.
    Attribute* town = GetAttribute(ATTRIBUTE_TYPE_TOWN_SIZE);
    g_town_pop = 19; CHECK(town->Evaluate(obj, nullptr) == 0, "19 is a small town");
    g_town_pop = 20; CHECK(town->Evaluate(obj, nullptr) == 1, "20 is a medium town");
    g_town_pop = 39; CHECK(town->Evaluate(obj, nullptr) == 1, "39 is still medium");
    g_town_pop = 40; CHECK(town->Evaluate(obj, nullptr) == 2, "40 is a big town");

    // Belief: 0.2 / 0.4 / 0.6. Needs an observer, so the guard is exercised too.
    Attribute* belief = GetAttribute(ATTRIBUTE_TYPE_RELIGIOUS_BELIEF_IN_YOU);
    Creature* observer = reinterpret_cast<Creature*>(1);   // only compared, never read
    g_belief = 0.0f;  CHECK(belief->Evaluate(obj, observer) == 0, "no belief is bucket 0");
    g_belief = 0.19f; CHECK(belief->Evaluate(obj, observer) == 0, "just under 0.2 is still 0");
    g_belief = 0.2f;  CHECK(belief->Evaluate(obj, observer) == 1, "0.2 crosses into bucket 1");
    g_belief = 0.4f;  CHECK(belief->Evaluate(obj, observer) == 2, "0.4 crosses into bucket 2");
    g_belief = 0.6f;  CHECK(belief->Evaluate(obj, observer) == 3, "0.6 crosses into bucket 3");
    g_belief = 1.0f;  CHECK(belief->Evaluate(obj, observer) == 3, "full belief stays at 3");
    CHECK(belief->Evaluate(obj, nullptr) == 0,
          "with no observer there is nobody to believe in, so bucket 0");

    // Carrying: empty hands is bucket 29, a real entry rather than a sentinel.
    Attribute* carrying = GetAttribute(ATTRIBUTE_TYPE_CREATURE_CARRYING);
    CHECK(carrying->Evaluate(nullptr, nullptr) == 29,
          "a creature with nothing in its hands reads as bucket 29");

    // --- unsupplied hooks ---------------------------------------------------
    // With no world installed the attributes must report their zero bucket
    // rather than dereferencing a null hook.
    AttributeWorld empty;
    SetAttributeWorld(empty);
    bool safe = true;
    for (uint32_t i = 0; i < _ATTRIBUTE_TYPE_COUNT; ++i) {
        Attribute* a = GetAttribute(static_cast<ATTRIBUTE_TYPE>(i));
        if (!a) continue;
        const uint32_t v = a->Evaluate(nullptr, nullptr);
        if (v >= a->GetNumValues()) safe = false;
    }
    CHECK(safe, "with no world and no object, every attribute stays in range");

    // --- belief feature vectors ---------------------------------------------
    // Each kind of belief describes its subject with a fixed ordered list. That
    // list is the limit of what the creature can ever learn to tell apart.
    SetAttributeWorld(w);

    uint32_t n = 0;
    const ATTRIBUTE_TYPE* v = GetBeliefAttributes(CREATURE_BELIEF_BASE, n);
    CHECK(v && n == 7, "the common vector is the seven from the base builder");
    CHECK(v[0] == ATTRIBUTE_TYPE_ALLEGIANCE && v[6] == ATTRIBUTE_TYPE_TYPE,
          "and is in the order the builder installs them");

    bool prefix_ok = true;
    for (uint32_t k = 0; k < _CREATURE_BELIEF_KIND_COUNT; ++k) {
        uint32_t kn = 0;
        const ATTRIBUTE_TYPE* kv =
            GetBeliefAttributes(static_cast<CREATURE_BELIEF_KIND>(k), kn);
        if (!kv || kn < 7) { prefix_ok = false; continue; }
        for (uint32_t i = 0; i < 7; ++i)
            if (kv[i] != v[i]) prefix_ok = false;
    }
    CHECK(prefix_ok, "every belief kind opens with the common seven");

    v = GetBeliefAttributes(CREATURE_BELIEF_ABODE, n);
    CHECK(n == 11 && v[7] == ATTRIBUTE_TYPE_ABODE_TYPE &&
          v[8] == ATTRIBUTE_TYPE_LIFE && v[9] == ATTRIBUTE_TYPE_ABODE_ON_FIRE &&
          v[10] == ATTRIBUTE_TYPE_ABODE_BEING_BUILT,
          "an abode belief adds type, life, fire and under-construction");

    v = GetBeliefAttributes(CREATURE_BELIEF_TOWN, n);
    CHECK(n == 11 && v[7] == ATTRIBUTE_TYPE_RELIGIOUS_BELIEF_IN_YOU &&
          v[10] == ATTRIBUTE_TYPE_TRIBE,
          "a town belief adds belief-in-you first and tribe last");

    v = GetBeliefAttributes(CREATURE_BELIEF_FOREST, n);
    CHECK(n == 8 && v[7] == ATTRIBUTE_TYPE_FOREST_SIZE,
          "a forest belief adds only its size");

    v = GetBeliefAttributes(CREATURE_BELIEF_CITADEL, n);
    CHECK(n == 7, "citadel, context and flock beliefs add nothing");

    v = GetBeliefAttributes(CREATURE_BELIEF_VILLAGER, n);
    CHECK(n == 11 && v[7] == ATTRIBUTE_TYPE_SEX &&
          v[8] == ATTRIBUTE_TYPE_VILLAGER_JOB,
          "a villager belief adds sex and job");

    // The asymmetry is the point: a creature can learn about a burning house
    // because OnFire is in the abode vector, and can never learn anything about
    // a burning forest, because it is not in the forest one.
    bool abode_has_fire = false, forest_has_fire = false;
    v = GetBeliefAttributes(CREATURE_BELIEF_ABODE, n);
    for (uint32_t i = 0; i < n; ++i)
        if (v[i] == ATTRIBUTE_TYPE_ABODE_ON_FIRE) abode_has_fire = true;
    v = GetBeliefAttributes(CREATURE_BELIEF_FOREST, n);
    for (uint32_t i = 0; i < n; ++i)
        if (v[i] == ATTRIBUTE_TYPE_ABODE_ON_FIRE) forest_has_fire = true;
    CHECK(abode_has_fire && !forest_has_fire,
          "fire is describable on an abode but not on a forest");

    CHECK(GetBeliefAttributes(
              static_cast<CREATURE_BELIEF_KIND>(_CREATURE_BELIEF_KIND_COUNT), n) == nullptr,
          "an unknown belief kind has no vector");
    CHECK(n == 0, "and reports zero length");

    // --- describing an object ------------------------------------------------
    g_forest = 25;
    uint8_t vec[kMaxBeliefAttributes] = {0};
    const uint32_t wrote = DescribeObject(CREATURE_BELIEF_FOREST, obj, nullptr,
                                          vec, kMaxBeliefAttributes);
    CHECK(wrote == 8, "describing a forest fills the whole vector");
    CHECK(vec[7] == 2, "and the forest-size slot carries its bucket");

    uint8_t small[3] = {0, 0, 0};
    CHECK(DescribeObject(CREATURE_BELIEF_TOWN, obj, nullptr, small, 3) == 3,
          "a short buffer is filled to capacity, not overrun");
    CHECK(DescribeObject(CREATURE_BELIEF_TOWN, obj, nullptr, nullptr, 8) == 0,
          "no buffer means nothing written");

    bool in_range = true;
    for (uint32_t k = 0; k < _CREATURE_BELIEF_KIND_COUNT; ++k) {
        uint8_t buf[kMaxBeliefAttributes] = {0};
        const uint32_t got = DescribeObject(static_cast<CREATURE_BELIEF_KIND>(k),
                                            obj, nullptr, buf, kMaxBeliefAttributes);
        uint32_t kn = 0;
        const ATTRIBUTE_TYPE* kv =
            GetBeliefAttributes(static_cast<CREATURE_BELIEF_KIND>(k), kn);
        for (uint32_t i = 0; i < got; ++i) {
            Attribute* a = GetAttribute(kv[i]);
            if (a && buf[i] >= a->GetNumValues()) in_range = false;
        }
    }
    CHECK(in_range, "every feature in every vector is a valid bucket for its attribute");

    // --- the opinion scale ---------------------------------------------------
    // Everything a creature learns ends up as one of eleven levels from -1 to
    // +1. The table came out of .rdata; these check the parts of its behaviour
    // that reading the code alone would have got wrong.
    using namespace creature;

    CHECK(kOpinionLevels == 11, "eleven levels");
    CHECK(OpinionValue(kOpinionNeutral) == 0.0f, "the neutral level is zero");
    CHECK(OpinionValue(0) == -1.0f && OpinionValue(10) == 1.0f,
          "the scale runs from -1 to +1");
    CHECK(OpinionValue(-1) == 0.0f && OpinionValue(99) == 0.0f,
          "an out-of-range level reads as zero rather than off the end");

    bool spacing_ok = true;
    for (int32_t i = 1; i < kOpinionLevels; ++i)
        if (std::fabs((OpinionValue(i) - OpinionValue(i - 1)) - 0.2f) > 1e-5f)
            spacing_ok = false;
    CHECK(spacing_ok, "levels are 0.2 apart");

    CHECK(OpinionFromMean(-1.0f) == 0, "a mean at the bottom of the scale");

    // The tolerance is 0.25 against a 0.2 spacing, so bands overlap and the
    // scan from the most negative upward decides. That biases every opinion one
    // step down -- dead-centre reads as slightly negative.
    CHECK(OpinionFromMean(0.0f) == 4,
          "a neutral mean resolves down to -0.2, because that band reaches it first");
    CHECK(OpinionFromMean(0.1f) == 5, "and 0.1 resolves down to 0.0");
    CHECK(OpinionFromMean(1.0f) == 9, "a mean at the top of the scale reads as +0.8");

    // Level 10 needs a mean above 1.05 and weights live on [-1, 1], so nothing
    // a creature can experience ever reaches it.
    bool top_reachable = false;
    for (int i = -100; i <= 100; ++i)
        if (OpinionFromMean(i / 100.0f) == 10) top_reachable = true;
    CHECK(!top_reachable,
          "the top level is unreachable: a creature never quite loves anything");
    CHECK(OpinionFromMean(1.1f) == 10, "only an out-of-range mean would reach it");

    CHECK(OpinionFromMean(5.0f) == kOpinionNone, "far off the scale matches nothing");
    CHECK(OpinionFromMean(-5.0f) == kOpinionNone, "in both directions");

    CHECK(OpinionFromEpisodes(nullptr, 0) == kOpinionNeutral,
          "no evidence at all means no view either way");
    const float liked[] = {1.0f, 1.0f, 1.0f};
    CHECK(OpinionFromEpisodes(liked, 3) == kOpinionMaxReachable,
          "consistent strong approval reads as high as the scale permits");
    const float mixed[] = {1.0f, -1.0f};
    CHECK(OpinionFromEpisodes(mixed, 2) == 4,
          "approval and disapproval in equal measure cancel to the middle band");

    CHECK(kInitialLessonWeight == 0.8f,
          "a creature's innate lessons start weighted near the top, not blank");

    printf(g_fail ? "\n%d FAILURE(S)\n" : "\nALL PASS\n", g_fail);
    return g_fail ? 1 : 0;
}
