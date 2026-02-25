// Decompiled functions for class: GameThing
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?CalculateInfluence@GameThing@@QAEMABUMapCoords@@@Z @ 0x00401490

float10 _CalculateInfluence_GameThing__QAEMABUMapCoords___Z(void)

{
  return (float10)1.0;
}



// ?IsAvailable@GameThing@@QAE_NXZ @ 0x004014a0

byte _IsAvailable_GameThing__QAE_NXZ(void)

{
  int in_ECX;
  
  return ~*(byte *)(in_ECX + 10) & 1;
}



// ?GetMaxAlignmentChangePerGameTurn@GameThing@@UAEMXZ @ 0x004014b0

float10 _GetMaxAlignmentChangePerGameTurn_GameThing__UAEMXZ(void)

{
  return (float10)2.7777778e-05;
}



// ?IsDeletedOnNewMap@GameThing@@QAE_NXZ @ 0x00401810

undefined4 _IsDeletedOnNewMap_GameThing__QAE_NXZ(void)

{
  return 1;
}



// ?SetPlayer@GameThing@@QAEXPAVGPlayer@@@Z @ 0x004033c0

void _SetPlayer_GameThing__QAEXPAVGPlayer___Z(void)

{
  return;
}



// ?JustGetResource@GameThing@@QAEIW4RESOURCE_TYPE@@KPA_N@Z @ 0x00403870

void _JustGetResource_GameThing__QAEIW4RESOURCE_TYPE__KPA_N_Z(int param_1,int param_2)

{
  int *piVar1;
  int in_ECX;
  
  piVar1 = (int *)(in_ECX + 0xbc + param_1 * 4);
  *piVar1 = *piVar1 + param_2;
  return;
}



// ?GetNearestPathTo@GameThing@@QAEIABUMapCoords@@MH@Z @ 0x00403c10

undefined4 _GetNearestPathTo_GameThing__QAEIABUMapCoords__MH_Z(void)

{
  return 0;
}



// ?AddResource@GameThing@@QAEIW4RESOURCE_TYPE@@KPAVGInterfaceStatus@@_NABUMapCoords@@H@Z @ 0x00403c30

undefined4
_AddResource_GameThing__QAEIW4RESOURCE_TYPE__KPAVGInterfaceStatus___NABUMapCoords__H_Z(void)

{
  return 0;
}



// ?RemoveResource@GameThing@@QAEIW4RESOURCE_TYPE@@KPAVGInterfaceStatus@@PA_N@Z @ 0x00403c40

undefined4 _RemoveResource_GameThing__QAEIW4RESOURCE_TYPE__KPAVGInterfaceStatus__PA_N_Z(void)

{
  return 0;
}



// ?GetNumberOfInstanceForGlobalList@GameThing@@QAEGXZ @ 0x00403c50

undefined2 _GetNumberOfInstanceForGlobalList_GameThing__QAEGXZ(void)

{
  return 1;
}



// ?CanBecomeArtifact@GameThing@@QAE_NXZ @ 0x00403c60

undefined1 _CanBecomeArtifact_GameThing__QAE_NXZ(void)

{
  return 0;
}



// ?IsFunctional@GameThing@@QAE_NXZ @ 0x00403c70

void _IsFunctional_GameThing__QAE_NXZ(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00403c72. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0x2c))();
  return;
}



// ?GetTown@GameThing@@QAEPAVTown@@XZ @ 0x00404e60

undefined4 _GetTown_GameThing__QAEPAVTown__XZ(void)

{
  return 0;
}



// ?UpdateSpellInfo@GameThing@@QAEXPAVSpell@@PAVPSysProcessInfo@@@Z @ 0x00407650

void _UpdateSpellInfo_GameThing__QAEXPAVSpell__PAVPSysProcessInfo___Z(void)

{
  return;
}



// ?SaveExtraData@GameThing@@QAEXAAVGameOSFile@@@Z @ 0x0041cc70

