// Decompiled functions for class: Abode
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetTown@Abode@@UAEPAVTown@@XZ @ 0x00401450

undefined4 _GetTown_Abode__UAEPAVTown__XZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x98);
}



// ?Delete@Abode@@UAEXXZ @ 0x004019a0

void _Delete_Abode__UAEXXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x910))();
  iVar1 = (**(code **)(*in_ECX + 0x48))();
  if (iVar1 != 0) {
    if ((*(uint *)(DAT_00c22ca4 + 0x14) & 0x8000) == 0) {
      (**(code **)(*in_ECX + 0x90c))();
    }
    (**(code **)(*in_ECX + 0x48))();
    FUN_006cd770(in_ECX);
  }
  _Delete_Object__UAEXH_Z();
  return;
}



// ?SaveObject@Abode@@UAEIPAVLHOSFile@@PBUMapCoords@@@Z @ 0x00401a60

void _SaveObject_Abode__UAEIPAVLHOSFile__PBUMapCoords___Z(undefined4 param_1,undefined4 param_2)

{
  _GetInspectObjectPos_Object__UAE_NPAVVillager__PAUMapCoords___Z(param_1,param_2);
  return;
}



// ?IsFunctional@Abode@@UAE_NXZ @ 0x00402c90

undefined2 _IsFunctional_Abode__UAE_NXZ(void)

{
  return 1;
}



// ?GetResource@Abode@@UAEIW4RESOURCE_TYPE@@@Z @ 0x00403890

void _GetResource_Abode__UAEIW4RESOURCE_TYPE___Z(int param_1,uint param_2)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = *(uint *)(in_ECX + 0xbc + param_1 * 4);
  if (uVar1 < param_2) {
    param_2 = uVar1;
  }
  *(uint *)(in_ECX + 0xbc + param_1 * 4) = uVar1 - param_2;
  return;
}



// ?CastAbode@Abode@@UAEPAV1@XZ @ 0x004038c0

void _CastAbode_Abode__UAEPAV1_XZ
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  int *in_ECX;
  
  if (((int *)in_ECX[0x1d] != (int *)0x0) && ((param_1 == 1 || (param_1 == -2)))) {
    (**(code **)(*(int *)in_ECX[0x1d] + 0x9c))(param_1,param_2,param_3,param_4,0,0);
    return;
  }
  (**(code **)(*in_ECX + 0x8e4))(param_1,param_2,param_3,param_4,param_5,param_6);
  return;
}



// ?GetPlayer@Abode@@UAEPAVGPlayer@@XZ @ 0x00404600

void _GetPlayer_Abode__UAEPAVGPlayer__XZ(void)

{
  int iVar1;
  int *piVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x48))();
  if (iVar1 != 0) {
    piVar2 = (int *)(**(code **)(*in_ECX + 0x48))();
    (**(code **)(*piVar2 + 0x1c))();
    return;
  }
  _GetPlayer_GameThing__QAEPAVGPlayer__XZ();
  return;
}



// ?GetArrivePos@Abode@@UAEPAUMapCoords@@PAU2@@Z @ 0x00508f70

