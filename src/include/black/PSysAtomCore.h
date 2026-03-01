#pragma once
// PSysAtomCore — atom core and collection types for particle system
// Struct layout from bw1-decomp (PSysAtomCore.h)
//
// AtomCollection (0x4), UR_GesturingRecognised (0x4), AtomCore (0x14, extends PSysBase),
// plus atom/collection modifier data subtypes

#include <cstdint>
#include "PSysBase.h"
#include "PSysModifiers.h"

struct AtomCollection {
    uint8_t field_0x0[0x4];
};
static_assert(sizeof(AtomCollection) == 0x4, "AtomCollection size mismatch");

struct UR_GesturingRecognised {
    uint8_t field_0x0[0x4];
};
static_assert(sizeof(UR_GesturingRecognised) == 0x4, "UR_GesturingRecognised size mismatch");

struct AtomCore : public PSysBase {
    ~AtomCore() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(AtomCore) == 0x14, "AtomCore size mismatch");

struct UR_GesturingRecognised_AtomData : public BaseAtomModifierData {
    ~UR_GesturingRecognised_AtomData() override;
};
static_assert(sizeof(UR_GesturingRecognised_AtomData) == 0x14, "UR_GesturingRecognised_AtomData size mismatch");

struct UR_Plasma_AtomData : public BaseAtomModifierData {
    ~UR_Plasma_AtomData() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(UR_Plasma_AtomData) == 0x14, "UR_Plasma_AtomData size mismatch");

struct UR_Plasma_SubCollectionData : public BaseCollectionModifierData {
    ~UR_Plasma_SubCollectionData() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(UR_Plasma_SubCollectionData) == 0x14, "UR_Plasma_SubCollectionData size mismatch");
