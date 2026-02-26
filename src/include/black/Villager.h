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
    bool CanBePickedUp() override;
    uint32_t GetTastiness() override;

    // === New virtual methods (vtable 0xB40-0xB44) ===
    virtual const char* GetVillagerName();
    virtual void DrawVillagerInfo();

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
    float    field_0x110;                  // 0x110
    uint32_t field_0x114;                  // 0x114
    FireEffect* villager_fire_effect;      // 0x118
    GameThing* target_thing;               // 0x11C
    Football* football;                    // 0x120
    uint32_t field_0x124;                  // 0x124
    uint32_t field_0x128;                  // 0x128
    Abode*   home;                         // 0x12C — home building
};
static_assert(sizeof(Villager) == 0x130, "Villager size mismatch");
