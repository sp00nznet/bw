// Decompiled functions for class: Spell
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetSpellCastPos@Spell@@UAEXPAUMapCoords@@@Z @ 0x0052e470

void _GetSpellCastPos_Spell__UAEXPAUMapCoords___Z(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0xcc);
  param_1[1] = *(undefined4 *)(in_ECX + 0xd0);
  param_1[2] = *(undefined4 *)(in_ECX + 0xd4);
  return;
}



// ?GetLife@Spell@@UAEMXZ @ 0x0052e4a0

float10 _GetLife_Spell__UAEMXZ(void)

{
  int in_ECX;
  
  return (float10)*(float *)(in_ECX + 0x38);
}



// ?IsFunctional@Spell@@UAE_NXZ @ 0x0052e4b0

undefined4 _IsFunctional_Spell__UAE_NXZ(void)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  
  fVar2 = (float10)(**(code **)(*in_ECX + 0x11c))();
  if (fVar2 != (float10)0.0) {
    iVar1 = (**(code **)(*in_ECX + 0x2c))();
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}



// ?GetPlayer@Spell@@UAEPAVGPlayer@@XZ @ 0x0052e4e0

undefined4 _GetPlayer_Spell__UAEPAVGPlayer__XZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xa4);
}



// ?GetText@Spell@@UAEPBDXZ @ 0x0052e500

char * _GetText_Spell__UAEPBDXZ(void)

{
  return s_Spell_00b0d3ac;
}



// ?GetImpressiveIntensity@Spell@@UAEMW4IMPRESSIVE_TYPE@@@Z @ 0x0052e520

void _GetImpressiveIntensity_Spell__UAEMW4IMPRESSIVE_TYPE___Z(void)

{
  FUN_006b79a0();
  return;
}



// ?GetMovementDirection@Spell@@UAEXPAULHPoint@@@Z @ 0x006672a0

void _GetMovementDirection_Spell__UAEXPAULHPoint___Z(undefined4 *param_1)

{
  int in_ECX;
  
  *param_1 = *(undefined4 *)(in_ECX + 0x2c);
  param_1[1] = *(undefined4 *)(in_ECX + 0x30);
  param_1[2] = *(undefined4 *)(in_ECX + 0x34);
  return;
}



// ?GetSampleForAttack@Spell@@UAEIXZ @ 0x006b3290

undefined4 _GetSampleForAttack_Spell__UAEIXZ(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  iVar1 = FUN_006c1b80(*(undefined4 *)(*(int *)(in_ECX + 0xac) + 0x28));
  if (iVar1 == 6) {
    uVar2 = FUN_0067bcf0(10);
    switch(uVar2) {
    case 0:
      return 0x132e;
    case 1:
      return 0x132f;
    case 2:
      return 0x1330;
    case 3:
      return 0x1331;
    case 4:
      return 0x1332;
    case 5:
      return 0x1333;
    case 6:
      return 0x1334;
    case 7:
      return 0x1335;
    case 8:
      return 0x1336;
    case 9:
      return 0x1337;
    }
  }
  return 0;
}



// ?ToBeDeleted@Spell@@UAEXH@Z @ 0x006b7050

void _ToBeDeleted_Spell__UAEXH_Z(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *in_ECX;
  
  iVar3 = DAT_00c22ca4;
  piVar1 = *(int **)(DAT_00c22ca4 + 0x201c80);
  if (piVar1 == in_ECX) {
    *(int *)(DAT_00c22ca4 + 0x201c80) = in_ECX[0x3a];
  }
  else {
    do {
      piVar2 = piVar1;
      if (piVar2 == (int *)0x0) goto LAB_006b709d;
      piVar1 = (int *)piVar2[0x3a];
    } while ((int *)piVar2[0x3a] != in_ECX);
    piVar2[0x3a] = in_ECX[0x3a];
  }
  *(int *)(iVar3 + 0x201c84) = *(int *)(iVar3 + 0x201c84) + -1;
  in_ECX[0x3a] = 0;
LAB_006b709d:
  if ((int *)in_ECX[0x2c] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x2c] + 4))(1);
    in_ECX[0x2c] = 0;
  }
  if (in_ECX[10] != 0) {
    FUN_0067f9a0();
  }
  if ((int *)in_ECX[0x2b] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x2b] + 0xc))(0);
  }
  FUN_006b8560();
  (**(code **)(*in_ECX + 0x530))();
  FUN_00724350();
  _ToBeDeleted_GameThingWithPos__UAEXH_Z(param_1);
  return;
}



