# The creature's plan chooser

A creature picks a desire to serve, an action that serves it, the thing to do it to
and, for some actions, a thing to do it with. The result is a plan. The code is
`src/core/CreaturePlanChooser.cpp` (`black/CreaturePlanChooser.h`), translated from
v1.0, and `test_chooser` checks it on the shipped tables.

## A plan

| Offset | Field | Set by |
|---|---|---|
| +0x08 | desire | the desire pickers |
| +0x0C | target: what a targeted desire is about (a town to help) | `sub_4AC390` |
| +0x10 | belief: what the action is done to | `sub_4AC5F0` |
| +0x14 | object: what it is done with | `sub_4D1EB0` |
| +0x18 | action, one of 328 | `sub_4D1A90` |
| +0x1C | desire score | the desire pickers |
| +0x20 / +0x24 / +0x28 | belief, object and action scores | `sub_4D1A90` |

A plan is complete (`sub_4D13B0`) when it has a desire, a target if the desire needs
one, a belief and an action, plus an object if the action needs one.

## Choosing (`sub_4AC5F0`)

Up to forty passes, each striking one desire off:

1. **A desire about something** (`sub_4AC390`). Eight desires need a target
   (`DESIRE_TABLE` +0x30: to impress, compassion, anger, to be friends, to obey a
   creature, 31, to educate a friend, miss friend). Each scores its strength x how it
   rates the thing (`sub_4CA530`) x distance falloff.
2. **A desire on its own** (`sub_4AC290`) scores a tenth of its strength. Only desires
   with a belief-fit predicate are offered here: play, fear, curiosity, to poo,
   tiredness, to bring stuff home, to rest and to get high. Hunger is not one of them;
   the agenda plans hunger through the action chooser directly (`sub_4D0D00`).
   The comparison in step 1 uses the strength, but the score it stores leaves it out,
   so a targeted desire nearly always beats an untargeted one here.
3. **The thing to act on.** If it suits the desire and scores above zero, the
   creature looks for an action on it. If not, it tries the beliefs related to it
   (`sub_4BB170`).
4. **The action** (`sub_4D1CC0`): each of the desire's candidates, at most thirty from
   `DESIRE_ACTION_TABLE`. Compassion about a town uses
   `COMPASSION_FOR_TOWN_ACTION_TABLE` instead, by what the town needs. A candidate is
   kept if:
   - its validity predicate passes;
   - the creature has its abilities (action +172/+176, 6 = none) and knows its spell
     (+180, a magic type);
   - it is not disabled while leashed;
   - it may be done to a belief (+164);
   - it is not aimed at the creature's own object when +184 forbids that;
   - its target predicate accepts the belief.

   The plan keeps whichever candidate has the largest object x belief x action score.
   A tie goes to the later candidate.

## Scores

| Score | Value | From |
|---|---|---|
| Action | 0.5 + (opinion + 1) x 0.5 x 0.005, plus familiarity | `sub_4AB7F0` |
| Familiarity | times done x 4 / 36,000, at most 0.01; x 0.025 for actions serving desire 0 | `sub_4D0D70` |
| Belief | opinion of it x falloff x a per-desire special factor | `sub_4CA6A0` |
| Falloff | 1 - c x min(distance / 200, 1); the creature's own object scores 1.6 | `sub_4D1F70` |
| Object | 0.1 for the best fitting belief | `sub_4D1EB0`; `sub_4CA7D0` is a constant |

- The belief's opinion is the value of the level its learned tree gives (`sub_4B83C0`,
  the scale in `CreatureOpinion`).
- A leashed creature scores anything beyond its leash at 0. The one exception is
  desire 35 (to hang around at home) when the object passes the vslot 860 test.
- The falloff c is per desire (`DESIRE_TABLE` +0x68): 0.4 for curiosity, 0.01 to 0.05
  for the rest.

So the action's own score barely moves: a creature that loves an action prefers it
by half a percent. What decides a plan is the belief, which is what the creature has
learned about things.

## Dispatch tables

The predicates sit in two `.bss` tables filled by static initialisers that IDA left
as data. Most of their stores go through registers, so `work/gen_chooser_dispatch.py`
runs each initialiser under unicorn and reads the table afterwards.

**Actions** (0x8FFCB8, 328 x 80 bytes):

| Offset | Meaning | Actions |
|---|---|---|
| +16 | validity predicate | 112 |
| +52 | target predicate | 184 |
| +68 | needs an object | 38 |

The +52 entries are the vcall thunks noted in `CreatureActionNames.h`. They call a
virtual on the target object, with the creature as the argument.

**Desires** (0xBA8BB0, 40 x 40 bytes):

| Offset | Meaning |
|---|---|
| +0 | gate |
| +16 | targeted fit, set for exactly the eight targeted desires |
| +20 | belief fit |
| +36 | special score: play and curiosity |

`CreatureDispatch.gen.h` records which entries are filled, and the host is asked only
where the binary has a predicate.

## The predicates are the object's virtuals

