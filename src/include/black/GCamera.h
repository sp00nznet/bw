#pragma once
// GCamera — main game camera
// Struct layout from bw1-decomp
//
// Size: 0x1D8 bytes (inherits 0x28 from GameThingWithPos)
// Vtable: extends GameThingWithPos
//
// Contains 12 CameraMode* slots, Zoomer3d structs for smooth
// heading/origin interpolation, and a FOV zoomer.

#include "GameThingWithPos.h"
#include "Zoomer.h"

// Forward declarations
struct CameraMode;

struct GCamera : public GameThingWithPos {
    // === Overrides of Base virtuals ===
    ~GCamera() override;                                            // 0x00441b30
    void ToBeDeleted(int param) override;                           // 0x00441ee0

    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;                                  // 0x00443840
    uint32_t Load(GameOSFile* file) override;                       // 0x004433a0
    uint32_t Save(GameOSFile* file) override;                       // 0x004430e0
    uint32_t GetSaveType() override;                                // 0x00441b20

    // === Overrides of GameThingWithPos virtuals ===
    bool IsMoving() const override;                                 // 0x00441b00
    const char* GetText() override;                                 // 0x00441af0
    float GetHeight() override;                                     // 0x00441b10

    // === Non-virtual methods ===
    bool CantExitCurrentMode();                                     // 0x00441b70
    void SwitchToViewMode(CameraMode* mode);                        // 0x00441cd0
    void CheckStackedModesForValidity();                            // 0x00441d40
    void Validate();                                                // 0x00441f50
    void Update();                                                  // 0x00441f80
    void UpdateGameThingWithPosData();                              // 0x00442ef0
    void SetCameraFov(float fov, float time);                       // 0x00443680

    // === Static methods ===
    static float GetThingViewingDistance(GameThingWithPos* target);  // 0x00441f20
    static void SetPointFromPointDistanceHeadingAndPitch(LHPoint* out, const LHPoint& point,
        float distance, float heading, float pitch);                // 0x00442810
    static void GetHeadingAndPitchFromPoints(const LHPoint& origin, const LHPoint& heading,
        float* pitch, float* yaw);                                  // 0x004428d0

    // === Fields ===
    CameraMode*  modes[12];              // 0x28
    int32_t      mode_current_index;     // 0x58
    LHPoint      pos;                    // 0x5C
    float        time;                   // 0x68
    float        time_delta;             // 0x6C
    uint32_t     field_0x70;             // 0x70
    uint32_t     camera_dirty;           // 0x74
    uint8_t      field_0x78;             // 0x78
    uint8_t      field_0x79;             // 0x79
    uint8_t      field_0x7a;             // 0x7A
    uint8_t      field_0x7b;             // 0x7B
    uint32_t     field_0x7c;             // 0x7C
    uint8_t      field_0x80[0x8];        // 0x80
    Zoomer3d     camera_heading_zoomer;  // 0x88
    Zoomer3d     camera_origin_zoomer;   // 0x118
    Zoomer       fov_zoomer;             // 0x1A8
};
static_assert(sizeof(GCamera) == 0x1D8, "GCamera size mismatch");
