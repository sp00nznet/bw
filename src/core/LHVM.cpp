// LHVM — Lionhead Virtual Machine bytecode interpreter
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
//
// The CHL (Challenge) file format:
//   [Header]   "LHVM" + version
//   [Globals]  count + variable names
//   [Code]     count + VMInstruction array
//   [AutoStart] count + script ID array
//   [Scripts]  count + VMScript array
//   [Data]     size + string constants

#include <black/LHVM.h>
#include <cstring>
#include <cstdlib>
#include <cmath>

// ============================================================================
// Native function stubs — each pops args and pushes default return values
// These will be filled in as game subsystems are implemented.
// ============================================================================

static void NativeStub(LHVM* /*vm*/) {
    // Default no-op — unimplemented native function
}

// --- Camera functions ---
static void Native_SET_CAMERA_POSITION(LHVM* vm) {
    vm->PopFloat(); // x
    vm->PopFloat(); // y
    vm->PopFloat(); // z
    // Sets camera position instantly (needs GCamera wiring)
}

static void Native_SET_CAMERA_FOCUS(LHVM* vm) {
    vm->PopFloat(); // x
    vm->PopFloat(); // y
    vm->PopFloat(); // z
    // Sets camera focus point instantly (needs GCamera wiring)
}

static void Native_MOVE_CAMERA_POSITION(LHVM* vm) {
    vm->PopFloat(); // x
    vm->PopFloat(); // y
    vm->PopFloat(); // z
    vm->PopFloat(); // time
    // Smoothly moves camera position over time (needs GCamera wiring)
}

static void Native_MOVE_CAMERA_FOCUS(LHVM* vm) {
    vm->PopFloat(); // x
    vm->PopFloat(); // y
    vm->PopFloat(); // z
    vm->PopFloat(); // time
    // Smoothly moves camera focus over time (needs GCamera wiring)
}

static void Native_GET_CAMERA_POSITION(LHVM* vm) {
    // Returns current camera world position (needs GCamera wiring)
    vm->PushFloat(0.0f); // x
    vm->PushFloat(0.0f); // y
    vm->PushFloat(0.0f); // z
}

static void Native_GET_CAMERA_FOCUS(LHVM* vm) {
    // Returns current camera focus point (needs GCamera wiring)
    vm->PushFloat(0.0f); // x
    vm->PushFloat(0.0f); // y
    vm->PushFloat(0.0f); // z
}

static void Native_HAS_CAMERA_ARRIVED(LHVM* vm) {
    vm->PushBoolean(true); // camera always "arrived" for now
}

static void Native_START_CAMERA_CONTROL(LHVM* /*vm*/) {
    // Locks camera control to script — disables player camera input
}

static void Native_END_CAMERA_CONTROL(LHVM* /*vm*/) {
    // Releases camera control back to player
}

// --- Property functions ---
static void Native_GET_PROPERTY(LHVM* vm) {
    vm->PopInt();    // property type
    vm->PopObject(); // object
    // Returns object property value (needs entity system wiring)
    vm->PushFloat(0.0f);
}

static void Native_SET_PROPERTY(LHVM* vm) {
    vm->PopFloat();  // value
    vm->PopInt();    // property type
    vm->PopObject(); // object
    // Sets object property value (needs entity system wiring)
}

static void Native_GET_POSITION(LHVM* vm) {
    vm->PopObject(); // object
    // Returns object XYZ position (needs entity lookup)
    vm->PushFloat(0.0f); // x
    vm->PushFloat(0.0f); // y
    vm->PushFloat(0.0f); // z
}

static void Native_SET_POSITION(LHVM* vm) {
    vm->PopFloat();  // z
    vm->PopFloat();  // y
    vm->PopFloat();  // x
    vm->PopObject(); // object
    // Teleports object to XYZ position (needs entity lookup)
}

static void Native_GET_DISTANCE(LHVM* vm) {
    float z2 = vm->PopFloat();
    float y2 = vm->PopFloat();
    float x2 = vm->PopFloat();
    float z1 = vm->PopFloat();
    float y1 = vm->PopFloat();
    float x1 = vm->PopFloat();
    float dx = x2 - x1;
    float dy = y2 - y1;
    float dz = z2 - z1;
    vm->PushFloat(sqrtf(dx * dx + dy * dy + dz * dz));
}

// --- Object functions ---
static void Native_CREATE(LHVM* vm) {
    vm->PopFloat(); // z
    vm->PopFloat(); // y
    vm->PopFloat(); // x
    vm->PopInt();   // subtype
    vm->PopInt();   // type
    // Creates a new game object at position (needs EntityFactory wiring)
    vm->PushObject(0);
}

static void Native_OBJECT_DELETE(LHVM* vm) {
    vm->PopObject(); // object to delete
    // Marks object for deletion (needs entity lookup)
}

static void Native_THING_VALID(LHVM* vm) {
    uint32_t obj_id = vm->PopObject(); // object
    // Checks if object ID is still valid — simplified
    vm->PushBoolean(obj_id != 0);
}

static void Native_IS_OF_TYPE(LHVM* vm) {
    vm->PopInt();    // subtype
    vm->PopInt();    // type
    vm->PopObject(); // object
    // Checks if object matches type/subtype (needs entity lookup)
    vm->PushBoolean(false);
}

// --- Math functions ---
static void Native_RANDOM(LHVM* vm) {
    float max_val = vm->PopFloat();
    float min_val = vm->PopFloat();
    // Simple linear congruential RNG (game uses its own, this is placeholder)
    float t = static_cast<float>(rand()) / static_cast<float>(RAND_MAX);
    vm->PushFloat(min_val + t * (max_val - min_val));
}

static void Native_RANDOM_ULONG(LHVM* vm) {
    int32_t max_val = vm->PopInt();
    int32_t min_val = vm->PopInt();
    if (max_val <= min_val) {
        vm->PushInt(min_val);
    } else {
        vm->PushInt(min_val + (rand() % (max_val - min_val + 1)));
    }
}

static void Native_SQUARE_ROOT(LHVM* vm) {
    float value = vm->PopFloat();
    vm->PushFloat(sqrtf(value));
}

// --- Time functions ---
static void Native_DLL_GETTIME(LHVM* vm) {
    vm->PushFloat(0.0f); // Returns game time in seconds (needs g_game)
}

static void Native_GET_GAME_TIME(LHVM* vm) {
    vm->PushFloat(0.0f); // Returns game time in seconds (needs g_game)
}

static void Native_SET_GAME_TIME(LHVM* vm) {
    vm->PopFloat(); // time — sets the current game time
}

// --- Script control ---
static void Native_STOP_SCRIPT(LHVM* vm) {
    vm->PopInt(); // script name (string offset)
    // Stops the named script task
}

static void Native_STOP_ALL_SCRIPTS_EXCLUDING(LHVM* vm) {
    vm->PopInt(); // script name (string offset)
    // Stops all running scripts except the named one
}

// --- Text/dialogue ---
static void Native_RUN_TEXT(LHVM* vm) {
    vm->PopInt(); // string ID
    vm->PopInt(); // duration or flags
    // Displays text on screen (needs text rendering system)
    vm->PushBoolean(true);
}

static void Native_TEMP_TEXT(LHVM* vm) {
    vm->PopInt(); // string ID
    vm->PopInt(); // duration
    // Displays temporary text overlay (needs text rendering system)
}

static void Native_TEXT_READ(LHVM* vm) {
    vm->PushBoolean(true); // text always "read"
}

static void Native_START_DIALOGUE(LHVM* /*vm*/) {
    // Enters dialogue mode — locks camera and input
}

static void Native_END_DIALOGUE(LHVM* /*vm*/) {
    // Exits dialogue mode — releases camera and input
}

static void Native_IS_DIALOGUE_READY(LHVM* vm) {
    vm->PushBoolean(true);
}

// --- Widescreen ---
static void Native_SET_WIDESCREEN(LHVM* vm) {
    vm->PopBoolean(); // enable — toggles widescreen letterbox bars
}

static void Native_WIDESCREEN_TRANSISTION_FINISHED(LHVM* vm) {
    vm->PushBoolean(true);
}

// --- Influence ---
static void Native_GET_INFLUENCE(LHVM* vm) {
    vm->PopInt();   // player
    vm->PopFloat(); // z
    vm->PopFloat(); // y
    vm->PopFloat(); // x
    vm->PushFloat(0.0f);
}

// --- Game speed ---
static void Native_SET_GAMESPEED(LHVM* vm) {
    vm->PopFloat(); // speed — multiplier for game tick rate
}

// --- Alignment ---
static void Native_GET_ALIGNMENT(LHVM* vm) {
    vm->PopObject(); // player or creature
    vm->PushFloat(0.0f);
}

static void Native_SET_ALIGNMENT(LHVM* vm) {
    vm->PopFloat();  // alignment value
    vm->PopObject(); // player or creature
}

// --- Fade ---
static void Native_SET_FADE(LHVM* vm) {
    vm->PopFloat(); // r
    vm->PopFloat(); // g
    vm->PopFloat(); // b
    vm->PopFloat(); // time
}

static void Native_SET_FADE_IN(LHVM* vm) {
    vm->PopFloat(); // time
}

static void Native_FADE_FINISHED(LHVM* vm) {
    vm->PushBoolean(true);
}

// --- Hand ---
static void Native_GET_HAND_POSITION(LHVM* vm) {
    vm->PushFloat(0.0f); // x
    vm->PushFloat(0.0f); // y
    vm->PushFloat(0.0f); // z
}

static void Native_GET_HAND_STATE(LHVM* vm) {
    vm->PushInt(0); // hand state enum
}

// --- Land height ---
static void Native_GET_LAND_HEIGHT(LHVM* vm) {
    vm->PopFloat(); // z
    vm->PopFloat(); // x
    vm->PushFloat(0.0f);
}

// --- Key input ---
static void Native_KEY_DOWN(LHVM* vm) {
    vm->PopInt(); // key code
    vm->PushBoolean(false);
}

// --- Mana ---
static void Native_GET_MANA(LHVM* vm) {
    vm->PopObject(); // player
    vm->PushFloat(0.0f);
}

// --- Sound ---
static void Native_PLAY_SOUND_EFFECT(LHVM* vm) {
    vm->PopInt();   // sound enum
    vm->PopInt();   // flags
    // Plays sound effect (needs audio system)
    vm->PushBoolean(true);
}

static void Native_STOP_SOUND_EFFECT(LHVM* vm) {
    vm->PopInt(); // sound handle
}

static void Native_SOUND_EXISTS(LHVM* vm) {
    vm->PopInt(); // sound handle
    vm->PushBoolean(false);
}

// --- Belief ---
static void Native_BELIEF_FOR_PLAYER(LHVM* vm) {
    vm->PopObject(); // player
    vm->PopObject(); // town or object
    vm->PushFloat(0.0f);
}

// --- Active ---
static void Native_SET_ACTIVE(LHVM* vm) {
    vm->PopBoolean(); // active state
    vm->PopObject();  // object
}

static void Native_IS_ACTIVE(LHVM* vm) {
    uint32_t obj_id = vm->PopObject();
    // Check if object is still alive — simplified to ID != 0
    vm->PushBoolean(obj_id != 0);
}

static void Native_THING_FIELD_OF_VIEW(LHVM* vm) {
    vm->PopObject(); // object to check
    vm->PushBoolean(true); // assume in view for now
}

static void Native_POS_FIELD_OF_VIEW(LHVM* vm) {
    vm->PopFloat(); // z
    vm->PopFloat(); // y
    vm->PopFloat(); // x
    vm->PushBoolean(true);
}

static void Native_SPIRIT_SPEAKS(LHVM* vm) {
    vm->PopInt(); // spirit type
    vm->PopInt(); // text ID
}

static void Native_SPIRIT_PLAYED(LHVM* vm) {
    vm->PopObject(); // spirit
    vm->PushBoolean(true);
}

static void Native_SET_SCRIPT_STATE(LHVM* vm) {
    vm->PopInt();    // state
    vm->PopObject(); // object
}

static void Native_SET_SCRIPT_STATE_POS(LHVM* vm) {
    vm->PopFloat(); // z
    vm->PopFloat(); // y
    vm->PopFloat(); // x
    vm->PopInt();   // state
    vm->PopObject(); // object
}

static void Native_SET_SCRIPT_FLOAT(LHVM* vm) {
    vm->PopFloat();  // value
    vm->PopInt();    // property index
    vm->PopObject(); // object
}

static void Native_SET_SCRIPT_ULONG(LHVM* vm) {
    vm->PopInt();    // value
    vm->PopInt();    // property index
    vm->PopObject(); // object
}

// --- Map ---
static void Native_LOAD_MAP(LHVM* vm) {
    vm->PopInt(); // map string offset — triggers map transition
}

// --- Game thing clicked ---
static void Native_GAME_THING_CLICKED(LHVM* vm) {
    vm->PopObject(); // object
    vm->PushBoolean(false);
}

static void Native_GET_OBJECT_CLICKED(LHVM* vm) {
    vm->PushObject(0);
}

static void Native_CLEAR_CLICKED_OBJECT(LHVM* /*vm*/) {
    // Clears the last-clicked object state for scripts
}

static void Native_CLEAR_CLICKED_POSITION(LHVM* /*vm*/) {
    // Clears the last-clicked position state for scripts
}

static void Native_POSITION_CLICKED(LHVM* vm) {
    vm->PopFloat(); // z
    vm->PopFloat(); // y
    vm->PopFloat(); // x
    vm->PopFloat(); // radius
    vm->PushBoolean(false);
}

// --- Town ---
static void Native_GET_TOWN_WITH_ID(LHVM* vm) {
    vm->PopInt(); // town ID
    vm->PushObject(0);
}

static void Native_GET_PLAYER_TOWN_TOTAL(LHVM* vm) {
    vm->PopObject(); // player
    vm->PushInt(0);
}

static void Native_GET_NEAREST_TOWN_OF_PLAYER(LHVM* vm) {
    vm->PopFloat();  // z
    vm->PopFloat();  // y
    vm->PopFloat();  // x
    vm->PopObject(); // player
    vm->PushObject(0);
}

// --- Object state ---
static void Native_GET_OBJECT_STATE(LHVM* vm) {
    vm->PopObject(); // object
    vm->PushInt(0);  // state enum value
}

static void Native_SET_HEADING_AND_SPEED(LHVM* vm) {
    vm->PopFloat();  // speed
    vm->PopFloat();  // heading z
    vm->PopFloat();  // heading y
    vm->PopFloat();  // heading x
    vm->PopObject(); // object
}

static void Native_GET_OBJECT_DESTINATION(LHVM* vm) {
    vm->PopObject(); // object
    vm->PushFloat(0.0f); // x
    vm->PushFloat(0.0f); // y
    vm->PushFloat(0.0f); // z
}

static void Native_IS_ON_FIRE(LHVM* vm) {
    vm->PopObject();
    vm->PushBoolean(false);
}

static void Native_IS_FIRE_NEAR(LHVM* vm) {
    vm->PopFloat(); // radius
    vm->PopFloat(); // z
    vm->PopFloat(); // y
    vm->PopFloat(); // x
    vm->PushBoolean(false);
}

static void Native_SET_ON_FIRE(LHVM* vm) {
    vm->PopFloat();  // strength
    vm->PopObject(); // object
}

static void Native_SET_TARGET(LHVM* vm) {
    vm->PopFloat();  // z
    vm->PopFloat();  // y
    vm->PopFloat();  // x
    vm->PopObject(); // object
}

static void Native_IS_LEASHED(LHVM* vm) {
    vm->PopObject();
    vm->PushBoolean(false);
}

static void Native_IS_LEASHED_TO_OBJECT(LHVM* vm) {
    vm->PopObject(); // leash target
    vm->PopObject(); // leashed object
    vm->PushBoolean(false);
}

static void Native_IS_FIGHTING(LHVM* vm) {
    vm->PopObject();
    vm->PushBoolean(false);
}

static void Native_GET_DESIRE(LHVM* vm) {
    vm->PopInt();    // desire type
    vm->PopObject(); // object
    vm->PushFloat(0.0f);
}

static void Native_GET_RESOURCE(LHVM* vm) {
    vm->PopInt();    // resource type
    vm->PopObject(); // object
    vm->PushFloat(0.0f);
}

static void Native_ADD_RESOURCE(LHVM* vm) {
    vm->PopFloat();  // amount
    vm->PopInt();    // resource type
    vm->PopObject(); // target
}

static void Native_REMOVE_RESOURCE(LHVM* vm) {
    vm->PopFloat();  // amount
    vm->PopInt();    // resource type
    vm->PopObject(); // target
}

static void Native_SET_INDESTRUCTABLE(LHVM* vm) {
    vm->PopBoolean(); // indestructible
    vm->PopObject();  // object
}

static void Native_IS_POISONED(LHVM* vm) {
    vm->PopObject();
    vm->PushBoolean(false);
}

static void Native_SET_POISONED(LHVM* vm) {
    vm->PopFloat();  // amount
    vm->PopObject(); // target
}

static void Native_IS_SKELETON(LHVM* vm) {
    vm->PopObject();
    vm->PushBoolean(false);
}

static void Native_SET_SKELETON(LHVM* vm) {
    vm->PopBoolean(); // enable
    vm->PopObject();  // object
}

static void Native_SQUARE_ROOT_ALIAS(LHVM* vm) {
    float value = vm->PopFloat();
    vm->PushFloat(sqrtf(value));
}

static void Native_ABS(LHVM* vm) {
    float value = vm->PopFloat();
    vm->PushFloat(value < 0.0f ? -value : value);
}

static void Native_SET_ID_MOVEABLE(LHVM* vm) {
    vm->PopBoolean(); // moveable
    vm->PopObject();  // object
}

static void Native_SET_ID_PICKUPABLE(LHVM* vm) {
    vm->PopBoolean(); // pickupable
    vm->PopObject();  // object
}

static void Native_GET_OBJECT_HAND_IS_OVER(LHVM* vm) {
    vm->PushObject(0);
}

static void Native_RELEASE_FROM_SCRIPT(LHVM* vm) {
    vm->PopObject(); // object to release
}

static void Native_IS_CREATURE_AVAILABLE(LHVM* vm) {
    vm->PopObject(); // player
    vm->PushBoolean(true);
}

// --- Movement ---
static void Native_MOVE_GAME_THING(LHVM* vm) {
    vm->PopFloat();  // speed
    vm->PopFloat();  // z
    vm->PopFloat();  // y
    vm->PopFloat();  // x
    vm->PopObject(); // object
}

static void Native_SET_FOCUS(LHVM* vm) {
    vm->PopFloat();  // z
    vm->PopFloat();  // y
    vm->PopFloat();  // x
    vm->PopObject(); // object
}

static void Native_CALL(LHVM* vm) {
    vm->PopFloat();  // z
    vm->PopFloat();  // y
    vm->PopFloat();  // x
    vm->PopObject(); // player
}

static void Native_CALL_NEAR(LHVM* vm) {
    vm->PopFloat();  // radius
    vm->PopFloat();  // z
    vm->PopFloat();  // y
    vm->PopFloat();  // x
    vm->PopObject(); // player
    vm->PopObject(); // target
}

static void Native_CALL_IN(LHVM* vm) {
    vm->PopObject(); // target area
    vm->PopObject(); // player
}

// --- Flock ---
static void Native_FLOCK_CREATE(LHVM* vm) {
    vm->PopFloat();  // z
    vm->PopFloat();  // y
    vm->PopFloat();  // x
    vm->PushObject(0); // created flock
}

static void Native_FLOCK_ATTACH(LHVM* vm) {
    vm->PopObject(); // member
    vm->PopObject(); // flock
}

static void Native_FLOCK_DETACH(LHVM* vm) {
    vm->PopObject(); // member
    vm->PopObject(); // flock
}

static void Native_FLOCK_DISBAND(LHVM* vm) {
    vm->PopObject(); // flock
}

static void Native_ID_SIZE(LHVM* vm) {
    vm->PopObject(); // container/flock
    vm->PushInt(0);
}

static void Native_FLOCK_MEMBER(LHVM* vm) {
    vm->PopInt();    // index
    vm->PopObject(); // flock
    vm->PushObject(0);
}

// --- Music ---
static void Native_START_MUSIC(LHVM* vm) {
    vm->PopInt(); // music ID
}

static void Native_STOP_MUSIC(LHVM* /*vm*/) {
}

static void Native_ATTACH_MUSIC(LHVM* vm) {
    vm->PopObject(); // target
    vm->PopInt();    // music ID
}

static void Native_DETACH_MUSIC(LHVM* vm) {
    vm->PopObject(); // target
}

// --- Camera follow ---
static void Native_FOCUS_FOLLOW(LHVM* vm) {
    vm->PopObject(); // target
}

static void Native_POSITION_FOLLOW(LHVM* vm) {
    vm->PopObject(); // target
}

// --- Special effects ---
static void Native_SPECIAL_EFFECT_POSITION(LHVM* vm) {
    vm->PopFloat(); // strength
    vm->PopInt();   // effect type
    vm->PopFloat(); // z
    vm->PopFloat(); // y
    vm->PopFloat(); // x
    vm->PushObject(0);
}

