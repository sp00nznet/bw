"""Decode the creature action names out of the dispatch-table initialiser.

The 80-byte-per-action table at 0x8FFCB8 is .bss, filled by a long inlined run
of `mov [table + 80*i], offset "..."` stores around 0x481000. Only entries
233..327 get a name; 1..232 are never written and index 0 is a static
"Undefined". Run inside idalib:

    py -3.11 gen_action_names.py            # writes work/decomp/creature_actions.txt

then regenerate the header/source from that list.
"""
BASE = 0x8FFCB8
STRIDE = 80
COUNT = 328
SCAN = (0x460000, 0x4C0000)
# See the session transcript for the idalib loop; the output it produces is
# work/decomp/creature_actions.txt, "index<TAB>name" per line.
