#pragma once
// FishFarm — fishing building that produces food from water
// Struct layout from bw1-decomp
//
// Size: 0x98 bytes (inherits 0x7C from MultiMapFixed)
// Vtable: extends MultiMapFixed

#include "MultiMapFixed.h"

// Forward declarations
struct ControlHandUpdateInfo;
struct LHOSFile;

// Lionhead linked list of Villagers (LHLinkedList<Villager>)
struct LHLinkedList_Villager {
    void*    head;   // 0x0
    uint32_t count;  // 0x4
};
static_assert(sizeof(LHLinkedList_Villager) == 0x8, "LHLinkedList_Villager size mismatch");

struct FishFarm : public MultiMapFixed {
    // === Overrides of Base/GameThing virtuals ===
    void ToBeDeleted(int param) override;
    GPlayer* GetPlayer() override;
    Town* GetTown() override;
    float Get2DRadius() override;
    uint32_t RemoveResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool* param4) override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    MapCoords* GetArrivePos(MapCoords* out) override;
    uint32_t GetCreatureBeliefType() override;
    bool IsObjectInMap_0() override;
    bool32_t CanBeEatenByCreature(Creature* creature) override;
    bool32_t CanBeSleptNextToByCreature(Creature* creature) override;
    bool32_t CanBePickedUpByCreature(Creature* creature) override;
    bool32_t CanBeStompedOnByCreature(Creature* creature) override;
    bool32_t CanBeGivenToVillager(Creature* creature) override;
    bool32_t CanBePutInAStoragePit(Creature* creature) override;
    bool32_t CanBeDestroyedByStoning(Creature* creature) override;
    bool32_t CanBeExaminedByCreature(Creature* creature) override;
    bool32_t IsBeingBuilt(Creature* creature) override;
    bool32_t NeedsRepair(Creature* creature) override;
    bool32_t CanBePoodOn(Creature* creature) override;

    // === Overrides of Object virtuals ===
    Object* GetMapChild(const MapCell* cell) override;
    void SetMapChild(Object* object, MapCell* cell) override;
    void InsertMapObject() override;
    void RemoveMapObject() override;
    float GetMeshRadius() const override;
    uint32_t Process() override;
    void Draw() override;
    uint32_t GetDiscipleStateIfInteractedWith(GInterfaceStatus* status, Villager* villager) override;
    float GetHeightForHandAboveInteractObject() override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    float GetFoodValue(FOOD_TYPE type) override;
    RESOURCE_TYPE GetResourceType() override;
    bool IsLockedInInteract() override;
    bool32_t ValidForLockedSelectProcess(GInterfaceStatus* status) override;
    bool32_t NetworkFriendlyStartLockedSelect(GInterfaceStatus* status) override;
    bool32_t NetworkUnfriendlyLockedSelect(ControlHandUpdateInfo* param1) override;
    bool32_t NetworkUnfriendlyEndLockedSelect() override;
    bool32_t NetworkFriendlyEndLockedSelect(GInterfaceStatus* status) override;
    bool32_t ValidForPlaceInHand(GInterfaceStatus* status) override;
    bool32_t InterfaceSetInMagicHand(GInterfaceStatus* status) override;
    bool InteractsWithPhysicsObjects() override;
    bool CreatureMustAvoid(Creature* param1) override;
    uint32_t ProcessInInteract(GInterfaceStatus* status) override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;

    // === Overrides of MultiMapFixed virtuals ===
    MapCoords* GetDoorPos(MapCoords* pos) override;
    PlannedMultiMapFixed* ConvertToPlanned() override;

    // === Fields ===
    FishFarm*              next;       // 0x7C — linked list next
    LHLinkedList_Villager  villagers;  // 0x80 — villagers working here
    uint32_t               field_0x88; // 0x88
    Town*                  town;       // 0x8C
    float                  field_0x90; // 0x90
    float                  field_0x94; // 0x94
};
static_assert(sizeof(FishFarm) == 0x98, "FishFarm size mismatch");
