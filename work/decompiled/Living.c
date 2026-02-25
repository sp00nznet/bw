// Decompiled functions for class: Living
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?IsPoisoned@Living@@UAEIXZ @ 0x00413dc0

byte _IsPoisoned_Living__UAEIXZ(void)

{
  int in_ECX;
  
  return *(byte *)(in_ECX + 0xb4) >> 1 & 1;
}



// ?SetPoisoned@Living@@UAEXH@Z @ 0x00413dd0

void _SetPoisoned_Living__UAEXH_Z(byte param_1)

{
  int in_ECX;
  
  *(ushort *)(in_ECX + 0xb4) = (param_1 & 1) << 1 | *(ushort *)(in_ECX + 0xb4) & 0xfffd;
  return;
}



// ?IsSkeleton@Living@@UBEIXZ @ 0x00413e00

uint _IsSkeleton_Living__UBEIXZ(void)

{
  int in_ECX;
  
  return (*(byte *)(in_ECX + 0xb4) & 0x40) >> 6;
}



// ?SetSkeleton@Living@@UAEXH@Z @ 0x00413e10

void _SetSkeleton_Living__UAEXH_Z(byte param_1)

{
  int in_ECX;
  
  *(ushort *)(in_ECX + 0xb4) = (param_1 & 1) << 6 | *(ushort *)(in_ECX + 0xb4) & 0xffbf;
  return;
}



// ?IsScriptInterruptableState@Living@@UBE_NW4VILLAGER_STATES@@@Z @ 0x00413e60

bool _IsScriptInterruptableState_Living__UBE_NW4VILLAGER_STATES___Z(int param_1)

{
  return param_1 == 0x18;
}



// ?ReactToBallPriority@Living@@UAEEPAVReaction@@0@Z @ 0x00413e70

undefined1 _ReactToBallPriority_Living__UAEEPAVReaction__0_Z(void)

{
  return 0;
}



// ?MoveByTeleport@Living@@UAEXABUMapCoords@@@Z @ 0x00413e80

undefined4 _MoveByTeleport_Living__UAEXABUMapCoords___Z(void)

{
  int iVar1;
  int *in_ECX;
  
  if (((*(byte *)(in_ECX + 0x2d) & 1) != 1) && ((char)in_ECX[0x23] != '\x0f')) {
    iVar1 = (**(code **)(*in_ECX + 0xd4))();
    if (iVar1 == 1) {
      return 0;
    }
  }
  return 1;
}



// ?CanBePickedUp@Living@@UAE_NXZ @ 0x00413eb0

uint _CanBePickedUp_Living__UAE_NXZ(void)

{
  int in_ECX;
  
  return ((ushort)~*(ushort *)(in_ECX + 0x24) & 0x2000) >> 0xd;
}



// ?IsStompable@Living@@UAE_NXZ @ 0x00413ec0

bool _IsStompable_Living__UAE_NXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0xaf0))();
  return iVar1 == 0;
}



// ?IsFunctional@Living@@UAE_NXZ @ 0x00413ed0

undefined4 _IsFunctional_Living__UAE_NXZ(void)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  
  iVar1 = (**(code **)(*in_ECX + 0x2c))();
  if (iVar1 == 1) {
    fVar2 = (float10)(**(code **)(*in_ECX + 0x11c))();
    if (fVar2 != (float10)0.0) {
      return 1;
    }
  }
  return 0;
}



// ?CanBeAttackedByCreature@Living@@UAEIPAVCreature@@@Z @ 0x00413f00

undefined4 _CanBeAttackedByCreature_Living__UAEIPAVCreature___Z(int *param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0xaf0))();
  if (((iVar1 == 0) && (*(int *)(in_ECX[10] + 0xc4) != 0)) && (param_1 != in_ECX)) {
    return 1;
  }
  return 0;
}



// ?CanBePlayedWithByCreature@Living@@UAEIPAVCreature@@@Z @ 0x00413f40

undefined4 _CanBePlayedWithByCreature_Living__UAEIPAVCreature___Z(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0xaf0))();
  if ((iVar1 == 0) && (*(int *)(in_ECX[10] + 200) != 0)) {
    return 1;
  }
  return 0;
}



// ?CanBeInspectedByCreature@Living@@UAEIPAVCreature@@@Z @ 0x00413f70

undefined4 _CanBeInspectedByCreature_Living__UAEIPAVCreature___Z(undefined4 param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0xaf0))();
  if (iVar1 == 0) {
    iVar1 = _CanBeInspectedByCreature_Object__UAE_NPAVCreature___Z(param_1);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}



// ?CanBeStompedOnByCreature@Living@@UAEIPAVCreature@@@Z @ 0x00413fa0

bool _CanBeStompedOnByCreature_Living__UAEIPAVCreature___Z(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0xaf0))();
  return iVar1 == 0;
}



// ?SetSpecularColor@Living@@UAEXULH3DColor@@@Z @ 0x00413fb0

void _SetSpecularColor_Living__UAEXULH3DColor___Z(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xd0) = param_1;
  return;
}



// ?GetSpecularColor@Living@@UAE?AULH3DColor@@XZ @ 0x00413fc0

undefined4 _GetSpecularColor_Living__UAE_AULH3DColor__XZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xd0);
}



// ?ExitPlayAnim@Living@@UAEHW4VILLAGER_STATES@@@Z @ 0x00414000

undefined4 _ExitPlayAnim_Living__UAEHW4VILLAGER_STATES___Z(int param_1)

{
  return *(undefined4 *)(&DAT_00b73fcc + param_1 * 0xb8);
}



// ?GetAge@Living@@UAEIXZ @ 0x004141f0

void _GetAge_Living__UAEIXZ(undefined4 param_1)

{
  FUN_00414350(param_1);
  FUN_00414270(param_1);
  _GetAge_Living__UAEIXZ(param_1);
  return;
}



// ?SetAnim__i@Living@@UAEXH@Z @ 0x004147c0

void _SetAnim__i_Living__UAEXH_Z(void)

{
  int in_ECX;
  
  (**(code **)(&DAT_00c33298 + (uint)*(byte *)(in_ECX + 0x8c) * 0x90))();
  return;
}



// ?IsDancing@Living@@UAE_NXZ @ 0x004160f0

undefined4 _IsDancing_Living__UAE_NXZ(int *param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 0x2c))();
  if (((iVar1 != 0) && (((byte)~(byte)*(ushort *)(param_1 + 9) >> 6 & 1) != 0)) &&
     ((*(ushort *)(param_1 + 9) & 4) == 0)) {
    iVar1 = *(int *)(*(int *)(in_ECX + 0x28) + 0x20c);
    if (((iVar1 != 0) && (iVar1 <= *(short *)(in_ECX + 0xe4))) &&
       ((*(uint *)(*(int *)(in_ECX + 0x28) + 0x230) & *(uint *)(param_1[10] + 0x70)) != 0)) {
      return 1;
    }
  }
  return 0;
}



// ?GetFleeingPositionFromStationaryObject@Living@@UAEXPAUMapCoords@@PAVGameThingWithPos@@M@Z @ 0x00416770

byte _GetFleeingPositionFromStationaryObject_Living__UAEXPAUMapCoords__PAVGameThingWithPos__M_Z
               (void)

{
  byte bVar1;
  int in_ECX;
  uint uStack_4;
  
  bVar1 = *(byte *)(in_ECX + 0x8c);
  uStack_4 = (uint)bVar1;
  if (*(int *)(&DAT_00b73fc4 + uStack_4 * 0xb8) == 0) {
    bVar1 = *(byte *)(in_ECX + 0x8d);
  }
  return bVar1;
}



// ?StopReactingAndSetState@Living@@UAEXXZ @ 0x004167b0

void _StopReactingAndSetState_Living__UAEXXZ(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x8e4))((&DAT_00b73fd4)[(uint)*(byte *)((int)in_ECX + 0x8e) * 0xb8]);
  return;
}



// ?IsStateForInterface@Living@@UBE_NW4VILLAGER_STATES@@@Z @ 0x004175c0

undefined4 _IsStateForInterface_Living__UBE_NW4VILLAGER_STATES___Z(int param_1)

{
  uint uVar1;
  int *in_ECX;
  int iVar2;
  
  uVar1 = (**(code **)(*in_ECX + 0xb00))();
  iVar2 = (uVar1 & 0xff) * 0x90;
  param_1 = param_1 * 0x90;
  if ((*(int *)(&DAT_00c33258 + iVar2) == *(int *)(&DAT_00c33258 + param_1)) &&
     ((*(int *)(&DAT_00c33258 + iVar2) == 0 ||
      (((*(int *)(&DAT_00c3325c + iVar2) == *(int *)(&DAT_00c3325c + param_1) &&
        (*(int *)(&DAT_00c33260 + iVar2) == *(int *)(&DAT_00c33260 + param_1))) &&
       (*(int *)(&DAT_00c33264 + iVar2) == *(int *)(&DAT_00c33264 + param_1))))))) {
    return 1;
  }
  return 0;
}



// ?IsDeathState@Living@@UBE_NW4VILLAGER_STATES@@@Z @ 0x00417680

void _IsDeathState_Living__UBE_NW4VILLAGER_STATES___Z(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0xb00))();
  return;
}



// ?IsDead@Living@@UAE_NXZ @ 0x00417f50

bool _IsDead_Living__UAE_NXZ(void)

{
  int iVar1;
  uint uVar2;
  int *in_ECX;
  
  iVar1 = in_ECX[10];
  uVar2 = (**(code **)(*in_ECX + 0x8cc))();
  return uVar2 < *(uint *)(iVar1 + 0x138);
}



// ?GetInHandImmersionTexture@Living@@UAE?AW4IMMERSION_EFFECT_TYPE@@XZ @ 0x004181c0

undefined4 _GetInHandImmersionTexture_Living__UAE_AW4IMMERSION_EFFECT_TYPE__XZ(void)

{
  return 0x16;
}



// ?ReactToVillagerInHandPriority@Living@@UAEEPAVReaction@@0@Z @ 0x0041b310

uint _ReactToVillagerInHandPriority_Living__UAEEPAVReaction__0_Z(int param_1)

{
  float fVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  int in_ECX;
  
  iVar3 = FUN_007344da(*(undefined4 *)(param_1 + 0x14),0,&GameThingWithPos::RTTI_Type_Descriptor,
                       &Living::RTTI_Type_Descriptor,0);
  uVar4 = 0;
  if (iVar3 != 0) {
    fVar1 = *(float *)(*(int *)(iVar3 + 0x28) + 300);
    fVar2 = *(float *)(*(int *)(in_ECX + 0x28) + 300);
    uVar4 = (uint)(ushort)((ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                          (ushort)(fVar1 == fVar2) << 0xe);
    if (fVar1 < fVar2 || (fVar1 == fVar2) != 0) {
      return uVar4;
    }
  }
  return CONCAT31((int3)(uVar4 >> 8),(undefined1)DAT_00c70f50);
}



// ?SetupReactToBreeder@Living@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x0041b360

void _SetupReactToBreeder_Living__UAEXPAVGameThingWithPos__PAVReaction___Z
               (undefined4 param_1,undefined4 param_2)

{
  int *in_ECX;
  int unaff_ESI;
  
  (**(code **)(*in_ECX + 0x98c))(param_2,0x31);
  in_ECX[0x2f] = unaff_ESI;
  return;
}



// ?SetupReactToBreeder@Living@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x0041b390

void _SetupReactToBreeder_Living__UAEXPAVGameThingWithPos__PAVReaction___Z
               (undefined4 param_1,undefined4 param_2)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x9a0))(param_1,param_2);
  return;
}



// ?SetupReactToMagicTree@Living@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x0041b3b0

void _SetupReactToMagicTree_Living__UAEXPAVGameThingWithPos__PAVReaction___Z
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
    }
  }
  return;
}



// ?StopReactingAndSetState@Living@@UAEXXZ @ 0x00461ec0

void _StopReactingAndSetState_Living__UAEXXZ(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00461ec2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0x994))();
  return;
}



// ?IsPosValidForMapCellExistance@Living@@UAEIABUMapCoords@@@Z @ 0x00463ba0

undefined4 _IsPosValidForMapCellExistance_Living__UAEIABUMapCoords___Z(int *param_1)

{
  int iVar1;
  int iVar2;
  float fVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int in_ECX;
  float10 fVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined1 auStack_30 [48];
  
  uVar8 = 0x3f800000;
  uVar7 = 0;
  uVar4 = FUN_004ba1b0(in_ECX);
  FUN_004d1300(0x18,1,0,uVar4,uVar7,uVar8);
  FUN_004aba10(auStack_30,1,1);
  *(undefined4 *)(*(int *)(in_ECX + 0x164) + 0x1c14) = 1;
  FUN_004de990();
  fVar3 = (float)param_1[2];
  fVar6 = (float10)FUN_00760fd0();
  iVar1 = *param_1;
  iVar2 = param_1[1];
  puVar5 = (undefined4 *)FUN_00746d70(0x10,s_C__dev_black_Creature_cpp_008fe0a0,0xd95);
  if (puVar5 == (undefined4 *)0x0) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    puVar5[1] = (float)iVar1 * 0.00015258789;
    puVar5[2] = (float)(fVar6 + (float10)fVar3);
    *puVar5 = &vftable_SubArgumentPoint;
    puVar5[3] = (float)iVar2 * 0.00015258789;
  }
  FUN_004de610(0x5d,puVar5,0,0,0,0xffffffff,0,0,0,0xffffffff);
  fVar3 = *(float *)(in_ECX + 0x11d4);
  fVar6 = (float10)FUN_00760fd0();
  iVar1 = *(int *)(in_ECX + 0x11cc);
  iVar2 = *(int *)(in_ECX + 0x11d0);
  puVar5 = (undefined4 *)FUN_00746d70(0x14,s_C__dev_black_Creature_cpp_008fe0a0,0xd98);
  if (puVar5 == (undefined4 *)0x0) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    puVar5[1] = (float)iVar1 * 0.00015258789;
    puVar5[2] = (float)(fVar6 + (float10)fVar3);
    *puVar5 = &vftable_SubArgumentPointAndFloat;
    puVar5[3] = (float)iVar2 * 0.00015258789;
    puVar5[4] = 0x40a00000;
  }
  FUN_004de610(8,puVar5,&LAB_004b4c70,0,0,0,&LAB_004aefb0,0,0,0);
  FUN_004de610(0x7b,0,0,0,0,0xffffffff,0,0,0,0xffffffff);
  *(undefined4 *)(*(int *)(in_ECX + 0x164) + 0x1c10) = 1;
  FUN_004d13a0();
  return 1;
}



// ?DebugShowTime@Living@@UAEIIEE@Z @ 0x004663b0

undefined4 _DebugShowTime_Living__UAEIIEE_Z(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(*(int *)(in_ECX + 0x164) + 0xf60) == 0x57) {
    return 1;
  }
  uVar1 = _DebugShowTime_Living__UAEIIEE_Z();
  return uVar1;
}



// ?IsChild@Living@@UAE_NXZ @ 0x004668c0

undefined4 _IsChild_Living__UAE_NXZ(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = *(int *)(*(int *)(in_ECX + 0x164) + 0xf60);
  if ((iVar1 != 9) && (iVar1 != 0x105)) {
    return 0;
  }
  return 1;
}



// ?IsAvailableForBeliefButNotReaction@Living@@UAE_NW4REACTION@@@Z @ 0x004d26e0

