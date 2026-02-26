#pragma once
// Pot — food/wood container object
// Struct layout from bw1-decomp
//
// Size: 0x78 bytes (inherits 0x68 from MobileObject)
// Vtable: 0x86C bytes (extends MobileObject's 0x85C with 4 new methods)
//
// Pot is a moveable container for food or wood resources.
// It can be picked up, thrown, poisoned, set on fire,
// and applied to other objects or map positions.

#include "MobileObject.h"

// Forward declarations
struct GPotInfo;

struct Pot : public MobileObject {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    uint32_t JustAddResource(RESOURCE_TYPE type, uint32_t amount, bool param3) override;
    uint32_t JustRemoveResource(RESOURCE_TYPE type, uint32_t amount, bool* param3) override;
    uint32_t JustGetResource(RESOURCE_TYPE type, uint32_t amount, bool* param3) override;
    uint32_t GetResource(RESOURCE_TYPE type) override;
    uint32_t AddResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool param4, const MapCoords& coords, int param6) override;
    uint32_t RemoveResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool* param4) override;
    char* GetDebugText() override;
    uint32_t GetGuidanceResourceType() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    uint32_t GetCreatureBeliefType() override;
    uint32_t GetOverwriteInteractableToolTip() override;
    bool32_t IsPoisoned() override;
    bool32_t IsSpeedUp() override;
    bool32_t IsPot() override;
    uint32_t GetScriptObjectType() override;

    // === Overrides of Object virtuals ===
    void Draw() override;
    void DrawOutOfMap(bool param1) override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    float GetFoodValue(FOOD_TYPE type) override;
    bool IsResourceStore(RESOURCE_TYPE type) override;
    bool DeleteObjectAndTakeResource(Object* param1, GInterfaceStatus* param2) override;
    float GetRadiusMultiplierForApplyingPotToPos() override;
    RESOURCE_TYPE GetResourceType() override;
    int GetDefaultResource() override;
    void SetPoisonedResource(RESOURCE_TYPE type, int param2) override;
    void SetPoisoned(int param1) override;
    void StartOnFire() override;
    void EndOnFire() override;
    bool32_t InterfaceSetInMagicHand(GInterfaceStatus* status) override;
    uint32_t ValidToApplyThisToObject(GInterfaceStatus* status, Object* param2) override;
    uint32_t ApplyThisToObject(GInterfaceStatus* status, Object* param2, GestureSystemPacketData* param3) override;
    uint32_t ApplyThisToMapCoord(GInterfaceStatus* status, const MapCoords* param2, GestureSystemPacketData* param3) override;
    bool32_t IsEffectReceiver(EffectValues* param1) override;
    uint32_t InitialisePhysicsFromHand(LHPoint* p1, LHPoint* p2, GInterfaceStatus* p3, Object* p4, int p5) override;
    uint32_t GetPhysicsConstantsType() override;
    void EndPhysics(PhysicsObject* param1, bool param2) override;
    bool InteractsWithPhysicsObjects() override;
    void ReactToPhysicsImpact(PhysicsObject* param1, bool param2) override;
    bool CanBecomeAPhysicsObject() override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;
    bool IsAPotFromABuildingSite() override;

    // === New virtual methods (vtable 0x85C-0x868) ===
    virtual void SetSize();
    virtual bool IsPartOfStructure();
    virtual void SetSpeedUp(int speed);
    virtual void SetMultiMapFixed(MultiMapFixed* multiMapFixed);

    // === Fields ===
    RESOURCE_TYPE field_0x68;  // 0x68 — resource type this pot holds
    uint32_t      field_0x6c;  // 0x6C — resource amount?
    uint32_t      field_0x70;  // 0x70
    uint8_t       field_0x74;  // 0x74 — flags (poisoned, etc.)
};
static_assert(sizeof(Pot) == 0x78, "Pot size mismatch");
