// Object class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Object adds 3D representation, life, angles, scale, and the enormous
// interface/interaction virtual method set. Most methods return defaults
// here and are overridden by Living, Villager, Tree, Abode, etc.

#include <black/Object.h>

// ============================================================================
// Orientation and scale (vtable 0x500-0x528)
// ============================================================================

void Object::DestroyedByBeam() {}

float Object::GetXAngle() {
    return 0.0f;
}

float Object::GetYAngle() {
    // Reads y_angle field at offset 0x4C
    return y_angle;
}

float Object::GetZAngle() {
    return 0.0f;
}

void Object::SetFocus(const LHPoint* /*focus*/) {}

void Object::SetXYZAngles(float /*x*/, float /*y*/, float /*z*/) {}
void Object::SetXYZAnglesAndScale(float /*x*/, float /*y*/, float /*z*/, float /*scale*/) {}

void Object::SetJustScale(float s) {
    // Writes to scale field at offset 0x50
    scale = s;
}

void Object::SetYJustAngle(float /*angle*/) {}

void Object::SetYAngle(float /*angle*/) {}

void Object::UpdateFrom3DPosition() {
    // Default: no-op
}

uint32_t Object::MoveAlongPath() {
    return 1;
}

// ============================================================================
// Map and 3D object management (vtable 0x530-0x56C)
// ============================================================================

bool Object::IsReachable() {
    // Delegates to IsAvailable through vtable
    // Original at 0x00402560: jmp [eax + 0x2c] = vtable slot for IsAvailable
    return IsAvailable();
}

// IsMoving: checks if XZ position differs from stored obj_coords
bool Object::IsMoving() const {
    return coords.x != obj_coords.x || coords.z != obj_coords.z;
}

bool Object::BlocksTownClearArea() const {
    return false;
}

void Object::Create3DObject() {}

Object* Object::GetMapChild(const MapCell* /*cell*/) {
    return nullptr;
}

void Object::SetMapChild(Object* /*object*/, MapCell* /*cell*/) {}
void Object::InsertMapObject() {}
void Object::RemoveMapObject() {}
void Object::InsertMapObjectToCell(MapCell* /*cell*/) {}
void Object::RemoveMapObjectFromCell(MapCell* /*cell*/) {}
bool Object::IsObjectInMap_1(MapCell* /*cell*/) { return false; }
bool Object::IsObjectInMapCheck() { return false; }
int Object::MoveMapObject(const MapCoords& /*coords*/) { return 0; }
void Object::ActualMoveMapObject(const MapCoords& /*coords*/) {}

Object* Object::GetPtr() {
    // Returns this pointer (identity cast)
    // Original at 0x00402570: mov eax, ecx; ret
    return this;
}

float Object::GetMeshRadius() const {
    return 0.0f;
}

Game3DObject* Object::Get3DObjectForPSys() {
    // Returns game_3d_object field at offset 0x40
    return game_3d_object;
}

// ============================================================================
// Particle system / fire (vtable 0x570-0x598)
// ============================================================================

bool Object::GetPSysFireFlameMatrix(LHMatrix* /*matrix*/) { return false; }
bool Object::GetPSysFireLocalRndFlamePos(LHPoint* /*point*/, int* /*param2*/) { return false; }
bool Object::GetPSysFireWorldFlamePos(const LHPoint*, int, LHPoint*) { return false; }
float Object::GetPSysFireLocalFlameScale() { return 0.0f; }
uint32_t Object::GetPSysFireMaxFlames() { return 0; }

float Object::GetSpotEffectPower() const {
    return 0.0f;
}

float Object::GetAggressorValueFromDamage(float /*param1*/) const {
    return 0.0f;
}

// ============================================================================
// Hold / interface (vtable 0x590-0x5AC)
// ============================================================================

HOLD_TYPE Object::GetHoldType() { return HOLD_TYPE_DEFAULT; }
float Object::GetHoldRadius() { return 0.0f; }
float Object::GetHoldLoweringMultiplier() { return 0.0f; }

