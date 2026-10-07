#pragma once
// CreatureBrain — a creature in the world, deciding through v1.0's agenda.
// docs/creature-chooser.md.
//
// Each turn: the objects within sight become beliefs (their belief type from
// GetCreatureBeliefType, their attribute vector from DescribeObject, and an
// opinion per desire from the tree its mind's episodes build); the agenda
// (sub_4D0630) runs over them with the object predicates bound to the objects'
// own virtuals; and the creature walks to whatever its current plan is about.
//
// Action validity is CreatureActionValidity's translation of all 47 predicates;
// the brain fills the facts this world has (life, home, stage, desires, action
// turns, known spells, fish farms) and the rest keep their idle defaults.
//
// What is ours rather than the binary's: what happens on arrival. The 52
// actions that dispatch through the action table run real behaviour code that
// is not translated; here an action completes when the creature reaches its
// belief (a fishing action, at the nearest fish farm), an eating action kills
// the villager it was about. The effects are v1.0's: the eat sub-action's
// energy (sub_4DF5A0), the action-done routine at 0x460020 (costs, the
// desire's factor, source resets, countdowns). Desires come from the per-turn desire
// system fed by the body (CreatureBody): hunger rises as energy drains.
// Sources whose inputs this world lacks keep their saved value, fading by
// their factor.

#include "CreatureActionValidity.h"
#include "CreatureBody.h"
#include "CreatureDesire.h"
#include "CreatureLearner.h"
#include "CreaturePlanChooser.h"

#include <cstdint>
#include <unordered_map>
#include <vector>

struct Creature;
struct Object;

namespace creature {

class CreatureBrain {
public:
    // Tables for `species`, the mind's known lists and its opinion trees.
    // False if info.dat is not loaded.
    bool Init(Creature* creature, const CreatureMind& mind, uint32_t species = 0);

    // One turn over the objects around it. Returns true when an action
    // completed this turn.
    bool Tick(const std::vector<Object*>& objects);

    ChooserMind mind;     // the agenda's view of the mind; desire values come from `desires`
    DesireSystem desires; // the per-turn desire system (sub_4BE5B0)
    CreatureBody body;    // CreaturePhysical, ticked every turn (sub_4CF980)
    BodyInfo     body_info;
    bool         drive_desires = true;  // false: the host sets mind.desire itself
    CreatureFacts facts;  // what the validity predicates read; the brain fills what it can each turn
    Agenda      agenda;

    uint32_t Action() const { return agenda.plans.current_action; }
    uint32_t Desire() const { return agenda.plans.current_desire; }
    Object*  Target() const;   // what the current plan is done to, or nullptr
    uint32_t completed = 0;    // actions finished so far
    uint32_t last_action = 0;  // the most recent one
    uint32_t last_desire = 40; // and the desire it served
    Object*  last_target = nullptr;

private:
    uint32_t IdOf(Object* o);
    float    Opinion(uint32_t desire, const BeliefView& b) const;
    bool     SourceValue(uint32_t type, float* out) const;
    void     ActionDone(uint32_t action, uint32_t served_desire);
    Object*  NearestFishFarm() const;

    Creature*     creature_ = nullptr;
    uint32_t      turn_ = 0;
    ChooserTables tables_;
    ChooserHost   host_;
    std::vector<BeliefView> beliefs_;
    std::vector<Object*> seen_;
    std::unordered_map<Object*, uint32_t> ids_;
    std::vector<Object*> objects_ = {nullptr};  // id -> object; 0 is none
    // Per desire, the opinion tree for each belief kind, from the mind's
    // second tree per desire (mental+0x2518, which sub_4CA6A0 reads).
    DecisionTreeModel trees_[kNumCreatureDesires][_CREATURE_BELIEF_KIND_COUNT];
};

// The four actions whose validity is sub_4B6A40 (a fish farm within 600 m).
bool IsFishing(uint32_t action);

// sub_4B8FF0's belief type -> the attribute vector it carries.
CREATURE_BELIEF_KIND BeliefKindOfType(uint32_t type);

}  // namespace creature
