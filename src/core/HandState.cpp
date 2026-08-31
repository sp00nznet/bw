// HandState — the hand's polymorphic interaction states.
//
// Translated from runblack_decrypted.exe (v1.0) via tools/decomp: the twelve
// HandState vftables, five to eight slots each (work/decomp/handstate.txt).
//
// What the original bodies mostly *do* is draw. HandStateNormal::Update is a
// hundred lines of mesh and animation calls; Holding::Update is seven hundred.
// Underneath that drawing is a small amount of real state-machine behaviour --
// an idle-clip latch that restarts the blend when the clip changes, a frame
// counter, a completion flag, a captured target, a lerp between two positions
// -- and that is what is translated here, at the field offsets the binary uses
// (see HandState.h). Every draw call funnels through the HandMachine hooks so
// renderer can be supplied later without touching these bodies again.
//
// Where a body depends on a subsystem core does not have -- the interface
// layer, the physics record table, the creature mind -- the comment says so
// rather than leaving a bare stub.

#include "black/HandState.h"

#include "black/HandMachine.h"
#include "black/GameThing.h"

#include <cstring>

namespace {

// dword_B5A228: the frame delta the animation code advances counters by. The
// original reads it from the global frame timer; the hand's Update is handed a
// delta instead, so it is carried here between the call and the state body.
uint32_t g_frame_delta = 1;

uint32_t AnimLength(uint32_t anim_id) {
    const HandDrawHooks& h = GetHandDrawHooks();
    uint32_t n = h.anim_length ? h.anim_length(anim_id) : 0;
    return n ? n : 1;  // never divide by zero when no renderer is installed
}

void DrawHand(HandMachine* hand, uint32_t anim_id, uint32_t frame, LHMatrix* xf) {
    const HandDrawHooks& h = GetHandDrawHooks();
    if (h.draw_hand) h.draw_hand(hand, anim_id, frame, xf);
}

}  // namespace

void SetHandFrameDelta(uint32_t delta) { g_frame_delta = delta ? delta : 1; }

// ---------------------------------------------------------------------------
// HandState base (vftable 0x8688f4)
// ---------------------------------------------------------------------------

void HandState::Enter() {
    // sub_4017c0: empty in the base; every state that has data resets it here.
}

void HandState::DrawTheHeldObject() {
    // sub_4b1e90: the base hand holds nothing, so there is nothing to draw.
}

void HandState::Exit() {
    // sub_4010e0: empty in the base.
}

void HandState::Update(float /*delta*/, LHMatrix* /*transform*/) {
    // sub_4010f0: empty in the base.
}

bool HandState::AllowCameraTricons() {
    // sub_403c20: the base forbids the camera tricons; only the states that
    // leave the camera alone (Normal, Camera, PlayAnim) allow them.
    return false;
}

// ---------------------------------------------------------------------------
// HandStateInvisible (vftable 0x80ad84)
// ---------------------------------------------------------------------------

void HandStateInvisible::Enter() {
    // sub_456E00: hides the cursor, then copies the hand's current bone
    // matrices over the previous-frame set so nothing interpolates in from
    // wherever the hand was when it vanished.
    if (!hand) return;
    hand->prev_screen[0] = hand->screen[0];
    hand->prev_screen[1] = hand->screen[1];
}

void HandStateInvisible::Exit() {
    // sub_456E40: restores the cursor. Nothing to do without an interface.
}

void HandStateInvisible::Update(float /*delta*/, LHMatrix* /*transform*/) {
    // sub_4017b0: nothing is drawn while the hand is invisible.
}

// ---------------------------------------------------------------------------
// HandStateNormal (vftable 0x83e9b8)
// ---------------------------------------------------------------------------

void HandStateNormal::Enter() {
    // sub_579910: clears the whole gesture-recognition scratch block (a run of
    // globals we do not have) and resets the idle animation. last_anim_id is
    // -1 so the first Update treats whatever clip it picks as a change and
    // starts the blend from the hand's current pose.
    anim_frame = 0;
    last_anim_id = -1;
    if (hand) hand->blend_time = hand->scale;
}

void HandStateNormal::Update(float /*delta*/, LHMatrix* transform) {
    // sub_57ADB0. The bulk of the original is three mesh draws (the hand plus
    // two lean/tilt overlays driven by how far the hand is from where the
    // mouse wants it). The state machine part is the clip latch: pick the idle
    // clip, wrap the frame counter on its length, and when the clip changes,
    // restart the animation blend.
    if (!hand) return;

    const uint32_t anim_id = hand->anim_params[0];
    anim_frame = (anim_frame + g_frame_delta) % AnimLength(anim_id);

    if (last_anim_id != static_cast<int32_t>(anim_id)) {
        last_anim_id = static_cast<int32_t>(anim_id);
        // sub_4572F0 restarts the blend; the original then draws with the
        // hand's blend duration rather than the frame delta.
        hand->blend_time = hand->scale;
        // Clip 15 is the one the original phase-shifts by half a cycle when
        // the player is in interface mode 21, so two hands do not draw in
        // lockstep. Without the interface we always start it at zero.
        if (anim_id == 15) anim_frame = 0;
    }

    // The lean overlays are driven by the clamped screen-space error; kept
    // here because it is the hand's actual behaviour, not decoration.
    for (int axis = 0; axis < 2; ++axis) {
        float error = hand->screen[axis] - hand->target_screen[axis];
        if (error < -80.0f) error = -80.0f;
        if (error > 80.0f) error = 80.0f;
        hand->screen[axis] = hand->target_screen[axis] + error;
    }

    DrawHand(hand, anim_id, anim_frame, transform);
    hand->prev_screen[0] = hand->screen[0];
    hand->prev_screen[1] = hand->screen[1];
}

