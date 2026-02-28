#pragma once
// PSysManager — particle system manager entity
// Struct layout from bw1-decomp (PSysManager.h)
//
// Size: 0xE4 bytes (inherits PSysBase + 0xD0 bytes of fields)

#include "PSysBase.h"

struct PSysManager : public PSysBase {
    ~PSysManager() override;
    GPlayer* GetPlayer() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Fields ===
    uint8_t field_0x14[0xD0];  // 0x14
};
static_assert(sizeof(PSysManager) == 0xE4, "PSysManager size mismatch");
