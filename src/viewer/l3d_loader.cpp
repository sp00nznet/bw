// L3D mesh file loader implementation
// Parses Lionhead's .L3D binary format into renderable mesh data
// Based on openblack's format documentation

#include "l3d_loader.h"

#include <algorithm>
#include <cstdio>
#include <cstring>
#include <limits>

namespace bw {

void L3DModel::ComputeBounds() {
    min_x = min_y = min_z =  std::numeric_limits<float>::max();
    max_x = max_y = max_z = -std::numeric_limits<float>::max();

    for (const auto& sub : submeshes) {
        for (const auto& prim : sub.primitives) {
            for (const auto& v : prim.vertices) {
                min_x = std::min(min_x, v.px);
                min_y = std::min(min_y, v.py);
                min_z = std::min(min_z, v.pz);
                max_x = std::max(max_x, v.px);
                max_y = std::max(max_y, v.py);
                max_z = std::max(max_z, v.pz);
            }
        }
    }
    if (min_x > max_x) { min_x = max_x = 0; min_y = max_y = 0; min_z = max_z = 0; }
}

float L3DModel::GetExtent() const {
    float dx = max_x - min_x;
    float dy = max_y - min_y;
    float dz = max_z - min_z;
    return std::max({dx, dy, dz, 0.001f});
}

uint32_t L3DModel::TotalVertices() const {
    uint32_t n = 0;
    for (const auto& sub : submeshes)
        for (const auto& prim : sub.primitives)
            n += static_cast<uint32_t>(prim.vertices.size());
    return n;
}

uint32_t L3DModel::TotalTriangles() const {
    uint32_t n = 0;
    for (const auto& sub : submeshes)
        for (const auto& prim : sub.primitives)
            n += static_cast<uint32_t>(prim.triangles.size());
    return n;
}

static bool ReadFile(const std::string& path, std::vector<uint8_t>& out) {
    FILE* f = fopen(path.c_str(), "rb");
    if (!f) return false;
    fseek(f, 0, SEEK_END);
    long size = ftell(f);
    fseek(f, 0, SEEK_SET);
    if (size <= 0) { fclose(f); return false; }
    out.resize(static_cast<size_t>(size));
    size_t read = fread(out.data(), 1, out.size(), f);
    fclose(f);
    return read == out.size();
}

template<typename T>
static const T* At(const std::vector<uint8_t>& data, uint32_t offset) {
    if (static_cast<size_t>(offset) + sizeof(T) > data.size()) return nullptr;
    return reinterpret_cast<const T*>(data.data() + offset);
}

bool LoadL3D(const std::string& path, L3DModel& out) {
    std::vector<uint8_t> data;
    if (!ReadFile(path, data)) {
        fprintf(stderr, "L3D: Failed to read file: %s\n", path.c_str());
        return false;
    }

    if (data.size() < sizeof(L3DHeader)) {
        fprintf(stderr, "L3D: File too small: %s (%zu bytes)\n", path.c_str(), data.size());
        return false;
    }

    const auto* hdr = At<L3DHeader>(data, 0);
    if (!hdr || memcmp(hdr->magic, "L3D0", 4) != 0) {
        fprintf(stderr, "L3D: Bad magic in %s\n", path.c_str());
        return false;
    }

    out.filename = path;
    out.flags = hdr->flags;
    out.submeshes.clear();

    printf("L3D: %s — flags=0x%08X, size=%u, submeshes=%u, skins=%u\n",
           path.c_str(), hdr->flags, hdr->size, hdr->submesh_count, hdr->skin_count);
    fflush(stdout);

    // The submesh offsets table: array of uint32_t offsets, one per submesh
    for (uint32_t s = 0; s < hdr->submesh_count; ++s) {
        // Read submesh offset from the offset table
        uint32_t offset_table_pos = hdr->submesh_offsets_offset + s * sizeof(uint32_t);
        const auto* sub_offset_ptr = At<uint32_t>(data, offset_table_pos);
        if (!sub_offset_ptr) {
            fprintf(stderr, "L3D: Submesh offset %u out of bounds\n", s);
            continue;
        }
        uint32_t sub_offset = *sub_offset_ptr;

        const auto* shdr = At<L3DSubmeshHeader>(data, sub_offset);
        if (!shdr) {
            fprintf(stderr, "L3D: Submesh %u header out of bounds at 0x%X\n", s, sub_offset);
            continue;
        }

        ParsedSubmesh psub;
        psub.flags = shdr->flags;

        printf("  submesh[%u]: flags=0x%X, prims=%u, bones=%u, offset=0x%X\n",
               s, shdr->flags, shdr->num_primitives, shdr->num_bones, sub_offset);
        fflush(stdout);

        // primitives_offset points to an OFFSET TABLE (array of uint32_t),
        // each entry is the file offset to the actual L3DPrimitiveHeader
        for (uint32_t p = 0; p < shdr->num_primitives; ++p) {
            uint32_t prim_ofs_table_pos = shdr->primitives_offset + p * sizeof(uint32_t);
            const auto* prim_offset_ptr = At<uint32_t>(data, prim_ofs_table_pos);
            if (!prim_offset_ptr) {
                fprintf(stderr, "L3D: Primitive offset %u.%u out of bounds\n", s, p);
                continue;
            }
            uint32_t prim_offset = *prim_offset_ptr;
            const auto* phdr = At<L3DPrimitiveHeader>(data, prim_offset);
            if (!phdr) {
                fprintf(stderr, "L3D: Primitive %u.%u header out of bounds\n", s, p);
                continue;
            }

            PrimitiveGroup pg;
            pg.skin_id = phdr->material.skin_id;
            pg.material_type = phdr->material.type;
            pg.color = phdr->material.color;

            printf("    prim[%u] at 0x%X: mat_type=%u skin=%u nverts=%u voff=0x%X ntris=%u toff=0x%X\n",
                   p, prim_offset, phdr->material.type, phdr->material.skin_id,
                   phdr->num_vertices, phdr->vertices_offset,
                   phdr->num_triangles, phdr->triangles_offset);
            fflush(stdout);

            // Read vertices
            if (phdr->num_vertices > 0 && phdr->vertices_offset > 0 &&
                phdr->vertices_offset != 0xFFFFFFFF) {
                size_t end = static_cast<size_t>(phdr->vertices_offset) +
                             phdr->num_vertices * sizeof(L3DVertex);
                if (end <= data.size()) {
                    pg.vertices.resize(phdr->num_vertices);
                    memcpy(pg.vertices.data(),
                           data.data() + phdr->vertices_offset,
                           phdr->num_vertices * sizeof(L3DVertex));
                }
            }

            // Read triangles (num_triangles × 3 × uint16_t indices)
            if (phdr->num_triangles > 0 && phdr->triangles_offset > 0 &&
                phdr->triangles_offset != 0xFFFFFFFF) {
                size_t tri_bytes = phdr->num_triangles * 3 * sizeof(uint16_t);
                size_t end = static_cast<size_t>(phdr->triangles_offset) + tri_bytes;
                if (end <= data.size()) {
                    pg.triangles.resize(phdr->num_triangles);
                    memcpy(pg.triangles.data(),
                           data.data() + phdr->triangles_offset,
                           tri_bytes);
                }
            }

            // Read vertex groups (bone assignments)
            std::vector<L3DVertexGroup> groups;
            if (phdr->num_groups > 0 && phdr->groups_offset > 0 &&
                phdr->groups_offset != 0xFFFFFFFF) {
                size_t end = static_cast<size_t>(phdr->groups_offset) +
                             phdr->num_groups * sizeof(L3DVertexGroup);
                if (end <= data.size()) {
                    groups.resize(phdr->num_groups);
                    memcpy(groups.data(), data.data() + phdr->groups_offset,
                           phdr->num_groups * sizeof(L3DVertexGroup));
                }
            }

            if (!pg.vertices.empty() && !pg.triangles.empty()) {
                printf("    prim[%u]: %zu verts, %zu tris, skin=%u, mat=%u\n",
                       p, pg.vertices.size(), pg.triangles.size(), pg.skin_id, pg.material_type);

                // Build the bone_per_vertex table from the vertex groups
                // (vertex groups are an RLE list: each group covers
                // `vertex_count` consecutive vertices owned by `bone_index`).
                if (shdr->num_bones > 0 && !groups.empty()) {
                    pg.bone_per_vertex.assign(pg.vertices.size(), 0xFFFFu);
                    uint32_t vert_idx = 0;
                    for (const auto& grp : groups) {
                        for (uint16_t vi = 0; vi < grp.vertex_count &&
                                              vert_idx < pg.vertices.size();
                             ++vi, ++vert_idx) {
                            pg.bone_per_vertex[vert_idx] = grp.bone_index;
                        }
                    }
                }

                psub.primitives.push_back(std::move(pg));
            }
        }

        // Load the bone hierarchy + compute bind-pose world matrices once
        // per submesh. Re-used every frame by SkinPrimitive.
        if (shdr->num_bones > 0 && shdr->bones_offset > 0 &&
            shdr->bones_offset != 0xFFFFFFFF) {
            size_t bone_end = static_cast<size_t>(shdr->bones_offset) +
                              shdr->num_bones * sizeof(L3DBone);
            if (bone_end <= data.size()) {
                psub.bones.resize(shdr->num_bones);
                memcpy(psub.bones.data(), data.data() + shdr->bones_offset,
                       shdr->num_bones * sizeof(L3DBone));

                psub.bind_world.resize(shdr->num_bones);
                for (uint32_t b = 0; b < shdr->num_bones; ++b) {
                    const auto& bn = psub.bones[b];
                    // Local transform: 3x3 row-major orientation + translation.
                    BoneMatrix local;
                    local.m[ 0] = bn.orientation[0]; local.m[ 1] = bn.orientation[1]; local.m[ 2] = bn.orientation[2]; local.m[ 3] = 0;
                    local.m[ 4] = bn.orientation[3]; local.m[ 5] = bn.orientation[4]; local.m[ 6] = bn.orientation[5]; local.m[ 7] = 0;
                    local.m[ 8] = bn.orientation[6]; local.m[ 9] = bn.orientation[7]; local.m[10] = bn.orientation[8]; local.m[11] = 0;
                    local.m[12] = bn.px;             local.m[13] = bn.py;             local.m[14] = bn.pz;             local.m[15] = 1;

                    if (bn.parent != 0xFFFFFFFFu && bn.parent < shdr->num_bones) {
                        const float* P = psub.bind_world[bn.parent].m;
                        const float* L = local.m;
                        float* R = psub.bind_world[b].m;
                        for (int r = 0; r < 4; ++r) {
                            for (int c = 0; c < 4; ++c) {
                                R[r*4+c] = L[r*4+0]*P[0*4+c] + L[r*4+1]*P[1*4+c] +
                                           L[r*4+2]*P[2*4+c] + L[r*4+3]*P[3*4+c];
                            }
                        }
                    } else {
                        psub.bind_world[b] = local;
                    }
                }
                printf("      (kept skeleton: %u bones)\n", shdr->num_bones);
            }
        }

        if (!psub.primitives.empty()) {
            out.submeshes.push_back(std::move(psub));
        }
    }

    out.ComputeBounds();
    fflush(stdout);

    printf("L3D: Total: %u verts, %u tris, bounds [%.2f,%.2f,%.2f]-[%.2f,%.2f,%.2f]\n",
           out.TotalVertices(), out.TotalTriangles(),
           out.min_x, out.min_y, out.min_z, out.max_x, out.max_y, out.max_z);
    fflush(stdout);

    return !out.submeshes.empty();
}

// ============================================================================
// CPU skinning
// ============================================================================

void SkinPrimitive(const PrimitiveGroup& prim,
                   const std::vector<BoneMatrix>& pose,
                   std::vector<float>& out_pos,
                   std::vector<float>& out_normal) {
    const size_t n = prim.vertices.size();
    out_pos.resize(n * 3);
    out_normal.resize(n * 3);

    const bool skinned = !pose.empty() && !prim.bone_per_vertex.empty() &&
                         prim.bone_per_vertex.size() == n;

    for (size_t i = 0; i < n; ++i) {
        const L3DVertex& v = prim.vertices[i];

        uint16_t bone = skinned ? prim.bone_per_vertex[i] : uint16_t(0xFFFFu);
        if (bone == 0xFFFFu || bone >= pose.size()) {
            // Unskinned vertex (or out-of-range bone) — pass through.
            out_pos[i*3 + 0]    = v.px;
            out_pos[i*3 + 1]    = v.py;
            out_pos[i*3 + 2]    = v.pz;
            out_normal[i*3 + 0] = v.nx;
            out_normal[i*3 + 1] = v.ny;
            out_normal[i*3 + 2] = v.nz;
            continue;
        }

        const float* M = pose[bone].m;
        out_pos[i*3 + 0]    = M[0]*v.px + M[4]*v.py + M[ 8]*v.pz + M[12];
        out_pos[i*3 + 1]    = M[1]*v.px + M[5]*v.py + M[ 9]*v.pz + M[13];
        out_pos[i*3 + 2]    = M[2]*v.px + M[6]*v.py + M[10]*v.pz + M[14];
        out_normal[i*3 + 0] = M[0]*v.nx + M[4]*v.ny + M[ 8]*v.nz;
        out_normal[i*3 + 1] = M[1]*v.nx + M[5]*v.ny + M[ 9]*v.nz;
        out_normal[i*3 + 2] = M[2]*v.nx + M[6]*v.ny + M[10]*v.nz;
    }
}

} // namespace bw