undefined4 _SaveExtraData_GameThing__QAEXAAVGameOSFile___Z(void)

{
  return 0x75;
}



// ?GetSampleForAttack@GameThing@@UAEIXZ @ 0x0041cc80

char * _GetSampleForAttack_GameThing__UAEIXZ(void)

{
  return s_AnimatedStatic__008f8328;
}



// ?SaveExtraData@GameThing@@QAEXAAVGameOSFile@@@Z @ 0x0041d950

undefined4 _SaveExtraData_GameThing__QAEXAAVGameOSFile___Z(void)

{
  return 0x74;
}



// ?GetSampleForAttack@GameThing@@UAEIXZ @ 0x0041d960

char * _GetSampleForAttack_GameThing__UAEIXZ(void)

{
  return s_Feature__008f8338;
}



// ?GetDebugText@GameThing@@QAEPADXZ @ 0x00420020

char * _GetDebugText_GameThing__QAEPADXZ(void)

{
  return s_GameThing_Unknown_008f8464;
}



// ?GetGuidanceResourceType@GameThing@@UAEIXZ @ 0x004319f0

char * _GetGuidanceResourceType_GameThing__UAEIXZ(void)

{
  return s_BigForest__008fbeb4;
}



// ?CastPlayer@GameThing@@QAEPAVGPlayer@@XZ @ 0x00431c90

uint _CastPlayer_GameThing__QAEPAVGPlayer__XZ(int param_1,uint param_2)

{
  uint uVar1;
  int *in_ECX;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  
  if (param_1 != 1) {
    return 0;
  }
  fVar2 = (float10)(**(code **)(*in_ECX + 0x11c))();
  fVar3 = (float10)(**(code **)(*in_ECX + 0x664))();
  if (fVar3 <= (float10)(float)((float10)param_2 / fVar2)) {
    (**(code **)(*in_ECX + 0x664))();
    uVar1 = __ftol();
    in_ECX[0x21] = 0;
    (**(code **)(*in_ECX + 0xc))(0);
    return uVar1;
  }
  in_ECX[0x21] = (int)((float)in_ECX[0x21] - (float)((float10)param_2 / fVar2));
  uVar1 = *(uint *)(in_ECX[10] + 0x6c);
  fVar2 = (float10)(**(code **)(*in_ECX + 0x120))();
  fVar3 = (float10)(**(code **)(*in_ECX + 0x11c))();
  fVar4 = (float10)(**(code **)(*in_ECX + 0x664))();
  if ((float10)250.0 < ABS(fVar4 - (float10)(float)(fVar3 * (float10)(float)fVar2 * (float10)uVar1))
     ) {
    uVar1 = *(uint *)(in_ECX[10] + 0x6c);
    fVar2 = (float10)(**(code **)(*in_ECX + 0x664))();
    fVar3 = (float10)(**(code **)(*in_ECX + 0x11c))();
    (**(code **)(*in_ECX + 0x124))((float)((float10)(float)fVar2 / (fVar3 * (float10)uVar1)));
    FUN_00431de0();
  }
  return param_2;
}



// ?SaveExtraData@GameThing@@QAEXAAVGameOSFile@@@Z @ 0x00432030

undefined4 _SaveExtraData_GameThing__QAEXAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_MultiMapFixed__UAEIPAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x80));
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x84),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x84) + 4;
    }
    return 1;
  }
  return 0;
}



// ?SaveExtraData@GameThing@@QAEXAAVGameOSFile@@@Z @ 0x004321f0

undefined4 _SaveExtraData_GameThing__QAEXAAVGameOSFile___Z(void)

{
  return 0x72;
}



// ?ResolveLoad@GameThing@@QAEXXZ @ 0x00435fd0

undefined4 _ResolveLoad_GameThing__QAEXXZ(void)

{
  return 0x5e;
}



