#pragma once
// PhysicsSaveInfo — physics state serialization helper
// Struct layout from bw1-decomp (PhysicsSaveInfo.h)
//
// No struct — just a static method for reading physics save data

struct GameOSFile;

struct PhysicsSaveInfo {
    static void ReadInfo(GameOSFile* file);
};
