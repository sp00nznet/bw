#pragma once
// CameraModeNew3 — primary gameplay camera mode
// Struct layout from bw1-decomp (CameraModeNew3.h)
//
// Size: 0x300 bytes (extends CameraMode with 6 new virtuals at 0x48+)
// This is the main free-roaming camera used during gameplay.

#include "CameraMode.h"
#include "types.h"
#include "Zoomer.h"

struct CameraExclusion;
struct GArena;
struct LHMatrix;

enum CameraModeNew3_fight_status_t : uint32_t {
    CameraModeNew3_fight_status_t_0x0 = 0x0,
    CameraModeNew3_fight_status_t_0x1 = 0x1,
    CameraModeNew3_fight_status_t_0x2 = 0x2,
    _CameraModeNew3_fight_status_t_COUNT = 0x3
};

struct CameraModeNew3 : public CameraMode {
    // === CameraMode overrides ===
    void Update() override;

    // === New virtuals (slots 18-23, vtable offset 0x48-0x5C) ===
    virtual void Initialise();
    virtual void Reinitialise(bool param_2);
    virtual void FlyToPosFoc(LHPoint* param_2, LHPoint* param_3, float param_4);
    virtual void SetupVia(const LHPoint* param_2, const LHPoint* param_3, const LHPoint* param_4, float param_5);
    virtual uint32_t GetCameraFeatures();
    virtual void ForceRotateAboutPoint(LHPoint* point);

    // === Non-virtual methods ===
    void UpdateTricons();
    void UpdateClickParams(const LHPoint* param_1, const LHPoint* param_2, bool param_3);
    float GetAltitude(LHPoint* param_1);
    void SetAltitudeAndNormal(LHPoint* param_1, LHPoint* normal);
    void DragFocusOntoLand(LHPoint* param_1, LHPoint* param_2);
    bool UpdateStrafe(LHPoint* param_1, LHPoint* param_2, float* param_3, float* param_4, float param_5, uint32_t param_6);
    bool WantToQuitFight(LHPoint param_1, LHPoint param_2, float param_3);
    void StartFight(GArena* arena);
    void EndFightNow(int param_1);

    // === Static methods ===
    static float CalcPerpDistance(LHPoint* param_1, LHPoint* param_2, LHPoint* param_3);
    static float FindBestAngle(float param_1, float param_2, float* param_3, float* param_4, float* param_5);

    // === Fields ===
    uint32_t field_0x8;                                  // 0x08
    LHPoint origin;                                      // 0x0C
    LHPoint heading;                                     // 0x18
    LHPoint field_0x24;                                  // 0x24
    LHPoint field_0x30;                                  // 0x30
    uint32_t field_0x3c;                                 // 0x3C
    uint32_t field_0x40;                                 // 0x40
    uint32_t has_fight;                                  // 0x44
    GArena* arena;                                       // 0x48
    uint8_t field_0x4c;                                  // 0x4C
    uint8_t field_0x4d;                                  // 0x4D
    uint8_t field_0x4e;                                  // 0x4E
    uint8_t field_0x4f;                                  // 0x4F
    float yaw_0;                                         // 0x50
    float pitch_0;                                       // 0x54
    float fight_distance;                                // 0x58
    int fight_time_left;                                 // 0x5C
    int time_in_arena;                                   // 0x60
    CameraModeNew3_fight_status_t fight_status;          // 0x64
    LHPoint field_0x68;                                  // 0x68
    float field_0x74;                                    // 0x74
    float elapsed_time;                                  // 0x78
    LHPoint rotate_point;                                // 0x7C
    bool rotate_around_point;                            // 0x88
    CAMERA_MODE_MOUSE_STATUS mouse_buttons;              // 0x8C
    uint32_t tricon_0x90;                                // 0x90
    uint32_t tricon_0x94;                                // 0x94
    Point2D from_screen_centre;                          // 0x98
    Point2D from_screen_centre_abs;                      // 0xA0
    LHCoord mouse_delta;                                 // 0xA8
    LHCoord mouse_pos_current;                           // 0xB0
    LHCoord rotate_around_mouse_pos;                     // 0xB8
    LHCoord mouse_pos_1;                                 // 0xC0
    bool screen_centre_hit;                              // 0xC8
    LHPoint mouse_hit_point;                             // 0xCC
    LHPoint last_grab_mouse_hit_point;                   // 0xD8
    float yaw_1;                                         // 0xE4
    float pitch_1;                                       // 0xE8
    float perp_distance_0xec;                            // 0xEC
    LHPoint screen_centre_hit_point;                     // 0xF0
    float distance_0xfc;                                 // 0xFC
    uint8_t field_0x100;                                 // 0x100
    uint8_t field_0x101;                                 // 0x101
    uint8_t field_0x102;                                 // 0x102
    uint8_t field_0x103;                                 // 0x103
    LHPoint field_0x104;                                 // 0x104
    LHPoint field_0x110;                                 // 0x110
    LHPoint field_0x11c;                                 // 0x11C
    int field_0x128;                                     // 0x128
    LHPoint heading_0x12c;                               // 0x12C
    LHPoint field_0x138;                                 // 0x138
    bool hand_hit;                                       // 0x144
    uint8_t field_0x145;                                 // 0x145
    uint8_t field_0x146;                                 // 0x146
    uint8_t field_0x147;                                 // 0x147
    bool hit_0x148;                                      // 0x148
    LHPoint field_0x14c;                                 // 0x14C
    double field_0x158;                                  // 0x158
    LHPoint field_0x160;                                 // 0x160
    LHPoint field_0x16c;                                 // 0x16C
    uint8_t field_0x178[0x30];                           // 0x178 (LHMatrix)
    float distance_0x1a8;                                // 0x1A8
    CAMERA_MODE_HAND_STATUS hand_status;                 // 0x1AC
    LHCoord field_0x1b0;                                 // 0x1B0
    Point2D field_0x1b8;                                 // 0x1B8
    float length_0x1c0;                                  // 0x1C0
    float vertical_distance;                             // 0x1C4
    LHPoint fallback_origin;                             // 0x1C8
    LHPoint fallback_heading;                            // 0x1D4
    LHPoint field_0x1e0;                                 // 0x1E0
    LHPoint origin_0x1ec;                                // 0x1EC
    LHPoint field_0x1f8;                                 // 0x1F8
    LHPoint heading_0x204;                               // 0x204
    Zoomer field_0x210;                                  // 0x210
    Zoomer3d field_0x240;                                // 0x240
    bool field_0x2d0;                                    // 0x2D0
    uint8_t field_0x2d1;                                 // 0x2D1
    uint8_t field_0x2d2;                                 // 0x2D2
    uint8_t field_0x2d3;                                 // 0x2D3
    LHCoord mouse_pos_previous;                          // 0x2D4
    LHCoord field_0x2dc;                                 // 0x2DC
    float heading_distance;                              // 0x2E4
    float idle_time;                                     // 0x2E8
    int field_0x2ec;                                     // 0x2EC
    int field_0x2f0;                                     // 0x2F0
    CameraExclusion* camera_exclusion;                   // 0x2F4
    uint32_t field_0x2f8;                                // 0x2F8
    uint32_t field_0x2fc;                                // 0x2FC
};
static_assert(sizeof(CameraModeNew3) == 0x300, "CameraModeNew3 size mismatch");
