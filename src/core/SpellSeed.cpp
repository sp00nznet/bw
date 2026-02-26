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

void SpellSeed::ToBeDeleted(int /*param*/) {
    // Original at 0x00728280 — complex
    // TODO: implement properly
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
    // TODO: implement when save system is available
    return 0;
}

uint32_t SpellSeed::Save(GameOSFile* /*file*/) {
    // Original at 0x00729ca0 — complex serialization
    // TODO: implement when save system is available
    return 0;
}

uint32_t SpellSeed::GetSaveType() {
    // Original at 0x00727fa0
    // TODO: verify return value
    return 0;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

uint32_t SpellSeed::GetCreatureBeliefType() {
    // Original at 0x00727f70
    // TODO: verify return value
    return 0;
}

uint32_t SpellSeed::GetOrigin() {
    // Original at 0x00727f80
    // TODO: verify return value
    return 0;
}

float SpellSeed::GetPower() const {
    // Original at 0x007298b0 — complex
    // TODO: implement properly
    return 0.0f;
}

float SpellSeed::GetPSysPower() const {
    // Original at 0x007298f0 — complex
    // TODO: implement properly
    return 0.0f;
}

WorshipSite* SpellSeed::GetWorshipSite() {
    // Original at 0x00728a00 — complex
    // TODO: implement properly
    return nullptr;
}

bool32_t SpellSeed::IsSpellSeed() {
    // Original at 0x00727f50: returns 1
    return 1;
}

uint32_t SpellSeed::GetScriptObjectType() {
    // Original at 0x00729c90 — complex
    // TODO: implement properly
    return 0;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

void SpellSeed::InsertMapObject() {
    // Original at 0x00728f30 — complex
    // TODO: implement properly
}

void SpellSeed::RemoveMapObject() {
    // Original at 0x00728f40 — complex
    // TODO: implement properly
}

HOLD_TYPE SpellSeed::GetHoldType() {
    // Original at 0x00728680 — complex
    // TODO: implement properly
    return HOLD_TYPE_DEFAULT;
}

float SpellSeed::GetHoldRadius() {
    // Original at 0x00728640 — complex
    // TODO: implement properly
    return 0.0f;
}

float SpellSeed::GetHoldLoweringMultiplier() {
    // Original at 0x00728660 — complex
    // TODO: implement properly
    return 1.0f;
}

float SpellSeed::GetHoldYRotate() {
    // Original at 0x00728670 — complex
    // TODO: implement properly
    return 0.0f;
}

bool32_t SpellSeed::HandShouldFeelWithMeshIntersect() {
    // Original at 0x00727f60: returns 0
    return 0;
}

int SpellSeed::GetMesh() const {
    // Original at 0x00729850 — complex
    // TODO: implement properly
    return 0;
}

void SpellSeed::Draw() {
    // Original at 0x00518710 — complex rendering
    // TODO: implement when rendering system is available
}

void SpellSeed::DrawOutOfMap(bool /*param1*/) {
    // Original at 0x005190a0 — complex rendering
    // TODO: implement when rendering system is available
}

bool SpellSeed::IsG3DObjectDrawnInHand() {
    // Original at 0x00728600 — complex
    // TODO: implement properly
    return false;
}

void SpellSeed::CallVirtualFunctionsForCreation(const MapCoords& coords) {
    // Original at 0x00728360 — complex
    // TODO: implement properly
    Object::CallVirtualFunctionsForCreation(coords);
}

bool32_t SpellSeed::ValidForPlaceInHand(GInterfaceStatus* /*status*/) {
    // Original at 0x00728580 — complex
    // TODO: implement properly
    return 1;
}

bool32_t SpellSeed::InterfaceSetInMagicHand(GInterfaceStatus* /*status*/) {
    // Original at 0x00728810 — complex
    // TODO: implement properly
    return 0;
}

bool32_t SpellSeed::InterfaceSetOutMagicHand(GInterfaceStatus* /*status*/) {
    // Original at 0x00728940 — complex
    // TODO: implement properly
    return 0;
}

bool32_t SpellSeed::ValidToRemoveFromHand(GInterfaceStatus* /*status*/, const MapCoords* /*param2*/) {
    // Original at 0x00728760 — complex
    // TODO: implement properly
    return 0;
}

uint32_t SpellSeed::RemoveFromHand(GInterfaceStatus* /*status*/, const MapCoords* /*param2*/) {
    // Original at 0x00728f00 — complex
    // TODO: implement properly
    return 0;
}

uint32_t SpellSeed::ValidToApplyThisToObject(GInterfaceStatus* /*status*/, Object* /*param2*/) {
    // Original at 0x007286d0 — complex
    // TODO: implement properly
    return 0;
}

uint32_t SpellSeed::ApplyThisToObject(GInterfaceStatus* /*status*/, Object* /*param2*/,
                                       GestureSystemPacketData* /*param3*/) {
    // Original at 0x00728d10 — complex
    // TODO: implement properly
    return 0;
}

uint32_t SpellSeed::ValidToApplyThisToMapCoord(GInterfaceStatus* /*status*/, const MapCoords* /*param2*/) {
    // Original at 0x00728720 — complex
    // TODO: implement properly
    return 0;
}

uint32_t SpellSeed::ApplyThisToMapCoord(GInterfaceStatus* /*status*/, const MapCoords* /*param2*/,
                                         GestureSystemPacketData* /*param3*/) {
    // Original at 0x00728e20 — complex
    // TODO: implement properly
    return 0;
}

uint32_t SpellSeed::ValidForLockedApplyProcess(GInterfaceStatus* /*status*/) {
    // Original at 0x00728750 — complex
    // TODO: implement properly
    return 0;
}

uint32_t SpellSeed::ApplyUnlockProcess(GInterfaceStatus* /*status*/) {
    // Original at 0x00728eb0 — complex
    // TODO: implement properly
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
    // Original at 0x0072acd0 — complex
    // TODO: implement properly
    return 0;
}

bool32_t SpellSeed::IsEffectReceiver(EffectValues* /*param1*/) {
    // Original at 0x00728f50 — complex
    // TODO: implement properly
    return 0;
}

bool SpellSeed::InteractsWithPhysicsObjects() {
    // Original at 0x00728570: returns false
    return false;
}

bool SpellSeed::ProcessInHand() {
    // Original at 0x00729930 — complex
    // TODO: implement properly
    return false;
}

size_t SpellSeed::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) {
    // Original at 0x00727f90
    // TODO: implement when save system is available
    return 0;
}

IMMERSION_EFFECT_TYPE SpellSeed::GetInHandImmersionTexture() {
    // Original at 0x0072a2d0 — complex
    // TODO: implement properly
    return IMMERSION_EFFECT_TYPE_NONE;
}
