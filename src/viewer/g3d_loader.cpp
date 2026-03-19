// G3D mesh pack file loader implementation
// Parses Lionhead's G3D archive format (AllMeshes.g3d)
// Based on openblack's PackFile format documentation

#include "g3d_loader.h"

#include <cstdio>
#include <cstring>

namespace bw {

bool G3DArchive::HasBlock(const std::string& name) const {
    return blocks.find(name) != blocks.end();
}

// Refactored L3D parsing from raw memory buffer (shared with file-based loader)
bool ParseL3DFromMemory(const std::vector<uint8_t>& data, L3DModel& out, int index) {
    if (data.size() < sizeof(L3DHeader)) return false;

    auto At = [&](uint32_t offset, size_t sz) -> const void* {
        if (static_cast<size_t>(offset) + sz > data.size()) return nullptr;
        return data.data() + offset;
    };

    const auto* hdr = reinterpret_cast<const L3DHeader*>(At(0, sizeof(L3DHeader)));
    if (!hdr || memcmp(hdr->magic, "L3D0", 4) != 0) return false;

    out.flags = hdr->flags;
    out.submeshes.clear();
    char name_buf[32];
    snprintf(name_buf, sizeof(name_buf), "mesh_%d", index);
    out.filename = name_buf;

    // submesh_offsets_offset → array of uint32_t offsets
    for (uint32_t s = 0; s < hdr->submesh_count; ++s) {
        uint32_t ot_pos = hdr->submesh_offsets_offset + s * sizeof(uint32_t);
        const auto* sop = reinterpret_cast<const uint32_t*>(At(ot_pos, 4));
        if (!sop) continue;

        const auto* shdr = reinterpret_cast<const L3DSubmeshHeader*>(At(*sop, sizeof(L3DSubmeshHeader)));
        if (!shdr) continue;

        ParsedSubmesh psub;
        psub.flags = shdr->flags;

        for (uint32_t p = 0; p < shdr->num_primitives; ++p) {
            uint32_t pt_pos = shdr->primitives_offset + p * sizeof(uint32_t);
            const auto* pop = reinterpret_cast<const uint32_t*>(At(pt_pos, 4));
            if (!pop) continue;

            const auto* phdr = reinterpret_cast<const L3DPrimitiveHeader*>(At(*pop, sizeof(L3DPrimitiveHeader)));
            if (!phdr) continue;

            PrimitiveGroup pg;
            pg.skin_id = phdr->material.skin_id;
            pg.material_type = phdr->material.type;
            pg.color = phdr->material.color;

            // Vertices
            if (phdr->num_vertices > 0 && phdr->vertices_offset != 0xFFFFFFFF) {
                size_t vb = phdr->num_vertices * sizeof(L3DVertex);
                const auto* vd = At(phdr->vertices_offset, vb);
                if (vd) {
                    pg.vertices.resize(phdr->num_vertices);
                    memcpy(pg.vertices.data(), vd, vb);
                }
            }

            // Triangles
            if (phdr->num_triangles > 0 && phdr->triangles_offset != 0xFFFFFFFF) {
                size_t tb = phdr->num_triangles * 3 * sizeof(uint16_t);
                const auto* td = At(phdr->triangles_offset, tb);
                if (td) {
                    pg.triangles.resize(phdr->num_triangles);
                    memcpy(pg.triangles.data(), td, tb);
                }
            }

            // Vertex groups + bone transforms
            if (!pg.vertices.empty() && !pg.triangles.empty()) {
                std::vector<L3DVertexGroup> groups;
                if (phdr->num_groups > 0 && phdr->groups_offset != 0xFFFFFFFF) {
                    size_t gb = phdr->num_groups * sizeof(L3DVertexGroup);
                    const auto* gd = At(phdr->groups_offset, gb);
                    if (gd) {
                        groups.resize(phdr->num_groups);
                        memcpy(groups.data(), gd, gb);
                    }
                }

                // Apply bone transforms
                if (shdr->num_bones > 0 && shdr->bones_offset != 0xFFFFFFFF && !groups.empty()) {
                    size_t bb = shdr->num_bones * sizeof(L3DBone);
                    const auto* bd = At(shdr->bones_offset, bb);
                    if (bd) {
                        std::vector<L3DBone> bones(shdr->num_bones);
                        memcpy(bones.data(), bd, bb);

                        struct Mat4 { float m[16]; };
                        std::vector<Mat4> bw(shdr->num_bones);

                        for (uint32_t b = 0; b < shdr->num_bones; ++b) {
                            const auto& bn = bones[b];
                            Mat4 loc;
                            loc.m[0]=bn.orientation[0]; loc.m[1]=bn.orientation[1]; loc.m[2]=bn.orientation[2]; loc.m[3]=0;
                            loc.m[4]=bn.orientation[3]; loc.m[5]=bn.orientation[4]; loc.m[6]=bn.orientation[5]; loc.m[7]=0;
                            loc.m[8]=bn.orientation[6]; loc.m[9]=bn.orientation[7]; loc.m[10]=bn.orientation[8]; loc.m[11]=0;
                            loc.m[12]=bn.px; loc.m[13]=bn.py; loc.m[14]=bn.pz; loc.m[15]=1;

                            if (bn.parent != 0xFFFFFFFF && bn.parent < shdr->num_bones) {
                                const float* P = bw[bn.parent].m;
                                const float* L = loc.m;
                                float* R = bw[b].m;
                                for (int r = 0; r < 4; ++r)
                                    for (int c = 0; c < 4; ++c)
                                        R[r*4+c] = L[r*4+0]*P[0*4+c] + L[r*4+1]*P[1*4+c] +
                                                   L[r*4+2]*P[2*4+c] + L[r*4+3]*P[3*4+c];
                            } else {
                                bw[b] = loc;
                            }
                        }

                        uint32_t vi = 0;
                        for (const auto& grp : groups) {
                            if (grp.bone_index < shdr->num_bones) {
                                const float* M = bw[grp.bone_index].m;
                                for (uint16_t j = 0; j < grp.vertex_count && vi < pg.vertices.size(); ++j, ++vi) {
                                    auto& v = pg.vertices[vi];
                                    float ox=v.px, oy=v.py, oz=v.pz;
                                    v.px = M[0]*ox+M[4]*oy+M[8]*oz+M[12];
                                    v.py = M[1]*ox+M[5]*oy+M[9]*oz+M[13];
                                    v.pz = M[2]*ox+M[6]*oy+M[10]*oz+M[14];
                                    float onx=v.nx, ony=v.ny, onz=v.nz;
                                    v.nx = M[0]*onx+M[4]*ony+M[8]*onz;
                                    v.ny = M[1]*onx+M[5]*ony+M[9]*onz;
                                    v.nz = M[2]*onx+M[6]*ony+M[10]*onz;
                                }
                            } else {
                                vi += grp.vertex_count;
                            }
                        }
                    }
                }

                psub.primitives.push_back(std::move(pg));
            }
        }
        if (!psub.primitives.empty())
            out.submeshes.push_back(std::move(psub));
    }

    out.ComputeBounds();
    return !out.submeshes.empty();
}

// ============================================================================
// G3D archive parser
// ============================================================================

#pragma pack(push, 1)
struct PackBlockHeader {
    char     name[32];
    uint32_t size;
};
static_assert(sizeof(PackBlockHeader) == 36, "PackBlockHeader size mismatch");
#pragma pack(pop)

static bool ReadFileContents(const std::string& path, std::vector<uint8_t>& out) {
    FILE* f = fopen(path.c_str(), "rb");
    if (!f) return false;
    fseek(f, 0, SEEK_END);
    long sz = ftell(f);
    fseek(f, 0, SEEK_SET);
    if (sz <= 0) { fclose(f); return false; }
    out.resize(static_cast<size_t>(sz));
    size_t rd = fread(out.data(), 1, out.size(), f);
    fclose(f);
    return rd == out.size();
}

bool LoadG3D(const std::string& path, G3DArchive& out) {
    std::vector<uint8_t> data;
    if (!ReadFileContents(path, data)) {
        fprintf(stderr, "G3D: Failed to read file: %s\n", path.c_str());
        return false;
    }

    // Verify magic
    if (data.size() < 8 || memcmp(data.data(), "LiOnHeAd", 8) != 0) {
        fprintf(stderr, "G3D: Bad magic in %s\n", path.c_str());
        return false;
    }

    printf("G3D: Loading %s (%zu bytes)\n", path.c_str(), data.size());
    fflush(stdout);

    // Parse blocks: after 8-byte magic, read PackBlockHeader + data repeatedly
    size_t pos = 8;
    while (pos + sizeof(PackBlockHeader) <= data.size()) {
        const auto* bhdr = reinterpret_cast<const PackBlockHeader*>(data.data() + pos);
        pos += sizeof(PackBlockHeader);

        std::string block_name(bhdr->name, strnlen(bhdr->name, 32));
        uint32_t block_size = bhdr->size;

        if (pos + block_size > data.size()) {
            fprintf(stderr, "G3D: Block '%s' size %u exceeds file at pos %zu\n",
                    block_name.c_str(), block_size, pos);
            break;
        }

        G3DBlock block;
        block.name = block_name;
        block.data.assign(data.data() + pos, data.data() + pos + block_size);
        out.blocks[block_name] = std::move(block);

        printf("  block: '%s' (%u bytes)\n", block_name.c_str(), block_size);
        pos += block_size;
    }
    fflush(stdout);

    // Parse MESHES block
    auto mit = out.blocks.find("MESHES");
    if (mit == out.blocks.end()) {
        // Try alternate names
        for (auto& [name, block] : out.blocks) {
            if (name.find("MESH") != std::string::npos) {
                mit = out.blocks.find(name);
                break;
            }
        }
    }

    if (mit != out.blocks.end()) {
        const auto& mdata = mit->second.data;
        if (mdata.size() >= 8 && memcmp(mdata.data(), "MKJC", 4) == 0) {
            uint32_t mesh_count = *reinterpret_cast<const uint32_t*>(mdata.data() + 4);
            printf("G3D: MESHES block — %u meshes\n", mesh_count);
            fflush(stdout);

            if (8 + mesh_count * 4 <= mdata.size()) {
                const uint32_t* offsets = reinterpret_cast<const uint32_t*>(mdata.data() + 8);

                out.mesh_blobs.resize(mesh_count);
                out.meshes.resize(mesh_count);

                uint32_t loaded = 0;
                for (uint32_t i = 0; i < mesh_count; ++i) {
                    uint32_t start = offsets[i];
                    uint32_t end = (i + 1 < mesh_count) ? offsets[i + 1] : static_cast<uint32_t>(mdata.size());

                    if (start >= mdata.size() || end > mdata.size() || start >= end)
                        continue;

                    out.mesh_blobs[i].assign(mdata.data() + start, mdata.data() + end);

                    if (ParseL3DFromMemory(out.mesh_blobs[i], out.meshes[i], i)) {
                        loaded++;
                    }
                }
                printf("G3D: Loaded %u / %u meshes successfully\n", loaded, mesh_count);
            }
        } else {
            fprintf(stderr, "G3D: MESHES block missing MKJC magic\n");
        }
    } else {
        fprintf(stderr, "G3D: No MESHES block found\n");
    }

    // Parse texture blocks
    // Each numbered block (hex name like "6e") contains: G3DTextureHeader(16) + DdsHeader(124) + texels
    uint32_t tex_loaded = 0;
    for (auto& [name, block] : out.blocks) {
        // Skip non-texture blocks
        if (name == "INFO" || name == "MESHES" || name.substr(0, 3) == "LOW")
            continue;

        // Check if this is a hex-named texture block
        if (block.data.size() < 16 + 124) continue;

        const auto* thdr = reinterpret_cast<const G3DTextureHeader*>(block.data.data());
        if (thdr->type != 1 && thdr->type != 2) continue; // 1=DXT1, 2=DXT3

        // DDS header starts at offset 16 (after G3DTextureHeader)
        // DDS header is 124 bytes; first field is size (should be 124)
        uint32_t dds_header_size = *reinterpret_cast<const uint32_t*>(block.data.data() + 16);
        if (dds_header_size != 124) continue;

        uint32_t width  = *reinterpret_cast<const uint32_t*>(block.data.data() + 16 + 12); // offset 12 in DDS header
        uint32_t height = *reinterpret_cast<const uint32_t*>(block.data.data() + 16 + 8);  // offset 8 in DDS header

        // Texel data starts after G3DTextureHeader(16) + DdsHeader(124) = 140 bytes
        size_t texel_offset = 16 + 124;
        if (texel_offset >= block.data.size()) continue;

        G3DTexture tex;
        tex.id = thdr->id;
        tex.type = thdr->type;
        tex.width = width;
        tex.height = height;
        tex.texel_data.assign(block.data.data() + texel_offset,
                              block.data.data() + block.data.size());

        out.textures[tex.id] = std::move(tex);
        tex_loaded++;
    }
    printf("G3D: Loaded %u textures\n", tex_loaded);

    fflush(stdout);
    return !out.meshes.empty();
}

} // namespace bw