static void Native_SPECIAL_EFFECT_OBJECT(LHVM* vm) {
    vm->PopFloat(); // strength
    vm->PopInt();   // effect type
    vm->PopObject(); // target
    vm->PushObject(0);
}

// --- Dance ---
static void Native_DANCE_CREATE(LHVM* vm) {
    vm->PopInt();    // dance type
    vm->PopFloat();  // z
    vm->PopFloat();  // y
    vm->PopFloat();  // x
    vm->PopObject(); // target
    vm->PushObject(0);
}

// --- Snapshot/influence ---
static void Native_SNAPSHOT(LHVM* /*vm*/) {
}

static void Native_INFLUENCE_OBJECT(LHVM* vm) {
    vm->PopFloat();  // radius
    vm->PopFloat();  // strength
    vm->PopObject(); // object
    vm->PopObject(); // player
}

static void Native_INFLUENCE_POSITION(LHVM* vm) {
    vm->PopFloat();  // radius
    vm->PopFloat();  // strength
    vm->PopFloat();  // z
    vm->PopFloat();  // y
    vm->PopFloat();  // x
    vm->PopObject(); // player
}

// --- Interface ---
static void Native_SET_INTERFACE_INTERACTION(LHVM* vm) {
    vm->PopInt(); // level
}

// --- Leash ---
static void Native_ATTACH_OBJECT_LEASH_TO_OBJECT(LHVM* vm) {
    vm->PopObject(); // target
    vm->PopObject(); // leashed
}

static void Native_ATTACH_OBJECT_LEASH_TO_HAND(LHVM* vm) {
    vm->PopObject(); // leashed
}

static void Native_DETACH_OBJECT_LEASH(LHVM* vm) {
    vm->PopObject(); // leashed
}

// --- Creature commands ---
static void Native_CREATURE_SET_PLAYER(LHVM* vm) {
    vm->PopObject(); // player
    vm->PopObject(); // creature
}

static void Native_CREATURE_DO_ACTION(LHVM* vm) {
    vm->PopObject(); // target object
    vm->PopInt();    // action type
    vm->PopObject(); // creature
}

static void Native_IN_CREATURE_HAND(LHVM* vm) {
    vm->PopObject(); // object
    vm->PopObject(); // creature
    vm->PushBoolean(false);
}

static void Native_CREATURE_SET_DESIRE_VALUE(LHVM* vm) {
    vm->PopFloat();  // value
    vm->PopInt();    // desire type
    vm->PopObject(); // creature
}

static void Native_CREATURE_FORCE_FINISH(LHVM* vm) {
    vm->PopObject(); // creature
}

static void Native_CALL_PLAYER_CREATURE(LHVM* vm) {
    vm->PopObject(); // player
}

static void Native_SET_CREATURE_HOME(LHVM* vm) {
    vm->PopFloat();  // z
    vm->PopFloat();  // y
    vm->PopFloat();  // x
    vm->PopObject(); // creature
}

// --- Timer ---
static void Native_START_COUNTDOWN_TIMER(LHVM* vm) {
    vm->PopFloat(); // duration
    vm->PushObject(0);
}

static void Native_GET_COUNTDOWN_TIMER(LHVM* vm) {
    vm->PopObject(); // timer
    vm->PushFloat(0.0f);
}

static void Native_REMOVE_COUNTDOWN_TIMER(LHVM* vm) {
    vm->PopObject(); // timer
}

static void Native_COUNTDOWN_TIMER_EXISTS(LHVM* vm) {
    vm->PopObject(); // timer
    vm->PushBoolean(false);
}

// --- Highlight ---
static void Native_CREATE_HIGHLIGHT(LHVM* vm) {
    vm->PopFloat(); // height
    vm->PopFloat(); // z
    vm->PopFloat(); // y
    vm->PopFloat(); // x
    vm->PopInt();   // type
    vm->PushObject(0);
}

// --- Weather ---
static void Native_CHANGE_WEATHER_PROPERTIES(LHVM* vm) {
    vm->PopFloat(); // param3
    vm->PopFloat(); // param2
    vm->PopFloat(); // param1
}

static void Native_CHANGE_CLOUD_PROPERTIES(LHVM* vm) {
    vm->PopFloat(); // param3
    vm->PopFloat(); // param2
    vm->PopFloat(); // param1
}

// --- Build ---
static void Native_BUILD_BUILDING(LHVM* vm) {
    vm->PopFloat();  // amount
    vm->PopObject(); // building
}

// --- Spirit ---
static void Native_SPIRIT_EJECT(LHVM* vm) {
    vm->PopObject(); // spirit
}

static void Native_SPIRIT_HOME(LHVM* vm) {
    vm->PopObject(); // spirit
}

static void Native_SPIRIT_POINT_POS(LHVM* vm) {
    vm->PopFloat(); // z
    vm->PopFloat(); // y
    vm->PopFloat(); // x
    vm->PopObject(); // spirit
}

static void Native_SPIRIT_POINT_GAME_THING(LHVM* vm) {
    vm->PopObject(); // target
    vm->PopObject(); // spirit
}

// --- Creature AI ---
static void Native_CREATURE_LEARN_EVERYTHING(LHVM* vm) {
    vm->PopObject(); // creature
}

static void Native_CREATURE_SET_KNOWS_ACTION(LHVM* vm) {
    vm->PopFloat();  // know value
    vm->PopInt();    // action subtypes
    vm->PopInt();    // action type
    vm->PopObject(); // creature
}

static void Native_CREATURE_SET_AGENDA_PRIORITY(LHVM* vm) {
    vm->PopFloat();  // priority
    vm->PopInt();    // agenda type
    vm->PopObject(); // creature
}

static void Native_CREATURE_TURN_OFF_ALL_DESIRES(LHVM* vm) {
    vm->PopObject(); // creature
}

static void Native_CREATURE_SET_DESIRE_ACTIVATED(LHVM* vm) {
    vm->PopBoolean(); // activated
    vm->PopInt();     // desire type
    vm->PopObject();  // creature
}

static void Native_CREATURE_SET_DESIRE_MAXIMUM(LHVM* vm) {
    vm->PopFloat();  // maximum
    vm->PopInt();    // desire type
    vm->PopObject(); // creature
}

static void Native_CREATURE_DESIRE_IS(LHVM* vm) {
    vm->PopInt();    // desire type
    vm->PopObject(); // creature
    vm->PushFloat(0.0f);
}

static void Native_CREATURE_LEARN_DISTINCTION(LHVM* vm) {
    vm->PopFloat();  // value
    vm->PopInt();    // type
    vm->PopObject(); // creature
}

static void Native_GET_TARGET_OBJECT(LHVM* vm) {
    vm->PopObject(); // creature
    vm->PushObject(0);
}

static void Native_SET_CREATURE_HELP(LHVM* vm) {
    vm->PopInt();    // help type
    vm->PopObject(); // creature
}

static void Native_CREATURE_INITIALISE_NUM_TIMES(LHVM* vm) {
    vm->PopInt();    // action type
    vm->PopObject(); // creature
}

static void Native_CREATURE_GET_NUM_TIMES(LHVM* vm) {
    vm->PopInt();    // action type
    vm->PopObject(); // creature
    vm->PushInt(0);
}

// --- Reactions ---
static void Native_CREATE_REACTION(LHVM* vm) {
    vm->PopFloat();  // param
    vm->PopInt();    // type
    vm->PopObject(); // target
    vm->PopObject(); // source
}

static void Native_REMOVE_REACTION(LHVM* vm) {
    vm->PopObject(); // target
    vm->PopObject(); // source
}

// --- Dual camera ---
static void Native_START_DUAL_CAMERA(LHVM* vm) {
    vm->PopObject(); // target2
    vm->PopObject(); // target1
}

static void Native_UPDATE_DUAL_CAMERA(LHVM* vm) {
    vm->PopObject(); // target2
    vm->PopObject(); // target1
}

static void Native_RELEASE_DUAL_CAMERA(LHVM* /*vm*/) {
}

static void Native_CREATE_DUAL_CAMERA_WITH_POINT(LHVM* vm) {
    vm->PopFloat(); // z
    vm->PopFloat(); // y
    vm->PopFloat(); // x
    vm->PopObject(); // target
}

// --- Camera face ---
static void Native_SET_CAMERA_TO_FACE_OBJECT(LHVM* vm) {
    vm->PopFloat();  // distance
    vm->PopObject(); // target
}

static void Native_MOVE_CAMERA_TO_FACE_OBJECT(LHVM* vm) {
    vm->PopFloat();  // time
    vm->PopFloat();  // distance
    vm->PopObject(); // target
}

// --- Object state ---
static void Native_GET_OBJECT_DROPPED(LHVM* vm) {
    vm->PopObject(); // object
    vm->PushObject(0);
}

static void Native_CLEAR_DROPPED_BY_OBJECT(LHVM* vm) {
    vm->PopObject(); // object
}

static void Native_LOOK_GAME_THING(LHVM* vm) {
    vm->PopObject(); // target
}

// --- Misc ---
static void Native_GET_MOON_PERCENTAGE(LHVM* vm) {
    vm->PushFloat(0.5f);
}

static void Native_POPULATE_CONTAINER(LHVM* vm) {
    vm->PopInt();    // count
    vm->PopObject(); // villager type
    vm->PopObject(); // container
}

static void Native_PLAYED(LHVM* vm) {
    vm->PopObject(); // object
    vm->PushBoolean(true);
}

static void Native_OVERRIDE_STATE_ANIMATION(LHVM* vm) {
    vm->PopInt();    // animation
    vm->PopObject(); // object
}

static void Native_CALL_IN_NEAR(LHVM* vm) {
    vm->PopFloat();  // distance
    vm->PopFloat();  // z
    vm->PopFloat();  // y
    vm->PopFloat();  // x
    vm->PopObject(); // target
    vm->PopObject(); // player
}

// --- Camera extensions ---
static void Native_CONVERT_CAMERA_POSITION(LHVM* vm) {
    vm->PopFloat(); // z
    vm->PopFloat(); // y
    vm->PopFloat(); // x
}

static void Native_CONVERT_CAMERA_FOCUS(LHVM* vm) {
    vm->PopFloat(); // z
    vm->PopFloat(); // y
    vm->PopFloat(); // x
}

static void Native_RUN_CAMERA_PATH(LHVM* vm) {
    vm->PopInt(); // path ID
}

static void Native_SET_CAMERA_ZONE(LHVM* vm) {
    vm->PopFloat();  // z2
    vm->PopFloat();  // x2
    vm->PopFloat();  // z1
    vm->PopFloat();  // x1
}

static void Native_CAMERA_PROPERTIES(LHVM* vm) {
    vm->PopFloat(); // param3
    vm->PopFloat(); // param2
    vm->PopFloat(); // param1
}

static void Native_SHAKE_CAMERA(LHVM* vm) {
    vm->PopFloat(); // duration
    vm->PopFloat(); // intensity
}

static void Native_SET_FIXED_CAM_ROTATION(LHVM* vm) {
    vm->PopFloat(); // angle
}

static void Native_STORE_CAMERA_DETAILS(LHVM* /*vm*/) {
}

static void Native_RESTORE_CAMERA_DETAILS(LHVM* /*vm*/) {
}

static void Native_SET_CAMERA_POS_FOC_LENS(LHVM* vm) {
    vm->PopFloat(); // lens
    vm->PopFloat(); // fz
    vm->PopFloat(); // fy
    vm->PopFloat(); // fx
    vm->PopFloat(); // pz
    vm->PopFloat(); // py
    vm->PopFloat(); // px
}

static void Native_MOVE_CAMERA_POS_FOC_LENS(LHVM* vm) {
    vm->PopFloat(); // time
    vm->PopFloat(); // lens
    vm->PopFloat(); // fz
    vm->PopFloat(); // fy
    vm->PopFloat(); // fx
    vm->PopFloat(); // pz
    vm->PopFloat(); // py
    vm->PopFloat(); // px
}

static void Native_SET_CAMERA_LENS(LHVM* vm) {
    vm->PopFloat(); // lens
}

static void Native_MOVE_CAMERA_LENS(LHVM* vm) {
    vm->PopFloat(); // time
    vm->PopFloat(); // lens
}

static void Native_GET_STORED_CAMERA_POSITION(LHVM* vm) {
    vm->PushFloat(0.0f);
    vm->PushFloat(0.0f);
    vm->PushFloat(0.0f);
}

static void Native_GET_STORED_CAMERA_FOCUS(LHVM* vm) {
    vm->PushFloat(0.0f);
    vm->PushFloat(0.0f);
    vm->PushFloat(0.0f);
}

// --- Timer extensions ---
static void Native_CREATE_TIMER(LHVM* vm) {
    vm->PopFloat(); // duration
    vm->PushObject(0);
}

static void Native_HIDE_COUNTDOWN_TIMER(LHVM* vm) {
    vm->PopObject(); // timer
}

static void Native_REVEAL_COUNTDOWN_TIMER(LHVM* vm) {
    vm->PopObject(); // timer
}

static void Native_SET_TIMER_TIME(LHVM* vm) {
    vm->PopFloat();  // time
    vm->PopObject(); // timer
}

static void Native_GET_TIMER_TIME_REMAINING(LHVM* vm) {
    vm->PopObject(); // timer
    vm->PushFloat(0.0f);
}

static void Native_GET_TIMER_TIME_SINCE_SET(LHVM* vm) {
    vm->PopObject(); // timer
    vm->PushFloat(0.0f);
}

// --- Game speed ---
static void Native_START_GAME_SPEED(LHVM* /*vm*/) {
}

static void Native_END_GAME_SPEED(LHVM* /*vm*/) {
}

static void Native_GAME_TIME_ON_OFF(LHVM* vm) {
    vm->PopBoolean(); // on/off
}

static void Native_MOVE_GAME_TIME(LHVM* vm) {
    vm->PopFloat(); // hours
}

// --- Spell ---
static void Native_SPELL_AT_THING(LHVM* vm) {
    vm->PopInt();    // spell type
    vm->PopObject(); // target
    vm->PopObject(); // caster
    vm->PushObject(0);
}

static void Native_SPELL_AT_POS(LHVM* vm) {
    vm->PopInt();    // spell type
    vm->PopFloat();  // z
    vm->PopFloat();  // y
    vm->PopFloat();  // x
    vm->PopObject(); // caster
    vm->PushObject(0);
}

static void Native_SPELL_AT_POINT(LHVM* vm) {
    vm->PopFloat(); // radius
    vm->PopInt();   // spell type
    vm->PopFloat(); // z
    vm->PopFloat(); // y
    vm->PopFloat(); // x
    vm->PopObject(); // caster
    vm->PushObject(0);
}

// --- Object held ---
static void Native_GET_OBJECT_HELD(LHVM* vm) {
    vm->PopObject(); // player
    vm->PushObject(0);
}

static void Native_CLEAR_HIT_OBJECT(LHVM* /*vm*/) {
}

static void Native_GAME_THING_HIT(LHVM* vm) {
    vm->PopObject(); // object
    vm->PushBoolean(false);
}

static void Native_GET_HIT_OBJECT(LHVM* vm) {
    vm->PopObject(); // object
    vm->PushObject(0);
}

static void Native_GET_OBJECT_WHICH_HIT(LHVM* vm) {
    vm->PopObject(); // object
    vm->PushObject(0);
}

// --- Creature misc ---
static void Native_SET_CREATURE_ONLY_DESIRE(LHVM* vm) {
    vm->PopInt();    // desire
    vm->PopObject(); // creature
}

static void Native_SET_CREATURE_ONLY_DESIRE_OFF(LHVM* vm) {
    vm->PopObject(); // creature
}

static void Native_CREATURE_CREATE_RELATIVE(LHVM* vm) {
    vm->PopFloat();  // distance
    vm->PopInt();    // type
    vm->PopObject(); // relative creature
    vm->PopObject(); // player
    vm->PushObject(0);
}

static void Native_SWAP_CREATURE(LHVM* vm) {
    vm->PopObject(); // creature2
    vm->PopObject(); // creature1
}

static void Native_SET_CREATURE_DEV_STAGE(LHVM* vm) {
    vm->PopFloat();  // stage
    vm->PopObject(); // creature
}

// --- Misc ---
static void Native_SET_AFFECTED_BY_WIND(LHVM* vm) {
    vm->PopBoolean(); // affected
    vm->PopObject();  // object
}

static void Native_GET_ACTION_TEXT_FOR_OBJECT(LHVM* vm) {
    vm->PopObject(); // object
    vm->PushInt(0);
}

static void Native_CHANGE_INNER_OUTER_PROPERTIES(LHVM* vm) {
    vm->PopFloat(); // outer
    vm->PopFloat(); // inner
    vm->PopObject(); // object
}

static void Native_ADD_REFERENCE(LHVM* vm) {
    vm->PopObject(); // object
}

static void Native_REMOVE_REFERENCE(LHVM* vm) {
    vm->PopObject(); // object
}

static void Native_GET_REAL_TIME(LHVM* vm) {
    vm->PushFloat(0.0f);
}

static void Native_GET_REAL_DAY(LHVM* vm) {
    vm->PushInt(1);
}

static void Native_GET_REAL_MONTH(LHVM* vm) {
    vm->PushInt(1);
}

static void Native_GET_REAL_YEAR(LHVM* vm) {
    vm->PushInt(2001);
}

// --- Set drawing ---
static void Native_SET_HIGH_GRAPHICS_DETAIL(LHVM* vm) {
    vm->PopBoolean();
}

static void Native_CHANGE_LIGHTNING_PROPERTIES(LHVM* vm) {
    vm->PopFloat();
    vm->PopFloat();
    vm->PopFloat();
}

static void Native_CHANGE_TIME_FADE_PROPERTIES(LHVM* vm) {
    vm->PopFloat();
    vm->PopFloat();
    vm->PopFloat();
}

// --- Focus/position follow ---
static void Native_SET_FOCUS_FOLLOW(LHVM* vm) {
    vm->PopFloat();  // distance
    vm->PopObject(); // target
}

static void Native_SET_POSITION_FOLLOW(LHVM* vm) {
    vm->PopFloat();  // distance
    vm->PopObject(); // target
}

static void Native_SET_FOCUS_AND_POSITION_FOLLOW(LHVM* vm) {
    vm->PopFloat();  // distance
    vm->PopObject(); // target
}

static void Native_FOCUS_AND_POSITION_FOLLOW(LHVM* vm) {
    vm->PopObject(); // target
}

// --- Remaining common natives ---
static void Native_STOP_POINTING(LHVM* vm) { vm->PopObject(); }
static void Native_STOP_LOOKING(LHVM* vm) { vm->PopObject(); }

static void Native_LOOK_AT_POSITION(LHVM* vm) {
    vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopObject();
}

static void Native_PLAY_SPIRIT_ANIM(LHVM* vm) {
    vm->PopBoolean(); vm->PopInt(); vm->PopObject();
}

static void Native_CALL_IN_NOT_NEAR(LHVM* vm) {
    vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat();
    vm->PopObject(); vm->PopObject(); vm->PopObject();
}

static void Native_SET_TEMPERATURE(LHVM* vm) { vm->PopFloat(); }

static void Native_WALK_PATH(LHVM* vm) {
    vm->PopBoolean(); vm->PopInt(); vm->PopObject();
}

static void Native_GET_WALK_PATH_PERCENTAGE(LHVM* vm) {
    vm->PopObject(); vm->PushFloat(0.0f);
}

static void Native_SET_ANIMATION_MODIFY(LHVM* vm) { vm->PopFloat(); vm->PopObject(); }

static void Native_PLAY_GESTURE(LHVM* vm) {
    vm->PopFloat(); vm->PopInt(); vm->PopObject();
}

static void Native_DEV_FUNCTION(LHVM* vm) { vm->PopInt(); }
static void Native_HAS_MOUSE_WHEEL(LHVM* vm) { vm->PushBoolean(true); }
static void Native_NUM_MOUSE_BUTTONS(LHVM* vm) { vm->PushInt(3); }

static void Native_SET_ATTACK_OWN_TOWN(LHVM* vm) { vm->PopBoolean(); vm->PopObject(); }
static void Native_SET_MAGIC_RADIUS(LHVM* vm) { vm->PopFloat(); vm->PopObject(); }

static void Native_TEMP_TEXT_WITH_NUMBER(LHVM* vm) { vm->PopFloat(); vm->PopInt(); }
static void Native_RUN_TEXT_WITH_NUMBER(LHVM* vm) { vm->PopFloat(); vm->PopInt(); }

static void Native_CREATURE_SPELL_REVERSION(LHVM* vm) { vm->PopBoolean(); vm->PopObject(); }
static void Native_GET_EVENTS_PER_SECOND(LHVM* vm) { vm->PushFloat(30.0f); }

static void Native_GET_TIME_SINCE(LHVM* vm) {
    vm->PopInt(); vm->PopObject(); vm->PushFloat(999.0f);
}

static void Native_GET_TOTAL_EVENTS(LHVM* vm) { vm->PopObject(); vm->PushInt(0); }

