#pragma once
// FireFly — glowing sprite-based flying object
// Struct layout from bw1-decomp, implementations from v1.0 decompilation
//
// Size: 0xC4 bytes (inherits 0x54 from Object)

#include "Object.h"

// Forward declarations
struct LH3DSprite;

struct FireFly : public Object {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    bool IsMoving() const override;

    // === Overrides of Object virtuals ===
    void Draw() override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    bool InteractsWithPhysicsObjects() override;
    void ReactToPhysicsImpact(PhysicsObject* param1, bool param2) override;
    bool CanBecomeAPhysicsObject() override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;

    // === Fields ===
    uint32_t    field_0x54;     // 0x54
    LH3DSprite* sprite;         // 0x58
    uint32_t    field_0x5c;     // 0x5C
    MapCoords   field_0x60;     // 0x60
    MapCoords   field_0x6c;     // 0x6C
    MapCoords   field_0x78;     // 0x78
    uint8_t     field_0x84[0xC];// 0x84
    uint32_t    field_0x90;     // 0x90
    uint32_t    field_0x94;     // 0x94
    uint32_t    field_0x98;     // 0x98
    float       field_0x9c;     // 0x9C
    float       field_0xa0;     // 0xA0
    float       field_0xa4;     // 0xA4
    float       field_0xa8;     // 0xA8
    float       field_0xac;     // 0xAC
    float       field_0xb0;     // 0xB0
    float       field_0xb4;     // 0xB4
    float       field_0xb8;     // 0xB8
    float       field_0xbc;     // 0xBC
    uint8_t     field_0xc0;     // 0xC0
};
static_assert(sizeof(FireFly) == 0xC4, "FireFly size mismatch");
