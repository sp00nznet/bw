#pragma once
// FireEffect — fire visual and damage effect on objects
// Struct layout from bw1-decomp
//
// Size: 0x50 bytes (inherits 0x14 from GameThing)

#include "GameThing.h"

// Forward declarations
struct FireGraphic;
struct Object;

struct FireEffect : public GameThing {
    // === Overrides ===
    void ToBeDeleted(int param) override;
    int Get3DSoundPos(LHPoint* pos) override;
    GPlayer* GetPlayer() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
    void ResolveLoad() override;

    // === Fields ===
    float        temperature;   // 0x14
    float        temperature2;  // 0x18
    Object*      source;        // 0x1C — object on fire
    GPlayer*     player;        // 0x20 — player who caused fire
    GameThing*   thing;         // 0x24
    uint32_t     field_0x28;    // 0x28
    uint32_t     field_0x2c;    // 0x2C
    uint32_t     field_0x30;    // 0x30
    uint32_t     field_0x34;    // 0x34
    uint8_t      field_0x38;    // 0x38
    // 3 bytes padding
    FireEffect*  next;          // 0x3C — linked list next
    uint8_t      field_0x40[0x8]; // 0x40
    uint32_t     field_0x48;    // 0x48
    uint32_t     field_0x4c;    // 0x4C
};
static_assert(sizeof(FireEffect) == 0x50, "FireEffect size mismatch");
