// Decompiled functions for class: Creature
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetPlayer@Creature@@UAEPAVGPlayer@@XZ @ 0x0045e830

undefined4 _GetPlayer_Creature__UAEPAVGPlayer__XZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x1070);
}



// ?RemoveDance@Creature@@UAEXXZ @ 0x0045e840

void _RemoveDance_Creature__UAEXXZ(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x1074) = 0;
  return;
}



// ?GetSaveType@Creature@@UAEIXZ @ 0x0045e850

undefined4 _GetSaveType_Creature__UAEIXZ(void)

{
  return 0x69;
}



// ?GetDebugText@Creature@@UAEPADXZ @ 0x0045e860

char * _GetDebugText_Creature__UAEPADXZ(void)

{
  return s_Creature__008fe0e0;
}



// ?ToBeDeleted@Creature@@UAEXH@Z @ 0x0045f240

void _ToBeDeleted_Creature__UAEXH_Z(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int *in_ECX;
  undefined4 uVar6;
  undefined1 auStack_200 [256];
  undefined1 auStack_100 [256];
  
  iVar5 = (**(code **)(*in_ECX + 0x1c))();
  if ((iVar5 != 0) && (iVar5 = FUN_005f7f80(), iVar5 != 0)) {
    FUN_005f7f80();
    iVar5 = FUN_00667ed0();
    if ((*(int *)(iVar5 + 0x1bc) != 0) && (in_ECX[0x416] == 0)) {
      FUN_005f7f80();
      iVar5 = FUN_00667ed0();
      FUN_00733e17(auStack_200,s___Scripts_CreatureMind__s_008fe028,*(int *)(iVar5 + 0x1bc) + 4);
      FUN_004c89e0(auStack_200);
      FUN_005f7f80();
      iVar5 = FUN_00667ed0();
      FUN_00733e17(auStack_100,s___Scripts_CreatureMind_Physique__008fe004,
                   *(int *)(iVar5 + 0x1bc) + 4);
      FUN_004c8280(auStack_100);
    }
  }
  FUN_00462ff0();
  iVar5 = (**(code **)(*in_ECX + 0x1c))();
  if (((iVar5 != 0) && (iVar5 = (**(code **)(*in_ECX + 0x1c))(), *(int *)(iVar5 + 0x260) != 0)) &&
     (iVar5 = (**(code **)(*in_ECX + 0x1c))(), *(int *)(*(int *)(iVar5 + 0x260) + 0x30) != 0)) {
    (**(code **)(*in_ECX + 0x1c))();
    _Draw_PlannedMultiMapFixed__QAEXXZ();
  }
  iVar5 = (**(code **)(*in_ECX + 0x1c))();
  if (iVar5 != 0) {
    uVar6 = 0;
    (**(code **)(*in_ECX + 0x1c))(0);
    for (iVar5 = FUN_005f8050(uVar6); iVar5 != 0; iVar5 = FUN_005f8050(iVar5)) {
      FUN_005a6970(in_ECX,0);
      (**(code **)(*in_ECX + 0x1c))(iVar5);
    }
  }
  if ((int *)in_ECX[0x41e] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x41e] + 0xc))(0);
    in_ECX[0x41e] = 0;
  }
  if ((int *)in_ECX[0x41f] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x41f] + 0xc))(0);
    in_ECX[0x41f] = 0;
  }
  if ((int *)in_ECX[0x420] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x420] + 0xc))(0);
    in_ECX[0x420] = 0;
  }
  if ((int *)in_ECX[0x421] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x421] + 0xc))(0);
    in_ECX[0x421] = 0;
  }
  if ((int *)in_ECX[0x422] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x422] + 0xc))(0);
    in_ECX[0x422] = 0;
  }
  FUN_004d5160();
  if ((int *)in_ECX[0x479] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x479] + 0xc))(0);
    in_ECX[0x479] = 0;
  }
  if (in_ECX[0x47b] != 0) {
    FUN_004331c0();
    in_ECX[0x47b] = 0;
  }
  puVar4 = (undefined4 *)0x0;
  puVar1 = DAT_00b81580;
  while (puVar3 = puVar1, puVar2 = puVar4, puVar3 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar3;
    puVar4 = puVar3;
    if ((int *)puVar3[1] == in_ECX) {
      puVar4 = puVar1;
      if (puVar3 != DAT_00b81580) {
        *puVar2 = puVar1;
        puVar4 = DAT_00b81580;
      }
      DAT_00b81580 = puVar4;
      DAT_00b81584 = DAT_00b81584 + -1;
      FUN_007290de(puVar3);
      puVar4 = puVar2;
    }
  }
  if ((int *)in_ECX[0x41d] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x41d] + 0xc))(0);
    in_ECX[0x41d] = 0;
  }
  FUN_0067f9a0();
  _ToBeDeleted__6LivingFi(param_1);
  return;
}



// ?GetDestPos@Creature@@UAEPAUMapCoords@@XZ @ 0x0045f700

int _GetDestPos_Creature__UAEPAUMapCoords__XZ(void)

{
  int in_ECX;
  
  return in_ECX + 0x1214;
}



// ?GetFinalDestPos@Creature@@UAEPAUMapCoords@@PAU2@@Z @ 0x0045f710

void _GetFinalDestPos_Creature__UAEPAUMapCoords__PAU2__Z(undefined4 *param_1)

{
  undefined4 *puVar1;
  int *in_ECX;
  
  puVar1 = (undefined4 *)(**(code **)(*in_ECX + 0x860))();
  *param_1 = *puVar1;
  param_1[1] = puVar1[1];
  param_1[2] = puVar1[2];
  return;
}



// ?ValidToSelectFightThisToMapCoord@Creature@@UAEIPAVGInterfaceStatus@@PBUMapCoords@@@Z @ 0x00460ff0

bool _ValidToSelectFightThisToMapCoord_Creature__UAEIPAVGInterfaceStatus__PBUMapCoords___Z(void)

{
  int iVar1;
  
  iVar1 = FUN_00464dc0();
  return iVar1 != 0;
}



// ?ValidToApplyFightThisToMapCoord@Creature@@UAEIPAVGInterfaceStatus@@PBUMapCoords@@@Z @ 0x00461000

void _ValidToApplyFightThisToMapCoord_Creature__UAEIPAVGInterfaceStatus__PBUMapCoords___Z
               (undefined4 param_1,undefined4 param_2)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x75c))(param_1,param_2);
  return;
}



// ?ValidForLockedSelectProcess@Creature@@UAE_NPAVGInterfaceStatus@@@Z @ 0x00461020

undefined4 _ValidForLockedSelectProcess_Creature__UAE_NPAVGInterfaceStatus___Z(void)

{
  int iVar1;
  int *in_ECX;
  
  if (((*(int *)(in_ECX[10] + 500) != 0xd) && ((*(byte *)((int)in_ECX + 0x25) & 4) == 0)) &&
     ((*(int *)(in_ECX[0x59] + 0xf60) != 9 || (2 < *(uint *)(in_ECX[0x59] + 0xfb4))))) {
    iVar1 = (**(code **)(*in_ECX + 0x1c))();
    if (iVar1 != 0) {
      iVar1 = FUN_004d5000(0);
      if (iVar1 == 0) {
        return 1;
      }
    }
  }
  return 0;
}



// ?NetworkFriendlyStartLockedSelect@Creature@@UAE_NPAVGInterfaceStatus@@@Z @ 0x00461080

undefined4 _NetworkFriendlyStartLockedSelect_Creature__UAE_NPAVGInterfaceStatus___Z(int param_1)

{
  FUN_00461af0();
  *(byte *)(param_1 + 0x24) = *(byte *)(param_1 + 0x24) | 0x20;
  return 1;
}



// ?IsReadyForNetworkUnfriendlyLockedSelect@Creature@@UAEIXZ @ 0x004610a0

bool _IsReadyForNetworkUnfriendlyLockedSelect_Creature__UAEIXZ(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0x3cc) == 0;
}



// ?GetReadyForNetworkUnfriendlyEndLockedSelect@Creature@@UAEIXZ @ 0x004610b0

undefined4 _GetReadyForNetworkUnfriendlyEndLockedSelect_Creature__UAEIXZ(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(*(int *)(in_ECX + 0x160) + 0x58);
  *(undefined4 *)(iVar1 + 0x48c8) = 0;
  *(undefined4 *)(iVar1 + 0x48c4) = 0;
  *(undefined4 *)(iVar1 + 0x48c0) = 0;
  FUN_00469050();
  return 1;
}



// ?IsReadyForNetworkUnfriendlyEndLockedSelect@Creature@@UAEIXZ @ 0x004610e0

undefined4 _IsReadyForNetworkUnfriendlyEndLockedSelect_Creature__UAEIXZ(void)

{
  int iVar1;
  
  iVar1 = FUN_0046bfe0();
  if (iVar1 != 0) {
    iVar1 = FUN_0046cb50();
    if ((iVar1 != 0) && (iVar1 = FUN_0046d620(), iVar1 == 0)) {
      return 0;
    }
    iVar1 = FUN_00469680();
    if (iVar1 == 0) {
      return 1;
    }
  }
  return 0;
}



// ?DestroyedByEffect@Creature@@UAEIPAVGPlayer@@M@Z @ 0x00461140

undefined4 _DestroyedByEffect_Creature__UAEIPAVGPlayer__M_Z(void)

{
  int *in_ECX;
  
  if (in_ECX[0x456] != 0) {
    FUN_00461170();
    return 1;
  }
  (**(code **)(*in_ECX + 0x5b0))(0x3f800000);
  return 1;
}



// ?SetHeadPos@Creature@@UAEXPAUMapCoords@@@Z @ 0x00461240

void _SetHeadPos_Creature__UAEXPAUMapCoords___Z(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_00469c40();
  uVar1 = __ftol();
  *param_1 = uVar1;
  uVar1 = __ftol();
  param_1[1] = uVar1;
  param_1[2] = 0;
  iVar2 = FUN_00469c40();
  param_1[2] = *(undefined4 *)(iVar2 + 4);
  return;
}



// ?GetNearestEdgeOfObject@Creature@@UAEXPAVObject@@@Z @ 0x004619e0

void _GetNearestEdgeOfObject_Creature__UAEXPAVObject___Z(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return;
}



// ?GetMovementDirection@Creature@@UAEXPAULHPoint@@@Z @ 0x00461a90

void _GetMovementDirection_Creature__UAEXPAULHPoint___Z(float *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  
  uVar1 = FUN_006dece0(*(undefined4 *)(*(int *)(*(int *)(in_ECX + 0x160) + 0x58) + 0x84));
  iVar2 = FUN_006de4d0(uVar1,0x41200000);
  param_1[1] = 0.0;
  *param_1 = (float)iVar2;
  iVar2 = FUN_006de4d0(uVar1,0x41200000);
  param_1[2] = (float)iVar2;
  return;
}



// ?GetImpressiveType@Creature@@UAE?AW4IMPRESSIVE_TYPE@@XZ @ 0x00461dc0

undefined4 _GetImpressiveType_Creature__UAE_AW4IMPRESSIVE_TYPE__XZ(void)

{
  int iVar1;
  
  iVar1 = FUN_00461db0();
  return *(undefined4 *)(&DAT_00b8dd2c + iVar1 * 0x10c);
}



// ?IsObjectTurningTooFastForCameraToFollowSmoothly@Creature@@UAEIXZ @ 0x00461de0

undefined4 _IsObjectTurningTooFastForCameraToFollowSmoothly_Creature__UAEIXZ(void)

{
  int in_ECX;
  
  switch(*(undefined4 *)(*(int *)(in_ECX + 0x164) + 0xf60)) {
  case 8:
  case 0x52:
  case 0x58:
  case 0x59:
  case 0x5a:
  case 0x5c:
    return 1;
  default:
    return 0;
  }
}



// ?GetFacingDirection@Creature@@UAEMXZ @ 0x00461e70

float10 _GetFacingDirection_Creature__UAEMXZ(void)

{
  int in_ECX;
  
  return ((float10)*(float *)(*(int *)(*(int *)(in_ECX + 0x160) + 0x58) + 0x84) + (float10)6.2831855
         ) - (float10)2.5;
}



// ?GetFacingPitch@Creature@@UAEMXZ @ 0x00461e90

float10 _GetFacingPitch_Creature__UAEMXZ(void)

{
  int in_ECX;
  
  return (float10)*(float *)(*(int *)(*(int *)(in_ECX + 0x160) + 0x58) + 0x486c);
}



// ?IsScary@Creature@@UAE_NXZ @ 0x00461ea0

undefined4 _IsScary_Creature__UAE_NXZ(void)

{
  int in_ECX;
  
  if (*(float *)(*(int *)(in_ECX + 0x168) + 8) < -0.25) {
    return 1;
  }
  return 0;
}



// ?GetRadius@Creature@@UAEMXZ @ 0x00461ed0

float10 _GetRadius_Creature__UAEMXZ(void)

{
  int in_ECX;
  
  return (float10)*(float *)(*(int *)(*(int *)(in_ECX + 0x160) + 0x58) + 0x5228);
}



// ?GetHeight@Creature@@UAEMXZ @ 0x00461ee0

float10 _GetHeight_Creature__UAEMXZ(void)

{
  int in_ECX;
  
  return (float10)*(float *)(*(int *)(*(int *)(in_ECX + 0x160) + 0x58) + 0x90) * (float10)15.0;
}



// ?SaveObject@Creature@@UAEIAAULHOSFile@@ABUMapCoords@@@Z @ 0x00461f00

