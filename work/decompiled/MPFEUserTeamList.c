// Decompiled functions for class: MPFEUserTeamList
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Send@MPFEUserTeamList@@UAEXPAUMPFEPlayerDetails@@@Z @ 0x005e5720

void _Send_MPFEUserTeamList__UAEXPAUMPFEPlayerDetails___Z(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &vftable_MPFEMessageObject;
  if (in_ECX[1] != 0) {
    FUN_007290de(in_ECX[1]);
  }
  if ((param_1 & 1) != 0) {
    FUN_007290de();
  }
  return;
}



