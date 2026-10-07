#pragma once
// Sigmoid — sub_6DF550, the S-curve Lionhead's code uses for soft thresholds:
// how far `value` is past `threshold` (both clamped to [-1, 1]), read off the
// 41-entry table at 0xB461D4. 0 well below, 0.5 at the threshold, 1 well above;
// a threshold of exactly 1 always gives 0.
float Sigmoid(float threshold, float value);
