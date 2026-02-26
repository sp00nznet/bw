// Windmill class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)
//
// Windmill is a simple Abode subclass with rotating blades.
// Most logic lives in Open/Close/PreDraw (non-virtual).

#include <black/Windmill.h>

char* Windmill::GetDebugText() {
    // Original at 0x00405910: returns pointer to "Windmill" string
    static char text[] = "Windmill";
    return text;
}

uint32_t Windmill::GetSaveType() {
    // Original at 0x00405900
    return 0xF8;
}

void Windmill::Draw() {
    // Original at 0x00516320 — complex (blade rotation animation)
    // TODO: implement when rendering system is available
}

void Windmill::CallVirtualFunctionsForCreation(const MapCoords& coords) {
    // Original at 0x00405950
    // Calls Abode::CallVirtualFunctionsForCreation, then creates sound tag
    Abode::CallVirtualFunctionsForCreation(coords);
    // TODO: create SoundTag when sound system is available
}
