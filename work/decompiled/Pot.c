// Decompiled functions for class: Pot
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetScriptObjectType@Pot@@UAEIXZ @ 0x00418150

undefined4 _GetScriptObjectType_Pot__UAEIXZ(void)

{
  return 0x10;
}



// ?Draw@Pot@@UAEXXZ @ 0x004f7f40

void _Draw_Pot__UAEXXZ(void)

{
  char cVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  if (in_ECX[0x1c] != 0) {
    cVar1 = (**(code **)(*in_ECX + 0x4a4))();
    if ((cVar1 != '\0') && (in_ECX[0x11] == 0)) {
      uVar2 = FUN_004f7f30();
      FUN_004f7f20();
      FUN_00768080(uVar2);
      FUN_005ed470();
      return;
    }
    _Draw_MobileObject__UAEXXZ();
  }
  return;
}



// ?DrawOutOfMap@Pot@@UAEX_N@Z @ 0x004f7f90

void _DrawOutOfMap_Pot__UAEX_N_Z(undefined4 param_1)

{
  uint *puVar1;
  char cVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  if (in_ECX[0x10] != 0) {
    puVar1 = (uint *)(in_ECX[0x10] + 8);
    *puVar1 = *puVar1 | 0x40;
  }
  if (in_ECX[0x1c] != 0) {
    cVar2 = (**(code **)(*in_ECX + 0x4a4))();
    if ((cVar2 == '\0') || (in_ECX[0x11] != 0)) {
      _DrawOutOfMap_Object__UAEX_N_Z(param_1);
    }
    else {
      uVar3 = FUN_004f7f30();
      FUN_004f7f20();
      FUN_00768080(uVar3);
      FUN_005ed470();
    }
  }
  if (in_ECX[0x10] != 0) {
    puVar1 = (uint *)(in_ECX[0x10] + 8);
    *puVar1 = *puVar1 & 0xffffffbf;
  }
  return;
}



// ?GetResourceType@Pot@@UAE?AW4RESOURCE_TYPE@@XZ @ 0x0052e8d0

undefined4 _GetResourceType_Pot__UAE_AW4RESOURCE_TYPE__XZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x68);
}



// ?IsPoisoned@Pot@@UAEIXZ @ 0x0052e8e0

byte _IsPoisoned_Pot__UAEIXZ(void)

{
  int in_ECX;
  
  return *(byte *)(in_ECX + 0x74) & 1;
}



// ?IsSpeedUp@Pot@@UAEIXZ @ 0x0052e8f0

uint _IsSpeedUp_Pot__UAEIXZ(void)

{
  int in_ECX;
  
  return (*(byte *)(in_ECX + 0x74) & 0x10) >> 4;
}



// ?SetPoisoned@Pot@@UAEXH@Z @ 0x0052e900

void _SetPoisoned_Pot__UAEXH_Z(byte param_1)

{
  int in_ECX;
  
  *(byte *)(in_ECX + 0x74) = (*(byte *)(in_ECX + 0x74) ^ param_1) & 1 ^ *(byte *)(in_ECX + 0x74);
  return;
}



// ?SetPoisonedResource@Pot@@UAEXW4RESOURCE_TYPE@@H@Z @ 0x0052e940

void _SetPoisonedResource_Pot__UAEXW4RESOURCE_TYPE__H_Z(undefined4 param_1,byte param_2)

{
  int in_ECX;
  
  *(byte *)(in_ECX + 0x74) = (*(byte *)(in_ECX + 0x74) ^ param_2) & 1 ^ *(byte *)(in_ECX + 0x74);
  return;
}



// ?IsAPotFromABuildingSite@Pot@@UAE_NXZ @ 0x0052e960

uint _IsAPotFromABuildingSite_Pot__UAE_NXZ(void)

{
  int in_ECX;
  
  return (*(byte *)(in_ECX + 0x74) & 8) >> 3;
}



// ?GetSaveType@Pot@@UAEIXZ @ 0x0052e970

undefined4 _GetSaveType_Pot__UAEIXZ(void)

{
  return 0x58;
}



// ?GetDebugText@Pot@@UAEPADXZ @ 0x0052e980

undefined * _GetDebugText_Pot__UAEPADXZ(void)

{
  return &DAT_00b1a38c;
}



// ?GetCreatureBeliefType@Pot@@UAEIXZ @ 0x005b8310

undefined4 _GetCreatureBeliefType_Pot__UAEIXZ(void)

