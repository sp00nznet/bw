#pragma once
// CHand — player hand (cursor) entity, extends Morphable
// Struct layout from bw1-decomp
// Size: 0x49C4 bytes
//
// The hand is the primary player interaction device. It contains
// a Morphable (0x4834 bytes) plus hand state machines, physics,
// and interface system data.

#include "Morphable.h"

struct GInterfaceStatus;
struct HandFX;
struct HandState;
struct HandStateCamera;
struct HandStateCitadel;
struct HandStateCreature;
struct HandStateGrain;
struct HandStateHolding;
struct HandStateInvisible;
struct HandStateMultiPickUp;
struct HandStateNormal;
struct HandStatePlayAnim;
struct HandStateTotem;
struct HandStateTug;
struct LHMatrix;

struct ControlHandUpdateInfo {
    uint8_t field_0x0;  // 0x00
};
static_assert(sizeof(ControlHandUpdateInfo) == 0x1, "ControlHandUpdateInfo size mismatch");

struct CHand_State_Named {
    HandStateInvisible*   invisible;       // 0x00
    HandStateNormal*      normal;          // 0x04
    HandStateCamera*      camera;          // 0x08
    HandStateTug*         tug;             // 0x0C
    HandStateHolding*     holding;         // 0x10
    HandStateTotem*       totem;           // 0x14
    HandStateMultiPickUp* multi_pick_up;   // 0x18
    HandStateCreature*    creature;        // 0x1C
    HandStateGrain*       grain;           // 0x20
    HandStatePlayAnim*    play_anim;       // 0x24
    HandStateCitadel*     citadel;         // 0x28
};
static_assert(sizeof(CHand_State_Named) == 0x2C, "CHand_State_Named size mismatch");

union CHand_State {
    CHand_State_Named named;
    HandState*        raw[0xB];
};
static_assert(sizeof(CHand_State) == 0x2C, "CHand_State size mismatch");

struct CHand {
    Morphable     super;                              // 0x0000
    // 0x4834 .. 0x49C3 — hand-specific state
    uint8_t       field_0x4834[0x49C4 - 0x4834];     // 0x4834
};
static_assert(sizeof(CHand) == 0x49C4, "CHand size mismatch");