int _SaveObject_Creature__UAEIAAULHOSFile__ABUMapCoords___Z(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int *in_ECX;
  char *pcVar7;
  undefined1 auStack_138 [12];
  char acStack_12c [200];
  undefined1 auStack_64 [100];
  
  iVar2 = FUN_0053eb80();
  if ((iVar2 == 0) || (iVar3 = (**(code **)(*in_ECX + 0x1c))(), iVar3 == 0)) {
    return iVar2;
  }
  if (param_2 != 0) {
    FUN_005c13b0(auStack_138,param_2);
  }
  piVar4 = in_ECX + 0x48a;
  if ((char)in_ECX[0x48a] == '\0') {
    piVar4 = (int *)&DAT_008fe790;
  }
  iVar3 = in_ECX[10];
  (**(code **)(*in_ECX + 0x1c))(piVar4);
  uVar5 = FUN_005f7d20();
  iVar3 = (iVar3 + -0xb81ce8) / 0x394;
  uVar6 = FUN_005bf290(auStack_64);
  uVar5 = FUN_006ad590(0x2f,uVar6,iVar3,uVar5);
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



// ?NetworkFriendlyEndLockedSelect@Creature@@UAEIPAVGInterfaceStatus@@@Z @ 0x00462010

undefined4 _NetworkFriendlyEndLockedSelect_Creature__UAEIPAVGInterfaceStatus___Z(int param_1)

{
  FUN_004619d0();
  FUN_004690b0();
  *(ushort *)(param_1 + 0x24) = *(ushort *)(param_1 + 0x24) & 0xffdf;
  return 1;
}



// ?FillInEffectDefenceMultiplier@Creature@@UAEXAAUEffectNumbers@@@Z @ 0x00462b60

void _FillInEffectDefenceMultiplier_Creature__UAEXAAUEffectNumbers___Z(float *param_1)

{
  float fVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  uint uVar4;
  
  uVar4 = 0;
  iVar3 = 0x90 - (int)param_1;
  do {
    *param_1 = *(float *)(*(int *)(in_ECX + 0x28) + iVar3 + (int)param_1);
    if ((uVar4 < 3) || (uVar4 == 4)) {
      iVar2 = FUN_004619d0();
      fVar1 = *(float *)(iVar2 + 0x90);
      if (0.001 <= fVar1) {
        if (2.0 < fVar1) {
          fVar1 = 2.0;
        }
      }
      else {
        fVar1 = 0.001;
      }
      *param_1 = *param_1 / (fVar1 * 1.5 + 1.0);
    }
    uVar4 = uVar4 + 1;
    param_1 = param_1 + 1;
  } while (uVar4 < 7);
  return;
}



// ?ApplyEffect@Creature@@UAEXAAVEffectValues@@H@Z @ 0x00462be0

float10 _ApplyEffect_Creature__UAEXAAVEffectValues__H_Z(int param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  float *pfVar4;
  float *pfVar5;
  undefined4 uVar6;
  float10 fVar7;
  float10 fVar8;
  int unaff_retaddr;
  undefined4 uVar9;
  undefined1 auStack_34 [48];
  float fStack_4;
  
  fVar7 = (float10)(**(code **)(*in_ECX + 0x5d0))(param_1);
  if ((float10)0.0 < fVar7) {
    if (*(int **)(param_1 + 0x28) == in_ECX) {
      return (float10)0.0;
    }
  }
  else if (((*(int **)(param_1 + 0x28) != in_ECX) && (iVar2 = FUN_00464dc0(), iVar2 != 0)) &&
          (iVar2 = *(int *)(param_1 + 0x28), iVar3 = (**(code **)(*in_ECX + 0x1c))(), iVar2 != iVar3
          )) {
    return (float10)0.0;
  }
  iVar2 = FUN_00464dc0();
  if (iVar2 == 0) {
    FUN_004627f0(param_1);
  }
  else if ((DAT_00b859d0 == '\0') && (DAT_00b859d1 == '\0')) {
    FUN_004619d0();
    cVar1 = FUN_004728b0();
    if (cVar1 != '\0') {
      FUN_004fca90(&DAT_0080ae20);
    }
    uVar9 = 0xb8;
    FUN_004619d0(0xb8);
    FUN_0046cff0(uVar9);
    fVar8 = (float10)(**(code **)(*in_ECX + 0x5d4))(param_1);
    if ((float10)0.0 < fVar8) {
      uVar9 = __ftol();
      FUN_004619d0(uVar9);
      FUN_0046a1c0(uVar9);
      iVar2 = FUN_004619d0();
      *(float *)(iVar2 + 0x4aa8) = (float)fVar8 + *(float *)(iVar2 + 0x4aa8);
      iVar2 = FUN_004619d0();
      if (0.0 <= *(float *)(iVar2 + 0x4aa8)) {
        iVar2 = FUN_004619d0();
        if (1.0 < *(float *)(iVar2 + 0x4aa8)) {
          iVar2 = FUN_004619d0();
          *(undefined4 *)(iVar2 + 0x4aa8) = 0x3f800000;
        }
      }
      else {
        iVar2 = FUN_004619d0();
        *(undefined4 *)(iVar2 + 0x4aa8) = 0;
      }
    }
    if (0.0 < (float)fVar7) {
      iVar2 = FUN_004619d0();
      *(float *)(iVar2 + 0x4aa8) = *(float *)(iVar2 + 0x4aa8) - (float)fVar7;
      iVar2 = FUN_004619d0();
      if (*(float *)(iVar2 + 0x4aa8) <= 0.0) {
        iVar2 = FUN_004619d0();
        if (*(int *)(iVar2 + 0x528c) == 0) {
          in_ECX[0x42c] = 1;
          FUN_00461170();
        }
        else {
          iVar2 = FUN_004619d0();
          iVar2 = *(int *)(*(int *)(iVar2 + 0x528c) + 0x4834);
          uVar9 = FUN_004ba200(iVar2,in_ECX);
          uVar6 = 0x27;
          iVar3 = FUN_004619d0();
          if (*(float *)(iVar3 + 0x9c) < -0.5) {
            uVar6 = 0x13;
          }
          FUN_004d1300(0x18,uVar6,uVar9,uVar9,0,0x3f800000);
          FUN_004aba10(auStack_34,1,1);
          *(undefined4 *)(*(int *)(iVar2 + 0x164) + 0x1c14) = 1;
          *(int *)(iVar2 + 0x17c) = *(int *)(iVar2 + 0x17c) + 1;
          *(undefined4 *)(iVar2 + 0x10b0) = 1;
          FUN_004d13a0();
          in_ECX[0x42c] = 1;
          FUN_00461170();
          param_1 = unaff_retaddr;
        }
      }
    }
  }
  fVar7 = (float10)(**(code **)(*in_ECX + 0x5d4))(param_1);
  if ((float10)0.0 < fVar7) {
    uVar9 = __ftol();
    FUN_004619d0(uVar9);
    FUN_0046a1c0(uVar9);
  }
  iVar2 = FUN_007344da(*(undefined4 *)(param_1 + 0x28),0,&GameThing::RTTI_Type_Descriptor,
                       &Creature::RTTI_Type_Descriptor,0);
  if (iVar2 != 0) {
    iVar3 = *(int *)(in_ECX[0x59] + 0x18c3c);
    if ((iVar3 == 0) || (600 < (uint)(*(int *)(DAT_00c22ca4 + 0x201afc) - iVar3))) {
      fStack_4 = 0.0;
      *(undefined4 *)(in_ECX[0x59] + 0x18c3c) = *(undefined4 *)(DAT_00c22ca4 + 0x201afc);
      pfVar4 = (float *)&DAT_00b6e6f8;
      pfVar5 = (float *)(param_1 + 8);
      do {
        if (0.0 < *pfVar5) {
          fStack_4 = *pfVar5 * *pfVar4 + fStack_4;
        }
        pfVar4 = pfVar4 + 0x12;
        pfVar5 = pfVar5 + 1;
      } while (pfVar4 < &DAT_00b6e818);
      FUN_004abfe0(iVar2,fStack_4);
    }
  }
  iVar2 = FUN_00464dc0();
  if (iVar2 != 0) {
    return (float10)1.0;
  }
  fVar7 = (float10)_ApplyEffect_Object__UAEXPBXPAVEffectValues___Z(param_1,unaff_retaddr);
  return fVar7;
}



// ?ApplySingleEffect@Creature@@UAEXW4EFFECT_TYPE@@MPAVGameThing@@PBUMapCoords@@@Z @ 0x00462f80

void _ApplySingleEffect_Creature__UAEXW4EFFECT_TYPE__MPAVGameThing__PBUMapCoords___Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  _ApplySingleEffect_Object__UAEXW4EFFECT_TYPE__MPAVGameThing__PBUMapCoords___Z
            (param_1,param_2,param_3,param_4);
  return;
}



// ?GetCitadel@Creature@@UAEPAVCitadel@@XZ @ 0x004630d0

undefined4 _GetCitadel_Creature__UAEPAVCitadel__XZ(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x1070) != 0) {
    return *(undefined4 *)(*(int *)(in_ECX + 0x1070) + 0x260);
  }
  return 0;
}



// ?IsDominantCreature@Creature@@UAEIPAVCreature@@@Z @ 0x004630f0

bool _IsDominantCreature_Creature__UAEIPAVCreature___Z(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int in_ECX;
  uint uVar4;
  
  uVar2 = *(uint *)(*(int *)(in_ECX + 0x160) + 8);
  uVar3 = *(uint *)(*(int *)(param_1 + 0x160) + 8);
  uVar1 = uVar2 - uVar3;
  uVar4 = (int)uVar1 >> 0x1f;
  if (10 < (uVar1 ^ uVar4) - uVar4) {
    return uVar3 < uVar2;
  }
  uVar2 = FUN_00430360();
  uVar3 = FUN_00430360();
  return uVar2 < uVar3;
}



// ?IsReadyForNewScriptAction@Creature@@UAEIXZ @ 0x004631a0

bool _IsReadyForNewScriptAction_Creature__UAEIXZ(void)

{
  int in_ECX;
  
  return *(int *)(*(int *)(*(int *)(in_ECX + 0x164) + 0xfb4) * 0x60 + 0xfd8 +
                 *(int *)(in_ECX + 0x164)) == 0x40;
}



// ?GetBoundingSphere@Creature@@UAEXAAULHPoint@@AAM@Z @ 0x00463620

void _GetBoundingSphere_Creature__UAEXAAULHPoint__AAM_Z(undefined4 param_1,undefined4 param_2)

{
  FUN_00468280(param_1,param_2);
  return;
}



// ?ReactToPhysicsImpact@Creature@@UAEXPAVPhysicsObject@@_N@Z @ 0x00463640

void _ReactToPhysicsImpact_Creature__UAEXPAVPhysicsObject___N_Z(float param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *in_ECX;
  float10 fVar6;
  undefined1 auStack_40 [44];
  undefined4 uStack_14;
  undefined4 uStack_10;
  float fStack_c;
  
  iVar5 = (int)param_1;
  iVar4 = *(int *)((int)param_1 + 0x20);
  if (iVar4 != 0) {
    if ((*(int **)(iVar4 + 0x18) != (int *)0x0) &&
       (iVar2 = (**(code **)(**(int **)(iVar4 + 0x18) + 0x3b4))(0), iVar2 != 0)) {
      return;
    }
    if ((*(int **)(iVar4 + 0x18) != (int *)0x0) &&
       (iVar2 = (**(code **)(**(int **)(iVar4 + 0x18) + 0x3b4))(0), iVar2 != 0)) {
      return;
    }
    FUN_00468470(iVar4 + 200,iVar5 + 0xc);
    if ((*(byte *)((int)in_ECX + 0x25) & 4) != 0) {
      param_1 = (float)(DAT_00c22ca4 + 0x18 + (uint)*(byte *)(DAT_00c22ca4 + 0x201b15) * 0x278);
      iVar2 = (**(code **)(*in_ECX + 0x1c))();
      if ((float)iVar2 == param_1) {
        return;
      }
    }
    uVar3 = FUN_005f6180();
    FUN_004fc540(3,*(undefined4 *)(iVar4 + 0x18),uVar3);
    fVar6 = (float10)FUN_00467150(*(undefined4 *)(iVar5 + 8));
    param_1 = (float)fVar6;
    FUN_004fca90(&param_1);
    if (0.005 < param_1) {
      uStack_14 = __ftol();
      uStack_10 = __ftol();
      fStack_c = 0.0;
      __ftol();
      __ftol();
      fVar1 = *(float *)(iVar4 + 0xcc);
      fVar6 = (float10)FUN_00760fd0();
      DAT_00b859d1 = 1;
      fStack_c = (float)((float10)fVar1 - fVar6);
      (**(code **)(*in_ECX + 0x5cc))(auStack_40,0);
      DAT_00b859d1 = 0;
      iVar4 = (**(code **)(*in_ECX + 0x1c))();
      iVar5 = FUN_005f6180();
      if (iVar5 == iVar4) {
        FUN_004c2a80(-param_1);
      }
      FUN_004c06c0(0x12,param_1);
      FUN_004c06c0(9,param_1);
    }
    FUN_00430270();
  }
  return;
}



// ?SetUpPhysOb@Creature@@UAEXPAUPhysOb@@@Z @ 0x00463830

void _SetUpPhysOb_Creature__UAEXPAUPhysOb___Z(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int *in_ECX;
  int iVar7;
  undefined4 *puVar8;
  undefined4 uVar9;
  
  iVar3 = param_1;
  iVar2 = *(int *)(in_ECX[0x58] + 0x58);
  FUN_00468280(param_1 + 0xa0,param_1 + 0x150);
  uVar9 = 0;
  iVar4 = (**(code **)(*in_ECX + 0x788))(0);
  FUN_00759e40(0x447a0000,&DAT_00be7740 + iVar4 * 6,uVar9);
  *(undefined4 *)(param_1 + 0x154) = 0;
  *(undefined4 *)(param_1 + 0x160) = 0;
  *(undefined4 *)(param_1 + 0x164) = 0;
  iVar4 = *(int *)(iVar2 + 0x47b8);
  *(int *)(param_1 + 0x154) = iVar4;
  iVar4 = FUN_00746d70(iVar4 * 0x50,s_C__dev_black_Creature_cpp_008fe0a0,0xcf7);
  if (iVar4 == 0) {
    iVar4 = 0;
  }
  iVar7 = 0;
  *(int *)(param_1 + 0x15c) = iVar4;
  if (0 < *(int *)(param_1 + 0x154)) {
    puVar5 = (undefined4 *)(iVar4 + 0x14);
    do {
      puVar5[1] = 0;
      *puVar5 = 0;
      puVar5[-1] = 0;
      puVar5 = puVar5 + 0x14;
      iVar7 = iVar7 + 1;
    } while (iVar7 < *(int *)(param_1 + 0x154));
  }
  iVar4 = FUN_0046b9f0();
  *(int *)(param_1 + 0x168) = iVar4;
  *(undefined4 *)(param_1 + 0x16c) = *(undefined4 *)(iVar2 + 0xb4 + *(int *)(iVar2 + 0x98) * 4);
  FUN_00759eb0();
  piVar1 = (int *)(param_1 + 0x154);
  puVar5 = *(undefined4 **)(param_1 + 0x15c);
  param_1 = 0;
  if (*piVar1 < 1) {
    *(int *)(iVar2 + 0x57ac) = iVar3;
    return;
  }
  puVar6 = puVar5 + 10;
  puVar8 = (undefined4 *)(iVar4 + 0x3c);
  do {
    puVar6[3] = *puVar8;
    puVar6[4] = puVar8[1];
    puVar6[5] = puVar8[2];
    *puVar6 = *puVar8;
    puVar6[1] = puVar8[1];
    puVar6[2] = puVar8[2];
    *puVar5 = 0;
    puVar6[-1] = 0;
    puVar5 = puVar5 + 0x14;
    puVar6 = puVar6 + 0x14;
    puVar8 = puVar8 + 0x1e;
    param_1 = param_1 + 1;
  } while (param_1 < *(int *)(iVar3 + 0x154));
  *(int *)(iVar2 + 0x57ac) = iVar3;
  return;
}



// ?IsMoving@Creature@@UBE_NXZ @ 0x00463a70

void _IsMoving_Creature__UBE_NXZ(void)

{
  FUN_0046cb80();
  return;
}



// ?MoveMapObject@Creature@@UAEHPBUMapCoords@@@Z @ 0x00463a80

undefined4 _MoveMapObject_Creature__UAEHPBUMapCoords___Z(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  FUN_004b56d0(in_ECX);
  FUN_004b5850(in_ECX);
  FUN_004b3e60();
  if (*(int *)(in_ECX + 0x10cc) != 0) {
    return 6;
  }
  uVar1 = _MoveMapObject_Object__UAEIUMapCoords___Z(param_1);
  return uVar1;
}



