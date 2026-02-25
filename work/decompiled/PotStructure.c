// Decompiled functions for class: PotStructure
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?SetMultiMapFixed@PotStructure@@UAEXPAVMultiMapFixed@@@Z @ 0x0052e920

void _SetMultiMapFixed_PotStructure__UAEXPAVMultiMapFixed___Z(byte param_1)

{
  int in_ECX;
  
  *(byte *)(in_ECX + 0x74) = (param_1 & 1) << 4 | *(byte *)(in_ECX + 0x74) & 0xef;
  return;
}



// ?SetPlayer@PotStructure@@UAEXPAVGPlayer@@@Z @ 0x0052e9f0

void _SetPlayer_PotStructure__UAEXPAVGPlayer___Z(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x7c) = param_1;
  return;
}



// ?CanBeThrownByPlayer@PotStructure@@UAEIXZ @ 0x0052ea10

bool _CanBeThrownByPlayer_PotStructure__UAEIXZ(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0x70) != 0;
}



// ?SetSize@PotStructure@@UAEXXZ @ 0x006171b0

void _SetSize_PotStructure__UAEXXZ(void)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  
  iVar1 = *in_ECX;
  fVar2 = (float10)FUN_006171d0();
  (**(code **)(iVar1 + 0x124))((float)fVar2);
  return;
}



// ?ToBeDeleted@PotStructure@@UAEXH@Z @ 0x00617630

void _ToBeDeleted_PotStructure__UAEXH_Z(undefined4 param_1)

{
  FUN_00617650();
  _ToBeDeleted_Pot__UAEXH_Z(param_1);
  return;
}



// ?JustRemoveResource@PotStructure@@UAEIW4RESOURCE_TYPE@@IPA_N@Z @ 0x00617680

undefined4
_JustRemoveResource_PotStructure__UAEIW4RESOURCE_TYPE__IPA_N_Z
          (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int *in_ECX;
  
  uVar1 = _JustRemoveResource_Pot__UAEIW4RESOURCE_TYPE__IPA_N_Z(param_1,param_2,param_3);
  if (in_ECX[0x1c] == 0) {
    if (in_ECX[0x1e] == 0) {
      (**(code **)(*in_ECX + 0xc))(0);
      return uVar1;
    }
  }
  else {
    (**(code **)(*in_ECX + 0x85c))();
  }
  return uVar1;
}



// ?SetMultiMapFixed@PotStructure@@UAEXPAVMultiMapFixed@@@Z @ 0x006176d0

undefined4 _SetMultiMapFixed_PotStructure__UAEXPAVMultiMapFixed___Z(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x78) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(in_ECX + 0x78) + 0x2c))();
    if (iVar1 != 0) {
      return *(undefined4 *)(in_ECX + 0x78);
    }
    *(undefined4 *)(in_ECX + 0x78) = 0;
  }
  return 0;
}



// ?IsResourceStore@PotStructure@@UAE_NW4RESOURCE_TYPE@@@Z @ 0x00617700

undefined4 _IsResourceStore_PotStructure__UAE_NW4RESOURCE_TYPE___Z(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x860))();
  if (piVar1 == (int *)0x0) {
    uVar3 = _ValidForLockedSelectProcess_Fixed__UAE_NPAVGInterfaceStatus___Z(param_1);
    return uVar3;
  }
  iVar2 = (**(code **)(*piVar1 + 0x680))(param_1);
  if (iVar2 != 0) {
    iVar2 = (**(code **)(*in_ECX + 0x690))();
    if ((param_1 == iVar2) || (param_1 == -2)) {
      return 1;
    }
  }
  return 0;
}



// ?IsPartOfStructure@PotStructure@@UAE_NXZ @ 0x00618500

