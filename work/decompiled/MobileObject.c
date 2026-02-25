// Decompiled functions for class: MobileObject
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetMesh@MobileObject@@UBEHXZ @ 0x0041cc20

void _GetMesh_MobileObject__UBEHXZ(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0041cc25. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x28) + 0x2c))();
  return;
}



// ?GetZAngle@MobileObject@@UAEMXZ @ 0x0041fe90

float10 _GetZAngle_MobileObject__UAEMXZ(void)

{
  int in_ECX;
  
  return (float10)*(float *)(in_ECX + 0x60);
}



// ?GetCreatureMimicType@MobileObject@@UAEIXZ @ 0x0041fea0

undefined4 _GetCreatureMimicType_MobileObject__UAEIXZ(void)

{
  return 8;
}



// ?CanBeUsedToHoldWater@MobileObject@@UAEIPAVCreature@@@Z @ 0x0041feb0

bool _CanBeUsedToHoldWater_MobileObject__UAEIPAVCreature___Z(void)

{
  int in_ECX;
  
  return *(int *)(*(int *)(in_ECX + 0x28) + 0x104) == 6;
}



// ?GetSaveType@MobileObject@@UAEIXZ @ 0x0041fed0

undefined4 _GetSaveType_MobileObject__UAEIXZ(void)

{
  return 0x53;
}



// ?GetDebugText@MobileObject@@UAEPADXZ @ 0x0041fee0

char * _GetDebugText_MobileObject__UAEPADXZ(void)

{
  return s_MobileObject__008f8434;
}



// ?IsMushroom@MobileObject@@UAEIPAVCreature@@@Z @ 0x004c5fe0

undefined4 _IsMushroom_MobileObject__UAEIPAVCreature___Z(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(*(int *)(in_ECX + 0x28) + 0x104);
  if ((iVar1 != 0x13) && (iVar1 != 0x12)) {
    return 0;
  }
  return 1;
}



// ?Draw@MobileObject@@UAEXXZ @ 0x004f4790

void _Draw_MobileObject__UAEXXZ(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
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



// ?RemoveMapObjectFromCell@MobileObject@@UAEXPAUMapCell@@@Z @ 0x00505600

void _RemoveMapObjectFromCell_MobileObject__UAEXPAUMapCell___Z(undefined4 param_1)

{
  _RemoveMapObjectFromCell_Object__UAEXPAUMapCell___Z(param_1);
  return;
}



// ?ToBeDeleted@MobileObject@@UAEXH@Z @ 0x005c23e0

void _ToBeDeleted_MobileObject__UAEXH_Z(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int in_ECX;
  
  iVar4 = DAT_00c22ca4;
  piVar1 = (int *)(DAT_00c22ca4 + 0x201ca0);
  piVar6 = (int *)*piVar1;
  piVar5 = (int *)0x0;
  iVar3 = DAT_00c22ca4;
  while (piVar2 = piVar5, piVar5 = piVar6, DAT_00c22ca4 = iVar3, piVar5 != (int *)0x0) {
    piVar6 = (int *)*piVar5;
    if (piVar5[1] == in_ECX) {
      if (piVar5 == (int *)*piVar1) {
        *piVar1 = (int)piVar6;
      }
      else {
        *piVar2 = (int)piVar6;
      }
      *(int *)(iVar4 + 0x201ca4) = *(int *)(iVar4 + 0x201ca4) + -1;
      FUN_007290de(piVar5);
      piVar5 = piVar2;
      iVar3 = DAT_00c22ca4;
    }
  }
  piVar6 = *(int **)(iVar3 + 0x201d90);
  piVar1 = (int *)(iVar3 + 0x201d90);
  if (piVar6 != (int *)0x0) {
    while (piVar6[1] != in_ECX) {
      piVar6 = (int *)*piVar6;
      if (piVar6 == (int *)0x0) {
        _ToBeDeleted_Object__UAEXH_Z(param_1);
        return;
      }
    }
    piVar6 = (int *)*piVar1;
    piVar5 = (int *)0x0;
    while (piVar2 = piVar5, piVar5 = piVar6, piVar5 != (int *)0x0) {
      piVar6 = (int *)*piVar5;
      if (piVar5[1] == in_ECX) {
        if (piVar5 == (int *)*piVar1) {
          *piVar1 = (int)piVar6;
        }
        else {
          *piVar2 = (int)piVar6;
        }
        *(int *)(iVar3 + 0x201d94) = *(int *)(iVar3 + 0x201d94) + -1;
        FUN_007290de(piVar5);
        piVar5 = piVar2;
      }
    }
  }
  _ToBeDeleted_Object__UAEXH_Z(param_1);
  return;
}



// ?GetHoldLoweringMultiplier@MobileObject@@UAEMXZ @ 0x005c2600

float10 _GetHoldLoweringMultiplier_MobileObject__UAEMXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x58c))();
  if (iVar1 == 6) {
    return (float10)0.7;
  }
  return (float10)-0.3;
}



