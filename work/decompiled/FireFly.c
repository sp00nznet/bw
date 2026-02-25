// Decompiled functions for class: FireFly
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetSaveType@FireFly@@UAEIXZ @ 0x00500b10

undefined4 _GetSaveType_FireFly__UAEIXZ(void)

{
  return 0x2a;
}



// ?GetDebugText@FireFly@@UAEPADXZ @ 0x00500b20

char * _GetDebugText_FireFly__UAEPADXZ(void)

{
  return s_FireFly__00b17018;
}



// ?ToBeDeleted@FireFly@@UAEXH@Z @ 0x00500ce0

void _ToBeDeleted_FireFly__UAEXH_Z(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  iVar2 = DAT_00c22ca4;
  iVar3 = *(int *)(DAT_00c22ca4 + 0x201dc8);
  if (iVar3 == in_ECX) {
    *(int *)(DAT_00c22ca4 + 0x201dc8) = *(int *)(in_ECX + 0x54);
  }
  else {
    if (iVar3 == 0) goto LAB_00500d24;
    while (iVar1 = *(int *)(iVar3 + 0x54), iVar1 != in_ECX) {
      iVar3 = iVar1;
      if (iVar1 == 0) {
        _ToBeDeleted_Object__UAEXH_Z(0);
        return;
      }
    }
    *(undefined4 *)(iVar3 + 0x54) = *(undefined4 *)(in_ECX + 0x54);
  }
  *(int *)(iVar2 + 0x201dcc) = *(int *)(iVar2 + 0x201dcc) + -1;
  *(undefined4 *)(in_ECX + 0x54) = 0;
LAB_00500d24:
  _ToBeDeleted_Object__UAEXH_Z(0);
  return;
}



// ?CallVirtualFunctionsForCreation@FireFly@@UAEXABUMapCoords@@@Z @ 0x00500d30

/* WARNING: Removing unreachable block (ram,0x00500dcb) */

void _CallVirtualFunctionsForCreation_FireFly__UAEXABUMapCoords___Z(undefined4 *param_1)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  
  _CallVirtualFunctionsForCreation_Object__UAEXABUMapCoords___Z(param_1);
  *(undefined4 *)(in_ECX + 0x60) = *param_1;
  *(undefined4 *)(in_ECX + 100) = param_1[1];
  *(undefined4 *)(in_ECX + 0x68) = param_1[2];
  *(undefined4 *)(in_ECX + 0x78) = *param_1;
  *(undefined4 *)(in_ECX + 0x7c) = param_1[1];
  *(undefined4 *)(in_ECX + 0x80) = param_1[2];
  iVar2 = FUN_0064e790(1);
  *(int *)(in_ECX + 0x58) = iVar2;
  if (iVar2 != 0) {
    if (DAT_00bf0fc0 == 0) {
      uVar3 = FUN_005485f0(s___data_textures_S_SpriteSheet3_r_00b17024);
      DAT_00bf0fc0 = FUN_00788de0(0xd,uVar3);
    }
    *(int *)(*(int *)(in_ECX + 0x58) + 0x2c) = DAT_00bf0fc0;
    *(uint *)(*(int *)(in_ECX + 0x58) + 0x28) =
         *(uint *)(*(int *)(in_ECX + 0x58) + 0x28) & 0xffffffe5 | 0x25;
    iVar2 = *(int *)(in_ECX + 0x58);
    fVar1 = 0.3 / *(float *)(iVar2 + 0xc);
    *(float *)(iVar2 + 0x18) = fVar1 * *(float *)(iVar2 + 0x18);
    *(float *)(iVar2 + 0x1c) = fVar1 * *(float *)(iVar2 + 0x1c);
    *(undefined4 *)(iVar2 + 0xc) = 0x3e99999a;
  }
  return;
}



// ?Save@FireFly@@UAEIAAVGameOSFile@@@Z @ 0x00502080

