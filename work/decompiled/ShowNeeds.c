// Decompiled functions for class: ShowNeeds
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetSaveType@ShowNeeds@@UAEIXZ @ 0x0052ed90

undefined4 _GetSaveType_ShowNeeds__UAEIXZ(void)

{
  return 0x3e;
}



// ?GetDebugText@ShowNeeds@@UAEPADXZ @ 0x0052eda0

char * _GetDebugText_ShowNeeds__UAEPADXZ(void)

{
  return s_ShowNeeds__00b1a454;
}



// ?ToBeDeleted@ShowNeeds@@UAEXH@Z @ 0x006b13a0

void _ToBeDeleted_ShowNeeds__UAEXH_Z(undefined4 param_1)

{
  int in_ECX;
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(in_ECX + 0x18);
  iVar2 = 3;
  do {
    if ((int *)*piVar1 != (int *)0x0) {
      (**(code **)(*(int *)*piVar1 + 0xc))(param_1);
    }
    piVar1 = piVar1 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  _ToBeDeleted_GameThing__UAEXH_Z(param_1);
  return;
}



// ?GetPlayer@ShowNeeds@@UAEPAVGPlayer@@XZ @ 0x006b14b0

undefined4 _GetPlayer_ShowNeeds__UAEPAVGPlayer__XZ(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x14) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x006b14b9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(**(int **)(in_ECX + 0x14) + 0x1c))();
    return uVar1;
  }
  return 0;
}



// ?Save@ShowNeeds@@UAEIAAVGameOSFile@@@Z @ 0x006b14c0

undefined4 _Save_ShowNeeds__UAEIAAVGameOSFile___Z(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_0053e8e0(param_1);
  if (iVar1 != 0) {
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x14));
    FUN_00531ff0(in_ECX + 0x18,3);
    return 1;
  }
  return 0;
}



// ?Load@ShowNeeds@@UAEIAAVGameOSFile@@@Z @ 0x006b1500

undefined4 _Load_ShowNeeds__UAEIAAVGameOSFile___Z(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_0053e9f0(param_1);
  if (iVar1 != 0) {
    FUN_00531f30(in_ECX + 0x14);
    FUN_00532060(in_ECX + 0x18);
    return 1;
  }
  return 0;
}



// ?GetShowNeedsPos@ShowNeeds@@UAEIIPAUMapCoords@@@Z @ 0x006b1540

undefined4 _GetShowNeedsPos_ShowNeeds__UAEIIPAUMapCoords___Z(undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  (**(code **)(**(int **)(*(int *)(in_ECX + 0x14) + 0x100) + 0xe4))(param_1,param_2);
  return 1;
}



