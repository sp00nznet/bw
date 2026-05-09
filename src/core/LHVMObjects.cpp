// LHVM ↔ Object bridge — implementation
//
// Owns the script-handle ↔ Object* registry and wires the LHVM natives
// that touch the entity system. This is intentionally a separate module
// from LHVM.cpp so the VM core stays free of game-object headers.

#include <black/LHVMObjects.h>
#include <black/LHVM.h>
#include <black/Object.h>
#include <black/Terrain.h>
#include <black/EntityFactory.h>
#include <black/Flock.h>
#include <black/types.h>

#include <cmath>
#include <cstdlib>
#include <cstring>
#include <unordered_map>

// Forward decl matching LHVM.cpp's anonymous accessor pattern.
struct GGame;
extern GGame* g_game;
#include <vector>

namespace lhvm {

// ============================================================================
// Object handle table
// ============================================================================
//
// Handle 0 is reserved for "null". Handles are dense 32-bit indices into a
// vector of Object*. Freed handles go on a free list and may be reused.

namespace {

struct Slot {
    Object*  obj;          // nullptr if free
    uint32_t flags;        // script-level flags (FLAG_*)
};

constexpr uint32_t FLAG_ACTIVE         = 1u << 0;
constexpr uint32_t FLAG_INDESTRUCTABLE = 1u << 1;
constexpr uint32_t FLAG_MOVEABLE       = 1u << 2;
constexpr uint32_t FLAG_PICKUPABLE     = 1u << 3;
constexpr uint32_t FLAG_ON_FIRE        = 1u << 4;
constexpr uint32_t FLAG_POISONED       = 1u << 5;
constexpr uint32_t FLAG_SKELETON       = 1u << 6;
constexpr uint32_t FLAG_RELEASED       = 1u << 7;  // released from script
constexpr uint32_t FLAG_FIGHTING       = 1u << 8;
constexpr uint32_t FLAG_LEASHED        = 1u << 9;

// slot 0 is the null sentinel
std::vector<Slot>            g_slots = { { nullptr, 0 } };
std::vector<uint32_t>        g_free;
std::unordered_map<Object*, uint32_t> g_reverse;

} // namespace

uint32_t RegisterObject(Object* obj) {
    if (!obj) return 0;
    auto it = g_reverse.find(obj);
    if (it != g_reverse.end()) return it->second;

    uint32_t handle;
    if (!g_free.empty()) {
        handle = g_free.back();
        g_free.pop_back();
        g_slots[handle] = { obj, FLAG_ACTIVE };
    } else {
        handle = static_cast<uint32_t>(g_slots.size());
        g_slots.push_back({ obj, FLAG_ACTIVE });
    }
    g_reverse[obj] = handle;
    return handle;
}

Object* LookupObject(uint32_t handle) {
    if (handle == 0 || handle >= g_slots.size()) return nullptr;
    return g_slots[handle].obj;
}

uint32_t HandleFor(Object* obj) {
    if (!obj) return 0;
    auto it = g_reverse.find(obj);
    return it == g_reverse.end() ? 0 : it->second;
}

void UnregisterObject(uint32_t handle) {
    if (handle == 0 || handle >= g_slots.size()) return;
    Slot& s = g_slots[handle];
    if (!s.obj) return;
    g_reverse.erase(s.obj);
    s.obj = nullptr;
    s.flags = 0;
    g_free.push_back(handle);
}

void ClearAllObjects() {
    g_slots.assign(1, { nullptr, 0 });
    g_free.clear();
    g_reverse.clear();
}

static Slot* SlotOf(uint32_t handle) {
    if (handle == 0 || handle >= g_slots.size() || !g_slots[handle].obj) return nullptr;
    return &g_slots[handle];
}

// ============================================================================
// Host services
// ============================================================================

HandQueryFn   g_hand_query_func   = nullptr;
ClickQueryFn  g_click_query_func  = nullptr;
EntitySpawnFn g_entity_spawn_func = nullptr;

static void NotifySpawn(uint32_t handle, Object* obj,
                        int32_t script_type, int32_t script_subtype,
                        float x, float y, float z) {
    if (!g_entity_spawn_func || handle == 0 || !obj) return;
    SpawnInfo info = { handle, obj, script_type, script_subtype, x, y, z };
    g_entity_spawn_func(&info);
}

namespace {
ClickInfo g_click_latch = {};

ClickInfo CurrentClick() {
    ClickInfo info = {};
    if (g_click_query_func) g_click_query_func(&info);
    // OR with latched values so scripts can read across multiple ticks
    if (g_click_latch.thing_clicked)    { info.thing_clicked = true;    info.clicked_object = g_click_latch.clicked_object; }
    if (g_click_latch.position_clicked) {
        info.position_clicked = true;
        info.click_x = g_click_latch.click_x;
        info.click_y = g_click_latch.click_y;
        info.click_z = g_click_latch.click_z;
    }
    return info;
}

HandInfo CurrentHand() {
    HandInfo info = {};
    if (g_hand_query_func) g_hand_query_func(&info);
    return info;
}
} // namespace

void ClearClickedObject()   { g_click_latch.thing_clicked = false;    g_click_latch.clicked_object = 0; }
void ClearClickedPosition() { g_click_latch.position_clicked = false; g_click_latch.click_x = g_click_latch.click_y = g_click_latch.click_z = 0; }

void NotifyObjectClicked(uint32_t handle) {
    g_click_latch.thing_clicked    = true;
    g_click_latch.clicked_object   = handle;
}

void NotifyPositionClicked(float x, float y, float z) {
    g_click_latch.position_clicked = true;
    g_click_latch.click_x = x;
    g_click_latch.click_y = y;
    g_click_latch.click_z = z;
}

// ============================================================================
// Coordinate conversion helpers
// ============================================================================

static constexpr float MAP_FIXED_SCALE = 65536.0f;

static float WorldX(const Object* obj) { return obj->obj_coords.x.full / MAP_FIXED_SCALE; }
static float WorldZ(const Object* obj) { return obj->obj_coords.z.full / MAP_FIXED_SCALE; }
static float WorldY(const Object* obj) { return obj->obj_coords.altitude; }

static MapCoords MakeCoords(float x, float y, float z) {
    return MapCoords(static_cast<int32_t>(x * MAP_FIXED_SCALE),
                     static_cast<int32_t>(z * MAP_FIXED_SCALE),
                     y);
}

// ============================================================================
// Native implementations (50)
// ============================================================================

static void N_GET_POSITION(LHVM* vm) {
    uint32_t h = vm->PopObject();
    Object* o = LookupObject(h);
    if (o) { vm->PushFloat(WorldX(o)); vm->PushFloat(WorldY(o)); vm->PushFloat(WorldZ(o)); }
    else   { vm->PushFloat(0); vm->PushFloat(0); vm->PushFloat(0); }
}

static void N_SET_POSITION(LHVM* vm) {
    float z = vm->PopFloat(), y = vm->PopFloat(), x = vm->PopFloat();
    uint32_t h = vm->PopObject();
    Object* o = LookupObject(h);
    if (!o) return;
    MapCoords c = MakeCoords(x, y, z);
    o->SetPos(c);
    o->obj_coords = c;
}

static void N_MOVE_GAME_THING(LHVM* vm) {
    // Stack (top-down): radius, z, y, x, object
    vm->PopFloat();  // radius — ignored, treated as teleport
    float z = vm->PopFloat(), y = vm->PopFloat(), x = vm->PopFloat();
    uint32_t h = vm->PopObject();
    Object* o = LookupObject(h);
    if (!o) return;
    MapCoords c = MakeCoords(x, y, z);
    o->SetPos(c);
    o->obj_coords = c;
}

// SCRIPT_OBJECT_TYPE → EntityCategory mapping (chlasm/ScriptEnums.h).
static EntityCategory CategoryForScriptType(int32_t script_type) {
    switch (script_type) {
    case 2:  return ENTITY_CAT_ABODE;       // ABODE
    case 4:                                  // VILLAGER
    case 5:  return ENTITY_CAT_VILLAGER;    // VILLAGER_CHILD
    case 6:                                  // ANIMAL
    case 21: return ENTITY_CAT_ANIMAL;      // BIRD
    case 8:  return ENTITY_CAT_MOBILE;      // MOBILE_STATIC
    case 47: return ENTITY_CAT_ROCK;        // ROCK
    case 12: return ENTITY_CAT_CREATURE;    // CREATURE
    case 22: return ENTITY_CAT_TREE;        // TREE
    case 49: return ENTITY_CAT_BONFIRE;     // BONFIRE (if defined)
    default: return ENTITY_CAT_FEATURE;     // safe fallback
    }
}

static void N_CREATE(LHVM* vm) {
    float z = vm->PopFloat(), y = vm->PopFloat(), x = vm->PopFloat();
    int32_t subtype = vm->PopInt();
    int32_t type    = vm->PopInt();
    (void)y;  // altitude is recomputed from terrain inside EntityFactory

    EntityCreateParams p = {};
    p.world_x   = x;
    p.world_z   = z;
    p.angle     = 0.0f;
    p.scale     = 1.0f;
    p.mesh_id   = 0;
    p.type_enum = static_cast<uint32_t>(subtype);
    p.type_name = "";

    Object* obj = EntityFactory::CreateEntity(CategoryForScriptType(type), p);
    uint32_t h = HandleFor(obj);
    NotifySpawn(h, obj, type, subtype, x, y, z);
    vm->PushObject(h);
}

static void N_OBJECT_DELETE(LHVM* vm) {
    vm->PopInt();  // 'with effect' flag — second arg in v1.0
    uint32_t h = vm->PopObject();
    Slot* s = SlotOf(h);
    if (!s) return;
    s->obj->ToBeDeleted(0);
    UnregisterObject(h);
}

static void N_THING_VALID(LHVM* vm) {
    uint32_t h = vm->PopObject();
    vm->PushBoolean(LookupObject(h) != nullptr);
}

static void N_IS_OF_TYPE(LHVM* vm) {
    int32_t  subtype = vm->PopInt();
    int32_t  type    = vm->PopInt();
    uint32_t h       = vm->PopObject();
    Object* o = LookupObject(h);
    if (!o) { vm->PushBoolean(false); return; }
    bool match = (static_cast<int32_t>(o->GetScriptObjectType()) == type);
    if (match && subtype != -1) {
        // Subtype check requires per-type info struct lookup — defer; the
        // type-only match is correct for ~90% of script queries.
    }
    vm->PushBoolean(match);
}

static void N_GET_PROPERTY(LHVM* vm) {
    int32_t  prop = vm->PopInt();
    uint32_t h    = vm->PopObject();
    Object* o = LookupObject(h);
    if (!o) { vm->PushFloat(0); return; }

    // Property IDs come from SCRIPT_OBJECT_PROPERTY_TYPE in the original.
    // Cover the most common ones used by Land1; rest fall through to 0.
    switch (prop) {
    case 1:  vm->PushFloat(o->life);                             return; // HEALTH
    case 2:  vm->PushFloat(o->scale);                            return; // SCALE
    case 3:  vm->PushFloat(o->y_angle);                          return; // Y_ANGLE
    case 4:  vm->PushFloat(WorldX(o));                           return; // X_POS
    case 5:  vm->PushFloat(WorldY(o));                           return; // Y_POS
    case 6:  vm->PushFloat(WorldZ(o));                           return; // Z_POS
    default: vm->PushFloat(0);                                   return;
    }
}

static void N_SET_PROPERTY(LHVM* vm) {
    float    val  = vm->PopFloat();
    int32_t  prop = vm->PopInt();
    uint32_t h    = vm->PopObject();
    Object* o = LookupObject(h);
    if (!o) return;
    switch (prop) {
    case 1:  o->SetLife(val); break;
    case 2:  o->scale  = val; break;
    case 3:  o->y_angle = val; break;
    default: break;
    }
}

static void N_GET_DISTANCE_OBJECT(LHVM* /*vm*/) {
    // GET_DISTANCE in v1.0 takes 6 floats (two positions); already wired.
    // Object-pair variant doesn't exist as its own native — left as a no-op
    // so the existing pos/pos implementation in LHVM.cpp continues to handle it.
}

static void N_GET_OBJECT_HAND_IS_OVER(LHVM* vm) {
    HandInfo h = CurrentHand();
    vm->PushObject(h.hover_object);
}

static void N_GET_HAND_POSITION(LHVM* vm) {
    HandInfo h = CurrentHand();
    vm->PushFloat(h.x); vm->PushFloat(h.y); vm->PushFloat(h.z);
}

static void N_GET_HAND_STATE(LHVM* vm) {
    HandInfo h = CurrentHand();
    vm->PushInt(h.state);
}

static void N_GET_LAND_HEIGHT(LHVM* vm) {
    float z = vm->PopFloat();
    float x = vm->PopFloat();
    vm->PushFloat(GetTerrainHeightAt(x, z));
}

static void N_SET_FOCUS(LHVM* vm) {
    // Sets a creature's focus to a position. No creature subsystem wiring yet
    // (chunk 3); just consume the args.
    vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); // z, y, x
    vm->PopObject();
}

static void N_SET_TARGET(LHVM* vm) {
    vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); // z, y, x
    vm->PopObject();
}

static void N_SET_HEADING_AND_SPEED(LHVM* vm) {
    float speed = vm->PopFloat();
    float z = vm->PopFloat(), y = vm->PopFloat(), x = vm->PopFloat();
    uint32_t h = vm->PopObject();
    Object* o = LookupObject(h);
    if (!o) return;
    // Compute heading angle and rotate towards target. Speed is stored on
    // the object's MobileWallHug if present; for now just face the target.
    float dx = x - WorldX(o);
    float dz = z - WorldZ(o);
    if (dx != 0.0f || dz != 0.0f) {
        o->y_angle = atan2f(dx, dz);
    }
    (void)speed; (void)y;  // y/speed wired in chunk 3 with movement system
}

static void N_GET_OBJECT_DESTINATION(LHVM* vm) {
    uint32_t h = vm->PopObject();
    Object* o = LookupObject(h);
    if (o) { vm->PushFloat(WorldX(o)); vm->PushFloat(WorldY(o)); vm->PushFloat(WorldZ(o)); }
    else   { vm->PushFloat(0); vm->PushFloat(0); vm->PushFloat(0); }
}

static void N_GET_OBJECT_STATE(LHVM* vm) {
    uint32_t h = vm->PopObject();
    Object* o = LookupObject(h);
    if (!o) { vm->PushInt(0); return; }
    // For Living-derived objects the state is action.top_state at offset 0x8C.
    // We don't have an IsLiving virtual on Object, so dispatch via the existing
    // virtual GetScriptObjectType to decide; living types have a small known
    // type-id range. Wired properly in chunk 3.
    vm->PushInt(0);
}

static void N_IS_LEASHED(LHVM* vm) {
    uint32_t h = vm->PopObject();
    Slot* s = SlotOf(h);
    vm->PushBoolean(s && (s->flags & FLAG_LEASHED));
}

static void N_IS_LEASHED_TO_OBJECT(LHVM* vm) {
    vm->PopObject();              // leash target — leash relationship not modelled yet
    uint32_t h = vm->PopObject(); // leashed object
    Slot* s = SlotOf(h);
    vm->PushBoolean(s && (s->flags & FLAG_LEASHED));
}

static void N_IS_FIGHTING(LHVM* vm) {
    uint32_t h = vm->PopObject();
    Slot* s = SlotOf(h);
    vm->PushBoolean(s && (s->flags & FLAG_FIGHTING));
}

// --- Resource ops --------------------------------------------------------
//
// Resources live on Abode/StoragePit/Pot/etc. and are scripted via JustAdd /
// JustRemoveResource on those types. For non-resource-bearing objects this
// is a logical no-op. We dispatch via Object's virtual GetResourceType when
// available; otherwise treat as zero.

static void N_GET_RESOURCE(LHVM* vm) {
    int32_t type = vm->PopInt();
    uint32_t h   = vm->PopObject();
    Object* o = LookupObject(h);
    if (!o) { vm->PushFloat(0); return; }
    // Object::GetDefaultResource returns a single value per object.
    // Type-keyed lookup requires the per-resource arrays on Abode/StoragePit;
    // that table walk is in chunk 2.
    (void)type;
    vm->PushFloat(static_cast<float>(o->GetDefaultResource()));
}

static void N_ADD_RESOURCE(LHVM* vm) {
    vm->PopFloat();   // amount
    vm->PopInt();     // type
    vm->PopObject();  // target — resource arrays accessed in chunk 2
}

static void N_REMOVE_RESOURCE(LHVM* vm) {
    vm->PopFloat(); vm->PopInt(); vm->PopObject();
}

// --- Status flag pairs ---------------------------------------------------

static void N_IS_ON_FIRE(LHVM* vm) {
    uint32_t h = vm->PopObject();
    Slot* s = SlotOf(h);
    vm->PushBoolean(s && (s->flags & FLAG_ON_FIRE));
}

static void N_IS_FIRE_NEAR(LHVM* vm) {
    float r = vm->PopFloat();
    float z = vm->PopFloat(), y = vm->PopFloat(), x = vm->PopFloat();
    (void)y;
    bool found = false;
    float r2 = r * r;
    for (size_t i = 1; i < g_slots.size(); i++) {
        const Slot& s = g_slots[i];
        if (!s.obj || !(s.flags & FLAG_ON_FIRE)) continue;
        float dx = WorldX(s.obj) - x, dz = WorldZ(s.obj) - z;
        if (dx*dx + dz*dz <= r2) { found = true; break; }
    }
    vm->PushBoolean(found);
}

static void N_SET_ON_FIRE(LHVM* vm) {
    vm->PopFloat();  // strength — no fire intensity model yet
    uint32_t h = vm->PopObject();
    Slot* s = SlotOf(h);
    if (s) s->flags |= FLAG_ON_FIRE;
}

static void N_IS_POISONED(LHVM* vm) {
    uint32_t h = vm->PopObject();
    Slot* s = SlotOf(h);
    vm->PushBoolean(s && (s->flags & FLAG_POISONED));
}

static void N_SET_POISONED(LHVM* vm) {
    vm->PopFloat();  // amount — no poison-per-tick model yet
    uint32_t h = vm->PopObject();
    Slot* s = SlotOf(h);
    if (s) s->flags |= FLAG_POISONED;
}

static void N_IS_SKELETON(LHVM* vm) {
    uint32_t h = vm->PopObject();
    Slot* s = SlotOf(h);
    vm->PushBoolean(s && (s->flags & FLAG_SKELETON));
}

static void N_SET_SKELETON(LHVM* vm) {
    bool on = vm->PopBoolean();
    uint32_t h = vm->PopObject();
    Slot* s = SlotOf(h);
    if (!s) return;
    if (on) s->flags |=  FLAG_SKELETON;
    else    s->flags &= ~FLAG_SKELETON;
}

static void N_SET_INDESTRUCTABLE(LHVM* vm) {
    bool on = vm->PopBoolean();
    uint32_t h = vm->PopObject();
    Slot* s = SlotOf(h);
    if (!s) return;
    if (on) s->flags |=  FLAG_INDESTRUCTABLE;
    else    s->flags &= ~FLAG_INDESTRUCTABLE;
}

static void N_SET_ID_MOVEABLE(LHVM* vm) {
    bool on = vm->PopBoolean();
    uint32_t h = vm->PopObject();
    Slot* s = SlotOf(h);
    if (!s) return;
    if (on) s->flags |=  FLAG_MOVEABLE;
    else    s->flags &= ~FLAG_MOVEABLE;
}

static void N_SET_ID_PICKUPABLE(LHVM* vm) {
    bool on = vm->PopBoolean();
    uint32_t h = vm->PopObject();
    Slot* s = SlotOf(h);
    if (!s) return;
    if (on) s->flags |=  FLAG_PICKUPABLE;
    else    s->flags &= ~FLAG_PICKUPABLE;
}

static void N_SET_ACTIVE(LHVM* vm) {
    bool on = vm->PopBoolean();
    uint32_t h = vm->PopObject();
    Slot* s = SlotOf(h);
    if (!s) return;
    if (on) s->flags |=  FLAG_ACTIVE;
    else    s->flags &= ~FLAG_ACTIVE;
}

static void N_IS_ACTIVE(LHVM* vm) {
    uint32_t h = vm->PopObject();
    Slot* s = SlotOf(h);
    vm->PushBoolean(s && (s->flags & FLAG_ACTIVE));
}

static void N_RELEASE_FROM_SCRIPT(LHVM* vm) {
    uint32_t h = vm->PopObject();
    Slot* s = SlotOf(h);
    if (s) s->flags |= FLAG_RELEASED;
}

static void N_IS_CREATURE_AVAILABLE(LHVM* vm) {
    vm->PopInt();  // creature type
    // Creature availability comes from Game::IsCreatureAvailable; defaults to
    // true so post-Land1 scripts can proceed. Refine in chunk 3.
    vm->PushBoolean(true);
}

// --- Influence / mana / belief / alignment -------------------------------

static void N_GET_INFLUENCE(LHVM* vm) {
    vm->PopInt();    // player
    vm->PopFloat();  // z
    vm->PopFloat();  // y
    vm->PopFloat();  // x
    // Influence map not yet wired (depends on Town::GetRadius walks).
    vm->PushFloat(0.0f);
}

static void N_GET_MANA(LHVM* vm) {
    vm->PopObject(); // player
    vm->PushFloat(100.0f);  // generous default until prayer-site economy lands
}

static void N_BELIEF_FOR_PLAYER(LHVM* vm) {
    vm->PopInt();      // player
    vm->PopObject();   // town
    vm->PushFloat(0.5f);
}

static void N_GET_ALIGNMENT(LHVM* vm) {
    vm->PopObject(); // player or creature
    vm->PushFloat(0.0f);  // neutral
}

static void N_SET_ALIGNMENT(LHVM* vm) {
    vm->PopFloat();
    vm->PopObject();
}

// --- Click state ---------------------------------------------------------

static void N_GAME_THING_CLICKED(LHVM* vm) {
    uint32_t h = vm->PopObject();
    ClickInfo c = CurrentClick();
    vm->PushBoolean(c.thing_clicked && c.clicked_object == h);
}

static void N_GET_OBJECT_CLICKED(LHVM* vm) {
    ClickInfo c = CurrentClick();
    vm->PushObject(c.thing_clicked ? c.clicked_object : 0);
}

static void N_POSITION_CLICKED(LHVM* vm) {
    float r  = vm->PopFloat();
    float z  = vm->PopFloat();
    float y  = vm->PopFloat();
    float x  = vm->PopFloat();
    (void)y;
    ClickInfo c = CurrentClick();
    if (!c.position_clicked) { vm->PushBoolean(false); return; }
    float dx = c.click_x - x, dz = c.click_z - z;
    vm->PushBoolean(dx*dx + dz*dz <= r * r);
}

static void N_CLEAR_CLICKED_OBJECT(LHVM* /*vm*/)   { ClearClickedObject(); }
static void N_CLEAR_CLICKED_POSITION(LHVM* /*vm*/) { ClearClickedPosition(); }

// --- Town queries --------------------------------------------------------

static void N_GET_TOWN_WITH_ID(LHVM* vm) {
    vm->PopInt();          // town id
    vm->PushObject(0);     // town registry not populated by EntityFactory yet
}

static void N_GET_NEAREST_TOWN_OF_PLAYER(LHVM* vm) {
    vm->PopInt();    // player
    vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); // z, y, x
    vm->PushObject(0);
}

static void N_GET_PLAYER_TOWN_TOTAL(LHVM* vm) {
    vm->PopInt();   // player
    vm->PushInt(0);
}

static void N_GET_DESIRE(LHVM* vm) {
    vm->PopInt();      // desire type
    uint32_t h = vm->PopObject();
    Object* o = LookupObject(h);
    (void)o;
    // Desires live on Living/Creature; returning 0 keeps "do nothing" as the
    // default reaction. Real wiring in chunk 3.
    vm->PushFloat(0.0f);
}

// ============================================================================
// Chunk 2 — flock subsystem, container iteration, spatial helpers
// ============================================================================
//
// The Flock entity owns its members through a LivingDLList linked-list, but
// wiring that up requires the Living node-prev/next plumbing. Until that
// arrives we keep a parallel side-table keyed by flock handle so the script
// view of membership is consistent with FLOCK_ATTACH/DETACH.

namespace {

std::unordered_map<uint32_t, std::vector<uint32_t>> g_flock_members;
std::unordered_map<uint32_t, uint32_t>              g_object_to_flock;

void FlockClear(uint32_t flock_h) {
    auto it = g_flock_members.find(flock_h);
    if (it == g_flock_members.end()) return;
    for (uint32_t m : it->second) g_object_to_flock.erase(m);
    g_flock_members.erase(it);
}

} // namespace

static void N_FLOCK_CREATE(LHVM* vm) {
    float z = vm->PopFloat(), y = vm->PopFloat(), x = vm->PopFloat();
    Flock* f = static_cast<Flock*>(calloc(1, sizeof(Flock)));
    if (!f) { vm->PushObject(0); return; }
    MapCoords c = MakeCoords(x, y, z);
    f->coords = c;
    f->SetDomainCentrePos(c);
    uint32_t h = RegisterObject(reinterpret_cast<Object*>(f));
    g_flock_members[h] = {};
    NotifySpawn(h, reinterpret_cast<Object*>(f), 11 /* SCRIPT_OBJECT_TYPE_FLOCK */, 0, x, y, z);
    vm->PushObject(h);
}

