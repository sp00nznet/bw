#pragma once
// GameThingWithPos — entity with a position in the game world
// Struct layout from bw1-decomp, implementations from v1.0 decompilation
//
// Size: 0x28 bytes (inherits 0x14 from GameThing)
// Vtable: 0x500 bytes (~320 entries, extends GameThing's 0xFC)

#include "GameThing.h"
#include "types.h"

// Forward declarations
struct Citadel;
struct Creature;
struct Living;
struct Object;
struct Reaction;
struct WorshipSite;

// Impressive type enum (partial — from bw1-decomp's chlasm/Enum.h)
enum IMPRESSIVE_TYPE : uint32_t {
    IMPRESSIVE_TYPE_NONE = 0x1B,
    // ... remaining entries
};

// Death reason enum
enum DEATH_REASON : uint32_t {
    DEATH_REASON_NONE = 0,
    // ... remaining entries
};

// Help text enum
enum HELP_TEXT : uint32_t {
    HELP_TEXT_NONE = 0,
    // ... remaining entries
};

struct GameThingWithPos : public GameThing {
    // === Virtual methods extending GameThing's vtable ===
    // These add ~220 new virtual slots (0xFC through 0x4FC)

    // --- Position and movement (vtable 0xFC-0x16C) ---
    virtual void SetPos(const MapCoords& coords);
    virtual MapCoords* GetPos(MapCoords* out);
    virtual MapCoords* GetArrivePos(MapCoords* out);
    virtual void PhysicsEditorCreate(int param1);
    virtual uint32_t GetCreatureBeliefType();
    virtual uint32_t GetCreatureBeliefListType();
    virtual Citadel* GetCitadel();
    virtual uint32_t GetOrigin();
    virtual float GetLife();           // overrides GameThing
    virtual float GetScale();
    virtual void SetScale(float scale);
    virtual float GetPower() const;
    virtual float GetPSysPower() const;
    virtual float GetSpeedInMetres() const;
    virtual void SetSpeedInMetres(float speed, int scale);
    virtual float GetRunningSpeedInMetres();
    virtual float GetDistanceFromObject(const MapCoords& target);
    virtual float GetDefaultSpeedInMetres();
    virtual void SetHeight(float height);
    virtual void SetMaxHeight(float height);
    virtual float GetMaxHeight();
    virtual void GetPSysBeamTargetPos(LHPoint* pos);
    virtual float GetSpeedInMetresPerSecond() const;
    virtual void SetSpeedInMetresPerSecond(float speed, int scale);
    virtual float GetRunningSpeedInMetresPerSecond();
    virtual float GetDefaultSpeedInMetresPerSecond();
    virtual bool IsAnimate();
    virtual void GetMovementDirection(LHPoint* pos);
    virtual void GetPhysicsMovementDirection(LHPoint* pos);
    virtual void GetInteractPos(LHPoint* pos);
    virtual bool IsMoving() const;
    virtual bool IsObjectInMap_0();
    virtual bool IsDrowning();

    // --- State queries (vtable 0x180-0x1AC) ---
    virtual bool IsCannotBePickedUp() const;
    virtual uint32_t GetOverwritePickUpToolTip();
    virtual bool IsStompable();
    virtual bool IsAvailableForStateChange();
    virtual bool IsInteractable();
    virtual uint32_t GetOverwriteInteractableToolTip();
    virtual uint32_t GetOverwriteDropToolTip();
    virtual uint32_t GetOverwriteTapToolTip();
    virtual bool32_t IsCastShadowAtNight();
    virtual void CleanupWhenDeleted(int param1);
    virtual IMPRESSIVE_TYPE GetImpressiveType();
    virtual float GetImpressiveIntensity(IMPRESSIVE_TYPE type);
    virtual float GetImpressiveValue(Living* param1, Reaction* param2);
    virtual float GetUpdateOfBoredomValue(Reaction* param1, GameThingWithPos* param2);

