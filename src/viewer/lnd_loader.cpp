// LND landscape file loader implementation
// Parses Black & White .lnd terrain files

#include "lnd_loader.h"

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <limits>

namespace bw {

static const float HEIGHT_SCALE = 0.67f;
static const float CELL_SIZE = 10.0f; // World units between cells

float Landscape::GetExtent() const {
    float dx = max_x - min_x;
    float dy = max_y - min_y;
    float dz = max_z - min_z;
    return std::max({dx, dy, dz, 1.0f});
}

void Landscape::BuildMesh() {
    vertices.clear();
    indices.clear();

    if (blocks.empty()) return;

    // First pass: count total vertices and indices
    uint32_t total_verts = block_count * 17 * 17;
    uint32_t total_tris = block_count * 16 * 16 * 2;
    vertices.reserve(total_verts);
    indices.reserve(total_tris * 3);

    min_x = min_y = min_z =  std::numeric_limits<float>::max();
    max_x = max_y = max_z = -std::numeric_limits<float>::max();

    // Build grid position lookup: block index → (grid_col, grid_row)
    // Block indices in the grid are 1-based (0 = ocean/empty)
    // blocks[] array is 0-based: blocks[0] = file block with index 1
    int block_grid_col[256] = {};
    int block_grid_row[256] = {};
    for (int row = 0; row < 32; ++row) {
        for (int col = 0; col < 32; ++col) {
            uint8_t idx = index_grid[row][col];
            if (idx > 0 && idx < 256) {
                block_grid_col[idx] = col;
                block_grid_row[idx] = row;
            }
        }
    }

    uint32_t vert_offset = 0;
    for (uint32_t bi = 0; bi < block_count && bi < blocks.size(); ++bi) {
        const auto& blk = blocks[bi];

        // blocks[bi] corresponds to grid index (bi+1) since block 0 is not stored
        uint32_t grid_idx = bi + 1;

        // Block world position from grid coordinates
        // Each block is 16 cells wide, each cell is CELL_SIZE apart
        float bx = block_grid_col[grid_idx] * 16.0f * CELL_SIZE;
        float bz = block_grid_row[grid_idx] * 16.0f * CELL_SIZE;

        // Generate vertices for this block's 17x17 grid
        for (int row = 0; row < 17; ++row) {
            for (int col = 0; col < 17; ++col) {
                const auto& cell = blk.cells[row * 17 + col];

                TerrainVertex v;
                v.x = bx + col * CELL_SIZE;
                v.y = cell.altitude * HEIGHT_SCALE;
                v.z = bz + row * CELL_SIZE;

                // Vertex color from cell (normalize 0-255 to 0-1)
                v.r = cell.r / 255.0f;
                v.g = cell.g / 255.0f;
                v.b = cell.b / 255.0f;

                // Normal placeholder (computed below)
                v.nx = 0; v.ny = 1; v.nz = 0;

                min_x = std::min(min_x, v.x);
                min_y = std::min(min_y, v.y);
                min_z = std::min(min_z, v.z);
                max_x = std::max(max_x, v.x);
                max_y = std::max(max_y, v.y);
                max_z = std::max(max_z, v.z);

                vertices.push_back(v);
            }
        }

        // Generate triangle indices for this block (two triangles per cell quad)
        for (int row = 0; row < 16; ++row) {
            for (int col = 0; col < 16; ++col) {
                uint32_t tl = vert_offset + row * 17 + col;
                uint32_t tr = tl + 1;
                uint32_t bl = tl + 17;
                uint32_t br = bl + 1;

                // Check cell split direction from flags
                const auto& cell = blk.cells[row * 17 + col];
                bool split_ne = (cell.flags & 0x80) != 0; // bit for split direction

                if (split_ne) {
                    // NE-SW split: tl-br diagonal
                    indices.push_back(tl); indices.push_back(bl); indices.push_back(br);
                    indices.push_back(tl); indices.push_back(br); indices.push_back(tr);
                } else {
                    // NW-SE split: tr-bl diagonal
                    indices.push_back(tl); indices.push_back(bl); indices.push_back(tr);
                    indices.push_back(tr); indices.push_back(bl); indices.push_back(br);
                }
            }
        }

        vert_offset += 17 * 17;
    }

    // Compute normals from adjacent vertices
    for (size_t i = 0; i < indices.size(); i += 3) {
        auto& v0 = vertices[indices[i]];
        auto& v1 = vertices[indices[i+1]];
        auto& v2 = vertices[indices[i+2]];

        float ax = v1.x - v0.x, ay = v1.y - v0.y, az = v1.z - v0.z;
        float bx = v2.x - v0.x, by = v2.y - v0.y, bz = v2.z - v0.z;

        float nx = ay * bz - az * by;
        float ny = az * bx - ax * bz;
        float nz = ax * by - ay * bx;

        v0.nx += nx; v0.ny += ny; v0.nz += nz;
        v1.nx += nx; v1.ny += ny; v1.nz += nz;
        v2.nx += nx; v2.ny += ny; v2.nz += nz;
    }

    // Normalize
    for (auto& v : vertices) {
        float len = sqrtf(v.nx*v.nx + v.ny*v.ny + v.nz*v.nz);
        if (len > 0.0001f) {
            v.nx /= len; v.ny /= len; v.nz /= len;
        } else {
            v.nx = 0; v.ny = 1; v.nz = 0;
        }
    }

    printf("LND: Built mesh — %zu verts, %zu tris\n",
           vertices.size(), indices.size() / 3);
}

bool LoadLND(const std::string& path, Landscape& out) {
    FILE* f = fopen(path.c_str(), "rb");
    if (!f) {
        fprintf(stderr, "LND: Failed to open: %s\n", path.c_str());
        return false;
    }

    fseek(f, 0, SEEK_END);
    long file_size = ftell(f);
    fseek(f, 0, SEEK_SET);

    // Read header
    LNDHeader hdr;
    if (fread(&hdr, sizeof(hdr), 1, f) != 1) {
        fprintf(stderr, "LND: Failed to read header\n");
        fclose(f);
        return false;
    }

    printf("LND: %s — blocks=%u, materials=%u, countries=%u, lowres_tex=%u\n",
           path.c_str(), hdr.block_count, hdr.material_count,
           hdr.country_count, hdr.lowres_texture_count);
    fflush(stdout);

    // Find land blocks by scanning for consecutive valid indices (1, 2, 3, ...)
    // The lowres texture section varies by game version, so we scan instead of computing
    {
        std::vector<uint8_t> scan_buf(file_size);
        fseek(f, 0, SEEK_SET);
        fread(scan_buf.data(), 1, file_size, f);

        long block_start = -1;
        uint32_t bs = hdr.block_size;
        for (size_t start = sizeof(LNDHeader); start + bs * 5 < scan_buf.size(); ++start) {
            bool valid = true;
            for (int i = 0; i < 5; ++i) {
                size_t idx_off = start + i * bs + 0x908;
                if (idx_off + 4 > scan_buf.size()) { valid = false; break; }
                uint32_t idx = *reinterpret_cast<const uint32_t*>(scan_buf.data() + idx_off);
                if (idx != static_cast<uint32_t>(i + 1)) { valid = false; break; }
            }
            if (valid) {
                block_start = static_cast<long>(start);
                break;
            }
        }

        if (block_start < 0) {
            fprintf(stderr, "LND: Could not find land blocks\n");
            fclose(f);
            return false;
        }

        fseek(f, block_start, SEEK_SET);
        printf("LND: Found blocks at offset 0x%lX\n", block_start);
        fflush(stdout);
    }

    // Read land blocks — block 0 is NOT stored in the file (ocean/null)
    uint32_t stored_blocks = hdr.block_count - 1;
    out.block_count = stored_blocks;
    out.material_count = hdr.material_count;
    out.country_count = hdr.country_count;

    // Copy index grid (32x32, maps grid position to block index)
    memcpy(out.index_grid, hdr.index_block, 1024);
    out.blocks.resize(stored_blocks);

    size_t blocks_read = fread(out.blocks.data(),
                                sizeof(LNDBlock), stored_blocks, f);
    fclose(f);

    if (blocks_read != stored_blocks) {
        fprintf(stderr, "LND: Only read %zu / %u blocks\n",
                blocks_read, stored_blocks);
        out.block_count = static_cast<uint32_t>(blocks_read);
        out.blocks.resize(blocks_read);
    }

    printf("LND: Read %u blocks, building mesh...\n", out.block_count);
    fflush(stdout);

    out.BuildMesh();

    printf("LND: Bounds [%.0f,%.0f,%.0f]-[%.0f,%.0f,%.0f]\n",
           out.min_x, out.min_y, out.min_z,
           out.max_x, out.max_y, out.max_z);
    fflush(stdout);

    return !out.vertices.empty();
}

} // namespace bw
