// CreatureOpinion — translated from runblack_decrypted.exe (v1.0).
//
//   sub_4B9410  leaf value: mean the episode weights, then bucket
//   sub_4B9B80  band membership: fabs(mean - kScale[level]) <= 0.25
//   flt_B0CDC0  the eleven levels, read from .rdata

#include "black/CreatureOpinion.h"

#include <cmath>

namespace creature {

namespace {

// flt_B0CDC0[0..10], verbatim.
const float kScale[kOpinionLevels] = {
    -1.0f, -0.8f, -0.6f, -0.4f, -0.2f,
     0.0f,
     0.2f,  0.4f,  0.6f,  0.8f,  1.0f,
};

}  // namespace

float OpinionValue(int32_t level) {
    return (level >= 0 && level < kOpinionLevels) ? kScale[level] : 0.0f;
}

int32_t OpinionFromMean(float mean) {
    // sub_4B9410's search: first level whose band contains the mean, scanning
    // upward from the most negative. Give up past the end of the scale.
    for (int32_t level = 0; level < kOpinionLevels; ++level)
        if (std::fabs(mean - kScale[level]) <= kOpinionTolerance) return level;
    return kOpinionNone;
}

int32_t OpinionFromEpisodes(const float* weights, uint32_t count) {
    if (!weights || count == 0) return kOpinionNeutral;
    float sum = 0.0f;
    for (uint32_t i = 0; i < count; ++i) sum += weights[i];
    return OpinionFromMean(sum / static_cast<float>(count));
}

}  // namespace creature
