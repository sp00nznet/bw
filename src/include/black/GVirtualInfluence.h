#pragma once
#include "Base.h"

struct GInterfaceStatus;

struct GVirtualInfluence : public Base {
    uint32_t          field_0x8;          // 0x08
    uint32_t          field_0xc;          // 0x0C
    uint32_t          field_0x10;         // 0x10
    uint32_t          field_0x14;         // 0x14
    uint32_t          field_0x18;         // 0x18
    uint32_t          field_0x1c;         // 0x1C
    uint32_t          field_0x20;         // 0x20
    uint32_t          field_0x24;         // 0x24
    uint32_t          field_0x28;         // 0x28
    uint32_t          field_0x2c;         // 0x2C
    float             field_0x30;         // 0x30
    float             field_0x34;         // 0x34
    GInterfaceStatus* interface_status;   // 0x38
    uint32_t          field_0x3c;         // 0x3C
    float             field_0x40;         // 0x40
    uint32_t          field_0x44;         // 0x44
    uint32_t          field_0x48;         // 0x48
    uint32_t          field_0x4c;         // 0x4C
    uint32_t          field_0x50;         // 0x50
    uint8_t           field_0x54[0xC];    // 0x54
};
static_assert(sizeof(GVirtualInfluence) == 0x60, "GVirtualInfluence size mismatch");
