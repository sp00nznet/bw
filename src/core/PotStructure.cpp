#include "black/PotStructure.h"
#include "black/MultiMapFixed.h"

void     PotStructure::ToBeDeleted(int param) {}
GPlayer* PotStructure::GetPlayer() { return nullptr; }
void     PotStructure::SetPlayer(GPlayer* player) {}
Town*    PotStructure::GetTown() { return nullptr; }
// sub_617680: Pot's (sub_617140). ponytail: an emptied pot that belongs to no
// structure (+0x78) deletes itself (vslot 3); core leaves it.
uint32_t PotStructure::JustRemoveResource(RESOURCE_TYPE type, uint32_t amount, bool* param3) { return Pot::JustRemoveResource(type, amount, param3); }
// ponytail: sub_618AB0 asks the structure it is part of; here, its own.
uint32_t PotStructure::GetResource(RESOURCE_TYPE type) { return JustGetResource(type, 0, nullptr); }
uint32_t PotStructure::AddResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool param4, const MapCoords& coords, int param6) { return 0; }
// sub_6189C0: from itself, counted off its structure (vslot 570), which
// makes up any shortfall from its other piles (vslot 40). ponytail: the share
// a structure reserves (vslot 571) and the delegation through +0x74 are not
// translated.
uint32_t PotStructure::RemoveResource(RESOURCE_TYPE type, uint32_t amount, GInterfaceStatus* status, bool* param4) {
    uint32_t took = JustRemoveResource(type, amount, param4);
    if (MultiMapFixed* s = field_0x78) {
        if (took) s->JustRemoveResource(type, took, nullptr);
        if (took < amount) took += s->RemoveResource(type, amount - took, status, param4);
    }
    return took;
}
uint32_t PotStructure::Load(GameOSFile* file) { return 0; }
uint32_t PotStructure::Save(GameOSFile* file) { return 0; }
bool32_t PotStructure::CanBeThrownByPlayer() { return 0; }
void     PotStructure::CallVirtualFunctionsForCreation(const MapCoords& coords) {}
bool     PotStructure::IsResourceStore(RESOURCE_TYPE type) { return false; }
void     PotStructure::SetSize() {}
bool     PotStructure::IsPartOfStructure() { return false; }
void     PotStructure::SetSpeedUp(int speed) {}
void     PotStructure::SetMultiMapFixed(MultiMapFixed* multiMapFixed) {}