// ?InterfaceGiveObject@Creature@@UAEIPAVGInterfaceStatus@@PAVObject@@@Z @ 0x00463f30

undefined4 _InterfaceGiveObject_Creature__UAEIPAVGInterfaceStatus__PAVObject___Z(void)

{
  return 0x16;
}



// ?InterfaceValidToGiveObject@Creature@@UAEIPAVGInterfaceStatus@@PAVObject@@@Z @ 0x00463f40

undefined4
_InterfaceValidToGiveObject_Creature__UAEIPAVGInterfaceStatus__PAVObject___Z
          (int *param_1,int *param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  
  iVar2 = (**(code **)(*in_ECX + 0x1c))();
  if (((iVar2 != 0) && (param_1 != (int *)0x0)) &&
     (iVar3 = (**(code **)(*param_1 + 0x1c))(), iVar3 != 0)) {
    if ((iVar2 != iVar3) && (cVar1 = FUN_005fa4f0(iVar3), cVar1 == '\0')) {
      return 0;
    }
    iVar2 = (**(code **)(*param_2 + 0x4c4))();
    if ((iVar2 == 0) && (*(int *)(in_ECX[10] + 500) != 0xd)) {
      iVar2 = FUN_004c4e00(in_ECX);
      if (iVar2 != 0) {
        return 1;
      }
      FUN_004b0770(0x25,7,0,0,0);
    }
  }
  return 0;
}



// ?GetImpressiveIntensity@Creature@@UAEMW4IMPRESSIVE_TYPE@@@Z @ 0x00464d50

void _GetImpressiveIntensity_Creature__UAEMW4IMPRESSIVE_TYPE___Z(void)

{
  FUN_004cf970();
  return;
}



// ?SetScale@Creature@@UAEXM@Z @ 0x00464d60

void _SetScale_Creature__UAEXM_Z(undefined4 param_1)

{
  int in_ECX;
  undefined4 unaff_retaddr;
  
  (**(code **)(**(int **)(*(int *)(in_ECX + 0x160) + 0x58) + 8))(param_1);
  *(undefined4 *)(*(int *)(in_ECX + 0x160) + 0x6c) = unaff_retaddr;
  return;
}



// ?GetScale@Creature@@UAEMXZ @ 0x00464d90

void _GetScale_Creature__UAEMXZ(void)

{
  FUN_004cf970();
  return;
}



// ?GetAge@Creature@@UAEIXZ @ 0x00464db0

void _GetAge_Creature__UAEIXZ(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(*(int *)(in_ECX + 0x160) + 8) = param_1;
  return;
}



// ?GetMaxAlignmentChangePerGameTurn@Creature@@UAEMXZ @ 0x00464de0

float10 _GetMaxAlignmentChangePerGameTurn_Creature__UAEMXZ(void)

{
  int in_ECX;
  
  return (float10)*(float *)(*(int *)(in_ECX + 0x28) + 0x348);
}



// ?GetImpressiveValue@Creature@@UAEMPAVLiving@@PAVReaction@@@Z @ 0x00464df0

float10 _GetImpressiveValue_Creature__UAEMPAVLiving__PAVReaction___Z
                  (int *param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  
  piVar1 = param_1;
  iVar2 = FUN_00461db0();
  fVar4 = (float10)FUN_0067fac0(param_1);
  iVar3 = *param_1;
  param_1 = (int *)(float)(fVar4 * (float10)*(float *)(&DAT_00b8dd30 + iVar2 * 0x10c));
  iVar3 = (**(code **)(iVar3 + 0x48))();
  if (iVar3 != 0) {
    iVar2 = FUN_006d58d0(in_ECX);
    if (iVar2 == 0) {
      param_1 = *(int **)(*(int *)(iVar3 + 0x28) + 0x154);
    }
  }
  fVar4 = (float10)FUN_006de0a0(piVar1 + 5,in_ECX + 5);
  iVar3 = FUN_0067f950();
  fVar4 = (float10)FUN_00431440((float)fVar4,*(undefined4 *)(iVar3 + 0x2c));
  fVar5 = (float10)(**(code **)(*in_ECX + 0x128))();
  fVar6 = (float10)FUN_0053eb20(param_2);
  fVar7 = (float10)FUN_004670e0();
  return fVar7 * (float10)(float)fVar6 * (float10)(float)fVar5 * (float10)(float)fVar4 *
         (float10)(float)param_1 * (float10)DAT_00c3b394;
}



// ?GetRunningSpeedInMetres@Creature@@UAEMXZ @ 0x00466370

float10 _GetRunningSpeedInMetres_Creature__UAEMXZ(void)

{
  int in_ECX;
  
  return (float10)*(float *)(*(int *)(in_ECX + 0x160) + 0x40);
}



// ?GetDefaultSpeedInMetres@Creature@@UAEMXZ @ 0x00466380

float10 _GetDefaultSpeedInMetres_Creature__UAEMXZ(void)

{
  int in_ECX;
  
  return (float10)*(float *)(*(int *)(in_ECX + 0x160) + 0x3c);
}



// ?GetWeight@Creature@@UAEMXZ @ 0x004668b0

void _GetWeight_Creature__UAEMXZ(void)

{
  FUN_004619d0();
  FUN_00468430();
  return;
}



// ?SetControlledByScript@Creature@@UAEXH@Z @ 0x00466e10

void _SetControlledByScript_Creature__UAEXH_Z(byte param_1)

{
  int in_ECX;
  
  *(ushort *)(in_ECX + 0x24) = (param_1 & 1) << 10 | *(ushort *)(in_ECX + 0x24) & 0xfbff;
  return;
}



// ?CreatureMustAvoid@Creature@@UAE_NPAVCreature@@@Z @ 0x00467000

undefined4 _CreatureMustAvoid_Creature__UAE_NPAVCreature___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  if ((param_1 != 0) && (param_1 != in_ECX)) {
    iVar1 = FUN_004619d0();
    switch(*(undefined4 *)(*(int *)(iVar1 + 0x5198) + 0x64054)) {
    case 0:
    case 1:
    case 2:
      return 1;
    }
  }
  return 0;
}



// ?AddToRoutePlan@Creature@@UAEXPAURPHolder@@PAVCreature@@HP6AXHUPoint2D@@MH@Z@Z @ 0x00467050

void _AddToRoutePlan_Creature__UAEXPAURPHolder__PAVCreature__HP6AXHUPoint2D__MH_Z_Z
               (int param_1,undefined4 param_2,undefined4 param_3,code *param_4)

{
  float fVar1;
  int iVar2;
  int *in_ECX;
  float10 fVar3;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  fVar3 = (float10)(**(code **)(*in_ECX + 100))();
  fVar1 = *(float *)(param_1 + 0x50020);
  iVar2 = FUN_004619d0();
  uStack_4 = *(undefined4 *)(iVar2 + 0x80);
  uStack_8 = *(undefined4 *)(iVar2 + 0x78);
  if (param_4 != (code *)0x0) {
    FUN_005c9250(&uStack_8);
    (*param_4)();
    return;
  }
  FUN_007903c0(in_ECX,&uStack_8,(float)((fVar3 + (float10)fVar1) * (float10)1.15),param_3);
  return;
}



// ?SetSpeedInMetres@Creature@@UAEXMH@Z @ 0x00467360

void _SetSpeedInMetres_Creature__UAEXMH_Z(undefined4 param_1)

{
  FUN_004683d0(param_1);
  return;
}



// ?GetQueryFirstEnumText@Creature@@UAE?AW4HELP_TEXT@@XZ @ 0x00467440

int _GetQueryFirstEnumText_Creature__UAE_AW4HELP_TEXT__XZ(void)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  int *in_ECX;
  
  iVar3 = _GetQueryFirstEnumText_Object__UAE_AW4HELP_TEXT__XZ();
  if ((*(int *)(in_ECX[10] + 500) != 0xc) && (*(int *)(in_ECX[10] + 500) != 0xd)) {
    bVar2 = *(byte *)(DAT_00c22ca4 + 0x201b15);
    iVar1 = DAT_00c22ca4 + 0x18;
    iVar4 = (**(code **)(*in_ECX + 0x1c))();
    if (iVar4 != iVar1 + (uint)bVar2 * 0x278) {
      iVar3 = iVar3 + 1;
    }
  }
  return iVar3;
}



// ?ReduceLife@Creature@@UAEXMPAVGPlayer@@@Z @ 0x00467840

void _ReduceLife_Creature__UAEXMPAVGPlayer___Z(float param_1,undefined4 param_2)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  undefined4 uVar5;
  undefined1 auStack_30 [48];
  
  iVar2 = FUN_004619d0();
  if ((iVar2 != 0) && (*(int *)(iVar2 + 0x528c) != 0)) {
    fVar1 = *(float *)(iVar2 + 0x4aa8) - param_1;
    *(float *)(iVar2 + 0x4aa8) = fVar1;
    if (fVar1 < 0.0) {
      fVar1 = 0.0;
    }
    *(float *)(iVar2 + 0x4aa8) = fVar1;
    if (fVar1 <= 0.0) {
      iVar2 = *(int *)(*(int *)(iVar2 + 0x528c) + 0x4834);
      uVar3 = FUN_004ba200(iVar2,in_ECX);
      uVar5 = 0x27;
      iVar4 = FUN_004619d0();
      if (*(float *)(iVar4 + 0x9c) < -0.5) {
        uVar5 = 0x13;
      }
      FUN_004d1300(0x18,uVar5,uVar3,uVar3,0,0x3f800000);
      FUN_004aba10(auStack_30,1,1);
      *(undefined4 *)(*(int *)(iVar2 + 0x164) + 0x1c14) = 1;
      *(int *)(iVar2 + 0x17c) = *(int *)(iVar2 + 0x17c) + 1;
      *(undefined4 *)(iVar2 + 0x10b0) = 1;
      FUN_004d13a0();
      *(undefined4 *)(in_ECX + 0x10b0) = 1;
      FUN_00461170();
    }
  }
  _ReduceLife_Object__UAEMMPAVGPlayer___Z(param_1,param_2);
  return;
}



// ?IncreaseLife@Creature@@UAEXM@Z @ 0x00467960

void _IncreaseLife_Creature__UAEXM_Z(float param_1)

{
  float fVar1;
  int iVar2;
  
  iVar2 = FUN_004619d0();
  if ((iVar2 != 0) && (*(int *)(iVar2 + 0x528c) != 0)) {
    fVar1 = param_1 + *(float *)(iVar2 + 0x4aa8);
    *(float *)(iVar2 + 0x4aa8) = fVar1;
    if (1.0 < fVar1) {
      fVar1 = 1.0;
    }
    *(float *)(iVar2 + 0x4aa8) = fVar1;
  }
  _IncreaseLife_Object__UAEXM_Z(param_1);
  return;
}



// ?SetHeight@Creature@@UAEXM@Z @ 0x004679c0

void _SetHeight_Creature__UAEXM_Z(float param_1)

{
  int iVar1;
  int in_ECX;
  
  *(float *)(*(int *)(in_ECX + 0x160) + 0x6c) = param_1 * 0.06666667;
  iVar1 = FUN_004619d0();
  *(float *)(iVar1 + 0x90) = param_1 * 0.06666667;
  return;
}



// ?FightThisToObject@Creature@@UAEIPAVGInterfaceStatus@@PAVObject@@@Z @ 0x004acea0

void _FightThisToObject_Creature__UAEIPAVGInterfaceStatus__PAVObject___Z
               (undefined4 param_1,undefined4 param_2)

{
  FUN_004aceb0(param_2);
  return;
}



// ?SelectFightThisToMapCoord@Creature@@UAEIPAVGInterfaceStatus@@PBUMapCoords@@@Z @ 0x004ad320

undefined4
_SelectFightThisToMapCoord_Creature__UAEIPAVGInterfaceStatus__PBUMapCoords___Z
          (undefined4 param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar2 = FUN_00464dc0();
  if (iVar2 == 0) {
    return 0;
  }
  fVar1 = (float)param_2[2];
  fVar3 = (float10)FUN_00760fd0();
  fStack_8 = (float)(fVar3 + (float10)fVar1);
  fStack_c = (float)*param_2 * 0.00015258789;
  fStack_4 = (float)param_2[1] * 0.00015258789;
  FUN_00471ee0(&fStack_c,1);
  return 1;
}



// ?ApplyFightThisToMapCoord@Creature@@UAEIPAVGInterfaceStatus@@PBUMapCoords@@@Z @ 0x004ad390

undefined4
_ApplyFightThisToMapCoord_Creature__UAEIPAVGInterfaceStatus__PBUMapCoords___Z
          (undefined4 param_1,int *param_2)

{
  float fVar1;
  int iVar2;
  float10 fVar3;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar2 = FUN_00464dc0();
  if (iVar2 == 0) {
    return 0;
  }
  fVar1 = (float)param_2[2];
  fVar3 = (float10)FUN_00760fd0();
  fStack_8 = (float)(fVar3 + (float10)fVar1);
  fStack_c = (float)*param_2 * 0.00015258789;
  fStack_4 = (float)param_2[1] * 0.00015258789;
  FUN_00471ee0(&fStack_c,0);
  return 1;
}



// ?GetHowMuchCreatureWantsToLookAtMe@Creature@@UAEMXZ @ 0x004b5340

float10 _GetHowMuchCreatureWantsToLookAtMe_Creature__UAEMXZ(void)

{
  return (float10)0.85;
}



// ?CanBeStompedOnByCreature@Creature@@UAEIPAVCreature@@@Z @ 0x004c5110

undefined4 _CanBeStompedOnByCreature_Creature__UAEIPAVCreature___Z(int *param_1)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  float10 fVar3;
  
  fVar2 = (float10)(**(code **)(*param_1 + 0x42c))();
  fVar3 = (float10)(**(code **)(*in_ECX + 0x42c))();
  iVar1 = _CanBeStompedOnByCreature_Object__UAE_NPAVCreature___Z(param_1);
  if ((iVar1 != 0) &&
     ((4.0 < (float)((float10)(float)fVar2 / fVar3) ||
      (*(int *)(&DAT_00b8de14 + *(int *)(in_ECX[0x59] + 0xf60) * 0x10c) != 0)))) {
    return 1;
  }
  return 0;
}



// ?CanBeKissedByCreature@Creature@@UAEIPAVCreature@@@Z @ 0x004c53b0

void _CanBeKissedByCreature_Creature__UAEIPAVCreature___Z(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_004619d0();
  FUN_004619d0(uVar1);
  FUN_00469280(uVar1);
  return;
}



// ?IsCreatureNotTooNear@Creature@@UAE_NPAVCreature@@@Z @ 0x004c5520

undefined4 _IsCreatureNotTooNear_Creature__UAE_NPAVCreature___Z(int *param_1)

{
  int *in_ECX;
  float10 fVar1;
  float10 fVar2;
  float10 fVar3;
  
  fVar1 = (float10)FUN_006de0a0(param_1 + 5,in_ECX + 5);
  fVar2 = (float10)(**(code **)(*param_1 + 0x42c))();
  fVar3 = (float10)(**(code **)(*in_ECX + 0x42c))();
  if (fVar3 + (float10)(float)fVar2 + fVar3 + (float10)(float)fVar2 < (float10)(float)fVar1) {
    return 1;
  }
  return 0;
}



