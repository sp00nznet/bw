// Decompiled functions for class: GAudio
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetSaveType@GAudio@@UAEIXZ @ 0x004211b0

undefined4 _GetSaveType_GAudio__UAEIXZ(void)

{
  return 0x101;
}



// ?GetDebugText@GAudio@@UAEPADXZ @ 0x004211c0

char * _GetDebugText_GAudio__UAEPADXZ(void)

{
  return s_GAudio__008f9ce4;
}



// ?ToBeDeleted@GAudio@@UAEXH@Z @ 0x00421210

void _ToBeDeleted_GAudio__UAEXH_Z(undefined4 param_1)

{
  LH_AudioSystem *this;
  int iVar1;
  int in_ECX;
  undefined4 *puVar2;
  
  iVar1 = LH_AudioSystem::LHWaveIsInstalled(*(LH_AudioSystem **)(in_ECX + 0x14));
  if (iVar1 == 1) {
    FUN_004224e0();
  }
  FUN_00424290();
  FUN_00422f70();
  puVar2 = (undefined4 *)(in_ECX + 0x2c);
  iVar1 = 0x55;
  do {
    if ((LH_AudioBank *)*puVar2 != (LH_AudioBank *)0x0) {
      LH_AudioSystem::LHBankRelease(*(LH_AudioSystem **)(in_ECX + 0x14),(LH_AudioBank *)*puVar2);
      *puVar2 = 0;
    }
    puVar2 = puVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  this = *(LH_AudioSystem **)(in_ECX + 0x14);
  if (this != (LH_AudioSystem *)0x0) {
    LH_AudioSystem::~LH_AudioSystem(this);
    FUN_007290de(this);
  }
  *(undefined4 *)(in_ECX + 0x14) = 0;
  if (*(int *)(in_ECX + 0x18) != 0) {
    FUN_00734abe(*(int *)(in_ECX + 0x18));
  }
  FUN_00749b70();
  _ToBeDeleted_GameThing__UAEXH_Z(param_1);
  return;
}



// ?Save@GAudio@@UAEIAAVGameOSFile@@@Z @ 0x00422540

undefined4 _Save_GAudio__UAEIAAVGameOSFile___Z(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  
  if (DAT_00b19ac8 != 0) {
    iVar3 = *(int *)(in_ECX + 0x188);
    iVar4 = 0;
    iVar2 = FUN_0072be90((byte *)(in_ECX + 0x188),4,0);
    if (iVar2 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x188) + 4;
    for (puVar1 = *(undefined4 **)(in_ECX + 0x184); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      iVar4 = iVar4 + 1;
      if (iVar3 < iVar4) goto LAB_004225d8;
      if (DAT_00b19ac8 == 0) goto LAB_00422656;
      FUN_00531bc0(puVar1[1]);
    }
    if (DAT_00b19ac8 != 0) {
      if (iVar4 == iVar3) {
        iVar3 = FUN_0072be90((byte *)(in_ECX + 0x28),4,0);
        if (iVar3 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x28) + 4;
        if (DAT_00b19ac8 != 0) {
          iVar3 = FUN_0072be90((byte *)(in_ECX + 0x180),4,0);
          if (iVar3 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x180) + 4;
        }
      }
      else {
LAB_004225d8:
        DAT_00b19ac8 = 0;
      }
    }
  }
LAB_00422656:
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0x18c));
  if (DAT_00b19ac8 != 0) {
    iVar3 = FUN_0072be90((byte *)(in_ECX + 400),4,0);
    if (iVar3 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 400) + 4;
  }
  return 1;
}



// ?Load@GAudio@@UAEIAAVGameOSFile@@@Z @ 0x004226b0

undefined4 _Load_GAudio__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  void *pvVar2;
  int *piVar3;
  int in_ECX;
  int in_stack_00005d0d;
  uint in_stack_00005d15;
  
  *(undefined4 *)(in_ECX + 0x1c) = 0xffffffff;
  *(undefined4 *)(in_ECX + 0x24) = 0;
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (in_stack_00005d15 & 0xff) + 4;
    for (; 0 < (int)in_stack_00005d15; in_stack_00005d15 = in_stack_00005d15 - 1) {
      FUN_00531f30();
      if (((in_stack_00005d0d != 0) && (pvVar2 = operator_new(8), pvVar2 != (void *)0x0)) &&
         (iVar1 = FUN_004ecf30(), iVar1 != 0)) {
        piVar3 = (int *)FUN_004ecf10();
        if (piVar3 == (int *)0x0) {
          *(int *)(in_ECX + 0x184) = iVar1;
        }
        else {
          *piVar3 = iVar1;
        }
        *(int *)(in_ECX + 0x188) = *(int *)(in_ECX + 0x188) + 1;
      }
    }
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
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
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x180) + 4;
  }
  FUN_00531f30();
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 400) + 4;
  }
  return 1;
}



