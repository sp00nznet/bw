# Players

v1.0's player is a 632-byte record. GGame holds eight of them from +24
(`sub_523640`: `game + 24 + 632 * i`, nullptr from 8).

## The layout

The vendor header (v1.41) is 0xA60 bytes. v1.0 is the same layout without the
0x828 bytes v1.41 has at 0xB8. The constructor (`sub_5F6EF0`), `Init`
(`sub_5F71B0`) and their readers place these fields:

| Offset | Field | Evidence |
|---|---|---|
| +0x14 | interfaces, by interface index | `Init` writes `this[5 + index]` |
| +0x60 | GAlignment* | the constructor allocates a 16-byte GAlignment |
| +0xB5 | player number | `Init` |
| +0xF8 | type | `Init`; `sub_523530` stops at type 3 |
| +0xFC | name (wide) | `Init` copies it |
| +0x15C | a 508-byte object | `Init` makes it (`sub_602310`); LOAD_CREATURE needs it |
| +0x25C | GameStats (4392 bytes) | `Init`, `sub_534440` |
| +0x260 | citadel | the mimic hub measures from it |
| +0x264 | creature | LOAD_CREATURE, LOAD_MY_CREATURE, the creature-mind save |

`static_assert`s pin the size and offsets (`black/Player.h`). The rest of GGame
is still v1.41's; a pad keeps its offsets.

## Types

| Type | Meaning | Evidence |
|---|---|---|
| 0 | unused | `sub_523160` inits empty slots as "Player[%d]" |
| 1 | human | `sub_5F7130` |
| 2 | computer | inferred: the mimic hub (`sub_4CB260`) excludes it |
| 3 | neutral | player 7; iteration stops there |

## In core

GGame is never built, so the eight players live in `Player.cpp`:
- `PlayerAt(i)` returns one; `ResetPlayers()` is a single-player start, run by
  `level::Load`. Player 0 is human, 1-6 unused, 7 neutral.
- Towns get the player their CREATE_TOWN names.
- A script's player number is 1-based, and 0 means the local player
  (`sub_6862D0`; `ScriptPlayer`).
- LOAD_CREATURE gives the creature to its player (`SetPlayerCreature`: player +612,
  creature +0x1070).
- LOAD_MY_CREATURE makes one for player 0 only if it has none (`sub_525210`).
- In the viewer, the first creature made with C is player 0's.
- A creature with a player sees its player's hand (`CreatureBrain::player_hand`, the
  mouse on the land), so PointAtHand runs.

**Not yet:**
- player processing (`GPlayer::Process`): towns are still run by `level::Process`;
- interfaces, the +0x15C object, GameStats and the citadel;
- the creature-mind and physique files named by the player's profile.