void _IsAvailableForBeliefButNotReaction_Living__UAE_NW4REACTION___Z(int *param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  float10 fVar3;
  int *piVar4;
  
  if ((int *)param_1[5] != in_ECX) {
    piVar4 = param_1;
    fVar3 = (float10)(**(code **)(*(int *)param_1[5] + 0x1b0))();
    iVar1 = (**(code **)(*param_1 + 0x1c))();
    iVar2 = (**(code **)(*in_ECX + 0x1c))();
    if (iVar1 == iVar2) {
      *(float *)(in_ECX[0x59] + 0x18c64) = (float)fVar3 * 4.0 + *(float *)(in_ECX[0x59] + 0x18c64);
      return;
    }
    iVar1 = FUN_007344da(param_1[5],0,&GameThingWithPos::RTTI_Type_Descriptor,
                         &Creature::RTTI_Type_Descriptor,0,piVar4);
    if (iVar1 != 0) {
      FUN_004ac1a0(iVar1,(float)fVar3 * 12.0);
    }
  }
  return;
}



// ?IsInterestedInWoodObject@Living@@UAE_NPAVObject@@@Z @ 0x004d2780

undefined4 _IsInterestedInWoodObject_Living__UAE_NPAVObject___Z(int param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0xd4))();
  if ((iVar1 != 0) && (in_ECX[0x418] != 0)) {
    iVar1 = FUN_005ab680();
    if (((iVar1 == 0) &&
        (((*(ushort *)(in_ECX + 9) & 0x80) == 0 && ((*(ushort *)(in_ECX + 9) & 0x400) == 0)))) &&
       ((*(int *)(in_ECX[0x59] + 0x1c14) == 0 || (in_ECX[0xe0] != 0)))) {
      iVar1 = FUN_00464dc0();
      if (((((iVar1 == 0) && (iVar1 = in_ECX[0x59], *(int *)(iVar1 + 0xf60) != 0x15)) &&
           ((*(int *)(iVar1 + 0x1be8) == 0 ||
            (*(int *)(*(int *)(*(int *)(iVar1 + 0x1be8) + 0x164) + 0xf60) != 0x15)))) &&
          ((((in_ECX[0xe1] == 0 && (in_ECX[0x42b] == 0)) && (in_ECX[0x42c] == 0)) &&
           ((*(byte *)(in_ECX + 9) & 0x10) == 0)))) &&
         (((*(int *)(iVar1 + 0x1c38) == 0 || (0x96 < (uint)(&DAT_00c70460)[param_1 * 0x19])) &&
          ((*(int *)(iVar1 + 0x1c10) == 0 && (in_ECX[0x43d] == 0)))))) {
        return 1;
      }
    }
  }
  return 0;
}



// ?ReactToScaffoldPriority@Living@@UAEEPAVReaction@@0@Z @ 0x004d28b0

void _ReactToScaffoldPriority_Living__UAEEPAVReaction__0_Z(undefined4 param_1,int param_2)

{
  __ftol(*(undefined4 *)(&DAT_00c7046c + param_2 * 100),0);
  return;
}



// ?FollowObjectPriority@Living@@UAEEPAVReaction@@0@Z @ 0x004d29a0

uint _FollowObjectPriority_Living__UAEEPAVReaction__0_Z(int param_1)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = FUN_007344da(*(undefined4 *)(param_1 + 0x14),0,&GameThingWithPos::RTTI_Type_Descriptor,
                       &Spell::RTTI_Type_Descriptor,0);
  if ((uVar1 != 0) && (*(int *)(uVar1 + 0xa0) == in_ECX)) {
    return uVar1 & 0xffffff00;
  }
  uVar1 = _FollowObjectPriority_Living__UAEEPAVReaction__0_Z(param_1,0);
  return uVar1;
}



// ?SetupLookAtSpell@Living@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x004d2a30

void _SetupLookAtSpell_Living__UAEXPAVGameThingWithPos__PAVReaction___Z
               (undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_007344da(param_1,0,&GameThingWithPos::RTTI_Type_Descriptor,
                       &Spell::RTTI_Type_Descriptor,0);
  FUN_004d2f90(param_2,*(undefined4 *)(iVar1 + 0xb4),param_1);
  return;
}



// ?FollowSpellPriority@Living@@UAEEPAVReaction@@0@Z @ 0x004d2ae0

uint _FollowSpellPriority_Living__UAEEPAVReaction__0_Z(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint in_ECX;
  
  uVar1 = *(uint *)(param_1 + 0x14);
  if ((((uVar1 != in_ECX) && (iVar2 = *(int *)(in_ECX + 0x164), *(int *)(iVar2 + 0x1c14) == 0)) &&
      (*(int *)(iVar2 + 0x1be8) == 0)) &&
     ((*(int *)(iVar2 + 0xf58) == 0 || (*(uint *)(*(int *)(iVar2 + 0xf58) + 0x30) != uVar1)))) {
    uVar4 = FUN_004ba200(in_ECX,uVar1);
    iVar5 = FUN_007344da(uVar4,0,&CreatureBelief::RTTI_Type_Descriptor,
                         &CreatureBeliefAboutCreature::RTTI_Type_Descriptor,0);
    iVar3 = DAT_00c22ca4;
    iVar2 = *(int *)(iVar5 + 0x78);
    if (iVar2 != 0) {
      in_ECX = __ftol();
      if ((uint)(*(int *)(iVar3 + 0x201afc) - iVar2) <= in_ECX) goto LAB_004d2bac;
    }
    uVar4 = *(undefined4 *)(iVar3 + 0x201afc);
    *(undefined4 *)(iVar5 + 0x78) = uVar4;
    return CONCAT31((int3)((uint)uVar4 >> 8),0xff);
  }
LAB_004d2bac:
  return in_ECX & 0xffffff00;
}



// ?SetupFollowObject@Living@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x004d2bc0

void _SetupFollowObject_Living__UAEXPAVGameThingWithPos__PAVReaction___Z
               (undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  float10 fVar4;
  undefined4 uVar5;
  TypeDescriptor *pTVar6;
  TypeDescriptor *pTVar7;
  undefined4 uVar8;
  
  iVar1 = FUN_007344da(param_1,0,&GameThingWithPos::RTTI_Type_Descriptor,
                       &Creature::RTTI_Type_Descriptor,0);
  uVar8 = 0;
  pTVar7 = &CreatureBeliefAboutCreature::RTTI_Type_Descriptor;
  pTVar6 = &CreatureBelief::RTTI_Type_Descriptor;
  uVar5 = 0;
  uVar2 = FUN_004ba1b0(iVar1);
  iVar3 = FUN_007344da(uVar2,uVar5,pTVar6,pTVar7,uVar8);
  fVar4 = (float10)FUN_004ca6a0(iVar3,6);
  in_ECX[0x2f] = iVar1;
  if ((*(int *)(in_ECX[0x59] + 0xf58) != iVar3) && ((float10)0.0 < fVar4)) {
    FUN_004ab9b0(6,0,0x3f,iVar3,0,0,1);
  }
  (**(code **)(*in_ECX + 0x98c))(param_2,0);
  return;
}



// ?ReactToWoodPriority@Living@@UAEEPAVReaction@@0@Z @ 0x004d2d00

undefined1 _ReactToWoodPriority_Living__UAEEPAVReaction__0_Z(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x1c))();
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*in_ECX + 0x1c))();
    if (*(int *)(iVar1 + 0xf8) != 2) {
      return DAT_00c70780;
    }
  }
  return 0;
}



// ?SetupReactToWood@Living@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x004d2d30

void _SetupReactToWood_Living__UAEXPAVGameThingWithPos__PAVReaction___Z
               (undefined4 param_1,undefined4 param_2)

{
  FUN_004d2f90(param_2,0x15,param_1);
  return;
}



// ?ReactToNewBuildingPriority@Living@@UAEEPAVReaction@@0@Z @ 0x004d3500

uint _ReactToNewBuildingPriority_Living__UAEEPAVReaction__0_Z(int param_1)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x1c))();
  uVar2 = 0;
  if (iVar1 != 0) {
    uVar2 = (**(code **)(*in_ECX + 0x1c))();
    if (*(int *)(uVar2 + 0xf8) != 2) {
      piVar3 = (int *)FUN_007344da(*(undefined4 *)(param_1 + 0x14),0,
                                   &GameThingWithPos::RTTI_Type_Descriptor,
                                   &GInterfaceStatus::RTTI_Type_Descriptor,0);
      uVar2 = 0;
      if (piVar3 != (int *)0x0) {
        uVar4 = (**(code **)(*piVar3 + 0x1c))();
        uVar2 = (**(code **)(*in_ECX + 0x1c))();
        if (uVar4 == uVar2) {
          iVar1 = FUN_0059c190();
          uVar2 = FUN_004615b0(*(int *)(param_1 + 0x14) + 0x14);
          if ((uVar2 != 0) && (iVar1 != 0)) {
            return DAT_00c70aa0 * 3;
          }
        }
      }
    }
  }
  return uVar2 & 0xffffff00;
}



// ?SetupReactToNewBuilding@Living@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x004d3590

void _SetupReactToNewBuilding_Living__UAEXPAVGameThingWithPos__PAVReaction___Z
               (int param_1,undefined4 param_2)

{
  int iVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int *in_ECX;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  iVar1 = in_ECX[0x59];
  *(undefined4 *)(iVar1 + 0xf7c) = *(undefined4 *)(iVar1 + 0xf4c);
  *(undefined4 *)(iVar1 + 0xf80) = *(undefined4 *)(iVar1 + 0xf50);
  *(undefined4 *)(iVar1 + 0xf84) = *(undefined4 *)(iVar1 + 0xf54);
  *(undefined4 *)(iVar1 + 0xf88) = *(undefined4 *)(iVar1 + 0xf58);
  *(undefined4 *)(iVar1 + 0xf8c) = *(undefined4 *)(iVar1 + 0xf5c);
  *(undefined4 *)(iVar1 + 0xf90) = *(undefined4 *)(iVar1 + 0xf60);
  *(undefined4 *)(iVar1 + 0xf94) = *(undefined4 *)(iVar1 + 0xf64);
  *(undefined4 *)(iVar1 + 0xf98) = *(undefined4 *)(iVar1 + 0xf68);
  *(undefined4 *)(iVar1 + 0xf9c) = *(undefined4 *)(iVar1 + 0xf6c);
  uVar6 = 1;
  *(undefined4 *)(iVar1 + 4000) = *(undefined4 *)(iVar1 + 0xf70);
  uVar5 = 0;
  uVar4 = 0;
  *(undefined4 *)(iVar1 + 0xfa4) = *(undefined4 *)(iVar1 + 0xf74);
  uVar3 = FUN_004ba1b0(in_ECX);
  FUN_004ab9b0(6,0,8,uVar3,uVar4,uVar5,uVar6);
  in_ECX[0x2f] = param_1;
  (**(code **)(*in_ECX + 0x98c))(param_2,0);
  FUN_0067bcb0(0x42700000,s_C__dev_black_CreatureReaction_cp_00b0e38c,599);
  uVar2 = __ftol(param_2,(int)(1000 / (ulonglong)DAT_00c22d78),0);
  *(undefined2 *)(in_ECX + 0x16) = uVar2;
  return;
}



// ?SetupReactToDroppedByHand@Living@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x004d3a10

void _SetupReactToDroppedByHand_Living__UAEXPAVGameThingWithPos__PAVReaction___Z
               (undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int *in_ECX;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  uVar4 = 1;
  uVar3 = 0;
  uVar2 = 0;
  uVar1 = FUN_004ba1b0(in_ECX);
  FUN_004ab9b0(8,0,0x11,uVar1,uVar2,uVar3,uVar4);
  in_ECX[0x2f] = (int)in_ECX;
  (**(code **)(*in_ECX + 0x98c))(param_2,0);
  return;
}



// ?Draw@Living@@UAEXXZ @ 0x004f74d0

void _Draw_Living__UAEXXZ(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_00527d30();
  if ((*(int *)(*(int *)(iVar1 + 0x3a0) + 0x4878) != 4) ||
     (*(int *)(*(int *)(iVar1 + 0x3a0) + 0x4904) != in_ECX)) {
    FUN_004f79e0(0x3f800000);
  }
  return;
}



// ?IsDead@Living@@UAE_NXZ @ 0x0052e150

uint _IsDead_Living__UAE_NXZ(void)

{
  int in_ECX;
  
  return (*(byte *)(in_ECX + 0xe0) & 8) >> 3;
}



// ?ExitPlayAnim@Living@@UAEHW4VILLAGER_STATES@@@Z @ 0x0052e1c0

undefined4 _ExitPlayAnim_Living__UAEHW4VILLAGER_STATES___Z(int param_1)

{
  return *(undefined4 *)(&DAT_00cdab28 + param_1 * 0x114);
}



// ?IsPosValidForMapCellExistance@Living@@UAEIABUMapCoords@@@Z @ 0x005aaf40

void _IsPosValidForMapCellExistance_Living__UAEIABUMapCoords___Z(undefined4 param_1)

{
  int *in_ECX;
  
  FUN_006b5f20(in_ECX + 5,0x27,0,2,0,0,1,1,0);
  FUN_006b5f20(param_1,0x26,0,2,0,0,1,1,0);
  (**(code **)(*in_ECX + 0x55c))(param_1);
  return;
}



// ?SetDying@Living@@UAE_NXZ @ 0x005aaf90

undefined4 _SetDying_Living__UAE_NXZ(void)

{
  undefined2 uVar1;
  int *in_ECX;
  
  if ((*(byte *)(in_ECX + 9) & 0x40) == 0) {
    if ((*(byte *)(in_ECX + 0x2d) & 1) != 1) {
      (**(code **)(*in_ECX + 0x5b0))(0);
      (**(code **)(*in_ECX + 0x8e4))(0xe);
      *(byte *)(in_ECX + 0x2d) = *(byte *)(in_ECX + 0x2d) | 0x31;
    }
    uVar1 = (**(code **)(*in_ECX + 0x880))();
    *(undefined2 *)(in_ECX + 0x16) = uVar1;
    return 1;
  }
  return 0;
}



// ?GetNumTurnsToDieOver@Living@@UAEIXZ @ 0x005aafe0

undefined4 _GetNumTurnsToDieOver_Living__UAEIXZ(void)

{
  return 600;
}



// ?Downed@Living@@UAE_NXZ @ 0x005ab0b0

undefined4 _Downed_Living__UAE_NXZ(void)

{
  int in_ECX;
  
  FUN_005ab520(0x12,1);
  *(undefined2 *)(in_ECX + 0x58) = 300;
  return 1;
}



// ?CallVirtualFunctionsForCreation@Living@@UAEXABUMapCoords@@@Z @ 0x005ab410

void _CallVirtualFunctionsForCreation_Living__UAEXABUMapCoords___Z(undefined4 param_1)

{
  int *in_ECX;
  
  _CallVirtualFunctionsForCreation_Object__UAEXABUMapCoords___Z(param_1);
  (**(code **)(*in_ECX + 0x8f8))(1);
  return;
}



// ?IsStateExitFunctionSameAs@Living@@UBE_NW4VILLAGER_STATES@@@Z @ 0x005ab500

undefined4 _IsStateExitFunctionSameAs_Living__UBE_NW4VILLAGER_STATES___Z(uint param_1)

{
  if ((0xc < param_1) && (param_1 < 0x12)) {
    return 1;
  }
  return 0;
}



// ?SetAnim__li@Living@@UAEXHH@Z @ 0x005ab5e0

void _SetAnim__li_Living__UAEXHH_Z(undefined4 param_1)

