#pragma once
// LHVM — Lionhead Virtual Machine bytecode interpreter
// This is the scripting engine that executes CHL (Challenge) files.
// CHL files contain compiled bytecode with:
//   - Global variables
//   - Script definitions (entry points)
//   - Instructions (31 opcodes)
//   - Auto-start scripts
//   - Data section (string constants)
//
// The LHVM is embedded inside GScript and accessed through ScriptDLL callbacks.
// Native function table: 465 entries (indices 0-464), sourced from openblack CHLApi.

#include <cstdint>
#include <cstdio>

// VM Opcodes (31 total, from CHL bytecode spec)
enum VMOpcode : uint32_t {
    OP_END         = 0,   // End script execution
    OP_WAIT        = 1,   // Wait for N ticks
    OP_PUSH        = 2,   // Push value onto stack
    OP_POP         = 3,   // Pop value from stack
    OP_ADD         = 4,   // Add top two stack values
    OP_CALL        = 5,   // Call native function
    OP_MINUS       = 6,   // Subtract
    OP_UMINUS      = 7,   // Unary minus
    OP_TIMES       = 8,   // Multiply
    OP_DIVIDE      = 9,   // Divide
    OP_MODULUS     = 10,  // Modulo
    OP_NOT         = 11,  // Logical NOT
    OP_AND         = 12,  // Logical AND
    OP_OR          = 13,  // Logical OR
    OP_EQ          = 14,  // Equal
    OP_NEQ         = 15,  // Not equal
    OP_GEQ         = 16,  // Greater or equal
    OP_LEQ         = 17,  // Less or equal
    OP_GT          = 18,  // Greater than
    OP_LT          = 19,  // Less than
    OP_JUMP        = 20,  // Unconditional jump
    OP_SLEEP       = 21,  // Sleep for N seconds
    OP_EXCEPT      = 22,  // Exception handler
    OP_CAST        = 23,  // Type cast
    OP_RUN         = 24,  // Run a script
    OP_ENDEXCEPT   = 25,  // End exception handler
    OP_RETEXCEPT   = 26,  // Return from exception
    OP_FAILEXCEPT  = 27,  // Fail exception
    OP_BRKEXCEPT   = 28,  // Break from exception
    OP_SWAP        = 29,  // Swap top two stack values
    OP_LINE        = 30,  // Line number (debug)
    _VM_OPCODE_COUNT = 31
};

// VM data types
enum VMType : uint32_t {
    VM_TYPE_NONE    = 0,
    VM_TYPE_INT     = 1,
    VM_TYPE_FLOAT   = 2,
    VM_TYPE_VECTOR  = 3,
    VM_TYPE_OBJECT  = 4,
    VM_TYPE_BOOLEAN = 5,
    _VM_TYPE_COUNT  = 6
};

// Script type tags
enum VMScriptType : uint32_t {
    VM_SCRIPT_TYPE_HELP       = 0,
    VM_SCRIPT_TYPE_CHALLENGE  = 1,
    VM_SCRIPT_TYPE_HIGHLIGHT  = 2,
    VM_SCRIPT_TYPE_SPELL      = 3,
    VM_SCRIPT_TYPE_DIALOGUE   = 4,
    _VM_SCRIPT_TYPE_COUNT     = 5
};

