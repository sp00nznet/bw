#pragma once
// GCameraEditor — camera path editor process
// Struct layout from bw1-decomp (CameraEditor.h)
//
// Size: 0x28 bytes (extends Prss)

#include "Prss.h"
#include "types.h"

struct LH3DWay;

struct GCameraEditor : public Prss {
    // === Static methods ===
    static void FinalDraw();
    static void CreateSegFile();
    static void Draw3DPart();

    // === Fields ===
    uint8_t field_0x10[0x18];  // 0x10
};
static_assert(sizeof(GCameraEditor) == 0x28, "GCameraEditor size mismatch");

struct GCameraEditor_InfoTrack {
    int32_t  field_0x0;      // 0x00
    uint32_t field_0x4;      // 0x04
    int32_t  field_0x8;      // 0x08
    uint32_t field_0xc;      // 0x0C
    GCameraEditor_InfoTrack* next;  // 0x10
    uint32_t field_0x14;     // 0x14
    LHPoint  field_0x18;     // 0x18
    LHPoint  field_0x24;     // 0x24
    int32_t  field_0x30;     // 0x30
    LH3DWay* field_0x34;     // 0x34
    int32_t* field_0x38;     // 0x38
};
static_assert(sizeof(GCameraEditor_InfoTrack) == 0x3C, "GCameraEditor_InfoTrack size mismatch");
