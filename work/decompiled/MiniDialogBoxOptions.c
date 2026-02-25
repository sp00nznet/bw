// Decompiled functions for class: MiniDialogBoxOptions
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Init@MiniDialogBoxOptions@@UAEXIIP6AXHPAVSetupBox@@PAVSetupControl@@HH@Z@Z @ 0x004f19e0

void _Init_MiniDialogBoxOptions__UAEXIIP6AXHPAVSetupBox__PAVSetupControl__HH_Z_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  int in_ECX;
  
  _Init__13DialogBoxBaseFUlUlPFiP8SetupBoxP12SetupControlii_v(param_1,param_2,param_3);
  puVar1 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_DialogBoxOptions_cp_00b16860,0x3ac);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0xd64 < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa0b0;
    }
    FUN_00407730(999,0x32,0x3c,700,0x28,*(undefined4 *)(iVar2 + 8));
    *puVar1 = &PTR_LAB_007ed4e8;
    puVar1[0x8f] = 4;
    *(undefined1 *)((int)puVar1 + 0x22a) = 0;
    puVar1[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x28) = puVar1;
  iVar2 = FUN_00420f70();
  iVar3 = FUN_00746d70(0x260,s_C__dev_black_DialogBoxOptions_cp_00b16860,0x3b1);
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = DAT_00c38db8;
    if (0xdc8 < DAT_00c38dbc) {
      iVar3 = DAT_00c38db8 + 0xa560;
    }
    iVar3 = FUN_0040ef70(0x75,0x11d,0x1c2,0,0,*(undefined4 *)(iVar3 + 8),0x19);
  }
  *(int *)(in_ECX + 0x34) = iVar3;
  *(undefined4 *)(iVar3 + 0x248) = 1;
  iVar3 = FUN_00746d70(0x260,s_C__dev_black_DialogBoxOptions_cp_00b16860,0x3b4);
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = DAT_00c38db8;
    if (0x1a96 < DAT_00c38dbc) {
      iVar3 = DAT_00c38db8 + 0x13f08;
    }
    iVar3 = FUN_0040ef70(0x76,0x1e5,0x1c2,0,0,*(undefined4 *)(iVar3 + 8),0x19);
  }
  *(int *)(in_ECX + 0x38) = iVar3;
  *(undefined4 *)(iVar3 + 0x248) = 0;
  iVar3 = FUN_00746d70(0x250,s_C__dev_black_DialogBoxOptions_cp_00b16860,0x3b7);
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    iVar3 = DAT_00c38db8;
    if (0xd66 < DAT_00c38dbc) {
      iVar3 = DAT_00c38db8 + 0xa0c8;
    }
    uVar4 = FUN_00407fc0(100,0xfa,0x8c,300,0x1e,0,*(undefined4 *)(iVar3 + 8));
  }
  *(undefined4 *)(in_ECX + 0x10) = uVar4;
  uVar4 = FUN_00405ed0();
  *(undefined4 *)(*(int *)(in_ECX + 0x10) + 0x20) = uVar4;
  *(undefined1 **)(*(int *)(in_ECX + 0x10) + 0x238) = &LAB_004f1f90;
  iVar3 = FUN_00746d70(0x250,s_C__dev_black_DialogBoxOptions_cp_00b16860,0x3ba);
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    iVar3 = DAT_00c38db8;
    if (0xd67 < DAT_00c38dbc) {
      iVar3 = DAT_00c38db8 + 0xa0d4;
    }
    uVar4 = FUN_00407fc0(0x65,0xfa,200,300,0x1e,0,*(undefined4 *)(iVar3 + 8));
  }
  *(undefined4 *)(in_ECX + 0x14) = uVar4;
  uVar4 = FUN_00405ed0();
  *(undefined4 *)(*(int *)(in_ECX + 0x14) + 0x20) = uVar4;
  *(undefined1 **)(*(int *)(in_ECX + 0x14) + 0x238) = &LAB_004f1fc0;
  puVar1 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_DialogBoxOptions_cp_00b16860,0x3be);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    iVar3 = DAT_00c38db8;
    if (0xd65 < DAT_00c38dbc) {
      iVar3 = DAT_00c38db8 + 0xa0bc;
    }
    FUN_00407730(999,0x32,0x118,700,0x28,*(undefined4 *)(iVar3 + 8));
    *puVar1 = &PTR_LAB_007ed4e8;
    puVar1[0x8f] = 1;
    *(undefined1 *)((int)puVar1 + 0x22a) = 0;
    puVar1[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x2c) = puVar1;
  puVar1 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_DialogBoxOptions_cp_00b16860,0x3bf);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    iVar3 = DAT_00c38db8;
    if (0xde6 < DAT_00c38dbc) {
      iVar3 = DAT_00c38db8 + 0xa6c8;
    }
    FUN_00407730(999,0x32,0x10e,700,0x8c,*(undefined4 *)(iVar3 + 8));
    *puVar1 = &PTR_LAB_007ed4e8;
    puVar1[0x8f] = 4;
    *(undefined1 *)((int)puVar1 + 0x22a) = 0;
    puVar1[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x30) = puVar1;
  uVar4 = FUN_00405ed0();
  *(undefined4 *)(*(int *)(in_ECX + 0x30) + 0x20) = uVar4;
  iVar3 = FUN_00746d70(0x244,s_C__dev_black_DialogBoxOptions_cp_00b16860,0x3c3);
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    uVar4 = FUN_00407d30(0x66,300,0x15e,200,0x1e,&DAT_008fd4c8,0);
  }
  *(undefined4 *)(in_ECX + 0x44) = uVar4;
  uVar4 = FUN_00405ed0();
  *(undefined4 *)(*(int *)(in_ECX + 0x44) + 0x20) = uVar4;
  *(undefined1 **)(*(int *)(in_ECX + 0x44) + 0x238) = &LAB_004f2080;
  iVar3 = FUN_00746d70(0x25c,s_C__dev_black_DialogBoxOptions_cp_00b16860,0x3c6);
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_0040b4a0(0x68,0x104,0x15d,&DAT_008fd4c8,0x20,0,2);
  }
  *(int *)(in_ECX + 0x18) = iVar3;
  *(undefined1 **)(iVar3 + 0x238) = &LAB_004f20e0;
  iVar3 = FUN_00746d70(0x25c,s_C__dev_black_DialogBoxOptions_cp_00b16860,0x3c8);
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_0040b4a0(0x67,0x1fc,0x15d,&DAT_008fd4c8,0x20,0,3);
  }
  *(int *)(in_ECX + 0x1c) = iVar3;
  *(undefined1 **)(iVar3 + 0x238) = &LAB_004f2080;
  uVar4 = FUN_004f0a90();
  FUN_004f09c0(uVar4);
  (**(code **)(**(int **)(in_ECX + 0x10) + 8))(iVar2 == 0);
  (**(code **)(**(int **)(in_ECX + 0x14) + 8))(iVar2 == 0);
  uVar5 = FUN_004228b0();
  *(float *)(*(int *)(in_ECX + 0x10) + 0x23c) = (float)uVar5 * 0.007874016;
  iVar2 = FUN_004228c0();
  *(float *)(*(int *)(in_ECX + 0x14) + 0x23c) = (float)iVar2 * 0.007874016;
  iVar2 = FUN_00746d70(0x25c,s_C__dev_black_DialogBoxOptions_cp_00b16860,999);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0xd7a < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa1b8;
    }
    iVar2 = FUN_0040b4a0(0x7a,0x1e,0x212,*(undefined4 *)(iVar2 + 8),0x28,0,2);
  }
  *(int *)(in_ECX + 0x20) = iVar2;
  *(undefined1 **)(iVar2 + 0x238) = &LAB_004f1ff0;
  uVar4 = FUN_00405ed0();
  *(undefined4 *)(*(int *)(in_ECX + 0x20) + 0x20) = uVar4;
  iVar2 = FUN_00746d70(0x25c,s_C__dev_black_DialogBoxOptions_cp_00b16860,0x3eb);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0xd53 < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0x9fe4;
    }
    iVar2 = FUN_0040b4a0(0x7b,0x2da,0x212,*(undefined4 *)(iVar2 + 8),0x28,1,3);
  }
  *(int *)(in_ECX + 0x24) = iVar2;
  *(undefined1 **)(iVar2 + 0x238) = &LAB_004f1ff0;
  uVar4 = FUN_00405ed0();
  *(undefined4 *)(*(int *)(in_ECX + 0x24) + 0x20) = uVar4;
  *(undefined1 **)(*(int *)(in_ECX + 0x24) + 0x238) = &LAB_00513710;
  FUN_00513120(1);
  return;
}



