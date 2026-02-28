#pragma once
// VortexObjectInfo — vortex object info particle entity
// Struct layout from bw1-decomp (VortexObjectInfo.h)
//
// Size: 0x14 bytes (inherits PSysBase, no new fields)

#include "PSysBase.h"

struct VortexObjectInfo : public PSysBase {
    ~VortexObjectInfo() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(VortexObjectInfo) == 0x14, "VortexObjectInfo size mismatch");
