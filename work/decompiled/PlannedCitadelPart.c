// Decompiled functions for class: PlannedCitadelPart
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Save@PlannedCitadelPart@@UAEIAAVGameOSFile@@@Z @ 0x00403f00

undefined4 _Save_PlannedCitadelPart__UAEIAAVGameOSFile___Z(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_PlannedMultiMapFixed__QAEIAAVGGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x48));
    return 1;
  }
  return 0;
}



// ?GetSaveType@PlannedCitadelPart@@UAEIXZ @ 0x00450900

undefined4 _GetSaveType_PlannedCitadelPart__UAEIXZ(void)

{
  return 0x37;
}



// ?GetDebugText@PlannedCitadelPart@@UAEPADXZ @ 0x00450910

char * _GetDebugText_PlannedCitadelPart__UAEPADXZ(void)

{
  return s_PlannedCitadelPart__008fd104;
}



// ?Load@PlannedCitadelPart@@UAEIAAVGameOSFile@@@Z @ 0x00453260

undefined4 _Load_PlannedCitadelPart__UAEIAAVGameOSFile___Z(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Load_PlannedMultiMapFixed__QAEIAAVGGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    FUN_00531f30(in_ECX + 0x48);
    return 1;
  }
  return 0;
}



// ?ToBeDeleted@PlannedCitadelPart@@UAEXH@Z @ 0x004547e0

void _ToBeDeleted_PlannedCitadelPart__UAEXH_Z(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x48);
  if (iVar1 != 0) {
    iVar3 = *(int *)(iVar1 + 0x5c);
    if (iVar3 == in_ECX) {
      *(undefined4 *)(iVar1 + 0x5c) = *(undefined4 *)(in_ECX + 0x44);
    }
    else {
      if (iVar3 == 0) goto LAB_00454826;
      while (iVar2 = *(int *)(iVar3 + 0x44), iVar2 != in_ECX) {
        iVar3 = iVar2;
        if (iVar2 == 0) {
          _ToBeDeleted_GameThingWithPos__UAEXH_Z(param_1);
          return;
        }
      }
      *(undefined4 *)(iVar3 + 0x44) = *(undefined4 *)(in_ECX + 0x44);
    }
    *(int *)(iVar1 + 0x60) = *(int *)(iVar1 + 0x60) + -1;
    *(undefined4 *)(in_ECX + 0x44) = 0;
  }
LAB_00454826:
  _ToBeDeleted_GameThingWithPos__UAEXH_Z(param_1);
  return;
}



