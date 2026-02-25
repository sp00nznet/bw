// Decompiled functions for class: RegisterBox
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Init@RegisterBox@@UAEXIIP6AXHPAVSetupBox@@PAVSetupControl@@HH@Z@Z @ 0x005113b0

void _Init_RegisterBox__UAEXIIP6AXHPAVSetupBox__PAVSetupControl__HH_Z_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  _Init__13DialogBoxBaseFUlUlPFiP8SetupBoxP12SetupControlii_v(param_1,param_2,param_3);
  DAT_00bf1e80 = in_ECX;
  puVar1 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0x301);
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = DAT_00c38db8;
    if (0xd82 < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa218;
    }
    FUN_00407730(999,100,0x96,600,0xfa,*(undefined4 *)(iVar2 + 8));
    *puVar1 = &PTR_LAB_007ed4e8;
    puVar1[0x8f] = 4;
    *(undefined1 *)((int)puVar1 + 0x22a) = 0;
    puVar1[0x90] = 0;
  }
  iVar2 = FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0x302);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0xd86 < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa248;
    }
    uVar3 = FUN_00407d30(2,0x136,0x1ae,200,0x32,*(undefined4 *)(iVar2 + 8),0);
  }
  *(undefined4 *)(in_ECX + 0x20) = uVar3;
  iVar2 = FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0x303);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0xd85 < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa23c;
    }
    uVar3 = FUN_00407d30(1,100,0x1ae,200,0x32,*(undefined4 *)(iVar2 + 8),0);
  }
  *(undefined4 *)(in_ECX + 0x18) = uVar3;
  iVar2 = FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0x304);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0xa23 < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0x79a4;
    }
    uVar3 = FUN_00407d30(3,0x208,0x1ae,200,0x32,*(undefined4 *)(iVar2 + 8),0);
  }
  *(undefined4 *)(in_ECX + 0x1c) = uVar3;
  iVar2 = FUN_00746d70(0x468,s_C__dev_black_frontend_cpp_00b17740,0x306);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0040a590(4,0xfa,300,300,0x32,&DAT_00b6e5f0,1);
  }
  *(undefined4 *)(in_ECX + 0x10) = uVar3;
  iVar2 = FUN_00746d70(0x468,s_C__dev_black_frontend_cpp_00b17740,0x307);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0040a590(5,0xfa,0x168,300,0x32,&DAT_00b6e5f0,1);
  }
  *(int *)(in_ECX + 0x14) = iVar2;
  *(undefined1 *)(iVar2 + 0x260) = 1;
  puVar1 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0x30a);
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = DAT_00c38db8;
    if (0xd83 < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa224;
    }
    FUN_00407730(999,0x32,300,200,0x32,*(undefined4 *)(iVar2 + 8));
    *puVar1 = &PTR_LAB_007ed4e8;
    puVar1[0x8f] = 2;
    *(undefined1 *)((int)puVar1 + 0x22a) = 0;
    puVar1[0x90] = 0;
  }
  puVar1 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0x30b);
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = DAT_00c38db8;
    if (0xd84 < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa230;
    }
    FUN_00407730(999,0x32,0x168,200,0x32,*(undefined4 *)(iVar2 + 8));
    *puVar1 = &PTR_LAB_007ed4e8;
    puVar1[0x8f] = 2;
    *(undefined1 *)((int)puVar1 + 0x22a) = 0;
    puVar1[0x90] = 0;
  }
  *(undefined1 *)(in_ECX + 0x24) = 0;
  return;
}



// ?Destroy@RegisterBox@@UAEXXZ @ 0x005116e0

void _Destroy_RegisterBox__UAEXXZ(void)

{
  _Destroy__13DialogBoxBaseFv();
  DAT_00bf1e80 = 0;
  return;
}



// ?InitControls@RegisterBox@@UAEXXZ @ 0x005116f0

void _InitControls_RegisterBox__UAEXXZ(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  FUN_00407620(*(undefined4 *)(in_ECX + 0x10));
  iVar1 = *(int *)(in_ECX + 0x10);
  FUN_00734395(iVar1 + 0x24,&DAT_00b6e5f0,0xff);
  *(undefined2 *)(iVar1 + 0x222) = 0;
  uVar2 = FUN_007343d2(iVar1 + 0x24);
  *(undefined4 *)(iVar1 + 0x24c) = uVar2;
  *(undefined4 *)(iVar1 + 0x254) = uVar2;
  *(undefined4 *)(iVar1 + 0x250) = uVar2;
  *(undefined4 *)(iVar1 + 600) = 0;
  iVar1 = *(int *)(in_ECX + 0x14);
  FUN_00734395(iVar1 + 0x24,&DAT_00b6e5f0,0xff);
  *(undefined2 *)(iVar1 + 0x222) = 0;
  uVar2 = FUN_007343d2(iVar1 + 0x24);
  *(undefined4 *)(iVar1 + 600) = 0;
  *(undefined4 *)(iVar1 + 0x24c) = uVar2;
  *(undefined4 *)(iVar1 + 0x254) = uVar2;
  *(undefined4 *)(iVar1 + 0x250) = uVar2;
  *(undefined1 *)(in_ECX + 0x24) = 0;
  return;
}



