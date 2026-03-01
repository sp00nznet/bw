#include "../include/black/PSysAtomCore.h"

// AtomCore
AtomCore::~AtomCore() {}
char* AtomCore::GetDebugText() { return nullptr; }
uint32_t AtomCore::Load(GameOSFile* file) { return 0; }
uint32_t AtomCore::Save(GameOSFile* file) { return 0; }
uint32_t AtomCore::GetSaveType() { return 0; }

// UR_GesturingRecognised_AtomData
UR_GesturingRecognised_AtomData::~UR_GesturingRecognised_AtomData() {}

// UR_Plasma_AtomData
UR_Plasma_AtomData::~UR_Plasma_AtomData() {}
char* UR_Plasma_AtomData::GetDebugText() { return nullptr; }
uint32_t UR_Plasma_AtomData::Load(GameOSFile* file) { return 0; }
uint32_t UR_Plasma_AtomData::Save(GameOSFile* file) { return 0; }
uint32_t UR_Plasma_AtomData::GetSaveType() { return 0; }

// UR_Plasma_SubCollectionData
UR_Plasma_SubCollectionData::~UR_Plasma_SubCollectionData() {}
char* UR_Plasma_SubCollectionData::GetDebugText() { return nullptr; }
uint32_t UR_Plasma_SubCollectionData::Load(GameOSFile* file) { return 0; }
uint32_t UR_Plasma_SubCollectionData::Save(GameOSFile* file) { return 0; }
uint32_t UR_Plasma_SubCollectionData::GetSaveType() { return 0; }
