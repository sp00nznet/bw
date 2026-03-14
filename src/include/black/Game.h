#pragma once
// GGame — the god struct containing all game state
// Struct layout from bw1-decomp
//
// Size: 0x250544 bytes (2,363,716 bytes = ~2.25 MB)
// Contains embedded GMap (2 MB), 8 GPlayers, landscape, script engine, etc.
// Inherits from GameThing (0x14 bytes)
//
// There is exactly one GGame instance per game session (g_game global).

#include "CreatureDatabase.h"
#include "GData.h"
#include "GKeyBuffer.h"
#include "GLandscape.h"
#include "GLanguage.h"
#include "GNetwork.h"
#include "GPlayerInfo.h"
#include "GTerrainMap.h"
#include "GameThing.h"
#include "GlobalGameLists.h"
#include "LHTimer.h"
#include "Map.h"
#include "PathCreator.h"
#include "Player.h"
#include "ScriptCreatureCurse.h"
#include "StatsDatabase.h"
#include "types.h"

// Forward declarations
enum PLAYER_NAME : uint32_t;
enum TRIBE_TYPE : uint32_t;
struct Config;
struct ControlMap;
struct DialogBoxKeyBinding;
struct DialogBoxOptions;
struct DialogBoxSaveMessage;
struct GCamera;
struct GClimate;
struct GInterface;
struct GScript;
struct GSoundMap;
struct GestureSystem;
struct GestureSystemData;
struct GestureSystemDataList;
struct GestureSystemResult;
struct GTribeInfo;
struct HelpProfile;
struct HelpSystem;
struct LHFilePath;
struct Settings;
struct Temple;
struct Town;

// Game mode enum
enum GAME_MODE : uint32_t {
    GAME_MODE_RUNNING  = 0,
    GAME_MODE_1        = 1,
    GAME_MODE_2        = 2,
    GAME_MODE_ONLINE   = 3,
    GAME_MODE_4        = 4,
    GAME_MODE_SKIRMISH = 5,
    GAME_MODE_QUITTING = 6,
};

struct GGame : public GameThing {
    // === Fields (fully typed from vendor Game.h) ===

    uint32_t          field_0x14;                 // 0x14
    GPlayer           players[8];                 // 0x18  (8 * 0xA60 = 0x5300)
    uint8_t           field_0x5318[0x664];        // 0x5318 — gap to stats DB
    StatsDatabase     stats_database;             // 0x597C (0x10)
    CreatureDatabase  creature_database;          // 0x598C (0x10)
    bool              field_0x599c;               // 0x599C
    uint8_t           field_0x599d;               // 0x599D
    uint8_t           field_0x599e;               // 0x599E
    uint8_t           field_0x599f;               // 0x599F
    uint32_t          field_0x59a0;               // 0x59A0
    uint32_t          field_0x59a4;               // 0x59A4
    uint8_t           field_0x59a8[0xC];          // 0x59A8
    Temple*           temple;                     // 0x59B4
    GMap              map;                        // 0x59B8 (0x200050)
    int32_t           land_number;                // 0x205A08 — current land/level number
    uint32_t          field_0x205a0c;             // 0x205A0C
    int               field_0x205a10;             // 0x205A10
    uint32_t          field_0x205a14;             // 0x205A14
    int               field_0x205a18;             // 0x205A18
    int               field_0x205a1c;             // 0x205A1C
    GLandscape        landscape;                  // 0x205A20 (0x8)
    uint32_t          field_0x205a28;             // 0x205A28
    uint32_t          field_0x205a2c;             // 0x205A2C
    GData             data;                       // 0x205A30 (0x28)
    uint8_t           field_0x205a58;             // 0x205A58
    uint8_t           player_index;               // 0x205A59
    uint8_t           field_0x205a5a;             // 0x205A5A
    uint8_t           neutral_player_index;       // 0x205A5B
    uint32_t          field_0x205a5c;             // 0x205A5C
    uint8_t           field_0x205a60;             // 0x205A60
    uint8_t           field_0x205a61;             // 0x205A61
    uint8_t           field_0x205a62;             // 0x205A62
    uint8_t           field_0x205a63;             // 0x205A63
    uint32_t          field_0x205a64;             // 0x205A64
    MapCoords         coords_0x205a68;            // 0x205A68
    MapCoords         coords_0x205a74;            // 0x205A74
    uint8_t           field_0x205a80[0xF0];       // 0x205A80
    GNetwork          network;                    // 0x205B70 (0x14)
    uint8_t           field_0x205b84[0x20];       // 0x205B84
    GlobalGameLists   game_lists;                 // 0x205BA4 (0x190)
    uint32_t          field_0x205d34;             // 0x205D34
    int               fps_0x205d38;               // 0x205D38
    uint32_t          field_0x205d3c;             // 0x205D3C
    int               field_0x205d40;             // 0x205D40
    uint32_t          field_0x205d44;             // 0x205D44
    int               field_0x205d48;             // 0x205D48
    uint8_t           field_0x205d4c[0xC];        // 0x205D4C
    int               field_0x205d58;             // 0x205D58
    uint32_t          field_0x205d5c;             // 0x205D5C
    uint32_t          field_0x205d60;             // 0x205D60
    float             field_0x205d64;             // 0x205D64
    LHTimer           timer;                      // 0x205D68 (0x110)
    uint8_t           field_0x205e78[0x14];       // 0x205E78
    GTerrainMap       terrain_map;                // 0x205E8C (0x4A130)
    GPlayerInfo       player_info;                // 0x24FFBC (0x90)
    GLanguage         language;                   // 0x25004C (0xC)
    GSoundMap*        sound_map;                  // 0x250058
    HelpSystem*       help_system;                // 0x25005C
    HelpProfile*      help_profile;               // 0x250060
    GestureSystemDataList* gesture_system_data_list; // 0x250064
    GestureSystemData*     gesture_system_data;   // 0x250068
    GestureSystem*         gesture_system;        // 0x25006C
    GestureSystemResult*   gesture_system_result;  // 0x250070
    Settings*         settings;                   // 0x250074
    float             town_influence_multiplier;  // 0x250078
    float             player_influence_multiplier; // 0x25007C
    uint32_t          field_0x250080;             // 0x250080
    ScriptCreatureCurse script_creature_curse;    // 0x250084 (0xC)
    GScript*          script;                     // 0x250090
    uint32_t          field_0x250094;             // 0x250094
    uint32_t          field_0x250098;             // 0x250098
    MapCoords         start_camera_coords;        // 0x25009C (0xC)
    uint8_t           field_0x2500a8[0xC8];       // 0x2500A8
    char*             field_0x250170;             // 0x250170
    uint32_t          field_0x250174;             // 0x250174
    Config*           config;                     // 0x250178
    uint32_t          enum_0x25017c;              // 0x25017C
    GAME_MODE         game_mode;                  // 0x250180
    uint8_t           field_0x250184[0x124];      // 0x250184
    GKeyBuffer        key_buffer;                 // 0x2502A8 (0x10)
    uint32_t          field_0x2502b8;             // 0x2502B8
    uint32_t          field_0x2502bc;             // 0x2502BC
    GCamera*          camera;                     // 0x2502C0
    uint32_t          field_0x2502c4;             // 0x2502C4
    uint32_t          field_0x2502c8;             // 0x2502C8
    uint8_t           field_0x2502cc;             // 0x2502CC
    uint8_t           field_0x2502cd;             // 0x2502CD
    uint8_t           field_0x2502ce;             // 0x2502CE
    uint8_t           field_0x2502cf;             // 0x2502CF
    uint8_t           field_0x2502d0[0x14];       // 0x2502D0
    LHFilePath*       field_0x2502e4;             // 0x2502E4
    uint8_t           field_0x2502e8[0x18];       // 0x2502E8
    ControlMap*       control_map;                // 0x250300
    DialogBoxOptions*     dialog_box_options;      // 0x250304
    DialogBoxKeyBinding*  dialog_box_key_binding;  // 0x250308
    DialogBoxSaveMessage* dialog_box_save_message; // 0x25030C
    PathCreator       path_creator;               // 0x250310 (0x220)
    uint32_t          field_0x250530;             // 0x250530
    GClimate*         climate;                    // 0x250534
    uint32_t          field_0x250538;             // 0x250538
    uint32_t          field_0x25053c;             // 0x25053C
    int               field_0x250540;             // 0x250540

