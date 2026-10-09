// EntityFactory — creates bw_core entity instances from level data
// Bridges the level script parser with the real game entity hierarchy.

#include <black/EntityFactory.h>
#include <black/Object.h>
#include <black/Tree.h>
#include <black/Abode.h>
#include <black/StoragePit.h>
#include <black/Creche.h>
#include <black/Workshop.h>
#include <black/Wonder.h>
#include <black/Graveyard.h>
#include <black/TownCentre.h>
#include <black/Field.h>
#include <black/Forest.h>
#include <black/BigForest.h>
#include <black/FishFarm.h>
#include <black/MobileObject.h>
#include <black/Villager.h>
#include <black/Rock.h>
#include <black/Bonfire.h>
#include <black/DeadTree.h>
#include <black/GStreetLantern.h>
#include <black/AnimatedStatic.h>
#include <black/MobileStatic.h>
#include <black/Feature.h>
#include <black/Animal.h>
#include <black/Creature.h>
#include <black/Terrain.h>
#include <black/Map.h>
#include <black/LHVMObjects.h>
#include <black/InfoDat.h>
#include <cstdlib>
#include <cstring>

extern GMap* g_map;

// Helper: set common Object fields from create params
static void InitObjectFromParams(Object* obj, const EntityCreateParams& params) {
    MapCoords pos = MapCoordsFromMetres(params.world_x, params.world_z,
                                        GetTerrainHeightAt(params.world_x, params.world_z));
    obj->SetPos(pos);
    obj->obj_coords = pos;
    obj->y_angle = params.angle;
    obj->scale = params.scale > 0.0f ? params.scale : 1.0f;
    obj->life = 1.0f;
    // sub_5E8A80: every Object takes the next serial from a game-wide counter (+0x3C).
    static uint32_t s_next_serial = 0;
    obj->field_0x3c = s_next_serial++;
}

// The object's balance record. Level scripts name the type (type_name);
// CHL's CREATE passes the info enum, which is the record index (type_enum).
// Null when info.dat is not loaded or the type does not resolve -- the
// object then runs on its built-in defaults, as it did before info.dat.
static const GObjectInfo* InfoFor(infodat::Section s, const EntityCreateParams& params) {
    int i = -1;
    if (params.type_name && *params.type_name)
        i = s == infodat::DETAIL_ABODE_INFO ? infodat::FindAbode(params.type_name)
                                            : infodat::FindByName(s, params.type_name);
    if (i < 0) i = static_cast<int>(params.type_enum);
    return infodat::Get<GObjectInfo>(s, static_cast<uint32_t>(i));
}