// ?GetSampleForAttack@GameThing@@UAEIXZ @ 0x00435fe0

char * _GetSampleForAttack_GameThing__UAEIXZ(void)

{
  return s_WorkshopBuildingSite__008fc08c;
}



// ?SaveExtraData@GameThing@@QAEXAAVGameOSFile@@@Z @ 0x00450000

undefined4 _SaveExtraData_GameThing__QAEXAAVGameOSFile___Z(void)

{
  return 0x3a;
}



// ?GetSampleForAttack@GameThing@@UAEIXZ @ 0x00450010

char * _GetSampleForAttack_GameThing__UAEIXZ(void)

{
  return s_CitadelHeart__008fd0a4;
}



// ?SaveExtraData@GameThing@@QAEXAAVGameOSFile@@@Z @ 0x00454680

undefined4 _SaveExtraData_GameThing__QAEXAAVGameOSFile___Z(void)

{
  return 0x36;
}



// ?GetSampleForAttack@GameThing@@UAEIXZ @ 0x00454690

char * _GetSampleForAttack_GameThing__UAEIXZ(void)

{
  return s_CitadelPart__008fd1dc;
}



// ?CastPlayer@GameThing@@QAEPAVGPlayer@@XZ @ 0x004ee920

uint _CastPlayer_GameThing__QAEPAVGPlayer__XZ(uint param_1)

{
  uint uVar1;
  int *in_ECX;
  
  uVar1 = (**(code **)(*in_ECX + 0x98))(param_1);
  if (uVar1 <= param_1) {
    (**(code **)(*in_ECX + 0xc))(0);
    return uVar1;
  }
  (**(code **)(*in_ECX + 0x124))
            ((float)(uVar1 - param_1) /
             ((float)*(uint *)(in_ECX[0x25] + 0x6c) * (float)in_ECX[0x27]));
  return param_1;
}



// ?SaveExtraData@GameThing@@QAEXAAVGameOSFile@@@Z @ 0x004eeb50

undefined4 _SaveExtraData_GameThing__QAEXAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _GetSaveType_Rock__UAEIXZ(param_1);
  if (iVar1 != 0) {
    FUN_00533b90(*(undefined4 *)(in_ECX + 0x94));
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x9c),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x9c) + 4;
    }
    return 1;
  }
  return 0;
}



// ?SaveExtraData@GameThing@@QAEXAAVGameOSFile@@@Z @ 0x004eee30

undefined4 _SaveExtraData_GameThing__QAEXAAVGameOSFile___Z(void)

{
  return 0x71;
}



// ?GetPlayer@GameThing@@QAEPAVGPlayer@@XZ @ 0x004fe200

int _GetPlayer_GameThing__QAEPAVGPlayer__XZ(void)

{
  return DAT_00c22ca4 + 0x18 + (uint)*(byte *)(DAT_00c22ca4 + 0x201b17) * 0x278;
}



// ?SaveExtraData@GameThing@@QAEXAAVGameOSFile@@@Z @ 0x00502a70

undefined4 _SaveExtraData_GameThing__QAEXAAVGameOSFile___Z(void)

{
  return 0x5b;
}



// ?GetSampleForAttack@GameThing@@UAEIXZ @ 0x00502a80

char * _GetSampleForAttack_GameThing__UAEIXZ(void)

{
  return s_FishFarm__00b17064;
}



// ?CastCreature@GameThing@@QAEPAVCreature@@XZ @ 0x005033c0

undefined4 _CastCreature_GameThing__QAEPAVCreature__XZ(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = FUN_00503370(param_2);
    return uVar1;
  }
  return 0;
}



// ?SaveExtraData@GameThing@@QAEXAAVGameOSFile@@@Z @ 0x00507100

char * _SaveExtraData_GameThing__QAEXAAVGameOSFile___Z(void)

{
  return s_Football__00b171c8;
}



// ?SaveExtraData@GameThing@@QAEXAAVGameOSFile@@@Z @ 0x0050b920

