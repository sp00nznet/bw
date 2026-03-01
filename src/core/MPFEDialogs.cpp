#include "../include/black/MPFEDatabase.h"
#include "../include/black/MPFEDownloads.h"
#include "../include/black/MPFEChooseConnection.h"
#include "../include/black/MPFEChannelSelector.h"
#include "../include/black/MPFECreateGame.h"
#include "../include/black/MPFEFindGame.h"
#include "../include/black/MPFELogin.h"

// MPFEDatabase
void MPFEDatabase::DatabaseError() {}
void MPFEDatabase::DatabaseComplete() {}

// MPFEDownloads
void MPFEDownloads::GetFileNumber(uint32_t param_1) {}
void MPFEDownloads::Refresh() {}
void MPFEDownloads::Stop() {}
void MPFEDownloads::FileCompleted() {}
void MPFEDownloads::FileError() {}

// MPFEChooseConnection
void MPFEChooseConnection::Destroy() {}

// MPFEChannelSelector
void MPFEChannelSelector::Init(uint32_t param_1, uint32_t param_2, DialogBoxCallback callback) {}
void MPFEChannelSelector::Destroy() {}
void MPFEChannelSelector::Show() {}
void MPFEChannelSelector::InitControls() {}
void MPFEChannelSelector::RefreshChannelList() {}

// MPFECreateGame
void MPFECreateGame::Init(uint32_t param_1, uint32_t param_2, DialogBoxCallback callback) {}
void MPFECreateGame::Destroy() {}

// MPFEFindGame
void MPFEFindGame::Init(uint32_t param_1, uint32_t param_2, DialogBoxCallback callback) {}
void MPFEFindGame::Destroy() {}

// MPFELogin
void MPFELogin::Init(uint32_t param_1, uint32_t param_2, DialogBoxCallback callback) {}
void MPFELogin::Destroy() {}
void MPFELogin::InitControls() {}
