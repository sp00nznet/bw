#pragma once
// EditorIconBase — editor icon UI base class
// Struct layout from bw1-decomp (EditorIconBase.h)
//
// Size: 0x4 bytes (own vtable hierarchy, NOT Base-derived)
// Vtable: 17 entries

#include <cstdint>
#include "types.h"

struct LHRegion;

struct EditorIconBase {
    virtual LHRegion*  GetRegion();                                    // vtable[0]
    virtual uint32_t   Process();                                      // vtable[1]
    virtual void       Draw(int param_1);                              // vtable[2]
    virtual bool       IsActive();                                     // vtable[3]
    virtual uint32_t   DrawTextString(LH3DColor* color, LHRegion* region);  // vtable[4]
    virtual LHRegion*  GetPDMRegion();                                 // vtable[5]
    virtual LHRegion*  GetTextRegion();                                // vtable[6]
    virtual uintptr_t  GetTextHandle();                                // vtable[7]
    virtual float      GetTextHeight();                                // vtable[8]
    virtual LH3DColor* GetTextColor();                                 // vtable[9]
    virtual LH3DColor* GetActiveColor();                               // vtable[10]
    virtual LH3DColor* GetInactiveColor();                             // vtable[11]
    virtual LH3DColor* GetHiliteColor();                               // vtable[12]
    virtual char*      GetText();                                      // vtable[13]
    virtual bool       IsScrollable();                                 // vtable[14]
    virtual void       DrawBox(int param_1);                           // vtable[15]
    virtual void       DrawBubbleBox();                                // vtable[16]
};
static_assert(sizeof(EditorIconBase) == 0x4, "EditorIconBase size mismatch");
