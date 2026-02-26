#pragma once
// Feature — static map decoration (ruins, stones, mushrooms, etc.)
// Struct layout from bw1-decomp
//
// Size: 0x7C bytes (same as MultiMapFixed — no new fields)
// Vtable: 0x90C bytes (same as MultiMapFixed, overrides ~12 methods)

#include "MultiMapFixed.h"

struct Feature : public MultiMapFixed {
    char* GetDebugText() override;
    uint32_t GetSaveType() override;
    uint32_t GetCreatureBeliefType() override;
    bool32_t CanBePickedUpByCreature(Creature* creature) override;
    bool32_t IsMushroom(Creature* creature) override;
    bool32_t IsFeature() override;
    HELP_TEXT GetQueryFirstEnumText() override;
    HELP_TEXT GetQueryLastEnumText() override;
    uint32_t GetScriptObjectType() override;
    int GetMesh() const override;
    void Draw() override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;
};
static_assert(sizeof(Feature) == 0x7C, "Feature size mismatch");
