#pragma once
#include "PotStructure.h"

struct ControlHandUpdateInfo;

struct PileResource : public PotStructure {
    // === Overrides of GameThing virtuals ===
    uint32_t JustAddResource(RESOURCE_TYPE type, uint32_t amount, bool param3) override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;

    // === Overrides of GameThingWithPos virtuals ===
    float GetLife() override;
    bool32_t IsField_1(Creature* creature) override;
    bool32_t CanBePickedUpByCreature(Creature* creature) override;
    bool32_t IsPileResource() override;

    // === Overrides of Object virtuals ===
    void SetLife(float life) override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    bool IsLockedInInteract() override;
    bool32_t ValidForLockedSelectProcess(GInterfaceStatus* status) override;
    bool32_t NetworkFriendlyStartLockedSelect(GInterfaceStatus* status) override;
    uint32_t NetworkUnfriendlyLockedSelect(ControlHandUpdateInfo* info) override;
    uint32_t NetworkUnfriendlyEndLockedSelect() override;
    uint32_t NetworkFriendlyEndLockedSelect(GInterfaceStatus* status) override;
    bool32_t ValidForPlaceInHand(GInterfaceStatus* status) override;
    bool32_t InterfaceSetInMagicHand(GInterfaceStatus* status) override;
    uint32_t IsTuggable() override;
    uint32_t ProcessInInteract(GInterfaceStatus* status) override;

    // === Fields ===
    float    field_0x84;  // 0x84
    float    field_0x88;  // 0x88
    uint32_t field_0x8c;  // 0x8C
    uint32_t field_0x90;  // 0x90
    uint32_t field_0x94;  // 0x94
    uint32_t field_0x98;  // 0x98
    uint32_t field_0x9c;  // 0x9C
    float    field_0xa0;  // 0xA0
    uint32_t field_0xa4;  // 0xA4
    uint32_t field_0xa8;  // 0xA8
    uint32_t field_0xac;  // 0xAC
    uint32_t field_0xb0;  // 0xB0
};
static_assert(sizeof(PileResource) == 0xB4, "PileResource size mismatch");
