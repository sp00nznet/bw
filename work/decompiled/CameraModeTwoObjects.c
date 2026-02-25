// Decompiled functions for class: CameraModeTwoObjects
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?CanPlayerGestureWhenCameraMoving@CameraModeTwoObjects@@UAE_NXZ @ 0x0043e700

void _CanPlayerGestureWhenCameraMoving_CameraModeTwoObjects__UAE_NXZ(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &vftable_CameraMode;
  if ((param_1 & 1) != 0) {
    FUN_007290de();
  }
  return;
}



// ?Restart@CameraModeTwoObjects@@UAEXXZ @ 0x0043e7e0

void _Restart_CameraModeTwoObjects__UAEXXZ(void)

{
  float fVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int in_ECX;
  float10 fVar8;
  float10 fVar9;
  
  iVar2 = *(int *)(in_ECX + 0xc);
  fVar1 = *(float *)(iVar2 + 0x78);
  fVar3 = *(float *)(iVar2 + 0x80);
  fVar4 = *(float *)(iVar2 + 0x90) * 7.5 + *(float *)(iVar2 + 0x7c);
  fVar5 = 15.0 - *(float *)(iVar2 + 0x90) * 10.5;
  fVar6 = (*(float *)(iVar2 + 0x90) * 22.5) / SQRT(fVar5 * fVar5 + 900.0);
  fVar7 = fVar6 * -30.0;
  fVar8 = (float10)fcos((float10)*(float *)(iVar2 + 0x5240));
  fVar9 = (float10)fsin((float10)*(float *)(iVar2 + 0x5240));
  FUN_00406240(fVar1,0,0x3f333333);
  FUN_00406240(fVar4,0,0x3f333333);
  FUN_00406240(fVar3,0,0x3f333333);
  FUN_00406240((float)((float10)(float)fVar8 * (float10)0.0 + -fVar9 * (float10)fVar7) + fVar1,0,
               0x3f333333);
  FUN_00406240(fVar5 * fVar6 + fVar4,0,0x3f333333);
  FUN_00406240(fVar3 + (float)fVar9 * 0.0 + (float)fVar8 * fVar7,0,0x3f333333);
  return;
}



// ?Cleanup@CameraModeTwoObjects@@UAEXXZ @ 0x0043ea40

void _Cleanup_CameraModeTwoObjects__UAEXXZ(void)

{
  int in_ECX;
  
  if (*(int *)(*(int *)(in_ECX + 0xc) + 0xbc) != 0) {
    *(undefined4 *)(*(int *)(in_ECX + 0xc) + 0xbc) = 0;
    *(undefined4 *)(*(int *)(in_ECX + 0xc) + 0xb8) = 0;
    *(undefined4 *)(in_ECX + 8) = 0;
  }
  if (*(int *)(*(int *)(in_ECX + 0xc) + 0xb0) == 0) {
    *(undefined4 *)(in_ECX + 8) = 0;
    FUN_0043ab50();
    return;
  }
  return;
}



// ?CanExist@CameraModeTwoObjects@@UAE_NXZ @ 0x0043f440

void _CanExist_CameraModeTwoObjects__UAE_NXZ(void)

{
  float fVar1;
  char cVar2;
  float *pfVar3;
  int iVar4;
  float *pfVar5;
  int *in_ECX;
  float fVar6;
  int *piVar7;
  float10 fVar8;
  float *pfStack_d8;
  float *pfStack_d4;
  TypeDescriptor *pTStack_d0;
  TypeDescriptor *pTStack_cc;
  TypeDescriptor *pTStack_c8;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float fStack_a0;
  float fStack_9c;
  TypeDescriptor *pTStack_98;
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  TypeDescriptor *pTStack_80;
  TypeDescriptor *pTStack_7c;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  float fStack_3c;
  TypeDescriptor *pTStack_38;
  TypeDescriptor *pTStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if ((float)in_ECX[5] <= 2.0) {
    iVar4 = 0x40000000;
  }
  else if (1500.0 <= (float)in_ECX[5]) {
    iVar4 = 0x44bb8000;
  }
  else {
    iVar4 = in_ECX[5];
  }
  in_ECX[5] = iVar4;
  if (*(float *)(in_ECX[1] + 0x68) <= 2.0) {
    fVar1 = (*(float *)(in_ECX[1] + 0x68) / 2.0) * -1.0 + 2.0;
  }
  else {
    fVar1 = 1.0;
  }
  fVar1 = fVar1 * (float)in_ECX[6];
  pTStack_c8 = (TypeDescriptor *)0x43f4c8;
  pfVar3 = (float *)(**(code **)(*in_ECX + 0x48))();
  if (pfVar3 != (float *)0x0) {
    pTStack_c8 = (TypeDescriptor *)0x43f4d7;
    iVar4 = (**(code **)((int)*pfVar3 + 0x34))();
    if (iVar4 != 0) {
      DAT_00be7670 = 0;
      DAT_00be766c = 0xff;
      pTStack_c8 = (TypeDescriptor *)0x43f4f5;
      fVar8 = (float10)(**(code **)((int)*pfVar3 + 0x11c))();
      DAT_00be764c = (float)((float10)1.0 - fVar8);
      DAT_00be7648 = 1.0 - *(float *)((int)pfVar3[0x58] + 0x1c);
      DAT_00be7644 = *(undefined4 *)((int)pfVar3[0x58] + 0x30);
    }
  }
  if (in_ECX[8] == 0) {
LAB_0043f734:
    if (pfVar3 == (float *)0x0) goto LAB_0043f87c;
    pTStack_c8 = (TypeDescriptor *)0x43f746;
    iVar4 = (**(code **)((int)*pfVar3 + 0x3ec))();
    if (iVar4 == 0) {
      fVar6 = pfVar3[7];
      pTStack_c8 = (TypeDescriptor *)0x43f7c5;
      fVar8 = (float10)FUN_00760fd0();
      pTStack_c8 = (TypeDescriptor *)0x0;
      pTStack_cc = &Object::RTTI_Type_Descriptor;
      fStack_9c = (float)(fVar8 + (float10)fVar6);
      pTStack_d0 = &GameThingWithPos::RTTI_Type_Descriptor;
      pfStack_d4 = (float *)0x0;
      fStack_a0 = (float)(int)pfVar3[5] * 0.00015258789;
      pTStack_98 = (TypeDescriptor *)((float)(int)pfVar3[6] * 0.00015258789);
      pfStack_d8 = pfVar3;
      iVar4 = FUN_007344da();
      if ((iVar4 != 0) && (iVar4 = *(int *)(iVar4 + 0x40), iVar4 != 0)) {
        fStack_a0 = *(float *)(iVar4 + 0x38);
        fStack_9c = *(float *)(iVar4 + 0x3c);
        pTStack_98 = *(TypeDescriptor **)(iVar4 + 0x40);
      }
      fVar6 = *pfVar3;
LAB_0043f821:
      pTStack_c8 = (TypeDescriptor *)0x43f827;
      fVar8 = (float10)(**(code **)((int)fVar6 + 0x42c))();
      fStack_9c = (float)(fVar8 * (float10)0.5 + (float10)fStack_9c);
    }
    else {
      if (pfVar3[0x10] == 0.0) {
        pfVar3 = (float *)0x0;
      }
      else {
        pfVar3 = *(float **)((int)pfVar3[0x10] + 8);
      }
      pTStack_c8 = (TypeDescriptor *)0x43f75f;
      pfVar5 = (float *)FUN_00506580();
      fStack_ac = *pfVar5;
      fStack_a8 = pfVar5[1];
      fVar6 = pfVar5[2];
      pTStack_c8 = (TypeDescriptor *)0x43f782;
      fStack_a4 = fVar6;
      fVar8 = (float10)FUN_00760fd0();
      fStack_9c = (float)(fVar8 + (float10)fVar6);
      fStack_a0 = (float)(int)fStack_ac * 0.00015258789;
      pTStack_98 = (TypeDescriptor *)((float)(int)fStack_a8 * 0.00015258789);
      if (pfVar3 != (float *)0x0) {
        fVar6 = *pfVar3;
        goto LAB_0043f821;
      }
    }
    pTStack_cc = (TypeDescriptor *)0x0;
    pTStack_d0 = (TypeDescriptor *)fStack_a0;
    pfStack_d4 = (float *)0x43f853;
    pTStack_c8 = (TypeDescriptor *)fVar1;
    FUN_00406240();
    pTStack_cc = (TypeDescriptor *)0x0;
    pTStack_d0 = (TypeDescriptor *)fStack_9c;
    pfStack_d4 = (float *)0x43f865;
    pTStack_c8 = (TypeDescriptor *)fVar1;
    FUN_00406240();
    pTStack_cc = (TypeDescriptor *)0x0;
    pTStack_d0 = pTStack_98;
    pfStack_d4 = (float *)0x43f877;
    pTStack_c8 = (TypeDescriptor *)fVar1;
    FUN_00406240();
  }
  else {
    if (pfVar3 != (float *)0x0) {
      pTStack_c8 = (TypeDescriptor *)0x0;
      pTStack_cc = &Object::RTTI_Type_Descriptor;
      pTStack_d0 = &GameThingWithPos::RTTI_Type_Descriptor;
      pfStack_d4 = (float *)0x0;
      pfStack_d8 = pfVar3;
      iVar4 = FUN_007344da();
      in_ECX[5] = (int)SQRT(((float)in_ECX[9] - (float)in_ECX[0xc]) *
                            ((float)in_ECX[9] - (float)in_ECX[0xc]) +
                            ((float)in_ECX[10] - (float)in_ECX[0xd]) *
                            ((float)in_ECX[10] - (float)in_ECX[0xd]) +
                            ((float)in_ECX[0xb] - (float)in_ECX[0xe]) *
                            ((float)in_ECX[0xb] - (float)in_ECX[0xe]));
      if ((iVar4 != 0) && (iVar4 = *(int *)(iVar4 + 0x40), iVar4 != 0)) {
        fStack_90 = *(float *)(iVar4 + 0x38);
        pTStack_d0 = (TypeDescriptor *)(fStack_90 + (float)in_ECX[9]);
        fStack_8c = *(float *)(iVar4 + 0x3c);
        fStack_88 = *(float *)(iVar4 + 0x40);
        fStack_a8 = fStack_8c + (float)in_ECX[10];
        pTStack_cc = (TypeDescriptor *)0x0;
        fStack_a4 = fStack_88 + (float)in_ECX[0xb];
        fStack_78 = fStack_90 + (float)in_ECX[0xc];
        fStack_74 = fStack_8c + (float)in_ECX[0xd];
        fStack_70 = fStack_88 + (float)in_ECX[0xe];
        pfStack_d4 = (float *)0x43f602;
        pTStack_c8 = (TypeDescriptor *)fVar1;
        fStack_ac = (float)pTStack_d0;
        FUN_00406240();
        pTStack_cc = (TypeDescriptor *)0x0;
        pTStack_d0 = (TypeDescriptor *)fStack_a8;
        pfStack_d4 = (float *)0x43f614;
        pTStack_c8 = (TypeDescriptor *)fVar1;
        FUN_00406240();
        pTStack_cc = (TypeDescriptor *)0x0;
        pTStack_d0 = (TypeDescriptor *)fStack_a4;
        pfStack_d4 = (float *)0x43f626;
        pTStack_c8 = (TypeDescriptor *)fVar1;
        FUN_00406240();
        pTStack_cc = (TypeDescriptor *)0x0;
        pTStack_d0 = (TypeDescriptor *)fStack_78;
        pfStack_d4 = (float *)0x43f640;
        pTStack_c8 = (TypeDescriptor *)fVar1;
        FUN_00406240();
        pTStack_cc = (TypeDescriptor *)0x0;
        pTStack_d0 = (TypeDescriptor *)fStack_74;
        pfStack_d4 = (float *)0x43f652;
        pTStack_c8 = (TypeDescriptor *)fVar1;
        FUN_00406240();
        pTStack_cc = (TypeDescriptor *)0x0;
        pTStack_d0 = (TypeDescriptor *)fStack_70;
        pfStack_d4 = (float *)0x43f664;
        pTStack_c8 = (TypeDescriptor *)fVar1;
        FUN_00406240();
        pTStack_c8 = (TypeDescriptor *)0x0;
        pTStack_cc = (TypeDescriptor *)&fStack_90;
        FUN_00440270(&pfStack_d8,&fStack_78);
        FUN_004402a0(&fStack_78);
        cVar2 = FUN_00442bd0();
        if (cVar2 != '\0') {
          return;
        }
        pTStack_c8 = (TypeDescriptor *)0x0;
        pTStack_cc = &CameraModeScript::RTTI_Type_Descriptor;
        pTStack_d0 = &CameraModeFollow::RTTI_Type_Descriptor;
        pfStack_d4 = (float *)0x0;
        iVar4 = FUN_007344da();
        if (iVar4 != 0) {
          return;
        }
        pTStack_cc = (TypeDescriptor *)0x0;
        fStack_74 = fStack_8c;
        pTStack_d0 = (TypeDescriptor *)fStack_90;
        fStack_78 = fStack_90;
        fStack_70 = fStack_88;
        pfStack_d4 = (float *)0x43f6ec;
        pTStack_c8 = (TypeDescriptor *)fVar1;
        FUN_00406240();
        pTStack_cc = (TypeDescriptor *)0x0;
        pTStack_d0 = (TypeDescriptor *)fStack_74;
        pfStack_d4 = (float *)0x43f6fe;
        pTStack_c8 = (TypeDescriptor *)fVar1;
        FUN_00406240();
        pTStack_cc = (TypeDescriptor *)0x0;
        pTStack_d0 = (TypeDescriptor *)fStack_70;
        pfStack_d4 = (float *)0x43f710;
        pTStack_c8 = (TypeDescriptor *)fVar1;
        FUN_00406240();
        pTStack_c8 = (TypeDescriptor *)0x16b;
        pTStack_cc = (TypeDescriptor *)s_C__dev_black_CameraModeFollow_cp_008fc8b8;
        pTStack_d0 = (TypeDescriptor *)0x300;
        pfStack_d4 = (float *)0x43f724;
        iVar4 = FUN_00746d70();
        goto joined_r0x0044024e;
      }
      goto LAB_0043f734;
    }
LAB_0043f87c:
    pTStack_c8 = (TypeDescriptor *)0x43f883;
    iVar4 = (**(code **)(*in_ECX + 0x4c))();
    if (iVar4 != -1) {
      pTStack_c8 = (TypeDescriptor *)0x43f893;
      pTStack_c8 = (TypeDescriptor *)(**(code **)(*in_ECX + 0x4c))();
      pTStack_cc = (TypeDescriptor *)0x43f89f;
      FUN_00523640();
      pTStack_c8 = (TypeDescriptor *)&fStack_ac;
      pTStack_cc = (TypeDescriptor *)0x43f8b1;
      piVar7 = (int *)FUN_00603510();
      fVar6 = (float)piVar7[2];
      pTStack_c8 = (TypeDescriptor *)0x43f8c1;
      fVar8 = (float10)FUN_00760fd0();
      fStack_9c = (float)(fVar8 + (float10)fVar6);
      pTStack_cc = (TypeDescriptor *)0x0;
      pTStack_d0 = (TypeDescriptor *)((float)*piVar7 * 0.00015258789);
      pTStack_98 = (TypeDescriptor *)((float)piVar7[1] * 0.00015258789);
      pfStack_d4 = (float *)0x43f900;
      pTStack_c8 = (TypeDescriptor *)fVar1;
      fStack_a0 = (float)pTStack_d0;
      FUN_00406240();
      pTStack_cc = (TypeDescriptor *)0x0;
      pTStack_d0 = (TypeDescriptor *)fStack_9c;
      pfStack_d4 = (float *)0x43f912;
      pTStack_c8 = (TypeDescriptor *)fVar1;
      FUN_00406240();
      pTStack_cc = (TypeDescriptor *)0x0;
      pTStack_d0 = pTStack_98;
      pfStack_d4 = (float *)0x43f924;
      pTStack_c8 = (TypeDescriptor *)fVar1;
      FUN_00406240();
    }
  }
  if ((int *)in_ECX[2] == (int *)0x0) {
    pTStack_c8 = (TypeDescriptor *)0x43fbec;
    iVar4 = (**(code **)(*in_ECX + 0x50))();
    if (iVar4 != -1) {
      if ((float)in_ECX[4] <= 0.24166098) {
        iVar4 = 0x3e7775fa;
      }
      else {
        iVar4 = in_ECX[4];
      }
      fStack_94 = (float)in_ECX[3];
      in_ECX[4] = iVar4;
      pTStack_c8 = (TypeDescriptor *)0x43fc21;
      pTStack_c8 = (TypeDescriptor *)(**(code **)(*in_ECX + 0x50))();
      pTStack_cc = (TypeDescriptor *)0x43fc2d;
      FUN_00523640();
      pTStack_c8 = (TypeDescriptor *)&fStack_ac;
      pTStack_cc = (TypeDescriptor *)0x43fc3f;
      piVar7 = (int *)FUN_00603510();
      fVar6 = (float)piVar7[2];
      pTStack_c8 = (TypeDescriptor *)0x43fc4f;
      fVar8 = (float10)FUN_00760fd0();
      pTStack_c8 = (TypeDescriptor *)in_ECX[4];
      pTStack_d0 = (TypeDescriptor *)in_ECX[5];
      pTStack_80 = (TypeDescriptor *)(float)(fVar8 + (float10)fVar6);
      pTStack_cc = (TypeDescriptor *)fStack_94;
      fStack_84 = (float)*piVar7 * 0.00015258789;
      pfStack_d4 = &fStack_a0;
      pfStack_d8 = &fStack_84;
      pTStack_7c = (TypeDescriptor *)((float)piVar7[1] * 0.00015258789);
      FUN_0043a640();
      iVar4 = in_ECX[1];
      pTStack_cc = (TypeDescriptor *)0x0;
      pTStack_d0 = (TypeDescriptor *)fStack_84;
      pfStack_d4 = (float *)0x43fca9;
      pTStack_c8 = (TypeDescriptor *)fVar1;
      FUN_00406240();
      pTStack_cc = (TypeDescriptor *)0x0;
      pTStack_d0 = pTStack_80;
      pfStack_d4 = (float *)0x43fcbb;
      pTStack_c8 = (TypeDescriptor *)fVar1;
      FUN_00406240();
      if (0.001 <= fVar1) {
        *(TypeDescriptor **)(iVar4 + 0x17c) = pTStack_7c;
        *(undefined4 *)(iVar4 + 0x198) = *(undefined4 *)(iVar4 + 0x184);
        fStack_64 = fVar1 * fVar1 * 0.5;
        *(undefined4 *)(iVar4 + 0x194) = *(undefined4 *)(iVar4 + 0x178);
        *(float *)(iVar4 + 400) = fVar1;
        fStack_68 = fStack_64 * fVar1 * 0.33333334;
        *(undefined4 *)(iVar4 + 0x180) = 0;
        *(undefined4 *)(iVar4 + 0x18c) = 0;
        uStack_4c = 0x3f800000;
        fStack_6c = fStack_64 * fStack_64 * 0.16666667;
        uStack_40 = 0;
        uStack_44 = 0;
        uStack_48 = 0;
        pTStack_c8 = (TypeDescriptor *)0x43fd81;
        fStack_60 = fStack_68;
        fStack_5c = fStack_64;
        fStack_58 = fVar1;
        fStack_54 = fStack_64;
        fStack_50 = fVar1;
        FUN_00759970();
        fStack_a4 = 0.0;
        fStack_ac = (*(float *)(iVar4 + 0x17c) - *(float *)(iVar4 + 0x194)) -
                    *(float *)(iVar4 + 0x198) * *(float *)(iVar4 + 400);
        fStack_a8 = *(float *)(iVar4 + 0x180) - *(float *)(iVar4 + 0x198);
        pTStack_c8 = (TypeDescriptor *)0x43fdb5;
        FUN_004151c0();
        *(float *)(iVar4 + 0x1a4) = fStack_ac;
        *(float *)(iVar4 + 0x1a0) = fStack_a8;
        *(float *)(iVar4 + 0x19c) = fStack_a4;
      }
      else {
        pTStack_c8 = pTStack_7c;
        pTStack_cc = (TypeDescriptor *)0x43fce1;
        FUN_004399e0();
      }
    }
  }
  else {
    pTStack_c8 = (TypeDescriptor *)0x43f93b;
    iVar4 = (**(code **)(*(int *)in_ECX[2] + 0x3ec))();
    if (iVar4 == 0) {
      iVar4 = in_ECX[2];
      fVar6 = *(float *)(iVar4 + 0x1c);
      pTStack_c8 = (TypeDescriptor *)0x43f9c4;
      fVar8 = (float10)FUN_00760fd0();
      pfStack_d8 = (float *)in_ECX[2];
      pTStack_c8 = (TypeDescriptor *)0x0;
      fStack_9c = (float)(fVar8 + (float10)fVar6);
      pTStack_cc = &Object::RTTI_Type_Descriptor;
      pTStack_d0 = &GameThingWithPos::RTTI_Type_Descriptor;
      pfStack_d4 = (float *)0x0;
      fStack_a0 = (float)*(int *)(iVar4 + 0x14) * 0.00015258789;
      pTStack_98 = (TypeDescriptor *)((float)*(int *)(iVar4 + 0x18) * 0.00015258789);
      iVar4 = FUN_007344da();
      if ((iVar4 != 0) && (iVar4 = *(int *)(iVar4 + 0x40), iVar4 != 0)) {
        fStack_a0 = *(float *)(iVar4 + 0x38);
        fStack_9c = *(float *)(iVar4 + 0x3c);
        pTStack_98 = *(TypeDescriptor **)(iVar4 + 0x40);
      }
      pTStack_c8 = (TypeDescriptor *)0x43fa2a;
      fVar8 = (float10)(**(code **)(*(int *)in_ECX[2] + 0x42c))();
LAB_0043fa2a:
      fStack_9c = (float)(fVar8 * (float10)0.5 + (float10)fStack_9c);
    }
    else {
      if (*(int *)(in_ECX[2] + 0x40) == 0) {
        piVar7 = (int *)0x0;
      }
      else {
        piVar7 = *(int **)(*(int *)(in_ECX[2] + 0x40) + 8);
      }
      pTStack_c8 = (TypeDescriptor *)0x43f955;
      pfVar3 = (float *)FUN_00506580();
      fStack_ac = *pfVar3;
      fStack_a8 = pfVar3[1];
      fVar6 = pfVar3[2];
      pTStack_c8 = (TypeDescriptor *)0x43f978;
      fStack_a4 = fVar6;
      fVar8 = (float10)FUN_00760fd0();
      fStack_9c = (float)(fVar8 + (float10)fVar6);
      fStack_a0 = (float)(int)fStack_ac * 0.00015258789;
      pTStack_98 = (TypeDescriptor *)((float)(int)fStack_a8 * 0.00015258789);
      if (piVar7 != (int *)0x0) {
        pTStack_c8 = (TypeDescriptor *)0x43f9ae;
        fVar8 = (float10)(**(code **)(*piVar7 + 0x42c))();
        goto LAB_0043fa2a;
      }
    }
    pfVar3 = (float *)(in_ECX + 4);
    if ((float)in_ECX[4] <= 0.24166098) {
      fVar6 = 0.24166098;
    }
    else {
      fVar6 = *pfVar3;
    }
    *pfVar3 = fVar6;
    fStack_94 = (float)in_ECX[3];
    if (in_ECX[7] != 0) {
      pfStack_d8 = (float *)in_ECX[2];
      pTStack_c8 = (TypeDescriptor *)0x0;
      pTStack_cc = &MobileWallHug::RTTI_Type_Descriptor;
      pTStack_d0 = &GameThingWithPos::RTTI_Type_Descriptor;
      pfStack_d4 = (float *)0x0;
      iVar4 = FUN_007344da();
      if (iVar4 != 0) {
        fStack_94 = fStack_94 -
                    ((float)((uint)*(ushort *)(iVar4 + 0x5c) << 1) * 0.0015339808 - 1.5707964);
      }
    }
    pTStack_c8 = (TypeDescriptor *)*pfVar3;
    pTStack_d0 = (TypeDescriptor *)in_ECX[5];
    pTStack_cc = (TypeDescriptor *)fStack_94;
    pfStack_d4 = &fStack_a0;
    pfStack_d8 = &fStack_84;
    FUN_0043a640();
    if ((((in_ECX[7] == 0) && (in_ECX[0x11] != 0)) && (in_ECX[0xf] == 0)) && (in_ECX[0x10] == 0)) {
      pTStack_c8 = (TypeDescriptor *)0xf;
      pTStack_cc = (TypeDescriptor *)0x43fafc;
      iVar4 = FUN_0045b7e0();
      if (iVar4 != 0) {
        pTStack_c8 = (TypeDescriptor *)0x6;
        pTStack_cc = (TypeDescriptor *)0x43fb17;
        iVar4 = FUN_0045b7e0();
        if (iVar4 != 0) {
          pTStack_c8 = (TypeDescriptor *)&fStack_ac;
          pTStack_cc = (TypeDescriptor *)&fStack_90;
          FUN_004402a0(&fStack_a0);
          FUN_004402a0(&fStack_84);
          FUN_00444db0();
          FUN_0043a700(&fStack_90,&fStack_ac,in_ECX + 3,pfVar3);
          if (*pfVar3 <= 0.24166098) {
            pTStack_c8 = (TypeDescriptor *)0x3e7775fa;
          }
          else {
            pTStack_c8 = (TypeDescriptor *)*pfVar3;
          }
          *pfVar3 = (float)pTStack_c8;
          pTStack_d0 = (TypeDescriptor *)in_ECX[5];
          pTStack_cc = (TypeDescriptor *)fStack_94;
          pfStack_d4 = &fStack_a0;
          pfStack_d8 = &fStack_84;
          FUN_0043a640();
        }
      }
    }
    pTStack_cc = (TypeDescriptor *)0x0;
    pTStack_d0 = (TypeDescriptor *)fStack_84;
    pfStack_d4 = (float *)0x43fbbc;
    pTStack_c8 = (TypeDescriptor *)fVar1;
    FUN_00406240();
    pTStack_cc = (TypeDescriptor *)0x0;
    pTStack_d0 = pTStack_80;
    pfStack_d4 = (float *)0x43fbce;
    pTStack_c8 = (TypeDescriptor *)fVar1;
    FUN_00406240();
    pTStack_cc = (TypeDescriptor *)0x0;
    pTStack_d0 = pTStack_7c;
    pfStack_d4 = (float *)0x43fbe0;
    pTStack_c8 = (TypeDescriptor *)fVar1;
    FUN_00406240();
  }
  pTStack_c8 = (TypeDescriptor *)0x0;
  pTStack_cc = (TypeDescriptor *)&fStack_3c;
  FUN_00440270(&pfStack_d8,&fStack_84);
  FUN_004402a0(&fStack_84);
  cVar2 = FUN_00442bd0();
  if (cVar2 != '\0') {
    return;
  }
  pTStack_c8 = (TypeDescriptor *)0x0;
  pTStack_cc = &CameraModeScript::RTTI_Type_Descriptor;
  pTStack_d0 = &CameraModeFollow::RTTI_Type_Descriptor;
  pfStack_d4 = (float *)0x0;
  iVar4 = FUN_007344da();
  if (iVar4 != 0) {
    return;
  }
  iVar4 = in_ECX[1];
  fStack_84 = fStack_3c;
  pTStack_80 = pTStack_38;
  pTStack_7c = pTStack_34;
  if (0.001 <= fVar1) {
    *(float *)(iVar4 + 0x11c) = fStack_3c;
    *(float *)(iVar4 + 0x134) = *(float *)(iVar4 + 0x118);
    *(undefined4 *)(iVar4 + 0x138) = *(undefined4 *)(iVar4 + 0x124);
    fStack_64 = fVar1 * fVar1 * 0.5;
    fStack_68 = fStack_64 * fVar1 * 0.33333334;
    *(undefined4 *)(iVar4 + 0x120) = 0;
    *(float *)(iVar4 + 0x130) = fVar1;
    *(undefined4 *)(iVar4 + 300) = 0;
    uStack_4c = 0x3f800000;
    fStack_6c = fStack_64 * fStack_64 * 0.16666667;
    uStack_40 = 0;
    uStack_44 = 0;
    uStack_48 = 0;
    pTStack_c8 = (TypeDescriptor *)0x43ff2f;
    fStack_60 = fStack_68;
    fStack_5c = fStack_64;
    fStack_58 = fVar1;
    fStack_54 = fStack_64;
    fStack_50 = fVar1;
    FUN_00759970();
    fStack_a4 = 0.0;
    fStack_ac = (*(float *)(iVar4 + 0x11c) - *(float *)(iVar4 + 0x134)) -
                *(float *)(iVar4 + 0x138) * *(float *)(iVar4 + 0x130);
    fStack_a8 = *(float *)(iVar4 + 0x120) - *(float *)(iVar4 + 0x138);
    pTStack_c8 = (TypeDescriptor *)0x43ff63;
    FUN_004151c0();
    *(float *)(iVar4 + 0x144) = fStack_ac;
    *(float *)(iVar4 + 0x140) = fStack_a8;
    *(float *)(iVar4 + 0x13c) = fStack_a4;
    *(TypeDescriptor **)(iVar4 + 0x14c) = pTStack_80;
    *(undefined4 *)(iVar4 + 0x164) = *(undefined4 *)(iVar4 + 0x148);
    *(undefined4 *)(iVar4 + 0x168) = *(undefined4 *)(iVar4 + 0x154);
    fStack_64 = fVar1 * fVar1 * 0.5;
    fStack_68 = fStack_64 * fVar1 * 0.33333334;
    *(undefined4 *)(iVar4 + 0x150) = 0;
    *(float *)(iVar4 + 0x160) = fVar1;
    *(undefined4 *)(iVar4 + 0x15c) = 0;
    uStack_4c = 0x3f800000;
    fStack_6c = fStack_64 * fStack_64 * 0.16666667;
    uStack_40 = 0;
    uStack_44 = 0;
    uStack_48 = 0;
    pTStack_c8 = (TypeDescriptor *)0x440056;
    fStack_60 = fStack_68;
    fStack_5c = fStack_64;
    fStack_58 = fVar1;
    fStack_54 = fStack_64;
    fStack_50 = fVar1;
    FUN_00759970();
    fStack_a4 = 0.0;
    fStack_ac = (*(float *)(iVar4 + 0x14c) - *(float *)(iVar4 + 0x164)) -
                *(float *)(iVar4 + 0x160) * *(float *)(iVar4 + 0x168);
    fStack_a8 = *(float *)(iVar4 + 0x150) - *(float *)(iVar4 + 0x168);
    pTStack_c8 = (TypeDescriptor *)0x44008a;
    FUN_004151c0();
    *(float *)(iVar4 + 0x174) = fStack_ac;
    *(float *)(iVar4 + 0x170) = fStack_a8;
    *(float *)(iVar4 + 0x16c) = fStack_a4;
    *(TypeDescriptor **)(iVar4 + 0x17c) = pTStack_7c;
    *(undefined4 *)(iVar4 + 0x194) = *(undefined4 *)(iVar4 + 0x178);
    *(undefined4 *)(iVar4 + 0x198) = *(undefined4 *)(iVar4 + 0x184);
    fStack_64 = fVar1 * fVar1 * 0.5;
    fStack_68 = fStack_64 * fVar1 * 0.33333334;
    *(undefined4 *)(iVar4 + 0x180) = 0;
    *(float *)(iVar4 + 400) = fVar1;
    *(undefined4 *)(iVar4 + 0x18c) = 0;
    uStack_4c = 0x3f800000;
    fStack_6c = fStack_64 * fStack_64 * 0.16666667;
    uStack_40 = 0;
    uStack_44 = 0;
    uStack_48 = 0;
    pTStack_c8 = (TypeDescriptor *)0x44018c;
    fStack_60 = fStack_68;
    fStack_5c = fStack_64;
    fStack_58 = fVar1;
    fStack_54 = fStack_64;
    fStack_50 = fVar1;
    FUN_00759970();
    fVar1 = (*(float *)(iVar4 + 0x17c) - *(float *)(iVar4 + 0x194)) -
            *(float *)(iVar4 + 0x198) * *(float *)(iVar4 + 400);
    fStack_94 = *(float *)(iVar4 + 0x180) - *(float *)(iVar4 + 0x198);
    fStack_8c = fStack_94 * fStack_20 + fVar1 * fStack_2c + fStack_8;
    *(float *)(iVar4 + 0x1a0) = fStack_8c;
    fStack_88 = fStack_94 * fStack_1c + fVar1 * fStack_28 + fStack_4;
    *(float *)(iVar4 + 0x19c) = fStack_88;
    *(float *)(iVar4 + 0x1a4) = fStack_30 * fVar1 + fStack_94 * fStack_24 + fStack_c;
  }
  else {
    *(float *)(iVar4 + 0x118) = fStack_3c;
    *(float *)(iVar4 + 0x134) = fStack_3c;
    *(float *)(iVar4 + 0x11c) = fStack_3c;
    *(undefined4 *)(iVar4 + 0x130) = 0;
    *(undefined4 *)(iVar4 + 300) = 0;
    *(undefined4 *)(iVar4 + 0x144) = 0;
    *(undefined4 *)(iVar4 + 0x140) = 0;
    *(undefined4 *)(iVar4 + 0x128) = 0;
    *(undefined4 *)(iVar4 + 0x13c) = 0;
    *(undefined4 *)(iVar4 + 0x124) = 0;
    *(undefined4 *)(iVar4 + 0x138) = 0;
    *(undefined4 *)(iVar4 + 0x120) = 0;
    *(TypeDescriptor **)(iVar4 + 0x148) = pTStack_38;
    *(TypeDescriptor **)(iVar4 + 0x164) = pTStack_38;
    *(TypeDescriptor **)(iVar4 + 0x14c) = pTStack_38;
    *(undefined4 *)(iVar4 + 0x160) = 0;
    *(undefined4 *)(iVar4 + 0x15c) = 0;
    *(undefined4 *)(iVar4 + 0x174) = 0;
    *(undefined4 *)(iVar4 + 0x170) = 0;
    *(undefined4 *)(iVar4 + 0x158) = 0;
    *(undefined4 *)(iVar4 + 0x16c) = 0;
    *(undefined4 *)(iVar4 + 0x154) = 0;
    *(undefined4 *)(iVar4 + 0x168) = 0;
    *(undefined4 *)(iVar4 + 0x150) = 0;
    *(TypeDescriptor **)(iVar4 + 0x178) = pTStack_34;
    *(TypeDescriptor **)(iVar4 + 0x194) = pTStack_34;
    *(TypeDescriptor **)(iVar4 + 0x17c) = pTStack_34;
    *(undefined4 *)(iVar4 + 400) = 0;
    *(undefined4 *)(iVar4 + 0x18c) = 0;
    *(undefined4 *)(iVar4 + 0x1a4) = 0;
    *(undefined4 *)(iVar4 + 0x1a0) = 0;
    *(undefined4 *)(iVar4 + 0x188) = 0;
    *(undefined4 *)(iVar4 + 0x19c) = 0;
    *(undefined4 *)(iVar4 + 0x184) = 0;
    *(undefined4 *)(iVar4 + 0x198) = 0;
    *(undefined4 *)(iVar4 + 0x180) = 0;
  }
  pTStack_c8 = (TypeDescriptor *)0x1df;
  pTStack_cc = (TypeDescriptor *)s_C__dev_black_CameraModeFollow_cp_008fc8b8;
  pTStack_d0 = (TypeDescriptor *)0x300;
  pfStack_d4 = (float *)0x440249;
  iVar4 = FUN_00746d70();
joined_r0x0044024e:
  if (iVar4 != 0) {
    pTStack_c8 = (TypeDescriptor *)in_ECX[1];
    pTStack_cc = (TypeDescriptor *)0x44025b;
    FUN_00443b80();
  }
  return;
}



