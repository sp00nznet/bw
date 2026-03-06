#pragma once
// Wolf — predator, derives from Lion
// Also contains SpellWolf — spell-summoned variant with extra overrides
// Size: 0x148 bytes

#include "AnimalLion.h"

struct GPlayer;

struct SpellWolf : public Lion {
    // === Virtual overrides ===
    virtual char*    GetDebugText() override { return nullptr; }
    virtual GPlayer* GetPlayer() override { return nullptr; }
    virtual void     SetPlayer(GPlayer*) override {}
    virtual uint32_t GetSaveType() override { return 0; }
    virtual uint32_t Load(void* file) override { return 0; }
    virtual uint32_t Save(void* file) override { return 0; }
    virtual void     Draw() override {}
    virtual void     CallVirtualFunctionsForCreation(const MapCoords&) override {}
    virtual bool     SetDying() override { return false; }
    virtual uint32_t StandAnimation() override { return 0; }
    virtual void     SetSpeed(int) override {}
    virtual uint32_t GetNumTurnsToDieOver() override { return 0; }
};
static_assert(sizeof(SpellWolf) == 0x148, "SpellWolf size mismatch");

struct Wolf : public Lion {
    virtual char*    GetDebugText() override { return nullptr; }
    virtual uint32_t GetSaveType() override { return 0; }
    virtual uint32_t StandAnimation() override { return 0; }
};
static_assert(sizeof(Wolf) == 0x148, "Wolf size mismatch");
