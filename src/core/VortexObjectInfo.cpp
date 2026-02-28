#include "black/VortexObjectInfo.h"

VortexObjectInfo::~VortexObjectInfo() {}
char* VortexObjectInfo::GetDebugText() { return nullptr; }
uint32_t VortexObjectInfo::Load(GameOSFile* file) { return 0; }
uint32_t VortexObjectInfo::Save(GameOSFile* file) { return 0; }
uint32_t VortexObjectInfo::GetSaveType() { return 0; }
