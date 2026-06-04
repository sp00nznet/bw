// psys_fx — see psys_fx.h.

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>
#include <GL/gl.h>

#include "psys_fx.h"

#include <cmath>
#include <cstdint>
#include <unordered_map>
#include <vector>

namespace bw {
namespace psysfx {

namespace {

// --- Spell families (mirrors RenderSpells' spell_id % 6 colour mapping) -----
enum Family { FIRE = 0, HEAL = 1, WATER = 2, LIGHTNING = 3, SHIELD = 4, SPARKLE = 5 };

struct Particle {
    float pos[3];
    float vel[3];
    float accel[3];
    float life, max_life;
    float size0, size1;     // size lerps from size0 -> size1 over life
    float r, g, b, a0;      // a0 = peak alpha
};

std::vector<Particle> g_particles;
std::unordered_map<uint64_t, float> g_spawn_accum;   // emitter key -> fractional spawn carry
GLuint  g_tex = 0;
bool    g_inited = false;

constexpr size_t kMaxParticles = 6000;

// Small fast PRNG — no <random> dependency, deterministic-ish per call site.
uint32_t g_rng = 0x1234abcdu;
inline float frand() {
    g_rng ^= g_rng << 13; g_rng ^= g_rng >> 17; g_rng ^= g_rng << 5;
    return (g_rng & 0xFFFFFF) / static_cast<float>(0x1000000);  // [0,1)
}
inline float frand2() { return frand() * 2.0f - 1.0f; }        // [-1,1)

uint64_t EmitterKey(const lhvm::SpellSnap& s) {
    // Stable-ish identity: family + target + quantised ground position.
    uint64_t qx = static_cast<uint64_t>(static_cast<int32_t>(s.x * 0.25f)) & 0xFFFFF;
    uint64_t qz = static_cast<uint64_t>(static_cast<int32_t>(s.z * 0.25f)) & 0xFFFFF;
    return (static_cast<uint64_t>(static_cast<uint32_t>(s.spell_id)) << 40) ^
           (static_cast<uint64_t>(s.target_object) << 20) ^ (qx << 10) ^ qz;
}

// Generate the 32x32 soft radial-gradient sprite (white core -> clear edge).
void BuildTexture() {
    const int N = 32;
    unsigned char px[N * N * 4];
    const float c = (N - 1) * 0.5f;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            float dx = (x - c) / c, dy = (y - c) / c;
            float d = std::sqrt(dx * dx + dy * dy);          // 0 centre .. ~1.41 corner
            float a = 1.0f - d;
            if (a < 0.0f) a = 0.0f;
            a *= a;                                          // soften falloff
            unsigned char* p = &px[(y * N + x) * 4];
            p[0] = p[1] = p[2] = 255;
            p[3] = static_cast<unsigned char>(a * 255.0f);
        }
    }
    glGenTextures(1, &g_tex);
    glBindTexture(GL_TEXTURE_2D, g_tex);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, N, N, 0, GL_RGBA, GL_UNSIGNED_BYTE, px);
}

void Spawn(const Particle& p) {
    if (g_particles.size() < kMaxParticles) g_particles.push_back(p);
}

