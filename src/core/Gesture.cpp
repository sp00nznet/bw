// Gesture — v1.0's gesture recognizer. See black/Gesture.h and docs/gestures.md.
//
// Translated from the decompilation (sub_545110 .. sub_5474D0), with the
// comparisons read from the disassembly where Hex-Rays lost the x87 flags.
#include <black/Gesture.h>

#include <cmath>
#include <cstdio>
#include <cstring>

namespace gesture {

float Heading(const Point& a, const Point& b) {  // sub_746D50
    float h = std::atan2(b.y - a.y, b.x - a.x);
    if (h < 0.0f) h += 6.2831855f;
    return h;
}

float AngleDiff(float a, float b) {  // sub_544FD0
    const float r = b - a;
    if (r > kPi) return -(6.2831855f - r);
    if (r <= -kPi) return r + 6.2831855f;
    return r;
}

int Octant(float heading) {  // sub_544F80 / sub_544F50 (round half up)
    float i = heading + 1.5707964f;
    while (i > 6.2831855f) i -= 6.2831855f;
    const float v = i * 8.0f * 0.15915494f;
    int n = static_cast<int>(v);
    if (v - static_cast<float>(n) > 0.5f) ++n;
    return n % 8;
}

namespace {

float Wrap(float a) {  // sub_545F80
    if (std::fabs(a) <= kPi) return a;
    return a < 0.0f ? a + 6.2831855f : a - 6.2831855f;
}

struct Box { float x0, y0, x1, y1; };

// sub_545440: the bounding box of points [a, b] of a record.
Box Bounds(const Data& d, int a, int b) {
    Box r{d.pts[a].x, d.pts[a].y, d.pts[a].x, d.pts[a].y};
    for (int i = a + 1; i <= b; ++i) {
        const Point& p = d.pts[i];
        if (p.x < r.x0) r.x0 = p.x; else if (p.x > r.x1) r.x1 = p.x;
        if (p.y < r.y0) r.y0 = p.y; else if (p.y > r.y1) r.y1 = p.y;
    }
    return r;
}

// sub_545510: width over height, the height scaled by the screen's ratio
// (dword_D5C108: width / height in v1.0).
float Aspect(const Box& b, float screen_ratio) {
    float h = (b.y1 - b.y0 + 1.0f) * screen_ratio;
    if (h < 1.0f) h = 1.0f;
    return (b.x1 - b.x0 + 1.0f) / h;
}

// sub_545F10: the octant of the stroke's first matched segment.
bool OctantOk(const Data& t, const Data& in, int i, bool mirrored) {
    if (!t.check_octant) return true;
    const int o = static_cast<uint8_t>(in.pts[i].octant);
    if (!mirrored) return o == static_cast<uint8_t>(t.pts[0].octant);
    const int to = t.pts[0].octant;
    return to ? o == static_cast<uint8_t>(8 - to) : o == 0;
}

// sub_545DD0, from the disassembly: thin (< 0.15), ordinary, wide (> 4).
bool SizeOk(const Data& t, const Data& in, const Result& r, float screen_ratio) {
    if (!t.check_size) return true;
    const float a = Aspect(Bounds(in, r.start, r.end), screen_ratio);
    if (a < 0.15f) return t.aspect < 0.15f;
    if (a > 4.0f) return t.aspect > 0.15f;
    return t.aspect >= 0.15f && t.aspect <= 4.0f;
}

// sub_545FD0 (mirrored false) / sub_546210 (true): walk the template's and
// the stroke's turns together from each start, summing how far they
// disagree; a turn too slight to count (kSkipTurn) may be passed over on
// either side if that brings them closer. Too far apart (kMaxDrift) and that
// start fails.
bool MatchFrom(const Data& t, const Data& in, bool mirrored, float screen_ratio, Result* out) {
    const int n_in = in.count - 1, n_t = t.count - 1;
    if (n_in <= 1) return false;
    const float sign = mirrored ? -1.0f : 1.0f;
    for (int s = 1; s < n_in; ++s) {
        if (!OctantOk(t, in, s - 1, mirrored)) continue;
        int i = s, j = 1;
        float acc = 0.0f;
        bool failed = false;
        if (n_t > 1) {
            for (;;) {
                float a_in = 0.0f, a_t = 0.0f;
                if (i < n_in) { a_in = sign * in.pts[i].turn; ++i; }
                if (j < n_t) { a_t = t.pts[j].turn; ++j; }
                acc = Wrap(a_t - a_in + acc);
                if (i < n_in && (std::fabs(in.pts[i].turn) < kSkipTurn || std::fabs(a_in) < kSkipTurn)) {
                    const float alt = Wrap(acc - sign * in.pts[i].turn);
                    if (std::fabs(acc) > std::fabs(alt)) { acc = alt; ++i; }
                }
                if (j < n_t && (std::fabs(t.pts[j].turn) < kSkipTurn || std::fabs(a_t) < kSkipTurn)) {
                    const float alt = Wrap(t.pts[j].turn + acc);
                    if (std::fabs(acc) > std::fabs(alt)) { acc = alt; ++j; }
                }
                if (std::fabs(acc) > kMaxDrift) { failed = true; break; }
                if (j >= n_t) break;
            }
        }
        if (failed) continue;
        Result r;
        if (!mirrored) { r.start = static_cast<uint8_t>(s - 1); r.end = static_cast<uint8_t>(i); }
        else { r.start = static_cast<uint8_t>(s); r.end = static_cast<uint8_t>(i - 1); }
        if (!SizeOk(t, in, r, screen_ratio)) continue;
        *out = r;
        return true;
    }
    return false;
}

}  // namespace

void Data::Finish(float screen_ratio) {  // sub_545570
    if (!count) { aspect = 0.0f; return; }
    const Box b = Bounds(*this, 0, count - 1);
    const float w = b.x1 - b.x0, h = b.y1 - b.y0;
    if (w > 1.0f || h > 1.0f) aspect = Aspect(b, screen_ratio);  // screen pixels
    else aspect = h <= 0.1f ? w / 0.1f : w / h;                    // normalised
}

bool Templates::Load(const std::string& path) {
    // sub_545AC0 / sub_545600: a count, then per template 80 points and seven
    // dwords read to +1608, +1609, +1610, +1616, +1620, +1624, +1612. The
    // first three land on overlapping bytes, so only their low bytes survive
    // as the point count and the gesture id.
    all.clear();
    FILE* f = std::fopen(path.c_str(), "rb");
    if (!f) return false;
    uint32_t n = 0;
    bool ok = std::fread(&n, 4, 1, f) == 1 && n < 4096;
    for (uint32_t k = 0; ok && k < n; ++k) {
        Data d;
        uint32_t w[7];
        ok = std::fread(d.pts, sizeof d.pts, 1, f) == 1 && std::fread(w, 4, 7, f) == 7;
        if (!ok) break;
        d.count = static_cast<uint8_t>(w[0]);
        d.id = static_cast<uint8_t>(w[1]);
        d.check_octant = w[3];
        d.mirror_ok = w[4];
        d.check_size = w[5];
        std::memcpy(&d.aspect, &w[6], 4);
        if (d.count > 80) d.count = 80;
        all.push_back(d);
    }
    std::fclose(f);
    if (!ok) all.clear();
    return ok;
}

bool Templates::Match(uint8_t id, const Data& in, float screen_ratio, Result* out) const {
    // sub_545D70 -> sub_545E80: each template of that gesture, as drawn and
    // then, where allowed, mirrored.
    for (size_t k = 0; k < all.size(); ++k) {
        const Data& t = all[k];
        if (t.id != id) continue;
        Result r;
        bool mirrored = false;
        bool ok = MatchFrom(t, in, false, screen_ratio, &r);
        if (!ok && t.mirror_ok) ok = mirrored = MatchFrom(t, in, true, screen_ratio, &r);
        if (ok) {
            r.id = t.id;
            r.mirrored = mirrored;
            r.index = static_cast<uint8_t>(k);
            if (out) *out = r;
            return true;
        }
    }
    return false;
}

// --- the trail ---------------------------------------------------------------

Trail::Entry& Trail::At(int i) {
    return ring[i <= count ? (head - count + i + 80) % 80 : 0];
}
const Trail::Entry& Trail::At(int i) const {
    return ring[i <= count ? (head - count + i + 80) % 80 : 0];
}

void Trail::Clear() {
    std::memset(ring, 0, sizeof ring);
    count = 0;
    head = 0;
    still = 0;
}

namespace {
bool Far(const Point& a, const Point& b) {  // sub_547130 -> sub_547160
    return std::fabs(b.x - a.x) >= 4.0f || std::fabs(b.y - a.y) >= 4.0f;
}
float Turn(const Point& a, const Point& b, const Point& c) {  // sub_546B30
    return AngleDiff(Heading(a, b), Heading(b, c));
}
}  // namespace

void Trail::Add(float sx, float sy, const float world[3]) {  // sub_546890
    for (;;) {
        Entry& e = ring[head];
        if (world) std::memcpy(e.world, world, sizeof e.world);
        e.pt.x = sx;
        e.pt.y = sy;
        if (count < 80) ++count;
        if (count <= 1) break;
        // sic: compared with the point two back, not the one before.
        const Entry& back = ring[(head - 2 + 80) % 80];
        if (back.pt.x - sx != 0.0f || back.pt.y - sy != 0.0f) { still = 0; break; }
        if (++still < 70) break;
        Clear();  // held still too long: start again with this point
    }
    head = static_cast<uint8_t>((head + 1) % 80);
    Process(count - 1);
}

void Trail::Process(int n) {  // sub_546FC0
    if (n != 0 && At(n - 1).flag == 8) At(n - 1).flag = 0;
    At(0).flag = 1;
    At(n).flag = 8;
    if (n == 0) return;
    const int k = LastKey(n);
    const int c = FindCorner(k, n);
    if (c) {
        if (!MergeCorner(c, n)) {
            At(c).flag = 2;
            Heading(c);
        }
        At(n).flag = 4;
    }
    Heading(n);
}

int Trail::LastKey(int n) const {  // sub_5469E0
    for (int i = n - 1; i > 0; --i)
        if (At(i).flag) return i;
    return 0;
}

int Trail::LastCorner(int n) const {  // sub_546D70
    for (int i = n - 1; i > 0; --i)
        if (At(i).flag == 2) return i;
    return 0;
}

int Trail::FarBack(int n) const {  // sub_546A40
    if (n == 1) return 0;
    const Point& pn = At(n).pt;
    for (int i = n - 1; i > 0; --i) {
        const Entry& e = At(i);
        if (e.flag) return i;
        const bool empty = std::fabs(e.pt.x) <= 0.0001f && std::fabs(e.pt.pad) <= 0.0001f && std::fabs(e.pt.y) <= 0.0001f;
        if (!empty && Far(e.pt, pn)) return i;
    }
    return 0;
}

int Trail::FindCorner(int k, int n) {  // sub_546BB0
    if (n <= 1) return 0;
    const Point pn = At(n).pt, pk = At(k).pt;
    int j = FarBack(n);
    int best = 0;
    float best_turn = 0.0f;
    for (; j > k; --j) {
        const Point& pj = At(j).pt;
        if (!Far(pk, pj)) break;
        const float t = std::fabs(Turn(pk, pj, pn));
        if (t >= kCornerTurn && t > best_turn) { best_turn = t; best = j; }
    }
    if (best) return best;
    if (k) {
        const Point& pk2 = At(LastKey(k)).pt;
        if (std::fabs(Turn(pk2, pk, pn)) >= kCornerTurn) return k;
    }
    return 0;
}

bool Trail::LongEnough(int a, int c, const Point& p1, const Point& p2) const {  // sub_5471A0 -> sub_5471D0
    const float dx = std::fabs(p2.x - p1.x), dy = std::fabs(p2.y - p1.y);
    const float m = dx > dy ? dx : dy;
    if (m >= 12.0f) return true;
    if (m <= 4.0f) return false;
    int from = a ? LastCorner(a) : 0;
    const int lim = c - 8 < 0 ? 0 : c - 8;
    if (from >= lim) from = lim;
    // sub_545110: the trail's bounding box over [from, c), skipping empty entries.
    const Entry& e0 = At(from);
    float x0 = e0.pt.x, x1 = e0.pt.x, y0 = e0.pt.y, y1 = e0.pt.y;
    int span = c - from;
    if (span >= count) span = count;
    if (span < 0) span += 80;
    int phys = (from <= count ? (head - count + from + 80) % 80 : 0);
    for (int s = 1; s < span; ++s) {
        phys = (phys + 1) % 80;
        const Point& p = ring[phys].pt;
        if (std::fabs(p.x) > 0.0001f || std::fabs(p.pad) > 0.0001f || std::fabs(p.y) > 0.0001f) {
            if (p.x < x0) x0 = p.x; else if (p.x > x1) x1 = p.x;
            if (p.y < y0) y0 = p.y; else if (p.y > y1) y1 = p.y;
        }
    }
    float size = y1 - y0 + 1.0f;
    if (size <= x1 - x0 + 1.0f) size = x1 - x0 + 1.0f;
    return size < 50.0f;  // a small gesture: short segments still count
}

bool Trail::MergeCorner(int c, int n) {  // sub_546DD0: true when c is not to be a corner
    const int p = LastCorner(c);
    Point& pc = At(c).pt;
    if (!p) {
        const Point& p0 = At(0).pt;
        if (!LongEnough(0, c, p0, pc)) {
            pc.x = p0.x; pc.pad = p0.pad; pc.y = p0.y;
            return true;
        }
        return false;
    }
    Point& pp = At(p).pt;
    if (LongEnough(p, c, pp, pc)) return false;
    // Too close to the last corner: keep one, wherever the turn is sharper.
    const Point& pq = At(LastCorner(p)).pt;
    const Point& pn = At(n).pt;
    const float t_prev = std::fabs(Turn(pq, pp, pn));
    if (std::fabs(Turn(pq, pc, pn)) >= t_prev) { pp.x = pc.x; pp.pad = pc.pad; pp.y = pc.y; }
    else { pc.x = pp.x; pc.pad = pp.pad; pc.y = pp.y; }
    return true;
}

void Trail::Heading(int c) {  // sub_5472B0
    const int p = LastCorner(c);
    Entry& ep = At(p);
    ep.heading = gesture::Heading(ep.pt, At(c).pt);
    ep.pt.octant = Octant(ep.heading);
    TurnAt(p);
}

void Trail::TurnAt(int p) {  // sub_5473C0
    if (!p) return;
    const int q = LastCorner(p);
    At(p).pt.turn = AngleDiff(At(q).heading, At(p).heading);
}

Data Trail::ToData(float screen_ratio) const {  // sub_545360
    Data d;
    for (int i = 0; i < count; ++i)
        if (i >= count - 1 || (At(i).flag & 0xB)) d.pts[d.count++] = At(i).pt;
    d.Finish(screen_ratio);
    return d;
}

}  // namespace gesture
