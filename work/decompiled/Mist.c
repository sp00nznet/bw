// Decompiled functions for class: Mist
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetSaveType@Mist@@UAEIXZ @ 0x00440b30

undefined4 _GetSaveType_Mist__UAEIXZ(void)

{
  return 0x48;
}



// ?GetCreatureBeliefType@Mist@@UAEIXZ @ 0x0052e6b0

undefined4 _GetCreatureBeliefType_Mist__UAEIXZ(void)

{
  return 0x12;
}



// ?GetText@Mist@@UAEPBDXZ @ 0x0052faa0

undefined * _GetText_Mist__UAEPBDXZ(void)

{
  return &DAT_00b1a600;
}



// ?GetDebugText@Mist@@UAEPADXZ @ 0x0052fab0

char * _GetDebugText_Mist__UAEPADXZ(void)

{
  return s_Mist__00b1a608;
}



// ?ToBeDeleted@Mist@@UAEXH@Z @ 0x005c1a10

void _ToBeDeleted_Mist__UAEXH_Z(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x28) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x28) + 4))();
    *(undefined4 *)(in_ECX + 0x28) = 0;
  }
  iVar2 = DAT_00c22ca4;
  iVar3 = *(int *)(DAT_00c22ca4 + 0x201ce0);
  if (iVar3 == in_ECX) {
    *(undefined4 *)(DAT_00c22ca4 + 0x201ce0) = *(undefined4 *)(in_ECX + 0x50);
  }
  else {
    if (iVar3 == 0) goto LAB_005c1a74;
    while (iVar1 = *(int *)(iVar3 + 0x50), iVar1 != in_ECX) {
      iVar3 = iVar1;
      if (iVar1 == 0) {
        _ToBeDeleted_GameThingWithPos__UAEXH_Z(param_1);
        return;
      }
    }
    *(undefined4 *)(iVar3 + 0x50) = *(undefined4 *)(in_ECX + 0x50);
  }
  *(int *)(iVar2 + 0x201ce4) = *(int *)(iVar2 + 0x201ce4) + -1;
  *(undefined4 *)(in_ECX + 0x50) = 0;
LAB_005c1a74:
  _ToBeDeleted_GameThingWithPos__UAEXH_Z(param_1);
  return;
}



// ?GetDistanceFromObject@Mist@@UAEMPBUMapCoords@@@Z @ 0x005c1d70

float10 _GetDistanceFromObject_Mist__UAEMPBUMapCoords___Z(undefined4 param_1)

{
  int in_ECX;
  float10 fVar1;
  float10 fVar2;
  
  fVar1 = (float10)FUN_006de0a0(in_ECX + 0x14,param_1);
  fVar2 = (float10)FUN_005c1d20();
  return (float10)(float)fVar1 - fVar2;
}



// ?GetScriptObjectType@Mist@@UAEIXZ @ 0x005c1eb0

undefined4 _GetScriptObjectType_Mist__UAEIXZ(void)

{
  return 0x1d;
}



// ?Save@Mist@@UAEIAAVGameOSFile@@@Z @ 0x005c1ec0

undefined4 _Save_Mist__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_GameThingWithPos__UAEXPAUGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x2c),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x2c) + 4;
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
    return 1;
  }
  return 0;
}



// ?Load@Mist@@UAEIAAVGameOSFile@@@Z @ 0x005c1fb0

undefined4 _Load_Mist__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Load_GameThingWithPos__QAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x2c),4,0,unaff_EDI,unaff_ESI,unaff_EBX);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x2c) + 4;
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
    return 1;
  }
  return 0;
}



