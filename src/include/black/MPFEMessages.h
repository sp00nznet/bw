#pragma once
// MPFEMessages — all multiplayer frontend message subclasses
// All inherit MPFEMessageObject (0x4) with no new fields
// Each has its own vtable but only overrides the destructor
// (MPFEUserTeamList also overrides Send)
//
// 26 types, all 0x4 bytes

#include "MPFEMessageObject.h"

struct MPFEPlayerDetails;

struct MPFEAskJoinMessage : public MPFEMessageObject {};
static_assert(sizeof(MPFEAskJoinMessage) == 0x4, "MPFEAskJoinMessage size mismatch");

struct MPFECancelStartMessage : public MPFEMessageObject {};
static_assert(sizeof(MPFECancelStartMessage) == 0x4, "MPFECancelStartMessage size mismatch");

struct MPFEChangeClanRequest : public MPFEMessageObject {};
static_assert(sizeof(MPFEChangeClanRequest) == 0x4, "MPFEChangeClanRequest size mismatch");

struct MPFEChangedMapMessage : public MPFEMessageObject {};
static_assert(sizeof(MPFEChangedMapMessage) == 0x4, "MPFEChangedMapMessage size mismatch");

struct MPFEChangedTeamRequestMessage : public MPFEMessageObject {};
static_assert(sizeof(MPFEChangedTeamRequestMessage) == 0x4, "MPFEChangedTeamRequestMessage size mismatch");

struct MPFEClanList : public MPFEMessageObject {};
static_assert(sizeof(MPFEClanList) == 0x4, "MPFEClanList size mismatch");

struct MPFECondtionUpdateMessage : public MPFEMessageObject {};
static_assert(sizeof(MPFECondtionUpdateMessage) == 0x4, "MPFECondtionUpdateMessage size mismatch");

struct MPFEDatabaseID : public MPFEMessageObject {};
static_assert(sizeof(MPFEDatabaseID) == 0x4, "MPFEDatabaseID size mismatch");

struct MPFEDisconnectNowMessage : public MPFEMessageObject {};
static_assert(sizeof(MPFEDisconnectNowMessage) == 0x4, "MPFEDisconnectNowMessage size mismatch");

struct MPFEFileTransferMessage : public MPFEMessageObject {};
static_assert(sizeof(MPFEFileTransferMessage) == 0x4, "MPFEFileTransferMessage size mismatch");

struct MPFEHasCreature : public MPFEMessageObject {};
static_assert(sizeof(MPFEHasCreature) == 0x4, "MPFEHasCreature size mismatch");

struct MPFEInviteToTeamMessage : public MPFEMessageObject {};
static_assert(sizeof(MPFEInviteToTeamMessage) == 0x4, "MPFEInviteToTeamMessage size mismatch");

struct MPFEKickMessage : public MPFEMessageObject {};
static_assert(sizeof(MPFEKickMessage) == 0x4, "MPFEKickMessage size mismatch");

struct MPFEKickMessageRequest : public MPFEMessageObject {};
static_assert(sizeof(MPFEKickMessageRequest) == 0x4, "MPFEKickMessageRequest size mismatch");

struct MPFEMapErrorMessage : public MPFEMessageObject {};
static_assert(sizeof(MPFEMapErrorMessage) == 0x4, "MPFEMapErrorMessage size mismatch");

struct MPFEPrivateChatMessage : public MPFEMessageObject {};
static_assert(sizeof(MPFEPrivateChatMessage) == 0x4, "MPFEPrivateChatMessage size mismatch");

struct MPFEPublicChatMessage : public MPFEMessageObject {};
static_assert(sizeof(MPFEPublicChatMessage) == 0x4, "MPFEPublicChatMessage size mismatch");

struct MPFEReadyMessage : public MPFEMessageObject {};
static_assert(sizeof(MPFEReadyMessage) == 0x4, "MPFEReadyMessage size mismatch");

struct MPFEReplyToInviteMessage : public MPFEMessageObject {};
static_assert(sizeof(MPFEReplyToInviteMessage) == 0x4, "MPFEReplyToInviteMessage size mismatch");

struct MPFEReplyToJoinMessage : public MPFEMessageObject {};
static_assert(sizeof(MPFEReplyToJoinMessage) == 0x4, "MPFEReplyToJoinMessage size mismatch");

struct MPFEStartGameNowMessage : public MPFEMessageObject {};
static_assert(sizeof(MPFEStartGameNowMessage) == 0x4, "MPFEStartGameNowMessage size mismatch");

struct MPFEStartGameOkayToStartMessage : public MPFEMessageObject {};
static_assert(sizeof(MPFEStartGameOkayToStartMessage) == 0x4, "MPFEStartGameOkayToStartMessage size mismatch");

struct MPFEStartGameReadyMessage : public MPFEMessageObject {};
static_assert(sizeof(MPFEStartGameReadyMessage) == 0x4, "MPFEStartGameReadyMessage size mismatch");

struct MPFEStartGameTransferFilesMessage : public MPFEMessageObject {};
static_assert(sizeof(MPFEStartGameTransferFilesMessage) == 0x4, "MPFEStartGameTransferFilesMessage size mismatch");

struct MPFETeamsReadyList : public MPFEMessageObject {};
static_assert(sizeof(MPFETeamsReadyList) == 0x4, "MPFETeamsReadyList size mismatch");

struct MPFEUserTeamList : public MPFEMessageObject {
    void Send(MPFEPlayerDetails* details) override;
};
static_assert(sizeof(MPFEUserTeamList) == 0x4, "MPFEUserTeamList size mismatch");
