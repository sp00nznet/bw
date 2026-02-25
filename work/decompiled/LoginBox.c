// Decompiled functions for class: LoginBox
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Init@LoginBox@@UAEXIIP6AXHPAVSetupBox@@PAVSetupControl@@HH@Z@Z @ 0x00514be0

void _Init_LoginBox__UAEXIIP6AXHPAVSetupBox__PAVSetupControl__HH_Z_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  _Init__13DialogBoxBaseFUlUlPFiP8SetupBoxP12SetupControlii_v(param_1,param_2,param_3);
  DAT_00bf1eb4 = in_ECX;
  puVar1 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0x8e4);
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = DAT_00c38db8;
    if (0xdd2 < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa5d8;
    }
    FUN_00407730(9,100,0x32,600,0x50,*(undefined4 *)(iVar2 + 8));
    *puVar1 = &PTR_LAB_007ed4e8;
    puVar1[0x8f] = 4;
    *(undefined1 *)((int)puVar1 + 0x22a) = 0;
    puVar1[0x90] = 0;
  }
  iVar2 = FUN_00746d70(0x2b0,s_C__dev_black_frontend_cpp_00b17740,0x8e5);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_004087c0(7,0x96,0x87,500,100);
  }
  *(undefined4 *)(in_ECX + 0x1c) = uVar3;
  uVar3 = FUN_00405ed0();
  *(undefined4 *)(*(int *)(in_ECX + 0x1c) + 0x20) = uVar3;
  iVar2 = FUN_00746d70(0x468,s_C__dev_black_frontend_cpp_00b17740,0x8e7);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0xdd3 < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa5e4;
    }
    uVar3 = FUN_0040a590(10,200,0x212,400,0x1e,*(undefined4 *)(iVar2 + 8),0);
  }
  *(undefined4 *)(in_ECX + 0x20) = uVar3;
  uVar3 = FUN_00405ed0();
  *(undefined4 *)(*(int *)(in_ECX + 0x20) + 0x20) = uVar3;
  iVar2 = FUN_00746d70(0x25c,s_C__dev_black_frontend_cpp_00b17740,0x8ea);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0xd85 < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa23c;
    }
    uVar3 = FUN_0040b4a0(3,0x2a8,0x208,*(undefined4 *)(iVar2 + 8),0x28,1,3);
  }
  *(undefined4 *)(in_ECX + 0x24) = uVar3;
  iVar2 = FUN_00746d70(0x25c,s_C__dev_black_frontend_cpp_00b17740,0x8eb);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0xd7a < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa1b8;
    }
    uVar3 = FUN_0040b4a0(4,0x50,0x208,*(undefined4 *)(iVar2 + 8),0x28,0,2);
  }
  *(undefined4 *)(in_ECX + 0x28) = uVar3;
  iVar2 = FUN_00746d70(0x260,s_C__dev_black_frontend_cpp_00b17740,0x8ed);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0xd88 < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa260;
    }
    iVar2 = FUN_0040ef70(8,0x96,0xff,0,0,*(undefined4 *)(iVar2 + 8),0x19);
  }
  *(int *)(in_ECX + 0x30) = iVar2;
  *(undefined4 *)(iVar2 + 0x244) = 0;
  puVar1 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0x8ef);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0xdd4 < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa5f0;
    }
    FUN_00407730(999,0x32,300,700,0x3c,*(undefined4 *)(iVar2 + 8));
    *puVar1 = &PTR_LAB_007ed4e8;
    puVar1[0x8f] = 4;
    *(undefined1 *)((int)puVar1 + 0x22a) = 0;
    puVar1[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x4c) = puVar1;
  uVar3 = FUN_00405ef0();
  *(undefined4 *)(*(int *)(in_ECX + 0x4c) + 0x20) = uVar3;
  iVar2 = FUN_00746d70(0x468,s_C__dev_black_frontend_cpp_00b17740,0x8f2);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0040a590(0,0x140,0x168,0x14a,0x1e,&DAT_00b6e5f0,1);
  }
  *(undefined4 *)(in_ECX + 0x10) = uVar3;
  puVar1 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0x8f3);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0xd8e < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa2a8;
    }
    FUN_00407730(999,100,0x168,0xd2,0x1e,*(undefined4 *)(iVar2 + 8));
    *puVar1 = &PTR_LAB_007ed4e8;
    puVar1[0x8f] = 2;
    *(undefined1 *)((int)puVar1 + 0x22a) = 0;
    puVar1[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x48) = puVar1;
  iVar2 = FUN_00746d70(0x468,s_C__dev_black_frontend_cpp_00b17740,0x8f4);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0040a590(1,0x140,0x19a,0x14a,0x1e,&DAT_00b6e5f0,1);
  }
  *(undefined4 *)(in_ECX + 0x14) = uVar3;
  puVar1 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0x8f5);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0xd8f < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa2b4;
    }
    FUN_00407730(999,100,0x19a,0xd2,0x1e,*(undefined4 *)(iVar2 + 8));
    *puVar1 = &PTR_LAB_007ed4e8;
    puVar1[0x8f] = 2;
    *(undefined1 *)((int)puVar1 + 0x22a) = 0;
    puVar1[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x50) = puVar1;
  *(undefined1 *)(*(int *)(in_ECX + 0x14) + 0x260) = 1;
  *(undefined4 *)(*(int *)(in_ECX + 0x14) + 4) = 0;
  *(undefined4 *)(*(int *)(in_ECX + 0x10) + 4) = 0;
  uVar3 = FUN_00405ed0();
  *(undefined4 *)(*(int *)(in_ECX + 0x50) + 0x20) = uVar3;
  *(undefined4 *)(*(int *)(in_ECX + 0x14) + 0x20) = *(undefined4 *)(*(int *)(in_ECX + 0x50) + 0x20);
  *(undefined4 *)(*(int *)(in_ECX + 0x48) + 0x20) = *(undefined4 *)(*(int *)(in_ECX + 0x14) + 0x20);
  *(undefined4 *)(*(int *)(in_ECX + 0x10) + 0x20) = *(undefined4 *)(*(int *)(in_ECX + 0x48) + 0x20);
  iVar2 = FUN_00746d70(0x468,s_C__dev_black_frontend_cpp_00b17740,0x8fd);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0xd90 < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa2c0;
    }
    uVar3 = FUN_0040a590(2,0x140,0x1cc,0x14a,0x1e,*(undefined4 *)(iVar2 + 8),1);
  }
  *(undefined4 *)(in_ECX + 0x18) = uVar3;
  uVar3 = FUN_00405ee0();
  *(undefined4 *)(*(int *)(in_ECX + 0x18) + 0x20) = uVar3;
  puVar1 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0x8ff);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0xd90 < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa2c0;
    }
    FUN_00407730(999,10,0x1cc,300,0x1e,*(undefined4 *)(iVar2 + 8));
    *puVar1 = &PTR_LAB_007ed4e8;
    puVar1[0x8f] = 2;
    *(undefined1 *)((int)puVar1 + 0x22a) = 0;
    puVar1[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x44) = puVar1;
  uVar3 = FUN_00405ed0();
  *(undefined4 *)(*(int *)(in_ECX + 0x44) + 0x20) = uVar3;
  iVar2 = FUN_00746d70(0x260,s_C__dev_black_frontend_cpp_00b17740,0x905);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0xd89 < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa26c;
    }
    iVar2 = FUN_0040ef70(5,0x46,0x23a,0,0,*(undefined4 *)(iVar2 + 8),0x14);
  }
  *(int *)(in_ECX + 0x2c) = iVar2;
  *(undefined4 *)(iVar2 + 0x20) = 0xc;
  iVar2 = FUN_00746d70(0x260,s_C__dev_black_frontend_cpp_00b17740,0x907);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0xd8a < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa278;
    }
    iVar2 = FUN_0040ef70(6,200,0x23a,0,0,*(undefined4 *)(iVar2 + 8),0x14);
  }
  *(int *)(in_ECX + 0x34) = iVar2;
  *(undefined4 *)(iVar2 + 0x20) = 0xc;
  iVar2 = FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0x90a);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0xd8b < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa284;
    }
    uVar3 = FUN_00407d30(0xd,0x140,0x244,100,0x19,*(undefined4 *)(iVar2 + 8),0);
  }
  *(undefined4 *)(in_ECX + 0x38) = uVar3;
  iVar2 = FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0x90b);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0xd8c < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa290;
    }
    uVar3 = FUN_00407d30(0xe,0x1b8,0x244,100,0x19,*(undefined4 *)(iVar2 + 8),0);
  }
  *(undefined4 *)(in_ECX + 0x3c) = uVar3;
  iVar2 = FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0x90c);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0xd8d < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa29c;
    }
    uVar3 = FUN_00407d30(0xf,0x230,0x244,100,0x19,*(undefined4 *)(iVar2 + 8),0);
  }
  *(undefined4 *)(in_ECX + 0x40) = uVar3;
  *(undefined4 *)(*(int *)(in_ECX + 0x38) + 0x20) = 0x10;
  *(undefined4 *)(*(int *)(in_ECX + 0x3c) + 0x20) = 0x10;
  *(undefined4 *)(*(int *)(in_ECX + 0x40) + 0x20) = 0x10;
  (**(code **)(**(int **)(in_ECX + 0x2c) + 8))(1);
  (**(code **)(**(int **)(in_ECX + 0x34) + 8))(1);
  (**(code **)(**(int **)(in_ECX + 0x38) + 8))(1);
  (**(code **)(**(int **)(in_ECX + 0x3c) + 8))(1);
  (**(code **)(**(int **)(in_ECX + 0x40) + 8))(1);
  FUN_00407620(*(undefined4 *)(in_ECX + 0x10));
  *(undefined4 *)(in_ECX + 0x54) = 0;
  return;
}



// ?Destroy@LoginBox@@UAEXXZ @ 0x00515390

void _Destroy_LoginBox__UAEXXZ(void)

{
  Dialup *this;
  int in_ECX;
  
  FUN_00515a10();
  if (*(Dialup **)(in_ECX + 0x54) != (Dialup *)0x0) {
    Dialup::Release(*(Dialup **)(in_ECX + 0x54));
    this = *(Dialup **)(in_ECX + 0x54);
    if (this != (Dialup *)0x0) {
      Dialup::~Dialup(this);
      FUN_007290de(this);
    }
    *(undefined4 *)(in_ECX + 0x54) = 0;
  }
  _Destroy__13DialogBoxBaseFv();
  DAT_00bf1eb4 = 0;
  return;
}



