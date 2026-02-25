// Decompiled functions for class: Tree
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetHoldType@Tree@@UAE?AW4HOLD_TYPE@@XZ @ 0x00418100

undefined4 _GetHoldType_Tree__UAE_AW4HOLD_TYPE__XZ(void)

{
  return 5;
}



// ?GetHowMuchCreatureWantsToLookAtMe@Tree@@UAEMXZ @ 0x004b5370

float10 _GetHowMuchCreatureWantsToLookAtMe_Tree__UAEMXZ(void)

{
  return (float10)0.3;
}



// ?IsTreeNotTooNearPlannedForest@Tree@@UAEIPAVCreature@@@Z @ 0x004c5ae0

undefined4 _IsTreeNotTooNearPlannedForest_Tree__UAEIPAVCreature___Z(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  float10 fVar4;
  
  uVar3 = 0;
  if (*(uint *)(param_1 + 0x1154) != 0) {
    do {
      iVar1 = *(int *)(param_1 + 0x1150) - uVar3;
      iVar2 = iVar1 + -1;
      if (iVar2 < 0) {
        iVar2 = iVar1 + 9;
      }
      if (*(int *)(param_1 + 0x1128 + iVar2 * 4) == in_ECX) {
        return 0;
      }
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(param_1 + 0x1154));
  }
  fVar4 = (float10)FUN_006de0a0(*(int *)(param_1 + 0x164) + 0x1c60,in_ECX + 0x14);
  if (fVar4 <= (float10)20.0) {
    return 0;
  }
  return 1;
}



// ?CanBePickedUpByCreature@Tree@@UAEIPAVCreature@@@Z @ 0x004c5e30

undefined4 _CanBePickedUpByCreature_Tree__UAEIPAVCreature___Z(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  if ((*(byte *)(in_ECX + 0x25) & 0x20) == 0) {
    iVar1 = _CanBePickedUpByCreature_Object__UAE_NPAVCreature___Z(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}



// ?ApplyThisToObject@Tree@@UAEIPAVGInterfaceStatus@@PAVObject@@PAUGestureSystemPacketData@@@Z @ 0x004ee4a0

undefined4
_ApplyThisToObject_Tree__UAEIPAVGInterfaceStatus__PAVObject__PAUGestureSystemPacketData___Z
          (undefined4 param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = FUN_007344da(param_2,0,&Object::RTTI_Type_Descriptor,&WorshipTotem::RTTI_Type_Descriptor,0
                      );
  if (iVar1 != 0) {
    return 1;
  }
  if (param_2 != (int *)0x0) {
    iVar1 = (**(code **)(*param_2 + 0x680))(1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}



// ?GetCreatureMimicType@Tree@@UAEIXZ @ 0x0052e220

undefined4 _GetCreatureMimicType_Tree__UAEIXZ(void)

{
  return 6;
}



// ?GetMesh@Tree@@UBEHXZ @ 0x0052ebd0

undefined4 _GetMesh_Tree__UBEHXZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x28) + 0x100);
}



// ?GetComputerSeen@Tree@@UAE_NXZ @ 0x0052ebe0

void _GetComputerSeen_Tree__UAE_NXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x86c))();
  if (iVar1 != 0) {
    (**(code **)(*in_ECX + 0x86c))();
    return;
  }
  return;
}



// ?GetSaveType@Tree@@UAEIXZ @ 0x0052ec00

undefined4 _GetSaveType_Tree__UAEIXZ(void)

{
  return 0x4f;
}



// ?GetDebugText@Tree@@UAEPADXZ @ 0x0052ec10

char * _GetDebugText_Tree__UAEPADXZ(void)

{
  return s_Tree__00b1a408;
}



// ?CallVirtualFunctionsForCreation@Tree@@UAEXABUMapCoords@@@Z @ 0x006db580

