// Decompiled functions for class: ScriptTimer
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetText@ScriptTimer@@UAEPBDXZ @ 0x00531470

char * _GetText_ScriptTimer__UAEPBDXZ(void)

{
  return s_Script_Timer_00b1b2d4;
}



// ?GetSaveType@ScriptTimer@@UAEIXZ @ 0x00531480

undefined4 _GetSaveType_ScriptTimer__UAEIXZ(void)

{
  return 0x7d;
}



// ?GetDebugText@ScriptTimer@@UAEPADXZ @ 0x00531490

char * _GetDebugText_ScriptTimer__UAEPADXZ(void)

{
  return s_ScriptTimer__00b1b2e4;
}



// ?Save@ScriptTimer@@UAEIAAVGameOSFile@@@Z @ 0x006aab10

undefined4 _Save_ScriptTimer__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_GameThingWithPos__UAEXPAUGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x28),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x28) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90((byte *)(in_ECX + 0x2c),4,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x2c) + 4;
      }
    }
    return 1;
  }
  return 0;
}



// ?Load@ScriptTimer@@UAEIAAVGameOSFile@@@Z @ 0x006aabc0

undefined4 _Load_ScriptTimer__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Load_GameThingWithPos__QAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x28),4,0,unaff_EDI,unaff_ESI,unaff_EBX);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x28) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x2c) + 4;
    }
    return 1;
  }
  return 0;
}



