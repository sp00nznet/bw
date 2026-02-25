// Decompiled functions for class: DanceGroup
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetSaveType@DanceGroup@@UAEIXZ @ 0x004eb0f0

undefined4 _GetSaveType_DanceGroup__UAEIXZ(void)

{
  return 0x7b;
}



// ?GetDebugText@DanceGroup@@UAEPADXZ @ 0x004eb100

char * _GetDebugText_DanceGroup__UAEPADXZ(void)

{
  return s_DanceGroup__00b16010;
}



// ?Save@DanceGroup@@UAEIAAVGameOSFile@@@Z @ 0x004eb810

undefined4 _Save_DanceGroup__UAEIAAVGameOSFile___Z(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  
  iVar2 = FUN_0053e8e0(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0x14));
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0x18));
  if (DAT_00b19ac8 != 0) {
    iVar2 = *(int *)(in_ECX + 0x20);
    iVar3 = 0;
    FUN_0066ee00(in_ECX + 0x20);
    for (puVar1 = *(undefined4 **)(in_ECX + 0x1c); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      iVar3 = iVar3 + 1;
      if (iVar2 < iVar3) goto LAB_004eb8a0;
      if (DAT_00b19ac8 == 0) goto LAB_004ebaac;
      FUN_00531bc0(puVar1[1]);
    }
    if (DAT_00b19ac8 != 0) {
      if (iVar3 == iVar2) {
        iVar2 = FUN_0072be90((byte *)(in_ECX + 0x24),4,0);
        if (iVar2 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x24) + 4;
        if (DAT_00b19ac8 != 0) {
          iVar2 = FUN_0072be90((byte *)(in_ECX + 0x3c),4,0);
          if (iVar2 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x3c) + 4;
          if (DAT_00b19ac8 != 0) {
            iVar2 = FUN_0072be90((byte *)(in_ECX + 0x40),4,0);
            if (iVar2 == 3) {
              DAT_00b19ac8 = 0;
            }
            *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x40) + 4;
            if (DAT_00b19ac8 != 0) {
              iVar2 = FUN_0072be90((byte *)(in_ECX + 0x44),4,0);
              if (iVar2 == 3) {
                DAT_00b19ac8 = 0;
              }
              *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x44) + 4;
              if (DAT_00b19ac8 != 0) {
                iVar2 = FUN_0072be90((byte *)(in_ECX + 0x48),8,0);
                if (iVar2 == 3) {
                  DAT_00b19ac8 = 0;
                }
                *(uint *)(param_1 + 0x214) =
                     *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x48) + 8;
                if (DAT_00b19ac8 != 0) {
                  iVar2 = FUN_0072be90((byte *)(in_ECX + 0x50),4,0);
                  if (iVar2 == 3) {
                    DAT_00b19ac8 = 0;
                  }
                  *(uint *)(param_1 + 0x214) =
                       *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x50) + 4;
                  if (DAT_00b19ac8 != 0) {
                    iVar2 = FUN_0072be90((byte *)(in_ECX + 0x54),4,0);
                    if (iVar2 == 3) {
                      DAT_00b19ac8 = 0;
                    }
                    *(uint *)(param_1 + 0x214) =
                         *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x54) + 4;
                    if (DAT_00b19ac8 != 0) {
                      iVar2 = FUN_0072be90((byte *)(in_ECX + 0x58),4,0);
                      if (iVar2 == 3) {
                        DAT_00b19ac8 = 0;
                      }
                      *(uint *)(param_1 + 0x214) =
                           *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x58) + 4;
                      if (DAT_00b19ac8 != 0) {
                        iVar2 = FUN_0072be90((byte *)(in_ECX + 0x5c),0x10,0);
                        if (iVar2 == 3) {
                          DAT_00b19ac8 = 0;
                        }
                        *(uint *)(param_1 + 0x214) =
                             *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x5c) + 0x10;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else {
LAB_004eb8a0:
        DAT_00b19ac8 = 0;
      }
    }
  }
LAB_004ebaac:
  FUN_0066ee00(in_ECX + 0x6c);
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0x70));
  FUN_00604120(in_ECX + 0x74);
  FUN_0066ee00(in_ECX + 0x78);
  FUN_0066ee00(in_ECX + 0x7c);
  FUN_0066ee00(in_ECX + 0x80);
  FUN_0066ee00(in_ECX + 0x84);
  FUN_004ebf70(in_ECX + 0x88);
  FUN_004ebf70(in_ECX + 0x94);
  FUN_0066ee00(in_ECX + 0xa0);
  FUN_0066ee00(in_ECX + 0xa4);
  FUN_004ebf20(in_ECX + 0xa8);
  FUN_004ebf70(in_ECX + 0xe8);
  FUN_004ebfc0(in_ECX + 0xf4);
  FUN_0066ee00(in_ECX + 0x178);
  return 1;
}



// ?Load@DanceGroup@@UAEIAAVGameOSFile@@@Z @ 0x004ebb90

undefined4 _Load_DanceGroup__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  int iStack_4;
  
  iVar1 = param_1;
  iStack_4 = in_ECX;
  iVar2 = FUN_0053e9f0(param_1);
  if (iVar2 != 0) {
    FUN_00531f30(in_ECX + 0x14);
    FUN_00531f30(in_ECX + 0x18);
    if (DAT_00b19acc != 0) {
      FUN_00589540(&param_1);
      for (; 0 < param_1; param_1 = param_1 + -1) {
        FUN_00531f30(&iStack_4);
        FUN_006d5810(iStack_4);
      }
    }
    if (DAT_00b19acc != 0) {
      iVar2 = FUN_0072be50((byte *)(in_ECX + 0x24),4,0,unaff_EBP,unaff_EBX,unaff_EDI,unaff_ESI);
      if (iVar2 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x24) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar2 = FUN_0072be50();
      if (iVar2 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x3c) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar2 = FUN_0072be50();
      if (iVar2 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x40) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar2 = FUN_0072be50();
      if (iVar2 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x44) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar2 = FUN_0072be50();
      if (iVar2 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x48) + 8;
    }
    if (DAT_00b19acc != 0) {
      iVar2 = FUN_0072be50();
      if (iVar2 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x50) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar2 = FUN_0072be50();
      if (iVar2 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x54) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar2 = FUN_0072be50();
      if (iVar2 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x58) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar2 = FUN_0072be50();
      if (iVar2 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x5c) + 0x10;
    }
    if (DAT_00b19acc != 0) {
      iVar2 = FUN_0072be50();
      if (iVar2 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x6c) + 4;
    }
    FUN_00531f30();
    if (DAT_00b19acc != 0) {
      iVar2 = FUN_0072be50();
      if (iVar2 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x74) + 1;
    }
    FUN_00589540();
    FUN_00589540();
    FUN_00589540();
    FUN_00589540();
    FUN_004ec100();
    FUN_004ec100();
    FUN_00589540();
    FUN_00589540();
    FUN_004ec0b0();
    FUN_004ec100();
    FUN_004ec150();
    FUN_00589540();
    return 1;
  }
  return 0;
}