void _CallVirtualFunctionsForCreation_Tree__UAEXABUMapCoords___Z(int *param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  ushort uVar7;
  int *in_ECX;
  float10 fVar8;
  
  _Get3DType_Object__UAE_AW4LH3DObject__ObjectType__XZ(param_1);
  (**(code **)(*(int *)in_ECX[0x10] + 0x58))();
  (**(code **)(*(int *)in_ECX[0x10] + 0x90))();
  (**(code **)(*(int *)in_ECX[0x10] + 0x78))();
  fVar8 = (float10)(**(code **)(*in_ECX + 0x120))();
  fVar3 = (float)fVar8;
  fVar8 = (float10)(**(code **)(*in_ECX + 0x508))();
  fVar4 = (float)fVar8;
  fVar5 = (float)param_1[2];
  iVar6 = in_ECX[0x10];
  fVar8 = (float10)FUN_00760fd0();
  iVar1 = *param_1;
  iVar2 = param_1[1];
  if (fVar4 == 0.0) {
    if (fVar3 == 1.0) {
      FUN_004022b0();
    }
    else {
      FUN_004f5940(fVar3);
      FUN_004022f0();
    }
  }
  else if (fVar3 == 1.0) {
    FUN_00402280();
    *(float *)(iVar6 + 0x38) = (float)iVar1 * 0.00015258789;
    *(float *)(iVar6 + 0x3c) = (float)(fVar8 + (float10)fVar5);
    *(float *)(iVar6 + 0x40) = (float)iVar2 * 0.00015258789;
    FUN_004f5f10(fVar4);
  }
  else {
    *(undefined4 *)(iVar6 + 0x40) = 0;
    *(undefined4 *)(iVar6 + 0x3c) = 0;
    *(undefined4 *)(iVar6 + 0x38) = 0;
    *(undefined4 *)(iVar6 + 0x30) = 0;
    *(undefined4 *)(iVar6 + 0x2c) = 0;
    *(undefined4 *)(iVar6 + 0x28) = 0;
    *(undefined4 *)(iVar6 + 0x20) = 0;
    *(undefined4 *)(iVar6 + 0x1c) = 0;
    *(undefined4 *)(iVar6 + 0x18) = 0;
    *(float *)(iVar6 + 0x34) = fVar3;
    *(float *)(iVar6 + 0x14) = fVar3;
    *(float *)(iVar6 + 0x24) = fVar3;
    *(float *)(iVar6 + 0x38) = (float)iVar1 * 0.00015258789 + *(float *)(iVar6 + 0x38);
    *(float *)(iVar6 + 0x3c) = (float)(fVar8 + (float10)fVar5) + *(float *)(iVar6 + 0x3c);
    *(float *)(iVar6 + 0x40) = (float)iVar2 * 0.00015258789 + *(float *)(iVar6 + 0x40);
    FUN_004f5f10(fVar4);
  }
  *(float *)(iVar6 + 0x44) = fVar3;
  *(float *)(iVar6 + 0x48) = fVar4;
  (**(code **)(*(int *)in_ECX[0x10] + 0x10))();
  (**(code **)(*in_ECX + 0x508))();
  uVar7 = __ftol();
  *(ushort *)(in_ECX + 0x17) = (uVar7 & 0xf) << 2 | *(ushort *)(in_ECX + 0x17) & 0xffc3;
  *(undefined4 *)(in_ECX[0x10] + 0x10) = 0xbdcccccd;
  *(uint *)(in_ECX[0x10] + 8) = *(uint *)(in_ECX[0x10] + 8) | 0x80;
  return;
}



// ?GetVillagerHugRadius@Tree@@UAEMXZ @ 0x006db790

float10 _GetVillagerHugRadius_Tree__UAEMXZ(void)

{
  int *in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 100))();
  if ((float10)0.25 < fVar1 * (float10)0.1) {
    return (float10)0.25;
  }
  fVar1 = (float10)(**(code **)(*in_ECX + 100))();
  return fVar1 * (float10)0.1;
}



// ?SetLife@Tree@@UAEXM@Z @ 0x006db7d0

void _SetLife_Tree__UAEXM_Z(float param_1)

{
  int *in_ECX;
  
  if (param_1 <= 0.0) {
    (**(code **)(*in_ECX + 0xc))(0);
    return;
  }
  _SetLife_Object__UAEXM_Z(param_1);
  return;
}



// ?ToBeDeleted@Tree@@UAEXH@Z @ 0x006db800

void _ToBeDeleted_Tree__UAEXH_Z(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int *in_ECX;
  
  iVar6 = (**(code **)(*in_ECX + 0x86c))();
  if (iVar6 != 0) {
    FUN_0050e810(in_ECX);
    in_ECX[0x1a] = 0;
  }
  iVar6 = DAT_00c22ca4;
  if ((*(byte *)((int)in_ECX + 10) & 1) == 0) {
    piVar1 = (int *)(DAT_00c22ca4 + 0x201d98);
    piVar5 = (int *)0x0;
    piVar2 = *(int **)(DAT_00c22ca4 + 0x201d98);
    while (piVar4 = piVar2, piVar3 = piVar5, piVar4 != (int *)0x0) {
      piVar2 = (int *)*piVar4;
      piVar5 = piVar4;
      if ((int *)piVar4[1] == in_ECX) {
        if (piVar4 == (int *)*piVar1) {
          *piVar1 = (int)piVar2;
        }
        else {
          *piVar3 = (int)piVar2;
        }
        *(int *)(iVar6 + 0x201d9c) = *(int *)(iVar6 + 0x201d9c) + -1;
        FUN_007290de(piVar4);
        piVar5 = piVar3;
      }
    }
  }
  _ToBeDeleted_Object__UAEXH_Z(param_1);
  return;
}



// ?Process@Tree@@UAEIXZ @ 0x006db880

undefined4 _Process_Tree__UAEIXZ(void)

{
  float fVar1;
  float fVar2;
  undefined4 uVar3;
  int *in_ECX;
  float10 fVar4;
  float10 fVar5;
  undefined1 auStack_c [12];
  
  *(short *)(in_ECX + 0x18) = (short)in_ECX[0x18] + -1;
  if ((short)in_ECX[0x18] != 0) {
    return 1;
  }
  *(undefined2 *)(in_ECX + 0x18) = *(undefined2 *)(in_ECX[10] + 0x118);
  if ((*(byte *)((int)in_ECX + 0x5e) & 1) != 0) {
    fVar4 = (float10)(**(code **)(*in_ECX + 0x120))();
    if (fVar4 < (float10)(float)in_ECX[0x19]) {
      fVar2 = *(float *)(in_ECX[10] + 0x11c);
      uVar3 = FUN_005c0400(auStack_c);
      fVar4 = (float10)FUN_006fe770(uVar3);
      fVar1 = *(float *)(in_ECX[10] + 0x130);
      fVar5 = (float10)FUN_005c1450();
      FUN_006db9e0((float)((fVar5 * (float10)0.5 + (float10)1.0) *
                          (float10)(float)(fVar4 * (float10)0.01 * (float10)fVar1 * (float10)fVar2 +
                                          (float10)fVar2)),0,0);
      if ((*(byte *)((int)in_ECX + 0x5e) & 1) != 0) {
        fVar4 = (float10)(**(code **)(*in_ECX + 0x120))();
        if (fVar4 < (float10)(float)in_ECX[0x19]) {
          return 1;
        }
      }
      return 0;
    }
  }
  return 0;
}



