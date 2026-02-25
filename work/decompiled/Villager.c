// Decompiled functions for class: Villager
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetTeamForChessGame@Villager@@UAEIXZ @ 0x004176b0

undefined4 _GetTeamForChessGame_Villager__UAEIXZ(undefined4 param_1)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  int in_ECX;
  float10 fVar4;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined1 auStack_18 [12];
  undefined1 auStack_c [12];
  
  FUN_006dea00(*(undefined2 *)(*(int *)(in_ECX + 0x28) + 0x220));
  uVar2 = __ftol();
  fVar4 = (float10)FUN_006dea50(uVar2);
  fVar1 = (float)fVar4;
  uVar2 = FUN_006de6c0(auStack_18,*(short *)(in_ECX + 0x5c) + 0x200U & 0x7ff,fVar1);
  FUN_005c1360(&uStack_24,uVar2);
  fVar4 = (float10)FUN_006de0a0(param_1,&uStack_24);
  if ((float10)fVar1 < fVar4) {
    uVar2 = FUN_006de6c0(auStack_18,*(short *)(in_ECX + 0x5c) - 0x200U & 0x7ff,fVar1);
    puVar3 = (undefined4 *)FUN_005c1360(auStack_c,uVar2);
    uStack_24 = *puVar3;
    uStack_20 = puVar3[1];
    uStack_1c = puVar3[2];
    fVar4 = (float10)FUN_006de0a0(param_1,&uStack_24);
    if ((float10)fVar1 < fVar4) {
      return 1;
    }
  }
  return 0;
}



// ?GetHowMuchCreatureWantsToLookAtMe@Villager@@UAEMXZ @ 0x004b5350

float10 _GetHowMuchCreatureWantsToLookAtMe_Villager__UAEMXZ(void)

{
  return (float10)0.5;
}



// ?IsDoingSomethingInteresting@Villager@@UAEIPAVCreature@@@Z @ 0x004c5000

undefined4 _IsDoingSomethingInteresting_Villager__UAEIPAVCreature___Z(void)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = FUN_005b0da0();
  if (*(int *)(&DAT_00cdabf0 + (uVar1 & 0xff) * 0x114) != 6) {
    iVar2 = FUN_004c3f50(0,*(int *)(&DAT_00cdabf0 + (uVar1 & 0xff) * 0x114));
    if (iVar2 == 0) {
      return 1;
    }
  }
  return 0;
}



// ?DoesVillagerBelongToATownWhichIsAlreadyImpressed@Villager@@UAEIPAVCreature@@@Z @ 0x004c52c0

undefined4
_DoesVillagerBelongToATownWhichIsAlreadyImpressed_Villager__UAEIPAVCreature___Z(int param_1)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  
  iVar1 = (**(code **)(*in_ECX + 0x48))();
  if ((iVar1 != 0) && (*(int *)(param_1 + 0x1070) != 0)) {
    fVar2 = (float10)FUN_00430ba0(*(int *)(param_1 + 0x1070));
    if ((float10)0.5 < fVar2) {
      return 1;
    }
  }
  return 0;
}



// ?IsVillagerInTownWithoutManyBreeders@Villager@@UAEIPAVCreature@@@Z @ 0x004c5920

undefined4 _IsVillagerInTownWithoutManyBreeders_Villager__UAEIPAVCreature___Z(int param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  if ((((param_1 == 0) || (0.0 <= *(float *)(*(int *)(param_1 + 0x164) + 0x2a34))) ||
      (*(int *)(*(int *)(param_1 + 0x164) + 0x1c38) != 0)) &&
     ((~*(ushort *)(in_ECX + 9) & 0x400) != 0)) {
    iVar1 = (**(code **)(*in_ECX + 0x2c))();
    if (iVar1 != 0) {
      iVar1 = (**(code **)(*in_ECX + 0xaf4))();
      if (iVar1 == 0) {
        iVar1 = (**(code **)(*in_ECX + 0x4a0))();
        if (iVar1 == 0) {
          iVar1 = (**(code **)(*in_ECX + 0xaf0))();
          if (iVar1 == 0) {
            iVar1 = (**(code **)(*in_ECX + 0x48))();
            if ((iVar1 != 0) && ((*(ushort *)(in_ECX + 0x38) & 0x200) == 0)) {
              iVar2 = (**(code **)(*in_ECX + 0xaf4))();
              if ((iVar2 == 0) && (*(byte *)(iVar1 + 0x6d5) < 3)) {
                return 1;
              }
            }
          }
        }
      }
    }
  }
  return 0;
}



// ?IsVillagerNotWorshipping@Villager@@UAEIPAVCreature@@@Z @ 0x004c5ad0

bool _IsVillagerNotWorshipping_Villager__UAEIPAVCreature___Z(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x974))();
  return iVar1 == 0;
}



// ?IsVillagerWhoHasNotBeenImpressedRecently@Villager@@UAEIPAVCreature@@@Z @ 0x004c5c40

undefined4 _IsVillagerWhoHasNotBeenImpressedRecently_Villager__UAEIPAVCreature___Z(int param_1)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  
  fVar2 = (float10)FUN_006de0a0(param_1 + 0x14,in_ECX + 5);
  if (fVar2 < (float10)200.0) {
    iVar1 = (**(code **)(*in_ECX + 0x48))();
    if (*(int *)(param_1 + 0x10f8) != iVar1) {
      return 1;
    }
  }
  return 0;
}



// ?IsVillagerWhoHasNotBeenDancedWithRecently@Villager@@UAEIPAVCreature@@@Z @ 0x004c5c90

undefined4 _IsVillagerWhoHasNotBeenDancedWithRecently_Villager__UAEIPAVCreature___Z(int param_1)

{
  int in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)FUN_006de0a0(param_1 + 0x14,in_ECX + 0x14);
  if (fVar1 < (float10)200.0) {
    return 1;
  }
  return 0;
}



// ?CanBeHealedByCreature@Villager@@UAEIPAVCreature@@@Z @ 0x004c5fa0

undefined4 _CanBeHealedByCreature_Villager__UAEIPAVCreature___Z(void)

{
  int *in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 0x11c))();
  if (fVar1 <= (float10)0.7) {
    return 1;
  }
  return 0;
}



// ?IsVillagerFarFromHome@Villager@@UAEIPAVCreature@@@Z @ 0x004c6050

undefined4 _IsVillagerFarFromHome_Villager__UAEIPAVCreature___Z(void)

{
  int iVar1;
  int in_ECX;
  float10 fVar2;
  
  iVar1 = FUN_006e1ce0();
  if (iVar1 != 0) {
    fVar2 = (float10)FUN_006de0a0(iVar1 + 0x14,in_ECX + 0x14);
    if ((float10)40.0 < fVar2) {
      return 1;
    }
  }
  return 0;
}



// ?GetCreatureMimicType@Villager@@UAEIXZ @ 0x004cb770

undefined1 _GetCreatureMimicType_Villager__UAEIXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0xaf4))();
  if (iVar1 != 0) {
    return 2;
  }
  return *(int *)(in_ECX[10] + 0x1f8) != 0;
}



// ?IsPlayingFootball@Villager@@UAEIPAVCreature@@@Z @ 0x00508640

undefined4 _IsPlayingFootball_Villager__UAEIPAVCreature___Z(void)

{
  uint uVar1;
  int *in_ECX;
  int iVar2;
  
  uVar1 = (**(code **)(*in_ECX + 0xb00))();
  iVar2 = (uVar1 & 0xff) * 0x90;
  if ((((*(code **)(&DAT_00c2a2e8 + iVar2) == FUN_006f1aa0) &&
       (*(int *)(&DAT_00c2a2ec + iVar2) == 0)) && (*(int *)(&DAT_00c2a2f0 + iVar2) == 0)) &&
     (*(int *)(&DAT_00c2a2f4 + iVar2) == 0)) {
    return 1;
  }
  return 0;
}



// ?IsPlayingFootballAndMySideHasJustScored@Villager@@UAEIPAVCreature@@@Z @ 0x00508690

undefined4
_IsPlayingFootballAndMySideHasJustScored_Villager__UAEIPAVCreature___Z(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x364))(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_006e1a90();
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x1fc) == 3)) {
      iVar2 = FUN_004663d0();
      if (*(int *)(iVar1 + 0x300) == iVar2) {
        return 1;
      }
    }
  }
  return 0;
}



// ?IsPlayingFootballAndOtherSideHasJustScored@Villager@@UAEIPAVCreature@@@Z @ 0x005086e0

undefined4
_IsPlayingFootballAndOtherSideHasJustScored_Villager__UAEIPAVCreature___Z(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x364))(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_006e1a90();
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x1fc) == 3)) {
      iVar2 = FUN_004663d0();
      if (*(uint *)(iVar1 + 0x300) == (uint)(iVar2 == 0)) {
        return 1;
      }
    }
  }
  return 0;
}



// ?IsFoodSpeedUp@Villager@@UAE_NXZ @ 0x0052e160

bool _IsFoodSpeedUp_Villager__UAE_NXZ(void)

{
  int in_ECX;
  
  return *(char *)(in_ECX + 0xf0) != '\0';
}



// ?IsTouching@Villager@@UBE_NPAVObject@@M@Z @ 0x0052e170

void _IsTouching_Villager__UBE_NPAVObject__M_Z(undefined4 param_1,undefined4 param_2)

{
  _IsTouching_Object__UAE_NPAV1_M_Z(param_1,param_2);
  return;
}



// ?GetMesh@Villager@@UBEHXZ @ 0x0052e190

undefined4 _GetMesh_Villager__UBEHXZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x28) + 0x214);
}



// ?GetDetailMesh@Villager@@UAEHH@Z @ 0x0052e1a0

undefined4 _GetDetailMesh_Villager__UAEHH_Z(int param_1)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x28) + 0x210 + param_1 * 4);
}



// ?IsScriptState@Villager@@UBE_NW4VILLAGER_STATES@@@Z @ 0x0052e1e0

undefined4 _IsScriptState_Villager__UBE_NW4VILLAGER_STATES___Z(int param_1)

{
  return *(undefined4 *)(&DAT_00cdab2c + param_1 * 0x114);
}



// ?CanBePickedUp@Villager@@UAE_NXZ @ 0x0052e200

uint _CanBePickedUp_Villager__UAE_NXZ(void)

{
  int in_ECX;
  
  if ((*(byte *)(in_ECX + 0xe0) & 4) != 0) {
    return 0;
  }
  return ((ushort)~*(ushort *)(in_ECX + 0x24) & 0x2000) >> 0xd;
}



// ?CanBeImpressedByCreature@Villager@@UAEIPAVCreature@@@Z @ 0x0052e230

bool _CanBeImpressedByCreature_Villager__UAEIPAVCreature___Z(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x974))();
  return iVar1 == 0;
}



// ?CanBeHelpedByCreature@Villager@@UAEIPAVCreature@@@Z @ 0x0052e240

void _CanBeHelpedByCreature_Villager__UAEIPAVCreature___Z(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x628))();
  return;
}



// ?IsMaleVillager@Villager@@UAEIXZ @ 0x0052e250

bool _IsMaleVillager_Villager__UAEIXZ(void)

{
  int in_ECX;
  
  return *(int *)(*(int *)(in_ECX + 0x28) + 0x1f8) == 0;
}



// ?IsFemaleVillager@Villager@@UAEIXZ @ 0x0052e270

bool _IsFemaleVillager_Villager__UAEIXZ(void)

{
  int in_ECX;
  
  return *(int *)(*(int *)(in_ECX + 0x28) + 0x1f8) == 1;
}



// ?IsAChild@Villager@@UAEIXZ @ 0x0052e290

bool _IsAChild_Villager__UAEIXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0xaf4))();
  return iVar1 == 1;
}



// ?GetDeathReason@Villager@@UAE?AW4DEATH_REASON@@XZ @ 0x0052e2a0

undefined1 _GetDeathReason_Villager__UAE_AW4DEATH_REASON__XZ(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x110);
}



// ?InitialisePhysicsFromHand@Villager@@UAEIAAULHPoint@@0PAVGInterfaceStatus@@PAVObject@@H@Z @ 0x005ae640

int _InitialisePhysicsFromHand_Villager__UAEIAAULHPoint__0PAVGInterfaceStatus__PAVObject__H_Z
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _InitialisePhysicsFromHand_Living__UAEIAAULHPoint__0PAVGInterfaceStatus__PAVObject__H_Z
                    (param_1,param_2,param_3,param_4,param_5);
  if ((iVar1 == 0) || (((*(byte *)(iVar1 + 0x1d8) & 8) == 0 && (*(int *)(iVar1 + 0x18) == in_ECX))))
  {
    FUN_006e56e0(0,*(undefined4 *)(in_ECX + 0x104),0);
  }
  return iVar1;
}



// ?InitialisePhysics@Villager@@UAEIABULHPoint@@0PAVObject@@_NPAVGInterfaceStatus@@@Z @ 0x005ae6a0

undefined4
_InitialisePhysics_Villager__UAEIABULHPoint__0PAVObject___NPAVGInterfaceStatus___Z
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  FUN_006e0aa0(param_2,param_3,0);
  _InitialisePhysics_Living__UAEIABULHPoint__0PAVObject___NPAVGInterfaceStatus___Z
            (param_1,param_2,param_3,param_4,param_5,param_6);
  return param_1;
}



// ?SetUpPhysOb@Villager@@UAEXPAUPhysOb@@@Z @ 0x005ae6e0

