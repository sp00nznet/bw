#pragma once
// SpellFlock — flock summoning spell (base for flying and ground variants)
// Struct layout from bw1-decomp
//
// Size: 0xF4 bytes (inherits 0xF4 from SpellWithObjects, no added fields)

#include "SpellWithObjects.h"

struct SpellFlock : public SpellWithObjects {
    // === Overrides of GameThing virtuals ===
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;

    // === Overrides of Spell virtuals ===
    bool NeedsContinualPackets(GInterfaceStatus* param1) override;
    uint32_t Process() override;
    void CloseDown() override;
    int InitWithPos(GameThing* caster, const MapCoords& pos, SpellCastData* data, const PSysProcessInfo& psys) override;
    float CalculateCostToMaintain() override;
};
static_assert(sizeof(SpellFlock) == 0xF4, "SpellFlock size mismatch");
