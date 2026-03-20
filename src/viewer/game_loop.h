// Game loop infrastructure for Black & White recompilation
// Bridges the recompiled game code with the OpenGL renderer
//
// This provides a minimal game state that can tick entities,
// handle input, and render the world — a stepping stone toward
// the full GGame implementation.

#pragma once

#include <cstdint>
#include <vector>
#include <string>

#include "l3d_loader.h"
#include "g3d_loader.h"
#include "lnd_loader.h"
#include "script_parser.h"

namespace bw {

// Game entity instance — a placed object in the world
struct GameEntity {
    float    x, y, z;          // World position
    float    angle;            // Y rotation (radians)
    float    scale;            // Uniform scale
    int      mesh_id;          // Index into AllMeshes.g3d
    uint32_t type;             // Entity type (abode, tree, etc.)
    bool     alive;            // Active flag
    bool     selected;         // Currently selected by hand
    std::string name;          // Debug name

    // Simple physics
    float    vx, vy, vz;      // Velocity (for thrown objects)
    bool     physics_active;
};

// Entity types
enum EntityType : uint32_t {
    ENTITY_ABODE      = 0,
    ENTITY_TREE       = 1,
    ENTITY_VILLAGER   = 2,
    ENTITY_ANIMAL     = 3,
    ENTITY_FEATURE    = 4,
    ENTITY_MOBILE     = 5,
    ENTITY_HAND       = 6,
};

// The hand — player's cursor and primary interaction tool
struct HandState {
    float    x, y, z;          // World position (projected from mouse)
    float    screen_x, screen_y; // Screen coordinates
    float    prev_x, prev_z;   // Previous frame position (for velocity)
    float    vel_x, vel_z;     // Smoothed hand velocity
    float    height;           // Height above terrain
    int      held_entity;      // Index of held entity (-1 = none)
    bool     is_over_land;     // Mouse is over terrain (not sky)
    int      hover_entity;     // Entity under cursor (-1 = none)
};

// Game state — minimal game loop manager
struct GameState {
    // World data
    Landscape              terrain;
    G3DArchive             meshes;
    LevelScript            script;

    // Live entities
    std::vector<GameEntity> entities;

    // Player hand
    HandState              hand;
    int                    hand_mesh_id;    // Mesh for rendering the hand

    // Game timing
    uint32_t               game_turn;
    float                  delta_time;
    bool                   paused;

    // Camera
    float cam_x, cam_y, cam_z;
    float cam_yaw, cam_pitch, cam_dist;

    // Initialize from level files
    bool Init(const std::string& script_path);

    // Game tick
    void ProcessTurn();
    void ProcessInput(int mouse_x, int mouse_y, bool lmb, bool rmb);
    void UpdateHand(int mouse_x, int mouse_y, int screen_w, int screen_h);

    // Entity management
    int  FindEntityAt(float wx, float wz, float radius);
    void PickUpEntity(int index);
    void DropEntity();
    void ThrowEntity(float vx, float vy, float vz);

    // Terrain queries
    float GetTerrainHeight(float wx, float wz) const;

    // Spawn entities from script data
    void SpawnEntitiesFromScript();
};

} // namespace bw
