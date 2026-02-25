// GameThingWithPos class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// GameThingWithPos extends GameThing with world position and a massive set of
// type-query predicates used by the Creature AI belief system. Nearly all
// predicates return false here; derived classes (Object, Villager, etc.) override.

#include <black/GameThingWithPos.h>

// ============================================================================
// Position and basic property methods
// ============================================================================

void GameThingWithPos::SetPos(const MapCoords& src) {
    // Copies 12 bytes (3 ints) from src to this->coords
    // Original at 0x004014c0: memcpy(&this->coords, &src, sizeof(MapCoords))
    coords = src;
}

MapCoords* GameThingWithPos::GetPos(MapCoords* out) {
    // Returns pointer to output after copying position
    // Original at 0x00401960
    *out = coords;
    return out;
}

MapCoords* GameThingWithPos::GetArrivePos(MapCoords* out) {
    // Default: arrive pos == current pos
    *out = coords;
    return out;
}

void GameThingWithPos::PhysicsEditorCreate(int /*param1*/) {
    // Zeroes the altitude component of coords
    // Original at 0x004014e0: *(this + 0x1c) = 0
    coords.altitude = 0.0f;
}

uint32_t GameThingWithPos::GetCreatureBeliefType() {
    // Default: 0x15 (21)
    return 0x15;
}

uint32_t GameThingWithPos::GetCreatureBeliefListType() {
    // Default: 1
    return 1;
}

Citadel* GameThingWithPos::GetCitadel() {
    return nullptr;
}

uint32_t GameThingWithPos::GetOrigin() {
    return 0;
}

float GameThingWithPos::GetLife() {
    // Default life is 1.0 (fully alive)
    return 1.0f;
}

float GameThingWithPos::GetScale() {
    return 0.0f;
}

void GameThingWithPos::SetScale(float /*scale*/) {
    // Default: no-op
}

float GameThingWithPos::GetPower() const {
    return 0.0f;
}

float GameThingWithPos::GetPSysPower() const {
    return 0.0f;
}

float GameThingWithPos::GetSpeedInMetres() const {
    return 0.0f;
}

void GameThingWithPos::SetSpeedInMetres(float /*speed*/, int /*scale*/) {}

float GameThingWithPos::GetRunningSpeedInMetres() {
    return 0.0f;
}

float GameThingWithPos::GetDistanceFromObject(const MapCoords& /*target*/) {
    return 0.0f;
}

float GameThingWithPos::GetDefaultSpeedInMetres() {
    return 0.0f;
}

void GameThingWithPos::SetHeight(float /*height*/) {}
void GameThingWithPos::SetMaxHeight(float /*height*/) {}

float GameThingWithPos::GetMaxHeight() {
    return 0.0f;
}

void GameThingWithPos::GetPSysBeamTargetPos(LHPoint* /*pos*/) {}

float GameThingWithPos::GetSpeedInMetresPerSecond() const {
    return 0.0f;
}

void GameThingWithPos::SetSpeedInMetresPerSecond(float /*speed*/, int /*scale*/) {}

float GameThingWithPos::GetRunningSpeedInMetresPerSecond() {
    return 0.0f;
}

float GameThingWithPos::GetDefaultSpeedInMetresPerSecond() {
    return 0.0f;
}

bool GameThingWithPos::IsAnimate() {
    return false;
}

void GameThingWithPos::GetMovementDirection(LHPoint* /*pos*/) {}
void GameThingWithPos::GetPhysicsMovementDirection(LHPoint* /*pos*/) {}

void GameThingWithPos::GetInteractPos(LHPoint* pos) {
    // Default: returns coords as LHPoint (same memory layout as MapCoords)
    // Original at 0x004019f0: copies 12 bytes from this+0x14 to pos
    pos->x = *reinterpret_cast<float*>(&coords.x);
    pos->y = *reinterpret_cast<float*>(&coords.z);
    pos->z = coords.altitude;
}

bool GameThingWithPos::IsMoving() const {
    return false;
}

