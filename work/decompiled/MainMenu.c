// Decompiled functions for class: MainMenu
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Init@MainMenu@@UAEXIIP6AXHPAVSetupBox@@PAVSetupControl@@HH@Z@Z @ 0x005134b0

void _Init_MainMenu__UAEXIIP6AXHPAVSetupBox__PAVSetupControl__HH_Z_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  ushort *puVar4;
  int in_ECX;
  undefined1 local_400 [512];
  undefined1 local_200 [512];
  
  _Init__13DialogBoxBaseFUlUlPFiP8SetupBoxP12SetupControlii_v(param_1,param_2,param_3);
  DAT_00bf1eb0 = in_ECX;
  FUN_00615ec0(local_200);
  puVar1 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0x66b);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    FUN_00407730(999,0x32,0x41,700,0x5a,&DAT_00b6e5f0);
    *puVar1 = &PTR_LAB_007ed4e8;
    puVar1[0x8f] = 4;
    *(undefined1 *)((int)puVar1 + 0x22a) = 0;
    puVar1[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x24) = puVar1;
  iVar2 = FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0x66f);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00407d30(0,0xb4,0x91,0x1b8,0x46,&DAT_00b6e5f0,0);
  }
  *(undefined4 *)(in_ECX + 0x10) = uVar3;
  iVar2 = FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0x670);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00407d30(1,0xb4,0xe1,0x1b8,0x46,&DAT_00b6e5f0,0);
  }
  *(undefined4 *)(in_ECX + 0x14) = uVar3;
  iVar2 = FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0x671);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00407d30(2,0xb4,0x131,0x1b8,0x46,&DAT_00b6e5f0,0);
  }
  *(undefined4 *)(in_ECX + 0x18) = uVar3;
  iVar2 = FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0x672);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00407d30(3,0xb4,0x181,0x1b8,0x46,&DAT_00b6e5f0,0);
  }
  *(undefined4 *)(in_ECX + 0x1c) = uVar3;
  iVar2 = FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0x673);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00407d30(4,0xb4,0x1d1,0x1b8,0x46,&DAT_00b6e5f0,0);
  }
  *(undefined4 *)(in_ECX + 0x20) = uVar3;
  iVar2 = FUN_00615f80();
  if (iVar2 != 0) {
    puVar4 = LHNetGetCurrentProfileNameFromRegistry();
    FUN_00615d60(puVar4);
    puVar4 = LHNetGetCurrentProfileNameFromRegistry();
    LHNetUseProfile(puVar4);
    FUN_00615ec0(local_400);
    FUN_00616090(local_400,&DAT_00c6cad8);
  }
  FUN_00513380(0);
  return;
}



// ?Destroy@MainMenu@@UAEXXZ @ 0x005136f0

void _Destroy_MainMenu__UAEXXZ(void)

{
  _Draw_PlannedMultiMapFixed__QAEXXZ();
  _Destroy__13DialogBoxBaseFv();
  DAT_00bf1eb0 = 0;
  return;
}



// ?InitControls@MainMenu@@UAEXXZ @ 0x00513740

void _InitControls_MainMenu__UAEXXZ(void)

