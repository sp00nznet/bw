// Decompiled functions for class: GlobalGameLists
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Dump@GlobalGameLists@@UAEXXZ @ 0x0055a0e0

void _Dump_GlobalGameLists__UAEXXZ(void)

{
  int *piVar1;
  int in_ECX;
  
  for (piVar1 = *(int **)(in_ECX + 8); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[0x1a]) {
    (**(code **)(*piVar1 + 0x18))();
  }
  for (piVar1 = *(int **)(in_ECX + 0x10); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[0x11]) {
    (**(code **)(*piVar1 + 0x18))();
  }
  for (piVar1 = *(int **)(in_ECX + 0x18); piVar1 != (int *)0x0; piVar1 = (int *)piVar1[0x29]) {
    (**(code **)(*piVar1 + 0x18))();
  }
  return;
}