{
  undefined4 uVar1;
  int *in_ECX;
  
  uVar1 = (**(code **)(*in_ECX + 0x8fc))();
  (**(code **)(*in_ECX + 0x8f4))(uVar1,param_1);
  return;
}



// ?DebugShowTime@Living@@UAEIIEE@Z @ 0x005ab670

bool _DebugShowTime_Living__UAEIIEE_Z(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0xd8) != 0;
}



// ?InterfaceSetInMagicHand@Living@@UAEIPAVGInterfaceStatus@@@Z @ 0x005ab710

undefined4 _InterfaceSetInMagicHand_Living__UAEIPAVGInterfaceStatus___Z(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x8e8))();
  (**(code **)(*in_ECX + 0x8e4))(0x18);
  return 1;
}



// ?MoveInFlock@Living@@UAE_NXZ @ 0x005ab810

undefined4 _MoveInFlock_Living__UAE_NXZ(void)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  int in_ECX;
  float10 fVar6;
  undefined4 uVar7;
  float fVar8;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined1 auStack_c [12];
  
  uStack_18 = 0;
  uStack_14 = 0;
  uStack_10 = 0;
  if (*(int *)(in_ECX + 0xb8) != 0) {
    iVar2 = FUN_005aba70(in_ECX + 0x14,0x3f800000);
    if (iVar2 == 0) {
      iVar2 = FUN_005ab9d0();
      if (iVar2 != 0) {
        uVar1 = FUN_005aba00();
        fVar8 = (float)uVar1;
        uVar7 = 0;
        uVar3 = FUN_005ab9c0(0,fVar8);
        puVar4 = (undefined4 *)FUN_005abae0(auStack_c,uVar3,uVar7,fVar8);
        uStack_18 = *puVar4;
        uStack_14 = puVar4[1];
        uStack_10 = puVar4[2];
        FUN_005b0de0(&uStack_18,0x1b);
        return 0x23;
      }
      uVar3 = FUN_00506580(in_ECX + 0x14);
      fVar6 = (float10)FUN_006de0a0(uVar3);
      uVar1 = FUN_005aba20();
      if ((float)uVar1 < (float)fVar6) {
        uVar1 = FUN_005aba20();
        fVar8 = (float)uVar1;
        uVar7 = 0;
        uVar3 = FUN_00506580(0,fVar8);
        puVar4 = (undefined4 *)FUN_005abae0(auStack_c,uVar3,uVar7,fVar8);
        uStack_18 = *puVar4;
        uStack_14 = puVar4[1];
        uStack_10 = puVar4[2];
        uVar7 = 0x3f800000;
        uVar3 = FUN_00506580(0x3f800000);
        iVar2 = FUN_005aba70(uVar3,uVar7);
        iVar5 = FUN_005aba70(&uStack_18,0x3f800000);
        if ((iVar5 != 0) || (iVar2 == 0)) {
          FUN_005b0de0(&uStack_18,0x1b);
          return 0x23;
        }
      }
      return 0;
    }
  }
  return 1;
}



// ?GetAge@Living@@UAEIXZ @ 0x005abd10

void _GetAge_Living__UAEIXZ(int param_1)

{
  int in_ECX;
  
  *(int *)(in_ECX + 0xa0) = *(int *)(DAT_00c22ca4 + 0x201afc) - DAT_00c22d44 * param_1;
  return;
}



// ?HasSunk@Living@@UAE_NXZ @ 0x005abd40

undefined4 _HasSunk_Living__UAE_NXZ(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *in_ECX;
  undefined4 uVar4;
  int *piVar5;
  undefined4 uVar6;
  
  iVar1 = (**(code **)(*in_ECX + 0x2c))();
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = FUN_005ec980();
  if (iVar1 != 0) {
    piVar2 = (int *)FUN_005ec980();
    uVar6 = 0;
    uVar4 = 0x15;
    piVar5 = in_ECX;
    uVar3 = FUN_005ec980(0x15);
    (**(code **)(*piVar2 + 0x1c))(uVar3);
    FUN_004cb260(uVar3,uVar4,piVar5,uVar6);
  }
  (**(code **)(*in_ECX + 0x6a4))();
  (**(code **)(*in_ECX + 0x8e4))(0xf);
  (**(code **)(*in_ECX + 0xc))(0);
  return 1;
}



// ?ReactToPhysicsImpact@Living@@UAEXPAVPhysicsObject@@_N@Z @ 0x005abdb0

void _ReactToPhysicsImpact_Living__UAEXPAVPhysicsObject___N_Z(int param_1,float param_2)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int *in_ECX;
  undefined1 local_60 [8];
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined1 local_40 [64];
  
  if (param_2._0_1_ == '\0') {
    fVar1 = *(float *)(param_1 + 8) / (*(float *)(param_1 + 0x15c) * 9.81);
    if (2.0 < fVar1) {
      param_2 = (fVar1 - 2.0) * 0.03;
      uVar2 = FUN_005f6180();
      uVar3 = FUN_005f3c50(uVar2);
      FUN_004fc540(3,uVar3,uVar2);
      FUN_004fca90(&param_2);
      iVar4 = (**(code **)(*in_ECX + 0x774))(local_40);
      if (iVar4 != 0) {
        (**(code **)(*in_ECX + 0x5cc))(&local_44,0);
      }
      FUN_00430270();
      return;
    }
  }
  else if ((*(byte *)(in_ECX + 9) & 0x40) == 0) {
    local_58 = 0x3f800000;
    local_54 = 0;
    local_50 = 0x3f800000;
    local_4c = 0;
    local_48 = 0x41f00000;
    local_44 = 0;
    (**(code **)(*in_ECX + 0x784))(local_60,&local_4c,&local_58,0,1,0);
    return;
  }
  return;
}



// ?ExitDanceInScript@Living@@UAEHW4VILLAGER_STATES@@@Z @ 0x005abec0

undefined4 _ExitDanceInScript_Living__UAEHW4VILLAGER_STATES___Z(char param_1)

{
  int iVar1;
  int *in_ECX;
  
  if ((param_1 != '\n') && (param_1 != '\v')) {
    iVar1 = (**(code **)(*in_ECX + 0x96c))(param_1);
    if ((iVar1 == 0) && (param_1 != '\x10')) {
      return 0;
    }
  }
  return 1;
}



// ?ExitInHand@Living@@UAEHW4VILLAGER_STATES@@@Z @ 0x005abf00

undefined4 _ExitInHand_Living__UAEHW4VILLAGER_STATES___Z(char param_1)

{
  int iVar1;
  int *in_ECX;
  
  if ((param_1 != '\x18') && (param_1 != '\v')) {
    iVar1 = (**(code **)(*in_ECX + 0x96c))(param_1);
    if ((iVar1 == 0) && (param_1 != '\x10')) {
      return 0;
    }
  }
  return 1;
}



// ?ValidToApplyThisToObject@Living@@UAEIPAVGInterfaceStatus@@PAVObject@@@Z @ 0x005abf40

bool _ValidToApplyThisToObject_Living__UAEIPAVGInterfaceStatus__PAVObject___Z
               (undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_007344da(param_2,0,&Object::RTTI_Type_Descriptor,&WorshipTotem::RTTI_Type_Descriptor,0
                      );
  return iVar1 != 0;
}



// ?ApplyThisToObject@Living@@UAEIPAVGInterfaceStatus@@PAVObject@@PAUGestureSystemPacketData@@@Z @ 0x005abf70

undefined4
_ApplyThisToObject_Living__UAEIPAVGInterfaceStatus__PAVObject__PAUGestureSystemPacketData___Z
          (int *param_1,undefined4 param_2)

{
  float fVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int *in_ECX;
  float unaff_EBX;
  float10 fVar6;
  undefined1 *puVar7;
  float fStack_188;
  float fStack_184;
  float fStack_180;
  undefined1 auStack_17c [16];
  LH_SamplePlayOptions aLStack_16c [4];
  undefined4 uStack_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_148;
  float fStack_13c;
  float fStack_138;
  float fStack_134;
  
  iVar2 = FUN_007344da(param_2,0,&Object::RTTI_Type_Descriptor,&WorshipTotem::RTTI_Type_Descriptor,0
                      );
  if (iVar2 == 0) {
    return 0;
  }
  fVar6 = (float10)(**(code **)(*in_ECX + 0x5c0))();
  fStack_188 = (float)fVar6;
  iVar2 = *(int *)(iVar2 + 0x100);
  fVar6 = (float10)(**(code **)(*in_ECX + 0x11c))();
  fStack_188 = (float)(fVar6 * (float10)fStack_188);
  (**(code **)(*param_1 + 0x1c))();
  *(float *)(iVar2 + 0xf0) = fStack_188 + *(float *)(iVar2 + 0xf0);
  *(float *)(iVar2 + 0xf4) = fStack_188 + *(float *)(iVar2 + 0xf4);
  (**(code **)(*in_ECX + 0x5b0))(0);
  if (param_1 != (int *)0x0) {
    fStack_188 = (float)param_1[0x32];
    fStack_184 = (float)param_1[0x33];
    fStack_180 = (float)param_1[0x34];
    LH_SamplePlayOptions::LH_SamplePlayOptions(aLStack_16c);
    uStack_168 = *(undefined4 *)(DAT_00bf4e68 + 0x3ac);
    fStack_138 = fStack_184;
    fStack_13c = fStack_188;
    uStack_148 = 0xb3;
    uStack_164 = 1;
    fStack_134 = fStack_180;
    uStack_160 = 0;
    FUN_00423db0();
    LH_SamplePlayOptions::~LH_SamplePlayOptions(aLStack_16c);
  }
  piVar3 = (int *)FUN_00527d60();
  if (param_1 == piVar3) {
    puVar4 = (undefined4 *)FUN_00746d70(0xa0,s_C__dev_black_Living_cpp_00b20720,0x54d);
    if (puVar4 != (undefined4 *)0x0) {
      *puVar4 = &PTR_LAB_008049b4;
      puVar4[5] = 0;
      puVar4[6] = 0;
      puVar4[1] = DAT_00df8148;
      DAT_00df8148 = puVar4;
    }
    FUN_00733e17(auStack_17c,s__3_0f_00b20738,(double)unaff_EBX);
    iVar2 = FUN_00527d30();
    fVar1 = *(float *)(iVar2 + 0x3c0);
    fVar6 = (float10)FUN_00760fd0();
    puVar7 = &stack0xfffffe74;
    fStack_184 = (float)(fVar6 + (float10)fVar1);
    fStack_188 = (float)*(int *)(iVar2 + 0x3b8) * 0.00015258789;
    fStack_180 = (float)*(int *)(iVar2 + 0x3bc) * 0.00015258789;
    uVar5 = FUN_00789090(auStack_17c,puVar7);
    FUN_0078c9f0(&fStack_188,uVar5,puVar7);
  }
  (**(code **)(*in_ECX + 0xc))();
  return 3;
}



// ?EnterMoveToPos@Living@@UAEIW4VILLAGER_STATES@@0@Z @ 0x005ac190

undefined4 _EnterMoveToPos_Living__UAEIW4VILLAGER_STATES__0_Z(undefined4 param_1,uint param_2)

{
  int iVar1;
  int in_ECX;
  undefined4 uVar2;
  
  iVar1 = FUN_007344da();
  if (iVar1 == 0) {
    return 1;
  }
  iVar1 = FUN_006e2010();
  if (iVar1 != 0) {
    return 1;
  }
  iVar1 = *(int *)(in_ECX + 0xb0);
  if (iVar1 == 0) {
    return 1;
  }
  if (*(uint *)(iVar1 + 0x44) != (param_2 & 0xff)) {
    return 1;
  }
  *(undefined4 *)(iVar1 + 0x44) = 0;
  FUN_005adb30();
  iVar1 = *(int *)(in_ECX + 0xac);
  if (iVar1 == 0) {
    FUN_005b0de0();
    return 0x23;
  }
  if (*(int *)(iVar1 + 0x20) == 0) {
    iVar1 = *(int *)(iVar1 + 0x14);
    __ftol();
    FUN_0079aca0();
    if (&stack0x00000000 == &DAT_00000024) goto LAB_005ac2ef;
    uVar2 = **(undefined4 **)(iVar1 + 4);
  }
  else {
    __ftol();
    iVar1 = *(int *)(iVar1 + 0x14);
    FUN_0079aca0();
    if (&stack0x00000000 == &DAT_00000024) goto LAB_005ac2ef;
    uVar2 = **(undefined4 **)(iVar1 + 4);
  }
  FUN_0079a7b0(uVar2);
LAB_005ac2ef:
  __ftol();
  __ftol();
  FUN_005b0de0();
  return 0x23;
}



// ?ExitReaction@Living@@UAEHW4VILLAGER_STATES@@@Z @ 0x005ac370

undefined4 _ExitReaction_Living__UAEHW4VILLAGER_STATES___Z(uint param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  FUN_005c56b0(in_ECX);
  (**(code **)(*in_ECX + 0x974))();
  iVar1 = (**(code **)(*in_ECX + 0x95c))(param_1 & 0xff);
  if (iVar1 != 0) {
    return 1;
  }
  if (in_ECX[0x2c] == 0) {
    iVar1 = FUN_005ada30();
    in_ECX[0x2c] = iVar1;
    if (iVar1 == 0) goto LAB_005ac3e8;
  }
  uVar2 = (**(code **)(*in_ECX + 0xb00))();
  *(uint *)(in_ECX[0x2c] + 0x44) = uVar2 & 0xff;
  FUN_005ada60(in_ECX);
LAB_005ac3e8:
  uVar3 = (**(code **)(*in_ECX + 0x924))(param_1);
  return uVar3;
}



// ?EnterMoveOnPath@Living@@UAEIEE@Z @ 0x005ac400

undefined4 _EnterMoveOnPath_Living__UAEIEE_Z(undefined1 param_1,uint param_2)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_007344da();
  if (iVar1 != 0) {
    iVar1 = FUN_006e2010(param_1,param_2 & 0xff);
    if (((iVar1 == 0) && (iVar1 = *(int *)(in_ECX + 0xb0), iVar1 != 0)) &&
       (*(uint *)(iVar1 + 0x44) == (param_2 & 0xff))) {
      *(undefined4 *)(iVar1 + 0x44) = 0;
      FUN_005b0de0(in_ECX + 0x80,param_2);
      return 0x23;
    }
  }
  return 1;
}



// ?ExitInScript@Living@@UAEHW4VILLAGER_STATES@@@Z @ 0x005ac4c0

undefined4 _ExitInScript_Living__UAEHW4VILLAGER_STATES___Z(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x95c))(param_1 & 0xff);
  if (iVar1 != 0) {
    return 1;
  }
  if (in_ECX[0x2c] == 0) {
    iVar1 = FUN_005ada30();
    in_ECX[0x2c] = iVar1;
  }
  if (in_ECX[0x2c] != 0) {
    *(undefined4 *)(in_ECX[0x2c] + 0x44) = 5;
    FUN_005ada60(in_ECX);
  }
  (**(code **)(*in_ECX + 0xb04))(1);
  (**(code **)(*in_ECX + 0x974))();
  FUN_005c56b0(in_ECX);
  uVar2 = (**(code **)(*in_ECX + 0x924))(param_1);
  return uVar2;
}



// ?ExitMoveOnPath@Living@@UAEHW4VILLAGER_STATES@@@Z @ 0x005ac6d0

undefined4 _ExitMoveOnPath_Living__UAEHW4VILLAGER_STATES___Z(void)

{
  int in_ECX;
  
  FUN_005c56b0(in_ECX);
  *(undefined4 *)(in_ECX + 0x60) = 0;
  return 1;
}



