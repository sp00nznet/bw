// Decompiled functions for class: GameThingWithPos
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?IsDeletedWhenReleasedFromScript@GameThingWithPos@@UAE_NXZ @ 0x00401470

undefined4 _IsDeletedWhenReleasedFromScript_GameThingWithPos__UAE_NXZ(void)

{
  return 5;
}



// ?SetPos@GameThingWithPos@@QAEXABUMapCoords@@@Z @ 0x004014c0

void _SetPos_GameThingWithPos__QAEXABUMapCoords___Z(undefined4 *param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x14) = *param_1;
  *(undefined4 *)(in_ECX + 0x18) = param_1[1];
  *(undefined4 *)(in_ECX + 0x1c) = param_1[2];
  return;
}



// ?PhysicsEditorCreate@GameThingWithPos@@QAEXH@Z @ 0x004014e0

void _PhysicsEditorCreate_GameThingWithPos__QAEXH_Z(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x1c) = 0;
  return;
}



// ?IsCannotBePickedUp@GameThingWithPos@@UBE_NXZ @ 0x004014f0

uint _IsCannotBePickedUp_GameThingWithPos__UBE_NXZ(void)

{
  int in_ECX;
  
  return (*(ushort *)(in_ECX + 0x24) & 0x2000) >> 0xd;
}



// ?IsAvailableForStateChange@GameThingWithPos@@UAE_NXZ @ 0x00401500

uint _IsAvailableForStateChange_GameThingWithPos__UAE_NXZ(void)

{
  int in_ECX;
  
  return ((byte)~*(byte *)(in_ECX + 0x24) & 4) >> 2;
}



// ?IsDamaged@GameThingWithPos@@UAE_NXZ @ 0x00401510

undefined4 _IsDamaged_GameThingWithPos__UAE_NXZ(void)

{
  int *in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 0x11c))();
  if (fVar1 < (float10)1.0) {
    return 1;
  }
  return 0;
}



// ?CanBeStonedAndEatenByCreature@GameThingWithPos@@UAE_NPAVCreature@@@Z @ 0x00401530

undefined4 _CanBeStonedAndEatenByCreature_GameThingWithPos__UAE_NPAVCreature___Z(undefined4 param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 600))(param_1);
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*in_ECX + 0x278))(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}



// ?IsNotOnFire@GameThingWithPos@@UAE_NPAVCreature@@@Z @ 0x00401570

bool _IsNotOnFire_GameThingWithPos__UAE_NPAVCreature___Z(undefined4 param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x298))(param_1);
  return iVar1 == 0;
}



// ?CanBeUsedForBuildingHomeByCreature@GameThingWithPos@@UAE_NPAVCreature@@@Z @ 0x00401590

undefined4
_CanBeUsedForBuildingHomeByCreature_GameThingWithPos__UAE_NPAVCreature___Z(undefined4 param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x1f0))();
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*in_ECX + 0x2a0))(param_1);
    if (iVar1 != 0) {
      iVar1 = FUN_004c5380(param_1);
      if (iVar1 == 0) {
        return 1;
      }
    }
  }
  return 0;
}



// ?IsRock@GameThingWithPos@@UAE_NPAVCreature@@@Z @ 0x004015d0

void _IsRock_GameThingWithPos__UAE_NPAVCreature___Z(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x1f0))();
  return;
}



// ?IsPickupableRock@GameThingWithPos@@UAE_NPAVCreature@@@Z @ 0x004015e0

undefined4 _IsPickupableRock_GameThingWithPos__UAE_NPAVCreature___Z(undefined4 param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x1f0))();
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*in_ECX + 600))(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}



// ?IsLiving@GameThingWithPos@@UBE_NPAVCreature@@@Z @ 0x00401620

void _IsLiving_GameThingWithPos__UBE_NPAVCreature___Z(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x3c4))();
  return;
}



// ?SetControlledByScript@GameThingWithPos@@UAEXH@Z @ 0x00401630

void _SetControlledByScript_GameThingWithPos__UAEXH_Z(byte param_1)

{
  int in_ECX;
  
  *(ushort *)(in_ECX + 0x24) = (param_1 & 1) << 10 | *(ushort *)(in_ECX + 0x24) & 0xfbff;
  return;
}



// ?IsInScript@GameThingWithPos@@UAE_NXZ @ 0x00401660

uint _IsInScript_GameThingWithPos__UAE_NXZ(void)

{
  int in_ECX;
  
  return (*(ushort *)(in_ECX + 0x24) & 0x200) >> 9;
}



// ?GetCreatureBeliefType@GameThingWithPos@@UAEIXZ @ 0x00403c80

undefined4 _GetCreatureBeliefType_GameThingWithPos__UAEIXZ(void)

{
  return 0x15;
}



// ?IsObjectInMap@GameThingWithPos@@UAE_NXZ @ 0x00403c90

byte _IsObjectInMap_GameThingWithPos__UAE_NXZ(void)

{
  int in_ECX;
  
  return *(byte *)(in_ECX + 0x24) & 1;
}



// ?GetCreatureMimicType@GameThingWithPos@@UBEIXZ @ 0x00403ca0

undefined4 _GetCreatureMimicType_GameThingWithPos__UBEIXZ(void)

{
  return 10;
}



// ?SetInScript@GameThingWithPos@@UAEXH@Z @ 0x00403cb0

void _SetInScript_GameThingWithPos__UAEXH_Z(byte param_1)

{
  int in_ECX;
  
  *(ushort *)(in_ECX + 0x24) = (param_1 & 1) << 9 | *(ushort *)(in_ECX + 0x24) & 0xfdff;
  return;
}



// ?AttitudeToCreatureEating@GameThingWithPos@@UAEIXZ @ 0x00404420

undefined4 _AttitudeToCreatureEating_GameThingWithPos__UAEIXZ(void)

