// Living class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Living adds 179 virtual methods for AI reactions, animation state machines,
// and behavioral decision-making. Most are stubs in the base class — the real
// logic lives in Villager, Creature, and Animal overrides.

#include <black/Living.h>

// ============================================================================
// State / movement queries (vtable 0x874-0x8CC)
// ============================================================================

bool Living::AmILikelyToMove() { return false; }
void Living::SetFoodSpeedup(bool) {}
bool Living::IsFoodSpeedUp() { return false; }
uint32_t Living::GetNumTurnsToDieOver() { return 0; }
MapCoords* Living::GetFinalDestPos(MapCoords* out) { return out; }
bool Living::FleeingFromObjectReaction() { return false; }
bool Living::LookingAtObjectReaction() { return false; }
bool Living::FleeingAndLookingAtObjectReaction() { return false; }
bool Living::FollowingObjectReaction() { return false; }
bool Living::InspectObjectReaction() { return false; }
bool Living::Dying() { return false; }
bool Living::Dead() { return false; }
bool Living::Downed() { return false; }
bool Living::BeingEaten() { return false; }
bool Living::GotoFoodReaction() { return false; }
bool Living::GotoWoodReaction() { return false; }
bool Living::MoveInFlock() { return false; }
bool Living::IsMovingForAnimation() { return false; }
bool Living::ArrivesAtFoodReaction() { return false; }
bool Living::ArrivesAtWoodReaction() { return false; }
bool Living::InHand() { return false; }
bool Living::DecideWhatToDo() { return false; }
void Living::Birthday() {}

// ============================================================================
// Age and animation state machine (vtable 0x8D0-0x95C)
// ============================================================================

uint32_t Living::GetAge() { return 0; }
void Living::SetAge(uint32_t) {}
bool Living::LookAtFlyingObjectReaction() { return false; }
int Living::SetCurrentAndDestinationState(VILLAGER_STATES, VILLAGER_STATES) { return 0; }
int Living::CallIntoAnimationFunction(VILLAGER_STATES) { return 0; }
int Living::CallOutofAnimationFunction(VILLAGER_STATES) { return 0; }
int Living::SetTopState(VILLAGER_STATES) { return 0; }
void Living::StorePreviousState() {}
void Living::SetStateSpeed() {}
bool Living::IsFinalState(VILLAGER_STATES) { return false; }
void Living::SetAnim_2(int, int) {}
void Living::SetAnim_1(int) {}
ANIM_LIST Living::GetAnimId() { return ANM_INVALID; }
uint32_t Living::CallExitStateFunction(VILLAGER_STATES) { return 0; }
uint32_t Living::CallEntryStateFunction_2(VILLAGER_STATES, VILLAGER_STATES) { return 0; }
uint32_t Living::CallEntryStateFunction_1(VILLAGER_STATES) { return 0; }
int Living::ExitReaction(VILLAGER_STATES) { return 0; }
int Living::ExitInScript(VILLAGER_STATES) { return 0; }
int Living::ExitDanceInScript(VILLAGER_STATES) { return 0; }
int Living::ExitInHand(VILLAGER_STATES) { return 0; }
int Living::ExitInFlying(VILLAGER_STATES) { return 0; }
int Living::ExitInLanded(VILLAGER_STATES) { return 0; }
int Living::ExitNoChangeState(VILLAGER_STATES) { return 0; }
int Living::ExitMoveOnPath(VILLAGER_STATES) { return 0; }
int Living::ExitMoveToPos(uint8_t) { return 0; }
int Living::ExitBeingEaten(uint8_t) { return 0; }
void Living::SetState(LIVING_ACTION_INDEX, VILLAGER_STATES) {}
uint32_t Living::EnterMoveToPos(VILLAGER_STATES, VILLAGER_STATES) { return 0; }
uint32_t Living::EnterInScript(VILLAGER_STATES, VILLAGER_STATES) { return 0; }
uint32_t Living::EnterInHand(VILLAGER_STATES, VILLAGER_STATES) { return 0; }
uint32_t Living::EnterMoveOnPath(VILLAGER_STATES, VILLAGER_STATES) { return 0; }
uint32_t Living::EnterDanceInScript(VILLAGER_STATES, VILLAGER_STATES) { return 0; }
uint32_t Living::EnterScriptWander(VILLAGER_STATES, VILLAGER_STATES) { return 0; }
int Living::ExitScriptWander(VILLAGER_STATES) { return 0; }
uint32_t Living::EnterPlayAnim(VILLAGER_STATES, VILLAGER_STATES) { return 0; }
int Living::ExitPlayAnim(VILLAGER_STATES) { return 0; }

