// Decompiled functions for class: Fixed
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?CanBeSetOnFire@Fixed@@UAE_NPAVCreature@@@Z @ 0x004012d0

uint _CanBeSetOnFire_Fixed__UAE_NPAVCreature___Z(void)

{
  int in_ECX;
  
  return ((byte)~*(byte *)(in_ECX + 10) & 8) >> 3;
}



// ?GetTownArtifact@Fixed@@UAEPAVGameThing@@XZ @ 0x004012e0

undefined4 _GetTownArtifact_Fixed__UAEPAVGameThing__XZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x54);
}



// ?IsTownArtifact@Fixed@@UAE_NXZ @ 0x004012f0

bool _IsTownArtifact_Fixed__UAE_NXZ(void)

{
  int in_ECX;
  
  return *(int *)(in_ECX + 0x54) != 0;
}



// ?NetworkFriendlyStartLockedSelect@Fixed@@UAE_NPAVGInterfaceStatus@@@Z @ 0x00404e70

undefined4 _NetworkFriendlyStartLockedSelect_Fixed__UAE_NPAVGInterfaceStatus___Z(void)

{
  return 1;
}



// ?ValidForLockedSelectProcess@Fixed@@UAE_NPAVGInterfaceStatus@@@Z @ 0x00417220

undefined4 _ValidForLockedSelectProcess_Fixed__UAE_NPAVGInterfaceStatus___Z(void)

{
  return 0;
}



// ?IsObjectFullyInMap@Fixed@@UAE_NXZ @ 0x0041f930

void _IsObjectFullyInMap_Fixed__UAE_NXZ(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0041f932. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0x558))();
  return;
}



// ?GetHowMuchCreatureWantsToLookAtMe@Fixed@@UAEMXZ @ 0x004b5380

float10 _GetHowMuchCreatureWantsToLookAtMe_Fixed__UAEMXZ(void)

{
  return (float10)0.25;
}



// ?CanBeFrighteningToCreature@Fixed@@UAE_NPAVCreature@@@Z @ 0x004c5cd0

bool _CanBeFrighteningToCreature_Fixed__UAE_NPAVCreature___Z(undefined4 param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x3b4))(param_1);
  return iVar1 == 0;
}



// ?CanBeSetOnFire@Fixed@@UAE_NPAVCreature@@@Z @ 0x004c5fd0

void _CanBeSetOnFire_Fixed__UAE_NPAVCreature___Z(undefined4 param_1)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x3b4))(param_1);
  return;
}



// ?CanBeCrushed@Fixed@@UAE_NXZ @ 0x004ff140

void _CanBeCrushed_Fixed__UAE_NXZ(void)

