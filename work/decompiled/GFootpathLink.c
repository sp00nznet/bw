// Decompiled functions for class: GFootpathLink
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetDebugText@GFootpathLink@@UAEPADXZ @ 0x004eaeb0

char * _GetDebugText_GFootpathLink__UAEPADXZ(void)

{
  return s_FootpathLink__00b1462c;
}



// ?ToBeDeleted@GFootpathLink@@UAEXH@Z @ 0x0050ae50

void _ToBeDeleted_GFootpathLink__UAEXH_Z(undefined4 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_ECX;
  
  while (puVar1 = *(undefined4 **)(in_ECX + 0x14), puVar1 != (undefined4 *)0x0) {
    iVar2 = puVar1[1];
    puVar4 = (undefined4 *)0x0;
    while (puVar3 = puVar4, puVar4 = puVar1, puVar4 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*puVar4;
      if (puVar4[1] == iVar2) {
        if (puVar4 == *(undefined4 **)(in_ECX + 0x14)) {
          *(undefined4 **)(in_ECX + 0x14) = puVar1;
        }
        else {
          *puVar3 = puVar1;
        }
        *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + -1;
        FUN_007290de(puVar4);
        puVar4 = puVar3;
      }
    }
  }
  _ToBeDeleted_GameThing__UAEXH_Z(param_1);
  return;
}



// ?AddFootpath@GFootpathLink@@UAEIPAVGFootpath@@@Z @ 0x0050aeb0

undefined4 _AddFootpath_GFootpathLink__UAEIPAVGFootpath___Z(int param_1)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int in_ECX;
  
  if (param_1 != 0) {
    puVar2 = operator_new(8);
    if (puVar2 != (undefined4 *)0x0) {
      uVar1 = *(undefined4 *)(in_ECX + 0x14);
      puVar2[1] = param_1;
      *puVar2 = uVar1;
      *(undefined4 **)(in_ECX + 0x14) = puVar2;
      *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + 1;
    }
  }
  return 1;
}



// ?RemoveFootpath@GFootpathLink@@UAEIPAVGFootpath@@@Z @ 0x0050aef0

undefined4 _RemoveFootpath_GFootpathLink__UAEIPAVGFootpath___Z(int param_1)

{
  int *piVar1;
  int *piVar2;
  int in_ECX;
  int *piVar3;
  int *piVar4;
  
  piVar2 = *(int **)(in_ECX + 0x14);
  piVar3 = (int *)0x0;
  if (piVar2 == (int *)0x0) {
    return 1;
  }
  do {
    piVar1 = (int *)*piVar2;
    piVar4 = piVar2;
    if (piVar2[1] == param_1) {
      if (piVar2 == *(int **)(in_ECX + 0x14)) {
        *(int **)(in_ECX + 0x14) = piVar1;
      }
      else {
        *piVar3 = (int)piVar1;
      }
      *(int *)(in_ECX + 0x18) = *(int *)(in_ECX + 0x18) + -1;
      FUN_007290de(piVar2);
      piVar4 = piVar3;
    }
    piVar2 = piVar1;
    piVar3 = piVar4;
  } while (piVar1 != (int *)0x0);
  return 1;
}



// ?Save@GFootpathLink@@UAEIAAVGameOSFile@@@Z @ 0x0050b310

undefined4 _Save_GFootpathLink__UAEIAAVGameOSFile___Z(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  
  iVar2 = FUN_0053e8e0(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  if (DAT_00b19ac8 != 0) {
    iVar2 = *(int *)(in_ECX + 0x18);
    iVar4 = 0;
    iVar3 = FUN_0072be90((byte *)(in_ECX + 0x18),4,0);
    if (iVar3 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x18) + 4;
    for (puVar1 = *(undefined4 **)(in_ECX + 0x14); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      iVar4 = iVar4 + 1;
      if (iVar2 < iVar4) goto LAB_0050b3a1;
      if (DAT_00b19ac8 == 0) {
        return 1;
      }
      FUN_00531bc0(puVar1[1]);
    }
    if ((DAT_00b19ac8 != 0) && (iVar4 != iVar2)) {
LAB_0050b3a1:
      DAT_00b19ac8 = 0;
    }
  }
  return 1;
}



