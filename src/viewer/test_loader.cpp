// Quick test for L3D loader — no window, just parse and print stats
#include "l3d_loader.h"
#include <cstdio>

int main(int argc, char* argv[]) {
    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    if (argc < 2) {
        fprintf(stderr, "Usage: test_loader <l3d_file>\n");
        return 1;
    }
    printf("Loading: %s\n", argv[1]);
    fflush(stdout);

    bw::L3DModel model;
    if (!bw::LoadL3D(argv[1], model)) {
        fprintf(stderr, "FAILED to load: %s\n", argv[1]);
        return 1;
    }

    printf("\nSummary: %zu submeshes, %u total verts, %u total tris\n",
           model.submeshes.size(), model.TotalVertices(), model.TotalTriangles());
    printf("Bounds: [%.3f, %.3f, %.3f] - [%.3f, %.3f, %.3f]\n",
           model.min_x, model.min_y, model.min_z,
           model.max_x, model.max_y, model.max_z);
    printf("Extent: %.3f\n", model.GetExtent());

    return 0;
}