void _IsPartOfStructure_PotStructure__UAE_NXZ(void)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  int *in_ECX;
  float10 fVar10;
  float10 fVar11;
  
  fVar10 = (float10)(**(code **)(*in_ECX + 0x86c))();
  fVar11 = (float10)(**(code **)(*in_ECX + 0x42c))();
  fVar11 = ((float10)(float)fVar10 - (float10)1.0) * fVar11;
  in_ECX[7] = (int)(float)fVar11;
  in_ECX[0x22] = (int)(float)fVar11;
  in_ECX[0x29] = in_ECX[0x24];
  in_ECX[0x28] = in_ECX[0x21];
  in_ECX[0x23] = 0;
  in_ECX[0x27] = 0x3f800000;
  in_ECX[0x26] = 0;
  FUN_00759970();
  fVar3 = (float)in_ECX[0x22];
  fVar4 = (float)in_ECX[0x28];
  fVar5 = (float)in_ECX[0x29];
  fVar6 = (float)in_ECX[0x27];
  fVar7 = (float)in_ECX[0x23];
  fVar8 = (float)in_ECX[0x29];
  FUN_004151c0();
  in_ECX[0x2a] = 0;
  in_ECX[0x2c] = (int)((fVar3 - fVar4) - fVar5 * fVar6);
  in_ECX[0x2b] = (int)(fVar7 - fVar8);
  fVar10 = (float10)(**(code **)(*in_ECX + 0x120))();
  fVar3 = (float)fVar10;
  fVar10 = (float10)(**(code **)(*in_ECX + 0x508))();
  fVar4 = (float)fVar10;
  fVar5 = (float)in_ECX[7];
  iVar9 = in_ECX[0x10];
  fVar10 = (float10)FUN_00760fd0();
  iVar1 = in_ECX[5];
  iVar2 = in_ECX[6];
  if (fVar4 == 0.0) {
    if (fVar3 == 1.0) {
      FUN_004022b0();
    }
    else {
      FUN_004f5940(fVar3);
      FUN_004022f0();
    }
  }
  else if (fVar3 == 1.0) {
    FUN_00402280();
    *(float *)(iVar9 + 0x38) = (float)iVar1 * 0.00015258789;
    *(float *)(iVar9 + 0x3c) = (float)(fVar10 + (float10)fVar5);
    *(float *)(iVar9 + 0x40) = (float)iVar2 * 0.00015258789;
    FUN_004f5f10(fVar4);
  }
  else {
    *(undefined4 *)(iVar9 + 0x40) = 0;
    *(undefined4 *)(iVar9 + 0x3c) = 0;
    *(undefined4 *)(iVar9 + 0x38) = 0;
    *(undefined4 *)(iVar9 + 0x30) = 0;
    *(undefined4 *)(iVar9 + 0x2c) = 0;
    *(undefined4 *)(iVar9 + 0x28) = 0;
    *(undefined4 *)(iVar9 + 0x20) = 0;
    *(undefined4 *)(iVar9 + 0x1c) = 0;
    *(undefined4 *)(iVar9 + 0x18) = 0;
    *(float *)(iVar9 + 0x34) = fVar3;
    *(float *)(iVar9 + 0x14) = fVar3;
    *(float *)(iVar9 + 0x24) = fVar3;
    *(float *)(iVar9 + 0x38) = (float)iVar1 * 0.00015258789 + *(float *)(iVar9 + 0x38);
    *(float *)(iVar9 + 0x3c) = (float)(fVar10 + (float10)fVar5) + *(float *)(iVar9 + 0x3c);
    *(float *)(iVar9 + 0x40) = (float)iVar2 * 0.00015258789 + *(float *)(iVar9 + 0x40);
    FUN_004f5f10(fVar4);
  }
  *(float *)(iVar9 + 0x44) = fVar3;
  *(float *)(iVar9 + 0x48) = fVar4;
  return;
}



// ?AddResource@PotStructure@@UAEIW4RESOURCE_TYPE@@IPAVGInterfaceStatus@@_NPBUMapCoords@@H@Z @ 0x00618920

void _AddResource_PotStructure__UAEIW4RESOURCE_TYPE__IPAVGInterfaceStatus___NPBUMapCoords__H_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x860))();
  if (piVar1 == (int *)0x0) {
    (**(code **)(*in_ECX + 0x8c))(param_1,param_2,param_4);
    return;
  }
  if ((int *)piVar1[0x1d] != (int *)0x0) {
    iVar2 = (**(code **)(*(int *)piVar1[0x1d] + 0x11c))();
    if (iVar2 != 0) {
      (**(code **)(*(int *)piVar1[0x1d] + 0x9c))(param_1,param_2,param_3,param_4,param_5,param_6);
      return;
    }
  }
  (**(code **)(*piVar1 + 0x9c))(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}



