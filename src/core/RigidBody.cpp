// v1.0's rigid body: setup (sub_759DB0, sub_759E40, sub_75A110, sub_759EB0,
// sub_75AD90) and the four passes run every 5 ms substep (sub_75B830,
// sub_75BAD0, sub_75C440, sub_75C860). docs/physics.md.

#include <black/RigidBody.h>
#include <black/Terrain.h>

#include <algorithm>
#include <cmath>
#include <cstdio>

namespace physics {

namespace {

Material g_materials[24];
bool g_materials_loaded = false;

float Len(const Vec3& v) { return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z); }

// A body point to the world: x row0 + y row1 + z row2 + offset.
Vec3 ToWorld(const float r[9], const Vec3& l, const Vec3& o) {
    return {l.x * r[0] + l.y * r[3] + l.z * r[6] + o.x,
            l.x * r[1] + l.y * r[4] + l.z * r[7] + o.y,
            l.x * r[2] + l.y * r[5] + l.z * r[8] + o.z};
}

// The original's lever torque, F x r (its rotation convention matches).
void AddTorque(Vec3& t, const Vec3& r, const Vec3& f) {
    t.x += r.z * f.y - r.y * f.z;
    t.y += r.x * f.z - r.z * f.x;
    t.z += r.y * f.x - r.x * f.y;
}

// v1.0 sub_761570 takes the normal of the cell's land triangle.
// ponytail: a central difference of the height over 1 m instead; exact
// where the land is one plane, smoother across a cell's diagonal.
Vec3 LandNormal(float x, float z) {
    constexpr float d = 0.5f;
    Vec3 n{LandHeight(x - d, z) - LandHeight(x + d, z), 2 * d,
           LandHeight(x, z - d) - LandHeight(x, z + d)};
    const float l = Len(n);
    return {n.x / l, n.y / l, n.z / l};
}

// sub_759970: the inverse of a 3x3 (and its translation), the determinant
// held away from 0 by 1e-10 (flt_B5933C).
void Inverse(float out[12], const float a[12]) {
    const float c0 = a[8] * a[4] - a[7] * a[5];
    float det = (a[2] * a[7] - a[8] * a[1]) * a[3] + (a[5] * a[1] - a[2] * a[4]) * a[6] + c0 * a[0];
    if (std::fabs(det) < 1e-10f) det = det < 0 ? -1e-10f : 1e-10f;
    const float k = 1.0f / det;
    out[0] = c0 * k;
    out[3] = (a[6] * a[5] - a[8] * a[3]) * k;
    out[6] = (a[7] * a[3] - a[6] * a[4]) * k;
    out[1] = (a[2] * a[7] - a[8] * a[1]) * k;
    out[4] = (a[8] * a[0] - a[6] * a[2]) * k;
    out[7] = (a[6] * a[1] - a[0] * a[7]) * k;
    out[2] = (a[5] * a[1] - a[2] * a[4]) * k;
    out[5] = (a[2] * a[3] - a[0] * a[5]) * k;
    out[8] = (a[0] * a[4] - a[3] * a[1]) * k;
    out[9] = -(a[10] * out[3] + a[11] * out[6] + a[9] * out[0]);
    out[10] = -(out[7] * a[11] + a[9] * out[1] + out[4] * a[10]);
    out[11] = -(a[9] * out[2] + out[8] * a[11] + out[5] * a[10]);
}

// sub_759860: the rotation of `angle` about the unit axis a.
void AxisAngle(float m[9], const Vec3& a, float angle) {
    const float c = std::cos(angle), s = std::sin(angle);
    const float xx = a.x * a.x, yy = a.y * a.y, zz = a.z * a.z;
    const float xy = a.x * a.y, xz = a.x * a.z, yz = a.z * a.y;
    m[0] = (1 - xx) * c + xx;
    m[3] = xy - xy * c + s * a.z;
    m[6] = xz - xz * c - s * a.y;
    m[1] = xy - xy * c - s * a.z;
    m[4] = (1 - yy) * c + yy;
    m[7] = yz - yz * c + s * a.x;
    m[2] = xz - xz * c + s * a.y;
    m[5] = yz - yz * c - s * a.x;
    m[8] = (1 - zz) * c + zz;
}

// sub_4587A0: each row times m.
void MulRows(float r[9], const float m[9]) {
    float o[9];
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            o[3 * i + j] = r[3 * i] * m[j] + r[3 * i + 1] * m[3 + j] + r[3 * i + 2] * m[6 + j];
    std::copy(o, o + 9, r);
}

}  // namespace

