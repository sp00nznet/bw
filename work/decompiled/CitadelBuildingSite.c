// Decompiled functions for class: CitadelBuildingSite
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetSaveType@CitadelBuildingSite@@UAEIXZ @ 0x00435820

undefined4 _GetSaveType_CitadelBuildingSite__UAEIXZ(void)

{
  return 0x5d;
}



// ?GetDebugText@CitadelBuildingSite@@UAEPADXZ @ 0x00435830

char * _GetDebugText_CitadelBuildingSite__UAEPADXZ(void)

{
  return s_CitadelBuildingSite__008fc00c;
}



// ?ToBeDeleted@CitadelBuildingSite@@UAEXH@Z @ 0x004358b0

void _ToBeDeleted_CitadelBuildingSite__UAEXH_Z(undefined4 param_1)

{
  int iVar1;
  int *in_ECX;
  int iVar2;
  int *piVar3;
  
  piVar3 = in_ECX + 0x191;
  iVar2 = 6;
  do {
    if ((int *)*piVar3 != (int *)0x0) {
      (**(code **)(*(int *)*piVar3 + 0x868))(0);
      iVar1 = (**(code **)(*(int *)*piVar3 + 0x94))(1,0,0);
      if ((iVar1 == 0) || ((*(uint *)(DAT_00c22ca4 + 0x14) & 0x8000) != 0)) {
        (**(code **)(*(int *)*piVar3 + 0xc))(param_1);
      }
      else {
        FUN_00617330();
      }
      (**(code **)(*in_ECX + 0x10c))(0);
    }
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  _ToBeDeleted_BuildingSite__UAEXH_Z(param_1);
  return;
}



// ?GetResource@CitadelBuildingSite@@UAEIW4RESOURCE_TYPE@@@Z @ 0x004359b0

int _GetResource_CitadelBuildingSite__UAEIW4RESOURCE_TYPE___Z(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = 0;
  piVar3 = (int *)(in_ECX + 0x644);
  iVar2 = 6;
  do {
    if ((int *)*piVar3 != (int *)0x0) {
      iVar1 = (**(code **)(*(int *)*piVar3 + 0x94))(param_1,0,0);
      iVar4 = iVar4 + iVar1;
    }
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return iVar4;
}



// ?AddResource@CitadelBuildingSite@@UAEIW4RESOURCE_TYPE@@IPAVGInterfaceStatus@@_NPBUMapCoords@@H@Z @ 0x004359f0

uint _AddResource_CitadelBuildingSite__UAEIW4RESOURCE_TYPE__IPAVGInterfaceStatus___NPBUMapCoords__H_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               int param_5)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  uint uVar3;
  
  uVar3 = 0;
  if (param_5 != 0) {
    piVar1 = (int *)(**(code **)(*in_ECX + 0x108))(param_5);
    if (piVar1 == (int *)0x0) {
      FUN_00435930();
      piVar1 = (int *)(**(code **)(*in_ECX + 0x108))(param_5);
      if (piVar1 == (int *)0x0) goto LAB_00435a40;
    }
    uVar3 = (**(code **)(*piVar1 + 0x8c))(param_1,param_2,param_4);
  }
LAB_00435a40:
  iVar2 = (**(code **)(*in_ECX + 0x48))();
  if (iVar2 != 0) {
    *(float *)(iVar2 + 0x708) = (float)uVar3 + *(float *)(iVar2 + 0x708);
  }
  return uVar3;
}



// ?RemoveResource@CitadelBuildingSite@@UAEIW4RESOURCE_TYPE@@IPAVGInterfaceStatus@@PA_N@Z @ 0x00435a80

int _RemoveResource_CitadelBuildingSite__UAEIW4RESOURCE_TYPE__IPAVGInterfaceStatus__PA_N_Z
              (undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  int *piVar4;
  
  if (param_3 != 0) {
    iVar1 = _RemoveResource_BuildingSite__UAEIW4RESOURCE_TYPE__IPAVGInterfaceStatus__PA_N_Z
                      (param_1,param_2,param_3,param_4);
    return iVar1;
  }
  iVar1 = 0;
  uVar3 = 0;
  piVar4 = (int *)(in_ECX + 0x644);
  do {
    if (param_2 == 0) {
      return iVar1;
    }
    if (((int *)*piVar4 != (int *)0x0) &&
       (iVar2 = (**(code **)(*(int *)*piVar4 + 0x2c))(), iVar2 == 1)) {
      iVar2 = (**(code **)(*(int *)*piVar4 + 0x90))(param_1,param_2,0);
      iVar1 = iVar1 + iVar2;
      param_2 = param_2 - iVar2;
    }
    uVar3 = uVar3 + 1;
    piVar4 = piVar4 + 1;
  } while (uVar3 < 6);
  return iVar1;
}



