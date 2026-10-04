// VillagerStates — v1.0's villager state machine, the translated part.
//
// v1.0 runs each villager from Living::ProcessAll (sub_5AB2E0) through its
// vslot 392 tick (sub_6E01E0): count the turn, then call the current state's
// function from a 255-entry table at 0xC2A2C8 (rebuilt in work/decomp by
// emulating its initialiser). This file is that tick plus the states
// translated so far; docs/villager-states.md lists them and what is missing.
#include <black/Villager.h>

#include <black/Abode.h>
#include <black/LHRandom.h>
#include <black/Terrain.h>
#include <black/Town.h>
#include <black/TownDesire.h>

#include <cmath>
#include <cstring>

extern uint32_t g_game_turn;

namespace vs {
namespace {

float InfoF(const Villager& v, int off) { float x = 0; if (v.info) std::memcpy(&x, reinterpret_cast<const char*>(v.info) + off, 4); return x; }
uint32_t InfoU(const Villager& v, int off) { uint32_t x = 0; if (v.info) std::memcpy(&x, reinterpret_cast<const char*>(v.info) + off, 4); return x; }
uint8_t InfoB(const Villager& v, int off) { return v.info ? reinterpret_cast<const uint8_t*>(v.info)[off] : 0; }

// vslot 569 (sub_6E1B90), the core: the new state, its turn count from zero.
// ponytail: the original first may divert a frail villager into
// PauseForASecond (239), and runs the exit/enter slots of the state table.
void SetState(Villager& v, uint8_t s) {
    v.action.previous_state = v.action.top_state;
    v.action.top_state = s;
    v.action.turns_since_state_change = 0;
}

// sub_5B0E40: walk (the state at villager info +292) to pos, then enter `arrive`.
void MoveToPosThen(Villager& v, const MapCoords& pos, uint8_t arrive) {
    uint8_t walk = InfoB(v, 292);
    if (!walk) walk = VILLAGER_STATE_MOVE_TO_POS;
    v.action.previous_state = v.action.top_state;
    v.action.top_state = walk;
    v.action.final_state = arrive;
    v.action.turns_since_state_change = 0;
    MapCoords p = pos;
    p.altitude = GetTerrainHeightAt(MetresOf(p.x), MetresOf(p.z));
    v.SetGoalPos(p);
}
// sub_5AC660. ponytail: the original asks the object for its own approach
// (vslot 32, e.g. an abode's door); straight to its position here.
void MoveToObjectThen(Villager& v, Object* o, uint8_t arrive) { MoveToPosThen(v, o->coords, arrive); }

// sub_6DE5A0 / sub_5C12D0: a point `r` metres from `from` at angle `a`.
MapCoords Around(const MapCoords& from, float a, float r) {
    return MapCoords(from.x + static_cast<int32_t>(std::cos(a) * r * kMapUnitsPerMetre),
                     from.z + static_cast<int32_t>(std::sin(a) * r * kMapUnitsPerMetre), from.altitude);
}
// sub_6DE3E0: the heading from a to b.
float Heading(const MapCoords& a, const MapCoords& b) {
    return std::atan2(static_cast<float>(b.z - a.z), static_cast<float>(b.x - a.x));
}
float DistanceM(const MapCoords& a, const MapCoords& b) {
    const float dx = MetresOf(b.x - a.x), dz = MetresOf(b.z - a.z);
    return std::sqrt(dx * dx + dz * dz);
}

// sub_6D9490: an emergency within the last TownInfo +272 turns (+0xF14).
bool TownInEmergency(Town* t) {
    uint32_t since, window = 0;
    std::memcpy(&since, reinterpret_cast<const char*>(t) + 0xF14, 4);
    if (t->info) std::memcpy(&window, reinterpret_cast<const char*>(t->info) + 272, 4);
    return since && g_game_turn - since < window;
}

bool Hungry(const Villager& v) { return v.food <= InfoF(v, 704); }                 // sub_6E2110
float HungerNeed(float food) { const float f = food < 1 ? food : 1; return 1.0f - f * f * f; }  // sub_6EAB60
float SleepNeed(const Villager& v) {                                               // sub_6EABC0
    const float t = InfoF(v, 860), life = v.life;
    const float x = (life - (t < life ? t : life)) / (1.0f - t);
    return 1.0f - x * x;
}
// sub_6E76E0: how much the villager's own needs press, against work.
float BusyFactor(Villager& v) {
    if (v.field_0xe0 & 1) return 0.0f;
    const float hunger = Hungry(v) ? HungerNeed(v.food) : 0.0f;
    const float hurt = 1.0f - v.life * v.life;
    float r = (hunger < hurt ? hunger : hurt) * 0.5f + (hunger > hurt ? hunger : hurt);
    if (v.IsChild() && r <= 0.11f) return 0.11f;
    return r >= 1.0f ? 1.0f : r;
}

void RandomIdle(Villager& v);
bool SleepHandler(Villager& v);

// sub_6EFE70: a homeless villager moves into its town's best abode with space.
bool HomelessMoveIn(Villager& v) {
    Town* t = v.GetTown();
    if (!t) return false;
    Abode* a = t->FindAbodeWithSpaceInTown(&v, 0.0f);
    if (!a) return false;
    a->AddVillagerToAbode(&v);  // also takes it off the homeless list
    SetState(v, VILLAGER_STATE_GO_HOME);
    return true;
}

// sub_6EED70: sleep or eat, whichever presses harder past `threshold`.
// ponytail: eating (sub_6EAEF0 -> sub_6EA9F0) is not translated yet.
bool SleepOrEat(Villager& v, float threshold) {
    const float eat = HungerNeed(v.food) - threshold;
    const float sleep = SleepNeed(v) - threshold;
    if (eat <= sleep || eat <= 0.0f) {
        if (sleep > 0.0f && SleepHandler(v)) return true;
    } else if (sleep > 0.0f) {
        return SleepHandler(v);
    }
    return false;
}

// sub_6EED30: worship (not yet), a job from the town's desires, then sleep/eat.
bool FindSomethingToDo(Villager& v) {
    if (Town* t = v.GetTown()) {
        if (t->desire.FindWorkForVillager(&v, BusyFactor(v))) {  // sub_6E76A0 -> sub_6D7D30
            v.field_0xe0 &= ~1u;
            return true;
        }
    }
    return SleepOrEat(v, InfoF(v, 908));
}

// sub_6EECB0
bool HomeOrWork(Villager& v) { return (!v.GetHome() && HomelessMoveIn(v)) || FindSomethingToDo(v); }

// sub_6E3630: a random way to pass the time.
void RandomIdle(Villager& v) {
    Abode* home = v.GetHome();
    Town* town = v.GetTown();
    switch (lh::Random(9)) {
    case 0:
        if ((home && home->IsFunctional()) || lh::Random(100) < 10) { SetState(v, VILLAGER_STATE_GO_HOME); return; }
        [[fallthrough]];
    case 1: case 2: case 3:
        if (home) { SetState(v, VILLAGER_STATE_GO_AND_CHILLOUT_OUTSIDE_HOME); return; }
        [[fallthrough]];
    case 4: case 5: case 6: case 7: case 8:
        if (town) {  // sub_6E3750: a spot out from the town towards the villager
            const float scale = 0.1f * [&] { float x = 0; if (town->info) std::memcpy(&x, reinterpret_cast<const char*>(town->info) + 320, 4); return x; }();
            const float a = Heading(town->coords, v.coords) + lh::RandomFloat(0.785398f) - 0.392699f;
            MoveToPosThen(v, Around(town->coords, a, lh::RandomFloat(scale * 9.0f) + scale), VILLAGER_STATE_SIT_AND_CHILLOUT);
            return;
        }
        [[fallthrough]];
    default:
        SetState(v, VILLAGER_STATE_GO_HOME);
    }
}

// sub_6EFF90: the Sleep desire's handler, and the sleep half of SleepOrEat.
bool SleepHandler(Villager& v) {
    if ((v.field_0xe0 & 1) && v.life >= InfoF(v, 860)) return false;
    if (!(v.field_0xe0 & 4)) {  // not inside
        if (v.GetHome()) { SetState(v, VILLAGER_STATE_GO_HOME); return true; }
        return v.action.top_state == VILLAGER_STATE_SLEEP_IN_TENT;
    }
    // ponytail: sub_6EF830 (the household turning in together) is not translated.
    SetState(v, VILLAGER_STATE_GOTO_BED_AT_HOME);
    return true;
}

// --- states -----------------------------------------------------------------

void MoveToPos(Villager& v) {  // 1, sub_5AAE80. ponytail: straight-line walking
    if (v.speed == 0) v.SetSpeed(static_cast<int>(InfoU(v, 260)) ? static_cast<int>(InfoU(v, 260)) : 200);
    v.MoveToGoal();  // stands in for the wall-hugging path code (sub_5C5BA0)
    if (v.move_state == MOVE_TO_STATES_ARRIVED) SetState(v, v.action.final_state);  // sub_5AB4E0
}

void Created(Villager& v) {  // 85, sub_6E38B0: wait out the timer, then decide
    if (v.turns_until_next_state_change-- == 0) {
        v.turns_until_next_state_change = 0;
        SetState(v, VILLAGER_STATE_DECIDE_WHAT_TO_DO);
    }
}

void DecideWhatToDo(Villager& v) {  // 163, vslot 561 (sub_6E1260)
    Town* t = v.GetTown();
    if (t && TownInEmergency(t)) { SetState(v, VILLAGER_STATE_GOTO_CONGREGATE_IN_TOWN_AFTER_EMERGENCY); return; }
    // ponytail: disciples (+0xE0 0x200/0x400, sub_6E13C0) and children
    // (sub_6E73E0) have their own deciders; not translated.
    SetState(v, VILLAGER_STATE_DECIDE_WHAT_TO_DO);
    if (HomeOrWork(v)) return;
    // sub_6E1380: carrying more than villager info +620 / +624 -> the store.
    if (v.resource_held[1] > static_cast<int16_t>(InfoU(v, 620)) ||
        v.resource_held[0] > static_cast<int16_t>(InfoU(v, 624))) {
        SetState(v, VILLAGER_STATE_GOTO_STORAGE_PIT_FOR_DROP_OFF);
        return;
    }
    RandomIdle(v);
}

void GoHome(Villager& v) {  // 36 / 121, sub_6EEF60(37, 238)
    if (Abode* home = v.GetHome()) {
        if (v.field_0xe0 & 4) SetState(v, VILLAGER_STATE_AT_HOME);
        else if (v.action.final_state != VILLAGER_STATE_ARRIVES_HOME) MoveToObjectThen(v, home, VILLAGER_STATE_ARRIVES_HOME);
        return;
    }
    Town* t = v.GetTown();
    if (!t) { SetState(v, VILLAGER_STATE_VAGRANT_START); return; }
    uint8_t arrive = v.action.top_state;
    MapCoords pos;
    if (DistanceM(v.coords, t->coords) <= 100.0f) {  // near town: somewhere to lie down
        pos = Around(v.coords, lh::RandomFloat(6.2831855f), lh::RandomFloat(8.0f) + 2.0f);
        arrive = VILLAGER_STATE_SLEEP_IN_TENT;  // ponytail: sub_6EF1D0's free-spot search
    } else {                                       // far: head for town
        const float a = Heading(t->coords, v.coords) + lh::RandomFloat(1.5707964f) - 0.785398f;
        pos = Around(t->coords, a, lh::RandomFloat(25.0f) + 10.0f);
    }
    MoveToPosThen(v, pos, arrive);
}

void ArrivesHome(Villager& v) {  // 37, sub_6EF610 (the parts that need no door or children)
    Abode* home = v.GetHome();
    if (!home) { SetState(v, VILLAGER_STATE_HOMELESS_START); return; }
    if (Hungry(v) && !home->IsFunctional()) { SetState(v, VILLAGER_STATE_DECIDE_WHAT_TO_DO); return; }
    v.field_0xe0 |= 4;  // sub_6E1B20: inside
    SetState(v, VILLAGER_STATE_AT_HOME);
}

void AtHome(Villager& v) {  // 38, sub_6EEBE0
    Town* t = v.GetTown();
    if (v.GetHome() && t && TownInEmergency(t)) { SetState(v, VILLAGER_STATE_GOTO_BED_AT_HOME); return; }
    // sub_6EEE30: sleep or eat at home when it presses (threshold x 0.9).
    if (SleepOrEat(v, InfoF(v, 908) * 0.9f)) return;
    if (HomeOrWork(v)) return;
    // sub_6EECE0: inside, one time in four stay put; otherwise go out.
    if ((v.field_0xe0 & 4) && lh::Random(4) == 0) {
        v.turns_until_next_state_change = 0;
        SetState(v, VILLAGER_STATE_GOTO_BED_AT_HOME);
        return;
    }
    v.field_0xe0 &= ~4u;
    RandomIdle(v);
}

void GotoBedAtHome(Villager& v) {  // 119, sub_6EF800: asleep for villager info +588 turns
    SetState(v, VILLAGER_STATE_SLEEPING_AT_HOME);
    v.turns_until_next_state_change = static_cast<int16_t>(InfoU(v, 588));
}

void SleepingAtHome(Villager& v) {  // 120, sub_6EFA40 -> sub_6EFA80
    if (!v.GetTown()) return;
    if (--v.turns_until_next_state_change > 0) return;
    // sub_6EFA80: still tired (below info +864) -> sleep another info +588 turns.
    if (v.life < InfoF(v, 864)) { v.turns_until_next_state_change = static_cast<int16_t>(InfoU(v, 588)); return; }
    SetState(v, VILLAGER_STATE_AT_HOME);
}

void GoAndChilloutOutsideHome(Villager& v) {  // 245, sub_6F9400
    Abode* home = v.GetHome();
    Town* t = v.GetTown();
    if (!home || !t) { SetState(v, VILLAGER_STATE_DECIDE_WHAT_TO_DO); return; }
    float r = 0;
    if (t->info) std::memcpy(&r, reinterpret_cast<const char*>(t->info) + 324, 4);
    // ponytail: sub_6F9620's spot choice; a point at that radius from home
    MoveToPosThen(v, Around(home->coords, Heading(home->coords, v.coords), r * 10.0f), VILLAGER_STATE_SIT_AND_CHILLOUT);
}

void SitAndChillout(Villager& v) {  // 246, sub_6F94F0
    if (v.turns_until_next_state_change-- > 0) return;
    v.turns_until_next_state_change = 0;
    Town* t = v.GetTown();
    if (t && TownInEmergency(t)) { SetState(v, VILLAGER_STATE_GOTO_CONGREGATE_IN_TOWN_AFTER_EMERGENCY); return; }
    if (HomeOrWork(v)) return;
    if (lh::Random(10) == 0) { RandomIdle(v); return; }
    v.turns_until_next_state_change = static_cast<int16_t>(InfoU(v, 918));
}

}  // namespace
}  // namespace vs

