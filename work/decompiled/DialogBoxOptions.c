// Decompiled functions for class: DialogBoxOptions
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?CanESCOut@DialogBoxOptions@@UAE_NXZ @ 0x004f0340

bool _CanESCOut_DialogBoxOptions__UAE_NXZ(void)

{
  return *(int *)(*(int *)(DAT_00c22ca4 + 0x24c3b0) + 0x5c) ==
         *(int *)(*(int *)(DAT_00c22ca4 + 0x24c3b0) + 0x54);
}



// ?Init@DialogBoxOptions@@UAEXIIP6AXHPAVSetupBox@@PAVSetupControl@@HH@Z@Z @ 0x004f0370

void _Init_DialogBoxOptions__UAEXIIP6AXHPAVSetupBox__PAVSetupControl__HH_Z_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x58) = 5;
  *(undefined4 *)(in_ECX + 0x54) = 0;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  *(undefined4 *)(in_ECX + 0x5c) = 0;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  DAT_00be7618 = 0;
  _Init__13DialogBoxBaseFUlUlPFiP8SetupBoxP12SetupControlii_v(param_1,param_2,param_3);
  puVar1 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_DialogBoxOptions_cp_00b16860,0x3e);
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = DAT_00c38db8;
    if (0xd6a < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa0f8;
    }
    FUN_00407730(999,0x32,0x3c,700,0x28,*(undefined4 *)(iVar2 + 8));
    *puVar1 = &PTR_LAB_007ed4e8;
    puVar1[0x8f] = 4;
    *(undefined1 *)((int)puVar1 + 0x22a) = 0;
    puVar1[0x90] = 0;
  }
  iVar2 = FUN_00746d70(0x244,s_C__dev_black_DialogBoxOptions_cp_00b16860,0x40);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00407d30(0x6b,300,0x96,200,0x1e,&DAT_008fd4c8,0);
  }
  *(undefined4 *)(in_ECX + 0x10) = uVar3;
  uVar3 = FUN_00405ed0();
  *(undefined4 *)(*(int *)(in_ECX + 0x10) + 0x20) = uVar3;
  iVar2 = FUN_00746d70(0x25c,s_C__dev_black_DialogBoxOptions_cp_00b16860,0x42);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0040b4a0(0x6d,0x104,0x95,&DAT_008fd4c8,0x20,0,2);
  }
  *(undefined4 *)(in_ECX + 0x14) = uVar3;
  iVar2 = FUN_00746d70(0x25c,s_C__dev_black_DialogBoxOptions_cp_00b16860,0x43);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0040b4a0(0x6c,0x1fc,0x95,&DAT_008fd4c8,0x20,0,3);
  }
  *(undefined4 *)(in_ECX + 0x18) = uVar3;
  iVar2 = FUN_00746d70(0x244,s_C__dev_black_DialogBoxOptions_cp_00b16860,0x45);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00407d30(0x6e,300,0xd7,200,0x1e,&DAT_008fd4c8,0);
  }
  *(undefined4 *)(in_ECX + 0x1c) = uVar3;
  uVar3 = FUN_00405ed0();
  *(undefined4 *)(*(int *)(in_ECX + 0x1c) + 0x20) = uVar3;
  iVar2 = FUN_00746d70(0x25c,s_C__dev_black_DialogBoxOptions_cp_00b16860,0x47);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0040b4a0(0x70,0x104,0xd6,&DAT_008fd4c8,0x20,0,2);
  }
  *(undefined4 *)(in_ECX + 0x20) = uVar3;
  iVar2 = FUN_00746d70(0x25c,s_C__dev_black_DialogBoxOptions_cp_00b16860,0x48);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0040b4a0(0x6f,0x1fc,0xd6,&DAT_008fd4c8,0x20,0,3);
  }
  *(undefined4 *)(in_ECX + 0x24) = uVar3;
  iVar2 = FUN_00746d70(0x244,s_C__dev_black_DialogBoxOptions_cp_00b16860,0x4a);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00407d30(0x71,300,0x118,200,0x1e,&DAT_00b6e5f0,0);
  }
  *(undefined4 *)(in_ECX + 0x28) = uVar3;
  uVar3 = FUN_00405ed0();
  *(undefined4 *)(*(int *)(in_ECX + 0x28) + 0x20) = uVar3;
  iVar2 = FUN_00746d70(0x25c,s_C__dev_black_DialogBoxOptions_cp_00b16860,0x4c);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0040b4a0(0x72,0x104,0x117,&DAT_00b6e5f0,0x20,0,2);
  }
  *(undefined4 *)(in_ECX + 0x2c) = uVar3;
  iVar2 = FUN_00746d70(0x25c,s_C__dev_black_DialogBoxOptions_cp_00b16860,0x4d);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_0040b4a0(0x73,0x1fc,0x117,&DAT_00b6e5f0,0x20,0,3);
  }
  *(undefined4 *)(in_ECX + 0x30) = uVar3;
  iVar2 = FUN_00746d70(0x250,s_C__dev_black_DialogBoxOptions_cp_00b16860,0x4f);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0xd78 < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa1a0;
    }
    uVar3 = FUN_00407fc0(0x78,0xfa,0x16d,300,0x1e,0,*(undefined4 *)(iVar2 + 8));
  }
  *(undefined4 *)(in_ECX + 0x40) = uVar3;
  uVar3 = FUN_00405ed0();
  *(undefined4 *)(*(int *)(in_ECX + 0x40) + 0x20) = uVar3;
  iVar2 = FUN_00420f70();
  (**(code **)(**(int **)(in_ECX + 0x40) + 8))(iVar2 == 1);
  iVar2 = FUN_00746d70(0x260,s_C__dev_black_DialogBoxOptions_cp_00b16860,0x62);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0xd77 < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa194;
    }
    uVar3 = FUN_0040ef70(0x74,0x181,0x1c2,0,0,*(undefined4 *)(iVar2 + 8),0x19);
  }
  *(undefined4 *)(in_ECX + 0x34) = uVar3;
  iVar2 = FUN_00746d70(0x260,s_C__dev_black_DialogBoxOptions_cp_00b16860,99);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0xd69 < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa0ec;
    }
    uVar3 = FUN_0040ef70(0x69,0xb9,0x1c2,0,0,*(undefined4 *)(iVar2 + 8),0x19);
  }
  *(undefined4 *)(in_ECX + 0x38) = uVar3;
  iVar2 = FUN_00746d70(0x260,s_C__dev_black_DialogBoxOptions_cp_00b16860,100);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0x1aa0 < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0x13f80;
    }
    uVar3 = FUN_0040ef70(0x6a,0x249,0x1c2,0,0,*(undefined4 *)(iVar2 + 8),0x19);
  }
  *(undefined4 *)(in_ECX + 0x3c) = uVar3;
  iVar2 = FUN_00746d70(0x25c,s_C__dev_black_DialogBoxOptions_cp_00b16860,0x6e);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0xd7a < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa1b8;
    }
    uVar3 = FUN_0040b4a0(0x7a,0x1e,0x212,*(undefined4 *)(iVar2 + 8),0x28,0,2);
  }
  *(undefined4 *)(in_ECX + 0x44) = uVar3;
  uVar3 = FUN_00405ed0();
  *(undefined4 *)(*(int *)(in_ECX + 0x44) + 0x20) = uVar3;
  FUN_00513120(3);
  iVar2 = FUN_00746d70(0x48,s_C__dev_black_DialogBoxOptions_cp_00b16860,0x74);
  if (iVar2 == 0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = (undefined4 *)FUN_004f19c0();
  }
  *(undefined4 **)(in_ECX + 0x60) = puVar1;
  (**(code **)*puVar1)(0x30c,500,&LAB_004f0bb0);
  iVar2 = FUN_00746d70(0x30,s_C__dev_black_DialogBoxOptions_cp_00b16860,0x77);
  if (iVar2 == 0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = (undefined4 *)FUN_004f14c0();
  }
  *(undefined4 **)(in_ECX + 100) = puVar1;
  (**(code **)*puVar1)(0x30c,500,&LAB_004f1840);
  return;
}



// ?Destroy@DialogBoxOptions@@UAEXXZ @ 0x004f08b0

void _Destroy_DialogBoxOptions__UAEXXZ(void)

{
  int in_ECX;
  
  _Destroy__13DialogBoxBaseFv();
  *(undefined4 *)(in_ECX + 0x40) = 0;
  return;
}



// ?InitControls@DialogBoxOptions@@UAEXXZ @ 0x004f08d0

void _InitControls_DialogBoxOptions__UAEXXZ(void)

{
  int in_ECX;
  
  if (DAT_00bf4e68 != 0) {
    FUN_00420f70();
  }
  *(undefined4 *)(in_ECX + 0x48) = 0;
  *(undefined4 *)(in_ECX + 0x50) = 0;
  *(undefined4 *)(in_ECX + 0x4c) = 0;
  *(undefined4 *)(in_ECX + 0x54) = 0;
  *(undefined4 *)(in_ECX + 0x58) = 5;
  FUN_004f1110();
  *(undefined4 *)(in_ECX + 0x5c) = *(undefined4 *)(in_ECX + 0x54);
  (**(code **)(**(int **)(in_ECX + 0x60) + 0x20))();
  (**(code **)(**(int **)(in_ECX + 100) + 0x20))();
  return;
}



