// Decompiled functions for class: SpellForest
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?CloseDown@SpellForest@@UAEXXZ @ 0x0052e700

void _CloseDown_SpellForest__UAEXXZ(void)

{
  int in_ECX;
  
  FUN_006b7420();
  *(undefined4 *)(in_ECX + 0xa0) = 0;
  return;
}



// ?GetDebugText@SpellForest@@UAEPADXZ @ 0x0052e720

char * _GetDebugText_SpellForest__UAEPADXZ(void)

{
  return s_SpellForest__00b1a354;
}



// ?ToBeDeleted@SpellForest@@UAEXH@Z @ 0x006bc320

void _ToBeDeleted_SpellForest__UAEXH_Z(undefined4 param_1)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = *(int **)(in_ECX + 0xec);
  if ((piVar1 != (int *)0x0) && ((*(byte *)((int)piVar1 + 10) & 1) == 0)) {
    (**(code **)(*piVar1 + 0xc))(0);
    *(undefined4 *)(in_ECX + 0xec) = 0;
  }
  _ToBeDeleted_Spell__UAEXH_Z(param_1);
  return;
}



// ?InitWithPos@SpellForest@@UAEHPAVGameThing@@ABUMapCoords@@PAVSpellCastData@@ABUPSysProcessInfo@@@Z @ 0x006bc360

void _InitWithPos_SpellForest__UAEHPAVGameThing__ABUMapCoords__PAVSpellCastData__ABUPSysProcessInfo___Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  _InitWithPos_Spell__UAEHPAVGameThing__ABUMapCoords__PAVSpellCastData__ABUPSysProcessInfo___Z
            (param_1,param_2,param_3,param_4);
  return;
}



// ?SetMaxObjectsToCreate@SpellForest@@UAEXH@Z @ 0x006bc4e0

void _SetMaxObjectsToCreate_SpellForest__UAEXH_Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  *(int *)(in_ECX + 0xf4) = param_1;
  if (param_1 == -1) {
    iVar1 = FUN_006c4230();
    *(undefined4 *)(in_ECX + 0xf4) = *(undefined4 *)(iVar1 + 0x58);
  }
  return;
}



// ?GetMaxObjectsToCreate@SpellForest@@UAEHXZ @ 0x006bc510

int _GetMaxObjectsToCreate_SpellForest__UAEHXZ(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = FUN_006c4230();
  iVar1 = *(int *)(in_ECX + 0xec);
  iVar2 = *(int *)(iVar2 + 0x58);
  if (iVar1 == 0) {
    if (*(char *)(in_ECX + 0xf0) != '\0') {
      iVar2 = 0;
    }
  }
  else {
    iVar2 = *(int *)(iVar1 + 0x54) + *(int *)(iVar1 + 0x4c);
  }
  if (*(int *)(in_ECX + 0xf4) <= iVar2) {
    iVar2 = *(int *)(in_ECX + 0xf4);
  }
  return iVar2;
}



// ?HasEnoughChantsAndLifeForRecast@SpellForest@@UAEXXZ @ 0x006bc550

bool _HasEnoughChantsAndLifeForRecast_SpellForest__UAEXXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x550))();
  return 0 < iVar1;
}



// ?AdjustSpellSeedPos@SpellForest@@UAEXPAUMapCoords@@@Z @ 0x006bc570

void _AdjustSpellSeedPos_SpellForest__UAEXPAUMapCoords___Z(int param_1)

{
  int in_ECX;
  float10 fVar1;
  
  if (*(int *)(in_ECX + 0xec) != 0) {
    fVar1 = (float10)FUN_0050ec40();
    if (fVar1 < (float10)*(float *)(param_1 + 8)) {
      fVar1 = (float10)*(float *)(param_1 + 8);
    }
    *(float *)(param_1 + 8) = (float)fVar1;
    return;
  }
  *(undefined4 *)(param_1 + 8) = 0xc0a00000;
  return;
}



// ?SpellEvent@SpellForest@@UAEXABVSpellEventInfo@@@Z @ 0x006bc650

undefined4 _SpellEvent_SpellForest__UAEXABVSpellEventInfo___Z(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  float10 fVar8;
  float fStack_48;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined1 auStack_24 [12];
  float fStack_18;
  float fStack_c;
  
  if ((*param_1 != 1) && (*(int *)(in_ECX + 0xec) == 0)) {
    iVar1 = FUN_006b7e70(param_1);
    if (iVar1 == 1) {
      iVar1 = FUN_006bc5b0();
      fStack_48 = 1.0;
      if (1 < iVar1) {
        fStack_48 = 1.0 / ((float)iVar1 - 1.0);
      }
      FUN_005c0400(auStack_24);
      param_1 = (int *)0x0;
      if (0 < iVar1) {
        do {
          fVar4 = (float10)FUN_006bc380();
          fVar5 = (float10)FUN_006bc390();
          fVar6 = (float10)1.0 - (float10)((float)(int)param_1 * fStack_48);
          fVar7 = (float10)((float)(int)param_1 * fStack_48) *
                  (float10)((float)iVar1 * 1.3076923 * 6.2831855);
          fVar8 = (float10)fcos(fVar7);
          fStack_18 = (float)fVar8;
          fsin(fVar7);
          fStack_c = (float)((float10)fStack_18 *
                            (((float10)(float)fVar4 - fVar5) * SQRT((float10)1.0 - fVar6 * fVar6) +
                            fVar5));
          uStack_30 = __ftol();
          uStack_2c = __ftol();
          uStack_28 = 0;
          iVar2 = FUN_006bc930(&uStack_30);
          if (iVar2 != 0) {
            iVar2 = FUN_006bc620();
            if (iVar2 != 0) {
              uVar3 = FUN_006bc3a0(in_ECX + 0xc0);
              FUN_006bc420(&uStack_30,uVar3);
            }
          }
          param_1 = (int *)((int)param_1 + 1);
        } while ((int)param_1 < iVar1);
      }
    }
  }
  return 1;
}



// ?Process@SpellForest@@UAEIXZ @ 0x006bc7e0

void _Process_SpellForest__UAEIXZ(void)

{
  float10 fVar1;
  
  fVar1 = (float10)FUN_006b78b0();
  FUN_006bc840((float)fVar1);
  return;
}



// ?CalculateCostToMaintain@SpellForest@@UAEMXZ @ 0x006bc800

float10 _CalculateCostToMaintain_SpellForest__UAEMXZ(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  float10 fVar3;
  
  iVar2 = FUN_006b7980();
  fVar3 = (float10)_CalculateCostToMaintain_Spell__UAEMXZ();
  iVar1 = *(int *)(in_ECX + 0xec);
  if (iVar1 != 0) {
    fVar3 = (float10)(uint)(*(int *)(iVar1 + 0x54) + *(int *)(iVar1 + 0x4c)) *
            (float10)*(float *)(iVar2 + 0x7c) + fVar3;
  }
  return fVar3;
}



// ?Save@SpellForest@@UAEIAAVGameOSFile@@@Z @ 0x006bc970

undefined4 _Save_SpellForest__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_Spell__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0xf0),1,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xf0) + 1;
    }
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0xec));
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0xf4),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xf4) + 4;
    }
    return 1;
  }
  return 0;
}



// ?Load@SpellForest@@UAEIAAVGameOSFile@@@Z @ 0x006bca30

undefined4 _Load_SpellForest__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Load_Spell__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0xf0),1,0,unaff_EBX,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xf0) + 1;
    }
    FUN_00531f30();
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xf4) + 4;
    }
    return 1;
  }
  return 0;
}



