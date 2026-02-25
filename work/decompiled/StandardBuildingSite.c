// Decompiled functions for class: StandardBuildingSite
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetNearestEdge@StandardBuildingSite@@UAEMMMPAH@Z @ 0x004348d0

void _GetNearestEdge_StandardBuildingSite__UAEMMMPAH_Z
               (float *param_1,int param_2,float *param_3,float *param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int *in_ECX;
  float10 fVar7;
  int *unaff_retaddr;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined1 auStack_10 [4];
  float fStack_c;
  float *pfStack_8;
  float fStack_4;
  
  if (param_2 != 1) {
    if (param_4 != (float *)0x0) {
      *param_4 = 0.0;
    }
    iVar5 = FUN_00434490();
    *param_1 = *(float *)(iVar5 + 0x14);
    param_1[1] = *(float *)(iVar5 + 0x18);
    param_1[2] = *(float *)(iVar5 + 0x1c);
    return;
  }
  piVar4 = (int *)FUN_00434490();
  iVar5 = (**(code **)(*piVar4 + 0x304))();
  if (iVar5 != 0) {
    fStack_24 = 9.0;
    fStack_20 = 0.0;
    fStack_1c = -50.0;
    iVar5 = FUN_00434490();
    iVar5 = *(int *)(iVar5 + 0x40);
    fVar3 = fStack_1c * *(float *)(iVar5 + 0x2c);
    fVar2 = fStack_1c * *(float *)(iVar5 + 0x30);
    fVar1 = fStack_24 * *(float *)(iVar5 + 0x18);
    fStack_1c = fStack_20 * *(float *)(iVar5 + 0x28) +
                fStack_24 * *(float *)(iVar5 + 0x1c) + fStack_1c * *(float *)(iVar5 + 0x34) +
                *(float *)(iVar5 + 0x40);
    fStack_24 = fStack_24 * *(float *)(iVar5 + 0x14) + fStack_20 * *(float *)(iVar5 + 0x20) + fVar3
                + *(float *)(iVar5 + 0x38);
    fStack_20 = fVar1 + fStack_20 * *(float *)(iVar5 + 0x24) + fVar2 + *(float *)(iVar5 + 0x3c);
    FUN_005bf830(&fStack_24);
    if (param_4 != (float *)0x0) {
      piVar4 = (int *)FUN_00434490();
      fVar7 = (float10)(**(code **)(*piVar4 + 0x508))();
      *param_4 = (float)fVar7;
    }
    *param_1 = fStack_c;
    param_1[1] = (float)pfStack_8;
    param_1[2] = fStack_4;
    return;
  }
  piVar4 = (int *)(**(code **)(*in_ECX + 0x108))(0);
  if (piVar4 != (int *)0x0) {
    if (param_3 != (float *)0x0) {
      fVar7 = (float10)(**(code **)(*piVar4 + 0x508))();
      *param_3 = (float)fVar7;
    }
    *unaff_retaddr = piVar4[5];
    unaff_retaddr[1] = piVar4[6];
    unaff_retaddr[2] = piVar4[7];
    return;
  }
  iVar5 = FUN_00434490();
  fStack_1c = *(float *)(iVar5 + 0x14);
  uStack_18 = *(undefined4 *)(iVar5 + 0x18);
  uStack_14 = *(undefined4 *)(iVar5 + 0x1c);
  piVar4 = (int *)FUN_00434490();
  uVar6 = (**(code **)(*piVar4 + 0x864))(auStack_10,&fStack_1c);
  FUN_006de3e0(uVar6);
  FUN_0067bcb0(0x3f490fdb,s_C__dev_black_BuildingSite_cpp_008fbfc4,0x2aa);
  piVar4 = (int *)FUN_00434490();
  uVar6 = (**(code **)(*piVar4 + 0x864))(&uStack_14);
  fVar7 = (float10)FUN_005c18d0(uVar6);
  uVar6 = FUN_006de5a0(&uStack_18,fStack_4,(float)(fVar7 + (float10)4.0));
  FUN_005c12d0(uVar6);
  if (param_1 != (float *)0x0) {
    *param_1 = fStack_4 - 3.1415927;
  }
  *pfStack_8 = fStack_24;
  pfStack_8[1] = fStack_20;
  pfStack_8[2] = fStack_1c;
  return;
}



