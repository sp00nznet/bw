#pragma once
// SpellDispenser — spell distribution point
// Struct layout from bw1-decomp
//
// Size: 0xC4 bytes (same as Abode — no new fields)
// Vtable: 0x92C bytes (same as Abode, overrides ~12 methods)

#include "Abode.h"

struct SpellDispenser : public Abode {
    void ToBeDeleted(int param) override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
    bool32_t IsSpellDispenser() override;
    bool32_t IsActive() const override;
    uint32_t GetScriptObjectType() override;
    uint32_t Process() override;
    void Draw() override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    bool IsSpellSeedReturnPoint() const override;
};
static_assert(sizeof(SpellDispenser) == 0xC4, "SpellDispenser size mismatch");
