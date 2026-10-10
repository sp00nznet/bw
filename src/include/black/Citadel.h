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
    WorshipSite* FindOrCreateWorshipSite(const GTribeInfo* tribe_info);  // sub_44EAD0
    WorshipSite* FindWorshipSite(const GTribeInfo* tribe_info);          // sub_44EA50
    WorshipSite* CreateWorshipSite(const GTribeInfo* tribe_info);        // sub_44EBE0
    // v1.0 sub_44EA80: the worship site for the town's tribe, made if need be;
    // nullptr if the town cannot worship or the citadel's worship is off (+0x74).
    WorshipSite* WorshipSiteFor(Town* town);
    // v1.0 sub_44F720: its influence radius, the players' multiplier x +0x6C.
    float Power() const;
    // v1.0 sub_44EFB0: each worship site's turn (from sub_5F8410, once a
    // turn for every player's citadel).
    void ProcessWorship();

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

struct GObjectInfo;
// sub_44E400: Container (sub_456870: position, info, player), then the
// player's citadel (+608). ponytail: sub_44E610 and the 8-byte list at +124
// are not translated.
Citadel* NewCitadel(GPlayer* player, const MapCoords& at);
// sub_450280 -> sub_44FED0: a heart at `at`, `built` of the way up; the
// citadel's heart if it has none, the citadel's power raised by built x info
// +284; built >= 1 starts the worship sites (sub_450320).
struct CitadelHeart* NewCitadelHeart(const MapCoords& at, GObjectInfo* info, Citadel* citadel,
                                     float angle, float scale, float built, GameThing* town);
// sub_44EAF0 (CREATE_CITADEL): the player's new citadel and its finished heart.
// sub_4504D0 (CREATE_WORSHIP_SITE): the citadel's site for the tribe, given the
// player's town of that tribe and finished.
