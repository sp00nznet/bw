#pragma once
// InfluenceRing — player influence area marker
// Struct layout from bw1-decomp
//
// Size: 0x44 bytes (inherits 0x28 from GameThingWithPos)

#include "GameThingWithPos.h"

// BaseInfo — object reference info (from bw1-decomp, has its own vtable)
struct BaseInfo {
    void* vftable;          // 0x0 — BaseInfoVftable*
    uint32_t unique_id;     // 0x4
    uint32_t address_offset;// 0x8
};
static_assert(sizeof(BaseInfo) == 0xC, "BaseInfo size mismatch");

struct InfluenceRing : public GameThingWithPos {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    GPlayer* GetPlayer() override;
    void SetPlayer(GPlayer* player) override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    void SetPos(const MapCoords& coords) override;
    const char* GetText() override;
    bool32_t IsInfluenceRing() override;
    uint32_t GetScriptObjectType() override;

    // === Fields ===
    BaseInfo    info;       // 0x28
    GPlayer*    player;     // 0x34
    float       field_0x38; // 0x38
    int         field_0x3c; // 0x3C
    uint32_t    field_0x40; // 0x40
};
static_assert(sizeof(InfluenceRing) == 0x44, "InfluenceRing size mismatch");