static void N_FLOCK_ATTACH(LHVM* vm) {
    vm->PopBoolean();  // 'as leader' — leader role unmodelled for now
    uint32_t member = vm->PopObject();
    uint32_t flock  = vm->PopObject();
    if (!flock || !member) return;
    auto& members = g_flock_members[flock];
    for (uint32_t m : members) if (m == member) return;
    members.push_back(member);
    g_object_to_flock[member] = flock;
}

static void N_FLOCK_DETACH(LHVM* vm) {
    uint32_t member = vm->PopObject();
    uint32_t flock  = vm->PopObject();
    auto it = g_flock_members.find(flock);
    if (it == g_flock_members.end()) return;
    auto& v = it->second;
    for (auto i = v.begin(); i != v.end(); ++i) {
        if (*i == member) { v.erase(i); break; }
    }
    g_object_to_flock.erase(member);
}

static void N_FLOCK_DISBAND(LHVM* vm) {
    uint32_t flock = vm->PopObject();
    FlockClear(flock);
    Object* o = LookupObject(flock);
    if (o) {
        free(o);
        UnregisterObject(flock);
    }
}

static void N_FLOCK_MEMBER(LHVM* vm) {
    int32_t  index = vm->PopInt();
    uint32_t flock = vm->PopObject();
    auto it = g_flock_members.find(flock);
    if (it == g_flock_members.end() || index < 0 ||
        static_cast<size_t>(index) >= it->second.size()) {
        vm->PushObject(0); return;
    }
    vm->PushObject(it->second[index]);
}

static void N_FLOCK_WITHIN_LIMITS(LHVM* vm) {
    vm->PopObject();
    vm->PushBoolean(true);  // domain-radius check requires Flock::domain_radius wiring
}

static void N_GET_OBJECT_FLOCK(LHVM* vm) {
    uint32_t obj = vm->PopObject();
    auto it = g_object_to_flock.find(obj);
    vm->PushObject(it == g_object_to_flock.end() ? 0 : it->second);
}

static void N_ID_SIZE(LHVM* vm) {
    uint32_t h = vm->PopObject();
    auto it = g_flock_members.find(h);
    vm->PushInt(it == g_flock_members.end()
                    ? 0
                    : static_cast<int32_t>(it->second.size()));
}

static void N_GET_FIRST_IN_CONTAINER(LHVM* vm) {
    uint32_t h = vm->PopObject();
    auto it = g_flock_members.find(h);
    vm->PushObject((it == g_flock_members.end() || it->second.empty())
                       ? 0
                       : it->second.front());
}

static void N_GET_NEXT_IN_CONTAINER(LHVM* vm) {
    uint32_t prev = vm->PopObject();
    uint32_t cont = vm->PopObject();
    auto it = g_flock_members.find(cont);
    if (it == g_flock_members.end()) { vm->PushObject(0); return; }
    const auto& v = it->second;
    for (size_t i = 0; i < v.size(); i++) {
        if (v[i] == prev && i + 1 < v.size()) { vm->PushObject(v[i+1]); return; }
    }
    vm->PushObject(0);
}

// --- Object-creation helpers --------------------------------------------

static void N_CREATE_REWARD(LHVM* vm) {
    float z = vm->PopFloat(), y = vm->PopFloat(), x = vm->PopFloat();
    int32_t reward_type = vm->PopInt();
    EntityCreateParams p = {};
    p.world_x = x; p.world_z = z; p.scale = 1.0f;
    p.type_enum = static_cast<uint32_t>(reward_type);
    (void)y;
    Object* obj = EntityFactory::CreateEntity(ENTITY_CAT_FEATURE, p);
    uint32_t h = HandleFor(obj);
    NotifySpawn(h, obj, 7 /* REWARD */, reward_type, x, y, z);
    vm->PushObject(h);
}

static void N_CREATE_REWARD_IN_TOWN(LHVM* vm) {
    vm->PopObject();   // town
    vm->PopInt();      // reward type
    // Town anchor + reward materialisation arrives with the town registry.
    vm->PushObject(0);
}

static void N_CREATE_RANDOM_VILLAGER_OF_TRIBE(LHVM* vm) {
    int32_t tribe = vm->PopInt();
    float z = vm->PopFloat(), y = vm->PopFloat(), x = vm->PopFloat();
    (void)y;
    EntityCreateParams p = {};
    p.world_x = x; p.world_z = z; p.scale = 1.0f;
    p.type_enum = static_cast<uint32_t>(tribe);
    Object* obj = EntityFactory::CreateEntity(ENTITY_CAT_VILLAGER, p);
    uint32_t h = HandleFor(obj);
    NotifySpawn(h, obj, 4 /* VILLAGER */, tribe, x, y, z);
    vm->PushObject(h);
}

static void N_CREATE_MIST(LHVM* vm) {
    // 7 floats: x, y, z, plus 4 mist parameters (radius, density, speed, life)
    for (int i = 0; i < 7; i++) vm->PopFloat();
    vm->PushObject(0);  // Mist allocation deferred until weather subsystem
}

static void N_LOAD_CREATURE(LHVM* vm) {
    int32_t  ctype = vm->PopInt();
    float z = vm->PopFloat(), y = vm->PopFloat(), x = vm->PopFloat();
    vm->PopObject();
    (void)y;
    EntityCreateParams p = {};
    p.world_x = x; p.world_z = z; p.scale = 5.0f;
    Object* obj = EntityFactory::CreateEntity(ENTITY_CAT_CREATURE, p);
    uint32_t h = HandleFor(obj);
    NotifySpawn(h, obj, 12 /* CREATURE */, ctype, x, y, z);
    vm->PushObject(h);
}

static void N_LOAD_MY_CREATURE(LHVM* vm) {
    float z = vm->PopFloat(), y = vm->PopFloat(), x = vm->PopFloat();
    vm->PopObject();
    (void)y;
    EntityCreateParams p = {};
    p.world_x = x; p.world_z = z; p.scale = 5.0f;
    Object* obj = EntityFactory::CreateEntity(ENTITY_CAT_CREATURE, p);
    uint32_t h = HandleFor(obj);
    NotifySpawn(h, obj, 12 /* CREATURE */, 0, x, y, z);
    vm->PushObject(h);
}

// --- Capacity / state queries -------------------------------------------

static void N_OBJECT_CAPACITY(LHVM* vm) {
    vm->PopObject();
    vm->PushInt(0);  // wired in chunk 7 with Abode::GetMaxOccupants
}

static void N_OBJECT_ADULT_CAPACITY(LHVM* vm) {
    vm->PopObject();
    vm->PushInt(0);
}

static void N_ID_ADULT_SIZE(LHVM* vm) {
    uint32_t h = vm->PopObject();
    auto it = g_flock_members.find(h);
    vm->PushInt(it == g_flock_members.end()
                    ? 0
                    : static_cast<int32_t>(it->second.size()));
}

static void N_INSIDE_TEMPLE(LHVM* vm) {
    vm->PopObject();
    vm->PushBoolean(false);  // citadel-interior tracking unwired
}

static void N_IS_AFFECTED_BY_SPELL(LHVM* vm) {
    vm->PopInt();
    vm->PopObject();
    vm->PushBoolean(false);
}

static void N_IS_AUTO_FIGHTING(LHVM* vm) {
    uint32_t h = vm->PopObject();
    Slot* s = SlotOf(h);
    vm->PushBoolean(s && (s->flags & FLAG_FIGHTING));
}

static void N_IS_SPELL_CHARGING(LHVM* vm) {
    vm->PopObject();
    vm->PushBoolean(false);
}

static void N_IS_THAT_SPELL_CHARGING(LHVM* vm) {
    vm->PopInt();
    vm->PopObject();
    vm->PushBoolean(false);
}

static void N_POS_VALID_FOR_CREATURE(LHVM* vm) {
    float z = vm->PopFloat(), y = vm->PopFloat(), x = vm->PopFloat();
    (void)y;
    // Reject positions below sea level; everything else is fine until the
    // creature pathfinding mesh lands.
    vm->PushBoolean(GetTerrainHeightAt(x, z) > 0.5f);
}

// --- Position queries on objects ----------------------------------------

static void N_GET_TEMPLE_POSITION(LHVM* vm) {
    uint32_t h = vm->PopObject();
    Object* o = LookupObject(h);
    if (o) { vm->PushFloat(WorldX(o)); vm->PushFloat(WorldY(o)); vm->PushFloat(WorldZ(o)); }
    else   { vm->PushFloat(0); vm->PushFloat(0); vm->PushFloat(0); }
}

static void N_GET_TEMPLE_ENTRANCE_POSITION(LHVM* vm) {
    uint32_t h = vm->PopObject();
    Object* o = LookupObject(h);
    // Entrance is offset from the citadel origin; without a CitadelEntrance
    // walk we approximate as the centre.
    if (o) { vm->PushFloat(WorldX(o)); vm->PushFloat(WorldY(o)); vm->PushFloat(WorldZ(o)); }
    else   { vm->PushFloat(0); vm->PushFloat(0); vm->PushFloat(0); }
}

static void N_GET_LAST_SPELL_CAST_POS(LHVM* vm) {
    vm->PopObject();
    vm->PushFloat(0); vm->PushFloat(0); vm->PushFloat(0);
}

static void N_GET_FACING_CAMERA_POSITION(LHVM* vm) {
    float dist = vm->PopFloat();
    float z = vm->PopFloat(), y = vm->PopFloat(), x = vm->PopFloat();
    (void)dist;
    // Pass-through until the camera basis is exposed: anchor at the input pos.
    vm->PushFloat(x); vm->PushFloat(y); vm->PushFloat(z);
}

// --- Computer-player position helpers (logical only) --------------------

static void N_GET_COMPUTER_PLAYER_POSITION(LHVM* vm) {
    uint32_t h = vm->PopObject();
    Object* o = LookupObject(h);
    if (o) { vm->PushFloat(WorldX(o)); vm->PushFloat(WorldY(o)); vm->PushFloat(WorldZ(o)); }
    else   { vm->PushFloat(0); vm->PushFloat(0); vm->PushFloat(0); }
}

static void N_SET_COMPUTER_PLAYER_POSITION(LHVM* vm) {
    float z = vm->PopFloat(), y = vm->PopFloat(), x = vm->PopFloat();
    uint32_t h = vm->PopObject();
    Object* o = LookupObject(h);
    if (o) { o->SetPos(MakeCoords(x, y, z)); o->obj_coords = MakeCoords(x, y, z); }
}

static void N_MOVE_COMPUTER_PLAYER_POSITION(LHVM* vm) {
    vm->PopFloat();   // speed
    float z = vm->PopFloat(), y = vm->PopFloat(), x = vm->PopFloat();
    uint32_t h = vm->PopObject();
    Object* o = LookupObject(h);
    if (o) { o->SetPos(MakeCoords(x, y, z)); o->obj_coords = MakeCoords(x, y, z); }
}

// --- Misc object queries ------------------------------------------------

static void N_RESTART_OBJECT(LHVM* vm) {
    uint32_t h = vm->PopObject();
    Object* o = LookupObject(h);
    if (o) { o->life = 1.0f; o->SetLife(1.0f); }
}

static void N_OBJECT_CAST_BY_OBJECT(LHVM* vm) {
    vm->PopObject();   // potentially-cast-by
    vm->PopObject();   // target
    vm->PushBoolean(false);  // spell-cast attribution unwired
}

static void N_OPPOSING_CREATURE(LHVM* vm) {
    vm->PopObject();
    vm->PushObject(0);
}

static void N_GET_DEAD_LIVING(LHVM* vm) {
    vm->PopObject();
    vm->PushObject(0);
}

static void N_GET_FIRST_HELP(LHVM* vm) { vm->PopObject(); vm->PushObject(0); }
static void N_GET_LAST_HELP(LHVM* vm)  { vm->PopObject(); vm->PushObject(0); }
static void N_GET_HELP(LHVM* vm)       { vm->PopObject(); vm->PushInt(0); }

static void N_OBJECT_RELATIVE_BELIEF(LHVM* vm) {
    vm->PopObject(); vm->PopObject();
    vm->PushFloat(0.5f);
}

static void N_GET_TOTEM_STATUE(LHVM* vm) {
    vm->PopObject();
    vm->PushObject(0);  // worship-site totem lookup pending
}

static void N_GET_SPELL_ICON_IN_TEMPLE(LHVM* vm) {
    vm->PopInt(); vm->PopObject();
    vm->PushObject(0);
}

static void N_WITHIN_ROTATION(LHVM* vm) {
    float tolerance = vm->PopFloat();
    float target    = vm->PopFloat();
    uint32_t h      = vm->PopObject();
    Object* o = LookupObject(h);
    if (!o) { vm->PushBoolean(false); return; }
    float diff = fabsf(o->y_angle - target);
    if (diff > 3.14159265f) diff = 6.28318531f - diff;
    vm->PushBoolean(diff <= tolerance);
}

// --- Town-aggregate queries ---------------------------------------------

static void N_GET_TOWN_WORSHIP_DEATHS(LHVM* vm) {
    vm->PopObject();
    vm->PushFloat(0);
}

static void N_GET_TOWN_AND_VILLAGER_HEALTH(LHVM* vm) {
    vm->PopObject();
    vm->PushFloat(100.0f);
}

static void N_GET_SACRIFICE_TOTAL2(LHVM* vm) {
    vm->PopObject();
    vm->PushFloat(0);
}

static void N_GAME_ADD_FOR_BUILDING2(LHVM* vm) {
    vm->PopFloat(); vm->PopObject();
}

// --- Spell-charge / temple state ----------------------------------------

static void N_PLAYER_SPELL_CAST_TIME(LHVM* vm) {
    vm->PopInt(); vm->PopObject();
    vm->PushFloat(0);
}

static void N_PLAYER_SPELL_LAST_CAST(LHVM* vm) {
    vm->PopInt(); vm->PopObject();
    vm->PushFloat(0);
}

static void N_GET_MANA_FOR_SPELL(LHVM* vm) {
    vm->PopInt(); vm->PopObject();
    vm->PushFloat(50.0f);
}

// --- Attribute mutators that touch existing flags -----------------------

static void N_SET_CREATURE_AUTO_FIGHTING(LHVM* vm) {
    bool on = vm->PopBoolean();
    uint32_t h = vm->PopObject();
    Slot* s = SlotOf(h);
    if (!s) return;
    if (on) s->flags |=  FLAG_FIGHTING;
    else    s->flags &= ~FLAG_FIGHTING;
}

static void N_SET_FIGHT_EXIT(LHVM* vm) {
    uint32_t h = vm->PopObject();
    Slot* s = SlotOf(h);
    if (s) s->flags &= ~FLAG_FIGHTING;
}

static void N_SET_CAN_BUILD_WORSHIPSITE(LHVM* vm) {
    vm->PopBoolean(); vm->PopObject();
}

static void N_SET_MAGIC_IN_OBJECT(LHVM* vm) {
    vm->PopBoolean(); vm->PopInt(); vm->PopObject();
}

static void N_SET_MAGIC_PROPERTIES(LHVM* vm) {
    vm->PopFloat(); vm->PopInt(); vm->PopObject();
}

// ============================================================================
// Chunk 3 — creature mind / belief / desire (50)
// ============================================================================
//
// The 135KB CreatureMental struct will hold all of this in time, but until
// the Living state machine and Creature::Process pull from it, we stage the
// values in script-visible side-tables so SET → GET round-trips and
// "is desire X above threshold" queries stay self-consistent.

namespace {

struct CreatureMind {
    std::unordered_map<int32_t, float>   desire_value;
    std::unordered_map<int32_t, float>   desire_maximum;
    std::unordered_map<int32_t, bool>    desire_active;
    std::unordered_map<int32_t, float>   agenda_priority;
    std::unordered_map<int32_t, float>   distinction;
    std::unordered_map<int64_t, float>   action_knowledge;       // (type<<32)|subtype → value
    std::unordered_map<int32_t, int32_t> action_perform_count;   // action type → count
    int32_t  only_desire        = -1;
    bool     learn_everything   = false;
    bool     in_dev_script      = false;
    bool     auto_scale         = false;
    bool     creature_help_enabled = true;
    int32_t  player_handle      = 0;
    uint32_t leashed_to_handle  = 0;
    uint32_t interacting_with   = 0;
    int32_t  fight_move_queued  = 0;
    int32_t  fight_spell_queued = 0;
    int32_t  fight_step_queued  = 0;
    int32_t  fight_action       = 0;
    int32_t  dev_stage          = 0;
    int32_t  reaction           = -1;
    int32_t  name_string_id     = 0;
    bool     sound_on           = true;
    bool     in_temple          = false;
    float    home_x = 0, home_y = 0, home_z = 0;
    float    creed_a = 0, creed_b = 0;
    float    object_belief_scale = 1.0f;
    bool     leash_works        = true;
};

std::unordered_map<uint32_t, CreatureMind> g_minds;

CreatureMind& MindFor(uint32_t handle) { return g_minds[handle]; }

inline int64_t ActionKey(int32_t type, int32_t subtype) {
    return (static_cast<int64_t>(type) << 32) | static_cast<uint32_t>(subtype);
}

} // namespace

// --- Learning ------------------------------------------------------------

static void N_CREATURE_LEARN_EVERYTHING(LHVM* vm) {
    uint32_t h = vm->PopObject();
    if (h) MindFor(h).learn_everything = true;
}

static void N_CREATURE_LEARN_EVERYTHING_EXCLUDING(LHVM* vm) {
    int32_t excluded = vm->PopInt();
    uint32_t h = vm->PopObject();
    if (!h) return;
    auto& m = MindFor(h);
    m.learn_everything = true;
    m.action_knowledge.erase(ActionKey(excluded, 0));
}

static void N_CREATURE_SET_KNOWS_ACTION(LHVM* vm) {
    float    know    = vm->PopFloat();
    int32_t  subtype = vm->PopInt();
    int32_t  type    = vm->PopInt();
    uint32_t h       = vm->PopObject();
    if (h) MindFor(h).action_knowledge[ActionKey(type, subtype)] = know;
}

static void N_CREATURE_LEARN_DISTINCTION(LHVM* vm) {
    float    value = vm->PopFloat();
    int32_t  type  = vm->PopInt();
    uint32_t h     = vm->PopObject();
    if (h) MindFor(h).distinction[type] = value;
}

// --- Desires / agenda ----------------------------------------------------

static void N_CREATURE_SET_AGENDA_PRIORITY(LHVM* vm) {
    float    pri  = vm->PopFloat();
    int32_t  type = vm->PopInt();
    uint32_t h    = vm->PopObject();
    if (h) MindFor(h).agenda_priority[type] = pri;
}

static void N_CREATURE_TURN_OFF_ALL_DESIRES(LHVM* vm) {
    uint32_t h = vm->PopObject();
    if (!h) return;
    auto& m = MindFor(h);
    for (auto& kv : m.desire_active) kv.second = false;
}

static void N_CREATURE_SET_DESIRE_VALUE(LHVM* vm) {
    float    val  = vm->PopFloat();
    int32_t  type = vm->PopInt();
    uint32_t h    = vm->PopObject();
    if (h) MindFor(h).desire_value[type] = val;
}

static void N_CREATURE_SET_DESIRE_ACTIVATED(LHVM* vm) {
    bool     on   = vm->PopBoolean();
    int32_t  type = vm->PopInt();
    uint32_t h    = vm->PopObject();
    if (h) MindFor(h).desire_active[type] = on;
}

static void N_CREATURE_SET_DESIRE_MAXIMUM(LHVM* vm) {
    float    mx   = vm->PopFloat();
    int32_t  type = vm->PopInt();
    uint32_t h    = vm->PopObject();
    if (h) MindFor(h).desire_maximum[type] = mx;
}

static void N_CREATURE_DESIRE_IS(LHVM* vm) {
    int32_t  type = vm->PopInt();
    uint32_t h    = vm->PopObject();
    if (!h) { vm->PushFloat(0); return; }
    auto& m = MindFor(h);
    auto it = m.desire_value.find(type);
    vm->PushFloat(it == m.desire_value.end() ? 0.0f : it->second);
}

static void N_SET_CREATURE_ONLY_DESIRE(LHVM* vm) {
    int32_t  desire = vm->PopInt();
    uint32_t h      = vm->PopObject();
    if (h) MindFor(h).only_desire = desire;
}

static void N_SET_CREATURE_ONLY_DESIRE_OFF(LHVM* vm) {
    uint32_t h = vm->PopObject();
    if (h) MindFor(h).only_desire = -1;
}

// --- Actions / counts ----------------------------------------------------

static void N_CREATURE_DO_ACTION(LHVM* vm) {
    vm->PopObject();   // target
    int32_t  action = vm->PopInt();
    uint32_t h      = vm->PopObject();
    if (h) MindFor(h).action_perform_count[action] += 1;
}

static void N_CREATURE_INITIALISE_NUM_TIMES(LHVM* vm) {
    int32_t  action = vm->PopInt();
    uint32_t h      = vm->PopObject();
    if (h) MindFor(h).action_perform_count[action] = 0;
}

static void N_CREATURE_GET_NUM_TIMES(LHVM* vm) {
    int32_t  action = vm->PopInt();
    uint32_t h      = vm->PopObject();
    if (!h) { vm->PushInt(0); return; }
    auto& counts = MindFor(h).action_perform_count;
    auto it = counts.find(action);
    vm->PushInt(it == counts.end() ? 0 : it->second);
}

static void N_CREATURE_FORCE_FINISH(LHVM* vm) {
    vm->PopObject();  // creature — clearing the current action requires
                      // the LivingAction state machine, deferred.
}

static void N_CALL_PLAYER_CREATURE(LHVM* vm) {
    vm->PopObject();
    // Calling the player's creature back home is a navigation issue — the
    // creature object isn't tracked per-player yet, so this is a logical no-op.
}

// --- Configuration -------------------------------------------------------

static void N_CREATURE_SET_PLAYER(LHVM* vm) {
    int32_t  player = vm->PopInt();    // player handle (or index)
    uint32_t h      = vm->PopObject();
    if (h) MindFor(h).player_handle = player;
}

static void N_SET_CREATURE_HOME(LHVM* vm) {
    float z = vm->PopFloat(), y = vm->PopFloat(), x = vm->PopFloat();
    uint32_t h = vm->PopObject();
    if (!h) return;
    auto& m = MindFor(h);
    m.home_x = x; m.home_y = y; m.home_z = z;
}

static void N_SET_CREATURE_NAME(LHVM* vm) {
    int32_t  name_id = vm->PopInt();
    uint32_t h       = vm->PopObject();
    if (h) MindFor(h).name_string_id = name_id;
}

static void N_SET_CREATURE_HELP(LHVM* vm) {
    int32_t  level = vm->PopInt();
    uint32_t h     = vm->PopObject();
    if (h) MindFor(h).creature_help_enabled = (level != 0);
}

static void N_SET_CREATURE_DEV_STAGE(LHVM* vm) {
    int32_t  stage = vm->PopInt();
    uint32_t h     = vm->PopObject();
    if (h) MindFor(h).dev_stage = stage;
}

static void N_SET_CREATURE_SOUND(LHVM* vm) {
    bool     on = vm->PopBoolean();
    uint32_t h  = vm->PopObject();
    if (h) MindFor(h).sound_on = on;
}

static void N_SET_CREATURE_IN_TEMPLE(LHVM* vm) {
    bool     on = vm->PopBoolean();
    uint32_t h  = vm->PopObject();
    if (h) MindFor(h).in_temple = on;
}

static void N_CREATURE_AUTOSCALE(LHVM* vm) {
    bool     on = vm->PopBoolean();
    uint32_t h  = vm->PopObject();
    if (h) MindFor(h).auto_scale = on;
}

static void N_SET_CREATURE_CREED_PROPERTIES(LHVM* vm) {
    float b = vm->PopFloat(), a = vm->PopFloat();
    uint32_t h = vm->PopObject();
    if (h) { auto& m = MindFor(h); m.creed_a = a; m.creed_b = b; }
}

static void N_SET_OBJECT_BELIEF_SCALE(LHVM* vm) {
    float    scale = vm->PopFloat();
    uint32_t h     = vm->PopObject();
    if (h) MindFor(h).object_belief_scale = scale;
}

// --- State queries -------------------------------------------------------

static void N_CREATURE_REACTION(LHVM* vm) {
    int32_t  reaction = vm->PopInt();
    uint32_t h        = vm->PopObject();
    if (h) MindFor(h).reaction = reaction;
}

static void N_CREATURE_IN_DEV_SCRIPT(LHVM* vm) {
    bool     on = vm->PopBoolean();
    uint32_t h  = vm->PopObject();
    if (h) MindFor(h).in_dev_script = on;
}

static void N_CREATURE_FORCE_FRIENDS(LHVM* vm) {
    vm->PopObject(); vm->PopObject();
    // Bilateral friendship — flag both creatures fighting=false in chunk 3
    // would require resolving both handles; we leave the existing behaviour
    // (no fight state set) since CreatureAttitudeToPlayer isn't wired yet.
}

static void N_CREATURE_INTERACTING_WITH(LHVM* vm) {
    uint32_t h = vm->PopObject();
    if (!h) { vm->PushBoolean(false); return; }
    vm->PushBoolean(MindFor(h).interacting_with != 0);
}

static void N_CREATURE_SPELL_REVERSION(LHVM* vm) {
    vm->PopBoolean(); vm->PopObject();
    // Spell reversion toggles whether learned spells revert on use — the
    // CreatureLearning slot for that flag isn't surfaced yet, so we accept
    // and discard the value.
}