void _SetUpPhysOb_Villager__UAEXPAUPhysOb___Z(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int iVar8;
  undefined4 *puVar9;
  int *in_ECX;
  float *pfVar10;
  float10 fVar11;
  float10 fVar12;
  float10 fVar13;
  undefined4 uVar14;
  float fStack_34;
  float fStack_2c;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_14;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  fVar11 = (float10)(**(code **)(*in_ECX + 0x638))();
  fStack_34 = (float)fVar11;
  if (fVar11 < (float10)0.01) {
    fStack_34 = 0.01;
  }
  uVar14 = 1;
  iVar8 = (**(code **)(*in_ECX + 0x788))(1);
  FUN_00759e40(fStack_34,&DAT_00be7740 + iVar8 * 6,uVar14);
  *(undefined4 *)(param_1 + 0x154) = 0xc;
  iVar8 = FUN_00746d70(0x3c0,s_C__dev_black_LivingProjectile_cp_00b207a4,0x86);
  if (iVar8 == 0) {
    iVar8 = 0;
  }
  else {
    fStack_34 = 1.68156e-44;
    do {
      _GetPtr_Object__UAEPAV1_XZ();
      fStack_34 = (float)((int)fStack_34 + -1);
    } while (fStack_34 != 0.0);
  }
  *(int *)(param_1 + 0x15c) = iVar8;
  fVar11 = (float10)(**(code **)(*in_ECX + 0x120))();
  fVar12 = (float10)(**(code **)(*in_ECX + 0x42c))();
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(undefined4 *)(param_1 + 0x100) = 0;
  *(float *)(param_1 + 0xfc) = (float)(fVar12 * (float10)(float)((float10)0.5 / fVar11));
  fVar11 = (float10)(**(code **)(*in_ECX + 0x42c))();
  fVar1 = (float)(fVar11 * (float10)0.5);
  fVar11 = (float10)(**(code **)(*in_ECX + 100))();
  fVar2 = (float)(fVar11 * (float10)0.9);
  fVar12 = fVar11 * (float10)0.32;
  fVar3 = (float)(fVar11 * (float10)0.8);
  fVar4 = (float)fVar12;
  FUN_00402280();
  fVar11 = (float10)fcos((float10)1.5707963705062866);
  puVar9 = *(undefined4 **)(param_1 + 0x15c);
  iVar8 = 0;
  fVar13 = (float10)fsin((float10)1.5707963705062866);
  if (0 < *(int *)(param_1 + 0x154)) {
    pfVar10 = (float *)(puVar9 + 5);
    do {
      *puVar9 = 0;
      pfVar10[-2] = 0.0;
      pfVar10[-3] = 0.0;
      pfVar10[-4] = 0.0;
      switch(iVar8) {
      case 0:
        pfVar10[-1] = fVar3;
        *pfVar10 = fVar1;
        pfVar10[1] = fVar4;
        break;
      case 1:
        *pfVar10 = fVar1;
        pfVar10[-1] = -fVar3;
        goto LAB_005ae958;
      case 2:
        *pfVar10 = fVar1;
        pfVar10[-1] = -fVar3;
        pfVar10[1] = fVar4;
        break;
      case 3:
        pfVar10[-1] = fVar3;
        *pfVar10 = fVar1;
        goto LAB_005ae958;
      case 4:
        pfVar10[-1] = fVar2;
        *pfVar10 = 0.0;
        pfVar10[1] = (float)fVar12;
        break;
      case 5:
        *pfVar10 = 0.0;
        pfVar10[-1] = -fVar2;
        goto LAB_005ae958;
      case 6:
        *pfVar10 = 0.0;
        pfVar10[-1] = -fVar2;
        pfVar10[1] = (float)fVar12;
        break;
      case 7:
        pfVar10[-1] = fVar2;
        *pfVar10 = 0.0;
        goto LAB_005ae958;
      case 8:
        pfVar10[-1] = fVar3;
        *pfVar10 = -fVar1;
        pfVar10[1] = fVar4;
        break;
      case 9:
        pfVar10[-1] = -fVar3;
        goto LAB_005ae94c;
      case 10:
        pfVar10[1] = fVar4;
        pfVar10[-1] = -fVar3;
        *pfVar10 = -fVar1;
        break;
      case 0xb:
        pfVar10[-1] = fVar3;
LAB_005ae94c:
        *pfVar10 = -fVar1;
LAB_005ae958:
        pfVar10[1] = -(float)fVar12;
      }
      fVar5 = pfVar10[-1];
      fVar6 = *pfVar10;
      fVar7 = pfVar10[1];
      pfVar10[-1] = fVar5 * (float)fVar11 + fStack_24 * fVar6 + (float)-fVar13 * fVar7 + fStack_c;
      *pfVar10 = fStack_2c * fVar5 + fStack_20 * fVar6 + fStack_14 * fVar7 + fStack_8;
      pfVar10[1] = (float)fVar13 * fVar5 + (float)fVar11 * fVar7 + fStack_1c * fVar6 + fStack_4;
      if (*(float *)(param_1 + 0x150) <=
          SQRT(pfVar10[-1] * pfVar10[-1] + *pfVar10 * *pfVar10 + pfVar10[1] * pfVar10[1])) {
        fVar5 = SQRT(pfVar10[-1] * pfVar10[-1] + *pfVar10 * *pfVar10 + pfVar10[1] * pfVar10[1]);
      }
      else {
        fVar5 = *(float *)(param_1 + 0x150);
      }
      puVar9 = puVar9 + 0x14;
      pfVar10 = pfVar10 + 0x14;
      iVar8 = iVar8 + 1;
      *(float *)(param_1 + 0x150) = fVar5;
    } while (iVar8 < *(int *)(param_1 + 0x154));
  }
  *(undefined4 *)(param_1 + 0x160) = 0x14;
  puVar9 = (undefined4 *)FUN_00746d70(0x2d0,s_C__dev_black_LivingProjectile_cp_00b207a4,0xcc);
  *(undefined4 **)(param_1 + 0x164) = puVar9;
  puVar9[2] = 0;
  *puVar9 = 1;
  puVar9[1] = 2;
  puVar9[9] = 0;
  puVar9[0xb] = 1;
  puVar9[10] = 3;
  puVar9[0x14] = 3;
  puVar9[0x13] = 1;
  puVar9[0x12] = 5;
  puVar9[0x1d] = 3;
  puVar9[0x1c] = 5;
  puVar9[0x1b] = 7;
  puVar9[0x25] = 3;
  puVar9[0x24] = 7;
  puVar9[0x26] = 0;
  puVar9[0x2e] = 7;
  puVar9[0x2f] = 0;
  puVar9[0x2d] = 4;
  puVar9[0x38] = 0;
  puVar9[0x37] = 4;
  puVar9[0x36] = 6;
  puVar9[0x41] = 0;
  puVar9[0x40] = 6;
  puVar9[0x3f] = 2;
  puVar9[0x48] = 6;
  puVar9[0x49] = 2;
  puVar9[0x4a] = 1;
  puVar9[0x53] = 1;
  puVar9[0x52] = 6;
  puVar9[0x51] = 5;
  puVar9[0x5c] = 7;
  puVar9[0x5a] = 9;
  puVar9[0x5b] = 5;
  puVar9[0x65] = 7;
  puVar9[100] = 9;
  puVar9[99] = 0xb;
  puVar9[0x6d] = 7;
  puVar9[0x6c] = 0xb;
  puVar9[0x6e] = 4;
  puVar9[0x75] = 8;
  puVar9[0x76] = 0xb;
  puVar9[0x77] = 4;
  puVar9[0x7f] = 8;
  puVar9[0x80] = 4;
  puVar9[0x7e] = 10;
  puVar9[0x87] = 6;
  puVar9[0x88] = 10;
  puVar9[0x89] = 4;
  puVar9[0x91] = 6;
  puVar9[0x90] = 10;
  puVar9[0x92] = 5;
  puVar9[0x9a] = 10;
  puVar9[0x9b] = 5;
  puVar9[0x99] = 9;
  puVar9[0xa3] = 10;
  puVar9[0xa2] = 0xb;
  puVar9[0xa4] = 9;
  puVar9[0xac] = 10;
  puVar9[0xab] = 8;
  puVar9[0xad] = 0xb;
  FUN_00759eb0();
  *(float *)(param_1 + 0x14c) = *(float *)(param_1 + 0x14c) + *(float *)(param_1 + 0x14c);
  FUN_0075ad90();
  return;
}



// ?EndPhysics@Villager@@UAEXPAVPhysicsObject@@_N@Z @ 0x005af1e0

undefined4 _EndPhysics_Villager__UAEXPAVPhysicsObject___N_Z(float param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  short sVar3;
  float10 fVar4;
  uint unaff_retaddr;
  undefined4 uVar5;
  undefined4 uVar6;
  int *piVar7;
  
  iVar2 = (int)param_1;
  sVar3 = 3;
  if (param_1 == 0.0) goto LAB_005af2f9;
  if (-0.5 <= *(float *)((int)param_1 + 0xd8)) {
    if (*(float *)((int)param_1 + 0xd8) <= 0.5) {
      sVar3 = 0;
      fVar4 = (float10)FUN_00759180((int)param_1 + 0xec);
      fVar4 = (float10)FUN_007591d0((float)(fVar4 + (float10)3.1415927));
      param_1 = (float)fVar4;
      iVar1 = FUN_005f6180();
      if (iVar1 != 0) {
        uVar6 = 0x3dcccccd;
        uVar5 = 1;
        goto LAB_005af2ca;
      }
    }
    else {
      sVar3 = 2;
      fVar4 = (float10)FUN_00759180((int)param_1 + 0xe0);
      fVar4 = (float10)FUN_007591d0((float)(fVar4 + (float10)3.1415927));
      param_1 = (float)fVar4;
      iVar1 = FUN_005f6180();
      if (iVar1 != 0) {
        uVar6 = 0x3f000000;
        uVar5 = 2;
LAB_005af2ca:
        piVar7 = in_ECX + 5;
        FUN_005f6180(uVar5,uVar6,piVar7);
        FUN_004ae9a0(uVar5,uVar6,piVar7);
      }
    }
  }
  else {
    sVar3 = 1;
    fVar4 = (float10)FUN_00759180((int)param_1 + 0xe0);
    param_1 = (float)fVar4;
    iVar1 = FUN_005f6180();
    if (iVar1 != 0) {
      uVar6 = 0x3f000000;
      uVar5 = 2;
      goto LAB_005af2ca;
    }
  }
  (**(code **)(*in_ECX + 0x524))(param_1);
  if ((*(byte *)(iVar2 + 0x1d8) & 8) == 0) {
    *(ushort *)(in_ECX + 0x38) = *(ushort *)(in_ECX + 0x38) & 0xffdf;
  }
LAB_005af2f9:
  uVar5 = _EndPhysics_Object__UAEXPAVPhysicsObject___N_Z(iVar2,param_2);
  *(ushort *)(in_ECX + 0x2d) = *(ushort *)(in_ECX + 0x2d) & 0xffcf | sVar3 << 4;
  in_ECX[7] = 0;
  iVar1 = FUN_005bfb00();
  if (iVar1 == 0) {
    fVar4 = (float10)(**(code **)(*in_ECX + 0x11c))();
    if (fVar4 <= (float10)0.0) {
      if (iVar2 == 0) {
        uVar6 = 0;
      }
      else {
        uVar6 = FUN_005f6180();
      }
      if ((*(byte *)(in_ECX + 0x2d) & 1) == 1) {
        (**(code **)(*in_ECX + 0x8e4))(0xf);
      }
      else {
        FUN_006e0860(5,uVar6,0,1);
      }
      *(ushort *)(in_ECX + 0x2d) = *(ushort *)(in_ECX + 0x2d) & 0xffcf | sVar3 << 4;
      return uVar5;
    }
    if ((*(ushort *)(in_ECX + 0x2d) & 0x400) != 0) {
      FUN_006e2e40();
    }
    (**(code **)(*in_ECX + 0x8e4))(0xb);
    if (((*(ushort *)(in_ECX + 9) & 0x400) != 0) ||
       (*(int *)(&DAT_00cdac04 + (unaff_retaddr & 0xff) * 0x114) != 0)) {
      (**(code **)(*in_ECX + 0x8e4))(unaff_retaddr);
    }
    return uVar5;
  }
  fVar4 = (float10)(**(code **)(*in_ECX + 0x11c))();
  if (fVar4 <= (float10)0.0) {
    iVar1 = (**(code **)(*in_ECX + 0xaf0))();
    if (iVar1 != 0) {
      (**(code **)(*in_ECX + 0x8e4))(0xe);
      *(undefined2 *)(in_ECX + 0x16) = *(undefined2 *)(in_ECX[10] + 0x290);
      return uVar5;
    }
    *(undefined2 *)(in_ECX + 0x16) = 0;
    if (iVar2 == 0) {
      iVar2 = DAT_00c22ca4 + 0x18 + (uint)*(byte *)(DAT_00c22ca4 + 0x201b17) * 0x278;
    }
    else {
      iVar2 = FUN_005f6180();
    }
    FUN_006e0860(6,iVar2,0x3c23d70a,1);
    return uVar5;
  }
  *(undefined2 *)(in_ECX + 0x16) = *(undefined2 *)(in_ECX[10] + 0x39a);
  (**(code **)(*in_ECX + 0x8e4))(0x10);
  return uVar5;
}



// ?CalculateWhereIWillBeAfterNSeconds@Villager@@UAEXMPAULHPoint@@@Z @ 0x005ed7b0

void _CalculateWhereIWillBeAfterNSeconds_Villager__UAEXMPAULHPoint___Z
               (undefined4 param_1,float *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *in_ECX;
  float10 fVar4;
  float10 fVar5;
  float10 extraout_ST0;
  float10 extraout_ST1;
  
  iVar1 = in_ECX[5];
  iVar2 = in_ECX[6];
  fVar4 = (float10)(**(code **)(*in_ECX + 0x42c))();
  fVar5 = (float10)FUN_00760fd0();
  param_2[1] = (float)(fVar5 + (float10)(float)(fVar4 * (float10)0.5));
  *param_2 = (float)iVar1 * 0.00015258789;
  fVar4 = (float10)iVar2 * (float10)0.00015258789;
  param_2[2] = (float)fVar4;
  if (*(int *)(&DAT_00cdab1c + (uint)*(byte *)(in_ECX + 0x23) * 0x114) == 0) {
    uVar3 = __ftol();
    *param_2 = (float)((float10)in_ECX[0x19] * (float10)10.0 * (float10)1.5258789e-05 *
                       (float10)uVar3 + fVar4);
    uVar3 = __ftol();
    param_2[2] = (float)((float10)uVar3 * extraout_ST0 + extraout_ST1);
  }
  return;
}



// ?IsPosValidForTurnAngle@Villager@@UAE_NABUMapCoords@@@Z @ 0x006b67f0

int _IsPosValidForTurnAngle_Villager__UAE_NABUMapCoords___Z(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0x128) * 0x60 + 0x10 + DAT_00cbbdec;
}



// ?CallVirtualFunctionsForCreation@Villager@@UAEXABUMapCoords@@@Z @ 0x006dff90

void _CallVirtualFunctionsForCreation_Villager__UAEXABUMapCoords___Z(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  int *in_ECX;
  int iVar3;
  
  if ((DAT_00cc786c & 1) == 0) {
    DAT_00cc786c = DAT_00cc786c | 1;
    iVar1 = 0x1ff;
    if (*DAT_00d76c64 < 0x200) {
      iVar1 = 0;
    }
    DAT_00cc7868 = DAT_00d76c64[iVar1 + 1];
  }
  _CallVirtualFunctionsForCreation_Living__UAEXABUMapCoords___Z(param_1);
  iVar1 = (**(code **)(*in_ECX + 0x4a0))();
  if (iVar1 == 0) {
    iVar1 = in_ECX[10];
    uVar2 = (**(code **)(*in_ECX + 0x8cc))();
    if (uVar2 < *(uint *)(iVar1 + 0x138)) {
      iVar1 = *(int *)(in_ECX[10] + 0x204);
      if ((iVar1 < 0) || (iVar3 = iVar1, *DAT_00d76c64 <= iVar1)) {
        iVar3 = 0;
      }
      if ((iVar1 < 0) || (*DAT_00d76c64 <= iVar1)) {
        iVar1 = 0;
      }
      (**(code **)(*(int *)in_ECX[0x10] + 0xf4))(DAT_00d76c64[iVar1 + 1],DAT_00d76c64[iVar3 + 1]);
    }
  }
  else {
    (**(code **)(*(int *)in_ECX[0x10] + 0xf4))(DAT_00cc7868,DAT_00cc7868);
  }
  (**(code **)(*(int *)in_ECX[0x10] + 0xb4))();
  (**(code **)(*(int *)in_ECX[0x10] + 0xc4))();
  return;
}



// ?ProcessState@Villager@@UAEIXZ @ 0x006e01e0

undefined4 _ProcessState_Villager__UAEIXZ(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  *(short *)(in_ECX + 0x90) = *(short *)(in_ECX + 0x90) + 1;
  FUN_006e2f30();
  if (*(int *)(&DAT_00c2a348 + (uint)*(byte *)(in_ECX + 0x8c) * 0x90) != 0) {
    (**(code **)(&DAT_00c2a348 + (uint)*(byte *)(in_ECX + 0x8c) * 0x90))();
  }
  if (*(int *)(&DAT_00c2a348 + (uint)*(byte *)(in_ECX + 0x8d) * 0x90) != 0) {
    (**(code **)(&DAT_00c2a348 + (uint)*(byte *)(in_ECX + 0x8d) * 0x90))();
  }
  if ((*(ushort *)(in_ECX + 0xe0) & 0x800) != 0) {
    iVar1 = FUN_005ab3c0(1);
    if (iVar1 != 0) {
      FUN_006e02d0();
    }
    return 1;
  }
  FUN_006e05d0();
  uVar2 = FUN_006e1d10();
  return uVar2;
}



// ?DestroyedByEffect@Villager@@UAEIPAVGPlayer@@M@Z @ 0x006e0540

undefined4 _DestroyedByEffect_Villager__UAEIPAVGPlayer__M_Z(undefined4 param_1,undefined4 param_2)

{
  FUN_006e0860(2,param_1,param_2,1);
  return 1;
}



// ?GetPlayer@Villager@@UAEPAVGPlayer@@XZ @ 0x006e0560

