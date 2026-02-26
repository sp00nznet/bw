#pragma once
// WayPoint and Waypoint — navigation waypoint entities
// Struct layout from bw1-decomp
//
// WayPoint: 0x28 bytes (same as GameThingWithPos, no new fields)
// Waypoint: 0x2C bytes (GameThingWithPos + 4 bytes)

#include "GameThingWithPos.h"

// ============================================================================
// WayPoint — script waypoint (no new fields)
// ============================================================================

struct WayPoint : public GameThingWithPos {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    const char* GetText() override;
};
static_assert(sizeof(WayPoint) == 0x28, "WayPoint size mismatch");

// ============================================================================
// Waypoint — navigation waypoint (lowercase 'p', different class)
// ============================================================================

struct Waypoint : public GameThingWithPos {
    // === Fields ===
    uint8_t field_0x28[0x4];  // 0x28
};
static_assert(sizeof(Waypoint) == 0x2C, "Waypoint size mismatch");
