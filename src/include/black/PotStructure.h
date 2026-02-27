#pragma once
#include "Pot.h"

struct PotStructure : public Pot {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    GPlayer* GetPlayer() override;
    void SetPlayer(GPlayer* player) override;
    Town* GetTown() override;
    uint32_t JustRemoveResource(RESOURCE_TYPE type, uint32_t amount, bool* param3) override;
    uint32_t GetResource(RESOURCE_TYPE type) override;
    uint32_t AddResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool param4, const MapCoords& coords, int param6) override;
    uint32_t RemoveResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool* param4) override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;

    // === Overrides of GameThingWithPos virtuals ===
    bool32_t CanBeThrownByPlayer() override;

    // === Overrides of Object virtuals ===
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    bool IsResourceStore(RESOURCE_TYPE type) override;

    // === Overrides of Pot virtuals ===
    void SetSize() override;
    bool IsPartOfStructure() override;
    void SetSpeedUp(int speed) override;
    void SetMultiMapFixed(MultiMapFixed* multiMapFixed) override;

    // === Fields ===
    MultiMapFixed* field_0x78;  // 0x78
    uint32_t       field_0x7c;  // 0x7C
    uint8_t        field_0x80;  // 0x80
};
static_assert(sizeof(PotStructure) == 0x84, "PotStructure size mismatch");
