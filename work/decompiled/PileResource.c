// Decompiled functions for class: PileResource
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?JustAddResource@PileResource@@UAEIW4RESOURCE_TYPE@@I_N@Z @ 0x00617060

void _JustAddResource_PileResource__UAEIW4RESOURCE_TYPE__I_N_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (*(int *)(in_ECX + 0x28) + -0xc6d400) / 0x144;
  if ((iVar1 != 0xc) && (iVar1 != 0xb)) {
    FUN_00616ed0(in_ECX + 0x14,param_1,param_2);
  }
  _JustAddResource_Pot__UAEIW4RESOURCE_TYPE__I_N_Z(param_1,param_2,param_3);
  return;
}



// ?CallVirtualFunctionsForCreation@PileResource@@UAEXABUMapCoords@@@Z @ 0x00617f90

void _CallVirtualFunctionsForCreation_PileResource__UAEXABUMapCoords___Z(undefined4 param_1)

{
  int *in_ECX;
  float10 fVar1;
  
  FUN_00617860(param_1);
  fVar1 = (float10)(**(code **)(*in_ECX + 0x42c))();
  fVar1 = -fVar1;
  in_ECX[0x22] = (int)(float)fVar1;
  in_ECX[0x21] = (int)(float)fVar1;
  in_ECX[0x27] = 0;
  in_ECX[0x28] = (int)(float)fVar1;
  in_ECX[0x26] = 0;
  in_ECX[0x2c] = 0;
  in_ECX[0x2b] = 0;
  in_ECX[0x25] = 0;
  in_ECX[0x2a] = 0;
  in_ECX[0x24] = 0;
  in_ECX[0x29] = 0;
  in_ECX[0x23] = 0;
  (**(code **)(*in_ECX + 0x85c))();
  return;
}



// ?CanBePickedUpByCreature@PileResource@@UAEIPAVCreature@@@Z @ 0x00618010

undefined4 _CanBePickedUpByCreature_PileResource__UAEIPAVCreature___Z(void)

{
  int iVar1;
  int *in_ECX;
  
  if ((*(byte *)((int)in_ECX + 0x25) & 0x20) == 0) {
    iVar1 = (**(code **)(*in_ECX + 0x7b0))();
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}



// ?GetLife@PileResource@@UAEMXZ @ 0x00618030

float10 _GetLife_PileResource__UAEMXZ(void)

{
  int in_ECX;
  
  return (float10)*(uint *)(in_ECX + 0x70) / (float10)*(int *)(*(int *)(in_ECX + 0x28) + 0x11c);
}



// ?SetLife@PileResource@@UAEXM@Z @ 0x00618060

void _SetLife_PileResource__UAEXM_Z(float param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  float10 fVar4;
  
  fVar4 = (float10)(**(code **)(*in_ECX + 0x11c))();
  if ((float10)param_1 < fVar4) {
    iVar2 = __ftol();
    if (iVar2 == 0) {
      iVar2 = 1;
    }
    iVar1 = *in_ECX;
    uVar3 = (**(code **)(iVar1 + 0x690))(iVar2,0,0);
    (**(code **)(iVar1 + 0xa0))(uVar3);
    return;
  }
  if (fVar4 < (float10)param_1) {
    iVar2 = __ftol();
    if (iVar2 == 0) {
      iVar2 = 1;
    }
    iVar1 = *in_ECX;
    uVar3 = (**(code **)(iVar1 + 0x4a4))(0,0);
    uVar3 = (**(code **)(*in_ECX + 0x690))(iVar2,0,uVar3);
    (**(code **)(iVar1 + 0x9c))(uVar3);
    return;
  }
  return;
}



// ?ValidForLockedSelectProcess@PileResource@@UAE_NPAVGInterfaceStatus@@@Z @ 0x00618150

bool _ValidForLockedSelectProcess_PileResource__UAE_NPAVGInterfaceStatus___Z(void)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  iVar1 = in_ECX[10];
  iVar2 = (**(code **)(*in_ECX + 0x870))();
  return (iVar1 + -0xc6d400) / 0x144 != iVar2;
}



// ?ProcessInInteract@PileResource@@UAEIPAVGInterfaceStatus@@@Z @ 0x00618180

