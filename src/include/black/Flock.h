#pragma once
// Flock — group of living creatures moving together
// Struct layout from bw1-decomp
//
// Size: 0x90 bytes (inherits 0x30 from Container)
// Vtable: 0x500 bytes (same as Container — no new vtable slots)
//
// Flock manages a group of animals (members list + leader) around
// a domain centre. Used for herds, bird flocks, etc.

#include "Container.h"

// Forward declarations
struct CitadelHeart;
struct LivingDLList;

struct Flock : public Container {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    Town* GetTown() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    uint32_t GetCreatureBeliefType() override;
    uint32_t GetCreatureBeliefListType() override;
    bool IsActivityObjectWhichAngerAppliesTo(Creature* creature) override;
    bool IsActivityObjectWhichCompassionAppliesTo(Creature* creature) override;
    bool IsActivityObjectWhichPlayfulnessAppliesTo(Creature* creature) override;
    bool32_t IsSuitableForCreatureActivity() override;
    bool32_t IsFlock() const override;
    bool32_t IsScriptContainer() const override;
    const char* GetText() override;
    uint32_t GetScriptObjectType() override;

    // === Non-virtual methods ===
    void SetDomainCentrePos(const MapCoords& pos);
    MapCoords* GetFlockPos();

    // === Fields ===
    uint32_t       field_0x30;
    uint32_t       field_0x34;
    CitadelHeart*  citadel_heart;     // 0x38
    LivingDLList*  members;           // 0x3C
    LivingDLList*  leader;            // 0x40
    LivingDLList*  field_0x44;
    int            field_0x48;
    uint32_t       field_0x4c;
    uint16_t       domain_radius;     // 0x50
    uint16_t       field_0x52;
    uint32_t       field_0x54;
    uint32_t       field_0x58;
    uint32_t       field_0x5c;
    MapCoords      field_0x60;        // 0x60
    MapCoords      field_0x6c;        // 0x6C
    uint32_t       field_0x78;
    uint32_t       field_0x7c;
    uint32_t       field_0x80;
    uint32_t       field_0x84;
    uint32_t       field_0x88;
    uint32_t       field_0x8c;
};
static_assert(sizeof(Flock) == 0x90, "Flock size mismatch");
