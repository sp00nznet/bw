#pragma once
// GlobalGameLists — master container for all typed entity lists in the game world
// Struct layout from bw1-decomp
// Size: 0x190 bytes

#include "Base.h"

// Forward declarations for list element types
struct AnimatedStatic;
struct Ball;
struct BigForest;
struct BuildingSite;
struct Dance;
struct EarthQuake;
struct Field;
struct FireEffect;
struct FireFly;
struct FishFarm;
struct Flock;
struct Forest;
struct Fragment;
struct GArena;
struct GBaseInfo;
struct GClimate;
struct GFootpath;
struct GFootpathFinder;
struct GParticleContainer;
struct GPlayer;
struct GStream;
struct GStreetLantern;
struct GStreetLight;
struct GWaterfall;
struct GameThing;
struct GameThingWithPos;
struct InfluenceRing;
struct Living;
struct MagicFireBall;
struct MapShield;
struct Mist;
struct MobileObject;
struct MultiMapFixed;
struct Object;
struct PileFood;
struct PuzzleGame;
struct Reaction;
struct Reward;
struct ScriptHighlight;
struct SoundTag;
struct Spell;
struct Town;
struct TownArtifact;
struct TownCentre;
struct Tree;
struct Villager;
struct Waypoint;
struct WeatherThing;
struct Whale;

// LHListHead: { T* first; T* last; } — 8 bytes each
// LHLinkedList: { T* first; T* last; } — 8 bytes each
// Both are structurally identical 8-byte head/tail pairs

#define DECL_LIST_HEAD(T) struct LHListHead_##T { T* first; T* last; }

DECL_LIST_HEAD(Ball);
DECL_LIST_HEAD(Forest);
DECL_LIST_HEAD(Living);
DECL_LIST_HEAD(Spell);
DECL_LIST_HEAD(GParticleContainer);
DECL_LIST_HEAD(Dance);
DECL_LIST_HEAD(Reaction);
DECL_LIST_HEAD(EarthQuake);
DECL_LIST_HEAD(Villager);
DECL_LIST_HEAD(Field);
DECL_LIST_HEAD(FishFarm);
DECL_LIST_HEAD(FireEffect);
DECL_LIST_HEAD(SoundTag);
DECL_LIST_HEAD(Mist);
DECL_LIST_HEAD(GStreetLight);
DECL_LIST_HEAD(GStreetLantern);
DECL_LIST_HEAD(PileFood);
DECL_LIST_HEAD(InfluenceRing);
DECL_LIST_HEAD(WeatherThing);
DECL_LIST_HEAD(GStream);
DECL_LIST_HEAD(GFootpath);
DECL_LIST_HEAD(GWaterfall);
DECL_LIST_HEAD(Waypoint);
DECL_LIST_HEAD(GArena);
DECL_LIST_HEAD(ScriptHighlight);
DECL_LIST_HEAD(MagicFireBall);
DECL_LIST_HEAD(MapShield);
DECL_LIST_HEAD(GPlayer);
DECL_LIST_HEAD(BigForest);
DECL_LIST_HEAD(GBaseInfo);
DECL_LIST_HEAD(Whale);
DECL_LIST_HEAD(FireFly);
DECL_LIST_HEAD(PuzzleGame);
DECL_LIST_HEAD(GameThing);

#define DECL_LINKED_LIST(T) struct LHLinkedList_##T { T* first; T* last; }

DECL_LINKED_LIST(MobileObject);
DECL_LINKED_LIST(GFootpathFinder);
DECL_LINKED_LIST(Flock);
DECL_LINKED_LIST(Town);
DECL_LINKED_LIST(GameThingWithPos);
DECL_LINKED_LIST(BuildingSite);
DECL_LINKED_LIST(MultiMapFixed);
DECL_LINKED_LIST(AnimatedStatic);
DECL_LINKED_LIST(Reward);
DECL_LINKED_LIST(Object);
DECL_LINKED_LIST(Tree);
DECL_LINKED_LIST(GClimate);
DECL_LINKED_LIST(TownCentre);
DECL_LINKED_LIST(TownArtifact);
DECL_LINKED_LIST(Fragment);

#undef DECL_LIST_HEAD
#undef DECL_LINKED_LIST

struct GlobalGameLists : public Base {
    LHListHead_Ball                 balls;                     // 0x08
    LHListHead_Forest               forests;                   // 0x10
    LHListHead_Living               living_list;               // 0x18
    LHListHead_Spell                spells;                    // 0x20
    LHListHead_GParticleContainer   particle_containers;       // 0x28
    LHListHead_Dance                dances;                    // 0x30
    LHListHead_Reaction             reactions;                 // 0x38
    LHLinkedList_MobileObject       mobile_objects;            // 0x40
    LHLinkedList_GFootpathFinder    footpath_finder;           // 0x48
    LHListHead_EarthQuake           earthquakes;               // 0x50
    LHListHead_Villager             villagers_without_town;    // 0x58
    LHListHead_Field                fields;                    // 0x60
    LHListHead_FishFarm             fish_farms;                // 0x68
    LHListHead_FireEffect           fire_effects;              // 0x70
    LHListHead_SoundTag             sound_tags;                // 0x78
    LHListHead_Mist                 mist;                      // 0x80
    LHListHead_GStreetLight         street_lights;             // 0x88
    LHListHead_GStreetLantern       street_lanterns;           // 0x90
    LHListHead_PileFood             food_piles;                // 0x98
    LHLinkedList_Flock              flocks;                    // 0xA0
    LHListHead_InfluenceRing        influence_ring_list;       // 0xA8
    LHListHead_WeatherThing         weather_things;            // 0xB0
    LHListHead_GStream              streams;                   // 0xB8
    LHListHead_GFootpath            footpaths;                 // 0xC0
    LHListHead_GWaterfall           waterfalls;                // 0xC8
    LHListHead_Waypoint             waypoints;                 // 0xD0
    LHListHead_GArena               arenas;                    // 0xD8
    LHLinkedList_Town               town_list;                 // 0xE0
    LHLinkedList_GameThingWithPos   game_thing_with_pos;       // 0xE8
    LHListHead_ScriptHighlight      script_highlights;         // 0xF0
    LHListHead_MagicFireBall        magic_fire_balls;          // 0xF8
    LHListHead_MapShield            map_shields;               // 0x100
    LHLinkedList_BuildingSite       building_sites;            // 0x108
    LHLinkedList_MultiMapFixed      multi_map_fixed;           // 0x110
    LHLinkedList_AnimatedStatic     animated_statics;          // 0x118
    LHListHead_GPlayer              players;                   // 0x120
    LHLinkedList_Reward             rewards;                   // 0x128
    LHLinkedList_Object             objects;                   // 0x130
    LHLinkedList_Tree               trees;                     // 0x138
    LHListHead_BigForest            big_forests;               // 0x140
    LHListHead_GBaseInfo            base_infos;                // 0x148
    LHLinkedList_GClimate           climates;                  // 0x150
    LHLinkedList_TownCentre         town_centres;              // 0x158
    LHListHead_Whale                whales;                    // 0x160
    LHListHead_FireFly              fire_flies;                // 0x168
    LHListHead_PuzzleGame           puzzle_game;               // 0x170
    LHListHead_GameThing            game_things;               // 0x178
    LHLinkedList_TownArtifact       town_artifacts;            // 0x180
    LHLinkedList_Fragment           fragments;                 // 0x188
};
static_assert(sizeof(GlobalGameLists) == 0x190, "GlobalGameLists size mismatch");