// ?InitWithPos@Spell@@UAEHPAVGameThing@@ABUMapCoords@@PAVSpellCastData@@ABUPSysProcessInfo@@@Z @ 0x006b7110

undefined4
_InitWithPos_Spell__UAEHPAVGameThing__ABUMapCoords__PAVSpellCastData__ABUPSysProcessInfo___Z
          (undefined4 param_1,int *param_2,int *param_3)

{
  int iVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *in_ECX;
  int iVar6;
  int *piVar7;
  float10 fVar8;
  undefined4 uStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined1 uStack_c;
  undefined4 uStack_8;
  
  FUN_006b8890(param_2);
  in_ECX[0x30] = *param_2;
  in_ECX[0x31] = param_2[1];
  in_ECX[0x32] = param_2[2];
  iVar3 = (**(code **)(*in_ECX + 0x1c))();
  if (iVar3 != 0) {
    iVar3 = in_ECX[0x2d];
    (**(code **)(*in_ECX + 0x1c))();
    FUN_00539e70(iVar3);
  }
  FUN_006b81a0(param_3[1]);
  (**(code **)(*in_ECX + 0x54c))(param_3[3]);
  in_ECX[0x14] = param_3[2];
  fVar2 = (float)param_2[2];
  fVar8 = (float10)FUN_00760fd0();
  iVar3 = *param_2;
  iVar1 = param_2[1];
  in_ECX[5] = *param_2;
  in_ECX[6] = param_2[1];
  in_ECX[7] = param_2[2];
  in_ECX[0x33] = *param_2;
  in_ECX[0x34] = param_2[1];
  in_ECX[0x35] = param_2[2];
  piVar7 = in_ECX + 0x19;
  for (iVar6 = 0xf; iVar6 != 0; iVar6 = iVar6 + -1) {
    *piVar7 = *param_3;
    param_3 = param_3 + 1;
    piVar7 = piVar7 + 1;
  }
  in_ECX[0x36] = in_ECX[0x22];
  in_ECX[0x37] = in_ECX[0x23];
  in_ECX[0x38] = in_ECX[0x24];
  if (param_2 == (int *)0x0) {
    iVar6 = 0x42200000;
  }
  else {
    iVar6 = *param_2;
  }
  in_ECX[0x2f] = iVar6;
  (**(code **)(*in_ECX + 0x504))(&stack0xffffffc8,in_ECX + 0x36,iVar6,1);
  iVar4 = FUN_00636b40();
  iVar6 = in_ECX[0x2d];
  in_ECX[0x2c] = iVar4;
  uVar5 = *(undefined4 *)(DAT_00c22ca4 + 0x201afc);
  iVar4 = (**(code **)(*in_ECX + 0x1c))();
  *(int *)(iVar4 + 0xe8) = iVar6;
  *(int *)(iVar4 + 0xdc) = in_ECX[0x33];
  *(int *)(iVar4 + 0xe0) = in_ECX[0x34];
  *(int *)(iVar4 + 0xe4) = in_ECX[0x35];
  *(undefined4 *)(iVar4 + 0xec) = uVar5;
  if ((int *)in_ECX[0x2c] == (int *)0x0) {
    iVar6 = FUN_006c4230();
    if (*(int *)(iVar6 + 0x20) != 0) {
      return 0;
    }
    uStack_2c = 0xb;
    uStack_1c = 0;
    uStack_18 = 0;
    uStack_14 = 0;
    uStack_10 = 0x3f800000;
    uStack_c = 0;
    uStack_8 = 0;
    fStack_28 = (float)iVar3 * 0.00015258789;
    fStack_24 = (float)(fVar8 + (float10)fVar2);
    fStack_20 = (float)iVar1 * 0.00015258789;
    (**(code **)(*in_ECX + 0x52c))(&uStack_2c);
  }
  else {
    iVar3 = *(int *)in_ECX[0x2c];
    uVar5 = (**(code **)(*in_ECX + 0x1c))();
    (**(code **)(iVar3 + 0x20))(uVar5);
  }
  iVar3 = FUN_006b7980();
  if ((*(int *)(iVar3 + 0x8c) != 0) && (in_ECX[10] == 0)) {
    iVar3 = FUN_006b7980();
    if (*(int *)(iVar3 + 0x94) != -1) {
      uVar5 = (**(code **)(*in_ECX + 0x1c))(1);
      FUN_006b7980(uVar5);
      iVar3 = FUN_0067efc0();
      in_ECX[10] = iVar3;
    }
  }
  if (*(int *)(DAT_00c22ca4 + 0x201ae4) == 1) {
    FUN_00724420();
  }
  return 1;
}



