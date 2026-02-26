#pragma once
// PlannedMultiMapFixed — a planned building not yet constructed
// Struct layout from bw1-decomp
//
// Size: 0x48 bytes (inherits 0x28 from GameThingWithPos)
// Vtable: 0x51C bytes (extends GameThingWithPos's 0x500 with 7 methods)

#include "GameThingWithPos.h"

// Forward declarations
struct GFootpathLink;
struct GObjectInfo;
struct MultiMapFixed;

// Forward-declare enum (defined in MultiMapFixed.h)
enum ABODE_TYPE : uint32_t;

struct PlannedMultiMapFixed : public GameThingWithPos {
    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    float GetScale() override;
    void SetScale(float scale) override;
    const char* GetText() override;
    bool32_t IsWonder() override;
    bool32_t CreateBuildingSite() override;

    // === New virtual methods (vtable 0x500-0x518) ===
    virtual MultiMapFixed* CreatePlanned(float param1);
    virtual MultiMapFixed* CreatePlannedNoFixedCheck(float param1);
    virtual void PostCreatePlanned(MultiMapFixed& param1);
    virtual bool IsCivic();
    virtual ABODE_TYPE GetAbodeType();
    virtual float GetDesireToBeRepaired();
    virtual void Draw();

    // === Fields ===
    float              field_0x28;       // 0x28
    float              scale;            // 0x2C
    uint32_t           field_0x30;       // 0x30
    uint32_t           field_0x34;       // 0x34
    GFootpathLink*     footpath_link;    // 0x38
    int                creation_turn;    // 0x3C
    GObjectInfo*       info;             // 0x40
    PlannedMultiMapFixed* next;          // 0x44 — linked list next
};
static_assert(sizeof(PlannedMultiMapFixed) == 0x48, "PlannedMultiMapFixed size mismatch");
