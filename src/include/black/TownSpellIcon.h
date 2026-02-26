#pragma once
// TownSpellIcon — spell icon linked to a town's worship site
// Struct layout from bw1-decomp
//
// Size: 0x118 bytes (inherits 0x110 from SpellIcon)
// Vtable: extends SpellIcon (MultiMapFixedVftable), overrides 10 methods

#include "SpellIcon.h"

// Forward declarations
struct Town;

struct TownSpellIcon : public SpellIcon {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;               // 0x00748ae0

    // === Overrides of GameThing virtuals ===
    GPlayer* GetPlayer() override;                      // 0x00748b90
    Town* GetTown() override;                           // 0x0055e040
    char* GetDebugText() override;                      // 0x0055e060
    uint32_t Load(GameOSFile* file) override;           // 0x00748fb0
    uint32_t Save(GameOSFile* file) override;           // 0x00748f70
    uint32_t GetSaveType() override;                    // 0x0055e050

    // === Overrides of GameThingWithPos virtuals ===
    WorshipSite* GetWorshipSite() override;             // 0x00748f00

    // === Overrides of Object virtuals ===
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override; // 0x00748be0

    // === Fields ===
    TownSpellIcon*  next;   // 0x110 — linked list
    Town*           town;   // 0x114
};
static_assert(sizeof(TownSpellIcon) == 0x118, "TownSpellIcon size mismatch");
