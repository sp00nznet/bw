#pragma once
// Morphable — 3D morphable creature/character model
// Struct layout from bw1-decomp
// Size: 0x4834 bytes
//
// This is the rendering backbone for creatures and other morphable entities.
// It contains mesh data, animation sets, hair groups, and a vtable for
// morph/anim operations (separate from the GameThing hierarchy).
// Due to heavy dependencies on LH3D engine internals (LH3DAnimSet,
// LH3DMesh, LH3DObjectHair, CFrame, etc.), the internal layout is
// represented as an opaque byte array with key fields at known offsets.

#include "DrawingObject.h"

#include <stdint.h>

struct AnimInfo;
struct CAnim;
struct CFrame;
struct HairGroup;
struct LH3DComplexObject;
struct LH3DMesh;
struct LH3DObjectHair;
struct LHFile;
struct LHMatrix;

// Vtable for Morphable (10 entries, 0x28 bytes)
// NOT related to Base/GameThing vtable hierarchy
struct MorphableVftable {
    void*  SetAnimTime;         // 0x00
    void*  LoadBase;            // 0x04
    void*  SetSize;             // 0x08
    void*  MorphAnims;          // 0x0C
    void*  MorphTexture;        // 0x10
    void*  UpdateTime;          // 0x14
    void*  PrepareForDrawing;   // 0x18
    void*  AddForDrawing;       // 0x1C
    void*  LoadBinary;          // 0x20
    void*  SaveBinary;          // 0x24
};
static_assert(sizeof(MorphableVftable) == 0x28, "MorphableVftable size mismatch");

struct Morphable : public DrawingObject {
    // 0x04 .. 0x4833 — internal morph/animation state
    // Key known offsets:
    //   0x78:  LHPoint position
    //   0x90:  float size_1
    //   0x94:  float size_2
    //   0x98:  int current_mesh
    //   0xB4:  LH3DMesh* meshes[8]
    //   0x47F0: LHMatrix* transformed_matrices
    //   0x47FC: CFrame* frame
    //   0x4800: int32_t hair_group_count
    //   0x4804: HairGroup* hair_groups[8]
    //   0x482C: LH3DComplexObject* dynamic_shadow
    uint8_t field_0x4[0x4830];  // 0x04
};
static_assert(sizeof(Morphable) == 0x4834, "Morphable size mismatch");
