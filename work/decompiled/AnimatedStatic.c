// Decompiled functions for class: AnimatedStatic
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?ToBeDeleted@AnimatedStatic@@UAEXH@Z @ 0x0041d080

void _ToBeDeleted_AnimatedStatic__UAEXH_Z(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int in_ECX;
  
  iVar4 = DAT_00c22ca4;
  piVar1 = (int *)(DAT_00c22ca4 + 0x201d78);
  piVar2 = (int *)*piVar1;
  piVar5 = (int *)0x0;
  while (piVar3 = piVar5, piVar5 = piVar2, piVar5 != (int *)0x0) {
    piVar2 = (int *)*piVar5;
    if (piVar5[1] == in_ECX) {
      if (piVar5 == (int *)*piVar1) {
        *piVar1 = (int)piVar2;
      }
      else {
        *piVar3 = (int)piVar2;
      }
      *(int *)(iVar4 + 0x201d7c) = *(int *)(iVar4 + 0x201d7c) + -1;
      FUN_007290de(piVar5);
      piVar5 = piVar3;
    }
  }
  _ToBeDeleted_MultiMapFixed__UAEXH_Z(param_1);
  return;
}



