#pragma once
// HairGroup — creature hair simulation group
// Struct layout from bw1-decomp (HairGroup.h)
//
// Size: 0x7C bytes (plain data, no vtable)

#include <cstdint>
#include <cstdbool>

// Forward declarations
struct LH3DHair;
struct LHFile;

struct HairGroup {
    bool      field_0x0;      // 0x00
    int       hair_count;     // 0x04
    uint32_t  field_0x8[3];   // 0x08
    uint32_t  field_0x14[3];  // 0x14
    uint32_t  field_0x20[3];  // 0x20
    float     field_0x2c[3];  // 0x2C
    float     field_0x38[3];  // 0x38
    float     field_0x44[3];  // 0x44
    float     field_0x50[3];  // 0x50
    uint32_t  count_0x5c;     // 0x5C
    uint32_t  field_0x60;     // 0x60
    uint32_t  field_0x64;     // 0x64
    uint32_t  field_0x68;     // 0x68
    uint32_t  field_0x6c;     // 0x6C
    uint32_t  field_0x70;     // 0x70
    LH3DHair* hairs;          // 0x74
    uint32_t  field_0x78;     // 0x78
};
static_assert(sizeof(HairGroup) == 0x7C, "HairGroup size mismatch");
