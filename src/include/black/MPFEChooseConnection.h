#pragma once
// MPFEChooseConnection — connection type selection dialog
// Struct layout from bw1-decomp (MPFEChooseConnection.h)
//
// Size: 0x10 bytes (extends DialogBoxBase)

#include "DialogBoxBase.h"

struct MPFEChooseConnection : public DialogBoxBase {
    void Destroy() override;
};
static_assert(sizeof(MPFEChooseConnection) == 0x10, "MPFEChooseConnection size mismatch");
