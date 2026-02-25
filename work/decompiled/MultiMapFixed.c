// Decompiled functions for class: MultiMapFixed
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetResourceDropPosForComputerPlayer@MultiMapFixed@@UAEXPAUMapCoords@@@Z @ 0x00401300

void _GetResourceDropPosForComputerPlayer_MultiMapFixed__UAEXPAUMapCoords___Z(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0x14);
  param_1[1] = *(undefined4 *)(in_ECX + 0x18);
  param_1[2] = *(undefined4 *)(in_ECX + 0x1c);
  return;
}



// ?GetPercentBuilt@MultiMapFixed@@UAEMXZ @ 0x00401320

float10 _GetPercentBuilt_MultiMapFixed__UAEMXZ(void)

{
  int in_ECX;
  
  return (float10)*(float *)(in_ECX + 0x5c);
}



// ?GetPercentRepaired@MultiMapFixed@@UAEMXZ @ 0x00401330

void _GetPercentRepaired_MultiMapFixed__UAEMXZ(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00401332. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0x11c))();
  return;
}



// ?GetResourcePos@MultiMapFixed@@UAEPAUMapCoords@@W4RESOURCE_TYPE@@H@Z @ 0x00401340

void _GetResourcePos_MultiMapFixed__UAEPAUMapCoords__W4RESOURCE_TYPE__H_Z(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0x14);
  param_1[1] = *(undefined4 *)(in_ECX + 0x18);
  param_1[2] = *(undefined4 *)(in_ECX + 0x1c);
  return;
}



// ?IsPoisonedResource@MultiMapFixed@@UAE_NXZ @ 0x00401360

undefined1 _IsPoisonedResource_MultiMapFixed__UAE_NXZ(void)

{
  return 0;
}



// ?GetResourceNearestEdge@MultiMapFixed@@UAEPAUMapCoords@@PAU2@W4RESOURCE_TYPE@@PAVObject@@H@Z @ 0x00401370

undefined4
_GetResourceNearestEdge_MultiMapFixed__UAEPAUMapCoords__PAU2_W4RESOURCE_TYPE__PAVObject__H_Z
          (undefined4 param_1,undefined4 param_2)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x8cc))(param_1,param_2,0xffffffff);
  return param_1;
}



// ?IsBeingBuilt@MultiMapFixed@@UAE_NPAVCreature@@@Z @ 0x00401390

bool _IsBeingBuilt_MultiMapFixed__UAE_NPAVCreature___Z(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x890))();
  return iVar1 != 1;
}



// ?NeedsRepair@MultiMapFixed@@UAE_NPAVCreature@@@Z @ 0x004013b0

bool _NeedsRepair_MultiMapFixed__UAE_NPAVCreature___Z(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x88c))();
  return iVar1 == 0;
}



// ?GetFootpathLink@MultiMapFixed@@UAEPAVGFootpathLink@@XZ @ 0x004013c0

undefined4 _GetFootpathLink_MultiMapFixed__UAEPAVGFootpathLink__XZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 100);
}



// ?GetCollideData@MultiMapFixed@@UAEPAVNewCollide@@XZ @ 0x004013d0

undefined4 _GetCollideData_MultiMapFixed__UAEPAVNewCollide__XZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x78);
}



// ?GetShowNeedsPos@MultiMapFixed@@UAEIKPAUMapCoords@@@Z @ 0x00401840

undefined4 _GetShowNeedsPos_MultiMapFixed__UAEIKPAUMapCoords___Z(void)

{
  return 0;
}



// ?CreatureMustAvoid@MultiMapFixed@@UAE_NPAVCreature@@@Z @ 0x00401b50

void _CreatureMustAvoid_MultiMapFixed__UAE_NPAVCreature___Z(void)

{
  int iVar1;
  int *in_ECX;
  undefined4 uVar2;
  
  if ((undefined4 *)in_ECX[0x24] != (undefined4 *)0x0) {
    *(undefined4 *)in_ECX[0x24] = 0;
  }
  uVar2 = 0;
  iVar1 = (**(code **)(*in_ECX + 0x788))(0);
  FUN_00759e40(0x44fa0000,&DAT_00be7740 + iVar1 * 6,uVar2);
  FUN_0075a0f0();
  return;
}



// ?CastMultiMapFixed@MultiMapFixed@@UAEPAV1@XZ @ 0x00403a40

void _CastMultiMapFixed_MultiMapFixed__UAEPAV1_XZ
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *in_ECX;
  
  if (((int *)in_ECX[0x1d] != (int *)0x0) && ((param_1 == 1 || (param_1 == -2)))) {
    (**(code **)(*(int *)in_ECX[0x1d] + 0xa0))(param_1,param_2,param_3,param_4);
    return;
  }
  (**(code **)(*in_ECX + 0x8e8))(param_1,param_2,param_3,param_4);
  return;
}



// ?GetShowNeedsPos@MultiMapFixed@@UAEIKPAUMapCoords@@@Z @ 0x00404890

undefined4 _GetShowNeedsPos_MultiMapFixed__UAEIKPAUMapCoords___Z(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = _IsFunctional_MultiMapFixed__UAE_NXZ();
  if (iVar1 == 1) {
    iVar1 = (**(code **)(*in_ECX + 0x890))();
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}



// ?GetArrivePos@MultiMapFixed@@UAEPAUMapCoords@@PAU2@@Z @ 0x0041cc00

undefined4 _GetArrivePos_MultiMapFixed__UAEPAUMapCoords__PAU2__Z(undefined4 param_1)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x864))(param_1);
  return param_1;
}



// ?CreatureMustAvoid@MultiMapFixed@@UAE_NPAVCreature@@@Z @ 0x00452eb0

