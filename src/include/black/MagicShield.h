#pragma once
#include "MapShield.h"

struct MagicShield : public MapShield {
    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of Object virtuals ===
    void Draw() override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    LH3DObject_ObjectType Get3DType() override;
    bool SetDying() override;
    bool32_t IsEffectReceiver(EffectValues* param1) override;
    bool InteractsWithPhysicsObjects() override;

    // === Overrides of MapShield virtuals ===
    void ProcessShield() override;
    void DrawShield() override;
    bool IsPointDefinietlyWithinShieldVolume(const MapCoords* point) override;
};
static_assert(sizeof(MagicShield) == 0x68, "MagicShield size mismatch");
