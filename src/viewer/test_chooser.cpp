// test_chooser — the creature's plan chooser on the shipped tables: a hungry
// creature at a storage pit eats from it, a curious one looks at a tree, anger at a villager picks a way to
// hurt it (and an object to hurt it with), leashing rules out what is too far,
// compassion for a town reads the town's own action table. Needs info.dat.
#include <black/CreaturePlanChooser.h>
#include <black/InfoDat.h>
#include <black/Abode.h>
#include <black/BigForest.h>
#include <black/Bonfire.h>
#include <black/Animal.h>
#include <black/Citadel.h>
#include <black/Flock.h>
#include <black/Forest.h>
#include <black/Creature.h>
#include <black/CreatureDispatch.gen.h>
#include <black/CreatureLearner.h>
#include <black/CreatureActionValidity.h>
#include <black/CreatureBody.h>
#include <black/Sigmoid.h>
#include <black/Feature.h>
#include <black/Field.h>
#include <black/FishFarm.h>
#include <black/Rock.h>
#include <black/StoragePit.h>
#include <black/TownCentre.h>
#include <black/Tree.h>
#include <black/Villager.h>

#include "PredicateTable.gen.h"

#include <excpt.h>
#include <functional>
#include <map>

#include <cmath>
#include <cstdio>
#include <filesystem>
#include <set>
#include <string>

using namespace creature;

static int g_fail = 0;
#define CHECK(cond, msg) do { if (!(cond)) { printf("FAIL: %s\n", msg); ++g_fail; } \
                              else printf("ok  : %s\n", msg); } while (0)

enum : uint32_t { kVillager = 1, kTree = 2, kPit = 3, kTown = 5 };
enum : uint32_t { kHunger = 4, kAnger = 2, kCompassion = 1, kCuriosity = 6 };

// Slot 67 is GetCreatureBeliefType (a number, not a predicate).
// -1 if the predicate faulted (our body reads something an empty object lacks).
static int Ask(GameThingWithPos* o, Creature* c, int slot) {
    __try {
        if (slot == 67) return static_cast<int>(o->GetCreatureBeliefType());
        return CallObjectPredicate(o, c, slot) ? 1 : 0;
    } __except (EXCEPTION_EXECUTE_HANDLER) {
        return -1;
    }
}

// Every constant answer the binary gives for these classes' chooser predicates,
// checked against ours. Code-bodied predicates are counted, not checked.
static void CheckPredicateTable() {
    static Creature creature;
    const std::map<std::string, std::function<GameThingWithPos*()>> make = {
        {"Villager", [] { return new Villager(); }},   {"Abode", [] { return new Abode(); }},
        {"StoragePit", [] { return new StoragePit(); }}, {"TownCentre", [] { return new TownCentre(); }},
        {"Tree", [] { return new Tree(); }},           {"Field", [] { return new Field(); }},
        {"FishFarm", [] { return new FishFarm(); }},   {"Rock", [] { return new Rock(); }},
        {"BigForest", [] { return new BigForest(); }}, {"Creature", [] { return new Creature(); }},
        {"Bonfire", [] { return new Bonfire(); }},     {"Feature", [] { return new Feature(); }},
        {"Forest", [] { return new Forest(); }},       {"Citadel", [] { return new Citadel(); }},
        {"Flock", [] { return new Flock(); }},         {"Animal", [] { return new Animal(); }}};
    std::map<std::string, GameThingWithPos*> objs;
    int checked = 0, wrong = 0, code = 0;
    std::string bad;
    for (const PredicateRow& r : kPredicateTable) {
        if (r.value < 0) { ++code; continue; }
        GameThingWithPos*& o = objs[r.cls];
        if (!o) o = make.at(r.cls)();
        ++checked;
        const int got = Ask(o, &creature, r.slot);
        if (got != r.value) {
            ++wrong;
            char b[96];
            std::snprintf(b, sizeof b, "\n      %s slot %d: binary %d, ours %d", r.cls, r.slot, r.value, got);
            bad += b;
        }
    }
    char msg[160];
    std::snprintf(msg, sizeof msg, "predicates: %d constant answers across %zu classes match the binary (%d code-bodied not checked)",
                  checked - wrong, make.size(), code);
    if (wrong) printf("%s\n", bad.c_str());
    CHECK(wrong == 0, msg);
}

