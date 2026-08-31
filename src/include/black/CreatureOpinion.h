#pragma once
// CreatureOpinion — the scale a creature's likes and dislikes live on.
//
// Everything the creature learns ends up as one number: an opinion, on an
// eleven-point scale from -1.0 (hates it) through 0.0 (indifferent) to +1.0
// (loves it). A decision-tree leaf holds one of these, derived from the mean
// feedback weight of the learning episodes that reached it.
//
// Recovered from runblack_decrypted.exe (v1.0): sub_4B9410 averages a leaf's
// episode weights and then searches the table at flt_B0CDC0 for the level that
// mean falls within, and sub_4B9B80 is that membership test. The table was read
// out of .rdata rather than inferred -- the spacing is 0.2 with a +/-0.25
// tolerance, so the bands deliberately overlap, which changes the answer and
// would not have been guessable from the code alone.

#include <cstdint>

namespace creature {

// flt_B0CDC0[0..10]: -1.0 to +1.0 in steps of 0.2.
enum : int32_t {
    kOpinionLevels  = 11,
    // sub_4B9410 returns this when a leaf has no episodes anywhere up its
    // parent chain: the creature has no view either way.
    kOpinionNeutral = 5,
    // The same function returns -1 when a mean lands outside every band, which
    // the -/+0.25 tolerance makes possible only beyond the ends of the scale.
    kOpinionNone    = -1,
    // The highest level any mean in [-1, 1] can actually produce; see
    // OpinionFromMean.
    kOpinionMaxReachable = 9,
};

// How wide a band is on each side of its level (sub_4B9B80). Note this is
// larger than half the 0.2 spacing, so adjacent bands overlap and the search
// order below decides ties.
constexpr float kOpinionTolerance = 0.25f;

// The value a level represents, or 0 for an out-of-range level.
float OpinionValue(int32_t level);

// The level a mean feedback weight falls into, scanning from the most negative
// upward -- so where bands overlap, the more negative level wins. That scan
// order is the binary's (`while (!InBand(mean, i)) ++i`), and with bands wider
// than the spacing it is not a tie-break detail, it biases every opinion one
// step down: a mean of 0.0 reads as level 4 (-0.2), and a mean of 1.0 reads as
// level 9 (+0.8).
//
// The consequence is worth stating plainly: level 10 is unreachable. Reaching
// it needs a mean above 1.05, and episode weights live on [-1, 1]. A creature
// can come to hate something as completely as the scale allows, and can never
// quite love it that much.
//
// Returns kOpinionNone if nothing matches.
int32_t OpinionFromMean(float mean);

// Mean the weights, then bucket. An empty set is kOpinionNeutral, matching the
// binary's behaviour when a leaf and all its parents are empty.
int32_t OpinionFromEpisodes(const float* weights, uint32_t count);

// The weight CreatureInitialLesson seeds its episodes with (flt_B0CDE4). A
// creature does not start blank: its innate lessons come pre-weighted.
constexpr float kInitialLessonWeight = 0.8f;

}  // namespace creature
