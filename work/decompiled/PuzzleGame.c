// Decompiled functions for class: PuzzleGame
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetText@PuzzleGame@@UAEPBDXZ @ 0x00531950

char * _GetText_PuzzleGame__UAEPBDXZ(void)

{
  return s_PuzzleGame_00b1b3e4;
}



// ?GetSaveType@PuzzleGame@@UAEIXZ @ 0x00531960

undefined4 _GetSaveType_PuzzleGame__UAEIXZ(void)

{
  return 0x2c;
}



// ?GetDebugText@PuzzleGame@@UAEPADXZ @ 0x00531970

char * _GetDebugText_PuzzleGame__UAEPADXZ(void)

{
  return s_PuzzleGame__00b1b3f0;
}



// ?ToBeDeleted@PuzzleGame@@UAEXH@Z @ 0x00675340

void _ToBeDeleted_PuzzleGame__UAEXH_Z(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int in_ECX;
  int *piVar5;
  int iVar6;
  int *piVar7;
  
  iVar6 = *(int *)(in_ECX + 0x408);
  if (iVar6 != 0) {
    iVar1 = *(int *)(iVar6 + 0x28);
    if (iVar1 != 0) {
      FUN_007835d0();
      FUN_007290de(iVar1);
    }
    FUN_007290de(iVar6);
    *(undefined4 *)(in_ECX + 0x408) = 0;
  }
  piVar5 = *(int **)(in_ECX + 0x404);
  if (piVar5 != (int *)0x0) {
    if (DAT_00dd8854 == piVar5) {
      DAT_00dd8854 = (int *)piVar5[0x18];
    }
    else {
      piVar4 = (int *)DAT_00dd8854[0x18];
      piVar7 = DAT_00dd8854;
      while (piVar3 = piVar4, piVar3 != piVar5) {
        piVar7 = piVar3;
        piVar4 = (int *)piVar3[0x18];
      }
      piVar7[0x18] = piVar5[0x18];
    }
    iVar6 = 0xf;
    piVar7 = piVar5;
    do {
      if (*piVar7 != 0) {
        FUN_006754c0(1);
      }
      *piVar7 = 0;
      piVar7 = piVar7 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    FUN_007290de(piVar5);
    *(undefined4 *)(in_ECX + 0x404) = 0;
  }
  piVar5 = *(int **)(in_ECX + 0x400);
  if (piVar5 != (int *)0x0) {
    if (DAT_00dd8854 == piVar5) {
      DAT_00dd8854 = (int *)piVar5[0x18];
    }
    else {
      piVar4 = (int *)DAT_00dd8854[0x18];
      piVar7 = DAT_00dd8854;
      while (piVar3 = piVar4, piVar3 != piVar5) {
        piVar7 = piVar3;
        piVar4 = (int *)piVar3[0x18];
      }
      piVar7[0x18] = piVar5[0x18];
    }
    iVar6 = 0xf;
    piVar7 = piVar5;
    do {
      if (*piVar7 != 0) {
        FUN_006754c0(1);
      }
      *piVar7 = 0;
      piVar7 = piVar7 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
    FUN_007290de(piVar5);
    *(undefined4 *)(in_ECX + 0x400) = 0;
  }
  if (*(int *)(in_ECX + 0x48) == 3) {
    piVar5 = (int *)(in_ECX + 0x3bc);
    iVar6 = 4;
    do {
      if (*piVar5 != 0) {
        *(undefined4 *)(*piVar5 + 0x7c) = 0;
      }
      piVar5 = piVar5 + 1;
      iVar6 = iVar6 + -1;
    } while (iVar6 != 0);
  }
  iVar1 = DAT_00c22ca4;
  iVar6 = *(int *)(DAT_00c22ca4 + 0x201dd0);
  if (iVar6 == in_ECX) {
    *(int *)(DAT_00c22ca4 + 0x201dd0) = *(int *)(in_ECX + 0x2c);
  }
  else {
    if (iVar6 == 0) goto LAB_006754aa;
    while (iVar2 = *(int *)(iVar6 + 0x2c), iVar2 != in_ECX) {
      iVar6 = iVar2;
      if (iVar2 == 0) {
        _ToBeDeleted_GameThingWithPos__UAEXH_Z(param_1);
        return;
      }
    }
    *(undefined4 *)(iVar6 + 0x2c) = *(undefined4 *)(in_ECX + 0x2c);
  }
  *(int *)(iVar1 + 0x201dd4) = *(int *)(iVar1 + 0x201dd4) + -1;
  *(undefined4 *)(in_ECX + 0x2c) = 0;
LAB_006754aa:
  _ToBeDeleted_GameThingWithPos__UAEXH_Z(param_1);
  return;
}



// ?Save@PuzzleGame@@UAEIAAVGameOSFile@@@Z @ 0x006779f0

undefined4 _Save_PuzzleGame__UAEIAAVGameOSFile___Z(uint param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  byte *pbVar5;
  undefined4 *puVar6;
  int iStack_8;
  
  iVar1 = param_1;
  iVar2 = _Save_GameThingWithPos__UAEXPAUGameOSFile___Z(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  uVar4 = 0;
  if (DAT_00b19ac8 != 0) {
    iVar2 = FUN_0072be90((byte *)(in_ECX + 0x48),4,0);
    if (iVar2 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x48) + 4;
    if (DAT_00b19ac8 != 0) {
      iVar2 = FUN_0072be90((byte *)(in_ECX + 0x57c),4,0);
      if (iVar2 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x57c) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar2 = FUN_0072be90((byte *)(in_ECX + 0x584),4,0);
        if (iVar2 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x584) + 4;
        if (DAT_00b19ac8 != 0) {
          iVar2 = FUN_0072be90((byte *)(in_ECX + 0x580),4,0);
          if (iVar2 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x580) + 4;
        }
      }
    }
  }
  param_1 = 6;
  if (DAT_00b19ac8 != 0) {
    FUN_0066ee00(&param_1);
    if (param_1 != 0) {
      iVar2 = in_ECX + 0x3cc;
      do {
        FUN_0066ee00(iVar2);
        if (DAT_00b19ac8 == 0) break;
        uVar4 = uVar4 + 1;
        iVar2 = iVar2 + 4;
      } while (uVar4 < param_1);
    }
  }
  FUN_00531ff0(in_ECX + 0x398,6);
  FUN_00531ff0(in_ECX + 0xc4,4);
  FUN_00531ff0(in_ECX + 0xd4,4);
  puVar6 = (undefined4 *)(in_ECX + 0x3b0);
  iVar2 = 3;
  do {
    FUN_00531bc0(*puVar6);
    puVar6 = puVar6 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  puVar6 = (undefined4 *)(in_ECX + 0x3bc);
  iVar2 = 4;
  do {
    FUN_00531bc0(*puVar6);
    puVar6 = puVar6 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  param_1 = in_ECX + 0x4c;
  puVar6 = (undefined4 *)(in_ECX + 0x7c);
  iStack_8 = 3;
  do {
    iVar2 = 0;
    do {
      if (DAT_00b19ac8 != 0) {
        pbVar5 = (byte *)(param_1 + iVar2);
        iVar3 = FUN_0072be90(pbVar5,1,0);
        if (iVar3 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *pbVar5 + 1;
      }
      FUN_00531bc0(puVar6[-9]);
      FUN_00531bc0(*puVar6);
      FUN_00531bc0(puVar6[9]);
      iVar2 = iVar2 + 1;
      puVar6 = puVar6 + 1;
    } while (iVar2 < 3);
    param_1 = param_1 + 3;
    iStack_8 = iStack_8 + -1;
  } while (iStack_8 != 0);
  param_1 = 0;
  pbVar5 = (byte *)(in_ECX + 0x450);
  puVar6 = (undefined4 *)(in_ECX + 0x240);
  do {
    iStack_8 = 9;
    do {
      FUN_00531bc0(*puVar6);
      FUN_00531bc0(*puVar6);
      puVar6 = puVar6 + 1;
      iStack_8 = iStack_8 + -1;
    } while (iStack_8 != 0);
    if ((int)param_1 < 8) {
      FUN_00531bc0(*(undefined4 *)(pbVar5 + -0x40));
      FUN_00531bc0(*(undefined4 *)(pbVar5 + -0x20));
      if (DAT_00b19ac8 != 0) {
        iVar2 = FUN_0072be90(pbVar5,4,0);
        if (iVar2 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *pbVar5 + 4;
        if (DAT_00b19ac8 != 0) {
          iVar2 = FUN_0072be90(pbVar5 + 0x20,4,0);
          if (iVar2 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + pbVar5[0x20] + 4;
        }
      }
    }
    param_1 = param_1 + 1;
    pbVar5 = pbVar5 + 4;
  } while ((int)param_1 < 9);
  puVar6 = (undefined4 *)(in_ECX + 0x4e4);
  iVar2 = 0x12;
  do {
    FUN_00531bc0(*puVar6);
    puVar6 = puVar6 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_00531ff0(in_ECX + 0x494,0x14);
  if (DAT_00b19ac8 != 0) {
    iVar2 = FUN_0072be90((byte *)(in_ECX + 0x490),4,0);
    if (iVar2 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x490) + 4;
    if (DAT_00b19ac8 != 0) {
      iVar2 = FUN_0072be90((byte *)(in_ECX + 0x388),4,0);
      if (iVar2 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x388) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar2 = FUN_0072be90((byte *)(in_ECX + 0x38c),2,0);
        if (iVar2 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x38c) + 2;
        if (DAT_00b19ac8 != 0) {
          iVar2 = FUN_0072be90((byte *)(in_ECX + 0x390),4,0);
          if (iVar2 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x390) + 4;
          if (DAT_00b19ac8 != 0) {
            iVar2 = FUN_0072be90((byte *)(in_ECX + 0x394),4,0);
            if (iVar2 == 3) {
              DAT_00b19ac8 = 0;
            }
            *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x394) + 4;
            if (DAT_00b19ac8 != 0) {
              iVar2 = FUN_0072be90((byte *)(in_ECX + 0x3e4),4,0);
              if (iVar2 == 3) {
                DAT_00b19ac8 = 0;
              }
              *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x3e4) + 4;
              if (DAT_00b19ac8 != 0) {
                iVar2 = FUN_0072be90((byte *)(in_ECX + 1000),4,0);
                if (iVar2 == 3) {
                  DAT_00b19ac8 = 0;
                }
                *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 1000) + 4;
                if (DAT_00b19ac8 != 0) {
                  iVar2 = FUN_0072be90((byte *)(in_ECX + 0x3ec),4,0);
                  if (iVar2 == 3) {
                    DAT_00b19ac8 = 0;
                  }
                  *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x3ec) + 4
                  ;
                  if (DAT_00b19ac8 != 0) {
                    iVar2 = FUN_0072be90((byte *)(in_ECX + 0x3f0),4,0);
                    if (iVar2 == 3) {
                      DAT_00b19ac8 = 0;
                    }
                    *(uint *)(iVar1 + 0x214) =
                         *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x3f0) + 4;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0x3f4));
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0x3f8));
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0x3fc));
  FUN_00531bc0(*(undefined4 *)(in_ECX + 900));
  if (DAT_00b19ac8 != 0) {
    iVar2 = FUN_0072be90((byte *)(in_ECX + 0x3c),4,0);
    if (iVar2 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x3c) + 4;
    if (DAT_00b19ac8 != 0) {
      iVar2 = FUN_0072be90((byte *)(in_ECX + 0x44),2,0);
      if (iVar2 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x44) + 2;
      if (DAT_00b19ac8 != 0) {
        iVar2 = FUN_0072be90((byte *)(in_ECX + 0x46),2,0);
        if (iVar2 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x46) + 2;
      }
    }
  }
  return 1;
}



// ?Load@PuzzleGame@@UAEIAAVGameOSFile@@@Z @ 0x00678070

undefined4 _Load_PuzzleGame__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  int in_stack_00005d0d;
  uint in_stack_0000ba26;
  
  iVar1 = _Load_GameThingWithPos__QAEIAAVGameOSFile___Z();
  if (iVar1 == 0) {
    return 0;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x48) + 4;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x57c) + 4;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x584) + 4;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x580) + 4;
    if (DAT_00b19acc != 0) {
      FUN_00589540();
      uVar5 = 0;
      if (in_stack_0000ba26 != 0) {
        do {
          FUN_00589540();
          uVar5 = uVar5 + 1;
        } while (uVar5 < in_stack_0000ba26);
      }
    }
  }
  FUN_00532060();
  FUN_00532060();
  FUN_00532060();
  iVar1 = 3;
  do {
    FUN_00531f30();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  iVar1 = 4;
  do {
    FUN_00531f30();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  pbVar3 = (byte *)(in_ECX + 0x4c);
  iVar1 = 3;
  do {
    iVar4 = 3;
    do {
      if (DAT_00b19acc != 0) {
        iVar2 = FUN_0072be50();
        if (iVar2 == 3) {
          DAT_00b19acc = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *pbVar3 + 1;
      }
      FUN_00531f30();
      FUN_00531f30();
      FUN_00531f30();
      pbVar3 = pbVar3 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  pbVar3 = (byte *)(in_stack_00005d0d + 0x450);
  iVar1 = 0;
  do {
    iVar4 = 9;
    do {
      FUN_00531f30();
      FUN_00531f30();
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    if (iVar1 < 8) {
      FUN_00531f30();
      FUN_00531f30();
      if (DAT_00b19acc != 0) {
        iVar4 = FUN_0072be50();
        if (iVar4 == 3) {
          DAT_00b19acc = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *pbVar3 + 4;
        if (DAT_00b19acc != 0) {
          iVar4 = FUN_0072be50();
          if (iVar4 == 3) {
            DAT_00b19acc = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + pbVar3[0x20] + 4;
        }
      }
    }
    iVar1 = iVar1 + 1;
    pbVar3 = pbVar3 + 4;
  } while (iVar1 < 9);
  iVar1 = 0x12;
  do {
    FUN_00531f30();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_00532060();
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) =
         *(int *)(param_1 + 0x214) + *(byte *)(in_stack_00005d0d + 0x490) + 4;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) =
         *(int *)(param_1 + 0x214) + *(byte *)(in_stack_00005d0d + 0x388) + 4;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) =
         *(int *)(param_1 + 0x214) + *(byte *)(in_stack_00005d0d + 0x38c) + 2;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) =
         *(int *)(param_1 + 0x214) + *(byte *)(in_stack_00005d0d + 0x390) + 4;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) =
         *(int *)(param_1 + 0x214) + *(byte *)(in_stack_00005d0d + 0x394) + 4;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) =
         *(int *)(param_1 + 0x214) + *(byte *)(in_stack_00005d0d + 0x3e4) + 4;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_stack_00005d0d + 1000) + 4
    ;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) =
         *(int *)(param_1 + 0x214) + *(byte *)(in_stack_00005d0d + 0x3ec) + 4;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) =
         *(int *)(param_1 + 0x214) + *(byte *)(in_stack_00005d0d + 0x3f0) + 4;
  }
  FUN_00531f30();
  FUN_00531f30();
  FUN_00531f30();
  FUN_00531f30();
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_stack_00005d0d + 0x3c) + 4
    ;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_stack_00005d0d + 0x44) + 2
    ;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_stack_00005d0d + 0x46) + 2
    ;
  }
  return 1;
}



