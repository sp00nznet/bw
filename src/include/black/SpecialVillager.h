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
    uint32_t field_0x130;  // 0x128 in v1.0 (Villager is 0x128 there; the name keeps its v1.41 offset)
};
static_assert(sizeof(SpecialVillager) == 0x12C, "SpecialVillager: v1.0 Villager (0x128) plus one field");
