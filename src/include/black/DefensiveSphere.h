#pragma once
// DefensiveSphere — spherical defensive shield effect
// Struct layout from bw1-decomp (DefensiveSphere.h)
//
// Size: 0x14 bytes (extends DefensiveShield, no new fields)

#include "DefensiveShield.h"

struct DefensiveSphere : public DefensiveShield {
    ~DefensiveSphere() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(DefensiveSphere) == 0x14, "DefensiveSphere size mismatch");
