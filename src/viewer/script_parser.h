// Level script parser for Black & White (2001)
// Extracts entity positions from Land*.txt files for world rendering

#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace bw {

struct ScriptEntity {
    float    x, z;         // World position (Y computed from terrain)
    float    angle;        // Y rotation
    float    scale;        // Scale factor
    int      mesh_id;      // Index into AllMeshes.g3d (-1 = unknown)
    std::string type_name; // Original type string for debugging
};

struct LevelScript {
    std::vector<ScriptEntity> entities;
    float camera_x, camera_z;
};

// Parse a level script file. Returns true on success.
bool ParseLevelScript(const std::string& path, LevelScript& out);

// Map an abode type name (e.g., "NORSE_ABODE_A") to a mesh ID
int MapAbodeToMesh(const std::string& tribe, const std::string& type);

// Map a tree type ID to a mesh ID
int MapTreeToMesh(int tree_type);

} // namespace bw
