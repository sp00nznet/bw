#pragma once
// Living — animate entity that can move, react, and die
// Struct layout from bw1-decomp
//
// Size: 0xE0 bytes (inherits 0x8C from MobileWallHug)
// Vtable: 0xB40 bytes (extends MobileWallHug's 0x874 with 179 new methods)
//
// Living is the base for Villager, Animal, and Creature — entities that
// are "alive" in the game world with AI reactions, pathfinding, and animation.

#include "MobileWallHug.h"

// Forward declarations
struct DanceGroup;
struct DataForScriptRemind;
struct DataPath;
struct Flock;
struct GFootpathNode;
struct ReactionDoneWhen;

// ============================================================================
// Enums required by the Living vtable
// ============================================================================

// Villager state machine states (0-254, plus 255 sentinel)
// Full list in bw1-decomp's chlasm/GStates.h
// v1.0's 256 villager states, from chlasm's GStates.h (CC0). The numbers are
// the index into the state function table (0xC2A2C8) and into
// DETAIL_VILLAGER_STATE_TABLE_INFO; both agree with these names (85 Created,
// 163 DecideWhatToDo). The enum this replaces had 47 entries, numbered wrongly.
enum VILLAGER_STATES : uint32_t {
    VILLAGER_STATE_INVALID_STATE = 0,
    VILLAGER_STATE_MOVE_TO_POS = 1,
    VILLAGER_STATE_MOVE_TO_OBJECT = 2,
    VILLAGER_STATE_MOVE_ON_STRUCTURE = 3,
    VILLAGER_STATE_IN_SCRIPT = 4,
    VILLAGER_STATE_IN_DANCE = 5,
    VILLAGER_STATE_FLEEING_FROM_OBJECT_REACTION = 6,
    VILLAGER_STATE_LOOKING_AT_OBJECT_REACTION = 7,
    VILLAGER_STATE_FOLLOWING_OBJECT_REACTION = 8,
    VILLAGER_STATE_INSPECT_OBJECT_REACTION = 9,
    VILLAGER_STATE_FLYING = 10,
    VILLAGER_STATE_LANDED = 11,
    VILLAGER_STATE_LOOK_AT_FLYING_OBJECT_REACTION = 12,
    VILLAGER_STATE_SET_DYING = 13,
    VILLAGER_STATE_DYING = 14,
    VILLAGER_STATE_DEAD = 15,
    VILLAGER_STATE_DROWNING = 16,
    VILLAGER_STATE_DOWNED = 17,
    VILLAGER_STATE_BEING_EATEN = 18,
    VILLAGER_STATE_GOTO_FOOD_REACTION = 19,
    VILLAGER_STATE_ARRIVES_AT_FOOD_REACTION = 20,
    VILLAGER_STATE_GOTO_WOOD_REACTION = 21,
    VILLAGER_STATE_ARRIVES_AT_WOOD_REACTION = 22,
    VILLAGER_STATE_WAIT_FOR_ANIMATION = 23,
    VILLAGER_STATE_IN_HAND = 24,
    VILLAGER_STATE_GOTO_PICKUP_BALL_REACTION = 25,
    VILLAGER_STATE_ARRIVES_AT_PICKUP_BALL_REACTION = 26,
    VILLAGER_STATE_MOVE_IN_FLOCK = 27,
    VILLAGER_STATE_MOVE_ALONG_PATH = 28,
    VILLAGER_STATE_MOVE_ON_PATH = 29,
    VILLAGER_STATE_FLEEING_AND_LOOKING_AT_OBJECT_REACTION = 30,
    VILLAGER_STATE_GOTO_STORAGE_PIT_FOR_DROP_OFF = 31,
    VILLAGER_STATE_ARRIVES_AT_STORAGE_PIT_FOR_DROP_OFF = 32,
    VILLAGER_STATE_GOTO_STORAGE_PIT_FOR_FOOD = 33,
    VILLAGER_STATE_ARRIVES_AT_STORAGE_PIT_FOR_FOOD = 34,
    VILLAGER_STATE_ARRIVES_AT_HOME_WITH_FOOD = 35,
    VILLAGER_STATE_GO_HOME = 36,
    VILLAGER_STATE_ARRIVES_HOME = 37,
    VILLAGER_STATE_AT_HOME = 38,
    VILLAGER_STATE_ARRIVES_AT_STORAGE_PIT_FOR_BUILDING_MATERIALS = 39,
    VILLAGER_STATE_ARRIVES_AT_BUILDING_SITE = 40,
    VILLAGER_STATE_BUILDING = 41,
    VILLAGER_STATE_GOTO_STORAGE_PIT_FOR_WORSHIP_SUPPLIES = 42,
    VILLAGER_STATE_ARRIVES_AT_STORAGE_PIT_FOR_WORSHIP_SUPPLIES = 43,
    VILLAGER_STATE_GOTO_WORSHIP_SITE_WITH_SUPPLIES = 44,
    VILLAGER_STATE_MOVE_TO_WORSHIP_SITE_WITH_SUPPLIES = 45,
    VILLAGER_STATE_ARRIVES_AT_WORSHIP_SITE_WITH_SUPPLIES = 46,
    VILLAGER_STATE_FORESTER_MOVE_TO_FOREST = 47,
    VILLAGER_STATE_FORESTER_GOTO_FOREST = 48,
    VILLAGER_STATE_FORESTER_ARRIVES_AT_FOREST = 49,
    VILLAGER_STATE_FORESTER_CHOPS_TREE = 50,
    VILLAGER_STATE_FORESTER_CHOPS_TREE_FOR_BUILDING = 51,
    VILLAGER_STATE_FORESTER_FINISHED_FORESTERING = 52,
    VILLAGER_STATE_ARRIVES_AT_BIG_FOREST = 53,
    VILLAGER_STATE_ARRIVES_AT_BIG_FOREST_FOR_BUILDING = 54,
    VILLAGER_STATE_FISHERMAN_ARRIVES_AT_FISHING = 55,
    VILLAGER_STATE_FISHING = 56,
    VILLAGER_STATE_WAIT_FOR_COUNTER = 57,
    VILLAGER_STATE_GOTO_WORSHIP_SITE_FOR_WORSHIP = 58,
    VILLAGER_STATE_ARRIVES_AT_WORSHIP_SITE_FOR_WORSHIP = 59,
    VILLAGER_STATE_WORSHIPPING_AT_WORSHIP_SITE = 60,
    VILLAGER_STATE_GOTO_ALTAR_FOR_REST = 61,
    VILLAGER_STATE_ARRIVES_AT_ALTAR_FOR_REST = 62,
    VILLAGER_STATE_AT_ALTAR_REST = 63,
    VILLAGER_STATE_AT_ALTAR_FINISHED_REST = 64,
    VILLAGER_STATE_RESTART_WORSHIPPING_AT_WORSHIP_SITE = 65,
    VILLAGER_STATE_RESTART_WORSHIPPING_CREATURE = 66,
    VILLAGER_STATE_FARMER_ARRIVES_AT_FARM = 67,
    VILLAGER_STATE_FARMER_PLANTS_CROP = 68,
    VILLAGER_STATE_FARMER_DIGS_UP_CROP = 69,
    VILLAGER_STATE_MOVE_TO_FOOTBALL_PITCH_CONSTRUCTION = 70,
    VILLAGER_STATE_FOOTBALL_WALK_TO_POSITION = 71,
    VILLAGER_STATE_FOOTBALL_WAIT_FOR_KICK_OFF = 72,
    VILLAGER_STATE_FOOTBALL_ATTACKER = 73,
    VILLAGER_STATE_FOOTBALL_GOALIE = 74,
    VILLAGER_STATE_FOOTBALL_DEFENDER = 75,
    VILLAGER_STATE_FOOTBALL_WON_GOAL = 76,
    VILLAGER_STATE_FOOTBALL_LOST_GOAL = 77,
    VILLAGER_STATE_START_MOVE_TO_PICK_UP_BALL_FOR_DEAD_BALL = 78,
    VILLAGER_STATE_ARRIVED_AT_PICK_UP_BALL_FOR_DEAD_BALL = 79,
    VILLAGER_STATE_ARRIVED_AT_PUT_DOWN_BALL_FOR_DEAD_BALL_START = 80,
    VILLAGER_STATE_ARRIVED_AT_PUT_DOWN_BALL_FOR_DEAD_BALL_END = 81,
    VILLAGER_STATE_FOOTBALL_MATCH_PAUSED = 82,
    VILLAGER_STATE_FOOTBALL_WATCH_MATCH = 83,
    VILLAGER_STATE_FOOTBALL_MEXICAN_WAVE = 84,
    VILLAGER_STATE_CREATED = 85,
    VILLAGER_STATE_ARRIVES_IN_ABODE_TO_TRADE = 86,
    VILLAGER_STATE_ARRIVES_IN_ABODE_TO_PICK_UP_EXCESS = 87,
    VILLAGER_STATE_MAKE_SCARED_STIFF = 88,
    VILLAGER_STATE_SCARED_STIFF = 89,
    VILLAGER_STATE_WORSHIPPING_CREATURE = 90,
    VILLAGER_STATE_SHEPHERD_LOOK_FOR_FLOCK = 91,
    VILLAGER_STATE_SHEPHERD_MOVE_FLOCK_TO_WATER = 92,
    VILLAGER_STATE_SHEPHERD_MOVE_FLOCK_TO_FOOD = 93,
    VILLAGER_STATE_SHEPHERD_MOVE_FLOCK_BACK = 94,
    VILLAGER_STATE_SHEPHERD_DECIDE_WHAT_TO_DO_WITH_FLOCK = 95,
    VILLAGER_STATE_SHEPHERD_WAIT_FOR_FLOCK = 96,
    VILLAGER_STATE_SHEPHERD_SLAUGHTER_ANIMAL = 97,
    VILLAGER_STATE_SHEPHERD_FETCH_STRAY = 98,
    VILLAGER_STATE_SHEPHERD_GOTO_FLOCK = 99,
    VILLAGER_STATE_HOUSEWIFE_AT_HOME = 100,
    VILLAGER_STATE_HOUSEWIFE_GOTO_STORAGE_PIT = 101,
    VILLAGER_STATE_HOUSEWIFE_ARRIVES_AT_STORAGE_PIT = 102,
    VILLAGER_STATE_HOUSEWIFE_PICKUP_FROM_STORAGE_PIT = 103,
    VILLAGER_STATE_HOUSEWIFE_RETURN_HOME_WITH_FOOD = 104,
    VILLAGER_STATE_HOUSEWIFE_MAKE_DINNER = 105,
    VILLAGER_STATE_HOUSEWIFE_SERVES_DINNER = 106,
    VILLAGER_STATE_HOUSEWIFE_CLEARS_AWAY_DINNER = 107,
    VILLAGER_STATE_HOUSEWIFE_DOES_HOUSEWORK = 108,
    VILLAGER_STATE_HOUSEWIFE_GOSSIPS_AROUND_STORAGE_PIT = 109,
    VILLAGER_STATE_HOUSEWIFE_STARTS_GIVING_BIRTH = 110,
    VILLAGER_STATE_HOUSEWIFE_GIVING_BIRTH = 111,
    VILLAGER_STATE_HOUSEWIFE_GIVEN_BIRTH = 112,
    VILLAGER_STATE_CHILD_AT_CRECHE = 113,
    VILLAGER_STATE_CHILD_FOLLOWS_MOTHER = 114,
    VILLAGER_STATE_CHILD_BECOMES_ADULT = 115,
    VILLAGER_STATE_SITS_DOWN_TO_DINNER = 116,
    VILLAGER_STATE_EAT_FOOD = 117,
    VILLAGER_STATE_EAT_FOOD_AT_HOME = 118,
    VILLAGER_STATE_GOTO_BED_AT_HOME = 119,
    VILLAGER_STATE_SLEEPING_AT_HOME = 120,
    VILLAGER_STATE_WAKE_UP_AT_HOME = 121,
    VILLAGER_STATE_START_HAVING_SEX = 122,
    VILLAGER_STATE_HAVING_SEX = 123,
    VILLAGER_STATE_STOP_HAVING_SEX = 124,
    VILLAGER_STATE_START_HAVING_SEX_AT_HOME = 125,
    VILLAGER_STATE_HAVING_SEX_AT_HOME = 126,
    VILLAGER_STATE_STOP_HAVING_SEX_AT_HOME = 127,
    VILLAGER_STATE_WAIT_FOR_DINNER = 128,
    VILLAGER_STATE_HOMELESS_START = 129,
    VILLAGER_STATE_VAGRANT_START = 130,
    VILLAGER_STATE_MORN_DEATH = 131,
    VILLAGER_STATE_PERFORM_INSPECTION_REACTION = 132,
    VILLAGER_STATE_APPROACH_OBJECT_REACTION = 133,
    VILLAGER_STATE_INITIALISE_TELL_OTHERS_ABOUT_OBJECT = 134,
    VILLAGER_STATE_TELL_OTHERS_ABOUT_INTERESTING_OBJECT = 135,
    VILLAGER_STATE_APPROACH_VILLAGER_TO_TALK_TO = 136,
    VILLAGER_STATE_TELL_PARTICULAR_VILLAGER_ABOUT_OBJECT = 137,
    VILLAGER_STATE_INITIALISE_LOOK_AROUND_FOR_VILLAGER_TO_TELL = 138,
    VILLAGER_STATE_LOOK_AROUND_FOR_VILLAGER_TO_TELL = 139,
    VILLAGER_STATE_MOVE_TOWARDS_OBJECT_TO_LOOK_AT = 140,
    VILLAGER_STATE_INITIALISE_IMPRESSED_REACTION = 141,
    VILLAGER_STATE_PERFORM_IMPRESSED_REACTION = 142,
    VILLAGER_STATE_INITIALISE_FIGHT_REACTION = 143,
    VILLAGER_STATE_PERFORM_FIGHT_REACTION = 144,
    VILLAGER_STATE_HOMELESS_EAT_DINNER = 145,
    VILLAGER_STATE_INSPECT_CREATURE_REACTION = 146,
    VILLAGER_STATE_PERFORM_INSPECT_CREATURE_REACTION = 147,
    VILLAGER_STATE_APPROACH_CREATURE_REACTION = 148,
    VILLAGER_STATE_INITIALISE_BEWILDERED_BY_MAGIC_TREE_REACTION = 149,
    VILLAGER_STATE_PERFORM_BEWILDERED_BY_MAGIC_TREE_REACTION = 150,
    VILLAGER_STATE_TURN_TO_FACE_MAGIC_TREE = 151,
    VILLAGER_STATE_LOOK_AT_MAGIC_TREE = 152,
    VILLAGER_STATE_DANCE_FOR_EDITING_PURPOSES = 153,
    VILLAGER_STATE_MOVE_TO_DANCE_POS = 154,
    VILLAGER_STATE_INITIALISE_RESPECT_CREATURE_REACTION = 155,
    VILLAGER_STATE_PERFORM_RESPECT_CREATURE_REACTION = 156,
    VILLAGER_STATE_FINISH_RESPECT_CREATURE_REACTION = 157,
    VILLAGER_STATE_APPROACH_HAND_REACTION = 158,
    VILLAGER_STATE_FLEEING_FROM_CREATURE_REACTION = 159,
    VILLAGER_STATE_TURN_TO_FACE_CREATURE_REACTION = 160,
    VILLAGER_STATE_WATCH_FLYING_OBJECT_REACTION = 161,
    VILLAGER_STATE_POINT_AT_FLYING_OBJECT_REACTION = 162,
    VILLAGER_STATE_DECIDE_WHAT_TO_DO = 163,
    VILLAGER_STATE_INTERACT_DECIDE_WHAT_TO_DO = 164,
    VILLAGER_STATE_EAT_OUTSIDE = 165,
    VILLAGER_STATE_RUN_AWAY_FROM_OBJECT_REACTION = 166,
    VILLAGER_STATE_MOVE_TOWARDS_CREATURE_REACTION = 167,
    VILLAGER_STATE_AMAZED_BY_MAGIC_SHIELD_REACTION = 168,
    VILLAGER_STATE_VILLAGER_GOSSIPS = 169,
    VILLAGER_STATE_CHECK_INTERACT_WITH_ANIMAL = 170,
    VILLAGER_STATE_CHECK_INTERACT_WITH_WORSHIP_SITE = 171,
    VILLAGER_STATE_CHECK_INTERACT_WITH_ABODE = 172,
    VILLAGER_STATE_CHECK_INTERACT_WITH_FIELD = 173,
    VILLAGER_STATE_CHECK_INTERACT_WITH_FISH_FARM = 174,
    VILLAGER_STATE_CHECK_INTERACT_WITH_TREE = 175,
    VILLAGER_STATE_CHECK_INTERACT_WITH_BALL = 176,
    VILLAGER_STATE_CHECK_INTERACT_WITH_POT = 177,
    VILLAGER_STATE_CHECK_INTERACT_WITH_FOOTBALL = 178,
    VILLAGER_STATE_CHECK_INTERACT_WITH_VILLAGER = 179,
    VILLAGER_STATE_CHECK_INTERACT_WITH_MAGIC_LIVING = 180,
    VILLAGER_STATE_CHECK_INTERACT_WITH_ROCK = 181,
    VILLAGER_STATE_ARRIVES_AT_ROCK_FOR_WOOD = 182,
    VILLAGER_STATE_GOT_WOOD_FROM_ROCK = 183,
    VILLAGER_STATE_REENTER_BUILDING_STATE = 184,
    VILLAGER_STATE_ARRIVE_AT_PUSH_OBJECT = 185,
    VILLAGER_STATE_TAKE_WOOD_FROM_TREE = 186,
    VILLAGER_STATE_TAKE_WOOD_FROM_POT = 187,
    VILLAGER_STATE_TAKE_WOOD_FROM_TREE_FOR_BUILDING = 188,
    VILLAGER_STATE_TAKE_WOOD_FROM_POT_FOR_BUILDING = 189,
    VILLAGER_STATE_SHEPHERD_TAKE_ANIMAL_FOR_SLAUGHTER = 190,
    VILLAGER_STATE_SHEPHERD_TAKES_CONTROL_OF_FLOCK = 191,
    VILLAGER_STATE_SHEPHERD_RELEASES_CONTROL_OF_FLOCK = 192,
    VILLAGER_STATE_DANCE_BUT_NOT_WORSHIP = 193,
    VILLAGER_STATE_FAINTING_REACTION = 194,
    VILLAGER_STATE_START_CONFUSED_REACTION = 195,
    VILLAGER_STATE_CONFUSED_REACTION = 196,
    VILLAGER_STATE_AFTER_TAP_ON_ABODE = 197,
    VILLAGER_STATE_WEAK_ON_GROUND = 198,
    VILLAGER_STATE_SCRIPT_WANDER_AROUND_POSITION = 199,
    VILLAGER_STATE_SCRIPT_PLAY_ANIM = 200,
    VILLAGER_STATE_GO_TOWARDS_TELEPORT_REACTION = 201,
    VILLAGER_STATE_TELEPORT_REACTION = 202,
    VILLAGER_STATE_DANCE_WHILE_REACTING = 203,
    VILLAGER_STATE_CONTROLLED_BY_CREATURE = 204,
    VILLAGER_STATE_POINT_AT_DEAD_PERSON = 205,
    VILLAGER_STATE_GO_TOWARDS_DEAD_PERSON = 206,
    VILLAGER_STATE_LOOK_AT_DEAD_PERSON = 207,
    VILLAGER_STATE_MOURN_DEAD_PERSON = 208,
    VILLAGER_STATE_NOTHING_TO_DO = 209,
    VILLAGER_STATE_ARRIVES_AT_WORKSHOP_FOR_DROP_OFF = 210,
    VILLAGER_STATE_ARRIVES_AT_STORAGE_PIT_FOR_WORKSHOP_MATERIALS = 211,
    VILLAGER_STATE_SHOW_POISONED = 212,
    VILLAGER_STATE_HIDING_AT_WORSHIP_SITE = 213,
    VILLAGER_STATE_CROWD_REACTION = 214,
    VILLAGER_STATE_REACT_TO_FIRE = 215,
    VILLAGER_STATE_PUT_OUT_FIRE_BY_BEATING = 216,
    VILLAGER_STATE_PUT_OUT_FIRE_WITH_WATER = 217,
    VILLAGER_STATE_GET_WATER_TO_PUT_OUT_FIRE = 218,
    VILLAGER_STATE_ON_FIRE = 219,
    VILLAGER_STATE_MOVE_AROUND_FIRE = 220,
    VILLAGER_STATE_DISCIPLE_NOTHING_TO_DO = 221,
    VILLAGER_STATE_FOOTBALL_MOVE_TO_BALL = 222,
    VILLAGER_STATE_ARRIVES_AT_STORAGE_PIT_FOR_TRADER_PICK_UP = 223,
    VILLAGER_STATE_ARRIVES_AT_STORAGE_PIT_FOR_TRADER_DROP_OFF = 224,
    VILLAGER_STATE_BREEDER_DISCIPLE = 225,
    VILLAGER_STATE_MISSIONARY_DISCIPLE = 226,
    VILLAGER_STATE_REACT_TO_BREEDER = 227,
    VILLAGER_STATE_SHEPHERD_CHECK_ANIMAL_FOR_SLAUGHTER = 228,
    VILLAGER_STATE_INTERACT_DECIDE_WHAT_TO_DO_FOR_OTHER_VILLAGER = 229,
    VILLAGER_STATE_ARTIFACT_DANCE = 230,
    VILLAGER_STATE_FLEEING_FROM_PREDATOR_REACTION = 231,
    VILLAGER_STATE_WAIT_FOR_WOOD = 232,
    VILLAGER_STATE_INSPECT_OBJECT = 233,
    VILLAGER_STATE_GO_HOME_AND_CHANGE = 234,
    VILLAGER_STATE_WAIT_FOR_MATE = 235,
    VILLAGER_STATE_GO_AND_HIDE_IN_NEARBY_BUILDING = 236,
    VILLAGER_STATE_LOOK_TO_SEE_IF_IT_IS_SAFE = 237,
    VILLAGER_STATE_SLEEP_IN_TENT = 238,
    VILLAGER_STATE_PAUSE_FOR_A_SECOND = 239,
    VILLAGER_STATE_PANIC_REACTION = 240,
    VILLAGER_STATE_GET_FOOD_AT_WORSHIP_SITE = 241,
    VILLAGER_STATE_GOTO_CONGREGATE_IN_TOWN_AFTER_EMERGENCY = 242,
    VILLAGER_STATE_CONGREGATE_IN_TOWN_AFTER_EMERGENCY = 243,
    VILLAGER_STATE_SCRIPT_IN_CROWD = 244,
    VILLAGER_STATE_GO_AND_CHILLOUT_OUTSIDE_HOME = 245,
    VILLAGER_STATE_SIT_AND_CHILLOUT = 246,
    VILLAGER_STATE_SCRIPT_GO_AND_MOVE_ALONG_PATH = 247,
    VILLAGER_STATE_GO_HOME_FROM_WORSHIP = 248,
    VILLAGER_STATE_ARRIVES_HOME_FROM_WORSHIP = 249,
    VILLAGER_STATE_SLEEP_IN_TENT_FROM_WORSHIP = 250,
    VILLAGER_STATE_GO_TOWARDS_TELEPORT_REACTION_QUICKLY = 251,
    VILLAGER_STATE_GO_AND_CHILLOUT_IN_TOWN = 252,
    VILLAGER_STATE_WAIT_FOR_ARTIFACT_DANCE = 253,
    VILLAGER_STATE_BREEDER_JUST_LANDED = 254,
    VILLAGER_STATE_LAST_STATE = 255,
};

