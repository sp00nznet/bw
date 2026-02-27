#pragma once
#include "GroupBehaviour.h"

struct GDanceInfo;
struct GFootpath;
struct GFootpathLink;
struct Town;

struct Dance : public GroupBehaviour {
    // === Overrides (GameThing) ===
    GFootpathLink* GetFootpathLink() override;
    uint32_t AddFootpath(GFootpath*) override;
    uint32_t RemoveFootpath(GFootpath*) override;
    char*    GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides (GameThingWithPos) ===
    MapCoords* GetArrivePos(MapCoords*) override;
    bool32_t   IsDance() const override;
    uint32_t   GetScriptObjectType() override;

    // === Overrides (GroupBehaviour) ===
    void  Process() override;
    float GetAngle() override;

    // === Fields ===
    uint8_t field_0xe8[0x44];  // 0xE8
};
static_assert(sizeof(Dance) == 0x12C, "Dance size mismatch");
