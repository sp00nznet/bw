// miracles — the viewer's hand drawing gestures and casting miracles, on the
// core recognizer (black/Gesture.h) and caster (black/SpellCast.h).
// Hold the middle mouse button to draw; a spiral then a spell's gesture
// picks a miracle; a left click casts it under the hand. docs/gestures.md.
#pragma once

#include <string>

namespace level { struct World; }

namespace miracles {

bool Init(const std::string& data_dir);     // loads Gestures.jty
void StrokeBegin();
void StrokePoint(float sx, float sy);
void StrokeEnd(float screen_ratio);         // recognise; begin / advance a selection
bool Holding();                             // a miracle is in the hand
// Cast the held miracle at (x, z) metres. Returns what happened, for the HUD.
std::string Cast(level::World& w, float x, float z);
std::string Status();                       // a line for the HUD

}  // namespace miracles
