#pragma once
#include "GameThing.h"
#include <vector>

struct GClimate : public GameThing {
    // === Overrides ===
    char*    GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Fields ===
    MapCoords   pos;             // 0x14
    float       radius_min;      // 0x20 (the smaller of the two)
    float       radius_max;      // 0x24
    int32_t     id;              // 0x28: the level script's climate number
    const void* info;            // 0x2C: DETAIL_CLIMATE_INFO record (160 bytes)
    uint32_t    field_0x30;
    struct Rain { float amount; int32_t a; int32_t b; uint8_t c; } rain;  // 0x34 (sub_700D10)
    float       temp[2];         // 0x44 (sub_700E90)
    float       wind[3];         // 0x4C (sub_7019E0)
    uint8_t     field_0x58[0x30];  // 0x58: weather state
};
static_assert(sizeof(GClimate) == 0x88, "GClimate size mismatch");

// The game's climate list (+2104752) and its default climate (+2409952).
std::vector<GClimate*>& Climates();
GClimate*& DefaultClimate();
// sub_6FE4B0: id 0 replaces the default climate (sub_6FE1D0: record 0, 5000 m
// across); any other is a climate of the record at pos (sub_6FE320).
GClimate* CreateClimate(const MapCoords& pos, int type, float r1, float r2, int id);
// sub_7002A0, with id 0 the default (made if missing, as sub_7002F0 does).
GClimate* FindClimate(int id);
void ResetClimates();
