#pragma once
// CitadelEntrance — portal into a player's citadel
// Struct layout from bw1-decomp
//
// Size: 0x54 bytes (same as Object — no new fields)
// Simple methods at 0x00468exx are packed 16 bytes apart.
// Complex methods at 0x00468fxx-0x004693xx.

#include "Object.h"

struct CitadelEntrance : public Object {
    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t GetSaveType() override;
    void ResolveLoad() override;

    // === Overrides of GameThingWithPos virtuals ===
    HELP_TEXT GetQueryFirstEnumText() override;
    HELP_TEXT GetQueryLastEnumText() override;

    // === Overrides of Object virtuals ===
    uint32_t InterfaceValidToTap(GInterfaceStatus* status) override;
    uint32_t InterfaceTap(GInterfaceStatus* status) override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;
};
static_assert(sizeof(CitadelEntrance) == 0x54, "CitadelEntrance size mismatch");
