// The sub-action runner and the FishAndEat steps -- see black/CreatureSubActions.h.
#include <black/CreatureBrain.h>
#include <black/CreatureSubActions.h>

#include <black/Creature.h>
#include <black/CreatureDesireEnums.h>
#include <black/LandFeatures.h>
#include <black/Terrain.h>
#include <black/Object.h>
#include <black/PileFood.h>
#include <black/StoragePit.h>
#include <black/Villager.h>

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

// GetFoodValue(3), what eating it gives.
float FoodValue(Object* o) { return o ? o->GetFoodValue(static_cast<FOOD_TYPE>(3)) : 0.0f; }

struct Record { uint32_t id, kind; bool step[4]; };
// From the table at 0xB0EAF8 (work/decomp/subaction_table.json).
constexpr Record kRecords[] = {
    {kSubPickup, 2, {true, true, false, false}},               // sub_4DECD0 -> sub_4DED00, sub_4DF0B0 -> sub_4DF0E0
    {kSubDiscard, 0, {true, true, true, false}},               // sub_4DF500, sub_4DF570, sub_4E77D0
    {kSubEat, 0, {true, true, true, false}},                   // sub_4DF5A0, sub_4DF7A0, sub_4DFB90; abort sub_4E7810
    {kSubHeldObjectAction, 0, {true, true, false, false}},     // sub_4DFC00, sub_4E77D0
    {kSubDrink, 1, {false, true, false, false}},               // -, sub_4E4110
    {kSubTurnToFaceObject, 3, {true, true, true, false}},      // sub_4E05F0, sub_4E06D0, sub_4E0840
    {kSubClearObjectToActOn, 3, {false, true, false, false}},  // -, sub_4E6910
    {kSubCreatePickUpThenRemove, 1, {true, true, true, false}},// sub_4DF1E0, sub_4E4360, sub_4DF330
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
    return action == 155 || action == 11 || action == 12 || action == 90 || action == 218 || action == 55 || action == 27 || action == 259 || action == 65 || action == 193 || action == 169 || action == 168 || action == 23 || action == 165;
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
    case 11: {  // EatAlive (sub_482B30): pick it up, unless already holding something edible, and eat it
        Object* t = Target();
        if (!(hand.holding && hand.held.object && hand.held.object->CanBeEatenByCreature(creature_))) {
            if (!Random(2)) {  // sub_67BC90(2): half the time, a gesture first
                SubActionEntry g{kSubIndividualAction};
                g.integer = 54;
                a.Add(g);
            }
            SubActionEntry p{kSubPickup};
            p.object = t;
            a.Add(p);
        }
        SubActionEntry e{kSubEat};
        e.object = t;
        a.AddMain(e);
        return true;
    }
    case 12: {  // EatAfterExamining (sub_4850A0): pick it up, look it over (clip 103), eat it
        Object* t = Target();
        if (!(hand.holding && hand.held.object && hand.held.object->CanBeEatenByCreature(creature_))) {
            SubActionEntry p{kSubPickup};
            p.object = t;
            a.Add(p);
        }
        // ponytail: its callbacks (sub_4B4EE0, where to look; sub_4AEE40, the
        // sounds every few seconds) are not translated.
        SubActionEntry x{kSubHeldObjectAction};
        x.integer = 103;
        a.Add(x);
        SubActionEntry e{kSubEat};
        e.object = t;
        a.AddMain(e);
        return true;
    }
    case 27: {  // GoToHillAndWalkAlongRidge (sub_485B50): up the nearest hill, then round its top
        land::FeatureMap& fm = land::Features();
        MapCoords top;
        if (!fm.Find(land::kHill, creature_->coords, &top, false, true) &&
            !fm.Find(land::kLand, creature_->coords, &top, false, true)) {
            // ponytail: the original then calls vslot 6 of mental +109184 and
            // walks to (0, 0) anyway; here it stops.
            Stop();
            return false;
        }
        // ponytail: the place is not remembered (mental +7288).
        SubActionEntry m{kSubMoveToPos};
        m.point = top;
        m.value = creature_->GetHeight() * 3.0f;
        a.AddMain(m);
        // Eight points 15 m round the top, 45 degrees apart (the 2048-step
        // tables at 0xB54278 / 0xB53A78: cos, sin), each within 2 x height.
        for (int i = 0; i < 8; ++i) {
            const float t = i * 0.785398163f;
            SubActionEntry r{kSubMoveToPos};
            r.point = MapCoordsFromMetres(MetresOf(top.x) + 15.0f * std::cos(t), MetresOf(top.z) + 15.0f * std::sin(t));
            r.value = creature_->GetHeight() * 2.0f;
            a.Add(r);
        }
        return true;
    }
    case 259: {  // TakeFishFromSeaToHome (sub_4A23B0): fish, carry it home, put it down there
        if (!(hand.holding && hand.held.object && hand.held.object->CanBeEatenByCreature(creature_))) {
            Object* farm = NearestFishFarm();  // sub_503770, within 600 m
            if (!farm) {
                Stop();
                return false;
            }
            SubActionEntry m{kSubMoveToPos};  // as FishAndEat: the farm itself, not its coast
            m.point = farm->coords;
            m.value = std::max(15.0f, creature_->GetHeight());
            a.Add(m);
            a.Add(SubActionEntry{kSubCreateFishFromSea});
            a.Add(SubActionEntry{kSubPickupCreatedObject});
        }
        SubActionEntry h{kSubMoveToPos};
        h.point = creature_->field_0x1200;  // creature+4608: home
        h.value = creature_->GetHeight();
        a.Add(h);
        SubActionEntry d{kSubDiscard};
        d.integer = kClipDrop;
        a.AddMain(d);
        return true;
    }
    case 65: {  // EatFromStoragePit (sub_48AE00): a handful from the pit's food pile, eaten
        auto* pit = dynamic_cast<StoragePit*>(Target());
        Object* pile = pit ? static_cast<Object*>(pit->pile_food) : nullptr;  // sub_6C98C0(0, 0): +0xC4
        if (!pile) {
            Stop();  // "FailedToConstr..."
            return false;
        }
        // ponytail: the belief it makes of the pile (sub_4BA200) is not kept.
        SubActionEntry m{kSubMoveToPos};
        m.point = pile->coords;
        m.value = creature_->GetHeight() * 1.4f;
        a.Add(m);
        SubActionEntry t{kSubTurnToFaceObject};
        t.object = pile;
        t.value = 0.1f;
        a.Add(t);
        a.Add(SubActionEntry{kSubClearObjectToActOn});
        SubActionEntry c{kSubCreatePickUpThenRemove};
        c.object = pile;
        c.integer = 17;  // POT_INFO_WHEAT_IN_HAND
        a.Add(c);
        a.AddMain(SubActionEntry{kSubEatCreatedObject});
        return true;
    }
    case 90: {  // WaveAtPlayer (sub_48DDB0): face the camera and wave (clip 72)
        a.Add(SubActionEntry{kSubTurnToFaceCamera});
        SubActionEntry w{kSubIndividualAction};
        w.integer = 72;
        a.AddMain(w);
        return true;
    }
    case 218: {  // SitDownOnBeach (sub_494450): by the nearest water, facing it, resting 10-25 s
        MapCoords water;
        if (!land::Features().Find(land::kWater, creature_->coords, &water, true, true)) {
            Stop();  // "FailedToConstr..."
            return false;
        }
        // ponytail: sub_4C1820 (-> sub_4C18C0) finds a clear patch of land
        // within 4 x the creature's radius of the water to sit on; here he
        // walks toward the water point itself and stops a height short.
        SubActionEntry m{kSubMoveToPos};
        m.point = water;
        m.value = creature_->GetHeight();
        a.Add(m);
        SubActionEntry t{kSubTurnToFacePos};
        t.point = water;
        a.Add(t);
        SubActionEntry s{kSubStaticAction};
        s.integer = 38;
        s.value = RandomFloat(15.0f) + 10.0f;  // sub_67BCB0(15.0)
        a.AddMain(s);
        return true;
    }
    case 55: {  // DrinkFromTheSea (sub_4895E0): to the nearest coast, face the water, drink
        // ponytail: the first choice, the nearest drinking place within 1 km
        // (sub_4673B0, the game's list at +2104624), has no list in core.
        land::FeatureMap& fm = land::Features();
        MapCoords coast, water;
        fm.Find(land::kCoast, creature_->coords, &coast, true, true);
        fm.Find(land::kWater, coast, &water, true, true);
        // Unless it already stands in water (sub_5BFB00), it walks to the coast.
        // ponytail: the land test and the shore within 30 m (sub_46C0E0 /
        // sub_46C260) are not translated, nor the failure that holds desires
        // 14 and 20 back 30 s.
        const int32_t f = g_cell_flags_func ? g_cell_flags_func(creature_->coords.x.split.map, creature_->coords.z.split.map) : -1;
        if (f >= 0 && !(f & 0x10)) {
            SubActionEntry m{kSubMoveToPos};
            m.point = coast;
            m.value = creature_->GetHeight();
            a.Add(m);
        }
        SubActionEntry t{kSubTurnToFacePos};
        t.point = water;
        a.Add(t);
        SubActionEntry d{kSubIndividualAction};
        d.integer = 71;
        a.AddMain(d);
        a.Add(SubActionEntry{kSubDrink});
        return true;
    }
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
    case kClipPickup:
        hand.held = hand.grabbing;
        hand.holding = true;
        hand.grabbing = Food();
        // ponytail: a villager in the hand goes into IN_HAND (24) and stays put;
        // the original carries it at the hand.
        if (auto* v = dynamic_cast<Villager*>(hand.held.object)) v->SetTopState(VILLAGER_STATE_IN_HAND);
        break;
    case kClipEat:
        hand.holding = false;
        // ponytail: the original removes what was eaten; a villager dies.
        if (auto* v = dynamic_cast<Villager*>(hand.held.object)) v->SetTopState(VILLAGER_STATE_DYING);
        break;
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
        case 2:  // a pickup: drop what is held first, unless it is the very thing
            if (hand.holding) {
                if (hand.held.object && hand.held.object == e.object) {  // sub_4DE910
                    if (!a.Next()) Finish();
                    return;
                }
                if (!PlayAnim(kClipDrop)) a.starting = true;  // physical+40 = 0 when it starts
                return;
            }
            break;
        default: break;
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
    case kSubTurnToFaceObject * 4 + 0: {  // sub_4E05F0: turn to it
        // ponytail: the turn (sub_4D01E0) is instant, as in TurnToFacePos.
        if (!e.object) return kStepDone;
        const float dx = MetresOf(e.object->coords.x - creature_->coords.x), dz = MetresOf(e.object->coords.z - creature_->coords.z);
        if (std::sqrt(dx * dx + dz * dz) >= 0.1f) creature_->SetYAngle(std::atan2(dx, dz));
        return kStepDone;
    }
    case kSubTurnToFaceObject * 4 + 1:  // sub_4E06D0: facing it, look for the entry's seconds
        if (hand.Busy()) return kStepWait;
        countdown_ = static_cast<uint16_t>(e.value * kTurnsPerSecond);  // mental+7128
        return kStepDone;
    case kSubTurnToFaceObject * 4 + 2:  // sub_4E0840
        if (hand.Busy() || !countdown_) return hand.Busy() ? kStepWait : kStepDone;
        --countdown_;
        return kStepWait;
    case kSubClearObjectToActOn * 4 + 1:  // sub_4E6910
        // ponytail: the plan's object (mental+3928) becomes sub_4BA1B0's; the
        // brain's plan keeps its target here.
        return kStepDone;
    case kSubCreatePickUpThenRemove * 4 + 0: {  // sub_4DF1E0: a pot of the pile's food at it
        // As much as the creature's hand holds, 1000 x size_1 (3D +144), or
        // what the pile has (vslot 38 for the pot info's resource, food).
        // ponytail: the pot is not a world object here (as with the fish), and
        // its scale (3.75 x size_1) is not kept.
        if (!e.object) return kStepFailed;
        const uint32_t room = static_cast<uint32_t>(1000.0f * creature_->GetHeight() / 15.0f);
        const uint32_t n = std::min(room, e.object->GetResource(static_cast<RESOURCE_TYPE>(0)));
        created_ = Food{nullptr, static_cast<float>(n), true};  // a pot's food value is its amount (vslot 408)
        taken_ = false;
        return kStepDone;
    }
    case kSubCreatePickUpThenRemove * 4 + 1:  // sub_4E4360 -> sub_4DED00 on the pot, at its feet
        if (!PlayAnim(kClipPickup)) return kStepWait;
        hand.grabbing = created_;
        return kStepDone;
    case kSubCreatePickUpThenRemove * 4 + 2:  // sub_4DF330: as the hand closes, the pile gives it up
        if (hand.Busy()) return kStepWait;
        if (!taken_ && e.object) {
            e.object->RemoveResource(static_cast<RESOURCE_TYPE>(0), static_cast<uint32_t>(created_.value), nullptr, nullptr);
            taken_ = true;
        }
        return hand.holding ? kStepDone : kStepStop;
    case kSubDiscard * 4 + 0:  // sub_4DF500: put down what is held, with its clip
        if (!hand.holding) return kStepFailed;
        if (!PlayAnim(static_cast<uint32_t>(e.integer))) return hand.Busy() ? kStepWait : kStepFailed;
        discarded = hand.held;  // creature +4552
        return kStepDone;
    case kSubDiscard * 4 + 1:  // sub_4DF570: until the hand lets go
        return hand.holding ? kStepWait : kStepDone;
    case kSubDiscard * 4 + 2:  // sub_4E77D0
        return hand.Busy() ? kStepWait : kStepDone;
    case kSubDrink * 4 + 1:  // sub_4E4110: thirst slaked, the desire held back 20 s
        body.dehydration = 0.0f;  // physical +0x34
        desires.Countdown(CREATURE_DESIRE_FOR_WATER, 20.0f);
        creature_->SetSpeed(0);   // sub_5EBD20(0)
        return kStepDone;
    case kSubHeldObjectAction * 4 + 0:  // sub_4DFC00 -> sub_46D490: a clip of what is held
        if (hand.holding && !hand.Busy()) {
            PlayAnim(static_cast<uint32_t>(e.integer));
            return kStepDone;
        }
        return hand.Busy() ? kStepWait : kStepFailed;
    case kSubHeldObjectAction * 4 + 1:
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
    case kSubPickup * 4 + 0: {  // sub_4DED00
        Object* o = e.object;
        if (!o) return kStepFailed;
        // ponytail: objects being deleted (+10 bit 0) are not kept in core, and
        // the exception for info type 15 off the map is not needed by villagers.
        if (!o->CanBePickedUpByCreature(creature_) || !o->IsObjectInMap_0()) return kStepFailed;  // "StoppingPickup"
        const float dist = MetresOf(1) * creature_->GetDistanceFromObject(o->coords);
        // sub_4614E0: near enough to reach for without walking -- within 10 m
        // of the hand, or within 50 x its height. ponytail: a villager's height
        // (vslot 267) is its mesh's, 0 here, and the hand is the creature's
        // position (3D +0x78).
        if (dist >= 10.0f) {
            const int w = WalkTo(o->coords, 2.0f * (o->Get2DRadius() + creature_->Get2DRadius()));
            if (w == 1) return kStepWait;
            if (w != 3) return kStepFailed;  // ponytail: the place is not remembered (creature+4640)
        }
        // sub_46E750: within the hand's reach (sub_46E600, clip 14), or walk on
        // until it is. ponytail: no lead on a moving villager, no obstruction
        // test (sub_46E970), no height check.
        const float reach = creature_->HandReach();
        if (dist > reach) {
            const int w = WalkTo(o->coords, reach);
            return w == 1 || w == 3 ? kStepWait : kStepFailed;
        }
        if (!PlayAnim(kClipPickup)) return kStepWait;  // sub_469760
        hand.grabbing = Food{o, FoodValue(o), true};
        // ponytail: lifting it adds flt_B8ECD4 x (its weight / the creature's)
        // to strength (sub_4D0270); that constant is set at run time and is 0
        // in the image.
        return kStepDone;
    }
    case kSubPickup * 4 + 1:  // sub_4DF0E0: until the clip is over, then whether it closed on it
        if (!e.object) return kStepFailed;
        if (hand.Busy()) return kStepWait;
        return hand.holding ? kStepDone : kStepStop;
    case kSubEat * 4 + 2:  // sub_4DFB90
        if (hand.Busy()) return kStepWait;
        return e.object ? Digest(Food{e.object, FoodValue(e.object), true}) : kStepStop;
    case kSubEat * 4 + 0:
    case kSubEatCreatedObject * 4 + 0:  // sub_4DF5A0
        if (hand.Busy()) return kStepWait;
        if (!hand.holding) return kStepFailed;  // "Stopping eating"
        PlayAnim(kClipEat);
        body.Eat(hand.held.value, body_info);
        return kStepDone;
    case kSubEat * 4 + 1:
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
    // ponytail: PointAtPoint has no abort handler, and where v1.0 lets go of
    // an abandoned point (3D state 8) is not found; it is released here as
    // sub_46D340 does at its end, or it would hold the hand for good.
    if (subactions.count && subactions.entries[subactions.current].id == kSubStaticAction) EndAnim();
    if (hand.anim == kClipPoint) EndAnim();
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
    if (hand.anim == kClipPoint) EndAnim();  // as in EndAction
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
