// SpellDispenser class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)

#include <black/SpellDispenser.h>
#include <black/OneOffSpellSeed.h>
#include <black/WorshipSite.h>

void SpellDispenser::ToBeDeleted(int /*param*/) {
    // Original at 0x007228a0 — complex
}

char* SpellDispenser::GetDebugText() {
    static char text[] = "SpellDispenser";
    return text;
}

uint32_t SpellDispenser::Load(GameOSFile* /*file*/) {
    // Original at 0x00722e80 — complex
    return 0;
}

uint32_t SpellDispenser::Save(GameOSFile* /*file*/) {
    // Original at 0x00722d50 — complex
    return 0;
}

uint32_t SpellDispenser::GetSaveType() {
    // Original at 0x007226f0
    return 267;
}

bool32_t SpellDispenser::IsSpellDispenser() {
    // Original at 0x007226d0: returns 1
    return 1;
}

bool32_t SpellDispenser::IsActive() const {
    // Original at 0x007226c0: returns 1
    return 1;
}

uint32_t SpellDispenser::GetScriptObjectType() {
    // Original at 0x00722fb0 — complex
    return 0;
}

uint32_t SpellDispenser::Process() {
    // Original at 0x00722a70 — complex
    return 0;
}

void SpellDispenser::Draw() {
    // Original at 0x00722940 — complex rendering
}

void SpellDispenser::CallVirtualFunctionsForCreation(const MapCoords& coords) {
    // Original at 0x007227d0 — complex
    Abode::CallVirtualFunctionsForCreation(coords);
}

bool SpellDispenser::IsSpellSeedReturnPoint() const {
    // Original at 0x007226e0: returns true
    return true;
}

void SpellDispenser::SetActive(bool on) {
    active = on ? 1u : 0u;
    if (on) Dispense();
}

// v1.0 adds 1.2 x the building's height (vslot 267, sub_5EA4F0: its
// collision mesh's +40 x 2 x scale). ponytail: we have no collision mesh, so
// the seed sits at the dispenser's own height.
MapCoords SpellDispenser::DispensePos() const { return coords; }

// The seed of the dispenser's magic, with the magic's power-up, strength 1.
// ponytail: the effect it plays there (sub_5EFC00, type 9) is not.
OneOffSpellSeed* SpellDispenser::Dispense() {
    const int s = SeedOfMagic(static_cast<int>(magic));
    seed = s < 0 ? nullptr : CreateOneOffSpellSeed(DispensePos(), s, SeedPowerUp(s, static_cast<int>(magic)), 1.0f);
    if (seed) turns = 0;
    return seed;
}
