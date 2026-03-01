#include "../include/black/Particle3DAnim.h"
#include "../include/black/Particle3DAnimWithCamera.h"
#include "../include/black/Particle3DObj.h"
#include "../include/black/Particle3DObjAnimTextured.h"
#include "../include/black/Particle3DPnt.h"
#include "../include/black/Particle3DSprite.h"
#include "../include/black/ParticleChainJoint.h"
#include "../include/black/ParticleLightMap.h"
#include "../include/black/ParticlePlayerSymbol.h"

// Particle3DAnim
Particle3DAnim::~Particle3DAnim() {}
char* Particle3DAnim::GetDebugText() { return nullptr; }

// Particle3DAnimWithCamera
Particle3DAnimWithCamera::~Particle3DAnimWithCamera() {}

// Particle3DObj
Particle3DObj::~Particle3DObj() {}
char* Particle3DObj::GetDebugText() { return nullptr; }

// Particle3DObjAnimTextured
Particle3DObjAnimTextured::~Particle3DObjAnimTextured() {}

// Particle3DPnt
Particle3DPnt::~Particle3DPnt() {}
char* Particle3DPnt::GetDebugText() { return nullptr; }
uint32_t Particle3DPnt::Load(GameOSFile* file) { return 0; }
uint32_t Particle3DPnt::Save(GameOSFile* file) { return 0; }
uint32_t Particle3DPnt::GetSaveType() { return 0; }

// Particle3DSprite
Particle3DSprite::~Particle3DSprite() {}
char* Particle3DSprite::GetDebugText() { return nullptr; }
uint32_t Particle3DSprite::Load(GameOSFile* file) { return 0; }

// ParticleChainJoint
ParticleChainJoint::~ParticleChainJoint() {}
char* ParticleChainJoint::GetDebugText() { return nullptr; }
uint32_t ParticleChainJoint::Load(GameOSFile* file) { return 0; }
uint32_t ParticleChainJoint::Save(GameOSFile* file) { return 0; }
uint32_t ParticleChainJoint::GetSaveType() { return 0; }

// ParticleLightMap
ParticleLightMap::~ParticleLightMap() {}
char* ParticleLightMap::GetDebugText() { return nullptr; }
uint32_t ParticleLightMap::Load(GameOSFile* file) { return 0; }

// ParticlePlayerSymbol
ParticlePlayerSymbol::~ParticlePlayerSymbol() {}
