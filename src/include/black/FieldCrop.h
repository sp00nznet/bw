#pragma once
// FieldCrop — harvested crop from a field
// Struct layout from bw1-decomp
//
// Size: 0x68 bytes (same as MobileObject — no new fields)
// Vtable: uses MobileObject's vtable layout
//
// FieldCrop is a mobile crop object that can be picked up and
// delivered to storage pits or applied to fields.

#include "MobileObject.h"

// Forward declarations
struct GestureSystemPacketData;
struct PhysOb;

struct FieldCrop : public MobileObject {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    bool IsFunctional() override;
    char* GetDebugText() override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    void PhysicsEditorCreate(int param) override;

    // === Overrides of Object virtuals ===
    void InsertMapObject() override;
    void RemoveMapObject() override;
    HOLD_TYPE GetHoldType() override;
    void SetLife(float life) override;
    uint32_t InterfaceSetInMagicHand(GInterfaceStatus* status) override;
    uint32_t ValidToApplyThisToObject(GInterfaceStatus* status, Object* target) override;
    uint32_t ApplyThisToObject(GInterfaceStatus* status, Object* target,
                               GestureSystemPacketData* data) override;
    uint32_t ApplyThisToMapCoord(GInterfaceStatus* status, const MapCoords* coords,
                                 GestureSystemPacketData* data) override;
    uint32_t GetPhysicsConstantsType() override;
    void SetUpPhysOb(PhysOb* physOb) override;
    bool InteractsWithPhysicsObjects() override;
    bool CanBecomeAPhysicsObject() override;
    bool CreatureMustAvoid(Creature* creature) override;
    bool IsARootedObject() override;
};
static_assert(sizeof(FieldCrop) == 0x68, "FieldCrop size mismatch");