Every target and belief predicate (action +52, desire +16 and +20) is a vcall thunk:
a virtual on the object being considered, called with the creature. The generator
decodes each thunk's slot and names it from the vendor vtable structs.

| Desire | Its belief fit |
|---|---|
| anger | `CanBeAttackedByCreature` (slot 141) |
| fear | `CanBeFrighteningToCreature` |
| compassion | `CanBeHelpedByCreature` |
| curiosity | `CanBeInspectedByCreature` |
| to get high | `IsMushroom` (169) |

The targeted fits are:
- impress: `IsTownBelongingToAnotherPlayer`
- compassion: `IsActivityObjectWhichCompassionAppliesTo`
- anger: `IsActivityObjectWhichAngerAppliesTo`
- the creature-directed desires: `IsCreature`

The special scores are:
- play: 5 when the object `IsPlayingFootball`, 3 when it `IsToy`
- curiosity: 5 when it `IsDoingSomethingInteresting`

`CreatureDispatch.gen.cpp` switches from slot to our virtual of that name (75
predicates), and `BindObjectPredicates` plugs them into the chooser.

The naming was checked against the binary. Field's slot 201 (`IsFieldWithFoodInIt`)
reads +0xD0 and +0xDC, its growth and food. Slot 178 returns 1 only for villagers.

`work/gen_predicate_table.py` reads the 75 slots for twelve classes:

| Implementation | Count |
|---|---|
| Constant | 637 |
| Code | 263 |

`test_chooser` builds our objects and checks every constant. That found 17 wrong
answers, now fixed. Most came from comments that cited v1.41 addresses:
- Field said it could be stomped, examined and pooed on (all 0 in v1.0).
- A villager could be befriended (only a creature can).
- Five creature predicates were missing.
- Rock and Bonfire faulted instead of answering 1 for play.

The 263 code-bodied implementations (81 distinct functions) are not yet checked.

Two record fields were misread before and are now known:
- Action +168 is the desire the action serves (4 for the Eat actions, 2 for Fight and
  the attack spells). `AttributeCreatureDominantDesire` maps the current action back
  through this field.
- `DESIRE_TABLE` is the 448-byte table earlier notes called `CreatureInitialDesireInfo`.

## The agenda (`sub_4D0630`, every turn)

This is the loop a creature actually lives by. It is in `core/CreatureAgenda.cpp`.

1. **The queue.** Active, unsuppressed desires are queued (`sub_4D1550`), and desire 0
   comes off first. Each turn two of them (`dword_B0E2EC`) have their plan slot
   rebuilt (`sub_4D06F0`).
2. **Rebuilding a slot.**
   - The desire's gate must pass.
   - A desire that needs a target picks the best one: falloff x how it rates as a
     target (`sub_4D09A0`).
   - The slot is filled (`sub_4D0B40`). How depends on the desire table's +32 flag:

| Desires | +32 flag | Fill |
|---|---|---|
| All but seven | set | Choose the action first, by its own score (`sub_4D0E30`). Then find a belief for it: the best-scoring belief above zero that suits the desire and the action (`sub_4D1170`). An action that takes no belief is done to the creature itself. Then an object if the action needs one (`sub_4D1280`). A failure strikes the action off and tries again, up to 30 times. |
| To impress, compassion, to be friends, to obey a creature, 31, to educate a friend, miss friend | clear | The target names the belief (its vslot 12, `sub_4D0D20`) for each action the chooser offers. |

3. **The plan's score** (`sub_4D1DD0`) is:

   desire x target x min(action, 0.01) x belief x 10^5 x object

   0.1 stands in for a missing target or object. Because of the clamp, the action's
   own score never separates plans.
4. **Switching.** When the queue is empty, the best plan (`sub_4D14E0`) becomes
   current if it is complete and scores more than twice the current plan
   (`sub_4D05D0`). Otherwise the queue refills.

`test_chooser` runs the agenda from shipped data:
- Khazar's one innate lesson is rebuilt into his hunger tree, which rates a villager
  +0.6.
- Hungry (0.8) and curious (0.5), he settles on turn 2 on **EatAlive** against the
  villager, scoring 4.74.
- Curiosity finds nothing it rates above neutral.

The early creature that eats villagers is in the data from the start.

## A creature in the world (`CreatureBrain`)

`core/CreatureBrain.cpp` puts the agenda on a live creature. Each turn:

1. **Perception.** Every object within 200 m becomes a belief.
   - Its belief type comes from `GetCreatureBeliefType` (vslot 67, now checked
     against the binary: six classes were wrong, Creature among them, with 0x16
     against 8).
   - Its attribute vector comes from `DescribeObject`.
   - Its opinion, per desire, comes from the tree that the mind's episodes build
     (the second tree, `mental+0x2518`, which `sub_4CA6A0` reads).
2. **Wiring.** The object predicates are bound to the objects' own virtuals and the
   known lists to the mind's.
   - Every action's validity predicate is translated (see below).