// Index into LivingAction::states[] array
enum LIVING_ACTION_INDEX : uint32_t {
    LIVING_ACTION_INDEX_TOP = 0,
    LIVING_ACTION_INDEX_FINAL = 1,
    LIVING_ACTION_INDEX_PREVIOUS = 2,
    LIVING_ACTION_INDEX_COUNT = 3,
};

// Reaction types (-1 to 40)
// Full list in bw1-decomp's chlasm/Enum.h
enum REACTION : int32_t {
    REACTION_NONE = -1,
    REACTION_FLEE_FROM_OBJECT = 0,
    REACTION_LOOK_AT_OBJECT = 1,
    REACTION_FOLLOW_OBJECT = 2,
    REACTION_FLEE_FROM_SPELL = 3,
    REACTION_LOOK_AT_SPELL = 4,
    REACTION_FOLLOW_SPELL = 5,
    REACTION_REACT_TO_CREATURE = 6,
    REACTION_REACT_TO_FOOD = 7,
    REACTION_REACT_TO_MAGIC_TREE = 8,
    // ... remaining values through 40
    NUM_REACTION_FUNCTIONS = 41,
};

// Animation IDs (-4 to 470)
// Full list in bw1-decomp's chlasm/AllMeshes.h
enum ANIM_LIST : int32_t {
    ANM_DONT_DRAW = -4,
    ANM_NO_MOVE_ANIM_SET = -3,
    ANM_NO_ANIM_SET = -2,
    ANM_INVALID = -1,
    ANM_FIRST = 0,
    // ... remaining values through 470
    MAX_COUNT_3D_ANIMS = 471,
};

