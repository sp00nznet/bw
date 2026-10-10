#include "black/GStream.h"
#include <cmath>

namespace { GStream* g_streams = nullptr; }

GStream* CreateStream(int id) {
    auto* s = new GStream();
    s->id = id;
    s->next = g_streams;
    g_streams = s;
    return s;
}

GStream* FirstStream() { return g_streams; }

void ResetStreams() {
    while (g_streams) {
        GStream* s = g_streams;
        g_streams = s->next;
        while (s->points) { GStream::Point* p = s->points; s->points = p->next; delete p; }
        delete s;
    }
}

void GStream::AddPoint(float x, float y, float z) {
    auto* p = new Point{x, y, z, nullptr};
    Point** at = &points;
    while (*at) at = &(*at)->next;
    *at = p;
    ++count;
}

GStream* NearestStreamPoint(const MapCoords& from, float max_m, MapCoords* out) {
    const float fx = MetresOf(from.x), fz = MetresOf(from.z);
    GStream* found = nullptr;
    for (GStream* s = g_streams; s; s = s->next)
        for (GStream::Point* p = s->points; p; p = p->next) {
            const float d = std::hypot(p->x - fx, p->z - fz);  // sub_6DE0E0
            if (d >= max_m) continue;
            max_m = d;
            // v1.0 hands back y above the land (point y - land height); our
            // MapCoords carry the altitude itself, which is the point's y.
            *out = MapCoordsFromMetres(p->x, p->z, p->y);
            found = s;
        }
    return found;
}

char*    GStream::GetDebugText() { return "GStream"; }
uint32_t GStream::Load(GameOSFile* file) { return 0; }
uint32_t GStream::Save(GameOSFile* file) { return 0; }
uint32_t GStream::GetSaveType() { return 0x47; }
