// Decompiled functions for class: Rock
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetSampleForAttack@Rock@@UAEIXZ @ 0x00432200

char * _GetSampleForAttack_Rock__UAEIXZ(void)

{
  return s_Bonfire__008fbf10;
}



// ?GetSampleForAttack@Rock@@UAEIXZ @ 0x004eee40

char * _GetSampleForAttack_Rock__UAEIXZ(void)

{
  return s_FelledTree__00b166f4;
}



// ?GetSampleForAttack@Rock@@UAEIXZ @ 0x005314f0

char * _GetSampleForAttack_Rock__UAEIXZ(void)

{
  return s_Rock__00b1b2f4;
}



// ?RemoveResource@Rock@@UAEIW4RESOURCE_TYPE@@IPAVGInterfaceStatus@@PA_N@Z @ 0x006821d0

int _RemoveResource_Rock__UAEIW4RESOURCE_TYPE__IPAVGInterfaceStatus__PA_N_Z
              (float param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x690))();
  if ((float)iVar1 != param_1) {
    return 0;
  }
  iVar2 = (**(code **)(*in_ECX + 0x694))();
  iVar1 = in_ECX[10];
  param_1 = (float)(uint)(iVar2 + param_2) / (float)*(int *)(iVar1 + 0x6c);
  if (*(float *)(iVar1 + 0x124) <= param_1) {
    param_1 = *(float *)(iVar1 + 0x124);
  }
  (**(code **)(*in_ECX + 0x124))(param_1);
  iVar1 = (**(code **)(*in_ECX + 0x694))();
  return iVar1 - iVar2;
}



// ?GetPlayer@Rock@@UAEPAVGPlayer@@XZ @ 0x006825c0

undefined4 _GetPlayer_Rock__UAEPAVGPlayer__XZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x90);
}



// ?GetSaveType@Rock@@UAEIXZ @ 0x006825d0

undefined4 _GetSaveType_Rock__UAEIXZ(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _ResolveLoad_Object__UAEXXZ(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x88),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x88) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90((byte *)(in_ECX + 0x8c),4,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x8c) + 4;
      }
    }
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x90));
    return 1;
  }
  return 0;
}



// ?Save@Rock@@UAEIAAVGameOSFile@@@Z @ 0x00682690

undefined4 _Save_Rock__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _SaveExtraData_GameThing__QAEXAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x88),4,0,unaff_EDI,unaff_ESI,unaff_EBX);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x88) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x8c) + 4;
    }
    FUN_00531f30();
    return 1;
  }
  return 0;
}



// ?SetPlayer@Rock@@UAEXPAVGPlayer@@@Z @ 0x00767bc0

void _SetPlayer_Rock__UAEXPAVGPlayer___Z(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x90) = param_1;
  return;
}



