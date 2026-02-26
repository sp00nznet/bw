#pragma once
// Citadel — player's main stronghold with worship sites
// Struct layout from bw1-decomp
//
// Size: 0x80 bytes (inherits 0x30 from Container)
// Vtable: 0x500 bytes (same as Container — no new vtable slots)
//
// Citadel is the divine HQ. It holds a heart, worship sites (one
// per tribe), a ring of CitadelParts, and a living creature link.

#include "Container.h"

// Forward declarations
struct CitadelHeart;
struct GTribeInfo;
struct Living;
struct Town;
struct WorshipSite;

struct Citadel : public Container {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;

    // === Overrides of GameThing virtuals ===
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;

    // === Overrides of GameThingWithPos virtuals ===
    uint32_t GetCreatureBeliefType() override;
    uint32_t GetCreatureBeliefListType() override;
    uint32_t GetOrigin() override;
    bool IsActivityObjectWhichAngerAppliesTo(Creature* creature) override;
    bool32_t IsSuitableForCreatureActivity() override;
    float GetHowMuchCreatureWantsToLookAtMe() override;
    const char* GetText() override;
    bool32_t IsCitadel() override;

    // === Non-virtual methods ===
    void* AddTown(Town* town);
    WorshipSite* FindOrCreateWorshipSite(const GTribeInfo* tribe_info);

    // === Fields ===
    CitadelHeart*  heart;             // 0x30
    WorshipSite*   worship_sites[6];  // 0x34
    uint32_t       part_list[2];      // 0x4C — LHListHead<CitadelPart>
    uint32_t       field_0x54;
    uint32_t       field_0x58;
    uint32_t       field_0x5c;
    uint32_t       field_0x60;
    uint32_t       field_0x64;
    uint32_t       field_0x68;
    float          influence;         // 0x6C
    uint32_t       field_0x70;
    uint32_t       field_0x74;
    uint32_t       field_0x78;
    Living*        living;            // 0x7C
};
static_assert(sizeof(Citadel) == 0x80, "Citadel size mismatch");