    // --- Type predicates (vtable 0x1B8-0x4FC) ---
    // Massive set of "Is*" predicates, almost all return false in base class.
    // These are overridden by derived classes (Object, Villager, Creature, etc.)
    virtual bool IsTown_0();
    virtual bool IsTown_1(Creature* creature);
    virtual bool IsActivityObjectWhichAngerAppliesTo(Creature* creature);
    virtual bool IsActivityObjectWhichCompassionAppliesTo(Creature* creature);
    virtual bool IsActivityObjectWhichPlayfulnessAppliesTo(Creature* creature);
    virtual bool IsTownBelongingToAnotherPlayer(Creature* creature);
    virtual bool32_t TrueFunction();
    virtual bool32_t FalseFunction();
    virtual bool32_t IsNotLiving();
    virtual bool32_t IsSuitableForCreatureActivity();
    virtual bool32_t IsTownCentre();
    virtual bool32_t IsTotemStatue();
    virtual bool32_t IsTownDesireFlag();
    virtual bool32_t IsRock_1(Creature* creature);
    virtual bool32_t IsRock_0();
    virtual bool32_t IsSpellDispenser();
    virtual bool32_t IsMist();
    virtual bool32_t IsQueryIcon();
    virtual bool32_t IsStreetLight();
    virtual bool32_t IsStreetLantern();
    virtual bool32_t IsAbode();
    virtual bool32_t IsField_1(Creature* creature);
    virtual bool32_t IsField_0();
    virtual bool32_t IsBuildingMaterial();
    virtual bool32_t IsMagicFireBall();
    virtual bool32_t IsSuitableForCreatureAction();
    virtual bool32_t IsCitadelHeart();
    virtual bool32_t IsDamaged();
    virtual bool32_t CanBeHealedByCreature(Creature* creature);
    virtual bool32_t CanBeEatenByCreature(Creature* creature);
    virtual bool32_t CanCreatureEatMe(Creature* creature);
    virtual bool32_t CanBeAttackedByCreature(Creature* creature);
    virtual bool32_t CanBeFrighteningToCreature(Creature* creature);
    virtual bool32_t CanBeHelpedByCreature(Creature* creature);
    virtual bool32_t CanBePlayedWithByCreature(Creature* creature);
    virtual bool32_t CanBeImpressedByCreature(Creature* creature);
    virtual bool32_t CanBeInspectedByCreature(Creature* creature);
    virtual bool32_t CanBePoodUponByCreature(Creature* creature);
    virtual bool32_t CanBeBefriendedByCreature(Creature* creature);
    virtual bool32_t CanBeSleptNextToByCreature(Creature* creature);
    virtual bool32_t CanBePickedUpByCreature(Creature* creature);
    virtual bool32_t CanBeStrokedByCreature(Creature* creature);
    virtual bool32_t CanBeKissedByCreature(Creature* creature);
    virtual bool32_t CanBeSetOnFire(Creature* creature);
    virtual bool32_t CanBeStompedOnByCreature(Creature* creature);
    virtual bool32_t CanBeThrownByCreature(Creature* creature);
    virtual bool32_t CanBeGivenToVillager(Creature* creature);
    virtual bool32_t CanBePutInAStoragePit(Creature* creature);
    virtual bool32_t CanBeDestroyedByStoning(Creature* creature);
    virtual bool32_t CanBeStonedAndEatenByCreature(Creature* creature);
    virtual bool32_t CanBeExaminedByCreature(Creature* creature);
    virtual bool32_t CanBeFoughtByCreature(Creature* creature);
    virtual bool32_t CanReceiveGifts(Creature* creature);
    virtual bool32_t CanActAsAContainer(Creature* creature);
    virtual bool32_t IsBeingBuilt(Creature* creature);
    virtual bool32_t NeedsRepair(Creature* creature);
    virtual bool32_t IsOnFire(Creature* creature);
    virtual bool32_t IsNotOnFire(Creature* creature);
    virtual bool32_t CanBeUsedForBuilding(Creature* creature);
    virtual bool32_t IsMushroom(Creature* creature);
    virtual bool32_t CanBeUsedForRepair(Creature* creature);
    virtual bool32_t CanBeGivenToTown(Creature* creature);
    virtual bool32_t CanBeUsedToHoldWater(Creature* creature);
    virtual bool32_t CanBePutInFoodPile(Creature* creature);
    virtual bool32_t CanBePutInWoodPile(Creature* creature);
    virtual bool32_t CanHaveMagicFoodCastOnMe(Creature* creature);
    virtual bool32_t CanHaveMagicWoodCastOnMe(Creature* creature);
    virtual bool32_t CanBeBroughtBackToCitadel(Creature* creature);
    virtual bool32_t IsVillager(Creature* creature);
    virtual bool32_t IsVillagerFarFromHome(Creature* creature);
    virtual bool32_t IsVillagerInTownWithoutManyBreeders(Creature* creature);
    virtual bool32_t IsVillagerNotWorshipping(Creature* creature);
    virtual bool32_t IsVillagerBelongingToOtherPlayer(Creature* creature);
    virtual bool32_t IsCow(Creature* creature);
    virtual bool32_t CanBePoodOn(Creature* creature);
    virtual bool32_t IsVillagerWhoHasNotBeenImpressedRecently(Creature* creature);
    virtual bool32_t IsVillagerWhoHasNotBeenDancedWithRecently(Creature* creature);
    virtual bool32_t DoesVillagerBelongToATownWhichIsAlreadyImpressed(Creature* creature);
    virtual bool32_t DoesTotemBelongToATownWhichIsVeryImpressedIndeed(Creature* creature);
    virtual bool32_t IsDominantCreature(Creature* creature);
    virtual bool32_t CanBeDancedWith(Creature* creature);
    virtual bool32_t IsAggressive(Creature* creature);
    virtual bool32_t IsStoragePit(Creature* creature);
    virtual bool32_t IsWorshipSite_1();
    virtual bool32_t IsWorshipSite_0(Creature* creature);
    virtual WorshipSite* GetWorshipSite();
    virtual bool32_t IsWorkshop_0();
    virtual bool32_t IsWorkshop_1(Creature* creature);
    virtual bool32_t IsBuildingWhichIsBeingBuilt(Creature* creature);
    virtual bool32_t IsStoragePitWithFoodInIt(Creature* creature);
    virtual bool32_t IsFieldWhichNeedsWatering(Creature* creature);
    virtual bool32_t IsFieldWithFoodInIt(Creature* creature);
    virtual bool32_t IsFieldBelongingToAnotherPlayer(Creature* creature);
    virtual bool32_t IsStoragePitBelongingToAnotherPlayer(Creature* creature);
    virtual bool32_t IsStoragePitBelongingToMyPlayer(Creature* creature);
    virtual bool32_t BenefitsFromHavingWaterSprinkledOnIt(Creature* creature);
    virtual bool32_t IsTree_1();
    virtual bool32_t IsTree_0(Creature* creature);
    virtual bool32_t IsTreeNotTooNearPlannedForest(Creature* creature);
    virtual bool32_t IsTreeBigEnoughForCreature(Creature* creature);
    virtual bool32_t IsAFoodPileOutsideStoragePit(Creature* creature);
    virtual bool32_t IsAWoodPileOutsideStoragePit(Creature* creature);
    virtual bool32_t IsDoingSomethingInteresting(Creature* creature);
    virtual bool32_t CanBeUsedForBuildingHomeByCreature(Creature* creature);
    virtual bool32_t IsPickupableRock(Creature* creature);
    virtual bool32_t IsCitadelPart_0();
    virtual bool32_t IsCitadelPart_1(Creature* creature);
    virtual bool32_t IsPlayingFootball(Creature* creature);
    virtual bool32_t IsPlayingFootballAndMySideHasJustScored(Creature* creature);
    virtual bool32_t IsPlayingFootballAndOtherSideHasJustScored(Creature* creature);
    virtual bool32_t CanBeBroughtHomeByCreature(Creature* creature);
    virtual bool32_t IsAnimalBelongingToOtherPlayer(Creature* creature);
    virtual bool32_t IsOneOffSpellBelongingToOtherPlayer(Creature* creature);
    virtual bool32_t IsOneOffSpellAggressive(Creature* creature);
    virtual bool32_t IsOneOffSpellCompassionate(Creature* creature);
    virtual bool32_t IsOneOffSpellPlayful(Creature* creature);
    virtual bool32_t IsOneOffSpellToRestoreHealth(Creature* creature);
    virtual bool32_t CanBeKickedByCreature(Creature* creature);
    virtual bool32_t CanBeStolenByCreature(Creature* creature);
    virtual bool32_t IsStealableByCreature(Creature* creature);
    virtual bool32_t IsStealableSpell(Creature* creature);
    virtual bool32_t IsStealableScaffold(Creature* creature);
    virtual bool32_t IsTownBelongingToOtherPlayer(Creature* creature);
    virtual bool32_t IsTotemWithStealableSpell(Creature* creature);
    virtual bool32_t IsCreatureAvailableForJointActivity(Creature* creature);
    virtual bool32_t IsCreatureNotAvailableForJointActivity(Creature* creature);
    virtual bool32_t IsToyAwayFromHome(Creature* creature);
    virtual bool32_t IsToy(Creature* creature);
    virtual bool32_t IsToyBall(Creature* creature);
    virtual bool32_t IsToyDie(Creature* creature);
    virtual bool32_t IsToyCuddly(Creature* creature);
    virtual bool32_t IsLiving_1() const;
    virtual bool32_t IsLiving_0(Creature* creature) const;
    virtual bool32_t IsFence();
    virtual bool32_t IsSpellIcon();
    virtual bool32_t NothingScareyNearMe() const;
    virtual bool32_t CanBeUsedForThrowingDamageByCreature(Creature* creature);
    virtual bool32_t IsCreatureWhoSeemsFriendly(Creature* creature);
    virtual bool32_t CanBeThrownInTheSeaPlayfully(Creature* creature);
    virtual uint32_t GetCreatureMimicType();
    virtual float GetHowMuchCreatureWantsToLookAtMe();
    virtual bool32_t IsFlock() const;
    virtual bool32_t IsDance() const;
    virtual bool32_t IsReward() const;
    virtual bool32_t IsScriptContainer() const;
    virtual bool32_t IsWeather() const;
    virtual bool32_t IsSpell() const;
    virtual bool32_t IsDeletedWhenReleasedFromScript();
    virtual bool32_t IsMobileWallHug() const;
    virtual bool32_t IsActive() const;
    virtual bool32_t IsObjectTurningTooFastForCameraToFollowSmoothly();
    virtual void CalculateWhereIWillBeAfterNSeconds(float seconds, LHPoint* outPos);
    virtual uint32_t AttitudeToCreatureEating();
    virtual const char* GetText();
    virtual float CalculateDesireForFood();
    virtual float CalculateDesireForRest();
    virtual float CalculatePeopleHidingIndicator();
    virtual float GetHeight();
    virtual bool32_t IsReadyForNewScriptAction();
    virtual int ForDrawFXGetNumVertices();
    virtual void ForDrawFXGetVertexPos(int param1, LHPoint* param2);
    virtual void SetInScript(int param1);
    virtual void SetControlledByScript(int param1);
    virtual DEATH_REASON GetDeathReason();
    virtual bool32_t IsInScript();
    virtual bool32_t IsMaleVillager();
    virtual bool32_t IsFemaleVillager();
    virtual bool32_t IsAnimal();
    virtual bool32_t IsAChild();
    virtual bool32_t IsHouse();
    virtual bool32_t IsObject();
    virtual bool32_t IsFootball();
    virtual bool32_t IsCitadel();
    virtual bool32_t IsForest();
    virtual bool32_t IsMobileObject();
    virtual bool32_t IsMobileStatic();
    virtual bool32_t IsAnyKindOfTree();
    virtual bool32_t IsDeadTree();
    virtual bool32_t IsPileFood();
    virtual bool32_t IsFeature();
    virtual bool32_t IsScriptMarker();
    virtual bool32_t IsScriptHighlight();
    virtual bool32_t IsWonder();
    virtual bool32_t IsInfluenceRing();
    virtual bool32_t IsPuzzleGame();
    virtual bool32_t IsScaffold();
    virtual bool32_t IsSkeleton() const;
    virtual bool32_t IsPoisoned();
    virtual bool32_t IsSpeedUp();
    virtual bool32_t IsParticleContainer();
    virtual bool32_t IsSacrificeAltar();
    virtual bool32_t IsPot();
    virtual bool32_t IsComputerPlayer();
    virtual bool32_t CanBeThrownByPlayer();
    virtual void SetSkeleton(int index);
    virtual bool32_t IsSpellSeed();
    virtual bool32_t IsSpellShield();
    virtual bool32_t IsPileResource();
    virtual bool32_t IsScriptTimer();
    virtual bool32_t CreateBuildingSite();
    virtual HELP_TEXT GetQueryFirstEnumText();
    virtual HELP_TEXT GetQueryLastEnumText();
    virtual uint32_t GetFOVHelpMessageSet();
    virtual uint32_t GetFOVHelpCondition();
    virtual uint32_t GetScriptObjectType();
    virtual float GetFacingDirection();
    virtual void SetAffectedByWind(int param1);
    virtual float GetReactionPower();
    virtual void GetSpellCastPos(MapCoords* outPos);
    virtual void CleanUpBeforeReset();

    // === Fields ===
    MapCoords coords;        // 0x14 — position in the game world
    Object*   map_child;     // 0x20 — map object linked list child
    uint16_t  field_0x24;    // 0x24 — bitfield (IsCannotBePickedUp, IsInScript, etc.)
    uint8_t   field_0x26;    // 0x26
    // 0x27 padding to align to 0x28
};
static_assert(sizeof(GameThingWithPos) == 0x28, "GameThingWithPos size mismatch");
