// Game loop implementation
// Manages entity lifecycle, hand interaction, and game state

#include "game_loop.h"

#include <algorithm>
#include <cmath>
#include <cstdio>

namespace bw {

static const float GRAVITY = -9.8f * 2.0f;  // Scaled gravity
static const float HAND_HOVER_HEIGHT = 30.0f;
static const float PICK_RADIUS = 15.0f;

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
    delta_time = 1.0f / 30.0f;
    paused = false;

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

    // Spawn entities
    SpawnEntitiesFromScript();

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

void GameState::SpawnEntitiesFromScript() {
    entities.clear();
    entities.reserve(script.entities.size());

    int spawned = 0;
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
        if (se.type_name.find("ABODE") != std::string::npos ||
            se.type_name.find("TOWN") != std::string::npos) {
            e.type = ENTITY_ABODE;
        } else if (se.type_name == "TREE") {
            e.type = ENTITY_TREE;
        } else if (se.type_name.find("FORESTER") != std::string::npos ||
                   se.type_name.find("HOUSEWIFE") != std::string::npos ||
                   se.type_name.find("SHEPHERD") != std::string::npos ||
                   se.type_name.find("FISHERMAN") != std::string::npos) {
            e.type = ENTITY_VILLAGER;
        } else if (se.type_name == "ANIMAL") {
            e.type = ENTITY_ANIMAL;
        } else if (se.type_name == "MOBILE_STATIC") {
            e.type = ENTITY_MOBILE;
        } else {
            e.type = ENTITY_FEATURE;
        }

        entities.push_back(e);
        spawned++;
    }

    printf("Game: Spawned %d entities\n", spawned);
}

void GameState::ProcessTurn() {
    if (paused) return;
    game_turn++;

    // Simple physics for thrown objects
    for (auto& e : entities) {
        if (!e.alive || !e.physics_active) continue;

        e.vy += GRAVITY * delta_time;
        e.x += e.vx * delta_time;
        e.y += e.vy * delta_time;
        e.z += e.vz * delta_time;

        // Ground collision
        float ground = GetTerrainHeight(e.x, e.z);
        if (e.y <= ground) {
            e.y = ground;
            e.vx *= 0.5f;
            e.vy = 0;
            e.vz *= 0.5f;
            if (fabsf(e.vx) + fabsf(e.vz) < 0.5f) {
                e.physics_active = false;
                e.vx = e.vy = e.vz = 0;
            }
        }
    }

    // Update held entity position to follow hand
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
    // Can pick up anything except buildings
    if (e.type == ENTITY_ABODE || e.type == ENTITY_FEATURE) return;

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
