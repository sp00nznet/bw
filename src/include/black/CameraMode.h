#pragma once
// CameraMode — abstract base for camera behavior modes
// Struct layout from bw1-decomp
//
// Size: 0x8 bytes (vftable + camera pointer)
// Vtable: 18 entries (0x48 bytes)
//
// CameraMode has its own vtable hierarchy separate from GameThing.
// Each mode (Free, Follow, Citadel, etc.) overrides virtual methods
// to control camera behavior, mouse interaction, and serialization.

#include <cstdint>

// Forward declarations
struct GCamera;
struct GameOSFile;

// Mouse/hand screen coordinate
struct LHCoord {
    int32_t x;  // 0x00
    int32_t y;  // 0x04
};
static_assert(sizeof(LHCoord) == 0x8, "LHCoord size mismatch");

// Camera hand interaction state
enum CAMERA_MODE_HAND_STATUS : uint32_t {
    CAMERA_MODE_HAND_STATUS_NORMAL        = 0,
    CAMERA_MODE_HAND_STATUS_ZOOMING       = 1,
    CAMERA_MODE_HAND_STATUS_TILT_ON       = 2,
    CAMERA_MODE_HAND_STATUS_GRABBING_LAND = 3,
    CAMERA_MODE_HAND_STATUS_PANNING       = 4,
    CAMERA_MODE_HAND_STATUS_TILTING       = 5,
    CAMERA_MODE_HAND_STATUS_6             = 6,
    CAMERA_MODE_HAND_STATUS_7             = 7,
    CAMERA_MODE_HAND_STATUS_8             = 8,
    CAMERA_MODE_HAND_STATUS_COUNT         = 9
};

// Camera mouse button state
enum CAMERA_MODE_MOUSE_STATUS : uint32_t {
    CAMERA_MODE_MOUSE_STATUS_NONE   = 0,
    CAMERA_MODE_MOUSE_STATUS_LEFT   = 1,
    CAMERA_MODE_MOUSE_STATUS_MIDDLE = 2,
    CAMERA_MODE_MOUSE_STATUS_COUNT  = 3
};

struct CameraMode {
    // === Vtable (18 virtual methods) ===
    virtual ~CameraMode();                                         // slot 0
    virtual bool CanPlayerGestureWhenCameraMoving();               // slot 1
    virtual void Update();                                         // slot 2
    virtual void Validate();                                       // slot 3
    virtual void Restart();                                        // slot 4
    virtual bool IsStillValid();                                   // slot 5
    virtual void Cleanup();                                        // slot 6
    virtual bool CanExist();                                       // slot 7
    virtual bool MouseIsLocked();                                  // slot 8
    virtual void GetMousePos(LHCoord* pos);                        // slot 9
    virtual void ProcessKeyMovement(uint16_t key);                 // slot 10
    virtual void ProcessMouseMovement();                           // slot 11
    virtual void Delete();                                         // slot 12
    virtual bool Arrived();                                        // slot 13
    virtual uint32_t GetSaveID();                                  // slot 14
    virtual void Load(GameOSFile* file);                           // slot 15
    virtual void Save(GameOSFile* file);                           // slot 16
    virtual const char* GetDebugName();                            // slot 17

    // === Fields ===
    GCamera*  camera;  // 0x04
};
static_assert(sizeof(CameraMode) == 0x8, "CameraMode size mismatch");
