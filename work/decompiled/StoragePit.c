// Decompiled functions for class: StoragePit
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetResourceNearestEdge@StoragePit@@UAEPAUMapCoords@@PAU2@W4RESOURCE_TYPE@@PAVObject@@H@Z @ 0x00402c70

bool _GetResourceNearestEdge_StoragePit__UAEPAUMapCoords__PAU2_W4RESOURCE_TYPE__PAVObject__H_Z(void)

{
  int in_ECX;
  
  return (*(byte *)(in_ECX + 0x58) & 2) != 2;
}



// ?RemoveResource@StoragePit@@UAEIW4RESOURCE_TYPE@@IPAVGInterfaceStatus@@PA_N@Z @ 0x00403860

undefined4
_RemoveResource_StoragePit__UAEIW4RESOURCE_TYPE__IPAVGInterfaceStatus__PA_N_Z(int param_1)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xbc + param_1 * 4);
}



// ?IsCastShadowAtNight@StoragePit@@UAEIXZ @ 0x00405860

undefined4 _IsCastShadowAtNight_StoragePit__UAEIXZ(void)

{
  undefined4 uVar1;
  int *in_ECX;
  float10 fVar2;
  
  fVar2 = (float10)(**(code **)(*in_ECX + 0x880))();
  if (fVar2 == (float10)0.0) {
    return 0;
  }
  uVar1 = _IsInteractable_GameThingWithPos__UAE_NXZ();
  return uVar1;
}



// ?Load@StoragePit@@UAEIAAVGameOSFile@@@Z @ 0x0052e430

char * _Load_StoragePit__UAEIAAVGameOSFile___Z(void)

{
  return s_StoragePit__00b1a2e8;
}



// ?Delete@StoragePit@@UAEXXZ @ 0x006c8e60

void _Delete_StoragePit__UAEXXZ(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x910))();
  _Delete_Abode__UAEXXZ();
  return;
}



// ?ToBeDeleted@StoragePit@@UAEXH@Z @ 0x006c8e80

void _ToBeDeleted_StoragePit__UAEXH_Z(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  int *piVar3;
  
  (**(code **)(*in_ECX + 0x910))();
  if ((int *)in_ECX[0x31] != (int *)0x0) {
    iVar1 = (**(code **)(*(int *)in_ECX[0x31] + 0x2c))();
    if (iVar1 != 0) {
      (**(code **)(*(int *)in_ECX[0x31] + 0x868))(0);
      (**(code **)(*(int *)in_ECX[0x31] + 0xc))(param_1);
      in_ECX[0x31] = 0;
    }
  }
  piVar3 = in_ECX + 0x32;
  iVar1 = 5;
  do {
    if ((int *)*piVar3 != (int *)0x0) {
      iVar2 = (**(code **)(*(int *)*piVar3 + 0x2c))();
      if (iVar2 != 0) {
        (**(code **)(*(int *)*piVar3 + 0x868))(0);
        (**(code **)(*(int *)*piVar3 + 0xc))(param_1);
        *piVar3 = 0;
      }
    }
    piVar3 = piVar3 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_004019f0(param_1);
  return;
}



// ?IsResourceStore@StoragePit@@UAE_NW4RESOURCE_TYPE@@@Z @ 0x006c90d0

void _IsResourceStore_StoragePit__UAE_NW4RESOURCE_TYPE___Z(void)

{
  int in_ECX;
  
  Creche_vf406(in_ECX + 0x14);
  (**(code **)(**(int **)(in_ECX + 0x40) + 0x1e8))();
  return;
}