void _CreatureMustAvoid_MultiMapFixed__UAE_NPAVCreature___Z(int param_1)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int *in_ECX;
  undefined4 uVar6;
  float fStack_4;
  
  if (*(int *)(param_1 + 0x20) == 0) {
    return;
  }
  piVar2 = (int *)FUN_005f3c50();
  uVar6 = 0;
  iVar3 = FUN_005f3c60();
  if (iVar3 != 0) {
    piVar4 = (int *)FUN_005f3c60();
    uVar6 = (**(code **)(*piVar4 + 0x1c))();
  }
  if ((piVar2 == (int *)0x0) || (cVar1 = (**(code **)(*piVar2 + 0x7a8))(), cVar1 == '\0')) {
    uVar5 = 0;
  }
  else {
    uVar5 = 1;
  }
  piVar4 = (int *)(**(code **)(*in_ECX + 0x5d8))(uVar6,uVar5);
  if ((piVar4 != (int *)0x0) && (piVar4 != in_ECX)) {
    (**(code **)(*piVar4 + 0x7ac))(param_1,1);
    return;
  }
  if (((piVar2 != (int *)0x0) && (iVar3 = (**(code **)(*piVar2 + 0x2c))(), iVar3 == 1)) &&
     (cVar1 = (**(code **)(*piVar2 + 0x7a8))(), cVar1 != '\0')) {
    iVar3 = *(int *)(param_1 + 0x20);
    fStack_4 = SQRT(*(float *)(iVar3 + 0x104) * *(float *)(iVar3 + 0x104) +
                    *(float *)(iVar3 + 0x108) * *(float *)(iVar3 + 0x108) +
                    *(float *)(iVar3 + 0x10c) * *(float *)(iVar3 + 0x10c)) *
               *(float *)(iVar3 + 0x15c) * 5e-06;
    if (0.2 < fStack_4) {
      fStack_4 = 0.2;
    }
    in_ECX[0x23] = *(int *)(DAT_00c22ca4 + 0x201afc);
    FUN_004fc5a0(2,fStack_4,uVar6,0x3f800000,0);
    (**(code **)(*in_ECX + 0x5cc))(&stack0xffffffb8,0);
    FUN_00430270();
  }
  return;
}



// ?CreatureMustAvoid@MultiMapFixed@@UAE_NPAVCreature@@@Z @ 0x004548e0

void _CreatureMustAvoid_MultiMapFixed__UAE_NPAVCreature___Z(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x114))();
  if ((iVar1 != 0) && (*(int **)(iVar1 + 0x30) != (int *)0x0)) {
    (**(code **)(**(int **)(iVar1 + 0x30) + 0x7ac))(param_1,1);
    return;
  }
  _UpdateSpellInfo_GameThing__QAEXPAVSpell__PAVPSysProcessInfo___Z(param_1,param_2);
  return;
}



// ?IsBuildingWhichIsBeingBuilt@MultiMapFixed@@UAE_NPAVCreature@@@Z @ 0x004c5600

undefined4 _IsBuildingWhichIsBeingBuilt_MultiMapFixed__UAE_NPAVCreature___Z(void)

{
  int *in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 0x880))();
  if (fVar1 < (float10)1.0) {
    return 1;
  }
  if (((*(byte *)(in_ECX + 0x16) & 4) == 4) &&
     (fVar1 = (float10)(**(code **)(*in_ECX + 0x11c))(), fVar1 < (float10)1.0)) {
    return 1;
  }
  return 0;
}



// ?Process@MultiMapFixed@@UAEIXZ @ 0x004ee330

void _Process_MultiMapFixed__UAEIXZ(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined4 uVar5;
  int *in_ECX;
  float10 fVar6;
  undefined4 *unaff_retaddr;
  float afStack_30 [3];
  float fStack_24;
  float fStack_18;
  float fStack_c;
  
  if (in_ECX[0x10] != 0) {
    (**(code **)(*in_ECX + 0x63c))(afStack_30);
    iVar4 = (**(code **)(*(int *)in_ECX[0x10] + 0xf8))();
    fVar1 = *(float *)(iVar4 + 0x20);
    fVar2 = *(float *)(iVar4 + 0x1c);
    fVar3 = *(float *)(iVar4 + 0x18);
    uVar5 = __ftol();
    *unaff_retaddr = uVar5;
    uVar5 = __ftol();
    unaff_retaddr[1] = uVar5;
    __ftol();
    __ftol();
    fVar6 = (float10)FUN_00760fd0();
    unaff_retaddr[2] =
         (float)((float10)(afStack_30[0] * fVar3 + fStack_24 * fVar2 + fStack_18 * fVar1 + fStack_c)
                - fVar6);
    unaff_retaddr[2] = in_ECX[7];
    return;
  }
  *param_1 = in_ECX[5];
  param_1[1] = in_ECX[6];
  param_1[2] = in_ECX[7];
  return;
}



// ?GetDiscipleStateIfInteractedWith@MultiMapFixed@@UAEIPAVGInterfaceStatus@@PAVVillager@@@Z @ 0x004eeb30

float10 _GetDiscipleStateIfInteractedWith_MultiMapFixed__UAEIPAVGInterfaceStatus__PAVVillager___Z
                  (void)

{
  int *in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 0x120))();
  return fVar1 * fVar1 * fVar1 * (float10)*(float *)(in_ECX[0x25] + 0xac);
}



// ?Draw@MultiMapFixed@@UAEXXZ @ 0x004f4720

void _Draw_MultiMapFixed__UAEXXZ(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  iVar2 = (**(code **)(*in_ECX + 0x8a4))();
  if (iVar2 == 1) {
    FUN_004f4620(in_ECX[0x10]);
    return;
  }
  if (in_ECX[0x11] != 0) {
    FUN_004f46e0();
    return;
  }
  iVar2 = in_ECX[0x10];
  puVar1 = (undefined4 *)(iVar2 + 0x50);
  FUN_0075fc20(iVar2 + 0x38,iVar2 + 0x4c,puVar1);
  uVar3 = FUN_0075d130(iVar2 + 0x38,*puVar1,iVar2 + 0x4c);
  *puVar1 = uVar3;
  FUN_005ed470();
  return;
}



// ?GetShowNeedsPos@MultiMapFixed@@UAEIKPAUMapCoords@@@Z @ 0x004fe710

char * _GetShowNeedsPos_MultiMapFixed__UAEIKPAUMapCoords___Z(void)

{
  return s_Flowers__00b16f58;
}



// ?ToBeDeleted@MultiMapFixed@@UAEXH@Z @ 0x005045b0

