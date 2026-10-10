// v1.0's physics game layer: the pool (sub_5F3990 / sub_5F3000), objects
// joining it (sub_5F30F0 thrown, sub_5F3B40 at rest) and the turn
// (sub_5F3D10). docs/physics.md.

#include <black/PhysicsObject.h>

#include <black/Object.h>
#include <black/Terrain.h>
#include <black/Villager.h>

#include <algorithm>
#include <cmath>

namespace physics {

namespace {

std::vector<PhysicsObject*> g_pool;

void Remove(size_t i) {
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
    if (g_mesh_points_func) {
        static float xyz[3 * 4096];
        const int n = g_mesh_points_func(o->GetMesh(), xyz, 4096);
        for (int i = 0; i < n; ++i) v.push_back({xyz[3 * i], xyz[3 * i + 1], xyz[3 * i + 2]});
    }
    if (v.empty())
        for (int i = 0; i < 8; ++i) v.push_back({i & 1 ? 0.5f : -0.5f, i & 2 ? 0.5f : -0.5f, i & 4 ? 0.5f : -0.5f});
    const float c = std::cos(o->y_angle), s = std::sin(o->y_angle);
    const float rows[9] = {c, 0, -s, 0, 1, 0, s, 0, c};
    const bool on = o->CanBecomeAPhysicsObject() && !(o->field_0x24 & 0x1000);
    e->body.Setup(v, o->scale > 0.0f ? o->scale : 1.0f, std::max(o->GetWeight(), 0.0099999998f), *m, on, rows,
                  {MetresOf(o->coords.x), o->coords.altitude, MetresOf(o->coords.z)});
    return true;
}

PhysicsObject* Join(Object* o, Object* thrower, int kind, bool resting) {
    auto* e = new PhysicsObject();
    if (!SetUp(e, o)) { delete e; return nullptr; }
    e->object = o;
    e->thrower = thrower;
    e->kind = kind;
    e->resting = resting;
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

PhysicsObject* Throw(Object* o, const Vec3& vel, const Vec3& spin, Object* thrower, int kind) {
    if (!o || !o->CanBecomeAPhysicsObject() || (o->field_0x24 & 0x1000)) return nullptr;
    for (size_t i = 0; i < g_pool.size(); ++i) {
        if (g_pool[i]->object != o) continue;
        if (!g_pool[i]->resting) return nullptr;
        Remove(i);
        break;
    }
    PhysicsObject* e = Join(o, thrower, kind, false);
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
        e->hit = nullptr;
        ++i;
    }
    // Moving entries are kept; resting ones go unless always kept (bit 7).
    // ponytail: v1.0 first wakes what lies in the map cells under each moving
    // body (vslot 487, sub_5F3B40), which keeps those too.
    for (PhysicsObject* e : g_pool) {
        if (!(e->flags & 1)) { if (!e->resting) e->flags |= 1; }
        else if (e->resting && !(e->flags & 0x80)) e->flags &= ~1u;
    }
    for (size_t i = 0; i < g_pool.size();)
        if (!(g_pool[i]->flags & 1)) Remove(i); else ++i;

    for (int sub = 0; sub < 20; ++sub) {
        for (PhysicsObject* e : g_pool) { e->body.Predict(); e->body.Forces(); }
        // ponytail: body-to-body contacts (sub_75C060 over each pair, not a
        // thrower and what it threw) are not translated.
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
        e->object->ReactToPhysicsImpact(e, false);
    }
}

}  // namespace physics
