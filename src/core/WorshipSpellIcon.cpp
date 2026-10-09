// WorshipSpellIcon — spell icon on worship site totem
// Method stubs from bw1-decomp
#include "../include/black/WorshipSpellIcon.h"
#include "../include/black/InfoDat.h"
#include "../include/black/Player.h"
#include "../include/black/WorshipSite.h"
#include "../include/black/Citadel.h"
#include <cstring>

namespace {
const uint8_t* SeedRec(const WorshipSpellIcon* i) { return reinterpret_cast<const uint8_t*>(i->seed_info); }
int32_t SeedInt(const WorshipSpellIcon* i, int off) { int32_t x = 0; if (i->seed_info) std::memcpy(&x, SeedRec(i) + off, 4); return x; }
HandSeed g_hands[8];
}  // namespace

HandSeed& HeldSeed(GPlayer* p) { return g_hands[p ? p->player_number & 7 : 0]; }

// === Overrides of Base virtuals ===

// 0x0077f230
void WorshipSpellIcon::ToBeDeleted(int /*param*/) {}

// === Overrides of GameThing virtuals ===

// 0x0077f6f0
void WorshipSpellIcon::MaintainSpell(uint32_t /*param1*/, float /*param2*/) {}
// 0x0077f750
void WorshipSpellIcon::UpdateSpellInfo(Spell* /*spell*/, PSysProcessInfo* /*info*/) {}
// 0x0077f100
char* WorshipSpellIcon::GetDebugText() { return "WorshipSpellIcon"; }
// 0x007801f0
uint32_t WorshipSpellIcon::Load(GameOSFile* /*file*/) { return 0; }
// 0x0077ff80
uint32_t WorshipSpellIcon::Save(GameOSFile* /*file*/) { return 0; }
// 0x0077f0f0
uint32_t WorshipSpellIcon::GetSaveType() { return 120; }

// === Overrides of GameThingWithPos virtuals ===

// 0x0077f0a0
WorshipSite* WorshipSpellIcon::GetWorshipSite() { return site; }

// === Overrides of Object virtuals ===

// 0x0077f0e0
void WorshipSpellIcon::ApplyEffect(EffectValues* /*values*/, int /*param*/) {}
// v1.0 sub_7078A0 (vslot 383). Charged, the icon's charge goes to the
// charger's hand as a seed (sub_707E50 / sub_707DF0) and it stops charging.
// ponytail: the refresh countdown (+0x114), the debug fill (game flag
// 0x2000), a seed already in the hand topping up (sub_7079A0 -> sub_7081E0,
// sub_6C0570) and the first-charge help (sub_7079F0) are not translated.
uint32_t WorshipSpellIcon::Process() {
    if (!charging || Demand() > 0.0f) return 1;
    if (charger && charger->type == PLAYER_TYPE_HUMAN) {
        HandSeed& h = HeldSeed(charger);
        h.seed = static_cast<int>((SeedRec(this) - static_cast<const uint8_t*>(infodat::Element(infodat::DETAIL_SPELL_SEEDS, 0))) / 400);
        h.charge = charge;
        charge = 0.0f;
    }
    charging = 0;
    charger = nullptr;
    powerup = -1;
    return 1;
}
// 0x0077f290
void WorshipSpellIcon::CallVirtualFunctionsForCreation(const MapCoords& /*coords*/) {}
// 0x0077f0b0
uint32_t WorshipSpellIcon::IsEffectReceiver(EffectValues* /*values*/) { return 0; }
// 0x0077f0d0
size_t WorshipSpellIcon::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) { return 0; }

// === Non-virtual methods ===

// 0x0077f1f0
void WorshipSpellIcon::SetZero() {}
// 0x0077f320
void WorshipSpellIcon::UpdateGraphicsWithPULevels() {}
// 0x0077ff40
void WorshipSpellIcon::StopRemoveFromPlayer() {}

int WorshipSpellIcon::MagicType() const {
    const int32_t m = powerup >= 0 && powerup < 3 ? SeedInt(this, 296 + 4 * powerup) : 0;
    return m ? m : SeedInt(this, 292);
}

// ponytail: a seed already in the hand is costed by the hand's seed
// (sub_6C02A0); there is none here.
float WorshipSpellIcon::Cost() const {
    float c = 0.0f;
    if (const void* e = infodat::Element(infodat::DETAIL_MAGIC_EFFECT_INFO, static_cast<uint32_t>(MagicType())))
        std::memcpy(&c, static_cast<const uint8_t*>(e) + 120, 4);
    return c;
}

float WorshipSpellIcon::Demand() const { return Cost() - charge; }

float WorshipSpellIcon::AddCharge(float amount) {
    const float most = Cost();
    if (amount + charge <= most) { charge += amount; return amount; }
    const float over = amount - (most - charge);
    charge = most;
    return over;
}

// The player holds the magic (sub_5F93C0: +0x144, or its count at +0x188),
// and the site has mana or the icon some charge.
bool WorshipSpellIcon::CanCharge(GPlayer* who, int pu, bool need_mana) {
    if (charging || !who) return false;
    const int prev = powerup;
    powerup = pu;
    const int m = MagicType();
    powerup = prev;
    if (m < 0 || m >= 42 || who->magic_remainder[m] <= 0) return false;
    if (site && (!need_mana || site->ManaAvailable() > 0.0f)) return true;
    return charge != 0.0f;
}

// sub_708040 -> sub_707F00. ponytail: an icon already charged hands its seed
// over at once (sub_707E50 / sub_707DF0) on its next turn, not here; the
// start turn (sub_707B90) is not kept.
bool WorshipSpellIcon::StartCharging(GPlayer* who, int pu, bool need_mana) {
    if (!CanCharge(who, pu, need_mana)) return false;
    powerup = pu;
    charging = 1;
    charger = who;
    return true;
}

WorshipSpellIcon* ChargeSpell(GPlayer* player, int seed) {
    if (!player || !player->citadel || seed < 0) return nullptr;
    const void* rec = infodat::Element(infodat::DETAIL_SPELL_SEEDS, static_cast<uint32_t>(seed));
    WorshipSpellIcon* best = nullptr;
    float most = -1.0f;
    for (WorshipSite* ws : player->citadel->worship_sites) {
        if (!ws) continue;
        const float avail = ws->ManaAvailable();
        for (WorshipSpellIcon* i = ws->icons; i; i = i->next)
            if (i->seed_info == rec && avail > most) { most = avail; best = i; }
    }
    return best && best->StartCharging(player, -1, true) ? best : nullptr;
}

// === Static methods ===

// 0x0077f2b0
WorshipSpellIcon* WorshipSpellIcon::Create(const MapCoords& /*coords*/, const GSpellIconInfo* /*icon_info*/,
    const GSpellSeedInfo* /*seed_info*/, WorshipSite* /*site*/, int16_t /*slot*/, float /*param6*/, int /*param7*/) {
    return nullptr;
}