3. **Carrying it out.** When a plan becomes current, its action's handler queues
   sub-actions, which the runner steps through (see "What actions are made of"
   below). Fourteen handlers are translated so far. For any other action,
   the creature walks to its plan's belief and the action completes on arrival,
   with v1.0's effects (the eat step and the action-done routine) but not its
   timing.

`test_level` puts Khazar's shipped mind in a body 20 m from a Land 1 villager, hungry
(0.8) and curious (0.5):
- He plans on turn 1.
- He walks about 160 m to the nearest fish farm and fishes on turn 160.

His innate lesson does rate the villager +0.6 for hunger. But whether a creature can
eat something is `CanCreatureEatMe` (`sub_4C5EA0`, shared by every class), and that
goes through `CanBePickedUpByCreature` (`sub_4C4EC0`) to `sub_4C4E00`. That last one
compares the object with the creature's hand span, which `sub_46E600(14)` measures
off its animated skeleton. Until that is translated, the villager is not edible, so
he fishes.

## When an action is possible (action +16)

`core/CreatureActionValidity.cpp` translates all 47 validity predicates, covering the
112 actions that have one. The generator records which predicate each action calls by
address (`kActionValidityFn`), the translation switches on that address, and
`test_chooser` checks that every one is covered. They read the creature, its mind,
its player and the world through `CreatureFacts`, each fact named for where the
binary keeps it:

| Predicate | Actions | Condition |
|---|---|---|
| `sub_4B5FE0` | 47 spells | Charge at least half (`mental+97592` / `sub_4D82D0`), the player allows it, and the cost is affordable (`sub_4D7910`) |
| `sub_4B6190` | the power-up casts | The same, and stage 8 (`creature+0x1268`) |
| `sub_4B61C0` | teleports | The same, and over 150 m from home |
| `sub_4B60C0` | CastImpressiveSpell | Any of magic types 14, 10, 16, 11, 24 known, castable and over half charged |
| `sub_4B62D0` | Fight | Life above 0.1 |
| `sub_4B6640` / `sub_4B6650` | GoHome / PooAtHome | Over 20 m from home (`creature+0x1200`) / within it |
| `sub_4B63B0` | SleepAtHome, PrayAtCitadel | A player with a temple, home within 1 km |
| `sub_4B6490` | sleeping on the spot | Unless home with a temple is within 140 m |
| `sub_4B6400`, `sub_4B6430`, `sub_4B6460` | dances, stories | 200 / 300 / 450 turns since the last social act, and not the same kind |
| `sub_4B66E0` and others | ...WithFriend | That desire above 0.1 (hunger, water, poo, tiredness), or SADNESS below 0.1 |
| `sub_4B6690`, `sub_4B6670` | Scratch, SitDown | Not while its turn count reads under 2 s (`sub_464BB0`) |
| `sub_4B6220` | LookOutToSea, SitDownOnBeach | Stage 3 |
| `sub_4B66B0` / `sub_4B66D0` | LookAtSun / LookAtMoon | Day / night (`sub_528F30`) |

Others look at the player's hand, the town nearest a friend, the one-off spell the
creature holds, and its home's progress. A fact this world does not supply yet keeps
the answer of an idle creature with no player. `CreatureBrain` fills what it has:
- life, home, stage and home fields;
- desire values and per-action turn counts;
- known spells and fish farms.

## The body and the desires it drives

Each turn Creature's vslot 392 ticks the body and then the desires.

### The body (`CreatureBody`, `sub_4CF980`)

The body is the CreaturePhysical object at creature+352. Its constants come from the
creature info record.

| Field | Each turn |
|---|---|
| Energy (+0x1C) | Drains by `info+560` (0.000116) over 1 to 2 by growth, and 3 more while asleep or resting. From stage 1. |
| Reserve (+0x14) | Drains by `info+564` while energy is under 0.5. |
| Exhaustion (+0x30) | Builds while moving: faster when young, and faster still under `info+540` energy. |
| Dehydration (+0x34) | Builds over `info+548` seconds. From stage 3. |
| Temperature (+0x10) | Drifts toward `info+524` (15 degrees) through a sigmoid. |
| Growth (+0x6C) | Grows while still, from stage 3. |
| Strength (+0x0C) | Decays slowly. Carrying trains it. |

Each action also costs strength, energy and exhaustion from its record (`sub_4CFEB0`).

### The desires (`DesireSystem`, `sub_4BE5B0`)

Each desire has up to eight sources, each a value and a threshold.

1. **Sources refresh** (`sub_4C05B0`). A source with a value function is recomputed;
   every source is then scaled by its type's factor (`DESIRE_SOURCE_TABLE +8`).
   SADNESS fades at 0.998.
   - The functions are the first column of a per-source table at 0xBAE7D8, recovered
     by emulating its initialiser. HUNGER_FROM_ENERGY is 1 - energy (`sub_4C0840`);
     thirst, poo, tiredness, health and warmth read the body the same way.
   - Three desires take SADNESS's own value.
