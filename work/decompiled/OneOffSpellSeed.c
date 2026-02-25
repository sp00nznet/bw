// Decompiled functions for class: OneOffSpellSeed
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?IsOneOffSpellBelongingToOtherPlayer@OneOffSpellSeed@@UAEIPAVCreature@@@Z @ 0x004c5e60

bool _IsOneOffSpellBelongingToOtherPlayer_OneOffSpellSeed__UAEIPAVCreature___Z(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_005bfd00();
  iVar2 = (**(code **)(*param_1 + 0x1c))();
  return iVar1 != iVar2;
}



// ?DrawOutOfMap@OneOffSpellSeed@@UAEX_N@Z @ 0x004f5270

void _DrawOutOfMap_OneOffSpellSeed__UAEX_N_Z(undefined4 param_1)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  float fVar10;
  float fVar11;
  float fVar12;
  undefined4 uVar13;
  int iVar14;
  float *pfVar15;
  int *in_ECX;
  float10 fVar16;
  float10 fVar17;
  undefined1 auStack_30 [48];
  
  if (in_ECX[0x10] != 0) {
    puVar1 = (uint *)(in_ECX[0x10] + 8);
    *puVar1 = *puVar1 | 0x40;
  }
  if (in_ECX[0x1c] != 0) {
    FUN_006c0fa0();
    FUN_004f4d40();
    piVar2 = (int *)in_ECX[0x10];
    iVar3 = piVar2[0xe];
    iVar4 = piVar2[0xf];
    iVar5 = piVar2[0x10];
    iVar14 = (**(code **)(*piVar2 + 0xf8))();
    iVar6 = in_ECX[0x10];
    pfVar15 = (float *)(iVar14 + 0x18);
    fVar7 = *pfVar15 * *(float *)(iVar6 + 0x14) +
            *(float *)(iVar6 + 0x2c) * *(float *)(iVar14 + 0x20) +
            *(float *)(iVar6 + 0x20) * *(float *)(iVar14 + 0x1c) + *(float *)(iVar6 + 0x38);
    fVar8 = *(float *)(iVar6 + 0x30) * *(float *)(iVar14 + 0x20) +
            *(float *)(iVar6 + 0x18) * *pfVar15 +
            *(float *)(iVar6 + 0x24) * *(float *)(iVar14 + 0x1c) + *(float *)(iVar6 + 0x3c);
    fVar9 = *(float *)(iVar6 + 0x34) * *(float *)(iVar14 + 0x20) +
            *(float *)(iVar6 + 0x1c) * *pfVar15 +
            *(float *)(iVar6 + 0x28) * *(float *)(iVar14 + 0x1c) + *(float *)(iVar6 + 0x40);
    fVar10 = DAT_00d78bd8 - fVar7;
    fVar11 = DAT_00d78bdc - fVar8;
    fVar12 = DAT_00d78be0 - fVar9;
    fVar16 = (float10)FUN_00795d80(fVar10 * fVar10 + fVar12 * fVar12 + fVar11 * fVar11);
    fVar17 = (float10)(**(code **)(*in_ECX + 0x60))();
    iVar6 = in_ECX[0x10];
    *(float *)(iVar6 + 0x38) = (float)((float10)(float)((float10)fVar10 * fVar16) * fVar17) + fVar7;
    *(float *)(iVar6 + 0x3c) = (float)((float10)(float)((float10)fVar11 * fVar16) * fVar17) + fVar8;
    *(float *)(iVar6 + 0x40) =
         (float)(fVar17 * (float10)(float)((float10)fVar12 * fVar16) + (float10)fVar9);
    *(uint *)(in_ECX[0x10] + 8) = *(uint *)(in_ECX[0x10] + 8) | 0x40;
    (**(code **)(*(int *)in_ECX[0x10] + 0x48))();
    FUN_00768080(0);
    uVar13 = param_1;
    FUN_005ed470();
    iVar6 = in_ECX[0x10];
    *(int *)(iVar6 + 0x38) = iVar3;
    *(int *)(iVar6 + 0x3c) = iVar4;
    *(int *)(iVar6 + 0x40) = iVar5;
    *(uint *)(in_ECX[0x10] + 8) = *(uint *)(in_ECX[0x10] + 8) & 0xffffffbf;
    iVar3 = DAT_00d78910;
    DAT_00d78910 = iVar3;
    if (DAT_00d78910 != 0) {
      FUN_006c1260(auStack_30,&param_1);
      FUN_006be190(auStack_30,param_1);
      FUN_004f60f0(in_ECX,0,uVar13,*(uint *)(in_ECX[0x10] + 0x4c) >> 0x18);
      DAT_00d78910 = iVar3;
    }
  }
  if (in_ECX[0x10] != 0) {
    puVar1 = (uint *)(in_ECX[0x10] + 8);
    *puVar1 = *puVar1 & 0xffffffbf;
  }
  return;
}



