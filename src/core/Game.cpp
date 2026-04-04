// GGame — top-level game state
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// GGame is the "god struct" containing all game state: 8 players, the map,
// landscape, script engine, camera, climate, and everything else.

#include <black/Game.h>
#include <black/GCamera.h>
#include <black/GameThing.h>
#include <black/Living.h>
#include <black/MobileObject.h>
#include <black/Script.h>
#include <black/ScriptHighlight.h>
#include <black/Town.h>

// Global game instance pointer (allocated during engine init)
GGame* g_game = nullptr;

// === Virtual overrides (GameThing) ===

bool GGame::IsAvailable() {
    // Original at 0x0054b9a0
    return false;
}

char* GGame::GetDebugText() {
    // Original at 0x0051ec70: returns "Game"
    static char text[] = "Game";
    return text;
}

uint32_t GGame::Load(GameOSFile* /*file*/) {
    // Original at 0x00554830 — complex game state deserialization
    return 0;
}

uint32_t GGame::Save(GameOSFile* /*file*/) {
    // Original at 0x00554090 — complex game state serialization
    return 0;
}

uint32_t GGame::GetSaveType() {
    // Original at 0x0051ec60
    return 0x6a;
}

void GGame::ResolveLoad() {
    // Original at 0x00555080 — post-load fixup
}

void GGame::Delete(int param) {
    // Original at 0x0054c330
    Base::Delete(param);
}

void GGame::ToBeDeleted(int param) {
    // Original at 0x0054bfd0 — complex teardown
    GameThing::ToBeDeleted(param);
}

void GGame::Dump() {
    // Original at 0x00550780
}

// === Non-virtual methods ===

GPlayer* GGame::GetPlayer(uint32_t index) {
    // Original at 0x005509b0
    return &players[index];
}

GPlayer* GGame::GetPlayer(PLAYER_NAME name) {
    // Original at 0x00550a60 — find player by name enum
    for (int i = 0; i < 8; i++) {
        if (players[i].player_number == static_cast<uint8_t>(name)) {
            return &players[i];
        }
    }
    return nullptr;
}

GCamera* GGame::GetCamera() {
    // Original at 0x0054c180
    return camera;
}

GInterface* GGame::MyInterface() {
    // Original at 0x00555850 — returns the local player's interface
    // In single player, this is always player 0's interface
    if (players[0].type != PLAYER_TYPE_NONE) {
        return players[0].GetRealInterface(0);
    }
    return nullptr;
}

void GGame::Init() {
    // Original at 0x0054f3b0 — complex initialization
}

bool GGame::InitInner() {
    // Original at 0x0054f421 — complex
    return false;
}

void GGame::Loop() {
    // Original at 0x0054cf20 — main game loop
}

void GGame::StartGame() {
    // Original at 0x0054c190 — complex startup
}

void GGame::ProcessOneGameTurn() {
    // Original at 0x0054d620 — processes one tick of game logic
}

void GGame::ProcessGameCode() {
    // Original at 0x0054d820 — portable from vendor
    StartTurn();
    if ((field_0x14 & 4) == 0) {
        ProcessTurn();
    }
    EndTurn();
}

void GGame::ProcessGraphicsEngine(uint32_t /*param1*/, uint32_t /*param2*/) {
    // Original at 0x0054d850 — complex, calls camera update, interface, 3D engine
}

void GGame::Process3dEngine() {
    // Original at 0x0054da80 — 3D rendering pipeline
}

void GGame::StartTurn() {
    // Original at 0x0054e4f0 — turn initialization
    // Increment secondary turn counter (always)
    data.field_0x14++;

    // Increment primary game turn counter (only when not paused)
    if ((field_0x14 & 4) == 0) {
        data.game_turn++;
    }

    // Timer init — sets timer to -1 (needs timer system)
    // Clean up game object queue (linked list at data_bytes+0x33adc4)

    // Update UI
    // GInterface* iface = MyInterface();
    // if (iface) iface->Update();  // vtable offset 0x18

    // GGameInfo::Load() — loads pending game info changes

    // Reset multiplayer sound state
    if (IsMultiplayerGame() && sound_map) {
        // sound_map->field_0x4608 = 0;
    }
}

