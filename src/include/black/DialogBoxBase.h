#pragma once
// DialogBoxBase — base class for all dialog box UI elements
// Struct layout from bw1-decomp (DialogBoxBase.h)
//
// Size: 0x10 bytes
// Own vtable hierarchy (9 entries) — NOT related to Base/GameThing

#include <cstdint>

struct SetupBox;
struct SetupControl;

using DialogBoxCallback = void(__stdcall*)(int, SetupBox*, SetupControl*, int, int);

struct DialogBoxBase {
    virtual void Init(uint32_t param_1, uint32_t param_2, DialogBoxCallback callback);
    virtual void Destroy();
    virtual void InitSubDialogs();
    virtual void Show();
    virtual void CloseNotification();
    virtual bool WantsKeyControl();
    virtual bool WantsMouseControl();
    virtual bool CanESCOut();
    virtual void InitControls();

    // === Fields ===
    SetupBox*       setup_box;   // 0x04
    uint8_t         field_0x8;   // 0x08
    uint8_t         field_0x9;   // 0x09
    uint8_t         field_0xa;   // 0x0A
    uint8_t         field_0xb;   // 0x0B
    DialogBoxBase*  next;        // 0x0C
};
static_assert(sizeof(DialogBoxBase) == 0x10, "DialogBoxBase size mismatch");
