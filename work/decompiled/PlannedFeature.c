// Decompiled functions for class: PlannedFeature
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetSaveType@PlannedFeature@@UAEIXZ @ 0x004fe2d0

undefined4 _GetSaveType_PlannedFeature__UAEIXZ(void)

{
  return 0x73;
}



// ?GetDebugText@PlannedFeature@@UAEPADXZ @ 0x004fe2e0

char * _GetDebugText_PlannedFeature__UAEPADXZ(void)

{
  return s_PlannedFeature__00b16f10;
}



// ?CreatePlanned@PlannedFeature@@UAEPAVMultiMapFixed@@M@Z @ 0x004fe2f0

undefined4 _CreatePlanned_PlannedFeature__UAEPAVMultiMapFixed__M_Z(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int *in_ECX;
  undefined4 unaff_EBX;
  float10 fVar5;
  
  iVar3 = in_ECX[10];
  piVar2 = (int *)FUN_00403e10();
  iVar1 = *piVar2;
  fVar5 = (float10)(**(code **)(*in_ECX + 0x120))();
  iVar3 = (**(code **)(iVar1 + 0x3c))(in_ECX + 5,iVar3,(float)fVar5);
  if (iVar3 != 0) {
    iVar3 = in_ECX[10];
    fVar5 = (float10)(**(code **)(*in_ECX + 0x120))(unaff_EBX,1);
    uVar4 = FUN_00403e10(iVar3,(float)fVar5);
    uVar4 = FUN_004fe1a0(in_ECX + 5,uVar4);
    return uVar4;
  }
  return 0;
}



