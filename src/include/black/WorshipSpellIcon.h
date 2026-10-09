#pragma once
// WorshipSpellIcon — spell icon on a worship site totem
// Struct layout from bw1-decomp
//
// Size: 0x140 bytes (inherits 0x110 from SpellIcon)
// Vtable: extends SpellIcon (MultiMapFixedVftable), overrides ~15 methods
//
// Also defines PrayerIcon (SingleMapFixed subclass, 0x5C bytes).

#include "SpellIcon.h"

// Forward declarations
struct EffectValues;
struct GSpellIconInfo;
struct GSpellSeedInfo;
struct PSysProcessInfo;
struct WorshipSite;

struct WorshipSpellIcon : public SpellIcon {
    // === Overrides of Base virtuals ===
    void ToBeDeleted(int param) override;                                    // 0x0077f230

    // === Overrides of GameThing virtuals ===
    void MaintainSpell(uint32_t param1, float param2) override;              // 0x0077f6f0
    void UpdateSpellInfo(Spell* spell, PSysProcessInfo* info) override;      // 0x0077f750
    char* GetDebugText() override;                                           // 0x0077f100
    uint32_t Load(GameOSFile* file) override;                                // 0x007801f0
    uint32_t Save(GameOSFile* file) override;                                // 0x0077ff80
    uint32_t GetSaveType() override;                                         // 0x0077f0f0

    // === Overrides of GameThingWithPos virtuals ===
    WorshipSite* GetWorshipSite() override;                                  // 0x0077f0a0

    // === Overrides of Object virtuals ===
    void ApplyEffect(EffectValues* values, int param) override;              // 0x0077f0e0
    uint32_t Process() override;                                             // 0x0077f390
    void CallVirtualFunctionsForCreation(const MapCoords& coords) override;  // 0x0077f290
    uint32_t IsEffectReceiver(EffectValues* values) override;                // 0x0077f0b0
    size_t SaveObject(LHOSFile* param1, const MapCoords* param2) override;   // 0x0077f0d0

    // === Non-virtual methods ===
    void SetZero();                                                          // 0x0077f1f0
    void UpdateGraphicsWithPULevels();                                       // 0x0077f320
    void StopRemoveFromPlayer();                                             // 0x0077ff40
    int  MagicType() const;               // sub_6BCEB0 -> sub_6C19A0: the seed's magic at this power-up
    float Cost() const;                   // sub_707D40: magic effect info +120
    float Demand() const;                 // sub_708340: cost less the charge
    float AddCharge(float amount);        // sub_7082A0: what does not fit
    bool  CanCharge(GPlayer* who, int powerup, bool need_mana);  // sub_707FB0
    bool  StartCharging(GPlayer* who, int powerup, bool need_mana);  // sub_708040

    // === Static methods ===
    static WorshipSpellIcon* Create(const MapCoords& coords, const GSpellIconInfo* icon_info,
        const GSpellSeedInfo* seed_info, WorshipSite* site, int16_t slot, float param6, int param7);

    // === Fields ===
    WorshipSpellIcon*  next;          // 0x110
    int16_t            field_0x114;   // 0x114
    WorshipSite*       site;          // 0x118
    float              field_0x11c;   // 0x11C
    uint8_t            charging;      // 0x120 — sub_707F00
    uint8_t            pad_0x121[3];
    int32_t            powerup;       // 0x124 — -1 the seed's base magic, else +296 + 4n
    GPlayer*           charger;       // 0x128 — v1.0 the hand charging it; ours its player
    uint32_t           field_0x12c;   // 0x12C
    uint32_t           field_0x130;   // 0x130
    float              charge;        // 0x134 — mana in it
    uint32_t           field_0x138;   // 0x138
    int16_t            slot;          // 0x13C
};
static_assert(sizeof(WorshipSpellIcon) == 0x140, "WorshipSpellIcon size mismatch");
static_assert(offsetof(WorshipSpellIcon, charging) == 0x120 && offsetof(WorshipSpellIcon, charge) == 0x134, "sub_707700");

// v1.0 sub_5F9050: the player's hand asks for a seed. Of the player's worship
// sites holding its icon, the one with the most mana to give charges it
// (sub_5F9180 -> sub_708040). The icon, or nullptr.
WorshipSpellIcon* ChargeSpell(GPlayer* player, int seed);
// The seed a player's hand holds once charged (v1.0: a SpellSeed made in the
// hand, sub_707DF0 -> sub_6BED50, with the icon's charge). seed -1: none.
struct HandSeed { int seed = -1; float charge = 0.0f; };
HandSeed& HeldSeed(GPlayer* player);

// LHListHead<WorshipSpellIcon> — 8-byte linked list head
struct LHListHead_WorshipSpellIcon {
    WorshipSpellIcon* first;  // 0x00
    WorshipSpellIcon* last;   // 0x04
};
static_assert(sizeof(LHListHead_WorshipSpellIcon) == 0x8, "LHListHead_WorshipSpellIcon size mismatch");
