// BuildingSite — building construction management
// Method stubs from bw1-decomp
#include "../include/black/BuildingSite.h"
#include "../include/black/MultiMapFixed.h"
#include "../include/black/LHRandom.h"

#include <cmath>
#include <cstring>

// === New virtual methods (BuildingSite-specific vtable extensions) ===

// 0x0043b950
void BuildingSite::Init() {}
void BuildingSite::Process() {}
uint32_t BuildingSite::GetWoodForStats() { return 0; }
Pot* BuildingSite::GetPileWood(const MapCoords& /*coords*/) { return nullptr; }
void BuildingSite::SetPileWood(Pot* /*pile*/) {}
void BuildingSite::CreatePileWood() {}
void BuildingSite::GetResourcePosAndYAngle(uint32_t /*type*/, uint32_t /*param2*/, float* /*out*/) {}
void BuildingSite::RemovePotFromStructure(PotStructure* /*structure*/) {}
bool BuildingSite::IsLinkedToThisBuildingSite(Pot* /*pot*/) { return false; }
float BuildingSite::GetNearestEdge(float /*x*/, float /*y*/, int* /*out*/) { return 0.0f; }
void BuildingSite::GetNextPosFromIndex(int* /*index*/) {}
void BuildingSite::GetRandomBuildPos(Object* /*object*/, int* /*out*/) {}

// === Overrides of Base virtuals ===

// 0x0043b7b0
BuildingSite::~BuildingSite() {}
// 0x0043b960
void BuildingSite::ToBeDeleted(int /*param*/) {}

// === Overrides of GameThing virtuals ===

// 0x0043c0b0 — returns the town from the root building
Town* BuildingSite::GetTown() {
    MultiMapFixed* building = GetRootBuilding();
    if (building) return building->GetTown();
    return nullptr;
}

// 0x0043d050 — returns radius from root building
float BuildingSite::GetRadius() {
    MultiMapFixed* building = GetRootBuilding();
    if (building) return building->GetRadius();
    return 0.0f;
}

// 0x0043c5b0
uint32_t BuildingSite::GetResource(RESOURCE_TYPE type) {  // sub_434C60: the pile's
    return static_cast<int>(type) == 1 ? pile_wood : 0;
}
// 0x0043c490
uint32_t BuildingSite::AddResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus*, bool, const MapCoords&, int) {
    // sub_434B40: wood only, onto the pile. ponytail: the town's wood-on-sites
    // statistic (town +1800) is not kept.
    if (static_cast<int>(type) != 1) return 0;
    pile_wood += amount;
    return amount;
}
// 0x0043c530
uint32_t BuildingSite::RemoveResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus*, bool*) {  // sub_434BE0
    if (static_cast<int>(type) != 1) return 0;
    if (amount > pile_wood) amount = pile_wood;
    pile_wood -= amount;
    return amount;
}
// 0x0043cad0
uint32_t BuildingSite::Load(GameOSFile* /*file*/) { return 0; }
// 0x0043c830
uint32_t BuildingSite::Save(GameOSFile* /*file*/) { return 0; }
// 0x0043b7a0
uint32_t BuildingSite::GetSaveType() { return 0; }

// === Non-virtual methods ===

namespace {
uint32_t SiteInfoU(const MultiMapFixed* b, int off) { uint32_t x = 0; if (b && b->info) std::memcpy(&x, reinterpret_cast<const char*>(b->info) + off, 4); return x; }
}  // namespace

MultiMapFixed* BuildingSite::Building() { return root_building && root_building->IsAvailable() ? root_building : nullptr; }

bool BuildingSite::Unfinished() {
    MultiMapFixed* b = Building();
    return b && (!b->IsBuilt() || !b->IsRepaired());
}

int BuildingSite::BuildersWanted() {
    MultiMapFixed* b = Building();
    if (!b) return 0;
    if (b->IsBuilt() && (b->IsRepaired() || b->GetLife() == 0.0f)) return 0;
    return static_cast<int>(SiteInfoU(b, 272)) - static_cast<int>(builders);
}

float BuildingSite::Remaining() {
    const float wanted = static_cast<float>(SiteInfoU(Building(), 272));
    float r = (wanted ? static_cast<float>(BuildersWanted()) / wanted : 0.0f) + field_0x63c;
    return r < 0.0f ? 0.0f : (r > 1.0f ? 1.0f : r);
}

float BuildingSite::FullCost() {
    // ponytail: the original divides by the site's player's +124; there are
    // no players yet, so 1.
    MultiMapFixed* b = Building();
    return b ? static_cast<float>(SiteInfoU(b, 108)) * b->GetScale() : 0.0f;
}

float BuildingSite::StillRequired() {  // sub_434CA0
    MultiMapFixed* b = Building();
    if (!b) return 0.0f;
    const float left = b->IsBuilt() ? 1.0f - b->GetLife() : 1.0f - b->GetPercentBuilt();
    return FullCost() * left - static_cast<float>(pile_wood);
}

