#pragma once
#include "Villager.h"

struct GSpecialVillagerInfo;

struct SpecialVillager : public Villager {
    // === Overrides ===
    char*       GetDebugText() override;
    uint32_t    Load(GameOSFile* file) override;
    uint32_t    Save(GameOSFile* file) override;
    uint32_t    GetSaveType() override;
    void        Draw() override;
    const char* GetVillagerName() override;

    // === Fields ===
    uint32_t field_0x130;  // 0x130
};
static_assert(sizeof(SpecialVillager) == 0x134, "SpecialVillager size mismatch");
