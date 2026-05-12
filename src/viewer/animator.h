// animator — produces per-frame bone poses for entities, layered on top of
// the L3D bind pose. Real ANM parsing is deferred; this delivers visible
// skeletal motion (breathing, idle sway, walking gait) procedurally by
// perturbing each bone's local transform.

#pragma once

#include "l3d_loader.h"
#include <cstdint>
#include <vector>

namespace bw {

enum class AnimMode : uint8_t {
    Static    = 0,  // bind pose, no animation
    Idle      = 1,  // gentle breathing — small oscillation on most bones
    Walk      = 2,  // walking gait — alternating leg/arm swing
    AnimalIdle= 3,  // larger sway for quadrupeds
    BirdFlap  = 4,  // wing flapping for birds
};

// Build an animated pose for a submesh's skeleton. Returns the posed
// matrices that replace `submesh.bind_world` for this draw call. Empty
// vector if the submesh has no bones.
std::vector<BoneMatrix> PoseSubmesh(const ParsedSubmesh& submesh,
                                    AnimMode mode,
                                    float time_seconds,
                                    float phase_offset);

} // namespace bw