static void N_SWAP_CREATURE(LHVM* vm) {
    uint32_t b = vm->PopObject();
    uint32_t a = vm->PopObject();
    auto ia = g_minds.find(a);
    auto ib = g_minds.find(b);
    if (ia != g_minds.end() && ib != g_minds.end()) std::swap(ia->second, ib->second);
}

static void N_CREATURE_CREATE_RELATIVE(LHVM* vm) {
    vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat();
    uint32_t parent = vm->PopObject();
    Object* p = LookupObject(parent);
    EntityCreateParams pr = {};
    if (p) { pr.world_x = WorldX(p); pr.world_z = WorldZ(p); }
    pr.scale = 5.0f;
    Object* obj = EntityFactory::CreateEntity(ENTITY_CAT_CREATURE, pr);
    uint32_t h = HandleFor(obj);
    NotifySpawn(h, obj, 12 /* CREATURE */, 0, pr.world_x, 0, pr.world_z);
    vm->PushObject(h);
}

// --- Fight queue ---------------------------------------------------------

static void N_SET_CREATURE_QUEUE_FIGHT_MOVE(LHVM* vm) {
    int32_t  mv = vm->PopInt();
    uint32_t h  = vm->PopObject();
    if (h) MindFor(h).fight_move_queued = mv;
}

static void N_SET_CREATURE_QUEUE_FIGHT_SPELL(LHVM* vm) {
    int32_t  sp = vm->PopInt();
    uint32_t h  = vm->PopObject();
    if (h) MindFor(h).fight_spell_queued = sp;
}

static void N_SET_CREATURE_QUEUE_FIGHT_STEP(LHVM* vm) {
    int32_t  st = vm->PopInt();
    uint32_t h  = vm->PopObject();
    if (h) MindFor(h).fight_step_queued = st;
}

static void N_GET_CREATURE_FIGHT_ACTION(LHVM* vm) {
    uint32_t h = vm->PopObject();
    if (!h) { vm->PushInt(0); return; }
    vm->PushInt(MindFor(h).fight_action);
}

static void N_CREATURE_FIGHT_QUEUE_HITS(LHVM* vm) {
    int32_t  hits = vm->PopInt();
    uint32_t h    = vm->PopObject();
    if (h) MindFor(h).fight_action = hits;
}

// --- Hand / leash --------------------------------------------------------

static void N_IN_CREATURE_HAND(LHVM* vm) {
    uint32_t obj      = vm->PopObject();
    uint32_t creature = vm->PopObject();
    if (!creature) { vm->PushBoolean(false); return; }
    vm->PushBoolean(MindFor(creature).interacting_with == obj && obj != 0);
}

static void N_SET_LEASH_WORKS(LHVM* vm) {
    bool     on = vm->PopBoolean();
    uint32_t h  = vm->PopObject();
    if (h) MindFor(h).leash_works = on;
}

static void N_ATTACH_OBJECT_LEASH_TO_OBJECT(LHVM* vm) {
    uint32_t target  = vm->PopObject();
    uint32_t leashed = vm->PopObject();
    if (!leashed) return;
    Slot* s = SlotOf(leashed);
    if (s) s->flags |= FLAG_LEASHED;
    MindFor(leashed).leashed_to_handle = target;
}

static void N_ATTACH_OBJECT_LEASH_TO_HAND(LHVM* vm) {
    uint32_t leashed = vm->PopObject();
    if (!leashed) return;
    Slot* s = SlotOf(leashed);
    if (s) s->flags |= FLAG_LEASHED;
    MindFor(leashed).leashed_to_handle = 0;  // 0 = the hand
}

static void N_DETACH_OBJECT_LEASH(LHVM* vm) {
    uint32_t leashed = vm->PopObject();
    if (!leashed) return;
    Slot* s = SlotOf(leashed);
    if (s) s->flags &= ~FLAG_LEASHED;
    g_minds[leashed].leashed_to_handle = 0;
}

// --- Player-belief / desire-boost ---------------------------------------

static void N_SET_PLAYER_BELIEF(LHVM* vm) {
    vm->PopFloat();   // belief value
    vm->PopObject();  // town
    vm->PopObject();  // player
    // Real BELIEF setting goes through Town::SetBeliefInPlayer (already
    // implemented). Without a town registry we can't resolve which Town
    // owns this handle yet, so this stays logical until chunk 7.
}

static void N_SET_TOWN_DESIRE_BOOST(LHVM* vm) {
    vm->PopFloat(); vm->PopInt(); vm->PopObject();
}

static void N_CLEAR_ACTOR_MIND(LHVM* vm) {
    uint32_t h = vm->PopObject();
    g_minds.erase(h);
}

// --- Profile/training queries -------------------------------------------

static void N_CAN_SKIP_CREATURE_TRAINING(LHVM* vm)   { vm->PushBoolean(true); }
static void N_IS_KEEPING_OLD_CREATURE(LHVM* vm)       { vm->PushBoolean(false); }
static void N_CURRENT_PROFILE_HAS_CREATURE(LHVM* vm)  { vm->PushBoolean(false); }

static void N_GET_TARGET_OBJECT(LHVM* vm) {
    uint32_t h = vm->PopObject();
    if (!h) { vm->PushObject(0); return; }
    vm->PushObject(MindFor(h).interacting_with);
}

// ============================================================================
// Chunk 4 — spells / magic / weather (50)
// ============================================================================
//
// Spells in BW dispatch through MagicEffect/Spell objects. Until the spell
// hierarchy is wired to renders + impacts, scripts use these natives to
// "cast logically" — we record what was cast, where, and on whom so that
// downstream queries (IS_AFFECTED_BY_SPELL, last-cast-pos, charging state)
// can answer truthfully.

namespace {

struct SpellRecord {
    int32_t  spell_id;
    int32_t  target_player;
    uint32_t target_object;
    float    x, y, z;
    float    radius;
    float    cast_time;     // game seconds when last cast
};

std::unordered_map<uint32_t, std::vector<SpellRecord>> g_player_last_spell;  // per-player log
std::unordered_map<uint32_t, std::unordered_map<int32_t, bool>> g_object_spell_active;
std::unordered_map<uint32_t, float> g_player_wind_resistance;
std::unordered_map<uint32_t, std::unordered_map<int32_t, bool>> g_player_magic_enabled;
std::unordered_map<uint32_t, bool> g_player_spell_charging;

bool g_climate_paused      = false;
bool g_storms_paused       = false;
bool g_alignment_music_on  = true;
bool g_graphics_clipping   = false;
float g_clip_x = 0, g_clip_y = 0, g_clip_w = 0, g_clip_h = 0;
float g_weather_a = 0, g_weather_b = 0, g_weather_c = 0;
float g_cloud_a = 0,   g_cloud_b = 0,   g_cloud_c = 0;
float g_land_balance = 0.5f;

void RecordSpell(uint32_t player, int32_t spell, uint32_t target_obj,
                 float x, float y, float z, float radius) {
    SpellRecord r;
    r.spell_id     = spell;
    r.target_player= 0;
    r.target_object= target_obj;
    r.x = x; r.y = y; r.z = z;
    r.radius      = radius;
    r.cast_time   = 0;
    g_player_last_spell[player].push_back(r);
    if (target_obj) g_object_spell_active[target_obj][spell] = true;
}

} // namespace

// --- Spell casting -------------------------------------------------------

static void N_SPELL_AT_THING(LHVM* vm) {
    float    duration = vm->PopFloat();
    float    radius   = vm->PopFloat();
    float    z = vm->PopFloat(), y = vm->PopFloat(), x = vm->PopFloat();
    uint32_t target   = vm->PopObject();
    int32_t  spell    = vm->PopInt();
    uint32_t player   = vm->PopObject();
    (void)duration;
    RecordSpell(player, spell, target, x, y, z, radius);
    vm->PushObject(0);  // returns the new spell instance — none allocated yet
}

static void N_SPELL_AT_POS(LHVM* vm) {
    float    duration = vm->PopFloat();
    float    radius   = vm->PopFloat();
    float    z = vm->PopFloat(), y = vm->PopFloat(), x = vm->PopFloat();
    int32_t  spell    = vm->PopInt();
    uint32_t player   = vm->PopObject();
    (void)duration;
    RecordSpell(player, spell, 0, x, y, z, radius);
    vm->PushObject(0);
}

static void N_SPELL_AT_POINT(LHVM* vm) {
    float    radius = vm->PopFloat();
    float    z = vm->PopFloat(), y = vm->PopFloat(), x = vm->PopFloat();
    int32_t  spell  = vm->PopInt();
    uint32_t player = vm->PopObject();
    RecordSpell(player, spell, 0, x, y, z, radius);
    vm->PushObject(0);
}

static void N_SET_MAGIC_RADIUS(LHVM* vm) {
    float r = vm->PopFloat();
    uint32_t obj = vm->PopObject();
    (void)r; (void)obj;
}

static void N_SET_PLAYER_MAGIC(LHVM* vm) {
    bool     on = vm->PopBoolean();
    int32_t  magic = vm->PopInt();
    uint32_t player = vm->PopObject();
    g_player_magic_enabled[player][magic] = on;
}

static void N_HAS_PLAYER_MAGIC(LHVM* vm) {
    int32_t  magic = vm->PopInt();
    uint32_t player = vm->PopObject();
    auto pit = g_player_magic_enabled.find(player);
    if (pit == g_player_magic_enabled.end()) { vm->PushBoolean(false); return; }
    auto mit = pit->second.find(magic);
    vm->PushBoolean(mit != pit->second.end() && mit->second);
}

static void N_CLEAR_PLAYER_SPELL_CHARGING(LHVM* vm) {
    uint32_t player = vm->PopObject();
    g_player_spell_charging[player] = false;
}

static void N_VORTEX_PARAMETERS(LHVM* vm) {
    vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat();
    vm->PopObject();  // vortex object
}

static void N_VORTEX_FADE_OUT(LHVM* vm) {
    vm->PopObject();
}

// --- Weather / climate ---------------------------------------------------

static void N_CHANGE_WEATHER_PROPERTIES(LHVM* vm) {
    g_weather_c = vm->PopFloat();
    g_weather_b = vm->PopFloat();
    g_weather_a = vm->PopFloat();
}

static void N_CHANGE_CLOUD_PROPERTIES(LHVM* vm) {
    g_cloud_c = vm->PopFloat();
    g_cloud_b = vm->PopFloat();
    g_cloud_a = vm->PopFloat();
}

static void N_SET_AFFECTED_BY_WIND(LHVM* vm) {
    bool     on = vm->PopBoolean();
    uint32_t obj = vm->PopObject();
    (void)on; (void)obj;
}

static void N_IS_WIND_MAGIC_AT_POS(LHVM* vm) {
    vm->PopFloat(); vm->PopFloat(); vm->PopFloat();
    vm->PushBoolean(false);
}

static void N_PAUSE_UNPAUSE_CLIMATE_SYSTEM(LHVM* vm)             { g_climate_paused = vm->PopBoolean(); }
static void N_PAUSE_UNPAUSE_STORM_CREATION_IN_CLIMATE_SYSTEM(LHVM* vm) { g_storms_paused = vm->PopBoolean(); }

static void N_KILL_STORMS_IN_AREA(LHVM* vm) {
    vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat();
}

static void N_SET_PLAYER_WIND_RESISTANCE(LHVM* vm) {
    float    v = vm->PopFloat();
    uint32_t player = vm->PopObject();
    g_player_wind_resistance[player] = v;
}

static void N_GET_PLAYER_WIND_RESISTANCE(LHVM* vm) {
    uint32_t player = vm->PopObject();
    auto it = g_player_wind_resistance.find(player);
    vm->PushFloat(it == g_player_wind_resistance.end() ? 0.0f : it->second);
}

// --- Spirit (advisor) ---------------------------------------------------
//
// Spirit natives talk to the good/evil/neutral advisor. Until the advisor
// hierarchy lands these are state setters that the host (viewer) can read
// to drive UI/animation.

namespace {
struct SpiritState {
    bool     visible       = false;
    bool     ejected       = false;
    bool     played        = false;
    bool     speaking      = false;
    int32_t  current_anim  = 0;
    uint32_t pointing_at_obj = 0;
    float    point_x = 0, point_y = 0, point_z = 0;
    float    screen_x = 0, screen_y = 0;
};
std::unordered_map<uint32_t, SpiritState> g_spirits;
} // namespace

static void N_SPIRIT_EJECT(LHVM* vm) {
    uint32_t s = vm->PopObject();
    g_spirits[s].ejected = true;
}

static void N_SPIRIT_HOME(LHVM* vm) {
    uint32_t s = vm->PopObject();
    g_spirits[s].ejected = false;
}

static void N_SPIRIT_POINT_POS(LHVM* vm) {
    float z = vm->PopFloat(), y = vm->PopFloat(), x = vm->PopFloat();
    uint32_t s = vm->PopObject();
    auto& st = g_spirits[s];
    st.pointing_at_obj = 0;
    st.point_x = x; st.point_y = y; st.point_z = z;
}

static void N_SPIRIT_POINT_GAME_THING(LHVM* vm) {
    uint32_t target = vm->PopObject();
    uint32_t s      = vm->PopObject();
    g_spirits[s].pointing_at_obj = target;
}

static void N_PLAY_SPIRIT_ANIM(LHVM* vm) {
    int32_t  anim = vm->PopInt();
    uint32_t s    = vm->PopObject();
    auto& st = g_spirits[s];
    st.current_anim = anim;
    st.played = false;
}

static void N_SPIRIT_PLAYED(LHVM* vm) {
    uint32_t s = vm->PopObject();
    auto it = g_spirits.find(s);
    vm->PushBoolean(it != g_spirits.end() && it->second.played);
}

static void N_SPIRIT_SPEAKS(LHVM* vm) {
    vm->PopInt();    // line / sound id
    uint32_t s = vm->PopObject();
    g_spirits[s].speaking = true;
}

static void N_SPIRIT_APPEAR(LHVM* vm) {
    uint32_t s = vm->PopObject();
    g_spirits[s].visible = true;
}

static void N_SPIRIT_DISAPPEAR(LHVM* vm) {
    uint32_t s = vm->PopObject();
    g_spirits[s].visible = false;
}

static void N_SPIRIT_SCREEN_POINT(LHVM* vm) {
    float    sy = vm->PopFloat();
    float    sx = vm->PopFloat();
    uint32_t s  = vm->PopObject();
    auto& st = g_spirits[s];
    st.screen_x = sx; st.screen_y = sy;
}

// --- Object impact / building -------------------------------------------

static void N_GAME_THING_HIT(LHVM* vm) {
    uint32_t hitter = vm->PopObject();
    uint32_t hit    = vm->PopObject();
    (void)hitter;
    if (hit) {
        Object* o = LookupObject(hit);
        if (o) o->ReduceLife(0.05f, nullptr);
    }
    vm->PushBoolean(true);
}

static void N_BUILD_BUILDING(LHVM* vm) {
    float amount = vm->PopFloat();
    uint32_t bld = vm->PopObject();
    Object* o = LookupObject(bld);
    if (o) {
        // Building progress lives on Abode::percent_built — accessing it via
        // Object* without dynamic_cast keeps the helper general; clamping is
        // applied by Abode::Process when the script-set value lands.
        // Layout offset 0x54 is percent_built on Abode.
        if (amount > 1.0f) amount = 1.0f;
        if (amount < 0.0f) amount = 0.0f;
        *reinterpret_cast<float*>(reinterpret_cast<char*>(o) + 0x54) = amount;
    }
}

static void N_LOOK_GAME_THING(LHVM* vm) {
    vm->PopObject();  // object to look at
    vm->PopObject();  // looker (player or creature)
}

static void N_OBJECT_INFO_BITS(LHVM* vm) {
    uint32_t h = vm->PopObject();
    Slot* s = SlotOf(h);
    vm->PushInt(s ? static_cast<int32_t>(s->flags) : 0);
}

// --- Camera conversion --------------------------------------------------

static void N_CONVERT_CAMERA_POSITION(LHVM* vm) {
    int32_t enum_val = vm->PopInt();
    (void)enum_val;
    vm->PushFloat(0); vm->PushFloat(0); vm->PushFloat(0);
}

static void N_CONVERT_CAMERA_FOCUS(LHVM* vm) {
    int32_t enum_val = vm->PopInt();
    (void)enum_val;
    vm->PushFloat(0); vm->PushFloat(0); vm->PushFloat(0);
}

// --- UI / clipping / drawing --------------------------------------------

static void N_SET_GRAPHICS_CLIPPING(LHVM* vm) {
    g_graphics_clipping = vm->PopBoolean();
}

static void N_SET_CLIPPING_WINDOW(LHVM* vm) {
    g_clip_h = vm->PopFloat(); g_clip_w = vm->PopFloat();
    g_clip_y = vm->PopFloat(); g_clip_x = vm->PopFloat();
}

static void N_CLEAR_CLIPPING_WINDOW(LHVM* /*vm*/) {
    g_clip_x = g_clip_y = g_clip_w = g_clip_h = 0;
}

static void N_SET_DRAW_TEXT_COLOUR(LHVM* vm) {
    vm->PopFloat(); vm->PopFloat(); vm->PopFloat();
}

static void N_ENABLE_DISABLE_ALIGNMENT_MUSIC(LHVM* vm) {
    g_alignment_music_on = vm->PopBoolean();
}

static void N_SET_INTERFACE_INTERACTION(LHVM* vm) {
    vm->PopInt();
}

static void N_SET_INTERFACE_CITADEL(LHVM* vm) {
    vm->PopBoolean();
}

static void N_SET_LAND_BALANCE(LHVM* vm) {
    g_land_balance = vm->PopFloat();
    vm->PopInt();   // tribe
}

static void N_CREATE_HIGHLIGHT(LHVM* vm) {
    vm->PopFloat();  // height
    float z = vm->PopFloat(), y = vm->PopFloat(), x = vm->PopFloat();
    int32_t type = vm->PopInt();
    EntityCreateParams p = {};
    p.world_x = x; p.world_z = z; p.scale = 1.0f;
    p.type_enum = static_cast<uint32_t>(type);
    (void)y;
    Object* obj = EntityFactory::CreateEntity(ENTITY_CAT_FEATURE, p);
    uint32_t h = HandleFor(obj);
    NotifySpawn(h, obj, 1 /* MARKER (highlight) */, type, x, y, z);
    vm->PushObject(h);
}

// --- Poisoned-area queries ----------------------------------------------

static void N_ID_POISONED_SIZE(LHVM* vm) {
    uint32_t h = vm->PopObject();
    auto it = g_flock_members.find(h);
    int32_t count = 0;
    if (it != g_flock_members.end()) {
        for (uint32_t m : it->second) {
            Slot* s = SlotOf(m);
            if (s && (s->flags & FLAG_POISONED)) count++;
        }
    }
    vm->PushInt(count);
}

static void N_CALL_POISONED_IN(LHVM* vm) {
    vm->PopBoolean();             // exclude already called
    uint32_t container = vm->PopObject();
    auto it = g_flock_members.find(container);
    if (it != g_flock_members.end()) {
        for (uint32_t m : it->second) {
            Slot* s = SlotOf(m);
            if (s && (s->flags & FLAG_POISONED)) { vm->PushObject(m); return; }
        }
    }
    vm->PushObject(0);
}

static void N_CALL_NOT_POISONED_IN(LHVM* vm) {
    vm->PopBoolean();
    uint32_t container = vm->PopObject();
    auto it = g_flock_members.find(container);
    if (it != g_flock_members.end()) {
        for (uint32_t m : it->second) {
            Slot* s = SlotOf(m);
            if (s && !(s->flags & FLAG_POISONED)) { vm->PushObject(m); return; }
        }
    }
    vm->PushObject(0);
}

static void N_SAY_SOUND_EFFECT_PLAYING(LHVM* vm) {
    vm->PopInt();
    vm->PushBoolean(false);
}

// --- Spirit appearance / dialogue audio --------------------------------

static void N_ENABLE_DISABLE_MUSIC(LHVM* vm) {
    vm->PopBoolean(); vm->PopObject();
}

// --- Cache override for affected-by-spell -------------------------------
// (chunk 1's IS_AFFECTED_BY_SPELL was stub — make it real now)
static void N_IS_AFFECTED_BY_SPELL_REAL(LHVM* vm) {
    int32_t  spell = vm->PopInt();
    uint32_t obj   = vm->PopObject();
    auto oit = g_object_spell_active.find(obj);
    if (oit == g_object_spell_active.end()) { vm->PushBoolean(false); return; }
    auto sit = oit->second.find(spell);
    vm->PushBoolean(sit != oit->second.end() && sit->second);
}

// ============================================================================
// Chunk 5 — audio, dialogue, UI, time (50)
// ============================================================================

namespace {

struct AudioState {
    std::unordered_map<int32_t, bool> sound_playing;     // sound id → is-playing
    std::unordered_map<int32_t, bool> say_playing;       // SAY-line id → is-playing
    std::unordered_map<uint32_t, int32_t> attached_tags; // object → sound tag
    int32_t  current_music     = 0;
    int32_t  last_music_line   = 0;
    bool     music_playing     = false;
    uint32_t music_attached_to = 0;
    bool     game_sound_on     = true;
};

struct DialogueState {
    bool     active         = false;
    bool     ready          = true;
    bool     widescreen     = false;
    bool     widescreen_done= true;
    int32_t  current_text   = 0;
    int32_t  pending_temp   = 0;
    bool     last_text_read = true;
    int32_t  scroll_text_id = 0;
    int32_t  draw_text_value = 0;
};

struct ScreenFadeState {
    bool   in_progress = false;
    float  finish_time = 0;     // in game seconds
    float  r = 0, g = 0, b = 0;
};

AudioState     g_audio;
DialogueState  g_dialogue;
ScreenFadeState g_fade;
float          g_game_speed         = 1.0f;
float          g_game_time_base     = 0.0f;
float          g_game_time_props[3] = { 0, 0, 0 };
bool           g_help_system_on     = true;
bool           g_hand_demo_playing  = false;
int32_t        g_hand_demo_anim     = 0;
bool           g_hand_demo_keys_ok  = true;
float          g_bookmark_pos[3*8]  = {};

void SetSoundPlaying(int32_t id, bool on) { g_audio.sound_playing[id] = on; }

} // namespace

// --- Sound effects -------------------------------------------------------

static void N_PLAY_SOUND_EFFECT(LHVM* vm) {
    vm->PopFloat();   // volume / random offset (varies)
    vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); // x, y, z
    int32_t id = vm->PopInt();
    SetSoundPlaying(id, true);
}

static void N_STOP_SOUND_EFFECT(LHVM* vm) {
    vm->PopInt();   // bank id
    int32_t id = vm->PopInt();
    SetSoundPlaying(id, false);
}

static void N_SOUND_EXISTS(LHVM* vm) {
    vm->PopInt();   // bank id
    vm->PopInt();   // sample id
    vm->PushBoolean(true);  // assume present until SAD bank loader lands
}

static void N_GAME_SOUND_PLAYING(LHVM* vm) {
    int32_t id = vm->PopInt();
    auto it = g_audio.sound_playing.find(id);
    vm->PushBoolean(it != g_audio.sound_playing.end() && it->second);
}

static void N_GAME_PLAY_SAY_SOUND_EFFECT(LHVM* vm) {
    vm->PopFloat();  // volume
    vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); // x, y, z
    int32_t id = vm->PopInt();
    g_audio.say_playing[id] = true;
}

static void N_ATTACH_SOUND_TAG(LHVM* vm) {
    int32_t  tag = vm->PopInt();
    uint32_t obj = vm->PopObject();
    g_audio.attached_tags[obj] = tag;
}

static void N_DETACH_SOUND_TAG(LHVM* vm) {
    uint32_t obj = vm->PopObject();
    g_audio.attached_tags.erase(obj);
}

static void N_GAME_SET_MANA(LHVM* vm) {
    vm->PopFloat();   // mana
    vm->PopObject();  // player — applied via Game::SetMana when wired
}

// --- Music ---------------------------------------------------------------

static void N_START_MUSIC(LHVM* vm) {
    g_audio.current_music = vm->PopInt();
    g_audio.music_playing = true;
}

static void N_STOP_MUSIC(LHVM* /*vm*/) {
    g_audio.music_playing = false;
    g_audio.music_attached_to = 0;
}

static void N_ATTACH_MUSIC(LHVM* vm) {
    uint32_t obj = vm->PopObject();
    int32_t  id  = vm->PopInt();
    g_audio.current_music = id;
    g_audio.music_playing = true;
    g_audio.music_attached_to = obj;
}

static void N_DETACH_MUSIC(LHVM* vm) {
    vm->PopObject();
    g_audio.music_attached_to = 0;
}

static void N_LAST_MUSIC_LINE(LHVM* vm) {
    int32_t v = vm->PopInt();
    g_audio.last_music_line = v;
    vm->PushInt(v);
}

// --- Dialogue / text -----------------------------------------------------

static void N_RUN_TEXT(LHVM* vm) {
    vm->PopInt();              // duration / flags
    int32_t id = vm->PopInt();
    g_dialogue.current_text = id;
    g_dialogue.last_text_read = false;
    vm->PushBoolean(true);
}

static void N_TEMP_TEXT(LHVM* vm) {
    vm->PopInt();              // duration
    int32_t id = vm->PopInt();
    g_dialogue.pending_temp = id;
}

static void N_TEXT_READ(LHVM* vm) {
    vm->PushBoolean(g_dialogue.last_text_read);
}

