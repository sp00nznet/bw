#pragma once
// CreatureRoom — creature management room in the citadel
// Struct layout from bw1-decomp (CreatureRoom.h)
//
// Size: 0x4D8 bytes (extends TempleRoom)

#include "TempleRoom.h"

struct CreatureRoom : public TempleRoom {
    void InitEngine_0() override;

    // === Fields ===
    uint8_t  field_0xec[0x380];  // 0xEC
    uint32_t field_0x46c;        // 0x46C
    uint8_t  field_0x470[0x68];  // 0x470
};
static_assert(sizeof(CreatureRoom) == 0x4D8, "CreatureRoom size mismatch");
