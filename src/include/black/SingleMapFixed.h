#pragma once
// SingleMapFixed — fixed object occupying a single map cell
// Struct layout from bw1-decomp
//
// Size: 0x5C bytes (inherits 0x58 from Fixed)
// Vtable: 0x868 bytes (extends Fixed's 0x864 with 1 method)

#include "Fixed.h"

struct SingleMapFixed : public Fixed {
    // === New virtual methods (vtable 0x864) ===
    virtual void CreateCollideData();

    // === Fields ===
    NewCollide* collide_data;  // 0x58 — collision geometry
};
static_assert(sizeof(SingleMapFixed) == 0x5C, "SingleMapFixed size mismatch");
