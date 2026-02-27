#pragma once

// Persistent — serialization base with own vtable (NOT Base-derived)
// Size: 0x4, vtable: 4 virtual methods
struct Persistent {
    virtual void VirtualFunc();
    virtual void OnLoaded();
    virtual ~Persistent();
    virtual void DefineProperties(void* list);
};
static_assert(sizeof(Persistent) == 0x4, "Persistent size mismatch");

// FloatProvider — extends Persistent
struct FloatProvider : public Persistent {};
static_assert(sizeof(FloatProvider) == 0x4, "FloatProvider size mismatch");
