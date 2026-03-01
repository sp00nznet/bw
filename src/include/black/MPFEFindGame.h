#pragma once
// MPFEFindGame — game finder dialog
// Struct layout from bw1-decomp (MPFEFindGame.h)
//
// Size: 0x10 bytes (extends DialogBoxBase)

#include "DialogBoxBase.h"

struct MPFEFindGame : public DialogBoxBase {
    void Init(uint32_t param_1, uint32_t param_2, DialogBoxCallback callback) override;
    void Destroy() override;
};
static_assert(sizeof(MPFEFindGame) == 0x10, "MPFEFindGame size mismatch");