// Native function indices (465 total, 0-464)
// Sourced from openblack CHLApi — matches original B&W 1.0 function dispatch table
enum NativeFunction : uint32_t {
    NATIVE_NONE                                             = 0,
    NATIVE_SET_CAMERA_POSITION                              = 1,
    NATIVE_SET_CAMERA_FOCUS                                 = 2,
    NATIVE_MOVE_CAMERA_POSITION                             = 3,
    NATIVE_MOVE_CAMERA_FOCUS                                = 4,
    NATIVE_GET_CAMERA_POSITION                              = 5,
    NATIVE_GET_CAMERA_FOCUS                                 = 6,
    NATIVE_SPIRIT_EJECT                                     = 7,
    NATIVE_SPIRIT_HOME                                      = 8,
    NATIVE_SPIRIT_POINT_POS                                 = 9,
    NATIVE_SPIRIT_POINT_GAME_THING                          = 10,
    NATIVE_GAME_THING_FIELD_OF_VIEW                         = 11,
    NATIVE_POS_FIELD_OF_VIEW                                = 12,
    NATIVE_RUN_TEXT                                          = 13,
    NATIVE_TEMP_TEXT                                         = 14,
    NATIVE_TEXT_READ                                         = 15,
    NATIVE_GAME_THING_CLICKED                               = 16,
    NATIVE_SET_SCRIPT_STATE                                  = 17,
    NATIVE_SET_SCRIPT_STATE_POS                              = 18,
    NATIVE_SET_SCRIPT_FLOAT                                  = 19,
    NATIVE_SET_SCRIPT_ULONG                                  = 20,
    NATIVE_GET_PROPERTY                                      = 21,
    NATIVE_SET_PROPERTY                                      = 22,
    NATIVE_GET_POSITION                                      = 23,
    NATIVE_SET_POSITION                                      = 24,
    NATIVE_GET_DISTANCE                                      = 25,
    NATIVE_CALL                                              = 26,
    NATIVE_CREATE                                            = 27,
    NATIVE_RANDOM                                            = 28,
    NATIVE_DLL_GETTIME                                       = 29,
    NATIVE_START_CAMERA_CONTROL                              = 30,
    NATIVE_END_CAMERA_CONTROL                                = 31,
    NATIVE_SET_WIDESCREEN                                    = 32,
    NATIVE_MOVE_GAME_THING                                   = 33,
    NATIVE_SET_FOCUS                                         = 34,
    NATIVE_HAS_CAMERA_ARRIVED                                = 35,
    NATIVE_FLOCK_CREATE                                      = 36,
    NATIVE_FLOCK_ATTACH                                      = 37,
    NATIVE_FLOCK_DETACH                                      = 38,
    NATIVE_FLOCK_DISBAND                                     = 39,
    NATIVE_ID_SIZE                                           = 40,
    NATIVE_FLOCK_MEMBER                                      = 41,
    NATIVE_GET_HAND_POSITION                                 = 42,
    NATIVE_PLAY_SOUND_EFFECT                                 = 43,
    NATIVE_START_MUSIC                                       = 44,
    NATIVE_STOP_MUSIC                                        = 45,
    NATIVE_ATTACH_MUSIC                                      = 46,
    NATIVE_DETACH_MUSIC                                      = 47,
    NATIVE_OBJECT_DELETE                                      = 48,
    NATIVE_FOCUS_FOLLOW                                      = 49,
    NATIVE_POSITION_FOLLOW                                   = 50,
    NATIVE_CALL_NEAR                                         = 51,
    NATIVE_SPECIAL_EFFECT_POSITION                           = 52,
    NATIVE_SPECIAL_EFFECT_OBJECT                             = 53,
    NATIVE_DANCE_CREATE                                      = 54,
    NATIVE_CALL_IN                                           = 55,
    NATIVE_CHANGE_INNER_OUTER_PROPERTIES                     = 56,
    NATIVE_SNAPSHOT                                          = 57,
    NATIVE_GET_ALIGNMENT                                     = 58,
    NATIVE_SET_ALIGNMENT                                     = 59,
    NATIVE_INFLUENCE_OBJECT                                  = 60,
    NATIVE_INFLUENCE_POSITION                                = 61,
    NATIVE_GET_INFLUENCE                                     = 62,
    NATIVE_SET_INTERFACE_INTERACTION                          = 63,
    NATIVE_PLAYED                                            = 64,
    NATIVE_RANDOM_ULONG                                      = 65,
    NATIVE_SET_GAMESPEED                                     = 66,
    NATIVE_CALL_IN_NEAR                                      = 67,
    NATIVE_OVERRIDE_STATE_ANIMATION                          = 68,
    NATIVE_CREATURE_CREATE_RELATIVE_TO_CREATURE              = 69,
    NATIVE_CREATURE_LEARN_EVERYTHING                         = 70,
    NATIVE_CREATURE_SET_KNOWS_ACTION                         = 71,
    NATIVE_CREATURE_SET_AGENDA_PRIORITY                      = 72,
    NATIVE_CREATURE_TURN_OFF_ALL_DESIRES                     = 73,
    NATIVE_CREATURE_LEARN_DISTINCTION_ABOUT_ACTIVITY_OBJECT  = 74,
    NATIVE_CREATURE_DO_ACTION                                = 75,
    NATIVE_IN_CREATURE_HAND                                  = 76,
    NATIVE_CREATURE_SET_DESIRE_VALUE                         = 77,
    NATIVE_CREATURE_SET_DESIRE_ACTIVATED_78                   = 78,
    NATIVE_CREATURE_SET_DESIRE_ACTIVATED_79                   = 79,
    NATIVE_CREATURE_SET_DESIRE_MAXIMUM                       = 80,
    NATIVE_CONVERT_CAMERA_POSITION                           = 81,
    NATIVE_CONVERT_CAMERA_FOCUS                              = 82,
    NATIVE_CREATURE_SET_PLAYER                               = 83,
    NATIVE_START_COUNTDOWN_TIMER                             = 84,
    NATIVE_CREATURE_INITIALISE_NUM_TIMES_PERFORMED_ACTION    = 85,
    NATIVE_CREATURE_GET_NUM_TIMES_ACTION_PERFORMED           = 86,
    NATIVE_REMOVE_COUNTDOWN_TIMER                            = 87,
    NATIVE_GET_OBJECT_DROPPED                                = 88,
    NATIVE_CLEAR_DROPPED_BY_OBJECT                           = 89,
    NATIVE_CREATE_REACTION                                   = 90,
    NATIVE_REMOVE_REACTION                                   = 91,
    NATIVE_GET_COUNTDOWN_TIMER                               = 92,
    NATIVE_START_DUAL_CAMERA                                 = 93,
    NATIVE_UPDATE_DUAL_CAMERA                                = 94,
    NATIVE_RELEASE_DUAL_CAMERA                               = 95,
    NATIVE_SET_CREATURE_HELP                                 = 96,
    NATIVE_GET_TARGET_OBJECT                                 = 97,
    NATIVE_CREATURE_DESIRE_IS                                = 98,
    NATIVE_COUNTDOWN_TIMER_EXISTS                            = 99,
    NATIVE_LOOK_GAME_THING                                   = 100,
    NATIVE_GET_OBJECT_DESTINATION                            = 101,
    NATIVE_CREATURE_FORCE_FINISH                             = 102,
    NATIVE_HIDE_COUNTDOWN_TIMER                              = 103,
    NATIVE_GET_ACTION_TEXT_FOR_OBJECT                         = 104,
    NATIVE_CREATE_DUAL_CAMERA_WITH_POINT                     = 105,
    NATIVE_SET_CAMERA_TO_FACE_OBJECT                         = 106,
    NATIVE_MOVE_CAMERA_TO_FACE_OBJECT                        = 107,
    NATIVE_GET_MOON_PERCENTAGE                               = 108,
    NATIVE_POPULATE_CONTAINER                                 = 109,
    NATIVE_ADD_REFERENCE                                     = 110,
    NATIVE_REMOVE_REFERENCE                                  = 111,
    NATIVE_SET_GAME_TIME                                     = 112,
    NATIVE_GET_GAME_TIME                                     = 113,
    NATIVE_GET_REAL_TIME                                     = 114,
    NATIVE_GET_REAL_DAY_115                                   = 115,
    NATIVE_GET_REAL_DAY_116                                   = 116,
    NATIVE_GET_REAL_MONTH                                    = 117,
    NATIVE_GET_REAL_YEAR                                     = 118,
    NATIVE_RUN_CAMERA_PATH                                   = 119,
    NATIVE_START_DIALOGUE                                    = 120,
    NATIVE_END_DIALOGUE                                      = 121,
    NATIVE_IS_DIALOGUE_READY                                 = 122,
    NATIVE_CHANGE_WEATHER_PROPERTIES                         = 123,
    NATIVE_CHANGE_LIGHTNING_PROPERTIES                        = 124,
    NATIVE_CHANGE_TIME_FADE_PROPERTIES                       = 125,
    NATIVE_CHANGE_CLOUD_PROPERTIES                           = 126,
    NATIVE_SET_HEADING_AND_SPEED                             = 127,
    NATIVE_START_GAME_SPEED                                  = 128,
    NATIVE_END_GAME_SPEED                                    = 129,
    NATIVE_BUILD_BUILDING                                    = 130,
    NATIVE_SET_AFFECTED_BY_WIND                              = 131,
    NATIVE_WIDESCREEN_TRANSISTION_FINISHED                   = 132,
    NATIVE_GET_RESOURCE                                      = 133,
    NATIVE_ADD_RESOURCE                                      = 134,
    NATIVE_REMOVE_RESOURCE                                   = 135,
    NATIVE_GET_TARGET_RELATIVE_POS                           = 136,
    NATIVE_STOP_POINTING                                     = 137,
    NATIVE_STOP_LOOKING                                      = 138,
    NATIVE_LOOK_AT_POSITION                                  = 139,
    NATIVE_PLAY_SPIRIT_ANIM                                  = 140,
    NATIVE_CALL_IN_NOT_NEAR                                  = 141,
    NATIVE_SET_CAMERA_ZONE                                   = 142,
    NATIVE_GET_OBJECT_STATE                                  = 143,
    NATIVE_REVEAL_COUNTDOWN_TIMER                            = 144,
    NATIVE_SET_TIMER_TIME                                    = 145,
    NATIVE_CREATE_TIMER                                      = 146,
    NATIVE_GET_TIMER_TIME_REMAINING                          = 147,
    NATIVE_GET_TIMER_TIME_SINCE_SET                          = 148,
    NATIVE_MOVE_MUSIC                                        = 149,
    NATIVE_GET_INCLUSION_DISTANCE                            = 150,
    NATIVE_GET_LAND_HEIGHT                                   = 151,
    NATIVE_LOAD_MAP                                          = 152,
    NATIVE_STOP_ALL_SCRIPTS_EXCLUDING                        = 153,
    NATIVE_STOP_ALL_SCRIPTS_IN_FILES_EXCLUDING               = 154,
    NATIVE_STOP_SCRIPT                                       = 155,
    NATIVE_CLEAR_CLICKED_OBJECT                              = 156,
    NATIVE_CLEAR_CLICKED_POSITION                            = 157,
    NATIVE_POSITION_CLICKED                                  = 158,
    NATIVE_RELEASE_FROM_SCRIPT                               = 159,
    NATIVE_GET_OBJECT_HAND_IS_OVER                           = 160,
    NATIVE_ID_POISONED_SIZE                                  = 161,
    NATIVE_IS_POISONED                                       = 162,
    NATIVE_CALL_POISONED_IN                                  = 163,
    NATIVE_CALL_NOT_POISONED_IN                              = 164,
    NATIVE_SPIRIT_PLAYED                                     = 165,
    NATIVE_CLING_SPIRIT                                      = 166,
    NATIVE_FLY_SPIRIT                                        = 167,
    NATIVE_SET_ID_MOVEABLE                                   = 168,
    NATIVE_SET_ID_PICKUPABLE                                 = 169,
    NATIVE_IS_ON_FIRE                                        = 170,
    NATIVE_IS_FIRE_NEAR                                      = 171,
    NATIVE_STOP_SCRIPTS_IN_FILES                             = 172,
    NATIVE_SET_POISONED                                      = 173,
    NATIVE_SET_TEMPERATURE                                   = 174,
    NATIVE_SET_ON_FIRE                                       = 175,
    NATIVE_SET_TARGET                                        = 176,
    NATIVE_WALK_PATH                                         = 177,
    NATIVE_FOCUS_AND_POSITION_FOLLOW                         = 178,
    NATIVE_GET_WALK_PATH_PERCENTAGE                          = 179,
    NATIVE_CAMERA_PROPERTIES                                 = 180,
    NATIVE_ENABLE_DISABLE_MUSIC                              = 181,
    NATIVE_GET_MUSIC_OBJ_DISTANCE                            = 182,
    NATIVE_GET_MUSIC_ENUM_DISTANCE                           = 183,
    NATIVE_SET_MUSIC_PLAY_POSITION                           = 184,
    NATIVE_ATTACH_OBJECT_LEASH_TO_OBJECT                     = 185,
    NATIVE_ATTACH_OBJECT_LEASH_TO_HAND                       = 186,
    NATIVE_DETACH_OBJECT_LEASH                               = 187,
    NATIVE_SET_CREATURE_ONLY_DESIRE                          = 188,
    NATIVE_SET_CREATURE_ONLY_DESIRE_OFF                      = 189,
    NATIVE_RESTART_MUSIC                                     = 190,
    NATIVE_MUSIC_PLAYED_191                                   = 191,
    NATIVE_IS_OF_TYPE                                        = 192,
    NATIVE_CLEAR_HIT_OBJECT                                  = 193,
    NATIVE_GAME_THING_HIT                                    = 194,
    NATIVE_SPELL_AT_THING                                    = 195,
    NATIVE_SPELL_AT_POS                                      = 196,
    NATIVE_CALL_PLAYER_CREATURE                              = 197,
    NATIVE_GET_SLOWEST_SPEED                                 = 198,
    NATIVE_GET_OBJECT_HELD_199                                = 199,
    NATIVE_HELP_SYSTEM_ON                                    = 200,
    NATIVE_SHAKE_CAMERA                                      = 201,
    NATIVE_SET_ANIMATION_MODIFY                              = 202,
    NATIVE_SET_AVI_SEQUENCE                                  = 203,
    NATIVE_PLAY_GESTURE                                      = 204,
    NATIVE_DEV_FUNCTION                                      = 205,
    NATIVE_HAS_MOUSE_WHEEL                                   = 206,
    NATIVE_NUM_MOUSE_BUTTONS                                 = 207,
    NATIVE_SET_CREATURE_DEV_STAGE                            = 208,
    NATIVE_SET_FIXED_CAM_ROTATION                            = 209,
    NATIVE_SWAP_CREATURE                                     = 210,
    NATIVE_GET_ARENA                                         = 211,
    NATIVE_GET_FOOTBALL_PITCH                                = 212,
    NATIVE_STOP_ALL_GAMES                                    = 213,
    NATIVE_ATTACH_TO_GAME                                    = 214,
    NATIVE_DETACH_FROM_GAME                                  = 215,
    NATIVE_DETACH_UNDEFINED_FROM_GAME                        = 216,
    NATIVE_SET_ONLY_FOR_SCRIPTS                              = 217,
    NATIVE_START_MATCH_WITH_REFEREE                          = 218,
    NATIVE_GAME_TEAM_SIZE                                    = 219,
    NATIVE_GAME_TYPE                                         = 220,
    NATIVE_GAME_SUB_TYPE                                     = 221,
    NATIVE_IS_LEASHED                                        = 222,
    NATIVE_SET_CREATURE_HOME                                 = 223,
    NATIVE_GET_HIT_OBJECT                                    = 224,
    NATIVE_GET_OBJECT_WHICH_HIT                              = 225,
    NATIVE_GET_NEAREST_TOWN_OF_PLAYER                        = 226,
    NATIVE_SPELL_AT_POINT                                    = 227,
    NATIVE_SET_ATTACK_OWN_TOWN                               = 228,
    NATIVE_IS_FIGHTING                                       = 229,
    NATIVE_SET_MAGIC_RADIUS                                  = 230,
    NATIVE_TEMP_TEXT_WITH_NUMBER                              = 231,
    NATIVE_RUN_TEXT_WITH_NUMBER                               = 232,
    NATIVE_CREATURE_SPELL_REVERSION                          = 233,
    NATIVE_GET_DESIRE                                        = 234,
    NATIVE_GET_EVENTS_PER_SECOND                             = 235,
    NATIVE_GET_TIME_SINCE                                    = 236,
    NATIVE_GET_TOTAL_EVENTS                                  = 237,
    NATIVE_UPDATE_SNAPSHOT                                   = 238,
    NATIVE_CREATE_REWARD                                     = 239,
    NATIVE_CREATE_REWARD_IN_TOWN                             = 240,
    NATIVE_SET_FADE                                          = 241,
    NATIVE_SET_FADE_IN                                       = 242,
    NATIVE_FADE_FINISHED                                     = 243,
    NATIVE_SET_PLAYER_MAGIC                                  = 244,
    NATIVE_HAS_PLAYER_MAGIC                                  = 245,
    NATIVE_SPIRIT_SPEAKS                                     = 246,
    NATIVE_BELIEF_FOR_PLAYER                                 = 247,
    NATIVE_GET_HELP                                          = 248,
    NATIVE_SET_LEASH_WORKS                                   = 249,
    NATIVE_LOAD_MY_CREATURE                                  = 250,
    NATIVE_OBJECT_RELATIVE_BELIEF                            = 251,
    NATIVE_CREATE_WITH_ANGLE_AND_SCALE                       = 252,
    NATIVE_SET_HELP_SYSTEM                                   = 253,
    NATIVE_SET_VIRTUAL_INFLUENCE                             = 254,
    NATIVE_SET_ACTIVE                                        = 255,
    NATIVE_THING_VALID                                       = 256,
    NATIVE_VORTEX_FADE_OUT                                   = 257,
    NATIVE_REMOVE_REACTION_OF_TYPE                           = 258,
    NATIVE_CREATURE_LEARN_EVERYTHING_EXCLUDING               = 259,
    NATIVE_PLAYED_PERCENTAGE                                 = 260,
    NATIVE_OBJECT_CAST_BY_OBJECT                             = 261,
    NATIVE_IS_WIND_MAGIC_AT_POS                              = 262,
    NATIVE_CREATE_MIST                                       = 263,
    NATIVE_SET_MIST_FADE                                     = 264,
    NATIVE_GET_OBJECT_FADE                                   = 265,
    NATIVE_PLAY_HAND_DEMO                                    = 266,
    NATIVE_IS_PLAYING_HAND_DEMO                              = 267,
    NATIVE_GET_ARSE_POSITION                                 = 268,
    NATIVE_IS_LEASHED_TO_OBJECT                              = 269,
    NATIVE_GET_INTERACTION_MAGNITUDE                         = 270,
    NATIVE_IS_CREATURE_AVAILABLE                             = 271,
    NATIVE_CREATE_HIGHLIGHT                                  = 272,
    NATIVE_GET_OBJECT_HELD_273                                = 273,
    NATIVE_GET_ACTION_COUNT                                  = 274,
    NATIVE_GET_OBJECT_LEASH_TYPE                             = 275,
    NATIVE_SET_FOCUS_FOLLOW                                  = 276,
    NATIVE_SET_POSITION_FOLLOW                               = 277,
    NATIVE_SET_FOCUS_AND_POSITION_FOLLOW                     = 278,
    NATIVE_SET_CAMERA_LENS                                   = 279,
    NATIVE_MOVE_CAMERA_LENS                                  = 280,
    NATIVE_CREATURE_REACTION                                 = 281,
    NATIVE_CREATURE_IN_DEV_SCRIPT                            = 282,
    NATIVE_STORE_CAMERA_DETAILS                              = 283,
    NATIVE_RESTORE_CAMERA_DETAILS                            = 284,
    NATIVE_START_ANGLE_SOUND_285                              = 285,
    NATIVE_SET_CAMERA_POS_FOC_LENS                           = 286,
    NATIVE_MOVE_CAMERA_POS_FOC_LENS                          = 287,
    NATIVE_GAME_TIME_ON_OFF                                  = 288,
    NATIVE_MOVE_GAME_TIME                                    = 289,
    NATIVE_SET_HIGH_GRAPHICS_DETAIL                          = 290,
    NATIVE_SET_SKELETON                                      = 291,
    NATIVE_IS_SKELETON                                       = 292,
    NATIVE_PLAYER_SPELL_CAST_TIME                            = 293,
    NATIVE_PLAYER_SPELL_LAST_CAST                            = 294,
    NATIVE_GET_LAST_SPELL_CAST_POS                           = 295,
    NATIVE_ADD_SPOT_VISUAL_TARGET_POS                        = 296,
    NATIVE_ADD_SPOT_VISUAL_TARGET_OBJECT                     = 297,
    NATIVE_SET_INDESTRUCTABLE                                = 298,
    NATIVE_SET_GRAPHICS_CLIPPING                             = 299,
    NATIVE_SPIRIT_APPEAR                                     = 300,
    NATIVE_SPIRIT_DISAPPEAR                                  = 301,
    NATIVE_SET_FOCUS_ON_OBJECT                               = 302,
    NATIVE_RELEASE_OBJECT_FOCUS                              = 303,
    NATIVE_IMMERSION_EXISTS                                  = 304,
    NATIVE_SET_DRAW_LEASH                                    = 305,
    NATIVE_SET_DRAW_HIGHLIGHT                                = 306,
    NATIVE_SET_OPEN_CLOSE                                    = 307,
    NATIVE_SET_INTRO_BUILDING                                = 308,
    NATIVE_CREATURE_FORCE_FRIENDS                            = 309,
    NATIVE_MOVE_COMPUTER_PLAYER_POSITION                     = 310,
    NATIVE_ENABLE_DISABLE_COMPUTER_PLAYER_311                 = 311,
    NATIVE_GET_COMPUTER_PLAYER_POSITION                      = 312,
    NATIVE_SET_COMPUTER_PLAYER_POSITION                      = 313,
    NATIVE_GET_STORED_CAMERA_POSITION                        = 314,
    NATIVE_GET_STORED_CAMERA_FOCUS                           = 315,
    NATIVE_CALL_NEAR_IN_STATE                                = 316,
    NATIVE_SET_CREATURE_SOUND                                = 317,
    NATIVE_CREATURE_INTERACTING_WITH                         = 318,
    NATIVE_SET_SUN_DRAW                                      = 319,
    NATIVE_OBJECT_INFO_BITS                                  = 320,
    NATIVE_SET_HURT_BY_FIRE                                  = 321,
    NATIVE_CONFINED_OBJECT                                   = 322,
    NATIVE_CLEAR_CONFINED_OBJECT                             = 323,
    NATIVE_GET_OBJECT_FLOCK                                  = 324,
    NATIVE_SET_PLAYER_BELIEF                                 = 325,
    NATIVE_PLAY_JC_SPECIAL                                   = 326,
    NATIVE_IS_PLAYING_JC_SPECIAL                             = 327,
    NATIVE_VORTEX_PARAMETERS                                 = 328,
    NATIVE_LOAD_CREATURE                                     = 329,
    NATIVE_IS_SPELL_CHARGING                                 = 330,
    NATIVE_IS_THAT_SPELL_CHARGING                            = 331,
    NATIVE_OPPOSING_CREATURE                                 = 332,
    NATIVE_FLOCK_WITHIN_LIMITS                               = 333,
    NATIVE_HIGHLIGHT_PROPERTIES                              = 334,
    NATIVE_LAST_MUSIC_LINE                                   = 335,
    NATIVE_HAND_DEMO_TRIGGER                                 = 336,
    NATIVE_GET_BELLY_POSITION                                = 337,
    NATIVE_SET_CREATURE_CREED_PROPERTIES                     = 338,
    NATIVE_GAME_THING_CAN_VIEW_CAMERA                        = 339,
    NATIVE_GAME_PLAY_SAY_SOUND_EFFECT                        = 340,
    NATIVE_SET_TOWN_DESIRE_BOOST                             = 341,
    NATIVE_IS_LOCKED_INTERACTION                             = 342,
    NATIVE_SET_CREATURE_NAME                                 = 343,
    NATIVE_COMPUTER_PLAYER_READY                             = 344,
    NATIVE_ENABLE_DISABLE_COMPUTER_PLAYER_345                 = 345,
    NATIVE_CLEAR_ACTOR_MIND                                  = 346,
    NATIVE_ENTER_EXIT_CITADEL                                = 347,
    NATIVE_START_ANGLE_SOUND_348                              = 348,
    NATIVE_THING_JC_SPECIAL                                  = 349,
    NATIVE_MUSIC_PLAYED_350                                   = 350,
    NATIVE_UPDATE_SNAPSHOT_PICTURE                            = 351,
    NATIVE_STOP_SCRIPTS_IN_FILES_EXCLUDING                   = 352,
    NATIVE_CREATE_RANDOM_VILLAGER_OF_TRIBE                   = 353,
    NATIVE_TOGGLE_LEASH                                      = 354,
    NATIVE_GAME_SET_MANA                                     = 355,
    NATIVE_SET_MAGIC_PROPERTIES                              = 356,
    NATIVE_SET_GAME_SOUND                                    = 357,
    NATIVE_SEX_IS_MALE                                       = 358,
    NATIVE_GET_FIRST_HELP                                    = 359,
    NATIVE_GET_LAST_HELP                                     = 360,
    NATIVE_IS_ACTIVE                                         = 361,
    NATIVE_SET_BOOKMARK_POSITION                             = 362,
    NATIVE_SET_SCAFFOLD_PROPERTIES                           = 363,
    NATIVE_SET_COMPUTER_PLAYER_PERSONALITY                   = 364,
    NATIVE_SET_COMPUTER_PLAYER_SUPPRESSION                   = 365,
    NATIVE_FORCE_COMPUTER_PLAYER_ACTION                      = 366,
    NATIVE_QUEUE_COMPUTER_PLAYER_ACTION                      = 367,
    NATIVE_GET_TOWN_WITH_ID                                  = 368,
    NATIVE_SET_DISCIPLE                                      = 369,
    NATIVE_RELEASE_COMPUTER_PLAYER                           = 370,
    NATIVE_SET_COMPUTER_PLAYER_SPEED                         = 371,
    NATIVE_SET_FOCUS_FOLLOW_COMPUTER_PLAYER                  = 372,
    NATIVE_SET_POSITION_FOLLOW_COMPUTER_PLAYER               = 373,
    NATIVE_CALL_COMPUTER_PLAYER                              = 374,
    NATIVE_CALL_BUILDING_IN_TOWN                             = 375,
    NATIVE_SET_CAN_BUILD_WORSHIPSITE                         = 376,
    NATIVE_GET_FACING_CAMERA_POSITION                        = 377,
    NATIVE_SET_COMPUTER_PLAYER_ATTITUDE                      = 378,
    NATIVE_GET_COMPUTER_PLAYER_ATTITUDE                      = 379,
    NATIVE_LOAD_COMPUTER_PLAYER_PERSONALITY                  = 380,
    NATIVE_SAVE_COMPUTER_PLAYER_PERSONALITY                  = 381,
    NATIVE_SET_PLAYER_ALLY                                   = 382,
    NATIVE_CALL_FLYING                                       = 383,
    NATIVE_SET_OBJECT_FADE_IN                                = 384,
    NATIVE_IS_AFFECTED_BY_SPELL                              = 385,
    NATIVE_SET_MAGIC_IN_OBJECT                               = 386,
    NATIVE_ID_ADULT_SIZE                                     = 387,
    NATIVE_OBJECT_CAPACITY                                   = 388,
    NATIVE_OBJECT_ADULT_CAPACITY                             = 389,
    NATIVE_SET_CREATURE_AUTO_FIGHTING                        = 390,
    NATIVE_IS_AUTO_FIGHTING                                  = 391,
    NATIVE_SET_CREATURE_QUEUE_FIGHT_MOVE                     = 392,
    NATIVE_SET_CREATURE_QUEUE_FIGHT_SPELL                    = 393,
    NATIVE_SET_CREATURE_QUEUE_FIGHT_STEP                     = 394,
    NATIVE_GET_CREATURE_FIGHT_ACTION                         = 395,
    NATIVE_CREATURE_FIGHT_QUEUE_HITS                         = 396,
    NATIVE_SQUARE_ROOT                                       = 397,
    NATIVE_GET_PLAYER_ALLY                                   = 398,
    NATIVE_SET_PLAYER_WIND_RESISTANCE                        = 399,
    NATIVE_GET_PLAYER_WIND_RESISTANCE                        = 400,
    NATIVE_PAUSE_UNPAUSE_CLIMATE_SYSTEM                      = 401,
    NATIVE_PAUSE_UNPAUSE_STORM_CREATION_IN_CLIMATE_SYSTEM    = 402,
    NATIVE_GET_MANA_FOR_SPELL                                = 403,
    NATIVE_KILL_STORMS_IN_AREA                               = 404,
    NATIVE_INSIDE_TEMPLE                                     = 405,
    NATIVE_RESTART_OBJECT                                    = 406,
    NATIVE_SET_GAME_TIME_PROPERTIES                          = 407,
    NATIVE_RESET_GAME_TIME_PROPERTIES                        = 408,
    NATIVE_SOUND_EXISTS                                      = 409,
    NATIVE_GET_TOWN_WORSHIP_DEATHS                           = 410,
    NATIVE_GAME_CLEAR_DIALOGUE                               = 411,
    NATIVE_GAME_CLOSE_DIALOGUE                               = 412,
    NATIVE_GET_HAND_STATE                                    = 413,
    NATIVE_SET_INTERFACE_CITADEL                              = 414,
    NATIVE_MAP_SCRIPT_FUNCTION                               = 415,
    NATIVE_WITHIN_ROTATION                                   = 416,
    NATIVE_GET_PLAYER_TOWN_TOTAL                             = 417,
    NATIVE_SPIRIT_SCREEN_POINT                               = 418,
    NATIVE_KEY_DOWN                                          = 419,
    NATIVE_SET_FIGHT_EXIT                                    = 420,
    NATIVE_GET_OBJECT_CLICKED                                = 421,
    NATIVE_GET_MANA                                          = 422,
    NATIVE_CLEAR_PLAYER_SPELL_CHARGING                       = 423,
    NATIVE_STOP_SOUND_EFFECT                                 = 424,
    NATIVE_GET_TOTEM_STATUE                                  = 425,
    NATIVE_SET_SET_ON_FIRE                                   = 426,
    NATIVE_SET_LAND_BALANCE                                  = 427,
    NATIVE_SET_OBJECT_BELIEF_SCALE                           = 428,
    NATIVE_START_IMMERSION                                   = 429,
    NATIVE_STOP_IMMERSION                                    = 430,
    NATIVE_STOP_ALL_IMMERSION                                = 431,
    NATIVE_SET_CREATURE_IN_TEMPLE                            = 432,
    NATIVE_GAME_DRAW_TEXT                                     = 433,
    NATIVE_GAME_DRAW_TEMP_TEXT                                = 434,
    NATIVE_FADE_ALL_DRAW_TEXT                                 = 435,
    NATIVE_SET_DRAW_TEXT_COLOUR                               = 436,
    NATIVE_SET_CLIPPING_WINDOW                               = 437,
    NATIVE_CLEAR_CLIPPING_WINDOW                             = 438,
    NATIVE_SAVE_GAME_IN_SLOT                                 = 439,
    NATIVE_SET_OBJECT_CARRYING                               = 440,
    NATIVE_POS_VALID_FOR_CREATURE                            = 441,
    NATIVE_GET_TIME_SINCE_OBJECT_ATTACKED                    = 442,
    NATIVE_GET_TOWN_AND_VILLAGER_HEALTH_TOTAL                = 443,
    NATIVE_GAME_ADD_FOR_BUILDING                             = 444,
    NATIVE_ENABLE_DISABLE_ALIGNMENT_MUSIC                    = 445,
    NATIVE_GET_DEAD_LIVING                                   = 446,
    NATIVE_ATTACH_SOUND_TAG                                  = 447,
    NATIVE_DETACH_SOUND_TAG                                  = 448,
    NATIVE_GET_SACRIFICE_TOTAL                               = 449,
    NATIVE_GAME_SOUND_PLAYING                                = 450,
    NATIVE_GET_TEMPLE_POSITION                               = 451,
    NATIVE_CREATURE_AUTOSCALE                                = 452,
    NATIVE_GET_SPELL_ICON_IN_TEMPLE                          = 453,
    NATIVE_GAME_CLEAR_COMPUTER_PLAYER_ACTIONS                = 454,
    NATIVE_GET_FIRST_IN_CONTAINER                            = 455,
    NATIVE_GET_NEXT_IN_CONTAINER                             = 456,
    NATIVE_GET_TEMPLE_ENTRANCE_POSITION                      = 457,
    NATIVE_SAY_SOUND_EFFECT_PLAYING                          = 458,
    NATIVE_SET_HAND_DEMO_KEYS                                = 459,
    NATIVE_CAN_SKIP_TUTORIAL                                 = 460,
    NATIVE_CAN_SKIP_CREATURE_TRAINING                        = 461,
    NATIVE_IS_KEEPING_OLD_CREATURE                           = 462,
    NATIVE_CURRENT_PROFILE_HAS_CREATURE                      = 463,
    _NATIVE_FUNCTION_COUNT                                   = 464
};

