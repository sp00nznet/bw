// Decompiled functions for class: SpellDove
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?StandAnimation@SpellDove@@UAEIXZ @ 0x004180c0

undefined4 _StandAnimation_SpellDove__UAEIXZ(void)

{
  return 0x17;
}



// ?GetNumTurnsToDieOver@SpellDove@@UAEIXZ @ 0x004181a0

undefined4 _GetNumTurnsToDieOver_SpellDove__UAEIXZ(void)

{
  return 0x14;
}



// ?GetSaveType@SpellDove@@UAEIXZ @ 0x00419e00

undefined4 _GetSaveType_SpellDove__UAEIXZ(void)

{
  return 0x90;
}



// ?GetDebugText@SpellDove@@UAEPADXZ @ 0x00419e10

char * _GetDebugText_SpellDove__UAEPADXZ(void)

{
  return s_Animal__SpellDove_008f7f70;
}



// ?SetDying@SpellDove@@UAE_NXZ @ 0x0041a690

undefined4 _SetDying_SpellDove__UAE_NXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  if ((float)in_ECX[0x53] != 0.0) {
    iVar1 = (**(code **)(*in_ECX + 0x880))();
    (**(code **)(*in_ECX + 0xbd0))((float)iVar1 * (float)DAT_00c22d78 * 0.001);
  }
  return 1;
}



// ?Load@SpellDove@@UAEIAAVGameOSFile@@@Z @ 0x0041ab90

undefined4 _Load_SpellDove__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Load_Dove__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x148),0x30,0,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x148) + 0x30;
    }
    return 1;
  }
  return 0;
}



// ?Save@SpellDove@@UAEIAAVGameOSFile@@@Z @ 0x0041ac00

undefined4 _Save_SpellDove__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_Dove__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x148),0x30,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x148) + 0x30;
    }
    return 1;
  }
  return 0;
}



