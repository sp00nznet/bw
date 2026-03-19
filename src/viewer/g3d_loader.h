// G3D mesh pack file loader for Black & White (2001)
// Format documented by the openblack project
// Parses Lionhead's AllMeshes.g3d archive containing all game meshes + textures

#pragma once

#include <cstdint>
#include <map>
#include <string>
#include <vector>

#include "l3d_loader.h"

namespace bw {

// A block within the G3D archive
struct G3DBlock {
    std::string          name;
    std::vector<uint8_t> data;
};

// 16-byte header at the start of each texture block
#pragma pack(push, 1)
struct G3DTextureHeader {
    uint32_t size;
    uint32_t id;
    uint32_t type;      // 1=DXT1, 2=DXT3
    uint32_t dds_size;
};
static_assert(sizeof(G3DTextureHeader) == 16, "G3DTextureHeader size mismatch");
#pragma pack(pop)

// Parsed texture from G3D (DXT compressed)
struct G3DTexture {
    uint32_t             id;        // Matches L3D skin_id
    uint32_t             type;      // 1=DXT1, 2=DXT3
    uint32_t             width;
    uint32_t             height;
    std::vector<uint8_t> texel_data; // Raw DXT compressed pixels (no headers)
};

// The full G3D archive
struct G3DArchive {
    std::map<std::string, G3DBlock>   blocks;
    std::map<uint32_t, G3DTexture>    textures;  // keyed by texture ID
    std::vector<std::vector<uint8_t>> mesh_blobs;
    std::vector<L3DModel>             meshes;

    bool HasBlock(const std::string& name) const;
    size_t MeshCount() const { return meshes.size(); }
};

// Load a G3D archive from disk. Returns true on success.
bool LoadG3D(const std::string& path, G3DArchive& out);

// Parse a single L3D mesh from a raw data blob
bool ParseL3DFromMemory(const std::vector<uint8_t>& data, L3DModel& out, int index);

} // namespace bw
