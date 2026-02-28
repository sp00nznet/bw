#include "black/PSysManager.h"

PSysManager::~PSysManager() {}
GPlayer* PSysManager::GetPlayer() { return nullptr; }
char* PSysManager::GetDebugText() { return nullptr; }
uint32_t PSysManager::Load(GameOSFile* file) { return 0; }
uint32_t PSysManager::Save(GameOSFile* file) { return 0; }
uint32_t PSysManager::GetSaveType() { return 0; }
