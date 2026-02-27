#pragma once

// Property — serialization property with own vtable (NOT Base-derived)
// Size: 0x4, vtable: 3 virtual methods
struct Property {
    virtual const char* GetAsString();
    virtual const char* GetAsUserReadableString();
    virtual uint32_t    ReadProperty(void* stream, void* streamer);
};
static_assert(sizeof(Property) == 0x4, "Property size mismatch");

struct BoolProperty : public Property {};
static_assert(sizeof(BoolProperty) == 0x4, "BoolProperty size mismatch");

struct SoundActionProperty : public Property {};
static_assert(sizeof(SoundActionProperty) == 0x4, "SoundActionProperty size mismatch");

struct StringProperty : public Property {};
static_assert(sizeof(StringProperty) == 0x4, "StringProperty size mismatch");

struct TPointerProperty : public Property {};
static_assert(sizeof(TPointerProperty) == 0x4, "TPointerProperty size mismatch");
