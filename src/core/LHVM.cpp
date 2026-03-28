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
    // TODO: set camera position
}

static void Native_SET_CAMERA_FOCUS(LHVM* vm) {
    vm->PopFloat(); // x
    vm->PopFloat(); // y
    vm->PopFloat(); // z
    // TODO: set camera focus
}

static void Native_MOVE_CAMERA_POSITION(LHVM* vm) {
    vm->PopFloat(); // x
    vm->PopFloat(); // y
    vm->PopFloat(); // z
    vm->PopFloat(); // time
    // TODO: move camera position
}

static void Native_MOVE_CAMERA_FOCUS(LHVM* vm) {
    vm->PopFloat(); // x
    vm->PopFloat(); // y
    vm->PopFloat(); // z
    vm->PopFloat(); // time
    // TODO: move camera focus
}

static void Native_GET_CAMERA_POSITION(LHVM* vm) {
    // TODO: get actual camera position
    vm->PushFloat(0.0f); // x
    vm->PushFloat(0.0f); // y
    vm->PushFloat(0.0f); // z
}

static void Native_GET_CAMERA_FOCUS(LHVM* vm) {
    // TODO: get actual camera focus
    vm->PushFloat(0.0f); // x
    vm->PushFloat(0.0f); // y
    vm->PushFloat(0.0f); // z
}

static void Native_HAS_CAMERA_ARRIVED(LHVM* vm) {
    vm->PushBoolean(true); // camera always "arrived" for now
}

static void Native_START_CAMERA_CONTROL(LHVM* /*vm*/) {
    // TODO: lock camera control to script
}

static void Native_END_CAMERA_CONTROL(LHVM* /*vm*/) {
    // TODO: release camera control
}

// --- Property functions ---
static void Native_GET_PROPERTY(LHVM* vm) {
    vm->PopInt();    // property type
    vm->PopObject(); // object
    // TODO: get actual property value
    vm->PushFloat(0.0f);
}

static void Native_SET_PROPERTY(LHVM* vm) {
    vm->PopFloat();  // value
    vm->PopInt();    // property type
    vm->PopObject(); // object
    // TODO: set property
}

static void Native_GET_POSITION(LHVM* vm) {
    vm->PopObject(); // object
    // TODO: get actual object position
    vm->PushFloat(0.0f); // x
    vm->PushFloat(0.0f); // y
    vm->PushFloat(0.0f); // z
}

static void Native_SET_POSITION(LHVM* vm) {
    vm->PopFloat();  // z
    vm->PopFloat();  // y
    vm->PopFloat();  // x
    vm->PopObject(); // object
    // TODO: set object position
}

static void Native_GET_DISTANCE(LHVM* vm) {
    vm->PopFloat(); // z2
    vm->PopFloat(); // y2
    vm->PopFloat(); // x2
    vm->PopFloat(); // z1
    vm->PopFloat(); // y1
    vm->PopFloat(); // x1
    // TODO: compute actual distance
    vm->PushFloat(0.0f);
}

// --- Object functions ---
static void Native_CREATE(LHVM* vm) {
    vm->PopFloat(); // z
    vm->PopFloat(); // y
    vm->PopFloat(); // x
    vm->PopInt();   // subtype
    vm->PopInt();   // type
    // TODO: create game object
    vm->PushObject(0);
}

static void Native_OBJECT_DELETE(LHVM* vm) {
    vm->PopObject(); // object to delete
    // TODO: delete game object
}

static void Native_THING_VALID(LHVM* vm) {
    vm->PopObject(); // object
    // TODO: check if object is valid
    vm->PushBoolean(false);
}

static void Native_IS_OF_TYPE(LHVM* vm) {
    vm->PopInt();    // subtype
    vm->PopInt();    // type
    vm->PopObject(); // object
    // TODO: check object type
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
    vm->PushFloat(0.0f); // TODO: return game time
}

static void Native_GET_GAME_TIME(LHVM* vm) {
    vm->PushFloat(0.0f); // TODO: return game time
}

static void Native_SET_GAME_TIME(LHVM* vm) {
    vm->PopFloat(); // time
    // TODO: set game time
}

// --- Script control ---
static void Native_STOP_SCRIPT(LHVM* vm) {
    vm->PopInt(); // script name (string offset)
    // TODO: stop named script
}

static void Native_STOP_ALL_SCRIPTS_EXCLUDING(LHVM* vm) {
    vm->PopInt(); // script name (string offset)
    // TODO: stop all scripts except named
}

// --- Text/dialogue ---
static void Native_RUN_TEXT(LHVM* vm) {
    vm->PopInt(); // string ID
    vm->PopInt(); // duration or flags
    // TODO: display text
    vm->PushBoolean(true);
}

static void Native_TEMP_TEXT(LHVM* vm) {
    vm->PopInt(); // string ID
    vm->PopInt(); // duration
    // TODO: display temp text
}

static void Native_TEXT_READ(LHVM* vm) {
    vm->PushBoolean(true); // text always "read"
}

static void Native_START_DIALOGUE(LHVM* /*vm*/) {
    // TODO: start dialogue mode
}

static void Native_END_DIALOGUE(LHVM* /*vm*/) {
    // TODO: end dialogue mode
}

static void Native_IS_DIALOGUE_READY(LHVM* vm) {
    vm->PushBoolean(true);
}

// --- Widescreen ---
static void Native_SET_WIDESCREEN(LHVM* vm) {
    vm->PopBoolean(); // enable
    // TODO: set widescreen mode
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
    vm->PopFloat(); // speed
    // TODO: set game speed
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
    // TODO: play sound
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
    vm->PopObject();
    vm->PushBoolean(true);
}

// --- Map ---
static void Native_LOAD_MAP(LHVM* vm) {
    vm->PopInt(); // map string offset
    // TODO: load map
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
    // TODO: clear click state
}