undefined4 _Save_FireFly__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_Object__UAEIPAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x5c),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x5c) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90((byte *)(in_ECX + 0x60),0xc,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x60) + 0xc;
        if (DAT_00b19ac8 != 0) {
          iVar1 = FUN_0072be90((byte *)(in_ECX + 0x6c),0xc,0);
          if (iVar1 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x6c) + 0xc;
          if (DAT_00b19ac8 != 0) {
            iVar1 = FUN_0072be90((byte *)(in_ECX + 0x78),0xc,0);
            if (iVar1 == 3) {
              DAT_00b19ac8 = 0;
            }
            *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x78) + 0xc;
            if (DAT_00b19ac8 != 0) {
              iVar1 = FUN_0072be90((byte *)(in_ECX + 0x84),0xc,0);
              if (iVar1 == 3) {
                DAT_00b19ac8 = 0;
              }
              *(uint *)(param_1 + 0x214) =
                   *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x84) + 0xc;
              if (DAT_00b19ac8 != 0) {
                iVar1 = FUN_0072be90((byte *)(in_ECX + 0x90),4,0);
                if (iVar1 == 3) {
                  DAT_00b19ac8 = 0;
                }
                *(uint *)(param_1 + 0x214) =
                     *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x90) + 4;
                if (DAT_00b19ac8 != 0) {
                  iVar1 = FUN_0072be90((byte *)(in_ECX + 0x94),4,0);
                  if (iVar1 == 3) {
                    DAT_00b19ac8 = 0;
                  }
                  *(uint *)(param_1 + 0x214) =
                       *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x94) + 4;
                  if (DAT_00b19ac8 != 0) {
                    iVar1 = FUN_0072be90((byte *)(in_ECX + 0x98),4,0);
                    if (iVar1 == 3) {
                      DAT_00b19ac8 = 0;
                    }
                    *(uint *)(param_1 + 0x214) =
                         *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x98) + 4;
                    if (DAT_00b19ac8 != 0) {
                      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x9c),4,0);
                      if (iVar1 == 3) {
                        DAT_00b19ac8 = 0;
                      }
                      *(uint *)(param_1 + 0x214) =
                           *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x9c) + 4;
                      if (DAT_00b19ac8 != 0) {
                        iVar1 = FUN_0072be90((byte *)(in_ECX + 0xa0),4,0);
                        if (iVar1 == 3) {
                          DAT_00b19ac8 = 0;
                        }
                        *(uint *)(param_1 + 0x214) =
                             *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xa0) + 4;
                        if (DAT_00b19ac8 != 0) {
                          iVar1 = FUN_0072be90((byte *)(in_ECX + 0xa4),4,0);
                          if (iVar1 == 3) {
                            DAT_00b19ac8 = 0;
                          }
                          *(uint *)(param_1 + 0x214) =
                               *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xa4) + 4;
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
    }
    FUN_0066ee00(in_ECX + 0xa8);
    FUN_0066ee00(in_ECX + 0xac);
    FUN_0066ee00(in_ECX + 0xb0);
    FUN_0066ee00(in_ECX + 0xb4);
    FUN_0066ee00(in_ECX + 0xb8);
    FUN_0066ee00(in_ECX + 0xbc);
    FUN_00604120(in_ECX + 0xc0);
    FUN_005341d0(&DAT_00bf0e64,0x2a);
    FUN_005341d0(&DAT_00bf0f0c,0x2a);
    FUN_00604120(&DAT_00b16fdc);
    return 1;
  }
  return 0;
}



// ?Load@FireFly@@UAEIAAVGameOSFile@@@Z @ 0x005023d0

undefined4 _Load_FireFly__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Load__6ObjectFR10GameOSFile(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x5c),4,0,unaff_EDI,unaff_EBP,unaff_ESI,unaff_EBX);
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
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x60) + 0xc;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x6c) + 0xc;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x78) + 0xc;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x84) + 0xc;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x90) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x94) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x98) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x9c) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xa0) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xa4) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xa8) + 4;
    }
    FUN_00589540();
    FUN_00589540();
    FUN_00589540();
    FUN_00589540();
    FUN_00589540();
    FUN_00604170();
    FUN_005027e0();
    FUN_005027e0();
    FUN_00604170();
    return 1;
  }
  return 0;
}



// ?SaveObject@FireFly@@UAEIAAULHOSFile@@ABUMapCoords@@@Z @ 0x00502720

int _SaveObject_FireFly__UAEIAAULHOSFile__ABUMapCoords___Z(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  char *pcVar5;
  undefined1 auStack_138 [12];
  char acStack_12c [200];
  undefined1 auStack_64 [100];
  
  iVar2 = FUN_0053eb80();
  if (iVar2 == 0) {
    return 0;
  }
  if (param_2 != 0) {
    FUN_005c13b0(auStack_138,param_2);
  }
  uVar3 = FUN_005bf290(auStack_64);
  uVar3 = FUN_006ad590(0x55,uVar3);
  FUN_00733e17(acStack_12c,uVar3);
  iVar4 = -1;
  pcVar5 = acStack_12c;
  do {
    if (iVar4 == 0) break;
    iVar4 = iVar4 + -1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_006b10c0();
  return iVar2;
}