void _ToBeDeleted_MultiMapFixed__UAEXH_Z(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *in_ECX;
  
  FUN_0067f9a0();
  iVar4 = (**(code **)(*in_ECX + 0x74))();
  if (iVar4 != 0) {
    piVar5 = (int *)(**(code **)(*in_ECX + 0x74))();
    (**(code **)(*piVar5 + 0xc))(0);
    in_ECX[0x19] = 0;
  }
  iVar4 = DAT_00c22ca4;
  piVar5 = (int *)(DAT_00c22ca4 + 0x201d70);
  piVar1 = (int *)*piVar5;
  piVar3 = (int *)0x0;
  while (piVar2 = piVar3, piVar3 = piVar1, piVar3 != (int *)0x0) {
    piVar1 = (int *)*piVar3;
    if ((int *)piVar3[1] == in_ECX) {
      if (piVar3 == (int *)*piVar5) {
        *piVar5 = (int)piVar1;
      }
      else {
        *piVar2 = (int)piVar1;
      }
      *(int *)(iVar4 + 0x201d74) = *(int *)(iVar4 + 0x201d74) + -1;
      FUN_007290de(piVar3);
      piVar3 = piVar2;
    }
  }
  iVar4 = (**(code **)(*in_ECX + 0x178))();
  if (iVar4 != 0) {
    *(byte *)(DAT_00c22ca4 + 0x1a7c) = *(byte *)(DAT_00c22ca4 + 0x1a7c) | 1;
  }
  if ((int *)in_ECX[0x1d] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x1d] + 0xc))(param_1);
    FUN_005046f0(0);
  }
  _ToBeDeleted_Object__UAEXH_Z(param_1);
  return;
}



// ?GetDoorPos@MultiMapFixed@@UAEPAUMapCoords@@PAU2@@Z @ 0x00504670

void _GetDoorPos_MultiMapFixed__UAEPAUMapCoords__PAU2__Z(int *param_1)

{
  int iVar1;
  int in_ECX;
  int iStack_c;
  int iStack_8;
  int iStack_4;
  
  iStack_c = 0;
  iStack_8 = 0;
  iStack_4 = 0;
  iVar1 = FUN_005ed1c0(&iStack_c);
  if (((iVar1 == 1) && (iStack_c != 0)) && (iStack_8 != 0)) {
    *param_1 = iStack_c;
    param_1[1] = iStack_8;
    param_1[2] = iStack_4;
    return;
  }
  *param_1 = *(int *)(in_ECX + 0x14);
  param_1[1] = *(int *)(in_ECX + 0x18);
  param_1[2] = *(int *)(in_ECX + 0x1c);
  return;
}



// ?GetMapChild@MultiMapFixed@@UAEPAVObject@@PBUMapCell@@@Z @ 0x00504700

undefined4 _GetMapChild_MultiMapFixed__UAEPAVObject__PBUMapCell___Z(undefined4 param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)FUN_00503fb0(param_1);
  if (puVar1 != (undefined4 *)0x0) {
    return *puVar1;
  }
  return 0;
}



// ?SetMapChild@MultiMapFixed@@UAEXPAVObject@@PAUMapCell@@@Z @ 0x00504720

void _SetMapChild_MultiMapFixed__UAEXPAVObject__PAUMapCell___Z(undefined4 param_1)

{
  short sVar1;
  int in_ECX;
  uint uVar2;
  
  uVar2 = 0;
  if (*(int *)(in_ECX + 0x6c) != 0) {
    while ((sVar1 = FUN_005bea50(), sVar1 != *(short *)(*(int *)(in_ECX + 0x68) + 4 + uVar2 * 8) ||
           (sVar1 = FUN_005bea70(), sVar1 != *(short *)(*(int *)(in_ECX + 0x68) + 6 + uVar2 * 8))))
    {
      uVar2 = uVar2 + 1;
      if (*(uint *)(in_ECX + 0x6c) <= uVar2) {
        return;
      }
    }
    *(undefined4 *)(*(int *)(in_ECX + 0x68) + uVar2 * 8) = param_1;
  }
  return;
}



// ?IsObjectFullyInMap@MultiMapFixed@@UAE_NXZ @ 0x00504780

undefined4 _IsObjectFullyInMap_MultiMapFixed__UAE_NXZ(void)

{
  int iVar1;
  int *piVar2;
  int *in_ECX;
  uint uVar3;
  
  if ((in_ECX[0x1b] != 0) && (uVar3 = 0, in_ECX[0x1b] != 0)) {
    do {
      iVar1 = FUN_005a1610();
      piVar2 = *(int **)(iVar1 + 4);
      while( true ) {
        if (piVar2 == (int *)0x0) {
          return 0;
        }
        if (piVar2 == in_ECX) break;
        piVar2 = (int *)(**(code **)(*piVar2 + 0x53c))(iVar1);
      }
      if (piVar2 == (int *)0x0) {
        return 0;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint)in_ECX[0x1b]);
  }
  return 1;
}



// ?MoveMapObject@MultiMapFixed@@UAEHPAUMapCoords@@@Z @ 0x005047e0

undefined4 _MoveMapObject_MultiMapFixed__UAEHPAUMapCoords___Z(undefined4 param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = FUN_005c1400(in_ECX + 5);
  if (iVar1 == 0) {
    (**(code **)(*in_ECX + 0x560))(param_1);
    return 7;
  }
  return 6;
}



// ?InsertMapObject@MultiMapFixed@@UAEXXZ @ 0x00504940

