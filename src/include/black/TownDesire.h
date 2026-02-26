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
    TownDesire_FieldEntry field_0x8[17];     // 0x08
    float       field_0x90[17];              // 0x90
    float       field_0xd4[17];              // 0xD4
    float       field_0x118[17];             // 0x118
    uint32_t    field_0x15c;                 // 0x15C
    Town*       town;                        // 0x160
    float       field_0x164;                 // 0x164
    float       field_0x168[17];             // 0x168
    uint32_t    field_0x1ac[17];             // 0x1AC
    uint32_t    field_0x1f0[17];             // 0x1F0
    uint32_t    field_0x234[17];             // 0x234
    DesireSort  sorts[17];                   // 0x278
    DesireSort  sorts2[17];                  // 0x344
    uint32_t    field_0x410[17];             // 0x410
    float       field_0x454[17];             // 0x454
    uint32_t    field_0x498[17];             // 0x498
    float       field_0x4dc[17];             // 0x4DC
    uint32_t    field_0x520[17];             // 0x520
};
static_assert(sizeof(TownDesire) == 0x564, "TownDesire size mismatch");
