#pragma once
// LandscapeVortex — vortex/whirlwind entities
// Struct layout from bw1-decomp
//
// LandscapeVortex: 0xEC bytes (MobileStatic subclass)
// Has custom vtable extending MultiMapFixed's with 3 new methods.
// Subclasses: LandscapeVortexIn, LandscapeVortexOut, LandscapeVortexVolc

#include "MobileStatic.h"

// Forward declarations
struct Flock;

// Vortex type enum
enum VORTEX_TYPE : uint32_t {
    VORTEX_TYPE_IN = 0,
    VORTEX_TYPE_OUT = 1,
    VORTEX_TYPE_VOLC = 2,
};

struct LandscapeVortex : public MobileStatic {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;

    // === Overrides of GameThingWithPos virtuals ===
    void PhysicsEditorCreate(int param1) override;
    bool32_t CanBePickedUpByCreature(Creature* creature) override;
    bool32_t CanBeSetOnFire(Creature* creature) override;
    bool32_t CanBeStompedOnByCreature(Creature* creature) override;
    bool32_t CanBeThrownByCreature(Creature* creature) override;
    bool32_t CanBePutInAStoragePit(Creature* creature) override;
    bool32_t CanBeDestroyedByStoning(Creature* creature) override;
    bool32_t CanBeStonedAndEatenByCreature(Creature* creature) override;
    bool32_t CanBeExaminedByCreature(Creature* creature) override;
    bool32_t CanBeFoughtByCreature(Creature* creature) override;
    bool32_t CanActAsAContainer(Creature* creature) override;
    uint32_t GetScriptObjectType() override;

    // === Overrides of Object virtuals ===
    void Create3DObject() override;
    bool32_t HandShouldFeelWithMeshIntersect() override;
    int GetMesh() const override;
    void Draw() override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    bool32_t ValidForPlaceInHand(GInterfaceStatus* status) override;
    bool32_t IsEffectReceiver(EffectValues* param1) override;
    bool InteractsWithPhysicsObjects() override;
    bool CanBecomeAPhysicsObject() override;

    // === New virtual methods (extending MultiMapFixed vtable) ===
    virtual void ProcessContentsOfVortex();
    virtual void SetFlockParams(const MapCoords* coords, float param2, float param3, Flock* flock);
    virtual bool IsVillagerBeingThrownByThisVortex(Villager* villager);

    // === Fields ===
    LandscapeVortex* next;       // 0x88
    float       field_0x8c;      // 0x8C
    float       field_0x90;      // 0x90
    uint32_t    field_0x94;      // 0x94
    uint32_t    field_0x98;      // 0x98
    uint32_t    field_0x9c;      // 0x9C
    uint32_t    field_0xa0;      // 0xA0
    uint32_t    field_0xa4;      // 0xA4
    uint32_t    field_0xa8;      // 0xA8
    uint32_t    field_0xac;      // 0xAC
    uint32_t    field_0xb0;      // 0xB0
    uint32_t    field_0xb4;      // 0xB4
    uint8_t     field_0xb8;      // 0xB8
    // 3 bytes padding
    uint32_t    field_0xbc;      // 0xBC
    uint32_t    field_0xc0;      // 0xC0
    uint32_t    field_0xc4;      // 0xC4
    uint32_t    field_0xc8;      // 0xC8
    uint32_t    field_0xcc;      // 0xCC
    uint32_t    field_0xd0;      // 0xD0
    uint32_t    field_0xd4;      // 0xD4
    uint32_t    field_0xd8;      // 0xD8
    uint32_t    field_0xdc;      // 0xDC
    VORTEX_TYPE type;            // 0xE0
    uint32_t    field_0xe4;      // 0xE4
    float       field_0xe8;      // 0xE8
};
static_assert(sizeof(LandscapeVortex) == 0xEC, "LandscapeVortex size mismatch");

// ============================================================================
// LandscapeVortexIn — incoming vortex (sucks things in)
// ============================================================================

struct LandscapeVortexIn : public LandscapeVortex {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of Object virtuals ===
    uint32_t GetPhysicsConstantsType() override;
    bool InteractsWithPhysicsObjects() override;
    void ShouldPhysicsRaiseObjectUntilNotIntersectingThis(Object* param1) override;
    void ReactToPhysicsImpact(PhysicsObject* param1, bool param2) override;
    bool CreatureMustAvoid(Creature* param1) override;
};
static_assert(sizeof(LandscapeVortexIn) == 0xEC, "LandscapeVortexIn size mismatch");

// ============================================================================
// LandscapeVortexOut — outgoing vortex (pushes things out)
// ============================================================================

struct LandscapeVortexOut : public LandscapeVortex {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of MultiMapFixed virtuals ===
    void SetTown(Town* town) override;
};
static_assert(sizeof(LandscapeVortexOut) == 0xEC, "LandscapeVortexOut size mismatch");

// ============================================================================
// LandscapeVortexVolc — volcanic vortex
// ============================================================================

struct LandscapeVortexVolc : public LandscapeVortex {
    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(LandscapeVortexVolc) == 0xEC, "LandscapeVortexVolc size mismatch");
