// Decompiled functions for class: UR_PlasmaInf
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetSaveType@UR_PlasmaInf@@UAEIXZ @ 0x00451850

undefined4 _GetSaveType_UR_PlasmaInf__UAEIXZ(void)

{
  return 0xba;
}



// ?GetDebugText@UR_PlasmaInf@@UAEPADXZ @ 0x00531150

char * _GetDebugText_UR_PlasmaInf__UAEPADXZ(void)

{
  return s___a_class__008fd150;
}



// ?Load@UR_PlasmaInf@@UAEIAAVGameOSFile@@@Z @ 0x0063e010

undefined4 _Load_UR_PlasmaInf__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Load_PSysBase__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x14),0xc,0,unaff_EDI,unaff_EBP,unaff_ESI,unaff_EBX);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x14) + 0xc;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x20) + 0xc;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x2c) + 0xc;
      if (DAT_00b19acc != 0) {
        iVar1 = FUN_0072be50();
        if (iVar1 == 3) {
          DAT_00b19acc = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x2c) + 0xc;
      }
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x38) + 0xc;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x44) + 4;
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
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x4c) + 1;
    }
    return 1;
  }
  return 0;
}



// ?Save@UR_PlasmaInf@@UAEIAAVGameOSFile@@@Z @ 0x0066c1e0

undefined4 _Save_UR_PlasmaInf__UAEIAAVGameOSFile___Z(int param_1)

{
  byte *pbVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = _Save_SpritePos_FireGraphic__UAEIAAVGameOSFile___Z(param_1);
  if (iVar2 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar2 = FUN_0072be90((byte *)(in_ECX + 0x14),0xc,0);
      if (iVar2 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x14) + 0xc;
      if (DAT_00b19ac8 != 0) {
        iVar2 = FUN_0072be90((byte *)(in_ECX + 0x20),0xc,0);
        if (iVar2 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x20) + 0xc;
        if (DAT_00b19ac8 != 0) {
          pbVar1 = (byte *)(in_ECX + 0x2c);
          iVar2 = FUN_0072be90(pbVar1,0xc,0);
          if (iVar2 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *pbVar1 + 0xc;
          if (DAT_00b19ac8 != 0) {
            iVar2 = FUN_0072be90(pbVar1,0xc,0);
            if (iVar2 == 3) {
              DAT_00b19ac8 = 0;
            }
            *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *pbVar1 + 0xc;
            if (DAT_00b19ac8 != 0) {
              iVar2 = FUN_0072be90((byte *)(in_ECX + 0x38),0xc,0);
              if (iVar2 == 3) {
                DAT_00b19ac8 = 0;
              }
              *(uint *)(param_1 + 0x214) =
                   *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x38) + 0xc;
              if (DAT_00b19ac8 != 0) {
                iVar2 = FUN_0072be90((byte *)(in_ECX + 0x44),4,0);
                if (iVar2 == 3) {
                  DAT_00b19ac8 = 0;
                }
                *(uint *)(param_1 + 0x214) =
                     *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x44) + 4;
                if (DAT_00b19ac8 != 0) {
                  iVar2 = FUN_0072be90((byte *)(in_ECX + 0x48),4,0);
                  if (iVar2 == 3) {
                    DAT_00b19ac8 = 0;
                  }
                  *(uint *)(param_1 + 0x214) =
                       *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x48) + 4;
                  if (DAT_00b19ac8 != 0) {
                    iVar2 = FUN_0072be90((byte *)(in_ECX + 0x4c),1,0);
                    if (iVar2 == 3) {
                      DAT_00b19ac8 = 0;
                    }
                    *(uint *)(param_1 + 0x214) =
                         *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x4c) + 1;
                  }
                }
              }
            }
          }
        }
      }
    }
    return 1;
  }
  return 0;
}



