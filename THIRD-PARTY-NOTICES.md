# Third-party notices

The project's own code is MIT (see [LICENSE](LICENSE)). This file records what
else is in the tree and under what terms, because not all of it can be MIT.

---

## Compiled into the build

### kjmp2 — MPEG-1/2 Layer II decoder
`src/viewer/third_party/kjmp2.{c,h}`
Copyright (c) 2006-2013 Martin J. Fiedler <martin.fiedler@gmx.net>
**zlib licence.**

Used by `sad_loader` to decode BW's voice banks, which are `WAVE_FORMAT_MPEG`
(tag 0x0050) Layer II rather than MP3. Permissive and MIT-compatible; the
requirement is that the copyright notice stays in the source, which it does.
Do not remove the header block at the top of `kjmp2.c`.

---

## Reference material, not compiled

### bw1-decomp — 569 decompiled struct headers
`vendor/bw1-decomp/`
<https://github.com/openblack/bw1-decomp> — **CC0-1.0** (public domain
dedication).

This is the reference most of `src/include/black/` was translated from. CC0
carries no conditions, so nothing here constrains the MIT grant. It is worth
being explicit that the *layouts* originate in the original game binary; CC0 is
what the bw1-decomp authors applied to their transcription of them.

### SafeDiscLoader2
`vendor/SafeDiscLoader2/`
**GPL-3.0.**

Not referenced by `src/CMakeLists.txt` and not part of any build target, but it
*is* tracked in git, so this repository redistributes GPL-3.0 code. That is why
[LICENSE](LICENSE) scopes the MIT grant rather than claiming the whole tree.
The GPL applies to this directory on its own terms; it does not reach the rest
of the repository, since nothing links against it.

### SafeDiscLoader
`vendor/SafeDiscLoader/`
**No licence file present.** Terms unknown, so assume all rights reserved.
Not built, not linked.

Both SafeDisc directories are copy-protection tooling for producing a decrypted
`runblack.exe` to analyse. They are not needed to build or run anything here.

---

## Documentation used, code not copied

### openblack
<https://github.com/openblack/openblack> — GPL-3.0.

openblack's reverse-engineering notes were used as documentation for the L3D,
G3D, LND, CHL, ANM and Pack/SAD file formats. The loaders in `src/viewer/` were
written against those format descriptions, not copied from openblack's source;
file formats are facts about the data, and the implementations here are our own.

One item deserves naming rather than glossing: the 465-entry CHL native function
table in `src/include/black/LHVM.h` was transcribed with openblack's `CHLApi` as
the source. Those names and indices are the original game's bytecode ABI —
facts about Black & White recoverable from the CHL files and the executable —
so this is a thin data table describing an external interface rather than
openblack's own expression. It is called out here so anyone auditing the licence
can make their own judgement instead of discovering it themselves.

---

## The game itself

Black & White is © Lionhead Studios / Electronic Arts. No game assets, data
files, or original binaries are included in this repository, and none may be
added to it. Building and running requires your own copy of the game.

The translated method bodies in `src/core/` derive from the behaviour of the
original executable. MIT is applied to the expression of that translation as
written here; it is not, and cannot be, a licence to the original game.
