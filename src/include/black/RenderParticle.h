#pragma once
// RenderParticle — renderable particle entity
// Struct layout from bw1-decomp (PSysRenderParticle.h)
//
// Size: 0x18 bytes (inherits PSysBase, adds one field)

#include "PSysBase.h"

struct RenderParticle : public PSysBase {
    ~RenderParticle() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Fields ===
    uint32_t field_0x14;  // 0x14
};
static_assert(sizeof(RenderParticle) == 0x18, "RenderParticle size mismatch");
