// Decompiled functions for class: FishFarm
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Get2DRadius@FishFarm@@UAEMXZ @ 0x00502a60

float10 _Get2DRadius_FishFarm__UAEMXZ(void)

{
  return (float10)5.0;
}



// ?ToBeDeleted@FishFarm@@UAEXH@Z @ 0x00502b60

void _ToBeDeleted_FishFarm__UAEXH_Z(undefined4 param_1)

{
  FUN_00502b80();
  _ToBeDeleted_MultiMapFixed__UAEXH_Z(param_1);
  return;
}



// ?RemoveMapObject@FishFarm@@UAEXXZ @ 0x00502eb0

void _RemoveMapObject_FishFarm__UAEXXZ(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_10 = 0;
  uStack_c = 0;
  uStack_8 = 0;
  uStack_4 = 0;
  iVar1 = FUN_00502de0(&uStack_c,&uStack_10);
  while (iVar1 != 0) {
    uVar2 = FUN_005bfa00();
    _InsertMapObjectToCell_Fixed__UAEXPAUMapCell___Z(uVar2);
    iVar1 = FUN_00502de0(&uStack_c,&uStack_10);
  }
  *(byte *)(in_ECX + 0x24) = *(byte *)(in_ECX + 0x24) | 1;
  return;
}



// ?SetMapChild@FishFarm@@UAEXPAVObject@@PAUMapCell@@@Z @ 0x00502f70

undefined4 _SetMapChild_FishFarm__UAEXPAVObject__PAUMapCell___Z(void)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  int iStack_10;
  undefined2 uStack_c;
  ushort uStack_a;
  undefined2 uStack_8;
  ushort uStack_6;
  undefined2 uStack_4;
  undefined2 uStack_2;
  
  iStack_10 = 0;
  uStack_c = 0;
  uStack_a = 0;
  uStack_8 = 0;
  uStack_6 = 0;
  uStack_4 = 0;
  uStack_2 = 0;
  iVar3 = FUN_00502de0(&uStack_c,&iStack_10);
  uVar1 = uStack_a;
  while( true ) {
    if (iVar3 == 0) {
      return 0;
    }
    uStack_a = uVar1;
    uVar4 = FUN_005bea50();
    uVar2 = uStack_6;
    if ((uVar1 == uVar4) && (uVar4 = FUN_005bea70(), uVar2 == uVar4)) break;
    iVar3 = FUN_00502de0(&uStack_c,&iStack_10);
    uVar1 = uStack_a;
  }
  return *(undefined4 *)(*(int *)(in_ECX + 0x68) + -8 + iStack_10 * 8);
}



// ?InsertMapObject@FishFarm@@UAEXXZ @ 0x00503010

void _InsertMapObject_FishFarm__UAEXXZ(undefined4 param_1)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  int iStack_10;
  undefined2 uStack_c;
  ushort uStack_a;
  undefined2 uStack_8;
  ushort uStack_6;
  undefined2 uStack_4;
  undefined2 uStack_2;
  
  iStack_10 = 0;
  uStack_c = 0;
  uStack_a = 0;
  uStack_8 = 0;
  uStack_6 = 0;
  uStack_4 = 0;
  uStack_2 = 0;
  iVar3 = FUN_00502de0(&uStack_c,&iStack_10);
  if (iVar3 != 0) {
    while ((uVar1 = uStack_a, uVar4 = FUN_005bea50(), uVar2 = uStack_6, uVar1 != uVar4 ||
           (uVar4 = FUN_005bea70(), uVar2 != uVar4))) {
      iVar3 = FUN_00502de0(&uStack_c,&iStack_10);
      if (iVar3 == 0) {
        return;
      }
    }
    *(undefined4 *)(*(int *)(in_ECX + 0x68) + -8 + iStack_10 * 8) = param_1;
  }
  return;
}



// ?GetSaveType@FishFarm@@UAEIXZ @ 0x005037c0

undefined4 _GetSaveType_FishFarm__UAEIXZ(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  
  iVar2 = _Save_MultiMapFixed__UAEIPAVGameOSFile___Z(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  if (DAT_00b19ac8 != 0) {
    iVar2 = *(int *)(in_ECX + 0x84);
    iVar4 = 0;
    iVar3 = FUN_0072be90((byte *)(in_ECX + 0x84),4,0);
    if (iVar3 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x84) + 4;
    for (puVar1 = *(undefined4 **)(in_ECX + 0x80); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      iVar4 = iVar4 + 1;
      if (iVar2 < iVar4) goto LAB_0050385e;
      if (DAT_00b19ac8 == 0) goto LAB_00503868;
      FUN_00531bc0(puVar1[1]);
    }
    if ((DAT_00b19ac8 != 0) && (iVar4 != iVar2)) {
LAB_0050385e:
      DAT_00b19ac8 = 0;
    }
  }
LAB_00503868:
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0x8c));
  if (DAT_00b19ac8 != 0) {
    iVar2 = FUN_0072be90((byte *)(in_ECX + 0x90),4,0);
    if (iVar2 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x90) + 4;
    if (DAT_00b19ac8 != 0) {
      iVar2 = FUN_0072be90((byte *)(in_ECX + 0x94),4,0);
      if (iVar2 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x94) + 4;
    }
  }
  return 1;
}



// ?Save@FishFarm@@UAEIAAVGameOSFile@@@Z @ 0x00503900

undefined4 _Save_FishFarm__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  int in_ECX;
  int in_stack_00005d09;
  int in_stack_00005d0d;
  uint in_stack_00005d15;
  int in_stack_0000ba1a;
  
  iVar1 = _Load__13MultiMapFixedFR10GameOSFile();
  if (iVar1 != 0) {
    iVar1 = in_ECX;
    if (DAT_00b19acc != 0) {
      iVar2 = FUN_0072be50();
      if (iVar2 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (in_stack_00005d15 & 0xff) + 4;
      for (; 0 < (int)in_stack_00005d15; in_stack_00005d15 = in_stack_00005d15 - 1) {
        FUN_00531f30();
        if (((in_stack_00005d0d != 0) && (pvVar3 = operator_new(8), pvVar3 != (void *)0x0)) &&
           (iVar1 = FUN_004ecf30(), iVar1 != 0)) {
          piVar4 = (int *)FUN_004ecf10();
          if (piVar4 == (int *)0x0) {
            *(int *)(in_ECX + 0x80) = iVar1;
          }
          else {
            *piVar4 = iVar1;
          }
          *(int *)(in_ECX + 0x84) = *(int *)(in_ECX + 0x84) + 1;
        }
        iVar1 = in_stack_00005d09;
      }
    }
    FUN_00531f30();
    if (DAT_00b19acc != 0) {
      iVar2 = FUN_0072be50();
      if (iVar2 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(iVar1 + 0x90) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) =
           *(int *)(param_1 + 0x214) + *(byte *)(in_stack_0000ba1a + 0x94) + 4;
    }
    return 1;
  }
  return 0;
}



// ?GetPlayer@FishFarm@@UAEPAVGPlayer@@XZ @ 0x006da500

undefined4 _GetPlayer_FishFarm__UAEPAVGPlayer__XZ(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x48))();
  if (iVar1 != 0) {
    piVar2 = (int *)(**(code **)(*in_ECX + 0x48))();
    uVar3 = (**(code **)(*piVar2 + 0x1c))();
    return uVar3;
  }
  return 0;
}



// ?GetTown@FishFarm@@UAEPAVTown@@XZ @ 0x00767bb0

undefined4 _GetTown_FishFarm__UAEPAVTown__XZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x8c);
}



