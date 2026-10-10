// WorshipSite — worship site building (CitadelPart subclass)
// Method stubs from bw1-decomp
#include "../include/black/WorshipSite.h"
#include "../include/black/BuildingSite.h"
#include "../include/black/WorshipTotem.h"
#include "../include/black/Town.h"
#include "../include/black/Dance.h"
#include "../include/black/Player.h"
#include "../include/black/Villager.h"
#include "../include/black/WorshipSpellIcon.h"
#include "../include/black/InfoDat.h"
#include "../include/black/CreatureBrain.h"
#include "../include/black/GInterfaceStatus.h"
#include <cstring>
#include <cmath>

// === Overrides of Base virtuals ===

// 0x0077aa60
void WorshipSite::ToBeDeleted(int /*param*/) {}

// === Overrides of GameThing virtuals ===

// 0x0052ed20: clears dance pointer
void WorshipSite::RemoveDance() { dance = nullptr; }
// 0x0077bd80
uint32_t WorshipSite::GetResource(RESOURCE_TYPE /*type*/) { return 0; }
// 0x0077c5f0
uint32_t WorshipSite::AddResource(RESOURCE_TYPE /*type*/, uint32_t /*amount*/, GInterfaceStatus* /*status*/, bool /*param4*/, const MapCoords& /*coords*/, int /*param6*/) { return 0; }
// 0x0077c670
uint32_t WorshipSite::RemoveResource(RESOURCE_TYPE /*type*/, uint32_t /*amount*/, GInterfaceStatus* /*status*/, bool* /*param4*/) { return 0; }
// 0x0055dce0
char* WorshipSite::GetDebugText() { return "WorshipSite"; }
// 0x0077cd70
uint32_t WorshipSite::GetShowNeedsPos(uint32_t /*param1*/, MapCoords* /*param2*/) { return 0; }
// 0x0077d700
uint32_t WorshipSite::Load(GameOSFile* /*file*/) { return 0; }
// 0x0077d2f0
uint32_t WorshipSite::Save(GameOSFile* /*file*/) { return 0; }
// 0x0055dcd0
uint32_t WorshipSite::GetSaveType() { return 60; }
// 0x0077daf0
void WorshipSite::ResolveLoad() {}

// === Overrides of GameThingWithPos virtuals ===

// 0x0077ced0 — returns the door position as arrive position
MapCoords* WorshipSite::GetArrivePos(MapCoords* out) {
    return GetDoorPos(out);
}
// 0x0055dc30 — returns the interact position (base coords)
void WorshipSite::GetInteractPos(LHPoint* pos) {
    pos->x = *reinterpret_cast<float*>(&coords.x);
    pos->y = *reinterpret_cast<float*>(&coords.z);
    pos->z = coords.altitude;
}
// 0x0055dc80
uint32_t WorshipSite::IsSuitableForCreatureAction() { return 0; }
// 0x004e4b60
uint32_t WorshipSite::CanHaveMagicFoodCastOnMe(Creature* /*creature*/) { return 0; }
// 0x0055dc90
bool32_t WorshipSite::IsWorshipSite_0(Creature* /*creature*/) { return 1; }
// 0x0055dca0
bool32_t WorshipSite::IsWorshipSite_1() { return 1; }
// 0x0055dcb0
WorshipSite* WorshipSite::GetWorshipSite() { return this; }
// 0x0077c310
float WorshipSite::CalculateDesireForFood() { return 0.0f; }
// 0x0077c390
float WorshipSite::CalculateDesireForRest() { return 0.0f; }
// 0x0077c3d0
float WorshipSite::CalculatePeopleHidingIndicator() { return 0.0f; }
// 0x0077d2e0
uint32_t WorshipSite::GetScriptObjectType() { return 0xe; }

// === Overrides of Object virtuals ===

