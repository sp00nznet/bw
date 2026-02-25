// Decompiled functions for class: SpellSetupBox
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Init@SpellSetupBox@@UAEXIIP6AXHPAVSetupBox@@PAVSetupControl@@HH@Z@Z @ 0x0051afb0

void _Init_SpellSetupBox__UAEXIIP6AXHPAVSetupBox__PAVSetupControl__HH_Z_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  _Init__13DialogBoxBaseFUlUlPFiP8SetupBoxP12SetupControlii_v(param_1,param_2,param_3);
  DAT_00bf29b4 = in_ECX;
  iVar1 = FUN_00746d70(0x468,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x145);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0040a590(0x3e6,0x96,0x20d,500,0x1e,&DAT_008fd4c8,0);
  }
  *(undefined4 *)(in_ECX + 0x440) = uVar2;
  uVar2 = FUN_00405ee0();
  *(undefined4 *)(*(int *)(in_ECX + 0x440) + 0x20) = uVar2;
  iVar1 = FUN_00746d70(0x25c,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x14a);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0xa24 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0x79b0;
    }
    uVar2 = FUN_0040b4a0(0,0x28,0x208,*(undefined4 *)(iVar1 + 8),0x28,0,2);
  }
  *(undefined4 *)(in_ECX + 0x444) = uVar2;
  iVar1 = FUN_00746d70(0x25c,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x14b);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0xa23 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0x79a4;
    }
    uVar2 = FUN_0040b4a0(1,0x2d0,0x208,*(undefined4 *)(iVar1 + 8),0x28,1,3);
  }
  *(undefined4 *)(in_ECX + 0x448) = uVar2;
  puVar3 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x150);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0x10ed < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xcb1c;
    }
    FUN_00407730(999,0x5a,100,200,0x1e,*(undefined4 *)(iVar1 + 8));
    *puVar3 = &PTR_LAB_007ed4e8;
    puVar3[0x8f] = 0;
    *(undefined1 *)((int)puVar3 + 0x22a) = 0;
    puVar3[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x454) = puVar3;
  puVar3 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x151);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0x10f9 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xcbac;
    }
    FUN_00407730(999,0x14a,100,200,0x1e,*(undefined4 *)(iVar1 + 8));
    *puVar3 = &PTR_LAB_007ed4e8;
    puVar3[0x8f] = 0;
    *(undefined1 *)((int)puVar3 + 0x22a) = 0;
    puVar3[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x458) = puVar3;
  iVar1 = FUN_00746d70(700,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x152);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00409790(3,0x5a,0x8c,0xe6,200,10);
  }
  *(undefined4 *)(in_ECX + 0x44c) = uVar2;
  iVar1 = FUN_00746d70(700,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x153);
  if (iVar1 == 0) {
    *(undefined4 *)(in_ECX + 0x450) = 0;
    return;
  }
  uVar2 = FUN_00409790(2,0x14a,0x8c,200,200,10);
  *(undefined4 *)(in_ECX + 0x450) = uVar2;
  return;
}



// ?Destroy@SpellSetupBox@@UAEXXZ @ 0x0051b270

void _Destroy_SpellSetupBox__UAEXXZ(void)

{
  _Destroy__13DialogBoxBaseFv();
  DAT_00bf29b4 = 0;
  return;
}



// ?InitControls@SpellSetupBox@@UAEXXZ @ 0x0051b280

void _InitControls_SpellSetupBox__UAEXXZ(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  
  uVar2 = FUN_00405ed0();
  *(undefined4 *)(*(int *)(DAT_00bf29b4 + 4) + 0xac) = uVar2;
  iVar4 = *(int *)(in_ECX + 0x44c);
  iVar3 = *(int *)(iVar4 + 0x250);
  while (0 < iVar3) {
    FUN_004090d0(iVar3 + -1);
    iVar3 = *(int *)(iVar4 + 0x250);
  }
  iVar4 = *(int *)(in_ECX + 0x450);
  iVar3 = *(int *)(iVar4 + 0x250);
  while (0 < iVar3) {
    FUN_004090d0(iVar3 + -1);
    iVar3 = *(int *)(iVar4 + 0x250);
  }
  puVar5 = *(undefined4 **)(in_ECX + 0x10);
  puVar6 = (undefined4 *)(in_ECX + 0x14);
  for (iVar4 = 0x10b; iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  iVar4 = 0xcb28;
  uVar7 = 0x10ee;
  do {
    iVar3 = DAT_00c38db8;
    if ((uVar7 < DAT_00c38dbc) && (uVar7 != 0)) {
      iVar3 = DAT_00c38db8 + iVar4;
    }
    iVar1 = *(int *)(in_ECX + 0x44c);
    FUN_004091e0(*(undefined4 *)(iVar1 + 0x250),*(undefined4 *)(iVar3 + 8));
    iVar3 = *(int *)(iVar1 + 0x250) + -1;
    if ((-1 < iVar3) && (iVar3 < *(int *)(iVar1 + 0x250))) {
      *(undefined4 *)(*(int *)(iVar1 + 0x268) + iVar3 * 4) = 0;
    }
    iVar4 = iVar4 + 0xc;
    *(undefined1 *)(*(int *)(*(int *)(in_ECX + 0x44c) + 0x2b0) + -0x10ee + uVar7) =
         *(undefined1 *)(in_ECX + -0xcd8 + uVar7);
    iVar3 = uVar7 - 0x10ed;
    uVar7 = uVar7 + 1;
  } while (iVar3 < 10);
  iVar4 = 0xcb28;
  uVar7 = 0x10ee;
  do {
    iVar3 = DAT_00c38db8;
    if ((uVar7 < DAT_00c38dbc) && (uVar7 != 0)) {
      iVar3 = DAT_00c38db8 + iVar4;
    }
    iVar1 = *(int *)(in_ECX + 0x450);
    FUN_004091e0(*(undefined4 *)(iVar1 + 0x250),*(undefined4 *)(iVar3 + 8));
    iVar3 = *(int *)(iVar1 + 0x250) + -1;
    if ((-1 < iVar3) && (iVar3 < *(int *)(iVar1 + 0x250))) {
      *(undefined4 *)(*(int *)(iVar1 + 0x268) + iVar3 * 4) = 0;
    }
    iVar4 = iVar4 + 0xc;
    *(undefined1 *)(*(int *)(*(int *)(in_ECX + 0x450) + 0x2b0) + -0x10ee + uVar7) =
         *(undefined1 *)(in_ECX + -0xce3 + uVar7);
    iVar3 = uVar7 - 0x10ed;
    uVar7 = uVar7 + 1;
  } while (iVar3 < 0xb);
  return;
}