// A single bytecode instruction
struct VMInstruction {
    VMOpcode  opcode;      // 0x00 — which operation
    uint32_t  mode;        // 0x04 — addressing mode
    VMType    data_type;   // 0x08 — type of operand
    union {
        int32_t  int_val;
        float    float_val;
        uint32_t uint_val;
    };                     // 0x0C — immediate value
    uint32_t  line_number; // 0x10 — source line (debug)
};
static_assert(sizeof(VMInstruction) == 0x14, "VMInstruction size mismatch");

// A script definition (entry point in the CHL)
struct VMScript {
    char      name[256];        // 0x000 — script name
    char      filename[256];    // 0x100 — source filename
    VMScriptType script_type;   // 0x200 — what kind of script
    uint32_t  global_count;     // 0x204 — number of local variables
    uint32_t  instruction_addr; // 0x208 — IP of first instruction
    uint32_t  param_count;      // 0x20C — number of parameters
    uint32_t  script_id;        // 0x210 — unique ID
};

// A VM stack value
struct VMStackValue {
    VMType   type;
    union {
        int32_t  int_val;
        float    float_val;
        uint32_t uint_val;
    };
};

// A running script task
struct VMTask {
    uint32_t     task_id;              // unique task ID
    uint32_t     script_id;            // which script this task runs
    uint32_t     ip;                   // instruction pointer
    uint32_t     wait_ticks;           // ticks to wait (OP_WAIT)
    float        sleep_seconds;        // seconds to sleep (OP_SLEEP)
    bool         waiting;              // is waiting
    bool         sleeping;             // is sleeping
    bool         finished;             // has ended
    VMStackValue stack[256];           // operand stack
    uint32_t     stack_top;            // top of stack
    float*       local_vars;           // local variable storage
    uint32_t     local_var_count;      // number of locals
    uint32_t     exception_handler_ip; // IP of exception handler
    VMTask*      prev;                 // linked list
    VMTask*      next;                 // linked list
};

