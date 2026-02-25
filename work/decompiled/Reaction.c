// Decompiled functions for class: Reaction
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetPlayer@Reaction@@UAEPAVGPlayer@@XZ @ 0x0052df90

undefined4 _GetPlayer_Reaction__UAEPAVGPlayer__XZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x38);
}



// ?SetPlayer@Reaction@@UAEXPAVGPlayer@@@Z @ 0x0052dfa0

void _SetPlayer_Reaction__UAEXPAVGPlayer___Z(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x38) = param_1;
  return;
}



// ?GetRadius@Reaction@@UAEMXZ @ 0x0052dfb0

float10 _GetRadius_Reaction__UAEMXZ(void)

{
  int in_ECX;
  
  return (float10)*(float *)(in_ECX + 0x3c);
}



// ?GetSaveType@Reaction@@UAEIXZ @ 0x0052dfc0

undefined4 _GetSaveType_Reaction__UAEIXZ(void)

{
  return 0x26;
}



// ?GetDebugText@Reaction@@UAEPADXZ @ 0x0052dfd0

char * _GetDebugText_Reaction__UAEPADXZ(void)

{
  return s_Reaction__00b1a2b8;
}



// ?ToBeDeleted@Reaction@@UAEXH@Z @ 0x0067ecf0

void _ToBeDeleted_Reaction__UAEXH_Z(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  iVar3 = FUN_007344da(*(undefined4 *)(in_ECX + 0x14),0,&GameThingWithPos::RTTI_Type_Descriptor,
                       &Spell::RTTI_Type_Descriptor,0);
  if (iVar3 != 0) {
    *(undefined4 *)(iVar3 + 0x28) = 0;
  }
  if (DAT_00c71458 == in_ECX) {
    DAT_00c71458 = *(int *)(DAT_00c71458 + 0x40);
  }
  if (*(int **)(in_ECX + 0x28) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x28) + 0xc))(0);
  }
  iVar2 = DAT_00c22ca4;
  iVar3 = *(int *)(DAT_00c22ca4 + 0x201c98);
  if (iVar3 == in_ECX) {
    *(int *)(DAT_00c22ca4 + 0x201c98) = *(int *)(in_ECX + 0x40);
  }
  else {
    if (iVar3 == 0) goto LAB_0067ed81;
    while (iVar1 = *(int *)(iVar3 + 0x40), iVar1 != in_ECX) {
      iVar3 = iVar1;
      if (iVar1 == 0) {
        _ToBeDeleted_GameThing__UAEXH_Z(param_1);
        return;
      }
    }
    *(undefined4 *)(iVar3 + 0x40) = *(undefined4 *)(in_ECX + 0x40);
  }
  *(int *)(iVar2 + 0x201c9c) = *(int *)(iVar2 + 0x201c9c) + -1;
  *(undefined4 *)(in_ECX + 0x40) = 0;
LAB_0067ed81:
  _ToBeDeleted_GameThing__UAEXH_Z(param_1);
  return;
}



// ?Save@Reaction@@UAEIAAVGameOSFile@@@Z @ 0x0067fb50

undefined4 _Save_Reaction__UAEIAAVGameOSFile___Z(int param_1)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  undefined4 uStack_4;
  
  iVar2 = param_1;
  iVar3 = FUN_0053e8e0(param_1);
  if (iVar3 == 0) {
    return 0;
  }
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0x14));
  if (DAT_00b19ac8 != 0) {
    iVar3 = *(int *)(in_ECX + 0x1c);
    pbVar1 = (byte *)(in_ECX + 0x1c);
    param_1 = 0;
    iVar4 = FUN_0072be90(pbVar1,4,0);
    if (iVar4 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + *pbVar1 + 4;
    iVar4 = *(int *)pbVar1;
    while (iVar4 = iVar4 + -1, -1 < iVar4) {
      param_1 = param_1 + 1;
      if (iVar3 < param_1) {
        DAT_00b19ac8 = 0;
        goto LAB_0067fc8c;
      }
      if (DAT_00b19ac8 == 0) goto LAB_0067fc8c;
      uStack_4 = FUN_00680020(iVar4);
      FUN_00533120(&uStack_4);
    }
    if (DAT_00b19ac8 != 0) {
      iVar3 = FUN_0072be90((byte *)(in_ECX + 0x20),4,0);
      if (iVar3 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + *(byte *)(in_ECX + 0x20) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar3 = FUN_0072be90((byte *)(in_ECX + 0x24),4,0);
        if (iVar3 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + *(byte *)(in_ECX + 0x24) + 4;
      }
    }
  }
LAB_0067fc8c:
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0x28));
  if (DAT_00b19ac8 != 0) {
    iVar3 = FUN_0072be90((byte *)(in_ECX + 0x2c),4,0);
    if (iVar3 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + *(byte *)(in_ECX + 0x2c) + 4;
    if (DAT_00b19ac8 != 0) {
      iVar3 = FUN_0072be90((byte *)(in_ECX + 0x30),4,0);
      if (iVar3 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + *(byte *)(in_ECX + 0x30) + 4;
    }
  }
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0x38));
  if (DAT_00b19ac8 != 0) {
    iVar3 = FUN_0072be90((byte *)(in_ECX + 0x3c),4,0);
    if (iVar3 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + *(byte *)(in_ECX + 0x3c) + 4;
  }
  return 1;
}



// ?Load@Reaction@@UAEIAAVGameOSFile@@@Z @ 0x0067fd60

undefined4 _Load_Reaction__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  uint in_stack_00005d15;
  
  iVar1 = FUN_0053e9f0();
  if (iVar1 != 0) {
    FUN_00531f30();
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (in_stack_00005d15 & 0xff) + 4;
      for (; 0 < (int)in_stack_00005d15; in_stack_00005d15 = in_stack_00005d15 - 1) {
        FUN_00533110();
        FUN_0067fff0();
      }
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x20) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x24) + 4;
    }
    FUN_00531f30();
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x2c) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x30) + 4;
    }
    FUN_00531f30();
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x3c) + 4;
    }
    return 1;
  }
  return 0;
}



