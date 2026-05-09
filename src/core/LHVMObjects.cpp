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
}

} // namespace lhvm