undefined4 _SaveExtraData_GameThing__QAEXAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_0053e8e0(param_1);
  if (iVar1 == 1) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x18),0xc,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x18) + 0xc;
    }
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x14));
    return 1;
  }
  return 0;
}



// ?SaveExtraData@GameThing@@QAEXAAVGameOSFile@@@Z @ 0x0052ed40

undefined4 _SaveExtraData_GameThing__QAEXAAVGameOSFile___Z(void)

{
  return 0x3c;
}



// ?GetSampleForAttack@GameThing@@UAEIXZ @ 0x0052ed50

char * _GetSampleForAttack_GameThing__UAEIXZ(void)

{
  return s_WorshipSite__00b1a444;
}



// ?GetGuidanceResourceType@GameThing@@UAEIXZ @ 0x005313b0

char * _GetGuidanceResourceType_GameThing__UAEIXZ(void)

{
  return s_TotemStatue__00b1b2a0;
}



// ?SaveExtraData@GameThing@@QAEXAAVGameOSFile@@@Z @ 0x005314e0

undefined4 _SaveExtraData_GameThing__QAEXAAVGameOSFile___Z(void)

{
  return 0x6f;
}



// ?GetVillagerActivityDesire@GameThing@@QAEMPAVVillager@@@Z @ 0x00531860

float10 _GetVillagerActivityDesire_GameThing__QAEMPAVVillager___Z(void)

{
  return (float10)0.0;
}



// ?ToBeDeleted@GameThing@@UAEXH@Z @ 0x0053e870

void _ToBeDeleted_GameThing__UAEXH_Z(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  int *piVar5;
  
  bVar1 = *(byte *)((int)in_ECX + 10);
  if ((bVar1 & 1) == 0) {
    *(byte *)((int)in_ECX + 10) = bVar1 | 1;
    if (param_1 != 0) {
      (**(code **)(*in_ECX + 8))();
      return;
    }
    *(byte *)((int)in_ECX + 10) = bVar1 & 0xfd | 1;
    in_ECX[4] = 0;
    iVar3 = DAT_00c22ca4;
    piVar4 = *(int **)(DAT_00c22ca4 + 0x201dd8);
    piVar5 = (int *)(DAT_00c22ca4 + 0x201dd8);
    if (piVar4 != (int *)0x0) {
      while (piVar4 != in_ECX) {
        piVar4 = (int *)piVar4[4];
        if (piVar4 == (int *)0x0) {
          in_ECX[4] = *piVar5;
          iVar2 = *(int *)(iVar3 + 0x201ddc);
          *piVar5 = (int)in_ECX;
          *(int *)(iVar3 + 0x201ddc) = iVar2 + 1;
          return;
        }
      }
      if (piVar4 != (int *)0x0) {
        return;
      }
    }
    in_ECX[4] = *piVar5;
    iVar2 = *(int *)(iVar3 + 0x201ddc);
    *piVar5 = (int)in_ECX;
    *(int *)(iVar3 + 0x201ddc) = iVar2 + 1;
  }
  return;
}



// ?SaveExtraData@GameThing@@QAEXAAVGameOSFile@@@Z @ 0x0053ea90

void _SaveExtraData_GameThing__QAEXAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  uint uStack_4;
  
  uStack_4 = 0;
  if (DAT_00b19ac8 != 0) {
    iVar1 = FUN_0072be90(&uStack_4,4,0);
    if (iVar1 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (uStack_4 & 0xff) + 4;
  }
  return;
}



// ?MaintainSpell@GameThing@@UAEXIM@Z @ 0x0053eb70

float10 _MaintainSpell_GameThing__UAEXIM_Z(undefined4 param_1,float param_2)

{
  return (float10)param_2;
}



// ?UseFootpathIfNecessary@GameThing@@QAEXPAVLiving@@ABUMapCoords@@E@Z @ 0x0053ecd0

