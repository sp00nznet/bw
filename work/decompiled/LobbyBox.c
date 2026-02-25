// Decompiled functions for class: LobbyBox
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Init@LobbyBox@@UAEXIIP6AXHPAVSetupBox@@PAVSetupControl@@HH@Z@Z @ 0x005b3570

void _Init_LobbyBox__UAEXIIP6AXHPAVSetupBox__PAVSetupControl__HH_Z_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  undefined4 uVar3;
  
  _Init__13DialogBoxBaseFUlUlPFiP8SetupBoxP12SetupControlii_v(param_1,param_2,param_3);
  DAT_00c529fc = in_ECX;
  iVar1 = FUN_00746d70(0x2b0,s_C__dev_black_Lobbybox_cpp_00b20868,0x4e);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    if ((DAT_00c415bc == 0) || (uVar3 = 0x145, *(int *)(DAT_00c415bc + 4) == 0)) {
      uVar3 = 0x168;
    }
    uVar3 = FUN_004087c0(1,0x28,0x50,200,uVar3);
  }
  *(undefined4 *)(in_ECX + 0x2c) = uVar3;
  iVar1 = FUN_00746d70(0x2b0,s_C__dev_black_Lobbybox_cpp_00b20868,0x4f);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_004087c0(2,0xfa,0x50,400,0x168);
  }
  *(undefined4 *)(in_ECX + 0x30) = uVar3;
  iVar1 = FUN_00746d70(0x2b0,s_C__dev_black_Lobbybox_cpp_00b20868,0x50);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_004087c0(3,0x294,0x50,100,0x168);
  }
  *(undefined4 *)(in_ECX + 0x34) = uVar3;
  puVar2 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_Lobbybox_cpp_00b20868,0x51);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0xdd5 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xa5fc;
    }
    FUN_00407730(999,0x28,0x32,200,0x1b,*(undefined4 *)(iVar1 + 8));
    *puVar2 = &PTR_LAB_007ed4e8;
    puVar2[0x8f] = 2;
    *(undefined1 *)((int)puVar2 + 0x22a) = 0;
    puVar2[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x6c) = puVar2;
  puVar2 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_Lobbybox_cpp_00b20868,0x52);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0xdd6 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xa608;
    }
    FUN_00407730(999,0xfa,0x32,400,0x1b,*(undefined4 *)(iVar1 + 8));
    *puVar2 = &PTR_LAB_007ed4e8;
    puVar2[0x8f] = 2;
    *(undefined1 *)((int)puVar2 + 0x22a) = 0;
    puVar2[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x70) = puVar2;
  puVar2 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_Lobbybox_cpp_00b20868,0x53);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0xdd7 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xa614;
    }
    FUN_00407730(999,0x294,0x32,100,0x1b,*(undefined4 *)(iVar1 + 8));
    *puVar2 = &PTR_LAB_007ed4e8;
    puVar2[0x8f] = 2;
    *(undefined1 *)((int)puVar2 + 0x22a) = 0;
    puVar2[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x74) = puVar2;
  puVar2 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_Lobbybox_cpp_00b20868,0x57);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    FUN_00407730(0,0x28,0x17,300,0x1e,&DAT_00b6e5f0);
    *puVar2 = &PTR_LAB_007ed4e8;
    puVar2[0x8f] = 0;
    *(undefined1 *)((int)puVar2 + 0x22a) = 0;
    puVar2[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x5c) = puVar2;
  iVar1 = FUN_00746d70(0x468,s_C__dev_black_Lobbybox_cpp_00b20868,0x5b);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_0040a590(0x3e6,0x96,0x20d,300,0x1e,&DAT_008fd4c8,0);
  }
  *(int *)(in_ECX + 0x78) = iVar1;
  *(undefined4 *)(iVar1 + 0x20) = 0x10;
  iVar1 = FUN_00746d70(0x244,s_C__dev_black_Lobbybox_cpp_00b20868,0x5e);
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
  iVar1 = FUN_00746d70(0x25c,s_C__dev_black_Lobbybox_cpp_00b20868,0x61);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0xd4d < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0x9f9c;
    }
    uVar3 = FUN_0040b4a0(0xc,0x2d0,0x208,*(undefined4 *)(iVar1 + 8),0x28,1,3);
  }
  *(undefined4 *)(in_ECX + 0x44) = uVar3;
  iVar1 = FUN_00746d70(0x25c,s_C__dev_black_Lobbybox_cpp_00b20868,0x62);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0xd7a < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xa1b8;
    }
    uVar3 = FUN_0040b4a0(0xe,0x28,0x208,*(undefined4 *)(iVar1 + 8),0x28,0,2);
  }
  *(undefined4 *)(in_ECX + 0x54) = uVar3;
  iVar1 = FUN_00746d70(0x468,s_C__dev_black_Lobbybox_cpp_00b20868,0x66);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0040a590(10,0xfa,0x1e0,400,0x1e,&DAT_00b6e5f0,1);
  }
  *(undefined4 *)(in_ECX + 0x48) = uVar3;
  puVar2 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_Lobbybox_cpp_00b20868,0x67);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0xdb2 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xa458;
    }
    FUN_00407730(999,0xf8,0x1c2,400,0x1e,*(undefined4 *)(iVar1 + 8));
    *puVar2 = &PTR_LAB_007ed4e8;
    puVar2[0x8f] = 2;
    *(undefined1 *)((int)puVar2 + 0x22a) = 0;
    puVar2[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x68) = puVar2;
  iVar1 = FUN_00746d70(0x244,s_C__dev_black_Lobbybox_cpp_00b20868,0x6d);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0x1a9c < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0x13f50;
    }
    uVar3 = FUN_00407d30(0x10,0x1d6,0x20d,0x96,0x1e,*(undefined4 *)(iVar1 + 8),0);
  }
  *(undefined4 *)(in_ECX + 0x58) = uVar3;
  *(undefined **)(DAT_00bf29cc + 0x30) = &DAT_00c6fec8;
  (**(code **)(**(int **)(in_ECX + 0x58) + 8))(1);
  (**(code **)(**(int **)(in_ECX + 0x1c) + 8))(0);
  iVar1 = FUN_00746d70(0x244,s_C__dev_black_Lobbybox_cpp_00b20868,0x75);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0xdb0 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xa440;
    }
    uVar3 = FUN_00407d30(6,0x28,0x19a,200,0x1e,*(undefined4 *)(iVar1 + 8),0);
  }
  *(undefined4 *)(in_ECX + 0x3c) = uVar3;
  iVar1 = FUN_00746d70(0x244,s_C__dev_black_Lobbybox_cpp_00b20868,0x76);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0xdb1 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xa44c;
    }
    uVar3 = FUN_00407d30(7,0x28,0x1bd,0x5f,0x1e,*(undefined4 *)(iVar1 + 8),0);
  }
  *(undefined4 *)(in_ECX + 0x40) = uVar3;
  iVar1 = FUN_00746d70(0x468,s_C__dev_black_Lobbybox_cpp_00b20868,0x77);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0040a590(8,0x91,0x1bd,0x5f,0x1e,&DAT_00b6e5f0,1);
  }
  *(undefined4 *)(in_ECX + 0x4c) = uVar3;
  iVar1 = FUN_00746d70(0x468,s_C__dev_black_Lobbybox_cpp_00b20868,0x78);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_0040a590(9,0x91,0x1e0,0x5f,0x1e,&DAT_00b6e5f0,1);
  }
  *(int *)(in_ECX + 0x50) = iVar1;
  *(undefined1 *)(iVar1 + 0x260) = 1;
  puVar2 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_Lobbybox_cpp_00b20868,0x7a);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0xd84 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xa230;
    }
    FUN_00407730(999,0x28,0x1e0,100,0x1e,*(undefined4 *)(iVar1 + 8));
    *puVar2 = &PTR_LAB_007ed4e8;
    puVar2[0x8f] = 2;
    *(undefined1 *)((int)puVar2 + 0x22a) = 0;
    puVar2[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 100) = puVar2;
  iVar1 = FUN_00746d70(0x244,s_C__dev_black_Lobbybox_cpp_00b20868,0x7b);
  if (iVar1 == 0) {
    uVar3 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0xdb1 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xa44c;
    }
    uVar3 = FUN_00407d30(4,0x28,0x1e0,200,0x1e,*(undefined4 *)(iVar1 + 8),0);
  }
  *(undefined4 *)(in_ECX + 0x38) = uVar3;
  iVar1 = FUN_00746d70(0x260,s_C__dev_black_Lobbybox_cpp_00b20868,0x7f);
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
  *(int *)(in_ECX + 0x80) = iVar1;
  *(undefined4 *)(iVar1 + 0x20) = 0x10;
  *(undefined4 *)(*(int *)(DAT_00c529fc + 4) + 0xac) = 0x10;
  return;
}



