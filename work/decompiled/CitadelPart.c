// Decompiled functions for class: CitadelPart
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetMesh@CitadelPart@@UBEHXZ @ 0x004518c0

undefined4 _GetMesh_CitadelPart__UBEHXZ(void)

{
  FUN_00450fc0();
  FUN_00453b40();
  FUN_00453b90();
  return 1;
}



// ?IsBuilt@CitadelPart@@UAE_NXZ @ 0x00453010

undefined4 _IsBuilt_CitadelPart__UAE_NXZ(undefined4 param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int *in_ECX;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  fStack_c = -13.82;
  fStack_8 = 0.0;
  fStack_4 = -29.09;
  iVar4 = (**(code **)(*in_ECX + 0x114))();
  iVar4 = *(int *)(*(int *)(iVar4 + 0x30) + 0x40);
  fVar3 = fStack_4 * *(float *)(iVar4 + 0x2c);
  fVar2 = fStack_4 * *(float *)(iVar4 + 0x30);
  fVar1 = fStack_c * *(float *)(iVar4 + 0x18);
  fStack_4 = fStack_c * *(float *)(iVar4 + 0x1c) +
             fStack_8 * *(float *)(iVar4 + 0x28) + fStack_4 * *(float *)(iVar4 + 0x34) +
             *(float *)(iVar4 + 0x40);
  fStack_c = fStack_c * *(float *)(iVar4 + 0x14) + fStack_8 * *(float *)(iVar4 + 0x20) + fVar3 +
             *(float *)(iVar4 + 0x38);
  fStack_8 = fVar1 + fStack_8 * *(float *)(iVar4 + 0x24) + fVar2 + *(float *)(iVar4 + 0x3c);
  FUN_005bf830(&fStack_c);
  return param_1;
}



// ?ToBeDeleted@CitadelPart@@UAEXH@Z @ 0x004546e0

void _ToBeDeleted_CitadelPart__UAEXH_Z(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  int *piVar3;
  
  iVar2 = (**(code **)(*in_ECX + 0x114))();
  if (iVar2 != 0) {
    iVar2 = (**(code **)(*in_ECX + 0x114))();
    piVar3 = *(int **)(iVar2 + 0x4c);
    if (piVar3 == in_ECX) {
      *(int *)(iVar2 + 0x4c) = in_ECX[0x21];
    }
    else {
      if (piVar3 == (int *)0x0) goto LAB_0045474a;
      while (piVar1 = (int *)piVar3[0x21], piVar1 != in_ECX) {
        piVar3 = piVar1;
        if (piVar1 == (int *)0x0) {
          _ToBeDeleted_MultiMapFixed__UAEXH_Z(param_1);
          return;
        }
      }
      piVar3[0x21] = in_ECX[0x21];
    }
    *(int *)(iVar2 + 0x50) = *(int *)(iVar2 + 0x50) + -1;
    in_ECX[0x21] = 0;
  }
LAB_0045474a:
  _ToBeDeleted_MultiMapFixed__UAEXH_Z(param_1);
  return;
}



// ?GetPlayer@CitadelPart@@UAEPAVGPlayer@@XZ @ 0x00454840

undefined4 _GetPlayer_CitadelPart__UAEPAVGPlayer__XZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x80) + 0x2c);
}



// ?GetSaveType@CitadelPart@@UAEIXZ @ 0x00454920

undefined4 _GetSaveType_CitadelPart__UAEIXZ(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_MultiMapFixed__UAEIPAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x7c),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x7c) + 4;
    }
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x80));
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x88));
    return 1;
  }
  return 0;
}



// ?Save@CitadelPart@@UAEIAAVGameOSFile@@@Z @ 0x004549a0

undefined4 _Save_CitadelPart__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Load__13MultiMapFixedFR10GameOSFile(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x7c),4,0,unaff_EDI,unaff_ESI,unaff_EBX);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x7c) + 4;
    }
    FUN_00531f30();
    FUN_00531f30();
    return 1;
  }
  return 0;
}