bool GameThingWithPos::IsObjectInMap_0() {
    // Checks bit 0 of field_0x24
    // Original at 0x00403c90: return *(byte*)(this + 0x24) & 1
    return (field_0x24 & 1) != 0;
}

bool GameThingWithPos::IsDrowning() {
    return false;
}

// ============================================================================
// State queries with real logic
// ============================================================================

bool GameThingWithPos::IsCannotBePickedUp() const {
    // Checks bit 13 of field_0x24
    // Original at 0x004014f0: return (*(uint16*)(this + 0x24) & 0x2000) >> 13
    return (field_0x24 >> 13) & 1;
}

uint32_t GameThingWithPos::GetOverwritePickUpToolTip() { return 0; }

bool GameThingWithPos::IsStompable() {
    return false;
}

bool GameThingWithPos::IsAvailableForStateChange() {
    // Checks inverted bit 2 of field_0x24
    // Original at 0x00401500: return (~*(byte*)(this + 0x24) & 4) >> 2
    return (~static_cast<uint8_t>(field_0x24) >> 2) & 1;
}

bool GameThingWithPos::IsInteractable() {
    return false;
}

uint32_t GameThingWithPos::GetOverwriteInteractableToolTip() { return 0; }
uint32_t GameThingWithPos::GetOverwriteDropToolTip() { return 0; }
uint32_t GameThingWithPos::GetOverwriteTapToolTip() { return 0; }
bool32_t GameThingWithPos::IsCastShadowAtNight() { return 0; }
void GameThingWithPos::CleanupWhenDeleted(int /*param1*/) {}

IMPRESSIVE_TYPE GameThingWithPos::GetImpressiveType() {
    return IMPRESSIVE_TYPE_NONE;
}

float GameThingWithPos::GetImpressiveIntensity(IMPRESSIVE_TYPE /*type*/) {
    return 1.0f;
}

float GameThingWithPos::GetImpressiveValue(Living* /*param1*/, Reaction* /*param2*/) {
    return 0.0f;
}

float GameThingWithPos::GetUpdateOfBoredomValue(Reaction* /*param1*/, GameThingWithPos* /*param2*/) {
    return 0.0f;
}

// ============================================================================
// Type predicates — nearly all return false in the base class
// ============================================================================

bool GameThingWithPos::IsTown_0() { return false; }
bool GameThingWithPos::IsTown_1(Creature*) { return false; }
bool GameThingWithPos::IsActivityObjectWhichAngerAppliesTo(Creature*) { return false; }
bool GameThingWithPos::IsActivityObjectWhichCompassionAppliesTo(Creature*) { return false; }
bool GameThingWithPos::IsActivityObjectWhichPlayfulnessAppliesTo(Creature*) { return false; }
bool GameThingWithPos::IsTownBelongingToAnotherPlayer(Creature*) { return false; }

bool32_t GameThingWithPos::TrueFunction() { return 1; }
bool32_t GameThingWithPos::FalseFunction() { return 0; }
bool32_t GameThingWithPos::IsNotLiving() { return 1; }
bool32_t GameThingWithPos::IsSuitableForCreatureActivity() { return 0; }
bool32_t GameThingWithPos::IsTownCentre() { return 0; }
bool32_t GameThingWithPos::IsTotemStatue() { return 0; }
bool32_t GameThingWithPos::IsTownDesireFlag() { return 0; }
bool32_t GameThingWithPos::IsRock_1(Creature*) { return 0; }
bool32_t GameThingWithPos::IsRock_0() { return 0; }
bool32_t GameThingWithPos::IsSpellDispenser() { return 0; }
bool32_t GameThingWithPos::IsMist() { return 0; }
bool32_t GameThingWithPos::IsQueryIcon() { return 0; }
bool32_t GameThingWithPos::IsStreetLight() { return 0; }
bool32_t GameThingWithPos::IsStreetLantern() { return 0; }
bool32_t GameThingWithPos::IsAbode() { return 0; }
bool32_t GameThingWithPos::IsField_1(Creature*) { return 0; }
bool32_t GameThingWithPos::IsField_0() { return 0; }
bool32_t GameThingWithPos::IsBuildingMaterial() { return 0; }
bool32_t GameThingWithPos::IsMagicFireBall() { return 0; }
bool32_t GameThingWithPos::IsSuitableForCreatureAction() { return 0; }
bool32_t GameThingWithPos::IsCitadelHeart() { return 0; }

