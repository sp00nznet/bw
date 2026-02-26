// Tree class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Trees are fixed map objects that belong to Forests, provide wood,
// and can catch fire. Key overrides include hold type, creature
// interaction predicates, and wood value calculation.
//
// Simple overrides confirmed from bw1-decomp Tree.h method addresses
// (0x0055d8xx range — tiny return-constant functions).

#include <black/Tree.h>

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

uint32_t Tree::GetCreatureBeliefType() {
    // Original at 0x0055d950
    return 3;
}

bool32_t Tree::IsCastShadowAtNight() {
    // Trees cast shadows at night
    // Original at 0x0055da10
    return 1;
}

bool32_t Tree::CanBeAttackedByCreature(Creature*) {
    // Trees can be attacked by creatures
    // Original at 0x0055d9a0
    return 1;
}

bool32_t Tree::CanBePlayedWithByCreature(Creature*) {
    // Creatures can play with trees
    // Original at 0x0055d930
    return 1;
}

bool32_t Tree::CanBePickedUpByCreature(Creature*) {
    // Creatures can pick up trees
    // Original at 0x004e4a80 — complex (checks tree size vs creature)
    // TODO: implement properly when decompiled code available
    return 1;
}

bool32_t Tree::CanBeDestroyedByStoning(Creature*) {
    // Trees can be destroyed by stoning
    // Original at 0x0055d990
    return 1;
}

bool32_t Tree::CanBeUsedForBuilding(Creature*) {
    // Trees provide wood for building
    // Original at 0x0055d970
    return 1;
}

bool32_t Tree::CanBeUsedForRepair(Creature*) {
    // Trees provide wood for repair
    // Original at 0x0055d980
    return 1;
}

bool32_t Tree::BenefitsFromHavingWaterSprinkledOnIt(Creature*) {
    // Watering trees helps them grow
    // Original at 0x0055d940
    return 1;
}

bool32_t Tree::IsTree_1() {
    // A Tree is a tree
    // Original at 0x0055d9d0
    return 1;
}

bool32_t Tree::IsTree_0(Creature*) {
    // A Tree is a tree regardless of creature context
    // Original at 0x0055d920
    return 1;
}

bool32_t Tree::IsAnyKindOfTree() {
    // Original at 0x0055d9c0
    return 1;
}

bool32_t Tree::CanBeThrownInTheSeaPlayfully(Creature*) {
    // Trees can be thrown in the sea
    // Original at 0x0055d9b0
    return 1;
}

uint32_t Tree::GetCreatureMimicType() {
    // Original at 0x0055d960
    return 2;
}

float Tree::GetReactionPower() {
    // Original at 0x0055d8d0
    return 0.0f;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

bool Tree::BlocksTownClearArea() const {
    // Original at 0x0074c7f0 — complex (checks various conditions)
    // TODO: implement properly when decompiled code available
    return true;
}

HOLD_TYPE Tree::GetHoldType() {
    // Original at 0x0074b600
    return HOLD_TYPE_DEFAULT;
}

float Tree::GetHoldRadius() {
    // Original at 0x0074b610
    return 0.0f;
}

float Tree::GetHoldLoweringMultiplier() {
    // Original at 0x0074b620
    return 0.0f;
}

bool32_t Tree::HandShouldFeelWithMeshIntersect() {
    // Trees don't use mesh intersection for hand feel
    // Original at 0x0055d9e0
    return 0;
}

int Tree::GetMesh() const {
    // Original at 0x0055d8a0
    // TODO: reads from GTreeInfo
    return 0;
}

bool Tree::CanBePickedUp() {
    // Trees can be picked up by the hand
    // Original at 0x0055d8b0
    return true;
}

float Tree::GetVillagerHugRadius() {
    // Original at 0x0074a1a0
    return 0.0f;
}

float Tree::GetWoodValue() {
    // Original at 0x0074b7b0 — reads from GTreeInfo
    // TODO: implement data-driven when GTreeInfo is available
    return 0.0f;
}

bool Tree::IsResourceStore(RESOURCE_TYPE type) {
    // Trees store wood resources
    // Original at 0x0055d8f0
    return type == RESOURCE_TYPE_WOOD;
}

RESOURCE_TYPE Tree::GetResourceType() {
    // Trees are wood resources
    // Original at 0x0074b820
    return RESOURCE_TYPE_WOOD;
}

int Tree::GetDefaultResource() {
    // Original at 0x0074b7a0
    return 0;
}

float Tree::ApplyWaterSpell(SpellWater*) {
    // Original at 0x0074c390 — complex water interaction
    // TODO: implement when decompiled code available
    return 0.0f;
}

bool Tree::CanBecomeAPhysicsObject() {
    // Trees can become physics objects (when uprooted)
    // Original at 0x0074b630
    return true;
}

bool Tree::InteractsWithPhysicsObjects() {
    // Trees interact with physics
    // Original at 0x0074b6a0
    return true;
}

bool Tree::CreatureMustAvoid(Creature*) {
    // Original at 0x0074c0e0 — complex (checks tree state)
    // TODO: implement when decompiled code available
    return true;
}

bool Tree::IsARootedObject() {
    // Trees are rooted in the ground
    // Original at 0x0074b720
    return true;
}

uint32_t Tree::GetCarriedTreeType() {
    // Original at 0x0055d900 — returns info type
    return 0;
}

// ============================================================================
// New virtual methods (vtable 0x868-0x870)
// ============================================================================

float Tree::GetWoodValueMultiplier() {
    // Original at 0x0074b810
    return 1.0f;
}

Forest* Tree::GetForest() {
    return forest;
}

void Tree::SetOnFire(float /*param1*/) {
    // Original at 0x0074c140 — complex fire system
    // TODO: implement when decompiled code available
}