// ?CanBeAttackedByCreature@Creature@@UAEIPAVCreature@@@Z @ 0x004c56c0

undefined4 _CanBeAttackedByCreature_Creature__UAEIPAVCreature___Z(int *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int *in_ECX;
  
  if (param_1 != (int *)0x0) {
    for (puVar1 = (undefined4 *)param_1[0xf4]; puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      if ((int *)puVar1[1] == in_ECX) {
        return 0;
      }
    }
  }
  for (puVar1 = (undefined4 *)in_ECX[0xf4]; puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    if ((int *)puVar1[1] == param_1) {
      return 0;
    }
  }
  iVar2 = (**(code **)(*in_ECX + 0xaf0))();
  if (((iVar2 == 0) && (*(int *)(in_ECX[10] + 0xc4) != 0)) && (param_1 != in_ECX)) {
    return 1;
  }
  return 0;
}



// ?IsActivityObjectWhichAngerAppliesTo@Creature@@UAE_NPAVCreature@@@Z @ 0x004c5730

void _IsActivityObjectWhichAngerAppliesTo_Creature__UAE_NPAVCreature___Z(undefined4 param_1)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x234))(param_1);
  return;
}



// ?IsCreatureAvailableForJointActivity@Creature@@UAEIPAVCreature@@@Z @ 0x004c5850

bool _IsCreatureAvailableForJointActivity_Creature__UAEIPAVCreature___Z(void)

{
  int in_ECX;
  
  return *(int *)(*(int *)(in_ECX + 0x164) + 0x1be8) == 0;
}



// ?IsCreatureNotAvailableForJointActivity@Creature@@UAEIPAVCreature@@@Z @ 0x004c5870

undefined4 _IsCreatureNotAvailableForJointActivity_Creature__UAEIPAVCreature___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(*(int *)(in_ECX + 0x164) + 0x1be8);
  if ((iVar1 != 0) && (iVar1 != param_1)) {
    return 1;
  }
  return 0;
}



// ?IsCreatureWhoSeemsFriendly@Creature@@UAEIPAVCreature@@@Z @ 0x004c59e0

undefined4 _IsCreatureWhoSeemsFriendly_Creature__UAEIPAVCreature___Z(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined4 in_ECX;
  undefined1 *puVar4;
  undefined1 auStack_150 [164];
  undefined4 uStack_ac;
  undefined1 auStack_a8 [164];
  undefined4 uStack_4;
  
  uStack_ac = 0;
  uStack_4 = 0;
  uVar1 = FUN_004ba200(in_ECX,param_1);
  iVar2 = FUN_004ac4e0(uVar1,auStack_150);
  puVar4 = auStack_a8;
  uVar1 = FUN_004ba200(param_1,in_ECX);
  iVar3 = FUN_004ac4e0(uVar1,puVar4);
  if (((iVar2 != 2) && (iVar2 != 5)) && (iVar3 != 2)) {
    return 1;
  }
  return 0;
}



// ?Save@Creature@@UAEIAAVGameOSFile@@@Z @ 0x004c6170

