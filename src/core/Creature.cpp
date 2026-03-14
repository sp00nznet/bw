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
