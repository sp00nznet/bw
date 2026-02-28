#include "black/Chain.h"

Chain::~Chain() {}
char* Chain::GetDebugText() { return nullptr; }
uint32_t Chain::Load(GameOSFile* file) { return 0; }
uint32_t Chain::Save(GameOSFile* file) { return 0; }
uint32_t Chain::GetSaveType() { return 0; }