// ?ExitNoChangeState@Living@@UAEHW4VILLAGER_STATES@@@Z @ 0x005ac9a0

undefined4 _ExitNoChangeState_Living__UAEHW4VILLAGER_STATES___Z(void)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0xcc);
  if (iVar1 != 0) {
    puVar2 = *(undefined4 **)(iVar1 + 0x28);
    puVar4 = (undefined4 *)0x0;
    while (puVar3 = puVar4, puVar4 = puVar2, puVar4 != (undefined4 *)0x0) {
      puVar2 = (undefined4 *)*puVar4;
      if (puVar4[1] == in_ECX) {
        if (puVar4 == *(undefined4 **)(iVar1 + 0x28)) {
          *(undefined4 **)(iVar1 + 0x28) = puVar2;
        }
        else {
          *puVar3 = puVar2;
        }
        *(int *)(iVar1 + 0x2c) = *(int *)(iVar1 + 0x2c) + -1;
        FUN_007290de(puVar4);
        puVar4 = puVar3;
      }
    }
    *(undefined4 *)(in_ECX + 0xcc) = 0;
  }
  FUN_005c56b0(in_ECX);
  return 1;
}



// ?MoveAlongPath@Living@@UAEIXZ @ 0x005acb40

undefined4 _MoveAlongPath_Living__UAEIXZ(void)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int *in_ECX;
  float10 fVar4;
  undefined4 uVar5;
  float fStack_30;
  float fStack_28;
  
  iVar1 = in_ECX[0x2b];
  if (iVar1 == 0) {
    return 1;
  }
  if ((float)*(ushort *)((int)in_ECX + 0x5a) != *(float *)(iVar1 + 0x2c)) {
    *(float *)(iVar1 + 0x2c) = (float)*(ushort *)((int)in_ECX + 0x5a);
    fVar2 = ((float)*(ushort *)((int)in_ECX + 0x5a) / 655.0) * 0.1;
    fVar3 = 0.0;
    if (fVar2 != 0.0) {
      fVar3 = *(float *)(*(int *)(*(int *)(*(int *)(in_ECX[0x2b] + 0x14) + 8) + 0x208) + 0xc) /
              fVar2;
    }
    *(undefined4 *)(in_ECX[0x2b] + 0x28) = 0;
    if (0.01 < fVar3) {
      *(float *)(in_ECX[0x2b] + 0x28) =
           (float)*(int *)(*(int *)(*(int *)(*(int *)(in_ECX[0x2b] + 0x14) + 4) + 0x208) + 0x10) /
           fVar3;
    }
    (**(code **)(*in_ECX + 0x8f8))();
    *(float *)(in_ECX[0x2b] + 0x2c) = (float)*(ushort *)((int)in_ECX + 0x5a);
  }
  iVar1 = in_ECX[0x2b];
  if (*(int *)(iVar1 + 0x20) == 0) {
    iVar1 = *(int *)(iVar1 + 0x14);
    __ftol();
    FUN_0079aca0();
    if (&stack0x00000000 == &DAT_00000030) goto LAB_005acce8;
    uVar5 = **(undefined4 **)(iVar1 + 4);
  }
  else {
    __ftol();
    iVar1 = *(int *)(iVar1 + 0x14);
    FUN_0079aca0();
    if (&stack0x00000000 == &DAT_00000030) goto LAB_005acce8;
    uVar5 = **(undefined4 **)(iVar1 + 4);
  }
  FUN_0079a7b0(uVar5);
LAB_005acce8:
  iVar1 = in_ECX[0x2b];
  fVar4 = (float10)FUN_005ace00();
  if ((float10)*(float *)(iVar1 + 0x1c) <= fVar4) {
    FUN_005ab4e0();
    return 1;
  }
  *(float *)(iVar1 + 0x24) = *(float *)(iVar1 + 0x28) + *(float *)(iVar1 + 0x24);
  iVar1 = in_ECX[0x2b];
  fVar2 = (float)*(int *)(*(int *)(*(int *)(*(int *)(iVar1 + 0x14) + 4) + 0x208) + 0x10);
  if (fVar2 < *(float *)(iVar1 + 0x24)) {
    *(float *)(iVar1 + 0x24) = fVar2;
  }
  fVar2 = (float)in_ECX[0xb] * 0.00015258789 - fStack_30;
  fVar3 = (float)in_ECX[0xc] * 0.00015258789 - fStack_28;
  if (0.001 < fVar2 * fVar2 + fVar3 * fVar3) {
    iVar1 = *in_ECX;
    FUN_00795e70();
    (**(code **)(iVar1 + 0x524))();
  }
  __ftol();
  __ftol();
  (**(code **)(*in_ECX + 0x55c))();
  return 1;
}



// ?DanceType@Living@@UAEIXZ @ 0x005ace20

bool _DanceType_Living__UAEIXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0xaf0))();
  return iVar1 == 0;
}



// ?RemoveFromGame@Living@@UAEIXZ @ 0x005ace30

undefined4 _RemoveFromGame_Living__UAEIXZ(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *in_ECX;
  
  if (in_ECX[0x25] != 0) {
    (**(code **)(*in_ECX + 0x994))();
  }
  iVar2 = DAT_00c22ca4;
  piVar3 = *(int **)(DAT_00c22ca4 + 0x201c78);
  if (piVar3 != (int *)0x0) {
    while (piVar3 != in_ECX) {
      piVar3 = (int *)piVar3[0x29];
      if (piVar3 == (int *)0x0) {
        return 1;
      }
    }
    if (piVar3 != (int *)0x0) {
      piVar3 = *(int **)(DAT_00c22ca4 + 0x201c78);
      if (piVar3 == in_ECX) {
        *(int *)(DAT_00c22ca4 + 0x201c78) = in_ECX[0x29];
      }
      else {
        if (piVar3 == (int *)0x0) {
          return 1;
        }
        while (piVar1 = (int *)piVar3[0x29], piVar1 != in_ECX) {
          piVar3 = piVar1;
          if (piVar1 == (int *)0x0) {
            return 1;
          }
        }
        piVar3[0x29] = in_ECX[0x29];
      }
      *(int *)(iVar2 + 0x201c7c) = *(int *)(iVar2 + 0x201c7c) + -1;
      in_ECX[0x29] = 0;
    }
  }
  return 1;
}



// ?Save@Living@@UAEIAAVGameOSFile@@@Z @ 0x005acf00

undefined4 _Save_Living__UAEIAAVGameOSFile___Z(uint param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  iVar2 = param_1;
  iVar3 = _Save_MobileWallHug__UAEIAAVGameOSFile___Z(param_1);
  if (iVar3 == 0) {
    return 0;
  }
  FUN_00531bc0(*(undefined4 *)(in_ECX + 200));
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0xcc));
  if (DAT_00b19ac8 != 0) {
    iVar3 = FUN_0072be90((byte *)(in_ECX + 0x8c),6,0);
    if (iVar3 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + *(byte *)(in_ECX + 0x8c) + 6;
  }
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0x94));
  if (DAT_00b19ac8 != 0) {
    iVar3 = FUN_0072be90((byte *)(in_ECX + 0x9c),4,0);
    if (iVar3 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + *(byte *)(in_ECX + 0x9c) + 4;
    if (DAT_00b19ac8 != 0) {
      iVar3 = FUN_0072be90((byte *)(in_ECX + 0xa0),4,0);
      if (iVar3 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + *(byte *)(in_ECX + 0xa0) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar3 = FUN_0072be90((byte *)(in_ECX + 0xa8),1,0);
        if (iVar3 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + *(byte *)(in_ECX + 0xa8) + 1;
      }
    }
  }
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0xac));
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0xb0));
  if (DAT_00b19ac8 != 0) {
    iVar3 = FUN_0072be90((byte *)(in_ECX + 0xb4),2,0);
    if (iVar3 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + *(byte *)(in_ECX + 0xb4) + 2;
  }
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0xb8));
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0xbc));
  FUN_00531bc0(*(undefined4 *)(in_ECX + 200));
  if (DAT_00b19ac8 != 0) {
    iVar3 = FUN_0072be90((byte *)(in_ECX + 0xc4),4,0);
    if (iVar3 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + *(byte *)(in_ECX + 0xc4) + 4;
    if (DAT_00b19ac8 != 0) {
      iVar3 = FUN_0072be90((byte *)(in_ECX + 0xd0),4,0);
      if (iVar3 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + *(byte *)(in_ECX + 0xd0) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar3 = FUN_0072be90((byte *)(in_ECX + 0xd4),1,0);
        if (iVar3 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + *(byte *)(in_ECX + 0xd4) + 1;
      }
    }
  }
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0xd8));
  if (DAT_00b19ac8 != 0) {
    iVar3 = FUN_0072be90((byte *)(in_ECX + 0xdc),1,0);
    if (iVar3 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + *(byte *)(in_ECX + 0xdc) + 1;
  }
  param_1 = 0;
  for (puVar1 = *(undefined4 **)(in_ECX + 0x98); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    param_1 = param_1 + 1;
  }
  if (DAT_00b19ac8 != 0) {
    iVar3 = FUN_0072be90(&param_1,4,0);
    if (iVar3 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar2 + 0x214) = *(int *)(iVar2 + 0x214) + (param_1 & 0xff) + 4;
  }
  for (puVar1 = *(undefined4 **)(in_ECX + 0x98); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    FUN_0066ee00(puVar1[1]);
    FUN_0066ee00(puVar1[1] + 4);
  }
  return 1;
}



// ?Load@Living@@UAEIAAVGameOSFile@@@Z @ 0x005ad230

undefined4 _Load_Living__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  byte *pbVar2;
  int in_ECX;
  uint uVar3;
  uint in_stack_00005d15;
  uint in_stack_00011737;
  
  iVar1 = _Load_MobileWallHug__UAEIAAVGameOSFile___Z();
  if (iVar1 == 0) {
    return 0;
  }
  FUN_00531f30();
  FUN_00531f30();
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x8c) + 6;
  }
  FUN_00531f30();
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
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xa8) + 1;
  }
  FUN_00531f30();
  FUN_00531f30();
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xb4) + 2;
  }
  FUN_00531f30();
  FUN_00531f30();
  FUN_00531f30();
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xc4) + 4;
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
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xd4) + 1;
  }
  FUN_00531f30();
  if (DAT_00b19acc != 0) {
    iVar1 = FUN_0072be50();
    if (iVar1 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xdc) + 1;
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (in_stack_00011737 & 0xff) + 4;
    }
  }
  uVar3 = 0;
  if (in_stack_00005d15 != 0) {
    do {
      pbVar2 = (byte *)FUN_00746d70();
      if (DAT_00b19acc != 0) {
        iVar1 = FUN_0072be50();
        if (iVar1 == 3) {
          DAT_00b19acc = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *pbVar2 + 4;
      }
      if (DAT_00b19acc != 0) {
        iVar1 = FUN_0072be50();
        if (iVar1 == 3) {
          DAT_00b19acc = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + pbVar2[4] + 4;
      }
      FUN_005adfe0();
      uVar3 = uVar3 + 1;
    } while (uVar3 < in_stack_00005d15);
  }
  return 1;
}



// ?GetFinalState@Living@@UBE?AW4VILLAGER_STATES@@XZ @ 0x005ae110

void _GetFinalState_Living__UBE_AW4VILLAGER_STATES__XZ(void)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xd8) != 0) {
    piVar1 = (int *)(*(int *)(*(int *)(in_ECX + 0xd8) + 0x18) + 0x90);
    *piVar1 = *piVar1 + -1;
    if (*(int *)(*(int *)(in_ECX + 0xd8) + 0xe8) != 0) {
      piVar1 = (int *)(*(int *)(in_ECX + 0xd8) + 0x78);
      *piVar1 = *piVar1 + -1;
    }
    iVar2 = *(int *)(in_ECX + 0xd8);
    piVar1 = *(int **)(iVar2 + 0x1c);
    piVar4 = (int *)0x0;
    while (piVar3 = piVar4, piVar4 = piVar1, piVar4 != (int *)0x0) {
      piVar1 = (int *)*piVar4;
      if (piVar4[1] == in_ECX) {
        if (piVar4 == *(int **)(iVar2 + 0x1c)) {
          *(int **)(iVar2 + 0x1c) = piVar1;
        }
        else {
          *piVar3 = (int)piVar1;
        }
        *(int *)(iVar2 + 0x20) = *(int *)(iVar2 + 0x20) + -1;
        FUN_007290de(piVar4);
        piVar4 = piVar3;
      }
    }
    FUN_004eb6a0();
    *(undefined4 *)(in_ECX + 0xd8) = 0;
  }
  return;
}



// ?InitialisePhysicsFromHand@Living@@UAEIAAULHPoint@@0PAVGInterfaceStatus@@PAVObject@@H@Z @ 0x005ae530

int _InitialisePhysicsFromHand_Living__UAEIAAULHPoint__0PAVGInterfaceStatus__PAVObject__H_Z
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  
  iVar2 = (**(code **)(*in_ECX + 0x974))();
  if (iVar2 != 0) {
    (**(code **)(*in_ECX + 0xb04))(1);
  }
  cVar1 = FUN_005b0da0();
  if (cVar1 != '\x18') {
    (**(code **)(*in_ECX + 0x8e8))();
  }
  iVar2 = _InitialisePhysicsFromHand_Object__UAEIPAULHPoint__0PAVGInterfaceStatus__PAV1_H_Z
                    (param_1,param_2,param_3,param_4,param_5);
  if (iVar2 == 0) {
    (**(code **)(*in_ECX + 0x790))(0,1);
  }
  else if (((*(byte *)(iVar2 + 0x1d8) & 8) == 0) && (*(int **)(iVar2 + 0x18) == in_ECX)) {
    (**(code **)(*in_ECX + 0x8e4))(10);
    return iVar2;
  }
  return iVar2;
}



// ?InitialisePhysics@Living@@UAEIABULHPoint@@0PAVObject@@_NPAVGInterfaceStatus@@@Z @ 0x005ae5c0

undefined4 *
_InitialisePhysics_Living__UAEIABULHPoint__0PAVObject___NPAVGInterfaceStatus___Z
          (undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  
  cVar1 = FUN_005b0da0();
  if (cVar1 != '\n') {
    cVar1 = FUN_005b0da0();
    if (cVar1 != '\x18') {
      (**(code **)(*in_ECX + 0x8e8))();
    }
    iVar2 = (**(code **)(*in_ECX + 0x8e4))(10);
    if (iVar2 != 1) {
      *param_1 = 0;
      param_1[1] = 0;
      return param_1;
    }
  }
  _InitialisePhysics_Object__UAEIPBULHPoint__0PAV1__NPAVGInterfaceStatus___Z
            (param_1,param_2,param_3,param_4,param_5,param_6);
  return param_1;
}



// ?UpdateHowImpressed@Living@@UAEXPAVReaction@@H@Z @ 0x005af650

void _UpdateHowImpressed_Living__UAEXPAVReaction__H_Z(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int *in_ECX;
  int unaff_retaddr;
  
  if (in_ECX[0x25] == 0) {
    (**(code **)(*in_ECX + 0x8e8))();
  }
  (**(code **)(*in_ECX + 0x8e4))(param_2);
  iVar2 = (**(code **)(*in_ECX + 0x974))();
  if (iVar2 != 0) {
    (**(code **)(*in_ECX + 0xb04))(1);
  }
  in_ECX[0x25] = unaff_retaddr;
  puVar3 = operator_new(8);
  if (puVar3 != (undefined4 *)0x0) {
    uVar1 = *(undefined4 *)(unaff_retaddr + 0x18);
    *puVar3 = in_ECX;
    puVar3[1] = uVar1;
    *(undefined4 **)(unaff_retaddr + 0x18) = puVar3;
    *(int *)(unaff_retaddr + 0x1c) = *(int *)(unaff_retaddr + 0x1c) + 1;
    return;
  }
  *(undefined4 *)(unaff_retaddr + 0x18) = 0;
  *(int *)(unaff_retaddr + 0x1c) = *(int *)(unaff_retaddr + 0x1c) + 1;
  return;
}



