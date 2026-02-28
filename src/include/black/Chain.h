#pragma once
// Chain — particle chain effect entity
// Struct layout from bw1-decomp (Chain.h)
//
// Size: 0x14 bytes (inherits PSysBase, no new fields)

#include "PSysBase.h"

struct Chain : public PSysBase {
    ~Chain() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(Chain) == 0x14, "Chain size mismatch");
