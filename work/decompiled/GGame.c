// Decompiled functions for class: GGame
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetSaveType@GGame@@UAEIXZ @ 0x0051ec60

undefined4 _GetSaveType_GGame__UAEIXZ(void)

{
  return 0x6a;
}



// ?GetDebugText@GGame@@UAEPADXZ @ 0x0051ec70

char * _GetDebugText_GGame__UAEPADXZ(void)

{
  return s_Game__00b1951c;
}



// ?ToBeDeleted@GGame@@UAEXH@Z @ 0x0051f230

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void _ToBeDeleted_GGame__UAEXH_Z(void)

{
  int iVar1;
  int in_ECX;
  
  FUN_004ed1f0();
  if (*(int **)(in_ECX + 0x24c120) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x24c120) + 4))(1);
  }
  if (*(int **)(in_ECX + 0x24c124) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x24c124) + 4))(1);
  }
  if (*(int **)(in_ECX + 0x24c128) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x24c128) + 4))(1);
  }
  FUN_007290de(*(undefined4 *)(in_ECX + 0x24c12c));
  if (*(int **)(in_ECX + 0x24c13c) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x24c13c) + 4))(1);
  }
  if (*(int **)(in_ECX + 0x24c114) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x24c114) + 4))(1);
  }
  FUN_00734f30(*(undefined4 *)(in_ECX + 0x24c37c));
  FUN_00734f30(*(undefined4 *)(in_ECX + 0x24c380));
  FUN_00734f30(*(undefined4 *)(in_ECX + 0x24c384));
  FUN_00734f30(*(undefined4 *)(in_ECX + 0x24c388));
  FUN_00734f30(*(undefined4 *)(in_ECX + 0x24c38c));
  FUN_00734f30(*(undefined4 *)(in_ECX + 0x24c390));
  FUN_007c0540();
  _DAT_00d5c41c = 0;
  _DAT_00d5c420 = 0;
  FUN_00454a20();
  FUN_0079b5c0();
  FUN_0051dd60(1);
  FUN_00788470(FUN_0079b770,0);
  FUN_0079b5e0();
  (*(code *)0x4ac31f4)(&DAT_00bf4e40);
  (*(code *)0x4ab23ee)(&DAT_00bf4e40);
  (*(code *)0x4ab836d)(&DAT_00e16358);
  (*(code *)0x4ab836d)(&DAT_00bf4e40);
  iVar1 = *(int *)(in_ECX + 0x24c140);
  *(byte *)(in_ECX + 10) = *(byte *)(in_ECX + 10) | 1;
  if (iVar1 != 0) {
    FUN_00585f70();
    FUN_007290de(iVar1);
  }
  iVar1 = *(int *)(in_ECX + 0x24c224);
  if (iVar1 != 0) {
    FUN_00456750();
    FUN_0072bc20();
    FUN_007290de(iVar1);
    *(undefined4 *)(in_ECX + 0x24c224) = 0;
  }
  return;
}



// ?Dump@GGame@@UAEXXZ @ 0x005234c0

void _Dump_GGame__UAEXXZ(void)

{
  int *piVar1;
  int in_ECX;
  uint uVar2;
  
  uVar2 = 0;
  do {
    piVar1 = (int *)FUN_00523640(uVar2);
    (**(code **)(*piVar1 + 0x18))();
    uVar2 = uVar2 + 1;
  } while (uVar2 < 8);
  (**(code **)(*(int *)(in_ECX + 0x1a74) + 0x18))();
  (**(code **)(*(int *)(in_ECX + 0x201c60) + 0x18))();
  return;
}



// ?Load@GGame@@UAEIAAVGameOSFile@@@Z @ 0x00526db0