// ?StartReacting@Living@@UAEXW4REACTION@@PAVGameThingWithPos@@PAVReaction@@@Z @ 0x005af860

void _StartReacting_Living__UAEXW4REACTION__PAVGameThingWithPos__PAVReaction___Z(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x94);
  if (iVar1 == 0) {
    *(undefined4 *)(in_ECX + 0xbc) = 0;
    return;
  }
  piVar4 = *(int **)(iVar1 + 0x18);
  piVar3 = (int *)0x0;
  do {
    piVar2 = piVar4;
    if (piVar2 == (int *)0x0) {
LAB_005af8aa:
      FUN_005af700(*(undefined4 *)(*(int *)(in_ECX + 0x94) + 0x24));
      *(undefined4 *)(in_ECX + 0x94) = 0;
      *(undefined4 *)(in_ECX + 0xbc) = 0;
      return;
    }
    if (*piVar2 == in_ECX) {
      if (piVar3 == (int *)0x0) {
        *(int *)(iVar1 + 0x18) = (*(int **)(iVar1 + 0x18))[1];
      }
      else {
        piVar3[1] = piVar2[1];
      }
      FUN_007290de(piVar2);
      *(int *)(iVar1 + 0x1c) = *(int *)(iVar1 + 0x1c) + -1;
      goto LAB_005af8aa;
    }
    piVar4 = (int *)piVar2[1];
    piVar3 = piVar2;
  } while( true );
}



// ?StopReacting@Living@@UAEXXZ @ 0x005af8e0

void _StopReacting_Living__UAEXXZ(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x99c))();
  if (in_ECX[0x25] != 0) {
    (**(code **)(*in_ECX + 0x994))();
  }
  return;
}



// ?IsInterestedInWoodObject@Living@@UAE_NPAVObject@@@Z @ 0x005af910

undefined4 _IsInterestedInWoodObject_Living__UAE_NPAVObject___Z(void)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  
  cVar1 = (**(code **)(*in_ECX + 0xb00))();
  iVar2 = (**(code **)(*in_ECX + 0xd4))();
  if ((iVar2 != 0) && ((~*(ushort *)(in_ECX + 9) & 0x400) != 0)) {
    iVar2 = FUN_005ab680();
    if (((iVar2 == 0) &&
        ((((cVar1 != '\x0f' && (cVar1 != '\x10')) && (cVar1 != '\x11')) &&
         ((cVar1 != '\x12' && (cVar1 != '\x0e')))))) &&
       ((cVar1 != '\x17' &&
        (((cVar1 != '\x05' && ((*(byte *)(in_ECX + 0x2d) & 1) != 1)) &&
         ((*(byte *)(in_ECX + 9) & 0x80) == 0)))))) {
      return 1;
    }
  }
  return 0;
}



// ?SetupLookAtObject@Living@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x005afa80

void _SetupLookAtObject_Living__UAEXPAVGameThingWithPos__PAVReaction___Z
               (undefined4 param_1,undefined4 param_2)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x9a4))(param_1,param_2);
  return;
}



// ?SetupLookAtNiceSpell@Living@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x005afaa0

void _SetupLookAtNiceSpell_Living__UAEXPAVGameThingWithPos__PAVReaction___Z
               (undefined4 param_1,undefined4 param_2)

{
  int *in_ECX;
  int unaff_ESI;
  
  (**(code **)(*in_ECX + 0x98c))(param_2,8);
  in_ECX[0x2f] = unaff_ESI;
  return;
}



// ?SetupFollowObject@Living@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x005afad0

void _SetupFollowObject_Living__UAEXPAVGameThingWithPos__PAVReaction___Z
               (undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  
  piVar1 = (int *)FUN_007344da(param_1,0,&GameThingWithPos::RTTI_Type_Descriptor,
                               &Object::RTTI_Type_Descriptor,0);
  iVar2 = (**(code **)(*piVar1 + 0x7ec))();
  if (iVar2 != 0) {
    (**(code **)(*in_ECX + 0x98c))(param_2,6);
    in_ECX[0x2f] = (int)piVar1;
    return;
  }
  (**(code **)(*in_ECX + 0x98c))(param_2,7);
  in_ECX[0x2f] = (int)piVar1;
  return;
}



// ?SetupReactToCreature@Living@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x005afb40

void _SetupReactToCreature_Living__UAEXPAVGameThingWithPos__PAVReaction___Z
               (undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = FUN_007344da(param_1,0,&GameThingWithPos::RTTI_Type_Descriptor,
                       &Object::RTTI_Type_Descriptor,0);
  (**(code **)(*in_ECX + 0x98c))(param_2,0x13);
  in_ECX[0x2f] = iVar1;
  return;
}



// ?SetupFleeFromObject@Living@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x005afb80

void _SetupFleeFromObject_Living__UAEXPAVGameThingWithPos__PAVReaction___Z
               (undefined4 param_1,undefined4 param_2)

{
  int *in_ECX;
  int unaff_ESI;
  
  (**(code **)(*in_ECX + 0x98c))(param_2,7);
  in_ECX[0x2f] = unaff_ESI;
  return;
}



// ?SetupReactToMagicTree@Living@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x005afbb0

void _SetupReactToMagicTree_Living__UAEXPAVGameThingWithPos__PAVReaction___Z
               (undefined4 param_1,undefined4 param_2)

{
  int *in_ECX;
  int unaff_ESI;
  
  (**(code **)(*in_ECX + 0x98c))(param_2,0xc);
  in_ECX[0x2f] = unaff_ESI;
  return;
}



// ?SetupReactToFire@Living@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x005afbe0

void _SetupReactToFire_Living__UAEXPAVGameThingWithPos__PAVReaction___Z
               (undefined4 param_1,undefined4 param_2)

{
  int *in_ECX;
  int unaff_ESI;
  
  (**(code **)(*in_ECX + 0x98c))(param_2,0x19);
  in_ECX[0x2f] = unaff_ESI;
  return;
}



// ?SetupReactToMagicShield@Living@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x005afc10

void _SetupReactToMagicShield_Living__UAEXPAVGameThingWithPos__PAVReaction___Z
               (undefined4 param_1,undefined4 param_2)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x9b8))(param_1,param_2);
  return;
}



// ?SetupReactToMagicShieldDestroyed@Living@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x005afc30

undefined1 _SetupReactToMagicShieldDestroyed_Living__UAEXPAVGameThingWithPos__PAVReaction___Z(void)

{
  return (undefined1)DAT_00c70460;
}



// ?ReactToTownCelebrationPriority@Living@@UAEEPAVReaction@@0@Z @ 0x005afc40

undefined1 _ReactToTownCelebrationPriority_Living__UAEEPAVReaction__0_Z(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x14);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x454))();
    if ((iVar2 != 0) && ((int)(uint)*(ushort *)((int)piVar1 + 0x5a) <= *(int *)(piVar1[10] + 0x10c))
       ) {
      return 0;
    }
  }
  return (undefined1)DAT_00c70f50;
}



// ?FleeFromObjectPriority@Living@@UAEEPAVReaction@@0@Z @ 0x005afc80

undefined1 _FleeFromObjectPriority_Living__UAEEPAVReaction__0_Z(void)

{
  return DAT_00c704c4;
}



// ?LookAtObjectPriority@Living@@UAEEPAVReaction@@0@Z @ 0x005afc90

undefined1 _LookAtObjectPriority_Living__UAEEPAVReaction__0_Z(void)

{
  return DAT_00c70528;
}



// ?FollowObjectPriority@Living@@UAEEPAVReaction@@0@Z @ 0x005afca0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint _FollowObjectPriority_Living__UAEEPAVReaction__0_Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_006de110(in_ECX + 0x14,*(int *)(param_1 + 0x14) + 0x14);
  if (iVar1 < 600000) {
    return ((600000 - iVar1) * 100) / 600000 + _DAT_00c7058c;
  }
  return _DAT_00c7058c & 0xff;
}



// ?FleeFromSpellPriority@Living@@UAEEPAVReaction@@0@Z @ 0x005afd00

undefined1 _FleeFromSpellPriority_Living__UAEEPAVReaction__0_Z(void)

{
  return DAT_00c705f0;
}



// ?LookAtSpellPriority@Living@@UAEEPAVReaction@@0@Z @ 0x005afd10

undefined1 _LookAtSpellPriority_Living__UAEEPAVReaction__0_Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_007344da(*(undefined4 *)(param_1 + 0x14),0,&GameThingWithPos::RTTI_Type_Descriptor,
                       &Spell::RTTI_Type_Descriptor,0);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0xa0) == in_ECX)) {
    return 0;
  }
  return DAT_00c70c94;
}



// ?LookAtNiceSpellPriority@Living@@UAEEPAVReaction@@0@Z @ 0x005afd50

undefined1 _LookAtNiceSpellPriority_Living__UAEEPAVReaction__0_Z(void)

{
  return DAT_00c70654;
}



// ?FollowSpellPriority@Living@@UAEEPAVReaction@@0@Z @ 0x005afd60

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint _FollowSpellPriority_Living__UAEEPAVReaction__0_Z(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x974))();
  return CONCAT31((int3)((uint)-iVar1 >> 8),~-(iVar1 != 0)) & _DAT_00c706b8;
}



// ?ReactToCreaturePriority@Living@@UAEEPAVReaction@@0@Z @ 0x005afd80

uint _ReactToCreaturePriority_Living__UAEEPAVReaction__0_Z(int param_1)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int *in_ECX;
  float10 fVar6;
  
  piVar3 = (int *)FUN_007344da(*(undefined4 *)(param_1 + 0x14),0,
                               &GameThingWithPos::RTTI_Type_Descriptor,&Object::RTTI_Type_Descriptor
                               ,0);
  uVar4 = CONCAT31((int3)((uint)piVar3 >> 8),*(byte *)(piVar3 + 9));
  if ((*(byte *)(piVar3 + 9) & 0x44) == 0) {
    iVar5 = (**(code **)(*piVar3 + 0x98))(0);
    uVar4 = 0;
    if (iVar5 != 0) {
      fVar6 = (float10)FUN_006de0a0(in_ECX + 5,piVar3 + 5);
      fVar1 = (float)fVar6;
      iVar5 = FUN_0067f950();
      fVar2 = *(float *)(iVar5 + 0x44);
      uVar4 = CONCAT22((short)((uint)iVar5 >> 0x10),
                       (ushort)(fVar1 < fVar2) << 8 | (ushort)(NAN(fVar1) || NAN(fVar2)) << 10 |
                       (ushort)(fVar1 == fVar2) << 0xe);
      if (fVar1 < fVar2 || (fVar1 == fVar2) != 0) {
        iVar5 = (**(code **)(*in_ECX + 0x978))(piVar3);
        return CONCAT31((int3)((uint)-iVar5 >> 8),-(iVar5 != 0)) & DAT_00c7071c;
      }
    }
  }
  return uVar4 & 0xffffff00;
}



// ?ReactToFoodPriority@Living@@UAEEPAVReaction@@0@Z @ 0x005afe10

uint _ReactToFoodPriority_Living__UAEEPAVReaction__0_Z(int param_1)

{
  uint uVar1;
  int iVar2;
  int *in_ECX;
  
  uVar1 = FUN_007344da(*(undefined4 *)(param_1 + 0x14),0,&GameThingWithPos::RTTI_Type_Descriptor,
                       &Object::RTTI_Type_Descriptor,0);
  if ((*(byte *)(uVar1 + 0x24) & 4) != 0) {
    return uVar1 & 0xffffff00;
  }
  iVar2 = (**(code **)(*in_ECX + 0x97c))(uVar1);
  return CONCAT31((int3)((uint)-(iVar2 + -1) >> 8),~-(iVar2 + -1 != 0)) & DAT_00c70910;
}



// ?ReactToWoodPriority@Living@@UAEEPAVReaction@@0@Z @ 0x005afe60

undefined1 _ReactToWoodPriority_Living__UAEEPAVReaction__0_Z(void)

{
  return DAT_00c70780;
}



// ?ReactToMagicTreePriority@Living@@UAEEPAVReaction@@0@Z @ 0x005afe70

undefined1 _ReactToMagicTreePriority_Living__UAEEPAVReaction__0_Z(void)

{
  int in_ECX;
  
  if ((*(char *)(in_ECX + 0x8c) != '\n') && (*(char *)(in_ECX + 0x8c) != '\v')) {
    return DAT_00c707e4;
  }
  return 0;
}



// ?ReactToFlyingObjectPriority@Living@@UAEEPAVReaction@@0@Z @ 0x005afe90

uint _ReactToFlyingObjectPriority_Living__UAEEPAVReaction__0_Z(int param_1)

{
  int iVar1;
  
  FUN_007344da(*(undefined4 *)(param_1 + 0x14),0,&GameThingWithPos::RTTI_Type_Descriptor,
               &Ball::RTTI_Type_Descriptor,0);
  iVar1 = FUN_0042faf0();
  return CONCAT31((int3)((uint)-(iVar1 + -1) >> 8),~-(iVar1 + -1 != 0)) & DAT_00c708ac;
}



// ?ReactToFirePriority@Living@@UAEEPAVReaction@@0@Z @ 0x005afed0

undefined1 _ReactToFirePriority_Living__UAEEPAVReaction__0_Z(void)

{
  return DAT_00c70974;
}



// ?ReactToMagicShieldPriority@Living@@UAEEPAVReaction@@0@Z @ 0x005afee0

undefined1 _ReactToMagicShieldPriority_Living__UAEEPAVReaction__0_Z(void)

{
  return DAT_00c709d8;
}



// ?ReactToCreatureGiftPriority@Living@@UAEEPAVReaction@@0@Z @ 0x005afef0

uint _ReactToCreatureGiftPriority_Living__UAEEPAVReaction__0_Z(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x974))();
  return CONCAT31((int3)((uint)-iVar1 >> 8),~-(iVar1 != 0)) & DAT_00c70a3c;
}



// ?ReactToDroppedByHandPriority@Living@@UAEEPAVReaction@@0@Z @ 0x005aff10

undefined1 _ReactToDroppedByHandPriority_Living__UAEEPAVReaction__0_Z(void)

{
  return DAT_00c70e24;
}



// ?ReactToFaintingPriority@Living@@UAEEPAVReaction@@0@Z @ 0x005aff20

undefined1 _ReactToFaintingPriority_Living__UAEEPAVReaction__0_Z(void)

{
  return DAT_00c70e88;
}



// ?ReactToScaffoldPriority@Living@@UAEEPAVReaction@@0@Z @ 0x005aff30

void _ReactToScaffoldPriority_Living__UAEEPAVReaction__0_Z(undefined4 param_1,int param_2)

{
  __ftol(*(undefined4 *)(&DAT_00c70464 + param_2 * 100),0);
  return;
}



// ?StandardNumGameTurnsToReactFunction@Living@@UAEIPAVGameThingWithPos@@IM@Z @ 0x005aff90

void _StandardNumGameTurnsToReactFunction_Living__UAEIPAVGameThingWithPos__IM_Z
               (undefined4 param_1,int param_2)

