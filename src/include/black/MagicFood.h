#pragma once
#include "PileFood.h"

enum IMPRESSIVE_TYPE : uint32_t;

struct MagicFood : public PileFood {
    // === Overrides of GameThing virtuals ===
    GPlayer* GetPlayer() override;
    void SetPlayer(GPlayer* player) override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    IMPRESSIVE_TYPE GetImpressiveType() override;
    bool32_t IsAFoodPileOutsideStoragePit(Creature* creature) override;

    // === Overrides of Object virtuals ===
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
};
static_assert(sizeof(MagicFood) == 0xBC, "MagicFood size mismatch");
