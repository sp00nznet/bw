#pragma once
// LHDLL — dynamic library loader with vtable
// Struct layout from bw1-decomp
// Size: 0x24 bytes

#include <stdint.h>

struct LHDLL;
struct LHTransport;

struct LHDLLVftable {
    uint32_t (__fastcall* GetAPI)(LHDLL* self);     // 0x00
    uint32_t (__fastcall* ResetAPI)(LHDLL* self);   // 0x04
};
static_assert(sizeof(LHDLLVftable) == 0x8, "LHDLLVftable size mismatch");

struct LHDLL {
    LHDLLVftable* vftable;       // 0x00
    uint8_t       field_0x4;     // 0x04
    void*         hmodule;       // 0x08
    LHTransport*  transport;     // 0x0C
    int           field_0x10;    // 0x10
    uint32_t      field_0x14;    // 0x14
    uint32_t      field_0x18;    // 0x18
    uint32_t      field_0x1c;    // 0x1C
    char*         library_path;  // 0x20
};
static_assert(sizeof(LHDLL) == 0x24, "LHDLL size mismatch");
