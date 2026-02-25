// Decompiled functions for class: Graveyard
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetSaveType@Graveyard@@UAEIXZ @ 0x0052efb0

char * _GetSaveType_Graveyard__UAEIXZ(void)

{
  return s_GraveYard__00b1a4dc;
}



// ?GetArrivePos@Graveyard@@UAEPAUMapCoords@@PAU2@@Z @ 0x00702450

undefined4 _GetArrivePos_Graveyard__UAEPAUMapCoords__PAU2__Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _GetArrivePos_Creche__UAEPAUMapCoords__PAU2__Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0xc4),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xc4) + 4;
    }
    return 1;
  }
  return 0;
}