{
  return 0x10;
}



// ?InteractsWithPhysicsObjects@Pot@@UAE_NXZ @ 0x00616c00

uint _InteractsWithPhysicsObjects_Pot__UAE_NXZ(void)

{
  uint uVar1;
  
  uVar1 = FUN_00618900();
  if (uVar1 != 0) {
    return uVar1 & 0xffffff00;
  }
  uVar1 = _InteractsWithPhysicsObjects_Object__UAE_NXZ();
  return uVar1;
}



// ?GetPhysicsConstantsType@Pot@@UAEIXZ @ 0x00616c20

undefined4 _GetPhysicsConstantsType_Pot__UAEIXZ(void)

{
  int iVar1;
  int in_ECX;
  
  if ((*(int **)(in_ECX + 0x28) != (int *)0x0) &&
     (iVar1 = (**(code **)(**(int **)(in_ECX + 0x28) + 0x2c))(), iVar1 == 0x143)) {
    return 5;
  }
  return 4;
}



// ?ToBeDeleted@Pot@@UAEXH@Z @ 0x00616e40

void _ToBeDeleted_Pot__UAEXH_Z(undefined4 param_1)

{
  FUN_00617370();
  _ToBeDeleted_MobileObject__UAEXH_Z(param_1);
  return;
}



// ?CallVirtualFunctionsForCreation@Pot@@UAEXABUMapCoords@@@Z @ 0x00616e60

void _CallVirtualFunctionsForCreation_Pot__UAEXABUMapCoords___Z(undefined4 param_1)

{
  int *in_ECX;
  
  _CallVirtualFunctionsForCreation_MobileObject__UAEXABUMapCoords___Z(param_1);
  (**(code **)(*(int *)in_ECX[0x10] + 0x80))();
  if ((in_ECX[10] + -0xc6d400) / 0x144 == 0xc) {
    (**(code **)(*(int *)in_ECX[0x10] + 0x90))();
    (**(code **)(*(int *)in_ECX[0x10] + 0x78))();
  }
  (**(code **)(*in_ECX + 0x85c))();
  return;
}



// ?AddResource@Pot@@UAEIW4RESOURCE_TYPE@@IPAVGInterfaceStatus@@_NPBUMapCoords@@H@Z @ 0x00616fc0

void _AddResource_Pot__UAEIW4RESOURCE_TYPE__IPAVGInterfaceStatus___NPBUMapCoords__H_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x8c))(param_1,param_2,param_4);
  return;
}



// ?JustAddResource@Pot@@UAEIW4RESOURCE_TYPE@@I_N@Z @ 0x00616fe0

int _JustAddResource_Pot__UAEIW4RESOURCE_TYPE__I_N_Z(undefined4 param_1,int param_2,char param_3)

{
  uint uVar1;
  char cVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  if (*(int *)(in_ECX[10] + 0x124) < 0x13) {
    uVar1 = *(uint *)(in_ECX[10] + 0x11c);
    if (uVar1 < (uint)(in_ECX[0x1c] + param_2)) {
      param_2 = uVar1 - in_ECX[0x1c];
    }
  }
  in_ECX[0x1c] = in_ECX[0x1c] + param_2;
  if ((param_3 == '\0') && (cVar2 = (**(code **)(*in_ECX + 0x4a4))(), cVar2 == '\0')) {
    uVar3 = 0;
  }
  else {
    uVar3 = 1;
  }
  (**(code **)(*in_ECX + 0x69c))(uVar3);
  (**(code **)(*in_ECX + 0x85c))();
  return param_2;
}



// ?JustGetResource@Pot@@UAEIW4RESOURCE_TYPE@@IPA_N@Z @ 0x006170c0

int _JustGetResource_Pot__UAEIW4RESOURCE_TYPE__IPA_N_Z
              (int param_1,undefined4 param_2,undefined1 *param_3)

{
  undefined1 uVar1;
  int iVar2;
  int *in_ECX;
  
  iVar2 = (**(code **)(*in_ECX + 0x690))();
  if (param_1 == iVar2) {
    if (param_3 != (undefined1 *)0x0) {
      uVar1 = (**(code **)(*in_ECX + 0x4a4))();
      *param_3 = uVar1;
    }
    return in_ECX[0x1c];
  }
  return 0;
}



// ?GetResource@Pot@@UAEIW4RESOURCE_TYPE@@@Z @ 0x00617100

void _GetResource_Pot__UAEIW4RESOURCE_TYPE___Z(undefined4 param_1)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x94))(param_1,0,0);
  return;
}



