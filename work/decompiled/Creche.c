// Decompiled functions for class: Creche
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetArrivePos@Creche@@UAEPAUMapCoords@@PAU2@@Z @ 0x00405070

undefined4 _GetArrivePos_Creche__UAEPAUMapCoords__PAU2__Z(uint param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  uint uVar4;
  uint local_4;
  
  iVar1 = param_1;
  iVar2 = _Save_MultiMapFixed__UAEIPAVGameOSFile___Z(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = 0;
  if (DAT_00b19ac8 != 0) {
    iVar3 = FUN_0072be90((byte *)(in_ECX + 0x7c),1,0);
    if (iVar3 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x7c) + 1;
    if (DAT_00b19ac8 != 0) {
      iVar3 = FUN_0072be90((byte *)(in_ECX + 0x80),0xc,0);
      if (iVar3 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x80) + 0xc;
      if (DAT_00b19ac8 != 0) {
        iVar3 = FUN_0072be90((byte *)(in_ECX + 0x94),4,0);
        if (iVar3 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x94) + 4;
      }
    }
  }
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0x98));
  if (DAT_00b19ac8 != 0) {
    param_1 = *(int *)(in_ECX + 0xa4);
    FUN_0066ee00(in_ECX + 0xa4);
    iVar3 = 0;
    while( true ) {
      if (iVar3 == 0) {
        iVar3 = *(int *)(in_ECX + 0xa0);
      }
      else {
        iVar3 = *(int *)(iVar3 + 0xe4);
      }
      if (iVar3 == 0) break;
      iVar2 = iVar2 + 1;
      if ((int)param_1 < iVar2) {
        DAT_00b19ac8 = 0;
        goto LAB_004052ab;
      }
      if (DAT_00b19ac8 == 0) goto LAB_004052ab;
      FUN_00531bc0(iVar3);
    }
    if (DAT_00b19ac8 != 0) {
      iVar2 = FUN_0072be90((byte *)(in_ECX + 0xb4),1,0);
      if (iVar2 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0xb4) + 1;
      if (DAT_00b19ac8 != 0) {
        iVar2 = FUN_0072be90((byte *)(in_ECX + 0xb6),1,0);
        if (iVar2 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0xb6) + 1;
        if (DAT_00b19ac8 != 0) {
          iVar2 = FUN_0072be90((byte *)(in_ECX + 0xb7),1,0);
          if (iVar2 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0xb7) + 1;
          if (DAT_00b19ac8 != 0) {
            iVar2 = FUN_0072be90((byte *)(in_ECX + 0xb8),1,0);
            if (iVar2 == 3) {
              DAT_00b19ac8 = 0;
            }
            *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0xb8) + 1;
          }
        }
      }
    }
  }
LAB_004052ab:
  param_1 = 2;
  if (DAT_00b19ac8 != 0) {
    FUN_0066ee00(&param_1);
    uVar4 = 0;
    if (param_1 != 0) {
      iVar2 = in_ECX + 0xbc;
      do {
        FUN_0066ee00(iVar2);
        if (DAT_00b19ac8 == 0) break;
        uVar4 = uVar4 + 1;
        iVar2 = iVar2 + 4;
      } while (uVar4 < param_1);
    }
  }
  local_4 = (uint)(*(int *)(in_ECX + 0x90) != 0);
  if (DAT_00b19ac8 != 0) {
    iVar2 = FUN_0072be90(&local_4,4,0);
    if (iVar2 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + (local_4 & 0xff) + 4;
  }
  if (local_4 != 0) {
    FUN_006fb420(iVar1);
  }
  return 1;
}



// ?GetSaveType@Creche@@UAEIXZ @ 0x004e9230

char * _GetSaveType_Creche__UAEIXZ(void)

{
  return s_Creche__00b14570;
}