// ?Draw@Tree@@UAEXXZ @ 0x006dc020

void _Draw_Tree__UAEXXZ(void)

{
  undefined4 *puVar1;
  int *piVar2;
  uint uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  int *in_ECX;
  float *pfVar10;
  float *pfVar11;
  float10 fVar12;
  float10 fVar13;
  float10 fVar14;
  float10 fVar15;
  float10 fVar16;
  float fStack_ac;
  float fStack_a8;
  float fStack_a4;
  float fStack_a0;
  float fStack_9c;
  float fStack_98;
  float fStack_94;
  float fStack_90;
  float afStack_8c [3];
  float fStack_80;
  float afStack_7c [4];
  float fStack_6c;
  float fStack_68;
  float fStack_64;
  float fStack_60;
  float fStack_5c;
  float fStack_58;
  float fStack_54;
  float fStack_50;
  float fStack_4c;
  float fStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  float afStack_30 [12];
  
  puVar1 = (undefined4 *)(in_ECX[0x10] + 0x50);
  iVar9 = in_ECX[0x10] + 0x4c;
  FUN_00760090(in_ECX + 5,iVar9,puVar1);
  afStack_8c[0] = (float)in_ECX[6];
  afStack_8c[1] = 0.0;
  fStack_9c = (float)(uint)in_ECX[5] * 0.00015258789;
  fStack_98 = 0.0;
  fStack_94 = (float)(uint)afStack_8c[0] * 0.00015258789;
  uVar7 = FUN_0075d130(&fStack_9c,*puVar1,iVar9);
  *puVar1 = uVar7;
  if (in_ECX[0x10] != 0) {
    *(undefined4 *)(in_ECX[0x10] + 100) = 1;
  }
  if ((*(ushort *)(in_ECX + 0x17) & 0x3c0) != 0) {
    piVar2 = (int *)in_ECX[0x10];
    iVar8 = ((*(ushort *)(in_ECX + 0x17) & 0x3c0) >> 6) * 0x10;
    fVar12 = (float10)(**(code **)(*in_ECX + 0x120))();
    afStack_8c[0] = (float)fVar12;
    iVar9 = (**(code **)(*piVar2 + 0xf8))();
    fVar4 = afStack_8c[0] * *(float *)(iVar9 + 0x28);
    iVar9 = in_ECX[0x10];
    if (*(float *)(&DAT_00c3ab5c + iVar8) <= fVar4 + fVar4 + *(float *)(iVar9 + 0x3c)) {
      fStack_a8 = *(float *)(iVar9 + 0x3c);
      fStack_ac = *(float *)(&DAT_00c3ab58 + iVar8);
      fStack_a4 = *(float *)(&DAT_00c3ab60 + iVar8);
      fStack_9c = fStack_ac;
      fStack_98 = fStack_a8;
      fStack_94 = fStack_a4;
      FUN_004402a0(iVar9 + 0x38);
      FUN_004aaa10(afStack_8c);
      fVar12 = (float10)FUN_00489b90();
      afStack_8c[0] = (float)fVar12;
      fStack_a0 = *(float *)(&DAT_00c3ab64 + iVar8);
      if (fVar12 < (float10)fStack_a0) {
        iVar9 = in_ECX[0x10];
        fStack_ac = *(float *)(iVar9 + 0x38) - fStack_9c;
        fStack_a8 = *(float *)(iVar9 + 0x3c) - fStack_98;
        fStack_a4 = *(float *)(iVar9 + 0x40) - fStack_94;
        fVar12 = (float10)FUN_00795d80(fStack_a4 * fStack_a4 +
                                       fStack_a8 * fStack_a8 + fStack_ac * fStack_ac);
        fStack_ac = (float)((float10)fStack_ac * fVar12);
        fStack_9c = 0.0;
        fStack_98 = -1.0;
        fStack_94 = 0.0;
        fStack_a8 = (float)((float10)fStack_a8 * fVar12);
        fStack_a4 = (float)((float10)fStack_a4 * fVar12);
        fVar12 = (float10)FUN_00795e70(&fStack_9c,&fStack_ac);
        fStack_90 = (float)(fVar12 + (float10)1.5707964);
        afStack_8c[0] = 1.0 - (((fStack_a0 - 0.75) * afStack_8c[0]) / fStack_a0 + 0.75) / fStack_a0;
        fVar12 = (float10)(**(code **)(*in_ECX + 0x508))();
        fVar13 = (float10)fcos(fVar12 - (float10)fStack_90);
        fVar12 = (float10)fsin(fVar12 - (float10)fStack_90);
        fVar14 = (float10)fcos((float10)0.47123894 * (float10)afStack_8c[0]);
        fStack_48 = (float)fVar14;
        fVar14 = (float10)fsin((float10)0.47123894 * (float10)afStack_8c[0]);
        fStack_4c = (float)fVar14;
        fStack_a0 = 0.0;
        fVar14 = (float10)0.0;
        afStack_7c[1] = (float)((float10)(float)fVar12 * (float10)fStack_4c + fVar14);
        fVar4 = (float)fVar12 * fStack_48 - 0.0;
        fStack_6c = fStack_48 + 0.0;
        fStack_60 = (float)((float10)(float)fVar13 * (float10)fStack_4c + fVar14);
        fVar5 = (float)fVar13 * fStack_48 - 0.0;
        fVar15 = (float10)fcos((float10)fStack_90);
        fVar16 = (float10)fsin((float10)fStack_90);
        afStack_7c[0] = (float)(fVar15 * (float10)(float)fVar13 - (float10)fVar4 * fVar16);
        afStack_7c[2] = (float)((float10)fVar4 * fVar15 + fVar16 * (float10)(float)fVar13);
        fStack_90 = (float)(float10)0.0;
        afStack_7c[3] =
             (float)((float10)0.0 - (float10)(float)(fVar14 - (float10)fStack_4c) * fVar16);
        fStack_68 = (float)((float10)(float)(fVar14 - (float10)fStack_4c) * fVar15 + (float10)0.0);
        iVar9 = in_ECX[0x10];
        fStack_64 = (float)((float10)(float)-fVar12 * fVar15 - (float10)fVar5 * fVar16);
        fStack_5c = (float)((float10)fVar5 * fVar15 + (float10)(float)-fVar12 * fVar16);
        fStack_80 = (float)(float10)0.0;
        fStack_58 = (float)((float10)fStack_90 - (fVar14 - (float10)0.0) * fVar16) +
                    *(float *)(iVar9 + 0x38);
        fStack_54 = (float)((float10)0.0 + fVar14) + *(float *)(iVar9 + 0x3c);
        fStack_50 = (float)((fVar14 - (float10)0.0) * fVar15 + (float10)fStack_80 +
                           (float10)*(float *)(iVar9 + 0x40));
        fVar12 = (float10)(**(code **)(*in_ECX + 0x120))();
        iVar9 = in_ECX[0x10];
        afStack_7c[0] = (float)(fVar12 * (float10)afStack_7c[0]);
        pfVar10 = (float *)(iVar9 + 0x14);
        pfVar11 = afStack_30;
        for (iVar8 = 0xc; iVar8 != 0; iVar8 = iVar8 + -1) {
          *pfVar11 = *pfVar10;
          pfVar10 = pfVar10 + 1;
          pfVar11 = pfVar11 + 1;
        }
        afStack_7c[1] = (float)((float10)afStack_7c[1] * fVar12);
        afStack_7c[2] = (float)((float10)afStack_7c[2] * fVar12);
        afStack_7c[3] = (float)((float10)afStack_7c[3] * fVar12);
        fStack_6c = (float)((float10)fStack_6c * fVar12);
        fStack_68 = (float)((float10)fStack_68 * fVar12);
        fStack_64 = (float)((float10)fStack_64 * fVar12);
        fStack_60 = (float)((float10)fStack_60 * fVar12);
        fStack_5c = (float)((float10)fStack_5c * fVar12);
        pfVar10 = afStack_7c;
        pfVar11 = (float *)(iVar9 + 0x14);
        for (iVar8 = 0xc; iVar8 != 0; iVar8 = iVar8 + -1) {
          *pfVar11 = *pfVar10;
          pfVar10 = pfVar10 + 1;
          pfVar11 = pfVar11 + 1;
        }
        if (0.3 <= afStack_8c[0]) {
          uStack_44 = 2;
          if (0.67 <= afStack_8c[0]) {
            uStack_44 = 1;
          }
        }
        else {
          uStack_44 = 3;
        }
        uStack_40 = 0;
        uStack_3c = 0;
        uStack_38 = 10;
        uStack_34 = 0x4b;
        FUN_0051f3d0();
        fStack_9c = DAT_00d78bd8;
        iVar9 = in_ECX[0x10];
        fVar4 = DAT_00d78bd8 - *(float *)(iVar9 + 0x38);
        fStack_98 = DAT_00d78bdc;
        fVar5 = DAT_00d78bdc - *(float *)(iVar9 + 0x3c);
        fStack_94 = DAT_00d78be0;
        fVar6 = DAT_00d78be0 - *(float *)(iVar9 + 0x40);
        FUN_00424390(in_ECX,SQRT(fVar5 * fVar5 + fVar6 * fVar6 + fVar4 * fVar4),&uStack_44,0,
                     *(undefined4 *)(DAT_00bf4e68 + 0x3b0),0,0,0);
        goto LAB_006dc587;
      }
    }
    *(ushort *)(in_ECX + 0x17) = *(ushort *)(in_ECX + 0x17) & 0xfc3f;
  }
  afStack_8c[0] = *(float *)(in_ECX[0x10] + 0x20);
  fStack_90 = *(float *)(in_ECX[0x10] + 0x28);
  fVar12 = (float10)(**(code **)(*in_ECX + 0x120))();
  *(float *)(in_ECX[0x10] + 0x20) =
       (float)(fVar12 * (float10)*(float *)((int)&DAT_00cc46a4 + (*(byte *)(in_ECX + 0x17) & 0x3c)))
  ;
  fVar12 = (float10)(**(code **)(*in_ECX + 0x120))();
  *(float *)(in_ECX[0x10] + 0x28) =
       (float)(fVar12 * (float10)*(float *)((int)&DAT_00cc4664 + (*(byte *)(in_ECX + 0x17) & 0x3c)))
  ;
LAB_006dc587:
  if (in_ECX[0x11] == 0) {
    uVar3 = *(uint *)(in_ECX[0x10] + 0x4c);
    *(uint *)(in_ECX[0x10] + 0x4c) =
         ((uVar3 & 0xff0000) * DAT_00b45eec & 0xff0000ff |
          (uVar3 & 0xff00) * DAT_00b45eec & 0xff0000 | (uVar3 & 0xff) * DAT_00b45eec & 0xff00) >> 8
         | uVar3 & 0xff000000;
    FUN_005ed470();
  }
  else {
    FUN_006dc8c0(1);
  }
  if ((*(ushort *)(in_ECX + 0x17) & 0x3c0) == 0) {
    *(float *)(in_ECX[0x10] + 0x20) = afStack_8c[0];
    *(float *)(in_ECX[0x10] + 0x28) = fStack_90;
  }
  else {
    *(ushort *)(in_ECX + 0x17) = *(ushort *)(in_ECX + 0x17) & 0xfc3f;
    pfVar10 = afStack_30;
    pfVar11 = (float *)(in_ECX[0x10] + 0x14);
    for (iVar9 = 0xc; iVar9 != 0; iVar9 = iVar9 + -1) {
      *pfVar11 = *pfVar10;
      pfVar10 = pfVar10 + 1;
      pfVar11 = pfVar11 + 1;
    }
  }
  afStack_8c[0] = *(float *)(DAT_00c22ca4 + 0x201e04);
  afStack_8c[1] = 0.0;
  uVar7 = __ftol();
  iVar9 = FUN_0067bcf0(uVar7);
  if (iVar9 == 1) {
    (**(code **)(*in_ECX + 0x10))(&fStack_9c);
    FUN_0051f3d0();
    fVar4 = DAT_00d78bd8;
    fStack_ac = DAT_00d78bdc;
    fStack_a8 = DAT_00d78be0;
    if ((((ABS(fStack_a0 - DAT_00d78bd8) <= 10.0) && (ABS(fStack_98 - DAT_00d78be0) <= 10.0)) &&
        (ABS(DAT_00d78bdc - fStack_9c) < 18.0)) &&
       (fVar12 = (float10)(**(code **)(*in_ECX + 0x42c))(), (float10)10.0 < fVar12)) {
      fStack_48 = 0.0;
      uStack_44 = 0;
      uStack_40 = 0x14;
      uStack_3c = 0;
      uStack_38 = 0x46;
      FUN_00424390(in_ECX,SQRT((fStack_a0 - fVar4) * (fStack_a0 - fVar4) +
                               (fStack_9c - fStack_ac) * (fStack_9c - fStack_ac) +
                               (fStack_98 - fStack_a8) * (fStack_98 - fStack_a8)),&fStack_48,0,
                   *(undefined4 *)(DAT_00bf4e68 + 0x3b0),1,0,0);
    }
  }
  return;
}



