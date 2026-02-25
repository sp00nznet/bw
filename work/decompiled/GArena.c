// Decompiled functions for class: GArena
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetRadius@GArena@@UAEMXZ @ 0x0041eff0

float10 _GetRadius_GArena__UAEMXZ(void)

{
  int in_ECX;
  
  return (float10)*(float *)(in_ECX + 0x30);
}



// ?GetText@GArena@@UAEPBDXZ @ 0x0041f000

char * _GetText_GArena__UAEPBDXZ(void)

{
  return s_ff__Arena_008f8378 + 4;
}



// ?GetSaveType@GArena@@UAEIXZ @ 0x0041f010

undefined4 _GetSaveType_GArena__UAEIXZ(void)

{
  return 0x41;
}



// ?GetDebugText@GArena@@UAEPADXZ @ 0x0041f020

char * _GetDebugText_GArena__UAEPADXZ(void)

{
  return s_Arena__008f8384;
}



// ?ToBeDeleted@GArena@@UAEXH@Z @ 0x0041f120

void _ToBeDeleted_GArena__UAEXH_Z(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  iVar3 = DAT_00c22ca4;
  iVar1 = *(int *)(DAT_00c22ca4 + 0x201d38);
  if (iVar1 == in_ECX) {
    *(int *)(DAT_00c22ca4 + 0x201d38) = *(int *)(in_ECX + 0x48);
  }
  else {
    do {
      iVar2 = iVar1;
      if (iVar2 == 0) goto LAB_0041f15f;
      iVar1 = *(int *)(iVar2 + 0x48);
    } while (*(int *)(iVar2 + 0x48) != in_ECX);
    *(undefined4 *)(iVar2 + 0x48) = *(undefined4 *)(in_ECX + 0x48);
  }
  *(int *)(iVar3 + 0x201d3c) = *(int *)(iVar3 + 0x201d3c) + -1;
  *(undefined4 *)(in_ECX + 0x48) = 0;
LAB_0041f15f:
  FUN_0041f300();
  iVar1 = *(int *)(in_ECX + 0x2c);
  if (iVar1 != 0) {
    FUN_0041eda0();
    FUN_007290de(iVar1);
    *(undefined4 *)(in_ECX + 0x2c) = 0;
  }
  FUN_0067f9a0();
  _ToBeDeleted_GameThingWithPos__UAEXH_Z(param_1);
  return;
}



// ?Save@GArena@@UAEIAAVGameOSFile@@@Z @ 0x0041f710

undefined4 _Save_GArena__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_GameThingWithPos__UAEXPAUGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x28),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x28) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90((byte *)(in_ECX + 0x30),4,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x30) + 4;
        if (DAT_00b19ac8 != 0) {
          iVar1 = FUN_0072be90((byte *)(in_ECX + 0x34),4,0);
          if (iVar1 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x34) + 4;
        }
      }
    }
    FUN_00531ff0(in_ECX + 0x38,2);
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x44));
    return 1;
  }
  return 0;
}



// ?Load@GArena@@UAEIAAVGameOSFile@@@Z @ 0x0041f810

undefined4 _Load_GArena__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Load_GameThingWithPos__QAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x28),4,0,unaff_EDI,unaff_ESI,unaff_EBX);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x28) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x30) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x34) + 4;
    }
    FUN_00532060();
    FUN_00531f30();
    return 1;
  }
  return 0;
}