void _UseFootpathIfNecessary_GameThing__QAEXPAVLiving__ABUMapCoords__E_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  FUN_005b0e40(param_2,param_3);
  return;
}



// ?JustAddResource@GameThing@@QAEIW4RESOURCE_TYPE@@K_N@Z @ 0x0053ef30

undefined4 _JustAddResource_GameThing__QAEIW4RESOURCE_TYPE__K_N_Z(void)

{
  return 0;
}



// ?SaveExtraData@GameThing@@QAEXAAVGameOSFile@@@Z @ 0x005c3460

undefined4 _SaveExtraData_GameThing__QAEXAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Load__13MultiMapFixedFR10GameOSFile(param_1);
  if (iVar1 != 0) {
    FUN_00531f30(in_ECX + 0x7c);
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x80),4,0,unaff_EBX,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x80) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x84) + 4;
    }
    return 1;
  }
  return 0;
}



// ?CastCreature@GameThing@@QAEPAVCreature@@XZ @ 0x00682130

uint _CastCreature_GameThing__QAEPAVCreature__XZ(uint param_1)

{
  float fVar1;
  float fVar2;
  uint uVar3;
  int *in_ECX;
  float10 fVar4;
  
  uVar3 = (**(code **)(*in_ECX + 0x98))(param_1);
  if (uVar3 <= param_1) {
    (**(code **)(*in_ECX + 0xc))(0);
    return uVar3;
  }
  fVar2 = (float)(uVar3 - param_1) / (float)*(int *)(in_ECX[10] + 0x6c);
  fVar1 = (float)in_ECX[7];
  fVar4 = (float10)(**(code **)(*in_ECX + 0x120))();
  in_ECX[7] = (int)(float)((float10)(fVar1 * fVar2) / fVar4);
  (**(code **)(*in_ECX + 0x124))(fVar2);
  return param_1;
}



// ?GetGuidanceResourceType@GameThing@@UAEIXZ @ 0x006b3330

undefined4 _GetGuidanceResourceType_GameThing__UAEIXZ(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0067bcf0(10);
  switch(uVar1) {
  case 0:
    return 0x1342;
  case 1:
    return 0x1343;
  case 2:
    return 0x1344;
  case 3:
    return 0x1345;
  case 4:
    return 0x1346;
  case 5:
    return 0x1347;
  case 6:
    return 0x1348;
  case 7:
    return 0x1349;
  case 8:
    return 0x134a;
  case 9:
    return 0x134b;
  default:
    return 0;
  }
}



// ?CastCreature@GameThing@@QAEPAVCreature@@XZ @ 0x006c91a0