undefined4 _GetPlayer_Villager__UAEPAVGPlayer__XZ(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x48))();
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*in_ECX + 0x48))();
    return *(undefined4 *)(iVar1 + 0x2c);
  }
  return 0;
}



// ?HasSunk@Villager@@UAE_NXZ @ 0x006e0c10

undefined4 _HasSunk_Villager__UAE_NXZ(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *in_ECX;
  undefined4 uVar4;
  undefined4 uVar5;
  
  iVar1 = (**(code **)(*in_ECX + 0x2c))();
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = FUN_005ec980();
  if (iVar1 != 0) {
    piVar2 = (int *)FUN_005ec980();
    iVar1 = (**(code **)(*piVar2 + 0x1c))();
    if (iVar1 != 0) {
      uVar5 = 0;
      uVar4 = 0x15;
      piVar2 = in_ECX;
      uVar3 = FUN_005ec980(0x15);
      FUN_004cb260(uVar3,uVar4,piVar2,uVar5);
    }
  }
  *(undefined2 *)(in_ECX + 0x16) = *(undefined2 *)(in_ECX[10] + 0x39a);
  if ((*(byte *)(in_ECX + 0x2d) & 1) == 1) {
    (**(code **)(*in_ECX + 0x8e4))(0xe);
    *(undefined2 *)(in_ECX + 0x16) = *(undefined2 *)(in_ECX[10] + 0x290);
    return 1;
  }
  (**(code **)(*in_ECX + 0x8e4))(0x10);
  return 1;
}



// ?GetFinalState@Villager@@UBE?AW4VILLAGER_STATES@@XZ @ 0x006e1200

void _GetFinalState_Villager__UBE_AW4VILLAGER_STATES__XZ(undefined4 param_1)

{
  _GetFinalState_Living__UBE_AW4VILLAGER_STATES__XZ(param_1);
  return;
}



// ?InHand@Villager@@UAE_NXZ @ 0x006e1260

undefined4 _InHand_Villager__UAE_NXZ(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x48))();
  if (iVar1 != 0) {
    (**(code **)(*in_ECX + 0x48))();
    iVar1 = FUN_006d9490();
    if (iVar1 != 0) {
      (**(code **)(*in_ECX + 0x8e4))(0xf2);
      return 1;
    }
  }
  if (((*(ushort *)(in_ECX + 0x38) >> 9 & 1) != 0) || ((*(ushort *)(in_ECX + 0x38) & 0x400) != 0)) {
    iVar1 = FUN_006e13c0();
    if (iVar1 == 1) {
      if ((*(byte *)((int)in_ECX + 0xe1) & 4) != 0) {
        *(undefined1 *)((int)in_ECX + 0xf2) = 0;
        return 1;
      }
      if (*(int *)(&DAT_008d1364 + (uint)*(byte *)((int)in_ECX + 0xf2) * 0x1c) == 0) {
        return 1;
      }
      (**(code **)(*in_ECX + 0x1c))(1);
      FUN_0067efc0();
      return 1;
    }
    if ((*(ushort *)(in_ECX + 0x38) & 0x400) != 0) {
      *(undefined1 *)((int)in_ECX + 0xf2) = 0;
      *(ushort *)(in_ECX + 0x38) = *(ushort *)(in_ECX + 0x38) & 63999;
    }
  }
  (**(code **)(*in_ECX + 0x8e4))(0xa3);
  iVar1 = (**(code **)(*in_ECX + 0xaf4))();
  if (iVar1 == 0) {
    iVar1 = FUN_006eecb0();
    if (((iVar1 != 1) && (iVar1 = FUN_006e1380(), iVar1 == 0)) &&
       (iVar1 = FUN_006e3630(), iVar1 == 0)) {
      (**(code **)(*in_ECX + 0x8e4))(0x24);
    }
    return 1;
  }
  uVar2 = FUN_006e73e0();
  return uVar2;
}



// ?SaveObject@Villager@@UAEIAAULHOSFile@@ABUMapCoords@@@Z @ 0x006e16f0

int _SaveObject_Villager__UAEIAAULHOSFile__ABUMapCoords___Z(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *piVar6;
  undefined4 uVar7;
  int *in_ECX;
  char *pcVar8;
  undefined4 uVar9;
  undefined1 auStack_200 [12];
  char acStack_1f4 [200];
  undefined1 auStack_12c [100];
  undefined1 auStack_c8 [100];
  undefined1 auStack_64 [100];
  
  iVar2 = FUN_0053eb80();
  if (iVar2 == 0) {
    return 0;
  }
  if (param_2 != 0) {
    FUN_005c13b0(auStack_200,param_2);
  }
  if (*(int *)(in_ECX[10] + 500) == -1) {
    iVar3 = (**(code **)(*in_ECX + 0x48))();
    if (iVar3 == 0) {
      uVar7 = 0xffffffff;
    }
    else {
      iVar3 = (**(code **)(*in_ECX + 0x48))();
      uVar7 = *(undefined4 *)(iVar3 + 0x5b4);
    }
    iVar3 = in_ECX[10];
    uVar4 = (**(code **)(*in_ECX + 0x8cc))();
    iVar3 = (iVar3 + -0xcc7880) / 0x3a4;
    uVar5 = FUN_005bf290(auStack_12c);
    uVar9 = 0x11;
  }
  else {
    iVar3 = FUN_006e1ce0();
    if ((iVar3 != 0) && (param_2 == 0)) {
      piVar6 = (int *)FUN_006e1ce0();
      (**(code **)(*piVar6 + 0x864))(auStack_200);
      uVar7 = (**(code **)(*in_ECX + 0x8cc))();
      uVar4 = FUN_006e16b0(auStack_c8);
      uVar5 = FUN_005bf290(auStack_64);
      uVar9 = FUN_005bf290(auStack_12c);
      uVar7 = FUN_006ad590(0x12,uVar9,uVar5,uVar4,uVar7);
      FUN_00733e17(acStack_1f4,uVar7);
      iVar3 = -1;
      pcVar8 = acStack_1f4;
      do {
        if (iVar3 == 0) break;
        iVar3 = iVar3 + -1;
        cVar1 = *pcVar8;
        pcVar8 = pcVar8 + 1;
      } while (cVar1 != '\0');
      goto LAB_006e18d6;
    }
    iVar3 = (**(code **)(*in_ECX + 0x48))();
    if (iVar3 == 0) {
      uVar7 = 0xffffffff;
    }
    else {
      iVar3 = (**(code **)(*in_ECX + 0x48))();
      uVar7 = *(undefined4 *)(iVar3 + 0x5b4);
    }
    uVar4 = (**(code **)(*in_ECX + 0x8cc))();
    iVar3 = FUN_006e16b0(auStack_c8);
    uVar5 = FUN_005bf290(auStack_12c);
    uVar9 = 0x10;
  }
  uVar7 = FUN_006ad590(uVar9,uVar7,uVar5,iVar3,uVar4);
  FUN_00733e17(acStack_1f4,uVar7);
  iVar3 = -1;
  pcVar8 = acStack_1f4;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
LAB_006e18d6:
  FUN_006b10c0();
  return iVar2;
}



// ?IsFunctional@Villager@@UAE_NXZ @ 0x006e18f0

undefined4 _IsFunctional_Villager__UAE_NXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x2c))();
  if ((iVar1 == 1) && ((*(byte *)(in_ECX + 0x23) < 0xd || (0xe < *(byte *)(in_ECX + 0x23))))) {
    return 1;
  }
  return 0;
}



// ?IsAvailable@Villager@@UAE_NXZ @ 0x006e1940

undefined4 _IsAvailable_Villager__UAE_NXZ(void)

{
  char cVar1;
  int *in_ECX;
  
  if ((*(byte *)((int)in_ECX + 10) & 1) == 0) {
    cVar1 = (**(code **)(*in_ECX + 0xb00))();
    if (cVar1 != '\x0e') {
      return 1;
    }
  }
  return 0;
}



// ?IsEffectReceiver@Villager@@UAEIPAVEffectValues@@@Z @ 0x006e1960

uint _IsEffectReceiver_Villager__UAEIPAVEffectValues___Z(int param_1)

{
  int iVar1;
  uint uVar2;
  int *in_ECX;
  
  if ((param_1 != 0) && (0.0 < *(float *)(param_1 + 0x14))) {
    iVar1 = (**(code **)(*in_ECX + 0xaf0))();
    return (uint)(iVar1 == 0);
  }
  uVar2 = (**(code **)(*in_ECX + 0x530))();
  return uVar2;
}



// ?GetCitadel@Villager@@UAEPAVCitadel@@XZ @ 0x006e19a0

undefined4 _GetCitadel_Villager__UAEPAVCitadel__XZ(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x48))();
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x2c) != 0)) {
    return *(undefined4 *)(*(int *)(iVar1 + 0x2c) + 0x260);
  }
  return 0;
}



// ?CallOutofAnimationFunction@Villager@@UAEHW4VILLAGER_STATES@@@Z @ 0x006e1b90

int _CallOutofAnimationFunction_Villager__UAEHW4VILLAGER_STATES___Z(uint param_1)

{
  float fVar1;
  float fVar2;
  char cVar3;
  int iVar4;
  int *in_ECX;
  float10 fVar5;
  
  iVar4 = FUN_006e1ca0(param_1);
  if (iVar4 != 0) {
    fVar5 = (float10)(**(code **)(*in_ECX + 0x11c))();
    fVar1 = (float)fVar5;
    cVar3 = (**(code **)(*in_ECX + 0x4a4))();
    if (cVar3 != '\0') {
      fVar1 = fVar1 * 0.5;
    }
    iVar4 = 2;
    fVar2 = 1.0 - fVar1;
    do {
      iVar4 = iVar4 + -1;
      fVar2 = fVar2 * (1.0 - fVar1);
    } while (iVar4 != 0);
    fVar5 = (float10)FUN_0067bcb0(0x3f800000,s_C__dev_black_Villager_cpp_00b4651c,0x758);
    if (fVar5 - (float10)fVar2 * (float10)0.5 < (float10)*(float *)(in_ECX[10] + 0x368)) {
      iVar4 = FUN_006f90a0(param_1 & 0xff);
      if (iVar4 != 0) {
        return 1;
      }
    }
  }
  iVar4 = __purecall(param_1);
  if (iVar4 == 0x2f) {
    (**(code **)(*in_ECX + 0x908))(0xa3);
  }
  return iVar4;
}



// ?GetAnimId@Villager@@UAE?AW4ANIM_LIST@@XZ @ 0x006e1e60

undefined4 _GetAnimId_Villager__UAE_AW4ANIM_LIST__XZ(undefined4 param_1)

{
  byte bVar1;
  byte bVar2;
  int *in_ECX;
  int iVar3;
  int iVar4;
  
  bVar1 = *(byte *)(in_ECX + 0x23);
  bVar2 = (**(code **)(*in_ECX + 0xb00))();
  iVar4 = 1;
  iVar3 = 1;
  if (*(code **)(&DAT_00c2a2e8 + (uint)bVar1 * 0x90) != (code *)0x0) {
    iVar4 = (**(code **)(&DAT_00c2a2e8 + (uint)bVar1 * 0x90))(param_1);
  }
  if ((bVar1 != bVar2) && (*(code **)(&DAT_00c2a2e8 + (uint)bVar2 * 0x90) != (code *)0x0)) {
    iVar3 = (**(code **)(&DAT_00c2a2e8 + (uint)bVar2 * 0x90))(param_1);
  }
  if ((iVar4 == 1) && (iVar3 == 1)) {
    return 1;
  }
  return 0;
}



// ?CallEntryStateFunction@Villager@@QAE_NEE@Z @ 0x006e1f10

bool _CallEntryStateFunction_Villager__QAE_NEE_Z(uint param_1)

{
  undefined1 uVar1;
  int iVar2;
  int *in_ECX;
  
  uVar1 = (**(code **)(*in_ECX + 0xb00))();
  if (*(code **)(&DAT_00c2a2d8 + (param_1 & 0xff) * 0x90) != (code *)0x0) {
    iVar2 = (**(code **)(&DAT_00c2a2d8 + (param_1 & 0xff) * 0x90))(uVar1,param_1);
    if (iVar2 != 1) {
      return iVar2 == 0x23;
    }
  }
  (**(code **)(*in_ECX + 0x934))(0,param_1);
  return true;
}



// ?CallExitStateFunction@Villager@@UAEIW4VILLAGER_STATES@@@Z @ 0x006e1f80

undefined4 _CallExitStateFunction_Villager__UAEIW4VILLAGER_STATES___Z(uint param_1)

{
  int iVar1;
  int *in_ECX;
  undefined4 unaff_ESI;
  
  (**(code **)(*in_ECX + 0xb00))();
  iVar1 = (**(code **)(*in_ECX + 0x908))(param_1);
  if (iVar1 == 0) {
    return 0;
  }
  if ((*(code **)(&DAT_00c2a2d8 + (param_1 & 0xff) * 0x90) != (code *)0x0) &&
     (iVar1 = (**(code **)(&DAT_00c2a2d8 + (param_1 & 0xff) * 0x90))(unaff_ESI,param_1), iVar1 != 1)
     ) {
    if (iVar1 != 0x23) {
      return 0;
    }
    return 1;
  }
  (**(code **)(*in_ECX + 0x934))(1,param_1);
  return 1;
}



// ?CallEntryStateFunction@Villager@@QAE_NE@Z @ 0x006e22b0

undefined4 _CallEntryStateFunction_Villager__QAE_NE_Z(uint param_1)

{
  int *in_ECX;
  
  FUN_005c56b0(in_ECX);
  if (*(int *)(&DAT_00cdabc8 + (param_1 & 0xff) * 0x114) == 0) {
    (**(code **)(*in_ECX + 0x994))();
  }
  return 1;
}



// ?ValidToApplyThisToObject@Villager@@UAEIPAVGInterfaceStatus@@PAVObject@@@Z @ 0x006e26d0

undefined4
_ValidToApplyThisToObject_Villager__UAEIPAVGInterfaceStatus__PAVObject___Z
          (undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 in_ECX;
  
  iVar1 = FUN_007344da(param_2,0,&Object::RTTI_Type_Descriptor,&WorshipTotem::RTTI_Type_Descriptor,0
                      );
  if (iVar1 != 0) {
    return 1;
  }
  iVar1 = FUN_007344da(param_2,0,&Object::RTTI_Type_Descriptor,&MagicTeleport::RTTI_Type_Descriptor,
                       0);
  if (iVar1 != 0) {
    iVar1 = FUN_005b9b40(param_1,in_ECX);
    if (iVar1 == 1) {
      return 1;
    }
  }
  return 0;
}



// ?ApplyThisToObject@Villager@@UAEIPAVGInterfaceStatus@@PAVObject@@PAUGestureSystemPacketData@@@Z @ 0x006e2740

