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
    VILLAGER_STATE_DYING = 10,
    VILLAGER_STATE_DEAD = 11,
    VILLAGER_STATE_DOWNED = 12,
    VILLAGER_STATE_BEING_EATEN = 13,
    VILLAGER_STATE_GOTO_FOOD_REACTION = 14,
    VILLAGER_STATE_ARRIVES_AT_FOOD_REACTION = 15,
    VILLAGER_STATE_GOTO_WOOD_REACTION = 16,
    VILLAGER_STATE_ARRIVES_AT_WOOD_REACTION = 17,
    VILLAGER_STATE_IN_HAND = 18,
    // ... remaining values through 254
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
};
static_assert(sizeof(Living) == 0xE0, "Living size mismatch");
