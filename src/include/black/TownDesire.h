#pragma once
// TownDesire — manages the set of desires/needs for a town
// Struct layout from bw1-decomp
//
// Size: 0x564 bytes (inherits 0x8 from Base)
// Vtable: BaseVftable (inherits Base's 7 virtual methods, overrides destructor)
//
// Contains 17 desire slots (TOWN_DESIRE_INFO_LAST = 17), each with
// multiple parallel arrays for tracking desire values, sorts, etc.
// Embedded directly inside Town struct.

#include "Base.h"

// Forward declarations
struct GTownDesireInfo;
struct Town;

// Forward-declare enum
enum TOWN_DESIRE_INFO : uint32_t;

// Inner helper: 8-byte per-desire state block
struct TownDesire_FieldEntry {
    uint8_t data[8];  // 0x00
};
static_assert(sizeof(TownDesire_FieldEntry) == 0x8, "TownDesire_FieldEntry size mismatch");

// Desire sort entry used for ordering desires by priority
struct DesireSort {
    uint32_t          field_0x0;  // 0x00
    float             field_0x4;  // 0x04
    TOWN_DESIRE_INFO  field_0x8;  // 0x08
};
static_assert(sizeof(DesireSort) == 0xC, "DesireSort size mismatch");

struct TownDesire : public Base {
    // === Override of Base virtuals ===
    ~TownDesire() override;  // 0x00745730

    // === Non-virtual methods ===
    void Process();                                       // 0x00745ae0
    GTownDesireInfo* GetInfo(uint32_t index) const;       // 0x00745f80

    // === Fields ===
    // TOWN_DESIRE_INFO_LAST = 17
    // Names from v1.0's own desire dump (sub_6D7630), which labels each array.
    TownDesire_FieldEntry field_0x8[17];     // 0x08
    float       cheat[17];                   // 0x90  "DesireCheat"
    float       boost[17];                   // 0xD4  "DesireBoost"
    float       desire[17];                  // 0x118 "Desire": raw x multiplier, in [-1, 1]
    uint32_t    field_0x15c;                 // 0x15C
    Town*       town;                        // 0x160
    float       free_villagers;              // 0x164 adults + children - (+0x5CC) - worshippers
    float       raw[17];                     // 0x168 "RawDesire": function x tribe weight
    float       count_a[17];                 // 0x1AC have (table +32), stored as float
    float       count_b[17];                 // 0x1F0 want (table +48), stored as float
    uint32_t    field_0x234[17];             // 0x234
    DesireSort  sorts[17];                   // 0x278 by desire + boost + cheat, descending
    DesireSort  sorts2[17];                  // 0x344 by raw + boost + cheat, descending
    uint32_t    field_0x410[17];             // 0x410
    float       prev_state_amount[17];       // 0x454
    uint32_t    prev_state_count[17];        // 0x498
    float       state_amount[17];            // 0x4DC "VillagerStateAmount": villagers on it
    uint32_t    state_count[17];             // 0x520 "VillagerStateCount"
};
static_assert(sizeof(TownDesire) == 0x564, "TownDesire size mismatch");
