// FishFarm class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)

#include <black/FishFarm.h>
#include <black/GMultiMapFixedInfo.h>
#include <black/ObjectInfo.h>
#include <black/Game.h>

// External game instance
extern GGame* g_game;

void FishFarm::ToBeDeleted(int param) {
    // Original at 0x0052c690 — complex cleanup
    MultiMapFixed::ToBeDeleted(param);
}

GPlayer* FishFarm::GetPlayer() {
    // Original at 0x0052c850 — gets player from town
    if (town) return reinterpret_cast<GameThing*>(town)->GetPlayer();
    return nullptr;
}

Town* FishFarm::GetTown() {
    // Original at 0x0052c450: returns this->town
    return town;
}

float FishFarm::Get2DRadius() {
    // Original at 0x0052c470: returns 5.0f (from rdata constant)
    return 5.0f;
}

uint32_t FishFarm::RemoveResource(RESOURCE_TYPE /*type*/, uint32_t /*amount*/,
                                   GInterfaceStatus* /*status*/, bool* /*param4*/) {
    // Original at 0x0052cf20 — complex resource management
    return 0;
}

char* FishFarm::GetDebugText() {
    // Original at 0x0052c5b0
    static char text[] = "FishFarm";
    return text;
}

uint32_t FishFarm::Load(GameOSFile* /*file*/) {
    // Original at 0x0052d4f0 — complex serialization
    return 0;
}

uint32_t FishFarm::Save(GameOSFile* /*file*/) {
    // Original at 0x0052d3b0 — complex serialization
    return 0;
}

uint32_t FishFarm::GetSaveType() {
    // Original at 0x0052c5a0: mov eax, 0x5b; ret
    return 0x5b;
}

MapCoords* FishFarm::GetArrivePos(MapCoords* out) {
    // Original at 0x0052c490 — returns door pos
    return GetDoorPos(out);
}

uint32_t FishFarm::GetCreatureBeliefType() {
    // Original at 0x0052c4d0: mov eax, 0x0b; ret
    return 0x0b;
}

bool FishFarm::IsObjectInMap_0() {
    // Original at 0x0052c980 — complex map query
    // Calls internal map query with zero MapCoords origin, checks occupancy result
    return false;
}

bool32_t FishFarm::CanBeEatenByCreature(Creature* /*creature*/) {
    // Original at 0x0052c550: returns 0
    return 0;
}

bool32_t FishFarm::CanBeSleptNextToByCreature(Creature* /*creature*/) {
    // Original at 0x0052c560: returns 0
    return 0;
}

bool32_t FishFarm::CanBePickedUpByCreature(Creature* /*creature*/) {
    // Original at 0x0052c4f0: returns 0
    return 0;
}

bool32_t FishFarm::CanBeStompedOnByCreature(Creature* /*creature*/) {
    // Original at 0x0052c500: returns 0
    return 0;
}

bool32_t FishFarm::CanBeGivenToVillager(Creature* /*creature*/) {
    // Original at 0x0052c510: returns 0
    return 0;
}

bool32_t FishFarm::CanBePutInAStoragePit(Creature* /*creature*/) {
    // Original at 0x0052c520: returns 0
    return 0;
}

bool32_t FishFarm::CanBeDestroyedByStoning(Creature* /*creature*/) {
    // Original at 0x0052c530: returns 0
    return 0;
}

bool32_t FishFarm::CanBeExaminedByCreature(Creature* /*creature*/) {
    // Original at 0x0052c540: returns 0
    return 0;
}

bool32_t FishFarm::IsBeingBuilt(Creature* /*creature*/) {
    // Original at 0x0052c570: returns 0
    return 0;
}

bool32_t FishFarm::NeedsRepair(Creature* /*creature*/) {
    // Original at 0x0052c580: returns 0
    return 0;
}

bool32_t FishFarm::CanBePoodOn(Creature* /*creature*/) {
    // Original at 0x0052c4e0: returns 0
    return 0;
}

Object* FishFarm::GetMapChild(const MapCell* /*cell*/) {
    // Original at 0x0052cad0 — complex map traversal
    return nullptr;
}

void FishFarm::SetMapChild(Object* /*object*/, MapCell* /*cell*/) {
    // Original at 0x0052cb70 — complex
}

void FishFarm::InsertMapObject() {
    // Original at 0x0052ca10 — complex
}

void FishFarm::RemoveMapObject() {
    // Original at 0x0052ca70 — complex
}

float FishFarm::GetMeshRadius() const {
    // Original at 0x0052c480: returns 5.0f (same rdata constant as Get2DRadius)
    return 5.0f;
}

