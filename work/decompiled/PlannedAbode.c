// Decompiled functions for class: PlannedAbode
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetTown@PlannedAbode@@QAEPAVTown@@XZ @ 0x00403be0

undefined4 _GetTown_PlannedAbode__QAEPAVTown__XZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x48);
}



// ?CreatePlanned@PlannedAbode@@QAEPAVMultiMapFixed@@M@Z @ 0x00403e20

undefined4 _CreatePlanned_PlannedAbode__QAEPAVMultiMapFixed__M_Z(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  float10 fVar3;
  int *piVar4;
  float fVar5;
  int iVar6;
  
  iVar1 = in_ECX[10];
  iVar6 = in_ECX[0x12];
  fVar3 = (float10)(**(code **)(*in_ECX + 0x120))(iVar6);
  fVar5 = (float)fVar3;
  piVar4 = in_ECX + 5;
  FUN_00403e10(piVar4,iVar1,fVar5);
  iVar1 = FUN_00403640(piVar4,iVar1,fVar5,iVar6);
  if (iVar1 != 0) {
    uVar2 = (**(code **)(*in_ECX + 0x504))(param_1);
    return uVar2;
  }
  return 0;
}



// ?IsWonder@PlannedAbode@@UAE_NXZ @ 0x00404830

bool _IsWonder_PlannedAbode__UAE_NXZ(void)

{
  int iVar1;
  
  iVar1 = FUN_00403e10();
  return *(int *)(iVar1 + 0x120) == 0x100;
}