void GGame::ProcessTurn() {
    // Original at 0x0054e5c0 — main game logic per tick
    // This is the heart of the game loop, calling all subsystems.
    // Translated from x86 assembly at 0x0054e5c0-0x0054e960.

    // Phase 1: Physics/Input normalization
    // LHPoint::FastNormalize on input vector (needs physics)
    // GGameInfo::Process() — updates game info state

    // Phase 2: Entity processing
    // Pre-player processing at 0x005cdb90 (creature/spell effects)
    GPlayer::ProcessPlayers();
    // Post-player processing at 0x0050bb60 (influence map updates)
    game_lists.Process();
    // Inter-entity processing at 0x00539d70 (entity interactions)
    Living::ProcessLiving();

    // Phase 3: World updates
    // Terrain (0x00730760), Weather (0x00435f30), Forest growth (0x006e3b50)
    // Physics step (0x00720300), Climate (0x0063e090), Footpaths (0x0052b7a0)
    // Particles (0x00644fc0), Spells (0x0067d630), Effects (0x0068f5b0)

    // Phase 4: Scripting
    if (script) {
        script->Process();
    }
    // Post-script: process spell icons (0x005c8fe0), update help system (0x005c4660)

    // Phase 5: Sound/Ambience
    // Sound engine tick — ambient, music, 3D positional audio

    // Phase 6: Hand/Gesture processing
    // GInterface* iface = MyInterface();
    // if (iface) { /* CHand::GameTurnUpdate() */ }
    AddPlayerSparkles();
    MobileObject::AddMobileObjectCheckSum();

    // Phase 7: Dead entity cleanup
    GameThing::ProcessDeadList(0);

    // Phase 8: Highlights
    ScriptHighlight::ProcessHighlights();

    // Phase 9: Influence
    Update3DInfluence();

    // Phase 10: Camera validation
    if (camera) {
        camera->CheckStackedModesForValidity();
        camera->Validate();
    }

    // Phase 11: Creature AI events
    // Iterate pending creature event linked list (field_0x205d2c)

    // Phase 12: Save/reload detection
    // Check paused state, turn count, multiplayer status for auto-save/reload
}

void GGame::EndTurn() {
    // Original at 0x0054e960 — turn finalization

    // Phase 1: Sound engine — process 3D audio, ambient, music fade
    // Phase 2: Particle/effect cleanup — iterate effect list, remove expired

    // Phase 3: Map update (only when not paused)
    if ((field_0x14 & 4) == 0) {
        // game_turn > 5: full map cell update pass
        // game_turn <= 5: simplified initial processing path
    }

    // Phase 4: Terrain/Physics cleanup — terrain_map update, physics step finalize

    // Phase 5: Script event check (creature birth trigger)
    // Only if NOT paused, turn count <= 5, NOT multiplayer
    if ((field_0x14 & 4) == 0 && data.game_turn <= 5 &&
        !IsMultiplayerGame() && field_0x205a0c == 0 && field_0x205a14 == 1) {
        // Check creature state for triggering OnBirth script
    }

    // Phase 6: Network processing
    network.Process();

    // Phase 7: Save event detection — time-based auto-save logic
    // Phase 8: FPS calculations — floating point tracking based on turn divisor
}

void GGame::ProcessFrameInputs() {
    // Original at 0x0054c340 — complex input processing
}

void GGame::ProcessGameInputs() {
    // Original at 0x0054c3d0 — complex input processing
}

void GGame::ProcessBufferedKeys() {
    // Original at 0x0054c420 — complex key processing
}

bool GGame::LocalTimerSaysDoATurn() {
    // Original at 0x0054c4a0 — always returns true for single-player
    // In multiplayer, this checks network sync timing
    return !IsMultiplayerGame();
}

void GGame::ProcessNetworkPackets() {
    // Original at 0x0054cc30 — complex network processing
}

void GGame::DisplayPlayerTextMessages() {
    // Original at 0x0054d840 — stub (forwards to GGlobal)
}

void GGame::ClearVariables() {
    // Original at 0x0054bf20 — resets game state variables
}

uint32_t GGame::InitOneTimeOnly() {
    // Original at 0x0054ef40 — one-time-only initialization
    return 0;
}

void GGame::UnfinishInitialisation() {
    // Original at 0x00550080 — complex
}

void GGame::FinishInitialisation() {
    // Original at 0x00550110 — complex
}

void GGame::CreateMeshPack() {
    // Original at 0x00550170 — complex mesh loading
}

bool GGame::LoadFiles() {
    // Original at 0x00550390 — complex file loading
    return false;
}

void GGame::SetupPlayers() {
    // Original at 0x00550410 — complex player setup
}

void GGame::LoopThroughPlayers() {
    // Original at 0x005507d0 — iterates active players for per-frame updates
    GPlayer* player = GetNextActivePlayer(nullptr);
    while (player) {
        // Per-frame: update influence radius, interface state, spell cooldowns
        player = GetNextActivePlayer(player);
    }
}

