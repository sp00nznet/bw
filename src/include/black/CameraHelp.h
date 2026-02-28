#pragma once
// CameraHelp — camera help system reason codes
// Struct layout from bw1-decomp (CameraHelp.h)
//
// Defines: CameraHelpReason enum (sparse, 0x309 entries)

#include <cstdint>

struct LHPoint;

enum CameraHelpReason : uint32_t {
    CameraHelpReason_0x100 = 0x100,
    CameraHelpReason_0x101 = 0x101,
    CameraHelpReason_0x102 = 0x102,
    CameraHelpReason_0x200 = 0x200,
    CameraHelpReason_0x201 = 0x201,
    CameraHelpReason_0x202 = 0x202,
    CameraHelpReason_0x203 = 0x203,
    CameraHelpReason_0x300 = 0x300,
    CameraHelpReason_0x301 = 0x301,
    CameraHelpReason_0x302 = 0x302,
    CameraHelpReason_0x303 = 0x303,
    CameraHelpReason_0x304 = 0x304,
    CameraHelpReason_0x305 = 0x305,
    CameraHelpReason_0x306 = 0x306,
    CameraHelpReason_0x307 = 0x307,
    CameraHelpReason_0x308 = 0x308,
};
