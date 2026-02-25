// Decompiled functions for class: GMultiMapFixedInfo
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?IsOkToCreateAtPos@GMultiMapFixedInfo@@UBE_NABUMapCoords@@MM@Z @ 0x004ff8a0

bool _IsOkToCreateAtPos_GMultiMapFixedInfo__UBE_NABUMapCoords__MM_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  
  uVar1 = (**(code **)(*in_ECX + 0x2c))(param_2,param_3);
  iVar2 = FUN_005bfd80(uVar1,param_2,param_3);
  return iVar2 != 0;
}



