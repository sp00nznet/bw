// SubArgument — creature script sub-action arguments
// Method stubs (bodies come from Ghidra decompilation)

#include "black/SubArgument.h"

// --- SubArgument base ---

void SubArgument::SetArgumentOfSubActionAgenda(CreatureSubActionAgenda* /*param_1*/, uint32_t /*param_2*/) {
}

uint32_t SubArgument::HasDestination() {
    return 0;
}

LHPoint* SubArgument::GetDestination() {
    return nullptr;
}

Object* SubArgument::GetObject() {
    return nullptr;
}

// --- SubArgumentInteger ---

// win1.41 004ff6f0 SubArgumentInteger::SetArgumentOfSubActionAgenda(CreatureSubActionAgenda *, unsigned long)
void SubArgumentInteger::SetArgumentOfSubActionAgenda(CreatureSubActionAgenda* /*param_1*/, uint32_t /*param_2*/) {
}

// --- SubArgumentObjectAndInteger ---

// win1.41 004ff6d0 SubArgumentObjectAndInteger::SetArgumentOfSubActionAgenda(CreatureSubActionAgenda *, unsigned long)
void SubArgumentObjectAndInteger::SetArgumentOfSubActionAgenda(CreatureSubActionAgenda* /*param_1*/, uint32_t /*param_2*/) {
}

// win1.41 0047c880 SubArgumentObjectAndInteger::HasDestination(void)
uint32_t SubArgumentObjectAndInteger::HasDestination() {
    return 0;
}

// win1.41 0047c890 SubArgumentObjectAndInteger::GetDestination(void)
LHPoint* SubArgumentObjectAndInteger::GetDestination() {
    return nullptr;
}

// --- SubArgumentPoint ---

// win1.41 004ff780 SubArgumentPoint::SetArgumentOfSubActionAgenda(CreatureSubActionAgenda *, unsigned long)
void SubArgumentPoint::SetArgumentOfSubActionAgenda(CreatureSubActionAgenda* /*param_1*/, uint32_t /*param_2*/) {
}

// win1.41 004791c0 SubArgumentPoint::HasDestination(void)
uint32_t SubArgumentPoint::HasDestination() {
    return 0;
}

// win1.41 004791d0 SubArgumentPoint::GetDestination(void)
LHPoint* SubArgumentPoint::GetDestination() {
    return nullptr;
}

// win1.41 004791b0 SubArgumentPoint::GetObject(void)
Object* SubArgumentPoint::GetObject() {
    return nullptr;
}
