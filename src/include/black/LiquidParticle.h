#pragma once
#include <cstdint>
#include "LHPoint.h"

struct GInterface;

struct LiquidParticle {
    float field_0x0;   float field_0x4;   float field_0x8;
    float field_0xc;   float field_0x10;  float field_0x14;
    float field_0x18;  float field_0x1c;  float field_0x20;
    float field_0x24;  float field_0x28;
};
static_assert(sizeof(LiquidParticle) == 0x2C, "LiquidParticle size mismatch");

struct LiquidParticleGroup {
    LiquidParticle       particle_buffer[0x400]; // 0x0000
    uint32_t             particle_count;         // 0xB000
    LHPoint              point;                  // 0xB004
    LiquidParticleGroup* next;                   // 0xB010
    GInterface*          iface;                  // 0xB014
    void (__cdecl*       sparkle_func)(LiquidParticleGroup*, GInterface*); // 0xB018
};
static_assert(sizeof(LiquidParticleGroup) == 0xB01C, "LiquidParticleGroup size mismatch");