// ?RemoveResource@Pot@@UAEIW4RESOURCE_TYPE@@IPAVGInterfaceStatus@@PA_N@Z @ 0x00617120

void _RemoveResource_Pot__UAEIW4RESOURCE_TYPE__IPAVGInterfaceStatus__PA_N_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x90))(param_1,param_2,param_4);
  return;
}



// ?JustRemoveResource@Pot@@UAEIW4RESOURCE_TYPE@@IPA_N@Z @ 0x00617140

uint _JustRemoveResource_Pot__UAEIW4RESOURCE_TYPE__IPA_N_Z
               (undefined4 param_1,uint param_2,char *param_3)

{
  uint uVar1;
  int *in_ECX;
  
  uVar1 = in_ECX[0x1c];
  if (param_2 < uVar1) {
    in_ECX[0x1c] = uVar1 - param_2;
  }
  else {
    in_ECX[0x1c] = 0;
    FUN_00617370();
    *(byte *)(in_ECX + 0x1d) = *(byte *)(in_ECX + 0x1d) & 0xfe;
    param_2 = uVar1;
    if ((int *)in_ECX[0x11] != (int *)0x0) {
      (**(code **)(*(int *)in_ECX[0x11] + 0xc))(0);
      in_ECX[0x11] = 0;
    }
  }
  (**(code **)(*in_ECX + 0x85c))();
  if (param_3 != (char *)0x0) {
    *param_3 = '\x01' - ((*(byte *)(in_ECX + 0x1d) & 1) != 1);
  }
  return param_2;
}



// ?SaveObject@Pot@@UAEIAAULHOSFile@@ABUMapCoords@@@Z @ 0x00617220

int _SaveObject_Pot__UAEIAAULHOSFile__ABUMapCoords___Z(undefined4 param_1,int param_2)

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
  iVar3 = (**(code **)(*in_ECX + 0x860))();
  if (iVar3 != 0) {
    return 0;
  }
  iVar3 = in_ECX[10];
  uVar4 = (**(code **)(*in_ECX + 0x690))(in_ECX[0x1c]);
  iVar3 = (iVar3 + -0xc6d400) / 0x144;
  uVar5 = FUN_005bf290(auStack_64);
  uVar4 = FUN_006ad590(0x26,uVar5,iVar3,uVar4);
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



// ?IsEffectReceiver@Pot@@UAEIPAVEffectValues@@@Z @ 0x00617320

bool _IsEffectReceiver_Pot__UAEIPAVEffectValues___Z(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0x70) != 0;
}



// ?EndOnFire@Pot@@UAEXXZ @ 0x006173a0

void _EndOnFire_Pot__UAEXXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x2c))();
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*in_ECX + 0x860))();
    if (((iVar1 == 0) && (in_ECX[0x1c] != 0)) && ((*(uint *)(DAT_00c22ca4 + 0x14) & 0x8000) == 0)) {
      FUN_00617330();
    }
  }
  return;
}



// ?InterfaceSetInMagicHand@Pot@@UAEIPAVGInterfaceStatus@@@Z @ 0x006173e0

void _InterfaceSetInMagicHand_Pot__UAEIPAVGInterfaceStatus___Z(undefined4 param_1)

{
  FUN_00617370();
  _NetworkFriendlyStartLockedSelect_Fixed__UAE_NPAVGInterfaceStatus___Z(param_1);
  return;
}



// ?Save@Pot@@UAEIAAVGameOSFile@@@Z @ 0x00617400

undefined4 _Save_Pot__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_MobileObject__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x68),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x68) + 4;
    }
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x6c));
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x70),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x70) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90((byte *)(in_ECX + 0x74),1,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x74) + 1;
      }
    }
    return 1;
  }
  return 0;
}



// ?Load@Pot@@UAEIAAVGameOSFile@@@Z @ 0x006174f0

undefined4 _Load_Pot__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Load_MobileObject__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x68),4,0,unaff_EBX,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x68) + 4;
    }
    FUN_00531f30();
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x70) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x74) + 1;
    }
    return 1;
  }
  return 0;
}



// ?EndPhysics@Pot@@UAEXPAVPhysicsObject@@_N@Z @ 0x006178a0