{
  return 1;
}



// ?IsSacrificeAltar@GameThingWithPos@@UAE_NXZ @ 0x00404850

bool _IsSacrificeAltar_GameThingWithPos__UAE_NXZ(void)

{
  int in_ECX;
  
  return *(int *)(*(int *)(in_ECX + 0x28) + 0x120) == 0x100;
}



// ?GetPos@GameThingWithPos@@QAEPAUMapCoords@@XZ @ 0x00405380

undefined4 _GetPos_GameThingWithPos__QAEPAUMapCoords__XZ(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  uint uVar3;
  int in_stack_00005d09;
  int in_stack_00005d0d;
  int in_stack_00005d15;
  uint in_stack_0000ba26;
  uint in_stack_0001172f;
  
  iVar1 = _Load__13MultiMapFixedFR10GameOSFile();
  if (iVar1 == 0) {
    return 0;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x7c) + 1;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x80) + 0xc;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x94) + 4;
  }
  FUN_00531f30();
  if (DAT_00b19acc != 0) {
    FUN_00589540();
    for (; 0 < in_stack_00005d15; in_stack_00005d15 = in_stack_00005d15 + -1) {
      FUN_00531f30();
      *(undefined4 *)(in_stack_00005d09 + 0xe4) = 0;
      FUN_00405d00();
    }
  }
  *(undefined4 *)(in_ECX + 0xa8) = 0;
  *(undefined4 *)(in_ECX + 0xac) = 0;
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xb4) + 1;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xb6) + 1;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xb7) + 1;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xb8) + 1;
    if (DAT_00b19acc != 0) {
      FUN_00589540();
      uVar3 = 0;
      if (in_stack_0000ba26 != 0) {
        do {
          FUN_00589540();
          uVar3 = uVar3 + 1;
        } while (uVar3 < in_stack_0000ba26);
      }
      if (DAT_00b19acc != 0) {
        iVar1 = FUN_0072be50();
        if (iVar1 == 3) {
          DAT_00b19acc = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (in_stack_0001172f & 0xff) + 4;
      }
    }
  }
  if (in_stack_00005d0d != 0) {
    iVar1 = FUN_00746d70();
    if (iVar1 != 0) {
      (**(code **)(**(int **)(in_ECX + 0x28) + 0x2c))();
      uVar2 = FUN_006fb2c0();
      *(undefined4 *)(in_ECX + 0x90) = uVar2;
      return 1;
    }
    *(undefined4 *)(in_ECX + 0x90) = 0;
  }
  return 1;
}



// ?GetDebugText@GameThingWithPos@@QAEPADXZ @ 0x004140e0

char * _GetDebugText_GameThingWithPos__QAEPADXZ(void)

{
  return s_GameThingWithPos_Unknown_008f7c68;
}



// ?GetPower@GameThingWithPos@@UBEMXZ @ 0x00418140

undefined4 _GetPower_GameThingWithPos__UBEMXZ(void)

{
  return 0xf;
}



// ?GetReactionPower@GameThingWithPos@@UAEMXZ @ 0x00418190

undefined4 _GetReactionPower_GameThingWithPos__UAEMXZ(void)

{
  return 0x13;
}



// ?GetImpressiveType@GameThingWithPos@@UAE?AW4IMPRESSIVE_TYPE@@XZ @ 0x00418210

undefined4 _GetImpressiveType_GameThingWithPos__UAE_AW4IMPRESSIVE_TYPE__XZ(void)

{
  return 0x1b;
}



// ?GetCreatureBeliefListType@GameThingWithPos@@UAEIXZ @ 0x0041cc30

undefined4 _GetCreatureBeliefListType_GameThingWithPos__UAEIXZ(void)

{
  return 0xf;
}



// ?GetLife@GameThingWithPos@@UBEMXZ @ 0x0041f030

float10 _GetLife_GameThingWithPos__UBEMXZ(void)

{
  return (float10)1.0;
}



// ?GetCreatureBeliefListType@GameThingWithPos@@UAEIXZ @ 0x0044ffa0

undefined4 _GetCreatureBeliefListType_GameThingWithPos__UAEIXZ(void)

{
  return 4;
}



// ?GetReactionPower@GameThingWithPos@@UAEMXZ @ 0x00453320

undefined4 _GetReactionPower_GameThingWithPos__UAEMXZ(void)

{
  return 0x12;
}



// ?GetOrigin@GameThingWithPos@@UBEIXZ @ 0x004b1f50

undefined4 _GetOrigin_GameThingWithPos__UBEIXZ(void)

{
  return 0x11;
}



// ?IsScriptContainer@GameThingWithPos@@UBE_NXZ @ 0x004b5300

float10 _IsScriptContainer_GameThingWithPos__UBE_NXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x3b4))(0);
  if (iVar1 != 0) {
    return (float10)0.9;
  }
  return (float10)0.4;
}



// ?IsMobileWallHug@GameThingWithPos@@UBE_NXZ @ 0x004b5360

float10 _IsMobileWallHug_GameThingWithPos__UBE_NXZ(void)

{
  return (float10)0.4;
}



// ?IsWorkshop@GameThingWithPos@@UAE_NPAVCreature@@@Z @ 0x004c5300

bool _IsWorkshop_GameThingWithPos__UAE_NPAVCreature___Z(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x48))();
  return iVar1 != 0;
}



// ?IsAggressive@GameThingWithPos@@UAE_NPAVCreature@@@Z @ 0x004c5310