undefined4 _Save_Creature__UAEIAAVGameOSFile___Z(int param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined1 uVar3;
  int iVar4;
  char cVar5;
  int *in_ECX;
  int iVar6;
  undefined4 uVar7;
  int iStack_228;
  int iStack_224;
  uint uStack_220;
  uint uStack_21c;
  uint uStack_218;
  uint uStack_214;
  uint uStack_210;
  uint uStack_20c;
  uint uStack_208;
  undefined1 auStack_204 [256];
  undefined1 auStack_104 [260];
  
  iVar4 = _Save_Living__UAEIAAVGameOSFile___Z(param_1);
  if (iVar4 == 0) {
    return 0;
  }
  if (DAT_00b19ac8 != 0) {
    iVar4 = FUN_0072be90(&DAT_0080f3d0,4,0);
    if (iVar4 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(int *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + 0x24;
  }
  uStack_208 = (uint)(*(int *)(DAT_00c22ca4 + 0x201ae4) == 1);
  if (DAT_00b19ac8 != 0) {
    iVar4 = FUN_0072be90(&uStack_208,4,0);
    if (iVar4 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (uStack_208 & 0xff) + 4;
  }
  cVar5 = '\0';
  for (puVar2 = DAT_00b81580; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
    if ((int *)puVar2[1] == in_ECX) goto LAB_004c6241;
    cVar5 = cVar5 + '\x01';
  }
  cVar5 = -1;
LAB_004c6241:
  uStack_220 = CONCAT31(uStack_220._1_3_,cVar5);
  if (DAT_00b19ac8 != 0) {
    iVar4 = FUN_0072be90(&uStack_220,1,0);
    if (iVar4 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (uStack_220 & 0xff) + 1;
  }
  iVar4 = (**(code **)(*in_ECX + 0x1c))();
  if (iVar4 == 0) {
    uStack_21c = CONCAT31(uStack_21c._1_3_,0xff);
  }
  else {
    (**(code **)(*in_ECX + 0x1c))();
    uVar3 = FUN_005f7d20();
    uStack_21c = CONCAT31(uStack_21c._1_3_,uVar3);
  }
  if (DAT_00b19ac8 != 0) {
    iVar4 = FUN_0072be90(&uStack_21c,1,0);
    if (iVar4 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (uStack_21c & 0xff) + 1;
  }
  FUN_00715bb0(auStack_204);
  FUN_00733e17(auStack_204,s__s__i_00b0e084,auStack_204,DAT_00d26950);
  if ((0xe < DAT_00d26950) && (DAT_00d26950 < 0x12)) {
    FUN_00733e17(auStack_204,s__s__i_00b0e084,auStack_204,*(undefined4 *)(DAT_00c22ca4 + 0x201ac4));
  }
  FUN_00733e17(auStack_104,s__s_SavedCreature_d_00b0e070,auStack_204,uStack_220 & 0xff);
  FUN_004c89e0(auStack_104);
  iVar4 = 0;
  do {
    FUN_005327b0(in_ECX[0xdc] + 4 + iVar4);
    iVar4 = iVar4 + 0x18;
  } while (iVar4 < 0x180);
  iVar4 = in_ECX[0xdc];
  if (DAT_00b19ac8 != 0) {
    iStack_224 = *(int *)(iVar4 + 0x18c);
    FUN_0066ee00(&iStack_224);
    iStack_228 = 0;
    if (0 < iStack_224) {
      iVar6 = 0;
      do {
        FUN_00532a20(iVar6 + *(int *)(iVar4 + 0x184));
        if (DAT_00b19ac8 == 0) goto LAB_004c6510;
        iStack_228 = iStack_228 + 1;
        iVar6 = iVar6 + 0xc;
      } while (iStack_228 < iStack_224);
    }
    if (DAT_00b19ac8 != 0) {
      iVar4 = in_ECX[0x59];
      iVar6 = FUN_0072be90((byte *)(iVar4 + 0x20ce4),4,0);
      if (iVar6 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(iVar4 + 0x20ce4) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar4 = FUN_0072be90(in_ECX + 0xdd,4,0);
        if (iVar4 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xdd) + 4;
        if (DAT_00b19ac8 != 0) {
          iVar4 = FUN_0072be90(in_ECX + 0xde,4,0);
          if (iVar4 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xde) + 4;
          if (DAT_00b19ac8 != 0) {
            iVar4 = FUN_0072be90(in_ECX + 0xdf,1,0);
            if (iVar4 == 3) {
              DAT_00b19ac8 = 0;
            }
            *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xdf) + 1;
          }
        }
      }
    }
  }
LAB_004c6510:
  if (*(int *)(in_ECX[0xdc] + 0xb0) == 0) {
    in_ECX[0x4a9] = 0;
    in_ECX[0x4a8] = 0;
    in_ECX[0x4a7] = 0;
  }
  if (DAT_00b19ac8 != 0) {
    iVar4 = FUN_0072be90(in_ECX + 0x4a6,1,0);
    if (iVar4 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x4a6) + 1;
    if (DAT_00b19ac8 != 0) {
      iVar4 = FUN_0072be90(in_ECX + 0x4a7,4,0);
      if (iVar4 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x4a7) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar4 = FUN_0072be90(in_ECX + 0x4a8,4,0);
        if (iVar4 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x4a8) + 4;
        if (DAT_00b19ac8 != 0) {
          iVar4 = FUN_0072be90(in_ECX + 0x4a9,4,0);
          if (iVar4 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x4a9) + 4;
          if (DAT_00b19ac8 != 0) {
            iVar4 = FUN_0072be90(in_ECX + 0x4aa,4,0);
            if (iVar4 == 3) {
              DAT_00b19ac8 = 0;
            }
            *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x4aa) + 4;
            if (DAT_00b19ac8 != 0) {
              iVar4 = FUN_0072be90(in_ECX + 0x4ab,4,0);
              if (iVar4 == 3) {
                DAT_00b19ac8 = 0;
              }
              *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x4ab) + 4
              ;
            }
          }
        }
      }
    }
  }
  FUN_00531bc0(in_ECX[0x41e]);
  FUN_00531bc0(in_ECX[0x421]);
  FUN_00531bc0(in_ECX[0x422]);
  FUN_00531bc0(in_ECX[0x41f]);
  FUN_00531bc0(in_ECX[0x420]);
  if (DAT_00b19ac8 != 0) {
    iVar4 = FUN_0072be90(in_ECX + 0x476,0xc,0);
    if (iVar4 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x476) + 0xc;
  }
  FUN_00531bc0(in_ECX[0x479]);
  FUN_00531bc0(in_ECX[0x47a]);
  if (DAT_00b19ac8 != 0) {
    iVar4 = FUN_0072be90(in_ECX + 0x47c,1,0);
    if (iVar4 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x47c) + 1;
  }
  FUN_00531bc0(in_ECX[0x428]);
  if (DAT_00b19ac8 != 0) {
    iVar4 = FUN_0072be90(in_ECX + 0x480,0xc,0);
    if (iVar4 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x480) + 0xc;
  }
  iVar4 = FUN_004619d0();
  if (DAT_00b19ac8 != 0) {
    iVar6 = FUN_0072be90((byte *)(iVar4 + 0x4aa8),4,0);
    if (iVar6 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(iVar4 + 0x4aa8) + 4;
  }
  uStack_218 = FUN_00466e60();
  if (DAT_00b19ac8 != 0) {
    iVar4 = FUN_0072be90(&uStack_218,4,0);
    if (iVar4 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (uStack_218 & 0xff) + 4;
    if (DAT_00b19ac8 != 0) {
      iStack_228 = in_ECX[0x425];
      iVar4 = 0;
      FUN_0066ee00(in_ECX + 0x425);
      for (puVar2 = (undefined4 *)in_ECX[0x424]; puVar2 != (undefined4 *)0x0;
          puVar2 = (undefined4 *)*puVar2) {
        iVar4 = iVar4 + 1;
        if (iStack_228 < iVar4) goto LAB_004c689d;
        if (DAT_00b19ac8 == 0) goto LAB_004c68a7;
        FUN_00531bc0(puVar2[1]);
      }
      if ((DAT_00b19ac8 != 0) && (iVar4 != iStack_228)) {
LAB_004c689d:
        DAT_00b19ac8 = 0;
      }
    }
  }
LAB_004c68a7:
  FUN_00531bc0(in_ECX[0x41d]);
  if (DAT_00b19ac8 != 0) {
    iVar4 = FUN_0072be90(in_ECX + 0x456,4,0);
    if (iVar4 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x456) + 4;
  }
  uStack_20c = *(uint *)(in_ECX[0x58] + 0xc);
  if (DAT_00b19ac8 != 0) {
    iVar4 = FUN_0072be90(&uStack_20c,4,0);
    if (iVar4 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (uStack_20c & 0xff) + 4;
    if (DAT_00b19ac8 != 0) {
      iVar4 = in_ECX[0x58];
      iVar6 = FUN_0072be90((byte *)(iVar4 + 0x6c),4,0);
      if (iVar6 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(iVar4 + 0x6c) + 4;
    }
  }
  uStack_214 = *(uint *)(in_ECX[0x5a] + 8);
  if (DAT_00b19ac8 != 0) {
    iVar4 = FUN_0072be90(&uStack_214,4,0);
    if (iVar4 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (uStack_214 & 0xff) + 4;
  }
  uStack_210 = *(uint *)(in_ECX[0x58] + 0x48);
  if (DAT_00b19ac8 != 0) {
    iVar4 = FUN_0072be90(&uStack_210,4,0);
    if (iVar4 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (uStack_210 & 0xff) + 4;
  }
  FUN_0066ee00(in_ECX + 0x457);
  FUN_0066ee00(in_ECX + 0x458);
  if ((((*(byte *)((int)in_ECX + 0x25) & 4) == 0) && (iVar4 = FUN_00464dc0(), iVar4 == 0)) &&
     (in_ECX[0x425] == 0)) {
    iVar4 = 0;
  }
  else {
    iVar4 = 1;
  }
  piVar1 = in_ECX + 0x441;
  *piVar1 = iVar4;
  FUN_0066ee00(piVar1);
  if (*piVar1 != 0) {
    FUN_0066ee00(in_ECX[0x59] + 0xf50);
    FUN_0066ee00(in_ECX[0x59] + 0xf60);
    if (*(int *)(in_ECX[0x59] + 0xf54) == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(undefined4 *)(*(int *)(in_ECX[0x59] + 0xf54) + 0x30);
    }
    FUN_00531bc0(uVar7);
    if (*(int *)(in_ECX[0x59] + 0xf58) == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(undefined4 *)(*(int *)(in_ECX[0x59] + 0xf58) + 0x30);
    }
    FUN_00531bc0(uVar7);
    if (*(int *)(in_ECX[0x59] + 0xf5c) == 0) {
      uVar7 = 0;
    }
    else {
      uVar7 = *(undefined4 *)(*(int *)(in_ECX[0x59] + 0xf5c) + 0x30);
    }
    FUN_00531bc0(uVar7);
    if (*(int *)(in_ECX[0x59] + 0xf60) == 0x105) {
      *(undefined4 *)(in_ECX[0x59] + 0xfb4) = 0;
    }
    FUN_004c6b80(param_1);
  }
  iVar4 = 0;
  do {
    FUN_004d8110(iVar4,&iStack_228,&iStack_224);
    FUN_0066ee00(&iStack_228);
    FUN_0066ee00(&iStack_224);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 4);
  return 1;
}



// ?Load@Creature@@UAEIAAVGameOSFile@@@Z @ 0x004c7230

/* WARNING: Removing unreachable block (ram,0x004c7541) */

undefined4 _Load_Creature__UAEIAAVGameOSFile___Z(int param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int in_ECX;
  uint uVar7;
  uint uVar8;
  char *pcVar9;
  char *pcVar10;
  int in_stack_0000b2c6;
  undefined4 in_stack_0000b2d6;
  int in_stack_0000b2e6;
  uint in_stack_00016cec;
  uint in_stack_00016cf0;
  
  iVar3 = _Load_Living__UAEIAAVGameOSFile___Z();
  if (iVar3 == 0) {
    return 0;
  }
  if (*(int *)(in_ECX + 0x168) == 0) {
    puVar4 = (undefined4 *)FUN_004300a0();
    if (puVar4 == (undefined4 *)0x0) {
      puVar4 = (undefined4 *)0x0;
    }
    else {
      puVar4[1] = 0;
      *puVar4 = &vftable_GAlignment;
      puVar4[3] = 0;
      puVar4[2] = 0;
    }
    *(undefined4 **)(in_ECX + 0x168) = puVar4;
  }
  if (DAT_00b19acc != 0) {
    iVar3 = FUN_0072be50();
    if (iVar3 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (DAT_00bcc4d4 & 0xff) + 4;
    if (DAT_00b19acc != 0) {
      iVar3 = FUN_0072be50();
      if (iVar3 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (DAT_00bcc4d0 & 0xff) + 4;
    }
  }
  if (DAT_00b19acc != 0) {
    iVar3 = FUN_0072be50();
    if (iVar3 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x10c4) + 1;
  }
  if (DAT_00b19acc != 0) {
    iVar3 = FUN_0072be50();
    if (iVar3 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x10c5) + 1;
  }
  iVar3 = 0;
  if (*(byte *)(in_ECX + 0x10c5) != 0xff) {
    iVar3 = FUN_00523640();
  }
  iVar5 = FUN_005256a0();
  if ((((iVar5 == 0) && (iVar5 = FUN_00523640(), iVar3 == iVar5)) &&
      (iVar5 = FUN_005f7f80(), iVar5 != 0)) &&
     ((iVar5 = FUN_00667ed0(), iVar5 != 0 && (*(int *)(iVar5 + 0x1bc) != 0)))) {
    FUN_00733e17();
    FUN_0072bc10();
    FUN_00459b60();
    iVar5 = (**(code **)(in_stack_0000b2e6 + 4))();
    if (iVar5 == 0) {
      bVar2 = true;
      FUN_0072be50();
      uVar7 = 0xffffffff;
      pcVar9 = &stack0x0001162f;
      do {
        pcVar10 = pcVar9;
        if (uVar7 == 0) break;
        uVar7 = uVar7 - 1;
        pcVar10 = pcVar9 + 1;
        cVar1 = *pcVar9;
        pcVar9 = pcVar10;
      } while (cVar1 != '\0');
      uVar7 = ~uVar7;
      pcVar9 = pcVar10 + -uVar7;
      pcVar10 = &stack0x00011517;
      for (uVar8 = uVar7 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
        *(undefined4 *)pcVar10 = *(undefined4 *)pcVar9;
        pcVar9 = pcVar9 + 4;
        pcVar10 = pcVar10 + 4;
      }
      for (uVar7 = uVar7 & 3; uVar7 != 0; uVar7 = uVar7 - 1) {
        *pcVar10 = *pcVar9;
        pcVar9 = pcVar9 + 1;
        pcVar10 = pcVar10 + 1;
      }
    }
    else {
      bVar2 = false;
    }
    iVar5 = FUN_0072c050();
    if (((bVar2) && (iVar5 == 0)) && (in_stack_0000b2c6 != 0)) {
      FUN_006ab530();
      FUN_006ab530();
      *(undefined4 **)(in_ECX + 0x28) = &DAT_00b81ce8 + iVar3 * 0xe5;
    }
    if (bVar2) {
      FUN_004c7bc0();
    }
    FUN_0072bc20();
  }
  FUN_0045eab0();
  iVar5 = 0;
  do {
    FUN_005328f0();
    iVar5 = iVar5 + 0x18;
  } while (iVar5 < 0x180);
  if (DAT_00b19acc != 0) {
    FUN_00589540();
    iVar5 = 0;
    if (0 < iVar3) {
      do {
        FUN_004d4510();
        FUN_00532ab0();
        FUN_0054a9f0();
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar3);
    }
  }
  if ((0x19 < DAT_00bcc4d4) && (iVar5 = *(int *)(in_ECX + 0x164), DAT_00b19acc != 0)) {
    iVar6 = FUN_0072be50();
    if (iVar6 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(iVar5 + 0x20ce4) + 4;
  }
  if (DAT_00b19acc != 0) {
    iVar5 = FUN_0072be50();
    if (iVar5 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x374) + 4;
  }
  if (DAT_00b19acc != 0) {
    iVar5 = FUN_0072be50();
    if (iVar5 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x378) + 4;
  }
  if (DAT_00b19acc != 0) {
    iVar5 = FUN_0072be50();
    if (iVar5 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x37c) + 1;
  }
  if (DAT_00b19acc != 0) {
    iVar5 = FUN_0072be50();
    if (iVar5 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x1298) + 1;
  }
  if (DAT_00b19acc != 0) {
    iVar5 = FUN_0072be50();
    if (iVar5 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x129c) + 4;
  }
  if (DAT_00b19acc != 0) {
    iVar5 = FUN_0072be50();
    if (iVar5 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x12a0) + 4;
  }
  if (DAT_00b19acc != 0) {
    iVar5 = FUN_0072be50();
    if (iVar5 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x12a4) + 4;
  }
  if (DAT_00b19acc != 0) {
    iVar5 = FUN_0072be50();
    if (iVar5 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x12a8) + 4;
  }
  if (DAT_00b19acc != 0) {
    iVar5 = FUN_0072be50();
    if (iVar5 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x12ac) + 4;
  }
  FUN_00531f30();
  FUN_00531f30();
  FUN_00531f30();
  FUN_00531f30();
  FUN_00531f30();
  if (DAT_00b19acc != 0) {
    iVar5 = FUN_0072be50();
    if (iVar5 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x11d8) + 0xc;
  }
  FUN_00531f30();
  FUN_00531f30();
  if (DAT_00b19acc != 0) {
    iVar5 = FUN_0072be50();
    if (iVar5 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x11f0) + 1;
  }
  FUN_00531f30();
  if (DAT_00b19acc != 0) {
    iVar5 = FUN_0072be50();
    if (iVar5 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x1200) + 0xc;
  }
  iVar5 = FUN_004619d0();
  if (DAT_00b19acc != 0) {
    iVar6 = FUN_0072be50();
    if (iVar6 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(iVar5 + 0x4aa8) + 4;
    if (DAT_00b19acc != 0) {
      iVar5 = FUN_0072be50();
      if (iVar5 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (in_stack_00016cec & 0xff) + 4;
    }
  }
  FUN_00466e40();
  if (DAT_00b19acc != 0) {
    FUN_00589540();
    for (; 0 < iVar3; iVar3 = iVar3 + -1) {
      FUN_00531f30();
      FUN_006d5810();
    }
  }
  FUN_00531f30();
  if (DAT_00b19acc != 0) {
    iVar3 = FUN_0072be50();
    if (iVar3 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x1158) + 4;
    if (DAT_00b19acc != 0) {
      iVar3 = FUN_0072be50();
      if (iVar3 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (in_stack_00016cf0 & 0xff) + 4;
    }
  }
  FUN_004d0200();
  FUN_00589540();
  FUN_00589540();
  FUN_00412600();
  FUN_00589540();
  *(undefined4 *)(*(int *)(in_ECX + 0x160) + 0x48) = in_stack_0000b2d6;
  FUN_00589540();
  FUN_00589540();
  FUN_00589540();
  if (*(int *)(in_ECX + 0x1104) != 0) {
    FUN_00589540();
    FUN_00589540();
    FUN_00531f30();
    FUN_00531f30();
    FUN_00531f30();
    FUN_004c6ec0();
  }
  iVar3 = 0;
  do {
    FUN_00589540();
    FUN_00589540();
    FUN_004d8070();
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  return 1;
}



// ?ResolveLoad@Creature@@UAEXXZ @ 0x004c7cf0

/* WARNING: Removing unreachable block (ram,0x004c825a) */

void _ResolveLoad_Creature__UAEXXZ(void)

{
  char cVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  undefined4 *puVar5;
  int *in_ECX;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  int unaff_EBP;
  int iVar9;
  char *pcVar10;
  char *pcVar11;
  undefined4 uStack_868;
  undefined4 uStack_864;
  undefined4 uStack_860;
  undefined4 uStack_858;
  undefined4 uStack_854;
  undefined4 uStack_850;
  undefined4 uStack_84c;
  undefined4 uStack_848;
  int iStack_73c;
  int iStack_234;
  
  iVar4 = in_ECX[0x428];
  iVar9 = 0;
  if (*(char *)((int)in_ECX + 0x10c5) != -1) {
    iVar9 = FUN_00523640();
  }
  FUN_00715bb0();
  FUN_00733e17();
  if ((0xe < DAT_00d26950) && (DAT_00d26950 < 0x12)) {
    FUN_00733e17();
  }
  if (DAT_00c22ca4 + 0x18 + (uint)*(byte *)(DAT_00c22ca4 + 0x201b15) * 0x278 == iVar9) {
    FUN_005f7f80();
    FUN_00667ed0();
    FUN_00733e17();
  }
  else {
    FUN_00733e17();
  }
  FUN_0072bc10();
  iVar9 = (**(code **)(iStack_73c + 4))();
  if (iVar9 == 0) {
    bVar3 = true;
    iStack_234 = 2;
    FUN_0072be50();
    uVar6 = 0xffffffff;
    pcVar10 = &stack0x00005c05;
    do {
      pcVar11 = pcVar10;
      if (uVar6 == 0) break;
      uVar6 = uVar6 - 1;
      pcVar11 = pcVar10 + 1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar11;
    } while (cVar1 != '\0');
    uVar6 = ~uVar6;
    pcVar10 = pcVar11 + -uVar6;
    pcVar11 = &stack0x00005aed;
    for (uVar7 = uVar6 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {
      *(undefined4 *)pcVar11 = *(undefined4 *)pcVar10;
      pcVar10 = pcVar10 + 4;
      pcVar11 = pcVar11 + 4;
    }
    for (uVar6 = uVar6 & 3; uVar6 != 0; uVar6 = uVar6 - 1) {
      *pcVar11 = *pcVar10;
      pcVar10 = pcVar10 + 1;
      pcVar11 = pcVar11 + 1;
    }
  }
  else {
    bVar3 = false;
  }
  iVar9 = FUN_0072c050();
  if (((bVar3) && (iVar9 == 0)) && (iVar4 != 0)) {
    FUN_006ab530();
    FUN_006ab530();
    FUN_004c9460();
    FUN_004c95d0();
    _ResolveLoad_Object__UAEXXZ();
  }
  iVar4 = FUN_004619d0();
  if ((int *)in_ECX[0x10] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x10] + 4))();
  }
  in_ECX[0x10] = *(int *)(iVar4 + 0x482c);
  iVar4 = (**(code **)(*in_ECX + 0x1c))();
  if (iVar4 != 0) {
    (**(code **)(*in_ECX + 0x1c))();
    FUN_005f7f80();
    FUN_00667ed0();
    FUN_00590e80();
  }
  if (in_ECX[0x441] != 0) {
    uVar6 = in_ECX[0x105];
    if (uVar6 < (uint)in_ECX[0x107]) {
      piVar8 = in_ECX + uVar6 * 0x18 + 0x10f;
      do {
        if (*piVar8 != 0) {
          iVar4 = FUN_004ba200();
          *piVar8 = iVar4;
        }
        uVar6 = uVar6 + 1;
        piVar8 = piVar8 + 0x18;
      } while (uVar6 < (uint)in_ECX[0x107]);
    }
    FUN_004d1380();
    iVar4 = in_ECX[0x466];
    iVar9 = in_ECX[0x465];
    if (in_ECX[0x467] != 0) {
      uStack_868 = FUN_004ba200();
    }
    if (in_ECX[0x468] != 0) {
      uStack_864 = FUN_004ba200();
    }
    if (in_ECX[0x469] != 0) {
      uStack_860 = FUN_004ba200();
    }
    iVar2 = in_ECX[0x59];
    *(undefined4 *)(iVar2 + 0xf4c) = 0;
    *(int *)(iVar2 + 0xf50) = iVar9;
    *(undefined4 *)(iVar2 + 0xf54) = uStack_868;
    *(undefined4 *)(iVar2 + 0xf58) = uStack_864;
    *(undefined4 *)(iVar2 + 0xf5c) = uStack_860;
    *(int *)(iVar2 + 0xf60) = iVar4;
    *(undefined4 *)(iVar2 + 0xf64) = uStack_858;
    *(undefined4 *)(iVar2 + 0xf68) = uStack_854;
    *(undefined4 *)(iVar2 + 0xf6c) = uStack_850;
    *(undefined4 *)(iVar2 + 0xf70) = uStack_84c;
    *(undefined4 *)(iVar2 + 0xf74) = uStack_848;
    in_ECX[0x428] = unaff_EBP;
    *(undefined4 *)(in_ECX[0x59] + 0x1c14) = 1;
    iVar4 = in_ECX[0x59];
    *(int *)(iVar4 + 0xfac) = in_ECX[0x103];
    *(int *)(iVar4 + 0xfb0) = in_ECX[0x104];
    *(int *)(iVar4 + 0xfb4) = in_ECX[0x105];
    *(int *)(iVar4 + 0xfb8) = in_ECX[0x106];
    *(int *)(iVar4 + 0xfbc) = in_ECX[0x107];
    *(int *)(iVar4 + 0xfc0) = in_ECX[0x108];
    *(int *)(iVar4 + 0xfc4) = in_ECX[0x109];
    *(int *)(iVar4 + 0xfc8) = in_ECX[0x10a];
    piVar8 = in_ECX + 0x10f;
    puVar5 = (undefined4 *)(iVar4 + 0xfd4);
    iVar9 = 0x20;
    do {
      *puVar5 = *(undefined4 *)((int)in_ECX + (0x408 - (iVar4 + 0xfa8)) + (int)puVar5);
      puVar5[1] = piVar8[-1];
      puVar5[2] = *piVar8;
      puVar5[2] = *piVar8;
      puVar5[3] = piVar8[1];
      puVar5[4] = piVar8[2];
      puVar5[5] = piVar8[3];
      puVar5[6] = piVar8[4];
      puVar5[7] = piVar8[5];
      puVar5[8] = piVar8[6];
      puVar5[9] = piVar8[7];
      puVar5[10] = piVar8[8];
      puVar5[0xb] = piVar8[9];
      puVar5[0xf] = piVar8[0xd];
      puVar5[0x10] = piVar8[0xe];
      puVar5[0x11] = piVar8[0xf];
      puVar5[0x12] = piVar8[0x10];
      puVar5[0x13] = piVar8[0x11];
      puVar5[0x14] = piVar8[0x12];
      puVar5[0x15] = piVar8[0x13];
      puVar5[0x16] = piVar8[0x14];
      piVar8 = piVar8 + 0x18;
      puVar5 = puVar5 + 0x18;
      iVar9 = iVar9 + -1;
    } while (iVar9 != 0);
    *(int *)(iVar4 + 0x1bd0) = in_ECX[0x40c];
    *(int *)(iVar4 + 0x1bd4) = in_ECX[0x40d];
    *(int *)(iVar4 + 0x1bd8) = in_ECX[0x40e];
    *(int *)(iVar4 + 0x1bdc) = in_ECX[0x40f];
    *(int *)(iVar4 + 0x1be0) = in_ECX[0x410];
    *(int *)(iVar4 + 0x1be4) = in_ECX[0x411];
    *(int *)(iVar4 + 0x1be8) = in_ECX[0x412];
    *(int *)(iVar4 + 0x1bec) = in_ECX[0x413];
    *(int *)(iVar4 + 0x1bf0) = in_ECX[0x414];
    FUN_004d13a0();
  }
  if (bVar3) {
    if (iStack_234 != 2) {
      FUN_006ab1f0();
    }
    FUN_0072bdd0();
  }
  FUN_0072bc20();
  return;
}



// ?UpdateHowImpressed@Creature@@UAEXPAVReaction@@H@Z @ 0x004d25e0

void _UpdateHowImpressed_Creature__UAEXPAVReaction__H_Z(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int *in_ECX;
  
  in_ECX[0x25] = param_1;
  puVar2 = operator_new(8);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    uVar1 = *(undefined4 *)(param_1 + 0x18);
    *puVar2 = in_ECX;
    puVar2[1] = uVar1;
  }
  *(undefined4 **)(param_1 + 0x18) = puVar2;
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
  (**(code **)(*in_ECX + 0x988))(param_1,1);
  return;
}



// ?AddReaction@Creature@@UAEXPAVReaction@@W4VILLAGER_STATES@@@Z @ 0x004d2630

void _AddReaction_Creature__UAEXPAVReaction__W4VILLAGER_STATES___Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x164);
  *(undefined4 *)(iVar1 + 0xf7c) = *(undefined4 *)(iVar1 + 0xf4c);
  *(undefined4 *)(iVar1 + 0xf80) = *(undefined4 *)(iVar1 + 0xf50);
  *(undefined4 *)(iVar1 + 0xf84) = *(undefined4 *)(iVar1 + 0xf54);
  *(undefined4 *)(iVar1 + 0xf88) = *(undefined4 *)(iVar1 + 0xf58);
  *(undefined4 *)(iVar1 + 0xf8c) = *(undefined4 *)(iVar1 + 0xf5c);
  *(undefined4 *)(iVar1 + 0xf90) = *(undefined4 *)(iVar1 + 0xf60);
  *(undefined4 *)(iVar1 + 0xf94) = *(undefined4 *)(iVar1 + 0xf64);
  *(undefined4 *)(iVar1 + 0xf98) = *(undefined4 *)(iVar1 + 0xf68);
  *(undefined4 *)(iVar1 + 0xf9c) = *(undefined4 *)(iVar1 + 0xf6c);
  *(undefined4 *)(iVar1 + 4000) = *(undefined4 *)(iVar1 + 0xf70);
  *(undefined4 *)(iVar1 + 0xfa4) = *(undefined4 *)(iVar1 + 0xf74);
  _AddReaction_Living__UAEXPAVReaction__W4VILLAGER_STATES___Z(param_1,param_2,param_3);
  return;
}



// ?StandardNumGameTurnsToReactFunction@Creature@@UAEIPAVGameThingWithPos@@IM@Z @ 0x004d2910

void _StandardNumGameTurnsToReactFunction_Creature__UAEIPAVGameThingWithPos__IM_Z
               (undefined4 param_1,int param_2)

{
  __ftol(*(undefined4 *)(&DAT_00c70470 + param_2 * 100),0);
  return;
}



// ?StandardNumGameTurnsBeforeReactingAgainFunction@Creature@@UAEIPAVGameThingWithPos@@IM@Z @ 0x004d2960

void _StandardNumGameTurnsBeforeReactingAgainFunction_Creature__UAEIPAVGameThingWithPos__IM_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  _StandardNumGameTurnsBeforeReactingAgainFunction_Living__UAEIPAVGameThingWithPos__IM_Z
            (param_1,param_2,param_3);
  return;
}



// ?NumGameTurnsToReactToCreatureFunction@Creature@@UAEIPAVGameThingWithPos@@IM@Z @ 0x004d2980

void _NumGameTurnsToReactToCreatureFunction_Creature__UAEIPAVGameThingWithPos__IM_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  _NumGameTurnsToReactToCreatureFunction_Living__UAEIPAVGameThingWithPos__IM_Z
            (param_1,param_2,param_3);
  return;
}



// ?ResetStateAfterReacting@Creature@@UAEXXZ @ 0x004d29f0

void _ResetStateAfterReacting_Creature__UAEXXZ(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_007344da(param_1,0,&GameThingWithPos::RTTI_Type_Descriptor,
                       &Spell::RTTI_Type_Descriptor,0);
  FUN_004d30f0(param_2,*(undefined4 *)(iVar1 + 0xb4),param_1);
  return;
}



// ?SetupReactToTeleport@Creature@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x004d2a70

void _SetupReactToTeleport_Creature__UAEXPAVGameThingWithPos__PAVReaction___Z
               (int param_1,undefined4 param_2)

{
  int *in_ECX;
  
  FUN_004ba200(in_ECX,param_1);
  FUN_004d2890(0,3);
  in_ECX[0x2f] = param_1;
  (**(code **)(*in_ECX + 0x98c))(param_2,0);
  return;
}



// ?ReactToTeleportPriority@Creature@@UAEEPAVReaction@@0@Z @ 0x004d2ab0

undefined1 _ReactToTeleportPriority_Creature__UAEEPAVReaction__0_Z(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x1c))();
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*in_ECX + 0x1c))();
    if (*(int *)(iVar1 + 0xf8) != 2) {
      return DAT_00c70cf8;
    }
  }
  return 0;
}



// ?ReactToCreaturePriority@Creature@@UAEEPAVReaction@@0@Z @ 0x004d2c70

uint _ReactToCreaturePriority_Creature__UAEEPAVReaction__0_Z(int param_1)

{
  int iVar1;
  uint uVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x1c))();
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = (**(code **)(*in_ECX + 0x1c))();
    if (*(int *)(uVar2 + 0xf8) != 2) {
      iVar1 = FUN_004615b0(*(int *)(param_1 + 0x14) + 0x14);
      return CONCAT31((int3)((uint)-iVar1 >> 8),-(iVar1 != 0)) & DAT_00c7071c;
    }
  }
  return uVar2 & 0xffffff00;
}



