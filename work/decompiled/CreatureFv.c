// Decompiled functions for class: CreatureFv
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// _ProcessState__8CreatureFv @ 0x0045d8a0

undefined4 _ProcessState__8CreatureFv(void)

{
  byte bVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int *in_ECX;
  int *piVar7;
  uint uVar8;
  float10 fVar9;
  float fStack_244;
  int *piStack_240;
  undefined4 uStack_23c;
  float fStack_234;
  undefined **ppuStack_230;
  undefined4 uStack_22c;
  undefined4 uStack_228;
  undefined4 uStack_224;
  undefined4 uStack_220;
  undefined4 uStack_21c;
  undefined4 uStack_218;
  undefined4 uStack_214;
  undefined4 uStack_210;
  undefined4 uStack_20c;
  undefined4 uStack_208;
  undefined4 uStack_204;
  undefined1 auStack_200 [256];
  undefined1 auStack_100 [256];
  
  iVar3 = (**(code **)(*in_ECX + 0x1c))();
  if (iVar3 != 0) {
    iVar6 = *(int *)(iVar3 + 0x25c);
    if (*(float *)(iVar6 + 0x1078) == 0.0) {
      fVar9 = (float10)FUN_004670d0();
      *(float *)(iVar6 + 0x1078) = (float)fVar9;
    }
    if ((*(int *)(iVar3 + 0x260) != 0) &&
       (iVar3 = *(int *)(*(int *)(iVar3 + 0x260) + 0x30), iVar3 != 0)) {
      (**(code **)(**(int **)(iVar3 + 0x40) + 0x1cc))(&piStack_240);
      iVar3 = __ftol();
      in_ECX[0x480] = iVar3;
      iVar3 = __ftol();
      in_ECX[0x481] = iVar3;
      in_ECX[0x482] = 0;
    }
  }
  piStack_240 = *(int **)(in_ECX[0x58] + 0x58);
  FUN_004d46e0();
  FUN_004d81b0();
  _Draw_PlannedMultiMapFixed__QAEXXZ();
  FUN_004aeae0();
  iVar3 = (**(code **)(*in_ECX + 0x1c))();
  if (((iVar3 != 0) && (iVar3 = (**(code **)(*in_ECX + 0x1c))(), *(int *)(iVar3 + 0x15c) != 0)) &&
     (iVar3 = (**(code **)(*in_ECX + 0x1c))(), *(int *)(*(int *)(iVar3 + 0x15c) + 0x1b8) != 0)) {
    in_ECX[0x417] = 0;
  }
  FUN_004619d0();
  iVar3 = FUN_0046d620();
  if (((iVar3 != 0) && (iVar3 = *(int *)(in_ECX[0x59] + 0xf60), iVar3 != 9)) &&
     ((iVar3 != 0x105 && (iVar3 != 0xd9)))) {
    FUN_004619d0();
    FUN_0046d630();
  }
  iVar3 = *(int *)(in_ECX[0x58] + 0x28);
  if (iVar3 != 0) {
    *(int *)(iVar3 + 0x14) = in_ECX[5];
    *(int *)(iVar3 + 0x18) = in_ECX[6];
    *(int *)(iVar3 + 0x1c) = in_ECX[7];
  }
  FUN_004ba9b0();
  FUN_004d0040();
  if ((*(byte *)(in_ECX + 9) & 0x10) == 0) {
    FUN_00467790();
    *(int *)(in_ECX[0x58] + 0x70) = *(int *)(in_ECX[0x58] + 0x70) + 1;
    FUN_004b2040();
    iVar3 = FUN_004b29d0();
    if (iVar3 == 0) {
      if (((in_ECX[0x49a] < 5) && (iVar6 = (**(code **)(*in_ECX + 0x1c))(), iVar6 != 0)) &&
         ((iVar6 = (**(code **)(*in_ECX + 0x1c))(), *(int *)(iVar6 + 0xf8) != 2 &&
          (((iVar6 = FUN_005256a0(), iVar6 == 0 &&
            (bVar1 = *(byte *)(DAT_00c22ca4 + 0x201b15), iVar6 = DAT_00c22ca4 + 0x18,
            iVar4 = (**(code **)(*in_ECX + 0x1c))(), iVar4 == iVar6 + (uint)bVar1 * 0x278)) &&
           (*(int *)(DAT_00c22ca4 + 0x201ac4) == 1)))))) {
        in_ECX[0x46a] = in_ECX[0x480];
        in_ECX[0x46b] = in_ECX[0x481];
        in_ECX[0x46c] = in_ECX[0x482];
        in_ECX[0x46d] = 0x41200000;
      }
    }
    else {
      in_ECX[0x43a] = 0;
    }
    if ((((in_ECX[0x4a5] == 0) && (iVar6 = FUN_00466830(), iVar6 != 0)) &&
        ((in_ECX[0xe0] != 2 &&
         ((*(int *)(in_ECX[0x59] + 0x1c10) == 0 && (*(int *)(in_ECX[0x59] + 0x1c38) == 0)))))) &&
       ((*(byte *)((int)in_ECX + 0x25) & 4) == 0)) {
      piVar7 = in_ECX + 0x46a;
      iVar6 = FUN_005c04c0();
      if (iVar6 != 0) {
        fVar9 = (float10)FUN_006de0a0(in_ECX + 5,piVar7);
        fStack_244 = (float)fVar9;
        if ((float10)(float)in_ECX[0x46d] < fVar9) {
          if (in_ECX[0x46e] != 0) {
            fStack_234 = (float)in_ECX[0x46d] * 0.5;
            if (fStack_234 < 5.0) {
              fStack_234 = 5.0;
            }
            fVar9 = (float10)FUN_006de0a0(in_ECX[0x59] + 0x1c78,piVar7);
            if (fVar9 <= (float10)fStack_234) goto LAB_0045dcb5;
          }
          if ((&DAT_00c76750)
              [(uint)*(ushort *)((int)in_ECX + 0x11aa) +
               (uint)*(ushort *)((int)in_ECX + 0x11ae) * 0x200] == '\0') {
            if ((iVar3 != 0) && (*(int *)(*(int *)(iVar3 + 300) + 0x24) != 0)) {
              *(undefined4 *)(in_ECX[0x59] + 0x1cea0 + *(int *)(in_ECX[0x59] + 0xf60) * 4) = 0;
            }
            fVar2 = (float)in_ECX[0x46d] + (float)in_ECX[0x46d];
            if (0.0 <= fStack_244) {
              if (fVar2 < fStack_244) {
                fStack_244 = fVar2;
              }
            }
            else {
              fStack_244 = 0.0;
            }
            FUN_004683d0((fStack_244 * 0.8) / fVar2 + *(float *)(in_ECX[10] + 0x254));
            FUN_004778c0();
            FUN_004ae0e0(piVar7);
            in_ECX[0x46e] = 1;
            iVar3 = FUN_004b29d0();
            if (iVar3 != 0) {
              in_ECX[0xe0] = 1;
            }
          }
        }
      }
    }
LAB_0045dcb5:
    if (*(int *)(in_ECX[0x59] + 0x700) != 0x28) {
      FUN_004be450(*(int *)(in_ECX[0x59] + 0x700));
      *(int *)(in_ECX[0x59] + 0x704) = *(int *)(in_ECX[0x59] + 0x704) + 1;
      if (*(uint *)(in_ECX[0x59] + 0x708) <
          (uint)((ulonglong)*(uint *)(in_ECX[0x59] + 0x704) / (1000 / ZEXT48(DAT_00c22d78)))) {
        FUN_004be470();
        *(undefined4 *)(in_ECX[0x59] + 0x700) = 0x28;
      }
    }
    if (DAT_00c22130 != 0) {
      FUN_004612a0();
      if (in_ECX[0x417] != 0) {
        _Draw_PlannedMultiMapFixed__QAEXXZ();
      }
      if ((DAT_00c22128 == 0) || (in_ECX[0x49a] < 1)) {
        uVar8 = 0x148;
        piVar7 = &DAT_00b89754;
        do {
          if (*piVar7 != 0) {
            *(undefined4 *)(uVar8 + in_ECX[0x59] + 8) = 0;
          }
          uVar8 = uVar8 + 4;
          piVar7 = piVar7 + 0x70;
        } while (uVar8 < 0x1e8);
      }
      else {
        FUN_004cf980(in_ECX[10]);
      }
      FUN_004c13c0(in_ECX + 5,in_ECX);
      FUN_004ba890();
      FUN_00461a00();
    }
    if ((DAT_00c22120 != 0) && (*(int *)(in_ECX[0x59] + 0x20cec) != 0)) {
      FUN_004b3f10();
    }
    iVar3 = in_ECX[0x59];
    iVar6 = FUN_004d13b0();
    if ((((iVar6 != 0) && (*(uint *)(iVar3 + 0xfbc) != 0)) &&
        (*(uint *)(iVar3 + 0xfb4) < *(uint *)(iVar3 + 0xfbc))) &&
       ((*(int *)(iVar3 + 0xfb8) < 3 && (*(int *)(in_ECX[0x59] + 0x1c28) != 0)))) {
      *(undefined4 *)(in_ECX[0x59] + 0x1c28) = 0;
      iVar3 = in_ECX[0x59];
      uStack_22c = *(undefined4 *)(iVar3 + 0xf4c);
      uStack_228 = *(undefined4 *)(iVar3 + 0xf50);
      uStack_224 = *(undefined4 *)(iVar3 + 0xf54);
      uStack_220 = *(undefined4 *)(iVar3 + 0xf58);
      uStack_21c = *(undefined4 *)(iVar3 + 0xf5c);
      uStack_218 = *(undefined4 *)(iVar3 + 0xf60);
      uStack_214 = *(undefined4 *)(iVar3 + 0xf64);
      uStack_210 = *(undefined4 *)(iVar3 + 0xf68);
      uStack_20c = *(undefined4 *)(iVar3 + 0xf6c);
      uStack_208 = *(undefined4 *)(iVar3 + 0xf70);
      uStack_204 = *(undefined4 *)(iVar3 + 0xf74);
      ppuStack_230 = &vftable_CreaturePlan;
      FUN_0045fa70(s_starting_again_008fe044,1,1);
      iVar3 = in_ECX[0x59];
      *(undefined4 *)(iVar3 + 0xf4c) = uStack_22c;
      *(undefined4 *)(iVar3 + 0xf50) = uStack_228;
      *(undefined4 *)(iVar3 + 0xf54) = uStack_224;
      *(undefined4 *)(iVar3 + 0xf58) = uStack_220;
      *(undefined4 *)(iVar3 + 0xf5c) = uStack_21c;
      *(undefined4 *)(iVar3 + 0xf60) = uStack_218;
      *(undefined4 *)(iVar3 + 0xf64) = uStack_214;
      *(undefined4 *)(iVar3 + 0xf68) = uStack_210;
      *(undefined4 *)(iVar3 + 0xf6c) = uStack_20c;
      *(undefined4 *)(iVar3 + 0xf70) = uStack_208;
      *(undefined4 *)(iVar3 + 0xf74) = uStack_204;
      FUN_004b6ca0(*(undefined4 *)(in_ECX[0x59] + 0xf60));
      FUN_004d13a0();
    }
    iVar3 = in_ECX[0x59];
    iVar6 = FUN_004d13b0();
    if (((iVar6 != 0) && (*(uint *)(iVar3 + 0xfbc) != 0)) &&
       ((*(uint *)(iVar3 + 0xfb4) < *(uint *)(iVar3 + 0xfbc) &&
        ((*(int *)(iVar3 + 0xfb8) < 3 && (*(int *)(in_ECX[0x59] + 0xf50) != 0x21)))))) {
      in_ECX[0x446] = 1;
    }
    iVar3 = (**(code **)(*in_ECX + 0x1c))();
    if (((iVar3 != 0) && (iVar3 = (**(code **)(*in_ECX + 0x1c))(), *(int *)(iVar3 + 0xf8) != 2)) &&
       ((*(byte *)((int)in_ECX + 0x25) & 4) == 0)) {
      FUN_004669d0();
      FUN_00466a50();
    }
    FUN_00466b00();
    FUN_004b3bc0();
    if (in_ECX[0x43a] != 0) {
      in_ECX[0x43a] = in_ECX[0x43a] + -1;
    }
    if (((DAT_00c22124 == 0) || (*(int *)(in_ECX[0x59] + 0x20ce4) == 0)) ||
       (((*(byte *)((int)in_ECX + 0x25) & 4) != 0 || (*(int *)(in_ECX[0x59] + 0x20d30) != 0)))) {
      if (*(int *)(in_ECX[0x59] + 0x20ce4) != 0) goto LAB_0045e1ce;
    }
    else {
      uVar8 = 0;
      if ((int)(0x3d8 / (1000 / ZEXT48(DAT_00c22d78))) != 0) {
        do {
          FUN_004ab850();
          uVar8 = uVar8 + 1;
        } while (uVar8 < (uint)(0x3d8 / (1000 / ZEXT48(DAT_00c22d78))));
      }
      FUN_004b0dc0();
      iVar3 = (**(code **)(*in_ECX + 0x1c))();
      if (iVar3 != 0) {
        FUN_004b0420();
      }
      FUN_004abfb0();
      FUN_004be5b0(in_ECX);
      _Draw_PlannedMultiMapFixed__QAEXXZ();
      if (in_ECX[0x433] != 0) {
        FUN_004619d0();
        iVar3 = FUN_0046cb80();
        if (iVar3 != 0) {
          FUN_004be9a0(0x17,in_ECX[10],0x3fc00000);
        }
      }
      if (in_ECX[0x43a] == 0) {
        FUN_004d0440();
      }
      if (((*(int *)(*(int *)(DAT_00c22ca4 + 0x24c118) + 0x45e8) != 0) &&
          (*(int *)(*(int *)(DAT_00c22ca4 + 0x24c118) + 0x45ec) != 0)) &&
         (*(int *)(in_ECX[0x59] + 0xf60) != 0x13a)) {
        uVar5 = FUN_004ba1b0(in_ECX);
        FUN_004d1300(0x18,0x13a,0,uVar5,0,0x3f800000);
        FUN_004aba10(&ppuStack_230,1,1);
        *(undefined4 *)(in_ECX[0x59] + 0x1c14) = 1;
        FUN_004d13a0();
      }
      iVar3 = in_ECX[0x59];
      iVar6 = FUN_004d13b0();
      if ((((iVar6 == 0) || (*(uint *)(iVar3 + 0xfbc) == 0)) ||
          (*(uint *)(iVar3 + 0xfbc) <= *(uint *)(iVar3 + 0xfb4))) || (2 < *(int *)(iVar3 + 0xfb8)))
      {
        *(undefined4 *)(in_ECX[0x59] + 0xf74) = 0;
        *(int *)(in_ECX[0x59] + 0x21fc) = *(int *)(in_ECX[0x59] + 0x21fc) + 1;
        in_ECX[0xe1] = 0;
        in_ECX[0xe0] = 0;
      }
      else {
        if (DAT_00bf4fb8 != 0) {
          FUN_004622b0();
        }
        FUN_004b6df0();
LAB_0045e1ce:
        FUN_004de180();
      }
    }
    if (DAT_00c2212c == 0) goto LAB_0045e35c;
    FUN_004cffa0(in_ECX[10]);
    FUN_00461380();
  }
  else {
    *(undefined4 *)(in_ECX[0x59] + 0x1c28) = 1;
    if (in_ECX[0xf3] == 1) {
      FUN_00461cd0();
    }
    else if (in_ECX[0xf3] == 2) {
      _GetTown_GameThing__QAEPAVTown__XZ();
    }
  }
  piVar7 = piStack_240;
  if ((DAT_00c2212c == 0) || (*(int *)(in_ECX[0x59] + 0x20ce8) == 0)) goto LAB_0045e35c;
  iVar3 = piStack_240[0x120b];
  *(int *)(iVar3 + 0xa0) = in_ECX[0x4a7];
  if ((float)in_ECX[0x4a7] != 0.0) {
    uVar5 = FUN_00547f10();
    *(undefined4 *)(iVar3 + 0x9c) = uVar5;
  }
  if ((float)in_ECX[0x4a9] != 0.0) {
    piStack_240 = DAT_00c22d78;
    uStack_23c = 0;
    fVar2 = (float)DAT_00c22d78 * (float)in_ECX[0x4a9] * 0.001 + (float)in_ECX[0x4a7];
    in_ECX[0x4a7] = (int)fVar2;
    if ((float)in_ECX[0x4a9] <= 0.0) {
      if (fVar2 < (float)in_ECX[0x4a8]) {
        in_ECX[0x4a7] = in_ECX[0x4a8];
        goto LAB_0045e2c9;
      }
    }
    else if ((float)in_ECX[0x4a8] < fVar2) {
      in_ECX[0x4a7] = in_ECX[0x4a8];
LAB_0045e2c9:
      in_ECX[0x4a9] = 0;
    }
    if ((in_ECX[0x4a7] == 0x3f800000) && ((char)in_ECX[0x4a6] != '\0')) {
      (**(code **)(*in_ECX + 0xc))(0);
      return 3;
    }
  }
  if ((float)in_ECX[0x4aa] != 0.0) {
    uVar5 = FUN_00547ed0(0);
    *(undefined4 *)(iVar3 + 0x90) = uVar5;
    *(undefined4 *)(iVar3 + 0x98) = 0x354f8d;
  }
  uStack_23c = 0;
  *(int *)(iVar3 + 0x94) = in_ECX[0x4aa];
  iVar3 = *piVar7;
  piStack_240 = DAT_00c22d78;
  uVar5 = __ftol();
  (**(code **)(iVar3 + 0x14))(uVar5);
LAB_0045e35c:
  FUN_00412140(in_ECX);
  if (DAT_00b859c8 == in_ECX) {
    FUN_00460350();
  }
  if (((*(uint *)(in_ECX[0x58] + 0x70) != 0) && (*(uint *)(in_ECX[0x58] + 0x70) % 600 == 0)) &&
     (bVar1 = *(byte *)(DAT_00c22ca4 + 0x201b15), iVar3 = DAT_00c22ca4 + 0x18,
     iVar6 = (**(code **)(*in_ECX + 0x1c))(), iVar6 == iVar3 + (uint)bVar1 * 0x278)) {
    (**(code **)(*in_ECX + 0x1c))();
    iVar3 = FUN_005f7f80();
    iVar6 = FUN_00527d60();
    if (iVar3 == iVar6) {
      (**(code **)(*in_ECX + 0x1c))();
      FUN_005f7f80();
      iVar3 = FUN_00667ed0();
      if ((*(int *)(*(int *)(iVar3 + 0x1bc) + 0x1fc) == 0) && (in_ECX[0x416] == 0)) {
        (**(code **)(*in_ECX + 0x1c))();
        FUN_005f7f80();
        FUN_00667ed0();
        FUN_005f7f80();
        iVar3 = FUN_00667ed0();
        FUN_00733e17(auStack_200,s___Scripts_CreatureMind__s_008fe028,*(int *)(iVar3 + 0x1bc) + 4);
        FUN_004c89e0(auStack_200);
        FUN_005f7f80();
        iVar3 = FUN_00667ed0();
        FUN_00733e17(auStack_100,s___Scripts_CreatureMind_Physique__008fe004,
                     *(int *)(iVar3 + 0x1bc) + 4);
        FUN_004c8280(auStack_100);
        FUN_004652a0();
      }
    }
  }
  FUN_004658d0();
  iVar3 = FUN_00464dc0();
  if (iVar3 != 0) {
    iVar3 = FUN_004619d0();
    *(float *)(iVar3 + 0x4aac) = *(float *)(iVar3 + 0x4aac) + 0.0016666;
    iVar3 = FUN_004619d0();
    if (0.0 <= *(float *)(iVar3 + 0x4aac)) {
      iVar3 = FUN_004619d0();
      if (1.0 < *(float *)(iVar3 + 0x4aac)) {
        iVar3 = FUN_004619d0();
        *(undefined4 *)(iVar3 + 0x4aac) = 0x3f800000;
      }
    }
    else {
      iVar3 = FUN_004619d0();
      *(undefined4 *)(iVar3 + 0x4aac) = 0;
    }
  }
  piStack_240 = (int *)FUN_00461920();
  in_ECX[0x49c] = (int)((float)in_ECX[0x49c] * 0.9 + (float)(int)piStack_240 * 0.1);
  FUN_00412060(in_ECX);
  if (DAT_00c22130 != 0) {
    FUN_00462030();
  }
  return 1;
}



