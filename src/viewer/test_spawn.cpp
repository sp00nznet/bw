// test_spawn — every entity in a shipped level spawns through EntityFactory
// with its info.dat record attached, headless. Mirrors the viewer's
// GameState::SpawnEntitiesFromScript category choice (game_loop.cpp).
#include <black/EntityFactory.h>
#include <black/InfoDat.h>
#include <black/Object.h>
#include "script_parser.h"

#include <cstdio>
#include <string>

static EntityCategory CategoryFor(const std::string& t) {
    if (t.find("ABODE") != std::string::npos || t.find("TOWN") != std::string::npos) return ENTITY_CAT_ABODE;
    if (t == "TREE") return ENTITY_CAT_TREE;
    if (t.find("FORESTER") != std::string::npos || t.find("HOUSEWIFE") != std::string::npos ||
        t.find("SHEPHERD") != std::string::npos || t.find("FISHERMAN") != std::string::npos)
        return ENTITY_CAT_VILLAGER;
    if (t == "MOBILE_STATIC") return ENTITY_CAT_MOBILE;
    return ENTITY_CAT_FEATURE;
}

int main(int argc, char**) {
    const char* roots[] = {"game_data/", "../game_data/", "../../game_data/", "../../../game_data/"};
    std::string root;
    for (const char* r : roots)
        if (infodat::Load((std::string(r) + "info.dat").c_str())) { root = r; break; }
    bw::LevelScript script;
    if (root.empty() || !bw::ParseLevelScript(root + "Land1.txt", script)) {
        printf("note: game_data not reachable; skipped\n");
        return 0;
    }
    if (argc > 1) infodat::Unload();  // any argument: spawn without balance data, for comparison
    int spawned = 0, with_info = 0;
    for (const auto& se : script.entities) {
        EntityCreateParams p;
        p.world_x = se.x; p.world_z = se.z; p.angle = se.angle; p.scale = se.scale;
        p.mesh_id = se.mesh_id;
        p.type_enum = static_cast<uint32_t>(se.info_index);
        p.type_name = se.info_index >= 0 ? "" : se.type_name.c_str();
        printf("spawn %-24s ", se.type_name.c_str()); fflush(stdout);
        Object* o = EntityFactory::CreateEntity(CategoryFor(se.type_name), p);
        printf("%s\n", o ? (o->info ? "info" : "no info") : "FAILED");
        spawned += o != nullptr;
        with_info += o && o->info;
    }
    printf("\n%d/%zu spawned, %d with an info record\n", spawned, script.entities.size(), with_info);
    return spawned == int(script.entities.size()) ? 0 : 1;
}
