#pragma once
// Totem — tribal power marker
// Struct layout from bw1-decomp
//
// Size: 0xE4 bytes (inherits 0xC4 from Abode)
// Vtable: 0x92C bytes (same as Abode, overrides ~18 methods)
//
// Totems are worship structures that belong to towns.
// They override creature interaction queries and provide
// locked select (interface grab) functionality for
// totem-dragging rituals.

#include "Abode.h"

struct Totem : public Abode {
    // === Overrides of Base virtuals ===
    void Delete(int param) override;
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    bool32_t IsCastShadowAtNight() override;
    bool32_t CanBePlayedWithByCreature(Creature* creature) override;
    bool32_t CanBeImpressedByCreature(Creature* creature) override;
    bool32_t DoesTotemBelongToATownWhichIsVeryImpressedIndeed(Creature* creature) override;

    // === Overrides of Object virtuals ===
    void Draw() override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    bool32_t ValidForLockedSelectProcess(GInterfaceStatus* status) override;
    bool32_t NetworkFriendlyStartLockedSelect(GInterfaceStatus* status) override;
    bool32_t NetworkUnfriendlyStartLockedSelect() override;
    bool32_t NetworkUnfriendlyLockedSelect(ControlHandUpdateInfo* param1) override;
    bool32_t NetworkUnfriendlyEndLockedSelect() override;
    bool32_t NetworkFriendlyEndLockedSelect(GInterfaceStatus* status) override;
    bool32_t IsEffectReceiver(EffectValues* param1) override;

    // === Fields ===
    MapCoords field_0xc4;  // 0xC4
    MapCoords field_0xd0;  // 0xD0
    uint32_t  field_0xdc;  // 0xDC
    uint32_t  field_0xe0;  // 0xE0
};
static_assert(sizeof(Totem) == 0xE4, "Totem size mismatch");
