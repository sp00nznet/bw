#pragma once
// CPUCheck — CPU capability detection
// Struct layout from bw1-decomp (CPUCheck.h)
//
// Size: 0x4 bytes (own vtable hierarchy, NOT Base-derived)
// Vtable: 1 entry (destructor)

#include <cstdint>

struct CPUCheck {
    virtual ~CPUCheck();  // vtable[0]
};
static_assert(sizeof(CPUCheck) == 0x4, "CPUCheck size mismatch");
