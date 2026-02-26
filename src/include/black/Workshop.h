#pragma once
// Workshop — crafting/production building
// Struct layout from bw1-decomp
//
// Size: 0xE8 bytes (inherits 0xC4 from Abode)
// Vtable: 0x92C bytes (same as Abode, overrides ~24 methods)
//
// Workshop is a building where villagers craft scaffolding
// and other building materials. It overrides resource
// management, serialization, and creature interaction methods.

#include "Abode.h"

struct Workshop : public Abode {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    uint32_t AddResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool param4, const MapCoords& coords, int param6) override;
    uint32_t RemoveResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool* param4) override;
    char* GetDebugText() override;
    uint32_t GetShowNeedsPos(uint32_t param1, MapCoords* param2);
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
    void ResolveLoad() override;

    // === Overrides of GameThingWithPos virtuals ===
    bool32_t CanActAsAContainer(Creature* creature) override;
    bool32_t IsStoragePit(Creature* creature) override;
    bool32_t IsWorkshop_0() override;
    bool32_t IsWorkshop_1(Creature* creature) override;
    bool32_t CreateBuildingSite() override;

    // === Overrides of Object virtuals ===
    void ScaffoldMoved(Scaffold* scaffold) override;
    uint32_t Process() override;
    void Draw() override;
    uint32_t GetDiscipleStateIfInteractedWith(GInterfaceStatus* status, Villager* villager) override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    LH3DObject_ObjectType Get3DType() override;
    bool IsResourceStore(RESOURCE_TYPE type) override;
    bool DeleteObjectAndTakeResource(Object* param1, GInterfaceStatus* param2) override;
    bool DoCreatureMimicAfterAddingResource(RESOURCE_TYPE type, GInterfaceStatus* status) override;

    // === Non-virtual methods ===
    int GetSpaceInStore();
    float GetDesireToBeSupplied();
    float GetVisualWoodDesire();

    // === Fields ===
    uint8_t field_0xc4[0x24];  // 0xC4 — unknown data
};
static_assert(sizeof(Workshop) == 0xE8, "Workshop size mismatch");
