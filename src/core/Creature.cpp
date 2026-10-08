// Creature class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// The Creature is the player's avatar — a giant animal with AI, emotions,
// alignment, and learning. At 0x12C8 bytes (nearly 5KB), it's the largest
// struct in the game, containing subsystems for physical state, mental
// state, alignment, help system, sub-actions, and particle effects.

#include <black/Creature.h>
#include <black/CreatureBrain.h>
#include <black/CreatureInfo.h>
#include <black/CreaturePhysical.h>
#include <cmath>
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

uint32_t Creature::GetCreatureBeliefType() {
    // v1.0 vslot 67: return 8 (checked by test_chooser)
    return 8;
}

bool Creature::IsCreature(Creature* /*creature*/) {
    // Original vslot 12 (0x00401820): return 1
    return true;
}

bool Creature::IsCreature() {
    // Original at 0x00461200
    return true;
}

bool Creature::CanBePickedUp() {
    // Creatures can always be picked up
    return true;
}

bool32_t Creature::CanBePickedUpByCreature(Creature* /*other*/) {
    // v1.0 vslot 150: return 0 (checked by test_chooser)
    return 0;
}

// The creature's 3D object (physical +0x58), as far as these read it: its
// Morphable sizes and the four hand points sub_4CE650 measures.
namespace {
const LH3DCreature* Body3D(const Creature* c) { return c->physical ? c->physical->creature_3d : nullptr; }
float At3D(const LH3DCreature* m, size_t off) {
    float v;
    std::memcpy(&v, reinterpret_cast<const char*>(m) + off, sizeof v);
    return v;
}
}  // namespace

float Creature::Get2DRadius() {
    const LH3DCreature* m = Body3D(this);
    return m ? At3D(m, 0x5228) : Living::Get2DRadius();  // 3D +21032
}

// sub_461EE0: 15 x size_1. ponytail: without a 3D object, as if size_1 were 1.
float Creature::GetHeight() {
    const LH3DCreature* m = Body3D(this);
    return (m ? At3D(m, 0x90) : 1.0f) * 15.0f;
}

// sub_468430: (size_1 x 8.33)^3 x 100, heavier by 15% per unit of the two
// morph weights at +0xA4 and +0xAC (the latter is strength, sub_4D0270).
float Creature::GetWeight() {
    const LH3DCreature* m = Body3D(this);
    if (!m) return Living::GetWeight();
    const float s = At3D(m, 0x90) * 8.333334f;
    return s * ((At3D(m, 0xAC) + At3D(m, 0xA4)) * 0.15000001f + 1.0f) * 100.0f * s * s;
}

// sub_46E600(14): the four points at +0x49C8 are where the hand is in the
// pickup clip (clip 14) on each of the morph meshes 84..81, which sub_4CE650
// measures once off the skeleton. They are blended -0.4, -0.4, 0.9, 0.9 and
// scaled by size_2.
// ponytail: core loads no meshes, so the points are whatever the host put
// there (zero: no reach).
float Creature::HandReach() {
    const LH3DCreature* m = Body3D(this);
    if (!m) return 0.0f;
    static constexpr float kWeight[4] = {-0.4f, -0.4f, 0.9f, 0.9f};
    float p[3] = {};
    for (int i = 0; i < 4; ++i)
        for (int k = 0; k < 3; ++k) p[k] += kWeight[i] * At3D(m, 0x94) * At3D(m, 0x49C8 + 12 * i + 4 * k);
    return std::sqrt(p[0] * p[0] + p[1] * p[1] + p[2] * p[2]);
}

// The v1.0 Creature's constant answers to the chooser's predicates (vslots
// 113, 142, 144, 148, 149, 160), checked by test_chooser.
bool Creature::IsActivityObjectWhichCompassionAppliesTo(Creature*) { return true; }
bool32_t Creature::CanBeFrighteningToCreature(Creature*) { return 1; }
bool32_t Creature::CanBePlayedWithByCreature(Creature*) { return 1; }
bool32_t Creature::CanBeBefriendedByCreature(Creature*) { return 1; }
bool32_t Creature::CanBeSleptNextToByCreature(Creature*) { return 1; }
bool32_t Creature::CanBeExaminedByCreature(Creature*) { return 0; }

bool32_t Creature::CanBeThrownByPlayer() {
    return 1;
}

HOLD_TYPE Creature::GetHoldType() {
    return static_cast<HOLD_TYPE>(0x10);
}

uint32_t Creature::GetPhysicsConstantsType() {
    return 0xA;
}

uint32_t Creature::GetTastiness() {
    return 0;
}

float Creature::GetHowMuchCreatureWantsToLookAtMe() {
    return 1.0f;
}

// ============================================================================
// ProcessState — creature AI state dispatch
// ============================================================================

uint32_t Creature::ProcessState() {
    // Creatures have a more complex AI than villagers — desires, mental model,
    // learning, and physical needs all drive behavior.
    // For now, implement basic state handling.

    action.turns_since_state_change++;

    VILLAGER_STATES state = static_cast<VILLAGER_STATES>(action.top_state);

    switch (state) {
    case VILLAGER_STATE_INVALID_STATE:
        // Left to itself: its mind decides (Creature vslot 392 -> the mental
        // tick, the agenda and the sub-actions), when it has one.
        creature::TickBrain(this);
        break;

    case VILLAGER_STATE_MOVE_TO_POS:
    case VILLAGER_STATE_MOVE_TO_OBJECT:
        // Moving toward a target — advance using MobileWallHug pathfinding
        if (speed == 0) SetSpeed(400);  // Default creature walk speed
        MoveToGoal();
        if (move_state == MOVE_TO_STATES_ARRIVED) {
            SetTopState(VILLAGER_STATE_INVALID_STATE);
        }
        break;

    case VILLAGER_STATE_IN_SCRIPT:
        // Controlled by LHVM script — don't interfere
        break;

    case VILLAGER_STATE_IN_HAND:
        // Being held by the god hand
        break;

    case VILLAGER_STATE_FLYING:
        // Thrown by hand — physics handles this
        break;

    case VILLAGER_STATE_LANDED:
        // Just landed after being thrown — return to idle
        SetTopState(VILLAGER_STATE_INVALID_STATE);
        break;

    case VILLAGER_STATE_SET_DYING:
        SetTopState(VILLAGER_STATE_DYING);
        break;

    case VILLAGER_STATE_DYING:
        if (action.turns_since_state_change > 120) {
            SetTopState(VILLAGER_STATE_DEAD);
        }
        break;

    case VILLAGER_STATE_DEAD:
        if (action.turns_since_state_change > 600) {
            ToBeDeleted(0);
        }
        break;

    case VILLAGER_STATE_BEING_EATEN:
        ReduceLife(0.02f, nullptr);
        if (GetLife() <= 0.0f) {
            SetTopState(VILLAGER_STATE_SET_DYING);
        }
        break;

    default:
        // Unhandled creature states — timeout to idle
        if (action.turns_since_state_change > 300) {
            SetTopState(VILLAGER_STATE_INVALID_STATE);
        }
        break;
    }

    return 1;
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
    coords = pos;  // where it stands (the original places it on creation)
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
    Creature* creature = new Creature();
    if (!creature) return nullptr;

    creature->InitCreature(pos, creature_info, player);

    return creature;
}