// ?SetupReactToCreature@Creature@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x004d2cc0

void _SetupReactToCreature_Creature__UAEXPAVGameThingWithPos__PAVReaction___Z
               (int param_1,undefined4 param_2)

{
  int *in_ECX;
  
  FUN_004ba200(in_ECX,param_1);
  in_ECX[0x2f] = param_1;
  (**(code **)(*in_ECX + 0x98c))(param_2,0);
  return;
}



// ?ReactToFlyingObjectPriority@Creature@@UAEEPAVReaction@@0@Z @ 0x004d2d50

undefined1 _ReactToFlyingObjectPriority_Creature__UAEEPAVReaction__0_Z(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x1c))();
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*in_ECX + 0x1c))();
    if (*(int *)(iVar1 + 0xf8) != 2) {
      return (undefined1)DAT_00c708ac;
    }
  }
  return 0;
}



// ?SetupReactToFire@Creature@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x004d2d80

void _SetupReactToFire_Creature__UAEXPAVGameThingWithPos__PAVReaction___Z
               (int param_1,undefined4 param_2)

{
  int *in_ECX;
  
  FUN_004be9a0(3,in_ECX[10],0x3fa66666);
  in_ECX[0x2f] = param_1;
  (**(code **)(*in_ECX + 0x98c))(param_2,0);
  return;
}



// ?ReactToBallPriority@Creature@@UAEEPAVReaction@@0@Z @ 0x004d2dc0

uint _ReactToBallPriority_Creature__UAEEPAVReaction__0_Z(int param_1)

{
  int *piVar1;
  uint in_EAX;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  int *in_ECX;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  
  piVar1 = *(int **)(param_1 + 0x14);
  if (piVar1 != (int *)0x0) {
    fVar2 = (float10)FUN_006de0a0(piVar1 + 5,in_ECX + 5);
    fVar3 = (float10)(**(code **)(*piVar1 + 100))();
    fVar4 = (float10)(**(code **)(*in_ECX + 100))();
    fVar4 = fVar4 + (float10)(float)fVar3;
    fVar2 = (float10)(float)fVar2;
    in_EAX = CONCAT22(extraout_var,
                      (ushort)(fVar4 < fVar2) << 8 | (ushort)(NAN(fVar4) || NAN(fVar2)) << 10 |
                      (ushort)(fVar4 == fVar2) << 0xe);
    if (fVar4 >= fVar2 && (fVar4 == fVar2) == 0) {
      piVar1 = *(int **)(param_1 + 0x14);
      fVar2 = (float10)(**(code **)(*in_ECX + 0x42c))();
      fVar3 = (float10)(**(code **)(*piVar1 + 0x42c))();
      fVar3 = (float10)(float)fVar2 / fVar3;
      fVar2 = (float10)0.2;
      in_EAX = CONCAT22(extraout_var_00,
                        (ushort)(fVar3 < fVar2) << 8 | (ushort)(NAN(fVar3) || NAN(fVar2)) << 10 |
                        (ushort)(fVar3 == fVar2) << 0xe);
      if (fVar3 >= fVar2 && (fVar3 == fVar2) == 0) {
        return CONCAT31((int3)(in_EAX >> 8),DAT_00c70848);
      }
    }
  }
  return in_EAX & 0xffffff00;
}



// ?SetupReactToFlyingObject@Creature@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x004d2e50

void _SetupReactToFlyingObject_Creature__UAEXPAVGameThingWithPos__PAVReaction___Z
               (int param_1,undefined4 param_2)

{
  float fVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int *in_ECX;
  float10 fVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  uVar3 = FUN_004ba200(in_ECX,param_1);
  iVar4 = FUN_004bb170(uVar3);
  if (iVar4 != 0) {
    fVar1 = *(float *)(in_ECX[0x59] + 0x154);
    fVar5 = (float10)FUN_004ca530(iVar4,1);
    if ((float10)0.05 < fVar5 * (float10)fVar1) {
      uVar2 = *(uint *)(in_ECX[0x59] + 0x17d90);
      fVar5 = (float10)FUN_004d82d0(0x16);
      if ((float10)uVar2 / fVar5 <= (float10)1.0) {
        uVar2 = *(uint *)(in_ECX[0x59] + 0x17d90);
        fVar5 = (float10)FUN_004d82d0(0x16);
        if ((float10)uVar2 / fVar5 != (float10)1.0) goto LAB_004d2f30;
      }
      uVar7 = 0xee;
      uVar6 = 1;
      goto LAB_004d2f3d;
    }
  }
LAB_004d2f30:
  uVar7 = 0x10;
  iVar4 = 0;
  uVar6 = 5;
LAB_004d2f3d:
  FUN_004ab9b0(uVar6,iVar4,uVar7,uVar3,0,0,1);
  in_ECX[0x2f] = param_1;
  (**(code **)(*in_ECX + 0x98c))(param_2,0);
  return;
}



// ?SetupReactToBall@Creature@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x004d2f70

void _SetupReactToBall_Creature__UAEXPAVGameThingWithPos__PAVReaction___Z
               (undefined4 param_1,undefined4 param_2)

{
  FUN_004d2f90(param_2,0x13,param_1);
  return;
}



// ?ReactToMagicTreePriority@Creature@@UAEEPAVReaction@@0@Z @ 0x004d3360

undefined1 _ReactToMagicTreePriority_Creature__UAEEPAVReaction__0_Z(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int *in_ECX;
  
  iVar2 = (**(code **)(*in_ECX + 0x1c))();
  if ((iVar2 != 0) && (iVar2 = (**(code **)(*in_ECX + 0x1c))(), *(int *)(iVar2 + 0xf8) != 2)) {
    iVar2 = (**(code **)(*param_1 + 0x1c))();
    if (iVar2 != 0) {
      iVar2 = (**(code **)(*param_1 + 0x1c))();
      iVar3 = (**(code **)(*in_ECX + 0x1c))();
      if (iVar2 != iVar3) {
        uVar4 = (**(code **)(*in_ECX + 0x1c))();
        (**(code **)(*param_1 + 0x1c))(uVar4);
        cVar1 = FUN_005fa4f0(uVar4);
        if ((cVar1 == '\0') &&
           (uVar5 = FUN_0067bc90(100,s_C__dev_black_CreatureReaction_cp_00b0e38c,0x210), 2 < uVar5))
        {
          return 0;
        }
      }
    }
    if ((((*(int *)(in_ECX[0x59] + 0x20d34) == 0) ||
         (899 < *(int *)(DAT_00c22ca4 + 0x201afc) - *(int *)(in_ECX[0x59] + 0x20d34))) &&
        (uVar4 = FUN_007344da(param_1[5],0,&GameThingWithPos::RTTI_Type_Descriptor,
                              &Object::RTTI_Type_Descriptor,0),
        *(int *)(in_ECX[0x59] + 0xf60) != 0xed)) &&
       (((iVar2 = FUN_005f56a0(uVar4), iVar2 != 0 && ((*(byte *)(iVar2 + 0x1d8) & 4) != 0)) &&
        ((iVar2 = FUN_005eb730(), iVar2 != 0 &&
         (iVar2 = FUN_004615b0(param_1[5] + 0x14), iVar2 != 0)))))) {
      return DAT_00c707e4;
    }
  }
  return 0;
}



// ?SetupReactToMagicTree@Creature@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x004d3480

void _SetupReactToMagicTree_Creature__UAEXPAVGameThingWithPos__PAVReaction___Z
               (int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  *(undefined4 *)(in_ECX[0x59] + 0x20d34) = *(undefined4 *)(DAT_00c22ca4 + 0x201afc);
  FUN_007344da(param_1,0,&GameThingWithPos::RTTI_Type_Descriptor,&Object::RTTI_Type_Descriptor,0);
  iVar1 = FUN_005eb730();
  if (iVar1 != 0) {
    uVar2 = FUN_004ba200(in_ECX,param_1);
    FUN_004ab9b0(6,0,0x50,uVar2,0,0,1);
    in_ECX[0x2f] = param_1;
    (**(code **)(*in_ECX + 0x98c))(param_2,0);
  }
  return;
}



// ?ReactToHandPickUpPriority@Creature@@UAEEPAVReaction@@0@Z @ 0x004d36b0

uint _ReactToHandPickUpPriority_Creature__UAEEPAVReaction__0_Z(int param_1)

{
  int iVar1;
  uint uVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x1c))();
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = (**(code **)(*in_ECX + 0x1c))();
    if (*(int *)(uVar2 + 0xf8) != 2) {
      iVar1 = FUN_004615b0(*(int *)(param_1 + 0x14) + 0x14);
      return CONCAT31((int3)((uint)-iVar1 >> 8),-(iVar1 != 0)) & DAT_00c70b04;
    }
  }
  return uVar2 & 0xffffff00;
}



// ?SetupReactToHandPickUp@Creature@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x004d3700