// ============================================================================
// LivingAction — 3-state action mini state machine
// ============================================================================

struct LivingAction {
    uint8_t top_state;      // 0x0 — states[LIVING_ACTION_INDEX_TOP]
    uint8_t final_state;    // 0x1 — states[LIVING_ACTION_INDEX_FINAL]
    uint8_t previous_state; // 0x2 — states[LIVING_ACTION_INDEX_PREVIOUS]
    uint8_t field_0x3;      // 0x3
    uint16_t turns_since_state_change; // 0x4
};
static_assert(sizeof(LivingAction) == 0x6, "LivingAction size mismatch");

// ============================================================================
// Living struct
// ============================================================================

struct Living : public MobileWallHug {
    // === Overrides of GameThing virtuals ===
    bool IsFunctional() override;

    // === Overrides of GameThingWithPos virtuals ===
    bool32_t IsSkeleton() const override;
    bool32_t IsPoisoned() override;
    void SetSkeleton(int index) override;
    bool IsStompable() override;
    bool32_t CanBeAttackedByCreature(Creature*) override;
    bool32_t CanBePlayedWithByCreature(Creature*) override;
    bool32_t CanBeStompedOnByCreature(Creature*) override;

    // === Overrides of Object virtuals ===
    void SetSpecularColor(LH3DColor color) override;
    LH3DColor GetSpecularColor() override;
    void SetPoisoned(int param1) override;
    bool CanBePickedUp() override;
    IMMERSION_EFFECT_TYPE GetInHandImmersionTexture() override;

