#pragma once
// LH3DStorm — weather storm system base
// Struct layout from lionhead lh3dlib (LH3DStorm.h)
//
// Size: 0x4 bytes (own vtable hierarchy)
// Vtable: 5 entries (Update, DrawClouds, DebugDraw, CalcAtmos, destructor)

#include "types.h"

struct WeatherInfo;

struct LH3DStorm {
    virtual void Update(float param_1);                           // vtable[0]
    virtual void DrawClouds();                                    // vtable[1]
    virtual void DebugDraw();                                     // vtable[2]
    virtual void CalcAtmos(LHPoint* point, WeatherInfo* info);    // vtable[3]
    virtual ~LH3DStorm();                                         // vtable[4]
};
static_assert(sizeof(LH3DStorm) == 0x4, "LH3DStorm size mismatch");
