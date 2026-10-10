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
struct Living;

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
    // sub_5058F0 after the Container part: on the game's flock list, at pos.
    void Init(const MapCoords& pos, uint32_t id);
    void SetDomainCentrePos(const MapCoords& pos);  // sub_505CF0
    MapCoords* GetFlockPos();
    bool AddMember(Living* l);                       // sub_505B20
    bool RemoveMember(Living* l, bool delete_if_empty);  // sub_505C20

    // A member's node (12 bytes, sub_746D70(12)).
    struct Node { Node* next; Node* prev; Living* living; };

    // === Fields ===
    Living*        leader;            // 0x30
    Town*          town;              // 0x34 (CREATE_FLOCK's town, which lists it at +0xF00)
    CitadelHeart*  citadel_heart;     // 0x38
    Node*          head;              // 0x3C: ordered by the member's +0xD4 byte
    Node*          tail;              // 0x40
    Node*          cursor;            // 0x44: the last node linked
    int            count;             // 0x48
    uint32_t       field_0x4c;
    uint16_t       domain_radius;     // 0x50 (80 unless set)
    uint16_t       radius_b;          // 0x52 (30 unless set)
    uint32_t       field_0x54;
    uint32_t       field_0x58;
    uint32_t       field_0x5c;
    MapCoords      start_pos;         // 0x60
    MapCoords      field_0x6c;        // 0x6C (also the start position)
    uint32_t       field_0x78;        // 43 at init
    uint32_t       field_0x7c;
    uint32_t       field_0x80;
    uint32_t       field_0x84;
    uint32_t       max_count;         // 0x88: the most members it has had
    uint32_t       id;                // 0x8C: the level script's flock number
};
static_assert(sizeof(Flock) == 0x90, "Flock size mismatch");
