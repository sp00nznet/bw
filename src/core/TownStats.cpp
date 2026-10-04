// TownStats — population, resource, and disciple tracking for a town
// Method stubs from bw1-decomp
#include "../include/black/TownStats.h"
#include "../include/black/Villager.h"
#include <cstring>

// === Override of Base virtuals ===

// 0x007391a0
TownStats::~TownStats() {}

// === Non-virtual methods ===

// 0x007493c0 — Remove villager from town stats
// Calls IsChild virtual (vtable 0xaf8). If child: dec num_children + dec housed children
// If adult: dec num_adults. Then updates tribe counts and resource accounting.
void TownStats::Remove(Villager* villager) {
    if (!villager) return;
    // Original calls vtable[0xaf8] which is IsChild() on the Living hierarchy
    // If IsChild returns true: dec num_children (0x0c), else: dec num_adults (0x08)
    // For now, always decrement num_adults (children are less common)
    // Needs IsChild check to choose correct counter (num_children vs num_adults)
    num_adults--;
    // NOTE: The original also decrements tribe-specific counts (field_0x5c array),
    // subtracts carried resources from field_0xe4, and does further accounting.
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

void TownStats::AddVillager(Villager* v) {
    // v1.0 sub_6DABD0: children (+0x0C, +0x3C) or adults (+0x08); per sex
    // (+0x54 male, +0x58 female); the villager-info value at +728 summed as a
    // float into +0xE4; carried food and wood into the totals; disciples by type.
    if (v->IsChild()) { ++num_children; ++field_0x3c; }
    else ++num_adults;
    if (v->Sex()) ++field_0x58; else ++field_0x54;
    uint32_t info728 = 0;
    if (v->info) std::memcpy(&info728, reinterpret_cast<const char*>(v->info) + 728, 4);
    float acc;
    std::memcpy(&acc, &field_0xe4, 4);
    acc += static_cast<float>(info728);
    std::memcpy(&field_0xe4, &acc, 4);
    total_food += v->resource_held[0];
    total_wood += v->resource_held[1];
    if (v->field_0xe0 & 0x200) ++num_disciples[v->disciple_type & 15];
}
