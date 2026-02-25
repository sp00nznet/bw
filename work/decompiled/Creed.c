// Decompiled functions for class: Creed
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetSaveType@Creed@@UAEIXZ @ 0x004e9ad0

undefined4 _GetSaveType_Creed__UAEIXZ(void)

{
  return 0x6d;
}



// ?GetDebugText@Creed@@UAEPADXZ @ 0x004e9ae0

char * _GetDebugText_Creed__UAEPADXZ(void)

{
  return s_Creed__00b145a4;
}



// ?CallVirtualFunctionsForCreation@Creed@@UAEXABUMapCoords@@@Z @ 0x004e9b00

void _CallVirtualFunctionsForCreation_Creed__UAEXABUMapCoords___Z(undefined4 param_1)

{
  _CallVirtualFunctionsForCreation_MobileObject__UAEXABUMapCoords___Z(param_1);
  FUN_006b5c00();
  return;
}



// ?ToBeDeleted@Creed@@UAEXH@Z @ 0x004e9b30

void _ToBeDeleted_Creed__UAEXH_Z(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x68);
  if (iVar1 != 0) {
    FUN_00636360();
    FUN_007290de(iVar1);
    *(undefined4 *)(in_ECX + 0x68) = 0;
  }
  FUN_006b5fa0();
  _ToBeDeleted_MobileObject__UAEXH_Z(param_1);
  return;
}



// ?Create3DObject@Creed@@UAEXXZ @ 0x004e9b80

void _Create3DObject_Creed__UAEXXZ(void)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int *in_ECX;
  float10 fVar4;
  
  piVar2 = (int *)in_ECX[10];
  fVar4 = (float10)(**(code **)(*in_ECX + 0x120))();
  fVar4 = (float10)(**(code **)(*in_ECX + 0x508))((float)fVar4);
  uVar1 = (**(code **)(*piVar2 + 0x2c))((float)fVar4);
  piVar2 = (int *)FUN_005ecf60(in_ECX + 5,0,uVar1);
  in_ECX[0x10] = (int)piVar2;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x58))();
    (**(code **)(*(int *)in_ECX[0x10] + 0x78))();
    iVar3 = FUN_00746d70(0x14,s_C__dev_black_PSysHandFX_h_00b145ac,0x3e);
    if (iVar3 != 0) {
      iVar3 = FUN_006362e0();
      in_ECX[0x1a] = iVar3;
      return;
    }
    in_ECX[0x1a] = 0;
  }
  return;
}



// ?SetScale@Creed@@UAEXM@Z @ 0x004e9c00

void _SetScale_Creed__UAEXM_Z(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x68) != 0) {
    FUN_005bea40(param_1);
  }
  return;
}



// ?Save@Creed@@UAEIAAVGameOSFile@@@Z @ 0x004e9c20

bool _Save_Creed__UAEIAAVGameOSFile___Z(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _Save_MobileObject__UAEIAAVGameOSFile___Z(param_1);
  return iVar1 != 0;
}



// ?Load@Creed@@UAEIAAVGameOSFile@@@Z @ 0x004e9c40

bool _Load_Creed__UAEIAAVGameOSFile___Z(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _Load_MobileObject__UAEIAAVGameOSFile___Z(param_1);
  return iVar1 != 0;
}



// ?Draw@Creed@@UAEXXZ @ 0x004f4cd0

void _Draw_Creed__UAEXXZ(void)

{
  int iVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x68) != 0) && (iVar1 = *(int *)(in_ECX + 0x40), iVar1 != 0)) {
    FUN_00636390(iVar1 + 0x14,*(undefined4 *)(iVar1 + 0x44));
    FUN_005ed680();
  }
  return;
}



// ?DrawOutOfMap@Creed@@UAEX_N@Z @ 0x004f4d00

void _DrawOutOfMap_Creed__UAEX_N_Z(void)

{
  uint *puVar1;
  int in_ECX;
  
  if ((*(int *)(in_ECX + 0x68) != 0) && (*(int *)(in_ECX + 0x40) != 0)) {
    puVar1 = (uint *)(*(int *)(in_ECX + 0x40) + 8);
    *puVar1 = *puVar1 | 0x40;
    FUN_00636390(*(int *)(in_ECX + 0x40) + 0x14,*(undefined4 *)(*(int *)(in_ECX + 0x40) + 0x44));
    puVar1 = (uint *)(*(int *)(in_ECX + 0x40) + 8);
    *puVar1 = *puVar1 & 0xffffffbf;
  }
  return;
}



