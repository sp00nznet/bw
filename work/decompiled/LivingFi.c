// Decompiled functions for class: LivingFi
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// _ToBeDeleted__6LivingFi @ 0x005aacc0

void _ToBeDeleted__6LivingFi(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  int *piVar3;
  
  (**(code **)(*in_ECX + 0x34))();
  if (in_ECX[0x25] != 0) {
    (**(code **)(*in_ECX + 0x994))();
  }
  iVar2 = DAT_00c22ca4;
  piVar3 = (int *)(DAT_00c22ca4 + 0x201c78);
  for (piVar1 = (int *)*piVar3; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[0x29]) {
    if (piVar1 == in_ECX) {
      if (piVar1 != (int *)0x0) {
        piVar1 = (int *)*piVar3;
        if ((int *)*piVar3 != in_ECX) goto joined_r0x005aad17;
        *piVar3 = in_ECX[0x29];
        goto LAB_005aad37;
      }
      break;
    }
  }
  goto LAB_005aad40;
  while (piVar1 = (int *)piVar3[0x29], (int *)piVar3[0x29] != in_ECX) {
joined_r0x005aad17:
    piVar3 = piVar1;
    if (piVar3 == (int *)0x0) goto LAB_005aad40;
  }
  piVar3[0x29] = in_ECX[0x29];
LAB_005aad37:
  *(int *)(iVar2 + 0x201c7c) = *(int *)(iVar2 + 0x201c7c) + -1;
  in_ECX[0x29] = 0;
LAB_005aad40:
  if ((int *)in_ECX[0x2b] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x2b] + 0xc))(0);
    in_ECX[0x2b] = 0;
  }
  if ((int *)in_ECX[0x2c] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x2c] + 0xc))(0);
    in_ECX[0x2c] = 0;
  }
  iVar2 = (**(code **)(*in_ECX + 0x974))();
  if (iVar2 != 0) {
    (**(code **)(*in_ECX + 0xb04))(1);
  }
  if (in_ECX[0x2e] != 0) {
    FUN_00505c20(in_ECX,1);
    FUN_005acec0(0);
  }
  _ToBeDeleted_Object__UAEXH_Z(param_1);
  piVar3 = (int *)in_ECX[0x26];
  if (piVar3 == (int *)0x0) {
    in_ECX[0x26] = 0;
    return;
  }
  do {
    piVar1 = (int *)*piVar3;
    FUN_007290de(piVar3[1]);
    FUN_007290de(piVar3);
    piVar3 = piVar1;
  } while (piVar1 != (int *)0x0);
  in_ECX[0x26] = 0;
  return;
}