float Object::GetHoldYRotate() {
    return 0.0f;
}

bool32_t Object::HandShouldFeelWithMeshIntersect() {
    return 1;
}

void Object::SetSpecularColor(LH3DColor /*color*/) {}

LH3DColor Object::GetSpecularColor() {
    LH3DColor c;
    c.color = 0;
    return c;
}

void Object::SetBeliefSprite(LH3DSprite* /*sprite*/) {}

LH3DSprite* Object::GetBeliefSprite() {
    return nullptr;
}

// ============================================================================
// Life and effects (vtable 0x5B0-0x5FC)
// ============================================================================

void Object::SetLife(float /*life*/) {}

bool Object::IsAlive() {
    // Checks GetLife() > 0.0 && IsAvailable()
    // Original at 0x00402610: complex FPU comparison + vtable call
    if (GetLife() > 0.0f) {
        return IsAvailable();
    }
    return false;
}

void Object::ReduceLife(float /*value*/, GPlayer* /*player*/) {}
void Object::IncreaseLife(float /*value*/) {}
float Object::GetSacrificeValue() { return 0.0f; }
void Object::ReduceLifeDueToBurning(float, GPlayer*) {}
void Object::FillInEffectDefenceMultiplier(EffectNumbers*) {}
void Object::ApplyEffect(EffectValues*, int) {}
float Object::GetDamageEffect(EffectValues*) { return 0.0f; }
float Object::GetHealEffect(EffectValues*) { return 0.0f; }
void* Object::GetActualObjectToEffect(GPlayer*, bool) { return nullptr; }
void Object::DrawValue(int, float) {}
void Object::ScaffoldMoved(Scaffold*) {}
float Object::GetHeatCapacity() { return 0.0f; }
void Object::GetFireGPHXDrawn(bool*, bool*, bool*, bool*) {}
float Object::GetRainCoolingMultiplier() { return 0.0f; }
LHPoint* Object::GetDefaultFireCentrePos(LHPoint* pos) { return pos; }
float Object::GetDefaultFireRadius() { return 0.0f; }
uint32_t Object::DestroyedByEffect(GPlayer*, float) { return 0; }

// ============================================================================
// Process / state (vtable 0x600-0x668)
// ============================================================================

uint32_t Object::Process() { return 0; }
uint32_t Object::ProcessBySpell(Spell*) { return 0; }
void Object::ApplySingleEffect(EFFECT_TYPE, float, GameThing*, const MapCoords*) {}
int Object::GetMesh() const { return 0; }
int Object::GetDetailMesh(int) { return 0; }
void Object::Draw() {}
void Object::DrawOutOfMap(bool) {}
bool Object::IsG3DObjectDrawnInHand() { return false; }
void Object::GetDrawRegion(LHRegion*) {}
uint32_t Object::ProcessState() { return 0; }
float Object::GetProjectileSpeed() { return 0.0f; }
bool Object::CanBePickedUp() { return false; }
bool32_t Object::CanBeCrushed() { return 0; }
float Object::GetTopPos() { return 0.0f; }
float Object::GetVillagerHugRadius() {
    // Original: GetScale() * 1.05 + 0.0005
    return GetScale() * 1.05f + 0.0005f;
}
float Object::GetWeight() { return 0.0f; }
void Object::GetWorldMatrix(LHMatrix*) {}
bool Object::CanBeSuckedIntoVortex(LandscapeVortex*) { return false; }
uint32_t Object::GetDiscipleStateIfInteractedWith(GInterfaceStatus*, Villager*) { return 0; }
MapCoords* Object::GetWorkingPos(MapCoords* out, Object*) { return out; }
float Object::GetHeightForHandAboveInteractObject() { return 0.0f; }
uint32_t Object::GetHandHelpMessageSet() { return 0; }
uint32_t Object::GetHandHelpCondition() { return 0; }
void Object::CallVirtualFunctionsForCreation(const MapCoords&) {}
LH3DObject_ObjectType Object::Get3DType() { return LH3D_OBJECT_TYPE_DEFAULT; }

