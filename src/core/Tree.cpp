// Tree class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Trees are fixed map objects that belong to Forests, provide wood,
// and can catch fire. Key overrides include hold type, creature
// interaction predicates, and wood value calculation.

#include <black/Tree.h>

// ============================================================================
// New virtual methods (vtable 0x868-0x870)
// ============================================================================

void Tree::GetWoodValueMultiplier() {}

Forest* Tree::GetForest() {
    return forest;
}

void Tree::SetOnFire(float /*param1*/) {}
