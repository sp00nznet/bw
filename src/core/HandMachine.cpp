// HandMachine — owner of the eleven HandState objects and the transitions
// between them. See HandMachine.h for why this is host-shaped rather than a
// copy of the original's layout; the authentic HandMachine struct lives in HandMachine.h.

#include "black/HandMachine.h"

#include "black/GameThing.h"

HandMachine g_hand;

namespace {

HandDrawHooks g_hooks;

// One instance of every state, as the original does: the states are long-lived
// objects that keep their data between visits, not things allocated per
// transition. Enter is what resets them.
HandStateInvisible   s_invisible;
HandStateNormal      s_normal;
HandStateCamera      s_camera;
HandStateTug         s_tug;
HandStateHolding     s_holding;
HandStateTotem       s_totem;
HandStateMultiPickUp s_multi_pickup;
HandStateCreature    s_creature;
HandStateGrain       s_grain;
HandStatePlayAnim    s_play_anim;
HandStateCitadel     s_citadel;

HandState* StateFor(HAND_STATES id) {
    switch (id) {
        case HAND_STATE_INVISIBLE:     return &s_invisible;
        case HAND_STATE_NORMAL:        return &s_normal;
        case HAND_STATE_CAMERA:        return &s_camera;
        case HAND_STATE_TUG:           return &s_tug;
        case HAND_STATE_HOLDING:       return &s_holding;
        case HAND_STATE_TOTEM:         return &s_totem;
        case HAND_STATE_MULTI_PICK_UP: return &s_multi_pickup;
        case HAND_STATE_CREATURE:      return &s_creature;
        case HAND_STATE_GRAIN:         return &s_grain;
        case HAND_STATE_PLAY_ANIM:     return &s_play_anim;
        case HAND_STATE_CITADEL:       return &s_citadel;
        default:                       return &s_invisible;
    }
}

}  // namespace

void SetHandDrawHooks(const HandDrawHooks& hooks) { g_hooks = hooks; }
const HandDrawHooks& GetHandDrawHooks() { return g_hooks; }

void HandMachine::Init() {
    for (int i = 0; i < _HAND_STATES_COUNT; ++i)
        StateFor(static_cast<HAND_STATES>(i))->hand = this;
    state_id = HAND_STATE_INVISIBLE;
    state = StateFor(state_id);
    state->Enter();
}

void HandMachine::Shutdown() {
    if (state) state->Exit();
    state = nullptr;
}

void HandMachine::SetState(HAND_STATES id) {
    if (state && id == state_id) return;  // Enter resets state data; do not re-run it
    if (state) state->Exit();
    state_id = id;
    state = StateFor(id);
    state->hand = this;
    state->Enter();
}

void HandMachine::Update(float delta_time, LHMatrix* transform) {
    if (!state) Init();
    // The original advances animation counters by a global frame delta in
    // animation ticks; the viewer runs at BW's 10 Hz sim rate, so one tick per
    // update is the same cadence.
    SetHandFrameDelta(delta_time > 0.0f ? 1u : 0u);
    state->Update(delta_time, transform);
}

void HandMachine::DrawTheHeldObject() {
    if (state) state->DrawTheHeldObject();
}

HAND_STATES HandMachine::ChooseState(const HandInput& in) {
    // The original drives these transitions from its interface layer, which we
    // do not have. This is our ordering over the same inputs: a scripted
    // animation owns the hand outright, then the modal interfaces, then what
    // the hand is carrying, then what it is pulling on, then rest.
    if (in.scripted_anim) return HAND_STATE_PLAY_ANIM;
    if (!in.over_land)    return HAND_STATE_INVISIBLE;
    if (in.citadel)       return HAND_STATE_CITADEL;
    if (in.camera_drag)   return HAND_STATE_CAMERA;
    if (in.over_totem)    return HAND_STATE_TOTEM;
    if (in.over_creature) return HAND_STATE_CREATURE;
    if (in.multi_pickup)  return HAND_STATE_MULTI_PICK_UP;
    if (in.holding)       return in.holding_grain ? HAND_STATE_GRAIN
                                                  : HAND_STATE_HOLDING;
    if (in.tugging)       return HAND_STATE_TUG;
    return HAND_STATE_NORMAL;
}
