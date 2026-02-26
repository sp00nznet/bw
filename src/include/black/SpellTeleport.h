#pragma once
// SpellTeleport — teleportation spell
// Struct layout from bw1-decomp
//
// Size: 0xF4 bytes (inherits 0xF4 from SpellWithObjects, no added fields)

#include "SpellWithObjects.h"

struct SpellTeleport : public SpellWithObjects {
    // === Overrides ===
    char* GetDebugText() override;
    uint32_t GetSaveType() override;
    int InitWithPos(GameThing* caster, const MapCoords& pos, SpellCastData* data, const PSysProcessInfo& psys) override;
};
static_assert(sizeof(SpellTeleport) == 0xF4, "SpellTeleport size mismatch");