undefined4 _Load_GGame__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint in_stack_0001160f;
  uint uStack_120;
  
  iVar1 = FUN_0053e9f0();
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      FUN_00589540();
      uVar3 = 0;
      if (uStack_120 != 0) {
        do {
          FUN_00604170();
          uVar3 = uVar3 + 1;
        } while (uVar3 < uStack_120);
      }
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x14) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x201ac4) + 4;
    }
    iVar1 = 8;
    do {
      FUN_00531f30();
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    func_0x00533310();
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x201b15) + 1;
      if (DAT_00b19acc != 0) {
        iVar1 = FUN_0072be50();
        if (iVar1 == 3) {
          DAT_00b19acc = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + DAT_00c22dbc + 1;
      }
    }
    *(undefined1 *)(in_ECX + 0x201b17) = 7;
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x201b18) + 1;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x201c5c) + 4;
    }
    func_0x0055ac40();
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x201df0) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x24c5e8) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x24c5ec) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x24c134) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x24c130) + 4;
      if (DAT_00b19acc != 0) {
        iVar1 = FUN_0072be50();
        if (iVar1 == 3) {
          DAT_00b19acc = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (in_stack_0001160f & 0xff) + 4;
      }
    }
    FUN_00528f20();
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (DAT_00c22d80 & 0xff) + 4;
      if (DAT_00b19acc != 0) {
        iVar1 = FUN_0072be50();
        if (iVar1 == 3) {
          DAT_00b19acc = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (DAT_00c22d84 & 0xff) + 4;
        if (DAT_00b19acc != 0) {
          iVar1 = FUN_0072be50();
          if (iVar1 == 3) {
            DAT_00b19acc = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (DAT_00c22d88 & 0xff) + 4;
          if (DAT_00b19acc != 0) {
            iVar1 = FUN_0072be50();
            if (iVar1 == 3) {
              DAT_00b19acc = 0;
            }
            *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (DAT_00c22d7c & 0xff) + 4;
          }
        }
      }
    }
    FUN_00528f60();
    FUN_00528f70();
    FUN_006cb000();
    FUN_006b4bf0();
    FUN_004402a0();
    FUN_005bf830();
    FUN_006b4b10();
    iVar1 = *(int *)(in_ECX + 0x24c128);
    *(undefined1 *)(iVar1 + 0xc88) = 0;
    *(undefined1 *)(iVar1 + 0xc90) = 0;
    *(undefined4 *)(iVar1 + 0xc8c) = 0;
    puVar4 = (undefined4 *)(iVar1 + 8);
    for (iVar2 = 800; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    FUN_00588c30();
    func_0x00586260();
    func_0x00686a00();
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x24c148) + 0xc;
    }
    FUN_00531f30();
    FUN_00531f30();
    func_0x00442410();
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (DAT_008fc59c & 0xff) + 4;
      if (DAT_00b19acc != 0) {
        iVar1 = FUN_0072be50();
        if (iVar1 == 3) {
          DAT_00b19acc = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (DAT_008fc594 & 0xff) + 4;
        if (DAT_00b19acc != 0) {
          iVar1 = FUN_0072be50();
          if (iVar1 == 3) {
            DAT_00b19acc = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (DAT_008fc598 & 0xff) + 4;
          if (DAT_00b19acc != 0) {
            iVar1 = FUN_0072be50();
            if (iVar1 == 3) {
              DAT_00b19acc = 0;
            }
            *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (DAT_00cb7008 & 0xff) + 4;
          }
        }
      }
    }
    FUN_007bf5d0();
    iVar1 = 0;
    if (DAT_00ec1778 == 0) {
      iVar1 = FUN_00746d70();
      FUN_007bf9d0();
    }
    FUN_005027e0();
    FUN_005027e0();
    FUN_00589540();
    FUN_00589540();
    if (iVar1 != 0) {
      FUN_007bfab0();
      FUN_007290de();
    }
    FUN_00528c20();
    DAT_00e08190 = 0;
    DAT_00e08194 = 0;
    FUN_00589540();
    FUN_00604170();
    FUN_00589540();
    FUN_00589540();
    FUN_00589540();
    FUN_00589540();
    DAT_00c22dc0 = *(undefined4 *)(DAT_00c22ca4 + 0x201afc);
    *(undefined4 *)(in_ECX + 0x201ad8) = *(undefined4 *)(DAT_00c22ca4 + 0x201afc);
    FUN_00589540();
    FUN_00432f50();
    FUN_005a2530();
    iVar1 = FUN_00527d30();
    if (*(int *)(iVar1 + 0x3a0) != 0) {
      FUN_004596e0();
    }
    (**(code **)(*DAT_00bf4e68 + 0xe8))();
    FUN_00589540();
    FUN_00725db0();
    FUN_00714710();
    FUN_0070c840();
    return 1;
  }
  return 0;
}



// ?ResolveLoad@GGame@@UAEXXZ @ 0x005275b0

void _ResolveLoad_GGame__UAEXXZ(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_00527d30();
  if (*(int *)(iVar1 + 0x3a0) != 0) {
    FUN_00459aa0();
  }
  *(undefined4 *)(in_ECX + 0x24c5ec) = 0;
  *(int *)(in_ECX + 0x24c5e8) = *(int *)(in_ECX + 0x201afc) * 100;
  DAT_00dc8d20 = 0;
  *(undefined4 *)(in_ECX + 0x201e04) = *(undefined4 *)(in_ECX + 0x24c5ec);
  *(undefined4 *)(in_ECX + 0x201e20) = 0;
  FUN_005a2410();
  thunk_FUN_00589350();
  return;
}



