// Decompiled functions for class: WorkshopBuildingSite
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?AddResource@WorkshopBuildingSite@@UAEIW4RESOURCE_TYPE@@IPAVGInterfaceStatus@@_NPBUMapCoords@@H@Z @ 0x00436180

undefined4
_AddResource_WorkshopBuildingSite__UAEIW4RESOURCE_TYPE__IPAVGInterfaceStatus___NPBUMapCoords__H_Z
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x14) != (int *)0x0) {
    uVar1 = (**(code **)(**(int **)(in_ECX + 0x14) + 0x9c))
                      (param_1,param_2,param_3,param_4,param_5,0);
    return uVar1;
  }
  return 0;
}



// ?RemoveResource@WorkshopBuildingSite@@UAEIW4RESOURCE_TYPE@@IPAVGInterfaceStatus@@PA_N@Z @ 0x004361c0

undefined4
_RemoveResource_WorkshopBuildingSite__UAEIW4RESOURCE_TYPE__IPAVGInterfaceStatus__PA_N_Z
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x14) != (int *)0x0) {
    uVar1 = (**(code **)(**(int **)(in_ECX + 0x14) + 0xa0))(param_1,param_2,param_3,param_4);
    return uVar1;
  }
  return 0;
}