// ?InitWithObject@Spell@@UAEHPAVGameThing@@PAVObject@@PAVSpellCastData@@ABUPSysProcessInfo@@@Z @ 0x006b73a0

int _InitWithObject_Spell__UAEHPAVGameThing__PAVObject__PAVSpellCastData__ABUPSysProcessInfo___Z
              (undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x534))(param_1,param_2 + 0x14,param_3,param_4);
  if ((iVar1 == 1) && ((int *)in_ECX[0x2c] != (int *)0x0)) {
    (**(code **)(*(int *)in_ECX[0x2c] + 0x114))(param_2);
  }
  return iVar1;
}



// ?GetParticleType@Spell@@UAEXXZ @ 0x006b73f0

undefined4 _GetParticleType_Spell__UAEXXZ(void)

{
  int iVar1;
  
  iVar1 = FUN_006c4230();
  return *(undefined4 *)(iVar1 + 0x20);
}



// ?GetWorshipSite@Spell@@UAEPAVWorshipSite@@XZ @ 0x006b74c0

undefined4 _GetWorshipSite_Spell__UAEPAVWorshipSite__XZ(void)

{
  int *piVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0xa0) != (int *)0x0) {
    piVar1 = (int *)(**(code **)(**(int **)(in_ECX + 0xa0) + 0xb8))();
    if (piVar1 != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x006b74da. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      uVar2 = (**(code **)(*piVar1 + 0x30c))();
      return uVar2;
    }
  }
  return 0;
}



// ?GetImpressiveType@Spell@@UAE?AW4IMPRESSIVE_TYPE@@XZ @ 0x006b7520

undefined4 _GetImpressiveType_Spell__UAE_AW4IMPRESSIVE_TYPE__XZ(void)

{
  int iVar1;
  
  iVar1 = FUN_006c4230();
  return *(undefined4 *)(iVar1 + 0x24);
}



// ?Draw@Spell@@UAEXXZ @ 0x006b7690

void _Draw_Spell__UAEXXZ(void)

{
  int *in_ECX;
  
  if ((int *)in_ECX[0x2c] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x2c] + 0x108))(1);
  }
  (**(code **)(*in_ECX + 0x508))();
  return;
}



// ?Process@Spell@@UAEIXZ @ 0x006b7960

int _Process_Spell__UAEIXZ(void)

{
  int in_ECX;
  
  FUN_006b78b0();
  return (-(uint)(*(int *)(in_ECX + 0xb0) != 0) & 0xfffffffc) + 5;
}



// ?CalculateCostToMaintain@Spell@@UAEMXZ @ 0x006b7a60

float10 _CalculateCostToMaintain_Spell__UAEMXZ(void)

{
  int iVar1;
  
  iVar1 = FUN_006b7980();
  return (float10)*(float *)(iVar1 + 0x80);
}



// ?SpellEvent@Spell@@UAEXABVSpellEventInfo@@@Z @ 0x006b8180

undefined4 _SpellEvent_Spell__UAEXABVSpellEventInfo___Z(int *param_1)

