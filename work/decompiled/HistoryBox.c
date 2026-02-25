// Decompiled functions for class: HistoryBox
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Init@HistoryBox@@UAEXIIP6AXHPAVSetupBox@@PAVSetupControl@@HH@Z@Z @ 0x005188d0

void _Init_HistoryBox__UAEXIIP6AXHPAVSetupBox__PAVSetupControl__HH_Z_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  
  _Init__13DialogBoxBaseFUlUlPFiP8SetupBoxP12SetupControlii_v(param_1,param_2,param_3);
  DAT_00bf1edc = in_ECX;
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x94) = 0;
  uVar1 = FUN_00405ef0();
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0xac) = uVar1;
  iVar2 = FUN_00746d70(0x25c,s_C__dev_black_frontend_cpp_00b17740,0xe80);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0x1a10 < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0x138c0;
    }
    uVar1 = FUN_0040b4a0(1,0x3c,500,*(undefined4 *)(iVar2 + 8),0x28,0,2);
  }
  *(undefined4 *)(in_ECX + 0x10) = uVar1;
  iVar2 = FUN_00746d70(0x25c,s_C__dev_black_frontend_cpp_00b17740,0xe81);
  if (iVar2 == 0) {
    uVar1 = 0;
  }
  else {
    iVar2 = DAT_00c38db8;
    if (0x1a0f < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0x138b4;
    }
    uVar1 = FUN_0040b4a0(2,700,500,*(undefined4 *)(iVar2 + 8),0x28,1,3);
  }
  *(undefined4 *)(in_ECX + 0x18) = uVar1;
  iVar2 = FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0xe82);
  if (iVar2 == 0) {
    *(undefined4 *)(in_ECX + 0x14) = 0;
    uVar1 = FUN_00405ed0();
    *(undefined4 *)(*(int *)(in_ECX + 0x14) + 0x20) = uVar1;
    return;
  }
  iVar2 = DAT_00c38db8;
  if (0x1a73 < DAT_00c38dbc) {
    iVar2 = DAT_00c38db8 + 0x13d64;
  }
  uVar1 = FUN_00407d30(999,0x140,500,0xa0,0x28,*(undefined4 *)(iVar2 + 8),1);
  *(undefined4 *)(in_ECX + 0x14) = uVar1;
  uVar1 = FUN_00405ed0();
  *(undefined4 *)(*(int *)(in_ECX + 0x14) + 0x20) = uVar1;
  return;
}



// ?Destroy@HistoryBox@@UAEXXZ @ 0x00518a50

void _Destroy_HistoryBox__UAEXXZ(void)

{
  _Destroy__13DialogBoxBaseFv();
  DAT_00bf1edc = 0;
  return;
}



// ?WantsMouseControl@HistoryBox@@UAE_NXZ @ 0x00518af0

bool _WantsMouseControl_HistoryBox__UAE_NXZ(void)

{
  int iVar1;
  undefined4 auStack_10 [2];
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar1 = FUN_004f02b0();
  if (iVar1 == 0) {
    return false;
  }
  uStack_8 = DAT_00d5c370;
  uStack_4 = DAT_00d5c374;
  auStack_10[0] = DAT_00d5c374;
  FUN_0040fc50(&uStack_8,auStack_10);
  iVar1 = FUN_004065e0(uStack_8,auStack_10[0]);
  if (iVar1 != 0) {
    return true;
  }
  return DAT_00b6e5cc != 0;
}



