// Decompiled functions for class: GCamera
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetText@GCamera@@UAEPBDXZ @ 0x00439a10

char * _GetText_GCamera__UAEPBDXZ(void)

{
  return s_Camera_008fc480;
}



// ?IsMoving@GCamera@@UBE_NXZ @ 0x00439a20

undefined4 _IsMoving_GCamera__UBE_NXZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x74);
}



// ?GetHeight@GCamera@@UAEMXZ @ 0x00439a30

float10 _GetHeight_GCamera__UAEMXZ(void)

{
  int in_ECX;
  
  return (float10)*(float *)(in_ECX + 0x1c);
}



// ?GetSaveType@GCamera@@UAEIXZ @ 0x00439a40

undefined4 _GetSaveType_GCamera__UAEIXZ(void)

{
  return 0x77;
}



// ?ToBeDeleted@GCamera@@UAEXH@Z @ 0x00439d10

void _ToBeDeleted_GCamera__UAEXH_Z(undefined4 param_1)

{
  int in_ECX;
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  if (-1 < *(int *)(in_ECX + 0x58)) {
    piVar1 = (int *)(in_ECX + 0x28);
    do {
      if ((undefined4 *)*piVar1 != (undefined4 *)0x0) {
        (*(code *)**(undefined4 **)*piVar1)(1);
      }
      iVar2 = iVar2 + 1;
      piVar1 = piVar1 + 1;
    } while (iVar2 <= *(int *)(in_ECX + 0x58));
  }
  _ToBeDeleted_GameThingWithPos__UAEXH_Z(param_1);
  return;
}



// ?Save@GCamera@@UAEIAAVGameOSFile@@@Z @ 0x0043ac50

undefined4 _Save_GCamera__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  FUN_0051f3d0();
  iVar1 = param_1;
  iVar2 = _Save_GameThingWithPos__UAEXPAUGameOSFile___Z(param_1);
  if (iVar2 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar2 = FUN_0072be90((byte *)(in_ECX + 0x5c),0xc,0);
      if (iVar2 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x5c) + 0xc;
      if (DAT_00b19ac8 != 0) {
        iVar2 = FUN_0072be90((byte *)(in_ECX + 0x68),4,0);
        if (iVar2 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x68) + 4;
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
            if (DAT_00b19ac8 != 0) {
              iVar2 = FUN_0072be90((byte *)(in_ECX + 0x74),4,0);
              if (iVar2 == 3) {
                DAT_00b19ac8 = 0;
              }
              *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x74) + 4;
              if (DAT_00b19ac8 != 0) {
                iVar2 = FUN_0072be90((byte *)(in_ECX + 0x80),8,0);
                if (iVar2 == 3) {
                  DAT_00b19ac8 = 0;
                }
                *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x80) + 8;
                if (DAT_00b19ac8 != 0) {
                  iVar2 = FUN_0072be90((byte *)(in_ECX + 0x88),0x90,0);
                  if (iVar2 == 3) {
                    DAT_00b19ac8 = 0;
                  }
                  *(uint *)(iVar1 + 0x214) =
                       *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x88) + 0x90;
                  if (DAT_00b19ac8 != 0) {
                    iVar2 = FUN_0072be90((byte *)(in_ECX + 0x118),0x90,0);
                    if (iVar2 == 3) {
                      DAT_00b19ac8 = 0;
                    }
                    *(uint *)(iVar1 + 0x214) =
                         *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x118) + 0x90;
                    if (DAT_00b19ac8 != 0) {
                      iVar2 = FUN_0072be90((byte *)(in_ECX + 0x1a8),0x30,0);
                      if (iVar2 == 3) {
                        DAT_00b19ac8 = 0;
                      }
                      *(uint *)(iVar1 + 0x214) =
                           *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x1a8) + 0x30;
                      if (DAT_00b19ac8 != 0) {
                        iVar2 = FUN_0072be90((byte *)(in_ECX + 0x78),1,0);
                        if (iVar2 == 3) {
                          DAT_00b19ac8 = 0;
                        }
                        *(uint *)(iVar1 + 0x214) =
                             *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x78) + 1;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    param_1 = (**(code **)(**(int **)(in_ECX + 0x28 + *(int *)(in_ECX + 0x58) * 4) + 0x38))();
    FUN_0066ee00(&param_1);
    (**(code **)(**(int **)(in_ECX + 0x28 + *(int *)(in_ECX + 0x58) * 4) + 0x40))(iVar1);
    return 1;
  }
  return 0;
}



// ?Load@GCamera@@UAEIAAVGameOSFile@@@Z @ 0x0043af10

undefined4 _Load_GCamera__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  uint in_stack_00005d15;
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
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x5c) + 0xc;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x68) + 4;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x6c) + 4;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x70) + 4;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x74) + 4;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x80) + 8;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x88) + 0x90;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x118) + 0x90;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x1a8) + 0x30;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x78) + 1;
  }
  FUN_0043ab50();
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (in_stack_0000ba26 & 0xff) + 4;
    in_stack_00005d15 = in_stack_0000ba26;
  }
  if ((in_stack_00005d15 != 0) && (piVar2 = (int *)FUN_00439570(), piVar2 != (int *)0x0)) {
    (**(code **)(*piVar2 + 0x3c))();
  }
  return 1;
}



// ?GetDebugText@GCamera@@UAEPADXZ @ 0x0043b3b0

undefined * _GetDebugText_GCamera__UAEPADXZ(void)

{
  int in_ECX;
  
  FUN_00733e17(&DAT_00b7b3e8,s_Camera_Pos___2f___2f___2f___Foc__008fc4e8,
               (double)((float)*(int *)(in_ECX + 0x14) * 10.0 * 1.5258789e-05),
               (double)*(float *)(in_ECX + 0x1c),
               (double)((float)*(int *)(in_ECX + 0x18) * 10.0 * 1.5258789e-05),
               (double)*(float *)(in_ECX + 0x88),(double)*(float *)(in_ECX + 0xb8),
               (double)*(float *)(in_ECX + 0xe8));
  return &DAT_00b7b3e8;
}



