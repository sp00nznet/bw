#pragma once
// MultiplayerDatabase — base class for multiplayer data synchronization
// Struct layout from bw1-decomp (MultiplayerDatabase.h)
//
// Size: 0x10 bytes (own vtable hierarchy, NOT Base-derived)
// Vtable: 2 entries (Send, ReceiveReturnData)

#include <cstdint>

struct DBInfo;

struct MultiplayerDatabase {
    virtual uint32_t Send();               // vtable[0]
    virtual uint32_t ReceiveReturnData();  // vtable[1]

    uint32_t field_0x4;   // 0x04 — bool32_t
    DBInfo*  info;         // 0x08
    char*    field_0xc;   // 0x0C
};
static_assert(sizeof(MultiplayerDatabase) == 0x10, "MultiplayerDatabase size mismatch");