{
  int *piVar1;
  ushort *puVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined1 auStack_200 [512];
  
  puVar2 = LHNetGetCurrentProfileNameFromRegistry();
  FUN_00615d60(puVar2);
  FUN_00615ec0(auStack_200);
  FUN_00616090(auStack_200,&DAT_00c6cad8);
  iVar6 = DAT_00c38db8;
  if (0xd4c < DAT_00c38dbc) {
    iVar6 = DAT_00c38db8 + 0x9f90;
  }
  UNICODE_sprintf((ushort *)(*(int *)(in_ECX + 0x24) + 0x24),*(ushort **)(iVar6 + 8),&DAT_00c6ccd8);
  *(undefined4 *)(in_ECX + 0x30) = 0xffffffff;
  FUN_00715b00();
  FUN_0059e400();
  uVar3 = FUN_00533e50();
  *(undefined4 *)(DAT_00c22ca4 + 0x24c350) = uVar3;
  *(undefined4 *)(in_ECX + 0x34) = *(undefined4 *)(DAT_00c22ca4 + 0x24c350);
  iVar6 = 0;
  do {
    piVar1 = *(int **)(in_ECX + 0x10 + iVar6 * 4);
    switch(iVar6) {
    case 0:
      iVar5 = DAT_00c38db8;
      if (0xd4e < DAT_00c38dbc) {
        iVar5 = DAT_00c38db8 + 0x9fa8;
      }
      FUN_00733ff8(piVar1 + 9,*(undefined4 *)(iVar5 + 8));
      piVar1[0x8e] = (int)&LAB_00513aa0;
      break;
    case 1:
      iVar5 = DAT_00c38db8;
      if (*(int *)(DAT_00c22ca4 + 0x201ac8) == 0) {
        if (0x1aca < DAT_00c38dbc) {
          iVar5 = DAT_00c38db8 + 0x14178;
        }
      }
      else if (0x1acb < DAT_00c38dbc) {
        iVar5 = DAT_00c38db8 + 0x14184;
      }
      FUN_00733ff8(piVar1 + 9,*(undefined4 *)(iVar5 + 8));
      iVar5 = *piVar1;
      iVar7 = FUN_005256a0();
      (**(code **)(iVar5 + 8))
                (CONCAT31((int3)((uint)-(iVar7 + -1) >> 8),'\x01' - (iVar7 + -1 != 0)));
      piVar1[0x8e] = (int)&LAB_00513b50;
      break;
    case 2:
      iVar7 = FUN_005256a0();
      iVar5 = DAT_00c38db8;
      if (iVar7 == 0) {
        if (0xd50 < DAT_00c38dbc) {
          iVar5 = DAT_00c38db8 + 0x9fc0;
        }
      }
      else if (0x1478 < DAT_00c38dbc) {
        iVar5 = DAT_00c38db8 + 0xf5a0;
      }
      FUN_00733ff8(piVar1 + 9,*(undefined4 *)(iVar5 + 8));
      (**(code **)(*piVar1 + 8))
                (CONCAT31((int3)((uint)*(int *)(DAT_00c22ca4 + 0x201ac8) >> 8),
                          *(int *)(DAT_00c22ca4 + 0x201ac8) == 1));
      piVar1[0x8e] = (int)&LAB_00513ab0;
      break;
    case 3:
      iVar5 = DAT_00c38db8;
      if (0xd52 < DAT_00c38dbc) {
        iVar5 = DAT_00c38db8 + 0x9fd8;
      }
      FUN_00733ff8(piVar1 + 9,*(undefined4 *)(iVar5 + 8));
      piVar1[0x8e] = (int)&LAB_00513ba0;
      break;
    case 4:
      iVar5 = DAT_00c38db8;
      if (0xd53 < DAT_00c38dbc) {
        iVar5 = DAT_00c38db8 + 0x9fe4;
      }
      FUN_00733ff8(piVar1 + 9,*(undefined4 *)(iVar5 + 8));
      piVar1[0x8e] = (int)&LAB_00513710;
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 5);
  iVar5 = 0x91;
  iVar7 = 0x46;
  iVar6 = 0x50;
  if ((*(int *)(DAT_00c22ca4 + 0x201ac8) != 0) || (iVar4 = FUN_005256a0(), iVar4 != 0)) {
    iVar6 = 100;
    iVar7 = 0x50;
    iVar5 = 0x96;
  }
  *(int *)(*(int *)(in_ECX + 0x10) + 0xc) = iVar5;
  *(int *)(*(int *)(in_ECX + 0x10) + 0x14) = iVar7 + iVar5;
  if (*(char *)(*(int *)(in_ECX + 0x10) + 0x229) == '\0') {
    iVar5 = iVar5 + iVar6;
  }
  *(int *)(*(int *)(in_ECX + 0x14) + 0xc) = iVar5;
  *(int *)(*(int *)(in_ECX + 0x14) + 0x14) = iVar7 + iVar5;
  if (*(char *)(*(int *)(in_ECX + 0x14) + 0x229) == '\0') {
    iVar5 = iVar5 + iVar6;
  }
  *(int *)(*(int *)(in_ECX + 0x18) + 0xc) = iVar5;
  *(int *)(*(int *)(in_ECX + 0x18) + 0x14) = iVar7 + iVar5;
  if (*(char *)(*(int *)(in_ECX + 0x18) + 0x229) == '\0') {
    iVar5 = iVar5 + iVar6;
  }
  *(int *)(*(int *)(in_ECX + 0x1c) + 0xc) = iVar5;
  *(int *)(*(int *)(in_ECX + 0x1c) + 0x14) = iVar7 + iVar5;
  if (*(char *)(*(int *)(in_ECX + 0x1c) + 0x229) == '\0') {
    iVar5 = iVar5 + iVar6;
  }
  *(int *)(*(int *)(in_ECX + 0x20) + 0xc) = iVar5;
  *(int *)(*(int *)(in_ECX + 0x20) + 0x14) = iVar7 + iVar5;
  return;
}



