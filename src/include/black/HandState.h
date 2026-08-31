#pragma once
// HandState — hand interaction state machine
// Struct layout from bw1-decomp (HandState.h and HandState*.h)
//
// Size: 0x8 bytes (own vtable hierarchy, NOT Base-derived)
// Vtable: 5 entries (Enter, DrawTheHeldObject, Exit, Update, AllowCameraTricons)
//
// Also defines all 11 HandState subclasses:
//   HandStateInvisible (0x8), HandStateNormal (0x10), HandStateCamera (0xD8),
//   HandStateTug (0x14C), HandStateHolding (0x144), HandStateTotem (0xAC),
//   HandStateMultiPickUp (0x8), HandStateCreature (0x120), HandStateGrain (0x228),
//   HandStatePlayAnim (0x20), HandStateCitadel (0xD0)

#include <cstdint>

struct CHand;
struct GameThing;
struct LHMatrix;

// Hand state enumeration
enum HAND_STATES : uint32_t {
    HAND_STATE_INVISIBLE      = 0x0,
    HAND_STATE_NORMAL         = 0x1,
    HAND_STATE_CAMERA         = 0x2,
    HAND_STATE_TUG            = 0x3,
    HAND_STATE_HOLDING        = 0x4,
    HAND_STATE_TOTEM          = 0x5,
    HAND_STATE_MULTI_PICK_UP  = 0x6,
    HAND_STATE_CREATURE       = 0x7,
    HAND_STATE_GRAIN          = 0x8,
    HAND_STATE_PLAY_ANIM      = 0x9,
    HAND_STATE_CITADEL        = 0xA,
    _HAND_STATES_COUNT        = 0xB
};

struct HandState {
    virtual void Enter();                                  // vtable[0]
    virtual void DrawTheHeldObject();                      // vtable[1]
    virtual void Exit();                                   // vtable[2]
    virtual void Update(float param_1, LHMatrix* param_2); // vtable[3]
    virtual bool AllowCameraTricons();                     // vtable[4]

    CHand* hand;   // 0x04
};
static_assert(sizeof(HandState) == 0x8, "HandState size mismatch");

// --- Subclasses ---

struct HandStateInvisible : public HandState {
    void Enter() override;
    void Exit() override;
    void Update(float param_1, LHMatrix* param_2) override;
};
static_assert(sizeof(HandStateInvisible) == 0x8, "HandStateInvisible size mismatch");

struct HandStateNormal : public HandState {
    void Enter() override;
    void Update(float param_1, LHMatrix* param_2) override;

    // sub_579910 / sub_57ADB0: the resting hand cycles an idle animation and
    // latches which clip it is on, so a change of clip restarts the blend.
    uint32_t anim_frame;    // 0x08 — advanced by the frame delta, wraps on clip length
    int32_t  last_anim_id;  // 0x0C — -1 until the first Update picks a clip
};
static_assert(sizeof(HandStateNormal) == 0x10, "HandStateNormal size mismatch");

struct HandStateCamera : public HandState {
    void Enter() override;
    bool AllowCameraTricons() override;

    uint32_t field_0x8;          // 0x08
    uint8_t  field_0xc[0xCC];   // 0x0C
};
static_assert(sizeof(HandStateCamera) == 0xD8, "HandStateCamera size mismatch");

struct HandStateTug : public HandState {
    void Enter() override;
    void DrawTheHeldObject() override;
    void Update(float param_1, LHMatrix* param_2) override;

    uint32_t field_0x8;          // 0x08
    uint8_t  field_0xc[0x140];  // 0x0C
};
static_assert(sizeof(HandStateTug) == 0x14C, "HandStateTug size mismatch");

struct HandStateHolding : public HandState {
    void Enter() override;
    void DrawTheHeldObject() override;
    void Update(float param_1, LHMatrix* param_2) override;
    bool AllowCameraTricons() override;

