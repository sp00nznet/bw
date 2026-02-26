#pragma once
// SpellShield — magical shield spell
// Struct layout from bw1-decomp
//
// Size: 0x10C bytes (inherits 0xF4 from SpellWithObjects)

#include "SpellWithObjects.h"

// Forward declarations
struct GMagicInfo;

struct SpellShield : public SpellWithObjects {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    float GetRadius() override;
    float Get2DRadius() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    float GetImpressiveValue(Living* param1, Reaction* param2) override;
    bool32_t IsSpellShield() override;

    // === Overrides of Spell virtuals ===
    void UpdateStruckReaction() override;
    void SetUpDestroyedReaction() override;
    uint32_t Process() override;
    void CloseDown() override;
    int InitWithPos(GameThing* caster, const MapCoords& pos, SpellCastData* data, const PSysProcessInfo& psys) override;
    float CalculateCostToMaintain() override;

    // === Fields ===
    uint8_t field_0xf4[0x18];  // 0xF4
};
static_assert(sizeof(SpellShield) == 0x10C, "SpellShield size mismatch");
