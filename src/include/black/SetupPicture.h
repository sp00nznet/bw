#pragma once
// SetupPicture — picture/image display widget (extends SetupButton)
// Size: 0x294 bytes

#include "SetupButton.h"
#include "Zoomer.h"
#include "types.h"

struct LH3DMaterial;

struct SetupPicture : public SetupButton {
    int           hovered_picture_index;  // 0x244
    Zoomer        zoomer;                 // 0x248
    LH3DMaterial* material;               // 0x278
    LH3DColor     tint;                   // 0x27C
    bool          draggable;              // 0x280
    bool          dragging;               // 0x281
    int           picture_index;          // 0x284
    int           num_rows;               // 0x288
    int           num_pictures;           // 0x28C
    bool          clickable;              // 0x290
};
static_assert(sizeof(SetupPicture) == 0x294, "SetupPicture size mismatch");