bool VillagerSleepHandler(Villager* v) { return vs::SleepHandler(*v); }

// vslot 392 (sub_6E01E0). ponytail: the per-turn upkeep (sub_6E05D0: hunger,
// life, the state info's effects), the second state slot and timed
// transitions are not translated yet; untranslated states hold, and after 300
// turns fall back to deciding so a villager is never stranded.
uint32_t Villager::ProcessState() {
    ++action.turns_since_state_change;
    switch (action.top_state) {
    case VILLAGER_STATE_MOVE_TO_POS: vs::MoveToPos(*this); break;
    case VILLAGER_STATE_CREATED: vs::Created(*this); break;
    case VILLAGER_STATE_DECIDE_WHAT_TO_DO: vs::DecideWhatToDo(*this); break;
    case VILLAGER_STATE_GO_HOME:
    case VILLAGER_STATE_WAKE_UP_AT_HOME: vs::GoHome(*this); break;
    case VILLAGER_STATE_ARRIVES_HOME: vs::ArrivesHome(*this); break;
    case VILLAGER_STATE_AT_HOME: vs::AtHome(*this); break;
    case VILLAGER_STATE_GOTO_BED_AT_HOME: vs::GotoBedAtHome(*this); break;
    case VILLAGER_STATE_SLEEPING_AT_HOME: vs::SleepingAtHome(*this); break;
    case VILLAGER_STATE_GO_AND_CHILLOUT_OUTSIDE_HOME: vs::GoAndChilloutOutsideHome(*this); break;
    case VILLAGER_STATE_SIT_AND_CHILLOUT: vs::SitAndChillout(*this); break;
    default:
        if (action.turns_since_state_change > 300) vs::SetState(*this, VILLAGER_STATE_DECIDE_WHAT_TO_DO);
        break;
    }
    return 1;
}
