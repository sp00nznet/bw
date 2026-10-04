// Gesture — v1.0's gesture recognizer (GestureSystem / GestureSystemData).
//
// A stroke drawn with the hand is kept as a trail of up to 80 screen points
// (sub_546890). As each point arrives the trail marks corners where the
// stroke turns (sub_546FC0); each corner keeps the heading of the segment it
// starts, that heading's octant, and the turn from the previous segment. The
// start, corners and end make a GestureSystemData (sub_545360), compared turn
// by turn against the 81 templates in Data/Gestures.jty (sub_545D70).
// docs/gestures.md.
#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace gesture {

// 20 bytes, as stored in Gestures.jty and in the trail.
struct Point {
    float   x;       // screen x (templates: 0..1)
    float   pad;
    float   y;       // screen y (templates: 0..1)
    float   turn;    // the turn at this point, radians in (-pi, pi]
    int32_t octant;  // octant 0..7 of the heading of the segment starting here
};
static_assert(sizeof(Point) == 20, "gesture::Point is 20 bytes");

// GestureSystemData (1628 bytes in v1.0; the fields that matter).
struct Data {
    Point    pts[80] = {};
    uint8_t  count = 0;         // +1608
    uint8_t  id = 0;            // +1609: the gesture this template is
    float    aspect = 0;        // +1612: width / height
    uint32_t check_octant = 0;  // +1616: the first segment's octant must agree
    uint32_t mirror_ok = 0;     // +1620: may also match mirrored
    uint32_t check_size = 0;    // +1624: the aspect band must agree

    void Finish(float screen_ratio);  // sub_545570: the aspect
};

struct Result {
    uint8_t id = 0;
    bool    mirrored = false;
    uint8_t start = 0, end = 0;  // the input points matched
    uint8_t index = 0;           // the template
};

// The templates (Data/Gestures.jty, loaded by sub_545AC0).
struct Templates {
    std::vector<Data> all;
    bool Load(const std::string& path);
    // sub_545D70: does `input` match any template of gesture `id`?
    bool Match(uint8_t id, const Data& input, float screen_ratio, Result* out) const;
};

// The trail the hand draws (GestureSystem +2408744 in v1.0).
struct Trail {
    struct Entry {
        Point    pt;
        float    world[3];
        uint32_t flag;     // 1 start, 2 corner, 4 key, 8 end
        float    heading;  // of the segment starting here, [0, 2pi)
    };
    static_assert(sizeof(Entry) == 40, "trail entries are 40 bytes");

    Entry    ring[80] = {};
    uint8_t  count = 0;   // +3208
    uint32_t still = 0;   // +3212: turns the hand has not moved
    uint8_t  head = 0;    // +3216: the next slot

    void Clear();
    void Add(float sx, float sy, const float world[3] = nullptr);  // sub_546890
    Data ToData(float screen_ratio) const;                         // sub_545360

    // Internals, named after the original functions.
    Entry& At(int i);
    const Entry& At(int i) const;
    void Process(int n);                // sub_546FC0
    int  LastKey(int n) const;          // sub_5469E0
    int  LastCorner(int n) const;       // sub_546D70
    int  FarBack(int n) const;          // sub_546A40
    int  FindCorner(int k, int n);      // sub_546BB0
    bool MergeCorner(int c, int n);     // sub_546DD0
    bool LongEnough(int a, int c, const Point& p1, const Point& p2) const;  // sub_5471A0
    void Heading(int c);                // sub_5472B0
    void TurnAt(int p);                 // sub_5473C0
};

// The recognizer's angles (v1.0 initialisers at 0x545C50 / 0x5467A0).
constexpr float kPi = 3.1415927f;
constexpr float kCornerTurn = 0.39269909f * 3.0f * 0.25f;  // flt_C27628: a turn this sharp is a corner
constexpr float kSkipTurn = kCornerTurn * 7.0f * 0.25f;    // flt_C275EC: turns below this may be skipped
constexpr float kMaxDrift = kCornerTurn * 2.0f;            // flt_C275E8: the most the turns may disagree

float Heading(const Point& a, const Point& b);  // sub_746D50: atan2 in [0, 2pi)
float AngleDiff(float a, float b);              // sub_544FD0: b - a in (-pi, pi]
int   Octant(float heading);                    // sub_544F80

}  // namespace gesture