// ?InitControls@MiniDialogBoxOptions@@UAEXXZ @ 0x004f2110

void _InitControls_MiniDialogBoxOptions__UAEXXZ(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int in_ECX;
  bool bVar5;
  
  iVar2 = FUN_00420f70();
  bVar5 = iVar2 == 0;
  (**(code **)(**(int **)(in_ECX + 0x10) + 8))(bVar5);
  (**(code **)(**(int **)(in_ECX + 0x14) + 8))(bVar5);
  (**(code **)(**(int **)(in_ECX + 0x28) + 8))(bVar5);
  (**(code **)(**(int **)(in_ECX + 0x30) + 8))(iVar2 == 1);
  uVar3 = FUN_004228b0();
  *(float *)(*(int *)(in_ECX + 0x10) + 0x23c) = (float)uVar3 * 0.007874016;
  iVar4 = FUN_004228c0();
  *(float *)(*(int *)(in_ECX + 0x14) + 0x23c) = (float)iVar4 * 0.007874016;
  iVar4 = DAT_00c38db8;
  if (0xd64 < DAT_00c38dbc) {
    iVar4 = DAT_00c38db8 + 0xa0b0;
  }
  FUN_00733ff8(*(int *)(in_ECX + 0x28) + 0x24,*(undefined4 *)(iVar4 + 8));
  piVar1 = (int *)(*(int *)(in_ECX + 0x28) + 0x14);
  *piVar1 = *piVar1 - *(int *)(*(int *)(in_ECX + 0x28) + 0xc);
  piVar1 = (int *)(*(int *)(in_ECX + 0x2c) + 0x14);
  *piVar1 = *piVar1 - *(int *)(*(int *)(in_ECX + 0x2c) + 0xc);
  piVar1 = (int *)(*(int *)(in_ECX + 0x44) + 0x14);
  *piVar1 = *piVar1 - *(int *)(*(int *)(in_ECX + 0x44) + 0xc);
  piVar1 = (int *)(*(int *)(in_ECX + 0x18) + 0x14);
  *piVar1 = *piVar1 - *(int *)(*(int *)(in_ECX + 0x18) + 0xc);
  iVar4 = *(int *)(in_ECX + 0x1c);
  *(int *)(iVar4 + 0x14) = *(int *)(iVar4 + 0x14) - *(int *)(iVar4 + 0xc);
  if (iVar2 == 0) {
    *(undefined4 *)(*(int *)(in_ECX + 0x2c) + 0xc) = 0x3c;
    *(undefined4 *)(*(int *)(in_ECX + 0x44) + 0xc) = 0x78;
    *(undefined4 *)(*(int *)(in_ECX + 0x1c) + 0xc) = 0x77;
    *(undefined4 *)(*(int *)(in_ECX + 0x18) + 0xc) = 0x77;
  }
  else {
    *(undefined4 *)(*(int *)(in_ECX + 0x2c) + 0xc) = 0x118;
    *(undefined4 *)(*(int *)(in_ECX + 0x44) + 0xc) = 0x15e;
    *(undefined4 *)(*(int *)(in_ECX + 0x1c) + 0xc) = 0x15d;
    *(undefined4 *)(*(int *)(in_ECX + 0x18) + 0xc) = 0x15d;
  }
  piVar1 = (int *)(*(int *)(in_ECX + 0x28) + 0x14);
  *piVar1 = *piVar1 + *(int *)(*(int *)(in_ECX + 0x28) + 0xc);
  piVar1 = (int *)(*(int *)(in_ECX + 0x2c) + 0x14);
  *piVar1 = *piVar1 + *(int *)(*(int *)(in_ECX + 0x2c) + 0xc);
  piVar1 = (int *)(*(int *)(in_ECX + 0x44) + 0x14);
  *piVar1 = *piVar1 + *(int *)(*(int *)(in_ECX + 0x44) + 0xc);
  piVar1 = (int *)(*(int *)(in_ECX + 0x18) + 0x14);
  *piVar1 = *piVar1 + *(int *)(*(int *)(in_ECX + 0x18) + 0xc);
  iVar4 = *(int *)(in_ECX + 0x1c);
  *(int *)(iVar4 + 0x14) = *(int *)(iVar4 + 0x14) + *(int *)(iVar4 + 0xc);
  return;
}



// ?CanESCOut@MiniDialogBoxOptions@@UAE_NXZ @ 0x004f2290

bool _CanESCOut_MiniDialogBoxOptions__UAE_NXZ(void)

{
  return *(int *)(*(int *)(DAT_00c22ca4 + 0x24c3b0) + 0x5c) ==
         *(int *)(*(int *)(DAT_00c22ca4 + 0x24c3b0) + 0x54);
}



