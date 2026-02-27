// HandState — hand interaction state machine
// Method stubs (bodies come from Ghidra decompilation)

#include "black/HandState.h"

// --- HandState base ---

// win1.41 inlined HandState::Enter(void)
void HandState::Enter() {
}

// win1.41 0046e5e0 HandState::DrawTheHeldObject(void)
void HandState::DrawTheHeldObject() {
}

// win1.41 005b02d0 HandState::Exit(void)
void HandState::Exit() {
}

// win1.41 inlined HandState::Update(float, LHMatrix *)
void HandState::Update(float /*param_1*/, LHMatrix* /*param_2*/) {
}

// win1.41 0046be80 HandState::AllowCameraTricons(void)
bool HandState::AllowCameraTricons() {
    return false;
}

// --- HandStateInvisible ---

// win1.41 0046be90 HandStateInvisible::Enter(void)
void HandStateInvisible::Enter() {
}

// win1.41 0046bed0 HandStateInvisible::Exit(void)
void HandStateInvisible::Exit() {
}

// win1.41 0046bee0 HandStateInvisible::Update(float, LHMatrix *)
void HandStateInvisible::Update(float /*param_1*/, LHMatrix* /*param_2*/) {
}

// --- HandStateNormal ---

// win1.41 005b5d00 HandStateNormal::Enter(void)
void HandStateNormal::Enter() {
}

// win1.41 005b71a0 HandStateNormal::Update(float, LHMatrix *)
void HandStateNormal::Update(float /*param_1*/, LHMatrix* /*param_2*/) {
}

// --- HandStateCamera ---

// win1.41 005b02f0 HandStateCamera::Enter(void)
void HandStateCamera::Enter() {
}

// --- HandStateTug ---

// win1.41 005b7df0 HandStateTug::Enter(void)
void HandStateTug::Enter() {
}

// win1.41 005b8e40 HandStateTug::DrawTheHeldObject(void)
void HandStateTug::DrawTheHeldObject() {
}

// win1.41 005b8070 HandStateTug::Update(float, LHMatrix *)
void HandStateTug::Update(float /*param_1*/, LHMatrix* /*param_2*/) {
}

// --- HandStateTotem ---

// win1.41 005b7690 HandStateTotem::Enter(void)
void HandStateTotem::Enter() {
}

// win1.41 005b7790 HandStateTotem::Exit(void)
void HandStateTotem::Exit() {
}

// win1.41 005b77a0 HandStateTotem::Update(float, LHMatrix *)
void HandStateTotem::Update(float /*param_1*/, LHMatrix* /*param_2*/) {
}

// --- HandStateCreature ---

// win1.41 005b13f0 HandStateCreature::Enter(void)
void HandStateCreature::Enter() {
}

// --- HandStatePlayAnim ---

// win1.41 005b7510 HandStatePlayAnim::Enter(void)
void HandStatePlayAnim::Enter() {
}

// win1.41 005b7520 HandStatePlayAnim::Update(float, LHMatrix *)
void HandStatePlayAnim::Update(float /*param_1*/, LHMatrix* /*param_2*/) {
}

// --- HandStateCitadel ---

// win1.41 005b0c10 HandStateCitadel::Enter(void)
void HandStateCitadel::Enter() {
}

// win1.41 005b0d00 HandStateCitadel::Update(float, LHMatrix *)
void HandStateCitadel::Update(float /*param_1*/, LHMatrix* /*param_2*/) {
}