void _SetupReactToHandPickUp_Creature__UAEXPAVGameThingWithPos__PAVReaction___Z
               (int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int *in_ECX;
  
  uVar1 = FUN_004ba200(in_ECX,param_1);
  FUN_004ab9b0(6,0,0x14,uVar1,0,0,1);
  FUN_004d2890(0,2);
  in_ECX[0x2f] = param_1;
  (**(code **)(*in_ECX + 0x98c))(param_2,0);
  return;
}



// ?ReactToHandUsingTotemPriority@Creature@@UAEEPAVReaction@@0@Z @ 0x004d3750

undefined1 _ReactToHandUsingTotemPriority_Creature__UAEEPAVReaction__0_Z(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x1c))();
  if ((iVar1 != 0) && (iVar1 = (**(code **)(*in_ECX + 0x1c))(), *(int *)(iVar1 + 0xf8) != 2)) {
    iVar1 = (**(code **)(*param_1 + 0x1c))();
    if (iVar1 != 0) {
      iVar1 = (**(code **)(*param_1 + 0x1c))();
      iVar2 = (**(code **)(*in_ECX + 0x1c))();
      if ((iVar1 != iVar2) &&
         (uVar3 = FUN_0067bc90(100,s_C__dev_black_CreatureReaction_cp_00b0e38c,0x27f), 2 < uVar3)) {
        return 0;
      }
    }
    iVar1 = *(int *)(in_ECX[0x59] + 0x20d38);
    if ((((iVar1 == 0) || (899 < *(int *)(DAT_00c22ca4 + 0x201afc) - iVar1)) &&
        (*(int *)(in_ECX[0x59] + 0xf50) != 2)) &&
       (((int *)param_1[5] != in_ECX && (iVar1 = FUN_004615b0((int *)param_1[5] + 5), iVar1 != 0))))
    {
      return DAT_00c70b68;
    }
  }
  return 0;
}



// ?SetupReactToHandUsingTotem@Creature@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x004d3810

void _SetupReactToHandUsingTotem_Creature__UAEXPAVGameThingWithPos__PAVReaction___Z
               (int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int *in_ECX;
  
  *(undefined4 *)(in_ECX[0x59] + 0x20d38) = *(undefined4 *)(DAT_00c22ca4 + 0x201afc);
  uVar1 = FUN_004ba200(in_ECX,param_1);
  FUN_004ab9b0(6,0,0x14,uVar1,0,0,1);
  in_ECX[0x2f] = param_1;
  (**(code **)(*in_ECX + 0x98c))(param_2,0);
  return;
}



// ?ReactToObjectCrushedPriority@Creature@@UAEEPAVReaction@@0@Z @ 0x004d3870

uint _ReactToObjectCrushedPriority_Creature__UAEEPAVReaction__0_Z(int param_1)

{
  int iVar1;
  uint uVar2;
  uint in_ECX;
  
  uVar2 = *(uint *)(param_1 + 0x14);
  if (((uVar2 != 0) && (uVar2 != in_ECX)) && (*(int *)(*(int *)(in_ECX + 0x164) + 0xf60) != 0x15)) {
    iVar1 = FUN_004615b0(uVar2 + 0x14);
    uVar2 = 0;
    if (iVar1 != 0) {
      iVar1 = (**(code **)(**(int **)(param_1 + 0x14) + 0xa4))();
      uVar2 = 0;
      if (iVar1 != 0) {
        return CONCAT31((int3)((uint)*(int *)(iVar1 + 0x164) >> 8),
                        *(uint *)(*(int *)(iVar1 + 0x164) + 0x1be8) == in_ECX) - 1U & DAT_00c70bcc;
      }
    }
  }
  return uVar2 & 0xffffff00;
}



// ?SetupReactToFight@Creature@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x004d38e0

void _SetupReactToFight_Creature__UAEXPAVGameThingWithPos__PAVReaction___Z
               (int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  in_ECX[0x2f] = param_1;
  iVar1 = FUN_007344da(param_1,0,&GameThingWithPos::RTTI_Type_Descriptor,
                       &MagicTeleport::RTTI_Type_Descriptor,0);
  if (iVar1 != 0) {
    piVar2 = (int *)(**(code **)(*in_ECX + 0x860))();
    in_ECX[0x473] = *piVar2;
    in_ECX[0x474] = piVar2[1];
    in_ECX[0x475] = piVar2[2];
    uVar3 = (**(code **)(*in_ECX + 0x860))();
    FUN_005b9d30(in_ECX,uVar3);
    uVar3 = FUN_004ba200(in_ECX,param_1);
    FUN_004ab9b0(6,0,0x86,uVar3,0,0,1);
    *(undefined4 *)(in_ECX[0x59] + 0x1c14) = 1;
    *(undefined4 *)(in_ECX[0x59] + 0x1c10) = 1;
    in_ECX[0x2f] = param_1;
    (**(code **)(*in_ECX + 0x98c))(param_2,0);
  }
  return;
}



// ?ReactToHandPuttingStuffInStoragePitPriority@Creature@@UAEEPAVReaction@@0@Z @ 0x004d39a0

undefined1 _ReactToHandPuttingStuffInStoragePitPriority_Creature__UAEEPAVReaction__0_Z(int param_1)

{
  int iVar1;
  
  if (*(int **)(param_1 + 0x14) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(param_1 + 0x14) + 0x34))();
    if (iVar1 != 0) {
      return DAT_00c70d5c;
    }
  }
  return 0;
}



// ?SetupReactToHandPuttingStuffInStoragePit@Creature@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x004d39d0

void _SetupReactToHandPuttingStuffInStoragePit_Creature__UAEXPAVGameThingWithPos__PAVReaction___Z
               (int param_1,undefined4 param_2)

{
  int *in_ECX;
  
  in_ECX[0x2f] = param_1;
  (**(code **)(*in_ECX + 0x98c))(param_2,0);
  FUN_004c06c0(0x30,0x3f800000);
  return;
}



// ?SetupReactToFainting@Creature@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x004d3a50

void _SetupReactToFainting_Creature__UAEXPAVGameThingWithPos__PAVReaction___Z
               (undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int *in_ECX;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = 1;
  uVar3 = 0;
  uVar2 = 0;
  uVar1 = FUN_004ba200(in_ECX,param_1);
  FUN_004ab9b0(8,0,0x14,uVar1,uVar2,uVar3,uVar4);
  in_ECX[0x2f] = (int)in_ECX;
  (**(code **)(*in_ECX + 0x98c))(param_2,0);
  return;
}



// ?SetFocus@Creature@@UAEXPBULHPoint@@@Z @ 0x004d64a0

void _SetFocus_Creature__UAEXPBULHPoint___Z(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int in_ECX;
  
  *(undefined4 *)(*(int *)(in_ECX + 0x164) + 0x1d3f4) = 1;
  *(undefined4 *)(*(int *)(in_ECX + 0x164) + 0x1d3f8) = 1;
  iVar1 = *(int *)(in_ECX + 0x164);
  *(undefined4 *)(iVar1 + 0x1d400) = *param_1;
  *(undefined4 *)(iVar1 + 0x1d404) = param_1[1];
  *(undefined4 *)(iVar1 + 0x1d408) = param_1[2];
  FUN_004d67a0(1);
  uVar2 = *param_1;
  uVar3 = param_1[1];
  uVar4 = param_1[2];
  puVar5 = (undefined4 *)FUN_00746d70(0x10,s_C__dev_black_CreatureScript_cpp_00b0eaa0,0x28);
  if (puVar5 == (undefined4 *)0x0) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    puVar5[1] = uVar2;
    puVar5[2] = uVar3;
    *puVar5 = &vftable_SubArgumentPoint;
    puVar5[3] = uVar4;
  }
  FUN_004de610(7,puVar5,&LAB_004b4c70,0,0,0,0,0,0,0xffffffff);
  return;
}



// ?MaintainSpell@Creature@@UAEXIM@Z @ 0x004d7970

float10 _MaintainSpell_Creature__UAEXIM_Z(int param_1,float param_2)

{
  float fVar1;
  int iVar2;
  float fVar3;
  int in_ECX;
  float10 fVar4;
  float fStack_4;
  
  if (param_2 <= 0.0) {
    return (float10)param_2;
  }
  fVar4 = (float10)FUN_004d78c0();
  fVar1 = (float)fVar4;
  if (fVar4 <= (float10)0.0) {
    return (float10)0.0;
  }
  if (param_2 < fVar1) {
    fVar4 = (float10)FUN_004d7880(param_2);
    fStack_4 = (float)fVar4;
    if ((float10)0.0 <= fVar4) {
      if (0.7 < fStack_4) {
        fStack_4 = 0.7;
      }
    }
    else {
      fStack_4 = 0.0;
    }
    iVar2 = *(int *)(in_ECX + 0x160);
    fVar1 = -(fStack_4 * *(float *)(&DAT_00bcb03c + *(int *)(param_1 + 0xb4) * 0x70)) +
            *(float *)(iVar2 + 0x1c);
    *(float *)(iVar2 + 0x1c) = fVar1;
    if (0.0 <= fVar1) {
      fVar4 = (float10)FUN_004cf970();
      if ((float10)1.0 <= fVar4) {
        fVar4 = (float10)FUN_004cf970();
      }
      else {
        fVar4 = (float10)1.0;
      }
      if (fVar4 < (float10)*(float *)(iVar2 + 0x1c)) {
        fVar4 = (float10)FUN_004cf970();
        if ((float10)1.0 <= fVar4) {
          fVar4 = (float10)FUN_004cf970();
        }
        else {
          fVar4 = (float10)1.0;
        }
        *(float *)(iVar2 + 0x1c) = (float)fVar4;
      }
    }
    else {
      *(undefined4 *)(iVar2 + 0x1c) = 0;
    }
    *(float *)(*(int *)(in_ECX + 0x160) + 0x30) =
         *(float *)(*(int *)(in_ECX + 0x160) + 0x30) + fStack_4;
    return (float10)param_2;
  }
  fVar4 = (float10)FUN_004d7880(fVar1);
  param_2 = (float)fVar4;
  if ((float10)0.0 <= fVar4) {
    if (0.7 < param_2) {
      param_2 = 0.7;
    }
  }
  else {
    param_2 = 0.0;
  }
  iVar2 = *(int *)(in_ECX + 0x160);
  fVar3 = -(param_2 * *(float *)(&DAT_00bcb03c + *(int *)(param_1 + 0xb4) * 0x70)) +
          *(float *)(iVar2 + 0x1c);
  *(float *)(iVar2 + 0x1c) = fVar3;
  if (0.0 <= fVar3) {
    fVar4 = (float10)FUN_004cf970();
    if ((float10)1.0 <= fVar4) {
      fVar4 = (float10)FUN_004cf970();
    }
    else {
      fVar4 = (float10)1.0;
    }
    if (fVar4 < (float10)*(float *)(iVar2 + 0x1c)) {
      fVar4 = (float10)FUN_004cf970();
      if ((float10)1.0 <= fVar4) {
        fVar4 = (float10)FUN_004cf970();
      }
      else {
        fVar4 = (float10)1.0;
      }
      *(float *)(iVar2 + 0x1c) = (float)fVar4;
    }
  }
  else {
    *(undefined4 *)(iVar2 + 0x1c) = 0;
  }
  *(float *)(*(int *)(in_ECX + 0x160) + 0x30) =
       *(float *)(*(int *)(in_ECX + 0x160) + 0x30) + param_2;
  return (float10)fVar1;
}



// ?UpdateSpellInfo@Creature@@UAEXPAVSpell@@PAUPSysProcessInfo@@@Z @ 0x004d7d70

void _UpdateSpellInfo_Creature__UAEXPAVSpell__PAUPSysProcessInfo___Z(int param_1,float *param_2)

{
  float *pfVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  char cVar6;
  int iVar7;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if (param_1 != 0) {
    iVar7 = FUN_006c4230();
    if (iVar7 != 0) {
      cVar6 = FUN_005b9020();
      if (cVar6 != '\0') goto LAB_004d7dc1;
    }
  }
  FUN_00474fb0(&fStack_c);
  param_2[3] = fStack_c;
  param_2[4] = fStack_8;
  param_2[5] = fStack_4;
LAB_004d7dc1:
  pfVar1 = param_2 + 6;
  *pfVar1 = *param_2 - param_2[3];
  param_2[7] = param_2[1] - param_2[4];
  param_2[8] = param_2[2] - param_2[5];
  fVar2 = *pfVar1;
  fVar3 = param_2[8];
  fVar4 = param_2[7];
  if (((fVar2 != 0.0) || (fVar4 != 0.0)) || (fVar3 != 0.0)) {
    fVar5 = 1.0 / SQRT(fVar2 * fVar2 + fVar4 * fVar4 + fVar3 * fVar3);
    *pfVar1 = fVar5 * fVar2;
    param_2[7] = fVar5 * fVar4;
    param_2[8] = fVar5 * fVar3;
  }
  return;
}



// ?CanBeSuckedIntoVortex@Creature@@UAE_NPAVLandscapeVortex@@@Z @ 0x004d8040

undefined4 _CanBeSuckedIntoVortex_Creature__UAE_NPAVLandscapeVortex___Z(void)

{
  int iVar1;
  int in_ECX;
  
  if ((*(char *)(in_ECX + 0x37c) != '\0') && (iVar1 = FUN_004b29d0(), iVar1 != 0)) {
    return 1;
  }
  if ((*(byte *)(in_ECX + 0x25) & 4) != 0) {
    return 1;
  }
  return 0;
}



// ?GetPSysBeamTargetPos@Creature@@UAEXPAULHPoint@@@Z @ 0x004d8160

void _GetPSysBeamTargetPos_Creature__UAEXPAULHPoint___Z(undefined4 *param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = FUN_004619d0();
  if (iVar3 != 0) {
    puVar4 = (undefined4 *)FUN_00469c40();
    uVar1 = puVar4[1];
    uVar2 = puVar4[2];
    *param_1 = *puVar4;
    param_1[1] = uVar1;
    param_1[2] = uVar2;
  }
  return;
}



// ?Draw@Creature@@UAEXXZ @ 0x004f3ff0

void _Draw_Creature__UAEXXZ(void)

