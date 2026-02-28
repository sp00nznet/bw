#pragma once
// GatheringText — text rendering and justification
// Struct layout from bw1-decomp (GatheringText.h)
//
// Types: TEXTJUSTIFY enum, GatheringText (0x1, plain data)

#include <cstdint>

enum TEXTJUSTIFY : uint32_t {
    TEXTJUSTIFY_LEFT         = 0x0,
    TEXTJUSTIFY_CENTRE       = 0x1,
    TEXTJUSTIFY_RIGHT        = 0x2,
    TEXTJUSTIFY_LEFT_BREAK   = 0x3,
    TEXTJUSTIFY_CENTRE_BREAK = 0x4,
};

struct GatheringText {
    uint8_t field_0x0;  // 0x0
};
static_assert(sizeof(GatheringText) == 0x1, "GatheringText size mismatch");
