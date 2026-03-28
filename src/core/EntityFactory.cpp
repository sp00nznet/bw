// EntityFactory — creates bw_core entity instances from level data
// Bridges the level script parser with the real game entity hierarchy.

#include <black/EntityFactory.h>
#include <black/Object.h>
#include <black/Tree.h>
#include <black/Abode.h>
#include <black/Villager.h>
#include <black/Rock.h>
#include <black/Bonfire.h>
#include <black/MobileStatic.h>
#include <black/Feature.h>
#include <black/Animal.h>
#include <black/Terrain.h>
#include <black/Map.h>
#include <cstdlib>
#include <cstring>

extern GMap* g_map;

// Helper: set common Object fields from create params
static void InitObjectFromParams(Object* obj, const EntityCreateParams& params) {
    // Convert world coordinates to MapCoords (world * 65536 for fixed-point)
    int32_t map_x = static_cast<int32_t>(params.world_x * 65536.0f);
    int32_t map_z = static_cast<int32_t>(params.world_z * 65536.0f);
    float altitude = GetTerrainHeightAt(params.world_x, params.world_z);

    MapCoords pos(map_x, map_z, altitude);
    obj->SetPos(pos);
    obj->obj_coords = pos;
    obj->y_angle = params.angle;
    obj->scale = params.scale > 0.0f ? params.scale : 1.0f;
    obj->life = 1.0f;
}

namespace EntityFactory {

Object* CreateEntity(EntityCategory category, const EntityCreateParams& params) {
    switch (category) {
    case ENTITY_CAT_TREE:     return CreateTree(params);
    case ENTITY_CAT_ABODE:    return CreateAbode(params);
    case ENTITY_CAT_VILLAGER: return CreateVillager(params);
    case ENTITY_CAT_MOBILE:
    case ENTITY_CAT_ROCK:     return CreateMobileStatic(params);
    default: break;
    }

    // Generic feature fallback — allocate a Feature
    Feature* feat = static_cast<Feature*>(calloc(1, sizeof(Feature)));
    if (!feat) return nullptr;
    InitObjectFromParams(feat, params);
    return feat;
}

Object* CreateTree(const EntityCreateParams& params) {
    Tree* tree = static_cast<Tree*>(calloc(1, sizeof(Tree)));
    if (!tree) return nullptr;
    InitObjectFromParams(tree, params);

    // Insert into map
    tree->InsertMapObject();

    return tree;
}

Object* CreateAbode(const EntityCreateParams& params) {
    Abode* abode = static_cast<Abode*>(calloc(1, sizeof(Abode)));
    if (!abode) return nullptr;
    InitObjectFromParams(abode, params);

    // Start fully built
    abode->percent_built = 1.0f;
    abode->field_0x58 = 8;  // "fully built" flag

    // Insert into map
    abode->InsertMapObject();

    return abode;
}

Object* CreateVillager(const EntityCreateParams& params) {
    Villager* villager = static_cast<Villager*>(calloc(1, sizeof(Villager)));
    if (!villager) return nullptr;
    InitObjectFromParams(villager, params);

    // Initialize villager state
    villager->food = 1.0f;
    villager->action.top_state = 0;  // INVALID — will be set by AI
    villager->action.final_state = 0;
    villager->action.previous_state = 0;

    return villager;
}

Object* CreateMobileStatic(const EntityCreateParams& params) {
    Rock* rock = static_cast<Rock*>(calloc(1, sizeof(Rock)));
    if (!rock) return nullptr;
    InitObjectFromParams(rock, params);

    return rock;
}

} // namespace EntityFactory
