#pragma once
// CreaturePlanChooser — how a creature turns its desires into a plan: which
// desire to serve, what to do about it, and to what. docs/creature-chooser.md.
//
// Translated from runblack_decrypted.exe (v1.0):
//
//   sub_4AC5F0  Choose: desires in turn until one yields a complete plan
//   sub_4AC390  the best desire about a given belief (targeted desires)
//   sub_4AC290  the best desire that needs no target
//   sub_4D1CC0  the best action for a plan's desire
//   sub_4D1870  a desire's k-th candidate action (DESIRE_ACTION_TABLE,
//               COMPASSION_FOR_TOWN_ACTION_TABLE for desire 1 about a town)
//   sub_4D1BE0  whether an action can be done at all
//   sub_4D1A90  scoring one action and keeping it if it beats the plan
//   sub_4AB7F0  the action's own score, from the creature's opinion of it
//   sub_4D0D70  the familiarity bonus, from how often it has done it
//   sub_4CA6A0  the belief's score: opinion x distance falloff x special
//   sub_4D1F70  the distance falloff
//   sub_4D1EB0  the best object for actions that need one
//   sub_4D13B0  whether a plan is complete
//
// The arithmetic and the order of the tests are the binary's. What reads the
// world (is this object edible, how hungry is this town, what is my opinion of
// that hut) goes through ChooserHost; the binary calls through per-action and
// per-desire predicate tables there, and CreatureDispatch.gen.h says which
// entries it fills, so the host is only asked where the original asks.

#include "CreatureDesire.h"

#include <cstdint>
#include <functional>
#include <vector>

struct Creature;
struct GameThingWithPos;

namespace creature {

// The candidate lists, action records and tuning the chooser reads, from
// info.dat. Load() needs infodat loaded; it fails if the tables are missing.
struct ChooserTables {
    uint32_t candidates[kNumCreatureDesires][30] = {};  // DESIRE_ACTION_TABLE, 0-terminated
    uint32_t town_candidates[17][30] = {};              // COMPASSION_FOR_TOWN_ACTION_TABLE
    bool     needs_target[kNumCreatureDesires] = {};    // DESIRE_TABLE +0x30
    float    falloff[kNumCreatureDesires] = {};         // DESIRE_TABLE +0x68
    struct Action {
        bool     uses_belief = false;  // +164: may be chosen for a belief
        uint32_t desire = 0;           // +168: the desire it serves; 0 (to impress) cuts the familiarity bonus to 2.5%
        uint32_t ability[2] = {6, 6};  // +172, +176: 6 = none
        uint32_t spell = 0;            // +180: a magic type it needs, 0 = none
        bool     not_own = false;      // +184: never at the creature's own object
    } actions[328];
    // DETAIL_CREATURE_INFO +680, +708, +712 (all seventeen species agree).
    uint32_t count_cap = 36000;
    float    max_distance = 200.0f;
    float    own_score = 1.6f;

    bool Load(uint32_t species = 0);
};

// One thing the creature has a belief about.
struct BeliefView {
    uint32_t id = 0;          // non-zero
    float    distance = 0.0f; // from the creature
    float    opinion = 0.0f;  // OpinionValue of what its tree says (sub_4B83C0)
    bool     own = false;     // the creature's own object (creature+352 +40)
    uint32_t type = 0;        // sub_4B8FF0's belief type: 6 villager, 8 creature...
    bool     self = false;    // the creature itself: never a target, but the
                              // belief an action without one is done "to"
};

// What the creature's mind holds that the chooser reads.
struct ChooserMind {
    float    desire[kNumCreatureDesires] = {};          // mental+336
    bool     active[kNumCreatureDesires] = {};          // sub_4BEE70
    bool     suppressed[kNumCreatureDesires] = {};      // mental+176
    float    action_opinion[328] = {};                  // mental+9656, -1..1
    uint32_t action_count[328] = {};                    // mental+118432
    bool     action_disabled[328] = {};                 // mental+7324, honoured when leashed
    float    leash = 0.0f;   // creature+4532; > 0 means leashed (sub_466830)
    bool     has_player = true;  // desire 9 needs one
};

// The world, as the chooser asks about it. Every hook has a default that
// answers as if the binary's predicate were absent.
struct ChooserHost {
    std::function<bool(uint32_t desire)> desire_gate;                      // desire +0
    std::function<bool(uint32_t belief, uint32_t desire)> targeted_fit;    // desire +16
    std::function<bool(uint32_t belief, uint32_t desire)> belief_fit;      // sub_4C4BD0 / desire +20
    std::function<float(uint32_t belief, uint32_t desire)> special;        // desire +36, and desire 6
    std::function<float(uint32_t belief, uint32_t desire)> target_score;   // sub_4CA530
    std::function<bool(uint32_t action, const ActionPlan&)> action_valid;  // action +16
    std::function<bool(uint32_t belief, uint32_t action)> action_fit;      // action +52
    std::function<bool(int kind, uint32_t id)> has;  // sub_4C3F50: 0 ability, 1 spell
    std::function<bool(uint32_t belief)> leash_exempt;   // desire 35's vslot 860 test
    std::function<int(uint32_t belief)> town_need;       // desire 1: the town desire 0..16, or -1
    std::function<std::vector<uint32_t>(uint32_t belief)> related;  // sub_4BB170
    // sub_4C4B60: may a targeted desire be about this? Default: anything but
    // the creature itself (the binary also asks the object's vslot 119,
    // IsSuitableForCreatureActivity, and spares its own player from anger).
    std::function<bool(uint32_t belief, uint32_t desire)> target_ok;
    // A target belief's vslot 12: the belief to act on for (desire, action),
    // writing its score. Default: the target itself, score untouched.
    std::function<uint32_t(uint32_t target, uint32_t desire, uint32_t action, float* score)> target_belief;
    // sub_4B83C0 through the desire's own tree. Default: BeliefView::opinion.
    std::function<float(uint32_t belief, uint32_t desire)> opinion;
};

// Fill the host's object predicates (action +52, desire +16/+20/+36) with the
// virtuals the binary calls on the object a belief is about -- the slots in
// CreatureDispatch.gen.h. `resolve` maps a belief id to its object.
void BindObjectPredicates(ChooserHost* host, Creature* creature,
                          std::function<GameThingWithPos*(uint32_t belief)> resolve);

// sub_4C3F50 over a mind's CreatureActionKnownAbout lists: kind 0 abilities,
// kind 1 magic types.
void BindKnownActions(ChooserHost* host, const CreatureMind& mind);

class PlanChooser {
public:
    PlanChooser(const ChooserTables& t, const ChooserMind& m, const ChooserHost& h,
                const std::vector<BeliefView>& beliefs)
        : t_(t), m_(m), h_(h), beliefs_(beliefs) {}

