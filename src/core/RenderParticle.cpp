#include "black/RenderParticle.h"

RenderParticle::~RenderParticle() {}
char* RenderParticle::GetDebugText() { return nullptr; }
uint32_t RenderParticle::Load(GameOSFile* file) { return 0; }
uint32_t RenderParticle::Save(GameOSFile* file) { return 0; }
uint32_t RenderParticle::GetSaveType() { return 0; }
