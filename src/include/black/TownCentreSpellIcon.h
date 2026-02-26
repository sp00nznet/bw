#pragma once
// TownCentreSpellIcon — spell icon specific to town centres with power-up tracking
// Struct layout from bw1-decomp
//
// Size: 0x128 bytes (inherits 0x118 from TownSpellIcon)
// Vtable: extends TownSpellIcon (MultiMapFixedVftable), overrides 8 methods

#include "TownSpellIcon.h"

// Forward-declare enum
enum POWER_UP_TYPE : uint32_t;

struct TownCentreSpellIcon : public TownSpellIcon {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;                                    // 0x00748c80

    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;                                           // 0x0055e0b0
    uint32_t Load(GameOSFile* file) override;                                // 0x007490e0
    uint32_t Save(GameOSFile* file) override;                                // 0x00748ff0
    uint32_t GetSaveType() override;                                         // 0x0055e0a0

    // === Overrides of Object virtuals ===
    void Draw() override;                                                    // 0x00519640
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;  // 0x00748d20

    // === Non-virtual methods ===
    void SetPULevel(POWER_UP_TYPE power_up_type, bool enabled);              // 0x00748eb0
    void UpdateGraphicWithPULevels();                                        // 0x00748ed0

    // === Fields ===
    uint32_t  field_0x118;              // 0x118
    uint32_t  power_up_enabled[3];      // 0x11C  (POWER_UP_TYPE_LAST = 3)
};
static_assert(sizeof(TownCentreSpellIcon) == 0x128, "TownCentreSpellIcon size mismatch");
