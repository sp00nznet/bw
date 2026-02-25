// Decompiled functions for class: PuzzleGrain
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetSaveType@PuzzleGrain@@UAEIXZ @ 0x00531840

undefined4 _GetSaveType_PuzzleGrain__UAEIXZ(void)

{
  return 0x107;
}



// ?GetDebugText@PuzzleGrain@@UAEPADXZ @ 0x00531850

char * _GetDebugText_PuzzleGrain__UAEPADXZ(void)

{
  return s_PuzzleGrain__00b1b398;
}



// ?CallVirtualFunctionsForCreation@PuzzleGrain@@UAEXABUMapCoords@@@Z @ 0x00531880

void _CallVirtualFunctionsForCreation_PuzzleGrain__UAEXABUMapCoords___Z(undefined4 param_1)

{
  _CallVirtualFunctionsForCreation_MobileObject__UAEXABUMapCoords___Z(param_1);
  return;
}



// ?EndPhysics@PuzzleGrain@@UAEXPAVPhysicsObject@@_N@Z @ 0x00531890

void _EndPhysics_PuzzleGrain__UAEXPAVPhysicsObject___N_Z(undefined4 param_1,undefined4 param_2)

{
  _EndPhysics_Object__UAEXPAVPhysicsObject___N_Z(param_1,param_2);
  return;
}



// ?Load@PuzzleGrain@@UAEIAAVGameOSFile@@@Z @ 0x0067a0f0

undefined4 _Load_PuzzleGrain__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = FUN_00619160(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0xbc),4,0,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xbc) + 4;
    }
    return 1;
  }
  return 0;
}



// ?Save@PuzzleGrain@@UAEIAAVGameOSFile@@@Z @ 0x0067a160

undefined4 _Save_PuzzleGrain__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_00619120(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0xbc),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xbc) + 4;
    }
    return 1;
  }
  return 0;
}



