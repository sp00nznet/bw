#pragma once
// HelpSpirit — floating spirit guide (good/evil conscience)
// Struct layout from bw1-decomp
//
// Size: 0x64 bytes (inherits 0x54 from Object)

#include "Object.h"

// Help spirit type enum (partial)
enum HELP_SPIRIT_TYPE : uint32_t {
    HELP_SPIRIT_TYPE_GOOD = 0,
    HELP_SPIRIT_TYPE_EVIL = 1,
};

struct HelpSpirit : public Object {
    // === Overrides of Object virtuals ===
    void Create3DObject() override;
    uint32_t Process() override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    bool32_t ValidForPlaceInHand(GInterfaceStatus* status) override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;

    // === Fields ===
    uint32_t         field_0x54;   // 0x54
    HELP_SPIRIT_TYPE type;         // 0x58
    uint8_t          field_0x5c[0x8]; // 0x5C
};
static_assert(sizeof(HelpSpirit) == 0x64, "HelpSpirit size mismatch");
