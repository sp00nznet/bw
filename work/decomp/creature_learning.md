# How the creature learns

Recovered from `runblack_decrypted.exe` (v1.0) with `tools/decomp/bw_decomp.py`.
None of this is reachable by the RTTI vtable walk that drove the rest of the
project — `AttributeTest`, `DecisionTree` and the learning nodes are plain data
structs with non-virtual methods. The way in was `xrefs`: follow data references
from the 24 `Attribute` vtables back to the code that constructs them, then
follow calls outward from there.

Original source files, named in the allocator's own debug arguments:

- `C:\dev\black\CreatureMentalBeliefs.cpp` — the per-belief attribute sets
- `C:\dev\black\CreatureInitialLesson.cpp` — the innate lessons a creature starts with

## The shape of it

The creature runs **greedy decision-tree induction with gain ratio** — C4.5, in
1999, per creature, live. Not a scripted behaviour tree.

```
sub_4B78F0(node, tree):                  # rebuild after new evidence arrives
    sub_4B7810(node)                     # allocate a fresh root (148 bytes)
    while node.pending:                  # +24
        sub_4B81E0(node)                 # one induction step

sub_4B81E0(node, tree):
    if node.depth_budget == 0 or node.weight < 0.01:      # +124, sub_4B93F0
        node.opinion = LeafValue(node)                     # +144, sub_4B9410
        tree.total += node.weight                          # +32
        Finalise(node)                                     # sub_4B7D80
    else:
        candidates = ScoreSplits(node)                     # sub_4B9490
        best = candidates.head                             # sorted descending
        if best.score <= 0.0:
            ... same leaf path ...
        else:
            node.split_attribute = best.attribute          # +128
            node.split_extra     = best.field_4            # +140
            Expand(node)                                   # sub_4B7E00
        free candidates
    node.pending = 0
```

### Stopping (`sub_4B93F0`)

```c
return node->weight < 0.01f;
```

A branch stops growing once the evidence that reached it is under 1% of the
whole. Combined with "no split scores above zero", that is the entire pruning
policy — there is no depth limit doing the real work.

### Split scoring (`sub_4B9490` + `sub_4B9820`)

`sub_4B9490` walks the node's candidate attributes (`node[7..]`, count at
`node[31]`), scores each with `sub_4B9820`, and inserts into a list kept sorted
by **descending** score, so the head is the winner.

`sub_4B9820` is gain ratio:

```
total = node.weight
if attribute->GetNumValues() == 0: return total          # degenerate
for v in 0 .. GetNumValues()-1:
    subset = episodes whose attribute value == v         # sub_4BA8F0
    frac   = |subset| / |episodes|
    weighted += Impurity(subset) * frac                  # sub_4B99E0
    if frac > 0: split_info -= frac * <lost>             # sub_4B9BB0
if split_info < 1.0: split_info = 1.0                    # clamp the divisor
return (total - weighted) / split_info
```

**Uncertainty, stated rather than papered over:** Hex-Rays renders the
`split_info` accumulation as `split_info -= frac * frac`, with a call to
`sub_4B9BB0(frac)` immediately before whose result is discarded. That is the
signature of an FPU idiom the decompiler lost. The C4.5 split-information term
is `-Σ frac·log₂(frac)`, and a `frac²` term would make the clamp to 1.0
meaningless (the sum can never exceed 1). So `sub_4B9BB0` is near-certainly a
log, but this has **not** been confirmed — it needs the disassembly, not the
pseudocode. Nothing in `src/` depends on this yet.

### Leaf value (`sub_4B9410`)

```c
if (node has no episodes) {
    walk up node->parent (+12); if we reach the root, return 5;   // neutral
}
mean = Σ episode.weight / count;                                  // weight at +12
for (level = 0; level < 11; ++level)
    if (fabs(mean - kOpinionScale[level]) <= 0.25f) return level; // sub_4B9B80
return -1;
```

## The opinion scale (`flt_B0CDC0`, read from .rdata)

```
[0] -1.0   [1] -0.8   [2] -0.6   [3] -0.4   [4] -0.2
[5]  0.0
[6]  0.2   [7]  0.4   [8]  0.6   [9]  0.8   [10] 1.0
```

Eleven levels, 0.2 apart, **±0.25 tolerance**. The tolerance is wider than half
the spacing, so the bands overlap by design, and the scan runs from the most
negative upward — so a mean of 0.1 reads as level 4 (−0.2), not level 5 or 6.
A creature's opinions skew negative at the boundaries.

This is implemented and tested in `src/core/CreatureOpinion.cpp`. It was read
out of the binary rather than inferred: a reasonable guess from the code alone
(±0.25 tolerance ⇒ 0.5 spacing ⇒ a −2.5…+2.5 scale) is wrong on every count.

`flt_B0CDE4` = **0.8**, the weight `CreatureInitialLesson` seeds its episodes
with. A creature does not start blank; its innate lessons arrive already
weighted near the top of the scale.

## Struct sizes recovered

| type | size | note |
|---|---|---|
| `Attribute` | 0xC | vendor header says 0x8 and omits the value field at +8 |
| `CreatureLearningEpisode` | 20 | `{vftable, _, context*, weight@12, _@16}` |
| `CreatureLearningContext` | 24 | built by `sub_4C3650` |
| induction node | 148 | `sub_4B7810` allocates it |

## Still open

- `sub_4B9BB0` — confirm the log (needs disassembly, not pseudocode).
- `sub_4B99E0` — the subset impurity measure.
- `sub_4B7E00` / `sub_4B7D80` — node expansion and leaf finalisation, which
  would give the node struct's remaining fields.
- `sub_4BA8F0` — how an episode is matched against an attribute value.
- The `Attribute` vtable may be longer than the 13 slots the walk found:
  `sub_4C3650` calls slot 13 (offset 52) on one.
