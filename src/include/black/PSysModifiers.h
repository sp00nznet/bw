#pragma once
// PSysModifiers — particle system modifier base types
// Struct layout from bw1-decomp (PSysModifiers.h)
//
// Defines 6 types, all 0x14 bytes extending PSysBase:
//   BaseAtomModifierData, BaseCollectionModifierData,
//   DrawOffset, DrawOffsetDecay, DrawOffsetLT, GJAnimVolFX

#include "PSysBase.h"

struct BaseAtomModifierData : public PSysBase {
    ~BaseAtomModifierData() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(BaseAtomModifierData) == 0x14, "BaseAtomModifierData size mismatch");

struct BaseCollectionModifierData : public PSysBase {
    ~BaseCollectionModifierData() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(BaseCollectionModifierData) == 0x14, "BaseCollectionModifierData size mismatch");

struct DrawOffset : public PSysBase {
    ~DrawOffset() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(DrawOffset) == 0x14, "DrawOffset size mismatch");

struct DrawOffsetDecay : public DrawOffset {
    ~DrawOffsetDecay() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(DrawOffsetDecay) == 0x14, "DrawOffsetDecay size mismatch");

struct DrawOffsetLT : public DrawOffset {
    ~DrawOffsetLT() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(DrawOffsetLT) == 0x14, "DrawOffsetLT size mismatch");

struct GJAnimVolFX : public PSysBase {
    ~GJAnimVolFX() override;
};
static_assert(sizeof(GJAnimVolFX) == 0x14, "GJAnimVolFX size mismatch");
