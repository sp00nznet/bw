// Tiny audio shim — plays intro.wav for music start and MessageBeep variants
// for sound effects. Registered as the LHVM audio callback set so CHL scripts
// produce audible feedback even before the SAD bank parser is written.

#pragma once

#include <string>

namespace bw {
namespace audio {

// Initialise (preloads intro.wav from the supplied game-data directory if
// present). Safe to call once; subsequent calls are no-ops.
void Init(const std::string& game_data_dir);

// Register the LHVM audio callbacks. Call after Init().
void RegisterLHVMHooks();

// Stop everything currently playing (called on shutdown).
void Shutdown();

} // namespace audio
} // namespace bw
