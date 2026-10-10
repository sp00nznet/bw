// v1.0's physics game layer: the pool (sub_5F3990 / sub_5F3000), objects
// joining it (sub_5F30F0 thrown, sub_5F3B40 at rest) and the turn
// (sub_5F3D10). docs/physics.md.

#include <black/PhysicsObject.h>

#include <black/Map.h>
#include <black/Object.h>
#include <black/Terrain.h>
#include <black/Villager.h>

#include <algorithm>
#include <cmath>

namespace physics {

namespace {

std::vector<PhysicsObject*> g_pool;

void Remove(size_t i) {
    for (PhysicsObject* e : g_pool) if (e->hit == g_pool[i]) e->hit = nullptr;
    delete g_pool[i];
    g_pool[i] = g_pool.back();  // the original moves the last entry into the gap
    g_pool.pop_back();
}

// SetUpPhysOb (vslot 483, sub_5E9B20): the object's material (vslot 482),
// weight (vslot 398, at least 0.01) and whether it moves at all; the points
// from its mesh; then the body placed at the object.
// ponytail: the orientation is the object's y angle only; v1.0 takes its 3D
// object's whole matrix (+0x40 -> +20).
bool SetUp(PhysicsObject* e, Object* o) {
    const Material* m = PhysicsConstants(static_cast<int>(o->GetPhysicsConstantsType()));
    if (!m) return false;
    std::vector<Vec3> v;
    std::vector<int> faces;
    if (g_mesh_points_func) {
        static float xyz[3 * 4096];
        const int n = g_mesh_points_func(o->GetMesh(), xyz, 4096);
        for (int i = 0; i < n; ++i) v.push_back({xyz[3 * i], xyz[3 * i + 1], xyz[3 * i + 2]});
    }
    // ponytail: a host mesh brings its points only; its faces (sub_75A110's
    // index triples) would need a faces hook, so such a body is not hit by
    // others yet. The box has both.
    if (v.empty()) UnitBox(v, faces);
    const float c = std::cos(o->y_angle), s = std::sin(o->y_angle);
    const float rows[9] = {c, 0, -s, 0, 1, 0, s, 0, c};
    const bool on = o->CanBecomeAPhysicsObject() && !(o->field_0x24 & 0x1000);
    e->body.Setup(v, o->scale > 0.0f ? o->scale : 1.0f, std::max(o->GetWeight(), 0.0099999998f), *m, on, rows,
                  {MetresOf(o->coords.x), o->coords.altitude, MetresOf(o->coords.z)}, faces);
    return true;
}

PhysicsObject* Join(Object* o, Object* thrower, GInterfaceStatus* status, bool resting) {
    auto* e = new PhysicsObject();
    if (!SetUp(e, o)) { delete e; return nullptr; }
    e->object = o;
    e->thrower = thrower;
    e->status = status;
    e->body.asleep = resting;
    e->villager = dynamic_cast<Villager*>(o) ? 1 : 0;
    e->flags = 1u | (o->GetAlwaysRemainsInPhysicsInternalSystem() ? 0x80u : 0u);
    g_pool.push_back(e);
    return e;
}

// The object to where the body is: the centre less the turned, scaled
// average of its points (sub_75B770's translation).
void PlaceObject(PhysicsObject* e) {
    const RigidBody& b = e->body;
    const float k = e->object->scale > 0.0f ? e->object->scale : 1.0f;
    const Vec3 c{b.centroid.x * k, b.centroid.y * k, b.centroid.z * k};
    const float x = b.pos.x - (c.x * b.rows[0] + c.y * b.rows[3] + c.z * b.rows[6]);
    const float y = b.pos.y - (c.x * b.rows[1] + c.y * b.rows[4] + c.z * b.rows[7]);
    const float z = b.pos.z - (c.x * b.rows[2] + c.y * b.rows[5] + c.z * b.rows[8]);
    // ponytail: v1.0 also turns the object to the body (sub_759210 ->
    // vslot 325) and moves it between map cells; only the position is kept.
    e->object->coords = MapCoordsFromMetres(x, z, y);
}

}  // namespace

PhysicsObject* Find(const Object* o) {
    for (PhysicsObject* e : g_pool) if (e->object == o) return e;
    return nullptr;
}

const std::vector<PhysicsObject*>& Pool() { return g_pool; }

void ResetPool() {
    for (PhysicsObject* e : g_pool) delete e;
    g_pool.clear();
}

PhysicsObject* Throw(Object* o, const Vec3& vel, const Vec3& spin, Object* thrower, GInterfaceStatus* status) {
    if (!o || !o->CanBecomeAPhysicsObject() || (o->field_0x24 & 0x1000)) return nullptr;
    for (size_t i = 0; i < g_pool.size(); ++i) {
        if (g_pool[i]->object != o) continue;
        if (!g_pool[i]->body.asleep) return nullptr;
        Remove(i);
        break;
    }
    PhysicsObject* e = Join(o, thrower, status, false);
    if (!e) return nullptr;
    RigidBody& b = e->body;
    // The spin through the inertia, to the world: the angular momentum.
    const float* I = b.inertia;
    const Vec3 l{I[0] * spin.x + I[3] * spin.y + I[6] * spin.z, I[1] * spin.x + I[4] * spin.y + I[7] * spin.z,
                 I[2] * spin.x + I[5] * spin.y + I[8] * spin.z};
    b.ang_mom = {l.x * b.rows[0] + l.y * b.rows[3] + l.z * b.rows[6], l.x * b.rows[1] + l.y * b.rows[4] + l.z * b.rows[7],
                 l.x * b.rows[2] + l.y * b.rows[5] + l.z * b.rows[8]};
    b.vel = vel;
    const float sp = std::sqrt(vel.x * vel.x + vel.y * vel.y + vel.z * vel.z);
    if (sp > kMaxSpeed) b.vel = {vel.x * kMaxSpeed / sp, vel.y * kMaxSpeed / sp, vel.z * kMaxSpeed / sp};
    return e;
}

PhysicsObject* AddResting(Object* o) { return o ? Join(o, nullptr, 0, true) : nullptr; }

void Step() {
    // Gone objects leave; the dead sink faster. ponytail: the previous
    // orientation (+212) the renderer blends from is not kept.
    for (size_t i = 0; i < g_pool.size();) {
        PhysicsObject* e = g_pool[i];
        if (e->object->GetLife() < 0.0099999998f) e->body.buoyancy += 0.0099999998f;
        if (!e->object->IsAvailable()) { Remove(i); continue; }
        e->impulse = Vec3{};
        e->body.hit = nullptr;
        ++i;
    }
    // Moving entries are kept; resting ones go unless always kept (bit 7).
    for (PhysicsObject* e : g_pool) {
        if (!(e->flags & 1)) { if (!e->body.asleep) e->flags |= 1; }
        else if (e->body.asleep && !(e->flags & 0x80)) e->flags &= ~1u;
    }
    // What lies in the map cells under a moving body (its radius and a tenth
    // of a second of travel either way) and interacts (vslot 487) is kept,
    // or joins at rest.
    // ponytail: v1.0 adds only objects with a 3D object (+0x40); bw_core
    // makes none and the host draws everything on the map, so all may join.
    for (size_t i = 0; i < g_pool.size(); ++i) {
        const RigidBody& b = g_pool[i]->body;
        if (b.asleep || !g_map) continue;
        const float m = std::sqrt(b.vel.x * b.vel.x + b.vel.y * b.vel.y + b.vel.z * b.vel.z) * 0.1f + b.radius;
        const MapCoords lo = MapCoordsFromMetres(b.pos.x - m, b.pos.z - m), hi = MapCoordsFromMetres(b.pos.x + m, b.pos.z + m);
        const int x0 = std::max(static_cast<int>(lo.x.full) >> 16, 0), z0 = std::max(static_cast<int>(lo.z.full) >> 16, 0);
        const int x1 = std::min(static_cast<int>(hi.x.full) >> 16, 511), z1 = std::min(static_cast<int>(hi.z.full) >> 16, 511);
        std::vector<Object*> near;
        for (int x = x0; x <= x1; ++x)
            for (int z = z0; z <= z1; ++z) {
                if (!g_map->InBounds(x, z)) continue;
                const MapCell* c = g_map->ToMap(x, z);
                for (Object* o = c->first_object_fixed; o; o = o->map_parent) near.push_back(o);
                for (Object* o = c->first_object_mobile; o; o = o->map_child) near.push_back(o);
            }
        for (Object* o : near) {
            if (!o->InteractsWithPhysicsObjects()) continue;
            if (PhysicsObject* e = Find(o)) e->flags |= 1;
            else AddResting(o);
        }
    }
    for (size_t i = 0; i < g_pool.size();)
        if (!(g_pool[i]->flags & 1)) Remove(i); else ++i;

    for (int sub = 0; sub < 20; ++sub) {
        for (PhysicsObject* e : g_pool) { e->body.Predict(); e->body.Forces(); }
        // Each pair whose bounding spheres meet: the first's points against
        // the second's faces (sub_75C060), unless the first checks no bodies
        // (vslot 488, bit 4), both rest, a villager meets an entry that passes
        // through villagers, or one threw the other.
        for (PhysicsObject* a : g_pool) {
            if (!a->object->ChecksVerticesVObjects() || (a->flags & 0x10)) continue;
            for (PhysicsObject* b : g_pool) {
                if (a == b) continue;
                RigidBody& ab = a->body;
                RigidBody& bb = b->body;
                if (ab.asleep && bb.asleep && !ab.fresh && !bb.fresh) continue;
                if ((a->villager == 1 && (b->flags & 2)) || (b->villager == 1 && (a->flags & 2))) continue;
                if (a->thrower == b->object || b->thrower == a->object) continue;
                const float r = ab.radius + bb.radius;
                const Vec3 d{ab.pos.x - bb.pos.x, ab.pos.y - bb.pos.y, ab.pos.z - bb.pos.z};
                if (!(r * r > d.x * d.x + d.y * d.y + d.z * d.z)) continue;
                ab.Collide(bb);
            }
        }
        for (PhysicsObject* e : g_pool) e->body.Contacts();
        for (size_t i = 0; i < g_pool.size(); ++i) {
            PhysicsObject* e = g_pool[i];
            RigidBody& b = e->body;
            int code = b.Integrate();
            // Floating low with water taken on: things that sink (vslot 494)
            // stop here. ponytail: the splash (the list at 0xDCA62C) and the
            // landing sound (vslot 501, sample 69..73) are not made.
            if (!b.asleep && b.radius * 0.5f > b.pos.y && b.buoyancy > 1.0f && e->object->HasSunk()) {
                b.vel = b.ang_mom = Vec3{};
                code = 2;
            }
            switch (code) {
            case 1: PlaceObject(e); break;
            case 2:  // at rest: v1.0 sub_5F5A80, then EndPhysics (vslot 484)
                PlaceObject(e);
                e->object->EndPhysics(e, true);
                b.asleep = true;
                break;
            case 3:  // touched while asleep: InitialisePhysics (vslot 481) wakes it
                if (e->object->CanBecomeAPhysicsObject() && !(e->object->field_0x24 & 0x1000)) b.asleep = false;
                break;
            case 4:  // sunk: v1.0 deletes it (vslot 3)
                // ponytail: taken off the map and marked unavailable (+0xA bit
                // 0) instead, as TakeResourceOf does: our ToBeDeleted frees at
                // once and the level's object list still holds it.
                if (e->object->IsAvailable()) {
                    if (e->object->IsObjectInMap_0()) e->object->RemoveMapObject();
                    e->object->field_0xa |= 1;
                }
                break;
            default: break;
            }
            if (b.touching) e->impulse = {e->impulse.x + b.force.x, e->impulse.y + b.force.y, e->impulse.z + b.force.z};
        }
    }
    // The turn's knocks: a strength from the forces while touching; a hard
    // one (over half the weight) would hurt what is around (sub_5F5240);
    // every one reaches the object (vslot 491).
    // ponytail: sub_5F5240's damage, the creature's lessons from a thrown
    // object landing (sub_4CB260 kinds 15 / 16) and sub_686F30 are not.
    for (size_t i = 0; i < g_pool.size(); ++i) {
        PhysicsObject* e = g_pool[i];
        const Vec3& p = e->impulse;
        const float i2 = p.x * p.x + p.y * p.y + p.z * p.z;
        if (i2 <= 0.000099999997f) continue;
        e->strength = std::sqrt(i2) * 0.050000001f;
        // The entry of the body it last touched; an entry nobody threw takes
        // the hand of the one that hit it.
        if (!e->body.hit) e->hit = nullptr;
        for (PhysicsObject* o : g_pool) {
            if (&o->body != e->body.hit) continue;
            if (!e->status) e->status = o->status;
            e->hit = o;
        }
        e->object->ReactToPhysicsImpact(e, false);
    }
}

}  // namespace physics
