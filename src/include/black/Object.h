#pragma once
// Object — base class for all positioned game objects with 3D representation
// Struct layout from bw1-decomp, implementations from v1.0 decompilation
//
// Size: 0x54 bytes (inherits 0x28 from GameThingWithPos)
// Vtable: 0x85C bytes (~535 entries, extends GameThingWithPos's 0x500)

#include "GameThingWithPos.h"
#include "types.h"

// Forward declarations
struct ControlHandUpdateInfo;
struct EffectNumbers;
struct EffectValues;
struct FireEffect;
struct Game3DObject;
struct GestureSystemPacketData;
struct GObjectInfo;
struct LH3DSprite;
struct LHMatrix;
struct LHOSFile;
struct LHRegion;
struct LandscapeVortex;
struct MapCell;
struct MultiMapFixed;
struct NewCollide;
struct PhysOb;
struct PhysicsObject;
struct Point2D;
struct RPHolder;
struct Scaffold;
struct SpellWater;

// Food type enum
enum FOOD_TYPE : uint32_t {
    FOOD_TYPE_0 = 0,
    FOOD_TYPE_COUNT = 1
};

// Effect type enum (partial)
enum EFFECT_TYPE : uint32_t {
    EFFECT_TYPE_NONE = 0,
};

// Hold type enum
enum HOLD_TYPE : uint32_t {
    HOLD_TYPE_DEFAULT = 0,
};

// Immersion effect type enum
enum IMMERSION_EFFECT_TYPE : uint32_t {
    IMMERSION_EFFECT_TYPE_NONE = 0,
};

// Sound collision type enum
enum SOUND_COLLISION_TYPE : uint32_t {
    SOUND_COLLISION_TYPE_NONE = 0,
};

// Tribe type enum (partial)
enum TRIBE_TYPE : uint32_t {
    TRIBE_TYPE_NONE = 0,
};

// 3D object type enum
enum LH3DObject_ObjectType : uint32_t {
    LH3D_OBJECT_TYPE_DEFAULT = 0,
};

// 3D color (ARGB packed)
struct LH3DColor {
    uint32_t color;
};

struct Object : public GameThingWithPos {
    // === Overrides of GameThingWithPos virtuals ===
    bool IsMoving() const override;

    // === Virtual methods extending GameThingWithPos's vtable ===
    // These add ~215 new virtual slots (0x500 through 0x858)

    // --- Orientation and scale (0x500-0x528) ---
    virtual void DestroyedByBeam();
    virtual float GetXAngle();
    virtual float GetYAngle();
    virtual float GetZAngle();
    virtual void SetFocus(const LHPoint* focus);
    virtual void SetXYZAngles(float x, float y, float z);
    virtual void SetXYZAnglesAndScale(float x, float y, float z, float scale);
    virtual void SetJustScale(float scale);
    virtual void SetYJustAngle(float angle);
    virtual void SetYAngle(float angle);
    virtual void UpdateFrom3DPosition();
    virtual uint32_t MoveAlongPath();

    // --- Map and 3D object management (0x530-0x568) ---
    virtual bool IsReachable();
    virtual bool BlocksTownClearArea() const;
    virtual void Create3DObject();
    virtual Object* GetMapChild(const MapCell* cell);
    virtual void SetMapChild(Object* object, MapCell* cell);
    virtual void InsertMapObject();
    virtual void RemoveMapObject();
    virtual void InsertMapObjectToCell(MapCell* cell);
    virtual void RemoveMapObjectFromCell(MapCell* cell);
    virtual bool IsObjectInMap_1(MapCell* cell);
    virtual bool IsObjectInMapCheck();
    virtual int MoveMapObject(const MapCoords& coords);
    virtual void ActualMoveMapObject(const MapCoords& coords);
    virtual Object* GetPtr();
    virtual float GetMeshRadius() const;
    virtual Game3DObject* Get3DObjectForPSys();

    // --- Particle system / fire (0x570-0x580) ---
    virtual bool GetPSysFireFlameMatrix(LHMatrix* matrix);
    virtual bool GetPSysFireLocalRndFlamePos(LHPoint* point, int* param2);
    virtual bool GetPSysFireWorldFlamePos(const LHPoint* param1, int param2, LHPoint* param3);
    virtual float GetPSysFireLocalFlameScale();
    virtual uint32_t GetPSysFireMaxFlames();
    virtual float GetSpotEffectPower() const;
    virtual float GetAggressorValueFromDamage(float param1) const;