    // === New virtual methods (vtable 0x874-0xB3C, 179 methods) ===

    // --- State / movement queries (0x874-0x8CC) ---
    virtual bool AmILikelyToMove();
    virtual void SetFoodSpeedup(bool speedup);
    virtual bool IsFoodSpeedUp();
    virtual uint32_t GetNumTurnsToDieOver();
    virtual MapCoords* GetFinalDestPos(MapCoords* out);
    virtual bool FleeingFromObjectReaction();
    virtual bool LookingAtObjectReaction();
    virtual bool FleeingAndLookingAtObjectReaction();
    virtual bool FollowingObjectReaction();
    virtual bool InspectObjectReaction();
    virtual bool Dying();
    virtual bool Dead();
    virtual bool Downed();
    virtual bool BeingEaten();
    virtual bool GotoFoodReaction();
    virtual bool GotoWoodReaction();
    virtual bool MoveInFlock();
    virtual bool IsMovingForAnimation();
    virtual bool ArrivesAtFoodReaction();
    virtual bool ArrivesAtWoodReaction();
    virtual bool InHand();
    virtual bool DecideWhatToDo();
    virtual void Birthday();

    // --- Age and animation state machine (0x8D0-0x95C) ---
    virtual uint32_t GetAge();
    virtual void SetAge(uint32_t age);
    virtual bool LookAtFlyingObjectReaction();
    virtual int SetCurrentAndDestinationState(VILLAGER_STATES current, VILLAGER_STATES destination);
    virtual int CallIntoAnimationFunction(VILLAGER_STATES state);
    virtual int CallOutofAnimationFunction(VILLAGER_STATES state);
    virtual int SetTopState(VILLAGER_STATES state);
    virtual void StorePreviousState();
    virtual void SetStateSpeed();
    virtual bool IsFinalState(VILLAGER_STATES state);
    virtual void SetAnim_2(int param1, int param2);
    virtual void SetAnim_1(int param1);
    virtual ANIM_LIST GetAnimId();
    virtual uint32_t CallExitStateFunction(VILLAGER_STATES state);
    virtual uint32_t CallEntryStateFunction_2(VILLAGER_STATES state1, VILLAGER_STATES state2);
    virtual uint32_t CallEntryStateFunction_1(VILLAGER_STATES state);
    virtual int ExitReaction(VILLAGER_STATES state);
    virtual int ExitInScript(VILLAGER_STATES state);
    virtual int ExitDanceInScript(VILLAGER_STATES state);
    virtual int ExitInHand(VILLAGER_STATES state);
    virtual int ExitInFlying(VILLAGER_STATES state);
    virtual int ExitInLanded(VILLAGER_STATES state);
    virtual int ExitNoChangeState(VILLAGER_STATES state);
    virtual int ExitMoveOnPath(VILLAGER_STATES state);
    virtual int ExitMoveToPos(uint8_t param1);
    virtual int ExitBeingEaten(uint8_t param1);
    virtual void SetState(LIVING_ACTION_INDEX index, VILLAGER_STATES state);
    virtual uint32_t EnterMoveToPos(VILLAGER_STATES state1, VILLAGER_STATES state2);
    virtual uint32_t EnterInScript(VILLAGER_STATES state1, VILLAGER_STATES state2);
    virtual uint32_t EnterInHand(VILLAGER_STATES state1, VILLAGER_STATES state2);
    virtual uint32_t EnterMoveOnPath(VILLAGER_STATES state1, VILLAGER_STATES state2);
    virtual uint32_t EnterDanceInScript(VILLAGER_STATES state1, VILLAGER_STATES state2);
    virtual uint32_t EnterScriptWander(VILLAGER_STATES state1, VILLAGER_STATES state2);
    virtual int ExitScriptWander(VILLAGER_STATES state);
    virtual uint32_t EnterPlayAnim(VILLAGER_STATES state1, VILLAGER_STATES state2);
    virtual int ExitPlayAnim(VILLAGER_STATES state);

