#pragma once
// GBelief — villager/town belief system data
// Struct layout from bw1-decomp
//
// Size: 0x1D0 bytes (inherits 0x8 from Base)
// Tracks belief in each player and boredom multipliers.

#include "Base.h"

// Forward declarations
struct GPlayer;

// Maximum players tracked (8 player slots)
static constexpr int BELIEF_MAX_PLAYERS = 8;
// Number of reaction function types (NUM_REACTION_FUNCTIONS = 41)
static constexpr int NUM_REACTION_FUNCTIONS = 41;

struct GBelief : public Base {
    // === Static methods ===
    static float DistanceChangeToBelief(float param1, float param2);  // 0x00438770

    // === Non-virtual methods ===
    float GetBeliefInPlayer(unsigned long index);                     // 0x00437e70
    void SetBelief(unsigned long index, float value);                 // 0x004387d0
    void SetBeliefInPlayerCap(GPlayer* player, float cap);            // 0x00438a00

    // === Fields ===
    float    belief_in_player[BELIEF_MAX_PLAYERS];      // 0x08
    uint32_t field_0x28[BELIEF_MAX_PLAYERS];             // 0x28
    float    field_0x48[BELIEF_MAX_PLAYERS];             // 0x48
    float    belief_in_player_max[BELIEF_MAX_PLAYERS];   // 0x68
    uint32_t field_0x88[BELIEF_MAX_PLAYERS];             // 0x88
    float    field_0xa8[BELIEF_MAX_PLAYERS];             // 0xA8
    float    field_0xc8[BELIEF_MAX_PLAYERS];             // 0xC8
    float    boredom_multiplier[NUM_REACTION_FUNCTIONS]; // 0xE8
    float    field_0x18c[0x11];                          // 0x18C
};
static_assert(sizeof(GBelief) == 0x1D0, "GBelief size mismatch");