undefined4 _IsAggressive_GameThingWithPos__UAE_NPAVCreature___Z(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x48))();
  if (iVar1 != 0) {
    iVar1 = FUN_00467190();
    if (iVar1 != 0) {
      iVar1 = (**(code **)(*in_ECX + 0x6cc))(iVar1);
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
  return 0;
}



// ?CanBeBroughtHomeByCreature@GameThingWithPos@@UAE_NPAVCreature@@@Z @ 0x004c53d0

undefined4 _CanBeBroughtHomeByCreature_GameThingWithPos__UAE_NPAVCreature___Z(int param_1)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  
  fVar2 = (float10)FUN_006de0a0(in_ECX + 5,param_1 + 0x1200);
  if ((float10)50.0 < fVar2) {
    FUN_007344da();
    iVar1 = (**(code **)(*in_ECX + 0x3c4))();
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*in_ECX + 600))(param_1);
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
  return 0;
}



// ?IsCreatureAvailableForJointActivity@GameThingWithPos@@UAE_NPAVCreature@@@Z @ 0x004c5440

undefined4 _IsCreatureAvailableForJointActivity_GameThingWithPos__UAE_NPAVCreature___Z(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  iVar1 = FUN_005ea110();
  if (iVar1 != 0) {
    return 0;
  }
  uVar2 = (**(code **)(*in_ECX + 0x890))();
  return uVar2;
}



// ?IsToyAwayFromHome@GameThingWithPos@@UAE_NPAVCreature@@@Z @ 0x004c55b0

undefined4 _IsToyAwayFromHome_GameThingWithPos__UAE_NPAVCreature___Z(int *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *in_ECX;
  uint uVar4;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x48))();
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x1c))();
    iVar3 = (**(code **)(*param_1 + 0x1c))();
    if (iVar3 != iVar2) {
      uVar4 = 0;
      do {
        iVar2 = FUN_006d0160(uVar4);
        if (iVar2 != 0) {
          return 1;
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < 0x1e);
    }
  }
  return 0;
}



// ?IsStealableByCreature@GameThingWithPos@@UAE_NPAVCreature@@@Z @ 0x004c5650

bool _IsStealableByCreature_GameThingWithPos__UAE_NPAVCreature___Z(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x3b4))(param_1);
  if (((iVar1 == 0) && (iVar1 = (**(code **)(*in_ECX + 0x49c))(), iVar1 == 0)) &&
     (iVar1 = (**(code **)(*in_ECX + 0xac))(), iVar1 == 0)) {
    return false;
  }
  iVar1 = (**(code **)(*in_ECX + 600))(param_1);
  if (iVar1 == 0) {
    return false;
  }
  uVar2 = (**(code **)(*param_1 + 0x1c))();
  iVar1 = FUN_0058e0b0(in_ECX + 5,uVar2);
  return iVar1 == 0;
}



// ?NothingScareyNearMe@GameThingWithPos@@UBE_NXZ @ 0x004c58a0

void _NothingScareyNearMe_GameThingWithPos__UBE_NXZ(void)

{
  int in_ECX;
  
  FUN_004c58c0(in_ECX + 0x14);
  return;
}



// ?IsTree@GameThingWithPos@@UAE_NPAVCreature@@@Z @ 0x004c5cf0

undefined4 _IsTree_GameThingWithPos__UAE_NPAVCreature___Z(void)

{
  int in_ECX;
  
  if ((0.0 < *(float *)(in_ECX + 0xd0)) && (0.0 < *(float *)(in_ECX + 0xdc))) {
    return 1;
  }
  return 0;
}



// ?IsTree@GameThingWithPos@@UAE_NXZ @ 0x004c5d30

undefined4 _IsTree_GameThingWithPos__UAE_NXZ(void)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_00500020();
  if (fVar1 == (float10)0.0) {
    return 1;
  }
  return 0;
}



// ?IsAFoodPileOutsideStoragePit@GameThingWithPos@@UAE_NPAVCreature@@@Z @ 0x004c5d50

undefined4 _IsAFoodPileOutsideStoragePit_GameThingWithPos__UAE_NPAVCreature___Z(int *param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x890))();
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*param_1 + 0x1c))();
    iVar2 = (**(code **)(*in_ECX + 0x1c))();
    if (iVar2 != iVar1) {
      return 1;
    }
  }
  return 0;
}



// ?IsAWoodPileOutsideStoragePit@GameThingWithPos@@UAE_NPAVCreature@@@Z @ 0x004c5d90

undefined4 _IsAWoodPileOutsideStoragePit_GameThingWithPos__UAE_NPAVCreature___Z(int *param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x890))();
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*param_1 + 0x1c))();
    iVar2 = (**(code **)(*in_ECX + 0x1c))();
    if (iVar2 == iVar1) {
      return 1;
    }
  }
  return 0;
}



// ?IsVillagerBelongingToOtherPlayer@GameThingWithPos@@UAE_NPAVCreature@@@Z @ 0x004c5e90

void _IsVillagerBelongingToOtherPlayer_GameThingWithPos__UAE_NPAVCreature___Z(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x890))();
  return;
}



// ?CanCreatureEatMe@GameThingWithPos@@UAE_NPAVCreature@@@Z @ 0x004c5ea0

undefined4 _CanCreatureEatMe_GameThingWithPos__UAE_NPAVCreature___Z(int *param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  iVar1 = FUN_007344da();
  if (iVar1 != 0) {
    if (*(int *)(param_1[0x59] + 0x18510 + *(int *)(*(int *)(iVar1 + 0x28) + 0x10) * 4) != 0) {
      return 0;
    }
    iVar1 = (**(code **)(*param_1 + 0x1c))();
    if ((((iVar1 != 0) && (iVar1 = (**(code **)(*param_1 + 0x1c))(), *(int *)(iVar1 + 0xf8) == 2))
        && ((*(byte *)((int)param_1 + 0x25) & 4) == 0)) &&
       (iVar1 = (**(code **)(*in_ECX + 0x2c8))(0), iVar1 != 0)) {
      iVar1 = (**(code **)(*param_1 + 0x1c))();
      iVar2 = (**(code **)(*in_ECX + 0x1c))();
      if (iVar2 == iVar1) {
        return 0;
      }
    }
  }
  iVar1 = (**(code **)(*in_ECX + 0x3b4))(param_1);
  if ((iVar1 == 0) && (iVar1 = (**(code **)(*in_ECX + 600))(param_1), iVar1 != 0)) {
    return 1;
  }
  return 0;
}



