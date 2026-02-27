#pragma once
// CreaturePreviousLesson — previous lesson data for learning
// Struct layout from bw1-decomp (CreaturePreviousLesson.h)
//
// Size: 0x120C bytes (inherits 0x8 from Base)

#include "Base.h"

struct CreaturePreviousLesson : public Base {
    uint32_t field_0x8;            // 0x08
    uint8_t  field_0xc[0x1200];    // 0x0C-0x120B
};
static_assert(sizeof(CreaturePreviousLesson) == 0x120C, "CreaturePreviousLesson size mismatch");