2. **A source pushes** (`sub_4C04E0`) by `Sigmoid(threshold, value)` (`sub_6DF550`,
   now shared with the villagers' falloff).
3. **The desire moves.** It gains the pushes over 10 x its cycle time (in seconds,
   `DESIRE_INITIAL_CYCLE_TIME` by species). With no push, or while its countdown
   runs, it decays by its own factor. It is clamped to the species' minimum and its
   own maximum.

### Where the starting values come from

| What | From |
|---|---|
| Sources | `INITIAL_DESIRE_SOURCE_VALUE` / `_THRESHOLD` (`sub_4C0100`) |
| A mind file | Its own values instead |

A mind file's three floats per desire are value, maximum and cycle. They were matched
against info.dat: Khazar's hunger is 0, 2.0 and 23.6, against the table's maximum of 2
and cycle of 20.

The mind also carries the stage and the saved body (`sub_4CA040`). Khazar, Lethys and
Nemesis are stage 13 with energy 0.997.

These corrections came out of it:
- `sub_4BEB30`, which `DesireModel` translates, is the player-feedback path (its only
  caller is `sub_4C2F60`), not the per-turn update.
- `CreatureDesires +0x1E8` is the cycle time, not the value (the value is at +0x148).
- The cycle-time table holds floats.

### On Land 1

`test_level` starves Khazar to 0.4 energy beside a village and lets his mind run all 40
desires:
1. Hunger climbs as HUNGER_FROM_ENERGY passes its threshold.
2. On the way he looks at the sun, points at the hand, communicates his state and
   hangs around at home.
3. On turn 180 he walks to a fish farm and eats.

`test_chooser` checks one turn of each exactly: the energy drain, and one turn of
hunger at Sigmoid(0.4, 0.5) / 200.

Ours, because actions complete on arrival: a completed plan's slot scores nothing until
the queue rebuilds it.

## What actions are made of: sub-actions

An action's handler (the action table's +32) does nothing itself. It queues
**sub-actions** on the creature's sub-action agenda: `AddSubAction` (`sub_4DE610`) and
a closing `AddMainSubAction` (`sub_4DE770`). For example:

| Action | Sub-actions |
|---|---|
| EatAlive | Pickup (0), then Eat (2) on the villager |
| FishAndEat | MoveToPos (8) to a point by the nearest fish farm, CreateFishFromSea (92), PickupCreatedObject (55), EatCreatedObject (128) |

The sub-action table lives at 0xB0EAF8 (`aPickup`): 144-byte records, the name at
+0, a kind at +64, and up to four steps from +80 (a handler and its `this`
adjustment). It is filled by many small initialisers in 0x4D8300 to 0x4DE100, which
`emu_sub2` runs one by one. There are 158 named sub-actions, from Pickup through
WaitForSpellsToWearOff. `sub_4DE180` runs the current one each turn.

**Eating** (Eat's first step, `sub_4DF5A0`):
- **Energy** rises by `GetFoodValue(3)` (the object's info +104: 250 for a villager,
  20 for a fish, `POT_INFO_FISH`) over `min(growth, 0.8) x info+888` (1000).
- **The cap** is max(growth, 1). Any part of the meal past full x `info+568` goes to
  the reserve.
- **Poo** rises by the gain x `info+896`, and a meal counter at creature+4540 goes up.
- **Growth** is in the mind's saved body (`sub_4D5C40`): Khazar's is 0.32, so a
  villager is 0.78 of energy and a fish 0.062.

**When an action is done** (the routine at 0x460020, which IDA had left as data):
1. The body pays the action's costs (`sub_4CFEB0`).
2. Every `DESIRE_TABLE +120`-th completion of the plan's desire (`sub_4BEE20`):
   - its sources flagged in `DESIRE_SOURCE_TABLE +4` are zeroed (`sub_4C0750`);
   - the action's own desire (record +168) is multiplied by record +208 when record
     +216 is set (`sub_4BE680`). FishAndEat cuts hunger to 1%.
3. A switch on the desire (`0x460218` / `0x460238`):

| Desire | Effect |
|---|---|
| to poo, to attract attention | A 60 s countdown (`sub_4BE3E0`) |
| idle with the player, warmer, colder | A 120 s countdown |
| restore health | +0.5 life |
| tiredness | Falls to the weakest desire over 1.3 (`sub_4BE8B0`, `sub_4BEAC0`) |

### The runner

The agenda is at mental+4008 (`CreatureSubActionAgenda`, 0xC50): a starting flag
(+8), the current sub-action (+12), its step (+16), the count (+20), the main
sub-action (+28), then 32 entries of 96 bytes from +48 (id, object argument, point,
radius, two callbacks).

1. **When the plan becomes current**, `sub_4D15E0` calls `sub_4B6CA0`. That clears
   the agenda and calls the action's handler.
2. **Each turn**, `sub_4DE180`:
   - skips the steps the record has no handler for;
   - when a sub-action begins, checks its kind (record +64):

     | Kind | Check |
     |---|---|
     | 0 | Stops the action unless something is in hand |
     | 1 | Puts down what is held first |
     | 2 | Skips ahead if the hand already holds the target, else drops what it holds |
     | 3 | None |
   - runs the step. It answers 0 (not yet), 1 or 3 (stop the action: `sub_45FA70`)
     or 2 (next step: `sub_4DE940`).
3. **After the third step** of the last sub-action, the action-done routine runs
   (0x460020), then `sub_45F790` closes the action. A record's fourth handler is
   its abort handler, which `sub_45FBC0` calls when an action is stopped.

### FishAndEat, step by step

The handler is `sub_4932E0`:

| Sub-action | Steps |
|---|---|
| MoveToPos | Walks to the farm until within 15 m (`sub_4E0B90`), then waits until it has stopped (`sub_4E1AC0`) |
| CreateFishFromSea | Makes a fish pot at its feet (`sub_4E5EE0`) |
| PickupCreatedObject | Starts the pickup clip (`sub_4DED00`), then waits for it (`sub_4DF0E0`) |
| EatCreatedObject | Starts the eating clip and takes the energy (`sub_4DF5A0`), waits until the fish is out of the hand (`sub_4DF7A0`), then digests it (`sub_4DF830`) |

**Digesting** (`sub_4DF830`):
- Something counts as food if it is a mushroom, pile food, or has food value ≥ 5
  and is not poisoned.
- If it is food, hunger falls by the same amount the meal gave in energy, clamped
  to [0, 1]. The action-done routine then scales hunger by 0.01.
- If it is not food, hunger is held back for 20 s and the agenda is emptied.

**What is ours** (`CreatureSubActions.cpp`):
- **Clip lengths:** pickup takes 12 turns, eating 20 and putting down 10. The real
  lengths are the clips' frame counts, and core doesn't load the creature's ANM set.
- **Clip effects:** they happen when a clip ends, not on its frame events.
- **The walk:** it goes to the farm itself, not to the coast beside it, because core
  has no land/sea test. The original's radius is max(15, the creature's height).
