// Decompiled functions for class: GFootpath
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetDebugText@GFootpath@@UAEPADXZ @ 0x0050a140

char * _GetDebugText_GFootpath__UAEPADXZ(void)

{
  return s_Footpath__00b173b0;
}



// ?ToBeDeleted@GFootpath@@UAEXH@Z @ 0x0050a200

void _ToBeDeleted_GFootpath__UAEXH_Z(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0x14);
  while (piVar1 != (int *)0x0) {
    iVar4 = *piVar1;
    piVar1 = (int *)piVar1[9];
    (**(code **)(iVar4 + 0xc))(0);
  }
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  iVar3 = DAT_00c22ca4;
  iVar4 = *(int *)(DAT_00c22ca4 + 0x201d20);
  if (iVar4 == in_ECX) {
    *(undefined4 *)(DAT_00c22ca4 + 0x201d20) = *(undefined4 *)(in_ECX + 0x1c);
  }
  else {
    if (iVar4 == 0) goto LAB_0050a272;
    while (iVar2 = *(int *)(iVar4 + 0x1c), iVar2 != in_ECX) {
      iVar4 = iVar2;
      if (iVar2 == 0) {
        *(undefined4 *)(in_ECX + 0x20) = 0;
        _ToBeDeleted_GameThing__UAEXH_Z(param_1);
        return;
      }
    }
    *(undefined4 *)(iVar4 + 0x1c) = *(undefined4 *)(in_ECX + 0x1c);
  }
  *(int *)(iVar3 + 0x201d24) = *(int *)(iVar3 + 0x201d24) + -1;
  *(undefined4 *)(in_ECX + 0x1c) = 0;
LAB_0050a272:
  *(undefined4 *)(in_ECX + 0x20) = 0;
  _ToBeDeleted_GameThing__UAEXH_Z(param_1);
  return;
}



// ?Save@GFootpath@@UAEIAAVGameOSFile@@@Z @ 0x0050ac40

undefined4 _Save_GFootpath__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  int iVar3;
  
  iVar1 = FUN_0053e8e0(param_1);
  if (iVar1 == 0) {
    return 0;
  }
  iVar2 = 0;
  for (iVar1 = *(int *)(in_ECX + 0x14); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x24)) {
    iVar2 = iVar2 + 1;
  }
  *(int *)(in_ECX + 0x18) = iVar2;
  if (DAT_00b19ac8 != 0) {
    iVar1 = *(int *)(in_ECX + 0x18);
    iVar3 = 0;
    iVar2 = FUN_0072be90((byte *)(in_ECX + 0x18),4,0);
    if (iVar2 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x18) + 4;
    iVar2 = 0;
    while( true ) {
      if (iVar2 == 0) {
        iVar2 = *(int *)(in_ECX + 0x14);
      }
      else {
        iVar2 = *(int *)(iVar2 + 0x24);
      }
      if (iVar2 == 0) break;
      iVar3 = iVar3 + 1;
      if (iVar1 < iVar3) {
        DAT_00b19ac8 = 0;
        return 1;
      }
      if (DAT_00b19ac8 == 0) {
        return 1;
      }
      FUN_00531bc0(iVar2);
    }
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x20),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x20) + 4;
    }
  }
  return 1;
}



// ?Load@GFootpath@@UAEIAAVGameOSFile@@@Z @ 0x0050ad50

undefined4 _Load_GFootpath__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
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
      *(undefined4 *)(in_stack_00005d0d + 0x24) = 0;
      iVar2 = *(int *)(in_ECX + 0x14);
      if (iVar2 == 0) {
        *(int *)(in_ECX + 0x14) = in_stack_00005d0d;
      }
      else {
        for (iVar1 = *(int *)(iVar2 + 0x24); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x24)) {
          iVar2 = iVar1;
        }
        *(int *)(iVar2 + 0x24) = in_stack_00005d0d;
      }
      *(undefined4 *)(in_stack_00005d0d + 0x24) = 0;
      *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
    }
  }
  if (DAT_00b19acc != 0) {
    iVar2 = FUN_0072be50();
    if (iVar2 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x20) + 4;
  }
  return 1;
}