{
  float *pfVar1;
  int iVar2;
  int iVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  bool bVar7;
  undefined1 uVar8;
  undefined4 uVar9;
  int iVar10;
  int *in_ECX;
  uint uVar11;
  float10 fVar12;
  undefined4 *puVar13;
  float fStack_1c;
  undefined4 uStack_c;
  uint uStack_8;
  
  iVar2 = in_ECX[0x48];
  if ((float)in_ECX[0x34] < *(float *)(iVar2 + 0x120) * 0.25) {
    return;
  }
  uStack_8 = DAT_00c6e460;
  if ((float)in_ECX[0x37] < (float)DAT_00c6e460) {
    return;
  }
  in_ECX[0x39] = 0;
  bVar7 = false;
  in_ECX[0x39] = (int)-(1.0 - (float)in_ECX[0x37] / *(float *)(iVar2 + 0x130));
  if (*(float *)(iVar2 + 0x120) <= (float)in_ECX[0x34]) {
    if (*(float *)(iVar2 + 0x124) <= (float)in_ECX[0x34]) {
      uStack_c = *(undefined4 *)(in_ECX[0x10] + 0x20);
      uStack_8 = *(uint *)(in_ECX[0x10] + 0x28);
      bVar7 = true;
      uVar11 = (uint)in_ECX >> 0x10 & 0xf;
      fVar12 = (float10)(**(code **)(*in_ECX + 0x120))();
      *(float *)(in_ECX[0x10] + 0x20) =
           (float)(fVar12 * (float10)(float)(&DAT_00cc46a4)[uVar11] * (float10)1.75);
      fVar12 = (float10)(**(code **)(*in_ECX + 0x120))();
      *(float *)(in_ECX[0x10] + 0x28) =
           (float)(fVar12 * (float10)(float)(&DAT_00cc4664)[uVar11] * (float10)1.75);
      goto LAB_004ff28a;
    }
    puVar13 = &DAT_00bf03b0;
  }
  else {
    puVar13 = (undefined4 *)&DAT_00bf03b8;
  }
  uVar9 = __ftol(&DAT_00bf03b4,puVar13);
  FUN_004ff090(uVar9);
LAB_004ff28a:
  pfVar1 = (float *)(in_ECX + 0x3a);
  FUN_00406240(in_ECX[0x39],0,0x3f800000);
  fVar4 = (float)DAT_00dc8d20 * 0.001 + (float)in_ECX[0x3f];
  in_ECX[0x3f] = (int)fVar4;
  if (fVar4 < (float)in_ECX[0x40]) {
    fVar5 = fVar4 * fVar4 * 0.5;
    fVar6 = fVar4 * fVar5 * 0.33333334;
    in_ECX[0x3d] = (int)(fVar4 * (float)in_ECX[0x43] +
                         fVar6 * (float)in_ECX[0x45] + fVar5 * (float)in_ECX[0x44] +
                        (float)in_ECX[0x42]);
    *pfVar1 = (float)in_ECX[0x42] * (float)in_ECX[0x3f] +
              fVar5 * (float)in_ECX[0x43] +
              fVar6 * (float)in_ECX[0x44] + fVar5 * fVar5 * 0.16666667 * (float)in_ECX[0x45] +
              (float)in_ECX[0x41];
  }
  else {
    *pfVar1 = (float)in_ECX[0x3b];
    in_ECX[0x3d] = in_ECX[0x3c];
    in_ECX[0x3e] = 0;
    in_ECX[0x3f] = in_ECX[0x40];
  }
  fStack_1c = *pfVar1;
  iVar2 = ((int *)in_ECX[0x10])[0xf];
  if (fStack_1c < -0.8) {
    (**(code **)(*(int *)in_ECX[0x10] + 0x48))();
    uVar8 = __ftol();
    *(undefined1 *)(in_ECX[0x10] + 0x4f) = uVar8;
    fStack_1c = -0.8;
  }
  iVar10 = (**(code **)(*(int *)in_ECX[0x10] + 0xf8))();
  iVar3 = in_ECX[0x10];
  fStack_1c = *(float *)(iVar3 + 0x44) * *(float *)(iVar10 + 0x28) * fStack_1c;
  *(float *)(iVar3 + 0x3c) = fStack_1c + fStack_1c + *(float *)(iVar3 + 0x3c);
  *(undefined4 *)(in_ECX[0x10] + 0x60) = 0x40;
  *(undefined4 *)(in_ECX[0x10] + 0x5c) = 0x40;
  if (in_ECX[0x11] == 0) {
    FUN_00768080(0);
    FUN_005ed470();
  }
  else {
    FUN_006c6850();
    uVar9 = FUN_006c6760();
    FUN_00768080(uVar9);
    FUN_005ed470();
    FUN_005ea220();
  }
  *(int *)(in_ECX[0x10] + 0x3c) = iVar2;
  if (bVar7) {
    *(undefined4 *)(in_ECX[0x10] + 0x20) = uStack_c;
    *(uint *)(in_ECX[0x10] + 0x28) = uStack_8;
  }
  return;
}



// ?InsertMapObjectToCellAssumeFixed@Fixed@@UAEXPAUMapCell@@@Z @ 0x004ff730

int _InsertMapObjectToCellAssumeFixed_Fixed__UAEXPAUMapCell___Z(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *in_ECX;
  char *pcVar5;
  float10 fVar6;
  int iVar7;
  double dVar8;
  undefined1 auStack_138 [12];
  undefined1 auStack_12c [100];
  char acStack_c8 [200];
  
  iVar2 = FUN_0053eb80();
  if (iVar2 == 0) {
    return 0;
  }
  if (param_2 != 0) {
    FUN_005c13b0(auStack_138,param_2);
  }
  iVar3 = (**(code **)(*in_ECX + 0x48))();
  if (iVar3 != 0) {
    iVar3 = (**(code **)(*in_ECX + 0x48))();
    iVar3 = *(int *)(iVar3 + 0x5b4);
    if (iVar3 != -1) {
      iVar7 = in_ECX[0x48];
      fVar6 = (float10)(**(code **)(*in_ECX + 0x508))();
      iVar7 = (iVar7 + -0xbf03d0) / 0x154;
      dVar8 = (double)fVar6;
      uVar4 = FUN_005bf290(auStack_12c);
      uVar4 = FUN_006ad590(0x59,iVar3,uVar4,iVar7,dVar8);
      FUN_00733e17(acStack_c8,uVar4);
      goto LAB_004ff84d;
    }
  }
  iVar3 = in_ECX[0x48];
  fVar6 = (float10)(**(code **)(*in_ECX + 0x508))();
  iVar3 = (iVar3 + -0xbf03d0) / 0x154;
  dVar8 = (double)fVar6;
  uVar4 = FUN_005bf290(auStack_12c);
  uVar4 = FUN_006ad590(0x1d,uVar4,iVar3,dVar8);
  FUN_00733e17(acStack_c8,uVar4);
LAB_004ff84d:
  iVar3 = -1;
  pcVar5 = acStack_c8;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  FUN_006b10c0();
  return iVar2;
}



