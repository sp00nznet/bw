// GPlayer class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)

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
