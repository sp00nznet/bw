// Decompiled functions for class: SetupMultiplayerMain
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Init@SetupMultiplayerMain@@UAEXIIP6AXHPAVSetupBox@@PAVSetupControl@@HH@Z@Z @ 0x0051d110

void _Init_SetupMultiplayerMain__UAEXIIP6AXHPAVSetupBox__PAVSetupControl__HH_Z_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  _Init__13DialogBoxBaseFUlUlPFiP8SetupBoxP12SetupControlii_v(param_1,param_2,param_3);
  DAT_00bf29cc = in_ECX;
  iVar1 = FUN_00746d70(0x468,s_C__dev_black_FrontEndSetupMultip_00b17a5c,0x4d);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0040a590(0x3e6,0x96,0x20d,500,0x1e,&DAT_008fd4c8,0);
  }
  *(undefined4 *)(in_ECX + 0x14) = uVar2;
  uVar2 = FUN_00405ee0();
  *(undefined4 *)(*(int *)(in_ECX + 0x14) + 0x20) = uVar2;
  iVar1 = FUN_00746d70(0x25c,s_C__dev_black_FrontEndSetupMultip_00b17a5c,0x51);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0xa24 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0x79b0;
    }
    uVar2 = FUN_0040b4a0(0,0x2d0,0x208,*(undefined4 *)(iVar1 + 8),0x28,1,3);
  }
  *(undefined4 *)(in_ECX + 0x18) = uVar2;
  iVar1 = FUN_00746d70(0x244,s_C__dev_black_FrontEndSetupMultip_00b17a5c,0x54);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0x12e1 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xe28c;
    }
    iVar1 = FUN_00407d30(3,400,0x96,200,100,*(undefined4 *)(iVar1 + 8),0);
  }
  *(int *)(in_ECX + 0x1c) = iVar1;
  *(code **)(iVar1 + 0x238) = FUN_0051d380;
  iVar1 = FUN_00746d70(0x244,s_C__dev_black_FrontEndSetupMultip_00b17a5c,0x57);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0x12e2 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xe298;
    }
    iVar1 = FUN_00407d30(4,400,300,200,100,*(undefined4 *)(iVar1 + 8),0);
  }
  *(int *)(in_ECX + 0x20) = iVar1;
  *(undefined1 **)(iVar1 + 0x238) = &LAB_0051d370;
  iVar1 = FUN_00746d70(0x260,s_C__dev_black_FrontEndSetupMultip_00b17a5c,0x5a);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0x12e3 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xe2a4;
    }
    uVar2 = FUN_0040ef70(1,0x113,0xbe,1,1,*(undefined4 *)(iVar1 + 8),0x14);
  }
  *(undefined4 *)(in_ECX + 0x28) = uVar2;
  iVar1 = FUN_00746d70(0x260,s_C__dev_black_FrontEndSetupMultip_00b17a5c,0x5c);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0x12e4 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xe2b0;
    }
    uVar2 = FUN_0040ef70(2,0x113,0x154,1,0,*(undefined4 *)(iVar1 + 8),0x14);
  }
  *(undefined4 *)(in_ECX + 0x2c) = uVar2;
  *(undefined1 **)(*(int *)(in_ECX + 0x28) + 0x238) = &LAB_0051d410;
  *(undefined1 **)(*(int *)(in_ECX + 0x2c) + 0x238) = &LAB_0051d410;
  return;
}



// ?Destroy@SetupMultiplayerMain@@UAEXXZ @ 0x0051d530

void _Destroy_SetupMultiplayerMain__UAEXXZ(void)

{
  _Destroy__13DialogBoxBaseFv();
  DAT_00bf29cc = 0;
  return;
}



// ?InitControls@SetupMultiplayerMain@@UAEXXZ @ 0x0051d540

void _InitControls_SetupMultiplayerMain__UAEXXZ(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  uVar2 = FUN_00405ee0();
  iVar1 = *(int *)(DAT_00bf29cc + 4);
  *(undefined4 *)(iVar1 + 0xac) = uVar2;
  if (*(char *)(in_ECX + 0x10) == '\0') {
    puVar4 = *(undefined4 **)(in_ECX + 0x30);
    puVar5 = (undefined4 *)(in_ECX + 0x34);
    for (iVar3 = 0x10b; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
  }
  *(undefined1 *)(in_ECX + 0x10) = 0;
  (**(code **)(**(int **)(in_ECX + 0x1c) + 8))
            (CONCAT31((int3)((uint)iVar1 >> 8),*(char *)(in_ECX + 0x428) == '\0'));
  *(uint *)(*(int *)(in_ECX + 0x28) + 0x248) = (uint)*(byte *)(in_ECX + 0x428);
  (**(code **)(**(int **)(in_ECX + 0x20) + 8))(*(undefined1 *)(in_ECX + 0x428));
  *(uint *)(*(int *)(in_ECX + 0x2c) + 0x248) = (uint)(*(char *)(in_ECX + 0x428) == '\0');
  return;
}



// ?InitSubDialogs@SetupMultiplayerMain@@UAEXXZ @ 0x0051d730

void _InitSubDialogs_SetupMultiplayerMain__UAEXXZ(void)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  
  puVar1 = (undefined4 *)FUN_00746d70(0x4b0,s_C__dev_black_FrontEndSetupMultip_00b17a5c,0xbc);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    FUN_004efee0();
    puVar3 = puVar1 + 0x38;
    for (iVar2 = 0xcb; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    FUN_006b1130();
    *puVar1 = &vftable_SetupLandscapeBox;
    *(undefined1 *)(puVar1 + 4) = 0;
  }
  *(undefined4 **)(in_ECX + 0x460) = puVar1;
  (**(code **)*puVar1)(0x2ec,0x224,&LAB_0051a820);
  *(int *)(*(int *)(in_ECX + 0x460) + 0x14) = in_ECX + 0x34;
  (**(code **)(**(int **)(in_ECX + 0x460) + 8))();
  return;
}



