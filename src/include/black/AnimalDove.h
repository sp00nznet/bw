#pragma once
// Dove — flying bird base type (doves, pigeons, bats, etc.)
// Also contains SpellDove — spell-summoned variant
// Struct layout from bw1-decomp
//
// Size: 0x148 bytes (same as Animal — no new fields)
// Vtable: overrides GetDebugText, GetSaveType, Load, Save, etc.

#include "Animal.h"

struct Creature;

struct Dove : public Animal {
    // No new fields — same size as Animal

    // === Virtual overrides ===
    virtual char*    GetDebugText() override { return nullptr; }
    virtual uint32_t GetSaveType() override { return 0; }
    virtual uint32_t Load(void* file) override { return 0; }
    virtual uint32_t Save(void* file) override { return 0; }
    virtual bool32_t CanBePickedUpByCreature(Creature*) override { return 0; }
    virtual bool32_t CanBeStompedOnByCreature(Creature*) override { return 0; }
    virtual bool32_t CanBePoodOn(Creature*) override { return 0; }
    virtual float    GetHowMuchCreatureWantsToLookAtMe() override { return 0.0f; }
    virtual uint32_t GetScriptObjectType() override { return 0; }
    virtual void     Draw() override {}
    virtual void     CallVirtualFunctionsForCreation(const MapCoords&) override {}
    virtual uint32_t StandAnimation() override { return 0; }
};
static_assert(sizeof(Dove) == 0x148, "Dove size mismatch");

struct SpellDove : public Dove {
    // No new fields

    // === Virtual overrides ===
    virtual char*    GetDebugText() override { return nullptr; }
    virtual uint32_t GetSaveType() override { return 0; }
    virtual uint32_t Load(void* file) override { return 0; }
    virtual uint32_t Save(void* file) override { return 0; }
    virtual bool     SetDying() override { return false; }
    virtual uint32_t StandAnimation() override { return 0; }
    virtual uint32_t GetNumTurnsToDieOver() override { return 0; }
};
static_assert(sizeof(SpellDove) == 0x148, "SpellDove size mismatch");
