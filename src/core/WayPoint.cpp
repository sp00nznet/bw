// WayPoint class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)

#include <black/WayPoint.h>

void WayPoint::ToBeDeleted(int param) {
    // Original at 0x00770c00 — complex cleanup
    GameThingWithPos::ToBeDeleted(param);
}

char* WayPoint::GetDebugText() {
    // Original at 0x00770b30
    static char text[] = "WayPoint";
    return text;
}

uint32_t WayPoint::GetSaveType() {
    // Original at 0x00770b20
    return 0;
}

const char* WayPoint::GetText() {
    // Original at 0x00770b40 — complex
    return "WayPoint";
}
