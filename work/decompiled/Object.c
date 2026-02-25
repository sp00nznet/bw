// Decompiled functions for class: Object
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetCarriedTreeType@Object@@UAEIXZ @ 0x00401440

undefined4 _GetCarriedTreeType_Object__UAEIXZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x90);
}



// ?GetLife@Object@@UAEMXZ @ 0x00401460

undefined4 _GetLife_Object__UAEMXZ(void)

{
  return 3;
}



// ?GetYAngle@Object@@UAEMXZ @ 0x00401670

float10 _GetYAngle_Object__UAEMXZ(void)

{
  int in_ECX;
  
  return (float10)*(float *)(in_ECX + 0x4c);
}



// ?GetScale@Object@@UAEMXZ @ 0x00401680

float10 _GetScale_Object__UAEMXZ(void)

{
  int in_ECX;
  
  return (float10)*(float *)(in_ECX + 0x50);
}



// ?SetJustScale@Object@@UAEXM@Z @ 0x00401690

void _SetJustScale_Object__UAEXM_Z(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x50) = param_1;
  return;
}



// ?GetPtr@Object@@UAEPAV1@XZ @ 0x004016a0

void _GetPtr_Object__UAEPAV1_XZ(void)

{
  return;
}



// ?Get3DObjectForPSys@Object@@UAEPAVGame3DObject@@XZ @ 0x004016b0

undefined4 _Get3DObjectForPSys_Object__UAEPAVGame3DObject__XZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x40);
}



// ?GetLife@Object@@UAEMXZ @ 0x004016c0

float10 _GetLife_Object__UAEMXZ(void)

{
  int in_ECX;
  
  return (float10)*(float *)(in_ECX + 0x48);
}



// ?IsAlive@Object@@UAE_NXZ @ 0x004016d0

undefined4 _IsAlive_Object__UAE_NXZ(void)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  
  fVar2 = (float10)(**(code **)(*in_ECX + 0x11c))();
  if ((float10)0.0 < fVar2) {
    iVar1 = (**(code **)(*in_ECX + 0x2c))();
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}



// ?GetDetailMesh@Object@@UAEHH@Z @ 0x00401700

void _GetDetailMesh_Object__UAEHH_Z(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x608))();
  return;
}



// ?IsG3DObjectDrawnInHand@Object@@UAE_NXZ @ 0x00401710

undefined1 _IsG3DObjectDrawnInHand_Object__UAE_NXZ(void)

{
  return 1;
}



// ?GetVillagerHugRadius@Object@@UAEMXZ @ 0x00401720

float10 _GetVillagerHugRadius_Object__UAEMXZ(void)

{
  int *in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 100))();
  return fVar1 * (float10)1.05 + (float10)0.0005;
}



// ?GetFoodValue@Object@@UAEMW4FOOD_TYPE@@@Z @ 0x00401740

float10 _GetFoodValue_Object__UAEMW4FOOD_TYPE___Z(uint param_1)

{
  uint uVar1;
  int *in_ECX;
  
  uVar1 = (**(code **)(*in_ECX + 0x668))();
  if ((param_1 & uVar1) != 0) {
    return (float10)*(float *)(in_ECX[10] + 0x68);
  }
  return (float10)0.0;
}



// ?GetFoodType@Object@@UAE?AW4FOOD_TYPE@@XZ @ 0x00401770

void _GetFoodType_Object__UAE_AW4FOOD_TYPE__XZ(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00401775. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x28) + 0x38))();
  return;
}



// ?IsMoving@Object@@UAE_NXZ @ 0x00401780

undefined4 _IsMoving_Object__UAE_NXZ(void)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x14) == *(int *)(in_ECX + 0x2c)) &&
     (*(int *)(in_ECX + 0x18) == *(int *)(in_ECX + 0x30))) {
    return 0;
  }
  return 1;
}



// ?GetResourceType@Object@@UAE?AW4RESOURCE_TYPE@@XZ @ 0x004017a0

undefined4 _GetResourceType_Object__UAE_AW4RESOURCE_TYPE__XZ(void)

{
  return 0xffffffff;
}



// ?SetPoisonedResource@Object@@UAEXW4RESOURCE_TYPE@@H@Z @ 0x004017b0

void _SetPoisonedResource_Object__UAEXW4RESOURCE_TYPE__H_Z(void)

{
  return;
}



// ?SetDying@Object@@UAE_NXZ @ 0x004017e0

undefined4 _SetDying_Object__UAE_NXZ(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0xc))(0);
  return 1;
}



// ?GetDistanceFromObject@Object@@UAEMPAUMapCoords@@@Z @ 0x00401800

void _GetDistanceFromObject_Object__UAEMPAUMapCoords___Z(undefined4 param_1)

{
  _GetDistanceFromObject_GameThingWithPos__UBEMPAUMapCoords___Z(param_1);
  return;
}



// ?CanBeHelpedByCreature@Object@@UAE_NPAVCreature@@@Z @ 0x00401820

undefined4 _CanBeHelpedByCreature_Object__UAE_NPAVCreature___Z(void)

{
  return 1;
}



// ?RemoveFromHand@Object@@UAEIPAVGInterfaceStatus@@PBUMapCoords@@@Z @ 0x00401830

undefined4 _RemoveFromHand_Object__UAEIPAVGInterfaceStatus__PBUMapCoords___Z(void)

{
  return 0x17;
}



// ?InterfaceGiveObject@Object@@UAEIPAVGInterfaceStatus@@PAV1@@Z @ 0x00401850

undefined4 _InterfaceGiveObject_Object__UAEIPAVGInterfaceStatus__PAV1__Z(void)

{
  return 0x16;
}



// ?SelectFightThisToMapCoord@Object@@UAEIPAVGInterfaceStatus@@PBUMapCoords@@@Z @ 0x00401860

undefined4 _SelectFightThisToMapCoord_Object__UAEIPAVGInterfaceStatus__PBUMapCoords___Z(void)

{
  return 1;
}



// ?IsSuitableForCreatureAction@Object@@UAE_NXZ @ 0x00401870

undefined4 _IsSuitableForCreatureAction_Object__UAE_NXZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x28) + 0xc0);
}



// ?CanBeAttackedByCreature@Object@@UAE_NPAVCreature@@@Z @ 0x00401880

undefined4 _CanBeAttackedByCreature_Object__UAE_NPAVCreature___Z(int param_1)

{
  int in_ECX;
  
  if ((*(int *)(*(int *)(in_ECX + 0x28) + 0xc4) != 0) && (param_1 != in_ECX)) {
    return 1;
  }
  return 0;
}



// ?CanBePlayedWithByCreature@Object@@UAE_NPAVCreature@@@Z @ 0x004018a0

undefined4 _CanBePlayedWithByCreature_Object__UAE_NPAVCreature___Z(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x28) + 200);
}



// ?IsOnFire@Object@@UAE_NPAVCreature@@@Z @ 0x004018b0

void _IsOnFire_Object__UAE_NPAVCreature___Z(void)

{
  FUN_005ea110();
  return;
}



// ?SetHeadPos@Object@@UAEXPAUMapCoords@@@Z @ 0x004018c0

void _SetHeadPos_Object__UAEXPAUMapCoords___Z(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0x14);
  param_1[1] = *(undefined4 *)(in_ECX + 0x18);
  param_1[2] = *(undefined4 *)(in_ECX + 0x1c);
  return;
}



// ?GetText@Object@@UAEPBDXZ @ 0x004018e0

int _GetText_Object__UAEPBDXZ(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0x28) + 0x18;
}



// ?SetYJustAngle@Object@@UAEXM@Z @ 0x00401a40

void _SetYJustAngle_Object__UAEXM_Z(void)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  
  iVar1 = *in_ECX;
  fVar2 = (float10)(**(code **)(iVar1 + 0x11c))(0);
  (**(code **)(iVar1 + 0x5b8))((float)fVar2);
  return;
}



// ?GetHoldLoweringMultiplier@Object@@UAEMXZ @ 0x00401a80

undefined4 _GetHoldLoweringMultiplier_Object__UAEMXZ(float *param_1,undefined4 *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  undefined4 uVar5;
  int in_ECX;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if (*(int *)(in_ECX + 0x90) != 0) {
    cVar4 = FUN_006fb260(param_1,FUN_0067bd10);
    if (cVar4 != '\0') {
      FUN_00759970();
      fVar1 = *param_1;
      fVar2 = param_1[1];
      fVar3 = param_1[2];
      *param_1 = fStack_30 * fVar1 + fStack_24 * fVar2 + fStack_18 * fVar3 + fStack_c;
      param_1[1] = fStack_2c * fVar1 + fStack_20 * fVar2 + fStack_14 * fVar3 + fStack_8;
      param_1[2] = fStack_28 * fVar1 + fStack_1c * fVar2 + fStack_10 * fVar3 + fStack_4;
      *param_2 = 0;
      return 1;
    }
  }
  uVar5 = _GetPSysFireLocalRndFlamePos_Object__UAE_NPAULHPoint__PAH_Z(param_1,param_2);
  return uVar5;
}



// ?ProcessState@Object@@UAEIXZ @ 0x00402d00

undefined4 _ProcessState_Object__UAEIXZ(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  int *piVar4;
  
  FUN_005a5fa0();
  iVar2 = in_ECX[0x1d];
  iVar1 = (**(code **)(*in_ECX + 0x448))();
  if (iVar1 != 0) {
    if (iVar2 == 0) {
      iVar2 = (**(code **)(*in_ECX + 0x48))();
      if (iVar2 == 0) {
        return 0;
      }
      piVar4 = in_ECX;
      (**(code **)(*in_ECX + 0x48))();
      FUN_006ceac0(piVar4);
    }
    iVar2 = (**(code **)(*in_ECX + 0x890))();
    if (iVar2 != 1) {
      (**(code **)(*in_ECX + 0x5b0))(0x3f800000);
    }
    if ((int *)in_ECX[0x11] == (int *)0x0) {
      return 1;
    }
    (**(code **)(*(int *)in_ECX[0x11] + 0xc))(0);
    in_ECX[0x11] = 0;
    return 1;
  }
  if ((iVar2 != 0) && (*(int *)(iVar2 + 0x24) != 0)) {
    if (*(int *)(iVar2 + 0x20) == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(*(int *)(iVar2 + 0x20) + 4);
    }
    uVar3 = (**(code **)(*in_ECX + 0x1c))();
    if (iVar2 == 0) goto LAB_00402dc1;
    FUN_00684210();
    FUN_00683460(uVar3);
  }
  iVar2 = (**(code **)(*in_ECX + 0x2c))();
  if (iVar2 == 0) {
    return 1;
  }
LAB_00402dc1:
  (**(code **)(*in_ECX + 0xc))(0);
  return 1;
}



// ?GetProjectileSpeed@Object@@UAEMXZ @ 0x004031c0

undefined4 _GetProjectileSpeed_Object__UAEMXZ(void)

{
  float fVar1;
  int iVar2;
  int *in_ECX;
  float10 fVar3;
  
  _Process_MultiMapFixed__UAEIXZ();
  fVar3 = (float10)(**(code **)(*in_ECX + 0x89c))();
  if (fVar3 == (float10)0.0) {
    fVar3 = (float10)(**(code **)(*in_ECX + 0x8a0))();
    if (fVar3 == (float10)0.0) {
      iVar2 = (**(code **)(*in_ECX + 0x890))();
      if (iVar2 != 0) {
        iVar2 = (**(code **)(*in_ECX + 0x448))();
        if (iVar2 == 0) {
          iVar2 = (**(code **)(*in_ECX + 0x48))();
          if (iVar2 != 0) {
            iVar2 = (**(code **)(*in_ECX + 0x48))();
            if (*(int *)(iVar2 + 0x5f4) != 0) goto LAB_00403273;
          }
          fVar1 = (float)in_ECX[0x2c];
          in_ECX[0x2c] = (int)(fVar1 + 0.001);
          if (1.0 <= fVar1 + 0.001) {
            (**(code **)(*in_ECX + 0x5b8))(*(undefined4 *)(in_ECX[10] + 0x1b0),0);
            in_ECX[0x2c] = 0;
          }
        }
      }
    }
  }
LAB_00403273:
  if (*(byte *)((int)in_ECX + 0xb9) < 200) {
    *(byte *)((int)in_ECX + 0xb9) = *(byte *)((int)in_ECX + 0xb9) + 1;
  }
  return 1;
}



// ?GetTopPos@Object@@UAEMXZ @ 0x00403630

void _GetTopPos_Object__UAEMXZ(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00403635. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x28) + 0x2c))();
  return;
}



// ?DrawValue@Object@@UAEXHM@Z @ 0x00404430

float10 _DrawValue_Object__UAEXHM_Z(undefined4 param_1,undefined4 param_2)

{
  float fVar1;
  int iVar2;
  int *in_ECX;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  int *piVar6;
  
  fVar3 = (float10)(**(code **)(*in_ECX + 0x11c))();
  fVar4 = (float10)(**(code **)(*in_ECX + 0x894))();
  fVar5 = (float10)_ReduceLife_MultiMapFixed__UAEXMPAVGPlayer___Z(param_1,param_2);
  fVar1 = (float)fVar5;
  if ((float10)1.0 <= fVar5) goto LAB_0040454a;
  for (iVar2 = in_ECX[0x28]; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0xe4)) {
    FUN_006e2680();
  }
  if ((fVar4 < (float10)(float)fVar3) &&
     (fVar3 = (float10)(**(code **)(*in_ECX + 0x894))(), (float10)fVar1 <= fVar3)) {
    (**(code **)(*in_ECX + 0x918))(param_2);
    iVar2 = (**(code **)(*in_ECX + 0x920))();
    if (iVar2 != 0) {
      (**(code **)(*in_ECX + 0x48))();
      FUN_006d94c0();
    }
  }
  if (in_ECX[0x1d] == 0) {
    iVar2 = (**(code **)(*in_ECX + 0x48))();
    if (iVar2 != 0) {
      piVar6 = in_ECX;
      (**(code **)(*in_ECX + 0x48))();
      FUN_006ceac0(piVar6);
    }
    if (in_ECX[0x1d] != 0) goto LAB_0040450b;
  }
  else {
LAB_0040450b:
    iVar2 = (**(code **)(*in_ECX + 0x890))();
    if (iVar2 != 0) {
      *(float *)(in_ECX[0x1d] + 0x640) = fVar1 * 1.1 - 0.1;
    }
  }
  if (fVar1 == 0.0) {
    _AttitudeToCreatureEating_GameThingWithPos__UAEIXZ();
  }
LAB_0040454a:
  return (float10)fVar1;
}



// ?ScaffoldMoved@Object@@UAEXPAVScaffold@@@Z @ 0x00404560

float10 _ScaffoldMoved_Object__UAEXPAVScaffold___Z(undefined4 param_1)

{
  int *in_ECX;
  float10 fVar1;
  float10 fVar2;
  float10 fVar3;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 0x11c))();
  fVar2 = (float10)(**(code **)(*in_ECX + 0x894))();
  fVar3 = (float10)_IncreaseLife_Object__UAEXM_Z(param_1);
  if (((float10)(float)fVar1 <= fVar2) &&
     (fVar1 = (float10)(**(code **)(*in_ECX + 0x894))(), fVar1 < (float10)(float)fVar3)) {
    (**(code **)(*in_ECX + 0x91c))();
  }
  return (float10)(float)fVar3;
}



// ?IsARootedObject@Object@@UAE_NXZ @ 0x004048c0

undefined1 _IsARootedObject_Object__UAE_NXZ(void)

{
  return 0;
}



// ?IsScary@Object@@UAE_NXZ @ 0x004048d0

void _IsScary_Object__UAE_NXZ(int param_1,char param_2)

{
  int *piVar1;
  int *piVar2;
  float fVar3;
  char cVar4;
  int iVar5;
  int iVar6;
  float *pfVar7;
  int iVar8;
  int *in_ECX;
  float10 fVar9;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar8 = *(int *)(param_1 + 0x20);
  if (iVar8 == 0) {
    return;
  }
  piVar1 = *(int **)(iVar8 + 0x18);
  iVar5 = FUN_005f6180();
  if ((iVar5 != 0) && ((*(byte *)(param_1 + 0x1d8) & 4) != 0)) {
    FUN_004cb260(*(undefined4 *)(iVar8 + 0x24),0x10,in_ECX,0);
  }
  cVar4 = (**(code **)(*piVar1 + 0x7a8))();
  if (cVar4 == '\0') {
    return;
  }
  fVar3 = SQRT(*(float *)(iVar8 + 0x104) * *(float *)(iVar8 + 0x104) +
               *(float *)(iVar8 + 0x108) * *(float *)(iVar8 + 0x108) +
               *(float *)(iVar8 + 0x10c) * *(float *)(iVar8 + 0x10c)) * *(float *)(iVar8 + 0x15c);
  if (fVar3 <= 2000.0) {
    if (fVar3 <= 1000.0) {
      if (fVar3 <= 300.0) {
        return;
      }
      uStack_14 = 3;
    }
    else {
      uStack_14 = 2;
    }
    uStack_c = 0x16;
    uStack_8 = 0x10;
    pfVar7 = (float *)FUN_005c0400(&fStack_2c);
    fStack_20 = *pfVar7;
    fStack_1c = pfVar7[1];
    fStack_18 = pfVar7[2];
    iVar8 = FUN_0051f3d0();
    if (iVar8 == 0) {
      return;
    }
    FUN_0051f3d0();
    fStack_2c = DAT_00d78bd8;
    fStack_28 = DAT_00d78bdc;
    fStack_24 = DAT_00d78be0;
    uStack_10 = 0;
    uStack_4 = 0x4b;
    FUN_00424390(in_ECX,SQRT((DAT_00d78bd8 - fStack_20) * (DAT_00d78bd8 - fStack_20) +
                             (DAT_00d78bdc - fStack_1c) * (DAT_00d78bdc - fStack_1c) +
                             (DAT_00d78be0 - fStack_18) * (DAT_00d78be0 - fStack_18)),&uStack_14,0,
                 *(undefined4 *)(DAT_00bf4e68 + 0x3b0),0,0,0);
    return;
  }
  iVar6 = (**(code **)(*in_ECX + 0x890))();
  if (iVar6 == 0) goto LAB_00404b4c;
  fVar9 = (float10)(**(code **)(*in_ECX + 0x898))();
  piVar2 = (int *)in_ECX[0x24];
  if (piVar2 == (int *)0x0) {
    iVar6 = FUN_00746d70(0x28,s_C__dev_black_Abode_cpp_008f76dc,0x72f);
    if (iVar6 == 0) {
LAB_00404a44:
      iVar6 = 0;
    }
    else {
      iVar6 = FUN_00755810(in_ECX[0x10]);
    }
LAB_00404a46:
    in_ECX[0x24] = iVar6;
  }
  else {
    if (((float10)0.2 <= fVar9) && (fVar9 != (float10)1.0)) {
      if (piVar2 != (int *)0x0) {
        FUN_007559f0();
        FUN_007290de(piVar2);
      }
      iVar6 = FUN_00746d70(0x28,s_C__dev_black_Abode_cpp_008f76dc,0x72a);
      if (iVar6 == 0) goto LAB_00404a44;
      iVar6 = FUN_00755810(in_ECX[0x10]);
      goto LAB_00404a46;
    }
    if ((int *)*piVar2 == piVar1) {
      if ((1400.0 < fVar3) && (*(int **)(param_1 + 0x18) == in_ECX)) {
        *(int **)(param_1 + 0x1c) = piVar1;
        *(int **)(iVar8 + 0x1c) = in_ECX;
      }
    }
    else {
      *piVar2 = (int)piVar1;
    }
  }
  fStack_20 = *(float *)(iVar8 + 200);
  fStack_2c = *(float *)(iVar8 + 0x104) * 0.3;
  fStack_1c = *(float *)(iVar8 + 0xcc);
  fStack_18 = *(float *)(iVar8 + 0xd0);
  fStack_28 = *(float *)(iVar8 + 0x108) * 0.3;
  fStack_24 = *(float *)(iVar8 + 0x10c) * 0.3;
  if (param_2 != '\0') {
    FUN_006fb260(&fStack_20,&LAB_00404c80);
    fVar9 = (float10)FUN_0044f9b0();
    fStack_2c = (float)(fVar9 * (float10)fStack_2c);
    fStack_28 = (float)((float10)fStack_28 * fVar9);
    fStack_24 = (float)((float10)fStack_24 * fVar9);
  }
  FUN_00756620(&fStack_20,&fStack_2c,*(float *)(iVar8 + 0x178) + 0.7,in_ECX);
  fVar9 = (float10)FUN_00755b10();
  if (fVar9 == (float10)1.0) {
    iVar8 = in_ECX[0x24];
    if (iVar8 != 0) {
      FUN_007559f0();
      FUN_007290de(iVar8);
    }
    in_ECX[0x24] = 0;
    return;
  }
LAB_00404b4c:
  FUN_00404ca0(piVar1,iVar5);
  return;
}



// ?FightThisToObject@Object@@UAEIPAVGInterfaceStatus@@PAV1@@Z @ 0x00404e80

undefined4 _FightThisToObject_Object__UAEIPAVGInterfaceStatus__PAV1__Z(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int *in_ECX;
  LH_SamplePlayOptions aLStack_168 [4];
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  int iStack_144;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  
  DAT_00b6e52c = (**(code **)(*in_ECX + 0x48))();
  FUN_00783140();
  for (iVar5 = in_ECX[0x28]; iVar5 != 0; iVar5 = *(int *)(iVar5 + 0xe4)) {
    FUN_006e2680();
  }
  uVar4 = (**(code **)(*in_ECX + 0x8c4))();
  if ((uVar4 & 2) != 0) {
    iVar5 = FUN_00527d60();
    if ((param_1 == iVar5) && (iVar5 = FUN_005f80b0(), iVar5 != 0)) {
      FUN_00456f70(iVar5 + 0x78,0x39);
    }
    uVar1 = *(undefined4 *)(param_1 + 0xd0);
    uVar2 = *(undefined4 *)(param_1 + 200);
    uVar3 = *(undefined4 *)(param_1 + 0xcc);
    LH_SamplePlayOptions::LH_SamplePlayOptions(aLStack_168);
    uStack_164 = *(undefined4 *)(DAT_00bf4e68 + 0x3ac);
    iStack_144 = DAT_00b6e53c + 0x6e;
    DAT_00b6e53c = DAT_00b6e53c + 1;
    if (DAT_00b6e53c == 9) {
      DAT_00b6e53c = 0;
    }
    uStack_160 = 1;
    uStack_15c = 0;
    uStack_138 = uVar2;
    uStack_134 = uVar3;
    uStack_130 = uVar1;
    FUN_00423db0(aLStack_168);
    LH_SamplePlayOptions::~LH_SamplePlayOptions(aLStack_168);
  }
  return 1;
}



// ?GetYAngle@Object@@UAEMXZ @ 0x00404fc0

undefined4 _GetYAngle_Object__UAEMXZ(void)

{
  return 2;
}



// ?GetImpressiveValue@Object@@UAEMXZ @ 0x004057d0

int _GetImpressiveValue_Object__UAEMXZ(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  float10 fVar5;
  
  iVar1 = _GetDiscipleStateIfInteractedWith_MultiMapFixed__UAEIPAVGInterfaceStatus__PAVVillager___Z
                    (param_1,param_2);
  if ((iVar1 == 0) && (iVar2 = (**(code **)(*in_ECX + 0xd4))(), iVar2 != 0)) {
    iVar2 = (**(code **)(*param_1 + 0x1c))();
    iVar3 = (**(code **)(*in_ECX + 0x1c))();
    if (((iVar3 == iVar2) &&
        (((fVar5 = (float10)(**(code **)(*in_ECX + 0x89c))(), fVar5 < (float10)1.0 &&
          (piVar4 = (int *)FUN_006e1ce0(), piVar4 != in_ECX)) &&
         (iVar2 = (**(code **)(*in_ECX + 0x48))(), iVar2 != 0)))) &&
       (iVar2 = (**(code **)(*in_ECX + 0x48))(), *(int *)(iVar2 + 0x5f4) == 0)) {
      return 10;
    }
  }
  return iVar1;
}



// ?IsAPotFromABuildingSite@Object@@UAE_NXZ @ 0x004059f0

void _IsAPotFromABuildingSite_Object__UAE_NXZ(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  float10 fVar4;
  float10 fVar5;
  
  if (*(int *)(in_ECX[10] + 0x174) != 0) {
    fVar4 = (float10)FUN_005c18d0(param_1 + 0x14);
    fVar5 = (float10)(**(code **)(*in_ECX + 100))();
    if ((float10)(float)fVar4 < fVar5) {
      piVar1 = (int *)(**(code **)(*in_ECX + 0x48))();
      if ((piVar1 != (int *)0x0) && (piVar1[0x17d] == 0)) {
        iVar2 = (**(code **)(*piVar1 + 0x1c))();
        iVar3 = (**(code **)(*param_2 + 0x1c))();
        if (iVar2 == iVar3) {
          DAT_00b6e52c = piVar1;
          FUN_00783140();
        }
      }
    }
  }
  return;
}



// ?GetMapChild@Object@@UAEPAV1@PBUMapCell@@@Z @ 0x004140f0

undefined4 _GetMapChild_Object__UAEPAV1_PBUMapCell___Z(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x20) != 0) {
    iVar1 = FUN_007344da(*(int *)(in_ECX + 0x20),0,&Object::RTTI_Type_Descriptor,
                         &Object::RTTI_Type_Descriptor,0);
    if (iVar1 == 0) {
      return 0;
    }
  }
  return *(undefined4 *)(in_ECX + 0x20);
}



// ?SetMapChild@Object@@UAEXPAV1@PAUMapCell@@@Z @ 0x00414120

void _SetMapChild_Object__UAEXPAV1_PAUMapCell___Z(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x20) = param_1;
  return;
}



// ?GetInHandImmersionTexture@Object@@UAE?AW4IMMERSION_EFFECT_TYPE@@XZ @ 0x00418220

undefined4 _GetInHandImmersionTexture_Object__UAE_AW4IMMERSION_EFFECT_TYPE__XZ(void)

{
  return 0xffffffff;
}



// ?CanBeStrokedByCreature@Object@@UAE_NPAVCreature@@@Z @ 0x0041cc40

undefined4 _CanBeStrokedByCreature_Object__UAE_NPAVCreature___Z(undefined4 param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x2a4))(param_1);
  if ((iVar1 != 0) && ((*(byte *)((int)in_ECX + 0x25) & 0x20) == 0)) {
    return 1;
  }
  return 0;
}



// ?PhysicallyDestroysAbodes@Object@@UAEIXZ @ 0x0041ccc0

undefined4 _PhysicallyDestroysAbodes_Object__UAEIXZ(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (*(int *)(in_ECX + 0x28) + -0xb765f0) / 300;
  if ((-1 < iVar1) && ((iVar1 < 3 || (iVar1 == 0xf)))) {
    return 1;
  }
  return 0;
}



// ?GetBoundingSphere@Object@@UAEXPAULHPoint@@PAM@Z @ 0x0041ccf0

void _GetBoundingSphere_Object__UAEXPAULHPoint__PAM_Z(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x788))();
  FUN_00759e40(0x461c4000,&DAT_00be7740 + iVar1 * 6,0);
  uVar2 = FUN_0041cd30();
  FUN_0075a110(uVar2);
  return;
}



// ?GetFoodValue@Object@@UAEMW4FOOD_TYPE@@@Z @ 0x0041cde0

void _GetFoodValue_Object__UAEMW4FOOD_TYPE___Z(void)

{
  int iVar1;
  int *piVar2;
  int *in_ECX;
  float10 fVar3;
  float10 fVar4;
  
  (**(code **)(*in_ECX + 0x538))();
  (**(code **)(*in_ECX + 0x608))();
  (**(code **)(*(int *)in_ECX[0x10] + 0xf4))(0,0);
  fVar3 = (float10)(**(code **)(*in_ECX + 0x120))();
  fVar4 = (float10)(**(code **)(*in_ECX + 0x508))();
  FUN_00761280(in_ECX[0x10] + 0x50);
  FUN_0041dbb0((float)fVar4,(float)fVar3);
  (**(code **)(*(int *)in_ECX[0x10] + 0x88))();
  (**(code **)(*(int *)in_ECX[0x10] + 0x40))();
  (**(code **)(*(int *)in_ECX[0x10] + 0x80))();
  (**(code **)(*in_ECX + 0x850))();
  FUN_00504d40();
  if ((*(byte *)((int)in_ECX + 10) & 1) == 0) {
    (**(code **)(*in_ECX + 0x544))();
  }
  iVar1 = (**(code **)(*in_ECX + 0x890))();
  if (iVar1 == 0) {
    (**(code **)(*(int *)in_ECX[0x10] + 0x88))();
    (**(code **)(*(int *)in_ECX[0x10] + 0x80))();
  }
  (**(code **)(*(int *)in_ECX[0x10] + 0x180))();
  piVar2 = in_ECX + 0x23;
  iVar1 = 3;
  do {
    if (*piVar2 != 0) {
      FUN_0041d830(*piVar2);
    }
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = FUN_0041db70();
  if (iVar1 != 0) {
    (**(code **)(*(int *)in_ECX[0x10] + 0x40))();
    iVar1 = 0;
    do {
      piVar2 = (int *)FUN_005ecd90(0);
      in_ECX[iVar1 + 0x20] = (int)piVar2;
      (**(code **)(*piVar2 + 0xf4))(0,0);
      (**(code **)(*(int *)in_ECX[iVar1 + 0x20] + 0x58))();
      (**(code **)(*(int *)in_ECX[iVar1 + 0x20] + 0x20))(0,0x3f800000);
      FUN_0077cfc0(in_ECX[iVar1 + 0x20] + 0x38,0);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 2);
  }
  return;
}



// ?GetNearestEdgeToPos@Object@@UAEXPBUMapCoords@@@Z @ 0x0041d130

int _GetNearestEdgeToPos_Object__UAEXPBUMapCoords___Z(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *in_ECX;
  int iVar6;
  char *pcVar7;
  undefined1 auStack_19c [12];
  char acStack_190 [200];
  undefined1 auStack_c8 [100];
  undefined1 auStack_64 [100];
  
  iVar2 = FUN_0053eb80();
  if (iVar2 == 0) {
    return 0;
  }
  if (param_2 != 0) {
    FUN_005c13b0(auStack_19c,param_2);
  }
  (**(code **)(*in_ECX + 0x120))();
  (**(code **)(*in_ECX + 0x508))();
  uVar3 = __ftol();
  uVar3 = __ftol(uVar3);
  uVar4 = FUN_004fe4d0(auStack_64);
  uVar5 = FUN_005bf290(auStack_c8);
  uVar3 = FUN_006ad590(0x57,uVar5,uVar4,uVar3);
  FUN_00733e17(acStack_190,uVar3);
  iVar6 = -1;
  pcVar7 = acStack_190;
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  FUN_006b10c0();
  return iVar2;
}



// ?IsG3DObjectDrawnInHand@Object@@UAE_NXZ @ 0x0041d250

void _IsG3DObjectDrawnInHand_Object__UAE_NXZ(void)

{
  int iVar1;
  int *piVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int in_ECX;
  int *piVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int iStack_10;
  
  (**(code **)(**(int **)(in_ECX + 0x40) + 0x18c))();
  if (*(int *)(in_ECX + 0x7c) == 1) {
    uVar4 = (**(code **)(**(int **)(in_ECX + 0x40) + 0x184))();
    FUN_0041d230(uVar4);
  }
  (**(code **)(**(int **)(in_ECX + 0x40) + 0x188))();
  iVar1 = *(int *)(in_ECX + 0x40);
  puVar9 = (undefined4 *)(iVar1 + 0x50);
  FUN_0075fc20(iVar1 + 0x38,iVar1 + 0x4c,puVar9);
  uVar4 = FUN_0075d130(iVar1 + 0x38,*puVar9,iVar1 + 0x4c);
  *puVar9 = uVar4;
  switch((*(int *)(in_ECX + 0x28) + -0xb765f0) / 300) {
  case 0:
    FUN_005ed470();
    iVar1 = DAT_00d78910;
    if (DAT_00d78910 != 0) {
      piVar8 = (int *)(in_ECX + 0x80);
      iVar5 = 2;
      do {
        *(undefined4 *)(*piVar8 + 0x4c) = *(undefined4 *)(*(int *)(in_ECX + 0x40) + 0x4c);
        *(undefined4 *)(*piVar8 + 0x50) = *(undefined4 *)(*(int *)(in_ECX + 0x40) + 0x50);
        (**(code **)(*(int *)*piVar8 + 0x100))();
        piVar8 = piVar8 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    DAT_00d78910 = iVar1;
    return;
  case 1:
    FUN_005ed470();
    iVar1 = DAT_00d78910;
    iVar5 = FUN_0041d7b0();
    if (iVar5 != 0) {
      iStack_10 = 0;
      piVar8 = (int *)(in_ECX + 0x80);
      do {
        if (*piVar8 != 0) {
          piVar2 = *(int **)(in_ECX + 0x40);
          iVar6 = (**(code **)(*piVar2 + 0x18c))();
          iVar5 = (**(code **)(*piVar2 + 0x184))();
          iVar5 = *(int *)(iVar5 + 0x20);
          iVar7 = (**(code **)(*(int *)*piVar8 + 0xf8))();
          fVar3 = *(float *)(iVar7 + 0x28) + *(float *)(iVar7 + 0x28);
          puVar9 = (undefined4 *)(*(int *)(in_ECX + 0x40) + 0x14);
          puVar10 = (undefined4 *)(*piVar8 + 0x14);
          for (iVar7 = 0xc; iVar7 != 0; iVar7 = iVar7 + -1) {
            *puVar10 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar10 = puVar10 + 1;
          }
          iVar7 = (**(code **)(**(int **)(in_ECX + 0x40) + 0xf8))();
          *(float *)(*piVar8 + 0x3c) =
               ((*(float *)(iVar7 + 0x28) + *(float *)(iVar7 + 0x28) +
                ((float)iStack_10 * fVar3 - fVar3 * 7.15 * ((float)iVar6 / (float)(iVar5 + -3)))) -
               0.2) + *(float *)(*piVar8 + 0x3c);
          FUN_005ed470();
        }
        iStack_10 = iStack_10 + 1;
        piVar8 = piVar8 + 1;
      } while (iStack_10 < 3);
    }
    if (*(int *)(in_ECX + 0x7c) == 0) {
      iStack_10 = 0;
      piVar8 = (int *)(in_ECX + 0x80);
      do {
        if ((int *)*piVar8 != (int *)0x0) {
          iVar5 = (**(code **)(*(int *)*piVar8 + 0xf8))();
          fVar3 = (float)iStack_10 * *(float *)(iVar5 + 0x28);
          puVar9 = (undefined4 *)(*(int *)(in_ECX + 0x40) + 0x14);
          puVar10 = (undefined4 *)(*piVar8 + 0x14);
          for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
            *puVar10 = *puVar9;
            puVar9 = puVar9 + 1;
            puVar10 = puVar10 + 1;
          }
          iVar5 = (**(code **)(**(int **)(in_ECX + 0x40) + 0xf8))();
          *(float *)(*piVar8 + 0x3c) =
               ((*(float *)(iVar5 + 0x28) + *(float *)(iVar5 + 0x28) + fVar3 + fVar3) - 0.2) +
               *(float *)(*piVar8 + 0x3c);
          (**(code **)(*(int *)*piVar8 + 0x34))((int *)*piVar8 + 0xe);
          *(undefined4 *)(*piVar8 + 0x4c) = *(undefined4 *)(*(int *)(in_ECX + 0x40) + 0x4c);
          *(undefined4 *)(*piVar8 + 0x50) = *(undefined4 *)(*(int *)(in_ECX + 0x40) + 0x50);
          (**(code **)(*(int *)*piVar8 + 0x100))();
          if ((DAT_00d78910 != 0) && (FUN_0058a220(in_ECX,DAT_00d78914), DAT_00d788f0 != 0)) {
            iVar5 = *piVar8;
            uVar4 = 0;
            iVar6 = in_ECX;
            FUN_00527d30();
            FUN_00595eb0(iVar6,uVar4,iVar5);
          }
        }
        iStack_10 = iStack_10 + 1;
        piVar8 = piVar8 + 1;
      } while (iStack_10 < 3);
    }
    DAT_00d78910 = iVar1;
    return;
  case 2:
  case 0xf:
    FUN_005ed470();
  }
  return;
}



// ?IsFireMan@Object@@UAE_NXZ @ 0x0041d970

void _IsFireMan_Object__UAE_NXZ(undefined4 param_1,undefined4 param_2,code *param_3)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  float *pfVar4;
  float10 fVar5;
  uint uVar6;
  float fStack_58;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_38;
  float fStack_34;
  undefined1 auStack_30 [4];
  float fStack_2c;
  float fStack_10;
  float fStack_8;
  
  iVar2 = (**(code **)(*(int *)in_ECX[0x10] + 0xf8))();
  iVar3 = FUN_0041db70();
  if (iVar3 == 0) {
    (**(code **)(*in_ECX + 0x63c))(auStack_30);
    if (param_3 != (code *)0x0) {
      FUN_0041de00(fStack_10,fStack_8);
      (*param_3)();
      return;
    }
    fStack_48 = fStack_10;
    fStack_44 = fStack_8;
    FUN_007903c0(in_ECX,&fStack_48,*(float *)(iVar2 + 0x30) * 0.7,param_2);
    return;
  }
  fVar5 = (float10)(**(code **)(*in_ECX + 0x120))();
  fStack_50 = (float)(fVar5 * (float10)*(float *)(iVar2 + 0x24) * (float10)0.13333334);
  (**(code **)(*in_ECX + 0x63c))(auStack_30);
  uVar6 = 0;
  do {
    if ((uVar6 & 1) == 0) {
      fVar1 = -fStack_58;
    }
    else {
      fVar1 = fStack_58 + 0.0;
      fStack_58 = fVar1;
    }
    fStack_40 = fStack_34 * fVar1 + fStack_10;
    fStack_38 = fStack_2c * fVar1 + fStack_8;
    if (in_ECX[0x1f] == 1) {
      iVar2 = FUN_0041d7b0();
      if (iVar2 != 0) goto LAB_0041da79;
      if (4 < (int)uVar6) {
        if (param_3 != (code *)0x0) {
          FUN_0041de00(fStack_40,fStack_38);
          (*param_3)();
          goto LAB_0041dac2;
        }
        fStack_50 = fStack_40;
        fStack_4c = fStack_38;
        pfVar4 = &fStack_50;
        goto LAB_0041dab9;
      }
    }
    else {
LAB_0041da79:
      if (param_3 == (code *)0x0) {
        fStack_48 = fStack_40;
        fStack_44 = fStack_38;
        pfVar4 = &fStack_48;
LAB_0041dab9:
        FUN_007903c0(in_ECX,pfVar4,0x40200000,param_2);
      }
      else {
        FUN_0041de00(fStack_40,fStack_38);
        (*param_3)();
      }
    }
LAB_0041dac2:
    uVar6 = uVar6 + 1;
    if (0xe < (int)uVar6) {
      return;
    }
  } while( true );
}



// ?GetDiscipleStateIfInteractedWith@Object@@UAEIPAVGInterfaceStatus@@PAVVillager@@@Z @ 0x0041f6d0

undefined4 _GetDiscipleStateIfInteractedWith_Object__UAEIPAVGInterfaceStatus__PAVVillager___Z(void)

{
  return 0;
}



// ?GetFoodValue@Object@@UAEMW4FOOD_TYPE@@@Z @ 0x0041f990

void _GetFoodValue_Object__UAEMW4FOOD_TYPE___Z(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int *in_ECX;
  float10 fVar4;
  float fVar5;
  undefined4 uVar6;
  float fVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined1 auStack_c [12];
  
  _CallVirtualFunctionsForCreation_Object__UAEXABUMapCoords___Z(param_1);
  iVar1 = (**(code **)(*(int *)in_ECX[0x10] + 0xf8))();
  *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) | 0x4000;
  (**(code **)(*(int *)in_ECX[0x10] + 0x80))();
  iVar1 = (**(code **)(**(int **)(in_ECX[0x16] + 0x38 + in_ECX[0x18] * 4) + 0x1c))();
  if (iVar1 == 0) {
    param_1 = 0xffffffff;
    puVar2 = &param_1;
  }
  else {
    puVar2 = (undefined4 *)FUN_005f8990(&param_1);
  }
  uVar6 = *puVar2;
  if ((*(byte *)((int)in_ECX + 10) & 1) == 0) {
    iVar1 = FUN_00746d70(0x84,s_C__dev_black_Arena_cpp_008f838c,0x216);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      uVar9 = 8;
      uVar8 = 0x3f8ccccd;
      fVar4 = (float10)(**(code **)(*in_ECX + 0x120))(0x3f8ccccd,8);
      fVar7 = (float)(fVar4 * (float10)8.0);
      fVar4 = (float10)(**(code **)(*in_ECX + 0x120))(uVar6,fVar7);
      fVar5 = (float)(fVar4 * (float10)1.8);
      uVar3 = FUN_005c0400(auStack_c);
      iVar1 = FUN_0041ed40(uVar3,fVar5,uVar6,fVar7,uVar8,uVar9);
    }
    in_ECX[0x1a] = iVar1;
    if (iVar1 != 0) {
      *(undefined4 *)(iVar1 + 0x80) = 0x3ea8f5c3;
    }
  }
  return;
}



// ?GetMapChild@Object@@UAEPAV1@PBUMapCell@@@Z @ 0x0041fab0

void _GetMapChild_Object__UAEPAV1_PBUMapCell___Z(void)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  float10 fVar4;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  fVar4 = (float10)(**(code **)(*in_ECX + 0x120))();
  fVar4 = (float10)(**(code **)(*in_ECX + 0x508))((float)fVar4);
  piVar1 = (int *)FUN_005ecf60(in_ECX + 5,0,0xcb,(float)fVar4);
  in_ECX[0x10] = (int)piVar1;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x58))();
    (**(code **)(*(int *)in_ECX[0x10] + 0x78))();
    uStack_c = 0;
    uStack_8 = 0;
    uStack_4 = 0;
    FUN_0041fa90(&uStack_c);
    fVar4 = (float10)(**(code **)(*in_ECX + 0x120))(0xffffffff);
    uVar2 = (**(code **)(*in_ECX + 0x1c))((float)fVar4);
    iVar3 = FUN_006bdac0(&uStack_c,in_ECX[0x1b],uVar2);
    in_ECX[0x17] = iVar3;
    if (iVar3 != 0) {
      FUN_006be1e0(0);
    }
  }
  return;
}



// ?GetNearestEdgeToPos@Object@@UAEXPBUMapCoords@@@Z @ 0x004319d0

undefined4 _GetNearestEdgeToPos_Object__UAEXPBUMapCoords___Z(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x28) + 0x124);
}



// ?ResolveLoad@Object@@UAEXXZ @ 0x004319e0

undefined4 _ResolveLoad_Object__UAEXXZ(void)

{
  return 0x4d;
}



// ?GetCollideSoundType@Object@@UAE?AW4SOUND_COLLISION_TYPE@@XZ @ 0x00431b30

void _GetCollideSoundType_Object__UAE_AW4SOUND_COLLISION_TYPE__XZ(void)

{
  FUN_005ea110();
  return;
}



// ?GetInHandImmersionTexture@Object@@UAE?AW4IMMERSION_EFFECT_TYPE@@XZ @ 0x00431b40

int _GetInHandImmersionTexture_Object__UAE_AW4IMMERSION_EFFECT_TYPE__XZ
              (undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  int iVar4;
  char *pcVar5;
  float10 fVar6;
  undefined4 uVar7;
  double dVar8;
  char acStack_12c [200];
  undefined1 auStack_64 [100];
  
  iVar2 = FUN_0053eb80();
  if (iVar2 == 0) {
    return 0;
  }
  if (param_2 != 0) {
    FUN_005c13b0();
  }
  iVar4 = in_ECX[10];
  fVar6 = (float10)(**(code **)(*in_ECX + 0x120))();
  fVar6 = (float10)(**(code **)(*in_ECX + 0x508))((double)fVar6);
  iVar4 = (iVar4 + -0xb79f30) / 0x128;
  dVar8 = (double)fVar6;
  uVar7 = 0;
  uVar3 = FUN_005bf290(auStack_64);
  uVar3 = FUN_006ad590(0x3a,uVar3,iVar4,uVar7,dVar8);
  FUN_00733e17(acStack_12c,uVar3);
  iVar4 = -1;
  pcVar5 = acStack_12c;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_006b10c0();
  return iVar2;
}



// ?GetFoodType@Object@@UAE?AW4FOOD_TYPE@@XZ @ 0x00431c20

void _GetFoodType_Object__UAE_AW4FOOD_TYPE__XZ(void)

{
  int in_ECX;
  
  _CallVirtualFunctionsForCreation_MultiMapFixed__UAEXABUMapCoords___Z(in_ECX + 0x14);
  (**(code **)(**(int **)(in_ECX + 0x40) + 0x1e8))();
  (**(code **)(**(int **)(in_ECX + 0x40) + 0x58))();
  (**(code **)(**(int **)(in_ECX + 0x40) + 0x80))();
  (**(code **)(**(int **)(in_ECX + 0x40) + 0x90))();
  (**(code **)(**(int **)(in_ECX + 0x40) + 0x78))();
  return;
}



// ?IsABeliever@Object@@UAE_NXZ @ 0x00431c70

float10 _IsABeliever_Object__UAE_NXZ(void)

{
  int *in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 0x11c))();
  return fVar1 * (float10)(float)in_ECX[0x21];
}



// ?GetHandHelpCondition@Object@@UAEIXZ @ 0x00432110

byte _GetHandHelpCondition_Object__UAEIXZ(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x1c))();
  iVar2 = (**(code **)(*param_2 + 0x1c))();
  return (iVar1 != iVar2) - 1U & 2;
}



// ?SetJustScale@Object@@UAEXM@Z @ 0x004321b0

float10 _SetJustScale_Object__UAEXM_Z(void)

{
  int in_ECX;
  
  return (float10)*(float *)(in_ECX + 0x84);
}



// ?Get3DType@Object@@UAE?AW4LH3DObject__ObjectType@@XZ @ 0x00432240

void _Get3DType_Object__UAE_AW4LH3DObject__ObjectType__XZ(undefined4 param_1)

{
  _GetFoodType_Object__UAE_AW4FOOD_TYPE__XZ(param_1);
  return;
}



// ?GetNearestEdgeToPos@Object@@UAEXPBUMapCoords@@@Z @ 0x004322a0

undefined4 _GetNearestEdgeToPos_Object__UAEXPBUMapCoords___Z(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  char *pcVar4;
  float10 fVar5;
  float10 fVar6;
  double dVar7;
  double dVar8;
  char acStack_12c [200];
  undefined1 auStack_64 [100];
  
  iVar2 = FUN_0053eb80();
  if (iVar2 == 0) {
    return 0;
  }
  if (param_2 != 0) {
    FUN_005c13b0();
  }
  fVar5 = (float10)FUN_005ebcd0();
  fVar6 = (float10)(**(code **)(*in_ECX + 0x120))();
  fVar6 = (float10)(**(code **)(*in_ECX + 0x508))((double)fVar6);
  dVar8 = (double)fVar6;
  dVar7 = (double)(float)fVar5;
  uVar3 = FUN_005bf290(auStack_64);
  uVar3 = FUN_006ad590(0x49,uVar3,dVar7,dVar8);
  FUN_00733e17(acStack_12c,uVar3);
  iVar2 = -1;
  pcVar4 = acStack_12c;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  FUN_006b10c0();
  uVar3 = FUN_0053eb80();
  return uVar3;
}



// ?GetBeliefSprite@Object@@UAEPAVLH3DSprite@@XZ @ 0x0044ffe0

void _GetBeliefSprite_Object__UAEPAVLH3DSprite__XZ(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0) = param_1;
  return;
}



// ?SetLife@Object@@UAEXM@Z @ 0x0044fff0

undefined4 _SetLife_Object__UAEXM_Z(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xa0);
}



// ?GetNearestEdge@Object@@UAEXMM@Z @ 0x004526c0

int _GetNearestEdge_Object__UAEXMM_Z(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *in_ECX;
  char *pcVar6;
  undefined *puVar7;
  undefined1 auStack_138 [12];
  undefined1 auStack_12c [100];
  char acStack_c8 [200];
  
  iVar2 = FUN_0053eb80();
  if (iVar2 == 0) {
    return 0;
  }
  if (param_2 != 0) {
    FUN_005c13b0(auStack_138,param_2);
  }
  iVar3 = (**(code **)(*in_ECX + 0x114))();
  if ((iVar3 == 0) || ((*(byte *)(in_ECX + 0x16) & 2) != 0)) {
    if (in_ECX[0x25] != 0) {
      (**(code **)(*in_ECX + 0x120))();
      (**(code **)(*in_ECX + 0x508))();
      (**(code **)(*in_ECX + 0x1c))();
      iVar3 = FUN_005f7d20();
      puVar7 = (&PTR_s_PLAYER_ONE_00b228d4)[iVar3];
      iVar3 = in_ECX[10];
      uVar4 = __ftol();
      uVar4 = __ftol(uVar4);
      iVar3 = (iVar3 + -0xb7faf8) / 0x158;
      uVar5 = FUN_005bf290(auStack_12c);
      uVar4 = FUN_006ad590(0x14,*(undefined4 *)(in_ECX[0x25] + 0x5b4),uVar5,iVar3,puVar7,uVar4);
      FUN_00733e17(acStack_c8,uVar4);
    }
  }
  else {
    (**(code **)(*in_ECX + 0x120))();
    (**(code **)(*in_ECX + 0x508))();
    (**(code **)(*in_ECX + 0x1c))();
    iVar3 = FUN_005f7d20();
    puVar7 = (&PTR_s_PLAYER_ONE_00b228d4)[iVar3];
    iVar3 = in_ECX[10];
    uVar4 = __ftol();
    uVar4 = __ftol(uVar4);
    iVar3 = (iVar3 + -0xb7faf8) / 0x158;
    uVar5 = FUN_005bf290(auStack_12c);
    uVar4 = FUN_006ad590(0x13,uVar5,iVar3,puVar7,uVar4);
    FUN_00733e17(acStack_c8,uVar4);
  }
  iVar3 = -1;
  pcVar6 = acStack_c8;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_006b10c0();
  return iVar2;
}



// ?GetWoodValue@Object@@UAEMXZ @ 0x004528c0

void _GetWoodValue_Object__UAEMXZ(void)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int *in_ECX;
  float10 fVar5;
  float fStack_3c;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if (in_ECX[0x10] == 0) {
    fStack_3c = 6.351307e-39;
    (**(code **)(*in_ECX + 0x65c))();
    fStack_3c = 6.351317e-39;
    iVar2 = FUN_007677c0();
    in_ECX[0x10] = iVar2;
    fVar1 = (float)in_ECX[7];
    fStack_3c = 6.351345e-39;
    fVar5 = (float10)FUN_00760fd0();
    fStack_8 = (float)(fVar5 + (float10)fVar1);
    fStack_c = (float)in_ECX[5] * 0.00015258789;
    fStack_4 = (float)in_ECX[6] * 0.00015258789;
    fStack_3c = 6.351405e-39;
    fVar5 = (float10)(**(code **)(*in_ECX + 0x508))();
    fStack_3c = 6.351434e-39;
    FUN_00760fd0();
    fStack_3c = 1.0;
    FUN_0041dbb0((float)fVar5);
    iVar2 = *(int *)in_ECX[0x10];
    fStack_3c = 6.351527e-39;
    (**(code **)(*in_ECX + 0x1c))();
    fStack_3c = 6.351537e-39;
    fStack_3c = (float)FUN_005f7d20();
    fStack_3c = (float)FUN_005fa6b0();
    fVar5 = (float10)(**(code **)(*in_ECX + 0x880))();
    (**(code **)(iVar2 + 0x234))(&fStack_c,(float)fVar5);
    (**(code **)(*in_ECX + 0x850))();
    if (in_ECX[0x37] == 0) {
      iVar2 = FUN_004300a0(0x68,s_C__dev_black_CitadelHeart_cpp_008fd078,0x5e0);
      if (iVar2 == 0) {
        iVar2 = 0;
      }
      else {
        iVar2 = FUN_004540d0(in_ECX + 5,&DAT_00c62d18);
      }
      in_ECX[0x37] = iVar2;
    }
    piVar3 = (int *)FUN_007677c0();
    *(int **)(in_ECX[0x37] + 0x40) = piVar3;
    iVar2 = *piVar3;
    (**(code **)(*(int *)in_ECX[0x10] + 0x204))(0,0);
    (**(code **)(iVar2 + 0xf4))();
    fVar5 = (float10)(**(code **)(*in_ECX + 0x508))();
    fStack_3c = (float)fVar5;
    FUN_00760fd0();
    FUN_0041dbb0(fStack_3c,0x3f800000);
    (**(code **)(*piVar3 + 0x1e8))();
    *(int **)(in_ECX[0x37] + 0x54) = in_ECX;
    (**(code **)(*in_ECX + 0x544))();
    (**(code **)(*(int *)in_ECX[0x10] + 0xf8))();
    FUN_004402a0(in_ECX[0x10] + 0x38);
    iVar2 = FUN_00441ff0(2);
    in_ECX[0x38] = iVar2;
    if (iVar2 != 0) {
      *(undefined4 *)(iVar2 + 0x24) = 0;
    }
    in_ECX[0x36] = (int)DAT_00b7fc5c;
    DAT_00b7fc5c = in_ECX;
    iVar2 = FUN_0079fb70(in_ECX[0x10]);
    in_ECX[0x24] = iVar2;
    FUN_0044fe70();
    piVar3 = (int *)FUN_007677c0();
    in_ECX[0x2a] = (int)piVar3;
    (**(code **)(*piVar3 + 0xf4))(0,0);
    uVar4 = (**(code **)(*(int *)in_ECX[0x2a] + 0xf8))();
    fStack_3c = 2.350989e-38;
    FUN_00548b20(uVar4,&fStack_3c);
    (**(code **)(*(int *)in_ECX[0x2a] + 0x98))();
  }
  fStack_3c = 6.352247e-39;
  _Draw_PlannedMultiMapFixed__QAEXXZ();
  return;
}



// ?GetWorkingPos@Object@@UAEPAUMapCoords@@PAU2@PAV1@@Z @ 0x00452b90

void _GetWorkingPos_Object__UAEPAUMapCoords__PAU2_PAV1__Z(undefined4 *param_1)

{
  int in_ECX;
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(*(int *)(in_ECX + 0x40) + 0x14);
  for (iVar1 = 0xc; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}



// ?GetCollideSoundType@Object@@UAE?AW4SOUND_COLLISION_TYPE@@XZ @ 0x00453330

float10 _GetCollideSoundType_Object__UAE_AW4SOUND_COLLISION_TYPE__XZ(void)

{
  int *in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 100))();
  return fVar1 * (float10)0.33;
}



// ?IsARootedObject@Object@@UAE_NXZ @ 0x00453340

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _IsARootedObject_Object__UAE_NXZ(undefined4 param_1,int param_2,float param_3,code *param_4)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  float fStack_3c;
  int iStack_38;
  int iStack_30;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  uVar2 = param_3;
  FUN_00760fd0();
  fStack_24 = (float)in_ECX[5] * 0.00015258789;
  fStack_20 = (float)in_ECX[6] * 0.00015258789;
  fStack_4 = fStack_20;
  if (param_4 == (code *)0x0) {
    FUN_007903c0(in_ECX,&fStack_24,0x416dc28f,param_3);
  }
  else {
    FUN_005c9250(&fStack_24);
    (*param_4)();
  }
  iVar3 = (**(code **)(*in_ECX + 0x1c))();
  fVar1 = *(float *)(*(int *)(iVar3 + 0x60) + 8);
  if (-0.7 <= fVar1) {
    iStack_30 = 3;
    if (-0.3 <= fVar1) {
      iStack_30 = 4;
    }
  }
  else {
    iStack_30 = 2;
  }
  fVar4 = (float10)(**(code **)(*in_ECX + 0x508))();
  iStack_38 = 0;
  fStack_3c = (float)(fVar4 + (float10)_DAT_008fd000);
  do {
    iVar3 = 0;
    fVar4 = (float10)fsin((float10)fStack_3c);
    fVar5 = (float10)fcos((float10)fStack_3c);
    param_3 = 15.91;
    do {
      if (iStack_38 < 2) {
        if (iVar3 < 3) {
          fStack_1c = param_3 * (float)fVar5 + fStack_24;
          fStack_18 = param_3 * (float)fVar4 + fStack_20;
          param_3 = param_3 + 4.3;
        }
        else if (iVar3 == 3) {
          if (iStack_38 == 0) {
            fVar6 = (float10)0.06;
          }
          else {
            fVar6 = (float10)-0.06;
          }
          fVar7 = (float10)fcos(fVar6 + (float10)fStack_3c);
          fStack_1c = (float)(fVar7 * (float10)param_3 + (float10)fStack_24);
          fVar6 = (float10)fsin(fVar6 + (float10)fStack_3c);
          fStack_18 = (float)(fVar6 * (float10)param_3 + (float10)fStack_20);
          param_3 = param_3 + 2.15;
        }
        else if (iVar3 == 4) {
          if (iStack_38 == 0) {
            fVar6 = (float10)0.16;
          }
          else {
            fVar6 = (float10)-0.16;
          }
          fVar7 = (float10)fcos(fVar6 + (float10)fStack_3c);
          fStack_1c = (float)(fVar7 * (float10)param_3 + (float10)fStack_24);
          fVar6 = (float10)fsin(fVar6 + (float10)fStack_3c);
          fStack_18 = (float)(fVar6 * (float10)param_3 + (float10)fStack_20);
          param_3 = param_3 + 1.505;
        }
        else if (iVar3 == 5) {
          if (iStack_38 == 0) {
            fVar6 = (float10)0.27;
          }
          else {
            fVar6 = (float10)-0.27;
          }
          fVar7 = (float10)fcos(fVar6 + (float10)fStack_3c);
          fStack_1c = (float)(fVar7 * (float10)param_3 + (float10)fStack_24);
          fVar6 = (float10)fsin(fVar6 + (float10)fStack_3c);
          fStack_18 = (float)(fVar6 * (float10)param_3 + (float10)fStack_20);
        }
        if (param_4 == (code *)0x0) {
          FUN_007903c0(in_ECX,&fStack_1c,0x40175c29,uVar2);
        }
        else {
          FUN_005c9250(&fStack_1c);
          (*param_4)();
        }
      }
      else if (iVar3 < iStack_30) {
        fStack_14 = param_3 * (float)fVar5 + fStack_24;
        fStack_10 = param_3 * (float)fVar4 + fStack_20;
        if (param_4 == (code *)0x0) {
          FUN_007903c0(in_ECX,&fStack_14,0x40175c29,uVar2);
        }
        else {
          FUN_005c9250(&fStack_14);
          (*param_4)();
        }
        param_3 = param_3 + 4.3;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 6);
    if ((param_2 != 0) && (iStack_38 != 0)) {
      if ((iStack_38 + -1 < 6) &&
         ((in_ECX[0x20] != 0 && (*(int *)(in_ECX[0x20] + 0x34 + (iStack_38 + -1) * 4) != 0)))) {
        fVar4 = (float10)fcos((float10)fStack_3c + (float10)0.5);
        fStack_c = (float)(fVar4 * (float10)24.0 + (float10)fStack_24);
        fVar4 = (float10)fsin((float10)fStack_3c + (float10)0.5);
        fStack_8 = (float)(fVar4 * (float10)24.0 + (float10)fStack_20);
        if (param_4 == (code *)0x0) {
          FUN_007903c0(in_ECX,&fStack_c,0x41400000,uVar2);
        }
        else {
          FUN_005c9250(&fStack_c);
          (*param_4)();
        }
      }
    }
    iStack_38 = iStack_38 + 1;
    fStack_3c = fStack_3c + 0.8975979;
  } while (iStack_38 < 7);
  return;
}



// ?GetHeatCapacity@Object@@UAEMXZ @ 0x00453e80

int * _GetHeatCapacity_Object__UAEMXZ(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  int *piVar4;
  float10 fVar5;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x114))();
  (**(code **)(*piVar1 + 0x1c))();
  piVar1 = (int *)0x0;
  iVar2 = FUN_005fa1d0(0);
  if (iVar2 != 0) {
    do {
      piVar4 = (int *)0x0;
      while( true ) {
        if (piVar4 == (int *)0x0) {
          piVar4 = *(int **)(iVar2 + 0x74c);
        }
        else {
          piVar4 = (int *)piVar4[0x27];
        }
        if (piVar4 == (int *)0x0) break;
        iVar3 = (**(code **)(*piVar4 + 0x2c))();
        if ((((iVar3 == 1) &&
             (fVar5 = (float10)(**(code **)(*piVar4 + 0x11c))(), (float10)0.0 < fVar5)) &&
            (fVar5 = (float10)(**(code **)(*piVar4 + 0x880))(), (float10)0.0 < fVar5)) &&
           (iVar3 = (**(code **)(*piVar4 + 0x210))(), iVar3 == 0)) {
          fVar5 = (float10)(**(code **)(*piVar4 + 0x11c))();
          if ((float10)0.25 < fVar5) goto LAB_00453fc0;
          if (piVar1 == (int *)0x0) {
            piVar1 = piVar4;
          }
        }
      }
      iVar2 = FUN_005fa1d0(iVar2);
    } while (iVar2 != 0);
    if (piVar1 != (int *)0x0) {
      FUN_00453900(piVar1,param_2);
      return piVar1;
    }
  }
  iVar2 = FUN_005fa1d0(0);
  do {
    if (iVar2 == 0) {
      FUN_00453740(param_2);
      return in_ECX;
    }
    for (piVar4 = *(int **)(iVar2 + 0x760); piVar4 != (int *)0x0; piVar4 = (int *)piVar4[0x39]) {
      iVar3 = (**(code **)(*piVar4 + 0x2c))();
      if (iVar3 == 1) {
LAB_00453fc0:
        FUN_00453900(piVar4,param_2);
        return piVar4;
      }
    }
    iVar2 = FUN_005fa1d0(iVar2);
  } while( true );
}



// ?ApplySingleEffect@Object@@UAEXW4EFFECT_TYPE@@MPAVGameThing@@PBUMapCoords@@@Z @ 0x00453fe0

undefined4 _ApplySingleEffect_Object__UAEXW4EFFECT_TYPE__MPAVGameThing__PBUMapCoords___Z(void)

{
  FUN_00450e20();
  return 1;
}



// ?GetFOVHelpMessageSet@Object@@UAEIXZ @ 0x00453ff0

undefined4 _GetFOVHelpMessageSet_Object__UAEIXZ(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 in_ECX;
  
  iVar1 = FUN_004300a0(0x65c,s_C__dev_black_CitadelHeart_cpp_008fd078,0x922);
  if (iVar1 != 0) {
    uVar2 = FUN_00435870(in_ECX);
    return uVar2;
  }
  return 0;
}



// ?GetWoodValue@Object@@UAEMXZ @ 0x00454850

void _GetWoodValue_Object__UAEMXZ(undefined4 param_1)

{
  int in_ECX;
  
  _CallVirtualFunctionsForCreation_MultiMapFixed__UAEXABUMapCoords___Z(param_1);
  (**(code **)(**(int **)(in_ECX + 0x40) + 0x1e8))();
  return;
}



// ?GetHeatCapacity@Object@@UAEMXZ @ 0x00454870

int * _GetHeatCapacity_Object__UAEMXZ(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *in_ECX;
  float10 fVar4;
  
  iVar1 = (**(code **)(*in_ECX + 0x114))();
  if ((iVar1 != 0) && (piVar3 = *(int **)(iVar1 + 0x30), piVar3 != (int *)0x0)) {
    piVar2 = (int *)(**(code **)(*piVar3 + 0x5d8))(param_1,param_2);
    if (piVar2 == piVar3) {
      fVar4 = (float10)(**(code **)(*in_ECX + 0x11c))();
      if ((float10)0.0 < fVar4) {
        return in_ECX;
      }
    }
    return piVar2;
  }
  piVar3 = (int *)_GetActualObjectToEffect_Object__UAEPAXPAVGPlayer___N_Z(param_1,param_2);
  return piVar3;
}



// ?CanBePickedUpByCreature@Object@@UAE_NPAVCreature@@@Z @ 0x004c4ec0

undefined4 _CanBePickedUpByCreature_Object__UAE_NPAVCreature___Z(int *param_1)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int *in_ECX;
  
  if (param_1 != (int *)0x0) {
    iVar2 = (**(code **)(*param_1 + 0x1c))();
    if (iVar2 != 0) {
      iVar2 = (**(code **)(*param_1 + 0x1c))();
      if ((*(int *)(iVar2 + 0xf8) == 2) && ((*(byte *)((int)param_1 + 0x25) & 4) == 0)) {
        iVar2 = (**(code **)(*in_ECX + 0x448))();
        if (iVar2 != 0) {
          return 0;
        }
      }
    }
  }
  iVar2 = (**(code **)(*in_ECX + 0x800))();
  if (iVar2 != 0) {
    return 0;
  }
  iVar2 = (**(code **)(*in_ECX + 0x2c8))(0);
  if (iVar2 != 0) {
    piVar3 = (int *)FUN_007344da();
    if (piVar3 != (int *)0x0) {
      cVar1 = (**(code **)(*piVar3 + 0xb00))();
      if (cVar1 == '<') {
        iVar2 = (**(code **)(*piVar3 + 0x1c))();
        iVar4 = (**(code **)(*param_1 + 0x1c))();
        if (iVar2 == iVar4) {
          return 0;
        }
      }
    }
  }
  iVar2 = (**(code **)(*in_ECX + 0x178))();
  if ((iVar2 == 0) && (*(int **)(param_1[0x58] + 0x28) != in_ECX)) {
    return 0;
  }
  uVar5 = FUN_004c4e00(param_1);
  return uVar5;
}



// ?CanBeStrokedByCreature@Object@@UAE_NPAVCreature@@@Z @ 0x004c4fa0

undefined4 _CanBeStrokedByCreature_Object__UAE_NPAVCreature___Z(undefined4 param_1)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  
  fVar2 = (float10)(**(code **)(*in_ECX + 0x11c))();
  if (fVar2 < (float10)1.0) {
    iVar1 = (**(code **)(*in_ECX + 600))(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}



// ?CanBeInspectedByCreature@Object@@UAE_NPAVCreature@@@Z @ 0x004c4fe0

bool _CanBeInspectedByCreature_Object__UAE_NPAVCreature___Z(void)

{
  int in_ECX;
  
  return *(int *)(*(int *)(in_ECX + 0x28) + 0xcc) != 0;
}



// ?CanBeBroughtBackToCitadel@Object@@UAE_NPAVCreature@@@Z @ 0x004c5050

undefined4 _CanBeBroughtBackToCitadel_Object__UAE_NPAVCreature___Z(int param_1)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  
  iVar1 = (**(code **)(*in_ECX + 600))(param_1);
  if ((iVar1 != 0) && (*(int *)(in_ECX[10] + 0xd4) != 0)) {
    fVar2 = (float10)FUN_006de0a0(in_ECX + 5,
                                  *(int *)(*(int *)(*(int *)(param_1 + 0x164) + 0x1d484) + 0x30) +
                                  0x14);
    if ((float10)45.0 < fVar2) {
      return 1;
    }
  }
  return 0;
}



// ?CanBeStompedOnByCreature@Object@@UAE_NPAVCreature@@@Z @ 0x004c50b0

undefined4 _CanBeStompedOnByCreature_Object__UAE_NPAVCreature___Z(int param_1)

{
  float fVar1;
  int iVar2;
  int *in_ECX;
  float10 fVar3;
  
  iVar2 = (**(code **)(*in_ECX + 0x178))();
  if (iVar2 != 0) {
    fVar1 = *(float *)(*(int *)(*(int *)(param_1 + 0x160) + 0x58) + 0x90);
    fVar3 = (float10)(**(code **)(*in_ECX + 0x42c))();
    if (fVar3 < (float10)0.2 * (float10)(fVar1 * 15.0)) {
      return 1;
    }
  }
  return 0;
}



// ?CanBeThrownByCreature@Object@@UAE_NPAVCreature@@@Z @ 0x004c5190

undefined4 _CanBeThrownByCreature_Object__UAE_NPAVCreature___Z(void)

{
  int *in_ECX;
  float10 fVar1;
  float10 fVar2;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 0x42c))();
  fVar2 = (float10)FUN_004c51d0();
  if ((float10)(float)fVar1 < fVar2 * (float10)0.8) {
    return 1;
  }
  return 0;
}



// ?CanBePutInAStoragePit@Object@@UAE_NPAVCreature@@@Z @ 0x004c51e0

undefined4 _CanBePutInAStoragePit_Object__UAE_NPAVCreature___Z(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = FUN_005bfa00();
  piVar3 = *(int **)(iVar1 + 4);
  while( true ) {
    if (piVar3 == (int *)0x0) {
      return 1;
    }
    iVar2 = FUN_007344da(piVar3,0,&Object::RTTI_Type_Descriptor,&StoragePit::RTTI_Type_Descriptor,0)
    ;
    if (iVar2 != 0) break;
    piVar3 = (int *)(**(code **)(*piVar3 + 0x53c))(iVar1);
  }
  return 0;
}



// ?CanBePutInFoodPile@Object@@UAE_NPAVCreature@@@Z @ 0x004c5230

undefined4 _CanBePutInFoodPile_Object__UAE_NPAVCreature___Z(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x628))();
  if (((iVar1 != 0) && (0.0 < *(float *)(in_ECX[10] + 0x68))) && (*(int *)(in_ECX[10] + 0x10) != 2))
  {
    return 1;
  }
  return 0;
}



// ?CanBePutInWoodPile@Object@@UAE_NPAVCreature@@@Z @ 0x004c5270

undefined4 _CanBePutInWoodPile_Object__UAE_NPAVCreature___Z(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x628))();
  if (iVar1 != 0) {
    if (0.0 < (float)*(uint *)(in_ECX[10] + 0x6c)) {
      return 1;
    }
  }
  return 0;
}



// ?CanBePoodUponByCreature@Object@@UAE_NPAVCreature@@@Z @ 0x004c5350

undefined4 _CanBePoodUponByCreature_Object__UAE_NPAVCreature___Z(void)

{
  int *in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 0x42c))();
  if ((float10)1.5 < fVar1) {
    return 1;
  }
  return 0;
}



// ?CanBeKickedByCreature@Object@@UAE_NPAVCreature@@@Z @ 0x004c5740

undefined4 _CanBeKickedByCreature_Object__UAE_NPAVCreature___Z(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *in_ECX;
  float10 fVar3;
  float10 fVar4;
  
  if (((param_1 != (int *)0x0) && (iVar1 = FUN_004b29d0(), iVar1 != 0)) &&
     (piVar2 = (int *)FUN_004b2a50(), piVar2 == in_ECX)) {
    return 0;
  }
  iVar1 = (**(code **)(*(int *)in_ECX[10] + 0x2c))();
  if (iVar1 != 400) {
    iVar1 = (**(code **)(*in_ECX + 0x34))();
    if (iVar1 != 0) {
      return 1;
    }
    iVar1 = FUN_004b29d0();
    if ((iVar1 != 0) && (piVar2 = (int *)FUN_004b2a50(), piVar2 == in_ECX)) {
      return 0;
    }
    iVar1 = (**(code **)(*in_ECX + 0x7b0))();
    if ((iVar1 != 0) && ((*(byte *)((int)in_ECX + 0x25) & 0x10) == 0)) {
      fVar3 = (float10)(**(code **)(*in_ECX + 0x638))();
      fVar4 = (float10)(**(code **)(*param_1 + 0x638))();
      if (((float10)(float)fVar3 < fVar4 + fVar4) &&
         ((((*(ushort *)(in_ECX + 9) & 0x4000) == 0 && (*(int **)(param_1[0x58] + 0x28) != in_ECX))
          && ((*(ushort *)(in_ECX + 9) & 4) == 0)))) {
        return 1;
      }
    }
  }
  return 0;
}



// ?CanBeExaminedByCreature@Object@@UAE_NPAVCreature@@@Z @ 0x004c5810

undefined4 _CanBeExaminedByCreature_Object__UAE_NPAVCreature___Z(int *param_1)

{
  int *in_ECX;
  float10 fVar1;
  float10 fVar2;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 0x42c))();
  fVar2 = (float10)(**(code **)(*param_1 + 0x42c))();
  if ((float10)(float)fVar1 < fVar2 * (float10)0.25) {
    return 1;
  }
  return 0;
}



// ?CanBeEatenByCreature@Object@@UAE_NPAVCreature@@@Z @ 0x004c5cc0

void _CanBeEatenByCreature_Object__UAE_NPAVCreature___Z(undefined4 param_1)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 600))(param_1);
  return;
}



// ?GetImmersionTexture@Object@@UAE?AW4IMMERSION_EFFECT_TYPE@@XZ @ 0x004cf5d0

int _GetImmersionTexture_Object__UAE_AW4IMMERSION_EFFECT_TYPE__XZ(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *in_ECX;
  char *pcVar6;
  undefined1 auStack_138 [12];
  char acStack_12c [200];
  undefined1 auStack_64 [100];
  
  iVar2 = FUN_0053eb80();
  if (iVar2 == 0) {
    return 0;
  }
  if (param_2 != 0) {
    FUN_005c13b0(auStack_138,param_2);
  }
  iVar3 = (**(code **)(*in_ECX + 0x1c))();
  if (iVar3 == 0) {
    pcVar6 = s_No_player_00b0e274;
  }
  else {
    (**(code **)(*in_ECX + 0x1c))();
    iVar3 = FUN_005f7d20();
    pcVar6 = (&PTR_s_PLAYER_ONE_00b228d4)[iVar3];
  }
  (**(code **)(*in_ECX + 0x120))();
  (**(code **)(*in_ECX + 0x508))();
  iVar3 = in_ECX[10];
  uVar4 = __ftol(*(byte *)(in_ECX + 0x16) >> 1 & 1);
  uVar4 = __ftol(uVar4);
  iVar3 = (iVar3 + -0xbce788) / 0x144;
  uVar5 = FUN_005bf290(auStack_64);
  uVar4 = FUN_006ad590(0x15,uVar5,iVar3,pcVar6,uVar4);
  FUN_00733e17(acStack_12c,uVar4);
  iVar3 = -1;
  pcVar6 = acStack_12c;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_006b10c0();
  return iVar2;
}



// ?ScaffoldMoved@Object@@UAEXPAVScaffold@@@Z @ 0x004e9390

void _ScaffoldMoved_Object__UAEXPAVScaffold___Z(undefined4 param_1,undefined4 param_2)

{
  _DrawValue_Object__UAEXHM_Z(param_1,param_2);
  return;
}



// ?GetDrawRegion@Object@@UAEXPAULHRegion@@@Z @ 0x004edee0

void _GetDrawRegion_Object__UAEXPAULHRegion___Z(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  if ((*(byte *)(in_ECX + 0x98) & 0x10) != 0) {
    iVar2 = FUN_00746d70(0x44,s_C__dev_black_DeadTree_cpp_00b16690,0x25);
    if (iVar2 != 0) {
      FUN_0077fd80(*(undefined4 *)(in_ECX + 0x40),0x250);
    }
    *(ushort *)(in_ECX + 0x98) = *(ushort *)(in_ECX + 0x98) & 0xffef;
  }
  if (*(int *)(in_ECX + 0x44) != 0) {
    FUN_004f46e0();
    return;
  }
  iVar2 = *(int *)(in_ECX + 0x40);
  puVar1 = (undefined4 *)(iVar2 + 0x50);
  FUN_0075fc20(iVar2 + 0x38,iVar2 + 0x4c,puVar1);
  uVar3 = FUN_0075d130(iVar2 + 0x38,*puVar1,iVar2 + 0x4c);
  *puVar1 = uVar3;
  FUN_005ed470();
  return;
}



// ?ResolveLoad@Object@@UAEXXZ @ 0x004ee060

undefined4 _ResolveLoad_Object__UAEXXZ(void)

{
  return 0x70;
}



// ?ProcessBySpell@Object@@UAEIPAVSpell@@@Z @ 0x004ee460

float10 _ProcessBySpell_Object__UAEIPAVSpell___Z(void)

{
  int *in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 0x42c))();
  return fVar1 * (float10)0.35;
}



// ?ApplyUnlockProcess@Object@@UAEIPAVGInterfaceStatus@@@Z @ 0x004ee4f0

undefined4 _ApplyUnlockProcess_Object__UAEIPAVGInterfaceStatus___Z(int param_1,int *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int *in_ECX;
  float10 fVar5;
  float10 fVar6;
  LH_SamplePlayOptions aLStack_168 [4];
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_144;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  
  iVar4 = FUN_007344da(param_2,0,&Object::RTTI_Type_Descriptor,&WorshipTotem::RTTI_Type_Descriptor,0
                      );
  if (iVar4 != 0) {
    fVar5 = (float10)(**(code **)(*in_ECX + 0x5c0))();
    iVar4 = *(int *)(iVar4 + 0x100);
    fVar6 = (float10)(**(code **)(*in_ECX + 0x11c))();
    *(float *)(iVar4 + 0xf0) =
         (float)(fVar6 * (float10)(float)fVar5 + (float10)*(float *)(iVar4 + 0xf0));
    *(float *)(iVar4 + 0xf4) =
         (float)(fVar6 * (float10)(float)fVar5 + (float10)*(float *)(iVar4 + 0xf4));
    if (param_1 != 0) {
      uVar1 = *(undefined4 *)(param_1 + 200);
      uVar2 = *(undefined4 *)(param_1 + 0xcc);
      uVar3 = *(undefined4 *)(param_1 + 0xd0);
      LH_SamplePlayOptions::LH_SamplePlayOptions(aLStack_168);
      uStack_164 = *(undefined4 *)(DAT_00bf4e68 + 0x3ac);
      uStack_144 = 0xb3;
      uStack_160 = 1;
      uStack_15c = 0;
      uStack_138 = uVar1;
      uStack_134 = uVar2;
      uStack_130 = uVar3;
      FUN_00423db0(aLStack_168);
      LH_SamplePlayOptions::~LH_SamplePlayOptions(aLStack_168);
    }
    FUN_005a5fa0();
    (**(code **)(*in_ECX + 0xc))(0);
    return 3;
  }
  if (param_2 != (int *)0x0) {
    iVar4 = (**(code **)(*param_2 + 0x680))(1);
    if (iVar4 != 0) {
      iVar4 = (**(code **)(*param_2 + 0x684))();
      if (iVar4 != 0) {
        return 3;
      }
    }
  }
  return 0;
}



// ?ApplyOnlyAfterRecSystem@Object@@UAEIXZ @ 0x004ee660

undefined4
_ApplyOnlyAfterRecSystem_Object__UAEIXZ(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  
  piVar1 = (int *)FUN_005c11c0();
  if (piVar1 != (int *)0x0) {
    iVar3 = *piVar1;
    uVar2 = (**(code **)(*in_ECX + 0x690))();
    iVar3 = (**(code **)(iVar3 + 0x680))(uVar2);
    if (iVar3 != 0) {
      iVar3 = (**(code **)(*piVar1 + 0x684))();
      if (iVar3 != 0) {
        return 3;
      }
    }
  }
  uVar2 = _InterfaceValidToTap_Object__UAEIPAVGInterfaceStatus___Z(param_1,param_2,param_3);
  return uVar2;
}



// ?GetLandingPoint@Object@@UAE_NEPAULHPoint@@@Z @ 0x004ee700

undefined4 _GetLandingPoint_Object__UAE_NEPAULHPoint___Z(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = 0x196;
  if (*DAT_00d76c64 < 0x197) {
    iVar1 = 0;
  }
  iVar1 = DAT_00d76c64[iVar1 + 1];
  iVar2 = (**(code **)(**(int **)(in_ECX + 0x40) + 0xf8))();
  if (iVar2 == iVar1) {
    return 0x12;
  }
  return *(undefined4 *)(*(int *)(in_ECX + 0x28) + 0x48);
}



// ?IsLockedInInteract@Object@@UAE_NXZ @ 0x004ee8e0

void _IsLockedInInteract_Object__UAE_NXZ(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x120))();
  __ftol();
  return;
}



// ?GetNearestEdge@Object@@UAEXMM@Z @ 0x004ee9e0

undefined4 _GetNearestEdge_Object__UAEXMM_Z(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *in_ECX;
  char *pcVar5;
  float10 fVar6;
  undefined *puVar7;
  double dVar8;
  undefined1 auStack_138 [12];
  char acStack_12c [200];
  undefined1 auStack_64 [100];
  
  iVar2 = FUN_0053eb80();
  if (iVar2 == 0) {
    return 0;
  }
  if (param_2 != 0) {
    FUN_005c13b0(auStack_138,param_2);
  }
  iVar2 = (**(code **)(*in_ECX + 0x1c))();
  if (iVar2 != 0) {
    (**(code **)(*in_ECX + 0x1c))();
  }
  iVar2 = in_ECX[0x25];
  iVar3 = FUN_005f7d20();
  puVar7 = (&PTR_s_PLAYER_ONE_00b228d4)[iVar3];
  fVar6 = (float10)(**(code **)(*in_ECX + 0x50c))();
  fVar6 = (float10)(**(code **)(*in_ECX + 0x508))((double)fVar6);
  fVar6 = (float10)(**(code **)(*in_ECX + 0x504))((double)fVar6);
  fVar6 = (float10)(**(code **)(*in_ECX + 0x11c))((double)fVar6);
  iVar2 = (iVar2 + -0xcc4770) / 0x140;
  dVar8 = (double)fVar6;
  uVar4 = FUN_005bf290(auStack_64);
  uVar4 = FUN_006ad590(0x2b,uVar4,puVar7,iVar2,dVar8);
  FUN_00733e17(acStack_12c,uVar4);
  iVar2 = -1;
  pcVar5 = acStack_12c;
  do {
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_006b10c0();
  uVar4 = FUN_0053eb80();
  return uVar4;
}



// ?IsG3DObjectDrawnInHand@Object@@UAE_NXZ @ 0x004eeea0

void _IsG3DObjectDrawnInHand_Object__UAE_NXZ(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x44) == 0) {
    iVar2 = *(int *)(in_ECX + 0x40);
    puVar1 = (undefined4 *)(iVar2 + 0x50);
    FUN_0075fc20(iVar2 + 0x38,iVar2 + 0x4c,puVar1);
    uVar3 = FUN_0075d130(iVar2 + 0x38,*puVar1,iVar2 + 0x4c);
    *puVar1 = uVar3;
    FUN_005ed470();
  }
  else {
    FUN_004f46e0();
  }
  iVar2 = *(int *)(in_ECX + 0x40);
  puVar1 = (undefined4 *)(iVar2 + 0x50);
  FUN_0075fc20(iVar2 + 0x38,iVar2 + 0x4c,puVar1);
  uVar3 = FUN_0075d130(iVar2 + 0x38,*puVar1,iVar2 + 0x4c);
  *puVar1 = uVar3;
  FUN_005ed470();
  return;
}



// ?GetNearestEdgeOfObject@Object@@UAEXPAV1@@Z @ 0x004eef20

undefined4 _GetNearestEdgeOfObject_Object__UAEXPAV1__Z(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x40) + 0xf8))();
  iVar2 = (**(code **)(*DAT_00b7fa54 + 0xf8))();
  if (iVar1 == iVar2) {
    return 0;
  }
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x40) + 0xf8))();
  iVar2 = (**(code **)(*DAT_00b7fa58 + 0xf8))();
  if (iVar1 == iVar2) {
    return 1;
  }
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x40) + 0xf8))();
  iVar2 = (**(code **)(*DAT_00b7fa5c + 0xf8))();
  if (iVar1 == iVar2) {
    return 2;
  }
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x40) + 0xf8))();
  iVar2 = (**(code **)(*DAT_00b7fa60 + 0xf8))();
  if (iVar1 == iVar2) {
    return 3;
  }
  return *(undefined4 *)(*(int *)(in_ECX + 0x94) + 0x138);
}



// ?IsSpellSeedReturnPoint@Object@@UAE_NXZ @ 0x004eefd0

float10 _IsSpellSeedReturnPoint_Object__UAE_NXZ(void)

{
  float fVar1;
  int iVar2;
  int *in_ECX;
  float10 fVar3;
  
  fVar3 = (float10)(**(code **)(*in_ECX + 0x120))();
  fVar1 = (float)fVar3;
  iVar2 = in_ECX[0x25];
  fVar3 = (float10)(**(code **)(*in_ECX + 0x11c))();
  return fVar3 * (float10)*(int *)(iVar2 + 0x6c) * (float10)fVar1 * (float10)fVar1 * (float10)fVar1;
}



// ?GetWeight@Object@@UAEMXZ @ 0x004f2850

void _GetWeight_Object__UAEMXZ(void)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *in_ECX;
  uint uVar5;
  float10 extraout_ST0;
  float10 fVar6;
  float10 fVar7;
  int *piVar8;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  piVar8 = (int *)in_ECX[0x10];
  if ((*(char *)((int)in_ECX + 0xb6) == '\0') || (iVar2 = FUN_00528f30(), iVar2 == 0)) {
LAB_004f294d:
    (**(code **)(*piVar8 + 0x30))();
  }
  else {
    iVar2 = __ftol();
    fVar1 = (float)((extraout_ST0 - (float10)iVar2) + (float10)DAT_00b201cc);
    if (fVar1 <= 20.5) {
      if (3.0 <= fVar1) goto LAB_004f294d;
      iVar2 = __ftol();
    }
    else {
      iVar2 = __ftol();
    }
    if (iVar2 < 1) goto LAB_004f294d;
    __ftol();
    (**(code **)(*piVar8 + 0x30))();
  }
  _SetPlayer_GameThing__QAEXPAVGPlayer___Z(1);
  if (in_ECX[0x24] == 0) {
    _Draw_MultiMapFixed__UAEXXZ();
  }
  else {
    (**(code **)(*(int *)in_ECX[0x10] + 0xf8))();
    iVar2 = FUN_007bbeb0(in_ECX[0x10]);
    if (iVar2 != 0) {
      if (in_ECX[0x11] == 0) {
        iVar2 = in_ECX[0x24];
        *(undefined4 *)(iVar2 + 0x10) = 0xffffffff;
        *(undefined4 *)(iVar2 + 0x14) = 0;
      }
      else {
        uVar3 = FUN_006c6760();
        uVar4 = FUN_006c6850();
        iVar2 = in_ECX[0x24];
        *(undefined4 *)(iVar2 + 0x10) = uVar4;
        *(undefined4 *)(iVar2 + 0x14) = uVar3;
      }
      FUN_00756240(0,in_ECX[0x10] + 0x38);
      FUN_0058a220(in_ECX,DAT_00d78914);
      if (DAT_00d788f0 != 0) {
        uVar4 = 0;
        uVar3 = 0;
        piVar8 = in_ECX;
        FUN_00527d30();
        FUN_00595eb0(piVar8,uVar3,uVar4);
      }
    }
    FUN_004f4620(in_ECX[0x10]);
  }
  uVar3 = __ftol();
  iVar2 = FUN_0067bcf0(uVar3);
  if (iVar2 == 1) {
    (**(code **)(*in_ECX + 0x10))(&fStack_20);
    FUN_0051f3d0();
    fVar1 = SQRT((fStack_20 - DAT_00d78bd8) * (fStack_20 - DAT_00d78bd8) +
                 (fStack_1c - DAT_00d78bdc) * (fStack_1c - DAT_00d78bdc) +
                 (fStack_18 - DAT_00d78be0) * (fStack_18 - DAT_00d78be0));
    if (fVar1 < 200.0) {
      fVar6 = (float10)FUN_00528ef0();
      fVar7 = (float10)FUN_007bd220((float)fVar6);
      uStack_14 = 0;
      uStack_10 = 0;
      uStack_c = 0x13;
      uStack_8 = 0;
      if ((float10)0.7 <= fVar7) {
        if ((float10)1.3 <= fVar7) {
          uStack_4 = 0x4a;
        }
        else if (12.0 <= (float)fVar6) {
          uStack_4 = 0x48;
        }
        else {
          uStack_4 = 0x49;
        }
      }
      else {
        uStack_4 = 0x47;
      }
      FUN_00424390(in_ECX,fVar1,&uStack_14,0,*(undefined4 *)(DAT_00bf4e68 + 0x3b0),1,0,0);
    }
  }
  if ((in_ECX[0x23] != 0) && (DAT_00d78910 != 0)) {
    if ((*(char *)((int)in_ECX + 0xb6) == '\0') &&
       ((iVar2 = (**(code **)(*in_ECX + 0x310))(), iVar2 == 0 || (in_ECX[0x31] == 0)))) {
      iVar2 = *(int *)(in_ECX[0x23] + 0xc);
      if (iVar2 != 2) {
        if (iVar2 != 0) goto LAB_004f2bc5;
        *(undefined4 *)(in_ECX[0x23] + 0xc) = 2;
      }
    }
    else {
      *(undefined4 *)(in_ECX[0x23] + 0xc) = 0;
    }
    FUN_007575f0();
  }
LAB_004f2bc5:
  uVar5 = (*(byte *)(in_ECX + 0x1f) & 0x10) >> 4;
  if (((DAT_00b5a4d8 != 0) && (iVar2 = (**(code **)(*in_ECX + 0x48))(), DAT_00b6e52c == iVar2)) ||
     (uVar5 != 0)) {
    FUN_00405750(uVar5);
  }
  return;
}



// ?GetVillagerHugRadius@Object@@UAEMXZ @ 0x004f2d30

void _GetVillagerHugRadius_Object__UAEMXZ(void)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  int *piVar3;
  float10 fVar4;
  int iStack_8;
  
  _GetWeight_Object__UAEMXZ();
  iVar1 = DAT_00d78910;
  iVar2 = (**(code **)(*in_ECX + 0x48))();
  if (iVar2 != 0) {
    piVar3 = in_ECX + 0x34;
    iStack_8 = 6;
    do {
      iVar2 = *piVar3;
      if (iVar2 != 0) {
        fVar4 = (float10)(**(code **)(*in_ECX + 0x11c))();
        if ((float10)0.0 < fVar4) {
          FUN_00768080(*(undefined4 *)(iVar2 + 0x10c));
          FUN_005ed470();
          if (DAT_00d78910 != 0) {
            FUN_006bd890(*(undefined1 *)(*(int *)(iVar2 + 0x40) + 0x4c));
            FUN_006bd880();
          }
        }
      }
      piVar3 = piVar3 + 1;
      iStack_8 = iStack_8 + -1;
    } while (iStack_8 != 0);
    DAT_00d78910 = iVar1;
    return;
  }
  DAT_00d78910 = iVar1;
  return;
}



// ?ProcessState@Object@@UAEIXZ @ 0x004f45f0

void _ProcessState_Object__UAEIXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  if (in_ECX[0x10] != 0) {
    iVar1 = (**(code **)(*in_ECX + 0x3cc))();
    if (iVar1 != 0) {
      *(undefined4 *)(in_ECX[0x10] + 100) = 1;
    }
  }
  _Draw_MultiMapFixed__UAEXXZ();
  return;
}



// ?DrawInHand@Object@@UAEXPAVGInterfaceStatus@@@Z @ 0x004f5700

void _DrawInHand_Object__UAEXPAVGInterfaceStatus___Z(int param_1)

{
  uint *puVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *in_ECX;
  float10 fVar8;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_14;
  float local_10;
  float local_c;
  float local_8;
  float local_4;
  
  iVar2 = param_1;
  iVar5 = FUN_00527d30();
  if (param_1 == *(int *)(iVar5 + 0x39c)) {
    FUN_00527d30();
    FUN_00458cd0();
    return;
  }
  local_30 = *(float *)(param_1 + 200);
  local_2c = *(float *)(param_1 + 0xcc);
  local_28 = *(float *)(param_1 + 0xd0);
  if (in_ECX[0x10] != 0) {
    puVar1 = (uint *)(in_ECX[0x10] + 8);
    *puVar1 = *puVar1 | 0x40;
  }
  if (in_ECX[0x10] != 0) {
    iVar6 = *(int *)(DAT_00c22ca4 + 0x201e04) + *(int *)(param_1 + 0xe0);
    iVar5 = *(int *)(param_1 + 0xe4);
    *(int *)(param_1 + 0xe0) = iVar6;
    if (iVar5 == 0) {
      iVar2 = in_ECX[0x14];
      piVar7 = (int *)FUN_005bf830(&local_30);
      fVar3 = (float)piVar7[2];
      fVar8 = (float10)FUN_00760fd0();
      local_20 = (float)(fVar8 + (float10)fVar3);
      local_24 = (float)*piVar7 * 0.00015258789;
      local_1c = (float)piVar7[1] * 0.00015258789;
      FUN_0041dbb0(0,iVar2);
    }
    else {
      param_1 = iVar6;
      if (iVar5 <= iVar6) {
        param_1 = iVar5;
      }
      fVar3 = (float)in_ECX[0x14];
      local_20 = local_2c - *(float *)(iVar2 + 0xd8);
      local_1c = local_28 - *(float *)(iVar2 + 0xdc);
      fVar4 = (float)param_1 / (float)iVar5;
      local_14 = local_20 * fVar4;
      local_10 = local_1c * fVar4;
      local_c = (local_30 - *(float *)(iVar2 + 0xd4)) * fVar4 + *(float *)(iVar2 + 0xd4);
      local_8 = local_14 + *(float *)(iVar2 + 0xd8);
      local_4 = local_10 + *(float *)(iVar2 + 0xdc);
      piVar7 = (int *)FUN_005bf830(&local_c);
      iVar2 = in_ECX[0x10];
      fVar4 = (float)piVar7[2];
      fVar8 = (float10)FUN_00760fd0();
      local_20 = (float)(fVar8 + (float10)fVar4);
      local_24 = (float)*piVar7 * 0.00015258789;
      local_1c = (float)piVar7[1] * 0.00015258789;
      if (fVar3 == 1.0) {
        FUN_004022b0();
      }
      else {
        FUN_004f5940(fVar3);
        *(float *)(iVar2 + 0x38) = local_24 + *(float *)(iVar2 + 0x38);
        *(float *)(iVar2 + 0x3c) = local_20 + *(float *)(iVar2 + 0x3c);
        *(float *)(iVar2 + 0x40) = local_1c + *(float *)(iVar2 + 0x40);
      }
      *(float *)(iVar2 + 0x44) = fVar3;
      *(undefined4 *)(iVar2 + 0x48) = 0;
    }
    (**(code **)(*in_ECX + 0x614))(0);
  }
  if (in_ECX[0x10] != 0) {
    puVar1 = (uint *)(in_ECX[0x10] + 8);
    *puVar1 = *puVar1 & 0xffffffbf;
  }
  return;
}



// ?GetDrawRegion@Object@@UAEXPAULHRegion@@@Z @ 0x004f59f0

void _GetDrawRegion_Object__UAEXPAULHRegion___Z(void)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int *in_ECX;
  float10 fVar8;
  float10 fVar9;
  
  iVar7 = (**(code **)(*in_ECX + 0x890))();
  if (iVar7 == 0) {
    FUN_004f4620(in_ECX[0x10]);
    return;
  }
  FUN_006b1490();
  if (in_ECX[0x11] != 0) {
    FUN_004f46e0();
    return;
  }
  fVar8 = (float10)(**(code **)(*in_ECX + 0x120))();
  fVar2 = (float)fVar8;
  fVar8 = (float10)(**(code **)(*in_ECX + 0x508))();
  fVar3 = (float)fVar8;
  iVar7 = in_ECX[0x10];
  fVar5 = (float)in_ECX[5] * 0.00015258789;
  fVar6 = (float)in_ECX[6] * 0.00015258789;
  fVar4 = (float)in_ECX[7];
  fVar8 = (float10)FUN_00761280(iVar7 + 0x50);
  fVar4 = (float)(fVar8 + (float10)fVar4);
  if (fVar3 == 0.0) {
    if (fVar2 == 1.0) {
      FUN_004022b0();
    }
    else {
      FUN_004f5940(fVar2);
      *(float *)(iVar7 + 0x38) = fVar5 + *(float *)(iVar7 + 0x38);
      *(float *)(iVar7 + 0x3c) = fVar4 + *(float *)(iVar7 + 0x3c);
      *(float *)(iVar7 + 0x40) = fVar6 + *(float *)(iVar7 + 0x40);
    }
  }
  else if (fVar2 == 1.0) {
    pfVar1 = (float *)(iVar7 + 0x14);
    FUN_00402280();
    fVar8 = (float10)fcos((float10)fVar3);
    *(float *)(iVar7 + 0x38) = fVar5;
    *(float *)(iVar7 + 0x3c) = fVar4;
    *(float *)(iVar7 + 0x40) = fVar6;
    fVar9 = (float10)fsin((float10)fVar3);
    fVar4 = *pfVar1;
    *pfVar1 = (float)(fVar8 * (float10)*pfVar1 + fVar9 * (float10)*(float *)(iVar7 + 0x2c));
    *(float *)(iVar7 + 0x2c) =
         (float)(fVar8 * (float10)*(float *)(iVar7 + 0x2c) - fVar9 * (float10)fVar4);
    fVar4 = *(float *)(iVar7 + 0x18);
    *(float *)(iVar7 + 0x18) =
         (float)(fVar8 * (float10)*(float *)(iVar7 + 0x18) +
                fVar9 * (float10)*(float *)(iVar7 + 0x30));
    *(float *)(iVar7 + 0x30) =
         (float)(fVar8 * (float10)*(float *)(iVar7 + 0x30) - fVar9 * (float10)fVar4);
    fVar4 = *(float *)(iVar7 + 0x1c);
    *(float *)(iVar7 + 0x1c) =
         (float)(fVar8 * (float10)*(float *)(iVar7 + 0x1c) +
                fVar9 * (float10)*(float *)(iVar7 + 0x34));
    *(float *)(iVar7 + 0x34) =
         (float)(fVar8 * (float10)*(float *)(iVar7 + 0x34) -
                (float10)(float)(fVar9 * (float10)fVar4));
  }
  else {
    *(undefined4 *)(iVar7 + 0x40) = 0;
    *(undefined4 *)(iVar7 + 0x3c) = 0;
    *(undefined4 *)(iVar7 + 0x38) = 0;
    *(undefined4 *)(iVar7 + 0x30) = 0;
    *(undefined4 *)(iVar7 + 0x2c) = 0;
    *(undefined4 *)(iVar7 + 0x28) = 0;
    *(undefined4 *)(iVar7 + 0x20) = 0;
    *(undefined4 *)(iVar7 + 0x1c) = 0;
    *(undefined4 *)(iVar7 + 0x18) = 0;
    *(float *)(iVar7 + 0x34) = fVar2;
    *(float *)(iVar7 + 0x24) = fVar2;
    *(float *)(iVar7 + 0x14) = fVar2;
    *(float *)(iVar7 + 0x38) = fVar5 + *(float *)(iVar7 + 0x38);
    *(float *)(iVar7 + 0x3c) = fVar4 + *(float *)(iVar7 + 0x3c);
    *(float *)(iVar7 + 0x40) = fVar6 + *(float *)(iVar7 + 0x40);
    fVar8 = (float10)fcos((float10)fVar3);
    fVar9 = (float10)fsin((float10)fVar3);
    fVar4 = *(float *)(iVar7 + 0x14);
    *(float *)(iVar7 + 0x14) =
         (float)(fVar9 * (float10)*(float *)(iVar7 + 0x2c) +
                fVar8 * (float10)*(float *)(iVar7 + 0x14));
    *(float *)(iVar7 + 0x2c) =
         (float)(fVar8 * (float10)*(float *)(iVar7 + 0x2c) - fVar9 * (float10)fVar4);
    fVar4 = *(float *)(iVar7 + 0x18);
    *(float *)(iVar7 + 0x18) =
         (float)(fVar8 * (float10)*(float *)(iVar7 + 0x18) +
                fVar9 * (float10)*(float *)(iVar7 + 0x30));
    *(float *)(iVar7 + 0x30) =
         (float)(fVar8 * (float10)*(float *)(iVar7 + 0x30) - fVar9 * (float10)fVar4);
    fVar4 = *(float *)(iVar7 + 0x1c);
    *(float *)(iVar7 + 0x1c) =
         (float)(fVar8 * (float10)*(float *)(iVar7 + 0x1c) +
                fVar9 * (float10)*(float *)(iVar7 + 0x34));
    *(float *)(iVar7 + 0x34) =
         (float)(fVar8 * (float10)*(float *)(iVar7 + 0x34) -
                (float10)(float)(fVar9 * (float10)fVar4));
  }
  *(float *)(iVar7 + 0x44) = fVar2;
  *(float *)(iVar7 + 0x48) = fVar3;
  FUN_005ed470();
  return;
}



// ?GetProjectileSpeed@Object@@UAEMXZ @ 0x004f5c70

void _GetProjectileSpeed_Object__UAEMXZ(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *in_ECX;
  float10 fVar4;
  
  iVar3 = (**(code **)(*in_ECX + 0x890))();
  if (iVar3 == 0) {
    FUN_004f4620(in_ECX[0x10]);
    return;
  }
  if (in_ECX[0x43] == 0) {
    fVar4 = (float10)(**(code **)(*in_ECX + 0x120))();
    fVar1 = (float)fVar4;
    fVar4 = (float10)(**(code **)(*in_ECX + 0x508))();
    fVar2 = (float)fVar4;
    iVar3 = in_ECX[0x10];
    FUN_00761280(iVar3 + 0x50);
    if (fVar2 == 0.0) {
      if (fVar1 == 1.0) {
        FUN_004022b0();
        *(float *)(iVar3 + 0x44) = fVar1;
        *(float *)(iVar3 + 0x48) = fVar2;
      }
      else {
        FUN_004f5940(fVar1);
        FUN_004022f0();
        *(float *)(iVar3 + 0x44) = fVar1;
        *(float *)(iVar3 + 0x48) = fVar2;
      }
    }
    else if (fVar1 == 1.0) {
      FUN_004022b0();
      FUN_004f5f10(fVar2);
      *(float *)(iVar3 + 0x44) = fVar1;
      *(float *)(iVar3 + 0x48) = fVar2;
    }
    else {
      FUN_004f5940(fVar1);
      FUN_004022f0();
      FUN_004f5f10(fVar2);
      *(float *)(iVar3 + 0x44) = fVar1;
      *(float *)(iVar3 + 0x48) = fVar2;
    }
  }
  else {
    fVar4 = (float10)(**(code **)(*in_ECX + 0x120))();
    fVar1 = (float)fVar4;
    fVar4 = (float10)(**(code **)(*in_ECX + 0x508))();
    fVar2 = (float)fVar4;
    iVar3 = in_ECX[0x10];
    FUN_00760fd0();
    if (fVar2 == 0.0) {
      if (fVar1 == 1.0) {
        FUN_004022b0();
      }
      else {
        FUN_004f5940(fVar1);
        FUN_004022f0();
      }
    }
    else if (fVar1 == 1.0) {
      FUN_004022b0();
      FUN_004f5f10(fVar2);
    }
    else {
      FUN_004f5940(fVar1);
      FUN_004022f0();
      FUN_004f5f10(fVar2);
    }
    *(float *)(iVar3 + 0x44) = fVar1;
    *(float *)(iVar3 + 0x48) = fVar2;
    FUN_00768080(in_ECX[0x43]);
  }
  FUN_005ed470();
  if (DAT_00d78910 != 0) {
    FUN_006bd890(*(uint *)(in_ECX[0x10] + 0x4c) >> 0x18);
    FUN_006bd880();
  }
  return;
}



// ?GetWeight@Object@@UAEMXZ @ 0x004f71b0

void _GetWeight_Object__UAEMXZ(void)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *in_ECX;
  float10 fVar8;
  float10 fVar9;
  
  _SetPlayer_GameThing__QAEXPAVGPlayer___Z(1);
  iVar6 = (**(code **)(*in_ECX + 0x890))();
  if (iVar6 == 0) {
    FUN_004f4620(in_ECX[0x10]);
    return;
  }
  FUN_006cb670();
  (**(code **)(*(int *)in_ECX[0x10] + 0x48))();
  if ((*(byte *)(in_ECX + 9) & 0x10) != 0) {
    FUN_00527d30();
    piVar7 = (int *)FUN_0058f6e0();
    if (piVar7 == in_ECX) {
      if (in_ECX[0x11] != 0) {
        fVar8 = (float10)(**(code **)(*in_ECX + 0x120))();
        fVar9 = (float10)(**(code **)(*in_ECX + 0x508))();
        FUN_00760fd0();
        FUN_0041dbb0((float)fVar9,(float)fVar8);
        FUN_004f46e0();
        return;
      }
      fVar8 = (float10)(**(code **)(*in_ECX + 0x120))();
      fVar9 = (float10)(**(code **)(*in_ECX + 0x508))();
      FUN_00761280(in_ECX[0x10] + 0x50);
      FUN_0041dbb0((float)fVar9,(float)fVar8);
      FUN_005ed470();
      return;
    }
  }
  if (in_ECX[0x11] != 0) {
    FUN_004f46e0();
    return;
  }
  fVar8 = (float10)(**(code **)(*in_ECX + 0x120))();
  fVar2 = (float)fVar8;
  fVar8 = (float10)(**(code **)(*in_ECX + 0x508))();
  fVar3 = (float)fVar8;
  iVar6 = in_ECX[5];
  iVar5 = in_ECX[0x10];
  iVar1 = in_ECX[6];
  fVar4 = (float)in_ECX[7];
  fVar8 = (float10)FUN_00761280(iVar5 + 0x50);
  if (fVar3 == 0.0) {
    if (fVar2 == 1.0) {
      FUN_004022b0();
    }
    else {
      FUN_004f5940(fVar2);
      FUN_004022f0();
    }
  }
  else if (fVar2 == 1.0) {
    FUN_004022b0();
    FUN_004f5f10(fVar3);
  }
  else {
    *(undefined4 *)(iVar5 + 0x40) = 0;
    *(undefined4 *)(iVar5 + 0x3c) = 0;
    *(undefined4 *)(iVar5 + 0x38) = 0;
    *(undefined4 *)(iVar5 + 0x30) = 0;
    *(undefined4 *)(iVar5 + 0x2c) = 0;
    *(undefined4 *)(iVar5 + 0x28) = 0;
    *(undefined4 *)(iVar5 + 0x20) = 0;
    *(undefined4 *)(iVar5 + 0x1c) = 0;
    *(undefined4 *)(iVar5 + 0x18) = 0;
    *(float *)(iVar5 + 0x34) = fVar2;
    *(float *)(iVar5 + 0x24) = fVar2;
    *(float *)(iVar5 + 0x14) = fVar2;
    *(float *)(iVar5 + 0x38) = (float)iVar6 * 0.00015258789 + *(float *)(iVar5 + 0x38);
    *(float *)(iVar5 + 0x3c) = (float)(fVar8 + (float10)fVar4) + *(float *)(iVar5 + 0x3c);
    *(float *)(iVar5 + 0x40) = (float)iVar1 * 0.00015258789 + *(float *)(iVar5 + 0x40);
    fVar8 = (float10)fcos((float10)fVar3);
    fVar9 = (float10)fsin((float10)fVar3);
    fVar4 = *(float *)(iVar5 + 0x14);
    *(float *)(iVar5 + 0x14) =
         (float)(fVar9 * (float10)*(float *)(iVar5 + 0x2c) +
                fVar8 * (float10)*(float *)(iVar5 + 0x14));
    *(float *)(iVar5 + 0x2c) =
         (float)(fVar8 * (float10)*(float *)(iVar5 + 0x2c) - fVar9 * (float10)fVar4);
    fVar4 = *(float *)(iVar5 + 0x18);
    *(float *)(iVar5 + 0x18) =
         (float)(fVar8 * (float10)*(float *)(iVar5 + 0x18) +
                fVar9 * (float10)*(float *)(iVar5 + 0x30));
    *(float *)(iVar5 + 0x30) =
         (float)(fVar8 * (float10)*(float *)(iVar5 + 0x30) - fVar9 * (float10)fVar4);
    fVar4 = *(float *)(iVar5 + 0x1c);
    *(float *)(iVar5 + 0x1c) =
         (float)(fVar8 * (float10)*(float *)(iVar5 + 0x1c) +
                fVar9 * (float10)*(float *)(iVar5 + 0x34));
    *(float *)(iVar5 + 0x34) =
         (float)(fVar8 * (float10)*(float *)(iVar5 + 0x34) -
                (float10)(float)(fVar9 * (float10)fVar4));
  }
  *(float *)(iVar5 + 0x44) = fVar2;
  *(float *)(iVar5 + 0x48) = fVar3;
  FUN_005ed470();
  return;
}



// ?DrawOutOfMap@Object@@UAEX_N@Z @ 0x004f8bf0

void _DrawOutOfMap_Object__UAEX_N_Z(void)

{
  uint *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int *in_ECX;
  
  if (in_ECX[0x10] != 0) {
    puVar1 = (uint *)(in_ECX[0x10] + 8);
    *puVar1 = *puVar1 | 0x40;
  }
  if (in_ECX[0x11] == 0) {
    iVar4 = in_ECX[0x10];
    puVar2 = (undefined4 *)(iVar4 + 0x50);
    FUN_0075fc20(iVar4 + 0x38,iVar4 + 0x4c,puVar2);
    uVar3 = FUN_0075d130(iVar4 + 0x38,*puVar2,iVar4 + 0x4c);
    *puVar2 = uVar3;
    FUN_005ed470();
  }
  else {
    uVar3 = FUN_006c6760();
    FUN_006c6850();
    FUN_00768080(uVar3);
    FUN_005ed470();
    FUN_005ea220();
  }
  if (in_ECX[0x10] != 0) {
    puVar1 = (uint *)(in_ECX[0x10] + 8);
    *puVar1 = *puVar1 & 0xffffffbf;
  }
  iVar4 = (**(code **)(*in_ECX + 0x2c8))(0);
  if (iVar4 != 0) {
    (**(code **)(*in_ECX + 0xb40))();
  }
  return;
}



// ?GetNearestEdgeToPos@Object@@UAEXPBUMapCoords@@@Z @ 0x004fe370

int _GetNearestEdgeToPos_Object__UAEXPBUMapCoords___Z(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *in_ECX;
  int iVar6;
  char *pcVar7;
  undefined1 auStack_19c [12];
  char acStack_190 [200];
  undefined1 auStack_c8 [100];
  undefined1 auStack_64 [100];
  
  iVar2 = FUN_0053eb80();
  if (iVar2 == 0) {
    return 0;
  }
  if (param_2 != 0) {
    FUN_005c13b0(auStack_19c,param_2);
  }
  (**(code **)(*in_ECX + 0x120))();
  (**(code **)(*in_ECX + 0x508))();
  uVar3 = __ftol(*(byte *)(in_ECX + 0x16) >> 1 & 1);
  uVar3 = __ftol(uVar3);
  uVar4 = FUN_004fe4d0(auStack_64);
  uVar5 = FUN_005bf290(auStack_c8);
  uVar3 = FUN_006ad590(0x4b,uVar5,uVar4,uVar3);
  FUN_00733e17(acStack_190,uVar3);
  iVar6 = -1;
  pcVar7 = acStack_190;
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  FUN_006b10c0();
  return iVar2;
}



// ?GetFOVHelpMessageSet@Object@@UAEIXZ @ 0x004fe590

undefined4 _GetFOVHelpMessageSet_Object__UAEIXZ(void)

{
  undefined4 uVar1;
  int *in_ECX;
  float10 fVar2;
  
  if ((in_ECX[10] + -0xbead00) / 0x124 == 0x45) {
    fVar2 = (float10)(**(code **)(*in_ECX + 0x880))();
    if ((float10)1.0 <= fVar2) {
      return 0xb31;
    }
  }
  uVar1 = _GetQueryFirstEnumText_Object__UAE_AW4HELP_TEXT__XZ();
  return uVar1;
}



// ?GetFOVHelpCondition@Object@@UAEIXZ @ 0x004fe5e0

undefined4 _GetFOVHelpCondition_Object__UAEIXZ(void)

{
  undefined4 uVar1;
  int *in_ECX;
  float10 fVar2;
  
  if ((in_ECX[10] + -0xbead00) / 0x124 == 0x45) {
    fVar2 = (float10)(**(code **)(*in_ECX + 0x880))();
    if ((float10)1.0 <= fVar2) {
      return 0xb31;
    }
  }
  uVar1 = _GetQueryLastEnumText_Object__UAE_AW4HELP_TEXT__XZ();
  return uVar1;
}



// ?GetFoodType@Object@@UAE?AW4FOOD_TYPE@@XZ @ 0x004fe7a0

void _GetFoodType_Object__UAE_AW4FOOD_TYPE__XZ(undefined4 param_1)

{
  int in_ECX;
  
  _CallVirtualFunctionsForCreation_MultiMapFixed__UAEXABUMapCoords___Z(param_1);
  if (*(int **)(in_ECX + 0x40) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x1e8))();
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x58))();
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x78))();
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x80))();
  }
  return;
}



// ?ShouldFootpathsGoRound@Object@@UAE_NXZ @ 0x004fe7f0

int _ShouldFootpathsGoRound_Object__UAE_NXZ(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *in_ECX;
  int iVar6;
  char *pcVar7;
  undefined1 auStack_19c [12];
  char acStack_190 [200];
  undefined1 auStack_c8 [100];
  undefined1 auStack_64 [100];
  
  iVar2 = FUN_0053eb80();
  if (iVar2 == 0) {
    return 0;
  }
  if (param_2 != 0) {
    FUN_005c13b0(auStack_19c,param_2);
  }
  (**(code **)(*in_ECX + 0x120))();
  (**(code **)(*in_ECX + 0x508))();
  uVar3 = __ftol();
  uVar3 = __ftol(uVar3);
  uVar4 = FUN_004fe4d0(auStack_64);
  uVar5 = FUN_005bf290(auStack_c8);
  uVar3 = FUN_006ad590(0x22,uVar5,uVar4,uVar3);
  FUN_00733e17(acStack_190,uVar3);
  iVar6 = -1;
  pcVar7 = acStack_190;
  do {
    if (iVar6 == 0) break;
    iVar6 = iVar6 + -1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  FUN_006b10c0();
  return iVar2;
}



// ?ApplySingleEffect@Object@@UAEXW4EFFECT_TYPE@@MPAVGameThing@@PBUMapCoords@@@Z @ 0x004ff4a0

void _ApplySingleEffect_Object__UAEXW4EFFECT_TYPE__MPAVGameThing__PBUMapCoords___Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined1 *param_4)

{
  _GetFireGPHXDrawn_Object__UAEXPA_N000_Z(param_1,param_2,param_3,param_4);
  *param_4 = 0;
  return;
}



// ?GetBoundingSphere@Object@@UAEXPAULHPoint@@PAM@Z @ 0x004ff4d0

undefined4 _GetBoundingSphere_Object__UAEXPAULHPoint__PAM_Z(void)

{
  int iVar1;
  int *in_ECX;
  int unaff_retaddr;
  
  iVar1 = (**(code **)(*in_ECX + 0x6fc))(0);
  if (((iVar1 == 0) && (unaff_retaddr != 0)) && (0.0 < *(float *)(unaff_retaddr + 8))) {
    return 0;
  }
  return 1;
}



// ?IsABeliever@Object@@UAE_NXZ @ 0x004ff600

void _IsABeliever_Object__UAE_NXZ(void)

{
  int *piVar1;
  int *in_ECX;
  float10 fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  piVar1 = (int *)FUN_005ecd90(1);
  in_ECX[0x10] = (int)piVar1;
  (**(code **)(*piVar1 + 0x78))();
  *(undefined4 *)(in_ECX[0x10] + 0x10) = 0;
  (**(code **)(*in_ECX + 0x608))();
  (**(code **)(*(int *)in_ECX[0x10] + 0xf4))(0,0);
  (**(code **)(*(int *)in_ECX[0x10] + 0x88))();
  fVar2 = (float10)(**(code **)(*in_ECX + 0x120))();
  fVar5 = (float)fVar2;
  fVar2 = (float10)(**(code **)(*in_ECX + 0x50c))(fVar5);
  fVar4 = (float)fVar2;
  fVar2 = (float10)(**(code **)(*in_ECX + 0x508))(fVar4);
  fVar3 = (float)fVar2;
  fVar2 = (float10)(**(code **)(*in_ECX + 0x504))(fVar3);
  FUN_005ed520((float)fVar2,fVar3,fVar4,fVar5);
  (**(code **)(*(int *)in_ECX[0x10] + 0x1e8))();
  (**(code **)(*in_ECX + 0x850))();
  FUN_00504d40();
  if (((*(byte *)(in_ECX + 9) & 4) == 0) && ((*(byte *)((int)in_ECX + 10) & 0x11) == 0)) {
    (**(code **)(*in_ECX + 0x544))();
  }
  in_ECX[0x39] = -0x40800000;
  in_ECX[0x40] = 0;
  in_ECX[0x3f] = 0;
  in_ECX[0x45] = 0;
  in_ECX[0x44] = 0;
  in_ECX[0x3e] = 0;
  in_ECX[0x43] = 0;
  in_ECX[0x3d] = 0;
  in_ECX[0x42] = 0;
  in_ECX[0x3c] = 0;
  in_ECX[0x3b] = -0x40800000;
  in_ECX[0x3a] = -0x40800000;
  in_ECX[0x41] = -0x40800000;
  return;
}



// ?SetPoisonedResource@Object@@UAEXW4RESOURCE_TYPE@@H@Z @ 0x004ff8d0

float10 _SetPoisonedResource_Object__UAEXW4RESOURCE_TYPE__H_Z(int *param_1)

{
  float fVar1;
  undefined1 uVar2;
  int iVar3;
  undefined4 uVar4;
  int in_ECX;
  float10 fVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  fVar5 = (float10)_ApplyWaterSpell_Object__UAEMPAVSpellWater___Z(param_1);
  iVar3 = (**(code **)(*param_1 + 0x1c))();
  if (iVar3 != 0) {
    uVar7 = 0x16;
    uVar6 = 0x21;
    iVar3 = in_ECX;
    uVar4 = FUN_006b89a0(0x21);
    (**(code **)(*param_1 + 0x1c))(uVar4);
    FUN_004cb260(uVar4,uVar6,iVar3,uVar7);
  }
  iVar3 = FUN_005ea110();
  if (iVar3 == 0) {
    iVar3 = *(int *)(in_ECX + 0x120);
    if ((float)*(byte *)(in_ECX + 0xcc) <= *(float *)(iVar3 + 0x128)) {
      uVar2 = __ftol();
      *(undefined1 *)(in_ECX + 0xcc) = uVar2;
    }
    else if (*(float *)(in_ECX + 0xd0) <= *(float *)(iVar3 + 0x124)) {
      fVar1 = *(float *)(iVar3 + 0x150);
      *(float *)(in_ECX + 0xd0) = fVar1 + *(float *)(in_ECX + 0xd0);
      FUN_005001f0();
      *(float *)(in_ECX + 0xdc) =
           (fVar1 * *(float *)(*(int *)(in_ECX + 0x120) + 0x130)) /
           *(float *)(*(int *)(in_ECX + 0x120) + 0x124) + *(float *)(in_ECX + 0xdc);
      return (float10)(float)fVar5;
    }
  }
  return (float10)(float)fVar5;
}



// ?IsG3DObjectDrawnInHand@Object@@UAE_NXZ @ 0x004ff9c0

undefined4 _IsG3DObjectDrawnInHand_Object__UAE_NXZ(void)

{
  float fVar1;
  bool bVar2;
  char cVar3;
  int iVar4;
  undefined4 uVar5;
  int *in_ECX;
  float10 fVar6;
  undefined1 auStack_c [12];
  
  _GetProjectileSpeed_Object__UAEMXZ();
  if ((uint)(*(int *)(DAT_00c22ca4 + 0x201afc) + in_ECX[0x47]) % 10 == 0) {
    iVar4 = FUN_005ea110();
    if (iVar4 != 1) {
      if ((*(float *)(in_ECX[0x48] + 0x128) <= (float)*(byte *)(in_ECX + 0x33)) &&
         ((float)in_ECX[0x34] <= *(float *)(in_ECX[0x48] + 0x124))) {
        fVar6 = (float10)FUN_005c1450();
        fVar6 = fVar6 * (float10)0.5 + (float10)1.0;
        fVar1 = (float)(fVar6 + fVar6);
        uVar5 = FUN_005c0400(auStack_c);
        cVar3 = FUN_006fe660(uVar5);
        iVar4 = in_ECX[0x48];
        bVar2 = *(float *)(iVar4 + 0x120) <= (float)in_ECX[0x34];
        if (cVar3 == '\0') {
          if (bVar2) {
            fVar1 = fVar1 * *(float *)(iVar4 + 0x13c);
          }
          else {
            fVar1 = fVar1 * *(float *)(iVar4 + 0x138);
          }
        }
        else if (bVar2) {
          fVar1 = fVar1 * *(float *)(iVar4 + 0x144);
        }
        else {
          fVar1 = fVar1 * *(float *)(iVar4 + 0x140);
        }
        in_ECX[0x34] = (int)(fVar1 + (float)in_ECX[0x34]);
        iVar4 = FUN_005001f0();
        in_ECX[0x37] = (int)((fVar1 * *(float *)(in_ECX[0x48] + 0x130)) /
                             *(float *)(in_ECX[0x48] + 0x124) + (float)in_ECX[0x37]);
        if (iVar4 != 0) {
          iVar4 = FUN_005001f0();
          if (iVar4 == 0) {
            iVar4 = (**(code **)(*in_ECX + 0x48))();
            if (iVar4 != 0) {
              iVar4 = (**(code **)(*in_ECX + 0x48))();
              *(undefined4 *)(iVar4 + 0x5e8) = 1;
              *(undefined4 *)(iVar4 + 0x5ec) = 0;
            }
          }
        }
      }
    }
  }
  return 1;
}



// ?ValidToApplyThisToObject@Object@@UAEIPAVGInterfaceStatus@@PAV1@@Z @ 0x004ffe40

undefined4 _ValidToApplyThisToObject_Object__UAEIPAVGInterfaceStatus__PAV1__Z(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  
  uVar1 = __ftol();
  uVar2 = (**(code **)(*in_ECX + 0x48))(0,0,0x3f800000,0);
  iVar3 = FUN_00616c40(in_ECX + 5,&DAT_00c6e330,uVar1,0,uVar2);
  if (iVar3 != 0) {
    FUN_0059c850(iVar3);
  }
  FUN_004ffec0((float)uVar1);
  return 0;
}



// ?GetNearestPosOfObject@Object@@UAEXPAV1@@Z @ 0x00500050

undefined4 _GetNearestPosOfObject_Object__UAEXPAV1__Z(int *param_1)

{
  byte bVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int *in_ECX;
  int iVar8;
  float10 fVar9;
  
  piVar2 = param_1;
  uVar3 = FUN_0059c190();
  piVar4 = (int *)FUN_007344da(uVar3,0,&Object::RTTI_Type_Descriptor,&Pot::RTTI_Type_Descriptor,0);
  if (piVar4 != (int *)0x0) {
    uVar3 = (**(code **)(*in_ECX + 0x690))();
    FUN_00616a60(param_1[0x10]);
    iVar5 = __ftol();
    fVar9 = (float10)FUN_00616b10(param_1[0x10]);
    FUN_00637b10(param_1,0,(float)fVar9);
    iVar8 = *(int *)(piVar4[10] + 0x13c);
    param_1 = (int *)iVar5;
    if (iVar8 != 0) {
      iVar7 = *piVar4;
      uVar6 = (**(code **)(iVar7 + 0x690))();
      iVar7 = (**(code **)(iVar7 + 0x98))(uVar6);
      iVar8 = iVar8 - iVar7;
      if (iVar8 < iVar5) {
        param_1 = (int *)iVar8;
      }
    }
    iVar8 = FUN_005001f0();
    if (iVar8 != 0) {
      param_1 = (int *)((int)param_1 / 2);
    }
    if (0 < (int)param_1) {
      FUN_004ffec0((float)(int)param_1);
      (**(code **)(*piVar4 + 0x9c))(uVar3,param_1,0,0,0,0);
      if ((*(byte *)((int)in_ECX + 10) & 1) != 0) {
        FUN_00637c30(piVar2);
      }
      bVar1 = *(byte *)(DAT_00c22ca4 + 0x201b15);
      iVar8 = DAT_00c22ca4 + 0x18;
      iVar5 = (**(code **)(*piVar2 + 0x1c))();
      if (iVar5 == iVar8 + (uint)bVar1 * 0x278) {
        FUN_0058ac80(0xeea,(float)(uint)piVar4[0x1c]);
      }
      return 1;
    }
    FUN_00637c30(piVar2);
  }
  return 0;
}



// ?InterfaceSetOutMagicHand@Object@@UAE_NPAVGInterfaceStatus@@@Z @ 0x00500340

undefined4 _InterfaceSetOutMagicHand_Object__UAE_NPAVGInterfaceStatus___Z(void)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *in_ECX;
  
  bVar1 = *(byte *)(DAT_00c22ca4 + 0x201b15);
  iVar4 = DAT_00c22ca4 + 0x18;
  iVar2 = (**(code **)(*in_ECX + 0x1c))();
  if (iVar2 == iVar4 + (uint)bVar1 * 0x278) {
    FUN_00527d30();
    uVar3 = FUN_0059c190();
    iVar4 = FUN_007344da(uVar3,0,&Object::RTTI_Type_Descriptor,&Pot::RTTI_Type_Descriptor,0);
    if (iVar4 != 0) {
      FUN_0058ac80(0xeea,(float)*(uint *)(iVar4 + 0x70));
    }
  }
  return 1;
}



// ?ValidToRemoveFromHand@Object@@UAE_NPAVGInterfaceStatus@@PBUMapCoords@@@Z @ 0x005003d0

undefined4
_ValidToRemoveFromHand_Object__UAE_NPAVGInterfaceStatus__PBUMapCoords___Z(undefined4 param_1)

{
  FUN_00637c30(param_1);
  return 1;
}



// ?GetFoodValue@Object@@UAEMW4FOOD_TYPE@@@Z @ 0x00500890

char _GetFoodValue_Object__UAEMW4FOOD_TYPE___Z(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 0x1c))();
  iVar2 = (**(code **)(*param_2 + 0x1c))();
  if (iVar1 == iVar2) {
    iVar1 = (**(code **)(*in_ECX + 0x890))();
    return (-(iVar1 != 1) & 3U) + 1;
  }
  return '\0';
}



// ?DrawOutOfMap@Object@@UAEX_N@Z @ 0x005008e0

undefined4 _DrawOutOfMap_Object__UAEX_N_Z(void)

{
  int in_ECX;
  
  FUN_00500900();
  if (*(int **)(in_ECX + 0x44) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x44) + 0xc))(0);
  }
  return 1;
}



// ?ScaffoldMoved@Object@@UAEXPAVScaffold@@@Z @ 0x00500920

float10 _ScaffoldMoved_Object__UAEXPAVScaffold___Z(float param_1)

{
  int in_ECX;
  
  FUN_004ffec0(param_1 * *(float *)(*(int *)(in_ECX + 0x120) + 0x130));
  return (float10)1.0;
}



// ?GetHealEffect@Object@@UAEMPAVEffectValues@@@Z @ 0x00500970

void _GetHealEffect_Object__UAEMPAVEffectValues___Z(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x11c))();
  return;
}



// ?GetHandHelpMessageSet@Object@@UAEIXZ @ 0x00502d00

float10 _GetHandHelpMessageSet_Object__UAEIXZ(void)

{
  return (float10)5.0;
}



// ?IsDrowning@Object@@UAE_NXZ @ 0x00502e20

undefined4 _IsDrowning_Object__UAE_NXZ(void)

{
  int iVar1;
  int in_ECX;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_10 = 0;
  uStack_c = 0;
  uStack_8 = 0;
  uStack_4 = 0;
  iVar1 = FUN_00502de0(&uStack_c,&uStack_10);
  while( true ) {
    if (iVar1 == 0) {
      return 1;
    }
    iVar1 = FUN_005bfa60();
    while( true ) {
      if (iVar1 == 0) {
        return 0;
      }
      if (iVar1 == in_ECX) break;
      iVar1 = FUN_005ea910(&uStack_c);
    }
    if (iVar1 == 0) break;
    iVar1 = FUN_00502de0(&uStack_c,&uStack_10);
  }
  return 0;
}



// ?Get3DType@Object@@UAE?AW4LH3DObject__ObjectType@@XZ @ 0x005030b0

void _Get3DType_Object__UAE_AW4LH3DObject__ObjectType__XZ(void)

{
  int iVar1;
  float fVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 uVar6;
  char cVar7;
  int *in_ECX;
  int iVar8;
  undefined4 *puVar9;
  float10 fVar10;
  float10 fVar11;
  float10 fVar12;
  float fStack_34;
  int iStack_30;
  int iStack_2c;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  
  (**(code **)(*in_ECX + 0x850))();
  in_ECX[0x1b] = 1;
  puVar3 = (undefined4 *)FUN_00746d70(8,s_C__dev_black_FishFarm_cpp_00b17070,0x12a);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    *(undefined2 *)(puVar3 + 1) = 0;
    *(undefined2 *)((int)puVar3 + 6) = 0;
    *(undefined2 *)(puVar3 + 1) = 0;
    *(undefined2 *)((int)puVar3 + 6) = 0;
    *puVar3 = 0;
  }
  in_ECX[0x1a] = (int)puVar3;
  if (((*(byte *)(in_ECX + 9) & 4) == 0) && ((*(byte *)((int)in_ECX + 10) & 0x11) == 0)) {
    (**(code **)(*in_ECX + 0x544))();
  }
  fVar2 = (float)in_ECX[7];
  fVar10 = (float10)FUN_00760fd0();
  iVar5 = in_ECX[5];
  iVar1 = in_ECX[6];
  puVar3 = (undefined4 *)FUN_0079a330(0x20);
  if (puVar3 != (undefined4 *)0x0) {
    puVar4 = puVar3;
    for (iVar8 = 8; iVar8 != 0; iVar8 = iVar8 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
  }
  iStack_30 = -1;
  fStack_34 = 2.0;
  DAT_00b59d38 = 0;
  do {
    if (50.0 <= fStack_34) break;
    iStack_2c = 0;
    do {
      fVar11 = (float10)iStack_2c * (float10)6.2831855 * (float10)0.03125;
      fVar12 = (float10)fcos(fVar11);
      fVar11 = (float10)fsin(fVar11);
      fStack_24 = (float)(fVar12 * (float10)fStack_34) + (float)iVar5 * 0.00015258789;
      fStack_1c = (float)(fVar11 * (float10)fStack_34 + (float10)((float)iVar1 * 0.00015258789));
      __ftol();
      __ftol();
      fVar11 = (float10)FUN_00760fd0();
      if (fVar11 == (float10)0.0) {
        cVar7 = *(char *)(iStack_2c + (int)puVar3) + '\x01';
        *(char *)(iStack_2c + (int)puVar3) = cVar7;
        iVar8 = iStack_2c;
        if (cVar7 == '\x02') break;
      }
      else {
        *(undefined1 *)(iStack_2c + (int)puVar3) = 0;
      }
      iStack_2c = iStack_2c + 1;
      iVar8 = iStack_30;
    } while (iStack_2c < 0x20);
    iStack_30 = iVar8;
    fStack_34 = fStack_34 + 2.0;
    fStack_20 = (float)(fVar10 + (float10)fVar2);
  } while (iStack_30 == -1);
  DAT_00b59d38 = 1;
  if (iStack_30 == -1) {
    in_ECX[0x22] = 0;
    FUN_0079a3b0(puVar3);
    return;
  }
  puVar4 = (undefined4 *)FUN_00746d70(0x68,s_C__dev_black_FishFarm_cpp_00b17070,0x154);
  if (puVar4 == (undefined4 *)0x0) {
    in_ECX[0x22] = 0;
    FUN_0079a3b0(puVar3);
    return;
  }
  puVar4[0x17] = 0;
  puVar4[0x18] = DAT_00dd8854;
  DAT_00dd8854 = puVar4;
  puVar4[0x15] = 0;
  puVar4[0x16] = 0x40e00000;
  puVar4[0x12] = fStack_24;
  puVar4[0x13] = fStack_20;
  puVar4[0x14] = fStack_1c;
  puVar4[0xf] = fStack_24;
  puVar4[0x10] = fStack_20;
  puVar4[0x11] = fStack_1c;
  iStack_2c = 0xf;
  puVar9 = puVar4;
  do {
    iVar5 = FUN_00746d70(0x24,s_c__dev_libs_lhall_released_heade_00b1708c,0x2f8);
    if (iVar5 == 0) {
      uVar6 = 0;
    }
    else {
      uVar6 = FUN_0077e240(puVar4 + 0x12);
    }
    *puVar9 = uVar6;
    puVar9 = puVar9 + 1;
    iStack_2c = iStack_2c + -1;
  } while (iStack_2c != 0);
  puVar4[0x19] = 0x3f800000;
  in_ECX[0x22] = (int)puVar4;
  FUN_0079a3b0(puVar3);
  return;
}



// ?GetNearestPosOfObject@Object@@UAEXPAV1@@Z @ 0x005033e0

int _GetNearestPosOfObject_Object__UAEXPAV1__Z(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *in_ECX;
  char *pcVar5;
  int iVar6;
  undefined1 auStack_138 [12];
  undefined1 auStack_12c [100];
  char acStack_c8 [200];
  
  iVar2 = FUN_0053eb80();
  if (iVar2 == 0) {
    return 0;
  }
  if (param_2 != 0) {
    FUN_005c13b0(auStack_138,param_2);
  }
  iVar3 = (**(code **)(*in_ECX + 0x48))();
  if (iVar3 != 0) {
    iVar3 = (**(code **)(*in_ECX + 0x48))();
    iVar3 = *(int *)(iVar3 + 0x5b4);
    if (iVar3 != -1) {
      iVar6 = (in_ECX[10] + -0xbf0fd8) / 0x128;
      uVar4 = FUN_005bf290(auStack_12c);
      uVar4 = FUN_006ad590(0x20,iVar3,uVar4,iVar6);
      FUN_00733e17(acStack_c8,uVar4);
      goto LAB_005034dc;
    }
  }
  iVar3 = (in_ECX[10] + -0xbf0fd8) / 0x128;
  uVar4 = FUN_005bf290(auStack_12c);
  uVar4 = FUN_006ad590(0x1f,uVar4,iVar3);
  FUN_00733e17(acStack_c8,uVar4);
LAB_005034dc:
  iVar3 = -1;
  pcVar5 = acStack_c8;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_006b10c0();
  return iVar2;
}



// ?ProcessBySpell@Object@@UAEIPAVSpell@@@Z @ 0x00503560

undefined4 _ProcessBySpell_Object__UAEIPAVSpell___Z(void)

{
  int *in_ECX;
  float10 fVar1;
  
  if (*(uint *)(DAT_00c22ca4 + 0x201afc) % *(uint *)(in_ECX[10] + 0x124) == 0) {
    in_ECX[0x25] = (int)((float)in_ECX[0x25] + 1.0);
  }
  if (0.0 <= (float)in_ECX[0x25]) {
    fVar1 = (float10)(**(code **)(*in_ECX + 0x660))(3);
    if (fVar1 < (float10)(float)in_ECX[0x25]) {
      fVar1 = (float10)(**(code **)(*in_ECX + 0x660))(3);
      in_ECX[0x25] = (int)(float)fVar1;
    }
  }
  else {
    in_ECX[0x25] = 0;
  }
  if (in_ECX[0x22] != 0) {
    fVar1 = (float10)(**(code **)(*in_ECX + 0x660))(3);
    *(float *)(in_ECX[0x22] + 100) = (float)((float10)(float)in_ECX[0x25] / fVar1);
  }
  return 1;
}



// ?GetWoodValue@Object@@UAEMXZ @ 0x00503610

float10 _GetWoodValue_Object__UAEMXZ(int param_1)

{
  int iVar1;
  uint uVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*(int *)in_ECX[10] + 0x38))();
  if ((param_1 != iVar1) && (param_1 != 3)) {
    return (float10)0.0;
  }
  uVar2 = (**(code **)(*in_ECX + 0x668))();
  if ((uVar2 & 3) != 0) {
    return (float10)*(float *)(in_ECX[10] + 0x68);
  }
  return (float10)0.0;
}



// ?InterfaceSetOutMagicHand@Object@@UAE_NPAVGInterfaceStatus@@@Z @ 0x00503a80

undefined4 _InterfaceSetOutMagicHand_Object__UAE_NPAVGInterfaceStatus___Z(void)

{
  int *in_ECX;
  float10 fVar1;
  
  FUN_006169b0();
  fVar1 = (float10)(**(code **)(*in_ECX + 0x660))(3);
  if ((float10)0.0 < fVar1) {
    return 1;
  }
  return 0;
}



// ?ValidToRemoveFromHand@Object@@UAE_NPAVGInterfaceStatus@@PBUMapCoords@@@Z @ 0x00503ac0

undefined4 _ValidToRemoveFromHand_Object__UAE_NPAVGInterfaceStatus__PBUMapCoords___Z(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  float10 fVar4;
  
  FUN_006169b0();
  uVar1 = __ftol();
  fVar4 = (float10)(**(code **)(*in_ECX + 0x660))(3);
  if ((float10)0.0 < fVar4) {
    uVar2 = (**(code **)(*in_ECX + 0x48))(0,0,0x3f800000,0);
    iVar3 = FUN_00616c40(in_ECX + 5,&DAT_00c6e330,uVar1,0,uVar2);
    if (iVar3 != 0) {
      FUN_0059c850(iVar3);
    }
  }
  return 0;
}



// ?GetWorkingPos@Object@@UAEPAUMapCoords@@PAU2@PAV1@@Z @ 0x00503b30

byte _GetWorkingPos_Object__UAEPAUMapCoords__PAU2_PAV1__Z(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x1c))();
  iVar2 = (**(code **)(*param_2 + 0x1c))();
  return (iVar1 != iVar2) - 1U & 3;
}



// ?IsReadyForNetworkUnfriendlyLockedSelect@Object@@UAE_NXZ @ 0x00503b60

undefined4 _IsReadyForNetworkUnfriendlyLockedSelect_Object__UAE_NXZ(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int *in_ECX;
  float unaff_EBX;
  float10 fVar6;
  int unaff_retaddr;
  
  (**(code **)(*in_ECX + 0x690))();
  iVar2 = _GetScriptObjectType_Creature__UAEIXZ();
  fVar6 = (float10)(**(code **)(*in_ECX + 0x660))(3);
  if (fVar6 <= (float10)unaff_EBX) {
    (**(code **)(*in_ECX + 0x660))(3);
  }
  iVar3 = __ftol();
  if (iVar3 != 0) {
    uVar4 = (**(code **)(*in_ECX + 0x48))(0,0,0x3f800000,0);
    piVar5 = (int *)FUN_00616c40(unaff_retaddr + 0x14,&DAT_00c6d400 + iVar2 * 0x51,iVar3,0,uVar4);
    if (piVar5 != (int *)0x0) {
      cVar1 = (**(code **)(*piVar5 + 0x4a4))();
      (**(code **)(*piVar5 + 0x69c))(cVar1 != '\0');
      FUN_0059c850(piVar5);
      uVar4 = (**(code **)(*in_ECX + 0x1c))();
      *(undefined4 *)(unaff_retaddr + 0x128) = uVar4;
      FUN_00637aa0(unaff_retaddr,in_ECX + 5,3);
      return 1;
    }
  }
  return 0;
}



// ?ValidAsInterfaceLeashTarget@Object@@UAE_NXZ @ 0x00503c70

undefined4 _ValidAsInterfaceLeashTarget_Object__UAE_NXZ(int *param_1)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  FUN_00637c30(param_1);
  bVar1 = *(byte *)(DAT_00c22ca4 + 0x201b15);
  iVar4 = DAT_00c22ca4 + 0x18;
  iVar2 = (**(code **)(*param_1 + 0x1c))();
  if (iVar2 == iVar4 + (uint)bVar1 * 0x278) {
    FUN_00527d30();
    uVar3 = FUN_0059c190();
    iVar4 = FUN_007344da(uVar3,0,&Object::RTTI_Type_Descriptor,&Pot::RTTI_Type_Descriptor,0);
    if (iVar4 != 0) {
      FUN_0058ac80(0xeea,(float)*(uint *)(iVar4 + 0x70));
    }
  }
  return 1;
}



// ?IsPushable@Object@@UAE_NXZ @ 0x00503d10

undefined4 _IsPushable_Object__UAE_NXZ(int *param_1)

{
  byte bVar1;
  undefined4 uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *in_ECX;
  uint uVar7;
  float10 fVar8;
  float unaff_retaddr;
  
  uVar2 = FUN_0059c190();
  piVar3 = (int *)FUN_007344da(uVar2,0,&Object::RTTI_Type_Descriptor,&Pot::RTTI_Type_Descriptor,0);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*in_ECX + 0x690))();
    _GetScriptObjectType_Creature__UAEIXZ();
    FUN_00616a60(param_1[0x10]);
    fVar8 = (float10)FUN_00616b10(param_1[0x10]);
    FUN_00637b10(param_1,3,(float)fVar8);
    fVar8 = (float10)(**(code **)(*in_ECX + 0x660))(3);
    if (fVar8 <= (float10)unaff_retaddr) {
      (**(code **)(*in_ECX + 0x660))(3);
    }
    uVar4 = __ftol();
    iVar6 = *(int *)(piVar3[10] + 0x13c);
    if (iVar6 != 0) {
      iVar5 = *piVar3;
      uVar2 = (**(code **)(iVar5 + 0x690))();
      iVar5 = (**(code **)(iVar5 + 0x98))(uVar2);
      uVar7 = iVar6 - iVar5;
      uVar7 = ((int)uVar7 < 0) - 1 & uVar7;
      if ((int)uVar7 < (int)uVar4) {
        uVar4 = uVar7;
      }
    }
    iVar6 = FUN_00503370(uVar4);
    if (iVar6 != 0) {
      (**(code **)(*piVar3 + 0x9c))(0,uVar4,param_1,0,0,0);
      if ((*(byte *)((int)in_ECX + 10) & 1) != 0) {
        FUN_00637c30(param_1);
      }
      bVar1 = *(byte *)(DAT_00c22ca4 + 0x201b15);
      iVar6 = DAT_00c22ca4 + 0x18;
      iVar5 = (**(code **)(*param_1 + 0x1c))();
      if (iVar5 == iVar6 + (uint)bVar1 * 0x278) {
        FUN_0058ac80(0xeea,(float)(uint)piVar3[0x1c]);
      }
      return 1;
    }
    FUN_00637c30(param_1);
  }
  return 0;
}



// ?Get3DType@Object@@UAE?AW4LH3DObject__ObjectType@@XZ @ 0x00504b70

void _Get3DType_Object__UAE_AW4LH3DObject__ObjectType__XZ(undefined4 param_1)

{
  _CallVirtualFunctionsForCreation_Object__UAEXABUMapCoords___Z(param_1);
  return;
}



// ?GetDrawRegion@Object@@UAEXPAULHRegion@@@Z @ 0x00509410

undefined4 _GetDrawRegion_Object__UAEXPAULHRegion___Z(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  int *in_ECX;
  int *piVar10;
  undefined4 uVar11;
  int iStack_c;
  
  if (*(int *)(DAT_00c22ca4 + 0x201afc) == DAT_00bf16b0) {
    return 1;
  }
  DAT_00bf16b0 = *(int *)(DAT_00c22ca4 + 0x201afc);
  FUN_004ef260(&DAT_00bf4e6c,4,s_Football_State___s_00b17354,
               s_WaitingForPlayers_00b171fc + in_ECX[0x7f] * 0x40);
  FUN_004ef260(&DAT_00bf4e6c,4,s_Home___d__v_Away___d__00b1733c,(char)in_ECX[0x84],
               *(undefined1 *)((int)in_ECX + 0x211));
  if (in_ECX[0x83] == 0) {
    if (((int *)in_ECX[in_ECX[0x86] + 0x96] != (int *)0x0) &&
       (iVar5 = (**(code **)(*(int *)in_ECX[in_ECX[0x86] + 0x96] + 0x174))(), iVar5 == 0)) {
      (**(code **)(*(int *)in_ECX[in_ECX[0x86] + 0x96] + 0x8e4))(0x54);
    }
    iVar5 = in_ECX[0x86];
    in_ECX[0x86] = iVar5 + 1U;
    if (0x27 < iVar5 + 1U) {
      in_ECX[0x83] = 0x100;
      in_ECX[0x86] = 0;
    }
  }
  else {
    in_ECX[0x83] = in_ECX[0x83] + -1;
  }
  iVar5 = in_ECX[0x7f];
  if (iVar5 == 0) {
    if ((2 < (uint)in_ECX[0x89]) && (2 < (uint)in_ECX[0x8b])) {
      iVar5 = in_ECX[0x81];
      in_ECX[0x81] = iVar5 + 1U;
      uVar6 = __ftol();
      if (uVar6 < iVar5 + 1U) {
        piVar7 = (int *)FUN_005071d0();
        (**(code **)(*piVar7 + 0x55c))(in_ECX + 5);
        in_ECX[0x80] = 1;
        in_ECX[0x81] = 0;
      }
      if ((in_ECX[0x80] == 1) && (iVar5 = FUN_00508200(), iVar5 == 1)) {
        in_ECX[0x7f] = 1;
        iVar5 = __ftol();
        in_ECX[0xc1] = iVar5;
        FUN_00509e70();
        piVar7 = in_ECX + 0x8c;
        iVar5 = 2;
        do {
          FUN_00509af0(piVar7);
          piVar7 = piVar7 + 2;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
    }
  }
  else if (iVar5 == 1) {
    if (in_ECX[0xbe] == 1) {
      uVar11 = 0;
      in_ECX[0x81] = in_ECX[0x81] + 1;
      (**(code **)(*in_ECX + 0x48))(0);
      iVar5 = FUN_006d8260(uVar11);
      if (*(int *)(iVar5 + 8) != 0xf) {
        (**(code **)(*in_ECX + 0x48))();
        uVar6 = __ftol();
        if (uVar6 < (uint)in_ECX[0x81]) {
          FUN_005079f0();
        }
      }
    }
    iVar5 = FUN_005071d0();
    if (iVar5 != 0) {
      iVar9 = FUN_00507870(iVar5);
      if (iVar9 == 1) {
        in_ECX[0x94] = 0;
        FUN_00509ce0(in_ECX + 0x88,0);
        FUN_00509ce0(in_ECX + 0x8a,1);
        FUN_00509e70();
        uVar6 = in_ECX[0xc1];
        uVar8 = __ftol();
        if (uVar6 < uVar8) {
          in_ECX[0xc1] = uVar6 + 1;
        }
        else {
          piVar7 = in_ECX + 0x8c;
          iVar5 = 2;
          do {
            FUN_00509af0(piVar7);
            piVar7 = piVar7 + 2;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
          in_ECX[0xc1] = 0;
        }
        piVar7 = in_ECX + 0x8c;
        iVar5 = 2;
        do {
          FUN_00509ba0(piVar7);
          piVar7 = piVar7 + 2;
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      else {
        if (in_ECX[0x88] == 0) {
          piVar7 = (int *)0x0;
        }
        else {
          piVar7 = *(int **)(in_ECX[0x88] + 4);
        }
        if (in_ECX[0x8a] == 0) {
          piVar10 = (int *)0x0;
        }
        else {
          piVar10 = *(int **)(in_ECX[0x8a] + 4);
        }
        uVar6 = FUN_006de110(piVar7 + 5,iVar5 + 0x14);
        uVar8 = FUN_006de110(piVar10 + 5,iVar5 + 0x14);
        if ((float)uVar6 <= (float)uVar8) {
          piVar7 = piVar10;
        }
        for (puVar1 = (undefined4 *)in_ECX[0x88]; puVar1 != (undefined4 *)0x0;
            puVar1 = (undefined4 *)*puVar1) {
          piVar10 = (int *)puVar1[1];
          if (((piVar10 != piVar7) && (piVar10 != (int *)in_ECX[0x94])) && (in_ECX[0x7f] != 3)) {
            (**(code **)(*piVar10 + 0x8e4))(0x52);
          }
        }
        for (puVar1 = (undefined4 *)in_ECX[0x8a]; puVar1 != (undefined4 *)0x0;
            puVar1 = (undefined4 *)*puVar1) {
          piVar10 = (int *)puVar1[1];
          if (((piVar10 != piVar7) && (piVar10 != (int *)in_ECX[0x94])) && (in_ECX[0x7f] != 3)) {
            (**(code **)(*piVar10 + 0x8e4))(0x52);
          }
        }
        if (in_ECX[0x94] == 0) {
          FUN_006e0f90(iVar5,0x4f);
          in_ECX[0x94] = (int)piVar7;
          in_ECX[0x82] = 0;
          goto LAB_0050988c;
        }
      }
    }
    in_ECX[0x82] = 0;
  }
  else if ((iVar5 == 3) && (iVar5 = in_ECX[0xbf], in_ECX[0xbf] = iVar5 + 1U, 0x46 < iVar5 + 1U)) {
    in_ECX[0x7f] = 1;
    iVar5 = __ftol();
    in_ECX[0xc1] = iVar5;
  }
LAB_0050988c:
  piVar7 = in_ECX + 0x32;
  iVar5 = 10;
  do {
    if (((int *)*piVar7 != (int *)0x0) &&
       (iVar9 = (**(code **)(*(int *)*piVar7 + 0x2c))(), iVar9 == 0)) {
      *piVar7 = 0;
    }
    piVar7 = piVar7 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  piVar7 = in_ECX + 0x3c;
  iVar5 = 0x14;
  do {
    if (((int *)*piVar7 != (int *)0x0) &&
       (iVar9 = (**(code **)(*(int *)*piVar7 + 0x2c))(), iVar9 == 0)) {
      *piVar7 = 0;
    }
    piVar7 = piVar7 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  if (((int *)in_ECX[0x50] != (int *)0x0) &&
     (iVar5 = (**(code **)(*(int *)in_ECX[0x50] + 0x2c))(), iVar5 == 0)) {
    in_ECX[0x50] = 0;
  }
  if (((int *)in_ECX[0x87] != (int *)0x0) &&
     (iVar5 = (**(code **)(*(int *)in_ECX[0x87] + 0x2c))(), iVar5 == 0)) {
    in_ECX[0x87] = 0;
  }
  puVar1 = (undefined4 *)in_ECX[0x88];
  while (puVar2 = puVar1, puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar2;
    if (((puVar2 != (undefined4 *)0x0) && ((int *)puVar2[1] != (int *)0x0)) &&
       (iVar5 = (**(code **)(*(int *)puVar2[1] + 0x2c))(), iVar5 == 0)) {
      iVar5 = puVar2[1];
      piVar7 = (int *)in_ECX[0x88];
      piVar10 = (int *)0x0;
      while (piVar4 = piVar10, piVar10 = piVar7, piVar10 != (int *)0x0) {
        piVar7 = (int *)*piVar10;
        if (piVar10[1] == iVar5) {
          if (piVar10 == (int *)in_ECX[0x88]) {
            in_ECX[0x88] = (int)piVar7;
          }
          else {
            *piVar4 = (int)piVar7;
          }
          in_ECX[0x89] = in_ECX[0x89] + -1;
          FUN_007290de(piVar10);
          piVar10 = piVar4;
        }
      }
    }
  }
  puVar1 = (undefined4 *)in_ECX[0x8a];
  while (puVar2 = puVar1, puVar2 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar2;
    if (((puVar2 != (undefined4 *)0x0) && ((int *)puVar2[1] != (int *)0x0)) &&
       (iVar5 = (**(code **)(*(int *)puVar2[1] + 0x2c))(), iVar5 == 0)) {
      iVar5 = puVar2[1];
      piVar7 = (int *)in_ECX[0x8a];
      piVar10 = (int *)0x0;
      while (piVar4 = piVar10, piVar10 = piVar7, piVar10 != (int *)0x0) {
        piVar7 = (int *)*piVar10;
        if (piVar10[1] == iVar5) {
          if (piVar10 == (int *)in_ECX[0x8a]) {
            in_ECX[0x8a] = (int)piVar7;
          }
          else {
            *piVar4 = (int)piVar7;
          }
          in_ECX[0x8b] = in_ECX[0x8b] + -1;
          FUN_007290de(piVar10);
          piVar10 = piVar4;
        }
      }
    }
  }
  piVar7 = in_ECX + 0x8c;
  iStack_c = 2;
  do {
    puVar1 = (undefined4 *)*piVar7;
    while (puVar2 = puVar1, puVar2 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*puVar2;
      if (((puVar2 != (undefined4 *)0x0) && ((int *)puVar2[1] != (int *)0x0)) &&
         (iVar5 = (**(code **)(*(int *)puVar2[1] + 0x2c))(), iVar5 == 0)) {
        iVar5 = puVar2[1];
        piVar10 = (int *)*piVar7;
        piVar4 = (int *)0x0;
        while (piVar3 = piVar4, piVar4 = piVar10, piVar4 != (int *)0x0) {
          piVar10 = (int *)*piVar4;
          if (piVar4[1] == iVar5) {
            if (piVar4 == (int *)*piVar7) {
              *piVar7 = (int)piVar10;
            }
            else {
              *piVar3 = (int)piVar10;
            }
            piVar7[1] = piVar7[1] + -1;
            FUN_007290de(piVar4);
            piVar4 = piVar3;
          }
        }
      }
    }
    piVar7 = piVar7 + 2;
    iStack_c = iStack_c + -1;
  } while (iStack_c != 0);
  piVar7 = in_ECX + 0x92;
  iVar5 = 2;
  do {
    if (((int *)piVar7[-2] != (int *)0x0) &&
       (iVar9 = (**(code **)(*(int *)piVar7[-2] + 0x2c))(), iVar9 == 0)) {
      piVar7[-2] = 0;
    }
    if (((int *)*piVar7 != (int *)0x0) &&
       (iVar9 = (**(code **)(*(int *)*piVar7 + 0x2c))(), iVar9 == 0)) {
      *piVar7 = 0;
    }
    piVar7 = piVar7 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  if (((int *)in_ECX[0x94] != (int *)0x0) &&
     (iVar5 = (**(code **)(*(int *)in_ECX[0x94] + 0x2c))(), iVar5 == 0)) {
    in_ECX[0x94] = 0;
  }
  piVar7 = in_ECX + 0x96;
  iVar5 = 0x28;
  do {
    if (((int *)*piVar7 != (int *)0x0) &&
       (iVar9 = (**(code **)(*(int *)*piVar7 + 0x2c))(), iVar9 == 0)) {
      *piVar7 = 0;
    }
    piVar7 = piVar7 + 1;
    iVar5 = iVar5 + -1;
  } while (iVar5 != 0);
  return 1;
}



// ?IsAlive@Object@@UAE_NXZ @ 0x0052e840

void _IsAlive_Object__UAE_NXZ(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x10c) = param_1;
  return;
}



// ?IsMoving@Object@@UAE_NXZ @ 0x0052ed00

undefined4 _IsMoving_Object__UAE_NXZ(undefined4 param_1)

{
  FUN_00705e70(param_1);
  return param_1;
}



// ?DrawOutOfMap@Object@@UAEX_N@Z @ 0x0052ed30

undefined4 _DrawOutOfMap_Object__UAEX_N_Z(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x28) + 0x138);
}



// ?GetLandingPointCount@Object@@UAEHXZ @ 0x005317f0

void _GetLandingPointCount_Object__UAEHXZ(undefined4 param_1,undefined4 param_2)

{
  _UpdateSpellInfo_GameThing__QAEXPAVSpell__PAVPSysProcessInfo___Z(param_1,param_2);
  return;
}



// ?GetMeshRadius@Object@@UAEMXZ @ 0x005b9ff0

void _GetMeshRadius_Object__UAEMXZ(undefined4 param_1)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int *in_ECX;
  float10 fVar8;
  float10 fVar9;
  
  _ActualMoveMapObject_Object__UAEXUMapCoords___Z(param_1);
  if (in_ECX[0x10] != 0) {
    fVar8 = (float10)(**(code **)(*in_ECX + 0x120))();
    fVar4 = (float)fVar8;
    fVar8 = (float10)(**(code **)(*in_ECX + 0x508))();
    fVar5 = (float)fVar8;
    fVar6 = (float)in_ECX[7];
    iVar7 = in_ECX[0x10];
    fVar8 = (float10)FUN_00760fd0();
    iVar2 = in_ECX[5];
    iVar3 = in_ECX[6];
    if (fVar5 == 0.0) {
      if (fVar4 == 1.0) {
        FUN_004022b0();
      }
      else {
        *(float *)(iVar7 + 0x34) = fVar4;
        *(float *)(iVar7 + 0x14) = fVar4;
        *(undefined4 *)(iVar7 + 0x40) = 0;
        *(undefined4 *)(iVar7 + 0x3c) = 0;
        *(undefined4 *)(iVar7 + 0x38) = 0;
        *(undefined4 *)(iVar7 + 0x30) = 0;
        *(undefined4 *)(iVar7 + 0x2c) = 0;
        *(undefined4 *)(iVar7 + 0x28) = 0;
        *(undefined4 *)(iVar7 + 0x20) = 0;
        *(undefined4 *)(iVar7 + 0x1c) = 0;
        *(undefined4 *)(iVar7 + 0x18) = 0;
        *(float *)(iVar7 + 0x24) = fVar4;
        FUN_004022f0();
      }
    }
    else if (fVar4 == 1.0) {
      pfVar1 = (float *)(iVar7 + 0x14);
      FUN_00402280();
      fVar9 = (float10)fcos((float10)fVar5);
      *(float *)(iVar7 + 0x38) = (float)iVar2 * 0.00015258789;
      *(float *)(iVar7 + 0x3c) = (float)(fVar8 + (float10)fVar6);
      *(float *)(iVar7 + 0x40) = (float)iVar3 * 0.00015258789;
      fVar8 = (float10)fsin((float10)fVar5);
      fVar6 = *pfVar1;
      *pfVar1 = (float)(fVar9 * (float10)*pfVar1 + fVar8 * (float10)*(float *)(iVar7 + 0x2c));
      *(float *)(iVar7 + 0x2c) =
           (float)(fVar9 * (float10)*(float *)(iVar7 + 0x2c) - fVar8 * (float10)fVar6);
      fVar6 = *(float *)(iVar7 + 0x18);
      *(float *)(iVar7 + 0x18) =
           (float)(fVar9 * (float10)*(float *)(iVar7 + 0x18) +
                  fVar8 * (float10)*(float *)(iVar7 + 0x30));
      *(float *)(iVar7 + 0x30) =
           (float)(fVar9 * (float10)*(float *)(iVar7 + 0x30) - fVar8 * (float10)fVar6);
      fVar6 = *(float *)(iVar7 + 0x1c);
      *(float *)(iVar7 + 0x1c) =
           (float)(fVar9 * (float10)*(float *)(iVar7 + 0x1c) +
                  fVar8 * (float10)*(float *)(iVar7 + 0x34));
      *(float *)(iVar7 + 0x34) =
           (float)(fVar9 * (float10)*(float *)(iVar7 + 0x34) -
                  (float10)(float)(fVar8 * (float10)fVar6));
    }
    else {
      *(undefined4 *)(iVar7 + 0x40) = 0;
      *(undefined4 *)(iVar7 + 0x3c) = 0;
      *(undefined4 *)(iVar7 + 0x38) = 0;
      *(undefined4 *)(iVar7 + 0x30) = 0;
      *(undefined4 *)(iVar7 + 0x2c) = 0;
      *(undefined4 *)(iVar7 + 0x28) = 0;
      *(undefined4 *)(iVar7 + 0x20) = 0;
      *(undefined4 *)(iVar7 + 0x1c) = 0;
      *(undefined4 *)(iVar7 + 0x18) = 0;
      *(float *)(iVar7 + 0x34) = fVar4;
      *(float *)(iVar7 + 0x24) = fVar4;
      *(float *)(iVar7 + 0x14) = fVar4;
      *(float *)(iVar7 + 0x38) = (float)iVar2 * 0.00015258789 + *(float *)(iVar7 + 0x38);
      *(float *)(iVar7 + 0x3c) = (float)(fVar8 + (float10)fVar6) + *(float *)(iVar7 + 0x3c);
      *(float *)(iVar7 + 0x40) = (float)iVar3 * 0.00015258789 + *(float *)(iVar7 + 0x40);
      fVar8 = (float10)fcos((float10)fVar5);
      fVar9 = (float10)fsin((float10)fVar5);
      fVar6 = *(float *)(iVar7 + 0x14);
      *(float *)(iVar7 + 0x14) =
           (float)(fVar9 * (float10)*(float *)(iVar7 + 0x2c) +
                  fVar8 * (float10)*(float *)(iVar7 + 0x14));
      *(float *)(iVar7 + 0x2c) =
           (float)(fVar8 * (float10)*(float *)(iVar7 + 0x2c) - fVar9 * (float10)fVar6);
      fVar6 = *(float *)(iVar7 + 0x18);
      *(float *)(iVar7 + 0x18) =
           (float)(fVar8 * (float10)*(float *)(iVar7 + 0x18) +
                  fVar9 * (float10)*(float *)(iVar7 + 0x30));
      *(float *)(iVar7 + 0x30) =
           (float)(fVar8 * (float10)*(float *)(iVar7 + 0x30) - fVar9 * (float10)fVar6);
      fVar6 = *(float *)(iVar7 + 0x1c);
      *(float *)(iVar7 + 0x1c) =
           (float)(fVar8 * (float10)*(float *)(iVar7 + 0x1c) +
                  fVar9 * (float10)*(float *)(iVar7 + 0x34));
      *(float *)(iVar7 + 0x34) =
           (float)(fVar8 * (float10)*(float *)(iVar7 + 0x34) -
                  (float10)(float)(fVar9 * (float10)fVar6));
    }
    *(float *)(iVar7 + 0x44) = fVar4;
    *(float *)(iVar7 + 0x48) = fVar5;
  }
  return;
}



// ?GetFireGPHXDrawn@Object@@UAEXPA_N000@Z @ 0x005bab30

void _GetFireGPHXDrawn_Object__UAEXPA_N000_Z(void)

{
  return;
}



// ?HasSunk@Object@@UAE_NXZ @ 0x005bad40

undefined1 _HasSunk_Object__UAE_NXZ(void)

{
  return 1;
}



// ?IsFireMan@Object@@UAE_NXZ @ 0x005c3380

undefined4 _IsFireMan_Object__UAE_NXZ(int param_1)

{
  int iVar1;
  
  if ((param_1 != 0) && ((~*(ushort *)(param_1 + 0x24) & 0x400) != 0)) {
    iVar1 = FUN_005ea110();
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}



// ?ResolveLoad@Object@@UAEXXZ @ 0x005c3520

undefined4 _ResolveLoad_Object__UAEXXZ(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_MultiMapFixed__UAEIPAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x7c));
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x80),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x80) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90((byte *)(in_ECX + 0x84),4,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x84) + 4;
      }
    }
    return 1;
  }
  return 0;
}



// ?GetInHandImmersionTexture@Object@@UAE?AW4IMMERSION_EFFECT_TYPE@@XZ @ 0x005c37b0

undefined4
_GetInHandImmersionTexture_Object__UAE_AW4IMMERSION_EFFECT_TYPE__XZ(undefined4 param_1,int param_2)

{
  char cVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *in_ECX;
  char *pcVar6;
  float10 fVar7;
  double dVar8;
  double dVar9;
  undefined8 uVar10;
  undefined1 local_140 [12];
  char acStack_134 [200];
  undefined1 auStack_6c [104];
  
  iVar3 = FUN_0053eb80();
  if (iVar3 != 0) {
    piVar4 = in_ECX + 5;
    if (param_2 != 0) {
      piVar4 = (int *)FUN_005c13b0(local_140,param_2);
    }
    fVar2 = (float)piVar4[2];
    if (in_ECX[0x1f] == 0) {
      iVar3 = in_ECX[10];
      fVar7 = (float10)(**(code **)(*in_ECX + 0x120))();
      fVar7 = (float10)(**(code **)(*in_ECX + 0x50c))((double)fVar7);
      fVar7 = (float10)(**(code **)(*in_ECX + 0x508))((double)fVar7);
      fVar7 = (float10)(**(code **)(*in_ECX + 0x504))((double)fVar7);
      iVar3 = (iVar3 + -0xc5b5e0) / 300;
      dVar9 = (double)fVar7;
      dVar8 = (double)fVar2;
      uVar5 = FUN_005bf290(auStack_6c);
      uVar5 = FUN_006ad590(0x2a,uVar5,iVar3,dVar8,dVar9);
      FUN_00733e17(acStack_134,uVar5);
      iVar3 = -1;
      pcVar6 = acStack_134;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      FUN_006b10c0();
      iVar3 = (**(code **)(*in_ECX + 0x800))();
      if ((iVar3 != 0) && (iVar3 = (**(code **)(*in_ECX + 0x7fc))(), iVar3 != 0)) {
        uVar10 = CONCAT44(param_2,param_1);
        (**(code **)(*in_ECX + 0x7fc))(param_1,param_2);
        FUN_00420c30(uVar10);
      }
      FUN_005c0740(0x1c,0);
      piVar4 = (int *)FUN_007344da();
      while (piVar4 != (int *)0x0) {
        if ((((in_ECX[5] == piVar4[5]) && (in_ECX[6] == piVar4[6])) &&
            ((float)piVar4[7] == (float)in_ECX[7])) &&
           ((piVar4 != in_ECX && (in_ECX[10] == piVar4[10])))) {
          FUN_0053eb80();
        }
        FUN_005c0740(0x1c,piVar4);
        piVar4 = (int *)FUN_007344da();
      }
      uVar5 = FUN_0053eb80();
      return uVar5;
    }
  }
  return 0;
}



// ?InterfaceValidToTap@Object@@UAEIPAVGInterfaceStatus@@@Z @ 0x005c3a00

undefined4 _InterfaceValidToTap_Object__UAEIPAVGInterfaceStatus___Z(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x3cc))();
  if (iVar1 != 0) {
    piVar2 = (int *)FUN_005c11c0();
    if (piVar2 != (int *)0x0) {
      iVar1 = *piVar2;
      uVar3 = (**(code **)(*in_ECX + 0x690))();
      iVar1 = (**(code **)(iVar1 + 0x680))(uVar3);
      if (iVar1 != 0) {
        iVar1 = (**(code **)(*piVar2 + 0x684))();
        if (iVar1 != 0) {
          return 3;
        }
      }
    }
  }
  (**(code **)(*in_ECX + 0x758))(param_1,0);
  return 0x16;
}



// ?IsInterfacePowerUpWhenInHand@Object@@UAEIXZ @ 0x005c3a80

undefined4 _IsInterfacePowerUpWhenInHand_Object__UAEIXZ(undefined4 param_1,int *param_2)

{
  int iVar1;
  int *in_ECX;
  
  if (*(int *)(in_ECX[10] + 0x128) == 0x31) {
    iVar1 = FUN_007344da(param_2,0,&Object::RTTI_Type_Descriptor,
                         &AnimatedStatic::RTTI_Type_Descriptor,0);
    if (iVar1 != 0) {
      if ((*(int *)(iVar1 + 0x28) + -0xb765f0) / 300 == 1) {
        return 1;
      }
    }
  }
  else {
    iVar1 = (**(code **)(*in_ECX + 0x3cc))();
    if ((iVar1 != 0) && (param_2 != (int *)0x0)) {
      iVar1 = (**(code **)(*param_2 + 0x680))(1);
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
  return 0;
}



// ?ApplyOnlyAfterRecSystem@Object@@UAEIXZ @ 0x005c3b00

undefined4 _ApplyOnlyAfterRecSystem_Object__UAEIXZ(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  if (*(int *)(in_ECX[10] + 0x128) == 0x31) {
    iVar1 = FUN_007344da(param_2,0,&Object::RTTI_Type_Descriptor,
                         &AnimatedStatic::RTTI_Type_Descriptor,0);
    if (iVar1 != 0) {
      uVar2 = (**(code **)(*(int *)in_ECX[10] + 0x2c))();
      FUN_0041d830(uVar2);
      FUN_005a5fa0();
      (**(code **)(*in_ECX + 0xc))(0);
      return 3;
    }
  }
  else {
    iVar1 = (**(code **)(*in_ECX + 0x3cc))();
    if ((iVar1 != 0) && (param_2 != (int *)0x0)) {
      iVar1 = (**(code **)(*param_2 + 0x680))(1);
      if ((iVar1 != 0) && ((*(byte *)((int)in_ECX + 0x25) & 0x40) == 0)) {
        iVar1 = (**(code **)(*param_2 + 0x684))();
        if (iVar1 != 0) {
          return 3;
        }
      }
    }
  }
  return 0;
}



// ?SetYAngle@Object@@UAEXM@Z @ 0x005c3bb0

void _SetYAngle_Object__UAEXM_Z(int param_1,int param_2)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  undefined4 unaff_retaddr;
  
  iVar1 = (**(code **)(*in_ECX + 0x178))();
  if (iVar1 != 0) {
    (**(code **)(*in_ECX + 0x548))();
  }
  in_ECX[0x20] = param_1;
  (**(code **)(*in_ECX + 0x520))(param_2);
  in_ECX[0x21] = param_2;
  if (in_ECX[0x10] != 0) {
    fVar2 = (float10)(**(code **)(*in_ECX + 0x120))();
    FUN_005ed520(unaff_retaddr,param_2,param_2,(float)fVar2);
  }
  if (iVar1 != 0) {
    (**(code **)(*in_ECX + 0x544))();
  }
  return;
}



// ?UpdateFrom3DPosition@Object@@UAEXXZ @ 0x005c3c30

void _UpdateFrom3DPosition_Object__UAEXXZ(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int *in_ECX;
  undefined4 unaff_EBX;
  
  iVar1 = (**(code **)(*in_ECX + 0x178))();
  if (iVar1 != 0) {
    (**(code **)(*in_ECX + 0x548))();
  }
  in_ECX[0x20] = param_1;
  (**(code **)(*in_ECX + 0x520))(param_2);
  in_ECX[0x21] = param_2;
  (**(code **)(*in_ECX + 0x51c))(param_3);
  if (in_ECX[0x10] != 0) {
    FUN_005ed520(unaff_EBX,param_2,param_1,param_3);
  }
  if (iVar1 != 0) {
    (**(code **)(*in_ECX + 0x544))();
  }
  return;
}



// ?GetRoutePlanRadius@Object@@UAEMPAVCreature@@@Z @ 0x005c3d30

void _GetRoutePlanRadius_Object__UAEMPAVCreature___Z(void)

{
  int iVar1;
  int *piVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x3cc))();
  if ((iVar1 != 0) && ((*(byte *)((int)in_ECX + 0x25) & 0x40) == 0)) {
    piVar2 = (int *)FUN_005f3c50();
    if (piVar2 != (int *)0x0) {
      iVar1 = (**(code **)(*piVar2 + 0x680))(1);
      if (iVar1 != 0) {
        (**(code **)(*piVar2 + 0x684))();
      }
    }
  }
  return;
}



// ?GetCollideSoundType@Object@@UAE?AW4SOUND_COLLISION_TYPE@@XZ @ 0x005c3d80

void _GetCollideSoundType_Object__UAE_AW4SOUND_COLLISION_TYPE__XZ(undefined4 param_1)

{
  _CreatureMustAvoid_Object__UAE_NPAVCreature___Z(param_1);
  return;
}



// ?GetAlwaysRemainsInPhysicsInternalSystem@Object@@UAE_NXZ @ 0x005c3e20

undefined4 _GetAlwaysRemainsInPhysicsInternalSystem_Object__UAE_NXZ(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x3b4))(0);
  if (iVar1 == 0) {
    iVar1 = FUN_005c3ea0();
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*in_ECX + 0x3cc))();
      if (iVar1 == 0) {
        iVar1 = FUN_005c3ef0();
        if (((iVar1 == 0) && (*(int *)(in_ECX[10] + 0x128) != 2)) &&
           (*(int *)(in_ECX[10] + 0x128) != 10)) {
          uVar2 = _InteractsWithPhysicsObjects_MultiMapFixed__UAE_NXZ();
          return uVar2;
        }
      }
    }
  }
  return 1;
}



// ?HandShouldFeelWithMeshIntersect@Object@@UAE_NXZ @ 0x005c3f20

undefined4 _HandShouldFeelWithMeshIntersect_Object__UAE_NXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = FUN_005c3ea0();
  if ((iVar1 == 0) && (iVar1 = FUN_005c3ef0(), iVar1 == 0)) {
    iVar1 = (**(code **)(*in_ECX + 0x3b4))(0);
    if (iVar1 == 0) {
      return 1;
    }
    iVar1 = (**(code **)(*(int *)in_ECX[10] + 0x2c))();
    if ((iVar1 != 0x191) && (iVar1 = (**(code **)(*(int *)in_ECX[10] + 0x2c))(), iVar1 != 0x193)) {
      return 1;
    }
  }
  return 6;
}



// ?GetSpecularColor@Object@@UAE?AULH3DColor@@XZ @ 0x005c3fa0

float10 _GetSpecularColor_Object__UAE_AULH3DColor__XZ(void)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = FUN_005c3ea0();
  if (iVar1 != 0) {
    return (float10)0.7;
  }
  iVar1 = FUN_005c3ef0();
  if (iVar1 != 0) {
    return (float10)0.4;
  }
  fVar2 = (float10)_GetSpeedInMetres_GameThingWithPos__UBEMXZ();
  return fVar2;
}



// ?SetDying@Object@@UAE_NXZ @ 0x005c43a0

int _SetDying_Object__UAE_NXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x3cc))();
  return (-(uint)(iVar1 != 0) & 2) - 1;
}



// ?IsAttackable@Object@@UAE_NPAV1@@Z @ 0x005c43c0

undefined4 _IsAttackable_Object__UAE_NPAV1__Z(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x3cc))();
  if (iVar1 != 0) {
    (**(code **)(*in_ECX + 0x664))();
    uVar2 = __ftol();
    return uVar2;
  }
  return 0;
}



// ?GetFoodType@Object@@UAE?AW4FOOD_TYPE@@XZ @ 0x005c43f0

void _GetFoodType_Object__UAE_AW4FOOD_TYPE__XZ(undefined4 param_1)

{
  int *in_ECX;
  float10 fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  _CallVirtualFunctionsForCreation_MultiMapFixed__UAEXABUMapCoords___Z(param_1);
  if (in_ECX[0x10] != 0) {
    fVar1 = (float10)(**(code **)(*in_ECX + 0x120))();
    fVar4 = (float)fVar1;
    fVar1 = (float10)(**(code **)(*in_ECX + 0x50c))(fVar4);
    fVar3 = (float)fVar1;
    fVar1 = (float10)(**(code **)(*in_ECX + 0x508))(fVar3);
    fVar2 = (float)fVar1;
    fVar1 = (float10)(**(code **)(*in_ECX + 0x504))(fVar2);
    FUN_005ed5e0((float)fVar1,fVar2,fVar3,fVar4);
  }
  return;
}



// ?Get3DType@Object@@UAE?AW4LH3DObject__ObjectType@@XZ @ 0x005e8a50

uint _Get3DType_Object__UAE_AW4LH3DObject__ObjectType__XZ(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x608))();
  if ((iVar1 < 0) || (*DAT_00d76c64 <= iVar1)) {
    iVar1 = 0;
  }
  return *(uint *)(DAT_00d76c64[iVar1 + 1] + 4) >> 7 & 2;
}



// ?Create3DObject@Object@@UAEXXZ @ 0x005e8b50

void _Create3DObject_Object__UAEXXZ(void)

{
  undefined4 uVar1;
  int *piVar2;
  int *in_ECX;
  float10 fVar3;
  
  uVar1 = (**(code **)(*in_ECX + 0x65c))();
  piVar2 = (int *)FUN_005ecd90(uVar1);
  in_ECX[0x10] = (int)piVar2;
  (**(code **)(*piVar2 + 0x58))();
  (**(code **)(*(int *)in_ECX[0x10] + 0x78))();
  fVar3 = (float10)(**(code **)(*in_ECX + 0x77c))();
  *(float *)(in_ECX[0x10] + 0x10) = (float)fVar3;
  return;
}



// ?ToBeDeleted@Object@@UAEXH@Z @ 0x005e8bd0

void _ToBeDeleted_Object__UAEXH_Z(undefined4 param_1)

{
  int in_ECX;
  
  _ToBeDeleted_GameThingWithPos__UAEXH_Z(param_1);
  if (*(int **)(in_ECX + 0x44) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x44) + 0xc))(0);
    *(undefined4 *)(in_ECX + 0x44) = 0;
  }
  return;
}



// ?Delete@Object@@UAEXH@Z @ 0x005e8c00

void _Delete_Object__UAEXH_Z(void)

{
  int *in_ECX;
  
  if (in_ECX != (int *)0x0) {
    (**(code **)(*in_ECX + 4))(1);
  }
  return;
}



// ?IsObjectInMapCheck@Object@@UAE_NXZ @ 0x005e8c10

undefined4 _IsObjectInMapCheck_Object__UAE_NXZ(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  if ((*(byte *)((int)in_ECX + 0x25) & 0x80) == 0) {
    iVar1 = FUN_005c04c0();
    if ((iVar1 != 0) && (piVar2 = (int *)FUN_005bfa40(), piVar2 != (int *)0x0)) {
      do {
        if (piVar2 == in_ECX) {
          return 1;
        }
        iVar1 = *piVar2;
        uVar3 = FUN_005bfa00();
        piVar2 = (int *)(**(code **)(iVar1 + 0x53c))(uVar3);
      } while (piVar2 != (int *)0x0);
      return 0;
    }
  }
  else {
    iVar1 = FUN_005c04c0();
    if (iVar1 != 0) {
      piVar2 = (int *)FUN_005bfa60();
      while (piVar2 != (int *)0x0) {
        if (piVar2 == in_ECX) {
          return 1;
        }
        iVar1 = *piVar2;
        uVar3 = FUN_005bfa00();
        piVar2 = (int *)(**(code **)(iVar1 + 0x53c))(uVar3);
      }
    }
  }
  return 0;
}



// ?InsertMapObject@Object@@UAEXXZ @ 0x005e8ca0

void _InsertMapObject_Object__UAEXXZ(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  iVar1 = FUN_005bfa00();
  if (iVar1 != 0) {
    if ((*(uint *)(DAT_00c22ca4 + 0x14) & 0x8000) == 0x8000) {
      uVar2 = (**(code **)(*in_ECX + 0xd8))();
      FUN_00733e17(&DAT_00c62288,s_JEREMY__very_bad__object___s_ins_00b21c98,uVar2);
    }
    iVar1 = *in_ECX;
    uVar2 = FUN_005bfa00();
    (**(code **)(iVar1 + 0x54c))(uVar2);
    *(byte *)(in_ECX + 9) = *(byte *)(in_ECX + 9) | 1;
  }
  return;
}



// ?RemoveMapObject@Object@@UAEXXZ @ 0x005e8d00

void _RemoveMapObject_Object__UAEXXZ(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  iVar1 = FUN_005bfa00();
  if (iVar1 != 0) {
    iVar1 = *in_ECX;
    uVar2 = FUN_005bfa00();
    (**(code **)(iVar1 + 0x550))(uVar2);
    *(ushort *)(in_ECX + 9) = *(ushort *)(in_ECX + 9) & 0xfffe;
  }
  return;
}



// ?IsObjectInMap@Object@@UAE_NPAUMapCell@@@Z @ 0x005e8d30

undefined4 _IsObjectInMap_Object__UAE_NPAUMapCell___Z(undefined4 *param_1)

{
  int *piVar1;
  int *in_ECX;
  
  if ((*(byte *)((int)in_ECX + 0x25) & 0x80) == 0) {
    piVar1 = (int *)*param_1;
    if (piVar1 != (int *)0x0) {
      do {
        if (piVar1 == in_ECX) {
          return 1;
        }
        piVar1 = (int *)(**(code **)(*piVar1 + 0x53c))(param_1);
      } while (piVar1 != (int *)0x0);
      return 0;
    }
  }
  else {
    for (piVar1 = (int *)param_1[1]; piVar1 != (int *)0x0;
        piVar1 = (int *)(**(code **)(*piVar1 + 0x53c))(param_1)) {
      if (piVar1 == in_ECX) {
        return 1;
      }
    }
  }
  return 0;
}



// ?InsertMapObjectToCell@Object@@UAEXPAUMapCell@@@Z @ 0x005e8d90

void _InsertMapObjectToCell_Object__UAEXPAUMapCell___Z(int *param_1)

{
  int iVar1;
  int *piVar2;
  int *in_ECX;
  
  if ((*(byte *)((int)in_ECX + 0x25) & 0x80) == 0) {
    iVar1 = *param_1;
    if (iVar1 != 0) {
      *(int **)(iVar1 + 0x38) = in_ECX;
      (**(code **)(*in_ECX + 0x540))(iVar1,param_1);
    }
    FUN_0074a820(in_ECX);
  }
  else {
    piVar2 = (int *)param_1[1];
    if (piVar2 == (int *)0x0) {
      FUN_005bea40(in_ECX);
    }
    else {
      iVar1 = (**(code **)(*piVar2 + 0x53c))(param_1);
      while (iVar1 != 0) {
        piVar2 = (int *)(**(code **)(*piVar2 + 0x53c))(param_1);
        iVar1 = (**(code **)(*piVar2 + 0x53c))(param_1);
      }
      (**(code **)(*piVar2 + 0x540))();
    }
  }
  if ((in_ECX[0x10] != 0) && ((*(uint *)(in_ECX[0x10] + 8) & 0x100) != 0)) {
    FUN_005a2b10();
  }
  FUN_0059db30();
  return;
}



// ?RemoveMapObjectFromCell@Object@@UAEXPAUMapCell@@@Z @ 0x005e8e30

void _RemoveMapObjectFromCell_Object__UAEXPAUMapCell___Z(int param_1)

{
  undefined4 uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *in_ECX;
  
  if ((*(byte *)((int)in_ECX + 0x25) & 0x80) == 0) {
    if (((in_ECX[0xe] == 0) ||
        (iVar4 = FUN_007344da(in_ECX[0xe],0,&Object::RTTI_Type_Descriptor,
                              &Object::RTTI_Type_Descriptor,0), iVar4 != 0)) && (in_ECX[0xe] != 0))
    {
      iVar4 = FUN_007344da(in_ECX[0xe],0,&Object::RTTI_Type_Descriptor,&Object::RTTI_Type_Descriptor
                           ,0);
      if (iVar4 == 0) {
        piVar3 = (int *)0x0;
      }
      else {
        piVar3 = (int *)in_ECX[0xe];
      }
      iVar4 = (**(code **)(*in_ECX + 0x53c))(param_1);
      (**(code **)(*piVar3 + 0x540))(iVar4,param_1);
      if (iVar4 != 0) {
        *(int **)(iVar4 + 0x38) = piVar3;
      }
      in_ECX[0xe] = 0;
    }
    else {
      iVar4 = (**(code **)(*in_ECX + 0x53c))(param_1);
      FUN_0074a820(iVar4);
      if (iVar4 != 0) {
        *(undefined4 *)(iVar4 + 0x38) = 0;
      }
    }
  }
  else {
    piVar3 = *(int **)(param_1 + 4);
    if (piVar3 == in_ECX) {
      (**(code **)(*in_ECX + 0x53c))(param_1);
      uVar1 = (**(code **)(*in_ECX + 0x53c))(param_1);
      FUN_005bea40(uVar1);
    }
    else {
      for (; piVar3 != (int *)0x0; piVar3 = (int *)(**(code **)(*piVar3 + 0x53c))(param_1)) {
        piVar2 = (int *)(**(code **)(*piVar3 + 0x53c))(param_1);
        if (piVar2 == in_ECX) {
          (**(code **)(*in_ECX + 0x53c))(param_1);
          iVar4 = *piVar3;
          uVar1 = (**(code **)(*in_ECX + 0x53c))(param_1,param_1);
          (**(code **)(iVar4 + 0x540))(uVar1);
          break;
        }
      }
    }
  }
  (**(code **)(*in_ECX + 0x540))(0,param_1);
  if ((in_ECX[0x10] != 0) && ((*(uint *)(in_ECX[0x10] + 8) & 0x100) != 0)) {
    FUN_005a2b10();
  }
  FUN_0059dba0();
  return;
}



// ?MoveMapObject@Object@@UAEIUMapCoords@@@Z @ 0x005e8fa0

undefined4 _MoveMapObject_Object__UAEIUMapCoords___Z(int *param_1)

{
  int *in_ECX;
  
  if ((*(short *)((int)in_ECX + 0x16) == *(short *)((int)param_1 + 2)) &&
     (*(short *)((int)in_ECX + 0x1a) == *(short *)((int)param_1 + 6))) {
    in_ECX[5] = *param_1;
    in_ECX[6] = param_1[1];
    in_ECX[7] = param_1[2];
    return 6;
  }
  (**(code **)(*in_ECX + 0x560))(param_1);
  return 7;
}



// ?IsAttackable@Object@@UAE_NPAV1@@Z @ 0x005e8ff0

undefined4 _IsAttackable_Object__UAE_NPAV1__Z(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x2c))();
  if (iVar1 != 1) {
    return 0;
  }
  if (param_1 != 0) {
    iVar1 = (**(code **)(*in_ECX + 0x6ac))(param_1);
    if (iVar1 == 1) {
      return 0;
    }
  }
  return 1;
}



// ?IsAllied@Object@@UAE_NPAV1@@Z @ 0x005e9030

bool _IsAllied_Object__UAE_NPAV1__Z(int *param_1)

{
  char cVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  uVar2 = (**(code **)(*param_1 + 0x1c))();
  (**(code **)(*in_ECX + 0x1c))(uVar2);
  cVar1 = FUN_005fa4f0(uVar2);
  return cVar1 == '\x01';
}



// ?GetMeshRadius@Object@@UAEMXZ @ 0x005e9060

float10 _GetMeshRadius_Object__UAEMXZ(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x40) + 0xf8))();
  return (float10)*(float *)(iVar1 + 0x30);
}



// ?CallVirtualFunctionsForCreation@Object@@UAEXABUMapCoords@@@Z @ 0x005e9070

void _CallVirtualFunctionsForCreation_Object__UAEXABUMapCoords___Z(void)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  float10 fVar3;
  
  (**(code **)(*in_ECX + 0x538))();
  (**(code **)(*in_ECX + 0x850))();
  iVar1 = (**(code **)(*in_ECX + 0x60c))(2);
  if ((iVar1 < 0) || (*DAT_00d76c64 <= iVar1)) {
    iVar1 = 0;
  }
  iVar1 = DAT_00d76c64[iVar1 + 1];
  iVar2 = (**(code **)(*in_ECX + 0x60c))(1);
  if ((iVar2 < 0) || (*DAT_00d76c64 <= iVar2)) {
    iVar2 = 0;
  }
  iVar2 = DAT_00d76c64[iVar2 + 1];
  (**(code **)(*in_ECX + 0x60c))(0);
  (**(code **)(*(int *)in_ECX[0x10] + 0xf4))(iVar2,iVar1);
  iVar1 = *in_ECX;
  fVar3 = (float10)(**(code **)(iVar1 + 0x120))();
  fVar3 = (float10)(**(code **)(*in_ECX + 0x50c))((float)fVar3);
  fVar3 = (float10)(**(code **)(*in_ECX + 0x508))((float)fVar3);
  fVar3 = (float10)(**(code **)(*in_ECX + 0x504))((float)fVar3);
  (**(code **)(iVar1 + 0x518))((float)fVar3);
  if (((*(byte *)(in_ECX + 9) & 4) == 0) && ((*(byte *)((int)in_ECX + 10) & 0x11) == 0)) {
    (**(code **)(*in_ECX + 0x544))();
  }
  return;
}



// ?GetNearestEdgeOfObject@Object@@UAEXPAV1@@Z @ 0x005e9160

void _GetNearestEdgeOfObject_Object__UAEXPAV1__Z(undefined4 param_1,int param_2)

{
  int *in_ECX;
  float10 fVar1;
  float afStack_c [2];
  float *pfStack_4;
  
  (**(code **)(*in_ECX + 0x838))();
  fVar1 = (float10)FUN_00760fd0();
  pfStack_4[2] = (float)param_2 * 0.00015258789;
  *pfStack_4 = (float)(int)afStack_c * 0.00015258789;
  pfStack_4[1] = (float)(fVar1 + (float10)afStack_c[0]);
  return;
}



// ?GetNearestPosOfObject@Object@@UAEXPAV1@@Z @ 0x005e91c0

undefined4 _GetNearestPosOfObject_Object__UAEXPAV1__Z(undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  int *in_ECX;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  undefined1 auStack_c [12];
  
  fVar2 = (float10)FUN_006de3e0(in_ECX + 5,param_2 + 5);
  fVar3 = (float10)(**(code **)(*param_2 + 100))();
  fVar4 = (float10)(**(code **)(*in_ECX + 100))();
  uVar1 = FUN_006de5a0(auStack_c,(float)fVar2,(float)(fVar4 + (float10)(float)fVar3));
  FUN_005c1360(param_1,uVar1);
  return param_1;
}



// ?GetNearestEdgeToPos@Object@@UAEXPBUMapCoords@@@Z @ 0x005e9230

undefined4 _GetNearestEdgeToPos_Object__UAEXPBUMapCoords___Z(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int *in_ECX;
  float10 fVar2;
  float10 fVar3;
  undefined1 auStack_c [12];
  
  fVar2 = (float10)FUN_006de3e0(in_ECX + 5,param_2);
  fVar3 = (float10)(**(code **)(*in_ECX + 100))();
  uVar1 = FUN_006de5a0(auStack_c,(float)fVar2,(float)fVar3);
  FUN_005c1360(param_1,uVar1);
  return param_1;
}



// ?GetNearestEdge@Object@@UAEXMM@Z @ 0x005e9280

undefined4 _GetNearestEdge_Object__UAEXMM_Z(undefined4 param_1,undefined4 param_2,float param_3)

{
  undefined4 uVar1;
  int *in_ECX;
  float10 fVar2;
  undefined1 auStack_c [12];
  
  fVar2 = (float10)(**(code **)(*in_ECX + 100))();
  uVar1 = FUN_006de5a0(auStack_c,param_2,(float)(fVar2 + (float10)param_3));
  FUN_005c1360(param_1,uVar1);
  return param_1;
}



// ?InitialisePhysicsFromHand@Object@@UAEIPAULHPoint@@0PAVGInterfaceStatus@@PAV1@H@Z @ 0x005e9390

int _InitialisePhysicsFromHand_Object__UAEIPAULHPoint__0PAVGInterfaceStatus__PAV1_H_Z
              (float *param_1,undefined4 *param_2,int *param_3,int *param_4,int param_5)

{
  uint uVar1;
  uint uVar2;
  float fVar3;
  int iVar4;
  int *piVar5;
  int *in_ECX;
  int *piVar6;
  bool bVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  float local_48;
  float local_10;
  int local_c;
  char local_5;
  
  if ((*(byte *)(in_ECX + 9) & 0x40) != 0) {
    return 0;
  }
  FUN_005e9300();
  piVar6 = param_3;
  bVar7 = param_4 != (int *)0x0;
  *(ushort *)(in_ECX + 9) = *(ushort *)(in_ECX + 9) & 0xffdf | 0x40;
  if ((!bVar7) && (param_3 != (int *)0x0)) {
    param_3[0x49] = (int)in_ECX;
  }
  local_5 = bVar7;
  iVar4 = (**(code **)(*in_ECX + 0x178))();
  if (iVar4 != 0) {
    (**(code **)(*in_ECX + 0x548))();
  }
  if ((DAT_00c685cc != 0) && (DAT_00c685d0 == in_ECX)) {
    DAT_00c685cc = 0;
    FUN_00759d60();
  }
  local_c = FUN_005f30f0();
  if (local_c == 0) {
    return 0;
  }
  if ((int *)in_ECX[0x10] != (int *)0x0) {
    iVar4 = (**(code **)(*(int *)in_ECX[0x10] + 0x14))();
    if (iVar4 != 0) {
      *(uint *)(local_c + 0x1d8) = *(uint *)(local_c + 0x1d8) | 0x20;
      (**(code **)(*(int *)in_ECX[0x10] + 0x10))();
    }
    iVar4 = (**(code **)(*(int *)in_ECX[0x10] + 0x9c))();
    if (iVar4 != 0) {
      *(uint *)(local_c + 0x1d8) = *(uint *)(local_c + 0x1d8) | 0x40;
      (**(code **)(*(int *)in_ECX[0x10] + 0x98))();
    }
  }
  *(undefined4 *)(local_c + 0x90) = *param_2;
  *(undefined4 *)(local_c + 0x94) = param_2[1];
  *(undefined4 *)(local_c + 0x98) = param_2[2];
  fVar3 = param_1[2] * param_1[2] + *param_1 * *param_1;
  if (bVar7) {
    if (fVar3 <= 1.0) {
      bVar7 = false;
      iVar4 = (**(code **)(*in_ECX + 0x478))();
      FUN_0075b1b0(0,CONCAT31((int3)((uint)-iVar4 >> 8),'\x01' - (iVar4 != 0)));
      local_10 = *(float *)(local_c + 0xcc);
      FUN_0075b830();
      FUN_005f3550(&local_c);
    }
    else {
      local_10 = *(float *)(local_c + 0xcc);
      bVar7 = true;
    }
  }
  else {
    bVar7 = 4.0 < fVar3;
    iVar4 = (**(code **)(*in_ECX + 0x478))();
    FUN_0075b1b0(bVar7,CONCAT31((int3)((uint)-iVar4 >> 8),'\x01' - (iVar4 != 0)));
    local_10 = *(float *)(local_c + 0xcc);
    FUN_0075b830();
    FUN_005f3550(&local_c);
    *(uint *)(local_c + 0x1d8) = *(uint *)(local_c + 0x1d8) | 4;
  }
  FUN_005bf830(local_c + 200);
  if ((bVar7) ||
     ((local_10 != *(float *)(local_c + 0xcc) &&
      (((iVar4 = (**(code **)(*in_ECX + 0x2c8))(0), iVar4 == 0 || (piVar6 == (int *)0x0)) ||
       (iVar4 = (**(code **)(*piVar6 + 0x1c))(), *(int *)(iVar4 + 0xf8) != 2)))))) {
LAB_005e986e:
    iVar4 = (**(code **)(*in_ECX + 0x2c8))(0);
    if (iVar4 != 0) {
      FUN_006e0aa0(param_1,0,param_2);
    }
    if (piVar6 != (int *)0x0) {
      (**(code **)(*piVar6 + 0x1c))();
    }
    FUN_0067efc0();
    FUN_00466720();
  }
  else {
    iVar4 = FUN_005bfb70();
    if (iVar4 == 0) {
      uVar1 = (uint)ROUND(*(float *)(local_c + 0xd0) * 0.1);
      uVar2 = (uint)ROUND(*(float *)(local_c + 200) * 0.1);
      if ((((((int)uVar2 < 0) || (0x1ff < (int)uVar2)) ||
           (((int)uVar1 < 0 ||
            ((0x1ff < (int)uVar1 ||
             (piVar6 = param_3,
             (byte)(&DAT_00d73794)[((int)uVar1 >> 4) + ((int)uVar2 >> 4) * 0x20] == 0)))))) ||
          (iVar4 = (&DAT_00d73394)
                   [(byte)(&DAT_00d73794)[((int)uVar1 >> 4) + ((int)uVar2 >> 4) * 0x20]] +
                   ((uVar2 & 0xf) * 0x11 + (uVar1 & 0xf)) * 8, iVar4 == 0)) ||
         (*(byte *)(iVar4 + 4) < 2)) goto LAB_005e986e;
    }
    iVar4 = (**(code **)(*in_ECX + 0x3c4))();
    if ((iVar4 != 0) || (iVar4 = (**(code **)(*in_ECX + 0x3cc))(), iVar4 != 0)) {
      __ftol();
      __ftol();
      FUN_00761570();
      if (local_48 < 0.7) goto LAB_005e986e;
    }
    iVar4 = (**(code **)(*in_ECX + 0x2c8))(0);
    if (((iVar4 != 0) && (piVar5 = (int *)FUN_00527d60(), piVar5 == piVar6)) &&
       (in_ECX[0x41] != (uint)*(byte *)((int)in_ECX + 0xf2))) {
      FUN_006b3530(piVar5,(uint)*(byte *)((int)in_ECX + 0xf2));
    }
    *(uint *)(local_c + 0x1d8) = *(uint *)(local_c + 0x1d8) | 8;
    FUN_004cb680();
    iVar4 = (**(code **)(*in_ECX + 0x3c4))();
    if (((iVar4 != 0) || (iVar4 = (**(code **)(*in_ECX + 0x3cc))(), iVar4 != 0)) ||
       ((iVar4 = (**(code **)(*in_ECX + 0x338))(), iVar4 != 0 &&
        ((in_ECX[0x11] == 0 && (iVar4 = FUN_005bfc70(), iVar4 != 0)))))) {
      iVar4 = (**(code **)(*in_ECX + 0x338))();
      if ((iVar4 != 0) && (local_5 == '\0')) {
        param_1 = (float *)0x0;
        param_2 = (undefined4 *)0x0;
        param_3 = (int *)0x0;
        FUN_00759210(&param_2,&param_1,&param_3);
        if (((param_5 != 0) || (0.2 < ABS((float)param_1))) || (0.2 < ABS((float)param_3))) {
          *(uint *)(local_c + 0x1d8) = *(uint *)(local_c + 0x1d8) & 0xfffffff7;
          goto LAB_005e98b4;
        }
      }
      FUN_005f5720();
    }
  }
LAB_005e98b4:
  if (((piVar6 != (int *)0x0) && (iVar4 = (**(code **)(*in_ECX + 0x3b4))(0), iVar4 != 0)) &&
     ((param_4 == (int *)0x0 || (iVar4 = (**(code **)(*param_4 + 0x34))(), iVar4 == 0)))) {
    uVar9 = 0;
    uVar8 = 0x29;
    (**(code **)(*piVar6 + 0x1c))(piVar6,0x29);
    FUN_004cb260(piVar6,uVar8,in_ECX,uVar9);
  }
  return local_c;
}



// ?InitialisePhysics@Object@@UAEIPBULHPoint@@0PAV1@_NPAVGInterfaceStatus@@@Z @ 0x005e9900

void _InitialisePhysics_Object__UAEIPBULHPoint__0PAV1__NPAVGInterfaceStatus___Z(int *param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  char in_stack_00000014;
  
  if (((*(ushort *)(in_ECX + 9) & 0x40) == 0) && ((*(ushort *)(in_ECX + 9) & 0x1000) == 0)) {
    FUN_005e9300();
    *(ushort *)(in_ECX + 9) = *(ushort *)(in_ECX + 9) & 0xffdf | 0x40;
    iVar1 = (**(code **)(*in_ECX + 0x178))();
    if (iVar1 != 0) {
      (**(code **)(*in_ECX + 0x548))();
    }
    iVar1 = 0;
    if (in_stack_00000014 != '\0') {
      (**(code **)(*in_ECX + 0x63c))(in_ECX[0x10] + 0x14);
      iVar1 = FUN_005f30f0();
      if (iVar1 == 0) goto LAB_005e9982;
      if ((int *)in_ECX[0x10] != (int *)0x0) {
        iVar2 = (**(code **)(*(int *)in_ECX[0x10] + 0x14))();
        if (iVar2 != 0) {
          *(uint *)(iVar1 + 0x1d8) = *(uint *)(iVar1 + 0x1d8) | 0x20;
          (**(code **)(*(int *)in_ECX[0x10] + 0x10))();
        }
        iVar2 = (**(code **)(*(int *)in_ECX[0x10] + 0x9c))();
        if ((iVar2 != 0) && ((*(uint *)(iVar1 + 0x1d8) & 4) != 0)) {
          *(uint *)(iVar1 + 0x1d8) = *(uint *)(iVar1 + 0x1d8) | 0x40;
          (**(code **)(*(int *)in_ECX[0x10] + 0x98))();
        }
        FUN_00466720();
      }
    }
    if ((in_ECX[0x11] != 0) && ((*(uint *)(DAT_00c22ca4 + 0x14) & 0x8000) == 0)) {
      FUN_006c6d10(0);
    }
    *param_1 = iVar1;
    param_1[1] = 1;
    return;
  }
LAB_005e9982:
  *param_1 = 0;
  param_1[1] = 0;
  return;
}



// ?EndPhysics@Object@@UAEXPAVPhysicsObject@@_N@Z @ 0x005e9a20

void _EndPhysics_Object__UAEXPAVPhysicsObject___N_Z(int param_1,char param_2)

{
  int iVar1;
  int *in_ECX;
  
  if ((param_1 != 0) && ((*(byte *)(in_ECX + 9) & 0x40) == 0)) {
    return;
  }
  *(ushort *)(in_ECX + 9) = *(ushort *)(in_ECX + 9) & 0xffbf;
  in_ECX[0xb] = in_ECX[5];
  in_ECX[0xc] = in_ECX[6];
  in_ECX[0xd] = in_ECX[7];
  if (((int *)in_ECX[0x10] != (int *)0x0) && (param_1 != 0)) {
    if ((*(byte *)(param_1 + 0x1d8) & 0x20) != 0) {
      (**(code **)(*(int *)in_ECX[0x10] + 0x10))();
    }
    if ((*(byte *)(param_1 + 0x1d8) & 0x40) != 0) {
      (**(code **)(*(int *)in_ECX[0x10] + 0x98))();
    }
  }
  if ((param_2 != '\0') && ((*(byte *)((int)in_ECX + 10) & 1) == 0)) {
    iVar1 = FUN_005c04c0();
    if (iVar1 == 0) {
      (**(code **)(*in_ECX + 0xc))(0);
    }
    else {
      (**(code **)(*in_ECX + 0x544))();
    }
  }
  FUN_0067f9d0();
  FUN_004cb680();
  return;
}



// ?InterfaceSetOutMagicHand@Object@@UAE_NPAVGInterfaceStatus@@@Z @ 0x005e9ae0

undefined4 _InterfaceSetOutMagicHand_Object__UAE_NPAVGInterfaceStatus___Z(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x44) != 0) {
    FUN_006c6d60();
  }
  return 1;
}



// ?GetCollideSoundType@Object@@UAE?AW4SOUND_COLLISION_TYPE@@XZ @ 0x005e9b00

undefined4 _GetCollideSoundType_Object__UAE_AW4SOUND_COLLISION_TYPE__XZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x28) + 0x48);
}



// ?GetPhysicsConstantsType@Object@@UAEIXZ @ 0x005e9b10

bool _GetPhysicsConstantsType_Object__UAEIXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x7b0))();
  return iVar1 != 0;
}



// ?SetUpPhysOb@Object@@UAEXPAVPhysOb@@@Z @ 0x005e9b20

void _SetUpPhysOb_Object__UAEXPAVPhysOb___Z(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  float10 fVar4;
  float fStack_4;
  
  iVar1 = (**(code **)(*in_ECX + 0x788))();
  fVar4 = (float10)(**(code **)(*in_ECX + 0x638))();
  fStack_4 = (float)fVar4;
  if (fVar4 < (float10)0.01) {
    fStack_4 = 0.01;
  }
  iVar2 = (**(code **)(*in_ECX + 0x7b0))();
  if ((iVar2 == 0) || ((*(byte *)((int)in_ECX + 0x25) & 0x10) != 0)) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  FUN_00759e40(fStack_4,&DAT_00be7740 + iVar1 * 6,uVar3);
  FUN_0075a0f0();
  return;
}



// ?GetBoundingSphere@Object@@UAEXPAULHPoint@@PAM@Z @ 0x005e9ba0

void _GetBoundingSphere_Object__UAEXPAULHPoint__PAM_Z(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  int *in_ECX;
  float10 fVar3;
  
  fVar3 = (float10)(**(code **)(*in_ECX + 0x42c))();
  fVar1 = (float)(fVar3 * (float10)0.5);
  fVar3 = (float10)(**(code **)(*in_ECX + 100))();
  *param_2 = (float)SQRT((float10)fVar1 * (float10)fVar1 + fVar3 * fVar3);
  fVar2 = (float)in_ECX[7];
  fVar3 = (float10)FUN_00760fd0();
  param_1[1] = (float)(fVar3 + (float10)fVar2);
  *param_1 = (float)in_ECX[5] * 0.00015258789;
  param_1[2] = (float)in_ECX[6] * 0.00015258789;
  param_1[1] = (float)(fVar3 + (float10)fVar2 + (float10)fVar1);
  return;
}



// ?InteractsWithPhysicsObjects@Object@@UAE_NXZ @ 0x005e9c20

bool _InteractsWithPhysicsObjects_Object__UAE_NXZ(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0x40) != 0;
}



// ?ShouldPhysicsRaiseObjectUntilNotIntersectingThis@Object@@UAEXPAV1@@Z @ 0x005e9c30

void _ShouldPhysicsRaiseObjectUntilNotIntersectingThis_Object__UAEXPAV1__Z(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x79c))();
  return;
}



// ?CleanupWhenDeleted@Object@@UAEXH@Z @ 0x005e9c40

void _CleanupWhenDeleted_Object__UAEXH_Z(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x178))();
  if (iVar1 != 0) {
    (**(code **)(*in_ECX + 0x548))();
  }
  return;
}



// ?ReduceLife@Object@@UAEMMPAVGPlayer@@@Z @ 0x005e9c60

void _ReduceLife_Object__UAEMMPAVGPlayer___Z(float param_1)

{
  int *in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 0x11c))();
  if (fVar1 < (float10)param_1) {
    (**(code **)(*in_ECX + 0x5b0))(0);
    (**(code **)(*in_ECX + 0x11c))();
    return;
  }
  (**(code **)(*in_ECX + 0x5b0))((float)(fVar1 - (float10)param_1));
  (**(code **)(*in_ECX + 0x11c))();
  return;
}



// ?IncreaseLife@Object@@UAEXM@Z @ 0x005e9cc0

void _IncreaseLife_Object__UAEXM_Z(float param_1)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  
  fVar2 = (float10)(**(code **)(*in_ECX + 0x11c))();
  if ((float10)1.0 < fVar2 + (float10)param_1) {
    fVar2 = (float10)(**(code **)(*in_ECX + 0x11c))();
    param_1 = (float)((float10)1.0 - fVar2);
  }
  if (param_1 != 0.0) {
    iVar1 = *in_ECX;
    fVar2 = (float10)(**(code **)(iVar1 + 0x11c))();
    (**(code **)(iVar1 + 0x5b0))((float)(fVar2 + (float10)param_1));
  }
  (**(code **)(*in_ECX + 0x11c))();
  return;
}



// ?DestroyedByEffect@Object@@UAEIPAVGPlayer@@M@Z @ 0x005e9d30

undefined4 _DestroyedByEffect_Object__UAEIPAVGPlayer__M_Z(void)

{
  int *in_ECX;
  
  if ((*(byte *)((int)in_ECX + 10) & 1) == 0) {
    (**(code **)(*in_ECX + 0xc))(0);
  }
  return 1;
}



// ?FillInEffectDefenceMultiplier@Object@@UAEXPAVEffectNumbers@@@Z @ 0x005e9d50

void _FillInEffectDefenceMultiplier_Object__UAEXPAVEffectNumbers___Z(undefined4 *param_1)

{
  int in_ECX;
  int iVar1;
  int iVar2;
  
  iVar1 = 0x90 - (int)param_1;
  iVar2 = 7;
  do {
    *param_1 = *(undefined4 *)(*(int *)(in_ECX + 0x28) + iVar1 + (int)param_1);
    param_1 = param_1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return;
}



// ?ApplyEffect@Object@@UAEXPBXPAVEffectValues@@@Z @ 0x005e9dd0

int _ApplyEffect_Object__UAEXPBXPAVEffectValues___Z(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *in_ECX;
  uint uVar6;
  float unaff_EBX;
  int iVar7;
  float unaff_ESI;
  float10 fVar8;
  
  (**(code **)(*in_ECX + 0x11c))();
  (**(code **)(*in_ECX + 0x5d0))(param_1);
  fVar8 = (float10)(**(code **)(*in_ECX + 0x5d4))(param_1);
  if (0.0 < (float)fVar8) {
    (**(code **)(*in_ECX + 0x5bc))((float)fVar8);
  }
  if (0.0 < unaff_EBX) {
    iVar3 = *in_ECX;
    uVar2 = FUN_004fc9c0();
    (**(code **)(iVar3 + 0x5b8))(unaff_EBX,uVar2);
  }
  fVar8 = (float10)(**(code **)(*in_ECX + 0x11c))();
  if ((fVar8 == (float10)0.0) && (unaff_ESI != 0.0)) {
    if ((*(int **)(param_1 + 0x28) != (int *)0x0) &&
       (iVar3 = (**(code **)(**(int **)(param_1 + 0x28) + 0xa4))(), iVar3 != 0)) {
      *(float *)(iVar3 + 0x11c0) = *(float *)(iVar3 + 0x11c0) + 1.0;
    }
    iVar3 = *in_ECX;
    uVar2 = FUN_004fc9c0(unaff_ESI);
    (**(code **)(iVar3 + 0x5f8))(uVar2);
  }
  (**(code **)(*in_ECX + 0x11c))();
  if (((0.01 < *(float *)(param_1 + 0xc)) && (iVar3 = (**(code **)(*in_ECX + 0x62c))(), iVar3 != 0))
     && (iVar3 = FUN_0067fa90(), iVar3 == 0)) {
    piVar4 = (int *)FUN_007344da(*(undefined4 *)(param_1 + 0x28),0,&GameThing::RTTI_Type_Descriptor,
                                 &GameThingWithPos::RTTI_Type_Descriptor,0);
    if (piVar4 == (int *)0x0) {
      piVar4 = in_ECX;
    }
    uVar2 = (**(code **)(*in_ECX + 0x1c))(1);
    FUN_0067efc0(piVar4,0x12,uVar2);
  }
  fVar8 = (float10)FUN_006c51b0();
  fVar1 = (float)(fVar8 + (float10)unaff_EBX);
  iVar3 = FUN_004fcab0();
  if (((iVar3 != 0) && (iVar3 = (**(code **)(*in_ECX + 0x48))(), iVar3 != 0)) &&
     ((*(int *)(param_1 + 0x28) != 0 &&
      ((fVar1 != 0.0 &&
       (iVar3 = FUN_007344da(*(int *)(param_1 + 0x28),0,&GameThing::RTTI_Type_Descriptor,
                             &GameThingWithPos::RTTI_Type_Descriptor,0), iVar3 != 0)))))) {
    fVar8 = (float10)(**(code **)(*in_ECX + 0x588))(fVar1);
    FUN_006cfb10(param_1,(float)fVar8);
  }
  if ((*(int **)(param_1 + 0x28) == (int *)0x0) ||
     (iVar3 = (**(code **)(**(int **)(param_1 + 0x28) + 0x34))(), iVar3 == 0)) {
    iVar3 = FUN_004fc9c0();
    if (iVar3 == 0) {
      return 0;
    }
    iVar3 = FUN_004fc9c0();
    iVar7 = *(int *)(iVar3 + 0x60);
    iVar5 = (**(code **)(*in_ECX + 0x1c))();
    iVar3 = 0;
    if (iVar5 != 0) {
      iVar3 = FUN_004fc9c0();
      iVar5 = (**(code **)(*in_ECX + 0x1c))();
      uVar6 = (uint)*(byte *)(iVar3 + 0xb5);
      *(float *)(iVar5 + 0x94 + uVar6 * 4) = fVar1 + *(float *)(iVar5 + 0x94 + uVar6 * 4);
      iVar3 = iVar5 + 0x94 + uVar6 * 4;
    }
  }
  else {
    iVar3 = (**(code **)(**(int **)(param_1 + 0x28) + 0xa4))();
    iVar7 = *(int *)(iVar3 + 0x168);
  }
  if (iVar7 != 0) {
    iVar3 = FUN_00412320(in_ECX,param_1,unaff_ESI);
  }
  return iVar3;
}



// ?ReduceLifeDueToBurning@Object@@UAEXMPAVGPlayer@@@Z @ 0x005ea070

void _ReduceLifeDueToBurning_Object__UAEXMPAVGPlayer___Z(float param_1,undefined4 param_2)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  float fVar5;
  
  if ((*(byte *)((int)in_ECX + 10) & 4) == 0) {
    (**(code **)(*in_ECX + 0x5b8))(param_1,param_2);
    iVar1 = (**(code **)(*in_ECX + 0x48))();
    if ((iVar1 != 0) && (param_1 != 0.0)) {
      fVar2 = (float10)(**(code **)(*in_ECX + 0x588))(param_1);
      fVar5 = (float)fVar2;
      uVar4 = 0x3f800000;
      uVar3 = 0;
      fVar2 = (float10)FUN_005ebcd0(0,0x3f800000,param_2,fVar5);
      uVar3 = FUN_004fc5a0(0,(float)fVar2,uVar3,uVar4,param_2);
      FUN_006cfb10(uVar3,fVar5);
      FUN_00430270();
    }
  }
  (**(code **)(*in_ECX + 0x11c))();
  return;
}



// ?GetHeatCapacity@Object@@UAEMXZ @ 0x005ea130

float10 _GetHeatCapacity_Object__UAEMXZ(void)

{
  int in_ECX;
  
  return (float10)*(float *)(*(int *)(in_ECX + 0x28) + 0xb0);
}



// ?GetActualObjectToEffect@Object@@UAEPAXPAVGPlayer@@_N@Z @ 0x005ea140

void _GetActualObjectToEffect_Object__UAEPAXPAVGPlayer___N_Z(void)

{
  return;
}



// ?GetDamageEffect@Object@@UAEMPAVEffectValues@@@Z @ 0x005ea150

float10 _GetDamageEffect_Object__UAEMPAVEffectValues___Z(int param_1)

{
  int *in_ECX;
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  float unaff_ESI;
  float10 fVar4;
  float afStack_1c [7];
  
  pfVar2 = afStack_1c;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar2 = 0.0;
    pfVar2 = pfVar2 + 1;
  }
  FUN_006c6940();
  (**(code **)(*in_ECX + 0x5c8))(afStack_1c);
  fVar4 = (float10)unaff_ESI;
  pfVar3 = afStack_1c;
  pfVar2 = (float *)(param_1 + 0xc);
  iVar1 = 2;
  do {
    if ((float10)0.0 < (float10)*pfVar2 * (float10)*pfVar3) {
      fVar4 = (float10)*pfVar2 * (float10)*pfVar3 + fVar4;
    }
    pfVar2 = pfVar2 + 1;
    pfVar3 = pfVar3 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  return fVar4;
}



// ?GetHealEffect@Object@@UAEMPAVEffectValues@@@Z @ 0x005ea1d0

float10 _GetHealEffect_Object__UAEMPAVEffectValues___Z(void)

{
  int *in_ECX;
  int iVar1;
  float unaff_EDI;
  float *pfVar2;
  float10 fVar3;
  int unaff_retaddr;
  float afStack_1c [7];
  
  pfVar2 = afStack_1c;
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *pfVar2 = 0.0;
    pfVar2 = pfVar2 + 1;
  }
  (**(code **)(*in_ECX + 0x5c8))(afStack_1c);
  fVar3 = (float10)*(float *)(unaff_retaddr + 0x14) * (float10)afStack_1c[2];
  if (fVar3 <= (float10)0.0) {
    fVar3 = (float10)unaff_EDI;
  }
  return fVar3;
}



// ?IsTouching@Object@@UAE_NPAV1@M@Z @ 0x005ea230

undefined4 _IsTouching_Object__UAE_NPAV1_M_Z(float param_1)

{
  int *in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 0x6c4))(param_1);
  if (fVar1 <= (float10)param_1) {
    return 1;
  }
  return 0;
}



// ?IsTouching@Object@@UAE_NPAUMapCoords@@@Z @ 0x005ea260

undefined4 _IsTouching_Object__UAE_NPAUMapCoords___Z(undefined4 param_1)

{
  int *in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 0x13c))(param_1);
  if (fVar1 <= (float10)0.0) {
    return 1;
  }
  return 0;
}



// ?IsTouching@Object@@UAE_NPAUMapCoords@@0@Z @ 0x005ea290

undefined4 _IsTouching_Object__UAE_NPAUMapCoords__0_Z(int *param_1,int *param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int *in_ECX;
  float10 fVar5;
  float fStack_c;
  float fStack_4;
  
  fVar1 = (float)*param_1 * 10.0 * 1.5258789e-05;
  fVar2 = (float)*param_2 * 10.0 * 1.5258789e-05;
  fVar4 = fVar1;
  if (fVar2 <= fVar1) {
    fVar4 = fVar2;
  }
  fVar3 = (float)param_1[1] * 10.0 * 1.5258789e-05;
  fStack_c = (float)param_2[1] * 10.0 * 1.5258789e-05;
  fStack_4 = fStack_c;
  if (fVar3 < fStack_c) {
    fStack_4 = fVar3;
  }
  param_2 = (int *)fVar2;
  if (fVar2 < fVar1) {
    param_2 = (int *)fVar1;
  }
  if (fStack_c < fVar3) {
    fStack_c = fVar3;
  }
  fVar5 = (float10)(**(code **)(*in_ECX + 100))();
  fVar1 = (float)fVar5;
  fVar2 = (float)in_ECX[5] * 10.0 * 1.5258789e-05;
  if ((((fVar4 <= fVar2 + fVar1) && (fVar2 - fVar1 <= (float)param_2)) &&
      (fVar2 = (float)in_ECX[6] * 10.0 * 1.5258789e-05, fStack_4 <= fVar2 + fVar1)) &&
     (fVar2 - fVar1 <= fStack_c)) {
    return 1;
  }
  return 0;
}



// ?GetDistanceFromObject@Object@@UAEMPAV1@@Z @ 0x005ea3e0

float10 _GetDistanceFromObject_Object__UAEMPAV1__Z(int *param_1)

{
  int *in_ECX;
  float10 fVar1;
  float10 fVar2;
  float10 fVar3;
  
  fVar1 = (float10)FUN_006de0a0(in_ECX + 5,param_1 + 5);
  fVar2 = (float10)(**(code **)(*param_1 + 100))();
  fVar3 = (float10)(**(code **)(*in_ECX + 100))();
  return (float10)(float)fVar1 - (fVar3 + (float10)(float)fVar2);
}



// ?ApplySingleEffect@Object@@UAEXW4EFFECT_TYPE@@MPAVGameThing@@PBUMapCoords@@@Z @ 0x005ea420

void _ApplySingleEffect_Object__UAEXW4EFFECT_TYPE__MPAVGameThing__PBUMapCoords___Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *in_ECX;
  undefined1 local_40 [64];
  
  FUN_004fc5a0(param_1,param_2,param_3,0x3f800000,0);
  (**(code **)(*in_ECX + 0x5cc))(local_40,0);
  FUN_00430270();
  return;
}



// ?ActualMoveMapObject@Object@@UAEXUMapCoords@@@Z @ 0x005ea470

void _ActualMoveMapObject_Object__UAEXUMapCoords___Z(undefined4 param_1)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x548))();
  (**(code **)(*in_ECX + 0xfc))(param_1);
  (**(code **)(*in_ECX + 0x544))();
  return;
}



// ?GetHeight@Object@@UAEMXZ @ 0x005ea4f0

float10 _GetHeight_Object__UAEMXZ(void)

{
  int iVar1;
  int in_ECX;
  float10 fVar2;
  
  if (*(int **)(in_ECX + 0x40) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(in_ECX + 0x40) + 0xf8))();
    if (iVar1 != 0) {
      fVar2 = (float10)*(float *)(iVar1 + 0x28) * (float10)*(float *)(in_ECX + 0x50);
      return fVar2 + fVar2;
    }
  }
  return (float10)0.0;
}



// ?GetHeightForHandAboveInteractObject@Object@@UAEMXZ @ 0x005ea520

void _GetHeightForHandAboveInteractObject_Object__UAEMXZ(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005ea522. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0x42c))();
  return;
}



// ?GetTopPos@Object@@UAEMXZ @ 0x005ea530

float10 _GetTopPos_Object__UAEMXZ(void)

{
  float fVar1;
  int *in_ECX;
  float10 fVar2;
  
  fVar1 = (float)in_ECX[7];
  fVar2 = (float10)(**(code **)(*in_ECX + 0x42c))();
  return fVar2 + (float10)fVar1;
}



// ?Get2DRadius@Object@@UAEMXZ @ 0x005ea550

float10 _Get2DRadius_Object__UAEMXZ(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  float10 fVar4;
  
  if (in_ECX[0x10] == 0) {
    return (float10)0.0;
  }
  fVar4 = (float10)(**(code **)(*in_ECX + 0x120))();
  piVar1 = (int *)in_ECX[0x10];
  iVar2 = (**(code **)(*piVar1 + 0xf8))();
  iVar3 = (**(code **)(*piVar1 + 0xf8))();
  if (*(float *)(iVar3 + 0x2c) < *(float *)(iVar2 + 0x24)) {
    iVar2 = (**(code **)(*piVar1 + 0xf8))();
    return (float10)*(float *)(iVar2 + 0x24) * (float10)(float)fVar4;
  }
  iVar2 = (**(code **)(*piVar1 + 0xf8))();
  return (float10)*(float *)(iVar2 + 0x2c) * (float10)(float)fVar4;
}



// ?GetWorldMatrix@Object@@UAEXPAULHMatrix@@@Z @ 0x005ea5d0

void _GetWorldMatrix_Object__UAEXPAULHMatrix___Z(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int *in_ECX;
  float10 fVar6;
  float10 fVar7;
  float10 fVar8;
  
  fVar3 = (float)in_ECX[7];
  fVar6 = (float10)FUN_00760fd0();
  fVar3 = (float)(fVar6 + (float10)fVar3);
  fVar4 = (float)in_ECX[5] * 0.00015258789;
  fVar5 = (float)in_ECX[6] * 0.00015258789;
  fVar6 = (float10)(**(code **)(*in_ECX + 0x120))();
  fVar1 = (float)fVar6;
  fVar6 = (float10)(**(code **)(*in_ECX + 0x508))();
  fVar2 = (float)fVar6;
  if (fVar6 == (float10)0.0) {
    if (fVar1 != 1.0) {
      param_1[7] = 0.0;
      param_1[6] = 0.0;
      param_1[5] = 0.0;
      param_1[3] = 0.0;
      param_1[2] = 0.0;
      param_1[1] = 0.0;
      param_1[4] = fVar1;
      param_1[8] = fVar1;
      *param_1 = fVar1;
      param_1[9] = fVar4;
      param_1[10] = fVar3;
      param_1[0xb] = fVar5;
      return;
    }
    FUN_00402280();
    param_1[9] = fVar4;
    param_1[10] = fVar3;
    param_1[0xb] = fVar5;
    return;
  }
  if (fVar1 != 1.0) {
    fVar6 = (float10)fcos((float10)fVar2);
    param_1[7] = 0.0;
    param_1[6] = 0.0;
    param_1[2] = 0.0;
    param_1[1] = 0.0;
    param_1[5] = 0.0;
    param_1[3] = 0.0;
    *param_1 = fVar1;
    param_1[4] = fVar1;
    param_1[8] = fVar1;
    param_1[9] = fVar4;
    param_1[10] = fVar3;
    param_1[0xb] = fVar5;
    fVar7 = (float10)fsin((float10)fVar2);
    fVar8 = (float10)0.0;
    *param_1 = (float)(fVar8 + fVar6 * (float10)fVar1);
    param_1[6] = 0.0 - (float)(fVar7 * (float10)fVar1);
    param_1[1] = (float)((float10)0.0 + fVar8);
    param_1[7] = (float)((float10)0.0 - fVar8);
    param_1[2] = (float)(fVar7 * (float10)fVar1) + 0.0;
    param_1[8] = (float)(fVar6 * (float10)fVar1 - fVar8);
    return;
  }
  fVar6 = (float10)fcos((float10)fVar2);
  param_1[7] = 0.0;
  param_1[6] = 0.0;
  param_1[2] = 0.0;
  param_1[1] = 0.0;
  param_1[5] = 0.0;
  param_1[3] = 0.0;
  *param_1 = 1.0;
  param_1[8] = 1.0;
  param_1[4] = 1.0;
  param_1[9] = fVar4;
  param_1[10] = fVar3;
  param_1[0xb] = fVar5;
  fVar7 = (float10)fsin((float10)fVar2);
  fVar8 = (float10)0.0;
  *param_1 = (float)(fVar8 + fVar6);
  param_1[6] = 0.0 - (float)fVar7;
  param_1[1] = (float)((float10)0.0 + fVar8);
  param_1[7] = (float)((float10)0.0 - fVar8);
  param_1[2] = (float)fVar7 + 0.0;
  param_1[8] = (float)(fVar6 - fVar8);
  return;
}



// ?GetLandingPointCount@Object@@UAEHXZ @ 0x005ea800

int _GetLandingPointCount_Object__UAEHXZ(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x40) + 0xf8))();
  return *(int *)(iVar1 + 0x40) + -2;
}



// ?GetLandingPoint@Object@@UAE_NEPAULHPoint@@@Z @ 0x005ea820

undefined4 _GetLandingPoint_Object__UAE_NEPAULHPoint___Z(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  (**(code **)(**(int **)(in_ECX + 0x40) + 0x1cc))(param_2);
  return 1;
}



// ?GetWeight@Object@@UAEMXZ @ 0x005ea850

float10 _GetWeight_Object__UAEMXZ(void)

{
  int *in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 0x120))();
  return fVar1 * fVar1 * fVar1 * (float10)*(float *)(in_ECX[10] + 0xac);
}



// ?GetRoutePlanRadius@Object@@UAEMPAVCreature@@@Z @ 0x005ea870

float10 _GetRoutePlanRadius_Object__UAEMPAVCreature___Z(int *param_1)

{
  int *in_ECX;
  float10 fVar1;
  float10 fVar2;
  
  if (param_1 == (int *)0x0) {
    fVar1 = (float10)(**(code **)(*in_ECX + 100))();
    return fVar1;
  }
  fVar1 = (float10)(**(code **)(*in_ECX + 0x42c))();
  fVar2 = (float10)(**(code **)(*param_1 + 0x42c))();
  if ((float10)(float)fVar1 <= fVar2 * (float10)0.8) {
    param_1 = (int *)(float)((float10)0.7 -
                            ((float10)(float)fVar1 / (fVar2 * (float10)0.8)) * (float10)0.3);
  }
  else {
    param_1 = (int *)0x3ecccccd;
  }
  fVar1 = (float10)(**(code **)(*in_ECX + 100))();
  FUN_004619d0();
  fVar2 = (float10)FUN_004693e0();
  return (float10)(float)fVar1 - fVar2 * (float10)(float)param_1;
}



// ?IsBuildingMaterial@Object@@UAE_NXZ @ 0x005ea900

undefined4 _IsBuildingMaterial_Object__UAE_NXZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x28) + 0xbc);
}



// ?GetQueryFirstEnumText@Object@@UAE?AW4HELP_TEXT@@XZ @ 0x005ea930

undefined4 _GetQueryFirstEnumText_Object__UAE_AW4HELP_TEXT__XZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x28) + 0x50);
}



// ?GetQueryLastEnumText@Object@@UAE?AW4HELP_TEXT@@XZ @ 0x005ea940

undefined4 _GetQueryLastEnumText_Object__UAE_AW4HELP_TEXT__XZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x28) + 0x54);
}



// ?GetFOVHelpMessageSet@Object@@UAEIXZ @ 0x005ea950

undefined4 _GetFOVHelpMessageSet_Object__UAEIXZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x28) + 0x58);
}



// ?GetFOVHelpCondition@Object@@UAEIXZ @ 0x005ea960

undefined4 _GetFOVHelpCondition_Object__UAEIXZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x28) + 0x5c);
}



// ?GetHandHelpMessageSet@Object@@UAEIXZ @ 0x005ea970

undefined4 _GetHandHelpMessageSet_Object__UAEIXZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x28) + 0x60);
}



// ?GetHandHelpCondition@Object@@UAEIXZ @ 0x005ea980

undefined4 _GetHandHelpCondition_Object__UAEIXZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x28) + 100);
}



// ?ThrowObjectFromHand@Object@@UAEIPAVGInterfaceStatus@@H@Z @ 0x005ea990

undefined4
_ThrowObjectFromHand_Object__UAEIPAVGInterfaceStatus__H_Z(int *param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  float10 fVar4;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  bVar1 = *(byte *)(DAT_00c22ca4 + 0x201b15);
  iVar3 = DAT_00c22ca4 + 0x18;
  iVar2 = (**(code **)(*param_1 + 0x1c))();
  if (iVar2 == iVar3 + (uint)bVar1 * 0x278) {
    FUN_00586170(4);
  }
  iStack_18 = param_1[0x14];
  iStack_14 = param_1[0x15];
  iStack_10 = param_1[0x16];
  iStack_4 = param_1[0x13];
  iStack_c = param_1[0x11];
  iStack_8 = param_1[0x12];
  *(ushort *)(in_ECX + 9) = *(ushort *)(in_ECX + 9) & 0xfffb;
  FUN_007592f0(param_1[0x1b],param_1[0x1a],param_1[0x1c]);
  iVar3 = in_ECX[0x10];
  *(int *)(iVar3 + 0x38) = param_1[0x17];
  *(int *)(iVar3 + 0x3c) = param_1[0x18];
  *(int *)(iVar3 + 0x40) = param_1[0x19];
  fVar4 = (float10)(**(code **)(*in_ECX + 0x120))();
  iVar3 = in_ECX[0x10];
  *(float *)(iVar3 + 0x14) = (float)(fVar4 * (float10)*(float *)(iVar3 + 0x14));
  *(float *)(iVar3 + 0x18) = (float)(fVar4 * (float10)*(float *)(iVar3 + 0x18));
  *(float *)(iVar3 + 0x1c) = (float)(fVar4 * (float10)*(float *)(iVar3 + 0x1c));
  *(float *)(iVar3 + 0x20) = (float)(fVar4 * (float10)*(float *)(iVar3 + 0x20));
  *(float *)(iVar3 + 0x24) = (float)(fVar4 * (float10)*(float *)(iVar3 + 0x24));
  *(float *)(iVar3 + 0x28) = (float)(fVar4 * (float10)*(float *)(iVar3 + 0x28));
  *(float *)(iVar3 + 0x2c) = (float)(fVar4 * (float10)*(float *)(iVar3 + 0x2c));
  *(float *)(iVar3 + 0x30) = (float)(fVar4 * (float10)*(float *)(iVar3 + 0x30));
  *(float *)(iVar3 + 0x34) = (float)(fVar4 * (float10)*(float *)(iVar3 + 0x34));
  iVar3 = (**(code **)(*in_ECX + 0x780))(&iStack_c,&iStack_18,param_1,0,param_2);
  iVar2 = (**(code **)(*param_1 + 0x1c))();
  if ((*(int *)(iVar2 + 0x158) != 0) && (iVar3 != 0)) {
    *(undefined4 *)(iVar3 + 0x174) = 0;
  }
  return 0x16;
}



// ?CreatureMustAvoid@Object@@UAE_NPAVCreature@@@Z @ 0x005eaae0

undefined4 _CreatureMustAvoid_Object__UAE_NPAVCreature___Z(int *param_1)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  float10 fVar3;
  
  if (param_1 != (int *)0x0) {
    fVar2 = (float10)(**(code **)(*in_ECX + 0x42c))();
    fVar3 = (float10)(**(code **)(*param_1 + 0x42c))();
    if ((float10)(float)fVar2 < fVar3 * (float10)0.1) {
      iVar1 = FUN_005ea110();
      if (iVar1 == 0) {
        return 0;
      }
    }
  }
  return 1;
}



// ?AddToRoutePlan@Object@@UAEXPAVRPHolder@@PAVCreature@@HP6AXHUPoint2D@@MH@Z@Z @ 0x005eab30

void _AddToRoutePlan_Object__UAEXPAVRPHolder__PAVCreature__HP6AXHUPoint2D__MH_Z_Z
               (undefined4 param_1,int *param_2,code *param_3)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  int *in_ECX;
  float unaff_EBX;
  float10 fVar4;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 fVar5;
  float fVar6;
  float fStack_54;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_38;
  float fStack_34;
  undefined1 local_30 [4];
  float fStack_2c;
  float fStack_28;
  float fStack_20;
  float fStack_1c;
  float fStack_14;
  float fStack_10;
  float fStack_8;
  
  piVar1 = (int *)in_ECX[0x10];
  if (param_2 != (int *)0x0) {
    fVar4 = (float10)(**(code **)(*in_ECX + 0x42c))();
    (**(code **)(*param_2 + 0x42c))();
    param_2 = (int *)(float)fVar4;
  }
  if (piVar1 != (int *)0x0) {
    (**(code **)(*in_ECX + 0x63c))(local_30);
    iVar3 = (**(code **)(*piVar1 + 0xf8))();
    fStack_48 = fStack_1c * *(float *)(iVar3 + 0x20) +
                fStack_34 * *(float *)(iVar3 + 0x18) + fStack_28 * *(float *)(iVar3 + 0x1c) +
                fStack_10;
    fStack_44 = fStack_14 * *(float *)(iVar3 + 0x20) +
                fStack_2c * *(float *)(iVar3 + 0x18) + fStack_20 * *(float *)(iVar3 + 0x1c) +
                fStack_8;
    fStack_38 = fStack_44;
    fVar4 = (float10)(**(code **)(*in_ECX + 0x120))();
    iVar3 = (**(code **)(*piVar1 + 0xf8))();
    fVar6 = (float)fVar4 * *(float *)(iVar3 + 0x24) + unaff_EBX + fStack_54;
    fStack_38 = (float)fVar4 * *(float *)(iVar3 + 0x2c) + unaff_EBX + fStack_54;
    if (fVar6 <= fStack_38 * 1.2) {
      if (fStack_38 <= fVar6 * 1.2) goto LAB_005ead21;
      iVar3 = __ftol();
      param_1 = (float)(iVar3 + 1);
      fVar4 = extraout_ST0_00;
      if (5 < (int)param_1) {
        param_1 = 7.00649e-45;
        fVar4 = (float10)fStack_38 * (float10)0.2;
      }
      bVar2 = false;
      fStack_4c = (float)fVar4;
      iVar3 = (int)param_1;
      param_1 = fStack_38 / (float)(int)param_1;
    }
    else {
      iVar3 = __ftol();
      param_1 = (float)(iVar3 + 1);
      if (5 < (int)param_1) {
        param_1 = 7.00649e-45;
        fStack_38 = (float)(extraout_ST0 * (float10)0.2);
      }
      bVar2 = true;
      fStack_4c = fStack_38;
      iVar3 = (int)param_1;
      param_1 = (float)(extraout_ST0 / (float10)(int)param_1);
    }
    if (iVar3 == 1) {
LAB_005ead21:
      fVar4 = (float10)(**(code **)(*in_ECX + 100))();
      fVar4 = fVar4 + (float10)unaff_EBX + (float10)fStack_54;
      fVar6 = (float)fVar4;
      if (fVar4 < (float10)0.05) {
        fVar6 = 0.05;
      }
      if (param_3 == (code *)0x0) {
        FUN_007903c0(in_ECX,&fStack_48,fVar6,param_2);
        return;
      }
      FUN_005c9250(&fStack_48);
      (*param_3)();
      return;
    }
    fStack_54 = 1.5707964;
    if (!bVar2) {
      fStack_54 = 0.0;
    }
    fVar4 = (float10)(**(code **)(*in_ECX + 0x508))();
    fVar5 = (float10)fsin(fVar4 + (float10)fStack_54);
    fVar6 = (float)(fVar5 * (float10)param_1);
    fVar4 = (float10)fcos(fVar4 + (float10)fStack_54);
    fVar4 = -(fVar4 * (float10)param_1);
    fStack_48 = fStack_48 - (float)((float10)fVar6 * (float10)(iVar3 + -1));
    fStack_44 = (float)((float10)fStack_44 - fVar4 * (float10)(iVar3 + -1));
    param_1 = fStack_4c * 1.15;
    if (param_1 < 0.05) {
      param_1 = 0.05;
    }
    fStack_4c = (float)iVar3;
    if (0 < iVar3) {
      do {
        if (param_3 == (code *)0x0) {
          FUN_007903c0(in_ECX,&fStack_48,param_1,param_2);
        }
        else {
          FUN_005c9250(&fStack_48);
          (*param_3)();
        }
        fStack_48 = fVar6 + fVar6 + fStack_48;
        fStack_4c = (float)((int)fStack_4c + -1);
        fStack_44 = fStack_44 + (float)(fVar4 + fVar4);
      } while (fStack_4c != 0.0);
    }
  }
  return;
}



// ?GetHoldRadius@Object@@UAEMXZ @ 0x005eaf80

float10 _GetHoldRadius_Object__UAEMXZ(void)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  
  iVar1 = (**(code **)(*in_ECX + 0x58c))();
  if (iVar1 == 1) {
    fVar2 = (float10)(**(code **)(*in_ECX + 0x42c))();
    return fVar2 * (float10)0.75;
  }
  fVar2 = (float10)(**(code **)(*in_ECX + 100))();
  return fVar2;
}



// ?GetInspectObjectPos@Object@@UAE_NPAVVillager@@PAUMapCoords@@@Z @ 0x005eafe0

undefined4
_GetInspectObjectPos_Object__UAE_NPAVVillager__PAUMapCoords___Z
          (undefined4 param_1,undefined4 *param_2)

{
  int in_ECX;
  
  *param_2 = *(undefined4 *)(in_ECX + 0x14);
  param_2[1] = *(undefined4 *)(in_ECX + 0x18);
  param_2[2] = *(undefined4 *)(in_ECX + 0x1c);
  return 1;
}



// ?GetSpecialPos@Object@@UAE_NIPAUMapCoords@@@Z @ 0x005eb000

undefined4 _GetSpecialPos_Object__UAE_NIPAUMapCoords___Z(undefined4 param_1,undefined4 *param_2)

{
  int in_ECX;
  
  *param_2 = *(undefined4 *)(in_ECX + 0x14);
  param_2[1] = *(undefined4 *)(in_ECX + 0x18);
  param_2[2] = *(undefined4 *)(in_ECX + 0x1c);
  return 0;
}



// ?SetXYZAngles@Object@@UAEXMMM@Z @ 0x005eb020

void _SetXYZAngles_Object__UAEXMMM_Z(undefined4 param_1,undefined4 param_2)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  int *in_ECX;
  float10 fVar8;
  float10 fVar9;
  int iStack_14;
  
  iVar7 = (**(code **)(*in_ECX + 0x178))();
  if (iVar7 != 0) {
    (**(code **)(*in_ECX + 0x548))();
  }
  (**(code **)(*in_ECX + 0x520))(param_2);
  if (in_ECX[0x10] != 0) {
    fVar8 = (float10)(**(code **)(*in_ECX + 0x120))();
    fVar3 = (float)fVar8;
    fVar8 = (float10)(**(code **)(*in_ECX + 0x508))();
    fVar4 = (float)fVar8;
    fVar5 = (float)in_ECX[7];
    iVar6 = in_ECX[0x10];
    fVar8 = (float10)FUN_00760fd0();
    iVar7 = in_ECX[5];
    iVar2 = in_ECX[6];
    if (fVar4 == 0.0) {
      if (fVar3 == 1.0) {
        FUN_004022b0();
      }
      else {
        *(float *)(iVar6 + 0x34) = fVar3;
        *(float *)(iVar6 + 0x14) = fVar3;
        *(undefined4 *)(iVar6 + 0x40) = 0;
        *(undefined4 *)(iVar6 + 0x3c) = 0;
        *(undefined4 *)(iVar6 + 0x38) = 0;
        *(undefined4 *)(iVar6 + 0x30) = 0;
        *(undefined4 *)(iVar6 + 0x2c) = 0;
        *(undefined4 *)(iVar6 + 0x28) = 0;
        *(undefined4 *)(iVar6 + 0x20) = 0;
        *(undefined4 *)(iVar6 + 0x1c) = 0;
        *(undefined4 *)(iVar6 + 0x18) = 0;
        *(float *)(iVar6 + 0x24) = fVar3;
        FUN_004022f0();
      }
    }
    else if (fVar3 == 1.0) {
      pfVar1 = (float *)(iVar6 + 0x14);
      FUN_00402280();
      fVar9 = (float10)fcos((float10)fVar4);
      *(float *)(iVar6 + 0x38) = (float)iVar7 * 0.00015258789;
      *(float *)(iVar6 + 0x3c) = (float)(fVar8 + (float10)fVar5);
      *(float *)(iVar6 + 0x40) = (float)iVar2 * 0.00015258789;
      fVar8 = (float10)fsin((float10)fVar4);
      fVar5 = *pfVar1;
      *pfVar1 = (float)(fVar8 * (float10)*(float *)(iVar6 + 0x2c) + fVar9 * (float10)*pfVar1);
      *(float *)(iVar6 + 0x2c) =
           (float)(fVar9 * (float10)*(float *)(iVar6 + 0x2c) - fVar8 * (float10)fVar5);
      fVar5 = *(float *)(iVar6 + 0x18);
      *(float *)(iVar6 + 0x18) =
           (float)(fVar8 * (float10)*(float *)(iVar6 + 0x30) +
                  fVar9 * (float10)*(float *)(iVar6 + 0x18));
      *(float *)(iVar6 + 0x30) =
           (float)(fVar9 * (float10)*(float *)(iVar6 + 0x30) - fVar8 * (float10)fVar5);
      fVar5 = *(float *)(iVar6 + 0x1c);
      *(float *)(iVar6 + 0x1c) =
           (float)(fVar8 * (float10)*(float *)(iVar6 + 0x34) +
                  fVar9 * (float10)*(float *)(iVar6 + 0x1c));
      *(float *)(iVar6 + 0x34) =
           (float)(fVar9 * (float10)*(float *)(iVar6 + 0x34) -
                  (float10)(float)(fVar8 * (float10)fVar5));
    }
    else {
      *(undefined4 *)(iVar6 + 0x40) = 0;
      *(undefined4 *)(iVar6 + 0x3c) = 0;
      *(undefined4 *)(iVar6 + 0x38) = 0;
      *(undefined4 *)(iVar6 + 0x30) = 0;
      *(undefined4 *)(iVar6 + 0x2c) = 0;
      *(undefined4 *)(iVar6 + 0x28) = 0;
      *(undefined4 *)(iVar6 + 0x20) = 0;
      *(undefined4 *)(iVar6 + 0x1c) = 0;
      *(undefined4 *)(iVar6 + 0x18) = 0;
      *(float *)(iVar6 + 0x34) = fVar3;
      *(float *)(iVar6 + 0x24) = fVar3;
      *(float *)(iVar6 + 0x14) = fVar3;
      *(float *)(iVar6 + 0x38) = (float)iVar7 * 0.00015258789 + *(float *)(iVar6 + 0x38);
      *(float *)(iVar6 + 0x3c) = (float)(fVar8 + (float10)fVar5) + *(float *)(iVar6 + 0x3c);
      *(float *)(iVar6 + 0x40) = (float)iVar2 * 0.00015258789 + *(float *)(iVar6 + 0x40);
      fVar8 = (float10)fcos((float10)fVar4);
      fVar9 = (float10)fsin((float10)fVar4);
      fVar5 = *(float *)(iVar6 + 0x14);
      *(float *)(iVar6 + 0x14) =
           (float)(fVar8 * (float10)*(float *)(iVar6 + 0x14) +
                  fVar9 * (float10)*(float *)(iVar6 + 0x2c));
      *(float *)(iVar6 + 0x2c) =
           (float)(fVar8 * (float10)*(float *)(iVar6 + 0x2c) - fVar9 * (float10)fVar5);
      fVar5 = *(float *)(iVar6 + 0x18);
      *(float *)(iVar6 + 0x18) =
           (float)(fVar8 * (float10)*(float *)(iVar6 + 0x18) +
                  fVar9 * (float10)*(float *)(iVar6 + 0x30));
      *(float *)(iVar6 + 0x30) =
           (float)(fVar8 * (float10)*(float *)(iVar6 + 0x30) - fVar9 * (float10)fVar5);
      fVar5 = *(float *)(iVar6 + 0x1c);
      *(float *)(iVar6 + 0x1c) =
           (float)(fVar8 * (float10)*(float *)(iVar6 + 0x1c) +
                  fVar9 * (float10)*(float *)(iVar6 + 0x34));
      *(float *)(iVar6 + 0x34) =
           (float)(fVar8 * (float10)*(float *)(iVar6 + 0x34) -
                  (float10)(float)(fVar9 * (float10)fVar5));
    }
    *(float *)(iVar6 + 0x44) = fVar3;
    *(float *)(iVar6 + 0x48) = fVar4;
    iVar7 = iStack_14;
  }
  if (iVar7 != 0) {
    (**(code **)(*in_ECX + 0x544))();
  }
  return;
}



// ?SetXYZAnglesAndScale@Object@@UAEXMMMM@Z @ 0x005eb2a0

void _SetXYZAnglesAndScale_Object__UAEXMMMM_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  int *in_ECX;
  int unaff_EBX;
  float10 fVar8;
  float10 fVar9;
  
  iVar7 = (**(code **)(*in_ECX + 0x178))();
  if (iVar7 != 0) {
    (**(code **)(*in_ECX + 0x548))();
  }
  (**(code **)(*in_ECX + 0x520))(param_2);
  (**(code **)(*in_ECX + 0x51c))(param_3);
  if (in_ECX[0x10] != 0) {
    fVar8 = (float10)(**(code **)(*in_ECX + 0x120))();
    fVar3 = (float)fVar8;
    fVar8 = (float10)(**(code **)(*in_ECX + 0x508))();
    fVar4 = (float)fVar8;
    fVar5 = (float)in_ECX[7];
    iVar6 = in_ECX[0x10];
    fVar8 = (float10)FUN_00760fd0();
    iVar7 = in_ECX[5];
    iVar2 = in_ECX[6];
    if (fVar4 == 0.0) {
      if (fVar3 == 1.0) {
        FUN_004022b0();
      }
      else {
        *(float *)(iVar6 + 0x34) = fVar3;
        *(float *)(iVar6 + 0x14) = fVar3;
        *(undefined4 *)(iVar6 + 0x40) = 0;
        *(undefined4 *)(iVar6 + 0x3c) = 0;
        *(undefined4 *)(iVar6 + 0x38) = 0;
        *(undefined4 *)(iVar6 + 0x30) = 0;
        *(undefined4 *)(iVar6 + 0x2c) = 0;
        *(undefined4 *)(iVar6 + 0x28) = 0;
        *(undefined4 *)(iVar6 + 0x20) = 0;
        *(undefined4 *)(iVar6 + 0x1c) = 0;
        *(undefined4 *)(iVar6 + 0x18) = 0;
        *(float *)(iVar6 + 0x24) = fVar3;
        FUN_004022f0();
      }
    }
    else if (fVar3 == 1.0) {
      pfVar1 = (float *)(iVar6 + 0x14);
      FUN_00402280();
      fVar9 = (float10)fcos((float10)fVar4);
      *(float *)(iVar6 + 0x38) = (float)iVar7 * 0.00015258789;
      *(float *)(iVar6 + 0x3c) = (float)(fVar8 + (float10)fVar5);
      *(float *)(iVar6 + 0x40) = (float)iVar2 * 0.00015258789;
      fVar8 = (float10)fsin((float10)fVar4);
      fVar5 = *pfVar1;
      *pfVar1 = (float)(fVar9 * (float10)*pfVar1 + fVar8 * (float10)*(float *)(iVar6 + 0x2c));
      *(float *)(iVar6 + 0x2c) =
           (float)(fVar9 * (float10)*(float *)(iVar6 + 0x2c) - fVar8 * (float10)fVar5);
      fVar5 = *(float *)(iVar6 + 0x18);
      *(float *)(iVar6 + 0x18) =
           (float)(fVar9 * (float10)*(float *)(iVar6 + 0x18) +
                  fVar8 * (float10)*(float *)(iVar6 + 0x30));
      *(float *)(iVar6 + 0x30) =
           (float)(fVar9 * (float10)*(float *)(iVar6 + 0x30) - fVar8 * (float10)fVar5);
      fVar5 = *(float *)(iVar6 + 0x1c);
      *(float *)(iVar6 + 0x1c) =
           (float)(fVar9 * (float10)*(float *)(iVar6 + 0x1c) +
                  fVar8 * (float10)*(float *)(iVar6 + 0x34));
      *(float *)(iVar6 + 0x34) =
           (float)(fVar9 * (float10)*(float *)(iVar6 + 0x34) -
                  (float10)(float)(fVar8 * (float10)fVar5));
    }
    else {
      *(undefined4 *)(iVar6 + 0x40) = 0;
      *(undefined4 *)(iVar6 + 0x3c) = 0;
      *(undefined4 *)(iVar6 + 0x38) = 0;
      *(undefined4 *)(iVar6 + 0x30) = 0;
      *(undefined4 *)(iVar6 + 0x2c) = 0;
      *(undefined4 *)(iVar6 + 0x28) = 0;
      *(undefined4 *)(iVar6 + 0x20) = 0;
      *(undefined4 *)(iVar6 + 0x1c) = 0;
      *(undefined4 *)(iVar6 + 0x18) = 0;
      *(float *)(iVar6 + 0x34) = fVar3;
      *(float *)(iVar6 + 0x24) = fVar3;
      *(float *)(iVar6 + 0x14) = fVar3;
      *(float *)(iVar6 + 0x38) = (float)iVar7 * 0.00015258789 + *(float *)(iVar6 + 0x38);
      *(float *)(iVar6 + 0x3c) = (float)(fVar8 + (float10)fVar5) + *(float *)(iVar6 + 0x3c);
      *(float *)(iVar6 + 0x40) = (float)iVar2 * 0.00015258789 + *(float *)(iVar6 + 0x40);
      fVar8 = (float10)fcos((float10)fVar4);
      fVar9 = (float10)fsin((float10)fVar4);
      fVar5 = *(float *)(iVar6 + 0x14);
      *(float *)(iVar6 + 0x14) =
           (float)(fVar9 * (float10)*(float *)(iVar6 + 0x2c) +
                  fVar8 * (float10)*(float *)(iVar6 + 0x14));
      *(float *)(iVar6 + 0x2c) =
           (float)(fVar8 * (float10)*(float *)(iVar6 + 0x2c) - fVar9 * (float10)fVar5);
      fVar5 = *(float *)(iVar6 + 0x18);
      *(float *)(iVar6 + 0x18) =
           (float)(fVar8 * (float10)*(float *)(iVar6 + 0x18) +
                  fVar9 * (float10)*(float *)(iVar6 + 0x30));
      *(float *)(iVar6 + 0x30) =
           (float)(fVar8 * (float10)*(float *)(iVar6 + 0x30) - fVar9 * (float10)fVar5);
      fVar5 = *(float *)(iVar6 + 0x1c);
      *(float *)(iVar6 + 0x1c) =
           (float)(fVar8 * (float10)*(float *)(iVar6 + 0x1c) +
                  fVar9 * (float10)*(float *)(iVar6 + 0x34));
      *(float *)(iVar6 + 0x34) =
           (float)(fVar8 * (float10)*(float *)(iVar6 + 0x34) -
                  (float10)(float)(fVar9 * (float10)fVar5));
    }
    *(float *)(iVar6 + 0x44) = fVar3;
    *(float *)(iVar6 + 0x48) = fVar4;
    iVar7 = unaff_EBX;
  }
  if (iVar7 != 0) {
    (**(code **)(*in_ECX + 0x544))();
  }
  return;
}



// ?SetScale@Object@@UAEXM@Z @ 0x005eb520

void _SetScale_Object__UAEXM_Z(float param_1)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  
  fVar2 = (float10)(**(code **)(*in_ECX + 0x120))();
  if (fVar2 != (float10)param_1) {
    iVar1 = *in_ECX;
    fVar2 = (float10)(**(code **)(iVar1 + 0x50c))(param_1);
    fVar2 = (float10)(**(code **)(*in_ECX + 0x508))((float)fVar2);
    fVar2 = (float10)(**(code **)(*in_ECX + 0x504))((float)fVar2);
    (**(code **)(iVar1 + 0x518))((float)fVar2);
  }
  return;
}



// ?SetYAngle@Object@@UAEXM@Z @ 0x005eb580

void _SetYAngle_Object__UAEXM_Z(float param_1)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  
  fVar2 = (float10)(**(code **)(*in_ECX + 0x508))();
  if (fVar2 != (float10)param_1) {
    iVar1 = *in_ECX;
    fVar2 = (float10)(**(code **)(iVar1 + 0x50c))();
    fVar2 = (float10)(**(code **)(*in_ECX + 0x504))(param_1,(float)fVar2);
    (**(code **)(iVar1 + 0x514))((float)fVar2);
  }
  return;
}



// ?IsObjectInMap@Object@@UAE_NXZ @ 0x005eb5d0

byte _IsObjectInMap_Object__UAE_NXZ(void)

{
  int in_ECX;
  
  return *(byte *)(in_ECX + 0x24) & 1;
}



// ?DrawValue@Object@@UAEXHM@Z @ 0x005eb5e0

void _DrawValue_Object__UAEXHM_Z(undefined4 param_1,float param_2)

{
  float fVar1;
  undefined4 *puVar2;
  int *in_ECX;
  float10 fVar3;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if (param_2 != 0.0) {
    fVar1 = (float)in_ECX[7];
    fVar3 = (float10)FUN_00760fd0();
    fStack_8 = (float)(fVar3 + (float10)fVar1);
    fStack_c = (float)in_ECX[5] * 0.00015258789;
    fStack_4 = (float)in_ECX[6] * 0.00015258789;
    fVar3 = (float10)(**(code **)(*in_ECX + 0x42c))();
    fStack_8 = (float)(fVar3 + (float10)fStack_8);
    if ((*(uint *)(DAT_00c22ca4 + 0x14) & 0x4000) != 0) {
      puVar2 = (undefined4 *)FUN_00746d70(0xa0,s_C__dev_black_Object_cpp_00b21cd8,0x79e);
      if (puVar2 != (undefined4 *)0x0) {
        *puVar2 = &PTR_LAB_008049b4;
        puVar2[5] = 0;
        puVar2[6] = 0;
        puVar2[1] = DAT_00df8148;
        DAT_00df8148 = puVar2;
      }
      FUN_0078cad0(&fStack_c,param_2,param_1);
    }
  }
  return;
}



// ?GetImpressiveValue@Object@@UAEMXZ @ 0x005eb6b0

float10 _GetImpressiveValue_Object__UAEMXZ(void)

{
  int in_ECX;
  
  return (float10)DAT_00c3b394 * (float10)*(float *)(*(int *)(in_ECX + 0x28) + 0xe8);
}



// ?SetFocus@Object@@UAEXPBULHPoint@@@Z @ 0x005eb6c0

void _SetFocus_Object__UAEXPBULHPoint___Z(undefined4 param_1)

{
  float fVar1;
  int *in_ECX;
  float10 fVar2;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  fVar1 = (float)in_ECX[7];
  fVar2 = (float10)FUN_00760fd0();
  fStack_8 = (float)(fVar2 + (float10)fVar1);
  fStack_c = (float)in_ECX[5] * 0.00015258789;
  fStack_4 = (float)in_ECX[6] * 0.00015258789;
  fVar2 = (float10)FUN_00795e70(&fStack_c,param_1);
  (**(code **)(*in_ECX + 0x524))((float)fVar2);
  return;
}



// ?GetPhysicsMovementDirection@Object@@UAEXPAULHPoint@@@Z @ 0x005eb800

void _GetPhysicsMovementDirection_Object__UAEXPAULHPoint___Z(undefined4 *param_1)

{
  int iVar1;
  
  iVar1 = FUN_005f56a0();
  if (iVar1 != 0) {
    *param_1 = *(undefined4 *)(iVar1 + 0x104);
    param_1[1] = *(undefined4 *)(iVar1 + 0x108);
    param_1[2] = *(undefined4 *)(iVar1 + 0x10c);
    return;
  }
  param_1[2] = 0;
  param_1[1] = 0;
  *param_1 = 0;
  return;
}



// ?GetResource@Object@@UAEIW4RESOURCE_TYPE@@@Z @ 0x005eb840

undefined4 _GetResource_Object__UAEIW4RESOURCE_TYPE___Z(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x690))();
  if (param_1 == iVar1) {
    uVar2 = (**(code **)(*in_ECX + 0x694))();
    return uVar2;
  }
  return 0;
}



// ?GetWorkingPos@Object@@UAEPAUMapCoords@@PAU2@PAV1@@Z @ 0x005eb870

undefined4 _GetWorkingPos_Object__UAEPAUMapCoords__PAU2_PAV1__Z(undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  int *in_ECX;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  undefined1 auStack_c [12];
  
  fVar2 = (float10)FUN_006de3e0(in_ECX + 5,param_2 + 5);
  fVar3 = (float10)(**(code **)(*in_ECX + 0x60))();
  fVar4 = (float10)(**(code **)(*param_2 + 0x60))();
  uVar1 = FUN_006de5a0(auStack_c,(float)fVar2,(float)(fVar4 + (float10)(float)fVar3));
  FUN_005c1360(param_1,uVar1);
  return param_1;
}



// ?GetWoodValue@Object@@UAEMXZ @ 0x005eb8e0

float10 _GetWoodValue_Object__UAEMXZ(void)

{
  float fVar1;
  int iVar2;
  int *in_ECX;
  float10 fVar3;
  
  fVar3 = (float10)(**(code **)(*in_ECX + 0x120))();
  fVar1 = (float)fVar3;
  iVar2 = in_ECX[10];
  fVar3 = (float10)(**(code **)(*in_ECX + 0x11c))();
  return fVar3 * (float10)*(int *)(iVar2 + 0x6c) * (float10)fVar1 * (float10)fVar1 * (float10)fVar1;
}



// ?GetAggressorValueFromDamage@Object@@UAEMM@Z @ 0x005eb930

float10 _GetAggressorValueFromDamage_Object__UAEMM_Z(float param_1)

{
  int in_ECX;
  
  return (float10)param_1 * (float10)*(float *)(*(int *)(in_ECX + 0x28) + 0xec);
}



// ?CalculateForceAppliedBy@Object@@UAEMPAVLiving@@@Z @ 0x005eb940

float10 _CalculateForceAppliedBy_Object__UAEMPAVLiving___Z(void)

{
  int *in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 0x638))();
  return fVar1 * (float10)9.81;
}



// ?PushObject@Object@@UAEXPAVLiving@@@Z @ 0x005eb960

float10 _PushObject_Object__UAEXPAVLiving___Z(undefined4 param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  float10 fVar5;
  float10 fVar6;
  undefined1 auStack_30 [12];
  float fStack_24;
  float fStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  fVar5 = (float10)(**(code **)(*in_ECX + 0x810))(param_1);
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  if (((*(byte *)(in_ECX + 9) & 0x40) == 0) || ((*(byte *)((int)in_ECX + 10) & 0x10) != 0)) {
    piVar4 = (int *)(**(code **)(*in_ECX + 0x784))(auStack_30,&uStack_1c,&uStack_1c,0,1,0);
    iVar3 = *piVar4;
  }
  else {
    iVar3 = FUN_005f56a0();
  }
  if (iVar3 != 0) {
    *(uint *)(iVar3 + 0x1d8) = *(uint *)(iVar3 + 0x1d8) | 2;
    fVar1 = (float)in_ECX[7];
    fVar6 = (float10)FUN_00760fd0();
    fVar2 = *(float *)(iVar3 + 200) - (float)in_ECX[5] * 0.00015258789;
    fStack_24 = *(float *)(iVar3 + 0xcc) - (float)(fVar6 + (float10)fVar1);
    fStack_20 = *(float *)(iVar3 + 0xd0) - (float)in_ECX[6] * 0.00015258789;
    if (((fVar2 != 0.0) || (fStack_24 != 0.0)) || (fStack_20 != 0.0)) {
      fVar1 = (float)fVar5 / SQRT(fVar2 * fVar2 + fStack_24 * fStack_24 + fStack_20 * fStack_20);
      fVar2 = fVar1 * fVar2;
      fStack_24 = fStack_24 * fVar1;
      fStack_20 = fStack_20 * fVar1;
    }
    *(float *)(iVar3 + 0x144) = fVar2 + *(float *)(iVar3 + 0x144);
    *(float *)(iVar3 + 0x148) = fStack_24 + *(float *)(iVar3 + 0x148);
    *(float *)(iVar3 + 0x14c) = fStack_20 + *(float *)(iVar3 + 0x14c);
  }
  return (float10)0.0;
}



// ?PushObject@Object@@UAEXPAVLiving@@PAUMapCoords@@@Z @ 0x005ebae0

float10 _PushObject_Object__UAEXPAVLiving__PAUMapCoords___Z(int *param_1,float param_2)

{
  undefined4 uVar1;
  int *in_ECX;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  undefined1 auStack_18 [12];
  undefined1 auStack_c [12];
  
  fVar2 = (float10)FUN_006de3e0(in_ECX + 5,param_2);
  fVar3 = (float10)(**(code **)(*param_1 + 0x130))();
  fVar4 = (float10)FUN_006de0a0(in_ECX + 5,param_2);
  param_2 = (float)(fVar3 + (float10)0.5);
  if (fVar4 < (float10)(float)(fVar3 + (float10)0.5)) {
    param_2 = (float)fVar4;
  }
  uVar1 = FUN_006de5a0(auStack_c,(float)fVar2,param_2);
  FUN_005c1360(auStack_18,uVar1);
  (**(code **)(*in_ECX + 0x560))(auStack_18);
  return (float10)0.0;
}



// ?GetImpressiveValue@Object@@UAEMPAVLiving@@PAVReaction@@@Z @ 0x005ebb80

float10 _GetImpressiveValue_Object__UAEMPAVLiving__PAVReaction___Z(int param_1,undefined4 param_2)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  
  fVar2 = (float10)FUN_0067fac0(param_1);
  fVar3 = (float10)(**(code **)(*in_ECX + 0x66c))();
  fVar4 = (float10)FUN_006de0a0(param_1 + 0x14,in_ECX + 5);
  iVar1 = FUN_0067f950();
  fVar4 = (float10)FUN_00431440((float)fVar4,*(undefined4 *)(iVar1 + 0x2c));
  fVar5 = (float10)(**(code **)(*in_ECX + 0x128))();
  fVar6 = (float10)FUN_0053eb20(param_2);
  fVar7 = (float10)FUN_005ebc20();
  return fVar7 * (float10)(float)fVar6 * (float10)(float)fVar5 * (float10)(float)fVar4 *
         (float10)(float)(fVar3 * (float10)(float)fVar2);
}



// ?CanBeDestroyedBySpell@Object@@UAE_NPAVSpell@@@Z @ 0x005ebc60

undefined4 _CanBeDestroyedBySpell_Object__UAE_NPAVSpell___Z(void)

{
  int iVar1;
  int *in_ECX;
  int unaff_retaddr;
  
  iVar1 = (**(code **)(*in_ECX + 0x774))(0);
  if ((iVar1 == 1) && ((*(byte *)((int)in_ECX + 0x25) & 0x40) == 0)) {
    iVar1 = (**(code **)(*in_ECX + 0x448))();
    if (((iVar1 == 0) ||
        ((*(int *)(*(int *)(DAT_00c22ca4 + 0x24c118) + 0x45e8) == 0 ||
         (*(int *)(*(int *)(DAT_00c22ca4 + 0x24c118) + 0x45ec) == 0)))) ||
       ((unaff_retaddr != 0 && ((*(byte *)(unaff_retaddr + 0x25) & 4) != 0)))) {
      return 1;
    }
  }
  return 0;
}



// ?GetRainCoolingMultiplier@Object@@UAEMXZ @ 0x005ebd40

float10 _GetRainCoolingMultiplier_Object__UAEMXZ(void)

{
  return (float10)0.01;
}



// ?GetDefaultFireCentrePos@Object@@UAEPAULHPoint@@PAU2@@Z @ 0x005ebd50

void _GetDefaultFireCentrePos_Object__UAEPAULHPoint__PAU2__Z(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0x14);
  param_1[1] = *(undefined4 *)(in_ECX + 0x18);
  param_1[2] = *(undefined4 *)(in_ECX + 0x1c);
  return;
}



// ?ProcessInHand@Object@@UAE_NXZ @ 0x005ebd70

undefined4 _ProcessInHand_Object__UAE_NXZ(void)

{
  undefined4 uVar1;
  int in_ECX;
  float10 fVar2;
  
  uVar1 = FUN_005ec400();
  fVar2 = (float10)FUN_0058ddc0(in_ECX + 0x14,uVar1,0,0,1);
  if ((float10)0.0 < fVar2) {
    FUN_006c6b20();
  }
  return 1;
}



// ?SetInScript@Object@@UAEXH@Z @ 0x005ebdb0

void _SetInScript_Object__UAEXH_Z(byte param_1)

{
  int in_ECX;
  
  *(ushort *)(in_ECX + 0x24) = (param_1 & 1) << 9 | *(ushort *)(in_ECX + 0x24) & 0xfdff;
  return;
}



// ?CanBeSuckedIntoVortex@Object@@UAE_NPAVLandscapeVortex@@@Z @ 0x005ebde0

void _CanBeSuckedIntoVortex_Object__UAE_NPAVLandscapeVortex___Z(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x7b0))();
  return;
}



// ?GetDrawImportance@Object@@UAEMXZ @ 0x005ebdf0

float10 _GetDrawImportance_Object__UAEMXZ(void)

{
  int in_ECX;
  
  return (float10)*(float *)(*(int *)(in_ECX + 0x28) + 0xf8);
}



// ?Save@Object@@UAEIPAVGameOSFile@@@Z @ 0x005ebe00

undefined4 _Save_Object__UAEIPAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  uint *puVar3;
  uint *puVar4;
  uint local_48;
  undefined4 local_44;
  undefined4 local_40;
  uint local_3c;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30 [12];
  
  iVar1 = _Save_GameThingWithPos__UAEXPAUGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    FUN_00533b90(*(undefined4 *)(in_ECX + 0x28));
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x2c),0xc,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x2c) + 0xc;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90((byte *)(in_ECX + 0x3c),4,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x3c) + 4;
        if (DAT_00b19ac8 != 0) {
          iVar1 = FUN_0072be90((byte *)(in_ECX + 0x48),4,0);
          if (iVar1 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x48) + 4;
          if (DAT_00b19ac8 != 0) {
            iVar1 = FUN_0072be90((byte *)(in_ECX + 0x50),4,0);
            if (iVar1 == 3) {
              DAT_00b19ac8 = 0;
            }
            *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x50) + 4;
            if (DAT_00b19ac8 != 0) {
              iVar1 = FUN_0072be90((byte *)(in_ECX + 0x4c),4,0);
              if (iVar1 == 3) {
                DAT_00b19ac8 = 0;
              }
              *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x4c) + 4;
            }
          }
        }
      }
    }
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x44));
    if (((*(byte *)(in_ECX + 0x24) & 0x40) != 0) && ((*(byte *)(in_ECX + 10) & 0x10) == 0)) {
      iVar1 = FUN_005f56a0();
      if (iVar1 == 0) {
        local_30[0xb] = 0;
        local_30[10] = 0;
        local_30[9] = 0;
        local_30[7] = 0;
        local_30[6] = 0;
        local_30[5] = 0;
        local_30[3] = 0;
        local_30[2] = 0;
        local_30[1] = 0;
        local_30[8] = 0x3f800000;
        local_30[4] = 0x3f800000;
        local_30[0] = 0x3f800000;
        local_40 = 0;
        local_44 = 0;
        local_48 = 0;
        local_34 = 0;
        local_38 = 0;
        local_3c = 0;
      }
      else {
        puVar3 = (uint *)(iVar1 + 0xa4);
        puVar4 = local_30;
        for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar4 = *puVar3;
          puVar3 = puVar3 + 1;
          puVar4 = puVar4 + 1;
        }
        local_48 = *(uint *)(iVar1 + 0x104);
        local_44 = *(undefined4 *)(iVar1 + 0x108);
        local_40 = *(undefined4 *)(iVar1 + 0x10c);
        local_3c = *(uint *)(iVar1 + 0x90);
        local_38 = *(undefined4 *)(iVar1 + 0x94);
        local_34 = *(undefined4 *)(iVar1 + 0x98);
      }
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90(local_30,0x30,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (local_30[0] & 0xff) + 0x30;
        if (DAT_00b19ac8 != 0) {
          iVar1 = FUN_0072be90(&local_48,0xc,0);
          if (iVar1 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (local_48 & 0xff) + 0xc;
          if (DAT_00b19ac8 != 0) {
            iVar1 = FUN_0072be90(&local_3c,0xc,0);
            if (iVar1 == 3) {
              DAT_00b19ac8 = 0;
            }
            *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (local_3c & 0xff) + 0xc;
          }
        }
      }
    }
    return 1;
  }
  return 0;
}



// ?ResolveLoad@Object@@UAEXXZ @ 0x005ec290

void _ResolveLoad_Object__UAEXXZ(void)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  (**(code **)(*in_ECX + 0x658))(in_ECX + 5);
  if ((((*(ushort *)(in_ECX + 9) & 0x40) != 0) && ((*(byte *)((int)in_ECX + 10) & 0x10) == 0)) &&
     (DAT_00c22dd8 < DAT_00c22dd4)) {
    *(ushort *)(in_ECX + 9) = *(ushort *)(in_ECX + 9) & 0xffbf;
    uStack_10 = 0;
    uStack_c = 0;
    uStack_8 = 0;
    piVar3 = (int *)(**(code **)(*in_ECX + 0x784))(&stack0xffffffe8,&uStack_10,&uStack_10,0,1,0);
    iVar2 = *piVar3;
    if (iVar2 == 0) {
      DAT_00c22dd8 = DAT_00c22dd8 + 1;
    }
    else {
      puVar1 = (undefined4 *)(DAT_00c22dd0 + DAT_00c22dd8 * 0x48);
      puVar5 = puVar1;
      puVar6 = (undefined4 *)(iVar2 + 0xa4);
      for (iVar4 = 0xc; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      *(undefined4 *)(iVar2 + 0x104) = puVar1[0xc];
      *(undefined4 *)(iVar2 + 0x108) = puVar1[0xd];
      *(undefined4 *)(iVar2 + 0x10c) = puVar1[0xe];
      *(undefined4 *)(iVar2 + 0x90) = puVar1[0xf];
      *(undefined4 *)(iVar2 + 0x94) = puVar1[0x10];
      *(undefined4 *)(iVar2 + 0x98) = puVar1[0x11];
      DAT_00c22dd8 = DAT_00c22dd8 + 1;
    }
  }
  if ((*(ushort *)(in_ECX + 9) & 4) != 0) {
    if ((*(ushort *)(in_ECX + 9) & 1) != 0) {
      (**(code **)(*in_ECX + 0x548))();
    }
    *(ushort *)(in_ECX + 9) = *(ushort *)(in_ECX + 9) & 0xfffe;
  }
  *(ushort *)(in_ECX + 9) = *(ushort *)(in_ECX + 9) & 0xffcf;
  return;
}



// ?SetLife@Object@@UAEXM@Z @ 0x005ec3b0

void _SetLife_Object__UAEXM_Z(float param_1)

{
  int in_ECX;
  
  if ((((((*(ushort *)(in_ECX + 0x24) & 0x200) == 0) ||
        (*(int *)(*(int *)(DAT_00c22ca4 + 0x24c118) + 0x45e8) == 0)) ||
       (*(int *)(*(int *)(DAT_00c22ca4 + 0x24c118) + 0x45ec) == 0)) &&
      ((*(ushort *)(in_ECX + 0x24) & 0x4000) == 0)) || (0.01 < param_1)) {
    *(float *)(in_ECX + 0x48) = param_1;
  }
  return;
}



// ?GetImmersionTexture@Object@@UAE?AW4IMMERSION_EFFECT_TYPE@@XZ @ 0x005ec490

undefined4 _GetImmersionTexture_Object__UAE_AW4IMMERSION_EFFECT_TYPE__XZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x28) + 0x4c);
}



// ?InitialiseIsFixedForMapList@Object@@UAEXH@Z @ 0x005ec8b0

void _InitialiseIsFixedForMapList_Object__UAEXH_Z(void)

{
  short sVar1;
  int in_ECX;
  
  sVar1 = FUN_005be520(*(undefined4 *)(*(int *)(in_ECX + 0x28) + 0x10));
  *(ushort *)(in_ECX + 0x24) = *(ushort *)(in_ECX + 0x24) & 0x7fff | sVar1 << 0xf;
  return;
}



// ?IsDrowning@Object@@UAE_NXZ @ 0x005ec9f0

undefined4 _IsDrowning_Object__UAE_NXZ(void)

{
  int iVar1;
  int in_ECX;
  
  if ((*(byte *)(in_ECX + 0x24) & 0x40) != 0) {
    iVar1 = FUN_005f56a0();
    if ((iVar1 != 0) && (*(float *)(iVar1 + 0xcc) < 0.0)) {
      return 1;
    }
  }
  return 0;
}



// ?CanBecomeArtifact@Object@@UAE_NXZ @ 0x005eca20

undefined4 _CanBecomeArtifact_Object__UAE_NXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  if (0.0 < *(float *)(in_ECX[10] + 0xf4)) {
    iVar1 = (**(code **)(*in_ECX + 0x448))();
    if (iVar1 == 0) {
      return 1;
    }
  }
  return 0;
}



// ?SetYJustAngle@Object@@UAEXM@Z @ 0x005eca50

void _SetYJustAngle_Object__UAEXM_Z(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x4c) = param_1;
  return;
}



// ?ApplyWaterSpell@Object@@UAEMPAVSpellWater@@@Z @ 0x005ecb30

float10 _ApplyWaterSpell_Object__UAEMPAVSpellWater___Z(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_005ea110();
  if ((iVar1 != 0) && (param_1[0x3c] == 0)) {
    uVar2 = (**(code **)(*param_1 + 0x1c))(1);
    iVar1 = FUN_0067efc0(param_1,0x22,uVar2);
    param_1[0x3c] = iVar1;
  }
  return (float10)0.0;
}



// ?GetRadiusMultiplierForApplyingPotToPos@Object@@UAEMXZ @ 0x005ecd00

float10 _GetRadiusMultiplierForApplyingPotToPos_Object__UAEMXZ(void)

{
  return (float10)1.2;
}



// ?GetSacrificeValue@Object@@UAEMXZ @ 0x005ecd10

float10 _GetSacrificeValue_Object__UAEMXZ(void)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  
  iVar1 = in_ECX[10];
  fVar2 = (float10)(**(code **)(*in_ECX + 0x11c))();
  return (fVar2 * (float10)0.5 + (float10)0.5) * (float10)*(float *)(iVar1 + 0xe4);
}



// ?DestroyedByBeam@Object@@UAEXXZ @ 0x005ecd30

void _DestroyedByBeam_Object__UAEXXZ(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0xc))(0);
  return;
}



// ?CalculateWhereIWillBeAfterNSeconds@Object@@UAEXMPAULHPoint@@@Z @ 0x005ed740

void _CalculateWhereIWillBeAfterNSeconds_Object__UAEXMPAULHPoint___Z
               (undefined4 param_1,float *param_2)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  float10 fVar3;
  float10 fVar4;
  
  iVar1 = in_ECX[5];
  iVar2 = in_ECX[6];
  fVar3 = (float10)(**(code **)(*in_ECX + 0x42c))();
  fVar4 = (float10)FUN_00760fd0();
  param_2[1] = (float)(fVar4 + (float10)(float)(fVar3 * (float10)0.5));
  *param_2 = (float)iVar1 * 0.00015258789;
  param_2[2] = (float)iVar2 * 0.00015258789;
  return;
}



// ?GetRadius@Object@@UAEMXZ @ 0x0062b6b0

void _GetRadius_Object__UAEMXZ(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0062b6b2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 100))();
  return;
}



// ?SelectOnlyAfterRecSystem@Object@@UAE_NXZ @ 0x00678900

bool _SelectOnlyAfterRecSystem_Object__UAE_NXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0xd4))();
  return iVar1 != 0;
}



// ?ValidToFightThisToObject@Object@@UAEIPAVGInterfaceStatus@@PBUMapCoords@@@Z @ 0x00678920

bool _ValidToFightThisToObject_Object__UAEIPAVGInterfaceStatus__PBUMapCoords___Z(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0xe4) == -1;
}



// ?FightThisToObject@Object@@UAEIPAVGInterfaceStatus@@PAV1@@Z @ 0x00678940

undefined4 _FightThisToObject_Object__UAEIPAVGInterfaceStatus__PAV1__Z(void)

{
  int in_ECX;
  LH_SamplePlayOptions aLStack_168 [4];
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_148;
  undefined4 uStack_144;
  
  if (*(int *)(in_ECX + 0xe4) == -1) {
    *(undefined4 *)(in_ECX + 0xe8) = 0xffffffff;
  }
  LH_SamplePlayOptions::LH_SamplePlayOptions(aLStack_168);
  uStack_164 = *(undefined4 *)(DAT_00bf4e68 + 0x3ac);
  uStack_144 = 1;
  uStack_148 = 0;
  uStack_160 = 0;
  FUN_00423db0(aLStack_168);
  LH_SamplePlayOptions::~LH_SamplePlayOptions(aLStack_168);
  return 1;
}



// ?ValidForPlaceInHand@Object@@UAE_NPAVGInterfaceStatus@@@Z @ 0x00678bd0

undefined4 _ValidForPlaceInHand_Object__UAE_NPAVGInterfaceStatus___Z(void)

{
  float fVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc4) = *(undefined4 *)(in_ECX + 0x14);
  *(undefined4 *)(in_ECX + 200) = *(undefined4 *)(in_ECX + 0x18);
  *(undefined4 *)(in_ECX + 0xcc) = *(undefined4 *)(in_ECX + 0x1c);
  fVar1 = *(float *)(in_ECX + 0xcc) - *(float *)(in_ECX + 0xd8);
  *(float *)(in_ECX + 0xf4) = fVar1;
  *(float *)(in_ECX + 0xf8) = fVar1;
  return 1;
}



// ?InterfaceMustBeInInfluenceForInteraction@Object@@UAE_NXZ @ 0x00678c50

undefined4 _InterfaceMustBeInInfluenceForInteraction_Object__UAE_NXZ(void)

{
  undefined4 uVar1;
  int in_ECX;
  int iVar2;
  
  if (*(int *)(in_ECX + 0xe4) == -1) {
    *(undefined4 *)(in_ECX + 0xe8) = 0xffffffff;
    return 1;
  }
  iVar2 = in_ECX + 0xc4;
  uVar1 = FUN_00430360(iVar2);
  FUN_005238a0(0x28,uVar1,iVar2);
  return 1;
}



// ?ValidToRemoveFromHand@Object@@UAE_NPAVGInterfaceStatus@@PBUMapCoords@@@Z @ 0x00678c90

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _ValidToRemoveFromHand_Object__UAE_NPAVGInterfaceStatus__PBUMapCoords___Z(float *param_1)

{
  undefined4 uVar1;
  int in_ECX;
  float10 fVar2;
  float10 extraout_ST0;
  float10 extraout_ST1;
  int iVar3;
  
  if (*(int *)(in_ECX + 0xe4) == -1) {
    *(undefined4 *)(in_ECX + 0xe8) = 0xffffffff;
    return 1;
  }
  if ((*(byte *)(in_ECX + 0x24) & 0x10) != 0) {
    *(float *)(in_ECX + 0xf4) = *param_1 / _DAT_00b2cf4c + *(float *)(in_ECX + 0xf4);
    fVar2 = (float10)FUN_006cb690();
    if (-fVar2 <= (float10)*(float *)(in_ECX + 0xf4)) {
      if (0.0 < *(float *)(in_ECX + 0xf4)) {
        *(undefined4 *)(in_ECX + 0xf4) = 0;
      }
    }
    else {
      *(float *)(in_ECX + 0xf4) = (float)-fVar2;
    }
    iVar3 = *(int *)(in_ECX + 0xe4);
    param_1 = (float *)__ftol();
    if (iVar3 < (int)param_1) {
      param_1 = (float *)iVar3;
    }
    fVar2 = -(((float10)1.0 - (float10)(int)param_1 / extraout_ST0) * extraout_ST1);
    *(float *)(in_ECX + 0xcc) = (float)((float10)*(float *)(in_ECX + 0xd8) + fVar2);
    if (fVar2 != (float10)*(float *)(in_ECX + 0xf8)) {
      iVar3 = in_ECX + 0xc4;
      *(float *)(in_ECX + 0xf8) = (float)fVar2;
      uVar1 = FUN_00430360(iVar3);
      FUN_005238a0(0x28,uVar1,iVar3);
      return 1;
    }
  }
  return 1;
}



// ?InterfaceSetOutMagicHand@Object@@UAE_NPAVGInterfaceStatus@@@Z @ 0x006820a0

undefined4 _InterfaceSetOutMagicHand_Object__UAE_NPAVGInterfaceStatus___Z(void)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  
  iVar1 = (**(code **)(*in_ECX + 0x1f0))();
  if (iVar1 != 0) {
    fVar2 = (float10)(**(code **)(*in_ECX + 100))();
    if ((float10)3.6 < fVar2) {
      return 0;
    }
  }
  return 1;
}



// ?SetPoisoned@Object@@UAEXH@Z @ 0x00682100

void _SetPoisoned_Object__UAEXH_Z(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x120))();
  __ftol();
  return;
}



// ?InterfaceValidToGiveObject@Object@@UAEIPAVGInterfaceStatus@@PAV1@@Z @ 0x00682270

undefined4 _InterfaceValidToGiveObject_Object__UAEIPAVGInterfaceStatus__PAV1__Z(void)

{
  int *in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 0x42c))();
  if ((float10)0.7 < fVar1) {
    return 1;
  }
  return 0;
}



// ?InterfaceGiveObject@Object@@UAEIPAVGInterfaceStatus@@PAV1@@Z @ 0x006822a0

undefined4 _InterfaceGiveObject_Object__UAEIPAVGInterfaceStatus__PAV1__Z(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  undefined4 uVar4;
  undefined4 uVar5;
  LH_SamplePlayOptions aLStack_168 [4];
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  int iStack_144;
  int iStack_138;
  int iStack_134;
  int iStack_130;
  
  FUN_00682380();
  iVar3 = param_1[0x33];
  iVar1 = param_1[0x32];
  iVar2 = param_1[0x34];
  LH_SamplePlayOptions::LH_SamplePlayOptions(aLStack_168);
  uStack_164 = *(undefined4 *)(DAT_00bf4e68 + 0x3ac);
  iStack_144 = DAT_00c7674c + 0x82;
  DAT_00c7674c = DAT_00c7674c + 1;
  if (DAT_00c7674c == 4) {
    DAT_00c7674c = 0;
  }
  uStack_15c = 0;
  uStack_160 = 1;
  iStack_138 = iVar1;
  iStack_134 = iVar3;
  iStack_130 = iVar2;
  FUN_00423db0(aLStack_168);
  iVar3 = (**(code **)(*param_1 + 0x1c))();
  if (iVar3 != 0) {
    iVar3 = in_ECX + 0x14;
    uVar5 = 0x3f000000;
    uVar4 = 3;
    (**(code **)(*param_1 + 0x1c))(3,0x3f000000,iVar3);
    FUN_004ae9a0(uVar4,uVar5,iVar3);
  }
  LH_SamplePlayOptions::~LH_SamplePlayOptions(aLStack_168);
  return 1;
}



// ?GetAlwaysRemainsInPhysicsInternalSystem@Object@@UAE_NXZ @ 0x00682750

void _GetAlwaysRemainsInPhysicsInternalSystem_Object__UAE_NXZ(int param_1)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  int *in_ECX;
  float10 fVar4;
  
  fVar1 = *(float *)(param_1 + 8) / (*(float *)(param_1 + 0x15c) * 9.81);
  piVar2 = (int *)FUN_005f3c50();
  if ((4.0 < fVar1) && (fVar4 = (float10)(**(code **)(*in_ECX + 0x42c))(), (float10)0.7 < fVar4)) {
    if ((piVar2 != (int *)0x0) && (iVar3 = (**(code **)(*piVar2 + 0x1f0))(), iVar3 != 0)) {
      return;
    }
    iVar3 = *in_ECX;
    fVar4 = (float10)(**(code **)(iVar3 + 0x11c))();
    (**(code **)(iVar3 + 0x5b0))((float)(fVar4 - ((float10)fVar1 - (float10)4.0) * (float10)0.005));
    fVar4 = (float10)(**(code **)(*in_ECX + 0x11c))();
    if (fVar4 < (float10)0.01) {
      FUN_00682380();
    }
  }
  return;
}



// ?CanBeStrokedByCreature@Object@@UAE_NPAVCreature@@@Z @ 0x00682880

void _CanBeStrokedByCreature_Object__UAE_NPAVCreature___Z(undefined4 param_1)

{
  _CanBePickedUpByCreature_Object__UAE_NPAVCreature___Z(param_1);
  return;
}



// ?GetUpdateOfBoredomValue@Object@@UAEMPAVReaction@@PAVGameThingWithPos@@@Z @ 0x006b8850

void _GetUpdateOfBoredomValue_Object__UAEMPAVReaction__PAVGameThingWithPos___Z
               (undefined4 param_1,undefined4 param_2)

{
  _GetUpdateOfBoredomValue_GameThingWithPos__UAEMPAUReaction__PAV1__Z(param_1,param_2);
  return;
}



// ?GetImpressiveValue@Object@@UAEMXZ @ 0x006bcd70

void _GetImpressiveValue_Object__UAEMXZ(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  _CallVirtualFunctionsForCreation_MultiMapFixed__UAEXABUMapCoords___Z(param_1);
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x40) + 0xf8))();
  *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) | 0x4000;
  (**(code **)(**(int **)(in_ECX + 0x40) + 0x80))();
  return;
}



// ?ValidToSelectFightThisToMapCoord@Object@@UAEIPAVGInterfaceStatus@@PBUMapCoords@@@Z @ 0x006bcf90

undefined4
_ValidToSelectFightThisToMapCoord_Object__UAEIPAVGInterfaceStatus__PBUMapCoords___Z(int *param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0xd4))();
  if (iVar1 != 0) {
    if ((*(uint *)(DAT_00c22ca4 + 0x14) & 0x2000) != 0) {
      (**(code **)(*in_ECX + 0x1c))();
      iVar1 = FUN_005f8140();
      if (iVar1 != 0) {
        return 1;
      }
    }
    iVar1 = (**(code **)(*param_1 + 0x1c))();
    iVar2 = (**(code **)(*in_ECX + 0x1c))();
    if (iVar2 == iVar1) {
      return 1;
    }
  }
  return 0;
}



// ?ValidToApplyFightThisToMapCoord@Object@@UAEIPAVGInterfaceStatus@@PBUMapCoords@@@Z @ 0x006bd000

undefined4
_ValidToApplyFightThisToMapCoord_Object__UAEIPAVGInterfaceStatus__PBUMapCoords___Z(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x914))();
  if (iVar1 != 0) {
    iVar1 = FUN_00707d80(param_1);
    if (iVar1 == 1) {
      iVar1 = FUN_00527d60();
      if (param_1 == iVar1) {
        uVar2 = (**(code **)(*in_ECX + 0x910))();
        FUN_006bd060(uVar2);
      }
    }
    return 1;
  }
  return 0;
}



// ?GetPSysFireFlameMatrix@Object@@UAE_NPAULHMatrix@@@Z @ 0x006bd160

undefined4 _GetPSysFireFlameMatrix_Object__UAE_NPAULHMatrix___Z(int *param_1)

{
  float fVar1;
  undefined4 uVar2;
  int *in_ECX;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float local_c;
  float local_8;
  float local_4;
  
  uVar2 = _MoveMapObject_Object__UAEIUMapCoords___Z(param_1);
  if (in_ECX[0x10] != 0) {
    fVar3 = (float10)(**(code **)(*in_ECX + 0x120))();
    fVar4 = (float10)(**(code **)(*in_ECX + 0x508))();
    fVar1 = (float)param_1[2];
    fVar5 = (float10)FUN_00760fd0();
    local_8 = (float)(fVar5 + (float10)fVar1);
    local_c = (float)*param_1 * 0.00015258789;
    local_4 = (float)param_1[1] * 0.00015258789;
    FUN_0041dbb0((float)fVar4,(float)fVar3);
  }
  if (in_ECX[0x1f] != 0) {
    local_c = 0.0;
    local_8 = 0.0;
    local_4 = 0.0;
    FUN_006bcd50(&local_c);
    (**(code **)(*(int *)in_ECX[0x1f] + 0x500))(&local_c);
  }
  return uVar2;
}



// ?GetPSysFireFlameMatrix@Object@@UAE_NPAULHMatrix@@@Z @ 0x006c88e0

undefined4 _GetPSysFireFlameMatrix_Object__UAE_NPAULHMatrix___Z(undefined4 *param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  
  iVar1 = *(int *)(in_ECX + 0x40);
  if (iVar1 == 0) {
    return 0;
  }
  puVar3 = (undefined4 *)(iVar1 + 0x14);
  for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
    *param_1 = *puVar3;
    puVar3 = puVar3 + 1;
    param_1 = param_1 + 1;
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),1);
}



// ?GetPSysFireWorldFlamePos@Object@@UAE_NPBULHPoint@@HPAU2@@Z @ 0x006c8910

uint _GetPSysFireWorldFlamePos_Object__UAE_NPBULHPoint__HPAU2__Z
               (float *param_1,int param_2,float *param_3)

{
  float *pfVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x40) == (int *)0x0) {
    *param_3 = *param_1;
    param_3[1] = param_1[1];
    fVar4 = param_1[2];
    param_3[2] = fVar4;
  }
  else {
    iVar3 = (**(code **)(**(int **)(in_ECX + 0x40) + 0x1a8))();
    if (iVar3 == 0) {
      iVar3 = *(int *)(in_ECX + 0x40);
      *param_3 = *param_1 * *(float *)(iVar3 + 0x14) +
                 *(float *)(iVar3 + 0x20) * param_1[1] + *(float *)(iVar3 + 0x2c) * param_1[2] +
                 *(float *)(iVar3 + 0x38);
      param_3[1] = *(float *)(iVar3 + 0x18) * *param_1 +
                   *(float *)(iVar3 + 0x24) * param_1[1] + *(float *)(iVar3 + 0x30) * param_1[2] +
                   *(float *)(iVar3 + 0x3c);
      param_3[2] = *(float *)(iVar3 + 0x1c) * *param_1 +
                   *(float *)(iVar3 + 0x28) * param_1[1] + *(float *)(iVar3 + 0x34) * param_1[2] +
                   *(float *)(iVar3 + 0x40);
      return CONCAT31((int3)((uint)(iVar3 + 0x14) >> 8),1);
    }
    fVar4 = (float)(**(code **)(**(int **)(in_ECX + 0x40) + 0xf8))();
    if (fVar4 == 0.0) {
      return 0;
    }
    if ((*(int *)(in_ECX + 0x40) != 0) &&
       (iVar3 = *(int *)(*(int *)(in_ECX + 0x40) + 0x80), iVar3 != 0)) {
      pfVar1 = (float *)(param_2 * 0x30 + 0x24 + iVar3);
      fVar4 = pfVar1[1];
      fVar2 = pfVar1[2];
      *param_3 = *pfVar1;
      param_3[1] = fVar4;
      param_3[2] = fVar2;
      return CONCAT31((int3)((uint)fVar4 >> 8),1);
    }
  }
  return (uint)fVar4 & 0xffffff00;
}



// ?GetPSysFireLocalRndFlamePos@Object@@UAE_NPAULHPoint@@PAH@Z @ 0x006c8a20

undefined4 _GetPSysFireLocalRndFlamePos_Object__UAE_NPAULHPoint__PAH_Z(float *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  int iVar3;
  float *pfVar4;
  float *pfVar5;
  float afStack_30 [12];
  
  if ((int *)in_ECX[0x10] == (int *)0x0) {
    *param_2 = 0;
  }
  else {
    iVar1 = (**(code **)(*(int *)in_ECX[0x10] + 0xf8))();
    if (iVar1 == 0) {
      return 0;
    }
    iVar2 = (**(code **)(*(int *)in_ECX[0x10] + 0x1ac))();
    if (iVar2 != 0) {
      afStack_30[0xb] = 0.0;
      afStack_30[10] = 0.0;
      afStack_30[9] = 0.0;
      afStack_30[7] = 0.0;
      afStack_30[6] = 0.0;
      afStack_30[5] = 0.0;
      afStack_30[3] = 0.0;
      afStack_30[2] = 0.0;
      afStack_30[1] = 0.0;
      afStack_30[8] = 1.0;
      afStack_30[4] = 1.0;
      afStack_30[0] = 1.0;
      FUN_0078f6e0(PTR_DAT_00b59edc,iVar1,afStack_30);
      iVar1 = FUN_0067bcf0(*(uint *)(iVar1 + 4) & 0xff);
      *param_2 = iVar1;
      pfVar4 = (float *)(PTR_DAT_00b59edc + iVar1 * 0x30);
      pfVar5 = afStack_30;
      for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
        *pfVar5 = *pfVar4;
        pfVar4 = pfVar4 + 1;
        pfVar5 = pfVar5 + 1;
      }
      *param_1 = afStack_30[9];
      param_1[1] = afStack_30[10];
      param_1[2] = afStack_30[0xb];
      return 1;
    }
    iVar2 = (**(code **)(*(int *)in_ECX[0x10] + 0x1a8))();
    if (iVar2 == 0) {
      FUN_00559500(iVar1,param_1,0);
      iVar1 = (**(code **)(*in_ECX + 0x478))();
      if (iVar1 != 0) {
        *param_1 = *param_1 * 0.5;
        param_1[1] = param_1[1] * 0.5;
        param_1[2] = param_1[2] * 0.5;
      }
      return 1;
    }
    if ((in_ECX[0x10] != 0) && (iVar2 = *(int *)(in_ECX[0x10] + 0x80), iVar2 != 0)) {
      iVar1 = FUN_0067bcf0(*(uint *)(iVar1 + 4) & 0xff);
      *param_2 = iVar1;
      pfVar4 = (float *)(iVar1 * 0x30 + iVar2);
      pfVar5 = afStack_30;
      for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
        *pfVar5 = *pfVar4;
        pfVar4 = pfVar4 + 1;
        pfVar5 = pfVar5 + 1;
      }
      *param_1 = afStack_30[9];
      param_1[1] = afStack_30[10];
      param_1[2] = afStack_30[0xb];
      return 1;
    }
  }
  return 0;
}



// ?GetPSysFireLocalFlameScale@Object@@UAEMXZ @ 0x006c8c00

float10 _GetPSysFireLocalFlameScale_Object__UAEMXZ(void)

{
  int iVar1;
  float fVar2;
  int *in_ECX;
  float10 fVar3;
  float fStack_4;
  
  if (in_ECX[0x10] == 0) {
    return (float10)0.0;
  }
  fVar3 = (float10)(**(code **)(*in_ECX + 100))();
  fStack_4 = (float)fVar3;
  fVar3 = (float10)(**(code **)(*in_ECX + 0x42c))();
  if ((float10)fStack_4 <= fVar3) {
    fStack_4 = (float)fVar3;
  }
  iVar1 = (**(code **)(*in_ECX + 0x478))();
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*(int *)in_ECX[0x10] + 0x1a8))();
    if (iVar1 == 0) {
      iVar1 = FUN_005ea4a0();
      if (iVar1 != 0) {
        fVar3 = (float10)(**(code **)(*in_ECX + 0x42c))();
        return fVar3 * (float10)0.3;
      }
      if (fStack_4 < 3.0) {
        fVar3 = (float10)(**(code **)(*in_ECX + 0x42c))();
        return fVar3 * (float10)0.5;
      }
      fVar2 = 0.5;
    }
    else {
      fVar2 = 0.3;
    }
  }
  else {
    fVar2 = 0.2;
  }
  fVar3 = (float10)(**(code **)(*in_ECX + 0x42c))();
  return fVar3 * (float10)fVar2;
}



// ?GetPSysFireMaxFlames@Object@@UAEIXZ @ 0x006c8ce0

undefined4 _GetPSysFireMaxFlames_Object__UAEIXZ(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  float10 fVar3;
  float fStack_4;
  
  if (in_ECX[0x10] == 0) {
    return 0;
  }
  fVar3 = (float10)(**(code **)(*in_ECX + 100))();
  fStack_4 = (float)fVar3;
  fVar3 = (float10)(**(code **)(*in_ECX + 0x42c))();
  if ((float10)fStack_4 <= fVar3) {
    fStack_4 = (float)fVar3;
  }
  iVar1 = (**(code **)(*in_ECX + 0x478))();
  if (iVar1 == 0) {
    uVar2 = 2;
    if (3.0 <= fStack_4) {
      uVar2 = 7;
    }
    return uVar2;
  }
  return 2;
}



// ?GetDistanceFromObject@Object@@UAEMPAV1@@Z @ 0x006c96c0

void _GetDistanceFromObject_Object__UAEMPAV1__Z(undefined4 param_1)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x698))(0,param_1);
  return;
}



// ?EndOnFire@Object@@UAEXXZ @ 0x006c96e0

void _EndOnFire_Object__UAEXXZ(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  int *piVar5;
  
  if (param_1 == 0) {
    if ((*(int **)(in_ECX + 0xc4) != (int *)0x0) &&
       (iVar2 = (**(code **)(**(int **)(in_ECX + 0xc4) + 0x2c))(), iVar2 != 0)) {
      if ((param_2 == 0) &&
         (cVar1 = (**(code **)(**(int **)(in_ECX + 0xc4) + 0x4a4))(), cVar1 == '\0')) {
        uVar3 = 0;
      }
      else {
        uVar3 = 1;
      }
      (**(code **)(**(int **)(in_ECX + 0xc4) + 0x698))(0,uVar3);
      return;
    }
  }
  else if (param_1 == 1) {
    piVar5 = (int *)(in_ECX + 200);
    iVar2 = 5;
    do {
      if (((int *)*piVar5 != (int *)0x0) &&
         (iVar4 = (**(code **)(*(int *)*piVar5 + 0x2c))(), iVar4 != 0)) {
        if ((param_2 == 0) && (cVar1 = (**(code **)(*(int *)*piVar5 + 0x4a4))(), cVar1 == '\0')) {
          uVar3 = 0;
        }
        else {
          uVar3 = 1;
        }
        (**(code **)(*(int *)*piVar5 + 0x698))(1,uVar3);
      }
      piVar5 = piVar5 + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}



// ?RemoveFromGame@Object@@UAEIXZ @ 0x006c9820

void _RemoveFromGame_Object__UAEIXZ(undefined4 param_1,undefined4 param_2)

{
  _IsScary_Object__UAE_NXZ(param_1,param_2);
  return;
}



// ?IsAllied@Object@@UAE_NPAV1@@Z @ 0x006c9840

undefined4 _IsAllied_Object__UAE_NPAV1__Z(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  if (param_2 != (int *)0x0) {
    (**(code **)(*param_2 + 0x1c))();
  }
  if ((*(byte *)(param_1 + 0x24) & 0x40) != 0) {
    iVar1 = FUN_005f56a0(param_1);
    if (iVar1 != 0) {
      iVar1 = *(int *)(iVar1 + 0x24);
      iVar2 = FUN_00527d60();
      if (iVar1 == iVar2) {
        FUN_00586170(6);
      }
    }
  }
  FUN_005ecb70(param_1,param_2);
  FUN_0067efc0();
  return 1;
}



// ?IsTouching@Object@@UAE_NPAUMapCoords@@@Z @ 0x006c9900

undefined4 _IsTouching_Object__UAE_NPAUMapCoords___Z(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_var;
  undefined4 extraout_var_00;
  undefined4 extraout_var_01;
  undefined4 uVar4;
  
  iVar1 = _DoCreatureMimicAfterAddingResource_MultiMapFixed__UAE_NW4RESOURCE_TYPE__PAVGInterfaceStatus___Z
                    (param_1,param_2);
  if (iVar1 == 0) {
    iVar1 = param_2[0x4a];
    if (param_1 == 0) {
      iVar2 = (**(code **)(*param_2 + 0x1c))();
      uVar4 = 0;
      if (iVar1 == iVar2) {
        uVar3 = 2;
        (**(code **)(*param_2 + 0x1c))(param_2,2);
        FUN_004cb260(param_2,uVar3,extraout_var,uVar4);
        return 1;
      }
      iVar1 = FUN_0067bc90(2,s_C__dev_black_StoragePit_cpp_00b45aa4,0x2b0);
      iVar1 = (iVar1 != 0) + 0x2b;
    }
    else {
      iVar2 = (**(code **)(*param_2 + 0x1c))();
      uVar4 = 0;
      if (iVar1 != iVar2) {
        uVar3 = 0x2d;
        (**(code **)(*param_2 + 0x1c))(param_2,0x2d);
        FUN_004cb260(param_2,uVar3,extraout_var_00,uVar4);
        return 1;
      }
      iVar1 = 4;
    }
    (**(code **)(*param_2 + 0x1c))(param_2,iVar1);
    FUN_004cb260(param_2,iVar1,extraout_var_01,uVar4);
  }
  return 1;
}



// ?ResolveLoad@Object@@UAEXXZ @ 0x006c9a10

undefined4 _ResolveLoad_Object__UAEXXZ(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _GetPos_GameThingWithPos__QAEPAUMapCoords__XZ(param_1);
  if (iVar1 != 0) {
    FUN_00532060(in_ECX + 0xc4);
    FUN_00532060(in_ECX + 200);
    return 1;
  }
  return 0;
}



// ?GetImpressiveValue@Object@@UAEMXZ @ 0x006c9b10

int _GetImpressiveValue_Object__UAEMXZ(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = _GetImpressiveValue_Object__UAEMXZ(param_1,param_2);
  if (iVar1 == 7) {
    iVar1 = 9;
  }
  return iVar1;
}



// ?SelectOnlyAfterRecSystem@Object@@UAE_NXZ @ 0x006cb490

undefined4 _SelectOnlyAfterRecSystem_Object__UAE_NXZ(int *param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 0x1c))();
  iVar2 = (**(code **)(*in_ECX + 0x1c))();
  if (iVar2 == iVar1) {
    iVar1 = (**(code **)(*in_ECX + 0xd4))();
    if (iVar1 != 0) {
      iVar1 = (**(code **)(*in_ECX + 0x890))();
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
  return 0;
}



// ?InterfaceMustBeInInfluenceForInteraction@Object@@UAE_NXZ @ 0x006cb500

undefined4 _InterfaceMustBeInInfluenceForInteraction_Object__UAE_NXZ(void)

{
  undefined4 uVar1;
  int in_ECX;
  int iVar2;
  
  iVar2 = in_ECX + 0xc4;
  uVar1 = FUN_00430360(iVar2);
  FUN_005238a0(0x28,uVar1,iVar2);
  return 1;
}



// ?ValidToRemoveFromHand@Object@@UAE_NPAVGInterfaceStatus@@PBUMapCoords@@@Z @ 0x006cb520

undefined4 _ValidToRemoveFromHand_Object__UAE_NPAVGInterfaceStatus__PBUMapCoords___Z(float *param_1)

{
  float fVar1;
  float fVar2;
  int in_ECX;
  float10 fVar3;
  
  if ((*(byte *)(in_ECX + 0x24) & 0x10) != 0) {
    fVar1 = *(float *)(in_ECX + 0xd8);
    fVar2 = *(float *)(in_ECX + 0xcc);
    fVar3 = (float10)FUN_006cb690();
    fVar1 = (fVar2 - fVar1) + *param_1;
    fVar2 = -(float)fVar3;
    if ((fVar2 <= fVar1) && (fVar2 = fVar1, 0.0 < fVar1)) {
      fVar2 = 0.0;
    }
    *(float *)(in_ECX + 0xcc) = *(float *)(in_ECX + 0xd8) + fVar2;
  }
  return 1;
}



// ?FillInEffectDefenceMultiplier@Object@@UAEXPAVEffectNumbers@@@Z @ 0x006cbaf0

void _FillInEffectDefenceMultiplier_Object__UAEXPAVEffectNumbers___Z(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x7c) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x7c) + 0x5bc))(param_1);
    return;
  }
  _IncreaseLife_Object__UAEXM_Z(param_1);
  return;
}



// ?ReduceLifeDueToBurning@Object@@UAEXMPAVGPlayer@@@Z @ 0x006cbb20

void _ReduceLifeDueToBurning_Object__UAEXMPAVGPlayer___Z(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x7c) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x7c) + 0x5b8))(param_1,param_2);
    return;
  }
  _ReduceLife_MultiMapFixed__UAEXMPAVGPlayer___Z(param_1,param_2);
  return;
}



// ?GetWoodValue@Object@@UAEMXZ @ 0x006cbbd0

void _GetWoodValue_Object__UAEMXZ(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int *in_ECX;
  float10 fVar7;
  float fStack_14;
  float fStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = 0;
  uStack_8 = 0;
  uStack_4 = 0;
  uVar4 = (**(code **)(*in_ECX + 0x65c))();
  piVar5 = (int *)FUN_005ecd90(uVar4);
  in_ECX[0x23] = (int)piVar5;
  (**(code **)(*piVar5 + 0x80))();
  fVar7 = (float10)(**(code **)(*in_ECX + 0x120))();
  fVar1 = (float)fVar7;
  fVar7 = (float10)(**(code **)(*in_ECX + 0x508))();
  fVar2 = (float)fVar7;
  fVar3 = (float)in_ECX[7];
  iVar6 = in_ECX[0x23];
  fVar7 = (float10)FUN_00760fd0();
  fStack_14 = (float)(fVar7 + (float10)fVar3);
  fStack_10 = (float)in_ECX[6] * 0.00015258789;
  if (fVar2 == 0.0) {
    if (fVar1 == 1.0) {
      FUN_004022b0();
    }
    else {
      FUN_004f5940(fVar1);
      FUN_004022f0();
    }
  }
  else if (fVar1 == 1.0) {
    FUN_004022b0();
    FUN_004f5f10(fVar2);
  }
  else {
    FUN_004f5940(fVar1);
    FUN_004022f0();
    FUN_004f5f10(fVar2);
  }
  *(float *)(iVar6 + 0x48) = fVar2;
  *(float *)(iVar6 + 0x44) = fVar1;
  (**(code **)(*in_ECX + 0x608))();
  (**(code **)(*(int *)in_ECX[0x23] + 0xf4))(0,0);
  (**(code **)(*(int *)in_ECX[0x23] + 0x58))();
  iVar6 = FUN_005ed240(0,&fStack_14);
  if (iVar6 == 1) {
    _CallVirtualFunctionsForCreation_MultiMapFixed__UAEXABUMapCoords___Z(&fStack_14);
    (**(code **)(*(int *)in_ECX[0x10] + 0x80))();
  }
  else {
    (**(code **)(*in_ECX + 0x850))();
  }
  iVar6 = in_ECX[0x27];
  in_ECX[0x22] = iVar6;
  in_ECX[0x24] = iVar6;
  in_ECX[0x35] = 0;
  in_ECX[0x25] = iVar6;
  return;
}



// ?IsReadyForNetworkUnfriendlyLockedSelect@Object@@UAE_NXZ @ 0x006cc310

undefined4 _IsReadyForNetworkUnfriendlyLockedSelect_Object__UAE_NXZ(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 0x1c))();
  iVar2 = (**(code **)(*in_ECX + 0x1c))();
  if (iVar2 == iVar1) {
    iVar1 = (**(code **)(*in_ECX + 0xd4))();
    if (iVar1 != 0) {
      iVar1 = (**(code **)(*in_ECX + 0x1c))();
      if ((*(int *)(iVar1 + 0x260) != 0) &&
         (piVar3 = *(int **)(*(int *)(iVar1 + 0x260) + 0x30), piVar3 != (int *)0x0)) {
        iVar1 = (**(code **)(*piVar3 + 0x890))();
        if (iVar1 != 0) {
          piVar3 = (int *)(**(code **)(*in_ECX + 0x48))();
          if (piVar3 != (int *)0x0) {
            piVar3 = (int *)(**(code **)(*piVar3 + 0x30c))();
            if (piVar3 != (int *)0x0) {
              iVar1 = (**(code **)(*piVar3 + 0x890))();
              if (iVar1 != 0) {
                return 1;
              }
            }
          }
        }
      }
    }
  }
  return 0;
}



// ?GetReadyForNetworkUnfriendlyEndLockedSelect@Object@@UAE_NXZ @ 0x006cc3f0

undefined4 _GetReadyForNetworkUnfriendlyEndLockedSelect_Object__UAE_NXZ(void)

{
  int iVar1;
  int in_ECX;
  float10 fVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  fVar2 = (float10)FUN_006cc2b0();
  *(float *)(in_ECX + 0x88) = (float)fVar2;
  uVar4 = 0x80000000;
  uVar3 = 0xf;
  FUN_00527d30(0xf,0x80000000);
  FUN_00598f00(uVar3,uVar4);
  iVar1 = FUN_00527d30();
  FUN_006b34d0(*(undefined4 *)(iVar1 + 0x39c),*(undefined4 *)(in_ECX + 0x88));
  return 1;
}



// ?ValidAsInterfaceLeashTarget@Object@@UAE_NXZ @ 0x006cc440

undefined4 _ValidAsInterfaceLeashTarget_Object__UAE_NXZ(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  undefined4 uVar3;
  
  uVar3 = *(undefined4 *)(in_ECX + 0x88);
  uVar1 = FUN_00430360(uVar3);
  FUN_00523cb0(0x29,uVar1,uVar3);
  iVar2 = FUN_00527d30();
  FUN_006b34f0(*(undefined4 *)(iVar2 + 0x39c),*(undefined4 *)(in_ECX + 0x88));
  uVar3 = 0xf;
  FUN_00527d30(0xf);
  FUN_00598f70(uVar3);
  return 1;
}



// ?GetDrawRegion@Object@@UAEXPAULHRegion@@@Z @ 0x006cc760

void _GetDrawRegion_Object__UAEXPAULHRegion___Z(void)

{
  undefined4 *puVar1;
  byte bVar2;
  int *piVar3;
  int *piVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined4 uVar11;
  int *in_ECX;
  float10 fVar12;
  float10 fVar13;
  float10 fVar14;
  float fStack_3c;
  float fStack_38;
  int iStack_24;
  int iStack_20;
  float fStack_1c;
  undefined4 uStack_18;
  float fStack_14;
  undefined4 uStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  (*(code *)0x4ab7641)();
  iVar9 = __ftol();
  fVar5 = (float)(uint)(iVar9 - in_ECX[0x34]) + (float)in_ECX[0x2c];
  in_ECX[0x2c] = (int)fVar5;
  if (fVar5 < (float)in_ECX[0x2d]) {
    fVar7 = fVar5 * fVar5 * 0.5;
    fVar6 = fVar5 * fVar7 * 0.33333334;
    in_ECX[0x2a] = (int)(fVar6 * (float)in_ECX[0x32] +
                         fVar7 * (float)in_ECX[0x31] + fVar5 * (float)in_ECX[0x30] +
                        (float)in_ECX[0x2f]);
    in_ECX[0x27] = (int)(fVar7 * (float)in_ECX[0x30] +
                         fVar6 * (float)in_ECX[0x31] +
                         (float)in_ECX[0x2f] * (float)in_ECX[0x2c] +
                         fVar7 * fVar7 * 0.16666667 * (float)in_ECX[0x32] + (float)in_ECX[0x2e]);
  }
  else {
    in_ECX[0x27] = in_ECX[0x28];
    in_ECX[0x2a] = in_ECX[0x29];
    in_ECX[0x2b] = 0;
    in_ECX[0x2c] = in_ECX[0x2d];
  }
  in_ECX[0x34] = iVar9;
  iVar9 = (**(code **)(*in_ECX + 0x890))();
  if (iVar9 != 0) {
    fVar12 = (float10)(**(code **)(*in_ECX + 0x11c))();
    if ((float10)0.0 < fVar12) {
      fStack_3c = (float)in_ECX[0x27] * 8.0;
      fStack_38 = (float)in_ECX[0x22] * 8.0;
      if ((*(byte *)(in_ECX + 9) & 0x10) != 0) {
        fStack_3c = (float)in_ECX[0x22] * 8.0;
        fStack_38 = (float)in_ECX[0x27] * 8.0;
      }
      iVar9 = in_ECX[0x23];
      uStack_18 = *(undefined4 *)(iVar9 + 0x38);
      fStack_14 = *(float *)(iVar9 + 0x3c);
      uStack_10 = *(undefined4 *)(iVar9 + 0x40);
      if (fStack_38 != fStack_3c) {
        fStack_14 = (fStack_38 - (float)in_ECX[0x26]) + fStack_14;
        FUN_005bf830(&uStack_18);
        fVar12 = (float10)(**(code **)(*in_ECX + 0x120))();
        fVar13 = (float10)(**(code **)(*in_ECX + 0x508))();
        fVar14 = (float10)FUN_00760fd0();
        fStack_8 = (float)(fVar14 + (float10)fStack_1c);
        fStack_c = (float)iStack_24 * 0.00015258789;
        fStack_4 = (float)iStack_20 * 0.00015258789;
        FUN_0041dbb0((float)fVar13,(float)fVar12);
        fStack_1c = fStack_1c + 2.729;
        fVar12 = (float10)(**(code **)(*in_ECX + 0x120))();
        fVar13 = (float10)(**(code **)(*in_ECX + 0x508))();
        fVar14 = (float10)FUN_00760fd0();
        fStack_8 = (float)(fVar14 + (float10)fStack_1c);
        fStack_c = (float)iStack_24 * 0.00015258789;
        fStack_4 = (float)iStack_20 * 0.00015258789;
        FUN_0041dbb0((float)fVar13,(float)fVar12);
        piVar3 = (int *)in_ECX[0x23];
        piVar4 = (int *)in_ECX[0x10];
        in_ECX[0x25] = (int)fStack_3c;
        in_ECX[0x10] = (int)piVar3;
        (**(code **)(*piVar3 + 0x48))();
        *(undefined1 *)((int)piVar3 + 0x4f) = 0x80;
        FUN_005ed470();
        (**(code **)(*(int *)in_ECX[0x10] + 0x48))();
        in_ECX[0x10] = (int)piVar4;
        (**(code **)(*piVar4 + 0x48))();
        *(undefined1 *)(in_ECX[0x10] + 0x4f) = 0x80;
        FUN_005ed470();
        (**(code **)(*(int *)in_ECX[0x10] + 0x48))();
        fStack_14 = ((float)in_ECX[0x26] - fStack_38) + fStack_14;
      }
      if ((fStack_3c != (float)in_ECX[0x24]) || (fStack_38 != fStack_3c)) {
        if (in_ECX[0x35] == 0) {
          bVar2 = *(byte *)(DAT_00c22ca4 + 0x201b15);
          iVar9 = DAT_00c22ca4 + 0x18;
          iVar10 = (**(code **)(*in_ECX + 0x1c))();
          if (iVar10 == iVar9 + (uint)bVar2 * 0x278) {
            FUN_0058ac80(0xeeb,(float)in_ECX[0x22] * 100.0);
          }
        }
        in_ECX[0x35] = 0;
        fStack_14 = (fStack_3c - (float)in_ECX[0x26]) + fStack_14;
        FUN_005bf830(&uStack_18);
        fVar12 = (float10)(**(code **)(*in_ECX + 0x120))();
        fVar13 = (float10)(**(code **)(*in_ECX + 0x508))();
        fVar14 = (float10)FUN_00760fd0();
        fStack_8 = (float)(fVar14 + (float10)fStack_1c);
        fStack_c = (float)iStack_24 * 0.00015258789;
        fStack_4 = (float)iStack_20 * 0.00015258789;
        FUN_0041dbb0((float)fVar13,(float)fVar12);
        fVar12 = (float10)(**(code **)(*in_ECX + 0x120))();
        fVar13 = (float10)(**(code **)(*in_ECX + 0x508))();
        fVar14 = (float10)FUN_00760fd0();
        fStack_8 = (float)(fVar14 + (float10)(fStack_1c + 2.729));
        fStack_c = (float)iStack_24 * 0.00015258789;
        fStack_4 = (float)iStack_20 * 0.00015258789;
        FUN_0041dbb0((float)fVar13,(float)fVar12);
        in_ECX[0x26] = (int)fStack_3c;
        in_ECX[0x24] = (int)fStack_3c;
      }
      iVar9 = in_ECX[0x23];
      iVar10 = in_ECX[0x10];
      puVar1 = (undefined4 *)(iVar9 + 0x50);
      in_ECX[0x10] = iVar9;
      FUN_0075fc20(iVar9 + 0x38,iVar9 + 0x4c,puVar1);
      uVar11 = FUN_0075d130(iVar9 + 0x38,*puVar1,iVar9 + 0x4c);
      *puVar1 = uVar11;
      FUN_005ed470();
      uVar8 = DAT_00d78910;
      puVar1 = (undefined4 *)(iVar10 + 0x50);
      in_ECX[0x10] = iVar10;
      FUN_0075fc20(iVar10 + 0x38,iVar10 + 0x4c,puVar1);
      uVar11 = FUN_0075d130(iVar10 + 0x38,*puVar1,iVar10 + 0x4c);
      *puVar1 = uVar11;
      FUN_005ed470();
      DAT_00d78910 = DAT_00d78910 | uVar8;
    }
  }
  return;
}



// ?GetTribalPower@Object@@UAEMW4TRIBE_TYPE@@@Z @ 0x006d1260

float10 _GetTribalPower_Object__UAEMW4TRIBE_TYPE___Z(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x1c))();
  if (iVar1 != 0) {
    return (float10)*(float *)(iVar1 + 0x68 + param_1 * 4);
  }
  return (float10)1.0;
}



// ?ApplyWaterSpell@Object@@UAEMPAVSpellWater@@@Z @ 0x006d5e80

void _ApplyWaterSpell_Object__UAEMPAVSpellWater___Z(void)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  
  Creche_vf406(in_ECX + 0x14);
  (**(code **)(**(int **)(in_ECX + 0x40) + 0x1e8))();
  piVar1 = (int *)FUN_007677c0();
  *(int **)(in_ECX + 0xc4) = piVar1;
  (**(code **)(*piVar1 + 0xf4))(0,0);
  uVar2 = (**(code **)(**(int **)(in_ECX + 0xc4) + 0xf8))();
  FUN_00548b20(uVar2,&stack0xfffffff0);
  (**(code **)(**(int **)(in_ECX + 0xc4) + 0x98))();
  return;
}



// ?ProcessState@Object@@UAEIXZ @ 0x006d5f80

undefined4 _ProcessState_Object__UAEIXZ(void)

{
  int in_ECX;
  
  _GetProjectileSpeed_Object__UAEMXZ();
  if (*(int **)(in_ECX + 0xcc) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0xcc) + 0x5fc))();
  }
  return 1;
}



// ?ScaffoldMoved@Object@@UAEXPAVScaffold@@@Z @ 0x006d6450

float10 _ScaffoldMoved_Object__UAEXPAVScaffold___Z(undefined4 param_1)

{
  int *in_ECX;
  float10 fVar1;
  float fStack_4;
  
  fStack_4 = 0.0;
  fVar1 = (float10)(**(code **)(*in_ECX + 0x11c))();
  if (fVar1 < (float10)1.0) {
    fVar1 = (float10)_ScaffoldMoved_Object__UAEXPAVScaffold___Z(param_1);
    fStack_4 = (float)fVar1;
    if ((int *)in_ECX[0x33] != (int *)0x0) {
      (**(code **)(*(int *)in_ECX[0x33] + 0x5b0))(fStack_4);
    }
  }
  return (float10)fStack_4;
}



// ?DrawValue@Object@@UAEXHM@Z @ 0x006d6670

float10 _DrawValue_Object__UAEXHM_Z(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)_DrawValue_Object__UAEXHM_Z(param_1,param_2);
  if (*(int **)(in_ECX + 0xcc) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0xcc) + 0x5b0))((float)fVar1);
  }
  return (float10)(float)fVar1;
}



// ?GetFoodType@Object@@UAE?AW4FOOD_TYPE@@XZ @ 0x006d67a0

uint _GetFoodType_Object__UAE_AW4FOOD_TYPE__XZ(undefined4 param_1,int *param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *in_ECX;
  
  uVar2 = _GetImpressiveValue_Object__UAEMXZ(param_1,param_2);
  if ((uVar2 != 7) && (uVar2 != 4)) {
    iVar3 = (**(code **)(*param_2 + 0x48))();
    iVar4 = (**(code **)(*in_ECX + 0x48))();
    if (iVar4 != iVar3) {
      (**(code **)(*in_ECX + 0x48))();
      cVar1 = FUN_006d2a70();
      return -(uint)(cVar1 != '\0') & 10;
    }
  }
  return uVar2;
}



// ?GetImpressiveValue@Object@@UAEMXZ @ 0x006da650

void _GetImpressiveValue_Object__UAEMXZ(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *in_ECX;
  float10 fVar4;
  
  _Create3DObject_Object__UAEXXZ();
  (**(code **)(*in_ECX + 0x850))();
  (**(code **)(*(int *)in_ECX[0x10] + 0x80))();
  fVar4 = (float10)(**(code **)(*in_ECX + 0x120))();
  fVar1 = (float)fVar4;
  fVar4 = (float10)(**(code **)(*in_ECX + 0x508))();
  fVar2 = (float)fVar4;
  iVar3 = in_ECX[0x10];
  FUN_00760fd0();
  if (fVar2 == 0.0) {
    if (fVar1 == 1.0) {
      FUN_004022b0();
    }
    else {
      FUN_004f5940(fVar1);
      FUN_004022f0();
    }
  }
  else if (fVar1 == 1.0) {
    FUN_004022b0();
    FUN_004f5f10(fVar2);
  }
  else {
    FUN_004f5940(fVar1);
    FUN_004022f0();
    FUN_004f5f10(fVar2);
  }
  *(float *)(iVar3 + 0x44) = fVar1;
  *(float *)(iVar3 + 0x48) = fVar2;
  (**(code **)(*(int *)in_ECX[10] + 0x2c))();
  (**(code **)(*(int *)in_ECX[0x10] + 0xf4))(0,0);
  (**(code **)(*(int *)in_ECX[0x10] + 0x58))();
  FUN_006bce20();
  FUN_006da800();
  return;
}



// ?ResolveLoad@Object@@UAEXXZ @ 0x006da890

undefined4 _ResolveLoad_Object__UAEXXZ(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_006be480(param_1);
  if (iVar1 != 0) {
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x114));
    return 1;
  }
  return 0;
}



// ?ResolveLoad@Object@@UAEXXZ @ 0x006da910

undefined4 _ResolveLoad_Object__UAEXXZ(uint param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  byte *pbVar4;
  
  iVar1 = param_1;
  iVar2 = _ResolveLoad_Object__UAEXXZ(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0x118));
  param_1 = 3;
  if (DAT_00b19ac8 != 0) {
    iVar2 = FUN_0072be90(&param_1,4,0);
    if (iVar2 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + (param_1 & 0xff) + 4;
    uVar3 = 0;
    if (param_1 != 0) {
      pbVar4 = (byte *)(in_ECX + 0x11c);
      do {
        if (DAT_00b19ac8 == 0) {
          return 1;
        }
        iVar2 = FUN_0072be90(pbVar4,4,0);
        if (iVar2 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *pbVar4 + 4;
        if (DAT_00b19ac8 == 0) {
          return 1;
        }
        uVar3 = uVar3 + 1;
        pbVar4 = pbVar4 + 4;
      } while (uVar3 < param_1);
    }
  }
  return 1;
}



// ?GetNearestEdgeOfObject@Object@@UAEXPAV1@@Z @ 0x006dbef0

int _GetNearestEdgeOfObject_Object__UAEXPAV1__Z(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *in_ECX;
  uint uVar6;
  char *pcVar7;
  float10 fVar8;
  double dVar9;
  undefined1 auStack_138 [12];
  char acStack_12c [200];
  undefined1 auStack_64 [100];
  
  iVar2 = FUN_0053eb80();
  if (iVar2 == 0) {
    return 0;
  }
  if (param_2 != 0) {
    FUN_005c13b0(auStack_138,param_2);
  }
  iVar3 = (**(code **)(*in_ECX + 0x86c))();
  if ((iVar3 == 0) || (param_2 != 0)) {
    uVar5 = 0xffffffff;
  }
  else {
    iVar3 = (**(code **)(*in_ECX + 0x86c))();
    uVar5 = *(undefined4 *)(iVar3 + 0x40);
  }
  iVar3 = in_ECX[10];
  fVar8 = (float10)(**(code **)(*in_ECX + 0x120))((double)(float)in_ECX[0x19]);
  fVar8 = (float10)(**(code **)(*in_ECX + 0x508))((double)fVar8);
  iVar3 = (iVar3 + -0xcc4770) / 0x140;
  dVar9 = (double)fVar8;
  uVar6 = *(byte *)((int)in_ECX + 0x5e) >> 1 & 1;
  uVar4 = FUN_005bf290(auStack_64);
  uVar5 = FUN_006ad590(0x1c,uVar5,uVar4,iVar3,uVar6,dVar9);
  FUN_00733e17(acStack_12c,uVar5);
  iVar3 = -1;
  pcVar7 = acStack_12c;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  FUN_006b10c0();
  return iVar2;
}



// ?InterfaceSetOutMagicHand@Object@@UAE_NPAVGInterfaceStatus@@@Z @ 0x006dcc00

undefined4 _InterfaceSetOutMagicHand_Object__UAE_NPAVGInterfaceStatus___Z(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  
  if ((*(byte *)(in_ECX + 0x24) & 0x40) == 0) {
    uVar1 = FUN_006b6100(0x20,3,0,3,0,0,1,1,0);
    FUN_006b5f20(in_ECX + 0x14,uVar1);
    iVar2 = (**(code **)(*param_1 + 0x1c))();
    if (iVar2 != 0) {
      FUN_004124b0(iVar2,in_ECX,0);
    }
  }
  return 1;
}



// ?GetBoundingSphere@Object@@UAEXPAULHPoint@@PAM@Z @ 0x006dd110

undefined4 _GetBoundingSphere_Object__UAEXPAULHPoint__PAM_Z(void)

{
  int iVar1;
  int iVar2;
  float fVar3;
  uint uVar4;
  int in_ECX;
  float10 fVar5;
  LH_SamplePlayOptions aLStack_168 [4];
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  int iStack_144;
  float fStack_138;
  float fStack_134;
  float fStack_130;
  
  fVar3 = *(float *)(in_ECX + 0x1c);
  fVar5 = (float10)FUN_00760fd0();
  iVar1 = *(int *)(in_ECX + 0x14);
  iVar2 = *(int *)(in_ECX + 0x18);
  LH_SamplePlayOptions::LH_SamplePlayOptions(aLStack_168);
  uStack_164 = *(undefined4 *)(DAT_00bf4e68 + 0x3ac);
  uVar4 = (*(code *)0x4ab7641)();
  uStack_160 = 1;
  uStack_15c = 0;
  iStack_144 = uVar4 % 3 + 0x53;
  fStack_138 = (float)iVar1 * 0.00015258789;
  fStack_134 = (float)(fVar5 + (float10)fVar3);
  fStack_130 = (float)iVar2 * 0.00015258789;
  FUN_00423db0(aLStack_168);
  LH_SamplePlayOptions::~LH_SamplePlayOptions(aLStack_168);
  return 1;
}



// ?ValidForLockedApplyProcess@Object@@UAEIPAVGInterfaceStatus@@@Z @ 0x006dd430

undefined4
_ValidForLockedApplyProcess_Object__UAEIPAVGInterfaceStatus___Z
          (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  
  piVar1 = (int *)FUN_005c11c0();
  if (piVar1 != (int *)0x0) {
    iVar3 = *piVar1;
    uVar2 = (**(code **)(*in_ECX + 0x690))();
    iVar3 = (**(code **)(iVar3 + 0x680))(uVar2);
    if (iVar3 != 0) {
      iVar3 = (**(code **)(*piVar1 + 0x684))();
      if (iVar3 != 0) {
        return 3;
      }
    }
  }
  uVar2 = _ApplyThisToMapCoord_Mobile__UAEIPAVGInterfaceStatus__ABUMapCoords__PAUGestureSystemPacketData___Z
                    (param_1,param_2,param_3);
  return uVar2;
}



// ?GetRadiusMultiplierForApplyingPotToPos@Object@@UAEMXZ @ 0x00702560

undefined4 _GetRadiusMultiplierForApplyingPotToPos_Object__UAEMXZ(void)

{
  int in_ECX;
  
  switch(*(undefined4 *)(*(int *)(in_ECX + 0x28) + 0x158)) {
  default:
    return 1;
  case 1:
  case 2:
  case 5:
  case 6:
    return 0;
  }
}



// ?GetWoodValue@Object@@UAEMXZ @ 0x00704aa0

void _GetWoodValue_Object__UAEMXZ(undefined4 param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *in_ECX;
  float10 fVar4;
  
  iVar3 = (**(code **)(*in_ECX + 0x114))();
  if (*(int *)(*(int *)(iVar3 + 0x30) + 0x40) == 0) {
    iVar3 = (**(code **)(*in_ECX + 0x114))();
    (**(code **)(**(int **)(iVar3 + 0x30) + 0x658))(param_1);
  }
  (**(code **)(*in_ECX + 0x114))();
  (**(code **)(*in_ECX + 0x538))();
  (**(code **)(*(int *)in_ECX[0x10] + 0xf4))(0,0);
  fVar4 = (float10)(**(code **)(*in_ECX + 0x120))();
  fVar1 = (float)fVar4;
  fVar4 = (float10)(**(code **)(*in_ECX + 0x508))();
  fVar2 = (float)fVar4;
  iVar3 = in_ECX[0x10];
  FUN_00761280(iVar3 + 0x50);
  if (fVar2 == 0.0) {
    if (fVar1 == 1.0) {
      FUN_004022b0();
    }
    else {
      FUN_004f5940(fVar1);
      FUN_004022f0();
    }
  }
  else if (fVar1 == 1.0) {
    FUN_004022b0();
    FUN_004f5f10(fVar2);
  }
  else {
    FUN_004f5940(fVar1);
    FUN_004022f0();
    FUN_004f5f10(fVar2);
  }
  *(float *)(iVar3 + 0x48) = fVar2;
  *(float *)(iVar3 + 0x44) = fVar1;
  (**(code **)(*in_ECX + 0x850))();
  FUN_00504d40();
  if (((*(byte *)(in_ECX + 9) & 4) == 0) && ((*(byte *)((int)in_ECX + 10) & 0x11) == 0)) {
    (**(code **)(*in_ECX + 0x544))();
  }
  (**(code **)(*(int *)in_ECX[0x10] + 0x1e8))();
  iVar3 = (**(code **)(*(int *)in_ECX[0x10] + 0xf8))();
  *(uint *)(iVar3 + 4) = *(uint *)(iVar3 + 4) | 0x4000;
  (**(code **)(*(int *)in_ECX[0x10] + 0x88))();
  (**(code **)(*(int *)in_ECX[0x10] + 0x80))();
  (**(code **)(*(int *)in_ECX[0x10] + 0x78))();
  return;
}



// ?GetNearestPosOfObject@Object@@UAEXPAV1@@Z @ 0x007051e0

int _GetNearestPosOfObject_Object__UAEXPAV1__Z(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  int *in_ECX;
  char *pcVar6;
  float10 fVar7;
  undefined *puVar8;
  undefined *puVar9;
  undefined4 uStack_15c;
  undefined4 uStack_158;
  undefined4 uStack_154;
  int iStack_150;
  float fStack_14c;
  float fStack_148;
  undefined4 uStack_144;
  undefined4 uStack_140;
  undefined4 uStack_13c;
  undefined1 auStack_138 [12];
  char acStack_12c [200];
  undefined1 auStack_64 [100];
  
  iVar2 = FUN_0053eb80();
  if (iVar2 == 0) {
    return 0;
  }
  uStack_15c = 0;
  uStack_158 = 0;
  uStack_154 = 0;
  iStack_150 = iVar2;
  FUN_00705db0(&uStack_15c);
  if (param_2 == 0) {
    puVar3 = &uStack_15c;
  }
  else {
    puVar3 = (undefined4 *)FUN_005c13b0(auStack_138,param_2);
  }
  uStack_144 = *puVar3;
  uStack_140 = puVar3[1];
  uStack_13c = puVar3[2];
  fVar7 = (float10)(**(code **)(*in_ECX + 0x120))();
  fStack_148 = (float)fVar7;
  if ((~*(byte *)(in_ECX + 0x16) & 2) != 0) {
    iVar4 = (**(code **)(*in_ECX + 0x890))();
    if (iVar4 != 0) {
      fVar7 = (float10)(**(code **)(*in_ECX + 0x508))();
      fStack_14c = (float)fVar7;
      (**(code **)(*in_ECX + 0x1c))();
      iVar2 = FUN_005f7d20();
      puVar8 = (&PTR_s_PLAYER_ONE_00b228d4)[iVar2];
      iVar2 = in_ECX[10];
      uVar5 = __ftol();
      uVar5 = __ftol(uVar5);
      iVar4 = FUN_007053a0(uVar5);
      puVar9 = (&PTR_s_CELTIC_00b45f28)[iVar4];
      iVar2 = (iVar2 + -0xcec6c0) / 0x160;
      uVar5 = FUN_005bf290(auStack_64);
      uVar5 = FUN_006ad590(0x16,uVar5,iVar2,puVar8,puVar9);
      FUN_00733e17(acStack_12c,uVar5);
      iVar2 = -1;
      pcVar6 = acStack_12c;
      do {
        if (iVar2 == 0) break;
        iVar2 = iVar2 + -1;
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      FUN_006b10c0();
      iVar2 = iStack_150;
    }
  }
  _SaveObject_MultiMapFixed__UAEIPAVLHOSFile__PBUMapCoords___Z(param_1,param_2);
  return iVar2;
}



// ?GetHeight@Object@@UAEMXZ @ 0x007053b0

float10 _GetHeight_Object__UAEMXZ(void)

{
  uint uVar1;
  int *in_ECX;
  float unaff_ESI;
  float10 fVar2;
  
  FUN_004ea4f0();
  uVar1 = (**(code **)(*in_ECX + 0x98))(0);
  fVar2 = ((float10)uVar1 + (float10)0.0001) / ((float10)unaff_ESI + (float10)0.0001);
  if ((float10)1.0 <= fVar2) {
    fVar2 = (float10)1.0;
  }
  return (float10)1.0 - fVar2;
}



// ?ProcessInHand@Object@@UAE_NXZ @ 0x00705bd0

undefined4 _ProcessInHand_Object__UAE_NXZ(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  float10 extraout_ST0;
  undefined1 auStack_18 [12];
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (*(int *)(in_ECX + 0x40) != 0) {
    FUN_005ed220(param_1,auStack_18);
    uStack_c = __ftol();
    uStack_8 = __ftol();
    uStack_4 = 0;
    FUN_00760fd0();
    uVar1 = __ftol();
    *param_2 = uVar1;
    uVar1 = __ftol();
    param_2[2] = (float)extraout_ST0;
    param_2[1] = uVar1;
    return 1;
  }
  *param_2 = *(undefined4 *)(in_ECX + 0x14);
  param_2[1] = *(undefined4 *)(in_ECX + 0x18);
  param_2[2] = *(undefined4 *)(in_ECX + 0x1c);
  return 0;
}



// ?PushObject@Object@@UAEXPAVLiving@@PAUMapCoords@@@Z @ 0x00705ed0

undefined4 _PushObject_Object__UAEXPAVLiving__PAUMapCoords___Z(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x114))();
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*in_ECX + 0x114))();
    uVar2 = (**(code **)(**(int **)(iVar1 + 0x30) + 0x80c))();
    return uVar2;
  }
  return 0;
}



// ?GetNearestEdge@Object@@UAEXMM@Z @ 0x00706990

void _GetNearestEdge_Object__UAEXMM_Z(float *param_1,int *param_2)

{
  int iVar1;
  float fVar2;
  undefined4 uVar3;
  int *piVar4;
  int in_ECX;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  undefined1 *puVar8;
  undefined1 auStack_24 [12];
  undefined1 auStack_18 [12];
  undefined1 auStack_c [12];
  
  fVar5 = (float10)FUN_006de3e0(in_ECX + 0x14,param_2 + 5);
  fVar6 = (float10)(**(code **)(*param_2 + 100))();
  fVar7 = (float10)FUN_00706ad0();
  uVar3 = FUN_006de5a0(auStack_24,(float)fVar5,(float)(fVar7 + (float10)(float)fVar6));
  puVar8 = auStack_18;
  FUN_00706a40(auStack_c);
  piVar4 = (int *)FUN_005c1360(puVar8,uVar3);
  fVar2 = (float)piVar4[2];
  fVar5 = (float10)FUN_00760fd0();
  iVar1 = *piVar4;
  param_1[2] = (float)piVar4[1] * 0.00015258789;
  *param_1 = (float)iVar1 * 0.00015258789;
  param_1[1] = (float)(fVar5 + (float10)fVar2);
  return;
}



// ?GetHandHelpMessageSet@Object@@UAEIXZ @ 0x00706b70

int _GetHandHelpMessageSet_Object__UAEIXZ(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int in_ECX;
  
  iVar1 = _GetDiscipleStateIfInteractedWith_MultiMapFixed__UAEIPAVGInterfaceStatus__PAVVillager___Z
                    (param_1,param_2);
  if ((iVar1 != 4) && (iVar2 = (**(code **)(*param_2 + 0x48))(), iVar2 != 0)) {
    piVar3 = (int *)(**(code **)(*param_2 + 0x48))();
    iVar2 = (**(code **)(*piVar3 + 0x30c))();
    if (iVar2 == in_ECX) {
      return 0xb;
    }
  }
  return iVar1;
}



// ?SetPoisonedResource@Object@@UAEXW4RESOURCE_TYPE@@H@Z @ 0x00706bf0

undefined4 _SetPoisonedResource_Object__UAEXW4RESOURCE_TYPE__H_Z(int param_1,int *param_2)

{
  int iVar1;
  undefined4 extraout_var;
  int iVar2;
  
  iVar1 = _DoCreatureMimicAfterAddingResource_MultiMapFixed__UAE_NW4RESOURCE_TYPE__PAVGInterfaceStatus___Z
                    (param_1,param_2);
  if (iVar1 == 0) {
    if (param_1 != 0) {
      return 0;
    }
    iVar2 = iVar1;
    (**(code **)(*param_2 + 0x1c))(param_2,0);
    FUN_004cb260(param_2,iVar1,extraout_var,iVar2);
  }
  return 1;
}



// ?GetDefaultResource@Object@@UAEHXZ @ 0x00706e80

float10 _GetDefaultResource_Object__UAEHXZ(void)

{
  return (float10)1.5;
}



// ?GetResourceType@Object@@UAE?AW4RESOURCE_TYPE@@XZ @ 0x007071b0

undefined4 _GetResourceType_Object__UAE_AW4RESOURCE_TYPE__XZ(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  if ((*(byte *)(param_1 + 0x24) & 0x40) != 0) {
    iVar1 = FUN_005f56a0(param_1);
    if (iVar1 != 0) {
      iVar1 = *(int *)(iVar1 + 0x24);
      iVar2 = FUN_00527d60();
      if (iVar1 == iVar2) {
        FUN_00586170(6);
      }
    }
  }
  FUN_005ecb70(param_1,param_2);
  return 1;
}