// ?CallVirtualFunctionsForCreation@MobileObject@@UAEXABUMapCoords@@@Z @ 0x005c2620

void _CallVirtualFunctionsForCreation_MobileObject__UAEXABUMapCoords___Z(void)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  
  (**(code **)(*in_ECX + 0x538))();
  (**(code **)(*in_ECX + 0x850))();
  (**(code **)(*in_ECX + 0x608))();
  (**(code **)(*(int *)in_ECX[0x10] + 0xf4))(0,0);
  iVar1 = (**(code **)(*(int *)in_ECX[0x10] + 0xf8))();
  *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) | 0x4000;
  fVar2 = (float10)(**(code **)(*in_ECX + 0x120))();
  fVar5 = (float)fVar2;
  fVar2 = (float10)(**(code **)(*in_ECX + 0x50c))(fVar5);
  fVar4 = (float)fVar2;
  fVar2 = (float10)(**(code **)(*in_ECX + 0x508))(fVar4);
  fVar3 = (float)fVar2;
  fVar2 = (float10)(**(code **)(*in_ECX + 0x504))(fVar3);
  FUN_005ed520((float)fVar2,fVar3,fVar4,fVar5);
  if (((*(byte *)(in_ECX + 9) & 4) == 0) && ((*(byte *)((int)in_ECX + 10) & 0x11) == 0)) {
    (**(code **)(*in_ECX + 0x544))();
  }
  return;
}



// ?SaveObject@MobileObject@@UAEIAAULHOSFile@@ABUMapCoords@@@Z @ 0x005c26f0

