// Decompiled functions for class: Field
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetSaveType@Field@@UAEIXZ @ 0x004fec80

char * _GetSaveType_Field__UAEIXZ(void)

{
  return s_Field__00b16fd4;
}



// ?ToBeDeleted@Field@@UAEXH@Z @ 0x004fecc0

void _ToBeDeleted_Field__UAEXH_Z(undefined4 param_1)

{
  FUN_004019f0(param_1);
  return;
}



// ?GetPlayer@Field@@UAEPAVGPlayer@@XZ @ 0x004ff510

undefined4 _GetPlayer_Field__UAEPAVGPlayer__XZ(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x118) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004ff51c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(**(int **)(in_ECX + 0x118) + 0x1c))();
    return uVar1;
  }
  return 0;
}



// ?GetTown@Field@@UAEPAVTown@@XZ @ 0x004ff530

undefined4 _GetTown_Field__UAEPAVTown__XZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x118);
}



// ?NetworkFriendlyStartLockedSelect@Field@@UAE_NPAVGInterfaceStatus@@@Z @ 0x004ffc20

undefined4 _NetworkFriendlyStartLockedSelect_Field__UAE_NPAVGInterfaceStatus___Z(int *param_1)

{
  float fVar1;
  float fVar2;
  int in_ECX;
  
  fVar1 = (float)*param_1 * 10.0 * 1.5258789e-05;
  fVar2 = (float)*(int *)(in_ECX + 0x14) * 10.0 * 1.5258789e-05;
  if ((fVar2 - 5.0 <= fVar1) && (fVar1 < fVar2 + 5.0)) {
    fVar1 = (float)param_1[1] * 10.0 * 1.5258789e-05;
    fVar2 = (float)*(int *)(in_ECX + 0x18) * 10.0 * 1.5258789e-05;
    if ((fVar2 - 5.0 <= fVar1) && (fVar1 < fVar2 + 5.0)) {
      return 1;
    }
  }
  return 0;
}



// ?NetworkFriendlyEndLockedSelect@Field@@UAEIPAVGInterfaceStatus@@@Z @ 0x00500220

undefined4 _NetworkFriendlyEndLockedSelect_Field__UAEIPAVGInterfaceStatus___Z(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x690))();
  uVar1 = __ftol();
  iVar2 = FUN_005001f0();
  if (iVar2 != 0) {
    uVar1 = uVar1 >> 1;
  }
  if (uVar1 != 0) {
    FUN_004ffec0((float)uVar1);
    uVar3 = (**(code **)(*in_ECX + 0x48))(0,0,0x3f800000,0);
    iVar2 = FUN_00616c40(param_1 + 0x14,&DAT_00c6e330,uVar1,0,uVar3);
    if (iVar2 != 0) {
      FUN_0059c850(iVar2);
      uVar3 = FUN_005bfd00();
      *(undefined4 *)(param_1 + 0x128) = uVar3;
      FUN_00637aa0(param_1,in_ECX + 5,0);
      return 1;
    }
  }
  return 0;
}



// ?NetworkUnfriendlyEndLockedSelect@Field@@UAEIXZ @ 0x00500300

undefined4 _NetworkUnfriendlyEndLockedSelect_Field__UAEIXZ(void)

{
  int in_ECX;
  
  if ((0.0 < *(float *)(in_ECX + 0xd0)) && (1.0 < *(float *)(in_ECX + 0xdc))) {
    return 1;
  }
  return 0;
}



// ?GetArrivePos@Field@@UAEPAUMapCoords@@PAU2@@Z @ 0x005003f0

undefined4 _GetArrivePos_Field__UAEPAUMapCoords__PAU2__Z(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  
  iVar2 = _GetArrivePos_Creche__UAEPAUMapCoords__PAU2__Z(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  FUN_00533b90(*(undefined4 *)(in_ECX + 0x120));
  iVar2 = 0;
  if (DAT_00b19ac8 != 0) {
    iVar3 = FUN_0072be90((byte *)(in_ECX + 200),4,0);
    if (iVar3 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 200) + 4;
    if (DAT_00b19ac8 != 0) {
      iVar3 = FUN_0072be90((byte *)(in_ECX + 0xdc),4,0);
      if (iVar3 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xdc) + 4;
    }
  }
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0x118));
  if (DAT_00b19ac8 != 0) {
    iVar3 = FUN_0072be90((byte *)(in_ECX + 0x11c),4,0);
    if (iVar3 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x11c) + 4;
    if (DAT_00b19ac8 != 0) {
      iVar3 = FUN_0072be90((byte *)(in_ECX + 0xcc),1,0);
      if (iVar3 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xcc) + 1;
      if (DAT_00b19ac8 != 0) {
        iVar3 = FUN_0072be90((byte *)(in_ECX + 0xd0),4,0);
        if (iVar3 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xd0) + 4;
        if (DAT_00b19ac8 != 0) {
          iVar3 = *(int *)(in_ECX + 0xd8);
          iVar4 = FUN_0072be90((byte *)(in_ECX + 0xd8),4,0);
          if (iVar4 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xd8) + 4;
          for (puVar1 = *(undefined4 **)(in_ECX + 0xd4); puVar1 != (undefined4 *)0x0;
              puVar1 = (undefined4 *)*puVar1) {
            iVar2 = iVar2 + 1;
            if (iVar3 < iVar2) {
              DAT_00b19ac8 = 0;
              return 1;
            }
            if (DAT_00b19ac8 == 0) {
              return 1;
            }
            FUN_00531bc0(puVar1[1]);
          }
          if (DAT_00b19ac8 != 0) {
            if (iVar2 != iVar3) {
              DAT_00b19ac8 = 0;
              return 1;
            }
            iVar2 = FUN_0072be90((byte *)(in_ECX + 0xe0),1,0);
            if (iVar2 == 3) {
              DAT_00b19ac8 = 0;
            }
            *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xe0) + 1;
          }
        }
      }
    }
  }
  return 1;
}



