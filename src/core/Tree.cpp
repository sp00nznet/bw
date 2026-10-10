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
#include <black/PhysicsObject.h>
#include <black/Player.h>

#include <cstring>

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

uint32_t Tree::GetCreatureBeliefType() {
    // v1.0 vslot 67: return 5 (checked by test_chooser)
    return 5;
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
    // Needs size comparison between tree and creature from decompiled code
    return 1;
}

bool32_t Tree::CanBeDestroyedByStoning(Creature*) {
    // v1.0 vslot 158: return 0 (checked by test_chooser)
    return 0;
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
    // Original at 0x0052e220 (v1.0)
    return 6;
}

float Tree::GetReactionPower() {
    // Original at 0x0055d8d0
    return 0.0f;
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

char* Tree::GetDebugText() {
    // Original at 0x0052ec10
    static char text[] = "Tree";
    return text;
}

uint32_t Tree::GetSaveType() {
    // Original at 0x0052ec00
    return 0x4f;
}

// ============================================================================
// Overrides of Fixed virtuals
// ============================================================================

float Tree::GetHowMuchCreatureWantsToLookAtMe() {
    // Original at 0x004b5370
    return 0.3f;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

bool Tree::BlocksTownClearArea() const {
    // Original at 0x0074c7f0 — complex (checks various conditions)
    // Checks tree state and town clear area conditions from decompiled code
    return true;
}

HOLD_TYPE Tree::GetHoldType() {
    // Original at 0x00418100
    return static_cast<HOLD_TYPE>(5);
}

float Tree::GetHoldRadius() {
    // Original at 0x006dcb20: proportional to tree health
    return GetLife() * 0.2f;
}

float Tree::GetHoldLoweringMultiplier() {
    // Original at 0x006dcb30
    return 0.1f;
}

bool32_t Tree::HandShouldFeelWithMeshIntersect() {
    // Trees don't use mesh intersection for hand feel
    // Original at 0x0055d9e0
    return 0;
}

int Tree::GetMesh() const {
    // Original at 0x0052ebd0: reads mesh ID from info at offset 0x100
    return *reinterpret_cast<const int*>(
        reinterpret_cast<const char*>(info) + 0x100);
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

// v1.0 sub_6DCC80: life x GetWoodValueMultiplier (vslot 538) x the
// record's wood (+108, an int) x scale x the land's balance [5].
float Tree::GetWoodValue() {
    int32_t wood = 0;
    if (info) std::memcpy(&wood, reinterpret_cast<const char*>(info) + 108, 4);
    return GetLife() * GetWoodValueMultiplier() * static_cast<float>(wood) * GetScale() * g_land_balance[5];
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

// v1.0 sub_6DCC70: the wood value, truncated (_ftol, sub_733E6C).
int Tree::GetDefaultResource() { return static_cast<int>(GetWoodValue()); }

float Tree::ApplyWaterSpell(SpellWater*) {
    // Original at 0x0074c390 — complex water interaction
    // Apply water growth effect from SpellWater — needs decompiled water interaction logic
    return 0.0f;
}

bool Tree::CanBecomeAPhysicsObject() {
    // Trees can become physics objects (when uprooted)
    // Original at 0x0074b630
    return true;
}

// v1.0 vslot 487 is 0x4048C0 (false): a moving body does not wake a tree.
bool Tree::InteractsWithPhysicsObjects() { return false; }

// v1.0 sub_6DCB90: a thrown tree that hits a wood store (vslot 416) is taken
// by it (vslot 417) with the throwing hand's status.
// ponytail: v1.0 also copies the entry's +424 matrix to 0xC62258 for the
// store's use; nothing reads it here.
void Tree::ReactToPhysicsImpact(PhysicsObject* entry, bool) {
    Object* store = entry && entry->hit ? entry->hit->object : nullptr;
    if (store && store->IsResourceStore(RESOURCE_TYPE_WOOD)) store->DeleteObjectAndTakeResource(this, entry->status);
}

bool Tree::CreatureMustAvoid(Creature*) {
    // Original at 0x0074c0e0 — complex (checks tree state)
    // Check tree state (burning, falling, etc.) to determine avoidance — needs decompiled logic
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
    // Ignite tree and spawn fire particle effects — needs fire/particle system
}