int _SaveObject_MobileObject__UAEIAAULHOSFile__ABUMapCoords___Z(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *piVar5;
  int *in_ECX;
  int iVar6;
  char *pcVar7;
  TypeDescriptor *pTVar8;
  TypeDescriptor *pTVar9;
  undefined4 uVar10;
  undefined1 auStack_138 [12];
  char acStack_12c [200];
  undefined1 auStack_64 [100];
  
  iVar2 = FUN_0053eb80();
  if (iVar2 != 0) {
    if (param_2 != 0) {
      FUN_005c13b0(auStack_138,param_2);
    }
    if (in_ECX[0x16] != 0) {
      return 0;
    }
    (**(code **)(*in_ECX + 0x120))();
    (**(code **)(*in_ECX + 0x508))();
    iVar6 = in_ECX[10];
    uVar3 = __ftol();
    uVar3 = __ftol(uVar3);
    iVar6 = (iVar6 + -0xc59350) / 0x114;
    uVar4 = FUN_005bf290(auStack_64);
    uVar3 = FUN_006ad590(0x28,uVar4,iVar6,uVar3);
    FUN_00733e17(acStack_12c,uVar3);
    iVar6 = -1;
    pcVar7 = acStack_12c;
    do {
      if (iVar6 == 0) break;
      iVar6 = iVar6 + -1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    FUN_006b10c0();
    uVar10 = 0;
    pTVar9 = &MobileObject::RTTI_Type_Descriptor;
    pTVar8 = &Object::RTTI_Type_Descriptor;
    uVar4 = 0;
    uVar3 = FUN_005c0740(0x14,0);
    piVar5 = (int *)FUN_007344da(uVar3,uVar4,pTVar8,pTVar9,uVar10);
    while (piVar5 != (int *)0x0) {
      if ((((in_ECX[5] == piVar5[5]) && (in_ECX[6] == piVar5[6])) &&
          ((float)piVar5[7] == (float)in_ECX[7])) &&
         ((piVar5 != in_ECX && (in_ECX[10] == piVar5[10])))) {
        FUN_0053eb80();
      }
      uVar10 = 0;
      pTVar9 = &MobileObject::RTTI_Type_Descriptor;
      pTVar8 = &Object::RTTI_Type_Descriptor;
      uVar4 = 0;
      uVar3 = FUN_005c0740(0x14,piVar5);
      piVar5 = (int *)FUN_007344da(uVar3,uVar4,pTVar8,pTVar9,uVar10);
    }
  }
  return iVar2;
}



// ?GetCreatureBeliefType@MobileObject@@UAEIXZ @ 0x005c2890

undefined4 _GetCreatureBeliefType_MobileObject__UAEIXZ(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(*(int *)(in_ECX + 0x28) + 0x104);
  if (iVar1 == 4) {
    return 0xe;
  }
  if (iVar1 != 5) {
    return 0x13;
  }
  return 0xd;
}



// ?SetXYZAngles@MobileObject@@UAEXMMM@Z @ 0x005c28c0

void _SetXYZAngles_MobileObject__UAEXMMM_Z(int param_1,int param_2)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  undefined4 unaff_retaddr;
  
  iVar1 = (**(code **)(*in_ECX + 0x178))();
  if (iVar1 != 0) {
    (**(code **)(*in_ECX + 0x548))();
  }
  in_ECX[0x17] = param_1;
  (**(code **)(*in_ECX + 0x520))(param_2);
  in_ECX[0x18] = param_2;
  if (in_ECX[0x10] != 0) {
    fVar2 = (float10)(**(code **)(*in_ECX + 0x120))();
    FUN_005ed520(unaff_retaddr,param_2,param_2,(float)fVar2);
  }
  if (iVar1 != 0) {
    (**(code **)(*in_ECX + 0x544))();
  }
  return;
}



// ?SetXYZAnglesAndScale@MobileObject@@UAEXMMMM@Z @ 0x005c2940

void _SetXYZAnglesAndScale_MobileObject__UAEXMMMM_Z(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int *in_ECX;
  undefined4 unaff_EBX;
  
  iVar1 = (**(code **)(*in_ECX + 0x178))();
  if (iVar1 != 0) {
    (**(code **)(*in_ECX + 0x548))();
  }
  in_ECX[0x17] = param_1;
  (**(code **)(*in_ECX + 0x520))(param_2);
  in_ECX[0x18] = param_2;
  (**(code **)(*in_ECX + 0x51c))(param_3);
  if (in_ECX[0x10] != 0) {
    FUN_005ed520(unaff_EBX,param_2,param_1,param_3);
  }
  if (iVar1 != 0) {
    (**(code **)(*in_ECX + 0x544))();
  }
  return;
}



// ?GetWorldMatrix@MobileObject@@UAEXPAULHMatrix@@@Z @ 0x005c29c0