void _EndPhysics_Pot__UAEXPAVPhysicsObject___N_Z(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  if ((char)param_2 != '\0') {
    iVar2 = (in_ECX[10] + -0xc6d400) / 0x144;
    if ((iVar2 == 0xc) || (iVar2 == 0xb)) {
      iVar2 = FUN_005bfb00();
      if (iVar2 == 0) {
        FUN_00617330();
        iVar2 = *in_ECX;
        uVar1 = *(undefined4 *)(param_1 + 0x24);
        uVar3 = (**(code **)(iVar2 + 0x4a4))(0);
        uVar3 = (**(code **)(iVar2 + 0x690))(uVar3);
        uVar3 = (**(code **)(iVar2 + 0x98))(uVar3);
        uVar3 = (**(code **)(*in_ECX + 0x690))(uVar3);
        FUN_00618e10(in_ECX + 5,uVar1,uVar3);
        FUN_005a5fa0();
        (**(code **)(*in_ECX + 0xc))(0);
        return;
      }
    }
  }
  _EndPhysics_Object__UAEXPAVPhysicsObject___N_Z(param_1,param_2);
  return;
}



// ?ReactToPhysicsImpact@Pot@@UAEXPAVPhysicsObject@@_N@Z @ 0x00617960

void _ReactToPhysicsImpact_Pot__UAEXPAVPhysicsObject___N_Z(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *in_ECX;
  
  piVar1 = (int *)FUN_005f3c50();
  if (((piVar1 == (int *)0x0) || (iVar2 = (**(code **)(*piVar1 + 0x2c))(), iVar2 != 1)) ||
     (iVar2 = (**(code **)(*in_ECX + 0x2c))(), iVar2 != 1)) goto LAB_006179e3;
  iVar2 = *piVar1;
  uVar3 = (**(code **)(*in_ECX + 0x690))();
  iVar2 = (**(code **)(iVar2 + 0x680))(uVar3);
  if (iVar2 == 0) {
    iVar2 = (**(code **)(*piVar1 + 0x4b4))();
    if (iVar2 == 0) goto LAB_006179e3;
    iVar2 = (**(code **)(*piVar1 + 0x690))();
    iVar4 = (**(code **)(*in_ECX + 0x690))();
    if (iVar2 != iVar4) goto LAB_006179e3;
  }
  iVar2 = (**(code **)(*piVar1 + 0x684))();
  if (iVar2 != 0) {
    return;
  }
LAB_006179e3:
  _ReactToPhysicsImpact_MobileObject__UAEXPAVPhysicsObject___N_Z(param_1,param_2);
  return;
}



// ?DeleteObjectAndTakeResource@Pot@@UAE_NPAVObject@@PAVGInterfaceStatus@@@Z @ 0x00617a00

undefined4
_DeleteObjectAndTakeResource_Pot__UAE_NPAVObject__PAVGInterfaceStatus___Z
          (undefined4 param_1,undefined4 param_2)

{
  FUN_005ecb70(param_1,param_2);
  return 1;
}



// ?ValidToApplyThisToObject@Pot@@UAEIPAVGInterfaceStatus@@PAVObject@@@Z @ 0x00617a20

undefined4
_ValidToApplyThisToObject_Pot__UAEIPAVGInterfaceStatus__PAVObject___Z
          (undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *in_ECX;
  
  if (param_2 != (int *)0x0) {
    iVar2 = *param_2;
    uVar1 = (**(code **)(*in_ECX + 0x690))();
    iVar2 = (**(code **)(iVar2 + 0x680))(uVar1);
    if (iVar2 != 0) {
      return 1;
    }
  }
  piVar3 = (int *)FUN_007344da(param_2,0,&Object::RTTI_Type_Descriptor,&Pot::RTTI_Type_Descriptor,0)
  ;
  if (piVar3 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar3 + 0x690))();
    iVar4 = (**(code **)(*in_ECX + 0x690))();
    if (iVar2 == iVar4) {
      return 1;
    }
  }
  return 0;
}



// ?ApplyThisToObject@Pot@@UAEIPAVGInterfaceStatus@@PAVObject@@PAUGestureSystemPacketData@@@Z @ 0x00617aa0

