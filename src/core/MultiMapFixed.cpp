// MultiMapFixed class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Multi-cell building objects (Abode, Citadel, Workshop, etc.) that span
// multiple map cells. Handles building/repair progress, footpath
// connectivity, resource management, and collision.

#include <black/MultiMapFixed.h>
#include <black/Map.h>

extern GMap* g_map;
#include <black/BuildingSite.h>
#include <black/GMultiMapFixedInfo.h>

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

Town* MultiMapFixed::GetTown() {
    // Original at 0x004220a0 — complex
    // TODO: implement when Town system is available
    return nullptr;
}

bool MultiMapFixed::IsFootpathLink() {
    // MultiMapFixed IS a footpath link
    // Original at 0x00401610
    return true;
}

GFootpathLink* MultiMapFixed::GetFootpathLink() {
    // Returns the footpath link pointer
    // Original at 0x00401620
    return footpath_link;
}

uint32_t MultiMapFixed::GetNearestPathTo(const MapCoords& /*coords*/, float /*param2*/, int /*param3*/) {
    // Original at 0x0052eeb0 — complex pathfinding
    // TODO: implement when pathfinding system is available
    return 0;
}

void MultiMapFixed::UseFootpathIfNecessary(Living* /*living*/, const MapCoords* /*coords*/, uint8_t /*param3*/) {
    // Original at 0x0052eec0 — complex
    // TODO: implement when pathfinding system is available
}

uint32_t MultiMapFixed::AddFootpath(GFootpath* /*footpath*/) {
    // Original at 0x0052ee10 — complex
    // TODO: implement when footpath system is available
    return 0;
}

uint32_t MultiMapFixed::RemoveFootpath(GFootpath* /*footpath*/) {
    // Original at 0x0052ee80 — complex
    // TODO: implement when footpath system is available
    return 0;
}

uint32_t MultiMapFixed::AddResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool param4, const MapCoords& coords, int /*param6*/) {
    // Original at 0x00505350: delegates to building_site->AddResource
    if (building_site != nullptr) {
        return building_site->AddResource(type, amount, status, param4, coords, 0);
    }
    return 0;
}

uint32_t MultiMapFixed::RemoveResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool* param4) {
    // Original at 0x00505390: delegates to building_site->RemoveResource
    if (building_site != nullptr) {
        return building_site->RemoveResource(type, amount, status, param4);
    }
    return 0;
}

MultiMapFixed* MultiMapFixed::CastMultiMapFixed() {
    // Original at 0x00401540
    return this;
}

bool MultiMapFixed::IsFunctional() {
    // Original at 0x00505140
    // Checks: available, built, and repair above threshold
    if (!IsAvailable()) return false;
    if (!IsBuilt()) return false;
    float repaired = GetPercentRepaired();
    float threshold = GetPercentRepairedForNonFunctional();
    return threshold < repaired;
}

uint32_t MultiMapFixed::Load(GameOSFile* /*file*/) {
    // Original at 0x0052f310 — complex serialization
    // TODO: implement when save system is available
    return 0;
}

