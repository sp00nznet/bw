#pragma once
// PSysInterface — particle system interface with extended vtable
// Struct layout from bw1-decomp (PSysInterface.h)
//
// Size: 0x14 bytes (inherits PSysBase, no new fields)
// Extends GameThing vtable with 14 NEW virtual entries at 0xFC+

#include "PSysBase.h"

struct PSysProcessInfo;
struct Spell;
enum PARTICLE_TYPE : uint32_t;

enum PSysInterfaceNetGameType : uint32_t {
    PSysInterface_NET_GAME_TYPE_0 = 0x0,
    _PSysInterface_NET_GAME_TYPE_COUNT = 0x1
};

struct PSysInterface : public PSysBase {
    ~PSysInterface() override;

    // === 14 NEW virtuals at vtable offset 0xFC+ ===
    virtual uint32_t Process_1(const PSysProcessInfo* info, uint32_t param_3);
    virtual void Process_2(PSysProcessInfo* info);
    virtual void Draw_1(float param_1, bool param_2);
    virtual void Draw_2(bool param_1);
    virtual void AddDrawing(float param_1, const LHPoint* param_2);
    virtual void AddTarget_1(const LHPoint* target);
    virtual void AddTarget_2(GameThing* target);
    virtual void CloseDown();
    virtual void SetMagnitude(float value);
    virtual void SetAge(float value);
    virtual void SetOrigin(const LHPoint* value);
    virtual void SetOriginAndMoveAllAtoms(const LHPoint* value);
    virtual void SetAlpha(uint8_t value);
    virtual LHPoint* GetOrigin();
};
static_assert(sizeof(PSysInterface) == 0x14, "PSysInterface size mismatch");
