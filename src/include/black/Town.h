#pragma once
// Town — central gameplay entity managing a settlement
// Struct layout from bw1-decomp
//
// Size: 0xF28 bytes (inherits 0x30 from Container)
// Vtable: ContainerVftable (0x500 bytes, no new virtual slots)
//
// Town is the largest class in the game. It manages population,
// desires, buildings, fields, worship, resources, and player interaction.
// Contains embedded TownDesire (0x564), TownStats (0x118), and GBelief (0x1D0).

#include "LHNodeList.h"
#include <vector>
#include <cstddef>
#include "Container.h"
#include "TownDesire.h"
#include "TownStats.h"
#include "GBelief.h"
#include "EffectValues.h"
#include "types.h"

// Forward declarations
struct Abode;
struct BuildingSite;
struct Citadel;
struct Creature;
struct Creche;
struct Field;
struct Forest;
struct FishFarm;
struct GMultiMapFixedInfo;
struct GTownInfo;
struct GTribeInfo;
struct MultiMapFixed;
struct Object;
struct PlannedMultiMapFixed;
struct StoragePit;
struct TotemStatue;
struct TownCentre;
struct TownDesireFlags;
struct TownSpellIcon;
struct TownArtifact;
struct Villager;
struct Workshop;
struct WorshipSite;

// Forward-declare enums
enum ABODE_TYPE : uint32_t;
enum LIVING_TYPE : uint32_t;
enum MAGIC_TYPE : uint32_t;
enum TOWN_DESIRE_INFO : uint32_t;
enum TRIBE_TYPE : uint32_t;

// Per-type linked list structs (8 bytes each, Lionhead LH pattern)
struct LHListHead_Abode { void* head; uint32_t count; };
static_assert(sizeof(LHListHead_Abode) == 0x8, "size mismatch");

struct LHLinkedList_HomelessVillager { void* first; void* last; };
static_assert(sizeof(LHLinkedList_HomelessVillager) == 0x8, "size mismatch");

struct LHListHead_TownSpellIcon { void* head; uint32_t count; };
static_assert(sizeof(LHListHead_TownSpellIcon) == 0x8, "size mismatch");


struct LHLinkedList_Playthings { void* first; void* last; };
static_assert(sizeof(LHLinkedList_Playthings) == 0x8, "size mismatch");

struct LHLinkedList_TownArtifactList { void* first; void* last; };
static_assert(sizeof(LHLinkedList_TownArtifactList) == 0x8, "size mismatch");

struct LHListHead_PlannedMMF { void* head; uint32_t count; };
static_assert(sizeof(LHListHead_PlannedMMF) == 0x8, "size mismatch");

// PlayerTownInteract — per-player interaction history (0x80 bytes)
// Defined inline in vendor Town.h
struct PlayerTownInteract {
    uint32_t      field_0x0;       // 0x00
    float         field_0x4;       // 0x04
    float         field_0x8;       // 0x08
    uint32_t      field_0xc;       // 0x0C
    float         field_0x10;      // 0x10
    uint32_t      field_0x14[10];  // 0x14
    EffectValues  effect_values;   // 0x3C
    uint32_t      field_0x7c;      // 0x7C
};
static_assert(sizeof(PlayerTownInteract) == 0x80, "PlayerTownInteract size mismatch");

// Member function pointer type for area-checking callbacks
using ObjectCompareFunc = int (Object::*)(const void*, const void*);

struct Town : public Container {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    Town* GetTown() override;
    float GetVillagerActivityDesire(Villager* villager) override;
    void SetVillagerActivity(Villager* villager) override;
    float GetRadius() override;
    uint16_t GetNumberOfInstanceForGlobalList() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
    void ResolveLoad() override;

    // === Overrides of GameThingWithPos virtuals ===
    uint32_t GetCreatureBeliefType() override;
    uint32_t GetCreatureBeliefListType() override;
    Citadel* GetCitadel() override;
    uint32_t GetOrigin() override;
    bool IsTown_0() override;
    bool IsTown_1(Creature* creature) override;
    bool IsActivityObjectWhichAngerAppliesTo(Creature* creature) override;
    bool IsActivityObjectWhichCompassionAppliesTo(Creature* creature) override;
    bool IsActivityObjectWhichPlayfulnessAppliesTo(Creature* creature) override;
    bool IsTownBelongingToAnotherPlayer(Creature* creature) override;
    bool32_t IsSuitableForCreatureActivity() override;
    bool32_t CanBePlayedWithByCreature(Creature* creature) override;
    WorshipSite* GetWorshipSite() override;
    bool32_t IsTownBelongingToOtherPlayer(Creature* creature) override;
    bool32_t IsScriptContainer() const override;
    const char* GetText() override;
    float CalculateDesireForFood() override;
    uint32_t GetScriptObjectType() override;

