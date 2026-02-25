// Decompiled functions for class: Flock
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetText@Flock@@UAEPBDXZ @ 0x005059d0

char * _GetText_Flock__UAEPBDXZ(void)

{
  return s_Flock_00b17134;
}



// ?GetSaveType@Flock@@UAEIXZ @ 0x005059e0

undefined4 _GetSaveType_Flock__UAEIXZ(void)

{
  return 0x7e;
}



// ?GetDebugText@Flock@@UAEPADXZ @ 0x005059f0

char * _GetDebugText_Flock__UAEPADXZ(void)

{
  return s_Flock__00b1713c;
}



// ?ToBeDeleted@Flock@@UAEXH@Z @ 0x00506080

void _ToBeDeleted_Flock__UAEXH_Z(undefined4 param_1)

{
  FUN_00505f30();
  _ToBeDeleted_GameThingWithPos__UAEXH_Z(param_1);
  return;
}



// ?Save@Flock@@UAEIAAVGameOSFile@@@Z @ 0x005065b0

undefined4 _Save_Flock__UAEIAAVGameOSFile___Z(uint param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  uint uStack_8;
  uint uStack_4;
  
  iVar1 = param_1;
  iVar2 = _Save_Container__UAEIAAVGameOSFile___Z(param_1);
  if (iVar2 != 0) {
    uStack_8 = 0;
    param_1 = 0xffffffff;
    if (DAT_00b19ac8 != 0) {
      iVar2 = FUN_0072be90(&uStack_8,4,0);
      if (iVar2 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + (uStack_8 & 0xff) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar2 = FUN_0072be90(&param_1,4,0);
        if (iVar2 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + (param_1 & 0xff) + 4;
        if (DAT_00b19ac8 != 0) {
          iVar2 = FUN_0072be90(&param_1,4,0);
          if (iVar2 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + (param_1 & 0xff) + 4;
        }
      }
    }
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x30));
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x34));
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x38));
    uStack_4 = *(uint *)(in_ECX + 0x48);
    if (DAT_00b19ac8 != 0) {
      iVar2 = FUN_0072be90(&uStack_4,4,0);
      if (iVar2 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + (uStack_4 & 0xff) + 4;
    }
    *(undefined4 *)(in_ECX + 0x44) = *(undefined4 *)(in_ECX + 0x3c);
    while ((iVar2 = *(int *)(in_ECX + 0x44), iVar2 != 0 && (*(int *)(iVar2 + 8) != 0))) {
      if (iVar2 == 0) {
        FUN_00531bc0(0);
        FUN_00506ce0();
      }
      else {
        FUN_00531bc0(*(undefined4 *)(iVar2 + 8));
        FUN_00506ce0();
      }
    }
    if (DAT_00b19ac8 != 0) {
      iVar2 = FUN_0072be90((byte *)(in_ECX + 0x88),4,0);
      if (iVar2 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x88) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar2 = FUN_0072be90((byte *)(in_ECX + 0x4c),4,0);
        if (iVar2 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x4c) + 4;
        if (DAT_00b19ac8 != 0) {
          iVar2 = FUN_0072be90((byte *)(in_ECX + 0x50),2,0);
          if (iVar2 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x50) + 2;
          if (DAT_00b19ac8 != 0) {
            iVar2 = FUN_0072be90((byte *)(in_ECX + 0x52),2,0);
            if (iVar2 == 3) {
              DAT_00b19ac8 = 0;
            }
            *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x52) + 2;
            if (DAT_00b19ac8 != 0) {
              iVar2 = FUN_0072be90((byte *)(in_ECX + 0x54),4,0);
              if (iVar2 == 3) {
                DAT_00b19ac8 = 0;
              }
              *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x54) + 4;
              if (DAT_00b19ac8 != 0) {
                iVar2 = FUN_0072be90((byte *)(in_ECX + 0x58),4,0);
                if (iVar2 == 3) {
                  DAT_00b19ac8 = 0;
                }
                *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x58) + 4;
                if (DAT_00b19ac8 != 0) {
                  iVar2 = FUN_0072be90((byte *)(in_ECX + 0x5c),4,0);
                  if (iVar2 == 3) {
                    DAT_00b19ac8 = 0;
                  }
                  *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x5c) + 4;
                }
              }
            }
          }
        }
      }
    }
    FUN_004ebf70(in_ECX + 0x60);
    FUN_004ebf70(in_ECX + 0x6c);
    FUN_0066ee00(in_ECX + 0x78);
    FUN_0066ee00(in_ECX + 0x7c);
    FUN_0066ee00(in_ECX + 0x80);
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x84));
    FUN_0066ee00(in_ECX + 0x8c);
    return 1;
  }
  return 0;
}



// ?Load@Flock@@UAEIAAVGameOSFile@@@Z @ 0x00506940

