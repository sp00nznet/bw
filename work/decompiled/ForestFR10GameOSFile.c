// Decompiled functions for class: ForestFR10GameOSFile
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// _Load__6ForestFR10GameOSFile @ 0x0050f240

undefined4 _Load__6ForestFR10GameOSFile(int param_1)

{
  int iVar1;
  int in_ECX;
  uint in_stack_00011737;
  uint in_stack_00017448;
  
  iVar1 = _Load_Container__UAEIAAVGameOSFile___Z();
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x3c) + 4;
    }
    FUN_00531f30();
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x40) + 4;
      if (DAT_00b19acc != 0) {
        iVar1 = FUN_0072be50();
        if (iVar1 == 3) {
          DAT_00b19acc = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (in_stack_00011737 & 0xff) + 4;
        for (; 0 < (int)in_stack_00011737; in_stack_00011737 = in_stack_00011737 - 1) {
          FUN_00531f30();
          FUN_0050f4e0();
        }
        if (DAT_00b19acc != 0) {
          iVar1 = FUN_0072be50();
          if (iVar1 == 3) {
            DAT_00b19acc = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (in_stack_00017448 & 0xff) + 4;
          for (; 0 < (int)in_stack_00017448; in_stack_00017448 = in_stack_00017448 - 1) {
            FUN_00531f30();
            FUN_0050f4e0();
          }
        }
      }
    }
    FUN_00531f30();
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (DAT_00bf1828 & 0xff) + 4;
      if (DAT_00b19acc != 0) {
        iVar1 = FUN_0072be50();
        if (iVar1 == 3) {
          DAT_00b19acc = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (DAT_00b17458 & 0xff) + 4;
      }
    }
    return 1;
  }
  return 0;
}