int _CastCreature_GameThing__QAEPAVCreature__XZ
              (int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  char cVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int *in_ECX;
  int unaff_EBX;
  int iVar5;
  undefined *puVar6;
  int *piVar7;
  undefined *puVar8;
  undefined4 uVar9;
  undefined1 auStack_c [12];
  
  iVar5 = 0;
  if (((int *)in_ECX[0x1d] != (int *)0x0) && ((param_1 == 1 || (param_1 == -2)))) {
    iVar5 = (**(code **)(*(int *)in_ECX[0x1d] + 0x9c))(param_1,param_2,param_3,param_4,0,0);
    return iVar5;
  }
  if (param_1 == 0) {
    puVar6 = &DAT_00c6d688;
    piVar7 = in_ECX + 0x31;
    do {
      if (param_2 == 0) break;
      if (*piVar7 == 0) {
        (**(code **)(*in_ECX + 0x508))(0x3f800000,0);
        uVar9 = 0;
        puVar8 = puVar6;
        uVar2 = FUN_006c9590(auStack_c,0,iVar5);
        piVar3 = (int *)FUN_00616c40(uVar2,puVar8,uVar9);
        *piVar7 = (int)piVar3;
        if (((char)param_4 == '\0') && (cVar1 = (**(code **)(*piVar3 + 0x4a4))(), cVar1 == '\0')) {
          uVar2 = 0;
        }
        else {
          uVar2 = 1;
        }
        (**(code **)(*(int *)*piVar7 + 0x69c))(uVar2);
      }
      if (((int *)*piVar7 != (int *)0x0) &&
         (iVar4 = (**(code **)(*(int *)*piVar7 + 0x2c))(), iVar4 != 0)) {
        iVar4 = (**(code **)(*(int *)*piVar7 + 0x8c))(0,param_2,param_4);
        param_2 = param_2 - iVar4;
      }
      puVar6 = puVar6 + 0x144;
      iVar5 = iVar5 + 1;
      piVar7 = piVar7 + 1;
    } while (puVar6 < &DAT_00c6d7cc);
  }
  else if (param_1 == 1) {
    puVar6 = &DAT_00c6d7cc;
    piVar7 = in_ECX + 0x32;
    do {
      if (param_2 == 0) break;
      if (*piVar7 == 0) {
        (**(code **)(*in_ECX + 0x508))(0x3f800000,0);
        uVar9 = 0;
        puVar8 = puVar6;
        uVar2 = FUN_006c9590(auStack_c,1,iVar5);
        piVar3 = (int *)FUN_00616c40(uVar2,puVar8,uVar9);
        *piVar7 = (int)piVar3;
        if (((char)param_4 == '\0') && (cVar1 = (**(code **)(*piVar3 + 0x4a4))(), cVar1 == '\0')) {
          uVar2 = 0;
        }
        else {
          uVar2 = 1;
        }
        (**(code **)(*(int *)*piVar7 + 0x69c))(uVar2);
      }
      if (((int *)*piVar7 != (int *)0x0) &&
         (iVar4 = (**(code **)(*(int *)*piVar7 + 0x2c))(), iVar4 != 0)) {
        iVar4 = (**(code **)(*(int *)*piVar7 + 0x8c))(1,param_2,param_4);
        param_2 = param_2 - iVar4;
      }
      puVar6 = puVar6 + 0x144;
      iVar5 = iVar5 + 1;
      piVar7 = piVar7 + 1;
    } while (puVar6 < &DAT_00c6de20);
  }
  iVar5 = (**(code **)(*in_ECX + 0x98))(param_1);
  if (((iVar5 == 0) && (unaff_EBX != 0)) && (iVar5 = (**(code **)(*in_ECX + 0x48))(), iVar5 != 0)) {
    iVar5 = (**(code **)(*in_ECX + 0x48))();
    *(undefined4 *)(iVar5 + 0x5e8) = 1;
    *(undefined4 *)(iVar5 + 0x5ec) = 0;
  }
  (**(code **)(*in_ECX + 0x8e4))(param_1,unaff_EBX,param_2,param_3,param_4,param_5);
  return unaff_EBX;
}



// ?CastPlayer@GameThing@@QAEPAVGPlayer@@XZ @ 0x006c94e0

int _CastPlayer_GameThing__QAEPAVGPlayer__XZ
              (int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *in_ECX;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  if (param_1 == 0) {
    iVar3 = 0;
    piVar2 = in_ECX + 0x31;
    do {
      if (param_2 == 0) break;
      if ((int *)*piVar2 != (int *)0x0) {
        iVar1 = (**(code **)(*(int *)*piVar2 + 0x90))(0,param_2,0);
        iVar4 = iVar4 + iVar1;
        param_2 = param_2 - iVar1;
      }
      iVar3 = iVar3 + -1;
      piVar2 = piVar2 + -1;
    } while (-1 < iVar3);
  }
  else {
    if (param_1 != 1) {
      return 0;
    }
    iVar3 = 4;
    piVar2 = in_ECX + 0x36;
    do {
      if (param_2 == 0) break;
      if ((int *)*piVar2 != (int *)0x0) {
        iVar1 = (**(code **)(*(int *)*piVar2 + 0x90))(1,param_2,0);
        iVar4 = iVar4 + iVar1;
        param_2 = param_2 - iVar1;
      }
      iVar3 = iVar3 + -1;
      piVar2 = piVar2 + -1;
    } while (-1 < iVar3);
  }
  if (iVar4 != 0) {
    (**(code **)(*in_ECX + 0x8e8))(param_1,iVar4,param_3,param_4);
  }
  return iVar4;
}