- **The fish:** it isn't a world object.
- **The leash:** it isn't checked.

### The idle actions

These are the actions Khazar does before he gets hungry:

| Action | Handler | Sub-actions |
|---|---|---|
| LookAtSun (193) | `sub_499520` | TurnToFacePos toward (−50000, −50000) m; half the time, then PointAtPoint at it for 3 s |
| PointAtCamera (168) | `sub_4976C0` | TurnToFaceCamera, then PointAtPoint at the camera for 1 s. The camera is `sub_467190`'s: its player's nearest, or the game's when it has no player. Fails with no camera. |
| PointAtHand (169) | `sub_4977F0` | TurnToFaceCamera, then PointAtPoint at the player's nearest hand for 1 s. Fails with no hand. |
| CommunicateState (23) | `sub_485610` | TurnToFaceCamera, then CommunicateToPlayer |
| HangAroundAtHome (165) | `sub_496DC0` | MoveToPos home (within 5 m), Wait 2 to 5 s, then IndividualAction 57 when its player has no temple |

How the sub-actions behave:
- **TurnToFacePos** (`sub_4E0980`) turns only if the point is more than π/8 off the
  creature's heading.
- **PointAtPoint** holds the pose for max(10 turns, seconds × 10).
- **CommunicateToPlayer** (`sub_4E31C0`):
  - It plays the clip of the strongest active desire that has one. That clip is
    the desire table's +28, where +24 is set.
  - If the player gave feedback within the last 10 s, it plays clip 55 or 56
    instead.
  - Either way, desire 18 is held back for 60 s.
- **StaticAction** (`sub_4DFD90`) holds a clip for its seconds. With clip 38
  (resting), it sheds `CREATURE_INFO +576` × 0.2 of exhaustion every turn. Its
  abort handler ends the clip.

When the agenda switches plans, `sub_4D08E0` first stops the running action
("Overriding action"). When no sub-action is running, the per-turn routine
(0x45D8A0) zeroes the current plan's score, so a failed action is picked again
if it still scores best.

**Ours** in these:
- **Turning** is instant.
- **No player:** core has no player, camera, hands or temple. TurnToFaceCamera is
  skipped, and HangAroundAtHome always takes the no-temple branch.
- **Random numbers** come from a seeded generator of the brain's own, not the
  game's.
- **PointAtHand** is ruled out when there is no player (`ChooserHost::action_possible`).
  v1.0 has no validity test for it, since its creature always has a player. Here
  its handler would otherwise fail every turn. PointAtCamera is likewise ruled
  out when the host gives the brain no camera (`CreatureBrain::camera`).

In `test_level` the starved Khazar looks at the sun four times and ends up facing
its point, and points at the camera for 10 turns. He then fishes over 181 turns. His energy rises by exactly one fish
when the eating clip starts, and his hunger ends at clamp(hunger − that fish, 0, 1)
× 0.01.

### EatAlive, and what fits in a hand

EatAlive (11, `sub_482B30`) queues a Pickup of its target and an Eat of it. Half the
time it plays IndividualAction 54 first. If the creature already holds something
edible, it skips the pickup.