// ?DrawOutOfMap@Tree@@UAEX_N@Z @ 0x006dc790

void _DrawOutOfMap_Tree__UAEX_N_Z(undefined4 param_1)

{
  uint *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int *in_ECX;
  float afStack_c [3];
  
  if (in_ECX[0x10] != 0) {
    puVar1 = (uint *)(in_ECX[0x10] + 8);
    *puVar1 = *puVar1 | 0x40;
    iVar4 = (**(code **)(*in_ECX + 2000))();
    if (iVar4 != 0) {
      FUN_004ee820(in_ECX[0x10]);
    }
    puVar2 = (undefined4 *)(in_ECX[0x10] + 0x50);
    iVar4 = in_ECX[0x10] + 0x4c;
    FUN_00760090(in_ECX + 5,iVar4,puVar2);
    afStack_c[0] = (float)(uint)in_ECX[5] * 0.00015258789;
    afStack_c[1] = 0.0;
    afStack_c[2] = (float)(uint)in_ECX[6] * 0.00015258789;
    uVar5 = FUN_0075d130(afStack_c,*puVar2,iVar4);
    *puVar2 = uVar5;
    *(undefined4 *)(in_ECX[0x10] + 0x5c) = 0x40;
    *(undefined4 *)(in_ECX[0x10] + 0x60) = 0x80;
    if (in_ECX[0x11] == 0) {
      uVar3 = *(uint *)(in_ECX[0x10] + 0x4c);
      *(uint *)(in_ECX[0x10] + 0x4c) =
           ((uVar3 & 0xff0000) * DAT_00b45eec & 0xff0000ff |
            (uVar3 & 0xff00) * DAT_00b45eec & 0xff0000 | (uVar3 & 0xff) * DAT_00b45eec & 0xff00) >>
           8 | uVar3 & 0xff000000;
      FUN_005ed470();
    }
    else {
      FUN_006dc8c0(param_1);
    }
    if (in_ECX[0x10] != 0) {
      puVar1 = (uint *)(in_ECX[0x10] + 8);
      *puVar1 = *puVar1 & 0xffffffbf;
    }
  }
  return;
}