void _InsertMapObject_MultiMapFixed__UAEXXZ(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int *in_ECX;
  float10 fVar8;
  
  iVar5 = (**(code **)(*in_ECX + 0x178))();
  if (iVar5 == 0) {
    (**(code **)(*in_ECX + 0x908))();
  }
  FUN_004558f0(in_ECX);
  iVar5 = FUN_00455e10();
  if (iVar5 != 0) {
    iVar7 = -1;
    do {
      if (iVar7 + 1 == in_ECX[0x1c]) {
        iVar1 = in_ECX[0x1a];
        FUN_00504d40();
        iVar6 = iVar7;
        while (-1 < iVar6) {
          iVar6 = iVar6 + -1;
          iVar2 = in_ECX[0x1a];
          *(undefined4 *)(iVar2 + 8 + iVar6 * 8) = *(undefined4 *)(iVar1 + 8 + iVar6 * 8);
          *(undefined4 *)(iVar2 + 0xc + iVar6 * 8) = *(undefined4 *)(iVar1 + 0xc + iVar6 * 8);
        }
        if (iVar1 != 0) {
          FUN_007290de(iVar1);
        }
      }
      FUN_005a15e0(iVar5);
      in_ECX[0x1b] = iVar7 + 2;
      _InsertMapObjectToCell_Fixed__UAEXPAUMapCell___Z(iVar5);
      iVar5 = FUN_00455e10();
      iVar7 = iVar7 + 1;
    } while (iVar5 != 0);
  }
  FUN_00503f90();
  FUN_005a2b10();
  *(byte *)(in_ECX + 9) = *(byte *)(in_ECX + 9) | 1;
  iVar5 = (**(code **)(*in_ECX + 0x7bc))(0);
  puVar4 = DAT_00b81580;
  if (iVar5 != 0) {
    fVar8 = (float10)(**(code **)(*in_ECX + 100))(in_ECX + 5);
    FUN_0050b9f0((float)fVar8);
    puVar4 = DAT_00b81580;
  }
  for (; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {
    uVar3 = puVar4[1];
    iVar5 = FUN_004619d0();
    iVar7 = (**(code **)(*in_ECX + 0x7bc))(uVar3);
    if (iVar7 != 0) {
      iVar7 = *(int *)(*(int *)(iVar5 + 0x5198) + 0x64054);
      if ((1 < iVar7) && (iVar7 < 5)) {
        (**(code **)(*in_ECX + 0x7c0))(*(int *)(iVar5 + 0x5198),uVar3,1,0);
      }
    }
  }
  FUN_00455b80();
  return;
}



// ?RemoveMapObject@MultiMapFixed@@UAEXXZ @ 0x00504aa0

void _RemoveMapObject_MultiMapFixed__UAEXXZ(void)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  
  FUN_004558f0(in_ECX);
  iVar1 = FUN_00455e10();
  while (iVar1 != 0) {
    _RemoveMapObjectFromCell_Object__UAEXPAUMapCell___Z(iVar1);
    iVar1 = FUN_00455e10();
  }
  *(ushort *)(in_ECX + 9) = *(ushort *)(in_ECX + 9) & 0xfffe;
  FUN_005a2b10();
  FUN_005c8860();
  iVar1 = (**(code **)(*in_ECX + 0x7bc))(0);
  if (iVar1 != 0) {
    fVar2 = (float10)(**(code **)(*in_ECX + 100))(in_ECX + 5);
    FUN_0050c550((float)fVar2);
  }
  FUN_00505870();
  FUN_00455b80();
  return;
}



// ?CheckMapObject@MultiMapFixed@@UAEXXZ @ 0x00504b30

void _CheckMapObject_MultiMapFixed__UAEXXZ(void)

{
  int iVar1;
  undefined4 in_ECX;
  
  FUN_004558f0(in_ECX);
  iVar1 = FUN_00455e10();
  while (iVar1 != 0) {
    _IsObjectInMap_Object__UAE_NPAUMapCell___Z(iVar1);
    iVar1 = FUN_00455e10();
  }
  FUN_00455b80();
  return;
}



// ?CallVirtualFunctionsForCreation@MultiMapFixed@@UAEXABUMapCoords@@@Z @ 0x00504b80

void _CallVirtualFunctionsForCreation_MultiMapFixed__UAEXABUMapCoords___Z(void)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  int *in_ECX;
  float10 fVar7;
  int *piStack_4;
  
  (**(code **)(*in_ECX + 0x538))();
  (**(code **)(*in_ECX + 0x608))();
  (**(code **)(*(int *)in_ECX[0x10] + 0xf4))(0,0);
  fVar7 = (float10)(**(code **)(*in_ECX + 0x120))();
  fVar2 = (float)fVar7;
  fVar7 = (float10)(**(code **)(*in_ECX + 0x508))();
  fVar3 = (float)fVar7;
  iVar6 = *piStack_4;
  iVar5 = in_ECX[0x10];
  iVar1 = piStack_4[1];
  fVar4 = (float)piStack_4[2];
  fVar7 = (float10)FUN_00761280(iVar5 + 0x50);
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
    *(float *)(iVar5 + 0x14) = fVar2;
    *(float *)(iVar5 + 0x24) = fVar2;
    *(float *)(iVar5 + 0x38) = (float)iVar6 * 0.00015258789 + *(float *)(iVar5 + 0x38);
    *(float *)(iVar5 + 0x3c) = (float)(fVar7 + (float10)fVar4) + *(float *)(iVar5 + 0x3c);
    *(float *)(iVar5 + 0x40) = (float)iVar1 * 0.00015258789 + *(float *)(iVar5 + 0x40);
    FUN_004f5f10(fVar3);
  }
  *(float *)(iVar5 + 0x48) = fVar3;
  *(float *)(iVar5 + 0x44) = fVar2;
  (**(code **)(*in_ECX + 0x850))();
  FUN_00504d40();
  if (((*(byte *)(in_ECX + 9) & 4) == 0) && ((*(byte *)((int)in_ECX + 10) & 0x11) == 0)) {
    (**(code **)(*in_ECX + 0x544))();
  }
  iVar6 = (**(code **)(*in_ECX + 0x890))();
  if (iVar6 != 1) {
    (**(code **)(*(int *)in_ECX[0x10] + 0x88))();
    (**(code **)(*(int *)in_ECX[0x10] + 0x80))();
  }
  return;
}



// ?Built@MultiMapFixed@@UAE_NXZ @ 0x00504e10

undefined4 _Built_MultiMapFixed__UAE_NXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  if ((int *)in_ECX[0x1d] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x1d] + 0xc))(0);
  }
  iVar1 = (**(code **)(*in_ECX + 0x8c0))();
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*in_ECX + 0x8c4))();
    if (iVar1 != 0x804) {
      iVar1 = (**(code **)(*in_ECX + 0x48))();
      if (iVar1 != 0) {
        (**(code **)(*in_ECX + 0x1c))(0);
        FUN_0067efc0();
      }
    }
  }
  if (in_ECX[0x10] != 0) {
    iVar1 = (**(code **)(*in_ECX + 0x210))();
    if (iVar1 == 0) {
      (**(code **)(*(int *)in_ECX[0x10] + 0x80))();
      FUN_005a2b10();
    }
  }
  *(byte *)(in_ECX + 0x16) = *(byte *)(in_ECX + 0x16) & 0xfd | 8;
  in_ECX[0x17] = 0x3f800000;
  return 1;
}



