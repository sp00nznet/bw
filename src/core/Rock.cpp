// Rock class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Rock is a throwable/moveable object used as building material.
// Methods at 0x004397xx are small (~16 bytes each).

#include <black/Rock.h>

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

GPlayer* Rock::GetPlayer() {
    // Original at 0x006e77a0: returns this->player
    return player;
}

void Rock::SetPlayer(GPlayer* p) {
    // Original at 0x00439720: this->player = p
    player = p;
}

uint32_t Rock::AddResource(RESOURCE_TYPE /*type*/, uint32_t /*amount*/,
                            GInterfaceStatus* /*status*/, bool /*param4*/,
                            const MapCoords& /*coords*/, int /*param6*/) {
    // Original at 0x006e7170 — complex
    // TODO: implement properly
    return 0;
}

uint32_t Rock::RemoveResource(RESOURCE_TYPE /*type*/, uint32_t /*amount*/,
                               GInterfaceStatus* /*status*/, bool* /*param4*/) {
    // Original at 0x006e70d0 — complex
    // TODO: implement properly
    return 0;
}

char* Rock::GetDebugText() {
    // Original at 0x00561390: returns "Rock"
    static char text[] = "Rock";
    return text;
}

uint32_t Rock::GetSampleForAttack() {
    // Original at 0x0071bcd0 — complex
    // TODO: implement properly
    return 0;
}

uint32_t Rock::Load(GameOSFile* /*file*/) {
    // Original at 0x006e7870 — complex serialization
    // TODO: implement when save system is available
    return 0;
}

uint32_t Rock::Save(GameOSFile* /*file*/) {
    // Original at 0x006e77b0 — complex serialization
    // TODO: implement when save system is available
    return 0;
}

uint32_t Rock::GetSaveType() {
    // Original at 0x00561380
    // TODO: verify return value
    return 0;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

void Rock::PhysicsEditorCreate(int /*param1*/) {
    // Original at 0x006e79f0 — complex
    // TODO: implement properly
}

uint32_t Rock::GetOverwriteTapToolTip() {
    // Original at 0x006e7a60
    // TODO: implement properly
    return 0;
}

bool32_t Rock::IsRock_0() {
    // Original at 0x00439730: returns 1
    return 1;
}

bool32_t Rock::CanBeAttackedByCreature(Creature* /*creature*/) {
    // Original at 0x00439760: small method
    return 1;
}

bool32_t Rock::CanBePickedUpByCreature(Creature* /*creature*/) {
    // Original at 0x006e7a70 — complex
    // TODO: implement properly
    return 0;
}

uint32_t Rock::GetCreatureMimicType() {
    // Original at 0x00439750: small method
    // TODO: verify return value
    return 6;
}

bool32_t Rock::CanBeThrownByPlayer() {
    // Original at 0x006e7070 — complex
    // TODO: implement properly
    return 1;
}

uint32_t Rock::GetScriptObjectType() {
    // Original at 0x006e79e0 — complex
    // TODO: implement properly
    return 0;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

void Rock::ActualMoveMapObject(const MapCoords& /*coords*/) {
    // Original at 0x006e7210 — complex
    // TODO: implement properly
}

void Rock::Draw() {
    // Original at 0x00517f10 — complex rendering
    // TODO: implement when rendering system is available
}

bool Rock::IsResourceStore(RESOURCE_TYPE /*type*/) {
    // Original at 0x00439710: small method
    // Rocks store ore/wood
    return true;
}

RESOURCE_TYPE Rock::GetResourceType() {
    // Original at 0x006e70c0 — complex
    // TODO: implement properly
    return RESOURCE_TYPE_WOOD;
}

int Rock::GetDefaultResource() {
    // Original at 0x006e7090 — complex
    // TODO: implement properly
    return 0;
}

bool32_t Rock::ValidForPlaceInHand(GInterfaceStatus* /*status*/) {
    // Original at 0x006e7030 — complex
    // TODO: implement properly
    return 1;
}

uint32_t Rock::InterfaceValidToTap(GInterfaceStatus* /*status*/) {
    // Original at 0x006e7450 — complex
    // TODO: implement properly
    return 0;
}

uint32_t Rock::InterfaceTap(GInterfaceStatus* /*status*/) {
    // Original at 0x006e7480 — complex
    // TODO: implement properly
    return 0;
}

uint32_t Rock::GetPhysicsConstantsType() {
    // Original at 0x006e6ff0 — complex
    // TODO: implement properly
    return 0;
}

void Rock::EndPhysics(PhysicsObject* /*param1*/, bool /*param2*/) {
    // Original at 0x006e7000 — complex
    // TODO: implement properly
}

bool Rock::InteractsWithPhysicsObjects() {
    // Original at 0x00561370: returns true
    return true;
}

void Rock::ReactToPhysicsImpact(PhysicsObject* /*param1*/, bool /*param2*/) {
    // Original at 0x006e7930 — complex
    // TODO: implement properly
}

bool Rock::ShouldFootpathsGoRound() {
    // Original at 0x00439770: returns true
    return true;
}

// ============================================================================
// New virtual method
// ============================================================================

bool Rock::IsMovable() {
    // Original at 0x00439740: returns true
    return true;
}
