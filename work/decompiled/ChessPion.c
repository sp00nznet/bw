// Decompiled functions for class: ChessPion
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetSaveType@ChessPion@@UAEIXZ @ 0x0041d580

undefined4 _GetSaveType_ChessPion__UAEIXZ(uint param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  uint uVar3;
  byte *pbVar4;
  
  iVar1 = param_1;
  iVar2 = _Save_MultiMapFixed__UAEIPAVGameOSFile___Z(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  param_1 = 3;
  if (DAT_00b19ac8 != 0) {
    iVar2 = FUN_0072be90(&param_1,4,0);
    if (iVar2 == 3) {
      DAT_00b19ac8 = 0;
    }
    uVar3 = 0;
    *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + (param_1 & 0xff) + 4;
    if (param_1 != 0) {
      pbVar4 = (byte *)(in_ECX + 0x8c);
      do {
        if (DAT_00b19ac8 == 0) {
          return 1;
        }
        iVar2 = FUN_0072be90(pbVar4,4,0);
        if (iVar2 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *pbVar4 + 4;
        if (DAT_00b19ac8 == 0) {
          return 1;
        }
        uVar3 = uVar3 + 1;
        pbVar4 = pbVar4 + 4;
      } while (uVar3 < param_1);
    }
    if (DAT_00b19ac8 != 0) {
      iVar2 = FUN_0072be90((byte *)(in_ECX + 0x7c),4,0);
      if (iVar2 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x7c) + 4;
    }
  }
  return 1;
}



// ?Save@ChessPion@@UAEIAAVGameOSFile@@@Z @ 0x0041d6a0

undefined4 _Save_ChessPion__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_EBX;
  uint uVar3;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  byte *pbVar4;
  int in_stack_00005d0d;
  uint in_stack_00005d15;
  uint in_stack_0000ba26;
  undefined4 extraout_var;
  
  iVar1 = param_1;
  iVar2 = _Load__13MultiMapFixedFR10GameOSFile(param_1);
  if (iVar2 != 0) {
    if (DAT_00b19acc != 0) {
      iVar2 = FUN_0072be50(&param_1,4,0,unaff_EDI,unaff_EBP,unaff_EBX,unaff_ESI,extraout_var);
      if (iVar2 == 3) {
        DAT_00b19acc = 0;
      }
      uVar3 = 0;
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + (in_stack_00005d15 & 0xff) + 4;
      if (in_stack_00005d15 != 0) {
        pbVar4 = (byte *)(in_stack_00005d0d + 0x8c);
        do {
          if (DAT_00b19acc != 0) {
            iVar2 = FUN_0072be50();
            if (iVar2 == 3) {
              DAT_00b19acc = 0;
            }
            *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *pbVar4 + 4;
            in_stack_00005d15 = in_stack_0000ba26;
          }
          uVar3 = uVar3 + 1;
          pbVar4 = pbVar4 + 4;
        } while (uVar3 < in_stack_00005d15);
      }
    }
    if (DAT_00b19acc != 0) {
      iVar2 = FUN_0072be50();
      if (iVar2 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_stack_00005d0d + 0x7c) + 4;
    }
    return 1;
  }
  return 0;
}



