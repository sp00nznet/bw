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

## The citadel

Land 1's script plans the player's temple:
`CREATE_PLANNED_CITADEL(0, "1915.05,2508.89", 0, "PLAYER_ONE", 36000, 1000)`.

The loader's case 20 does this. It finds the town by id only (`sub_5256C0`) and checks
that the player exists (`sub_5F89B0`). It then makes a `PlannedTownCitadelHeart`
(`sub_4530C0`): 76 bytes, with its town at +0x48, put on the town's planned list. Its
record is CITADEL_HEART_INFO[0], "Citadel Heart": 6,500 wood and 100 builders wanted.

Nothing builds it until a script asks. The Land 1 opening (`FollowUs`) calls
BUILD_BUILDING at the plan's place with 1.0:

1. `sub_694840` pops the desire, then the position, and calls `sub_6D11E0`. That walks
   every town of every player and takes the planned building nearest the position
   (`sub_6D1140`).
2. `sub_6CEA80` starts it with vslot 321, which is `sub_453190` for the heart:
   - The town's player gets a Citadel (`sub_44E400`) if it has none. The Citadel is a
     Container, and the player's +608 points to it.
   - A CitadelHeart is made at the plan's place, angle and scale, 0% built
     (`sub_450280` → `sub_44FED0`). It becomes the citadel's heart (+0x30), and its
     town is kept at +0x94.
   - The plan is deleted.
3. The heart's site (vslot 309, `sub_453FF0`) joins the town's site list. The site's
   priority (+0x63C) is set to the desire × 5.

Towns join their player's list as they are made (`sub_6CDFF0` → `sub_5F9230`: tail of
+616, next at town +0x754).

In `test_level`, BUILD_BUILDING at Land 1's citadel makes player 0's citadel and heart.
At the end of the test's run, town 0's villagers have it 18% built after 3,000 turns,
with up to 11 builders.

The creature's "player has a temple" (player +608) now reads the citadel.

**Ours:**
- The site is a standard one; v1.0 uses a 1,628-byte CitadelBuildingSite
  (`sub_435870`).
- Not translated:
  - the land check (`sub_454760`);
  - the citadel's own init (`sub_44E610`);
  - its power base (`sub_44F720`);
  - the heart's entrance (`sub_450590`);
  - PostCreatePlanned (vslot 322);
  - what happens when the heart is finished (`sub_450320`).
- BUILD_BUILDING takes a plan within 10 m of its centre. v1.0 measures to the plan's
  edge.

**Not yet:**
- player processing (`GPlayer::Process`): towns are still run by `level::Process`;
- interfaces, the +0x15C object, GameStats and the citadel;
- the creature-mind and physique files named by the player's profile.
