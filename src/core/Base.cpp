// Base class implementation
// Decompiled from Black & White v1.0 (runblack_decrypted.exe)
// Cross-referenced with bw1-decomp (v1.20)

#include <black/Base.h>

// Original addresses (v1.0):
//   Serialise:                0x004017c0
//   Delete:                   0x004010e0
//   ToBeDeleted:              0x004010f0
//   Get3DSoundPos:            0x00403c20
//   CleanUpForSerialisation:  0x004017f0
//   Dump:                     0x004017f0 (same as CleanUpForSerialisation - empty)

void Base::Serialise(Archive& /*archive*/) {
    // Empty in base class — derived classes override
}

Base::~Base() {
    // Destructor calls operator delete if allocated on heap
    // Original assembly: pushes flag, calls delete if needed
}

void Base::Delete(int /*param*/) {
    if (this) {
        // Calls destructor through vtable: this->vftable->__dt(this, 1)
        delete this;
    }
}

void Base::ToBeDeleted(int param) {
    // Calls Delete through vtable
    Delete(param);
}

int Base::Get3DSoundPos(LHPoint* /*pos*/) {
    return 0;
}

void Base::CleanUpForSerialisation() {
    // Empty in base class
}

void Base::Dump() {
    // Empty in base class
}
