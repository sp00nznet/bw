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
- `tools/run_tests.cmd`: runs every test exe and fails on any failure (netlab's QA for bw).

### Fixed
- Entities were `calloc`'d, so they had no vtable, and the first virtual call
  (`SetPos`) crashed. That took the viewer down on the first spawned abode, before
  this change too. Entities and flocks are now constructed with `new`.
- Save field offsets were `uint16_t`; GFootpathFinder's last five (up to 409,796, the
  object is 0x640C8) were truncated. MSVC only warned; clang-cl refused. The type was
  already refused as inexact, so no wrong bytes were written. The test's 0x20000
  ceiling that the truncation hid is now the largest real object.
- `tools/run_tests.cmd` counted a test that never started (exit 0xC0000135, a missing
  DLL) as passing; any non-zero exit now fails.
- LHVM spawns that passed a tribe, reward or highlight type in `type_enum` no longer
  have it read as an info index.

### Changed
- Static CRT: the exes no longer need the VC++ redistributable on the machine.
- Builds and QA run on recomp-netlab (`netlab check bw`); see README.
- Raw decompiler output, address lists and RTTI/vtable maps are no longer tracked
  (`work/decomp/`, `work/decompiled/`); the scripts that produce them are.
- The `info.dat` "later build" theory is refuted: the v1.2 patch expects our exact
  v1.0 `info.dat` and exe.