// ?GetWoodForStats@StandardBuildingSite@@UAEIXZ @ 0x00434c90

void _GetWoodForStats_StandardBuildingSite__UAEIXZ(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x98))(1);
  return;
}



// ?GetRandomBuildPos@StandardBuildingSite@@UAEXPAVObject@@PAH@Z @ 0x00435490

undefined4
_GetRandomBuildPos_StandardBuildingSite__UAEXPAVObject__PAH_Z
          (undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  float10 fVar3;
  
  iVar1 = FUN_00434460(param_2 + 0x14);
  fVar2 = (float10)FUN_006de3e0(iVar1 + 0x14);
  fVar3 = (float10)FUN_0067bcb0(0x3fc90fdb,s_C__dev_black_BuildingSite_cpp_008fbfc4,0x36d);
  (**(code **)(*in_ECX + 0x120))
            (param_1,(float)((fVar3 - (float10)0.7853982) + (float10)(float)fVar2),0,param_3);
  return param_1;
}



// ?GetNearestEdge@StandardBuildingSite@@UAEMMMPAH@Z @ 0x004354f0

/* WARNING: Removing unreachable block (ram,0x00435596) */

undefined4 *
_GetNearestEdge_StandardBuildingSite__UAEMMMPAH_Z
          (undefined4 *param_1,float param_2,undefined4 param_3,uint *param_4)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (param_2 < -18.849556) {
LAB_0043559a:
    uVar1 = 0;
  }
  else {
    if (param_2 <= 18.849556) {
      for (; param_2 < 0.0; param_2 = param_2 + 6.2831855) {
      }
      for (; 6.2831855 < param_2; param_2 = param_2 - 6.2831855) {
      }
      if (param_2 == 0.0) goto LAB_0043559a;
    }
    uVar1 = __ftol();
    uVar1 = uVar1 & 0x7f;
    if (0x7f < uVar1) {
      uVar1 = 0x7f;
    }
  }
  if (param_4 != (uint *)0x0) {
    *param_4 = uVar1;
  }
  uVar2 = __ftol();
  uVar3 = __ftol();
  *param_1 = uVar2;
  param_1[1] = uVar3;
  param_1[2] = 0;
  return param_1;
}



// ?GetNextPosFromIndex@StandardBuildingSite@@UAEXPAH@Z @ 0x004355f0

undefined4 * _GetNextPosFromIndex_StandardBuildingSite__UAEXPAH_Z(undefined4 *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  float10 fVar6;
  
  iVar1 = FUN_00434460();
  if (iVar1 == 0) {
    *param_1 = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    return param_1;
  }
  piVar2 = (int *)FUN_00434460();
  fVar6 = (float10)(**(code **)(*piVar2 + 100))();
  FUN_0067bcb0((float)((float10)2.0 / (fVar6 * (float10)6.2831855 * (float10)0.0078125)) * 0.5,
               s_C__dev_black_BuildingSite_cpp_008fbfc4,0x3a8);
  iVar1 = __ftol();
  iVar3 = FUN_0067bc90(2,s_C__dev_black_BuildingSite_cpp_008fbfc4,0x3a9);
  iVar1 = *param_2 + ((-(uint)(iVar3 != 0) & 2) - 1) * iVar1;
  if (iVar1 < 0x80) {
    if (iVar1 < 0) {
      iVar1 = iVar1 + 0x80;
    }
  }
  else {
    iVar1 = iVar1 + -0x80;
  }
  if (param_2 != (int *)0x0) {
    *param_2 = iVar1;
  }
  uVar4 = __ftol();
  uVar5 = __ftol();
  *param_1 = uVar4;
  param_1[1] = uVar5;
  param_1[2] = 0;
  return param_1;
}



