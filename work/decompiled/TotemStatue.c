// Decompiled functions for class: TotemStatue
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?ResolveLoad@TotemStatue@@UAEXXZ @ 0x005313a0

undefined4 _ResolveLoad_TotemStatue__UAEXXZ(void)

{
  return 0x7f;
}



// ?ToBeDeleted@TotemStatue@@UAEXH@Z @ 0x006cbab0

void _ToBeDeleted_TotemStatue__UAEXH_Z(undefined4 param_1)

{
  FUN_006cbad0();
  _ToBeDeleted_MultiMapFixed__UAEXH_Z(param_1);
  return;
}



// ?GetMesh@TotemStatue@@UBEHXZ @ 0x006cbdb0

undefined4 _GetMesh_TotemStatue__UBEHXZ(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int *in_ECX;
  undefined1 *puVar5;
  uint uStack_180;
  undefined4 uStack_17c;
  undefined1 auStack_174 [8];
  LH_SamplePlayOptions aLStack_16c [4];
  undefined4 uStack_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_148;
  uint uStack_138;
  undefined4 uStack_134;
  
  (*(code *)0x4ab9dc5)();
  uStack_180 = DAT_00d78a9c;
  uStack_17c = 0;
  iVar4 = __ftol();
  uStack_180 = iVar4 - in_ECX[0x34];
  uStack_17c = 0;
  fVar1 = (float)uStack_180 + (float)in_ECX[0x2c];
  in_ECX[0x2c] = (int)fVar1;
  if (fVar1 < (float)in_ECX[0x2d]) {
    fVar3 = fVar1 * fVar1 * 0.5;
    fVar2 = fVar1 * fVar3 * 0.33333334;
    in_ECX[0x2a] = (int)(fVar2 * (float)in_ECX[0x32] +
                         fVar1 * (float)in_ECX[0x30] + fVar3 * (float)in_ECX[0x31] +
                        (float)in_ECX[0x2f]);
    in_ECX[0x27] = (int)(fVar3 * (float)in_ECX[0x30] +
                         fVar2 * (float)in_ECX[0x31] +
                         (float)in_ECX[0x2f] * (float)in_ECX[0x2c] +
                         fVar3 * fVar3 * 0.16666667 * (float)in_ECX[0x32] + (float)in_ECX[0x2e]);
  }
  else {
    in_ECX[0x27] = in_ECX[0x28];
    in_ECX[0x2a] = in_ECX[0x29];
    in_ECX[0x2b] = 0;
    in_ECX[0x2c] = in_ECX[0x2d];
  }
  in_ECX[0x34] = iVar4;
  if ((ABS((float)in_ECX[0x27] - (float)in_ECX[0x28]) < 0.005) && (in_ECX[0x33] != 0)) {
    in_ECX[0x33] = 0;
    FUN_006b5ff0();
    LH_SamplePlayOptions::LH_SamplePlayOptions((LH_SamplePlayOptions *)&uStack_168);
    puVar5 = auStack_174;
    (**(code **)(*in_ECX + 0x100))(puVar5,&uStack_180);
    FUN_005c0400(puVar5);
    uStack_168 = *(undefined4 *)(DAT_00bf4e68 + 0x3ac);
    uStack_138 = uStack_180;
    uStack_148 = 0x1e;
    uStack_164 = 1;
    uStack_134 = uStack_17c;
    uStack_160 = 0;
    FUN_00423db0(aLStack_16c);
    LH_SamplePlayOptions::~LH_SamplePlayOptions(aLStack_16c);
  }
  return 1;
}



// ?GetTown@TotemStatue@@UAEPAVTown@@XZ @ 0x006cc2c0

undefined4 _GetTown_TotemStatue__UAEPAVTown__XZ(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x7c) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x006cc2c9. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(**(int **)(in_ECX + 0x7c) + 0x48))();
    return uVar1;
  }
  return 0;
}