// ============================================================================
// Food / resource (vtable 0x660-0x69C)
// ============================================================================

float Object::GetFoodValue(FOOD_TYPE) { return 0.0f; }
float Object::GetWoodValue() { return 0.0f; }
FOOD_TYPE Object::GetFoodType() { return FOOD_TYPE_0; }
float Object::GetImpressiveValue_1() { return 0.0f; }
bool Object::IsSpellSeedReturnPoint() const { return false; }
bool32_t Object::IsABeliever() { return 0; }
MultiMapFixed* Object::AsMultiMapFixed() { return nullptr; }
float Object::ApplyWaterSpell(SpellWater*) { return 0.0f; }
bool Object::IsResourceStore(RESOURCE_TYPE) { return false; }
bool Object::DeleteObjectAndTakeResource(Object*, GInterfaceStatus*) { return false; }
float Object::GetRadiusMultiplierForApplyingPotToPos() { return 0.0f; }
bool Object::DoCreatureMimicAfterAddingResource(RESOURCE_TYPE, GInterfaceStatus*) { return false; }

RESOURCE_TYPE Object::GetResourceType() {
    // Returns -1 (no resource)
    return static_cast<RESOURCE_TYPE>(0xFFFFFFFF);
}

int Object::GetDefaultResource() { return 0; }
void Object::SetPoisonedResource(RESOURCE_TYPE, int) {}
void Object::SetPoisoned(int) {}

// ============================================================================
// Combat / interaction (vtable 0x6A0-0x6CC)
// ============================================================================

bool Object::IsLockedInInteract() { return false; }
bool Object::SetDying() {
    // Original: calls SetLife(0.0f) then returns true
    SetLife(0.0f);
    return true;
}
bool Object::IsAttackable(Object*) { return false; }
bool Object::IsAllied(Object*) { return false; }
bool Object::IsTouching_1(MapCoords*, MapCoords*) const { return false; }
bool Object::IsTouching_2(MapCoords*) const { return false; }
bool Object::IsTouching_3(Object*, float) const { return false; }
void Object::StartOnFire() {}
void Object::EndOnFire() {}
float Object::GetDistanceFromObject_1(Object*) { return 0.0f; }
float Object::GetTribalPower(TRIBE_TYPE) { return 0.0f; }

// ============================================================================
// Interface / network (vtable 0x6D0-0x778)
// ============================================================================

bool32_t Object::ValidForLockedSelectProcess(GInterfaceStatus*) { return 0; }

bool32_t Object::NetworkFriendlyStartLockedSelect(GInterfaceStatus*) {
    return 1;  // Network-friendly operations default to true
}

bool32_t Object::NetworkUnfriendlyStartLockedSelect() { return 0; }
bool32_t Object::IsReadyForNetworkUnfriendlyLockedSelect() { return 0; }
bool32_t Object::NetworkUnfriendlyLockedSelect(ControlHandUpdateInfo*) { return 0; }
bool32_t Object::GetReadyForNetworkUnfriendlyEndLockedSelect() { return 0; }
bool32_t Object::IsReadyForNetworkUnfriendlyEndLockedSelect() { return 0; }
bool32_t Object::NetworkUnfriendlyEndLockedSelect() { return 0; }

bool32_t Object::NetworkFriendlyEndLockedSelect(GInterfaceStatus*) {
    return 1;
}

