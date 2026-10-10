// PlannedTownCitadelHeart class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)

#include <black/PlannedTownCitadelHeart.h>

#include <black/Citadel.h>
#include <black/CitadelHeart.h>
#include <black/InfoDat.h>
#include <black/LHVMObjects.h>
#include <black/Player.h>
#include <black/Town.h>
#include <cstring>

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
    Citadel* citadel = player->citadel ? player->citadel : NewCitadel(player, coords);
    // The heart at the plan's place, angle and scale; +148 is the plan's town.
    CitadelHeart* heart = NewCitadelHeart(coords, info, citadel, field_0x28, scale,
                                          built, reinterpret_cast<GameThing*>(town));
    if (field_0x30) heart->field_0x58 |= 4;
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