// ?Draw@OneOffSpellSeed@@UAEXXZ @ 0x004f54b0

void _Draw_OneOffSpellSeed__UAEXXZ(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  float *pfVar4;
  int *in_ECX;
  float10 fVar5;
  undefined4 uStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  int iStack_48;
  int iStack_44;
  int iStack_40;
  float fStack_3c;
  float fStack_38;
  undefined1 auStack_30 [48];
  
  if (in_ECX[0x1c] != 0) {
    FUN_006c0fa0();
    FUN_004f4d40();
    piVar1 = (int *)in_ECX[0x10];
    iStack_48 = piVar1[0xe];
    iStack_44 = piVar1[0xf];
    iStack_40 = piVar1[0x10];
    iVar3 = (**(code **)(*piVar1 + 0xf8))();
    iVar2 = in_ECX[0x10];
    pfVar4 = (float *)(iVar3 + 0x18);
    fStack_54 = *pfVar4 * *(float *)(iVar2 + 0x14) +
                *(float *)(iVar2 + 0x20) * *(float *)(iVar3 + 0x1c) +
                *(float *)(iVar2 + 0x2c) * *(float *)(iVar3 + 0x20) + *(float *)(iVar2 + 0x38);
    fStack_50 = *(float *)(iVar2 + 0x24) * *(float *)(iVar3 + 0x1c) +
                *(float *)(iVar2 + 0x18) * *pfVar4 +
                *(float *)(iVar2 + 0x30) * *(float *)(iVar3 + 0x20) + *(float *)(iVar2 + 0x3c);
    fStack_4c = *(float *)(iVar2 + 0x28) * *(float *)(iVar3 + 0x1c) +
                *(float *)(iVar2 + 0x1c) * *pfVar4 +
                *(float *)(iVar2 + 0x34) * *(float *)(iVar3 + 0x20) + *(float *)(iVar2 + 0x40);
    fStack_60 = DAT_00d78bd8 - fStack_54;
    fStack_5c = DAT_00d78bdc - fStack_50;
    fStack_58 = DAT_00d78be0 - fStack_4c;
    fVar5 = (float10)FUN_00795d80(fStack_60 * fStack_60 +
                                  fStack_58 * fStack_58 + fStack_5c * fStack_5c);
    fStack_60 = (float)((float10)fStack_60 * fVar5);
    fStack_5c = (float)((float10)fStack_5c * fVar5);
    fStack_58 = (float)((float10)fStack_58 * fVar5);
    fVar5 = (float10)(**(code **)(*in_ECX + 0x60))();
    iVar2 = in_ECX[0x10];
    fStack_3c = (float)((float10)fStack_60 * fVar5);
    fStack_38 = (float)((float10)fStack_5c * fVar5);
    fStack_54 = fStack_3c + fStack_54;
    *(float *)(iVar2 + 0x38) = fStack_54;
    fStack_50 = fStack_38 + fStack_50;
    *(float *)(iVar2 + 0x3c) = fStack_50;
    fStack_4c = (float)(fVar5 * (float10)fStack_58 + (float10)fStack_4c);
    *(float *)(iVar2 + 0x40) = fStack_4c;
    (**(code **)(*(int *)in_ECX[0x10] + 0x48))();
    FUN_00768080(0);
    FUN_005ed470();
    iVar2 = in_ECX[0x10];
    *(int *)(iVar2 + 0x38) = iStack_48;
    *(int *)(iVar2 + 0x3c) = iStack_44;
    *(int *)(iVar2 + 0x40) = iStack_40;
    iVar2 = DAT_00d78910;
    DAT_00d78910 = iVar2;
    if (DAT_00d78910 != 0) {
      FUN_006c1260(auStack_30,&uStack_64);
      FUN_006be190(auStack_30,uStack_64);
      FUN_004f60f0(in_ECX,0,1,*(uint *)(in_ECX[0x10] + 0x4c) >> 0x18);
      DAT_00d78910 = iVar2;
    }
  }
  return;
}



// ?GetSaveType@OneOffSpellSeed@@UAEIXZ @ 0x0052e670

undefined4 _GetSaveType_OneOffSpellSeed__UAEIXZ(void)

{
  return 0x25;
}



// ?GetDebugText@OneOffSpellSeed@@UAEPADXZ @ 0x0052e680

char * _GetDebugText_OneOffSpellSeed__UAEPADXZ(void)

{
  return s_OneOffSpellSeed__00b1a334;
}



