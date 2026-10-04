# Villager states

How v1.0 runs a villager each turn, and how much of it is translated
(`src/core/VillagerStates.cpp`).

## The tick

`Living::ProcessAll` (`sub_5AB2E0`) walks the game's global living list. For each
living thing it saves the position as the previous one, then calls its vslot 392. A
villager's vslot 392 is `sub_6E01E0`:

- count the turn in its state (+0x90)
- call the current state's function from a 255-entry table at `0xC2A2C8`, indexed by
  the state byte at +0x8C (also, for both state bytes, the slot at +0x80)
- run the per-turn upkeep (`sub_6E05D0`: hunger, life, the state's own effects from
  `DETAIL_VILLAGER_STATE_TABLE_INFO`) or, when the +0xE0 bit 11 says so, a timed
  transition

`Object::Process` returns 0 for villagers, and nothing called `ProcessState`, so until
this change **villagers never ran**. `level::Process` now runs the living pass after the
towns.

## The state table

The table is `.bss`, filled by a 62 KB inlined initialiser at `0x560EB0` that IDA never
made a function. `work/emulate_init.py` rebuilds it, 9,180 dwords = 255 states × 36. Every
state has a process function at +0, plus up to eight more slots. The numbers agree with
chlasm's `GStates.h` (CC0): 16 Drowning, 85 Created, 119 GotoBedAtHome, 163
DecideWhatToDo, 245 GoAndChilloutOutsideHome. That is now our `VILLAGER_STATES`. The
47-entry enum it replaced numbered states as in v1.41 (it put DECIDE_WHAT_TO_DO at 85).
Names read from `info.dat`'s state table came out off by one around 117–119; chlasm's
are the ones the code agrees with.

## Translated so far

| State | v1.0 | What it does |
|---|---|---|
| 1 MoveToPos | `sub_5AAE80` | walk to the goal, then enter the destination state |
| 85 Created | `sub_6E38B0` | wait out the timer, then DecideWhatToDo |
| 163 DecideWhatToDo | vslot 561, `sub_6E1260` | see below |
| 36 GoHome / 121 WakeUpAtHome | `sub_6EEF60(37, 238)` | to the home; without one, somewhere near town to lie down; without a town, VagrantStart |
| 37 ArrivesHome | `sub_6EF610` | go inside (+0xE0 bit 2), AtHome |
| 38 AtHome | `sub_6EEBE0` | sleep or eat if pressing; else find something; one time in four go to bed, else out |
| 119 GotoBedAtHome | `sub_6EF800` | asleep for villager info +588 turns |
| 120 SleepingAtHome | `sub_6EFA40` | wake when rested (life ≥ info +864), else sleep on |
| 245 GoAndChilloutOutsideHome | `sub_6F9400` | to a spot outside home |
| 246 SitAndChillout | `sub_6F94F0` | sit for info +918 turns, then look for something, 1 in 10 wander off |

**DecideWhatToDo, in v1.0's order:**

1. After a recent town emergency, congregate (242).
2. A homeless villager moves into the town's best abode with space (`sub_6EFE70`).
3. **Work from the town's desires** (`TownDesire::FindWorkForVillager`, `sub_6D7D30`).
   The desires are offered in rank order. A desire is taken when its total, scaled by
   how few villagers just joined it, beats its info threshold plus how busy the
   villager is (`sub_6E76E0`). One quirk is kept: the original indexes the "villagers on
   it" arrays by rank, not desire.
4. Sleep or eat, whichever presses harder (`sub_6EED70`).
5. Carrying too much: go to the storage pit (31).
6. Otherwise a random way to pass the time (`sub_6E3630`).

**The game's random generator** is translated too (`LHRandom.h`, `sub_746D10`:
`seed = ror32(9377 × seed + 9439, 13)`). Every random choice above draws from it.

Land 1, 2,000 turns: villagers leave Created, decide, walk home, go inside, go to bed
and sleep, chill outside, and sit around town. 24 have neither home nor town and become
vagrants (130).

## Not yet

- **Movement is a straight line.** v1.0's path code (`sub_5C5BA0`, 625 lines of wall
  hugging over map cells and footpaths) belongs with the landscape work.
- **The upkeep** (`sub_6E05D0`). Without it hunger and tiredness don't change, so
  villagers never get hungry or tired on their own.
- **Eating** (`sub_6EA9F0`), **all the work handlers** (food, wood, building, repair,
  worship), Relaxation's handler (it needs the town's relax spots), the disciple and
  child deciders, and `SetState`'s exit/enter slots and pause diversion.
- **The random seed's starting value**: the game sets it at runtime, and we have not
  recovered it.
- Untranslated states hold, then fall back to DecideWhatToDo after 300 turns, so no
  villager is stranded.
