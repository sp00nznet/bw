// Decompiled functions for class: EditingDebugBox
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Init@EditingDebugBox@@UAEXIIP6AXHPAVSetupBox@@PAVSetupControl@@HH@Z@Z @ 0x00511100

void _Init_EditingDebugBox__UAEXIIP6AXHPAVSetupBox__PAVSetupControl__HH_Z_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  _Init__13DialogBoxBaseFUlUlPFiP8SetupBoxP12SetupControlii_v(param_1,param_2,param_3);
  DAT_00bf1e7c = in_ECX;
  iVar1 = FUN_00746d70(0x468,s_C__dev_black_frontend_cpp_00b17740,0x2ba);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = FUN_0040a590(1,200,300,400,0x1e,&DAT_00b6e5f0,1);
  }
  *(undefined4 *)(in_ECX + 0x14) = uVar2;
  uVar2 = FUN_00405ed0();
  *(undefined4 *)(*(int *)(in_ECX + 0x14) + 0x20) = uVar2;
  puVar3 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0x2bd);
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = (undefined4 *)0x0;
  }
  else {
    FUN_00407730(2,200,0xfa,400,0x1e,&DAT_00b6e5f0);
    *puVar3 = &PTR_LAB_007ed4e8;
    puVar3[0x8f] = 1;
    *(undefined1 *)((int)puVar3 + 0x22a) = 0;
    puVar3[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x10) = puVar3;
  uVar2 = FUN_00405ed0();
  *(undefined4 *)(*(int *)(in_ECX + 0x10) + 0x20) = uVar2;
  iVar1 = FUN_00746d70(0x25c,s_C__dev_black_frontend_cpp_00b17740,0x2c1);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0xa23 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0x79a4;
    }
    uVar2 = FUN_0040b4a0(3,0x23a,0x15e,*(undefined4 *)(iVar1 + 8),0x1e,1,3);
  }
  *(undefined4 *)(in_ECX + 0x1c) = uVar2;
  iVar1 = FUN_00746d70(0x25c,s_C__dev_black_frontend_cpp_00b17740,0x2c2);
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = DAT_00c38db8;
    if (0xa24 < DAT_00c38dbc) {
      iVar1 = DAT_00c38db8 + 0x79b0;
    }
    uVar2 = FUN_0040b4a0(4,200,0x15e,*(undefined4 *)(iVar1 + 8),0x1e,0,2);
  }
  *(undefined4 *)(in_ECX + 0x18) = uVar2;
  *(undefined4 *)(in_ECX + 0x20) = 0;
  *(undefined4 *)(in_ECX + 0x224) = 0;
  iVar1 = DAT_00c38db8;
  if (0x1a84 < DAT_00c38dbc) {
    iVar1 = DAT_00c38db8 + 0x13e30;
  }
  FUN_00733ff8(in_ECX + 0x24,*(undefined4 *)(iVar1 + 8));
  return;
}



// ?Destroy@EditingDebugBox@@UAEXXZ @ 0x005112d0

void _Destroy_EditingDebugBox__UAEXXZ(void)

{
  _Destroy__13DialogBoxBaseFv();
  DAT_00bf1e7c = 0;
  return;
}



// ?InitControls@EditingDebugBox@@UAEXXZ @ 0x005112e0

void _InitControls_EditingDebugBox__UAEXXZ(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x14);
  FUN_00734395(iVar1 + 0x24,*(undefined4 *)(in_ECX + 0x224),0xff);
  *(undefined2 *)(iVar1 + 0x222) = 0;
  uVar2 = FUN_007343d2(iVar1 + 0x24);
  *(undefined4 *)(iVar1 + 0x24c) = uVar2;
  *(undefined4 *)(iVar1 + 0x254) = uVar2;
  *(undefined4 *)(iVar1 + 0x250) = uVar2;
  *(undefined4 *)(iVar1 + 600) = 0;
  FUN_00733ff8(*(int *)(in_ECX + 0x10) + 0x24,in_ECX + 0x24);
  return;
}



