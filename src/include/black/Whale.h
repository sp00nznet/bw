#pragma once
// Whale — ocean creature
// Struct layout from bw1-decomp
//
// Size: 0x74 bytes (inherits 0x68 from MobileObject)
// Vtable: uses MobileObject's vtable layout

#include "MobileObject.h"

struct Whale : public MobileObject {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
    void ResolveLoad() override;

    // === Overrides of GameThingWithPos virtuals ===
    void PhysicsEditorCreate(int param) override;

    // === Overrides of Object virtuals ===
    uint32_t Process() override;
    void Draw() override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    bool InteractsWithPhysicsObjects() override;
    bool CanBecomeAPhysicsObject() override;

    // === Fields ===
    uint8_t field_0x68[0xc];   // 0x68 — whale state data
};
static_assert(sizeof(Whale) == 0x74, "Whale size mismatch");
