// Decompiled functions for class: DeadTree
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetGuidanceResourceType@DeadTree@@UAEIXZ @ 0x004ee070

char * _GetGuidanceResourceType_DeadTree__UAEIXZ(void)

{
  return s_DeadTree__00b166c8;
}



// ?GetWoodValue@DeadTree@@UAEMXZ @ 0x004ee0e0

void _GetWoodValue_DeadTree__UAEMXZ(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  float10 fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  *(ushort *)(in_ECX + 0x26) = *(ushort *)(in_ECX + 0x26) & 0xffe0;
  (**(code **)(*in_ECX + 0x538))();
  (**(code **)(*in_ECX + 0x850))();
  (**(code **)(*(int *)in_ECX[0x10] + 0x80))();
  (**(code **)(*(int *)in_ECX[0x10] + 0x90))();
  iVar1 = *(int *)in_ECX[0x10];
  uVar2 = FUN_004ee2b0();
  uVar2 = FUN_004ee2b0(uVar2);
  FUN_004ee2b0(uVar2);
  (**(code **)(iVar1 + 0xf4))();
  FUN_00504d40();
  *(undefined4 *)(in_ECX[0x10] + 0x10) = 0x3f800000;
  (**(code **)(*(int *)in_ECX[0x10] + 0x58))();
  fVar3 = (float10)(**(code **)(*in_ECX + 0x120))();
  fVar6 = (float)fVar3;
  fVar3 = (float10)(**(code **)(*in_ECX + 0x50c))(fVar6);
  fVar5 = (float)fVar3;
  fVar3 = (float10)(**(code **)(*in_ECX + 0x508))(fVar5);
  fVar4 = (float)fVar3;
  fVar3 = (float10)(**(code **)(*in_ECX + 0x504))(fVar4);
  FUN_005ed520((float)fVar3,fVar4,fVar5,fVar6);
  if (((*(byte *)(in_ECX + 9) & 4) == 0) && ((*(byte *)((int)in_ECX + 10) & 0x11) == 0)) {
    (**(code **)(*in_ECX + 0x544))();
  }
  return;
}



// ?ToBeDeleted@DeadTree@@UAEXH@Z @ 0x004ee2e0

void _ToBeDeleted_DeadTree__UAEXH_Z(undefined4 param_1)

{
  _ToBeDeleted_MobileStatic__UAEXH_Z(param_1);
  return;
}



// ?CreatureMustAvoid@DeadTree@@UAE_NPAVCreature@@@Z @ 0x004ee2f0

void _CreatureMustAvoid_DeadTree__UAE_NPAVCreature___Z(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)FUN_005f3c50();
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x680))(1);
    if (iVar2 != 0) {
      (**(code **)(*piVar1 + 0x684))();
    }
  }
  return;
}



// ?InteractsWithPhysicsObjects@DeadTree@@UAE_NXZ @ 0x004ee740

void _InteractsWithPhysicsObjects_DeadTree__UAE_NXZ(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  float10 fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  iVar1 = 0x196;
  if (*DAT_00d76c64 < 0x197) {
    iVar1 = 0;
  }
  iVar1 = DAT_00d76c64[iVar1 + 1];
  iVar2 = (**(code **)(*(int *)in_ECX[0x10] + 0xf8))();
  if (iVar2 == iVar1) {
    _SetUpPhysOb_Object__UAEXPAVPhysOb___Z(param_1);
    return;
  }
  fVar3 = (float10)(**(code **)(*in_ECX + 0x120))();
  fVar6 = (float)fVar3;
  fVar3 = (float10)(**(code **)(*in_ECX + 100))(fVar6);
  fVar5 = (float)fVar3;
  fVar3 = (float10)(**(code **)(*in_ECX + 0x42c))(fVar5);
  fVar4 = (float)fVar3;
  fVar3 = (float10)(**(code **)(*in_ECX + 0x638))(fVar4);
  FUN_005ec4a0(param_1,(float)fVar3,fVar4,fVar5,fVar6);
  return;
}



// ?GetSaveType@DeadTree@@UAEIXZ @ 0x004eebc0

undefined4 _GetSaveType_DeadTree__UAEIXZ(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Save_Rock__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    FUN_00533bf0(in_ECX + 0x94);
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x9c),4,0,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x9c) + 4;
    }
    return 1;
  }
  return 0;
}



