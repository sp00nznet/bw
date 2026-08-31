// test_attribute — the creature's world-description vocabulary.
//
// The schema (names, ids, bucket counts) is generated from the binary and
// cross-checked against the CC0 chlasm enum, so what this checks is the part
// that could still be wrong: that the registry is complete and consistent, that
// the shared clamp saturates instead of wrapping, and that each recovered
// threshold falls where the binary puts it.

#include <black/Attribute.h>

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

// Evaluate needs a non-null object to get past the guards; the stubbed
// attributes never dereference it.
static GameThingWithPos* FakeObj() {
    static char storage[64] = {0};
    return reinterpret_cast<GameThingWithPos*>(storage);
}

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

    GameThingWithPos* obj = FakeObj();

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

    printf(g_fail ? "\n%d FAILURE(S)\n" : "\nALL PASS\n", g_fail);
    return g_fail ? 1 : 0;
}
