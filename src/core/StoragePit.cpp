// StoragePit class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)

#include <black/StoragePit.h>
#include <black/InfoDat.h>
#include <black/ObjectInfo.h>
#include <black/PileFood.h>
#include <black/PileWood.h>

#include <cstring>

namespace {

// The pit's piles: one of food (+0xC4, POT_INFO_STORAGE_PIT_FOOD_PILE) and five
// of wood (+0xC8..+0xD8, pot infos 3..7), filled in order.
PileResource** Piles(StoragePit* p, RESOURCE_TYPE type) {
    return type == 0 ? reinterpret_cast<PileResource**>(&p->pile_food) : reinterpret_cast<PileResource**>(&p->pile_wood);
}
int PileCount(RESOURCE_TYPE type) { return type == 0 ? 1 : type == 1 ? 5 : 0; }

// sub_616C40 for a pile of the pit (sub_617D30 food, sub_618830 wood).
// ponytail: it lies at the pit's own position; the original puts each at its
// resource position (sub_6C9590 -> vslot 510).
PileResource* MakePile(StoragePit* pit, RESOURCE_TYPE type, int i) {
    PileResource* p = type == 0 ? static_cast<PileResource*>(new PileFood()) : new PileWood();
    p->info = infodat::Get<GObjectInfo>(infodat::DETAIL_POT_INFO, static_cast<uint32_t>((type == 0 ? 2 : 3) + i));
    p->coords = pit->coords;
    p->field_0x68 = type;
    p->field_0x78 = pit;  // PotStructure: the structure it belongs to
    return p;
}

}  // namespace

void StoragePit::Delete(int param) { Abode::Delete(param); } // 0x00732c10
void StoragePit::ToBeDeleted(int param) { Abode::ToBeDeleted(param); } // 0x00732c30

// sub_6C91A0: into the piles, making each as it is needed; what they took is
// then counted by the pit itself (vslot 569 -> its own JustAddResource) and
// returned. ponytail: the delegation of wood to +0x74 when set, and the town's
// notice of new food (vslot 18 +1512), are not translated.
uint32_t StoragePit::AddResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool param4, const MapCoords& coords, int param6) {
    uint32_t put = 0;
    PileResource** piles = Piles(this, type);
    for (int i = 0; i < PileCount(type) && amount; ++i) {
        if (!piles[i]) piles[i] = MakePile(this, type, i);
        const uint32_t n = piles[i]->JustAddResource(type, amount, param4);
        put += n;
        amount -= n;
    }
    if (put) Abode::AddResource(type, put, status, param4, coords, param6);
    return put;
}

// sub_6C94E0: out of the piles, the last wood pile first; then the pit's own
// count (vslot 570).
uint32_t StoragePit::RemoveResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool* param4) {
    uint32_t took = 0;
    PileResource** piles = Piles(this, type);
    for (int i = PileCount(type) - 1; i >= 0 && amount; --i) {
        if (!piles[i]) continue;
        const uint32_t n = piles[i]->JustRemoveResource(type, amount, nullptr);
        took += n;
        amount -= n;
    }
    if (took) Abode::RemoveResource(type, took, status, param4);
    return took;
}

char* StoragePit::GetDebugText() { static char t[] = "StoragePit"; return t; } // 0x0055cd40
uint32_t StoragePit::Load(GameOSFile*) { return 0; } // 0x00733920
uint32_t StoragePit::Save(GameOSFile*) { return 0; } // 0x007338d0
uint32_t StoragePit::GetSaveType() { return 8; } // 0x0055cd30

MapCoords* StoragePit::GetArrivePos(MapCoords* out) { return GetDoorPos(out); } // 0x0055ccb0
bool32_t StoragePit::IsCastShadowAtNight() { return 1; } // 0x0055ccf0
bool32_t StoragePit::CanBeEatenByCreature(Creature*) { return 1; } // v1.0 vslot 139
bool32_t StoragePit::CanActAsAContainer(Creature*) { return 1; } // 0x0055cd00
bool32_t StoragePit::CanHaveMagicFoodCastOnMe(Creature*) { return 0; } // 0x004e4b50
bool32_t StoragePit::CanHaveMagicWoodCastOnMe(Creature*) { return 1; } // v1.0 vslot 176
bool32_t StoragePit::IsStoragePit(Creature*) { return 1; } // 0x004e4990
bool32_t StoragePit::IsStoragePitWithFoodInIt(Creature*) {
    // 0x004e4d90 — returns true if storage pit has food
    return GetResource(static_cast<RESOURCE_TYPE>(0)) > 0 ? 1 : 0;
}
bool32_t StoragePit::IsStoragePitBelongingToAnotherPlayer(Creature*) { return 0; } // 0x004e49a0
bool32_t StoragePit::IsStoragePitBelongingToMyPlayer(Creature*) { return 0; } // 0x004e49e0
bool32_t StoragePit::IsPoisoned() { return 0; } // 0x007336b0

void StoragePit::Draw() { /* 0x00519350 */ }
uint32_t StoragePit::GetDiscipleStateIfInteractedWith(GInterfaceStatus*, Villager*) { return 0; } // 0x00733a20
void StoragePit::CallVirtualFunctionsForCreation(const MapCoords&) { /* 0x00732e80 */ }
LH3DObject_ObjectType StoragePit::Get3DType() { return static_cast<LH3DObject_ObjectType>(0); } // 0x0055ccd0
bool StoragePit::IsResourceStore(RESOURCE_TYPE) { return true; } // 0x0055cd20
bool StoragePit::DeleteObjectAndTakeResource(Object*, GInterfaceStatus*) { return false; } // 0x00733750
bool StoragePit::DoCreatureMimicAfterAddingResource(RESOURCE_TYPE, GInterfaceStatus*) { return false; } // 0x00733810
void StoragePit::SetPoisonedResource(RESOURCE_TYPE, int) { /* 0x007335f0 */ }
void StoragePit::SetPoisoned(int) { /* 0x007335d0 */ }
void StoragePit::ReactToPhysicsImpact(PhysicsObject*, bool) { /* 0x00733730 */ }

bool StoragePit::IsPoisonedResource() { return false; } // 0x00733550
MapCoords* StoragePit::GetResourceNearestEdge(MapCoords* c, RESOURCE_TYPE, Object*, int) { return c; } // 0x00733400
int StoragePit::CalulateAmountOverMaximum(RESOURCE_TYPE) { return 0; } // 0x00733260
void StoragePit::RemovePotFromStructure(PotStructure*) { /* 0x007331d0 */ }

void StoragePit::DeleteDependancys() { /* 0x00732cd0 */ }
void StoragePit::MakeFunctional() { /* 0x00732f30 */ }
void StoragePit::StopBeingFunctional(GPlayer*) { /* 0x00733960 */ }
void StoragePit::RestartBeingFunctional() { /* 0x007339d0 */ }
bool StoragePit::CausesTownEmergencyIfDamaged() { return true; } // 0x0055cce0
