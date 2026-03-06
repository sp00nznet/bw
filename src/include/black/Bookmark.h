#pragma once
// BookmarkGraphic — visual bookmark on the map
// Struct layout from bw1-decomp
// Size: 0x8 bytes

#include <stdint.h>

enum CREATURE_TYPE : uint32_t;
struct LH3DSprite;

struct BookmarkGraphic {
    LH3DSprite*   sprite;  // 0x0
    CREATURE_TYPE type;    // 0x4
};
static_assert(sizeof(BookmarkGraphic) == 0x8, "BookmarkGraphic size mismatch");
