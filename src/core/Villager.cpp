// Villager class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Villagers are the main population unit. They have needs (food, shelter),
// can become disciples, carry resources, build structures, and worship.

#include <black/Villager.h>
#include <black/Abode.h>
#include <black/BuildingSite.h>

// ============================================================================
// Overrides from GameThingWithPos / Object
// ============================================================================

uint32_t Villager::GetCreatureBeliefType() {
    // Original at 0x0055ca70
    return 6;
}

bool32_t Villager::IsABeliever() {
    // Villagers are always believers
    // Original at 0x0055c990
    return 1;
}

bool32_t Villager::CanReceiveGifts(Creature*) {
    // Villagers can always receive gifts
    // Original at 0x0055ca90
    return 1;
}

bool32_t Villager::IsVillager(Creature*) {
    // Original at 0x0055cab0
    return 1;
}

bool Villager::CanBePickedUp() {
    // Original at 0x0055ca50
    // If bit 2 of field_0xe0 is set, cannot be picked up (e.g. in special state)
    if (field_0xe0 & 0x04) {
        return false;
    }
    // Otherwise, can be picked up if bit 13 of field_0x24 is NOT set
    // (bit 13 = "cannot be picked up" flag in GameThingWithPos)
    return !(field_0x24 & 0x2000);
}

uint32_t Villager::GetTastiness() {
    // Villagers are tastiness level 2 (creatures find them moderately tasty)
    // Original at 0x0055ca30
    return 2;
}

int Villager::GetMesh() const {
    // Original at 0x0052e190: reads mesh ID from info struct at offset 0x214
    return *reinterpret_cast<const int*>(
        reinterpret_cast<const char*>(info) + 0x214);
}

int Villager::GetDetailMesh(int detail) {
    // Original at 0x0052e1a0: reads detail mesh from info at 0x210 + detail * 4
    return *reinterpret_cast<const int*>(
        reinterpret_cast<const char*>(info) + 0x210 + detail * 4);
}

// ============================================================================
// New virtual methods (vtable 0xB40-0xB44)
// ============================================================================

const char* Villager::GetVillagerName() {
    // Original at 0x0055ca40 — returns null (name resolved elsewhere)
    return nullptr;
}

float Villager::GetHowMuchCreatureWantsToLookAtMe() {
    // Original at 0x004d1b40
    return 0.5f;
}

void Villager::DrawVillagerInfo() {}

// ============================================================================
// ProcessState — villager state machine dispatch
// ============================================================================