// ?StartOnFire@MultiMapFixed@@UAEXXZ @ 0x00504eb0

void _StartOnFire_MultiMapFixed__UAEXXZ(void)

{
  FUN_0067f9a0();
  return;
}



// ?Repaired@MultiMapFixed@@UAE_NXZ @ 0x00504ec0

undefined4 _Repaired_MultiMapFixed__UAE_NXZ(void)

{
  int *in_ECX;
  
  if ((int *)in_ECX[0x1d] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x1d] + 0xc))(0);
  }
  (**(code **)(*in_ECX + 0x8b8))();
  *(byte *)(in_ECX + 0x16) = *(byte *)(in_ECX + 0x16) & 0xfb;
  return 1;
}



// ?GetInfluence@MultiMapFixed@@UAEMXZ @ 0x00504ef0

float10 _GetInfluence_MultiMapFixed__UAEMXZ(void)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  
  iVar1 = in_ECX[10];
  fVar2 = (float10)(**(code **)(*in_ECX + 0x880))();
  fVar3 = (float10)(**(code **)(*in_ECX + 0x120))();
  fVar4 = (float10)(**(code **)(*in_ECX + 0x11c))();
  return fVar4 * (float10)(float)(fVar3 * (float10)(float)fVar2) *
         (float10)*(float *)(iVar1 + 0x11c);
}



// ?GetDesireToBeRepaired@MultiMapFixed@@UAEMXZ @ 0x00504f30

float10 _GetDesireToBeRepaired_MultiMapFixed__UAEMXZ(void)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  
  iVar1 = (**(code **)(*in_ECX + 0x88c))();
  if (iVar1 == 0) {
    fVar2 = (float10)(**(code **)(*in_ECX + 0x884))();
    fVar2 = (((float10)1.0 - fVar2) * (float10)0.5 + (float10)0.5) *
            (float10)*(float *)(in_ECX[10] + 0x118);
    if ((float10)1.0 <= fVar2) {
      return (float10)1.0;
    }
  }
  else {
    fVar2 = (float10)0.0;
  }
  return fVar2;
}



// ?BuildBy@MultiMapFixed@@UAEXM@Z @ 0x00504f90

void _BuildBy_MultiMapFixed__UAEXM_Z(float param_1)

{
  float fVar1;
  int iVar2;
  int *in_ECX;
  float10 fVar3;
  
  iVar2 = (**(code **)(*in_ECX + 0x890))();
  if (iVar2 == 0) {
    fVar1 = (float)in_ECX[0x17];
    in_ECX[0x17] = (int)(param_1 + fVar1);
    if (param_1 + fVar1 < 0.0) {
      in_ECX[0x17] = 0;
    }
    if (1.0 <= (float)in_ECX[0x17]) {
      (**(code **)(*in_ECX + 0x8a8))();
    }
  }
  else {
    iVar2 = (**(code **)(*in_ECX + 0x88c))();
    if (iVar2 == 0) {
      (**(code **)(*in_ECX + 0x5bc))(param_1);
      fVar3 = (float10)(**(code **)(*in_ECX + 0x11c))();
      if ((float10)1.0 <= fVar3) {
        (**(code **)(*in_ECX + 0x8ac))();
        return;
      }
    }
  }
  return;
}



// ?AddFootpathLink@MultiMapFixed@@QAEXPAVGFootpath@@@Z @ 0x00505060

undefined4 _AddFootpathLink_MultiMapFixed__QAEXPAVGFootpath___Z(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x74))();
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)FUN_004300a0(0x1c,s_C__dev_black_Fixed_cpp_00b170e4,0x3d1);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      FUN_0053e720();
      puVar2[6] = 0;
      puVar2[5] = 0;
      *puVar2 = &vftable_GFootpathLink;
    }
    in_ECX[0x19] = (int)puVar2;
  }
  piVar3 = (int *)(**(code **)(*in_ECX + 0x74))();
  (**(code **)(*piVar3 + 0x84))(param_1);
  return 1;
}



// ?RemoveFootpath@MultiMapFixed@@UAEIPAVGFootpath@@@Z @ 0x005050d0

undefined4 _RemoveFootpath_MultiMapFixed__UAEIPAVGFootpath___Z(undefined4 param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x74))();
  if (iVar1 != 0) {
    (**(code **)(*(int *)in_ECX[0x19] + 0x88))(param_1);
  }
  return 1;
}



// ?SaveObject@MultiMapFixed@@UAEIPAVLHOSFile@@PBUMapCoords@@@Z @ 0x00505100

undefined4
_SaveObject_MultiMapFixed__UAEIPAVLHOSFile__PBUMapCoords___Z(undefined4 param_1,int param_2)

{
  int iVar1;
  int *in_ECX;
  
  if (param_2 != 0) {
    iVar1 = (**(code **)(*in_ECX + 0x74))();
    if (iVar1 != 0) {
      (**(code **)(*in_ECX + 0x74))(param_1,param_2);
      FUN_0050b280(param_1,param_2);
    }
  }
  return 1;
}



// ?IsFunctional@MultiMapFixed@@UAE_NXZ @ 0x00505140

undefined4 _IsFunctional_MultiMapFixed__UAE_NXZ(void)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  float10 fVar3;
  
  iVar1 = (**(code **)(*in_ECX + 0x2c))();
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*in_ECX + 0x890))();
    if (iVar1 != 0) {
      fVar2 = (float10)(**(code **)(*in_ECX + 0x884))();
      fVar3 = (float10)(**(code **)(*in_ECX + 0x894))();
      if (fVar3 < (float10)(float)fVar2) {
        return 1;
      }
    }
  }
  return 0;
}



// ?GetPercentRepairedForNonFunctional@MultiMapFixed@@UAEMXZ @ 0x00505190

float10 _GetPercentRepairedForNonFunctional_MultiMapFixed__UAEMXZ(void)

{
  return (float10)0.75;
}



