// Decompiled functions for class: TownSpellIcon
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetTown@TownSpellIcon@@UAEPAVTown@@XZ @ 0x0052eff0

undefined4 _GetTown_TownSpellIcon__UAEPAVTown__XZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x114);
}



// ?ToBeDeleted@TownSpellIcon@@UAEXH@Z @ 0x006da4c0

void _ToBeDeleted_TownSpellIcon__UAEXH_Z(undefined4 param_1)

{
  int iVar1;
  int *in_ECX;
  int *piVar2;
  
  iVar1 = (**(code **)(*in_ECX + 0x48))();
  if (iVar1 != 0) {
    piVar2 = in_ECX;
    (**(code **)(*in_ECX + 0x48))();
    FUN_006d00e0(piVar2);
    in_ECX[0x45] = 0;
  }
  FUN_006bcce0(param_1);
  return;
}