// ============================================================================
// State query predicates (vtable 0x960-0x98C)
// ============================================================================

bool Living::IsScriptState(VILLAGER_STATES) const { return false; }
bool Living::IsScriptInterruptableState(VILLAGER_STATES) const { return false; }
bool Living::IsStateForInterface(VILLAGER_STATES) const { return false; }
bool Living::IsStateExitFunctionSameAs(VILLAGER_STATES) const { return false; }
bool Living::IsDeathState(VILLAGER_STATES) const { return false; }
uint32_t Living::DebugShowTime(uint32_t, uint8_t, uint8_t) { return 0; }
bool Living::IsDancing() { return false; }
bool Living::IsInterestedInFoodObject(Object*) { return false; }
bool Living::IsInterestedInWoodObject(Object*) { return false; }
bool Living::IsAvailableForReaction(REACTION) { return false; }
bool Living::IsAvailableForBeliefButNotReaction(REACTION) { return false; }

// ============================================================================
// Reaction management (vtable 0x98C-0x9A0)
// ============================================================================

void Living::UpdateHowImpressed(Reaction*, int) {}
void Living::AddReaction(Reaction*, VILLAGER_STATES) {}
void Living::StartReacting(REACTION, GameThingWithPos*, Reaction*) {}
void Living::StopReacting() {}
void Living::StopReactingAndSetState() {}
void Living::ResetStateAfterReacting() {}

// ============================================================================
// Reaction setup (vtable 0x9A4-0xA28)
// ============================================================================

void Living::SetupFleeFromObject(GameThingWithPos*, Reaction*) {}
void Living::SetupLookAtObject(GameThingWithPos*, Reaction*) {}
void Living::SetupLookAtSpell(GameThingWithPos*, Reaction*) {}
void Living::SetupLookAtNiceSpell(GameThingWithPos*, Reaction*) {}
void Living::SetupFollowObject(GameThingWithPos*, Reaction*) {}
void Living::SetupReactToCreature(GameThingWithPos*, Reaction*) {}
void Living::SetupReactToFood(GameThingWithPos*, Reaction*) {}
void Living::SetupReactToWood(GameThingWithPos*, Reaction*) {}
void Living::SetupReactToMagicTree(GameThingWithPos*, Reaction*) {}
void Living::SetupReactToFlyingObject(GameThingWithPos*, Reaction*) {}
void Living::SetupReactToFire(GameThingWithPos*, Reaction*) {}
void Living::SetupReactToBall(GameThingWithPos*, Reaction*) {}
void Living::SetupReactToMagicShield(GameThingWithPos*, Reaction*) {}
void Living::SetupReactToCreatureGift(GameThingWithPos*, Reaction*) {}
void Living::SetupReactToNewBuilding(GameThingWithPos*, Reaction*) {}
void Living::SetupReactToHandPickUp(GameThingWithPos*, Reaction*) {}
void Living::SetupReactToHandUsingTotem(GameThingWithPos*, Reaction*) {}
void Living::SetupReactToObjectCrushed(GameThingWithPos*, Reaction*) {}
void Living::SetupReactToFight(GameThingWithPos*, Reaction*) {}
void Living::SetupReactToTeleport(GameThingWithPos*, Reaction*) {}
void Living::SetupReactToHandPuttingStuffInStoragePit(GameThingWithPos*, Reaction*) {}
void Living::SetupReactToDeath(GameThingWithPos*, Reaction*) {}
void Living::SetupReactToDroppedByHand(GameThingWithPos*, Reaction*) {}
void Living::SetupReactToFainting(GameThingWithPos*, Reaction*) {}
void Living::SetupReactToConfused(GameThingWithPos*, Reaction*) {}
void Living::SetupReactToFallingTree(GameThingWithPos*, Reaction*) {}
void Living::SetupReactToCrowd(GameThingWithPos*, Reaction*) {}
void Living::SetupReactToBreeder(GameThingWithPos*, Reaction*) {}
void Living::SetupFleeFromPredator(GameThingWithPos*, Reaction*) {}
void Living::SetupReactToTownCelebration(GameThingWithPos*, Reaction*) {}
void Living::SetupReactToVillagerInHand(GameThingWithPos*, Reaction*) {}
void Living::SetupReactToBurningObjectInHand(GameThingWithPos*, Reaction*) {}
void Living::SetupReactToMagicShieldStruck(GameThingWithPos*, Reaction*) {}
void Living::SetupReactToMagicShieldDestroyed(GameThingWithPos*, Reaction*) {}

// ============================================================================
// Reaction priority (vtable 0xA30-0xABC)
// All return 0 (lowest priority) in base class
// ============================================================================