// ---------------------------------------------------------------------------
// HandStateCamera (vftable 0x83e870)
// ---------------------------------------------------------------------------

void HandStateCamera::Enter() {
    // sub_5740C0: snapshots the camera's origin, heading and focus into the
    // 0xCC-byte block so Update can drag relative to where the drag started.
    // The block's layout needs GCamera's save/restore path decompiled; until
    // then it is zeroed so a fresh drag never starts from stale values.
    field_0x8 = 0;
    std::memset(field_0xc, 0, sizeof(field_0xc));
}

bool HandStateCamera::AllowCameraTricons() {
    // sub_401710: the camera state is the one that owns the tricons.
    return true;
}

// ---------------------------------------------------------------------------
// HandStateTug (vftable 0x83ea34)
// ---------------------------------------------------------------------------

void HandStateTug::Enter() {
    // sub_57B970: captures the tugged object, the grab point on it, and the
    // rubber-band rest length into the 0x140-byte block. Needs the object
    // physics record we do not carry; zeroed for a clean start.
    field_0x8 = 0;
    std::memset(field_0xc, 0, sizeof(field_0xc));
}

void HandStateTug::DrawTheHeldObject() {
    // sub_579820: forwards to the held object's own draw-in-hand virtual.
    if (!hand || !hand->held) return;
    const HandDrawHooks& h = GetHandDrawHooks();
    if (h.draw_held) h.draw_held(hand, hand->held);
}

void HandStateTug::Update(float /*delta*/, LHMatrix* transform) {
    // sub_57BBF0: the rubber band -- pull the object toward the hand, feed the
    // strain back into the hand's pose, and break the tug when it exceeds the
    // object's limit. All of that runs through the physics solver, so what is
    // left here is drawing the hand and the object it is pulling on.
    if (!hand) return;
    DrawHand(hand, hand->anim_params[0], 0, transform);
    DrawTheHeldObject();
}

// ---------------------------------------------------------------------------
// HandStateHolding (vftable 0x83e958)
// ---------------------------------------------------------------------------

void HandStateHolding::Enter() {
    // sub_577780: takes the object out of the world and into the hand, sizing
    // the hand pose to it. The sizing needs the object's mesh bounds.
    field_0x8 = 0;
    field_0xc = 0;
    std::memset(field_0x10, 0, sizeof(field_0x10));
}

void HandStateHolding::DrawTheHeldObject() {
    // sub_579360: normally draws the held object; skipped while the interface
    // is dragging that same object, so it is not drawn twice.
    if (!hand || !hand->held) return;
    const HandDrawHooks& h = GetHandDrawHooks();
    if (h.draw_held) h.draw_held(hand, hand->held);
}

void HandStateHolding::Update(float /*delta*/, LHMatrix* transform) {
    // sub_577900, the largest body in the family: hand pose, held-object
    // orientation, drop/throw prediction arc, and the highlight on whatever is
    // under the object. All of it is drawing and picking.
    if (!hand) return;
    DrawHand(hand, hand->anim_params[0], 0, transform);
    DrawTheHeldObject();
}

bool HandStateHolding::AllowCameraTricons() {
    // sub_577730: allowed only when the player's creature is not itself being
    // held -- otherwise the tricons would fight the creature interface.
    return true;
}

float HandStateHolding::GetDrawX() { return 0.0f; }  // sub_7075E0
float HandStateHolding::GetDrawZ() { return 0.0f; }  // sub_7075E0

void HandStateHolding::GetHeldPos(float* out_xyz) {
    // nullsub_1: the plain holding state has no separate held position -- the
    // object is simply at the hand.
    if (!out_xyz || !hand) return;
    out_xyz[0] = hand->pos[0];
    out_xyz[1] = hand->pos[1];
    out_xyz[2] = hand->pos[2];
}

// ---------------------------------------------------------------------------
// HandStateTotem (vftable 0x83e9fc)
// ---------------------------------------------------------------------------

void HandStateTotem::Enter() {
    // sub_57B240: finds the player's totem, measures its top (the statue's own
    // height if it has one, otherwise the object's bounding height) and parks
    // the hand there with the cursor hidden.
    field_0x8 = 0;
    totem_top_y = 0.0f;
    if (!hand) return;
    // The original measures the totem statue's own top (or the object's
    // bounding height when it has no statue); both read the physics record
    // table, so the hand's current height stands in until that lands.
    totem_top_y = hand->pos[1];
}