// ?IsTree@GameThingWithPos@@UAE_NXZ @ 0x004c6090

undefined4 _IsTree_GameThingWithPos__UAE_NXZ(void)

{
  float fVar1;
  int iVar2;
  int *in_ECX;
  float10 fVar3;
  
  iVar2 = FUN_004619d0();
  fVar1 = *(float *)(iVar2 + 0x90);
  fVar3 = (float10)(**(code **)(*in_ECX + 100))();
  if (((fVar3 <= (float10)(fVar1 * 15.0)) && (in_ECX[0x31] != 0)) &&
     (*(int *)(in_ECX[0x31] + 0x70) != 0)) {
    return 1;
  }
  return 0;
}



// ?GetPos@GameThingWithPos@@QAEPAUMapCoords@@XZ @ 0x004e9200

void _GetPos_GameThingWithPos__QAEPAUMapCoords__XZ(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0x14);
  param_1[1] = *(undefined4 *)(in_ECX + 0x18);
  param_1[2] = *(undefined4 *)(in_ECX + 0x1c);
  return;
}



// ?PhysicsEditorCreate@GameThingWithPos@@QAEXH@Z @ 0x004e9220

undefined4 _PhysicsEditorCreate_GameThingWithPos__QAEXH_Z(void)

{
  return 0x50;
}



// ?Get3DSoundPos@GameThingWithPos@@UAEHPAULHPoint@@@Z @ 0x004ea630

undefined4 _Get3DSoundPos_GameThingWithPos__UAEHPAULHPoint___Z(float *param_1)

{
  float fVar1;
  int in_ECX;
  float10 fVar2;
  
  fVar1 = *(float *)(in_ECX + 0x1c);
  fVar2 = (float10)FUN_00760fd0();
  param_1[1] = (float)(fVar2 + (float10)fVar1);
  *param_1 = (float)*(int *)(in_ECX + 0x14) * 0.00015258789;
  param_1[2] = (float)*(int *)(in_ECX + 0x18) * 0.00015258789;
  return 1;
}



// ?SetAffectedByWind@GameThingWithPos@@UAEXH@Z @ 0x004fe480

undefined4 _SetAffectedByWind_GameThingWithPos__UAEXH_Z(void)

{
  return 3;
}



// ?CanBeGivenToTown@GameThingWithPos@@UAE_NPAVCreature@@@Z @ 0x004fe490

bool _CanBeGivenToTown_GameThingWithPos__UAE_NPAVCreature___Z(void)

{
  int in_ECX;
  
  return (*(int *)(in_ECX + 0x28) + -0xbead00) / 0x124 == 0x36;
}



// ?SetPos@GameThingWithPos@@QAEXABUMapCoords@@@Z @ 0x004fe700

undefined4 _SetPos_GameThingWithPos__QAEXABUMapCoords___Z(void)

{
  return 0x10a;
}



// ?GetCreatureBeliefListType@GameThingWithPos@@UAEIXZ @ 0x004fec50

undefined4 _GetCreatureBeliefListType_GameThingWithPos__UAEIXZ(void)

{
  return 0xb;
}



// ?IsAWoodPileOutsideStoragePit@GameThingWithPos@@UAE_NPAVCreature@@@Z @ 0x004fec60

void _IsAWoodPileOutsideStoragePit_GameThingWithPos__UAE_NPAVCreature___Z(undefined4 param_1)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 800))(param_1);
  return;
}



// ?PhysicsEditorCreate@GameThingWithPos@@QAEXH@Z @ 0x004fec70

undefined4 _PhysicsEditorCreate_GameThingWithPos__QAEXH_Z(void)

{
  return 0x32;
}



// ?GetPos@GameThingWithPos@@QAEPAUMapCoords@@XZ @ 0x00500640

undefined4 _GetPos_GameThingWithPos__QAEPAUMapCoords__XZ(int param_1)

{
  int iVar1;
  void *pvVar2;
  int *piVar3;
  int in_ECX;
  int in_stack_0000ba1e;
  uint in_stack_0000ba26;
  
  iVar1 = _GetPos_GameThingWithPos__QAEPAUMapCoords__XZ();
  if (iVar1 == 0) {
    return 0;
  }
  FUN_00533bf0();
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 200) + 4;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xdc) + 4;
  }
  FUN_00531f30();
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x11c) + 4;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xcc) + 1;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xd0) + 4;
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (in_stack_0000ba26 & 0xff) + 4;
    for (; 0 < (int)in_stack_0000ba26; in_stack_0000ba26 = in_stack_0000ba26 - 1) {
      FUN_00531f30();
      if (((in_stack_0000ba1e != 0) && (pvVar2 = operator_new(8), pvVar2 != (void *)0x0)) &&
         (iVar1 = FUN_004ecf30(), iVar1 != 0)) {
        piVar3 = (int *)FUN_004ecf10();
        if (piVar3 == (int *)0x0) {
          *(int *)(in_ECX + 0xd4) = iVar1;
        }
        else {
          *piVar3 = iVar1;
        }
        *(int *)(in_ECX + 0xd8) = *(int *)(in_ECX + 0xd8) + 1;
      }
    }
  }
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xe0) + 1;
  }
  return 1;
}



// ?GetImpressiveIntensity@GameThingWithPos@@UAEMW4IMPRESSIVE_TYPE@@@Z @ 0x005008d0

undefined4 _GetImpressiveIntensity_GameThingWithPos__UAEMW4IMPRESSIVE_TYPE___Z(void)

{
  return 0xe73;
}