| Sub-action | Steps | What it does |
|---|---|---|
| Pickup (0, kind 2) | `sub_4DED00`, `sub_4DF0E0` | Walks within 2 × (both radii) unless within 10 m. Then walks into the hand's reach (`sub_46E750`), plays the pickup clip (14) and waits for the hand to close. |
| Eat (2, kind 0) | `sub_4DF5A0`, `sub_4DF7A0`, `sub_4DFB90` | The first two are EatCreatedObject's: the eating clip (96), and the meal (`GetFoodValue(3)`) taken into the body. The last digests the target (`sub_4DF830`). |

A pickup sub-action (kind 2) drops what the hand holds first (clip 97), unless it holds
the very thing, in which case the pickup is skipped.

Whether a villager can be eaten:
- `CanCreatureEatMe` (`sub_4C5EA0`) requires that it is not a toy and that it can be
  picked up.
- `CanBePickedUpByCreature` (`sub_4C4EC0`) rules out a town artifact and a villager
  worshipping at its own player's site. It also requires the villager to be in the map.
- `sub_4C4E00` requires that it fits in the hand:
  - its radius plus the creature's is within the hand's reach;
  - it weighs no more than 0.8 of the creature (`sub_4C51D0`);
  - it can be picked up at all (vslot 394).

The creature's measures come from its 3D object (`LH3DCreature`, physical +0x58):

| Measure | From |
|---|---|
| Radius | +0x5228 |
| Weight | `sub_468430`: (size_1 × 8.33)³ × 100 × (1 + 0.15 × the morph weights at +0xA4 and +0xAC) |
| Reach | `sub_46E600` with clip 14: four hand points at +0x49C8, blended −0.4, −0.4, 0.9, 0.9 and scaled by size_2 (+0x94) |

`sub_4CE650` measures the four hand points once, from the pickup clip on the creature's
morph meshes 84..81. A villager weighs scale³ × its info's +172 (`sub_5EA850`).

**Ours** in these:
- **No meshes:** core loads none. Without a 3D object the reach is 0 and nothing fits
  in the hand, and a villager's mesh radius and height are 0.
- **The held villager** goes into IN_HAND and stays put. When the eating clip ends,
  it dies.
- **Not translated:**
  - the player tests;
  - the per-type ban (mental +99600);
  - leading a moving target;
  - the strength gained from lifting;
  - Eat's abort handler.
- **In the map:** mobiles are now put in the map when created (`sub_5E8CA0`). Only
  the flag is set; core builds no map grid yet.

In `test_level` a second Khazar has a 3D object whose hand reaches 5 m. Starved, he
picks up a villager after two LookAtSuns. He eats it 22 turns later: a meal of 250
(info +104), and the villager dies.

EatAfterExamining (12, `sub_4850A0`) is the same without the gesture. Between the
pickup and the eating it plays HeldObjectAction (3, `sub_4DFC00`): clip 103 on what
is held. Nothing in `test_level` chooses it yet.

### Places: the feature map

Some actions go to a kind of place: water to sit by, a coast to drink at, a hill. v1.0
keeps one global `CreatureGlobalExplorationMap` (0xBAEFA0) for this
(`black/LandFeatures.h`):
- It has 64 × 64 regions, one per 8 × 8-cell block.
- `sub_4C1610` builds it once per level.
- Each region keeps its highest cell (the altitude byte × 0.67) and a byte of feature
  bits, one per test in the table at 0xB0D7E0.

| Bit | Feature | Test | Where in the block |
|---|---|---|---|
| 0, 1, 3 | Citadel, Town, Forest | An object of info type 8, 0 or 6 in its cells | That object's cell |
| 2 | Field | `sub_5C0740(18)` | Its first coast cell (`0x5C1090`) |
| 4 | Coast | A cell with the coast flag (0x20) and not water | Its first coast cell |
| 5 | Water | A cell with the water flag (0x10), or no landscape | Its first water cell |
| 6 | Hill | Above half the map's highest point, and no neighbour higher (`sub_5BF4B0`) | Its highest cell |
| 7 | Land | A cell that is not water | Its centre |

`sub_4C1480` finds the nearest block with a feature, spiralling out from a point for
4096 steps. The four directions are (1, 0), (0, 1), (−1, 0), (0, −1), set by the
initialiser at 0x6DDD90. It prefers blocks the creature has not explored
(`sub_4C1440`, a bit grid in its exploration map) unless told to take the first.

The handlers that use it:

