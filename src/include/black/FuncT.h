#pragma once
// FuncT — evaluatable function interface
// Struct layout from bw1-decomp (FuncT.h)
//
// Size: 0x4 bytes (own vtable hierarchy, NOT Base-derived)
// Vtable: 1 entry (Eval)

#include <cstdint>

struct FuncT {
    virtual void Eval(float param_1, float* param_2, float* param_3) const;  // vtable[0]
};
static_assert(sizeof(FuncT) == 0x4, "FuncT size mismatch");