// ?ToBeDeleted@OneOffSpellSeed@@UAEXH@Z @ 0x006c0e60

void _ToBeDeleted_OneOffSpellSeed__UAEXH_Z(void)

{
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x70) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x70) + 0xc))(0);
    *(undefined4 *)(in_ECX + 0x70) = 0;
  }
  _ToBeDeleted_MobileObject__UAEXH_Z(0);
  return;
}



// ?CallVirtualFunctionsForCreation@OneOffSpellSeed@@UAEXABUMapCoords@@@Z @ 0x006c0e90

void _CallVirtualFunctionsForCreation_OneOffSpellSeed__UAEXABUMapCoords___Z(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  undefined1 uStack_8;
  undefined1 uStack_7;
  undefined1 uStack_6;
  undefined1 uStack_5;
  undefined1 uStack_4;
  
  _CallVirtualFunctionsForCreation_MobileObject__UAEXABUMapCoords___Z(param_1);
  uStack_4 = 1;
  uStack_8 = 1;
  uStack_7 = 1;
  uStack_6 = 0;
  uStack_5 = 1;
  iVar1 = **(int **)(in_ECX + 0x40);
  FUN_005489c0(s___data_spells_meshes_O_Bibble_up_00b25f7c,&uStack_8,0,0);
  (**(code **)(iVar1 + 0xf4))();
  (**(code **)(**(int **)(in_ECX + 0x40) + 0x40))();
  (**(code **)(**(int **)(in_ECX + 0x40) + 0x78))();
  (**(code **)(**(int **)(in_ECX + 0x40) + 0x80))();
  if ((*(byte *)(in_ECX + 10) & 1) == 0) {
    iVar1 = FUN_006bdac0(param_1,*(undefined4 *)(in_ECX + 0x68),
                         DAT_00c22ca4 + 0x18 + (uint)*(byte *)(DAT_00c22ca4 + 0x201b17) * 0x278,
                         0x3f800000,*(undefined4 *)(in_ECX + 0x78));
    *(int *)(in_ECX + 0x70) = iVar1;
    if (iVar1 != 0) {
      FUN_006be1e0(0);
    }
  }
  return;
}



// ?InterfaceSetInMagicHand@OneOffSpellSeed@@UAEIPAVGInterfaceStatus@@@Z @ 0x006c0f60

undefined4 _InterfaceSetInMagicHand_OneOffSpellSeed__UAEIPAVGInterfaceStatus___Z(int *param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = FUN_006c1980(*(undefined4 *)(in_ECX + 0x78));
  (**(code **)(*param_1 + 0x1c))(uVar1);
  FUN_005f93f0(uVar1);
  return 1;
}



// ?InterfaceTap@OneOffSpellSeed@@UAEIPAVGInterfaceStatus@@@Z @ 0x006c1060

undefined4 _InterfaceTap_OneOffSpellSeed__UAEIPAVGInterfaceStatus___Z(int param_1)

{
  int iVar1;
  int *in_ECX;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uStack_16c;
  LH_SamplePlayOptions aLStack_168 [4];
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_144;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  
  iVar1 = FUN_006c1150(param_1,in_ECX[0x1a],in_ECX[0x1e],in_ECX[0x1b]);
  if (iVar1 != 0) {
    uVar3 = 0x80000000;
    uVar2 = 0xe;
    FUN_00667ed0(0xe,0x80000000);
    FUN_00598f00(uVar2,uVar3);
    uVar2 = *(undefined4 *)(param_1 + 0xcc);
    uVar3 = *(undefined4 *)(param_1 + 200);
    uStack_16c = *(undefined4 *)(param_1 + 0xd0);
    LH_SamplePlayOptions::LH_SamplePlayOptions(aLStack_168);
    uStack_164 = *(undefined4 *)(DAT_00bf4e68 + 0x3ac);
    uStack_144 = 0x6d;
    uStack_160 = 1;
    uStack_130 = uStack_16c;
    uStack_15c = 0;
    uStack_138 = uVar3;
    uStack_134 = uVar2;
    FUN_00423db0(aLStack_168);
    (**(code **)(*in_ECX + 0xc))(0);
    LH_SamplePlayOptions::~LH_SamplePlayOptions((LH_SamplePlayOptions *)&uStack_16c);
    return 3;
  }
  return 0;
}



// ?GetPhysicsConstantsType@OneOffSpellSeed@@UAEIXZ @ 0x006c1330

undefined4 _GetPhysicsConstantsType_OneOffSpellSeed__UAEIXZ(void)

{
  return 9;
}



// ?Save@OneOffSpellSeed@@UAEIAAVGameOSFile@@@Z @ 0x006c1340

