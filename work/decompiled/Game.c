// Decompiled functions for class: Game
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Save@Game@@QAEIAAVGGameOSFile@@@Z @ 0x00526660

undefined4 _Save_Game__QAEIAAVGGameOSFile___Z(uint param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  float10 fVar7;
  uint uStack_8;
  float fStack_4;
  
  iVar2 = param_1;
  iVar3 = FUN_0053e8e0(param_1);
  if (iVar3 == 0) {
    return 0;
  }
  param_1 = 0xffffffff;
  pcVar5 = s__Revision__756___00b19a3c;
  do {
    if (param_1 == 0) break;
    param_1 = param_1 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  param_1 = ~param_1;
  if (DAT_00b19ac8 != 0) {
    FUN_0066ee00(&param_1);
    uVar6 = 0;
    if (param_1 != 0) {
      do {
        FUN_00604120(s__Revision__756___00b19a3c + uVar6);
        if (DAT_00b19ac8 == 0) goto LAB_00526740;
        uVar6 = uVar6 + 1;
      } while (uVar6 < param_1);
    }
    if (DAT_00b19ac8 != 0) {
      iVar3 = FUN_0072be90((byte *)(in_ECX + 0x14),4,0);
      if (iVar3 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + *(byte *)(in_ECX + 0x14) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar3 = FUN_0072be90((byte *)(in_ECX + 0x201ac4),4,0);
        if (iVar3 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + *(byte *)(in_ECX + 0x201ac4) + 4;
      }
    }
  }
LAB_00526740:
  iVar3 = in_ECX + 0x18;
  iVar4 = 8;
  do {
    FUN_00531bc0(iVar3);
    iVar3 = iVar3 + 0x278;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  FUN_00533130(in_ECX + 0x201aec);
  if (DAT_00b19ac8 != 0) {
    iVar3 = FUN_0072be90((byte *)(in_ECX + 0x201b15),1,0);
    if (iVar3 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + *(byte *)(in_ECX + 0x201b15) + 1;
  }
  uVar6 = uStack_8;
  uStack_8 = uStack_8 & 0xffffff00;
  iVar3 = *(int *)(in_ECX + 0x27c + (uint)*(byte *)(in_ECX + 0x201b15) * 0x278);
  if (iVar3 != 0) {
    uStack_8 = CONCAT31(SUB43(uVar6,1),
                        (*(char *)(iVar3 + 0x1114) * '\x02' + *(char *)(iVar3 + 0x1110)) * '\x02' +
                        *(char *)(iVar3 + 0x110c));
  }
  if (DAT_00b19ac8 != 0) {
    iVar3 = FUN_0072be90(&uStack_8,1,0);
    if (iVar3 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + (uStack_8 & 0xff) + 1;
    if (DAT_00b19ac8 != 0) {
      iVar3 = FUN_0072be90((byte *)(in_ECX + 0x201b18),1,0);
      if (iVar3 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + *(byte *)(in_ECX + 0x201b18) + 1;
      if (DAT_00b19ac8 != 0) {
        iVar3 = FUN_0072be90((byte *)(in_ECX + 0x201c5c),4,0);
        if (iVar3 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + *(byte *)(in_ECX + 0x201c5c) + 4;
      }
    }
  }
  FUN_0055a6c0(iVar2);
  if (DAT_00b19ac8 != 0) {
    iVar3 = FUN_0072be90((byte *)(in_ECX + 0x201df0),4,0);
    if (iVar3 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + *(byte *)(in_ECX + 0x201df0) + 4;
    if (DAT_00b19ac8 != 0) {
      iVar3 = FUN_0072be90((byte *)(in_ECX + 0x24c5e8),4,0);
      if (iVar3 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + *(byte *)(in_ECX + 0x24c5e8) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar3 = FUN_0072be90((byte *)(in_ECX + 0x24c5ec),4,0);
        if (iVar3 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + *(byte *)(in_ECX + 0x24c5ec) + 4;
        if (DAT_00b19ac8 != 0) {
          iVar3 = FUN_0072be90((byte *)(in_ECX + 0x24c134),4,0);
          if (iVar3 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + *(byte *)(in_ECX + 0x24c134) + 4;
          if (DAT_00b19ac8 != 0) {
            iVar3 = FUN_0072be90((byte *)(in_ECX + 0x24c130),4,0);
            if (iVar3 == 3) {
              DAT_00b19ac8 = 0;
            }
            *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + *(byte *)(in_ECX + 0x24c130) + 4;
          }
        }
      }
    }
  }
  fVar7 = (float10)FUN_00528ef0();
  fStack_4 = (float)fVar7;
  if (DAT_00b19ac8 != 0) {
    iVar3 = FUN_0072be90(&fStack_4,4,0);
    if (iVar3 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + ((uint)fStack_4 & 0xff) + 4;
    if (DAT_00b19ac8 != 0) {
      iVar3 = FUN_0072be90(&DAT_00c22d80,4,0);
      if (iVar3 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + (DAT_00c22d80 & 0xff) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar3 = FUN_0072be90(&DAT_00c22d84,4,0);
        if (iVar3 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + (DAT_00c22d84 & 0xff) + 4;
        if (DAT_00b19ac8 != 0) {
          iVar3 = FUN_0072be90(&DAT_00c22d88,4,0);
          if (iVar3 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + (DAT_00c22d88 & 0xff) + 4;
          if (DAT_00b19ac8 != 0) {
            iVar3 = FUN_0072be90(&DAT_00c22d7c,4,0);
            if (iVar3 == 3) {
              DAT_00b19ac8 = 0;
            }
            *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + (DAT_00c22d7c & 0xff) + 4;
          }
        }
      }
    }
  }
  FUN_00588700(iVar2);
  FUN_00586250(iVar2);
  FUN_00686630(iVar2);
  if (DAT_00b19ac8 != 0) {
    iVar3 = FUN_0072be90((byte *)(in_ECX + 0x24c148),0xc,0);
    if (iVar3 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + *(byte *)(in_ECX + 0x24c148) + 0xc;
  }
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0x24c36c));
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0x24c5e0));
  FUN_004427c0(iVar2);
  if (DAT_00b19ac8 != 0) {
    iVar3 = FUN_0072be90(&DAT_008fc59c,4,0);
    if (iVar3 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + (DAT_008fc59c & 0xff) + 4;
    if (DAT_00b19ac8 != 0) {
      iVar3 = FUN_0072be90(&DAT_008fc594,4,0);
      if (iVar3 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + (DAT_008fc594 & 0xff) + 4;
    }
  }
  FUN_0066ee00(&DAT_008fc598);
  FUN_0066ee00(&DAT_00cb7008);
  iVar3 = 0;
  if (DAT_00ec1778 == 0) {
    iVar3 = FUN_00746d70(0x1100c,s_C__dev_black_Game_cpp_00b194a4,0x1bb9);
    FUN_007bf9d0();
  }
  FUN_005341d0(DAT_00ec1778,0x4000);
  FUN_005341d0(DAT_00ec1778 + 0x10000,0x400);
  FUN_0066ee00(DAT_00ec1778 + 0x11000);
  FUN_0066ee00(DAT_00ec1778 + 0x11004);
  if (iVar3 != 0) {
    FUN_007bfab0();
    FUN_007290de(iVar3);
  }
  FUN_00528bd0(&DAT_00e08190);
  FUN_0066ee00(in_ECX + 0x24c228);
  FUN_00604120(&DAT_00c22ce9);
  FUN_0066ee00(in_ECX + 0x201ac8);
  FUN_0066ee00(in_ECX + 0x201acc);
  FUN_0066ee00(in_ECX + 0x201ad0);
  FUN_0066ee00(&DAT_00c22dc0);
  FUN_0066ee00(in_ECX + 0x201ad4);
  FUN_00432d60(iVar2);
  FUN_005a24e0(iVar2);
  iVar3 = FUN_00527d30();
  if (*(int *)(iVar3 + 0x3a0) != 0) {
    FUN_004598c0(iVar2);
  }
  (**(code **)(*DAT_00bf4e68 + 0xec))(iVar2);
  FUN_0066ee00(&DAT_00d5ab40);
  FUN_00725c60(iVar2);
  FUN_00714430(iVar2);
  FUN_0070c7a0(iVar2);
  return 1;
}



