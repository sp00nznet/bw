#pragma once
// GUtils — static utility functions for distance/angle calculations
// Struct layout from bw1-decomp (Utils.h)
//
// GUtils is a namespace-like static class — no instances, all static methods.
// Used throughout the codebase for coordinate math.

#include "types.h"

struct GUtils {
    // Distance calculations
    static float GetDistanceInMetres(const MapCoords& a, const MapCoords& b);
    static void GetDistance(const MapCoords& a, const MapCoords& b);
    static int FastDistance(const MapCoords& a, const MapCoords& b);

    // Angle calculations
    static uint16_t GetAngleFromDXDZ(int32_t dx, int32_t dz);
    static uint16_t GetAngleFromXZ(const MapCoords& a, const MapCoords& b);
    static float Get3DAngleFromXZ(const MapCoords& a, const MapCoords& b);
    static float ConvertGameAngleTo3D(uint32_t angle);
    static uint32_t ConvertAngle3DToGame(float angle);

    // Position utilities
    static MapCoords* GetPosFromAngle(float angle, float radius);
    static const JustMapXZ* Spiral(int32_t& param1, int32_t& param2);
    static void SpiralIncrement(MapCoords& coords, int32_t& param2, int32_t& param3, float param4);
    static void GetMidPoint(MapCoords& a, MapCoords& b, float t);
    static void GetXByAngleMetersDistance(uint16_t angle, float distance);

    // Conversion utilities
    static float ConvertWholeDistanceToMeters(int32_t dist);
    static int GetMapCellSpiralSizeFromRadius(float radius);
    static int GetIncrementSpiralSizeFromRadius(float param1, float param2);

    // Game utilities
    static bool FindNearestDrinkingWater(MapCoords& result, MapCoords& start, float max_dist);
    static float SigmoidThreshold(float param1, float param2);
    static float GetDistanceModifier(float param1, float param2);
};
