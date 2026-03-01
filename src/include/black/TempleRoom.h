#pragma once
// TempleRoom — base class for citadel interior rooms
// Struct layout from bw1-decomp (TempleRoom.h)
//
// Size: 0xEC bytes
// Own vtable hierarchy (16 entries) — NOT related to Base/GameThing
// Also defines InnerRoom (0x2C, plain data) and TempleRoomsEnum

#include <cstdint>
#include "LHCoord.h"

struct Zoomer3d;
struct InnerRoom;
struct InnerCamera;
enum INTERFACE_MESSAGE_TYPES : uint32_t;
enum BINDABLE_ACTIONS : uint32_t;
enum LH_KEY : uint32_t;

enum TempleRoomsEnum : uint32_t {
    TEMPLE_ROOM_WORLD       = 0x0,
    TEMPLE_ROOM_CREATURE    = 0x1,
    TEMPLE_ROOM_CHALLENGE   = 0x2,
    TEMPLE_ROOM_UNIVERSE    = 0x3,
    TEMPLE_ROOM_OPTIONS     = 0x4,
    TEMPLE_ROOM_SAVEGAME    = 0x5,
    TEMPLE_ROOM_CREDITS     = 0x6,
    _TempleRoomsEnum_COUNT  = 0x7
};

struct InnerRoom {
    uint32_t field_0x0;     // 0x00
    uint32_t field_0x4;     // 0x04
    uint32_t field_0x8;     // 0x08
    float    field_0xc;     // 0x0C
    uint8_t  field_0x10;    // 0x10
    uint8_t  pad_0x11[3];   // 0x11
    uint32_t field_0x14;    // 0x14
    uint32_t field_0x18;    // 0x18
    uint32_t field_0x1c;    // 0x1C
    uint32_t field_0x20;    // 0x20
    uint32_t field_0x24;    // 0x24
    uint32_t field_0x28;    // 0x28
};
static_assert(sizeof(InnerRoom) == 0x2C, "InnerRoom size mismatch");

struct TempleRoom {
    virtual bool IsAvailable();
    virtual void DrawAdditional(bool param);
    virtual void PreDraw();
    virtual void Draw();
    virtual void DrawHand();
    virtual void Update();
    virtual void UpdateMouse(LHCoord coord, INTERFACE_MESSAGE_TYPES message_type);
    virtual void UpdateKeyboard(LH_KEY key, uint16_t param);
    virtual void TriggerIntroCamera(bool param, Zoomer3d* zoomer1, Zoomer3d* zoomer2);
    virtual void InitEngine_0();
    virtual void InitEngine_1(char* param1, char* param2, char* param3, char* param4);
    virtual void CloseEngine();
    virtual void CalculateTooltipsInsideCitadel(BINDABLE_ACTIONS* actions);
    virtual void PreToolTipProcess();
    virtual void PostToolTipProcess();
    virtual void OnEnterRoom();

    // === Fields ===
    char         name[0x20];       // 0x04
    uint32_t     field_0x24;       // 0x24
    uint32_t     field_0x28;       // 0x28
    uint32_t     field_0x2c;       // 0x2C
    uint32_t     field_0x30;       // 0x30
    int32_t      field_0x34;       // 0x34
    int32_t      field_0x38;       // 0x38
    uint8_t      field_0x3c[0x40]; // 0x3C
    uint32_t     field_0x7c;       // 0x7C
    uint8_t      field_0x80[0x40]; // 0x80
    InnerRoom*   inner_room;       // 0xC0
    InnerCamera* camera;           // 0xC4
    int32_t      field_0xc8;       // 0xC8
    uint8_t      field_0xcc[0x4];  // 0xCC
    uint32_t     field_0xd0;       // 0xD0
    uint32_t     field_0xd4;       // 0xD4
    uint32_t     field_0xd8;       // 0xD8
    uint32_t     field_0xdc;       // 0xDC
    uint32_t     field_0xe0;       // 0xE0
    float        field_0xe4;       // 0xE4
    float        field_0xe8;       // 0xE8
};
static_assert(sizeof(TempleRoom) == 0xEC, "TempleRoom size mismatch");
