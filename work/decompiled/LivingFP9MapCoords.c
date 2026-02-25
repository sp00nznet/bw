// Decompiled functions for class: LivingFP9MapCoords
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// _GetFinalDestPos__6LivingFP9MapCoords @ 0x005aadf0

void _GetFinalDestPos__6LivingFP9MapCoords(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *in_ECX;
  
  if (((in_ECX[0x32] != 0) && (in_ECX[0x33] != 0)) &&
     (iVar1 = FUN_0050a310(param_1,(*(byte *)(in_ECX + 0x2d) & 8) >> 3), iVar1 != 0)) {
    return;
  }
  puVar2 = (undefined4 *)(**(code **)(*in_ECX + 0x860))();
  *param_1 = *puVar2;
  param_1[1] = puVar2[1];
  param_1[2] = puVar2[2];
  return;
}