// 0x0077d030
void WorshipSite::UpdateFrom3DPosition() {}
// 0x0077dde0
LHPoint* WorshipSite::GetDefaultFireCentrePos(LHPoint* /*pos*/) { return nullptr; }
// 0x0077de10
float WorshipSite::GetDefaultFireRadius() { return 0.0f; }
// 0x0077b1d0 — per-tick worship site processing
uint32_t WorshipSite::Process() {
    // Process building construction if not yet built
    if (!IsBuilt()) {
        return MultiMapFixed::Process();
    }
    // Process worship charging, update spell icon mana levels, tally villager worship counts
    return 1;
}
// 0x00704310: returns 1
int WorshipSite::GetMesh() const { return 1; }
// 0x005193d0
void WorshipSite::Draw() {}
// 0x0077de70
uint32_t WorshipSite::GetDiscipleStateIfInteractedWith(GInterfaceStatus* /*status*/, Villager* /*villager*/) { return 0; }
// 0x0077b9d0
void WorshipSite::CallVirtualFunctionsForCreation(const MapCoords& /*coords*/) {}
// 0x0077dec0
bool WorshipSite::IsResourceStore(RESOURCE_TYPE /*type*/) { return false; }
// 0x0077e7b0
// v1.0 sub_7071B0. ponytail: the tutorial cue for a held living is not kept.
bool WorshipSite::DeleteObjectAndTakeResource(Object* o, GInterfaceStatus* status) {
    TakeResourceOf(o, status);
    return true;
}
// 0x0077e480
float WorshipSite::GetRadiusMultiplierForApplyingPotToPos() { return 0.0f; }
// 0x0077def0
// v1.0 sub_706BF0: food put in is "Put food in worship site" (row 0).
bool WorshipSite::DoCreatureMimicAfterAddingResource(RESOURCE_TYPE type, GInterfaceStatus* status) {
    if (MultiMapFixed::DoCreatureMimicAfterAddingResource(type, status)) return true;
    if (type != RESOURCE_TYPE_FOOD) return false;
    creature::PlayerDid(status ? status->GetPlayer() : nullptr, 0, this);
    return true;
}
// 0x0077de20 — distance from object to worship site center
float WorshipSite::GetDistanceFromObject_1(Object* object) {
    if (!object) return 0.0f;
    float dx = static_cast<float>(coords.x - object->coords.x);
    float dz = static_cast<float>(coords.z - object->coords.z);
    return sqrtf(dx * dx + dz * dz);
}
// 0x0055dc60
bool WorshipSite::InteractsWithPhysicsObjects() { return false; }
// 0x0077ae30
bool WorshipSite::GetInspectObjectPos(Villager* /*villager*/, MapCoords* /*coords*/) { return false; }
// 0x0077cc90
uint32_t WorshipSite::GetSpecialPos(uint32_t /*param1*/, MapCoords* /*param2*/) { return 0; }
// 0x0077d000
uint32_t WorshipSite::GetObjectCollide() { return 0; }
// 0x0077c120
size_t WorshipSite::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) { return 0; }
// 0x0077dc90
void WorshipSite::GetNearestEdgeOfObject(Object* /*object*/) {}

// === Overrides of MultiMapFixed virtuals ===

// 0x0077e460
void WorshipSite::GetResourceDropPosForComputerPlayer(MapCoords* out) {
    *out = coords;
}
// 0x0077bdd0 — checks if worship site is fully built
bool WorshipSite::IsBuilt() {
    // WorshipSite overrides: check construction flag and percent_built
    if (field_0x58 & 0x02) return false;
    return GetPercentBuilt() >= 1.0f;
}
// 0x0077ac10 — called when worship site finishes building
bool WorshipSite::Built() {
    if (building_site != nullptr) {
        building_site->ToBeDeleted(0);
    }
    field_0x58 = (field_0x58 & ~2) | 8;
    percent_built = 1.0f;
    return true;
}
// 0x0055dc70
ABODE_TYPE WorshipSite::GetAbodeType() { return static_cast<ABODE_TYPE>(0); }
// 0x0077c5d0
MapCoords* WorshipSite::GetResourcePos(RESOURCE_TYPE /*type*/, int /*param*/) { return nullptr; }
// 0x0077c6d0
MapCoords* WorshipSite::GetResourceNearestEdge(MapCoords* /*out*/, RESOURCE_TYPE /*type*/, Object* /*object*/, int /*param*/) { return nullptr; }
// 0x0077ae10
void WorshipSite::RemovePotFromStructure(PotStructure* /*structure*/) {}

// === Non-virtual methods ===

// ponytail: the footpath to the town (sub_6D3BE0, GFootpathLink) and the
// town's spells (sub_705860) are not translated.
void WorshipSite::AddTown(Town* town) {
    town->SetWorshipSite(this);
    if (!towns.Has(town)) towns.Add(town);
    AddTownSpells(town);  // sub_705860
}

float WorshipSite::ManaAvailable() const { return field_0x108 ? 1000000.0f : mana_shown - mana_spent; }