// ?GetHoldRadius@Tree@@UAEMXZ @ 0x006dcb20

float10 _GetHoldRadius_Tree__UAEMXZ(void)

{
  int *in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 100))();
  return fVar1 * (float10)0.2;
}



// ?GetHoldLoweringMultiplier@Tree@@UAEMXZ @ 0x006dcb30

float10 _GetHoldLoweringMultiplier_Tree__UAEMXZ(void)

{
  return (float10)0.1;
}



// ?EndPhysics@Tree@@UAEXPAVPhysicsObject@@_N@Z @ 0x006dcb40

void _EndPhysics_Tree__UAEXPAVPhysicsObject___N_Z(undefined4 param_1)

{
  int *in_ECX;
  float10 fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 0x120))();
  fVar4 = (float)fVar1;
  fVar1 = (float10)(**(code **)(*in_ECX + 100))(fVar4);
  fVar3 = (float)fVar1;
  fVar1 = (float10)(**(code **)(*in_ECX + 0x42c))(fVar3);
  fVar2 = (float)fVar1;
  fVar1 = (float10)(**(code **)(*in_ECX + 0x638))(fVar2);
  FUN_005ec4a0(param_1,(float)fVar1,fVar2,fVar3,fVar4);
  return;
}



// ?CanBecomeAPhysicsObject@Tree@@UAE_NXZ @ 0x006dcb90

