// LHVM ↔ Object bridge — implementation
//
// Owns the script-handle ↔ Object* registry and wires the LHVM natives
// that touch the entity system. This is intentionally a separate module
// from LHVM.cpp so the VM core stays free of game-object headers.

#include <black/LHVMObjects.h>
#include <black/LHVM.h>
#include <black/Object.h>
#include <black/Terrain.h>
#include <black/types.h>

#include <cmath>
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

static void N_CREATE(LHVM* vm) {
    // The full CREATE pipeline depends on EntityFactory, which is wired by
    // the host. For now we record the position so scripts that immediately
    // GET_POSITION on the result get a sensible value, but no real entity
    // is allocated yet. (Wired in chunk 2 once flock/script-object types
    // are mapped to EntityFactory categories.)
    vm->PopFloat(); vm->PopFloat(); vm->PopFloat(); // z, y, x
    vm->PopInt();   vm->PopInt();                   // subtype, type
    vm->PushObject(0);
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
}

} // namespace lhvm
