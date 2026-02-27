#pragma once
#include "PileWood.h"

enum IMPRESSIVE_TYPE : uint32_t;

struct MagicWood : public PileWood {
    // === Overrides of GameThing virtuals ===
    GPlayer* GetPlayer() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    IMPRESSIVE_TYPE GetImpressiveType() override;
    bool32_t IsAWoodPileOutsideStoragePit(Creature* creature) override;

    // === Overrides of Object virtuals ===
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
};
static_assert(sizeof(MagicWood) == 0xB4, "MagicWood size mismatch");
