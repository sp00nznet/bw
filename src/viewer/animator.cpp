// animator — see animator.h.

#include "animator.h"

#include <cmath>

namespace bw {

namespace {

// Multiply two 4x4 column-major matrices: out = A * B.
inline void Mul4x4(const float* A, const float* B, float* out) {
    for (int r = 0; r < 4; ++r) {
        for (int c = 0; c < 4; ++c) {
            out[r*4+c] = A[r*4+0]*B[0*4+c] + A[r*4+1]*B[1*4+c] +
                         A[r*4+2]*B[2*4+c] + A[r*4+3]*B[3*4+c];
        }
    }
}

// Build a local transform from a bone's 3x3 orientation + translation,
// then post-multiply by a small Y-axis rotation `delta_y_rad`.
void BoneLocalWithDelta(const L3DBone& bn, float delta_y_rad,
                        float delta_x_rad, BoneMatrix& out) {
    BoneMatrix base;
    base.m[ 0] = bn.orientation[0]; base.m[ 1] = bn.orientation[1]; base.m[ 2] = bn.orientation[2]; base.m[ 3] = 0;
    base.m[ 4] = bn.orientation[3]; base.m[ 5] = bn.orientation[4]; base.m[ 6] = bn.orientation[5]; base.m[ 7] = 0;
    base.m[ 8] = bn.orientation[6]; base.m[ 9] = bn.orientation[7]; base.m[10] = bn.orientation[8]; base.m[11] = 0;
    base.m[12] = bn.px;             base.m[13] = bn.py;             base.m[14] = bn.pz;             base.m[15] = 1;

    if (delta_y_rad == 0.0f && delta_x_rad == 0.0f) {
        out = base;
        return;
    }

    // Compose: out = base * Ry(delta_y) * Rx(delta_x). Pre-multiplying the
    // rotation onto the local transform rotates the bone (and all children)
    // by `delta` in the bone's parent frame.
    float cy = cosf(delta_y_rad), sy = sinf(delta_y_rad);
    float cx = cosf(delta_x_rad), sx = sinf(delta_x_rad);

    BoneMatrix rot;
    rot.m[ 0] = cy;       rot.m[ 1] = 0;     rot.m[ 2] = -sy;      rot.m[ 3] = 0;
    rot.m[ 4] = sy*sx;    rot.m[ 5] = cx;    rot.m[ 6] = cy*sx;    rot.m[ 7] = 0;
    rot.m[ 8] = sy*cx;    rot.m[ 9] = -sx;   rot.m[10] = cy*cx;    rot.m[11] = 0;
    rot.m[12] = 0;        rot.m[13] = 0;     rot.m[14] = 0;        rot.m[15] = 1;

    Mul4x4(rot.m, base.m, out.m);  // Apply rotation in local-bone frame
}

// Returns the per-bone (delta_y_rad, delta_x_rad) for the given mode + time.
void PickBoneDeltas(AnimMode mode, uint32_t bone_index, uint32_t total_bones,
                    float t, float* out_dy, float* out_dx) {
    *out_dy = 0; *out_dx = 0;
    if (bone_index == 0) return;  // root stays put — entity transform owns it

    float idx_n = static_cast<float>(bone_index) / static_cast<float>(total_bones);

    switch (mode) {
    case AnimMode::Static:
        return;

    case AnimMode::Idle: {
        // Small global sway + small per-bone breathing offset.
        float amp = 0.025f + idx_n * 0.015f;
        *out_dy = sinf(t * 1.4f + bone_index * 0.27f) * amp;
        *out_dx = sinf(t * 1.8f + bone_index * 0.11f) * amp * 0.5f;
        return;
    }

    case AnimMode::Walk: {
        // Larger amplitude, phase-flipped on alternating bones — gait-like.
        float phase = (bone_index & 1) ? 0.0f : 3.14159265f;
        float amp = 0.10f + idx_n * 0.05f;
        *out_dx = sinf(t * 6.0f + phase) * amp;
        *out_dy = sinf(t * 6.0f + phase + 0.5f) * amp * 0.4f;
        return;
    }

    case AnimMode::AnimalIdle: {
        float amp = 0.05f + idx_n * 0.03f;
        *out_dy = sinf(t * 1.7f + bone_index * 0.3f) * amp;
        *out_dx = sinf(t * 2.3f + bone_index * 0.15f) * amp * 0.6f;
        return;
    }

    case AnimMode::BirdFlap: {
        // Flap fast and wide on outer bones (assume wings = higher index).
        float amp = idx_n * 0.5f + 0.1f;
        *out_dx = sinf(t * 9.0f) * amp;
        return;
    }
    }
}

} // namespace

std::vector<BoneMatrix> PoseSubmesh(const ParsedSubmesh& submesh,
                                    AnimMode mode,
                                    float time_seconds,
                                    float phase_offset) {
    std::vector<BoneMatrix> pose;
    if (submesh.bones.empty() || mode == AnimMode::Static) {
        return pose;  // Empty = use bind_world fallback in RenderModel
    }

    const uint32_t n = static_cast<uint32_t>(submesh.bones.size());
    pose.resize(n);

    float t = time_seconds + phase_offset;

    // Build perturbed local transforms then accumulate world matrices.
    for (uint32_t b = 0; b < n; ++b) {
        float dy, dx;
        PickBoneDeltas(mode, b, n, t, &dy, &dx);

        BoneMatrix local;
        BoneLocalWithDelta(submesh.bones[b], dy, dx, local);

        const uint32_t parent = submesh.bones[b].parent;
        if (parent != 0xFFFFFFFFu && parent < n) {
            Mul4x4(local.m, pose[parent].m, pose[b].m);
        } else {
            pose[b] = local;
        }
    }
    return pose;
}

} // namespace bw
