// Decompiled functions for class: NewProfileBox
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Init@NewProfileBox@@UAEXIIP6AXHPAVSetupBox@@PAVSetupControl@@HH@Z@Z @ 0x00510a80

void _Init_NewProfileBox__UAEXIIP6AXHPAVSetupBox__PAVSetupControl__HH_Z_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  _Init__13DialogBoxBaseFUlUlPFiP8SetupBoxP12SetupControlii_v(param_1,param_2,param_3);
  DAT_00bf1e74 = in_ECX;
  iVar1 = FUN_00746d70(0x294,s_C__dev_black_frontend_cpp_00b17740,0x211);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0040e6d0(0x7b,0x170,300,DAT_00bf1a48,0,4,1,0x40,0);
  }
  *(undefined4 *)(in_ECX + 0x1c) = uVar2;
  puVar3 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0x213);
  if (puVar3 != (undefined4 *)0x0) {
    iVar1 = DAT_00c38db8;
    if (0xd7e < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xa1e8;
    }
    FUN_00407730(999,100,0x96,600,0x32,*(undefined4 *)(iVar1 + 8));
    *puVar3 = &PTR_LAB_007ed4e8;
    puVar3[0x8f] = 1;
    *(undefined1 *)((int)puVar3 + 0x22a) = 0;
    puVar3[0x90] = 0;
  }
  iVar1 = FUN_00746d70(0x25c,s_C__dev_black_frontend_cpp_00b17740,0x215);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0xa23 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0x79a4;
    }
    uVar2 = FUN_0040b4a0(2,0x262,400,*(undefined4 *)(iVar1 + 8),0x28,1,3);
  }
  *(undefined4 *)(in_ECX + 0x18) = uVar2;
  iVar1 = FUN_00746d70(0x25c,s_C__dev_black_frontend_cpp_00b17740,0x216);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0xa24 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0x79b0;
    }
    uVar2 = FUN_0040b4a0(1,0x96,400,*(undefined4 *)(iVar1 + 8),0x28,0,2);
  }
  *(undefined4 *)(in_ECX + 0x14) = uVar2;
  puVar3 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0x21b);
  if (puVar3 != (undefined4 *)0x0) {
    iVar1 = DAT_00c38db8;
    if (0xd7f < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xa1f4;
    }
    FUN_00407730(999,100,300,0xfa,0x40,*(undefined4 *)(iVar1 + 8));
    *puVar3 = &PTR_LAB_007ed4e8;
    puVar3[0x8f] = 2;
    *(undefined1 *)((int)puVar3 + 0x22a) = 0;
    puVar3[0x90] = 0;
  }
  puVar3 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0x21c);
  if (puVar3 != (undefined4 *)0x0) {
    iVar1 = DAT_00c38db8;
    if (0xd80 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xa200;
    }
    FUN_00407730(999,0x1c2,300,0xfa,0x40,*(undefined4 *)(iVar1 + 8));
    *puVar3 = &PTR_LAB_007ed4e8;
    puVar3[0x8f] = 0;
    *(undefined1 *)((int)puVar3 + 0x22a) = 0;
    puVar3[0x90] = 0;
  }
  iVar1 = FUN_00746d70(0x468,s_C__dev_black_frontend_cpp_00b17740,0x21f);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_0040a590(3,200,0xe6,400,0x32,&DAT_00b6e5f0,1);
  }
  *(int *)(in_ECX + 0x10) = iVar1;
  *(undefined4 *)(iVar1 + 0x240) = 0x1d;
  *(undefined1 *)(DAT_00bf1e74 + 0x20) = 0;
  return;
}



// ?Destroy@NewProfileBox@@UAEXXZ @ 0x00510d50

void _Destroy_NewProfileBox__UAEXXZ(void)

{
  _Destroy__13DialogBoxBaseFv();
  DAT_00bf1e74 = 0;
  return;
}



// ?InitControls@NewProfileBox@@UAEXXZ @ 0x00510d60

void _InitControls_NewProfileBox__UAEXXZ(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  
  FUN_00407620(*(undefined4 *)(in_ECX + 0x10));
  iVar2 = *(int *)(in_ECX + 0x10);
  FUN_00734395(iVar2 + 0x24,&DAT_00b6e5f0,0xff);
  *(undefined2 *)(iVar2 + 0x222) = 0;
  uVar1 = FUN_007343d2(iVar2 + 0x24);
  *(undefined4 *)(iVar2 + 0x24c) = uVar1;
  *(undefined4 *)(iVar2 + 0x254) = uVar1;
  *(undefined4 *)(iVar2 + 0x250) = uVar1;
  *(undefined4 *)(iVar2 + 600) = 0;
  iVar2 = FUN_00615f80();
  if (iVar2 == 0) {
    (**(code **)(**(int **)(in_ECX + 0x18) + 8))(1);
  }
  else {
    (**(code **)(**(int **)(in_ECX + 0x18) + 8))(0);
  }
  *(int *)(*(int *)(in_ECX + 0x14) + 0x10) = *(int *)(*(int *)(in_ECX + 0x14) + 8) + 0x28;
  *(int *)(*(int *)(in_ECX + 0x18) + 0x10) = *(int *)(*(int *)(in_ECX + 0x18) + 8) + 0x28;
  *(int *)(*(int *)(in_ECX + 0x1c) + 0x284) =
       (int)(0 % (ulonglong)*(uint *)(*(int *)(in_ECX + 0x1c) + 0x28c));
  *(undefined1 *)(DAT_00bf1e74 + 0x20) = 0;
  return;
}