bool LoadPhysicsConstants(const char* path) {
    FILE* f = std::fopen(path, "r");
    if (!f) return false;
    int version = 0, rows = 0;
    bool ok = std::fscanf(f, "%d %d", &version, &rows) == 2 && rows > 0 && rows <= 24;
    for (int i = 0; ok && i < rows; ++i)
        for (float& v : g_materials[i].v) ok = ok && std::fscanf(f, "%f", &v) == 1;
    std::fclose(f);
    g_materials_loaded = ok;
    return ok;
}

const Material* PhysicsConstants(int type) {
    return g_materials_loaded && type >= 0 && type < 24 ? &g_materials[type] : nullptr;
}

void RigidBody::Setup(const std::vector<Vec3>& vertices, float scale, float m, const Material& mat,
                      bool on, const float r[9], const Vec3& at) {
    // sub_759E40: mass and material.
    mass = m;
    buoyancy = mat.v[0];
    stiffness = m * mat.v[1];
    damping = m * mat.v[2];
    friction = mat.v[3];
    spin_kept = std::pow(mat.v[4], kSubstep);
    drag = mat.v[5];
    enabled = on;
    ang_mom = vel = Vec3{};
    speed = 0;

    // sub_75A110: the points about the vertices' average, scaled; the radius
    // is the farthest.
    centroid = Vec3{};
    for (const Vec3& v : vertices) { centroid.x += v.x; centroid.y += v.y; centroid.z += v.z; }
    const float inv_n = vertices.empty() ? 0.0f : 1.0f / static_cast<float>(vertices.size());
    centroid = {centroid.x * inv_n, centroid.y * inv_n, centroid.z * inv_n};
    points.assign(vertices.size(), Point{});
    radius = 0;
    for (size_t i = 0; i < vertices.size(); ++i) {
        Point& p = points[i];
        p.local = {(vertices[i].x - centroid.x) * scale, (vertices[i].y - centroid.y) * scale,
                   (vertices[i].z - centroid.z) * scale};
        radius = std::max(radius, Len(p.local));
    }
    // sub_759DB0: the rest counter starts at minus the radius in mm.
    // ponytail: v1.0 uses the mesh's own radius (+40) x scale; ours is the
    // farthest point, the same for a mesh whose radius is its extent.
    age = -static_cast<int>(radius * 1000.0f);

    // sub_759EB0: ext force and torque cleared; the inertia from the points,
    // each mass / n. Element [5] (+28) takes -xz, not -yz: the original's.
    ext_force = ext_torque = Vec3{};
    std::fill(inertia, inertia + 9, 0.0f);
    if (enabled && !points.empty()) {
        const float w = mass / static_cast<float>(points.size());
        for (Point& p : points) {
            const Vec3& l = p.local;
            p.rest = p.lever = Len(l);
            inertia[0] += (l.y * l.y + l.z * l.z) * w;
            inertia[1] -= l.y * l.x * w;
            inertia[3] -= l.y * l.x * w;
            inertia[4] += (l.x * l.x + l.z * l.z) * w;
            inertia[2] -= l.x * l.z * w;
            inertia[6] -= l.x * l.z * w;
            inertia[8] += (l.x * l.x + l.y * l.y) * w;
            inertia[5] -= l.x * l.z * w;
            inertia[7] -= l.y * l.z * w;
        }
        float a[12] = {};
        std::copy(inertia, inertia + 9, a);
        Inverse(inv_inertia, a);
        drag = radius * drag * radius * 0.3f;
    } else {
        for (Point& p : points) p.rest = p.lever = Len(p.local);
        std::fill(inertia, inertia + 9, 0.0f);
        std::fill(inv_inertia, inv_inertia + 12, 0.0f);
        inertia[0] = inertia[4] = inertia[8] = 1.0f;
        inv_inertia[0] = inv_inertia[4] = inv_inertia[8] = 1.0f;
    }
    floating = touching = false;
    fresh = true;

    // sub_75AD90: the object's orientation, rows made unit; the centre is the
    // object's position plus the (scaled) average; the points placed.
    std::copy(r, r + 9, rows);
    pos = ToWorld(rows, {centroid.x * scale, centroid.y * scale, centroid.z * scale}, at);
    for (int i = 0; i < 3; ++i) {
        float* row = rows + 3 * i;
        const float l = std::sqrt(row[0] * row[0] + row[1] * row[1] + row[2] * row[2]);
        if (l != 0.0f) { row[0] /= l; row[1] /= l; row[2] /= l; }
    }
    for (Point& p : points) {
        p.pred = p.contact = ToWorld(rows, p.local, pos);
        p.prev_depth = 0;
        p.depth = 0;
    }
}

