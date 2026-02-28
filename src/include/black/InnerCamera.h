#pragma once
// InnerCamera — camera controller for citadel interior rooms
// Struct layout from bw1-decomp (InnerCamera.h)
//
// Size: 0x46C bytes
// Own vtable hierarchy (12 entries) — NOT related to Base/GameThing

#include "types.h"
#include "Zoomer.h"
#include "LHCoord.h"

struct InnerRoom;
struct LH3DMesh;
struct LH3DCamera;

struct InnerCamera {
    virtual void ReloadCamera(char* param_1);
    virtual void PreDraw();
    virtual void Init(char* param_1);
    virtual void Reinit();
    virtual void Close();
    virtual uint32_t CalcDoorHit(InnerRoom* room, LHCoord coord, float param_3, bool param_4);
    virtual void Update(InnerRoom* room, float param_2, int param_3, int param_4, const LHCoord* coord, bool param_6);
    virtual void UpdateMain(InnerRoom* room, float param_2, int param_3, int param_4, const LHCoord* coord, bool param_6);
    virtual void UpdateState(InnerRoom* room, float param_2, int param_3, int param_4, const LHCoord* coord, bool param_6);
    virtual void FocusOnSubMesh(LH3DMesh* mesh, int param_2, float param_3, float param_4, float param_5);
    virtual void TriggerIntro(bool param_1, Zoomer3d* zoomer1, Zoomer3d* zoomer2);
    virtual ~InnerCamera();

    // === Fields ===
    Zoomer3d    zoomer_pos;         // 0x04
    Zoomer3d    zoomer_foc;         // 0x94
    uint32_t    field_0x124;        // 0x124
    uint32_t    field_0x128;        // 0x128
    int32_t     field_0x12c;        // 0x12C
    uint8_t     field_0x130[0x4];   // 0x130
    uint32_t    field_0x134;        // 0x134
    LHCoord*    field_0x138;        // 0x138
    uint32_t    field_0x13c;        // 0x13C
    uint32_t    field_0x140;        // 0x140
    float       field_0x144;        // 0x144
    uint32_t    field_0x148;        // 0x148
    uint32_t    field_0x14c;        // 0x14C
    uint32_t    field_0x150;        // 0x150
    uint32_t    field_0x154;        // 0x154
    int         field_0x158;        // 0x158
    int         field_0x15c;        // 0x15C
    char        filename[0x100];    // 0x160
    LHPoint     field_0x260;        // 0x260
    LHPoint     field_0x26c;        // 0x26C
    Zoomer3d    field_0x278;        // 0x278
    Zoomer3d    field_0x308;        // 0x308
    uint8_t     field_0x398;        // 0x398
    uint8_t     field_0x399;        // 0x399
    uint8_t     field_0x39a;        // 0x39A
    uint8_t     field_0x39b;        // 0x39B
    LHPoint     pos_0x39c;          // 0x39C
    LHPoint     foc_0x3a8;          // 0x3A8
    uint8_t     field_0x3b4[0x18];  // 0x3B4
    float       field_0x3cc;        // 0x3CC
    float       field_0x3d0;        // 0x3D0
    LHPoint     current_pos;        // 0x3D4
    LHPoint     current_foc;        // 0x3E0
    Point2D     field_0x3ec;        // 0x3EC
    uint8_t     field_0x3f4;        // 0x3F4
    uint8_t     field_0x3f5[0x3];   // 0x3F5
    uint32_t    field_0x3f8;        // 0x3F8
    float       field_0x3fc;        // 0x3FC
    float       field_0x400;        // 0x400
    uint8_t     field_0x404[0x1C];  // 0x404
    float       field_0x420;        // 0x420
    float       field_0x424;        // 0x424
    uint32_t    field_0x428;        // 0x428
    LHPoint     field_0x42c;        // 0x42C
    uint32_t    field_0x438;        // 0x438
    LH3DCamera* lh3dcamera;         // 0x43C
    uint8_t     field_0x440[0xC];   // 0x440
    int32_t     field_0x44c;        // 0x44C
    uint32_t    field_0x450;        // 0x450
    LHPoint     field_0x454;        // 0x454
    LHPoint     field_0x460;        // 0x460
};
static_assert(sizeof(InnerCamera) == 0x46C, "InnerCamera size mismatch");
