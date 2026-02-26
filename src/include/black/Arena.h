#pragma once
// GArena — arena game thing, and ArenaSpellIcon — arena spell icon
// Struct layout from bw1-decomp
//
// GArena: 0x4C bytes (inherits 0x28 from GameThingWithPos)
// ArenaSpellIcon: 0x58 bytes (inherits 0x58 from Fixed, no new fields)

#include "Fixed.h"

// Forward declarations
struct EffectValues;

// ============================================================================
// GArena — arena game thing with position
// ============================================================================

struct GArena : public GameThingWithPos {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    float GetRadius() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    const char* GetText() override;

    // === Fields ===
    uint8_t field_0x28[0x24];  // 0x28
};
static_assert(sizeof(GArena) == 0x4C, "GArena size mismatch");

// ============================================================================
// ArenaSpellIcon — spell icon displayed in the arena
// ============================================================================

struct ArenaSpellIcon : public Fixed {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of Object virtuals ===
    void Create3DObject() override;
    void Draw() override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    bool32_t IsEffectReceiver(EffectValues* param1) override;
    bool CreatureMustAvoid(Creature* param1) override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;
};
static_assert(sizeof(ArenaSpellIcon) == 0x58, "ArenaSpellIcon size mismatch");