// The want is counted in full (+0x100); what is there is taken (+0xFC).
// ponytail: the player's statistics (+604 -> +4384) are not kept.
float WorshipSite::Spend(float amount) {
    if (amount < 0.0f) return 0.0f;
    field_0x100 += amount;
    if (ManaAvailable() >= amount) { mana_spent += amount; return amount; }
    const float got = ManaAvailable();
    mana_spent = mana_shown;
    return got;
}

void WorshipSite::AddWorshipper(Villager* v) {
    if (!v || worshippers.Has(v)) return;
    worshippers.Add(v);
    ++field_0xc8;
}

void WorshipSite::RemoveWorshipper(Villager* v) {
    if (!field_0xc8 || !worshippers.Has(v)) return;
    worshippers.Remove(v);
    --field_0xc8;
}

uint32_t WorshipSite::Dancers() const { return dance ? dance->members : 0; }

namespace {
int32_t SeedInt(int seed, int off) {
    int32_t x = 0;
    if (const void* e = infodat::Element(infodat::DETAIL_SPELL_SEEDS, static_cast<uint32_t>(seed))) std::memcpy(&x, static_cast<const uint8_t*>(e) + off, 4);
    return x;
}
}  // namespace

int SeedBase(int seed) { return SeedInt(seed, 292); }  // seed +292 (sub_6C1980(-1))
int SeedPowerUp(int seed, int magic) {
    if (SeedInt(seed, 292) == magic) return -1;
    for (int i = 0; i < 3; ++i) if (SeedInt(seed, 296 + 4 * i) == magic) return i;
    return -1;
}
int SeedOfMagic(int magic) {                           // sub_6C1A50 / sub_6C1A20
    for (int s = 0; s < 30; ++s)
        for (int off : {292, 296, 300, 304})
            if (SeedInt(s, off) == magic) return s;
    return -1;
}

namespace {
float SiteInfo(const WorshipSite* w, int off) { float x = 0; if (w->info) std::memcpy(&x, reinterpret_cast<const char*>(w->info) + off, 4); return x; }
}

// The dancers x info +324 x the player's worship multiplier (+0x70).
float WorshipSite::ManaProduced() {
    GPlayer* p = GetPlayer();
    return static_cast<float>(Dancers()) * SiteInfo(this, 324) * (p ? p->multipliers[2] : 0.0f);
}

float WorshipSite::MaxMana() const { return static_cast<float>(Dancers()) * SiteInfo(this, 340) + SiteInfo(this, 336); }

// sub_704610 then sub_7047E0, once a turn per site from the citadel
// (sub_44EFB0). What the dancers make is kept, less what the spell icons
// took (+0xFC), at an efficiency that falls as the store nears its most:
// 0.5 - mana / max / 2, at least 0.2 while positive, plus the share spent,
// at most 1.
// ponytail: there are no spell icons yet (sub_704040), so nothing is spent
// and the charging pass of sub_704610 has nothing to feed. Every 1000 turns
// v1.0 also passes some on through the list at +0xAC (sub_420CF0); not
// translated. The dance's look (sub_704A00) is not kept.
void WorshipSite::ProcessWorship() {
    // ponytail: v1.0 counts a dancer in (sub_55E370) and out (vslot 705);
    // with no dance groups built, the members are recounted here: the
    // site's worshippers dancing or on their way to their place (60).
    if (dance) {
        uint32_t n = 0;
        for (LHNode* x = worshippers.head; x; x = x->next) {
            const auto* v = static_cast<const Villager*>(x->obj);
            n += v->action.top_state == VILLAGER_STATE_WORSHIPPING_AT_WORSHIP_SITE || v->action.final_state == VILLAGER_STATE_WORSHIPPING_AT_WORSHIP_SITE;
        }
        dance->members = n;
    }
    const float made = ManaProduced();
    if (made == 0.0f) field_0x114 = field_0x100 == 0.0f ? 0.0f : 1.0f;
    else field_0x114 = (field_0x100 - made) / made;

    // The charging icons share what there is (sub_704610): each gets an
    // equal part, and each one's full want is spent (sub_705BA0).
    if (field_0x114 <= 0.0f) {
        float n = 0.0f, want = 0.0f;
        bool reserve = false;
        field_0x10c = 0;  // +0x111 in v1.0 (a byte): something charged this turn
        for (WorshipSpellIcon* i = icons; i; i = i->next) {
            if (i->charging && i->Demand() > 0.0f) { n += 1.0f; want += i->Demand(); }
            if (i->field_0x12c) reserve = true;
        }
        if (n != 0.0f) {
            float avail = ManaAvailable();
            if (reserve) avail = std::max(0.0f, avail - SiteInfo(this, 344));  // sub_705B10
            const float share = std::min(avail, want) / n;
            if (share != 0.0f)
                for (WorshipSpellIcon* i = icons; i; i = i->next) {
                    if (!i->charging) continue;
                    const float d = i->Demand();
                    if (d <= 0.0f) continue;
                    i->AddCharge(share);
                    if (!field_0x108) Spend(d);
                    field_0x10c = 1;
                }
        }
    }
    for (WorshipSpellIcon* i = icons; i; i = i->next) i->Process();  // vslot 383

    const float spent_share = made == 0.0f ? 1.0f : mana_spent / made;
    const float most = MaxMana();
    float eff = 0.5f - (most != 0.0f ? mana / most : 0.0f) * 0.5f;
    if (eff <= 0.0f) eff = 0.0f;
    else if (eff < 0.2f) eff = 0.2f;
    eff += spent_share;
    if (eff >= 1.0f) eff = 1.0f;
    const float kept = made * eff;
    const float dancers = static_cast<float>(Dancers());
    worship_rate = dancers == 0.0f ? 0.0f : kept / dancers;
    float m = mana - (mana_spent - kept);
    if (m <= 0.0f) m = 0.0f;
    mana = m;
    mana_spent = 0.0f;
    field_0x100 = 0.0f;
    mana_shown = m + made;
}

