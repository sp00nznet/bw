#pragma once
// LevelLoader — reads a land script (Land1.txt ...) the way the game does and
// builds the world in bw_core: towns, their abodes and villagers, trees,
// animals, features. Translated from the original's level-script dispatcher
// (sub_6AD5E0, one case per command of the 105-entry table at 0xB44048).
// See docs/level-loader.md.

#include <cstdint>
#include <map>
#include <string>
#include <vector>

struct Object;
struct Town;

namespace level {

// One object the script made, with what a renderer needs to pick a mesh.
struct Spawned {
    Object*     obj;
    std::string command;    // "CREATE_ABODE", "CREATE_NEW_TREE", ...
    std::string type_name;  // the script's type string, when it names one
    int         type_index; // the info record index, when it gives a number (-1 otherwise)
};

struct World {
    std::vector<Town*>   towns;
    std::vector<Spawned> objects;
    std::string landscape;                   // LOAD_LANDSCAPE path, as written
    float camera_x = 0, camera_z = 0;        // START_CAMERA_POS
    int   land_number = 0;
    int   lines = 0, commands = 0, handled = 0;
    std::map<std::string, int> unhandled;    // command -> occurrences
};

// Parses the script and creates its objects. Needs info.dat loaded (objects
// get their records from it) and, for altitudes, g_terrain_height_func set.
bool Load(const char* path, World& out, std::string* err = nullptr);

// The town a script refers to by id (CREATE_TOWN's first argument).
Town* FindTown(const World& w, uint32_t id);

// Run one simulation turn over the world: towns, then their objects.
void Process(World& w);

} // namespace level
