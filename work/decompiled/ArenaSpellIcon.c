// Decompiled functions for class: ArenaSpellIcon
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetSaveType@ArenaSpellIcon@@UAEIXZ @ 0x0041f940

undefined4 _GetSaveType_ArenaSpellIcon__UAEIXZ(void)

{
  return 0x42;
}



// ?GetDebugText@ArenaSpellIcon@@UAEPADXZ @ 0x0041f950

char * _GetDebugText_ArenaSpellIcon__UAEPADXZ(void)

{
  return s_SpellIcon__008f83c8;
}



// ?ToBeDeleted@ArenaSpellIcon@@UAEXH@Z @ 0x0041fb70

void _ToBeDeleted_ArenaSpellIcon__UAEXH_Z(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x5c) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x5c) + 0xc))(0);
    *(undefined4 *)(in_ECX + 0x5c) = 0;
  }
  iVar1 = *(int *)(in_ECX + 0x68);
  if (iVar1 != 0) {
    FUN_0041eda0();
    FUN_007290de(iVar1);
    *(undefined4 *)(in_ECX + 0x68) = 0;
  }
  _ToBeDeleted_Object__UAEXH_Z(param_1);
  return;
}



// ?Save@ArenaSpellIcon@@UAEIAAVGameOSFile@@@Z @ 0x0041fc20

undefined4 _Save_ArenaSpellIcon__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_Fixed__UAEIPAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x58));
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x60),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x60) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90((byte *)(in_ECX + 100),4,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 100) + 4;
        if (DAT_00b19ac8 != 0) {
          iVar1 = FUN_0072be90((byte *)(in_ECX + 0x6c),4,0);
          if (iVar1 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x6c) + 4;
        }
      }
    }
    return 1;
  }
  return 0;
}



// ?Load@ArenaSpellIcon@@UAEIAAVGameOSFile@@@Z @ 0x0041fd10

undefined4 _Load_ArenaSpellIcon__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Load_Fixed__QAEIAAVGGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    FUN_00531f30(in_ECX + 0x58);
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x60),4,0,unaff_EBX,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x60) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 100) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x6c) + 4;
    }
    return 1;
  }
  return 0;
}



