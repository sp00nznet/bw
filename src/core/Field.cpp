// Field class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Field is an agricultural building. Simple methods at 0x00527fxx-
// 0x005280xx are packed 16 bytes apart (trivial returns). Complex
// methods at 0x005284xx-0x0052a0xx.

#include <black/Field.h>

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
    // Original at 0x00528940 — complex (may derive from town)
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
    // Original at 0x00528070
    return 0;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

MapCoords* Field::GetArrivePos(MapCoords* out) {
    // Original at 0x00529330: calls GetDoorPos
    return GetDoorPos(out);
}

uint32_t Field::GetCreatureBeliefType() {
    // Original at 0x00527f20
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
    // Original at 0x004e4930 — complex
    return 0;
}

bool32_t Field::IsFieldBelongingToAnotherPlayer(Creature* /*creature*/) {
    // Original at 0x004e4900 — complex
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

uint32_t Field::Process() {
    // Original at 0x00529020 — complex
    return 0;
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
    // Original at 0x00528010: returns RESOURCE_TYPE for food
    return RESOURCE_TYPE(0);
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

bool32_t Field::PlantCrop(const MapCoords& /*pos*/) {
    // Original at 0x005291a0 — complex
    return 0;
}

bool32_t Field::GetPlantCropPos() {
    // Original at 0x00529210 — complex
    return 0;
}

int Field::GetFieldActivity(int /*param*/) {
    // Original at 0x00529350 — complex
    return 0;
}

float Field::GetPercentFull() {
    // Original at 0x00529500 — complex
    return 0.0f;
}

float Field::RemoveFood(float /*amount*/) {
    // Original at 0x005295a0 — complex
    return 0.0f;
}

float Field::GetFoodValue() {
    // Original at 0x00529700 — complex
    return 0.0f;
}
