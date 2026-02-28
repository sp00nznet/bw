#include "black/DialogBoxBase.h"

void DialogBoxBase::Init(uint32_t param_1, uint32_t param_2, DialogBoxCallback callback) {}
void DialogBoxBase::Destroy() {}
void DialogBoxBase::InitSubDialogs() {}
void DialogBoxBase::Show() {}
void DialogBoxBase::CloseNotification() {}
bool DialogBoxBase::WantsKeyControl() { return false; }
bool DialogBoxBase::WantsMouseControl() { return false; }
bool DialogBoxBase::CanESCOut() { return false; }
void DialogBoxBase::InitControls() {}