void _CanBecomeAPhysicsObject_Tree__UAE_NXZ(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 in_ECX;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  piVar1 = (int *)FUN_005f3c50();
  if ((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x680))(1), iVar2 != 0)) {
    puVar3 = (undefined4 *)(param_1 + 0x1a8);
    puVar4 = &DAT_00c62258;
    for (iVar2 = 0xc; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    iVar2 = (**(code **)(*piVar1 + 0x684))(in_ECX,*(undefined4 *)(param_1 + 0x24));
    if (iVar2 != 0) {
      return;
    }
  }
  _UpdateSpellInfo_GameThing__QAEXPAVSpell__PAVPSysProcessInfo___Z(param_1,param_2);
  return;
}



// ?GetOverwriteDropToolTip@Tree@@UAEIXZ @ 0x006dcc60

undefined4 _GetOverwriteDropToolTip_Tree__UAEIXZ(void)

{
  return 0xeef;
}



// ?GetDefaultResource@Tree@@UAEHXZ @ 0x006dcc70

void _GetDefaultResource_Tree__UAEHXZ(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x664))();
  __ftol();
  return;
}



// ?GetWoodValue@Tree@@UAEMXZ @ 0x006dcc80

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 _GetWoodValue_Tree__UAEMXZ(void)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  
  fVar2 = (float10)(**(code **)(*in_ECX + 0x120))();
  iVar1 = in_ECX[10];
  fVar3 = (float10)(**(code **)(*in_ECX + 0x868))();
  fVar4 = (float10)(**(code **)(*in_ECX + 0x11c))();
  return fVar4 * (float10)(float)fVar3 * (float10)*(int *)(iVar1 + 0x6c) * (float10)(float)fVar2 *
         (float10)_DAT_00c3b3a4;
}



// ?DropSfx@Tree@@UAEIXZ @ 0x006dcce0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int * _DropSfx_Tree__UAEIXZ(int param_1,undefined4 param_2)

