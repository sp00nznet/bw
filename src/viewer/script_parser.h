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
    int      info_index = -1; // record in its info.dat table, when the script gives a number
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

// Mesh for an object the native level loader made (level::Spawned), or -1 for
// kinds the viewer has no mesh table for yet. *scale_mul is the draw-scale
// correction the viewer applies to that kind (villagers draw at 0.4).
int MeshForSpawn(const std::string& command, const std::string& type_name, int type_index,
                 float* scale_mul);

} // namespace bw