undefined4
_ApplyThisToObject_Villager__UAEIPAVGInterfaceStatus__PAVObject__PAUGestureSystemPacketData___Z
          (int *param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  float *pfVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int *in_ECX;
  float10 fVar7;
  undefined8 uVar8;
  float fStack_198;
  float fStack_194;
  float fStack_190;
  float fStack_18c;
  float fStack_188;
  int iStack_184;
  int iStack_180;
  float fStack_17c;
  undefined1 auStack_178 [16];
  LH_SamplePlayOptions aLStack_168 [4];
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_144;
  float fStack_138;
  float fStack_134;
  float fStack_130;
  
  piVar2 = (int *)FUN_007344da(param_2,0,&Object::RTTI_Type_Descriptor,
                               &WorshipTotem::RTTI_Type_Descriptor,0);
  if (piVar2 == (int *)0x0) {
    iVar3 = FUN_007344da(param_2,0,&Object::RTTI_Type_Descriptor,
                         &MagicTeleport::RTTI_Type_Descriptor,0);
    if (iVar3 != 0) {
      iVar3 = FUN_005b9b40(param_1,in_ECX);
      if (iVar3 == 1) {
        uVar6 = FUN_005b9b80(param_1,in_ECX);
        return uVar6;
      }
    }
    return 0;
  }
  iVar3 = (**(code **)(*(int *)piVar2[0x40] + 0x890))();
  if ((iVar3 != 0) && ((~*(ushort *)(in_ECX + 9) & 0x4000) != 0)) {
    fVar7 = (float10)(**(code **)(*in_ECX + 0x5c0))();
    fStack_198 = (float)fVar7;
    piVar1 = (int *)piVar2[0x40];
    (**(code **)(*param_1 + 0x1c))();
    iVar3 = (**(code **)(*in_ECX + 0xaf4))();
    if (iVar3 != 0) {
      fStack_198 = fStack_198 * 1.25;
    }
    piVar1[0x3c] = (int)(fStack_198 + (float)piVar1[0x3c]);
    piVar1[0x3d] = (int)(fStack_198 + (float)piVar1[0x3d]);
    iVar3 = (**(code **)(*param_1 + 0x1c))();
    if (iVar3 != 0) {
      FUN_004cb260(param_1,0x28,in_ECX,0);
    }
    fStack_194 = 0.0;
    if (param_1 != (int *)0x0) {
      fStack_194 = (float)(**(code **)(*param_1 + 0x1c))();
    }
    uVar6 = 1;
    fVar7 = (float10)(**(code **)(*in_ECX + 0x11c))();
    FUN_006e0860(7,fStack_194,(float)fVar7,uVar6);
    iStack_184 = piVar2[5];
    iStack_180 = piVar2[6];
    fStack_17c = (float)piVar2[7];
    fVar7 = (float10)(**(code **)(*piVar2 + 0x42c))();
    fStack_17c = (float)((float10)fStack_17c + fVar7);
    pfVar4 = (float *)FUN_005efc00(&iStack_184,0x1b,0x3f800000,0);
    if (pfVar4 != (float *)0x0) {
      fStack_194 = *pfVar4;
      (**(code **)(*piVar1 + 0x1c))();
      (**(code **)((int)fStack_194 + 0x20))();
    }
    if (param_1 != (int *)0x0) {
      fStack_18c = (float)param_1[0x33];
      fStack_190 = (float)param_1[0x32];
      fStack_188 = (float)param_1[0x34];
      LH_SamplePlayOptions::LH_SamplePlayOptions(aLStack_168);
      uStack_164 = *(undefined4 *)(DAT_00bf4e68 + 0x3ac);
      fStack_134 = fStack_18c;
      fStack_138 = fStack_190;
      uStack_144 = 0xb3;
      uStack_160 = 1;
      fStack_130 = fStack_188;
      uStack_15c = 0;
      FUN_00423db0();
      iVar3 = (**(code **)(*in_ECX + 0xaf4))();
      if (iVar3 == 0) {
        uStack_164 = *(undefined4 *)(DAT_00bf4e68 + 0x3b0);
        if (*(int *)(in_ECX[10] + 0x1f8) == 1) {
          uVar8 = 0x600000218;
        }
        else {
          uVar8 = 0x8000000dd;
        }
        uStack_144 = FUN_006b6100(uVar8);
        FUN_00423db0();
      }
      else {
        uStack_164 = *(undefined4 *)(DAT_00bf4e68 + 0x3bc);
        FUN_00423db0();
        uStack_144 = FUN_006b6100(0xd,10);
      }
      LH_SamplePlayOptions::~LH_SamplePlayOptions(aLStack_168);
    }
    piVar2 = (int *)FUN_00527d60();
    if (param_1 == piVar2) {
      puVar5 = (undefined4 *)FUN_00746d70(0xa0,s_C__dev_black_Villager_cpp_00b4651c,0x993);
      if (puVar5 != (undefined4 *)0x0) {
        puVar5[5] = 0;
        puVar5[6] = 0;
        *puVar5 = &PTR_LAB_008049b4;
        puVar5[1] = DAT_00df8148;
        DAT_00df8148 = puVar5;
      }
      FUN_00733e17(auStack_178,s__3_0f_00b20738,(double)fStack_198);
      iVar3 = FUN_00527d30();
      fStack_194 = *(float *)(iVar3 + 0x3c0);
      fVar7 = (float10)FUN_00760fd0();
      pfVar4 = &fStack_198;
      fStack_18c = (float)(fVar7 + (float10)fStack_194);
      fStack_190 = (float)*(int *)(iVar3 + 0x3b8) * 0.00015258789;
      fStack_198 = -NAN;
      fStack_188 = (float)*(int *)(iVar3 + 0x3bc) * 0.00015258789;
      uVar6 = FUN_00789090(auStack_178,pfVar4);
      FUN_0078c9f0(&fStack_190,uVar6,pfVar4);
    }
    (**(code **)(*in_ECX + 0xc))();
    return 3;
  }
  return 0x17;
}



// ?GetScriptObjectType@Villager@@UAEIXZ @ 0x006e2b20

char _GetScriptObjectType_Villager__UAEIXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x458))();
  return (iVar1 != 0) + '\x04';
}



// ?IsTouching@Villager@@UBE_NPAUMapCoords@@@Z @ 0x006e2b40

undefined4 _IsTouching_Villager__UBE_NPAUMapCoords___Z(undefined4 param_1)

{
  int *in_ECX;
  float10 fVar1;
  float10 fVar2;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 0x13c))(param_1);
  fVar2 = (float10)(**(code **)(*in_ECX + 0x130))();
  if ((float10)(float)fVar1 < fVar2) {
    return 1;
  }
  return 0;
}



// ?InterfaceSetInMagicHand@Villager@@UAEIPAVGInterfaceStatus@@@Z @ 0x006e2b80

void _InterfaceSetInMagicHand_Villager__UAEIPAVGInterfaceStatus___Z(int *param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  *(byte *)(in_ECX + 0x38) = *(byte *)(in_ECX + 0x38) | 0x20;
  if ((*(char *)((int)in_ECX + 0x8d) == '{') && (in_ECX[0x44] != 0)) {
    *(undefined4 *)(in_ECX[0x44] + 0x110) = 0;
    (**(code **)(*(int *)in_ECX[0x44] + 0x8c4))();
    in_ECX[0x44] = 0;
  }
  iVar1 = (**(code **)(*param_1 + 0x1c))();
  iVar2 = (**(code **)(*in_ECX + 0x1c))();
  if (iVar2 == iVar1) {
    iVar1 = FUN_006efcc0();
    if (iVar1 != 0) {
      (**(code **)(*param_1 + 0x1c))(0);
      FUN_0067efc0();
    }
  }
  _InterfaceSetInMagicHand_Living__UAEIPAVGInterfaceStatus___Z(param_1);
  return;
}



// ?SetSpeedInMetres@Villager@@UAEXMH@Z @ 0x006e2c10

void _SetSpeedInMetres_Villager__UAEXMH_Z(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = FUN_006dea70(param_1,param_2);
  FUN_006e0d40(uVar1,param_2);
  return;
}



// ?SetFoodSpeedup@Villager@@UAEX_N@Z @ 0x006e2f10

void _SetFoodSpeedup_Villager__UAEX_N_Z(char param_1)

{
  int in_ECX;
  
  if (param_1 != '\0') {
    *(undefined1 *)(in_ECX + 0xf0) = 0xff;
    return;
  }
  *(undefined1 *)(in_ECX + 0xf0) = 0;
  return;
}



// ?IncreaseLife@Villager@@UAEXM@Z @ 0x006e2f60

void _IncreaseLife_Villager__UAEXM_Z(undefined4 param_1)

{
  _IncreaseLife_Object__UAEXM_Z(param_1);
  return;
}



// ?StorePreviousState@Villager@@UAEXXZ @ 0x006e3220

void _StorePreviousState_Villager__UAEXXZ(void)

{
  undefined4 uVar1;
  int *in_ECX;
  
  uVar1 = (**(code **)(*in_ECX + 0xb00))();
  FUN_006e3240(uVar1);
  return;
}



// ?RemoveFromGame@Villager@@UAEIXZ @ 0x006e38e0

void _RemoveFromGame_Villager__UAEIXZ(void)

{
  FUN_006e0080();
  _RemoveFromGame_Living__UAEIXZ();
  return;
}



// ?SetStateSpeed@Villager@@UAEXXZ @ 0x006e39e0

undefined4 _SetStateSpeed_Villager__UAEXXZ(uint param_1)

{
  return *(undefined4 *)(&DAT_00cdab1c + (param_1 & 0xff) * 0x114);
}



// ?GetQueryFirstEnumText@Villager@@UAE?AW4HELP_TEXT@@XZ @ 0x006e3a00

int _GetQueryFirstEnumText_Villager__UAE_AW4HELP_TEXT__XZ(void)

{
  uint uVar1;
  int iVar2;
  int *in_ECX;
  
  uVar1 = (**(code **)(*in_ECX + 0xb00))();
  iVar2 = *(int *)(&DAT_00cdac10 + (uVar1 & 0xff) * 0x114);
  if (iVar2 == 0) {
    if ((*(ushort *)(in_ECX + 0x38) & 0x200) != 0) {
      uVar1 = (uint)*(byte *)((int)in_ECX + 0xf2);
      if (uVar1 < 8) {
        return uVar1 + 0xc39;
      }
      if (uVar1 == 9) {
        return 0xad2;
      }
      if (uVar1 == 8) {
        return 0xc39;
      }
    }
    iVar2 = _GetQueryFirstEnumText_Object__UAE_AW4HELP_TEXT__XZ();
  }
  return iVar2;
}



// ?GetQueryLastEnumText@Villager@@UAE?AW4HELP_TEXT@@XZ @ 0x006e3a70

uint _GetQueryLastEnumText_Villager__UAE_AW4HELP_TEXT__XZ(void)

{
  uint uVar1;
  uint uVar2;
  int *in_ECX;
  
  uVar1 = (**(code **)(*in_ECX + 0xb00))();
  uVar1 = *(uint *)(&DAT_00cdac10 + (uVar1 & 0xff) * 0x114);
  if (uVar1 != 0) {
    uVar2 = (**(code **)(*in_ECX + 0xb00))();
    if (*(uint *)(&DAT_00cdac10 + (uVar2 & 0xff) * 0x114) <= uVar1) {
      return uVar1;
    }
    return *(uint *)(&DAT_00cdac10 + (uint)*(byte *)(in_ECX + 0x23) * 0x114);
  }
  if ((*(ushort *)(in_ECX + 0x38) & 0x200) != 0) {
    uVar1 = (uint)*(byte *)((int)in_ECX + 0xf2);
    if (*(byte *)((int)in_ECX + 0xf2) < 8) {
      return uVar1 + 0xc39;
    }
    if (uVar1 == 9) {
      return 0xad2;
    }
    if (uVar1 == 8) {
      return 0xc39;
    }
  }
  uVar1 = _GetQueryLastEnumText_Object__UAE_AW4HELP_TEXT__XZ();
  return uVar1;
}



// ?ResolveLoad@Villager@@UAEXXZ @ 0x006e4340

void _ResolveLoad_Villager__UAEXXZ(void)

{
  int in_ECX;
  
  _ResolveLoad_Object__UAEXXZ();
  (**(code **)(**(int **)(in_ECX + 0x40) + 0xcc))();
  return;
}



// ?GetDiscipleStateIfInteractedWith@Villager@@UAEIPAVGInterfaceStatus@@PAVVillager@@@Z @ 0x006e57c0

undefined1
_GetDiscipleStateIfInteractedWith_Villager__UAEIPAVGInterfaceStatus__PAVVillager___Z
          (int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  if (param_2 == in_ECX) {
    return *(undefined1 *)((int)in_ECX + 0xf2);
  }
  iVar1 = (**(code **)(*in_ECX + 0xd4))();
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*param_1 + 0x1c))();
    iVar2 = (**(code **)(*in_ECX + 0x1c))();
    if (iVar1 == iVar2) {
      iVar1 = (**(code **)(*param_2 + 0x1c))();
      iVar2 = (**(code **)(*in_ECX + 0x1c))();
      if (iVar1 == iVar2) {
        iVar1 = FUN_006efcc0();
        if (iVar1 != 0) {
          iVar1 = FUN_006efcc0();
          if ((iVar1 != 0) && (*(int *)(in_ECX[10] + 0x1f8) != *(int *)(param_2[10] + 0x1f8))) {
            return 5;
          }
        }
      }
    }
  }
  return 0;
}



// ?SetSkeleton@Villager@@QAEXH@Z @ 0x006e5990

void _SetSkeleton_Villager__QAEXH_Z(byte param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int *in_ECX;
  int iVar6;
  
  if ((DAT_00cc785c & 1) == 0) {
    DAT_00cc785c = DAT_00cc785c | 1;
    iVar2 = 0x1ff;
    if (*DAT_00d76c64 < 0x200) {
      iVar2 = 0;
    }
    DAT_00cc7858 = DAT_00d76c64[iVar2 + 1];
  }
  *(ushort *)(in_ECX + 0x2d) = (param_1 & 1) << 6 | *(ushort *)(in_ECX + 0x2d) & 0xffbf;
  iVar2 = (**(code **)(*in_ECX + 0x4a0))();
  if (iVar2 == 0) {
    uVar1 = *(uint *)(in_ECX[10] + 0x138);
    uVar3 = (**(code **)(*in_ECX + 0x8cc))();
    if (uVar3 < uVar1) {
      if ((int *)in_ECX[0x10] == (int *)0x0) goto LAB_006e5af9;
      iVar2 = *(int *)(in_ECX[10] + 0x20c);
      if ((iVar2 < 0) || (*DAT_00d76c64 <= iVar2)) {
        iVar2 = 0;
      }
      iVar2 = DAT_00d76c64[iVar2 + 1];
      iVar4 = *(int *)(in_ECX[10] + 0x208);
      if ((iVar4 < 0) || (*DAT_00d76c64 <= iVar4)) {
        iVar4 = 0;
      }
      iVar4 = DAT_00d76c64[iVar4 + 1];
      iVar6 = *(int *)in_ECX[0x10];
    }
    else {
      if (in_ECX[0x10] == 0) goto LAB_006e5af9;
      iVar2 = (**(code **)(*in_ECX + 0x60c))(2);
      if ((iVar2 < 0) || (*DAT_00d76c64 <= iVar2)) {
        iVar2 = 0;
      }
      iVar2 = DAT_00d76c64[iVar2 + 1];
      iVar4 = (**(code **)(*in_ECX + 0x60c))(1);
      if ((iVar4 < 0) || (*DAT_00d76c64 <= iVar4)) {
        iVar4 = 0;
      }
      iVar4 = DAT_00d76c64[iVar4 + 1];
      (**(code **)(*in_ECX + 0x60c))(0);
      iVar6 = *(int *)in_ECX[0x10];
    }
    (**(code **)(iVar6 + 0xf4))(iVar4,iVar2);
  }
  else if ((int *)in_ECX[0x10] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x10] + 0xf4))(DAT_00cc7858,DAT_00cc7858);
  }
LAB_006e5af9:
  uVar5 = (**(code **)(*in_ECX + 0x8cc))();
  FUN_006e2590(uVar5);
  return;
}



// ?IsReachable@Villager@@UAE_NXZ @ 0x006e5b20

bool _IsReachable_Villager__UAE_NXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x2c))();
  if (iVar1 == 0) {
    return false;
  }
  if ((*(byte *)(in_ECX + 0x38) & 4) == 4) {
    return false;
  }
  if ((*(byte *)(in_ECX + 9) & 4) == 4) {
    return false;
  }
  return (char)in_ECX[0x23] != -0x14;
}



// ?ValidForPlaceInHand@Villager@@UAEIPAVGInterfaceStatus@@@Z @ 0x006e5b60

bool _ValidForPlaceInHand_Villager__UAEIPAVGInterfaceStatus___Z(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x530))();
  return iVar1 != 0;
}



