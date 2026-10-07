#pragma once
// The creature's sub-action agenda (mental+4008, CreatureSubActionAgenda).
// docs/creature-chooser.md, "What actions are made of".
//
// An action's handler (action table +32, called by sub_4B6CA0 when its plan
// becomes current) queues sub-actions here; the runner (sub_4DE180, every
// turn) steps through them. Each sub-action has up to three steps plus an
// abort handler (the table at 0xB0EAF8, work/decomp/subaction_table.json); a
// step answers 0 (not yet), 1 (failed), 2 (done) or 3 (stop). After the third
// step of the last sub-action the action is done (0x460020).
//
// CreatureBrain runs it (CreatureSubActions.cpp). Translated so far: the
// handlers of FishAndEat (155), LookAtSun (193), PointAtHand (169),
// CommunicateState (23) and HangAroundAtHome (165), and the eleven sub-actions
// they queue. Every other action still completes on arrival.

#include "types.h"

#include <cstdint>

struct Object;

namespace creature {

enum : uint32_t {  // sub-action ids: records of the table at 0xB0EAF8
    kSubPickup = 0,
    kSubEat = 2,
    kSubHeldObjectAction = 3,
    kSubDrink = 51,
    kSubStaticAction = 4,
    kSubTurnToFacePos = 7,
    kSubMoveToPos = 8,
    kSubIndividualAction = 10,
    kSubWait = 24,
    kSubTurnToFaceCamera = 31,
    kSubCommunicateToPlayer = 32,
    kSubPointAtPoint = 80,
    kSubPickupCreatedObject = 55,
    kSubCreateFishFromSea = 92,
    kSubEatCreatedObject = 128,
};

// What a step answers (sub_4DE180's switch).
enum : int { kStepWait = 0, kStepFailed = 1, kStepDone = 2, kStepStop = 3 };

// Something to eat: a world object, or the fish CreateFishFromSea conjures,
// which is not one here.
struct Food {
    Object* object = nullptr;
    float   value = 0.0f;  // GetFoodValue(3)
    bool    any = false;
};

struct SubActionEntry {      // 96 bytes at agenda +48 in the original
    uint32_t id = 0;         // +0
    Object*  object = nullptr;  // +4: SubArgumentObject
    int32_t  integer = 0;    // +8: SubArgumentInteger (a clip, or turns to wait)
    MapCoords point;         // +12: SubArgumentPoint
    float    value = 0.0f;   // +24: the float of ...AndFloat (a radius, or seconds)
};

struct SubActionAgenda {
    static constexpr uint32_t kCapacity = 32;  // (0xC50 - 48) / 96
    bool     starting = false;  // +8: the current sub-action has not begun
    uint32_t current = 0;       // +12
    uint32_t step = 0;          // +16
    uint32_t count = 0;         // +20
    int32_t  main = -1;         // +28: the sub-action that is the action proper
    SubActionEntry entries[kCapacity];

    void Clear() { *this = SubActionAgenda(); }  // sub_4DE990
    // sub_4DE610. ponytail: the original refuses a MoveToPos outside the
    // creature's leash (creature+4520, radius +4532); there is no leash here.
    void Add(const SubActionEntry& e) {
        if (count < kCapacity) entries[count++] = e;
    }
    void AddMain(const SubActionEntry& e) { Add(e); main = static_cast<int32_t>(count) - 1; }  // sub_4DE770
    // sub_4DE910: on to the next sub-action; false when there is none.
    bool Next() {
        starting = true;
        ++current;
        step = 0;
        if (current < count) return true;
        current = step = 0;
        return false;
    }
};

// The sub-action's kind (record +64): what the runner checks as it begins.
// 0 needs something in hand, 1 puts down what is held, 2 picks up, 3 nothing.
uint32_t SubActionKind(uint32_t id);
// Whether the record has a handler for `step` (0..3; 3 is the abort handler).
bool SubActionHasStep(uint32_t id, uint32_t step);
// Actions whose handler is translated, and so run as sub-actions.
bool HasSubActions(uint32_t action);

}  // namespace creature
