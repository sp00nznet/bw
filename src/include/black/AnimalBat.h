#pragma once
// Bat — flying predator bird, derives from Dove
// Also contains SpellBat — spell-summoned variant
// Size: 0x148 bytes

#include "AnimalDove.h"

struct Creature;

struct Bat : public Dove {
    virtual char*    GetDebugText() override { return nullptr; }
    virtual uint32_t GetSaveType() override { return 0; }
    virtual bool32_t CanBeFrighteningToCreature(Creature*) override { return 1; }
    virtual uint32_t StandAnimation() override { return 0; }
};
static_assert(sizeof(Bat) == 0x148, "Bat size mismatch");

struct SpellBat : public SpellDove {
    virtual char*    GetDebugText() override { return nullptr; }
    virtual uint32_t GetSaveType() override { return 0; }
    virtual bool32_t CanBeFrighteningToCreature(Creature*) override { return 1; }
    virtual uint32_t StandAnimation() override { return 0; }
};
static_assert(sizeof(SpellBat) == 0x148, "SpellBat size mismatch");
