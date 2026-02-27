#include "black/PlayerComputer.h"

// GComputerAttitudeToPlayer
char*    GComputerAttitudeToPlayer::GetDebugText() { return "GComputerAttitudeToPlayer"; }
uint32_t GComputerAttitudeToPlayer::Load(GameOSFile* file) { return 0; }
uint32_t GComputerAttitudeToPlayer::Save(GameOSFile* file) { return 0; }
uint32_t GComputerAttitudeToPlayer::GetSaveType() { return 0; }

// GComputerPlayer
void     GComputerPlayer::ToBeDeleted(int param) {}
GPlayer* GComputerPlayer::GetPlayer() { return nullptr; }
char*    GComputerPlayer::GetDebugText() { return "GComputerPlayer"; }
uint32_t GComputerPlayer::Load(GameOSFile* file) { return 0; }
uint32_t GComputerPlayer::Save(GameOSFile* file) { return 0; }
uint32_t GComputerPlayer::GetSaveType() { return 0; }
void     GComputerPlayer::SaveExtraData(GameOSFile* file) {}
void     GComputerPlayer::SetSpeedInMetres(float speed, int param2) {}
const char* GComputerPlayer::GetText() { return ""; }
bool32_t GComputerPlayer::IsComputerPlayer() { return 1; }
uint32_t GComputerPlayer::GetScriptObjectType() { return 0; }

// GComputerPlayerQueue
char*    GComputerPlayerQueue::GetDebugText() { return "GComputerPlayerQueue"; }
uint32_t GComputerPlayerQueue::Load(GameOSFile* file) { return 0; }
uint32_t GComputerPlayerQueue::Save(GameOSFile* file) { return 0; }
uint32_t GComputerPlayerQueue::GetSaveType() { return 0; }

// GComputerSeen
char*    GComputerSeen::GetDebugText() { return "GComputerSeen"; }
uint32_t GComputerSeen::Load(GameOSFile* file) { return 0; }
uint32_t GComputerSeen::Save(GameOSFile* file) { return 0; }
uint32_t GComputerSeen::GetSaveType() { return 0; }

// GComputerSpellCast
char*    GComputerSpellCast::GetDebugText() { return "GComputerSpellCast"; }
uint32_t GComputerSpellCast::Load(GameOSFile* file) { return 0; }
uint32_t GComputerSpellCast::Save(GameOSFile* file) { return 0; }
uint32_t GComputerSpellCast::GetSaveType() { return 0; }

// PlayerActionState
void     PlayerActionState::ToBeDeleted(int param) {}
GPlayer* PlayerActionState::GetPlayer() { return nullptr; }
uint32_t PlayerActionState::Load(GameOSFile* file) { return 0; }
uint32_t PlayerActionState::Save(GameOSFile* file) { return 0; }
uint32_t PlayerActionState::GetSaveType() { return 0; }
void     PlayerActionState::SaveExtraData(GameOSFile* file) {}
const char* PlayerActionState::GetText() { return ""; }

// PlayerSubAction
uint32_t PlayerSubAction::Load(GameOSFile* file) { return 0; }
uint32_t PlayerSubAction::Save(GameOSFile* file) { return 0; }
uint32_t PlayerSubAction::GetSaveType() { return 0; }

// PlayerSubActionArgument
uint32_t PlayerSubActionArgument::Load(GameOSFile* file) { return 0; }
uint32_t PlayerSubActionArgument::Save(GameOSFile* file) { return 0; }
uint32_t PlayerSubActionArgument::GetSaveType() { return 0; }
