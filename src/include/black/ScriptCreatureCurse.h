#pragma once
// ScriptCreatureCurse — creature curse effect data
// Struct layout from bw1-decomp (ScriptCreatureCurse.h)
//
// Size: 0xC bytes (plain data, no vtable)

#include <cstdint>

struct ScriptCreatureCurse {
    float height;     // 0x0
    float strength;   // 0x4
    float alignment;  // 0x8
};
static_assert(sizeof(ScriptCreatureCurse) == 0xC, "ScriptCreatureCurse size mismatch");
