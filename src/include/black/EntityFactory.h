#pragma once
// EntityFactory — creates bw_core entity instances from level data
// This bridges the gap between the level script parser and the real
// game entity hierarchy.

#include "types.h"
#include <cstdint>

// Forward declarations
struct Object;
struct GameThing;

// Entity creation parameters (matches what the script parser provides)
struct EntityCreateParams {
    float    world_x;       // World X position
    float    world_z;       // World Z position
    float    angle;         // Y rotation in radians
    float    scale;         // Uniform scale factor
    int      mesh_id;       // Mesh index into AllMeshes.g3d
    uint32_t type_enum;     // Entity subtype enum value
    const char* type_name;  // Type string for debugging ("TREE", "NORSE_ABODE_A", etc.)
};

// High-level entity type categories
enum EntityCategory : uint32_t {
    ENTITY_CAT_TREE       = 0,
    ENTITY_CAT_ABODE      = 1,
    ENTITY_CAT_VILLAGER   = 2,
    ENTITY_CAT_ANIMAL     = 3,
    ENTITY_CAT_FEATURE    = 4,
    ENTITY_CAT_MOBILE     = 5,
    ENTITY_CAT_BONFIRE    = 6,
    ENTITY_CAT_ROCK       = 7,
    ENTITY_CAT_CREATURE   = 8,
};

namespace EntityFactory {

// Create a game entity from level data. Returns the created Object, or nullptr on failure.
// The entity is allocated, initialized with position/angle/scale, and inserted into the map.
Object* CreateEntity(EntityCategory category, const EntityCreateParams& params);

// Create a tree at the given position
Object* CreateTree(const EntityCreateParams& params);

// Create an abode (building) at the given position
Object* CreateAbode(const EntityCreateParams& params);

// Create a villager at the given position
Object* CreateVillager(const EntityCreateParams& params);

// Create a mobile static (rock, mushroom, etc.)
Object* CreateMobileStatic(const EntityCreateParams& params);

// Create a creature (player's avatar)
Object* CreateCreature(const EntityCreateParams& params);

} // namespace EntityFactory
