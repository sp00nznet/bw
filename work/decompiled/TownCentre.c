// Decompiled functions for class: TownCentre
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetSaveType@TownCentre@@UAEIXZ @ 0x0052eca0

char * _GetSaveType_TownCentre__UAEIXZ(void)

{
  return s_TownCentre__00b1a424;
}



// ?ToBeDeleted@TownCentre@@UAEXH@Z @ 0x006d5ce0

void _ToBeDeleted_TownCentre__UAEXH_Z(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *in_ECX;
  
  FUN_00642a00();
  (**(code **)(*in_ECX + 0x910))();
  if ((int *)in_ECX[0x33] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x33] + 0xc))(param_1);
  }
  iVar4 = DAT_00c22ca4;
  piVar1 = (int *)(DAT_00c22ca4 + 0x201db8);
  piVar2 = *(int **)(DAT_00c22ca4 + 0x201db8);
  piVar5 = (int *)0x0;
  while (piVar3 = piVar5, piVar5 = piVar2, piVar5 != (int *)0x0) {
    piVar2 = (int *)*piVar5;
    if ((int *)piVar5[1] == in_ECX) {
      if (piVar5 == (int *)*piVar1) {
        *piVar1 = (int)piVar2;
      }
      else {
        *piVar3 = (int)piVar2;
      }
      *(int *)(iVar4 + 0x201dbc) = *(int *)(iVar4 + 0x201dbc) + -1;
      FUN_007290de(piVar5);
      piVar5 = piVar3;
    }
  }
  FUN_004019f0(param_1);
  return;
}



// ?GetArrivePos@TownCentre@@UAEPAUMapCoords@@PAU2@@Z @ 0x006d66f0

undefined4 _GetArrivePos_TownCentre__UAEPAUMapCoords__PAU2__Z(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _GetArrivePos_Creche__UAEPAUMapCoords__PAU2__Z(param_1);
  if (iVar1 != 0) {
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0xcc));
    FUN_00531ff0(in_ECX + 0xd0,6);
    return 1;
  }
  return 0;
}



