// Decompiled functions for class: PlannedTownCitadelHeart
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetSaveType@PlannedTownCitadelHeart@@UAEIXZ @ 0x00453100

undefined4 _GetSaveType_PlannedTownCitadelHeart__UAEIXZ(void)

{
  return 0x39;
}



// ?GetDebugText@PlannedTownCitadelHeart@@UAEPADXZ @ 0x00453110

char * _GetDebugText_PlannedTownCitadelHeart__UAEPADXZ(void)

{
  return s_PlannedTownCitadelHeart__008fd188;
}



// ?ToBeDeleted@PlannedTownCitadelHeart@@UAEXH@Z @ 0x00453120

void _ToBeDeleted_PlannedTownCitadelHeart__UAEXH_Z(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x48) != 0) {
    FUN_006d0000(in_ECX);
  }
  _ToBeDeleted_GameThingWithPos__UAEXH_Z(param_1);
  return;
}



// ?CreatePlanned@PlannedTownCitadelHeart@@UAEPAVMultiMapFixed@@M@Z @ 0x00453140

undefined4 _CreatePlanned_PlannedTownCitadelHeart__UAEPAVMultiMapFixed__M_Z(undefined4 param_1)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  undefined4 uVar3;
  
  iVar1 = in_ECX[10];
  uVar3 = 0;
  fVar2 = (float10)(**(code **)(*in_ECX + 0x120))(0);
  iVar1 = FUN_00454760(in_ECX + 5,iVar1,(float)fVar2,uVar3);
  if (iVar1 != 0) {
    uVar3 = (**(code **)(*in_ECX + 0x504))(param_1);
    return uVar3;
  }
  return 0;
}



// ?CreatePlannedNoFixedCheck@PlannedTownCitadelHeart@@UAEPAVMultiMapFixed@@M@Z @ 0x00453190

int _CreatePlannedNoFixedCheck_PlannedTownCitadelHeart__UAEPAVMultiMapFixed__M_Z(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  float10 fVar4;
  
  iVar2 = (**(code **)(*(int *)in_ECX[0x12] + 0x1c))();
  if (iVar2 == 0) {
    return 0;
  }
  iVar3 = *(int *)(iVar2 + 0x260);
  if (iVar3 == 0) {
    iVar3 = FUN_004300a0(0x80,s_C__dev_black_CitadelHeart_cpp_008fd078,0x714);
    if (iVar3 == 0) {
      return 0;
    }
    iVar3 = FUN_0044e400(in_ECX + 5,&DAT_00b7fa70,iVar2);
    if (iVar3 == 0) {
      return 0;
    }
  }
  iVar2 = in_ECX[10];
  iVar1 = in_ECX[0x10];
  fVar4 = (float10)(**(code **)(*in_ECX + 0x120))(param_1,1);
  iVar2 = FUN_00450280(in_ECX + 5,iVar1,iVar3,iVar2,(float)fVar4);
  if (iVar2 == 0) {
    return 0;
  }
  *(int *)(iVar2 + 0x94) = in_ECX[0x12];
  if (in_ECX[0xc] != 0) {
    *(byte *)(iVar2 + 0x58) = *(byte *)(iVar2 + 0x58) | 4;
  }
  (**(code **)(*in_ECX + 0x508))(iVar2);
  (**(code **)(*in_ECX + 0xc))(0);
  return iVar2;
}



