// Living class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Living adds 179 virtual methods for AI reactions, animation state machines,
// and behavioral decision-making. Most are stubs in the base class — the real
// logic lives in Villager, Creature, and Animal overrides.

#include <black/Living.h>
#include <black/ObjectInfo.h>
#include <black/Map.h>

extern GMap* g_map;

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

bool Living::IsFunctional() {
    // Original at 0x00413ed0: IsAvailable() && GetLife() != 0.0
    if (IsAvailable()) {
        if (GetLife() != 0.0f) {
            return true;
        }
    }
    return false;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

bool Living::IsStompable() {
    // Original at 0x00413ec0: calls vtable 0xaf0 (IsDead from Living), returns !IsDead
    return !IsDead();
}

bool32_t Living::CanBeAttackedByCreature(Creature* creature) {
    // Original at 0x00413f00: !IsDead() && info->canCreatureAttackMe && creature != this
    if (IsDead())
        return 0;
    if (info->canCreatureAttackMe && reinterpret_cast<void*>(creature) != reinterpret_cast<void*>(this))
        return 1;
    return 0;
}

bool32_t Living::CanBePlayedWithByCreature(Creature* /*creature*/) {
    // Original at 0x00413f40: !IsDead() && info->canCreaturePlayWithMe
    if (IsDead())
        return 0;
    return info->canCreaturePlayWithMe;
}

bool32_t Living::CanBeStompedOnByCreature(Creature* /*creature*/) {
    // Original at 0x00413fa0: !IsDead()
    return !IsDead() ? 1 : 0;
}

bool32_t Living::IsSkeleton() const {
    // Original at 0x00413e00: (status >> 6) & 1
    return (status >> 6) & 1;
}

bool32_t Living::IsPoisoned() {
    // Original at 0x00413dc0: (status >> 1) & 1
    return (status >> 1) & 1;
}

void Living::SetSkeleton(int value) {
    // Original at 0x00413e10: sets bit 6 of status field at 0xB4
    status = (static_cast<uint16_t>(value) & 1) << 6 | (status & 0xFFBF);
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

void Living::SetSpecularColor(LH3DColor color) {
    // Original at 0x00413fb0: *(this + 0xD0) = color
    specular_color = color;
}

LH3DColor Living::GetSpecularColor() {
    // Original at 0x00413fc0: return *(this + 0xD0)
    return specular_color;
}

void Living::SetPoisoned(int value) {
    // Original at 0x00413dd0: sets bit 1 of status field at 0xB4
    status = (static_cast<uint16_t>(value) & 1) << 1 | (status & 0xFFFD);
}

bool Living::CanBePickedUp() {
    // Original at 0x00413eb0: returns inverted bit 13 of field_0x24
    // Bit 13 set means NOT pickable (IsCannotBePickedUp flag)
    return (field_0x24 & 0x2000) == 0;
}

IMMERSION_EFFECT_TYPE Living::GetInHandImmersionTexture() {
    // Original at 0x004181c0
    return static_cast<IMMERSION_EFFECT_TYPE>(0x16);
}

// ============================================================================
// State / movement queries (vtable 0x874-0x8CC)
// ============================================================================

bool Living::AmILikelyToMove() { return false; }
void Living::SetFoodSpeedup(bool) {}
bool Living::IsFoodSpeedUp() { return false; }
uint32_t Living::GetNumTurnsToDieOver() { return 0; }

MapCoords* Living::GetFinalDestPos(MapCoords* out) {
    *out = coords;
    return out;
}

// State query methods — check action.top_state against specific VILLAGER_STATES
bool Living::FleeingFromObjectReaction() {
    return action.top_state == VILLAGER_STATE_FLEEING_FROM_OBJECT_REACTION;
}

bool Living::LookingAtObjectReaction() {
    return action.top_state == VILLAGER_STATE_LOOKING_AT_OBJECT_REACTION;
}

bool Living::FleeingAndLookingAtObjectReaction() {
    return FleeingFromObjectReaction() || LookingAtObjectReaction();
}

bool Living::FollowingObjectReaction() {
    return action.top_state == VILLAGER_STATE_FOLLOWING_OBJECT_REACTION;
}

bool Living::InspectObjectReaction() {
    return action.top_state == VILLAGER_STATE_INSPECT_OBJECT_REACTION;
}

bool Living::Dying() {
    return action.top_state == VILLAGER_STATE_DYING;
}

bool Living::Dead() {
    return action.top_state == VILLAGER_STATE_DEAD;
}

bool Living::Downed() {
    return action.top_state == VILLAGER_STATE_DOWNED;
}

bool Living::BeingEaten() {
    return action.top_state == VILLAGER_STATE_BEING_EATEN;
}

bool Living::GotoFoodReaction() {
    return action.top_state == VILLAGER_STATE_GOTO_FOOD_REACTION;
}

bool Living::GotoWoodReaction() {
    return action.top_state == VILLAGER_STATE_GOTO_WOOD_REACTION;
}

bool Living::MoveInFlock() {
    return flock != nullptr;
}

bool Living::IsMovingForAnimation() {
    return IsMoving();
}

bool Living::ArrivesAtFoodReaction() {
    return action.top_state == VILLAGER_STATE_ARRIVES_AT_FOOD_REACTION;
}

bool Living::ArrivesAtWoodReaction() {
    return action.top_state == VILLAGER_STATE_ARRIVES_AT_WOOD_REACTION;
}

bool Living::InHand() {
    return action.top_state == VILLAGER_STATE_IN_HAND;
}

bool Living::DecideWhatToDo() { return false; }
void Living::Birthday() {}

// ============================================================================
// Age and animation state machine (vtable 0x8D0-0x95C)
// ============================================================================

uint32_t Living::GetAge() {
    // Age is computed from birth_turn — overridden by Villager with real age tracking
    return 0;
}

void Living::SetAge(uint32_t /*age*/) {
    // Base: no-op, overridden by Villager
}
bool Living::LookAtFlyingObjectReaction() { return false; }
int Living::SetCurrentAndDestinationState(VILLAGER_STATES current, VILLAGER_STATES destination) {
    // Sets top and final states for the state machine transition
    SetState(LIVING_ACTION_INDEX_TOP, current);
    SetState(LIVING_ACTION_INDEX_FINAL, destination);
    return 1;
}

int Living::CallIntoAnimationFunction(VILLAGER_STATES) { return 0; }
int Living::CallOutofAnimationFunction(VILLAGER_STATES) { return 0; }

int Living::SetTopState(VILLAGER_STATES state) {
    StorePreviousState();
    SetState(LIVING_ACTION_INDEX_TOP, state);
    return 1;
}
void Living::StorePreviousState() {
    action.previous_state = action.top_state;
}
void Living::SetStateSpeed() {}
bool Living::IsFinalState(VILLAGER_STATES state) {
    return action.top_state == static_cast<uint8_t>(state);
}
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
void Living::SetState(LIVING_ACTION_INDEX index, VILLAGER_STATES state) {
    switch (index) {
    case LIVING_ACTION_INDEX_TOP:
        action.top_state = static_cast<uint8_t>(state);
        action.turns_since_state_change = 0;
        break;
    case LIVING_ACTION_INDEX_FINAL:
        action.final_state = static_cast<uint8_t>(state);
        break;
    case LIVING_ACTION_INDEX_PREVIOUS:
        action.previous_state = static_cast<uint8_t>(state);
        break;
    default:
        break;
    }
}
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

bool Living::IsScriptState(VILLAGER_STATES state) const {
    return state == VILLAGER_STATE_IN_SCRIPT;
}
bool Living::IsScriptInterruptableState(VILLAGER_STATES state) const {
    // Original at 0x00413e60: return state == 0x18
    return state == VILLAGER_STATE_IN_HAND;
}
bool Living::IsStateForInterface(VILLAGER_STATES) const { return false; }
bool Living::IsStateExitFunctionSameAs(VILLAGER_STATES) const { return false; }
bool Living::IsDeathState(VILLAGER_STATES state) const {
    return state == VILLAGER_STATE_DEAD || state == VILLAGER_STATE_DYING;
}
uint32_t Living::DebugShowTime(uint32_t, uint8_t, uint8_t) { return 0; }
bool Living::IsDancing() {
    return action.top_state == VILLAGER_STATE_IN_DANCE;
}
bool Living::IsInterestedInFoodObject(Object*) { return false; }
bool Living::IsInterestedInWoodObject(Object*) { return false; }
bool Living::IsAvailableForReaction(REACTION) { return false; }
bool Living::IsAvailableForBeliefButNotReaction(REACTION) { return false; }

// ============================================================================
// Reaction management (vtable 0x98C-0x9A0)
// ============================================================================

void Living::UpdateHowImpressed(Reaction*, int) {}
void Living::AddReaction(Reaction*, VILLAGER_STATES) {}
void Living::StartReacting(REACTION /*type*/, GameThingWithPos* target, Reaction* r) {
    // Store the reaction and the target entity
    reaction = r;
    field_0xbc = target;
}
void Living::StopReacting() {
    // Clear the current reaction
    reaction = nullptr;
    reaction_done_when = nullptr;
}

void Living::StopReactingAndSetState() {
    // Stop reacting and reset to previous state
    StopReacting();
    ResetStateAfterReacting();
}

void Living::ResetStateAfterReacting() {
    // Restore the previous state after finishing a reaction
    SetTopState(static_cast<VILLAGER_STATES>(action.previous_state));
}

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
uint32_t Living::IsPosValidForMapCellExistance(const MapCoords* pos) {
    // Checks if the position is within the map bounds
    if (!g_map || !pos) return 0;
    uint32_t cell_x = static_cast<uint32_t>(pos->x) >> 16;
    uint32_t cell_z = static_cast<uint32_t>(pos->z) >> 16;
    return g_map->InBounds(cell_x, cell_z) ? 1 : 0;
}

// ============================================================================
// Miscellaneous (vtable 0xAF0-0xB3C)
// ============================================================================

void Living::MoveByTeleport(const MapCoords* target) {
    if (target) {
        SetPos(*target);
    }
}

bool Living::IsDead() {
    // Original: checks if top_state is DEAD or DYING
    return action.top_state == VILLAGER_STATE_DEAD || action.top_state == VILLAGER_STATE_DYING;
}

bool Living::IsChild() { return false; }
void Living::GetFleeingPositionFromMovingObject(MapCoords*, GameThingWithPos*, float) {}
void Living::GetFleeingPositionFromStationaryObject(MapCoords*, GameThingWithPos*, float) {}
VILLAGER_STATES Living::GetFinalState() const {
    return static_cast<VILLAGER_STATES>(action.final_state);
}
void Living::RemoveFromDance(int) {}
void Living::SetStateAfterFinishingDance() {}
float Living::CalculateLifeDesire() {
    // Life desire inversely proportional to current life
    float life = GetLife();
    if (life >= 1.0f) return 0.0f;
    return 1.0f - life;
}
uint32_t Living::DanceType() { return 0; }
bool Living::CanBeHealedByHealSpell() {
    // Can be healed if alive but damaged
    return !IsDead() && GetLife() < 1.0f;
}
bool Living::MoveAllowedForChessGame() { return false; }
bool Living::AttackAllowedForChessGame() { return false; }
void Living::AddToBoxPositionForChessGame(int, int) {}
int Living::GetBoxXForChessGame() { return 0; }
int Living::GetBoxZForChessGame() { return 0; }
void Living::SetBoxXForChessGame(int) {}
void Living::SetBoxZForChessGame(int) {}
uint32_t Living::GetTeamForChessGame() { return 0; }
bool Living::IsPosValidForTurnAngle(const MapCoords*) { return false; }

// Static methods
void Living::ProcessLiving() {
    // Original at 0x005ec810 — processes all living entities per tick
    // Iterates the global living list and calls ProcessState() on each
    // Iterate g_game->game_lists.living_list and for each living entity:
    //   1. Increment turns_since_state_change
    //   2. Call ProcessState() (dispatches to state handler)
    //   3. Update movement if moving
    //   4. Check health/death conditions
}