{
  __ftol(*(undefined4 *)(&DAT_00c70468 + param_2 * 100),0);
  return;
}



// ?NumGameTurnsBeforeReactingAgainToCreatureFunction@Living@@UAEIPAVGameThingWithPos@@IM@Z @ 0x005afff0

undefined4
_NumGameTurnsBeforeReactingAgainToCreatureFunction_Living__UAEIPAVGameThingWithPos__IM_Z
          (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  float10 fVar4;
  
  piVar1 = (int *)FUN_007344da(param_1,0,&GameThingWithPos::RTTI_Type_Descriptor,
                               &Animal::RTTI_Type_Descriptor,0);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  if ((char)in_ECX[0x23] == '\a') {
    fVar4 = (float10)(**(code **)(*piVar1 + 0x154))();
    if ((float10)5.0 < fVar4) {
      iVar2 = FUN_005b0480(piVar1);
      if (iVar2 != 0) {
        return 0;
      }
    }
  }
  uVar3 = (**(code **)(*in_ECX + 0xabc))(param_1,param_2,param_3);
  return uVar3;
}



// ?NumGameTurnsToReactToPredatorFunction@Living@@UAEIPAVGameThingWithPos@@IM@Z @ 0x005b0070

undefined4
_NumGameTurnsToReactToPredatorFunction_Living__UAEIPAVGameThingWithPos__IM_Z
          (undefined4 param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int *in_ECX;
  float10 fVar3;
  
  piVar1 = (int *)FUN_007344da(param_1,0,&GameThingWithPos::RTTI_Type_Descriptor,
                               &Animal::RTTI_Type_Descriptor,0);
  if (piVar1 != (int *)0x0) {
    fVar3 = (float10)(**(code **)(*piVar1 + 0x154))();
    if (fVar3 <= (float10)5.0) {
      fVar3 = (float10)FUN_006de0a0(in_ECX + 5,piVar1 + 5);
      if ((float10)*(float *)(&DAT_00c70490 + param_2 * 100) <= fVar3) {
        uVar2 = (**(code **)(*in_ECX + 0xac0))(param_1,param_2,param_3);
        return uVar2;
      }
    }
  }
  return 0;
}



// ?NumGameTurnsBeforeReactingAgainToPredatorFunction@Living@@UAEIPAVGameThingWithPos@@IM@Z @ 0x005b0100

void _NumGameTurnsBeforeReactingAgainToPredatorFunction_Living__UAEIPAVGameThingWithPos__IM_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0xac0))(param_1,param_2,param_3);
  return;
}



// ?StandardNumGameTurnsBeforeReactingAgainFunction@Living@@UAEIPAVGameThingWithPos@@IM@Z @ 0x005b0120

void _StandardNumGameTurnsBeforeReactingAgainFunction_Living__UAEIPAVGameThingWithPos__IM_Z
               (undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  
  piVar1 = (int *)FUN_007344da(param_1,0,&GameThingWithPos::RTTI_Type_Descriptor,
                               &Creature::RTTI_Type_Descriptor,0);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x1a8))();
    iVar2 = (**(code **)(*in_ECX + 0x48))();
    if (iVar2 != 0) {
      (**(code **)(*in_ECX + 0x48))(piVar1);
      FUN_006d58d0(piVar1);
    }
    __ftol();
    return;
  }
  return;
}



// ?NumGameTurnsToReactToCreatureFunction@Living@@UAEIPAVGameThingWithPos@@IM@Z @ 0x005b0210

undefined4
_NumGameTurnsToReactToCreatureFunction_Living__UAEIPAVGameThingWithPos__IM_Z(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  piVar1 = (int *)FUN_007344da(param_1,0,&GameThingWithPos::RTTI_Type_Descriptor,
                               &Creature::RTTI_Type_Descriptor,0);
  (**(code **)(*piVar1 + 0x1a8))();
  if ((*(int *)(piVar1[0x59] + 0xf60) < 0x148) &&
     (*(int *)(&DAT_00b8dd2c + *(int *)(piVar1[0x59] + 0xf60) * 0x10c) != 0x18)) {
    return 0;
  }
  iVar2 = (**(code **)(*in_ECX + 0x48))();
  if (iVar2 != 0) {
    (**(code **)(*in_ECX + 0x48))(piVar1);
    iVar2 = FUN_006d58d0(piVar1);
    if ((2 < iVar2) && (iVar2 < 5)) {
      return 0;
    }
  }
  uVar3 = __ftol();
  return uVar3;
}



// ?GetFleeingPositionFromMovingObject@Living@@UAEXPAUMapCoords@@PAVGameThingWithPos@@M@Z @ 0x005b0630

void _GetFleeingPositionFromMovingObject_Living__UAEXPAUMapCoords__PAVGameThingWithPos__M_Z
               (undefined4 *param_1,int param_2,float param_3)

{
  float fVar1;
  float fVar2;
  int in_ECX;
  float10 fVar3;
  float fStack_3c;
  float fStack_38;
  float fStack_34;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  float fStack_4;
  
  fVar1 = *(float *)(param_2 + 0x1c);
  fVar3 = (float10)FUN_00760fd0();
  fVar2 = *(float *)(in_ECX + 0x1c);
  fStack_2c = (float)(fVar3 + (float10)fVar1);
  fStack_30 = (float)*(int *)(param_2 + 0x14) * 0.00015258789;
  fStack_28 = (float)*(int *)(param_2 + 0x18) * 0.00015258789;
  fVar3 = (float10)FUN_00760fd0();
  fVar3 = fVar3 + (float10)fVar2;
  fVar1 = (float)*(int *)(in_ECX + 0x14) * 0.00015258789;
  fStack_4 = (float)*(int *)(in_ECX + 0x18) * 0.00015258789;
  fStack_24 = fVar1 - fStack_30;
  fStack_20 = (float)(fVar3 - (float10)fStack_2c);
  fStack_1c = fStack_4 - fStack_28;
  if ((fStack_24 != 0.0) || (fStack_3c = fStack_24, fStack_34 = fStack_1c, fStack_1c != 0.0)) {
    fStack_34 = param_3 / SQRT(fStack_24 * fStack_24 + fStack_1c * fStack_1c);
    fStack_3c = fStack_24 * fStack_34;
    fStack_34 = fStack_1c * fStack_34;
  }
  fStack_3c = fStack_3c + fVar1;
  fStack_38 = (float)(fVar3 + (float10)0.0);
  fStack_34 = fStack_34 + fStack_4;
  FUN_005bf830(&fStack_3c);
  *param_1 = uStack_18;
  param_1[1] = uStack_14;
  param_1[2] = uStack_10;
  return;
}



// ?IsChild@Living@@UAE_NXZ @ 0x005b0780

void _IsChild_Living__UAE_NXZ(undefined4 param_1,int *param_2)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  int *unaff_retaddr;
  float fVar3;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_14;
  float fStack_10;
  
  (**(code **)(*param_2 + 0x168))(&fStack_24);
  if (0.0 < SQRT(fStack_20 * fStack_20 + fStack_24 * fStack_24 + fStack_28 * fStack_28)) {
    *unaff_retaddr = in_ECX[5];
    unaff_retaddr[1] = in_ECX[6];
    unaff_retaddr[2] = in_ECX[7];
    fStack_2c = fStack_28;
    fStack_1c = (float)in_ECX[5] * 10.0 * 1.5258789e-05 - (float)param_2[5] * 10.0 * 1.5258789e-05;
    fStack_14 = (float)in_ECX[6] * 10.0 * 1.5258789e-05 - (float)param_2[6] * 10.0 * 1.5258789e-05;
    fVar3 = -fStack_20;
    if (((fVar3 != 0.0) || (fStack_30 != 0.0)) || (fStack_28 != 0.0)) {
      fStack_2c = 1.0 / SQRT(fVar3 * fVar3 + fStack_30 * fStack_30 + fStack_28 * fStack_28);
      fVar3 = fStack_2c * fVar3;
      fStack_2c = fStack_2c * fStack_28;
    }
    fVar2 = (float10)FUN_0067bcb0(0x41000000,s_C__dev_black_LivingReaction_cpp_00b207c8,0x2f1);
    fStack_10 = (float)(((float10)fVar3 * (float10)(float)param_2 + fVar2) - (float10)4.0);
    FUN_0067bcb0(0x41000000,s_C__dev_black_LivingReaction_cpp_00b207c8,0x2f2);
    if (fVar3 * fStack_1c + fStack_2c * fStack_14 < 0.0) {
      iVar1 = __ftol();
      *unaff_retaddr = iVar1;
    }
    else {
      iVar1 = __ftol();
      *unaff_retaddr = iVar1;
    }
    iVar1 = __ftol();
    unaff_retaddr[1] = iVar1;
    return;
  }
  (**(code **)(*in_ECX + 0xafc))(unaff_retaddr,param_2,param_2);
  return;
}



// ?AmILikelyToMove@Living@@UAE_NXZ @ 0x005b0d10

bool _AmILikelyToMove_Living__UAE_NXZ(void)

{
  int in_ECX;
  
  return *(char *)(in_ECX + 0x8c) == '\x01';
}



// ?LookAtFlyingObjectReaction@Living@@UAE_NXZ @ 0x005b0f30

undefined4 _LookAtFlyingObjectReaction_Living__UAE_NXZ(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  undefined4 unaff_EBX;
  
  iVar1 = (**(code **)(*in_ECX + 0x900))(param_2);
  if (iVar1 == 0) {
    return 0x2e;
  }
  iVar1 = (**(code **)(*in_ECX + 0x8e0))(param_2);
  iVar2 = (**(code **)(*in_ECX + 0x904))(unaff_EBX,param_2);
  if (iVar2 != 0) {
    (**(code **)(*in_ECX + 0x8ec))();
    if (iVar1 != -1) {
      (**(code **)(*in_ECX + 0x8f4))(iVar1,1);
      return 1;
    }
    FUN_005ab570();
    iVar1 = (**(code **)(*in_ECX + 0x8dc))(param_2);
    if (iVar1 != -1) {
      (**(code **)(*in_ECX + 0x8f4))(iVar1,1);
    }
    return 1;
  }
  return 0x2f;
}



// ?ExitBeingEaten@Living@@UAEHE@Z @ 0x005b0fe0

void _ExitBeingEaten_Living__UAEHE_Z(undefined4 param_1,undefined4 param_2)

{
  FUN_005ab6f0(param_1,param_2);
  return;
}



// ?GetBoundingSphere@Living@@UAEXAAULHPoint@@AAM@Z @ 0x005c3cb0

void _GetBoundingSphere_Living__UAEXAAULHPoint__AAM_Z(float *param_1,float *param_2)

{
  float fVar1;
  float fVar2;
  int *in_ECX;
  float10 fVar3;
  
  fVar3 = (float10)(**(code **)(*in_ECX + 0x42c))();
  fVar1 = (float)(fVar3 * (float10)0.5);
  fVar3 = (float10)(**(code **)(*in_ECX + 100))();
  *param_2 = (float)SQRT((float10)fVar1 * (float10)fVar1 +
                         fVar3 * (float10)0.5 * fVar3 * (float10)0.5);
  fVar2 = (float)in_ECX[7];
  fVar3 = (float10)FUN_00760fd0();
  param_1[1] = (float)(fVar3 + (float10)fVar2);
  *param_1 = (float)in_ECX[5] * 0.00015258789;
  param_1[2] = (float)in_ECX[6] * 0.00015258789;
  param_1[1] = (float)(fVar3 + (float10)fVar2 + (float10)fVar1);
  return;
}



// ?IsDeathState@Living@@UBE_NW4VILLAGER_STATES@@@Z @ 0x00644cf0

void _IsDeathState_Living__UBE_NW4VILLAGER_STATES___Z(void)

{
  return;
}



// ?CanBeHealedByHealSpell@Living@@UAE_NXZ @ 0x0067b940

bool _CanBeHealedByHealSpell_Living__UAE_NXZ(int param_1,int param_2)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x148) != param_1) {
    return false;
  }
  iVar1 = *(int *)(in_ECX + 0x14c);
  if ((iVar1 == 1) || (iVar1 == 6)) {
    if (iVar1 - param_2 == *(int *)(in_ECX + 0x150) * 4 + -2) {
      iVar1 = FUN_0067ac90(param_1,param_2 + -1 + *(int *)(in_ECX + 0x150) * 2);
      if (iVar1 == 0) {
        return true;
      }
    }
  }
  return *(int *)(in_ECX + 0x14c) - param_2 == *(int *)(in_ECX + 0x150) * 2 + -1;
}



// ?AddReaction@Living@@UAEXPAVReaction@@W4VILLAGER_STATES@@@Z @ 0x0067f7e0

void _AddReaction_Living__UAEXPAVReaction__W4VILLAGER_STATES___Z
               (int param_1,undefined4 param_2,undefined4 param_3)

{
  (**(code **)(&DAT_00b2d198 + param_1 * 0xc0))(param_2,param_3);
  return;
}



// ?SetAnim__i@Living@@UAEXH@Z @ 0x006e0380

undefined4 _SetAnim__i_Living__UAEXH_Z(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if ((*(char *)(in_ECX + 0x8c) != -1) && (*(char *)(in_ECX + 0x8c) != '\0')) {
    FUN_006e0410();
    if (*(int *)(&DAT_00c2a328 + (uint)*(byte *)(in_ECX + 0x8c) * 0x90) != 0) {
      uVar1 = (**(code **)(&DAT_00c2a328 + (uint)*(byte *)(in_ECX + 0x8c) * 0x90))();
      return uVar1;
    }
    return *(undefined4 *)(&DAT_00cdab10 + (uint)*(byte *)(in_ECX + 0x8c) * 0x114);
  }
  return 0x181;
}



// ?GetFleeingPositionFromStationaryObject@Living@@UAEXPAUMapCoords@@PAVGameThingWithPos@@M@Z @ 0x006e19c0

byte _GetFleeingPositionFromStationaryObject_Living__UAEXPAUMapCoords__PAVGameThingWithPos__M_Z
               (void)

{
  byte bVar1;
  int in_ECX;
  uint uStack_4;
  
  bVar1 = *(byte *)(in_ECX + 0x8c);
  uStack_4 = (uint)bVar1;
  if (*(int *)(&DAT_00cdab1c + uStack_4 * 0x114) == 0) {
    bVar1 = *(byte *)(in_ECX + 0x8d);
  }
  return bVar1;
}



// ?StopReactingAndSetState@Living@@UAEXXZ @ 0x006e1a00

void _StopReactingAndSetState_Living__UAEXXZ(void)

{
  uint uVar1;
  int *in_ECX;
  
  FUN_006e1a40();
  uVar1 = (**(code **)(*in_ECX + 0xb00))();
  if (*(int *)(&DAT_00cdabc8 + (uVar1 & 0xff) * 0x114) != 0) {
    (**(code **)(*in_ECX + 0x8e4))(0xa3);
  }
  return;
}



// ?LookAtFlyingObjectReaction@Living@@UAE_NXZ @ 0x006e1c60

int _LookAtFlyingObjectReaction_Living__UAE_NXZ(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = _LookAtFlyingObjectReaction_Living__UAE_NXZ(param_1,param_2);
  if (iVar1 == 0x2f) {
    (**(code **)(*in_ECX + 0x908))(0xa3);
  }
  return iVar1;
}



// ?IsStateForInterface@Living@@UBE_NW4VILLAGER_STATES@@@Z @ 0x006e2070

undefined4 _IsStateForInterface_Living__UBE_NW4VILLAGER_STATES___Z(int param_1)

