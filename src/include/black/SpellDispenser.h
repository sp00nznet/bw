#pragma once
// SpellDispenser — spell distribution point
// Struct layout from bw1-decomp
//
// Size: 0xDC in v1.0 (sub_6B9720 clears up to +0xD8); the vendor's 0xC4 is short.
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

    void SetActive(bool on);   // sub_6B9F90: on dispenses at once
    struct OneOffSpellSeed* Dispense();  // sub_6B9AF0
    MapCoords DispensePos() const;       // sub_6B9AA0

    uint32_t turns = 0;                  // 0xC4: since the last dispense
    uint32_t recharge = 0;               // 0xC8: info +428 rounded, or the level's
    struct OneOffSpellSeed* seed = nullptr;  // 0xCC: the last one made
    uint32_t active = 0;                 // 0xD0
    uint32_t magic = 0;                  // 0xD4: MAGIC_TYPE it gives
    uint32_t field_0xd8 = 0;
};
static_assert(sizeof(SpellDispenser) == 0xDC, "SpellDispenser size mismatch");
