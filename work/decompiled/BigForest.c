// Decompiled functions for class: BigForest
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?ToBeDeleted@BigForest@@UAEXH@Z @ 0x00431a40

void _ToBeDeleted_BigForest__UAEXH_Z(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  iVar3 = DAT_00c22ca4;
  iVar1 = *(int *)(DAT_00c22ca4 + 0x201da0);
  if (iVar1 == in_ECX) {
    *(int *)(DAT_00c22ca4 + 0x201da0) = *(int *)(in_ECX + 0x7c);
  }
  else {
    do {
      iVar2 = iVar1;
      if (iVar2 == 0) goto LAB_00431a7c;
      iVar1 = *(int *)(iVar2 + 0x7c);
    } while (*(int *)(iVar2 + 0x7c) != in_ECX);
    *(undefined4 *)(iVar2 + 0x7c) = *(undefined4 *)(in_ECX + 0x7c);
  }
  *(int *)(iVar3 + 0x201da4) = *(int *)(iVar3 + 0x201da4) + -1;
  *(undefined4 *)(in_ECX + 0x7c) = 0;
LAB_00431a7c:
  if (*(int *)(in_ECX + 0x80) != 0) {
    *(undefined4 *)(*(int *)(in_ECX + 0x80) + 0x38) = 0;
  }
  _ToBeDeleted_MultiMapFixed__UAEXH_Z(param_1);
  return;
}



// ?IsTuggable@BigForest@@UAEIXZ @ 0x00431f80

undefined4 _IsTuggable_BigForest__UAEIXZ(void)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  
  iVar2 = *in_ECX;
  uVar1 = __ftol(0,0);
  (**(code **)(iVar2 + 0xa0))(1,uVar1);
  iVar2 = FUN_006db4f0(in_ECX + 5,&DAT_00cc4b30,in_ECX[0x20],0x3f800000,0,0x3f800000);
  if (iVar2 != 0) {
    FUN_0059c850(iVar2);
  }
  return 0;
}



// ?GetSaveType@BigForest@@UAEIXZ @ 0x004320a0

undefined4 _GetSaveType_BigForest__UAEIXZ(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Load__13MultiMapFixedFR10GameOSFile(param_1);
  if (iVar1 != 0) {
    FUN_00531f30(in_ECX + 0x80);
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x84),4,0,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x84) + 4;
    }
    return 1;
  }
  return 0;
}