// ?Restart@CameraModeTwoObjects@@UAEXXZ @ 0x00440b50

void _Restart_CameraModeTwoObjects__UAEXXZ(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int iVar7;
  int in_ECX;
  float10 fVar8;
  float fStack_8c;
  float fStack_88;
  float fStack_78;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  iVar7 = *(int *)(in_ECX + 8);
  if (iVar7 != 0) {
    fVar6 = *(float *)(iVar7 + 0x1c);
    fVar8 = (float10)FUN_00760fd0();
    fStack_74 = (float)(fVar8 + (float10)fVar6);
    fStack_78 = (float)*(int *)(iVar7 + 0x14) * 0.00015258789;
    fStack_70 = (float)*(int *)(iVar7 + 0x18) * 0.00015258789;
    fVar8 = (float10)(**(code **)(**(int **)(in_ECX + 8) + 0x42c))();
    fStack_74 = (float)(fVar8 * (float10)0.5 + (float10)fStack_74);
    fVar6 = *(float *)(in_ECX + 0x18) + *(float *)(in_ECX + 0xc);
    *(float *)(in_ECX + 0xc) = fVar6;
    if (6.2831855 < fVar6) {
      *(float *)(in_ECX + 0xc) = fVar6 - 6.2831855;
    }
    fVar8 = (float10)(**(code **)(**(int **)(in_ECX + 8) + 0x4ec))();
    fStack_8c = (float)fVar8;
    if ((float10)6.2831855 < fVar8) {
      fStack_8c = fStack_8c - 6.2831855;
    }
    iVar7 = (**(code **)(**(int **)(in_ECX + 8) + 0x410))();
    if (iVar7 == 0) {
      fStack_8c = fStack_8c + *(float *)(in_ECX + 0xc);
      if (6.2831855 < fStack_8c) {
        fStack_8c = fStack_8c - 6.2831855;
      }
      DAT_00b7c890 = 6.2831855 - fStack_8c;
    }
    fVar6 = DAT_00b7c890;
    FUN_004ef260(&DAT_00bf4e6c,4,s_heading____3f_008fc940,(double)DAT_00b7c890);
    (**(code **)(**(int **)(in_ECX + 8) + 0x824))();
    fStack_88 = *(float *)(in_ECX + 0x10);
    if (fStack_88 <= 0.06283186) {
      fStack_88 = 0.06283186;
    }
    FUN_0043a640(&uStack_3c,&fStack_78,*(undefined4 *)(in_ECX + 0x14),fVar6,fStack_88);
    iVar7 = *(int *)(in_ECX + 4);
    if (*(float *)(iVar7 + 0x68) <= 2.0) {
      fStack_8c = (*(float *)(iVar7 + 0x68) / 2.0) * -1.0 + 2.0;
    }
    else {
      fStack_8c = 1.0;
    }
    FUN_00406240(uStack_3c,0,fStack_8c);
    FUN_00406240(uStack_38,0,fStack_8c);
    if (0.001 <= fStack_8c) {
      *(undefined4 *)(iVar7 + 0x17c) = uStack_34;
      *(undefined4 *)(iVar7 + 0x194) = *(undefined4 *)(iVar7 + 0x178);
      fStack_64 = fStack_8c * fStack_8c * 0.5;
      *(undefined4 *)(iVar7 + 0x198) = *(undefined4 *)(iVar7 + 0x184);
      *(float *)(iVar7 + 400) = fStack_8c;
      fStack_58 = fStack_8c;
      fStack_68 = fStack_64 * fStack_8c * 0.33333334;
      *(undefined4 *)(iVar7 + 0x180) = 0;
      *(undefined4 *)(iVar7 + 0x18c) = 0;
      fStack_50 = fStack_8c;
      uStack_4c = 0x3f800000;
      fStack_6c = fStack_64 * fStack_64 * 0.16666667;
      uStack_40 = 0;
      uStack_44 = 0;
      uStack_48 = 0;
      fStack_60 = fStack_68;
      fStack_5c = fStack_64;
      fStack_54 = fStack_64;
      FUN_00759970();
      fVar6 = *(float *)(iVar7 + 0x17c);
      fVar1 = *(float *)(iVar7 + 0x194);
      fVar2 = *(float *)(iVar7 + 0x198);
      fVar3 = *(float *)(iVar7 + 400);
      fVar4 = *(float *)(iVar7 + 0x180);
      fVar5 = *(float *)(iVar7 + 0x198);
      FUN_004151c0();
      *(float *)(iVar7 + 0x1a4) = (fVar6 - fVar1) - fVar2 * fVar3;
      *(float *)(iVar7 + 0x1a0) = fVar4 - fVar5;
      *(undefined4 *)(iVar7 + 0x19c) = 0;
    }
    else {
      FUN_004399e0(uStack_34);
    }
    iVar7 = *(int *)(in_ECX + 4);
    FUN_00406240(fStack_78,0,fStack_8c);
    FUN_00406240(fStack_74,0,fStack_8c);
    if (fStack_8c < 0.001) {
      FUN_004399e0();
      return;
    }
    *(float *)(iVar7 + 0xec) = fStack_70;
    *(undefined4 *)(iVar7 + 0x104) = *(undefined4 *)(iVar7 + 0xe8);
    fStack_64 = fStack_8c * fStack_8c * 0.5;
    *(undefined4 *)(iVar7 + 0x108) = *(undefined4 *)(iVar7 + 0xf4);
    *(float *)(iVar7 + 0x100) = fStack_8c;
    fStack_58 = fStack_8c;
    fStack_68 = fStack_64 * fStack_8c * 0.33333334;
    *(undefined4 *)(iVar7 + 0xf0) = 0;
    *(undefined4 *)(iVar7 + 0xfc) = 0;
    fStack_50 = fStack_8c;
    uStack_4c = 0x3f800000;
    fStack_6c = fStack_64 * fStack_64 * 0.16666667;
    uStack_40 = 0;
    uStack_44 = 0;
    uStack_48 = 0;
    fStack_60 = fStack_68;
    fStack_5c = fStack_64;
    fStack_54 = fStack_64;
    FUN_00759970();
    fVar6 = *(float *)(iVar7 + 0xec);
    fVar1 = *(float *)(iVar7 + 0x104);
    fVar2 = *(float *)(iVar7 + 0x108);
    fVar3 = *(float *)(iVar7 + 0x100);
    fVar4 = *(float *)(iVar7 + 0xf0);
    fVar5 = *(float *)(iVar7 + 0x108);
    FUN_004151c0();
    *(float *)(iVar7 + 0x114) = (fVar6 - fVar1) - fVar2 * fVar3;
    *(float *)(iVar7 + 0x110) = fVar4 - fVar5;
    *(undefined4 *)(iVar7 + 0x10c) = 0;
  }
  return;
}



// ?Cleanup@CameraModeTwoObjects@@UAEXXZ @ 0x004411e0