{
  undefined4 uVar1;
  
  if ((*param_1 != 1) && (*param_1 != 0xb)) {
    uVar1 = FUN_006b7e70(param_1);
    return uVar1;
  }
  return 1;
}



// ?DrawSpellSeed@Spell@@UAEXXZ @ 0x006b8510

void _DrawSpellSeed_Spell__UAEXXZ(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0xac) != 0) {
    FUN_006bfa70();
    return;
  }
  return;
}



// ?ProcessSpellSeed@Spell@@UAEXXZ @ 0x006b8520

undefined4 _ProcessSpellSeed_Spell__UAEXXZ(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0xac) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(in_ECX + 0xac) + 0x2c))();
    if (iVar1 != 0) {
      uVar2 = FUN_006bf9c0();
      return uVar2;
    }
  }
  *(undefined4 *)(in_ECX + 0xac) = 0;
  return 1;
}



// ?NeedsContinualPackets@Spell@@UAE_NPAVGInterfaceStatus@@@Z @ 0x006b8670

undefined4 _NeedsContinualPackets_Spell__UAE_NPAVGInterfaceStatus___Z(int *param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  iVar1 = FUN_006b86c0();
  if ((iVar1 != 0) && (in_ECX[0x10] == 0)) {
    iVar1 = FUN_006b74b0();
    if (iVar1 != 0) {
      iVar1 = (**(code **)(*param_1 + 0x1c))();
      iVar2 = (**(code **)(*in_ECX + 0x1c))();
      if (iVar1 == iVar2) {
        return 1;
      }
    }
  }
  return 0;
}



// ?GetImpressiveValue@Spell@@UAEMPAVLiving@@PAVReaction@@@Z @ 0x006b87b0

float10 _GetImpressiveValue_Spell__UAEMPAVLiving__PAVReaction___Z(int param_1,undefined4 param_2)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int *in_ECX;
  float10 fVar4;
  float10 fVar5;
  float10 fVar6;
  float10 fVar7;
  
  fVar2 = DAT_00c3b398;
  fVar4 = (float10)FUN_0067fac0(param_1);
  iVar3 = FUN_006b7980();
  fVar1 = *(float *)(iVar3 + 0xc4);
  fVar5 = (float10)FUN_006de0a0(param_1 + 0x14,in_ECX + 5);
  iVar3 = FUN_0067f950();
  fVar5 = (float10)FUN_00431440((float)fVar5,*(undefined4 *)(iVar3 + 0x2c));
  fVar6 = (float10)(**(code **)(*in_ECX + 0x128))();
  fVar7 = (float10)FUN_0053eb20(param_2);
  return fVar7 * (float10)(float)fVar6 * (float10)(float)fVar5 *
         (float10)((float)fVar4 * fVar1 * fVar2);
}



// ?GetQueryFirstEnumText@Spell@@UAE?AW4HELP_TEXT@@XZ @ 0x006b8960

undefined4 _GetQueryFirstEnumText_Spell__UAE_AW4HELP_TEXT__XZ(void)

{
  int iVar1;
  
  iVar1 = FUN_006b7980();
  return *(undefined4 *)(iVar1 + 0xf8);
}



// ?GetQueryLastEnumText@Spell@@UAE?AW4HELP_TEXT@@XZ @ 0x006b8970

undefined4 _GetQueryLastEnumText_Spell__UAE_AW4HELP_TEXT__XZ(void)

{
  int iVar1;
  
  iVar1 = FUN_006b7980();
  return *(undefined4 *)(iVar1 + 0xfc);
}



// ?GetFOVHelpMessageSet@Spell@@UAEIXZ @ 0x006b8980

undefined4 _GetFOVHelpMessageSet_Spell__UAEIXZ(void)

{
  int iVar1;
  
  iVar1 = FUN_006b7980();
  return *(undefined4 *)(iVar1 + 0x108);
}



// ?GetFOVHelpCondition@Spell@@UAEIXZ @ 0x006b8990

undefined4 _GetFOVHelpCondition_Spell__UAEIXZ(void)