// ?GetResourcePosAndYAngle@CitadelBuildingSite@@UAEXIIPAM@Z @ 0x00435af0

void _GetResourcePosAndYAngle_CitadelBuildingSite__UAEXIIPAM_Z
               (undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  float10 fVar7;
  undefined1 auStack_c [12];
  
  piVar4 = (int *)FUN_00434490();
  (**(code **)(*piVar4 + 0x114))(param_3);
  fVar7 = (float10)FUN_0044eda0(param_3);
  iVar5 = FUN_00434490();
  uVar1 = *(undefined4 *)(iVar5 + 0x14);
  uVar2 = *(undefined4 *)(iVar5 + 0x18);
  uVar3 = *(undefined4 *)(iVar5 + 0x1c);
  uVar6 = FUN_006de5a0(auStack_c,(float)(fVar7 - (float10)1.1423974),0x41b00000);
  FUN_005c12d0(uVar6);
  *param_1 = uVar1;
  param_1[1] = uVar2;
  param_1[2] = uVar3;
  return;
}



// ?GetPileWood@CitadelBuildingSite@@UAEPAVPot@@ABUMapCoords@@@Z @ 0x00435b80

int _GetPileWood_CitadelBuildingSite__UAEPAVPot__ABUMapCoords___Z(float param_1)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  int iVar3;
  int *piVar4;
  int iVar5;
  
  iVar1 = (int)param_1;
  if (param_1 == 0.0) {
    return 0;
  }
  param_1 = 3.4028235e+38;
  iVar3 = 0;
  piVar4 = (int *)(in_ECX + 0x644);
  iVar5 = 6;
  do {
    if (*piVar4 != 0) {
      uVar2 = FUN_006de030(iVar1,*piVar4 + 0x14);
      if ((float)uVar2 < param_1) {
        iVar3 = *piVar4;
        param_1 = (float)uVar2;
      }
    }
    piVar4 = piVar4 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  return iVar3;
}



// ?IsLinkedToThisBuildingSite@CitadelBuildingSite@@UAE_NPAVPot@@@Z @ 0x00435c00

undefined4 _IsLinkedToThisBuildingSite_CitadelBuildingSite__UAE_NPAVPot___Z(int param_1)

{
  uint uVar1;
  int in_ECX;
  int *piVar2;
  
  uVar1 = 0;
  piVar2 = (int *)(in_ECX + 0x644);
  do {
    if (*piVar2 == param_1) {
      return 1;
    }
    uVar1 = uVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (uVar1 < 6);
  return 0;
}



// ?RemovePotFromStructure@CitadelBuildingSite@@UAEXPAVPotStructure@@@Z @ 0x00435c30

void _RemovePotFromStructure_CitadelBuildingSite__UAEXPAVPotStructure___Z(int param_1)

{
  int *piVar1;
  int in_ECX;
  int iVar2;
  
  piVar1 = (int *)(in_ECX + 0x644);
  iVar2 = 6;
  do {
    if (*piVar1 == param_1) {
      *piVar1 = 0;
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}



// ?Save@CitadelBuildingSite@@UAEIAAVGameOSFile@@@Z @ 0x00435c60

undefined4 _Save_CitadelBuildingSite__UAEIAAVGameOSFile___Z(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_BuildingSite__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    FUN_00531ff0(in_ECX + 0x644,6);
    return 1;
  }
  return 0;
}



// ?Load@CitadelBuildingSite@@UAEIAAVGameOSFile@@@Z @ 0x00435ca0

undefined4 _Load_CitadelBuildingSite__UAEIAAVGameOSFile___Z(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Load_BuildingSite__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    FUN_00532060(in_ECX + 0x644);
    return 1;
  }
  return 0;
}



// ?Process@CitadelBuildingSite@@UAEXXZ @ 0x00435ce0

void _Process_CitadelBuildingSite__UAEXXZ(void)

{
  int iVar1;
  int in_ECX;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)(in_ECX + 0x644);
  iVar3 = 6;
  do {
    if ((int *)*piVar2 != (int *)0x0) {
      iVar1 = (**(code **)(*(int *)*piVar2 + 0x2c))();
      if (iVar1 != 1) {
        *piVar2 = 0;
      }
    }
    piVar2 = piVar2 + 1;
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  return;
}



