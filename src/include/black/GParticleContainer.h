#pragma once
// GParticleContainer — particle system container attached to a game entity
// Struct layout from bw1-decomp
//
// Size: 0x40 bytes (inherits 0x28 from GameThingWithPos)
// Vtable: extends GameThingWithPos

#include "GameThingWithPos.h"

struct GParticleContainer : public GameThingWithPos {
    // === Overrides ===
    void ToBeDeleted(int param) override;
    void SetPlayer(GPlayer* player) override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
    void SetScale(float scale) override;
    const char* GetText() override;
    bool32_t IsParticleContainer() override;

    // === Fields ===
    GameThingWithPos* thing;      // 0x28 — the entity this container is attached to
    uint32_t          field_0x2c; // 0x2C
    uint32_t          field_0x30; // 0x30
    float             field_0x34; // 0x34
    bool              field_0x38; // 0x38
    // 3 bytes padding
    GParticleContainer* next;     // 0x3C — linked list next
};
static_assert(sizeof(GParticleContainer) == 0x40, "GParticleContainer size mismatch");
