#pragma once
// ShowNeeds — visual needs display for entities
// Struct layout from bw1-decomp
//
// Size: 0x24 bytes (inherits 0x14 from GameThing)

#include "GameThing.h"

// Forward declarations
struct GameThingWithPos;
struct ShowNeedsVisuals;

struct ShowNeeds : public GameThing {
    // === Overrides ===
    void ToBeDeleted(int param) override;
    GPlayer* GetPlayer() override;
    char* GetDebugText() override;
    uint32_t GetShowNeedsPos(uint32_t param1, MapCoords* param2) override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Fields ===
    GameThingWithPos*    thing;       // 0x14 — entity this display is for
    ShowNeedsVisuals*    visuals[3];  // 0x18 — visual display elements
};
static_assert(sizeof(ShowNeeds) == 0x24, "ShowNeeds size mismatch");
