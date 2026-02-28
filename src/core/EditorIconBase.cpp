#include "black/EditorIconBase.h"

LHRegion*  EditorIconBase::GetRegion() { return nullptr; }
uint32_t   EditorIconBase::Process() { return 0; }
void       EditorIconBase::Draw(int param_1) {}
bool       EditorIconBase::IsActive() { return false; }
uint32_t   EditorIconBase::DrawTextString(LH3DColor* color, LHRegion* region) { return 0; }
LHRegion*  EditorIconBase::GetPDMRegion() { return nullptr; }
LHRegion*  EditorIconBase::GetTextRegion() { return nullptr; }
uintptr_t  EditorIconBase::GetTextHandle() { return 0; }
float      EditorIconBase::GetTextHeight() { return 0.0f; }
LH3DColor* EditorIconBase::GetTextColor() { return nullptr; }
LH3DColor* EditorIconBase::GetActiveColor() { return nullptr; }
LH3DColor* EditorIconBase::GetInactiveColor() { return nullptr; }
LH3DColor* EditorIconBase::GetHiliteColor() { return nullptr; }
char*      EditorIconBase::GetText() { return nullptr; }
bool       EditorIconBase::IsScrollable() { return false; }
void       EditorIconBase::DrawBox(int param_1) {}
void       EditorIconBase::DrawBubbleBox() {}