static void Native_STOP_ALL_SCRIPTS_IN_FILES_EXCLUDING(LHVM* vm) { vm->PopInt(); }
static void Native_STOP_SCRIPTS_IN_FILES(LHVM* vm) { vm->PopInt(); }
static void Native_ENABLE_DISABLE_MUSIC(LHVM* vm) { vm->PopBoolean(); }
static void Native_GET_INCLUSION_DISTANCE(LHVM* vm) { vm->PushFloat(100.0f); }
static void Native_ID_POISONED_SIZE(LHVM* vm) { vm->PopObject(); vm->PushInt(0); }
static void Native_CLING_SPIRIT(LHVM* vm) { vm->PopObject(); vm->PopObject(); }
static void Native_FLY_SPIRIT(LHVM* vm) { vm->PopObject(); vm->PopObject(); }
static void Native_CALL_POISONED_IN(LHVM* vm) { vm->PopObject(); vm->PopObject(); }
static void Native_CALL_NOT_POISONED_IN(LHVM* vm) { vm->PopObject(); vm->PopObject(); }
static void Native_GET_TARGET_RELATIVE_POS(LHVM* vm) {
    vm->PopFloat(); vm->PopObject();
    vm->PushFloat(0.0f); vm->PushFloat(0.0f); vm->PushFloat(0.0f);
}
static void Native_MOVE_MUSIC(LHVM* vm) { vm->PopFloat(); vm->PopObject(); }
static void Native_SET_ONLY_FOR_SCRIPTS(LHVM* vm) { vm->PopBoolean(); vm->PopObject(); }
static void Native_GET_SLOWEST_SPEED(LHVM* vm) { vm->PopObject(); vm->PushFloat(1.0f); }
static void Native_SET_AVI_SEQUENCE(LHVM* vm) { vm->PopBoolean(); vm->PopInt(); }
static void Native_MUSIC_PLAYED(LHVM* vm) { vm->PopInt(); vm->PushBoolean(true); }
static void Native_GET_MUSIC_OBJ_DISTANCE(LHVM* vm) { vm->PopObject(); vm->PushFloat(0.0f); }
static void Native_GET_MUSIC_ENUM_DISTANCE(LHVM* vm) { vm->PopInt(); vm->PushFloat(0.0f); }
static void Native_SET_MUSIC_PLAY_POSITION(LHVM* vm) { vm->PopFloat(); vm->PopInt(); }
static void Native_RESTART_MUSIC(LHVM* vm) { vm->PopInt(); }

static void Native_GET_ARENA(LHVM* vm) { vm->PushObject(0); }
static void Native_GET_FOOTBALL_PITCH(LHVM* vm) { vm->PushObject(0); }
static void Native_STOP_ALL_GAMES(LHVM* /*vm*/) {}
static void Native_ATTACH_TO_GAME(LHVM* vm) { vm->PopObject(); vm->PopObject(); vm->PopInt(); }
static void Native_DETACH_FROM_GAME(LHVM* vm) { vm->PopObject(); vm->PopObject(); }
static void Native_DETACH_UNDEFINED_FROM_GAME(LHVM* vm) { vm->PopObject(); }
static void Native_START_MATCH_WITH_REFEREE(LHVM* vm) { vm->PopObject(); vm->PopObject(); }
static void Native_GAME_TEAM_SIZE(LHVM* vm) { vm->PopObject(); vm->PushInt(0); }
static void Native_GAME_TYPE(LHVM* vm) { vm->PopObject(); vm->PushInt(0); }
static void Native_GAME_SUB_TYPE(LHVM* vm) { vm->PopObject(); vm->PushInt(0); }
static void Native_IS_LEASHED_67(LHVM* vm) { vm->PopObject(); vm->PushBoolean(false); }

// --- More natives (batch 5) ---
static void Native_SET_DISCIPLE(LHVM* vm) { vm->PopInt(); vm->PopObject(); }
static void Native_SET_OBJECT_CARRYING(LHVM* vm) { vm->PopInt(); vm->PopObject(); }
static void Native_SET_OBJECT_FADE_IN(LHVM* vm) { vm->PopFloat(); vm->PopObject(); }
static void Native_SEX_IS_MALE(LHVM* vm) { vm->PopObject(); vm->PushBoolean(true); }
static void Native_SPIRIT_APPEAR(LHVM* vm) { vm->PopObject(); }
static void Native_SPIRIT_DISAPPEAR(LHVM* vm) { vm->PopObject(); }
static void Native_SET_FOCUS_ON_OBJECT(LHVM* vm) { vm->PopObject(); }
static void Native_RELEASE_OBJECT_FOCUS(LHVM* /*vm*/) {}
static void Native_SET_DRAW_LEASH(LHVM* vm) { vm->PopBoolean(); vm->PopObject(); }
static void Native_SET_DRAW_HIGHLIGHT(LHVM* vm) { vm->PopBoolean(); vm->PopObject(); }
static void Native_SET_OPEN_CLOSE(LHVM* vm) { vm->PopBoolean(); vm->PopObject(); }
static void Native_SET_INTRO_BUILDING(LHVM* vm) { vm->PopBoolean(); vm->PopObject(); }
static void Native_CREATURE_FORCE_FRIENDS(LHVM* vm) { vm->PopObject(); vm->PopObject(); }
static void Native_SET_LEASH_WORKS(LHVM* vm) { vm->PopBoolean(); vm->PopObject(); }
static void Native_SET_VIRTUAL_INFLUENCE(LHVM* vm) { vm->PopFloat(); vm->PopFloat(); vm->PopObject(); }
static void Native_VORTEX_FADE_OUT(LHVM* vm) { vm->PopObject(); }
static void Native_TOGGLE_LEASH(LHVM* vm) { vm->PopObject(); }
static void Native_CREATE_WITH_ANGLE_AND_SCALE(LHVM* vm) {
    vm->PopFloat(); vm->PopFloat(); vm->PopInt(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat();
    vm->PushObject(0);
}
static void Native_SET_HURT_BY_FIRE(LHVM* vm) { vm->PopBoolean(); vm->PopObject(); }
static void Native_SET_SUN_DRAW(LHVM* vm) { vm->PopBoolean(); }
static void Native_OBJECT_INFO_BITS(LHVM* vm) { vm->PopObject(); vm->PushInt(0); }
static void Native_CONFINED_OBJECT(LHVM* vm) { vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopObject(); }
static void Native_CLEAR_CONFINED_OBJECT(LHVM* vm) { vm->PopObject(); }
static void Native_SET_PLAYER_BELIEF(LHVM* vm) { vm->PopFloat(); vm->PopObject(); vm->PopObject(); }
static void Native_SET_GRAPHICS_CLIPPING(LHVM* vm) { vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); }
static void Native_IMMERSION_EXISTS(LHVM* vm) { vm->PushBoolean(false); }
static void Native_GET_OBJECT_FADE(LHVM* vm) { vm->PopObject(); vm->PushFloat(1.0f); }
static void Native_PLAY_HAND_DEMO(LHVM* vm) { vm->PopInt(); }
static void Native_IS_PLAYING_HAND_DEMO(LHVM* vm) { vm->PushBoolean(false); }
static void Native_GET_ARSE_POSITION(LHVM* vm) { vm->PopObject(); vm->PushFloat(0.0f); vm->PushFloat(0.0f); vm->PushFloat(0.0f); }
static void Native_GET_BELLY_POSITION(LHVM* vm) { vm->PopObject(); vm->PushFloat(0.0f); vm->PushFloat(0.0f); vm->PushFloat(0.0f); }
static void Native_GET_INTERACTION_MAGNITUDE(LHVM* vm) { vm->PopObject(); vm->PushFloat(0.0f); }
static void Native_GET_ACTION_COUNT(LHVM* vm) { vm->PopInt(); vm->PopObject(); vm->PushInt(0); }
static void Native_GET_OBJECT_LEASH_TYPE(LHVM* vm) { vm->PopObject(); vm->PushInt(0); }
static void Native_CREATURE_REACTION(LHVM* vm) { vm->PopInt(); vm->PopObject(); }
static void Native_CREATURE_IN_DEV_SCRIPT(LHVM* vm) { vm->PopBoolean(); vm->PopObject(); }
static void Native_START_ANGLE_SOUND(LHVM* vm) { vm->PopFloat(); vm->PopInt(); vm->PopObject(); }
static void Native_IS_LOCKED_INTERACTION(LHVM* vm) { vm->PopObject(); vm->PushBoolean(false); }
static void Native_SET_CREATURE_NAME(LHVM* vm) { vm->PopInt(); vm->PopObject(); }
static void Native_SET_CREATURE_SOUND(LHVM* vm) { vm->PopBoolean(); vm->PopObject(); }
static void Native_CREATURE_INTERACTING_WITH(LHVM* vm) { vm->PopObject(); vm->PushBoolean(false); }
static void Native_SET_TOWN_DESIRE_BOOST(LHVM* vm) { vm->PopFloat(); vm->PopInt(); vm->PopObject(); }
static void Native_GAME_PLAY_SAY_SOUND_EFFECT(LHVM* vm) { vm->PopFloat(); vm->PopInt(); vm->PopObject(); }
static void Native_SET_CREATURE_CREED_PROPERTIES(LHVM* vm) { vm->PopFloat(); vm->PopFloat(); vm->PopObject(); }
static void Native_GAME_THING_CAN_VIEW_CAMERA(LHVM* vm) { vm->PopObject(); vm->PushBoolean(true); }
static void Native_CAN_SKIP_TUTORIAL(LHVM* vm) { vm->PushBoolean(true); }
static void Native_CAN_SKIP_CREATURE_TRAINING(LHVM* vm) { vm->PushBoolean(true); }
static void Native_IS_KEEPING_OLD_CREATURE(LHVM* vm) { vm->PushBoolean(false); }
static void Native_CURRENT_PROFILE_HAS_CREATURE(LHVM* vm) { vm->PushBoolean(false); }
static void Native_SET_HAND_DEMO_KEYS(LHVM* vm) { vm->PopInt(); }
static void Native_THING_JC_SPECIAL(LHVM* vm) { vm->PopInt(); vm->PopObject(); }
static void Native_PLAY_JC_SPECIAL(LHVM* vm) { vm->PopInt(); vm->PopObject(); }
static void Native_IS_PLAYING_JC_SPECIAL(LHVM* vm) { vm->PopObject(); vm->PushBoolean(false); }
static void Native_HAND_DEMO_TRIGGER(LHVM* vm) { vm->PushBoolean(false); }
static void Native_SET_OBJECT_BELIEF_SCALE(LHVM* vm) { vm->PopFloat(); vm->PopObject(); }
static void Native_HIGHLIGHT_PROPERTIES(LHVM* vm) { vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopObject(); }
static void Native_SET_SCAFFOLD_PROPERTIES(LHVM* vm) { vm->PopFloat(); vm->PopFloat(); vm->PopObject(); }
static void Native_PLAYED_PERCENTAGE(LHVM* vm) { vm->PopObject(); vm->PushFloat(1.0f); }
static void Native_OBJECT_CAST_BY_OBJECT(LHVM* vm) { vm->PopObject(); vm->PopObject(); vm->PushBoolean(false); }
static void Native_IS_WIND_MAGIC_AT_POS(LHVM* vm) { vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PushBoolean(false); }
static void Native_CREATE_MIST(LHVM* vm) { vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PushObject(0); }
static void Native_SET_MIST_FADE(LHVM* vm) { vm->PopFloat(); vm->PopFloat(); vm->PopObject(); }
static void Native_SET_BOOKMARK_POSITION(LHVM* vm) { vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopInt(); }

// --- Final batch: all remaining natives ---
static void Native_CALL_BUILDING_IN_TOWN(LHVM* vm) { vm->PopObject(); vm->PopObject(); vm->PopInt(); }
static void Native_CALL_FLYING(LHVM* vm) { vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopObject(); }
static void Native_CALL_NEAR_IN_STATE(LHVM* vm) { vm->PopInt(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopObject(); vm->PopObject(); }
static void Native_CLEAR_ACTOR_MIND(LHVM* vm) { vm->PopObject(); }
static void Native_CLEAR_CLIPPING_WINDOW(LHVM* /*vm*/) {}
static void Native_CLEAR_PLAYER_SPELL_CHARGING(LHVM* vm) { vm->PopObject(); }
static void Native_COMPUTER_PLAYER_READY(LHVM* vm) { vm->PopObject(); vm->PushBoolean(true); }
static void Native_CREATE_RANDOM_VILLAGER_OF_TRIBE(LHVM* vm) { vm->PopInt(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PushObject(0); }
static void Native_CREATE_REWARD(LHVM* vm) { vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopInt(); vm->PushObject(0); }
static void Native_CREATE_REWARD_IN_TOWN(LHVM* vm) { vm->PopObject(); vm->PopInt(); vm->PushObject(0); }
static void Native_CREATURE_AUTOSCALE(LHVM* vm) { vm->PopBoolean(); vm->PopObject(); }
static void Native_CREATURE_FIGHT_QUEUE_HITS(LHVM* vm) { vm->PopInt(); vm->PopObject(); }
static void Native_CREATURE_LEARN_EVERYTHING_EXCLUDING(LHVM* vm) { vm->PopInt(); vm->PopObject(); }
static void Native_DETACH_SOUND_TAG(LHVM* vm) { vm->PopObject(); }
static void Native_ATTACH_SOUND_TAG(LHVM* vm) { vm->PopInt(); vm->PopObject(); }
static void Native_ENABLE_DISABLE_ALIGNMENT_MUSIC(LHVM* vm) { vm->PopBoolean(); }
static void Native_ENABLE_DISABLE_COMPUTER_PLAYER(LHVM* vm) { vm->PopBoolean(); vm->PopObject(); }
static void Native_ENTER_EXIT_CITADEL(LHVM* vm) { vm->PopBoolean(); vm->PopObject(); }
static void Native_FADE_ALL_DRAW_TEXT(LHVM* vm) { vm->PopFloat(); }
static void Native_FLOCK_WITHIN_LIMITS(LHVM* vm) { vm->PopObject(); vm->PushBoolean(true); }
static void Native_FORCE_COMPUTER_PLAYER_ACTION(LHVM* vm) { vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopInt(); vm->PopObject(); }
static void Native_GAME_CLEAR_COMPUTER_PLAYER_ACTIONS(LHVM* vm) { vm->PopObject(); }
static void Native_GAME_CLEAR_DIALOGUE(LHVM* /*vm*/) {}
static void Native_GAME_CLOSE_DIALOGUE(LHVM* /*vm*/) {}
static void Native_GAME_DRAW_TEXT(LHVM* vm) { vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopInt(); vm->PopInt(); }
static void Native_GAME_DRAW_TEMP_TEXT(LHVM* vm) { vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopInt(); vm->PopInt(); }
static void Native_GAME_SET_MANA(LHVM* vm) { vm->PopFloat(); vm->PopObject(); }
static void Native_GAME_SOUND_PLAYING(LHVM* vm) { vm->PopInt(); vm->PushBoolean(false); }
static void Native_GET_COMPUTER_PLAYER_ATTITUDE(LHVM* vm) { vm->PopObject(); vm->PushFloat(0.0f); }
static void Native_GET_COMPUTER_PLAYER_POSITION(LHVM* vm) { vm->PopObject(); vm->PushFloat(0.0f); vm->PushFloat(0.0f); vm->PushFloat(0.0f); }
static void Native_GET_CREATURE_FIGHT_ACTION(LHVM* vm) { vm->PopObject(); vm->PushInt(0); }
static void Native_GET_DEAD_LIVING(LHVM* vm) { vm->PopObject(); vm->PushObject(0); }
static void Native_GET_FACING_CAMERA_POSITION(LHVM* vm) { vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PushFloat(0.0f); vm->PushFloat(0.0f); vm->PushFloat(0.0f); }
static void Native_GET_FIRST_HELP(LHVM* vm) { vm->PopObject(); vm->PushObject(0); }
static void Native_GET_HELP(LHVM* vm) { vm->PopObject(); vm->PushInt(0); }
static void Native_GET_LAST_HELP(LHVM* vm) { vm->PopObject(); vm->PushObject(0); }
static void Native_GET_LAST_SPELL_CAST_POS(LHVM* vm) { vm->PopObject(); vm->PushFloat(0.0f); vm->PushFloat(0.0f); vm->PushFloat(0.0f); }
static void Native_GET_MANA_FOR_SPELL(LHVM* vm) { vm->PopInt(); vm->PopObject(); vm->PushFloat(0.0f); }
static void Native_GET_OBJECT_FLOCK(LHVM* vm) { vm->PopObject(); vm->PushObject(0); }
static void Native_GET_PLAYER_ALLY(LHVM* vm) { vm->PopObject(); vm->PopObject(); vm->PushFloat(0.0f); }
static void Native_GET_PLAYER_WIND_RESISTANCE(LHVM* vm) { vm->PopObject(); vm->PushFloat(0.0f); }
static void Native_GET_SPELL_ICON_IN_TEMPLE(LHVM* vm) { vm->PopInt(); vm->PopObject(); vm->PushObject(0); }
static void Native_GET_TEMPLE_ENTRANCE_POSITION(LHVM* vm) { vm->PopObject(); vm->PushFloat(0.0f); vm->PushFloat(0.0f); vm->PushFloat(0.0f); }
static void Native_GET_TEMPLE_POSITION(LHVM* vm) { vm->PopObject(); vm->PushFloat(0.0f); vm->PushFloat(0.0f); vm->PushFloat(0.0f); }
static void Native_GET_TOTEM_STATUE(LHVM* vm) { vm->PopObject(); vm->PushObject(0); }
static void Native_GET_TOWN_WORSHIP_DEATHS(LHVM* vm) { vm->PopObject(); vm->PushFloat(0.0f); }
static void Native_ID_ADULT_SIZE(LHVM* vm) { vm->PopObject(); vm->PushInt(0); }
static void Native_INSIDE_TEMPLE(LHVM* vm) { vm->PopObject(); vm->PushBoolean(false); }
static void Native_IS_AFFECTED_BY_SPELL(LHVM* vm) { vm->PopInt(); vm->PopObject(); vm->PushBoolean(false); }
static void Native_IS_AUTO_FIGHTING(LHVM* vm) { vm->PopObject(); vm->PushBoolean(false); }
static void Native_IS_SPELL_CHARGING(LHVM* vm) { vm->PopObject(); vm->PushBoolean(false); }
static void Native_IS_THAT_SPELL_CHARGING(LHVM* vm) { vm->PopInt(); vm->PopObject(); vm->PushBoolean(false); }
static void Native_KILL_STORMS_IN_AREA(LHVM* vm) { vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); }
static void Native_LAST_MUSIC_LINE(LHVM* vm) { vm->PopInt(); vm->PushInt(0); }
static void Native_LOAD_COMPUTER_PLAYER_PERSONALITY(LHVM* vm) { vm->PopInt(); vm->PopObject(); }
static void Native_LOAD_CREATURE(LHVM* vm) { vm->PopInt(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopObject(); vm->PushObject(0); }
static void Native_LOAD_MY_CREATURE(LHVM* vm) { vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopObject(); vm->PushObject(0); }
static void Native_MAP_SCRIPT_FUNCTION(LHVM* vm) { vm->PopInt(); vm->PopObject(); }
static void Native_MOVE_COMPUTER_PLAYER_POSITION(LHVM* vm) { vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopObject(); }
static void Native_OBJECT_ADULT_CAPACITY(LHVM* vm) { vm->PopObject(); vm->PushInt(0); }
static void Native_OBJECT_CAPACITY(LHVM* vm) { vm->PopObject(); vm->PushInt(0); }
static void Native_OBJECT_RELATIVE_BELIEF(LHVM* vm) { vm->PopObject(); vm->PopObject(); vm->PushFloat(0.0f); }
static void Native_OPPOSING_CREATURE(LHVM* vm) { vm->PopObject(); vm->PushObject(0); }
static void Native_PAUSE_UNPAUSE_CLIMATE_SYSTEM(LHVM* vm) { vm->PopBoolean(); }
static void Native_PAUSE_UNPAUSE_STORM_CREATION(LHVM* vm) { vm->PopBoolean(); }
static void Native_PLAYER_SPELL_CAST_TIME(LHVM* vm) { vm->PopInt(); vm->PopObject(); vm->PushFloat(0.0f); }
static void Native_PLAYER_SPELL_LAST_CAST(LHVM* vm) { vm->PopInt(); vm->PopObject(); vm->PushFloat(0.0f); }
static void Native_POS_VALID_FOR_CREATURE(LHVM* vm) { vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PushBoolean(true); }
static void Native_QUEUE_COMPUTER_PLAYER_ACTION(LHVM* vm) { vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopInt(); vm->PopObject(); }
static void Native_RELEASE_COMPUTER_PLAYER(LHVM* vm) { vm->PopObject(); }
static void Native_REMOVE_REACTION_OF_TYPE(LHVM* vm) { vm->PopInt(); vm->PopObject(); vm->PopObject(); }
static void Native_RESTART_OBJECT(LHVM* vm) { vm->PopObject(); }
static void Native_SAVE_COMPUTER_PLAYER_PERSONALITY(LHVM* vm) { vm->PopInt(); vm->PopObject(); }
static void Native_SAVE_GAME_IN_SLOT(LHVM* vm) { vm->PopInt(); }
static void Native_SAY_SOUND_EFFECT_PLAYING(LHVM* vm) { vm->PopInt(); vm->PushBoolean(false); }
static void Native_SET_CAN_BUILD_WORSHIPSITE(LHVM* vm) { vm->PopBoolean(); vm->PopObject(); }
static void Native_SET_CLIPPING_WINDOW(LHVM* vm) { vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); }
static void Native_SET_COMPUTER_PLAYER_ATTITUDE(LHVM* vm) { vm->PopFloat(); vm->PopObject(); }
static void Native_SET_COMPUTER_PLAYER_PERSONALITY(LHVM* vm) { vm->PopInt(); vm->PopFloat(); vm->PopObject(); }
static void Native_SET_COMPUTER_PLAYER_POSITION(LHVM* vm) { vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopObject(); }
static void Native_SET_COMPUTER_PLAYER_SPEED(LHVM* vm) { vm->PopFloat(); vm->PopObject(); }
static void Native_SET_COMPUTER_PLAYER_SUPPRESSION(LHVM* vm) { vm->PopFloat(); vm->PopObject(); }
static void Native_SET_CREATURE_AUTO_FIGHTING(LHVM* vm) { vm->PopBoolean(); vm->PopObject(); }
static void Native_SET_CREATURE_IN_TEMPLE(LHVM* vm) { vm->PopBoolean(); vm->PopObject(); }
static void Native_SET_CREATURE_QUEUE_FIGHT_MOVE(LHVM* vm) { vm->PopInt(); vm->PopObject(); }
static void Native_SET_CREATURE_QUEUE_FIGHT_SPELL(LHVM* vm) { vm->PopInt(); vm->PopObject(); }
static void Native_SET_CREATURE_QUEUE_FIGHT_STEP(LHVM* vm) { vm->PopInt(); vm->PopObject(); }
static void Native_SET_DRAW_TEXT_COLOUR(LHVM* vm) { vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); }
static void Native_SET_FIGHT_EXIT(LHVM* vm) { vm->PopObject(); }
static void Native_SET_FOCUS_FOLLOW_COMPUTER_PLAYER(LHVM* vm) { vm->PopObject(); }
static void Native_SET_GAME_SOUND(LHVM* vm) { vm->PopBoolean(); }
static void Native_SET_MAGIC_IN_OBJECT(LHVM* vm) { vm->PopBoolean(); vm->PopInt(); vm->PopObject(); }
static void Native_SET_MAGIC_PROPERTIES(LHVM* vm) { vm->PopFloat(); vm->PopInt(); vm->PopObject(); }
static void Native_SET_PLAYER_ALLY(LHVM* vm) { vm->PopFloat(); vm->PopObject(); vm->PopObject(); }
static void Native_SET_PLAYER_WIND_RESISTANCE(LHVM* vm) { vm->PopFloat(); vm->PopObject(); }
static void Native_SET_POSITION_FOLLOW_COMPUTER_PLAYER(LHVM* vm) { vm->PopObject(); }
static void Native_SET_SET_ON_FIRE(LHVM* vm) { vm->PopFloat(); vm->PopObject(); }
static void Native_SPIRIT_SCREEN_POINT(LHVM* vm) { vm->PopFloat(); vm->PopFloat(); vm->PopObject(); }
static void Native_START_IMMERSION(LHVM* vm) { vm->PopInt(); vm->PopObject(); }
static void Native_STOP_IMMERSION(LHVM* vm) { vm->PopInt(); vm->PopObject(); }
static void Native_STOP_ALL_IMMERSION(LHVM* /*vm*/) {}
static void Native_STOP_SCRIPTS_IN_FILES_EXCLUDING(LHVM* vm) { vm->PopInt(); }
static void Native_UPDATE_SNAPSHOT(LHVM* /*vm*/) {}
static void Native_UPDATE_SNAPSHOT_PICTURE(LHVM* vm) { vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); }
static void Native_VORTEX_PARAMETERS(LHVM* vm) { vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopObject(); }
static void Native_WITHIN_ROTATION(LHVM* vm) { vm->PopFloat(); vm->PopFloat(); vm->PopObject(); vm->PushBoolean(false); }
static void Native_CALL_COMPUTER_PLAYER(LHVM* vm) { vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopObject(); }
static void Native_ADD_SPOT_VISUAL_TARGET_POS(LHVM* vm) { vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopObject(); }
static void Native_ADD_SPOT_VISUAL_TARGET_OBJECT(LHVM* vm) { vm->PopObject(); vm->PopObject(); }
static void Native_SET_SET_ON_FIRE2(LHVM* vm) { vm->PopFloat(); vm->PopObject(); }
static void Native_GET_TOWN_AND_VILLAGER_HEALTH(LHVM* vm) { vm->PopObject(); vm->PushFloat(100.0f); }
static void Native_GET_SACRIFICE_TOTAL2(LHVM* vm) { vm->PopObject(); vm->PushFloat(0.0f); }
static void Native_GAME_ADD_FOR_BUILDING2(LHVM* vm) { vm->PopFloat(); vm->PopObject(); }
static void Native_GET_TIME_SINCE_ATTACKED(LHVM* vm) { vm->PopObject(); vm->PushFloat(999.0f); }

