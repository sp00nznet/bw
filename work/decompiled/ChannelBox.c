// Decompiled functions for class: ChannelBox
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Init@ChannelBox@@UAEXIIP6AXHPAVSetupBox@@PAVSetupControl@@HH@Z@Z @ 0x005d3c60

void _Init_ChannelBox__UAEXIIP6AXHPAVSetupBox__PAVSetupControl__HH_Z_Z
               (undefined4 param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int in_ECX;
  int iVar5;
  uint uVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined2 *puVar9;
  undefined4 *local_c;
  
  _Init__13DialogBoxBaseFUlUlPFiP8SetupBoxP12SetupControlii_v(param_1,param_2,param_3);
  DAT_00c5ff1c = in_ECX;
  *(undefined4 *)(in_ECX + 0x9a0) = 0;
  *(undefined4 *)(in_ECX + 0x9a4) = 0;
  *(undefined4 *)(in_ECX + 0xa28) = 0;
  *(undefined4 *)(in_ECX + 0xa2c) = 0;
  puVar4 = (undefined4 *)(in_ECX + 0x9a8);
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  puVar4 = (undefined4 *)(in_ECX + 0x9e8);
  for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  *(undefined4 *)(in_ECX + 0x16c) = 0;
  *(undefined4 *)(in_ECX + 0x19c) = 0;
  local_c = (undefined4 *)(in_ECX + 0x20);
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 5;
  iVar5 = 0;
  do {
    iVar1 = FUN_00746d70(0x254,s_C__dev_black_MPFEAlexDialog_cpp_00b21010,0x20e);
    if (iVar1 == 0) {
      uVar8 = 0;
    }
    else {
      iVar1 = __ftol();
      uVar6 = (uint)(iVar5 == 3);
      uVar7 = (uint)(iVar5 == 0);
      uVar2 = (uint)(iVar5 == *(int *)(in_ECX + 0x10));
      puVar9 = &DAT_00b6e5f0;
      uVar8 = 0x28;
      iVar3 = __ftol(0x28,&DAT_00b6e5f0,uVar2,uVar7,uVar6);
      uVar8 = FUN_0040d730(iVar5 + 0x8fc,iVar1,0x104 - (param_2 >> 1),iVar3 - iVar1,uVar8,puVar9,
                           uVar2,uVar7,uVar6);
    }
    *local_c = uVar8;
    iVar5 = iVar5 + 1;
    local_c = local_c + 1;
  } while (iVar5 < 4);
  uVar8 = FUN_00405ed0();
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0xac) = uVar8;
  puVar4 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_MPFEAlexDialog_cpp_00b21010,0x212);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    FUN_00407730(1,0x28,0x3c,0x2d0,0x1c,&DAT_00b6e5f0);
    *puVar4 = &PTR_LAB_007ed4e8;
    puVar4[0x8f] = 1;
    *(undefined1 *)((int)puVar4 + 0x22a) = 0;
    puVar4[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x30) = puVar4;
  puVar4 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_MPFEAlexDialog_cpp_00b21010,0x213);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    FUN_00407730(1,0x8c,0x17c,0x208,0x1c,&DAT_00b6e5f0);
    *puVar4 = &PTR_LAB_007ed4e8;
    puVar4[0x8f] = 1;
    *(undefined1 *)((int)puVar4 + 0x22a) = 0;
    puVar4[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x34) = puVar4;
  iVar5 = FUN_00746d70(0x244,s_C__dev_black_MPFEAlexDialog_cpp_00b21010,0x215);
  if (iVar5 == 0) {
    uVar8 = 0;
  }
  else {
    iVar5 = DAT_00c38db8;
    if (0x19e2 < DAT_00c38dbc) {
      iVar5 = DAT_00c38db8 + 0x13698;
    }
    uVar8 = FUN_00407d30(999,0,0,0x28,0x19,*(undefined4 *)(iVar5 + 8),0);
  }
  *(undefined4 *)(in_ECX + 0x120) = uVar8;
  iVar5 = FUN_00746d70(0x244,s_C__dev_black_MPFEAlexDialog_cpp_00b21010,0x216);
  if (iVar5 == 0) {
    uVar8 = 0;
  }
  else {
    iVar5 = DAT_00c38db8;
    if (0x19e3 < DAT_00c38dbc) {
      iVar5 = DAT_00c38db8 + 0x136a4;
    }
    uVar8 = FUN_00407d30(999,0,0,0x28,0x19,*(undefined4 *)(iVar5 + 8),0);
  }
  *(undefined4 *)(in_ECX + 0x124) = uVar8;
  uVar8 = FUN_00405ee0();
  *(undefined4 *)(*(int *)(in_ECX + 0x124) + 0x20) = uVar8;
  *(undefined4 *)(*(int *)(in_ECX + 0x120) + 0x20) =
       *(undefined4 *)(*(int *)(in_ECX + 0x124) + 0x20);
  iVar5 = FUN_00405ee0();
  uVar8 = FUN_007343d2(*(int *)(in_ECX + 0x120) + 0x24);
  FUN_0078a120(*(int *)(in_ECX + 0x120) + 0x24,uVar8,(float)iVar5);
  uVar8 = __ftol();
  *(undefined4 *)(in_ECX + 300) = uVar8;
  iVar5 = FUN_00405ee0();
  uVar8 = FUN_007343d2(*(int *)(in_ECX + 0x124) + 0x24);
  FUN_0078a120(*(int *)(in_ECX + 0x124) + 0x24,uVar8,(float)iVar5);
  uVar8 = __ftol();
  *(undefined4 *)(in_ECX + 0x130) = uVar8;
  iVar5 = FUN_00746d70(0x244,s_C__dev_black_MPFEAlexDialog_cpp_00b21010,0x21c);
  if (iVar5 == 0) {
    uVar8 = 0;
  }
  else {
    uVar8 = FUN_00407d30(999,0,0,0x28,0x19,&DAT_008fd4c8,0);
  }
  *(undefined4 *)(in_ECX + 0x128) = uVar8;
  uVar8 = FUN_00405ee0();
  *(undefined4 *)(*(int *)(in_ECX + 0x128) + 0x20) = uVar8;
  *(undefined1 *)(*(int *)(in_ECX + 0x128) + 0x22b) = 1;
  (**(code **)(**(int **)(in_ECX + 0x120) + 8))(1);
  (**(code **)(**(int **)(in_ECX + 0x124) + 8))(1);
  (**(code **)(**(int **)(in_ECX + 0x128) + 8))(1);
  *(undefined1 *)(*(int *)(in_ECX + 0x124) + 0x22b) = 1;
  *(undefined1 *)(*(int *)(in_ECX + 0x120) + 0x22b) = 1;
  iVar5 = 0;
  do {
    FUN_005d2800(in_ECX,iVar5);
    iVar5 = iVar5 + 1;
  } while (iVar5 < 5);
  iVar5 = FUN_00746d70(0x25c,s_C__dev_black_MPFEAlexDialog_cpp_00b21010,0x22f);
  if (iVar5 == 0) {
    uVar8 = 0;
  }
  else {
    iVar5 = DAT_00c38db8;
    if (0xd59 < DAT_00c38dbc) {
      iVar5 = DAT_00c38db8 + 0xa02c;
    }
    uVar8 = FUN_0040b4a0(999,0x14,0x212,*(undefined4 *)(iVar5 + 8),0x28,0,2);
  }
  *(undefined4 *)(in_ECX + 0x114) = uVar8;
  iVar5 = FUN_00746d70(0x25c,s_C__dev_black_MPFEAlexDialog_cpp_00b21010,0x230);
  if (iVar5 == 0) {
    uVar8 = 0;
  }
  else {
    iVar5 = DAT_00c38db8;
    if (0x19e5 < DAT_00c38dbc) {
      iVar5 = DAT_00c38db8 + 0x136bc;
    }
    uVar8 = FUN_0040b4a0(999,0x2e4,0x212,*(undefined4 *)(iVar5 + 8),0x28,1,3);
  }
  *(undefined4 *)(in_ECX + 0x118) = uVar8;
  uVar8 = FUN_00405ef0();
  *(undefined4 *)(*(int *)(in_ECX + 0x114) + 0x20) = uVar8;
  uVar8 = FUN_00405ef0();
  *(undefined4 *)(*(int *)(in_ECX + 0x118) + 0x20) = uVar8;
  iVar5 = FUN_00746d70(0x25c,s_C__dev_black_MPFEAlexDialog_cpp_00b21010,0x234);
  if (iVar5 == 0) {
    uVar8 = 0;
  }
  else {
    iVar5 = DAT_00c38db8;
    if (0x1a82 < DAT_00c38dbc) {
      iVar5 = DAT_00c38db8 + 0x13e18;
    }
    uVar8 = FUN_0040b4a0(999,0x2e4,0x212,*(undefined4 *)(iVar5 + 8),0x28,1,3);
  }
  *(undefined4 *)(in_ECX + 0x11c) = uVar8;
  uVar8 = FUN_00405ef0();
  *(undefined4 *)(*(int *)(in_ECX + 0x11c) + 0x20) = uVar8;
  iVar5 = FUN_00746d70(0x468,s_C__dev_black_MPFEAlexDialog_cpp_00b21010,0x238);
  if (iVar5 == 0) {
    uVar8 = 0;
  }
  else {
    iVar5 = DAT_00c38db8;
    if (0x1aae < DAT_00c38dbc) {
      iVar5 = DAT_00c38db8 + 0x14028;
    }
    uVar8 = FUN_0040a590(999,0x8c,0x221,0x208,0x1e,*(undefined4 *)(iVar5 + 8),1);
  }
  *(undefined4 *)(in_ECX + 0x144) = uVar8;
  uVar8 = FUN_00405ee0();
  *(undefined4 *)(*(int *)(in_ECX + 0x144) + 0x20) = uVar8;
  iVar5 = FUN_00746d70(0x2b0,s_C__dev_black_MPFEAlexDialog_cpp_00b21010,0x23a);
  if (iVar5 == 0) {
    uVar8 = 0;
  }
  else {
    uVar8 = FUN_004087c0(999,0x8c,0x19a,0x208,0x78);
  }
  *(undefined4 *)(in_ECX + 0x148) = uVar8;
  uVar8 = FUN_00405ee0();
  *(undefined4 *)(*(int *)(in_ECX + 0x148) + 0x20) = uVar8;
  *(undefined1 *)(*(int *)(in_ECX + 0x148) + 0x291) = 0;
  puVar4 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_MPFEAlexDialog_cpp_00b21010,0x23e);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    iVar5 = DAT_00c38db8;
    if (0x1a6a < DAT_00c38dbc) {
      iVar5 = DAT_00c38db8 + 0x13cf8;
    }
    FUN_00407730(1,0x28,0x17c,0x2d0,0x1c,*(undefined4 *)(iVar5 + 8));
    *puVar4 = &PTR_LAB_007ed4e8;
    puVar4[0x8f] = 1;
    *(undefined1 *)((int)puVar4 + 0x22a) = 0;
    puVar4[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x14c) = puVar4;
  puVar4 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_MPFEAlexDialog_cpp_00b21010,0x241);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    FUN_00407730(1,100,0x17c,300,0x1c,&DAT_00b6e5f0);
    *puVar4 = &PTR_LAB_007ed4e8;
    puVar4[0x8f] = 1;
    *(undefined1 *)((int)puVar4 + 0x22a) = 0;
    puVar4[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x154) = puVar4;
  puVar4 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_MPFEAlexDialog_cpp_00b21010,0x242);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    FUN_00407730(1,400,0x17c,300,0x1c,&DAT_00b6e5f0);
    *puVar4 = &PTR_LAB_007ed4e8;
    puVar4[0x8f] = 1;
    *(undefined1 *)((int)puVar4 + 0x22a) = 0;
    puVar4[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x158) = puVar4;
  iVar5 = FUN_00746d70(0x2b0,s_C__dev_black_MPFEAlexDialog_cpp_00b21010,0x243);
  if (iVar5 == 0) {
    uVar8 = 0;
  }
  else {
    uVar8 = FUN_004087c0(999,0x8c,0x19a,0xfa,0x78);
  }
  *(undefined4 *)(in_ECX + 0x15c) = uVar8;
  iVar5 = FUN_00746d70(0x2b0,s_C__dev_black_MPFEAlexDialog_cpp_00b21010,0x244);
  if (iVar5 == 0) {
    uVar8 = 0;
  }
  else {
    uVar8 = FUN_004087c0(999,0x19a,0x19a,0xfa,0x78);
  }
  *(undefined4 *)(in_ECX + 0x160) = uVar8;
  iVar5 = FUN_00746d70(0x244,s_C__dev_black_MPFEAlexDialog_cpp_00b21010,0x245);
  if (iVar5 == 0) {
    uVar8 = 0;
  }
  else {
    iVar5 = DAT_00c38db8;
    if (0x1ab0 < DAT_00c38dbc) {
      iVar5 = DAT_00c38db8 + 0x14040;
    }
    uVar8 = FUN_00407d30(999,0xfa,0x21c,300,0x1e,*(undefined4 *)(iVar5 + 8),0);
  }
  *(undefined4 *)(in_ECX + 0x164) = uVar8;
  iVar5 = FUN_00746d70(0x244,s_C__dev_black_MPFEAlexDialog_cpp_00b21010,0x246);
  if (iVar5 == 0) {
    uVar8 = 0;
  }
  else {
    iVar5 = DAT_00c38db8;
    if (0x1a53 < DAT_00c38dbc) {
      iVar5 = DAT_00c38db8 + 0x13be4;
    }
    uVar8 = FUN_00407d30(999,0xfa,0x21c,300,0x1e,*(undefined4 *)(iVar5 + 8),0);
  }
  *(undefined4 *)(in_ECX + 0x168) = uVar8;
  uVar8 = FUN_00405ee0();
  *(undefined4 *)(*(int *)(in_ECX + 0x160) + 0x20) = uVar8;
  *(undefined1 *)(*(int *)(in_ECX + 0x160) + 0x291) = 0;
  puVar4 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_MPFEAlexDialog_cpp_00b21010,0x24b);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    FUN_00407730(1,0,0x17c,800,0x1c,&DAT_00b6e5f0);
    *puVar4 = &PTR_LAB_007ed4e8;
    puVar4[0x8f] = 1;
    *(undefined1 *)((int)puVar4 + 0x22a) = 0;
    puVar4[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x170) = puVar4;
  iVar5 = FUN_00746d70(0x2b0,s_C__dev_black_MPFEAlexDialog_cpp_00b21010,0x24c);
  if (iVar5 == 0) {
    uVar8 = 0;
  }
  else {
    uVar8 = FUN_004087c0(999,0x8c,0x19a,0x208,0x78);
  }
  *(undefined4 *)(in_ECX + 0x174) = uVar8;
  iVar5 = FUN_00746d70(0x244,s_C__dev_black_MPFEAlexDialog_cpp_00b21010,0x24d);
  if (iVar5 == 0) {
    uVar8 = 0;
  }
  else {
    iVar5 = DAT_00c38db8;
    if (0x1a70 < DAT_00c38dbc) {
      iVar5 = DAT_00c38db8 + 0x13d40;
    }
    uVar8 = FUN_00407d30(999,0x8c,0x21c,0xa0,0x1e,*(undefined4 *)(iVar5 + 8),0);
  }
  *(undefined4 *)(in_ECX + 0x178) = uVar8;
  iVar5 = FUN_00746d70(0x244,s_C__dev_black_MPFEAlexDialog_cpp_00b21010,0x24e);
  if (iVar5 == 0) {
    uVar8 = 0;
  }
  else {
    iVar5 = DAT_00c38db8;
    if (0x19e2 < DAT_00c38dbc) {
      iVar5 = DAT_00c38db8 + 0x13698;
    }
    uVar8 = FUN_00407d30(999,0x140,0x21c,0xa0,0x1e,*(undefined4 *)(iVar5 + 8),0);
  }
  *(undefined4 *)(in_ECX + 0x17c) = uVar8;
  iVar5 = FUN_00746d70(0x244,s_C__dev_black_MPFEAlexDialog_cpp_00b21010,0x24f);
  if (iVar5 == 0) {
    uVar8 = 0;
  }
  else {
    iVar5 = DAT_00c38db8;
    if (0x19e3 < DAT_00c38dbc) {
      iVar5 = DAT_00c38db8 + 0x136a4;
    }
    uVar8 = FUN_00407d30(999,500,0x21c,0xa0,0x1e,*(undefined4 *)(iVar5 + 8),0);
  }
  *(undefined4 *)(in_ECX + 0x180) = uVar8;
  uVar8 = FUN_00405ee0();
  *(undefined4 *)(*(int *)(in_ECX + 0x174) + 0x20) = uVar8;
  *(undefined1 *)(*(int *)(in_ECX + 0x174) + 0x291) = 0;
  puVar4 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_MPFEAlexDialog_cpp_00b21010,0x254);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    iVar5 = DAT_00c38db8;
    if (0x19e8 < DAT_00c38dbc) {
      iVar5 = DAT_00c38db8 + 0x136e0;
    }
    FUN_00407730(1,0x8c,0x17c,0xbe,0x1c,*(undefined4 *)(iVar5 + 8));
    *puVar4 = &PTR_LAB_007ed4e8;
    puVar4[0x8f] = 1;
    *(undefined1 *)((int)puVar4 + 0x22a) = 0;
    puVar4[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x184) = puVar4;
  puVar4 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_MPFEAlexDialog_cpp_00b21010,0x255);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    iVar5 = DAT_00c38db8;
    if (0x19e9 < DAT_00c38dbc) {
      iVar5 = DAT_00c38db8 + 0x136ec;
    }
    FUN_00407730(1,0,0x17c,800,0x1c,*(undefined4 *)(iVar5 + 8));
    *puVar4 = &PTR_LAB_007ed4e8;
    puVar4[0x8f] = 1;
    *(undefined1 *)((int)puVar4 + 0x22a) = 0;
    puVar4[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x188) = puVar4;
  puVar4 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_MPFEAlexDialog_cpp_00b21010,0x256);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    iVar5 = DAT_00c38db8;
    if (0x1a72 < DAT_00c38dbc) {
      iVar5 = DAT_00c38db8 + 0x13d58;
    }
    FUN_00407730(1,0x1d6,0x17c,0xbe,0x1c,*(undefined4 *)(iVar5 + 8));
    *puVar4 = &PTR_LAB_007ed4e8;
    puVar4[0x8f] = 1;
    *(undefined1 *)((int)puVar4 + 0x22a) = 0;
    puVar4[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x18c) = puVar4;
  iVar5 = FUN_00746d70(0x2b0,s_C__dev_black_MPFEAlexDialog_cpp_00b21010,599);
  if (iVar5 == 0) {
    uVar8 = 0;
  }
  else {
    uVar8 = FUN_004087c0(999,0x8c,0x19a,0xbe,0x78);
  }
  *(undefined4 *)(in_ECX + 400) = uVar8;
  iVar5 = FUN_00746d70(0x2b0,s_C__dev_black_MPFEAlexDialog_cpp_00b21010,600);
  if (iVar5 == 0) {
    uVar8 = 0;
  }
  else {
    uVar8 = FUN_004087c0(999,0x1d6,0x19a,0xbe,0x78);
  }
  *(undefined4 *)(in_ECX + 0x194) = uVar8;
  iVar5 = FUN_00746d70(0x244,s_C__dev_black_MPFEAlexDialog_cpp_00b21010,0x259);
  if (iVar5 == 0) {
    uVar8 = 0;
  }
  else {
    iVar5 = DAT_00c38db8;
    if (0x1ab1 < DAT_00c38dbc) {
      iVar5 = DAT_00c38db8 + 0x1404c;
    }
    uVar8 = FUN_00407d30(999,0xfa,0x21c,300,0x19,*(undefined4 *)(iVar5 + 8),0);
  }
  *(undefined4 *)(in_ECX + 0x198) = uVar8;
  uVar8 = FUN_00405ee0();
  *(undefined4 *)(*(int *)(in_ECX + 0x194) + 0x20) = uVar8;
  *(undefined1 *)(*(int *)(in_ECX + 0x194) + 0x291) = 0;
  return;
}