int main() {
    CheckPredicateTable();

    std::string path;
    for (const char* r : {"game_data/", "../game_data/", "../../game_data/", "../../../game_data/"})
        if (std::filesystem::exists(std::string(r) + "info.dat")) { path = std::string(r) + "info.dat"; break; }
    if (path.empty() || !infodat::Load(path.c_str())) { printf("note: info.dat not reachable; skipped\n"); return 0; }

    static ChooserTables t;
    CHECK(t.Load() && t.max_distance == 200.0f && t.count_cap == 36000, "chooser tables load from info.dat (species 0)");
    CHECK(t.candidates[kHunger][0] == 66 && t.actions[65].desire == kHunger && t.actions[155].ability[0] == 4,
          "hunger's candidates start at EatFromContainer; EatFromStoragePit serves hunger; FishAndEat needs ability 4");

    static ChooserMind m;
    m.active[kHunger] = m.active[kAnger] = m.active[kCuriosity] = m.active[kCompassion] = true;
    m.desire[kHunger] = 0.8f;
    m.desire[kAnger] = 0.3f;
    m.desire[kCuriosity] = 0.5f;
    m.desire[kCompassion] = 0.4f;

    std::vector<BeliefView> beliefs = {
        {kVillager, 50.0f, 0.6f}, {kTree, 20.0f, 0.3f}, {kPit, 100.0f, 0.8f}, {kTown, 80.0f, 0.6f}};

    // Which action may be done to what; the binary asks per-action predicates.
    const std::set<std::pair<uint32_t, uint32_t>> fits = {
        {kPit, 65}, {kVillager, 11}, {kVillager, 18}, {kVillager, 15}, {kTree, 15},
        {kTree, 79}, {kTree, 10}, {kTree, 20}, {kTown, 48}};
    ChooserHost h;
    h.action_fit = [&](uint32_t b, uint32_t a) { return fits.count({b, a}) > 0; };
    bool knows_food = false;
    h.action_valid = [](uint32_t a, const ActionPlan&) { return a == 48; };   // no fights
    h.has = [&](int kind, uint32_t id) { return kind == 1 && id == 14 && knows_food; };
    h.belief_fit = [](uint32_t b, uint32_t d) {
        return d == kCuriosity || (d == kAnger && b == kVillager) || (d == kCompassion && b == kTown);
    };
    h.targeted_fit = [](uint32_t b, uint32_t d) { return (d == kAnger && b == kVillager) || (d == kCompassion && b == kTown); };
    h.town_need = [](uint32_t b) { return b == kTown ? 0 : -1; };

    char msg[256];
    {
        PlanChooser c(t, m, h, beliefs);
        const float s = c.ActionScore(65);
        std::snprintf(msg, sizeof msg, "an untried, neutral action scores 0.5025 (got %.4f)", s);
        CHECK(std::fabs(s - 0.5025f) < 1e-5f, msg);

        // Hunger is not a reaction desire (no belief fit in the desire table), so
        // it is planned through the agenda's path: sub_4D0D00, the action chooser
        // with the plan's own belief.
        ActionPlan p;
        p.desire = kHunger;
        p.belief = kPit;
        const bool ok = c.ChooseAction(&p, nullptr, kPit, false) && c.Complete(p);
        std::snprintf(msg, sizeof msg, "hungry at a storage pit: action %u (EatFromStoragePit 65), belief score %.3f",
                      p.action, p.belief_score);
        CHECK(ok && p.action == 65 && std::fabs(p.belief_score - 0.8f * (1.0f - 0.05f * 0.5f)) < 1e-5f, msg);

        ActionPlan q;
        const bool ok2 = c.Choose(0, kTree, &q);
        std::snprintf(msg, sizeof msg, "at a tree hunger has nothing to do, so curiosity looks: desire %u action %u", q.desire, q.action);
        CHECK(ok2 && q.desire == kCuriosity && q.action == 20, msg);
    }
    {
        m.action_opinion[10] = 1.0f;  // it liked picking things up
        PlanChooser c(t, m, h, beliefs);
        ActionPlan q;
        c.Choose(0, kTree, &q);
        std::snprintf(msg, sizeof msg, "an action it likes beats the others: ExamineByPickingUp (10), got %u", q.action);
        CHECK(q.action == 10, msg);
        m.action_opinion[10] = 0.0f;
    }
    {
        m.action_opinion[15] = 0.5f;
        PlanChooser c(t, m, h, beliefs);
        ActionPlan p;
        const bool ok = c.Choose(kVillager, kVillager, &p);
        std::snprintf(msg, sizeof msg, "angry at a villager: desire %u action %u (Hurl 15) with object %u (the tree)", p.desire, p.action, p.object);
        CHECK(ok && p.desire == kAnger && p.target == kVillager && p.action == 15 && p.object == kTree, msg);

        m.action_opinion[18] = 1.0f;
        ActionPlan p2;
        c.Choose(kVillager, kVillager, &p2);
        std::snprintf(msg, sizeof msg, "liking Stomp more picks it instead: got %u", p2.action);
        CHECK(p2.action == 18 && p2.object == 0, msg);
        m.action_opinion[18] = m.action_opinion[15] = 0.0f;
    }
    {
        m.leash = 30.0f;
        PlanChooser c(t, m, h, beliefs);
        ActionPlan p;
        CHECK(!c.Choose(kVillager, kVillager, &p) && c.BeliefScore(kTree, kCuriosity) > 0.0f,
              "leashed to 30, the villager at 50 is out of reach; the tree at 20 is not");
        m.leash = 0.0f;
    }
    {
        // The shipped minds' known lists: Khazar knows abilities 0..5 and no
        // spells, so FishAndEat's ability 4 is there but CastMagicFood is not.
        CreatureMind khazar;
        bool loaded = false;
        for (const char* r : {"game_data/", "../game_data/", "../../game_data/", "../../../game_data/"})
            if (LoadCreatureMindFile((std::string(r) + "CreatureMind/KhazarCreature").c_str(), khazar)) { loaded = true; break; }
        ChooserHost kh = h;
        BindKnownActions(&kh, khazar);
        PlanChooser c(t, m, kh, beliefs);
        ActionPlan fish;
        fish.desire = kHunger;
        CHECK(loaded && kh.has(0, 4) && !kh.has(1, 14) && c.ActionPossible(48, fish) == false,
              "Khazar's mind: knows ability 4 (fishing), not the food miracle, so CastMagicFood is impossible");
    }
    {
        PlanChooser c(t, m, h, beliefs);
        ActionPlan p;
        CHECK(!c.Choose(kTown, kTown, &p), "compassion for a hungry town: nothing to do without the food miracle");
        knows_food = true;
        ActionPlan q;
        const bool ok = c.Choose(kTown, kTown, &q);
        std::snprintf(msg, sizeof msg, "knowing it, the town's own table gives CastMagicFood: desire %u target %u action %u", q.desire, q.target, q.action);
        CHECK(ok && q.desire == kCompassion && q.target == kTown && q.action == 48, msg);
    }

    {
        // The agenda, end to end from shipped data. Khazar's one innate lesson
        // (hunger, about a villager, weight 0.8) is rebuilt into his hunger
        // opinion tree; a villager like the one in the lesson classifies through
        // it, and everything else stays at the empty tree's neutral.
        CreatureMind khazar;
        for (const char* r : {"game_data/", "../game_data/", "../../game_data/", "../../../game_data/"})
            if (LoadCreatureMindFile((std::string(r) + "CreatureMind/KhazarCreature").c_str(), khazar)) break;
        std::vector<LearningEpisode> eps;
        uint8_t villager[kMaxBeliefAttributes] = {};
        for (const MindEpisode& e : khazar.learning[kHunger][1].episodes) {
            LearningEpisode le;
            for (size_t i = 0; i < e.attributes.size() && i < kMaxBeliefAttributes; ++i)
                le.features[i] = villager[i] = static_cast<uint8_t>(e.attributes[i]);
            le.weight = e.weight;
            eps.push_back(le);
        }
        DecisionTreeModel tree;
        tree.Induce(CREATURE_BELIEF_VILLAGER, eps.data(), static_cast<uint32_t>(eps.size()));
        const float liking = OpinionValue(tree.Classify(villager, kMaxBeliefAttributes));
        std::snprintf(msg, sizeof msg, "Khazar's hunger tree, from his innate lesson, rates a villager %.1f", liking);
        CHECK(eps.size() == 1 && std::fabs(liking - 0.6f) < 1e-6f, msg);

        static ChooserMind km;
        km.active[kHunger] = km.active[kCuriosity] = true;
        km.desire[kHunger] = 0.8f;
        km.desire[kCuriosity] = 0.5f;
        const std::vector<BeliefView> world = {
            {kVillager, 50.0f, liking, false, 6}, {kPit, 100.0f, 0.0f, false, 3},
            {kTree, 20.0f, 0.0f}, {9, 0.0f, 0.0f, false, 8, true}};
        ChooserHost ah;
        BindKnownActions(&ah, khazar);
        const std::set<std::pair<uint32_t, uint32_t>> can = {
            {kPit, 65}, {kVillager, 11}, {kVillager, 12}, {kTree, 79}, {kTree, 10}, {kTree, 20}};
        ah.action_fit = [&](uint32_t b, uint32_t a) { return can.count({b, a}) > 0; };
        ah.belief_fit = [](uint32_t b, uint32_t d) { return d == kCuriosity || (d == kHunger && (b == kPit || b == kVillager)); };
        PlanChooser c(t, km, ah, world);
        Agenda agenda;
        int turn = 0;
        bool changed = false;
        while (!changed && turn < 10) { changed = agenda.Tick(c, km, ah); ++turn; }
        const ActionPlan* cur = agenda.plans.For(agenda.plans.current_desire);
        std::snprintf(msg, sizeof msg,
                      "the agenda settles on turn %d: desire %u, action %u (EatAlive 11) on belief %u, score %.2f; curiosity scores %.2f",
                      turn, agenda.plans.current_desire, agenda.plans.current_action, cur ? cur->belief : 0, agenda.current_total,
                      agenda.plans.For(kCuriosity)->total);
        CHECK(changed && turn == 2 && agenda.plans.current_desire == kHunger && agenda.plans.current_action == 11 &&
                  cur->belief == kVillager &&
                  std::fabs(agenda.current_total - 0.8f * 0.1f * 0.01f * 0.6f * 0.9875f * 1e5f * 0.1f) < 1e-3f &&
                  agenda.plans.For(kCuriosity)->total == 0.0f,
              msg);
        CHECK(!agenda.Tick(c, km, ah) && agenda.count == 2,
              "with nothing scoring twice as well, the next turn refills the queue (both desires)");
    }

    {
        // Action validity (action +16): all 47 predicates translated, and a few
        // of their thresholds as the binary has them.
        int with = 0, done = 0;
        for (uint32_t a = 0; a < 328; ++a)
            if (kActionValidityFn[a]) { ++with; if (ValidityTranslated(a)) ++done; }
        std::snprintf(msg, sizeof msg, "validity: %d of %d actions with a predicate have its translation", done, with);
        CHECK(with == 112 && done == with, msg);

        CreatureFacts f;
        ActionPlan none;
        f.life = 0.11f;
        const bool fight = ActionValid(21, 0, none, f);
        f.life = 0.1f;
        const bool fight_weak = ActionValid(21, 0, none, f);
        f.home_distance = 21.0f;
        const bool go_home = ActionValid(162, 0, none, f), poo_home = ActionValid(175, 0, none, f);
        CHECK(fight && !fight_weak && go_home && !poo_home,
              "Fight needs life above 0.1; GoHome needs to be over 20 m from home, PooAtHome within it");
        f.spell_charge[14] = 0.49f;
        f.can_cast[14] = true;
        const bool low = ActionValid(48, 14, none, f);  // CastMagicFood
        f.spell_charge[14] = 0.5f;
        const bool half = ActionValid(48, 14, none, f);
        f.stage = 7;
        const bool pu7 = ActionValid(98, 14, none, f);  // CastMagicFoodPU1
        f.stage = 8;
        const bool pu8 = ActionValid(98, 14, none, f);
        CHECK(!low && half && !pu7 && pu8,
              "a spell needs half its charge; the power-up casts also need stage 8 (creature+0x1268, sub_4B6190)");
        f.action_count[75] = 19;
        const bool scratch19 = ActionValid(75, 0, none, f);
        f.action_count[75] = 20;
        const bool scratch20 = ActionValid(75, 0, none, f);
        CHECK(!scratch19 && scratch20, "Scratch is refused while its turn count reads under 2 s (19 turns) and allowed from 20 (whole seconds, sub_464BB0)");
    }

    {
        // The body and the per-turn desires, exactly. An adult at rest drains
        // info+560 of energy a turn (sub_4CF980); one turn of a hunger source
        // half a step past its threshold adds Sigmoid(0.4, 0.5) over 10 x the
        // cycle time (sub_4C04E0, sub_4BE5B0).
        BodyInfo bi;
        CreatureBody body;
        const bool body_ok = bi.Load(0);
        body.Init(bi);
        CreatureBody::Context bc;
        bc.stage = 13;
        for (int i = 0; i < 100; ++i) body.Tick(bi, bc);
        std::snprintf(msg, sizeof msg, "100 turns at rest drain energy 1 -> %.5f (info+560 = %.6f a turn)", body.energy, bi.energy_drain);
        CHECK(body_ok && std::fabs(body.energy - (1.0f - 100 * bi.energy_drain)) < 2e-5f, msg);

        DesireSystem ds;
        const bool ds_ok = ds.Init(0);
        ds.Tick([](uint32_t type, float* v) { if (type != 14) return false; *v = 0.5f; return true; });
        const float expect = Sigmoid(0.4f, 0.5f) / (10.0f * ds.cycle[4]);
        std::snprintf(msg, sizeof msg, "a hunger source 0.1 past its 0.4 threshold adds %.6f in a turn (Sigmoid %.4f / 10 x cycle %.0f)",
                      ds.value[4], Sigmoid(0.4f, 0.5f), ds.cycle[4]);
        CHECK(ds_ok && ds.cycle[4] == 20.0f && std::fabs(ds.value[4] - expect) < 1e-7f && Sigmoid(0.4f, 0.5f) > 0.885f, msg);

        // Eating a villager (food 250, its info +104) at Khazar's growth 0.32:
        // 250 / (0.32 x 1000) = 0.78 energy, capped at max(growth, 1); past
        // full, 0.06 of the meal spills into the reserve; poo rises by 0.8 x the gain.
        CreatureBody eater;
        eater.Init(bi);
        eater.growth = 0.32f;
        eater.energy = 0.1f;
        eater.Eat(250.0f, bi);
        const float gain = 250.0f / (0.32f * bi.digest);
        std::snprintf(msg, sizeof msg, "a villager is %.3f of energy to a creature of growth 0.32 (sub_4DF5A0): 0.1 -> %.3f, poo %.2f",
                      gain, eater.energy, eater.poo);
        CHECK(std::fabs(eater.energy - (0.1f + gain)) < 1e-5f && std::fabs(eater.poo - gain * bi.poo_per_meal) < 1e-5f && eater.meals == 1, msg);
    }

    printf(g_fail ? "\n%d FAILED\n" : "\nall passed\n", g_fail);
    return g_fail ? 1 : 0;
}