// ?CanBecomeAPhysicsObject@Villager@@UAE_NXZ @ 0x006e5b80

void _CanBecomeAPhysicsObject_Villager__UAE_NXZ(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x006e5b82. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0x530))();
  return;
}



// ?AddResource@Villager@@UAEIW4RESOURCE_TYPE@@IPAVGInterfaceStatus@@_NPBUMapCoords@@H@Z @ 0x006e5b90

undefined4
_AddResource_Villager__UAEIW4RESOURCE_TYPE__IPAVGInterfaceStatus___NPBUMapCoords__H_Z
          (int param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  int *in_ECX;
  
  if (param_1 == 0) {
    FUN_006e1180(param_2);
    if (param_4 != '\0') {
      (**(code **)(*in_ECX + 0x69c))(1);
      return 0;
    }
  }
  else if (param_1 == 1) {
    FUN_006e11a0(param_2,0);
  }
  return 0;
}



// ?SetCurrentAndDestinationState@Villager@@UAEHEE@Z @ 0x006e5c30

int _SetCurrentAndDestinationState_Villager__UAEHEE_Z(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(&DAT_00c2a338 + (uint)*(byte *)(in_ECX + 0x8c) * 0x90) == 0) {
    iVar1 = -1;
  }
  else {
    iVar1 = (**(code **)(&DAT_00c2a338 + (uint)*(byte *)(in_ECX + 0x8c) * 0x90))(1,param_1);
    if (iVar1 != -1) {
      *(ushort *)(in_ECX + 0xe0) = *(ushort *)(in_ECX + 0xe0) & 0xefff | 0x800;
      return iVar1;
    }
  }
  return iVar1;
}



// ?CallIntoAnimationFunction@Villager@@UAEHW4VILLAGER_STATES@@@Z @ 0x006e5cc0

int _CallIntoAnimationFunction_Villager__UAEHW4VILLAGER_STATES___Z(uint param_1)

{
  int iVar1;
  int in_ECX;
  
  if ((*(int *)(&DAT_00cdac00 + (param_1 & 0xff) * 0x114) == 0) &&
     (*(int *)(&DAT_00c2a338 + (uint)*(byte *)(in_ECX + 0x8c) * 0x90) != 0)) {
    iVar1 = (**(code **)(&DAT_00c2a338 + (uint)*(byte *)(in_ECX + 0x8c) * 0x90))(0,param_1);
    if (iVar1 == -1) {
      return -1;
    }
    *(byte *)(in_ECX + 0xe1) = *(byte *)(in_ECX + 0xe1) | 0x18;
    return iVar1;
  }
  return -1;
}



// ?GetFinalDestPos@Villager@@UAEPAUMapCoords@@PAU2@@Z @ 0x006e6130

void _GetFinalDestPos_Villager__UAEPAUMapCoords__PAU2__Z(undefined4 param_1)

{
  _GetFinalDestPos__6LivingFP9MapCoords(param_1);
  return;
}



// ?ThrowObjectFromHand@Villager@@UAEIPAVGInterfaceStatus@@H@Z @ 0x006e6140

void _ThrowObjectFromHand_Villager__UAEIPAVGInterfaceStatus__H_Z(undefined4 param_1,int param_2)

{
  int iVar1;
  int *in_ECX;
  undefined4 uVar2;
  
  (**(code **)(*in_ECX + 0x1c))();
  if (param_2 != 0) {
    iVar1 = (**(code **)(*in_ECX + 0x1c))();
    if (iVar1 != 0) {
      uVar2 = param_1;
      (**(code **)(*in_ECX + 0x1c))(param_1);
      iVar1 = FUN_005fa670(uVar2);
      if (iVar1 == 0) goto LAB_006e6181;
    }
    FUN_006e56e0(0,0,0);
  }
LAB_006e6181:
  _ThrowObjectFromHand_Object__UAEIPAVGInterfaceStatus__H_Z(param_1,param_2);
  return;
}



// ?IsDrowning@Villager@@UAE_NXZ @ 0x006e6190

bool _IsDrowning_Villager__UAE_NXZ(void)

{
  int in_ECX;
  
  return *(char *)(in_ECX + 0x8c) == '\x10';
}



// ?SetLife@Villager@@UAEXM@Z @ 0x006e61a0

void _SetLife_Villager__UAEXM_Z(float param_1)

{
  int *in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 0x11c))();
  if (((float10)0.7 < fVar1) && (param_1 < 0.7)) {
    FUN_006e6220();
    _SetLife_Object__UAEXM_Z(param_1);
    return;
  }
  fVar1 = (float10)(**(code **)(*in_ECX + 0x11c))();
  if ((fVar1 < (float10)0.7) && (0.7 < param_1)) {
    FUN_006e6230();
  }
  _SetLife_Object__UAEXM_Z(param_1);
  return;
}



// ?RemoveFromDance@Villager@@UAEXH@Z @ 0x006e8d90

void _RemoveFromDance_Villager__UAEXH_Z(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x8e4))(0xa3);
  return;
}



// ?IsFireMan@Villager@@UAE_NXZ @ 0x006ea510

undefined4 _IsFireMan_Villager__UAE_NXZ(void)

{
  byte bVar1;
  int *in_ECX;
  int iVar2;
  uint uStack_4;
  
  bVar1 = (**(code **)(*in_ECX + 0xb00))();
  uStack_4 = (uint)bVar1;
  iVar2 = uStack_4 * 0x90;
  if (((((*(code **)(&DAT_00c2a2e8 + iVar2) != FUN_006e9fb0) ||
        (*(int *)(&DAT_00c2a2ec + iVar2) != 0)) || (*(int *)(&DAT_00c2a2f0 + iVar2) != 0)) ||
      (*(int *)(&DAT_00c2a2f4 + iVar2) != 0)) && (bVar1 != 0xd7)) {
    return 0;
  }
  return 1;
}



// ?SetStateAfterFinishingDance@Villager@@UAEXXZ @ 0x006eab40

float10 _SetStateAfterFinishingDance_Villager__UAEXXZ(void)

{
  int *in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 0x11c))();
  return (float10)1.0 - fVar1;
}



// ?IsInterestedInWoodObject@Villager@@UAE_NPAVObject@@@Z @ 0x006f1b80

undefined4 _IsInterestedInWoodObject_Villager__UAE_NPAVObject___Z(void)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  float10 fVar4;
  int unaff_retaddr;
  
  uVar1 = (**(code **)(*in_ECX + 0xb00))();
  if ((((*(ushort *)(in_ECX + 0x38) & 2) == 0) &&
      (*(int *)(&DAT_00cdabfc + (uVar1 & 0xff) * 0x114) != 0)) &&
     ((*(ushort *)(in_ECX + 0x38) & 0x80) == 0)) {
    iVar2 = (**(code **)(*in_ECX + 0x96c))(uVar1 & 0xff);
    if (iVar2 == 0) {
      iVar2 = in_ECX[10];
      fVar4 = (float10)(**(code **)(*in_ECX + 0x11c))();
      if (((float10)*(float *)(iVar2 + 0x380) < fVar4) || (unaff_retaddr == 7)) {
        uVar3 = _IsInterestedInWoodObject_Living__UAE_NPAVObject___Z(unaff_retaddr);
        return uVar3;
      }
    }
  }
  return 0;
}



// ?IsAvailableForReaction@Villager@@UAE_NW4REACTION@@@Z @ 0x006f1c00

undefined4 _IsAvailableForReaction_Villager__UAE_NW4REACTION___Z(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  if (*(int *)(&DAT_00b2d190 + param_1 * 0xc0) == 0) {
    iVar1 = (**(code **)(*in_ECX + 0x530))();
    if (iVar1 != 0) {
      return 0;
    }
  }
  return 1;
}



// ?UpdateHowImpressed@Villager@@UAEXPAVReaction@@H@Z @ 0x006f1c30

void _UpdateHowImpressed_Villager__UAEXPAVReaction__H_Z(undefined4 param_1)

{
  int *in_ECX;
  undefined4 unaff_retaddr;
  
  (**(code **)(*in_ECX + 0x988))(param_1,1);
  _UpdateHowImpressed_Living__UAEXPAVReaction__H_Z(param_1,unaff_retaddr);
  return;
}



// ?SetTopState@Villager@@UAEHE@Z @ 0x006f1c60

void _SetTopState_Villager__UAEHE_Z(void)

{
  uint uVar1;
  int *in_ECX;
  
  uVar1 = (**(code **)(*in_ECX + 0xb00))();
  uVar1 = uVar1 & 0xff;
  if ((*(int *)(&DAT_00cdab20 + uVar1 * 0x114) != 0) ||
     (*(int *)(&DAT_00cdabc8 + uVar1 * 0x114) != 0)) {
    uVar1 = (uint)*(byte *)((int)in_ECX + 0x8e);
  }
  FUN_005ab6f0(2,uVar1);
  return;
}



// ?IsAvailableForBeliefButNotReaction@Villager@@UAE_NW4REACTION@@@Z @ 0x006f1cb0

void _IsAvailableForBeliefButNotReaction_Villager__UAE_NW4REACTION___Z(int *param_1)

{
  float fVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *in_ECX;
  undefined4 unaff_EBX;
  float10 fVar6;
  undefined4 unaff_retaddr;
  
  iVar4 = (**(code **)(*param_1 + 0x1c))();
  if (iVar4 != 0) {
    iVar4 = (**(code **)(*in_ECX + 0x48))();
    if (iVar4 != 0) {
      piVar2 = (int *)param_1[5];
      fVar6 = (float10)(**(code **)(*piVar2 + 0x1b0))();
      iVar3 = *(int *)(iVar4 + 0x614);
      fVar1 = *(float *)(*(int *)(iVar4 + 0x28) + 0x130);
      iVar4 = *(int *)(iVar4 + 0x610);
      iVar5 = FUN_0067f950();
      FUN_00430bc0(unaff_EBX,
                   ((fVar1 + 0.001) / ((float)(uint)(iVar3 + iVar4) + 0.001)) * (float)fVar6,in_ECX,
                   unaff_retaddr,*(undefined4 *)(iVar5 + 0x5c));
      fVar1 = *(float *)(&DAT_00b2d200 + param_1[9] * 0xc0);
      (**(code **)(&DAT_00b2d1f8 + param_1[9] * 0xc0))();
      fVar6 = (float10)(**(code **)(*piVar2 + 0x1b4))(param_1);
      FUN_00431460(param_1,(float)(fVar6 * (float10)fVar1));
    }
  }
  return;
}



// ?SetupReactToWood@Villager@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x006f2010

void _SetupReactToWood_Villager__UAEXPAVGameThingWithPos__PAVReaction___Z
               (undefined4 param_1,undefined4 param_2)

{
  int *in_ECX;
  int unaff_ESI;
  
  (**(code **)(*in_ECX + 0x98c))(param_2,0x95);
  in_ECX[0x2f] = unaff_ESI;
  return;
}



// ?ReactToTownCelebrationPriority@Villager@@UAEEPAVReaction@@0@Z @ 0x006f2040

uint _ReactToTownCelebrationPriority_Villager__UAEEPAVReaction__0_Z(int param_1)

{
  float fVar1;
  float fVar2;
  char cVar3;
  bool bVar4;
  ushort uVar5;
  int *piVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  int *in_ECX;
  float10 fVar10;
  
  piVar6 = (int *)FUN_007344da(*(undefined4 *)(param_1 + 0x14),0,
                               &GameThingWithPos::RTTI_Type_Descriptor,&Animal::RTTI_Type_Descriptor
                               ,0);
  uVar9 = 0;
  if (piVar6 != (int *)0x0) {
    fVar10 = (float10)FUN_006de0a0(in_ECX + 5,piVar6 + 5);
    fVar1 = (float)fVar10;
    iVar7 = FUN_0067f950();
    fVar2 = *(float *)(iVar7 + 0x40);
    bVar4 = fVar1 < fVar2;
    uVar5 = (ushort)(fVar1 == fVar2);
    uVar9 = CONCAT22((short)((uint)iVar7 >> 0x10),
                     (ushort)bVar4 << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 | uVar5 << 0xe);
    if ((((*(byte *)(in_ECX + 0x38) & 4) == 0) &&
        (uVar9 = CONCAT31((int3)(uVar9 >> 8),0xec), (char)in_ECX[0x23] != -0x14)) &&
       ((*(char *)((int)in_ECX + 0x8d) != -0x14 || (bVar4 || uVar5 != 0)))) {
      uVar8 = (**(code **)(*in_ECX + 0xb00))();
      if (((char)uVar8 != -0x13) || (*(ushort *)(in_ECX + 0x24) < 0x14)) {
        cVar3 = (char)piVar6[0x23];
        uVar9 = CONCAT31((int3)((uint)uVar8 >> 8),cVar3);
        if ((cVar3 == '#') || (cVar3 == '3')) goto LAB_006f2159;
        if ((!bVar4 && uVar5 == 0) && (iVar7 = FUN_005af6d0(0x1c), iVar7 != 0)) {
          iVar7 = FUN_005b0480(piVar6);
          uVar9 = 0;
          if (iVar7 == 0) goto LAB_006f2159;
        }
      }
      (**(code **)(*piVar6 + 0x154))();
      uVar9 = __ftol();
      return uVar9;
    }
  }
LAB_006f2159:
  return uVar9 & 0xffffff00;
}



// ?ReactToMagicShieldDestroyedPriority@Villager@@UAEEPAVReaction@@0@Z @ 0x006f2170

undefined1 _ReactToMagicShieldDestroyedPriority_Villager__UAEEPAVReaction__0_Z(void)

{
  return DAT_00c71338;
}



// ?SetupReactToBreeder@Villager@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x006f2180

void _SetupReactToBreeder_Villager__UAEXPAVGameThingWithPos__PAVReaction___Z
               (undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int *in_ECX;
  int unaff_ESI;
  
  cVar1 = (**(code **)(*in_ECX + 0xb00))();
  if (cVar1 == -0x14) {
    in_ECX[0x41] = 0;
    return;
  }
  (**(code **)(*in_ECX + 0x98c))(param_2,0xe7);
  in_ECX[0x2f] = unaff_ESI;
  return;
}



// ?SetupReactToMagicTree@Villager@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x006f21c0

void _SetupReactToMagicTree_Villager__UAEXPAVGameThingWithPos__PAVReaction___Z
               (int param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  int *in_ECX;
  float10 fVar6;
  float10 fVar7;
  
  uVar4 = FUN_007344da(param_1,0,&GameThingWithPos::RTTI_Type_Descriptor,
                       &Object::RTTI_Type_Descriptor,0);
  iVar5 = FUN_005f56a0(uVar4);
  if (iVar5 != 0) {
    fVar1 = *(float *)(iVar5 + 0x104);
    fVar2 = *(float *)(iVar5 + 0x108);
    fVar3 = *(float *)(iVar5 + 0x10c);
    fVar6 = (float10)FUN_006de0a0(in_ECX + 5,param_1 + 0x14);
    fVar7 = SQRT((float10)fVar1 * (float10)fVar1 +
                 (float10)fVar2 * (float10)fVar2 + (float10)fVar3 * (float10)fVar3);
    if (fVar6 < fVar7 + fVar7) {
      (**(code **)(*in_ECX + 0x98c))(param_2,6);
      in_ECX[0x2f] = param_1;
      return;
    }
    (**(code **)(*in_ECX + 0x98c))(param_2,0xa2);
    in_ECX[0x2f] = param_1;
  }
  return;
}



// ?SetupLookAtSpell@Villager@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x006f22b0

void _SetupLookAtSpell_Villager__UAEXPAVGameThingWithPos__PAVReaction___Z
               (undefined4 param_1,undefined4 param_2)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x9a8))(param_1,param_2);
  return;
}



// ?FleeingFromObjectReaction@Villager@@UAE_NXZ @ 0x006f22d0