undefined4 _GetArrivePos_Abode__UAEPAUMapCoords__PAU2__Z(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  undefined4 unaff_EBX;
  byte *pbVar3;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _GetPos_GameThingWithPos__QAEPAUMapCoords__XZ(param_1);
  if (iVar1 != 0) {
    FUN_00531f30(in_ECX + 0xc4);
    FUN_00532060(in_ECX + 200);
    FUN_00532060(in_ECX + 0xf0);
    FUN_00531f30(in_ECX + 0x140);
    pbVar3 = (byte *)(in_ECX + 0x14c);
    iVar1 = 0xc;
    do {
      if (DAT_00b19acc != 0) {
        iVar2 = FUN_0072be50(pbVar3,0xc,0,unaff_EBP,unaff_EBX,unaff_EDI,unaff_ESI);
        if (iVar2 == 3) {
          DAT_00b19acc = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *pbVar3 + 0xc;
      }
      pbVar3 = pbVar3 + 0xc;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x1dc),4,0,unaff_EBP,unaff_EBX,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x1dc) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x1e0),4,0,unaff_EBP,unaff_EBX,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x1e0) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x1e4),1,0,unaff_EBP,unaff_EBX,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x1e4) + 1;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x1e8),4,0,unaff_EBP,unaff_EBX,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x1e8) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x1ec),1,0,unaff_EBP,unaff_EBX,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x1ec) + 1;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x1f0),4,0,unaff_EBP,unaff_EBX,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x1f0) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 500),1,0,unaff_EBP,unaff_EBX,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 500) + 1;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x1f8),4,0,unaff_EBP,unaff_EBX,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x1f8) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x1fc),4,0,unaff_EBP,unaff_EBX,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x1fc) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x200),4,0,unaff_EBP,unaff_EBX,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x200) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x204),4,0,unaff_EBP,unaff_EBX,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x204) + 4;
    }
    FUN_00589540(in_ECX + 0x208);
    FUN_00589540(in_ECX + 0x20c);
    FUN_00604170(in_ECX + 0x210);
    FUN_00604170(in_ECX + 0x211);
    FUN_00589540(in_ECX + 0x214);
    FUN_00589540(in_ECX + 0x218);
    FUN_00531f30(in_ECX + 0x21c);
    FUN_0055c8c0(in_ECX + 0x220);
    FUN_0055c8c0(in_ECX + 0x228);
    FUN_0055c8c0(in_ECX + 0x230);
    FUN_0055c8c0(in_ECX + 0x238);
    FUN_00532060(in_ECX + 0x240);
    FUN_00532060(in_ECX + 0x248);
    FUN_00531f30(in_ECX + 0x250);
    FUN_00532060(in_ECX + 600);
    FUN_004ec100(in_ECX + 0x308);
    FUN_00531f30(in_ECX + 0x254);
    return 1;
  }
  return 0;
}



// ?GetArrivePos@Abode@@UAEPAUMapCoords@@PAU2@@Z @ 0x00678b20

undefined4 _GetArrivePos_Abode__UAEPAUMapCoords__PAU2__Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _GetArrivePos_Abode__UAEPAUMapCoords__PAU2__Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0xe4),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xe4) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90((byte *)(in_ECX + 0xe8),4,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xe8) + 4;
      }
    }
    return 1;
  }
  return 0;
}



// ?GetArrivePos@Abode@@UAEPAUMapCoords@@PAU2@@Z @ 0x006cb7b0

undefined4 _GetArrivePos_Abode__UAEPAUMapCoords__PAU2__Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _GetArrivePos_Creche__UAEPAUMapCoords__PAU2__Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0xc4),0xc,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xc4) + 0xc;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90((byte *)(in_ECX + 0xd0),0xc,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xd0) + 0xc;
      }
    }
    return 1;
  }
  return 0;
}



// ?MoveAbodeToPlannedAbodes@Abode@@UAEXXZ @ 0x006d6800

void _MoveAbodeToPlannedAbodes_Abode__UAEXXZ(undefined4 *param_1)

{
  int iVar1;
  int in_ECX;
  float fStack_18;
  float fStack_14;
  float fStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar1 = *(int *)(in_ECX + 0x40);
  fStack_18 = *(float *)(iVar1 + 0x14) + *(float *)(iVar1 + 0x14) +
              (*(float *)(iVar1 + 0x38) - *(float *)(iVar1 + 0x2c) * 12.0);
  fStack_14 = ((*(float *)(iVar1 + 0x18) + *(float *)(iVar1 + 0x18)) -
              *(float *)(iVar1 + 0x30) * 12.0) + *(float *)(iVar1 + 0x3c);
  fStack_10 = ((*(float *)(iVar1 + 0x1c) + *(float *)(iVar1 + 0x1c)) -
              *(float *)(iVar1 + 0x34) * 12.0) + *(float *)(iVar1 + 0x40);
  FUN_005bf830(&fStack_18);
  *param_1 = uStack_c;
  param_1[1] = uStack_8;
  param_1[2] = uStack_4;
  return;
}



