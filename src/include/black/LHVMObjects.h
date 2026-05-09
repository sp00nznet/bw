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

// Hosts call these on user input. The latch holds the value until a script
// consumes it via GAME_THING_CLICKED / POSITION_CLICKED, or until cleared.
void NotifyObjectClicked(uint32_t handle);
void NotifyPositionClicked(float x, float y, float z);

// --- Entity spawn notifier (LHVM-allocated entities → host renderer) -----
//
// When a CHL native creates a new world entity (CREATE, FLOCK_CREATE,
// LOAD_CREATURE, CREATE_REWARD, CREATE_HIGHLIGHT, POPULATE_CONTAINER,
// GET_ARENA, GET_FOOTBALL_PITCH, etc.) the bindings allocate the Object*
// through EntityFactory and register it. Hosts that draw a parallel
// viewer-side representation can register a notifier here so they pick up
// the new Object and add it to their render list. The notifier fires once
// per new spawn; it does NOT fire for pre-existing entities created by the
// host's own scene loader.

struct SpawnInfo {
    uint32_t handle;        // LHVM handle for the new Object*
    Object*  obj;           // raw pointer (for direct host pairing)
    int32_t  script_type;   // SCRIPT_OBJECT_TYPE the script asked for
    int32_t  script_subtype;
    float    x, y, z;
};
using EntitySpawnFn = void (*)(const SpawnInfo*);
extern EntitySpawnFn g_entity_spawn_func;

// --- Native registration -------------------------------------------------

// Override the stub registrations in LHVM with wired implementations.
// Call once after LHVM::InitNativeFunctions().
void RegisterObjectNatives(LHVM* vm);

} // namespace lhvm