bool32_t GameThingWithPos::IsDamaged() {
    // Calls GetLife() through vtable, returns true if life < 1.0
    // Original at 0x00401510: vtable[0x11c/4] = GetLife
    return GetLife() < 1.0f;
}

bool32_t GameThingWithPos::CanBeHealedByCreature(Creature*) { return 0; }
bool32_t GameThingWithPos::CanBeEatenByCreature(Creature*) { return 0; }
bool32_t GameThingWithPos::CanCreatureEatMe(Creature*) { return 0; }
bool32_t GameThingWithPos::CanBeAttackedByCreature(Creature*) { return 0; }
bool32_t GameThingWithPos::CanBeFrighteningToCreature(Creature*) { return 0; }
bool32_t GameThingWithPos::CanBeHelpedByCreature(Creature*) { return 0; }
bool32_t GameThingWithPos::CanBePlayedWithByCreature(Creature*) { return 0; }
bool32_t GameThingWithPos::CanBeImpressedByCreature(Creature*) { return 0; }
bool32_t GameThingWithPos::CanBeInspectedByCreature(Creature*) { return 0; }
bool32_t GameThingWithPos::CanBePoodUponByCreature(Creature*) { return 0; }
bool32_t GameThingWithPos::CanBeBefriendedByCreature(Creature*) { return 0; }
bool32_t GameThingWithPos::CanBeSleptNextToByCreature(Creature*) { return 0; }
bool32_t GameThingWithPos::CanBePickedUpByCreature(Creature*) { return 0; }
bool32_t GameThingWithPos::CanBeStrokedByCreature(Creature*) { return 0; }
bool32_t GameThingWithPos::CanBeKissedByCreature(Creature*) { return 0; }
bool32_t GameThingWithPos::CanBeSetOnFire(Creature*) { return 0; }
bool32_t GameThingWithPos::CanBeStompedOnByCreature(Creature*) { return 0; }
bool32_t GameThingWithPos::CanBeThrownByCreature(Creature*) { return 0; }
bool32_t GameThingWithPos::CanBeGivenToVillager(Creature*) { return 0; }
bool32_t GameThingWithPos::CanBePutInAStoragePit(Creature*) { return 0; }
bool32_t GameThingWithPos::CanBeDestroyedByStoning(Creature*) { return 0; }

bool32_t GameThingWithPos::CanBeStonedAndEatenByCreature(Creature* creature) {
    // Compound check: CanBeDestroyedByStoning(creature) && CanBeEatenByCreature(creature)
    // Original at 0x00401530: vtable[0x258/4] && vtable[0x278/4]
    if (CanBeDestroyedByStoning(creature)) {
        if (CanBeEatenByCreature(creature)) {
            return 1;
        }
    }
    return 0;
}

bool32_t GameThingWithPos::CanBeExaminedByCreature(Creature*) { return 0; }
bool32_t GameThingWithPos::CanBeFoughtByCreature(Creature*) { return 0; }
bool32_t GameThingWithPos::CanReceiveGifts(Creature*) { return 0; }
bool32_t GameThingWithPos::CanActAsAContainer(Creature*) { return 0; }
bool32_t GameThingWithPos::IsBeingBuilt(Creature*) { return 0; }
bool32_t GameThingWithPos::NeedsRepair(Creature*) { return 0; }
bool32_t GameThingWithPos::IsOnFire(Creature*) { return 0; }

