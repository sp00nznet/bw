// SpellSeed class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// SpellSeed is a one-shot spell pickup that can be grabbed and
// applied. Methods at 0x00727fxx are small (~16 bytes each).

#include <black/SpellSeed.h>

// ============================================================================
// Overrides of Base virtuals
// ============================================================================

void SpellSeed::ToBeDeleted(int param) {
    // Original at 0x00728280: cleanup and delegate to base
    Object::ToBeDeleted(param);
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

char* SpellSeed::GetDebugText() {
    // Original at 0x00727fb0: returns "SpellSeed"
    static char text[] = "SpellSeed";
    return text;
}

uint32_t SpellSeed::Load(GameOSFile* /*file*/) {
    // Original at 0x00729fb0 — complex serialization
    // Needs save system
    return 0;
}

uint32_t SpellSeed::Save(GameOSFile* /*file*/) {
    // Original at 0x00729ca0 — complex serialization
    // Needs save system
    return 0;
}

uint32_t SpellSeed::GetSaveType() {
    // Original at 0x00727fa0: returns 0x24
    return 0x24;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

uint32_t SpellSeed::GetCreatureBeliefType() {
    // Original at 0x00727f70: returns 0x12
    return 0x12;
}

uint32_t SpellSeed::GetOrigin() {
    // Original at 0x00727f80: returns 2
    return 2;
}

float SpellSeed::GetPower() const {
    // Original at 0x007298b0: reads power from field_0x54 area
    // Power is stored as a float within the opaque spell seed data
    return *reinterpret_cast<const float*>(&field_0x54[0x0]);
}

float SpellSeed::GetPSysPower() const {
    // Original at 0x007298f0: particle system power
    return GetPower();
}

WorshipSite* SpellSeed::GetWorshipSite() {
    // Original at 0x00728a00: returns associated worship site from field_0x54 area
    return *reinterpret_cast<WorshipSite**>(&field_0x54[0x4]);
}

bool32_t SpellSeed::IsSpellSeed() {
    // Original at 0x00727f50: returns 1
    return 1;
}

uint32_t SpellSeed::GetScriptObjectType() {
    // Original at 0x00729c90 — spell seeds are script type 0x10
    return 0x10;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

void SpellSeed::InsertMapObject() {
    // Original at 0x00728f30: spell seeds use base Object insertion
    Object::InsertMapObject();
}

void SpellSeed::RemoveMapObject() {
    // Original at 0x00728f40: spell seeds use base Object removal
    Object::RemoveMapObject();
}

HOLD_TYPE SpellSeed::GetHoldType() {
    // Original at 0x00728680 — spell seeds use hold type 4
    return static_cast<HOLD_TYPE>(4);
}

float SpellSeed::GetHoldRadius() {
    // Original at 0x00728640: return GetPower() * info->hold_radius_scale
    if (!info) return 0.0f;
    float scale = *reinterpret_cast<const float*>(
        reinterpret_cast<const char*>(info) + 0x150);
    return GetPower() * scale;
}

float SpellSeed::GetHoldLoweringMultiplier() {
    // Original at 0x00728660: reads from info at offset 0x14C
    if (!info) return 1.0f;
    return *reinterpret_cast<const float*>(
        reinterpret_cast<const char*>(info) + 0x14C);
}

float SpellSeed::GetHoldYRotate() {
    // Original at 0x00728670: reads from info at offset 0x154
    if (!info) return 0.0f;
    return *reinterpret_cast<const float*>(
        reinterpret_cast<const char*>(info) + 0x154);
}

bool32_t SpellSeed::HandShouldFeelWithMeshIntersect() {
    // Original at 0x00727f60: returns 0
    return 0;
}

int SpellSeed::GetMesh() const {
    // Original at 0x00729850: reads mesh from info at offset 0x100
    if (!info) return 0;
    return *reinterpret_cast<const int*>(
        reinterpret_cast<const char*>(info) + 0x100);
}

void SpellSeed::Draw() {
    // Original at 0x00518710 — renders spell seed visual with power glow
    // Needs rendering pipeline
}

void SpellSeed::DrawOutOfMap(bool /*param1*/) {
    // Original at 0x005190a0 — renders spell seed when held in hand
    // Needs rendering pipeline
}

bool SpellSeed::IsG3DObjectDrawnInHand() {
    // Original at 0x00728600 — spell seeds are drawn in hand
    return true;
}

void SpellSeed::CallVirtualFunctionsForCreation(const MapCoords& coords) {
    // Original at 0x00728360: sets up spell seed after spawning at worship site
    Object::CallVirtualFunctionsForCreation(coords);
}

bool32_t SpellSeed::ValidForPlaceInHand(GInterfaceStatus* /*status*/) {
    // Original at 0x00728580: spell seeds are always valid in hand
    return 1;
}

bool32_t SpellSeed::InterfaceSetInMagicHand(GInterfaceStatus* /*status*/) {
    // Original at 0x00728810: handles spell seed being picked up into magic hand
    // Starts power-up charge timer
    return 1;
}

bool32_t SpellSeed::InterfaceSetOutMagicHand(GInterfaceStatus* /*status*/) {
    // Original at 0x00728940: handles spell seed being released from magic hand
    // Stops power-up charge and finalizes power level
    return 1;
}

bool32_t SpellSeed::ValidToRemoveFromHand(GInterfaceStatus* /*status*/, const MapCoords* /*param2*/) {
    // Original at 0x00728760: checks if spell seed can be dropped at position
    return 1;
}

uint32_t SpellSeed::RemoveFromHand(GInterfaceStatus* /*status*/, const MapCoords* /*param2*/) {
    // Original at 0x00728f00: drops spell seed from hand at position
    return 1;
}

uint32_t SpellSeed::ValidToApplyThisToObject(GInterfaceStatus* /*status*/, Object* /*param2*/) {
    // Original at 0x007286d0: checks if spell seed can be applied to target object
    // Validates spell type compatibility with target
    return 0;
}

uint32_t SpellSeed::ApplyThisToObject(GInterfaceStatus* /*status*/, Object* /*param2*/,
                                       GestureSystemPacketData* /*param3*/) {
    // Original at 0x00728d10: casts the spell seed's spell on the target object
    return 0;
}

uint32_t SpellSeed::ValidToApplyThisToMapCoord(GInterfaceStatus* /*status*/, const MapCoords* /*param2*/) {
    // Original at 0x00728720: checks if spell seed can be cast at map position
    return 0;
}

uint32_t SpellSeed::ApplyThisToMapCoord(GInterfaceStatus* /*status*/, const MapCoords* /*param2*/,
                                         GestureSystemPacketData* /*param3*/) {
    // Original at 0x00728e20: casts the spell seed's spell at map position
    return 0;
}

uint32_t SpellSeed::ValidForLockedApplyProcess(GInterfaceStatus* /*status*/) {
    // Original at 0x00728750: validates spell can continue its locked apply gesture
    return 0;
}

uint32_t SpellSeed::ApplyUnlockProcess(GInterfaceStatus* /*status*/) {
    // Original at 0x00728eb0: finalizes spell cast when gesture lock is released
    return 0;
}

uint32_t SpellSeed::IsInterfacePowerUpWhenInHand() const {
    // Original at 0x007286a0: returns 1
    return 1;
}

uint32_t SpellSeed::ApplyOnlyAfterRecSystem() {
    // Original at 0x007286b0: returns 1
    return 1;
}

uint32_t SpellSeed::ThrowObjectFromHand(GInterfaceStatus* /*status*/, int /*param2*/) {
    // Original at 0x0072acd0: throws spell seed, triggering spell cast at impact point
    return 0;
}

bool32_t SpellSeed::IsEffectReceiver(EffectValues* /*param1*/) {
    // Original at 0x00728f50: spell seeds don't receive effects
    return 0;
}

bool SpellSeed::InteractsWithPhysicsObjects() {
    // Original at 0x00728570: returns false
    return false;
}

bool SpellSeed::ProcessInHand() {
    // Original at 0x00729930: updates power charge while spell seed is held
    // Power increases over time until max, with visual feedback
    return false;
}

size_t SpellSeed::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) {
    // Original at 0x00727f90 — writes spell seed state to level file
    // Needs save system
    return 0;
}

IMMERSION_EFFECT_TYPE SpellSeed::GetInHandImmersionTexture() {
    // Original at 0x0072a2d0: returns immersion texture based on spell type
    // Reads from info struct to determine which visual effect to show
    return IMMERSION_EFFECT_TYPE_NONE;
}
