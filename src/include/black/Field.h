#pragma once
// Field — agricultural field for growing crops
// Struct layout from bw1-decomp
//
// Size: 0x124 bytes (inherits 0xC4 from Abode)
// Vtable: same as MultiMapFixed (0x92C bytes)
//
// Field is the largest Abode subclass. Manages crop planting,
// growth, harvesting, and food production. Supports creature
// interactions (eating, stomping, watering, poo fertilizing).

#include "Abode.h"

// Forward declarations
struct ControlHandUpdateInfo;
struct EffectValues;
struct GFieldTypeInfo;
struct Spell;
struct SpellWater;

struct Field : public Abode {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    GPlayer* GetPlayer() override;
    Town* GetTown() override;
    float Get2DRadius() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    MapCoords* GetArrivePos(MapCoords* out) override;
    uint32_t GetCreatureBeliefType() override;
    uint32_t GetOverwriteInteractableToolTip() override;
    bool32_t IsField_1(Creature* creature) override;
    bool32_t IsField_0() override;
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
    bool32_t IsFieldWhichNeedsWatering(Creature* creature) override;
    bool32_t IsFieldWithFoodInIt(Creature* creature) override;
    bool32_t IsFieldBelongingToAnotherPlayer(Creature* creature) override;
    bool32_t BenefitsFromHavingWaterSprinkledOnIt(Creature* creature) override;

    // === Overrides of Object virtuals ===
    float GetMeshRadius() const override;
    void ReduceLife(float value, GPlayer* player) override;
    void ReduceLifeDueToBurning(float value, GPlayer* player) override;
    void GetFireGPHXDrawn(bool* p1, bool* p2, bool* p3, bool* p4) override;
    uint32_t DestroyedByEffect(GPlayer* player, float param) override;
    uint32_t Process() override;
    void Draw() override;
    uint32_t GetDiscipleStateIfInteractedWith(GInterfaceStatus* status,
                                               Villager* villager) override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    float ApplyWaterSpell(SpellWater* spell) override;
    RESOURCE_TYPE GetResourceType() override;
    bool IsLockedInInteract() override;
    bool IsTouching_2(MapCoords* coords) const override;
    bool32_t ValidForLockedSelectProcess(GInterfaceStatus* status) override;
    bool32_t NetworkFriendlyStartLockedSelect(GInterfaceStatus* status) override;
    uint32_t NetworkUnfriendlyLockedSelect(ControlHandUpdateInfo* param) override;
    uint32_t NetworkUnfriendlyEndLockedSelect() override;
    uint32_t NetworkFriendlyEndLockedSelect(GInterfaceStatus* status) override;
    uint32_t ValidForPlaceInHand(GInterfaceStatus* status) override;
    uint32_t InterfaceSetInMagicHand(GInterfaceStatus* status) override;
    uint32_t IsTuggable() override;
    uint32_t IsEffectReceiver(EffectValues* param) override;
    bool32_t CanBeDestroyedBySpell_1(Spell* spell) override;
    bool InteractsWithPhysicsObjects() override;
    bool CanBecomeAPhysicsObject() override;
    bool CreatureMustAvoid(Creature* creature) override;
    uint32_t ProcessInInteract(GInterfaceStatus* status) override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;

    // === Overrides of MultiMapFixed virtuals ===
    MapCoords* GetDoorPos(MapCoords* pos) override;

    // === Non-virtual methods ===
    bool32_t PlantCrop(const MapCoords& pos);
    bool32_t GetPlantCropPos();
    int GetFieldActivity(int param);
    float GetPercentFull();
    float RemoveFood(float amount);
    float GetFoodValue();

    // === Fields ===
    Field*          next;            // 0xC4
    uint32_t        field_0xc8;
    uint8_t         field_0xcc;
    uint32_t        field_0xd0;
    uint32_t        field_0xd4;
    uint32_t        field_0xd8;
    uint32_t        field_0xdc;
    uint32_t        field_0xe0;
    float           field_0xe4;
    float           field_0xe8;
    float           field_0xec;
    uint32_t        field_0xf0;
    uint32_t        field_0xf4;
    uint32_t        field_0xf8;
    uint32_t        field_0xfc;
    uint32_t        field_0x100;
    float           field_0x104;
    uint32_t        field_0x108;
    uint32_t        field_0x10c;
    uint32_t        field_0x110;
    uint32_t        field_0x114;
    Town*           town;            // 0x118
    int             field_0x11c;
    GFieldTypeInfo* type_info;       // 0x120
};
static_assert(sizeof(Field) == 0x124, "Field size mismatch");