// ?GetPileWood@StandardBuildingSite@@UAEPAVPot@@ABUMapCoords@@@Z @ 0x00435d60

undefined4 _GetPileWood_StandardBuildingSite__UAEPAVPot__ABUMapCoords___Z(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x644);
}



// ?SetPileWood@StandardBuildingSite@@UAEXPAVPot@@@Z @ 0x00435d70

void _SetPileWood_StandardBuildingSite__UAEXPAVPot___Z(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x644) = param_1;
  return;
}



// ?GetSaveType@StandardBuildingSite@@UAEIXZ @ 0x00435d80

undefined4 _GetSaveType_StandardBuildingSite__UAEIXZ(void)

{
  return 0x5c;
}



// ?GetDebugText@StandardBuildingSite@@UAEPADXZ @ 0x00435d90

char * _GetDebugText_StandardBuildingSite__UAEPADXZ(void)

{
  return s_StandardBuildingSite__008fc04c;
}



// ?CreatePileWood@StandardBuildingSite@@UAEXXZ @ 0x00435de0

void _CreatePileWood_StandardBuildingSite__UAEXXZ(void)

{
  int iVar1;
  int *in_ECX;
  undefined4 uVar2;
  TypeDescriptor *pTStack_20;
  undefined1 auStack_10 [16];
  
  pTStack_20 = &StandardBuildingSite::RTTI_Type_Descriptor;
  iVar1 = FUN_007344da();
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*in_ECX + 0x108))();
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*in_ECX + 0x2c))();
      if (iVar1 != 0) {
        pTStack_20 = (TypeDescriptor *)&stack0xffffffec;
        uVar2 = 0xffffffff;
        (**(code **)(*in_ECX + 0x114))(auStack_10,1,0xffffffff);
        iVar1 = *in_ECX;
        uVar2 = FUN_00434460(0,0,uVar2,0x3f800000,1);
        uVar2 = FUN_00616c40(&pTStack_20,&DAT_00c6df64,0,uVar2);
        (**(code **)(iVar1 + 0x10c))(uVar2);
      }
    }
  }
  return;
}



// ?RemovePotFromStructure@StandardBuildingSite@@UAEXPAVPotStructure@@@Z @ 0x00435e80

void _RemovePotFromStructure_StandardBuildingSite__UAEXPAVPotStructure___Z(void)

{
  int iVar1;
  int *in_ECX;
  int unaff_retaddr;
  
  iVar1 = (**(code **)(*in_ECX + 0x108))(0);
  if (iVar1 == unaff_retaddr) {
    (**(code **)(*in_ECX + 0x10c))(0);
  }
  return;
}



// ?IsLinkedToThisBuildingSite@StandardBuildingSite@@UAE_NPAVPot@@@Z @ 0x00435eb0

bool _IsLinkedToThisBuildingSite_StandardBuildingSite__UAE_NPAVPot___Z(int param_1)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0x644) == param_1;
}



// ?Save@StandardBuildingSite@@UAEIAAVGameOSFile@@@Z @ 0x00435ed0

undefined4 _Save_StandardBuildingSite__UAEIAAVGameOSFile___Z(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_BuildingSite__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x644));
    return 1;
  }
  return 0;
}



// ?Load@StandardBuildingSite@@UAEIAAVGameOSFile@@@Z @ 0x00435f10

undefined4 _Load_StandardBuildingSite__UAEIAAVGameOSFile___Z(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Load_BuildingSite__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    FUN_00531f30(in_ECX + 0x644);
    return 1;
  }
  return 0;
}



// ?Process@StandardBuildingSite@@UAEXXZ @ 0x00435f50

void _Process_StandardBuildingSite__UAEXXZ(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x644) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(in_ECX + 0x644) + 0x2c))();
    if (iVar1 != 1) {
      *(undefined4 *)(in_ECX + 0x644) = 0;
    }
  }
  return;
}



