#pragma once
// GRand — game random number generation
// Struct layout from bw1-decomp (Rand.h)
//
// No struct data — just static utility methods

#include <cstdint>

struct GRand {
    static int GameRand(uint32_t max);
    static float GameFloatRand(float scale);
    static uint32_t LocalRand(long param_1);
};