void RigidBody::Predict() {
    touching = false;
    if (asleep) {
        pred_centre = pos;
        force = torque = Vec3{};
        return;
    }
    // Everything is looked at where it will be 60 ms on.
    const Vec3 d{vel.x * 0.06f, vel.y * 0.06f, vel.z * 0.06f};
    for (Point& p : points) {
        p.pred = ToWorld(rows, p.local, pos);
        p.pred = {p.pred.x + d.x, p.pred.y + d.y, p.pred.z + d.z};
        p.lever = std::max(Len({p.pred.x - pos.x, p.pred.y - pos.y, p.pred.z - pos.z}), 0.001f);
    }
    pred_centre = {pos.x + d.x, pos.y + d.y, pos.z + d.z};
    // ponytail: the 36-byte triangle list (+356), turned here too, is not
    // kept: only body-to-body contacts read it.
    force = ext_force;
    torque = ext_torque;
}

void RigidBody::Forces() {
    if (asleep) {
        // ponytail: the branch for a body resting on another (+360) is not.
        for (Point& p : points) { p.contact = p.pred; p.depth = 0; }
        return;
    }
    const float dk = -(speed * drag);
    force = {force.x + dk * vel.x, force.y + dk * vel.y, force.z + dk * vel.z};
    contacts = 0;
    force.y -= mass * 9.81f;

    // The sea: the land under the centre is at 0 and the centre is less than
    // a radius up. ponytail: v1.0 also asks whether the first point's cell
    // is landscape with a non-zero altitude (the block table at 0xD73794);
    // a land height of 0 stands in for it.
    if (LandHeight(pos.x, pos.z) < 0.0001f && pos.y < radius) {
        int under = 0;
        for (const Point& p : points) under += p.pred.y < 0.0f;
        if (under) {
            floating = touching = true;
            const float frac = std::min((radius - pos.y) / (radius + radius), 1.0f);
            buoyancy += 0.000066666667f;  // it takes on water
            const float up = frac * mass * 9.81f / buoyancy;
            const float wd = frac * speed * drag * 100.0f;
            const Vec3 f{-wd * vel.x, up - wd * vel.y, -wd * vel.z};
            force = {force.x + f.x, force.y + f.y, force.z + f.z};
            const float s = 0.02f / static_cast<float>(under);
            const Vec3 fp{f.x * s, f.y * s, f.z * s};
            for (Point& p : points) {
                p.contact = p.pred;
                p.depth = 0;
                if (p.pred.y < 0.0f)
                    AddTorque(torque, {p.pred.x - pred_centre.x, p.pred.y - pred_centre.y, p.pred.z - pred_centre.z}, fp);
            }
            return;
        }
        floating = false;
    }
    // The land: each predicted point under it is a contact at the land's
    // height, with the land's normal there.
    for (Point& p : points) {
        const float h = LandHeight(p.pred.x, p.pred.z);
        p.depth = h - p.pred.y;
        p.other = nullptr;
        p.contact = p.pred;
        if (p.depth < 0.0f) continue;
        ++contacts;
        p.normal = LandNormal(p.pred.x, p.pred.z);
        p.contact.y = h;
        touching = true;
    }
}