// ?GetPlayer@TotemStatue@@UAEPAVGPlayer@@XZ @ 0x006cc2d0

int _GetPlayer_TotemStatue__UAEPAVGPlayer__XZ(void)

{
  int iVar1;
  int *piVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x48))();
  if (iVar1 != 0) {
    piVar2 = (int *)(**(code **)(*in_ECX + 0x48))();
    iVar1 = (**(code **)(*piVar2 + 0x1c))();
    return iVar1;
  }
  return DAT_00c22ca4 + 0x18 + (uint)*(byte *)(DAT_00c22ca4 + 0x201b17) * 0x278;
}



// ?NetworkUnfriendlyLockedSelect@TotemStatue@@UAEIPAUControlHandUpdateInfo@@@Z @ 0x006cc3a0

undefined4
_NetworkUnfriendlyLockedSelect_TotemStatue__UAEIPAUControlHandUpdateInfo___Z(int *param_1)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x1c))();
  if (*(int *)(iVar1 + 0x264) != 0) {
    FUN_00461d40(0);
  }
  (**(code **)(*param_1 + 0x1c))(1);
  FUN_0067efc0();
  return 1;
}



// ?NetworkUnfriendlyEndLockedSelect@TotemStatue@@UAEIXZ @ 0x006cc4a0

undefined4 _NetworkUnfriendlyEndLockedSelect_TotemStatue__UAEIXZ(float *param_1)

{
  float fVar1;
  int in_ECX;
  
  if ((*(byte *)(in_ECX + 0x24) & 0x10) != 0) {
    fVar1 = *param_1 * 0.1 + *(float *)(in_ECX + 0x88);
    if (fVar1 < 0.0) {
      *(undefined4 *)(in_ECX + 0x88) = 0;
      return 1;
    }
    if (1.0 < fVar1) {
      fVar1 = 1.0;
    }
    *(float *)(in_ECX + 0x88) = fVar1;
  }
  return 1;
}



// ?GetSaveType@TotemStatue@@UAEIXZ @ 0x006cc600

undefined4 _GetSaveType_TotemStatue__UAEIXZ(int param_1)

{
  byte *pbVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar3 = _Load__13MultiMapFixedFR10GameOSFile(param_1);
  if (iVar3 != 0) {
    FUN_00531f30(in_ECX + 0x7c);
    pbVar1 = (byte *)(in_ECX + 0x80);
    if (DAT_00b19acc != 0) {
      iVar3 = FUN_0072be50(pbVar1,4,0,unaff_EBP,unaff_EBX,unaff_EDI,unaff_ESI);
      if (iVar3 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *pbVar1 + 4;
    }
    uVar2 = *(undefined4 *)pbVar1;
    *(undefined4 *)(in_ECX + 0xb4) = 0;
    *(undefined4 *)(in_ECX + 0xa0) = uVar2;
    *(undefined4 *)(in_ECX + 0xb0) = 0;
    *(undefined4 *)(in_ECX + 0x9c) = uVar2;
    *(undefined4 *)(in_ECX + 200) = 0;
    *(undefined4 *)(in_ECX + 0xb8) = uVar2;
    *(undefined4 *)(in_ECX + 0xc4) = 0;
    *(undefined4 *)(in_ECX + 0xac) = 0;
    *(undefined4 *)(in_ECX + 0xc0) = 0;
    *(undefined4 *)(in_ECX + 0xa8) = 0;
    *(undefined4 *)(in_ECX + 0xbc) = 0;
    *(undefined4 *)(in_ECX + 0xa4) = 0;
    if (DAT_00b19acc != 0) {
      iVar3 = FUN_0072be50();
      if (iVar3 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x84) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar3 = FUN_0072be50();
      if (iVar3 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x88) + 4;
    }
    *(undefined4 *)(in_ECX + 0x8c) = 0;
    return 1;
  }
  return 0;
}



