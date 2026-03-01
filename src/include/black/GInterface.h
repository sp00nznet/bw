#pragma once
// GInterface — main game interface controller
// Struct layout from bw1-decomp (Interface.h)
//
// Size: 0x47C bytes (extends GameThingWithPos)

#include "GameThingWithPos.h"
#include "GInterfaceCollide.h"
#include "GInterfaceFlags.h"
#include "InterfaceHandState.h"
#include "GInterfaceMessageBuffer.h"

struct CHand;
struct GInterfaceStatus;
struct GPlayer;
struct LHCoord;
struct LHPlayer;
struct Leash;
struct LiquidParticleGroup;
enum INTERFACE_MESSAGE_TYPES : uint32_t;

struct GInterface : public GameThingWithPos {
    ~GInterface() override;
    void ToBeDeleted(int param) override;
    int Get3DSoundPos(LHPoint* pos) override;
    GPlayer* GetPlayer() override;
    char* GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
    void SaveExtraData(GameOSFile* file) override;
    void ResolveLoad() override;
    bool32_t IsActive() const override;
    const char* GetText() override;

    void SetToZero();
    void Init(uint8_t param);
    void InitLeash();
    void SetupHand();
    void PreDrawProcess();
    void PostDrawProcess();
    void Process();
    void UpdateHandRenderCollide();
    void UpdateAllLeashes();
    void SendMessage(INTERFACE_MESSAGE_TYPES type, LHCoord* coord);

    // === Fields ===
    uint32_t                field_0x28;       // 0x28
    LiquidParticleGroup*    liquid_particle_group;  // 0x2C
    GInterfaceFlags         flags;            // 0x30
    int                     field_0x44;       // 0x44
    uint32_t                field_0x48;       // 0x48
    uint32_t                field_0x4c;       // 0x4C
    uint8_t                 file[0x8];        // 0x50  (LHReleasedOSFile)
    uint8_t                 field_0x58[0x104]; // 0x58
    uint32_t                is_specific_playback; // 0x15C
    uint32_t                is_any_playback;  // 0x160
    uint8_t                 field_0x164[0x30]; // 0x164
    uint32_t                field_0x194;      // 0x194
    Leash*                  leash_0x198;      // 0x198
    Leash*                  leash_0x19c;      // 0x19C
    Leash*                  leash_0x1a0;      // 0x1A0
    uint32_t                field_0x1a4;      // 0x1A4
    uint32_t                field_0x1a8;      // 0x1A8
    uint32_t                field_0x1ac;      // 0x1AC
    uint32_t                field_0x1b0;      // 0x1B0
    uint32_t                field_0x1b4;      // 0x1B4
    uint32_t                field_0x1b8;      // 0x1B8
    LHPlayer*               lh_player;        // 0x1BC
    uint8_t                 field_0x1c0[0x1A0]; // 0x1C0
    uint32_t                field_0x360;      // 0x360
    uint32_t                field_0x364;      // 0x364
    uint32_t                field_0x368;      // 0x368
    uint32_t                field_0x36c;      // 0x36C
    uint32_t                field_0x370;      // 0x370
    uint32_t                field_0x374;      // 0x374
    uint32_t                field_0x378;      // 0x378
    uint32_t                field_0x37c;      // 0x37C
    uint32_t                field_0x380;      // 0x380
    uint32_t                field_0x384;      // 0x384
    uint32_t                field_0x388;      // 0x388
    uint32_t                field_0x38c;      // 0x38C
    uint32_t                field_0x390;      // 0x390
    uint32_t                field_0x394;      // 0x394
    uint32_t                field_0x398;      // 0x398
    GInterfaceStatus*       status;           // 0x39C
    CHand*                  hand;             // 0x3A0
    InterfaceHandState      hand_state;       // 0x3A4
    GInterfaceCollide       interface_collide;     // 0x3B0
    GInterfaceCollide       interface_collide_2;   // 0x3E0
    float                   field_0x410;      // 0x410
    float                   field_0x414;      // 0x414
    uint32_t                field_0x418;      // 0x418
    uint32_t                field_0x41c;      // 0x41C
    uint32_t                field_0x420;      // 0x420
    uint32_t                field_0x424;      // 0x424
    uint32_t                field_0x428;      // 0x428
    uint32_t                field_0x42c;      // 0x42C
    GInterfaceMessageBuffer message_buffers;  // 0x430
    int                     field_0x444;      // 0x444
    int                     field_0x448;      // 0x448
    uint32_t                field_0x44c;      // 0x44C
    uint32_t                field_0x450;      // 0x450
    uint32_t                field_0x454;      // 0x454
    uint32_t                field_0x458;      // 0x458
    uint8_t                 field_0x45c[0xC]; // 0x45C  (BaseInfo)
    uint32_t                field_0x468;      // 0x468
    uint32_t                field_0x46c;      // 0x46C
    uint32_t                field_0x470;      // 0x470
    uint32_t                field_0x474;      // 0x474
    uint32_t                field_0x478;      // 0x478
};
static_assert(sizeof(GInterface) == 0x47C, "GInterface size mismatch");
