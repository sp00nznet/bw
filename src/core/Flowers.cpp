// Flowers class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Simple methods at 0x005279xx are packed 16 bytes apart.

#include <black/Flowers.h>

char* Flowers::GetDebugText() {
    static char text[] = "Flowers";
    return text;
}

uint32_t Flowers::GetSaveType() {
    // Original at 0x00527990
    return 0;
}

void Flowers::CallVirtualFunctionsForCreation(const MapCoords& coords) {
    // Original at 0x00527a30 — complex
    Feature::CallVirtualFunctionsForCreation(coords);
}

LH3DObject_ObjectType Flowers::Get3DType() {
    // Original at 0x00527980
    return LH3D_OBJECT_TYPE_DEFAULT;
}

size_t Flowers::SaveObject(LHOSFile* /*param1*/, const MapCoords* /*param2*/) {
    // Original at 0x00527a80 — complex
    return 0;
}
