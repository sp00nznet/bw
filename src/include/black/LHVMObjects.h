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

// --- Audio output hooks ---------------------------------------------------
//
// Fired when scripts ask the audio subsystem to do something. The host
// registers a handler that translates the script-level event into actual
// playback (PlaySound, DirectSound, miniaudio, etc.). All hooks may be
// null; bindings tolerate it.

using SoundPlayFn  = void (*)(int32_t sound_id, float x, float y, float z);
using SoundStopFn  = void (*)(int32_t sound_id);
using MusicEventFn = void (*)(int32_t music_id, bool start);

extern SoundPlayFn  g_audio_play_sound_func;
extern SoundStopFn  g_audio_stop_sound_func;
extern MusicEventFn g_audio_music_func;

// Fired by SAVE_GAME_IN_SLOT. Host should serialize whatever state it
// tracks; nothing is auto-serialized by the bindings themselves.
using SaveSlotFn = void (*)(int32_t slot);
extern SaveSlotFn g_save_slot_func;

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

// --- Host introspection (for HUD / debug) --------------------------------
//
// Snapshot the current state of side-tables that downstream modules might
// want to display. These functions are pure reads — safe to call from any
// thread that doesn't simultaneously fire natives.

struct DialogueSnapshot {
    bool     active;
    bool     ready;
    bool     widescreen;
    int32_t  current_text_id;     // RUN_TEXT id (0 = none)
    int32_t  pending_temp_id;     // TEMP_TEXT id (0 = none)
    int32_t  draw_text_id;        // GAME_DRAW_TEXT id (0 = none)
    int32_t  current_music_id;
    bool     music_playing;
    bool     hand_demo_playing;
};
DialogueSnapshot SnapshotDialogue();

// Number of objects currently registered in the handle table.
uint32_t RegisteredObjectCount();

// Influence-source enumeration — used by the host to render the influence
// map. Returns the number of sources copied into out (capped at out_max).
struct InfluenceSourceView {
    float    x, z;
    float    radius;
    int32_t  player;
    bool     antiplayer;
    bool     from_object;
};
uint32_t SnapshotInfluences(InfluenceSourceView* out, uint32_t out_max);

// Read the current click latch.
struct ClickSnapshot {
    bool     thing_clicked;
    uint32_t clicked_object;
    bool     position_clicked;
    float    click_x, click_y, click_z;
};
ClickSnapshot SnapshotClick();

// Read the current spirit-advisor pointing target.
struct SpiritPointView {
    bool     visible;
    bool     ejected;
    bool     speaking;
    int32_t  current_anim;
    uint32_t pointing_at_obj;     // 0 if pointing at a position
    float    point_x, point_y, point_z;
};
uint32_t SnapshotSpirits(SpiritPointView* out, uint32_t out_max);

// Camera follow / cinematic state from chunk 6.
struct CameraFollowSnapshot {
    uint32_t focus_target;
    uint32_t position_target;
    bool     dual_active;
    bool     has_arrived;
    float    lens_value;
    float    shake_amount;
};
CameraFollowSnapshot SnapshotCameraFollow();

// Active spell view — produced by SPELL_AT_THING / SPELL_AT_POS /
// SPELL_AT_POINT. Spells expire after their duration so the host
// renders only currently-active casts.
struct SpellSnap {
    int32_t  spell_id;
    uint32_t target_object;
    float    x, y, z;
    float    radius;
    float    age;        // game seconds since cast
    float    duration;   // total lifetime
};
uint32_t SnapshotSpells(SpellSnap* out, uint32_t out_max);

// Drop spell records whose age exceeds duration. Hosts should call this
// once per game tick (after the LHVM ProcessTick) to keep the active set
// bounded.
void TickSpells();

// String-table accessor — calls through to the active LHVM instance and
// returns the data-section string at the given offset, or "" if out of range.
const char* DataString(LHVM* vm, uint32_t offset);

// Host registers the running VM so DialogueTextString can resolve text
// ids against the data section automatically.
void SetActiveLHVM(LHVM* vm);

// Returns the data-section string for whichever text id is currently
// being shown (current_text > pending_temp). Empty string if no text
// active or no active LHVM registered.
const char* DialogueTextString();

// --- Native registration -------------------------------------------------

// Override the stub registrations in LHVM with wired implementations.
// Call once after LHVM::InitNativeFunctions().
void RegisterObjectNatives(LHVM* vm);

} // namespace lhvm