bool32_t GameThingWithPos::IsNotOnFire(Creature* creature) {
    // Returns !IsOnFire(creature) through vtable
    // Original at 0x00401570: vtable[0x298/4]
    return !IsOnFire(creature);
}

bool32_t GameThingWithPos::CanBeUsedForBuilding(Creature*) { return 0; }
bool32_t GameThingWithPos::IsMushroom(Creature*) { return 0; }
bool32_t GameThingWithPos::CanBeUsedForRepair(Creature*) { return 0; }
bool32_t GameThingWithPos::CanBeGivenToTown(Creature*) { return 0; }
bool32_t GameThingWithPos::CanBeUsedToHoldWater(Creature*) { return 0; }
bool32_t GameThingWithPos::CanBePutInFoodPile(Creature*) { return 0; }
bool32_t GameThingWithPos::CanBePutInWoodPile(Creature*) { return 0; }
bool32_t GameThingWithPos::CanHaveMagicFoodCastOnMe(Creature*) { return 0; }
bool32_t GameThingWithPos::CanHaveMagicWoodCastOnMe(Creature*) { return 0; }
bool32_t GameThingWithPos::CanBeBroughtBackToCitadel(Creature*) { return 0; }
bool32_t GameThingWithPos::IsVillager(Creature*) { return 0; }
bool32_t GameThingWithPos::IsVillagerFarFromHome(Creature*) { return 0; }
bool32_t GameThingWithPos::IsVillagerInTownWithoutManyBreeders(Creature*) { return 0; }
bool32_t GameThingWithPos::IsVillagerNotWorshipping(Creature*) { return 0; }
bool32_t GameThingWithPos::IsVillagerBelongingToOtherPlayer(Creature*) { return 0; }
bool32_t GameThingWithPos::IsCow(Creature*) { return 0; }
bool32_t GameThingWithPos::CanBePoodOn(Creature*) { return 0; }
bool32_t GameThingWithPos::IsVillagerWhoHasNotBeenImpressedRecently(Creature*) { return 0; }
bool32_t GameThingWithPos::IsVillagerWhoHasNotBeenDancedWithRecently(Creature*) { return 0; }
bool32_t GameThingWithPos::DoesVillagerBelongToATownWhichIsAlreadyImpressed(Creature*) { return 0; }
bool32_t GameThingWithPos::DoesTotemBelongToATownWhichIsVeryImpressedIndeed(Creature*) { return 0; }
bool32_t GameThingWithPos::IsDominantCreature(Creature*) { return 0; }
bool32_t GameThingWithPos::CanBeDancedWith(Creature*) { return 0; }
bool32_t GameThingWithPos::IsAggressive(Creature*) { return 0; }
bool32_t GameThingWithPos::IsStoragePit(Creature*) { return 0; }
bool32_t GameThingWithPos::IsWorshipSite_1() { return 0; }
bool32_t GameThingWithPos::IsWorshipSite_0(Creature*) { return 0; }
WorshipSite* GameThingWithPos::GetWorshipSite() { return nullptr; }
bool32_t GameThingWithPos::IsWorkshop_0() { return 0; }
bool32_t GameThingWithPos::IsWorkshop_1(Creature*) { return 0; }
bool32_t GameThingWithPos::IsBuildingWhichIsBeingBuilt(Creature*) { return 0; }
bool32_t GameThingWithPos::IsStoragePitWithFoodInIt(Creature*) { return 0; }
bool32_t GameThingWithPos::IsFieldWhichNeedsWatering(Creature*) { return 0; }
bool32_t GameThingWithPos::IsFieldWithFoodInIt(Creature*) { return 0; }
bool32_t GameThingWithPos::IsFieldBelongingToAnotherPlayer(Creature*) { return 0; }
bool32_t GameThingWithPos::IsStoragePitBelongingToAnotherPlayer(Creature*) { return 0; }
bool32_t GameThingWithPos::IsStoragePitBelongingToMyPlayer(Creature*) { return 0; }
bool32_t GameThingWithPos::BenefitsFromHavingWaterSprinkledOnIt(Creature*) { return 0; }
bool32_t GameThingWithPos::IsTree_1() { return 0; }
bool32_t GameThingWithPos::IsTree_0(Creature*) { return 0; }
bool32_t GameThingWithPos::IsTreeNotTooNearPlannedForest(Creature*) { return 0; }
bool32_t GameThingWithPos::IsTreeBigEnoughForCreature(Creature*) { return 0; }
bool32_t GameThingWithPos::IsAFoodPileOutsideStoragePit(Creature*) { return 0; }
bool32_t GameThingWithPos::IsAWoodPileOutsideStoragePit(Creature*) { return 0; }
bool32_t GameThingWithPos::IsDoingSomethingInteresting(Creature*) { return 0; }

