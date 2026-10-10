// The rigid body (v1.0 0x759D60..0x75C860): a 1 m box dropped onto flat
// land comes to rest on it, sitting level; one dropped into the sea floats
// at the surface for a while, then sinks as it takes on water.
#include <black/RigidBody.h>
#include <black/PhysicsObject.h>
#include <black/EntityFactory.h>
#include <black/InfoDat.h>
#include <black/MobileObject.h>
#include <black/Terrain.h>

#include <cmath>
#include <cstdio>
#include <string>

using namespace physics;

static int g_fail = 0;
#define CHECK(c, m) do { bool ok_ = (c); printf("%s: %s\n", ok_ ? "ok  " : "FAIL", m); if (!ok_) ++g_fail; } while (0)

static float g_ground = 10.0f;
static float Flat(float, float) { return g_ground; }

static RigidBody Box(const Material& m, float x, float y, float z) {
    std::vector<Vec3> v;
    for (int i = 0; i < 8; ++i) v.push_back({i & 1 ? 0.5f : -0.5f, i & 2 ? 0.5f : -0.5f, i & 4 ? 0.5f : -0.5f});
    const float rows[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};
    RigidBody b;
    b.Setup(v, 1.0f, 10.0f, m, true, rows, {x, y, z});
    return b;
}