// ?Destroy@ChannelBox@@UAEXXZ @ 0x005d4990

void _Destroy_ChannelBox__UAEXXZ(void)

{
  _Destroy__13DialogBoxBaseFv();
  DAT_00c5ff1c = 0;
  return;
}



// ?InitControls@ChannelBox@@UAEXXZ @ 0x005d49a0

void _InitControls_ChannelBox__UAEXXZ(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  int iVar3;
  undefined4 *puVar4;
  undefined4 uStack_4;
  
  *(undefined4 *)(in_ECX + 0xa30) = 0;
  *(undefined4 *)(in_ECX + 0xa40) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  FUN_005d3620(0);
  while (*(int *)(in_ECX + 0xa38) != 0) {
    uVar2 = *(undefined4 *)(*(int *)(in_ECX + 0xa38) + 4);
    FUN_00542c40(uVar2,0);
    FUN_007290de(uVar2);
  }
  iVar3 = *(int *)(in_ECX + 0x194);
  iVar1 = *(int *)(iVar3 + 0x250);
  while (0 < iVar1) {
    FUN_004090d0(iVar1 + -1);
    iVar1 = *(int *)(iVar3 + 0x250);
  }
  iVar3 = *(int *)(in_ECX + 400);
  iVar1 = *(int *)(iVar3 + 0x250);
  while (0 < iVar1) {
    FUN_004090d0(iVar1 + -1);
    iVar1 = *(int *)(iVar3 + 0x250);
  }
  iVar3 = *(int *)(in_ECX + 0x160);
  iVar1 = *(int *)(iVar3 + 0x250);
  while (0 < iVar1) {
    FUN_004090d0(iVar1 + -1);
    iVar1 = *(int *)(iVar3 + 0x250);
  }
  iVar3 = *(int *)(in_ECX + 0x15c);
  iVar1 = *(int *)(iVar3 + 0x250);
  while (0 < iVar1) {
    FUN_004090d0(iVar1 + -1);
    iVar1 = *(int *)(iVar3 + 0x250);
  }
  iVar3 = *(int *)(in_ECX + 0x174);
  iVar1 = *(int *)(iVar3 + 0x250);
  while (0 < iVar1) {
    FUN_004090d0(iVar1 + -1);
    iVar1 = *(int *)(iVar3 + 0x250);
  }
  iVar3 = *(int *)(in_ECX + 0x148);
  iVar1 = *(int *)(iVar3 + 0x250);
  while (0 < iVar1) {
    FUN_004090d0(iVar1 + -1);
    iVar1 = *(int *)(iVar3 + 0x250);
  }
  *(undefined4 *)(in_ECX + 0x16c) = 0;
  *(undefined4 *)(in_ECX + 0x19c) = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0x14) = 5;
  uStack_4 = 0;
  uVar2 = FUN_0078d3c0(0,0x44,0xffffffff,&uStack_4);
  *(undefined4 *)(in_ECX + 0x9a0) = uVar2;
  uVar2 = FUN_00788de0(5,uVar2);
  *(undefined4 *)(in_ECX + 0x9a4) = uVar2;
  *(undefined4 *)(in_ECX + 0xa30) = 0;
  if (*(int *)(in_ECX + 0xa28) != 0) {
    FUN_0078d710();
  }
  *(undefined4 *)(in_ECX + 0xa28) = 0;
  if (*(int *)(in_ECX + 0xa2c) != 0) {
    *(undefined4 *)(*(int *)(in_ECX + 0xa2c) + 8) = 0;
  }
  *(undefined4 *)(in_ECX + 0xa2c) = 0;
  uVar2 = FUN_0078d3c0(0,0x44,0xffffffff,&uStack_4);
  *(undefined4 *)(in_ECX + 0xa28) = uVar2;
  uVar2 = FUN_00788de0(5,uVar2);
  *(undefined4 *)(in_ECX + 0xa2c) = uVar2;
  puVar4 = (undefined4 *)(in_ECX + 0x9a8);
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  puVar4 = (undefined4 *)(in_ECX + 0x9e8);
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
  }
  FUN_005d4b80();
  return;
}