undefined4 _ProcessInInteract_PileResource__UAEIPAVGInterfaceStatus___Z(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int *in_ECX;
  undefined1 uVar8;
  float10 fVar9;
  uint unaff_retaddr;
  
  uVar2 = FUN_0059c190();
  piVar3 = (int *)FUN_007344da(uVar2,0,&Object::RTTI_Type_Descriptor,&Pot::RTTI_Type_Descriptor,0);
  if ((piVar3 != (int *)0x0) && (piVar3 != in_ECX)) {
    iVar5 = piVar3[10];
    iVar4 = (**(code **)(*in_ECX + 0x870))();
    if ((iVar5 + -0xc6d400) / 0x144 == iVar4) {
      iVar5 = (**(code **)(*in_ECX + 0x690))();
      (**(code **)(*in_ECX + 0x870))();
      FUN_00616a60(*(undefined4 *)(param_1 + 0x40));
      cVar1 = (**(code **)(*piVar3 + 0x4a4))();
      if (iVar5 == 0) {
        uVar8 = cVar1 != '\0';
      }
      else {
        uVar8 = 2;
      }
      fVar9 = (float10)FUN_00616b10(*(undefined4 *)(param_1 + 0x40));
      FUN_00637b10(param_1,uVar8,(float)fVar9);
      uVar6 = (**(code **)(*in_ECX + 0x98))(iVar5);
      if (uVar6 <= unaff_retaddr) {
        unaff_retaddr = (**(code **)(*in_ECX + 0x98))(iVar5);
      }
      iVar4 = *(int *)(piVar3[10] + 0x13c);
      if (iVar4 != 0) {
        iVar7 = *piVar3;
        uVar2 = (**(code **)(iVar7 + 0x690))();
        iVar7 = (**(code **)(iVar7 + 0x98))(uVar2);
        uVar6 = (iVar4 - iVar7 < 0) - 1 & iVar4 - iVar7;
        if ((int)uVar6 < (int)unaff_retaddr) {
          unaff_retaddr = uVar6;
        }
      }
      if (unaff_retaddr != 0) {
        uVar2 = (**(code **)(*in_ECX + 0xa0))(iVar5,unaff_retaddr,param_1,&stack0x00000000);
        (**(code **)(*piVar3 + 0x9c))(iVar5,uVar2,param_1,iVar4,0,0);
        if ((*(byte *)((int)in_ECX + 10) & 1) != 0) {
          FUN_00637c30(param_1);
        }
        iVar5 = FUN_00667ed0();
        iVar4 = FUN_00527d30();
        if (iVar5 == iVar4) {
          FUN_0058ac80(0xeea,(float)(uint)piVar3[0x1c]);
        }
        return 1;
      }
      FUN_00637c30(param_1);
    }
  }
  return 0;
}



// ?NetworkFriendlyStartLockedSelect@PileResource@@UAE_NPAVGInterfaceStatus@@@Z @ 0x00618370

undefined4 _NetworkFriendlyStartLockedSelect_PileResource__UAE_NPAVGInterfaceStatus___Z(void)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  int *piVar7;
  int *in_ECX;
  undefined4 unaff_EDI;
  undefined1 uVar8;
  int unaff_retaddr;
  undefined1 *puVar9;
  char cVar10;
  char cStack_19;
  
  iVar2 = (**(code **)(*in_ECX + 0x690))();
  iVar3 = (**(code **)(*in_ECX + 0x870))();
  uVar5 = *(uint *)(&DAT_00c6d530 + iVar3 * 0x144);
  uVar4 = (**(code **)(*in_ECX + 0x98))();
  if (uVar4 <= uVar5) {
    uVar5 = (**(code **)(*in_ECX + 0x98))(iVar2);
  }
  if (uVar5 != 0) {
    puVar9 = &stack0xfffffff7;
    (**(code **)(*in_ECX + 0xa0))(iVar2,uVar5,unaff_retaddr,puVar9);
    cVar10 = (char)((uint)puVar9 >> 0x18);
    uVar6 = (**(code **)(*in_ECX + 0x48))(0,0,0x3f800000,0);
    piVar7 = (int *)FUN_00616c40(unaff_retaddr + 0x14,unaff_EDI,uVar5,0,uVar6);
    if (piVar7 != (int *)0x0) {
      cStack_19 = (char)((uint)iVar2 >> 0x18);
      if ((cStack_19 == '\0') && (cVar1 = (**(code **)(*piVar7 + 0x4a4))(), cVar1 == '\0')) {
        uVar6 = 0;
      }
      else {
        uVar6 = 1;
      }
      (**(code **)(*piVar7 + 0x69c))(uVar6);
      FUN_0059c850(piVar7);
      uVar6 = (**(code **)(*in_ECX + 0x1c))();
      *(undefined4 *)(unaff_retaddr + 0x128) = uVar6;
      if (iVar2 == 0) {
        uVar8 = cVar10 != '\0';
      }
      else {
        uVar8 = 2;
      }
      FUN_00637aa0(unaff_retaddr,in_ECX + 5,uVar8);
      return 1;
    }
    return 0;
  }
  return 0;
}



