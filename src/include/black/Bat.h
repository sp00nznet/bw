#pragma once
// Bat and SpellBat — bat animal entities (Dove/SpellDove subclasses)
// Struct layout from bw1-decomp (file: AnimalBat.h)

#include "Dove.h"

// Bat — normal bat (Dove subclass)
struct Bat : public Dove {
    char* GetDebugText() override;
    uint32_t GetSaveType() override;
    bool32_t CanBeFrighteningToCreature(Creature* creature) override;
    uint32_t StandAnimation() override;
};
static_assert(sizeof(Bat) == 0x148, "Bat size mismatch");

// SpellBat — summoned bat (SpellDove subclass)
struct SpellBat : public SpellDove {
    char* GetDebugText() override;
    uint32_t GetSaveType() override;
    bool32_t CanBeFrighteningToCreature(Creature* creature) override;
    uint32_t StandAnimation() override;
};
static_assert(sizeof(SpellBat) == 0x148, "SpellBat size mismatch");
