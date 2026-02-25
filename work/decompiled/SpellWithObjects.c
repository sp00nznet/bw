// Decompiled functions for class: SpellWithObjects
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetDebugText@SpellWithObjects@@UAEPADXZ @ 0x0052e550

char * _GetDebugText_SpellWithObjects__UAEPADXZ(void)

{
  return s_SpellWithObjects__00b1a2f4;
}



// ?GetSaveType@SpellWithObjects@@UAEIXZ @ 0x005be0f0

undefined4 _GetSaveType_SpellWithObjects__UAEIXZ(void)

{
  return 0x14;
}



// ?ToBeDeleted@SpellWithObjects@@UAEXH@Z @ 0x006b81d0

void _ToBeDeleted_SpellWithObjects__UAEXH_Z(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x530))();
  while (piVar1 = (int *)in_ECX[0x3b], piVar1 != (int *)0x0) {
    iVar2 = piVar1[1];
    piVar4 = (int *)0x0;
    while (piVar3 = piVar4, piVar4 = piVar1, piVar4 != (int *)0x0) {
      piVar1 = (int *)*piVar4;
      if (piVar4[1] == iVar2) {
        if (piVar4 == (int *)in_ECX[0x3b]) {
          in_ECX[0x3b] = (int)piVar1;
        }
        else {
          *piVar3 = (int)piVar1;
        }
        in_ECX[0x3c] = in_ECX[0x3c] + -1;
        FUN_007290de(piVar4);
        piVar4 = piVar3;
      }
    }
  }
  _ToBeDeleted_Spell__UAEXH_Z(param_1);
  return;
}



// ?Load@SpellWithObjects@@UAEIAAVGameOSFile@@@Z @ 0x006b82f0

undefined4 _Load_SpellWithObjects__UAEIAAVGameOSFile___Z(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 *puVar4;
  int in_stack_00005d0d;
  uint in_stack_00005d15;
  
  iVar2 = _Load_Spell__UAEIAAVGameOSFile___Z();
  if (iVar2 == 0) {
    return 0;
  }
  if (DAT_00b19acc != 0) {
    iVar2 = FUN_0072be50();
    if (iVar2 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (in_stack_00005d15 & 0xff) + 4;
    for (; 0 < (int)in_stack_00005d15; in_stack_00005d15 = in_stack_00005d15 - 1) {
      FUN_00531f30();
      if ((in_stack_00005d0d != 0) && (puVar3 = operator_new(8), puVar3 != (undefined4 *)0x0)) {
        puVar3[1] = in_stack_00005d0d;
        *puVar3 = 0;
        puVar1 = *(undefined4 **)(in_ECX + 0xec);
        if (*(undefined4 **)(in_ECX + 0xec) == (undefined4 *)0x0) {
LAB_006b839c:
          *(undefined4 **)(in_ECX + 0xec) = puVar3;
        }
        else {
          do {
            puVar4 = puVar1;
            puVar1 = (undefined4 *)*puVar4;
          } while ((undefined4 *)*puVar4 != (undefined4 *)0x0);
          if (puVar4 == (undefined4 *)0x0) goto LAB_006b839c;
          *puVar4 = puVar3;
        }
        *(int *)(in_ECX + 0xf0) = *(int *)(in_ECX + 0xf0) + 1;
      }
    }
  }
  return 1;
}



// ?Save@SpellWithObjects@@UAEIAAVGameOSFile@@@Z @ 0x006b83d0

undefined4 _Save_SpellWithObjects__UAEIAAVGameOSFile___Z(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  
  iVar2 = _Save_Spell__UAEIAAVGameOSFile___Z(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  if (DAT_00b19ac8 != 0) {
    iVar2 = *(int *)(in_ECX + 0xf0);
    iVar4 = 0;
    iVar3 = FUN_0072be90((byte *)(in_ECX + 0xf0),4,0);
    if (iVar3 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xf0) + 4;
    for (puVar1 = *(undefined4 **)(in_ECX + 0xec); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      iVar4 = iVar4 + 1;
      if (iVar2 < iVar4) goto LAB_006b846e;
      if (DAT_00b19ac8 == 0) {
        return 1;
      }
      FUN_00531bc0(puVar1[1]);
    }
    if ((DAT_00b19ac8 != 0) && (iVar4 != iVar2)) {
LAB_006b846e:
      DAT_00b19ac8 = 0;
    }
  }
  return 1;
}



// ?Process@SpellWithObjects@@UAEIXZ @ 0x006b8490

undefined4 _Process_SpellWithObjects__UAEIXZ(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  FUN_006b78b0();
  iVar1 = FUN_006b8240();
  if ((iVar1 != 0) || (uVar2 = 5, *(int *)(in_ECX + 0xb0) != 0)) {
    uVar2 = 1;
  }
  return uVar2;
}



// ?CloseDown@SpellWithObjects@@UAEXXZ @ 0x006b84d0

void _CloseDown_SpellWithObjects__UAEXXZ(void)

{
  undefined4 *puVar1;
  char cVar2;
  int *in_ECX;
  
  FUN_006b7420();
  cVar2 = (**(code **)(*in_ECX + 0x554))();
  if (cVar2 != '\0') {
    for (puVar1 = (undefined4 *)in_ECX[0x3b]; puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      if ((*(byte *)((int)puVar1[1] + 10) & 1) == 0) {
        (**(code **)(*(int *)puVar1[1] + 0x6a4))();
      }
    }
  }
  return;
}