    // --- State query predicates (0x960-0x98C) ---
    virtual bool IsScriptState(VILLAGER_STATES state) const;
    virtual bool IsScriptInterruptableState(VILLAGER_STATES state) const;
    virtual bool IsStateForInterface(VILLAGER_STATES state) const;
    virtual bool IsStateExitFunctionSameAs(VILLAGER_STATES state) const;
    virtual bool IsDeathState(VILLAGER_STATES state) const;
    virtual uint32_t DebugShowTime(uint32_t param1, uint8_t param2, uint8_t param3);
    virtual bool IsDancing();
    virtual bool IsInterestedInFoodObject(Object* object);
    virtual bool IsInterestedInWoodObject(Object* object);
    virtual bool IsAvailableForReaction(REACTION reaction);
    virtual bool IsAvailableForBeliefButNotReaction(REACTION reaction);

    // --- Reaction management (0x98C-0x9A0) ---
    virtual void UpdateHowImpressed(Reaction* param1, int param2);
    virtual void AddReaction(Reaction* reaction, VILLAGER_STATES state);
    virtual void StartReacting(REACTION type, GameThingWithPos* target, Reaction* reaction);
    virtual void StopReacting();
    virtual void StopReactingAndSetState();
    virtual void ResetStateAfterReacting();

