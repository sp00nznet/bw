#include "black/LayerCommunication.h"

void LayerCommunication::SendMessageW(wchar_t* message, bool param2, MPFEPlayerDetails* player) {}
void LayerCommunication::SendMessageA(const char* message, bool param2, MPFEPlayerDetails* player) {}
void LayerCommunication::LeaveMainRoom() {}
void LayerCommunication::LeaveGameChannel() {}
void LayerCommunication::BeginPlayerEnumeration() {}
void LayerCommunication::PopulateChannelPlayers(MPFEChannelDetails* channel) {}
void LayerCommunication::Process() {}
void LayerCommunication::InitialiseLobbyState() {}
void LayerCommunication::CreateOrJoinRoom(wchar_t* param1, wchar_t* param2, MPFEChannelDetails* channel) {}
void LayerCommunication::StartGame() {}
uint32_t LayerCommunication::Connect() { return 0; }
void LayerCommunication::Disconnect() {}
void LayerCommunication::KickPlayerFromChannel(MPFEPlayerDetails* player) {}
void LayerCommunication::BanPlayerInChannel(MPFEPlayerDetails* player) {}
uint32_t LayerCommunication::GetNumPeopleInRoom() { return 0; }
void LayerCommunication::LockChannel(bool lock) {}
void LayerCommunication::SetInvite(bool invite) {}
