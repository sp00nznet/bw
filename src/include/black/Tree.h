#pragma once
// Tree — tree entity in the game world
// Struct layout from bw1-decomp
//
// Size: 0x6C bytes (inherits 0x5C from SingleMapFixed)
// Vtable: 0x874 bytes (extends SingleMapFixed's 0x868 with 3 methods)
//
// Trees are fixed map objects that belong to Forests, provide wood,
// and can catch fire. Override list from bw1-decomp's Tree.h.

#include "SingleMapFixed.h"

// Forward declarations
struct Forest;
struct GTreeInfo;
struct SpellWater;

struct Tree : public SingleMapFixed {
    // === Overrides of GameThing virtuals ===
    // CastTree: returns this (GameThing default returns nullptr)
    // GetPlayer, GetComputerSeen, GetDebugText, GetSaveType: tree-specific

    // === Overrides of GameThingWithPos virtuals ===
    uint32_t GetCreatureBeliefType() override;
    bool32_t IsCastShadowAtNight() override;
    bool32_t CanBeAttackedByCreature(Creature*) override;
    bool32_t CanBePlayedWithByCreature(Creature*) override;
    bool32_t CanBePickedUpByCreature(Creature*) override;
    bool32_t CanBeDestroyedByStoning(Creature*) override;
    bool32_t CanBeUsedForBuilding(Creature*) override;
    bool32_t CanBeUsedForRepair(Creature*) override;
    bool32_t BenefitsFromHavingWaterSprinkledOnIt(Creature*) override;
    bool32_t IsTree_1() override;
    bool32_t IsTree_0(Creature*) override;
    bool32_t IsAnyKindOfTree() override;
    bool32_t CanBeThrownInTheSeaPlayfully(Creature*) override;
    uint32_t GetCreatureMimicType() override;
    float GetReactionPower() override;

    // === Overrides of Object virtuals ===
    bool BlocksTownClearArea() const override;
    HOLD_TYPE GetHoldType() override;
    float GetHoldRadius() override;
    float GetHoldLoweringMultiplier() override;
    bool32_t HandShouldFeelWithMeshIntersect() override;
    int GetMesh() const override;
    bool CanBePickedUp() override;
    float GetVillagerHugRadius() override;
    float GetWoodValue() override;
    bool IsResourceStore(RESOURCE_TYPE type) override;
    RESOURCE_TYPE GetResourceType() override;
    int GetDefaultResource() override;
    float ApplyWaterSpell(SpellWater* spell) override;
    bool CanBecomeAPhysicsObject() override;
    bool InteractsWithPhysicsObjects() override;
    bool CreatureMustAvoid(Creature*) override;
    bool IsARootedObject() override;
    uint32_t GetCarriedTreeType() override;

    // === New virtual methods (vtable 0x868-0x870) ===
    virtual float GetWoodValueMultiplier();
    virtual Forest* GetForest();
    virtual void SetOnFire(float param1);

    // === Fields ===
    uint32_t field_0x5c;  // 0x5C
    int16_t  field_0x60;  // 0x60
    uint16_t pad_0x62;    // 0x62
    float    field_0x64;  // 0x64
    Forest*  forest;      // 0x68 — owning forest
};
static_assert(sizeof(Tree) == 0x6C, "Tree size mismatch");
