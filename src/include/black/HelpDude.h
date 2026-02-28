#pragma once
// HelpDude — help system advisor character
// Struct layout from bw1-decomp (HelpDude.h)
//
// Size: 0x8 bytes (LocalBase-derived, empty body)
// Overrides: ToBeDeleted, Get3DSoundPos

#include "LocalBase.h"

struct HelpDude : LocalBase {
    void ToBeDeleted(int param) override;
    int  Get3DSoundPos(LHPoint* pos) override;
};
static_assert(sizeof(HelpDude) == 0x8, "HelpDude size mismatch");