static void N_RUN_TEXT_WITH_NUMBER(LHVM* vm) {
    vm->PopFloat();            // numeric arg interpolated into text
    vm->PopInt();              // duration / flags
    int32_t id = vm->PopInt();
    g_dialogue.current_text = id;
    g_dialogue.last_text_read = false;
    vm->PushBoolean(true);
}

static void N_TEMP_TEXT_WITH_NUMBER(LHVM* vm) {
    vm->PopFloat();
    vm->PopInt();
    int32_t id = vm->PopInt();
    g_dialogue.pending_temp = id;
}

static void N_START_DIALOGUE(LHVM* /*vm*/) {
    g_dialogue.active = true;
    g_dialogue.ready  = false;
}

static void N_END_DIALOGUE(LHVM* /*vm*/) {
    g_dialogue.active = false;
    g_dialogue.ready  = true;
}

static void N_IS_DIALOGUE_READY(LHVM* vm) {
    vm->PushBoolean(g_dialogue.ready);
}

static void N_GAME_CLEAR_DIALOGUE(LHVM* /*vm*/) {
    g_dialogue.current_text = 0;
    g_dialogue.pending_temp = 0;
}

static void N_GAME_CLOSE_DIALOGUE(LHVM* /*vm*/) {
    g_dialogue.active = false;
    g_dialogue.current_text = 0;
}

static void N_GAME_DRAW_TEXT(LHVM* vm) {
    vm->PopFloat(); vm->PopFloat();          // size, fade
    vm->PopFloat(); vm->PopFloat();          // x, y
    vm->PopInt();                            // colour
    int32_t id = vm->PopInt();
    g_dialogue.draw_text_value = id;
}

static void N_GAME_DRAW_TEMP_TEXT(LHVM* vm) {
    vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat();
    vm->PopInt();
    int32_t id = vm->PopInt();
    g_dialogue.pending_temp = id;
}

static void N_FADE_ALL_DRAW_TEXT(LHVM* vm) {
    vm->PopFloat();
    g_dialogue.draw_text_value = 0;
}

// --- Widescreen / fade ---------------------------------------------------

static void N_SET_WIDESCREEN(LHVM* vm) {
    g_dialogue.widescreen      = vm->PopBoolean();
    g_dialogue.widescreen_done = false;
}

static void N_WIDESCREEN_TRANSISTION_FINISHED(LHVM* vm) {
    g_dialogue.widescreen_done = true;
    vm->PushBoolean(true);
}

static void N_SET_FADE(LHVM* vm) {
    float t = vm->PopFloat();
    g_fade.b = vm->PopFloat();
    g_fade.g = vm->PopFloat();
    g_fade.r = vm->PopFloat();
    g_fade.in_progress = true;
    g_fade.finish_time = t;
}

static void N_SET_FADE_IN(LHVM* vm) {
    g_fade.finish_time = vm->PopFloat();
    g_fade.in_progress = true;
    g_fade.r = g_fade.g = g_fade.b = 0;
}

static void N_FADE_FINISHED(LHVM* vm) {
    bool done = !g_fade.in_progress;
    if (g_fade.in_progress && g_fade.finish_time <= 0.0f) {
        g_fade.in_progress = false;
        done = true;
    }
    vm->PushBoolean(done);
}

// --- Time / game speed ---------------------------------------------------

static void N_SET_GAMESPEED(LHVM* vm) {
    g_game_speed = vm->PopFloat();
}

static void N_SET_GAME_TIME(LHVM* vm) {
    g_game_time_base = vm->PopFloat();
}

static void N_GET_REAL_TIME(LHVM* vm) {
    // Wall-clock seconds since module load aren't tracked; mirror game time
    // via g_game's game_turn (10 fps tick) so scripts comparing real-to-game
    // see motion until host wiring overrides this.
    if (!g_game) { vm->PushFloat(0); return; }
    uint32_t turn = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(g_game) + 0x205A40);
    vm->PushFloat(static_cast<float>(turn) / 10.0f);
}

static void N_SET_GAME_TIME_PROPERTIES(LHVM* vm) {
    g_game_time_props[2] = vm->PopFloat();
    g_game_time_props[1] = vm->PopFloat();
    g_game_time_props[0] = vm->PopFloat();
}

static void N_RESET_GAME_TIME_PROPERTIES(LHVM* /*vm*/) {
    g_game_time_props[0] = g_game_time_props[1] = g_game_time_props[2] = 0;
}

static void N_KEY_DOWN(LHVM* vm) {
    vm->PopInt();
    vm->PushBoolean(false);  // wired by host once input plumbing is live
}

// --- Help / hand demo ----------------------------------------------------

static void N_HELP_SYSTEM_ON(LHVM* vm) {
    vm->PushBoolean(g_help_system_on);
}

static void N_SET_HELP_SYSTEM(LHVM* vm) {
    g_help_system_on = vm->PopBoolean();
}

static void N_PLAY_HAND_DEMO(LHVM* vm) {
    vm->PopBoolean();  // skipable
    vm->PopBoolean();  // pause game time
    g_hand_demo_anim = vm->PopInt();
    g_hand_demo_playing = true;
}

static void N_HAND_DEMO_TRIGGER(LHVM* vm) {
    vm->PushBoolean(g_hand_demo_playing);
}

static void N_SET_HAND_DEMO_KEYS(LHVM* vm) {
    g_hand_demo_keys_ok = vm->PopBoolean();
}

// --- Bookmarks / map / interaction --------------------------------------

static void N_SET_BOOKMARK_POSITION(LHVM* vm) {
    float z = vm->PopFloat(), y = vm->PopFloat(), x = vm->PopFloat();
    int32_t slot = vm->PopInt();
    if (slot >= 0 && slot < 8) {
        g_bookmark_pos[slot*3 + 0] = x;
        g_bookmark_pos[slot*3 + 1] = y;
        g_bookmark_pos[slot*3 + 2] = z;
    }
}

static void N_GET_INTERACTION_MAGNITUDE(LHVM* vm) {
    vm->PopObject();
    vm->PushFloat(0.5f);   // mid magnitude until hand input integrates
}

static void N_LOAD_MAP(LHVM* vm) {
    vm->PopInt();   // map slot / id — host must reload terrain
}

// --- Camera-control toggles (overrides existing chunk-1 stubs) ----------

static void N_START_CAMERA_CONTROL(LHVM* /*vm*/) { g_dialogue.active = true; }
static void N_END_CAMERA_CONTROL(LHVM* /*vm*/)   { g_dialogue.active = false; }

// ============================================================================
// Chunk 6 — camera, cinematic, follow, computer-player driving (50)
// ============================================================================

namespace {

struct CameraStash {
    float pos_x = 0, pos_y = 0, pos_z = 0;
    float foc_x = 0, foc_y = 0, foc_z = 0;
    float lens  = 60.0f;
    bool  has_data = false;
};

struct CameraFollowState {
    uint32_t focus_target    = 0;
    uint32_t position_target = 0;
    bool     dual_active     = false;
    float    dual_x = 0, dual_y = 0, dual_z = 0;
    float    shake_amount    = 0;
    float    lens_value      = 60.0f;
    bool     has_arrived     = true;
    int32_t  zone            = 0;
    bool     can_view        = true;
};

CameraStash       g_cam_stash;
CameraFollowState g_cam_follow;

struct ComputerPlayerState {
    bool    enabled    = true;
    int32_t personality= 0;
    float   suppression= 0;
    float   speed      = 1.0f;
    float   attitude   = 0;
    bool    ready      = true;
    std::vector<std::tuple<int32_t,float,float,float>> action_queue;  // (action, x, y, z)
};
std::unordered_map<uint32_t, ComputerPlayerState> g_cp;

std::unordered_map<uint64_t, float> g_player_ally;  // (a<<32|b) → strength

uint64_t AllyKey(uint32_t a, uint32_t b) {
    if (a > b) std::swap(a, b);
    return (static_cast<uint64_t>(a) << 32) | b;
}

} // namespace

static void N_HAS_CAMERA_ARRIVED(LHVM* vm)        { vm->PushBoolean(g_cam_follow.has_arrived); }

static void N_FOCUS_FOLLOW(LHVM* vm) {
    g_cam_follow.focus_target = vm->PopObject();
    g_cam_follow.has_arrived  = false;
}
static void N_POSITION_FOLLOW(LHVM* vm) {
    g_cam_follow.position_target = vm->PopObject();
    g_cam_follow.has_arrived     = false;
}
static void N_SET_FOCUS_FOLLOW(LHVM* vm)    { g_cam_follow.focus_target    = vm->PopObject(); }
static void N_SET_POSITION_FOLLOW(LHVM* vm) { g_cam_follow.position_target = vm->PopObject(); }

static void N_SET_FOCUS_AND_POSITION_FOLLOW(LHVM* vm) {
    g_cam_follow.position_target = vm->PopObject();
    g_cam_follow.focus_target    = g_cam_follow.position_target;
}

static void N_FOCUS_AND_POSITION_FOLLOW(LHVM* vm) {
    vm->PopFloat();   // distance
    g_cam_follow.position_target = vm->PopObject();
    g_cam_follow.focus_target    = g_cam_follow.position_target;
    g_cam_follow.has_arrived     = false;
}

static void N_CAMERA_PROPERTIES(LHVM* vm) {
    vm->PopBoolean();   // bool — height-aware
    vm->PopFloat(); vm->PopFloat();  // angle, distance
}

static void N_SHAKE_CAMERA(LHVM* vm) {
    vm->PopFloat();    // duration
    g_cam_follow.shake_amount = vm->PopFloat();   // magnitude
    vm->PopFloat();    // radius
    vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); // x, y, z
}

static void N_SET_CAMERA_ZONE(LHVM* vm) {
    vm->PopInt();   // zone string id (CHL string offset)
    g_cam_follow.zone += 1;  // increment to mark a transition
}

static void N_RUN_CAMERA_PATH(LHVM* vm) {
    vm->PopInt();  // path id
    g_cam_follow.has_arrived = false;
}

static void N_SET_CAMERA_LENS(LHVM* vm)  { g_cam_follow.lens_value = vm->PopFloat(); }
static void N_MOVE_CAMERA_LENS(LHVM* vm) {
    vm->PopFloat();  // duration
    g_cam_follow.lens_value = vm->PopFloat();
}

static void N_STORE_CAMERA_DETAILS(LHVM* /*vm*/)   { g_cam_stash.has_data = true; }
static void N_RESTORE_CAMERA_DETAILS(LHVM* /*vm*/) { g_cam_follow.has_arrived = false; }

static void N_SET_CAMERA_POS_FOC_LENS(LHVM* vm) {
    g_cam_follow.lens_value = vm->PopFloat();
    vm->PopFloat(); vm->PopFloat(); vm->PopFloat();   // foc x,y,z
    vm->PopFloat(); vm->PopFloat(); vm->PopFloat();   // pos x,y,z
}

static void N_MOVE_CAMERA_POS_FOC_LENS(LHVM* vm) {
    vm->PopFloat();   // duration
    g_cam_follow.lens_value = vm->PopFloat();
    vm->PopFloat(); vm->PopFloat(); vm->PopFloat();
    vm->PopFloat(); vm->PopFloat(); vm->PopFloat();
    g_cam_follow.has_arrived = false;
}

static void N_GET_STORED_CAMERA_POSITION(LHVM* vm) {
    vm->PushFloat(g_cam_stash.pos_x);
    vm->PushFloat(g_cam_stash.pos_y);
    vm->PushFloat(g_cam_stash.pos_z);
}
static void N_GET_STORED_CAMERA_FOCUS(LHVM* vm) {
    vm->PushFloat(g_cam_stash.foc_x);
    vm->PushFloat(g_cam_stash.foc_y);
    vm->PushFloat(g_cam_stash.foc_z);
}

static void N_SET_CAMERA_TO_FACE_OBJECT(LHVM* vm) {
    vm->PopFloat();   // distance
    g_cam_follow.focus_target = vm->PopObject();
}
static void N_MOVE_CAMERA_TO_FACE_OBJECT(LHVM* vm) {
    vm->PopFloat();   // duration
    vm->PopFloat();   // distance
    g_cam_follow.focus_target = vm->PopObject();
    g_cam_follow.has_arrived  = false;
}

static void N_START_DUAL_CAMERA(LHVM* vm) {
    g_cam_follow.dual_active = true;
    vm->PopObject(); vm->PopObject();   // two targets
}
static void N_UPDATE_DUAL_CAMERA(LHVM* vm) {
    vm->PopObject(); vm->PopObject();
}
static void N_RELEASE_DUAL_CAMERA(LHVM* /*vm*/) { g_cam_follow.dual_active = false; }
static void N_CREATE_DUAL_CAMERA_WITH_POINT(LHVM* vm) {
    g_cam_follow.dual_z = vm->PopFloat();
    g_cam_follow.dual_y = vm->PopFloat();
    g_cam_follow.dual_x = vm->PopFloat();
    vm->PopObject();
    g_cam_follow.dual_active = true;
}

static void N_SET_FOCUS_FOLLOW_COMPUTER_PLAYER(LHVM* vm)    { g_cam_follow.focus_target = vm->PopObject(); }
static void N_SET_POSITION_FOLLOW_COMPUTER_PLAYER(LHVM* vm) { g_cam_follow.position_target = vm->PopObject(); }

static void N_GAME_THING_CAN_VIEW_CAMERA(LHVM* vm) {
    vm->PopFloat();  // angle
    vm->PopObject();
    vm->PushBoolean(g_cam_follow.can_view);
}

static void N_GAME_TYPE(LHVM* vm) {
    uint32_t h = vm->PopObject();
    Object* o = LookupObject(h);
    vm->PushInt(o ? static_cast<int32_t>(o->GetScriptObjectType()) : 0);
}

// --- Computer-player AI driver -----------------------------------------

static void N_COMPUTER_PLAYER_READY(LHVM* vm) {
    uint32_t h = vm->PopObject();
    auto it = g_cp.find(h);
    vm->PushBoolean(it == g_cp.end() || it->second.ready);
}

static void N_ENABLE_DISABLE_COMPUTER_PLAYER_311(LHVM* vm) {
    bool on = vm->PopBoolean();
    uint32_t h = vm->PopObject();
    g_cp[h].enabled = on;
}
static void N_ENABLE_DISABLE_COMPUTER_PLAYER_345(LHVM* vm) {
    bool on = vm->PopBoolean();
    uint32_t h = vm->PopObject();
    g_cp[h].enabled = on;
}

static void N_SET_COMPUTER_PLAYER_PERSONALITY(LHVM* vm) {
    vm->PopFloat();   // weight
    int32_t pers = vm->PopInt();
    uint32_t h = vm->PopObject();
    g_cp[h].personality = pers;
}
static void N_SET_COMPUTER_PLAYER_SUPPRESSION(LHVM* vm) {
    float v = vm->PopFloat();
    uint32_t h = vm->PopObject();
    g_cp[h].suppression = v;
}
static void N_SET_COMPUTER_PLAYER_SPEED(LHVM* vm) {
    float v = vm->PopFloat();
    uint32_t h = vm->PopObject();
    g_cp[h].speed = v;
}
static void N_SET_COMPUTER_PLAYER_ATTITUDE(LHVM* vm) {
    float v = vm->PopFloat();
    uint32_t h = vm->PopObject();
    g_cp[h].attitude = v;
}
static void N_GET_COMPUTER_PLAYER_ATTITUDE(LHVM* vm) {
    uint32_t h = vm->PopObject();
    auto it = g_cp.find(h);
    vm->PushFloat(it == g_cp.end() ? 0.0f : it->second.attitude);
}
static void N_FORCE_COMPUTER_PLAYER_ACTION(LHVM* vm) {
    float z = vm->PopFloat(), y = vm->PopFloat(), x = vm->PopFloat();
    int32_t action = vm->PopInt();
    uint32_t h = vm->PopObject();
    g_cp[h].action_queue.clear();
    g_cp[h].action_queue.emplace_back(action, x, y, z);
}
static void N_QUEUE_COMPUTER_PLAYER_ACTION(LHVM* vm) {
    float z = vm->PopFloat(), y = vm->PopFloat(), x = vm->PopFloat();
    int32_t action = vm->PopInt();
    uint32_t h = vm->PopObject();
    g_cp[h].action_queue.emplace_back(action, x, y, z);
}
static void N_GAME_CLEAR_COMPUTER_PLAYER_ACTIONS(LHVM* vm) {
    uint32_t h = vm->PopObject();
    g_cp[h].action_queue.clear();
}
static void N_RELEASE_COMPUTER_PLAYER(LHVM* vm) {
    uint32_t h = vm->PopObject();
    g_cp[h].enabled = false;
    g_cp[h].action_queue.clear();
}
static void N_LOAD_COMPUTER_PLAYER_PERSONALITY(LHVM* vm) {
    int32_t  pers = vm->PopInt();
    uint32_t h    = vm->PopObject();
    g_cp[h].personality = pers;
}
static void N_SAVE_COMPUTER_PLAYER_PERSONALITY(LHVM* vm) {
    vm->PopInt();
    vm->PopObject();
}

// --- Player ally relationship -----------------------------------------

static void N_SET_PLAYER_ALLY(LHVM* vm) {
    float    v = vm->PopFloat();
    uint32_t b = vm->PopObject();
    uint32_t a = vm->PopObject();
    g_player_ally[AllyKey(a, b)] = v;
}
static void N_GET_PLAYER_ALLY(LHVM* vm) {
    uint32_t b = vm->PopObject();
    uint32_t a = vm->PopObject();
    auto it = g_player_ally.find(AllyKey(a, b));
    vm->PushFloat(it == g_player_ally.end() ? 0.0f : it->second);
}

// --- Animation / playback queries -------------------------------------

static void N_PLAYED_PERCENTAGE(LHVM* vm) {
    vm->PopObject();
    vm->PushFloat(1.0f);   // assume animation has finished
}

static void N_GET_OBJECT_DROPPED(LHVM* vm) {
    vm->PopObject();
    vm->PushObject(0);
}

static void N_REMOVE_REACTION(LHVM* vm) {
    vm->PopObject(); vm->PopObject();
}
static void N_REMOVE_REACTION_OF_TYPE(LHVM* vm) {
    vm->PopInt(); vm->PopObject(); vm->PopObject();
}

// ============================================================================
// Chunk 7 — town/player/influence, timers, animation, dance, music, calendar
// ============================================================================

namespace {

struct Timer {
    float total_seconds   = 0;
    float started_at_turn = 0;   // game seconds when set
    bool  visible         = false;
};
std::unordered_map<uint32_t, Timer> g_timers;

float CurrentGameTime() {
    if (!g_game) return 0;
    uint32_t turn = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(g_game) + 0x205A40);
    return static_cast<float>(turn) / 10.0f;
}

struct InfluenceSource {
    bool   from_object;
    uint32_t source_handle;
    float  x, z;
    float  radius;
    int32_t player;
    bool   antiplayer;     // negative influence
};
std::vector<InfluenceSource> g_influences;

uint32_t g_next_dance = 1;
std::unordered_map<uint32_t, std::vector<uint32_t>> g_dance_members;

float g_temperature = 20.0f;
float g_inclusion_distance = 100.0f;
bool  g_attack_own_town = false;

struct WalkPath {
    std::vector<MapCoords> nodes;
    float percent = 0.0f;
};
std::unordered_map<uint32_t, WalkPath> g_walk_paths;

} // namespace

static void N_INFLUENCE_OBJECT(LHVM* vm) {
    bool antiplayer = vm->PopBoolean();
    int32_t fixed = vm->PopInt();
    (void)fixed;
    float radius = vm->PopFloat();
    uint32_t obj = vm->PopObject();
    InfluenceSource s = {};
    s.from_object = true;
    s.source_handle = obj;
    s.radius = radius;
    s.antiplayer = antiplayer;
    Object* o = LookupObject(obj);
    if (o) { s.x = WorldX(o); s.z = WorldZ(o); }
    g_influences.push_back(s);
    vm->PushObject(0);
}

static void N_INFLUENCE_POSITION(LHVM* vm) {
    bool antiplayer = vm->PopBoolean();
    int32_t fixed = vm->PopInt();
    (void)fixed;
    float radius = vm->PopFloat();
    float z = vm->PopFloat(), y = vm->PopFloat(), x = vm->PopFloat();
    (void)y;
    InfluenceSource s = {};
    s.from_object = false;
    s.x = x; s.z = z; s.radius = radius;
    s.antiplayer = antiplayer;
    g_influences.push_back(s);
    vm->PushObject(0);
}

// Override chunk 1's GET_INFLUENCE with a real walking sum
static void N_GET_INFLUENCE_REAL(LHVM* vm) {
    int32_t player = vm->PopInt();
    float z = vm->PopFloat(), y = vm->PopFloat(), x = vm->PopFloat();
    (void)y;
    float total = 0.0f;
    for (const auto& s : g_influences) {
        float dx = s.x - x, dz = s.z - z;
        float d2 = dx*dx + dz*dz;
        if (d2 > s.radius * s.radius) continue;
        float w = 1.0f - sqrtf(d2) / s.radius;
        total += s.antiplayer ? -w : w;
    }
    (void)player;
    vm->PushFloat(total);
}

// --- Special effects + animation overrides -----------------------------

static void N_SPECIAL_EFFECT_POSITION(LHVM* vm) {
    vm->PopFloat();   // strength
    vm->PopInt();     // effect type
    vm->PopFloat(); vm->PopFloat(); vm->PopFloat();   // pos
    vm->PushObject(0);
}
static void N_SPECIAL_EFFECT_OBJECT(LHVM* vm) {
    vm->PopFloat();   // strength
    vm->PopInt();
    vm->PopObject();
    vm->PushObject(0);
}

static void N_OVERRIDE_STATE_ANIMATION(LHVM* vm) {
    vm->PopInt();    // state
    vm->PopObject();
}

static void N_PLAYED(LHVM* vm) {
    vm->PopObject();
    vm->PushBoolean(true);   // assume played
}

static void N_CLEAR_DROPPED_BY_OBJECT(LHVM* vm) {
    vm->PopObject();
}

static void N_CREATE_REACTION(LHVM* vm) {
    vm->PopFloat();   // duration
    vm->PopInt();     // reaction type
    vm->PopObject();  // target
    vm->PopObject();  // source
}

static void N_POPULATE_CONTAINER(LHVM* vm) {
    int32_t  type    = vm->PopInt();
    int32_t  count   = vm->PopInt();
    float    radius  = vm->PopFloat();
    uint32_t cont    = vm->PopObject();
    Object* c = LookupObject(cont);
    auto& members = g_flock_members[cont];
    for (int32_t i = 0; i < count; i++) {
        EntityCreateParams p = {};
        if (c) {
            float ang = (i * 6.28318f) / static_cast<float>(count);
            p.world_x = WorldX(c) + cosf(ang) * radius;
            p.world_z = WorldZ(c) + sinf(ang) * radius;
        }
        p.scale = 1.0f;
        p.type_enum = static_cast<uint32_t>(type);
        Object* obj = EntityFactory::CreateEntity(CategoryForScriptType(type), p);
        if (obj) {
            uint32_t mh = HandleFor(obj);
            members.push_back(mh);
            g_object_to_flock[mh] = cont;
        }
    }
}

static void N_ADD_REFERENCE(LHVM* vm)    { vm->PopObject(); vm->PushInt(0); }
static void N_REMOVE_REFERENCE(LHVM* vm) { vm->PopObject(); vm->PushInt(0); }

// --- Calendar / real time ----------------------------------------------

static void N_GET_REAL_DAY_115(LHVM* vm) { vm->PushInt(1); }
static void N_GET_REAL_DAY_116(LHVM* vm) { vm->PushInt(1); }
static void N_GET_REAL_MONTH(LHVM* vm)   { vm->PushInt(1); }
static void N_GET_REAL_YEAR(LHVM* vm)    { vm->PushInt(2001); }

static void N_GET_MOON_PERCENTAGE(LHVM* vm) {
    // Synodic month proxy: cycle game time over 30 in-game days.
    float t = CurrentGameTime();
    float cycle = fmodf(t, 30.0f) / 30.0f;
    vm->PushFloat(0.5f - 0.5f * cosf(cycle * 6.28318f));
}

static void N_CHANGE_LIGHTNING_PROPERTIES(LHVM* vm) {
    vm->PopFloat(); vm->PopFloat(); vm->PopFloat();
}
static void N_CHANGE_TIME_FADE_PROPERTIES(LHVM* vm) {
    vm->PopFloat(); vm->PopFloat();
}

// --- Look / pointing helpers -------------------------------------------

static void N_GET_TARGET_RELATIVE_POS(LHVM* vm) {
    vm->PopObject();   // target
    vm->PopObject();   // source
    vm->PushFloat(0); vm->PushFloat(0); vm->PushFloat(0);
}

static void N_STOP_POINTING(LHVM* vm) { vm->PopObject(); }
static void N_STOP_LOOKING(LHVM* vm)  { vm->PopObject(); }

static void N_LOOK_AT_POSITION(LHVM* vm) {
    vm->PopFloat(); vm->PopFloat(); vm->PopFloat();   // pos
    vm->PopObject();   // looker
}

static void N_CLING_SPIRIT(LHVM* vm) {
    vm->PopFloat(); vm->PopFloat();
    uint32_t s = vm->PopObject();
    g_spirits[s].visible = true;
}

static void N_FLY_SPIRIT(LHVM* vm) {
    vm->PopFloat(); vm->PopFloat();
    vm->PopObject();
}

// --- Walking paths -----------------------------------------------------