// ?NetworkUnfriendlyEndLockedSelect@PileResource@@UAEIXZ @ 0x00618490

undefined4 _NetworkUnfriendlyEndLockedSelect_PileResource__UAEIXZ(void)

{
  int iVar1;
  byte bVar2;
  int iVar3;
  undefined4 uVar4;
  int *in_ECX;
  
  bVar2 = *(byte *)(DAT_00c22ca4 + 0x201b15);
  iVar1 = DAT_00c22ca4 + 0x18;
  iVar3 = (**(code **)(*in_ECX + 0x1c))();
  if (iVar3 == iVar1 + (uint)bVar2 * 0x278) {
    FUN_00527d30();
    uVar4 = FUN_0059c190();
    FUN_007344da(uVar4,0,&Object::RTTI_Type_Descriptor,&Pot::RTTI_Type_Descriptor,0);
  }
  return 1;
}



// ?ValidForPlaceInHand@PileResource@@UAEIPAVGInterfaceStatus@@@Z @ 0x006188a0

bool _ValidForPlaceInHand_PileResource__UAEIPAVGInterfaceStatus___Z(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  
  iVar3 = in_ECX[10];
  iVar1 = (**(code **)(*in_ECX + 0x870))();
  if ((iVar3 + -0xc6d400) / 0x144 != iVar1) {
    return false;
  }
  uVar2 = (**(code **)(*in_ECX + 0x690))();
  iVar3 = (**(code **)(*in_ECX + 0x98))(uVar2);
  return iVar3 != 0;
}



// ?InterfaceSetInMagicHand@PileResource@@UAEIPAVGInterfaceStatus@@@Z @ 0x00618b30

undefined4 _InterfaceSetInMagicHand_PileResource__UAEIPAVGInterfaceStatus___Z(void)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int *in_ECX;
  float unaff_EBX;
  
  FUN_00617370();
  iVar4 = in_ECX[10];
  iVar2 = (**(code **)(*in_ECX + 0x870))();
  if ((iVar4 + -0xc6d400) / 0x144 == iVar2) {
    return 1;
  }
  uVar3 = (**(code **)(*in_ECX + 0x690))();
  iVar4 = (**(code **)(*in_ECX + 0x870))();
  FUN_006169b0();
  uVar5 = (**(code **)(*in_ECX + 0x98))(uVar3);
  if ((float)uVar5 <= unaff_EBX) {
    (**(code **)(*in_ECX + 0x98))(uVar3);
  }
  else {
    FUN_006169b0();
  }
  iVar2 = __ftol();
  if (iVar2 != 0) {
    (**(code **)(*in_ECX + 0xa0))(uVar3,iVar2,0,0);
    uVar3 = (**(code **)(*in_ECX + 0x48))(0,0,0x3f800000,0);
    piVar6 = (int *)FUN_00616c40(in_ECX + 5,&DAT_00c6d400 + iVar4 * 0x51,iVar2,0,uVar3);
    if (piVar6 != (int *)0x0) {
      cVar1 = (**(code **)(*piVar6 + 0x4a4))();
      if ((cVar1 == '\0') && (cVar1 = (**(code **)(*in_ECX + 0x4a4))(), cVar1 == '\0')) {
        uVar3 = 0;
      }
      else {
        uVar3 = 1;
      }
      (**(code **)(*piVar6 + 0x69c))(uVar3);
      FUN_0059c850(piVar6);
      return 0;
    }
    return 0;
  }
  return 0;
}



// ?Save@PileResource@@UAEIAAVGameOSFile@@@Z @ 0x006191a0

undefined4 _Save_PileResource__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_00617760(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x84),0x30,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x84) + 0x30;
    }
    return 1;
  }
  return 0;
}



// ?Load@PileResource@@UAEIAAVGameOSFile@@@Z @ 0x00619210

undefined4 _Load_PileResource__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = FUN_006177e0(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x84),0x30,0,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x84) + 0x30;
    }
    return 1;
  }
  return 0;
}



// ?IsPileResource@PileResource@@UAEIXZ @ 0x0067ac80

void _IsPileResource_PileResource__UAEIXZ(void)

{
  return;
}



