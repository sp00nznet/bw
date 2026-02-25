// Decompiled functions for class: SpecialVillager
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetSaveType@SpecialVillager@@UAEIXZ @ 0x00531310

undefined4 _GetSaveType_SpecialVillager__UAEIXZ(void)

{
  return 0x76;
}



// ?GetDebugText@SpecialVillager@@UAEPADXZ @ 0x00531320

char * _GetDebugText_SpecialVillager__UAEPADXZ(void)

{
  return s_SpecialVillager__00b1b26c;
}



// ?ToBeDeleted@SpecialVillager@@UAEXH@Z @ 0x006b6420

void _ToBeDeleted_SpecialVillager__UAEXH_Z(undefined4 param_1)

{
  FUN_006b6300(0);
  FUN_006e1cf0(param_1);
  return;
}



// ?GetVillagerName@SpecialVillager@@UAEPBDXZ @ 0x006b65a0

undefined4 _GetVillagerName_SpecialVillager__UAEPBDXZ(void)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  float10 fVar5;
  float *pfVar6;
  float fStack_14;
  undefined4 uStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  if (((DAT_00cbd000 == 0) || (DAT_00cbd004 != in_ECX)) || (in_ECX[0x10] == 0)) {
    cVar1 = FUN_004f7ab0();
    if (cVar1 == '\0') {
      if (((0.01 < *(float *)(DAT_00c22ca4 + 0x1a6c)) || ((*(byte *)((int)in_ECX + 0xb5) & 1) != 0))
         && (((*(uint *)(DAT_00c22ca4 + 0x14) & 0x200000) == 0 &&
             ((*(byte *)((int)in_ECX + 0xb5) & 2) == 0)))) {
        cVar1 = FUN_006b67d0();
        if (cVar1 != '\0') {
          uVar2 = (**(code **)(*in_ECX + 0xb3c))();
          FUN_00789090(uVar2);
          uStack_10 = *(undefined4 *)(DAT_00c22ca4 + 0x1a6c);
          fStack_14 = (float)in_ECX[7];
          fVar5 = (float10)FUN_00760fd0();
          iVar3 = in_ECX[0x10];
          fStack_8 = (float)(fVar5 + (float10)fStack_14);
          fStack_c = (float)in_ECX[5] * 0.00015258789;
          fStack_4 = (float)in_ECX[6] * 0.00015258789;
          if (iVar3 != 0) {
            fStack_c = *(float *)(iVar3 + 0x38);
            fStack_8 = *(float *)(iVar3 + 0x3c);
            fStack_4 = *(float *)(iVar3 + 0x40);
          }
          fStack_8 = fStack_8 + 1.75;
          iVar3 = (**(code **)(*in_ECX + 0x48))();
          if (iVar3 != 0) {
            piVar4 = (int *)(**(code **)(*in_ECX + 0x48))();
            iVar3 = (**(code **)(*piVar4 + 0x1c))();
            if (iVar3 != 0) {
              piVar4 = (int *)(**(code **)(*in_ECX + 0x48))();
              pfVar6 = &fStack_14;
              (**(code **)(*piVar4 + 0x1c))(pfVar6);
              FUN_005f8990(pfVar6);
            }
          }
          FUN_004402a0(&fStack_c);
          FUN_006f1240(uStack_10);
          return 1;
        }
      }
    }
  }
  return 0;
}



// ?Draw@SpecialVillager@@UAEXXZ @ 0x006b6730

void _Draw_SpecialVillager__UAEXXZ(void)

{
  int iVar1;
  int in_ECX;
  undefined4 uStack_c;
  float fStack_8;
  undefined4 uStack_4;
  
  FUN_004f7e40();
  if (((DAT_00cbd000 != 0) && (DAT_00cbd004 == in_ECX)) &&
     (iVar1 = *(int *)(in_ECX + 0x40), iVar1 != 0)) {
    uStack_c = *(undefined4 *)(iVar1 + 0x38);
    uStack_4 = *(undefined4 *)(iVar1 + 0x40);
    fStack_8 = *(float *)(iVar1 + 0x3c) + 1.5;
    FUN_004402a0(&uStack_c);
    FUN_00543e10(&LAB_006b62d0,in_ECX);
    if ((*(float *)(DAT_00cbd000 + 0x98) <= 0.0) || ((*(byte *)(in_ECX + 0xe0) & 4) != 0)) {
      FUN_006b6300(0);
    }
  }
  return;
}



// ?Save@SpecialVillager@@UAEIAAVGameOSFile@@@Z @ 0x006b6890

undefined4 _Save_SpecialVillager__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_006e3d60(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x128),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x128) + 4;
    }
    return 1;
  }
  return 0;
}



// ?Load@SpecialVillager@@UAEIAAVGameOSFile@@@Z @ 0x006b6900

undefined4 _Load_SpecialVillager__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = FUN_006e4060(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x128),4,0,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x128) + 4;
    }
    return 1;
  }
  return 0;
}