// ?GetPercentForDrawBuilding@MultiMapFixed@@UAEMXZ @ 0x005051a0

void _GetPercentForDrawBuilding_MultiMapFixed__UAEMXZ(void)

{
  int *in_ECX;
  float10 fVar1;
  float10 fVar2;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 0x888))();
  fVar2 = (float10)(**(code **)(*in_ECX + 0x880))();
  if ((float10)(float)fVar1 < fVar2) {
    (**(code **)(*in_ECX + 0x888))();
    return;
  }
  (**(code **)(*in_ECX + 0x880))();
  return;
}



// ?GetPercentRepairedFromWhenDamaged@MultiMapFixed@@UAEMXZ @ 0x005051e0

float10 _GetPercentRepairedFromWhenDamaged_MultiMapFixed__UAEMXZ(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *in_ECX;
  float10 fVar4;
  
  iVar3 = (**(code **)(*in_ECX + 0x890))();
  if (iVar3 == 0) {
    fVar4 = (float10)1.0;
  }
  else {
    iVar3 = (**(code **)(*in_ECX + 0x8b4))();
    if ((iVar3 == 0) || (in_ECX[0x1d] == 0)) {
      fVar4 = (float10)(**(code **)(*in_ECX + 0x884))();
      return fVar4 * (float10)0.98;
    }
    fVar1 = *(float *)(in_ECX[0x1d] + 0x640);
    fVar2 = 1.0 - fVar1;
    fVar4 = (float10)(**(code **)(*in_ECX + 0x884))();
    fVar1 = (float)(fVar4 - (float10)fVar1);
    fVar4 = (float10)0.0;
    if ((fVar2 != 0.0) && (fVar1 != 0.0)) {
      return (float10)fVar1 / (float10)fVar2;
    }
  }
  return fVar4;
}



// ?IsDrawBuilding@MultiMapFixed@@UAE_NXZ @ 0x00505290

bool _IsDrawBuilding_MultiMapFixed__UAE_NXZ(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0x74) != 0;
}



// ?GetDiscipleStateIfInteractedWith@MultiMapFixed@@UAEIPAVGInterfaceStatus@@PAVVillager@@@Z @ 0x005052a0

undefined4
_GetDiscipleStateIfInteractedWith_MultiMapFixed__UAEIPAVGInterfaceStatus__PAVVillager___Z
          (int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x48))();
  if ((iVar1 == 0) || (*(int *)(iVar1 + 0x5f4) == 0)) {
    iVar2 = (**(code **)(*param_1 + 0x1c))();
    iVar3 = (**(code **)(*param_2 + 0x1c))();
    if (iVar2 == iVar3) {
      iVar2 = (**(code **)(*param_1 + 0x1c))();
      iVar3 = (**(code **)(*in_ECX + 0x1c))();
      if (iVar3 == iVar2) {
        iVar1 = (**(code **)(*in_ECX + 0x890))();
        if ((iVar1 != 0) && (iVar1 = (**(code **)(*in_ECX + 0x88c))(), iVar1 != 0)) {
          return 0;
        }
        return 4;
      }
      if (iVar1 != 0) {
        return 7;
      }
    }
  }
  return 0;
}



// ?RemovePotFromStructure@MultiMapFixed@@UAEXPAVPotStructure@@@Z @ 0x00505330

void _RemovePotFromStructure_MultiMapFixed__UAEXPAVPotStructure___Z(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x74) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x74) + 0x118))(param_1);
  }
  return;
}



// ?AddResource@MultiMapFixed@@UAEIW4RESOURCE_TYPE@@IPAVGInterfaceStatus@@_NPBUMapCoords@@H@Z @ 0x00505350

undefined4
_AddResource_MultiMapFixed__UAEIW4RESOURCE_TYPE__IPAVGInterfaceStatus___NPBUMapCoords__H_Z
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x74) != (int *)0x0) {
    uVar1 = (**(code **)(**(int **)(in_ECX + 0x74) + 0x9c))
                      (param_1,param_2,param_3,param_4,param_5,0);
    return uVar1;
  }
  return 0;
}



// ?RemoveResource@MultiMapFixed@@UAEIEEE@Z @ 0x00505390

undefined4
_RemoveResource_MultiMapFixed__UAEIEEE_Z
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x74) != (int *)0x0) {
    uVar1 = (**(code **)(**(int **)(in_ECX + 0x74) + 0xa0))(param_1,param_2,param_3,param_4);
    return uVar1;
  }
  return 0;
}



// ?IsResourceStore@MultiMapFixed@@UAE_NW4RESOURCE_TYPE@@@Z @ 0x005053c0

undefined4 _IsResourceStore_MultiMapFixed__UAE_NW4RESOURCE_TYPE___Z(int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = 1;
  if ((param_1 != 1) || (*(int *)(in_ECX + 0x74) == 0)) {
    uVar1 = 0;
  }
  return uVar1;
}



// ?DoCreatureMimicAfterAddingResource@MultiMapFixed@@UAE_NW4RESOURCE_TYPE@@PAVGInterfaceStatus@@@Z @ 0x005053e0

undefined4
_DoCreatureMimicAfterAddingResource_MultiMapFixed__UAE_NW4RESOURCE_TYPE__PAVGInterfaceStatus___Z
          (int *param_1)

{
  int iVar1;
  int *in_ECX;
  int unaff_retaddr;
  undefined4 uVar2;
  undefined4 uVar3;
  
  iVar1 = (**(code **)(*in_ECX + 0x318))(0);
  if ((iVar1 != 0) && (unaff_retaddr == 1)) {
    uVar3 = 0;
    uVar2 = 7;
    (**(code **)(*param_1 + 0x1c))(param_1,7);
    FUN_004cb260(param_1,uVar2,in_ECX,uVar3);
    return 1;
  }
  return 0;
}



// ?Save@MultiMapFixed@@UAEIPAVGameOSFile@@@Z @ 0x00505420

undefined4 _Save_MultiMapFixed__UAEIPAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_Fixed__UAEIPAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x58),1,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x58) + 1;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90((byte *)(in_ECX + 0x5c),4,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x5c) + 4;
      }
    }
    FUN_00531bc0(*(undefined4 *)(in_ECX + 100));
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x74));
    return 1;
  }
  return 0;
}



