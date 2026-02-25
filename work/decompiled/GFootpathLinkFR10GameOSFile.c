// Decompiled functions for class: GFootpathLinkFR10GameOSFile
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// _Load__13GFootpathLinkFR10GameOSFile @ 0x0050b3c0

undefined4 _Load__13GFootpathLinkFR10GameOSFile(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 *puVar4;
  int in_stack_00005d0d;
  uint in_stack_00005d15;
  
  iVar2 = FUN_0053e9f0();
  if (iVar2 == 0) {
    return 0;
  }
  if (DAT_00b19acc != 0) {
    iVar2 = FUN_0072be50();
    if (iVar2 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (in_stack_00005d15 & 0xff) + 4;
    for (; 0 < (int)in_stack_00005d15; in_stack_00005d15 = in_stack_00005d15 - 1) {
      FUN_00531f30();
      if ((in_stack_00005d0d != 0) && (puVar3 = operator_new(8), puVar3 != (undefined4 *)0x0)) {
        puVar3[1] = in_stack_00005d0d;
        *puVar3 = 0;
        puVar1 = *(undefined4 **)(in_ECX + 0x14);
        if (*(undefined4 **)(in_ECX + 0x14) == (undefined4 *)0x0) {
LAB_0050b469:
          *(undefined4 **)(in_ECX + 0x14) = puVar3;
        }
        else {
          do {
            puVar4 = puVar1;
            puVar1 = (undefined4 *)*puVar4;
          } while ((undefined4 *)*puVar4 != (undefined4 *)0x0);
          if (puVar4 == (undefined4 *)0x0) goto LAB_0050b469;
          *puVar4 = puVar3;
        }
        *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
      }
    }
  }
  return 1;
}



