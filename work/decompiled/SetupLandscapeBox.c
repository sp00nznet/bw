// Decompiled functions for class: SetupLandscapeBox
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Init@SetupLandscapeBox@@UAEXIIP6AXHPAVSetupBox@@PAVSetupControl@@HH@Z@Z @ 0x005198c0

void _Init_SetupLandscapeBox__UAEXIIP6AXHPAVSetupBox__PAVSetupControl__HH_Z_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int in_ECX;
  
  _Init__13DialogBoxBaseFUlUlPFiP8SetupBoxP12SetupControlii_v(param_1,param_2,param_3);
  DAT_00bf29b0 = in_ECX;
  iVar1 = FUN_00746d70(0x468,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x42);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0040a590(0x3e6,0x96,0x20d,500,0x1e,&DAT_008fd4c8,0);
  }
  *(undefined4 *)(in_ECX + 0x44c) = uVar2;
  uVar2 = FUN_00405ee0();
  *(undefined4 *)(*(int *)(in_ECX + 0x44c) + 0x20) = uVar2;
  iVar1 = FUN_00746d70(0x25c,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x47);
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
  *(undefined4 *)(in_ECX + 0x450) = uVar2;
  iVar1 = FUN_00746d70(0x25c,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x48);
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
  *(undefined4 *)(in_ECX + 0x454) = uVar2;
  iVar1 = FUN_00746d70(0x468,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x4f);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0040a590(2,100,0x1b8,100,0x1e,&DAT_00b6e5f0,1);
  }
  *(undefined4 *)(in_ECX + 0x448) = uVar2;
  puVar3 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x50);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0x115e < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xd068;
    }
    FUN_00407730(999,100,0x19a,0x6e,0x28,*(undefined4 *)(iVar1 + 8));
    *puVar3 = &PTR_LAB_007ed4e8;
    puVar3[0x8f] = 0;
    *(undefined1 *)((int)puVar3 + 0x22a) = 0;
    puVar3[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x458) = puVar3;
  puVar3 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x51);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    FUN_00407730(999,100,0x50,0xd2,0x28,&DAT_00b6e5f0);
    *puVar3 = &PTR_LAB_007ed4e8;
    puVar3[0x8f] = 0;
    *(undefined1 *)((int)puVar3 + 0x22a) = 0;
    puVar3[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x45c) = puVar3;
  iVar1 = DAT_00c38db8;
  if (0x10e7 < DAT_00c38dbc) {
    iVar1 = DAT_00c38db8 + 0xcad4;
  }
  FUN_007343ef(puVar3 + 9,*(undefined4 *)(iVar1 + 8),*(undefined4 *)(in_ECX + 0x42c));
  iVar1 = FUN_00746d70(0x250,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x55);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00407fc0(3,100,100,100,0x14,0,&DAT_00b6e5f0);
  }
  *(undefined4 *)(in_ECX + 0x474) = uVar2;
  iVar1 = FUN_00746d70(0x260,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x57);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0x10e5 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xcabc;
    }
    iVar1 = FUN_0040ef70(4,100,0x82,0,0,*(undefined4 *)(iVar1 + 8),0x14);
  }
  *(int *)(in_ECX + 0x484) = iVar1;
  *(undefined4 *)(iVar1 + 0x244) = 0;
  iVar1 = FUN_00746d70(0x260,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x59);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0x10e6 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xcac8;
    }
    iVar1 = FUN_0040ef70(5,400,0x82,0,0,*(undefined4 *)(iVar1 + 8),0x14);
  }
  *(int *)(in_ECX + 0x488) = iVar1;
  *(undefined4 *)(iVar1 + 0x244) = 0;
  iVar1 = FUN_00746d70(0x260,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x5b);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0x10e8 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xcae0;
    }
    iVar1 = FUN_0040ef70(6,100,0xa0,0,0,*(undefined4 *)(iVar1 + 8),0x14);
  }
  *(int *)(in_ECX + 0x48c) = iVar1;
  *(undefined4 *)(iVar1 + 0x244) = 0;
  iVar1 = FUN_00746d70(0x260,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x5d);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0x10e9 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xcaec;
    }
    iVar1 = FUN_0040ef70(7,400,0xa0,0,0,*(undefined4 *)(iVar1 + 8),0x14);
  }
  *(int *)(in_ECX + 0x490) = iVar1;
  *(undefined4 *)(iVar1 + 0x244) = 0;
  iVar1 = FUN_00746d70(0x260,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x5f);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0x10ea < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xcaf8;
    }
    iVar1 = FUN_0040ef70(8,100,0xbe,0,0,*(undefined4 *)(iVar1 + 8),0x14);
  }
  *(int *)(in_ECX + 0x494) = iVar1;
  *(undefined4 *)(iVar1 + 0x244) = 0;
  iVar1 = FUN_00746d70(0x260,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x61);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0x10eb < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xcb04;
    }
    iVar1 = FUN_0040ef70(9,400,0xbe,0,0,*(undefined4 *)(iVar1 + 8),0x14);
  }
  *(int *)(in_ECX + 0x498) = iVar1;
  *(undefined4 *)(iVar1 + 0x244) = 0;
  iVar1 = FUN_00746d70(0x260,s_C__dev_black_FrontEndSetupGame_c_00b17990,99);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0x10ec < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xcb10;
    }
    iVar1 = FUN_0040ef70(10,100,0xdc,0,0,*(undefined4 *)(iVar1 + 8),0x14);
  }
  *(int *)(in_ECX + 0x49c) = iVar1;
  *(undefined4 *)(iVar1 + 0x244) = 0;
  iVar1 = FUN_00746d70(0x250,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x69);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00407fc0(0xc,100,0x122,100,0x14,0,&DAT_00b6e5f0);
  }
  *(undefined4 *)(in_ECX + 0x478) = uVar2;
  puVar3 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x6a);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    FUN_00407730(999,100,0x104,0xfa,0x1e,&DAT_00b6e5f0);
    *puVar3 = &PTR_LAB_007ed4e8;
    puVar3[0x8f] = 0;
    *(undefined1 *)((int)puVar3 + 0x22a) = 0;
    puVar3[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x460) = puVar3;
  iVar1 = DAT_00c38db8;
  if (0x115b < DAT_00c38dbc) {
    iVar1 = DAT_00c38db8 + 0xd044;
  }
  uVar2 = *(undefined4 *)(iVar1 + 8);
  uVar4 = FUN_0051a270(*(undefined4 *)(in_ECX + 0x434));
  FUN_007343ef(*(int *)(in_ECX + 0x460) + 0x24,uVar2,uVar4);
  iVar1 = FUN_00746d70(0x250,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x6d);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00407fc0(0xb,0x140,0x122,100,0x14,0,&DAT_00b6e5f0);
  }
  *(undefined4 *)(in_ECX + 0x47c) = uVar2;
  puVar3 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x6e);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    FUN_00407730(999,0x140,0x104,0xfa,0x1e,&DAT_00b6e5f0);
    *puVar3 = &PTR_LAB_007ed4e8;
    puVar3[0x8f] = 0;
    *(undefined1 *)((int)puVar3 + 0x22a) = 0;
    puVar3[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x464) = puVar3;
  iVar1 = DAT_00c38db8;
  if (0x115c < DAT_00c38dbc) {
    iVar1 = DAT_00c38db8 + 0xd050;
  }
  uVar2 = *(undefined4 *)(iVar1 + 8);
  uVar4 = FUN_0051a270(*(undefined4 *)(in_ECX + 0x430));
  FUN_007343ef(*(int *)(in_ECX + 0x464) + 0x24,uVar2,uVar4);
  iVar1 = FUN_00746d70(0x250,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x70);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_00407fc0(0xd,0x21c,0x122,100,0x14,0,&DAT_00b6e5f0);
  }
  *(undefined4 *)(in_ECX + 0x480) = uVar2;
  puVar3 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x71);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    FUN_00407730(999,0x21c,0x104,0xfa,0x1e,&DAT_00b6e5f0);
    *puVar3 = &PTR_LAB_007ed4e8;
    puVar3[0x8f] = 0;
    *(undefined1 *)((int)puVar3 + 0x22a) = 0;
    puVar3[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x468) = puVar3;
  iVar1 = DAT_00c38db8;
  if (0x115d < DAT_00c38dbc) {
    iVar1 = DAT_00c38db8 + 0xd05c;
  }
  uVar2 = *(undefined4 *)(iVar1 + 8);
  uVar4 = FUN_0051a270(*(undefined4 *)(in_ECX + 0x430));
  FUN_007343ef(*(int *)(in_ECX + 0x468) + 0x24,uVar2,uVar4);
  puVar3 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x75);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0x12be < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xe0e8;
    }
    FUN_00407730(999,100,0x136,0xfa,0x1e,*(undefined4 *)(iVar1 + 8));
    *puVar3 = &PTR_LAB_007ed4e8;
    puVar3[0x8f] = 0;
    *(undefined1 *)((int)puVar3 + 0x22a) = 0;
    puVar3[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x46c) = puVar3;
  iVar1 = FUN_00746d70(0x2b0,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x76);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004087c0(0xe,100,0x15e,200,0x3c);
  }
  *(undefined4 *)(in_ECX + 0x4a8) = uVar2;
  puVar3 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x79);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0x12bf < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xe0f4;
    }
    FUN_00407730(999,0x140,0x136,0xfa,0x1e,*(undefined4 *)(iVar1 + 8));
    *puVar3 = &PTR_LAB_007ed4e8;
    puVar3[0x8f] = 0;
    *(undefined1 *)((int)puVar3 + 0x22a) = 0;
    puVar3[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x470) = puVar3;
  iVar1 = FUN_00746d70(0x2b0,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x7a);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_004087c0(0xf,0x140,0x15e,200,0x3c);
  }
  *(undefined4 *)(in_ECX + 0x4ac) = uVar2;
  iVar1 = FUN_00746d70(0x244,s_C__dev_black_FrontEndSetupGame_c_00b17990,0x7c);
  if (iVar1 == 0) {
    *(undefined4 *)(in_ECX + 0x4a4) = 0;
    puRam00000238 = &LAB_0051a340;
    return;
  }
  iVar1 = DAT_00c38db8;
  if (0x12c0 < DAT_00c38dbc) {
    iVar1 = DAT_00c38db8 + 0xe100;
  }
  iVar1 = FUN_00407d30(0x11,0x140,0x1b8,200,0x1e,*(undefined4 *)(iVar1 + 8),0);
  *(int *)(in_ECX + 0x4a4) = iVar1;
  *(undefined1 **)(iVar1 + 0x238) = &LAB_0051a340;
  return;
}