void _GetWorldMatrix_MobileObject__UAEXPAULHMatrix___Z(float *param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  int *in_ECX;
  float10 fVar4;
  float10 fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  
  fVar3 = (float)in_ECX[7];
  fVar4 = (float10)FUN_00760fd0();
  iVar1 = in_ECX[5];
  iVar2 = in_ECX[6];
  fVar5 = (float10)(**(code **)(*in_ECX + 0x120))();
  fVar8 = (float)fVar5;
  if (fVar5 != (float10)1.0) {
    fVar5 = (float10)(**(code **)(*in_ECX + 0x50c))();
    fVar7 = (float)fVar5;
    fVar5 = (float10)(**(code **)(*in_ECX + 0x504))(fVar7);
    fVar6 = (float)fVar5;
    fVar5 = (float10)(**(code **)(*in_ECX + 0x508))(fVar6);
    FUN_007592f0((float)fVar5,fVar6,fVar7);
    *param_1 = fVar8 * *param_1;
    param_1[9] = (float)iVar1 * 0.00015258789;
    param_1[10] = (float)(fVar4 + (float10)fVar3);
    param_1[0xb] = (float)iVar2 * 0.00015258789;
    param_1[1] = fVar8 * param_1[1];
    param_1[2] = fVar8 * param_1[2];
    param_1[3] = fVar8 * param_1[3];
    param_1[4] = fVar8 * param_1[4];
    param_1[5] = fVar8 * param_1[5];
    param_1[6] = fVar8 * param_1[6];
    param_1[7] = fVar8 * param_1[7];
    param_1[8] = fVar8 * param_1[8];
    return;
  }
  fVar5 = (float10)(**(code **)(*in_ECX + 0x50c))();
  fVar8 = (float)fVar5;
  fVar5 = (float10)(**(code **)(*in_ECX + 0x504))(fVar8);
  fVar7 = (float)fVar5;
  fVar5 = (float10)(**(code **)(*in_ECX + 0x508))(fVar7);
  FUN_007592f0((float)fVar5,fVar7,fVar8);
  param_1[9] = (float)iVar1 * 0.00015258789;
  param_1[10] = (float)(fVar4 + (float10)fVar3);
  param_1[0xb] = (float)iVar2 * 0.00015258789;
  return;
}



// ?MoveAlongPath@MobileObject@@UAEIXZ @ 0x005c2bf0

undefined4 _MoveAlongPath_MobileObject__UAEIXZ(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  float fVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int *in_ECX;
  float10 fVar8;
  undefined4 uVar9;
  
  iVar2 = in_ECX[0x19];
  if (*(int *)(iVar2 + 0x20) == 0) {
    iVar2 = *(int *)(iVar2 + 0x14);
    __ftol();
    FUN_0079aca0();
    if (&stack0x00000000 == &DAT_00000024) goto LAB_005c2cbb;
    uVar9 = **(undefined4 **)(iVar2 + 4);
  }
  else {
    __ftol();
    iVar2 = *(int *)(iVar2 + 0x14);
    FUN_0079aca0();
    if (&stack0x00000000 == &DAT_00000024) goto LAB_005c2cbb;
    uVar9 = **(undefined4 **)(iVar2 + 4);
  }
  FUN_0079a7b0(uVar9);
LAB_005c2cbb:
  iVar2 = in_ECX[0x19];
  fVar8 = (float10)FUN_005c2dc0();
  iVar6 = DAT_00c22ca4;
  if (fVar8 < (float10)*(float *)(iVar2 + 0x1c)) {
    *(float *)(iVar2 + 0x24) = *(float *)(iVar2 + 0x28) + *(float *)(iVar2 + 0x24);
    iVar2 = in_ECX[0x19];
    fVar4 = (float)*(int *)(*(int *)(*(int *)(*(int *)(iVar2 + 0x14) + 4) + 0x208) + 0x10);
    if (fVar4 < *(float *)(iVar2 + 0x24)) {
      *(float *)(iVar2 + 0x24) = fVar4;
    }
    __ftol();
    __ftol();
    (**(code **)(*in_ECX + 0xfc))();
    FUN_005ed520(0,0,0);
    return 1;
  }
  piVar1 = (int *)(DAT_00c22ca4 + 0x201d90);
  piVar3 = *(int **)(DAT_00c22ca4 + 0x201d90);
  piVar7 = (int *)0x0;
  while (piVar5 = piVar7, piVar7 = piVar3, piVar7 != (int *)0x0) {
    piVar3 = (int *)*piVar7;
    if ((int *)piVar7[1] == in_ECX) {
      if (piVar7 == (int *)*piVar1) {
        *piVar1 = (int)piVar3;
      }
      else {
        *piVar5 = (int)piVar3;
      }
      *(int *)(iVar6 + 0x201d94) = *(int *)(iVar6 + 0x201d94) + -1;
      FUN_007290de();
      piVar7 = piVar5;
    }
  }
  return 1;
}



