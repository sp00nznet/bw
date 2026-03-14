// Creature class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// The Creature is the player's avatar — a giant animal with AI, emotions,
// alignment, and learning. At 0x12C8 bytes (nearly 5KB), it's the largest
// struct in the game, containing subsystems for physical state, mental
// state, alignment, help system, sub-actions, and particle effects.

#include <black/Creature.h>

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
