#pragma once
// Prss — process/screen base class (from lh3dlib)
// Struct layout from bw1-decomp (Prss.h)
//
// Size: 0x10 bytes (own vtable hierarchy, NOT Base-derived)
// Vtable: 7 entries (ProcessTurn, Display, Terminate, PrssKey, PrssMouse, ClickFunction, StringFunction)

#include <cstdint>

// Forward declarations
struct MouseInput;
enum LH_KEY : uint32_t;

struct Prss {
    virtual int  ProcessTurn();                                             // vtable[0]
    virtual void Display();                                                 // vtable[1]
    virtual void Terminate();                                               // vtable[2]
    virtual void PrssKey(LH_KEY key, uint16_t param_2);                    // vtable[3]
    virtual void PrssMouse(MouseInput* param_1);                           // vtable[4]
    virtual void ClickFunction(int param_1, int param_2, int param_3);     // vtable[5]
    virtual void StringFunction(int param_1, char* param_2, int param_3);  // vtable[6]

    uint32_t field_0x4;   // 0x04
    uint32_t field_0x8;   // 0x08
    uint32_t field_0xc;   // 0x0C
};
static_assert(sizeof(Prss) == 0x10, "Prss size mismatch");