undefined4 _FleeingFromObjectReaction_Villager__UAE_NXZ(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  if ((int *)in_ECX[0x2f] != (int *)0x0) {
    iVar1 = (**(code **)(*(int *)in_ECX[0x2f] + 0x2c))();
    if (iVar1 != 0) {
      (**(code **)(*(int *)in_ECX[0x2f] + 0x1c))();
      uVar2 = _FleeingFromObjectReaction_PuzzleHorse__UAE_NXZ();
      return uVar2;
    }
  }
  (**(code **)(*in_ECX + 0x998))();
  return 1;
}



// ?NumGameTurnsToReactToPredatorFunction@Villager@@UAEIPAVGameThingWithPos@@IM@Z @ 0x006f28b0

undefined4
_NumGameTurnsToReactToPredatorFunction_Villager__UAEIPAVGameThingWithPos__IM_Z
          (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  cVar1 = (**(code **)(*in_ECX + 0xb00))();
  if (cVar1 == -0x13) {
    return 0;
  }
  uVar2 = _NumGameTurnsToReactToPredatorFunction_Living__UAEIPAVGameThingWithPos__IM_Z
                    (param_1,param_2,param_3);
  return uVar2;
}



// ?NumGameTurnsToReactToBurningObjectFunction@Villager@@UAEIPAVGameThingWithPos@@IM@Z @ 0x006f2900

undefined4
_NumGameTurnsToReactToBurningObjectFunction_Villager__UAEIPAVGameThingWithPos__IM_Z
          (int *param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int *in_ECX;
  float10 fVar2;
  
  fVar2 = (float10)FUN_006de0a0(in_ECX + 5,param_1 + 5);
  if ((float10)*(float *)(&DAT_00c70490 + param_2 * 100) <= fVar2) {
    fVar2 = (float10)(**(code **)(*param_1 + 0x154))();
    if (fVar2 <= (float10)3.0) {
      uVar1 = (**(code **)(*in_ECX + 0xac0))(param_1,param_2,param_3);
      return uVar1;
    }
  }
  return 0;
}



// ?NumGameTurnsBeforeReactingAgainToBurningObjectFunction@Villager@@UAEIPAVGameThingWithPos@@IM@Z @ 0x006f2970

undefined4
_NumGameTurnsBeforeReactingAgainToBurningObjectFunction_Villager__UAEIPAVGameThingWithPos__IM_Z
          (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *in_ECX;
  
  iVar2 = (**(code **)(*in_ECX + 0x48))();
  if (iVar2 != 0) {
    iVar2 = FUN_0067bc90(4,s_C__dev_black_VillagerReaction_cp_00b47428,0x20e);
    if (iVar2 != 0) {
      iVar2 = *(int *)(DAT_00c22ca4 + 0x201afc);
      iVar3 = (**(code **)(*in_ECX + 0x48))();
      iVar3 = *(int *)(iVar3 + 0xea8);
      iVar1 = in_ECX[10];
      iVar4 = FUN_0067bc90(0x32,s_C__dev_black_VillagerReaction_cp_00b47428,0x210);
      if ((uint)(iVar4 + (iVar2 - iVar3)) < *(uint *)(iVar1 + 0x364)) {
        return 0x7fffffff;
      }
    }
  }
  uVar5 = (**(code **)(*in_ECX + 0xabc))(param_1,param_2,param_3);
  return uVar5;
}



// ?NumGameTurnsToReactToShieldFunction@Villager@@UAEIPAVGameThingWithPos@@IM@Z @ 0x006f2a00

undefined4
_NumGameTurnsToReactToShieldFunction_Villager__UAEIPAVGameThingWithPos__IM_Z
          (int *param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x48))();
  if (iVar1 != 0) {
    iVar1 = *(int *)(DAT_00c22ca4 + 0x201afc);
    iVar2 = (**(code **)(*in_ECX + 0x48))();
    if (*(uint *)(in_ECX[10] + 0x364) < (uint)(iVar1 - *(int *)(iVar2 + 0xea8))) {
      return 0x7fffffff;
    }
  }
  iVar1 = (**(code **)(*param_1 + 0x4c8))();
  if (iVar1 != 0) {
    iVar1 = FUN_006c25e0(in_ECX + 0x20,0);
    if (iVar1 == 0) {
      return 0;
    }
  }
  uVar3 = (**(code **)(*in_ECX + 0xac0))(param_1,param_2,param_3);
  return uVar3;
}



// ?LookingAtObjectReaction@Villager@@UAE_NXZ @ 0x006f2a90

undefined4 _LookingAtObjectReaction_Villager__UAE_NXZ(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  if (in_ECX[0x2f] != 0) {
    iVar1 = FUN_005ab4c0();
    if (iVar1 != 0) {
      iVar1 = (**(code **)(*(int *)in_ECX[0x2f] + 0x2c))();
      if (iVar1 == 0) {
        (**(code **)(*in_ECX + 0x998))();
        return 1;
      }
      uVar2 = _LookingAtObjectReaction_PuzzleHorse__UAE_NXZ();
      return uVar2;
    }
  }
  (**(code **)(*in_ECX + 0x998))();
  return 1;
}



// ?FollowingObjectReaction@Villager@@UAE_NXZ @ 0x006f2ae0

undefined4 _FollowingObjectReaction_Villager__UAE_NXZ(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*(int *)in_ECX[0x2f] + 0x2c))();
  if (iVar1 == 0) {
    (**(code **)(*in_ECX + 0x998))();
    return 1;
  }
  uVar2 = _FollowingObjectReaction_PuzzleHorse__UAE_NXZ();
  return uVar2;
}



// ?InspectObjectReaction@Villager@@UAE_NXZ @ 0x006f2b10

undefined4 _InspectObjectReaction_Villager__UAE_NXZ(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  
  iVar1 = (**(code **)(*(int *)in_ECX[0x2f] + 0x2c))();
  if (iVar1 == 0) {
    (**(code **)(*in_ECX + 0x998))();
    return 1;
  }
  in_ECX[0x41] = 0x41a00000;
  iVar1 = __ftol();
  uVar2 = __ftol(s_C__dev_black_VillagerReaction_cp_00b47428,0x259);
  iVar3 = FUN_0067bc90(uVar2);
  in_ECX[0x42] = iVar3 + iVar1;
  (**(code **)(*in_ECX + 0x8e4))(0x84);
  return 1;
}



// ?GotoFoodReaction@Villager@@UAE_NXZ @ 0x006f2e10

undefined4 _GotoFoodReaction_Villager__UAE_NXZ(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  if ((int *)in_ECX[0x2f] != (int *)0x0) {
    iVar1 = (**(code **)(*(int *)in_ECX[0x2f] + 0x2c))();
    if (iVar1 != 0) {
      uVar2 = _GotoFoodReaction_PuzzleHorse__UAE_NXZ();
      return uVar2;
    }
  }
  (**(code **)(*in_ECX + 0x998))();
  return 1;
}



// ?GotoWoodReaction@Villager@@UAE_NXZ @ 0x006f2e40

undefined4 _GotoWoodReaction_Villager__UAE_NXZ(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  if ((int *)in_ECX[0x2f] != (int *)0x0) {
    iVar1 = (**(code **)(*(int *)in_ECX[0x2f] + 0x2c))();
    if ((iVar1 != 0) && ((*(byte *)(in_ECX[0x2f] + 0x24) & 4) == 0)) {
      iVar1 = FUN_005ea110();
      if (iVar1 == 0) {
        uVar2 = _GotoWoodReaction_PuzzleHorse__UAE_NXZ();
        return uVar2;
      }
    }
  }
  (**(code **)(*in_ECX + 0x998))();
  return 1;
}



// ?ArrivesAtFoodReaction@Villager@@UAE_NXZ @ 0x006f2e90

undefined4 _ArrivesAtFoodReaction_Villager__UAE_NXZ(void)

{
  undefined1 uVar1;
  short sVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int *in_ECX;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  piVar3 = (int *)FUN_007344da(in_ECX[0x2f],0,&GameThingWithPos::RTTI_Type_Descriptor,
                               &Object::RTTI_Type_Descriptor);
  if ((((piVar3 != (int *)0x0) && (iVar4 = (**(code **)(*piVar3 + 0x2c))(), iVar4 != 0)) &&
      ((*(byte *)(piVar3 + 9) & 4) == 0)) && (iVar4 = FUN_005ea110(), iVar4 == 0)) {
    if ((*(byte *)(piVar3 + 9) & 0x40) == 0) {
      iVar4 = (**(code **)(*piVar3 + 0x690))();
      if (iVar4 == 1) {
        sVar2 = FUN_006e11e0();
        if ((0 < sVar2) && (iVar4 = (**(code **)(*piVar3 + 0xa0))(1,(int)sVar2,0), 0 < iVar4)) {
          (**(code **)(*piVar3 + 0x820))();
          FUN_006e11a0(iVar4);
        }
      }
      uVar6 = FUN_006ee9b0();
      return uVar6;
    }
    uStack_c = (undefined4)(1000 / (ulonglong)DAT_00c22d78);
    uVar6 = *(undefined4 *)(in_ECX[0x25] + 0x24);
    uStack_8 = 0;
    uVar5 = __ftol();
    iVar4 = FUN_005af6d0(uVar6);
    if ((uint)(*(int *)(DAT_00c22ca4 + 0x201afc) - iVar4) <= uVar5) {
      (**(code **)(*piVar3 + 0x648))(&uStack_c);
      iVar4 = (**(code **)(*in_ECX + 0x85c))(&stack0xffffffec,0x3f000000);
      if (iVar4 == 0) {
        uVar6 = (**(code **)(*in_ECX + 0xb00))();
        FUN_005b0e40(&stack0xffffffe4,uVar6);
        return 1;
      }
      iVar4 = FUN_005ab120(piVar3,1);
      if (iVar4 == 0) {
        return 1;
      }
      uVar1 = (**(code **)(*in_ECX + 0xb00))();
      FUN_006f9070(10,uVar1);
      return 1;
    }
  }
  (**(code **)(*in_ECX + 0x8e4))();
  return 1;
}



// ?NumGameTurnsBeforeReactingAgainToPredatorFunction@Villager@@UAEIPAVGameThingWithPos@@IM@Z @ 0x006f3040

undefined4
_NumGameTurnsBeforeReactingAgainToPredatorFunction_Villager__UAEIPAVGameThingWithPos__IM_Z
          (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  bVar1 = (**(code **)(*in_ECX + 0xb00))();
  if ((0x2e < bVar1) && ((bVar1 < 0x33 || (bVar1 == 0x34)))) {
    return 0;
  }
  uVar2 = (**(code **)(*in_ECX + 0xac0))(param_1,param_2,param_3);
  return uVar2;
}



// ?IsMovingForAnimation@Villager@@UAE_NXZ @ 0x006f3090

undefined4 _IsMovingForAnimation_Villager__UAE_NXZ(void)

{
  int iVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  int *in_ECX;
  float10 fVar7;
  float10 fVar8;
  undefined1 auStack_c [12];
  
  if ((int *)in_ECX[0x2f] != (int *)0x0) {
    iVar3 = (**(code **)(*(int *)in_ECX[0x2f] + 0x2c))();
    if (iVar3 != 0) {
      sVar2 = FUN_006e11c0();
      iVar3 = FUN_007344da(in_ECX[0x2f],0,&GameThingWithPos::RTTI_Type_Descriptor,
                           &PileFood::RTTI_Type_Descriptor,0);
      if ((iVar3 != 0) && (0 < sVar2)) {
        FUN_006e2e90(iVar3,0,(int)sVar2);
      }
      if (0 < (short)in_ECX[0x3d]) {
        iVar3 = FUN_006e2110();
        if (iVar3 != 0) {
          (**(code **)(*in_ECX + 0x8e4))(0x75);
          return 1;
        }
        if (*(int *)(&DAT_008d136c + (uint)*(byte *)((int)in_ECX + 0xf2) * 0x1c) != 1) {
          FUN_006e3900(auStack_c,0);
          fVar7 = (float10)FUN_005ab450(auStack_c,*(undefined4 *)(in_ECX[10] + 0x350));
          iVar1 = in_ECX[0x3d];
          iVar3 = *(int *)(in_ECX[10] + 0x264);
          iVar4 = (**(code **)(*in_ECX + 0x48))();
          if (iVar4 != 0) {
            piVar5 = (int *)(**(code **)(*in_ECX + 0x48))();
            fVar8 = (float10)(**(code **)(*piVar5 + 0x420))();
            if ((float10)0.1 <
                fVar8 * (float10)((float)(int)(short)iVar1 / (float)iVar3) * (float10)(float)fVar7)
            {
              uVar6 = FUN_006f7670();
              return uVar6;
            }
          }
        }
      }
      (**(code **)(*in_ECX + 0x8e4))(0xa3);
      return 1;
    }
  }
  (**(code **)(*in_ECX + 0x998))();
  return 1;
}



// ?IsInterestedInFoodObject@Villager@@UAE_NPAVObject@@@Z @ 0x006f36c0

undefined4 _IsInterestedInFoodObject_Villager__UAE_NPAVObject___Z(int *param_1)

{
  float fVar1;
  float fVar2;
  short sVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int *in_ECX;
  float10 fVar8;
  float10 fVar9;
  
  iVar5 = (**(code **)(*in_ECX + 0x48))();
  iVar6 = (**(code **)(*param_1 + 0x2c))();
  if ((((iVar6 != 0) && (((byte)~*(byte *)(param_1 + 9) >> 2 & 1) != 0)) &&
      (sVar3 = FUN_006e11e0(), sVar3 != 0)) &&
     ((iVar5 != 0 &&
      (iVar5 = in_ECX[10], fVar8 = (float10)(**(code **)(*in_ECX + 0x11c))(),
      (float10)*(float *)(iVar5 + 0x35c) < fVar8)))) {
    iVar5 = (**(code **)(*param_1 + 0x47c))();
    if ((iVar5 != 0) &&
       ((sVar3 = *(short *)((int)in_ECX + 0xf6), sVar4 = FUN_006e11e0(), sVar3 < sVar4 &&
        (iVar5 = FUN_006e1dd0(), iVar5 != 0)))) {
      return 1;
    }
    if (((in_ECX[0x3f] != 0) && (iVar5 = FUN_006cfe30(in_ECX[0x3f]), iVar5 != 0)) &&
       (fVar8 = (float10)FUN_00434ca0(), fVar8 <= (float10)0.0)) {
      return 0;
    }
    iVar5 = (**(code **)(*param_1 + 0x830))();
    if (((iVar5 != 0) || (*(int *)(&DAT_008d1370 + (uint)*(byte *)((int)in_ECX + 0xf2) * 0x1c) != 0)
        ) && (iVar5 = FUN_006e1dd0(), iVar5 != 0)) {
      return 1;
    }
    fVar8 = (float10)FUN_005ab430(param_1,DAT_00c7092c);
    uVar7 = (**(code **)(*in_ECX + 0xb00))();
    iVar5 = in_ECX[10];
    fVar1 = *(float *)(&DAT_00cdabdc + (uVar7 & 0xff) * 0x114);
    sVar3 = FUN_006e11e0();
    iVar5 = *(int *)(iVar5 + 0x268);
    fVar9 = (float10)FUN_006d10a0(1);
    fVar2 = *(float *)(DAT_00c22ca4 + 0x201b0c);
    iVar6 = FUN_006d7d10(1);
    if (*(float *)(iVar6 + 0x18) <
        (float)((float10)fVar2 +
               fVar9 * (float10)((float)(int)sVar3 / (float)iVar5) * (float10)fVar1 *
               (float10)(float)fVar8)) {
      return 1;
    }
  }
  return 0;
}



// ?SetupReactToFlyingObject@Villager@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x006f3be0

