// GPlayer class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)

#include <black/Object.h>
#include <cmath>
#include <algorithm>
#include <black/Citadel.h>
#include <black/Player.h>
#include <black/Game.h>
#include <black/Town.h>
#include <black/Creature.h>

extern GGame* g_game;

// ============================================================================
// Overrides of Base virtuals
// ============================================================================

void GPlayer::ToBeDeleted(int /*param*/) {
    // Original at 0x006490b0 — complex cleanup
}

void GPlayer::Dump() {
    // Original at 0x0064a6d0 — debug output
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

GPlayer* GPlayer::GetPlayer() {
    // Original at 0x00648e70: returns this
    return this;
}

float GPlayer::GetMaxAlignmentChangePerGameTurn() {
    // Original at 0x0064b670 — complex
    return MAX_ALIGNMENT_CHANGE_PER_TURN;
}

void GPlayer::MaintainSpell(uint32_t /*param1*/, float /*param2*/) {
    // Original at 0x0064c430 — complex
}

void GPlayer::UpdateSpellInfo(Spell* /*spell*/, PSysProcessInfo* /*info*/) {
    // Original at 0x0064c470 — complex
}

GPlayer* GPlayer::CastPlayer() {
    // Original at 0x00648e80: returns this
    return this;
}

// ============================================================================
// Static methods
// ============================================================================

void GPlayer::ProcessPlayers() {
    // Original at 0x00649a20 — iterates all 8 players and calls Process()
    if (!g_game) return;
    for (int i = 0; i < 8; i++) {
        GPlayer* player = &g_game->players[i];
        if (player->type != PLAYER_TYPE_NONE) {
            player->Process();
        }
    }
}

void GPlayer::PostLoadCleanup() {
    // Original at 0x0064ab90 — complex post-load resolution
}

GPlayer* GPlayer::GetPlayerFromText(const char* /*str*/) {
    // Original at 0x0064b5e0 — complex string lookup
    return nullptr;
}

// ============================================================================
// Non-virtual methods
// ============================================================================

// sub_5F71B0: the type (+248), number (+181) and name (+252).
// ponytail: the 508-byte object at +348, the GameStats at +604 and the
// interface it makes at interfaces[param4] are not built; nothing in core
// reads them yet.
void GPlayer::Init(PLAYER_TYPE t, uint8_t number, char16_t* new_name, uint8_t /*param4*/) {
    type = t;
    player_number = number;
    if (new_name) {
        size_t i = 0;
        for (; i + 1 < sizeof(name) / sizeof(name[0]) && new_name[i]; ++i) name[i] = new_name[i];
        name[i] = 0;
    }
}

namespace {
GPlayer g_players[8];
}  // namespace

GPlayer* PlayerAt(uint32_t index) { return index < 8 ? &g_players[index] : nullptr; }

void ResetPlayers() {
    for (uint32_t i = 0; i < 8; ++i) {
        GPlayer& p = g_players[i];
        p.creature = nullptr;
        p.citadel = nullptr;
        p.towns = {};
        for (int k = 0; k < 9; ++k) p.multipliers[k] = p.multipliers_b8[k] = 1.0f;  // sub_5F7360
        char16_t name[16] = u"Player[0]";
        name[7] = static_cast<char16_t>(u'0' + i);
        p.Init(i == 0 ? PLAYER_TYPE_HUMAN : i == 7 ? PLAYER_TYPE_NEUTRAL : PLAYER_TYPE_NONE, static_cast<uint8_t>(i), name, static_cast<uint8_t>(i));
    }
}

void SetPlayerCreature(GPlayer* p, Creature* c) {
    if (!p || !c) return;
    p->creature = c;
    c->SetOwner(p);
}

// ponytail: v1.0's 0 is the player at GGame+2104087 (the local one); here, player 0.
float g_town_influence_multiplier = 1.0f;
float g_player_influence_multiplier = 1.0f;

namespace {
std::vector<InfluenceRing*> g_rings;  // game +2104584 (newest first there; order does not matter to the sum)
}

InfluenceRing* AddInfluenceRing(const MapCoords& at, Object* follow, GPlayer* player, float radius, bool anti) {
    auto* r = new InfluenceRing{follow ? follow->coords : at, follow, player, radius, anti};
    g_rings.push_back(r);
    return r;
}

void RemoveInfluenceRing(InfluenceRing* ring) {
    for (auto it = g_rings.begin(); it != g_rings.end(); ++it)
        if (*it == ring) { delete ring; g_rings.erase(it); return; }
}

const std::vector<InfluenceRing*>& InfluenceRings() { return g_rings; }

// The inner part (A x r) is whole; to (A + B) x r it falls to 1 - C; out to r
// it falls from 0.2 to 0. A, B and C are floats at 0xC38DE0..E8 in .bss that
// no code writes and nothing points at, so they are 0 in the shipped game:
// a ring gives 0.2 x (1 - d / r).
float RingFalloff(float d, float r) {
    constexpr float A = 0.0f, Bw = 0.0f, C = 0.0f;
    const float inner = A * r;
    if (d <= inner) return 1.0f;
    const float mid = (Bw + A) * r;
    if (d <= mid) return (1.0f - (d - inner) / (mid - inner)) * (1.0f - C);
    if (d >= r) return 0.0f;
    return (1.0f - (d - mid) / (r - mid)) * 0.2f;
}

// ponytail: not modelled -- the debug "all influence" flag (game +20 bit
// 0x2000) and the player's +332; the game mode that gives a citadel-less
// player none (sub_5256A0); the landscape test (sub_442BD0, ours: inside the
// map). A ring keeps the position it was made at (+0x14).
float PlayerInfluence(GPlayer* p, const MapCoords& at) {
    if (!p) return 1.0f;
    auto dist = [&at](const MapCoords& c) { return std::hypot(MetresOf(at.x - c.x), MetresOf(at.z - c.z)); };
    float v = 0.0f;
    if (Citadel* c = p->citadel) {  // sub_44E9B0
        const float power = c->Power();
        if (power > dist(c->coords)) v += power;
    }
    for (Town* t = p->towns.first; t; t = t->next)  // sub_6D9500
        if (dist(t->coords) < t->influence) v += t->influence;
    if (at.x < 0 || at.z < 0) return 0.0f;
    // The rings (sub_58E410 / sub_58E510), skipping one whose object is going
    // (+0x24 bit 2): the player's own anti-ring around the point leaves it
    // none; the rest add their falloff.
    for (const InfluenceRing* r : g_rings) {
        if (r->follow && (r->follow->field_0x24 & 4)) continue;
        if (r->player != p) continue;
        const float d = dist(r->at);
        if (r->anti) { if (d <= r->radius) return 0.0f; }
        else v += RingFalloff(d, r->radius);
    }
    return std::clamp(v, -1.0f, 1.0f);
}

// sub_523530 walks the players in use. ponytail: v1.0 starts from the local
// player's slot; here the first strictly greater wins from player 0 up.
GPlayer* InfluenceOwner(const MapCoords& at, float* amount) {
    GPlayer* best = PlayerAt(0);
    float most = 0.0f;
    for (uint32_t i = 0; i < 8; ++i) {
        GPlayer* p = PlayerAt(i);
        if (p->type == PLAYER_TYPE_NONE) continue;
        const float v = PlayerInfluence(p, at);
        if (v > most) most = v, best = p;
    }
    if (amount) *amount = most;
    return best;
}

GPlayer* ScriptPlayer(int32_t n) { return PlayerAt(n > 0 ? static_cast<uint32_t>(n - 1) : 0u); }

void GPlayer::Process() {
    // Original at 0x006494e0 — per-tick player update
    // Processes towns, creature, spell charges, and alignment

    // Process each town owned by this player
    Town* town_ptr = towns.first;
    while (town_ptr) {
        town_ptr->Process();
        town_ptr = town_ptr->next;
    }

    // Process creature AI tick — advance creature desire evaluation and action selection
    // Update spell charge timers — regenerate mana for each spell type over time
    // Update alignment changes — shift player alignment based on recent actions
}

void GPlayer::Birthday() {
    // Original at 0x0064a6b0 — trigger birthday events for all towns
    Town* town_ptr = towns.first;
    while (town_ptr) {
        town_ptr->Birthday();
        town_ptr = town_ptr->next;
    }
}

uint8_t GPlayer::GetPlayerNumber() const {
    // Original at 0x0064a790: returns player_number
    return player_number;
}

GInterfaceStatus* GPlayer::GetNextInterfaceStatus(GInterfaceStatus* /*status*/) {
    // Original at 0x0064aac0 — complex
    return nullptr;
}

bool GPlayer::IsNeutral() {
    // Original at 0x0064ac00: checks player_number == PLAYER_NAME_NEUTRAL
    return player_number == PLAYER_NAME_NEUTRAL;
}

float GPlayer::CalculateInfluencePower() {
    // Original at 0x0064ad00 — sum influence from all towns
    float total = 0.0f;
    Town* town_ptr = towns.first;
    while (town_ptr) {
        total += town_ptr->influence;
        town_ptr = town_ptr->next;
    }
    return total;
}

LH3DColor* GPlayer::GetPlayer3DColor(LH3DColor* color) {
    // Original at 0x0064b590 — complex, hidden struct return
    return color;
}

bool32_t GPlayer::IsMagicTypeEnabled(MAGIC_TYPE type) {
    // Original at 0x0064c220 — checks if a magic type is available to this player
    if (static_cast<uint32_t>(type) >= 0x2A) return 0;
    return magic_enabled[static_cast<uint32_t>(type)] ? 1 : 0;
}

GInterface* GPlayer::GetRealInterface(unsigned long index) {
    // Original at 0x0064d120 — returns interface by index
    if (index == 0) return interfaces[0];
    return nullptr;
}

bool GPlayer::IsMemberOfThisPlayer(GInterfaceStatus* /*status*/) {
    // Original at 0x0064d750 — complex
    return false;
}

LH3DColor GPlayer::GetPlayerColour() const {
    // Original at 0x0064d800 — complex color lookup from player index
    LH3DColor color = {0};
    return color;
}
