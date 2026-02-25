// Decompiled functions for class: CHand
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?MorphTexture@CHand@@UAEXXZ @ 0x00456eb0

void _MorphTexture_CHand__UAEXXZ(void)

{
  int in_ECX;
  
  _MorphTexture_Morphable__UAEXXZ();
  if (*(int *)(in_ECX + 0x4840) == 0) {
    _Draw_PlannedMultiMapFixed__QAEXXZ();
  }
  return;
}



// ?UpdateTime@CHand@@UAEXH@Z @ 0x00457260

int _UpdateTime_CHand__UAEXH_Z(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 0x47bc);
  if ((iVar2 != 0) && (*(int **)(in_ECX + 0x47c0) != (int *)0x0)) {
    param_1 = param_1 + *(int *)(in_ECX + 0x47d0);
    iVar1 = **(int **)(in_ECX + 0x47c0);
    iVar2 = param_1 / iVar1;
    *(int *)(in_ECX + 0x47d0) = param_1 % iVar1;
  }
  return iVar2;
}



// ?PrepareForDrawing@CHand@@UAEXXZ @ 0x00457340

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _PrepareForDrawing_CHand__UAEXXZ(void)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  float *pfVar9;
  float *pfVar10;
  int in_ECX;
  uint uVar11;
  float unaff_EBP;
  undefined4 *puVar12;
  undefined4 *puVar13;
  float10 fVar14;
  float afStack_18 [2];
  float fStack_10;
  float fStack_c;
  
  if (((*(int *)(DAT_00c22ca4 + 0x201e0c) == 0) && (*(int *)(DAT_00c22ca4 + 0x201e10) == 0)) ||
     (0xff < DAT_00d5c370)) {
    if (DAT_00b7ff20 != '\0') {
      DAT_00b7ff20 = '\0';
      FUN_004570d0(1);
    }
  }
  else if (*(int *)(in_ECX + 0x483c) == 0) {
    DAT_00b7ff20 = '\x01';
    FUN_004571f0(1);
  }
  iVar6 = FUN_00527d00();
  if (*(int *)(DAT_00c22ca4 + 0x201ae4) == 1) {
    iVar6 = DAT_00b5a228;
  }
  *(int *)(in_ECX + 0x4900) = *(int *)(in_ECX + 0x4900) + iVar6;
  fVar2 = (float)iVar6 * 0.001;
  iVar6 = FUN_00527d30();
  FUN_00456e90(*(undefined4 *)(iVar6 + 0x48));
  fVar14 = (float10)FUN_005fa5c0();
  if (fVar14 <= (float10)-1.0) {
    fVar14 = (float10)-1.0;
  }
  else if ((float10)1.0 <= fVar14) {
    fVar14 = (float10)1.0;
  }
  *(float *)(in_ECX + 0x9c) = (float)fVar14;
  FUN_005d1180();
  if (*(int *)(in_ECX + 0x47bc) == 0) {
    piVar1 = (int *)(in_ECX + 0x485c);
    *(undefined4 *)(in_ECX + 0x4864) = *(undefined4 *)(in_ECX + 0x485c);
    *(undefined4 *)(in_ECX + 0x4868) = *(undefined4 *)(in_ECX + 0x4860);
    uVar7 = DAT_00d5c374;
    if (*(char *)(in_ECX + 0x4874) == '\0') {
      *piVar1 = DAT_00d5c370;
      *(undefined4 *)(in_ECX + 0x4860) = uVar7;
    }
    else {
      *piVar1 = *(int *)(in_ECX + 0x486c);
      *(undefined4 *)(in_ECX + 0x4860) = *(undefined4 *)(in_ECX + 0x4870);
    }
    *(uint *)(in_ECX + 0x4858) = (uint)(*(int *)(in_ECX + 0x4864) != *piVar1);
    FUN_006ddf50();
    if ((0.01 < ABS(afStack_18[0])) || (0.01 < ABS(fStack_10))) {
      fVar14 = (float10)FUN_00759180(afStack_18);
      *(float *)(in_ECX + 0x84) = (float)fVar14;
    }
    uVar7 = FUN_00457b00();
    iVar6 = FUN_00457d70(uVar7);
    if (iVar6 != *(int *)(in_ECX + 0x4878)) {
      (**(code **)(**(int **)(in_ECX + 0x487c + *(int *)(in_ECX + 0x4878) * 4) + 8))();
      *(int *)(in_ECX + 0x4878) = iVar6;
      (**(code **)**(undefined4 **)(in_ECX + 0x487c + iVar6 * 4))();
      FUN_004572f0();
    }
    if (((*(int *)(in_ECX + 0x483c) == 0) && (iVar6 != 0)) && (DAT_00b6e5b2 == '\0')) {
      piVar8 = (int *)FUN_00667ed0();
      iVar6 = (**(code **)(*piVar8 + 0x40c))();
      if (iVar6 != 0) {
        if (*(int *)(in_ECX + 0x48b4) == 0) {
          *(undefined4 *)(in_ECX + 0x48c4) = 0;
          *(undefined4 *)(in_ECX + 0x48c0) = 0;
          *(float *)(in_ECX + 0x48b8) = (float)*piVar1;
          *(undefined4 *)(in_ECX + 0x48b4) = 1;
          *(float *)(in_ECX + 0x48bc) = (float)*(int *)(in_ECX + 0x4860);
        }
        else {
          fVar3 = fVar2 * *(float *)(in_ECX + 0x48c0) + *(float *)(in_ECX + 0x48b8);
          *(float *)(in_ECX + 0x48b8) = fVar3;
          fVar5 = (float)*piVar1;
          fVar4 = fVar5 - 80.0;
          if ((fVar5 - 80.0 < fVar3) && (fVar4 = fVar5 + 80.0, fVar3 < fVar5 + 80.0)) {
            fVar4 = fVar3;
          }
          *(float *)(in_ECX + 0x48b8) = fVar4;
          fVar3 = (fVar5 - fVar4) * 20.0 * fVar2 + *(float *)(in_ECX + 0x48c0);
          *(float *)(in_ECX + 0x48c0) = fVar3;
          fVar14 = (float10)FUN_00735800();
          *(float *)(in_ECX + 0x48c0) = (float)(fVar14 * (float10)fVar3);
          fVar3 = fVar2 * *(float *)(in_ECX + 0x48c4) + *(float *)(in_ECX + 0x48bc);
          *(float *)(in_ECX + 0x48bc) = fVar3;
          fVar4 = (float)*(int *)(in_ECX + 0x4860) - 80.0;
          if ((fVar4 < fVar3) && (fVar4 = (float)*(int *)(in_ECX + 0x4860) + 80.0, fVar3 < fVar4)) {
            fVar4 = fVar3;
          }
          *(float *)(in_ECX + 0x48bc) = fVar4;
          fVar3 = ((float)*(int *)(in_ECX + 0x4860) - fVar4) * 20.0 * fVar2 +
                  *(float *)(in_ECX + 0x48c4);
          *(float *)(in_ECX + 0x48c4) = fVar3;
          fVar14 = (float10)FUN_00735800();
          *(float *)(in_ECX + 0x48c4) = (float)(fVar14 * (float10)fVar3);
        }
        (**(code **)(**(int **)(in_ECX + 0x487c + *(int *)(in_ECX + 0x4878) * 4) + 0xc))
                  (fVar2,*(undefined4 *)(in_ECX + 0x47f0));
        if (*(char *)(in_ECX + 0x4874) != '\0') {
          *(undefined1 *)(in_ECX + 0x4874) = 0;
        }
        if (0.13 <= *(float *)(in_ECX + 0x49b0)) {
          _DAT_00b7fee8 = DAT_00b7ff08;
          _DAT_00b7feec = DAT_00b7ff0c;
          _DAT_00b7fef0 = DAT_00b7ff10;
        }
        else {
          fVar2 = unaff_EBP + *(float *)(in_ECX + 0x49b0);
          *(float *)(in_ECX + 0x49b0) = fVar2;
          if (fVar2 < 0.13) {
            fVar2 = fVar2 / 0.13;
            uVar11 = (uint)(*(int *)(in_ECX + 0x47b8) * 0x30) >> 2;
            if (uVar11 != 0) {
              iVar6 = *(int *)(in_ECX + 0x49ac) - (int)*(float **)(in_ECX + 0x47f0);
              pfVar9 = *(float **)(in_ECX + 0x47f0);
              do {
                pfVar10 = pfVar9 + 1;
                uVar11 = uVar11 - 1;
                *pfVar9 = (*pfVar9 - *(float *)(iVar6 + -4 + (int)pfVar10)) * fVar2 +
                          *(float *)(iVar6 + -4 + (int)pfVar10);
                pfVar9 = pfVar10;
              } while (uVar11 != 0);
            }
            fStack_10 = (DAT_00b7ff0c - _DAT_00b7fefc) * fVar2;
            fStack_c = (DAT_00b7ff10 - _DAT_00b7ff00) * fVar2;
            _DAT_00b7fee8 = (DAT_00b7ff08 - _DAT_00b7fef8) * fVar2 + _DAT_00b7fef8;
            _DAT_00b7feec = fStack_10 + _DAT_00b7fefc;
            _DAT_00b7fef0 = fStack_c + _DAT_00b7ff00;
            if ((*(int *)(in_ECX + 0x4878) == 4) &&
               ((DAT_00c685cc == 0 || (*(int *)(in_ECX + 0x4904) != DAT_00c685d0)))) {
              iVar6 = *(int *)(*(int *)(in_ECX + 0x4904) + 0x40);
              fVar2 = DAT_00c35054 + _DAT_00b7feec;
              fVar3 = DAT_00c35058 + _DAT_00b7fef0;
              *(float *)(iVar6 + 0x38) = _DAT_00b7fee8 + DAT_00c35050;
              *(float *)(iVar6 + 0x3c) = fVar2;
              *(float *)(iVar6 + 0x40) = fVar3;
            }
          }
        }
        (**(code **)(**(int **)(in_ECX + 0x482c) + 0xf4))(0,0);
        puVar12 = *(undefined4 **)(in_ECX + 0x47f0);
        puVar13 = (undefined4 *)(*(int *)(in_ECX + 0x482c) + 0x14);
        for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar13 = *puVar12;
          puVar12 = puVar12 + 1;
          puVar13 = puVar13 + 1;
        }
        *(undefined4 *)(*(int *)(in_ECX + 0x482c) + 0x44) = *(undefined4 *)(in_ECX + 0x94);
        *(undefined4 *)(*(int *)(in_ECX + 0x482c) + 0x80) = *(undefined4 *)(in_ECX + 0x47f0);
        PTR_DAT_00b59edc = *(undefined **)(in_ECX + 0x47f0);
        *(undefined4 *)(*(int *)(in_ECX + 0x482c) + 0xbc) = 1;
        FUN_00770780();
        PTR_DAT_00b59edc = (undefined *)&DAT_00d73c58;
        if (*(int *)(in_ECX + 0x49a0) != 0) {
          FUN_004588c0();
        }
      }
    }
    return;
  }
  FUN_00458530();
  return;
}



// ?AddForDrawing@CHand@@UAE_NXZ @ 0x00457ee0

undefined4 _AddForDrawing_CHand__UAE_NXZ(void)

{
  FUN_00457ef0();
  return 1;
}