// --- Missing function definitions (final batch) ---
static void Native_SET_GAME_TIME_PROPERTIES(LHVM* vm) { vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); }
static void Native_RESET_GAME_TIME_PROPERTIES(LHVM* /*vm*/) {}
static void Native_SET_INTERFACE_CITADEL(LHVM* vm) { vm->PopBoolean(); }
static void Native_SET_LAND_BALANCE(LHVM* vm) { vm->PopFloat(); vm->PopInt(); }
static void Native_GET_FIRST_IN_CONTAINER(LHVM* vm) { vm->PopObject(); vm->PushObject(0); }
static void Native_GET_NEXT_IN_CONTAINER(LHVM* vm) { vm->PopObject(); vm->PopObject(); vm->PushObject(0); }

// --- Help system ---
static void Native_HELP_SYSTEM_ON(LHVM* vm) {
    vm->PushBoolean(true);
}

static void Native_SET_HELP_SYSTEM(LHVM* vm) {
    vm->PopBoolean(); // enable
}

// --- Player magic ---
static void Native_SET_PLAYER_MAGIC(LHVM* vm) {
    vm->PopBoolean(); // enable
    vm->PopInt();     // magic type
    vm->PopObject();  // player
}

static void Native_HAS_PLAYER_MAGIC(LHVM* vm) {
    vm->PopInt();    // magic type
    vm->PopObject(); // player
    vm->PushBoolean(false);
}

// ============================================================================
// Native function registration
// ============================================================================

void LHVM::RegisterNativeFunction(NativeFunction id, const char* name, NativeFunctionPtr func) {
    if (id < _NATIVE_FUNCTION_COUNT) {
        native_functions[id].name = name;
        native_functions[id].func = func;
    }
}

