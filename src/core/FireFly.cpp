// FireFly class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)

#include <black/FireFly.h>
#include <black/LHRandom.h>

namespace {
float g_reward_prob[42];
float g_reward_total[42];
}

void SetFireFlyRewardProb(uint32_t magic, float prob) {
    if (magic > 41) return;
    g_reward_prob[magic] = prob;
    float sum = 0.0f;
    for (int i = 0; i < 42; ++i) g_reward_total[i] = sum += g_reward_prob[i];
}

float FireFlyRewardProb(uint32_t magic) { return magic > 41 ? 0.0f : g_reward_prob[magic]; }

uint32_t PickFireFlyReward() {
    const float roll = lh::RandomFloat(g_reward_total[41]);  // sub_67BCB0
    if (roll == 0.0f) return 0;
    for (uint32_t i = 0; i < 42; ++i)
        if (roll <= g_reward_total[i]) return i;
    return 0;
}

// ============================================================================
// Overrides of Base virtuals
// ============================================================================

void FireFly::ToBeDeleted(int param) {
    // Original at 0x0052a4c0 — complex cleanup
    Object::ToBeDeleted(param);
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

char* FireFly::GetDebugText() {
    // Original at 0x0052a300
    static char text[] = "FireFly";
    return text;
}

uint32_t FireFly::Load(GameOSFile* /*file*/) {
    // Original at 0x0052bbc0 — complex serialization
    return 0;
}

uint32_t FireFly::Save(GameOSFile* /*file*/) {
    // Original at 0x0052b870 — complex serialization
    return 0;
}

uint32_t FireFly::GetSaveType() {
    // Original at 0x0052a2f0
    return 0x2a;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

bool FireFly::IsMoving() const {
    // Original at 0x0052a1d0 — complex
    return false;
}

// ============================================================================
// Overrides of Object virtuals
// ============================================================================

void FireFly::Draw() {
    // Original at 0x0052aa90 — complex rendering
}

void FireFly::CallVirtualFunctionsForCreation(const MapCoords& coords) {
    // Original at 0x0052a510 — complex
    Object::CallVirtualFunctionsForCreation(coords);
}

bool FireFly::InteractsWithPhysicsObjects() {
    // Original at 0x0052a1a0: returns false
    return false;
}

void FireFly::ReactToPhysicsImpact(PhysicsObject* /*param1*/, bool /*param2*/) {
    // Original at 0x0052a1b0 — stubbed
}

bool FireFly::CanBecomeAPhysicsObject() {
    // Original at 0x0052a1c0: returns false
    return false;
}

size_t FireFly::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) {
    // Original at 0x0052bf10 — complex serialization
    return 0;
}
