// GGame — top-level game state
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// GGame is the "god struct" containing all game state: 8 players, the map,
// landscape, script engine, camera, climate, and everything else.

#include <black/Game.h>

// Global game instance pointer (allocated during engine init)
GGame* g_game = nullptr;

GPlayer* GGame::GetPlayer(uint32_t index) {
    // Original at win1.41 0x004ed4c0
    return &players[index];
}
