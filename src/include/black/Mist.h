#pragma once
// Mist — fog/mist effect entity
// Struct layout from bw1-decomp
//
// Size: 0x54 bytes (inherits 0x28 from GameThingWithPos)

#include "GameThingWithPos.h"

struct Mist : public GameThingWithPos {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    GPlayer* GetPlayer() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
    void ResolveLoad() override;

    // === Overrides of GameThingWithPos virtuals ===
    uint32_t GetCreatureBeliefType() override;
    float GetDistanceFromObject(const MapCoords& target) override;
    bool32_t IsMist() override;
    const char* GetText() override;
    uint32_t GetScriptObjectType() override;

    // === Fields ===
    uint32_t    field_0x28;        // 0x28
    float       field_0x2c;        // 0x2C
    uint32_t    field_0x30;        // 0x30
    float       field_0x34;        // 0x34
    uint8_t     field_0x38[0x14];  // 0x38
    uint32_t    field_0x4c;        // 0x4C
    Mist*       next;              // 0x50
};
static_assert(sizeof(Mist) == 0x54, "Mist size mismatch");
