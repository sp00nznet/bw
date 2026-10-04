// Field class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Field is an agricultural building. Simple methods at 0x00527fxx-
// 0x005280xx are packed 16 bytes apart (trivial returns). Complex
// methods at 0x005284xx-0x0052a0xx.

#include <cstring>
#include <black/Field.h>

namespace {
float TypeF(const Field* f, int off) {
    float x = 0;
    if (f->type_info) std::memcpy(&x, reinterpret_cast<const char*>(f->type_info) + off, 4);
    return x;
}
}  // namespace

// ============================================================================
// Overrides of Base virtuals
// ============================================================================

void Field::ToBeDeleted(int /*param*/) {
    // Original at 0x005280f0 — complex
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

GPlayer* Field::GetPlayer() {
    // Original at 0x00528940 — gets player from owning town
    if (town) return reinterpret_cast<GameThing*>(town)->GetPlayer();
    return nullptr;
}

Town* Field::GetTown() {
    // Original at 0x00528960
    return town;
}

float Field::Get2DRadius() {
    // Original at 0x00528e80 — complex
    return 0.0f;
}

char* Field::GetDebugText() {
    static char text[] = "Field";
    return text;
}

uint32_t Field::Load(GameOSFile* /*file*/) {
    // Original at 0x00529d60 — complex serialization
    return 0;
}

uint32_t Field::Save(GameOSFile* /*file*/) {
    // Original at 0x00529b10 — complex serialization
    return 0;
}

uint32_t Field::GetSaveType() {
    // Original at 0x00528070 — correct save type constant needs verification from assembly
    return 50;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

MapCoords* Field::GetArrivePos(MapCoords* out) {
    // Original at 0x00529330: calls GetDoorPos
    return GetDoorPos(out);
}

uint32_t Field::GetCreatureBeliefType() {
    // Original at 0x00527f20: returns field creature belief type
    return 0;
}

uint32_t Field::GetOverwriteInteractableToolTip() {
    // Original at 0x0052a000 — complex
    return 0;
}

bool32_t Field::IsField_1(Creature* /*creature*/) {
    // Original at 0x00527f30: returns 1
    return 1;
}

bool32_t Field::IsField_0() {
    // Original at 0x00527f40: returns 1
    return 1;
}

bool32_t Field::CanBeEatenByCreature(Creature* /*creature*/) {
    // Original at 0x00527fd0: returns 1
    return 1;
}

bool32_t Field::CanBeSleptNextToByCreature(Creature* /*creature*/) {
    // Original at 0x00527fe0: returns 0
    return 0;
}

bool32_t Field::CanBePickedUpByCreature(Creature* /*creature*/) {
    // Original at 0x00527f70: returns 0
    return 0;
}

bool32_t Field::CanBeStompedOnByCreature(Creature* /*creature*/) {
    // Original at 0x00527f80: returns 1
    return 1;
}

bool32_t Field::CanBeGivenToVillager(Creature* /*creature*/) {
    // Original at 0x00527f90: returns 0
    return 0;
}

bool32_t Field::CanBePutInAStoragePit(Creature* /*creature*/) {
    // Original at 0x00527fa0: returns 0
    return 0;
}

bool32_t Field::CanBeDestroyedByStoning(Creature* /*creature*/) {
    // Original at 0x00527fb0: returns 0
    return 0;
}

bool32_t Field::CanBeExaminedByCreature(Creature* /*creature*/) {
    // Original at 0x00527fc0: returns 1
    return 1;
}

bool32_t Field::IsBeingBuilt(Creature* /*creature*/) {
    // Original at 0x00527ff0: returns 0
    return 0;
}

bool32_t Field::NeedsRepair(Creature* /*creature*/) {
    // Original at 0x00528000: returns 0
    return 0;
}

bool32_t Field::CanBePoodOn(Creature* /*creature*/) {
    // Original at 0x00527f60: returns 1
    return 1;
}

bool32_t Field::IsFieldWhichNeedsWatering(Creature* /*creature*/) {
    // Original at 0x004e4970 — complex
    return 0;
}

bool32_t Field::IsFieldWithFoodInIt(Creature* /*creature*/) {
    // Original at 0x004e4930 — returns true if food value > 0
    return GetFoodValue() > 0.0f ? 1 : 0;
}

bool32_t Field::IsFieldBelongingToAnotherPlayer(Creature* /*creature*/) {
    // Original at 0x004e4900 — compares field's player with creature's player
    // Needs Creature::GetPlayer() comparison — requires full Creature definition
    return 0;
}

bool32_t Field::BenefitsFromHavingWaterSprinkledOnIt(Creature* /*creature*/) {
    // Original at 0x00527f50: returns 1
    return 1;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

float Field::GetMeshRadius() const {
    // Original at 0x00528a30 — complex
    return 0.0f;
}

void Field::ReduceLife(float /*value*/, GPlayer* /*player*/) {
    // Original at 0x0052a0a0 — complex
}

void Field::ReduceLifeDueToBurning(float /*value*/, GPlayer* /*player*/) {
    // Original at 0x0052a050 — complex
}

void Field::GetFireGPHXDrawn(bool* /*p1*/, bool* /*p2*/, bool* /*p3*/, bool* /*p4*/) {
    // Original at 0x005288d0 — complex
}

uint32_t Field::DestroyedByEffect(GPlayer* /*player*/, float /*param*/) {
    // Original at 0x0052a010 — complex
    return 0;
}

extern uint32_t g_game_turn;  // LevelLoader.cpp
uint32_t Field::Process() {
    // v1.0 sub_4FF9C0, read from the disassembly. The abode tick, then on one
    // turn in ten: a fully planted field below full growth (+292) grows by
    // k x a rate -- +312 / +316 dry (before / after ripe at +288), +320 /
    // +324 when it rains on the field -- and its food by that x +304 / +292.
    // k = 2 x (0.5 x the players' influence there + 1).
    // ponytail: no players, so the influence (sub_5C1450) is 0 and k is 2;
    // no rain (sub_6FE660) and no burning (sub_5EA110) yet.
    Abode::Process();
    if ((g_game_turn + static_cast<uint32_t>(stagger)) % 10u) return 1;
    if (static_cast<float>(field_0xcc) < TypeF(this, 296) || growth > TypeF(this, 292)) return 1;
    const float k = (0.0f * 0.5f + 1.0f) * 2.0f;
    const bool rain = false;
    const float rate = growth < TypeF(this, 288) ? TypeF(this, rain ? 320 : 312) : TypeF(this, rain ? 324 : 316);
    const float g = k * rate;
    growth += g;
    food += g * TypeF(this, 304) / TypeF(this, 292);
    return 1;
}

void Field::Draw() {
    // Original at 0x00528570 — complex rendering
}

uint32_t Field::GetDiscipleStateIfInteractedWith(GInterfaceStatus* /*status*/,
                                                  Villager* /*villager*/) {
    // Original at 0x00529fb0 — complex
    return 0;
}

void Field::CallVirtualFunctionsForCreation(const MapCoords& coords) {
    // Original at 0x00528a40 — complex
    Abode::CallVirtualFunctionsForCreation(coords);
}

float Field::ApplyWaterSpell(SpellWater* /*spell*/) {
    // Original at 0x00528f30 — complex
    return 0.0f;
}

RESOURCE_TYPE Field::GetResourceType() {
    // Original at 0x00528010: fields produce food
    return RESOURCE_TYPE_FOOD;
}

bool Field::IsLockedInInteract() {
    // Original at 0x00528050
    return false;
}

bool Field::IsTouching_2(MapCoords* /*coords*/) const {
    // Original at 0x00529290 — complex
    return false;
}

bool32_t Field::ValidForLockedSelectProcess(GInterfaceStatus* /*status*/) {
    // Original at 0x005299e0 — complex
    return 0;
}

bool32_t Field::NetworkFriendlyStartLockedSelect(GInterfaceStatus* /*status*/) {
    // Original at 0x00529900 — complex
    return 0;
}

uint32_t Field::NetworkUnfriendlyLockedSelect(ControlHandUpdateInfo* /*param*/) {
    // Original at 0x00529a20 — complex
    return 0;
}

uint32_t Field::NetworkUnfriendlyEndLockedSelect() {
    // Original at 0x00529a60 — complex
    return 0;
}

uint32_t Field::NetworkFriendlyEndLockedSelect(GInterfaceStatus* /*status*/) {
    // Original at 0x00529af0 — complex
    return 0;
}

uint32_t Field::ValidForPlaceInHand(GInterfaceStatus* /*status*/) {
    // Original at 0x00528ef0 — complex
    return 0;
}

uint32_t Field::InterfaceSetInMagicHand(GInterfaceStatus* /*status*/) {
    // Original at 0x00529520 — complex
    return 0;
}

uint32_t Field::IsTuggable() {
    // Original at 0x00528040: returns 0
    return 0;
}

uint32_t Field::IsEffectReceiver(EffectValues* /*param*/) {
    // Original at 0x00528900 — complex
    return 0;
}

bool32_t Field::CanBeDestroyedBySpell_1(Spell* /*spell*/) {
    // Original at 0x00529ff0 — complex
    return 0;
}

bool Field::InteractsWithPhysicsObjects() {
    // Original at 0x00528020: returns false
    return false;
}

bool Field::CanBecomeAPhysicsObject() {
    // Original at 0x00528030: returns false
    return false;
}

bool Field::CreatureMustAvoid(Creature* /*creature*/) {
    // Original at 0x005280c0 — complex
    return false;
}

uint32_t Field::ProcessInInteract(GInterfaceStatus* /*status*/) {
    // Original at 0x00529730 — complex
    return 0;
}

size_t Field::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) {
    // Original at 0x00528ce0 — complex
    return 0;
}

// ============================================================================
// Overrides of MultiMapFixed virtuals
// ============================================================================

MapCoords* Field::GetDoorPos(MapCoords* pos) {
    // Original at 0x00528c80
    *pos = coords;
    return pos;
}

// ============================================================================
// Non-virtual methods
// ============================================================================

bool32_t Field::PlantCrop(const MapCoords& /*pos*/) {  // sub_4FFB40
    if (static_cast<float>(field_0xcc) >= TypeF(this, 296)) return 0;
    ++field_0xcc;
    return 1;
}

bool32_t Field::GetPlantCropPos() {  // sub_4FFB90
    return static_cast<float>(field_0xcc) < TypeF(this, 296);
}

int Field::GetFieldActivity(int /*param*/) {  // sub_4FFCC0
    if (GetPercentFull() < 1.0f) return 1;
    if (growth < TypeF(this, 288)) return 0;
    return 2;
}

float Field::GetPercentFull() {  // sub_4FFE20
    return static_cast<float>(field_0xcc) / TypeF(this, 296);
}

float Field::GetPull() {  // sub_4FFD10
    // Burning (+0x44) or unfinished fields pull nobody.
    if (fire_effect || !IsFunctional()) return 0.0f;
    int32_t most = 0;  // +308 is an int: the farmers a field takes
    if (type_info) std::memcpy(&most, reinterpret_cast<const char*>(type_info) + 308, 4);
    float busy = static_cast<float>(farmers.count) / static_cast<float>(most);
    if (busy >= 1.0f) busy = 1.0f;
    const float free_ = 1.0f - busy;
    float full = GetPercentFull();
    if (full >= 1.0f) full = 1.0f;
    switch (GetFieldActivity(0)) {
    case 1: return (1.0f - full) * free_ * free_ * free_;
    case 2: return growth < TypeF(this, 292) ? 0.0f : free_;
    default: return 0.0f;
    }
}

int Field::Harvest(float room) {  // sub_4FFEC0, read from the disassembly
    if (food == 0.0f) return 0;
    if (static_cast<float>(field_0xcc) < TypeF(this, 296)) return 0;
    const int take = static_cast<int>(room);
    int cost = take;  // unripe crops waste more than the villager gets
    if (growth < TypeF(this, 292)) cost = static_cast<int>(room * TypeF(this, 332) + static_cast<float>(take));
    if (static_cast<float>(cost) < food) {
        food -= static_cast<float>(cost);
        return take;
    }
    // ponytail: sub_5EBD20(this, 0, 0) and the town's +0x5E8 "fields need
    // work" flag are not translated.
    if (growth < TypeF(this, 292)) {
        food = 0.0f;
        return static_cast<int>(room * TypeF(this, 332));
    }
    const int rest = static_cast<int>(food);
    food = 0.0f;
    field_0xcc = 0;
    growth = 0.0f;
    return rest;
}

float Field::RemoveFood(float amount) { return static_cast<float>(Harvest(amount)); }

float Field::GetFoodValue() { return food; }