{
  int *piVar1;
  void *pvVar2;
  undefined4 *puVar3;
  float *pfVar4;
  TypeDescriptor *pTVar5;
  int iVar6;
  TypeDescriptor *in_ECX;
  float10 fVar7;
  TypeDescriptor *in_stack_ffffff94;
  TypeDescriptor *in_stack_ffffff98;
  TypeDescriptor *in_stack_ffffff9c;
  undefined4 uVar8;
  undefined4 uVar9;
  TypeDescriptor TStack_48;
  float fStack_40;
  TypeDescriptor TStack_3c;
  float fStack_34;
  undefined4 uStack_30;
  float fStack_2c;
  undefined4 uStack_28;
  TypeDescriptor TStack_24;
  float fStack_1c;
  void *pvStack_18;
  float fStack_14;
  float fStack_10;
  TypeDescriptor TStack_c;
  float fStack_4;
  
  if (((uint)in_ECX[4].spare & 0x10) != 0) {
    FUN_00527d30();
    pTVar5 = (TypeDescriptor *)FUN_0058f6e0();
    if (pTVar5 == in_ECX) {
      DAT_00be766c = 0xff;
      DAT_00be7670 = 1;
      fVar7 = (float10)(**(code **)((int)in_ECX->pVFTable + 0x11c))();
      DAT_00be764c = (float)((float10)1.0 - fVar7);
      DAT_00be7648 = 1.0 - *(float *)((int)in_ECX[0x2c].pVFTable + 0x1c);
      DAT_00be7644 = *(undefined4 *)((int)in_ECX[0x2c].pVFTable + 0x30);
      iVar6 = (**(code **)((int)in_ECX->pVFTable + 0x1c))();
      if (iVar6 != 0) {
        (**(code **)((int)in_ECX->pVFTable + 0x1c))();
        iVar6 = FUN_005f80b0();
        if (iVar6 != 0) {
          in_stack_ffffff94 = *(TypeDescriptor **)(iVar6 + 0x487c + *(int *)(iVar6 + 0x4878) * 4);
          in_stack_ffffff9c = &HandState::RTTI_Type_Descriptor;
          in_stack_ffffff98 = (TypeDescriptor *)0x0;
          iVar6 = FUN_007344da(in_stack_ffffff94,0,&HandState::RTTI_Type_Descriptor,
                               &HandStateCreature::RTTI_Type_Descriptor,0);
          if (iVar6 != 0) {
            DAT_00be7640 = *(undefined4 *)(iVar6 + 0xd8);
          }
        }
      }
    }
  }
  if (DAT_00c67828 != 0) {
    for (iVar6 = *(int *)((int)in_ECX[0x2c].spare + 0x222c); iVar6 != 0; iVar6 = *(int *)(iVar6 + 8)
        ) {
      TStack_48.spare = *(void **)(iVar6 + 0x2c);
      fVar7 = (float10)FUN_00760fd0();
      TStack_48.pVFTable._0_1_ = 0;
      TStack_3c.spare = (void *)(float)(fVar7 + (float10)(float)TStack_48.spare);
      in_stack_ffffff9c = &TStack_24;
      TStack_48.pVFTable._1_1_ = 0;
      TStack_3c.pVFTable = (void *)((float)*(int *)(iVar6 + 0x24) * 0.00015258789);
      TStack_48.pVFTable._2_1_ = 0xff;
      TStack_48.pVFTable._3_1_ = 0xff;
      fStack_34 = (float)*(int *)(iVar6 + 0x28) * 0.00015258789;
      TStack_24.spare = (void *)((float)TStack_3c.spare + 30.0);
      in_stack_ffffff98 = &TStack_3c;
      in_stack_ffffff94 = (TypeDescriptor *)0x4f415b;
      TStack_24.pVFTable = TStack_3c.pVFTable;
      fStack_1c = fStack_34;
      _Draw_PlannedMultiMapFixed__QAEXXZ(in_stack_ffffff98,in_stack_ffffff9c,&TStack_48,0);
    }
  }
  if ((DAT_00ba42a8 != 0) && (iVar6 = FUN_00466830(), iVar6 != 0)) {
    in_stack_ffffff98 = in_ECX[0x236].spare;
    in_stack_ffffff9c = &TStack_48;
    in_stack_ffffff94 = in_ECX + 0x235;
    TStack_48.pVFTable._0_1_ = 0;
    TStack_48.pVFTable._1_1_ = 0xff;
    TStack_48.pVFTable._2_1_ = 0xff;
    TStack_48.pVFTable._3_1_ = 0xff;
    FUN_006df1e0(in_stack_ffffff94,in_stack_ffffff98,in_stack_ffffff9c,0x3f000000,1);
  }
  pvVar2 = *(void **)(*(int *)((int)in_ECX[0x2c].pVFTable + 0x58) + 0x482c);
  if (in_ECX[8].pVFTable != pvVar2) {
    in_ECX[8].pVFTable = pvVar2;
  }
  iVar6 = (**(code **)(**(int **)((int)in_ECX[0x2c].pVFTable + 0x58) + 0x1c))();
  if (iVar6 != 0) {
    uVar9 = 0;
    uVar8 = 0;
    in_stack_ffffff9c = in_ECX;
    FUN_00527d30();
    in_stack_ffffff98 = (TypeDescriptor *)0x4f41e9;
    FUN_00595eb0(in_stack_ffffff9c,uVar8,uVar9);
  }
  FUN_0046cb80();
  if (DAT_00ba42a8 != 0) {
    FUN_0046b5d0();
  }
  if ((DAT_00ba42b8 != 0) && (iVar6 = *(int *)((int)in_ECX[0x2c].spare + 0xf58), iVar6 != 0)) {
    fStack_40 = *(float *)(iVar6 + 0x2c);
    fVar7 = (float10)FUN_00760fd0();
    TStack_3c.spare = (void *)(float)(fVar7 + (float10)fStack_40);
    TStack_3c.pVFTable = (void *)((float)*(int *)(iVar6 + 0x24) * 0.00015258789);
    TStack_48.pVFTable._0_1_ = 0;
    TStack_48.pVFTable._1_1_ = 0;
    TStack_48.pVFTable._2_1_ = 0xff;
    fStack_34 = (float)*(int *)(iVar6 + 0x28) * 0.00015258789;
    TStack_48.pVFTable._3_1_ = 0xff;
    fStack_14 = (float)TStack_3c.spare + 20.0;
    pvStack_18 = TStack_3c.pVFTable;
    fStack_10 = fStack_34;
    _Draw_PlannedMultiMapFixed__QAEXXZ(&TStack_3c,&pvStack_18,&TStack_48,0);
    iVar6 = *(int *)(iVar6 + 0x30);
    fStack_40 = *(float *)(iVar6 + 0x1c);
    fVar7 = (float10)FUN_00760fd0();
    TStack_24.spare = (void *)(float)(fVar7 + (float10)fStack_40);
    in_stack_ffffff9c = &TStack_c;
    TStack_24.pVFTable = (void *)((float)*(int *)(iVar6 + 0x14) * 0.00015258789);
    fStack_1c = (float)*(int *)(iVar6 + 0x18) * 0.00015258789;
    in_stack_ffffff98 = &TStack_24;
    TStack_c.spare = (void *)((float)TStack_24.spare + 20.0);
    TStack_48.spare = (void *)0xffff2020;
    in_stack_ffffff94 = (TypeDescriptor *)0x4f431d;
    TStack_c.pVFTable = TStack_24.pVFTable;
    fStack_4 = fStack_1c;
    _Draw_PlannedMultiMapFixed__QAEXXZ(in_stack_ffffff98,in_stack_ffffff9c,&TStack_48.spare,0);
  }
  if ((DAT_00ba42ac != 0) && (pvVar2 = in_ECX[0x2c].spare, 0 < *(int *)((int)pvVar2 + 0x20d08))) {
    TStack_24.pVFTable = *(void **)((int)pvVar2 + 0x20cf0);
    in_stack_ffffff98 = (TypeDescriptor *)((int)pvVar2 + 0x20cf0);
    fStack_1c = *(float *)((int)pvVar2 + 0x20cf8);
    TStack_3c.pVFTable = *(void **)((int)pvVar2 + 0x20cfc);
    TStack_3c.spare = *(void **)((int)pvVar2 + 0x20d00);
    fStack_34 = *(float *)((int)pvVar2 + 0x20d04);
    in_stack_ffffff9c = &TStack_24;
    TStack_48.pVFTable._0_1_ = 0;
    TStack_48.pVFTable._1_1_ = 0;
    TStack_48.pVFTable._2_1_ = 0xff;
    TStack_48.pVFTable._3_1_ = 0xff;
    TStack_48.spare = (void *)0xff00ff00;
    TStack_24.spare = (void *)0x0;
    _Draw_PlannedMultiMapFixed__QAEXXZ(in_stack_ffffff98,in_stack_ffffff9c,&TStack_48.spare,0);
    in_stack_ffffff94 = (TypeDescriptor *)0x0;
    TStack_3c.spare = (void *)0x0;
    _Draw_PlannedMultiMapFixed__QAEXXZ((int)in_ECX[0x2c].spare + 0x20cfc,&TStack_3c,&TStack_48,0);
    if ((*(byte *)(DAT_00c22ca4 + 0x14) & 4) == 0) {
      piVar1 = (int *)((int)in_ECX[0x2c].spare + 0x20d08);
      *piVar1 = *piVar1 + -1;
    }
  }
  if (DAT_00ba42b0 != 0) {
    pvVar2 = in_ECX[0x2c].spare;
    TStack_24.pVFTable = *(void **)((int)pvVar2 + 0x20d0c);
    in_stack_ffffff98 = (TypeDescriptor *)((int)pvVar2 + 0x20d0c);
    fStack_1c = *(float *)((int)pvVar2 + 0x20d14);
    TStack_24.spare = (void *)(*(float *)((int)pvVar2 + 0x20d10) + 20.0);
    in_stack_ffffff9c = &TStack_24;
    TStack_48.spare = (void *)0xffff0000;
    in_stack_ffffff94 = (TypeDescriptor *)0x4f4453;
    _Draw_PlannedMultiMapFixed__QAEXXZ(in_stack_ffffff98,in_stack_ffffff9c,&TStack_48.spare,0);
  }
  if (*(float *)((int)in_ECX[0x2d].pVFTable + 8) <= 0.333) {
    if (*(float *)((int)in_ECX[0x2d].pVFTable + 8) < -0.333) {
      iVar6 = 3;
      goto LAB_004f4488;
    }
  }
  else {
    iVar6 = 1;
LAB_004f4488:
    if ((&DAT_00debb68)[iVar6] != 0) goto LAB_004f4493;
  }
  iVar6 = 0;
LAB_004f4493:
  DAT_00be7678 = (&DAT_00debb68)[iVar6];
  iVar6 = *(int *)(*(int *)((int)in_ECX[0x2c].pVFTable + 0x58) + 0x47f0);
  uStack_30 = *(undefined4 *)(iVar6 + 0x24);
  fStack_2c = *(float *)(iVar6 + 0x28);
  uStack_28 = *(undefined4 *)(iVar6 + 0x2c);
  TStack_c.pVFTable = (void *)__ftol();
  TStack_c.spare = (void *)__ftol();
  fStack_4 = 0.0;
  fVar7 = (float10)(**(code **)((int)in_ECX->pVFTable + 0x42c))();
  fStack_40 = (float)fVar7;
  fVar7 = (float10)FUN_00760fd0();
  pvVar2 = in_ECX[0x24e].spare;
  fStack_2c = (float)(fVar7 + (float10)fStack_40);
  *(undefined4 *)((int)in_ECX[0x24f].spare + 0xac) = DAT_00be7678;
  if (pvVar2 != (void *)0x0) {
    uVar9 = 0;
    uVar8 = 0;
    FUN_004402a0(&uStack_30);
    FUN_00543e10(&LAB_00463370,in_ECX,in_stack_ffffff94,in_stack_ffffff98,in_stack_ffffff9c,uVar8,
                 uVar9);
  }
  if (DAT_00ba42b4 != 0) {
    for (puVar3 = in_ECX[0x244].pVFTable; puVar3 != (undefined4 *)0x0;
        puVar3 = (undefined4 *)*puVar3) {
      pfVar4 = (float *)puVar3[1];
      TStack_24.pVFTable = (void *)*pfVar4;
      TStack_24.spare = (void *)pfVar4[1];
      fStack_1c = pfVar4[2];
      TStack_c.spare = (void *)((float)TStack_24.spare + 10.0);
      TStack_48.spare = (void *)0xffff0000;
      TStack_c.pVFTable = TStack_24.pVFTable;
      fStack_4 = fStack_1c;
      _Draw_PlannedMultiMapFixed__QAEXXZ(&TStack_24,&TStack_c,&TStack_48.spare,0);
    }
  }
  FUN_004d4a70();
  if (in_ECX[0x213].spare != (void *)0x0) {
    FUN_007575f0();
  }
  return;
}



// ?GetScriptObjectType@Creature@@UAEIXZ @ 0x005c2de0

undefined4 _GetScriptObjectType_Creature__UAEIXZ(void)

{
  return 0xc;
}



// ?CalculateWhereIWillBeAfterNSeconds@Creature@@UAEXMPAULHPoint@@@Z @ 0x005ed8d0

void _CalculateWhereIWillBeAfterNSeconds_Creature__UAEXMPAULHPoint___Z(float param_1,float *param_2)

{
  float fVar1;
  int iVar2;
  int in_ECX;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  
  iVar2 = *(int *)(*(int *)(in_ECX + 0x160) + 0x58);
  fVar3 = (float10)*(float *)(iVar2 + 0x4838) * (float10)param_1;
  fVar4 = (float10)*(float *)(iVar2 + 0x84);
  param_2[1] = 0.0;
  fVar5 = (float10)fsin(fVar4);
  fVar5 = fVar5 * fVar3;
  *param_2 = (float)fVar5;
  fVar4 = (float10)fcos(fVar4);
  fVar3 = -(fVar4 * fVar3);
  param_2[2] = (float)fVar3;
  iVar2 = *(int *)(*(int *)(in_ECX + 0x160) + 0x58);
  *param_2 = (float)fVar5 + *(float *)(iVar2 + 0x78);
  param_2[1] = *(float *)(iVar2 + 0x7c);
  param_2[2] = (float)(fVar3 + (float10)*(float *)(iVar2 + 0x80));
  fVar1 = *(float *)(*(int *)(*(int *)(in_ECX + 0x160) + 0x58) + 0x90);
  __ftol();
  __ftol();
  fVar3 = (float10)FUN_00760fd0();
  param_2[1] = (float)(fVar3 + (float10)(fVar1 * 15.0));
  return;
}



// ?GetSampleForAttack@Creature@@UAEIXZ @ 0x006b33b0

undefined4 _GetSampleForAttack_Creature__UAEIXZ(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0067bcf0(10);
  switch(uVar1) {
  case 0:
    return 0x1338;
  case 1:
    return 0x1339;
  case 2:
    return 0x133a;
  case 3:
    return 0x133b;
  case 4:
    return 0x133c;
  case 5:
    return 0x133d;
  case 6:
    return 0x133e;
  case 7:
    return 0x133f;
  case 8:
    return 0x1340;
  case 9:
    return 0x1341;
  default:
    return 0;
  }
}



// ?GetCreatureMimicType@Creature@@UAEIXZ @ 0x006b6df0

undefined4 _GetCreatureMimicType_Creature__UAEIXZ(void)

{
  return 9;
}



// ?ReactToFightPriority@Creature@@UAEEPAVReaction@@0@Z @ 0x006f48a0

uint _ReactToFightPriority_Creature__UAEEPAVReaction__0_Z(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 in_ECX;
  
  iVar1 = FUN_007344da(*(undefined4 *)(param_1 + 0x14),0,&GameThingWithPos::RTTI_Type_Descriptor,
                       &MagicTeleport::RTTI_Type_Descriptor,0);
  if (iVar1 == 0) {
    return 0;
  }
  uVar2 = FUN_005b9c20(in_ECX);
  return CONCAT31((int3)((uint)uVar2 >> 8),-((char)uVar2 != '\0')) & DAT_00c70c30;
}



