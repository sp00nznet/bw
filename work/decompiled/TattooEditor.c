// Decompiled functions for class: TattooEditor
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Init@TattooEditor@@UAEXIIP6AXHPAVSetupBox@@PAVSetupControl@@HH@Z@Z @ 0x005160b0

void _Init_TattooEditor__UAEXIIP6AXHPAVSetupBox__PAVSetupControl__HH_Z_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int in_ECX;
  int *piVar4;
  uint uVar5;
  
  _Init__13DialogBoxBaseFUlUlPFiP8SetupBoxP12SetupControlii_v(param_1,param_2,param_3);
  DAT_00bf1ec0 = in_ECX;
  iVar1 = FUN_00746d70(600,s_C__dev_black_frontend_cpp_00b17740,0xa65);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0040eb70(5,0x2c,0x23,0x34,0x207,0,DAT_00b6e540);
  }
  *(undefined4 *)(in_ECX + 0x60) = uVar2;
  iVar1 = FUN_00746d70(600,s_C__dev_black_frontend_cpp_00b17740,0xa66);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0040eb70(6,0x2c0,0x23,0x34,0x207,1,DAT_00b6e540);
  }
  *(undefined4 *)(in_ECX + 100) = uVar2;
  puVar3 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0xa69);
  if (puVar3 != (undefined4 *)0x0) {
    iVar1 = DAT_00c38db8;
    if (0xdc2 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xa518;
    }
    FUN_00407730(999,0x96,0x1e,500,100,*(undefined4 *)(iVar1 + 8));
    *puVar3 = &PTR_LAB_007ed4e8;
    puVar3[0x8f] = 4;
    *(undefined1 *)((int)puVar3 + 0x22a) = 0;
    puVar3[0x90] = 0;
  }
  iVar1 = FUN_00746d70(0x25c,s_C__dev_black_frontend_cpp_00b17740,0xa6b);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0xa24 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0x79b0;
    }
    uVar2 = FUN_0040b4a0(1,0x96,500,*(undefined4 *)(iVar1 + 8),0x28,0,2);
  }
  *(undefined4 *)(in_ECX + 0x14) = uVar2;
  iVar1 = FUN_00746d70(0x25c,s_C__dev_black_frontend_cpp_00b17740,0xa6c);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0xa23 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0x79a4;
    }
    uVar2 = FUN_0040b4a0(2,0x262,500,*(undefined4 *)(iVar1 + 8),0x28,1,3);
  }
  *(undefined4 *)(in_ECX + 0x18) = uVar2;
  uVar5 = 0;
  piVar4 = (int *)(in_ECX + 0x20);
  do {
    iVar1 = FUN_00746d70(0x294,s_C__dev_black_frontend_cpp_00b17740,0xa73);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = FUN_0040e6d0(uVar5 + 100,((7 < (int)uVar5) - 1 & 0xfffffdc0) + 0x290,
                           (uVar5 & 7) * 0x41 + 0x23,DAT_00bf1a48,uVar5,4,0,0x40,1);
    }
    *piVar4 = iVar1;
    uVar5 = uVar5 + 1;
    piVar4 = piVar4 + 1;
    *(undefined4 *)(iVar1 + 0x27c) = 0xffffffff;
  } while ((int)uVar5 < 0x10);
  iVar1 = FUN_00746d70(0x25c,s_C__dev_black_frontend_cpp_00b17740,0xa77);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0040b4a0(0xb,0x160,0x1c2,&DAT_008fd4c8,0x60,0,4);
  }
  *(undefined4 *)(in_ECX + 0x1c) = uVar2;
  FUN_0072c360(s_data_tattoocols_raw_00b178e4,in_ECX + 0xa8,0x3000,0);
  *(undefined4 *)(*(int *)(in_ECX + 0x60) + 0x250) = 0x3f000000;
  *(undefined4 *)(*(int *)(in_ECX + 100) + 0x250) = 0x3f000000;
  *(undefined4 *)(in_ECX + 0x320c) = 0;
  *(undefined1 *)(in_ECX + 0x3210) = 0;
  return;
}



// ?Destroy@TattooEditor@@UAEXXZ @ 0x00516380

void _Destroy_TattooEditor__UAEXXZ(void)

{
  _Destroy__13DialogBoxBaseFv();
  DAT_00bf1ec0 = 0;
  return;
}



// ?InitControls@TattooEditor@@UAEXXZ @ 0x00516f60

void _InitControls_TattooEditor__UAEXXZ(void)

{
  int iVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x3224) = 0;
  DAT_00bf1ec0 = in_ECX;
  *(undefined1 *)(*(int *)(in_ECX + 4) + 0x78) = 0;
  iVar1 = FUN_0067bcf0(20000);
  DAT_00bf1a38 = iVar1 + 20000;
  DAT_00bf1a34 = 0;
  *(undefined4 *)(in_ECX + 0x3218) = 0;
  *(undefined4 *)(in_ECX + 0x321c) = 0;
  *(undefined4 *)(in_ECX + 0x30a8) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x3214) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x3220) = 0x7ffffff;
  return;
}



