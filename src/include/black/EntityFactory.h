#pragma once
// EntityFactory — creates bw_core entity instances from level data
// This bridges the gap between the level script parser and the real
// game entity hierarchy.

#include "types.h"
#include <cstdint>

// Forward declarations
struct Object;
struct GameThing;

// type_enum when the caller has no info record to name.
constexpr uint32_t kNoInfo = 0xFFFFFFFFu;

// Entity creation parameters (matches what the script parser provides)
struct EntityCreateParams {
    float    world_x;       // World X position
    float    world_z;       // World Z position
    float    angle;         // Y rotation in radians
    float    scale;         // Uniform scale factor
    int      mesh_id;       // Mesh index into AllMeshes.g3d
    uint32_t type_enum = kNoInfo; // Info record index (the CHL subtype / *_INFO enum), or kNoInfo
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
    ENTITY_CAT_MOBILE_OBJECT = 9,
    ENTITY_CAT_FIELD      = 10,  // a town field (Field abode, DETAIL_FIELD_TYPE_INFO)
    ENTITY_CAT_FISH_FARM  = 11,
    ENTITY_CAT_BIG_FOREST = 12,  // BigForest + its Forest container (sub_431AA0)
    ENTITY_CAT_DEAD_TREE  = 13,  // DeadTree, DETAIL_TREE_INFO (sub_4EE200)
    ENTITY_CAT_STREET_LANTERN = 14,  // GStreetLantern, DETAIL_MOBILE_STATIC_INFO (sub_6CA4E0)
    ENTITY_CAT_ANIMATED_STATIC = 15,  // AnimatedStatic, DETAIL_ANIMATED_STATIC_INFO (sub_41CB70)
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

Object* CreateAnimal(const EntityCreateParams& params);
Object* CreateMobileObject(const EntityCreateParams& params);
Object* CreateField(const EntityCreateParams& params);
Object* CreateFishFarm(const EntityCreateParams& params);
Object* CreateBigForest(const EntityCreateParams& params);
Object* CreateBonfire(const EntityCreateParams& params);
Object* CreateDeadTree(const EntityCreateParams& params);
Object* CreateStreetLantern(const EntityCreateParams& params);
Object* CreateAnimatedStatic(const EntityCreateParams& params);

// Create a creature (player's avatar)
Object* CreateCreature(const EntityCreateParams& params);

} // namespace EntityFactory
