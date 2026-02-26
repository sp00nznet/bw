#pragma once
// Wonder — special large structure (temples of power)
// Struct layout from bw1-decomp
//
// Size: 0xC8 bytes (inherits 0xC4 from Abode)
// Vtable: 0x92C bytes (same as Abode, overrides ~14 methods)
//
// Wonders are the large god-power buildings that players
// construct to gain special abilities. They override
// resource storage (CanActAsAContainer, IsStoragePit),
// building lifecycle (Built, SetPower, AddToPlayer),
// and identity/serialization methods.

#include "Abode.h"

struct Wonder : public Abode {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    MapCoords* GetArrivePos(MapCoords* out) override;
    bool32_t CanActAsAContainer(Creature* creature) override;
    bool32_t IsStoragePit(Creature* creature) override;

    // === Overrides of Object virtuals ===
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    LH3DObject_ObjectType Get3DType() override;

    // === Overrides of MultiMapFixed virtuals ===
    bool Built() override;
    void SetPower(float power) override;
    void AddToPlayer() override;
    void RemoveFromPlayer() override;

    // === Fields ===
    float power;  // 0xC4
};
static_assert(sizeof(Wonder) == 0xC8, "Wonder size mismatch");
