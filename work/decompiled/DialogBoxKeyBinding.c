// Decompiled functions for class: DialogBoxKeyBinding
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Init@DialogBoxKeyBinding@@UAEXIIP6AXHPAVSetupBox@@PAVSetupControl@@HH@Z@Z @ 0x004ef580

void _Init_DialogBoxKeyBinding__UAEXIIP6AXHPAVSetupBox__PAVSetupControl__HH_Z_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int in_ECX;
  
  _Init__13DialogBoxBaseFUlUlPFiP8SetupBoxP12SetupControlii_v(param_1,param_2,param_3);
  puVar1 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_DialogBoxKeyBinding_00b1674c,0x40);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0xd7b < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa1c4;
    }
    FUN_00407730(999,100,0x3c,600,100,*(undefined4 *)(iVar2 + 8));
    *puVar1 = &PTR_LAB_007ed4e8;
    puVar1[0x8f] = 4;
    *(undefined1 *)((int)puVar1 + 0x22a) = 0;
    puVar1[0x90] = 0;
  }
  uVar3 = FUN_00405ef0();
  puVar1[8] = uVar3;
  iVar2 = FUN_00746d70(0x2b0,s_C__dev_black_DialogBoxKeyBinding_00b1674c,0x41);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = FUN_004087c0(300,100,0x78,600,0x140);
  }
  *(undefined4 *)(in_ECX + 0x18) = uVar3;
  iVar2 = FUN_00405ef0();
  iVar4 = FUN_00405ed0();
  *(int *)(*(int *)(in_ECX + 0x18) + 0x20) = (iVar4 + iVar2) / 2;
  iVar2 = FUN_00746d70(0x244,s_C__dev_black_DialogBoxKeyBinding_00b1674c,0x43);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0xd7c < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa1d0;
    }
    uVar3 = FUN_00407d30(0x12d,0x104,0x212,0x118,0x28,*(undefined4 *)(iVar2 + 8),0);
  }
  *(undefined4 *)(in_ECX + 0x10) = uVar3;
  iVar2 = FUN_00746d70(0x25c,s_C__dev_black_DialogBoxKeyBinding_00b1674c,0x44);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0xd7a < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa1b8;
    }
    uVar3 = FUN_0040b4a0(0x12e,0x1e,0x212,*(undefined4 *)(iVar2 + 8),0x28,0,2);
  }
  *(undefined4 *)(in_ECX + 0x14) = uVar3;
  uVar3 = FUN_00405ed0();
  *(undefined4 *)(*(int *)(in_ECX + 0x14) + 0x20) = uVar3;
  *(undefined1 *)(*(int *)(in_ECX + 0x18) + 0x244) = 1;
  *(undefined1 *)(*(int *)(in_ECX + 0x18) + 0x284) = 1;
  DAT_00be75b0 = 0;
  uVar3 = FUN_00405ed0();
  *(undefined4 *)(*(int *)(in_ECX + 0x10) + 0x20) = uVar3;
  *(undefined1 *)(*(int *)(in_ECX + 0x18) + 0x23c) = 1;
  FUN_00513120(4);
  return;
}