    // === Static methods ===
    static Town* GetNearestTownToPos(const MapCoords& coords, TRIBE_TYPE tribe_type,
                                     ABODE_TYPE abode_type, float max_distance);  // 0x0073b170
    static void AsssignTownFeature();                                              // 0x0073eac0
    static bool FindClearArea(MapCoords& p1, MapCoords& p2, float p3, float p4,
                              float p5, ObjectCompareFunc callback, Object* obj);  // 0x007412f0
    static bool CheckForClearArea(MapCoords& p1, float p2,
                                  ObjectCompareFunc callback, Object* obj);        // 0x007413d0

    // === Non-virtual methods ===
    void AddStructureToTown(MultiMapFixed* structure);
    void RecalculateBounds();
    void SetStoragePit(StoragePit* pit);                                           // v1.0 sub_6D16B0                                                      // v1.0 sub_6CE1E0 (first half)
    void AddAbodeToTownStats(Abode* abode);                                        // 0x00739a20
    bool AddVillagerToTown(Villager* villager);                                    // 0x0073a090
    PlannedMultiMapFixed* GetBestPlanned(float& score, ABODE_TYPE type);           // 0x0073a140
    float GetDesireToBeBuilt(const GMultiMapFixedInfo* info, unsigned long param);  // 0x0073a1a0
    bool32_t RequestBestPlanned();                                                  // 0x0073a650
    void ChildToAdult(Villager* villager);                                          // 0x0073af50
    bool IsHarvestTime();                                                           // 0x0073b2d0
    bool32_t RequestANewAbode(ABODE_TYPE type);                                     // 0x0073b330
    Abode* FindAbodeWithSpaceInTown(Villager* villager, float min_score);           // 0x0073b370
    Field* FindClosesFieldToWithFood(const MapCoords& pos);                         // 0x0073b3d0
    bool32_t IsVillagerInHomelessList(Villager* villager);                           // 0x0073b580
    StoragePit* GetStoragePit();                                                    // 0x0073b5b0
    void Birthday();                                                                // 0x0073b5d0
    BuildingSite* AddBuildingSite(PlannedMultiMapFixed* planned);                   // 0x0073b860
    BuildingSite* AddBuildingSiteNoFixedCheck(PlannedMultiMapFixed* planned);       // 0x0073b8a0
    void AddBuildingSite(BuildingSite* site);                                       // v1.0 sub_6CEAF0: onto the site list (+0x788)
    uint32_t RemoveBuildingSite(MultiMapFixed* structure);                           // 0x0073ba20
    void SetBeliefInPlayer(GPlayer* player, float value);                           // 0x0073ba70
    void SetWorshipPercentage(float percentage);                                    // 0x0073c060
    void AdjustWorshipersWorshipping(long param1, int param2, int param3);          // 0x0073c0f0
    GTribeInfo* GetTribe() const;                                                   // 0x0073c840
    int GetWorshipersNeeded(int param1, int param2, int* result);                   // 0x0073c860
    bool32_t IsBuildingSiteValid(BuildingSite* site);                               // 0x0073cf00
    bool32_t GetBestBuildingSite(const MapCoords& pos, int param);                  // 0x0073cf60
    void AddPlanned(PlannedMultiMapFixed* planned);                                 // v1.0 sub_6CFFB0: tail of the planned list (+0x9A0)
    void RemovePlanned(PlannedMultiMapFixed* planned);                              // 0x0073d0d0
    void AllVillagersCheckNeedNewAbode();                                            // 0x0073d150
    TownSpellIcon* GetNextSpellIcon(TownSpellIcon* icon);                           // 0x0073d360
    bool AddMagicTypesHeld(MAGIC_TYPE type);                                        // 0x0073d380
    bool IsMagicTypeHeld(MAGIC_TYPE type);                                          // 0x0073d630
    bool GetFlock(LIVING_TYPE type, int param);                                     // 0x0073de30
    TotemStatue* GetTotemStatue();                                                  // 0x0073e1d0
    void RemoveVillager(Villager* villager);                                        // 0x0073e210
    void RemoveVillagerOnWayToWorshipSite(Villager* villager);                      // 0x0073e360
    float GetDesire(TOWN_DESIRE_INFO desire);                                       // 0x0073e400
    float GetRawDesire(TOWN_DESIRE_INFO desire);                                    // 0x0073e420
    void* GetTemporaryResourceStorePotOrPos(const MapCoords& p1, MapCoords& p2,
                                            RESOURCE_TYPE type);                    // 0x0073e900
    void AssignForestsToTown();                                                     // 0x0073eb00
    Workshop* GetBestWorkshop(MapCoords& pos, int p2, int p3);                      // 0x00740250
    MapCoords* GetCongregationPos(MapCoords* out);                                  // 0x007408b0
    void MakeScenicForest();                                                        // 0x00741b40
    void UpdateAttitudeToCreature();                                                // 0x007437f0
    uint32_t Process();                                                             // v1.0 sub_6D8EB0
    float TownInfoInfluence() const;                                                // v1.0 sub_6D2810
    void ProcessAbodes(uint32_t turn, uint32_t period);                             // v1.0 sub_6D9120