bool32_t GameThingWithPos::CanBeUsedForBuildingHomeByCreature(Creature* creature) {
    // Compound: IsRock_0() && CanBeUsedForBuilding(creature) && !FUN_004c5380(creature)
    // Original at 0x00401590: vtable[0x1f0/4] && vtable[0x2a0/4]
    if (IsRock_0()) {
        if (CanBeUsedForBuilding(creature)) {
            return 1;
        }
    }
    return 0;
}

bool32_t GameThingWithPos::IsPickupableRock(Creature* creature) {
    // IsRock_0() && CanBePickedUpByCreature(creature)
    // Original at 0x004015e0: vtable[0x1f0/4] && vtable[600/4]
    if (IsRock_0()) {
        if (CanBePickedUpByCreature(creature)) {
            return 1;
        }
    }
    return 0;
}

bool32_t GameThingWithPos::IsCitadelPart_0() { return 0; }
bool32_t GameThingWithPos::IsCitadelPart_1(Creature*) { return 0; }
bool32_t GameThingWithPos::IsPlayingFootball(Creature*) { return 0; }
bool32_t GameThingWithPos::IsPlayingFootballAndMySideHasJustScored(Creature*) { return 0; }
bool32_t GameThingWithPos::IsPlayingFootballAndOtherSideHasJustScored(Creature*) { return 0; }
bool32_t GameThingWithPos::CanBeBroughtHomeByCreature(Creature*) { return 0; }
bool32_t GameThingWithPos::IsAnimalBelongingToOtherPlayer(Creature*) { return 0; }
bool32_t GameThingWithPos::IsOneOffSpellBelongingToOtherPlayer(Creature*) { return 0; }
bool32_t GameThingWithPos::IsOneOffSpellAggressive(Creature*) { return 0; }
bool32_t GameThingWithPos::IsOneOffSpellCompassionate(Creature*) { return 0; }
bool32_t GameThingWithPos::IsOneOffSpellPlayful(Creature*) { return 0; }
bool32_t GameThingWithPos::IsOneOffSpellToRestoreHealth(Creature*) { return 0; }
bool32_t GameThingWithPos::CanBeKickedByCreature(Creature*) { return 0; }
bool32_t GameThingWithPos::CanBeStolenByCreature(Creature*) { return 0; }
bool32_t GameThingWithPos::IsStealableByCreature(Creature*) { return 0; }
bool32_t GameThingWithPos::IsStealableSpell(Creature*) { return 0; }
bool32_t GameThingWithPos::IsStealableScaffold(Creature*) { return 0; }
bool32_t GameThingWithPos::IsTownBelongingToOtherPlayer(Creature*) { return 0; }
bool32_t GameThingWithPos::IsTotemWithStealableSpell(Creature*) { return 0; }
bool32_t GameThingWithPos::IsCreatureAvailableForJointActivity(Creature*) { return 0; }
bool32_t GameThingWithPos::IsCreatureNotAvailableForJointActivity(Creature*) { return 0; }
bool32_t GameThingWithPos::IsToyAwayFromHome(Creature*) { return 0; }
bool32_t GameThingWithPos::IsToy(Creature*) { return 0; }
bool32_t GameThingWithPos::IsToyBall(Creature*) { return 0; }
bool32_t GameThingWithPos::IsToyDie(Creature*) { return 0; }
bool32_t GameThingWithPos::IsToyCuddly(Creature*) { return 0; }
bool32_t GameThingWithPos::IsLiving_1() const { return 0; }