{
  uint uVar1;
  int iVar2;
  int *in_ECX;
  int iVar3;
  
  uVar1 = (**(code **)(*in_ECX + 0xb00))();
  iVar3 = (uVar1 & 0xff) * 0x90;
  iVar2 = param_1 * 0x90;
  if (((*(int *)(&DAT_00c2a2e8 + iVar3) != *(int *)(&DAT_00c2a2e8 + iVar2)) ||
      ((*(int *)(&DAT_00c2a2e8 + iVar3) != 0 &&
       (((*(int *)(&DAT_00c2a2ec + iVar3) != *(int *)(&DAT_00c2a2ec + iVar2) ||
         (*(int *)(&DAT_00c2a2f0 + iVar3) != *(int *)(&DAT_00c2a2f0 + iVar2))) ||
        (*(int *)(&DAT_00c2a2f4 + iVar3) != *(int *)(&DAT_00c2a2f4 + iVar2))))))) &&
     (*(int *)(&DAT_00cdab1c + param_1 * 0x114) != 0)) {
    return 0;
  }
  return 1;
}



// ?GetAge@Living@@UAEIXZ @ 0x006e23c0

void _GetAge_Living__UAEIXZ(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int *in_ECX;
  uint uVar4;
  int iVar5;
  
  if ((DAT_00cc7864 & 1) == 0) {
    DAT_00cc7864 = DAT_00cc7864 | 1;
    iVar2 = 0x1ff;
    if (*DAT_00d76c64 < 0x200) {
      iVar2 = 0;
    }
    DAT_00cc7860 = DAT_00d76c64[iVar2 + 1];
  }
  uVar1 = *(uint *)(in_ECX[10] + 0x138);
  uVar4 = param_1;
  if (param_1 < uVar1) {
LAB_006e2419:
    *(byte *)(in_ECX + 0x38) = *(byte *)(in_ECX + 0x38) | 8;
    uVar3 = (**(code **)(*in_ECX + 0x8cc))();
    if ((uVar3 < uVar1) || (in_ECX[0x10] == 0)) goto LAB_006e2562;
    iVar2 = (**(code **)(*in_ECX + 0x4a0))();
    if (iVar2 == 0) {
      iVar2 = *(int *)(in_ECX[10] + 0x20c);
      if ((iVar2 < 0) || (*DAT_00d76c64 <= iVar2)) {
        iVar2 = 0;
      }
      param_1 = DAT_00d76c64[iVar2 + 1];
      iVar2 = *(int *)(in_ECX[10] + 0x208);
      if ((iVar2 < 0) || (*DAT_00d76c64 <= iVar2)) {
        iVar2 = 0;
      }
      iVar2 = DAT_00d76c64[iVar2 + 1];
      iVar5 = *(int *)in_ECX[0x10];
LAB_006e2557:
      (**(code **)(iVar5 + 0xf4))(iVar2,param_1);
      goto LAB_006e2562;
    }
  }
  else {
    if (param_1 < 0x12) {
      uVar4 = 0x12;
    }
    if (uVar4 < uVar1) goto LAB_006e2419;
    *(ushort *)(in_ECX + 0x38) = *(ushort *)(in_ECX + 0x38) & 0xfff7;
    uVar3 = (**(code **)(*in_ECX + 0x8cc))();
    if ((uVar1 <= uVar3) || (in_ECX[0x10] == 0)) goto LAB_006e2562;
    iVar2 = (**(code **)(*in_ECX + 0x4a0))();
    if (iVar2 == 0) {
      (**(code **)(*in_ECX + 0x60c))(2);
      iVar2 = (**(code **)(*in_ECX + 0x60c))(1);
      if ((iVar2 < 0) || (*DAT_00d76c64 <= iVar2)) {
        iVar2 = 0;
      }
      iVar2 = DAT_00d76c64[iVar2 + 1];
      (**(code **)(*in_ECX + 0x60c))(0);
      iVar5 = *(int *)in_ECX[0x10];
      goto LAB_006e2557;
    }
  }
  (**(code **)(*(int *)in_ECX[0x10] + 0xf4))(DAT_00cc7860,DAT_00cc7860);
LAB_006e2562:
  FUN_006dfea0(uVar4);
  FUN_006e2590(uVar4);
  _GetAge_Living__UAEIXZ(uVar4);
  return;
}



// ?ExitBeingEaten@Living@@UAEHE@Z @ 0x006e3170

void _ExitBeingEaten_Living__UAEHE_Z(int param_1,uint param_2)

{
  int *in_ECX;
  uint uVar1;
  uint uVar2;
  
  if ((param_1 != 2) || (*(int *)(&DAT_00cdab20 + (param_2 & 0xff) * 0x114) == 0)) {
    uVar1 = (uint)*(byte *)(param_1 + 0x8c + (int)in_ECX);
    uVar2 = param_2 & 0xff;
    if ((*(int *)(&DAT_00cdab1c + uVar1 * 0x114) != 0) && (uVar1 != 0)) {
      FUN_006e3040(uVar1,0);
    }
    if ((*(int *)(&DAT_00cdab1c + uVar2 * 0x114) != 0) && (uVar2 != 0)) {
      FUN_006e3040(uVar2,1);
    }
    if (param_1 == 0) {
      (**(code **)(*in_ECX + 0x934))(1,0);
    }
    _ExitBeingEaten_Living__UAEHE_Z(param_1,param_2);
  }
  return;
}



// ?StartReacting@Living@@UAEXW4REACTION@@PAVGameThingWithPos@@PAVReaction@@@Z @ 0x006f1fc0

void _StartReacting_Living__UAEXW4REACTION__PAVGameThingWithPos__PAVReaction___Z(void)

{
  char cVar1;
  int iVar2;
  int *in_ECX;
  
  cVar1 = FUN_005b0da0();
  if (cVar1 == -0x35) {
    iVar2 = (**(code **)(*in_ECX + 0x974))();
    if (iVar2 != 0) {
      (**(code **)(*in_ECX + 0xb04))(1);
    }
  }
  _StartReacting_Living__UAEXW4REACTION__PAVGameThingWithPos__PAVReaction___Z();
  return;
}



// ?SetupFleeFromObject@Living@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x006f2290

void _SetupFleeFromObject_Living__UAEXPAVGameThingWithPos__PAVReaction___Z
               (undefined4 param_1,undefined4 param_2)

{
  _SetupFleeFromObject_Living__UAEXPAVGameThingWithPos__PAVReaction___Z(param_1,param_2);
  return;
}



// ?NumGameTurnsBeforeReactingAgainToCreatureFunction@Living@@UAEIPAVGameThingWithPos@@IM@Z @ 0x006f2870

undefined4
_NumGameTurnsBeforeReactingAgainToCreatureFunction_Living__UAEIPAVGameThingWithPos__IM_Z
          (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  cVar1 = (**(code **)(*in_ECX + 0xb00))();
  if ((cVar1 != -0x14) && (cVar1 != -0x13)) {
    uVar2 = _NumGameTurnsBeforeReactingAgainToCreatureFunction_Living__UAEIPAVGameThingWithPos__IM_Z
                      (param_1,param_2,param_3);
    return uVar2;
  }
  return 0x7fffffff;
}



// ?StandardNumGameTurnsBeforeReactingToWoodAgainFunction@Living@@UAEIPAVGameThingWithPos@@IM@Z @ 0x006f28e0

void _StandardNumGameTurnsBeforeReactingToWoodAgainFunction_Living__UAEIPAVGameThingWithPos__IM_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0xabc))(param_1,param_2,param_3);
  return;
}



// ?IsDancing@Living@@UAE_NXZ @ 0x006f3550

undefined4 _IsDancing_Living__UAE_NXZ(int *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  char cVar4;
  short sVar5;
  int iVar6;
  uint uVar7;
  int *in_ECX;
  float10 fVar8;
  float10 fVar9;
  
  iVar6 = (**(code **)(*param_1 + 0x2c))();
  if (((iVar6 != 0) && (((byte)~(byte)*(ushort *)(param_1 + 9) >> 6 & 1) != 0)) &&
     ((*(ushort *)(param_1 + 9) & 4) == 0)) {
    fVar8 = (float10)FUN_005ab430(param_1,DAT_00c70738);
    uVar7 = (**(code **)(*in_ECX + 0xb00))();
    fVar1 = *(float *)(&DAT_00cdabd8 + (uVar7 & 0xff) * 0x114);
    fVar9 = (float10)FUN_006eab50();
    iVar6 = in_ECX[10];
    sVar5 = FUN_006e11c0();
    fVar3 = (float)(int)sVar5 / (float)*(int *)(iVar6 + 0x264);
    cVar4 = (**(code **)(*param_1 + 0x4a8))();
    if (cVar4 == '\0') {
      fVar2 = 1.0;
    }
    else {
      fVar2 = 2.0;
    }
    if (0.25 < fVar2 * fVar3 * (float)fVar9 * fVar1 * (float)fVar8 +
               *(float *)(DAT_00c22ca4 + 0x201b0c)) {
      return 1;
    }
    iVar6 = (**(code **)(*in_ECX + 0x48))();
    if (iVar6 != 0) {
      fVar9 = (float10)FUN_006d1080(0);
      fVar2 = *(float *)(DAT_00c22ca4 + 0x201b0c);
      iVar6 = FUN_006d7d10(0);
      if (*(float *)(iVar6 + 0x18) <
          (float)((float10)fVar2 + fVar9 * (float10)fVar3 * (float10)fVar1 * (float10)(float)fVar8))
      {
        return 1;
      }
    }
  }
  return 0;
}



// ?ReactToMagicTreePriority@Living@@UAEEPAVReaction@@0@Z @ 0x006f3900

uint _ReactToMagicTreePriority_Living__UAEEPAVReaction__0_Z(int param_1)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined2 extraout_var;
  int *in_ECX;
  float10 fVar5;
  float10 fVar6;
  undefined1 *puVar7;
  undefined1 auStack_18 [12];
  undefined1 auStack_c [12];
  
  iVar2 = (**(code **)(*in_ECX + 0x974))();
  if (iVar2 != 0) {
    iVar2 = FUN_005b0480(*(undefined4 *)(param_1 + 0x14));
    if (iVar2 == 0) {
      return 0;
    }
  }
  if (in_ECX[0x25] != 0) {
    uVar3 = FUN_005ab4c0();
    if (*(int *)(uVar3 + 0x24) == 0xd) {
      piVar1 = (int *)in_ECX[0x2f];
      if (piVar1 == (int *)0x0) {
        return uVar3 & 0xffffff00;
      }
      uVar4 = FUN_0067f810(auStack_18);
      puVar7 = auStack_c;
      FUN_005ab4c0(puVar7,uVar4);
      uVar4 = FUN_0067f810(puVar7);
      fVar5 = (float10)FUN_006de0a0(uVar4);
      fVar6 = (float10)(**(code **)(*piVar1 + 0x60))();
      fVar5 = (float10)(float)fVar5;
      if (fVar6 < fVar5 || (fVar6 == fVar5) != 0) {
        return CONCAT22(extraout_var,
                        (ushort)(fVar6 < fVar5) << 8 | (ushort)(NAN(fVar6) || NAN(fVar5)) << 10 |
                        (ushort)(fVar6 == fVar5) << 0xe);
      }
    }
  }
  uVar3 = _ReactToMagicTreePriority_Living__UAEEPAVReaction__0_Z(param_1,0);
  return uVar3;
}



// ?ReactToBallPriority@Living@@UAEEPAVReaction@@0@Z @ 0x006f3cb0

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined1 _ReactToBallPriority_Living__UAEEPAVReaction__0_Z(int param_1,int param_2)

{
  int iVar1;
  float fVar2;
  char cVar3;
  undefined1 uVar4;
  int iVar5;
  uint uVar6;
  int *in_ECX;
  float10 fVar7;
  float10 fVar8;
  float10 fVar9;
  
  iVar5 = FUN_007344da(*(undefined4 *)(param_1 + 0x14),0,&GameThingWithPos::RTTI_Type_Descriptor,
                       &Object::RTTI_Type_Descriptor,0);
  if (iVar5 == 0) {
    return 0;
  }
  iVar1 = *(int *)(iVar5 + 0x44);
  if (iVar1 == 0) {
    return 0;
  }
  cVar3 = (**(code **)(*in_ECX + 0xb00))();
  if (cVar3 == -0x25) {
    return 0;
  }
  fVar7 = (float10)FUN_006de0a0(in_ECX + 5,iVar5 + 0x14);
  fVar8 = (float10)FUN_006c6200();
  fVar9 = (float10)FUN_006c62f0();
  if ((((float10)(float)fVar8 / fVar9) * (float10)0.5 + (float10)1.0) * (float10)_DAT_00c70848 <
      (float10)255.0) {
    FUN_006c6200();
    FUN_006c62f0();
  }
  uVar4 = __ftol();
  if (((uint)(*(int *)(DAT_00c22ca4 + 0x201afc) - *(int *)(param_1 + 0x2c)) < 0x19) &&
     (iVar5 = FUN_0067f950(), (float)fVar7 < *(float *)(iVar5 + 0x40))) {
    return uVar4;
  }
  fVar8 = (float10)FUN_006c6310();
  if (fVar8 <= (float10)(float)fVar7) {
    uVar6 = (**(code **)(*in_ECX + 0xb00))();
    if ((((param_2 == 0) || (*(int *)(param_2 + 0x24) == 10)) &&
        (((iVar5 = (uVar6 & 0xff) * 0x90, *(code **)(&DAT_00c2a2e8 + iVar5) == FUN_006e9fb0 &&
          (((*(int *)(&DAT_00c2a2ec + iVar5) == 0 && (*(int *)(&DAT_00c2a2f0 + iVar5) == 0)) &&
           (*(int *)(&DAT_00c2a2f4 + iVar5) == 0)))) ||
         (cVar3 = (**(code **)(*in_ECX + 0xb00))(), cVar3 == -0x24)))) &&
       ((in_ECX[0x43] != 0 && (iVar5 = FUN_00667a80(), iVar5 != 0)))) {
      iVar5 = FUN_006c6190(in_ECX[0x43]);
      if (iVar5 != 0) {
        return 0;
      }
      fVar2 = _DAT_00c70864 + 10.0;
      iVar5 = (**(code **)(*(int *)in_ECX[0x43] + 0x2c))();
      if (iVar5 != 0) {
        iVar5 = FUN_00667a80();
        iVar5 = FUN_00667a80(iVar5 + 0x14);
        fVar7 = (float10)FUN_006de0a0(iVar5 + 0x14);
        if (fVar7 <= (float10)fVar2 + (float10)fVar2) {
          FUN_006c5ed0(iVar1);
          return 0;
        }
      }
    }
  }
  return uVar4;
}



// ?SetupReactToFood@Living@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x006f4210

void _SetupReactToFood_Living__UAEXPAVGameThingWithPos__PAVReaction___Z
               (undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = FUN_007344da(param_1,0,&GameThingWithPos::RTTI_Type_Descriptor,
                       &Object::RTTI_Type_Descriptor,0);
  (**(code **)(*in_ECX + 0x98c))(param_2,0x15);
  in_ECX[0x2f] = iVar1;
  return;
}



// ?SetupReactToBall@Living@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x006f4300

