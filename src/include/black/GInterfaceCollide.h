#pragma once
#include "Base.h"
#include "MapCoords.h"

struct Bubble;
struct Leash;
struct Object;

struct GInterfaceCollide : public Base {
    MapCoords pos;             // 0x08
    float     pos_distance;    // 0x14
    Object*   object;          // 0x18
    float     object_distance; // 0x1C
    Bubble*   bubble;          // 0x20
    float     bubble_distance; // 0x24
    Leash*    leash;           // 0x28
    float     leash_distance;  // 0x2C
};
static_assert(sizeof(GInterfaceCollide) == 0x30, "GInterfaceCollide size mismatch");
