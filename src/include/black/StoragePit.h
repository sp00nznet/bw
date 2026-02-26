#pragma once
// StoragePit — resource storage building
// Struct layout from bw1-decomp
//
// Size: 0xDC bytes (inherits 0xC4 from Abode)
// Vtable: 0x92C bytes (same as Abode, overrides ~27 methods)
//
// StoragePit is a building that stores food and wood resources.
// It manages PileFood/PileWood visual piles and handles resource
// poisoning, creature feeding, and magic resource effects.

#include "Abode.h"

// Forward declarations
struct PileFood;
struct PileWood;
struct PileResource;
struct PotStructure;

struct StoragePit : public Abode {
    // === Overrides of Base virtuals ===
    void Delete(int param) override;
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    uint32_t AddResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool param4, const MapCoords& coords, int param6) override;
    uint32_t RemoveResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool* param4) override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    MapCoords* GetArrivePos(MapCoords* out) override;
    bool32_t IsCastShadowAtNight() override;
    bool32_t CanBeEatenByCreature(Creature* creature) override;
    bool32_t CanActAsAContainer(Creature* creature) override;
    bool32_t CanHaveMagicFoodCastOnMe(Creature* creature) override;
    bool32_t CanHaveMagicWoodCastOnMe(Creature* creature) override;
    bool32_t IsStoragePit(Creature* creature) override;
    bool32_t IsStoragePitWithFoodInIt(Creature* creature) override;
    bool32_t IsStoragePitBelongingToAnotherPlayer(Creature* creature) override;
    bool32_t IsStoragePitBelongingToMyPlayer(Creature* creature) override;
    bool32_t IsPoisoned() override;

    // === Overrides of Object virtuals ===
    void Draw() override;
    uint32_t GetDiscipleStateIfInteractedWith(GInterfaceStatus* status, Villager* villager) override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    LH3DObject_ObjectType Get3DType() override;
    bool IsResourceStore(RESOURCE_TYPE type) override;
    bool DeleteObjectAndTakeResource(Object* param1, GInterfaceStatus* param2) override;
    bool DoCreatureMimicAfterAddingResource(RESOURCE_TYPE type, GInterfaceStatus* status) override;
    void SetPoisonedResource(RESOURCE_TYPE type, int param2) override;
    void SetPoisoned(int param1) override;
    void ReactToPhysicsImpact(PhysicsObject* param1, bool param2) override;

    // === Overrides of MultiMapFixed virtuals ===
    bool IsPoisonedResource() override;
    MapCoords* GetResourceNearestEdge(MapCoords* coords, RESOURCE_TYPE type, Object* param3, int param4) override;
    int CalulateAmountOverMaximum(RESOURCE_TYPE type) override;
    void RemovePotFromStructure(PotStructure* structure) override;

    // === Overrides of Abode virtuals ===
    void DeleteDependancys() override;
    void MakeFunctional() override;
    void StopBeingFunctional(GPlayer* param1) override;
    void RestartBeingFunctional() override;
    bool CausesTownEmergencyIfDamaged() override;

    // === Fields ===
    PileFood*     pile_food;   // 0xC4
    PileWood*     pile_wood;   // 0xC8
    PileResource* field_0xcc;  // 0xCC
    PileResource* field_0xd0;  // 0xD0
    PileResource* field_0xd4;  // 0xD4
    PileResource* field_0xd8;  // 0xD8
};
static_assert(sizeof(StoragePit) == 0xDC, "StoragePit size mismatch");