static void N_WALK_PATH(LHVM* vm) {
    vm->PopFloat();   // start delay
    vm->PopBoolean(); // backwards
    int32_t  path_id = vm->PopInt();
    uint32_t obj     = vm->PopObject();
    (void)path_id;
    g_walk_paths[obj].percent = 0.0f;
}

static void N_GET_WALK_PATH_PERCENTAGE(LHVM* vm) {
    uint32_t obj = vm->PopObject();
    auto it = g_walk_paths.find(obj);
    vm->PushFloat(it == g_walk_paths.end() ? 0.0f : it->second.percent);
}

// --- Music --------------------------------------------------------------

static void N_RESTART_MUSIC(LHVM* /*vm*/)         { g_audio.music_playing = true; }
static void N_MUSIC_PLAYED_191(LHVM* vm)          { vm->PopInt(); vm->PushBoolean(g_audio.music_playing); }
static void N_GET_MUSIC_OBJ_DISTANCE(LHVM* vm)    { vm->PopObject(); vm->PushFloat(0); }
static void N_GET_MUSIC_ENUM_DISTANCE(LHVM* vm)   { vm->PopInt(); vm->PushFloat(0); }
static void N_SET_MUSIC_PLAY_POSITION(LHVM* vm)   { vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); }
static void N_MOVE_MUSIC(LHVM* vm)                { vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); }

// --- Hit / held / slowest ----------------------------------------------

static void N_CLEAR_HIT_OBJECT(LHVM* /*vm*/) {}
static void N_GET_SLOWEST_SPEED(LHVM* vm)    { vm->PopObject(); vm->PushFloat(50.0f); }
static void N_GET_OBJECT_HELD_199(LHVM* vm)  { vm->PopObject(); vm->PushObject(0); }

// --- Animation / AVI ---------------------------------------------------

static void N_SET_ANIMATION_MODIFY(LHVM* vm) {
    vm->PopBoolean(); vm->PopObject();
}
static void N_SET_AVI_SEQUENCE(LHVM* vm) {
    vm->PopBoolean(); vm->PopInt();
}
static void N_PLAY_GESTURE(LHVM* vm) {
    vm->PopFloat(); vm->PopInt(); vm->PopInt(); vm->PopInt(); vm->PopObject();
}

// --- Input / dev ---------------------------------------------------

static void N_DEV_FUNCTION(LHVM* vm)         { vm->PopInt(); }
static void N_HAS_MOUSE_WHEEL(LHVM* vm)      { vm->PushBoolean(true); }
static void N_NUM_MOUSE_BUTTONS(LHVM* vm)    { vm->PushInt(3); }

// --- Timers ------------------------------------------------------------

static void N_CREATE_TIMER(LHVM* vm) {
    float seconds = vm->PopFloat();
    EntityCreateParams p = {};
    p.scale = 1.0f;
    Object* obj = EntityFactory::CreateEntity(ENTITY_CAT_FEATURE, p);
    uint32_t h = HandleFor(obj);
    if (h) g_timers[h] = { seconds, CurrentGameTime(), false };
    vm->PushObject(h);
}

static void N_SET_TIMER_TIME(LHVM* vm) {
    float seconds = vm->PopFloat();
    uint32_t h = vm->PopObject();
    auto it = g_timers.find(h);
    if (it != g_timers.end()) {
        it->second.total_seconds   = seconds;
        it->second.started_at_turn = CurrentGameTime();
    }
}

static void N_GET_TIMER_TIME_REMAINING(LHVM* vm) {
    uint32_t h = vm->PopObject();
    auto it = g_timers.find(h);
    if (it == g_timers.end()) { vm->PushFloat(0); return; }
    float elapsed = CurrentGameTime() - it->second.started_at_turn;
    float left    = it->second.total_seconds - elapsed;
    vm->PushFloat(left < 0 ? 0.0f : left);
}

static void N_GET_TIMER_TIME_SINCE_SET(LHVM* vm) {
    uint32_t h = vm->PopObject();
    auto it = g_timers.find(h);
    if (it == g_timers.end()) { vm->PushFloat(0); return; }
    vm->PushFloat(CurrentGameTime() - it->second.started_at_turn);
}

static void N_GET_INCLUSION_DISTANCE(LHVM* vm) {
    vm->PushFloat(g_inclusion_distance);
}

// --- Game speed / temperature -----------------------------------------

static void N_START_GAME_SPEED(LHVM* /*vm*/) { g_game_speed = 1.0f; }
static void N_END_GAME_SPEED(LHVM* /*vm*/)   { g_game_speed = 0.0f; }
static void N_SET_TEMPERATURE(LHVM* vm)      { g_temperature = vm->PopFloat(); }

// --- Town interactions -------------------------------------------------

static void N_SET_ATTACK_OWN_TOWN(LHVM* vm) {
    g_attack_own_town = vm->PopBoolean();
    vm->PopObject();
}

static void N_CALL_BUILDING_IN_TOWN(LHVM* vm) {
    vm->PopObject();   // exclude
    vm->PopObject();   // town
    int32_t type = vm->PopInt();
    (void)type;
    vm->PushObject(0);
}

static void N_CALL_COMPUTER_PLAYER(LHVM* vm) {
    vm->PopFloat(); vm->PopFloat(); vm->PopFloat();
    vm->PopObject();
}

static void N_THING_JC_SPECIAL(LHVM* vm) {
    vm->PopObject(); vm->PopInt();
    vm->PushBoolean(false);
}

static void N_GAME_SUB_TYPE(LHVM* vm) {
    uint32_t h = vm->PopObject();
    Object* o = LookupObject(h);
    // Sub-type lives on each entity's info struct; without the info table
    // walk we report 0 (the "generic" subtype) so type-only IS_OF_TYPE wins.
    (void)o;
    vm->PushInt(0);
}

// --- Stop scripts -----------------------------------------------------

static void N_STOP_ALL_SCRIPTS_IN_FILES_EXCLUDING(LHVM* vm) { vm->PopInt(); }
static void N_STOP_SCRIPTS_IN_FILES(LHVM* vm)               { vm->PopInt(); }

// --- Snapshot / pictures (no-op until save subsystem) ----------------

static void N_SNAPSHOT(LHVM* vm) {
    vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat();
    vm->PopFloat(); vm->PopFloat(); vm->PopInt();
    vm->PushObject(0);
}
static void N_UPDATE_SNAPSHOT(LHVM* /*vm*/) {}
static void N_UPDATE_SNAPSHOT_PICTURE(LHVM* vm) {
    vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat();
}

// --- Dance subsystem -------------------------------------------------

static void N_DANCE_CREATE(LHVM* vm) {
    vm->PopFloat();   // duration
    vm->PopInt();     // dance type
    vm->PopFloat(); vm->PopFloat(); vm->PopFloat();   // pos
    vm->PopObject();  // owner
    uint32_t h = g_next_dance++;
    g_dance_members[h] = {};
    vm->PushObject(h);
}

static void N_CHANGE_INNER_OUTER_PROPERTIES(LHVM* vm) {
    vm->PopFloat(); vm->PopFloat(); vm->PopFloat();
}

// ============================================================================
// Chunk 8 — game state, save, mini-games, immersion, misc remainders (60+)
// ============================================================================

namespace {

uint32_t g_hit_object        = 0;
uint32_t g_object_which_hit  = 0;
uint32_t g_events_total      = 0;
float    g_events_last_time  = 0;
bool     g_high_graphics     = true;
bool     g_game_time_running = true;
bool     g_sun_draw          = true;

struct MiniGame {
    int32_t type        = 0;
    int32_t team_size   = 5;
    bool    in_progress = false;
    std::vector<uint32_t> attached_objects;
};
std::unordered_map<uint32_t, MiniGame> g_minigames;     // arena/footballpitch handle → state

struct ObjectExtras {
    bool   confined         = false;
    bool   hurt_by_fire     = true;
    bool   only_for_scripts = false;
    bool   open             = false;
    bool   draw_leash       = true;
    bool   draw_highlight   = true;
    bool   carrying         = false;
    int32_t leash_type      = 0;
    float  fade_value       = 1.0f;
    float  attacked_at      = -1e9f;
    int32_t action_count    = 0;
    int32_t mist_fade       = 0;
};
std::unordered_map<uint32_t, ObjectExtras> g_extras;

ObjectExtras& Extras(uint32_t h) { return g_extras[h]; }

uint32_t   g_save_slot       = 0;
bool       g_immersion_on    = false;
int32_t    g_active_immersion= 0;

} // namespace

// --- Mini-games (arenas, football, hanoi, dance) ----------------------

static void N_GET_ARENA(LHVM* vm) {
    vm->PopFloat();   // size
    vm->PopFloat(); vm->PopFloat(); vm->PopFloat();   // pos
    EntityCreateParams p = {};
    p.scale = 1.0f;
    Object* obj = EntityFactory::CreateEntity(ENTITY_CAT_FEATURE, p);
    uint32_t h = HandleFor(obj);
    if (h) g_minigames[h] = {};
    vm->PushObject(h);
}

static void N_GET_FOOTBALL_PITCH(LHVM* vm) {
    vm->PopObject();  // town
    EntityCreateParams p = {};
    p.scale = 1.0f;
    Object* obj = EntityFactory::CreateEntity(ENTITY_CAT_FEATURE, p);
    uint32_t h = HandleFor(obj);
    if (h) g_minigames[h] = {};
    vm->PushObject(h);
}

static void N_STOP_ALL_GAMES(LHVM* vm) {
    vm->PopObject();  // owner
    for (auto& kv : g_minigames) kv.second.in_progress = false;
}

static void N_ATTACH_TO_GAME(LHVM* vm) {
    int32_t  side = vm->PopInt();
    uint32_t obj  = vm->PopObject();
    uint32_t game = vm->PopObject();
    (void)side;
    g_minigames[game].attached_objects.push_back(obj);
}

static void N_DETACH_FROM_GAME(LHVM* vm) {
    int32_t  side = vm->PopInt();
    uint32_t obj  = vm->PopObject();
    uint32_t game = vm->PopObject();
    (void)side;
    auto& v = g_minigames[game].attached_objects;
    for (auto i = v.begin(); i != v.end(); ++i) if (*i == obj) { v.erase(i); break; }
}

static void N_DETACH_UNDEFINED_FROM_GAME(LHVM* vm) {
    uint32_t game = vm->PopObject();
    g_minigames[game].attached_objects.clear();
}

static void N_SET_ONLY_FOR_SCRIPTS(LHVM* vm) {
    bool on = vm->PopBoolean();
    uint32_t h = vm->PopObject();
    Extras(h).only_for_scripts = on;
}

static void N_START_MATCH_WITH_REFEREE(LHVM* vm) {
    vm->PopInt();       // referee count
    uint32_t game = vm->PopObject();
    g_minigames[game].in_progress = true;
}

static void N_GAME_TEAM_SIZE(LHVM* vm) {
    int32_t  size = vm->PopInt();
    uint32_t game = vm->PopObject();
    g_minigames[game].team_size = size;
}

// --- Hit tracking -----------------------------------------------------

static void N_GET_HIT_OBJECT(LHVM* vm)        { vm->PushObject(g_hit_object); }
static void N_GET_OBJECT_WHICH_HIT(LHVM* vm)  { vm->PushObject(g_object_which_hit); }

// --- Event metering ---------------------------------------------------

static void N_GET_EVENTS_PER_SECOND(LHVM* vm) {
    int32_t event = vm->PopInt();
    (void)event;
    float now = CurrentGameTime();
    float dt  = now - g_events_last_time;
    vm->PushFloat(dt > 0 ? static_cast<float>(g_events_total) / dt : 0.0f);
}
static void N_GET_TIME_SINCE(LHVM* vm) {
    int32_t event = vm->PopInt();
    (void)event;
    vm->PushFloat(CurrentGameTime() - g_events_last_time);
}
static void N_GET_TOTAL_EVENTS(LHVM* vm) {
    int32_t event = vm->PopInt();
    (void)event;
    vm->PushInt(static_cast<int32_t>(g_events_total));
}

// --- Object spawn helpers --------------------------------------------

static void N_CREATE_WITH_ANGLE_AND_SCALE(LHVM* vm) {
    float scale  = vm->PopFloat();
    float angle  = vm->PopFloat();
    float z = vm->PopFloat(), y = vm->PopFloat(), x = vm->PopFloat();
    int32_t  subtype = vm->PopInt();
    int32_t  type    = vm->PopInt();
    (void)y;
    EntityCreateParams p = {};
    p.world_x = x; p.world_z = z; p.angle = angle;
    p.scale = scale > 0 ? scale : 1.0f;
    p.type_enum = static_cast<uint32_t>(subtype);
    Object* obj = EntityFactory::CreateEntity(CategoryForScriptType(type), p);
    vm->PushObject(HandleFor(obj));
}

// --- Visual / fade ---------------------------------------------------

static void N_SET_VIRTUAL_INFLUENCE(LHVM* vm) {
    bool on = vm->PopBoolean();
    uint32_t h = vm->PopObject();
    if (on) Extras(h).only_for_scripts = true;
}

static void N_SET_MIST_FADE(LHVM* vm) {
    int32_t  amt = vm->PopInt();
    uint32_t h   = vm->PopObject();
    Extras(h).mist_fade = amt;
}

static void N_GET_OBJECT_FADE(LHVM* vm) {
    uint32_t h = vm->PopObject();
    auto it = g_extras.find(h);
    vm->PushFloat(it == g_extras.end() ? 1.0f : it->second.fade_value);
}

static void N_SET_OBJECT_FADE_IN(LHVM* vm) {
    vm->PopFloat();   // duration
    uint32_t h = vm->PopObject();
    Extras(h).fade_value = 1.0f;
}

// --- Hand demo / interaction --------------------------------------

static void N_IS_PLAYING_HAND_DEMO(LHVM* vm) { vm->PushBoolean(g_hand_demo_playing); }
static void N_GET_ARSE_POSITION(LHVM* vm) {
    uint32_t h = vm->PopObject();
    Object* o = LookupObject(h);
    if (o) { vm->PushFloat(WorldX(o)); vm->PushFloat(WorldY(o)); vm->PushFloat(WorldZ(o)); }
    else   { vm->PushFloat(0); vm->PushFloat(0); vm->PushFloat(0); }
}
static void N_GET_BELLY_POSITION(LHVM* vm) {
    uint32_t h = vm->PopObject();
    Object* o = LookupObject(h);
    if (o) { vm->PushFloat(WorldX(o)); vm->PushFloat(WorldY(o) + 2); vm->PushFloat(WorldZ(o)); }
    else   { vm->PushFloat(0); vm->PushFloat(0); vm->PushFloat(0); }
}
static void N_GET_OBJECT_HELD_273(LHVM* vm) { vm->PopObject(); vm->PushObject(0); }
static void N_GET_ACTION_COUNT(LHVM* vm) {
    uint32_t h = vm->PopObject();
    auto it = g_extras.find(h);
    vm->PushInt(it == g_extras.end() ? 0 : it->second.action_count);
}
static void N_GET_OBJECT_LEASH_TYPE(LHVM* vm) {
    uint32_t h = vm->PopObject();
    auto it = g_extras.find(h);
    vm->PushInt(it == g_extras.end() ? 0 : it->second.leash_type);
}

// --- Cinematic / time controls ------------------------------------

static void N_START_ANGLE_SOUND_285(LHVM* vm) { vm->PopInt(); vm->PopObject(); }
static void N_START_ANGLE_SOUND_348(LHVM* vm) { vm->PopInt(); vm->PopObject(); }
static void N_GAME_TIME_ON_OFF(LHVM* vm)      { g_game_time_running = vm->PopBoolean(); }
static void N_MOVE_GAME_TIME(LHVM* vm) {
    g_game_time_base += vm->PopFloat();   // delta hours
    vm->PopFloat();                       // duration
}
static void N_SET_HIGH_GRAPHICS_DETAIL(LHVM* vm) { g_high_graphics = vm->PopBoolean(); vm->PopObject(); }
static void N_ADD_SPOT_VISUAL_TARGET_POS(LHVM* vm) {
    vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopObject();
}
static void N_ADD_SPOT_VISUAL_TARGET_OBJECT(LHVM* vm) { vm->PopObject(); vm->PopObject(); }

// --- Focus / immersion --------------------------------------------

static void N_SET_FOCUS_ON_OBJECT(LHVM* vm)    { g_cam_follow.focus_target = vm->PopObject(); vm->PopObject(); }
static void N_RELEASE_OBJECT_FOCUS(LHVM* vm)   { vm->PopObject(); g_cam_follow.focus_target = 0; }
static void N_IMMERSION_EXISTS(LHVM* vm)        { vm->PushBoolean(g_immersion_on); }
static void N_START_IMMERSION(LHVM* vm)         { g_active_immersion = vm->PopInt(); vm->PopObject(); g_immersion_on = true; }
static void N_STOP_IMMERSION(LHVM* vm)          { vm->PopInt(); vm->PopObject(); g_immersion_on = false; }
static void N_STOP_ALL_IMMERSION(LHVM* /*vm*/) { g_immersion_on = false; }
static void N_MAP_SCRIPT_FUNCTION(LHVM* vm)     { vm->PopInt(); vm->PopObject(); }

// --- Drawing toggles ----------------------------------------------

static void N_SET_DRAW_LEASH(LHVM* vm)     { bool b = vm->PopBoolean(); uint32_t h = vm->PopObject(); Extras(h).draw_leash = b; }
static void N_SET_DRAW_HIGHLIGHT(LHVM* vm) { bool b = vm->PopBoolean(); uint32_t h = vm->PopObject(); Extras(h).draw_highlight = b; }
static void N_SET_OPEN_CLOSE(LHVM* vm)     { bool b = vm->PopBoolean(); uint32_t h = vm->PopObject(); Extras(h).open = b; }
static void N_SET_INTRO_BUILDING(LHVM* vm) { vm->PopBoolean(); vm->PopObject(); }
static void N_SET_SUN_DRAW(LHVM* vm)       { g_sun_draw = vm->PopBoolean(); }
static void N_SET_HURT_BY_FIRE(LHVM* vm)   { bool b = vm->PopBoolean(); uint32_t h = vm->PopObject(); Extras(h).hurt_by_fire = b; }
static void N_CONFINED_OBJECT(LHVM* vm) {
    vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat();
    uint32_t h = vm->PopObject();
    Extras(h).confined = true;
}
static void N_CLEAR_CONFINED_OBJECT(LHVM* vm) {
    uint32_t h = vm->PopObject();
    Extras(h).confined = false;
}
static void N_HIGHLIGHT_PROPERTIES(LHVM* vm) {
    vm->PopInt(); vm->PopInt(); vm->PopObject();
}

// --- Misc -----------------------------------------------------------

static void N_CALL_NEAR_IN_STATE(LHVM* vm) {
    int32_t state = vm->PopInt();
    float radius = vm->PopFloat();
    float z = vm->PopFloat(), y = vm->PopFloat(), x = vm->PopFloat();
    uint32_t player_or_filter = vm->PopObject();
    uint32_t target = vm->PopObject();
    (void)state; (void)radius; (void)x; (void)y; (void)z;
    (void)player_or_filter; (void)target;
}

static void N_PLAY_JC_SPECIAL(LHVM* vm) { vm->PopInt(); vm->PopObject(); }
static void N_IS_PLAYING_JC_SPECIAL(LHVM* vm) { vm->PopObject(); vm->PushBoolean(false); }

static void N_IS_LOCKED_INTERACTION(LHVM* vm) {
    vm->PopObject();
    vm->PushBoolean(g_dialogue.active);
}

static void N_ENTER_EXIT_CITADEL(LHVM* vm) {
    vm->PopBoolean(); vm->PopObject();
}

static void N_MUSIC_PLAYED_350(LHVM* vm) { vm->PopInt(); vm->PushBoolean(g_audio.music_playing); }

static void N_TOGGLE_LEASH(LHVM* vm) {
    uint32_t h = vm->PopObject();
    Slot* s = SlotOf(h);
    if (s) s->flags ^= FLAG_LEASHED;
}

static void N_SET_GAME_SOUND(LHVM* vm) { g_audio.game_sound_on = vm->PopBoolean(); }

static void N_SEX_IS_MALE(LHVM* vm) {
    vm->PopObject();
    vm->PushBoolean(true);   // unwired sex bit; default true keeps scripts moving
}

static void N_SET_SCAFFOLD_PROPERTIES(LHVM* vm) {
    vm->PopInt(); vm->PopInt(); vm->PopFloat(); vm->PopObject();
}

static void N_SET_DISCIPLE(LHVM* vm) {
    vm->PopInt(); vm->PopObject();
}

static void N_SET_SET_ON_FIRE(LHVM* vm) {
    vm->PopFloat();   // strength
    uint32_t h = vm->PopObject();
    Slot* s = SlotOf(h);
    if (s) s->flags |= FLAG_ON_FIRE;
}

static void N_SET_OBJECT_CARRYING(LHVM* vm) {
    int32_t carrying = vm->PopInt();
    uint32_t h = vm->PopObject();
    Extras(h).carrying = (carrying != 0);
}

static void N_GET_TIME_SINCE_OBJECT_ATTACKED(LHVM* vm) {
    vm->PopObject();   // player
    uint32_t h = vm->PopObject();
    auto it = g_extras.find(h);
    if (it == g_extras.end()) { vm->PushFloat(99999.0f); return; }
    vm->PushFloat(CurrentGameTime() - it->second.attacked_at);
}

static void N_SET_FIXED_CAM_ROTATION(LHVM* vm) {
    vm->PopFloat(); vm->PopFloat(); vm->PopFloat();
}

// --- Save / tutorial ----------------------------------------------

static void N_SAVE_GAME_IN_SLOT(LHVM* vm) { g_save_slot = static_cast<uint32_t>(vm->PopInt()); }
static void N_CAN_SKIP_TUTORIAL(LHVM* vm) { vm->PushBoolean(true); }

// ============================================================================
// Registration
// ============================================================================

