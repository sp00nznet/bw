// G3D archive loader test — parse AllMeshes.g3d and print stats
#include "g3d_loader.h"
#include <cstdio>

int main(int argc, char* argv[]) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);

    const char* path = (argc >= 2) ? argv[1] : "game_data/AllMeshes.g3d";
    printf("Loading G3D: %s\n", path);

    bw::G3DArchive archive;
    if (!bw::LoadG3D(path, archive)) {
        fprintf(stderr, "FAILED to load G3D: %s\n", path);
        return 1;
    }

    printf("\n=== Summary ===\n");
    printf("Blocks: %zu\n", archive.blocks.size());
    printf("Meshes: %zu\n", archive.meshes.size());

    // Print first 20 meshes with stats
    uint32_t total_v = 0, total_t = 0, valid = 0;
    for (size_t i = 0; i < archive.meshes.size(); ++i) {
        const auto& m = archive.meshes[i];
        uint32_t nv = m.TotalVertices();
        uint32_t nt = m.TotalTriangles();
        total_v += nv;
        total_t += nt;
        if (!m.submeshes.empty()) valid++;
        if (i < 20 && !m.submeshes.empty()) {
            printf("  [%3zu] %u verts, %u tris, %zu submeshes\n",
                   i, nv, nt, m.submeshes.size());
        }
    }
    printf("  ... (%u valid meshes)\n", valid);
    printf("Total: %u vertices, %u triangles\n", total_v, total_t);

    return 0;
}