bool32_t Object::ValidAsInterfaceTarget() { return 0; }
bool32_t Object::ValidAsInterfaceLeashTarget() { return 0; }
bool32_t Object::SelectOnlyAfterRecSystem() { return 0; }
bool32_t Object::ValidForPlaceInHand(GInterfaceStatus*) { return 0; }
bool32_t Object::InterfaceSetInMagicHand(GInterfaceStatus*) { return 0; }
bool32_t Object::InterfaceSetOutMagicHand(GInterfaceStatus*) { return 0; }
bool32_t Object::ValidToRemoveFromHand(GInterfaceStatus*, const MapCoords*) { return 0; }
uint32_t Object::RemoveFromHand(GInterfaceStatus*, const MapCoords*) { return 0; }
bool32_t Object::ValidToShakeFromHand() { return 0; }
bool32_t Object::InterfaceMustBeInInfluenceForInteraction() { return 0; }
bool32_t Object::IsTuggable() { return 0; }
uint32_t Object::ValidToApplyThisToObject(GInterfaceStatus*, Object*) { return 0; }
uint32_t Object::ApplyThisToObject(GInterfaceStatus*, Object*, GestureSystemPacketData*) { return 0; }
uint32_t Object::ValidToApplyThisToMapCoord(GInterfaceStatus*, const MapCoords*) { return 0; }
uint32_t Object::ApplyThisToMapCoord(GInterfaceStatus*, const MapCoords*, GestureSystemPacketData*) { return 0; }
uint32_t Object::ValidForLockedApplyProcess(GInterfaceStatus*) { return 0; }
uint32_t Object::ApplyUnlockProcess(GInterfaceStatus*) { return 0; }
uint32_t Object::IsInterfacePowerUpWhenInHand() const { return 0; }
uint32_t Object::ApplyOnlyAfterRecSystem() { return 0; }
uint32_t Object::ApplyOnlyAfterReleased() { return 0; }
uint32_t Object::InterfaceValidToTap(GInterfaceStatus*) { return 0; }
uint32_t Object::InterfaceTap(GInterfaceStatus*) { return 0; }
uint32_t Object::InterfaceValidToGiveObject(GInterfaceStatus*, Object*) { return 0; }
uint32_t Object::InterfaceGiveObject(GInterfaceStatus*, Object*) { return 0; }
uint32_t Object::InterfaceValidToInteractAsMapCoordsObject(GInterfaceStatus*) { return 0; }
uint32_t Object::InterfaceInteractAsMapCoordsObject(GInterfaceStatus*) { return 0; }
uint32_t Object::ThrowObjectFromHand(GInterfaceStatus*, int) { return 0; }
uint32_t Object::ValidToSelectFightThisToMapCoord(GInterfaceStatus*, const MapCoords*) { return 0; }
uint32_t Object::ValidToApplyFightThisToMapCoord(GInterfaceStatus*, const MapCoords*) { return 0; }
uint32_t Object::SelectFightThisToMapCoord(GInterfaceStatus*, const MapCoords*) { return 0; }
uint32_t Object::ApplyFightThisToMapCoord(GInterfaceStatus*, const MapCoords*) { return 0; }
uint32_t Object::ValidToFightThisToObject(GInterfaceStatus*, const MapCoords*) { return 0; }
uint32_t Object::FightThisToObject(GInterfaceStatus*, Object*) { return 0; }
bool32_t Object::IsEffectReceiver(EffectValues*) { return 0; }
bool32_t Object::CanBeDestroyedBySpell_1(Spell*) { return 0; }
float Object::GetImportance() { return 0.0f; }

// ============================================================================
// Physics (vtable 0x780-0x7B4)
// ============================================================================

