// Decompiled functions for class: Ball
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetSaveType@Ball@@UAEIXZ @ 0x0042f6f0

undefined4 _GetSaveType_Ball__UAEIXZ(void)

{
  return 0x44;
}



// ?GetDebugText@Ball@@UAEPADXZ @ 0x0042f700

char * _GetDebugText_Ball__UAEPADXZ(void)

{
  return s_Ball__008fbc9c;
}



// ?GetPlayer@Ball@@UAEPAVGPlayer@@XZ @ 0x0042fa40

int _GetPlayer_Ball__UAEPAVGPlayer__XZ(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x98) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0042fa4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (**(code **)(**(int **)(in_ECX + 0x98) + 0x1c))();
    return iVar1;
  }
  return DAT_00c22ca4 + 0x18 + (uint)*(byte *)(DAT_00c22ca4 + 0x201b17) * 0x278;
}



// ?GetScriptObjectType@Ball@@UAEIXZ @ 0x0042fb00

undefined4 _GetScriptObjectType_Ball__UAEIXZ(void)

{
  return 0x1c;
}



// ?Save@Ball@@UAEIAAVGameOSFile@@@Z @ 0x0042fb10

undefined4 _Save_Ball__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_MobileObject__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x6c),0xc,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x6c) + 0xc;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90((byte *)(in_ECX + 0x78),0xc,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x78) + 0xc;
      }
    }
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x94));
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x98));
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x9c));
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0xa0));
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0xa4),0xc,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xa4) + 0xc;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90((byte *)(in_ECX + 0xb0),4,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xb0) + 4;
      }
    }
    return 1;
  }
  return 0;
}



// ?Load@Ball@@UAEIAAVGameOSFile@@@Z @ 0x0042fc60

undefined4 _Load_Ball__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Load_MobileObject__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x6c),0xc,0,unaff_EBP,unaff_EBX,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x6c) + 0xc;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x78) + 0xc;
    }
    FUN_00531f30();
    FUN_00531f30();
    FUN_00531f30();
    FUN_00531f30();
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xa4) + 0xc;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xb0) + 4;
    }
    return 1;
  }
  return 0;
}



// ?Draw@Ball@@UAEXXZ @ 0x004f3150

void _Draw_Ball__UAEXXZ(void)

{
  int in_ECX;
  
  FUN_004ef260(&DAT_00bf4e6c,2,s_height____2f_00b169d0,(double)*(float *)(in_ECX + 0x1c));
  _Draw_MobileObject__UAEXXZ();
  return;
}



