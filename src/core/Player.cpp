// GPlayer class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)

#include <black/Player.h>
#include <black/Game.h>
#include <black/Town.h>

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

void GPlayer::Init(PLAYER_TYPE /*type*/, uint8_t /*number*/,
                    char16_t* /*name*/, uint8_t /*param4*/) {
    // Original at 0x00649190 — complex initialization
}

void GPlayer::Process() {
    // Original at 0x006494e0 — per-tick player update
    // Processes towns, creature, spell charges, and alignment

    // Process each town owned by this player
    Town* town_ptr = towns.first;
    while (town_ptr) {
        town_ptr->Process();
        town_ptr = town_ptr->next;
    }

    // TODO: process creature AI tick
    // TODO: update spell charge timers
    // TODO: update alignment changes
}

void GPlayer::Birthday() {
    // Original at 0x0064a6b0 — complex
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
    // Original at 0x0064ad00 — complex
    return 0.0f;
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
