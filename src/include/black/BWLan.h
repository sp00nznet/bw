#pragma once
// BWLan — LAN network communication layer
// Struct layout from bw1-decomp (BWLan.h)
//
// Size: 0x4 bytes (inherits LayerCommunication, no new fields)

#include "LayerCommunication.h"

struct MPFEChannelDetails;
struct MPFEPlayerDetails;

struct BWLan : public LayerCommunication {
    void SendMessageW(wchar_t* message, bool param2, MPFEPlayerDetails* player) override;
    void SendMessageA(const char* message, bool param2, MPFEPlayerDetails* player) override;
    void LeaveMainRoom() override;
    void LeaveGameChannel() override;
    void BeginPlayerEnumeration() override;
    void PopulateChannelPlayers(MPFEChannelDetails* channel) override;
    void Process() override;
    void InitialiseLobbyState() override;
    void CreateOrJoinRoom(wchar_t* param1, wchar_t* param2, MPFEChannelDetails* channel) override;
    void StartGame() override;
    uint32_t Connect() override;
};
static_assert(sizeof(BWLan) == 0x4, "BWLan size mismatch");
