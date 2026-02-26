#pragma once
// Abode — residential building (houses villagers)
// Struct layout from bw1-decomp
//
// Size: 0xC4 bytes (inherits 0x7C from MultiMapFixed)
// Vtable: 0x92C bytes (extends MultiMapFixed's 0x90C with 8 new methods)
//
// Abode is the residential building class. It houses villagers, manages
// food/wood resources, and provides the base for all housing types
// (huts, villas, temples, civic buildings, etc.)

#include "MultiMapFixed.h"

// Forward declarations
struct GAbodeInfo;
struct GTribeInfo;
struct LH3DSmoke;

// Linked list head for Villager list (Lionhead's LHListHead<Villager>)
struct LHListHead {
    void*    head;   // 0x0 — first node
    uint32_t count;  // 0x4 — number of nodes
};
static_assert(sizeof(LHListHead) == 0x8, "LHListHead size mismatch");

struct Abode : public MultiMapFixed {
    // === Overrides of Base virtuals ===
    void Delete(int param) override;
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    GPlayer* GetPlayer() override;
    Town* GetTown() override;
    uint32_t JustAddResource(RESOURCE_TYPE type, uint32_t amount, bool param3) override;
    uint32_t JustRemoveResource(RESOURCE_TYPE type, uint32_t amount, bool* param3) override;
    uint32_t GetResource(RESOURCE_TYPE type) override;
    uint32_t AddResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool param4, const MapCoords& coords, int param6) override;
    uint32_t RemoveResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool* param4) override;
    Abode* CastAbode() override;
    uint16_t GetNumberOfInstanceForGlobalList() override;
    bool IsFunctional() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    MapCoords* GetArrivePos(MapCoords* out) override;
    uint32_t GetCreatureBeliefType() override;
    uint32_t GetOrigin() override;
    bool IsInteractable() override;
    bool32_t IsCastShadowAtNight() override;
    bool32_t IsAbode() override;
    bool32_t CanBeStompedOnByCreature(Creature* creature) override;
    bool32_t CanBeKickedByCreature(Creature* creature) override;
    uint32_t GetCreatureMimicType() override;
    float GetHowMuchCreatureWantsToLookAtMe() override;
    void CalculateWhereIWillBeAfterNSeconds(float seconds, LHPoint* outPos) override;
    bool32_t IsHouse() override;
    bool32_t IsWonder() override;
    uint32_t GetScriptObjectType() override;

    // === Overrides of Object virtuals ===
    void DestroyedByBeam() override;
    void InsertMapObject() override;
    bool GetPSysFireLocalRndFlamePos(LHPoint* point, int* param2) override;
    void ReduceLife(float value, GPlayer* player) override;
    void IncreaseLife(float value) override;
    uint32_t DestroyedByEffect(GPlayer* player, float param2) override;
    uint32_t Process() override;
    int GetMesh() const override;
    void Draw() override;
    uint32_t GetDiscipleStateIfInteractedWith(GInterfaceStatus* status, Villager* villager) override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    uint32_t InterfaceValidToTap(GInterfaceStatus* status) override;
    uint32_t InterfaceTap(GInterfaceStatus* status) override;
    uint32_t GetPhysicsConstantsType() override;
    void SetUpPhysOb(PhysOb* param1) override;
    uint32_t ChecksVerticesVObjects() override;
    void ReactToPhysicsImpact(PhysicsObject* param1, bool param2) override;
    bool CanBecomeAPhysicsObject() override;
    bool GetInspectObjectPos(Villager* param1, MapCoords* pos) override;
    void DiscipleInHandNear(Villager* param1, GInterfaceStatus* status) override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;
    bool ShouldFootpathsGoRound() override;

    // === Overrides of MultiMapFixed virtuals ===
    float GetInfluence() override;
    bool IsRepaired() override;
    bool IsBuilt() override;
    float GetPercentRepairedForNonFunctional() override;
    float GetPercentAbodeFullWithAdults() override;
    float GetPercentAbodeFullWithChildren() override;
    bool Built() override;
    bool Repaired() override;
    LH3DMesh* GetDestructionMesh() override;
    void RemoveDamage() override;
    bool IsCivic() override;
    ABODE_TYPE GetAbodeType() override;
    float GetDesireToBeRepaired() override;
    uint32_t DoResourceAdding(RESOURCE_TYPE type, GInterfaceStatus* iface, bool param3, MapCoords* param4, int param5) override;
    uint32_t DoResourceRemoving(RESOURCE_TYPE type, uint32_t param2, GInterfaceStatus* iface, bool param4) override;
    void SetTown(Town* town) override;
    bool GetShouldNotBeAddedToPlanned() override;
    void SetShouldNotBeAddedToPlanned(bool value) override;
    PlannedMultiMapFixed* ConvertToPlanned() override;

    // === New virtual methods (vtable 0x90C-0x928) ===
    virtual void MoveAbodeToPlannedAbodes();
    virtual void DeleteDependancys();
    virtual void MakeFunctional();
    virtual void StopBeingFunctional(GPlayer* param1);
    virtual void RestartBeingFunctional();
    virtual bool CausesTownEmergencyIfDamaged();
    virtual bool CanBeHiddenIn();
    virtual GTribeInfo* GetTribe();

    // === Fields ===
    uint32_t        field_0x7c;              // 0x7C — bitfield byte (bit 2 = ShouldNotBeAddedToPlanned)
    MapCoords       drinking_water;          // 0x80
    LH3DSmoke*      smoke;                   // 0x8C
    LH3DMesh*       destruction_mesh;        // 0x90
    uint32_t        field_0x94;              // 0x94
    Town*           town;                    // 0x98
    Abode*          next;                    // 0x9C — linked list next
    LHListHead      villagers;               // 0xA0 — villager linked list
    Villager*       male_female_villagers[2]; // 0xA8 — [0]=male, [1]=female
    uint32_t        field_0xb0;              // 0xB0
    uint8_t         adult_count;             // 0xB4
    uint8_t         field_0xb5;              // 0xB5
    uint8_t         field_0xb6;              // 0xB6
    uint8_t         field_0xb7;              // 0xB7
    uint8_t         index;                   // 0xB8
    uint8_t         field_0xb9;              // 0xB9
    // 2 bytes padding (0xBA-0xBB)
    uint32_t        resources[2];            // 0xBC — [0]=food, [1]=wood (RESOURCE_TYPE_LAST=2)
};
static_assert(sizeof(Abode) == 0xC4, "Abode size mismatch");