| Action | Handler | Sub-actions |
|---|---|---|
| SitDownOnBeach (218) | `sub_494450` | MoveToPos near the nearest water; TurnToFacePos to it; StaticAction 38 (resting) for 10–25 s |
| DrinkFromTheSea (55) | `sub_4895E0` | MoveToPos to the nearest coast, unless already in water; TurnToFacePos to the water beyond; IndividualAction 71; then Drink (51, `sub_4E4110`: dehydration 0, desire 14 held back 20 s) |
| WaveAtPlayer (90) | `sub_48DDB0` | TurnToFaceCamera; IndividualAction 72 |
| GoToHillAndWalkAlongRidge (27) | `sub_485B50` | MoveToPos to the nearest hill's top (else the nearest land), within 3 × height. This is the main sub-action, though it is queued first. Then eight MoveToPos 15 m round the top, 45° apart, each within 2 × height. |
| TakeFishFromSeaToHome (259) | `sub_4A23B0` | Unless it already holds something edible: MoveToPos to the nearest fish farm, CreateFishFromSea, PickupCreatedObject. Then MoveToPos home and Discard (1, `sub_4DF500` / `sub_4DF570`) with clip 97. |

A creature's height (slot 267, `sub_461EE0`) is 15 × size_1, which these use as the
walk radius.