// ?IsPoisoned@MobileObject@@UAEIXZ @ 0x005c2e00

bool _IsPoisoned_MobileObject__UAEIXZ(void)

{
  int in_ECX;
  
  return *(undefined **)(in_ECX + 0x28) == &DAT_00c5a7cc;
}



// ?GetPhysicsConstantsType@MobileObject@@UAEIXZ @ 0x005c2e10

undefined4 _GetPhysicsConstantsType_MobileObject__UAEIXZ(void)

{
  undefined *puVar1;
  undefined4 uVar2;
  int in_ECX;
  
  puVar1 = *(undefined **)(in_ECX + 0x28);
  if (puVar1 == &DAT_00c5a5a4) {
    return 0x15;
  }
  if (puVar1 == &DAT_00c5a6b8) {
    return 0x16;
  }
  if (puVar1 == &DAT_00c5a7cc) {
    return 0x17;
  }
  uVar2 = _GetPhysicsConstantsType_Object__UAEIXZ();
  return uVar2;
}



// ?ReactToPhysicsImpact@MobileObject@@UAEXPAVPhysicsObject@@_N@Z @ 0x005c2e40

void _ReactToPhysicsImpact_MobileObject__UAEXPAVPhysicsObject___N_Z(int param_1)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int *in_ECX;
  
  puVar1 = (undefined *)in_ECX[10];
  if (((puVar1 == &DAT_00c5a5a4) || (puVar1 == &DAT_00c5a6b8)) || (puVar1 == &DAT_00c5a7cc)) {
    piVar3 = (int *)FUN_005f3c50();
    iVar2 = *(int *)(param_1 + 0x20);
    if (piVar3 != (int *)0x0) {
      iVar5 = *piVar3;
      uVar4 = (**(code **)(*in_ECX + 0x690))();
      iVar5 = (**(code **)(iVar5 + 0x680))(uVar4);
      if (iVar5 != 0) {
        if (iVar2 != 0) {
          (**(code **)(*piVar3 + 0x684))();
          return;
        }
        (**(code **)(*piVar3 + 0x684))();
      }
    }
  }
  return;
}



// ?PhysicsEditorCreate@MobileObject@@UAEXH@Z @ 0x005c2ec0

void _PhysicsEditorCreate_MobileObject__UAEXH_Z(void)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  undefined4 *puStack_30;
  undefined4 *puStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  int aiStack_14 [2];
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_20 = 0x5c2ece;
  iVar2 = (**(code **)(*in_ECX + 0x7b0))();
  if (iVar2 != 0) {
    puVar1 = (undefined *)in_ECX[10];
    uStack_c = 0;
    uStack_8 = 0;
    uStack_4 = 0;
    if (((puVar1 == &DAT_00c5a5a4) || (puVar1 == &DAT_00c5a6b8)) || (puVar1 == &DAT_00c5a7cc)) {
      in_ECX[7] = 0;
    }
    else {
      uStack_20 = 0;
      uStack_24 = 1;
      uStack_28 = 0;
      puStack_2c = &uStack_c;
      puStack_30 = &uStack_c;
      piVar3 = (int *)(**(code **)(*in_ECX + 0x784))(aiStack_14);
      puStack_30 = (undefined4 *)*piVar3;
      if (puStack_30 != (undefined4 *)0x0) {
        if (aiStack_14[0] == 0) {
          FUN_0075b1b0(0,1);
        }
        FUN_005f3550(&puStack_30);
        return;
      }
    }
  }
  return;
}