// ?InsertMapObjectToCell@Fixed@@UAEXPAUMapCell@@@Z @ 0x00502f10

void _InsertMapObjectToCell_Fixed__UAEXPAUMapCell___Z(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_10 = 0;
  uStack_c = 0;
  uStack_8 = 0;
  uStack_4 = 0;
  iVar1 = FUN_00502de0(&uStack_c,&uStack_10);
  while (iVar1 != 0) {
    uVar2 = FUN_005bfa00();
    _RemoveMapObjectFromCell_Object__UAEXPAUMapCell___Z(uVar2);
    iVar1 = FUN_00502de0(&uStack_c,&uStack_10);
  }
  *(ushort *)(in_ECX + 0x24) = *(ushort *)(in_ECX + 0x24) & 0xfffe;
  return;
}



// ?Create3DObject@Fixed@@UAEXXZ @ 0x00504170

void _Create3DObject_Fixed__UAEXXZ(void)

{
  int in_ECX;
  
  _Create3DObject_Object__UAEXXZ();
                    /* WARNING: Could not recover jumptable at 0x00504183. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(**(int **)(in_ECX + 0x40) + 0x80))();
  return;
}



// ?GetSpecialPos@Fixed@@UAE_NIPAUMapCoords@@@Z @ 0x00504190

undefined4 _GetSpecialPos_Fixed__UAE_NIPAUMapCoords___Z(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x40) != 0) {
    iVar1 = FUN_005ed240(param_1,param_2);
    if (iVar1 != 0) {
      return 1;
    }
  }
  *param_2 = *(undefined4 *)(in_ECX + 0x14);
  param_2[1] = *(undefined4 *)(in_ECX + 0x18);
  param_2[2] = *(undefined4 *)(in_ECX + 0x1c);
  return 0;
}



// ?InsertMapObjectToCell@Fixed@@UAEXPAUMapCell@@@Z @ 0x005041e0

void _InsertMapObjectToCell_Fixed__UAEXPAUMapCell___Z(int param_1)

{
  int *in_ECX;
  
  if (*(int *)(param_1 + 4) != 0) {
    (**(code **)(*in_ECX + 0x540))(*(int *)(param_1 + 4),param_1);
  }
  FUN_005bea40(in_ECX);
  FUN_005a2b10();
  FUN_0059db30();
  return;
}



// ?GetTownArtifactValue@Fixed@@UAEMXZ @ 0x00504220

float10 _GetTownArtifactValue_Fixed__UAEMXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x7fc))();
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*in_ECX + 0x7fc))();
    return (float10)*(float *)(iVar1 + 0x28);
  }
  return (float10)0.0;
}



// ?EndPhysics@Fixed@@UAEXPAVPhysicsObject@@_N@Z @ 0x00504250

void _EndPhysics_Fixed__UAEXPAVPhysicsObject___N_Z(int param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int *in_ECX;
  
  if ((char)param_2 != '\0') {
    cVar1 = (**(code **)(*in_ECX + 0xcc))();
    if (cVar1 != '\0') {
      iVar2 = FUN_005f6180();
      if (iVar2 != 0) {
        FUN_005f6180();
        iVar2 = FUN_005f8140();
        if (((iVar2 == 0) && ((*(uint *)(param_1 + 0x1d8) & 4) != 0)) &&
           ((*(uint *)(param_1 + 0x1d8) & 8) != 0)) {
          piVar3 = (int *)FUN_005c0c70(FUN_005ec8e0,0,0,0,0x42480000,0);
          if (piVar3 != (int *)0x0) {
            iVar2 = (**(code **)(*piVar3 + 0x208))();
            if (iVar2 == 0) {
              iVar2 = (**(code **)(*piVar3 + 0x304))();
              if (iVar2 != 0) {
                uVar5 = (**(code **)(*piVar3 + 0x30c))();
                iVar2 = (**(code **)(*in_ECX + 0x7fc))();
                if (iVar2 != 0) {
                  (**(code **)(*in_ECX + 0x7fc))(uVar5);
                  iVar2 = FUN_00420b20(uVar5);
                  if (iVar2 != 0) {
                    FUN_005f6180(1);
                    FUN_0067efc0();
                  }
                }
                uVar5 = FUN_005f6180();
                FUN_00706800(in_ECX,uVar5);
              }
            }
            else {
              iVar2 = (**(code **)(*piVar3 + 0x48))();
              if (iVar2 != 0) {
                iVar4 = (**(code **)(*in_ECX + 0x7fc))();
                if (iVar4 != 0) {
                  (**(code **)(*in_ECX + 0x7fc))(iVar2);
                  iVar2 = FUN_00420af0(iVar2);
                  if (iVar2 != 0) {
                    FUN_005f6180(1);
                    FUN_0067efc0();
                  }
                }
                uVar5 = FUN_005f6180();
                FUN_006d2860(in_ECX,uVar5);
                _EndPhysics_Object__UAEXPAVPhysicsObject___N_Z(param_1,param_2);
                return;
              }
            }
          }
        }
      }
    }
  }
  _EndPhysics_Object__UAEXPAVPhysicsObject___N_Z(param_1,param_2);
  return;
}



// ?InterfaceSetInMagicHand@Fixed@@UAE_NPAVGInterfaceStatus@@@Z @ 0x005043e0

void _InterfaceSetInMagicHand_Fixed__UAE_NPAVGInterfaceStatus___Z(int *param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x800))();
  if (iVar1 != 0) {
    (**(code **)(*in_ECX + 0x7fc))();
    FUN_004204b0();
    piVar2 = (int *)(**(code **)(*in_ECX + 0x7fc))();
    iVar1 = *piVar2;
    uVar3 = (**(code **)(*param_1 + 0x1c))();
    (**(code **)(iVar1 + 0x20))(uVar3);
  }
  _NetworkFriendlyStartLockedSelect_Fixed__UAE_NPAVGInterfaceStatus___Z(param_1);
  return;
}



// ?Save@Fixed@@UAEIPAVGameOSFile@@@Z @ 0x00504440

undefined4 _Save_Fixed__UAEIPAVGameOSFile___Z(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_Object__UAEIPAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x54));
    return 1;
  }
  return 0;
}



// ?Load@Fixed@@QAEIAAVGGameOSFile@@@Z @ 0x00504470

undefined4 _Load_Fixed__QAEIAAVGGameOSFile___Z(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Load__6ObjectFR10GameOSFile(param_1);
  if (iVar1 != 0) {
    FUN_00531f30(in_ECX + 0x54);
    return 1;
  }
  return 0;
}



// ?InsertMapObject@Fixed@@UAEXXZ @ 0x00504820

void _InsertMapObject_Fixed__UAEXXZ(void)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *in_ECX;
  float10 fVar5;
  
  _InsertMapObject_Object__UAEXXZ();
  iVar3 = (**(code **)(*in_ECX + 0x7bc))(0);
  puVar2 = DAT_00b81580;
  if (iVar3 != 0) {
    fVar5 = (float10)(**(code **)(*in_ECX + 100))(in_ECX + 5);
    FUN_0050b9f0((float)fVar5);
    puVar2 = DAT_00b81580;
  }
  for (; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
    uVar1 = puVar2[1];
    iVar3 = FUN_004619d0();
    iVar4 = (**(code **)(*in_ECX + 0x7bc))(uVar1);
    if (iVar4 != 0) {
      iVar4 = *(int *)(*(int *)(iVar3 + 0x5198) + 0x64054);
      if ((1 < iVar4) && (iVar4 < 5)) {
        (**(code **)(*in_ECX + 0x7c0))(*(int *)(iVar3 + 0x5198),uVar1,1,0);
      }
    }
  }
  return;
}



// ?RemoveMapObject@Fixed@@UAEXXZ @ 0x005048b0

void _RemoveMapObject_Fixed__UAEXXZ(void)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  
  _RemoveMapObject_Object__UAEXXZ();
  iVar1 = (**(code **)(*in_ECX + 0x7bc))(0);
  if (iVar1 != 0) {
    fVar2 = (float10)(**(code **)(*in_ECX + 100))(in_ECX + 5);
    FUN_0050c550((float)fVar2);
  }
  return;
}



// ?IsObjectFullyInMap@Fixed@@UAE_NXZ @ 0x00504de0

undefined4 _IsObjectFullyInMap_Fixed__UAE_NXZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x58);
}



// ?InterfaceSetInMagicHand@Fixed@@UAE_NPAVGInterfaceStatus@@@Z @ 0x00678c10

undefined4 _InterfaceSetInMagicHand_Fixed__UAE_NPAVGInterfaceStatus___Z(void)

{
  float fVar1;
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc4) = *(undefined4 *)(in_ECX + 0x14);
  *(undefined4 *)(in_ECX + 200) = *(undefined4 *)(in_ECX + 0x18);
  *(undefined4 *)(in_ECX + 0xcc) = *(undefined4 *)(in_ECX + 0x1c);
  fVar1 = *(float *)(in_ECX + 0xcc) - *(float *)(in_ECX + 0xd8);
  *(float *)(in_ECX + 0xf4) = fVar1;
  *(float *)(in_ECX + 0xf8) = fVar1;
  return 1;
}



// ?InsertMapObjectToCell@Fixed@@UAEXPAUMapCell@@@Z @ 0x006bcdb0

void _InsertMapObjectToCell_Fixed__UAEXPAUMapCell___Z(void)

{
  undefined4 uVar1;
  int *piVar2;
  int *in_ECX;
  float10 fVar3;
  
  piVar2 = (int *)in_ECX[10];
  fVar3 = (float10)(**(code **)(*in_ECX + 0x120))();
  fVar3 = (float10)(**(code **)(*in_ECX + 0x508))((float)fVar3);
  uVar1 = (**(code **)(*piVar2 + 0x2c))((float)fVar3);
  piVar2 = (int *)FUN_005ecf60(in_ECX + 5,0,uVar1);
  in_ECX[0x10] = (int)piVar2;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0x58))();
    (**(code **)(*(int *)in_ECX[0x10] + 0x78))();
    FUN_006bce20();
  }
  return;
}



// ?InterfaceSetInMagicHand@Fixed@@UAE_NPAVGInterfaceStatus@@@Z @ 0x006cb4e0

undefined4 _InterfaceSetInMagicHand_Fixed__UAE_NPAVGInterfaceStatus___Z(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xc4) = *(undefined4 *)(in_ECX + 0x14);
  *(undefined4 *)(in_ECX + 200) = *(undefined4 *)(in_ECX + 0x18);
  *(undefined4 *)(in_ECX + 0xcc) = *(undefined4 *)(in_ECX + 0x1c);
  return 1;
}



// ?VillagerMustAvoid@Fixed@@UAE_NPAVVillager@@@Z @ 0x006db750

float10 _VillagerMustAvoid_Fixed__UAE_NPAVVillager___Z(void)

{
  int *in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 100))();
  if ((float10)0.25 < fVar1 * (float10)0.1) {
    return (float10)0.25;
  }
  fVar1 = (float10)(**(code **)(*in_ECX + 100))();
  return fVar1 * (float10)0.1;
}



// ?GetTownArtifact@Fixed@@UAEPAVGameThing@@XZ @ 0x00703f90

undefined4 _GetTownArtifact_Fixed__UAEPAVGameThing__XZ(undefined4 param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  undefined1 auStack_c [12];
  
  puVar1 = (undefined4 *)FUN_00706a40(auStack_c);
  *param_2 = *puVar1;
  param_2[1] = puVar1[1];
  param_2[2] = puVar1[2];
  return 1;
}



// ?NetworkFriendlyStartLockedSelect@Fixed@@UAE_NPAVGInterfaceStatus@@@Z @ 0x00706b20

float10 _NetworkFriendlyStartLockedSelect_Fixed__UAE_NPAVGInterfaceStatus___Z(int *param_1)

{
  undefined4 uVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  int *piVar5;
  undefined1 auStack_c [12];
  
  piVar5 = param_1 + 5;
  uVar1 = FUN_00706a40(auStack_c);
  fVar2 = (float10)FUN_006de0a0(uVar1,piVar5);
  fVar3 = (float10)(**(code **)(*param_1 + 100))();
  fVar4 = (float10)FUN_00706ad0();
  return (float10)(float)fVar2 - (fVar4 + (float10)(float)fVar3);
}



