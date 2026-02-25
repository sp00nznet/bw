// Decompiled functions for class: LH3DCreatureFPc
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// _LoadBase__12LH3DCreatureFPc @ 0x004cb830

undefined4 _LoadBase__12LH3DCreatureFPc(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = _LoadBase_Morphable__UAEIPAD_Z(param_1);
  if (iVar1 == 0) {
    return 0;
  }
  if (*(int *)(in_ECX + 0x5174) != 0) {
    FUN_007290de(*(int *)(in_ECX + 0x5174));
  }
  uVar2 = FUN_00746d70(*(int *)(in_ECX + 0x47b8) * 0x30,s_C__dev_black_CreatureMorph_cpp_00b0e174,
                       0x29);
  *(undefined4 *)(in_ECX + 0x5174) = uVar2;
  if (*(int *)(in_ECX + 0x5178) != 0) {
    FUN_007290de(*(int *)(in_ECX + 0x5178));
  }
  uVar2 = FUN_00746d70(*(int *)(in_ECX + 0x47b8) * 0x30,s_C__dev_black_CreatureMorph_cpp_00b0e174,
                       0x2b);
  *(undefined4 *)(in_ECX + 0x5178) = uVar2;
  if (*(int *)(in_ECX + 0x517c) != 0) {
    FUN_007290de(*(int *)(in_ECX + 0x517c));
  }
  uVar2 = FUN_00746d70(*(int *)(in_ECX + 0x47b8) * 0x30,s_C__dev_black_CreatureMorph_cpp_00b0e174,
                       0x2d);
  *(undefined4 *)(in_ECX + 0x517c) = uVar2;
  if (*(int *)(in_ECX + 0x5180) != 0) {
    FUN_007290de(*(int *)(in_ECX + 0x5180));
  }
  uVar2 = FUN_00746d70(*(int *)(in_ECX + 0x47b8) * 0x30,s_C__dev_black_CreatureMorph_cpp_00b0e174,
                       0x2f);
  *(undefined4 *)(in_ECX + 0x5180) = uVar2;
  if (*(int *)(in_ECX + 0x51f0) == 0) {
    uVar2 = FUN_00746d70(*(int *)(in_ECX + 0x47b8) << 2,s_C__dev_black_CreatureMorph_cpp_00b0e174,
                         0x32);
    *(undefined4 *)(in_ECX + 0x51f0) = uVar2;
    iVar1 = 0;
    if (0 < *(int *)(in_ECX + 0x47b8)) {
      do {
        *(undefined4 *)(*(int *)(in_ECX + 0x51f0) + iVar1 * 4) = 0xffffffff;
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(in_ECX + 0x47b8));
    }
  }
  return 1;
}