// CHL file header
struct CHLHeader {
    char     magic[4];       // "LHVM"
    uint32_t version;        // format version
};

// Forward declare
struct LHVM;

// Native function callback signature — receives VM pointer, reads args from stack
typedef void (*NativeFunctionPtr)(LHVM* vm);

// Native function table entry
struct NativeFunctionEntry {
    const char*       name;     // function name (e.g., "SET_CAMERA_POSITION")
    NativeFunctionPtr func;     // implementation (nullptr = unimplemented stub)
};

// The virtual machine state
struct LHVM {
    // CHL data
    VMInstruction*  instructions;      // instruction array
    uint32_t        instruction_count; // total instructions
    VMScript*       scripts;           // script definitions
    uint32_t        script_count;      // total scripts
    char*           data_section;      // string constants
    uint32_t        data_size;         // data section size
    float*          global_vars;       // global variables
    uint32_t        global_var_count;  // total globals
    uint32_t*       auto_start_scripts; // script IDs to auto-start
    uint32_t        auto_start_count;  // count of auto-starts

    // Runtime state
    VMTask*         first_task;        // linked list of running tasks
    VMTask*         last_task;
    uint32_t        next_task_id;      // ID counter for new tasks
    uint32_t        tick_count;        // game ticks processed
    VMTask*         current_task;      // task currently being executed (for native callbacks)

    // Native function dispatch table (465 entries)
    NativeFunctionEntry native_functions[_NATIVE_FUNCTION_COUNT];

    // Methods
    bool LoadBinary(const char* path);
    void FreeBinary();
    uint32_t StartScript(const char* name);
    uint32_t StartScriptByID(uint32_t script_id);
    void StopTask(uint32_t task_id);
    void StopAllTasks();
    void ProcessTick();

    // Native function registration
    void InitNativeFunctions();
    void RegisterNativeFunction(NativeFunction id, const char* name, NativeFunctionPtr func);

    // Stack operations (for native function implementations)
    void PushInt(int32_t value);
    void PushFloat(float value);
    void PushObject(uint32_t object_id);
    void PushBoolean(bool value);
    int32_t PopInt();
    float PopFloat();
    uint32_t PopObject();
    bool PopBoolean();
    VMStackValue PopValue();

    // Data section access
    const char* GetString(uint32_t offset);

private:
    void ExecuteTask(VMTask* task);
    VMTask* CreateTask(uint32_t script_id);
    void DestroyTask(VMTask* task);
};
