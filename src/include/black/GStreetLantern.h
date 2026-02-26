#pragma once
// GStreetLantern — street lantern illumination object
// Struct layout from bw1-decomp
//
// Size: 0x64 bytes (inherits 0x54 from Object + 0x10 bytes)
// Simple methods at 0x005614xx are packed 16 bytes apart.
// Complex methods at 0x007348xx-0x00734dxx.

#include "Object.h"

struct GStreetLantern : public Object {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    bool32_t IsStreetLantern() override;
    uint32_t GetScriptObjectType() override;

    // === Overrides of Object virtuals ===
    void Draw() override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    bool InteractsWithPhysicsObjects() override;
    bool CreatureMustAvoid(Creature* param1) override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;

    // === Fields ===
    uint8_t field_0x54[0x10];  // 0x54
};
static_assert(sizeof(GStreetLantern) == 0x64, "GStreetLantern size mismatch");
