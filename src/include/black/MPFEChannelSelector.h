#pragma once
// MPFEChannelSelector — multiplayer channel browser dialog
// Struct layout from bw1-decomp (MPFEChannelSelector.h)
//
// Size: 0x58 bytes (extends DialogBoxBase)

#include "DialogBoxBase.h"

struct SetupStaticText;
struct SetupBigButton;
struct SetupEdit;
struct SetupList;
struct SetupButton;
struct SetupCheckBox;

struct MPFEChannelSelector : public DialogBoxBase {
    void Init(uint32_t param_1, uint32_t param_2, DialogBoxCallback callback) override;
    void Destroy() override;
    void Show() override;
    void InitControls() override;

    void RefreshChannelList();

    // === Fields ===
    SetupStaticText* title;                    // 0x10
    SetupStaticText* instructions;             // 0x14
    SetupBigButton*  back_arrow;               // 0x18
    SetupBigButton*  next_arrow;               // 0x1C
    SetupEdit*       field_0x20;               // 0x20
    SetupEdit*       field_0x24;               // 0x24
    SetupList*       field_0x28;               // 0x28
    SetupList*       field_0x2c;               // 0x2C
    SetupButton*     join_help_channel_button; // 0x30
    SetupButton*     refresh_button;           // 0x34
    SetupCheckBox*   resume_checkbox;          // 0x38
    SetupStaticText* current_game_label;       // 0x3C
    SetupStaticText* players_in_game_label;    // 0x40
    SetupStaticText* game_name_label;          // 0x44
    SetupStaticText* field_0x48;               // 0x48
    uint8_t          field_0x4c;               // 0x4C
    uint32_t         field_0x50;               // 0x50
    uint32_t         field_0x54;               // 0x54
};
static_assert(sizeof(MPFEChannelSelector) == 0x58, "MPFEChannelSelector size mismatch");
