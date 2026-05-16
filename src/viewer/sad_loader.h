// sad_loader — Lionhead SAD audio bank decoder.
//
// SAD files are LiOnHeAd Pack archives containing three blocks:
//   * LHFileSegmentBankInfo  — bank name/description (one record)
//   * LHAudioWaveData        — concatenated WAV files (RIFF chunks)
//   * LHAudioBankSampleTable — u32 count + N AudioBankSampleHeader[640]
//
// Each sample header includes:
//   * full path/name (256 chars) — usually like
//     "C:\\Dialogue\\<bank>\\<rate>\\HELP_TEXT_<KEY>_<N>.wav"
//   * the id, offset, and size of the WAV inside LHAudioWaveData
//   * sample rate and other audio metadata
//
// LoadSAD pulls every sample out and registers it for playback +
// optionally a friendly subtitle key.

#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace bw {
namespace sad {

struct SADSample {
    int32_t           id;
    std::string       name;          // raw sample name, eg. ".../HELP_TEXT_..._06.wav"
    std::string       help_key;      // extracted HELP_TEXT_... key (empty if none)
    std::vector<uint8_t> wav_bytes;  // full RIFF/WAVE buffer ready for playback
    uint32_t          sample_rate;
    bool              is_pcm;        // true if PCM, false for MPEG-encoded
};

// Parse a single SAD file. Appends discovered samples to the global
// registry. Returns the number of samples extracted.
size_t LoadSAD(const std::string& path);

// Look up a sample by integer id. Returns nullptr if unknown.
const SADSample* SampleById(int32_t id);

// Iterate registry slots. Index must be < Count().
const SADSample* SampleByIndex(uint32_t idx);

// Look up a sample by HELP_TEXT_* key (e.g. "DEATH_IN_VILLAGE"). Returns
// the first match. Returns nullptr if unknown.
const SADSample* SampleByHelpKey(const std::string& key);

// Total samples loaded so far.
size_t Count();

// Play a sample by id using Win32 PlaySound (memory variant). Returns
// true if the sample was found AND looked playable (PCM); false otherwise.
bool Play(int32_t id);

// Auto-discover and load every .sad file under the given directory tree.
// Returns total samples found.
size_t LoadAllUnder(const std::string& root_dir);

} // namespace sad
} // namespace bw
