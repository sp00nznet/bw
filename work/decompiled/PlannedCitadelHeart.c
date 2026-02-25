// Decompiled functions for class: PlannedCitadelHeart
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?CreatePlanned@PlannedCitadelHeart@@UAEPAVMultiMapFixed@@M@Z @ 0x00450d90

int _CreatePlanned_PlannedCitadelHeart__UAEPAVMultiMapFixed__M_Z(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  float10 fVar3;
  int iVar4;
  
  iVar2 = in_ECX[10];
  iVar4 = in_ECX[0x12];
  fVar3 = (float10)(**(code **)(*in_ECX + 0x120))(iVar4);
  iVar2 = FUN_00454760(in_ECX + 5,iVar2,(float)fVar3,iVar4);
  if (iVar2 != 0) {
    iVar2 = in_ECX[10];
    iVar4 = in_ECX[0x12];
    iVar1 = in_ECX[0x10];
    fVar3 = (float10)(**(code **)(*in_ECX + 0x120))(param_1,1);
    iVar2 = FUN_00450280(in_ECX + 5,iVar1,iVar4,iVar2,(float)fVar3);
    if (iVar2 != 0) {
      (**(code **)(*in_ECX + 0x508))(iVar2);
    }
    return iVar2;
  }
  return 0;
}



// ?CreateBuildingSite@PlannedCitadelHeart@@UAEIXZ @ 0x00454020

undefined4 _CreateBuildingSite_PlannedCitadelHeart__UAEIXZ(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 in_ECX;
  
  iVar1 = FUN_004300a0(0x65c,s_C__dev_black_CitadelHeart_cpp_008fd078,0x928);
  if (iVar1 != 0) {
    uVar2 = FUN_00435890(in_ECX);
    return uVar2;
  }
  return 0;
}