namespace EntityFactory {

Object* CreateEntity(EntityCategory category, const EntityCreateParams& params) {
    Object* obj = nullptr;
    switch (category) {
    case ENTITY_CAT_TREE:     obj = CreateTree(params);         break;
    case ENTITY_CAT_ABODE:    obj = CreateAbode(params);        break;
    case ENTITY_CAT_VILLAGER: obj = CreateVillager(params);     break;
    case ENTITY_CAT_MOBILE:
    case ENTITY_CAT_ROCK:     obj = CreateMobileStatic(params); break;
    case ENTITY_CAT_CREATURE: obj = CreateCreature(params);     break;
    case ENTITY_CAT_ANIMAL:   obj = CreateAnimal(params);       break;
    case ENTITY_CAT_MOBILE_OBJECT: obj = CreateMobileObject(params); break;
    case ENTITY_CAT_FIELD:    obj = CreateField(params);        break;
    case ENTITY_CAT_FISH_FARM: obj = CreateFishFarm(params);    break;
    case ENTITY_CAT_BIG_FOREST: obj = CreateBigForest(params);  break;
    case ENTITY_CAT_BONFIRE:  obj = CreateBonfire(params);      break;
    case ENTITY_CAT_DEAD_TREE: obj = CreateDeadTree(params);    break;
    case ENTITY_CAT_STREET_LANTERN: obj = CreateStreetLantern(params); break;
    case ENTITY_CAT_ANIMATED_STATIC: obj = CreateAnimatedStatic(params); break;
    default: {
        // Generic feature fallback — allocate a Feature
        Feature* feat = new Feature();
        if (feat) {
            InitObjectFromParams(feat, params);
            feat->info = InfoFor(infodat::DETAIL_FEATURE_INFO, params);
            obj = feat;
        }
        break;
    }
    }
    if (obj) lhvm::RegisterObject(obj);
    return obj;
}

Object* CreateTree(const EntityCreateParams& params) {
    Tree* tree = new Tree();
    if (!tree) return nullptr;
    InitObjectFromParams(tree, params);
    tree->info = InfoFor(infodat::DETAIL_TREE_INFO, params);

    // Insert into map
    tree->InsertMapObject();

    return tree;
}

// The concrete class an abode record asks for, by GAbodeInfo::abodeType
// (info + 0x120) -- the same switch sub_401BA0 makes before construction.
// Types with no class of ours yet (totem 20, football pitch 4100, spell
// dispenser 8196) fall back to a plain Abode.
static Abode* NewAbodeFor(const GObjectInfo* info) {
    int32_t type = 2;
    if (info) std::memcpy(&type, reinterpret_cast<const char*>(info) + 0x120, 4);
    switch (type) {
    case 36:   return new StoragePit();
    case 68:   return new Creche();
    case 132:  return new Workshop();
    case 256:  return new Wonder();
    case 516:  return new Graveyard();
    case 1028: return new TownCentre();
    default:   return new Abode();
    }
}

Object* CreateAbode(const EntityCreateParams& params) {
    const GObjectInfo* info = InfoFor(infodat::DETAIL_ABODE_INFO, params);
    Abode* abode = NewAbodeFor(info);
    InitObjectFromParams(abode, params);
    abode->info = info;

    // Start fully built
    abode->percent_built = 1.0f;
    abode->field_0x58 = 8;  // "fully built" flag

    // Insert into map
    abode->InsertMapObject();

    return abode;
}

Object* CreateVillager(const EntityCreateParams& params) {
    Villager* villager = new Villager();
    if (!villager) return nullptr;
    InitObjectFromParams(villager, params);
    villager->info = InfoFor(infodat::DETAIL_VILLAGER_INFO, params);

    // Initialize villager state
    villager->food = 1.0f;
    villager->action.top_state = 0;  // INVALID — will be set by AI
    villager->action.final_state = 0;
    villager->action.previous_state = 0;
    villager->InsertMapObject();

    return villager;
}

Object* CreateMobileStatic(const EntityCreateParams& params) {
    Rock* rock = new Rock();
    if (!rock) return nullptr;
    InitObjectFromParams(rock, params);
    rock->info = InfoFor(infodat::DETAIL_MOBILE_STATIC_INFO, params);

    return rock;
}

Object* CreateAnimal(const EntityCreateParams& params) {
    // ponytail: one Animal class for every species; the 17 species subclasses
    // differ in virtuals we have not translated yet. Add a switch on the
    // species when one of them needs its own behaviour.
    Animal* animal = new Animal();
    InitObjectFromParams(animal, params);
    animal->info = InfoFor(infodat::DETAIL_ANIMAL_INFO, params);
    animal->InsertMapObject();
    return animal;
}

// sub_432250 -> sub_432150: a mobile static of the fixed record
// MOBILE_STATIC_INFO[8] (0xC5BF40). ponytail: its fire light (sub_5EFC40,
// 25 m) is not made, and our Bonfire is 0x94 where v1.0's is 152 bytes.
Object* CreateBonfire(const EntityCreateParams& params) {
    auto* b = new Bonfire();
    InitObjectFromParams(b, params);
    b->info = infodat::Get<GObjectInfo>(infodat::DETAIL_MOBILE_STATIC_INFO, 8);
    b->InsertMapObject();
    return b;
}

// sub_4EE200 -> sub_4EE080 (160 bytes): a tree record's dead tree.
Object* CreateDeadTree(const EntityCreateParams& params) {
    auto* t = new DeadTree();
    InitObjectFromParams(t, params);
    t->info = InfoFor(infodat::DETAIL_TREE_INFO, params);
    t->InsertMapObject();
    return t;
}

// sub_6CA4E0 (100 bytes). The caller skips one within 0.5 m of another.
Object* CreateStreetLantern(const EntityCreateParams& params) {
    auto* l = new GStreetLantern();
    InitObjectFromParams(l, params);
    l->info = InfoFor(infodat::DETAIL_MOBILE_STATIC_INFO, params);
    return l;
}

// sub_41CB70 (152 bytes): a MultiMapFixed made whole (sub_5044E0 with 1.0).
// ponytail: the game's animated-static list (+2104696) is not kept.
Object* CreateAnimatedStatic(const EntityCreateParams& params) {
    auto* s = new AnimatedStatic();
    InitObjectFromParams(s, params);
    s->info = InfoFor(infodat::DETAIL_ANIMATED_STATIC_INFO, params);
    s->percent_built = 1.0f;
    s->InsertMapObject();
    return s;
}

Object* CreateMobileObject(const EntityCreateParams& params) {
    MobileObject* mo = new MobileObject();
    InitObjectFromParams(mo, params);
    mo->info = InfoFor(infodat::DETAIL_MOBILE_OBJECT_INFO, params);
    return mo;
}

Object* CreateField(const EntityCreateParams& params) {
    Field* field = new Field();
    InitObjectFromParams(field, params);
    field->info = InfoFor(infodat::DETAIL_FIELD_TYPE_INFO, params);
    // +0x120: the field type record the crop code reads (sub_4FEB10's a3).
    // ponytail: v1.0's info (+0x28) is the tribe's abode record 15
    // (sub_4041D0); the type record stands in there too.
    field->type_info = reinterpret_cast<GFieldTypeInfo*>(const_cast<GObjectInfo*>(field->info));
    field->percent_built = 1.0f;
    field->InsertMapObject();
    return field;
}

Object* CreateBigForest(const EntityCreateParams& params) {
    // sub_431AA0 / sub_431940: the big forest, its Forest container (+0x80,
    // whose +0x38 points back), and its wood: scale x info +108.
    // ponytail: the global big-forest and forest lists live in level::World.
    BigForest* bf = new BigForest();
    InitObjectFromParams(bf, params);
    bf->info = InfoFor(infodat::DETAIL_BIG_FOREST_INFO, params);
    Forest* f = new Forest();
    f->coords = bf->coords;
    f->big_forest = bf;
    bf->forest = f;
    int32_t most = 0;
    if (bf->info) std::memcpy(&most, reinterpret_cast<const char*>(bf->info) + 108, 4);
    bf->wood = bf->scale * static_cast<float>(most);
    bf->InsertMapObject();
    return bf;
}

Object* CreateFishFarm(const EntityCreateParams& params) {
    FishFarm* farm = new FishFarm();
    InitObjectFromParams(farm, params);
    farm->info = InfoFor(infodat::DETAIL_FISH_FARM_INFO, params);
    farm->InsertMapObject();
    return farm;
}

Object* CreateCreature(const EntityCreateParams& params) {
    // Allocate using Creature::Create factory
    MapCoords pos = MapCoordsFromMetres(params.world_x, params.world_z,
                                        GetTerrainHeightAt(params.world_x, params.world_z));

    Creature* creature = Creature::Create(pos, nullptr, nullptr);
    if (!creature) return nullptr;

    creature->y_angle = params.angle;
    creature->scale = params.scale > 0.0f ? params.scale : 5.0f; // Creatures are big
    creature->life = 1.0f;
    creature->InsertMapObject();

    return creature;
}

} // namespace EntityFactory
