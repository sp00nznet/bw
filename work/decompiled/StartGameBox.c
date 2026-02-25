// Decompiled functions for class: StartGameBox
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Init@StartGameBox@@UAEXIIP6AXHPAVSetupBox@@PAVSetupControl@@HH@Z@Z @ 0x00517d40

void _Init_StartGameBox__UAEXIIP6AXHPAVSetupBox__PAVSetupControl__HH_Z_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  
  _Init__13DialogBoxBaseFUlUlPFiP8SetupBoxP12SetupControlii_v(param_1,param_2,param_3);
  DAT_00bf1ed0 = in_ECX;
  uVar1 = FUN_00405ef0();
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0xac) = uVar1;
  puVar2 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0xd56);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    FUN_00407730(1,0x28,0x1e,0x2d0,0x28,&DAT_00b6e5f0);
    *puVar2 = &PTR_LAB_007ed4e8;
    puVar2[0x8f] = 4;
    *(undefined1 *)((int)puVar2 + 0x22a) = 0;
    puVar2[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x10) = puVar2;
  iVar3 = FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0xd58);
  if (iVar3 == 0) {
    uVar1 = 0;
  }
  else {
    iVar3 = DAT_00c38db8;
    if (0x1a60 < DAT_00c38dbc) {
      iVar3 = DAT_00c38db8 + 0x13c80;
    }
    uVar1 = FUN_00407d30(999,0x140,0x212,0xa0,0x28,*(undefined4 *)(iVar3 + 8),1);
  }
  *(undefined4 *)(in_ECX + 0x18) = uVar1;
  iVar3 = FUN_00746d70(0x2b0,s_C__dev_black_frontend_cpp_00b17740,0xd59);
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = FUN_004087c0(0,100,0x6e,600,0x17c);
  }
  *(int *)(in_ECX + 0x14) = iVar3;
  *(undefined1 *)(iVar3 + 0x291) = 0;
  iVar3 = FUN_00746d70(0x25c,s_C__dev_black_frontend_cpp_00b17740,0xd5c);
  if (iVar3 == 0) {
    *(undefined4 *)(in_ECX + 0x1c) = 0;
    return;
  }
  uVar1 = FUN_0040b4a0(999,0x1e,0x212,&DAT_00b6e5f0,0x28,0,2);
  *(undefined4 *)(in_ECX + 0x1c) = uVar1;
  return;
}



// ?Destroy@StartGameBox@@UAEXXZ @ 0x00517ec0

void _Destroy_StartGameBox__UAEXXZ(void)

{
  _Destroy__13DialogBoxBaseFv();
  DAT_00bf1ed0 = 0;
  return;
}



// ?InitControls@StartGameBox@@UAEXXZ @ 0x00517ed0

void _InitControls_StartGameBox__UAEXXZ(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = DAT_00c38db8;
  if (0xd7a < DAT_00c38dbc) {
    iVar1 = DAT_00c38db8 + 0xa1b8;
  }
  FUN_00733ff8(*(int *)(in_ECX + 0x1c) + 0x24,*(undefined4 *)(iVar1 + 8));
  return;
}



