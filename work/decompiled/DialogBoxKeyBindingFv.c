// Decompiled functions for class: DialogBoxKeyBindingFv
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// _InitControls__19DialogBoxKeyBindingFv @ 0x004ef770

void _InitControls__19DialogBoxKeyBindingFv(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int in_ECX;
  uint uVar5;
  undefined1 auStack_200 [512];
  
  iVar1 = *(int *)(in_ECX + 0x18);
  uVar3 = *(undefined4 *)(iVar1 + 0x27c);
  uVar4 = *(undefined4 *)(iVar1 + 0x248);
  iVar2 = *(int *)(iVar1 + 0x250);
  while (0 < iVar2) {
    FUN_004090d0(iVar2 + -1);
    iVar2 = *(int *)(iVar1 + 0x250);
  }
  uVar5 = 0;
  do {
    FUN_0045b640(uVar5,auStack_200);
    FUN_004091e0(uVar5,auStack_200);
    if ((-1 < (int)uVar5) && ((int)uVar5 < *(int *)(*(int *)(in_ECX + 0x18) + 0x250))) {
      *(undefined1 **)(*(int *)(*(int *)(in_ECX + 0x18) + 0x26c) + uVar5 * 4) = &LAB_004ef3e0;
    }
    FUN_0045c1b0(uVar5);
    uVar5 = uVar5 + 1;
  } while (uVar5 < 0x21);
  *(undefined4 *)(*(int *)(in_ECX + 0x18) + 0x27c) = uVar3;
  *(undefined4 *)(*(int *)(in_ECX + 0x18) + 0x248) = uVar4;
  DAT_00be75b0 = 0;
  return;
}



