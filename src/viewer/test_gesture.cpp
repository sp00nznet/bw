// test_gesture — v1.0's gesture recognizer (black/Gesture.h) against the
// shipped templates. Each template's own shape is drawn as a mouse stroke
// through the trail (corner detection, headings, turns) and must be
// recognised as its own gesture. Needs game_data/Gestures.jty; skips without.
#include <black/Gesture.h>
#include <black/InfoDat.h>

#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <string>

static int g_fail = 0;
#define CHECK(cond, msg) do { if (!(cond)) { printf("FAIL: %s\n", msg); ++g_fail; } \
                              else printf("ok  : %s\n", msg); } while (0)

// Draw template d as a mouse stroke: 200 px across, a point every 20 px.
static gesture::Trail Draw(const gesture::Data& d) {
    gesture::Trail trail;
    trail.Clear();
    for (int i = 0; i + 1 < d.count; ++i) {
        const float ax = 100 + d.pts[i].x * 200, ay = 100 + d.pts[i].y * 200;
        const float bx = 100 + d.pts[i + 1].x * 200, by = 100 + d.pts[i + 1].y * 200;
        const float len = std::sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
        const int steps = len > 20 ? static_cast<int>(len / 20) : 1;
        for (int s = 0; s < steps; ++s) trail.Add(ax + (bx - ax) * s / steps, ay + (by - ay) * s / steps);
    }
    trail.Add(100 + d.pts[d.count - 1].x * 200, 100 + d.pts[d.count - 1].y * 200);
    return trail;
}