{
  int iVar1;
  
  iVar1 = FUN_006b7980();
  return *(undefined4 *)(iVar1 + 0x10c);
}



// ?Save@Spell@@UAEIAAVGameOSFile@@@Z @ 0x006b89f0

undefined4 _Save_Spell__UAEIAAVGameOSFile___Z(uint param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = param_1;
  iVar2 = _Save_GameThingWithPos__UAEXPAUGameOSFile___Z(param_1);
  if (iVar2 != 0) {
    param_1 = 0x12c859;
    if (DAT_00b19ac8 != 0) {
      iVar2 = FUN_0072be90(&param_1,4,0);
      if (iVar2 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + (param_1 & 0xff) + 4;
    }
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0xb0));
    param_1 = 0x2a1c9a;
    if (DAT_00b19ac8 != 0) {
      iVar2 = FUN_0072be90(&param_1,4,0);
      if (iVar2 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + (param_1 & 0xff) + 4;
    }
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x28));
    if (DAT_00b19ac8 != 0) {
      iVar2 = FUN_0072be90((byte *)(in_ECX + 0x2c),0xc,0);
      if (iVar2 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x2c) + 0xc;
      if (DAT_00b19ac8 != 0) {
        iVar2 = FUN_0072be90((byte *)(in_ECX + 0xcc),0xc,0);
        if (iVar2 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0xcc) + 0xc;
        if (DAT_00b19ac8 != 0) {
          iVar2 = FUN_0072be90((byte *)(in_ECX + 0xd8),0xc,0);
          if (iVar2 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0xd8) + 0xc;
          if (DAT_00b19ac8 != 0) {
            iVar2 = FUN_0072be90((byte *)(in_ECX + 0x38),4,0);
            if (iVar2 == 3) {
              DAT_00b19ac8 = 0;
            }
            *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x38) + 4;
            if (DAT_00b19ac8 != 0) {
              iVar2 = FUN_0072be90((byte *)(in_ECX + 0x3c),4,0);
              if (iVar2 == 3) {
                DAT_00b19ac8 = 0;
              }
              *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x3c) + 4;
              if (DAT_00b19ac8 != 0) {
                iVar2 = FUN_0072be90((byte *)(in_ECX + 0x40),4,0);
                if (iVar2 == 3) {
                  DAT_00b19ac8 = 0;
                }
                *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x40) + 4;
                if (DAT_00b19ac8 != 0) {
                  iVar2 = FUN_0072be90((byte *)(in_ECX + 0x44),4,0);
                  if (iVar2 == 3) {
                    DAT_00b19ac8 = 0;
                  }
                  *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x44) + 4;
                  if (DAT_00b19ac8 != 0) {
                    iVar2 = FUN_0072be90((byte *)(in_ECX + 0x48),4,0);
                    if (iVar2 == 3) {
                      DAT_00b19ac8 = 0;
                    }
                    *(uint *)(iVar1 + 0x214) =
                         *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x48) + 4;
                    if (DAT_00b19ac8 != 0) {
                      iVar2 = FUN_0072be90((byte *)(in_ECX + 0x4c),4,0);
                      if (iVar2 == 3) {
                        DAT_00b19ac8 = 0;
                      }
                      *(uint *)(iVar1 + 0x214) =
                           *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x4c) + 4;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
    FUN_006b9130(in_ECX + 100);
    FUN_0066ee00(in_ECX + 0x50);
    FUN_00604120(in_ECX + 0x5c);
    FUN_00604120(in_ECX + 0x5d);
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0xa0));
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0xa4));
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0xa8));
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0xac));
    FUN_0066ee00(in_ECX + 0xb4);
    FUN_0066ee00(in_ECX + 0xb8);
    FUN_0066ee00(in_ECX + 0xbc);
    FUN_0066ee00(in_ECX + 0xe4);
    FUN_004ebf70(in_ECX + 0xc0);
    FUN_0066ee00(in_ECX + 0x54);
    FUN_0066ee00(in_ECX + 0x58);
    return 1;
  }
  return 0;
}



