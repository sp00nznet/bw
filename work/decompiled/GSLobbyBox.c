// Decompiled functions for class: GSLobbyBox
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Init@GSLobbyBox@@UAEXIIP6AXHPAVSetupBox@@PAVSetupControl@@HH@Z@Z @ 0x0055fb80

void _Init_GSLobbyBox__UAEXIIP6AXHPAVSetupBox__PAVSetupControl__HH_Z_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  _Init__13DialogBoxBaseFUlUlPFiP8SetupBoxP12SetupControlii_v(param_1,param_2,param_3);
  DAT_00c2a2c0 = in_ECX;
  iVar1 = FUN_00746d70(0x2b0,s_C__dev_black_GSLobbybox_cpp_00b1cf64,0x27e);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004087c0(1,0x28,0x50,200,0x145);
  }
  *(undefined4 *)(in_ECX + 0x228) = uVar2;
  iVar1 = FUN_00746d70(0x2b0,s_C__dev_black_GSLobbybox_cpp_00b1cf64,0x27f);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004087c0(2,0xfa,0x50,400,0x168);
  }
  *(undefined4 *)(in_ECX + 0x22c) = uVar2;
  iVar1 = FUN_00746d70(0x2b0,s_C__dev_black_GSLobbybox_cpp_00b1cf64,0x280);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004087c0(3,0x294,0x50,100,0x168);
  }
  *(undefined4 *)(in_ECX + 0x230) = uVar2;
  puVar3 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_GSLobbybox_cpp_00b1cf64,0x281);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0xdd5 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xa5fc;
    }
    FUN_00407730(999,0x28,0x32,200,0x1b,*(undefined4 *)(iVar1 + 8));
    *puVar3 = &PTR_LAB_007ed4e8;
    puVar3[0x8f] = 2;
    *(undefined1 *)((int)puVar3 + 0x22a) = 0;
    puVar3[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x260) = puVar3;
  puVar3 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_GSLobbybox_cpp_00b1cf64,0x282);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0xdd6 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xa608;
    }
    FUN_00407730(999,0xfa,0x32,400,0x1b,*(undefined4 *)(iVar1 + 8));
    *puVar3 = &PTR_LAB_007ed4e8;
    puVar3[0x8f] = 2;
    *(undefined1 *)((int)puVar3 + 0x22a) = 0;
    puVar3[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x264) = puVar3;
  puVar3 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_GSLobbybox_cpp_00b1cf64,0x283);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0xdd7 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xa614;
    }
    FUN_00407730(999,0x294,0x32,100,0x1b,*(undefined4 *)(iVar1 + 8));
    *puVar3 = &PTR_LAB_007ed4e8;
    puVar3[0x8f] = 2;
    *(undefined1 *)((int)puVar3 + 0x22a) = 0;
    puVar3[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x268) = puVar3;
  puVar3 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_GSLobbybox_cpp_00b1cf64,0x287);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    FUN_00407730(0,0x28,0x17,300,0x1e,&DAT_00b6e5f0);
    *puVar3 = &PTR_LAB_007ed4e8;
    puVar3[0x8f] = 0;
    *(undefined1 *)((int)puVar3 + 0x22a) = 0;
    puVar3[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x250) = puVar3;
  iVar1 = FUN_00746d70(0x468,s_C__dev_black_GSLobbybox_cpp_00b1cf64,0x28b);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_0040a590(0x3e6,0x96,0x20d,300,0x1e,&DAT_008fd4c8,0);
  }
  *(int *)(in_ECX + 0x26c) = iVar1;
  *(undefined4 *)(iVar1 + 0x20) = 0x10;
  iVar1 = FUN_00746d70(0x25c,s_C__dev_black_GSLobbybox_cpp_00b1cf64,0x28e);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0xd4d < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0x9f9c;
    }
    uVar2 = FUN_0040b4a0(0xc,0x2d0,0x208,*(undefined4 *)(iVar1 + 8),0x28,1,3);
  }
  *(undefined4 *)(in_ECX + 0x238) = uVar2;
  iVar1 = FUN_00746d70(0x25c,s_C__dev_black_GSLobbybox_cpp_00b1cf64,0x28f);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0xd7a < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xa1b8;
    }
    uVar2 = FUN_0040b4a0(0xe,0x28,0x208,*(undefined4 *)(iVar1 + 8),0x28,0,2);
  }
  *(undefined4 *)(in_ECX + 0x248) = uVar2;
  iVar1 = FUN_00746d70(0x468,s_C__dev_black_GSLobbybox_cpp_00b1cf64,0x293);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0040a590(10,0xfa,0x1e0,400,0x1e,&DAT_00b6e5f0,1);
  }
  *(undefined4 *)(in_ECX + 0x23c) = uVar2;
  puVar3 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_GSLobbybox_cpp_00b1cf64,0x294);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0xdb2 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xa458;
    }
    FUN_00407730(999,0xf8,0x1c2,400,0x1e,*(undefined4 *)(iVar1 + 8));
    *puVar3 = &PTR_LAB_007ed4e8;
    puVar3[0x8f] = 2;
    *(undefined1 *)((int)puVar3 + 0x22a) = 0;
    puVar3[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x25c) = puVar3;
  iVar1 = FUN_00746d70(0x244,s_C__dev_black_GSLobbybox_cpp_00b1cf64,0x298);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0x1a9c < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0x13f50;
    }
    uVar2 = FUN_00407d30(0x10,0x1d6,0x20d,0x96,0x1e,*(undefined4 *)(iVar1 + 8),0);
  }
  *(undefined4 *)(in_ECX + 0x24c) = uVar2;
  iVar1 = FUN_00746d70(0x244,s_C__dev_black_GSLobbybox_cpp_00b1cf64,0x299);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0x1a8c < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0x13e90;
    }
    iVar1 = FUN_00407d30(0x29a,0x1d6,0x20d,0x96,0x1e,*(undefined4 *)(iVar1 + 8),0);
  }
  *(int *)(in_ECX + 0x1c) = iVar1;
  *(undefined1 **)(iVar1 + 0x238) = &LAB_005b3ce0;
  (**(code **)(**(int **)(in_ECX + 0x24c) + 8))(1);
  (**(code **)(**(int **)(in_ECX + 0x1c) + 8))(0);
  iVar1 = FUN_00746d70(0x244,s_C__dev_black_GSLobbybox_cpp_00b1cf64,0x2a4);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0x1a4f < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0x13bb4;
    }
    uVar2 = FUN_00407d30(7,0x28,0x1bd,0x5f,0x1e,*(undefined4 *)(iVar1 + 8),0);
  }
  *(undefined4 *)(in_ECX + 0x234) = uVar2;
  iVar1 = FUN_00746d70(0x468,s_C__dev_black_GSLobbybox_cpp_00b1cf64,0x2a7);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0040a590(8,0x91,0x1bd,0x5f,0x1e,&DAT_00b6e5f0,1);
  }
  *(undefined4 *)(in_ECX + 0x240) = uVar2;
  iVar1 = FUN_00746d70(0x468,s_C__dev_black_GSLobbybox_cpp_00b1cf64,0x2a8);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_0040a590(9,0x91,0x1e0,0x5f,0x1e,&DAT_00b6e5f0,1);
  }
  *(int *)(in_ECX + 0x244) = iVar1;
  *(undefined1 *)(iVar1 + 0x260) = 1;
  puVar3 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_GSLobbybox_cpp_00b1cf64,0x2aa);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0xd84 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xa230;
    }
    FUN_00407730(999,0x28,0x1e0,100,0x1e,*(undefined4 *)(iVar1 + 8));
    *puVar3 = &PTR_LAB_007ed4e8;
    puVar3[0x8f] = 2;
    *(undefined1 *)((int)puVar3 + 0x22a) = 0;
    puVar3[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 600) = puVar3;
  iVar1 = FUN_00746d70(0x260,s_C__dev_black_GSLobbybox_cpp_00b1cf64,0x2ac);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0xdb8 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xa4a0;
    }
    iVar1 = FUN_0040ef70(0xf,0x46,0x23a,0,0,*(undefined4 *)(iVar1 + 8),0x14);
  }
  *(int *)(in_ECX + 0x270) = iVar1;
  *(undefined4 *)(iVar1 + 0x20) = 0x10;
  *(undefined4 *)(in_ECX + 0x2ac) = 0;
  *(undefined4 *)(in_ECX + 0x2b0) = 0;
  *(undefined4 *)(in_ECX + 0x280) = 0;
  *(undefined4 *)(in_ECX + 0x294) = 0;
  *(undefined1 *)(in_ECX + 0x22) = 0;
  *(undefined1 *)(in_ECX + 0x21) = 0;
  *(undefined1 *)(in_ECX + 0x20) = 0;
  return;
}