// ?PhysicsEditorCreate@GameThingWithPos@@QAEXH@Z @ 0x00508b30

undefined4 _PhysicsEditorCreate_GameThingWithPos__QAEXH_Z(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  byte *pbVar3;
  
  iVar1 = param_1;
  iVar2 = _GetArrivePos_Creche__UAEPAUMapCoords__PAU2__Z(param_1);
  if (iVar2 != 0) {
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0xc4));
    FUN_00531ff0(in_ECX + 200,10);
    FUN_00531ff0(in_ECX + 0xf0,0x14);
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x140));
    pbVar3 = (byte *)(in_ECX + 0x14c);
    param_1 = 0xc;
    do {
      if (DAT_00b19ac8 != 0) {
        iVar2 = FUN_0072be90(pbVar3,0xc,0);
        if (iVar2 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *pbVar3 + 0xc;
      }
      pbVar3 = pbVar3 + 0xc;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
    if (DAT_00b19ac8 != 0) {
      iVar2 = FUN_0072be90((byte *)(in_ECX + 0x1dc),4,0);
      if (iVar2 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x1dc) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar2 = FUN_0072be90((byte *)(in_ECX + 0x1e0),4,0);
        if (iVar2 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x1e0) + 4;
        if (DAT_00b19ac8 != 0) {
          iVar2 = FUN_0072be90((byte *)(in_ECX + 0x1e4),1,0);
          if (iVar2 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x1e4) + 1;
          if (DAT_00b19ac8 != 0) {
            iVar2 = FUN_0072be90((byte *)(in_ECX + 0x1e8),4,0);
            if (iVar2 == 3) {
              DAT_00b19ac8 = 0;
            }
            *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x1e8) + 4;
            if (DAT_00b19ac8 != 0) {
              iVar2 = FUN_0072be90((byte *)(in_ECX + 0x1ec),1,0);
              if (iVar2 == 3) {
                DAT_00b19ac8 = 0;
              }
              *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x1ec) + 1;
              if (DAT_00b19ac8 != 0) {
                iVar2 = FUN_0072be90((byte *)(in_ECX + 0x1f0),4,0);
                if (iVar2 == 3) {
                  DAT_00b19ac8 = 0;
                }
                *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x1f0) + 4;
                if (DAT_00b19ac8 != 0) {
                  iVar2 = FUN_0072be90((byte *)(in_ECX + 500),1,0);
                  if (iVar2 == 3) {
                    DAT_00b19ac8 = 0;
                  }
                  *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 500) + 1;
                  if (DAT_00b19ac8 != 0) {
                    iVar2 = FUN_0072be90((byte *)(in_ECX + 0x1f8),4,0);
                    if (iVar2 == 3) {
                      DAT_00b19ac8 = 0;
                    }
                    *(uint *)(iVar1 + 0x214) =
                         *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x1f8) + 4;
                    if (DAT_00b19ac8 != 0) {
                      iVar2 = FUN_0072be90((byte *)(in_ECX + 0x1fc),4,0);
                      if (iVar2 == 3) {
                        DAT_00b19ac8 = 0;
                      }
                      *(uint *)(iVar1 + 0x214) =
                           *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x1fc) + 4;
                      if (DAT_00b19ac8 != 0) {
                        iVar2 = FUN_0072be90((byte *)(in_ECX + 0x200),4,0);
                        if (iVar2 == 3) {
                          DAT_00b19ac8 = 0;
                        }
                        *(uint *)(iVar1 + 0x214) =
                             *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x200) + 4;
                        if (DAT_00b19ac8 != 0) {
                          iVar2 = FUN_0072be90((byte *)(in_ECX + 0x204),4,0);
                          if (iVar2 == 3) {
                            DAT_00b19ac8 = 0;
                          }
                          *(uint *)(iVar1 + 0x214) =
                               *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x204) + 4;
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
    FUN_0066ee00(in_ECX + 0x208);
    FUN_0066ee00(in_ECX + 0x20c);
    FUN_00604120(in_ECX + 0x210);
    FUN_00604120(in_ECX + 0x211);
    FUN_0066ee00(in_ECX + 0x214);
    FUN_0066ee00(in_ECX + 0x218);
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x21c));
    FUN_006d4d80(in_ECX + 0x220);
    FUN_006d4d80(in_ECX + 0x228);
    FUN_006d4d80(in_ECX + 0x230);
    FUN_006d4d80(in_ECX + 0x238);
    FUN_00531ff0(in_ECX + 0x240,2);
    FUN_00531ff0(in_ECX + 0x248,2);
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x250));
    FUN_00531ff0(in_ECX + 600,0x28);
    FUN_004ebf70(in_ECX + 0x308);
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x254));
    return 1;
  }
  return 0;
}



// ?SetPos@GameThingWithPos@@QAEXABUMapCoords@@@Z @ 0x0052eac0

undefined4 _SetPos_GameThingWithPos__QAEXABUMapCoords___Z(void)

{
  return 0x54;
}



// ?PhysicsEditorCreate@GameThingWithPos@@QAEXH@Z @ 0x0052ec90

undefined4 _PhysicsEditorCreate_GameThingWithPos__QAEXH_Z(void)

{
  return 0x60;
}



// ?PhysicsEditorCreate@GameThingWithPos@@QAEXH@Z @ 0x0052efa0

undefined4 _PhysicsEditorCreate_GameThingWithPos__QAEXH_Z(void)

{
  return 0x51;
}



// ?SetPos@GameThingWithPos@@QAEXABUMapCoords@@@Z @ 0x0052f000

undefined4 _SetPos_GameThingWithPos__QAEXABUMapCoords___Z(void)

{
  return 0x55;
}



// ?SetPos@GameThingWithPos@@QAEXABUMapCoords@@@Z @ 0x0052f050

