#pragma once
// MobileObject — moveable single-cell object (pots, mushrooms, etc.)
// Struct layout from bw1-decomp
//
// Size: 0x68 bytes (inherits 0x58 from Mobile)
// Vtable: 0x85C bytes (same as Mobile/Object — no new vtable slots)
//
// MobileObject is a Mobile (single-cell) object that can be picked up
// and carried. It serves as the base class for Pot (food/wood containers).
// In the original, it uses a union overlay for the vtable pointer,
// but in C++ the vtable is implicit.

#include "Mobile.h"

// Forward declarations
struct GMobileObjectInfo;

struct MobileObject : public Mobile {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    GPlayer* GetPlayer() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    void PhysicsEditorCreate(int param1) override;
    uint32_t GetCreatureBeliefType() override;
    bool32_t CanBePlayedWithByCreature(Creature* creature) override;
    bool32_t CanBeStompedOnByCreature(Creature* creature) override;
    bool32_t IsMushroom(Creature* creature) override;
    bool32_t CanBeUsedToHoldWater(Creature* creature) override;
    bool32_t CanBeThrownInTheSeaPlayfully(Creature* creature) override;
    uint32_t GetCreatureMimicType() override;
    bool32_t IsMobileObject() override;
    bool32_t IsPoisoned() override;
    uint32_t GetScriptObjectType() override;

    // === Overrides of Object virtuals ===
    float GetXAngle() override;
    float GetZAngle() override;
    void SetXYZAngles(float x, float y, float z) override;
    void SetXYZAnglesAndScale(float x, float y, float z, float scale) override;
    uint32_t MoveAlongPath() override;
    void Create3DObject() override;
    void InsertMapObjectToCell(MapCell* cell) override;
    void RemoveMapObjectFromCell(MapCell* cell) override;
    HOLD_TYPE GetHoldType() override;
    float GetHoldLoweringMultiplier() override;
    int GetMesh() const override;
    void Draw() override;
    bool CanBePickedUp() override;
    void GetWorldMatrix(LHMatrix* out) override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    RESOURCE_TYPE GetResourceType() override;
    int GetDefaultResource() override;
    uint32_t ValidToApplyThisToObject(GInterfaceStatus* status, Object* param2) override;
    uint32_t ApplyThisToObject(GInterfaceStatus* status, Object* param2, GestureSystemPacketData* param3) override;
    uint32_t GetPhysicsConstantsType() override;
    void ReactToPhysicsImpact(PhysicsObject* param1, bool param2) override;
    bool CanBecomeAPhysicsObject() override;
    void AddToRoutePlan(RPHolder* p1, Creature* p2, int p3, void (*p4)(int, Point2D, float, int)) override;
    uint32_t GetTastiness() override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;

    // === Fields ===
    Object*  object;      // 0x58 — associated/parent object
    uint32_t field_0x5c;  // 0x5C
    uint32_t field_0x60;  // 0x60
    uint32_t field_0x64;  // 0x64
};
static_assert(sizeof(MobileObject) == 0x68, "MobileObject size mismatch");