void LHVM::InitNativeFunctions() {
    // Initialize all entries to stub
    for (uint32_t i = 0; i < _NATIVE_FUNCTION_COUNT; i++) {
        native_functions[i].name = "UNIMPLEMENTED";
        native_functions[i].func = NativeStub;
    }

    // Register all 465 native functions
    // Functions with actual stub implementations pop/push correct arg counts.
    // Functions registered as NativeStub are pure no-ops awaiting implementation.

    RegisterNativeFunction(NATIVE_NONE,                          "NONE",                          NativeStub);
    RegisterNativeFunction(NATIVE_SET_CAMERA_POSITION,           "SET_CAMERA_POSITION",           Native_SET_CAMERA_POSITION);
    RegisterNativeFunction(NATIVE_SET_CAMERA_FOCUS,              "SET_CAMERA_FOCUS",              Native_SET_CAMERA_FOCUS);
    RegisterNativeFunction(NATIVE_MOVE_CAMERA_POSITION,          "MOVE_CAMERA_POSITION",          Native_MOVE_CAMERA_POSITION);
    RegisterNativeFunction(NATIVE_MOVE_CAMERA_FOCUS,             "MOVE_CAMERA_FOCUS",             Native_MOVE_CAMERA_FOCUS);
    RegisterNativeFunction(NATIVE_GET_CAMERA_POSITION,           "GET_CAMERA_POSITION",           Native_GET_CAMERA_POSITION);
    RegisterNativeFunction(NATIVE_GET_CAMERA_FOCUS,              "GET_CAMERA_FOCUS",              Native_GET_CAMERA_FOCUS);
    RegisterNativeFunction(NATIVE_SPIRIT_EJECT,                  "SPIRIT_EJECT",                  Native_SPIRIT_EJECT);
    RegisterNativeFunction(NATIVE_SPIRIT_HOME,                   "SPIRIT_HOME",                   Native_SPIRIT_HOME);
    RegisterNativeFunction(NATIVE_SPIRIT_POINT_POS,              "SPIRIT_POINT_POS",              Native_SPIRIT_POINT_POS);
    RegisterNativeFunction(NATIVE_SPIRIT_POINT_GAME_THING,       "SPIRIT_POINT_GAME_THING",       Native_SPIRIT_POINT_GAME_THING);
    RegisterNativeFunction(NATIVE_GAME_THING_FIELD_OF_VIEW,      "GAME_THING_FIELD_OF_VIEW",      Native_THING_FIELD_OF_VIEW);
    RegisterNativeFunction(NATIVE_POS_FIELD_OF_VIEW,             "POS_FIELD_OF_VIEW",             Native_POS_FIELD_OF_VIEW);
    RegisterNativeFunction(NATIVE_RUN_TEXT,                       "RUN_TEXT",                       Native_RUN_TEXT);
    RegisterNativeFunction(NATIVE_TEMP_TEXT,                      "TEMP_TEXT",                      Native_TEMP_TEXT);
    RegisterNativeFunction(NATIVE_TEXT_READ,                      "TEXT_READ",                      Native_TEXT_READ);
    RegisterNativeFunction(NATIVE_GAME_THING_CLICKED,            "GAME_THING_CLICKED",            Native_GAME_THING_CLICKED);
    RegisterNativeFunction(NATIVE_SET_SCRIPT_STATE,              "SET_SCRIPT_STATE",              Native_SET_SCRIPT_STATE);
    RegisterNativeFunction(NATIVE_SET_SCRIPT_STATE_POS,          "SET_SCRIPT_STATE_POS",          Native_SET_SCRIPT_STATE_POS);
    RegisterNativeFunction(NATIVE_SET_SCRIPT_FLOAT,              "SET_SCRIPT_FLOAT",              Native_SET_SCRIPT_FLOAT);
    RegisterNativeFunction(NATIVE_SET_SCRIPT_ULONG,              "SET_SCRIPT_ULONG",              Native_SET_SCRIPT_ULONG);
    RegisterNativeFunction(NATIVE_GET_PROPERTY,                  "GET_PROPERTY",                  Native_GET_PROPERTY);
    RegisterNativeFunction(NATIVE_SET_PROPERTY,                  "SET_PROPERTY",                  Native_SET_PROPERTY);
    RegisterNativeFunction(NATIVE_GET_POSITION,                  "GET_POSITION",                  Native_GET_POSITION);
    RegisterNativeFunction(NATIVE_SET_POSITION,                  "SET_POSITION",                  Native_SET_POSITION);
    RegisterNativeFunction(NATIVE_GET_DISTANCE,                  "GET_DISTANCE",                  Native_GET_DISTANCE);
    RegisterNativeFunction(NATIVE_CALL,                          "CALL",                          Native_CALL);
    RegisterNativeFunction(NATIVE_CREATE,                        "CREATE",                        Native_CREATE);
    RegisterNativeFunction(NATIVE_RANDOM,                        "RANDOM",                        Native_RANDOM);
    RegisterNativeFunction(NATIVE_DLL_GETTIME,                   "DLL_GETTIME",                   Native_DLL_GETTIME);
    RegisterNativeFunction(NATIVE_START_CAMERA_CONTROL,          "START_CAMERA_CONTROL",          Native_START_CAMERA_CONTROL);
    RegisterNativeFunction(NATIVE_END_CAMERA_CONTROL,            "END_CAMERA_CONTROL",            Native_END_CAMERA_CONTROL);
    RegisterNativeFunction(NATIVE_SET_WIDESCREEN,                "SET_WIDESCREEN",                Native_SET_WIDESCREEN);
    RegisterNativeFunction(NATIVE_MOVE_GAME_THING,               "MOVE_GAME_THING",               Native_MOVE_GAME_THING);
    RegisterNativeFunction(NATIVE_SET_FOCUS,                     "SET_FOCUS",                     Native_SET_FOCUS);
    RegisterNativeFunction(NATIVE_HAS_CAMERA_ARRIVED,            "HAS_CAMERA_ARRIVED",            Native_HAS_CAMERA_ARRIVED);
    RegisterNativeFunction(NATIVE_FLOCK_CREATE,                  "FLOCK_CREATE",                  Native_FLOCK_CREATE);
    RegisterNativeFunction(NATIVE_FLOCK_ATTACH,                  "FLOCK_ATTACH",                  Native_FLOCK_ATTACH);
    RegisterNativeFunction(NATIVE_FLOCK_DETACH,                  "FLOCK_DETACH",                  Native_FLOCK_DETACH);
    RegisterNativeFunction(NATIVE_FLOCK_DISBAND,                 "FLOCK_DISBAND",                 Native_FLOCK_DISBAND);
    RegisterNativeFunction(NATIVE_ID_SIZE,                       "ID_SIZE",                       Native_ID_SIZE);
    RegisterNativeFunction(NATIVE_FLOCK_MEMBER,                  "FLOCK_MEMBER",                  Native_FLOCK_MEMBER);
    RegisterNativeFunction(NATIVE_GET_HAND_POSITION,             "GET_HAND_POSITION",             Native_GET_HAND_POSITION);
    RegisterNativeFunction(NATIVE_PLAY_SOUND_EFFECT,             "PLAY_SOUND_EFFECT",             Native_PLAY_SOUND_EFFECT);
    RegisterNativeFunction(NATIVE_START_MUSIC,                   "START_MUSIC",                   Native_START_MUSIC);
    RegisterNativeFunction(NATIVE_STOP_MUSIC,                    "STOP_MUSIC",                    Native_STOP_MUSIC);
    RegisterNativeFunction(NATIVE_ATTACH_MUSIC,                  "ATTACH_MUSIC",                  Native_ATTACH_MUSIC);
    RegisterNativeFunction(NATIVE_DETACH_MUSIC,                  "DETACH_MUSIC",                  Native_DETACH_MUSIC);
    RegisterNativeFunction(NATIVE_OBJECT_DELETE,                 "OBJECT_DELETE",                 Native_OBJECT_DELETE);
    RegisterNativeFunction(NATIVE_FOCUS_FOLLOW,                  "FOCUS_FOLLOW",                  Native_FOCUS_FOLLOW);
    RegisterNativeFunction(NATIVE_POSITION_FOLLOW,               "POSITION_FOLLOW",               Native_POSITION_FOLLOW);
    RegisterNativeFunction(NATIVE_CALL_NEAR,                     "CALL_NEAR",                     Native_CALL_NEAR);
    RegisterNativeFunction(NATIVE_SPECIAL_EFFECT_POSITION,       "SPECIAL_EFFECT_POSITION",       Native_SPECIAL_EFFECT_POSITION);
    RegisterNativeFunction(NATIVE_SPECIAL_EFFECT_OBJECT,         "SPECIAL_EFFECT_OBJECT",         Native_SPECIAL_EFFECT_OBJECT);
    RegisterNativeFunction(NATIVE_DANCE_CREATE,                  "DANCE_CREATE",                  Native_DANCE_CREATE);
    RegisterNativeFunction(NATIVE_CALL_IN,                       "CALL_IN",                       Native_CALL_IN);
    RegisterNativeFunction(NATIVE_CHANGE_INNER_OUTER_PROPERTIES, "CHANGE_INNER_OUTER_PROPERTIES", Native_CHANGE_INNER_OUTER_PROPERTIES);
    RegisterNativeFunction(NATIVE_SNAPSHOT,                      "SNAPSHOT",                      Native_SNAPSHOT);
    RegisterNativeFunction(NATIVE_GET_ALIGNMENT,                 "GET_ALIGNMENT",                 Native_GET_ALIGNMENT);
    RegisterNativeFunction(NATIVE_SET_ALIGNMENT,                 "SET_ALIGNMENT",                 Native_SET_ALIGNMENT);
    RegisterNativeFunction(NATIVE_INFLUENCE_OBJECT,              "INFLUENCE_OBJECT",              Native_INFLUENCE_OBJECT);
    RegisterNativeFunction(NATIVE_INFLUENCE_POSITION,            "INFLUENCE_POSITION",            Native_INFLUENCE_POSITION);
    RegisterNativeFunction(NATIVE_GET_INFLUENCE,                 "GET_INFLUENCE",                 Native_GET_INFLUENCE);
    RegisterNativeFunction(NATIVE_SET_INTERFACE_INTERACTION,      "SET_INTERFACE_INTERACTION",      Native_SET_INTERFACE_INTERACTION);
    RegisterNativeFunction(NATIVE_PLAYED,                        "PLAYED",                        Native_PLAYED);
    RegisterNativeFunction(NATIVE_RANDOM_ULONG,                  "RANDOM_ULONG",                  Native_RANDOM_ULONG);
    RegisterNativeFunction(NATIVE_SET_GAMESPEED,                 "SET_GAMESPEED",                 Native_SET_GAMESPEED);
    RegisterNativeFunction(NATIVE_CALL_IN_NEAR,                  "CALL_IN_NEAR",                  Native_CALL_IN_NEAR);
    RegisterNativeFunction(NATIVE_OVERRIDE_STATE_ANIMATION,      "OVERRIDE_STATE_ANIMATION",      Native_OVERRIDE_STATE_ANIMATION);
    RegisterNativeFunction(NATIVE_CREATURE_CREATE_RELATIVE_TO_CREATURE, "CREATURE_CREATE_RELATIVE_TO_CREATURE", Native_CREATURE_CREATE_RELATIVE);
    RegisterNativeFunction(NATIVE_CREATURE_LEARN_EVERYTHING,     "CREATURE_LEARN_EVERYTHING",     Native_CREATURE_LEARN_EVERYTHING);
    RegisterNativeFunction(NATIVE_CREATURE_SET_KNOWS_ACTION,     "CREATURE_SET_KNOWS_ACTION",     Native_CREATURE_SET_KNOWS_ACTION);
    RegisterNativeFunction(NATIVE_CREATURE_SET_AGENDA_PRIORITY,  "CREATURE_SET_AGENDA_PRIORITY",  Native_CREATURE_SET_AGENDA_PRIORITY);
    RegisterNativeFunction(NATIVE_CREATURE_TURN_OFF_ALL_DESIRES, "CREATURE_TURN_OFF_ALL_DESIRES", Native_CREATURE_TURN_OFF_ALL_DESIRES);
    RegisterNativeFunction(NATIVE_CREATURE_LEARN_DISTINCTION_ABOUT_ACTIVITY_OBJECT, "CREATURE_LEARN_DISTINCTION_ABOUT_ACTIVITY_OBJECT", Native_CREATURE_LEARN_DISTINCTION);
    RegisterNativeFunction(NATIVE_CREATURE_DO_ACTION,            "CREATURE_DO_ACTION",            Native_CREATURE_DO_ACTION);
    RegisterNativeFunction(NATIVE_IN_CREATURE_HAND,              "IN_CREATURE_HAND",              Native_IN_CREATURE_HAND);
    RegisterNativeFunction(NATIVE_CREATURE_SET_DESIRE_VALUE,     "CREATURE_SET_DESIRE_VALUE",     Native_CREATURE_SET_DESIRE_VALUE);
    RegisterNativeFunction(NATIVE_CREATURE_SET_DESIRE_ACTIVATED_78, "CREATURE_SET_DESIRE_ACTIVATED", Native_CREATURE_SET_DESIRE_ACTIVATED);
    RegisterNativeFunction(NATIVE_CREATURE_SET_DESIRE_ACTIVATED_79, "CREATURE_SET_DESIRE_ACTIVATED", Native_CREATURE_SET_DESIRE_ACTIVATED);
    RegisterNativeFunction(NATIVE_CREATURE_SET_DESIRE_MAXIMUM,   "CREATURE_SET_DESIRE_MAXIMUM",   Native_CREATURE_SET_DESIRE_MAXIMUM);
    RegisterNativeFunction(NATIVE_CONVERT_CAMERA_POSITION,        "CONVERT_CAMERA_POSITION",       Native_CONVERT_CAMERA_POSITION);
    RegisterNativeFunction(NATIVE_CONVERT_CAMERA_FOCUS,           "CONVERT_CAMERA_FOCUS",          Native_CONVERT_CAMERA_FOCUS);
    RegisterNativeFunction(NATIVE_CREATURE_SET_PLAYER,           "CREATURE_SET_PLAYER",           Native_CREATURE_SET_PLAYER);
    RegisterNativeFunction(NATIVE_START_COUNTDOWN_TIMER,         "START_COUNTDOWN_TIMER",         Native_START_COUNTDOWN_TIMER);
    RegisterNativeFunction(NATIVE_CREATURE_INITIALISE_NUM_TIMES_PERFORMED_ACTION, "CREATURE_INITIALISE_NUM_TIMES_PERFORMED_ACTION", Native_CREATURE_INITIALISE_NUM_TIMES);
    RegisterNativeFunction(NATIVE_CREATURE_GET_NUM_TIMES_ACTION_PERFORMED, "CREATURE_GET_NUM_TIMES_ACTION_PERFORMED", Native_CREATURE_GET_NUM_TIMES);
    RegisterNativeFunction(NATIVE_REMOVE_COUNTDOWN_TIMER,        "REMOVE_COUNTDOWN_TIMER",        Native_REMOVE_COUNTDOWN_TIMER);
    RegisterNativeFunction(NATIVE_GET_OBJECT_DROPPED,            "GET_OBJECT_DROPPED",            Native_GET_OBJECT_DROPPED);
    RegisterNativeFunction(NATIVE_CLEAR_DROPPED_BY_OBJECT,       "CLEAR_DROPPED_BY_OBJECT",       Native_CLEAR_DROPPED_BY_OBJECT);
    RegisterNativeFunction(NATIVE_CREATE_REACTION,               "CREATE_REACTION",               Native_CREATE_REACTION);
    RegisterNativeFunction(NATIVE_REMOVE_REACTION,               "REMOVE_REACTION",               Native_REMOVE_REACTION);
    RegisterNativeFunction(NATIVE_GET_COUNTDOWN_TIMER,           "GET_COUNTDOWN_TIMER",           Native_GET_COUNTDOWN_TIMER);
    RegisterNativeFunction(NATIVE_START_DUAL_CAMERA,             "START_DUAL_CAMERA",             Native_START_DUAL_CAMERA);
    RegisterNativeFunction(NATIVE_UPDATE_DUAL_CAMERA,            "UPDATE_DUAL_CAMERA",            Native_UPDATE_DUAL_CAMERA);
    RegisterNativeFunction(NATIVE_RELEASE_DUAL_CAMERA,           "RELEASE_DUAL_CAMERA",           Native_RELEASE_DUAL_CAMERA);
    RegisterNativeFunction(NATIVE_SET_CREATURE_HELP,             "SET_CREATURE_HELP",             Native_SET_CREATURE_HELP);
    RegisterNativeFunction(NATIVE_GET_TARGET_OBJECT,             "GET_TARGET_OBJECT",             Native_GET_TARGET_OBJECT);
    RegisterNativeFunction(NATIVE_CREATURE_DESIRE_IS,            "CREATURE_DESIRE_IS",            Native_CREATURE_DESIRE_IS);
    RegisterNativeFunction(NATIVE_COUNTDOWN_TIMER_EXISTS,        "COUNTDOWN_TIMER_EXISTS",        Native_COUNTDOWN_TIMER_EXISTS);
    RegisterNativeFunction(NATIVE_LOOK_GAME_THING,               "LOOK_GAME_THING",               Native_LOOK_GAME_THING);
    RegisterNativeFunction(NATIVE_GET_OBJECT_DESTINATION,        "GET_OBJECT_DESTINATION",        Native_GET_OBJECT_DESTINATION);
    RegisterNativeFunction(NATIVE_CREATURE_FORCE_FINISH,         "CREATURE_FORCE_FINISH",         Native_CREATURE_FORCE_FINISH);
    RegisterNativeFunction(NATIVE_HIDE_COUNTDOWN_TIMER,          "HIDE_COUNTDOWN_TIMER",          Native_HIDE_COUNTDOWN_TIMER);
    RegisterNativeFunction(NATIVE_GET_ACTION_TEXT_FOR_OBJECT,     "GET_ACTION_TEXT_FOR_OBJECT",     Native_GET_ACTION_TEXT_FOR_OBJECT);
    RegisterNativeFunction(NATIVE_CREATE_DUAL_CAMERA_WITH_POINT, "CREATE_DUAL_CAMERA_WITH_POINT", Native_CREATE_DUAL_CAMERA_WITH_POINT);
    RegisterNativeFunction(NATIVE_SET_CAMERA_TO_FACE_OBJECT,     "SET_CAMERA_TO_FACE_OBJECT",     Native_SET_CAMERA_TO_FACE_OBJECT);
    RegisterNativeFunction(NATIVE_MOVE_CAMERA_TO_FACE_OBJECT,    "MOVE_CAMERA_TO_FACE_OBJECT",    Native_MOVE_CAMERA_TO_FACE_OBJECT);
    RegisterNativeFunction(NATIVE_GET_MOON_PERCENTAGE,           "GET_MOON_PERCENTAGE",           Native_GET_MOON_PERCENTAGE);
    RegisterNativeFunction(NATIVE_POPULATE_CONTAINER,            "POPULATE_CONTAINER",            Native_POPULATE_CONTAINER);
    RegisterNativeFunction(NATIVE_ADD_REFERENCE,                 "ADD_REFERENCE",                 Native_ADD_REFERENCE);
    RegisterNativeFunction(NATIVE_REMOVE_REFERENCE,              "REMOVE_REFERENCE",              Native_REMOVE_REFERENCE);
    RegisterNativeFunction(NATIVE_SET_GAME_TIME,                 "SET_GAME_TIME",                 Native_SET_GAME_TIME);
    RegisterNativeFunction(NATIVE_GET_GAME_TIME,                 "GET_GAME_TIME",                 Native_GET_GAME_TIME);
    RegisterNativeFunction(NATIVE_GET_REAL_TIME,                 "GET_REAL_TIME",                 Native_GET_REAL_TIME);
    RegisterNativeFunction(NATIVE_GET_REAL_DAY_115,              "GET_REAL_DAY",                  Native_GET_REAL_DAY);
    RegisterNativeFunction(NATIVE_GET_REAL_DAY_116,              "GET_REAL_DAY",                  Native_GET_REAL_DAY);
    RegisterNativeFunction(NATIVE_GET_REAL_MONTH,                "GET_REAL_MONTH",                Native_GET_REAL_MONTH);
    RegisterNativeFunction(NATIVE_GET_REAL_YEAR,                 "GET_REAL_YEAR",                 Native_GET_REAL_YEAR);
    RegisterNativeFunction(NATIVE_RUN_CAMERA_PATH,                "RUN_CAMERA_PATH",               Native_RUN_CAMERA_PATH);
    RegisterNativeFunction(NATIVE_START_DIALOGUE,                "START_DIALOGUE",                Native_START_DIALOGUE);
    RegisterNativeFunction(NATIVE_END_DIALOGUE,                  "END_DIALOGUE",                  Native_END_DIALOGUE);
    RegisterNativeFunction(NATIVE_IS_DIALOGUE_READY,             "IS_DIALOGUE_READY",             Native_IS_DIALOGUE_READY);
    RegisterNativeFunction(NATIVE_CHANGE_WEATHER_PROPERTIES,     "CHANGE_WEATHER_PROPERTIES",     Native_CHANGE_WEATHER_PROPERTIES);
    RegisterNativeFunction(NATIVE_CHANGE_LIGHTNING_PROPERTIES,   "CHANGE_LIGHTNING_PROPERTIES",   Native_CHANGE_LIGHTNING_PROPERTIES);
    RegisterNativeFunction(NATIVE_CHANGE_TIME_FADE_PROPERTIES,   "CHANGE_TIME_FADE_PROPERTIES",   Native_CHANGE_TIME_FADE_PROPERTIES);
    RegisterNativeFunction(NATIVE_CHANGE_CLOUD_PROPERTIES,       "CHANGE_CLOUD_PROPERTIES",       Native_CHANGE_CLOUD_PROPERTIES);
    RegisterNativeFunction(NATIVE_SET_HEADING_AND_SPEED,         "SET_HEADING_AND_SPEED",         Native_SET_HEADING_AND_SPEED);
    RegisterNativeFunction(NATIVE_START_GAME_SPEED,              "START_GAME_SPEED",              Native_START_GAME_SPEED);
    RegisterNativeFunction(NATIVE_END_GAME_SPEED,                "END_GAME_SPEED",                Native_END_GAME_SPEED);
    RegisterNativeFunction(NATIVE_BUILD_BUILDING,                "BUILD_BUILDING",                Native_BUILD_BUILDING);
    RegisterNativeFunction(NATIVE_SET_AFFECTED_BY_WIND,          "SET_AFFECTED_BY_WIND",          Native_SET_AFFECTED_BY_WIND);
    RegisterNativeFunction(NATIVE_WIDESCREEN_TRANSISTION_FINISHED, "WIDESCREEN_TRANSISTION_FINISHED", Native_WIDESCREEN_TRANSISTION_FINISHED);
    RegisterNativeFunction(NATIVE_GET_RESOURCE,                  "GET_RESOURCE",                  Native_GET_RESOURCE);
    RegisterNativeFunction(NATIVE_ADD_RESOURCE,                  "ADD_RESOURCE",                  Native_ADD_RESOURCE);
    RegisterNativeFunction(NATIVE_REMOVE_RESOURCE,               "REMOVE_RESOURCE",               Native_REMOVE_RESOURCE);
    RegisterNativeFunction(NATIVE_GET_TARGET_RELATIVE_POS,       "GET_TARGET_RELATIVE_POS",       Native_GET_TARGET_RELATIVE_POS);
    RegisterNativeFunction(NATIVE_STOP_POINTING,                 "STOP_POINTING",                 Native_STOP_POINTING);
    RegisterNativeFunction(NATIVE_STOP_LOOKING,                  "STOP_LOOKING",                  Native_STOP_LOOKING);
    RegisterNativeFunction(NATIVE_LOOK_AT_POSITION,              "LOOK_AT_POSITION",              Native_LOOK_AT_POSITION);
    RegisterNativeFunction(NATIVE_PLAY_SPIRIT_ANIM,              "PLAY_SPIRIT_ANIM",              Native_PLAY_SPIRIT_ANIM);
    RegisterNativeFunction(NATIVE_CALL_IN_NOT_NEAR,              "CALL_IN_NOT_NEAR",              Native_CALL_IN_NOT_NEAR);
    RegisterNativeFunction(NATIVE_SET_CAMERA_ZONE,                "SET_CAMERA_ZONE",               Native_SET_CAMERA_ZONE);
    RegisterNativeFunction(NATIVE_GET_OBJECT_STATE,              "GET_OBJECT_STATE",              Native_GET_OBJECT_STATE);
    RegisterNativeFunction(NATIVE_REVEAL_COUNTDOWN_TIMER,        "REVEAL_COUNTDOWN_TIMER",        Native_REVEAL_COUNTDOWN_TIMER);
    RegisterNativeFunction(NATIVE_SET_TIMER_TIME,                "SET_TIMER_TIME",                Native_SET_TIMER_TIME);
    RegisterNativeFunction(NATIVE_CREATE_TIMER,                  "CREATE_TIMER",                  Native_CREATE_TIMER);
    RegisterNativeFunction(NATIVE_GET_TIMER_TIME_REMAINING,      "GET_TIMER_TIME_REMAINING",      Native_GET_TIMER_TIME_REMAINING);
    RegisterNativeFunction(NATIVE_GET_TIMER_TIME_SINCE_SET,      "GET_TIMER_TIME_SINCE_SET",      Native_GET_TIMER_TIME_SINCE_SET);
    RegisterNativeFunction(NATIVE_MOVE_MUSIC,                    "MOVE_MUSIC",                    Native_MOVE_MUSIC);
    RegisterNativeFunction(NATIVE_GET_INCLUSION_DISTANCE,        "GET_INCLUSION_DISTANCE",        Native_GET_INCLUSION_DISTANCE);
    RegisterNativeFunction(NATIVE_GET_LAND_HEIGHT,               "GET_LAND_HEIGHT",               Native_GET_LAND_HEIGHT);
    RegisterNativeFunction(NATIVE_LOAD_MAP,                      "LOAD_MAP",                      Native_LOAD_MAP);
    RegisterNativeFunction(NATIVE_STOP_ALL_SCRIPTS_EXCLUDING,    "STOP_ALL_SCRIPTS_EXCLUDING",    Native_STOP_ALL_SCRIPTS_EXCLUDING);
    RegisterNativeFunction(NATIVE_STOP_ALL_SCRIPTS_IN_FILES_EXCLUDING, "STOP_ALL_SCRIPTS_IN_FILES_EXCLUDING", Native_STOP_ALL_SCRIPTS_IN_FILES_EXCLUDING);
    RegisterNativeFunction(NATIVE_STOP_SCRIPT,                   "STOP_SCRIPT",                   Native_STOP_SCRIPT);
    RegisterNativeFunction(NATIVE_CLEAR_CLICKED_OBJECT,          "CLEAR_CLICKED_OBJECT",          Native_CLEAR_CLICKED_OBJECT);
    RegisterNativeFunction(NATIVE_CLEAR_CLICKED_POSITION,        "CLEAR_CLICKED_POSITION",        Native_CLEAR_CLICKED_POSITION);
    RegisterNativeFunction(NATIVE_POSITION_CLICKED,              "POSITION_CLICKED",              Native_POSITION_CLICKED);
    RegisterNativeFunction(NATIVE_RELEASE_FROM_SCRIPT,           "RELEASE_FROM_SCRIPT",           Native_RELEASE_FROM_SCRIPT);
    RegisterNativeFunction(NATIVE_GET_OBJECT_HAND_IS_OVER,       "GET_OBJECT_HAND_IS_OVER",       Native_GET_OBJECT_HAND_IS_OVER);
    RegisterNativeFunction(NATIVE_ID_POISONED_SIZE,              "ID_POISONED_SIZE",              Native_ID_POISONED_SIZE);
    RegisterNativeFunction(NATIVE_IS_POISONED,                   "IS_POISONED",                   Native_IS_POISONED);
    RegisterNativeFunction(NATIVE_CALL_POISONED_IN,              "CALL_POISONED_IN",              Native_CALL_POISONED_IN);
    RegisterNativeFunction(NATIVE_CALL_NOT_POISONED_IN,          "CALL_NOT_POISONED_IN",          Native_CALL_NOT_POISONED_IN);
    RegisterNativeFunction(NATIVE_SPIRIT_PLAYED,                 "SPIRIT_PLAYED",                 Native_SPIRIT_PLAYED);
    RegisterNativeFunction(NATIVE_CLING_SPIRIT,                  "CLING_SPIRIT",                  Native_CLING_SPIRIT);
    RegisterNativeFunction(NATIVE_FLY_SPIRIT,                    "FLY_SPIRIT",                    Native_FLY_SPIRIT);
    RegisterNativeFunction(NATIVE_SET_ID_MOVEABLE,               "SET_ID_MOVEABLE",               Native_SET_ID_MOVEABLE);
    RegisterNativeFunction(NATIVE_SET_ID_PICKUPABLE,             "SET_ID_PICKUPABLE",             Native_SET_ID_PICKUPABLE);
    RegisterNativeFunction(NATIVE_IS_ON_FIRE,                    "IS_ON_FIRE",                    Native_IS_ON_FIRE);
    RegisterNativeFunction(NATIVE_IS_FIRE_NEAR,                  "IS_FIRE_NEAR",                  Native_IS_FIRE_NEAR);
    RegisterNativeFunction(NATIVE_STOP_SCRIPTS_IN_FILES,         "STOP_SCRIPTS_IN_FILES",         Native_STOP_SCRIPTS_IN_FILES);
    RegisterNativeFunction(NATIVE_SET_POISONED,                  "SET_POISONED",                  Native_SET_POISONED);
    RegisterNativeFunction(NATIVE_SET_TEMPERATURE,               "SET_TEMPERATURE",               Native_SET_TEMPERATURE);
    RegisterNativeFunction(NATIVE_SET_ON_FIRE,                   "SET_ON_FIRE",                   Native_SET_ON_FIRE);
    RegisterNativeFunction(NATIVE_SET_TARGET,                    "SET_TARGET",                    Native_SET_TARGET);
    RegisterNativeFunction(NATIVE_WALK_PATH,                     "WALK_PATH",                     Native_WALK_PATH);
    RegisterNativeFunction(NATIVE_FOCUS_AND_POSITION_FOLLOW,     "FOCUS_AND_POSITION_FOLLOW",     Native_FOCUS_AND_POSITION_FOLLOW);
    RegisterNativeFunction(NATIVE_GET_WALK_PATH_PERCENTAGE,      "GET_WALK_PATH_PERCENTAGE",      Native_GET_WALK_PATH_PERCENTAGE);
    RegisterNativeFunction(NATIVE_CAMERA_PROPERTIES,             "CAMERA_PROPERTIES",             Native_CAMERA_PROPERTIES);
    RegisterNativeFunction(NATIVE_ENABLE_DISABLE_MUSIC,          "ENABLE_DISABLE_MUSIC",          Native_ENABLE_DISABLE_MUSIC);
    RegisterNativeFunction(NATIVE_GET_MUSIC_OBJ_DISTANCE,        "GET_MUSIC_OBJ_DISTANCE",        Native_GET_MUSIC_OBJ_DISTANCE);
    RegisterNativeFunction(NATIVE_GET_MUSIC_ENUM_DISTANCE,       "GET_MUSIC_ENUM_DISTANCE",       Native_GET_MUSIC_ENUM_DISTANCE);
    RegisterNativeFunction(NATIVE_SET_MUSIC_PLAY_POSITION,       "SET_MUSIC_PLAY_POSITION",       Native_SET_MUSIC_PLAY_POSITION);
    RegisterNativeFunction(NATIVE_ATTACH_OBJECT_LEASH_TO_OBJECT, "ATTACH_OBJECT_LEASH_TO_OBJECT", Native_ATTACH_OBJECT_LEASH_TO_OBJECT);
    RegisterNativeFunction(NATIVE_ATTACH_OBJECT_LEASH_TO_HAND,   "ATTACH_OBJECT_LEASH_TO_HAND",   Native_ATTACH_OBJECT_LEASH_TO_HAND);
    RegisterNativeFunction(NATIVE_DETACH_OBJECT_LEASH,           "DETACH_OBJECT_LEASH",           Native_DETACH_OBJECT_LEASH);
    RegisterNativeFunction(NATIVE_SET_CREATURE_ONLY_DESIRE,      "SET_CREATURE_ONLY_DESIRE",      Native_SET_CREATURE_ONLY_DESIRE);
    RegisterNativeFunction(NATIVE_SET_CREATURE_ONLY_DESIRE_OFF,  "SET_CREATURE_ONLY_DESIRE_OFF",  Native_SET_CREATURE_ONLY_DESIRE_OFF);
    RegisterNativeFunction(NATIVE_RESTART_MUSIC,                 "RESTART_MUSIC",                 Native_RESTART_MUSIC);
    RegisterNativeFunction(NATIVE_MUSIC_PLAYED_191,              "MUSIC_PLAYED",                  Native_MUSIC_PLAYED);
    RegisterNativeFunction(NATIVE_IS_OF_TYPE,                    "IS_OF_TYPE",                    Native_IS_OF_TYPE);
    RegisterNativeFunction(NATIVE_CLEAR_HIT_OBJECT,              "CLEAR_HIT_OBJECT",              Native_CLEAR_HIT_OBJECT);
    RegisterNativeFunction(NATIVE_GAME_THING_HIT,                "GAME_THING_HIT",                Native_GAME_THING_HIT);
    RegisterNativeFunction(NATIVE_SPELL_AT_THING,                "SPELL_AT_THING",                Native_SPELL_AT_THING);
    RegisterNativeFunction(NATIVE_SPELL_AT_POS,                  "SPELL_AT_POS",                  Native_SPELL_AT_POS);
    RegisterNativeFunction(NATIVE_CALL_PLAYER_CREATURE,          "CALL_PLAYER_CREATURE",          Native_CALL_PLAYER_CREATURE);
    RegisterNativeFunction(NATIVE_GET_SLOWEST_SPEED,             "GET_SLOWEST_SPEED",             Native_GET_SLOWEST_SPEED);
    RegisterNativeFunction(NATIVE_GET_OBJECT_HELD_199,           "GET_OBJECT_HELD",               Native_GET_OBJECT_HELD);
    RegisterNativeFunction(NATIVE_HELP_SYSTEM_ON,                "HELP_SYSTEM_ON",                Native_HELP_SYSTEM_ON);
    RegisterNativeFunction(NATIVE_SHAKE_CAMERA,                  "SHAKE_CAMERA",                  Native_SHAKE_CAMERA);
    RegisterNativeFunction(NATIVE_SET_ANIMATION_MODIFY,          "SET_ANIMATION_MODIFY",          Native_SET_ANIMATION_MODIFY);
    RegisterNativeFunction(NATIVE_SET_AVI_SEQUENCE,              "SET_AVI_SEQUENCE",              Native_SET_AVI_SEQUENCE);
    RegisterNativeFunction(NATIVE_PLAY_GESTURE,                  "PLAY_GESTURE",                  Native_PLAY_GESTURE);
    RegisterNativeFunction(NATIVE_DEV_FUNCTION,                  "DEV_FUNCTION",                  Native_DEV_FUNCTION);
    RegisterNativeFunction(NATIVE_HAS_MOUSE_WHEEL,               "HAS_MOUSE_WHEEL",               Native_HAS_MOUSE_WHEEL);
    RegisterNativeFunction(NATIVE_NUM_MOUSE_BUTTONS,             "NUM_MOUSE_BUTTONS",             Native_NUM_MOUSE_BUTTONS);
    RegisterNativeFunction(NATIVE_SET_CREATURE_DEV_STAGE,        "SET_CREATURE_DEV_STAGE",        Native_SET_CREATURE_DEV_STAGE);
    RegisterNativeFunction(NATIVE_SET_FIXED_CAM_ROTATION,        "SET_FIXED_CAM_ROTATION",        Native_SET_FIXED_CAM_ROTATION);
    RegisterNativeFunction(NATIVE_SWAP_CREATURE,                 "SWAP_CREATURE",                 Native_SWAP_CREATURE);
    RegisterNativeFunction(NATIVE_GET_ARENA,                     "GET_ARENA",                     Native_GET_ARENA);
    RegisterNativeFunction(NATIVE_GET_FOOTBALL_PITCH,            "GET_FOOTBALL_PITCH",            Native_GET_FOOTBALL_PITCH);
    RegisterNativeFunction(NATIVE_STOP_ALL_GAMES,                "STOP_ALL_GAMES",                Native_STOP_ALL_GAMES);
    RegisterNativeFunction(NATIVE_ATTACH_TO_GAME,                "ATTACH_TO_GAME",                Native_ATTACH_TO_GAME);
    RegisterNativeFunction(NATIVE_DETACH_FROM_GAME,              "DETACH_FROM_GAME",              Native_DETACH_FROM_GAME);
    RegisterNativeFunction(NATIVE_DETACH_UNDEFINED_FROM_GAME,    "DETACH_UNDEFINED_FROM_GAME",    Native_DETACH_UNDEFINED_FROM_GAME);
    RegisterNativeFunction(NATIVE_SET_ONLY_FOR_SCRIPTS,          "SET_ONLY_FOR_SCRIPTS",          Native_SET_ONLY_FOR_SCRIPTS);
    RegisterNativeFunction(NATIVE_START_MATCH_WITH_REFEREE,      "START_MATCH_WITH_REFEREE",      Native_START_MATCH_WITH_REFEREE);
    RegisterNativeFunction(NATIVE_GAME_TEAM_SIZE,                "GAME_TEAM_SIZE",                Native_GAME_TEAM_SIZE);
    RegisterNativeFunction(NATIVE_GAME_TYPE,                     "GAME_TYPE",                     Native_GAME_TYPE);
    RegisterNativeFunction(NATIVE_GAME_SUB_TYPE,                 "GAME_SUB_TYPE",                 Native_GAME_SUB_TYPE);
    RegisterNativeFunction(NATIVE_IS_LEASHED,                    "IS_LEASHED",                    Native_IS_LEASHED);
    RegisterNativeFunction(NATIVE_SET_CREATURE_HOME,             "SET_CREATURE_HOME",             Native_SET_CREATURE_HOME);
    RegisterNativeFunction(NATIVE_GET_HIT_OBJECT,                "GET_HIT_OBJECT",                Native_GET_HIT_OBJECT);
    RegisterNativeFunction(NATIVE_GET_OBJECT_WHICH_HIT,          "GET_OBJECT_WHICH_HIT",          Native_GET_OBJECT_WHICH_HIT);
    RegisterNativeFunction(NATIVE_GET_NEAREST_TOWN_OF_PLAYER,    "GET_NEAREST_TOWN_OF_PLAYER",    Native_GET_NEAREST_TOWN_OF_PLAYER);
    RegisterNativeFunction(NATIVE_SPELL_AT_POINT,                "SPELL_AT_POINT",                Native_SPELL_AT_POINT);
    RegisterNativeFunction(NATIVE_SET_ATTACK_OWN_TOWN,           "SET_ATTACK_OWN_TOWN",           Native_SET_ATTACK_OWN_TOWN);
    RegisterNativeFunction(NATIVE_IS_FIGHTING,                   "IS_FIGHTING",                   Native_IS_FIGHTING);
    RegisterNativeFunction(NATIVE_SET_MAGIC_RADIUS,              "SET_MAGIC_RADIUS",              Native_SET_MAGIC_RADIUS);
    RegisterNativeFunction(NATIVE_TEMP_TEXT_WITH_NUMBER,          "TEMP_TEXT_WITH_NUMBER",          Native_TEMP_TEXT_WITH_NUMBER);
    RegisterNativeFunction(NATIVE_RUN_TEXT_WITH_NUMBER,           "RUN_TEXT_WITH_NUMBER",           Native_RUN_TEXT_WITH_NUMBER);
    RegisterNativeFunction(NATIVE_CREATURE_SPELL_REVERSION,      "CREATURE_SPELL_REVERSION",      Native_CREATURE_SPELL_REVERSION);
    RegisterNativeFunction(NATIVE_GET_DESIRE,                    "GET_DESIRE",                    Native_GET_DESIRE);
    RegisterNativeFunction(NATIVE_GET_EVENTS_PER_SECOND,         "GET_EVENTS_PER_SECOND",         Native_GET_EVENTS_PER_SECOND);
    RegisterNativeFunction(NATIVE_GET_TIME_SINCE,                "GET_TIME_SINCE",                Native_GET_TIME_SINCE);
    RegisterNativeFunction(NATIVE_GET_TOTAL_EVENTS,              "GET_TOTAL_EVENTS",              Native_GET_TOTAL_EVENTS);
    RegisterNativeFunction(NATIVE_UPDATE_SNAPSHOT,               "UPDATE_SNAPSHOT",               Native_UPDATE_SNAPSHOT);
    RegisterNativeFunction(NATIVE_CREATE_REWARD,                 "CREATE_REWARD",                 Native_CREATE_REWARD);
    RegisterNativeFunction(NATIVE_CREATE_REWARD_IN_TOWN,         "CREATE_REWARD_IN_TOWN",         Native_CREATE_REWARD_IN_TOWN);
    RegisterNativeFunction(NATIVE_SET_FADE,                      "SET_FADE",                      Native_SET_FADE);
    RegisterNativeFunction(NATIVE_SET_FADE_IN,                   "SET_FADE_IN",                   Native_SET_FADE_IN);
    RegisterNativeFunction(NATIVE_FADE_FINISHED,                 "FADE_FINISHED",                 Native_FADE_FINISHED);
    RegisterNativeFunction(NATIVE_SET_PLAYER_MAGIC,              "SET_PLAYER_MAGIC",              Native_SET_PLAYER_MAGIC);
    RegisterNativeFunction(NATIVE_HAS_PLAYER_MAGIC,              "HAS_PLAYER_MAGIC",              Native_HAS_PLAYER_MAGIC);
    RegisterNativeFunction(NATIVE_SPIRIT_SPEAKS,                 "SPIRIT_SPEAKS",                 Native_SPIRIT_SPEAKS);
    RegisterNativeFunction(NATIVE_BELIEF_FOR_PLAYER,             "BELIEF_FOR_PLAYER",             Native_BELIEF_FOR_PLAYER);
    RegisterNativeFunction(NATIVE_GET_HELP,                      "GET_HELP",                      Native_GET_HELP);
    RegisterNativeFunction(NATIVE_SET_LEASH_WORKS,               "SET_LEASH_WORKS",               Native_SET_LEASH_WORKS);
    RegisterNativeFunction(NATIVE_LOAD_MY_CREATURE,              "LOAD_MY_CREATURE",              Native_LOAD_MY_CREATURE);
    RegisterNativeFunction(NATIVE_OBJECT_RELATIVE_BELIEF,        "OBJECT_RELATIVE_BELIEF",        Native_OBJECT_RELATIVE_BELIEF);
    RegisterNativeFunction(NATIVE_CREATE_WITH_ANGLE_AND_SCALE,   "CREATE_WITH_ANGLE_AND_SCALE",   Native_CREATE_WITH_ANGLE_AND_SCALE);
    RegisterNativeFunction(NATIVE_SET_HELP_SYSTEM,               "SET_HELP_SYSTEM",               Native_SET_HELP_SYSTEM);
    RegisterNativeFunction(NATIVE_SET_VIRTUAL_INFLUENCE,         "SET_VIRTUAL_INFLUENCE",         Native_SET_VIRTUAL_INFLUENCE);
    RegisterNativeFunction(NATIVE_SET_ACTIVE,                    "SET_ACTIVE",                    Native_SET_ACTIVE);
    RegisterNativeFunction(NATIVE_THING_VALID,                   "THING_VALID",                   Native_THING_VALID);
    RegisterNativeFunction(NATIVE_VORTEX_FADE_OUT,               "VORTEX_FADE_OUT",               Native_VORTEX_FADE_OUT);
    RegisterNativeFunction(NATIVE_REMOVE_REACTION_OF_TYPE,       "REMOVE_REACTION_OF_TYPE",       Native_REMOVE_REACTION_OF_TYPE);
    RegisterNativeFunction(NATIVE_CREATURE_LEARN_EVERYTHING_EXCLUDING, "CREATURE_LEARN_EVERYTHING_EXCLUDING", Native_CREATURE_LEARN_EVERYTHING_EXCLUDING);
    RegisterNativeFunction(NATIVE_PLAYED_PERCENTAGE,             "PLAYED_PERCENTAGE",             Native_PLAYED_PERCENTAGE);
    RegisterNativeFunction(NATIVE_OBJECT_CAST_BY_OBJECT,         "OBJECT_CAST_BY_OBJECT",         Native_OBJECT_CAST_BY_OBJECT);
    RegisterNativeFunction(NATIVE_IS_WIND_MAGIC_AT_POS,          "IS_WIND_MAGIC_AT_POS",          Native_IS_WIND_MAGIC_AT_POS);
    RegisterNativeFunction(NATIVE_CREATE_MIST,                   "CREATE_MIST",                   Native_CREATE_MIST);
    RegisterNativeFunction(NATIVE_SET_MIST_FADE,                 "SET_MIST_FADE",                 Native_SET_MIST_FADE);
    RegisterNativeFunction(NATIVE_GET_OBJECT_FADE,               "GET_OBJECT_FADE",               Native_GET_OBJECT_FADE);
    RegisterNativeFunction(NATIVE_PLAY_HAND_DEMO,                "PLAY_HAND_DEMO",                Native_PLAY_HAND_DEMO);
    RegisterNativeFunction(NATIVE_IS_PLAYING_HAND_DEMO,          "IS_PLAYING_HAND_DEMO",          Native_IS_PLAYING_HAND_DEMO);
    RegisterNativeFunction(NATIVE_GET_ARSE_POSITION,             "GET_ARSE_POSITION",             Native_GET_ARSE_POSITION);
    RegisterNativeFunction(NATIVE_IS_LEASHED_TO_OBJECT,          "IS_LEASHED_TO_OBJECT",          Native_IS_LEASHED_TO_OBJECT);
    RegisterNativeFunction(NATIVE_GET_INTERACTION_MAGNITUDE,     "GET_INTERACTION_MAGNITUDE",     Native_GET_INTERACTION_MAGNITUDE);
    RegisterNativeFunction(NATIVE_IS_CREATURE_AVAILABLE,         "IS_CREATURE_AVAILABLE",         Native_IS_CREATURE_AVAILABLE);
    RegisterNativeFunction(NATIVE_CREATE_HIGHLIGHT,              "CREATE_HIGHLIGHT",              Native_CREATE_HIGHLIGHT);
    RegisterNativeFunction(NATIVE_GET_OBJECT_HELD_273,           "GET_OBJECT_HELD",               Native_GET_OBJECT_HELD);
    RegisterNativeFunction(NATIVE_GET_ACTION_COUNT,              "GET_ACTION_COUNT",              Native_GET_ACTION_COUNT);
    RegisterNativeFunction(NATIVE_GET_OBJECT_LEASH_TYPE,         "GET_OBJECT_LEASH_TYPE",         Native_GET_OBJECT_LEASH_TYPE);
    RegisterNativeFunction(NATIVE_SET_FOCUS_FOLLOW,              "SET_FOCUS_FOLLOW",              Native_SET_FOCUS_FOLLOW);
    RegisterNativeFunction(NATIVE_SET_POSITION_FOLLOW,           "SET_POSITION_FOLLOW",           Native_SET_POSITION_FOLLOW);
    RegisterNativeFunction(NATIVE_SET_FOCUS_AND_POSITION_FOLLOW, "SET_FOCUS_AND_POSITION_FOLLOW", Native_SET_FOCUS_AND_POSITION_FOLLOW);
    RegisterNativeFunction(NATIVE_SET_CAMERA_LENS,               "SET_CAMERA_LENS",               Native_SET_CAMERA_LENS);
    RegisterNativeFunction(NATIVE_MOVE_CAMERA_LENS,              "MOVE_CAMERA_LENS",              Native_MOVE_CAMERA_LENS);
    RegisterNativeFunction(NATIVE_CREATURE_REACTION,             "CREATURE_REACTION",             Native_CREATURE_REACTION);
    RegisterNativeFunction(NATIVE_CREATURE_IN_DEV_SCRIPT,        "CREATURE_IN_DEV_SCRIPT",        Native_CREATURE_IN_DEV_SCRIPT);
    RegisterNativeFunction(NATIVE_STORE_CAMERA_DETAILS,          "STORE_CAMERA_DETAILS",          Native_STORE_CAMERA_DETAILS);
    RegisterNativeFunction(NATIVE_RESTORE_CAMERA_DETAILS,        "RESTORE_CAMERA_DETAILS",        Native_RESTORE_CAMERA_DETAILS);
    RegisterNativeFunction(NATIVE_START_ANGLE_SOUND_285,         "START_ANGLE_SOUND",             Native_START_ANGLE_SOUND);
    RegisterNativeFunction(NATIVE_SET_CAMERA_POS_FOC_LENS,       "SET_CAMERA_POS_FOC_LENS",       Native_SET_CAMERA_POS_FOC_LENS);
    RegisterNativeFunction(NATIVE_MOVE_CAMERA_POS_FOC_LENS,      "MOVE_CAMERA_POS_FOC_LENS",      Native_MOVE_CAMERA_POS_FOC_LENS);
    RegisterNativeFunction(NATIVE_GAME_TIME_ON_OFF,              "GAME_TIME_ON_OFF",              Native_GAME_TIME_ON_OFF);
    RegisterNativeFunction(NATIVE_MOVE_GAME_TIME,                "MOVE_GAME_TIME",                Native_MOVE_GAME_TIME);
    RegisterNativeFunction(NATIVE_SET_HIGH_GRAPHICS_DETAIL,      "SET_HIGH_GRAPHICS_DETAIL",      Native_SET_HIGH_GRAPHICS_DETAIL);
    RegisterNativeFunction(NATIVE_SET_SKELETON,                  "SET_SKELETON",                  Native_SET_SKELETON);
    RegisterNativeFunction(NATIVE_IS_SKELETON,                   "IS_SKELETON",                   Native_IS_SKELETON);
    RegisterNativeFunction(NATIVE_PLAYER_SPELL_CAST_TIME,        "PLAYER_SPELL_CAST_TIME",        Native_PLAYER_SPELL_CAST_TIME);
    RegisterNativeFunction(NATIVE_PLAYER_SPELL_LAST_CAST,        "PLAYER_SPELL_LAST_CAST",        Native_PLAYER_SPELL_LAST_CAST);
    RegisterNativeFunction(NATIVE_GET_LAST_SPELL_CAST_POS,       "GET_LAST_SPELL_CAST_POS",       Native_GET_LAST_SPELL_CAST_POS);
    RegisterNativeFunction(NATIVE_ADD_SPOT_VISUAL_TARGET_POS,    "ADD_SPOT_VISUAL_TARGET_POS",    Native_ADD_SPOT_VISUAL_TARGET_POS);
    RegisterNativeFunction(NATIVE_ADD_SPOT_VISUAL_TARGET_OBJECT, "ADD_SPOT_VISUAL_TARGET_OBJECT", Native_ADD_SPOT_VISUAL_TARGET_OBJECT);
    RegisterNativeFunction(NATIVE_SET_INDESTRUCTABLE,            "SET_INDESTRUCTABLE",            Native_SET_INDESTRUCTABLE);
    RegisterNativeFunction(NATIVE_SET_GRAPHICS_CLIPPING,         "SET_GRAPHICS_CLIPPING",         Native_SET_GRAPHICS_CLIPPING);
    RegisterNativeFunction(NATIVE_SPIRIT_APPEAR,                 "SPIRIT_APPEAR",                 Native_SPIRIT_APPEAR);
    RegisterNativeFunction(NATIVE_SPIRIT_DISAPPEAR,              "SPIRIT_DISAPPEAR",              Native_SPIRIT_DISAPPEAR);
    RegisterNativeFunction(NATIVE_SET_FOCUS_ON_OBJECT,           "SET_FOCUS_ON_OBJECT",           Native_SET_FOCUS_ON_OBJECT);
    RegisterNativeFunction(NATIVE_RELEASE_OBJECT_FOCUS,          "RELEASE_OBJECT_FOCUS",          Native_RELEASE_OBJECT_FOCUS);
    RegisterNativeFunction(NATIVE_IMMERSION_EXISTS,              "IMMERSION_EXISTS",              Native_IMMERSION_EXISTS);
    RegisterNativeFunction(NATIVE_SET_DRAW_LEASH,                "SET_DRAW_LEASH",                Native_SET_DRAW_LEASH);
    RegisterNativeFunction(NATIVE_SET_DRAW_HIGHLIGHT,            "SET_DRAW_HIGHLIGHT",            Native_SET_DRAW_HIGHLIGHT);
    RegisterNativeFunction(NATIVE_SET_OPEN_CLOSE,                "SET_OPEN_CLOSE",                Native_SET_OPEN_CLOSE);
    RegisterNativeFunction(NATIVE_SET_INTRO_BUILDING,            "SET_INTRO_BUILDING",            Native_SET_INTRO_BUILDING);
    RegisterNativeFunction(NATIVE_CREATURE_FORCE_FRIENDS,        "CREATURE_FORCE_FRIENDS",        Native_CREATURE_FORCE_FRIENDS);
    RegisterNativeFunction(NATIVE_MOVE_COMPUTER_PLAYER_POSITION, "MOVE_COMPUTER_PLAYER_POSITION", Native_MOVE_COMPUTER_PLAYER_POSITION);
    RegisterNativeFunction(NATIVE_ENABLE_DISABLE_COMPUTER_PLAYER_311, "ENABLE_DISABLE_COMPUTER_PLAYER", Native_ENABLE_DISABLE_COMPUTER_PLAYER);
    RegisterNativeFunction(NATIVE_GET_COMPUTER_PLAYER_POSITION,  "GET_COMPUTER_PLAYER_POSITION",  Native_GET_COMPUTER_PLAYER_POSITION);
    RegisterNativeFunction(NATIVE_SET_COMPUTER_PLAYER_POSITION,  "SET_COMPUTER_PLAYER_POSITION",  Native_SET_COMPUTER_PLAYER_POSITION);
    RegisterNativeFunction(NATIVE_GET_STORED_CAMERA_POSITION,    "GET_STORED_CAMERA_POSITION",    Native_GET_STORED_CAMERA_POSITION);
    RegisterNativeFunction(NATIVE_GET_STORED_CAMERA_FOCUS,       "GET_STORED_CAMERA_FOCUS",       Native_GET_STORED_CAMERA_FOCUS);
    RegisterNativeFunction(NATIVE_CALL_NEAR_IN_STATE,            "CALL_NEAR_IN_STATE",            Native_CALL_NEAR_IN_STATE);
    RegisterNativeFunction(NATIVE_SET_CREATURE_SOUND,            "SET_CREATURE_SOUND",            Native_SET_CREATURE_SOUND);
    RegisterNativeFunction(NATIVE_CREATURE_INTERACTING_WITH,     "CREATURE_INTERACTING_WITH",     Native_CREATURE_INTERACTING_WITH);
    RegisterNativeFunction(NATIVE_SET_SUN_DRAW,                  "SET_SUN_DRAW",                  Native_SET_SUN_DRAW);
    RegisterNativeFunction(NATIVE_OBJECT_INFO_BITS,              "OBJECT_INFO_BITS",              Native_OBJECT_INFO_BITS);
    RegisterNativeFunction(NATIVE_SET_HURT_BY_FIRE,              "SET_HURT_BY_FIRE",              Native_SET_HURT_BY_FIRE);
    RegisterNativeFunction(NATIVE_CONFINED_OBJECT,               "CONFINED_OBJECT",               Native_CONFINED_OBJECT);
    RegisterNativeFunction(NATIVE_CLEAR_CONFINED_OBJECT,         "CLEAR_CONFINED_OBJECT",         Native_CLEAR_CONFINED_OBJECT);
    RegisterNativeFunction(NATIVE_GET_OBJECT_FLOCK,              "GET_OBJECT_FLOCK",              Native_GET_OBJECT_FLOCK);
    RegisterNativeFunction(NATIVE_SET_PLAYER_BELIEF,             "SET_PLAYER_BELIEF",             Native_SET_PLAYER_BELIEF);
    RegisterNativeFunction(NATIVE_PLAY_JC_SPECIAL,               "PLAY_JC_SPECIAL",               Native_PLAY_JC_SPECIAL);
    RegisterNativeFunction(NATIVE_IS_PLAYING_JC_SPECIAL,         "IS_PLAYING_JC_SPECIAL",         Native_IS_PLAYING_JC_SPECIAL);
    RegisterNativeFunction(NATIVE_VORTEX_PARAMETERS,             "VORTEX_PARAMETERS",             Native_VORTEX_PARAMETERS);
    RegisterNativeFunction(NATIVE_LOAD_CREATURE,                 "LOAD_CREATURE",                 Native_LOAD_CREATURE);
    RegisterNativeFunction(NATIVE_IS_SPELL_CHARGING,             "IS_SPELL_CHARGING",             Native_IS_SPELL_CHARGING);
    RegisterNativeFunction(NATIVE_IS_THAT_SPELL_CHARGING,        "IS_THAT_SPELL_CHARGING",        Native_IS_THAT_SPELL_CHARGING);
    RegisterNativeFunction(NATIVE_OPPOSING_CREATURE,             "OPPOSING_CREATURE",             Native_OPPOSING_CREATURE);
    RegisterNativeFunction(NATIVE_FLOCK_WITHIN_LIMITS,           "FLOCK_WITHIN_LIMITS",           Native_FLOCK_WITHIN_LIMITS);
    RegisterNativeFunction(NATIVE_HIGHLIGHT_PROPERTIES,          "HIGHLIGHT_PROPERTIES",          Native_HIGHLIGHT_PROPERTIES);
    RegisterNativeFunction(NATIVE_LAST_MUSIC_LINE,               "LAST_MUSIC_LINE",               Native_LAST_MUSIC_LINE);
    RegisterNativeFunction(NATIVE_HAND_DEMO_TRIGGER,             "HAND_DEMO_TRIGGER",             Native_HAND_DEMO_TRIGGER);
    RegisterNativeFunction(NATIVE_GET_BELLY_POSITION,            "GET_BELLY_POSITION",            Native_GET_BELLY_POSITION);
    RegisterNativeFunction(NATIVE_SET_CREATURE_CREED_PROPERTIES, "SET_CREATURE_CREED_PROPERTIES", Native_SET_CREATURE_CREED_PROPERTIES);
    RegisterNativeFunction(NATIVE_GAME_THING_CAN_VIEW_CAMERA,    "GAME_THING_CAN_VIEW_CAMERA",    Native_GAME_THING_CAN_VIEW_CAMERA);
    RegisterNativeFunction(NATIVE_GAME_PLAY_SAY_SOUND_EFFECT,    "GAME_PLAY_SAY_SOUND_EFFECT",    Native_GAME_PLAY_SAY_SOUND_EFFECT);
    RegisterNativeFunction(NATIVE_SET_TOWN_DESIRE_BOOST,         "SET_TOWN_DESIRE_BOOST",         Native_SET_TOWN_DESIRE_BOOST);
    RegisterNativeFunction(NATIVE_IS_LOCKED_INTERACTION,         "IS_LOCKED_INTERACTION",         Native_IS_LOCKED_INTERACTION);
    RegisterNativeFunction(NATIVE_SET_CREATURE_NAME,             "SET_CREATURE_NAME",             Native_SET_CREATURE_NAME);
    RegisterNativeFunction(NATIVE_COMPUTER_PLAYER_READY,         "COMPUTER_PLAYER_READY",         Native_COMPUTER_PLAYER_READY);
    RegisterNativeFunction(NATIVE_ENABLE_DISABLE_COMPUTER_PLAYER_345, "ENABLE_DISABLE_COMPUTER_PLAYER", Native_ENABLE_DISABLE_COMPUTER_PLAYER);
    RegisterNativeFunction(NATIVE_CLEAR_ACTOR_MIND,              "CLEAR_ACTOR_MIND",              Native_CLEAR_ACTOR_MIND);
    RegisterNativeFunction(NATIVE_ENTER_EXIT_CITADEL,            "ENTER_EXIT_CITADEL",            Native_ENTER_EXIT_CITADEL);
    RegisterNativeFunction(NATIVE_START_ANGLE_SOUND_348,         "START_ANGLE_SOUND",             Native_START_ANGLE_SOUND);
    RegisterNativeFunction(NATIVE_THING_JC_SPECIAL,              "THING_JC_SPECIAL",              Native_THING_JC_SPECIAL);
    RegisterNativeFunction(NATIVE_MUSIC_PLAYED_350,              "MUSIC_PLAYED",                  Native_MUSIC_PLAYED);
    RegisterNativeFunction(NATIVE_UPDATE_SNAPSHOT_PICTURE,       "UPDATE_SNAPSHOT_PICTURE",       Native_UPDATE_SNAPSHOT_PICTURE);
    RegisterNativeFunction(NATIVE_STOP_SCRIPTS_IN_FILES_EXCLUDING, "STOP_SCRIPTS_IN_FILES_EXCLUDING", Native_STOP_SCRIPTS_IN_FILES_EXCLUDING);
    RegisterNativeFunction(NATIVE_CREATE_RANDOM_VILLAGER_OF_TRIBE, "CREATE_RANDOM_VILLAGER_OF_TRIBE", Native_CREATE_RANDOM_VILLAGER_OF_TRIBE);
    RegisterNativeFunction(NATIVE_TOGGLE_LEASH,                  "TOGGLE_LEASH",                  Native_TOGGLE_LEASH);
    RegisterNativeFunction(NATIVE_GAME_SET_MANA,                 "GAME_SET_MANA",                 Native_GAME_SET_MANA);
    RegisterNativeFunction(NATIVE_SET_MAGIC_PROPERTIES,          "SET_MAGIC_PROPERTIES",          Native_SET_MAGIC_PROPERTIES);
    RegisterNativeFunction(NATIVE_SET_GAME_SOUND,                "SET_GAME_SOUND",                Native_SET_GAME_SOUND);
    RegisterNativeFunction(NATIVE_SEX_IS_MALE,                   "SEX_IS_MALE",                   Native_SEX_IS_MALE);
    RegisterNativeFunction(NATIVE_GET_FIRST_HELP,                "GET_FIRST_HELP",                Native_GET_FIRST_HELP);
    RegisterNativeFunction(NATIVE_GET_LAST_HELP,                 "GET_LAST_HELP",                 Native_GET_LAST_HELP);
    RegisterNativeFunction(NATIVE_IS_ACTIVE,                     "IS_ACTIVE",                     Native_IS_ACTIVE);
    RegisterNativeFunction(NATIVE_SET_BOOKMARK_POSITION,         "SET_BOOKMARK_POSITION",         Native_SET_BOOKMARK_POSITION);
    RegisterNativeFunction(NATIVE_SET_SCAFFOLD_PROPERTIES,       "SET_SCAFFOLD_PROPERTIES",       Native_SET_SCAFFOLD_PROPERTIES);
    RegisterNativeFunction(NATIVE_SET_COMPUTER_PLAYER_PERSONALITY, "SET_COMPUTER_PLAYER_PERSONALITY", Native_SET_COMPUTER_PLAYER_PERSONALITY);
    RegisterNativeFunction(NATIVE_SET_COMPUTER_PLAYER_SUPPRESSION, "SET_COMPUTER_PLAYER_SUPPRESSION", Native_SET_COMPUTER_PLAYER_SUPPRESSION);
    RegisterNativeFunction(NATIVE_FORCE_COMPUTER_PLAYER_ACTION,  "FORCE_COMPUTER_PLAYER_ACTION",  Native_FORCE_COMPUTER_PLAYER_ACTION);
    RegisterNativeFunction(NATIVE_QUEUE_COMPUTER_PLAYER_ACTION,  "QUEUE_COMPUTER_PLAYER_ACTION",  Native_QUEUE_COMPUTER_PLAYER_ACTION);
    RegisterNativeFunction(NATIVE_GET_TOWN_WITH_ID,              "GET_TOWN_WITH_ID",              Native_GET_TOWN_WITH_ID);
    RegisterNativeFunction(NATIVE_SET_DISCIPLE,                  "SET_DISCIPLE",                  Native_SET_DISCIPLE);
    RegisterNativeFunction(NATIVE_RELEASE_COMPUTER_PLAYER,       "RELEASE_COMPUTER_PLAYER",       Native_RELEASE_COMPUTER_PLAYER);
    RegisterNativeFunction(NATIVE_SET_COMPUTER_PLAYER_SPEED,     "SET_COMPUTER_PLAYER_SPEED",     Native_SET_COMPUTER_PLAYER_SPEED);
    RegisterNativeFunction(NATIVE_SET_FOCUS_FOLLOW_COMPUTER_PLAYER, "SET_FOCUS_FOLLOW_COMPUTER_PLAYER", Native_SET_FOCUS_FOLLOW_COMPUTER_PLAYER);
    RegisterNativeFunction(NATIVE_SET_POSITION_FOLLOW_COMPUTER_PLAYER, "SET_POSITION_FOLLOW_COMPUTER_PLAYER", Native_SET_POSITION_FOLLOW_COMPUTER_PLAYER);
    RegisterNativeFunction(NATIVE_CALL_COMPUTER_PLAYER,          "CALL_COMPUTER_PLAYER",          Native_CALL_COMPUTER_PLAYER);
    RegisterNativeFunction(NATIVE_CALL_BUILDING_IN_TOWN,         "CALL_BUILDING_IN_TOWN",         Native_CALL_BUILDING_IN_TOWN);
    RegisterNativeFunction(NATIVE_SET_CAN_BUILD_WORSHIPSITE,     "SET_CAN_BUILD_WORSHIPSITE",     Native_SET_CAN_BUILD_WORSHIPSITE);
    RegisterNativeFunction(NATIVE_GET_FACING_CAMERA_POSITION,    "GET_FACING_CAMERA_POSITION",    Native_GET_FACING_CAMERA_POSITION);
    RegisterNativeFunction(NATIVE_SET_COMPUTER_PLAYER_ATTITUDE,  "SET_COMPUTER_PLAYER_ATTITUDE",  Native_SET_COMPUTER_PLAYER_ATTITUDE);
    RegisterNativeFunction(NATIVE_GET_COMPUTER_PLAYER_ATTITUDE,  "GET_COMPUTER_PLAYER_ATTITUDE",  Native_GET_COMPUTER_PLAYER_ATTITUDE);
    RegisterNativeFunction(NATIVE_LOAD_COMPUTER_PLAYER_PERSONALITY, "LOAD_COMPUTER_PLAYER_PERSONALITY", Native_LOAD_COMPUTER_PLAYER_PERSONALITY);
    RegisterNativeFunction(NATIVE_SAVE_COMPUTER_PLAYER_PERSONALITY, "SAVE_COMPUTER_PLAYER_PERSONALITY", Native_SAVE_COMPUTER_PLAYER_PERSONALITY);
    RegisterNativeFunction(NATIVE_SET_PLAYER_ALLY,               "SET_PLAYER_ALLY",               Native_SET_PLAYER_ALLY);
    RegisterNativeFunction(NATIVE_CALL_FLYING,                   "CALL_FLYING",                   Native_CALL_FLYING);
    RegisterNativeFunction(NATIVE_SET_OBJECT_FADE_IN,            "SET_OBJECT_FADE_IN",            Native_SET_OBJECT_FADE_IN);
    RegisterNativeFunction(NATIVE_IS_AFFECTED_BY_SPELL,          "IS_AFFECTED_BY_SPELL",          Native_IS_AFFECTED_BY_SPELL);
    RegisterNativeFunction(NATIVE_SET_MAGIC_IN_OBJECT,           "SET_MAGIC_IN_OBJECT",           Native_SET_MAGIC_IN_OBJECT);
    RegisterNativeFunction(NATIVE_ID_ADULT_SIZE,                 "ID_ADULT_SIZE",                 Native_ID_ADULT_SIZE);
    RegisterNativeFunction(NATIVE_OBJECT_CAPACITY,               "OBJECT_CAPACITY",               Native_OBJECT_CAPACITY);
    RegisterNativeFunction(NATIVE_OBJECT_ADULT_CAPACITY,         "OBJECT_ADULT_CAPACITY",         Native_OBJECT_ADULT_CAPACITY);
    RegisterNativeFunction(NATIVE_SET_CREATURE_AUTO_FIGHTING,    "SET_CREATURE_AUTO_FIGHTING",    Native_SET_CREATURE_AUTO_FIGHTING);
    RegisterNativeFunction(NATIVE_IS_AUTO_FIGHTING,              "IS_AUTO_FIGHTING",              Native_IS_AUTO_FIGHTING);
    RegisterNativeFunction(NATIVE_SET_CREATURE_QUEUE_FIGHT_MOVE, "SET_CREATURE_QUEUE_FIGHT_MOVE", Native_SET_CREATURE_QUEUE_FIGHT_MOVE);
    RegisterNativeFunction(NATIVE_SET_CREATURE_QUEUE_FIGHT_SPELL, "SET_CREATURE_QUEUE_FIGHT_SPELL", Native_SET_CREATURE_QUEUE_FIGHT_SPELL);
    RegisterNativeFunction(NATIVE_SET_CREATURE_QUEUE_FIGHT_STEP, "SET_CREATURE_QUEUE_FIGHT_STEP", Native_SET_CREATURE_QUEUE_FIGHT_STEP);
    RegisterNativeFunction(NATIVE_GET_CREATURE_FIGHT_ACTION,     "GET_CREATURE_FIGHT_ACTION",     Native_GET_CREATURE_FIGHT_ACTION);
    RegisterNativeFunction(NATIVE_CREATURE_FIGHT_QUEUE_HITS,     "CREATURE_FIGHT_QUEUE_HITS",     Native_CREATURE_FIGHT_QUEUE_HITS);
    RegisterNativeFunction(NATIVE_SQUARE_ROOT,                   "SQUARE_ROOT",                   Native_SQUARE_ROOT);
    RegisterNativeFunction(NATIVE_GET_PLAYER_ALLY,               "GET_PLAYER_ALLY",               Native_GET_PLAYER_ALLY);
    RegisterNativeFunction(NATIVE_SET_PLAYER_WIND_RESISTANCE,    "SET_PLAYER_WIND_RESISTANCE",    Native_SET_PLAYER_WIND_RESISTANCE);
    RegisterNativeFunction(NATIVE_GET_PLAYER_WIND_RESISTANCE,    "GET_PLAYER_WIND_RESISTANCE",    Native_GET_PLAYER_WIND_RESISTANCE);
    RegisterNativeFunction(NATIVE_PAUSE_UNPAUSE_CLIMATE_SYSTEM,  "PAUSE_UNPAUSE_CLIMATE_SYSTEM",  Native_PAUSE_UNPAUSE_CLIMATE_SYSTEM);
    RegisterNativeFunction(NATIVE_PAUSE_UNPAUSE_STORM_CREATION_IN_CLIMATE_SYSTEM, "PAUSE_UNPAUSE_STORM_CREATION_IN_CLIMATE_SYSTEM", Native_PAUSE_UNPAUSE_STORM_CREATION);
    RegisterNativeFunction(NATIVE_GET_MANA_FOR_SPELL,            "GET_MANA_FOR_SPELL",            Native_GET_MANA_FOR_SPELL);
    RegisterNativeFunction(NATIVE_KILL_STORMS_IN_AREA,           "KILL_STORMS_IN_AREA",           Native_KILL_STORMS_IN_AREA);
    RegisterNativeFunction(NATIVE_INSIDE_TEMPLE,                 "INSIDE_TEMPLE",                 Native_INSIDE_TEMPLE);
    RegisterNativeFunction(NATIVE_RESTART_OBJECT,                "RESTART_OBJECT",                Native_RESTART_OBJECT);
    RegisterNativeFunction(NATIVE_SET_GAME_TIME_PROPERTIES,      "SET_GAME_TIME_PROPERTIES",      Native_SET_GAME_TIME_PROPERTIES);
    RegisterNativeFunction(NATIVE_RESET_GAME_TIME_PROPERTIES,    "RESET_GAME_TIME_PROPERTIES",    Native_RESET_GAME_TIME_PROPERTIES);
    RegisterNativeFunction(NATIVE_SOUND_EXISTS,                  "SOUND_EXISTS",                  Native_SOUND_EXISTS);
    RegisterNativeFunction(NATIVE_GET_TOWN_WORSHIP_DEATHS,       "GET_TOWN_WORSHIP_DEATHS",       Native_GET_TOWN_WORSHIP_DEATHS);
    RegisterNativeFunction(NATIVE_GAME_CLEAR_DIALOGUE,           "GAME_CLEAR_DIALOGUE",           Native_GAME_CLEAR_DIALOGUE);
    RegisterNativeFunction(NATIVE_GAME_CLOSE_DIALOGUE,           "GAME_CLOSE_DIALOGUE",           Native_GAME_CLOSE_DIALOGUE);
    RegisterNativeFunction(NATIVE_GET_HAND_STATE,                "GET_HAND_STATE",                Native_GET_HAND_STATE);
    RegisterNativeFunction(NATIVE_SET_INTERFACE_CITADEL,         "SET_INTERFACE_CITADEL",         Native_SET_INTERFACE_CITADEL);
    RegisterNativeFunction(NATIVE_MAP_SCRIPT_FUNCTION,           "MAP_SCRIPT_FUNCTION",           Native_MAP_SCRIPT_FUNCTION);
    RegisterNativeFunction(NATIVE_WITHIN_ROTATION,               "WITHIN_ROTATION",               Native_WITHIN_ROTATION);
    RegisterNativeFunction(NATIVE_GET_PLAYER_TOWN_TOTAL,         "GET_PLAYER_TOWN_TOTAL",         Native_GET_PLAYER_TOWN_TOTAL);
    RegisterNativeFunction(NATIVE_SPIRIT_SCREEN_POINT,           "SPIRIT_SCREEN_POINT",           Native_SPIRIT_SCREEN_POINT);
    RegisterNativeFunction(NATIVE_KEY_DOWN,                      "KEY_DOWN",                      Native_KEY_DOWN);
    RegisterNativeFunction(NATIVE_SET_FIGHT_EXIT,                "SET_FIGHT_EXIT",                Native_SET_FIGHT_EXIT);
    RegisterNativeFunction(NATIVE_GET_OBJECT_CLICKED,            "GET_OBJECT_CLICKED",            Native_GET_OBJECT_CLICKED);
    RegisterNativeFunction(NATIVE_GET_MANA,                      "GET_MANA",                      Native_GET_MANA);
    RegisterNativeFunction(NATIVE_CLEAR_PLAYER_SPELL_CHARGING,   "CLEAR_PLAYER_SPELL_CHARGING",   Native_CLEAR_PLAYER_SPELL_CHARGING);
    RegisterNativeFunction(NATIVE_STOP_SOUND_EFFECT,             "STOP_SOUND_EFFECT",             Native_STOP_SOUND_EFFECT);
    RegisterNativeFunction(NATIVE_GET_TOTEM_STATUE,              "GET_TOTEM_STATUE",              Native_GET_TOTEM_STATUE);
    RegisterNativeFunction(NATIVE_SET_SET_ON_FIRE,               "SET_SET_ON_FIRE",               Native_SET_SET_ON_FIRE);
    RegisterNativeFunction(NATIVE_SET_LAND_BALANCE,              "SET_LAND_BALANCE",              Native_SET_LAND_BALANCE);
    RegisterNativeFunction(NATIVE_SET_OBJECT_BELIEF_SCALE,       "SET_OBJECT_BELIEF_SCALE",       Native_SET_OBJECT_BELIEF_SCALE);
    RegisterNativeFunction(NATIVE_START_IMMERSION,               "START_IMMERSION",               Native_START_IMMERSION);
    RegisterNativeFunction(NATIVE_STOP_IMMERSION,                "STOP_IMMERSION",                Native_STOP_IMMERSION);
    RegisterNativeFunction(NATIVE_STOP_ALL_IMMERSION,            "STOP_ALL_IMMERSION",            Native_STOP_ALL_IMMERSION);
    RegisterNativeFunction(NATIVE_SET_CREATURE_IN_TEMPLE,        "SET_CREATURE_IN_TEMPLE",        Native_SET_CREATURE_IN_TEMPLE);
    RegisterNativeFunction(NATIVE_GAME_DRAW_TEXT,                "GAME_DRAW_TEXT",                Native_GAME_DRAW_TEXT);
    RegisterNativeFunction(NATIVE_GAME_DRAW_TEMP_TEXT,           "GAME_DRAW_TEMP_TEXT",           Native_GAME_DRAW_TEMP_TEXT);
    RegisterNativeFunction(NATIVE_FADE_ALL_DRAW_TEXT,            "FADE_ALL_DRAW_TEXT",            Native_FADE_ALL_DRAW_TEXT);
    RegisterNativeFunction(NATIVE_SET_DRAW_TEXT_COLOUR,          "SET_DRAW_TEXT_COLOUR",          Native_SET_DRAW_TEXT_COLOUR);
    RegisterNativeFunction(NATIVE_SET_CLIPPING_WINDOW,           "SET_CLIPPING_WINDOW",           Native_SET_CLIPPING_WINDOW);
    RegisterNativeFunction(NATIVE_CLEAR_CLIPPING_WINDOW,         "CLEAR_CLIPPING_WINDOW",         Native_CLEAR_CLIPPING_WINDOW);
    RegisterNativeFunction(NATIVE_SAVE_GAME_IN_SLOT,             "SAVE_GAME_IN_SLOT",             Native_SAVE_GAME_IN_SLOT);
    RegisterNativeFunction(NATIVE_SET_OBJECT_CARRYING,           "SET_OBJECT_CARRYING",           Native_SET_OBJECT_CARRYING);
    RegisterNativeFunction(NATIVE_POS_VALID_FOR_CREATURE,        "POS_VALID_FOR_CREATURE",        Native_POS_VALID_FOR_CREATURE);
    RegisterNativeFunction(NATIVE_GET_TIME_SINCE_OBJECT_ATTACKED, "GET_TIME_SINCE_OBJECT_ATTACKED", Native_GET_TIME_SINCE_ATTACKED);
    RegisterNativeFunction(NATIVE_GET_TOWN_AND_VILLAGER_HEALTH_TOTAL, "GET_TOWN_AND_VILLAGER_HEALTH_TOTAL", Native_GET_TOWN_AND_VILLAGER_HEALTH);
    RegisterNativeFunction(NATIVE_GAME_ADD_FOR_BUILDING,         "GAME_ADD_FOR_BUILDING",         Native_GAME_ADD_FOR_BUILDING2);
    RegisterNativeFunction(NATIVE_ENABLE_DISABLE_ALIGNMENT_MUSIC, "ENABLE_DISABLE_ALIGNMENT_MUSIC", Native_ENABLE_DISABLE_ALIGNMENT_MUSIC);
    RegisterNativeFunction(NATIVE_GET_DEAD_LIVING,               "GET_DEAD_LIVING",               Native_GET_DEAD_LIVING);
    RegisterNativeFunction(NATIVE_ATTACH_SOUND_TAG,              "ATTACH_SOUND_TAG",              Native_ATTACH_SOUND_TAG);
    RegisterNativeFunction(NATIVE_DETACH_SOUND_TAG,              "DETACH_SOUND_TAG",              Native_DETACH_SOUND_TAG);
    RegisterNativeFunction(NATIVE_GET_SACRIFICE_TOTAL,           "GET_SACRIFICE_TOTAL",           Native_GET_SACRIFICE_TOTAL2);
    RegisterNativeFunction(NATIVE_GAME_SOUND_PLAYING,            "GAME_SOUND_PLAYING",            Native_GAME_SOUND_PLAYING);
    RegisterNativeFunction(NATIVE_GET_TEMPLE_POSITION,           "GET_TEMPLE_POSITION",           Native_GET_TEMPLE_POSITION);
    RegisterNativeFunction(NATIVE_CREATURE_AUTOSCALE,            "CREATURE_AUTOSCALE",            Native_CREATURE_AUTOSCALE);
    RegisterNativeFunction(NATIVE_GET_SPELL_ICON_IN_TEMPLE,      "GET_SPELL_ICON_IN_TEMPLE",      Native_GET_SPELL_ICON_IN_TEMPLE);
    RegisterNativeFunction(NATIVE_GAME_CLEAR_COMPUTER_PLAYER_ACTIONS, "GAME_CLEAR_COMPUTER_PLAYER_ACTIONS", Native_GAME_CLEAR_COMPUTER_PLAYER_ACTIONS);
    RegisterNativeFunction(NATIVE_GET_FIRST_IN_CONTAINER,        "GET_FIRST_IN_CONTAINER",        Native_GET_FIRST_IN_CONTAINER);
    RegisterNativeFunction(NATIVE_GET_NEXT_IN_CONTAINER,         "GET_NEXT_IN_CONTAINER",         Native_GET_NEXT_IN_CONTAINER);
    RegisterNativeFunction(NATIVE_GET_TEMPLE_ENTRANCE_POSITION,  "GET_TEMPLE_ENTRANCE_POSITION",  Native_GET_TEMPLE_ENTRANCE_POSITION);
    RegisterNativeFunction(NATIVE_SAY_SOUND_EFFECT_PLAYING,      "SAY_SOUND_EFFECT_PLAYING",      Native_SAY_SOUND_EFFECT_PLAYING);
    RegisterNativeFunction(NATIVE_SET_HAND_DEMO_KEYS,            "SET_HAND_DEMO_KEYS",            Native_SET_HAND_DEMO_KEYS);
    RegisterNativeFunction(NATIVE_CAN_SKIP_TUTORIAL,             "CAN_SKIP_TUTORIAL",             Native_CAN_SKIP_TUTORIAL);
    RegisterNativeFunction(NATIVE_CAN_SKIP_CREATURE_TRAINING,    "CAN_SKIP_CREATURE_TRAINING",    Native_CAN_SKIP_CREATURE_TRAINING);
    RegisterNativeFunction(NATIVE_IS_KEEPING_OLD_CREATURE,       "IS_KEEPING_OLD_CREATURE",       Native_IS_KEEPING_OLD_CREATURE);
    RegisterNativeFunction(NATIVE_CURRENT_PROFILE_HAS_CREATURE,  "CURRENT_PROFILE_HAS_CREATURE",  Native_CURRENT_PROFILE_HAS_CREATURE);
}

