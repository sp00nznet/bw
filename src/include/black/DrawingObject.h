#pragma once

// DrawingObject — abstract base with own vtable (pure virtual)
// NOT derived from Base
// Vendor: vtable[0] is AddDrawing (overridden in VillagerName, etc.)
struct DrawingObject {
    virtual void AddDrawing() = 0;
};
static_assert(sizeof(DrawingObject) == 0x4, "DrawingObject size mismatch");