int main() {
    setvbuf(stdout, nullptr, _IONBF, 0);
    const char* roots[] = {"game_data/", "../game_data/", "../../game_data/", "../../../game_data/"};
    std::string root;
    for (const char* r : roots)
        if (LoadPhysicsConstants((std::string(r) + "PhysicsConstants.txt").c_str())) { root = r; break; }
    if (root.empty()) { printf("note: game_data not reachable; skipped\n"); return 0; }
    char msg[256];
    g_terrain_height_func = Flat;

    const Material* m = PhysicsConstants(0);
    std::snprintf(msg, sizeof msg, "PhysicsConstants.txt: row 0 = %.2f %.2f %.2f %.2f %.2f %.2f, row 23 loaded %d",
                  m ? m->v[0] : 0, m ? m->v[1] : 0, m ? m->v[2] : 0, m ? m->v[3] : 0, m ? m->v[4] : 0, m ? m->v[5] : 0,
                  PhysicsConstants(23) != nullptr);
    CHECK(m && m->v[1] == 78.75f && PhysicsConstants(23) && !PhysicsConstants(24), msg);

    {
        // Land at 10 m, the box's centre at 15 m: it falls, lands, settles.
        // Rows: material 1 (a softer, stickier one) is what the check uses.
        RigidBody b = Box(*PhysicsConstants(1), 100.0f, 15.0f, 100.0f);
        const float r0 = b.radius;
        int code = 1, steps = 0, first_touch = -1;
        float lowest = b.pos.y;
        while (code != 2 && code != 0 && steps < 20 * 600) {  // a minute of game time at most
            code = b.Step();
            if (b.touching && first_touch < 0) first_touch = steps;
            lowest = std::fmin(lowest, b.pos.y);
            ++steps;
        }
        const float tilt = std::fabs(b.rows[4]);  // the body's up row still up
        std::snprintf(msg, sizeof msg, "a box dropped 4.5 m onto land: touches at step %d (%.2f s), rests (code %d) after %.1f s at y %.3f (lowest %.3f), up row y %.3f, radius %.3f",
                      first_touch, first_touch * kSubstep, code, steps * kSubstep, b.pos.y, lowest, tilt, r0);
        // Free fall from 4.5 m (centre 15, base 14.5 over land at 10) takes
        // ~0.96 s; the 60 ms look-ahead touches a little earlier. The contact
        // spring is k x (first depth) + 200 c x (depth - first depth), soft
        // for this material, and the body rests (code 2) at its first slow
        // moment while touching -- here the bottom of the landing, its base
        // ~0.6 m into the land; the game layer leaves the object there.
        CHECK(code == 2 && first_touch > 120 && first_touch < 200 && steps - first_touch < 100 &&
              b.pos.y > 10.5f - 0.75f && b.pos.y < 10.5f && tilt > 0.99f, msg);
    }
    {
        // The sea: land at 0. Dropped from 3 m it floats, then sinks.
        g_ground = 0.0f;
        RigidBody b = Box(*PhysicsConstants(1), 100.0f, 3.0f, 100.0f);
        int steps = 0, code = 1;
        float after3s = 0.0f;
        bool floated = false;
        while (code != 4 && steps < 20 * 6000) {
            code = b.Step();
            ++steps;
            if (steps == 600) after3s = b.pos.y;
            floated = floated || b.floating;
        }
        std::snprintf(msg, sizeof msg, "a box dropped into the sea: floating %d, y after 3 s %.3f, sinks (code %d) after %.0f s, buoyancy divisor %.2f",
                      floated, after3s, code, steps * kSubstep, b.buoyancy);
        CHECK(floated && std::fabs(after3s) < b.radius && code == 4, msg);
    }

    // The game layer (sub_5F30F0 / sub_5F3D10): a mobile object thrown at
    // 3 m/s across and 4 up flies, lands and rests as the pool's turns run,
    // placed where its body stopped; one thrown into the sea sinks and is
    // deleted, and the pool lets it go.
    if (infodat::Load((root + "info.dat").c_str())) {
        g_ground = 10.0f;
        EntityCreateParams p{};
        p.world_x = 200.0f; p.world_z = 200.0f; p.angle = 0.0f; p.scale = 1.0f; p.mesh_id = -1; p.type_enum = 0;
        p.type_name = "test";
        Object* o = EntityFactory::CreateEntity(ENTITY_CAT_MOBILE_OBJECT, p);
        o->coords = MapCoordsFromMetres(200.0f, 200.0f, 10.6f);
        PhysicsObject* e = physics::Throw(o, {3.0f, 4.0f, 0.0f}, {}, nullptr, nullptr);
        int turns = 0;
        float peak = 0.0f, hardest = 0.0f;
        while (e && !e->body.asleep && turns < 200) {
            physics::Step();
            peak = std::fmax(peak, o->coords.altitude);
            hardest = std::fmax(hardest, e->strength);
            ++turns;
        }
        const float moved = MetresOf(o->coords.x) - 200.0f;
        std::snprintf(msg, sizeof msg, "a thrown mobile object (weight %.2f, material %u): rests after %d turns, %.2f m on, peak %.2f, at y %.2f, hardest knock %.1f; pool %zu",
                      o->GetWeight(), o->GetPhysicsConstantsType(), turns, moved, peak, o->coords.altitude, hardest, physics::Pool().size());
        CHECK(e && e->body.asleep && turns < 200 && moved > 0.5f && peak > 10.8f && std::fabs(o->coords.altitude - 10.0f) < 1.0f &&
              hardest > 0.0f && physics::Pool().size() == 1, msg);

        g_ground = 0.0f;
        physics::ResetPool();
        Object* s2 = EntityFactory::CreateEntity(ENTITY_CAT_MOBILE_OBJECT, p);
        s2->coords = MapCoordsFromMetres(200.0f, 200.0f, 2.0f);
        physics::Throw(s2, {}, {}, nullptr, nullptr);
        turns = 0;
        while (s2->IsAvailable() && turns < 2000) { physics::Step(); ++turns; }
        physics::Step();
        std::snprintf(msg, sizeof msg, "a mobile object in the sea: deleted after %d turns (%.0f s), pool %zu",
                      turns, turns * 0.1f, physics::Pool().size());
        CHECK(!s2->IsAvailable() && turns < 2000 && physics::Pool().empty(), msg);
    } else {
        printf("note: info.dat not reachable; game-layer checks skipped\n");
    }

    printf(g_fail ? "\n%d FAILED\n" : "\nall passed\n", g_fail);
    return g_fail ? 1 : 0;
}
