#pragma once
// SpellPointInf — spell point influence particle entity
// Struct layout from bw1-decomp (SpellPointInf.h)
//
// Size: 0x14 bytes (inherits PSysBase, no new fields)

#include "PSysBase.h"

struct SpellPointInf : public PSysBase {
    ~SpellPointInf() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(SpellPointInf) == 0x14, "SpellPointInf size mismatch");