void _SetupReactToFlyingObject_Villager__UAEXPAVGameThingWithPos__PAVReaction___Z
               (undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  uint uVar4;
  
  iVar2 = FUN_007344da(param_1,0,&GameThingWithPos::RTTI_Type_Descriptor,
                       &Object::RTTI_Type_Descriptor,0);
  in_ECX[0x2f] = iVar2;
  if (iVar2 != 0) {
    if ((*(byte *)(in_ECX + 0x38) & 0x10) == 0) {
      (**(code **)(*in_ECX + 0x98c))(param_2,0xd7);
    }
    else {
      bVar1 = (**(code **)(*in_ECX + 0xb00))();
      if (*(int *)(&DAT_00cdab20 + (uint)bVar1 * 0x114) != 0) {
        bVar1 = *(byte *)((int)in_ECX + 0x8e);
      }
      (**(code **)(*in_ECX + 0x98c))(param_2,0xd7);
      if (*(int *)(iVar2 + 0x44) != 0) {
        uVar4 = (uint)bVar1;
        in_ECX[0x43] = *(int *)(iVar2 + 0x44);
        uVar3 = (**(code **)(*in_ECX + 0x860))(uVar4);
        FUN_006e98a0(uVar3,uVar4);
        return;
      }
    }
  }
  return;
}



// ?ReactToFirePriority@Villager@@UAEEPAVReaction@@0@Z @ 0x006f4250

uint _ReactToFirePriority_Villager__UAEEPAVReaction__0_Z(int param_1)

{
  float10 fVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined2 extraout_var;
  uint uVar5;
  int iVar6;
  int *in_ECX;
  float10 fVar7;
  undefined1 auStack_c [12];
  
  piVar2 = (int *)FUN_007344da(*(undefined4 *)(param_1 + 0x14),0,
                               &GameThingWithPos::RTTI_Type_Descriptor,
                               &SpellShield::RTTI_Type_Descriptor,0);
  uVar5 = 0;
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0x2c))();
    uVar5 = 0;
    if (iVar3 != 0) {
      piVar2 = in_ECX + 5;
      uVar4 = FUN_0067f810(auStack_c);
      FUN_006de0a0(uVar4,piVar2);
      iVar3 = (**(code **)(*in_ECX + 0x48))();
      uVar5 = 0;
      if (iVar3 == 0) {
LAB_006f42e8:
        return CONCAT31((int3)(uVar5 >> 8),DAT_00c70974);
      }
      fVar7 = (float10)FUN_006d8280(3);
      fVar1 = (float10)0.0;
      uVar5 = CONCAT22(extraout_var,
                       (ushort)(fVar7 < fVar1) << 8 | (ushort)(NAN(fVar7) || NAN(fVar1)) << 10 |
                       (ushort)(fVar7 == fVar1) << 0xe);
      if ((fVar7 == fVar1) == 0) {
        iVar3 = *(int *)(DAT_00c22ca4 + 0x201afc);
        iVar6 = (**(code **)(*in_ECX + 0x48))();
        uVar5 = in_ECX[10];
        if ((uint)(iVar3 - *(int *)(iVar6 + 0xea8)) <= *(uint *)(uVar5 + 0x364)) goto LAB_006f42e8;
      }
    }
  }
  return uVar5 & 0xffffff00;
}



// ?SetupReactToFight@Villager@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x006f48f0

void _SetupReactToFight_Villager__UAEXPAVGameThingWithPos__PAVReaction___Z(int param_1)

{
  int iVar1;
  int *in_ECX;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar1 = FUN_007344da(param_1,0,&GameThingWithPos::RTTI_Type_Descriptor,
                       &MagicTeleport::RTTI_Type_Descriptor,0);
  if (iVar1 != 0) {
    uStack_c = 0;
    uStack_8 = 0;
    uStack_4 = 0;
    (**(code **)(*in_ECX + 0x884))(&uStack_c);
    FUN_005b9d30(in_ECX,&stack0xfffffff0);
    in_ECX[0x2f] = param_1;
    (**(code **)(*in_ECX + 0x98c))
              (param_1,(((int)(uint)*(ushort *)((int)in_ECX + 0x5a) <= *(int *)(in_ECX[10] + 0x10c))
                        - 1 & 0x32) + 0xc9);
  }
  return;
}



// ?ReactToDeathPriority@Villager@@UAEEPAVReaction@@0@Z @ 0x006f4b50

uint _ReactToDeathPriority_Villager__UAEEPAVReaction__0_Z(int param_1)

{
  float10 fVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined2 extraout_var;
  int *in_ECX;
  float10 fVar6;
  
  FUN_005b0da0();
  piVar2 = (int *)FUN_007344da(*(undefined4 *)(param_1 + 0x14),0,
                               &GameThingWithPos::RTTI_Type_Descriptor,
                               &Villager::RTTI_Type_Descriptor,0);
  uVar5 = 0;
  if (piVar2 != (int *)0x0) {
    iVar3 = (**(code **)(*piVar2 + 0x2c))();
    uVar5 = 0;
    if ((iVar3 != 0) && (uVar5 = 0, (*(ushort *)(in_ECX + 0x38) & 0x200) == 0)) {
      uVar4 = (**(code **)(*piVar2 + 0x48))();
      uVar5 = (**(code **)(*in_ECX + 0x48))();
      if (uVar5 == uVar4) {
        fVar6 = (float10)FUN_006de0a0(in_ECX + 5,piVar2 + 5);
        fVar1 = (float10)10.0;
        uVar5 = CONCAT22(extraout_var,
                         (ushort)(fVar6 < fVar1) << 8 | (ushort)(NAN(fVar6) || NAN(fVar1)) << 10 |
                         (ushort)(fVar6 == fVar1) << 0xe);
        if (fVar6 < fVar1) {
          uVar5 = FUN_006e1dd0();
          if ((uVar5 != 0) && ((~*(ushort *)(in_ECX + 9) & 0x400) != 0)) {
            iVar3 = (**(code **)(*in_ECX + 0x2c))();
            uVar5 = 0;
            if (iVar3 != 0) {
              uVar5 = (**(code **)(*in_ECX + 0xaf4))();
              if (uVar5 == 0) {
                uVar5 = (**(code **)(*in_ECX + 0x4a0))();
                if (uVar5 == 0) {
                  uVar5 = (**(code **)(*in_ECX + 0xaf0))();
                  if (uVar5 == 0) {
                    return (uint)DAT_00c70dc0;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return uVar5 & 0xffffff00;
}



// ?SetupReactToDeath@Villager@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x006f4cb0

void _SetupReactToDeath_Villager__UAEXPAVGameThingWithPos__PAVReaction___Z
               (undefined4 param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  
  piVar1 = (int *)FUN_007344da(*(undefined4 *)(param_2 + 0x14),0,
                               &GameThingWithPos::RTTI_Type_Descriptor,
                               &Villager::RTTI_Type_Descriptor,0);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x2c))();
    if ((iVar2 != 0) && ((*(byte *)(in_ECX + 0xe1) & 4) == 0)) {
      FUN_006e6d80(*(undefined1 *)((int)piVar1 + 0xf2));
    }
  }
  return;
}



// ?SetupReactToDroppedByHand@Villager@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x006f4f50

void _SetupReactToDroppedByHand_Villager__UAEXPAVGameThingWithPos__PAVReaction___Z
               (undefined4 param_1,undefined4 param_2)

{
  int *in_ECX;
  
  in_ECX[0x2f] = (int)in_ECX;
  (**(code **)(*in_ECX + 0x98c))(param_2,0xc2);
  return;
}



// ?SetupReactToFainting@Villager@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x006f4f70

void _SetupReactToFainting_Villager__UAEXPAVGameThingWithPos__PAVReaction___Z
               (undefined4 param_1,undefined4 param_2)

{
  int *in_ECX;
  
  in_ECX[0x2f] = (int)in_ECX;
  (**(code **)(*in_ECX + 0x98c))(param_2,0xc3);
  return;
}



// ?ReactToFallingTreePriority@Villager@@UAEEPAVReaction@@0@Z @ 0x006f50c0

undefined1 _ReactToFallingTreePriority_Villager__UAEEPAVReaction__0_Z(void)

{
  return DAT_00c70fb4;
}



// ?SetupReactToFallingTree@Villager@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x006f50d0

void _SetupReactToFallingTree_Villager__UAEXPAVGameThingWithPos__PAVReaction___Z
               (undefined4 param_1,undefined4 param_2)

{
  int *in_ECX;
  int unaff_ESI;
  
  (**(code **)(*in_ECX + 0x98c))(param_2,0xd6);
  in_ECX[0x2f] = unaff_ESI;
  return;
}



// ?SetupFleeFromPredator@Villager@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x006f5640

void _SetupFleeFromPredator_Villager__UAEXPAVGameThingWithPos__PAVReaction___Z
               (int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int *in_ECX;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar1 = (**(code **)(*param_1 + 0x1b8))();
  if (iVar1 != 0) {
    if (*(int *)(param_2 + 0x28) == 0) {
      iVar1 = FUN_004300a0(300,s_C__dev_black_VillagerReaction_cp_00b47428,0x877);
      if (iVar1 == 0) {
        return;
      }
      iVar1 = FUN_004e9dc0(param_1 + 5,&DAT_00be6300,0,DAT_00be6310,0,param_1);
      if (iVar1 == 0) {
        return;
      }
      *(int *)(param_2 + 0x28) = iVar1;
    }
    in_ECX[0x2f] = (int)param_1;
    (**(code **)(*in_ECX + 0x98c))(param_2,7);
    return;
  }
  piVar2 = (int *)FUN_007344da(param_1,0,&GameThingWithPos::RTTI_Type_Descriptor,
                               &Object::RTTI_Type_Descriptor,0);
  (**(code **)(*piVar2 + 100))();
  iVar1 = *(int *)(param_2 + 0x28);
  if (iVar1 == 0) {
    piVar3 = (int *)FUN_007344da(param_1,0,&GameThingWithPos::RTTI_Type_Descriptor,
                                 &TownCentre::RTTI_Type_Descriptor,0);
    iVar1 = FUN_004300a0(300,s_C__dev_black_VillagerReaction_cp_00b47428,0x88b);
    if (iVar1 == 0) {
      return;
    }
    if (piVar3 == (int *)0x0) {
      uVar4 = 0;
    }
    else {
      uVar4 = (**(code **)(*piVar3 + 0x48))();
    }
    iVar1 = FUN_004e9dc0(param_1 + 5,&DAT_00be6460,piVar2,DAT_00be6470,0,uVar4);
    if (iVar1 == 0) {
      return;
    }
    *(int *)(param_2 + 0x28) = iVar1;
  }
  iVar5 = (**(code **)(*in_ECX + 0x974))();
  if (iVar5 != 0) {
    (**(code **)(*in_ECX + 0xb04))(1);
  }
  in_ECX[0x2f] = (int)param_1;
  iVar5 = FUN_0055e370(in_ECX);
  if (iVar5 != 1) {
    (**(code **)(*in_ECX + 0x98c))(param_2,7);
    return;
  }
  uStack_c = 0;
  uStack_8 = 0;
  uStack_4 = 0;
  FUN_005ae1a0(iVar1 + 0x14,&uStack_c);
  FUN_005af730(param_2,iVar1,0xcb,0);
  return;
}



// ?ReactToBreederPriority@Villager@@UAEEPAVReaction@@0@Z @ 0x006f57f0

uint _ReactToBreederPriority_Villager__UAEEPAVReaction__0_Z(int param_1)

{
  uint uVar1;
  int iVar2;
  int *in_ECX;
  
  if ((*(ushort *)(in_ECX + 0x38) & 0x200) != 0) {
    return 0;
  }
  uVar1 = (**(code **)(*in_ECX + 0x974))();
  if (uVar1 != 0) {
    return uVar1 & 0xffffff00;
  }
  iVar2 = (**(code **)(*in_ECX + 0x48))();
  if (iVar2 == 0) {
    return 0;
  }
  return CONCAT31((int3)((uint)iVar2 >> 8),*(int *)(param_1 + 0x14) != iVar2) - 1U & DAT_00c7107c;
}



// ?SetupReactToCrowd@Villager@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x006f5850

void _SetupReactToCrowd_Villager__UAEXPAVGameThingWithPos__PAVReaction___Z
               (undefined4 param_1,undefined4 param_2)

{
  int *in_ECX;
  int unaff_ESI;
  
  (**(code **)(*in_ECX + 0x98c))(param_2,0xe3);
  in_ECX[0x2f] = unaff_ESI;
  return;
}



// ?ReactToCrowdPriority@Villager@@UAEEPAVReaction@@0@Z @ 0x006f5880

uint _ReactToCrowdPriority_Villager__UAEEPAVReaction__0_Z(int param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int in_ECX;
  
  uVar2 = (**(code **)(**(int **)(param_1 + 0x14) + 0x2c8))(0);
  if (((uVar2 != 0) && (iVar1 = *(int *)(param_1 + 0x14), iVar1 != 0)) && (in_ECX != iVar1)) {
    iVar3 = FUN_006efcc0();
    uVar2 = 0;
    if (((iVar3 != 0) &&
        (uVar2 = *(uint *)(*(int *)(in_ECX + 0x28) + 0x1f8),
        uVar2 != *(uint *)(*(int *)(iVar1 + 0x28) + 0x1f8))) &&
       ((uVar2 = *(uint *)(param_1 + 0x1c), uVar2 == 0 && ((*(byte *)(in_ECX + 0x25) & 4) == 0)))) {
      return (uint)DAT_00c71018;
    }
  }
  return uVar2 & 0xffffff00;
}



// ?SetupReactToTownCelebration@Villager@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x006f5960

void _SetupReactToTownCelebration_Villager__UAEXPAVGameThingWithPos__PAVReaction___Z
               (undefined4 param_1,undefined4 param_2)

{
  int *in_ECX;
  int unaff_ESI;
  
  (**(code **)(*in_ECX + 0x98c))(param_2,0xeb);
  in_ECX[0x2f] = unaff_ESI;
  return;
}



// ?FleeFromPredatorPriority@Villager@@UAEEPAVReaction@@0@Z @ 0x006f5990

undefined1 _FleeFromPredatorPriority_Villager__UAEEPAVReaction__0_Z(int param_1)

{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *in_ECX;
  
  iVar3 = (**(code **)(**(int **)(param_1 + 0x14) + 0x2c8))(0);
  if ((iVar3 != 0) && (piVar1 = *(int **)(param_1 + 0x14), piVar1 != (int *)0x0)) {
    cVar2 = (**(code **)(*piVar1 + 0xb00))();
    if (cVar2 == '\x18') {
      iVar3 = FUN_006efcc0();
      if ((iVar3 != 0) && (*(int *)(in_ECX[10] + 0x1f8) != *(int *)(piVar1[10] + 0x1f8))) {
        iVar3 = (**(code **)(*piVar1 + 0x1c))();
        iVar4 = (**(code **)(*in_ECX + 0x1c))();
        if ((iVar4 == iVar3) && ((*(byte *)((int)in_ECX + 0x25) & 4) == 0)) {
          return DAT_00c71018;
        }
      }
    }
  }
  return 0;
}



// ?ReactToVillagerInHandPriority@Villager@@UAEEPAVReaction@@0@Z @ 0x006f5a80

undefined4 _ReactToVillagerInHandPriority_Villager__UAEEPAVReaction__0_Z(int param_1)

{
  int iVar1;
  int *piVar2;
  float10 fVar3;
  undefined4 uVar4;
  undefined2 extraout_var;
  int in_ECX;
  float10 fVar5;
  
  iVar1 = *(int *)(param_1 + 0x24);
  piVar2 = *(int **)(param_1 + 0x14);
  fVar5 = (float10)FUN_006de0a0(in_ECX + 0x14,piVar2 + 5);
  fVar3 = (float10)*(float *)(&DAT_00c70490 + iVar1 * 100);
  uVar4 = CONCAT22((short)((uint)(iVar1 * 5) >> 0x10),
                   (ushort)(fVar5 < fVar3) << 8 | (ushort)(NAN(fVar5) || NAN(fVar3)) << 10 |
                   (ushort)(fVar5 == fVar3) << 0xe);
  if (fVar5 < fVar3 == 0 && (fVar5 == fVar3) == 0) {
    fVar5 = (float10)(**(code **)(*piVar2 + 0x154))();
    fVar3 = (float10)3.0;
    uVar4 = CONCAT22(extraout_var,
                     (ushort)(fVar5 < fVar3) << 8 | (ushort)(NAN(fVar5) || NAN(fVar3)) << 10 |
                     (ushort)(fVar5 == fVar3) << 0xe);
    if (fVar5 < fVar3) {
      return uVar4;
    }
  }
  return CONCAT31((int3)((uint)uVar4 >> 8),DAT_00c71144);
}



// ?SetupReactToVillagerInHand@Villager@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x006f5ae0

void _SetupReactToVillagerInHand_Villager__UAEXPAVGameThingWithPos__PAVReaction___Z
               (int param_1,undefined4 param_2)

{
  int *in_ECX;
  
  in_ECX[0x2f] = param_1;
  (**(code **)(*in_ECX + 0x98c))(param_2,6);
  return;
}



// ?SetupReactToBurningObjectInHand@Villager@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x006f5b00

void _SetupReactToBurningObjectInHand_Villager__UAEXPAVGameThingWithPos__PAVReaction___Z
               (undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = FUN_007344da(param_1,0,&GameThingWithPos::RTTI_Type_Descriptor,
                       &SpellShield::RTTI_Type_Descriptor,0);
  if (iVar1 != 0) {
    FUN_006c23c0(in_ECX);
    (**(code **)(*in_ECX + 0x988))(param_2,1);
    in_ECX[0x2f] = iVar1;
    in_ECX[0x25] = *(int *)(iVar1 + 0xf8);
    FUN_005a15c0(iVar1 + 0x14);
  }
  return;
}



// ?SetupReactToMagicShieldStruck@Villager@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x006f5b70

void _SetupReactToMagicShieldStruck_Villager__UAEXPAVGameThingWithPos__PAVReaction___Z
               (int param_1,undefined4 param_2)

{
  FUN_006f90e0(param_2,param_1 + 0x14);
  return;
}



// ?ReactToBurningObjectInHandPriority@Villager@@UAEEPAVReaction@@0@Z @ 0x006f5b90

uint _ReactToBurningObjectInHandPriority_Villager__UAEEPAVReaction__0_Z(int param_1)

{
  int iVar1;
  uint uVar2;
  int *in_ECX;
  
  iVar1 = FUN_007344da(*(undefined4 *)(param_1 + 0x14),0,&GameThingWithPos::RTTI_Type_Descriptor,
                       &SpellShield::RTTI_Type_Descriptor,0);
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = (**(code **)(*in_ECX + 0xb00))();
    if (((char)uVar2 == -0x58) &&
       ((uVar2 = in_ECX[0x41], uVar2 != *(uint *)(iVar1 + 0x14) ||
        (in_ECX[0x42] != *(int *)(iVar1 + 0x18))))) {
      return CONCAT31((int3)(uVar2 >> 8),DAT_00c7120c);
    }
  }
  return uVar2 & 0xffffff00;
}



// ?ReactToMagicShieldStruckPriority@Villager@@UAEEPAVReaction@@0@Z @ 0x006f5bf0

undefined1 _ReactToMagicShieldStruckPriority_Villager__UAEEPAVReaction__0_Z(void)

{
  return DAT_00c71270;
}



// ?IsReadyForNewScriptAction@Villager@@UAEIXZ @ 0x006f67c0

bool _IsReadyForNewScriptAction_Villager__UAEIXZ(void)

{
  char cVar1;
  
  cVar1 = FUN_005b0da0();
  return cVar1 == '\x04';
}



// ?SetDying@Villager@@UAE_NXZ @ 0x006f8500

undefined4 _SetDying_Villager__UAE_NXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x48))();
  if ((*(byte *)(in_ECX + 0x2d) & 1) != 1) {
    (**(code **)(*in_ECX + 0x5b0))(0);
    (**(code **)(*in_ECX + 0x8e4))(0xe);
    *(byte *)(in_ECX + 0x2d) = *(byte *)(in_ECX + 0x2d) | 1;
    FUN_006e0080();
    *(byte *)(in_ECX + 0x2d) = *(byte *)(in_ECX + 0x2d) | 0x30;
  }
  if ((iVar1 != 0) && (*(int **)(iVar1 + 0x740) != (int *)0x0)) {
    iVar1 = (**(code **)(**(int **)(iVar1 + 0x740) + 0xd4))();
    if (iVar1 != 0) {
      *(undefined2 *)(in_ECX + 0x16) = *(undefined2 *)(in_ECX[10] + 0x294);
      goto LAB_006f857e;
    }
  }
  *(undefined2 *)(in_ECX + 0x16) = *(undefined2 *)(in_ECX[10] + 0x290);
LAB_006f857e:
  if ((*(byte *)(in_ECX + 0x38) & 0x40) == 0) {
    *(int *)(DAT_00c22ca4 + 0x201b10) = *(int *)(DAT_00c22ca4 + 0x201b10) + -1;
    *(ushort *)(in_ECX + 0x38) = *(ushort *)(in_ECX + 0x38) | 0x40;
  }
  return 1;
}



// ?Dying@Villager@@UAE_NXZ @ 0x006f85b0

undefined4 _Dying_Villager__UAE_NXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x444))();
  if (iVar1 == 7) {
    (**(code **)(*in_ECX + 0x8e4))(0xf);
  }
  else {
    FUN_005ab520(0xf,1);
  }
  if ((*(byte *)(in_ECX + 0x38) & 4) == 0) {
    iVar1 = (**(code **)(*in_ECX + 0x48))();
    if ((iVar1 != 0) && (iVar1 = (**(code **)(*in_ECX + 0x48))(), *(int *)(iVar1 + 0x740) != 0)) {
      return 1;
    }
    FUN_0067efc0();
  }
  return 1;
}



