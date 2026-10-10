#pragma once
// Mist — fog/mist effect entity
// Struct layout from bw1-decomp
//
// Size: 0x54 bytes (inherits 0x28 from GameThingWithPos)

#include "GameThingWithPos.h"

struct Mist : public GameThingWithPos {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    GPlayer* GetPlayer() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
    void ResolveLoad() override;

    // === Overrides of GameThingWithPos virtuals ===
    uint32_t GetCreatureBeliefType() override;
    float GetDistanceFromObject(const MapCoords& target) override;
    bool32_t IsMist() override;
    const char* GetText() override;
    uint32_t GetScriptObjectType() override;

    // === Fields ===
    uint32_t    field_0x28;        // 0x28
    float       scale;             // 0x2C: CREATE_MIST's fourth argument
    uint32_t    colour;            // 0x30: its third (an ARGB word)
    float       field_0x34;        // 0x34: its fifth
    uint8_t     field_0x38[0x14];  // 0x38
    uint32_t    field_0x4c;        // 0x4C: bit 0 cleared at creation
    Mist*       next;              // 0x50: the game's list (+2104544), newest first
};
static_assert(sizeof(Mist) == 0x54, "Mist size mismatch");

// sub_5C1AE0 -> sub_5C1980: a mist at pos, on the game's list.
// ponytail: its vslot-320 creation call is not made.
Mist* CreateMist(const MapCoords& pos, float scale, uint32_t colour, float f34);
Mist* FirstMist();
void ResetMists();