// 0x0077afc0
MapCoords* WorshipSite::GetSpellIconPosFromSlot(MapCoords* /*coords*/, uint32_t /*slot*/, float /*angle*/) { return nullptr; }
// 0x0077b080
MapCoords* WorshipSite::GetSpellIconPos(MapCoords* /*coords*/, int16_t* /*slot*/) { return nullptr; }
// 0x0077c430
void WorshipSite::AddSpellIcon(WorshipSpellIcon* icon) {  // sub_7054C0
    icon->next = icons;
    icons = icon;
    ++icon_count;
}
// 0x0077c910
// sub_705860: an icon for each of the town's spells (its list +0x770).
// ponytail: that list is the town centre's icons (TownCentreSpellIcon,
// sub_6D6180), which are not built; the town's held magic stands in, each
// base magic with its seed (sub_6C1A50).
void WorshipSite::AddTownSpells(Town* town) {
    if (!town->town_centre) return;
    for (int m = 1; m < 42; ++m) {
        if (!town->IsMagicTypeHeld(static_cast<MAGIC_TYPE>(m))) continue;
        const int seed = SeedOfMagic(m);
        if (seed >= 0 && SeedBase(seed) == m) AddSpellIconIfNecessary(static_cast<SPELL_SEED_TYPE>(seed));
    }
}
// 0x0077c9e0
// sub_705930: the seed's icon if the site has none (sub_7077C0: 320 bytes,
// SpellIcon info 0xCBE080, the seed's record, at the site).
// ponytail: an existing icon's refresh (sub_708410), the icon's place by
// slot (sub_7041E0) and its look are not kept.
void WorshipSite::AddSpellIconIfNecessary(SPELL_SEED_TYPE seed_type) {
    const auto* rec = static_cast<const GSpellSeedInfo*>(infodat::Element(infodat::DETAIL_SPELL_SEEDS, static_cast<uint32_t>(seed_type)));
    if (!rec) return;
    for (WorshipSpellIcon* i = icons; i; i = i->next)
        if (i->seed_info == rec) return;
    auto* icon = new WorshipSpellIcon();
    icon->seed_info = const_cast<GSpellSeedInfo*>(rec);
    icon->SetPos(coords);
    icon->scale = 1.0f;
    icon->site = this;
    icon->powerup = -1;
    icon->slot = -1;
    AddSpellIcon(icon);
}
// 0x0077cf30 — returns position of the totem at this worship site
MapCoords* WorshipSite::GetTotemPos(MapCoords* coords) {
    if (totem) {
        *coords = totem->coords;
    } else {
        *coords = this->coords;
    }
    return coords;
}
// 0x0077d0a0
void WorshipSite::RemoveVillagerFromWorshipCount(Villager* /*villager*/) {}
// 0x0077e1d0
void WorshipSite::RemoveVillagerRequestingToGoHome(Villager* /*villager*/) {}
// 0x0077e260 — returns count of villagers wanting to go home
int WorshipSite::GetNumVillagersRequestingToGoHome() {
    return num_villagers_requesting_to_go_home;
}
