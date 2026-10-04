// Fire — v1.0's heat simulation (FireEffect, sub_6C4E30 .. sub_6C6940).
//
// A FireEffect hangs on an object (+0x44) holding its temperature. Each tick
// (sub_6C52A0) it heats towards twice the object's ignition point while it
// burns, or cools towards the air (24.7, faster wet); above ignition it burns
// the object's life away and heats what is near enough (sub_6C5C70), which
// may catch in turn. An effect's value [0] is heat (sub_6C6940): a fire
// spell's adds it, water's (-4000) takes it away. docs/fire.md.
#pragma once

#include <vector>

struct FireEffect;
struct GPlayer;
struct Object;

namespace fire {

constexpr float kAir = 24.7f;  // sub_5C18C0: the temperature everywhere

// The object's materials (its info): ignition point (+180, at least 40,
// sub_6C6470), heat capacity (+176, at least 1, vslot 377), burn rate (+144).
float Ignition(const Object* o);
float Capacity(const Object* o);
float BurnRate(const Object* o);
float Temperature(const Object* o);  // sub_5EBCD0: its fire's, else the air's

// sub_6C5020 + sub_6C4E30: a fire on the object, at its current temperature;
// the existing one if it has one; null if it cannot burn.
FireEffect* Ignite(Object* o, GPlayer* by);

// sub_6C6940: heat (an effect's value [0]) delivered to the object.
void AddHeat(Object* o, float heat, GPlayer* by);

// One turn of every fire (sub_6C6A30 -> sub_6C52A0). `nearby` is what fires
// may spread to.
// ponytail: v1.0 ticks the fires in rotating groups (FireEffect +0x30);
// here every fire ticks every turn.
void Process(const std::vector<Object*>& nearby);

int Count();  // fires burning now
void Clear();

}  // namespace fire