// ?InitControls@GSLobbyBox@@UAEXXZ @ 0x005602b0

void _InitControls_GSLobbyBox__UAEXXZ(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  
  *(undefined4 *)(*(int *)(DAT_00c2a2c0 + 4) + 0xac) = 0x10;
  iVar3 = *(int *)(in_ECX + 0x23c);
  FUN_00734395(iVar3 + 0x24,&DAT_00b6e5f0,0xff);
  *(undefined2 *)(iVar3 + 0x222) = 0;
  uVar2 = FUN_007343d2(iVar3 + 0x24);
  *(undefined4 *)(iVar3 + 0x24c) = uVar2;
  *(undefined4 *)(iVar3 + 0x254) = uVar2;
  *(undefined4 *)(iVar3 + 0x250) = uVar2;
  *(undefined4 *)(iVar3 + 600) = 0;
  iVar3 = *(int *)(in_ECX + 0x22c);
  iVar1 = *(int *)(iVar3 + 0x250);
  while (0 < iVar1) {
    FUN_004090d0(iVar1 + -1);
    iVar1 = *(int *)(iVar3 + 0x250);
  }
  FUN_00560bc0();
  iVar3 = *(int *)(in_ECX + 0x230);
  iVar1 = *(int *)(iVar3 + 0x250);
  while (0 < iVar1) {
    FUN_004090d0(iVar1 + -1);
    iVar1 = *(int *)(iVar3 + 0x250);
  }
  iVar3 = *(int *)(in_ECX + 0x228);
  iVar1 = *(int *)(iVar3 + 0x250);
  while (0 < iVar1) {
    FUN_004090d0(iVar1 + -1);
    iVar1 = *(int *)(iVar3 + 0x250);
  }
  iVar3 = *(int *)(in_ECX + 0x22c);
  iVar1 = *(int *)(iVar3 + 0x250);
  while (0 < iVar1) {
    FUN_004090d0(iVar1 + -1);
    iVar1 = *(int *)(iVar3 + 0x250);
  }
  (**(code **)(**(int **)(in_ECX + 0x24c) + 8))(1);
  (**(code **)(**(int **)(in_ECX + 0x1c) + 8))(0);
  *(undefined4 *)(in_ECX + 0x27c) = 3;
  iVar3 = FUN_007cfc80(DAT_00c415f4);
  if (iVar3 != 0) {
    FUN_005603e0();
  }
  return;
}



// ?Destroy@GSLobbyBox@@UAEXXZ @ 0x00560460

void _Destroy_GSLobbyBox__UAEXXZ(void)

{
  _Destroy__13DialogBoxBaseFv();
  DAT_00c2a2c0 = 0;
  return;
}



