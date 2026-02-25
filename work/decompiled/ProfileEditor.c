// Decompiled functions for class: ProfileEditor
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?CanESCOut@ProfileEditor@@UAE_NXZ @ 0x0050fda0

undefined4 _CanESCOut_ProfileEditor__UAE_NXZ(void)

{
  if ((DAT_00bf1e84 != 0) && (DAT_00bf1e58 != '\0')) {
    return 0;
  }
  return 1;
}



// ?Init@ProfileEditor@@UAEXIIP6AXHPAVSetupBox@@PAVSetupControl@@HH@Z@Z @ 0x00511910

void _Init_ProfileEditor__UAEXIIP6AXHPAVSetupBox__PAVSetupControl__HH_Z_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  _Init__13DialogBoxBaseFUlUlPFiP8SetupBoxP12SetupControlii_v(param_1,param_2,param_3);
  DAT_00bf1e84 = in_ECX;
  iVar1 = FUN_00746d70(0x294,s_C__dev_black_frontend_cpp_00b17740,0x367);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0040e6d0(0x7b,0x170,0x127,DAT_00bf1a48,0,4,1,0x40,0);
  }
  *(undefined4 *)(in_ECX + 0x28) = uVar2;
  puVar3 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0x369);
  if (puVar3 != (undefined4 *)0x0) {
    iVar1 = DAT_00c38db8;
    if (0xd54 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0x9ff0;
    }
    FUN_00407730(999,100,0x3c,600,0x3c,*(undefined4 *)(iVar1 + 8));
    *puVar3 = &PTR_LAB_007ed4e8;
    puVar3[0x8f] = 4;
    *(undefined1 *)((int)puVar3 + 0x22a) = 0;
    puVar3[0x90] = 0;
  }
  iVar1 = FUN_00746d70(0x2b0,s_C__dev_black_frontend_cpp_00b17740,0x36a);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = FUN_004087c0(0,200,0x78,400,0xa0);
  }
  *(int *)(in_ECX + 0x10) = iVar1;
  *(undefined1 *)(iVar1 + 0x244) = 1;
  uVar2 = FUN_00405ed0();
  *(undefined4 *)(*(int *)(in_ECX + 0x10) + 0x20) = uVar2;
  iVar1 = FUN_00746d70(0x25c,s_C__dev_black_frontend_cpp_00b17740,0x36d);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0xd7a < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xa1b8;
    }
    uVar2 = FUN_0040b4a0(1,0x1e,0x212,*(undefined4 *)(iVar1 + 8),0x28,0,2);
  }
  *(undefined4 *)(in_ECX + 0x14) = uVar2;
  uVar2 = FUN_00405ed0();
  *(undefined4 *)(*(int *)(in_ECX + 0x14) + 0x20) = uVar2;
  puVar3 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0x371);
  if (puVar3 != (undefined4 *)0x0) {
    iVar1 = DAT_00c38db8;
    if (0xd7f < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xa1f4;
    }
    FUN_00407730(999,0xaa,0x127,0xbe,0x40,*(undefined4 *)(iVar1 + 8));
    *puVar3 = &PTR_LAB_007ed4e8;
    puVar3[0x8f] = 2;
    *(undefined1 *)((int)puVar3 + 0x22a) = 0;
    puVar3[0x90] = 0;
  }
  puVar3 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0x372);
  if (puVar3 != (undefined4 *)0x0) {
    iVar1 = DAT_00c38db8;
    if (0xd80 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xa200;
    }
    FUN_00407730(999,0x1b8,0x127,0xbe,0x40,*(undefined4 *)(iVar1 + 8));
    *puVar3 = &PTR_LAB_007ed4e8;
    puVar3[0x8f] = 0;
    *(undefined1 *)((int)puVar3 + 0x22a) = 0;
    puVar3[0x90] = 0;
  }
  puVar3 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0x375);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0xd57 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xa014;
    }
    FUN_00407730(999,0,0x172,0xbe,0x28,*(undefined4 *)(iVar1 + 8));
    *puVar3 = &PTR_LAB_007ed4e8;
    puVar3[0x8f] = 2;
    *(undefined1 *)((int)puVar3 + 0x22a) = 0;
    puVar3[0x90] = 0;
  }
  uVar2 = FUN_00405ed0();
  puVar3[8] = uVar2;
  iVar1 = FUN_00746d70(0x468,s_C__dev_black_frontend_cpp_00b17740,0x376);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0040a590(5,200,0x172,400,0x28,&DAT_00b6e5f0,1);
  }
  *(undefined4 *)(in_ECX + 0x24) = uVar2;
  uVar2 = FUN_00405ed0();
  *(undefined4 *)(*(int *)(in_ECX + 0x24) + 0x20) = uVar2;
  *(undefined4 *)(*(int *)(in_ECX + 0x24) + 0x240) = 0x1d;
  iVar1 = FUN_00746d70(0x25c,s_C__dev_black_frontend_cpp_00b17740,0x37a);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0xd61 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xa08c;
    }
    uVar2 = FUN_0040b4a0(2,0xd1,0x1c2,*(undefined4 *)(iVar1 + 8),0x19,2,0);
  }
  *(undefined4 *)(in_ECX + 0x18) = uVar2;
  iVar1 = FUN_00746d70(0x25c,s_C__dev_black_frontend_cpp_00b17740,0x37b);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0xd62 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xa098;
    }
    uVar2 = FUN_0040b4a0(3,0x144,0x1c2,*(undefined4 *)(iVar1 + 8),0x19,2,0);
  }
  *(undefined4 *)(in_ECX + 0x1c) = uVar2;
  iVar1 = FUN_00746d70(0x25c,s_C__dev_black_frontend_cpp_00b17740,0x37c);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0xd63 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0xa0a4;
    }
    uVar2 = FUN_0040b4a0(0x3e6,0x1bc,0x1c2,*(undefined4 *)(iVar1 + 8),0x19,2,0);
  }
  *(undefined4 *)(in_ECX + 0x50) = uVar2;
  iVar1 = FUN_00746d70(0x25c,s_C__dev_black_frontend_cpp_00b17740,0x37d);
  if (iVar1 == 0) {
    *(undefined4 *)(in_ECX + 0x20) = 0;
    FUN_00513120(2);
    return;
  }
  iVar1 = DAT_00c38db8;
  if (0xd4d < DAT_00c38dbc) {
    iVar1 = DAT_00c38db8 + 0x9f9c;
  }
  uVar2 = FUN_0040b4a0(4,0x22f,0x1c2,*(undefined4 *)(iVar1 + 8),0x19,2,0);
  *(undefined4 *)(in_ECX + 0x20) = uVar2;
  FUN_00513120(2);
  return;
}



