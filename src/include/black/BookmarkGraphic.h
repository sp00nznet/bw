#pragma once
#include <cstdint>

enum CREATURE_TYPE : uint32_t;
struct LH3DSprite;

struct BookmarkGraphic {
    LH3DSprite*   sprite;  // 0x00
    CREATURE_TYPE type;    // 0x04
};
static_assert(sizeof(BookmarkGraphic) == 0x8, "BookmarkGraphic size mismatch");
