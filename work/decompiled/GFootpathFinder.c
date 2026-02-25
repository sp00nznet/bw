// Decompiled functions for class: GFootpathFinder
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetDebugText@GFootpathFinder@@UAEPADXZ @ 0x0050d6b0

char * _GetDebugText_GFootpathFinder__UAEPADXZ(void)

{
  return s_Footpath_pathfinder__00b17440;
}



// ?Save@GFootpathFinder@@UAEIAAVGameOSFile@@@Z @ 0x0050d820

undefined4 _Save_GFootpathFinder__UAEIAAVGameOSFile___Z(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_0053e8e0(param_1);
  if (iVar1 == 0) {
    return 0;
  }
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0x640b4));
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0x640b8));
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0x640bc));
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0x640c0));
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0x640c4));
  return 1;
}



// ?ToBeDeleted@GFootpathFinder@@UAEXH@Z @ 0x0050d890

void _ToBeDeleted_GFootpathFinder__UAEXH_Z(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int in_ECX;
  
  iVar5 = DAT_00c22ca4;
  piVar1 = (int *)(DAT_00c22ca4 + 0x201ca8);
  piVar2 = (int *)*piVar1;
  piVar4 = (int *)0x0;
  while (piVar3 = piVar4, piVar4 = piVar2, piVar4 != (int *)0x0) {
    piVar2 = (int *)*piVar4;
    if (piVar4[1] == in_ECX) {
      if (piVar4 == (int *)*piVar1) {
        *piVar1 = (int)piVar2;
      }
      else {
        *piVar3 = (int)piVar2;
      }
      *(int *)(iVar5 + 0x201cac) = *(int *)(iVar5 + 0x201cac) + -1;
      FUN_007290de(piVar4);
      piVar4 = piVar3;
    }
  }
  if ((*(int **)(in_ECX + 0x640bc) != (int *)0x0) &&
     (iVar5 = (**(code **)(**(int **)(in_ECX + 0x640bc) + 0x2c))(), iVar5 != 0)) {
    (**(code **)(**(int **)(in_ECX + 0x640bc) + 0xc))(0);
  }
  _ToBeDeleted_GameThing__UAEXH_Z(param_1);
  return;
}



