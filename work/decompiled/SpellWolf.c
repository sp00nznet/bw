// Decompiled functions for class: SpellWolf
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?StandAnimation@SpellWolf@@UAEIXZ @ 0x00418560

undefined4 _StandAnimation_SpellWolf__UAEIXZ(void)

{
  return 0xb8;
}



// ?GetPlayer@SpellWolf@@UAEPAVGPlayer@@XZ @ 0x0041b780

undefined4 _GetPlayer_SpellWolf__UAEPAVGPlayer__XZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x198);
}



// ?SetPlayer@SpellWolf@@UAEXPAVGPlayer@@@Z @ 0x0041b790

void _SetPlayer_SpellWolf__UAEXPAVGPlayer___Z(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x198) = param_1;
  return;
}



// ?GetSaveType@SpellWolf@@UAEIXZ @ 0x0041b7a0

undefined4 _GetSaveType_SpellWolf__UAEIXZ(void)

{
  return 0x8d;
}



// ?GetDebugText@SpellWolf@@UAEPADXZ @ 0x0041b7b0

char * _GetDebugText_SpellWolf__UAEPADXZ(void)

{
  return s_Animal__SpellWolf_008f81bc;
}



// ?SetDying@SpellWolf@@UAE_NXZ @ 0x0041bb90

undefined4 _SetDying_SpellWolf__UAE_NXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  if ((float)in_ECX[0x5b] != 0.0) {
    iVar1 = (**(code **)(*in_ECX + 0x880))();
    (**(code **)(*in_ECX + 0xbd0))((float)iVar1 * (float)DAT_00c22d78 * 0.001);
  }
  return 1;
}



// ?Load@SpellWolf@@UAEIAAVGameOSFile@@@Z @ 0x0041bf30

undefined4 _Load_SpellWolf__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Load_Animal__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x148),0xc,0,unaff_EDI,unaff_EBP,unaff_ESI,unaff_EBX);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x148) + 0xc;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x154) + 0x10;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x164) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x168) + 0x30;
    }
    FUN_00531f30();
    return 1;
  }
  return 0;
}



// ?Save@SpellWolf@@UAEIAAVGameOSFile@@@Z @ 0x0041c050

undefined4 _Save_SpellWolf__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_Animal__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x148),0xc,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x148) + 0xc;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90((byte *)(in_ECX + 0x154),0x10,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x154) + 0x10;
        if (DAT_00b19ac8 != 0) {
          iVar1 = FUN_0072be90((byte *)(in_ECX + 0x164),4,0);
          if (iVar1 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x164) + 4;
          if (DAT_00b19ac8 != 0) {
            iVar1 = FUN_0072be90((byte *)(in_ECX + 0x168),0x30,0);
            if (iVar1 == 3) {
              DAT_00b19ac8 = 0;
            }
            *(uint *)(param_1 + 0x214) =
                 *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x168) + 0x30;
          }
        }
      }
    }
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x198));
    return 1;
  }
  return 0;
}



// ?Draw@SpellWolf@@UAEXXZ @ 0x004f8930