// ?Dead@Villager@@UAE_NXZ @ 0x006f8620

void _Dead_Villager__UAE_NXZ(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int *in_ECX;
  undefined4 uVar4;
  
  if ((int *)in_ECX[0x11] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x11] + 0xc))(0);
    in_ECX[0x11] = 0;
  }
  if ((DAT_00cebdf4 & 1) == 0) {
    DAT_00cebdf4 = DAT_00cebdf4 | 1;
    iVar1 = 0x1ff;
    if (*DAT_00d76c64 < 0x200) {
      iVar1 = 0;
    }
    DAT_00cebdfc = DAT_00d76c64[iVar1 + 1];
  }
  if ((*(byte *)((int)in_ECX + 0x25) & 4) != 0) goto LAB_006f87b0;
  iVar1 = (**(code **)(*(int *)in_ECX[0x10] + 0xf8))();
  if (iVar1 != DAT_00cebdfc) {
    FUN_005eca60(0,0x3f800000,0xffffffff);
    iVar1 = FUN_005bfb00();
    if (iVar1 == 0) {
      if (DAT_00dd88e0 == 0) {
        if (*DAT_00df82a8 < 0xf5) {
          DAT_00dd88e0 = DAT_00df82a8[1];
        }
        else {
          DAT_00dd88e0 = DAT_00df82a8[0xf5];
        }
        if (*DAT_00df82a8 < 0xf8) {
          DAT_00dd88e4 = DAT_00df82a8[1];
        }
        else {
          DAT_00dd88e4 = DAT_00df82a8[0xf8];
        }
        if (*DAT_00df82a8 < 0xf6) {
          DAT_00dd88e8 = DAT_00df82a8[1];
        }
        else {
          DAT_00dd88e8 = DAT_00df82a8[0xf6];
        }
        if (*DAT_00df82a8 < 0xf9) {
          DAT_00dd88ec = DAT_00df82a8[1];
        }
        else {
          DAT_00dd88ec = DAT_00df82a8[0xf9];
        }
      }
      iVar1 = in_ECX[10];
      uVar2 = (**(code **)(*in_ECX + 0x8cc))();
      if (uVar2 < *(uint *)(iVar1 + 0x138)) {
        iVar1 = FUN_00746d70(0xc,s_C__dev_black_VillagerStates_cpp_00b474c0,0x238);
        if (iVar1 != 0) {
          uVar3 = *(undefined4 *)(in_ECX[10] + 0x204);
          iVar1 = in_ECX[0x10];
          uVar4 = 1;
LAB_006f878b:
          FUN_00782290(iVar1,uVar3,uVar4);
        }
      }
      else {
        iVar1 = FUN_00746d70(0xc,s_C__dev_black_VillagerStates_cpp_00b474c0,0x23b);
        if (iVar1 != 0) {
          uVar4 = 0;
          uVar3 = (**(code **)(*(int *)in_ECX[10] + 0x2c))(0);
          iVar1 = in_ECX[0x10];
          goto LAB_006f878b;
        }
      }
    }
  }
  (**(code **)(*(int *)in_ECX[0x10] + 0xf4))(DAT_00cebdfc,DAT_00cebdfc);
  (**(code **)(*(int *)in_ECX[0x10] + 0xc4))();
LAB_006f87b0:
  _Dead_PuzzleHorse__UAE_NXZ();
  return;
}



// ?GetImportance@Villager@@UAEMXZ @ 0x006f8ab0

float10 _GetImportance_Villager__UAEMXZ(void)

{
  uint uVar1;
  int *in_ECX;
  
  uVar1 = (**(code **)(*in_ECX + 0x8cc))();
  return (float10)uVar1 * (float10)0.001;
}



// ?ExitInHand@Villager@@UAEHW4VILLAGER_STATES@@@Z @ 0x006f8ce0

undefined4 _ExitInHand_Villager__UAEHW4VILLAGER_STATES___Z(char param_1)

{
  if ((((param_1 != '\x18') && (param_1 != '\v')) && (param_1 != '\x0e')) &&
     ((param_1 != '\x0f' && (param_1 != '\x10')))) {
    return 0;
  }
  return 1;
}



// ?ArrivesAtWoodReaction@Villager@@UAE_NXZ @ 0x006f8e00

undefined4 _ArrivesAtWoodReaction_Villager__UAE_NXZ(void)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  int *piVar5;
  int *piVar6;
  int *piStack_8;
  int iStack_4;
  
  iVar2 = FUN_006e1ce0();
  if (iVar2 != 0) {
    iVar2 = FUN_006e1ce0();
    *(byte *)(iVar2 + 0x7c) = *(byte *)(iVar2 + 0x7c) | 0x10;
  }
  piStack_8 = (int *)0x0;
  iStack_4 = 0;
  iVar2 = FUN_006f9040();
  piVar5 = piStack_8;
  if (iVar2 == 0) {
    iVar2 = FUN_006e6430(&piStack_8,in_ECX + 5);
    piVar5 = piStack_8;
    if (iVar2 != 0) {
      for (; piVar5 != (int *)0x0; piVar5 = (int *)piVar5[1]) {
        piVar1 = (int *)*piVar5;
        iVar2 = FUN_005ec420();
        if (iVar2 != 0) {
          (**(code **)(*piVar1 + 0x7f4))();
          iVar2 = (**(code **)(*piVar1 + 0x644))(iVar2);
          if (((((~*(ushort *)(in_ECX + 9) & 0x400) == 0) ||
               (iVar3 = (**(code **)(*in_ECX + 0x2c))(), iVar3 == 0)) ||
              (iVar3 = (**(code **)(*in_ECX + 0xaf4))(), iVar3 != 0)) ||
             ((iVar3 = (**(code **)(*in_ECX + 0x4a0))(), iVar3 != 0 ||
              (iVar3 = (**(code **)(*in_ECX + 0xaf0))(), iVar3 != 0)))) {
            if (iVar2 != 0xb) goto LAB_006f8eee;
            iVar3 = (**(code **)(*in_ECX + 0xaf4))();
          }
          else {
            iVar3 = iVar2;
            if (iVar2 == 9) {
              iVar3 = (**(code **)(*piVar1 + 0x48))();
              in_ECX[0x45] = iVar3;
              goto LAB_006f8f0b;
            }
          }
          if (iVar3 != 0) {
LAB_006f8f0b:
            FUN_006e56e0(piVar1,iVar2,0);
            piVar5 = piStack_8;
            if (piStack_8 == (int *)0x0) {
              return 1;
            }
            do {
              piVar1 = piVar5;
              piVar6 = (int *)0x0;
              if (piVar5 == (int *)0x0) {
                return 1;
              }
              do {
                piVar4 = piVar1;
                if (*piVar4 == *piVar5) {
                  if (piVar6 == (int *)0x0) {
                    piStack_8 = (int *)piVar5[1];
                  }
                  else {
                    piVar6[1] = piVar4[1];
                  }
                  FUN_007290de(piVar4);
                  iStack_4 = iStack_4 + -1;
                  piVar5 = piStack_8;
                  break;
                }
                piVar1 = (int *)piVar4[1];
                piVar6 = piVar4;
              } while ((int *)piVar4[1] != (int *)0x0);
              if (piVar5 == (int *)0x0) {
                return 1;
              }
            } while( true );
          }
        }
LAB_006f8eee:
      }
    }
    FUN_006e56e0(0,in_ECX[0x41],0);
    piVar5 = piStack_8;
  }
  do {
    if (piVar5 == (int *)0x0) {
      return 1;
    }
    piVar1 = piVar5;
    piVar6 = (int *)0x0;
    if (piVar5 == (int *)0x0) {
      return 1;
    }
    do {
      piVar4 = piVar1;
      if (*piVar4 == *piVar5) {
        if (piVar6 == (int *)0x0) {
          piStack_8 = (int *)piVar5[1];
        }
        else {
          piVar6[1] = piVar4[1];
        }
        FUN_007290de(piVar4);
        iStack_4 = iStack_4 + -1;
        piVar5 = piStack_8;
        break;
      }
      piVar1 = (int *)piVar4[1];
      piVar6 = piVar4;
    } while ((int *)piVar4[1] != (int *)0x0);
  } while( true );
}



// ?BeingEaten@Villager@@UAE_NXZ @ 0x006f9390

undefined4 _BeingEaten_Villager__UAE_NXZ(void)

{
  undefined4 uVar1;
  int *in_ECX;
  undefined4 unaff_ESI;
  undefined4 uVar2;
  
  *(short *)(in_ECX + 0x16) = (short)in_ECX[0x16] + -1;
  if ((short)in_ECX[0x16] == 0) {
    *(undefined2 *)(in_ECX + 0x16) = 0x32;
    if ((*(byte *)((int)in_ECX + 0x25) & 0x40) != 0) {
      FUN_005ab520(0xb,1);
      return 1;
    }
    (**(code **)(*in_ECX + 0x11c))();
    (**(code **)(*in_ECX + 0x5b0))(0);
    uVar2 = 1;
    uVar1 = (**(code **)(*in_ECX + 0x1c))(unaff_ESI,1);
    FUN_006e0860(3,uVar1,unaff_ESI,uVar2);
  }
  return 1;
}



// ?GetWorshipSite@Villager@@UAEPAVWorshipSite@@XZ @ 0x006fa200

undefined4 _GetWorshipSite_Villager__UAEPAVWorshipSite__XZ(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x48))();
  if (iVar1 != 0) {
    piVar2 = (int *)(**(code **)(*in_ECX + 0x48))();
    uVar3 = (**(code **)(*piVar2 + 0x30c))();
    return uVar3;
  }
  iVar1 = (**(code **)(*in_ECX + 0x114))();
  if (iVar1 != 0) {
    uVar3 = FUN_006e1aa0();
    (**(code **)(*in_ECX + 0x114))(uVar3);
    uVar3 = FUN_0044ea50(uVar3);
    return uVar3;
  }
  return 0;
}



// ?GetTown@Villager@@UAEPAVTown@@XZ @ 0x00706d30

undefined4 _GetTown_Villager__UAEPAVTown__XZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x124);
}



