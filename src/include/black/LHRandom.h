#pragma once
// The game's random number generator, v1.0 sub_746D10, with its two wrappers:
// sub_67BCF0 / sub_67BC90 (an int below n) and sub_67BD10 / sub_67BCB0 (a float
// below f). One seed, at game +2104056; every random choice in the simulation
// draws from it, so a run is repeatable from the seed.
#include <cstdint>

namespace lh {
extern uint32_t g_random_seed;  // game +2104056

inline uint32_t RandomRaw() {
    // seed = ror32(9377 * seed + 9439, 13)
    const uint32_t v = 9377u * g_random_seed + 9439u;
    g_random_seed = (v >> 13) | (v << 19);
    return g_random_seed;
}
inline uint32_t Random(uint32_t n) { return n ? RandomRaw() % n : 0; }                    // sub_67BCF0
inline float RandomFloat(float f) {                                                          // sub_67BD10
    return f == 0.0f ? 0.0f : static_cast<float>(Random(0xFFFF)) * f * 0.000015259022f;
}
}  // namespace lh
