// Decompiled functions for class: GParticleContainer
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetText@GParticleContainer@@UAEPBDXZ @ 0x005312c0

char * _GetText_GParticleContainer__UAEPBDXZ(void)

{
  return s_Particle_Container_00b1b244;
}



// ?GetSaveType@GParticleContainer@@UAEIXZ @ 0x005312d0

undefined4 _GetSaveType_GParticleContainer__UAEIXZ(void)

{
  return 0x6e;
}



// ?GetDebugText@GParticleContainer@@UAEPADXZ @ 0x005312e0

char * _GetDebugText_GParticleContainer__UAEPADXZ(void)

{
  return s_ParticleContainer__00b1b258;
}



// ?ToBeDeleted@GParticleContainer@@UAEXH@Z @ 0x005ef8a0

void _ToBeDeleted_GParticleContainer__UAEXH_Z(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  iVar3 = DAT_00c22ca4;
  iVar1 = *(int *)(DAT_00c22ca4 + 0x201c88);
  if (iVar1 == in_ECX) {
    *(int *)(DAT_00c22ca4 + 0x201c88) = *(int *)(in_ECX + 0x3c);
  }
  else {
    do {
      iVar2 = iVar1;
      if (iVar2 == 0) goto LAB_005ef8de;
      iVar1 = *(int *)(iVar2 + 0x3c);
    } while (*(int *)(iVar2 + 0x3c) != in_ECX);
    *(undefined4 *)(iVar2 + 0x3c) = *(undefined4 *)(in_ECX + 0x3c);
  }
  *(int *)(iVar3 + 0x201c8c) = *(int *)(iVar3 + 0x201c8c) + -1;
  *(undefined4 *)(in_ECX + 0x3c) = 0;
LAB_005ef8de:
  FUN_0067f9a0();
  if (*(int **)(in_ECX + 0x2c) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x2c) + 4))(1);
    *(undefined4 *)(in_ECX + 0x2c) = 0;
  }
  _ToBeDeleted_GameThingWithPos__UAEXH_Z(param_1);
  return;
}



// ?SetPlayer@GParticleContainer@@UAEXPAVGPlayer@@@Z @ 0x005efa80

void _SetPlayer_GParticleContainer__UAEXPAVGPlayer___Z(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x2c) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x2c) + 0x20))(param_1);
  }
  return;
}



// ?SetScale@GParticleContainer@@UAEXM@Z @ 0x005efab0

void _SetScale_GParticleContainer__UAEXM_Z(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x2c) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x2c) + 0x11c))(param_1);
  }
  return;
}



// ?Save@GParticleContainer@@UAEIAAVGameOSFile@@@Z @ 0x005efc90

undefined4 _Save_GParticleContainer__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_GameThingWithPos__UAEXPAUGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x38),1,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x38) + 1;
    }
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x28));
    FUN_00533120(in_ECX + 0x2c);
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
      }
    }
    return 1;
  }
  return 0;
}



// ?Load@GParticleContainer@@UAEIAAVGameOSFile@@@Z @ 0x005efd90

undefined4 _Load_GParticleContainer__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Load_GameThingWithPos__QAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x38),1,0,unaff_EBX,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x38) + 1;
    }
    FUN_00531f30();
    FUN_00533110();
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
    return 1;
  }
  return 0;
}



