#pragma once
// MPFELogin — multiplayer login dialog
// Struct layout from bw1-decomp (MPFELogin.h)
//
// MPFELogin (0x5C, extends DialogBoxBase)
// MPFELoginDatabase (0xC, extends MPFEDatabase)

#include "DialogBoxBase.h"
#include "MPFEDatabase.h"

struct SetupBigButton;
struct SetupEdit;
struct SetupStaticText;

struct MPFELogin : public DialogBoxBase {
    void Init(uint32_t param_1, uint32_t param_2, DialogBoxCallback callback) override;
    void Destroy() override;
    void InitControls() override;

    // === Fields ===
    SetupBigButton*  left_arrow_button;   // 0x10
    SetupBigButton*  right_arrow_button;  // 0x14
    SetupEdit*       edit;                // 0x18
    SetupEdit*       edit2;               // 0x1C
    SetupStaticText* text1;               // 0x20
    SetupStaticText* text2;               // 0x24
    SetupStaticText* text3;               // 0x28
    MPFEDatabase     database;            // 0x2C
    void*            field_0x38;          // 0x38
    char             field_0x3c[0x20];    // 0x3C
};
static_assert(sizeof(MPFELogin) == 0x5C, "MPFELogin size mismatch");

struct MPFELoginDatabase : public MPFEDatabase {};
static_assert(sizeof(MPFELoginDatabase) == 0xC, "MPFELoginDatabase size mismatch");
