// Citadel class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Citadel is the divine stronghold. Simple methods at 0x00462axx
// are packed 16 bytes apart (trivial returns).

#include <black/Citadel.h>

// ============================================================================
// Overrides of Base virtuals
// ============================================================================

void Citadel::ToBeDeleted(int /*param*/) {
    // Original at 0x00462b90 — complex
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

char* Citadel::GetDebugText() {
    static char text[] = "Citadel";
    return text;
}

uint32_t Citadel::Load(GameOSFile* /*file*/) {
    // Original at 0x00463dc0 — complex serialization
    return 0;
}

uint32_t Citadel::Save(GameOSFile* /*file*/) {
    // Original at 0x00463b00 — complex serialization
    return 0;
}

uint32_t Citadel::GetSaveType() {
    // Original at 0x00462ac0
    return 0;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

uint32_t Citadel::GetCreatureBeliefType() {
    // Original at 0x00462a60
    return 0;
}

uint32_t Citadel::GetCreatureBeliefListType() {
    // Original at 0x00462a70
    return 0;
}

uint32_t Citadel::GetOrigin() {
    // Original at 0x00462a80
    return 0;
}

bool Citadel::IsActivityObjectWhichAngerAppliesTo(Creature* /*creature*/) {
    // Original at 0x004e40e0 — complex
    return false;
}

bool32_t Citadel::IsSuitableForCreatureActivity() {
    // Original at 0x00462a90: returns 1
    return 1;
}

float Citadel::GetHowMuchCreatureWantsToLookAtMe() {
    // Original at 0x004d1b50 — complex
    return 0.0f;
}

const char* Citadel::GetText() {
    // Original at 0x00462aa0
    return "Citadel";
}

bool32_t Citadel::IsCitadel() {
    // Original at 0x00462ab0: returns 1
    return 1;
}

// ============================================================================
// Non-virtual methods
// ============================================================================

void* Citadel::AddTown(Town* /*town*/) {
    // Original at 0x00463130 — complex
    return nullptr;
}

WorshipSite* Citadel::FindOrCreateWorshipSite(const GTribeInfo* /*tribe_info*/) {
    // Original at 0x00463220 — complex
    return nullptr;
}
