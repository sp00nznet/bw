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
// FishAndEat runs as v1.0's sub-actions (CreatureSubActions.h): walk to the
// fish farm, conjure a fish, pick it up, eat it, each step taking the turns it
// takes. The other actions' handlers are not translated; one of those
// completes when the creature reaches its belief, and an eating action kills
// the villager it was about. Either way the effects are v1.0's: the eat step
// (sub_4DF5A0) and the action-done routine at 0x460020 (costs, the desire's
// factor, source resets, countdowns). Desires come from the per-turn desire
// system fed by the body (CreatureBody): hunger rises as energy drains.
// Sources whose inputs this world lacks keep their saved value, fading by
// their factor.

#include "CreatureActionValidity.h"
#include "CreatureBody.h"
#include "CreatureDesire.h"
#include "CreatureLearner.h"
#include "CreaturePlanChooser.h"
#include "CreatureSubActions.h"

#include <cstdint>
#include <optional>
#include <random>
#include <unordered_map>
#include <vector>

struct Creature;
struct Villager;
struct Object;

namespace creature {

class CreatureBrain {
public:
    // Tables for `species`, the mind's known lists and its opinion trees.
    // False if info.dat is not loaded.
    bool Init(Creature* creature, const CreatureMind& mind, uint32_t species = 0);
    // A fresh mind, as a new creature's: the species' tables, nothing learned.
    bool Init(Creature* creature, uint32_t species);
    bool Init(Creature* creature, const CreatureMind* mind, uint32_t species);  // null: fresh

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
    size_t   objects_seen() const { return seen_.size(); }  // what the last turn was given
    uint32_t stopped = 0;      // actions abandoned (sub_45FA70)
    // Where the camera is, for the host to set: sub_467190's answer (its
    // player's nearest camera, or the game's when it has no player); unset
    // when there is none.
    std::optional<MapCoords> camera;
    // What it last put down (creature +4552). ponytail: a put-down fish is
    // not a world object here, so it is only remembered.
    Food discarded;

    // The sub-actions of the action under way (CreatureSubActions.h).
    SubActionAgenda subactions;
    // The 3D object's side, as far as the sub-actions read it: what the hand
    // holds (+18640) and the animation playing (+18836).
    struct Hand {
        Food     held;
        bool     holding = false;
        uint32_t anim = 0;       // the clip started by sub_46D670
        uint32_t anim_left = 0;  // turns until it ends: ours
        Food     grabbing;       // what a pickup clip (14) will close on
        bool Busy() const { return anim_left != 0; }  // sub_46CB50
    } hand;

    // The handler of the current plan's action, and the runner of what it
    // queued; Tick calls them, and so may a host that sets the plan itself.
    bool StartAction(uint32_t action);  // sub_4B6CA0: the action's handler
    void RunSubActions();               // sub_4DE180, once a turn
    // The belief index of an object (what a plan's target is), making one.
    uint32_t IdOf(Object* o);

    // What it knows about (the mind's CreatureActionKnownAbout lists, mental
    // +109052): kind 0 abilities, kind 1 magic types.
    bool Knows(int kind, uint32_t id) const;  // sub_4C3F50

    // The development stage (creature +0x1268) and the desires it switches on
    // and off (DETAIL_CREATURE_DEVELOPMENT).
    void SetDevelopmentStage(uint32_t stage);    // sub_4ACB00: all of stages 0..stage
    void EnterDevelopmentStage(uint32_t stage);  // sub_68EBD0 (SET_CREATURE_DEV_STAGE): that stage's only
    void Learn(int kind, uint32_t id);        // sub_4C3F80
    void LearnEverything(bool abilities = true, bool spells = true);

    // sub_4C3AD0: it has seen an ability (kind 0) or magic type (kind 1) in
    // use. True when the sighting teaches it (a spell is known about from its
    // first sighting; true once seen often enough).
    bool Observe(int kind, uint32_t id);
    // sub_4BA660's learning half: what a villager it notices is doing.
    void WatchVillager(const Villager* v);

private:
    float    Opinion(uint32_t desire, const BeliefView& b) const;
    bool     SourceValue(uint32_t type, float* out) const;
    void     ActionDone(uint32_t action, uint32_t served_desire);
    Object*  NearestFishFarm() const;
    // CreatureSubActions.cpp
    int  Step(uint32_t id, uint32_t step);
    bool Advance();                     // sub_4DE940
    int  WalkTo(const MapCoords& p, float radius);
    bool PlayAnim(uint32_t clip, uint32_t turns = 0);  // sub_46D670; 0: the clip's own length
    void EndAnim() { hand.anim = 0; hand.anim_left = 0; }  // sub_46D340 / sub_46D120
    uint32_t Random(uint32_t n) { return static_cast<uint32_t>(rng_() % n); }  // sub_67BC90
    float    RandomFloat(float f) { return std::uniform_real_distribution<float>(0.0f, f)(rng_); }  // sub_67BCB0
    void TickHand();
    void ApplyStage(uint32_t stage);
    int  Digest(const Food& f);         // sub_4DF830
    void Stop();                        // sub_45FA70
    void Override(uint32_t old_action); // sub_4D08E0's stop of the action it replaces
    void Finish();                      // sub_45F790
    void EndAction();

    Food     created_;      // mental+7276: what CreateFishFromSea made
    uint32_t running_ = 0;  // the action whose handler last ran
    bool     taken_ = false;  // mental+7128: CreatePickUpThenRemove has taken its share
    uint16_t countdown_ = 0;  // creature+88: the turns a point or static clip has left
    // ponytail: the handlers' dice come from this, not the game's random stream
    // (sub_67BC90), so a run is repeatable but not the original's sequence.
    std::mt19937 rng_{1};

    Creature*     creature_ = nullptr;
    uint32_t      turn_ = 0;
    ChooserTables tables_;
    ChooserHost   host_;
    std::vector<BeliefView> beliefs_;
    std::vector<Object*> seen_;
    std::vector<uint32_t> known_[2];  // abilities, magic types
    uint32_t species_ = 0;
    uint32_t ability_first_[6] = {};  // mental+97568: the turn it was first seen
    uint32_t ability_seen_[6] = {};   // mental+97544: sightings
    uint32_t spell_seen_[42] = {};    // mental+97592
    uint32_t spell_last_[42] = {};    // mental+97760: the turn last counted
    std::unordered_map<Object*, uint32_t> ids_;
    std::vector<Object*> objects_ = {nullptr};  // id -> object; 0 is none
    // Per desire, the opinion tree for each belief kind, from the mind's
    // second tree per desire (mental+0x2518, which sub_4CA6A0 reads).
    DecisionTreeModel trees_[kNumCreatureDesires][_CREATURE_BELIEF_KIND_COUNT];
};

// The brain of a creature in the game. v1.0 keeps it in the creature's
// CreatureMental; core keeps it beside the creature, made by AttachBrain.
CreatureBrain* AttachBrain(Creature* c, const CreatureMind& mind, uint32_t species = 0);
CreatureBrain* AttachBrain(Creature* c, const CreatureMind* mind, uint32_t species);  // null: a fresh mind
CreatureBrain* BrainOf(const Creature* c);
// One turn of an attached brain, over what the map's cells hold within 600 m
// (the furthest any predicate looks: sub_4B6A40's fish farms). False when it
// has none.
bool TickBrain(Creature* c);

// The four actions whose validity is sub_4B6A40 (a fish farm within 600 m).
bool IsFishing(uint32_t action);

// sub_4B8FF0's belief type -> the attribute vector it carries.
CREATURE_BELIEF_KIND BeliefKindOfType(uint32_t type);

}  // namespace creature
