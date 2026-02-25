// Creature class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// The Creature is the player's avatar — a giant animal with AI, emotions,
// alignment, and learning. At 0x12C8 bytes (nearly 5KB), it's the largest
// struct in the game, containing subsystems for physical state, mental
// state, alignment, help system, sub-actions, and particle effects.
//
// Key subsystems (pointed to by fields):
//   - CreaturePhysical (physical): body, hunger, fatigue, growth
//   - CreatureMental (mind): beliefs, desires, learning, personality
//   - GAlignment (alignment): good/evil axis
//   - CreatureSubActionAgenda: queued behaviors

#include <black/Creature.h>

// Creature has no new virtual methods — uses Living's vtable (0xB40).
// Override implementations for inherited virtuals (GetPlayer, GetSaveType, etc.)
// will be added incrementally from the decompiled output.
//
// Key overrides from decompiled Creature.c:
//   - GetPlayer: returns this->owner (offset 0x1070)
//   - GetSaveType: returns 0x69 (GAME_THING_TYPE_CREATURE)
//   - IsCreature: returns true
//   - Various interaction predicates
