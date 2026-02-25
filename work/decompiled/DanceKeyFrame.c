// Decompiled functions for class: DanceKeyFrame
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetSaveType@DanceKeyFrame@@UAEIXZ @ 0x004ec6d0

undefined4 _GetSaveType_DanceKeyFrame__UAEIXZ(void)

{
  return 0x7a;
}



// ?GetDebugText@DanceKeyFrame@@UAEPADXZ @ 0x004ec6e0

char * _GetDebugText_DanceKeyFrame__UAEPADXZ(void)

{
  return s_DanceKeyFrame__00b16074;
}



// ?ToBeDeleted@DanceKeyFrame@@UAEXH@Z @ 0x004ec6f0

void _ToBeDeleted_DanceKeyFrame__UAEXH_Z(undefined4 param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_ECX;
  
LAB_004ec6f6:
  do {
    if (*(int *)(in_ECX + 0x18) == 0) {
      _ToBeDeleted_GameThing__UAEXH_Z(param_1);
      return;
    }
    piVar1 = *(int **)(*(int *)(in_ECX + 0x18) + 4);
    (**(code **)(*piVar1 + 0xc))(0);
    puVar2 = *(undefined4 **)(in_ECX + 0x18);
    while( true ) {
      if (puVar2 == (undefined4 *)0x0) goto LAB_004ec6f6;
      if ((int *)puVar2[1] == piVar1) break;
      puVar2 = (undefined4 *)*puVar2;
    }
    puVar2 = *(undefined4 **)(in_ECX + 0x18);
    puVar4 = (undefined4 *)0x0;
    while (puVar3 = puVar4, puVar4 = puVar2, puVar4 != (undefined4 *)0x0) {
      puVar2 = (undefined4 *)*puVar4;
      if ((int *)puVar4[1] == piVar1) {
        if (puVar4 == *(undefined4 **)(in_ECX + 0x18)) {
          *(undefined4 **)(in_ECX + 0x18) = puVar2;
        }
        else {
          *puVar3 = puVar2;
        }
        *(int *)(in_ECX + 0x1c) = *(int *)(in_ECX + 0x1c) + -1;
        FUN_007290de(puVar4);
        puVar4 = puVar3;
      }
    }
  } while( true );
}



// ?Save@DanceKeyFrame@@UAEIAAVGameOSFile@@@Z @ 0x004ecc90

undefined4 _Save_DanceKeyFrame__UAEIAAVGameOSFile___Z(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  
  iVar2 = FUN_0053e8e0(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = 0;
  if (DAT_00b19ac8 != 0) {
    iVar3 = FUN_0072be90((byte *)(in_ECX + 0x14),4,0);
    if (iVar3 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x14) + 4;
    if (DAT_00b19ac8 != 0) {
      iVar3 = *(int *)(in_ECX + 0x1c);
      iVar4 = FUN_0072be90((byte *)(in_ECX + 0x1c),4,0);
      if (iVar4 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x1c) + 4;
      for (puVar1 = *(undefined4 **)(in_ECX + 0x18); puVar1 != (undefined4 *)0x0;
          puVar1 = (undefined4 *)*puVar1) {
        iVar2 = iVar2 + 1;
        if (iVar3 < iVar2) {
          DAT_00b19ac8 = 0;
          return 1;
        }
        if (DAT_00b19ac8 == 0) {
          return 1;
        }
        FUN_00531bc0(puVar1[1]);
      }
      if (DAT_00b19ac8 != 0) {
        if (iVar2 != iVar3) {
          DAT_00b19ac8 = 0;
          return 1;
        }
        iVar2 = FUN_0072be90((byte *)(in_ECX + 0x20),4,0);
        if (iVar2 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x20) + 4;
      }
    }
  }
  return 1;
}



// ?Load@DanceKeyFrame@@UAEIAAVGameOSFile@@@Z @ 0x004ecdc0

undefined4 _Load_DanceKeyFrame__UAEIAAVGameOSFile___Z(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  undefined4 *puVar4;
  int in_stack_0000ba1e;
  uint in_stack_0000ba26;
  
  iVar2 = FUN_0053e9f0();
  if (iVar2 == 0) {
    return 0;
  }
  if (DAT_00b19acc != 0) {
    iVar2 = FUN_0072be50();
    if (iVar2 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x14) + 4;
    if (DAT_00b19acc != 0) {
      iVar2 = FUN_0072be50();
      if (iVar2 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (in_stack_0000ba26 & 0xff) + 4;
      for (; 0 < (int)in_stack_0000ba26; in_stack_0000ba26 = in_stack_0000ba26 - 1) {
        FUN_00531f30();
        if ((in_stack_0000ba1e != 0) && (puVar3 = operator_new(8), puVar3 != (undefined4 *)0x0)) {
          puVar3[1] = in_stack_0000ba1e;
          *puVar3 = 0;
          puVar1 = *(undefined4 **)(in_ECX + 0x18);
          if (*(undefined4 **)(in_ECX + 0x18) == (undefined4 *)0x0) {
LAB_004ecea9:
            *(undefined4 **)(in_ECX + 0x18) = puVar3;
          }
          else {
            do {
              puVar4 = puVar1;
              puVar1 = (undefined4 *)*puVar4;
            } while ((undefined4 *)*puVar4 != (undefined4 *)0x0);
            if (puVar4 == (undefined4 *)0x0) goto LAB_004ecea9;
            *puVar4 = puVar3;
          }
          *(int *)(in_ECX + 0x1c) = *(int *)(in_ECX + 0x1c) + 1;
        }
      }
    }
  }
  if (DAT_00b19acc != 0) {
    iVar2 = FUN_0072be50();
    if (iVar2 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x20) + 4;
  }
  return 1;
}



