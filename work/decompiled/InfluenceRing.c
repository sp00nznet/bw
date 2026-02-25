// Decompiled functions for class: InfluenceRing
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetScriptObjectType@InfluenceRing@@UAEIXZ @ 0x00418130

undefined4 _GetScriptObjectType_InfluenceRing__UAEIXZ(void)

{
  return 0xe;
}



// ?SetPlayer@InfluenceRing@@UAEXPAVGPlayer@@@Z @ 0x0052fae0

void _SetPlayer_InfluenceRing__UAEXPAVGPlayer___Z(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x34) = param_1;
  return;
}



// ?GetText@InfluenceRing@@UAEPBDXZ @ 0x0052faf0

char * _GetText_InfluenceRing__UAEPBDXZ(void)

{
  return s_Influence_Ring_00b1a610;
}



// ?GetSaveType@InfluenceRing@@UAEIXZ @ 0x0052fb10

undefined4 _GetSaveType_InfluenceRing__UAEIXZ(void)

{
  return 0x49;
}



// ?GetDebugText@InfluenceRing@@UAEPADXZ @ 0x0052fb20

char * _GetDebugText_InfluenceRing__UAEPADXZ(void)

{
  return s_InfluenceRing__00b1a620;
}



// ?ToBeDeleted@InfluenceRing@@UAEXH@Z @ 0x0058e3b0

void _ToBeDeleted_InfluenceRing__UAEXH_Z(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  iVar2 = DAT_00c22ca4;
  iVar3 = *(int *)(DAT_00c22ca4 + 0x201d08);
  if (iVar3 == in_ECX) {
    *(int *)(DAT_00c22ca4 + 0x201d08) = *(int *)(in_ECX + 0x40);
  }
  else {
    if (iVar3 == 0) goto LAB_0058e3f8;
    while (iVar1 = *(int *)(iVar3 + 0x40), iVar1 != in_ECX) {
      iVar3 = iVar1;
      if (iVar1 == 0) {
        _ToBeDeleted_GameThingWithPos__UAEXH_Z(param_1);
        return;
      }
    }
    *(undefined4 *)(iVar3 + 0x40) = *(undefined4 *)(in_ECX + 0x40);
  }
  *(int *)(iVar2 + 0x201d0c) = *(int *)(iVar2 + 0x201d0c) + -1;
  *(undefined4 *)(in_ECX + 0x40) = 0;
LAB_0058e3f8:
  _ToBeDeleted_GameThingWithPos__UAEXH_Z(param_1);
  return;
}



// ?Save@InfluenceRing@@UAEIAAVGameOSFile@@@Z @ 0x0058e6c0

undefined4 _Save_InfluenceRing__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = _Save_GameThingWithPos__UAEXPAUGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    uVar2 = FUN_00430450(0,&Base::RTTI_Type_Descriptor,&GameThingWithPos::RTTI_Type_Descriptor,0);
    uVar2 = FUN_007344da(uVar2);
    FUN_00531bc0(uVar2);
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x34));
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x38),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x38) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90((byte *)(in_ECX + 0x3c),4,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x3c) + 4;
      }
    }
    return 1;
  }
  return 0;
}



// ?Load@InfluenceRing@@UAEIAAVGameOSFile@@@Z @ 0x0058e7a0

undefined4 _Load_InfluenceRing__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = param_1;
  iVar2 = _Load_GameThingWithPos__QAEIAAVGameOSFile___Z(param_1);
  if (iVar2 != 0) {
    FUN_00531f30(&param_1);
    FUN_00430480(param_1);
    FUN_00531f30(in_ECX + 0x34);
    if (DAT_00b19acc != 0) {
      iVar2 = FUN_0072be50((byte *)(in_ECX + 0x38),4,0,unaff_EBX,unaff_EDI,unaff_ESI);
      if (iVar2 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x38) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar2 = FUN_0072be50();
      if (iVar2 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x3c) + 4;
    }
    return 1;
  }
  return 0;
}



