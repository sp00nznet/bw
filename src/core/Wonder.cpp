// Wonder class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Wonders are large god-power structures. They extend Abode
// with a power field and override resource/building methods.

#include <black/Wonder.h>

// ============================================================================
// Overrides of Base virtuals
// ============================================================================

void Wonder::ToBeDeleted(int /*param*/) {
    // Original at 0x00778e40 — complex
    // TODO: implement properly
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

char* Wonder::GetDebugText() {
    // Original at 0x00561210: returns pointer to "Wonder" string
    static char text[] = "Wonder";
    return text;
}

uint32_t Wonder::Load(GameOSFile* /*file*/) {
    // Original at 0x007790f0 — complex serialization
    // TODO: implement when save system is available
    return 0;
}

uint32_t Wonder::Save(GameOSFile* /*file*/) {
    // Original at 0x00779080 — complex serialization
    // TODO: implement when save system is available
    return 0;
}

uint32_t Wonder::GetSaveType() {
    // Original at 0x00561200
    // TODO: verify return value from decompiled code
    return 0;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

MapCoords* Wonder::GetArrivePos(MapCoords* out) {
    // Original at 0x005611b0 — complex
    // TODO: implement properly
    *out = coords;
    return out;
}

bool32_t Wonder::CanActAsAContainer(Creature* /*creature*/) {
    // Original at 0x005611e0 — complex
    // TODO: implement properly
    return 0;
}

bool32_t Wonder::IsStoragePit(Creature* /*creature*/) {
    // Original at 0x005611f0 — complex
    // TODO: implement properly
    return 0;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

void Wonder::CallVirtualFunctionsForCreation(const MapCoords& coords) {
    // Original at 0x00779160 — complex
    // TODO: implement properly
    Abode::CallVirtualFunctionsForCreation(coords);
}

LH3DObject_ObjectType Wonder::Get3DType() {
    // Original at 0x00779190
    // TODO: verify return value
    return LH3D_OBJECT_TYPE_DEFAULT;
}

// ============================================================================
// Overrides of MultiMapFixed virtuals
// ============================================================================

bool Wonder::Built() {
    // Original at 0x00778f30 — complex
    // TODO: implement properly
    return false;
}

void Wonder::SetPower(float p) {
    // Original at 0x00779070
    power = p;
}

void Wonder::AddToPlayer() {
    // Original at 0x00778fc0 — complex
    // TODO: implement properly
}

void Wonder::RemoveFromPlayer() {
    // Original at 0x00778f50 — complex
    // TODO: implement properly
}
