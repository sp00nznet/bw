// Living class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Living is the base class for all animate entities (Villager, Creature, Animal).
// It adds 200+ virtual methods for AI reactions, animation state machines,
// and behavioral decision-making.
//
// Full virtual method implementations will be added incrementally as
// derived classes (Villager, Creature) are implemented.

#include <black/Living.h>

// Living has 200+ new virtual methods. Most are stubs in the base class
// and are overridden by Villager, Creature, and Animal. The key logic
// lives in the derived classes.
//
// TODO: Implement Living virtual methods as needed by derived classes.
// Priority methods (from decompiled Living.c):
//   - IsAlive: checks life > 0.0
//   - GetLife: returns life field from Object
//   - Process: main update tick
//   - DecideWhatToDo: AI decision tree
//   - StartReacting/StopReacting: reaction system
