#pragma once
// ShowNeedsVisuals — visual indicator for town/entity needs
// Struct layout from bw1-decomp
//
// Size: 0x94 bytes (inherits 0x54 from Object + 0x40 bytes)
// Simple methods at 0x0055ddxx are packed 16 bytes apart.
// Complex methods at 0x00719dxx-0x0071a4xx.

#include "Object.h"

// Forward declarations
struct GShowNeedsInfo;

struct ShowNeedsVisuals : public Object {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    GPlayer* GetPlayer() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
    void ResolveLoad() override;

    // === Overrides of GameThingWithPos virtuals ===
    float GetScale() override;
    void SetScale(float scale) override;
    const char* GetText() override;

    // === Overrides of Object virtuals ===
    int GetMesh() const override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;

    // === Fields ===
    int         field_0x54;      // 0x54
    uint32_t    field_0x58;      // 0x58
    uint32_t    field_0x5c;      // 0x5C
    GameThing*  game_thing;      // 0x60
    uint32_t    field_0x64;      // 0x64
    uint32_t    field_0x68;      // 0x68
    uint32_t    field_0x6c;      // 0x6C
    uint32_t    field_0x70;      // 0x70
    uint32_t    field_0x74;      // 0x74
    uint32_t    field_0x78;      // 0x78
    uint32_t    field_0x7c;      // 0x7C
    uint32_t    field_0x80;      // 0x80
    uint32_t    field_0x84;      // 0x84
    uint32_t    field_0x88;      // 0x88
    uint32_t    field_0x8c;      // 0x8C
    uint32_t    field_0x90;      // 0x90
};
static_assert(sizeof(ShowNeedsVisuals) == 0x94, "ShowNeedsVisuals size mismatch");
