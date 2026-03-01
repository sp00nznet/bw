#include "../include/black/PSysPCreator.h"

// RenderParticleCreatureRef
RenderParticleCreatureRef::~RenderParticleCreatureRef() {}
char* RenderParticleCreatureRef::GetDebugText() { return nullptr; }

// RenderParticleGJMesh
RenderParticleGJMesh::~RenderParticleGJMesh() {}

// RenderParticleGJMeshRotatingUV
RenderParticleGJMeshRotatingUV::~RenderParticleGJMeshRotatingUV() {}

// RenderParticleGameObject
RenderParticleGameObject::~RenderParticleGameObject() {}
char* RenderParticleGameObject::GetDebugText() { return nullptr; }

// RenderParticleGameObjectRef
RenderParticleGameObjectRef::~RenderParticleGameObjectRef() {}
char* RenderParticleGameObjectRef::GetDebugText() { return nullptr; }
uint32_t RenderParticleGameObjectRef::Load(GameOSFile* file) { return 0; }

// RenderParticleGoldenShower
RenderParticleGoldenShower::~RenderParticleGoldenShower() {}
char* RenderParticleGoldenShower::GetDebugText() { return nullptr; }

// RenderParticleMist
RenderParticleMist::~RenderParticleMist() {}
char* RenderParticleMist::GetDebugText() { return nullptr; }

// RenderParticleVolBlendMesh
RenderParticleVolBlendMesh::~RenderParticleVolBlendMesh() {}