    // --- Reaction setup (0x9A4-0xA28) ---
    virtual void SetupFleeFromObject(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupLookAtObject(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupLookAtSpell(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupLookAtNiceSpell(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupFollowObject(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupReactToCreature(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupReactToFood(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupReactToWood(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupReactToMagicTree(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupReactToFlyingObject(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupReactToFire(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupReactToBall(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupReactToMagicShield(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupReactToCreatureGift(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupReactToNewBuilding(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupReactToHandPickUp(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupReactToHandUsingTotem(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupReactToObjectCrushed(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupReactToFight(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupReactToTeleport(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupReactToHandPuttingStuffInStoragePit(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupReactToDeath(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupReactToDroppedByHand(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupReactToFainting(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupReactToConfused(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupReactToFallingTree(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupReactToCrowd(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupReactToBreeder(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupFleeFromPredator(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupReactToTownCelebration(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupReactToVillagerInHand(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupReactToBurningObjectInHand(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupReactToMagicShieldStruck(GameThingWithPos* param1, Reaction* param2);
    virtual void SetupReactToMagicShieldDestroyed(GameThingWithPos* param1, Reaction* param2);

    // --- Reaction priority (0xA30-0xABC) ---
    // Each returns priority (higher = more important) for this reaction type
    virtual uint8_t FleeFromObjectPriority(Reaction* param1, Reaction* param2);
    virtual uint8_t LookAtObjectPriority(Reaction* param1, Reaction* param2);
    virtual uint8_t FollowObjectPriority(Reaction* param1, Reaction* param2);
    virtual uint8_t FleeFromSpellPriority(Reaction* param1, Reaction* param2);
    virtual uint8_t LookAtSpellPriority(Reaction* param1, Reaction* param2);
    virtual uint8_t LookAtNiceSpellPriority(Reaction* param1, Reaction* param2);
    virtual uint8_t FollowSpellPriority(Reaction* param1, Reaction* param2);
    virtual uint8_t ReactToCreaturePriority(Reaction* param1, Reaction* param2);
    virtual uint8_t ReactToFoodPriority(Reaction* param1, Reaction* param2);
    virtual uint8_t ReactToWoodPriority(Reaction* param1, Reaction* param2);
    virtual uint8_t ReactToMagicTreePriority(Reaction* param1, Reaction* param2);
    virtual uint8_t ReactToFlyingObjectPriority(Reaction* param1, Reaction* param2);
    virtual uint8_t ReactToBallPriority(Reaction* param1, Reaction* param2);
    virtual uint8_t ReactToFirePriority(Reaction* param1, Reaction* param2);
    virtual uint8_t ReactToMagicShieldPriority(Reaction* param1, Reaction* param2);
    virtual uint8_t ReactToCreatureGiftPriority(Reaction* param1, Reaction* param2);
    virtual uint8_t ReactToNewBuildingPriority(Reaction* param1, Reaction* param2);
    virtual uint8_t ReactToHandPickUpPriority(Reaction* param1, Reaction* param2);
    virtual uint8_t ReactToHandUsingTotemPriority(Reaction* param1, Reaction* param2);
    virtual uint8_t ReactToObjectCrushedPriority(Reaction* param1, Reaction* param2);
    virtual uint8_t ReactToFightPriority(Reaction* param1, Reaction* param2);
    virtual uint8_t ReactToTeleportPriority(Reaction* param1, Reaction* param2);
    virtual uint8_t ReactToHandPuttingStuffInStoragePitPriority(Reaction* param1, Reaction* param2);
    virtual uint8_t ReactToDeathPriority(Reaction* param1, Reaction* param2);
    virtual uint8_t ReactToDroppedByHandPriority(Reaction* param1, Reaction* param2);
    virtual uint8_t ReactToFaintingPriority(Reaction* param1, Reaction* param2);
    virtual uint8_t ReactToConfusedPriority(Reaction* param1, Reaction* param2);
    virtual uint8_t ReactToFallingTreePriority(Reaction* param1, Reaction* param2);
    virtual uint8_t ReactToCrowdPriority(Reaction* param1, Reaction* param2);
    virtual uint8_t ReactToBreederPriority(Reaction* param1, Reaction* param2);
    virtual uint8_t ReactToTownCelebrationPriority(Reaction* param1, Reaction* param2);
    virtual uint8_t FleeFromPredatorPriority(Reaction* param1, Reaction* param2);
    virtual uint8_t ReactToVillagerInHandPriority(Reaction* param1, Reaction* param2);
    virtual uint8_t ReactToBurningObjectInHandPriority(Reaction* param1, Reaction* param2);
    virtual uint8_t ReactToMagicShieldStruckPriority(Reaction* param1, Reaction* param2);
    virtual uint8_t ReactToMagicShieldDestroyedPriority(Reaction* param1, Reaction* param2);
    virtual uint8_t ReactToScaffoldPriority(Reaction* param1, Reaction* param2);

    // --- Reaction timing (0xAC0-0xAEC) ---
    virtual uint32_t StandardNumGameTurnsToReactFunction(GameThingWithPos* param1, uint32_t param2, float param3);
    virtual uint32_t StandardNumGameTurnsBeforeReactingAgainFunction(GameThingWithPos* param1, uint32_t param2, float param3);
    virtual uint32_t NumGameTurnsToReactToCreatureFunction(GameThingWithPos* param1, uint32_t param2, float param3);
    virtual uint32_t NumGameTurnsBeforeReactingAgainToCreatureFunction(GameThingWithPos* param1, uint32_t param2, float param3);
    virtual uint32_t NumGameTurnsToReactToPredatorFunction(GameThingWithPos* param1, uint32_t param2, float param3);
    virtual uint32_t NumGameTurnsBeforeReactingAgainToPredatorFunction(GameThingWithPos* param1, uint32_t param2, float param3);
    virtual uint32_t StandardNumGameTurnsBeforeReactingToWoodAgainFunction(GameThingWithPos* param1, uint32_t param2, float param3);
    virtual uint32_t NumGameTurnsToReactToBurningObjectFunction(GameThingWithPos* param1, uint32_t param2, float param3);
    virtual uint32_t NumGameTurnsBeforeReactingAgainToBurningObjectFunction(GameThingWithPos* param1, uint32_t param2, float param3);
    virtual uint32_t NumGameTurnsToReactToShieldFunction(GameThingWithPos* param1, uint32_t param2, float param3);
    virtual uint32_t NumGameTurnsBeforeReactingToShieldAgainFunction(GameThingWithPos* param1, uint32_t param2, float param3);
    virtual uint32_t IsPosValidForMapCellExistance(const MapCoords* param1);

    // --- Miscellaneous (0xAF0-0xB3C) ---
    virtual void MoveByTeleport(const MapCoords* param1);
    virtual bool IsDead();
    virtual bool IsChild();
    virtual void GetFleeingPositionFromMovingObject(MapCoords* out, GameThingWithPos* param2, float param3);
    virtual void GetFleeingPositionFromStationaryObject(MapCoords* out, GameThingWithPos* param2, float param3);
    virtual VILLAGER_STATES GetFinalState() const;
    virtual void RemoveFromDance(int param1);
    virtual void SetStateAfterFinishingDance();
    virtual float CalculateLifeDesire();
    virtual uint32_t DanceType();
    virtual bool CanBeHealedByHealSpell();
    virtual bool MoveAllowedForChessGame();
    virtual bool AttackAllowedForChessGame();
    virtual void AddToBoxPositionForChessGame(int param1, int param2);
    virtual int GetBoxXForChessGame();
    virtual int GetBoxZForChessGame();
    virtual void SetBoxXForChessGame(int param1);
    virtual void SetBoxZForChessGame(int param1);
    virtual uint32_t GetTeamForChessGame();
    virtual bool IsPosValidForTurnAngle(const MapCoords* param1);

    // === Fields ===
    LivingAction action;                      // 0x8C — state machine
    uint16_t pad_0x92;                        // 0x92 — padding
    Reaction* reaction;                       // 0x94 — current reaction
    ReactionDoneWhen* reaction_done_when;     // 0x98
    int field_0x9c;                           // 0x9C
    int32_t birth_turn;                       // 0xA0 — game turn born
    Living* next;                             // 0xA4 — linked list
    uint32_t field_0xa8;                      // 0xA8
    DataPath* data_path;                      // 0xAC — pathfinding data
    DataForScriptRemind* data_for_script_remind; // 0xB0
    uint16_t status;                          // 0xB4 — status flags
    uint16_t pad_0xb6;                        // 0xB6 — padding
    Flock* flock;                             // 0xB8
    GameThingWithPos* field_0xbc;             // 0xBC
    uint32_t field_0xc0;                      // 0xC0
    uint32_t field_0xc4;                      // 0xC4
    GFootpath* living_footpath;               // 0xC8 — current footpath
    GFootpathNode* footpath_node;             // 0xCC — current node on path
    LH3DColor specular_color;                 // 0xD0
    uint32_t field_0xd4;                      // 0xD4
    DanceGroup* dance_group;                  // 0xD8
    uint8_t field_0xdc;                       // 0xDC
    uint8_t pad_0xdd[3];                      // 0xDD-0xDF — padding to 0xE0

    // Static methods
    static void ProcessLiving();              // 0x005ec810
};
static_assert(sizeof(Living) == 0xE0, "Living size mismatch");
