#pragma once
// WorshipSite — worship site building (CitadelPart subclass)
// Struct layout from bw1-decomp
//
// Size: 0x128 bytes (inherits 0x8C from CitadelPart)
// Vtable: extends MultiMapFixedVftable, overrides ~40 methods
//
// Manages spell icons, worship totems, dances, and resource storage
// for religious/prayer activities in a town.

#include "CitadelPart.h"
#include "WorshipSpellIcon.h"

// Forward declarations
struct Dance;
struct GTribeInfo;
struct PotStructure;
struct ShowNeeds;
struct WorshipTotem;

// Forward-declare enums
enum ABODE_TYPE : uint32_t;
enum SPELL_SEED_TYPE : uint32_t;

struct WorshipSite : public CitadelPart {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;                                    // 0x0077aa60

    // === Overrides of GameThing virtuals ===
    void RemoveDance() override;                                             // 0x0055dc50
    uint32_t GetResource(RESOURCE_TYPE type) override;                       // 0x0077bd80
    uint32_t AddResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool param4, const MapCoords& coords, int param6) override; // 0x0077c5f0
    uint32_t RemoveResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool* param4) override; // 0x0077c670
    char* GetDebugText() override;                                           // 0x0055dce0
    uint32_t GetShowNeedsPos(uint32_t param1, MapCoords* param2) override;   // 0x0077cd70
    uint32_t Load(GameOSFile* file) override;                                // 0x0077d700
    uint32_t Save(GameOSFile* file) override;                                // 0x0077d2f0
    uint32_t GetSaveType() override;                                         // 0x0055dcd0
    void ResolveLoad() override;                                             // 0x0077daf0

    // === Overrides of GameThingWithPos virtuals ===
    MapCoords* GetArrivePos(MapCoords* out) override;                        // 0x0077ced0
    void GetInteractPos(LHPoint* pos) override;                              // 0x0055dc30
    uint32_t IsSuitableForCreatureAction() override;                         // 0x0055dc80
    uint32_t CanHaveMagicFoodCastOnMe(Creature* creature) override;          // 0x004e4b60
    bool32_t IsWorshipSite_0(Creature* creature) override;                    // 0x0055dc90
    bool32_t IsWorshipSite_1() override;                                     // 0x0055dca0
    WorshipSite* GetWorshipSite() override;                                  // 0x0055dcb0
    float CalculateDesireForFood() override;                                 // 0x0077c310
    float CalculateDesireForRest() override;                                 // 0x0077c390
    float CalculatePeopleHidingIndicator() override;                         // 0x0077c3d0
    uint32_t GetScriptObjectType() override;                                 // 0x0077d2e0

    // === Overrides of Object virtuals ===
    void UpdateFrom3DPosition() override;                                    // 0x0077d030
    LHPoint* GetDefaultFireCentrePos(LHPoint* pos) override;                 // 0x0077dde0
    float GetDefaultFireRadius() override;                                   // 0x0077de10
    uint32_t Process() override;                                             // 0x0077b1d0
    int GetMesh() const override;                                            // 0x0055dcc0
    void Draw() override;                                                    // 0x005193d0
    uint32_t GetDiscipleStateIfInteractedWith(GInterfaceStatus* status, Villager* villager) override; // 0x0077de70
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;  // 0x0077b9d0
    bool IsResourceStore(RESOURCE_TYPE type) override;                       // 0x0077dec0
    bool DeleteObjectAndTakeResource(Object* object, GInterfaceStatus* status) override; // 0x0077e7b0
    float GetRadiusMultiplierForApplyingPotToPos() override;                 // 0x0077e480
    bool DoCreatureMimicAfterAddingResource(RESOURCE_TYPE type, GInterfaceStatus* status) override; // 0x0077def0
    float GetDistanceFromObject_1(Object* object) override;                  // 0x0077de20
    bool InteractsWithPhysicsObjects() override;                             // 0x0055dc60
    bool GetInspectObjectPos(Villager* villager, MapCoords* coords) override; // 0x0077ae30
    uint32_t GetSpecialPos(uint32_t param1, MapCoords* param2) override;     // 0x0077cc90
    uint32_t GetObjectCollide() override;                                    // 0x0077d000
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;   // 0x0077c120
    void GetNearestEdgeOfObject(Object* object) override;                    // 0x0077dc90

    // === Overrides of MultiMapFixed virtuals ===
    void GetResourceDropPosForComputerPlayer(MapCoords* coords) override;    // 0x0077e460
    bool IsBuilt() override;                                                 // 0x0077bdd0
    bool Built() override;                                                   // 0x0077ac10
    ABODE_TYPE GetAbodeType() override;                                      // 0x0055dc70
    MapCoords* GetResourcePos(RESOURCE_TYPE type, int param) override;       // 0x0077c5d0
    MapCoords* GetResourceNearestEdge(MapCoords* out, RESOURCE_TYPE type, Object* object, int param) override; // 0x0077c6d0
    void RemovePotFromStructure(PotStructure* structure) override;           // 0x0077ae10

    // === Non-virtual methods ===
    MapCoords* GetSpellIconPosFromSlot(MapCoords* coords, uint32_t slot, float angle); // 0x0077afc0
    MapCoords* GetSpellIconPos(MapCoords* coords, int16_t* slot);            // 0x0077b080
    void AddSpellIcon(WorshipSpellIcon* icon);                               // 0x0077c430
    void AddTownSpells(Town* town);                                          // 0x0077c910
    void AddSpellIconIfNecessary(SPELL_SEED_TYPE seed_type);                 // 0x0077c9e0
    MapCoords* GetTotemPos(MapCoords* coords);                               // 0x0077cf30
    void RemoveVillagerFromWorshipCount(Villager* villager);                  // 0x0077d0a0
    void RemoveVillagerRequestingToGoHome(Villager* villager);               // 0x0077e1d0
    int GetNumVillagersRequestingToGoHome();                                 // 0x0077e260

    // === Fields ===
    GTribeInfo*                      tribe_info;     // 0x8C
    ShowNeeds*                       show_needs;     // 0x90
    uint32_t                         field_0x94;     // 0x94
    uint32_t                         field_0x98;     // 0x98
    uint32_t                         field_0x9c;     // 0x9C
    Dance*                           dance;          // 0xA0
    uint8_t                          field_0xa4[0x14]; // 0xA4
    int32_t*                         field_0xb8;     // 0xB8
    uint8_t                          field_0xbc[0xC]; // 0xBC
    int32_t                          field_0xc8;     // 0xC8
    uint8_t                          field_0xcc[0xC]; // 0xCC
    int32_t                          field_0xd8;     // 0xD8
    WorshipTotem*                    totem;          // 0xDC
    LHListHead_WorshipSpellIcon      icon_list;      // 0xE0
    uint8_t                          field_0xe8[0x2C]; // 0xE8
    float                            field_0x114;    // 0x114
    float                            field_0x118;    // 0x118
    float                            field_0x11c;    // 0x11C
    uint32_t                         field_0x120;    // 0x120
    int32_t  num_villagers_requesting_to_go_home;    // 0x124
};
static_assert(sizeof(WorshipSite) == 0x128, "WorshipSite size mismatch");
