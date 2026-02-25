// Decompiled functions for class: GComputerPlayer
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetScriptObjectType@GComputerPlayer@@UAEIXZ @ 0x00418650

undefined4 _GetScriptObjectType_GComputerPlayer__UAEIXZ(void)

{
  return 0x26;
}



// ?GetSaveType@GComputerPlayer@@UAEIXZ @ 0x0052f2c0

undefined4 _GetSaveType_GComputerPlayer__UAEIXZ(void)

{
  return 0x66;
}



// ?GetDebugText@GComputerPlayer@@UAEPADXZ @ 0x0052f2d0

char * _GetDebugText_GComputerPlayer__UAEPADXZ(void)

{
  return s_GComputerPlayer__00b1a5ec;
}



// ?SetSpeedInMetres@GComputerPlayer@@UAEXMH@Z @ 0x0052f2e0

void _SetSpeedInMetres_GComputerPlayer__UAEXMH_Z(undefined4 param_1)

{
  FUN_006038a0(param_1);
  return;
}



// ?GetText@GComputerPlayer@@UAEPBDXZ @ 0x0052f2f0

void _GetText_GComputerPlayer__UAEPBDXZ(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0052f2f2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0xd8))();
  return;
}



// ?GetPlayer@GComputerPlayer@@UAEPAVGPlayer@@XZ @ 0x0052f300

undefined4 _GetPlayer_GComputerPlayer__UAEPAVGPlayer__XZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x28);
}



// ?ToBeDeleted@GComputerPlayer@@UAEXH@Z @ 0x006024f0

void _ToBeDeleted_GComputerPlayer__UAEXH_Z(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *in_ECX;
  int *piVar3;
  int *piVar4;
  int iVar5;
  
  iVar5 = in_ECX[0xb];
  if (iVar5 != 0) {
    FUN_00601690();
    FUN_007290de(iVar5);
    in_ECX[0xb] = 0;
  }
  if ((int *)in_ECX[0xd] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0xd] + 0xc))(param_1);
    in_ECX[0xd] = 0;
  }
  do {
    iVar5 = in_ECX[0x10];
    if (iVar5 == 0) {
      piVar3 = in_ECX + 0x76;
      iVar5 = 8;
      do {
        if ((int *)*piVar3 != (int *)0x0) {
          (**(code **)(*(int *)*piVar3 + 0xc))(0);
          *piVar3 = 0;
        }
        piVar3 = piVar3 + 1;
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
      iVar5 = (**(code **)(*in_ECX + 0x1c))();
      if (iVar5 != 0) {
        iVar5 = (**(code **)(*in_ECX + 0x1c))();
        *(undefined4 *)(iVar5 + 0x15c) = 0;
      }
      if (in_ECX[0xe] != 0) {
        piVar3 = *(int **)(in_ECX[0xe] + 4);
        while (piVar3 != (int *)0x0) {
          puVar2 = (undefined4 *)in_ECX[0xe];
          if (piVar3 != (int *)0x0) {
            do {
              if (puVar2 == (undefined4 *)0x0) goto LAB_006025bf;
              piVar4 = puVar2 + 1;
              puVar2 = (undefined4 *)*puVar2;
            } while ((int *)*piVar4 != piVar3);
          }
          if (puVar2 == (undefined4 *)0x0) {
LAB_006025bf:
            piVar4 = (int *)0x0;
          }
          else {
            piVar4 = (int *)puVar2[1];
          }
          (**(code **)(*piVar3 + 0xc))(0);
          piVar3 = piVar4;
        }
      }
      iVar5 = in_ECX[0x12];
      while (iVar5 != 0) {
        iVar1 = *(int *)(iVar5 + 0x20);
        FUN_007290de(iVar5);
        iVar5 = iVar1;
      }
      in_ECX[0x12] = 0;
      in_ECX[0x13] = 0;
      piVar3 = (int *)in_ECX[0x14];
      while (piVar4 = piVar3, piVar4 != (int *)0x0) {
        piVar3 = (int *)piVar4[0x49];
        if ((*(byte *)((int)piVar4 + 10) & 1) == 0) {
          (**(code **)(*piVar4 + 0xc))(0);
        }
      }
      in_ECX[0x14] = 0;
      in_ECX[0x15] = 0;
      _ToBeDeleted_GameThingWithPos__UAEXH_Z(param_1);
      return;
    }
    piVar3 = *(int **)(iVar5 + 4);
    (**(code **)(*piVar3 + 0xc))(0);
    for (puVar2 = (undefined4 *)in_ECX[0x10]; puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)*puVar2) {
      if ((int *)puVar2[1] == piVar3) {
        FUN_00542c40(piVar3,0);
        break;
      }
    }
  } while( true );
}



