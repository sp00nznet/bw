// Level script parser implementation
// Parses CREATE_ABODE, CREATE_NEW_TREE, etc. from Land*.txt files

#include "script_parser.h"

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>

namespace bw {

// Mesh IDs from AllMeshes.h (MESH_LIST enum)
// Buildings by tribe
static const std::map<std::string, int> g_abode_meshes = {
    // Norse
    {"NORSE_ABODE_A", 204},  // MSH_B_NORS_1
    {"NORSE_ABODE_B", 205},  // MSH_B_NORS_2
    {"NORSE_ABODE_C", 207},  // MSH_B_NORS_3
    {"NORSE_ABODE_D", 209},  // MSH_B_NORS_4
    {"NORSE_ABODE_E", 210},  // MSH_B_NORS_5
    {"NORSE_ABODE_F", 210},  // MSH_B_NORS_5 (reuse)
    {"NORSE_ABODE_CRECHE", 211},
    {"NORSE_ABODE_GRAVEYARD", 213},
    {"NORSE_ABODE_STORAGE_PIT", 215},  // MSH_B_NORS_TEMPLE as storage?
    {"NORSE_ABODE_TOWN_CENTRE", 179},  // MSH_B_NORS_VILLAGECENTRE
    {"NORSE_ABODE_WONDER", 216},  // MSH_B_NORS_WONDER
    {"NORSE_ABODE_WORKSHOP", 217},
    // Celtic
    {"CELTIC_ABODE_A", 74},  // MSH_B_CELT_1
    {"CELTIC_ABODE_B", 75},
    {"CELTIC_ABODE_C", 76},
    {"CELTIC_ABODE_D", 77},
    {"CELTIC_ABODE_E", 78},
    {"CELTIC_ABODE_CRECHE", 80},
    {"CELTIC_ABODE_GRAVEYARD", 83},
    {"CELTIC_ABODE_TOWN_CENTRE", 157},
    {"CELTIC_ABODE_WONDER", 91},
    {"CELTIC_ABODE_WORKSHOP", 92},
    // Aztec
    {"AZTEC_ABODE_A", 61},
    {"AZTEC_ABODE_B", 62},
    {"AZTEC_ABODE_C", 63},
    {"AZTEC_ABODE_D", 64},
    {"AZTEC_ABODE_CRECHE", 66},
    {"AZTEC_ABODE_GRAVEYARD", 67},
    {"AZTEC_ABODE_STORAGE_PIT", 70},
    {"AZTEC_ABODE_TOWN_CENTRE", 156},
    {"AZTEC_ABODE_WONDER", 72},
    {"AZTEC_ABODE_WORKSHOP", 73},
    // Japanese
    {"JAPANESE_ABODE_A", 131},
    {"JAPANESE_ABODE_B", 132},
    {"JAPANESE_ABODE_C", 133},
    {"JAPANESE_ABODE_D", 134},
    {"JAPANESE_ABODE_E", 135},
    {"JAPANESE_ABODE_CRECHE", 137},
    {"JAPANESE_ABODE_GRAVEYARD", 138},
    {"JAPANESE_ABODE_TOWN_CENTRE", 158},
    {"JAPANESE_ABODE_WONDER", 143},
    {"JAPANESE_ABODE_WORKSHOP", 144},
};

// Tree types (CREATE_NEW_TREE third parameter) → mesh ID
// Based on TREE_INFO enum order
static const int g_tree_meshes[] = {
    571,  // 0: MSH_T_BEECH
    572,  // 1: MSH_T_BIRCH
    573,  // 2: MSH_T_BUSH
    576,  // 3: MSH_T_CEDAR
    577,  // 4: MSH_T_CONIFER
    569,  // 5: MSH_T_COPSE
    579,  // 6: MSH_T_CYPRESS
    581,  // 7: MSH_T_HEDGE
    583,  // 8: MSH_T_OAK
    585,  // 9: MSH_T_OLIVE
    586,  // 10: MSH_T_PALM
    588,  // 11: MSH_T_PALM_B
    589,  // 12: MSH_T_PINE
    591,  // 13: MSH_T_RUBBER
    595,  // 14: MSH_T_WILLOW
};
static const int g_tree_mesh_count = sizeof(g_tree_meshes) / sizeof(g_tree_meshes[0]);

int MapAbodeToMesh(const std::string& /*tribe*/, const std::string& type) {
    auto it = g_abode_meshes.find(type);
    if (it != g_abode_meshes.end()) return it->second;
    return -1;
}

int MapTreeToMesh(int tree_type) {
    if (tree_type >= 0 && tree_type < g_tree_mesh_count)
        return g_tree_meshes[tree_type];
    return g_tree_meshes[0]; // fallback to beech
}

// Parse "x,z" coordinate string
static bool ParseCoord(const char* s, float& x, float& z) {
    return sscanf(s, "%f,%f", &x, &z) == 2;
}

// Find next quoted string in line starting at pos, returns content
static bool NextQuoted(const char* line, int& pos, char* out, int out_size) {
    const char* q1 = strchr(line + pos, '"');
    if (!q1) return false;
    const char* q2 = strchr(q1 + 1, '"');
    if (!q2) return false;
    int len = static_cast<int>(q2 - q1 - 1);
    if (len >= out_size) len = out_size - 1;
    memcpy(out, q1 + 1, len);
    out[len] = '\0';
    pos = static_cast<int>(q2 - line + 1);
    return true;
}

bool ParseLevelScript(const std::string& path, LevelScript& out) {
    FILE* f = fopen(path.c_str(), "r");
    if (!f) {
        fprintf(stderr, "Script: Failed to open: %s\n", path.c_str());
        return false;
    }

    out.entities.clear();
    out.camera_x = out.camera_z = 0;

    char line[1024];
    while (fgets(line, sizeof(line), f)) {
        // START_CAMERA_POS("x,z")
        if (strstr(line, "START_CAMERA_POS")) {
            int pos = 0;
            char coord[64];
            if (NextQuoted(line, pos, coord, sizeof(coord))) {
                ParseCoord(coord, out.camera_x, out.camera_z);
            }
        }
        // CREATE_ABODE(town, "x,z", "TYPE", ...)
        else if (strstr(line, "CREATE_ABODE") || strstr(line, "CREATE_PLANNED_ABODE")) {
            int pos = 0;
            char coord[64], type[128];
            if (NextQuoted(line, pos, coord, sizeof(coord)) &&
                NextQuoted(line, pos, type, sizeof(type))) {
                ScriptEntity e;
                if (ParseCoord(coord, e.x, e.z)) {
                    e.type_name = type;
                    e.angle = 0;
                    e.scale = 1.0f;
                    e.mesh_id = MapAbodeToMesh("", type);
                    out.entities.push_back(e);
                }
            }
        }
        // CREATE_NEW_TREE(player, "x,z", type, ?, angle, scale1, scale2)
        else if (strstr(line, "CREATE_NEW_TREE")) {
            int pos = 0;
            char coord[64];
            if (NextQuoted(line, pos, coord, sizeof(coord))) {
                ScriptEntity e;
                if (ParseCoord(coord, e.x, e.z)) {
                    // Parse remaining params: ..., type, ?, angle, scale, scale)
                    const char* after_coord = strchr(line + pos, ',');
                    int tree_type = 0;
                    float angle = 0, scale = 1.0f;
                    if (after_coord) {
                        sscanf(after_coord, ", %d, %*d, %f, %f", &tree_type, &angle, &scale);
                    }
                    e.type_name = "TREE";
                    e.angle = angle;
                    e.scale = scale;
                    e.mesh_id = MapTreeToMesh(tree_type);
                    out.entities.push_back(e);
                }
            }
        }
        // CREATE_TOWN_CENTRE(town, "x,z", ...)
        else if (strstr(line, "CREATE_TOWN_CENTRE")) {
            int pos = 0;
            char coord[64];
            // skip town id, get first quoted = coord
            if (NextQuoted(line, pos, coord, sizeof(coord))) {
                ScriptEntity e;
                if (ParseCoord(coord, e.x, e.z)) {
                    e.type_name = "TOWN_CENTRE";
                    e.angle = 0;
                    e.scale = 1.0f;
                    e.mesh_id = 179; // MSH_B_NORS_VILLAGECENTRE
                    out.entities.push_back(e);
                }
            }
        }
    }

    fclose(f);
    printf("Script: Parsed %zu entities from %s\n", out.entities.size(), path.c_str());
    fflush(stdout);

    int mapped = 0;
    for (const auto& e : out.entities)
        if (e.mesh_id >= 0) mapped++;
    printf("Script: %d entities mapped to meshes, %zu unmapped\n",
           mapped, out.entities.size() - mapped);

    return !out.entities.empty();
}

} // namespace bw
