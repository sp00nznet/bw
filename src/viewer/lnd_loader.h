// LND landscape file loader for Black & White (2001)
// Format documented by the openblack project
// Parses Lionhead's .lnd terrain heightmap files

#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace bw {

#pragma pack(push, 1)

struct LNDHeader {
    uint32_t block_count;          // 0x000
    uint8_t  index_block[1024];    // 0x004
    uint32_t material_count;       // 0x404
    uint32_t country_count;        // 0x408
    uint32_t block_size;           // 0x40C
    uint32_t material_size;        // 0x410
    uint32_t country_size;         // 0x414
    uint32_t lowres_texture_count; // 0x418
};
static_assert(sizeof(LNDHeader) == 0x41C, "LNDHeader size mismatch");

struct LNDCell {
    uint8_t  r, g, b;      // Vertex color
    uint8_t  luminance;     // Light intensity
    uint8_t  altitude;      // Height (0-255, * 0.67 for world units)
    uint8_t  save_color;
    uint16_t flags;         // Country ID, split, properties, sound
};
static_assert(sizeof(LNDCell) == 8, "LNDCell size mismatch");

struct LNDBlock {
    LNDCell  cells[17 * 17]; // 289 cells = 2312 bytes
    uint32_t index;          // 0x908
    float    map_x;          // 0x90C — world X position
    float    map_y;          // 0x910 — world Z position (Y in map space)
    uint32_t block_x;        // 0x914
    uint32_t block_y;        // 0x918
    uint32_t clipped;        // 0x91C (runtime)
    uint32_t frame_vis;      // 0x920 (runtime)
    uint32_t highest_alt;    // 0x924 (runtime)
    uint32_t use_small_bump; // 0x928 (runtime)
    uint32_t force_lowres;   // 0x92C (runtime)
    uint32_t mesh_lod;       // 0x930 (runtime)
    uint32_t mesh_blending;  // 0x934 (runtime)
    uint32_t tex_blend;      // 0x938 (runtime)
    uint32_t mesh_lod_type;  // 0x93C (runtime)
    uint32_t fog;            // 0x940 (runtime)
    uint32_t tex_pointer;    // 0x944 (runtime)
    uint32_t mat_pointer;    // 0x948 (runtime)
    uint32_t draw_something; // 0x94C (runtime)
    uint32_t spec_mat_before;// 0x950 (runtime)
    uint32_t spec_mat_after; // 0x954 (runtime)
    float    uv_before[12];  // 0x958 — UV transform (3x4)
    float    uv_after[12];   // 0x988 — UV transform (3x4)
    uint32_t next_sort;      // 0x9B8 (runtime)
    float    val_sorting;    // 0x9BC
    float    lowres_tex;     // 0x9C0
    float    fu_lrs;         // 0x9C4
    float    fv_lrs;         // 0x9C8
    float    iu_lrs;         // 0x9CC
    float    iv_lrs;         // 0x9D0
    uint32_t small_tex_upd;  // 0x9D4
};
static_assert(sizeof(LNDBlock) == 0x9D8, "LNDBlock size mismatch");

#pragma pack(pop)

// Parsed terrain vertex for rendering
struct TerrainVertex {
    float x, y, z;    // Position (y = altitude)
    float r, g, b;    // Vertex color
    float nx, ny, nz; // Normal
};

// Parsed landscape
struct Landscape {
    std::vector<LNDBlock>       blocks;
    uint32_t                    block_count;
    uint32_t                    material_count;
    uint32_t                    country_count;

    // Rendered terrain mesh
    std::vector<TerrainVertex>  vertices;
    std::vector<uint32_t>       indices;

    // Bounds
    float min_x, min_y, min_z;
    float max_x, max_y, max_z;

    float GetExtent() const;
    void BuildMesh();  // Generate vertices/indices from blocks
};

// Load a .lnd file. Returns true on success.
bool LoadLND(const std::string& path, Landscape& out);

} // namespace bw