uint32_t MultiMapFixed::Save(GameOSFile* /*file*/) {
    // Original at 0x0052f250 — complex serialization
    // TODO: implement when save system is available
    return 0;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

MapCoords* MultiMapFixed::GetArrivePos(MapCoords* out) {
    // Original at 0x00421fe0 — complex
    // TODO: implement properly
    *out = coords;
    return out;
}

bool MultiMapFixed::IsObjectInMap_0() {
    // Original at 0x0052e480 — complex
    // TODO: implement properly
    return false;
}

bool32_t MultiMapFixed::IsBeingBuilt(Creature* /*creature*/) {
    // Original at 0x004015e0: calls IsBuilt() through vtable, returns !IsBuilt()
    // Decompiled: dec eax; neg eax; sbb eax,eax; neg eax
    // This sequence inverts the boolean: if IsBuilt() == 1, returns 0; if 0, returns 1
    return IsBuilt() ? 0 : 1;
}

bool32_t MultiMapFixed::NeedsRepair(Creature* /*creature*/) {
    // Original at 0x00401600: calls IsRepaired() through vtable, returns !IsRepaired()
    // Decompiled: neg eax; sbb eax,eax; inc eax
    return IsRepaired() ? 0 : 1;
}

bool32_t MultiMapFixed::IsBuildingWhichIsBeingBuilt(Creature* /*creature*/) {
    // Original at 0x004c5600
    // Building under construction: either not fully built, or damaged and not fully repaired
    if (GetPercentBuilt() < 1.0f) return 1;
    if ((field_0x58 & 4) && GetLife() < 1.0f) return 1;
    return 0;
}

bool32_t MultiMapFixed::IsWonder() {
    // Original at 0x00422050 — complex
    // TODO: implement properly
    return 0;
}

bool32_t MultiMapFixed::CreateBuildingSite() {
    // Original at 0x0052f590 — complex
    // TODO: implement when building site system is available
    return 0;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

Object* MultiMapFixed::GetMapChild(const MapCell* /*cell*/) {
    // Original at 0x0052e400 — searches multi_children_array
    // TODO: implement properly
    return nullptr;
}

void MultiMapFixed::SetMapChild(Object* /*object*/, MapCell* /*cell*/) {
    // Original at 0x0052e420 — complex
    // TODO: implement properly
}

void MultiMapFixed::InsertMapObject() {
    // Original at 0x0052e650 — insert into all cells this building occupies
    if (!g_map) return;

    // Insert into the primary cell (same as SingleMapFixed)
    uint32_t cell_x = static_cast<uint32_t>(coords.x) >> 16;
    uint32_t cell_z = static_cast<uint32_t>(coords.z) >> 16;
    if (g_map->InBounds(cell_x, cell_z)) {
        MapCell* cell = g_map->ToMap(cell_x, cell_z);
        map_parent = cell->first_object_fixed;
        cell->SetFirstObjectFixed(this);
    }

    // Insert into additional cells from multi_children_array
    for (uint32_t i = 0; i < multi_children_array.size; i++) {
        MultiChild& child = multi_children_array.array[i];
        uint16_t cx = static_cast<uint16_t>(child.coords & 0xFFFF);
        uint16_t cz = static_cast<uint16_t>((child.coords >> 16) & 0xFFFF);
        if (g_map->InBounds(cx, cz)) {
            MapCell* cell = g_map->ToMap(cx, cz);
            InsertMapObjectToCell(cell);
        }
    }

    field_0x24 |= 1;  // Set "in map" flag
    obj_coords = coords;
}

void MultiMapFixed::RemoveMapObject() {
    // Original at 0x0052e7b0 — remove from all cells this building occupies
    if (!g_map) return;

    // Remove from primary cell
    uint32_t cell_x = static_cast<uint32_t>(obj_coords.x) >> 16;
    uint32_t cell_z = static_cast<uint32_t>(obj_coords.z) >> 16;
    if (g_map->InBounds(cell_x, cell_z)) {
        MapCell* cell = g_map->ToMap(cell_x, cell_z);
        Object* prev = nullptr;
        Object* curr = cell->first_object_fixed;
        while (curr) {
            if (curr == this) {
                if (prev) prev->map_parent = map_parent;
                else cell->SetFirstObjectFixed(map_parent);
                map_parent = nullptr;
                break;
            }
            prev = curr;
            curr = curr->map_parent;
        }
    }

    // Remove from additional cells
    for (uint32_t i = 0; i < multi_children_array.size; i++) {
        MultiChild& child = multi_children_array.array[i];
        uint16_t cx = static_cast<uint16_t>(child.coords & 0xFFFF);
        uint16_t cz = static_cast<uint16_t>((child.coords >> 16) & 0xFFFF);
        if (g_map->InBounds(cx, cz)) {
            MapCell* cell = g_map->ToMap(cx, cz);
            RemoveMapObjectFromCell(cell);
        }
    }

    field_0x24 &= ~1;  // Clear "in map" flag
}

int MultiMapFixed::MoveMapObject(const MapCoords& /*coords*/) {
    // Original at 0x0052e4f0 — complex
    // TODO: implement properly
    return 0;
}

void MultiMapFixed::ReduceLife(float value, GPlayer* player) {
    // Original at 0x00505790 — reduces life and enters damaged state if needed
    Object::ReduceLife(value, player);
    if (GetLife() < 1.0f && IsBuilt()) {
        field_0x58 |= 4;  // Set damaged bit
    }
}

uint32_t MultiMapFixed::Process() {
    // Original at 0x005058a0: delegates to building_site->Process()
    if (building_site != nullptr) {
        building_site->Process();
    }
    return 1;
}

void MultiMapFixed::Draw() {
    // Original at 0x00518090 — complex rendering
    // TODO: implement properly
}

uint32_t MultiMapFixed::GetDiscipleStateIfInteractedWith(GInterfaceStatus* /*status*/, Villager* /*villager*/) {
    // Original at 0x0052f0d0 — complex
    // TODO: implement properly
    return 0;
}

void MultiMapFixed::CallVirtualFunctionsForCreation(const MapCoords& /*coords*/) {
    // Original at 0x0052e890 — complex
    // TODO: implement properly
}

MultiMapFixed* MultiMapFixed::AsMultiMapFixed() {
    // Original at 0x00401490
    return this;
}

bool MultiMapFixed::IsResourceStore(RESOURCE_TYPE type) {
    // Original at 0x005053c0: returns true only for wood when building_site exists
    return (type == RESOURCE_TYPE_WOOD) && (building_site != nullptr);
}

bool MultiMapFixed::DeleteObjectAndTakeResource(Object* /*param1*/, GInterfaceStatus* /*param2*/) {
    // Original at 0x0052f460 — complex
    // TODO: implement properly
    return false;
}

bool MultiMapFixed::DoCreatureMimicAfterAddingResource(RESOURCE_TYPE /*type*/, GInterfaceStatus* /*status*/) {
    // Original at 0x0052f210 — complex
    // TODO: implement properly
    return false;
}

void MultiMapFixed::StartOnFire() {
    // Original at 0x0052ec60 — complex fire system
    // TODO: implement properly
}

bool MultiMapFixed::InteractsWithPhysicsObjects() {
    // Original at 0x005055a0: interacts when built enough and alive enough
    float built = GetPercentBuilt();
    float life = GetLife();
    return (built > 0.1f) && (life > 0.01f);
}

bool MultiMapFixed::CreatureMustAvoid(Creature* /*param1*/) {
    // Original at 0x0052f490 — complex
    // TODO: implement properly
    return false;
}

bool32_t MultiMapFixed::IsSolidToNewAbode() {
    // Original at 0x00401530
    return 1;
}

size_t MultiMapFixed::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) {
    // Original at 0x0052ef10 — complex
    // TODO: implement properly
    return 0;
}

NewCollide* MultiMapFixed::GetCollideData() const {
    // Original at 0x00401630
    return collide_data;
}

// ============================================================================
// Override of Fixed virtuals
// ============================================================================

bool MultiMapFixed::IsObjectFullyInMap() {
    // Original at 0x0052e490 — complex multi-cell check
    // TODO: implement properly
    return false;
}

// ============================================================================
// New virtual methods (vtable 0x864-0x908)
// ============================================================================

MapCoords* MultiMapFixed::GetDoorPos(MapCoords* pos) {
    // Original at 0x0052e370 — complex
    // TODO: implement properly
    *pos = coords;
    return pos;
}

float MultiMapFixed::GetInfluence() {
    // Original at 0x00504ef0: product of build/scale/life/info values
    float built = GetPercentBuilt();
    float scale = GetScale();
    float life = GetLife();
    return life * (scale * built) * static_cast<const GMultiMapFixedInfo*>(info)->influence;
}

bool MultiMapFixed::IsPlaytimeStructure() {
    // Original at 0x004014a0
    return false;
}

bool MultiMapFixed::IsPlaytimeStarted() {
    // Original at 0x004014b0
    return false;
}

bool MultiMapFixed::AddPlaytimeVillager(Villager* /*villager*/) {
    // Original at 0x004014c0
    return false;
}

void MultiMapFixed::CheckMapObject_1() {
    // Original at 0x0052e840 — complex
    // TODO: implement properly
}

void MultiMapFixed::GetResourceDropPosForComputerPlayer(MapCoords* drop_pos) {
    // Original at 0x004014d0: copies this->coords to drop_pos
    // Decompiled: adds 0x14 to ecx (= &this->coords from GameThingWithPos base)
    // then copies 12 bytes (3 floats)
    *drop_pos = coords;
}

float MultiMapFixed::GetPercentBuilt() {
    // Original at 0x004014f0: returns this->percent_built
    return percent_built;
}

float MultiMapFixed::GetPercentRepaired() {
    // Original at 0x00401500: calls GetLife() through vtable
    // Decompiled: mov eax,[ecx]; jmp [eax+0x11c]
    // 0x11c / 4 = vtable slot for GetLife
    return GetLife();
}

float MultiMapFixed::GetPercentRepairedFromWhenDamaged() {
    // Original at 0x005051e0: calculates repair progress relative to damage start
    if (!IsBuilt()) return 1.0f;
    if (GetDestructionMesh() == nullptr || building_site == nullptr) {
        return GetPercentRepaired() * 0.98f;
    }
    float damage_start = building_site->life;
    float range = 1.0f - damage_start;
    float progress = GetPercentRepaired() - damage_start;
    if (range != 0.0f && progress != 0.0f) {
        return progress / range;
    }
    return 0.0f;
}

bool MultiMapFixed::IsRepaired() {
    // Original at 0x00438d70 — stub, overridden in Abode etc.
    // Base implementation: not damaged means repaired
    return (field_0x58 & 4) == 0;
}

bool MultiMapFixed::IsBuilt() {
    // Original at 0x0052e850 (misnamed BuildBy in Ghidra mangling)
    // Checks: construction flag not set, and build progress >= 100%
    if ((field_0x58 & 2) == 2) return false;
    return GetPercentBuilt() >= 1.0f;
}

float MultiMapFixed::GetPercentRepairedForNonFunctional() {
    // Original at 0x00505190: constant threshold
    return 0.75f;
}

float MultiMapFixed::GetPercentForDrawBuilding() {
    // Original at 0x005051a0: returns the lesser of build and repair progress
    float repaired = GetPercentRepairedFromWhenDamaged();
    float built = GetPercentBuilt();
    return (repaired < built) ? repaired : built;
}

float MultiMapFixed::GetPercentAbodeFullWithAdults() {
    // Original at 0x00422000 — complex
    // TODO: implement properly
    return 0.0f;
}

float MultiMapFixed::GetPercentAbodeFullWithChildren() {
    // Original at 0x00422010 — complex
    // TODO: implement properly
    return 0.0f;
}

bool MultiMapFixed::IsDrawBuilding() {
    // Original at 0x00505290: true when a building site exists
    return building_site != nullptr;
}

bool MultiMapFixed::Built() {
    // Original at 0x00504e10 — complex (notifies town, player, etc.)
    // TODO: implement full notification chain (IsCivic, GetAbodeType, GetTown, etc.)
    if (building_site != nullptr) {
        building_site->ToBeDeleted(0);
    }
    // Clear "under construction" (bit 1), set "fully built" (bit 3)
    field_0x58 = (field_0x58 & ~2) | 8;
    percent_built = 1.0f;
    return true;
}

bool MultiMapFixed::Repaired() {
    // Original at 0x00504ec0: notify building site, remove damage state
    if (building_site != nullptr) {
        building_site->ToBeDeleted(0);
    }
    RemoveDamage();
    field_0x58 &= ~4;  // Clear damaged bit
    return true;
}

uint32_t MultiMapFixed::GetBuildingSiteWood(uint32_t* /*param1*/) {
    // Original at 0x00401510
    return 0;
}

LH3DMesh* MultiMapFixed::GetDestructionMesh() {
    // Original at 0x00422020 — complex
    // TODO: implement properly
    return nullptr;
}

void MultiMapFixed::RemoveDamage() {
    // Original at 0x00422030 — clears damage state and restores full life
    field_0x58 &= ~4;  // Clear damaged bit
    life = 1.0f;
}

void* MultiMapFixed::GetBuildingObject() {
    // Original at 0x00401520: returns this
    return this;
}

bool MultiMapFixed::IsCivic() {
    // Original at 0x00422040 — complex
    // TODO: implement properly
    return false;
}

ABODE_TYPE MultiMapFixed::GetAbodeType() {
    // Original at 0x00422060 — complex
    // TODO: implement properly
    return ABODE_TYPE_NONE;
}

void MultiMapFixed::SetPower(float /*power*/) {
    // Original at 0x00401550: no-op in base class
}

MapCoords* MultiMapFixed::GetResourcePos(RESOURCE_TYPE /*type*/, int /*param2*/) {
    // Original at 0x00401560: returns the building's position as resource pos
    return &coords;
}

bool MultiMapFixed::IsPoisonedResource() {
    // Original at 0x00401580
    return false;
}

MapCoords* MultiMapFixed::GetResourceNearestEdge(MapCoords* out, RESOURCE_TYPE type, Object* /*param3*/, int param4) {
    // Original at 0x00401590: delegates to GetResourcePos
    MapCoords* res = GetResourcePos(type, param4);
    if (res && out) {
        *out = *res;
        return out;
    }
    return nullptr;
}

float MultiMapFixed::GetDesireToBeRepaired() {
    // Original at 0x00504f30: desire scales with damage, clamped to [0, 1]
    if (IsRepaired()) return 0.0f;
    float repaired = GetPercentRepaired();
    float desire = ((1.0f - repaired) * 0.5f + 0.5f) *
                   static_cast<const GMultiMapFixedInfo*>(info)->desireToBeRepaired;
    if (desire >= 1.0f) return 1.0f;
    return desire;
}

void MultiMapFixed::AddToPlayer() {
    // Original at 0x004015b0: no-op in base class
}

void MultiMapFixed::RemoveFromPlayer() {
    // Original at 0x004015c0: no-op in base class
}

uint32_t MultiMapFixed::DoResourceAdding(RESOURCE_TYPE /*type*/, GInterfaceStatus* /*iface*/, bool /*param3*/, MapCoords* /*param4*/, int /*param5*/) {
    // Original at 0x00422070 — complex
    // TODO: implement properly
    return 0;
}

uint32_t MultiMapFixed::DoResourceRemoving(RESOURCE_TYPE /*type*/, uint32_t /*param2*/, GInterfaceStatus* /*iface*/, bool /*param4*/) {
    // Original at 0x00422080 — complex
    // TODO: implement properly
    return 0;
}

int MultiMapFixed::CalulateAmountOverMaximum(RESOURCE_TYPE /*type*/) {
    // Original at 0x004015d0
    return 0;
}

void MultiMapFixed::SetTown(Town* /*town*/) {
    // Original at 0x00422090 — complex
    // TODO: implement properly
}

void MultiMapFixed::RemovePotFromStructure(PotStructure* structure) {
    // Original at 0x00505330: delegates to building_site
    if (building_site != nullptr) {
        building_site->RemovePotFromStructure(structure);
    }
}

bool MultiMapFixed::GetShouldNotBeAddedToPlanned() {
    // Original at 0x004220b0 — complex
    // TODO: implement properly
    return false;
}

void MultiMapFixed::SetShouldNotBeAddedToPlanned(bool /*value*/) {
    // Original at 0x004220c0 — complex
    // TODO: implement properly
}

void MultiMapFixed::BuildBy(float amount) {
    // Original at 0x00504f90: increments build or repair progress
    if (!IsBuilt()) {
        // Building phase: advance percent_built
        float current = percent_built;
        percent_built = amount + current;
        if (percent_built < 0.0f) {
            percent_built = 0.0f;
        }
        if (percent_built >= 1.0f) {
            Built();
        }
    } else if (!IsRepaired()) {
        // Repair phase: increase life toward 1.0
        IncreaseLife(amount);
        if (GetLife() >= 1.0f) {
            Repaired();
        }
    }
}

PlannedMultiMapFixed* MultiMapFixed::ConvertToPlanned() {
    // Original at 0x00438d90 — complex
    // TODO: implement properly
    return nullptr;
}

void MultiMapFixed::CreateCollideData() {
    // Original at 0x0052f550 — complex
    // TODO: implement properly
}