uint8_t Living::FleeFromObjectPriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::LookAtObjectPriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::FollowObjectPriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::FleeFromSpellPriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::LookAtSpellPriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::LookAtNiceSpellPriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::FollowSpellPriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::ReactToCreaturePriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::ReactToFoodPriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::ReactToWoodPriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::ReactToMagicTreePriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::ReactToFlyingObjectPriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::ReactToBallPriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::ReactToFirePriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::ReactToMagicShieldPriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::ReactToCreatureGiftPriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::ReactToNewBuildingPriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::ReactToHandPickUpPriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::ReactToHandUsingTotemPriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::ReactToObjectCrushedPriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::ReactToFightPriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::ReactToTeleportPriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::ReactToHandPuttingStuffInStoragePitPriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::ReactToDeathPriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::ReactToDroppedByHandPriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::ReactToFaintingPriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::ReactToConfusedPriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::ReactToFallingTreePriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::ReactToCrowdPriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::ReactToBreederPriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::ReactToTownCelebrationPriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::FleeFromPredatorPriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::ReactToVillagerInHandPriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::ReactToBurningObjectInHandPriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::ReactToMagicShieldStruckPriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::ReactToMagicShieldDestroyedPriority(Reaction*, Reaction*) { return 0; }
uint8_t Living::ReactToScaffoldPriority(Reaction*, Reaction*) { return 0; }

// ============================================================================
// Reaction timing (vtable 0xAC0-0xAEC)
// ============================================================================

uint32_t Living::StandardNumGameTurnsToReactFunction(GameThingWithPos*, uint32_t, float) { return 0; }
uint32_t Living::StandardNumGameTurnsBeforeReactingAgainFunction(GameThingWithPos*, uint32_t, float) { return 0; }
uint32_t Living::NumGameTurnsToReactToCreatureFunction(GameThingWithPos*, uint32_t, float) { return 0; }
uint32_t Living::NumGameTurnsBeforeReactingAgainToCreatureFunction(GameThingWithPos*, uint32_t, float) { return 0; }
uint32_t Living::NumGameTurnsToReactToPredatorFunction(GameThingWithPos*, uint32_t, float) { return 0; }
uint32_t Living::NumGameTurnsBeforeReactingAgainToPredatorFunction(GameThingWithPos*, uint32_t, float) { return 0; }
uint32_t Living::StandardNumGameTurnsBeforeReactingToWoodAgainFunction(GameThingWithPos*, uint32_t, float) { return 0; }
uint32_t Living::NumGameTurnsToReactToBurningObjectFunction(GameThingWithPos*, uint32_t, float) { return 0; }
uint32_t Living::NumGameTurnsBeforeReactingAgainToBurningObjectFunction(GameThingWithPos*, uint32_t, float) { return 0; }
uint32_t Living::NumGameTurnsToReactToShieldFunction(GameThingWithPos*, uint32_t, float) { return 0; }
uint32_t Living::NumGameTurnsBeforeReactingToShieldAgainFunction(GameThingWithPos*, uint32_t, float) { return 0; }
uint32_t Living::IsPosValidForMapCellExistance(const MapCoords*) { return 0; }

// ============================================================================
// Miscellaneous (vtable 0xAF0-0xB3C)
// ============================================================================

void Living::MoveByTeleport(const MapCoords*) {}
bool Living::IsDead() { return false; }
bool Living::IsChild() { return false; }
void Living::GetFleeingPositionFromMovingObject(MapCoords*, GameThingWithPos*, float) {}
void Living::GetFleeingPositionFromStationaryObject(MapCoords*, GameThingWithPos*, float) {}
VILLAGER_STATES Living::GetFinalState() const { return VILLAGER_STATE_INVALID_STATE; }
void Living::RemoveFromDance(int) {}
void Living::SetStateAfterFinishingDance() {}
float Living::CalculateLifeDesire() { return 0.0f; }
uint32_t Living::DanceType() { return 0; }
bool Living::CanBeHealedByHealSpell() { return false; }
bool Living::MoveAllowedForChessGame() { return false; }
bool Living::AttackAllowedForChessGame() { return false; }
void Living::AddToBoxPositionForChessGame(int, int) {}
int Living::GetBoxXForChessGame() { return 0; }
int Living::GetBoxZForChessGame() { return 0; }
void Living::SetBoxXForChessGame(int) {}
void Living::SetBoxZForChessGame(int) {}
uint32_t Living::GetTeamForChessGame() { return 0; }
bool Living::IsPosValidForTurnAngle(const MapCoords*) { return false; }
