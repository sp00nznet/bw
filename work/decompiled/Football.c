// Decompiled functions for class: Football
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetCreatureBeliefType@Football@@UAEIXZ @ 0x005070f0

undefined4 _GetCreatureBeliefType_Football__UAEIXZ(void)

{
  return 0x45;
}



// ?SetVillagerActivity@Football@@UAEIPAVVillager@@@Z @ 0x00507bb0

undefined4 _SetVillagerActivity_Football__UAEIPAVVillager___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_005071d0();
  if ((*(int *)(in_ECX + 0x2f8) != 0) && (iVar1 != 0)) {
    iVar1 = FUN_005080b0(param_1);
    if (iVar1 != 1) {
      iVar1 = FUN_00507e80(param_1,1);
      if (iVar1 != 1) {
        iVar1 = FUN_00507e80(param_1,0);
        if (iVar1 != 1) {
          FUN_005080e0(param_1);
        }
      }
    }
    *(byte *)(param_1 + 0xe0) = *(byte *)(param_1 + 0xe0) | 0x80;
    *(int *)(param_1 + 0x114) = in_ECX;
    return 1;
  }
  return 0;
}



// ?GetVillagerActivityDesire@Football@@UAEMPAVVillager@@@Z @ 0x00507c20

float10 _GetVillagerActivityDesire_Football__UAEMPAVVillager___Z(void)

{
  int in_ECX;
  float10 fVar1;
  
  if (((4 < *(uint *)(in_ECX + 0x224)) && (4 < *(uint *)(in_ECX + 0x22c))) &&
     (*(int *)(in_ECX + 0x21c) != 0)) {
    fVar1 = (float10)FUN_0067bcb0(0x3f800000,s_C__dev_black_FootBall_cpp_00b171d4,0x280);
    return fVar1;
  }
  return (float10)1.0;
}



