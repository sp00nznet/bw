// The sub-action runner and the FishAndEat steps -- see black/CreatureSubActions.h.
#include <black/CreatureBrain.h>
#include <black/CreatureSubActions.h>

#include <black/Creature.h>
#include <black/CreatureDesireEnums.h>
#include <black/Object.h>

#include <algorithm>
#include <cmath>

namespace creature {

namespace {

// ponytail: a creature walks a metre a turn, as in CreatureBrain.cpp.
constexpr int kWalkSpeed = static_cast<int>(kMapUnitsPerMetre);

// The fish CreateFishFromSea conjures: POT_INFO_FISH, food value 20.
constexpr float kFishFood = 20.0f;

// Clips the steps start (sub_46D670's argument). kClipPoint is ours: the
// pointing pose (sub_46D180) takes a point, not a clip id.
enum : uint32_t { kClipPickup = 14, kClipPutDown = 95, kClipDrop = 97, kClipEat = 96, kClipPoint = 1000 };

// A clip held until a step ends it (pointing, a static action).
constexpr uint32_t kHeld = 0xFFFFFFFFu;

constexpr float kTurnsPerSecond = 10.0f;  // 1000 / dword_C22D78 at BW's 10 Hz

// The clip CommunicateToPlayer plays for a desire: DESIRE table +28 where +24
// is set (0xBA8BC8/0xBA8BCC, recovered with the rest of the table); 0 is none.
constexpr uint8_t kDesireClip[40] = {52, 64, 70, 67, 54, 61, 63, 66, 57, 67, 0, 0, 0, 0, 58, 0, 55, 72, 0, 59,
                                     58, 0,  0,  57, 0,  0,  0,  56, 0,  0,  67, 0, 0, 0, 0,  0, 0,  56, 0, 67};

// ponytail: how long a clip plays, in turns. The real lengths are the clips'
// frame counts in the creature's ANM set, which core does not load; until it
// does, a pickup takes 1.2 s, eating 2 s and putting down 1 s.
uint32_t ClipTurns(uint32_t clip) {
    switch (clip) {
    case kClipPickup: return 12;
    case kClipEat: return 20;
    default: return 10;
    }
}

struct Record { uint32_t id, kind; bool step[4]; };
// From the table at 0xB0EAF8 (work/decomp/subaction_table.json).
constexpr Record kRecords[] = {
    {kSubStaticAction, 1, {true, true, true, true}},           // sub_4DFD90, sub_4DFE20, sub_4E77D0; abort sub_4E7800
    {kSubTurnToFacePos, 3, {true, true, false, false}},        // sub_4E0980, sub_4E2AF0
    {kSubIndividualAction, 1, {true, true, false, false}},     // sub_4E0F60, sub_4E77D0
    {kSubWait, 3, {false, true, false, false}},                // -, sub_4E2410
    {kSubTurnToFaceCamera, 3, {true, true, false, false}},     // sub_4E2CA0, sub_4E2D80
    {kSubCommunicateToPlayer, 1, {true, true, false, false}},  // sub_4E31C0, sub_4E77D0
    {kSubPointAtPoint, 3, {true, true, true, false}},          // sub_4E5520, sub_4E5670, sub_4E77D0
    {kSubMoveToPos, 3, {true, false, true, false}},            // sub_4E0B90, -, sub_4E1AC0
    {kSubPickupCreatedObject, 1, {true, true, false, false}},  // sub_4E4360, sub_4E4380
    {kSubCreateFishFromSea, 1, {false, true, false, false}},   // -, sub_4E5EE0
    {kSubEatCreatedObject, 0, {true, true, true, false}},      // sub_4DF5A0, sub_4DF7A0, sub_4DF7D0
};

const Record* Find(uint32_t id) {
    for (const Record& r : kRecords) if (r.id == id) return &r;
    return nullptr;
}

}  // namespace

uint32_t SubActionKind(uint32_t id) { const Record* r = Find(id); return r ? r->kind : 3; }
bool SubActionHasStep(uint32_t id, uint32_t step) { const Record* r = Find(id); return r && step < 4 && r->step[step]; }
bool HasSubActions(uint32_t action) {
    return action == 155 || action == 193 || action == 169 || action == 168 || action == 23 || action == 165;
}

// sub_4B6CA0: clear the agenda and run the action's handler.
bool CreatureBrain::StartAction(uint32_t action) {
    subactions.Clear();
    subactions.starting = true;
    SubActionAgenda& a = subactions;
    switch (action) {
    case 193: {  // LookAtSun (sub_499520): face far to the north-west, and half the time point there
        SubActionEntry e{kSubTurnToFacePos};
        e.point = MapCoordsFromMetres(-50000.0f, -50000.0f);
        a.Add(e);
        if (!Random(2)) {
            e.id = kSubPointAtPoint;
            e.value = 3.0f;
            a.AddMain(e);
        }
        return true;
    }
    case 169:  // PointAtHand (sub_4977F0): the nearest hand of its player (sub_467290)
        // ponytail: core has no player hands, so this is the no-hand case.
        Stop();  // "FailedToConstr..."
        return false;
    case 168:  // PointAtCamera (sub_4976C0): face the camera, then point at it for 1 s
        if (!camera) {
            Stop();  // "FailedToConstr..."
            return false;
        }
        a.Add(SubActionEntry{kSubTurnToFaceCamera});
        {
            // ponytail: the point is the camera's when the action starts; the
            // pointing step's periodic callback (sub_4AEFF0) is not translated.
            SubActionEntry e{kSubPointAtPoint};
            e.point = *camera;
            e.value = 1.0f;
            a.AddMain(e);
        }
        return true;
    case 23:  // CommunicateState (sub_485610)
        a.Add(SubActionEntry{kSubTurnToFaceCamera});
        a.AddMain(SubActionEntry{kSubCommunicateToPlayer});
        return true;
    case 165: {  // HangAroundAtHome (sub_496DC0)
        SubActionEntry e{kSubMoveToPos};
        e.point = creature_->field_0x1200;  // creature+4608: home
        e.value = 5.0f;  // ponytail: min(5, the creature's GetHeight)
        a.Add(e);
        SubActionEntry w{kSubWait};
        w.integer = static_cast<int32_t>((RandomFloat(3.0f) + 2.0f) * kTurnsPerSecond);  // _ftol
        a.Add(w);
        // With no temple (its player's +608), it plays individual action 57.
        // ponytail: the temple branches (walk toward it, point or rest 10-15 s
        // facing it: StaticAction 38) need a player's temple, which core lacks.
        SubActionEntry i{kSubIndividualAction};
        i.integer = 57;
        a.AddMain(i);
        return true;
    }
    default: break;
    }
    if (action != 155) return false;
    // FishAndEat (sub_4932E0). Holding something edible already, it fails.
    if (hand.holding && hand.held.object && hand.held.object->CanBeEatenByCreature(creature_)) {
        Stop();  // "FailedToConstr..."
        return false;
    }
    Object* farm = NearestFishFarm();  // sub_503770, within 600 m
    if (!farm) {
        Stop();
        return false;
    }
    // ponytail: the original walks to the coast nearest the farm (sub_46C0E0 /
    // sub_46C260, within 30 m of it); there is no land/sea test in core, so
    // the farm itself is the place. Its radius is max(15, the creature's
    // GetHeight), taken here as 15 m.
    SubActionEntry e;
    e.id = kSubMoveToPos;
    e.point = farm->coords;
    e.value = 15.0f;
    subactions.Add(e);
    subactions.Add(SubActionEntry{kSubCreateFishFromSea});
    subactions.Add(SubActionEntry{kSubPickupCreatedObject});
    subactions.AddMain(SubActionEntry{kSubEatCreatedObject});
    return true;
}

// sub_464490: head for `p` until within `radius` metres. 1 while walking, 3 there.
int CreatureBrain::WalkTo(const MapCoords& p, float radius) {
    if (MetresOf(1) * creature_->GetDistanceFromObject(p) <= radius) {
        creature_->SetSpeed(0);
        return 3;
    }
    if (creature_->goal != p) creature_->SetGoalPos(p);
    if (creature_->speed == 0) creature_->SetSpeed(kWalkSpeed);
    creature_->MoveToGoal();
    if (creature_->move_state == MOVE_TO_STATES_ARRIVED) {
        creature_->SetSpeed(0);
        return 3;
    }
    return 1;
}

bool CreatureBrain::PlayAnim(uint32_t clip, uint32_t turns) {
    if (hand.Busy()) return false;
    hand.anim = clip;
    hand.anim_left = turns ? turns : ClipTurns(clip);
    return true;
}

// The clips' effect on the hand, when they end (ours: the original's happen
// on frame events within the clip).
void CreatureBrain::TickHand() {
    if (!hand.anim_left || --hand.anim_left) return;
    switch (hand.anim) {
    case kClipPickup: hand.held = hand.grabbing; hand.holding = true; hand.grabbing = Food(); break;
    case kClipEat: hand.holding = false; break;
    case kClipPutDown: case kClipDrop: hand.holding = false; hand.held = Food(); break;
    }
    hand.anim = 0;
}

// sub_4DE940: the next step, or the next sub-action after the third. The
// action is done (0x460020) after the main sub-action's last step.
bool CreatureBrain::Advance() {
    if (++subactions.step != 3) return true;
    if (subactions.count - 1 == subactions.current) ActionDone(Action(), Desire());
    return subactions.Next();
}

// sub_4DE180, once a turn.
void CreatureBrain::RunSubActions() {
    TickHand();
    SubActionAgenda& a = subactions;
    if (!a.count) { Stop(); return; }  // the agenda was emptied (sub_4DF830's refusal)
    if (a.current >= a.count || a.step >= 3) return;
    // ponytail: the wait-for-clip flag (+4040) is never set by the steps here.
    while (!SubActionHasStep(a.entries[a.current].id, a.step))
        if (!Advance()) { Finish(); return; }
    const SubActionEntry& e = a.entries[a.current];
    if (a.starting) {
        a.starting = false;
        switch (SubActionKind(e.id)) {
        case 0:  // needs something in hand
            if (!hand.holding) { Stop(); return; }  // "Stopping because..."
            break;
        case 1:  // puts down what is held first (sub_464590 picks the clip)
            if (hand.holding) {
                if (!PlayAnim(kClipPutDown)) a.starting = true;
                return;
            }
            break;
        default: break;  // 2 (pickups) is not used by the actions translated here
        }
    }
    // ponytail: the per-entry callback every +119824 seconds (entry +72) is
    // unset for every sub-action FishAndEat queues.
    switch (Step(e.id, a.step)) {
    case kStepWait: break;
    case kStepDone:
        if (!Advance()) Finish();
        break;
    default: Stop(); break;  // 1 and 3: "Stopping because..."
    }
}

// sub_4DF830 on what was eaten, the last step of eating it.
int CreatureBrain::Digest(const Food& f) {
    hand.held = Food();  // physical+40
    Object* o = f.object;
    const bool food = (o && (o->IsMushroom(creature_) || o->IsPileFood())) ||
                      (f.value >= 5.0f && !(o && o->IsPoisoned()));
    if (!food) {  // spat out: hunger held back 20 s, and the agenda emptied
        // ponytail: the feedback it gives (sub_4C2BB0, sub_4B0770) and the
        // count of things refused are not modelled.
        desires.Countdown(CREATURE_DESIRE_HUNGER, 20.0f);
        subactions.count = 0;
        return kStepWait;
    }
    // Hunger falls by what the meal gave, clamped to [0, 1] directly.
    const float size = std::min(body.growth, 0.8f);
    float& h = desires.value[CREATURE_DESIRE_HUNGER];
    h = std::clamp(h - f.value / (size * body_info.digest), 0.0f, 1.0f);
    mind.desire[CREATURE_DESIRE_HUNGER] = h;
    // ponytail: a meal over 50 also teaches (sub_4C2BB0); a fish is 20.
    return kStepDone;
}

int CreatureBrain::Step(uint32_t id, uint32_t step) {
    SubActionEntry& e = subactions.entries[subactions.current];
    switch (id * 4 + step) {
    case kSubTurnToFacePos * 4 + 0: {  // sub_4E0980
        const float dx = MetresOf(e.point.x - creature_->coords.x), dz = MetresOf(e.point.z - creature_->coords.z);
        if (std::sqrt(dx * dx + dz * dz) < 0.1f) return kStepDone;
        const float heading = std::atan2(dx, dz);
        const float diff = std::remainder(heading - creature_->GetYAngle(), 6.2831855f);
        if (std::fabs(diff) <= 0.39269909f) return kStepDone;  // within pi/8
        // ponytail: the turn (sub_4D01E0) is instant here; the original
        // plays a turning clip at the creature's turn speed.
        creature_->SetYAngle(heading);
        return kStepDone;
    }
    case kSubTurnToFacePos * 4 + 1:   // sub_4E2AF0
    case kSubIndividualAction * 4 + 1:
    case kSubCommunicateToPlayer * 4 + 1:
    case kSubPointAtPoint * 4 + 2:
    case kSubStaticAction * 4 + 2:    // sub_4E77D0: until the clip is over
        return hand.Busy() ? kStepWait : kStepDone;
    case kSubTurnToFaceCamera * 4 + 0:  // sub_4E2CA0 / sub_4E2D80: no player, nothing to face
    case kSubTurnToFaceCamera * 4 + 1:
        // ponytail: with a player it turns to the camera, which core lacks.
        return kStepDone;
    case kSubCommunicateToPlayer * 4 + 0: {  // sub_4E31C0
        // Its strongest active desire that has a clip (sub_4BE770). The
        // original plays the player-feedback clip (55 or 56) instead when
        // feedback came within 10 s (mental+101472); there is none here.
        uint32_t best = kNumCreatureDesires;
        float v = 0.0f;
        for (uint32_t d = 0; d < kNumCreatureDesires; ++d)
            if (desires.active[d] && desires.value[d] > v && kDesireClip[d]) best = d, v = desires.value[d];
        desires.Countdown(18, 60.0f);
        if (best == kNumCreatureDesires) return kStepFailed;
        return PlayAnim(kDesireClip[best]) ? kStepDone : kStepWait;  // sub_46D360
    }
    case kSubIndividualAction * 4 + 0:  // sub_4E0F60
        return PlayAnim(static_cast<uint32_t>(e.integer)) ? kStepDone : kStepWait;
    case kSubPointAtPoint * 4 + 0:  // sub_4E5520: point, for at least 10 turns
        if (hand.Busy()) return kStepWait;
        PlayAnim(kClipPoint, kHeld);
        countdown_ = static_cast<uint16_t>(std::max(static_cast<int>(e.value * kTurnsPerSecond), 10));
        return kStepDone;
    case kSubPointAtPoint * 4 + 1:  // sub_4E5670
    case kSubStaticAction * 4 + 1:  // sub_4DFE20
        if (id == kSubStaticAction && e.integer == 38)  // resting sheds exhaustion
            body.exhaustion = std::clamp(body.exhaustion - body_info.rest * 0.2f, 0.0f, 1.0f);
        if (--countdown_) return kStepWait;
        EndAnim();
        return kStepDone;
    case kSubStaticAction * 4 + 0:  // sub_4DFD90
        if (!PlayAnim(static_cast<uint32_t>(e.integer), kHeld)) return kStepWait;
        countdown_ = static_cast<uint16_t>(e.value * kTurnsPerSecond);
        return kStepDone;
    case kSubWait * 4 + 1:  // sub_4E2410
        // ponytail: the original waits out a busy clip unless sub_46D620 lets
        // it be cut short; here any clip is waited out.
        if (hand.Busy()) return kStepWait;
        return --e.integer > 0 ? kStepWait : kStepDone;
    case kSubMoveToPos * 4 + 0:  // sub_4E0B90
        return WalkTo(e.point, e.value) == 3 ? kStepDone : kStepWait;
    case kSubMoveToPos * 4 + 2:  // sub_4E1AC0: until it has stopped moving
        return creature_->speed != 0 ? kStepWait : kStepDone;
    case kSubCreateFishFromSea * 4 + 1:  // sub_4E5EE0: a fish pot at its feet
        created_ = Food{nullptr, kFishFood, true};
        return kStepDone;
    case kSubPickupCreatedObject * 4 + 0:  // sub_4E4360 -> sub_4DED00
        // The fish lies at its feet, so neither walk is needed; the
        // object tests (CanBePickedUpByCreature, in the map) are a world
        // object's, which the fish is not here.
        if (!created_.any) return kStepFailed;
        if (!PlayAnim(kClipPickup)) return kStepWait;  // sub_469760
        hand.grabbing = created_;
        return kStepDone;
    case kSubPickupCreatedObject * 4 + 1:  // sub_4E4380 -> sub_4DF0E0
        if (!created_.any) return kStepFailed;
        return hand.Busy() ? kStepWait : kStepDone;
    case kSubEatCreatedObject * 4 + 0:  // sub_4DF5A0
        if (hand.Busy()) return kStepWait;
        if (!hand.holding) return kStepFailed;  // "Stopping eating"
        PlayAnim(kClipEat);
        body.Eat(hand.held.value, body_info);
        return kStepDone;
    case kSubEatCreatedObject * 4 + 1:  // sub_4DF7A0: until the clip lets go of it
        return hand.holding ? kStepWait : kStepDone;
    case kSubEatCreatedObject * 4 + 2:  // sub_4DF7D0
        if (hand.Busy()) return kStepWait;
        return created_.any ? Digest(created_) : kStepStop;
    default: return kStepFailed;
    }
}

// The bookkeeping both endings share (sub_45FBC0, as far as it applies):
// nothing is current, so the agenda's next plan takes over.
void CreatureBrain::EndAction() {
    // The current sub-action's abort handler (record +128, from sub_45FBC0):
    // StaticAction's ends its clip (sub_4E7800).
    if (subactions.count && subactions.entries[subactions.current].id == kSubStaticAction) EndAnim();
    subactions.Clear();
    created_ = Food();
    if (hand.held.object && !hand.holding) hand.held = Food();
    creature_->SetSpeed(0);
    agenda.plans.current_desire = kNumCreatureDesires;  // mental+3920 = 40
    agenda.plans.current_action = 0;
    agenda.current_total = 0.0f;
    running_ = 0;
}

// sub_45FA70: abandoned. The turns spent on it are forgotten (mental+118432).
void CreatureBrain::Stop() {
    if (const uint32_t a = Action()) mind.action_count[a] = 0;
    ++stopped;
    EndAction();
}

// sub_4D08E0 stops the running action ("Overriding action") before the new
// plan is made current; here the agenda has already swapped the plan in, so
// the old action is named.
void CreatureBrain::Override(uint32_t old_action) {
    mind.action_count[old_action] = 0;
    ++stopped;
    if (subactions.count && subactions.entries[subactions.current].id == kSubStaticAction) EndAnim();
    subactions.Clear();
}

// sub_45F790: done (0x460020 has already run, from Advance).
void CreatureBrain::Finish() {
    const uint32_t served = Desire();
    last_action = Action();
    last_desire = served;
    last_target = Target();
    ++completed;
    // As on arrival: the spent plan's slot scores nothing until the queue
    // rebuilds it (ours, see CreatureBrain::Tick).
    if (served < kNumCreatureDesires) agenda.plans.plans[served].total = 0.0f;
    EndAction();
}

}  // namespace creature
