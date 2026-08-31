#pragma once
// HandMachine — the live hand: what the HandState machine actually acts on.
//
// Not to be confused with `HandMachine` in HandMachine.h, which is the real 0x49C4 struct
// from the vendor headers (a Morphable plus the CHand_State union of the eleven
// state pointers). That layout is authentic and stays as it is; this is the
// host-side working set that sits beside it.
//
// The original HandMachine is shared with the renderer, the interface layer and the
// animation system, and the HandState bodies reach into it at raw offsets. We
// do not have those subsystems, so this holds only the fields the state machine
// actually reads, each annotated with the original offset it came from
// (tools/decomp, vtable dump of the 12 HandState classes). It is deliberately
// NOT byte-compatible: filling 18 KB we cannot populate would be pretence, and
// nothing here is loaded from or written to a file.
//
// What IS faithful is the shape: one polymorphic HandState object per state,
// Exit-then-Enter on every transition, and each state carrying its own data at
// the offsets the binary uses (see HandState.h).

#include <cstdint>

#include "HandState.h"

struct GameThing;
struct LHMatrix;

// What the interface layer knows about the player's hand this frame. The
// original decides transitions inside its input/interface code, which we do
// not have; ChooseState below is our ordering over the same inputs, kept in
// one place so it is obvious what drives the machine.
struct HandInput {
    bool over_land     = true;   // cursor is on terrain, not sky
    bool holding       = false;  // an object is in the hand
    bool camera_drag   = false;  // camera is being dragged with the hand
    bool tugging       = false;  // pulling on something rooted in the map
    bool over_creature = false;  // interacting with the creature
    bool over_totem    = false;  // interacting with a town totem
    bool multi_pickup  = false;  // gathering several objects at once
    bool holding_grain = false;  // the held object is grain/food being fed
    bool scripted_anim = false;  // a script is playing a hand animation
    bool citadel       = false;  // inside the citadel interface
};

struct HandMachine {
    // --- world / screen -----------------------------------------------
    float pos[3] = {0, 0, 0};        // original +120 .. +131
    float screen[2] = {0, 0};        // original +18616 / +18620
    float target_screen[2] = {0, 0}; // original +18524 / +18528
    float prev_screen[2] = {0, 0};   // original +18644 / +18648 (latched each frame)

    // --- drawing ------------------------------------------------------
    // The states pass these straight to the mesh/animation draw calls. We have
    // no such renderer in core, so they are carried and handed to the draw
    // hook below; the viewer supplies drawing if it wants it.
    float    scale = 1.0f;      // original +18516
    float    blend_time = 0.0f; // original +18416
    uint32_t mesh_set = 0;      // original +152 (indexes the mesh array at +180)
    uint32_t anim_params[3] = {0, 0, 0};  // original +18420 / +18424 / +18428

    // --- interaction --------------------------------------------------
    GameThing* held = nullptr;   // original +18692 -- the object in the hand
    bool playing_anim = false;   // original +18716 -- cleared when a clip ends

    // --- state machine ------------------------------------------------
    HandState* state = nullptr;
    HAND_STATES state_id = HAND_STATE_INVISIBLE;

    void Init();
    void Shutdown();

    // Exit the current state and Enter the new one. Re-entering the same state
    // is a no-op, matching the original: Enter is what resets a state's data,
    // so calling it every frame would wipe frame counters and anim latches.
    void SetState(HAND_STATES id);

    void Update(float delta_time, LHMatrix* transform);

    HAND_STATES GetState() const { return state_id; }
    HandState*  GetStateObject() const { return state; }

    // Ask a state to draw whatever it is holding (vtable slot 1).
    void DrawTheHeldObject();

    // Which state these inputs call for. Priority runs from the states that
    // take the hand over completely down to the resting one.
    static HAND_STATES ChooseState(const HandInput& in);
};

extern HandMachine g_hand;

// The state bodies are almost entirely mesh and animation draw calls into a
// renderer core does not own. Rather than stub each call site, the states
// funnel them through this hook; the viewer can install one to actually draw.
struct HandDrawHooks {
    // Draw the hand's animated mesh: (hand, anim id, frame, transform).
    void (*draw_hand)(HandMachine* hand, uint32_t anim_id, uint32_t frame,
                      LHMatrix* transform) = nullptr;
    // Draw whatever object the hand is holding.
    void (*draw_held)(HandMachine* hand, GameThing* held) = nullptr;
    // Frames in an animation clip, used to know when a clip has finished.
    uint32_t (*anim_length)(uint32_t anim_id) = nullptr;
};

void SetHandDrawHooks(const HandDrawHooks& hooks);
const HandDrawHooks& GetHandDrawHooks();

// How far through the offering animation the grain is, 0 at the hand and 1 at
// the creature: the original reads it from a global the interface animates
// (dword_C22CA4 + 0x201CE0). HandStateGrain lerps its drawn position by it.
void SetGrainOfferProgress(float alpha);

// Animation ticks to advance a state's frame counter by (dword_B5A228).
void SetHandFrameDelta(uint32_t delta);
