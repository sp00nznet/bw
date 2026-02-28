#pragma once
// FireGraphic — fire visual effect particle entity
// Struct layout from bw1-decomp (FireGraphic.h)
//
// Size: 0x14 bytes (inherits PSysBase, no new fields)
// Also defines FireGraphicSpritePos (originally FireGraphic::SpritePos)

#include "PSysBase.h"

struct FireGraphic : public PSysBase {
    ~FireGraphic() override;
};
static_assert(sizeof(FireGraphic) == 0x14, "FireGraphic size mismatch");

// Originally FireGraphic::SpritePos — separate RTTI type
struct FireGraphicSpritePos : public PSysBase {
    ~FireGraphicSpritePos() override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(FireGraphicSpritePos) == 0x14, "FireGraphicSpritePos size mismatch");
