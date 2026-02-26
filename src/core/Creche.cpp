// Creche class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)

#include <black/Creche.h>

void Creche::ToBeDeleted(int /*param*/) {
    // Original at 0x0050aa30 — complex
}

char* Creche::GetDebugText() {
    static char text[] = "Creche";
    return text;
}

uint32_t Creche::GetSaveType() {
    // Original at 0x0050a9e0
    return 0;
}

MapCoords* Creche::GetArrivePos(MapCoords* out) {
    // Original at 0x0050a990: calls GetDoorPos
    return GetDoorPos(out);
}

bool32_t Creche::CanActAsAContainer(Creature* /*creature*/) {
    // Original at 0x0050a9b0
    return 1;
}

bool32_t Creche::IsStoragePit(Creature* /*creature*/) {
    // Original at 0x0050a9c0
    return 0;
}

void Creche::ReduceLife(float /*value*/, GPlayer* /*player*/) {
    // Original at 0x0050ab90 — complex
}

LH3DObject_ObjectType Creche::Get3DType() {
    // Original at 0x0050a9d0
    return LH3D_OBJECT_TYPE_DEFAULT;
}

void Creche::DeleteDependancys() {
    // Original at 0x0050aa50 — complex
}

void Creche::MakeFunctional() {
    // Original at 0x0050ab50 — complex
}
