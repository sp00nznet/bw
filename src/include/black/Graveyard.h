#pragma once
// Graveyard — burial ground building
// Struct layout from bw1-decomp
//
// Size: 0xC4 bytes (same as Abode — no new fields)
// Vtable: 0x92C bytes (same as Abode, overrides ~13 methods)

#include "Abode.h"

struct Graveyard : public Abode {
    void ToBeDeleted(int param) override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
    MapCoords* GetArrivePos(MapCoords* out) override;
    bool32_t CanActAsAContainer(Creature* creature) override;
    bool32_t IsStoragePit(Creature* creature) override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    LH3DObject_ObjectType Get3DType() override;
    bool InteractsWithPhysicsObjects() override;
    void DeleteDependancys() override;
    void MakeFunctional() override;
    bool CanBeHiddenIn() override;
};
static_assert(sizeof(Graveyard) == 0xC4, "Graveyard size mismatch");
