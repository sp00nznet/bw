// test_hand — the hand's polymorphic state machine.
//
// The state bodies are mostly drawing, which this cannot check. What it does
// check is the machine itself: that the right state is chosen, that a
// transition runs Exit then Enter (and that staying put does NOT re-run Enter,
// which would wipe the frame counters every frame), and the per-state
// behaviour that survives translation -- Normal's idle-clip latch, PlayAnim's
// completion flag, and Grain's offer lerp.

#include <black/CHand.h>
#include <black/HandState.h>

#include <cstdio>
#include <cmath>

static int g_fail = 0;
#define CHECK(cond, msg) do { if (!(cond)) { printf("FAIL: %s\n", msg); ++g_fail; } \
                              else printf("ok  : %s\n", msg); } while (0)

static uint32_t StubAnimLength(uint32_t /*anim_id*/) { return 4; }

static int g_draws = 0;
static void StubDrawHand(CHand*, uint32_t, uint32_t, LHMatrix*) { ++g_draws; }

int main() {
    HandDrawHooks hooks;
    hooks.anim_length = StubAnimLength;
    hooks.draw_hand = StubDrawHand;
    SetHandDrawHooks(hooks);

    // --- state selection --------------------------------------------------
    HandInput in;
    CHECK(CHand::ChooseState(in) == HAND_STATE_NORMAL, "idle hand rests in NORMAL");

    in.over_land = false;
    CHECK(CHand::ChooseState(in) == HAND_STATE_INVISIBLE, "off the land the hand hides");

    in = HandInput();
    in.holding = true;
    CHECK(CHand::ChooseState(in) == HAND_STATE_HOLDING, "carrying something is HOLDING");
    in.holding_grain = true;
    CHECK(CHand::ChooseState(in) == HAND_STATE_GRAIN, "carrying grain is the GRAIN state");

    in = HandInput();
    in.tugging = true;
    CHECK(CHand::ChooseState(in) == HAND_STATE_TUG, "pulling on something is TUG");

    in = HandInput();
    in.over_creature = true;
    in.holding = true;
    CHECK(CHand::ChooseState(in) == HAND_STATE_CREATURE,
          "the creature interface outranks what the hand is carrying");

    in = HandInput();
    in.scripted_anim = true;
    in.over_land = false;
    in.holding = true;
    CHECK(CHand::ChooseState(in) == HAND_STATE_PLAY_ANIM,
          "a scripted animation takes the hand over everything else");

    // --- transitions ------------------------------------------------------
    CHand hand;
    hand.Init();
    CHECK(hand.GetState() == HAND_STATE_INVISIBLE, "hand starts invisible");
    CHECK(hand.GetStateObject() != nullptr, "a state object is live from Init");
    CHECK(hand.GetStateObject()->hand == &hand, "the state points back at its hand");

    hand.SetState(HAND_STATE_NORMAL);
    CHECK(hand.GetState() == HAND_STATE_NORMAL, "transition to NORMAL took");
    HandStateNormal* normal = static_cast<HandStateNormal*>(hand.GetStateObject());
    CHECK(normal->last_anim_id == -1, "Enter reset the idle-clip latch");

    // --- Normal: the idle clip latch and frame counter ---------------------
    hand.anim_params[0] = 3;              // clip 3, four frames long
    hand.Update(0.1f, nullptr);
    CHECK(normal->last_anim_id == 3, "first Update latches the clip it drew");
    CHECK(normal->anim_frame == 1, "frame counter advanced");

    hand.Update(0.1f, nullptr);
    hand.Update(0.1f, nullptr);
    CHECK(normal->anim_frame == 3, "frame counter keeps advancing within the clip");
    hand.Update(0.1f, nullptr);
    CHECK(normal->anim_frame == 0, "frame counter wraps on the clip length");

    // Re-selecting the same state must not restart it: Enter is what clears
    // the counter, so running it every frame would freeze the animation.
    normal->anim_frame = 2;
    hand.SetState(HAND_STATE_NORMAL);
    CHECK(normal->anim_frame == 2, "re-entering the same state does not reset it");

    // A different clip restarts the blend.
    hand.anim_params[0] = 7;
    hand.Update(0.1f, nullptr);
    CHECK(normal->last_anim_id == 7, "changing clip re-latches");

    CHECK(g_draws > 0, "the state drew through the hook");

    // --- PlayAnim: the completion flag scripts poll -------------------------
    hand.playing_anim = true;
    hand.SetState(HAND_STATE_PLAY_ANIM);
    HandStatePlayAnim* play = static_cast<HandStatePlayAnim*>(hand.GetStateObject());
    play->anim_id = 1;
    play->anim_frame = 0;
    play->started = 0;
    play->anim_pos[0] = 10.0f;
    play->anim_pos[1] = 20.0f;
    play->anim_pos[2] = 30.0f;

    hand.Update(0.1f, nullptr);
    CHECK(play->started == 1, "PlayAnim marks itself started on the first Update");
    CHECK(hand.pos[0] == 10.0f && hand.pos[1] == 20.0f && hand.pos[2] == 30.0f,
          "PlayAnim pins the hand to the requested position");
    CHECK(hand.playing_anim, "clip is still running");

    for (int i = 0; i < 4; ++i) hand.Update(0.1f, nullptr);
    CHECK(!hand.playing_anim, "playing_anim clears once the clip has run out");

    // --- Grain: the offer lerp and Exit ------------------------------------
    hand.SetState(HAND_STATE_GRAIN);
    HandStateGrain* grain = static_cast<HandStateGrain*>(hand.GetStateObject());
    grain->source_x = 0.0f;   grain->target_x = 10.0f;
    grain->source_z = 4.0f;   grain->target_z = 8.0f;
    grain->feeding = 1;
    grain->target_object = reinterpret_cast<GameThing*>(1);

    SetGrainOfferProgress(0.0f);
    CHECK(grain->GetDrawX() == 0.0f && grain->GetDrawZ() == 4.0f,
          "at progress 0 the grain draws at the source");
    SetGrainOfferProgress(1.0f);
    CHECK(grain->GetDrawX() == 10.0f && grain->GetDrawZ() == 8.0f,
          "at progress 1 the grain draws at the target");
    SetGrainOfferProgress(0.5f);
    CHECK(std::fabs(grain->GetDrawX() - 5.0f) < 1e-5f &&
          std::fabs(grain->GetDrawZ() - 6.0f) < 1e-5f,
          "halfway through, the grain draws halfway");

    // Grain overrides the three virtuals Holding declares; the override must
    // actually be reached through a Holding* to prove the vtable is right.
    HandStateHolding* as_holding = grain;
    SetGrainOfferProgress(1.0f);
    CHECK(as_holding->GetDrawX() == 10.0f,
          "Grain's override is reached through the Holding interface");

    hand.SetState(HAND_STATE_NORMAL);
    CHECK(grain->feeding == 0 && grain->target_object == nullptr,
          "leaving GRAIN stops the offer and forgets the target");

    // A plain Holding does not lerp -- it reports zero, as the binary does.
    hand.SetState(HAND_STATE_HOLDING);
    HandStateHolding* holding = static_cast<HandStateHolding*>(hand.GetStateObject());
    CHECK(holding->GetDrawX() == 0.0f && holding->GetDrawZ() == 0.0f,
          "plain HOLDING has no offer interpolation");

    // --- camera tricons ---------------------------------------------------
    hand.SetState(HAND_STATE_CAMERA);
    CHECK(hand.GetStateObject()->AllowCameraTricons(), "CAMERA allows the tricons");
    hand.SetState(HAND_STATE_TUG);
    CHECK(!hand.GetStateObject()->AllowCameraTricons(), "TUG does not");

    hand.Shutdown();
    printf(g_fail ? "\n%d FAILURE(S)\n" : "\nALL PASS\n", g_fail);
    return g_fail ? 1 : 0;
}