{
  float fVar1;
  undefined4 *puVar2;
  bool bVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *in_ECX;
  float10 fVar7;
  float10 fVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  float fStack_3c;
  int iStack_34;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  float fStack_20;
  undefined4 uStack_1c;
  int iStack_18;
  int iStack_14;
  int iStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  if (((*(byte *)(in_ECX + 9) & 0x40) != 0) && ((*(byte *)((int)in_ECX + 10) & 0x10) == 0)) {
    if ((char)param_2 == '\0') {
      piVar4 = (int *)_EndPhysics_Fixed__UAEXPAVPhysicsObject___N_Z(param_1,0);
      return piVar4;
    }
    if ((*(byte *)(param_1 + 0x1d8) & 8) != 0) {
      if ((*(byte *)(in_ECX + 0x17) & 2) == 2) {
        piVar4 = (int *)_EndPhysics_Fixed__UAEXPAVPhysicsObject___N_Z(param_1,param_2);
        return piVar4;
      }
      iVar5 = FUN_005bfc70();
      if ((iVar5 != 0) && (in_ECX[0x11] == 0)) {
        iStack_18 = in_ECX[5];
        iStack_14 = in_ECX[6];
        iStack_10 = in_ECX[7];
        in_ECX[7] = 0;
        bVar3 = false;
        iVar5 = in_ECX[0x10];
        uStack_24 = *(undefined4 *)(iVar5 + 0x38);
        fStack_20 = *(float *)(iVar5 + 0x3c);
        uStack_1c = *(undefined4 *)(iVar5 + 0x40);
        iVar5 = 0;
        fStack_3c = 99999.0;
        uStack_c = __ftol();
        uStack_8 = __ftol();
        uStack_4 = 0;
        fVar7 = (float10)FUN_00760fd0();
        fStack_20 = (float)fVar7;
        FUN_0077da10(&uStack_24,1,0x3f800000,0xffffffff);
        iVar6 = FUN_005ec980();
        if (iVar6 != 0) {
          uVar10 = 0x80000000;
          uVar9 = 0x2e;
          FUN_00667ed0(0x2e,0x80000000);
          FUN_00598f00(uVar9,uVar10);
        }
        iStack_34 = 1000;
        uStack_28 = 1;
        uStack_2c = 1;
        do {
          fVar7 = (float10)FUN_006de0a0(in_ECX + 5,&iStack_18);
          if ((float10)_DAT_00b45ef0 + (float10)10.0 < fVar7) break;
          piVar4 = (int *)FUN_005bfa60();
          while (piVar4 != (int *)0x0) {
            fVar7 = (float10)FUN_005c18d0(in_ECX + 5);
            fVar8 = (float10)(**(code **)(*piVar4 + 100))();
            fVar1 = (float)((float10)(float)fVar7 - fVar8);
            if (((float10)(float)fVar7 - fVar8 < (float10)_DAT_00b45ef0) &&
               ((iVar6 = (**(code **)(*piVar4 + 0x48))(), iVar6 != 0 ||
                (iVar6 = FUN_005ea4a0(), iVar6 != 0)))) {
              bVar3 = true;
              iVar6 = (**(code **)(*piVar4 + 0x48))();
              if (iVar6 != 0) {
                iVar6 = (**(code **)(*piVar4 + 0x48))();
                for (puVar2 = *(undefined4 **)(iVar6 + 0x600); puVar2 != (undefined4 *)0x0;
                    puVar2 = (undefined4 *)*puVar2) {
                  if (*(int *)(puVar2[1] + 0x3c) != 0) {
                    fStack_3c = 0.0;
                    iVar5 = puVar2[1];
                  }
                }
              }
              break;
            }
            piVar4 = (int *)FUN_007344da(piVar4,0,&Object::RTTI_Type_Descriptor,
                                         &Tree::RTTI_Type_Descriptor,0);
            if (((piVar4 != (int *)0x0) && (iVar6 = (**(code **)(*piVar4 + 0x86c))(), iVar6 != 0))
               && (fVar1 < fStack_3c)) {
              iVar5 = (**(code **)(*piVar4 + 0x86c))();
              fStack_3c = fVar1;
            }
            piVar4 = (int *)FUN_005ea910(&iStack_18);
          }
          iStack_34 = iStack_34 + -1;
          uVar9 = FUN_006de790(&uStack_28,&uStack_2c);
          FUN_005c1300(uVar9);
        } while (iStack_34 != 0);
        iVar6 = (**(code **)(*in_ECX + 0x86c))();
        if (iVar6 != 0) {
          piVar4 = in_ECX;
          (**(code **)(*in_ECX + 0x86c))();
          FUN_0050e810(piVar4);
          in_ECX[0x1a] = 0;
        }
        *(byte *)((int)in_ECX + 0x5e) = bVar3 << 1 | *(byte *)((int)in_ECX + 0x5e) & 0xfd;
        if (iVar5 == 0) {
          if (bVar3) goto LAB_006dd017;
          iVar5 = FUN_004300a0(0x58,s_C__dev_black_Tree_cpp_00b45f10,0x35b);
          if (iVar5 == 0) {
            iVar5 = 0;
          }
          else {
            iVar5 = FUN_0050e200(in_ECX + 5,0);
          }
          in_ECX[0x1a] = iVar5;
        }
        else {
          in_ECX[0x1a] = iVar5;
        }
        FUN_0050e900(in_ECX);
LAB_006dd017:
        if (((*(byte *)((int)in_ECX + 0x5e) & 2) == 0) &&
           (piVar4 = (int *)FUN_005efc40(in_ECX + 5,0x2c,0x3e99999a,0x32,0), piVar4 != (int *)0x0))
        {
          iVar5 = *piVar4;
          uVar9 = FUN_005f6180();
          (**(code **)(iVar5 + 0x20))(uVar9);
        }
        iVar5 = FUN_005f6180();
        if (iVar5 != 0) {
          FUN_004cb260(*(undefined4 *)(param_1 + 0x24),0xb,in_ECX,0);
          FUN_004124b0(iVar5,in_ECX,1);
        }
        piVar4 = (int *)_EndPhysics_Fixed__UAEXPAVPhysicsObject___N_Z(param_1,param_2);
        return piVar4;
      }
    }
    FUN_005f6180();
    piVar4 = (int *)FUN_004ee1c0();
    if (piVar4 != (int *)0x0) {
      piVar4[0xb] = piVar4[5];
      piVar4[0xc] = piVar4[6];
      piVar4[0xd] = piVar4[7];
      (**(code **)(*piVar4 + 0x544))();
      *(ushort *)(piVar4 + 0x26) = *(ushort *)(piVar4 + 0x26) | 0x10;
      iVar5 = (**(code **)(*in_ECX + 0x448))();
      if (iVar5 != 0) {
        FUN_006a6760();
      }
      (**(code **)(*in_ECX + 0xc))(0);
      return piVar4;
    }
  }
  return in_ECX;
}



// ?GetWorkingPos@Tree@@UAEPAUMapCoords@@PAU2@PAVObject@@@Z @ 0x006dd4a0

undefined4 _GetWorkingPos_Tree__UAEPAUMapCoords__PAU2_PAVObject___Z(undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  int in_ECX;
  float10 fVar2;
  float10 fVar3;
  undefined1 auStack_c [12];
  
  fVar2 = (float10)FUN_006de3e0(in_ECX + 0x14,param_2 + 5);
  fVar3 = (float10)(**(code **)(*param_2 + 100))();
  uVar1 = FUN_006de5a0(auStack_c,(float)fVar2,(float)(fVar3 + (float10)0.9));
  FUN_005c1360(param_1,uVar1);
  return param_1;
}



// ?IsTreeBigEnoughForCreature@Tree@@UAEIPAVCreature@@@Z @ 0x006dd500

undefined4 _IsTreeBigEnoughForCreature_Tree__UAEIPAVCreature___Z(void)

