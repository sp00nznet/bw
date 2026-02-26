#pragma once
// HanoiBlock — puzzle piece (Tower of Hanoi minigame)
// Struct layout from bw1-decomp
//
// Size: 0x68 bytes (same as MobileObject — no new fields)
// Simple methods at 0x005617xx-0x005618xx are packed 16 bytes apart.
// Complex methods at 0x006db9xx-0x006de4xx.

#include "MobileObject.h"

struct HanoiBlock : public MobileObject {
    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    bool IsCannotBePickedUp() const override;

    // === Overrides of Object virtuals ===
    bool32_t InterfaceSetInMagicHand(GInterfaceStatus* status) override;
    bool CanBecomeAPhysicsObject() override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;
    IMMERSION_EFFECT_TYPE GetInHandImmersionTexture() override;
};
static_assert(sizeof(HanoiBlock) == 0x68, "HanoiBlock size mismatch");
