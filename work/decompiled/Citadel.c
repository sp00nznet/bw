// Decompiled functions for class: Citadel
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetText@Citadel@@UAEPBDXZ @ 0x0044e3a0

char * _GetText_Citadel__UAEPBDXZ(void)

{
  return s_Citadel_008fc824;
}



// ?GetSaveType@Citadel@@UAEIXZ @ 0x0044e3b0

undefined4 _GetSaveType_Citadel__UAEIXZ(void)

{
  return 0x35;
}



// ?GetDebugText@Citadel@@UAEPADXZ @ 0x0044e3c0

char * _GetDebugText_Citadel__UAEPADXZ(void)

{
  return s_Citadel__008fcf08;
}



// ?ToBeDeleted@Citadel@@UAEXH@Z @ 0x0044e480

void _ToBeDeleted_Citadel__UAEXH_Z(undefined4 param_1)

{
  int *in_ECX;
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  piVar2 = in_ECX + 0xd;
  iVar1 = 6;
  do {
    if ((int *)*piVar2 != (int *)0x0) {
      (**(code **)(*(int *)*piVar2 + 0xc))(param_1);
    }
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  piVar2 = (int *)in_ECX[0x1f];
  if (piVar2 != (int *)0x0) {
    iVar1 = *piVar2;
    while (iVar1 != 0) {
      FUN_0044e5b0(piVar2);
      iVar1 = *piVar2;
    }
    piVar2[1] = 0;
    FUN_007290de(piVar2);
  }
  in_ECX[0x1f] = 0;
  piVar2 = (int *)in_ECX[0x13];
  while (piVar2 != (int *)0x0) {
    iVar1 = *piVar2;
    piVar2 = (int *)piVar2[0x21];
    (**(code **)(iVar1 + 0xc))(0);
  }
  in_ECX[0x13] = 0;
  in_ECX[0x14] = 0;
  piVar2 = (int *)in_ECX[0x15];
  while (piVar2 != (int *)0x0) {
    iVar1 = *piVar2;
    piVar2 = (int *)piVar2[0x23];
    (**(code **)(iVar1 + 0xc))(0);
  }
  in_ECX[0x15] = 0;
  in_ECX[0x16] = 0;
  piVar2 = (int *)in_ECX[0x17];
  while (piVar2 != (int *)0x0) {
    iVar1 = *piVar2;
    piVar2 = (int *)piVar2[0x11];
    (**(code **)(iVar1 + 0xc))(0);
  }
  in_ECX[0x17] = 0;
  in_ECX[0x18] = 0;
  piVar2 = (int *)in_ECX[0x19];
  while (piVar2 != (int *)0x0) {
    iVar1 = *piVar2;
    piVar2 = (int *)piVar2[0x21];
    (**(code **)(iVar1 + 0xc))(0);
  }
  in_ECX[0x19] = 0;
  in_ECX[0x1a] = 0;
  iVar1 = in_ECX[0xb];
  if ((iVar1 != 0) && (*(int **)(iVar1 + 0x260) == in_ECX)) {
    *(undefined4 *)(iVar1 + 0x260) = 0;
  }
  iVar1 = (**(code **)(*in_ECX + 0x1c))();
  if ((iVar1 != 0) && (iVar1 = FUN_005256a0(), iVar1 != 0)) {
    uVar3 = 0;
    (**(code **)(*in_ECX + 0x1c))(0);
    FUN_005f9500(uVar3);
  }
  FUN_00527750();
  _ToBeDeleted_GameThingWithPos__UAEXH_Z(param_1);
  return;
}



// ?Save@Citadel@@UAEIAAVGameOSFile@@@Z @ 0x0044f190

undefined4 _Save_Citadel__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  
  iVar1 = param_1;
  iVar2 = _Save_Container__UAEIAAVGameOSFile___Z(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0x30));
  FUN_00531ff0(in_ECX + 0x34,6);
  if (DAT_00b19ac8 != 0) {
    iVar2 = *(int *)(in_ECX + 0x50);
    param_1 = 0;
    iVar3 = FUN_0072be90((byte *)(in_ECX + 0x50),4,0);
    if (iVar3 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x50) + 4;
    for (iVar3 = FUN_0044f780(0); iVar3 != 0; iVar3 = FUN_0044f780(iVar3)) {
      param_1 = param_1 + 1;
      if (iVar2 < param_1) {
        DAT_00b19ac8 = 0;
        break;
      }
      if (DAT_00b19ac8 == 0) break;
      FUN_00531bc0(iVar3);
    }
  }
  if (DAT_00b19ac8 != 0) {
    iVar2 = *(int *)(in_ECX + 0x58);
    iVar3 = 0;
    iVar4 = FUN_0072be90((byte *)(in_ECX + 0x58),4,0);
    if (iVar4 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x58) + 4;
    for (iVar4 = FUN_0044f7f0(0); iVar4 != 0; iVar4 = FUN_0044f7f0(iVar4)) {
      iVar3 = iVar3 + 1;
      if (iVar2 < iVar3) {
        DAT_00b19ac8 = 0;
        break;
      }
      if (DAT_00b19ac8 == 0) break;
      FUN_00531bc0(iVar4);
    }
    if (DAT_00b19ac8 != 0) {
      iVar2 = *(int *)(in_ECX + 0x60);
      iVar4 = 0;
      FUN_0066ee00(in_ECX + 0x60);
      iVar3 = 0;
      while( true ) {
        if (iVar3 == 0) {
          iVar3 = *(int *)(in_ECX + 0x5c);
        }
        else {
          iVar3 = *(int *)(iVar3 + 0x44);
        }
        if (iVar3 == 0) break;
        iVar4 = iVar4 + 1;
        if (iVar2 < iVar4) {
          DAT_00b19ac8 = 0;
          break;
        }
        if (DAT_00b19ac8 == 0) goto LAB_0044f429;
        FUN_00531bc0(iVar3);
      }
      if (DAT_00b19ac8 != 0) {
        iVar2 = *(int *)(in_ECX + 0x68);
        iVar4 = 0;
        FUN_0066ee00(in_ECX + 0x68);
        iVar3 = 0;
        goto LAB_0044f372;
      }
    }
  }