// ?SaveExtraData@GameThing@@QAEXAAVGameOSFile@@@Z @ 0x006cc500

undefined4 _SaveExtraData_GameThing__QAEXAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_MultiMapFixed__UAEIPAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x7c));
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x80),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x80) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90((byte *)(in_ECX + 0x84),4,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x84) + 4;
        if (DAT_00b19ac8 != 0) {
          iVar1 = FUN_0072be90((byte *)(in_ECX + 0x88),4,0);
          if (iVar1 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x88) + 4;
        }
      }
    }
    return 1;
  }
  return 0;
}



// ?SaveExtraData@GameThing@@QAEXAAVGameOSFile@@@Z @ 0x006da8d0

undefined4 _SaveExtraData_GameThing__QAEXAAVGameOSFile___Z(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_006be540(param_1);
  if (iVar1 != 0) {
    FUN_00531f30(in_ECX + 0x114);
    return 1;
  }
  return 0;
}



// ?SaveExtraData@GameThing@@QAEXAAVGameOSFile@@@Z @ 0x006daa00

undefined4 _SaveExtraData_GameThing__QAEXAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  undefined4 unaff_EBX;
  uint uVar3;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  byte *pbVar4;
  uint in_stack_00005d15;
  uint in_stack_0000ba26;
  
  iVar1 = param_1;
  iVar2 = _SaveExtraData_GameThing__QAEXAAVGameOSFile___Z(param_1);
  if (iVar2 != 0) {
    FUN_00531f30(in_ECX + 0x118);
    if (DAT_00b19acc != 0) {
      iVar2 = FUN_0072be50(&param_1,4,0,unaff_EBX,unaff_EDI,unaff_ESI);
      if (iVar2 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + (in_stack_00005d15 & 0xff) + 4;
      uVar3 = 0;
      if (in_stack_00005d15 != 0) {
        pbVar4 = (byte *)(in_ECX + 0x11c);
        do {
          if (DAT_00b19acc != 0) {
            iVar2 = FUN_0072be50();
            if (iVar2 == 3) {
              DAT_00b19acc = 0;
            }
            *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *pbVar4 + 4;
            in_stack_00005d15 = in_stack_0000ba26;
          }
          uVar3 = uVar3 + 1;
          pbVar4 = pbVar4 + 4;
        } while (uVar3 < in_stack_00005d15);
      }
    }
    return 1;
  }
  return 0;
}



// ?CastCreature@GameThing@@QAEPAVCreature@@XZ @ 0x00705680

undefined4
_CastCreature_GameThing__QAEPAVCreature__XZ
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int in_ECX;
  
  if ((*(int **)(in_ECX + 0x74) != (int *)0x0) && ((param_1 == 1 || (param_1 == -2)))) {
    uVar1 = (**(code **)(**(int **)(in_ECX + 0x74) + 0xa0))(param_1,param_2,param_3,param_4);
    return uVar1;
  }
  if ((param_1 == 0) && (*(int **)(in_ECX + 0xb4) != (int *)0x0)) {
    uVar1 = (**(code **)(**(int **)(in_ECX + 0xb4) + 0x90))(0,param_2,0);
    return uVar1;
  }
  return 0;
}



// ?GetDrawImportance@GameThing@@QAEMXZ @ 0x007075e0

float10 _GetDrawImportance_GameThing__QAEMXZ(void)

{
  return (float10)0.0;
}



