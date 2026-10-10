# Physics

Thrown and dropped objects in v1.0 are simulated by a rigid-body engine. The rigid body
(`black/RigidBody.h`, `core/RigidBody.cpp`) and the game layer (`black/PhysicsObject.h`,
`core/PhysicsObject.cpp`) are translated and run each game turn; `test_physics` and
`test_level` check them. This page maps the original and records what the translation
found. Dumps: `work/decomp/physics.txt` and
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
- **Bodies meet** (`sub_75C060`, between the forces and the contacts): each predicted
  point inside the other's bounding sphere is cast from this body's centre through the
  point (`sub_75A5B0`) onto the other's faces, the nearest face behind the point whose
  normal faces the cast and whose three edges hold the crossing. The crossing is the
  contact, the face's normal the normal, and the depth is how far the point is past it.
  A deeper hit than the land's takes the point, and unless both bodies sleep it marks
  both touching and each as the other's last hit (+120). The contact then uses the
  lesser stiffness, damping and friction of the two (friction × 0.3) and pushes the
  other body back (`sub_75C440`).
- **Faces** (+352 / +356, 36 bytes): the mesh's triangles as point indices, with the
  normal (b − a) × (c − a) made unit, in the body and turned to the world each predict.
- **+360 is dead**: only `sub_75AD90` writes it, always 0, so the "body on another"
  branches in `sub_75BAD0` and `sub_75C060` never run.
- **Not translated yet:** the land normal (`sub_761570` takes the cell's triangle; ours is
  a central difference), the sea's cell check (0xD73794), and `sub_75C360` (the
  joining body's push-up, `sub_5F3550`).

## The game layer (translated: `black/PhysicsObject.h`, `core/PhysicsObject.cpp`)

`PhysicsObject` now has named fields instead of the vendor's opaque block, and the pool
is a vector of them. `physics::Throw` is `sub_5F30F0`, `AddResting` is `sub_5F3B40`,
`Step` is `sub_5F3D10`:

1. Entries whose object is gone leave; a dead object (life under 0.01) takes 0.01 more
   water each turn.
2. Moving entries are kept; resting ones go unless the object always stays
   (vslot 493).
3. What lies in the map cells under each moving body (radius plus a tenth of a second of
   travel either way) and interacts (vslot 487) is kept, or joins at rest
   (`sub_5F3B40`); then entries not kept leave.
4. 20 substeps: predict and forces for all; each pair whose spheres meet collides
   (`sub_75C060`), unless the first checks no bodies (vslot 488, flag bit 4), both sleep
   and neither is new, a villager meets an entry with flag bit 1, or one threw the other;
   contacts for all; then each body
   integrates. A body low in the water with water taken on stops if the object sinks
   (vslot 494). Code 1 moves the object to the body (the centre less the turned point
   average); code 2 does that, calls `EndPhysics` (vslot 484) and puts the body to
   sleep; code 3 wakes it; code 4 (sunk) removes the object. While touching, the
   body's forces add to the entry's impulse.
5. A turn with an impulse over 1e-4 gives the entry a strength (|impulse| × 0.05), the
   entry of the body it last touched (+32; an entry nobody threw takes that one's hand),
   and calls the object's `ReactToPhysicsImpact` (vslot 491). A tree's (`sub_6DCB90`)
   hands it to a wood store it hit (vslots 416 / 417) with the hand's status.

Materials by object (vslot 482): a mobile object's records 17..19 are materials 21..23,
any other 1; an abode is 0. Weight (vslot 398, `sub_5EA850`) is scale³ × the record's
density (+172), at least 0.01. Points come from the host's `g_mesh_points_func`
(`Terrain.h`), else a 1 m box. In `test_physics` a mobile object thrown at 3 m/s
across and 4 up lands 2.8 m on and rests after 18 turns; one in the sea is gone after
23 s.

Which objects take part, from v1.0's tables: vslot 487 (woken) is Object's "has a 3D
object" (ours: true, as bw_core makes none), false for trees and fields, built over 0.1
and alive for a multi-map fixed; vslot 488 (its points checked) is true but for abodes;
vslot 492 (moves) is false for abodes. Bodies without a host mesh are the 1 m box with
its twelve faces; a host mesh brings points only, so it is not hit by others yet.

Not translated yet in this layer: turning the object with its body (`sub_759210` →
vslot 325), the splash and landing sound, the impact damage of a hard knock
(`sub_5F5240`), the creature's lessons from thrown objects (`sub_4CB260` kinds 15 and
16), and the mobile static's material choice (`sub_5C3FD0` calls the record's own
vtable). Sunk objects are marked unavailable rather than freed, as the store's take
does.

## In the game (phase 3, part 1)

- `level::Process` runs `physics::Step` after the magic pass, where v1.0's turn
  (`sub_5215E0`) calls `sub_5F3D10`; loading a level empties the pool.
- The land under the physics is v1.0's own (`LandHeight`, `Terrain.h`, from
  `sub_760FD0`): the cell corners' altitude bytes × 0.67 on the cell's triangle, the
  diagonal from byte +6 bit 7, corners at 3 or below as sea where the cell is at 4 or
  below. It needs the host's cell hooks and falls back to `GetTerrainHeightAt`.
- The viewer loads `PhysicsConstants.txt` beside info.dat, and its hand throw hands a
  core object to `physics::Throw` (with the hand's interface status, which the store
  path needs); the position sync then follows the core.
- **The viewer's land was mirrored.** Its mesh put the block grid's first index and a
  block's cell rows on z; v1.0 has them on x. Objects stood at their true positions on
  a transposed landscape (Land 1's first town had no land within 168 m). The mesh now
  follows v1.0's layout and cuts each cell along v1.0's diagonal, and the viewer's
  height is `LandHeight` once the cell hooks are in.

## Bodies meeting (phase 3, part 2)

Body-to-body contacts, the wake pass and the tree's impact are in. `test_level` drops a
Land 1 tree 4 m onto the first village's store: the store joins the pool at rest as the
tree nears, the tree meets its faces on the sixth turn, and the store takes it, 237 wood
(life 1 × record 350 × scale 0.68 × balance 1).

Next: the abode's own impact (`sub_4048D0`: a hard hit from something that destroys
abodes, `|impulse| × mass` over 2000, damages it; lesser ones make a sound), the
creature's `ThrowInPile`, and a faces hook for host meshes.

## Plan

1. ~~The rigid body~~ (done: `test_physics` drops a box on land and into the sea).
2. ~~The pool and step~~ (done, above).
3. Hooks: the hand's throw (done), objects landing on a store (done for trees), and the
   creature's `ThrowInPile` (the store actions).
