// Villager class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Villagers are the main population unit. They have needs (food, shelter),
// can become disciples, carry resources, build structures, and worship.

#include <black/Villager.h>
#include <black/Abode.h>

// ============================================================================
// Overrides from GameThingWithPos / Object
// ============================================================================

uint32_t Villager::GetCreatureBeliefType() {
    // Original at 0x0055ca70
    return 6;
}

bool32_t Villager::IsABeliever() {
    // Villagers are always believers
    // Original at 0x0055c990
    return 1;
}

bool32_t Villager::CanReceiveGifts(Creature*) {
    // Villagers can always receive gifts
    // Original at 0x0055ca90
    return 1;
}

bool32_t Villager::IsVillager(Creature*) {
    // Original at 0x0055cab0
    return 1;
}

bool Villager::CanBePickedUp() {
    // Original at 0x0055ca50
    // If bit 2 of field_0xe0 is set, cannot be picked up (e.g. in special state)
    if (field_0xe0 & 0x04) {
        return false;
    }
    // Otherwise, can be picked up if bit 13 of field_0x24 is NOT set
    // (bit 13 = "cannot be picked up" flag in GameThingWithPos)
    return !(field_0x24 & 0x2000);
}

uint32_t Villager::GetTastiness() {
    // Villagers are tastiness level 2 (creatures find them moderately tasty)
    // Original at 0x0055ca30
    return 2;
}

int Villager::GetMesh() const {
    // Original at 0x0052e190: reads mesh ID from info struct at offset 0x214
    return *reinterpret_cast<const int*>(
        reinterpret_cast<const char*>(info) + 0x214);
}

int Villager::GetDetailMesh(int detail) {
    // Original at 0x0052e1a0: reads detail mesh from info at 0x210 + detail * 4
    return *reinterpret_cast<const int*>(
        reinterpret_cast<const char*>(info) + 0x210 + detail * 4);
}

// ============================================================================
// New virtual methods (vtable 0xB40-0xB44)
// ============================================================================

const char* Villager::GetVillagerName() {
    // Original at 0x0055ca40 — returns null (name resolved elsewhere)
    return nullptr;
}

float Villager::GetHowMuchCreatureWantsToLookAtMe() {
    // Original at 0x004d1b40
    return 0.5f;
}

void Villager::DrawVillagerInfo() {}

// ============================================================================
// Non-virtual methods
// ============================================================================

Town* Villager::GetTown() {
    // Villager gets town from its home abode
    if (home) return home->GetTown();
    return nullptr;
}

Abode* Villager::GetHome() {
    return home;
}

void Villager::SetHome(Abode* abode) {
    home = abode;
}

bool Villager::IsPregnant() const {
    return is_pregnant != 0;
}

bool Villager::IsHomeless() const {
    return home == nullptr;
}

bool Villager::IsCarryingResource() const {
    return resource_held[0] != 0 || resource_held[1] != 0 || resource_held[2] != 0;
}

int16_t Villager::GetResourceHeld(RESOURCE_TYPE type) const {
    if (static_cast<uint32_t>(type) < 3) return resource_held[static_cast<uint32_t>(type)];
    return 0;
}

void Villager::AddResourceHeld(RESOURCE_TYPE type, int16_t amount) {
    if (static_cast<uint32_t>(type) < 3) {
        resource_held[static_cast<uint32_t>(type)] += amount;
    }
}

void Villager::ClearResourceHeld() {
    resource_held[0] = 0;
    resource_held[1] = 0;
    resource_held[2] = 0;
}

float Villager::GetFood() const {
    return food;
}

void Villager::SetFood(float value) {
    food = value;
}

bool Villager::IsFoodSpeedUp() const {
    return food_speed_up;
}
