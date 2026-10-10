#pragma once
// PhysicsObject -- one object under physics, and the pool of them (v1.0's
// growable array of 476-byte entries at 0xC685BC; game layer 0x5F2CE0..
// 0x5F5D00). docs/physics.md.
//
// The vendor's opaque 0x1DC layout is replaced by named fields: the
// arithmetic is the original's, the storage is ours (offsets in brackets).
#include "RigidBody.h"

#include <cstdint>
#include <vector>

struct Object;
struct GInterfaceStatus;

struct PhysicsObject {
    physics::Vec3 impulse;           // [12] forces summed over touching substeps
    Object*  object = nullptr;       // [24]
    Object*  thrower = nullptr;      // [28]
    PhysicsObject* hit = nullptr;    // [32] the entry it hit this turn
    GInterfaceStatus* status = nullptr;  // [36] the hand that threw it (sub_5F30F0's a5)
    float    strength = 0;           // [8] |impulse| x 0.05
    physics::RigidBody body;         // [40]; [412] resting is body.asleep
    int32_t  villager = 0;           // [420] 1 for a Villager
    uint32_t flags = 1;              // [472] bit 0 kept this turn, bit 1 passes through villagers,
                                     // bit 4 checks no bodies, bit 7 always kept
};

namespace physics {

// sub_5F30F0: the object flies with velocity `vel` (clamped to 124 m/s) and
// spin `spin` (body axes). Not for an object that cannot become physical
// (vslot 492) or whose +0x25 bit 0x10 is set; an object already in the pool
// is restarted only when resting. Returns its entry or nullptr.
PhysicsObject* Throw(Object* object, const Vec3& vel, const Vec3& spin, Object* thrower, GInterfaceStatus* status);
// sub_5F3B40: the object joins at rest (disturbed by something moving).
PhysicsObject* AddResting(Object* object);
// sub_5F3D10: one game turn, 20 substeps of 5 ms.
void Step();
// The entry for an object, or nullptr.
PhysicsObject* Find(const Object* object);
const std::vector<PhysicsObject*>& Pool();
void ResetPool();  // sub_5F3000

}  // namespace physics
