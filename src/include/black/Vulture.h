#pragma once
// Vulture — vulture animal entity (Dove subclass)
// Struct layout from bw1-decomp (file: AnimalVulture.h, struct: Vulture)

#include "Dove.h"

struct Vulture : public Dove {
    char* GetDebugText() override;
    uint32_t GetSaveType() override;
    bool32_t CanBeFrighteningToCreature(Creature* creature) override;
};
static_assert(sizeof(Vulture) == 0x148, "Vulture size mismatch");
