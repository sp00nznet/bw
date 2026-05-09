// LHVM ↔ Object bridge
// The CHL bytecode references game objects by uint32_t handle. This module
// owns the handle ↔ Object* mapping and implements the LHVM natives that
// touch the entity system.
//
// The viewer (or any host) can register query callbacks for hand and click
// state so that natives like GET_HAND_POSITION / GAME_THING_CLICKED return
// real values instead of stubs.

#pragma once

#include <cstdint>

struct Object;
struct LHVM;

namespace lhvm {

// --- Object handle table -------------------------------------------------

// Register an object and return its handle. The handle is non-zero and stable
// for the lifetime of the object. Re-registering the same pointer returns the
// existing handle.
uint32_t RegisterObject(Object* obj);

// Resolve a handle to its Object*. Returns nullptr for handle 0 or for handles
// that have been unregistered.
Object* LookupObject(uint32_t handle);

// Reverse lookup — returns 0 if obj is not registered.
uint32_t HandleFor(Object* obj);

// Drop a handle. Subsequent LookupObject(handle) returns nullptr.
void UnregisterObject(uint32_t handle);

// Drop every handle (e.g. on level reload).
void ClearAllObjects();

// --- Hand / click state services -----------------------------------------

struct HandInfo {
    float    x, y, z;          // world position
    int32_t  state;            // hand-state enum (0 = invisible)
    uint32_t hover_object;     // handle of object under hand, or 0
    uint32_t held_object;      // handle of held object, or 0
};

struct ClickInfo {
    bool     thing_clicked;
    uint32_t clicked_object;
    bool     position_clicked;
    float    click_x, click_y, click_z;
};

using HandQueryFn  = void (*)(HandInfo* out);
using ClickQueryFn = void (*)(ClickInfo* out);

extern HandQueryFn  g_hand_query_func;
extern ClickQueryFn g_click_query_func;

// Hosts call this to clear the click latch after the script consumes it.
void ClearClickedObject();
void ClearClickedPosition();

// --- Native registration -------------------------------------------------

// Override the stub registrations in LHVM with wired implementations.
// Call once after LHVM::InitNativeFunctions().
void RegisterObjectNatives(LHVM* vm);

} // namespace lhvm
