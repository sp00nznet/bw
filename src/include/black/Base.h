#pragma once
// Base — root class of all game objects
// Struct layout from bw1-decomp, implementations from v1.0 decompilation
//
// Size: 0x8 bytes
// Vtable: 7 entries (0x1C bytes)

#include <cstdint>

struct Archive;
struct BaseInfo;

struct Base {
    // === Vtable (7 virtual functions) ===
    virtual void Serialise(Archive& archive);
    virtual ~Base();
    virtual void Delete(int param);
    virtual void ToBeDeleted(int param);
    virtual int Get3DSoundPos(struct LHPoint* pos);
    virtual void CleanUpForSerialisation();
    virtual void Dump();

    // === Fields ===
    uint32_t destroyed;  // 0x4

    // === Static methods ===
    static void* operator new(size_t size);
    static void operator delete(void* ptr, size_t size);

    // === Non-virtual methods ===
    void SetInfo(BaseInfo* info) const;
};
static_assert(sizeof(Base) == 0x8, "Base size mismatch");