uint32_t FishFarm::Process() {
    // Original at 0x0052d130 — fish farm per-tick food accumulation
    // Reads game turn from g_game->data.game_turn, divides by a tick rate
    // from info[0x124] (past end of GFishFarmInfo — likely a field not captured
    // in the vendor decomp). On each tick interval, field_0x94 (current food)
    // increments by 1.0. Clamped to [0, GetFoodValue(FOOD_TYPE(3))].
    // If field_0x88 is set, updates field_0x88->field_0x64 with fill ratio.

    // Needs tick-rate divisor from info[0x124] once that GFishFarmInfo field is identified
    // For now, accumulate food each turn (simplified)

    // Clamp food to [0, max]
    if (field_0x94 < 0.0f) {
        field_0x94 = 0.0f;
    } else {
        float max_food = GetFoodValue(static_cast<FOOD_TYPE>(3));
        if (max_food < field_0x94) {
            field_0x94 = max_food;
        }
    }

    // Update fill percentage on associated object (visual indicator)
    if (field_0x88 != 0) {
        float max_food = GetFoodValue(static_cast<FOOD_TYPE>(3));
        if (max_food > 0.0f) {
            // field_0x88 points to an object whose field at 0x64 holds fill ratio
            // field_0x88->field_0x64 = field_0x94 / max_food
            // Cast field_0x88 to its visual indicator type once identified, then write fill ratio
        }
    }

    return 1;
}

void FishFarm::Draw() {
    // Original at 0x0052c830 — complex rendering
}

uint32_t FishFarm::GetDiscipleStateIfInteractedWith(GInterfaceStatus* /*status*/,
                                                     Villager* /*villager*/) {
    // Original at 0x0052d720 — complex
    return 0;
}

float FishFarm::GetHeightForHandAboveInteractObject() {
    // Original at 0x0052c840: returns 5.0f (same rdata constant)
    return 5.0f;
}

void FishFarm::CallVirtualFunctionsForCreation(const MapCoords& coords) {
    // Original at 0x0052cc10 — complex
    MultiMapFixed::CallVirtualFunctionsForCreation(coords);
}

float FishFarm::GetFoodValue(FOOD_TYPE type) {
    // Original at 0x0052d1e0 — returns food value from info if type matches
    // Calls info->GetFoodType() to get this farm's food type.
    // If the requested type matches the farm's food type, or type == 3 (any food),
    // then check GetFoodType() virtual on self — if result & 3 (valid food type),
    // return info->foodValue; else 0.
    // Note: info->GetFoodType() is a vtable call at info->vftable[0x38/4]
    const GObjectInfo* obj_info = reinterpret_cast<const GObjectInfo*>(info);
    FOOD_TYPE farm_type = static_cast<FOOD_TYPE>(obj_info->food_type);
    if (type != farm_type && type != static_cast<FOOD_TYPE>(3)) {
        return 0.0f;
    }
    // Check if this Object's GetFoodType returns a valid food type
    FOOD_TYPE self_type = Object::GetFoodType();
    if (static_cast<uint32_t>(self_type) & 3) {
        return obj_info->foodValue;
    }
    return 0.0f;
}

RESOURCE_TYPE FishFarm::GetResourceType() {
    // Original at 0x0052d760: returns RESOURCE_TYPE_FOOD
    return RESOURCE_TYPE_FOOD;
}

bool FishFarm::IsLockedInInteract() {
    // Original at 0x0052c590: mov eax, 1; ret — returns true
    return true;
}

bool32_t FishFarm::ValidForLockedSelectProcess(GInterfaceStatus* /*status*/) {
    // Original at 0x0052d750 — complex
    return 0;
}

bool32_t FishFarm::NetworkFriendlyStartLockedSelect(GInterfaceStatus* /*status*/) {
    // Original at 0x0052d770 — complex
    return 0;
}

bool32_t FishFarm::NetworkUnfriendlyLockedSelect(ControlHandUpdateInfo* /*param1*/) {
    // Original at 0x0052d880 — complex
    return 0;
}

bool32_t FishFarm::NetworkUnfriendlyEndLockedSelect() {
    // Original at 0x0052d890 — complex
    return 0;
}

bool32_t FishFarm::NetworkFriendlyEndLockedSelect(GInterfaceStatus* /*status*/) {
    // Original at 0x0052d8a0 — complex
    return 0;
}

bool32_t FishFarm::ValidForPlaceInHand(GInterfaceStatus* /*status*/) {
    // Original at 0x0052d670 — complex
    return 0;
}

bool32_t FishFarm::InterfaceSetInMagicHand(GInterfaceStatus* /*status*/) {
    // Original at 0x0052d6b0 — complex
    return 0;
}

bool FishFarm::InteractsWithPhysicsObjects() {
    // Original at 0x0052c4b0: returns false
    return false;
}

bool FishFarm::CreatureMustAvoid(Creature* /*param1*/) {
    // Original at 0x0052c460: returns false
    return false;
}

uint32_t FishFarm::ProcessInInteract(GInterfaceStatus* /*status*/) {
    // Original at 0x0052d950 — complex
    return 0;
}

size_t FishFarm::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) {
    // Original at 0x0052cf90 — complex
    return 0;
}

MapCoords* FishFarm::GetDoorPos(MapCoords* pos) {
    // Original at 0x0052cf40 — returns position as door pos
    *pos = coords;
    return pos;
}

PlannedMultiMapFixed* FishFarm::ConvertToPlanned() {
    // Original at 0x0052c4c0 — complex
    return nullptr;
}
