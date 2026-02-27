#pragma once

// DrawingObject — abstract base with own vtable (pure virtual)
// NOT derived from Base
struct DrawingObject {
    virtual ~DrawingObject() = 0;
};
static_assert(sizeof(DrawingObject) == 0x4, "DrawingObject size mismatch");
