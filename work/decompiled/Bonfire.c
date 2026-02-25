// Decompiled functions for class: Bonfire
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetSaveType@Bonfire@@UAEIXZ @ 0x00432390

undefined4 _GetSaveType_Bonfire__UAEIXZ(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _GetSaveType_Rock__UAEIXZ(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x94),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x94) + 4;
    }
    return 1;
  }
  return 0;
}



// ?Save@Bonfire@@UAEIAAVGameOSFile@@@Z @ 0x00432400

undefined4 _Save_Bonfire__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Save_Rock__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x94),4,0,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x94) + 4;
    }
    return 1;
  }
  return 0;
}



