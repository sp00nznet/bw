#pragma once
// BigForest — large forest area (multi-cell map object)
// Struct layout from bw1-decomp
//
// Size: 0x88 bytes (inherits 0x7C from MultiMapFixed + 0xC bytes)
// Simple methods at 0x00438dxx-0x00438exx are packed 16 bytes apart.
// Complex methods at 0x00438fxx-0x004395xx.

#include "MultiMapFixed.h"

// Forward declarations
struct Forest;
struct GBigForestInfo;

struct BigForest : public MultiMapFixed {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    uint32_t RemoveResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool* param4) override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of Object virtuals ===
    int GetMesh() const override;
    void Draw() override;
    uint32_t GetDiscipleStateIfInteractedWith(GInterfaceStatus* status, Villager* villager) override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    LH3DObject_ObjectType Get3DType() override;
    float GetWoodValue() override;
    bool32_t ValidForPlaceInHand(GInterfaceStatus* status) override;
    bool32_t InterfaceSetInMagicHand(GInterfaceStatus* status) override;
    bool32_t IsTuggable() override;
    bool InteractsWithPhysicsObjects() override;
    bool CreatureMustAvoid(Creature* param1) override;
    bool32_t VillagerMustAvoid(Villager* param1) override;
    uint32_t GetCarriedTreeType() override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;

    // === Fields ===
    uint32_t field_0x7c;   // 0x7C
    Forest*  forest;       // 0x80
    uint32_t field_0x84;   // 0x84
};
static_assert(sizeof(BigForest) == 0x88, "BigForest size mismatch");
