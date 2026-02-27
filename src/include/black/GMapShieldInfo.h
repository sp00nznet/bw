#pragma once
#include "GSingleMapFixedInfo.h"
struct GMapShieldInfo : public GSingleMapFixedInfo {};
static_assert(sizeof(GMapShieldInfo) == 0x100, "GMapShieldInfo size mismatch");
