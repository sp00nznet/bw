#pragma once
// GBallInfo — info for ball objects
// Struct layout from bw1-decomp (BallInfo.h)
//
// Size: 0x140 bytes (extends GMobileObjectInfo)
// Also defines GPBallInfo (0x114)

#include "GMobileObjectInfo.h"

struct GPBallInfo : public GMobileObjectInfo {
};
static_assert(sizeof(GPBallInfo) == 0x114, "GPBallInfo size mismatch");

struct GBallInfo : public GMobileObjectInfo {
    uint8_t field_0x114[0x2C]; // 0x114
};
static_assert(sizeof(GBallInfo) == 0x140, "GBallInfo size mismatch");
