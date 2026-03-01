#pragma once
// EditorHug — wall-hug editor process
// Struct layout from bw1-decomp (EditorHug.h)
//
// Size: 0x10 bytes (extends Prss, no new fields)

#include "Prss.h"

struct EditorHug : public Prss {
    int  ProcessTurn() override;
    void Display() override;
    void PrssKey(LH_KEY key, uint16_t param_2) override;
    void PrssMouse(MouseInput* param_1) override;
    void ClickFunction(int param_1, int param_2, int param_3) override;
};
static_assert(sizeof(EditorHug) == 0x10, "EditorHug size mismatch");
