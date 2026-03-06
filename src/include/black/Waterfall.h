#pragma once
// GWaterfall — waterfall visual effect (extends Object)
// Struct layout from bw1-decomp
// Size: 0x58 bytes

#include "Object.h"

struct LHOSFile;

struct GWaterfall : public Object {
    uint8_t field_0x54[0x4];  // 0x54

    // === Virtual overrides ===
    virtual char*    GetDebugText() override { return nullptr; }
    virtual uint32_t GetSaveType() override { return 0; }
    virtual uint32_t Load(void* file) override { return 0; }
    virtual uint32_t Save(void* file) override { return 0; }
    virtual void     ToBeDeleted(int) override {}
    virtual void     CallVirtualFunctionsForCreation(const MapCoords&) override {}
    virtual size_t   SaveObject(LHOSFile*, const MapCoords*) override { return 0; }
};
static_assert(sizeof(GWaterfall) == 0x58, "GWaterfall size mismatch");