    // === Virtual overrides (GameThing) ===
    bool IsAvailable() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
    void ResolveLoad() override;
    void Delete(int param) override;
    void ToBeDeleted(int param) override;
    void Dump() override;

    // === Non-virtual methods ===
    void Init();
    void Loop();
    void StartGame();
    void ProcessOneGameTurn();
    void ProcessGameCode();
    void ProcessGraphicsEngine(uint32_t param1, uint32_t param2);
    void Process3dEngine();
    void StartTurn();
    void ProcessTurn();
    void EndTurn();
    void ProcessFrameInputs();
    void ProcessGameInputs();
    void ProcessBufferedKeys();
    bool LocalTimerSaysDoATurn();
    void ProcessNetworkPackets();
    void DisplayPlayerTextMessages();
    void ClearVariables();
    uint32_t InitOneTimeOnly();
    bool InitInner();
    void UnfinishInitialisation();
    void FinishInitialisation();
    void CreateMeshPack();
    bool LoadFiles();
    void SetupPlayers();
    void LoopThroughPlayers();
    void Birthday();
    void ClearMap();
    void OnNewGame();
    void AddPlayerSparkles();
    GPlayer* GetPlayer(uint32_t index);
    GPlayer* GetPlayer(PLAYER_NAME name);
    GPlayer* GetPlayerFromReal(uint32_t index);
    GPlayer* GetNextPlayer(GPlayer* player);
    GPlayer* GetNextActivePlayer(GPlayer* player);
    GPlayer* GetNextActivePlayerAndNeutral(GPlayer* player);
    GPlayer* GetNextPlayerAndNeutral(GPlayer* player);
    GPlayer* GetNextPlayerWithNoCreature(GPlayer* player);
    GInterface* GetPlayerInterfaceFromReal(uint32_t index);
    GInterface* MyInterface();
    GCamera* GetCamera();
    GTribeInfo* GetTribe(TRIBE_TYPE type);
    Town* FindTownWithID(uint32_t id);
    int MyPlayerID(uint32_t param);
    bool IsMultiplayerGame() const;
    void SetLandBalance(uint32_t index, float balance, GPlayer* player);
    void StartPlaygroundGame(char* map_path);
    void ResetAndStartPlaygroundGame(char* path);
    GPlayer* Update3DInfluence();
    void ProcessOneSuperpacket();
    void DoNetworkStart();

    // Static methods
    static void DoYesNoSkipTutorialRequestersIfNecessary();
};
static_assert(sizeof(GGame) == 0x250544, "GGame size mismatch");

// Global game instance (the one and only)
extern GGame* g_game;
