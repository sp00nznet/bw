#pragma once
// GInterfaceStatus — per-player interface state
// Struct layout from bw1-decomp (InterfaceStatus.h)
//
// Size: 0x134 bytes (extends GameThingWithPos)

#include "GameThingWithPos.h"
#include "GMagicHand.h"
#include "LHCoord.h"

struct GGuidance;
struct GInterface;
struct GLeashStatus;
struct GPlayer;
struct GVirtualInfluence;
struct Object;
struct PSysProcessInfo;
struct Spell;

struct GInterfaceStatus : public GameThingWithPos {
    ~GInterfaceStatus() override;
    void ToBeDeleted(int param) override;
    GPlayer* GetPlayer() override;
    void UpdateSpellInfo(Spell* spell, PSysProcessInfo* info) override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
    void SaveExtraData(GameOSFile* file) override;
    void ResolveLoad() override;
    const char* GetText() override;

    static void SetActive(int param);
    static void ResetActionState();

    void SetToZero(GInterface* iface);
    void* GetFirstObjectInCurrentHand();
    bool IsSpaceInHands();
    GInterface* GetInterface();
    void Init(uint8_t player_number, GInterface* iface);

    // === Fields ===
    uint8_t              player_number;     // 0x28
    uint8_t              pad_0x29[3];       // 0x29
    GInterface*          iface;             // 0x2C
    GGuidance*           guidance;          // 0x30
    uint32_t             field_0x34;        // 0x34
    uint32_t             field_0x38;        // 0x38
    uint32_t             field_0x3c;        // 0x3C
    uint32_t             field_0x40;        // 0x40
    uint8_t              field_0x44[0x14];  // 0x44
    GMagicHand           magic_hand[2];     // 0x58
    bool                 hand_holding_something; // 0x90
    uint8_t              pad_0x91[3];       // 0x91
    LHCoord              field_0x94;        // 0x94
    uint32_t             field_0x9c;        // 0x9C
    uint32_t             field_0xa0;        // 0xA0
    LHPoint              field_0xa4;        // 0xA4
    LHPoint              camera_pos;        // 0xB0
    LHPoint              camera_foc;        // 0xBC
    LHPoint              field_0xc8;        // 0xC8
    LHPoint              field_0xd4;        // 0xD4
    uint32_t             field_0xe0;        // 0xE0
    uint32_t             field_0xe4;        // 0xE4
    LHPoint              field_0xe8;        // 0xE8
    float                field_0xf4;        // 0xF4
    float                field_0xf8;        // 0xF8
    float                field_0xfc;        // 0xFC
    float                field_0x100;       // 0x100
    float                field_0x104;       // 0x104
    float                field_0x108;       // 0x108
    LHPoint              hand_velocity;     // 0x10C
    float                field_0x118;       // 0x118
    uint32_t             field_0x11c;       // 0x11C
    Object*              last_dropped_object; // 0x120
    uint32_t             field_0x124;       // 0x124
    GLeashStatus*        leash_status;      // 0x128
    GVirtualInfluence*   influence;         // 0x12C
    float                field_0x130;       // 0x130
};
static_assert(sizeof(GInterfaceStatus) == 0x134, "GInterfaceStatus size mismatch");
