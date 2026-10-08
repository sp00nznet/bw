// PlannedTownCitadelHeart class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)

#include <black/PlannedTownCitadelHeart.h>

#include <black/Citadel.h>
#include <black/CitadelHeart.h>
#include <black/InfoDat.h>
#include <black/LHVMObjects.h>
#include <black/Player.h>
#include <black/Town.h>

Town* PlannedTownCitadelHeart::GetTown() { return town; }

void PlannedTownCitadelHeart::ToBeDeleted(int param) {
    // Original at 0x00467e80 — complex cleanup
    PlannedMultiMapFixed::ToBeDeleted(param);
}

char* PlannedTownCitadelHeart::GetDebugText() {
    // Original at 0x00467e50
    static char text[] = "PlannedTownCitadelHeart";
    return text;
}

uint32_t PlannedTownCitadelHeart::Load(GameOSFile* /*file*/) {
    // Original at 0x00467ff0 — complex serialization
    return 0;
}

uint32_t PlannedTownCitadelHeart::Save(GameOSFile* /*file*/) {
    // Original at 0x00467fc0 — complex serialization
    return 0;
}

uint32_t PlannedTownCitadelHeart::GetSaveType() {
    // Original at 0x00467e40: returns 0x39
    return 0x39;
}

bool32_t PlannedTownCitadelHeart::IsWonder() {
    // Original at 0x00467e20 — complex
    return 0;
}

// v1.0 sub_453140 (vslot 320): the land check (sub_454760), then vslot 321.
// ponytail: the land check is not translated.
MultiMapFixed* PlannedTownCitadelHeart::CreatePlanned(float built) { return CreatePlannedNoFixedCheck(built); }

// v1.0 sub_453190 (vslot 321): the town's player's citadel (a new one,
// sub_44E400, if it has none), then the heart in it at the plan's place
// (sub_450280), owned by the town; then the plan goes.
MultiMapFixed* PlannedTownCitadelHeart::CreatePlannedNoFixedCheck(float built) {
    GPlayer* player = town ? town->GetPlayer() : nullptr;
    if (!player) return nullptr;
    Citadel* citadel = player->citadel;
    if (!citadel) {
        // sub_44E400: Container (sub_456870: position, info, player), then the
        // player's citadel (+608). ponytail: sub_44E610 and the 8-byte list at
        // +124 are not translated.
        citadel = new Citadel();
        citadel->info = static_cast<GContainerInfo*>(const_cast<void*>(infodat::Element(infodat::DETAIL_CITADEL_INFO, 0)));
        citadel->SetPos(coords);
        citadel->owner = player;
        player->citadel = citadel;
    }
    // sub_450280 -> sub_44FED0: a CitadelPart at the plan's place, angle and
    // scale, `built` of the way up; the citadel's heart if it has none, the
    // citadel's power then raised by built x info +284. ponytail: the power
    // base (sub_44F720), sub_450200, the entrance (sub_450590, +0x98) and
    // vslot 406 are not translated.
    auto* heart = new CitadelHeart();
    heart->SetPos(coords);
    heart->obj_coords = coords;
    heart->y_angle = field_0x28;
    heart->scale = scale > 0.0f ? scale : 1.0f;
    heart->life = 1.0f;
    heart->info = info;
    heart->percent_built = built;
    heart->citadel = citadel;
    heart->field_0x90 = 0;
    heart->field_0x8c = 0;
    heart->field_0x9c = 2;
    if (!citadel->heart) citadel->heart = heart;
    heart->field_0x94 = reinterpret_cast<GameThing*>(town);  // sub_453190: heart +148 = the plan's town
    if (field_0x30) heart->field_0x58 |= 4;
    heart->InsertMapObject();
    lhvm::RegisterObject(heart);
    // vslot 322 (PostCreatePlanned) is not translated; vslot 3 deletes the plan.
    town->RemovePlanned(this);
    delete this;
    return heart;
}

bool PlannedTownCitadelHeart::IsCivic() {
    // Original at 0x00467e10 — complex
    return false;
}

ABODE_TYPE PlannedTownCitadelHeart::GetAbodeType() {
    // Original at 0x00467e30 — complex
    return static_cast<ABODE_TYPE>(0);
}