void RegisterObjectNatives(LHVM* vm) {
    vm->RegisterNativeFunction(NATIVE_GET_POSITION,                 "GET_POSITION",                 N_GET_POSITION);
    vm->RegisterNativeFunction(NATIVE_SET_POSITION,                 "SET_POSITION",                 N_SET_POSITION);
    vm->RegisterNativeFunction(NATIVE_MOVE_GAME_THING,              "MOVE_GAME_THING",              N_MOVE_GAME_THING);
    vm->RegisterNativeFunction(NATIVE_CREATE,                       "CREATE",                       N_CREATE);
    vm->RegisterNativeFunction(NATIVE_OBJECT_DELETE,                "OBJECT_DELETE",                N_OBJECT_DELETE);
    vm->RegisterNativeFunction(NATIVE_THING_VALID,                  "THING_VALID",                  N_THING_VALID);
    vm->RegisterNativeFunction(NATIVE_IS_OF_TYPE,                   "IS_OF_TYPE",                   N_IS_OF_TYPE);
    vm->RegisterNativeFunction(NATIVE_GET_PROPERTY,                 "GET_PROPERTY",                 N_GET_PROPERTY);
    vm->RegisterNativeFunction(NATIVE_SET_PROPERTY,                 "SET_PROPERTY",                 N_SET_PROPERTY);
    vm->RegisterNativeFunction(NATIVE_GET_OBJECT_HAND_IS_OVER,      "GET_OBJECT_HAND_IS_OVER",      N_GET_OBJECT_HAND_IS_OVER);
    vm->RegisterNativeFunction(NATIVE_GET_HAND_POSITION,            "GET_HAND_POSITION",            N_GET_HAND_POSITION);
    vm->RegisterNativeFunction(NATIVE_GET_HAND_STATE,               "GET_HAND_STATE",               N_GET_HAND_STATE);
    vm->RegisterNativeFunction(NATIVE_GET_LAND_HEIGHT,              "GET_LAND_HEIGHT",              N_GET_LAND_HEIGHT);
    vm->RegisterNativeFunction(NATIVE_SET_FOCUS,                    "SET_FOCUS",                    N_SET_FOCUS);
    vm->RegisterNativeFunction(NATIVE_SET_TARGET,                   "SET_TARGET",                   N_SET_TARGET);
    vm->RegisterNativeFunction(NATIVE_SET_HEADING_AND_SPEED,        "SET_HEADING_AND_SPEED",        N_SET_HEADING_AND_SPEED);
    vm->RegisterNativeFunction(NATIVE_GET_OBJECT_DESTINATION,       "GET_OBJECT_DESTINATION",       N_GET_OBJECT_DESTINATION);
    vm->RegisterNativeFunction(NATIVE_GET_OBJECT_STATE,             "GET_OBJECT_STATE",             N_GET_OBJECT_STATE);
    vm->RegisterNativeFunction(NATIVE_IS_LEASHED,                   "IS_LEASHED",                   N_IS_LEASHED);
    vm->RegisterNativeFunction(NATIVE_IS_LEASHED_TO_OBJECT,         "IS_LEASHED_TO_OBJECT",         N_IS_LEASHED_TO_OBJECT);
    vm->RegisterNativeFunction(NATIVE_IS_FIGHTING,                  "IS_FIGHTING",                  N_IS_FIGHTING);
    vm->RegisterNativeFunction(NATIVE_GET_RESOURCE,                 "GET_RESOURCE",                 N_GET_RESOURCE);
    vm->RegisterNativeFunction(NATIVE_ADD_RESOURCE,                 "ADD_RESOURCE",                 N_ADD_RESOURCE);
    vm->RegisterNativeFunction(NATIVE_REMOVE_RESOURCE,              "REMOVE_RESOURCE",              N_REMOVE_RESOURCE);
    vm->RegisterNativeFunction(NATIVE_IS_ON_FIRE,                   "IS_ON_FIRE",                   N_IS_ON_FIRE);
    vm->RegisterNativeFunction(NATIVE_IS_FIRE_NEAR,                 "IS_FIRE_NEAR",                 N_IS_FIRE_NEAR);
    vm->RegisterNativeFunction(NATIVE_SET_ON_FIRE,                  "SET_ON_FIRE",                  N_SET_ON_FIRE);
    vm->RegisterNativeFunction(NATIVE_IS_POISONED,                  "IS_POISONED",                  N_IS_POISONED);
    vm->RegisterNativeFunction(NATIVE_SET_POISONED,                 "SET_POISONED",                 N_SET_POISONED);
    vm->RegisterNativeFunction(NATIVE_IS_SKELETON,                  "IS_SKELETON",                  N_IS_SKELETON);
    vm->RegisterNativeFunction(NATIVE_SET_SKELETON,                 "SET_SKELETON",                 N_SET_SKELETON);
    vm->RegisterNativeFunction(NATIVE_SET_INDESTRUCTABLE,           "SET_INDESTRUCTABLE",           N_SET_INDESTRUCTABLE);
    vm->RegisterNativeFunction(NATIVE_SET_ID_MOVEABLE,              "SET_ID_MOVEABLE",              N_SET_ID_MOVEABLE);
    vm->RegisterNativeFunction(NATIVE_SET_ID_PICKUPABLE,            "SET_ID_PICKUPABLE",            N_SET_ID_PICKUPABLE);
    vm->RegisterNativeFunction(NATIVE_SET_ACTIVE,                   "SET_ACTIVE",                   N_SET_ACTIVE);
    vm->RegisterNativeFunction(NATIVE_IS_ACTIVE,                    "IS_ACTIVE",                    N_IS_ACTIVE);
    vm->RegisterNativeFunction(NATIVE_RELEASE_FROM_SCRIPT,          "RELEASE_FROM_SCRIPT",          N_RELEASE_FROM_SCRIPT);
    vm->RegisterNativeFunction(NATIVE_IS_CREATURE_AVAILABLE,        "IS_CREATURE_AVAILABLE",        N_IS_CREATURE_AVAILABLE);
    vm->RegisterNativeFunction(NATIVE_GET_INFLUENCE,                "GET_INFLUENCE",                N_GET_INFLUENCE);
    vm->RegisterNativeFunction(NATIVE_GET_MANA,                     "GET_MANA",                     N_GET_MANA);
    vm->RegisterNativeFunction(NATIVE_BELIEF_FOR_PLAYER,            "BELIEF_FOR_PLAYER",            N_BELIEF_FOR_PLAYER);
    vm->RegisterNativeFunction(NATIVE_GET_ALIGNMENT,                "GET_ALIGNMENT",                N_GET_ALIGNMENT);
    vm->RegisterNativeFunction(NATIVE_SET_ALIGNMENT,                "SET_ALIGNMENT",                N_SET_ALIGNMENT);
    vm->RegisterNativeFunction(NATIVE_GAME_THING_CLICKED,           "GAME_THING_CLICKED",           N_GAME_THING_CLICKED);
    vm->RegisterNativeFunction(NATIVE_GET_OBJECT_CLICKED,           "GET_OBJECT_CLICKED",           N_GET_OBJECT_CLICKED);
    vm->RegisterNativeFunction(NATIVE_POSITION_CLICKED,             "POSITION_CLICKED",             N_POSITION_CLICKED);
    vm->RegisterNativeFunction(NATIVE_CLEAR_CLICKED_OBJECT,         "CLEAR_CLICKED_OBJECT",         N_CLEAR_CLICKED_OBJECT);
    vm->RegisterNativeFunction(NATIVE_CLEAR_CLICKED_POSITION,       "CLEAR_CLICKED_POSITION",       N_CLEAR_CLICKED_POSITION);
    vm->RegisterNativeFunction(NATIVE_GET_TOWN_WITH_ID,             "GET_TOWN_WITH_ID",             N_GET_TOWN_WITH_ID);
    vm->RegisterNativeFunction(NATIVE_GET_NEAREST_TOWN_OF_PLAYER,   "GET_NEAREST_TOWN_OF_PLAYER",   N_GET_NEAREST_TOWN_OF_PLAYER);
    vm->RegisterNativeFunction(NATIVE_GET_PLAYER_TOWN_TOTAL,        "GET_PLAYER_TOWN_TOTAL",        N_GET_PLAYER_TOWN_TOTAL);
    vm->RegisterNativeFunction(NATIVE_GET_DESIRE,                   "GET_DESIRE",                   N_GET_DESIRE);

    // --- Chunk 2: spatial / flock / script-object types (50) ---
    vm->RegisterNativeFunction(NATIVE_FLOCK_CREATE,                 "FLOCK_CREATE",                 N_FLOCK_CREATE);
    vm->RegisterNativeFunction(NATIVE_FLOCK_ATTACH,                 "FLOCK_ATTACH",                 N_FLOCK_ATTACH);
    vm->RegisterNativeFunction(NATIVE_FLOCK_DETACH,                 "FLOCK_DETACH",                 N_FLOCK_DETACH);
    vm->RegisterNativeFunction(NATIVE_FLOCK_DISBAND,                "FLOCK_DISBAND",                N_FLOCK_DISBAND);
    vm->RegisterNativeFunction(NATIVE_FLOCK_MEMBER,                 "FLOCK_MEMBER",                 N_FLOCK_MEMBER);
    vm->RegisterNativeFunction(NATIVE_FLOCK_WITHIN_LIMITS,          "FLOCK_WITHIN_LIMITS",          N_FLOCK_WITHIN_LIMITS);
    vm->RegisterNativeFunction(NATIVE_GET_OBJECT_FLOCK,             "GET_OBJECT_FLOCK",             N_GET_OBJECT_FLOCK);
    vm->RegisterNativeFunction(NATIVE_ID_SIZE,                      "ID_SIZE",                      N_ID_SIZE);
    vm->RegisterNativeFunction(NATIVE_GET_FIRST_IN_CONTAINER,       "GET_FIRST_IN_CONTAINER",       N_GET_FIRST_IN_CONTAINER);
    vm->RegisterNativeFunction(NATIVE_GET_NEXT_IN_CONTAINER,        "GET_NEXT_IN_CONTAINER",        N_GET_NEXT_IN_CONTAINER);
    vm->RegisterNativeFunction(NATIVE_CREATE_REWARD,                "CREATE_REWARD",                N_CREATE_REWARD);
    vm->RegisterNativeFunction(NATIVE_CREATE_REWARD_IN_TOWN,        "CREATE_REWARD_IN_TOWN",        N_CREATE_REWARD_IN_TOWN);
    vm->RegisterNativeFunction(NATIVE_CREATE_RANDOM_VILLAGER_OF_TRIBE, "CREATE_RANDOM_VILLAGER_OF_TRIBE", N_CREATE_RANDOM_VILLAGER_OF_TRIBE);
    vm->RegisterNativeFunction(NATIVE_CREATE_MIST,                  "CREATE_MIST",                  N_CREATE_MIST);
    vm->RegisterNativeFunction(NATIVE_LOAD_CREATURE,                "LOAD_CREATURE",                N_LOAD_CREATURE);
    vm->RegisterNativeFunction(NATIVE_LOAD_MY_CREATURE,             "LOAD_MY_CREATURE",             N_LOAD_MY_CREATURE);
    vm->RegisterNativeFunction(NATIVE_OBJECT_CAPACITY,              "OBJECT_CAPACITY",              N_OBJECT_CAPACITY);
    vm->RegisterNativeFunction(NATIVE_OBJECT_ADULT_CAPACITY,        "OBJECT_ADULT_CAPACITY",        N_OBJECT_ADULT_CAPACITY);
    vm->RegisterNativeFunction(NATIVE_ID_ADULT_SIZE,                "ID_ADULT_SIZE",                N_ID_ADULT_SIZE);
    vm->RegisterNativeFunction(NATIVE_INSIDE_TEMPLE,                "INSIDE_TEMPLE",                N_INSIDE_TEMPLE);
    vm->RegisterNativeFunction(NATIVE_IS_AFFECTED_BY_SPELL,         "IS_AFFECTED_BY_SPELL",         N_IS_AFFECTED_BY_SPELL);
    vm->RegisterNativeFunction(NATIVE_IS_AUTO_FIGHTING,             "IS_AUTO_FIGHTING",             N_IS_AUTO_FIGHTING);
    vm->RegisterNativeFunction(NATIVE_IS_SPELL_CHARGING,            "IS_SPELL_CHARGING",            N_IS_SPELL_CHARGING);
    vm->RegisterNativeFunction(NATIVE_IS_THAT_SPELL_CHARGING,       "IS_THAT_SPELL_CHARGING",       N_IS_THAT_SPELL_CHARGING);
    vm->RegisterNativeFunction(NATIVE_POS_VALID_FOR_CREATURE,       "POS_VALID_FOR_CREATURE",       N_POS_VALID_FOR_CREATURE);
    vm->RegisterNativeFunction(NATIVE_GET_TEMPLE_POSITION,          "GET_TEMPLE_POSITION",          N_GET_TEMPLE_POSITION);
    vm->RegisterNativeFunction(NATIVE_GET_TEMPLE_ENTRANCE_POSITION, "GET_TEMPLE_ENTRANCE_POSITION", N_GET_TEMPLE_ENTRANCE_POSITION);
    vm->RegisterNativeFunction(NATIVE_GET_LAST_SPELL_CAST_POS,      "GET_LAST_SPELL_CAST_POS",      N_GET_LAST_SPELL_CAST_POS);
    vm->RegisterNativeFunction(NATIVE_GET_FACING_CAMERA_POSITION,   "GET_FACING_CAMERA_POSITION",   N_GET_FACING_CAMERA_POSITION);
    vm->RegisterNativeFunction(NATIVE_GET_COMPUTER_PLAYER_POSITION, "GET_COMPUTER_PLAYER_POSITION", N_GET_COMPUTER_PLAYER_POSITION);
    vm->RegisterNativeFunction(NATIVE_SET_COMPUTER_PLAYER_POSITION, "SET_COMPUTER_PLAYER_POSITION", N_SET_COMPUTER_PLAYER_POSITION);
    vm->RegisterNativeFunction(NATIVE_MOVE_COMPUTER_PLAYER_POSITION,"MOVE_COMPUTER_PLAYER_POSITION",N_MOVE_COMPUTER_PLAYER_POSITION);
    vm->RegisterNativeFunction(NATIVE_RESTART_OBJECT,               "RESTART_OBJECT",               N_RESTART_OBJECT);
    vm->RegisterNativeFunction(NATIVE_OBJECT_CAST_BY_OBJECT,        "OBJECT_CAST_BY_OBJECT",        N_OBJECT_CAST_BY_OBJECT);
    vm->RegisterNativeFunction(NATIVE_OPPOSING_CREATURE,            "OPPOSING_CREATURE",            N_OPPOSING_CREATURE);
    vm->RegisterNativeFunction(NATIVE_GET_DEAD_LIVING,              "GET_DEAD_LIVING",              N_GET_DEAD_LIVING);
    vm->RegisterNativeFunction(NATIVE_GET_FIRST_HELP,               "GET_FIRST_HELP",               N_GET_FIRST_HELP);
    vm->RegisterNativeFunction(NATIVE_GET_LAST_HELP,                "GET_LAST_HELP",                N_GET_LAST_HELP);
    vm->RegisterNativeFunction(NATIVE_GET_HELP,                     "GET_HELP",                     N_GET_HELP);
    vm->RegisterNativeFunction(NATIVE_OBJECT_RELATIVE_BELIEF,       "OBJECT_RELATIVE_BELIEF",       N_OBJECT_RELATIVE_BELIEF);
    vm->RegisterNativeFunction(NATIVE_GET_TOTEM_STATUE,             "GET_TOTEM_STATUE",             N_GET_TOTEM_STATUE);
    vm->RegisterNativeFunction(NATIVE_GET_SPELL_ICON_IN_TEMPLE,     "GET_SPELL_ICON_IN_TEMPLE",     N_GET_SPELL_ICON_IN_TEMPLE);
    vm->RegisterNativeFunction(NATIVE_WITHIN_ROTATION,              "WITHIN_ROTATION",              N_WITHIN_ROTATION);
    vm->RegisterNativeFunction(NATIVE_GET_TOWN_WORSHIP_DEATHS,      "GET_TOWN_WORSHIP_DEATHS",      N_GET_TOWN_WORSHIP_DEATHS);
    vm->RegisterNativeFunction(NATIVE_GET_TOWN_AND_VILLAGER_HEALTH_TOTAL, "GET_TOWN_AND_VILLAGER_HEALTH_TOTAL", N_GET_TOWN_AND_VILLAGER_HEALTH);
    vm->RegisterNativeFunction(NATIVE_GET_SACRIFICE_TOTAL,           "GET_SACRIFICE_TOTAL",           N_GET_SACRIFICE_TOTAL2);
    vm->RegisterNativeFunction(NATIVE_GAME_ADD_FOR_BUILDING,         "GAME_ADD_FOR_BUILDING",         N_GAME_ADD_FOR_BUILDING2);
    vm->RegisterNativeFunction(NATIVE_PLAYER_SPELL_CAST_TIME,       "PLAYER_SPELL_CAST_TIME",       N_PLAYER_SPELL_CAST_TIME);
    vm->RegisterNativeFunction(NATIVE_PLAYER_SPELL_LAST_CAST,       "PLAYER_SPELL_LAST_CAST",       N_PLAYER_SPELL_LAST_CAST);
    vm->RegisterNativeFunction(NATIVE_GET_MANA_FOR_SPELL,           "GET_MANA_FOR_SPELL",           N_GET_MANA_FOR_SPELL);
    vm->RegisterNativeFunction(NATIVE_SET_CREATURE_AUTO_FIGHTING,   "SET_CREATURE_AUTO_FIGHTING",   N_SET_CREATURE_AUTO_FIGHTING);
    vm->RegisterNativeFunction(NATIVE_SET_FIGHT_EXIT,               "SET_FIGHT_EXIT",               N_SET_FIGHT_EXIT);
    vm->RegisterNativeFunction(NATIVE_SET_CAN_BUILD_WORSHIPSITE,    "SET_CAN_BUILD_WORSHIPSITE",    N_SET_CAN_BUILD_WORSHIPSITE);
    vm->RegisterNativeFunction(NATIVE_SET_MAGIC_IN_OBJECT,          "SET_MAGIC_IN_OBJECT",          N_SET_MAGIC_IN_OBJECT);
    vm->RegisterNativeFunction(NATIVE_SET_MAGIC_PROPERTIES,         "SET_MAGIC_PROPERTIES",         N_SET_MAGIC_PROPERTIES);

    // --- Chunk 3: creature mind / belief / desire (50) ---
    vm->RegisterNativeFunction(NATIVE_CREATURE_LEARN_EVERYTHING,            "CREATURE_LEARN_EVERYTHING",            N_CREATURE_LEARN_EVERYTHING);
    vm->RegisterNativeFunction(NATIVE_CREATURE_LEARN_EVERYTHING_EXCLUDING,  "CREATURE_LEARN_EVERYTHING_EXCLUDING",  N_CREATURE_LEARN_EVERYTHING_EXCLUDING);
    vm->RegisterNativeFunction(NATIVE_CREATURE_SET_KNOWS_ACTION,            "CREATURE_SET_KNOWS_ACTION",            N_CREATURE_SET_KNOWS_ACTION);
    vm->RegisterNativeFunction(NATIVE_CREATURE_LEARN_DISTINCTION_ABOUT_ACTIVITY_OBJECT, "CREATURE_LEARN_DISTINCTION_ABOUT_ACTIVITY_OBJECT", N_CREATURE_LEARN_DISTINCTION);
    vm->RegisterNativeFunction(NATIVE_CREATURE_SET_AGENDA_PRIORITY,         "CREATURE_SET_AGENDA_PRIORITY",         N_CREATURE_SET_AGENDA_PRIORITY);
    vm->RegisterNativeFunction(NATIVE_CREATURE_TURN_OFF_ALL_DESIRES,        "CREATURE_TURN_OFF_ALL_DESIRES",        N_CREATURE_TURN_OFF_ALL_DESIRES);
    vm->RegisterNativeFunction(NATIVE_CREATURE_SET_DESIRE_VALUE,            "CREATURE_SET_DESIRE_VALUE",            N_CREATURE_SET_DESIRE_VALUE);
    vm->RegisterNativeFunction(NATIVE_CREATURE_SET_DESIRE_ACTIVATED_78,     "CREATURE_SET_DESIRE_ACTIVATED_78",     N_CREATURE_SET_DESIRE_ACTIVATED);
    vm->RegisterNativeFunction(NATIVE_CREATURE_SET_DESIRE_ACTIVATED_79,     "CREATURE_SET_DESIRE_ACTIVATED_79",     N_CREATURE_SET_DESIRE_ACTIVATED);
    vm->RegisterNativeFunction(NATIVE_CREATURE_SET_DESIRE_MAXIMUM,          "CREATURE_SET_DESIRE_MAXIMUM",          N_CREATURE_SET_DESIRE_MAXIMUM);
    vm->RegisterNativeFunction(NATIVE_CREATURE_DESIRE_IS,                   "CREATURE_DESIRE_IS",                   N_CREATURE_DESIRE_IS);
    vm->RegisterNativeFunction(NATIVE_SET_CREATURE_ONLY_DESIRE,             "SET_CREATURE_ONLY_DESIRE",             N_SET_CREATURE_ONLY_DESIRE);
    vm->RegisterNativeFunction(NATIVE_SET_CREATURE_ONLY_DESIRE_OFF,         "SET_CREATURE_ONLY_DESIRE_OFF",         N_SET_CREATURE_ONLY_DESIRE_OFF);
    vm->RegisterNativeFunction(NATIVE_CREATURE_DO_ACTION,                   "CREATURE_DO_ACTION",                   N_CREATURE_DO_ACTION);
    vm->RegisterNativeFunction(NATIVE_CREATURE_INITIALISE_NUM_TIMES_PERFORMED_ACTION, "CREATURE_INITIALISE_NUM_TIMES_PERFORMED_ACTION", N_CREATURE_INITIALISE_NUM_TIMES);
    vm->RegisterNativeFunction(NATIVE_CREATURE_GET_NUM_TIMES_ACTION_PERFORMED, "CREATURE_GET_NUM_TIMES_ACTION_PERFORMED", N_CREATURE_GET_NUM_TIMES);
    vm->RegisterNativeFunction(NATIVE_CREATURE_FORCE_FINISH,                "CREATURE_FORCE_FINISH",                N_CREATURE_FORCE_FINISH);
    vm->RegisterNativeFunction(NATIVE_CALL_PLAYER_CREATURE,                 "CALL_PLAYER_CREATURE",                 N_CALL_PLAYER_CREATURE);
    vm->RegisterNativeFunction(NATIVE_CREATURE_SET_PLAYER,                  "CREATURE_SET_PLAYER",                  N_CREATURE_SET_PLAYER);
    vm->RegisterNativeFunction(NATIVE_SET_CREATURE_HOME,                    "SET_CREATURE_HOME",                    N_SET_CREATURE_HOME);
    vm->RegisterNativeFunction(NATIVE_SET_CREATURE_NAME,                    "SET_CREATURE_NAME",                    N_SET_CREATURE_NAME);
    vm->RegisterNativeFunction(NATIVE_SET_CREATURE_HELP,                    "SET_CREATURE_HELP",                    N_SET_CREATURE_HELP);
    vm->RegisterNativeFunction(NATIVE_SET_CREATURE_DEV_STAGE,               "SET_CREATURE_DEV_STAGE",               N_SET_CREATURE_DEV_STAGE);
    vm->RegisterNativeFunction(NATIVE_SET_CREATURE_SOUND,                   "SET_CREATURE_SOUND",                   N_SET_CREATURE_SOUND);
    vm->RegisterNativeFunction(NATIVE_SET_CREATURE_IN_TEMPLE,               "SET_CREATURE_IN_TEMPLE",               N_SET_CREATURE_IN_TEMPLE);
    vm->RegisterNativeFunction(NATIVE_CREATURE_AUTOSCALE,                   "CREATURE_AUTOSCALE",                   N_CREATURE_AUTOSCALE);
    vm->RegisterNativeFunction(NATIVE_SET_CREATURE_CREED_PROPERTIES,        "SET_CREATURE_CREED_PROPERTIES",        N_SET_CREATURE_CREED_PROPERTIES);
    vm->RegisterNativeFunction(NATIVE_SET_OBJECT_BELIEF_SCALE,              "SET_OBJECT_BELIEF_SCALE",              N_SET_OBJECT_BELIEF_SCALE);
    vm->RegisterNativeFunction(NATIVE_CREATURE_REACTION,                    "CREATURE_REACTION",                    N_CREATURE_REACTION);
    vm->RegisterNativeFunction(NATIVE_CREATURE_IN_DEV_SCRIPT,               "CREATURE_IN_DEV_SCRIPT",               N_CREATURE_IN_DEV_SCRIPT);
    vm->RegisterNativeFunction(NATIVE_CREATURE_FORCE_FRIENDS,               "CREATURE_FORCE_FRIENDS",               N_CREATURE_FORCE_FRIENDS);
    vm->RegisterNativeFunction(NATIVE_CREATURE_INTERACTING_WITH,            "CREATURE_INTERACTING_WITH",            N_CREATURE_INTERACTING_WITH);
    vm->RegisterNativeFunction(NATIVE_CREATURE_SPELL_REVERSION,             "CREATURE_SPELL_REVERSION",             N_CREATURE_SPELL_REVERSION);
    vm->RegisterNativeFunction(NATIVE_SWAP_CREATURE,                        "SWAP_CREATURE",                        N_SWAP_CREATURE);
    vm->RegisterNativeFunction(NATIVE_CREATURE_CREATE_RELATIVE_TO_CREATURE, "CREATURE_CREATE_RELATIVE_TO_CREATURE", N_CREATURE_CREATE_RELATIVE);
    vm->RegisterNativeFunction(NATIVE_SET_CREATURE_QUEUE_FIGHT_MOVE,        "SET_CREATURE_QUEUE_FIGHT_MOVE",        N_SET_CREATURE_QUEUE_FIGHT_MOVE);
    vm->RegisterNativeFunction(NATIVE_SET_CREATURE_QUEUE_FIGHT_SPELL,       "SET_CREATURE_QUEUE_FIGHT_SPELL",       N_SET_CREATURE_QUEUE_FIGHT_SPELL);
    vm->RegisterNativeFunction(NATIVE_SET_CREATURE_QUEUE_FIGHT_STEP,        "SET_CREATURE_QUEUE_FIGHT_STEP",        N_SET_CREATURE_QUEUE_FIGHT_STEP);
    vm->RegisterNativeFunction(NATIVE_GET_CREATURE_FIGHT_ACTION,            "GET_CREATURE_FIGHT_ACTION",            N_GET_CREATURE_FIGHT_ACTION);
    vm->RegisterNativeFunction(NATIVE_CREATURE_FIGHT_QUEUE_HITS,            "CREATURE_FIGHT_QUEUE_HITS",            N_CREATURE_FIGHT_QUEUE_HITS);
    vm->RegisterNativeFunction(NATIVE_IN_CREATURE_HAND,                     "IN_CREATURE_HAND",                     N_IN_CREATURE_HAND);
    vm->RegisterNativeFunction(NATIVE_SET_LEASH_WORKS,                      "SET_LEASH_WORKS",                      N_SET_LEASH_WORKS);
    vm->RegisterNativeFunction(NATIVE_ATTACH_OBJECT_LEASH_TO_OBJECT,        "ATTACH_OBJECT_LEASH_TO_OBJECT",        N_ATTACH_OBJECT_LEASH_TO_OBJECT);
    vm->RegisterNativeFunction(NATIVE_ATTACH_OBJECT_LEASH_TO_HAND,          "ATTACH_OBJECT_LEASH_TO_HAND",          N_ATTACH_OBJECT_LEASH_TO_HAND);
    vm->RegisterNativeFunction(NATIVE_DETACH_OBJECT_LEASH,                  "DETACH_OBJECT_LEASH",                  N_DETACH_OBJECT_LEASH);
    vm->RegisterNativeFunction(NATIVE_SET_PLAYER_BELIEF,                    "SET_PLAYER_BELIEF",                    N_SET_PLAYER_BELIEF);
    vm->RegisterNativeFunction(NATIVE_SET_TOWN_DESIRE_BOOST,                "SET_TOWN_DESIRE_BOOST",                N_SET_TOWN_DESIRE_BOOST);
    vm->RegisterNativeFunction(NATIVE_CLEAR_ACTOR_MIND,                     "CLEAR_ACTOR_MIND",                     N_CLEAR_ACTOR_MIND);
    vm->RegisterNativeFunction(NATIVE_CAN_SKIP_CREATURE_TRAINING,           "CAN_SKIP_CREATURE_TRAINING",           N_CAN_SKIP_CREATURE_TRAINING);
    vm->RegisterNativeFunction(NATIVE_IS_KEEPING_OLD_CREATURE,              "IS_KEEPING_OLD_CREATURE",              N_IS_KEEPING_OLD_CREATURE);
    vm->RegisterNativeFunction(NATIVE_CURRENT_PROFILE_HAS_CREATURE,         "CURRENT_PROFILE_HAS_CREATURE",         N_CURRENT_PROFILE_HAS_CREATURE);
    vm->RegisterNativeFunction(NATIVE_GET_TARGET_OBJECT,                    "GET_TARGET_OBJECT",                    N_GET_TARGET_OBJECT);

    // --- Chunk 4: spells / magic / weather (50) ---
    vm->RegisterNativeFunction(NATIVE_SPELL_AT_THING,                       "SPELL_AT_THING",                       N_SPELL_AT_THING);
    vm->RegisterNativeFunction(NATIVE_SPELL_AT_POS,                         "SPELL_AT_POS",                         N_SPELL_AT_POS);
    vm->RegisterNativeFunction(NATIVE_SPELL_AT_POINT,                       "SPELL_AT_POINT",                       N_SPELL_AT_POINT);
    vm->RegisterNativeFunction(NATIVE_SET_MAGIC_RADIUS,                     "SET_MAGIC_RADIUS",                     N_SET_MAGIC_RADIUS);
    vm->RegisterNativeFunction(NATIVE_SET_PLAYER_MAGIC,                     "SET_PLAYER_MAGIC",                     N_SET_PLAYER_MAGIC);
    vm->RegisterNativeFunction(NATIVE_HAS_PLAYER_MAGIC,                     "HAS_PLAYER_MAGIC",                     N_HAS_PLAYER_MAGIC);
    vm->RegisterNativeFunction(NATIVE_CLEAR_PLAYER_SPELL_CHARGING,          "CLEAR_PLAYER_SPELL_CHARGING",          N_CLEAR_PLAYER_SPELL_CHARGING);
    vm->RegisterNativeFunction(NATIVE_VORTEX_PARAMETERS,                    "VORTEX_PARAMETERS",                    N_VORTEX_PARAMETERS);
    vm->RegisterNativeFunction(NATIVE_VORTEX_FADE_OUT,                      "VORTEX_FADE_OUT",                      N_VORTEX_FADE_OUT);
    vm->RegisterNativeFunction(NATIVE_CHANGE_WEATHER_PROPERTIES,            "CHANGE_WEATHER_PROPERTIES",            N_CHANGE_WEATHER_PROPERTIES);
    vm->RegisterNativeFunction(NATIVE_CHANGE_CLOUD_PROPERTIES,              "CHANGE_CLOUD_PROPERTIES",              N_CHANGE_CLOUD_PROPERTIES);
    vm->RegisterNativeFunction(NATIVE_SET_AFFECTED_BY_WIND,                 "SET_AFFECTED_BY_WIND",                 N_SET_AFFECTED_BY_WIND);
    vm->RegisterNativeFunction(NATIVE_IS_WIND_MAGIC_AT_POS,                 "IS_WIND_MAGIC_AT_POS",                 N_IS_WIND_MAGIC_AT_POS);
    vm->RegisterNativeFunction(NATIVE_PAUSE_UNPAUSE_CLIMATE_SYSTEM,         "PAUSE_UNPAUSE_CLIMATE_SYSTEM",         N_PAUSE_UNPAUSE_CLIMATE_SYSTEM);
    vm->RegisterNativeFunction(NATIVE_PAUSE_UNPAUSE_STORM_CREATION_IN_CLIMATE_SYSTEM, "PAUSE_UNPAUSE_STORM_CREATION_IN_CLIMATE_SYSTEM", N_PAUSE_UNPAUSE_STORM_CREATION_IN_CLIMATE_SYSTEM);
    vm->RegisterNativeFunction(NATIVE_KILL_STORMS_IN_AREA,                  "KILL_STORMS_IN_AREA",                  N_KILL_STORMS_IN_AREA);
    vm->RegisterNativeFunction(NATIVE_SET_PLAYER_WIND_RESISTANCE,           "SET_PLAYER_WIND_RESISTANCE",           N_SET_PLAYER_WIND_RESISTANCE);
    vm->RegisterNativeFunction(NATIVE_GET_PLAYER_WIND_RESISTANCE,           "GET_PLAYER_WIND_RESISTANCE",           N_GET_PLAYER_WIND_RESISTANCE);
    vm->RegisterNativeFunction(NATIVE_SPIRIT_EJECT,                         "SPIRIT_EJECT",                         N_SPIRIT_EJECT);
    vm->RegisterNativeFunction(NATIVE_SPIRIT_HOME,                          "SPIRIT_HOME",                          N_SPIRIT_HOME);
    vm->RegisterNativeFunction(NATIVE_SPIRIT_POINT_POS,                     "SPIRIT_POINT_POS",                     N_SPIRIT_POINT_POS);
    vm->RegisterNativeFunction(NATIVE_SPIRIT_POINT_GAME_THING,              "SPIRIT_POINT_GAME_THING",              N_SPIRIT_POINT_GAME_THING);
    vm->RegisterNativeFunction(NATIVE_PLAY_SPIRIT_ANIM,                     "PLAY_SPIRIT_ANIM",                     N_PLAY_SPIRIT_ANIM);
    vm->RegisterNativeFunction(NATIVE_SPIRIT_PLAYED,                        "SPIRIT_PLAYED",                        N_SPIRIT_PLAYED);
    vm->RegisterNativeFunction(NATIVE_SPIRIT_SPEAKS,                        "SPIRIT_SPEAKS",                        N_SPIRIT_SPEAKS);
    vm->RegisterNativeFunction(NATIVE_SPIRIT_APPEAR,                        "SPIRIT_APPEAR",                        N_SPIRIT_APPEAR);
    vm->RegisterNativeFunction(NATIVE_SPIRIT_DISAPPEAR,                     "SPIRIT_DISAPPEAR",                     N_SPIRIT_DISAPPEAR);
    vm->RegisterNativeFunction(NATIVE_SPIRIT_SCREEN_POINT,                  "SPIRIT_SCREEN_POINT",                  N_SPIRIT_SCREEN_POINT);
    vm->RegisterNativeFunction(NATIVE_GAME_THING_HIT,                       "GAME_THING_HIT",                       N_GAME_THING_HIT);
    vm->RegisterNativeFunction(NATIVE_BUILD_BUILDING,                       "BUILD_BUILDING",                       N_BUILD_BUILDING);
    vm->RegisterNativeFunction(NATIVE_LOOK_GAME_THING,                      "LOOK_GAME_THING",                      N_LOOK_GAME_THING);
    vm->RegisterNativeFunction(NATIVE_OBJECT_INFO_BITS,                     "OBJECT_INFO_BITS",                     N_OBJECT_INFO_BITS);
    vm->RegisterNativeFunction(NATIVE_CONVERT_CAMERA_POSITION,              "CONVERT_CAMERA_POSITION",              N_CONVERT_CAMERA_POSITION);
    vm->RegisterNativeFunction(NATIVE_CONVERT_CAMERA_FOCUS,                 "CONVERT_CAMERA_FOCUS",                 N_CONVERT_CAMERA_FOCUS);
    vm->RegisterNativeFunction(NATIVE_SET_GRAPHICS_CLIPPING,                "SET_GRAPHICS_CLIPPING",                N_SET_GRAPHICS_CLIPPING);
    vm->RegisterNativeFunction(NATIVE_SET_CLIPPING_WINDOW,                  "SET_CLIPPING_WINDOW",                  N_SET_CLIPPING_WINDOW);
    vm->RegisterNativeFunction(NATIVE_CLEAR_CLIPPING_WINDOW,                "CLEAR_CLIPPING_WINDOW",                N_CLEAR_CLIPPING_WINDOW);
    vm->RegisterNativeFunction(NATIVE_SET_DRAW_TEXT_COLOUR,                 "SET_DRAW_TEXT_COLOUR",                 N_SET_DRAW_TEXT_COLOUR);
    vm->RegisterNativeFunction(NATIVE_ENABLE_DISABLE_ALIGNMENT_MUSIC,       "ENABLE_DISABLE_ALIGNMENT_MUSIC",       N_ENABLE_DISABLE_ALIGNMENT_MUSIC);
    vm->RegisterNativeFunction(NATIVE_SET_INTERFACE_INTERACTION,            "SET_INTERFACE_INTERACTION",            N_SET_INTERFACE_INTERACTION);
    vm->RegisterNativeFunction(NATIVE_SET_INTERFACE_CITADEL,                "SET_INTERFACE_CITADEL",                N_SET_INTERFACE_CITADEL);
    vm->RegisterNativeFunction(NATIVE_SET_LAND_BALANCE,                     "SET_LAND_BALANCE",                     N_SET_LAND_BALANCE);
    vm->RegisterNativeFunction(NATIVE_CREATE_HIGHLIGHT,                     "CREATE_HIGHLIGHT",                     N_CREATE_HIGHLIGHT);
    vm->RegisterNativeFunction(NATIVE_ID_POISONED_SIZE,                     "ID_POISONED_SIZE",                     N_ID_POISONED_SIZE);
    vm->RegisterNativeFunction(NATIVE_CALL_POISONED_IN,                     "CALL_POISONED_IN",                     N_CALL_POISONED_IN);
    vm->RegisterNativeFunction(NATIVE_CALL_NOT_POISONED_IN,                 "CALL_NOT_POISONED_IN",                 N_CALL_NOT_POISONED_IN);
    vm->RegisterNativeFunction(NATIVE_SAY_SOUND_EFFECT_PLAYING,             "SAY_SOUND_EFFECT_PLAYING",             N_SAY_SOUND_EFFECT_PLAYING);
    vm->RegisterNativeFunction(NATIVE_ENABLE_DISABLE_MUSIC,                 "ENABLE_DISABLE_MUSIC",                 N_ENABLE_DISABLE_MUSIC);
    vm->RegisterNativeFunction(NATIVE_IS_AFFECTED_BY_SPELL,                 "IS_AFFECTED_BY_SPELL",                 N_IS_AFFECTED_BY_SPELL_REAL);

    // --- Chunk 5: audio / dialogue / UI / time (50) ---
    vm->RegisterNativeFunction(NATIVE_PLAY_SOUND_EFFECT,                    "PLAY_SOUND_EFFECT",                    N_PLAY_SOUND_EFFECT);
    vm->RegisterNativeFunction(NATIVE_STOP_SOUND_EFFECT,                    "STOP_SOUND_EFFECT",                    N_STOP_SOUND_EFFECT);
    vm->RegisterNativeFunction(NATIVE_SOUND_EXISTS,                         "SOUND_EXISTS",                         N_SOUND_EXISTS);
    vm->RegisterNativeFunction(NATIVE_GAME_SOUND_PLAYING,                   "GAME_SOUND_PLAYING",                   N_GAME_SOUND_PLAYING);
    vm->RegisterNativeFunction(NATIVE_GAME_PLAY_SAY_SOUND_EFFECT,           "GAME_PLAY_SAY_SOUND_EFFECT",           N_GAME_PLAY_SAY_SOUND_EFFECT);
    vm->RegisterNativeFunction(NATIVE_ATTACH_SOUND_TAG,                     "ATTACH_SOUND_TAG",                     N_ATTACH_SOUND_TAG);
    vm->RegisterNativeFunction(NATIVE_DETACH_SOUND_TAG,                     "DETACH_SOUND_TAG",                     N_DETACH_SOUND_TAG);
    vm->RegisterNativeFunction(NATIVE_GAME_SET_MANA,                        "GAME_SET_MANA",                        N_GAME_SET_MANA);
    vm->RegisterNativeFunction(NATIVE_START_MUSIC,                          "START_MUSIC",                          N_START_MUSIC);
    vm->RegisterNativeFunction(NATIVE_STOP_MUSIC,                           "STOP_MUSIC",                           N_STOP_MUSIC);
    vm->RegisterNativeFunction(NATIVE_ATTACH_MUSIC,                         "ATTACH_MUSIC",                         N_ATTACH_MUSIC);
    vm->RegisterNativeFunction(NATIVE_DETACH_MUSIC,                         "DETACH_MUSIC",                         N_DETACH_MUSIC);
    vm->RegisterNativeFunction(NATIVE_LAST_MUSIC_LINE,                      "LAST_MUSIC_LINE",                      N_LAST_MUSIC_LINE);
    vm->RegisterNativeFunction(NATIVE_RUN_TEXT,                             "RUN_TEXT",                             N_RUN_TEXT);
    vm->RegisterNativeFunction(NATIVE_TEMP_TEXT,                            "TEMP_TEXT",                            N_TEMP_TEXT);
    vm->RegisterNativeFunction(NATIVE_TEXT_READ,                            "TEXT_READ",                            N_TEXT_READ);
    vm->RegisterNativeFunction(NATIVE_RUN_TEXT_WITH_NUMBER,                 "RUN_TEXT_WITH_NUMBER",                 N_RUN_TEXT_WITH_NUMBER);
    vm->RegisterNativeFunction(NATIVE_TEMP_TEXT_WITH_NUMBER,                "TEMP_TEXT_WITH_NUMBER",                N_TEMP_TEXT_WITH_NUMBER);
    vm->RegisterNativeFunction(NATIVE_START_DIALOGUE,                       "START_DIALOGUE",                       N_START_DIALOGUE);
    vm->RegisterNativeFunction(NATIVE_END_DIALOGUE,                         "END_DIALOGUE",                         N_END_DIALOGUE);
    vm->RegisterNativeFunction(NATIVE_IS_DIALOGUE_READY,                    "IS_DIALOGUE_READY",                    N_IS_DIALOGUE_READY);
    vm->RegisterNativeFunction(NATIVE_GAME_CLEAR_DIALOGUE,                  "GAME_CLEAR_DIALOGUE",                  N_GAME_CLEAR_DIALOGUE);
    vm->RegisterNativeFunction(NATIVE_GAME_CLOSE_DIALOGUE,                  "GAME_CLOSE_DIALOGUE",                  N_GAME_CLOSE_DIALOGUE);
    vm->RegisterNativeFunction(NATIVE_GAME_DRAW_TEXT,                       "GAME_DRAW_TEXT",                       N_GAME_DRAW_TEXT);
    vm->RegisterNativeFunction(NATIVE_GAME_DRAW_TEMP_TEXT,                  "GAME_DRAW_TEMP_TEXT",                  N_GAME_DRAW_TEMP_TEXT);
    vm->RegisterNativeFunction(NATIVE_FADE_ALL_DRAW_TEXT,                   "FADE_ALL_DRAW_TEXT",                   N_FADE_ALL_DRAW_TEXT);
    vm->RegisterNativeFunction(NATIVE_SET_WIDESCREEN,                       "SET_WIDESCREEN",                       N_SET_WIDESCREEN);
    vm->RegisterNativeFunction(NATIVE_WIDESCREEN_TRANSISTION_FINISHED,      "WIDESCREEN_TRANSISTION_FINISHED",      N_WIDESCREEN_TRANSISTION_FINISHED);
    vm->RegisterNativeFunction(NATIVE_SET_FADE,                             "SET_FADE",                             N_SET_FADE);
    vm->RegisterNativeFunction(NATIVE_SET_FADE_IN,                          "SET_FADE_IN",                          N_SET_FADE_IN);
    vm->RegisterNativeFunction(NATIVE_FADE_FINISHED,                        "FADE_FINISHED",                        N_FADE_FINISHED);
    vm->RegisterNativeFunction(NATIVE_SET_GAMESPEED,                        "SET_GAMESPEED",                        N_SET_GAMESPEED);
    vm->RegisterNativeFunction(NATIVE_SET_GAME_TIME,                        "SET_GAME_TIME",                        N_SET_GAME_TIME);
    vm->RegisterNativeFunction(NATIVE_GET_REAL_TIME,                        "GET_REAL_TIME",                        N_GET_REAL_TIME);
    vm->RegisterNativeFunction(NATIVE_SET_GAME_TIME_PROPERTIES,             "SET_GAME_TIME_PROPERTIES",             N_SET_GAME_TIME_PROPERTIES);
    vm->RegisterNativeFunction(NATIVE_KEY_DOWN,                             "KEY_DOWN",                             N_KEY_DOWN);
    vm->RegisterNativeFunction(NATIVE_HELP_SYSTEM_ON,                       "HELP_SYSTEM_ON",                       N_HELP_SYSTEM_ON);
    vm->RegisterNativeFunction(NATIVE_SET_HELP_SYSTEM,                      "SET_HELP_SYSTEM",                      N_SET_HELP_SYSTEM);
    vm->RegisterNativeFunction(NATIVE_PLAY_HAND_DEMO,                       "PLAY_HAND_DEMO",                       N_PLAY_HAND_DEMO);
    vm->RegisterNativeFunction(NATIVE_HAND_DEMO_TRIGGER,                    "HAND_DEMO_TRIGGER",                    N_HAND_DEMO_TRIGGER);
    vm->RegisterNativeFunction(NATIVE_SET_HAND_DEMO_KEYS,                   "SET_HAND_DEMO_KEYS",                   N_SET_HAND_DEMO_KEYS);
    vm->RegisterNativeFunction(NATIVE_SET_BOOKMARK_POSITION,                "SET_BOOKMARK_POSITION",                N_SET_BOOKMARK_POSITION);
    vm->RegisterNativeFunction(NATIVE_GET_INTERACTION_MAGNITUDE,            "GET_INTERACTION_MAGNITUDE",            N_GET_INTERACTION_MAGNITUDE);
    vm->RegisterNativeFunction(NATIVE_LOAD_MAP,                             "LOAD_MAP",                             N_LOAD_MAP);
    vm->RegisterNativeFunction(NATIVE_START_CAMERA_CONTROL,                 "START_CAMERA_CONTROL",                 N_START_CAMERA_CONTROL);
    vm->RegisterNativeFunction(NATIVE_END_CAMERA_CONTROL,                   "END_CAMERA_CONTROL",                   N_END_CAMERA_CONTROL);

    // --- Chunk 6: camera, cinematic, follow, computer player (50) ---
    vm->RegisterNativeFunction(NATIVE_HAS_CAMERA_ARRIVED,                   "HAS_CAMERA_ARRIVED",                   N_HAS_CAMERA_ARRIVED);
    vm->RegisterNativeFunction(NATIVE_FOCUS_FOLLOW,                         "FOCUS_FOLLOW",                         N_FOCUS_FOLLOW);
    vm->RegisterNativeFunction(NATIVE_POSITION_FOLLOW,                      "POSITION_FOLLOW",                      N_POSITION_FOLLOW);
    vm->RegisterNativeFunction(NATIVE_SET_FOCUS_FOLLOW,                     "SET_FOCUS_FOLLOW",                     N_SET_FOCUS_FOLLOW);
    vm->RegisterNativeFunction(NATIVE_SET_POSITION_FOLLOW,                  "SET_POSITION_FOLLOW",                  N_SET_POSITION_FOLLOW);
    vm->RegisterNativeFunction(NATIVE_SET_FOCUS_AND_POSITION_FOLLOW,        "SET_FOCUS_AND_POSITION_FOLLOW",        N_SET_FOCUS_AND_POSITION_FOLLOW);
    vm->RegisterNativeFunction(NATIVE_FOCUS_AND_POSITION_FOLLOW,            "FOCUS_AND_POSITION_FOLLOW",            N_FOCUS_AND_POSITION_FOLLOW);
    vm->RegisterNativeFunction(NATIVE_CAMERA_PROPERTIES,                    "CAMERA_PROPERTIES",                    N_CAMERA_PROPERTIES);
    vm->RegisterNativeFunction(NATIVE_SHAKE_CAMERA,                         "SHAKE_CAMERA",                         N_SHAKE_CAMERA);
    vm->RegisterNativeFunction(NATIVE_SET_CAMERA_ZONE,                      "SET_CAMERA_ZONE",                      N_SET_CAMERA_ZONE);
    vm->RegisterNativeFunction(NATIVE_RUN_CAMERA_PATH,                      "RUN_CAMERA_PATH",                      N_RUN_CAMERA_PATH);
    vm->RegisterNativeFunction(NATIVE_SET_CAMERA_LENS,                      "SET_CAMERA_LENS",                      N_SET_CAMERA_LENS);
    vm->RegisterNativeFunction(NATIVE_MOVE_CAMERA_LENS,                     "MOVE_CAMERA_LENS",                     N_MOVE_CAMERA_LENS);
    vm->RegisterNativeFunction(NATIVE_STORE_CAMERA_DETAILS,                 "STORE_CAMERA_DETAILS",                 N_STORE_CAMERA_DETAILS);
    vm->RegisterNativeFunction(NATIVE_RESTORE_CAMERA_DETAILS,               "RESTORE_CAMERA_DETAILS",               N_RESTORE_CAMERA_DETAILS);
    vm->RegisterNativeFunction(NATIVE_SET_CAMERA_POS_FOC_LENS,              "SET_CAMERA_POS_FOC_LENS",              N_SET_CAMERA_POS_FOC_LENS);
    vm->RegisterNativeFunction(NATIVE_MOVE_CAMERA_POS_FOC_LENS,             "MOVE_CAMERA_POS_FOC_LENS",             N_MOVE_CAMERA_POS_FOC_LENS);
    vm->RegisterNativeFunction(NATIVE_GET_STORED_CAMERA_POSITION,           "GET_STORED_CAMERA_POSITION",           N_GET_STORED_CAMERA_POSITION);
    vm->RegisterNativeFunction(NATIVE_GET_STORED_CAMERA_FOCUS,              "GET_STORED_CAMERA_FOCUS",              N_GET_STORED_CAMERA_FOCUS);
    vm->RegisterNativeFunction(NATIVE_SET_CAMERA_TO_FACE_OBJECT,            "SET_CAMERA_TO_FACE_OBJECT",            N_SET_CAMERA_TO_FACE_OBJECT);
    vm->RegisterNativeFunction(NATIVE_MOVE_CAMERA_TO_FACE_OBJECT,           "MOVE_CAMERA_TO_FACE_OBJECT",           N_MOVE_CAMERA_TO_FACE_OBJECT);
    vm->RegisterNativeFunction(NATIVE_START_DUAL_CAMERA,                    "START_DUAL_CAMERA",                    N_START_DUAL_CAMERA);
    vm->RegisterNativeFunction(NATIVE_UPDATE_DUAL_CAMERA,                   "UPDATE_DUAL_CAMERA",                   N_UPDATE_DUAL_CAMERA);
    vm->RegisterNativeFunction(NATIVE_RELEASE_DUAL_CAMERA,                  "RELEASE_DUAL_CAMERA",                  N_RELEASE_DUAL_CAMERA);
    vm->RegisterNativeFunction(NATIVE_CREATE_DUAL_CAMERA_WITH_POINT,        "CREATE_DUAL_CAMERA_WITH_POINT",        N_CREATE_DUAL_CAMERA_WITH_POINT);
    vm->RegisterNativeFunction(NATIVE_SET_FOCUS_FOLLOW_COMPUTER_PLAYER,     "SET_FOCUS_FOLLOW_COMPUTER_PLAYER",     N_SET_FOCUS_FOLLOW_COMPUTER_PLAYER);
    vm->RegisterNativeFunction(NATIVE_SET_POSITION_FOLLOW_COMPUTER_PLAYER,  "SET_POSITION_FOLLOW_COMPUTER_PLAYER",  N_SET_POSITION_FOLLOW_COMPUTER_PLAYER);
    vm->RegisterNativeFunction(NATIVE_GAME_THING_CAN_VIEW_CAMERA,           "GAME_THING_CAN_VIEW_CAMERA",           N_GAME_THING_CAN_VIEW_CAMERA);
    vm->RegisterNativeFunction(NATIVE_GAME_TYPE,                            "GAME_TYPE",                            N_GAME_TYPE);
    vm->RegisterNativeFunction(NATIVE_COMPUTER_PLAYER_READY,                "COMPUTER_PLAYER_READY",                N_COMPUTER_PLAYER_READY);
    vm->RegisterNativeFunction(NATIVE_ENABLE_DISABLE_COMPUTER_PLAYER_311,   "ENABLE_DISABLE_COMPUTER_PLAYER_311",   N_ENABLE_DISABLE_COMPUTER_PLAYER_311);
    vm->RegisterNativeFunction(NATIVE_ENABLE_DISABLE_COMPUTER_PLAYER_345,   "ENABLE_DISABLE_COMPUTER_PLAYER_345",   N_ENABLE_DISABLE_COMPUTER_PLAYER_345);
    vm->RegisterNativeFunction(NATIVE_SET_COMPUTER_PLAYER_PERSONALITY,      "SET_COMPUTER_PLAYER_PERSONALITY",      N_SET_COMPUTER_PLAYER_PERSONALITY);
    vm->RegisterNativeFunction(NATIVE_SET_COMPUTER_PLAYER_SUPPRESSION,      "SET_COMPUTER_PLAYER_SUPPRESSION",      N_SET_COMPUTER_PLAYER_SUPPRESSION);
    vm->RegisterNativeFunction(NATIVE_SET_COMPUTER_PLAYER_SPEED,            "SET_COMPUTER_PLAYER_SPEED",            N_SET_COMPUTER_PLAYER_SPEED);
    vm->RegisterNativeFunction(NATIVE_SET_COMPUTER_PLAYER_ATTITUDE,         "SET_COMPUTER_PLAYER_ATTITUDE",         N_SET_COMPUTER_PLAYER_ATTITUDE);
    vm->RegisterNativeFunction(NATIVE_GET_COMPUTER_PLAYER_ATTITUDE,         "GET_COMPUTER_PLAYER_ATTITUDE",         N_GET_COMPUTER_PLAYER_ATTITUDE);
    vm->RegisterNativeFunction(NATIVE_FORCE_COMPUTER_PLAYER_ACTION,         "FORCE_COMPUTER_PLAYER_ACTION",         N_FORCE_COMPUTER_PLAYER_ACTION);
    vm->RegisterNativeFunction(NATIVE_QUEUE_COMPUTER_PLAYER_ACTION,         "QUEUE_COMPUTER_PLAYER_ACTION",         N_QUEUE_COMPUTER_PLAYER_ACTION);
    vm->RegisterNativeFunction(NATIVE_GAME_CLEAR_COMPUTER_PLAYER_ACTIONS,   "GAME_CLEAR_COMPUTER_PLAYER_ACTIONS",   N_GAME_CLEAR_COMPUTER_PLAYER_ACTIONS);
    vm->RegisterNativeFunction(NATIVE_RELEASE_COMPUTER_PLAYER,              "RELEASE_COMPUTER_PLAYER",              N_RELEASE_COMPUTER_PLAYER);
    vm->RegisterNativeFunction(NATIVE_LOAD_COMPUTER_PLAYER_PERSONALITY,     "LOAD_COMPUTER_PLAYER_PERSONALITY",     N_LOAD_COMPUTER_PLAYER_PERSONALITY);
    vm->RegisterNativeFunction(NATIVE_SAVE_COMPUTER_PLAYER_PERSONALITY,     "SAVE_COMPUTER_PLAYER_PERSONALITY",     N_SAVE_COMPUTER_PLAYER_PERSONALITY);
    vm->RegisterNativeFunction(NATIVE_SET_PLAYER_ALLY,                      "SET_PLAYER_ALLY",                      N_SET_PLAYER_ALLY);
    vm->RegisterNativeFunction(NATIVE_GET_PLAYER_ALLY,                      "GET_PLAYER_ALLY",                      N_GET_PLAYER_ALLY);
    vm->RegisterNativeFunction(NATIVE_PLAYED_PERCENTAGE,                    "PLAYED_PERCENTAGE",                    N_PLAYED_PERCENTAGE);
    vm->RegisterNativeFunction(NATIVE_GET_OBJECT_DROPPED,                   "GET_OBJECT_DROPPED",                   N_GET_OBJECT_DROPPED);
    vm->RegisterNativeFunction(NATIVE_REMOVE_REACTION,                      "REMOVE_REACTION",                      N_REMOVE_REACTION);
    vm->RegisterNativeFunction(NATIVE_REMOVE_REACTION_OF_TYPE,              "REMOVE_REACTION_OF_TYPE",              N_REMOVE_REACTION_OF_TYPE);

    // --- Chunk 7: town/player/influence, timers, animation, music (50) ---
    vm->RegisterNativeFunction(NATIVE_INFLUENCE_OBJECT,                     "INFLUENCE_OBJECT",                     N_INFLUENCE_OBJECT);
    vm->RegisterNativeFunction(NATIVE_INFLUENCE_POSITION,                   "INFLUENCE_POSITION",                   N_INFLUENCE_POSITION);
    vm->RegisterNativeFunction(NATIVE_GET_INFLUENCE,                        "GET_INFLUENCE",                        N_GET_INFLUENCE_REAL);
    vm->RegisterNativeFunction(NATIVE_SPECIAL_EFFECT_POSITION,              "SPECIAL_EFFECT_POSITION",              N_SPECIAL_EFFECT_POSITION);
    vm->RegisterNativeFunction(NATIVE_SPECIAL_EFFECT_OBJECT,                "SPECIAL_EFFECT_OBJECT",                N_SPECIAL_EFFECT_OBJECT);
    vm->RegisterNativeFunction(NATIVE_OVERRIDE_STATE_ANIMATION,             "OVERRIDE_STATE_ANIMATION",             N_OVERRIDE_STATE_ANIMATION);
    vm->RegisterNativeFunction(NATIVE_PLAYED,                               "PLAYED",                               N_PLAYED);
    vm->RegisterNativeFunction(NATIVE_CLEAR_DROPPED_BY_OBJECT,              "CLEAR_DROPPED_BY_OBJECT",              N_CLEAR_DROPPED_BY_OBJECT);
    vm->RegisterNativeFunction(NATIVE_CREATE_REACTION,                      "CREATE_REACTION",                      N_CREATE_REACTION);
    vm->RegisterNativeFunction(NATIVE_POPULATE_CONTAINER,                   "POPULATE_CONTAINER",                   N_POPULATE_CONTAINER);
    vm->RegisterNativeFunction(NATIVE_ADD_REFERENCE,                        "ADD_REFERENCE",                        N_ADD_REFERENCE);
    vm->RegisterNativeFunction(NATIVE_REMOVE_REFERENCE,                     "REMOVE_REFERENCE",                     N_REMOVE_REFERENCE);
    vm->RegisterNativeFunction(NATIVE_GET_REAL_DAY_115,                     "GET_REAL_DAY_115",                     N_GET_REAL_DAY_115);
    vm->RegisterNativeFunction(NATIVE_GET_REAL_DAY_116,                     "GET_REAL_DAY_116",                     N_GET_REAL_DAY_116);
    vm->RegisterNativeFunction(NATIVE_GET_REAL_MONTH,                       "GET_REAL_MONTH",                       N_GET_REAL_MONTH);
    vm->RegisterNativeFunction(NATIVE_GET_REAL_YEAR,                        "GET_REAL_YEAR",                        N_GET_REAL_YEAR);
    vm->RegisterNativeFunction(NATIVE_GET_MOON_PERCENTAGE,                  "GET_MOON_PERCENTAGE",                  N_GET_MOON_PERCENTAGE);
    vm->RegisterNativeFunction(NATIVE_CHANGE_LIGHTNING_PROPERTIES,          "CHANGE_LIGHTNING_PROPERTIES",          N_CHANGE_LIGHTNING_PROPERTIES);
    vm->RegisterNativeFunction(NATIVE_CHANGE_TIME_FADE_PROPERTIES,          "CHANGE_TIME_FADE_PROPERTIES",          N_CHANGE_TIME_FADE_PROPERTIES);
    vm->RegisterNativeFunction(NATIVE_GET_TARGET_RELATIVE_POS,              "GET_TARGET_RELATIVE_POS",              N_GET_TARGET_RELATIVE_POS);
    vm->RegisterNativeFunction(NATIVE_STOP_POINTING,                        "STOP_POINTING",                        N_STOP_POINTING);
    vm->RegisterNativeFunction(NATIVE_STOP_LOOKING,                         "STOP_LOOKING",                         N_STOP_LOOKING);
    vm->RegisterNativeFunction(NATIVE_LOOK_AT_POSITION,                     "LOOK_AT_POSITION",                     N_LOOK_AT_POSITION);
    vm->RegisterNativeFunction(NATIVE_CLING_SPIRIT,                         "CLING_SPIRIT",                         N_CLING_SPIRIT);
    vm->RegisterNativeFunction(NATIVE_FLY_SPIRIT,                           "FLY_SPIRIT",                           N_FLY_SPIRIT);
    vm->RegisterNativeFunction(NATIVE_WALK_PATH,                            "WALK_PATH",                            N_WALK_PATH);
    vm->RegisterNativeFunction(NATIVE_GET_WALK_PATH_PERCENTAGE,             "GET_WALK_PATH_PERCENTAGE",             N_GET_WALK_PATH_PERCENTAGE);
    vm->RegisterNativeFunction(NATIVE_RESTART_MUSIC,                        "RESTART_MUSIC",                        N_RESTART_MUSIC);
    vm->RegisterNativeFunction(NATIVE_MUSIC_PLAYED_191,                     "MUSIC_PLAYED_191",                     N_MUSIC_PLAYED_191);
    vm->RegisterNativeFunction(NATIVE_GET_MUSIC_OBJ_DISTANCE,               "GET_MUSIC_OBJ_DISTANCE",               N_GET_MUSIC_OBJ_DISTANCE);
    vm->RegisterNativeFunction(NATIVE_GET_MUSIC_ENUM_DISTANCE,              "GET_MUSIC_ENUM_DISTANCE",              N_GET_MUSIC_ENUM_DISTANCE);
    vm->RegisterNativeFunction(NATIVE_SET_MUSIC_PLAY_POSITION,              "SET_MUSIC_PLAY_POSITION",              N_SET_MUSIC_PLAY_POSITION);
    vm->RegisterNativeFunction(NATIVE_MOVE_MUSIC,                           "MOVE_MUSIC",                           N_MOVE_MUSIC);
    vm->RegisterNativeFunction(NATIVE_CLEAR_HIT_OBJECT,                     "CLEAR_HIT_OBJECT",                     N_CLEAR_HIT_OBJECT);
    vm->RegisterNativeFunction(NATIVE_GET_SLOWEST_SPEED,                    "GET_SLOWEST_SPEED",                    N_GET_SLOWEST_SPEED);
    vm->RegisterNativeFunction(NATIVE_GET_OBJECT_HELD_199,                  "GET_OBJECT_HELD_199",                  N_GET_OBJECT_HELD_199);
    vm->RegisterNativeFunction(NATIVE_SET_ANIMATION_MODIFY,                 "SET_ANIMATION_MODIFY",                 N_SET_ANIMATION_MODIFY);
    vm->RegisterNativeFunction(NATIVE_SET_AVI_SEQUENCE,                     "SET_AVI_SEQUENCE",                     N_SET_AVI_SEQUENCE);
    vm->RegisterNativeFunction(NATIVE_PLAY_GESTURE,                         "PLAY_GESTURE",                         N_PLAY_GESTURE);
    vm->RegisterNativeFunction(NATIVE_DEV_FUNCTION,                         "DEV_FUNCTION",                         N_DEV_FUNCTION);
    vm->RegisterNativeFunction(NATIVE_HAS_MOUSE_WHEEL,                      "HAS_MOUSE_WHEEL",                      N_HAS_MOUSE_WHEEL);
    vm->RegisterNativeFunction(NATIVE_NUM_MOUSE_BUTTONS,                    "NUM_MOUSE_BUTTONS",                    N_NUM_MOUSE_BUTTONS);
    vm->RegisterNativeFunction(NATIVE_CREATE_TIMER,                         "CREATE_TIMER",                         N_CREATE_TIMER);
    vm->RegisterNativeFunction(NATIVE_SET_TIMER_TIME,                       "SET_TIMER_TIME",                       N_SET_TIMER_TIME);
    vm->RegisterNativeFunction(NATIVE_GET_TIMER_TIME_REMAINING,             "GET_TIMER_TIME_REMAINING",             N_GET_TIMER_TIME_REMAINING);
    vm->RegisterNativeFunction(NATIVE_GET_TIMER_TIME_SINCE_SET,             "GET_TIMER_TIME_SINCE_SET",             N_GET_TIMER_TIME_SINCE_SET);
    vm->RegisterNativeFunction(NATIVE_GET_INCLUSION_DISTANCE,               "GET_INCLUSION_DISTANCE",               N_GET_INCLUSION_DISTANCE);
    vm->RegisterNativeFunction(NATIVE_START_GAME_SPEED,                     "START_GAME_SPEED",                     N_START_GAME_SPEED);
    vm->RegisterNativeFunction(NATIVE_END_GAME_SPEED,                       "END_GAME_SPEED",                       N_END_GAME_SPEED);
    vm->RegisterNativeFunction(NATIVE_SET_TEMPERATURE,                      "SET_TEMPERATURE",                      N_SET_TEMPERATURE);
    vm->RegisterNativeFunction(NATIVE_SET_ATTACK_OWN_TOWN,                  "SET_ATTACK_OWN_TOWN",                  N_SET_ATTACK_OWN_TOWN);
    vm->RegisterNativeFunction(NATIVE_CALL_BUILDING_IN_TOWN,                "CALL_BUILDING_IN_TOWN",                N_CALL_BUILDING_IN_TOWN);
    vm->RegisterNativeFunction(NATIVE_CALL_COMPUTER_PLAYER,                 "CALL_COMPUTER_PLAYER",                 N_CALL_COMPUTER_PLAYER);
    vm->RegisterNativeFunction(NATIVE_THING_JC_SPECIAL,                     "THING_JC_SPECIAL",                     N_THING_JC_SPECIAL);
    vm->RegisterNativeFunction(NATIVE_GAME_SUB_TYPE,                        "GAME_SUB_TYPE",                        N_GAME_SUB_TYPE);
    vm->RegisterNativeFunction(NATIVE_STOP_ALL_SCRIPTS_IN_FILES_EXCLUDING,  "STOP_ALL_SCRIPTS_IN_FILES_EXCLUDING",  N_STOP_ALL_SCRIPTS_IN_FILES_EXCLUDING);
    vm->RegisterNativeFunction(NATIVE_STOP_SCRIPTS_IN_FILES,                "STOP_SCRIPTS_IN_FILES",                N_STOP_SCRIPTS_IN_FILES);
    vm->RegisterNativeFunction(NATIVE_SNAPSHOT,                             "SNAPSHOT",                             N_SNAPSHOT);
    vm->RegisterNativeFunction(NATIVE_UPDATE_SNAPSHOT,                      "UPDATE_SNAPSHOT",                      N_UPDATE_SNAPSHOT);
    vm->RegisterNativeFunction(NATIVE_UPDATE_SNAPSHOT_PICTURE,              "UPDATE_SNAPSHOT_PICTURE",              N_UPDATE_SNAPSHOT_PICTURE);
    vm->RegisterNativeFunction(NATIVE_DANCE_CREATE,                         "DANCE_CREATE",                         N_DANCE_CREATE);
    vm->RegisterNativeFunction(NATIVE_CHANGE_INNER_OUTER_PROPERTIES,        "CHANGE_INNER_OUTER_PROPERTIES",        N_CHANGE_INNER_OUTER_PROPERTIES);

    // --- Chunk 8: game state, save, mini-games, immersion (60+) ---
    vm->RegisterNativeFunction(NATIVE_GET_ARENA,                            "GET_ARENA",                            N_GET_ARENA);
    vm->RegisterNativeFunction(NATIVE_GET_FOOTBALL_PITCH,                   "GET_FOOTBALL_PITCH",                   N_GET_FOOTBALL_PITCH);
    vm->RegisterNativeFunction(NATIVE_STOP_ALL_GAMES,                       "STOP_ALL_GAMES",                       N_STOP_ALL_GAMES);
    vm->RegisterNativeFunction(NATIVE_ATTACH_TO_GAME,                       "ATTACH_TO_GAME",                       N_ATTACH_TO_GAME);
    vm->RegisterNativeFunction(NATIVE_DETACH_FROM_GAME,                     "DETACH_FROM_GAME",                     N_DETACH_FROM_GAME);
    vm->RegisterNativeFunction(NATIVE_DETACH_UNDEFINED_FROM_GAME,           "DETACH_UNDEFINED_FROM_GAME",           N_DETACH_UNDEFINED_FROM_GAME);
    vm->RegisterNativeFunction(NATIVE_SET_ONLY_FOR_SCRIPTS,                 "SET_ONLY_FOR_SCRIPTS",                 N_SET_ONLY_FOR_SCRIPTS);
    vm->RegisterNativeFunction(NATIVE_START_MATCH_WITH_REFEREE,             "START_MATCH_WITH_REFEREE",             N_START_MATCH_WITH_REFEREE);
    vm->RegisterNativeFunction(NATIVE_GAME_TEAM_SIZE,                       "GAME_TEAM_SIZE",                       N_GAME_TEAM_SIZE);
    vm->RegisterNativeFunction(NATIVE_GET_HIT_OBJECT,                       "GET_HIT_OBJECT",                       N_GET_HIT_OBJECT);
    vm->RegisterNativeFunction(NATIVE_GET_OBJECT_WHICH_HIT,                 "GET_OBJECT_WHICH_HIT",                 N_GET_OBJECT_WHICH_HIT);
    vm->RegisterNativeFunction(NATIVE_GET_EVENTS_PER_SECOND,                "GET_EVENTS_PER_SECOND",                N_GET_EVENTS_PER_SECOND);
    vm->RegisterNativeFunction(NATIVE_GET_TIME_SINCE,                       "GET_TIME_SINCE",                       N_GET_TIME_SINCE);
    vm->RegisterNativeFunction(NATIVE_GET_TOTAL_EVENTS,                     "GET_TOTAL_EVENTS",                     N_GET_TOTAL_EVENTS);
    vm->RegisterNativeFunction(NATIVE_CREATE_WITH_ANGLE_AND_SCALE,          "CREATE_WITH_ANGLE_AND_SCALE",          N_CREATE_WITH_ANGLE_AND_SCALE);
    vm->RegisterNativeFunction(NATIVE_SET_VIRTUAL_INFLUENCE,                "SET_VIRTUAL_INFLUENCE",                N_SET_VIRTUAL_INFLUENCE);
    vm->RegisterNativeFunction(NATIVE_SET_MIST_FADE,                        "SET_MIST_FADE",                        N_SET_MIST_FADE);
    vm->RegisterNativeFunction(NATIVE_GET_OBJECT_FADE,                      "GET_OBJECT_FADE",                      N_GET_OBJECT_FADE);
    vm->RegisterNativeFunction(NATIVE_SET_OBJECT_FADE_IN,                   "SET_OBJECT_FADE_IN",                   N_SET_OBJECT_FADE_IN);
    vm->RegisterNativeFunction(NATIVE_IS_PLAYING_HAND_DEMO,                 "IS_PLAYING_HAND_DEMO",                 N_IS_PLAYING_HAND_DEMO);
    vm->RegisterNativeFunction(NATIVE_GET_ARSE_POSITION,                    "GET_ARSE_POSITION",                    N_GET_ARSE_POSITION);
    vm->RegisterNativeFunction(NATIVE_GET_BELLY_POSITION,                   "GET_BELLY_POSITION",                   N_GET_BELLY_POSITION);
    vm->RegisterNativeFunction(NATIVE_GET_OBJECT_HELD_273,                  "GET_OBJECT_HELD_273",                  N_GET_OBJECT_HELD_273);
    vm->RegisterNativeFunction(NATIVE_GET_ACTION_COUNT,                     "GET_ACTION_COUNT",                     N_GET_ACTION_COUNT);
    vm->RegisterNativeFunction(NATIVE_GET_OBJECT_LEASH_TYPE,                "GET_OBJECT_LEASH_TYPE",                N_GET_OBJECT_LEASH_TYPE);
    vm->RegisterNativeFunction(NATIVE_START_ANGLE_SOUND_285,                "START_ANGLE_SOUND_285",                N_START_ANGLE_SOUND_285);
    vm->RegisterNativeFunction(NATIVE_START_ANGLE_SOUND_348,                "START_ANGLE_SOUND_348",                N_START_ANGLE_SOUND_348);
    vm->RegisterNativeFunction(NATIVE_GAME_TIME_ON_OFF,                     "GAME_TIME_ON_OFF",                     N_GAME_TIME_ON_OFF);
    vm->RegisterNativeFunction(NATIVE_MOVE_GAME_TIME,                       "MOVE_GAME_TIME",                       N_MOVE_GAME_TIME);
    vm->RegisterNativeFunction(NATIVE_SET_HIGH_GRAPHICS_DETAIL,             "SET_HIGH_GRAPHICS_DETAIL",             N_SET_HIGH_GRAPHICS_DETAIL);
    vm->RegisterNativeFunction(NATIVE_ADD_SPOT_VISUAL_TARGET_POS,           "ADD_SPOT_VISUAL_TARGET_POS",           N_ADD_SPOT_VISUAL_TARGET_POS);
    vm->RegisterNativeFunction(NATIVE_ADD_SPOT_VISUAL_TARGET_OBJECT,        "ADD_SPOT_VISUAL_TARGET_OBJECT",        N_ADD_SPOT_VISUAL_TARGET_OBJECT);
    vm->RegisterNativeFunction(NATIVE_SET_FOCUS_ON_OBJECT,                  "SET_FOCUS_ON_OBJECT",                  N_SET_FOCUS_ON_OBJECT);
    vm->RegisterNativeFunction(NATIVE_RELEASE_OBJECT_FOCUS,                 "RELEASE_OBJECT_FOCUS",                 N_RELEASE_OBJECT_FOCUS);
    vm->RegisterNativeFunction(NATIVE_IMMERSION_EXISTS,                     "IMMERSION_EXISTS",                     N_IMMERSION_EXISTS);
    vm->RegisterNativeFunction(NATIVE_START_IMMERSION,                      "START_IMMERSION",                      N_START_IMMERSION);
    vm->RegisterNativeFunction(NATIVE_STOP_IMMERSION,                       "STOP_IMMERSION",                       N_STOP_IMMERSION);
    vm->RegisterNativeFunction(NATIVE_STOP_ALL_IMMERSION,                   "STOP_ALL_IMMERSION",                   N_STOP_ALL_IMMERSION);
    vm->RegisterNativeFunction(NATIVE_MAP_SCRIPT_FUNCTION,                  "MAP_SCRIPT_FUNCTION",                  N_MAP_SCRIPT_FUNCTION);
    vm->RegisterNativeFunction(NATIVE_SET_DRAW_LEASH,                       "SET_DRAW_LEASH",                       N_SET_DRAW_LEASH);
    vm->RegisterNativeFunction(NATIVE_SET_DRAW_HIGHLIGHT,                   "SET_DRAW_HIGHLIGHT",                   N_SET_DRAW_HIGHLIGHT);
    vm->RegisterNativeFunction(NATIVE_SET_OPEN_CLOSE,                       "SET_OPEN_CLOSE",                       N_SET_OPEN_CLOSE);
    vm->RegisterNativeFunction(NATIVE_SET_INTRO_BUILDING,                   "SET_INTRO_BUILDING",                   N_SET_INTRO_BUILDING);
    vm->RegisterNativeFunction(NATIVE_SET_SUN_DRAW,                         "SET_SUN_DRAW",                         N_SET_SUN_DRAW);
    vm->RegisterNativeFunction(NATIVE_SET_HURT_BY_FIRE,                     "SET_HURT_BY_FIRE",                     N_SET_HURT_BY_FIRE);
    vm->RegisterNativeFunction(NATIVE_CONFINED_OBJECT,                      "CONFINED_OBJECT",                      N_CONFINED_OBJECT);
    vm->RegisterNativeFunction(NATIVE_CLEAR_CONFINED_OBJECT,                "CLEAR_CONFINED_OBJECT",                N_CLEAR_CONFINED_OBJECT);
    vm->RegisterNativeFunction(NATIVE_HIGHLIGHT_PROPERTIES,                 "HIGHLIGHT_PROPERTIES",                 N_HIGHLIGHT_PROPERTIES);
    vm->RegisterNativeFunction(NATIVE_CALL_NEAR_IN_STATE,                   "CALL_NEAR_IN_STATE",                   N_CALL_NEAR_IN_STATE);
    vm->RegisterNativeFunction(NATIVE_PLAY_JC_SPECIAL,                      "PLAY_JC_SPECIAL",                      N_PLAY_JC_SPECIAL);
    vm->RegisterNativeFunction(NATIVE_IS_PLAYING_JC_SPECIAL,                "IS_PLAYING_JC_SPECIAL",                N_IS_PLAYING_JC_SPECIAL);
    vm->RegisterNativeFunction(NATIVE_IS_LOCKED_INTERACTION,                "IS_LOCKED_INTERACTION",                N_IS_LOCKED_INTERACTION);
    vm->RegisterNativeFunction(NATIVE_ENTER_EXIT_CITADEL,                   "ENTER_EXIT_CITADEL",                   N_ENTER_EXIT_CITADEL);
    vm->RegisterNativeFunction(NATIVE_MUSIC_PLAYED_350,                     "MUSIC_PLAYED_350",                     N_MUSIC_PLAYED_350);
    vm->RegisterNativeFunction(NATIVE_TOGGLE_LEASH,                         "TOGGLE_LEASH",                         N_TOGGLE_LEASH);
    vm->RegisterNativeFunction(NATIVE_SET_GAME_SOUND,                       "SET_GAME_SOUND",                       N_SET_GAME_SOUND);
    vm->RegisterNativeFunction(NATIVE_SEX_IS_MALE,                          "SEX_IS_MALE",                          N_SEX_IS_MALE);
    vm->RegisterNativeFunction(NATIVE_SET_SCAFFOLD_PROPERTIES,              "SET_SCAFFOLD_PROPERTIES",              N_SET_SCAFFOLD_PROPERTIES);
    vm->RegisterNativeFunction(NATIVE_SET_DISCIPLE,                         "SET_DISCIPLE",                         N_SET_DISCIPLE);
    vm->RegisterNativeFunction(NATIVE_SET_SET_ON_FIRE,                      "SET_SET_ON_FIRE",                      N_SET_SET_ON_FIRE);
    vm->RegisterNativeFunction(NATIVE_SET_OBJECT_CARRYING,                  "SET_OBJECT_CARRYING",                  N_SET_OBJECT_CARRYING);
    vm->RegisterNativeFunction(NATIVE_GET_TIME_SINCE_OBJECT_ATTACKED,       "GET_TIME_SINCE_OBJECT_ATTACKED",       N_GET_TIME_SINCE_OBJECT_ATTACKED);
    vm->RegisterNativeFunction(NATIVE_SET_FIXED_CAM_ROTATION,               "SET_FIXED_CAM_ROTATION",               N_SET_FIXED_CAM_ROTATION);
    vm->RegisterNativeFunction(NATIVE_SAVE_GAME_IN_SLOT,                    "SAVE_GAME_IN_SLOT",                    N_SAVE_GAME_IN_SLOT);
    vm->RegisterNativeFunction(NATIVE_CAN_SKIP_TUTORIAL,                    "CAN_SKIP_TUTORIAL",                    N_CAN_SKIP_TUTORIAL);
}

} // namespace lhvm
