// Decompiled functions for class: CDBox
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Init@CDBox@@UAEXIIP6AXHPAVSetupBox@@PAVSetupControl@@HH@Z@Z @ 0x005178e0

void _Init_CDBox__UAEXIIP6AXHPAVSetupBox__PAVSetupControl__HH_Z_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  _Init__13DialogBoxBaseFUlUlPFiP8SetupBoxP12SetupControlii_v(param_1,param_2,param_3);
  DAT_00bf1ecc = in_ECX;
  uVar1 = FUN_00405ed0();
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0xac) = uVar1;
  iVar2 = FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0xcfd);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_00407d30(1,0x15e,0x104,100,0x1e,&DAT_008fd4c8,0);
  }
  *(undefined4 *)(in_ECX + 0x20) = uVar1;
  uVar1 = FUN_00405ed0();
  *(undefined4 *)(*(int *)(in_ECX + 0x20) + 0x20) = uVar1;
  iVar2 = FUN_00746d70(0x25c,s_C__dev_black_frontend_cpp_00b17740,0xcff);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_0040b4a0(2,0x136,0x103,&DAT_008fd4c8,0x20,0,2);
  }
  *(undefined4 *)(in_ECX + 0x10) = uVar1;
  iVar2 = FUN_00746d70(0x25c,s_C__dev_black_frontend_cpp_00b17740,0xd00);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_0040b4a0(3,0x1ca,0x103,&DAT_008fd4c8,0x20,0,3);
  }
  *(undefined4 *)(in_ECX + 0x14) = uVar1;
  iVar2 = FUN_00746d70(0x25c,s_C__dev_black_frontend_cpp_00b17740,0xd02);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_0040b4a0(4,0x168,0x13f,&DAT_008fd4c8,0x20,0,3);
  }
  *(undefined4 *)(in_ECX + 0x18) = uVar1;
  iVar2 = FUN_00746d70(0x25c,s_C__dev_black_frontend_cpp_00b17740,0xd03);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_0040b4a0(5,0x198,0x13f,&DAT_008fd4c8,0x20,0,0);
  }
  *(undefined4 *)(in_ECX + 0x1c) = uVar1;
  puVar3 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0xd05);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0xde7 < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa6d4;
    }
    FUN_00407730(999,200,200,400,0x3c,*(undefined4 *)(iVar2 + 8));
    *puVar3 = &PTR_LAB_007ed4e8;
    puVar3[0x8f] = 4;
    *(undefined1 *)((int)puVar3 + 0x22a) = 0;
    puVar3[0x90] = 0;
  }
  uVar1 = FUN_00405ed0();
  puVar3[8] = uVar1;
  iVar2 = FUN_00746d70(0x25c,s_C__dev_black_frontend_cpp_00b17740,0xd07);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0xd7a < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa1b8;
    }
    uVar1 = FUN_0040b4a0(0xb,0xe6,0x186,*(undefined4 *)(iVar2 + 8),0x20,0,2);
  }
  *(undefined4 *)(in_ECX + 0x24) = uVar1;
  iVar2 = FUN_00746d70(0x260,s_C__dev_black_frontend_cpp_00b17740,0xd09);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0xde8 < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa6e0;
    }
    iVar2 = FUN_0040ef70(6,0x222,0x189,0,0,*(undefined4 *)(iVar2 + 8),0x18);
  }
  *(int *)(in_ECX + 0x28) = iVar2;
  *(undefined4 *)(iVar2 + 0x244) = 1;
  *(undefined4 *)(in_ECX + 0x30) = 0;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
  return;
}



// ?Destroy@CDBox@@UAEXXZ @ 0x00517ba0

void _Destroy_CDBox__UAEXXZ(void)

{
  _Destroy__13DialogBoxBaseFv();
  DAT_00bf1ecc = 0;
  return;
}



// ?InitControls@CDBox@@UAEXXZ @ 0x00517bb0

void _InitControls_CDBox__UAEXXZ(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  
  uVar1 = FUN_00422980();
  uVar1 = FUN_005e6460(uVar1);
  *(undefined4 *)(in_ECX + 0x2c) = uVar1;
  uVar1 = FUN_00422980();
  iVar2 = FUN_005e6520(uVar1);
  *(int *)(in_ECX + 0x30) = iVar2;
  if (iVar2 < *(int *)(in_ECX + 0x2c)) {
    *(int *)(in_ECX + 0x2c) = iVar2;
  }
  UNICODE_sprintf((ushort *)(*(int *)(in_ECX + 0x20) + 0x24),(ushort *)u__d____d_00b178f8,
                  *(undefined4 *)(in_ECX + 0x2c),iVar2);
  *(uint *)(*(int *)(in_ECX + 0x28) + 0x248) = (uint)DAT_00c61ea4;
  return;
}



