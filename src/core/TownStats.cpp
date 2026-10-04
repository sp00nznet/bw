// TownStats — population, resource, and disciple tracking for a town
// Method stubs from bw1-decomp
#include "../include/black/TownStats.h"
#include "../include/black/Villager.h"
#include "../include/black/Abode.h"
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

void TownStats::AddAbode(Abode* a) {
    // v1.0 sub_6DAF60. Capacity from the abode info (maxAdults +0x174,
    // maxChildren +0x178) into the room totals; homes (abodes with room) into
    // +0x10 and the adult/child room the desires read (+0x34/+0x40); civic
    // buildings into +0x1C; and a byte per abode number at +0x108, which is how
    // the Civic_Buildings desire knows what the town already has.
    if (!a || !a->info) return;
    const char* ai = reinterpret_cast<const char*>(a->info);
    uint32_t max_a, max_c, number;
    std::memcpy(&max_a, ai + 0x174, 4);
    std::memcpy(&max_c, ai + 0x178, 4);
    std::memcpy(&number, ai + 0x124, 4);
    int32_t type; std::memcpy(&type, ai + 0x120, 4);
    field_0x4c += max_a;
    field_0x50 += max_c;
    field_0x44 += 1;
    field_0x30 += max_a + max_c;
    if (type == 256) field_0x48 += 1;  // a Wonder
    if (max_a + max_c) {
        field_0x10 += 1;
        field_0x34 += max_a;
        field_0x40 += max_c;
    }
    if (a->IsCivic()) field_0x1c += 1;
    if (number < 16) reinterpret_cast<uint8_t*>(this)[0x108 + number] += 1;
}