    // Holding adds three virtuals of its own (slots 5..7 in the binary); only
    // Grain overrides them, to interpolate the held position while feeding.
    virtual float GetDrawX();                 // vtable[5] - sub_7075E0, returns 0
    virtual float GetDrawZ();                 // vtable[6] - sub_7075E0, returns 0
    virtual void  GetHeldPos(float* out_xyz); // vtable[7] - nullsub_1, no-op

    uint32_t   field_0x8;            // 0x08
    uint32_t   field_0xc;            // 0x0C
    uint8_t    field_0x10[0x104];    // 0x10 - held-object bookkeeping, not mapped
    // Named from HandStateGrain's slots 5/6/7 and Exit, which reach into this
    // region: the offer animation lerps drawn position from source to target.
    float      target_x;             // 0x114
    float      target_z;             // 0x118
    float      source_x;             // 0x11C
    float      source_z;             // 0x120
    uint8_t    feeding;              // 0x124 - cleared by HandStateGrain::Exit
    uint8_t    pad_0x125[3];         // 0x125
    uint8_t    field_0x128[0x14];    // 0x128
    GameThing* target_object;        // 0x13C - cleared by HandStateGrain::Exit
    uint8_t    field_0x140[0x4];     // 0x140
};
static_assert(sizeof(HandStateHolding) == 0x144, "HandStateHolding size mismatch");

struct HandStateTotem : public HandState {
    void Enter() override;
    void Exit() override;
    void Update(float param_1, LHMatrix* param_2) override;

    // sub_57B240: Enter measures the totem's top and parks the hand above it.
    uint32_t field_0x8;         // 0x08 — cleared on Enter
    uint8_t  field_0xc[0x9C];   // 0x0C
    float    totem_top_y;       // 0xA8 — world height of the totem's top
};
static_assert(sizeof(HandStateTotem) == 0xAC, "HandStateTotem size mismatch");

struct HandStateMultiPickUp : public HandState {
    void Enter() override;
    void DrawTheHeldObject() override;
};
static_assert(sizeof(HandStateMultiPickUp) == 0x8, "HandStateMultiPickUp size mismatch");

struct HandStateCreature : public HandState {
    void Enter() override;

    uint8_t field_0x8[0x118];  // 0x08
};
static_assert(sizeof(HandStateCreature) == 0x120, "HandStateCreature size mismatch");

struct HandStateGrain : public HandStateHolding {
    float GetDrawX() override;
    float GetDrawZ() override;
    void  GetHeldPos(float* out_xyz) override;
    void  Exit() override;

    uint8_t  field_0x144[0xA8];   // 0x144
    float    fallback_pos[3];     // 0x1EC - used when no target creature is set
    uint32_t fallback_valid;      // 0x1F8
    uint8_t  field_0x1fc[0x2C];   // 0x1FC
};
static_assert(sizeof(HandStateGrain) == 0x228, "HandStateGrain size mismatch");

struct HandStatePlayAnim : public HandState {
    void Enter() override;
    void Update(float param_1, LHMatrix* param_2) override;

    // sub_57B100: a scripted clip played at a fixed world position. The hand's
    // playing_anim flag is cleared once the frame counter passes clip length.
    float    anim_pos[3];   // 0x08 — world position the hand is pinned to
    uint32_t anim_id;       // 0x14
    uint32_t anim_frame;    // 0x18
    uint32_t started;       // 0x1C — set on the first Update
};
static_assert(sizeof(HandStatePlayAnim) == 0x20, "HandStatePlayAnim size mismatch");

struct HandStateCitadel : public HandState {
    void Enter() override;
    void Update(float param_1, LHMatrix* param_2) override;

    uint32_t field_0x8;         // 0x08
    uint8_t  field_0xc[0xC4];  // 0x0C
};
static_assert(sizeof(HandStateCitadel) == 0xD0, "HandStateCitadel size mismatch");
