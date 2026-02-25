// Decompiled functions for class: GStream
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetSaveType@GStream@@UAEIXZ @ 0x0052ee30

undefined4 _GetSaveType_GStream__UAEIXZ(void)

{
  return 0x47;
}



// ?GetDebugText@GStream@@UAEPADXZ @ 0x0052ee40

char * _GetDebugText_GStream__UAEPADXZ(void)

{
  return s_Stream__00b1a480;
}



// ?ToBeDeleted@GStream@@UAEXH@Z @ 0x006c9b80

void _ToBeDeleted_GStream__UAEXH_Z(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  iVar3 = *(int *)(in_ECX + 0x14);
  while (iVar3 != 0) {
    iVar1 = *(int *)(iVar3 + 0xc);
    FUN_007290de(iVar3);
    iVar3 = iVar1;
  }
  *(undefined4 *)(in_ECX + 0x14) = 0;
  *(undefined4 *)(in_ECX + 0x18) = 0;
  iVar1 = DAT_00c22ca4;
  iVar3 = *(int *)(DAT_00c22ca4 + 0x201d18);
  if (iVar3 == in_ECX) {
    *(int *)(DAT_00c22ca4 + 0x201d18) = *(int *)(in_ECX + 0x24);
  }
  else {
    if (iVar3 == 0) goto LAB_006c9bed;
    while (iVar2 = *(int *)(iVar3 + 0x24), iVar2 != in_ECX) {
      iVar3 = iVar2;
      if (iVar2 == 0) {
        _ToBeDeleted_GameThing__UAEXH_Z(param_1);
        return;
      }
    }
    *(undefined4 *)(iVar3 + 0x24) = *(undefined4 *)(in_ECX + 0x24);
  }
  *(int *)(iVar1 + 0x201d1c) = *(int *)(iVar1 + 0x201d1c) + -1;
  *(undefined4 *)(in_ECX + 0x24) = 0;
LAB_006c9bed:
  _ToBeDeleted_GameThing__UAEXH_Z(param_1);
  return;
}



// ?Save@GStream@@UAEIAAVGameOSFile@@@Z @ 0x006ca1d0

undefined4 _Save_GStream__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  byte *pbVar4;
  
  iVar1 = FUN_0053e8e0(param_1);
  if (iVar1 == 0) {
    return 0;
  }
  if (DAT_00b19ac8 != 0) {
    iVar1 = *(int *)(in_ECX + 0x18);
    iVar3 = 0;
    iVar2 = FUN_0072be90((byte *)(in_ECX + 0x18),4,0);
    if (iVar2 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x18) + 4;
    pbVar4 = (byte *)0x0;
    while( true ) {
      if (pbVar4 == (byte *)0x0) {
        pbVar4 = *(byte **)(in_ECX + 0x14);
      }
      else {
        pbVar4 = *(byte **)(pbVar4 + 0xc);
      }
      if (pbVar4 == (byte *)0x0) break;
      iVar3 = iVar3 + 1;
      if (iVar1 < iVar3) {
        DAT_00b19ac8 = 0;
        return 1;
      }
      if (DAT_00b19ac8 == 0) {
        return 1;
      }
      iVar2 = FUN_0072be90(pbVar4,0x10,0);
      if (iVar2 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *pbVar4 + 0x10;
    }
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x1c),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x1c) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90((byte *)(in_ECX + 0x20),4,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x20) + 4;
      }
    }
  }
  return 1;
}



// ?Load@GStream@@UAEIAAVGameOSFile@@@Z @ 0x006ca330

undefined4 _Load_GStream__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  int in_stack_00005d0d;
  uint in_stack_00005d15;
  
  iVar1 = param_1;
  iVar3 = in_ECX;
  iVar2 = FUN_0053e9f0(param_1);
  if (iVar2 != 0) {
    if (DAT_00b19acc != 0) {
      iVar3 = FUN_0072be50(&param_1,4,0,unaff_ESI,unaff_EBX,unaff_EDI,unaff_EBP,iVar3);
      if (iVar3 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + (in_stack_00005d15 & 0xff) + 4;
      for (; 0 < (int)in_stack_00005d15; in_stack_00005d15 = in_stack_00005d15 - 1) {
        pbVar4 = (byte *)FUN_00746d70();
        if (pbVar4 == (byte *)0x0) {
          pbVar4 = (byte *)0x0;
        }
        else {
          pbVar4[0xc] = 0;
          pbVar4[0xd] = 0;
          pbVar4[0xe] = 0;
          pbVar4[0xf] = 0;
        }
        if (DAT_00b19acc != 0) {
          iVar3 = FUN_0072be50();
          if (iVar3 == 3) {
            DAT_00b19acc = 0;
          }
          *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *pbVar4 + 0x10;
        }
        pbVar4[0xc] = 0;
        pbVar4[0xd] = 0;
        pbVar4[0xe] = 0;
        pbVar4[0xf] = 0;
        FUN_006ca4a0();
        in_ECX = in_stack_00005d0d;
      }
    }
    if (DAT_00b19acc != 0) {
      iVar3 = FUN_0072be50();
      if (iVar3 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x1c) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar3 = FUN_0072be50();
      if (iVar3 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x20) + 4;
    }
    return 1;
  }
  return 0;
}



// ?ResolveLoad@GStream@@UAEXXZ @ 0x006ca490

void _ResolveLoad_GStream__UAEXXZ(void)

{
  FUN_006c9ca0(0);
  return;
}