// ?Save@GComputerPlayer@@UAEIAAVGameOSFile@@@Z @ 0x00602c20

undefined4 _Save_GComputerPlayer__UAEIAAVGameOSFile___Z(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  
  iVar2 = param_1;
  iVar3 = _Save_GameThingWithPos__UAEXPAUGameOSFile___Z(param_1);
  if (iVar3 == 0) {
    return 0;
  }
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0x28));
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0x34));
  if (DAT_00b19ac8 != 0) {
    iVar3 = *(int *)(in_ECX + 0x3c);
    iVar4 = 0;
    FUN_0066ee00(in_ECX + 0x3c);
    for (puVar1 = *(undefined4 **)(in_ECX + 0x38); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      iVar4 = iVar4 + 1;
      if (iVar3 < iVar4) goto LAB_00602ca9;
      if (DAT_00b19ac8 == 0) goto LAB_00602d08;
      FUN_00531bc0(puVar1[1]);
    }
    if (DAT_00b19ac8 != 0) {
      if (iVar4 != iVar3) {
LAB_00602ca9:
        DAT_00b19ac8 = 0;
      }
      if (DAT_00b19ac8 != 0) {
        iVar3 = *(int *)(in_ECX + 0x44);
        iVar4 = 0;
        FUN_0066ee00(in_ECX + 0x44);
        for (puVar1 = *(undefined4 **)(in_ECX + 0x40); puVar1 != (undefined4 *)0x0;
            puVar1 = (undefined4 *)*puVar1) {
          iVar4 = iVar4 + 1;
          if (iVar3 < iVar4) goto LAB_00602d01;
          if (DAT_00b19ac8 == 0) goto LAB_00602d08;
          FUN_00531bc0(puVar1[1]);
        }
        if ((DAT_00b19ac8 != 0) && (iVar4 != iVar3)) {
LAB_00602d01:
          DAT_00b19ac8 = 0;
        }
      }
    }
  }