    // --- Hold / interface (0x590-0x5A4) ---
    virtual HOLD_TYPE GetHoldType();
    virtual float GetHoldRadius();
    virtual float GetHoldLoweringMultiplier();
    virtual float GetHoldYRotate();
    virtual bool32_t HandShouldFeelWithMeshIntersect();
    virtual void SetSpecularColor(LH3DColor color);
    virtual LH3DColor GetSpecularColor();
    virtual void SetBeliefSprite(LH3DSprite* sprite);
    virtual LH3DSprite* GetBeliefSprite();

    // --- Life and effects (0x5B0-0x5FC) ---
    virtual void SetLife(float life);
    virtual bool IsAlive();
    virtual void ReduceLife(float value, GPlayer* player);
    virtual void IncreaseLife(float value);
    virtual float GetSacrificeValue();
    virtual void ReduceLifeDueToBurning(float param1, GPlayer* param2);
    virtual void FillInEffectDefenceMultiplier(EffectNumbers* param1);
    virtual void ApplyEffect(EffectValues* param1, int param2);
    virtual float GetDamageEffect(EffectValues* values);
    virtual float GetHealEffect(EffectValues* values);
    virtual void* GetActualObjectToEffect(GPlayer* player, bool param2);
    virtual void DrawValue(int param1, float param2);
    virtual void ScaffoldMoved(Scaffold* scaffold);
    virtual float GetHeatCapacity();
    virtual void GetFireGPHXDrawn(bool* p1, bool* p2, bool* p3, bool* p4);
    virtual float GetRainCoolingMultiplier();
    virtual LHPoint* GetDefaultFireCentrePos(LHPoint* pos);
    virtual float GetDefaultFireRadius();
    virtual uint32_t DestroyedByEffect(GPlayer* player, float param2);

    // --- Process / state (0x600-0x628) ---
    virtual uint32_t Process();
    virtual uint32_t ProcessBySpell(Spell* spell);
    virtual void ApplySingleEffect(EFFECT_TYPE type, float param2, GameThing* param3, const MapCoords* param4);
    virtual int GetMesh() const;
    virtual int GetDetailMesh(int detail);
    virtual void Draw();
    virtual void DrawOutOfMap(bool param1);
    virtual bool IsG3DObjectDrawnInHand();
    virtual void GetDrawRegion(LHRegion* region);
    virtual uint32_t ProcessState();
    virtual float GetProjectileSpeed();
    virtual bool CanBePickedUp();
    virtual bool32_t CanBeCrushed();
    virtual float GetTopPos();
    virtual float GetVillagerHugRadius();
    virtual float GetWeight();
    virtual void GetWorldMatrix(LHMatrix* out);
    virtual bool CanBeSuckedIntoVortex(LandscapeVortex* param1);
    virtual uint32_t GetDiscipleStateIfInteractedWith(GInterfaceStatus* status, Villager* villager);
    virtual MapCoords* GetWorkingPos(MapCoords* out, Object* param2);
    virtual float GetHeightForHandAboveInteractObject();
    virtual uint32_t GetHandHelpMessageSet();
    virtual uint32_t GetHandHelpCondition();
    virtual void CallVirtualFunctionsForCreation(const MapCoords& coords);
    virtual LH3DObject_ObjectType Get3DType();

    // --- Food / resource (0x660-0x698) ---
    virtual float GetFoodValue(FOOD_TYPE type);
    virtual float GetWoodValue();
    virtual FOOD_TYPE GetFoodType();
    virtual float GetImpressiveValue_1();
    virtual bool IsSpellSeedReturnPoint() const;
    virtual bool32_t IsABeliever();
    virtual MultiMapFixed* AsMultiMapFixed();
    virtual float ApplyWaterSpell(SpellWater* spell);
    virtual bool IsResourceStore(RESOURCE_TYPE type);
    virtual bool DeleteObjectAndTakeResource(Object* param1, GInterfaceStatus* param2);
    virtual float GetRadiusMultiplierForApplyingPotToPos();
    virtual bool DoCreatureMimicAfterAddingResource(RESOURCE_TYPE type, GInterfaceStatus* status);
    virtual RESOURCE_TYPE GetResourceType();
    virtual int GetDefaultResource();
    virtual void SetPoisonedResource(RESOURCE_TYPE type, int param2);
    virtual void SetPoisoned(int param1);

