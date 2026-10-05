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

## Not yet

- The two shortcuts in the town branch of `sub_4D1870`: action 101 for a big town,
  and the rotation through town needs at mental+134428.
- The fight shortcut in `sub_4AC530`: a nearby enemy creature means anger, Fight.
- The 81 code-bodied predicate implementations, checked one by one. The action
  validity predicates (+16) and desire gates (+0) are creature methods and are still
  host-supplied.
- Beliefs' opinions. A creature with an untrained tree rates everything neutral (0),
  so the belief-driven path chooses nothing until it has learned. The shipped minds'
  learning data (the rest of the mind file) is what gives it opinions.
- Calling the chooser from `Creature::ProcessState`, and running the chosen action.
