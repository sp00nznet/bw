#pragma once
// Rock — throwable/moveable rock object
// Struct layout from bw1-decomp
//
// Size: 0x94 bytes (inherits 0x88 from MobileStatic)
// Vtable: 0x910 bytes (extends MobileStatic's 0x90C with 1 new method)
//
// Rock is a MobileStatic that can be thrown, used as a weapon by
// creatures, and serves as a building material (ore resource).
// It adds one new virtual (IsMovable) and overrides ~30 methods.

#include "MobileStatic.h"

// Forward declarations
struct GMobileStaticInfo;

struct Rock : public MobileStatic {
    // === Overrides of GameThing virtuals ===
    GPlayer* GetPlayer() override;
    void SetPlayer(GPlayer* player) override;
    uint32_t AddResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool param4, const MapCoords& coords, int param6) override;
    uint32_t RemoveResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool* param4) override;
    char* GetDebugText() override;
    uint32_t GetSampleForAttack() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    void PhysicsEditorCreate(int param1) override;
    uint32_t GetOverwriteTapToolTip() override;
    bool32_t IsRock_0() override;
    bool32_t CanBeAttackedByCreature(Creature* creature) override;
    bool32_t CanBePickedUpByCreature(Creature* creature) override;
    uint32_t GetCreatureMimicType() override;
    bool32_t CanBeThrownByPlayer() override;
    uint32_t GetScriptObjectType() override;

    // === Overrides of Object virtuals ===
    void ActualMoveMapObject(const MapCoords& coords) override;
    void Draw() override;
    bool IsResourceStore(RESOURCE_TYPE type) override;
    RESOURCE_TYPE GetResourceType() override;
    int GetDefaultResource() override;
    bool32_t ValidForPlaceInHand(GInterfaceStatus* status) override;
    uint32_t InterfaceValidToTap(GInterfaceStatus* status) override;
    uint32_t InterfaceTap(GInterfaceStatus* status) override;
    uint32_t GetPhysicsConstantsType() override;
    void EndPhysics(PhysicsObject* param1, bool param2) override;
    bool InteractsWithPhysicsObjects() override;
    void ReactToPhysicsImpact(PhysicsObject* param1, bool param2) override;
    bool ShouldFootpathsGoRound() override;

    // === New virtual method (vtable 0x90C) ===
    virtual bool IsMovable();

    // === Fields ===
    uint32_t field_0x88;   // 0x88
    float    field_0x8c;   // 0x8C
    GPlayer* player;       // 0x90
};
static_assert(sizeof(Rock) == 0x94, "Rock size mismatch");