byte _ApplyThisToObject_Pot__UAEIPAVGInterfaceStatus__PAVObject__PAUGestureSystemPacketData___Z
               (undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  undefined4 unaff_retaddr;
  
  if (param_2 != (int *)0x0) {
    iVar2 = *param_2;
    uVar1 = (**(code **)(*in_ECX + 0x690))();
    iVar2 = (**(code **)(iVar2 + 0x680))(uVar1);
    if (iVar2 != 0) {
      iVar2 = (**(code **)(*param_2 + 0x684))();
      return -(iVar2 != 0) & 3;
    }
  }
  iVar2 = *in_ECX;
  uVar1 = (**(code **)(iVar2 + 0x4a4))(0);
  uVar1 = (**(code **)(iVar2 + 0x690))(uVar1);
  uVar1 = (**(code **)(iVar2 + 0x98))(uVar1);
  uVar1 = (**(code **)(*in_ECX + 0x690))(uVar1);
  FUN_00618e10(in_ECX + 5,unaff_retaddr,uVar1);
  FUN_005a5fa0();
  (**(code **)(*in_ECX + 0xc))(0);
  return 3;
}



// ?ApplyThisToMapCoord@Pot@@UAEIPAVGInterfaceStatus@@ABUMapCoords@@PAUGestureSystemPacketData@@@Z @ 0x00617b40

undefined4
_ApplyThisToMapCoord_Pot__UAEIPAVGInterfaceStatus__ABUMapCoords__PAUGestureSystemPacketData___Z
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
  iVar3 = FUN_0067fa90();
  if ((iVar3 == 0) && (*(int *)(in_ECX[10] + 0x128) != -1)) {
    FUN_00617330();
  }
  uVar2 = _ApplyThisToMapCoord_Mobile__UAEIPAVGInterfaceStatus__ABUMapCoords__PAUGestureSystemPacketData___Z
                    (param_1,param_2,param_3);
  return uVar2;
}



// ?InitialisePhysicsFromHand@Pot@@UAEIAAULHPoint@@0PAVGInterfaceStatus@@PAVObject@@H@Z @ 0x00617bd0

undefined4
_InitialisePhysicsFromHand_Pot__UAEIAAULHPoint__0PAVGInterfaceStatus__PAVObject__H_Z
          (float *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  if (*param_1 * *param_1 + param_1[1] * param_1[1] + param_1[2] * param_1[2] <= 5.0) {
    uVar2 = (**(code **)(*in_ECX + 0x4a4))(0x3f400000);
    uVar2 = (**(code **)(*in_ECX + 0x690))(uVar2);
    FUN_00637cc0(param_3,uVar2);
    iVar1 = *in_ECX;
    uVar2 = (**(code **)(iVar1 + 0x4a4))(0);
    uVar2 = (**(code **)(iVar1 + 0x690))(uVar2);
    uVar2 = (**(code **)(iVar1 + 0x98))(uVar2);
    uVar2 = (**(code **)(*in_ECX + 0x690))(uVar2);
    FUN_00618e10(in_ECX + 5,param_3,uVar2);
    FUN_005a5fa0();
    (**(code **)(*in_ECX + 0xc))(0);
    return 0;
  }
  uVar2 = _InitialisePhysicsFromHand_Object__UAEIPAULHPoint__0PAVGInterfaceStatus__PAV1_H_Z
                    (param_1,param_2,param_3,param_4,param_5);
  return uVar2;
}



// ?CanBecomeAPhysicsObject@Pot@@UAE_NXZ @ 0x006184f0

undefined4 _CanBecomeAPhysicsObject_Pot__UAE_NXZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x28) + 300);
}



// ?GetRadiusMultiplierForApplyingPotToPos@Pot@@UAEMXZ @ 0x006190c0

float10 _GetRadiusMultiplierForApplyingPotToPos_Pot__UAEMXZ(void)

{
  return (float10)2.0;
}



// ?GetOverwriteInteractableToolTip@Pot@@UAEIXZ @ 0x006190d0

int _GetOverwriteInteractableToolTip_Pot__UAEIXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x480))();
  return 0xefe - (uint)(iVar1 != 0);
}



// ?GetFoodValue@Pot@@UAEMW4FOOD_TYPE@@@Z @ 0x006190f0

float10 _GetFoodValue_Pot__UAEMW4FOOD_TYPE___Z(void)

{
  uint uVar1;
  int *in_ECX;
  
  uVar1 = (**(code **)(*in_ECX + 0x98))(0);
  return (float10)uVar1;
}



// ?GetGuidanceResourceType@Pot@@UAEIXZ @ 0x006b3430

int _GetGuidanceResourceType_Pot__UAEIXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x690))();
  if (iVar1 == 0) {
    return 1;
  }
  iVar1 = (**(code **)(*in_ECX + 0x690))();
  return (-(uint)(iVar1 != 1) & 0xfffffffe) + 2;
}