{
  float fVar1;
  int iVar2;
  int *in_ECX;
  float10 fVar3;
  
  iVar2 = FUN_004619d0();
  fVar1 = *(float *)(iVar2 + 0x90);
  fVar3 = (float10)(**(code **)(*in_ECX + 0x42c))();
  if ((float10)(fVar1 * 15.0) <= fVar3) {
    return 1;
  }
  return 0;
}



// ?AddToRoutePlan@Tree@@UAEXPAURPHolder@@PAVCreature@@HP6AXHUPoint2D@@MH@Z@Z @ 0x006dd540

undefined4 _AddToRoutePlan_Tree__UAEXPAURPHolder__PAVCreature__HP6AXHUPoint2D__MH_Z_Z(int *param_1)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  float10 fVar3;
  
  if (param_1 != (int *)0x0) {
    fVar2 = (float10)(**(code **)(*in_ECX + 0x42c))();
    fVar3 = (float10)(**(code **)(*param_1 + 0x42c))();
    if ((float10)(float)fVar2 < fVar3 * (float10)1.5) {
      iVar1 = FUN_005ea110();
      if (iVar1 == 0) {
        return 0;
      }
    }
  }
  return 1;
}



// ?Save@Tree@@UAEIAAVGameOSFile@@@Z @ 0x006dd5d0

undefined4 _Save_Tree__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_Fixed__UAEIPAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x60),2,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x60) + 2;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90((byte *)(in_ECX + 100),4,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 100) + 4;
      }
    }
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x68));
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x5c),2,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x5c) + 2;
    }
    return 1;
  }
  return 0;
}



// ?Load@Tree@@UAEIAAVGameOSFile@@@Z @ 0x006dd6c0

undefined4 _Load_Tree__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Load_Fixed__QAEIAAVGGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x60),2,0,unaff_EDI,unaff_ESI,unaff_EBX);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x60) + 2;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 100) + 4;
    }
    FUN_00531f30();
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x5c) + 2;
    }
    return 1;
  }
  return 0;
}



// ?ApplyWaterSpell@Tree@@UAEMPAVSpellWater@@@Z @ 0x006dd7b0

float10 _ApplyWaterSpell_Tree__UAEMPAVSpellWater___Z(int *param_1)

{
  float fVar1;
  bool bVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *in_ECX;
  float10 fVar7;
  float fStack_188;
  char cStack_184;
  undefined1 auStack_174 [12];
  undefined4 auStack_168 [2];
  undefined4 uStack_160;
  undefined4 uStack_15c;
  int iStack_144;
  float fStack_138;
  float fStack_134;
  
  _ApplyWaterSpell_Object__UAEMPAVSpellWater___Z(param_1);
  cStack_184 = param_1[0x2d] == 0x17;
  if ((*(byte *)((int)in_ECX + 0x5e) & 1) == 0) {
LAB_006dd7fa:
    bVar2 = false;
  }
  else {
    fVar7 = (float10)(**(code **)(*in_ECX + 0x120))();
    if ((float10)(float)in_ECX[0x19] <= fVar7) goto LAB_006dd7fa;
    bVar2 = true;
  }
  if ((bVar2) || ((bool)cStack_184)) {
    fStack_188 = *(float *)(in_ECX[10] + 0x134) * *(float *)(in_ECX[10] + 0x11c);
    if (!bVar2) {
      fVar7 = (float10)(**(code **)(*in_ECX + 0x120))(0x40400000);
      fVar7 = (float10)FUN_006df670((float)fVar7);
      fStack_188 = (float)((float10)fStack_188 * (float10)0.5 * fVar7);
    }
    fVar7 = (float10)FUN_006db9e0(fStack_188,1,cStack_184);
    if (fVar7 != (float10)0.0) {
      LH_SamplePlayOptions::LH_SamplePlayOptions((LH_SamplePlayOptions *)auStack_168);
      piVar3 = (int *)(**(code **)(*in_ECX + 0x100))(auStack_174);
      fVar1 = (float)piVar3[2];
      fVar7 = (float10)FUN_00760fd0();
      auStack_168[0] = *(undefined4 *)(DAT_00bf4e68 + 0x3ac);
      cStack_184 = SUB41((float)*piVar3 * 0.00015258789,0);
      iVar5 = piVar3[1];
      uVar4 = (*(code *)0x4abbb68)();
      uStack_160 = 1;
      uStack_15c = 0;
      iStack_144 = uVar4 % 9 + 0x78;
      fStack_138 = (float)(fVar7 + (float10)fVar1);
      fStack_134 = (float)iVar5 * 0.00015258789;
      FUN_00423db0(auStack_168);
      LH_SamplePlayOptions::~LH_SamplePlayOptions((LH_SamplePlayOptions *)auStack_168);
    }
    if (bVar2) goto LAB_006dd99e;
  }
  iVar5 = (**(code **)(*in_ECX + 0x86c))();
  if ((iVar5 != 0) && (cStack_184 == '\0')) {
    (**(code **)(*in_ECX + 0x86c))();
    if (0x28 < (uint)(*(int *)(DAT_00c22ca4 + 0x201afc) - DAT_00bf1828)) {
      (**(code **)(*in_ECX + 0x86c))();
      iVar5 = FUN_0050e600(in_ECX);
      if ((iVar5 != 0) && (param_1 != (int *)0x0)) {
        iVar6 = (**(code **)(*param_1 + 0x1c))();
        if (iVar6 != 0) {
          FUN_004124b0(iVar6,iVar5,1);
        }
      }
    }
  }
LAB_006dd99e:
  return (float10)1.0;
}