uint32_t Villager::ProcessState() {
    // Original uses a function pointer table (_VillagerStateTable) indexed by state.
    // We implement as a switch dispatch since we don't have the original table.
    // Each case calls the appropriate handler for that state.

    action.turns_since_state_change++;

    VILLAGER_STATES state = static_cast<VILLAGER_STATES>(action.top_state);

    switch (state) {
    case VILLAGER_STATE_INVALID_STATE:
        // Idle — decide what to do next
        // TODO: call DecideWhatToDo() when AI decision tree is implemented
        break;

    case VILLAGER_STATE_MOVE_TO_POS:
    case VILLAGER_STATE_MOVE_TO_OBJECT:
    case VILLAGER_STATE_MOVE_ON_STRUCTURE:
        // Movement states — advance toward goal using MobileWallHug
        if (speed == 0) SetSpeed(200);  // Default villager walk speed
        MoveToGoal();
        if (move_state == MOVE_TO_STATES_ARRIVED) {
            // Arrived at destination — transition to final state
            SetTopState(static_cast<VILLAGER_STATES>(action.final_state));
        }
        break;

    case VILLAGER_STATE_IN_SCRIPT:
        // Controlled by LHVM script — do nothing, script drives state
        break;

    case VILLAGER_STATE_IN_DANCE:
        // Participating in a dance — handled by dance system
        break;

    case VILLAGER_STATE_FLEEING_FROM_OBJECT_REACTION:
    case VILLAGER_STATE_LOOKING_AT_OBJECT_REACTION:
    case VILLAGER_STATE_FOLLOWING_OBJECT_REACTION:
    case VILLAGER_STATE_INSPECT_OBJECT_REACTION:
    case VILLAGER_STATE_LOOK_AT_FLYING_OBJECT_REACTION:
    case VILLAGER_STATE_FLEEING_AND_LOOKING_AT_OBJECT_REACTION:
        // Reaction states — decrement reaction timer, check if done
        if (reaction && reaction_done_when) {
            // TODO: check reaction_done_when condition
        }
        break;

    case VILLAGER_STATE_FLYING:
        // Thrown by hand — physics handles this
        break;

    case VILLAGER_STATE_LANDED:
        // Just landed after being thrown
        SetTopState(VILLAGER_STATE_DECIDE_WHAT_TO_DO);
        break;

    case VILLAGER_STATE_IN_HAND:
        // Being held by the god hand — do nothing
        break;

    case VILLAGER_STATE_SET_DYING:
        // Transition to dying
        SetTopState(VILLAGER_STATE_DYING);
        break;

    case VILLAGER_STATE_DYING:
        // Dying animation — wait then transition to dead
        if (action.turns_since_state_change > 60) { // ~2 seconds at 30fps
            SetTopState(VILLAGER_STATE_DEAD);
        }
        break;

    case VILLAGER_STATE_DEAD:
        // Dead — mark for deletion after timeout
        if (action.turns_since_state_change > 300) { // ~10 seconds
            ToBeDeleted(0);
        }
        break;

    case VILLAGER_STATE_DROWNING:
        // In water — reduce life
        ReduceLife(0.01f, nullptr);
        if (GetLife() <= 0.0f) {
            SetTopState(VILLAGER_STATE_SET_DYING);
        }
        break;

    case VILLAGER_STATE_DOWNED:
        // Knocked down — recover after timeout
        if (action.turns_since_state_change > 90) { // ~3 seconds
            SetTopState(VILLAGER_STATE_DECIDE_WHAT_TO_DO);
        }
        break;

    case VILLAGER_STATE_BEING_EATEN:
        // Being consumed by creature
        ReduceLife(0.05f, nullptr);
        if (GetLife() <= 0.0f) {
            SetTopState(VILLAGER_STATE_SET_DYING);
        }
        break;

    case VILLAGER_STATE_GOTO_FOOD_REACTION:
    case VILLAGER_STATE_GOTO_WOOD_REACTION:
    case VILLAGER_STATE_GOTO_STORAGE_PIT_FOR_DROP_OFF:
    case VILLAGER_STATE_GOTO_STORAGE_PIT_FOR_FOOD:
    case VILLAGER_STATE_GO_HOME:
    case VILLAGER_STATE_GOTO_WORSHIP_SITE_FOR_WORSHIP:
        // Goto states — move toward goal
        if (speed == 0) SetSpeed(200);
        MoveToGoal();
        if (move_state == MOVE_TO_STATES_ARRIVED) {
            // Transition to the "arrives" state (final_state)
            SetTopState(static_cast<VILLAGER_STATES>(action.final_state));
        }
        break;

    case VILLAGER_STATE_ARRIVES_AT_FOOD_REACTION:
        // Arrived at food — pick up
        // TODO: resource pickup logic
        SetTopState(VILLAGER_STATE_GOTO_STORAGE_PIT_FOR_DROP_OFF);
        break;

    case VILLAGER_STATE_ARRIVES_AT_WOOD_REACTION:
        // Arrived at wood — pick up
        SetTopState(VILLAGER_STATE_GOTO_STORAGE_PIT_FOR_DROP_OFF);
        break;

    case VILLAGER_STATE_ARRIVES_HOME:
    case VILLAGER_STATE_AT_HOME:
        // At home — rest, consume food
        if (food > 0.0f) food -= 0.001f;
        if (action.turns_since_state_change > 150) {
            SetTopState(VILLAGER_STATE_DECIDE_WHAT_TO_DO);
        }
        break;

    case VILLAGER_STATE_BUILDING:
        // Building at a construction site
        if (building_site) {
            building_site->BuildBy(0.002f);
        }
        if (action.turns_since_state_change > 120) {
            SetTopState(VILLAGER_STATE_DECIDE_WHAT_TO_DO);
        }
        break;

    case VILLAGER_STATE_WORSHIPPING_AT_WORSHIP_SITE:
        // Worshipping — generates prayer power
        // TODO: increment worship counter on worship site
        break;

    case VILLAGER_STATE_DECIDE_WHAT_TO_DO:
        // AI decision point — choose next activity
        // Priority: survival > tasks > idle
        if (food <= 0.2f) {
            // Hungry — go find food
            if (home) {
                // Set goal to home position for food
                MapCoords home_pos;
                home->GetPos(&home_pos);
                SetGoalPos(home_pos);
                SetCurrentAndDestinationState(
                    VILLAGER_STATE_GOTO_STORAGE_PIT_FOR_FOOD,
                    VILLAGER_STATE_ARRIVES_AT_STORAGE_PIT_FOR_FOOD);
            } else {
                SetTopState(VILLAGER_STATE_INVALID_STATE);
            }
        } else if (building_site && building_site->GetBuilding()) {
            // Has a building assignment — go build
            MapCoords site_pos;
            building_site->GetBuilding()->GetPos(&site_pos);
            SetGoalPos(site_pos);
            SetCurrentAndDestinationState(
                VILLAGER_STATE_MOVE_TO_POS,
                VILLAGER_STATE_ARRIVES_AT_BUILDING_SITE);
        } else if (home) {
            // Nothing urgent — go home and rest
            MapCoords home_pos;
            home->GetPos(&home_pos);
            SetGoalPos(home_pos);
            SetCurrentAndDestinationState(
                VILLAGER_STATE_GO_HOME,
                VILLAGER_STATE_ARRIVES_HOME);
        } else {
            // Homeless — idle
            SetTopState(VILLAGER_STATE_INVALID_STATE);
        }
        break;

    default:
        // Unhandled states — many specialized states (forester, farmer, etc.)
        // For now, timeout back to decision state
        if (action.turns_since_state_change > 300) {
            SetTopState(VILLAGER_STATE_DECIDE_WHAT_TO_DO);
        }
        break;
    }

    return 1;
}

