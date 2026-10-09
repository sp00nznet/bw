// Citadel class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Citadel is the divine stronghold. Simple methods at 0x00462axx
// are packed 16 bytes apart (trivial returns).

#include <black/Citadel.h>
#include <black/CitadelHeart.h>
#include <black/InfoDat.h>
#include <black/LHVMObjects.h>
#include <black/Player.h>
#include <black/Town.h>
#include <black/WorshipSite.h>
#include <cmath>
#include <cstring>

// ============================================================================
// Overrides of Base virtuals
// ============================================================================

void Citadel::ToBeDeleted(int /*param*/) {
    // Original at 0x00462b90 — complex
}

// ============================================================================
// Overrides of GameThing virtuals
// ============================================================================

char* Citadel::GetDebugText() {
    static char text[] = "Citadel";
    return text;
}

uint32_t Citadel::Load(GameOSFile* /*file*/) {
    // Original at 0x00463dc0 — complex serialization
    return 0;
}

uint32_t Citadel::Save(GameOSFile* /*file*/) {
    // Original at 0x00463b00 — complex serialization
    return 0;
}

uint32_t Citadel::GetSaveType() {
    // Original at 0x0044e3b0
    return 0x35;
}

// ============================================================================
// Overrides of GameThingWithPos virtuals
// ============================================================================

uint32_t Citadel::GetCreatureBeliefType() {
    // v1.0 vslot 67: return 2 (checked by test_chooser)
    return 2;
}

uint32_t Citadel::GetCreatureBeliefListType() {
    // Original at 0x00462a70
    return 0;
}

uint32_t Citadel::GetOrigin() {
    // Original at 0x00462a80
    return 0;
}

bool Citadel::IsActivityObjectWhichAngerAppliesTo(Creature* /*creature*/) {
    // Original at 0x004e40e0 — complex
    return false;
}

bool32_t Citadel::IsSuitableForCreatureActivity() {
    // Original at 0x00462a90: returns 1
    return 1;
}

float Citadel::GetHowMuchCreatureWantsToLookAtMe() {
    // Original at 0x004d1b50 — citadels are very interesting to creatures
    return 1.0f;
}

const char* Citadel::GetText() {
    // Original at 0x00462aa0
    return "Citadel";
}

bool32_t Citadel::IsCitadel() {
    // Original at 0x00462ab0: returns 1
    return 1;
}

// ============================================================================
// Non-virtual methods
// ============================================================================

void* Citadel::AddTown(Town* /*town*/) {
    // Original at 0x00463130 — complex
    return nullptr;
}

WorshipSite* Citadel::FindWorshipSite(const GTribeInfo* tribe_info) {
    for (WorshipSite* w : worship_sites)
        if (w && w->tribe_info == tribe_info) return w;
    return nullptr;
}

WorshipSite* Citadel::FindOrCreateWorshipSite(const GTribeInfo* tribe_info) {
    if (WorshipSite* w = FindWorshipSite(tribe_info)) return w;
    return CreateWorshipSite(tribe_info);
}

WorshipSite* Citadel::WorshipSiteFor(Town* town) {
    if (!town || field_0x74 || !town->CanWorship()) return nullptr;
    return FindOrCreateWorshipSite(static_cast<const GTribeInfo*>(infodat::Element(infodat::DETAIL_TRIBE_INFO, town->tribe_type)));
}

// sub_44EBE0 -> sub_703DB0 -> sub_703AC0. The tribe's record is 28 bytes, its
// worship site record 352 (both by tribe). The slot is the free one of six
// whose place (the heart's mesh point 9 turned by heart angle + slot x 2pi/7,
// sub_44ECD0 / sub_452BB0) is nearest the tribe's nearest town (sub_6CE6D0).
// The site stands at the citadel (+0x14), 0% built, scale 1.
// ponytail: there are no meshes in core, so every slot's place is the heart's
// own (v1.0's fallback when the mesh has no point 9) and the first free slot
// wins. The totem (sub_708CF0), spell icons (sub_704040) and the towns'
// worship distances (sub_6CE140) are not translated.
WorshipSite* Citadel::CreateWorshipSite(const GTribeInfo* tribe_info) {
    const auto* base = static_cast<const uint8_t*>(infodat::Element(infodat::DETAIL_TRIBE_INFO, 0));
    if (!tribe_info || !base) return nullptr;
    const uint32_t tribe = static_cast<uint32_t>((reinterpret_cast<const uint8_t*>(tribe_info) - base) / 28);
    const void* info = infodat::Element(infodat::DETAIL_WORSHIP_SITE_INFO, tribe);
    if (!info) return nullptr;
    uint32_t slot = 0;
    while (slot < 6 && worship_sites[slot]) ++slot;
    if (slot == 6) return nullptr;

    auto* w = new WorshipSite();
    w->SetPos(coords);
    w->obj_coords = coords;
    w->y_angle = (heart ? heart->y_angle : 0.0f) + static_cast<float>(slot) * 0.89759791f;
    w->life = 1.0f;
    w->info = static_cast<GObjectInfo*>(const_cast<void*>(info));
    w->scale = *reinterpret_cast<const float*>(static_cast<const uint8_t*>(info) + 296);  // sub_5EC3B0
    std::memcpy(&w->field_0x7c, static_cast<const uint8_t*>(info) + 284, 4);  // this[31] = info +284
    w->percent_built = 0.0f;
    w->tribe_info = const_cast<GTribeInfo*>(tribe_info);
    w->slot = static_cast<uint8_t>(slot);
    // sub_4545E0: onto the citadel's parts (+0x4C, count +0x50).
    w->citadel = this;
    w->next = reinterpret_cast<CitadelPart*>(part_list[0]);
    part_list[0] = static_cast<uint32_t>(reinterpret_cast<uintptr_t>(w));
    ++part_list[1];
    worship_sites[slot] = w;  // sub_44EE00
    w->InsertMapObject();
    lhvm::RegisterObject(w);
    // sub_7040D0: the player's towns of the tribe worship here.
    if (GPlayer* p = GetPlayer())
        for (Town* t = p->towns.first; t; t = t->next)
            if (t->tribe_type == tribe) w->AddTown(t);
    return w;
}
