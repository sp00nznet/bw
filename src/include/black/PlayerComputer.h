#pragma once
#include "GameThingWithPos.h"

// GComputerAttitudeToPlayer — AI attitude tracking per player
struct GComputerAttitudeToPlayer : public GameThing {
    char*    GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(GComputerAttitudeToPlayer) == 0x14, "GComputerAttitudeToPlayer size mismatch");

// GComputerPlayer — AI player entity (extends GameThingWithPos for map presence)
struct GComputerPlayer : public GameThingWithPos {
    void ToBeDeleted(int param) override;
    GPlayer* GetPlayer() override;
    char*    GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
    void     SaveExtraData(GameOSFile* file) override;
    void     SetSpeedInMetres(float speed, int param2) override;
    const char* GetText() override;
    bool32_t IsComputerPlayer() override;
    uint32_t GetScriptObjectType() override;
};
static_assert(sizeof(GComputerPlayer) == 0x28, "GComputerPlayer size mismatch");

// GComputerPlayerQueue — AI action queue
struct GComputerPlayerQueue : public GameThing {
    char*    GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(GComputerPlayerQueue) == 0x14, "GComputerPlayerQueue size mismatch");

// GComputerSeen — AI awareness tracking
struct GComputerSeen : public GameThing {
    char*    GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(GComputerSeen) == 0x14, "GComputerSeen size mismatch");

// GComputerSpellCast — AI spell casting record
struct GComputerSpellCast : public GameThing {
    char*    GetDebugText() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(GComputerSpellCast) == 0x14, "GComputerSpellCast size mismatch");

// PlayerActionState — player action state (GameThingWithPos-derived)
struct PlayerActionState : public GameThingWithPos {
    void ToBeDeleted(int param) override;
    GPlayer* GetPlayer() override;
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
    void     SaveExtraData(GameOSFile* file) override;
    const char* GetText() override;
};
static_assert(sizeof(PlayerActionState) == 0x28, "PlayerActionState size mismatch");

// PlayerSubAction — player sub-action
struct PlayerSubAction : public GameThing {
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(PlayerSubAction) == 0x14, "PlayerSubAction size mismatch");

// PlayerSubActionArgument — argument data for sub-actions
struct PlayerSubActionArgument : public GameThing {
    uint32_t Load(GameOSFile* file) override;
    uint32_t Save(GameOSFile* file) override;
    uint32_t GetSaveType() override;
};
static_assert(sizeof(PlayerSubActionArgument) == 0x14, "PlayerSubActionArgument size mismatch");
