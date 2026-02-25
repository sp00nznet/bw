// Decompiled functions for class: LHReleasedOSFileFPc12LH_FILE_MODE
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// _Open__16LHReleasedOSFileFPc12LH_FILE_MODE @ 0x0072bd50

undefined4 _Open__16LHReleasedOSFileFPc12LH_FILE_MODE(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 local_100 [256];
  
  iVar1 = FUN_0072bca0(param_1,param_2);
  if (iVar1 == 0) {
    return 0;
  }
  if ((param_2 != 2) && (param_2 != 1)) {
    return 2;
  }
  FUN_00733e17(local_100,s__c___s_008f9c88,(int)DAT_00b4dee8,param_1);
  uVar2 = FUN_0072bca0(local_100,param_2);
  return uVar2;
}



