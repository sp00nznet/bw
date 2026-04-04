#pragma once
// Zoomer / Zoomer3d — smooth interpolation primitives from lh3dlib
// Struct layout from bw1-decomp (lionhead/lh3dlib/development/Zoomer.h)
//
// Zoomer:   0x30 bytes — single-axis smooth cubic Hermite interpolation
// Zoomer3d: 0x90 bytes — three-axis smooth interpolation

#include "types.h"

struct Zoomer {
    float    current_value;            // 0x00
    float    destination;              // 0x04
    float    destination_speed;        // 0x08
    float    current_speed;            // 0x0C
    float    time_m2;                  // 0x10
    float    current_time;             // 0x14
    float    duration;                 // 0x18
    float    start_value;              // 0x1C
    float    start_speed;              // 0x20
    LHPoint  non_linear_acceleration;  // 0x24

    // Methods
    void SetPosition(float position);                                    // 0x00441ac0
    void SetDestination(float dest);                                     // inlined
    float GetCurrentValue() const;                                       // inlined
    float GetDestination() const;                                        // inlined
    void SetDestinationWithSpeedAndTime(float dest, float speed, float time); // 0x00407d60
    void Update(float dt);                                               // 0x00442720
};
static_assert(sizeof(Zoomer) == 0x30, "Zoomer size mismatch");

struct Zoomer3d {
    Zoomer x;  // 0x00
    Zoomer y;  // 0x30
    Zoomer z;  // 0x60

    // Methods
    LHPoint GetCurrentValue() const;                                     // 0x004605d0
    LHPoint GetDestination() const;                                      // inlined
    void SetPosition(const LHPoint& pos);                                // inlined
    void SetDestinationWithSpeedAndTime(const LHPoint& dest, float speed, float time); // inlined
    void SetDestinationWithTime(const LHPoint& dest, float time);        // 0x0044e760
    void Update(float dt);                                               // inlined
};
static_assert(sizeof(Zoomer3d) == 0x90, "Zoomer3d size mismatch");