// ?Destroy@SetupLandscapeBox@@UAEXXZ @ 0x0051a350

void _Destroy_SetupLandscapeBox__UAEXXZ(void)

{
  _Destroy__13DialogBoxBaseFv();
  DAT_00bf29b0 = 0;
  return;
}



// ?InitControls@SetupLandscapeBox@@UAEXXZ @ 0x0051a360

void _InitControls_SetupLandscapeBox__UAEXXZ(void)

{
  float fVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  uVar2 = FUN_00405ee0();
  *(undefined4 *)(*(int *)(DAT_00bf29b0 + 4) + 0xac) = uVar2;
  if (*(char *)(in_ECX + 0x10) != '\0') {
    puVar5 = *(undefined4 **)(in_ECX + 0x14);
    puVar6 = (undefined4 *)(in_ECX + 0x18);
    for (iVar4 = 0x10b; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
  }
  *(undefined1 *)(in_ECX + 0x10) = 0;
  *(uint *)(*(int *)(in_ECX + 0x484) + 0x248) = (uint)*(byte *)(in_ECX + 0x40d);
  *(uint *)(*(int *)(in_ECX + 0x488) + 0x248) = (uint)*(byte *)(in_ECX + 0x40e);
  *(uint *)(*(int *)(in_ECX + 0x49c) + 0x248) = (uint)*(byte *)(in_ECX + 0x429);
  *(uint *)(*(int *)(in_ECX + 0x48c) + 0x248) = (uint)*(byte *)(in_ECX + 0x425);
  *(uint *)(*(int *)(in_ECX + 0x498) + 0x248) = (uint)*(byte *)(in_ECX + 0x428);
  fVar1 = (float)*(int *)(in_ECX + 0x42c) * 0.14285715;
  if (fVar1 <= 0.0) {
    fVar1 = 0.0;
  }
  else if (1.0 <= fVar1) {
    fVar1 = 1.0;
  }
  *(float *)(*(int *)(in_ECX + 0x474) + 0x23c) = fVar1;
  *(uint *)(*(int *)(in_ECX + 0x490) + 0x248) = (uint)*(byte *)(in_ECX + 0x426);
  *(uint *)(*(int *)(in_ECX + 0x494) + 0x248) = (uint)*(byte *)(in_ECX + 0x427);
  fVar1 = *(float *)(in_ECX + 0x430);
  if (fVar1 <= 0.0) {
    fVar1 = 0.0;
  }
  else if (1.0 <= fVar1) {
    fVar1 = 1.0;
  }
  *(float *)(*(int *)(in_ECX + 0x47c) + 0x23c) = fVar1;
  fVar1 = *(float *)(in_ECX + 0x434);
  if (fVar1 <= 0.0) {
    fVar1 = 0.0;
  }
  else if (1.0 <= fVar1) {
    fVar1 = 1.0;
  }
  *(float *)(*(int *)(in_ECX + 0x478) + 0x23c) = fVar1;
  fVar1 = *(float *)(in_ECX + 0x438);
  if (fVar1 <= 0.0) {
    fVar1 = 0.0;
  }
  else if (1.0 <= fVar1) {
    fVar1 = 1.0;
  }
  *(float *)(*(int *)(in_ECX + 0x480) + 0x23c) = fVar1;
  iVar4 = *(int *)(in_ECX + 0x4a8);
  iVar3 = *(int *)(iVar4 + 0x250);
  while (0 < iVar3) {
    FUN_004090d0(iVar3 + -1);
    iVar3 = *(int *)(iVar4 + 0x250);
  }
  iVar3 = FUN_0045b520(0x12c1);
  iVar4 = *(int *)(in_ECX + 0x4a8);
  FUN_004091e0(*(undefined4 *)(iVar4 + 0x250),*(undefined4 *)(iVar3 + 8));
  FUN_0051a800(*(int *)(iVar4 + 0x250) + -1,0);
  iVar3 = FUN_0045b520(0x12c2);
  iVar4 = *(int *)(in_ECX + 0x4a8);
  FUN_004091e0(*(undefined4 *)(iVar4 + 0x250),*(undefined4 *)(iVar3 + 8));
  FUN_0051a800(*(int *)(iVar4 + 0x250) + -1,0);
  iVar3 = FUN_0045b520(0x12c3);
  iVar4 = *(int *)(in_ECX + 0x4a8);
  FUN_004091e0(*(undefined4 *)(iVar4 + 0x250),*(undefined4 *)(iVar3 + 8));
  FUN_0051a800(*(int *)(iVar4 + 0x250) + -1,0);
  iVar3 = FUN_0045b520(0x12c4);
  iVar4 = *(int *)(in_ECX + 0x4a8);
  FUN_004091e0(*(undefined4 *)(iVar4 + 0x250),*(undefined4 *)(iVar3 + 8));
  FUN_0051a800(*(int *)(iVar4 + 0x250) + -1,0);
  iVar3 = FUN_0045b520(0x12c5);
  iVar4 = *(int *)(in_ECX + 0x4a8);
  FUN_004091e0(*(undefined4 *)(iVar4 + 0x250),*(undefined4 *)(iVar3 + 8));
  FUN_0051a800(*(int *)(iVar4 + 0x250) + -1,0);
  iVar4 = *(int *)(in_ECX + 0x4ac);
  iVar3 = *(int *)(iVar4 + 0x250);
  while (0 < iVar3) {
    FUN_004090d0(iVar3 + -1);
    iVar3 = *(int *)(iVar4 + 0x250);
  }
  iVar3 = FUN_0045b520(0x12c6);
  iVar4 = *(int *)(in_ECX + 0x4ac);
  FUN_004091e0(*(undefined4 *)(iVar4 + 0x250),*(undefined4 *)(iVar3 + 8));
  FUN_0051a800(*(int *)(iVar4 + 0x250) + -1,0);
  iVar3 = FUN_0045b520(0x12c7);
  iVar4 = *(int *)(in_ECX + 0x4ac);
  FUN_004091e0(*(undefined4 *)(iVar4 + 0x250),*(undefined4 *)(iVar3 + 8));
  FUN_0051a800(*(int *)(iVar4 + 0x250) + -1,0);
  iVar3 = FUN_0045b520(0x12c8);
  iVar4 = *(int *)(in_ECX + 0x4ac);
  FUN_004091e0(*(undefined4 *)(iVar4 + 0x250),*(undefined4 *)(iVar3 + 8));
  FUN_0051a800(*(int *)(iVar4 + 0x250) + -1,0);
  iVar3 = FUN_0045b520(0x12c9);
  iVar4 = *(int *)(in_ECX + 0x4ac);
  FUN_004091e0(*(undefined4 *)(iVar4 + 0x250),*(undefined4 *)(iVar3 + 8));
  FUN_0051a800(*(int *)(iVar4 + 0x250) + -1,0);
  FUN_0051a790(*(undefined4 *)(in_ECX + 0x440));
  FUN_0051a790(*(undefined4 *)(in_ECX + 0x43c));
  return;
}



// ?InitSubDialogs@SetupLandscapeBox@@UAEXXZ @ 0x0051d7c0

void _InitSubDialogs_SetupLandscapeBox__UAEXXZ(void)

{
  undefined4 *puVar1;
  int in_ECX;
  int iVar2;
  undefined4 *puVar3;
  
  puVar1 = (undefined4 *)FUN_00746d70(0x45c,s_C__dev_black_FrontEndSetupMultip_00b17a5c,0xc4);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    FUN_004efee0();
    puVar3 = puVar1 + 0x37;
    for (iVar2 = 0xcb; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = 0;
      puVar3 = puVar3 + 1;
    }
    FUN_006b1130();
    *puVar1 = &vftable_SpellSetupBox;
  }
  *(undefined4 **)(in_ECX + 0x444) = puVar1;
  (**(code **)*puVar1)(0x2ec,0x224,&LAB_0051b400);
  *(int *)(*(int *)(in_ECX + 0x444) + 0x10) = in_ECX + 0x18;
  return;
}



