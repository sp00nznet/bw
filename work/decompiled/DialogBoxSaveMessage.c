// Decompiled functions for class: DialogBoxSaveMessage
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Init@DialogBoxSaveMessage@@UAEXIIP6AXHPAVSetupBox@@PAVSetupControl@@HH@Z@Z @ 0x004f22f0

void _Init_DialogBoxSaveMessage__UAEXIIP6AXHPAVSetupBox__PAVSetupControl__HH_Z_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  _Init__13DialogBoxBaseFUlUlPFiP8SetupBoxP12SetupControlii_v(param_1,param_2,param_3);
  puVar1 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_DialogBoxSaveMessag_00b1692c,0x21);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0x1419 < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xf12c;
    }
    FUN_00407730(0x7d3,0xaf,200,0x1c2,0x32,*(undefined4 *)(iVar2 + 8));
    *puVar1 = &PTR_LAB_007ed4e8;
    puVar1[0x8f] = 4;
    *(undefined1 *)((int)puVar1 + 0x22a) = 0;
    puVar1[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x1c) = puVar1;
  iVar2 = FUN_00746d70(0x244,s_C__dev_black_DialogBoxSaveMessag_00b1692c,0x22);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0xa24 < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0x79b0;
    }
    uVar3 = FUN_00407d30(2000,0xfa,0x15e,100,0x32,*(undefined4 *)(iVar2 + 8),0);
  }
  *(undefined4 *)(in_ECX + 0x10) = uVar3;
  iVar2 = FUN_00746d70(0x244,s_C__dev_black_DialogBoxSaveMessag_00b1692c,0x23);
  if (iVar2 == 0) {
    uVar3 = 0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0xa23 < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0x79a4;
    }
    uVar3 = FUN_00407d30(0x7d1,0x1c2,0x15e,100,0x32,*(undefined4 *)(iVar2 + 8),0);
  }
  *(undefined4 *)(in_ECX + 0x14) = uVar3;
  iVar2 = FUN_00746d70(0x468,s_C__dev_black_DialogBoxSaveMessag_00b1692c,0x27);
  if (iVar2 == 0) {
    *(undefined4 *)(in_ECX + 0x18) = 0;
    uRam00000240 = 0x20;
    return;
  }
  iVar2 = FUN_0040a590(0x7d2,0xaf,0x113,0x1c2,0x32,&DAT_008fd4c8,1);
  *(int *)(in_ECX + 0x18) = iVar2;
  *(undefined4 *)(iVar2 + 0x240) = 0x20;
  return;
}



