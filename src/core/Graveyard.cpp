// Graveyard class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)

#include <black/Graveyard.h>

void Graveyard::ToBeDeleted(int /*param*/) {
    // Original at 0x00595cb0 — complex
}

char* Graveyard::GetDebugText() {
    static char text[] = "Graveyard";
    return text;
}

uint32_t Graveyard::Load(GameOSFile* /*file*/) {
    // Original at 0x00595f50 — complex
    return 0;
}

uint32_t Graveyard::Save(GameOSFile* /*file*/) {
    // Original at 0x00595ee0 — complex
    return 0;
}

uint32_t Graveyard::GetSaveType() {
    // Original at 0x0055dff0
    return 0;
}

MapCoords* Graveyard::GetArrivePos(MapCoords* out) {
    // Original at 0x0055df90: calls GetDoorPos
    return GetDoorPos(out);
}

bool32_t Graveyard::CanActAsAContainer(Creature* /*creature*/) {
    // Original at 0x0055dfd0
    return 0;
}

bool32_t Graveyard::IsStoragePit(Creature* /*creature*/) {
    // Original at 0x0055dfe0
    return 0;
}

void Graveyard::CallVirtualFunctionsForCreation(const MapCoords& coords) {
    // Original at 0x00595dd0 — complex
    Abode::CallVirtualFunctionsForCreation(coords);
}

LH3DObject_ObjectType Graveyard::Get3DType() {
    // Original at 0x0055dfb0
    return LH3D_OBJECT_TYPE_DEFAULT;
}

bool Graveyard::InteractsWithPhysicsObjects() {
    // Original at 0x00595cd0: returns false
    return false;
}

void Graveyard::DeleteDependancys() {
    // Original at 0x00595ce0 — complex
}

void Graveyard::MakeFunctional() {
    // Original at 0x00595e00 — complex
}

bool Graveyard::CanBeHiddenIn() {
    // Original at 0x0055dfc0: returns true
    return true;
}