// ?InteractsWithPhysicsObjects@MultiMapFixed@@UAE_NXZ @ 0x005055a0

undefined4 _InteractsWithPhysicsObjects_MultiMapFixed__UAE_NXZ(void)

{
  int *in_ECX;
  float10 fVar1;
  float10 fVar2;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 0x880))();
  fVar2 = (float10)(**(code **)(*in_ECX + 0x11c))();
  if (((float10)0.1 < fVar1) && ((float10)0.01 < fVar2)) {
    return 1;
  }
  return 0;
}



// ?DeleteObjectAndTakeResource@MultiMapFixed@@UAE_NPAVObject@@PAVGInterfaceStatus@@@Z @ 0x00505610

undefined4
_DeleteObjectAndTakeResource_MultiMapFixed__UAE_NPAVObject__PAVGInterfaceStatus___Z
          (undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x74) != 0) {
    FUN_005ecb70(param_1,param_2);
    return 1;
  }
  return 0;
}



// ?CreatureMustAvoid@MultiMapFixed@@UAE_NPAVCreature@@@Z @ 0x00505640

undefined4 _CreatureMustAvoid_MultiMapFixed__UAE_NPAVCreature___Z(int *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  int *in_ECX;
  float10 fVar3;
  float10 fVar4;
  
  fVar3 = (float10)(**(code **)(*in_ECX + 0x880))();
  if ((((float10)0.01 < fVar3) || (in_ECX[0x1d] == 0)) || (*(int *)(in_ECX[0x1d] + 0x24) != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (param_1 == (int *)0x0) {
    return 1;
  }
  if (bVar1) {
    fVar3 = (float10)(**(code **)(*in_ECX + 0x42c))();
    fVar4 = (float10)(**(code **)(*param_1 + 0x42c))();
    if (fVar4 * (float10)0.1 <= (float10)(float)fVar3) {
      return 1;
    }
  }
  uVar2 = FUN_005ea110();
  return uVar2;
}



// ?CreateCollideData@MultiMapFixed@@UAEXXZ @ 0x00505700

void _CreateCollideData_MultiMapFixed__UAEXXZ(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  FUN_00505870();
  iVar1 = FUN_00746d70(4,s_C__dev_black_Fixed_cpp_00b170e4,0x505);
  if (iVar1 != 0) {
    uVar2 = FUN_00782e40(*(undefined4 *)(in_ECX + 0x40));
    *(undefined4 *)(in_ECX + 0x78) = uVar2;
    return;
  }
  *(undefined4 *)(in_ECX + 0x78) = 0;
  return;
}



// ?CreateBuildingSite@MultiMapFixed@@UAE_NXZ @ 0x00505740

undefined4 * _CreateBuildingSite_MultiMapFixed__UAE_NXZ(void)

{
  undefined4 *puVar1;
  undefined4 in_ECX;
  
  puVar1 = (undefined4 *)FUN_004300a0(0x648,s_C__dev_black_Fixed_cpp_00b170e4,0x50b);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_00433fe0(in_ECX);
    *puVar1 = &vftable_StandardBuildingSite;
    puVar1[0x191] = 0;
    return puVar1;
  }
  return (undefined4 *)0x0;
}



// ?ReduceLife@MultiMapFixed@@UAEXMPAVGPlayer@@@Z @ 0x00505790

void _ReduceLife_MultiMapFixed__UAEXMPAVGPlayer___Z(float param_1,undefined4 param_2)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  
  iVar1 = (**(code **)(*in_ECX + 0x890))();
  if (iVar1 != 1) {
    fVar2 = (float10)(**(code **)(*in_ECX + 0x880))();
    if (fVar2 - (float10)param_1 <= (float10)0.0) {
      param_1 = 0.0;
    }
    else {
      fVar2 = (float10)(**(code **)(*in_ECX + 0x880))();
      param_1 = (float)(fVar2 - (float10)param_1);
    }
    FUN_00505020(param_1);
    if (param_1 == 0.0) {
      fVar2 = (float10)(**(code **)(*in_ECX + 0x11c))(param_2);
      _ReduceLife_Object__UAEMMPAVGPlayer___Z((float)fVar2,param_2);
    }
    (**(code **)(*in_ECX + 0x11c))();
    return;
  }
  _ReduceLife_Object__UAEMMPAVGPlayer___Z(param_1,param_2);
  return;
}



// ?Process@MultiMapFixed@@UAEIXZ @ 0x005058a0

undefined4 _Process_MultiMapFixed__UAEIXZ(void)

{
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x74) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x74) + 0x100))();
  }
  return 1;
}



// ?AsMultiMapFixed@MultiMapFixed@@UAEPAV1@XZ @ 0x00506e00

