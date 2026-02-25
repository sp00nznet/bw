// Fixed class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Fixed objects are anchored to the map (buildings, trees, rocks, etc.)
// They override many interaction predicates and provide town artifact support.

#include <black/Fixed.h>

// ============================================================================
// New virtual methods (vtable 0x85C-0x860)
// ============================================================================

void Fixed::InsertMapObjectToCellAssumeFixed() {}

bool Fixed::IsObjectFullyInMap() {
    return false;
}

// ============================================================================
// Overrides from GameThingWithPos / Object
// ============================================================================

// Fixed objects cannot be picked up by creatures
bool32_t Fixed::CanBePickedUpByCreature(Creature*) {
    return 0;
}

// Fixed objects cannot frighten creatures
bool32_t Fixed::CanBeFrighteningToCreature(Creature*) {
    return 0;
}

// Creatures can sleep next to fixed objects
bool32_t Fixed::CanBeSleptNextToByCreature(Creature*) {
    return 1;
}

// Fixed objects can be destroyed by stoning
bool32_t Fixed::CanBeDestroyedByStoning(Creature*) {
    return 1;
}

// Can be set on fire if bit 3 of field_0xa (GameThing status byte) is NOT set
bool32_t Fixed::CanBeSetOnFire(Creature*) {
    return ((~field_0xa) & 8) >> 3;
}

// Fixed objects can be crushed
bool32_t Fixed::CanBeCrushed() {
    return 1;
}

// Villagers must avoid fixed objects
bool32_t Fixed::VillagerMustAvoid(Villager*) {
    return 1;
}

// Returns the town artifact pointer
GameThing* Fixed::GetTownArtifact() {
    return town_artifact;
}

// Returns true if this object has a town artifact
bool32_t Fixed::IsTownArtifact() {
    return town_artifact != nullptr;
}

// Network-friendly selection always succeeds for fixed objects
bool32_t Fixed::NetworkFriendlyStartLockedSelect(GInterfaceStatus*) {
    return 1;
}

// Fixed objects are not valid for locked select process
bool32_t Fixed::ValidForLockedSelectProcess(GInterfaceStatus*) {
    return 0;
}

// How much a creature wants to look at this fixed object
float Fixed::GetHowMuchCreatureWantsToLookAtMe() {
    return 0.25f;
}