LAB_0044f429:
  FUN_0066ee00(in_ECX + 0x74);
  return 1;
LAB_0044f372:
  if (iVar3 == 0) {
    iVar3 = *(int *)(in_ECX + 100);
  }
  else {
    iVar3 = *(int *)(iVar3 + 0x84);
  }
  if (iVar3 == 0) {
    if (DAT_00b19ac8 != 0) {
      iVar2 = FUN_0072be90((byte *)(in_ECX + 0x6c),4,0);
      if (iVar2 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x6c) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar2 = FUN_0072be90((byte *)(in_ECX + 0x70),4,0);
        if (iVar2 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x70) + 4;
      }
    }
    goto LAB_0044f429;
  }
  iVar4 = iVar4 + 1;
  if (iVar2 < iVar4) {
    DAT_00b19ac8 = 0;
    goto LAB_0044f429;
  }
  if (DAT_00b19ac8 == 0) goto LAB_0044f429;
  FUN_00531bc0(iVar3);
  goto LAB_0044f372;
}



// ?Load@Citadel@@UAEIAAVGameOSFile@@@Z @ 0x0044f450

undefined4 _Load_Citadel__UAEIAAVGameOSFile___Z(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  int in_stack_00005d0d;
  uint in_stack_00005d15;
  int in_stack_0000ba1e;
  uint in_stack_0000ba26;
  
  iVar2 = _Load_Container__UAEIAAVGameOSFile___Z();
  if (iVar2 == 0) {
    return 0;
  }
  FUN_00531f30();
  FUN_00532060();
  if (DAT_00b19acc != 0) {
    iVar2 = FUN_0072be50();
    if (iVar2 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (in_stack_00005d15 & 0xff) + 4;
    for (; 0 < (int)in_stack_00005d15; in_stack_00005d15 = in_stack_00005d15 - 1) {
      FUN_00531f30();
      *(undefined4 *)(in_stack_00005d0d + 0x84) = 0;
      FUN_0044f730();
    }
    if (DAT_00b19acc != 0) {
      iVar2 = FUN_0072be50();
      if (iVar2 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (in_stack_0000ba26 & 0xff) + 4;
      for (; 0 < (int)in_stack_0000ba26; in_stack_0000ba26 = in_stack_0000ba26 - 1) {
        FUN_00531f30();
        *(undefined4 *)(in_stack_0000ba1e + 0x8c) = 0;
        FUN_0044f7a0();
      }
      if (DAT_00b19acc != 0) {
        FUN_00589540();
        for (; 0 < (int)in_stack_0000ba26; in_stack_0000ba26 = in_stack_0000ba26 - 1) {
          FUN_00531f30();
          *(undefined4 *)(in_stack_0000ba1e + 0x44) = 0;
          FUN_0055ca90();
        }
        if (DAT_00b19acc != 0) {
          FUN_00589540();
          for (; 0 < (int)in_stack_0000ba26; in_stack_0000ba26 = in_stack_0000ba26 - 1) {
            FUN_00531f30();
            *(undefined4 *)(in_stack_0000ba1e + 0x84) = 0;
            FUN_0044f730();
          }
        }
      }
    }
  }
  if (DAT_00b19acc != 0) {
    iVar2 = FUN_0072be50();
    if (iVar2 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x6c) + 4;
  }
  if (DAT_00b19acc != 0) {
    iVar2 = FUN_0072be50();
    if (iVar2 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x70) + 4;
  }
  if (DAT_00b19acc != 0) {
    iVar2 = FUN_0072be50();
    if (iVar2 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x74) + 4;
  }
  piVar1 = *(int **)(in_ECX + 0x7c);
  if (piVar1 != (int *)0x0) {
    iVar2 = *piVar1;
    while (iVar2 != 0) {
      FUN_0044e5b0();
      iVar2 = *piVar1;
    }
    piVar1[1] = 0;
    FUN_007290de();
  }
  puVar3 = (undefined4 *)FUN_00746d70();
  if (puVar3 == (undefined4 *)0x0) {
    *(undefined4 *)(in_ECX + 0x7c) = 0;
    return 1;
  }
  *puVar3 = 0;
  puVar3[1] = 0;
  *(undefined4 **)(in_ECX + 0x7c) = puVar3;
  return 1;
}



