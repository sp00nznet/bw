// Creature class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// The Creature is the player's avatar — a giant animal with AI, emotions,
// alignment, and learning. At 0x12C8 bytes (nearly 5KB), it's the largest
// struct in the game, containing subsystems for physical state, mental
// state, alignment, help system, sub-actions, and particle effects.

#include <black/Creature.h>
#include <black/CreatureInfo.h>
#include <black/CreaturePhysical.h>
#include <cstring>
#include <cstdlib>

// Forward-declare to avoid include conflicts (CreatureSubActionAgenda defined in both Creature.h and CreatureSubAction.h)
struct CreatureMental;

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

GPlayer* Creature::GetPlayer() {
    // Original at 0x0045e830: mov eax,[ecx+0x1070]
    return owner;
}

char* Creature::GetDebugText() {
    // Original at 0x0045e860
    static char text[] = "Creature";
    return text;
}

uint32_t Creature::GetSaveType() {
    // Original at 0x0045e850
    return 0x69;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

uint32_t Creature::GetScriptObjectType() {
    // Original at 0x005c2de0
    return 0xc;
}

// ============================================================================
// Overrides of Living/MobileWallHug virtuals
// ============================================================================

MapCoords* Creature::GetDestPos() {
    // Original at 0x0045f700: returns pointer to field_0x1214
    return &field_0x1214;
}

MapCoords* Creature::GetFinalDestPos(MapCoords* out) {
    // Original at 0x0045f710: copies dest pos to output
    MapCoords* dest = GetDestPos();
    *out = *dest;
    return out;
}

// ============================================================================
// Non-virtual methods
// ============================================================================

CreaturePhysical* Creature::GetPhysical() {
    return physical;
}

CreatureMental* Creature::GetMind() {
    return mind;
}

GAlignment* Creature::GetAlignment() {
    return alignment;
}

bool Creature::IsOnHomeTeam() {
    // Original at 0x00474490 — checks if creature belongs to the local player
    return owner != nullptr;
}

void Creature::SetOwner(GPlayer* player) {
    owner = player;
}

void Creature::SetName(const char16_t* new_name) {
    // Copy up to 63 chars + null terminator
    for (int i = 0; i < 63 && new_name[i]; i++) {
        name[i] = new_name[i];
    }
    name[63] = u'\0';
}

void Creature::InitCreature(const MapCoords& pos, const CreatureInfo* creature_info, GPlayer* player) {
    // Initialize core subsystems
    physical = static_cast<CreaturePhysical*>(calloc(1, sizeof(CreaturePhysical)));
    mind = static_cast<CreatureMental*>(calloc(1, 0x20D40)); // sizeof(CreatureMental)

    // Link physical back to creature
    physical->creature = this;

    // Set owner
    owner = player;

    // Set initial position
    field_0x1214 = pos;
    field_0x1200 = pos;
    field_0x11cc = pos;
    field_0x11a8 = pos;
    field_0x1164 = pos;
    field_0x3d8 = pos;
    field_0x3ec = pos;

    // Initialize game turn
    game_turn = 0;

    // Linked list
    next_creature = nullptr;

    // Clear name
    memset(name, 0, sizeof(name));
}

// ============================================================================
// Static factory methods
// ============================================================================

Creature* Creature::Create(const MapCoords& pos, const CreatureInfo* creature_info, GPlayer* player) {
    // Original at 0x00474a20 — allocates and initializes a new creature
    Creature* creature = static_cast<Creature*>(calloc(1, sizeof(Creature)));
    if (!creature) return nullptr;

    creature->InitCreature(pos, creature_info, player);

    return creature;
}
