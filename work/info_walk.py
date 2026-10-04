# Walk game_data/info.dat in the binary-path order of sub_425250 and report
# where each section lands, with the strings found inside it.
import re, sys
D = open("../game_data/info.dat", "rb").read()
CLASSES = [  # (name, bytes/rec, count) from info_readsizes.py
 ("MagicInfo",72,10),("MagicHeal",80,2),("MagicTeleport",76,1),("MagicForest",92,1),
 ("MagicResource",92,2),("MagicStorm",92,3),("MagicShield",100,2),("MagicResource",92,1),
 ("MagicInfo(water)",72,2),("MagicFlockGround",84,1),("MagicFlockFlying",88,1),("MagicCreature",140,16),
 ("MagicEffect",268,42),("SpellSeed",384,30),("AnimalInfo",700,31),("CreatureInfo",900,17),
 ("Creature_0",92,17),("427D80",68,40),("427E10",116,14),("427EA0",56,17),("428AC0",68,1),
 ("428BE0",328,1),("428D60",308,5),("428EE0",336,9),("429250",284,2),("AbodeInfo?",440,147),
 ("VillagerInfo?",916,84),("429760",76,48),("428820",302,23),("427BE0",244,4),("429660",256,4),
 ("429840",248,2),("428680",64,1)]
TABLES = [l.split() for l in open("decomp/info_layout.txt") if not l.startswith("#")]
TABLES = [(t[0], int(t[3]), int(t[2])) for t in TABLES]
seq = CLASSES + TABLES[:24] + [("SoundInfo",60,1),("BeliefInfo",24,1)] + TABLES[24:25] \
    + [("Influence",12,1),("HelpSystem",16,1)] + TABLES[25:]
off = int(sys.argv[1], 0) if len(sys.argv) > 1 else 0x2C
strs = [(m.start(), m.group().decode()) for m in re.finditer(rb"[A-Za-z][A-Za-z0-9_ ]{4,}", D)]
for name, rec, n in seq:
    end = off + rec * n
    inside = [(o, s) for o, s in strs if off <= o < end]
    rel = ", ".join(f"{(o-off)%rec}:{s[:18]}" for o, s in inside[:4])
    print(f"{off:7d} {name:34s} {rec:4d}x{n:<4d} strs={len(inside):3d} {rel}")
    off = end
print("end", off, "file", len(D))