void _Cleanup_CameraModeTwoObjects__UAEXXZ(void)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  float10 fVar4;
  float10 fVar5;
  float *pfVar6;
  float fStack_74;
  float fStack_70;
  float fStack_6c;
  uint uStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  iVar2 = *(int *)(in_ECX + 4);
  FUN_0043a530(*(undefined4 *)(iVar2 + 0x118),*(undefined4 *)(iVar2 + 0x148),
               *(undefined4 *)(iVar2 + 0x178));
  fStack_3c = fStack_24;
  iVar2 = *(int *)(in_ECX + 4);
  fStack_38 = fStack_20;
  fStack_34 = fStack_1c;
  FUN_0043a530(*(undefined4 *)(iVar2 + 0x88),*(undefined4 *)(iVar2 + 0xb8),
               *(undefined4 *)(iVar2 + 0xe8));
  fStack_30 = fStack_24;
  fStack_2c = fStack_20;
  fStack_28 = fStack_1c;
  fStack_64 = SQRT((fStack_3c - fStack_24) * (fStack_3c - fStack_24) +
                   (fStack_38 - fStack_20) * (fStack_38 - fStack_20) +
                   (fStack_34 - fStack_1c) * (fStack_34 - fStack_1c));
  FUN_0043a700(&fStack_30,&fStack_3c,&fStack_70,&fStack_74);
  FUN_0043a530(fStack_30 - fStack_3c,fStack_2c - fStack_38,fStack_28 - fStack_34);
  if (((fStack_54 != 0.0) || (fStack_50 != 0.0)) || (fStack_4c != 0.0)) {
    fVar1 = 1.0 / SQRT(fStack_54 * fStack_54 + fStack_4c * fStack_4c + fStack_50 * fStack_50);
    fStack_54 = fStack_54 * fVar1;
    fStack_50 = fStack_50 * fVar1;
    fStack_4c = fStack_4c * fVar1;
  }
  fStack_44 = 0.0;
  fStack_48 = fStack_4c - 0.0;
  fStack_40 = 0.0 - fStack_54;
  if ((fStack_48 != 0.0) || (fStack_40 != 0.0)) {
    fVar1 = 1.0 / SQRT(fStack_48 * fStack_48 + fStack_40 * fStack_40 + 0.0);
    fStack_48 = fVar1 * fStack_48;
    fStack_44 = fVar1 * 0.0;
    fStack_40 = fStack_40 * fVar1;
  }
  fStack_24 = fStack_40 * fStack_50 - fStack_44 * fStack_4c;
  fStack_20 = fStack_4c * fStack_48 - fStack_40 * fStack_54;
  fStack_1c = fStack_44 * fStack_54 - fStack_50 * fStack_48;
  if (((fStack_24 != 0.0) || (fStack_20 != 0.0)) || (fStack_1c != 0.0)) {
    fVar1 = 1.0 / SQRT(fStack_24 * fStack_24 + fStack_20 * fStack_20 + fStack_1c * fStack_1c);
    fStack_24 = fVar1 * fStack_24;
    fStack_20 = fStack_20 * fVar1;
    fStack_1c = fStack_1c * fVar1;
  }
  fStack_6c = (float)((float10)DAT_00b5a228 * (float10)0.001);
  fVar5 = (float10)1.4426950408889634 * (float10)DAT_00b5a228 * (float10)0.001 * (float10)-5.0;
  fVar4 = ROUND(fVar5);
  fVar5 = (float10)f2xm1(fVar5 - fVar4);
  fVar4 = (float10)fscale((float10)1 + fVar5,fVar4);
  *(float *)(in_ECX + 8) = (float)(fVar4 * (float10)*(float *)(in_ECX + 8));
  fStack_60 = DAT_00d5c370;
  fStack_5c = DAT_00d5c374;
  iVar2 = FUN_00527d30();
  if (*(int *)(iVar2 + 0x3ac) == 0x14) {
    uStack_68 = DAT_00d5c108 >> 0x10;
    fStack_70 = ((float)(int)fStack_60 / (float)(DAT_00d5c108 & 0xffff) - 0.5) * fStack_6c * 1.1 +
                fStack_70;
    fStack_74 = fStack_74 - ((float)(int)fStack_5c / (float)uStack_68 - 0.5) * fStack_6c * 1.1;
    *(float *)(in_ECX + 8) = fStack_6c + *(float *)(in_ECX + 8);
  }
  fVar1 = *(float *)(in_ECX + 8);
  FUN_0043a530(fVar1 * fStack_54,fStack_50 * fVar1,fStack_4c * fVar1);
  FUN_0043a530(fStack_60 * 5.0,fStack_5c * 5.0,fStack_58 * 5.0);
  fStack_3c = fStack_18 + fStack_3c;
  fStack_38 = fStack_14 + fStack_38;
  fStack_34 = fStack_10 + fStack_34;
  fStack_30 = fStack_18 + fStack_30;
  fStack_2c = fStack_14 + fStack_2c;
  fStack_28 = fStack_10 + fStack_28;
  if ((*(uint *)(in_ECX + 0x14) & 0x20) == 0) {
    if ((*(uint *)(in_ECX + 0x14) & 0x10) == 0) {
      uVar3 = FUN_00441b90(&fStack_24,(float)*(int *)(in_ECX + 0x10));
      pfVar6 = &fStack_c;
      FUN_00441b90(&fStack_60,(float)*(int *)(in_ECX + 0xc));
      FUN_00440270(pfVar6,uVar3);
      FUN_0075d6c0(0x3d4ccccd);
      FUN_00441bc0(&fStack_c);
      FUN_00441bc0(&fStack_c);
    }
    else {
      uStack_68 = DAT_00d5c108 & 0xffff;
      fStack_70 = fStack_70 - ((float)*(int *)(in_ECX + 0xc) * -3.1415927) / (float)uStack_68;
      fStack_74 = fStack_74 - (float)*(int *)(in_ECX + 0x10) * 0.002;
      if (fStack_74 <= -3.0) {
        fStack_74 = -3.0;
      }
      else if (3.0 <= fStack_74) {
        fStack_74 = 3.0;
      }
    }
  }
  else {
    fVar1 = (float)*(int *)(in_ECX + 0x10);
    FUN_0043a530(fVar1 * fStack_24,fStack_20 * fVar1,fStack_1c * fVar1);
    fVar1 = (float)*(int *)(in_ECX + 0xc);
    FUN_0043a530(fVar1 * fStack_48,fStack_44 * fVar1,fStack_40 * fVar1);
    FUN_0043a530(fStack_60 - fStack_c,fStack_5c - fStack_8,fStack_58 - fStack_4);
    fStack_20 = fStack_20 * 0.05;
    fStack_1c = fStack_1c * 0.05;
    fStack_3c = fStack_24 * 0.05 + fStack_3c;
    fStack_38 = fStack_20 + fStack_38;
    fStack_34 = fStack_1c + fStack_34;
    fStack_30 = fStack_24 * 0.05 + fStack_30;
    fStack_2c = fStack_20 + fStack_2c;
    fStack_28 = fStack_1c + fStack_28;
  }
  *(undefined4 *)(in_ECX + 0x10) = 0;
  *(undefined4 *)(in_ECX + 0xc) = 0;
  FUN_0043a640(&fStack_30,&fStack_3c,fStack_64,fStack_70,fStack_74);
  FUN_00441900(&fStack_30,0x3e4ccccd);
  FUN_00441900(&fStack_3c,0x3e4ccccd);
  FUN_00441870(&fStack_30);
  FUN_00441870(&fStack_3c);
  return;
}



// ?Cleanup@CameraModeTwoObjects@@UAEXXZ @ 0x00446790

undefined4 _Cleanup_CameraModeTwoObjects__UAEXXZ(void)

{
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x44) != 0) && (*(int *)(in_ECX + 0x48) != 0)) {
    return 1;
  }
  return 0;
}



