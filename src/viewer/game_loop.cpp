// Game loop implementation
// Manages entity lifecycle, hand interaction, and game state
// Now bridges to bw_core for real entity logic.

#include "game_loop.h"
#include "mesh_names.h"
#include "audio.h"
#include "save_state.h"
#include "anm_loader.h"
#include "helptext.h"

#include <unordered_map>

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>

// bw_core integration
#include <black/Terrain.h>
#include <black/EntityFactory.h>
#include <black/Object.h>
#include <black/LHVM.h>
#include <black/LHVMObjects.h>
#include <black/types.h>

namespace bw {

// Library of every animation extracted from AllAnims.anm + Anims/*.anm,
// indexed by source-name (e.g. "M_P_Conduct_Meeting") and by integer id.
struct ANMLibrary {
    std::vector<ANMSingle>                       animations;
    std::unordered_map<std::string, uint32_t>    by_name;       // exact "M_..." key
    std::unordered_map<std::string, uint32_t>    by_base_name;  // without ".max"
};

static const float GRAVITY = -9.8f * 2.0f;  // Scaled gravity
static const float HAND_HOVER_HEIGHT = 30.0f;
static const float PICK_RADIUS = 15.0f;

// Static pointer to current GameState for terrain/hand/click callbacks
static const GameState* s_current_game_state = nullptr;

// LHVM host services — translate the viewer's hand/click into the bw_core
// handle space the VM speaks. Registered on game init so chunk-1's
// GET_HAND_POSITION / GAME_THING_CLICKED / etc. return real values.
// Default mesh lookup for LHVM-spawned entities. The G3D archive's mesh
// order matches g_mesh_names so a name search yields the correct index.
static int FindMeshIdByName(const char* name) {
    for (int i = 0; i < g_mesh_name_count; i++) {
        if (std::strcmp(g_mesh_names[i], name) == 0) return i;
    }
    return -1;
}

static int DefaultMeshForScriptType(int script_type) {
    // SCRIPT_OBJECT_TYPE indices from chlasm/ScriptEnums.h.
    switch (script_type) {
    case  2: /* ABODE */          return FindMeshIdByName("B_NORS_VILLAGECENTRE");
    case  3: /* FEATURE */        return FindMeshIdByName("B_CAMPFIRE");
    case  4: /* VILLAGER */
    case  5: /* VILLAGER_CHILD */ return FindMeshIdByName("B_AMCN_VILLAGECENTRE");
    case  6: /* ANIMAL */         return FindMeshIdByName("A_COW_1");
    case  7: /* REWARD */         return FindMeshIdByName("REWARD_CHEST_EXPLODE");
    case  8: /* MOBILE_STATIC */  return FindMeshIdByName("U_BUCKET");
    case 11: /* FLOCK */          return FindMeshIdByName("A_DOVE_1");
    case 12: /* CREATURE */       return FindMeshIdByName("A_LION_1");
    case 13: /* DEAD_TREE */      return FindMeshIdByName("O_BURNT_TREE");
    case 20: /* MOBILE_OBJECT */  return FindMeshIdByName("U_CART");
    case 21: /* BIRD */           return FindMeshIdByName("A_DOVE_1");
    case 22: /* TREE */           return FindMeshIdByName("T_PINE");
    case 33: /* ROCK */           return FindMeshIdByName("U_BUCKET");   // no rock mesh in table
    case 35: /* FIELD */          return FindMeshIdByName("T_WHEAT");
    case 37: /* HIGHLIGHT */      return FindMeshIdByName("I_TREES");
    case 39: /* SCAFFOLD */       return FindMeshIdByName("B_SCAFFOLD_01");
    default:                      return FindMeshIdByName("T_BUSH");
    }
}

static void EntitySpawnCallback(const lhvm::SpawnInfo* info) {
    if (!info || !s_current_game_state) return;
    auto* g = const_cast<GameState*>(s_current_game_state);

    // Re-snap altitude to terrain so the new entity sits on the ground rather
    // than at whatever Y the script supplied (often 0).
    float ground = g->GetTerrainHeight(info->x, info->z);
    float y = ground > info->y ? ground : info->y;

    GameEntity e = {};
    e.x = info->x;
    e.y = y;
    e.z = info->z;
    e.angle = 0;
    e.scale = 1.0f;
    e.mesh_id = DefaultMeshForScriptType(info->script_type);
    e.type = (info->script_type == 22) ? ENTITY_TREE
           : (info->script_type == 2)  ? ENTITY_ABODE
           : (info->script_type == 4 || info->script_type == 5) ? ENTITY_VILLAGER
           : (info->script_type == 6 || info->script_type == 21) ? ENTITY_ANIMAL
           : ENTITY_FEATURE;
    e.alive = true;
    e.selected = false;
    e.physics_active = false;
    e.name = "lhvm";

    g->entities.push_back(e);
    g->core_entities.push_back(info->obj);
}

static void HandQueryCallback(lhvm::HandInfo* out) {
    *out = {};
    if (!s_current_game_state) return;
    const auto& h = s_current_game_state->hand;
    out->x = h.x;
    out->y = h.y;
    out->z = h.z;
    out->state = h.held_entity >= 0 ? 5  // HOLDING
               : h.hover_entity >= 0 ? 1  // NORMAL over thing
               : 1;
    auto handle_for_index = [](int idx) -> uint32_t {
        if (idx < 0 || !s_current_game_state) return 0;
        if (idx >= static_cast<int>(s_current_game_state->core_entities.size())) return 0;
        return lhvm::HandleFor(s_current_game_state->core_entities[idx]);
    };
    out->hover_object = handle_for_index(h.hover_entity);
    out->held_object  = handle_for_index(h.held_entity);
}

// Terrain height callback for bw_core
static float TerrainHeightCallback(float world_x, float world_z) {
    if (s_current_game_state) {
        return s_current_game_state->GetTerrainHeight(world_x, world_z);
    }
    return 0.0f;
}

float GameState::GetTerrainHeight(float wx, float wz) const {
    if (terrain.vertices.empty()) return 0;
    float best_dist = 1e30f;
    float best_y = 0;
    size_t step = std::max<size_t>(1, terrain.vertices.size() / 20000);
    for (size_t i = 0; i < terrain.vertices.size(); i += step) {
        const auto& v = terrain.vertices[i];
        float dx = v.x - wx, dz = v.z - wz;
        float d = dx*dx + dz*dz;
        if (d < best_dist) { best_dist = d; best_y = v.y; }
    }
    return best_y;
}

bool GameState::Init(const std::string& script_path) {
    game_turn = 0;
    delta_time = 1.0f / 10.0f;   // BW runs simulation at 10 Hz
    paused = false;
    use_bw_core = true;  // Enable bw_core entity creation

    // Derive paths
    std::string dir = script_path.substr(0, script_path.find_last_of("/\\") + 1);
    std::string base = script_path.substr(0, script_path.find_last_of('.'));
    std::string lnd_path = base + ".lnd";
    std::string g3d_path = dir + "AllMeshes.g3d";

    // Load terrain
    printf("Game: Loading terrain...\n"); fflush(stdout);
    if (!LoadLND(lnd_path, terrain)) {
        fprintf(stderr, "Game: Failed to load terrain: %s\n", lnd_path.c_str());
        return false;
    }

    // Register terrain + LHVM host services
    s_current_game_state = this;
    g_terrain_height_func = TerrainHeightCallback;
    lhvm::g_hand_query_func   = HandQueryCallback;
    lhvm::g_entity_spawn_func = EntitySpawnCallback;
    bw::audio::Init(dir);
    bw::audio::RegisterLHVMHooks();
    bw::savestate::RegisterLHVMHook(this);

    // HelpText: load both English DLLs so dialogue subtitles can show
    // real localized text instead of raw string ids. LanguageR holds
    // resource-class strings (short labels); LanguageD holds the longer
    // dialogue/description strings — load both and merge.
    bw::helptext::LoadFromDLL(dir + "LanguageR.dll");
    bw::helptext::LoadFromDLL(dir + "LanguageD.dll");
    printf("Game: Terrain + LHVM host services + audio + save registered for bw_core\n"); fflush(stdout);

    // Load animations: the full AllAnims.anm pack archive into a library
    // indexed by source-name, plus the standalone Anims/anim.anm as a
    // sanity-check test animation that ships with the viewer.
    {
        auto* lib = new bw::ANMLibrary();
        anim_library = lib;

        bw::ANMArchive archive;
        std::string anm_path = dir + "AllAnims.anm";
        if (bw::LoadANM(anm_path, archive)) {
            lib->animations.reserve(archive.packed_animations.size());
            for (size_t i = 0; i < archive.packed_animations.size(); ++i) {
                bw::ANMSingle one;
                char dbg[64];
                snprintf(dbg, sizeof(dbg), "AllAnims[%zu]", i);
                if (!bw::LoadANMSingleBytes(archive.packed_animations[i],
                                            dbg, one)) {
                    continue;
                }
                uint32_t id = static_cast<uint32_t>(lib->animations.size());
                // Normalize: strip trailing ".max" to make script-driven
                // lookups easier.
                std::string base = one.source_name;
                auto dot = base.find_last_of('.');
                if (dot != std::string::npos) base.resize(dot);
                lib->by_name[one.source_name] = id;
                lib->by_base_name[base] = id;
                lib->animations.push_back(std::move(one));
            }
            printf("Game: ANM library loaded — %zu animations available\n",
                   lib->animations.size());
        } else {
            printf("Game: AllAnims.anm not present or unreadable at %s\n",
                   anm_path.c_str());
        }

        // Persist test animation for runtime playback.
        if (!test_anim) test_anim = new bw::ANMSingle();
        std::string anim_path = dir + "Anims/anim.anm";
        if (!bw::LoadANMSingle(anim_path, *test_anim)) {
            printf("Game: Anims/anim.anm not present or unreadable at %s\n",
                   anim_path.c_str());
            delete test_anim;
            test_anim = nullptr;
        }
        fflush(stdout);
    }

    // Load meshes
    printf("Game: Loading meshes...\n"); fflush(stdout);
    if (!LoadG3D(g3d_path, meshes)) {
        fprintf(stderr, "Game: Failed to load meshes: %s\n", g3d_path.c_str());
        return false;
    }

    // Parse script
    printf("Game: Parsing level script...\n"); fflush(stdout);
    if (!ParseLevelScript(script_path, script)) {
        fprintf(stderr, "Game: Failed to parse script: %s\n", script_path.c_str());
        return false;
    }

    // Spawn entities (creates both viewer and bw_core entities)
    SpawnEntitiesFromScript();

    // Initialize LHVM scripting engine
    vm = nullptr;
    scripts_loaded = false;
    if (use_bw_core) {
        // Look for CHL file (compiled challenge script)
        std::string chl_path = dir + "Quests/Challenge.chl";
        FILE* test = fopen(chl_path.c_str(), "rb");
        if (!test) {
            // Try alternate location
            chl_path = dir + "Scripts/Quests/Challenge.chl";
            test = fopen(chl_path.c_str(), "rb");
        }
        if (test) {
            fclose(test);
            vm = static_cast<LHVM*>(calloc(1, sizeof(LHVM)));
            if (vm) {
                // LoadBinary calls InitNativeFunctions internally after the
                // CHL parses successfully — no need to pre-init here.
                if (vm->LoadBinary(chl_path.c_str())) {
                    scripts_loaded = true;
                    lhvm::SetActiveLHVM(vm);
                    printf("Game: Loaded CHL script: %s (%u instructions, %u scripts)\n",
                           chl_path.c_str(), vm->instruction_count, vm->script_count);
                    // Start auto-start scripts
                    for (uint32_t i = 0; i < vm->auto_start_count; i++) {
                        vm->StartScriptByID(vm->auto_start_scripts[i]);
                    }
                    printf("Game: Started %u auto-start scripts\n", vm->auto_start_count);
                } else {
                    printf("Game: Failed to load CHL: %s\n", chl_path.c_str());
                    free(vm);
                    vm = nullptr;
                }
            }
        } else {
            printf("Game: No CHL script found (tried %s)\n", chl_path.c_str());
        }
        fflush(stdout);
    }

    // Init hand
    hand = {};
    hand.held_entity = -1;
    hand.hover_entity = -1;
    hand_mesh_id = 250; // MSH_B_SPELLHAND

    // Init camera at script's camera position
    cam_x = script.camera_x;
    cam_z = script.camera_z;
    cam_y = GetTerrainHeight(cam_x, cam_z) + 50.0f;
    cam_yaw = 30.0f;
    cam_pitch = 30.0f;
    cam_dist = 200.0f;

    printf("Game: Initialized — %zu entities, camera at (%.0f, %.0f)\n",
           entities.size(), cam_x, cam_z);
    fflush(stdout);

    return true;
}

ANMSingle* GameState::LibraryAnimByName(const char* name) const {
    if (!anim_library || !name) return nullptr;
    auto* lib = static_cast<ANMLibrary*>(anim_library);
    auto exact = lib->by_name.find(name);
    if (exact != lib->by_name.end()) {
        return &lib->animations[exact->second];
    }
    auto base = lib->by_base_name.find(name);
    if (base != lib->by_base_name.end()) {
        return &lib->animations[base->second];
    }
    return nullptr;
}

ANMSingle* GameState::LibraryAnimByIndex(uint32_t idx) const {
    if (!anim_library) return nullptr;
    auto* lib = static_cast<ANMLibrary*>(anim_library);
    if (idx >= lib->animations.size()) return nullptr;
    return &lib->animations[idx];
}

uint32_t GameState::LibraryAnimCount() const {
    if (!anim_library) return 0;
    return static_cast<uint32_t>(static_cast<ANMLibrary*>(anim_library)->animations.size());
}

void GameState::SpawnEntitiesFromScript() {
    entities.clear();
    core_entities.clear();
    entities.reserve(script.entities.size());
    core_entities.reserve(script.entities.size());

    int spawned = 0;
    int core_spawned = 0;
    for (const auto& se : script.entities) {
        float y = GetTerrainHeight(se.x, se.z);
        if (y < 2.0f) continue; // Skip water

        GameEntity e;
        e.x = se.x;
        e.y = y;
        e.z = se.z;
        e.angle = se.angle;
        e.scale = se.scale;
        e.mesh_id = se.mesh_id;
        e.name = se.type_name;
        e.alive = true;
        e.selected = false;
        e.vx = e.vy = e.vz = 0;
        e.physics_active = false;

        // Determine type
        EntityCategory core_category = ENTITY_CAT_FEATURE;
        if (se.type_name.find("ABODE") != std::string::npos ||
            se.type_name.find("TOWN") != std::string::npos) {
            e.type = ENTITY_ABODE;
            core_category = ENTITY_CAT_ABODE;
        } else if (se.type_name == "TREE") {
            e.type = ENTITY_TREE;
            core_category = ENTITY_CAT_TREE;
        } else if (se.type_name.find("FORESTER") != std::string::npos ||
                   se.type_name.find("HOUSEWIFE") != std::string::npos ||
                   se.type_name.find("SHEPHERD") != std::string::npos ||
                   se.type_name.find("FISHERMAN") != std::string::npos) {
            e.type = ENTITY_VILLAGER;
            core_category = ENTITY_CAT_VILLAGER;
        } else if (se.type_name == "ANIMAL") {
            e.type = ENTITY_ANIMAL;
        } else if (se.type_name == "MOBILE_STATIC") {
            e.type = ENTITY_MOBILE;
            core_category = ENTITY_CAT_MOBILE;
        } else {
            e.type = ENTITY_FEATURE;
            core_category = ENTITY_CAT_FEATURE;
        }

        entities.push_back(e);

        // Create corresponding bw_core entity
        Object* core_obj = nullptr;
        if (use_bw_core) {
            EntityCreateParams params;
            params.world_x = se.x;
            params.world_z = se.z;
            params.angle = se.angle;
            params.scale = se.scale;
            params.mesh_id = se.mesh_id;
            params.type_enum = 0;
            params.type_name = se.type_name.c_str();

            core_obj = EntityFactory::CreateEntity(core_category, params);
            if (core_obj) core_spawned++;
        }
        core_entities.push_back(core_obj);

        spawned++;
    }

    printf("Game: Spawned %d viewer entities", spawned);
    if (use_bw_core) {
        printf(", %d bw_core entities", core_spawned);
    }
    printf("\n");
    fflush(stdout);
}

void GameState::ProcessTurn() {
    if (paused) return;
    game_turn++;

    // === Phase 0: Tick LHVM scripts ===
    if (scripts_loaded && vm) {
        vm->ProcessTick();
        lhvm::TickSpells();
    }

    // === Phase 1: Run bw_core game logic ===
    if (use_bw_core) {
        // Tick bw_core entities — this runs the real game simulation
        for (size_t i = 0; i < core_entities.size(); i++) {
            Object* obj = core_entities[i];
            if (!obj) continue;
            if (!obj->IsAvailable()) continue;
            obj->Process();
        }
    }

    // === Phase 2: Sync bw_core state back to viewer entities ===
    if (use_bw_core) {
        for (size_t i = 0; i < entities.size() && i < core_entities.size(); i++) {
            Object* obj = core_entities[i];
            if (!obj) continue;

            auto& ve = entities[i];
            if (ve.physics_active || ve.selected) continue; // Don't override physics/hand

            // Sync position from bw_core MapCoords to viewer world coords
            ve.x = static_cast<float>(obj->coords.x) / 65536.0f;
            ve.z = static_cast<float>(obj->coords.z) / 65536.0f;
            ve.y = obj->coords.altitude;

            // Sync rotation and scale
            ve.angle = obj->y_angle;
            ve.scale = obj->scale;

            // Sync alive state
            ve.alive = obj->IsAvailable() && obj->IsAlive();
        }
    }

    // === Phase 3: Viewer-side physics for thrown objects ===
    for (auto& e : entities) {
        if (!e.alive || !e.physics_active) continue;

        e.vy += GRAVITY * delta_time;
        e.x += e.vx * delta_time;
        e.y += e.vy * delta_time;
        e.z += e.vz * delta_time;

        // Ground collision
        float ground = GetTerrainHeight(e.x, e.z);
        bool just_hit_ground = (e.y <= ground);
        if (just_hit_ground) {
            // Speed at impact — drives damage falloff so a slow bounce
            // doesn't shred fragile targets like a hard-thrown rock would.
            float impact_speed = sqrtf(e.vx*e.vx + e.vy*e.vy + e.vz*e.vz);
            e.y = ground;
            e.vx *= 0.5f;
            e.vy = 0;
            e.vz *= 0.5f;

            // Fire bw_core impact on the thrown entity itself + any
            // nearby entity in a small radius. The PhysicsObject* arg is
            // unused by every existing ReactToPhysicsImpact body, so we
            // pass null. The bool param toggles damage application.
            size_t thrown_idx = &e - &entities[0];
            if (use_bw_core && impact_speed > 5.0f) {
                if (thrown_idx < core_entities.size() && core_entities[thrown_idx]) {
                    core_entities[thrown_idx]->ReactToPhysicsImpact(nullptr, true);
                }
                // Splash damage to nearby objects (thrown rock breaks pots, etc.)
                const float blast_r = 6.0f + impact_speed * 0.05f;
                const float blast_r2 = blast_r * blast_r;
                for (size_t j = 0; j < entities.size(); j++) {
                    if (j == thrown_idx) continue;
                    if (j >= core_entities.size() || !core_entities[j]) continue;
                    const auto& other = entities[j];
                    if (!other.alive) continue;
                    float dx = other.x - e.x, dz = other.z - e.z;
                    if (dx*dx + dz*dz <= blast_r2) {
                        core_entities[j]->ReactToPhysicsImpact(nullptr, true);
                    }
                }
            }

            if (fabsf(e.vx) + fabsf(e.vz) < 0.5f) {
                e.physics_active = false;
                e.vx = e.vy = e.vz = 0;

                // Sync landing position back to bw_core
                if (use_bw_core && thrown_idx < core_entities.size() &&
                    core_entities[thrown_idx]) {
                    int32_t map_x = static_cast<int32_t>(e.x * 65536.0f);
                    int32_t map_z = static_cast<int32_t>(e.z * 65536.0f);
                    MapCoords pos(map_x, map_z, e.y);
                    core_entities[thrown_idx]->SetPos(pos);
                }
            }
        }
    }

    // === Phase 4: Update held entity position to follow hand ===
    if (hand.held_entity >= 0 && hand.held_entity < static_cast<int>(entities.size())) {
        auto& e = entities[hand.held_entity];
        e.x = hand.x;
        e.y = hand.y + HAND_HOVER_HEIGHT;
        e.z = hand.z;
    }
}

int GameState::FindEntityAt(float wx, float wz, float radius) {
    int best = -1;
    float best_dist = radius * radius;
    for (int i = 0; i < static_cast<int>(entities.size()); ++i) {
        if (!entities[i].alive) continue;
        float dx = entities[i].x - wx;
        float dz = entities[i].z - wz;
        float d = dx*dx + dz*dz;
        if (d < best_dist) {
            best_dist = d;
            best = i;
        }
    }
    return best;
}

void GameState::PickUpEntity(int index) {
    if (index < 0 || index >= static_cast<int>(entities.size())) return;
    if (hand.held_entity >= 0) return; // Already holding something

    auto& e = entities[index];

    // Check if bw_core entity allows pick up
    if (use_bw_core && index < static_cast<int>(core_entities.size()) && core_entities[index]) {
        if (!core_entities[index]->CanBePickedUp()) return;
    } else {
        // Fallback: can pick up anything except buildings
        if (e.type == ENTITY_ABODE || e.type == ENTITY_FEATURE) return;
    }

    e.selected = true;
    e.physics_active = false;
    hand.held_entity = index;
    printf("Game: Picked up %s (entity %d)\n", e.name.c_str(), index);
}

void GameState::DropEntity() {
    if (hand.held_entity < 0) return;
    auto& e = entities[hand.held_entity];
    e.selected = false;

    // If hand was moving, fling the entity
    float speed = sqrtf(hand.vel_x * hand.vel_x + hand.vel_z * hand.vel_z);
    if (speed > 50.0f) {
        e.physics_active = true;
        e.vx = hand.vel_x * 0.3f;
        e.vy = speed * 0.15f; // Arc upward proportional to speed
        e.vz = hand.vel_z * 0.3f;
        printf("Game: Flung %s (speed=%.0f)\n", e.name.c_str(), speed);
    } else {
        e.y = GetTerrainHeight(e.x, e.z);
    }

    hand.held_entity = -1;
}

void GameState::ThrowEntity(float tvx, float tvy, float tvz) {
    if (hand.held_entity < 0) return;
    auto& e = entities[hand.held_entity];
    e.selected = false;
    e.physics_active = true;
    e.vx = tvx;
    e.vy = tvy;
    e.vz = tvz;
    hand.held_entity = -1;
    printf("Game: Threw %s with velocity (%.1f, %.1f, %.1f)\n",
           e.name.c_str(), tvx, tvy, tvz);
}

void GameState::UpdateHand(int mouse_x, int mouse_y, int screen_w, int screen_h) {
    hand.screen_x = static_cast<float>(mouse_x);
    hand.screen_y = static_cast<float>(mouse_y);

    // Project mouse to world coordinates using simple raycast approximation
    float nx = (2.0f * mouse_x / screen_w - 1.0f);
    float ny = -(2.0f * mouse_y / screen_h - 1.0f); // Screen Y is top-down, GL is bottom-up

    float rad_yaw = cam_yaw * 3.14159265f / 180.0f;
    float rad_pitch = cam_pitch * 3.14159265f / 180.0f;

    // Camera forward direction
    float fw_x = -sinf(rad_yaw) * cosf(rad_pitch);
    float fw_y = -sinf(rad_pitch);
    float fw_z = -cosf(rad_yaw) * cosf(rad_pitch);

    // Camera right and up
    float rt_x = cosf(rad_yaw);
    float rt_z = -sinf(rad_yaw);
    float up_x = -sinf(rad_yaw) * sinf(rad_pitch);
    float up_y = cosf(rad_pitch);
    float up_z = -cosf(rad_yaw) * sinf(rad_pitch);

    // Ray direction
    float fov_scale = tanf(22.5f * 3.14159265f / 180.0f); // half of 45 degree FOV
    float aspect = static_cast<float>(screen_w) / screen_h;
    float ray_x = fw_x + rt_x * nx * fov_scale * aspect + up_x * ny * fov_scale;
    float ray_y = fw_y + up_y * ny * fov_scale;
    float ray_z = fw_z + rt_z * nx * fov_scale * aspect + up_z * ny * fov_scale;

    // Camera eye position
    float eye_x = cam_x + cam_dist * cosf(rad_pitch) * sinf(rad_yaw);
    float eye_y = cam_y + cam_dist * sinf(rad_pitch);
    float eye_z = cam_z + cam_dist * cosf(rad_pitch) * cosf(rad_yaw);

    // Intersect ray with y=terrain_height plane (approximate)
    if (fabsf(ray_y) > 0.001f) {
        float t = (cam_y - eye_y) / ray_y;
        if (t > 0) {
            hand.x = eye_x + ray_x * t;
            hand.z = eye_z + ray_z * t;
            hand.y = GetTerrainHeight(hand.x, hand.z);
            hand.is_over_land = hand.y > 2.0f;
        }
    }

    // Track hand velocity for fling/throw
    hand.vel_x = (hand.x - hand.prev_x) / delta_time;
    hand.vel_z = (hand.z - hand.prev_z) / delta_time;
    hand.prev_x = hand.x;
    hand.prev_z = hand.z;

    // Update hover entity
    hand.hover_entity = FindEntityAt(hand.x, hand.z, PICK_RADIUS);
}

} // namespace bw
