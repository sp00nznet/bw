// Decompiled functions for class: TownDesireFlags
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetSaveType@TownDesireFlags@@UAEIXZ @ 0x0052ec40

undefined4 _GetSaveType_TownDesireFlags__UAEIXZ(void)

{
  return 0x4c;
}



// ?GetDebugText@TownDesireFlags@@UAEPADXZ @ 0x0052ec50

char * _GetDebugText_TownDesireFlags__UAEPADXZ(void)

{
  return s_TownDesireFlags__00b1a410;
}



// ?GetMesh@TownDesireFlags@@UBEHXZ @ 0x006a3030

undefined4 _GetMesh_TownDesireFlags__UBEHXZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x60);
}



// ?ToBeDeleted@TownDesireFlags@@UAEXH@Z @ 0x006d8580

void _ToBeDeleted_TownDesireFlags__UAEXH_Z(undefined4 param_1)

{
  _ToBeDeleted_Object__UAEXH_Z(param_1);
  return;
}



// ?Process@TownDesireFlags@@UAEIXZ @ 0x006d8590

undefined4 _Process_TownDesireFlags__UAEIXZ(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x58) = 0;
  return 1;
}



// ?Draw@TownDesireFlags@@UAEXXZ @ 0x006d85a0

void _Draw_TownDesireFlags__UAEXXZ(void)

{
  undefined4 *puVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  float *pfVar8;
  int in_ECX;
  float *pfVar9;
  float *pfVar10;
  float10 fVar11;
  float afStack_30 [12];
  
  if (*(int *)(in_ECX + 0x40) != 0) {
    *(undefined4 *)(*(int *)(in_ECX + 0x40) + 0x60) = 0x2d;
    *(undefined4 *)(*(int *)(in_ECX + 0x40) + 0x5c) = 0x2d;
  }
  iVar5 = FUN_006d88c0();
  fVar2 = *(float *)(in_ECX + 0x58);
  if (iVar5 == 0) {
    *(undefined4 *)(in_ECX + 0x80) = 0;
    *(float *)(in_ECX + 0x6c) = fVar2;
    *(undefined4 *)(in_ECX + 0x7c) = 0;
    *(float *)(in_ECX + 0x68) = fVar2;
    *(undefined4 *)(in_ECX + 0x94) = 0;
    *(float *)(in_ECX + 0x84) = fVar2;
    *(undefined4 *)(in_ECX + 0x90) = 0;
    *(undefined4 *)(in_ECX + 0x78) = 0;
    *(undefined4 *)(in_ECX + 0x8c) = 0;
    *(undefined4 *)(in_ECX + 0x74) = 0;
    *(undefined4 *)(in_ECX + 0x88) = 0;
    *(undefined4 *)(in_ECX + 0x70) = 0;
    return;
  }
  if (1.0 <= fVar2) {
    uVar6 = 0x3f800000;
  }
  else {
    uVar6 = *(undefined4 *)(in_ECX + 0x58);
  }
  *(undefined4 *)(in_ECX + 0x58) = uVar6;
  pfVar9 = (float *)(in_ECX + 0x68);
  FUN_00406240(uVar6,0,0x3f800000);
  fVar2 = (float)DAT_00dc8d20 * 0.001 + *(float *)(in_ECX + 0x7c);
  *(float *)(in_ECX + 0x7c) = fVar2;
  if (fVar2 < *(float *)(in_ECX + 0x80)) {
    fVar3 = fVar2 * fVar2 * 0.5;
    fVar4 = fVar2 * fVar3 * 0.33333334;
    *(float *)(in_ECX + 0x74) =
         fVar4 * *(float *)(in_ECX + 0x94) +
         fVar3 * *(float *)(in_ECX + 0x90) + fVar2 * *(float *)(in_ECX + 0x8c) +
         *(float *)(in_ECX + 0x88);
    *pfVar9 = fVar3 * *(float *)(in_ECX + 0x8c) +
              fVar4 * *(float *)(in_ECX + 0x90) +
              *(float *)(in_ECX + 0x88) * *(float *)(in_ECX + 0x7c) +
              fVar3 * fVar3 * 0.16666667 * *(float *)(in_ECX + 0x94) + *(float *)(in_ECX + 0x84);
  }
  else {
    *pfVar9 = *(float *)(in_ECX + 0x6c);
    *(undefined4 *)(in_ECX + 0x74) = *(undefined4 *)(in_ECX + 0x70);
    *(undefined4 *)(in_ECX + 0x78) = 0;
    *(undefined4 *)(in_ECX + 0x7c) = *(undefined4 *)(in_ECX + 0x80);
  }
  fVar2 = *pfVar9;
  iVar5 = *(int *)(in_ECX + 0x14);
  iVar7 = *(int *)(in_ECX + 0x18);
  FUN_00760fd0();
  FUN_0051f3d0();
  fVar4 = DAT_00d78bd8 - (float)iVar5 * 0.00015258789;
  fVar3 = DAT_00d78be0 - (float)iVar7 * 0.00015258789;
  FUN_00760fd0();
  fVar11 = (float10)fpatan((float10)fVar3,(float10)fVar4);
  FUN_0041dbb0((float)(fVar11 + (float10)1.5707964),0x3f800000);
  iVar5 = *(int *)(in_ECX + 0x40);
  puVar1 = (undefined4 *)(iVar5 + 0x50);
  FUN_0075fc20(iVar5 + 0x38,iVar5 + 0x4c,puVar1);
  uVar6 = FUN_0075d130(iVar5 + 0x38,*puVar1,iVar5 + 0x4c);
  *puVar1 = uVar6;
  iVar5 = FUN_006d8920();
  fVar4 = (1.0 - *(float *)(iVar5 + 0x14)) * 0.2;
  if (fVar2 < fVar4) {
    iVar5 = FUN_006d8920();
    fVar3 = *(float *)(iVar5 + 0x14);
    iVar7 = FUN_006d8920();
    iVar5 = *(int *)(in_ECX + 0x40);
    pfVar8 = (float *)(iVar5 + 0x14);
    fVar2 = (fVar2 - fVar3) / (fVar4 - *(float *)(iVar7 + 0x14));
    pfVar9 = pfVar8;
    pfVar10 = afStack_30;
    for (iVar7 = 0xc; iVar7 != 0; iVar7 = iVar7 + -1) {
      *pfVar10 = *pfVar9;
      pfVar9 = pfVar9 + 1;
      pfVar10 = pfVar10 + 1;
    }
    *pfVar8 = fVar2 * *pfVar8;
    *(float *)(iVar5 + 0x18) = fVar2 * *(float *)(iVar5 + 0x18);
    *(float *)(iVar5 + 0x1c) = fVar2 * *(float *)(iVar5 + 0x1c);
    *(float *)(iVar5 + 0x20) = fVar2 * *(float *)(iVar5 + 0x20);
    *(float *)(iVar5 + 0x24) = fVar2 * *(float *)(iVar5 + 0x24);
    *(float *)(iVar5 + 0x28) = fVar2 * *(float *)(iVar5 + 0x28);
    *(float *)(iVar5 + 0x2c) = fVar2 * *(float *)(iVar5 + 0x2c);
    *(float *)(iVar5 + 0x30) = fVar2 * *(float *)(iVar5 + 0x30);
    *(float *)(iVar5 + 0x34) = fVar2 * *(float *)(iVar5 + 0x34);
    FUN_005ed470();
    pfVar9 = afStack_30;
    pfVar10 = (float *)(*(int *)(in_ECX + 0x40) + 0x14);
    for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
      *pfVar10 = *pfVar9;
      pfVar9 = pfVar9 + 1;
      pfVar10 = pfVar10 + 1;
    }
    return;
  }
  FUN_005ed470();
  return;
}



