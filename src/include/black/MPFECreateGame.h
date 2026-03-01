#pragma once
// MPFECreateGame — game creation dialog
// Struct layout from bw1-decomp (MPFECreateGame.h)
//
// Size: 0x10 bytes (extends DialogBoxBase)

#include "DialogBoxBase.h"

struct MPFECreateGame : public DialogBoxBase {
    void Init(uint32_t param_1, uint32_t param_2, DialogBoxCallback callback) override;
    void Destroy() override;
};
static_assert(sizeof(MPFECreateGame) == 0x10, "MPFECreateGame size mismatch");