LAB_00602d08:
  if (DAT_00b19ac8 != 0) {
    iVar3 = *(int *)(in_ECX + 0x54);
    param_1 = 0;
    FUN_0066ee00(in_ECX + 0x54);
    for (iVar4 = FUN_00604210(0); iVar4 != 0; iVar4 = FUN_00604210(iVar4)) {
      param_1 = param_1 + 1;
      if (iVar3 < param_1) {
        DAT_00b19ac8 = 0;
        goto LAB_00602ec0;
      }
      if (DAT_00b19ac8 == 0) goto LAB_00602ec0;
      FUN_00531bc0(iVar4);
    }
    if (DAT_00b19ac8 != 0) {
      iVar3 = FUN_0072be90((byte *)(in_ECX + 0x58),4,0);
      if (iVar3 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + *(byte *)(in_ECX + 0x58) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar3 = FUN_0072be90((byte *)(in_ECX + 0x5c),4,0);
        if (iVar3 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + *(byte *)(in_ECX + 0x5c) + 4;
        if (DAT_00b19ac8 != 0) {
          iVar3 = FUN_0072be90((byte *)(in_ECX + 0x60),4,0);
          if (iVar3 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + *(byte *)(in_ECX + 0x60) + 4;
          if (DAT_00b19ac8 != 0) {
            iVar3 = FUN_0072be90((byte *)(in_ECX + 100),4,0);
            if (iVar3 == 3) {
              DAT_00b19ac8 = 0;
            }
            *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + *(byte *)(in_ECX + 100) + 4;
            if (DAT_00b19ac8 != 0) {
              iVar3 = FUN_0072be90(&DAT_00b24340,4,0);
              if (iVar3 == 3) {
                DAT_00b19ac8 = 0;
              }
              *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + (DAT_00b24340 & 0xff) + 4;
            }
          }
        }
      }
    }
  }
LAB_00602ec0:
  FUN_005341d0(in_ECX + 0x68,0x2a);
  if (DAT_00b19ac8 != 0) {
    iVar3 = FUN_0072be90((byte *)(in_ECX + 0x110),4,0);
    if (iVar3 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + *(byte *)(in_ECX + 0x110) + 4;
  }
  FUN_0066ee00(in_ECX + 0x1b8);
  FUN_0066ee00(in_ECX + 0x1bc);
  FUN_0066ee00(in_ECX + 0x1c0);
  FUN_00604120(in_ECX + 0x1d0);
  FUN_00531ff0(in_ECX + 0x1d8,8);
  if (*(int *)(in_ECX + 0x2c) != 0) {
    FUN_00601b90(iVar2);
  }
  return 1;
}



// ?Load@GComputerPlayer@@UAEIAAVGameOSFile@@@Z @ 0x00602f80

undefined4 _Load_GComputerPlayer__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  uint in_stack_00011737;
  
  iVar1 = _Load_GameThingWithPos__QAEIAAVGameOSFile___Z();
  if (iVar1 != 0) {
    FUN_00531f30();
    uVar2 = 0;
    *(undefined4 *)(in_ECX + 0x2c) = 0;
    FUN_00531f30();
    if (DAT_00b19acc != 0) {
      FUN_00589540();
      for (iVar1 = param_1; 0 < iVar1; iVar1 = iVar1 + -1) {
        FUN_00531f30();
        FUN_006d5810();
      }
      if (DAT_00b19acc != 0) {
        FUN_00589540();
        for (; 0 < iVar1; iVar1 = iVar1 + -1) {
          FUN_00531f30();
          FUN_006d5810();
        }
        if (DAT_00b19acc != 0) {
          FUN_00589540();
          for (; 0 < iVar1; iVar1 = iVar1 + -1) {
            FUN_00531f30();
            *(undefined4 *)(in_ECX + 0x124) = 0;
            FUN_006041c0();
          }
        }
      }
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x58) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x5c) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x60) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 100) + 4;
      if (DAT_00b19acc != 0) {
        iVar1 = FUN_0072be50();
        if (iVar1 == 3) {
          DAT_00b19acc = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (DAT_00b24340 & 0xff) + 4;
        if ((DAT_00b19acc != 0) && (FUN_00589540(), in_stack_00011737 != 0)) {
          do {
            FUN_00589540();
            uVar2 = uVar2 + 1;
          } while (uVar2 < in_stack_00011737);
        }
      }
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x110) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x1b8) + 4;
    }
    FUN_00589540();
    FUN_00589540();
    FUN_00604170();
    FUN_00532060();
    FUN_00602430();
    if (*(int *)(in_ECX + 0x2c) != 0) {
      FUN_00601c40();
    }
    return 1;
  }
  return 0;
}



// ?SaveExtraData@GComputerPlayer@@UAEXAAVGameOSFile@@@Z @ 0x006032b0

void _SaveExtraData_GComputerPlayer__UAEXAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int *in_ECX;
  uint uStack_4;
  
  (**(code **)(*in_ECX + 0x1c))();
  uStack_4 = FUN_005f7d20();
  if (DAT_00b19ac8 != 0) {
    iVar1 = FUN_0072be90(&uStack_4,4,0);
    if (iVar1 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (uStack_4 & 0xff) + 4;
  }
  return;
}



