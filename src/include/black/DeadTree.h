#pragma once
// DeadTree — dead tree resource with physics and fire
// Struct layout from bw1-decomp
//
// Size: 0xA0 bytes (inherits 0x94 from Rock)

#include "Rock.h"

// Forward declarations
struct GestureSystemPacketData;

struct DeadTree : public Rock {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    uint32_t RemoveResource(RESOURCE_TYPE type, uint32_t amount,
                            GInterfaceStatus* status, bool* param4) override;
    char* GetDebugText() override;
    uint32_t GetGuidanceResourceType() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    bool32_t IsRock_0() override;
    bool32_t IsAnyKindOfTree() override;
    bool32_t IsDeadTree() override;
    uint32_t GetScriptObjectType() override;

    // === Overrides of Object virtuals ===
    HOLD_TYPE GetHoldType() override;
    float GetHoldRadius() override;
    float GetHoldLoweringMultiplier() override;
    bool32_t HandShouldFeelWithMeshIntersect() override;
    LHPoint* GetDefaultFireCentrePos(LHPoint* pos) override;
    float GetDefaultFireRadius() override;
    void Draw() override;
    float GetWeight() override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    float GetWoodValue() override;
    RESOURCE_TYPE GetResourceType() override;
    int GetDefaultResource() override;
    void StartOnFire() override;
    void EndOnFire() override;
    uint32_t ValidToApplyThisToObject(GInterfaceStatus* status, Object* param2) override;
    uint32_t ApplyThisToObject(GInterfaceStatus* status, Object* param2,
                               GestureSystemPacketData* param3) override;
    uint32_t ApplyThisToMapCoord(GInterfaceStatus* status, const MapCoords* param2,
                                 GestureSystemPacketData* param3) override;
    uint32_t InterfaceValidToTap(GInterfaceStatus* status) override;
    uint32_t InterfaceTap(GInterfaceStatus* status) override;
    uint32_t GetPhysicsConstantsType() override;
    void SetUpPhysOb(PhysOb* param1) override;
    void EndPhysics(PhysicsObject* param1, bool param2) override;
    bool InteractsWithPhysicsObjects() override;
    void ReactToPhysicsImpact(PhysicsObject* param1, bool param2) override;
    bool CanBecomeAPhysicsObject() override;
    bool CreatureMustAvoid(Creature* param1) override;
    bool IsARootedObject() override;
    SOUND_COLLISION_TYPE GetCollideSoundType() override;
    uint32_t GetCarriedTreeType() override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;
    IMMERSION_EFFECT_TYPE GetInHandImmersionTexture() override;

    // === Fields ===
    uint8_t field_0x94[0xC]; // 0x94
};
static_assert(sizeof(DeadTree) == 0xA0, "DeadTree size mismatch");
