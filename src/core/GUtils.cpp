// GUtils — static utility functions
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)

#include <black/GUtils.h>
#include <cmath>

// Map coordinate conversion constants
static constexpr float COORD_TO_METRES = 10.0f / 65536.0f;  // 0x3727c5ac

float GUtils::GetDistanceInMetres(const MapCoords& a, const MapCoords& b) {
    // Original at 0x0074cd70
    int32_t dx = a.x.full - b.x.full;
    int32_t dz = a.z.full - b.z.full;
    float fx = static_cast<float>(dx) * COORD_TO_METRES;
    float fz = static_cast<float>(dz) * COORD_TO_METRES;
    return sqrtf(fx * fx + fz * fz);
}

void GUtils::GetDistance(const MapCoords& /*a*/, const MapCoords& /*b*/) {
    // Original at 0x0074ccb0 — stores result in global, used internally
}

int GUtils::FastDistance(const MapCoords& a, const MapCoords& b) {
    // Original at 0x0074ce10 — integer approximation of distance
    int32_t dx = abs(a.x.full - b.x.full);
    int32_t dz = abs(a.z.full - b.z.full);
    // Fast octagonal approximation: max(dx,dz) + 0.4142*min(dx,dz)
    if (dx > dz)
        return dx + (dz >> 2);
    return dz + (dx >> 2);
}

uint16_t GUtils::GetAngleFromDXDZ(int32_t dx, int32_t dz) {
    // Original at 0x0074d200
    float angle = atan2f(static_cast<float>(dx), static_cast<float>(dz));
    return static_cast<uint16_t>(angle * (32768.0f / 3.14159265f));
}

uint16_t GUtils::GetAngleFromXZ(const MapCoords& a, const MapCoords& b) {
    // Original at 0x0074d240
    return GetAngleFromDXDZ(a.x.full - b.x.full, a.z.full - b.z.full);
}

float GUtils::Get3DAngleFromXZ(const MapCoords& a, const MapCoords& b) {
    // Original at 0x0074d270
    float dx = static_cast<float>(a.x.full - b.x.full);
    float dz = static_cast<float>(a.z.full - b.z.full);
    return atan2f(dx, dz);
}

float GUtils::ConvertGameAngleTo3D(uint32_t angle) {
    // Original at 0x0074dc50
    // Game angles: 0-65535 (uint16 range) -> radians: 0 to 2*PI
    return static_cast<float>(angle) * (3.14159265f / 32768.0f);
}

uint32_t GUtils::ConvertAngle3DToGame(float angle) {
    // Original at 0x0074dc30
    return static_cast<uint32_t>(angle * (32768.0f / 3.14159265f));
}

MapCoords* GUtils::GetPosFromAngle(float angle, float radius) {
    // Original at 0x0074d580
    // Returns a MapCoords offset based on angle and radius in metres
    static MapCoords result;
    float metres_to_coord = 1.0f / COORD_TO_METRES;
    result.x = static_cast<int32_t>(sinf(angle) * radius * metres_to_coord);
    result.z = static_cast<int32_t>(cosf(angle) * radius * metres_to_coord);
    result.altitude = 0.0f;
    return &result;
}

const JustMapXZ* GUtils::Spiral(int32_t& /*param1*/, int32_t& /*param2*/) {
    // Original at 0x0074d7e0
    return nullptr;
}

void GUtils::SpiralIncrement(MapCoords& /*coords*/, int32_t& /*param2*/, int32_t& /*param3*/, float /*param4*/) {
    // Original at 0x0074d810
}

void GUtils::GetMidPoint(MapCoords& a, MapCoords& b, float t) {
    // Original at 0x0074ecc0 — linear interpolation between two points
    a.x = static_cast<int32_t>(a.x.full + static_cast<int32_t>((b.x.full - a.x.full) * t));
    a.z = static_cast<int32_t>(a.z.full + static_cast<int32_t>((b.z.full - a.z.full) * t));
    a.altitude = a.altitude + (b.altitude - a.altitude) * t;
}

void GUtils::GetXByAngleMetersDistance(uint16_t /*angle*/, float /*distance*/) {
    // Original at 0x0074d420
}

float GUtils::ConvertWholeDistanceToMeters(int32_t dist) {
    // Original at 0x0074dcc0
    return static_cast<float>(dist) * COORD_TO_METRES;
}

int GUtils::GetMapCellSpiralSizeFromRadius(float radius) {
    // Original at 0x0074f520
    return static_cast<int>(radius / (COORD_TO_METRES * 65536.0f)) + 1;
}

int GUtils::GetIncrementSpiralSizeFromRadius(float param1, float param2) {
    // Original at 0x0074f540
    return static_cast<int>(param1 / param2) + 1;
}

bool GUtils::FindNearestDrinkingWater(MapCoords& /*result*/, MapCoords& /*start*/, float /*max_dist*/) {
    // Original at 0x0074e3a0 — requires landscape/terrain integration
    return false;
}

float GUtils::SigmoidThreshold(float x, float threshold) {
    // Original at 0x0074f170
    // Smooth sigmoid-like threshold function
    if (x <= 0.0f) return 0.0f;
    if (x >= threshold) return 1.0f;
    float t = x / threshold;
    return t * t * (3.0f - 2.0f * t);  // smoothstep
}

float GUtils::GetDistanceModifier(float /*param1*/, float /*param2*/) {
    // Original at 0x0074f290
    return 1.0f;
}