void _AsMultiMapFixed_MultiMapFixed__UAEPAV1_XZ(void)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  undefined4 uVar5;
  int *in_ECX;
  float10 fVar6;
  float fStack_10;
  float fStack_c;
  int *piStack_4;
  
  (**(code **)(*in_ECX + 0x538))();
  if (DAT_00bf1530 == 0) {
    FUN_0072bed0(s___data_football_l3d_00b1719c,&fStack_10);
    uVar5 = FUN_0079a330(fStack_10);
    FUN_0072c360(s___data_football_l3d_00b1719c,uVar5,fStack_10,0);
    DAT_00bf1530 = FUN_007632b0(uVar5,0);
    FUN_0079a3b0(uVar5);
  }
  (**(code **)(*(int *)in_ECX[0x10] + 0xf4))(0,0);
  fVar6 = (float10)(**(code **)(*in_ECX + 0x120))();
  fVar2 = (float)fVar6;
  fVar6 = (float10)(**(code **)(*in_ECX + 0x508))();
  fVar3 = (float)fVar6;
  iVar1 = *piStack_4;
  iVar4 = in_ECX[0x10];
  fStack_c = (float)piStack_4[1] * 0.00015258789;
  fStack_10 = (float)piStack_4[2];
  fVar6 = (float10)FUN_00761280(iVar4 + 0x50);
  fStack_10 = (float)(fVar6 + (float10)fStack_10);
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
    FUN_00402280();
    *(float *)(iVar4 + 0x38) = (float)iVar1 * 0.00015258789;
    *(float *)(iVar4 + 0x3c) = fStack_10;
    *(float *)(iVar4 + 0x40) = fStack_c;
    FUN_004f5f10(fVar3);
  }
  else {
    *(undefined4 *)(iVar4 + 0x40) = 0;
    *(undefined4 *)(iVar4 + 0x3c) = 0;
    *(undefined4 *)(iVar4 + 0x38) = 0;
    *(undefined4 *)(iVar4 + 0x30) = 0;
    *(undefined4 *)(iVar4 + 0x2c) = 0;
    *(undefined4 *)(iVar4 + 0x28) = 0;
    *(undefined4 *)(iVar4 + 0x20) = 0;
    *(undefined4 *)(iVar4 + 0x1c) = 0;
    *(undefined4 *)(iVar4 + 0x18) = 0;
    *(float *)(iVar4 + 0x34) = fVar2;
    *(float *)(iVar4 + 0x14) = fVar2;
    *(float *)(iVar4 + 0x24) = fVar2;
    *(float *)(iVar4 + 0x38) = (float)iVar1 * 0.00015258789 + *(float *)(iVar4 + 0x38);
    *(float *)(iVar4 + 0x3c) = fStack_10 + *(float *)(iVar4 + 0x3c);
    *(float *)(iVar4 + 0x40) = fStack_c + *(float *)(iVar4 + 0x40);
    FUN_004f5f10(fVar3);
  }
  *(float *)(iVar4 + 0x44) = fVar2;
  *(float *)(iVar4 + 0x48) = fVar3;
  (**(code **)(*(int *)in_ECX[0x10] + 0x80))();
  (**(code **)(*(int *)in_ECX[0x10] + 0x1e8))();
  (**(code **)(*in_ECX + 0x850))();
  FUN_00504d40();
  if (((*(byte *)(in_ECX + 9) & 4) == 0) && ((*(byte *)((int)in_ECX + 10) & 0x11) == 0)) {
    (**(code **)(*in_ECX + 0x544))();
  }
  _Draw_PlannedMultiMapFixed__QAEXXZ();
  return;
}



// ?UseFootpathIfNecessary@MultiMapFixed@@UAEXPAVLiving@@PBUMapCoords@@E@Z @ 0x0050ef30

void _UseFootpathIfNecessary_MultiMapFixed__UAEXPAVLiving__PBUMapCoords__E_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x74))();
  if (iVar1 != 0) {
    (**(code **)(*in_ECX + 0x74))(param_1,param_2,param_3);
    FUN_0050b120(param_1,param_2,param_3,in_ECX);
    return;
  }
  _UseFootpathIfNecessary_GameThingWithPos__QAEXPAVLiving__ABUMapCoords__E_Z
            (param_1,param_2,param_3);
  return;
}



// ?BuildBy@MultiMapFixed@@UAEXM@Z @ 0x0052e850

undefined4 _BuildBy_MultiMapFixed__UAEXM_Z(void)

{
  int *in_ECX;
  float10 fVar1;
  
  if ((*(byte *)(in_ECX + 0x16) & 2) != 2) {
    fVar1 = (float10)(**(code **)(*in_ECX + 0x880))();
    if ((float10)1.0 <= fVar1) {
      return 1;
    }
  }
  return 0;
}



// ?GetShowNeedsPos@MultiMapFixed@@UAEIKPAUMapCoords@@@Z @ 0x0052ead0

char * _GetShowNeedsPos_MultiMapFixed__UAEIKPAUMapCoords___Z(void)

{
  return s_MobileStatic__00b1a3a0;
}



// ?GetShowNeedsPos@MultiMapFixed@@UAEIKPAUMapCoords@@@Z @ 0x0052f010

char * _GetShowNeedsPos_MultiMapFixed__UAEIKPAUMapCoords___Z(void)

{
  return s_TownSpellIcon__00b1a4e8;
}



// ?GetShowNeedsPos@MultiMapFixed@@UAEIKPAUMapCoords@@@Z @ 0x0052f060

char * _GetShowNeedsPos_MultiMapFixed__UAEIKPAUMapCoords___Z(void)

{
  return s_TownCentreSpellIcon__00b1a4f8;
}



// ?IsBuildingWhichIsBeingBuilt@MultiMapFixed@@UAE_NPAVCreature@@@Z @ 0x006da830

undefined4 _IsBuildingWhichIsBeingBuilt_MultiMapFixed__UAE_NPAVCreature___Z(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x48))();
  if (iVar1 != 0) {
    piVar2 = (int *)(**(code **)(*in_ECX + 0x48))();
    uVar3 = (**(code **)(*piVar2 + 0x30c))();
    return uVar3;
  }
  return 0;
}



// ?DeleteObjectAndTakeResource@MultiMapFixed@@UAE_NPAVObject@@PAVGInterfaceStatus@@@Z @ 0x00702530

void _DeleteObjectAndTakeResource_MultiMapFixed__UAE_NPAVObject__PAVGInterfaceStatus___Z(void)

{
  int iVar1;
  int in_ECX;
  
  Creche_vf406(in_ECX + 0x14);
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x40) + 500))();
  if (iVar1 != 0) {
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x1e8))();
  }
  return;
}



// ?SetTown@MultiMapFixed@@UAEXPAVTown@@@Z @ 0x00703d70

undefined4 _SetTown_MultiMapFixed__UAEXPAVTown___Z(void)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  _Built_MultiMapFixed__UAE_NXZ();
  iVar1 = (**(code **)(*in_ECX + 0x1c))();
  for (iVar1 = *(int *)(iVar1 + 0x268); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x754)) {
    iVar2 = FUN_006cfdf0(in_ECX);
    if (iVar2 != 0) {
      FUN_006cec00(in_ECX);
    }
  }
  return 1;
}



// ?SetPower@MultiMapFixed@@UAEXM@Z @ 0x00704ea0

undefined4 _SetPower_MultiMapFixed__UAEXM_Z(void)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  
  if (((*(byte *)(in_ECX + 0x16) & 2) == 0) &&
     (fVar2 = (float10)(**(code **)(*in_ECX + 0x880))(), (float10)1.0 <= fVar2)) {
    for (iVar1 = in_ECX[0x38]; iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x110)) {
    }
    return 1;
  }
  return 0;
}



