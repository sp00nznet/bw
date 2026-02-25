// Decompiled functions for class: HandStateInvisible
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Enter@HandStateInvisible@@UAEXXZ @ 0x00456e00

void _Enter_HandStateInvisible__UAEXXZ(void)

{
  int in_ECX;
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  FUN_004571f0(0);
  iVar2 = *(int *)(in_ECX + 4);
  puVar3 = *(undefined4 **)(iVar2 + 0x47f0);
  puVar4 = *(undefined4 **)(iVar2 + 0x49ac);
  for (uVar1 = (uint)(*(int *)(iVar2 + 0x47b8) * 0x30) >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
    *(undefined1 *)puVar4 = *(undefined1 *)puVar3;
    puVar3 = (undefined4 *)((int)puVar3 + 1);
    puVar4 = (undefined4 *)((int)puVar4 + 1);
  }
  return;
}



// ?Exit@HandStateInvisible@@UAEXXZ @ 0x00456e40

void _Exit_HandStateInvisible__UAEXXZ(void)

{
  FUN_004570d0(0);
  return;
}