// ?CallVirtualFunctionsForCreation@TownDesireFlags@@UAEXABUMapCoords@@@Z @ 0x006d8930

void _CallVirtualFunctionsForCreation_TownDesireFlags__UAEXABUMapCoords___Z(undefined4 param_1)

{
  int in_ECX;
  
  _CallVirtualFunctionsForCreation_Object__UAEXABUMapCoords___Z(param_1);
  (**(code **)(**(int **)(in_ECX + 0x40) + 0x78))();
  return;
}



// ?GetQueryFirstEnumText@TownDesireFlags@@UAE?AW4HELP_TEXT@@XZ @ 0x006d8a20

undefined4 _GetQueryFirstEnumText_TownDesireFlags__UAE_AW4HELP_TEXT__XZ(void)

{
  int iVar1;
  
  iVar1 = FUN_006d8920();
  return *(undefined4 *)(iVar1 + 0x7c);
}



// ?GetQueryLastEnumText@TownDesireFlags@@UAE?AW4HELP_TEXT@@XZ @ 0x006d8a30

undefined4 _GetQueryLastEnumText_TownDesireFlags__UAE_AW4HELP_TEXT__XZ(void)

{
  int iVar1;
  
  iVar1 = FUN_006d8920();
  return *(undefined4 *)(iVar1 + 0x80);
}



// ?GetFOVHelpMessageSet@TownDesireFlags@@UAEIXZ @ 0x006d8a50

undefined4 _GetFOVHelpMessageSet_TownDesireFlags__UAEIXZ(void)

{
  int iVar1;
  
  iVar1 = FUN_006d8920();
  return *(undefined4 *)(iVar1 + 0x88);
}



// ?GetFOVHelpCondition@TownDesireFlags@@UAEIXZ @ 0x006d8a60

undefined4 _GetFOVHelpCondition_TownDesireFlags__UAEIXZ(void)

{
  int iVar1;
  
  iVar1 = FUN_006d8920();
  return *(undefined4 *)(iVar1 + 0x8c);
}



// ?Save@TownDesireFlags@@UAEIAAVGameOSFile@@@Z @ 0x006d8a70

undefined4 _Save_TownDesireFlags__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_Object__UAEIPAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    FUN_00531bc0(*(undefined4 *)(in_ECX + 100));
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x54),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x54) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90((byte *)(in_ECX + 0x58),4,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x58) + 4;
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
      }
    }
    return 1;
  }
  return 0;
}



// ?Load@TownDesireFlags@@UAEIAAVGameOSFile@@@Z @ 0x006d8b90

undefined4 _Load_TownDesireFlags__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Load__6ObjectFR10GameOSFile(param_1);
  if (iVar1 != 0) {
    FUN_00531f30(in_ECX + 100);
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x54),4,0,unaff_EDI,unaff_EBP,unaff_ESI,unaff_EBX);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x54) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x58) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
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
    return 1;
  }
  return 0;
}