undefined4 _SetPos_GameThingWithPos__QAEXABUMapCoords___Z(void)

{
  return 0x56;
}



// ?GetCitadel@GameThingWithPos@@UAEPAUCitadel@@XZ @ 0x00531390

undefined4 _GetCitadel_GameThingWithPos__UAEPAUCitadel__XZ(void)

{
  return 0x17;
}



// ?PhysicsEditorCreate@GameThingWithPos@@QAEXH@Z @ 0x005313f0

undefined4 _PhysicsEditorCreate_GameThingWithPos__QAEXH_Z(void)

{
  return 0x80;
}



// ?PhysicsEditorCreate@GameThingWithPos@@QAEXH@Z @ 0x00531650

undefined4 _PhysicsEditorCreate_GameThingWithPos__QAEXH_Z(void)

{
  return 0x2b;
}



// ?PhysicsEditorCreate@GameThingWithPos@@QAEXH@Z @ 0x005317c0

undefined4 _PhysicsEditorCreate_GameThingWithPos__QAEXH_Z(void)

{
  return 0x31;
}



// ?IsAnimate@GameThingWithPos@@UAE_NXZ @ 0x005317e0

float10 _IsAnimate_GameThingWithPos__UAE_NXZ(void)

{
  int in_ECX;
  
  return (float10)*(int *)(in_ECX + 0xe4);
}



// ?ToBeDeleted@GameThingWithPos@@UAEXH@Z @ 0x0053eaf0

void _ToBeDeleted_GameThingWithPos__UAEXH_Z(undefined4 param_1)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x1a4))(param_1);
  _ToBeDeleted_GameThing__UAEXH_Z(param_1);
  return;
}



// ?GetPower@GameThingWithPos@@UBEMXZ @ 0x0053eb10

float10 _GetPower_GameThingWithPos__UBEMXZ(void)

{
  return (float10)1.0;
}



// ?GetUpdateOfBoredomValue@GameThingWithPos@@UAEMPAUReaction@@PAV1@@Z @ 0x0053eb60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 _GetUpdateOfBoredomValue_GameThingWithPos__UAEMPAUReaction__PAV1__Z(void)

{
  return (float10)_DAT_00b79f18;
}



// ?GetMovementDirection@GameThingWithPos@@UAEXPAULHPoint@@@Z @ 0x0053eba0

void _GetMovementDirection_GameThingWithPos__UAEXPAULHPoint___Z(undefined4 *param_1)

{
  int *in_ECX;
  
  if ((*(byte *)(in_ECX + 9) & 0x40) != 0) {
    (**(code **)(*in_ECX + 0x16c))(param_1);
    return;
  }
  param_1[2] = 0;
  param_1[1] = 0;
  *param_1 = 0;
  return;
}



// ?GetPhysicsMovementDirection@GameThingWithPos@@UAEXPAULHPoint@@@Z @ 0x0053ebd0

void _GetPhysicsMovementDirection_GameThingWithPos__UAEXPAULHPoint___Z(undefined4 *param_1)

{
  param_1[2] = 0;
  param_1[1] = 0;
  *param_1 = 0;
  return;
}



// ?IsInteractable@GameThingWithPos@@UAE_NXZ @ 0x0053ebf0

bool _IsInteractable_GameThingWithPos__UAE_NXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x2c))();
  return iVar1 != 0;
}



// ?CanBeThrownByPlayer@GameThingWithPos@@UBE_NXZ @ 0x0053ec00

undefined4 _CanBeThrownByPlayer_GameThingWithPos__UBE_NXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x470))();
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*in_ECX + 0x474))();
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*in_ECX + 0x478))();
      if (iVar1 == 0) {
        return 0;
      }
    }
  }
  return 1;
}



// ?ForDrawFXGetVertexPos@GameThingWithPos@@UAEXHPAULHPoint@@@Z @ 0x0053ec40

undefined1 _ForDrawFXGetVertexPos_GameThingWithPos__UAEXHPAULHPoint___Z(void)

{
  return 0;
}



// ?GetDistanceFromObject@GameThingWithPos@@UBEMPAUMapCoords@@@Z @ 0x0053ec50

float10 _GetDistanceFromObject_GameThingWithPos__UBEMPAUMapCoords___Z(undefined4 param_1)

{
  int *in_ECX;
  float10 fVar1;
  float10 fVar2;
  
  fVar1 = (float10)FUN_006de0a0(in_ECX + 5,param_1);
  fVar2 = (float10)(**(code **)(*in_ECX + 0x60))();
  return (float10)(float)fVar1 - fVar2;
}



// ?GetPSysBeamTargetPos@GameThingWithPos@@UAEXPAULHPoint@@@Z @ 0x0053ec80

void _GetPSysBeamTargetPos_GameThingWithPos__UAEXPAULHPoint___Z(undefined4 *param_1)

{
  undefined4 *puVar1;
  int *in_ECX;
  float10 fVar2;
  undefined1 auStack_c [12];
  
  puVar1 = (undefined4 *)FUN_005c0400(auStack_c);
  *param_1 = *puVar1;
  param_1[1] = puVar1[1];
  param_1[2] = puVar1[2];
  fVar2 = (float10)(**(code **)(*in_ECX + 0x42c))();
  param_1[1] = (float)(fVar2 * (float10)0.5 + (float10)(float)param_1[1]);
  return;
}



// ?UseFootpathIfNecessary@GameThingWithPos@@QAEXPAVLiving@@ABUMapCoords@@E@Z @ 0x0053ecf0

void _UseFootpathIfNecessary_GameThingWithPos__QAEXPAVLiving__ABUMapCoords__E_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x74))();
  if (iVar1 != 0) {
    (**(code **)(*in_ECX + 0x74))(param_1,param_2,param_3);
    FUN_0050b120(param_1,param_2,param_3,in_ECX);
    return;
  }
  FUN_005b0e40(param_2,param_3);
  return;
}