void BuildingSite::AddBuilder(Villager* v) {  // sub_434630 (it adds even a builder already listed)
    if (v) building_worker_list.Add(v);
    ++builders;
}

void BuildingSite::RemoveBuilder(Villager* v) {  // sub_434680
    if (building_worker_list.head) building_worker_list.Remove(v);
    --builders;
}

MapCoords BuildingSite::PosAt(uint32_t i) {
    const LHPoint& p = building_positions[i & 0x7F];
    return MapCoords(static_cast<int32_t>(p.x * kMapUnitsPerMetre), static_cast<int32_t>(p.z * kMapUnitsPerMetre), 0.0f);
}

MapCoords BuildingSite::RandomBuildPos(const Object* who, uint32_t* index) {
    // sub_435490: the heading from the building to the villager, give or
    // take 45 degrees, picks one of the 128 positions (sub_4354F0).
    MultiMapFixed* b = Building();
    if (!b) return MapCoords(0, 0, 0.0f);
    float a = std::atan2(static_cast<float>(who->coords.z - b->coords.z), static_cast<float>(who->coords.x - b->coords.x));
    a += lh::RandomFloat(1.5707964f) - 0.78539819f;
    while (a < 0.0f) a += 6.2831855f;
    while (a > 6.2831855f) a -= 6.2831855f;
    const uint32_t i = static_cast<uint32_t>(static_cast<int>(a * 0.15915494f * 128.0f)) & 0x7F;
    if (index) *index = i;
    return PosAt(i);
}

MapCoords BuildingSite::NextBuildPos(uint32_t* index) {
    // sub_4355F0: on round the building by about 2-3 m, either way.
    MultiMapFixed* b = Building();
    if (!b || !index) return MapCoords(0, 0, 0.0f);
    const float r = b->GetRadius() > 0.0f ? b->GetRadius() : 1.0f;
    const float step = 2.0f / (r * 6.2831855f * 0.0078125f);
    const int n = static_cast<int>(lh::RandomFloat(step * 0.5f) + step);
    int i = static_cast<int>(*index) + n * (lh::Random(2) != 0 ? 1 : -1);
    i = i < 128 ? (i < 0 ? i + 128 : i) : i - 128;
    *index = static_cast<uint32_t>(i);
    return PosAt(*index);
}

void BuildingSite::Construct(MultiMapFixed* building) {
    // sub_433FE0. ponytail: not on the game's global site list (+2104680).
    root_building = building;
    field_0x638 = (building->field_0x58 >> 2) & 1;
    building->building_site = this;  // sub_5046F0: building +0x74
    life = building->GetLife();
    // A built building that has lost life is being repaired.
    if (building->IsBuilt() && building->GetLife() < 1.0f) life = building->GetLife() * 1.1f - 0.1f;
    // sub_435460 -> sub_433670: 128 positions round the building's outline.
    // ponytail: a circle at the building's radius stands in for the mesh outline.
    const float r = building->GetRadius() > 0.0f ? building->GetRadius() : 2.0f;
    for (int i = 0; i < 128; ++i) {
        const float a = static_cast<float>(i) * 6.2831855f / 128.0f;
        building_positions[i].x = MetresOf(building->coords.x) + std::cos(a) * r;
        building_positions[i].y = 0.0f;
        building_positions[i].z = MetresOf(building->coords.z) + std::sin(a) * r;
    }
}


// 0x0043bc70 — returns the building this site is constructing
MultiMapFixed* BuildingSite::GetBuilding() {
    return root_building;
}

// 0x0043bca0 — returns the root building (same as GetBuilding for base class)
MultiMapFixed* BuildingSite::GetRootBuilding() {
    return root_building;
}

// 0x0043bde0 — returns the clear area radius from the root building's info
float BuildingSite::GetClearAreaRadius() {
    MultiMapFixed* building = GetRootBuilding();
    if (building) return building->GetRadius();
    return 0.0f;
}

// 0x0043be00 — delegates to root building's desire-to-be-repaired
float BuildingSite::GetDesireToBeRepaired() {
    MultiMapFixed* building = GetRootBuilding();
    if (building) return building->GetDesireToBeRepaired();
    return 0.0f;
}

// 0x0043c0c0
float BuildingSite::GetWoodValue() { return 0.0f; }
// 0x0043c5f0
float BuildingSite::GetWoodNeededToBuild() { return 0.0f; }
// 0x0043c680
bool32_t BuildingSite::ShouldIGetWood(Villager* /*villager*/) { return 0; }

// 0x0043d080 — delegates building progress to root building
void BuildingSite::BuildBy(float amount) {
    MultiMapFixed* building = GetRootBuilding();
    if (building) {
        building->BuildBy(amount);
    }
}
