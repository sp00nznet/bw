// Decompiled functions for class: GComputerSpellCast
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetSaveType@GComputerSpellCast@@UAEIXZ @ 0x005315c0

undefined4 _GetSaveType_GComputerSpellCast__UAEIXZ(void)

{
  return 0x68;
}



// ?GetDebugText@GComputerSpellCast@@UAEPADXZ @ 0x005315d0

char * _GetDebugText_GComputerSpellCast__UAEPADXZ(void)

{
  return s_ComputerSpellCast__00b1b328;
}



// ?Save@GComputerSpellCast@@UAEIAAVGameOSFile@@@Z @ 0x00610440

undefined4 _Save_GComputerSpellCast__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_0053e8e0(param_1);
  if (iVar1 != 0) {
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x14));
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x18),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x18) + 4;
    }
    return 1;
  }
  return 0;
}



// ?Load@GComputerSpellCast@@UAEIAAVGameOSFile@@@Z @ 0x006104b0

undefined4 _Load_GComputerSpellCast__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = FUN_0053e9f0(param_1);
  if (iVar1 != 0) {
    FUN_00531f30(in_ECX + 0x14);
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x18),4,0,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x18) + 4;
    }
    return 1;
  }
  return 0;
}



