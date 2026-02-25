// Decompiled functions for class: LoadingBox
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Init@LoadingBox@@UAEXIIP6AXHPAVSetupBox@@PAVSetupControl@@HH@Z@Z @ 0x005110c0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _Init_LoadingBox__UAEXIIP6AXHPAVSetupBox__PAVSetupControl__HH_Z_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 in_ECX;
  
  _Init__13DialogBoxBaseFUlUlPFiP8SetupBoxP12SetupControlii_v(param_1,param_2,param_3);
  _DAT_00bf1e78 = in_ECX;
  return;
}



// ?Destroy@LoadingBox@@UAEXXZ @ 0x005110f0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _Destroy_LoadingBox__UAEXXZ(void)

{
  _Destroy__13DialogBoxBaseFv();
  _DAT_00bf1e78 = 0;
  return;
}



