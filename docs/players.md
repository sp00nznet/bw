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
- BUILD_BUILDING takes a plan within 10 m of its centre. v1.0 measures to the plan's
  edge.

## Worship sites

When the heart is finished, CitadelHeart::Built (`sub_4503D0`) does this:

1. It runs MultiMapFixed::Built and sets scale 1.
2. It takes the heart's site off every town of the player (`sub_6CEC00`).
3. It calls `sub_450320`. A heart made already built (`sub_450280`, built ≥ 1) calls
   it straight away.

`sub_450320` walks the player's towns. For each one, the citadel finds the worship site
for the town's tribe, or makes it (`sub_44EA80` → `sub_44EA50` / `sub_44EBE0`).

That is skipped when:
- the citadel's worship is off (+0x74);
- the town has no people;
- the town's worship is disabled (+0x5F0, `sub_6D3500`).

The town joins the site's town list (+0xA4, `sub_705750`), and the town's worship site
(+0x984) is set (`sub_6CFF60`). An unbuilt worship site gets a site on the town's list,
with priority 0.

A worship site (`sub_703DB0` → `sub_703AC0`, 296 bytes) is a CitadelPart:
- It stands at the citadel, 0% built.
- Its record is WORSHIP_SITE_INFO[tribe] (352 bytes), and its tribe is
  TRIBE_INFO[tribe] (28 bytes, at +0x8C).
- It takes one of the citadel's six slots (+0x34; its slot byte is at +0x110). The slot
  is the free one whose place is nearest the tribe's nearest town. That place is the
  heart mesh's point 9, turned by heart angle + slot × 2π/7.

CitadelPart's GetPlayer (`sub_454840`, the citadel's player), IsBuilt (`sub_44FFB0`) and
IsRepaired (life ≥ 1) were stubs and are now translated.

In `test_level`, finishing Land 1's heart gives town 0 (tribe 7) its worship site in
slot 0. Town 0's villagers build it to 100% in 1,000 turns.

**Ours:**
- With no meshes in core, every slot's place is the heart's own position, which is what
  v1.0 uses when the mesh has no point 9. The first free slot is taken.
- Not translated:
  - the totem (`sub_708CF0`);
  - spell icons (`sub_704040`, `sub_705860`);
  - the footpath to each town (`sub_6D3BE0`);
  - the towns' worship distance (`sub_6CE140`);
  - the local player's sound and help.

## Worship and mana

A town's worship percentage (+0x5C0) is set by the town centre's totem. Scripts set it
with SET_PROPERTY 19 on the town centre (`sub_6A7D30` → `sub_6CF1C0`). It is kept only
while the town has a worship site.

**How many worship.** The town wants its people × percentage, at least one, plus the
site's extra (+0x124). Worshippers (+0x5C4) and walkers (+0x5CC) count against that
(`sub_6CF9C0`).

**The villagers.** They walk to the site and dance there; see docs/villager-states.md.
The site keeps them on a list (+0xD4, counted at +0xC8). Its Dance (`sub_4E9DC0`, 300
bytes) counts the dancers (+0x90).

**The mana.** Each turn, every player's citadel runs its worship sites (`sub_5F8410` →
`sub_44EFB0`, in the magic pass `sub_6B7570`). For each site (`sub_704610` →
`sub_7047E0`):
- The dancers make dancers × site info +324 × player +0x70 (`sub_706C40`).
- The player's nine multipliers at +0x68, and nine more at +0xB8, start at 1
  (`sub_5F7360`).
- What is made is kept at an efficiency of 0.5 − mana / most / 2, at least 0.2 while
  positive, plus the share the spell icons took, at most 1. "Most" is dancers × info +340
  + info +336.
- The site's mana (+0xF0) gains what is kept, less what the icons took (+0xFC).
- The rate per dancer (+0x104) is what tires them.

GET_MANA (`sub_698410`, native 422) reads +0xF0 off a worship site; SET_MANA
(`sub_698350`, native 355) writes it.

In `test_level`, Land 1's town 0 sets 25% to worship (7 of 26 people). All 7 walk 141 m to
the temple and dance there. The site holds 5,745 mana after 2,500 turns. With worship
off, they all go home and the mana stays.

The v1.0 native table is built inline at 0x69B000. Each entry is 144 bytes, from
0xB358E0, with native 130 BUILD_BUILDING first in that run. Scanning its
`mov [entry], offset fn` stores gives every native's function.

**Ours:**
- The Dance's groups and paths are not built. Every dancer is taken and stands within
  5 m of the site, and the member count is recounted each turn from the site's
  worshippers in state 60.
- Not translated:
  - the totem's look and calling worshippers in (`sub_6CF250`);
  - food at the site (241);
  - the creature that brings far villagers (`sub_6F9B70`);
  - the worship disciples;
  - the 1000-turn pass at +0xAC;
  - the citadel's share (`sub_44EEE0`).
- SET_MANA on a town is not supported; towns are not script handles here.

## Spell icons and charging

