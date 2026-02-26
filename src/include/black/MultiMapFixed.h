#pragma once
// MultiMapFixed — multi-cell fixed building object
// Struct layout from bw1-decomp
//
// Size: 0x7C bytes (inherits 0x58 from Fixed)
// Vtable: 0x90C bytes (extends Fixed's 0x864 with 42 new methods)
//
// Multi-cell buildings (Abode, Workshop, Citadel, etc.) that occupy
// multiple map cells. Supports building/repair progress, resource
// management, footpath connectivity, and collision data.

#include "Fixed.h"

// Forward declarations
struct BuildingSite;
struct GMultiMapFixedInfo;
struct LH3DMesh;
struct NewCollide;
struct PlannedMultiMapFixed;
struct PotStructure;

// Abode type enum (partial)
enum ABODE_TYPE : uint32_t {
    ABODE_TYPE_NONE = 0,
    // ... remaining entries
};

struct MultiChild {
    Object*  object;   // 0x0
    uint32_t coords;   // 0x4 — packed JustMapXZ (x, z as uint16_t pair)
};
static_assert(sizeof(MultiChild) == 0x8, "MultiChild size mismatch");

struct MultiChildList {
    MultiChild* array;     // 0x0
    uint32_t    size;      // 0x4
    uint32_t    capacity;  // 0x8
};
static_assert(sizeof(MultiChildList) == 0xC, "MultiChildList size mismatch");

struct MultiMapFixed : public Fixed {
    // === Overrides of GameThing virtuals ===
    Town* GetTown() override;
    bool IsFootpathLink() override;
    GFootpathLink* GetFootpathLink() override;
    uint32_t GetNearestPathTo(const MapCoords& coords, float param2, int param3) override;
    void UseFootpathIfNecessary(Living* living, const MapCoords* coords, uint8_t param3) override;
    uint32_t AddFootpath(GFootpath* footpath) override;
    uint32_t RemoveFootpath(GFootpath* footpath) override;
    uint32_t AddResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool param4, const MapCoords& coords, int param6) override;
    uint32_t RemoveResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool* param4) override;
    MultiMapFixed* CastMultiMapFixed() override;
    bool IsFunctional() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;

    // === Overrides of GameThingWithPos virtuals ===
    MapCoords* GetArrivePos(MapCoords* out) override;
    bool IsObjectInMap_0() override;
    bool32_t IsBeingBuilt(Creature* creature) override;
    bool32_t NeedsRepair(Creature* creature) override;
    bool32_t IsBuildingWhichIsBeingBuilt(Creature* creature) override;
    bool32_t IsWonder() override;
    bool32_t CreateBuildingSite() override;

    // === Overrides of Object virtuals ===
    Object* GetMapChild(const MapCell* cell) override;
    void SetMapChild(Object* object, MapCell* cell) override;
    void InsertMapObject() override;
    void RemoveMapObject() override;
    int MoveMapObject(const MapCoords& coords) override;
    void ReduceLife(float value, GPlayer* player) override;
    uint32_t Process() override;
    void Draw() override;
    uint32_t GetDiscipleStateIfInteractedWith(GInterfaceStatus* status, Villager* villager) override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    MultiMapFixed* AsMultiMapFixed() override;
    bool IsResourceStore(RESOURCE_TYPE type) override;
    bool DeleteObjectAndTakeResource(Object* param1, GInterfaceStatus* param2) override;
    bool DoCreatureMimicAfterAddingResource(RESOURCE_TYPE type, GInterfaceStatus* status) override;
    void StartOnFire() override;
    bool InteractsWithPhysicsObjects() override;
    bool CreatureMustAvoid(Creature* param1) override;
    bool32_t IsSolidToNewAbode() override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;
    NewCollide* GetCollideData() const override;

    // === Override of Fixed virtuals ===
    bool IsObjectFullyInMap() override;

    // === New virtual methods (vtable 0x864-0x908) ===
    virtual MapCoords* GetDoorPos(MapCoords* pos);
    virtual float GetInfluence();
    virtual bool IsPlaytimeStructure();
    virtual bool IsPlaytimeStarted();
    virtual bool AddPlaytimeVillager(Villager* villager);
    virtual void CheckMapObject_1();
    virtual void GetResourceDropPosForComputerPlayer(MapCoords* drop_pos);
    virtual float GetPercentBuilt();
    virtual float GetPercentRepaired();
    virtual float GetPercentRepairedFromWhenDamaged();
    virtual bool IsRepaired();
    virtual bool IsBuilt();
    virtual float GetPercentRepairedForNonFunctional();
    virtual float GetPercentForDrawBuilding();
    virtual float GetPercentAbodeFullWithAdults();
    virtual float GetPercentAbodeFullWithChildren();
    virtual bool IsDrawBuilding();
    virtual bool Built();
    virtual bool Repaired();
    virtual uint32_t GetBuildingSiteWood(uint32_t* param1);
    virtual LH3DMesh* GetDestructionMesh();
    virtual void RemoveDamage();
    virtual void* GetBuildingObject();
    virtual bool IsCivic();
    virtual ABODE_TYPE GetAbodeType();
    virtual void SetPower(float power);
    virtual MapCoords* GetResourcePos(RESOURCE_TYPE type, int param2);
    virtual bool IsPoisonedResource();
    virtual MapCoords* GetResourceNearestEdge(MapCoords* coords, RESOURCE_TYPE type, Object* param3, int param4);
    virtual float GetDesireToBeRepaired();
    virtual void AddToPlayer();
    virtual void RemoveFromPlayer();
    virtual uint32_t DoResourceAdding(RESOURCE_TYPE type, GInterfaceStatus* iface, bool param3, MapCoords* param4, int param5);
    virtual uint32_t DoResourceRemoving(RESOURCE_TYPE type, uint32_t param2, GInterfaceStatus* iface, bool param4);
    virtual int CalulateAmountOverMaximum(RESOURCE_TYPE type);
    virtual void SetTown(Town* town);
    virtual void RemovePotFromStructure(PotStructure* structure);
    virtual bool GetShouldNotBeAddedToPlanned();
    virtual void SetShouldNotBeAddedToPlanned(bool value);
    virtual void BuildBy(float param1);
    virtual PlannedMultiMapFixed* ConvertToPlanned();
    virtual void CreateCollideData();

    // === Fields ===
    uint8_t         field_0x58;          // 0x58
    // 3 bytes padding
    float           percent_built;       // 0x5C
    uint32_t        field_0x60;          // 0x60
    GFootpathLink*  footpath_link;       // 0x64
    MultiChildList  multi_children_array;// 0x68 (0x0C bytes)
    BuildingSite*   building_site;       // 0x74
    NewCollide*     collide_data;        // 0x78
};
static_assert(sizeof(MultiMapFixed) == 0x7C, "MultiMapFixed size mismatch");