void _SetupReactToBall_Living__UAEXPAVGameThingWithPos__PAVReaction___Z
               (undefined4 param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int *in_ECX;
  float10 fVar6;
  float10 fVar7;
  undefined1 *puVar8;
  int *piVar9;
  int *piVar10;
  undefined1 auStack_20 [12];
  undefined1 auStack_14 [16];
  float fStack_4;
  
  piVar3 = (int *)FUN_007344da(param_1,0,&GameThingWithPos::RTTI_Type_Descriptor,
                               &SpellShield::RTTI_Type_Descriptor,0);
  if (piVar3 != (int *)0x0) {
    (**(code **)(*in_ECX + 0x98c))(param_2,0xa8);
    in_ECX[0x2f] = (int)piVar3;
    fVar6 = (float10)(**(code **)(*piVar3 + 0x60))();
    piVar10 = in_ECX + 5;
    iVar4 = FUN_006c25e0(piVar10,(float)(fVar6 * (float10)0.2));
    if (iVar4 == 0) {
      piVar9 = piVar10;
      uVar5 = FUN_0067f810(auStack_20);
      fVar7 = (float10)FUN_006de3e0(uVar5,piVar9);
      fStack_4 = (float)fVar7;
      fVar7 = (float10)FUN_0067bcb0(0x3f490fdb,s_C__dev_black_VillagerReaction_cp_00b47428,0x629);
      fStack_4 = (float)((fVar7 - (float10)0.3926991) + (float10)fStack_4);
      fVar7 = (float10)(**(code **)(*piVar3 + 0x60))();
      fVar1 = (float)(fVar7 - (float10)(float)(fVar6 * (float10)0.2));
      fVar6 = (float10)FUN_0067bcb0(0x3f800000,s_C__dev_black_VillagerReaction_cp_00b47428,0x62b);
      fVar2 = (float)fVar6;
      iVar4 = 2;
      do {
        iVar4 = iVar4 + -1;
        fVar6 = fVar6 * (float10)fVar2;
      } while (iVar4 != 0);
      uVar5 = FUN_006de5a0(auStack_20,fStack_4,(float)((float10)fVar1 - fVar6 * (float10)fVar1));
      puVar8 = &stack0xffffffd4;
      FUN_0067f810(auStack_14);
      FUN_005c1360(puVar8,uVar5);
      FUN_005b0e40(&stack0xffffffd4,0xa8);
    }
    uVar5 = FUN_0067f810(auStack_14);
    fVar6 = (float10)FUN_006de3e0(uVar5,piVar10);
    fStack_4 = (float)fVar6;
    fVar6 = (float10)FUN_0067bcb0(0x3f490fdb,s_C__dev_black_VillagerReaction_cp_00b47428,0x62f);
    fStack_4 = (float)((fVar6 - (float10)0.3926991) + (float10)fStack_4);
    uVar5 = FUN_006de5a0(auStack_14,fStack_4,0x3f800000);
    uVar5 = FUN_005c1360(auStack_20,uVar5);
    FUN_005a15c0(uVar5);
  }
  return;
}



// ?SetupReactToCreatureGift@Living@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x006f46b0

void _SetupReactToCreatureGift_Living__UAEXPAVGameThingWithPos__PAVReaction___Z
               (int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  int iVar3;
  float10 fVar4;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  piVar1 = (int *)FUN_007344da(param_1,0,&GameThingWithPos::RTTI_Type_Descriptor,
                               &Object::RTTI_Type_Descriptor,0);
  fVar4 = (float10)(**(code **)(*piVar1 + 100))();
  iVar3 = *(int *)(param_2 + 0x28);
  if (iVar3 == 0) {
    iVar3 = 4;
    if ((float10)10.0 <= fVar4) {
      iVar3 = 5;
    }
    iVar2 = FUN_004300a0(300,s_C__dev_black_VillagerReaction_cp_00b47428,0x66e);
    if (iVar2 == 0) {
      return;
    }
    iVar3 = FUN_004e9dc0(param_1 + 0x14,&DAT_00be5ee0 + iVar3 * 0x2c,piVar1,
                         *(undefined4 *)(&DAT_00be5ef0 + iVar3 * 0xb0),0,in_ECX[0x49]);
    if (iVar3 == 0) {
      return;
    }
    *(int *)(param_2 + 0x28) = iVar3;
  }
  in_ECX[0x2f] = param_1;
  iVar2 = FUN_0055e370(in_ECX);
  if (iVar2 != 1) {
    (**(code **)(*in_ECX + 0x98c))(param_2,7);
    return;
  }
  uStack_c = 0;
  uStack_8 = 0;
  uStack_4 = 0;
  FUN_005ae1a0(iVar3 + 0x14,&uStack_c);
  FUN_005af7d0(param_2,&uStack_c,0xcb,0);
  return;
}



// ?ReactToHandPuttingStuffInStoragePitPriority@Living@@UAEEPAVReaction@@0@Z @ 0x006f4ae0

undefined1 _ReactToHandPuttingStuffInStoragePitPriority_Living__UAEEPAVReaction__0_Z(int param_1)

{
  int *piVar1;
  int iVar2;
  int *in_ECX;
  
  piVar1 = *(int **)(param_1 + 0x14);
  iVar2 = (**(code **)(*piVar1 + 0x34))();
  if (iVar2 != 0) {
    return DAT_00c70d5c;
  }
  iVar2 = (**(code **)(*in_ECX + 0x48))();
  if (iVar2 != 0) {
    iVar2 = (**(code **)(*in_ECX + 0x48))();
    if ((*(int **)(iVar2 + 0x740) != (int *)0x0) &&
       (iVar2 = (**(code **)(**(int **)(iVar2 + 0x740) + 0xd4))(), iVar2 != 0)) {
      return 0;
    }
  }
  if ((in_ECX != piVar1) && (*(uint *)(param_1 + 0x1c) < 10)) {
    return DAT_00c70d5c;
  }
  return 0;
}



// ?SetupReactToHandPuttingStuffInStoragePit@Living@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x006f4c40

void _SetupReactToHandPuttingStuffInStoragePit_Living__UAEXPAVGameThingWithPos__PAVReaction___Z
               (undefined4 param_1,int param_2)

{
  int iVar1;
  int *in_ECX;
  int unaff_ESI;
  undefined4 uVar2;
  
  if (*(int **)(param_2 + 0x14) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(param_2 + 0x14) + 0x34))();
    if (iVar1 != 0) {
      iVar1 = *in_ECX;
      uVar2 = 7;
      goto LAB_006f4c8a;
    }
  }
  iVar1 = FUN_0067bc90(2,s_C__dev_black_VillagerReaction_cp_00b47428,0x726);
  if (iVar1 == 0) {
    iVar1 = *in_ECX;
    *(undefined2 *)(in_ECX + 0x16) = 0;
    uVar2 = 0xcd;
  }
  else {
    iVar1 = *in_ECX;
    uVar2 = 0xce;
  }
LAB_006f4c8a:
  (**(code **)(iVar1 + 0x98c))(param_2,uVar2);
  in_ECX[0x2f] = unaff_ESI;
  return;
}



// ?ReactToObjectCrushedPriority@Living@@UAEEPAVReaction@@0@Z @ 0x006f5460

uint _ReactToObjectCrushedPriority_Living__UAEEPAVReaction__0_Z(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_007344da(*(undefined4 *)(param_1 + 0x14),0,&GameThingWithPos::RTTI_Type_Descriptor,
                       &GArena::RTTI_Type_Descriptor,0);
  if (iVar1 == 0) {
    return 0;
  }
  return CONCAT31((int3)((uint)iVar1 >> 8),*(int *)(iVar1 + 0x34) == 0) - 1U & DAT_00c70bcc;
}



// ?SetupReactToObjectCrushed@Living@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x006f54a0

void _SetupReactToObjectCrushed_Living__UAEXPAVGameThingWithPos__PAVReaction___Z
               (int param_1,undefined4 param_2)

{
  int *in_ECX;
  
  in_ECX[0x2f] = param_1;
  (**(code **)(*in_ECX + 0x98c))(param_2,0x8f);
  return;
}



// ?SetupFollowObject@Living@@UAEXPAVGameThingWithPos@@PAVReaction@@@Z @ 0x006f5c50

void _SetupFollowObject_Living__UAEXPAVGameThingWithPos__PAVReaction___Z
               (undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  piVar1 = (int *)FUN_007344da(param_1,0,&GameThingWithPos::RTTI_Type_Descriptor,
                               &Creature::RTTI_Type_Descriptor,0);
  iVar2 = (**(code **)(*piVar1 + 0x2c))();
  if (iVar2 != 0) {
    in_ECX[0x2f] = (int)piVar1;
    iVar2 = (**(code **)(*in_ECX + 0x48))();
    if (iVar2 != 0) {
      FUN_006d5900(piVar1);
      uVar3 = FUN_006d58d0(piVar1);
      switch(uVar3) {
      case 0:
      case 2:
      case 4:
        break;
      default:
        goto switchD_006f5ca5_caseD_1;
      case 3:
        (**(code **)(*in_ECX + 0x98c))(param_2,0x9f);
        return;
      }
    }
    (**(code **)(*in_ECX + 0x98c))(param_2,0x92);
  }
switchD_006f5ca5_caseD_1:
  return;
}



// ?FollowSpellPriority@Living@@UAEEPAVReaction@@0@Z @ 0x006f5d00

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint _FollowSpellPriority_Living__UAEEPAVReaction__0_Z(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int *in_ECX;
  float10 fVar7;
  
  iVar1 = (**(code **)(*in_ECX + 0x974))();
  if ((((iVar1 == 0) &&
       (piVar2 = (int *)FUN_007344da(*(undefined4 *)(param_1 + 0x14),0,
                                     &GameThingWithPos::RTTI_Type_Descriptor,
                                     &Creature::RTTI_Type_Descriptor,0), piVar2 != (int *)0x0)) &&
      (piVar2[0x4ab] == 0)) && (piVar2[0x41b] == 0)) {
    fVar7 = (float10)FUN_006de0a0(in_ECX + 5,piVar2 + 5);
    iVar1 = FUN_0067f950();
    if ((float)fVar7 <= *(float *)(iVar1 + 0x44)) {
      piVar3 = (int *)(**(code **)(*in_ECX + 0x48))();
      if (piVar3 == (int *)0x0) {
switchD_006f5da7_caseD_2:
        return _DAT_00c706b8 & 0xff;
      }
      uVar4 = FUN_006d58d0(piVar2);
      switch(uVar4) {
      case 0:
        uVar6 = __ftol();
        return uVar6;
      case 2:
        goto switchD_006f5da7_caseD_2;
      case 3:
        uVar6 = __ftol();
        return uVar6;
      case 4:
        iVar1 = (**(code **)(*piVar3 + 0x1c))();
        iVar5 = (**(code **)(*piVar2 + 0x1c))();
        if (iVar1 != iVar5) {
LAB_006f5e8f:
          return (uint)DAT_00c70528;
        }
        if ((*(ushort *)(in_ECX + 0x38) & 0x200) == 0) {
          uVar6 = (**(code **)(*in_ECX + 0xb00))();
          iVar5 = (uVar6 & 0xff) * 0x114;
          iVar1 = *(int *)(&DAT_00cdab14 + iVar5);
          if (((iVar1 < 0) || (0x10 < iVar1)) ||
             (((float)piVar3[iVar1 + 0x67] + (float)piVar3[iVar1 + 0x42] +
              (float)piVar3[iVar1 + 0x31]) * *(float *)(&DAT_00cdab18 + iVar5) <= 0.0))
          goto LAB_006f5e8f;
        }
      }
    }
  }
  return 0;
}



// ?AttitudeToCreatureEating@Living@@UAEIXZ @ 0x006f6750

char _AttitudeToCreatureEating_Living__UAEIXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x2c8))(0);
  return (-(iVar1 != 0) & 2U) + 1;
}



// ?ExitInLanded@Living@@UAEHW4VILLAGER_STATES@@@Z @ 0x006f68c0

undefined4 _ExitInLanded_Living__UAEHW4VILLAGER_STATES___Z(undefined1 param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x960))(param_1);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*in_ECX + 0x964))(param_1);
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*in_ECX + 0x968))(param_1);
      if (iVar1 == 0) {
        return 0;
      }
    }
  }
  return 1;
}



// ?EnterDanceInScript@Living@@UAEIW4VILLAGER_STATES@@0@Z @ 0x006f6910

void _EnterDanceInScript_Living__UAEIW4VILLAGER_STATES__0_Z(undefined4 param_1,undefined4 param_2)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x93c))(param_1,param_2);
  return;
}



// ?ExitScriptWander@Living@@UAEHW4VILLAGER_STATES@@@Z @ 0x006f6970

undefined4 _ExitScriptWander_Living__UAEHW4VILLAGER_STATES___Z(undefined1 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  iVar1 = FUN_007344da();
  if (iVar1 != 0) {
    iVar1 = FUN_006e2010(param_1,param_2 & 0xff);
    if (((iVar1 == 0) && (*(int *)(in_ECX + 0xb0) != 0)) &&
       (*(uint *)(*(int *)(in_ECX + 0xb0) + 0x44) == (param_2 & 0xff))) {
      FUN_005adb30(in_ECX);
      uStack_c = 0;
      uStack_8 = 0;
      uStack_4 = 0;
      iVar1 = FUN_005c1430(&uStack_c);
      if (iVar1 != 0) {
        iVar1 = FUN_005c5a00(0);
        if (iVar1 == 0) {
          *(undefined4 *)(*(int *)(in_ECX + 0xb0) + 0x24) = 0;
          *(undefined4 *)(*(int *)(in_ECX + 0xb0) + 0x44) = 0;
          FUN_005b0de0(in_ECX + 0x80,param_2);
          return 0x23;
        }
      }
      *(undefined4 *)(*(int *)(in_ECX + 0xb0) + 0x44) = 0;
      iVar1 = *(int *)(*(int *)(in_ECX + 0xb0) + 0x3c);
      if ((iVar1 < *DAT_00df82a8) && (-1 < iVar1)) {
        iVar1 = DAT_00df82a8[iVar1 + 1];
      }
      else {
        iVar1 = DAT_00df82a8[1];
      }
      iVar2 = (**(code **)(**(int **)(in_ECX + 0x40) + 0x184))();
      if (iVar1 != iVar2) {
        (**(code **)(**(int **)(in_ECX + 0x40) + 0x180))();
        (**(code **)(**(int **)(in_ECX + 0x40) + 0x188))();
      }
    }
  }
  return 1;
}



// ?EnterScriptWander@Living@@UAEIW4VILLAGER_STATES@@0@Z @ 0x006f6af0

void _EnterScriptWander_Living__UAEIW4VILLAGER_STATES__0_Z(undefined4 param_1)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x910))(param_1);
  return;
}



// ?EnterInScript@Living@@UAEIW4VILLAGER_STATES@@0@Z @ 0x006f8ff0

undefined4 _EnterInScript_Living__UAEIW4VILLAGER_STATES__0_Z(void)

{
  uint uVar1;
  int in_ECX;
  
  uVar1 = (uint)*(byte *)(in_ECX + 0xf2);
  if (uVar1 == 7) {
    uVar1 = 0;
  }
  *(uint *)(in_ECX + 0x104) = uVar1;
  return 1;
}



// ?ExitDanceInScript@Living@@UAEHW4VILLAGER_STATES@@@Z @ 0x006f9010

int _ExitDanceInScript_Living__UAEHW4VILLAGER_STATES___Z(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = _ExitDanceInScript_Living__UAEHW4VILLAGER_STATES___Z(param_1);
  if (iVar1 == 1) {
    iVar2 = FUN_006e1ce0();
    if (iVar2 != 0) {
      *(byte *)(iVar2 + 0x7c) = *(byte *)(iVar2 + 0x7c) & 0xef;
    }
  }
  return iVar1;
}