**A town's magic.** A town holds magic types (+0xDF4, one int each of 42).
`sub_6D0200` adds one, and the town's player gains it (`sub_5F94A0`: count at +0x188,
enabled at +0x230). It comes from:
- the level: CREATE_TOWN_SPELL and CREATE_TOWN_CENTRE_SPELL_ICON (cases 10 and 12) name a
  seed; CREATE_NEW_TOWN_SPELL (case 11) names a magic, and its seed's base comes with it;
- scripts: SET_MAGIC_IN_OBJECT (native 386).

Land 1 grants none at load. Land 2 gives town 1 Fire, Nature, Food and Wood, and town 2
Heal.

**The records.** A seed is DETAIL_SPELL_SEEDS (30 × 400 bytes). Its name is at +24, its
base magic at +292, and its power-ups at +296..+304. A magic's cost is its
DETAIL_MAGIC_EFFECT_INFO record +120, and its name is at +52 (Fire 3,500, Food 7,000).

**Icons.** A seed's base magic gets a WorshipSpellIcon at the town's worship site
(`sub_705930` → `sub_7077C0`, 320 bytes). This happens through the town centre's icons
(`sub_6D6180`). The site keeps them at +0xE0, counted at +0xE4, with next at icon +0x110.
A site joining a town takes the town's spells (`sub_705860`).

**Charging.**
1. A miracle picked by gesture asks the player's worship sites for its seed
   (`sub_5F9050`). The icon whose site has the most mana to give starts charging
   (`sub_708040` → `sub_707F00`): +0x120 set, the power-up at +0x124, and the charger at
   +0x128. That needs the player to hold the magic (`sub_5F93C0`) and the site to have
   mana.
2. Each turn the site splits what it has among its charging icons (`sub_704610`). Each
   icon's full want is spent (`sub_705BA0` → `sub_704C80`: wanted +0x100, taken +0xFC).
3. Full (`sub_7078A0`), the icon's charge (+0x134) goes to a human charger's hand as the
   seed (`sub_707DF0` → `sub_6BED50`).

In `test_level`, town 0 is given Food, and its icon appears at the worship site. Charging
it for player 0 fills 7,000 from 5,745 stored mana plus worship in 1,142 turns. The hand
then holds Food. In the viewer, once the player has a temple:
- the gesture menu offers only the miracles whose icons stand at its worship sites
  (`sub_58F9C0`);
- a picked miracle charges at the temple before it can be cast.

**Ours:**
- The town centre's own icons (TownCentreSpellIcon) and the town's icon list (+0x770) are
  not built. The worship site's icons come straight from the town's magic.
- Not translated:
  - power-up upgrades (`sub_6D6140`);
  - icon slots and looks;
  - a seed already in the hand topping up (`sub_7081E0`);
  - the refresh countdown.
- The hand's seed is a host record (`HeldSeed`), not a SpellSeed object.
- SET_MAGIC_IN_OBJECT still does nothing; towns are not script handles.

## The hand: taking things to buildings

A player's hand status is its GInterface's GInterfaceStatus (0x134 bytes, also in v1.0).
Its player is GGame's player by its number (+0x28, `sub_59BCA0`).

**Picking up** (`sub_59C390`): the object goes to +0x120. +0x128 records the player with
the most influence where it was picked up (`sub_5BFD00` → `sub_58E1E0`, else the local
player). The v1.41-based header had these two named `last_dropped_object` and
`leash_status`.

**Letting go over a building** calls its DeleteObjectAndTakeResource (vslot 417):

| Class | v1.0 | Takes it when |
|---|---|---|
| MultiMapFixed (abodes, fields) | `sub_505610` | it has a site under way (+0x74) |
| StoragePit | `sub_6C9840` | always |
| WorshipSite | `sub_7071B0` | always |
| Workshop, Pot, piles | `sub_617A00` | always |

Taking (`sub_5ECB70`): the object's resource type and all it holds go to the building's
AddResource. If that took any, the building's DoCreatureMimicAfterAddingResource
(vslot 419) lets the player's creature see it. Then the object is removed.

| Class | v1.0 | Mimic row |
|---|---|---|
| any, under construction | `sub_5053E0` | wood: 7 Put wood in building site |
| StoragePit | `sub_6C9900` | from the player's own land: food 2, wood 4; else food 43 or 44, wood 45 (theft) |
| WorshipSite | `sub_706BF0` | food: 0 Put food in worship site |
| Workshop | `sub_703880` | wood: 9 Put wood in workshop |

In `test_level`, player 0 picks up 100 wood in village 0 and lets go over its store. The
store goes 3,750 → 3,850, the pile is gone, and the creature on the learning leash takes
up row 4.

**Ours:**
- There is no influence map in core. The land's owner is the player of the nearest town
  whose radius holds the point, else player 0.
- The taken object is taken off the map and marked unavailable, not freed; the level's
  object list still holds it.
- Not translated:
  - the rest of the pick-up (a held living, hand states, multi-pick-up);
  - the local player's displays, sounds and tutorial cues;
  - Scaffold's own take (`sub_685A70`).
- The viewer's hand still moves its own entities and does not call this yet.

**Not yet:**
- player processing (`GPlayer::Process`): towns are still run by `level::Process`;
- interfaces, the +0x15C object, GameStats and the citadel;
- the creature-mind and physique files named by the player's profile.