void _Draw_SpellWolf__UAEXXZ(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  undefined4 uVar5;
  int *in_ECX;
  int iVar6;
  int iVar7;
  float *pfVar8;
  float *pfVar9;
  float10 fVar10;
  float10 fVar11;
  float local_44 [12];
  float local_14;
  int *local_10;
  int local_c;
  float local_8;
  
  fVar10 = (float10)(**(code **)(*in_ECX + 0x120))();
  FUN_004f7510((float)fVar10);
  FUN_004f7830();
  fVar1 = (float)DAT_00dc8d20 * 0.001 + (float)in_ECX[0x49];
  in_ECX[0x49] = (int)fVar1;
  if (fVar1 < (float)in_ECX[0x4a]) {
    fVar2 = fVar1 * fVar1 * 0.5;
    fVar3 = fVar1 * fVar2 * 0.33333334;
    in_ECX[0x47] = (int)(fVar2 * (float)in_ECX[0x4e] +
                         fVar1 * (float)in_ECX[0x4d] + fVar3 * (float)in_ECX[0x4f] +
                        (float)in_ECX[0x4c]);
    in_ECX[0x44] = (int)(fVar3 * (float)in_ECX[0x4e] +
                         (float)in_ECX[0x4c] * (float)in_ECX[0x49] +
                         fVar2 * (float)in_ECX[0x4d] +
                         fVar2 * fVar2 * 0.16666667 * (float)in_ECX[0x4f] + (float)in_ECX[0x4b]);
  }
  else {
    in_ECX[0x44] = in_ECX[0x45];
    in_ECX[0x47] = in_ECX[0x46];
    in_ECX[0x48] = 0;
    in_ECX[0x49] = in_ECX[0x4a];
  }
  local_8 = (float)in_ECX[0x44];
  if (local_8 != 0.0) {
    iVar7 = in_ECX[0x10];
    fVar10 = (float10)fcos((float10)local_8);
    pfVar4 = (float *)(iVar7 + 0x14);
    pfVar8 = pfVar4;
    pfVar9 = local_44;
    for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
      *pfVar9 = *pfVar8;
      pfVar8 = pfVar8 + 1;
      pfVar9 = pfVar9 + 1;
    }
    fVar11 = (float10)fsin((float10)local_8);
    fVar1 = *pfVar4;
    *pfVar4 = (float)(fVar10 * (float10)*pfVar4 - fVar11 * (float10)*(float *)(iVar7 + 0x20));
    *(float *)(iVar7 + 0x20) =
         (float)(fVar10 * (float10)*(float *)(iVar7 + 0x20) + fVar11 * (float10)fVar1);
    fVar1 = *(float *)(iVar7 + 0x18);
    *(float *)(iVar7 + 0x18) =
         (float)(fVar10 * (float10)*(float *)(iVar7 + 0x18) -
                fVar11 * (float10)*(float *)(iVar7 + 0x24));
    *(float *)(iVar7 + 0x24) =
         (float)(fVar10 * (float10)*(float *)(iVar7 + 0x24) + fVar11 * (float10)fVar1);
    fVar1 = *(float *)(iVar7 + 0x1c);
    *(float *)(iVar7 + 0x1c) =
         (float)(fVar10 * (float10)*(float *)(iVar7 + 0x1c) -
                fVar11 * (float10)*(float *)(iVar7 + 0x28));
    *(float *)(iVar7 + 0x28) =
         (float)(fVar10 * (float10)*(float *)(iVar7 + 0x28) +
                (float10)(float)(fVar11 * (float10)fVar1));
  }
  local_14 = (float)in_ECX[0x5a];
  local_10 = &local_c;
  local_c = (int)ROUND(local_14);
  *(uint *)(in_ECX[0x10] + 0x4c) = local_c << 0x18 | 0xffffff;
  (**(code **)(*(int *)in_ECX[0x10] + 0x48))();
  if (in_ECX[0x11] == 0) {
    FUN_00768080(in_ECX[0x34]);
    FUN_005ed470();
  }
  else {
    local_c = *(int *)(in_ECX[0x10] + 0x4c);
    local_14 = (float)FUN_006c6850();
    uVar5 = FUN_006c6760();
    local_10 = (int *)in_ECX[0x10];
    FUN_00768080(uVar5);
    FUN_005ed470();
    FUN_005ea220();
  }
  if (local_8 != 0.0) {
    pfVar8 = local_44;
    pfVar9 = (float *)(in_ECX[0x10] + 0x14);
    for (iVar7 = 0xc; iVar7 != 0; iVar7 = iVar7 + -1) {
      *pfVar9 = *pfVar8;
      pfVar8 = pfVar8 + 1;
      pfVar9 = pfVar9 + 1;
    }
  }
  _Draw_PlannedMultiMapFixed__QAEXXZ();
  return;
}



