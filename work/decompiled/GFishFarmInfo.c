// Decompiled functions for class: GFishFarmInfo
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetBaseInfo@GFishFarmInfo@@UAEPAVGBaseInfo@@AAI@Z @ 0x00502920

undefined * _GetBaseInfo_GFishFarmInfo__UAEPAVGBaseInfo__AAI_Z(undefined4 *param_1)

{
  *param_1 = 1;
  return &DAT_00bf0fd8;
}



// ?IsOkToCreateAtPos@GFishFarmInfo@@UBE_NABUMapCoords@@MM@Z @ 0x00503530

undefined4 _IsOkToCreateAtPos_GFishFarmInfo__UBE_NABUMapCoords__MM_Z(void)

{
  int iVar1;
  
  iVar1 = FUN_005bfbf0();
  if (iVar1 != 0) {
    iVar1 = FUN_005c0740(0x21,0);
    if (iVar1 == 0) {
      return 1;
    }
  }
  return 0;
}