    // v1.0 sub_6CD070: the state the constructor leaves on a zeroed Town.
    // See docs/constructors.md for what is translated and what is not yet.
    // v1.0 sub_6CD9F0(info, 0): how much the town wants the planned building.
    float PlanScore(const void* info, uint32_t a3);
    // v1.0 sub_6CE790 -> sub_6CD990 / sub_6CEA40: build the best planned
    // building whose type has a bit of `mask`; its site, or null.
    BuildingSite* PlanBuilding(uint32_t mask);
    // v1.0 sub_6CEA80: start this planned building (vslot 321, then its site,
    // vslot 309, joins the town). The site, or nullptr.
    BuildingSite* StartPlanned(PlannedMultiMapFixed* planned);
    // v1.0 sub_6D1750: the forests within TownInfo +356 of the store (or the
    // town) that hold wood, from the global list.
    void CollectForests(const std::vector<Forest*>& all);
    // v1.0 sub_6D1860: the nearest of them to pos, within TownInfo +356.
    Forest* NearestForest(const MapCoords& pos);
    void Construct(const MapCoords& pos, const void* town_info, GPlayer* player,
                   uint8_t player_number, TRIBE_TYPE tribe, const char* name, uint32_t id);
    void ProcessTownEmergency();                                                    // 0x007477a0
    bool IsInStateOfEmergency();                                                    // 0x00747970
    void SetInStateOfEmergency();                                                   // 0x007479a0
    bool32_t GetBestRepairBuildingSite();                                            // 0x00747ea0
    bool32_t DisplayHowImpressed();                                                  // 0x007635d0