// ============================================================================
// CHL file loading
// ============================================================================

bool LHVM::LoadBinary(const char* path) {
    FILE* f = fopen(path, "rb");
    if (!f) return false;

    // Read header
    CHLHeader header;
    if (fread(&header, sizeof(header), 1, f) != 1) {
        fclose(f);
        return false;
    }
    if (memcmp(header.magic, "LHVM", 4) != 0) {
        fclose(f);
        return false;
    }

    // Read global variables section
    fread(&global_var_count, sizeof(uint32_t), 1, f);
    global_vars = static_cast<float*>(calloc(global_var_count, sizeof(float)));
    // Skip variable name strings (null-terminated, read until all consumed)
    for (uint32_t i = 0; i < global_var_count; i++) {
        char c;
        do { fread(&c, 1, 1, f); } while (c != '\0');
    }

    // Read code section
    fread(&instruction_count, sizeof(uint32_t), 1, f);
    instructions = static_cast<VMInstruction*>(
        calloc(instruction_count, sizeof(VMInstruction)));
    fread(instructions, sizeof(VMInstruction), instruction_count, f);

    // Read auto-start section
    fread(&auto_start_count, sizeof(uint32_t), 1, f);
    auto_start_scripts = static_cast<uint32_t*>(
        calloc(auto_start_count, sizeof(uint32_t)));
    fread(auto_start_scripts, sizeof(uint32_t), auto_start_count, f);

    // Read scripts section
    fread(&script_count, sizeof(uint32_t), 1, f);
    scripts = static_cast<VMScript*>(calloc(script_count, sizeof(VMScript)));
    for (uint32_t i = 0; i < script_count; i++) {
        // Read null-terminated script name
        uint32_t j = 0;
        char c;
        do {
            fread(&c, 1, 1, f);
            if (j < 255) scripts[i].name[j++] = c;
        } while (c != '\0');
        scripts[i].name[255] = '\0';

        // Read null-terminated source filename
        j = 0;
        do {
            fread(&c, 1, 1, f);
            if (j < 255) scripts[i].filename[j++] = c;
        } while (c != '\0');
        scripts[i].filename[255] = '\0';

        // Read script metadata
        fread(&scripts[i].script_type, sizeof(uint32_t), 1, f);
        fread(&scripts[i].global_count, sizeof(uint32_t), 1, f);
        // Variable names for this script (skip)
        for (uint32_t v = 0; v < scripts[i].global_count; v++) {
            do { fread(&c, 1, 1, f); } while (c != '\0');
        }
        fread(&scripts[i].instruction_addr, sizeof(uint32_t), 1, f);
        fread(&scripts[i].param_count, sizeof(uint32_t), 1, f);
        fread(&scripts[i].script_id, sizeof(uint32_t), 1, f);
    }

    // Read data section (string constants)
    fread(&data_size, sizeof(uint32_t), 1, f);
    data_section = static_cast<char*>(calloc(data_size + 1, 1));
    if (data_size > 0) {
        fread(data_section, 1, data_size, f);
    }

    fclose(f);

    // Initialize runtime
    first_task = nullptr;
    last_task = nullptr;
    next_task_id = 1;
    tick_count = 0;
    current_task = nullptr;

    // Initialize native function dispatch table
    InitNativeFunctions();

    return true;
}

