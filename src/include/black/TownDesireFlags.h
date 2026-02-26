#pragma once
// TownDesireFlags — visual flags showing town desires
// Struct layout from bw1-decomp
//
// Size: 0x98 bytes (inherits 0x54 from Object)

#include "Object.h"

struct TownDesireFlags : public Object {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    Town* GetTown() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    bool32_t IsTownDesireFlag() override;
    HELP_TEXT GetQueryFirstEnumText() override;
    HELP_TEXT GetQueryLastEnumText() override;
    uint32_t GetFOVHelpMessageSet() override;
    uint32_t GetFOVHelpCondition() override;

    // === Overrides of Object virtuals ===
    uint32_t Process() override;
    int GetMesh() const override;
    void Draw() override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    bool32_t IsEffectReceiver(EffectValues* param1) override;
    bool InteractsWithPhysicsObjects() override;
    bool CreatureMustAvoid(Creature* param1) override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;

    // === Fields ===
    uint8_t field_0x54[0x44];  // 0x54
};
static_assert(sizeof(TownDesireFlags) == 0x98, "TownDesireFlags size mismatch");