// ?Destroy@LobbyBox@@UAEXXZ @ 0x005b3d60

void _Destroy_LobbyBox__UAEXXZ(void)

{
  _Destroy__13DialogBoxBaseFv();
  DAT_00c529fc = 0;
  return;
}



// ?InitControls@LobbyBox@@UAEXXZ @ 0x005b3d70

void _InitControls_LobbyBox__UAEXXZ(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  *(undefined4 *)(*(int *)(DAT_00c529fc + 4) + 0xac) = 0x10;
  iVar1 = *(int *)(in_ECX + 0x48);
  FUN_00734395(iVar1 + 0x24,&DAT_00b6e5f0,0xff);
  *(undefined2 *)(iVar1 + 0x222) = 0;
  uVar3 = FUN_007343d2(iVar1 + 0x24);
  *(undefined4 *)(iVar1 + 0x24c) = uVar3;
  *(undefined4 *)(iVar1 + 0x254) = uVar3;
  *(undefined4 *)(iVar1 + 0x250) = uVar3;
  *(undefined4 *)(iVar1 + 600) = 0;
  iVar1 = *(int *)(in_ECX + 0x30);
  iVar2 = *(int *)(iVar1 + 0x250);
  while (0 < iVar2) {
    FUN_004090d0(iVar2 + -1);
    iVar2 = *(int *)(iVar1 + 0x250);
  }
  FUN_005b6350();
  iVar1 = *(int *)(in_ECX + 0x34);
  iVar2 = *(int *)(iVar1 + 0x250);
  while (0 < iVar2) {
    FUN_004090d0(iVar2 + -1);
    iVar2 = *(int *)(iVar1 + 0x250);
  }
  iVar1 = *(int *)(in_ECX + 0x2c);
  iVar2 = *(int *)(iVar1 + 0x250);
  while (0 < iVar2) {
    FUN_004090d0(iVar2 + -1);
    iVar2 = *(int *)(iVar1 + 0x250);
  }
  iVar1 = *(int *)(in_ECX + 0x30);
  iVar2 = *(int *)(iVar1 + 0x250);
  while (0 < iVar2) {
    FUN_004090d0(iVar2 + -1);
    iVar2 = *(int *)(iVar1 + 0x250);
  }
  (**(code **)(**(int **)(in_ECX + 0x58) + 8))(1);
  (**(code **)(**(int **)(in_ECX + 0x1c) + 8))(0);
  return;
}