uint32_t Object::InitialisePhysicsFromHand(LHPoint*, LHPoint*, GInterfaceStatus*, Object*, int) { return 0; }
uint32_t Object::InitialisePhysics(const LHPoint*, const LHPoint*, Object*, bool, GInterfaceStatus*) { return 0; }
uint32_t Object::GetPhysicsConstantsType() { return 0; }
void Object::SetUpPhysOb(PhysOb*) {}
void Object::EndPhysics(PhysicsObject*, bool) {}
uint32_t Object::DropSfx() { return 0; }
void Object::GetBoundingSphere(LHPoint*, float*) {}
bool Object::InteractsWithPhysicsObjects() { return false; }
uint32_t Object::ChecksVerticesVObjects() { return 0; }
void Object::ShouldPhysicsRaiseObjectUntilNotIntersectingThis(Object*) {}
uint32_t Object::PhysicallyDestroysAbodes() { return 0; }
void Object::ReactToPhysicsImpact(PhysicsObject*, bool) {}
bool Object::CanBecomeAPhysicsObject() { return false; }
bool Object::GetAlwaysRemainsInPhysicsInternalSystem() { return false; }
bool Object::HasSunk() { return false; }

// ============================================================================
// Creature avoidance / route (vtable 0x7BC-0x7D8)
// ============================================================================

bool Object::CreatureMustAvoid(Creature*) { return false; }
void Object::AddToRoutePlan(RPHolder*, Creature*, int, void (*)(int, Point2D, float, int)) {}
float Object::GetRoutePlanRadius(Creature*) { return 0.0f; }
bool32_t Object::VillagerMustAvoid(Villager*) { return 0; }
bool Object::IsFireMan() { return false; }
bool Object::IsARootedObject() { return false; }
SOUND_COLLISION_TYPE Object::GetCollideSoundType() { return SOUND_COLLISION_TYPE_NONE; }
bool32_t Object::IsSolidToNewAbode() { return 0; }
uint32_t Object::RemoveFromGame() { return 0; }

// ============================================================================
// Miscellaneous (vtable 0x7E0-0x858)
// ============================================================================

int Object::GetLandingPointCount() { return 0; }
bool Object::GetLandingPoint(uint8_t, LHPoint*) { return false; }
uint32_t Object::GetTastiness() { return 0; }
bool Object::IsScary() { return false; }
bool Object::GetInspectObjectPos(Villager*, MapCoords*) { return false; }
void Object::DiscipleInHandNear(Villager*, GInterfaceStatus*) {}
bool32_t Object::GetSpecialPos(uint32_t, MapCoords*) { return 0; }
GameThing* Object::GetTownArtifact() { return nullptr; }
bool32_t Object::IsTownArtifact() { return 0; }
bool Object::ProcessInHand() { return false; }
uint32_t Object::ProcessInInteract(GInterfaceStatus*) { return 0; }
uint32_t Object::GetObjectCollide() { return 0; }
float Object::CalculateForceAppliedBy(Living*) { return 0.0f; }
bool Object::IsPushable() { return false; }
void Object::PushObject_1(Living*, MapCoords*) {}
void Object::PushObject_2(Living*) {}
uint32_t Object::GetCarriedTreeType() { return 0; }
float Object::GetFacingPitch() { return 0.0f; }

void Object::SetHeadPos(MapCoords* param1) {
    // Copies this object's coords to the output
    // Original: copies 12 bytes from this->coords to param_1
    *param1 = coords;
}

size_t Object::SaveObject(LHOSFile*, const MapCoords*) { return 0; }
bool Object::IsAPotFromABuildingSite() { return false; }
void Object::GetNearestEdgeOfObject(Object*) {}
void Object::GetNearestPosOfObject(Object*) {}
void Object::GetNearestEdgeToPos(const MapCoords*) {}
void Object::GetNearestEdge(float, float) {}
IMMERSION_EFFECT_TYPE Object::GetImmersionTexture() { return IMMERSION_EFFECT_TYPE_NONE; }
IMMERSION_EFFECT_TYPE Object::GetInHandImmersionTexture() { return IMMERSION_EFFECT_TYPE_NONE; }
bool Object::ShouldFootpathsGoRound() { return false; }
void Object::InitialiseIsFixedForMapList() {}

uint32_t Object::StandAnimation() {
    // Returns 0xFFFFFFFF (-1)
    return 0xFFFFFFFF;
}

NewCollide* Object::GetCollideData() const {
    return nullptr;
}
