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

HandQueryFn  g_hand_query_func  = nullptr;
ClickQueryFn g_click_query_func = nullptr;

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
    vm->PushObject(HandleFor(obj));
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
    vm->PushObject(HandleFor(obj));
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
    vm->PushObject(HandleFor(obj));
}

static void N_CREATE_MIST(LHVM* vm) {
    // 7 floats: x, y, z, plus 4 mist parameters (radius, density, speed, life)
    for (int i = 0; i < 7; i++) vm->PopFloat();
    vm->PushObject(0);  // Mist allocation deferred until weather subsystem
}

static void N_LOAD_CREATURE(LHVM* vm) {
    vm->PopInt();    // creature type
    float z = vm->PopFloat(), y = vm->PopFloat(), x = vm->PopFloat();
    vm->PopObject(); // owning player
    (void)y;
    EntityCreateParams p = {};
    p.world_x = x; p.world_z = z; p.scale = 5.0f;
    Object* obj = EntityFactory::CreateEntity(ENTITY_CAT_CREATURE, p);
    vm->PushObject(HandleFor(obj));
}

static void N_LOAD_MY_CREATURE(LHVM* vm) {
    float z = vm->PopFloat(), y = vm->PopFloat(), x = vm->PopFloat();
    vm->PopObject(); // owning player
    (void)y;
    EntityCreateParams p = {};
    p.world_x = x; p.world_z = z; p.scale = 5.0f;
    Object* obj = EntityFactory::CreateEntity(ENTITY_CAT_CREATURE, p);
    vm->PushObject(HandleFor(obj));
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
    // (cmag mode, x_offset, y_offset, z_offset, creature, (??)) → new creature
    vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); vm->PopFloat();
    uint32_t parent = vm->PopObject();
    Object* p = LookupObject(parent);
    EntityCreateParams pr = {};
    if (p) { pr.world_x = WorldX(p); pr.world_z = WorldZ(p); }
    pr.scale = 5.0f;
    Object* obj = EntityFactory::CreateEntity(ENTITY_CAT_CREATURE, pr);
    vm->PushObject(HandleFor(obj));
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
}

} // namespace lhvm