    // sub_4AC5F0. `about` is a belief that may prompt a targeted desire (or 0),
    // `at` the belief to act on. Fills `plan`; true if it is complete.
    bool Choose(uint32_t about, uint32_t at, ActionPlan* plan) const;

    void PickTargetedDesire(uint32_t belief, ActionPlan* plan, const std::vector<uint32_t>& tried) const;
    void PickDesire(ActionPlan* plan, const std::vector<uint32_t>& tried, bool any) const;
    bool ChooseAction(ActionPlan* plan, const std::vector<uint32_t>* tried, uint32_t belief, bool for_belief) const;

    uint32_t Candidate(const ActionPlan& plan, uint32_t k) const;
    bool  ActionPossible(uint32_t action, const ActionPlan& plan) const;
    float ActionScore(uint32_t action) const;   // sub_4AB7F0 + sub_4D0D70
    float Falloff(uint32_t desire, const BeliefView& b) const;
    float BeliefScore(uint32_t belief, uint32_t desire) const;
    uint32_t BestObject(uint32_t desire, uint32_t action, uint32_t exclude) const;
    bool Complete(const ActionPlan& plan) const;
    bool needs_target(uint32_t desire) const { return desire < kNumCreatureDesires && t_.needs_target[desire]; }

    // The agenda's half (see Agenda below).
    void  PickTarget(ActionPlan* plan) const;                                    // sub_4D09A0
    void  Fill(ActionPlan* plan) const;                                          // sub_4D0B40
    bool  ScoreActions(ActionPlan* plan, const std::vector<uint32_t>& tried) const;  // sub_4D0E30
    bool  FindBelief(ActionPlan* plan) const;                                    // sub_4D1170
    bool  FindObject(ActionPlan* plan) const;                                    // sub_4D1280
    float Total(const ActionPlan& plan) const;                                   // sub_4D1DD0

private:
    bool Leashed() const { return m_.leash > 0.0f; }
    const BeliefView* Find(uint32_t id) const;
    bool Offer(uint32_t desire, uint32_t action, uint32_t belief, ActionPlan* plan) const;
    bool BeliefFits(uint32_t belief, uint32_t desire) const;

    const ChooserTables& t_;
    const ChooserMind& m_;
    const ChooserHost& h_;
    const std::vector<BeliefView>& beliefs_;
};

// The creature's agenda (sub_4D0630, run every turn). Active desires queue up
// (sub_4D1550, desire 0 first); each turn two of them (dword_B0E2EC) have their
// plan slot rebuilt (sub_4D06F0). When the queue runs dry the best-scoring
// plan (sub_4D14E0) replaces the current one if it scores more than twice as
// much (sub_4D05D0), and otherwise the queue refills.
struct Agenda {
    PlanState plans;               // mental+1816: one plan per desire, +3912 current
    float     current_total = 0;   // mental+3956: the current plan's score
    uint32_t  queue[kNumCreatureDesires] = {};  // mental+3744
    uint32_t  count = 0;           // mental+3908
    uint32_t  best = kNumCreatureDesires;  // mental+3736

    // One turn. Returns true when the current plan changed.
    bool Tick(const PlanChooser& chooser, const ChooserMind& mind, const ChooserHost& host);
    void Refresh(const PlanChooser& chooser, const ChooserHost& host, uint32_t desire);  // sub_4D06F0
};

}  // namespace creature