// ?CalculateWhereIWillBeAfterNSeconds@GameThingWithPos@@UAEXMPAULHPoint@@@Z @ 0x0053ed40

void _CalculateWhereIWillBeAfterNSeconds_GameThingWithPos__UAEXMPAULHPoint___Z
               (undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined1 auStack_c [12];
  
  puVar1 = (undefined4 *)FUN_005c0400(auStack_c);
  *param_2 = *puVar1;
  param_2[1] = puVar1[1];
  param_2[2] = puVar1[2];
  return;
}



// ?Save@GameThingWithPos@@UAEXPAUGameOSFile@@@Z @ 0x0053ed70

undefined4 _Save_GameThingWithPos__UAEXPAUGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_0053e8e0(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x14),0xc,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x14) + 0xc;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90((byte *)(in_ECX + 0x24),2,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x24) + 2;
      }
    }
    return 1;
  }
  return 0;
}



// ?Load@GameThingWithPos@@QAEIAAVGameOSFile@@@Z @ 0x0053ee20

undefined4 _Load_GameThingWithPos__QAEIAAVGameOSFile___Z(int param_1)

{
  ushort *puVar1;
  int iVar2;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar2 = FUN_0053e9f0(param_1);
  if (iVar2 != 0) {
    if (DAT_00b19acc != 0) {
      iVar2 = FUN_0072be50((byte *)(in_ECX + 0x14),0xc,0,unaff_ESI,unaff_EDI,unaff_EBX);
      if (iVar2 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x14) + 0xc;
    }
    puVar1 = (ushort *)(in_ECX + 0x24);
    if (DAT_00b19acc != 0) {
      iVar2 = FUN_0072be50();
      if (iVar2 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)puVar1 + 2;
    }
    *puVar1 = *puVar1 & 0xfeff;
    if ((*puVar1 & 1) != 0) {
      *puVar1 = *puVar1 & 0xfffe;
    }
    return 1;
  }
  return 0;
}



// ?GetSpellCastPos@GameThingWithPos@@UAEXPAUMapCoords@@@Z @ 0x0053eef0

void _GetSpellCastPos_GameThingWithPos__UAEXPAUMapCoords___Z(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0x14);
  param_1[1] = *(undefined4 *)(in_ECX + 0x18);
  param_1[2] = *(undefined4 *)(in_ECX + 0x1c);
  return;
}



// ?GetReactionPower@GameThingWithPos@@UAEMXZ @ 0x005badf0

undefined4 _GetReactionPower_GameThingWithPos__UAEMXZ(void)

{
  return 0xd;
}



// ?GetOrigin@GameThingWithPos@@UBEIXZ @ 0x005c39e0

int _GetOrigin_GameThingWithPos__UBEIXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x1f0))();
  return (-(uint)(iVar1 != 0) & 0xfffffff9) + 0x13;
}



// ?IsLiving@GameThingWithPos@@UBE_NXZ @ 0x005c3d90

undefined4 _IsLiving_GameThingWithPos__UBE_NXZ(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x28) + 0x2c))();
  if ((0x18e < iVar1) && (iVar1 < 0x194)) {
    return 1;
  }
  return 0;
}



// ?IsLiving@GameThingWithPos@@UBE_NPAVCreature@@@Z @ 0x005c3dc0

bool _IsLiving_GameThingWithPos__UBE_NPAVCreature___Z(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x28) + 0x2c))();
  return iVar1 == 399;
}



// ?IsSpellIcon@GameThingWithPos@@UBE_NXZ @ 0x005c3e00

bool _IsSpellIcon_GameThingWithPos__UBE_NXZ(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x28) + 0x2c))();
  return iVar1 == 0x191;
}



// ?IsCreatureWhoSeemsFriendly@GameThingWithPos@@UBE_NPAVCreature@@@Z @ 0x005c3e80

undefined4 _IsCreatureWhoSeemsFriendly_GameThingWithPos__UBE_NPAVCreature___Z(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x28) + 0x2c))();
  if ((iVar1 != 0x38) && ((iVar1 < 0x51 || (0x52 < iVar1)))) {
    return 0;
  }
  return 1;
}



// ?GetDefaultSpeedInMetresPerSecond@GameThingWithPos@@UAEMXZ @ 0x00678a40

void _GetDefaultSpeedInMetresPerSecond_GameThingWithPos__UAEMXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = __ftol();
  in_ECX[0x39] = iVar1;
  (**(code **)(*in_ECX + 0x144))((float)in_ECX[0x3a]);
  return;
}



// ?GetPos@GameThingWithPos@@QAEPAUMapCoords@@XZ @ 0x00678a70

undefined4 _GetPos_GameThingWithPos__QAEPAUMapCoords__XZ(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _GetPos_GameThingWithPos__QAEPAUMapCoords__XZ(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0xe4),4,0,unaff_EDI,unaff_ESI,unaff_EBX);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xe4) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xe8) + 4;
    }
    return 1;
  }
  return 0;
}



// ?IsSpellSeed@GameThingWithPos@@UBE_NXZ @ 0x006820e0

undefined4 _IsSpellSeed_GameThingWithPos__UBE_NXZ(void)

{
  int *in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 100))();
  if (fVar1 <= (float10)3.6) {
    return 1;
  }
  return 0;
}



// ?SetAffectedByWind@GameThingWithPos@@UAEXH@Z @ 0x00682800

undefined4 _SetAffectedByWind_GameThingWithPos__UAEXH_Z(void)

{
  return 0x21;
}



// ?GetImpressiveType@GameThingWithPos@@UAE?AW4IMPRESSIVE_TYPE@@XZ @ 0x006bcff0

undefined4 _GetImpressiveType_GameThingWithPos__UAE_AW4IMPRESSIVE_TYPE__XZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x80) + 0x184);
}



