#include "black/ScriptHighlight.h"

// GameThing overrides
char*    ScriptHighlight::GetDebugText() { return "ScriptHighlight"; }
uint32_t ScriptHighlight::Load(GameOSFile* file) { return 0; }
uint32_t ScriptHighlight::Save(GameOSFile* file) { return 0; }
uint32_t ScriptHighlight::GetSaveType() { return 63; }

// GameThingWithPos overrides
bool32_t ScriptHighlight::IsScriptHighlight() { return 1; }
uint32_t ScriptHighlight::GetScriptObjectType() { return 0; }
bool32_t ScriptHighlight::CanBePickedUpByCreature(Creature*) { return 0; }

// Object overrides
uint32_t ScriptHighlight::Process() { return 0; }
void     ScriptHighlight::Draw() {}
void     ScriptHighlight::CallVirtualFunctionsForCreation(const MapCoords&) {}

// Static methods
void ScriptHighlight::ProcessHighlights() {
    // Original at 0x0070a460 — processes script highlight objects
}
