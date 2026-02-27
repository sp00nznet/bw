#pragma once
#include "GSingleMapFixedInfo.h"
struct GScriptHighlightInfo : public GSingleMapFixedInfo {};
static_assert(sizeof(GScriptHighlightInfo) == 0x100, "GScriptHighlightInfo size mismatch");