// ?CanExist@CameraModeTwoObjects@@UAE_NXZ @ 0x00446890

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Removing unreachable block (ram,0x00449623) */
/* WARNING: Removing unreachable block (ram,0x00449634) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _CanExist_CameraModeTwoObjects__UAE_NXZ(void)

{
  int *piVar1;
  float fVar2;
  float fVar3;
  undefined4 *puVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  ushort uVar8;
  double dVar9;
  char cVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  int *piVar14;
  float *pfVar15;
  int *piVar16;
  int *in_ECX;
  float fVar17;
  uint uVar18;
  float *pfVar19;
  float *pfVar20;
  bool bVar21;
  float10 fVar22;
  float10 fVar23;
  float10 fVar24;
  undefined4 in_stack_fffffe5c;
  undefined4 uVar25;
  undefined4 uVar26;
  undefined4 uVar27;
  undefined4 uVar28;
  undefined4 uVar29;
  undefined8 uVar30;
  float fStack_178;
  float local_174;
  float local_170;
  float local_16c;
  undefined4 uStack_168;
  float fStack_164;
  float fStack_160;
  float fStack_15c;
  float fStack_158;
  float fStack_154;
  float fStack_150;
  float local_14c;
  float local_148;
  float local_144;
  char cStack_13e;
  char local_13d;
  float fStack_13c;
  float fStack_138;
  float fStack_134;
  float fStack_130;
  float fStack_12c;
  float fStack_128;
  float fStack_124;
  float fStack_120;
  float fStack_11c;
  undefined8 uStack_118;
  float fStack_110;
  undefined4 uStack_104;
  undefined8 uStack_100;
  float fStack_f8;
  undefined8 local_f0;
  float fStack_e8;
  float local_dc;
  float fStack_d8;
  float fStack_d4;
  float fStack_d0;
  float fStack_cc;
  char cStack_c5;
  float fStack_c4;
  float fStack_c0;
  char cStack_b9;
  undefined8 uStack_b8;
  float fStack_a8;
  int *local_a4;
  float fStack_a0;
  float fStack_9c;
  int *piStack_98;
  float fStack_94;
  float local_90;
  float local_8c;
  float local_88;
  undefined1 auStack_84 [12];
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  float afStack_6c [4];
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  float fStack_40;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  undefined1 auStack_30 [12];
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  undefined1 auStack_18 [4];
  undefined1 auStack_14 [16];
  
  local_13d = '\0';
  if (in_ECX[0x11] != 0) {
    in_ECX[0x18] = 0;
    if (in_ECX[0x19] == 1) {
      piVar16 = in_ECX + 0x17;
      *piVar16 = *piVar16 - *(int *)(DAT_00c22ca4 + 0x201e04);
      if (*piVar16 < 0) {
        in_ECX[0x19] = 2;
      }
    }
    if (in_ECX[0x19] == 2) {
      FUN_00446760();
    }
    else if (((int *)in_ECX[0x12] == (int *)0x0) ||
            (iVar12 = (**(code **)(*(int *)in_ECX[0x12] + 0x2c))(), iVar12 == 0)) {
      FUN_00446730();
      in_ECX[0x12] = 0;
    }
  }
  if ((DAT_00b7c8fc & 1) == 0) {
    _DAT_00b7c8f0 = _DAT_008fccf4;
    DAT_00b7c8fc = DAT_00b7c8fc | 1;
    _DAT_00b7c8f8 = _DAT_008fccf4;
    _DAT_00b7c8f4 = 0;
    FUN_00733dd6();
  }
  uVar11 = FUN_00527d00();
  local_f0 = (double)(ulonglong)uVar11;
  iVar12 = in_ECX[1];
  local_dc = (float)(longlong)local_f0 * 0.001;
  local_16c = *(float *)(iVar12 + 0x17c);
  local_170 = *(float *)(iVar12 + 0x14c);
  local_174 = *(float *)(iVar12 + 0x11c);
  iVar12 = in_ECX[1];
  local_144 = *(float *)(iVar12 + 0xec);
  local_148 = *(float *)(iVar12 + 0xbc);
  local_14c = *(float *)(iVar12 + 0x8c);
  if (((in_ECX[0x11] != 0) && (in_ECX[0x12] != 0)) && ((in_ECX[0x23] == 0 || (in_ECX[0x23] == 2))))
  {
    in_ECX[0x4b] = (int)local_14c;
    in_ECX[0x4c] = (int)local_148;
    in_ECX[0x4d] = (int)local_144;
    *(undefined1 *)(in_ECX + 0x13) = 0;
    *(undefined1 *)((int)in_ECX + 0x4d) = 0;
    *(undefined1 *)((int)in_ECX + 0x4e) = 0;
  }
  iVar12 = in_ECX[1];
  local_70 = *(undefined4 *)(iVar12 + 0x178);
  local_74 = *(undefined4 *)(iVar12 + 0x148);
  local_78 = *(undefined4 *)(iVar12 + 0x118);
  if ((char)in_ECX[0x22] != '\0') {
    in_ECX[0x4b] = in_ECX[0x1f];
    in_ECX[0x4c] = in_ECX[0x20];
    in_ECX[0x4d] = in_ECX[0x21];
    local_14c = (float)in_ECX[0x4b];
    local_148 = (float)in_ECX[0x4c];
    local_144 = (float)in_ECX[0x4d];
  }
  DAT_00b7c948 = DAT_00b7c978;
  _DAT_00b7c944 = DAT_00b7c93c;
  DAT_00b7c940 = DAT_00b7c974;
  piVar16 = in_ECX + 0x2a;
  *piVar16 = 0;
  in_ECX[0x2b] = 0;
  local_90 = local_174;
  local_8c = local_170;
  local_88 = local_16c;
  if (in_ECX[0xbb] == 0) {
    iVar12 = FUN_00527d30();
    iVar12 = *(int *)(iVar12 + 0x3ac);
    DAT_00b7c978 = (uint)(iVar12 == 0x14);
    DAT_00b7c93c = FUN_0045b7e0();
    DAT_00b7c938 = (uint)(iVar12 == 0x16);
    if (iVar12 == 0x1b) {
      DAT_00b7c978 = FUN_0045b7e0();
    }
    iVar12 = DAT_00d5c128;
    iVar13 = (*(code *)0x4accf5d)();
    if (((iVar12 == iVar13) && (((byte)DAT_00d5c3b4 & 1) != 0)) && (((byte)DAT_00d5c3b4 & 2) != 0))
    {
      DAT_00b7c938 = 1;
      DAT_00b7c93c = 0;
      DAT_00b7c978 = 0;
    }
    DAT_00b7f9ec = 0;
    iVar12 = FUN_00527d30();
    if (*(int *)(iVar12 + 0x400) != 0) {
      DAT_00b7f9ec = 1;
    }
    if (DAT_00b7c93c != 0) {
      DAT_00b7f9ec = 2;
    }
    if (DAT_00b7c938 != 0) {
      in_ECX[0xb5] = in_ECX[0x2c];
      in_ECX[0xb6] = in_ECX[0x2d];
    }
    DAT_00b7c974 = FUN_0045b7e0();
    *piVar16 = DAT_00b80158;
    in_ECX[0x2b] = DAT_00b8015c;
    iVar12 = DAT_00d5c374;
    DAT_00b80158 = 0;
    DAT_00b8015c = 0;
    local_a4 = in_ECX + 0x2c;
    DAT_00d5c394 = 0;
    DAT_00d5c398 = 0;
    *local_a4 = DAT_00d5c370;
    in_ECX[0x2d] = iVar12;
    if ((DAT_00b7c938 != 0) || ((DAT_00b7c978 != 0 && (DAT_00b7c93c != 0)))) {
      DAT_00b7c938 = 1;
      DAT_00b7c93c = 0;
      DAT_00b7c978 = 0;
    }
    if (in_ECX[0xbc] != 0) {
      if (((DAT_00b7c978 == 0) && (DAT_00b7c93c == 0)) &&
         (((DAT_00b7c974 == 0 &&
           ((((DAT_00b7c938 == 0 && (_DAT_00b7c95c == 0.0)) && (_DAT_00b7c954 == 0.0)) &&
            ((_DAT_00b7c958 == 0.0 && (_DAT_00b7c94c == 0.0)))))) && (_DAT_00b7c950 == 0.0)))) {
        in_ECX[0xbc] = 0;
      }
      else {
        DAT_00b7c938 = 0;
        DAT_00b7c974 = 0;
        DAT_00b7c93c = 0;
        DAT_00b7c978 = 0;
        _DAT_00b7c950 = 0.0;
        _DAT_00b7c94c = 0.0;
        _DAT_00b7c954 = 0.0;
        _DAT_00b7c958 = 0.0;
        _DAT_00b7c95c = 0.0;
      }
    }
    uVar11 = (**(code **)(*in_ECX + 0x58))();
    if ((uVar11 & 0x20) == 0) {
      DAT_00b7c974 = 0;
      DAT_00b7c938 = 0;
    }
  }
  else {
    *piVar16 = 0;
    in_ECX[0x2b] = 0;
    DAT_00d5c394 = 0;
    DAT_00d5c398 = 0;
    DAT_00b7c974 = 0;
    DAT_00b7c938 = 0;
    DAT_00b7c93c = 0;
    DAT_00b7c978 = 0;
    iVar12 = FUN_00527d30();
    iVar12 = *(int *)(iVar12 + 0x3a0);
    local_a4 = in_ECX + 0x2c;
    *local_a4 = *(int *)(iVar12 + 0x485c);
    in_ECX[0x2d] = *(int *)(iVar12 + 0x4860);
    in_ECX[0x25] = 0;
    DAT_00b7c970 = 0;
    _DAT_00b7c950 = 0.0;
    _DAT_00b7c94c = 0.0;
    _DAT_00b7c954 = 0.0;
    _DAT_00b7c958 = 0.0;
    _DAT_00b7c95c = 0.0;
  }
  piVar14 = in_ECX + 0x2c;
  FUN_0051dba0();
  uStack_b8._0_4_ = 1.4013e-45;
  fStack_178 = 1.4013e-45;
  iVar12 = *piVar14;
  if (((iVar12 < 1) || ((int)((DAT_00d5c108 & 0xffff) - 1) <= iVar12)) && (DAT_00d5c164 == 0)) {
    in_ECX[0x30] = in_ECX[0x30] + *piVar16;
    uStack_b8._0_4_ = 0.0;
  }
  else {
    in_ECX[0x30] = iVar12;
  }
  iVar12 = in_ECX[0x2d];
  if (iVar12 < 1) {
LAB_00446e39:
    if (DAT_00d5c164 != 0) goto LAB_00446e41;
    in_ECX[0x31] = in_ECX[0x31] + in_ECX[0x2b];
    fStack_178 = 0.0;
  }
  else {
    uStack_118 = (double)CONCAT62(uStack_118._2_6_,DAT_00d5c108._2_2_);
    if ((int)(((uint)(float)uStack_118 & 0xffff) - 1) <= iVar12) goto LAB_00446e39;
LAB_00446e41:
    in_ECX[0x31] = iVar12;
  }
  in_ECX[0xb7] = in_ECX[0xb7] + *piVar16;
  in_ECX[0xb8] = in_ECX[0xb8] + in_ECX[0x2b];
  if (DAT_00b7c974 != 0) {
    DAT_00b7c93c = 0;
    DAT_00b7c978 = 0;
    _DAT_00b7c950 = (float)*piVar16 * _DAT_008fcce8 + _DAT_00b7c950;
    _DAT_00b7c94c = _DAT_00b7c94c - (float)in_ECX[0x2b] * _DAT_008fcce4;
    if (DAT_00b7c940 == 0) {
      in_ECX[0x2e] = *piVar14;
      in_ECX[0x2f] = in_ECX[0x2d];
    }
    else {
      *piVar14 = in_ECX[0x2e];
      in_ECX[0x2d] = in_ECX[0x2f];
    }
  }
  if ((DAT_00b7c8fc & 2) == 0) {
    DAT_00b7c8fc = DAT_00b7c8fc | 2;
    FUN_00733dd6();
  }
  iVar12 = FUN_0045b7e0();
  if ((iVar12 == 0) || (iVar12 = FUN_0045b7e0(), iVar12 == 0)) {
    uVar27 = 0;
  }
  else {
    if ((DAT_00b7c8fc & 4) == 0) {
      DAT_00b7c8fc = DAT_00b7c8fc | 4;
      FUN_00733dd6();
    }
    if ((DAT_00b7c8fc & 8) == 0) {
      DAT_00b7c8fc = DAT_00b7c8fc | 8;
      FUN_00733dd6();
    }
    if ((DAT_00b7c8fc & 0x10) == 0) {
      DAT_00b7c8fc = DAT_00b7c8fc | 0x10;
      FUN_00733dd6();
    }
    if ((DAT_00b7c8fc & 0x20) == 0) {
      DAT_00b7c8fc = DAT_00b7c8fc | 0x20;
      FUN_00733dd6();
    }
    if (DAT_00b7c988 < 0.01) {
      _DAT_00b7c8e8 = *piVar14;
      _DAT_00b7c8ec = in_ECX[0x2d];
      in_ECX[0x7b] = (int)local_174;
      in_ECX[0x7c] = (int)local_170;
      in_ECX[0x7d] = (int)local_16c;
      in_ECX[0x81] = (int)local_14c;
      in_ECX[0x82] = (int)local_148;
      in_ECX[0x83] = (int)local_144;
      iVar12 = FUN_00527d30();
      iVar12 = *(int *)(*(int *)(iVar12 + 0x3a0) + 0x482c);
      DAT_00b7c8d8 = *(float *)(iVar12 + 0x38);
      DAT_00b7c8dc = *(float *)(iVar12 + 0x3c);
      DAT_00b7c8e0 = *(float *)(iVar12 + 0x40);
      iVar12 = FUN_00527d30();
      piVar16 = *(int **)(iVar12 + 0x3c8);
      DAT_00b7fa04 = piVar16;
      if (piVar16 != (int *)0x0) {
        uStack_118 = (double)CONCAT44(uStack_118._4_4_,piVar16[7]);
        fVar22 = (float10)FUN_00760fd0();
        DAT_00b7c8dc = (float)(fVar22 + (float10)(float)uStack_118);
        DAT_00b7c8d8 = (float)piVar16[5] * 0.00015258789;
        DAT_00b7c8e0 = (float)piVar16[6] * 0.00015258789;
      }
      fStack_138 = (float)__ftol();
      fStack_134 = (float)__ftol();
      fStack_130 = 0.0;
      fVar22 = (float10)FUN_00760fd0();
      DAT_00b7c8dc = (float)fVar22;
      FUN_0043a700(&local_174,&local_14c,&DAT_00b7c89c,&DAT_00b7c8a0);
      fVar17 = SQRT((local_174 - local_14c) * (local_174 - local_14c) +
                    (local_170 - local_148) * (local_170 - local_148) +
                    (local_16c - local_144) * (local_16c - local_144));
      if (fVar17 <= 300.0) {
        if (50.0 <= fVar17) {
          _DAT_008fcd8c = 0x41700000;
        }
        else {
          _DAT_008fcd8c = 0x41200000;
        }
      }
      else {
        _DAT_008fcd8c = 0x42480000;
      }
      DAT_00b7c8a0 = (DAT_00b7c8a0 + 2.3561945) * 0.25;
      DAT_00b7c898 = _DAT_008fcd8c;
      FUN_0043a640(&fStack_128,&local_14c,_DAT_008fcd8c,DAT_00b7c89c,DAT_00b7c8a0);
      _DAT_00b7c8a8 = fStack_128 - local_14c;
      _DAT_00b7c8ac = fStack_124 - local_148;
      _DAT_00b7c8b0 = fStack_120 - local_144;
      if (((_DAT_00b7c8a8 != 0.0) || (_DAT_00b7c8ac != 0.0)) || (_DAT_00b7c8b0 != 0.0)) {
        fVar17 = 1.0 / SQRT(_DAT_00b7c8ac * _DAT_00b7c8ac +
                            _DAT_00b7c8b0 * _DAT_00b7c8b0 + _DAT_00b7c8a8 * _DAT_00b7c8a8);
        _DAT_00b7c8a8 = fVar17 * _DAT_00b7c8a8;
        _DAT_00b7c8ac = fVar17 * _DAT_00b7c8ac;
        _DAT_00b7c8b0 = fVar17 * _DAT_00b7c8b0;
      }
      _DAT_00b7c8c8 = _DAT_00b7c8b0 - 0.0;
      _DAT_00b7c8cc = 0.0;
      _DAT_00b7c8d0 = 0.0 - _DAT_00b7c8a8;
      if ((_DAT_00b7c8c8 != 0.0) || (_DAT_00b7c8d0 != 0.0)) {
        fVar17 = 1.0 / SQRT(_DAT_00b7c8c8 * _DAT_00b7c8c8 + _DAT_00b7c8d0 * _DAT_00b7c8d0 + 0.0);
        _DAT_00b7c8c8 = fVar17 * _DAT_00b7c8c8;
        _DAT_00b7c8cc = fVar17 * 0.0;
        _DAT_00b7c8d0 = _DAT_00b7c8d0 * fVar17;
      }
      fStack_158 = _DAT_00b7c8d0 * _DAT_00b7c8ac - _DAT_00b7c8cc * _DAT_00b7c8b0;
      fStack_154 = _DAT_00b7c8b0 * _DAT_00b7c8c8 - _DAT_00b7c8d0 * _DAT_00b7c8a8;
      fStack_150 = _DAT_00b7c8cc * _DAT_00b7c8a8 - _DAT_00b7c8ac * _DAT_00b7c8c8;
      if (((fStack_158 != 0.0) || (fStack_154 != 0.0)) ||
         (_DAT_00b7c8b8 = fStack_158, _DAT_00b7c8bc = fStack_154, _DAT_00b7c8c0 = fStack_150,
         fStack_150 != 0.0)) {
        _DAT_00b7c8c0 =
             1.0 / SQRT(fStack_158 * fStack_158 + fStack_154 * fStack_154 + fStack_150 * fStack_150)
        ;
        _DAT_00b7c8b8 = _DAT_00b7c8c0 * fStack_158;
        _DAT_00b7c8bc = fStack_154 * _DAT_00b7c8c0;
        _DAT_00b7c8c0 = fStack_150 * _DAT_00b7c8c0;
      }
      in_ECX[0xb5] = *piVar14;
      in_ECX[0xb6] = in_ECX[0x2d];
    }
    if (DAT_00b7fa04 != (int *)0x0) {
      iVar12 = (**(code **)(*DAT_00b7fa04 + 0x2c))();
      piVar16 = DAT_00b7fa04;
      if (iVar12 == 0) {
        DAT_00b7fa04 = (int *)0x0;
      }
      else {
        piVar1 = DAT_00b7fa04 + 5;
        uStack_118 = (double)CONCAT44(uStack_118._4_4_,DAT_00b7fa04[7]);
        fVar22 = (float10)FUN_00760fd0();
        DAT_00b7c8dc = (float)(fVar22 + (float10)(float)uStack_118);
        DAT_00b7c8d8 = (float)*piVar1 * 0.00015258789;
        DAT_00b7c8e0 = (float)piVar16[6] * 0.00015258789;
        FUN_00527d30();
        FUN_005d09b0();
      }
    }
    fStack_138 = (float)__ftol();
    fStack_134 = (float)__ftol();
    fStack_130 = 0.0;
    fVar22 = (float10)FUN_00760fd0();
    DAT_00b7c8dc = (float)fVar22;
    in_ECX[0x7e] = (int)DAT_00b7c8d8;
    in_ECX[0x7f] = (int)DAT_00b7c8dc;
    in_ECX[0x80] = (int)DAT_00b7c8e0;
    FUN_0043a640(in_ECX + 0x78,in_ECX + 0x7e,DAT_00b7c898,DAT_00b7c89c,DAT_00b7c8a0);
    uVar27 = 0x3f800000;
  }
  FUN_00406240(uVar27,0x3f00000000000000);
  _DAT_00b7c99c = _DAT_00b7c99c + local_dc;
  if (_DAT_00b7c99c < DAT_00b7c9a0) {
    fVar17 = _DAT_00b7c99c * _DAT_00b7c99c * 0.5;
    fVar5 = _DAT_00b7c99c * fVar17 * 0.33333334;
    _DAT_00b7c994 =
         _DAT_00b7c9b0 * fVar17 + _DAT_00b7c9b4 * fVar5 + _DAT_00b7c9ac * _DAT_00b7c99c +
         _DAT_00b7c9a8;
    DAT_00b7c988 = _DAT_00b7c9ac * fVar17 +
                   _DAT_00b7c9b0 * fVar5 +
                   _DAT_00b7c9a8 * _DAT_00b7c99c + fVar17 * fVar17 * 0.16666667 * _DAT_00b7c9b4 +
                   _DAT_00b7c9a4;
  }
  else {
    DAT_00b7c988 = DAT_00b7c98c;
    _DAT_00b7c994 = DAT_00b7c990;
    _DAT_00b7c998 = 0;
    _DAT_00b7c99c = DAT_00b7c9a0;
  }
  fStack_11c = 0.0;
  if ((in_ECX[0xbb] == 0) && (DAT_00b7c988 < 0.01)) {
    iVar12 = FUN_0045b7e0();
    if (iVar12 == 0) {
      iVar12 = FUN_0045b7e0();
      if ((iVar12 != 0) && (fStack_11c = DAT_00b80160, DAT_00b80160 == 0.0)) {
        fStack_11c = 1.68156e-43;
      }
    }
    else if (DAT_00b80160 == 0.0) {
      fStack_11c = -NAN;
    }
    else {
      fStack_11c = DAT_00b80160;
    }
    DAT_00b80160 = 0.0;
  }
  _DAT_00b7c954 = _DAT_00b7c954 - (float)(int)fStack_11c * _DAT_008fccdc;
  if (DAT_00b7c938 == 0) {
    DAT_00b7fa08 = 0;
    _DAT_00b7fa0c = *piVar14;
  }
  else {
    uStack_118 = (double)(CONCAT44(uStack_118._4_4_,DAT_00d5c108) & 0xffffffff0000ffff);
    _DAT_00b7c954 = (float)in_ECX[0x2b] * _DAT_008fcce0 + _DAT_00b7c954;
    uVar11 = in_ECX[0x2a] >> 0x1f;
    if ((float)(int)(float)uStack_118 * _DAT_008fcd40 <
        (float)(int)((in_ECX[0x2a] ^ uVar11) - uVar11)) {
      DAT_00b7fa08 = 1;
    }
    else {
      uVar11 = *piVar14 - _DAT_00b7fa0c >> 0x1f;
      if ((float)(int)((*piVar14 - _DAT_00b7fa0c ^ uVar11) - uVar11) <=
          (float)(int)(float)uStack_118 * _DAT_008fcd40) {
        if (DAT_00b7fa08 == 0) goto LAB_0044778c;
      }
      else {
        DAT_00b7fa08 = 1;
      }
    }
    _DAT_00b7c950 = (float)in_ECX[0x2a] * _DAT_008fcce0 + _DAT_00b7c950;
  }
LAB_0044778c:
  if ((((_DAT_00b7c954 != 0.0) || (_DAT_00b7c95c != 0.0)) || (_DAT_00b7c958 != 0.0)) ||
     (((_DAT_00b7c950 != 0.0 || (_DAT_00b7c94c != 0.0)) || (DAT_00b7c970 = 0, DAT_00b7c974 != 0))))
  {
    DAT_00b7c970 = 1;
  }
  if (((_DAT_00b7c954 != 0.0) || (_DAT_00b7c950 != 0.0)) ||
     ((_DAT_00b7c94c != 0.0 ||
      (uStack_104 = (float)((uint)uStack_104 & 0xffffff), DAT_00b7c974 != 0)))) {
    uStack_104 = (float)CONCAT13(1,(uint3)uStack_104);
  }
  uStack_118._0_4_ = (float)(DAT_00d5c108 & 0xffff);
  cStack_b9 = '\0';
  uStack_104._0_3_ = CONCAT12(1,(ushort)uStack_104);
  cStack_13e = '\0';
  in_ECX[0x26] = (int)((float)*piVar14 / (float)(int)(float)uStack_118 - 0.5);
  uVar8 = DAT_00d5c108._2_2_;
  fVar17 = (float)(uint)DAT_00d5c108._2_2_;
  fStack_cc = fVar17;
  if (*(int *)(*(int *)(DAT_00c22ca4 + 0x24c118) + 0x45e8) != 0) {
    iVar12 = __ftol();
    fStack_cc = (float)((int)fVar17 - iVar12);
  }
  in_ECX[0x27] = (int)((float)(int)(in_ECX[0x2d] - (uint)(uVar8 >> 1)) / (float)(int)fStack_cc);
  in_ECX[0x6e] = (int)((float)in_ECX[0x2a] / (float)(int)fStack_cc + (float)in_ECX[0x6e]);
  uStack_118 = (double)(CONCAT44(uStack_118._4_4_,DAT_00d5c108) & 0xffffffff0000ffff);
  in_ECX[0x6f] = (int)((float)in_ECX[0x2b] / (float)(DAT_00d5c108 & 0xffff) + (float)in_ECX[0x6f]);
  in_ECX[0x28] = (int)ABS((float)in_ECX[0x26]);
  in_ECX[0x29] = (int)ABS((float)in_ECX[0x27]);
  iVar12 = FUN_0075f1a0(in_ECX + 0x35,1,0);
  in_ECX[0x51] = iVar12;
  uVar25 = 1;
  piVar16 = in_ECX + 0x3e;
  local_f0 = (double)(ulonglong)CONCAT24(DAT_00d5c108._2_2_ >> 1,(DAT_00d5c108 & 0xffff) >> 1);
  piVar14 = in_ECX + 0x3c;
  uVar27 = 0x4479a3;
  iVar12 = FUN_0075f1a0(piVar16,1,0);
  in_ECX[0x32] = iVar12;
  fStack_138 = (float)__ftol();
  fStack_134 = (float)__ftol();
  fStack_130 = 0.0;
  fVar22 = (float10)FUN_00760fd0();
  in_ECX[0x34] = (int)(float)fVar22;
  fStack_138 = (float)__ftol();
  fStack_134 = (float)__ftol();
  fStack_130 = 0.0;
  fVar22 = (float10)FUN_00760fd0();
  in_ECX[0x3d] = (int)(float)fVar22;
  if (_DAT_008fcccc * 3.0 < (float)in_ECX[0x1e]) {
    uVar30 = CONCAT44(0x3f400000,uVar25);
    uVar25 = 0x447a55;
    FUN_004402a0(piVar14);
    FUN_004402a0(&local_174);
    cVar10 = FUN_004462f0(in_stack_fffffe5c,uVar25,piVar14,uVar27,piVar16,uVar30);
    if ((cVar10 != '\0') && ((*(byte *)(in_ECX + 0x23) & 1) != 0)) {
      FUN_00446760();
      FUN_00445570(&local_174,&local_14c,1);
    }
  }
  if ((in_ECX[0x32] != 0) && (in_ECX[0x11] == 0)) {
    piVar16 = *(int **)(DAT_00c22ca4 + 0x201d38);
    while (piVar16 != (int *)0x0) {
      piVar14 = (int *)(**(code **)(*piVar16 + 0x100))();
      FUN_00760fd0();
      fStack_12c = (float)*piVar14 * 0.00015258789;
      fStack_124 = (float)piVar14[1] * 0.00015258789;
      fStack_d0 = (fStack_12c - fStack_178) * (fStack_12c - fStack_178) +
                  (fStack_124 - local_170) * (fStack_124 - local_170);
      fVar22 = (float10)(**(code **)(*piVar16 + 0x60))();
      fStack_11c = (float)fVar22;
      fVar22 = (float10)(**(code **)(*piVar16 + 0x60))();
      if ((float10)fStack_cc < fVar22 * (float10)(float)uStack_118) {
        fStack_cc = (fStack_128 - local_14c) * (fStack_128 - local_14c) +
                    (fStack_120 - local_144) * (fStack_120 - local_144);
        fVar22 = (float10)(**(code **)(*piVar16 + 0x60))();
        uStack_118 = (double)CONCAT44(uStack_118._4_4_,(float)fVar22);
        fVar22 = (float10)(**(code **)(*piVar16 + 0x60))();
        if ((((float10)fStack_cc < fVar22 * (float10)(float)uStack_118) && (piVar16[0xe] != 0)) &&
           (piVar16[0xf] != 0)) {
          if ((piVar16 != (int *)0x0) &&
             (iVar12 = in_ECX[0x18] + DAT_00b5a228, in_ECX[0x18] = iVar12, 1000 < iVar12)) {
            FUN_00446430();
          }
          break;
        }
      }
      if (piVar16 == (int *)0x0) {
        piVar16 = *(int **)(DAT_00c22ca4 + 0x201d38);
      }
      else {
        piVar16 = (int *)piVar16[0x12];
      }
    }
  }
  in_ECX[0xbd] = 0;
  for (puVar4 = DAT_00b7f9e8; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {
    fStack_cc = DAT_008fccd8 + DAT_008fccd8;
    if ((((float)puVar4[3] - local_174) * ((float)puVar4[3] - local_174) +
         ((float)puVar4[5] - local_16c) * ((float)puVar4[5] - local_16c) <
         (fStack_cc + (float)puVar4[6]) * (fStack_cc + (float)puVar4[6])) &&
       ((puVar4[8] != 0 || (local_170 - (float)puVar4[4] < fStack_cc + (float)puVar4[7])))) {
      puVar4[1] = in_ECX[0xbd];
      in_ECX[0xbd] = (int)puVar4;
    }
  }
  if (in_ECX[0x32] == 0) {
    in_ECX[0xb9] = in_ECX[0x70];
  }
  else {
    in_ECX[0xb9] = (int)SQRT(((float)in_ECX[0x3c] - local_174) * ((float)in_ECX[0x3c] - local_174) +
                             ((float)in_ECX[0x3d] - local_170) * ((float)in_ECX[0x3d] - local_170) +
                             ((float)in_ECX[0x3e] - local_16c) * ((float)in_ECX[0x3e] - local_16c));
  }
  if ((float)in_ECX[0xb9] < 10.0) {
    in_ECX[0xb9] = 0x41200000;
  }
  if (in_ECX[0x51] != 0) {
    FUN_00444d10(&local_174,&local_14c,in_ECX + 0x33);
  }
  uVar11 = in_ECX[0x2a] >> 0x1f;
  uVar18 = 0;
  fStack_a0 = 1.3744469;
  if ((2 < (int)((in_ECX[0x2a] ^ uVar11) - uVar11)) ||
     (uVar11 = in_ECX[0x2b] >> 0x1f, 2 < (int)((in_ECX[0x2b] ^ uVar11) - uVar11))) {
    in_ECX[0xba] = 0;
  }
  if (DAT_00b7c978 == 0) {
    if (DAT_00b7c948 != 0) {
      uVar18 = 0;
    }
  }
  else {
    uVar18 = 1;
  }
  if (DAT_00b7c970 != 0) {
    uVar18 = uVar18 | 2;
    if ((uStack_104._3_1_ == '\0') && (uVar18 == 3)) {
      uVar18 = 1;
      DAT_00b7c970 = 0;
      _DAT_00b7c958 = 0.0;
      _DAT_00b7c95c = 0.0;
    }
  }
  if ((((DAT_00b7c978 == 0) && (DAT_00b7c938 == 0)) && (DAT_00b7c974 == 0)) && (DAT_00b7c970 == 0))
  {
    in_ECX[0xba] = (int)(local_dc + (float)in_ECX[0xba]);
  }
  else {
    in_ECX[0xba] = 0;
  }
  if ((((DAT_00b7c970 == 0) && (uVar18 == 0)) &&
      ((DAT_00b7c978 == 0 && ((DAT_00b7c974 == 0 && (DAT_00b7c938 == 0)))))) ||
     ((*(undefined1 *)(in_ECX + 0x40) = 0, DAT_00b7c970 == 0 &&
      ((((DAT_00b7c978 == 0 && (DAT_00b7c974 == 0)) && (DAT_00b7c938 == 0)) ||
       ((uVar11 = in_ECX[0x2a] >> 0x1f, (int)((in_ECX[0x2a] ^ uVar11) - uVar11) < 3 &&
        (uVar11 = in_ECX[0x2b] >> 0x1f, (int)((in_ECX[0x2b] ^ uVar11) - uVar11) < 3)))))))) {
    DAT_00b7f9f0 = '\0';
  }
  else {
    DAT_00b7f9f0 = '\x01';
  }
  bVar21 = false;
  uStack_104 = (float)((uint)uStack_104 & 0xffffff);
  uVar11 = (**(code **)(*in_ECX + 0x58))();
  if (((uVar11 & 0x40) != 0) && ((uVar18 == 0 || (uVar18 == 2)))) {
    FUN_0043a700(&local_174,in_ECX + 0x4b,&uStack_100,&uStack_118);
    fVar17 = (DAT_008fc594 - (float)uStack_118) * 0.2;
    if (ABS(fVar17) <= 0.01) {
      _DAT_00b7c94c = 0.0;
    }
    else {
      _DAT_00b7c94c = -local_dc;
      if ((-local_dc < fVar17) && (_DAT_00b7c94c = local_dc, fVar17 < local_dc)) {
        _DAT_00b7c94c = fVar17;
      }
      _DAT_00b7c94c = _DAT_00b7c94c * -150.0;
      uStack_104 = (float)CONCAT13(1,(uint3)uStack_104);
      bVar21 = true;
      cStack_13e = '\x01';
      uVar18 = 2;
    }
  }
  if ((uVar18 != in_ECX[0x23]) || (DAT_00b7c940 != DAT_00b7c974)) {
    in_ECX[0x6b] = 0;
    if ((uVar18 != 0) && (in_ECX[0x51] == 0)) {
      in_ECX[0x33] = (int)local_14c;
      in_ECX[0x34] = (int)local_148;
      in_ECX[0x35] = (int)local_144;
    }
    FUN_00445570(&local_174,&local_14c,1);
    in_ECX[0x23] = uVar18;
  }
  if (bVar21) {
    in_ECX[0x23] = 0;
    FUN_00445190();
    in_ECX[0x23] = uVar18;
  }
  else {
    FUN_00445190();
  }
  if ((DAT_00b7f9f0 != '\0') && ((*(byte *)(in_ECX + 0x24) & 0x10) != 0)) {
    FUN_0043dcb0(0x102,&local_174,0);
  }
  fStack_d0 = (float)(-(uint)(fStack_11c != 0.0) & 8);
  if (DAT_00b7c974 != 0) {
    fStack_d0 = (float)((int)fStack_d0 + 0x10);
  }
  if ((DAT_00b7c970 != 0) && (DAT_00b7c974 == 0)) {
    fStack_d0 = (float)((int)fStack_d0 + 1);
  }
  if ((*(byte *)(in_ECX + 0x23) & 1) != 0) {
    fStack_d0 = (float)((int)fStack_d0 + 2);
  }
  if (DAT_00b7c938 != 0) {
    fStack_d0 = (float)((int)fStack_d0 + 4);
  }
  fVar17 = fStack_d0;
  fStack_c0 = _DAT_00b7c954 * 0.0015;
  uVar11 = (**(code **)(*in_ECX + 0x58))();
  if ((uVar11 & 4) == 0) {
    fStack_c0 = 0.0;
    _DAT_00b7c954 = 0.0;
  }
  if (local_148 <= local_170) {
    fVar5 = (local_170 - local_148) * 3.0;
    fStack_12c = DAT_008fcd1c;
    if (DAT_008fcd1c < fVar5) {
      if (fVar5 < DAT_008fcd20) goto LAB_004480c0;
      fStack_12c = DAT_008fcd20;
    }
  }
  else {
    fStack_12c = (local_148 - local_170) * 3.0;
    if (fStack_12c <= DAT_008fcd1c) {
      fStack_12c = DAT_008fcd1c;
    }
    else {
      fVar5 = DAT_008fcd1c * 4.0;
      if (DAT_008fcd1c * 4.0 <= fStack_12c) {
LAB_004480c0:
        fStack_12c = fVar5;
      }
    }
  }
  fStack_c0 = fStack_12c * fStack_c0;
  fStack_cc = fStack_c0 + (float)in_ECX[0x6a];
  fVar5 = DAT_008fccd8 + 0.1;
  if (DAT_008fccd8 + 0.1 <= fStack_cc) {
    fVar5 = fStack_cc;
  }
  in_ECX[0x6a] = (int)fVar5;
  if (((fVar5 == DAT_008fccd8 + 0.1) && (fStack_c0 != 0.0)) && (DAT_00b7f9f0 != '\0')) {
    FUN_0043dcb0(0x200,&local_174,0);
  }
  fStack_138 = (float)__ftol();
  fStack_134 = (float)__ftol();
  fStack_130 = 0.0;
  fVar22 = (float10)FUN_00760fd0();
  fStack_94 = (float)(fVar22 + (float10)3.0);
  if (DAT_00b7f9d4 == 0) {
    piStack_98 = (int *)0x46ea6000;
  }
  else {
    piStack_98 = (int *)DAT_008fcd6c;
  }
  if (DAT_00b7f9d0 == 0) {
    fStack_c4 = 30000.0;
  }
  else {
    fStack_c4 = DAT_008fcd68;
  }
  fStack_138 = (float)__ftol();
  fStack_134 = (float)__ftol();
  fStack_130 = 0.0;
  fVar22 = (float10)FUN_00760fd0();
  if (fVar22 + (float10)fStack_c4 <= (float10)(float)piStack_98) {
    fStack_138 = (float)__ftol();
    fStack_134 = (float)__ftol();
    fStack_130 = 0.0;
    fVar22 = (float10)FUN_00760fd0();
    fStack_9c = (float)(fVar22 + (float10)fStack_c4);
  }
  else {
    fStack_9c = (float)piStack_98;
  }
  if (fStack_c0 != 0.0) {
    FUN_0043dcb0(0x304,&local_174,fVar17);
    *(undefined1 *)(in_ECX + 0x13) = 1;
  }
  fVar2 = ABS(local_170 - fStack_9c);
  local_f0 = (double)fVar2;
  fVar5 = ABS(local_170 - fStack_94);
  if (fVar2 <= ABS(local_170 - fStack_94)) {
    fVar5 = fVar2;
  }
  in_ECX[0x71] = (int)fVar5;
  if (local_170 < local_148) {
    in_ECX[0x71] = 0;
  }
  piStack_98 = in_ECX + 0xb5;
  iVar12 = (*local_a4 - in_ECX[0xb5]) * (*local_a4 - in_ECX[0xb5]) +
           (in_ECX[0x2d] - in_ECX[0xb6]) * (in_ECX[0x2d] - in_ECX[0xb6]);
  uStack_118 = (double)CONCAT44(uStack_118._4_4_,iVar12);
  fStack_11c = SQRT((float)iVar12) * (float)in_ECX[0x6a] * 0.011;
  if (fStack_11c < 50.0) {
    fStack_11c = 50.0;
  }
  fStack_d4 = 0.0;
  pfVar15 = (float *)(in_ECX + 0x4b);
  FUN_0043a700(&local_174,pfVar15,&fStack_a8,&fStack_d8);
  fStack_13c = (float)in_ECX[0x6a];
  fStack_c4 = 0.0;
  fStack_cc = 0.0;
  iVar12 = FUN_00445fc0();
  if (((iVar12 != 0) && (in_ECX[0x23] == 0)) &&
     ((DAT_00b7c978 == 0 &&
      (cVar10 = FUN_00445fe0(&local_174,&local_14c,&fStack_a8,&fStack_d8,local_dc,fVar17),
      cVar10 != '\0')))) {
    fStack_c4 = 1.4013e-45;
    fStack_d4 = 1.4013e-45;
    if (((float)in_ECX[0x70] < 0.0) || (5000.0 < (float)in_ECX[0x70])) {
      FUN_00445570(&local_174,&local_14c,1);
    }
  }
  iVar12 = FUN_00445fc0();
  if (iVar12 == 0) {
    in_ECX[0x1c] = 0;
    in_ECX[0x1b] = 0;
    in_ECX[0x1a] = 0;
  }
  else {
    if (in_ECX[0x6b] < 7) {
      iVar12 = (int)(float)uStack_b8;
      if ((float)uStack_b8 == 0.0) {
LAB_004484ba:
        uStack_b8 = (double)CONCAT44(uStack_b8._4_4_,0xbe4ccccd);
      }
      else {
        uStack_b8 = (double)CONCAT44(uStack_b8._4_4_,0xc0e00000);
        if (fStack_178 == 0.0) goto LAB_004484ba;
      }
      if ((iVar12 == 0) || (fStack_178 == 0.0)) {
        fVar22 = (float10)-2.2;
      }
      else {
        fVar22 = (float10)-7.0;
      }
      fVar24 = (float10)1.4426950408889634 * (float10)(float)uStack_b8 * (float10)local_dc;
      fVar23 = ROUND(fVar24);
      fVar24 = (float10)f2xm1(fVar24 - fVar23);
      fVar23 = (float10)fscale((float10)1 + fVar24,fVar23);
      in_ECX[0x1a] = (int)(float)((float10)(float)in_ECX[0x1a] * fVar23);
      in_ECX[0x1b] = (int)(float)((float10)(float)in_ECX[0x1b] * fVar23);
      fVar22 = fVar22 * (float10)local_dc;
    }
    else {
      fVar23 = (float10)1.4426950408889634 * (float10)local_dc * (float10)-1.0;
      fVar22 = ROUND(fVar23);
      fVar23 = (float10)f2xm1(fVar23 - fVar22);
      fVar22 = (float10)fscale((float10)1 + fVar23,fVar22);
      in_ECX[0x1a] = (int)(float)((float10)(float)in_ECX[0x1a] * fVar22);
      in_ECX[0x1b] = (int)(float)((float10)(float)in_ECX[0x1b] * fVar22);
      fVar22 = (float10)local_dc * (float10)-2.0;
    }
    fVar23 = ROUND((float10)1.4426950408889634 * fVar22);
    fVar22 = (float10)f2xm1((float10)1.4426950408889634 * fVar22 - fVar23);
    fVar22 = (float10)fscale((float10)1 + fVar22,fVar23);
    in_ECX[0x1c] = (int)(float)(fVar22 * (float10)(float)in_ECX[0x1c]);
    fVar17 = (float)in_ECX[0x1a];
    if (fVar17 * fVar17 +
        (float)in_ECX[0x1b] * (float)in_ECX[0x1b] + (float)in_ECX[0x1c] * (float)in_ECX[0x1c] <
        _DAT_008fccc8) {
      in_ECX[0x1c] = 0;
      in_ECX[0x1b] = 0;
      in_ECX[0x1a] = 0;
    }
  }
  if ((in_ECX[0x23] == 2) || (in_ECX[0x23] == 3)) {
    uStack_104._0_3_ = CONCAT12(1,(ushort)uStack_104);
    if ((_DAT_00b7c950 != 0.0) && (uVar11 = (**(code **)(*in_ECX + 0x58))(), (uVar11 & 2) != 0)) {
      uStack_118 = (double)(CONCAT44(uStack_118._4_4_,DAT_00d5c108) & 0xffffffff0000ffff);
      fVar17 = (float)(int)(float)uStack_118;
      uStack_118 = (double)(CONCAT44(uStack_118._4_4_,DAT_00d5c108) & 0xffffffff0000ffff);
      fStack_a8 = (_DAT_00b7c950 * 3.1415927) / fVar17 + fStack_a8;
      in_ECX[0x14] = (int)((_DAT_00b7c950 * 3.1415927) / (float)(int)(float)uStack_118 +
                          (float)in_ECX[0x14]);
      if (0.01 < ABS(_DAT_00b7c950)) {
        FUN_0043dcb0(0x300,&local_174,fStack_d0);
        if (0.0 < _DAT_00b7c950) {
          FUN_0043dcb0(0x301,&local_174,fStack_d0);
        }
        if (_DAT_00b7c950 < 0.0) {
          FUN_0043dcb0(0x302,&local_174,fStack_d0);
        }
        uStack_118 = (double)(CONCAT44(uStack_118._4_4_,DAT_00d5c108) & 0xffffffff0000ffff);
        FUN_00441f90((_DAT_00b7c950 * 3.1415927) / (float)(int)(float)uStack_118,local_dc);
        *(undefined1 *)((int)in_ECX + 0x4d) = 1;
        fStack_c4 = 1.4013e-45;
      }
    }
    if (_DAT_00b7c94c != 0.0) {
      uVar11 = (**(code **)(*in_ECX + 0x58))();
      if ((uVar11 & 1) == 0) {
        if (!bVar21) goto LAB_0044886e;
      }
      else if (!bVar21) {
        FUN_0043dcb0(0x303,&local_174,fStack_d0);
        *(undefined1 *)((int)in_ECX + 0x4e) = 1;
      }
      fStack_178 = _DAT_00b7c94c * 0.002;
      fStack_d8 = fStack_d8 - fStack_178;
      if (fStack_d8 <= -0.5235988) {
        fStack_d8 = -0.5235988;
      }
      else if (fStack_a0 <= fStack_d8) {
        fStack_d8 = fStack_a0;
      }
      in_ECX[0x15] = (int)((float)in_ECX[0x15] - fStack_178);
      FUN_00441fc0(fStack_178,local_dc);
      fStack_cc = 1.4013e-45;
      if ((DAT_008fcd74 == 0) || (DAT_00b7c974 != 0)) {
        if ((float)in_ECX[0x71] < DAT_008fccd8 + DAT_008fccd8) {
          fVar17 = ((DAT_008fccd8 + DAT_008fccd8) - (float)in_ECX[0x71]) * fStack_178 *
                   (float)in_ECX[0xb9] * 0.051;
          in_ECX[0x4c] = (int)(fVar17 + (float)in_ECX[0x4c]);
          local_148 = fVar17 + local_148;
          if (local_170 < local_148) {
            cStack_13e = '\x01';
          }
        }
      }
      else {
        uStack_104._0_3_ = (uint3)(ushort)uStack_104;
        cStack_13e = '\x01';
      }
    }
LAB_0044886e:
    uVar11 = (**(code **)(*in_ECX + 0x58))();
    if ((uVar11 & 8) != 0) {
      if ((_DAT_00b7c95c != 0.0) || (_DAT_00b7c958 != 0.0)) {
        FUN_0043dcb0(0x308,&local_174,fStack_d0);
      }
      if (in_ECX[0x23] == 2) {
        fVar22 = (float10)fptan((float10)fStack_d8);
        if (fVar22 <= (float10)0.20000000298023224) {
          fVar22 = (float10)0.20000000298023224;
        }
        else if ((float10)2.0 <= fVar22) {
          fVar22 = (float10)2.0;
        }
        fStack_154 = 0.0;
        fVar17 = (float)-((float10)fStack_12c * (float10)0.001 * (float10)_DAT_00b7c95c);
        uStack_118 = (double)CONCAT44(uStack_118._4_4_,fVar17);
        fVar22 = ((float10)fStack_12c * (float10)0.001 * (float10)_DAT_00b7c958) / fVar22;
        fVar23 = (float10)fcos(-(float10)fStack_a8);
        fStack_4c = (float)fVar23;
        fVar23 = (float10)fsin(-(float10)fStack_a8);
        fStack_158 = (float)(fVar22 * -fVar23 + (float10)fVar17 * (float10)fStack_4c);
        fVar22 = fVar22 * (float10)fStack_4c + (float10)fVar17 * fVar23;
        local_174 = local_174 + fStack_158;
        local_170 = local_170 + 0.0;
        local_16c = (float)(fVar22 + (float10)local_16c);
        local_14c = local_14c + fStack_158;
        local_148 = local_148 + 0.0;
        local_144 = (float)(fVar22 + (float10)local_144);
        *pfVar15 = fStack_158 + *pfVar15;
        in_ECX[0x4c] = (int)((float)in_ECX[0x4c] + 0.0);
        in_ECX[0x4d] = (int)(float)(fVar22 + (float10)(float)in_ECX[0x4d]);
        if ((_DAT_00b7c95c != 0.0) || (_DAT_00b7c958 != 0.0)) {
          cStack_b9 = '\x01';
        }
      }
    }
    uVar11 = (**(code **)(*in_ECX + 0x58))();
    if ((uVar11 & 4) != 0) {
      fVar17 = DAT_008fccd8 + 0.1;
      if (DAT_008fccd8 + 0.1 <= fStack_c0 + (float)in_ECX[0x3b]) {
        fVar17 = fStack_c0 + (float)in_ECX[0x3b];
      }
      in_ECX[0x3b] = (int)fVar17;
      fStack_178 = fStack_c0 + (float)in_ECX[0x70];
      fVar17 = DAT_008fccd8 + 0.1;
      if (DAT_008fccd8 + 0.1 <= fStack_178) {
        fVar17 = fStack_178;
      }
      in_ECX[0x70] = (int)fVar17;
      if (((fStack_c0 != 0.0) && (DAT_00b7f9f0 != '\0')) &&
         ((DAT_008fccd8 + 0.1 == (float)in_ECX[0x3b] || (fVar17 == DAT_008fccd8 + 0.1)))) {
        FUN_0043dcb0(0x200,&local_174,0);
      }
    }
    if ((in_ECX[0x23] == 2) && (DAT_00b7c974 == 0)) {
      fStack_d4 = 1.4013e-45;
      in_ECX[0x6b] = 1;
    }
    else if (in_ECX[0x6b] == 1) {
      fStack_d4 = 1.4013e-45;
      in_ECX[0x6b] = 1;
    }
    else {
      in_ECX[0x6b] = 2;
      fStack_d4 = 2.8026e-45;
    }
    _DAT_00b7c958 = 0.0;
    _DAT_00b7c95c = 0.0;
    _DAT_00b7c954 = 0.0;
    _DAT_00b7c94c = 0.0;
    _DAT_00b7c950 = 0.0;
  }
  if (in_ECX[0x23] == 1) {
    if ((*(byte *)(in_ECX + 0x24) & 3) == 0) {
      in_ECX[0x6b] = 3;
    }
    else if (in_ECX[0x6b] == 0) {
      fStack_178 = (float)in_ECX[0x6e];
      fStack_12c = (float)in_ECX[0x6f];
      if (_DAT_008fccfc * _DAT_008fccfc < fStack_178 * fStack_178 + fStack_12c * fStack_12c) {
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
    }
    FUN_0043a700(in_ECX + 0x4e,pfVar15,&local_f0,auStack_18);
    iVar12 = in_ECX[0x6b];
    if ((iVar12 < 7) || (10 < iVar12)) {
      if (iVar12 == 4) {
        uVar11 = (**(code **)(*in_ECX + 0x58))();
        if ((uVar11 & 2) != 0) {
          uVar11 = DAT_00d5c108 >> 0x10;
          uVar18 = DAT_00d5c108 & 0xffff;
          uStack_100 = (double)(CONCAT44(uStack_100._4_4_,DAT_00d5c108) & 0xffffffff0000ffff);
          fStack_c4 = (float)uVar11;
          uStack_118._0_4_ = (float)uVar11;
          if (*(int *)(*(int *)(DAT_00c22ca4 + 0x24c118) + 0x45e8) != 0) {
            iVar12 = __ftol();
            uStack_118._0_4_ = (float)(uVar11 - iVar12);
          }
          fVar17 = ((float)*local_a4 - (float)(int)(float)uStack_100 * 0.5) /
                   ((float)(int)(float)uStack_100 * 0.5);
          fStack_c4 = (float)(int)fStack_c4;
          fVar5 = (float)(int)(float)uStack_118;
          uStack_118 = (double)CONCAT44(uStack_118._4_4_,fVar5);
          fStack_178 = ((float)in_ECX[0x2d] - fStack_c4 * 0.5) / (fVar5 * 0.5);
          fVar17 = fVar17 * fVar17 + fStack_178 * fStack_178;
          if ((fVar17 < 0.89) || (0.91 < fVar17)) {
            if (fVar17 != 0.0) {
              fVar17 = 0.9 / SQRT(fVar17);
            }
            fStack_178 = fVar17 * fStack_178;
            iVar12 = __ftol();
            *local_a4 = iVar12;
            iVar12 = __ftol();
            in_ECX[0x2d] = iVar12;
          }
          piVar16 = local_a4;
          uVar18 = uVar18 / 2;
          fVar22 = (float10)fpatan((float10)(int)(*piStack_98 - uVar18),
                                   (float10)(piStack_98[1] - ((int)uVar11 >> 1)));
          iVar12 = in_ECX[0x2d] - ((int)uVar11 >> 1);
          uStack_100 = (double)CONCAT44(uStack_100._4_4_,iVar12);
          fVar23 = (float10)fpatan((float10)(int)(*local_a4 - uVar18),(float10)iVar12);
          fStack_12c = (float)(fVar23 - fVar22);
          if (3.1415927 < fStack_12c) {
            fStack_12c = fStack_12c - 6.2831855;
          }
          if (fStack_12c < -3.1415927) {
            fStack_12c = fStack_12c + 6.2831855;
          }
          *piStack_98 = *local_a4;
          piStack_98[1] = local_a4[1];
          iVar12 = FUN_00527d30();
          iVar12 = *(int *)(iVar12 + 0x3a0);
          *(int *)(iVar12 + 0x486c) = *piVar16;
          *(int *)(iVar12 + 0x4870) = piVar16[1];
          *(undefined1 *)(iVar12 + 0x4874) = 1;
          FUN_00527d30();
          iVar12 = FUN_0059b7d0();
          if (iVar12 == 0) {
            FUN_0074c0f0();
          }
          fStack_a8 = fStack_12c + fStack_a8;
          fStack_d4 = 1.4013e-45;
          in_ECX[0x14] = (int)(fStack_12c + (float)in_ECX[0x14]);
          in_ECX[0x24] = 1;
          *(undefined1 *)((int)in_ECX + 0x4d) = 1;
          FUN_00441f90(fStack_12c,local_dc);
          fStack_c4 = 1.4013e-45;
          if (DAT_00b7f9f0 != '\0') {
            FUN_0043dcb0(0x300,&local_174,fStack_d0);
          }
          if (0.01 < fStack_12c) {
            FUN_0043dcb0(0x301,&local_174,fStack_d0);
          }
          if (fStack_12c < 0.01) {
            FUN_0043dcb0(0x302,&local_174,fStack_d0);
          }
        }
      }
      else if ((iVar12 == 5) || (iVar12 == 6)) {
        uVar11 = (**(code **)(*in_ECX + 0x58))();
        if ((uVar11 & 1) != 0) {
          if (DAT_00b7f9f0 != '\0') {
            FUN_0043dcb0(0x303,&local_174,fStack_d0);
            *(undefined1 *)((int)in_ECX + 0x4e) = 1;
          }
          uStack_100 = (double)CONCAT44(uStack_100._4_4_,DAT_00d5c108 >> 0x10);
          fStack_178 = ((float)in_ECX[0x2b] / (float)(DAT_00d5c108 >> 0x10)) * _DAT_008fccec *
                       DAT_00d78bf0;
          fStack_d8 = fStack_d8 - fStack_178;
          in_ECX[0x15] = (int)(fStack_178 + (float)in_ECX[0x15]);
          FUN_00441fc0(fStack_178,local_dc);
          fStack_cc = 1.4013e-45;
          if ((DAT_008fcd74 == 0) || (DAT_00b7c974 != 0)) {
            if ((float)in_ECX[0x71] < DAT_008fccd8 + DAT_008fccd8) {
              fVar17 = ((DAT_008fccd8 + DAT_008fccd8) - (float)in_ECX[0x71]) * fStack_178 *
                       (float)in_ECX[0xb9] * 0.051;
              in_ECX[0x4c] = (int)(fVar17 + (float)in_ECX[0x4c]);
              local_148 = fVar17 + local_148;
              if (local_170 < local_148) {
                cStack_13e = '\x01';
              }
            }
          }
          else {
            cStack_13e = '\x01';
            uStack_104._0_3_ = (uint3)(ushort)uStack_104;
          }
          fStack_d4 = 1.4013e-45;
          in_ECX[0x24] = 2;
        }
      }
      else if (iVar12 == 3) {
        if ((float)in_ECX[0x3b] <= 3000.0) {
          uVar11 = (**(code **)(*in_ECX + 0x58))();
          if ((uVar11 & 8) != 0) {
            in_ECX[0x24] = 0;
            if ((in_ECX[0x51] != 0) && (in_ECX[0x52] != 0)) {
              pfVar15 = (float *)&DAT_00d78b48;
              pfVar19 = afStack_6c;
              for (iVar12 = 0xc; iVar12 != 0; iVar12 = iVar12 + -1) {
                *pfVar19 = *pfVar15;
                pfVar15 = pfVar15 + 1;
                pfVar19 = pfVar19 + 1;
              }
              fStack_124 = DAT_00d78bdc;
              fStack_128 = DAT_00d78bd8;
              fStack_120 = DAT_00d78be0;
              pfVar15 = (float *)(in_ECX + 0x58);
              piVar16 = in_ECX + 0x5e;
              piVar14 = &DAT_00d78b48;
              for (iVar12 = 0xc; iVar12 != 0; iVar12 = iVar12 + -1) {
                *piVar14 = *piVar16;
                piVar16 = piVar16 + 1;
                piVar14 = piVar14 + 1;
              }
              DAT_00d78bd8 = *pfVar15;
              DAT_00d78bdc = (float)in_ECX[0x59];
              DAT_00d78be0 = (float)in_ECX[0x5a];
              FUN_00776470();
              FUN_00776470();
              DAT_00d78be0 = fStack_120;
              DAT_00d78bdc = fStack_124;
              pfVar19 = afStack_6c;
              pfVar20 = (float *)&DAT_00d78b48;
              for (iVar12 = 0xc; iVar12 != 0; iVar12 = iVar12 + -1) {
                *pfVar20 = *pfVar19;
                pfVar19 = pfVar19 + 1;
                pfVar20 = pfVar20 + 1;
              }
              DAT_00d78bd8 = fStack_128;
              fStack_164 = fStack_164 - *pfVar15;
              fStack_160 = fStack_160 - (float)in_ECX[0x59];
              fStack_15c = fStack_15c - (float)in_ECX[0x5a];
              fStack_158 = fStack_158 - *pfVar15;
              fStack_154 = fStack_154 - (float)in_ECX[0x59];
              fStack_150 = fStack_150 - (float)in_ECX[0x5a];
              fVar17 = (float)in_ECX[0x53] * fStack_164 +
                       (float)in_ECX[0x55] * fStack_15c + (float)in_ECX[0x54] * fStack_160;
              uStack_100 = (double)fVar17;
              fVar5 = (float)in_ECX[0x53] * fStack_158 +
                      (float)in_ECX[0x54] * fStack_154 + (float)in_ECX[0x55] * fStack_150;
              uStack_118 = (double)fVar5;
              if (((-0.0010000000474974513 <= uStack_100) || (-0.0010000000474974513 <= uStack_118))
                 && ((uStack_100 <= 0.0010000000474974513 || (uStack_118 <= 0.0010000000474974513)))
                 ) {
                in_ECX[0x24] = 0x10;
                fStack_d4 = 5.60519e-45;
                goto LAB_00449ca8;
              }
              fVar2 = (float)*(double *)(in_ECX + 0x56) -
                      (*pfVar15 * (float)in_ECX[0x53] +
                      (float)in_ECX[0x54] * (float)in_ECX[0x59] +
                      (float)in_ECX[0x55] * (float)in_ECX[0x5a]);
              fVar17 = fVar2 / fVar17;
              uStack_100 = (double)fVar17;
              fVar2 = fVar2 / fVar5;
              if ((0.0001 < uStack_100) && (0.0001 < fVar2)) {
                fStack_15c = fVar17 * fStack_15c + (float)in_ECX[0x5a];
                fStack_160 = fVar17 * fStack_160 + (float)in_ECX[0x59];
                fStack_164 = fVar17 * fStack_164 + *pfVar15;
                fStack_138 = fVar2 * fStack_158;
                fStack_134 = fVar2 * fStack_154;
                fStack_150 = fVar2 * fStack_150 + (float)in_ECX[0x5a];
                fStack_154 = fStack_134 + (float)in_ECX[0x59];
                fStack_158 = fStack_138 + *pfVar15;
                fStack_128 = fStack_158;
                fStack_124 = fStack_154;
                fStack_120 = fStack_150;
                if (DAT_00b7f9f0 != '\0') {
                  FUN_0043dcb0(0x308,&local_174,fStack_d0);
                }
                fStack_164 = fStack_164 - fStack_158;
                fStack_160 = fStack_160 - fStack_154;
                fStack_15c = fStack_15c - fStack_150;
                fVar17 = fStack_15c * fStack_15c + fStack_160 * fStack_160 + fStack_164 * fStack_164
                ;
                if (fStack_11c * fStack_11c < fVar17) {
                  fVar17 = 1.0 / SQRT(fVar17);
                  fStack_164 = fStack_11c * fVar17 * fStack_164;
                  fStack_160 = fStack_11c * fVar17 * fStack_160;
                  fStack_15c = fVar17 * fStack_15c * fStack_11c;
                }
                if ((_DAT_008fcd28 < ABS(fStack_d8)) &&
                   (((_DAT_008fcd2c < (float)in_ECX[0x6a] && (iVar12 = in_ECX[0x2b], 0 < iVar12)) ||
                    (((float)in_ECX[0x6a] < _DAT_008fcd30 && (iVar12 = in_ECX[0x2b], iVar12 < 0)))))
                   ) {
                  fVar22 = (float10)_DAT_008fcd28 - (float10)ABS(fStack_d8);
                  if (fVar22 <= (float10)0.0) {
                    fVar22 = (float10)0.0;
                  }
                  else if ((float10)_DAT_008fcd28 <= fVar22) {
                    fVar22 = (float10)_DAT_008fcd28;
                  }
                  fVar23 = (float10)1.4426950408889634 *
                           ((float10)-iVar12 / (float10)(DAT_00d5c108 >> 0x10)) *
                           (float10)_DAT_008fcd24 * fVar22;
                  fVar22 = ROUND(fVar23);
                  fVar23 = (float10)f2xm1(fVar23 - fVar22);
                  fVar22 = (float10)fscale((float10)1 + fVar23,fVar22);
                  if (fVar22 <= (float10)0.97087383) {
                    fVar22 = (float10)0.97087383;
                  }
                  else if ((float10)1.13 <= fVar22) {
                    fVar22 = (float10)1.13;
                  }
                  fVar17 = (float)in_ECX[0x6a] - local_dc * 200.0;
                  fVar5 = local_dc * 200.0 + (float)in_ECX[0x6a];
                  fVar22 = fVar22 * (float10)(float)in_ECX[0x6a];
                  in_ECX[0x6a] = (int)(float)fVar22;
                  if (fVar22 <= (float10)fVar17) {
                    fVar22 = (float10)fVar17;
                  }
                  else if ((float10)fVar5 <= fVar22) {
                    fVar22 = (float10)fVar5;
                  }
                  in_ECX[0x6a] = (int)(float)fVar22;
                }
                fStack_110 = (float)in_ECX[0x5a] - fStack_15c;
                uStack_118 = (double)CONCAT44((float)in_ECX[0x59] - fStack_160,*pfVar15 - fStack_164
                                             );
                local_144 = (float)in_ECX[0x5d] - fStack_15c;
                local_148 = (float)in_ECX[0x5c] - fStack_160;
                local_14c = (float)in_ECX[0x5b] - fStack_164;
                uStack_100 = (double)CONCAT44(local_148,local_14c);
                fVar17 = (*pfVar15 - fStack_164) - local_14c;
                local_170 = ((float)in_ECX[0x59] - fStack_160) - local_148;
                local_16c = fStack_110 - local_144;
                if (((fVar17 != 0.0) || (local_170 != 0.0)) || (local_16c != 0.0)) {
                  fVar5 = 1.0 / SQRT(local_170 * local_170 + fVar17 * fVar17 + local_16c * local_16c
                                    );
                  fVar17 = fVar17 * fVar5;
                  local_170 = local_170 * fVar5;
                  local_16c = local_16c * fVar5;
                }
                fStack_178 = (float)in_ECX[0x6a];
                local_174 = fVar17 * fStack_178 + local_14c;
                local_170 = local_170 * fStack_178 + local_148;
                local_16c = local_16c * fStack_178 + local_144;
                fStack_f8 = local_144;
                iVar12 = FUN_00760490(&fStack_128,&fStack_120);
                if (iVar12 != 0) {
                  fStack_128 = fStack_128 - *pfVar15;
                  fStack_124 = fStack_124 - (float)in_ECX[0x59];
                  fStack_120 = fStack_120 - (float)in_ECX[0x5a];
                  fStack_178 = local_16c - (float)in_ECX[0x5a];
                  uStack_100 = (double)CONCAT44(uStack_100._4_4_,local_170 - (float)in_ECX[0x59]);
                  fStack_138 = local_174 - *pfVar15;
                  fVar17 = fStack_178 * fStack_178 + fStack_138 * fStack_138;
                  if (fVar17 <= DAT_008fccd8 * DAT_008fccd8) {
LAB_00449b59:
                    fStack_d4 = 5.60519e-45;
                    goto LAB_00449ca8;
                  }
                  fVar17 = DAT_008fccd8 / SQRT(fVar17);
                  uStack_118 = (double)CONCAT44(uStack_118._4_4_,fVar17);
                  uStack_b8 = (double)ABS(fStack_178);
                  if (ABS(fStack_138) <= ABS(fStack_178)) {
                    if (9.999999747378752e-05 < uStack_b8) {
                      fVar5 = fStack_120 / fStack_178;
                      goto LAB_00449a61;
                    }
                  }
                  else if (0.0001 < ABS(fStack_138)) {
                    fVar5 = fStack_128 / fStack_138;
LAB_00449a61:
                    fVar5 = fVar5 - fVar17;
                    if ((fVar5 <= 0.0) || (1.0 <= fVar5)) goto LAB_00449b59;
                    fVar5 = 1.0 - fVar5;
                    uStack_b8._4_4_ = (undefined4)((ulonglong)uStack_b8 >> 0x20);
                    uStack_b8 = (double)CONCAT44(uStack_b8._4_4_,fVar5);
                    fStack_134 = (local_170 - (float)in_ECX[0x59]) * fVar5;
                    uStack_100 = (double)CONCAT44(uStack_100._4_4_,fStack_134);
                    fStack_130 = fStack_178 * fVar5;
                    uStack_118 = (double)CONCAT44(uStack_118._4_4_,fStack_130);
                    local_174 = local_174 - fStack_138 * fVar5;
                    local_170 = local_170 - fStack_134;
                    local_16c = local_16c - fStack_130;
                    local_14c = local_14c - fStack_138 * fVar5;
                    local_148 = local_148 - fStack_134;
                    local_144 = local_144 - fStack_130;
                    if (DAT_00b7f9f0 != '\0') {
                      FUN_0043dcb0(0x200,&local_174,0);
                      fStack_d4 = 5.60519e-45;
                      goto LAB_00449ca8;
                    }
                  }
                }
              }
            }
            fStack_d4 = 5.60519e-45;
          }
        }
        else {
          in_ECX[0x24] = 0x10;
          local_13d = '\x01';
          in_ECX[0xbc] = 1;
        }
      }
    }
    else {
      iVar12 = FUN_00445fc0();
      if (iVar12 != 0) {
        if ((float)in_ECX[0x28] <= (float)in_ECX[0x29]) {
          iVar12 = 9;
          if (0.0 <= (float)in_ECX[0x27]) {
            iVar12 = 10;
          }
        }
        else {
          iVar12 = 7;
          if (0.0 <= (float)in_ECX[0x26]) {
            iVar12 = 8;
          }
        }
        in_ECX[0x6b] = iVar12;
        cVar10 = FUN_00445fe0(&local_174,&local_14c,&fStack_a8,&fStack_d8,local_dc,fStack_d0);
        if ((cVar10 != '\0') &&
           ((fStack_d4 = 1.4013e-45, (float)in_ECX[0x70] < 0.0 || (5000.0 < (float)in_ECX[0x70]))))
        {
          FUN_00445570(&local_174,&local_14c,1);
        }
      }
    }
  }
LAB_00449ca8:
  iVar12 = FUN_00527d30();
  if (((((*(byte *)(iVar12 + 0x40) & 4) != 0) && (DAT_00b7c970 == 0)) || (local_13d != '\0')) &&
     (uVar11 = (**(code **)(*in_ECX + 0x58))(), (uVar11 & 0x10) != 0)) {
    if ((DAT_00d5c400 & 0x10) != 0) {
      DAT_00d5c400 = DAT_00d5c400 & 0xef;
    }
    iVar12 = FUN_00527d30();
    piVar16 = *(int **)(iVar12 + 0x3c8);
    uStack_118 = (double)CONCAT44(uStack_118._4_4_,piVar16);
    iVar12 = FUN_00527d30();
    *(byte *)(iVar12 + 0x40) = *(byte *)(iVar12 + 0x40) & 0xfb;
    cStack_c5 = '\0';
    if (piVar16 == (int *)0x0) {
      iVar12 = FUN_0075f1a0(&fStack_15c,1,0);
      if (iVar12 == 0) goto LAB_0044a280;
      FUN_0043dcb0(0x305,&local_174,0);
    }
    else {
      uStack_100 = (double)CONCAT44(uStack_100._4_4_,piVar16[7]);
      fVar22 = (float10)FUN_00760fd0();
      fStack_160 = (float)(fVar22 + (float10)(float)uStack_100);
      fStack_164 = (float)piVar16[5] * 0.00015258789;
      fStack_15c = (float)piVar16[6] * 0.00015258789;
      FUN_0043dcb0(0x306,&local_174,0);
      iVar12 = 1;
      iVar13 = (**(code **)(*piVar16 + 0x34))();
      if (iVar13 != 0) {
        cStack_c5 = '\x01';
      }
    }
    fStack_138 = (float)__ftol();
    fStack_134 = (float)__ftol();
    fStack_130 = 0.0;
    fVar22 = (float10)FUN_00760fd0();
    fStack_160 = (float)fVar22;
    fStack_128 = 1.0;
    fStack_124 = 0.0;
    fStack_120 = 0.0;
    FUN_004402a0(&fStack_128);
    FUN_004402a0(&fStack_164);
    cVar10 = FUN_00442bd0();
    if (cVar10 == '\0') {
      FUN_0043dcb0(0x101,&fStack_164,0);
      fStack_164 = fStack_158;
      fStack_160 = fStack_154;
      fStack_15c = fStack_150;
    }
    cVar10 = FUN_00442b00(fStack_164,fStack_160,fStack_15c);
    if (cVar10 == '\x01') {
      FUN_0043dcb0(0x100,&fStack_164,0);
    }
    if ((fStack_164 - _DAT_00b7c8f0) * (fStack_164 - _DAT_00b7c8f0) +
        (fStack_15c - _DAT_00b7c8f8) * (fStack_15c - _DAT_00b7c8f8) < _DAT_008fccf0 * _DAT_008fccf0)
    {
      if ((local_13d == '\0') && (in_ECX[0x11] == 0)) {
        piVar16 = *(int **)(DAT_00c22ca4 + 0x201d38);
        while (piVar16 != (int *)0x0) {
          piVar14 = (int *)(**(code **)(*piVar16 + 0x100))();
          FUN_00760fd0();
          fStack_134 = (float)piVar14[1] * 0.00015258789;
          fVar17 = (float)*piVar14 * 0.00015258789 - uStack_168;
          uStack_104 = SQRT(fVar17 * fVar17 + (fStack_134 - fStack_160) * (fStack_134 - fStack_160))
          ;
          fVar22 = (float10)(**(code **)(*piVar16 + 0x60))();
          if ((float10)(float)uStack_100 < fVar22) {
            if (piVar16 != (int *)0x0) {
              cStack_c5 = '\0';
              FUN_00446430();
            }
            break;
          }
          if (piVar16 == (int *)0x0) {
            piVar16 = *(int **)(DAT_00c22ca4 + 0x201d38);
          }
          else {
            piVar16 = (int *)piVar16[0x12];
          }
        }
      }
      fVar3 = uStack_168;
      fVar5 = local_14c;
      fVar17 = local_144;
      fVar2 = local_148;
      if (iVar12 != 0) {
        fVar5 = (float)in_ECX[0x3c];
        fVar17 = (float)in_ECX[0x3e];
        fVar2 = (float)in_ECX[0x3d];
      }
      uStack_168 = (float)((uint)uStack_168 & 0xffffff);
      fVar6 = SQRT((fStack_164 - local_174) * (fStack_164 - local_174) +
                   (fStack_160 - local_170) * (fStack_160 - local_170) +
                   (fStack_15c - local_16c) * (fStack_15c - local_16c));
      if ((fVar6 <= DAT_008fcd00 * 1.5) ||
         (SQRT((fStack_164 - fVar5) * (fStack_164 - fVar5) +
               (fStack_160 - fVar2) * (fStack_160 - fVar2) +
               (fStack_15c - fVar17) * (fStack_15c - fVar17)) <= 10.0)) {
        if (fVar6 <= DAT_008fcd04 * 1.5) {
          fVar17 = DAT_008fcd08 * 1.5;
          in_ECX[0x1e] = (int)(_DAT_008fcccc * 0.5);
          if (fVar6 <= fVar17) {
            fStack_d4 = DAT_008fcd0c;
          }
          else {
            fStack_d4 = DAT_008fcd08;
          }
        }
        else {
          in_ECX[0x1e] = (int)(_DAT_008fcccc * 0.5);
          fStack_d4 = DAT_008fcd04;
        }
      }
      else {
        in_ECX[0x1e] = 0;
        fStack_d4 = DAT_008fcd00;
        uStack_168._0_3_ = SUB43(fVar3,0);
        uStack_168 = (float)CONCAT13(1,(undefined3)uStack_168);
      }
      bVar21 = local_13d != '\0';
      if (bVar21) {
        in_ECX[0x1e] = 0x3c23d70a;
        fStack_d4 = 1000.0;
        uStack_168 = (float)CONCAT13(1,(undefined3)uStack_168);
      }
      FUN_0043a700(&local_174,&local_14c,&fStack_178,&fStack_11c);
      fVar17 = fStack_d4;
      if (!bVar21) {
        fVar22 = (float10)FUN_00444ea0(fStack_178,fStack_d4,&fStack_164,&fStack_11c,0);
        fStack_178 = (float)fVar22;
      }
      local_14c = fStack_164;
      local_148 = fStack_160;
      local_144 = fStack_15c;
      if (fStack_11c <= 0.3926991) {
        fStack_11c = 0.3926991;
      }
      else if (1.4959966 <= fStack_11c) {
        fStack_11c = 1.4959966;
      }
      FUN_0043a640(&local_174,&local_14c,fVar17,fStack_178,fStack_11c);
      fStack_d4 = 4.2039e-45;
      if ((float)in_ECX[0x1e] == 0.0) {
        (**(code **)(*in_ECX + 0x54))(&local_174,&local_14c,&local_78,0x3dcccccd);
      }
      if (uStack_168._3_1_ != '\0') {
        uVar30 = 0x100000000;
        uVar28 = 0;
        uVar25 = 0;
        uVar27 = 3;
        uVar11 = (*(code *)0x4ab7641)(3,0,0,0,1);
        FUN_00423ce0(0,(uVar11 & 3) + 0x2e,uVar27,uVar25,uVar28,uVar30);
      }
      if ((cStack_c5 != '\0') &&
         (iVar12 = FUN_00746d70(0x48,s_HBC__dev_black_CameraModeNew3_cp_008fcd8e + 2,0xf5e),
         iVar12 != 0)) {
        uVar30 = 0;
        uVar28 = 0x3f800000;
        uVar27 = (float)uStack_118;
        uVar25 = FUN_0051f3d0((float)uStack_118,0x3f800000,0,0);
        FUN_0043eb30(uVar25,uVar27,uVar28,uVar30);
      }
    }
  }
LAB_0044a280:
  fStack_d0 = 0.0;
  if (((in_ECX[0x23] != 1) && (((in_ECX[0x23] != 2 || (cStack_b9 == '\0')) && (in_ECX[0x11] != 0))))
     && (iVar12 = in_ECX[0x12], iVar12 != 0)) {
    if ((*(int *)(iVar12 + 0x38) != 0) && (*(int *)(iVar12 + 0x3c) != 0)) {
      fVar17 = *(float *)(*(int *)(*(int *)(iVar12 + 0x3c) + 0x160) + 0x58);
      iVar12 = *(int *)(*(int *)(*(int *)(iVar12 + 0x38) + 0x160) + 0x58);
      fStack_d0 = _DAT_008fcd80;
      if (*(float *)(in_ECX[1] + 0x68) <= 2.0) {
        fStack_d0 = (_DAT_008fcd80 - 2.0) * (*(float *)(in_ECX[1] + 0x68) / 2.0) + 2.0;
      }
      fStack_d0 = fStack_d0 * 2.5;
      pfVar15 = (float *)((int)fVar17 + 0x78);
      pfVar19 = (float *)(iVar12 + 0x78);
      fStack_158 = (*pfVar19 + *pfVar15) * 0.5;
      fStack_154 = (*(float *)((int)fVar17 + 0x7c) + *(float *)(iVar12 + 0x7c)) * 0.5;
      fStack_150 = (*(float *)((int)fVar17 + 0x80) + *(float *)(iVar12 + 0x80)) * 0.5;
      fStack_178 = fVar17;
      fStack_128 = fStack_158;
      fStack_124 = fStack_154;
      fStack_120 = fStack_150;
      fVar22 = (float10)FUN_0046edb0();
      uStack_100._0_4_ = (float)fVar22;
      fVar22 = (float10)FUN_0046edb0();
      fStack_154 = (float)((fVar22 + (float10)(float)uStack_100) * (float10)0.25 +
                          (float10)fStack_124);
      if (fStack_c0 != 0.0) {
        fVar2 = *(float *)(iVar12 + 0x80) - *(float *)((int)fVar17 + 0x80);
        uStack_118 = (double)CONCAT44(uStack_118._4_4_,*(float *)(iVar12 + 0x5228));
        uStack_100._0_4_ = *(float *)(iVar12 + 0x5228);
        fVar5 = *(float *)(iVar12 + 0x80) - *(float *)((int)fVar17 + 0x80);
        in_ECX[0x16] = (int)((((fStack_c0 * 0.3 +
                               *(float *)((int)fStack_178 + 0x5228) * (float)in_ECX[0x16] +
                               SQRT((*pfVar19 - *pfVar15) * (*pfVar19 - *pfVar15) + fVar2 * fVar2) +
                               *(float *)(iVar12 + 0x5228)) -
                              SQRT((*pfVar19 - *pfVar15) * (*pfVar19 - *pfVar15) + fVar5 * fVar5)) -
                             (float)uStack_100) / *(float *)((int)fStack_178 + 0x5228));
      }
      if (_DAT_008fcd88 < (float)in_ECX[0x16]) {
        FUN_00446760();
      }
      if ((float)in_ECX[0x16] <= 0.0) {
        fVar5 = 0.0;
      }
      else {
        fVar5 = _DAT_008fcd88;
        if ((float)in_ECX[0x16] < _DAT_008fcd88) {
          fVar5 = (float)in_ECX[0x16];
        }
      }
      in_ECX[0x16] = (int)fVar5;
      if ((float)in_ECX[0x15] <= 0.24166098) {
        iVar13 = 0x3e7775fa;
      }
      else if (1.3291354 <= (float)in_ECX[0x15]) {
        iVar13 = 0x3faa211c;
      }
      else {
        iVar13 = in_ECX[0x15];
      }
      in_ECX[0x15] = iVar13;
      fVar5 = *(float *)(iVar12 + 0x80) - *(float *)((int)fVar17 + 0x80);
      uStack_118 = (double)CONCAT44(uStack_118._4_4_,*(float *)(iVar12 + 0x5228));
      uStack_100._0_4_ = *(float *)((int)fStack_178 + 0x5228);
      uStack_b8 = (double)CONCAT44(uStack_b8._4_4_,
                                   (float)uStack_100 * (float)in_ECX[0x16] +
                                   SQRT((*pfVar19 - *pfVar15) * (*pfVar19 - *pfVar15) +
                                        fVar5 * fVar5) + *(float *)(iVar12 + 0x5228));
      fStack_178 = (float)in_ECX[0x14];
      fStack_15c = *(float *)((int)fVar17 + 0x80) - *(float *)(iVar12 + 0x80);
      fStack_160 = *(float *)((int)fVar17 + 0x7c) - *(float *)(iVar12 + 0x7c);
      pfVar20 = (float *)(in_ECX + 0x84);
      fStack_164 = *pfVar15 - *pfVar19;
      fStack_11c = *pfVar20;
      if ((0.01 < ABS(fStack_164)) || (0.01 < ABS(fStack_15c))) {
        fVar22 = (float10)FUN_00759180();
        fStack_11c = (float)fVar22;
      }
      if ((char)in_ECX[0xb4] == '\0') {
        uStack_118 = (double)CONCAT44(uStack_118._4_4_,*pfVar20);
        fVar22 = (float10)FUN_004467f0();
        uStack_100._0_4_ = (float)fVar22;
        FUN_004467f0((float)uStack_118);
        fVar22 = (float10)FUN_004467f0();
        fStack_11c = (float)(fVar22 + (float10)(float)uStack_118);
        FUN_00406240(fStack_11c,0,0x40a00000);
        FUN_00406240(fStack_158,0,0x40a00000);
        FUN_00406240(fStack_154,0,0x40a00000);
        FUN_00406240(fStack_150,0,0x40a00000);
      }
      else {
        in_ECX[0x91] = (int)fStack_158;
        in_ECX[0x90] = (int)fStack_158;
        in_ECX[0x97] = (int)fStack_158;
        in_ECX[0x96] = 0;
        in_ECX[0x95] = 0;
        in_ECX[0x9b] = 0;
        in_ECX[0x9a] = 0;
        in_ECX[0x94] = 0;
        in_ECX[0x99] = 0;
        in_ECX[0x93] = 0;
        in_ECX[0x98] = 0;
        in_ECX[0x92] = 0;
        FUN_004399e0();
        FUN_004399e0();
        in_ECX[0x85] = (int)fStack_11c;
        *pfVar20 = fStack_11c;
        in_ECX[0x8b] = (int)fStack_11c;
        in_ECX[0x8a] = 0;
        in_ECX[0x89] = 0;
        in_ECX[0x8f] = 0;
        in_ECX[0x8e] = 0;
        in_ECX[0x88] = 0;
        in_ECX[0x8d] = 0;
        in_ECX[0x87] = 0;
        in_ECX[0x8c] = 0;
        in_ECX[0x86] = 0;
        *(undefined1 *)(in_ECX + 0xb4) = 0;
      }
      fVar17 = local_dc + (float)in_ECX[0x89];
      pfVar15 = (float *)(in_ECX + 0x89);
      pfVar19 = (float *)(in_ECX + 0x8a);
      *pfVar15 = fVar17;
      uStack_100 = (double)CONCAT44(uStack_100._4_4_,pfVar19);
      if (fVar17 < *pfVar19) {
        fVar2 = fVar17 * fVar17 * 0.5;
        fVar5 = fVar17 * fVar2 * 0.33333334;
        in_ECX[0x87] = (int)(fVar2 * (float)in_ECX[0x8e] +
                             fVar17 * (float)in_ECX[0x8d] + fVar5 * (float)in_ECX[0x8f] +
                            (float)in_ECX[0x8c]);
        *pfVar20 = *pfVar15 * (float)in_ECX[0x8c] +
                   fVar5 * (float)in_ECX[0x8e] +
                   fVar2 * (float)in_ECX[0x8d] + fVar2 * fVar2 * 0.16666667 * (float)in_ECX[0x8f] +
                   (float)in_ECX[0x8b];
      }
      else {
        *pfVar20 = (float)in_ECX[0x85];
        in_ECX[0x87] = in_ECX[0x86];
        in_ECX[0x88] = 0;
        *pfVar15 = *pfVar19;
      }
      FUN_0043a550();
      FUN_0043a550();
      FUN_0043a550();
      fStack_178 = fStack_178 - *pfVar20;
      local_144 = (float)in_ECX[0xa8];
      local_148 = (float)in_ECX[0x9c];
      local_14c = (float)in_ECX[0x90];
      fStack_138 = local_14c;
      fStack_134 = local_148;
      fStack_130 = local_144;
      FUN_0043a640(&local_174,&local_14c,(float)uStack_b8,fStack_178,in_ECX[0x15]);
      in_ECX[0x4b] = (int)local_14c;
      in_ECX[0x4c] = (int)local_148;
      in_ECX[0x4d] = (int)local_144;
      cStack_13e = '\0';
      uStack_104._0_3_ = CONCAT12(1,(ushort)uStack_104);
      fStack_d4 = 4.2039e-45;
      *(undefined1 *)(in_ECX + 0x22) = 0;
    }
  }
  if (fStack_d4 == 0.0) {
    if (in_ECX[0x23] == 0) {
      FUN_00445e70(&local_174,&local_14c);
    }
  }
  else if (fStack_d4 == 1.4013e-45) {
    if (fStack_d8 <= -0.5235988) {
      fStack_d8 = -0.5235988;
    }
    else if (fStack_a0 <= fStack_d8) {
      fStack_d8 = fStack_a0;
    }
    fVar17 = local_14c - local_174;
    fStack_160 = local_148 - local_170;
    fStack_15c = local_144 - local_16c;
    if (((fVar17 != 0.0) || (fStack_160 != 0.0)) || (fStack_15c != 0.0)) {
      fVar5 = 1.0 / SQRT(fStack_160 * fStack_160 + fStack_15c * fStack_15c + fVar17 * fVar17);
      fVar17 = fVar5 * fVar17;
      fStack_160 = fVar5 * fStack_160;
      fStack_15c = fVar5 * fStack_15c;
    }
    fVar5 = (float)in_ECX[0x70];
    fStack_164 = local_174 + fVar17 * fVar5;
    fStack_160 = local_170 + fVar5 * fStack_160;
    fStack_15c = local_16c + fVar5 * fStack_15c;
    if (fStack_d8 <= -0.5235988) {
      fStack_178 = -0.5235988;
    }
    else if (fStack_a0 <= fStack_d8) {
      fStack_178 = fStack_a0;
    }
    else {
      fStack_178 = fStack_d8;
    }
    pfVar15 = (float *)(in_ECX + 0x4b);
    FUN_0043a640(&local_174,pfVar15,fStack_13c,fStack_a8,fStack_178);
    local_14c = *pfVar15;
    local_148 = (float)in_ECX[0x4c];
    local_144 = (float)in_ECX[0x4d];
    if (fStack_c0 == 0.0) {
      local_14c = local_14c - local_174;
      local_148 = local_148 - local_170;
      fStack_e8 = local_144 - local_16c;
      if (((local_14c != 0.0) || (local_148 != 0.0)) ||
         (local_f0._4_4_ = local_148, fStack_e8 != 0.0)) {
        fVar17 = 1.0 / SQRT(local_148 * local_148 + fStack_e8 * fStack_e8 + local_14c * local_14c);
        local_14c = fVar17 * local_14c;
        local_f0._4_4_ = fVar17 * local_148;
        fStack_e8 = fVar17 * fStack_e8;
      }
      fStack_13c = (float)in_ECX[0x70];
      fVar5 = local_170 + fStack_13c * local_f0._4_4_;
      local_f0 = (double)CONCAT44(fVar5,(undefined4)local_f0);
      fStack_e8 = local_16c + fStack_13c * fStack_e8;
      fVar17 = fStack_164 - (local_14c * fStack_13c + local_174);
      fStack_160 = fStack_160 - fVar5;
      fStack_15c = fStack_15c - fStack_e8;
      *pfVar15 = fVar17 + *pfVar15;
      in_ECX[0x4c] = (int)(fStack_160 + (float)in_ECX[0x4c]);
      in_ECX[0x4d] = (int)(fStack_15c + (float)in_ECX[0x4d]);
      local_174 = local_174 + fVar17;
      local_170 = local_170 + fStack_160;
      local_16c = local_16c + fStack_15c;
      local_14c = *pfVar15;
      local_148 = (float)in_ECX[0x4c];
      local_144 = (float)in_ECX[0x4d];
    }
  }
  else if (fStack_d4 == 2.8026e-45) {
    if ((float)in_ECX[0x3b] <= 3000.0) {
      fVar22 = (float10)fptan((float10)DAT_00d78bf0 * (float10)0.5);
      fStack_11c = (float)fVar22;
      fStack_12c = ((float)(DAT_00d5c108 >> 0x10) * fStack_11c) / (float)(DAT_00d5c108 & 0xffff);
      if (fStack_d8 <= -0.5235988) {
        fStack_178 = -0.5235988;
      }
      else if (fStack_a0 <= fStack_d8) {
        fStack_178 = fStack_a0;
      }
      else {
        fStack_178 = fStack_d8;
      }
      pfVar15 = (float *)(in_ECX + 0x4b);
      uStack_100._0_4_ = (float)(DAT_00d5c108 & 0xffff);
      FUN_0043a640(&local_174,pfVar15,fStack_13c,fStack_a8,fStack_178);
      fStack_e8 = local_16c - (float)in_ECX[0x4d];
      uStack_b8 = (double)CONCAT44(uStack_b8._4_4_,fStack_e8);
      fStack_178 = local_170 - (float)in_ECX[0x4c];
      local_174 = local_174 - *pfVar15;
      if (((local_174 != 0.0) || (fStack_178 != 0.0)) || (fStack_154 = fStack_178, fStack_e8 != 0.0)
         ) {
        fVar17 = 1.0 / SQRT(fStack_e8 * fStack_e8 + fStack_178 * fStack_178 + local_174 * local_174)
        ;
        local_174 = fVar17 * local_174;
        fStack_154 = fVar17 * fStack_178;
        fStack_e8 = fVar17 * fStack_e8;
      }
      local_f0 = (double)CONCAT44(fStack_154,(undefined4)local_f0);
      fVar17 = fStack_e8 - 0.0;
      fStack_160 = 0.0;
      fStack_15c = 0.0 - local_174;
      if ((fVar17 != 0.0) || (fStack_15c != 0.0)) {
        fVar5 = 1.0 / SQRT(fStack_15c * fStack_15c + fVar17 * fVar17 + 0.0);
        fVar17 = fVar5 * fVar17;
        fStack_160 = fVar5 * 0.0;
        fStack_15c = fVar5 * fStack_15c;
      }
      fStack_128 = fStack_15c * fStack_154 - fStack_160 * fStack_e8;
      fStack_124 = fVar17 * fStack_e8 - local_174 * fStack_15c;
      fVar5 = local_174 * fStack_160 - fVar17 * fStack_154;
      if (((fStack_128 != 0.0) || (fStack_124 != 0.0)) || (fVar5 != 0.0)) {
        fVar2 = 1.0 / SQRT(fStack_124 * fStack_124 + fVar5 * fVar5 + fStack_128 * fStack_128);
        fStack_128 = fVar2 * fStack_128;
        fStack_124 = fVar2 * fStack_124;
        fVar5 = fVar2 * fVar5;
      }
      fVar2 = (float)in_ECX[0x3b];
      fVar3 = (float)in_ECX[0x27];
      fStack_158 = fVar2 * fStack_128 * fStack_12c * fVar3;
      fVar6 = fVar3 * fStack_12c * fVar2 * fStack_124;
      fVar3 = fVar3 * fVar2 * fVar5 * fStack_12c;
      fVar5 = (float)in_ECX[0x3b];
      fVar2 = (float)in_ECX[0x26];
      fVar17 = fVar17 * fVar5 * fStack_11c * fVar2;
      fVar7 = fVar2 * fStack_11c * fVar5 * fStack_160;
      fVar2 = fVar2 * fStack_11c * fVar5 * fStack_15c;
      local_144 = fVar2 + fVar2 + (float)in_ECX[0x38];
      uStack_118 = (double)CONCAT44(uStack_118._4_4_,local_144);
      local_148 = fVar7 + fVar7 + (float)in_ECX[0x37];
      uStack_100 = (double)CONCAT44(uStack_100._4_4_,local_148);
      local_14c = fVar17 + fVar17 + (float)in_ECX[0x36] + fStack_158 + fStack_158;
      local_148 = local_148 + fVar6 + fVar6;
      local_144 = local_144 + fVar3 + fVar3;
      *pfVar15 = local_14c;
      in_ECX[0x4c] = (int)local_148;
      in_ECX[0x4d] = (int)local_144;
      fStack_13c = (float)in_ECX[0x3b];
      fStack_154 = fStack_13c * fStack_154;
      fStack_150 = fStack_13c * fStack_e8;
      local_174 = local_174 * fStack_13c + local_14c;
      local_170 = fStack_154 + local_148;
      local_16c = fStack_150 + local_144;
      fStack_138 = local_174;
      fStack_134 = local_170;
      fStack_130 = local_16c;
      fStack_128 = local_14c;
      fStack_124 = local_148;
      fStack_120 = local_144;
    }
    else {
      in_ECX[0x24] = 0x10;
    }
  }
  if (((local_170 < local_148) || (fStack_d8 < 0.0)) && (DAT_00b7c974 != 0)) {
    cStack_13e = '\x01';
  }
  uVar11 = (**(code **)(*in_ECX + 0x58))();
  if ((uVar11 & 0x40) == 0) {
LAB_0044b0c1:
    if (cStack_13e != '\0') goto LAB_0044b0cd;
  }
  else {
    uStack_104._0_3_ = (uint3)(ushort)uStack_104;
    if ((in_ECX[0x23] != 0) && (uStack_104._3_1_ == '\0')) goto LAB_0044b0c1;
    fStack_138 = (float)__ftol();
    fStack_134 = (float)__ftol();
    fStack_130 = 0.0;
    fVar22 = (float10)FUN_00760fd0();
    cStack_13e = '\x01';
    local_8c = (float)(fVar22 + (float10)DAT_008fc598);
LAB_0044b0cd:
    local_14c = local_14c - local_174;
    local_148 = local_148 - local_170;
    local_174 = local_90;
    local_170 = local_8c;
    local_144 = local_144 - local_16c;
    local_16c = local_88;
    local_14c = local_90 + local_14c;
    local_148 = local_8c + local_148;
    local_144 = local_144 + local_88;
    in_ECX[0x4b] = (int)local_14c;
    in_ECX[0x4c] = (int)local_148;
    in_ECX[0x4d] = (int)local_144;
    fStack_138 = local_14c;
    fStack_134 = local_148;
    fStack_130 = local_144;
  }
  dVar9 = local_f0;
  if (0.01 < DAT_00b7c988) {
    local_16c = ((float)in_ECX[0x7a] - (float)in_ECX[0x7d]) * DAT_00b7c988 + (float)in_ECX[0x7d];
    local_170 = ((float)in_ECX[0x79] - (float)in_ECX[0x7c]) * DAT_00b7c988 + (float)in_ECX[0x7c];
    local_174 = ((float)in_ECX[0x78] - (float)in_ECX[0x7b]) * DAT_00b7c988 + (float)in_ECX[0x7b];
    fStack_13c = DAT_00b7c988;
    local_144 = ((float)in_ECX[0x80] - (float)in_ECX[0x83]) * DAT_00b7c988 + (float)in_ECX[0x83];
    local_148 = ((float)in_ECX[0x7f] - (float)in_ECX[0x82]) * DAT_00b7c988 + (float)in_ECX[0x82];
    local_14c = ((float)in_ECX[0x7e] - (float)in_ECX[0x81]) * DAT_00b7c988 + (float)in_ECX[0x81];
    fStack_138 = local_14c;
    fStack_134 = local_148;
    fStack_130 = local_144;
  }
  fStack_164 = local_174 - local_14c;
  fStack_24 = local_174;
  fStack_3c = local_14c;
  fStack_160 = local_170 - local_148;
  fStack_20 = local_170;
  fStack_1c = local_16c;
  uStack_168 = (float)((uint)uStack_168 & 0xffffff);
  fStack_15c = local_16c - local_144;
  local_13d = '\0';
  fStack_38 = local_148;
  fStack_34 = local_144;
  if (((fStack_164 != 0.0) || (fStack_160 != 0.0)) || (fStack_15c != 0.0)) {
    fVar17 = 1.0 / SQRT(fStack_160 * fStack_160 + fStack_15c * fStack_15c + fStack_164 * fStack_164)
    ;
    fStack_164 = fVar17 * fStack_164;
    fStack_160 = fVar17 * fStack_160;
    fStack_15c = fVar17 * fStack_15c;
  }
  uStack_118 = (double)((ulonglong)uStack_118 & 0xffffffff00000000);
  afStack_6c[0] = fStack_15c - 0.0;
  local_f0 = (double)((ulonglong)local_f0 & 0xffffffff);
  fStack_e8 = 0.0 - fStack_164;
  if ((afStack_6c[0] != 0.0) || (fStack_e8 != 0.0)) {
    fVar17 = 1.0 / SQRT(fStack_e8 * fStack_e8 + afStack_6c[0] * afStack_6c[0] + 0.0);
    afStack_6c[0] = fVar17 * afStack_6c[0];
    local_f0._0_4_ = SUB84(dVar9,0);
    local_f0 = (double)CONCAT44(fVar17 * 0.0,(undefined4)local_f0);
    fStack_e8 = fVar17 * fStack_e8;
  }
  fStack_158 = fStack_e8 * fStack_160 - local_f0._4_4_ * fStack_15c;
  fStack_154 = afStack_6c[0] * fStack_15c - fStack_164 * fStack_e8;
  fStack_150 = fStack_164 * local_f0._4_4_ - afStack_6c[0] * fStack_160;
  if (((fStack_158 != 0.0) || (fStack_154 != 0.0)) ||
     (fStack_128 = fStack_158, fStack_124 = fStack_154, fStack_120 = fStack_150, fStack_150 != 0.0))
  {
    fStack_120 = 1.0 / SQRT(fStack_154 * fStack_154 +
                            fStack_150 * fStack_150 + fStack_158 * fStack_158);
    fStack_128 = fStack_120 * fStack_158;
    fStack_124 = fStack_120 * fStack_154;
    fStack_120 = fStack_120 * fStack_150;
  }
  fStack_48 = local_174;
  fStack_12c = DAT_008fccd8;
  afStack_6c[0] = DAT_008fccd8 * afStack_6c[0];
  fStack_44 = local_170;
  fStack_40 = local_16c;
  afStack_6c[1] = DAT_008fccd8 * local_f0._4_4_;
  afStack_6c[2] = DAT_008fccd8 * fStack_e8;
  afStack_6c[3] = DAT_008fccd8 * fStack_128;
  fStack_5c = DAT_008fccd8 * fStack_124;
  fStack_58 = DAT_008fccd8 * fStack_120;
  fStack_54 = DAT_008fccd8 * fStack_164;
  fStack_50 = DAT_008fccd8 * fStack_160;
  fStack_4c = DAT_008fccd8 * fStack_15c;
  if (DAT_008fcd70 != 0) {
    for (iVar12 = in_ECX[0xbd]; iVar12 != 0; iVar12 = *(int *)(iVar12 + 4)) {
      fVar17 = *(float *)(iVar12 + 0xc) - local_174;
      fVar2 = *(float *)(iVar12 + 0x14) - local_16c;
      fVar5 = DAT_008fccd8 + *(float *)(iVar12 + 0x18);
      if (fVar17 * fVar17 + fVar2 * fVar2 < fVar5 * fVar5) {
        fVar5 = local_16c - *(float *)(iVar12 + 0x14);
        fVar17 = local_170 - *(float *)(iVar12 + 0x10);
        uStack_100._4_4_ = (undefined4)((ulonglong)uStack_100 >> 0x20);
        uStack_100 = (double)CONCAT44(uStack_100._4_4_,fVar17);
        fStack_128 = local_174 - *(float *)(iVar12 + 0xc);
        if (*(int *)(iVar12 + 0x20) == 1) {
          fVar2 = SQRT(fStack_128 * fStack_128 + fVar5 * fVar5);
          if (fVar2 <= 0.01) {
            fVar2 = 0.01;
          }
          fVar2 = (DAT_008fccd8 + *(float *)(iVar12 + 0x18)) / fVar2;
          fStack_128 = fVar2 * fStack_128;
          fStack_124 = fVar17 * fVar2;
          FUN_0043a530(fStack_128 + *(float *)(iVar12 + 0xc),fStack_124 + *(float *)(iVar12 + 0x10),
                       fVar5 * fVar2 + *(float *)(iVar12 + 0x14));
          local_174 = fStack_138;
          local_16c = fStack_130;
          uStack_168 = (float)CONCAT13(1,(undefined3)uStack_168);
          if (DAT_00b7f9f0 != '\0') {
            FUN_0043dcb0(0x201,&local_174);
          }
        }
      }
    }
  }
  uStack_118._0_4_ = -NAN;
  do {
    fVar17 = (float)uStack_118;
    iVar12 = (int)*(char *)((int)(float)uStack_118 + 0x8fcde6);
    uStack_100 = (double)CONCAT44(uStack_100._4_4_,iVar12);
    fStack_13c = 0.0;
    if (0 < iVar12) {
      fVar22 = (float10)(int)(float)uStack_118;
      fVar23 = (float10)fcos(fVar22 * (float10)0.7853982);
      uStack_118._0_4_ = (float)fVar23;
      fVar22 = (float10)fsin(fVar22 * (float10)0.7853982);
      fStack_178 = (float)fVar22;
      uStack_100 = (double)CONCAT44(uStack_100._4_4_,(float)iVar12);
      do {
        fVar5 = fStack_13c;
        fVar22 = ((float10)(int)fStack_13c * (float10)6.2831855) / (float10)(float)uStack_100;
        fVar23 = (float10)fcos(fVar22);
        fVar22 = (float10)fsin(fVar22);
        FUN_0043a530((float)(fVar22 * (float10)(float)uStack_118),fStack_178,
                     (float)(fVar23 * (float10)(float)uStack_118));
        _GetPtr_Object__UAEPAV1_XZ();
        FUN_0044c6b0();
        FUN_0044c6d0();
        fVar22 = (float10)FUN_00445b90();
        if ((float10)fStack_134 < fVar22) {
          if (DAT_00b7f9f0 != '\0') {
            FUN_0043dcb0(0x200,&local_174);
          }
          _GetPtr_Object__UAEPAV1_XZ();
          FUN_004402a0();
          FUN_00445c80(&local_f0,&fStack_128);
          FUN_00440270(auStack_14,&fStack_138);
          fVar22 = (float10)FUN_00441ec0();
          fStack_13c = (float)fVar22;
          if (DAT_008fccd8 * 0.5 < fStack_13c) {
            fStack_13c = DAT_008fccd8 * 0.5;
          }
          FUN_00441b90(&fStack_158,fStack_13c);
          FUN_00441bc0();
          uStack_168 = (float)CONCAT13(1,(undefined3)uStack_168);
          fVar22 = (float10)FUN_00441ec0();
          fStack_13c = (float)fVar22;
          if ((float10)0.0 < fVar22) {
            FUN_00441b90(auStack_84,fStack_13c);
            FUN_00441bc0();
            local_13d = '\x01';
          }
        }
        fStack_13c = (float)((int)fVar5 + 1);
      } while ((int)fStack_13c < iVar12);
    }
    uStack_118._0_4_ = (float)((int)fVar17 + 1);
  } while ((int)(float)uStack_118 < 3);
  if (DAT_00b7f9cc == 0) {
    _DAT_00b7f9c4 = 1e+10;
  }
  else {
    _GetPtr_Object__UAEPAV1_XZ();
    _GetPtr_Object__UAEPAV1_XZ();
    FUN_0044c5f0();
    pfVar15 = (float *)FUN_00440270(CONCAT44(&local_174,auStack_84));
    fStack_158 = *pfVar15;
    fStack_154 = pfVar15[1];
    fStack_150 = pfVar15[2];
    _GetPtr_Object__UAEPAV1_XZ();
    FUN_004402a0(&fStack_158);
    FUN_004402a0(&local_174);
    cVar10 = FUN_00442bd0();
    if (cVar10 == '\0') {
      FUN_00440270(&fStack_164,&local_174);
      local_f0 = (double)((ulonglong)local_f0 & 0xffffffff);
      fStack_160 = 0.0;
      FUN_0044c610();
      FUN_0044c610();
      fStack_13c = 50.0;
      if (in_ECX[0x6b] != 4) {
        fStack_13c = 20.0;
      }
      fStack_11c = -fStack_15c;
      iVar12 = 0;
      fStack_a0 = fStack_164;
      uStack_b8 = (double)CONCAT44(uStack_b8._4_4_,fStack_15c);
      uStack_100 = (double)CONCAT44(uStack_100._4_4_,fStack_164);
      fVar17 = 0.0;
      do {
        iVar13 = -1;
        fStack_178 = fVar17;
        do {
          fVar22 = (float10)fsin((float10)(int)fStack_178 * (float10)0.09817477);
          uStack_118._0_4_ = (float)(fVar22 * (float10)fStack_13c);
          fVar22 = (float10)fcos((float10)(int)fStack_178 * (float10)0.09817477);
          uVar27 = FUN_0043a530((float)(fVar22 * (float10)fStack_13c * (float10)fStack_a0 +
                                       (float10)(float)uStack_118 * (float10)fStack_11c),0,
                                (float)(fVar22 * (float10)fStack_13c * (float10)(float)uStack_b8 +
                                       (float10)(float)uStack_118 * (float10)(float)uStack_100));
          FUN_0044c520(&fStack_138,uVar27);
          FUN_004402a0(&fStack_158);
          FUN_004402a0(&fStack_138);
          cVar10 = FUN_00442bd0();
          if (cVar10 == '\x01') {
            fStack_128 = fStack_138;
            fStack_124 = fStack_134;
            fStack_120 = fStack_130;
            goto LAB_0044bad2;
          }
          iVar13 = iVar13 + 2;
          fStack_178 = (float)((int)fStack_178 + iVar12);
        } while (iVar13 < 2);
        fVar17 = (float)((int)fVar17 + -1);
        iVar12 = iVar12 + 2;
      } while (-0x20 < (int)fVar17);
LAB_0044bad2:
      FUN_004aaa10();
      FUN_004aaa10();
      local_174 = fStack_128;
      local_16c = fStack_120;
      uStack_168 = (float)CONCAT13(1,(undefined3)uStack_168);
      FUN_00441bc0();
      FUN_00441bc0();
      local_13d = '\x01';
      _DAT_00b7f9c4 = 0.0;
      if (DAT_00b7f9f0 != '\0') {
        FUN_0043dcb0(0x202,&local_174,0);
      }
      iVar12 = FUN_00527d30();
      if (iVar12 != 0) {
        uVar30 = 0x800000000000002a;
        FUN_00527d30(0x2a,0x80000000);
        FUN_00598f00(uVar30);
      }
      uVar30 = 0x100000001;
      uVar29 = 0;
      uVar26 = 0;
      uVar28 = 2;
      uVar25 = 0x2b;
      uVar27 = FUN_00446720(0x2b,2,0,0,1,1);
      FUN_00423f80(0,uVar27,uVar25,uVar28,uVar26,uVar29,uVar30);
      uVar25 = 400;
      uVar27 = 0x3f800000;
      FUN_004402a0(&local_174);
      FUN_0077b550(0x42c80000);
      if (in_ECX[0x6b] != 4) {
        in_ECX[0xbc] = 1;
      }
      if (DAT_00b7f9d8 != 0) {
        uVar30 = CONCAT44(0x43480000,uVar25);
        FUN_004402a0(&local_174);
        FUN_007932f0(uVar26,uVar27,uVar30);
      }
    }
    else {
      fVar22 = (float10)FUN_0044c5c0();
      _DAT_00b7f9c4 = (float)fVar22;
    }
  }
  fVar17 = fStack_d4;
  if ((fStack_d4 == 4.2039e-45) && (uStack_168._3_1_ != '\0')) {
    FUN_00440270(&fStack_138,&fStack_24);
    pfVar15 = (float *)FUN_0044c520(auStack_84,&fStack_138);
    local_14c = *pfVar15;
    local_148 = pfVar15[1];
    local_144 = pfVar15[2];
    cStack_13e = '\0';
    local_13d = '\x01';
    uStack_168 = (float)CONCAT13(1,(undefined3)uStack_168);
    cVar10 = '\0';
  }
  else {
    cVar10 = uStack_104._2_1_;
  }
  iVar12 = FUN_0051f3d0();
  if ((*(char *)(iVar12 + 0x78) == '\0') && (local_170 < fStack_94)) {
    local_170 = fStack_94;
    uStack_168 = (float)CONCAT13(1,(undefined3)uStack_168);
  }
  if ((DAT_008fcd70 != 0) && (fStack_9c < local_170)) {
    uStack_100 = (double)CONCAT44(uStack_100._4_4_,local_170 - fStack_9c);
    FUN_00440270(&fStack_128,&local_174);
    if (0.01 < ABS(fStack_124)) {
      FUN_0075d6c0();
      FUN_00441bc0();
      FUN_00441bc0();
      FUN_00441bc0();
    }
    uStack_168 = (float)CONCAT13(1,(undefined3)uStack_168);
    local_13d = '\x01';
    if (DAT_00b7f9f0 != '\0') {
      FUN_0043dcb0(0x203,&local_174,0);
    }
  }
  if (cVar10 == '\0') {
    pfVar15 = (float *)FUN_00440270(auStack_84,&local_174);
    local_14c = *pfVar15;
    local_148 = pfVar15[1];
    local_144 = pfVar15[2];
    FUN_0044c610();
    FUN_0075d6c0();
    FUN_00441bc0();
  }
  cVar10 = local_13d;
  if (DAT_00c22114 == 0) {
    FUN_004aaa10();
    FUN_004aaa10();
    fVar5 = local_174 * local_174 + local_16c * local_16c;
    cVar10 = local_13d;
    if (_DAT_008fccf0 * _DAT_008fccf0 < fVar5) {
      fVar5 = _DAT_008fccf0 / SQRT(fVar5);
      local_174 = fVar5 * local_174;
      local_16c = fVar5 * local_16c;
      cVar10 = '\x01';
      if (DAT_00b7f9f0 != '\0') {
        FUN_0043dcb0(0x202,&local_174,0);
      }
    }
    FUN_00441bc0();
    FUN_00441bc0();
  }
  FUN_00440270(auStack_30,&local_90);
  fVar22 = (float10)FUN_00441ea0();
  fStack_9c = _DAT_008fcd18 * (float)in_ECX[0xb9] * local_dc;
  if (fStack_9c < 300.0) {
    fStack_9c = 300.0;
  }
  if (((fVar22 <= (float10)fStack_9c * (float10)fStack_9c) || (fVar17 == 4.2039e-45)) ||
     (fStack_c0 != 0.0)) {
    if ((uStack_168._3_1_ == '\0') && (cVar10 == '\0')) goto LAB_0044c065;
  }
  else {
    FUN_0044c610();
    uVar27 = FUN_00441b90(auStack_84,fStack_9c);
    pfVar15 = (float *)FUN_0044c520(auStack_14,uVar27);
    local_174 = *pfVar15;
    local_170 = pfVar15[1];
    local_16c = pfVar15[2];
    uStack_168 = (float)CONCAT13(1,(undefined3)uStack_168);
  }
  if ((fVar17 != 2.8026e-45) && (fVar17 != 5.60519e-45)) {
    if (cVar10 != '\0') {
      in_ECX[0x4b] = (int)local_14c;
      in_ECX[0x4c] = (int)local_148;
      in_ECX[0x4d] = (int)local_144;
    }
    fVar22 = (float10)FUN_0043e5f0();
    in_ECX[0x6a] = (int)(float)fVar22;
    if (in_ECX[0x52] != 0) {
      fVar22 = (float10)FUN_00444d10(&local_174,&local_14c,in_ECX + 0x36);
      in_ECX[0x3b] = (int)(float)fVar22;
    }
    fVar17 = DAT_008fccd8 + 0.1;
    if (fVar17 <= (float)in_ECX[0x3b]) {
      fVar17 = (float)in_ECX[0x3b];
    }
    in_ECX[0x3b] = (int)fVar17;
    fVar17 = DAT_008fccd8 + 0.1;
    if (fVar17 <= (float)in_ECX[0x6a]) {
      fVar17 = (float)in_ECX[0x6a];
    }
    in_ECX[0x6a] = (int)fVar17;
    FUN_00445570(&local_174,&local_14c,1);
  }
LAB_0044c065:
  if ((char)in_ECX[0x22] != '\0') {
    in_ECX[0x4b] = in_ECX[0x1f];
    in_ECX[0x4c] = in_ECX[0x20];
    in_ECX[0x4d] = in_ECX[0x21];
    local_14c = (float)in_ECX[0x4b];
    local_148 = (float)in_ECX[0x4c];
    local_144 = (float)in_ECX[0x4d];
    fVar22 = (float10)FUN_0043e5f0();
    fStack_13c = (float)fVar22;
    FUN_0043a640(&local_174,&local_14c,fStack_13c,fStack_a8,fStack_d8);
  }
  fVar17 = local_dc + (float)in_ECX[0x1e];
  uStack_118 = (double)CONCAT44(uStack_118._4_4_,fVar17);
  in_ECX[0x1e] = (int)fVar17;
  fStack_13c = _DAT_008fccd4;
  if (cVar10 != '\0') {
    fStack_13c = _DAT_008fccd4 + _DAT_008fccd4;
  }
  if (uStack_168._3_1_ != '\0') {
    fStack_13c = fStack_13c + fStack_13c;
  }
  if (fVar17 <= _DAT_008fcccc) {
    fStack_13c = (fVar17 / _DAT_008fcccc) * (fStack_13c - DAT_008fccd0) + DAT_008fccd0;
  }
  fStack_94 = fStack_13c;
  uVar11 = (**(code **)(*in_ECX + 0x58))();
  if (((uVar11 & 0x40) != 0) && (cStack_13e != '\0')) {
    fStack_13c = 1.0;
    fStack_94 = 1.0;
  }
  if (fStack_d0 != 0.0) {
    fStack_13c = fStack_d0;
    fStack_94 = fStack_d0;
  }
  iVar12 = FUN_00735014((double)local_174);
  if (((((iVar12 == 0) && (iVar12 = FUN_00735014((double)local_170), iVar12 == 0)) &&
       (iVar12 = FUN_00735014((double)local_16c), iVar12 == 0)) &&
      ((iVar12 = FUN_00735014((double)local_14c), iVar12 == 0 &&
       (iVar12 = FUN_00735014((double)local_148), iVar12 == 0)))) &&
     (iVar12 = FUN_00735014((double)local_144), iVar12 == 0)) {
    iVar12 = FUN_0044c550();
    if (iVar12 == 0) {
      in_ECX[0x72] = (int)local_174;
      in_ECX[0x73] = (int)local_170;
      in_ECX[0x74] = (int)local_16c;
    }
    iVar12 = FUN_0044c550();
    if (iVar12 == 0) {
      in_ECX[0x75] = (int)local_14c;
      in_ECX[0x76] = (int)local_148;
      in_ECX[0x77] = (int)local_144;
    }
  }
  else {
    local_174 = (float)in_ECX[0x72];
    local_170 = (float)in_ECX[0x73];
    local_16c = (float)in_ECX[0x74];
    local_14c = (float)in_ECX[0x75];
    local_148 = (float)in_ECX[0x76];
    local_144 = (float)in_ECX[0x77];
  }
  fVar22 = (float10)FUN_0044c590();
  if (fVar22 < (float10)0.1) {
    local_174 = local_174 + 1.0;
  }
  if ((char)in_ECX[0x40] == '\0') {
    FUN_00441900(&local_174,fStack_13c);
    FUN_00441900(&local_14c,fStack_94);
  }
  else if (*(float *)(in_ECX[1] + 300) <= DAT_008fccd0 * 0.5) {
    if (*(char *)((int)in_ECX + 0x101) != '\0') {
      uVar30 = CONCAT44(0x40000000,&fStack_138);
      FUN_00440270(auStack_84,&local_78);
      FUN_00441b90(uVar30);
      if (0.0 < fStack_134) {
        fStack_134 = 0.0;
      }
      FUN_00441900(in_ECX + 0x41,DAT_008fccd0 * 0.9);
      FUN_00441900(in_ECX + 0x47,DAT_008fccd0 * 0.9);
      *(undefined1 *)((int)in_ECX + 0x101) = 0;
    }
  }
  else {
    FUN_00441900(in_ECX + 0x44,DAT_008fccd0);
    FUN_00441900(in_ECX + 0x47,DAT_008fccd0);
    in_ECX[0x1e] = 0;
    *(undefined1 *)(in_ECX + 0x40) = 0;
  }
  piVar16 = (int *)FUN_0044c500();
  in_ECX[3] = *piVar16;
  in_ECX[4] = piVar16[1];
  in_ECX[5] = piVar16[2];
  piVar16 = (int *)FUN_0044c500();
  in_ECX[6] = *piVar16;
  in_ECX[7] = piVar16[1];
  in_ECX[8] = piVar16[2];
  if (fStack_c4 == 0.0) {
    FUN_00441f90(0,local_dc);
  }
  if (fStack_cc == 0.0) {
    FUN_00441fc0(0,local_dc);
  }
  FUN_00527d30();
  iVar12 = FUN_0059b7d0();
  if (iVar12 == 0) {
    if (DAT_00d62f2a == '\0') {
      if (DAT_00b7fa10 == '\0') {
        DAT_00b7fa10 = DAT_00d62f2a;
        return;
      }
    }
    else {
      *local_a4 = *piStack_98;
      local_a4[1] = piStack_98[1];
    }
    FUN_0074c0f0();
    DAT_00b7fa10 = DAT_00d62f2a;
    return;
  }
  return;
}



// ?CanExist@CameraModeTwoObjects@@UAE_NXZ @ 0x0044ca00

void _CanExist_CameraModeTwoObjects__UAE_NXZ(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 8) != 0) {
    FUN_00623a60(*(int *)(in_ECX + 4) + 0x118,*(int *)(in_ECX + 4) + 0x88);
  }
  return;
}



// ?Restart@CameraModeTwoObjects@@UAEXXZ @ 0x0044cc20

void _Restart_CameraModeTwoObjects__UAEXXZ(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &vftable_CameraModeScript;
  FUN_0044d440();
  *in_ECX = &vftable_CameraMode;
  if ((param_1 & 1) != 0) {
    FUN_007290de();
  }
  return;
}



// ?IsStillValid@CameraModeTwoObjects@@UAE_NXZ @ 0x0044d720

undefined4 _IsStillValid_CameraModeTwoObjects__UAE_NXZ(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 8);
  if (*(int *)(in_ECX + 0x1c) == 0) {
    if (piVar1 == (int *)0x0) {
      return 0;
    }
    iVar2 = (**(code **)(*piVar1 + 0x2c))();
  }
  else {
    if (piVar1 == (int *)0x0) {
      return 0;
    }
    iVar2 = (**(code **)(*piVar1 + 0x2c))();
    if (iVar2 != 1) {
      return 0;
    }
    if (*(int **)(in_ECX + 0xc) == (int *)0x0) {
      return 0;
    }
    iVar2 = (**(code **)(**(int **)(in_ECX + 0xc) + 0x2c))();
  }
  if (iVar2 != 1) {
    return 0;
  }
  return *(undefined4 *)(in_ECX + 0x2c);
}



// ?Update@CameraModeTwoObjects@@UAEXXZ @ 0x0044d770

void _Update_CameraModeTwoObjects__UAEXXZ(void)

{
  undefined4 uVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  int *piVar7;
  int in_ECX;
  float10 fVar8;
  float10 fVar9;
  float10 fVar10;
  float fStack_c0;
  float fStack_bc;
  float fStack_b8;
  float fStack_a8;
  float fStack_a4;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float fStack_90;
  float fStack_8c;
  float fStack_88;
  float fStack_84;
  float fStack_80;
  float fStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if (*(float *)(*(int *)(in_ECX + 4) + 0x68) <= 1.5) {
    fStack_b8 = (*(float *)(*(int *)(in_ECX + 4) + 0x68) / 1.5) * -1.0 + 2.0;
  }
  else {
    fStack_b8 = 1.0;
  }
  iVar2 = *(int *)(in_ECX + 8);
  fVar3 = *(float *)(iVar2 + 0x1c);
  fVar8 = (float10)FUN_00760fd0();
  fVar3 = (float)(fVar8 + (float10)fVar3);
  fVar5 = (float)*(int *)(iVar2 + 0x14) * 0.00015258789;
  fVar6 = (float)*(int *)(iVar2 + 0x18) * 0.00015258789;
  if (*(int *)(in_ECX + 0x1c) == 0) {
    fStack_a8 = *(float *)(in_ECX + 0x10);
    fStack_a4 = *(float *)(in_ECX + 0x14);
    fStack_a0 = *(float *)(in_ECX + 0x18);
  }
  else {
    iVar2 = *(int *)(in_ECX + 0xc);
    fVar4 = *(float *)(iVar2 + 0x1c);
    fVar8 = (float10)FUN_00760fd0();
    fStack_a4 = (float)(fVar8 + (float10)fVar4);
    fStack_a8 = (float)*(int *)(iVar2 + 0x14) * 0.00015258789;
    fStack_a0 = (float)*(int *)(iVar2 + 0x18) * 0.00015258789;
  }
  fStack_68 = fStack_a4 + fVar3;
  fStack_64 = fStack_a0 + fVar6;
  fStack_9c = (fStack_a8 + fVar5) * 0.5;
  fStack_98 = fStack_68 * 0.5;
  fStack_94 = fStack_64 * 0.5;
  fStack_90 = fStack_9c;
  fStack_8c = fStack_98;
  fStack_88 = fStack_94;
  if (*(int *)(in_ECX + 0x1c) == 0) {
    fStack_bc = 1.0;
  }
  else {
    fVar8 = (float10)(**(code **)(**(int **)(in_ECX + 0xc) + 0x42c))();
    fStack_bc = (float)fVar8;
  }
  fVar9 = (float10)(**(code **)(**(int **)(in_ECX + 8) + 0x42c))();
  fVar8 = (float10)fStack_bc;
  if (*(int *)(in_ECX + 0x1c) == 0) {
    fStack_bc = 0.0;
  }
  else {
    fVar10 = (float10)(**(code **)(**(int **)(in_ECX + 0xc) + 0x42c))();
    fStack_bc = (float)fVar10;
  }
  fVar10 = (float10)(**(code **)(**(int **)(in_ECX + 8) + 0x42c))();
  if (fVar10 <= (float10)fStack_bc) {
    if (*(int *)(in_ECX + 0x1c) == 0) {
      fStack_bc = 0.0;
    }
    else {
      fVar10 = (float10)(**(code **)(**(int **)(in_ECX + 0xc) + 0x42c))();
      fStack_bc = (float)fVar10;
    }
  }
  else {
    fVar10 = (float10)(**(code **)(**(int **)(in_ECX + 8) + 0x42c))();
    fStack_bc = (float)fVar10;
  }
  fStack_98 = (float)((fVar9 + fVar8) * (float10)0.5) * 0.5 + fStack_98;
  FUN_00406240(fStack_9c,0,fStack_b8);
  FUN_00406240(fStack_98,0,fStack_b8);
  FUN_00406240(fStack_94,0,fStack_b8);
  if (*(float *)(in_ECX + 0x24) <= 0.24166098) {
    uVar1 = 0x3e7775fa;
  }
  else {
    uVar1 = *(undefined4 *)(in_ECX + 0x24);
  }
  *(undefined4 *)(in_ECX + 0x24) = uVar1;
  piVar7 = (int *)FUN_007344da(*(undefined4 *)(in_ECX + 8),0,&GameThingWithPos::RTTI_Type_Descriptor
                               ,&Object::RTTI_Type_Descriptor,0);
  if (piVar7 == (int *)0x0) {
    fStack_c0 = 30.0;
  }
  else {
    fVar8 = (float10)(**(code **)(*piVar7 + 100))();
    fStack_c0 = (float)fVar8;
  }
  if (*(int *)(in_ECX + 0x1c) != 0) {
    piVar7 = (int *)FUN_007344da(*(undefined4 *)(in_ECX + 0xc),0,
                                 &GameThingWithPos::RTTI_Type_Descriptor,
                                 &Object::RTTI_Type_Descriptor,0);
    if (piVar7 != (int *)0x0) {
      fVar8 = (float10)(**(code **)(*piVar7 + 100))();
      goto LAB_0044da12;
    }
  }
  fVar8 = (float10)30.0;
LAB_0044da12:
  fVar9 = (float10)fStack_c0;
  fVar4 = *(float *)(in_ECX + 0x28);
  fStack_84 = fStack_a8 - fVar5;
  fStack_80 = fStack_a4 - fVar3;
  fStack_7c = fStack_a0 - fVar6;
  if ((0.01 < ABS(fStack_84)) || (0.01 < ABS(fStack_7c))) {
    fVar10 = (float10)FUN_00759180(&fStack_84);
    fStack_c0 = (float)((float10)*(float *)(in_ECX + 0x20) - fVar10);
  }
  else {
    fStack_c0 = *(float *)(in_ECX + 0x20);
  }
  FUN_0043a640(&uStack_78,&fStack_9c,
               (float)((float10)fStack_bc * (float10)1.4 +
                      (SQRT(((float10)fVar6 - (float10)fStack_a0) *
                            ((float10)fVar6 - (float10)fStack_a0) +
                            ((float10)fVar5 - (float10)fStack_a8) *
                            ((float10)fVar5 - (float10)fStack_a8)) + fVar8 + fVar9) * (float10)fVar4
                      ),fStack_c0,*(undefined4 *)(in_ECX + 0x24));
  iVar2 = *(int *)(in_ECX + 4);
  FUN_00406240(uStack_78,0,fStack_b8);
  FUN_00406240(uStack_74,0,fStack_b8);
  if (fStack_b8 < 0.001) {
    *(undefined4 *)(iVar2 + 0x178) = uStack_70;
    *(undefined4 *)(iVar2 + 0x194) = uStack_70;
    *(undefined4 *)(iVar2 + 400) = 0;
    *(undefined4 *)(iVar2 + 0x18c) = 0;
    *(undefined4 *)(iVar2 + 0x1a4) = 0;
    *(undefined4 *)(iVar2 + 0x1a0) = 0;
    *(undefined4 *)(iVar2 + 0x188) = 0;
    *(undefined4 *)(iVar2 + 0x19c) = 0;
    *(undefined4 *)(iVar2 + 0x184) = 0;
    *(undefined4 *)(iVar2 + 0x198) = 0;
    *(undefined4 *)(iVar2 + 0x180) = 0;
    *(undefined4 *)(iVar2 + 0x17c) = uStack_70;
    return;
  }
  *(undefined4 *)(iVar2 + 0x17c) = uStack_70;
  *(undefined4 *)(iVar2 + 0x194) = *(undefined4 *)(iVar2 + 0x178);
  fStack_58 = fStack_b8 * fStack_b8 * 0.5;
  *(undefined4 *)(iVar2 + 0x198) = *(undefined4 *)(iVar2 + 0x184);
  *(float *)(iVar2 + 400) = fStack_b8;
  fStack_4c = fStack_b8;
  fStack_5c = fStack_58 * fStack_b8 * 0.33333334;
  *(undefined4 *)(iVar2 + 0x180) = 0;
  *(undefined4 *)(iVar2 + 0x18c) = 0;
  fStack_44 = fStack_b8;
  uStack_40 = 0x3f800000;
  fStack_60 = fStack_58 * fStack_58 * 0.16666667;
  uStack_34 = 0;
  uStack_38 = 0;
  uStack_3c = 0;
  fStack_54 = fStack_5c;
  fStack_50 = fStack_58;
  fStack_48 = fStack_58;
  FUN_00759970();
  fVar3 = (*(float *)(iVar2 + 0x17c) - *(float *)(iVar2 + 0x194)) -
          *(float *)(iVar2 + 400) * *(float *)(iVar2 + 0x198);
  fVar5 = *(float *)(iVar2 + 0x180) - *(float *)(iVar2 + 0x198);
  *(float *)(iVar2 + 0x1a0) = fStack_20 * fVar5 + fStack_2c * fVar3 + fStack_8;
  *(float *)(iVar2 + 0x19c) = fStack_28 * fVar3 + fStack_1c * fVar5 + fStack_4;
  *(float *)(iVar2 + 0x1a4) = fStack_30 * fVar3 + fStack_24 * fVar5 + fStack_c;
  return;
}