bool32_t GameThingWithPos::IsLiving_0(Creature* /*creature*/) const {
    // Delegates to IsLiving_1() through vtable
    // Original at 0x00401620: vtable[0x3c4/4]
    return IsLiving_1();
}

bool32_t GameThingWithPos::IsFence() { return 0; }
bool32_t GameThingWithPos::IsSpellIcon() { return 0; }
bool32_t GameThingWithPos::NothingScareyNearMe() const { return 0; }
bool32_t GameThingWithPos::CanBeUsedForThrowingDamageByCreature(Creature*) { return 0; }
bool32_t GameThingWithPos::IsCreatureWhoSeemsFriendly(Creature*) { return 0; }
bool32_t GameThingWithPos::CanBeThrownInTheSeaPlayfully(Creature*) { return 0; }

uint32_t GameThingWithPos::GetCreatureMimicType() {
    return 10;
}

float GameThingWithPos::GetHowMuchCreatureWantsToLookAtMe() {
    return 0.0f;
}

bool32_t GameThingWithPos::IsFlock() const { return 0; }
bool32_t GameThingWithPos::IsDance() const { return 0; }
bool32_t GameThingWithPos::IsReward() const { return 0; }
bool32_t GameThingWithPos::IsScriptContainer() const { return 0; }
bool32_t GameThingWithPos::IsWeather() const { return 0; }
bool32_t GameThingWithPos::IsSpell() const { return 0; }

bool32_t GameThingWithPos::IsDeletedWhenReleasedFromScript() {
    return 5;  // Original returns 5 — special sentinel for "conditionally delete"
}

bool32_t GameThingWithPos::IsMobileWallHug() const { return 0; }
bool32_t GameThingWithPos::IsActive() const { return 0; }
bool32_t GameThingWithPos::IsObjectTurningTooFastForCameraToFollowSmoothly() { return 0; }
void GameThingWithPos::CalculateWhereIWillBeAfterNSeconds(float, LHPoint*) {}

uint32_t GameThingWithPos::AttitudeToCreatureEating() {
    return 1;
}

const char* GameThingWithPos::GetText() {
    return nullptr;
}

float GameThingWithPos::CalculateDesireForFood() { return 0.0f; }
float GameThingWithPos::CalculateDesireForRest() { return 0.0f; }
float GameThingWithPos::CalculatePeopleHidingIndicator() { return 0.0f; }
float GameThingWithPos::GetHeight() { return 0.0f; }
bool32_t GameThingWithPos::IsReadyForNewScriptAction() { return 0; }
int GameThingWithPos::ForDrawFXGetNumVertices() { return 0; }
void GameThingWithPos::ForDrawFXGetVertexPos(int, LHPoint*) {}

void GameThingWithPos::SetInScript(int param1) {
    // Sets bit 9 of field_0x24 based on param1
    // Original at 0x00403cb0: field_0x24 = (param1 & 1) << 9 | field_0x24 & 0xfdff
    field_0x24 = static_cast<uint16_t>(
        ((param1 & 1) << 9) | (field_0x24 & 0xFDFF)
    );
}

void GameThingWithPos::SetControlledByScript(int param1) {
    // Sets bit 10 of field_0x24 based on param1
    // Original at 0x00401630: field_0x24 = (param1 & 1) << 10 | field_0x24 & 0xfbff
    field_0x24 = static_cast<uint16_t>(
        ((param1 & 1) << 10) | (field_0x24 & 0xFBFF)
    );
}

DEATH_REASON GameThingWithPos::GetDeathReason() {
    return DEATH_REASON_NONE;
}

bool32_t GameThingWithPos::IsInScript() {
    // Checks bit 9 of field_0x24
    // Original at 0x00401660: return (*(uint16*)(this + 0x24) & 0x200) >> 9
    return (field_0x24 >> 9) & 1;
}