void GGame::Birthday() {
    // Original at 0x005507f0 — iterate players and call Birthday on each town
    GPlayer* player = GetNextActivePlayer(nullptr);
    while (player) {
        player->Birthday();
        player = GetNextActivePlayer(player);
    }
}

int GGame::MyPlayerID(uint32_t /*param*/) {
    // Original at 0x00550820 — complex
    return 0;
}

GPlayer* GGame::GetNextPlayer(GPlayer* player) {
    // Original at 0x005508a0 — iterate to next player slot
    if (!player) return &players[0];
    uint32_t index = static_cast<uint32_t>(player - &players[0]);
    if (index >= 7) return nullptr;
    return &players[index + 1];
}

GPlayer* GGame::GetNextActivePlayer(GPlayer* player) {
    // Original at 0x005508d0 — iterate to next active (non-NONE) player
    GPlayer* next = GetNextPlayer(player);
    while (next) {
        if (next->type != PLAYER_TYPE_NONE) return next;
        next = GetNextPlayer(next);
    }
    return nullptr;
}

GPlayer* GGame::GetNextActivePlayerAndNeutral(GPlayer* player) {
    // Original at 0x00550930 — iterate to next active player (including neutral)
    if (!player) return &players[0];
    uint32_t index = static_cast<uint32_t>(player - &players[0]);
    for (uint32_t i = index + 1; i < 8; i++) {
        if (players[i].type != PLAYER_TYPE_NONE) return &players[i];
    }
    return nullptr;
}

GPlayer* GGame::GetNextPlayerAndNeutral(GPlayer* player) {
    // Original at 0x00550980 — iterate to next player slot (including neutral at index 7)
    if (!player) return &players[0];
    uint32_t index = static_cast<uint32_t>(player - &players[0]);
    if (index >= 7) return nullptr;
    return &players[index + 1];
}

GPlayer* GGame::GetNextPlayerWithNoCreature(GPlayer* player) {
    // Original at 0x00550a60 — iterate to next player that has no creature
    GPlayer* next = GetNextActivePlayer(player);
    while (next) {
        if (next->creature == nullptr) return next;
        next = GetNextActivePlayer(next);
    }
    return nullptr;
}

GPlayer* GGame::GetPlayerFromReal(uint32_t index) {
    // Original at 0x005509e0 — returns player by real index
    if (index >= 8) return nullptr;
    return &players[index];
}

GInterface* GGame::GetPlayerInterfaceFromReal(uint32_t index) {
    // Original at 0x00550a10 — returns player interface by index
    GPlayer* player = GetPlayerFromReal(index);
    if (player) return player->GetRealInterface(0);
    return nullptr;
}

GTribeInfo* GGame::GetTribe(TRIBE_TYPE /*type*/) {
    // Original at 0x00552620 — complex lookup
    return nullptr;
}

void GGame::AddPlayerSparkles() {
    // Original at 0x00552640 — complex visual effect
}

void GGame::ClearMap() {
    // Original at 0x00552bb0 — complex map cleanup
}

void GGame::StartPlaygroundGame(char* /*map_path*/) {
    // Original at 0x00552f40 — complex
}

bool GGame::IsMultiplayerGame() const {
    // Original at 0x00552fa0
    return network.field_0x0 != 0;
}

Town* GGame::FindTownWithID(uint32_t id) {
    // Original at 0x00552fb0 — iterate town list to find by ID
    // Towns are stored in game_lists.town_list
    Town* town = game_lists.town_list.first;
    while (town) {
        // Compare town's origin/index with requested ID
        if (town->GetOrigin() == id) return town;
        town = town->next;
    }
    return nullptr;
}

void GGame::SetLandBalance(uint32_t /*index*/, float /*balance*/, GPlayer* /*player*/) {
    // Original at 0x00555890 — complex
}

void GGame::OnNewGame() {
    // Original at 0x005538e0 — complex
}

GPlayer* GGame::Update3DInfluence() {
    // Original at 0x00555280 — complex influence update
    return nullptr;
}

void GGame::ResetAndStartPlaygroundGame(char* /*path*/) {
    // Original at 0x00555990 — complex
}

void GGame::ProcessOneSuperpacket() {
    // Original at 0x0063c3d0 — complex network packet processing
}

void GGame::DoNetworkStart() {
    // Original at 0x0054ced0 — complex network initialization
}

// Static methods
void GGame::DoYesNoSkipTutorialRequestersIfNecessary() {
    // Original at 0x0054cbd0 — complex UI requester
}