void RigidBody::Contacts() {
    age += 5;
    fresh = false;
    if (!contacts) return;
    for (Point& p : points) {
        if (p.depth <= 0.0f) {
            p.anchor = p.contact;
            p.prev_depth = 0;
            continue;
        }
        // ponytail: contacts with another body (+76: the lesser of the two
        // materials, friction x 0.3, and the reaction on it) wait on the
        // game layer's collisions.
        const float k = stiffness, c = damping, mu = friction;
        float fn;
        if (p.prev_depth == 0.0f) {
            p.prev_depth = p.depth;
            fn = p.depth * k;
        } else {
            fn = c * (p.lever / p.rest * ((p.depth - p.prev_depth) * 200.0f)) + k * p.prev_depth;
        }
        fn = std::max(fn, 0.0f);
        const float fmax = fn * mu;
        Vec3 n{p.normal.x * fn, p.normal.y * fn, p.normal.z * fn};
        // Friction: a spring to where the point first touched, which slips
        // when it pulls harder than the normal force allows.
        Vec3 t{(p.anchor.x - p.contact.x) * k, (p.anchor.y - p.contact.y) * k, (p.anchor.z - p.contact.z) * k};
        const float t2 = t.x * t.x + t.y * t.y + t.z * t.z;
        if (t2 > fmax * fmax) {
            const float s = fmax / std::sqrt(t2);
            t = {t.x * s, t.y * s, t.z * s};
            p.anchor = {p.contact.x + t.x / k, p.contact.y + t.y / k, p.contact.z + t.z / k};
        }
        n = {n.x + t.x, n.y + t.y, n.z + t.z};
        p.normal = n;  // the original keeps the point's force in the normal's slot
        force = {force.x + n.x, force.y + n.y, force.z + n.z};
        AddTorque(torque, {p.pred.x - pred_centre.x, p.pred.y - pred_centre.y, p.pred.z - pred_centre.z}, n);
    }
}

int RigidBody::Integrate() {
    if (!enabled || (asleep && !touching)) return 0;
    if (radius * -4.0f > pos.y) return 4;

    // Spin: the angular momentum takes the torque and keeps spin_kept of
    // itself; to the body, through the inverse inertia, back to the world.
    ang_mom = {(ang_mom.x + torque.x * kSubstep) * spin_kept, (ang_mom.y + torque.y * kSubstep) * spin_kept,
               (ang_mom.z + torque.z * kSubstep) * spin_kept};
    const Vec3 lb{rows[0] * ang_mom.x + rows[1] * ang_mom.y + rows[2] * ang_mom.z,
                  rows[3] * ang_mom.x + rows[4] * ang_mom.y + rows[5] * ang_mom.z,
                  rows[6] * ang_mom.x + rows[7] * ang_mom.y + rows[8] * ang_mom.z};
    const float* I = inv_inertia;
    Vec3 wb{lb.x * I[0] + lb.y * I[3] + lb.z * I[6], lb.x * I[1] + lb.y * I[4] + lb.z * I[7],
            lb.x * I[2] + lb.y * I[5] + lb.z * I[8]};
    const float w2 = wb.x * wb.x + wb.y * wb.y + wb.z * wb.z;
    if (w2 > kMaxSpin * kMaxSpin && (wb.x != 0 || wb.y != 0 || wb.z != 0)) {
        const float s = kMaxSpin / std::sqrt(w2);
        wb = {wb.x * s, wb.y * s, wb.z * s};
    }
    const Vec3 ww = ToWorld(rows, wb, {});

    vel = {vel.x + force.x / mass * kSubstep, vel.y + force.y / mass * kSubstep, vel.z + force.z / mass * kSubstep};
    speed = Len(vel);
    if (speed > kMaxSpeed) {
        const float s = kMaxSpeed / speed;
        vel = {vel.x * s, vel.y * s, vel.z * s};
        speed = kMaxSpeed;
    }

    // Coming to rest: touching, slow, hardly turning and hardly pushed to
    // turn. The bar starts at 1 and rises after 75 s of motion (age 15000).
    const float bar = asleep ? 4.0f : (age <= 15000 ? 1.0f : static_cast<float>(age) * 0.000066666667f);
    const float bar2 = bar * bar;
    if (contacts && speed < bar && w2 < bar2 * 0.25f) {
        const float k = 1.0f / (radius * radius * mass);
        const Vec3 aa{torque.x * k, torque.y * k, torque.z * k};
        if (aa.x * aa.x + aa.y * aa.y + aa.z * aa.z < bar2) {
            if (asleep || age > 0) {
                vel = ang_mom = Vec3{};
                speed = 0;
                return asleep ? 0 : 2;
            }
        }
    }

    const Vec3 th{ww.x * kSubstep, ww.y * kSubstep, ww.z * kSubstep};
    const float angle = Len(th);
    if (angle > 0.0000099999997f) {
        float m[9];
        AxisAngle(m, {th.x / angle, th.y / angle, th.z / angle}, angle);
        MulRows(rows, m);
    }
    pos = {pos.x + vel.x * kSubstep, pos.y + vel.y * kSubstep, pos.z + vel.z * kSubstep};
    return asleep ? 3 : 1;
}

int RigidBody::Step() {
    Predict();
    Forces();
    Contacts();
    return Integrate();
}

}  // namespace physics
