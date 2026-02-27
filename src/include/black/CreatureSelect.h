#pragma once
// CreatureSelect — creature selection screen handler
// Struct layout from bw1-decomp (CreatureSelect.h)
//
// Size: 0x10 bytes (extends Prss, no additional fields)
// Overrides: ProcessTurn, Display, ClickFunction

#include "Prss.h"

struct CreatureSelect : public Prss {
    // Override methods (stubs — bodies come from Ghidra decompilation)
    int  ProcessTurn() override;
    void Display() override;
    void ClickFunction(int param_1, int param_2, int param_3) override;
};
static_assert(sizeof(CreatureSelect) == 0x10, "CreatureSelect size mismatch");