// ?Destroy@ProfileEditor@@UAEXXZ @ 0x00511df0

void _Destroy_ProfileEditor__UAEXXZ(void)

{
  _Destroy__13DialogBoxBaseFv();
  DAT_00bf1e84 = 0;
  return;
}



// ?InitControls@ProfileEditor@@UAEXXZ @ 0x00511f60

void _InitControls_ProfileEditor__UAEXXZ(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  undefined1 auStack_200 [512];
  
  FUN_005120f0();
  FUN_00615ec0(auStack_200);
  iVar1 = FUN_00615ee0(auStack_200);
  iVar3 = *(int *)(in_ECX + 0x10);
  if ((iVar1 < 0) || (*(int *)(iVar3 + 0x250) <= iVar1)) {
    *(undefined4 *)(iVar3 + 0x248) = 0xffffffff;
  }
  else {
    *(int *)(iVar3 + 0x248) = iVar1;
  }
  if (((*(int *)(iVar3 + 4) != 0) && (DAT_00b6e5c0 != 0)) && (-1 < iVar1)) {
    iVar2 = FUN_007529d0();
    if (iVar2 != iVar1) {
      FUN_007529f0(0,*(int *)(iVar3 + 0x250) + -1,iVar1);
      FUN_004081a0(0);
    }
  }
  *(int *)(*(int *)(in_ECX + 0x10) + 0x248) = iVar1;
  FUN_00511f00();
  iVar3 = FUN_005256a0();
  *(uint *)(*(int *)(in_ECX + 0x24) + 0x25c) = (uint)(iVar3 == 0);
  return;
}