static void Native_CLEAR_CLICKED_POSITION(LHVM* /*vm*/) {
    // TODO: clear position click state
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
    RegisterNativeFunction(NATIVE_SPIRIT_EJECT,                  "SPIRIT_EJECT",                  NativeStub);
    RegisterNativeFunction(NATIVE_SPIRIT_HOME,                   "SPIRIT_HOME",                   NativeStub);
    RegisterNativeFunction(NATIVE_SPIRIT_POINT_POS,              "SPIRIT_POINT_POS",              NativeStub);
    RegisterNativeFunction(NATIVE_SPIRIT_POINT_GAME_THING,       "SPIRIT_POINT_GAME_THING",       NativeStub);
    RegisterNativeFunction(NATIVE_GAME_THING_FIELD_OF_VIEW,      "GAME_THING_FIELD_OF_VIEW",      NativeStub);
    RegisterNativeFunction(NATIVE_POS_FIELD_OF_VIEW,             "POS_FIELD_OF_VIEW",             NativeStub);
    RegisterNativeFunction(NATIVE_RUN_TEXT,                       "RUN_TEXT",                       Native_RUN_TEXT);
    RegisterNativeFunction(NATIVE_TEMP_TEXT,                      "TEMP_TEXT",                      Native_TEMP_TEXT);
    RegisterNativeFunction(NATIVE_TEXT_READ,                      "TEXT_READ",                      Native_TEXT_READ);
    RegisterNativeFunction(NATIVE_GAME_THING_CLICKED,            "GAME_THING_CLICKED",            Native_GAME_THING_CLICKED);
    RegisterNativeFunction(NATIVE_SET_SCRIPT_STATE,              "SET_SCRIPT_STATE",              NativeStub);
    RegisterNativeFunction(NATIVE_SET_SCRIPT_STATE_POS,          "SET_SCRIPT_STATE_POS",          NativeStub);
    RegisterNativeFunction(NATIVE_SET_SCRIPT_FLOAT,              "SET_SCRIPT_FLOAT",              NativeStub);
    RegisterNativeFunction(NATIVE_SET_SCRIPT_ULONG,              "SET_SCRIPT_ULONG",              NativeStub);
    RegisterNativeFunction(NATIVE_GET_PROPERTY,                  "GET_PROPERTY",                  Native_GET_PROPERTY);
    RegisterNativeFunction(NATIVE_SET_PROPERTY,                  "SET_PROPERTY",                  Native_SET_PROPERTY);
    RegisterNativeFunction(NATIVE_GET_POSITION,                  "GET_POSITION",                  Native_GET_POSITION);
    RegisterNativeFunction(NATIVE_SET_POSITION,                  "SET_POSITION",                  Native_SET_POSITION);
    RegisterNativeFunction(NATIVE_GET_DISTANCE,                  "GET_DISTANCE",                  Native_GET_DISTANCE);
    RegisterNativeFunction(NATIVE_CALL,                          "CALL",                          NativeStub);
    RegisterNativeFunction(NATIVE_CREATE,                        "CREATE",                        Native_CREATE);
    RegisterNativeFunction(NATIVE_RANDOM,                        "RANDOM",                        Native_RANDOM);
    RegisterNativeFunction(NATIVE_DLL_GETTIME,                   "DLL_GETTIME",                   Native_DLL_GETTIME);
    RegisterNativeFunction(NATIVE_START_CAMERA_CONTROL,          "START_CAMERA_CONTROL",          Native_START_CAMERA_CONTROL);
    RegisterNativeFunction(NATIVE_END_CAMERA_CONTROL,            "END_CAMERA_CONTROL",            Native_END_CAMERA_CONTROL);
    RegisterNativeFunction(NATIVE_SET_WIDESCREEN,                "SET_WIDESCREEN",                Native_SET_WIDESCREEN);
    RegisterNativeFunction(NATIVE_MOVE_GAME_THING,               "MOVE_GAME_THING",               NativeStub);
    RegisterNativeFunction(NATIVE_SET_FOCUS,                     "SET_FOCUS",                     NativeStub);
    RegisterNativeFunction(NATIVE_HAS_CAMERA_ARRIVED,            "HAS_CAMERA_ARRIVED",            Native_HAS_CAMERA_ARRIVED);
    RegisterNativeFunction(NATIVE_FLOCK_CREATE,                  "FLOCK_CREATE",                  NativeStub);
    RegisterNativeFunction(NATIVE_FLOCK_ATTACH,                  "FLOCK_ATTACH",                  NativeStub);
    RegisterNativeFunction(NATIVE_FLOCK_DETACH,                  "FLOCK_DETACH",                  NativeStub);
    RegisterNativeFunction(NATIVE_FLOCK_DISBAND,                 "FLOCK_DISBAND",                 NativeStub);
    RegisterNativeFunction(NATIVE_ID_SIZE,                       "ID_SIZE",                       NativeStub);
    RegisterNativeFunction(NATIVE_FLOCK_MEMBER,                  "FLOCK_MEMBER",                  NativeStub);
    RegisterNativeFunction(NATIVE_GET_HAND_POSITION,             "GET_HAND_POSITION",             Native_GET_HAND_POSITION);
    RegisterNativeFunction(NATIVE_PLAY_SOUND_EFFECT,             "PLAY_SOUND_EFFECT",             Native_PLAY_SOUND_EFFECT);
    RegisterNativeFunction(NATIVE_START_MUSIC,                   "START_MUSIC",                   NativeStub);
    RegisterNativeFunction(NATIVE_STOP_MUSIC,                    "STOP_MUSIC",                    NativeStub);
    RegisterNativeFunction(NATIVE_ATTACH_MUSIC,                  "ATTACH_MUSIC",                  NativeStub);
    RegisterNativeFunction(NATIVE_DETACH_MUSIC,                  "DETACH_MUSIC",                  NativeStub);
    RegisterNativeFunction(NATIVE_OBJECT_DELETE,                 "OBJECT_DELETE",                 Native_OBJECT_DELETE);
    RegisterNativeFunction(NATIVE_FOCUS_FOLLOW,                  "FOCUS_FOLLOW",                  NativeStub);
    RegisterNativeFunction(NATIVE_POSITION_FOLLOW,               "POSITION_FOLLOW",               NativeStub);
    RegisterNativeFunction(NATIVE_CALL_NEAR,                     "CALL_NEAR",                     NativeStub);
    RegisterNativeFunction(NATIVE_SPECIAL_EFFECT_POSITION,       "SPECIAL_EFFECT_POSITION",       NativeStub);
    RegisterNativeFunction(NATIVE_SPECIAL_EFFECT_OBJECT,         "SPECIAL_EFFECT_OBJECT",         NativeStub);
    RegisterNativeFunction(NATIVE_DANCE_CREATE,                  "DANCE_CREATE",                  NativeStub);
    RegisterNativeFunction(NATIVE_CALL_IN,                       "CALL_IN",                       NativeStub);
    RegisterNativeFunction(NATIVE_CHANGE_INNER_OUTER_PROPERTIES, "CHANGE_INNER_OUTER_PROPERTIES", NativeStub);
    RegisterNativeFunction(NATIVE_SNAPSHOT,                      "SNAPSHOT",                      NativeStub);
    RegisterNativeFunction(NATIVE_GET_ALIGNMENT,                 "GET_ALIGNMENT",                 Native_GET_ALIGNMENT);
    RegisterNativeFunction(NATIVE_SET_ALIGNMENT,                 "SET_ALIGNMENT",                 Native_SET_ALIGNMENT);
    RegisterNativeFunction(NATIVE_INFLUENCE_OBJECT,              "INFLUENCE_OBJECT",              NativeStub);
    RegisterNativeFunction(NATIVE_INFLUENCE_POSITION,            "INFLUENCE_POSITION",            NativeStub);
    RegisterNativeFunction(NATIVE_GET_INFLUENCE,                 "GET_INFLUENCE",                 Native_GET_INFLUENCE);
    RegisterNativeFunction(NATIVE_SET_INTERFACE_INTERACTION,      "SET_INTERFACE_INTERACTION",      NativeStub);
    RegisterNativeFunction(NATIVE_PLAYED,                        "PLAYED",                        NativeStub);
    RegisterNativeFunction(NATIVE_RANDOM_ULONG,                  "RANDOM_ULONG",                  Native_RANDOM_ULONG);
    RegisterNativeFunction(NATIVE_SET_GAMESPEED,                 "SET_GAMESPEED",                 Native_SET_GAMESPEED);
    RegisterNativeFunction(NATIVE_CALL_IN_NEAR,                  "CALL_IN_NEAR",                  NativeStub);
    RegisterNativeFunction(NATIVE_OVERRIDE_STATE_ANIMATION,      "OVERRIDE_STATE_ANIMATION",      NativeStub);
    RegisterNativeFunction(NATIVE_CREATURE_CREATE_RELATIVE_TO_CREATURE, "CREATURE_CREATE_RELATIVE_TO_CREATURE", NativeStub);
    RegisterNativeFunction(NATIVE_CREATURE_LEARN_EVERYTHING,     "CREATURE_LEARN_EVERYTHING",     NativeStub);
    RegisterNativeFunction(NATIVE_CREATURE_SET_KNOWS_ACTION,     "CREATURE_SET_KNOWS_ACTION",     NativeStub);
    RegisterNativeFunction(NATIVE_CREATURE_SET_AGENDA_PRIORITY,  "CREATURE_SET_AGENDA_PRIORITY",  NativeStub);
    RegisterNativeFunction(NATIVE_CREATURE_TURN_OFF_ALL_DESIRES, "CREATURE_TURN_OFF_ALL_DESIRES", NativeStub);
    RegisterNativeFunction(NATIVE_CREATURE_LEARN_DISTINCTION_ABOUT_ACTIVITY_OBJECT, "CREATURE_LEARN_DISTINCTION_ABOUT_ACTIVITY_OBJECT", NativeStub);
    RegisterNativeFunction(NATIVE_CREATURE_DO_ACTION,            "CREATURE_DO_ACTION",            NativeStub);
    RegisterNativeFunction(NATIVE_IN_CREATURE_HAND,              "IN_CREATURE_HAND",              NativeStub);
    RegisterNativeFunction(NATIVE_CREATURE_SET_DESIRE_VALUE,     "CREATURE_SET_DESIRE_VALUE",     NativeStub);
    RegisterNativeFunction(NATIVE_CREATURE_SET_DESIRE_ACTIVATED_78, "CREATURE_SET_DESIRE_ACTIVATED", NativeStub);
    RegisterNativeFunction(NATIVE_CREATURE_SET_DESIRE_ACTIVATED_79, "CREATURE_SET_DESIRE_ACTIVATED", NativeStub);
    RegisterNativeFunction(NATIVE_CREATURE_SET_DESIRE_MAXIMUM,   "CREATURE_SET_DESIRE_MAXIMUM",   NativeStub);
    RegisterNativeFunction(NATIVE_CONVERT_CAMERA_POSITION,       "CONVERT_CAMERA_POSITION",       NativeStub);
    RegisterNativeFunction(NATIVE_CONVERT_CAMERA_FOCUS,          "CONVERT_CAMERA_FOCUS",          NativeStub);
    RegisterNativeFunction(NATIVE_CREATURE_SET_PLAYER,           "CREATURE_SET_PLAYER",           NativeStub);
    RegisterNativeFunction(NATIVE_START_COUNTDOWN_TIMER,         "START_COUNTDOWN_TIMER",         NativeStub);
    RegisterNativeFunction(NATIVE_CREATURE_INITIALISE_NUM_TIMES_PERFORMED_ACTION, "CREATURE_INITIALISE_NUM_TIMES_PERFORMED_ACTION", NativeStub);
    RegisterNativeFunction(NATIVE_CREATURE_GET_NUM_TIMES_ACTION_PERFORMED, "CREATURE_GET_NUM_TIMES_ACTION_PERFORMED", NativeStub);
    RegisterNativeFunction(NATIVE_REMOVE_COUNTDOWN_TIMER,        "REMOVE_COUNTDOWN_TIMER",        NativeStub);
    RegisterNativeFunction(NATIVE_GET_OBJECT_DROPPED,            "GET_OBJECT_DROPPED",            NativeStub);
    RegisterNativeFunction(NATIVE_CLEAR_DROPPED_BY_OBJECT,       "CLEAR_DROPPED_BY_OBJECT",       NativeStub);
    RegisterNativeFunction(NATIVE_CREATE_REACTION,               "CREATE_REACTION",               NativeStub);
    RegisterNativeFunction(NATIVE_REMOVE_REACTION,               "REMOVE_REACTION",               NativeStub);
    RegisterNativeFunction(NATIVE_GET_COUNTDOWN_TIMER,           "GET_COUNTDOWN_TIMER",           NativeStub);
    RegisterNativeFunction(NATIVE_START_DUAL_CAMERA,             "START_DUAL_CAMERA",             NativeStub);
    RegisterNativeFunction(NATIVE_UPDATE_DUAL_CAMERA,            "UPDATE_DUAL_CAMERA",            NativeStub);
    RegisterNativeFunction(NATIVE_RELEASE_DUAL_CAMERA,           "RELEASE_DUAL_CAMERA",           NativeStub);
    RegisterNativeFunction(NATIVE_SET_CREATURE_HELP,             "SET_CREATURE_HELP",             NativeStub);
    RegisterNativeFunction(NATIVE_GET_TARGET_OBJECT,             "GET_TARGET_OBJECT",             NativeStub);
    RegisterNativeFunction(NATIVE_CREATURE_DESIRE_IS,            "CREATURE_DESIRE_IS",            NativeStub);
    RegisterNativeFunction(NATIVE_COUNTDOWN_TIMER_EXISTS,        "COUNTDOWN_TIMER_EXISTS",        NativeStub);
    RegisterNativeFunction(NATIVE_LOOK_GAME_THING,               "LOOK_GAME_THING",               NativeStub);
    RegisterNativeFunction(NATIVE_GET_OBJECT_DESTINATION,        "GET_OBJECT_DESTINATION",        NativeStub);
    RegisterNativeFunction(NATIVE_CREATURE_FORCE_FINISH,         "CREATURE_FORCE_FINISH",         NativeStub);
    RegisterNativeFunction(NATIVE_HIDE_COUNTDOWN_TIMER,          "HIDE_COUNTDOWN_TIMER",          NativeStub);
    RegisterNativeFunction(NATIVE_GET_ACTION_TEXT_FOR_OBJECT,     "GET_ACTION_TEXT_FOR_OBJECT",     NativeStub);
    RegisterNativeFunction(NATIVE_CREATE_DUAL_CAMERA_WITH_POINT, "CREATE_DUAL_CAMERA_WITH_POINT", NativeStub);
    RegisterNativeFunction(NATIVE_SET_CAMERA_TO_FACE_OBJECT,     "SET_CAMERA_TO_FACE_OBJECT",     NativeStub);
    RegisterNativeFunction(NATIVE_MOVE_CAMERA_TO_FACE_OBJECT,    "MOVE_CAMERA_TO_FACE_OBJECT",    NativeStub);
    RegisterNativeFunction(NATIVE_GET_MOON_PERCENTAGE,           "GET_MOON_PERCENTAGE",           NativeStub);
    RegisterNativeFunction(NATIVE_POPULATE_CONTAINER,            "POPULATE_CONTAINER",            NativeStub);
    RegisterNativeFunction(NATIVE_ADD_REFERENCE,                 "ADD_REFERENCE",                 NativeStub);
    RegisterNativeFunction(NATIVE_REMOVE_REFERENCE,              "REMOVE_REFERENCE",              NativeStub);
    RegisterNativeFunction(NATIVE_SET_GAME_TIME,                 "SET_GAME_TIME",                 Native_SET_GAME_TIME);
    RegisterNativeFunction(NATIVE_GET_GAME_TIME,                 "GET_GAME_TIME",                 Native_GET_GAME_TIME);
    RegisterNativeFunction(NATIVE_GET_REAL_TIME,                 "GET_REAL_TIME",                 NativeStub);
    RegisterNativeFunction(NATIVE_GET_REAL_DAY_115,              "GET_REAL_DAY",                  NativeStub);
    RegisterNativeFunction(NATIVE_GET_REAL_DAY_116,              "GET_REAL_DAY",                  NativeStub);
    RegisterNativeFunction(NATIVE_GET_REAL_MONTH,                "GET_REAL_MONTH",                NativeStub);
    RegisterNativeFunction(NATIVE_GET_REAL_YEAR,                 "GET_REAL_YEAR",                 NativeStub);
    RegisterNativeFunction(NATIVE_RUN_CAMERA_PATH,               "RUN_CAMERA_PATH",               NativeStub);
    RegisterNativeFunction(NATIVE_START_DIALOGUE,                "START_DIALOGUE",                Native_START_DIALOGUE);
    RegisterNativeFunction(NATIVE_END_DIALOGUE,                  "END_DIALOGUE",                  Native_END_DIALOGUE);
    RegisterNativeFunction(NATIVE_IS_DIALOGUE_READY,             "IS_DIALOGUE_READY",             Native_IS_DIALOGUE_READY);
    RegisterNativeFunction(NATIVE_CHANGE_WEATHER_PROPERTIES,     "CHANGE_WEATHER_PROPERTIES",     NativeStub);
    RegisterNativeFunction(NATIVE_CHANGE_LIGHTNING_PROPERTIES,   "CHANGE_LIGHTNING_PROPERTIES",   NativeStub);
    RegisterNativeFunction(NATIVE_CHANGE_TIME_FADE_PROPERTIES,   "CHANGE_TIME_FADE_PROPERTIES",   NativeStub);
    RegisterNativeFunction(NATIVE_CHANGE_CLOUD_PROPERTIES,       "CHANGE_CLOUD_PROPERTIES",       NativeStub);
    RegisterNativeFunction(NATIVE_SET_HEADING_AND_SPEED,         "SET_HEADING_AND_SPEED",         NativeStub);
    RegisterNativeFunction(NATIVE_START_GAME_SPEED,              "START_GAME_SPEED",              NativeStub);
    RegisterNativeFunction(NATIVE_END_GAME_SPEED,                "END_GAME_SPEED",                NativeStub);
    RegisterNativeFunction(NATIVE_BUILD_BUILDING,                "BUILD_BUILDING",                NativeStub);
    RegisterNativeFunction(NATIVE_SET_AFFECTED_BY_WIND,          "SET_AFFECTED_BY_WIND",          NativeStub);
    RegisterNativeFunction(NATIVE_WIDESCREEN_TRANSISTION_FINISHED, "WIDESCREEN_TRANSISTION_FINISHED", Native_WIDESCREEN_TRANSISTION_FINISHED);
    RegisterNativeFunction(NATIVE_GET_RESOURCE,                  "GET_RESOURCE",                  NativeStub);
    RegisterNativeFunction(NATIVE_ADD_RESOURCE,                  "ADD_RESOURCE",                  NativeStub);
    RegisterNativeFunction(NATIVE_REMOVE_RESOURCE,               "REMOVE_RESOURCE",               NativeStub);
    RegisterNativeFunction(NATIVE_GET_TARGET_RELATIVE_POS,       "GET_TARGET_RELATIVE_POS",       NativeStub);
    RegisterNativeFunction(NATIVE_STOP_POINTING,                 "STOP_POINTING",                 NativeStub);
    RegisterNativeFunction(NATIVE_STOP_LOOKING,                  "STOP_LOOKING",                  NativeStub);
    RegisterNativeFunction(NATIVE_LOOK_AT_POSITION,              "LOOK_AT_POSITION",              NativeStub);
    RegisterNativeFunction(NATIVE_PLAY_SPIRIT_ANIM,              "PLAY_SPIRIT_ANIM",              NativeStub);
    RegisterNativeFunction(NATIVE_CALL_IN_NOT_NEAR,              "CALL_IN_NOT_NEAR",              NativeStub);
    RegisterNativeFunction(NATIVE_SET_CAMERA_ZONE,               "SET_CAMERA_ZONE",               NativeStub);
    RegisterNativeFunction(NATIVE_GET_OBJECT_STATE,              "GET_OBJECT_STATE",              NativeStub);
    RegisterNativeFunction(NATIVE_REVEAL_COUNTDOWN_TIMER,        "REVEAL_COUNTDOWN_TIMER",        NativeStub);
    RegisterNativeFunction(NATIVE_SET_TIMER_TIME,                "SET_TIMER_TIME",                NativeStub);
    RegisterNativeFunction(NATIVE_CREATE_TIMER,                  "CREATE_TIMER",                  NativeStub);
    RegisterNativeFunction(NATIVE_GET_TIMER_TIME_REMAINING,      "GET_TIMER_TIME_REMAINING",      NativeStub);
    RegisterNativeFunction(NATIVE_GET_TIMER_TIME_SINCE_SET,      "GET_TIMER_TIME_SINCE_SET",      NativeStub);
    RegisterNativeFunction(NATIVE_MOVE_MUSIC,                    "MOVE_MUSIC",                    NativeStub);
    RegisterNativeFunction(NATIVE_GET_INCLUSION_DISTANCE,        "GET_INCLUSION_DISTANCE",        NativeStub);
    RegisterNativeFunction(NATIVE_GET_LAND_HEIGHT,               "GET_LAND_HEIGHT",               Native_GET_LAND_HEIGHT);
    RegisterNativeFunction(NATIVE_LOAD_MAP,                      "LOAD_MAP",                      Native_LOAD_MAP);
    RegisterNativeFunction(NATIVE_STOP_ALL_SCRIPTS_EXCLUDING,    "STOP_ALL_SCRIPTS_EXCLUDING",    Native_STOP_ALL_SCRIPTS_EXCLUDING);
    RegisterNativeFunction(NATIVE_STOP_ALL_SCRIPTS_IN_FILES_EXCLUDING, "STOP_ALL_SCRIPTS_IN_FILES_EXCLUDING", NativeStub);
    RegisterNativeFunction(NATIVE_STOP_SCRIPT,                   "STOP_SCRIPT",                   Native_STOP_SCRIPT);
    RegisterNativeFunction(NATIVE_CLEAR_CLICKED_OBJECT,          "CLEAR_CLICKED_OBJECT",          Native_CLEAR_CLICKED_OBJECT);
    RegisterNativeFunction(NATIVE_CLEAR_CLICKED_POSITION,        "CLEAR_CLICKED_POSITION",        Native_CLEAR_CLICKED_POSITION);
    RegisterNativeFunction(NATIVE_POSITION_CLICKED,              "POSITION_CLICKED",              Native_POSITION_CLICKED);
    RegisterNativeFunction(NATIVE_RELEASE_FROM_SCRIPT,           "RELEASE_FROM_SCRIPT",           NativeStub);
    RegisterNativeFunction(NATIVE_GET_OBJECT_HAND_IS_OVER,       "GET_OBJECT_HAND_IS_OVER",       NativeStub);
    RegisterNativeFunction(NATIVE_ID_POISONED_SIZE,              "ID_POISONED_SIZE",              NativeStub);
    RegisterNativeFunction(NATIVE_IS_POISONED,                   "IS_POISONED",                   NativeStub);
    RegisterNativeFunction(NATIVE_CALL_POISONED_IN,              "CALL_POISONED_IN",              NativeStub);
    RegisterNativeFunction(NATIVE_CALL_NOT_POISONED_IN,          "CALL_NOT_POISONED_IN",          NativeStub);
    RegisterNativeFunction(NATIVE_SPIRIT_PLAYED,                 "SPIRIT_PLAYED",                 NativeStub);
    RegisterNativeFunction(NATIVE_CLING_SPIRIT,                  "CLING_SPIRIT",                  NativeStub);
    RegisterNativeFunction(NATIVE_FLY_SPIRIT,                    "FLY_SPIRIT",                    NativeStub);
    RegisterNativeFunction(NATIVE_SET_ID_MOVEABLE,               "SET_ID_MOVEABLE",               NativeStub);
    RegisterNativeFunction(NATIVE_SET_ID_PICKUPABLE,             "SET_ID_PICKUPABLE",             NativeStub);
    RegisterNativeFunction(NATIVE_IS_ON_FIRE,                    "IS_ON_FIRE",                    NativeStub);
    RegisterNativeFunction(NATIVE_IS_FIRE_NEAR,                  "IS_FIRE_NEAR",                  NativeStub);
    RegisterNativeFunction(NATIVE_STOP_SCRIPTS_IN_FILES,         "STOP_SCRIPTS_IN_FILES",         NativeStub);
    RegisterNativeFunction(NATIVE_SET_POISONED,                  "SET_POISONED",                  NativeStub);
    RegisterNativeFunction(NATIVE_SET_TEMPERATURE,               "SET_TEMPERATURE",               NativeStub);
    RegisterNativeFunction(NATIVE_SET_ON_FIRE,                   "SET_ON_FIRE",                   NativeStub);
    RegisterNativeFunction(NATIVE_SET_TARGET,                    "SET_TARGET",                    NativeStub);
    RegisterNativeFunction(NATIVE_WALK_PATH,                     "WALK_PATH",                     NativeStub);
    RegisterNativeFunction(NATIVE_FOCUS_AND_POSITION_FOLLOW,     "FOCUS_AND_POSITION_FOLLOW",     NativeStub);
    RegisterNativeFunction(NATIVE_GET_WALK_PATH_PERCENTAGE,      "GET_WALK_PATH_PERCENTAGE",      NativeStub);
    RegisterNativeFunction(NATIVE_CAMERA_PROPERTIES,             "CAMERA_PROPERTIES",             NativeStub);
    RegisterNativeFunction(NATIVE_ENABLE_DISABLE_MUSIC,          "ENABLE_DISABLE_MUSIC",          NativeStub);
    RegisterNativeFunction(NATIVE_GET_MUSIC_OBJ_DISTANCE,        "GET_MUSIC_OBJ_DISTANCE",        NativeStub);
    RegisterNativeFunction(NATIVE_GET_MUSIC_ENUM_DISTANCE,       "GET_MUSIC_ENUM_DISTANCE",       NativeStub);
    RegisterNativeFunction(NATIVE_SET_MUSIC_PLAY_POSITION,       "SET_MUSIC_PLAY_POSITION",       NativeStub);
    RegisterNativeFunction(NATIVE_ATTACH_OBJECT_LEASH_TO_OBJECT, "ATTACH_OBJECT_LEASH_TO_OBJECT", NativeStub);
    RegisterNativeFunction(NATIVE_ATTACH_OBJECT_LEASH_TO_HAND,   "ATTACH_OBJECT_LEASH_TO_HAND",   NativeStub);
    RegisterNativeFunction(NATIVE_DETACH_OBJECT_LEASH,           "DETACH_OBJECT_LEASH",           NativeStub);
    RegisterNativeFunction(NATIVE_SET_CREATURE_ONLY_DESIRE,      "SET_CREATURE_ONLY_DESIRE",      NativeStub);
    RegisterNativeFunction(NATIVE_SET_CREATURE_ONLY_DESIRE_OFF,  "SET_CREATURE_ONLY_DESIRE_OFF",  NativeStub);
    RegisterNativeFunction(NATIVE_RESTART_MUSIC,                 "RESTART_MUSIC",                 NativeStub);
    RegisterNativeFunction(NATIVE_MUSIC_PLAYED_191,              "MUSIC_PLAYED",                  NativeStub);
    RegisterNativeFunction(NATIVE_IS_OF_TYPE,                    "IS_OF_TYPE",                    Native_IS_OF_TYPE);
    RegisterNativeFunction(NATIVE_CLEAR_HIT_OBJECT,              "CLEAR_HIT_OBJECT",              NativeStub);
    RegisterNativeFunction(NATIVE_GAME_THING_HIT,                "GAME_THING_HIT",                NativeStub);
    RegisterNativeFunction(NATIVE_SPELL_AT_THING,                "SPELL_AT_THING",                NativeStub);
    RegisterNativeFunction(NATIVE_SPELL_AT_POS,                  "SPELL_AT_POS",                  NativeStub);
    RegisterNativeFunction(NATIVE_CALL_PLAYER_CREATURE,          "CALL_PLAYER_CREATURE",          NativeStub);
    RegisterNativeFunction(NATIVE_GET_SLOWEST_SPEED,             "GET_SLOWEST_SPEED",             NativeStub);
    RegisterNativeFunction(NATIVE_GET_OBJECT_HELD_199,           "GET_OBJECT_HELD",               NativeStub);
    RegisterNativeFunction(NATIVE_HELP_SYSTEM_ON,                "HELP_SYSTEM_ON",                Native_HELP_SYSTEM_ON);
    RegisterNativeFunction(NATIVE_SHAKE_CAMERA,                  "SHAKE_CAMERA",                  NativeStub);
    RegisterNativeFunction(NATIVE_SET_ANIMATION_MODIFY,          "SET_ANIMATION_MODIFY",          NativeStub);
    RegisterNativeFunction(NATIVE_SET_AVI_SEQUENCE,              "SET_AVI_SEQUENCE",              NativeStub);
    RegisterNativeFunction(NATIVE_PLAY_GESTURE,                  "PLAY_GESTURE",                  NativeStub);
    RegisterNativeFunction(NATIVE_DEV_FUNCTION,                  "DEV_FUNCTION",                  NativeStub);
    RegisterNativeFunction(NATIVE_HAS_MOUSE_WHEEL,               "HAS_MOUSE_WHEEL",               NativeStub);
    RegisterNativeFunction(NATIVE_NUM_MOUSE_BUTTONS,             "NUM_MOUSE_BUTTONS",             NativeStub);
    RegisterNativeFunction(NATIVE_SET_CREATURE_DEV_STAGE,        "SET_CREATURE_DEV_STAGE",        NativeStub);
    RegisterNativeFunction(NATIVE_SET_FIXED_CAM_ROTATION,        "SET_FIXED_CAM_ROTATION",        NativeStub);
    RegisterNativeFunction(NATIVE_SWAP_CREATURE,                 "SWAP_CREATURE",                 NativeStub);
    RegisterNativeFunction(NATIVE_GET_ARENA,                     "GET_ARENA",                     NativeStub);
    RegisterNativeFunction(NATIVE_GET_FOOTBALL_PITCH,            "GET_FOOTBALL_PITCH",            NativeStub);
    RegisterNativeFunction(NATIVE_STOP_ALL_GAMES,                "STOP_ALL_GAMES",                NativeStub);
    RegisterNativeFunction(NATIVE_ATTACH_TO_GAME,                "ATTACH_TO_GAME",                NativeStub);
    RegisterNativeFunction(NATIVE_DETACH_FROM_GAME,              "DETACH_FROM_GAME",              NativeStub);
    RegisterNativeFunction(NATIVE_DETACH_UNDEFINED_FROM_GAME,    "DETACH_UNDEFINED_FROM_GAME",    NativeStub);
    RegisterNativeFunction(NATIVE_SET_ONLY_FOR_SCRIPTS,          "SET_ONLY_FOR_SCRIPTS",          NativeStub);
    RegisterNativeFunction(NATIVE_START_MATCH_WITH_REFEREE,      "START_MATCH_WITH_REFEREE",      NativeStub);
    RegisterNativeFunction(NATIVE_GAME_TEAM_SIZE,                "GAME_TEAM_SIZE",                NativeStub);
    RegisterNativeFunction(NATIVE_GAME_TYPE,                     "GAME_TYPE",                     NativeStub);
    RegisterNativeFunction(NATIVE_GAME_SUB_TYPE,                 "GAME_SUB_TYPE",                 NativeStub);
    RegisterNativeFunction(NATIVE_IS_LEASHED,                    "IS_LEASHED",                    NativeStub);
    RegisterNativeFunction(NATIVE_SET_CREATURE_HOME,             "SET_CREATURE_HOME",             NativeStub);
    RegisterNativeFunction(NATIVE_GET_HIT_OBJECT,                "GET_HIT_OBJECT",                NativeStub);
    RegisterNativeFunction(NATIVE_GET_OBJECT_WHICH_HIT,          "GET_OBJECT_WHICH_HIT",          NativeStub);
    RegisterNativeFunction(NATIVE_GET_NEAREST_TOWN_OF_PLAYER,    "GET_NEAREST_TOWN_OF_PLAYER",    Native_GET_NEAREST_TOWN_OF_PLAYER);
    RegisterNativeFunction(NATIVE_SPELL_AT_POINT,                "SPELL_AT_POINT",                NativeStub);
    RegisterNativeFunction(NATIVE_SET_ATTACK_OWN_TOWN,           "SET_ATTACK_OWN_TOWN",           NativeStub);
    RegisterNativeFunction(NATIVE_IS_FIGHTING,                   "IS_FIGHTING",                   NativeStub);
    RegisterNativeFunction(NATIVE_SET_MAGIC_RADIUS,              "SET_MAGIC_RADIUS",              NativeStub);
    RegisterNativeFunction(NATIVE_TEMP_TEXT_WITH_NUMBER,          "TEMP_TEXT_WITH_NUMBER",          NativeStub);
    RegisterNativeFunction(NATIVE_RUN_TEXT_WITH_NUMBER,           "RUN_TEXT_WITH_NUMBER",           NativeStub);
    RegisterNativeFunction(NATIVE_CREATURE_SPELL_REVERSION,      "CREATURE_SPELL_REVERSION",      NativeStub);
    RegisterNativeFunction(NATIVE_GET_DESIRE,                    "GET_DESIRE",                    NativeStub);
    RegisterNativeFunction(NATIVE_GET_EVENTS_PER_SECOND,         "GET_EVENTS_PER_SECOND",         NativeStub);
    RegisterNativeFunction(NATIVE_GET_TIME_SINCE,                "GET_TIME_SINCE",                NativeStub);
    RegisterNativeFunction(NATIVE_GET_TOTAL_EVENTS,              "GET_TOTAL_EVENTS",              NativeStub);
    RegisterNativeFunction(NATIVE_UPDATE_SNAPSHOT,               "UPDATE_SNAPSHOT",               NativeStub);
    RegisterNativeFunction(NATIVE_CREATE_REWARD,                 "CREATE_REWARD",                 NativeStub);
    RegisterNativeFunction(NATIVE_CREATE_REWARD_IN_TOWN,         "CREATE_REWARD_IN_TOWN",         NativeStub);
    RegisterNativeFunction(NATIVE_SET_FADE,                      "SET_FADE",                      Native_SET_FADE);
    RegisterNativeFunction(NATIVE_SET_FADE_IN,                   "SET_FADE_IN",                   Native_SET_FADE_IN);
    RegisterNativeFunction(NATIVE_FADE_FINISHED,                 "FADE_FINISHED",                 Native_FADE_FINISHED);
    RegisterNativeFunction(NATIVE_SET_PLAYER_MAGIC,              "SET_PLAYER_MAGIC",              Native_SET_PLAYER_MAGIC);
    RegisterNativeFunction(NATIVE_HAS_PLAYER_MAGIC,              "HAS_PLAYER_MAGIC",              Native_HAS_PLAYER_MAGIC);
    RegisterNativeFunction(NATIVE_SPIRIT_SPEAKS,                 "SPIRIT_SPEAKS",                 NativeStub);
    RegisterNativeFunction(NATIVE_BELIEF_FOR_PLAYER,             "BELIEF_FOR_PLAYER",             Native_BELIEF_FOR_PLAYER);
    RegisterNativeFunction(NATIVE_GET_HELP,                      "GET_HELP",                      NativeStub);
    RegisterNativeFunction(NATIVE_SET_LEASH_WORKS,               "SET_LEASH_WORKS",               NativeStub);
    RegisterNativeFunction(NATIVE_LOAD_MY_CREATURE,              "LOAD_MY_CREATURE",              NativeStub);
    RegisterNativeFunction(NATIVE_OBJECT_RELATIVE_BELIEF,        "OBJECT_RELATIVE_BELIEF",        NativeStub);
    RegisterNativeFunction(NATIVE_CREATE_WITH_ANGLE_AND_SCALE,   "CREATE_WITH_ANGLE_AND_SCALE",   NativeStub);
    RegisterNativeFunction(NATIVE_SET_HELP_SYSTEM,               "SET_HELP_SYSTEM",               Native_SET_HELP_SYSTEM);
    RegisterNativeFunction(NATIVE_SET_VIRTUAL_INFLUENCE,         "SET_VIRTUAL_INFLUENCE",         NativeStub);
    RegisterNativeFunction(NATIVE_SET_ACTIVE,                    "SET_ACTIVE",                    Native_SET_ACTIVE);
    RegisterNativeFunction(NATIVE_THING_VALID,                   "THING_VALID",                   Native_THING_VALID);
    RegisterNativeFunction(NATIVE_VORTEX_FADE_OUT,               "VORTEX_FADE_OUT",               NativeStub);
    RegisterNativeFunction(NATIVE_REMOVE_REACTION_OF_TYPE,       "REMOVE_REACTION_OF_TYPE",       NativeStub);
    RegisterNativeFunction(NATIVE_CREATURE_LEARN_EVERYTHING_EXCLUDING, "CREATURE_LEARN_EVERYTHING_EXCLUDING", NativeStub);
    RegisterNativeFunction(NATIVE_PLAYED_PERCENTAGE,             "PLAYED_PERCENTAGE",             NativeStub);
    RegisterNativeFunction(NATIVE_OBJECT_CAST_BY_OBJECT,         "OBJECT_CAST_BY_OBJECT",         NativeStub);
    RegisterNativeFunction(NATIVE_IS_WIND_MAGIC_AT_POS,          "IS_WIND_MAGIC_AT_POS",          NativeStub);
    RegisterNativeFunction(NATIVE_CREATE_MIST,                   "CREATE_MIST",                   NativeStub);
    RegisterNativeFunction(NATIVE_SET_MIST_FADE,                 "SET_MIST_FADE",                 NativeStub);
    RegisterNativeFunction(NATIVE_GET_OBJECT_FADE,               "GET_OBJECT_FADE",               NativeStub);
    RegisterNativeFunction(NATIVE_PLAY_HAND_DEMO,                "PLAY_HAND_DEMO",                NativeStub);
    RegisterNativeFunction(NATIVE_IS_PLAYING_HAND_DEMO,          "IS_PLAYING_HAND_DEMO",          NativeStub);
    RegisterNativeFunction(NATIVE_GET_ARSE_POSITION,             "GET_ARSE_POSITION",             NativeStub);
    RegisterNativeFunction(NATIVE_IS_LEASHED_TO_OBJECT,          "IS_LEASHED_TO_OBJECT",          NativeStub);
    RegisterNativeFunction(NATIVE_GET_INTERACTION_MAGNITUDE,     "GET_INTERACTION_MAGNITUDE",     NativeStub);
    RegisterNativeFunction(NATIVE_IS_CREATURE_AVAILABLE,         "IS_CREATURE_AVAILABLE",         NativeStub);
    RegisterNativeFunction(NATIVE_CREATE_HIGHLIGHT,              "CREATE_HIGHLIGHT",              NativeStub);
    RegisterNativeFunction(NATIVE_GET_OBJECT_HELD_273,           "GET_OBJECT_HELD",               NativeStub);
    RegisterNativeFunction(NATIVE_GET_ACTION_COUNT,              "GET_ACTION_COUNT",              NativeStub);
    RegisterNativeFunction(NATIVE_GET_OBJECT_LEASH_TYPE,         "GET_OBJECT_LEASH_TYPE",         NativeStub);
    RegisterNativeFunction(NATIVE_SET_FOCUS_FOLLOW,              "SET_FOCUS_FOLLOW",              NativeStub);
    RegisterNativeFunction(NATIVE_SET_POSITION_FOLLOW,           "SET_POSITION_FOLLOW",           NativeStub);
    RegisterNativeFunction(NATIVE_SET_FOCUS_AND_POSITION_FOLLOW, "SET_FOCUS_AND_POSITION_FOLLOW", NativeStub);
    RegisterNativeFunction(NATIVE_SET_CAMERA_LENS,               "SET_CAMERA_LENS",               NativeStub);
    RegisterNativeFunction(NATIVE_MOVE_CAMERA_LENS,              "MOVE_CAMERA_LENS",              NativeStub);
    RegisterNativeFunction(NATIVE_CREATURE_REACTION,             "CREATURE_REACTION",             NativeStub);
    RegisterNativeFunction(NATIVE_CREATURE_IN_DEV_SCRIPT,        "CREATURE_IN_DEV_SCRIPT",        NativeStub);
    RegisterNativeFunction(NATIVE_STORE_CAMERA_DETAILS,          "STORE_CAMERA_DETAILS",          NativeStub);
    RegisterNativeFunction(NATIVE_RESTORE_CAMERA_DETAILS,        "RESTORE_CAMERA_DETAILS",        NativeStub);
    RegisterNativeFunction(NATIVE_START_ANGLE_SOUND_285,         "START_ANGLE_SOUND",             NativeStub);
    RegisterNativeFunction(NATIVE_SET_CAMERA_POS_FOC_LENS,       "SET_CAMERA_POS_FOC_LENS",       NativeStub);
    RegisterNativeFunction(NATIVE_MOVE_CAMERA_POS_FOC_LENS,      "MOVE_CAMERA_POS_FOC_LENS",      NativeStub);
    RegisterNativeFunction(NATIVE_GAME_TIME_ON_OFF,              "GAME_TIME_ON_OFF",              NativeStub);
    RegisterNativeFunction(NATIVE_MOVE_GAME_TIME,                "MOVE_GAME_TIME",                NativeStub);
    RegisterNativeFunction(NATIVE_SET_HIGH_GRAPHICS_DETAIL,      "SET_HIGH_GRAPHICS_DETAIL",      NativeStub);
    RegisterNativeFunction(NATIVE_SET_SKELETON,                  "SET_SKELETON",                  NativeStub);
    RegisterNativeFunction(NATIVE_IS_SKELETON,                   "IS_SKELETON",                   NativeStub);
    RegisterNativeFunction(NATIVE_PLAYER_SPELL_CAST_TIME,        "PLAYER_SPELL_CAST_TIME",        NativeStub);
    RegisterNativeFunction(NATIVE_PLAYER_SPELL_LAST_CAST,        "PLAYER_SPELL_LAST_CAST",        NativeStub);
    RegisterNativeFunction(NATIVE_GET_LAST_SPELL_CAST_POS,       "GET_LAST_SPELL_CAST_POS",       NativeStub);
    RegisterNativeFunction(NATIVE_ADD_SPOT_VISUAL_TARGET_POS,    "ADD_SPOT_VISUAL_TARGET_POS",    NativeStub);
    RegisterNativeFunction(NATIVE_ADD_SPOT_VISUAL_TARGET_OBJECT, "ADD_SPOT_VISUAL_TARGET_OBJECT", NativeStub);
    RegisterNativeFunction(NATIVE_SET_INDESTRUCTABLE,            "SET_INDESTRUCTABLE",            NativeStub);
    RegisterNativeFunction(NATIVE_SET_GRAPHICS_CLIPPING,         "SET_GRAPHICS_CLIPPING",         NativeStub);
    RegisterNativeFunction(NATIVE_SPIRIT_APPEAR,                 "SPIRIT_APPEAR",                 NativeStub);
    RegisterNativeFunction(NATIVE_SPIRIT_DISAPPEAR,              "SPIRIT_DISAPPEAR",              NativeStub);
    RegisterNativeFunction(NATIVE_SET_FOCUS_ON_OBJECT,           "SET_FOCUS_ON_OBJECT",           NativeStub);
    RegisterNativeFunction(NATIVE_RELEASE_OBJECT_FOCUS,          "RELEASE_OBJECT_FOCUS",          NativeStub);
    RegisterNativeFunction(NATIVE_IMMERSION_EXISTS,              "IMMERSION_EXISTS",              NativeStub);
    RegisterNativeFunction(NATIVE_SET_DRAW_LEASH,                "SET_DRAW_LEASH",                NativeStub);
    RegisterNativeFunction(NATIVE_SET_DRAW_HIGHLIGHT,            "SET_DRAW_HIGHLIGHT",            NativeStub);
    RegisterNativeFunction(NATIVE_SET_OPEN_CLOSE,                "SET_OPEN_CLOSE",                NativeStub);
    RegisterNativeFunction(NATIVE_SET_INTRO_BUILDING,            "SET_INTRO_BUILDING",            NativeStub);
    RegisterNativeFunction(NATIVE_CREATURE_FORCE_FRIENDS,        "CREATURE_FORCE_FRIENDS",        NativeStub);
    RegisterNativeFunction(NATIVE_MOVE_COMPUTER_PLAYER_POSITION, "MOVE_COMPUTER_PLAYER_POSITION", NativeStub);
    RegisterNativeFunction(NATIVE_ENABLE_DISABLE_COMPUTER_PLAYER_311, "ENABLE_DISABLE_COMPUTER_PLAYER", NativeStub);
    RegisterNativeFunction(NATIVE_GET_COMPUTER_PLAYER_POSITION,  "GET_COMPUTER_PLAYER_POSITION",  NativeStub);
    RegisterNativeFunction(NATIVE_SET_COMPUTER_PLAYER_POSITION,  "SET_COMPUTER_PLAYER_POSITION",  NativeStub);
    RegisterNativeFunction(NATIVE_GET_STORED_CAMERA_POSITION,    "GET_STORED_CAMERA_POSITION",    NativeStub);
    RegisterNativeFunction(NATIVE_GET_STORED_CAMERA_FOCUS,       "GET_STORED_CAMERA_FOCUS",       NativeStub);
    RegisterNativeFunction(NATIVE_CALL_NEAR_IN_STATE,            "CALL_NEAR_IN_STATE",            NativeStub);
    RegisterNativeFunction(NATIVE_SET_CREATURE_SOUND,            "SET_CREATURE_SOUND",            NativeStub);
    RegisterNativeFunction(NATIVE_CREATURE_INTERACTING_WITH,     "CREATURE_INTERACTING_WITH",     NativeStub);
    RegisterNativeFunction(NATIVE_SET_SUN_DRAW,                  "SET_SUN_DRAW",                  NativeStub);
    RegisterNativeFunction(NATIVE_OBJECT_INFO_BITS,              "OBJECT_INFO_BITS",              NativeStub);
    RegisterNativeFunction(NATIVE_SET_HURT_BY_FIRE,              "SET_HURT_BY_FIRE",              NativeStub);
    RegisterNativeFunction(NATIVE_CONFINED_OBJECT,               "CONFINED_OBJECT",               NativeStub);
    RegisterNativeFunction(NATIVE_CLEAR_CONFINED_OBJECT,         "CLEAR_CONFINED_OBJECT",         NativeStub);
    RegisterNativeFunction(NATIVE_GET_OBJECT_FLOCK,              "GET_OBJECT_FLOCK",              NativeStub);
    RegisterNativeFunction(NATIVE_SET_PLAYER_BELIEF,             "SET_PLAYER_BELIEF",             NativeStub);
    RegisterNativeFunction(NATIVE_PLAY_JC_SPECIAL,               "PLAY_JC_SPECIAL",               NativeStub);
    RegisterNativeFunction(NATIVE_IS_PLAYING_JC_SPECIAL,         "IS_PLAYING_JC_SPECIAL",         NativeStub);
    RegisterNativeFunction(NATIVE_VORTEX_PARAMETERS,             "VORTEX_PARAMETERS",             NativeStub);
    RegisterNativeFunction(NATIVE_LOAD_CREATURE,                 "LOAD_CREATURE",                 NativeStub);
    RegisterNativeFunction(NATIVE_IS_SPELL_CHARGING,             "IS_SPELL_CHARGING",             NativeStub);
    RegisterNativeFunction(NATIVE_IS_THAT_SPELL_CHARGING,        "IS_THAT_SPELL_CHARGING",        NativeStub);
    RegisterNativeFunction(NATIVE_OPPOSING_CREATURE,             "OPPOSING_CREATURE",             NativeStub);
    RegisterNativeFunction(NATIVE_FLOCK_WITHIN_LIMITS,           "FLOCK_WITHIN_LIMITS",           NativeStub);
    RegisterNativeFunction(NATIVE_HIGHLIGHT_PROPERTIES,          "HIGHLIGHT_PROPERTIES",          NativeStub);
    RegisterNativeFunction(NATIVE_LAST_MUSIC_LINE,               "LAST_MUSIC_LINE",               NativeStub);
    RegisterNativeFunction(NATIVE_HAND_DEMO_TRIGGER,             "HAND_DEMO_TRIGGER",             NativeStub);
    RegisterNativeFunction(NATIVE_GET_BELLY_POSITION,            "GET_BELLY_POSITION",            NativeStub);
    RegisterNativeFunction(NATIVE_SET_CREATURE_CREED_PROPERTIES, "SET_CREATURE_CREED_PROPERTIES", NativeStub);
    RegisterNativeFunction(NATIVE_GAME_THING_CAN_VIEW_CAMERA,    "GAME_THING_CAN_VIEW_CAMERA",    NativeStub);
    RegisterNativeFunction(NATIVE_GAME_PLAY_SAY_SOUND_EFFECT,    "GAME_PLAY_SAY_SOUND_EFFECT",    NativeStub);
    RegisterNativeFunction(NATIVE_SET_TOWN_DESIRE_BOOST,         "SET_TOWN_DESIRE_BOOST",         NativeStub);
    RegisterNativeFunction(NATIVE_IS_LOCKED_INTERACTION,         "IS_LOCKED_INTERACTION",         NativeStub);
    RegisterNativeFunction(NATIVE_SET_CREATURE_NAME,             "SET_CREATURE_NAME",             NativeStub);
    RegisterNativeFunction(NATIVE_COMPUTER_PLAYER_READY,         "COMPUTER_PLAYER_READY",         NativeStub);
    RegisterNativeFunction(NATIVE_ENABLE_DISABLE_COMPUTER_PLAYER_345, "ENABLE_DISABLE_COMPUTER_PLAYER", NativeStub);
    RegisterNativeFunction(NATIVE_CLEAR_ACTOR_MIND,              "CLEAR_ACTOR_MIND",              NativeStub);
    RegisterNativeFunction(NATIVE_ENTER_EXIT_CITADEL,            "ENTER_EXIT_CITADEL",            NativeStub);
    RegisterNativeFunction(NATIVE_START_ANGLE_SOUND_348,         "START_ANGLE_SOUND",             NativeStub);
    RegisterNativeFunction(NATIVE_THING_JC_SPECIAL,              "THING_JC_SPECIAL",              NativeStub);
    RegisterNativeFunction(NATIVE_MUSIC_PLAYED_350,              "MUSIC_PLAYED",                  NativeStub);
    RegisterNativeFunction(NATIVE_UPDATE_SNAPSHOT_PICTURE,       "UPDATE_SNAPSHOT_PICTURE",       NativeStub);
    RegisterNativeFunction(NATIVE_STOP_SCRIPTS_IN_FILES_EXCLUDING, "STOP_SCRIPTS_IN_FILES_EXCLUDING", NativeStub);
    RegisterNativeFunction(NATIVE_CREATE_RANDOM_VILLAGER_OF_TRIBE, "CREATE_RANDOM_VILLAGER_OF_TRIBE", NativeStub);
    RegisterNativeFunction(NATIVE_TOGGLE_LEASH,                  "TOGGLE_LEASH",                  NativeStub);
    RegisterNativeFunction(NATIVE_GAME_SET_MANA,                 "GAME_SET_MANA",                 NativeStub);
    RegisterNativeFunction(NATIVE_SET_MAGIC_PROPERTIES,          "SET_MAGIC_PROPERTIES",          NativeStub);
    RegisterNativeFunction(NATIVE_SET_GAME_SOUND,                "SET_GAME_SOUND",                NativeStub);
    RegisterNativeFunction(NATIVE_SEX_IS_MALE,                   "SEX_IS_MALE",                   NativeStub);
    RegisterNativeFunction(NATIVE_GET_FIRST_HELP,                "GET_FIRST_HELP",                NativeStub);
    RegisterNativeFunction(NATIVE_GET_LAST_HELP,                 "GET_LAST_HELP",                 NativeStub);
    RegisterNativeFunction(NATIVE_IS_ACTIVE,                     "IS_ACTIVE",                     Native_IS_ACTIVE);
    RegisterNativeFunction(NATIVE_SET_BOOKMARK_POSITION,         "SET_BOOKMARK_POSITION",         NativeStub);
    RegisterNativeFunction(NATIVE_SET_SCAFFOLD_PROPERTIES,       "SET_SCAFFOLD_PROPERTIES",       NativeStub);
    RegisterNativeFunction(NATIVE_SET_COMPUTER_PLAYER_PERSONALITY, "SET_COMPUTER_PLAYER_PERSONALITY", NativeStub);
    RegisterNativeFunction(NATIVE_SET_COMPUTER_PLAYER_SUPPRESSION, "SET_COMPUTER_PLAYER_SUPPRESSION", NativeStub);
    RegisterNativeFunction(NATIVE_FORCE_COMPUTER_PLAYER_ACTION,  "FORCE_COMPUTER_PLAYER_ACTION",  NativeStub);
    RegisterNativeFunction(NATIVE_QUEUE_COMPUTER_PLAYER_ACTION,  "QUEUE_COMPUTER_PLAYER_ACTION",  NativeStub);
    RegisterNativeFunction(NATIVE_GET_TOWN_WITH_ID,              "GET_TOWN_WITH_ID",              Native_GET_TOWN_WITH_ID);
    RegisterNativeFunction(NATIVE_SET_DISCIPLE,                  "SET_DISCIPLE",                  NativeStub);
    RegisterNativeFunction(NATIVE_RELEASE_COMPUTER_PLAYER,       "RELEASE_COMPUTER_PLAYER",       NativeStub);
    RegisterNativeFunction(NATIVE_SET_COMPUTER_PLAYER_SPEED,     "SET_COMPUTER_PLAYER_SPEED",     NativeStub);
    RegisterNativeFunction(NATIVE_SET_FOCUS_FOLLOW_COMPUTER_PLAYER, "SET_FOCUS_FOLLOW_COMPUTER_PLAYER", NativeStub);
    RegisterNativeFunction(NATIVE_SET_POSITION_FOLLOW_COMPUTER_PLAYER, "SET_POSITION_FOLLOW_COMPUTER_PLAYER", NativeStub);
    RegisterNativeFunction(NATIVE_CALL_COMPUTER_PLAYER,          "CALL_COMPUTER_PLAYER",          NativeStub);
    RegisterNativeFunction(NATIVE_CALL_BUILDING_IN_TOWN,         "CALL_BUILDING_IN_TOWN",         NativeStub);
    RegisterNativeFunction(NATIVE_SET_CAN_BUILD_WORSHIPSITE,     "SET_CAN_BUILD_WORSHIPSITE",     NativeStub);
    RegisterNativeFunction(NATIVE_GET_FACING_CAMERA_POSITION,    "GET_FACING_CAMERA_POSITION",    NativeStub);
    RegisterNativeFunction(NATIVE_SET_COMPUTER_PLAYER_ATTITUDE,  "SET_COMPUTER_PLAYER_ATTITUDE",  NativeStub);
    RegisterNativeFunction(NATIVE_GET_COMPUTER_PLAYER_ATTITUDE,  "GET_COMPUTER_PLAYER_ATTITUDE",  NativeStub);
    RegisterNativeFunction(NATIVE_LOAD_COMPUTER_PLAYER_PERSONALITY, "LOAD_COMPUTER_PLAYER_PERSONALITY", NativeStub);
    RegisterNativeFunction(NATIVE_SAVE_COMPUTER_PLAYER_PERSONALITY, "SAVE_COMPUTER_PLAYER_PERSONALITY", NativeStub);
    RegisterNativeFunction(NATIVE_SET_PLAYER_ALLY,               "SET_PLAYER_ALLY",               NativeStub);
    RegisterNativeFunction(NATIVE_CALL_FLYING,                   "CALL_FLYING",                   NativeStub);
    RegisterNativeFunction(NATIVE_SET_OBJECT_FADE_IN,            "SET_OBJECT_FADE_IN",            NativeStub);
    RegisterNativeFunction(NATIVE_IS_AFFECTED_BY_SPELL,          "IS_AFFECTED_BY_SPELL",          NativeStub);
    RegisterNativeFunction(NATIVE_SET_MAGIC_IN_OBJECT,           "SET_MAGIC_IN_OBJECT",           NativeStub);
    RegisterNativeFunction(NATIVE_ID_ADULT_SIZE,                 "ID_ADULT_SIZE",                 NativeStub);
    RegisterNativeFunction(NATIVE_OBJECT_CAPACITY,               "OBJECT_CAPACITY",               NativeStub);
    RegisterNativeFunction(NATIVE_OBJECT_ADULT_CAPACITY,         "OBJECT_ADULT_CAPACITY",         NativeStub);
    RegisterNativeFunction(NATIVE_SET_CREATURE_AUTO_FIGHTING,    "SET_CREATURE_AUTO_FIGHTING",    NativeStub);
    RegisterNativeFunction(NATIVE_IS_AUTO_FIGHTING,              "IS_AUTO_FIGHTING",              NativeStub);
    RegisterNativeFunction(NATIVE_SET_CREATURE_QUEUE_FIGHT_MOVE, "SET_CREATURE_QUEUE_FIGHT_MOVE", NativeStub);
    RegisterNativeFunction(NATIVE_SET_CREATURE_QUEUE_FIGHT_SPELL, "SET_CREATURE_QUEUE_FIGHT_SPELL", NativeStub);
    RegisterNativeFunction(NATIVE_SET_CREATURE_QUEUE_FIGHT_STEP, "SET_CREATURE_QUEUE_FIGHT_STEP", NativeStub);
    RegisterNativeFunction(NATIVE_GET_CREATURE_FIGHT_ACTION,     "GET_CREATURE_FIGHT_ACTION",     NativeStub);
    RegisterNativeFunction(NATIVE_CREATURE_FIGHT_QUEUE_HITS,     "CREATURE_FIGHT_QUEUE_HITS",     NativeStub);
    RegisterNativeFunction(NATIVE_SQUARE_ROOT,                   "SQUARE_ROOT",                   Native_SQUARE_ROOT);
    RegisterNativeFunction(NATIVE_GET_PLAYER_ALLY,               "GET_PLAYER_ALLY",               NativeStub);
    RegisterNativeFunction(NATIVE_SET_PLAYER_WIND_RESISTANCE,    "SET_PLAYER_WIND_RESISTANCE",    NativeStub);
    RegisterNativeFunction(NATIVE_GET_PLAYER_WIND_RESISTANCE,    "GET_PLAYER_WIND_RESISTANCE",    NativeStub);
    RegisterNativeFunction(NATIVE_PAUSE_UNPAUSE_CLIMATE_SYSTEM,  "PAUSE_UNPAUSE_CLIMATE_SYSTEM",  NativeStub);
    RegisterNativeFunction(NATIVE_PAUSE_UNPAUSE_STORM_CREATION_IN_CLIMATE_SYSTEM, "PAUSE_UNPAUSE_STORM_CREATION_IN_CLIMATE_SYSTEM", NativeStub);
    RegisterNativeFunction(NATIVE_GET_MANA_FOR_SPELL,            "GET_MANA_FOR_SPELL",            NativeStub);
    RegisterNativeFunction(NATIVE_KILL_STORMS_IN_AREA,           "KILL_STORMS_IN_AREA",           NativeStub);
    RegisterNativeFunction(NATIVE_INSIDE_TEMPLE,                 "INSIDE_TEMPLE",                 NativeStub);
    RegisterNativeFunction(NATIVE_RESTART_OBJECT,                "RESTART_OBJECT",                NativeStub);
    RegisterNativeFunction(NATIVE_SET_GAME_TIME_PROPERTIES,      "SET_GAME_TIME_PROPERTIES",      NativeStub);
    RegisterNativeFunction(NATIVE_RESET_GAME_TIME_PROPERTIES,    "RESET_GAME_TIME_PROPERTIES",    NativeStub);
    RegisterNativeFunction(NATIVE_SOUND_EXISTS,                  "SOUND_EXISTS",                  Native_SOUND_EXISTS);
    RegisterNativeFunction(NATIVE_GET_TOWN_WORSHIP_DEATHS,       "GET_TOWN_WORSHIP_DEATHS",       NativeStub);
    RegisterNativeFunction(NATIVE_GAME_CLEAR_DIALOGUE,           "GAME_CLEAR_DIALOGUE",           NativeStub);
    RegisterNativeFunction(NATIVE_GAME_CLOSE_DIALOGUE,           "GAME_CLOSE_DIALOGUE",           NativeStub);
    RegisterNativeFunction(NATIVE_GET_HAND_STATE,                "GET_HAND_STATE",                Native_GET_HAND_STATE);
    RegisterNativeFunction(NATIVE_SET_INTERFACE_CITADEL,         "SET_INTERFACE_CITADEL",         NativeStub);
    RegisterNativeFunction(NATIVE_MAP_SCRIPT_FUNCTION,           "MAP_SCRIPT_FUNCTION",           NativeStub);
    RegisterNativeFunction(NATIVE_WITHIN_ROTATION,               "WITHIN_ROTATION",               NativeStub);
    RegisterNativeFunction(NATIVE_GET_PLAYER_TOWN_TOTAL,         "GET_PLAYER_TOWN_TOTAL",         Native_GET_PLAYER_TOWN_TOTAL);
    RegisterNativeFunction(NATIVE_SPIRIT_SCREEN_POINT,           "SPIRIT_SCREEN_POINT",           NativeStub);
    RegisterNativeFunction(NATIVE_KEY_DOWN,                      "KEY_DOWN",                      Native_KEY_DOWN);
    RegisterNativeFunction(NATIVE_SET_FIGHT_EXIT,                "SET_FIGHT_EXIT",                NativeStub);
    RegisterNativeFunction(NATIVE_GET_OBJECT_CLICKED,            "GET_OBJECT_CLICKED",            Native_GET_OBJECT_CLICKED);
    RegisterNativeFunction(NATIVE_GET_MANA,                      "GET_MANA",                      Native_GET_MANA);
    RegisterNativeFunction(NATIVE_CLEAR_PLAYER_SPELL_CHARGING,   "CLEAR_PLAYER_SPELL_CHARGING",   NativeStub);
    RegisterNativeFunction(NATIVE_STOP_SOUND_EFFECT,             "STOP_SOUND_EFFECT",             Native_STOP_SOUND_EFFECT);
    RegisterNativeFunction(NATIVE_GET_TOTEM_STATUE,              "GET_TOTEM_STATUE",              NativeStub);
    RegisterNativeFunction(NATIVE_SET_SET_ON_FIRE,               "SET_SET_ON_FIRE",               NativeStub);
    RegisterNativeFunction(NATIVE_SET_LAND_BALANCE,              "SET_LAND_BALANCE",              NativeStub);
    RegisterNativeFunction(NATIVE_SET_OBJECT_BELIEF_SCALE,       "SET_OBJECT_BELIEF_SCALE",       NativeStub);
    RegisterNativeFunction(NATIVE_START_IMMERSION,               "START_IMMERSION",               NativeStub);
    RegisterNativeFunction(NATIVE_STOP_IMMERSION,                "STOP_IMMERSION",                NativeStub);
    RegisterNativeFunction(NATIVE_STOP_ALL_IMMERSION,            "STOP_ALL_IMMERSION",            NativeStub);
    RegisterNativeFunction(NATIVE_SET_CREATURE_IN_TEMPLE,        "SET_CREATURE_IN_TEMPLE",        NativeStub);
    RegisterNativeFunction(NATIVE_GAME_DRAW_TEXT,                "GAME_DRAW_TEXT",                NativeStub);
    RegisterNativeFunction(NATIVE_GAME_DRAW_TEMP_TEXT,           "GAME_DRAW_TEMP_TEXT",           NativeStub);
    RegisterNativeFunction(NATIVE_FADE_ALL_DRAW_TEXT,            "FADE_ALL_DRAW_TEXT",            NativeStub);
    RegisterNativeFunction(NATIVE_SET_DRAW_TEXT_COLOUR,          "SET_DRAW_TEXT_COLOUR",          NativeStub);
    RegisterNativeFunction(NATIVE_SET_CLIPPING_WINDOW,           "SET_CLIPPING_WINDOW",           NativeStub);
    RegisterNativeFunction(NATIVE_CLEAR_CLIPPING_WINDOW,         "CLEAR_CLIPPING_WINDOW",         NativeStub);
    RegisterNativeFunction(NATIVE_SAVE_GAME_IN_SLOT,             "SAVE_GAME_IN_SLOT",             NativeStub);
    RegisterNativeFunction(NATIVE_SET_OBJECT_CARRYING,           "SET_OBJECT_CARRYING",           NativeStub);
    RegisterNativeFunction(NATIVE_POS_VALID_FOR_CREATURE,        "POS_VALID_FOR_CREATURE",        NativeStub);
    RegisterNativeFunction(NATIVE_GET_TIME_SINCE_OBJECT_ATTACKED, "GET_TIME_SINCE_OBJECT_ATTACKED", NativeStub);
    RegisterNativeFunction(NATIVE_GET_TOWN_AND_VILLAGER_HEALTH_TOTAL, "GET_TOWN_AND_VILLAGER_HEALTH_TOTAL", NativeStub);
    RegisterNativeFunction(NATIVE_GAME_ADD_FOR_BUILDING,         "GAME_ADD_FOR_BUILDING",         NativeStub);
    RegisterNativeFunction(NATIVE_ENABLE_DISABLE_ALIGNMENT_MUSIC, "ENABLE_DISABLE_ALIGNMENT_MUSIC", NativeStub);
    RegisterNativeFunction(NATIVE_GET_DEAD_LIVING,               "GET_DEAD_LIVING",               NativeStub);
    RegisterNativeFunction(NATIVE_ATTACH_SOUND_TAG,              "ATTACH_SOUND_TAG",              NativeStub);
    RegisterNativeFunction(NATIVE_DETACH_SOUND_TAG,              "DETACH_SOUND_TAG",              NativeStub);
    RegisterNativeFunction(NATIVE_GET_SACRIFICE_TOTAL,           "GET_SACRIFICE_TOTAL",           NativeStub);
    RegisterNativeFunction(NATIVE_GAME_SOUND_PLAYING,            "GAME_SOUND_PLAYING",            NativeStub);
    RegisterNativeFunction(NATIVE_GET_TEMPLE_POSITION,           "GET_TEMPLE_POSITION",           NativeStub);
    RegisterNativeFunction(NATIVE_CREATURE_AUTOSCALE,            "CREATURE_AUTOSCALE",            NativeStub);
    RegisterNativeFunction(NATIVE_GET_SPELL_ICON_IN_TEMPLE,      "GET_SPELL_ICON_IN_TEMPLE",      NativeStub);
    RegisterNativeFunction(NATIVE_GAME_CLEAR_COMPUTER_PLAYER_ACTIONS, "GAME_CLEAR_COMPUTER_PLAYER_ACTIONS", NativeStub);
    RegisterNativeFunction(NATIVE_GET_FIRST_IN_CONTAINER,        "GET_FIRST_IN_CONTAINER",        NativeStub);
    RegisterNativeFunction(NATIVE_GET_NEXT_IN_CONTAINER,         "GET_NEXT_IN_CONTAINER",         NativeStub);
    RegisterNativeFunction(NATIVE_GET_TEMPLE_ENTRANCE_POSITION,  "GET_TEMPLE_ENTRANCE_POSITION",  NativeStub);
    RegisterNativeFunction(NATIVE_SAY_SOUND_EFFECT_PLAYING,      "SAY_SOUND_EFFECT_PLAYING",      NativeStub);
    RegisterNativeFunction(NATIVE_SET_HAND_DEMO_KEYS,            "SET_HAND_DEMO_KEYS",            NativeStub);
    RegisterNativeFunction(NATIVE_CAN_SKIP_TUTORIAL,             "CAN_SKIP_TUTORIAL",             NativeStub);
    RegisterNativeFunction(NATIVE_CAN_SKIP_CREATURE_TRAINING,    "CAN_SKIP_CREATURE_TRAINING",    NativeStub);
    RegisterNativeFunction(NATIVE_IS_KEEPING_OLD_CREATURE,       "IS_KEEPING_OLD_CREATURE",       NativeStub);
    RegisterNativeFunction(NATIVE_CURRENT_PROFILE_HAS_CREATURE,  "CURRENT_PROFILE_HAS_CREATURE",  NativeStub);
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
