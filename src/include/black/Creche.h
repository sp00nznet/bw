#pragma once
// Creche — childcare building
// Struct layout from bw1-decomp
//
// Size: 0xC4 bytes (same as Abode — no new fields)
// Vtable: 0x92C bytes (same as Abode, overrides ~9 methods)

#include "Abode.h"

struct Creche : public Abode {
    void ToBeDeleted(int param) override;
    char* GetDebugText() override;
    uint32_t GetSaveType() override;
    MapCoords* GetArrivePos(MapCoords* out) override;
    bool32_t CanActAsAContainer(Creature* creature) override;
    bool32_t IsStoragePit(Creature* creature) override;
    void ReduceLife(float value, GPlayer* player) override;
    LH3DObject_ObjectType Get3DType() override;
    void DeleteDependancys() override;
    void MakeFunctional() override;
};
static_assert(sizeof(Creche) == 0xC4, "Creche size mismatch");
