// Decompiled functions for class: GStreetLantern
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetSaveType@GStreetLantern@@UAEIXZ @ 0x00531580

undefined4 _GetSaveType_GStreetLantern__UAEIXZ(void)

{
  return 0xfe;
}



// ?GetDebugText@GStreetLantern@@UAEPADXZ @ 0x00531590

char * _GetDebugText_GStreetLantern__UAEPADXZ(void)

{
  return s_GStreetLantern__00b1b318;
}



// ?CallVirtualFunctionsForCreation@GStreetLantern@@UAEXABUMapCoords@@@Z @ 0x006ca610

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _CallVirtualFunctionsForCreation_GStreetLantern__UAEXABUMapCoords___Z(void)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  float10 fVar3;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  int *piStack_4;
  
  piVar1 = (int *)FUN_005ecd90(0);
  in_ECX[0x10] = (int)piVar1;
  (**(code **)(*piVar1 + 0xf4))(0,0);
  piVar1 = piStack_4;
  piStack_4 = (int *)piStack_4[2];
  FUN_00760fd0();
  FUN_0041dbb0(0,0x3f800000);
  (**(code **)(*in_ECX + 0x850))();
  if (((*(byte *)(in_ECX + 9) & 4) == 0) && ((*(byte *)((int)in_ECX + 10) & 0x11) == 0)) {
    (**(code **)(*in_ECX + 0x544))();
  }
  piStack_4 = (int *)piVar1[2];
  fVar3 = (float10)FUN_00760fd0();
  fStack_10 = (float)(fVar3 + (float10)(float)piStack_4);
  fStack_14 = (float)*piVar1 * 0.00015258789;
  fStack_c = (float)piVar1[1] * 0.00015258789;
  iVar2 = FUN_0077cfc0(&fStack_14,in_ECX[0x16]);
  in_ECX[0x17] = iVar2;
  if ((*(byte *)((int)in_ECX + 10) & 1) == 0) {
    (**(code **)(*in_ECX + 0x42c))();
    iVar2 = FUN_006b5c80();
    in_ECX[0x18] = iVar2;
    FUN_006b5a00(_DAT_00cc16a8 & 0xff);
  }
  return;
}



// ?Draw@GStreetLantern@@UAEXXZ @ 0x006ca810

void _Draw_GStreetLantern__UAEXXZ(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 0x40);
  puVar1 = (undefined4 *)(iVar2 + 0x50);
  FUN_0075fc20(iVar2 + 0x38,iVar2 + 0x4c,puVar1);
  uVar3 = FUN_0075d130(iVar2 + 0x38,*puVar1,iVar2 + 0x4c);
  *puVar1 = uVar3;
  FUN_005ed470();
  return;
}



// ?ToBeDeleted@GStreetLantern@@UAEXH@Z @ 0x006ca850

void _ToBeDeleted_GStreetLantern__UAEXH_Z(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x60) = 0;
  iVar2 = DAT_00c22ca4;
  iVar3 = *(int *)(DAT_00c22ca4 + 0x201cf0);
  if (iVar3 == in_ECX) {
    *(int *)(DAT_00c22ca4 + 0x201cf0) = *(int *)(in_ECX + 0x54);
  }
  else {
    if (iVar3 == 0) goto LAB_006ca89f;
    while (iVar1 = *(int *)(iVar3 + 0x54), iVar1 != in_ECX) {
      iVar3 = iVar1;
      if (iVar1 == 0) {
        _ToBeDeleted_Object__UAEXH_Z(param_1);
        return;
      }
    }
    *(undefined4 *)(iVar3 + 0x54) = *(undefined4 *)(in_ECX + 0x54);
  }
  *(int *)(iVar2 + 0x201cf4) = *(int *)(iVar2 + 0x201cf4) + -1;
  *(undefined4 *)(in_ECX + 0x54) = 0;
LAB_006ca89f:
  _ToBeDeleted_Object__UAEXH_Z(param_1);
  return;
}



// ?SaveObject@GStreetLantern@@UAEIAAULHOSFile@@ABUMapCoords@@@Z @ 0x006ca8b0

undefined4
_SaveObject_GStreetLantern__UAEIAAULHOSFile__ABUMapCoords___Z(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  char *pcVar4;
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
  iVar2 = (*(int *)(in_ECX + 0x28) + -0xc5b5e0) / 300;
  uVar3 = FUN_005bf290(auStack_64);
  uVar3 = FUN_006ad590(0x50,uVar3,iVar2);
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



// ?Load@GStreetLantern@@UAEIAAVGameOSFile@@@Z @ 0x006ca980

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _Load_GStreetLantern__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Load__6ObjectFR10GameOSFile(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x58),4,0,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x58) + 4;
      if (DAT_00b19acc != 0) {
        iVar1 = FUN_0072be50();
        if (iVar1 == 3) {
          DAT_00b19acc = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (_DAT_00cc16a8 & 0xff) + 1;
      }
    }
    return 1;
  }
  return 0;
}



// ?Save@GStreetLantern@@UAEIAAVGameOSFile@@@Z @ 0x006caa30

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _Save_GStreetLantern__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_Object__UAEIPAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x58),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x58) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90(&DAT_00cc16a8,1,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (_DAT_00cc16a8 & 0xff) + 1;
      }
    }
    return 1;
  }
  return 0;
}



