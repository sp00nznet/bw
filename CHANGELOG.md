# Changelog

Format: [Keep a Changelog](https://keepachangelog.com/). No tagged releases yet;
history before this file lives in the README's batch log and `git log`.

## Unreleased

### Added
- `info.dat` loader (`InfoDat`): all 102 sections of v1.0's balance data, rebuilt in the
  original in-memory shape, plus a generated layout (`InfoDatLayout.gen.h`). See
  `docs/info-dat.md`.
- Objects created by `EntityFactory` carry their info record: abodes, villagers, trees,
  mobile statics and features, from level-script names or CHL info enums.
- `test_infodat` (layout, shipped-file anchors, all 1,218 Land1-5 type names resolve) and
  `test_spawn` (Land 1's 1,853 entities spawn headless).
- `tools/run_tests.cmd`: runs every test exe and fails on any failure (used by netlab QA).

### Fixed
- Entities were `calloc`'d, so they had no vtable, and the first virtual call
  (`SetPos`) crashed. That took the viewer down on the first spawned abode, before
  this change too. Entities and flocks are now constructed with `new`.
- LHVM spawns that passed a tribe, reward or highlight type in `type_enum` no longer
  have it read as an info index.

### Changed
- Raw decompiler output, address lists and RTTI/vtable maps are no longer tracked
  (`work/decomp/`, `work/decompiled/`); the scripts that produce them are.
- The `info.dat` "later build" theory is refuted: the v1.2 patch expects our exact
  v1.0 `info.dat` and exe.
