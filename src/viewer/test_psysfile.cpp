// test_psysfile — every particle graph in game_data/ZSpellFiles loads
// (inflate to the size its header gives, then parse), and the Food graph has
// the shape the Food miracle's drops depend on. Skips without game_data.
#include <black/SpellFile.h>

#include <cstdio>
#include <filesystem>
#include <set>
#include <string>

static int g_fail = 0;
#define CHECK(cond, msg) do { if (!(cond)) { printf("FAIL: %s\n", msg); ++g_fail; } \
                              else printf("ok  : %s\n", msg); } while (0)

int main() {
    namespace fs = std::filesystem;
    std::string dir;
    for (const char* r : {"game_data/", "../game_data/", "../../game_data/", "../../../game_data/"})
        if (fs::exists(std::string(r) + "ZSpellFiles")) { dir = std::string(r) + "ZSpellFiles"; break; }
    if (dir.empty()) { printf("note: game_data not reachable; skipped\n"); return 0; }

    char msg[256];
    int files = 0, loaded = 0;
    size_t classes = 0;
    std::set<std::string> types;
    std::string failed;
    for (const auto& e : fs::directory_iterator(dir)) {
        if (e.path().extension() != ".zzz") continue;
        ++files;
        psys::SpellFile f;
        if (!f.Load(e.path().string())) { failed += " " + e.path().filename().string(); continue; }
        ++loaded;
        classes += f.classes.size();
        for (const auto& c : f.classes) types.insert(c.type);
    }
    std::snprintf(msg, sizeof msg, "ZSpellFiles: %d of %d graphs inflate and parse (%zu rule objects, %zu classes)%s",
                  loaded, files, classes, types.size(), failed.c_str());
    CHECK(files == 132 && loaded == files && types.size() == 135, msg);

    psys::SpellFile food;
    if (food.Load(dir + "/SF_Food_txt.zzz")) {
        const psys::SpellClass* sprinkle = food.Find("UR_HandSprinkle0");
        const psys::SpellClass* collide = food.Find("LandscapeCollide0");
        const psys::SpellClass* gravity = food.Find("UpdateRuleGravity0");
        const bool ok = sprinkle && collide && gravity && sprinkle->Get("TotalTime")->Float() == 4.0f &&
                        sprinkle->Get("NextGroups")->Array().size() == 1 && sprinkle->Get("NextGroups")->Array()[0] == 1.0f &&
                        sprinkle->Get("KeyPoints")->Array().size() == 8 && collide->Get("SendEvent")->Bool() &&
                        collide->Get("Group")->Int() == 1 && gravity->Get("Gravity")->Float() == 15.0f &&
                        sprinkle->Get("PCreator")->Str() == "ParticlePointCreator0" && food.header.count("InitiallyCreated");
        std::snprintf(msg, sizeof msg, "SF_Food: the hand sprinkles grains (group 0 -> 1, %.0f s) that fall (gravity %.0f) and report landing (LandscapeCollide, group 1)",
                      sprinkle ? sprinkle->Get("TotalTime")->Float() : -1.0f, gravity ? gravity->Get("Gravity")->Float() : -1.0f);
        CHECK(ok, msg);
    }

    printf(g_fail ? "\n%d FAILED\n" : "\nall passed\n", g_fail);
    return g_fail ? 1 : 0;
}
