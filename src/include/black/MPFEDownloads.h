#pragma once
// MPFEDownloads — multiplayer frontend file download manager
// Struct layout from bw1-decomp (MPFEDownloads.h)
//
// Size: 0x280 bytes (own vtable hierarchy with 5 entries)

#include <cstdint>

struct MPFEDownloads {
    virtual void GetFileNumber(uint32_t param_1);
    virtual void Refresh();
    virtual void Stop();
    virtual void FileCompleted();
    virtual void FileError();

    uint8_t field_0x4[0x27C];  // 0x04
};
static_assert(sizeof(MPFEDownloads) == 0x280, "MPFEDownloads size mismatch");
