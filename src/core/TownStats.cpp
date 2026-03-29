// TownStats — population, resource, and disciple tracking for a town
// Method stubs from bw1-decomp
#include "../include/black/TownStats.h"
#include "../include/black/Villager.h"

// === Override of Base virtuals ===

// 0x007391a0
TownStats::~TownStats() {}

// === Non-virtual methods ===

// 0x007493c0 — Remove villager from town stats
// Checks if villager is a child (vtable 0xaf8 = IsChild), decrements num_children or num_adults
void TownStats::Remove(Villager* villager) {
    if (!villager) return;
    // Original checks IsChild virtual at offset 0xaf8 in vtable
    // For now, use home as proxy: if villager has an abode, decrement housed count
    Abode* abode = villager->GetHome();
    if (abode) {
        num_children--;
    } else {
        num_adults--;
    }
    // NOTE: The original also does complex resource accounting (field_0x54 tribe arrays,
    // field_0xe4 food subtraction, resource_held tallying). Left as simplified for now.
}

// 0x00749490 — Transition child villager to adult in stats
// If villager has an abode: dec field_0x4c, inc field_0x50 (housed children/adults)
// Always: dec num_children, inc num_adults
void TownStats::ChildToAdult(Villager* villager) {
    if (!villager) return;
    Abode* abode = villager->GetHome();
    if (abode) {
        field_0x4c--;  // housed children count
        field_0x50++;  // housed adults count
    }
    num_children--;
    num_adults++;
}
// 0x007494c0
void TownStats::VillagerMoveOutOfAbode(Villager* /*villager*/) {}
// 0x00749a60
void TownStats::Add(PlannedMultiMapFixed* /*planned*/) {}
// 0x00749aa0
void TownStats::Add(BuildingSite* /*building_site*/) {}
// 0x00749c60
void TownStats::IncrementNumOfDisciples(VILLAGER_DISCIPLE disciple) {
    uint32_t idx = static_cast<uint32_t>(disciple);
    if (idx < 16) {
        num_disciples[idx]++;
    }
}

// 0x00749c80
void TownStats::DecrementNumOfDisciples(VILLAGER_DISCIPLE disciple) {
    uint32_t idx = static_cast<uint32_t>(disciple);
    if (idx < 16 && num_disciples[idx] > 0) {
        num_disciples[idx]--;
    }
}
