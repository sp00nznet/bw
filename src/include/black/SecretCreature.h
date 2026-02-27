#pragma once
// SecretCreature — secret/hidden creature marker
// Struct layout from bw1-decomp (SecretCreature.h)
//
// Size: 0x4 bytes (own vtable hierarchy, NOT Base-derived)
// Vtable: 1 entry (destructor only)

struct SecretCreature {
    virtual ~SecretCreature() = default;
};
static_assert(sizeof(SecretCreature) == 0x4, "SecretCreature size mismatch");