// Emit `n` particles for one spell, following its family's behaviour. The
// family names trace BW's real Atom update rules (EmitterRuleConical,
// UR_HealSpellChakra, UR_LightningStrike, UR_SphereSurfaceTracer, ...).
void Emit(Family fam, const lhvm::SpellSnap& s, float ground, int n, float t) {
    for (int i = 0; i < n; ++i) {
        Particle p{};
        p.pos[0] = s.x; p.pos[1] = ground + 1.0f; p.pos[2] = s.z;
        p.accel[0] = p.accel[1] = p.accel[2] = 0.0f;
        switch (fam) {
        case FIRE: {  // conical ember fountain, buoyant then arcing down
            p.vel[0] = frand2() * 2.5f; p.vel[2] = frand2() * 2.5f;
            p.vel[1] = 6.0f + frand() * 6.0f;
            p.accel[1] = -4.0f;
            p.max_life = p.life = 0.8f + frand() * 0.7f;
            p.size0 = 1.4f; p.size1 = 3.2f;
            p.r = 1.0f; p.g = 0.45f + frand() * 0.3f; p.b = 0.12f; p.a0 = 0.85f;
        } break;
        case HEAL: {  // rising chakra helix
            float ang = t * 4.0f + i * 1.7f;
            float rr = s.radius * 0.5f;
            p.pos[0] = s.x + std::cos(ang) * rr;
            p.pos[2] = s.z + std::sin(ang) * rr;
            p.vel[0] = -std::sin(ang) * 1.5f; p.vel[2] = std::cos(ang) * 1.5f;
            p.vel[1] = 4.0f + frand() * 3.0f;
            p.max_life = p.life = 1.1f + frand() * 0.5f;
            p.size0 = 1.0f; p.size1 = 2.2f;
            p.r = 0.5f; p.g = 1.0f; p.b = 0.5f + frand() * 0.4f; p.a0 = 0.8f;
        } break;
        case WATER: {  // droplets falling under gravity
            p.pos[1] = ground + 6.0f + s.radius * 0.5f;
            p.pos[0] = s.x + frand2() * s.radius * 0.6f;
            p.pos[2] = s.z + frand2() * s.radius * 0.6f;
            p.vel[0] = frand2() * 1.5f; p.vel[2] = frand2() * 1.5f;
            p.vel[1] = -1.0f - frand() * 2.0f;
            p.accel[1] = -9.8f;
            p.max_life = p.life = 1.0f + frand() * 0.6f;
            p.size0 = 1.6f; p.size1 = 0.9f;
            p.r = 0.4f; p.g = 0.65f; p.b = 1.0f; p.a0 = 0.8f;
        } break;
        case LIGHTNING: {  // flickering sprites up a vertical column
            p.pos[1] = ground + 1.0f + frand() * 13.0f;
            p.pos[0] = s.x + frand2() * 0.6f;
            p.pos[2] = s.z + frand2() * 0.6f;
            p.vel[0] = p.vel[1] = p.vel[2] = 0.0f;
            p.max_life = p.life = 0.12f + frand() * 0.18f;
            p.size0 = 2.6f; p.size1 = 1.0f;
            p.r = 1.0f; p.g = 1.0f; p.b = 0.55f + frand() * 0.4f; p.a0 = 1.0f;
        } break;
        case SHIELD: {  // particles tracing a sphere surface
            float u = frand2(), th = t + i * 2.4f;
            float rxy = std::sqrt(1.0f - u * u) * s.radius;
            p.pos[0] = s.x + std::cos(th) * rxy;
            p.pos[2] = s.z + std::sin(th) * rxy;
            p.pos[1] = ground + s.radius + u * s.radius;
            p.vel[0] = -std::sin(th) * 1.0f; p.vel[2] = std::cos(th) * 1.0f;
            p.vel[1] = 0.0f;
            p.max_life = p.life = 0.5f + frand() * 0.4f;
            p.size0 = 1.2f; p.size1 = 2.0f;
            p.r = 0.7f; p.g = 0.45f; p.b = 1.0f; p.a0 = 0.55f;
        } break;
        default: {  // radial sparkle burst
            float th = frand() * 6.2831853f;
            float sp = 2.0f + frand() * 4.0f;
            p.vel[0] = std::cos(th) * sp; p.vel[2] = std::sin(th) * sp;
            p.vel[1] = 2.0f + frand() * 4.0f;
            p.accel[1] = -3.0f;
            p.max_life = p.life = 0.7f + frand() * 0.6f;
            p.size0 = 1.0f; p.size1 = 2.4f;
            p.r = 1.0f; p.g = 0.45f; p.b = 0.85f; p.a0 = 0.8f;
        } break;
        }
        Spawn(p);
    }
}

// Per-family spawn rate (particles/second), scaled by remaining spell life.
int RateFor(Family fam) {
    switch (fam) {
    case FIRE:      return 70;
    case HEAL:      return 55;
    case WATER:     return 60;
    case LIGHTNING: return 40;
    case SHIELD:    return 50;
    default:        return 45;
    }
}

} // namespace

