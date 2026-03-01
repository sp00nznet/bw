#pragma once
// PSysTornado — tornado-specific particle system modifier types
// Struct layout from bw1-decomp (PSysTornado.h)
//
// 4 types (all 0x14 bytes)

#include "PSysModifiers.h"

struct UR_Tornado_CollectionData : public BaseCollectionModifierData {
    ~UR_Tornado_CollectionData() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(UR_Tornado_CollectionData) == 0x14, "UR_Tornado_CollectionData size mismatch");

struct UR_Tornado_DebrisCollectionData : public BaseCollectionModifierData {
    ~UR_Tornado_DebrisCollectionData() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(UR_Tornado_DebrisCollectionData) == 0x14, "UR_Tornado_DebrisCollectionData size mismatch");

struct UR_Tornado_FlyingAtomData : public BaseAtomModifierData {
    ~UR_Tornado_FlyingAtomData() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(UR_Tornado_FlyingAtomData) == 0x14, "UR_Tornado_FlyingAtomData size mismatch");

struct UR_Tornado_FlyingCollectionData : public BaseCollectionModifierData {
    ~UR_Tornado_FlyingCollectionData() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(UR_Tornado_FlyingCollectionData) == 0x14, "UR_Tornado_FlyingCollectionData size mismatch");
