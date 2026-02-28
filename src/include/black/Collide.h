#pragma once
// Collide — collision detection types
// Struct layout from bw1-decomp (Collide.h)
//
// Plain data types for the spatial collision system:
//   ObjectCircleIteratorDirection enum
//   Point2DCompare (0xC), IntersectIntervalCircle (0x2C),
//   CircleHugInfo (0x8), Q210NewCollide4List (0xC),
//   ObjectCircleIterator (0x10), Q210NewCollide3Obj (0x28),
//   NewCollide (0x4), NewCollideDescriptor (0x24)

#include "types.h"

// Forward declarations
struct MapCell;
struct MapCoords;
struct MobileWallHug;
struct NewCollide;
struct Object;
struct Q210NewCollide3Obj;
struct Game3DObject;
struct LH3DObject;

enum ObjectCircleIteratorDirection : uint32_t {
    OBJECT_CIRCLE_ITERATOR_DIRECTION_SAME       = 0x0,
    OBJECT_CIRCLE_ITERATOR_DIRECTION_RIGHT      = 0x1,
    OBJECT_CIRCLE_ITERATOR_DIRECTION_LEFT       = 0x2,
    OBJECT_CIRCLE_ITERATOR_DIRECTION_DOWN       = 0x3,
    OBJECT_CIRCLE_ITERATOR_DIRECTION_UP         = 0x4,
    OBJECT_CIRCLE_ITERATOR_DIRECTION_UP_LEFT    = 0x5,
    OBJECT_CIRCLE_ITERATOR_DIRECTION_DOWN_LEFT  = 0x6,
    OBJECT_CIRCLE_ITERATOR_DIRECTION_UP_RIGHT   = 0x7,
    OBJECT_CIRCLE_ITERATOR_DIRECTION_DOWN_RIGHT = 0x8,
    OBJECT_CIRCLE_ITERATOR_DIRECTION_NONE       = 0x9,
};

struct Point2DCompare {
    Point2D  point;   // 0x0
    bool     result;  // 0x8
};
static_assert(sizeof(Point2DCompare) == 0xC, "Point2DCompare size mismatch");

struct IntersectIntervalCircle {
    Point2DCompare         compares[2];  // 0x00
    float                  field_0x18;   // 0x18
    float                  field_0x1c;   // 0x1C
    float                  field_0x20;   // 0x20
    bool                   field_0x24;   // 0x24
    Q210NewCollide3Obj*    obj;          // 0x28
};
static_assert(sizeof(IntersectIntervalCircle) == 0x2C, "IntersectIntervalCircle size mismatch");

struct CircleHugInfo {
    Q210NewCollide3Obj*  obj;           // 0x0
    uint8_t              turns_to_obj;  // 0x4
    uint8_t              field_0x5;     // 0x5
    int16_t              field_0x6;     // 0x6
};
static_assert(sizeof(CircleHugInfo) == 0x8, "CircleHugInfo size mismatch");

struct Q210NewCollide4List {
    uint32_t                        size;       // 0x0
    ObjectCircleIteratorDirection   direction;  // 0x4
    Q210NewCollide3Obj**            objs;       // 0x8
};
static_assert(sizeof(Q210NewCollide4List) == 0xC, "Q210NewCollide4List size mismatch");

struct ObjectCircleIterator {
    ObjectCircleIteratorDirection  direction;    // 0x0
    NewCollide*                   collide_data;  // 0x4
    Q210NewCollide3Obj*           collide_obj;   // 0x8
    Object*                       obj;           // 0xC
};
static_assert(sizeof(ObjectCircleIterator) == 0x10, "ObjectCircleIterator size mismatch");

struct Q210NewCollide3Obj {
    LHPoint               position;      // 0x00
    float                 radius;        // 0x0C
    float                 r2;            // 0x10
    float                 angle;         // 0x14
    LHPoint               bounding_box;  // 0x18
    Q210NewCollide4List*  iterator_list; // 0x24
};
static_assert(sizeof(Q210NewCollide3Obj) == 0x28, "Q210NewCollide3Obj size mismatch");

struct NewCollide {
    Q210NewCollide3Obj*  obj;  // 0x0
};
static_assert(sizeof(NewCollide) == 0x4, "NewCollide size mismatch");

struct NewCollideDescriptor {
    uint32_t  count;       // 0x00
    int       min_x;       // 0x04
    int       max_x;       // 0x08
    int       min_z;       // 0x0C
    int       max_z;       // 0x10
    int       current_x;   // 0x14
    int       current_z;   // 0x18
    int       array_index; // 0x1C
    uint8_t*  array;       // 0x20
};
static_assert(sizeof(NewCollideDescriptor) == 0x24, "NewCollideDescriptor size mismatch");
