// CitadelPart class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Trivial methods at 0x00464axx-0x00464bxx and 0x004694xx are packed 16 bytes apart.
// Complex methods at 0x004695xx-0x004699xx.

#include <black/CitadelPart.h>

// ============================================================================
// Overrides of Base virtuals
// ============================================================================

void CitadelPart::ToBeDeleted(int /*param*/) {
    // Original at 0x00469540 — complex
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

GPlayer* CitadelPart::GetPlayer() {
    // Original at 0x00469750 — complex
    return nullptr;
}

char* CitadelPart::GetDebugText() {
    // Original at 0x004694e0
    static char text[] = "CitadelPart";
    return text;
}

uint32_t CitadelPart::Load(GameOSFile* /*file*/) {
    // Original at 0x004698b0 — complex serialization
    return 0;
}

uint32_t CitadelPart::Save(GameOSFile* /*file*/) {
    // Original at 0x00469830 — complex serialization
    return 0;
}

uint32_t CitadelPart::GetSaveType() {
    // Original at 0x004694d0
    return 0;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

uint32_t CitadelPart::GetCreatureBeliefType() {
    // Original at 0x00464aa0 — complex
    return 0;
}

Citadel* CitadelPart::GetCitadel() {
    // Original at 0x00464a80: returns citadel field
    return citadel;
}

bool32_t CitadelPart::IsCitadelPart_0() {
    // Original at 0x00464b00: returns 1
    return 1;
}

bool32_t CitadelPart::IsCitadelPart_1(Creature* /*creature*/) {
    // Original at 0x00464b10: returns 1
    return 1;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

void* CitadelPart::GetActualObjectToEffect(GPlayer* /*player*/, bool /*param2*/) {
    // Original at 0x00469780 — complex
    return nullptr;
}

uint32_t CitadelPart::DestroyedByEffect(GPlayer* /*player*/, float /*param2*/) {
    // Original at 0x004695c0 — complex
    return 0;
}

uint32_t CitadelPart::Process() {
    // Original at 0x00469490 — complex
    return 0;
}

int CitadelPart::GetMesh() const {
    // Original at 0x00464a90
    return 0;
}

void CitadelPart::CallVirtualFunctionsForCreation(const MapCoords& coords) {
    // Original at 0x00469760 — complex
    MultiMapFixed::CallVirtualFunctionsForCreation(coords);
}

LH3DObject_ObjectType CitadelPart::Get3DType() {
    // Original at 0x004694b0
    return LH3D_OBJECT_TYPE_DEFAULT;
}

bool32_t CitadelPart::CanBeDestroyedBySpell_1(Spell* /*param1*/) {
    // Original at 0x004695d0 — complex
    return 0;
}

void CitadelPart::ReactToPhysicsImpact(PhysicsObject* /*param1*/, bool /*param2*/) {
    // Original at 0x004697f0 — complex
}

size_t CitadelPart::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) {
    // Original at 0x004694c0
    return 0;
}

bool CitadelPart::ShouldFootpathsGoRound() {
    // Original at 0x004694f0: returns true
    return true;
}

// ============================================================================
// Overrides of MultiMapFixed virtuals
// ============================================================================

bool CitadelPart::IsRepaired() {
    // Original at 0x00464ab0 — complex
    return false;
}

bool CitadelPart::IsBuilt() {
    // Original at 0x00464ad0 — complex
    return false;
}

PlannedMultiMapFixed* CitadelPart::ConvertToPlanned() {
    // Original at 0x004694a0 — complex
    return nullptr;
}
