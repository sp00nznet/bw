// Decompiled functions for class: EndGameBox
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Init@EndGameBox@@UAEXIIP6AXHPAVSetupBox@@PAVSetupControl@@HH@Z@Z @ 0x0053dab0

void _Init_EndGameBox__UAEXIIP6AXHPAVSetupBox__PAVSetupControl__HH_Z_Z
               (undefined2 *param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int in_ECX;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  
  _Init__13DialogBoxBaseFUlUlPFiP8SetupBoxP12SetupControlii_v(param_1,param_2,param_3);
  DAT_00c273a8 = in_ECX;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  iVar7 = 0;
  do {
    if (iVar7 == 0) {
      iVar1 = DAT_00c38db8;
      if (0x1a0e < DAT_00c38dbc) {
        iVar1 = DAT_00c38db8 + 0x138a8;
      }
      param_1 = *(undefined2 **)(iVar1 + 8);
    }
    else if (iVar7 == 1) {
      iVar1 = DAT_00c38db8;
      if (0x19f8 < DAT_00c38dbc) {
        iVar1 = DAT_00c38db8 + 0x137a0;
      }
      param_1 = *(undefined2 **)(iVar1 + 8);
    }
    else {
      param_1 = &DAT_00b6e5f0;
    }
    iVar1 = FUN_00746d70(0x254,s_C__dev_black_GameStatsFrontEnd_c_00b1c1e8,0x217);
    if (iVar1 == 0) {
      uVar8 = 0;
    }
    else {
      iVar1 = __ftol();
      uVar5 = (uint)(iVar7 == 5);
      uVar6 = (uint)(iVar7 == 0);
      uVar2 = (uint)(iVar7 == *(int *)(in_ECX + 0x10));
      uVar8 = 0x28;
      iVar3 = __ftol(0x28,param_1,uVar2,uVar6,uVar5);
      uVar8 = FUN_0040d730(iVar7 + 0x8fc,iVar1,0x104 - (param_2 >> 1),iVar3 - iVar1,uVar8,param_1,
                           uVar2,uVar6,uVar5);
    }
    *(undefined4 *)(in_ECX + 0x18 + iVar7 * 4) = uVar8;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 6);
  uVar8 = FUN_00405ef0();
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0xac) = uVar8;
  puVar4 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_GameStatsFrontEnd_c_00b1c1e8,0x21b);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    FUN_00407730(1,0x28,0x50,0x2d0,0xe4,&DAT_00b6e5f0);
    *puVar4 = &PTR_LAB_007ed4e8;
    puVar4[0x8f] = 4;
    *(undefined1 *)((int)puVar4 + 0x22a) = 0;
    puVar4[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x34) = puVar4;
  puVar4 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_GameStatsFrontEnd_c_00b1c1e8,0x21c);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    FUN_00407730(1,0x28,200,0x2d0,0x32,&DAT_00b6e5f0);
    *puVar4 = &PTR_LAB_007ed4e8;
    puVar4[0x8f] = 4;
    *(undefined1 *)((int)puVar4 + 0x22a) = 0;
    puVar4[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x38) = puVar4;
  puVar4 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_GameStatsFrontEnd_c_00b1c1e8,0x21d);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    iVar7 = DAT_00c38db8;
    if (0xdec < DAT_00c38dbc) {
      iVar7 = DAT_00c38db8 + 0xa710;
    }
    FUN_00407730(1,300,0x212,200,0x28,*(undefined4 *)(iVar7 + 8));
    *puVar4 = &PTR_LAB_007ed4e8;
    puVar4[0x8f] = 1;
    *(undefined1 *)((int)puVar4 + 0x22a) = 0;
    puVar4[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x3c) = puVar4;
  uVar8 = FUN_00405ee0();
  *(undefined4 *)(*(int *)(in_ECX + 0x3c) + 0x20) = uVar8;
  puVar4 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_GameStatsFrontEnd_c_00b1c1e8,0x21f);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    FUN_00407730(1,0x28,0xfa,0x2d0,0x31,&DAT_00b6e5f0);
    *puVar4 = &PTR_LAB_007ed4e8;
    puVar4[0x8f] = 4;
    *(undefined1 *)((int)puVar4 + 0x22a) = 0;
    puVar4[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x30) = puVar4;
  puVar4[7] = 1;
  *(undefined4 *)(*(int *)(in_ECX + 0x34) + 0x1c) = 1;
  *(undefined4 *)(*(int *)(in_ECX + 0x38) + 0x1c) = 1;
  puVar4 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_GameStatsFrontEnd_c_00b1c1e8,0x225);
  if (puVar4 == (undefined4 *)0x0) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    iVar7 = DAT_00c38db8;
    if (0x1a8d < DAT_00c38dbc) {
      iVar7 = DAT_00c38db8 + 0x13e9c;
    }
    FUN_00407730(1,0x28,0x14a,0x2d0,0x28,*(undefined4 *)(iVar7 + 8));
    *puVar4 = &PTR_LAB_007ed4e8;
    puVar4[0x8f] = 4;
    *(undefined1 *)((int)puVar4 + 0x22a) = 0;
    puVar4[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x40) = puVar4;
  iVar7 = FUN_00746d70(0x284,s_C__dev_black_GameStatsFrontEnd_c_00b1c1e8,0x228);
  if (iVar7 == 0) {
    uVar8 = 0;
  }
  else {
    uVar8 = FUN_0040d090(0,0x118,0x177,0xf0,0xaf,&DAT_00b6e5f0);
  }
  *(undefined4 *)(in_ECX + 0x44) = uVar8;
  *(undefined4 *)(*(int *)(in_ECX + 0x30) + 0x20) = 0x31;
  *(undefined4 *)(*(int *)(in_ECX + 0x34) + 0x20) = 0x31;
  iVar7 = FUN_00746d70(0x25c,s_C__dev_black_GameStatsFrontEnd_c_00b1c1e8,0x230);
  if (iVar7 == 0) {
    uVar8 = 0;
  }
  else {
    iVar7 = DAT_00c38db8;
    if (0x1a38 < DAT_00c38dbc) {
      iVar7 = DAT_00c38db8 + 0x13aa0;
    }
    uVar8 = FUN_0040b4a0(999,0x14,0x212,*(undefined4 *)(iVar7 + 8),0x28,0,2);
  }
  *(undefined4 *)(in_ECX + 0x48) = uVar8;
  iVar7 = FUN_00746d70(0x25c,s_C__dev_black_GameStatsFrontEnd_c_00b1c1e8,0x231);
  if (iVar7 == 0) {
    uVar8 = 0;
  }
  else {
    iVar7 = DAT_00c38db8;
    if (0x1ab5 < DAT_00c38dbc) {
      iVar7 = DAT_00c38db8 + 0x1407c;
    }
    uVar8 = FUN_0040b4a0(999,0x14,0x212,*(undefined4 *)(iVar7 + 8),0x28,0,2);
  }
  *(undefined4 *)(in_ECX + 0x50) = uVar8;
  iVar7 = FUN_00746d70(0x25c,s_C__dev_black_GameStatsFrontEnd_c_00b1c1e8,0x232);
  if (iVar7 == 0) {
    uVar8 = 0;
  }
  else {
    iVar7 = DAT_00c38db8;
    if (0xde4 < DAT_00c38dbc) {
      iVar7 = DAT_00c38db8 + 0xa6b0;
    }
    uVar8 = FUN_0040b4a0(999,0x2e4,0x212,*(undefined4 *)(iVar7 + 8),0x28,1,3);
  }
  *(undefined4 *)(in_ECX + 0x4c) = uVar8;
  *(undefined1 **)(*(int *)(in_ECX + 0x48) + 0x238) = &LAB_0053dff0;
  *(undefined1 **)(*(int *)(in_ECX + 0x50) + 0x238) = &LAB_0053dff0;
  *(undefined1 **)(*(int *)(in_ECX + 0x4c) + 0x238) = &LAB_0053dfc0;
  return;
}



