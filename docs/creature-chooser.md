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
3. **Carrying it out.** The creature walks to its current plan's belief. A fishing
   action is planned on the creature itself, so it walks to the nearest fish farm
   instead.

What happens on arrival is ours:
- the action completes;
- an eating action kills the villager;
- the desire it served drops by 0.5.

The 52 real action handlers are not translated.

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
the queue rebuilds it, and a meal restores half the energy.

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
- `CanCreatureEatMe`'s chain down to the hand span, so a creature can eat what it
  likes.
- Sources whose inputs this world lacks (watching the player or villagers, home,
  loneliness, ...). They keep their saved value and fade by their factor.
- The real action handlers.
- Compassion's rotation through a town's needs (mental+134428).
- Classifying a belief through a tree rebuilt from a mind's episodes (the node layout
  is now partly known: +12 parent, +16/+20 the split it hangs from, +128 its own split
  attribute (23 = leaf), +132 its children, +144 its opinion level).
- Calling the chooser from `Creature::ProcessState`, and running the chosen action.
