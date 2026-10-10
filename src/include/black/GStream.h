#pragma once
#include "GameThing.h"

struct GStream : public GameThing {
    // === Overrides ===
    char*    GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // A point (16 bytes, sub_6C9C80): metres, y the land height there.
    struct Point { float x, y, z; Point* next; };
    void AddPoint(float x, float y, float z);  // sub_6C9C00: at the end

    // === Fields ===
    Point*   points = nullptr;    // 0x14
    uint32_t count = 0;           // 0x18
    int32_t  id = 0;              // 0x1C: the level script's stream number
    uint32_t field_0x20 = 0;
    GStream* next = nullptr;      // 0x24: the game's list (+2104600), newest first
};
static_assert(sizeof(GStream) == 0x28, "GStream size mismatch");

GStream* CreateStream(int id);         // sub_6C9B30
GStream* FirstStream();
void ResetStreams();
// sub_6C9D10: the stream with the nearest point closer than max_m (2D) to
// `from`; *out is that point. nullptr when none.
GStream* NearestStreamPoint(const MapCoords& from, float max_m, MapCoords* out);
