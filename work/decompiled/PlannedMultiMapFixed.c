// Decompiled functions for class: PlannedMultiMapFixed
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetScale@PlannedMultiMapFixed@@UBEMXZ @ 0x00403bc0

float10 _GetScale_PlannedMultiMapFixed__UBEMXZ(void)

{
  int in_ECX;
  
  return (float10)*(float *)(in_ECX + 0x2c);
}



// ?SetScale@PlannedMultiMapFixed@@UAEXM@Z @ 0x00403bd0

void _SetScale_PlannedMultiMapFixed__UAEXM_Z(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x2c) = param_1;
  return;
}



// ?Draw@PlannedMultiMapFixed@@QAEXXZ @ 0x004167e0

void _Draw_PlannedMultiMapFixed__QAEXXZ(void)

{
  return;
}



// ?GetSaveType@PlannedMultiMapFixed@@UAEIXZ @ 0x0052e350

undefined4 _GetSaveType_PlannedMultiMapFixed__UAEIXZ(void)

{
  return 0x38;
}



// ?GetDebugText@PlannedMultiMapFixed@@QAEPADXZ @ 0x0052e360

char * _GetDebugText_PlannedMultiMapFixed__QAEPADXZ(void)

{
  return s_PlannedMultiMapFixed__00b1a2d0;
}



// ?GetDesireToBeRepaired@PlannedMultiMapFixed@@QAEMXZ @ 0x005f6aa0

float10 _GetDesireToBeRepaired_PlannedMultiMapFixed__QAEMXZ(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x30) != 0) {
    return (float10)*(float *)(*(int *)(in_ECX + 0x40) + 0x118);
  }
  return (float10)0.0;
}



// ?GetText@PlannedMultiMapFixed@@UAEPBDXZ @ 0x005f6ac0

int _GetText_PlannedMultiMapFixed__UAEPBDXZ(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0x40) + 0x18;
}



// ?CreateBuildingSite@PlannedMultiMapFixed@@UBE_NXZ @ 0x005f6ad0

undefined4 * _CreateBuildingSite_PlannedMultiMapFixed__UBE_NXZ(void)

{
  undefined4 *puVar1;
  undefined4 in_ECX;
  
  puVar1 = (undefined4 *)FUN_004300a0(0x648,s_C__dev_black_PlannedMultiMapFixe_00b228ac,0x4e);
  if (puVar1 != (undefined4 *)0x0) {
    FUN_00433f30(in_ECX);
    *puVar1 = &vftable_StandardBuildingSite;
    puVar1[0x191] = 0;
    return puVar1;
  }
  return (undefined4 *)0x0;
}



// ?Save@PlannedMultiMapFixed@@QAEIAAVGGameOSFile@@@Z @ 0x005f6b10

undefined4 _Save_PlannedMultiMapFixed__QAEIAAVGGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_GameThingWithPos__UAEXPAUGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x28),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x28) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90((byte *)(in_ECX + 0x2c),4,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x2c) + 4;
        if (DAT_00b19ac8 != 0) {
          iVar1 = FUN_0072be90((byte *)(in_ECX + 0x30),4,0);
          if (iVar1 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x30) + 4;
          if (DAT_00b19ac8 != 0) {
            iVar1 = FUN_0072be90((byte *)(in_ECX + 0x34),4,0);
            if (iVar1 == 3) {
              DAT_00b19ac8 = 0;
            }
            *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x34) + 4;
            if (DAT_00b19ac8 != 0) {
              iVar1 = FUN_0072be90((byte *)(in_ECX + 0x3c),4,0);
              if (iVar1 == 3) {
                DAT_00b19ac8 = 0;
              }
              *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x3c) + 4;
            }
          }
        }
      }
    }
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x38));
    FUN_00533b90(*(undefined4 *)(in_ECX + 0x40));
    return 1;
  }
  return 0;
}



// ?Load@PlannedMultiMapFixed@@QAEIAAVGGameOSFile@@@Z @ 0x005f6c70

undefined4 _Load_PlannedMultiMapFixed__QAEIAAVGGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Load_GameThingWithPos__QAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x28),4,0,unaff_EDI,unaff_EBP,unaff_ESI,unaff_EBX);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x28) + 4;
    }
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
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x34) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x3c) + 4;
    }
    FUN_00531f30();
    FUN_00533bf0();
    return 1;
  }
  return 0;
}



// ?PostCreatePlanned@PlannedMultiMapFixed@@QAEXAAVMultiMapFixed@@@Z @ 0x005f6dd0

void _PostCreatePlanned_PlannedMultiMapFixed__QAEXAAVMultiMapFixed___Z(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  if (*(int **)(param_1 + 100) != (int *)0x0) {
    (**(code **)(**(int **)(param_1 + 100) + 4))(1);
  }
  *(int *)(param_1 + 100) = in_ECX[0xe];
  in_ECX[0xe] = 0;
  iVar1 = (**(code **)(*in_ECX + 0x48))();
  if (iVar1 != 0) {
    FUN_006d3e30(param_1);
  }
  return;
}



