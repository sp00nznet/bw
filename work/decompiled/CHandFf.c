// Decompiled functions for class: CHandFf
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// _SetSize__5CHandFf @ 0x00457290

void _SetSize__5CHandFf(float param_1)

{
  int in_ECX;
  float10 fVar1;
  
  if (param_1 <= 0.05) {
    param_1 = 0.05;
  }
  else if (2.0 <= param_1) {
    param_1 = 2.0;
  }
  *(float *)(in_ECX + 0x90) = param_1;
  fVar1 = (float10)FUN_00456f60();
  *(float *)(in_ECX + 0x94) =
       (float)((fVar1 / (float10)*(float *)(in_ECX + 0x8c)) * (float10)*(float *)(in_ECX + 0x4834) *
              (float10)*(float *)(in_ECX + 0x90));
  return;
}



