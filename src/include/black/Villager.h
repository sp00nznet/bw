#pragma once
// Villager — human villager entity with needs, jobs, and town membership
// Struct layout from bw1-decomp
//
// Size: 0x130 bytes (inherits 0xE0 from Living)
// Vtable: 0xB48 bytes (extends Living's 0xB40 with 2 methods)

#include "Living.h"

// Forward declarations
struct Abode;
struct BuildingSite;
struct Football;
struct Town;

struct Villager : public Living {
    // === Overrides of inherited virtuals ===
    uint32_t GetCreatureBeliefType() override;
    bool32_t IsABeliever() override;
    bool32_t CanReceiveGifts(Creature*) override;
    bool32_t IsVillager(Creature*) override;
    bool32_t IsMaleVillager() override;
    bool32_t IsFemaleVillager() override;
    bool32_t CanBeEatenByCreature(Creature*) override;
    bool32_t CanBeBefriendedByCreature(Creature*) override;
    bool32_t CanBeStrokedByCreature(Creature*) override;
    bool32_t CanBeKissedByCreature(Creature*) override;
    bool32_t CanBeGivenToTown(Creature*) override;
    bool32_t CanBePutInFoodPile(Creature*) override;
    bool32_t CanBePutInWoodPile(Creature*) override;
    bool32_t CanBeBroughtBackToCitadel(Creature*) override;
    bool32_t CanBeThrownByCreature(Creature*) override;
    bool32_t CanBeGivenToVillager(Creature*) override;
    uint32_t GetScriptObjectType() override;
    bool CanBePickedUp() override;
    uint32_t GetTastiness() override;
    float GetHowMuchCreatureWantsToLookAtMe() override;
    HOLD_TYPE GetHoldType() override;
    float GetHoldLoweringMultiplier() override;
    uint32_t GetPhysicsConstantsType() override;
    int GetMesh() const override;
    int GetDetailMesh(int detail) override;
    bool AmILikelyToMove() override;
    uint32_t ProcessState() override;

    // === New virtual methods (vtable 0xB40-0xB44) ===
    virtual const char* GetVillagerName();
    virtual void DrawVillagerInfo();

    // === Non-virtual methods ===
    Town* GetTown();
    Abode* GetHome();
    void SetHome(Abode* abode);          // v1.0 sub_6E0D10: home, and the home's town
    void BecomeHomeless();               // v1.0 sub_6EFD50: onto its town's homeless list
    // v1.0 sub_6DFC80 (+ Living sub_5AAAE0): the state a new villager starts in.
    void Construct(uint32_t age, bool flag);
    void SetAge(uint32_t age) override;  // v1.0 sub_6E23C0
    bool IsChild() override;             // v1.0 vslot 701 (sub_52E150): +0xE0 bit 3
    uint32_t Sex() const;                // GVillagerInfo +504: 0 male, 1 female
    void SetTown(Town* town);
    bool IsPregnant() const;
    bool IsHomeless() const;
    bool IsCarryingResource() const;
    int16_t GetResourceHeld(RESOURCE_TYPE type) const;
    void AddResourceHeld(RESOURCE_TYPE type, int16_t amount);
    void ClearResourceHeld();
    float GetFood() const;
    void SetFood(float value);
    bool IsFoodSpeedUp() const;

    // === Fields ===
    uint16_t field_0xe0;                    // 0xE0
    uint16_t pad_0xe2;                      // 0xE2
    Villager* next_villager;                // 0xE4 — linked list
    float    food;                          // 0xE8 — food level
    int      last_check_turn;              // 0xEC
    bool     food_speed_up;                // 0xF0
    uint8_t  field_0xf1;                   // 0xF1
    uint8_t  disciple_type;                // 0xF2
    uint8_t  field_0xf3;                   // 0xF3
    int16_t  resource_held[3];             // 0xF4 — food/wood/ore counts
    int16_t  is_pregnant;                  // 0xFA
    int16_t  field_0xfc;                   // 0xFC
    uint16_t pad_0xfe;                     // 0xFE
    BuildingSite* building_site;           // 0x100
    Villager* mother;                      // 0x104
    GPlayer* last_player_to_interact;      // 0x108
    float    field_0x10c;                  // 0x10C
    Object*  target;                       // 0x110 — v1.0 this[68]: the farm or field worked
    uint32_t field_0x114;                  // 0x114
    FireEffect* villager_fire_effect;      // 0x118
    GameThing* target_thing;               // 0x11C
    Abode*   home;                         // 0x120 — v1.0 sub_6E1CE0 returns this[72]
    Town*    town;                         // 0x124 — v1.0 GetTown (vslot 18) returns this[73]
};
static_assert(sizeof(Villager) == 0x128, "Villager size mismatch (v1.0 allocates 296)");
