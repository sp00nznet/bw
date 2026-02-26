#pragma once
// Poo — creature waste product
// Struct layout from bw1-decomp
//
// Size: 0x68 bytes (same as MobileObject — no new fields)
// Vtable: uses MobileObject's vtable layout
//
// Poo is dropped by creatures and can fertilize fields.

#include "MobileObject.h"

struct Poo : public MobileObject {
    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    uint32_t GetScriptObjectType() override;

    // === Overrides of Object virtuals ===
    void InsertMapObject() override;
    HOLD_TYPE GetHoldType() override;
    uint32_t GetPhysicsConstantsType() override;
};
static_assert(sizeof(Poo) == 0x68, "Poo size mismatch");