// ?RemoveResource@PotStructure@@UAEIW4RESOURCE_TYPE@@IPAVGInterfaceStatus@@PA_N@Z @ 0x006189c0

uint _RemoveResource_PotStructure__UAEIW4RESOURCE_TYPE__IPAVGInterfaceStatus__PA_N_Z
               (undefined4 param_1,uint param_2,undefined4 param_3,undefined1 *param_4)

{
  undefined1 uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int *in_ECX;
  uint uVar5;
  
  piVar2 = (int *)(**(code **)(*in_ECX + 0x860))();
  if ((piVar2 != (int *)0x0) && ((int *)piVar2[0x1d] != (int *)0x0)) {
    iVar3 = (**(code **)(*(int *)piVar2[0x1d] + 0x11c))();
    if (iVar3 != 0) {
      uVar4 = (**(code **)(*(int *)piVar2[0x1d] + 0xa0))(param_1,param_2,param_3,param_4);
      return uVar4;
    }
  }
  if (param_4 != (undefined1 *)0x0) {
    uVar1 = (**(code **)(*in_ECX + 0x4a4))();
    *param_4 = uVar1;
  }
  if (piVar2 == (int *)0x0) {
    uVar4 = 0;
  }
  else {
    uVar4 = (**(code **)(*piVar2 + 0x8ec))(param_1);
  }
  uVar5 = param_2;
  if (0 < (int)uVar4) {
    if ((int)param_2 <= (int)uVar4) {
      uVar4 = param_2;
    }
    uVar5 = param_2 - uVar4;
  }
  if (uVar5 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = (**(code **)(*in_ECX + 0x90))(param_1,uVar5,param_4);
  }
  if (piVar2 != (int *)0x0) {
    if (uVar4 != 0) {
      (**(code **)(*piVar2 + 0x8e8))(param_1,uVar4,param_3,param_4);
    }
    if (uVar4 < param_2) {
      iVar3 = (**(code **)(*piVar2 + 0xa0))(param_1,param_2 - uVar4,param_3,param_4);
      uVar4 = uVar4 + iVar3;
    }
  }
  return uVar4;
}



// ?GetResource@PotStructure@@UAEIW4RESOURCE_TYPE@@@Z @ 0x00618ab0

void _GetResource_PotStructure__UAEIW4RESOURCE_TYPE___Z(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x860))();
  if (piVar1 != (int *)0x0) {
    if ((int *)piVar1[0x1d] != (int *)0x0) {
      iVar2 = (**(code **)(*(int *)piVar1[0x1d] + 0x11c))();
      if (iVar2 != 0) goto LAB_00618aea;
    }
    (**(code **)(*piVar1 + 0x98))(param_1);
    return;
  }
LAB_00618aea:
  (**(code **)(*in_ECX + 0x94))(param_1,0,0);
  return;
}



// ?GetTown@PotStructure@@UAEPAVTown@@XZ @ 0x00618b10

undefined4 _GetTown_PotStructure__UAEPAVTown__XZ(void)

{
  int *piVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x860))();
  if (piVar1 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00618b20. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar2 = (**(code **)(*piVar1 + 0x48))();
    return uVar2;
  }
  return 0;
}



// ?GetPlayer@PotStructure@@UAEPAVGPlayer@@XZ @ 0x00618de0

int _GetPlayer_PotStructure__UAEPAVGPlayer__XZ(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x78) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00618deb. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (**(code **)(**(int **)(in_ECX + 0x78) + 0x1c))();
    return iVar1;
  }
  iVar1 = *(int *)(in_ECX + 0x7c);
  if (iVar1 == 0) {
    iVar1 = DAT_00c22ca4 + 0x18 + (uint)*(byte *)(DAT_00c22ca4 + 0x201b17) * 0x278;
  }
  return iVar1;
}



