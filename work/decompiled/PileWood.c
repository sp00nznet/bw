// Decompiled functions for class: PileWood
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Draw@PileWood@@UAEXXZ @ 0x004f8010

void _Draw_PileWood__UAEXXZ(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  float fVar4;
  int *in_ECX;
  float10 fVar5;
  
  fVar2 = (float)DAT_00dc8d20 * 0.001 + (float)in_ECX[0x26];
  in_ECX[0x26] = (int)fVar2;
  if (fVar2 < (float)in_ECX[0x27]) {
    fVar1 = fVar2 * fVar2 * 0.5;
    fVar4 = fVar2 * fVar1 * 0.33333334;
    in_ECX[0x24] = (int)(fVar2 * (float)in_ECX[0x2a] +
                         fVar4 * (float)in_ECX[0x2c] + fVar1 * (float)in_ECX[0x2b] +
                        (float)in_ECX[0x29]);
    in_ECX[0x21] = (int)((float)in_ECX[0x29] * (float)in_ECX[0x26] +
                         fVar1 * (float)in_ECX[0x2a] +
                         fVar4 * (float)in_ECX[0x2b] +
                         fVar1 * fVar1 * 0.16666667 * (float)in_ECX[0x2c] + (float)in_ECX[0x28]);
  }
  else {
    in_ECX[0x21] = in_ECX[0x22];
    in_ECX[0x24] = in_ECX[0x23];
    in_ECX[0x25] = 0;
    in_ECX[0x26] = in_ECX[0x27];
  }
  fVar2 = (float)in_ECX[0x21];
  fVar5 = (float10)(**(code **)(*in_ECX + 0x42c))();
  if (-fVar5 < (float10)fVar2) {
    fVar5 = (float10)(**(code **)(*in_ECX + 0x120))();
    fVar2 = (float)fVar5;
    fVar5 = (float10)(**(code **)(*in_ECX + 0x508))();
    fVar1 = (float)fVar5;
    iVar3 = in_ECX[0x10];
    FUN_00760fd0();
    if (fVar1 == 0.0) {
      if (fVar2 == 1.0) {
        FUN_004022b0();
      }
      else {
        FUN_004f5940(fVar2);
        FUN_004022f0();
      }
    }
    else if (fVar2 == 1.0) {
      FUN_004022b0();
      FUN_004f5f10(fVar1);
    }
    else {
      *(undefined4 *)(iVar3 + 0x40) = 0;
      *(undefined4 *)(iVar3 + 0x3c) = 0;
      *(undefined4 *)(iVar3 + 0x38) = 0;
      *(undefined4 *)(iVar3 + 0x30) = 0;
      *(undefined4 *)(iVar3 + 0x2c) = 0;
      *(undefined4 *)(iVar3 + 0x28) = 0;
      *(undefined4 *)(iVar3 + 0x20) = 0;
      *(undefined4 *)(iVar3 + 0x1c) = 0;
      *(undefined4 *)(iVar3 + 0x18) = 0;
      *(float *)(iVar3 + 0x34) = fVar2;
      *(float *)(iVar3 + 0x14) = fVar2;
      *(float *)(iVar3 + 0x24) = fVar2;
      FUN_004022f0();
      FUN_004f5f10(fVar1);
    }
    *(float *)(iVar3 + 0x44) = fVar2;
    *(float *)(iVar3 + 0x48) = fVar1;
    _Draw_MobileObject__UAEXXZ();
    fVar5 = (float10)(**(code **)(*in_ECX + 0x120))();
    fVar2 = (float)fVar5;
    fVar5 = (float10)(**(code **)(*in_ECX + 0x508))();
    fVar1 = (float)fVar5;
    iVar3 = in_ECX[0x10];
    FUN_00760fd0();
    if (fVar1 == 0.0) {
      if (fVar2 == 1.0) {
        FUN_004022b0();
      }
      else {
        FUN_004f5940(fVar2);
        FUN_004022f0();
      }
    }
    else if (fVar2 == 1.0) {
      FUN_004022b0();
      FUN_004f5f10(fVar1);
    }
    else {
      FUN_004f5940(fVar2);
      FUN_004022f0();
      FUN_004f5f10(fVar1);
    }
    *(float *)(iVar3 + 0x44) = fVar2;
    *(float *)(iVar3 + 0x48) = fVar1;
  }
  return;
}



// ?GetSaveType@PileWood@@UAEIXZ @ 0x0052ea50

undefined4 _GetSaveType_PileWood__UAEIXZ(void)

{
  return 0x5a;
}



// ?GetDebugText@PileWood@@UAEPADXZ @ 0x0052ea60

char * _GetDebugText_PileWood__UAEPADXZ(void)

{
  return s_PileWood__00b1a394;
}