// ?ValidToApplyThisToObject@MobileObject@@UAEIPAVGInterfaceStatus@@PAVObject@@@Z @ 0x005c2f70

undefined4
_ValidToApplyThisToObject_MobileObject__UAEIPAVGInterfaceStatus__PAVObject___Z
          (undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  
  if (param_2 != (int *)0x0) {
    iVar2 = *param_2;
    uVar1 = (**(code **)(*in_ECX + 0x690))();
    iVar2 = (**(code **)(iVar2 + 0x680))(uVar1);
    if ((iVar2 != 0) &&
       (((iVar2 = *(int *)(in_ECX[10] + 0x104), iVar2 == 0x11 || (iVar2 == 0x12)) || (iVar2 == 0x13)
        ))) {
      return 1;
    }
  }
  return 0;
}



// ?ApplyThisToObject@MobileObject@@UAEIPAVGInterfaceStatus@@PAVObject@@PAUGestureSystemPacketData@@@Z @ 0x005c2fc0

undefined4
_ApplyThisToObject_MobileObject__UAEIPAVGInterfaceStatus__PAVObject__PAUGestureSystemPacketData___Z
          (undefined4 param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 != (int *)0x0) {
    iVar1 = (**(code **)(*param_2 + 0x684))();
    if (iVar1 != 0) {
      return 3;
    }
  }
  return 0;
}



// ?GetDefaultResource@MobileObject@@UAEHXZ @ 0x005c2ff0

undefined4 _GetDefaultResource_MobileObject__UAEHXZ(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = *(int *)(*(int *)(in_ECX + 0x28) + 0x104);
  if (((iVar1 != 0x11) && (iVar1 != 0x12)) && (iVar1 != 0x13)) {
    return 0;
  }
  uVar2 = __ftol();
  return uVar2;
}



// ?GetResourceType@MobileObject@@UAE?AW4RESOURCE_TYPE@@XZ @ 0x005c3020

undefined4 _GetResourceType_MobileObject__UAE_AW4RESOURCE_TYPE__XZ(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(*(int *)(in_ECX + 0x28) + 0x104);
  if (((iVar1 != 0x11) && (iVar1 != 0x12)) && (iVar1 != 0x13)) {
    return 0xffffffff;
  }
  return 0;
}



// ?Save@MobileObject@@UAEIAAVGameOSFile@@@Z @ 0x005c3040

undefined4 _Save_MobileObject__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_Mobile__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x58));
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x5c),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x5c) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90((byte *)(in_ECX + 0x60),4,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x60) + 4;
      }
    }
    FUN_00531bc0(*(undefined4 *)(in_ECX + 100));
    return 1;
  }
  return 0;
}



// ?Load@MobileObject@@UAEIAAVGameOSFile@@@Z @ 0x005c3100

undefined4 _Load_MobileObject__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Load_Mobile__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    FUN_00531f30(in_ECX + 0x58);
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x5c),4,0,unaff_EDI,unaff_ESI,unaff_EBX);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x5c) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x60) + 4;
    }
    FUN_00531f30();
    return 1;
  }
  return 0;
}



// ?AddToRoutePlan@MobileObject@@UAEXPAURPHolder@@PAVCreature@@HP6AXHUPoint2D@@MH@Z@Z @ 0x006a45f0

void _AddToRoutePlan_MobileObject__UAEXPAURPHolder__PAVCreature__HP6AXHUPoint2D__MH_Z_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_005eaea0(param_1,param_2,param_3,param_4);
  return;
}



