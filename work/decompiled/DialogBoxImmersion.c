// Decompiled functions for class: DialogBoxImmersion
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Init@DialogBoxImmersion@@UAEXIIP6AXHPAVSetupBox@@PAVSetupControl@@HH@Z@Z @ 0x004f1560

void _Init_DialogBoxImmersion__UAEXIIP6AXHPAVSetupBox__PAVSetupControl__HH_Z_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  _Init__13DialogBoxBaseFUlUlPFiP8SetupBoxP12SetupControlii_v(param_1,param_2,param_3);
  puVar1 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_DialogBoxOptions_cp_00b16860,0x2f1);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0x1a69 < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0x13cec;
    }
    FUN_00407730(999,0x32,0x3c,700,0x28,*(undefined4 *)(iVar2 + 8));
    *puVar1 = &PTR_LAB_007ed4e8;
    puVar1[0x8f] = 4;
    *(undefined1 *)((int)puVar1 + 0x22a) = 0;
    puVar1[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x10) = puVar1;
  puVar1 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_DialogBoxOptions_cp_00b16860,0x2f2);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0x1a69 < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0x13cec;
    }
    FUN_00407730(999,0x32,0x1b8,700,0x5a,*(undefined4 *)(iVar2 + 8));
    *puVar1 = &PTR_LAB_007ed4e8;
    puVar1[0x8f] = 4;
    *(undefined1 *)((int)puVar1 + 0x22a) = 0;
    puVar1[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x14) = puVar1;
  puVar1[8] = 0x1e;
  iVar2 = FUN_00746d70(0x244,s_C__dev_black_DialogBoxOptions_cp_00b16860,0x2f6);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_00407d30(0x7d,300,200,200,0x1e,&DAT_008fd4c8,0);
  }
  *(undefined4 *)(in_ECX + 0x20) = uVar3;
  uVar3 = FUN_00405ed0();
  *(undefined4 *)(*(int *)(in_ECX + 0x20) + 0x20) = uVar3;
  *(undefined1 **)(*(int *)(in_ECX + 0x20) + 0x238) = &LAB_004f1800;
  iVar2 = FUN_00746d70(0x25c,s_C__dev_black_DialogBoxOptions_cp_00b16860,0x2f9);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0040b4a0(0x7e,0x104,199,&DAT_008fd4c8,0x20,0,2);
  }
  *(int *)(in_ECX + 0x18) = iVar2;
  *(undefined1 **)(iVar2 + 0x238) = &LAB_004f17e0;
  iVar2 = FUN_00746d70(0x25c,s_C__dev_black_DialogBoxOptions_cp_00b16860,0x2fb);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = FUN_0040b4a0(0x7f,0x1fc,199,&DAT_008fd4c8,0x20,0,3);
  }
  *(int *)(in_ECX + 0x1c) = iVar2;
  *(undefined1 **)(iVar2 + 0x238) = &LAB_004f1800;
  iVar2 = FUN_00746d70(0x25c,s_C__dev_black_DialogBoxOptions_cp_00b16860,0x2fe);
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
  *(int *)(in_ECX + 0x24) = iVar2;
  *(undefined1 **)(iVar2 + 0x238) = &LAB_0053dff0;
  uVar3 = FUN_00405ed0();
  *(undefined4 *)(*(int *)(in_ECX + 0x24) + 0x20) = uVar3;
  FUN_00513120(5);
  return;
}



// ?InitControls@DialogBoxImmersion@@UAEXXZ @ 0x004f1820

void _InitControls_DialogBoxImmersion__UAEXXZ(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  uVar1 = DAT_00c6d2f8;
  *(undefined4 *)(in_ECX + 0x2c) = DAT_00c6d2f8;
  FUN_004f14e0(uVar1);
  return;
}



