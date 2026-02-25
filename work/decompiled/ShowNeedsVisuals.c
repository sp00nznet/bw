// Decompiled functions for class: ShowNeedsVisuals
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?SetScale@ShowNeedsVisuals@@UAEXM@Z @ 0x0052edb0

void _SetScale_ShowNeedsVisuals__UAEXM_Z(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x58) = param_1;
  return;
}



// ?GetScale@ShowNeedsVisuals@@UAEMXZ @ 0x0052edc0

float10 _GetScale_ShowNeedsVisuals__UAEMXZ(void)

{
  int in_ECX;
  
  return (float10)*(float *)(in_ECX + 0x58);
}



// ?GetText@ShowNeedsVisuals@@UAEPBDXZ @ 0x0052edd0

char * _GetText_ShowNeedsVisuals__UAEPBDXZ(void)

{
  return s_Show_Needs_00b1a460;
}



// ?GetSaveType@ShowNeedsVisuals@@UAEIXZ @ 0x0052ede0

undefined4 _GetSaveType_ShowNeedsVisuals__UAEIXZ(void)

{
  return 0x3d;
}



// ?GetDebugText@ShowNeedsVisuals@@UAEPADXZ @ 0x0052edf0

char * _GetDebugText_ShowNeedsVisuals__UAEPADXZ(void)

{
  return s_ShowNeedsVisuals__00b1a46c;
}



// ?ToBeDeleted@ShowNeedsVisuals@@UAEXH@Z @ 0x006b15e0

void _ToBeDeleted_ShowNeedsVisuals__UAEXH_Z(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x40) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x40) + 4))();
    *(undefined4 *)(in_ECX + 0x40) = 0;
  }
  _ToBeDeleted_GameThingWithPos__UAEXH_Z(param_1);
  return;
}



// ?CallVirtualFunctionsForCreation@ShowNeedsVisuals@@UAEXABUMapCoords@@@Z @ 0x006b1610

void _CallVirtualFunctionsForCreation_ShowNeedsVisuals__UAEXABUMapCoords___Z(void)

{
  undefined4 uVar1;
  int *piVar2;
  int *in_ECX;
  
  uVar1 = (**(code **)(*in_ECX + 0x608))();
  uVar1 = FUN_005e8a20(uVar1);
  piVar2 = (int *)FUN_005ecd90(uVar1);
  in_ECX[0x10] = (int)piVar2;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x58))();
    (**(code **)(*in_ECX + 0x608))();
    (**(code **)(*(int *)in_ECX[0x10] + 0xf4))(0,0);
    in_ECX[0x15] = 0;
    (**(code **)(*in_ECX + 0x124))(0x3f800000);
  }
  return;
}



// ?GetPlayer@ShowNeedsVisuals@@UAEPAVGPlayer@@XZ @ 0x006b19c0

void _GetPlayer_ShowNeedsVisuals__UAEPAVGPlayer__XZ(void)

{
  int in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x006b19c5. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x60) + 0x1c))();
  return;
}



// ?Save@ShowNeedsVisuals@@UAEIAAVGameOSFile@@@Z @ 0x006b1a00

undefined4 _Save_ShowNeedsVisuals__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_Object__UAEIPAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x54),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x54) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90((byte *)(in_ECX + 0x58),4,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x58) + 4;
      }
    }
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x60));
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x5c),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x5c) + 4;
    }
    return 1;
  }
  return 0;
}



// ?Load@ShowNeedsVisuals@@UAEIAAVGameOSFile@@@Z @ 0x006b1af0

undefined4 _Load_ShowNeedsVisuals__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Load__6ObjectFR10GameOSFile(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x54),4,0,unaff_EDI,unaff_ESI,unaff_EBX);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x54) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x58) + 4;
    }
    FUN_00531f30();
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x5c) + 4;
    }
    return 1;
  }
  return 0;
}



// ?ResolveLoad@ShowNeedsVisuals@@UAEXXZ @ 0x006d5f20

void _ResolveLoad_ShowNeedsVisuals__UAEXXZ(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x658))(in_ECX + 5);
  return;
}