int main() {
    gesture::Templates t;
    const char* roots[] = {"game_data/", "../game_data/", "../../game_data/", "../../../game_data/"};
    bool loaded = false;
    for (const char* r : roots)
        if (t.Load(std::string(r) + "Gestures.jty")) { loaded = true; break; }
    if (!loaded) { printf("note: game_data not reachable; skipped\n"); return 0; }

    char msg[256];
    std::map<int, int> per_id;
    for (const gesture::Data& d : t.all) ++per_id[d.id];
    std::snprintf(msg, sizeof msg, "Gestures.jty: %zu templates of %zu gestures", t.all.size(), per_id.size());
    CHECK(t.all.size() == 81 && per_id.size() == 23, msg);

    // Draw every template at 200 px on a 640 x 480 screen, a point every
    // 20 px along its outline (a frame of mouse movement: the trail keeps only
    // the last 80 points), and ask for its own gesture.
    const float ratio = 640.0f / 480.0f;
    int recognised = 0, confused = 0;
    std::string misses;
    for (size_t k = 0; k < t.all.size(); ++k) {
        const gesture::Data& d = t.all[k];
        gesture::Trail trail;
        trail.Clear();
        for (int i = 0; i + 1 < d.count; ++i) {
            const float ax = 100 + d.pts[i].x * 200, ay = 100 + d.pts[i].y * 200;
            const float bx = 100 + d.pts[i + 1].x * 200, by = 100 + d.pts[i + 1].y * 200;
            const float len = std::sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
            const int steps = len > 20 ? static_cast<int>(len / 20) : 1;
            for (int s = 0; s < steps; ++s)
                trail.Add(ax + (bx - ax) * s / steps, ay + (by - ay) * s / steps);
        }
        trail.Add(100 + d.pts[d.count - 1].x * 200, 100 + d.pts[d.count - 1].y * 200);
        const gesture::Data in = trail.ToData(ratio);
        gesture::Result r;
        if (t.Match(d.id, in, ratio, &r)) ++recognised;
        else { char b[32]; std::snprintf(b, sizeof b, " %zu(id %d)", k, d.id); misses += b; }
        // Does it also pass for some other gesture?
        for (const auto& kv : per_id)
            if (kv.first != d.id && t.Match(static_cast<uint8_t>(kv.first), in, ratio, &r)) { ++confused; break; }
    }
    printf("      not recognised:%s\n", misses.empty() ? " none" : misses.c_str());
    std::snprintf(msg, sizeof msg, "templates drawn as strokes are recognised as their own gesture: %d of %zu (%d also pass as another)",
                  recognised, t.all.size(), confused);
    CHECK(recognised * 10 >= static_cast<int>(t.all.size()) * 9, msg);

    // Which gesture casts what. A spell seed (DETAIL_SPELL_SEEDS, the table
    // at 0xCBE310) offers up to three stages: magic types at +296..+304 and
    // their gestures at +308..+316 (sub_58F820). The hand's own gestures are
    // fields of DETAIL_SPELL_SYSTEM_INFO (dword_CC1208 / 120C / 1210 / 1228).
    for (const char* r : roots) if (infodat::Load((std::string(r) + "info.dat").c_str())) break;
    if (infodat::Count(infodat::DETAIL_SPELL_SEEDS)) {
        int in_range = 0, stages = 0;
        const uint32_t n = infodat::Count(infodat::DETAIL_SPELL_SEEDS);
        for (uint32_t i = 0; i < n; ++i) {
            const char* e = static_cast<const char*>(infodat::Element(infodat::DETAIL_SPELL_SEEDS, i));
            int32_t magic[3], g[3], seq[4], dflt;
            std::memcpy(&dflt, e + 292, 4);
            std::memcpy(seq, e + 256, 16);
            std::memcpy(magic, e + 296, 12);
            std::memcpy(g, e + 308, 12);
            printf("      seed %2u %-26s select %d,%d,%d (+268 %d) magic %d", i, infodat::DebugName(infodat::DETAIL_SPELL_SEEDS, i), seq[0], seq[1], seq[2], seq[3], dflt);
            for (int k = 0; k < 3; ++k) {
                if (!magic[k]) continue;
                ++stages;
                in_range += g[k] >= 1 && g[k] <= 23;
                printf("  magic %2d gesture %2d", magic[k], g[k]);
            }
            printf("\n");
        }
        const char* sys = static_cast<const char*>(infodat::Element(infodat::DETAIL_SPELL_SYSTEM_INFO, 0));
        int32_t g16, g20, g24, g48;
        std::memcpy(&g16, sys + 16, 4); std::memcpy(&g20, sys + 20, 4); std::memcpy(&g24, sys + 24, 4); std::memcpy(&g48, sys + 48, 4);
        printf("      spell system gestures: +16 %d, +20 %d, +24 %d, +48 %d\n", g16, g20, g24, g48);
        std::snprintf(msg, sizeof msg, "every spell stage names a gesture 1-23: %d of %d", in_range, stages);
        CHECK(stages > 0 && in_range == stages, msg);
    }

    // Choosing miracles (sub_58F9C0 / sub_590420): spiral 1, then each spell's
    // own gesture, drawn from the templates, selects that seed.
    if (infodat::Count(infodat::DETAIL_SPELL_SEEDS)) {
        bool known[30];
        for (bool& k : known) k = true;
        // A drawing of gesture id that the recognizer accepts (some curved
        // templates do not survive this coarse sampling; see above).
        auto first_template = [&](int id) -> const gesture::Data* {
            for (const gesture::Data& d : t.all)
                if (d.id == id && t.Match(static_cast<uint8_t>(id), Draw(d).ToData(ratio), ratio, nullptr)) return &d;
            return nullptr;
        };
        int chosen_right = 0, tried = 0;
        std::string wrong;
        for (int seed = 0; seed < 30; ++seed) {
            const char* e = static_cast<const char*>(infodat::Element(infodat::DETAIL_SPELL_SEEDS, static_cast<uint32_t>(seed)));
            int32_t q[3];
            std::memcpy(q, e + 256, 12);
            if (!q[0] || !q[1]) continue;  // seeds with no gesture of their own cannot be chosen
            ++tried;
            gesture::SpellSelect sel;
            const gesture::Trail opening = Draw(*first_template(q[0]));
            const gesture::Data in0 = opening.ToData(ratio);
            if (!t.Match(static_cast<uint8_t>(q[0]), in0, ratio, nullptr) || !sel.Begin(static_cast<uint8_t>(q[0]), known)) continue;
            int got = -1;
            bool done = false;
            for (int stage = 1; stage < 3 && !done && q[stage]; ++stage) {
                const gesture::Data in = Draw(*first_template(q[stage])).ToData(ratio);
                got = sel.Step(0.1f, [&](uint8_t id) { return t.Match(id, in, ratio, nullptr); }, known, &done);
            }
            if (got == seed) ++chosen_right;
            else { char b[64]; std::snprintf(b, sizeof b, " %s->%d", infodat::DebugName(infodat::DETAIL_SPELL_SEEDS, seed), got); wrong += b; }
        }
        printf("      not chosen:%s\n", wrong.empty() ? " none" : wrong.c_str());
        std::snprintf(msg, sizeof msg, "drawing a spell's gestures chooses that spell: %d of %d", chosen_right, tried);
        CHECK(tried > 0 && chosen_right * 10 >= tried * 9, msg);
    }

    printf(g_fail ? "\n%d FAILED\n" : "\nall passed\n", g_fail);
    return g_fail ? 1 : 0;
}
