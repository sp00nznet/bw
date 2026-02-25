// Decompiled functions for class: Dove
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetScriptObjectType@Dove@@UAEIXZ @ 0x004181b0

undefined4 _GetScriptObjectType_Dove__UAEIXZ(void)

{
  return 0x15;
}



// ?GetSaveType@Dove@@UAEIXZ @ 0x004190b0

undefined4 _GetSaveType_Dove__UAEIXZ(void)

{
  return 0x8e;
}



// ?GetDebugText@Dove@@UAEPADXZ @ 0x004190c0

char * _GetDebugText_Dove__UAEPADXZ(void)

{
  return s_Animal__Dove_008f7f2c;
}



// ?Save@Dove@@UAEIAAVGameOSFile@@@Z @ 0x0041a1e0

bool _Save_Dove__UAEIAAVGameOSFile___Z(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _Save_Animal__UAEIAAVGameOSFile___Z(param_1);
  return iVar1 != 0;
}



// ?Load@Dove@@UAEIAAVGameOSFile@@@Z @ 0x0041a200

bool _Load_Dove__UAEIAAVGameOSFile___Z(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _Load_Animal__UAEIAAVGameOSFile___Z(param_1);
  return iVar1 != 0;
}



// ?CanBeStompedOnByCreature@Dove@@UAEIPAVCreature@@@Z @ 0x0041a220

undefined4 _CanBeStompedOnByCreature_Dove__UAEIPAVCreature___Z(int *param_1)

{
  float fVar1;
  int in_ECX;
  float10 fVar2;
  
  fVar1 = *(float *)(in_ECX + 0x1c);
  fVar2 = (float10)(**(code **)(*param_1 + 0x42c))();
  if ((float10)fVar1 < fVar2 * (float10)0.25) {
    return 1;
  }
  return 0;
}



// ?CanBePickedUpByCreature@Dove@@UAEIPAVCreature@@@Z @ 0x0041a260

undefined4 _CanBePickedUpByCreature_Dove__UAEIPAVCreature___Z(void)

{
  int in_ECX;
  
  if (*(float *)(in_ECX + 0x1c) < 1.0) {
    return 1;
  }
  return 0;
}



// ?CallVirtualFunctionsForCreation@Dove@@UAEXABUMapCoords@@@Z @ 0x0041a310

void _CallVirtualFunctionsForCreation_Dove__UAEXABUMapCoords___Z(undefined4 param_1)

{
  int in_ECX;
  
  _CallVirtualFunctionsForCreation_Animal__UAEXABUMapCoords___Z(param_1);
  if (*(int **)(in_ECX + 0x40) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x40) + 0x40))();
  }
  return;
}



// ?Draw@Dove@@UAEXXZ @ 0x0041a740

void _Draw_Dove__UAEXXZ(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float *pfVar4;
  int *in_ECX;
  int iVar5;
  int iVar6;
  float *pfVar7;
  float *pfVar8;
  float10 fVar9;
  float afStack_30 [12];
  
  fVar1 = (float)DAT_00dc8d20 * 0.001 + (float)in_ECX[0x49];
  in_ECX[0x49] = (int)fVar1;
  if (fVar1 < (float)in_ECX[0x4a]) {
    fVar2 = fVar1 * fVar1 * 0.5;
    fVar3 = fVar1 * fVar2 * 0.33333334;
    in_ECX[0x47] = (int)(fVar1 * (float)in_ECX[0x4d] +
                         fVar3 * (float)in_ECX[0x4f] + fVar2 * (float)in_ECX[0x4e] +
                        (float)in_ECX[0x4c]);
    in_ECX[0x44] = (int)((float)in_ECX[0x4c] * (float)in_ECX[0x49] +
                         fVar2 * (float)in_ECX[0x4d] +
                         fVar3 * (float)in_ECX[0x4e] +
                         fVar2 * fVar2 * 0.16666667 * (float)in_ECX[0x4f] + (float)in_ECX[0x4b]);
  }
  else {
    in_ECX[0x44] = in_ECX[0x45];
    in_ECX[0x47] = in_ECX[0x46];
    in_ECX[0x48] = 0;
    in_ECX[0x49] = in_ECX[0x4a];
  }
  *(undefined4 *)(in_ECX[0x10] + 0x4c) = DAT_00df8aa8;
  fVar9 = (float10)(**(code **)(*in_ECX + 0x120))();
  FUN_004f7510((float)fVar9);
  fVar1 = (float)in_ECX[0x44];
  iVar6 = in_ECX[0x10];
  fVar9 = (float10)fcos((float10)fVar1);
  pfVar4 = (float *)(iVar6 + 0x14);
  pfVar7 = pfVar4;
  pfVar8 = afStack_30;
  for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
    *pfVar8 = *pfVar7;
    pfVar7 = pfVar7 + 1;
    pfVar8 = pfVar8 + 1;
  }
  fVar2 = (float)fVar9;
  fVar9 = (float10)fsin((float10)fVar1);
  fVar1 = *pfVar4;
  *pfVar4 = (float)((float10)fVar2 * (float10)*pfVar4 - fVar9 * (float10)*(float *)(iVar6 + 0x20));
  *(float *)(iVar6 + 0x20) =
       (float)((float10)fVar2 * (float10)*(float *)(iVar6 + 0x20) + fVar9 * (float10)fVar1);
  fVar1 = *(float *)(iVar6 + 0x18);
  *(float *)(iVar6 + 0x18) =
       (float)((float10)fVar2 * (float10)*(float *)(iVar6 + 0x18) -
              fVar9 * (float10)*(float *)(iVar6 + 0x24));
  *(float *)(iVar6 + 0x24) =
       (float)((float10)fVar2 * (float10)*(float *)(iVar6 + 0x24) + fVar9 * (float10)fVar1);
  fVar1 = *(float *)(iVar6 + 0x1c);
  *(float *)(iVar6 + 0x1c) =
       (float)((float10)fVar2 * (float10)*(float *)(iVar6 + 0x1c) -
              fVar9 * (float10)*(float *)(iVar6 + 0x28));
  *(float *)(iVar6 + 0x28) = fVar2 * *(float *)(iVar6 + 0x28) + (float)(fVar9 * (float10)fVar1);
  *(uint *)(in_ECX[0x10] + 8) = *(uint *)(in_ECX[0x10] + 8) | 0x20;
  (**(code **)(*(int *)in_ECX[0x10] + 0x100))();
  pfVar7 = afStack_30;
  pfVar8 = (float *)(in_ECX[0x10] + 0x14);
  for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
    *pfVar8 = *pfVar7;
    pfVar7 = pfVar7 + 1;
    pfVar8 = pfVar8 + 1;
  }
  _Draw_PlannedMultiMapFixed__QAEXXZ();
  return;
}



// ?GetHowMuchCreatureWantsToLookAtMe@Dove@@UAEMXZ @ 0x004b5320

float10 _GetHowMuchCreatureWantsToLookAtMe_Dove__UAEMXZ(void)

{
  return (float10)0.9;
}