    // --- Combat / interaction (0x6A0-0x6C4) ---
    virtual bool IsLockedInInteract();
    virtual bool SetDying();
    virtual bool IsAttackable(Object* param1);
    virtual bool IsAllied(Object* param1);
    virtual bool IsTouching_1(MapCoords* p1, MapCoords* p2) const;
    virtual bool IsTouching_2(MapCoords* p1) const;
    virtual bool IsTouching_3(Object* p1, float p2) const;
    virtual void StartOnFire();
    virtual void EndOnFire();
    virtual float GetDistanceFromObject_1(Object* param1);
    virtual float GetTribalPower(TRIBE_TYPE type);

    // --- Interface / network (0x6D0-0x778) ---
    virtual bool32_t ValidForLockedSelectProcess(GInterfaceStatus* status);
    virtual bool32_t NetworkFriendlyStartLockedSelect(GInterfaceStatus* status);
    virtual bool32_t NetworkUnfriendlyStartLockedSelect();
    virtual bool32_t IsReadyForNetworkUnfriendlyLockedSelect();
    virtual bool32_t NetworkUnfriendlyLockedSelect(ControlHandUpdateInfo* param1);
    virtual bool32_t GetReadyForNetworkUnfriendlyEndLockedSelect();
    virtual bool32_t IsReadyForNetworkUnfriendlyEndLockedSelect();
    virtual bool32_t NetworkUnfriendlyEndLockedSelect();
    virtual bool32_t NetworkFriendlyEndLockedSelect(GInterfaceStatus* status);
    virtual bool32_t ValidAsInterfaceTarget();
    virtual bool32_t ValidAsInterfaceLeashTarget();
    virtual bool32_t SelectOnlyAfterRecSystem();
    virtual bool32_t ValidForPlaceInHand(GInterfaceStatus* status);
    virtual bool32_t InterfaceSetInMagicHand(GInterfaceStatus* status);
    virtual bool32_t InterfaceSetOutMagicHand(GInterfaceStatus* status);
    virtual bool32_t ValidToRemoveFromHand(GInterfaceStatus* status, const MapCoords* param2);
    virtual uint32_t RemoveFromHand(GInterfaceStatus* status, const MapCoords* param2);
    virtual bool32_t ValidToShakeFromHand();
    virtual bool32_t InterfaceMustBeInInfluenceForInteraction();
    virtual bool32_t IsTuggable();
    virtual uint32_t ValidToApplyThisToObject(GInterfaceStatus* status, Object* param2);
    virtual uint32_t ApplyThisToObject(GInterfaceStatus* status, Object* param2, GestureSystemPacketData* param3);
    virtual uint32_t ValidToApplyThisToMapCoord(GInterfaceStatus* status, const MapCoords* param2);
    virtual uint32_t ApplyThisToMapCoord(GInterfaceStatus* status, const MapCoords* param2, GestureSystemPacketData* param3);
    virtual uint32_t ValidForLockedApplyProcess(GInterfaceStatus* status);
    virtual uint32_t ApplyUnlockProcess(GInterfaceStatus* status);
    virtual uint32_t IsInterfacePowerUpWhenInHand() const;
    virtual uint32_t ApplyOnlyAfterRecSystem();
    virtual uint32_t ApplyOnlyAfterReleased();
    virtual uint32_t InterfaceValidToTap(GInterfaceStatus* status);
    virtual uint32_t InterfaceTap(GInterfaceStatus* status);
    virtual uint32_t InterfaceValidToGiveObject(GInterfaceStatus* status, Object* param2);
    virtual uint32_t InterfaceGiveObject(GInterfaceStatus* status, Object* param2);
    virtual uint32_t InterfaceValidToInteractAsMapCoordsObject(GInterfaceStatus* status);
    virtual uint32_t InterfaceInteractAsMapCoordsObject(GInterfaceStatus* status);
    virtual uint32_t ThrowObjectFromHand(GInterfaceStatus* status, int param2);
    virtual uint32_t ValidToSelectFightThisToMapCoord(GInterfaceStatus* status, const MapCoords* param2);
    virtual uint32_t ValidToApplyFightThisToMapCoord(GInterfaceStatus* status, const MapCoords* param2);
    virtual uint32_t SelectFightThisToMapCoord(GInterfaceStatus* status, const MapCoords* param2);
    virtual uint32_t ApplyFightThisToMapCoord(GInterfaceStatus* status, const MapCoords* param2);
    virtual uint32_t ValidToFightThisToObject(GInterfaceStatus* status, const MapCoords* param2);
    virtual uint32_t FightThisToObject(GInterfaceStatus* status, Object* param2);
    virtual bool32_t IsEffectReceiver(EffectValues* param1);
    virtual bool32_t CanBeDestroyedBySpell_1(Spell* param1);
    virtual float GetImportance();