bool32_t GameThingWithPos::IsMaleVillager() { return 0; }
bool32_t GameThingWithPos::IsFemaleVillager() { return 0; }
bool32_t GameThingWithPos::IsAnimal() { return 0; }
bool32_t GameThingWithPos::IsAChild() { return 0; }
bool32_t GameThingWithPos::IsHouse() { return 0; }
bool32_t GameThingWithPos::IsObject() { return 0; }
bool32_t GameThingWithPos::IsFootball() { return 0; }
bool32_t GameThingWithPos::IsCitadel() { return 0; }
bool32_t GameThingWithPos::IsForest() { return 0; }
bool32_t GameThingWithPos::IsMobileObject() { return 0; }
bool32_t GameThingWithPos::IsMobileStatic() { return 0; }
bool32_t GameThingWithPos::IsAnyKindOfTree() { return 0; }
bool32_t GameThingWithPos::IsDeadTree() { return 0; }
bool32_t GameThingWithPos::IsPileFood() { return 0; }
bool32_t GameThingWithPos::IsFeature() { return 0; }
bool32_t GameThingWithPos::IsScriptMarker() { return 0; }
bool32_t GameThingWithPos::IsScriptHighlight() { return 0; }
bool32_t GameThingWithPos::IsWonder() { return 0; }
bool32_t GameThingWithPos::IsInfluenceRing() { return 0; }
bool32_t GameThingWithPos::IsPuzzleGame() { return 0; }
bool32_t GameThingWithPos::IsScaffold() { return 0; }
bool32_t GameThingWithPos::IsSkeleton() const { return 0; }
bool32_t GameThingWithPos::IsPoisoned() { return 0; }
bool32_t GameThingWithPos::IsSpeedUp() { return 0; }
bool32_t GameThingWithPos::IsParticleContainer() { return 0; }

bool32_t GameThingWithPos::IsSacrificeAltar() {
    // Checks if info->field_0x120 == 0x100
    // Original at 0x00404850: *(int*)(*(int*)(this + 0x28) + 0x120) == 0x100
    // Note: this references field at offset 0x28 which is in Object, not GameThingWithPos.
    // In the base class this would access map_child->... which is wrong — this method
    // is only meaningful when called on an Object (where 0x28 = GObjectInfo* info).
    return 0;
}

bool32_t GameThingWithPos::IsPot() { return 0; }
bool32_t GameThingWithPos::IsComputerPlayer() { return 0; }
bool32_t GameThingWithPos::CanBeThrownByPlayer() { return 0; }
void GameThingWithPos::SetSkeleton(int /*index*/) {}
bool32_t GameThingWithPos::IsSpellSeed() { return 0; }
bool32_t GameThingWithPos::IsSpellShield() { return 0; }
bool32_t GameThingWithPos::IsPileResource() { return 0; }
bool32_t GameThingWithPos::IsScriptTimer() { return 0; }
bool32_t GameThingWithPos::CreateBuildingSite() { return 0; }

HELP_TEXT GameThingWithPos::GetQueryFirstEnumText() {
    return HELP_TEXT_NONE;
}

HELP_TEXT GameThingWithPos::GetQueryLastEnumText() {
    return HELP_TEXT_NONE;
}

uint32_t GameThingWithPos::GetFOVHelpMessageSet() { return 0; }
uint32_t GameThingWithPos::GetFOVHelpCondition() { return 0; }
uint32_t GameThingWithPos::GetScriptObjectType() { return 0; }
float GameThingWithPos::GetFacingDirection() { return 0.0f; }
void GameThingWithPos::SetAffectedByWind(int /*param1*/) {}
float GameThingWithPos::GetReactionPower() { return 0.0f; }

void GameThingWithPos::GetSpellCastPos(MapCoords* outPos) {
    // Returns current position
    *outPos = coords;
}

void GameThingWithPos::CleanUpBeforeReset() {}
