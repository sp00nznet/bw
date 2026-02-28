#pragma once
// LocalBase — base class for locally-allocated objects (not from heap)
// Struct layout from bw1-decomp
//
// Size: 0x8 bytes (empty Base subclass with custom operator new)
// Inheritance: Base (0x8) → LocalBase (0x8)

#include "Base.h"

struct LocalBase : Base {
};
static_assert(sizeof(LocalBase) == 0x8, "LocalBase size mismatch");
