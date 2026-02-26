// OneOffSpellSeed class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Trivial methods at 0x0055d1xx are packed 16 bytes apart.
// Complex methods at 0x0072a4xx-0x0072acxx.

#include <black/OneOffSpellSeed.h>

// ============================================================================
// Overrides of Base virtuals
// ============================================================================

void OneOffSpellSeed::ToBeDeleted(int /*param*/) {
    // Original at 0x0072a420 — complex
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

bool OneOffSpellSeed::GetComputerSeen() {
    // Original at 0x0055d140 — complex
    return false;
}

SpellSeed* OneOffSpellSeed::CastOneOffSpellSeed() {
    // Original at 0x0055d130: returns this cast to SpellSeed*
    return reinterpret_cast<SpellSeed*>(this);
}

char* OneOffSpellSeed::GetDebugText() {
    // Original at 0x0055d160
    static char text[] = "OneOffSpellSeed";
    return text;
}

uint32_t OneOffSpellSeed::Load(GameOSFile* /*file*/) {
    // Original at 0x0072aa20 — complex serialization
    return 0;
}

uint32_t OneOffSpellSeed::Save(GameOSFile* /*file*/) {
    // Original at 0x0072a930 — complex serialization
    return 0;
}

uint32_t OneOffSpellSeed::GetSaveType() {
    // Original at 0x0055d150
    return 0;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

uint32_t OneOffSpellSeed::GetOverwritePickUpToolTip() {
    // Original at 0x0072ac50 — complex
    return 0;
}

uint32_t OneOffSpellSeed::GetOverwriteTapToolTip() {
    // Original at 0x0072ac80 — complex
    return 0;
}

bool32_t OneOffSpellSeed::CanBeEatenByCreature(Creature* /*creature*/) {
    // Original at 0x004e48f0 — complex
    return 0;
}

bool32_t OneOffSpellSeed::IsOneOffSpellBelongingToOtherPlayer(Creature* /*creature*/) {
    // Original at 0x004e4ab0 — complex
    return 0;
}

bool32_t OneOffSpellSeed::IsOneOffSpellAggressive(Creature* /*creature*/) {
    // Original at 0x0072ab00 — complex
    return 0;
}

bool32_t OneOffSpellSeed::IsOneOffSpellCompassionate(Creature* /*creature*/) {
    // Original at 0x0072ab20 — complex
    return 0;
}

bool32_t OneOffSpellSeed::IsOneOffSpellPlayful(Creature* /*creature*/) {
    // Original at 0x0072ab40 — complex
    return 0;
}

bool32_t OneOffSpellSeed::IsOneOffSpellToRestoreHealth(Creature* /*creature*/) {
    // Original at 0x0072ab60 — complex
    return 0;
}

bool32_t OneOffSpellSeed::IsStealableSpell(Creature* /*creature*/) {
    // Original at 0x004e4040 — complex
    return 0;
}

HELP_TEXT OneOffSpellSeed::GetQueryFirstEnumText() {
    // Original at 0x0072ac90 — complex
    return HELP_TEXT_NONE;
}

HELP_TEXT OneOffSpellSeed::GetQueryLastEnumText() {
    // Original at 0x0072acb0 — complex
    return HELP_TEXT_NONE;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

int OneOffSpellSeed::GetMesh() const {
    // Original at 0x0072a910 — complex
    return 0;
}

void OneOffSpellSeed::Draw() {
    // Original at 0x00518e90 — complex rendering
}

void OneOffSpellSeed::DrawOutOfMap(bool /*param1*/) {
    // Original at 0x00518c50 — complex rendering
}

void OneOffSpellSeed::CallVirtualFunctionsForCreation(const MapCoords& coords) {
    // Original at 0x0072a450 — complex
    MobileObject::CallVirtualFunctionsForCreation(coords);
}

bool32_t OneOffSpellSeed::InterfaceSetInMagicHand(GInterfaceStatus* /*status*/) {
    // Original at 0x0072a530 — complex
    return 0;
}

uint32_t OneOffSpellSeed::InterfaceValidToTap(GInterfaceStatus* /*status*/) {
    // Original at 0x0072a630 — complex
    return 0;
}

uint32_t OneOffSpellSeed::InterfaceTap(GInterfaceStatus* /*status*/) {
    // Original at 0x0072a640 — complex
    return 0;
}

bool32_t OneOffSpellSeed::IsEffectReceiver(EffectValues* /*param1*/) {
    // Original at 0x0072a520 — complex
    return 0;
}

uint32_t OneOffSpellSeed::GetPhysicsConstantsType() {
    // Original at 0x0072a920 — complex
    return 0;
}

size_t OneOffSpellSeed::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) {
    // Original at 0x0072ab80 — complex
    return 0;
}