void Init() {
    if (g_inited) return;
    BuildTexture();
    g_particles.reserve(kMaxParticles);
    g_inited = true;
}

void Sync(const lhvm::SpellSnap* spells, uint32_t count, float dt, HeightFn height) {
    if (!g_inited) Init();
    if (dt <= 0.0f) dt = 1.0f / 30.0f;
    if (dt > 0.25f) dt = 0.25f;   // clamp huge frame gaps

    // Advance existing particles.
    for (size_t i = 0; i < g_particles.size();) {
        Particle& p = g_particles[i];
        p.life -= dt;
        if (p.life <= 0.0f) {
            p = g_particles.back();
            g_particles.pop_back();
            continue;
        }
        for (int k = 0; k < 3; ++k) {
            p.vel[k] += p.accel[k] * dt;
            p.pos[k] += p.vel[k] * dt;
        }
        ++i;
    }

    // Emit from each active spell.
    for (uint32_t i = 0; i < count; ++i) {
        const lhvm::SpellSnap& s = spells[i];
        float life_frac = s.duration > 0.0f ? s.age / s.duration : 0.0f;
        if (life_frac >= 1.0f) continue;             // expired — TickSpells will drop it
        float fade = 1.0f - life_frac;               // taper emission near the end
        Family fam = static_cast<Family>(((s.spell_id % 6) + 6) % 6);
        float ground = height ? height(s.x, s.z) : s.y;

        uint64_t key = EmitterKey(s);
        float& acc = g_spawn_accum[key];
        acc += RateFor(fam) * fade * dt;
        int n = static_cast<int>(acc);
        if (n > 0) { acc -= n; Emit(fam, s, ground, n, s.age); }
    }

    // Drop spawn accumulators that no longer correspond to an active spell.
    if (!g_spawn_accum.empty() && count == 0) g_spawn_accum.clear();
}

void Render() {
    if (g_particles.empty()) return;

    // Camera right/up from the current modelview (billboard basis).
    GLfloat m[16];
    glGetFloatv(GL_MODELVIEW_MATRIX, m);
    const float rx = m[0], ry = m[4], rz = m[8];   // right
    const float ux = m[1], uy = m[5], uz = m[9];   // up

    glPushAttrib(GL_ENABLE_BIT | GL_DEPTH_BUFFER_BIT | GL_TEXTURE_BIT | GL_COLOR_BUFFER_BIT);
    glDisable(GL_LIGHTING);
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, g_tex);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE);             // additive glow
    glDepthMask(GL_FALSE);                          // blend with scene, don't occlude

    glBegin(GL_QUADS);
    for (const Particle& p : g_particles) {
        float t = 1.0f - p.life / p.max_life;       // 0 at birth -> 1 at death
        float sz = p.size0 + (p.size1 - p.size0) * t;
        float alpha = p.a0 * (p.life / p.max_life); // linear fade out
        glColor4f(p.r, p.g, p.b, alpha);

        float ax = rx * sz, ay = ry * sz, az = rz * sz;
        float bx = ux * sz, by = uy * sz, bz = uz * sz;
        const float* c = p.pos;
        glTexCoord2f(0, 0); glVertex3f(c[0] - ax - bx, c[1] - ay - by, c[2] - az - bz);
        glTexCoord2f(1, 0); glVertex3f(c[0] + ax - bx, c[1] + ay - by, c[2] + az - bz);
        glTexCoord2f(1, 1); glVertex3f(c[0] + ax + bx, c[1] + ay + by, c[2] + az + bz);
        glTexCoord2f(0, 1); glVertex3f(c[0] - ax + bx, c[1] - ay + by, c[2] - az + bz);
    }
    glEnd();

    glDepthMask(GL_TRUE);
    glPopAttrib();
}

uint32_t LiveCount() { return static_cast<uint32_t>(g_particles.size()); }

} // namespace psysfx
} // namespace bw
