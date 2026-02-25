// Decompiled functions for class: DanceKeyAction
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetSaveType@DanceKeyAction@@UAEIXZ @ 0x004ec290

undefined4 _GetSaveType_DanceKeyAction__UAEIXZ(void)

{
  return 0x79;
}



// ?GetDebugText@DanceKeyAction@@UAEPADXZ @ 0x004ec2a0

char * _GetDebugText_DanceKeyAction__UAEPADXZ(void)

{
  return s_DanceKeyAction__00b16040;
}



// ?Save@DanceKeyAction@@UAEIAAVGameOSFile@@@Z @ 0x004ec3a0

undefined4 _Save_DanceKeyAction__UAEIAAVGameOSFile___Z(int param_1)

{
  byte *pbVar1;
  uint *puVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  uint uStack_8;
  int iStack_4;
  
  iVar3 = param_1;
  iVar4 = FUN_0053e8e0(param_1);
  if (iVar4 == 0) {
    return 0;
  }
  if (DAT_00b19ac8 != 0) {
    iStack_4 = *(int *)(in_ECX + 0x18);
    pbVar1 = (byte *)(in_ECX + 0x18);
    param_1 = 0;
    iVar4 = FUN_0072be90(pbVar1,4,0);
    if (iVar4 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar3 + 0x214) = *(int *)(iVar3 + 0x214) + *pbVar1 + 4;
    iVar4 = *(int *)pbVar1;
    while (iVar4 = iVar4 + -1, -1 < iVar4) {
      param_1 = param_1 + 1;
      if (iStack_4 < param_1) {
        DAT_00b19ac8 = 0;
        return 1;
      }
      if (DAT_00b19ac8 == 0) {
        return 1;
      }
      iVar5 = iVar4;
      for (puVar2 = *(uint **)(in_ECX + 0x14); puVar2 != (uint *)0x0; puVar2 = (uint *)puVar2[1]) {
        if (iVar5 == 0) {
          uStack_8 = *puVar2;
          goto LAB_004ec440;
        }
        iVar5 = iVar5 + -1;
      }
      uStack_8 = 0;
LAB_004ec440:
      iVar5 = FUN_0072be90(&uStack_8,4,0);
      if (iVar5 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(iVar3 + 0x214) = *(int *)(iVar3 + 0x214) + (uStack_8 & 0xff) + 4;
    }
    if (DAT_00b19ac8 != 0) {
      iVar4 = FUN_0072be90((byte *)(in_ECX + 0x1c),4,0);
      if (iVar4 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(iVar3 + 0x214) = *(int *)(iVar3 + 0x214) + *(byte *)(in_ECX + 0x1c) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar4 = FUN_0072be90((byte *)(in_ECX + 0x20),0x38,0);
        if (iVar4 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(iVar3 + 0x214) = *(int *)(iVar3 + 0x214) + *(byte *)(in_ECX + 0x20) + 0x38;
      }
    }
  }
  return 1;
}



// ?Load@DanceKeyAction@@UAEIAAVGameOSFile@@@Z @ 0x004ec520

undefined4 _Load_DanceKeyAction__UAEIAAVGameOSFile___Z(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 in_stack_00005d0d;
  uint in_stack_00005d15;
  uint in_stack_0000ba1e;
  
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
      if (DAT_00b19acc != 0) {
        iVar2 = FUN_0072be50();
        if (iVar2 == 3) {
          DAT_00b19acc = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (in_stack_0000ba1e & 0xff) + 4;
      }
      puVar3 = operator_new(8);
      if (puVar3 == (undefined4 *)0x0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        uVar1 = *(undefined4 *)(in_ECX + 0x14);
        *puVar3 = in_stack_00005d0d;
        puVar3[1] = uVar1;
      }
      *(undefined4 **)(in_ECX + 0x14) = puVar3;
      *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
    }
  }
  if (DAT_00b19acc != 0) {
    iVar2 = FUN_0072be50();
    if (iVar2 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x1c) + 4;
  }
  if (DAT_00b19acc != 0) {
    iVar2 = FUN_0072be50();
    if (iVar2 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x20) + 0x38;
  }
  return 1;
}



