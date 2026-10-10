#pragma once
// One rigid body of v1.0's physics (the 384-byte body at PhysicsObject +40,
// functions 0x759D60..0x75C860). docs/physics.md maps it.
//
// The arithmetic is the original's; the storage is ours (named fields, no
// asserted layout). The original takes its points from the object's mesh
// (sub_75A110: the vertices of the physics submeshes, flag 0x2000, else
// 0x20000000); bw_core has no meshes, so the caller hands the vertices in.
//
// Conventions kept from the original: an orientation's rows are the body's
// axes in the world, a body point goes to the world as local x row0 + y row1
// + z row2 + position, and positions are metres with y up.
#include <vector>

namespace physics {

struct Vec3 { float x = 0, y = 0, z = 0; };

// PhysicsConstants.txt: 24 rows of six numbers (v1.0's table at 0xBE7840,
// 24 bytes a row, picked by the object's vslot 482). Columns as
// sub_759E40 uses them: [0] buoyancy divisor, [1] contact stiffness per kg,
// [2] contact damping per kg, [3] friction, [4] spin kept per second, [5] drag.
struct Material { float v[6] = {}; };
bool LoadPhysicsConstants(const char* path);
const Material* PhysicsConstants(int type);  // nullptr when not loaded / out of range

struct RigidBody {
    // 80 bytes each in the original (offsets in brackets).
    struct Point {
        float prev_depth = 0;   // [0] depth at first contact; 0 when free
        Vec3  anchor;           // [4] friction anchor on the ground
        Vec3  local;            // [16] body space, centred and scaled
        float rest = 0;         // [28] |local|
        float lever = 0;        // [32] |predicted - centre|, at least 0.001
        float depth = 0;        // [36] land height - predicted y (> 0: under)
        Vec3  contact;          // [40]
        Vec3  pred;             // [52] predicted world position
        Vec3  normal;           // [64] the land's normal at the contact
        RigidBody* other = nullptr;  // [76] the body touched (land: none)
    };
    // 36 bytes each: a face of the mesh (indices into points) and its unit
    // normal, (b - a) x (c - a), in the body [12] and in the world [24].
    struct Tri {
        int  i[3] = {};
        Vec3 local_n;
        Vec3 n;
    };

    // sub_759DB0 + sub_759E40 + sub_75A110 + sub_759EB0 + sub_75AD90.
    // rows: orientation (3 rows of 3); pos: the object's position; faces:
    // index triples into vertices (the mesh's triangles).
    void Setup(const std::vector<Vec3>& vertices, float scale, float mass, const Material& m,
               bool enabled, const float rows[9], const Vec3& pos, const std::vector<int>& faces = {});

    // sub_75C060, run between Forces and Contacts: each predicted point
    // inside the other's bounding sphere, cast from the centre through it
    // onto the other's faces, becomes a contact with the other body.
    void Collide(RigidBody& other);
    // sub_75A5B0: the nearest face crossed going back from p along dir
    // (p + s dir, -1 < s < 0) whose normal faces dir; false when none.
    bool Cast(const Vec3& p, const Vec3& dir, Vec3& at, Vec3& normal) const;

    // One substep: the four passes in the original's order. Returns
    // sub_75C860's code: 0 still/asleep, 1 moved, 2 came to rest, 3 moved
    // while asleep, 4 sank (more than 4 radii under the sea).
    int Step();

    void Predict();    // sub_75B830
    void Forces();     // sub_75BAD0
    void Contacts();   // sub_75C440
    int  Integrate();  // sub_75C860

    std::vector<Point> points;
    std::vector<Tri> tris;      // +352 / +356
    float inertia[9] = {};      // +8
    float inv_inertia[12] = {}; // +56 (3x3 and a translation, sub_759970)
    Vec3  ang_mom;              // +104
    bool  enabled = false;      // +116
    RigidBody* hit = nullptr;   // +120 the last body touched (cleared each turn)
    float rows[9] = {1, 0, 0, 0, 1, 0, 0, 0, 1};  // +124 orientation
    Vec3  pos;                  // +160 centre of mass
    Vec3  vel;                  // +220
    Vec3  pred_centre;          // +232
    float speed = 0;            // +244
    Vec3  centroid;             // +248 (body space, before scaling)
    Vec3  force, torque;        // +260, +272
    Vec3  ext_force, ext_torque;  // +284, +296
    float mass = 1;             // +308
    float buoyancy = 1;         // +312: grows while floating, so things sink
    float stiffness = 0;        // +316
    float damping = 0;          // +320
    float friction = 0;         // +324
    float spin_kept = 1;        // +328 per substep
    float drag = 0;             // +332
    float radius = 0;           // +336
    int   contacts = 0;         // +344
    int   age = 0;              // +368: +5 a substep, from -(radius in mm)
    bool  asleep = false;       // +372
    bool  fresh = false;        // +373
    bool  touching = false;     // +374
    bool  floating = false;     // +375
};

// The 1 m box bodies take when the host has no mesh: corner i at
// (bit 0, bit 1, bit 2) -> -0.5 / +0.5, twelve faces wound outward.
void UnitBox(std::vector<Vec3>& vertices, std::vector<int>& faces);

constexpr float kSubstep = 0.005f;      // 200 a second
constexpr float kMaxSpeed = 124.0f;     // flt_B59340
constexpr float kMaxSpin = 9.424778f;   // flt_8D8948 (3 pi), squared at 0xD70F58

}  // namespace physics