undefined4 _Save_OneOffSpellSeed__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_MobileObject__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x78),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x78) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90((byte *)(in_ECX + 0x68),4,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x68) + 4;
        if (DAT_00b19ac8 != 0) {
          iVar1 = FUN_0072be90((byte *)(in_ECX + 0x6c),4,0);
          if (iVar1 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x6c) + 4;
        }
      }
    }
    return 1;
  }
  return 0;
}



// ?Load@OneOffSpellSeed@@UAEIAAVGameOSFile@@@Z @ 0x006c1430

undefined4 _Load_OneOffSpellSeed__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Load_MobileObject__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x78),4,0,unaff_EDI,unaff_ESI,unaff_EBX);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x78) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x68) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x6c) + 4;
    }
    return 1;
  }
  return 0;
}



// ?IsOneOffSpellAggressive@OneOffSpellSeed@@UAEIPAVCreature@@@Z @ 0x006c1510

undefined4 _IsOneOffSpellAggressive_OneOffSpellSeed__UAEIPAVCreature___Z(void)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  FUN_006c1020(0xffffffff);
  iVar1 = FUN_006c19a0(uVar2);
  return *(undefined4 *)(iVar1 + 0x48);
}



// ?IsOneOffSpellCompassionate@OneOffSpellSeed@@UAEIPAVCreature@@@Z @ 0x006c1530

undefined4 _IsOneOffSpellCompassionate_OneOffSpellSeed__UAEIPAVCreature___Z(void)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  FUN_006c1020(0xffffffff);
  iVar1 = FUN_006c19a0(uVar2);
  return *(undefined4 *)(iVar1 + 0x4c);
}



// ?IsOneOffSpellPlayful@OneOffSpellSeed@@UAEIPAVCreature@@@Z @ 0x006c1550

undefined4 _IsOneOffSpellPlayful_OneOffSpellSeed__UAEIPAVCreature___Z(void)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  FUN_006c1020(0xffffffff);
  iVar1 = FUN_006c19a0(uVar2);
  return *(undefined4 *)(iVar1 + 0x44);
}



// ?IsOneOffSpellToRestoreHealth@OneOffSpellSeed@@UAEIPAVCreature@@@Z @ 0x006c1570

undefined4 _IsOneOffSpellToRestoreHealth_OneOffSpellSeed__UAEIPAVCreature___Z(void)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0xffffffff;
  FUN_006c1020(0xffffffff);
  iVar1 = FUN_006c19a0(uVar2);
  return *(undefined4 *)(iVar1 + 0x50);
}



// ?SaveObject@OneOffSpellSeed@@UAEIAAULHOSFile@@ABUMapCoords@@@Z @ 0x006c1590

int _SaveObject_OneOffSpellSeed__UAEIAAULHOSFile__ABUMapCoords___Z(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
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
  FUN_006c1040();
  uVar3 = FUN_005b8c80();
  uVar4 = FUN_005bf290(auStack_64);
  uVar3 = FUN_006ad590(0x54,uVar4,uVar3);
  FUN_00733e17(acStack_12c,uVar3);
  iVar5 = -1;
  pcVar6 = acStack_12c;
  do {
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  FUN_006b10c0();
  return iVar2;
}



// ?GetOverwritePickUpToolTip@OneOffSpellSeed@@UAEIXZ @ 0x006c1660

undefined4 _GetOverwritePickUpToolTip_OneOffSpellSeed__UAEIXZ(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_006c1040();
  if (iVar1 != 0) {
    iVar1 = FUN_005b8f10();
    return *(undefined4 *)(iVar1 + 0x110);
  }
  return *(undefined4 *)(&DAT_00cbe494 + *(int *)(in_ECX + 0x68) * 400);
}



// ?GetQueryFirstEnumText@OneOffSpellSeed@@UAE?AW4HELP_TEXT@@XZ @ 0x006c16a0

void _GetQueryFirstEnumText_OneOffSpellSeed__UAE_AW4HELP_TEXT__XZ(void)

{
  int iVar1;
  
  iVar1 = FUN_006c1020();
  if (*(int *)(iVar1 + 0x50) == 0) {
    _GetQueryFirstEnumText_Object__UAE_AW4HELP_TEXT__XZ();
  }
  return;
}



// ?GetQueryLastEnumText@OneOffSpellSeed@@UAE?AW4HELP_TEXT@@XZ @ 0x006c16c0

void _GetQueryLastEnumText_OneOffSpellSeed__UAE_AW4HELP_TEXT__XZ(void)

{
  int iVar1;
  
  iVar1 = FUN_006c1020();
  if (*(int *)(iVar1 + 0x54) == 0) {
    _GetQueryLastEnumText_Object__UAE_AW4HELP_TEXT__XZ();
  }
  return;
}



