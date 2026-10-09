#include "../include/black/GInterfaceStatus.h"
#include "../include/black/Object.h"
#include "../include/black/Player.h"
#include "../include/black/Town.h"
#include <cmath>

GInterfaceStatus::~GInterfaceStatus() {}
void GInterfaceStatus::ToBeDeleted(int param) {}
GPlayer* GInterfaceStatus::GetPlayer() { return PlayerAt(player_number); }  // sub_59BCA0
void GInterfaceStatus::UpdateSpellInfo(Spell* spell, PSysProcessInfo* info) {}
char* GInterfaceStatus::GetDebugText() { return nullptr; }
uint32_t GInterfaceStatus::Load(GameOSFile* file) { return 0; }
uint32_t GInterfaceStatus::Save(GameOSFile* file) { return 0; }
uint32_t GInterfaceStatus::GetSaveType() { return 101; }
void GInterfaceStatus::SaveExtraData(GameOSFile* file) {}
void GInterfaceStatus::ResolveLoad() {}
const char* GInterfaceStatus::GetText() { return nullptr; }

void GInterfaceStatus::SetActive(int param) {}
void GInterfaceStatus::ResetActionState() {}
void GInterfaceStatus::SetToZero(GInterface* iface) {}
void* GInterfaceStatus::GetFirstObjectInCurrentHand() { return nullptr; }
bool GInterfaceStatus::IsSpaceInHands() { return false; }
GInterface* GInterfaceStatus::GetInterface() { return nullptr; }
void GInterfaceStatus::Init(uint8_t number, GInterface* i) { player_number = number; iface = i; }

namespace {
// sub_5BFD00 -> sub_58E1E0: the player with the most influence at the point,
// else the local player. ponytail: there is no influence map in core
// (sub_58DDC0); the player of the nearest town whose radius holds the point
// stands in, else player 0.
GPlayer* LandOwner(const MapCoords& at) {
    GPlayer* best = PlayerAt(0);
    float nearest = 3.4028235e38f;
    for (uint32_t p = 0; p < 8; ++p)
        for (Town* t = PlayerAt(p)->towns.first; t; t = t->next) {
            const float d = std::hypot(MetresOf(at.x - t->coords.x), MetresOf(at.z - t->coords.z));
            if (d <= t->GetRadius() && d < nearest) nearest = d, best = PlayerAt(p);
        }
    return best;
}
GInterfaceStatus* g_hands[8];
}  // namespace

// ponytail: the rest of sub_59C390 -- a held living (+36 bit 0x40), the hand
// state change, the multi-pick-up check, the interface's guidance -- is not
// translated.
bool GInterfaceStatus::PickUp(Object* o) {
    if (!o || held) return false;
    held = o;
    taken_from = LandOwner(o->coords);
    return true;
}

bool GInterfaceStatus::DropOn(Object* target) {
    Object* o = held;
    held = nullptr;
    return o && target && target->DeleteObjectAndTakeResource(o, this);
}

GInterfaceStatus* HandStatusOf(GPlayer* player) {
    if (!player) return nullptr;
    GInterfaceStatus*& s = g_hands[player->player_number & 7];
    if (!s) {
        s = new GInterfaceStatus();
        s->Init(player->player_number, nullptr);
    }
    return s;
}