void HandStateTotem::Exit() {
    // sub_57B340: clears the "hand is on the totem" global.
}

void HandStateTotem::Update(float /*delta*/, LHMatrix* transform) {
    // sub_57B350: draws the hand hovering over the totem and the offering it
    // is about to place.
    if (!hand) return;
    hand->pos[1] = totem_top_y;
    DrawHand(hand, hand->anim_params[0], 0, transform);
}

// ---------------------------------------------------------------------------
// HandStateMultiPickUp (vftable 0x83e984)
// ---------------------------------------------------------------------------

void HandStateMultiPickUp::Enter() {
    // sub_5793B0: same setup as Totem -- take the player's current target,
    // point the hand at it, hide the cursor. The state itself carries no data.
}

void HandStateMultiPickUp::DrawTheHeldObject() {
    // sub_579820: forwards to the held object's draw-in-hand virtual.
    if (!hand || !hand->held) return;
    const HandDrawHooks& h = GetHandDrawHooks();
    if (h.draw_held) h.draw_held(hand, hand->held);
}

// ---------------------------------------------------------------------------
// HandStateCreature (vftable 0x83e8c8)
// ---------------------------------------------------------------------------

void HandStateCreature::Enter() {
    // sub_575160: latches the creature being handled plus the leash and the
    // gesture the player is making at it, into the 0x118-byte block. The block
    // is the creature interaction context; it needs CreatureMental's command
    // state decompiled before the fields can be named.
    std::memset(field_0x8, 0, sizeof(field_0x8));
}

// ---------------------------------------------------------------------------
// HandStateGrain (vftable 0x83e918)
// ---------------------------------------------------------------------------

namespace {
// The global the original lerps the grain position by (dword_C22CA4 + 0x201CE0).
// It is the offering animation's progress, 0 at the hand and 1 at the target.
float g_grain_alpha = 0.0f;
}  // namespace

void SetGrainOfferProgress(float alpha) { g_grain_alpha = alpha; }

float HandStateGrain::GetDrawX() {
    // sub_576A60: lerp(source, target, alpha), written as
    // (target - source) * alpha + source.
    return (target_x - source_x) * g_grain_alpha + source_x;
}

float HandStateGrain::GetDrawZ() {
    // sub_576A40
    return (target_z - source_z) * g_grain_alpha + source_z;
}

void HandStateGrain::GetHeldPos(float* out_xyz) {
    // sub_576FB0: while a target creature is set, the grain is drawn at that
    // creature's mouth bone; otherwise it falls back to the stored position,
    // and if that was never set the caller's vector is left untouched.
    if (!out_xyz) return;
    if (target_object) {
        // The mouth bone comes out of the creature's animation state, which
        // core does not evaluate; the hand position is the closest stand-in.
        if (hand) {
            out_xyz[0] = hand->pos[0];
            out_xyz[1] = hand->pos[1];
            out_xyz[2] = hand->pos[2];
        }
        return;
    }
    if (!fallback_valid) return;
    out_xyz[0] = fallback_pos[0];
    out_xyz[1] = fallback_pos[1];
    out_xyz[2] = fallback_pos[2];
}

void HandStateGrain::Exit() {
    // sub_576FA0: stop offering and forget the target.
    feeding = 0;
    target_object = nullptr;
}

// ---------------------------------------------------------------------------
// HandStatePlayAnim (vftable 0x83e9dc)
// ---------------------------------------------------------------------------

void HandStatePlayAnim::Enter() {
    // sub_57B0F0: empty -- the clip and position are set by whoever requested
    // the animation, before the state is entered.
}

void HandStatePlayAnim::Update(float /*delta*/, LHMatrix* transform) {
    // sub_57B100: pin the hand to the requested position, advance the clip,
    // and clear the hand's playing_anim flag once the clip has run out. That
    // flag is what the script side polls to know the gesture finished.
    if (!hand) return;
    if (!started) started = 1;

    hand->pos[0] = anim_pos[0];
    hand->pos[1] = anim_pos[1];
    hand->pos[2] = anim_pos[2];

    DrawHand(hand, anim_id, anim_frame, transform);
    hand->prev_screen[0] = hand->screen[0];
    hand->prev_screen[1] = hand->screen[1];

    anim_frame += g_frame_delta;
    if (anim_frame >= AnimLength(anim_id)) hand->playing_anim = false;
}

// ---------------------------------------------------------------------------
// HandStateCitadel (vftable 0x83e89c)
// ---------------------------------------------------------------------------

void HandStateCitadel::Enter() {
    // sub_5749B0: snapshots the citadel interface layout into the 0xC4-byte
    // block. The citadel interface is not implemented.
    field_0x8 = 0;
    std::memset(field_0xc, 0, sizeof(field_0xc));
}

void HandStateCitadel::Update(float /*delta*/, LHMatrix* transform) {
    if (!hand) return;
    DrawHand(hand, hand->anim_params[0], 0, transform);
}
