#pragma once
// BuildingSite — manages construction of buildings
// Struct layout from bw1-decomp
//
// Size: 0x644 bytes (inherits 0x14 from GameThing)
// Vtable: 0x12C bytes (extends GameThingVftable with 12 new virtual methods)
//
// Contains 127 build positions (LHPoint[0x7F]) and a linked list of
// building workers. The custom vtable adds Init, Process, wood/resource
// management, and position calculation methods.

#include "GameThing.h"
#include "LHNodeList.h"

// Forward declarations
struct MultiMapFixed;
struct PlannedMultiMapFixed;
struct Pot;
struct PotStructure;
struct Object;
struct Villager;

// LHLinkedList<Villager> — 8-byte linked list head

struct BuildingSite : public GameThing {
    // === New virtual methods (extending vtable at 0xFC — 12 entries) ===
    virtual void Init();                                                    // 0x0043b950
    virtual void Process();                                                 // (subclass overrides)
    virtual uint32_t GetWoodForStats();                                     // (subclass overrides)
    virtual Pot* GetPileWood(const MapCoords& coords);                      // (subclass overrides)
    virtual void SetPileWood(Pot* pile);                                    // (subclass overrides)
    virtual void CreatePileWood();                                          // (subclass overrides)
    virtual void GetResourcePosAndYAngle(uint32_t type, uint32_t param2, float* out); // (subclass overrides)
    virtual void RemovePotFromStructure(PotStructure* structure);           // (subclass overrides)
    virtual bool IsLinkedToThisBuildingSite(Pot* pot);                      // (subclass overrides)
    virtual float GetNearestEdge(float x, float y, int* out);              // (subclass overrides)
    virtual void GetNextPosFromIndex(int* index);                           // (subclass overrides)
    virtual void GetRandomBuildPos(Object* object, int* out);              // (subclass overrides)

    // === Overrides of Base virtuals ===
    ~BuildingSite() override;                                               // 0x0043b7b0
    void ToBeDeleted(int param) override;                                   // 0x0043b960

    // === Overrides of GameThing virtuals ===
    Town* GetTown() override;                                               // 0x0043c0b0
    float GetRadius() override;                                             // 0x0043d050
    uint32_t GetResource(RESOURCE_TYPE type) override;                      // 0x0043c5b0
    uint32_t AddResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool param4, const MapCoords& coords, int param6) override; // 0x0043c490
    uint32_t RemoveResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool* param4) override; // 0x0043c530
    uint32_t Load(GameOSFile* file) override;                               // 0x0043cad0
    uint32_t Save(GameOSFile* file) override;                               // 0x0043c830
    uint32_t GetSaveType() override;                                        // 0x0043b7a0

    // === Non-virtual methods ===
    MultiMapFixed* GetBuilding();                                           // 0x0043bc70
    MultiMapFixed* GetRootBuilding();                                       // 0x0043bca0
    float GetClearAreaRadius();                                             // 0x0043bde0
    float GetDesireToBeRepaired();                                          // 0x0043be00
    float GetWoodValue();                                                   // 0x0043c0c0
    float GetWoodNeededToBuild();                                           // 0x0043c5f0
    bool32_t ShouldIGetWood(Villager* villager);                            // 0x0043c680
    void BuildBy(float amount);                                             // 0x0043d080

    // === Fields ===
    // v1.0 sub_433FE0: the site of a building under construction (or repair).
    void Construct(MultiMapFixed* building);
    MultiMapFixed*           root_building;          // 0x14
    LHNodeList               building_worker_list;   // 0x18 — its builders
    uint8_t                  field_0x20[0x14];       // 0x20
    LHPoint                  building_positions[128]; // 0x34 — sub_435460, around the building
    uint32_t                 wood_used;              // 0x634 — v1.0 this[397]
    uint32_t                 field_0x638;            // 0x638 — v1.0 this[398]: building +0x58 bit 2
    float                    field_0x63c;            // 0x63C — v1.0 this[399]
    float                    life;                   // 0x640 — v1.0 this[400]
};
static_assert(sizeof(BuildingSite) == 0x644, "BuildingSite size mismatch");