// ?Destroy@EndGameBox@@UAEXXZ @ 0x0053e000

void _Destroy_EndGameBox__UAEXXZ(void)

{
  _Destroy__13DialogBoxBaseFv();
  DAT_00c273a8 = 0;
  return;
}



// ?InitControls@EndGameBox@@UAEXXZ @ 0x0053e010

void _InitControls_EndGameBox__UAEXXZ(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  ushort *puVar4;
  int in_ECX;
  LHSPrintfW *this;
  int iVar5;
  undefined4 uVar6;
  double dVar7;
  undefined4 uStack_828;
  undefined4 uStack_824;
  int iStack_820;
  undefined4 uStack_81c;
  
  uStack_81c = 0;
  *(undefined4 *)(in_ECX + 0x10) = 0;
  iStack_820 = 0x53e029;
  FUN_0053da80();
  uVar1 = 0x1aba;
  switch(*(undefined4 *)(in_ECX + 0x60)) {
  case 0:
    if ((*(char *)(in_ECX + 0x58) == '\0') && (*(char *)(in_ECX + 0x59) != '\0')) {
      uVar1 = 0x1a68;
    }
    else {
      uVar1 = 0xdc7;
    }
    break;
  case 1:
  case 3:
    uVar1 = 0x1aba;
    break;
  case 2:
    uVar1 = (-(uint)(*(byte *)(DAT_00c22ca4 + 0xcd +
                              (uint)*(byte *)(DAT_00c22ca4 + 0x201b15) * 0x278) < 4) & 0xfffff681) +
            0x1a0e;
  }
  iVar2 = DAT_00c38db8;
  if ((uVar1 < DAT_00c38dbc) && (uVar1 != 0)) {
    iVar2 = DAT_00c38db8 + uVar1 * 0xc;
  }
  uStack_81c = *(undefined4 *)(iVar2 + 8);
  iStack_820 = *(int *)(in_ECX + 0x34) + 0x24;
  uStack_824 = 0x53e0b9;
  FUN_00733ff8();
  iVar2 = DAT_00c38db8;
  if (*(char *)(in_ECX + 0x58) == '\0') {
    if (0x1ab8 < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0x140a0;
    }
  }
  else if (0x1abd < DAT_00c38dbc) {
    iVar2 = DAT_00c38db8 + 0x140dc;
  }
  uStack_81c = *(undefined4 *)(iVar2 + 8);
  iStack_820 = *(int *)(in_ECX + 0x38) + 0x24;
  uStack_824 = 0x53e10e;
  FUN_00733ff8();
  if (*(int *)(in_ECX + 0x60) == 1) {
    uStack_81c = 0x53e128;
    FUN_00527d60();
    uStack_81c = 0;
    iStack_820 = 0x53e132;
    FUN_006b45b0();
  }
  uStack_81c = 1;
  iStack_820 = 0x53e13b;
  (**(code **)(**(int **)(in_ECX + 0x4c) + 8))();
  iStack_820 = 1;
  uStack_824 = 0x53e144;
  (**(code **)(**(int **)(in_ECX + 0x50) + 8))();
  uStack_824 = 1;
  uStack_828 = 0x53e14d;
  (**(code **)(**(int **)(in_ECX + 0x48) + 8))();
  uStack_828 = 1;
  (**(code **)(**(int **)(in_ECX + 0x30) + 8))();
  (**(code **)(**(int **)(in_ECX + 0x38) + 8))(1);
  (**(code **)(**(int **)(in_ECX + 0x40) + 8))(1);
  (**(code **)(**(int **)(in_ECX + 0x44) + 8))(1);
  (**(code **)(**(int **)(in_ECX + 0x3c) + 8))(0);
  FUN_0053e2f0();
  if ((*(int *)(DAT_00c22ca4 + 0x1a64) != 1) || (*(int *)(in_ECX + 0x60) == 0)) {
    FUN_0053e290();
  }
  if ((*(char *)(in_ECX + 0x5a) == '\0') && (*(int *)(in_ECX + 0x60) != 0)) {
    LHSession::StopSession(*(LHSession **)(DAT_00c22ca4 + 0x201c3c));
  }
  iVar2 = DAT_00c38db8;
  if (0x1a26 < DAT_00c38dbc) {
    iVar2 = DAT_00c38db8 + 0x139c8;
  }
  uVar6 = *(undefined4 *)(iVar2 + 8);
  iVar2 = FUN_00527ec0();
  this = (LHSPrintfW *)(*(int *)(iVar2 + 500) + *(int *)(in_ECX + 0x54) * 0x453);
  dVar7 = (double)*(float *)(*(int *)(in_ECX + 100) + 0x10 + (int)this * 4);
  uVar3 = LHSPrintfW::LHSPrintfW(this,(ushort *)&uStack_824);
  FUN_00733ff8(*(int *)(in_ECX + 0x30) + 0x24,uVar3,uVar6,dVar7);
  (**(code **)(**(int **)(in_ECX + 0x44) + 0x34))();
  puVar4 = *(ushort **)(in_ECX + 100);
  iVar2 = 0;
  if (*puVar4 != 0) {
    iVar5 = 0;
    do {
      uStack_824 = *(undefined4 *)(iVar5 + 0x10 + (int)puVar4);
      uStack_828 = *(undefined4 *)(iVar5 + 4 + (int)puVar4);
      (**(code **)(**(int **)(in_ECX + 0x44) + 0x3c))(&uStack_828);
      puVar4 = *(ushort **)(in_ECX + 100);
      iVar2 = iVar2 + 1;
      iVar5 = iVar5 + 0x114c;
    } while (iVar2 < (int)(uint)*puVar4);
  }
  (**(code **)(**(int **)(in_ECX + 0x44) + 0x38))(0);
  return;
}