**Ours** in these:
- **The object features** (Citadel, Town, Forest) read the map's cell lists.
  - The map (`g_map`, v1.0's at game +6772) is now emptied and sized at each level
    load. Fixed objects link into their cells as the level creates them.
  - The cells are x-major, `cell + 8 × (z + x × extent)` (`sub_5BFA00`). `GMap::ToMap`
    had them transposed.
  - Mobiles link into their cell's mobile list (`sub_5E8D90`): doubly linked,
    +0x20 next and +0x38 previous, new ones at the head. A walk relinks them when it
    crosses into another cell (`MoveMapObject`, `sub_5E8FA0`: 6 for the same cell, 7
    for a new one).
  - Field is not translated; its bit stays clear.
- **No exploration bits:** core keeps none, so every block counts as unexplored.
- **SitDownOnBeach** walks toward the water point itself. The original's search for
  a clear patch of land beside it (`sub_4C1820` → `sub_4C18C0`) is not translated.
- **DrinkFromTheSea:**
  - Its first choice, a drinking place within 1 km (`sub_4673B0`), has no list in
    core.
  - The shore fix-up (`sub_46C0E0` / `sub_46C260`) is not translated.
  - The failure path is not translated.
- **The map is built once,** on first use.

On Land 1:
- The highest point is 166.2 m.
- 166 blocks have coast, 3854 water, 20 hills and 376 land.
- 18 blocks have a town and 96 a forest. None has a citadel, because the level's
  CREATE_CITADEL is not handled yet. The nearest town cell to the map's centre holds
  an abode.
- In `test_level` the fed Khazar sits by the water on turn 548, 14.7 m from it, and
  drinks on turn 1144.
- His desires never choose 27 or 259 there, so the test sets the plan and runs each
  handler directly (`StartAction`, then `RunSubActions` each turn):
  - **GoToHillAndWalkAlongRidge:** he climbs to 15.2 m of the nearest hilltop and
    walks round it in 212 turns.
  - **TakeFishFromSeaToHome:** he fishes, carries the fish 30 m home and puts it down
    in 280 turns.
- **Ours:**
  - A fish put down is only remembered (`CreatureBrain::discarded`, creature +4552),
    since the fish is not a world object here.
  - When there is neither hill nor land, 27 stops. The original walks to (0, 0).

### EatFromStoragePit, and the pit's piles

A storage pit keeps its stock in pile objects:
- one food pile at +0xC4 (POT_INFO_STORAGE_PIT_FOOD_PILE, 2);
- five wood piles at +0xC8..+0xD8 (pot infos 3–7).

| Routine | Does |
|---|---|
| `AddResource` (`sub_6C91A0`) | Fills the piles in order, making each as it is needed. Then counts what they took into the pit's own total (vslot 569). |
| `RemoveResource` (`sub_6C94E0`) | Empties them, last wood pile first. |
| A pot's add (`sub_616FE0`) | Capped at its pot info's +284 unless the info's +292 (the pot info that takes the overflow) is POT_INFO_LAST. So wood piles 3–6 hold 5000 each, and the food pile and the last wood pile have no limit. |
| A pile's remove (`sub_6189C0`) | Counts off its pit, which makes up any shortfall from its other piles. |

The level's starting stock now goes in through AddResource, as v1.0's does (vtable
+156); it went through JustAddResource, which bypassed the piles.

EatFromStoragePit (65, `sub_48AE00`) goes to the pit's food pile:

| Sub-action | What it does |
|---|---|
| MoveToPos | Within 1.4 × height of the pile |
| TurnToFaceObject (6) | Faces the pile and looks at it for 0.1 s |
| ClearObjectToActOn (108) | — |
| CreatePickUpThenRemove (138, `sub_4DF1E0` / `sub_4DF330`) | Makes a pot of POT_INFO_WHEAT_IN_HAND holding min(1000 × size_1, the pile's food). Picks it up, and as the hand closes, the pile gives that much up. |
| EatCreatedObject (main) | Eats it. A pot's food value is its amount (vslot 408). |

**Ours:**
- **The handful's pot** is not a world object, as with the fish.
- **ClearObjectToActOn** leaves the plan's target alone.
- **Pile position:** piles lie at the pit's own position.

In `test_level`, run directly against a pit, Khazar takes a handful of exactly 1000 and
eats it. The pit's total and its pile stay equal throughout.

## What the shipped minds know

`CreatureMindFile` reads the mind past the desires now:
- **Learning** (`sub_4CA1E0`): two trees per desire, each kept as at most 16 episodes
  and rebuilt into a tree when loaded (`sub_4B78E0`). An episode (`sub_4CA390`) has:
  - a learning context;
  - the belief it was about. Its type picks the class (`sub_4B8FF0`: 0 town,
    3 abode, 6 villager, 8 creature, ...), and every class serialises the same way
    (`sub_4C9ED0`): two words, a count, then one value per attribute;
  - a weight.
- **Per-action words** (`sub_4CA260`): 313 at version 25, 322 at 30, all zero.
- **What it knows** (`sub_4C9D70`): the `CreatureActionKnownAbout` lists that the
  chooser's `has()` searches. `BindKnownActions` plugs them in.

| Mind | Abilities | Spells |
|---|---|---|
| Khazar, Lethys, Nemesis | 0 to 5 | none |
| The computer creature | 0 to 5 | magic types 10, 14, 21, 22 and 1 (heal, food, wood, water, and one more) |

All four minds hold exactly **one** learned episode: hunger, about a villager, weight
0.8. The story creatures ship almost untrained. Their opinions of everything else
are those of an empty tree, at or below neutral.
- **The belief path** (`sub_4AC5F0`) needs a score above zero, so it stays quiet
  until the creature learns.
- **The agenda's path** (`sub_4D0D00`, the action chooser with the plan's own belief)
  accepts a zero score, so that is where an untrained creature's behaviour comes
  from.

The version-17 files really are another format. The loader (`sub_4C9170`) reads a
version and then a species below 17, and in those files the second word is a float.

## In the game loop

A creature with a brain runs from the level's own tick:
- `creature::AttachBrain(creature, mind)` gives it one. v1.0 keeps the brain in the
  creature's CreatureMental; core keeps it beside the creature.
- `level::Process` runs a creature's `ProcessState`, as it does a villager's.
- Left to itself (no top state), the creature ticks its brain.
- The brain's world is what the map's cells hold within 600 m (`ObjectsNear`). That is
  the furthest any predicate looks: `sub_4B6A40`'s fish farms. Nothing hands it a
  list.

Fish farms were never in the map: their insert was an empty stub. v1.0's
(`sub_502EB0` → `sub_5041E0`) puts a farm at the head of its one cell's fixed list,
which MultiMapFixed's insert already does.

In `test_level`, Khazar is added to the level's objects and starved. Run by
`level::Process` alone, he fishes on turn 373.

**Ours:**
- **A held point is let go on abort.** PointAtPoint has no abort handler, and where
  v1.0 releases an abandoned point (3D state 8) was not found. Without the release, an
  action stopped mid-point held the hand for good, and the next action waited on it.
- **The cells are scanned as a square** of whole cells, not with v1.0's circle
  iterator. The brain filters by distance itself.
- **Viewer creatures and their minds.** In play mode, a creature a script makes gets a
  brain.
  - LOAD_CREATURE (`sub_696F00`: type, mind file, player, position; nothing returned)
    gives it the mind it names, from `CreatureMind/` (Challenge.chl names
    `KhazarCreature`, `LethysCreature` and `NemesisCreature`, with types 7, 4 and 5).
  - Its species is that CREATURE_TYPE, which is its CREATURE_INFO index.
  - Creatures made any other way get Khazar's mind. That includes the debug key **C**,
    which makes one at the hand. v1.0 gives a creature with no mind file a fresh mind,
    which is not translated.
  - LOAD_MY_CREATURE (`sub_696E70`) puts the player's own creature at a position; with
    no players in core, it makes one there.
- **The camera is the viewer's eye.** Each turn the viewer gives every brain the eye it
  draws from. That is `sub_467190`'s answer when there is no player: the game's camera.

## Not yet

- The two shortcuts in the town branch of `sub_4D1870`: action 101 for a big town,
  and the rotation through town needs at mental+134428.
- The fight shortcut in `sub_4AC530`: a nearby enemy creature means anger, Fight.
- The 81 code-bodied predicate implementations, checked one by one. The action
  validity predicates (+16) and desire gates (+0) are creature methods and are still
  host-supplied.
- The world facts the validity predicates still default:
  - the player's hand and temple;
  - spell charge and cost;
  - day and night, beaches, friends.
- The hand span itself: `sub_4CE650`'s measure off the creature's morph meshes in
  the pickup clip. Until core loads those, a creature without a host-filled 3D
  object can pick up nothing.
- Sources whose inputs this world lacks (watching the player or villagers, home,
  loneliness, ...). They keep their saved value and fade by their factor.
- The real action handlers.
- Compassion's rotation through a town's needs (mental+134428).
- Classifying a belief through a tree rebuilt from a mind's episodes (the node layout
  is now partly known: +12 parent, +16/+20 the split it hangs from, +128 its own split
  attribute (23 = leaf), +132 its children, +144 its opinion level).