// ============================================================================
// Overrides of GameThingWithPos type predicates
// ============================================================================

bool32_t Villager::IsMaleVillager() {
    // Returns true if disciple_type & sex bit indicates male
    // Sex is stored in the low bit of field_0xf1 (0 = male, 1 = female)
    return (field_0xf1 & 1) == 0 ? 1 : 0;
}

bool32_t Villager::IsFemaleVillager() {
    return (field_0xf1 & 1) != 0 ? 1 : 0;
}

// ============================================================================
// Overrides of Living virtuals
// ============================================================================

bool Villager::AmILikelyToMove() {
    uint8_t state = action.top_state;
    return state == VILLAGER_STATE_MOVE_TO_POS ||
           state == VILLAGER_STATE_MOVE_TO_OBJECT ||
           state == VILLAGER_STATE_MOVE_ON_STRUCTURE ||
           state == VILLAGER_STATE_FLEEING_FROM_OBJECT_REACTION ||
           state == VILLAGER_STATE_FOLLOWING_OBJECT_REACTION ||
           state == VILLAGER_STATE_GOTO_FOOD_REACTION ||
           state == VILLAGER_STATE_GOTO_WOOD_REACTION;
}

uint32_t Villager::GetScriptObjectType() {
    // Original at 0x005c2d80 — villagers are script type 1
    return 1;
}

HOLD_TYPE Villager::GetHoldType() {
    // Original at 0x005c2e40 — villagers use hold type 7
    return static_cast<HOLD_TYPE>(7);
}

float Villager::GetHoldLoweringMultiplier() {
    // Original at 0x005c2650
    return 0.65f;
}

uint32_t Villager::GetPhysicsConstantsType() {
    // Original at 0x005c2660 — villagers use physics type 7
    return 7;
}

bool32_t Villager::CanBeEatenByCreature(Creature* /*creature*/) {
    // Original at 0x004e48a0 — villagers can be eaten if not dead
    return !IsDead() ? 1 : 0;
}

bool32_t Villager::CanBeBefriendedByCreature(Creature* /*creature*/) {
    // Original at 0x0055c9a0 — villagers can be befriended
    return 1;
}

bool32_t Villager::CanBeStrokedByCreature(Creature* /*creature*/) {
    // Original at 0x0055c9b0 — villagers can be stroked
    return 1;
}

bool32_t Villager::CanBeKissedByCreature(Creature* /*creature*/) {
    // Original at 0x0055c9c0 — villagers can be kissed
    return 1;
}

bool32_t Villager::CanBeGivenToTown(Creature* /*creature*/) {
    // Original at 0x0055c9d0 — villagers can be given to a town
    return 1;
}

bool32_t Villager::CanBePutInFoodPile(Creature* /*creature*/) {
    // Original at 0x0055c9e0 — villagers cannot be put in food pile
    return 0;
}

bool32_t Villager::CanBePutInWoodPile(Creature* /*creature*/) {
    // Original at 0x0055c9f0 — villagers cannot be put in wood pile
    return 0;
}

bool32_t Villager::CanBeBroughtBackToCitadel(Creature* /*creature*/) {
    // Original at 0x0055ca00 — villagers can be brought to citadel
    return 1;
}

bool32_t Villager::CanBeThrownByCreature(Creature* /*creature*/) {
    // Original at 0x0055ca10 — villagers can be thrown
    return 1;
}

bool32_t Villager::CanBeGivenToVillager(Creature* /*creature*/) {
    // Original at 0x0055ca20 — villagers can receive other villagers
    return 0;
}

// ============================================================================
// Non-virtual methods
// ============================================================================

Town* Villager::GetTown() {
    // Villager gets town from its home abode
    if (home) return home->GetTown();
    return nullptr;
}

Abode* Villager::GetHome() {
    return home;
}

void Villager::SetHome(Abode* abode) {
    home = abode;
}

bool Villager::IsPregnant() const {
    return is_pregnant != 0;
}

bool Villager::IsHomeless() const {
    return home == nullptr;
}

bool Villager::IsCarryingResource() const {
    return resource_held[0] != 0 || resource_held[1] != 0 || resource_held[2] != 0;
}

int16_t Villager::GetResourceHeld(RESOURCE_TYPE type) const {
    if (static_cast<uint32_t>(type) < 3) return resource_held[static_cast<uint32_t>(type)];
    return 0;
}

void Villager::AddResourceHeld(RESOURCE_TYPE type, int16_t amount) {
    if (static_cast<uint32_t>(type) < 3) {
        resource_held[static_cast<uint32_t>(type)] += amount;
    }
}

void Villager::ClearResourceHeld() {
    resource_held[0] = 0;
    resource_held[1] = 0;
    resource_held[2] = 0;
}

float Villager::GetFood() const {
    return food;
}

void Villager::SetFood(float value) {
    food = value;
}

bool Villager::IsFoodSpeedUp() const {
    return food_speed_up;
}
