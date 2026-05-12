// L3D mesh file loader for Black & White (2001)
// Format reverse-engineered by the openblack project
// Parses Lionhead's proprietary .L3D mesh files

#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace bw {

// On-disk structures matching the L3D binary format (openblack reference)

#pragma pack(push, 1)

struct L3DPoint {
    float x, y, z;
};

struct L3DPoint2D {
    float x, y;
};

struct L3DBoundingBox {
    uint32_t unknown;
    L3DPoint centre;
    L3DPoint size;
    float    diagonal_length;
};
static_assert(sizeof(L3DBoundingBox) == 0x20, "L3DBoundingBox size mismatch");

struct L3DHeader {
    char          magic[4];                // 0x00: "L3D0"
    uint32_t      flags;                   // 0x04: LH3D_MESH_FLAGS
    uint32_t      size;                    // 0x08: total data size
    uint32_t      submesh_count;           // 0x0C: number of submeshes
    uint32_t      submesh_offsets_offset;   // 0x10: offset to submesh offset table
    L3DBoundingBox bounding_box;           // 0x14: bounding box (0x20 bytes)
    uint32_t      another_offset;          // 0x34
    uint32_t      skin_count;              // 0x38
    uint32_t      skin_offsets_offset;     // 0x3C
    uint32_t      extra_data_count;        // 0x40
    uint32_t      extra_data_offset;       // 0x44
    uint32_t      footprint_data_offset;   // 0x48
};
static_assert(sizeof(L3DHeader) == 0x4C, "L3DHeader size mismatch");

// Material type for each primitive group
struct L3DMaterial {
    uint32_t type;              // 0x00: material/blend type enum
    uint8_t  alpha_threshold;   // 0x04
    uint8_t  cull_mode;         // 0x05
    uint8_t  pad[2];            // 0x06: alignment
    uint32_t skin_id;           // 0x08
    uint32_t color;             // 0x0C: BGRA8 packed color
};
static_assert(sizeof(L3DMaterial) == 0x10, "L3DMaterial size mismatch");

// Submesh header (called "primitive group" in LH3D)
struct L3DSubmeshHeader {
    uint32_t flags;              // 0x00
    uint32_t num_primitives;     // 0x04: number of primitive groups
    uint32_t primitives_offset;  // 0x08: offset to primitive headers
    uint32_t num_bones;          // 0x0C
    uint32_t bones_offset;       // 0x10
};
static_assert(sizeof(L3DSubmeshHeader) == 0x14, "L3DSubmeshHeader size mismatch");

// Primitive group — one material + vertices + triangles
struct L3DPrimitiveHeader {
    L3DMaterial material;        // 0x00 (0x10 bytes)
    uint32_t num_vertices;       // 0x10
    uint32_t vertices_offset;    // 0x14
    uint32_t num_triangles;      // 0x18
    uint32_t triangles_offset;   // 0x1C
    uint32_t num_groups;         // 0x20: vertex group count
    uint32_t groups_offset;      // 0x24
    uint32_t num_blends;         // 0x28
    uint32_t blends_offset;      // 0x2C
};
static_assert(sizeof(L3DPrimitiveHeader) == 0x30, "L3DPrimitiveHeader size mismatch");

struct L3DVertex {
    float px, py, pz;   // Position
    float u, v;          // Texture coords
    float nx, ny, nz;    // Normal
};
static_assert(sizeof(L3DVertex) == 0x20, "L3DVertex size mismatch");

struct L3DTriangle {
    uint16_t i0, i1, i2;
};
static_assert(sizeof(L3DTriangle) == 6, "L3DTriangle size mismatch");

struct L3DBone {
    uint32_t parent;          // 0x00: parent bone index (0xFFFFFFFF = root)
    uint32_t first_child;     // 0x04
    uint32_t right_sibling;   // 0x08
    float    orientation[9];  // 0x0C: 3x3 rotation matrix (row-major)
    float    px, py, pz;      // 0x30: position
};
static_assert(sizeof(L3DBone) == 0x3C, "L3DBone size mismatch");

struct L3DVertexGroup {
    uint16_t vertex_count;
    uint16_t bone_index;
};
static_assert(sizeof(L3DVertexGroup) == 4, "L3DVertexGroup size mismatch");

#pragma pack(pop)

// Parsed mesh data ready for rendering

// 4x4 column-major bone matrix (model space).
struct BoneMatrix {
    float m[16];
};

struct PrimitiveGroup {
    // Bone-local vertices, as stored on disk. Bind pose / animated pose
    // is produced at render time by multiplying each vertex by the matrix
    // of its assigned bone.
    std::vector<L3DVertex>   vertices;
    std::vector<L3DTriangle> triangles;
    // Parallel to `vertices` — bone index for each vertex (UINT16_MAX
    // if this primitive is unskinned and vertices should pass through
    // unchanged).
    std::vector<uint16_t>    bone_per_vertex;
    uint32_t                 skin_id;
    uint32_t                 material_type;
    uint32_t                 color;  // BGRA8
};

struct ParsedSubmesh {
    std::vector<PrimitiveGroup> primitives;
    uint32_t                    flags;
    // Skeleton — kept for runtime skinning. Empty if the submesh is
    // un-skinned (most static props).
    std::vector<L3DBone>        bones;
    std::vector<BoneMatrix>     bind_world;  // bind-pose world matrix per bone
};

struct L3DModel {
    std::vector<ParsedSubmesh> submeshes;
    std::string                filename;
    uint32_t                   flags;

    // Bounding box
    float min_x, min_y, min_z;
    float max_x, max_y, max_z;

    void ComputeBounds();
    float GetExtent() const;
    uint32_t TotalVertices() const;
    uint32_t TotalTriangles() const;
};

// Load an L3D file from disk. Returns true on success.
bool LoadL3D(const std::string& path, L3DModel& out);

// CPU skinning helper. For each vertex in `prim`, applies `pose[bone]` to
// `prim.vertices[i].px/py/pz` and writes the result into `out_pos`. If
// `pose` is empty or the primitive is unskinned the vertex is copied
// through unchanged. `out_pos` is sized to prim.vertices.size() × 3.
void SkinPrimitive(const PrimitiveGroup& prim,
                   const std::vector<BoneMatrix>& pose,
                   std::vector<float>& out_pos,
                   std::vector<float>& out_normal);

} // namespace bw
