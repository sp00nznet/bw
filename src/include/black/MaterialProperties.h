#pragma once
// MaterialProperties — rendering material settings
// From bw1-decomp LH3DMaterial.h
//
// Size: 0x5 bytes
// Used by GJUtils for mesh material configuration.

#include <cstdint>

struct MaterialProperties {
    bool field_0x0;   // 0x00
    bool field_0x1;   // 0x01
    bool cull;        // 0x02
    bool field_0x3;   // 0x03
    bool field_0x4;   // 0x04
};
static_assert(sizeof(MaterialProperties) == 0x5, "MaterialProperties size mismatch");
