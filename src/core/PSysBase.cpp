#include "black/PSysBase.h"

PSysBase::~PSysBase() {}
char* PSysBase::GetDebugText() { return nullptr; }
uint32_t PSysBase::Load(GameOSFile* file) { return 0; }
