#pragma once
// SubArgument — creature script sub-action argument base
// Struct layout from bw1-decomp (SubArgument.h, CreatureScript.h)
//
// Size: 0x4 bytes (own vtable hierarchy, NOT Base-derived)
// Vtable: 4 entries (SetArgumentOfSubActionAgenda, HasDestination, GetDestination, GetObject)
//
// Also defines: SubArgumentInteger, SubArgumentObjectAndInteger, SubArgumentPoint (all 0x4)

#include <cstdint>

struct CreatureSubActionAgenda;
struct LHPoint;
struct Object;

struct SubArgument {
    virtual void     SetArgumentOfSubActionAgenda(CreatureSubActionAgenda* param_1, uint32_t param_2);  // vtable[0]
    virtual uint32_t HasDestination();                                                                   // vtable[1]
    virtual LHPoint* GetDestination();                                                                   // vtable[2]
    virtual Object*  GetObject();                                                                        // vtable[3]
};
static_assert(sizeof(SubArgument) == 0x4, "SubArgument size mismatch");

struct SubArgumentInteger : public SubArgument {
    void SetArgumentOfSubActionAgenda(CreatureSubActionAgenda* param_1, uint32_t param_2) override;
};
static_assert(sizeof(SubArgumentInteger) == 0x4, "SubArgumentInteger size mismatch");

struct SubArgumentObjectAndInteger : public SubArgument {
    void     SetArgumentOfSubActionAgenda(CreatureSubActionAgenda* param_1, uint32_t param_2) override;
    uint32_t HasDestination() override;
    LHPoint* GetDestination() override;
};
static_assert(sizeof(SubArgumentObjectAndInteger) == 0x4, "SubArgumentObjectAndInteger size mismatch");

struct SubArgumentPoint : public SubArgument {
    void     SetArgumentOfSubActionAgenda(CreatureSubActionAgenda* param_1, uint32_t param_2) override;
    uint32_t HasDestination() override;
    LHPoint* GetDestination() override;
    Object*  GetObject() override;
};
static_assert(sizeof(SubArgumentPoint) == 0x4, "SubArgumentPoint size mismatch");
