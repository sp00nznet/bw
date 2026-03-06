#pragma once
// FrontEnd — front-end UI state manager
// Struct layout from bw1-decomp
// Size: 0x500 bytes

#include <stdint.h>

struct ChannelBox;
struct CDBox;
struct EditingDebugBox;
struct EndGameBox;
struct GatheringBox;
struct GSLobbyBox;
struct HistoryBox;
struct LH3DMaterial;
struct LoadingBox;
struct LobbyBox;
struct LoginBox;
struct MainMenu;
struct MultiplayerConditionBox;
struct NewProfileBox;
struct Plasma;
struct ProfileEditor;
struct RegisterBox;
struct SetupMultiplayerMain;
struct SetupOnlineLandscapes;
struct SkipBox;
struct SkirmishGameBox;
struct StartGameBox;
struct StatsBox;
struct TattooEditor;

struct FrontEnd {
    bool                       cursor_on;                  // 0x00
    ChannelBox*                channel_box;                // 0x04
    EditingDebugBox*           editing_debug_box;          // 0x08
    SetupMultiplayerMain*      setup_multiplayer_main;     // 0x0C
    SetupOnlineLandscapes*     setup_online_landscapes;    // 0x10
    SkipBox*                   skip_box;                   // 0x14
    CDBox*                     cd_box;                     // 0x18
    GatheringBox*              gathering_box;              // 0x1C
    LoadingBox*                loading_box;                // 0x20
    GSLobbyBox*                gs_lobby_box;               // 0x24
    LobbyBox*                  lobby_box;                  // 0x28
    RegisterBox*               register_box;               // 0x2C
    LoginBox*                  login_box;                  // 0x30
    TattooEditor*              tattoo_editor;              // 0x34
    NewProfileBox*             new_profile_box;            // 0x38
    MainMenu*                  main_menu;                  // 0x3C
    ProfileEditor*             profile_editor;             // 0x40
    uint32_t                   field_0x44;                 // 0x44
    uint8_t                    field_0x48[0x34];           // 0x48
    uint8_t                    field_0x7c[0x40];           // 0x7C
    bool                       field_0xbc;                 // 0xBC
    bool                       field_0xbd;                 // 0xBD
    uint8_t                    field_0xbe;                 // 0xBE
    uint8_t                    field_0xbf;                 // 0xBF
    uint32_t                   field_0xc0;                 // 0xC0
    uint32_t                   field_0xc4;                 // 0xC4
    Plasma*                    plasma;                     // 0xC8
    LH3DMaterial*              field_0xcc;                 // 0xCC
    LH3DMaterial*              field_0xd0;                 // 0xD0
    LH3DMaterial*              field_0xd4;                 // 0xD4
    uint8_t                    field_0xd8[0x400];          // 0xD8
    float                      field_0x4d8;                // 0x4D8
    int                        field_0x4dc;                // 0x4DC
    bool                       field_0x4e0;                // 0x4E0
    bool                       field_0x4e1;                // 0x4E1
    bool                       field_0x4e2;                // 0x4E2
    bool                       field_0x4e3;                // 0x4E3
    bool                       field_0x4e4;                // 0x4E4
    bool                       field_0x4e5;                // 0x4E5
    uint8_t                    field_0x4e6;                // 0x4E6
    uint8_t                    field_0x4e7;                // 0x4E7
    StatsBox*                  stats_box;                  // 0x4E8
    EndGameBox*                end_game_box;               // 0x4EC
    MultiplayerConditionBox*   multiplayer_condition_box;  // 0x4F0
    StartGameBox*              start_game_box;             // 0x4F4
    HistoryBox*                history_box;                // 0x4F8
    SkirmishGameBox*           skirmish_game_box;          // 0x4FC
};
static_assert(sizeof(FrontEnd) == 0x500, "FrontEnd size mismatch");