    // === Fields ===
    StoragePit*                    storage_pit_list;        // 0x30
    TownDesire                     desire;                  // 0x34   (0x564 bytes)
    uint8_t                        field_0x598[0x18];       // 0x598
    char*                          field_0x5b0;             // 0x5B0
    uint32_t                       field_0x5b4;             // 0x5B4
    TRIBE_TYPE                     tribe_type;              // 0x5B8
    uint8_t                        player_number;           // 0x5BC
    // 3 bytes padding (0x5BD-0x5BF)
    float                          worship_percentage;      // 0x5C0
    uint32_t                       worship_count;           // 0x5C4
    float                          influence;               // 0x5C8
    int                            field_0x5cc;             // 0x5CC
    uint32_t                       field_0x5d0;             // 0x5D0
    uint32_t                       field_0x5d4;             // 0x5D4
    float                          belief_in_neutral_player;// 0x5D8
    float                          field_0x5dc;             // 0x5DC
    uint32_t                       field_0x5e0;             // 0x5E0
    uint32_t                       field_0x5e4;             // 0x5E4
    uint32_t                       field_0x5e8;             // 0x5E8
    uint32_t                       field_0x5ec;             // 0x5EC
    uint32_t                       field_0x5f0;             // 0x5F0
    uint32_t                       field_0x5f4;             // 0x5F4
    uint32_t                       field_0x5f8;             // 0x5F8
    uint32_t                       field_0x5fc;             // 0x5FC
    LHNodeList                     forests;                 // 0x600 — sub_6D1750 / sub_6D4400
    TownStats                      stats;                   // 0x608  (0x118 bytes)
    MapCoords                      field_0x728;             // 0x720
    MapCoords                      field_0x734;             // 0x72C
    uint32_t                       field_0x740;             // 0x738
    Creche*                        creche;                  // 0x73C
    uint32_t                       field_0x748;             // 0x740
    Abode*                         abode_0x74c;             // 0x744
    uint32_t                       field_0x750;             // 0x748
    LHListHead_Abode               abode_list;              // 0x74C
    Town*                          next;                    // 0x754
    uint32_t                       field_0x760;             // 0x758
    uint32_t                       field_0x764;             // 0x75C
    LHLinkedList_HomelessVillager  homeless_list;            // 0x760
    uint32_t                       field_0x770;             // 0x768
    uint32_t                       field_0x774;             // 0x76C
    LHListHead_TownSpellIcon       spell_icon_list;         // 0x770
    LHNodeList                     field_list;               // 0x778 (Field ctor sub_4FEB10)
    LHNodeList                     fish_farms;               // 0x780 (FishFarm ctor sub_502970)
    LHNodeList                     building_site_list;       // 0x788 — sub_6CEAF0
    GBelief                        belief;                   // 0x790  (0x1D0 bytes)
    uint32_t                       field_0x968;             // 0x960
    uint32_t                       field_0x96c;             // 0x964
    uint32_t                       field_0x970;             // 0x968
    uint32_t                       field_0x974;             // 0x96C
    uint32_t                       field_0x978;             // 0x970
    LHLinkedList_Playthings        playthings;               // 0x974
    uint32_t                       field_0x984;             // 0x97C
    uint32_t                       field_0x988;             // 0x980
    uint32_t                       field_0x98c;             // 0x984
    uint32_t                       field_0x990;             // 0x988
    LHLinkedList_TownArtifactList  artifacts;                // 0x98C
    uint32_t                       field_0x99c;             // 0x994
    uint32_t                       field_0x9a0;             // 0x998
    TownCentre*                    town_centre;             // 0x99C
    LHListHead_PlannedMMF          planned_list;             // 0x9A0
    TownDesireFlags*               town_desire_flags[17];   // 0x9A8  (TOWN_DESIRE_INFO_LAST)
    PlayerTownInteract             player_interactions[8];  // 0x9F4  (8 player slots)
    uint32_t                       field_0x9f4;             // 0xDF4 (v1.41 kept these two before the array)
    uint32_t                       field_0x9f8;             // 0xDF8
    int                            magic_remainder[42];     // 0xDF4  (MAGIC_TYPE_LAST_142)
    uint32_t                       field_0xea4;             // 0xE9C
    uint32_t                       field_0xea8;             // 0xEA0
    uint32_t                       field_0xeac;             // 0xEA4
    uint32_t                       field_0xeb0;             // 0xEA8
    float                          field_0xeb4;             // 0xEAC
    float                          field_0xeb8;             // 0xEB0
    uint32_t                       field_0xebc;             // 0xEB4
    uint32_t                       field_0xec0;             // 0xEB8
    uint32_t                       field_0xec4;             // 0xEBC
    void*                          field_0xec8[16];         // 0xEC0
    uint32_t                       field_0xf08;             // 0xF00
    uint32_t                       field_0xf0c;             // 0xF04
    MapCoords                      congregation_pos;        // 0xF08
    uint32_t                       field_0xf1c;             // 0xF14
    uint32_t                       field_0xf20;             // 0xF18
    uint32_t                       field_0xf24;             // 0xF1C
};
#if defined(__clang__)
#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Winvalid-offsetof"  // single inheritance: offsetof is exact here
#endif
static_assert(sizeof(Town) == 0xF20, "Town size mismatch (v1.0 allocates 3872)");
// Offsets the v1.0 constructor (sub_6CD070 and its helpers) and the level loader
// write; each one pins the layout (docs/constructors.md).
static_assert(offsetof(Town, field_0x5b0) == 0x5B0, "town name (this[364])");
static_assert(offsetof(Town, field_0x5b4) == 0x5B4, "town id (this[365])");
static_assert(offsetof(Town, tribe_type) == 0x5B8, "tribe (this[366])");
static_assert(offsetof(Town, player_number) == 0x5BC, "player number (byte 1468)");
static_assert(offsetof(Town, influence) == 0x5C8, "this[370] = sub_6D2810");
static_assert(offsetof(Town, field_0x5f4) == 0x5F4, "uninhabitable (SET_TOWN_UNINHABITABLE)");
static_assert(offsetof(Town, stats) == 0x608, "TownStats vftable at this[386]");
static_assert(offsetof(Town, field_0x728) == 0x720, "bounding box min (this[456])");
static_assert(offsetof(Town, field_0x734) == 0x72C, "bounding box max (this[459])");
static_assert(offsetof(Town, abode_list) == 0x74C, "abode list head (this[467])");
static_assert(offsetof(Town, next) == 0x754, "next town in the player's list (this[469])");
static_assert(offsetof(Town, belief) == 0x790, "GBelief vftable at this[484]");
static_assert(offsetof(Town, town_centre) == 0x99C, "town centre (CREATE_TOWN_CENTRE, +2460)");
static_assert(offsetof(Town, town_desire_flags) == 0x9A8, "desire objects (this[618..634])");
static_assert(offsetof(Town, player_interactions) == 0x9EC, "8 x 128-byte records (this[635])");
static_assert(offsetof(Town, field_0xeb4) == 0xEAC, "1.0f (this[939])");
static_assert(offsetof(Town, field_0xec8) == 0xEC0, "16-dword block (this[944])");
static_assert(offsetof(Town, congregation_pos) == 0xF08, "SET_TOWN_CONGREGATION_POS (+3848)");

// v1.0 sub_6D11E0 (BUILD_BUILDING): in every town of every player, start the
// planned building nearest `at` (sub_6D1140), its site's priority (+0x63C)
// set to `priority`. The site, or nullptr when no plan is near.
BuildingSite* BuildPlannedAt(const MapCoords& at, float priority);
#if defined(__clang__)
#pragma clang diagnostic pop
#endif
