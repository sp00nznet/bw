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
| 33 GotoStoragePitForFood | `sub_6F7880` | walk to the town's store |
| 34 ArrivesAtStoragePitForFood | `0x6F7900` | take what it wants to eat from the store, then decide |
| 117 EatFood | `0x6EAFF0` | eat what it carries, then decide |
| 118 EatFoodAtHome | `0x6EB080` | top up from home, eat, back to AtHome |
| 31 GotoStoragePit | `sub_6F7670` | take what it carries to the store |
| 32 ArrivesAtStoragePitForDropOff | `sub_6F7720` | put one kind of it into the store, then decide |
| 55 FishermanArrivesAtFishing | `sub_6EA660` | walk into the farm's cell, then fish |
| 56 Fishing | `sub_6EA730` | cast; a catch is a quarter load; full hands go to the store |
| 67 FarmerArrivesAtFarm | `sub_6E8EF0` | walk to a spot in the field; plant, or dig a full-grown crop |
| 68 FarmerPlantsCrop | `0x6E9090` | one more crop, then the next spot |
| 69 FarmerDigsUpCrop | `sub_6E9010` | dig food up; a full load goes to the store |
| 14 Dying | vslot 551, `sub_6F85B0` | on to Dead |
| 15 Dead | vslot 552 | holds (the body's removal is not translated) |

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

## The upkeep

After the state runs, `sub_6E05D0` runs the upkeep unless +0xE0 bit 11 asks for a
timed transition instead. Each state has a 276-byte element in
`DETAIL_VILLAGER_STATE_TABLE_INFO` (from `info.dat`), and the upkeep reads it:

- **Every turn**: the state's own life cost (element +0x108). A state that is a step on
  the way (+0x1C clear, e.g. walking) counts as the state it leads to (vslot 704).
- **In states that feel hunger** (+0xF4), once every villager info +732 turns:
  - **Old age** (`sub_6EF970`): staggered to about once every 800 turns. Past info
    +316 years a cubed random share of the years to +320 is added; past +320 the
    villager dies.
  - **Tired**: life below info +860, outside, in a state that allows it, sends it home.
  - **Growing up** (`sub_6E0EB0`): a child becomes an adult at info +312 years.
  - **The food drain** (`sub_6EACC0`): food falls by info +700 per turn, more when it
    hurries. Below info +704 the villager is hungry: it loses info +720 life per check
    and, where the state lets it, goes to eat (`sub_6EA9F0`). At no life it dies.

**Eating** (`sub_6EA9F0`) wants hunger x info +728 food (less in a well-off town). It
eats at home when home has enough, else walks to the town's storage pit, else eats
what it carries. A meal raises food by the share eaten x info +696.

**A year is 1,500 turns.** `dword_C22D44` is `GGameInfo` +0xC, and the constructor
(`sub_529080`) sets it to 1500 (and +0x10 to 36,000). Ages now count in years.

Land 1, 2,000 turns: mean food falls from 0.77 to 0.69, and 11 meals take 736 food
out of the village's pit.

## The food job

The Food desire's handler (`sub_6E9100`) ranks the town's food sources by pull x a
distance falloff, against taking what the villager already carries to the store
(how full its hands are x the store's falloff). The falloff (`sub_6DF670`) is a
sigmoid read from a 41-entry table at `0xB461D4`; sources count within 500 m (fish
farms) or 300 m (fields).

- **Fish farms** sit on the town's list at +0x780; v1.0's constructor (`sub_502970`)
  snaps a farm to its cell's centre and gives it to the **nearest** town, whatever the
  script says. A farm's pull is `1 - fishermen / info +288` truncated to an integer, so
  a farm being fished pulls nobody else: one fisherman per farm.
- **Fishing** (`sub_6EA730`): each cast catches with one chance in (fishermen); a catch
  is a quarter of a full load (villager info +612) x the season (spring 1.0, summer 0.9,
  autumn 0.7, winter 0.6). Full hands go to the store.
- Fishermen join and leave the farm's list through the fishing states' enter and exit
  slots (`0x6EA8B0`, `0x6EA910`).

Land 1 starts with 20,000 food in the village's store against a need of 12,025, so
Food desire is zero and nobody fishes, as in v1.0. With the store emptied, Food desire
reaches 0.98 and the village's five farms are worked, landing 694 food in 3,000 turns.

## Fields

Fields are not abodes in v1.0's town: the generic creator (`sub_401BA0`) returns
before the abode-list step for them, and the constructor (`sub_4FEB10`) puts them on
the town's field list (+0x778) instead. Each tick (`sub_4FF9C0`) is the abode tick, and
then, on one turn in ten, growth. The ten-turn slot is staggered by a random 0-9 set
at creation. A field reads its numbers from its type record (`DETAIL_FIELD_TYPE_INFO`,
held at +0x120):

- It holds 30 crops (+296), planted one at a time by farmers (state 68).
- A fully planted field below full growth (+292, 1200) grows by k x a rate:
  - The rate is +312 (0.5) before the crop is ripe (+288, 80) and +316 (1.5) after.
    Rain on the field uses +320 / +324 instead.
  - k = 2 x (0.5 x the players' influence there + 1).
  - Food grows by the same amount x +304 / +292.
- Its pull in the food job (`sub_4FFD10`) is `(1 - planted) x free³` while it needs
  planting, or `free` once it is full-grown, where `free = 1 - farmers / +308` (10).
- **Harvest** (`sub_4FFEC0`, read from the disassembly) digs up as much as the villager
  has room for. Before full growth, the field loses more than the villager gets
  (`room x +332` on top). When the food runs out, a full-grown field is cleared for
  replanting.

Farmers join and leave a field's list (+0xD4) through the farming states' enter and
exit slots, like fishermen. On Land 1, with the store emptied, the village's 17 fields
get 473 crops planted in 3,000 turns. At k = 2 the first are full-grown and dug up
by about turn 8,300.

**The game's random generator** is translated too (`LHRandom.h`, `sub_746D10`:
`seed = ror32(9377 × seed + 9439, 13)`). Every random choice above draws from it.

Land 1, 2,000 turns: villagers leave Created, decide, walk home, go inside, go to bed
and sleep, chill outside, and sit around town. 24 have neither home nor town and become
vagrants (130).

## Not yet

- **Movement is a straight line.** v1.0's path code (`sub_5C5BA0`, 625 lines of wall
  hugging over map cells and footpaths) belongs with the landscape work.
- **From the upkeep**: pregnancy and birth (`sub_6E1D80`, `sub_6F0C60`), a child's
  yearly growth in size, the disciple tail, and most of what a death notifies (the
  player's and town's statistics, mourning, dropping what it carried). Without a store
  the original forages for food somewhere in town (`sub_6E3900`); not translated.
- **From the food job**: the third source at town +0xF00; for fields, the players'
  influence (none yet, so k = 2), rain, burning, and the town's "fields need work" flag. The fishing cast waits a fixed 20 turns
  where the original waits out the animation, and the season is always spring (the game
  clock's start is set at runtime).
- **The other work handlers** (food, wood, building, repair,
  worship), Relaxation's handler (it needs the town's relax spots), the disciple and
  child deciders, and `SetState`'s exit/enter slots and pause diversion.
- **The random seed's starting value**: the game sets it at runtime, and we have not
  recovered it.
- Untranslated states hold, then fall back to DecideWhatToDo after 300 turns, so no
  villager is stranded.
