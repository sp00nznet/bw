// Decompiled functions for class: SetupOnlineLandscapes
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Init@SetupOnlineLandscapes@@UAEXIIP6AXHPAVSetupBox@@PAVSetupControl@@HH@Z@Z @ 0x0051b630

void _Init_SetupOnlineLandscapes__UAEXIIP6AXHPAVSetupBox__PAVSetupControl__HH_Z_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int *piVar4;
  int in_ECX;
  
  _Init__13DialogBoxBaseFUlUlPFiP8SetupBoxP12SetupControlii_v(param_1,param_2,param_3);
  DAT_00bf29bc = in_ECX;
  iVar1 = FUN_00746d70(0x468,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x1cc);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_0040a590(0x3e6,0x96,0x20d,500,0x1e,&DAT_00b6e5f0,0);
  }
  *(int *)(in_ECX + 0xa0) = iVar1;
  *(undefined4 *)(iVar1 + 0x20) = 0x10;
  iVar1 = FUN_00746d70(0x25c,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x1d0);
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
  *(undefined4 *)(in_ECX + 0xa4) = uVar2;
  puVar3 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x1d4);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0x12ca < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xe178;
    }
    FUN_00407730(3,0x50,0x3c,200,0x1e,*(undefined4 *)(iVar1 + 8));
    *puVar3 = &PTR_LAB_007ed4e8;
    puVar3[0x8f] = 0;
    *(undefined1 *)((int)puVar3 + 0x22a) = 0;
    puVar3[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0xac) = puVar3;
  puVar3[8] = 0x14;
  iVar1 = FUN_00746d70(0x2b0,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x1d6);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_004087c0(2,0x50,0x5a,0xfa,0x1a4);
  }
  *(int *)(in_ECX + 0x98) = iVar1;
  *(undefined4 *)(iVar1 + 0x20) = 0x14;
  puVar3 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x1d8);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    FUN_00407730(6,0x15e,0x15e,400,0x1e,&DAT_00b6e5f0);
    *puVar3 = &PTR_LAB_007ed4e8;
    puVar3[0x8f] = 0;
    *(undefined1 *)((int)puVar3 + 0x22a) = 0;
    puVar3[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0xb0) = puVar3;
  puVar3[8] = 0x14;
  iVar1 = FUN_00746d70(0x2b0,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x1da);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_004087c0(5,0x15e,0x177,400,100);
  }
  *(int *)(in_ECX + 0x9c) = iVar1;
  *(undefined4 *)(iVar1 + 0x20) = 0x14;
  (**(code **)(**(int **)(in_ECX + 0x9c) + 8))(1);
  iVar1 = FUN_00746d70(0x244,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x1de);
  if (iVar1 == 0) {
    piVar4 = (int *)0x0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0x12cc < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xe190;
    }
    piVar4 = (int *)FUN_00407d30(4,0x15e,0x1e0,200,0x1e,*(undefined4 *)(iVar1 + 8),0);
  }
  *(int **)(in_ECX + 0xa8) = piVar4;
  (**(code **)(*piVar4 + 8))(1);
  *(undefined4 *)(*(int *)(in_ECX + 0xa8) + 0x20) = 0x14;
  return;
}



// ?Destroy@SetupOnlineLandscapes@@UAEXXZ @ 0x0051b8e0

void _Destroy_SetupOnlineLandscapes__UAEXXZ(void)

{
  _Destroy__13DialogBoxBaseFv();
  DAT_00bf29bc = 0;
  return;
}



// ?InitControls@SetupOnlineLandscapes@@UAEXXZ @ 0x0051b8f0

void _InitControls_SetupOnlineLandscapes__UAEXXZ(void)

{
  int in_ECX;
  
  *(undefined4 *)(*(int *)(DAT_00bf29bc + 4) + 0xac) = 0x10;
  *(undefined4 *)(in_ECX + 0x80) = 0;
  *(undefined4 *)(in_ECX + 0x84) = 0;
  return;
}



// ?Show@SetupOnlineLandscapes@@UAEXXZ @ 0x0051cf40

void _Show_SetupOnlineLandscapes__UAEXXZ(void)

{
  (**(code **)(**(int **)(DAT_00bf29bc + 0xa8) + 8))(0);
  _Show__13DialogBoxBaseFv();
  return;
}



