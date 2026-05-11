// save_state — slot-based binary snapshot of the viewer game state.
//
// This is a host-level save, not the original BW save format. It captures
// enough state (entity positions/life/scale, game turn, hand state, LHVM
// globals, side-tables exposed by LHVMObjects) to resume a session. The
// proper BW format will land alongside full GameOSFile support.
//
// Format:
//   magic   "BWSV"   (4 bytes)
//   version u32      (currently 1)
//   sections, each: tag(4) + size(u32) + payload(size bytes)
//   tags: GTRN (game turn), ENTS (entity array), HAND (hand state),
//         LGLB (LHVM global vars), LINF (influence sources)

#pragma once

#include <cstdint>
#include <string>

namespace bw {

struct GameState;

namespace savestate {

// Returns true on success. Slot 0..15 → saves/slot_NN.bws in the working dir.
bool Save(int slot, const GameState& gs);
bool Load(int slot, GameState& gs);

// Returns the on-disk path for a given slot (no I/O).
std::string PathFor(int slot);

// Wire SAVE_GAME_IN_SLOT to actually serialize.
void RegisterLHVMHook(GameState* gs);

} // namespace savestate
} // namespace bw
