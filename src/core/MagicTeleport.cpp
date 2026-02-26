// MagicTeleport class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Trivial methods at 0x005fc0xx are packed 16 bytes apart (creature queries return 0).
// Complex methods at 0x005fc1xx-0x005fcexx.

#include <black/MagicTeleport.h>

// ============================================================================
// Overrides of Base virtuals
// ============================================================================

void MagicTeleport::ToBeDeleted(int /*param*/) {
    // Original at 0x005fc310 — complex
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

GPlayer* MagicTeleport::GetPlayer() {
    // Original at 0x005fc430 — complex
    return nullptr;
}

float MagicTeleport::Get2DRadius() {
    // Original at 0x005fccb0 — complex
    return 0.0f;
}

char* MagicTeleport::GetDebugText() {
    // Original at 0x005fc0f0
    static char text[] = "MagicTeleport";
    return text;
}

uint32_t MagicTeleport::Load(GameOSFile* /*file*/) {
    // Original at 0x005fbf50 — complex serialization
    return 0;
}

uint32_t MagicTeleport::Save(GameOSFile* /*file*/) {
    // Original at 0x005fbfa0 — complex serialization
    return 0;
}

uint32_t MagicTeleport::GetSaveType() {
    // Original at 0x005fc0e0
    return 0;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals (creature queries — all return 0)
// ============================================================================

bool32_t MagicTeleport::CanBePickedUpByCreature(Creature* /*creature*/) {
    // Original at 0x005fc040: returns 0
    return 0;
}

bool32_t MagicTeleport::CanBeSetOnFire(Creature* /*creature*/) {
    // Original at 0x005fc050: returns 0
    return 0;
}

bool32_t MagicTeleport::CanBeStompedOnByCreature(Creature* /*creature*/) {
    // Original at 0x005fc060: returns 0
    return 0;
}

bool32_t MagicTeleport::CanBeThrownByCreature(Creature* /*creature*/) {
    // Original at 0x005fc070: returns 0
    return 0;
}

bool32_t MagicTeleport::CanBePutInAStoragePit(Creature* /*creature*/) {
    // Original at 0x005fc080: returns 0
    return 0;
}

bool32_t MagicTeleport::CanBeDestroyedByStoning(Creature* /*creature*/) {
    // Original at 0x005fc090: returns 0
    return 0;
}

bool32_t MagicTeleport::CanBeStonedAndEatenByCreature(Creature* /*creature*/) {
    // Original at 0x005fc0a0: returns 0
    return 0;
}

bool32_t MagicTeleport::CanBeExaminedByCreature(Creature* /*creature*/) {
    // Original at 0x005fc0b0: returns 0
    return 0;
}

bool32_t MagicTeleport::CanBeFoughtByCreature(Creature* /*creature*/) {
    // Original at 0x005fc0c0: returns 0
    return 0;
}

bool32_t MagicTeleport::CanActAsAContainer(Creature* /*creature*/) {
    // Original at 0x005fc0d0: returns 0
    return 0;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

void MagicTeleport::ActualMoveMapObject(const MapCoords& /*coords*/) {
    // Original at 0x005fc960 — complex
}

void MagicTeleport::Draw() {
    // Original at 0x005fccc0 — complex rendering
}

void MagicTeleport::CallVirtualFunctionsForCreation(const MapCoords& coords) {
    // Original at 0x005fc260 — complex
    MobileStatic::CallVirtualFunctionsForCreation(coords);
}

bool32_t MagicTeleport::ValidForPlaceInHand(GInterfaceStatus* /*status*/) {
    // Original at 0x005fc440 — complex
    return 0;
}

bool32_t MagicTeleport::InterfaceSetInMagicHand(GInterfaceStatus* /*status*/) {
    // Original at 0x005fc470 — complex
    return 0;
}

bool32_t MagicTeleport::IsEffectReceiver(EffectValues* /*param1*/) {
    // Original at 0x005fce00 — complex
    return 0;
}

bool MagicTeleport::InteractsWithPhysicsObjects() {
    // Original at 0x005fcde0 — complex
    return false;
}

bool MagicTeleport::CanBecomeAPhysicsObject() {
    // Original at 0x005fcdf0 — complex
    return false;
}

bool32_t MagicTeleport::IsSolidToNewAbode() {
    // Original at 0x005fc4a0 — complex
    return 0;
}
