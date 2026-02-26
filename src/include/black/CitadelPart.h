#pragma once
// CitadelPart — citadel building component
// Struct layout from bw1-decomp
//
// Size: 0x8C bytes (inherits 0x7C from MultiMapFixed)

#include "MultiMapFixed.h"

// Forward declarations
struct Citadel;
struct CitadelPart;
struct PlannedMultiMapFixed;

struct CitadelPart : public MultiMapFixed {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    GPlayer* GetPlayer() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    uint32_t GetCreatureBeliefType() override;
    Citadel* GetCitadel() override;
    bool32_t IsCitadelPart_0() override;
    bool32_t IsCitadelPart_1(Creature* creature) override;

    // === Overrides of Object virtuals ===
    void* GetActualObjectToEffect(GPlayer* player, bool param2) override;
    uint32_t DestroyedByEffect(GPlayer* player, float param2) override;
    uint32_t Process() override;
    int GetMesh() const override;
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;
    LH3DObject_ObjectType Get3DType() override;
    bool32_t CanBeDestroyedBySpell_1(Spell* param1) override;
    void ReactToPhysicsImpact(PhysicsObject* param1, bool param2) override;
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;
    bool ShouldFootpathsGoRound() override;

    // === Overrides of MultiMapFixed virtuals ===
    bool IsRepaired() override;
    bool IsBuilt() override;
    PlannedMultiMapFixed* ConvertToPlanned() override;

    // === Fields ===
    float          field_0x7c;        // 0x7C
    Citadel*       citadel;           // 0x80
    CitadelPart*   next;              // 0x84
    GameThing*     game_thing_0x88;   // 0x88
};
static_assert(sizeof(CitadelPart) == 0x8C, "CitadelPart size mismatch");
