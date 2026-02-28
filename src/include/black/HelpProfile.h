#pragma once
// CameraHelpAccumulator / HelpProfile — help event tracking
// Struct layout from bw1-decomp
//
// CameraHelpAccumulator: 0x10C bytes (plain data, opaque)
// HelpProfile: 0x3358 bytes (Base-derived, array of 0x31 accumulators)

#include "Base.h"

struct CameraHelpAccumulator {
    uint8_t field_0x0[0x10C];  // 0x00
};
static_assert(sizeof(CameraHelpAccumulator) == 0x10C, "CameraHelpAccumulator size mismatch");

struct HelpProfile : Base {
    CameraHelpAccumulator accumulators[0x31];  // 0x08
    uint32_t              field_0x3354;         // 0x3354
};
static_assert(sizeof(HelpProfile) == 0x3358, "HelpProfile size mismatch");
