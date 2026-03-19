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

// Texture from G3D (DXT compressed)
struct G3DTexture {
    uint32_t             size;
    uint32_t             id;
    uint32_t             type;      // DXT format type
    uint32_t             dds_size;
    std::vector<uint8_t> dds_data;  // Raw DDS data (after header)
};

// The full G3D archive
struct G3DArchive {
    std::map<std::string, G3DBlock>   blocks;
    std::map<std::string, G3DTexture> textures;
    std::vector<std::vector<uint8_t>> mesh_blobs;   // Raw L3D data per mesh
    std::vector<L3DModel>             meshes;        // Parsed L3D models

    bool HasBlock(const std::string& name) const;
    size_t MeshCount() const { return meshes.size(); }
};

// Load a G3D archive from disk. Returns true on success.
bool LoadG3D(const std::string& path, G3DArchive& out);

// Parse a single L3D mesh from a raw data blob (used internally)
bool ParseL3DFromMemory(const std::vector<uint8_t>& data, L3DModel& out, int index);

} // namespace bw
