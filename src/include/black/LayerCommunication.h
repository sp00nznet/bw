#pragma once
// LayerCommunication — abstract network communication layer
// Struct layout from bw1-decomp (LayerCommunication.h)
//
// Size: 0x4 bytes (vtable only)
// Own vtable hierarchy (17 entries) — NOT related to Base/GameThing
// Unlocks BWGameSpy, BWLan implementations

#include <cstdint>

struct MPFEPlayerDetails;
struct MPFEChannelDetails;

struct LayerCommunication {
    virtual void SendMessageW(wchar_t* message, bool param2, MPFEPlayerDetails* player);
    virtual void SendMessageA(const char* message, bool param2, MPFEPlayerDetails* player);
    virtual void LeaveMainRoom();
    virtual void LeaveGameChannel();
    virtual void BeginPlayerEnumeration();
    virtual void PopulateChannelPlayers(MPFEChannelDetails* channel);
    virtual void Process();
    virtual void InitialiseLobbyState();
    virtual void CreateOrJoinRoom(wchar_t* param1, wchar_t* param2, MPFEChannelDetails* channel);
    virtual void StartGame();
    virtual uint32_t Connect();
    virtual void Disconnect();
    virtual void KickPlayerFromChannel(MPFEPlayerDetails* player);
    virtual void BanPlayerInChannel(MPFEPlayerDetails* player);
    virtual uint32_t GetNumPeopleInRoom();
    virtual void LockChannel(bool lock);
    virtual void SetInvite(bool invite);
};
static_assert(sizeof(LayerCommunication) == 0x4, "LayerCommunication size mismatch");