void LHVM::FreeBinary() {
    StopAllTasks();
    free(instructions); instructions = nullptr; instruction_count = 0;
    free(scripts);      scripts = nullptr;      script_count = 0;
    free(data_section); data_section = nullptr;  data_size = 0;
    free(global_vars);  global_vars = nullptr;   global_var_count = 0;
    free(auto_start_scripts); auto_start_scripts = nullptr; auto_start_count = 0;
}

// ============================================================================
// Task management
// ============================================================================

VMTask* LHVM::CreateTask(uint32_t script_id) {
    if (script_id >= script_count) return nullptr;

    VMTask* task = static_cast<VMTask*>(calloc(1, sizeof(VMTask)));
    task->task_id = next_task_id++;
    task->script_id = script_id;
    task->ip = scripts[script_id].instruction_addr;
    task->wait_ticks = 0;
    task->sleep_seconds = 0.0f;
    task->waiting = false;
    task->sleeping = false;
    task->finished = false;
    task->stack_top = 0;
    task->local_var_count = scripts[script_id].global_count;
    task->local_vars = static_cast<float*>(
        calloc(task->local_var_count, sizeof(float)));
    task->exception_handler_ip = 0;

    // Add to linked list
    task->prev = last_task;
    task->next = nullptr;
    if (last_task) last_task->next = task;
    else first_task = task;
    last_task = task;

    return task;
}