// ?Load@Spell@@UAEIAAVGameOSFile@@@Z @ 0x006b8d90

undefined4 _Load_Spell__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  uint in_stack_00005d15;
  uint in_stack_0000ba26;
  
  iVar1 = _Load_GameThingWithPos__QAEIAAVGameOSFile___Z();
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (in_stack_00005d15 & 0xff) + 4;
    }
    FUN_00531f30();
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (in_stack_0000ba26 & 0xff) + 4;
    }
    FUN_00531f30();
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x2c) + 0xc;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xcc) + 0xc;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xd8) + 0xc;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x38) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x3c) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x40) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x44) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x48) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x4c) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 100) + 0x3c;
    }
    FUN_00589540();
    FUN_00604170();
    FUN_00604170();
    FUN_00531f30();
    FUN_00531f30();
    FUN_00531f30();
    FUN_00531f30();
    FUN_00589540();
    FUN_00589540();
    FUN_00589540();
    FUN_00589540();
    FUN_004ec100();
    FUN_00589540();
    FUN_00589540();
    return 1;
  }
  return 0;
}



// ?AdjustSpellSeedPos@Spell@@UAEXPAUMapCoords@@@Z @ 0x006ba160

float10 _AdjustSpellSeedPos_Spell__UAEXPAUMapCoords___Z(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_006b7980();
  return (float10)*(uint *)(in_ECX + 0xf0) * (float10)*(float *)(iVar1 + 0x7c) +
         (float10)*(float *)(iVar1 + 0x80);
}



// ?InitWithObject@Spell@@UAEHPAVGameThing@@PAVObject@@PAVSpellCastData@@ABUPSysProcessInfo@@@Z @ 0x006ba980

undefined4
_InitWithObject_Spell__UAEHPAVGameThing__PAVObject__PAVSpellCastData__ABUPSysProcessInfo___Z
          (undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4)

{
  float fVar1;
  float fVar2;
  float fVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  undefined4 uVar7;
  int *in_ECX;
  float10 fVar8;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  FUN_006c4230();
  uVar4 = _InitWithPos_SpellFlock__UAEHPAVGameThing__ABUMapCoords__PAVSpellCastData__ABUPSysProcessInfo___Z
                    (param_1,param_2,param_3,param_4);
  iVar5 = (**(code **)(*in_ECX + 0x1c))();
  fVar2 = *(float *)(*(int *)(iVar5 + 0x60) + 8);
  iVar5 = FUN_006c4230();
  fVar1 = *(float *)(iVar5 + 0x5c);
  iVar5 = FUN_006b7470();
  if (iVar5 != 0) {
    fVar3 = (float)param_2[2];
    fVar8 = (float10)FUN_00760fd0();
    fStack_8 = (float)(fVar8 + (float10)fVar3);
    fStack_c = (float)*param_2 * 0.00015258789;
    uStack_18 = 0;
    fStack_4 = (float)param_2[1] * 0.00015258789;
    uStack_14 = 0;
    uStack_10 = 0;
    piVar6 = (int *)FUN_00637520(0,(fVar2 < fVar1) + 'z',&fStack_c,&uStack_18,0x3f800000,0);
    in_ECX[0x44] = (int)piVar6;
    if (piVar6 != (int *)0x0) {
      iVar5 = *piVar6;
      uVar7 = (**(code **)(*in_ECX + 0x1c))();
      (**(code **)(iVar5 + 0x20))(uVar7);
    }
  }
  return uVar4;
}



// ?InitWithObject@Spell@@UAEHPAVGameThing@@PAVObject@@PAVSpellCastData@@ABUPSysProcessInfo@@@Z @ 0x006bb120

undefined4
_InitWithObject_Spell__UAEHPAVGameThing__PAVObject__PAVSpellCastData__ABUPSysProcessInfo___Z
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = _InitWithPos_SpellFlock__UAEHPAVGameThing__ABUMapCoords__PAVSpellCastData__ABUPSysProcessInfo___Z
                    (param_1,param_2,param_3,param_4);
  FUN_006c4230();
  return uVar1;
}



