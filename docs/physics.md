# Physics

Thrown and dropped objects in v1.0 are simulated by a rigid-body engine. The rigid body
is translated (`black/RigidBody.h`, `core/RigidBody.cpp`, checked by `test_physics`); the
game layer is not yet: `PhysicsObject.h` is the vendor's opaque 0x1DC layout, and the
viewer still fakes flights (`GameState::ThrowEntity`, `game_loop.cpp`). This page maps the
original so the translation can go in phases. Dumps: `work/decomp/physics.txt` and
`work/decomp/rigidbody.txt` (gitignored; regenerate with `tools/decomp`).

## Two layers

| Layer | Range | Size | What it is |
|---|---|---|---|
| Game physics | `0x5F2CE0`..`0x5F5D00` | ~12 KB, 25 functions | The pool of `PhysicsObject`s, what is thrown, collisions with map objects, landing |
| Rigid body | `0x758FC0`..`0x75DF80` | ~20 KB, 52 functions | One body: contact points, forces, integration, the landscape and the sea |

## The pool

`PhysicsObject` (476 bytes, vtable `0x86ED64`, constructor `sub_5F3080`) lives in one
growable array: base `0xC685BC`, count `0xC685C0`, capacity `0xC685C4`, grown 16 at a
time by `sub_5F3990` (pointers into the array, at +32, are rebased when it moves).
`sub_5F3000` frees all of them.

| Offset | Field |
|---|---|
| +24 | the `Object` being simulated |
| +28 | who threw it (`sub_5F30F0`'s a4) |
| +36 | `sub_5F30F0`'s a5 |
| +40 | the rigid body (`sub_759DB0` sets it up with the object's mesh and scale) |
| +144..+152 | initial angular velocity, in body space |
| +260..+268 | initial velocity (`sub_5F30F0` a2), clamped to `flt_B59340` |
| +412 | resting (set by `sub_5F3B40`) |
| +420 | 1 when the object is a Villager |
| +472 | flags; bit 7 from the object's vslot 493 |

- `sub_5F30F0(object, velocity, spin, thrower, a5)`: the object becomes physical, unless
  vslot 492 says no or its +37 bit 0x10 is set. An existing entry for it is replaced
  only when resting. The body takes the object's position and orientation (vslot 483).
- `sub_5F3B40(object)`: the same, at rest, with no velocity (objects disturbed by a
  collision).
- `sub_5F3550`: one object's collisions. It walks the map cells under the body's bounds
  and wakes the objects there (vslot 489 decides; `sub_5F3B40`), then pushes
  overlapping bodies apart along ±y until none overlap by more than 0.001.
- `sub_5F3D10` (5.4 KB): the per-turn step over the pool, two callers.
- `sub_5F3C70(n)`: sets up to 15 substeps of a reference body (0xC67E30), running the
  four rigid-body passes 20 times each.

## The rigid body (at PhysicsObject +40)

| Offset | Field |
|---|---|
| +0 | the mesh / object the shape comes from |
| +4 | scale |
| +124..+156 | orientation (3×3) |
| +160..+168 | position, in metres |
| +220..+228 | velocity |
| +232..+240 | predicted position |
| +244, +332 | drag terms (force −(+244 × +332) × velocity) |
| +260..+268 | force accumulator; +272..+280 torque |
| +308 | mass (gravity is `mass × 9.81`) |
| +336 | sea level / float depth the buoyancy uses |
| +340, +348 | contact points: count and array (80 bytes each) |
| +352, +356 | second point list (36 bytes each) |
| +372 | asleep; +374 / +375 touching / floating this step |

The four passes, called in order each substep:

1. `sub_75B830`: predict. Each contact point to world (orientation × local + position)
   plus velocity × 0.06; the predicted centre likewise; reset force and torque.
2. `sub_75BAD0`: forces. Drag, gravity (−mass × 9.81 on y), then the sea: where the land
   height is under 0.0001 and the body is below +336, points under water push it up in
   proportion to depth; landscape contacts through `sub_760FD0` (land height) and
   `sub_761570`.
3. `sub_75C440`: contact response (restitution 0.3 from +324).
4. `sub_75C860`: integration (orientation renormalised, `sub_759860`).

`sub_75C360(body, normal)`: penetration depth along a normal (with `sub_7BBA10` or
`sub_75A940`); `sub_75AD90` re-orthonormalises the orientation; `sub_75B770` writes the
body's world matrix; `sub_759E40(mass, material, a4)` sets mass, friction and
restitution from a 24-byte material.

## What the translation found

- **Points come from the mesh** (`sub_75A110`): the vertices of the submeshes flagged
  0x2000 (else 0x20000000), centred on their average and scaled; the radius is the
  farthest. bw_core has no meshes, so `RigidBody::Setup` takes the vertices.
- **Materials** are `game_data/PhysicsConstants.txt` (version 3, 24 rows of six), the
  table at 0xBE7840 picked by the object's vslot 482: buoyancy divisor, stiffness and
  damping per kg, friction, spin kept per second (`pow(x, 0.005)` a substep), drag
  (× r² × 0.3).
- **The contact spring** is `k × d₀ + 200 c × (d − d₀) × lever/rest`, where d₀ is the
  depth at first contact (the point's +0, written only then) and d the depth now, 60 ms
  ahead. The disassembly confirms it. Friction is a spring to where the point first
  touched, slipping past `fn × friction`.
- **Coming to rest** (`sub_75C860` code 2) happens at the first slow moment while
  touching, once the age (−radius mm, +5 a substep) is positive. A box dropped 4.5 m
  on material 1 rests at the bottom of its landing, 0.6 m in; the game layer (case 2
  of `sub_5F3D10`) puts the object where the body is.
- **The sea** (land height 0 under the centre, centre less than a radius up): points
  under 0 lift the body by `depth share × weight / buoyancy`, and the divisor grows by
  1/15000 a substep, so a floating thing sinks; under −4 radii it is gone (code 4).
- **Inertia** element [5] takes −xz where −yz is meant: the original's slip, kept.
- **Not translated yet:** body-to-body contacts (+76, +356 triangles, `sub_75C360`),
  the land normal (`sub_761570` takes the cell's triangle; ours is a central
  difference), the sea's cell check (0xD73794) and the body resting on another (+360).

## Plan

1. ~~The rigid body~~ (done: `test_physics` drops a box on land and into the sea).
2. The pool and step (`sub_5F30F0`, `sub_5F3B40`, `sub_5F3D10`), with landing calling
   the object's impact virtuals.
3. Hooks: the hand's throw, the creature's `ThrowInPile` (the store actions), and
   objects landing on a store (`MultiMapFixed` resource taking).