void LHVM::DestroyTask(VMTask* task) {
    // Unlink from list
    if (task->prev) task->prev->next = task->next;
    else first_task = task->next;
    if (task->next) task->next->prev = task->prev;
    else last_task = task->prev;

    free(task->local_vars);
    free(task);
}

uint32_t LHVM::StartScript(const char* name) {
    for (uint32_t i = 0; i < script_count; i++) {
        if (strcmp(scripts[i].name, name) == 0) {
            VMTask* task = CreateTask(i);
            return task ? task->task_id : 0;
        }
    }
    return 0;
}

uint32_t LHVM::StartScriptByID(uint32_t script_id) {
    VMTask* task = CreateTask(script_id);
    return task ? task->task_id : 0;
}

void LHVM::StopTask(uint32_t task_id) {
    VMTask* task = first_task;
    while (task) {
        if (task->task_id == task_id) {
            task->finished = true;
            return;
        }
        task = task->next;
    }
}

void LHVM::StopAllTasks() {
    VMTask* task = first_task;
    while (task) {
        VMTask* next = task->next;
        free(task->local_vars);
        free(task);
        task = next;
    }
    first_task = nullptr;
    last_task = nullptr;
}

// ============================================================================
// Stack operations — operate on current_task's stack
// ============================================================================

void LHVM::PushInt(int32_t value) {
    if (!current_task || current_task->stack_top >= 256) return;
    current_task->stack[current_task->stack_top].type = VM_TYPE_INT;
    current_task->stack[current_task->stack_top].int_val = value;
    current_task->stack_top++;
}

void LHVM::PushFloat(float value) {
    if (!current_task || current_task->stack_top >= 256) return;
    current_task->stack[current_task->stack_top].type = VM_TYPE_FLOAT;
    current_task->stack[current_task->stack_top].float_val = value;
    current_task->stack_top++;
}

void LHVM::PushObject(uint32_t object_id) {
    if (!current_task || current_task->stack_top >= 256) return;
    current_task->stack[current_task->stack_top].type = VM_TYPE_OBJECT;
    current_task->stack[current_task->stack_top].uint_val = object_id;
    current_task->stack_top++;
}

void LHVM::PushBoolean(bool value) {
    if (!current_task || current_task->stack_top >= 256) return;
    current_task->stack[current_task->stack_top].type = VM_TYPE_BOOLEAN;
    current_task->stack[current_task->stack_top].int_val = value ? 1 : 0;
    current_task->stack_top++;
}

int32_t LHVM::PopInt() {
    if (!current_task || current_task->stack_top == 0) return 0;
    current_task->stack_top--;
    return current_task->stack[current_task->stack_top].int_val;
}

float LHVM::PopFloat() {
    if (!current_task || current_task->stack_top == 0) return 0.0f;
    current_task->stack_top--;
    return current_task->stack[current_task->stack_top].float_val;
}

uint32_t LHVM::PopObject() {
    if (!current_task || current_task->stack_top == 0) return 0;
    current_task->stack_top--;
    return current_task->stack[current_task->stack_top].uint_val;
}

bool LHVM::PopBoolean() {
    if (!current_task || current_task->stack_top == 0) return false;
    current_task->stack_top--;
    return current_task->stack[current_task->stack_top].int_val != 0;
}

VMStackValue LHVM::PopValue() {
    VMStackValue val = {};
    if (!current_task || current_task->stack_top == 0) return val;
    current_task->stack_top--;
    return current_task->stack[current_task->stack_top];
}

const char* LHVM::GetString(uint32_t offset) {
    if (offset < data_size) return &data_section[offset];
    return "";
}

// ============================================================================
// Instruction execution
// ============================================================================

void LHVM::ExecuteTask(VMTask* task) {
    if (task->finished) return;

    // Handle wait state
    if (task->waiting) {
        if (task->wait_ticks > 0) {
            task->wait_ticks--;
            return;
        }
        task->waiting = false;
    }

    // Set current task for native function callbacks
    current_task = task;

    // Execute instructions (up to 1000 per tick to prevent infinite loops)
    for (int steps = 0; steps < 1000; steps++) {
        if (task->ip >= instruction_count) {
            task->finished = true;
            current_task = nullptr;
            return;
        }

        VMInstruction& inst = instructions[task->ip];
        task->ip++;

        switch (inst.opcode) {
        case OP_END:
            task->finished = true;
            current_task = nullptr;
            return;

        case OP_WAIT:
            task->wait_ticks = static_cast<uint32_t>(
                task->stack_top > 0 ? task->stack[--task->stack_top].int_val : 1);
            task->waiting = true;
            current_task = nullptr;
            return;

        case OP_PUSH:
            if (task->stack_top < 256) {
                if (inst.mode == 1) {
                    // Push local variable
                    if (inst.uint_val < task->local_var_count) {
                        task->stack[task->stack_top].type = inst.data_type;
                        task->stack[task->stack_top].float_val = task->local_vars[inst.uint_val];
                    }
                } else if (inst.mode == 2) {
                    // Push global variable
                    if (inst.uint_val < global_var_count) {
                        task->stack[task->stack_top].type = inst.data_type;
                        task->stack[task->stack_top].float_val = global_vars[inst.uint_val];
                    }
                } else {
                    // Push immediate
                    task->stack[task->stack_top].type = inst.data_type;
                    task->stack[task->stack_top].int_val = inst.int_val;
                }
                task->stack_top++;
            }
            break;

        case OP_POP:
            if (task->stack_top > 0) {
                task->stack_top--;
                if (inst.mode == 1 && inst.uint_val < task->local_var_count) {
                    task->local_vars[inst.uint_val] = task->stack[task->stack_top].float_val;
                } else if (inst.mode == 2 && inst.uint_val < global_var_count) {
                    global_vars[inst.uint_val] = task->stack[task->stack_top].float_val;
                }
            }
            break;

        case OP_ADD:
            if (task->stack_top >= 2) {
                task->stack_top--;
                task->stack[task->stack_top - 1].float_val += task->stack[task->stack_top].float_val;
            }
            break;

        case OP_MINUS:
            if (task->stack_top >= 2) {
                task->stack_top--;
                task->stack[task->stack_top - 1].float_val -= task->stack[task->stack_top].float_val;
            }
            break;

        case OP_TIMES:
            if (task->stack_top >= 2) {
                task->stack_top--;
                task->stack[task->stack_top - 1].float_val *= task->stack[task->stack_top].float_val;
            }
            break;

        case OP_DIVIDE:
            if (task->stack_top >= 2) {
                task->stack_top--;
                float divisor = task->stack[task->stack_top].float_val;
                if (divisor != 0.0f)
                    task->stack[task->stack_top - 1].float_val /= divisor;
            }
            break;

        case OP_NOT:
            if (task->stack_top > 0) {
                task->stack[task->stack_top - 1].int_val =
                    task->stack[task->stack_top - 1].int_val == 0 ? 1 : 0;
            }
            break;

        case OP_AND:
            if (task->stack_top >= 2) {
                task->stack_top--;
                task->stack[task->stack_top - 1].int_val =
                    (task->stack[task->stack_top - 1].int_val && task->stack[task->stack_top].int_val) ? 1 : 0;
            }
            break;

        case OP_OR:
            if (task->stack_top >= 2) {
                task->stack_top--;
                task->stack[task->stack_top - 1].int_val =
                    (task->stack[task->stack_top - 1].int_val || task->stack[task->stack_top].int_val) ? 1 : 0;
            }
            break;

        case OP_EQ:
            if (task->stack_top >= 2) {
                task->stack_top--;
                task->stack[task->stack_top - 1].int_val =
                    (task->stack[task->stack_top - 1].float_val == task->stack[task->stack_top].float_val) ? 1 : 0;
            }
            break;

        case OP_NEQ:
            if (task->stack_top >= 2) {
                task->stack_top--;
                task->stack[task->stack_top - 1].int_val =
                    (task->stack[task->stack_top - 1].float_val != task->stack[task->stack_top].float_val) ? 1 : 0;
            }
            break;

        case OP_GT:
            if (task->stack_top >= 2) {
                task->stack_top--;
                task->stack[task->stack_top - 1].int_val =
                    (task->stack[task->stack_top - 1].float_val > task->stack[task->stack_top].float_val) ? 1 : 0;
            }
            break;

        case OP_LT:
            if (task->stack_top >= 2) {
                task->stack_top--;
                task->stack[task->stack_top - 1].int_val =
                    (task->stack[task->stack_top - 1].float_val < task->stack[task->stack_top].float_val) ? 1 : 0;
            }
            break;

        case OP_GEQ:
            if (task->stack_top >= 2) {
                task->stack_top--;
                task->stack[task->stack_top - 1].int_val =
                    (task->stack[task->stack_top - 1].float_val >= task->stack[task->stack_top].float_val) ? 1 : 0;
            }
            break;

        case OP_LEQ:
            if (task->stack_top >= 2) {
                task->stack_top--;
                task->stack[task->stack_top - 1].int_val =
                    (task->stack[task->stack_top - 1].float_val <= task->stack[task->stack_top].float_val) ? 1 : 0;
            }
            break;

        case OP_JUMP:
            // Conditional jump if top of stack is nonzero (or unconditional if mode == 0)
            if (inst.mode == 0) {
                task->ip = inst.uint_val;
            } else if (task->stack_top > 0) {
                task->stack_top--;
                if (task->stack[task->stack_top].int_val != 0) {
                    task->ip = inst.uint_val;
                }
            }
            break;

        case OP_CALL:
            // Native function dispatch — inst.uint_val is the function index
            if (inst.uint_val < _NATIVE_FUNCTION_COUNT && native_functions[inst.uint_val].func) {
                native_functions[inst.uint_val].func(this);
            }
            break;

        case OP_SLEEP:
            if (task->stack_top > 0) {
                task->stack_top--;
                task->sleep_seconds = task->stack[task->stack_top].float_val;
            }
            task->sleeping = true;
            current_task = nullptr;
            return;

        case OP_UMINUS:
            if (task->stack_top > 0) {
                task->stack[task->stack_top - 1].float_val =
                    -task->stack[task->stack_top - 1].float_val;
            }
            break;

        case OP_MODULUS:
            if (task->stack_top >= 2) {
                task->stack_top--;
                int32_t divisor = task->stack[task->stack_top].int_val;
                if (divisor != 0)
                    task->stack[task->stack_top - 1].int_val %= divisor;
            }
            break;

        case OP_SWAP:
            if (task->stack_top >= 2) {
                VMStackValue tmp = task->stack[task->stack_top - 1];
                task->stack[task->stack_top - 1] = task->stack[task->stack_top - 2];
                task->stack[task->stack_top - 2] = tmp;
            }
            break;

        case OP_LINE:
            // Debug info — no runtime effect
            break;

        case OP_RUN:
            // Start another script
            if (task->stack_top > 0) {
                task->stack_top--;
                StartScriptByID(static_cast<uint32_t>(task->stack[task->stack_top].int_val));
            }
            break;

        case OP_EXCEPT:
            task->exception_handler_ip = inst.uint_val;
            break;

        case OP_ENDEXCEPT:
        case OP_RETEXCEPT:
        case OP_FAILEXCEPT:
        case OP_BRKEXCEPT:
            // Exception handling — simplified for now
            break;

        case OP_CAST:
            // Type conversion — simplified (float<->int)
            if (task->stack_top > 0) {
                VMStackValue& top = task->stack[task->stack_top - 1];
                if (inst.data_type == VM_TYPE_FLOAT && top.type == VM_TYPE_INT) {
                    float f = static_cast<float>(top.int_val);
                    top.float_val = f;
                    top.type = VM_TYPE_FLOAT;
                } else if (inst.data_type == VM_TYPE_INT && top.type == VM_TYPE_FLOAT) {
                    int32_t i = static_cast<int32_t>(top.float_val);
                    top.int_val = i;
                    top.type = VM_TYPE_INT;
                }
                top.type = inst.data_type;
            }
            break;

        default:
            // Unknown opcode
            break;
        }
    }

    current_task = nullptr;
}

void LHVM::ProcessTick() {
    tick_count++;

    // Execute each task
    VMTask* task = first_task;
    while (task) {
        VMTask* next = task->next;  // save in case task is destroyed

        if (!task->finished) {
            ExecuteTask(task);
        }

        // Clean up finished tasks
        if (task->finished) {
            DestroyTask(task);
        }

        task = next;
    }
}
