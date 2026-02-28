#pragma once
// DefensiveShield — defensive shield particle effect entity
// Struct layout from bw1-decomp (DefensiveShield.h)
//
// Size: 0x14 bytes (inherits PSysBase, no new fields)

#include "PSysBase.h"

struct DefensiveShield : public PSysBase {
    ~DefensiveShield() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(DefensiveShield) == 0x14, "DefensiveShield size mismatch");
