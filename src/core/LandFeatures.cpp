// The global feature map -- see black/LandFeatures.h.
#include <black/LandFeatures.h>
#include <black/Terrain.h>

namespace land {

namespace {

constexpr uint32_t kCells = 512;  // the map, in cells (game +6784/+6788)

// LND cell flags: 0x10 water, 0x20 coast line.
enum : int32_t { kWaterFlag = 0x10, kCoastFlag = 0x20 };

int32_t Flags(uint32_t cx, uint32_t cz) { return g_cell_flags_func ? g_cell_flags_func(cx, cz) : -1; }

// The per-cell tests (sub_5BFB00, sub_5BFBF0, sub_5BFC70). A cell with no
// landscape block counts as water.
bool IsWater(uint32_t cx, uint32_t cz) {
    const int32_t f = cx < kCells && cz < kCells ? Flags(cx, cz) : -1;
    return f < 0 || (f & kWaterFlag);
}
bool IsCoast(uint32_t cx, uint32_t cz) {
    const int32_t f = cx < kCells && cz < kCells ? Flags(cx, cz) : -1;
    return f >= 0 && !(f & kWaterFlag) && (f & kCoastFlag);
}
bool IsLand(uint32_t cx, uint32_t cz) {
    const int32_t f = cx < kCells && cz < kCells ? Flags(cx, cz) : -1;
    return f >= 0 && !(f & kWaterFlag);
}
using CellTest = bool (*)(uint32_t, uint32_t);

// sub_5BF410: any cell of block (bx, bz) passing `t`.
bool AnyCell(int bx, int bz, CellTest t) {
    for (uint32_t x = 8 * bx; x < 8u * bx + 8; ++x)
        for (uint32_t z = 8 * bz; z < 8u * bz + 8; ++z)
            if (t(x, z)) return true;
    return false;
}

// sub_5BF6C0: the first such cell, into `out`'s cell words.
bool FirstCell(int bx, int bz, CellTest t, MapCoords* out) {
    for (uint32_t x = 8 * bx; x < 8u * bx + 8; ++x)
        for (uint32_t z = 8 * bz; z < 8u * bz + 8; ++z)
            if (x < kCells && z < kCells && t(x, z)) {
                out->x.split.map = static_cast<uint16_t>(x);
                out->z.split.map = static_cast<uint16_t>(z);
                return true;
            }
    return false;
}

bool InRange(int bx, int bz) { return bx >= 0 && bz >= 0 && bx < FeatureMap::kBlocks && bz < FeatureMap::kBlocks; }  // sub_5A1570

// dword_CC6694, filled by the initialiser at 0x6DDD90: the spiral's four
// directions, which sub_5BF4B0 also takes as a block's neighbours.
constexpr int16_t kDir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

}  // namespace

bool FeatureMap::Has(Feature f, int bx, int bz) const {
    return InRange(bx, bz) && (regions[bx][bz].features & (1u << f));
}

void FeatureMap::Build() {
    // sub_4C1660: each block's highest cell (the last of equals), altitude
    // byte x 0.67 (flt_B59350); a cell with no landscape is 0.
    max_height = 0.0f;
    for (int bx = 0; bx < kBlocks; ++bx)
        for (int bz = 0; bz < kBlocks; ++bz) {
            Region& r = regions[bx][bz];
            r = Region();
            bool first = true;
            for (uint32_t x = 8 * bx; x < 8u * bx + 8; ++x)
                for (uint32_t z = 8 * bz; z < 8u * bz + 8; ++z) {
                    const int32_t a = g_cell_altitude_func && x < kCells && z < kCells ? g_cell_altitude_func(x, z) : -1;
                    const float h = a >= 0 ? a * 0.67000002f : 0.0f;
                    if (h >= r.height || first) {
                        first = false;
                        r.height = h;
                        r.top.x.split.map = static_cast<uint16_t>(x);
                        r.top.z.split.map = static_cast<uint16_t>(z);
                    }
                }
            if (r.height > max_height) max_height = r.height;
        }
    // sub_4C17A0: the feature bits, once every height is known.
    for (int bx = 0; bx < kBlocks; ++bx)
        for (int bz = 0; bz < kBlocks; ++bz) {
            uint8_t& b = regions[bx][bz].features;
            // ponytail: Citadel, Town and Forest (0x5C0EF0..: an object of
            // info type 8, 0 or 6 in the block's map cells) need the map's
            // object lists, which core does not keep; Field (sub_5C0740(18))
            // is not translated. Their bits stay clear.
            if (AnyCell(bx, bz, IsCoast)) b |= 1u << kCoast;
            if (AnyCell(bx, bz, IsWater)) b |= 1u << kWater;
            if (AnyCell(bx, bz, IsLand)) b |= 1u << kLand;
            // sub_5BF4B0: above half the map's highest point, and no
            // neighbouring block higher.
            const float h = regions[bx][bz].height;
            bool hill = max_height * 0.5f < h;
            for (int d = 0; hill && d < 4; ++d) {
                const int nx = bx + kDir[d][0], nz = bz + kDir[d][1];
                if (InRange(nx, nz) && regions[nx][nz].height > h) hill = false;
            }
            if (hill) b |= 1u << kHill;
        }
}

bool FeatureMap::Find(Feature f, const MapCoords& from, MapCoords* out, bool first, bool own) const {
    const int ox = from.x.split.map >> 3, oz = from.z.split.map >> 3;
    int bx = ox, bz = oz;
    int dir = 1, count = 1;
    bool found = false;
    for (int steps = 4096;;) {
        if (Has(f, bx, bz) && (own || bx != ox || bz != oz)) {
            found = true;
            out->x.split.map = static_cast<uint16_t>(8 * bx + 4);
            out->z.split.map = static_cast<uint16_t>(8 * bz + 4);
            switch (f) {  // the refiners (off_B0D7E4)
            case kCoast: FirstCell(bx, bz, IsCoast, out); break;  // 0x5C1090
            case kWater: FirstCell(bx, bz, IsWater, out); break;  // 0x5C10A0
            case kHill: *out = regions[bx][bz].top; break;        // 0x5C0FF0
            default: break;
            }
            // ponytail: a match in a block the creature has explored is passed
            // over unless `first` (sub_4C1440, its exploration bits at +536);
            // core keeps no exploration bits, so every block is unexplored.
            (void)first;
            return true;
        }
        if (!--steps) return found;
        if (count-- == 1) count = ++dir / 2;  // sub_6DE790
        bx += kDir[dir & 3][0];
        bz += kDir[dir & 3][1];
    }
}

FeatureMap& Features() {
    static FeatureMap* m = [] {
        auto* fm = new FeatureMap();
        fm->Build();
        return fm;
    }();
    return *m;
}

}  // namespace land
