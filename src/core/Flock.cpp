// Flock class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Flock manages groups of animals. Simple methods at 0x0052f8xx
// are packed 16 bytes apart (trivial returns).

#include <black/Flock.h>

// ============================================================================
// Overrides of Base virtuals
// ============================================================================

void Flock::ToBeDeleted(int /*param*/) {
    // Original at 0x0052ffb0 — complex
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

Town* Flock::GetTown() {
    // Original at 0x0052f870: returns nullptr
    return nullptr;
}

char* Flock::GetDebugText() {
    static char text[] = "Flock";
    return text;
}

uint32_t Flock::Load(GameOSFile* /*file*/) {
    // Original at 0x00530930 — complex serialization
    return 0;
}

uint32_t Flock::Save(GameOSFile* /*file*/) {
    // Original at 0x005305a0 — complex serialization
    return 0;
}

uint32_t Flock::GetSaveType() {
    // Original at 0x0052f900
    return 0;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

uint32_t Flock::GetCreatureBeliefType() {
    // Original at 0x0052f8a0
    return 0;
}

uint32_t Flock::GetCreatureBeliefListType() {
    // Original at 0x0052f8b0
    return 0;
}

bool Flock::IsActivityObjectWhichAngerAppliesTo(Creature* /*creature*/) {
    // Original at 0x0052f8d0: returns true
    return true;
}

bool Flock::IsActivityObjectWhichCompassionAppliesTo(Creature* /*creature*/) {
    // Original at 0x0052f8e0: returns true
    return true;
}

bool Flock::IsActivityObjectWhichPlayfulnessAppliesTo(Creature* /*creature*/) {
    // Original at 0x0052f8f0: returns true
    return true;
}

bool32_t Flock::IsSuitableForCreatureActivity() {
    // Original at 0x0052f8c0: returns 1
    return 1;
}

bool32_t Flock::IsFlock() const {
    // Original at 0x0052f860: returns 1
    return 1;
}

bool32_t Flock::IsScriptContainer() const {
    // Original at 0x0052f880: returns 1
    return 1;
}

const char* Flock::GetText() {
    // Original at 0x0052f890
    return "Flock";
}

uint32_t Flock::GetScriptObjectType() {
    // Original at 0x00530490 — complex
    return 0;
}

// ============================================================================
// Non-virtual methods
// ============================================================================

void Flock::SetDomainCentrePos(const MapCoords& /*pos*/) {
    // Original at 0x0052fc20 — complex
}

MapCoords* Flock::GetFlockPos() {
    // Original at 0x00530570 — complex
    return &field_0x60;
}