    // --- Physics (0x780-0x7B4) ---
    virtual uint32_t InitialisePhysicsFromHand(LHPoint* p1, LHPoint* p2, GInterfaceStatus* p3, Object* p4, int p5);
    virtual uint32_t InitialisePhysics(const LHPoint* p1, const LHPoint* p2, Object* p3, bool p4, GInterfaceStatus* p5);
    virtual uint32_t GetPhysicsConstantsType();
    virtual void SetUpPhysOb(PhysOb* param1);
    virtual void EndPhysics(PhysicsObject* param1, bool param2);
    virtual uint32_t DropSfx();
    virtual void GetBoundingSphere(LHPoint* center, float* radius);
    virtual bool InteractsWithPhysicsObjects();
    virtual uint32_t ChecksVerticesVObjects();
    virtual void ShouldPhysicsRaiseObjectUntilNotIntersectingThis(Object* param1);
    virtual uint32_t PhysicallyDestroysAbodes();
    virtual void ReactToPhysicsImpact(PhysicsObject* param1, bool param2);
    virtual bool CanBecomeAPhysicsObject();
    virtual bool GetAlwaysRemainsInPhysicsInternalSystem();
    virtual bool HasSunk();

    // --- Creature avoidance / route (0x7BC-0x7D4) ---
    virtual bool CreatureMustAvoid(Creature* param1);
    virtual void AddToRoutePlan(RPHolder* p1, Creature* p2, int p3, void (*p4)(int, Point2D, float, int));
    virtual float GetRoutePlanRadius(Creature* param1);
    virtual bool32_t VillagerMustAvoid(Villager* param1);
    virtual bool IsFireMan();
    virtual bool IsARootedObject();
    virtual SOUND_COLLISION_TYPE GetCollideSoundType();
    virtual bool32_t IsSolidToNewAbode();
    virtual uint32_t RemoveFromGame();

    // --- Miscellaneous (0x7E0-0x858) ---
    virtual int GetLandingPointCount();
    virtual bool GetLandingPoint(uint8_t param1, LHPoint* param2);
    virtual uint32_t GetTastiness();
    virtual bool IsScary();
    virtual bool GetInspectObjectPos(Villager* param1, MapCoords* pos);
    virtual void DiscipleInHandNear(Villager* param1, GInterfaceStatus* status);
    virtual bool32_t GetSpecialPos(uint32_t index, MapCoords* pos);
    virtual GameThing* GetTownArtifact();
    virtual bool32_t IsTownArtifact();
    virtual bool ProcessInHand();
    virtual uint32_t ProcessInInteract(GInterfaceStatus* status);
    virtual uint32_t GetObjectCollide();
    virtual float CalculateForceAppliedBy(Living* param1);
    virtual bool IsPushable();
    virtual void PushObject_1(Living* param1, MapCoords* param2);
    virtual void PushObject_2(Living* param1);
    virtual uint32_t GetCarriedTreeType();
    virtual float GetFacingPitch();
    virtual void SetHeadPos(MapCoords* param1);
    virtual size_t SaveObject(LHOSFile* param1, const MapCoords* param2);
    virtual bool IsAPotFromABuildingSite();
    virtual void GetNearestEdgeOfObject(Object* param1);
    virtual void GetNearestPosOfObject(Object* param1);
    virtual void GetNearestEdgeToPos(const MapCoords* param1);
    virtual void GetNearestEdge(float param1, float param2);
    virtual IMMERSION_EFFECT_TYPE GetImmersionTexture();
    virtual IMMERSION_EFFECT_TYPE GetInHandImmersionTexture();
    virtual bool ShouldFootpathsGoRound();
    virtual void InitialiseIsFixedForMapList();
    virtual uint32_t StandAnimation();
    virtual NewCollide* GetCollideData() const;

    // === Fields ===
    const GObjectInfo* info;      // 0x28 — object type info
    MapCoords obj_coords;         // 0x2C — separate coords (arrival/desired position?)
    Object*   map_parent;         // 0x38 — map object tree parent
    uint32_t  field_0x3c;         // 0x3C
    Game3DObject* game_3d_object; // 0x40 — 3D representation
    FireEffect*   fire_effect;    // 0x44 — fire particle effect
    float     life;               // 0x48 — health (0.0 = dead, 1.0 = full)
    float     y_angle;            // 0x4C — rotation around Y axis
    float     scale;              // 0x50 — uniform scale factor
};
static_assert(sizeof(Object) == 0x54, "Object size mismatch");