undefined4 _Load_Flock__UAEIAAVGameOSFile___Z(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  bool bVar4;
  uint in_stack_00005d09;
  uint in_stack_0000ba26;
  int in_stack_00011727;
  int in_stack_0001172f;
  uint in_stack_00011737;
  uint in_stack_00017438;
  
  iVar2 = _Load_Container__UAEIAAVGameOSFile___Z();
  if (iVar2 == 0) {
    return 0;
  }
  if (DAT_00b19acc != 0) {
    iVar2 = FUN_0072be50();
    if (iVar2 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (in_stack_00005d09 & 0xff) + 4;
    if (DAT_00b19acc != 0) {
      iVar2 = FUN_0072be50();
      if (iVar2 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (in_stack_0000ba26 & 0xff) + 4;
      if (DAT_00b19acc != 0) {
        iVar2 = FUN_0072be50();
        if (iVar2 == 3) {
          DAT_00b19acc = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (in_stack_00011737 & 0xff) + 4;
      }
    }
  }
  FUN_00531f30();
  FUN_00531f30();
  FUN_00531f30();
  if (DAT_00b19acc != 0) {
    iVar2 = FUN_0072be50();
    if (iVar2 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (in_stack_00017438 & 0xff) + 4;
  }
  do {
    if (in_stack_00011727 == 0) {
      if (DAT_00b19acc != 0) {
        iVar2 = FUN_0072be50();
        if (iVar2 == 3) {
          DAT_00b19acc = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x88) + 4;
      }
      if (DAT_00b19acc != 0) {
        iVar2 = FUN_0072be50();
        if (iVar2 == 3) {
          DAT_00b19acc = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x4c) + 4;
      }
      if (DAT_00b19acc != 0) {
        iVar2 = FUN_0072be50();
        if (iVar2 == 3) {
          DAT_00b19acc = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x50) + 2;
      }
      if (DAT_00b19acc != 0) {
        iVar2 = FUN_0072be50();
        if (iVar2 == 3) {
          DAT_00b19acc = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x52) + 2;
      }
      FUN_00589540();
      FUN_00589540();
      FUN_00589540();
      FUN_004ec100();
      FUN_004ec100();
      FUN_00589540();
      FUN_00589540();
      FUN_00589540();
      FUN_00531f30();
      FUN_00589540();
      return 1;
    }
    bVar4 = false;
    FUN_00531f30();
    if (in_stack_0001172f != 0) {
      iVar2 = FUN_00746d70();
      if (iVar2 == 0) {
        puVar3 = (undefined4 *)0x0;
      }
      else {
        puVar3 = (undefined4 *)FUN_00506cf0();
      }
      if (*(int *)(in_ECX + 0x48) == 0) {
        *(undefined4 **)(in_ECX + 0x3c) = puVar3;
LAB_00506b26:
        *(undefined4 **)(in_ECX + 0x40) = puVar3;
        *(undefined4 **)(in_ECX + 0x44) = puVar3;
      }
      else {
        puVar1 = *(undefined4 **)(in_ECX + 0x3c);
        while ((puVar1 != (undefined4 *)0x0 && (!bVar4))) {
          bVar4 = *(byte *)(puVar3[2] + 0xd4) <= *(byte *)(puVar1[2] + 0xd4);
          if (bVar4) {
            puVar3[1] = puVar1[1];
            *puVar3 = puVar1;
            if (*(undefined4 **)(in_ECX + 0x3c) == puVar1) {
              *(undefined4 **)(in_ECX + 0x3c) = puVar3;
            }
            else {
              *(undefined4 **)puVar1[1] = puVar3;
            }
            puVar1[1] = puVar3;
            *(undefined4 **)(in_ECX + 0x44) = puVar3;
          }
          puVar1 = (undefined4 *)*puVar1;
        }
        if (*(undefined4 **)(in_ECX + 0x44) != puVar3) {
          **(undefined4 **)(in_ECX + 0x40) = puVar3;
          puVar3[1] = *(undefined4 *)(in_ECX + 0x40);
          goto LAB_00506b26;
        }
      }
      *(int *)(in_ECX + 0x48) = *(int *)(in_ECX + 0x48) + 1;
    }
    in_stack_00011727 = in_stack_00011727 + -1;
  } while( true );
}



// ?GetTown@Flock@@UAEPAVTown@@XZ @ 0x0052fb00

undefined4 _GetTown_Flock__UAEPAVTown__XZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x34);
}



// ?GetCreatureBeliefType@Flock@@UAEIXZ @ 0x0066f560

undefined4 _GetCreatureBeliefType_Flock__UAEIXZ(void)

{
  return 0x16;
}



// ?GetScriptObjectType@Flock@@UAEIXZ @ 0x006fc980

undefined4 _GetScriptObjectType_Flock__UAEIXZ(void)

{
  return 0xb;
}