// ?IsSpellSeed@GameThingWithPos@@UBE_NXZ @ 0x006c97a0

undefined4 _IsSpellSeed_GameThingWithPos__UBE_NXZ(void)

{
  char cVar1;
  int *in_ECX;
  
  cVar1 = (**(code **)(*in_ECX + 0x8d0))(0);
  if (cVar1 == '\0') {
    cVar1 = (**(code **)(*in_ECX + 0x8d0))(1);
    if (cVar1 == '\0') {
      return 0;
    }
  }
  return 1;
}



// ?SetPos@GameThingWithPos@@QAEXABUMapCoords@@@Z @ 0x006c99c0

undefined4 _SetPos_GameThingWithPos__QAEXABUMapCoords___Z(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _GetArrivePos_Creche__UAEPAUMapCoords__PAU2__Z(param_1);
  if (iVar1 != 0) {
    FUN_00531ff0(in_ECX + 0xc4,1);
    FUN_00531ff0(in_ECX + 200,5);
    return 1;
  }
  return 0;
}



// ?GetPos@GameThingWithPos@@QAEPAUMapCoords@@XZ @ 0x006cb700

undefined4 _GetPos_GameThingWithPos__QAEPAUMapCoords__XZ(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _GetPos_GameThingWithPos__QAEPAUMapCoords__XZ(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0xc4),0xc,0,unaff_EDI,unaff_ESI,unaff_EBX);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xc4) + 0xc;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xd0) + 0xc;
    }
    return 1;
  }
  return 0;
}



// ?GetPos@GameThingWithPos@@QAEPAUMapCoords@@XZ @ 0x006cc740

void _GetPos_GameThingWithPos__QAEPAUMapCoords__XZ(void)

{
  _ResolveLoad_Object__UAEXXZ();
  FUN_006cc030();
  return;
}



// ?GetReactionPower@GameThingWithPos@@UAEMXZ @ 0x006cccb0

undefined4 _GetReactionPower_GameThingWithPos__UAEMXZ(void)

{
  return 0x28;
}



// ?GetPos@GameThingWithPos@@QAEPAUMapCoords@@XZ @ 0x006d6740

undefined4 _GetPos_GameThingWithPos__QAEPAUMapCoords__XZ(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _GetPos_GameThingWithPos__QAEPAUMapCoords__XZ(param_1);
  if (iVar1 != 0) {
    FUN_00531f30(in_ECX + 0xcc);
    FUN_00532060(in_ECX + 0xd0);
    return 1;
  }
  return 0;
}



// ?GetCreatureBeliefListType@GameThingWithPos@@UAEIXZ @ 0x006d6780

void _GetCreatureBeliefListType_GameThingWithPos__UAEIXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  _ResolveLoad_Object__UAEXXZ();
  iVar1 = (**(code **)(*in_ECX + 0xd4))();
  if (iVar1 != 0) {
    FUN_00642970();
  }
  return;
}



// ?GetSpeedInMetres@GameThingWithPos@@UBEMXZ @ 0x006da0c0

float10 _GetSpeedInMetres_GameThingWithPos__UBEMXZ(void)

{
  return (float10)0.0;
}



// ?GetPos@GameThingWithPos@@QAEPAUMapCoords@@XZ @ 0x007024c0

undefined4 _GetPos_GameThingWithPos__QAEPAUMapCoords__XZ(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _GetPos_GameThingWithPos__QAEPAUMapCoords__XZ(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0xc4),4,0,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xc4) + 4;
    }
    return 1;
  }
  return 0;
}



// ?IsReadyForNewScriptAction@GameThingWithPos@@UBE_NXZ @ 0x00705420

float10 _IsReadyForNewScriptAction_GameThingWithPos__UBE_NXZ(void)

{
  int in_ECX;
  float10 fVar1;
  
  if (*(int *)(in_ECX + 0xa0) == 0) {
    return (float10)0.0;
  }
  fVar1 = (float10)FUN_004ea480();
  if ((float10)1.0 < fVar1) {
    return (float10)1.0;
  }
  fVar1 = (float10)FUN_004ea480();
  return fVar1;
}



// ?ForDrawFXGetNumVertices@GameThingWithPos@@UAEHXZ @ 0x00705460

float10 _ForDrawFXGetNumVertices_GameThingWithPos__UAEHXZ(void)

{
  int in_ECX;
  float10 fVar1;
  
  if (*(int *)(in_ECX + 0xa0) == 0) {
    return (float10)0.0;
  }
  fVar1 = (float10)(uint)(*(int *)(in_ECX + 200) - *(int *)(*(int *)(in_ECX + 0xa0) + 0x90)) *
          (float10)0.01;
  if ((float10)1.0 < fVar1) {
    fVar1 = (float10)1.0;
  }
  return fVar1;
}



// ?PhysicsEditorCreate@GameThingWithPos@@QAEXH@Z @ 0x00705dd0

void _PhysicsEditorCreate_GameThingWithPos__QAEXH_Z(undefined4 *param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = 0;
  uStack_8 = 0;
  uStack_4 = 0;
  iVar1 = FUN_00705db0(&uStack_c);
  if (iVar1 != 1) {
    FUN_005bf950(in_ECX + 0x14);
  }
  *param_1 = uStack_c;
  param_1[1] = uStack_8;
  param_1[2] = uStack_4;
  return;
}



// ?GetImpressiveValue@GameThingWithPos@@UAEMPAULiving@@PAUReaction@@@Z @ 0x007075f0

float10 _GetImpressiveValue_GameThingWithPos__UAEMPAULiving__PAUReaction___Z(void)

{
  return (float10)0.0;
}



// ?GetOrigin@GameThingWithPos@@UBEIXZ @ 0x00767b60

undefined4 _GetOrigin_GameThingWithPos__UBEIXZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x80);
}



