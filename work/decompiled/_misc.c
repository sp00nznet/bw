// Decompiled functions for class: _misc
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// Feature_vf547 @ 0x00401420

undefined4 Feature_vf547(void)

{
  int *in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 0x884))();
  if ((float10)1.0 <= fVar1) {
    return 1;
  }
  return 0;
}



// Creche_vf406 @ 0x00401f80

void Creche_vf406(float param_1)

{
  float *pfVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int *in_ECX;
  float10 fVar9;
  float10 fVar10;
  undefined4 local_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  _CallVirtualFunctionsForCreation_MultiMapFixed__UAEXABUMapCoords___Z(param_1);
  iVar7 = (**(code **)(*(int *)in_ECX[0x10] + 0x1c0))();
  if (iVar7 != 0) {
    puVar8 = (undefined4 *)FUN_00757420(0);
    in_ECX[0x23] = (int)puVar8;
    if (puVar8 != (undefined4 *)0x0) {
      *puVar8 = local_c;
      puVar8[1] = uStack_8;
      puVar8[2] = uStack_4;
      iVar7 = (**(code **)(*in_ECX + 0x310))();
      if (iVar7 != 0) {
        *(undefined ***)(in_ECX[0x23] + 0x10c) = &PTR__GetDebugText_GBaseInfo__UBEPBDXZ_00808080;
      }
    }
  }
  iVar7 = (**(code **)(*(int *)in_ECX[0x10] + 500))();
  if (iVar7 == 0) {
    fVar9 = (float10)(**(code **)(*in_ECX + 100))();
    if ((float10)-0.8 <= -(fVar9 * (float10)0.2)) {
      param_1 = -0.8;
    }
    else {
      fVar9 = (float10)(**(code **)(*in_ECX + 100))();
      param_1 = (float)-(fVar9 * (float10)0.2);
    }
    fVar9 = (float10)FUN_005ecda0();
    if (fVar9 <= (float10)param_1) {
      fVar9 = (float10)param_1;
    }
    else {
      fVar9 = (float10)FUN_005ecda0();
    }
    in_ECX[7] = (int)(float)fVar9;
  }
  fVar9 = (float10)(**(code **)(*in_ECX + 0x120))();
  fVar3 = (float)fVar9;
  fVar9 = (float10)(**(code **)(*in_ECX + 0x508))();
  fVar4 = (float)fVar9;
  fVar5 = (float)in_ECX[7];
  iVar6 = in_ECX[0x10];
  fVar9 = (float10)FUN_00760fd0();
  iVar7 = in_ECX[5];
  iVar2 = in_ECX[6];
  if (fVar4 == 0.0) {
    if (fVar3 == 1.0) {
      FUN_004022b0();
    }
    else {
      *(float *)(iVar6 + 0x34) = fVar3;
      *(float *)(iVar6 + 0x14) = fVar3;
      *(undefined4 *)(iVar6 + 0x40) = 0;
      *(undefined4 *)(iVar6 + 0x3c) = 0;
      *(undefined4 *)(iVar6 + 0x38) = 0;
      *(undefined4 *)(iVar6 + 0x30) = 0;
      *(undefined4 *)(iVar6 + 0x2c) = 0;
      *(undefined4 *)(iVar6 + 0x28) = 0;
      *(undefined4 *)(iVar6 + 0x20) = 0;
      *(undefined4 *)(iVar6 + 0x1c) = 0;
      *(undefined4 *)(iVar6 + 0x18) = 0;
      *(float *)(iVar6 + 0x24) = fVar3;
      FUN_004022f0();
    }
  }
  else if (fVar3 == 1.0) {
    pfVar1 = (float *)(iVar6 + 0x14);
    FUN_00402280();
    fVar10 = (float10)fcos((float10)fVar4);
    *(float *)(iVar6 + 0x38) = (float)iVar7 * 0.00015258789;
    *(float *)(iVar6 + 0x3c) = (float)(fVar9 + (float10)fVar5);
    *(float *)(iVar6 + 0x40) = (float)iVar2 * 0.00015258789;
    fVar9 = (float10)fsin((float10)fVar4);
    fVar5 = *pfVar1;
    *pfVar1 = (float)(fVar10 * (float10)*pfVar1 + fVar9 * (float10)*(float *)(iVar6 + 0x2c));
    *(float *)(iVar6 + 0x2c) =
         (float)(fVar10 * (float10)*(float *)(iVar6 + 0x2c) - fVar9 * (float10)fVar5);
    fVar5 = *(float *)(iVar6 + 0x18);
    *(float *)(iVar6 + 0x18) =
         (float)(fVar9 * (float10)*(float *)(iVar6 + 0x30) +
                fVar10 * (float10)*(float *)(iVar6 + 0x18));
    *(float *)(iVar6 + 0x30) =
         (float)(fVar10 * (float10)*(float *)(iVar6 + 0x30) - fVar9 * (float10)fVar5);
    fVar5 = *(float *)(iVar6 + 0x1c);
    *(float *)(iVar6 + 0x1c) =
         (float)(fVar9 * (float10)*(float *)(iVar6 + 0x34) +
                fVar10 * (float10)*(float *)(iVar6 + 0x1c));
    *(float *)(iVar6 + 0x34) =
         (float)(fVar10 * (float10)*(float *)(iVar6 + 0x34) -
                (float10)(float)(fVar9 * (float10)fVar5));
  }
  else {
    *(undefined4 *)(iVar6 + 0x40) = 0;
    *(undefined4 *)(iVar6 + 0x3c) = 0;
    *(undefined4 *)(iVar6 + 0x38) = 0;
    *(undefined4 *)(iVar6 + 0x30) = 0;
    *(undefined4 *)(iVar6 + 0x2c) = 0;
    *(undefined4 *)(iVar6 + 0x28) = 0;
    *(undefined4 *)(iVar6 + 0x20) = 0;
    *(undefined4 *)(iVar6 + 0x1c) = 0;
    *(undefined4 *)(iVar6 + 0x18) = 0;
    *(float *)(iVar6 + 0x34) = fVar3;
    *(float *)(iVar6 + 0x24) = fVar3;
    *(float *)(iVar6 + 0x14) = fVar3;
    *(float *)(iVar6 + 0x38) = (float)iVar7 * 0.00015258789 + *(float *)(iVar6 + 0x38);
    *(float *)(iVar6 + 0x3c) = (float)(fVar9 + (float10)fVar5) + *(float *)(iVar6 + 0x3c);
    *(float *)(iVar6 + 0x40) = (float)iVar2 * 0.00015258789 + *(float *)(iVar6 + 0x40);
    fVar9 = (float10)fcos((float10)fVar4);
    fVar10 = (float10)fsin((float10)fVar4);
    fVar5 = *(float *)(iVar6 + 0x14);
    *(float *)(iVar6 + 0x14) =
         (float)(fVar9 * (float10)*(float *)(iVar6 + 0x14) +
                fVar10 * (float10)*(float *)(iVar6 + 0x2c));
    *(float *)(iVar6 + 0x2c) =
         (float)(fVar9 * (float10)*(float *)(iVar6 + 0x2c) - fVar10 * (float10)fVar5);
    fVar5 = *(float *)(iVar6 + 0x18);
    *(float *)(iVar6 + 0x18) =
         (float)(fVar9 * (float10)*(float *)(iVar6 + 0x18) +
                fVar10 * (float10)*(float *)(iVar6 + 0x30));
    *(float *)(iVar6 + 0x30) =
         (float)(fVar9 * (float10)*(float *)(iVar6 + 0x30) - fVar10 * (float10)fVar5);
    fVar5 = *(float *)(iVar6 + 0x1c);
    *(float *)(iVar6 + 0x1c) =
         (float)(fVar9 * (float10)*(float *)(iVar6 + 0x1c) +
                fVar10 * (float10)*(float *)(iVar6 + 0x34));
    *(float *)(iVar6 + 0x34) =
         (float)(fVar9 * (float10)*(float *)(iVar6 + 0x34) -
                (float10)(float)(fVar10 * (float10)fVar5));
  }
  *(float *)(iVar6 + 0x44) = fVar3;
  *(float *)(iVar6 + 0x48) = fVar4;
  return;
}



// ??_GCreche@@UAEPAXI@Z @ 0x00403fc0

void ___GCreche__UAEPAXI_Z(byte param_1)

{
  FUN_004018f0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// StoragePit_vf523 @ 0x00404250

int StoragePit_vf523(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int *in_ECX;
  char *pcVar8;
  undefined4 uVar9;
  undefined1 local_264 [4];
  char acStack_260 [200];
  undefined1 auStack_198 [200];
  undefined1 auStack_d0 [204];
  undefined4 uStack_4;
  
  iVar2 = FUN_0053eb80();
  if (iVar2 == 0) {
    return 0;
  }
  if (param_2 != 0) {
    FUN_005c13b0(local_264,param_2);
  }
  iVar3 = (**(code **)(*in_ECX + 0x48))();
  if ((iVar3 == 0) || (param_2 != 0)) {
    uVar7 = 0xffffffff;
  }
  else {
    iVar3 = (**(code **)(*in_ECX + 0x48))();
    uVar7 = *(undefined4 *)(iVar3 + 0x5b4);
  }
  if ((*(byte *)(in_ECX + 0x16) & 2) == 0) {
    (**(code **)(*in_ECX + 0x120))();
    (**(code **)(*in_ECX + 0x508))();
    uVar4 = (**(code **)(*in_ECX + 0x98))(1);
    uVar4 = (**(code **)(*in_ECX + 0x98))(0,uVar4);
    uVar4 = __ftol(uVar4);
    uVar4 = __ftol(uVar4);
    uVar5 = FUN_00404210(auStack_198);
    uVar6 = FUN_005bf290(auStack_d0);
    uVar9 = 7;
  }
  else {
    (**(code **)(*in_ECX + 0x120))();
    (**(code **)(*in_ECX + 0x508))();
    uVar4 = (**(code **)(*in_ECX + 0x98))(1);
    uVar4 = (**(code **)(*in_ECX + 0x98))(0,uVar4);
    uVar4 = __ftol(uVar4);
    uVar4 = __ftol(uVar4);
    uVar5 = FUN_00404210(auStack_198);
    uVar6 = FUN_005bf290(auStack_d0);
    uVar9 = 8;
  }
  uVar7 = FUN_006ad590(uVar9,uVar7,uVar6,uVar5,uVar4);
  FUN_00733e17(acStack_260,uVar7);
  iVar3 = -1;
  pcVar8 = acStack_260;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  FUN_006b10c0();
  _SaveObject_MultiMapFixed__UAEIPAVLHOSFile__PBUMapCoords___Z(uStack_4,param_2);
  return iVar2;
}



// StoragePit_vf538 @ 0x004058b0

float10 StoragePit_vf538(void)

{
  int in_ECX;
  float10 fVar1;
  float10 fVar2;
  
  fVar1 = (float10)_GetInfluence_MultiMapFixed__UAEMXZ();
  fVar2 = (float10)FUN_00405730();
  return (fVar2 + (float10)*(byte *)(in_ECX + 0xb7) + (float10)1.0) * (float10)(float)fVar1;
}



// EditorIconBase_vf5 @ 0x00412770

void EditorIconBase_vf5(void)

{
  undefined4 *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00412772. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)*in_ECX)();
  return;
}



// EditorIconBase_vf7 @ 0x00412780

undefined4 EditorIconBase_vf7(void)

{
  return DAT_00be76f0;
}



// ?$EditorIconSlider@M_vf3 @ 0x004127b0

undefined4 __EditorIconSlider_M_vf3(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x30);
}



// EditorIconShow_vf0 @ 0x004127c0

int EditorIconShow_vf0(void)

{
  int in_ECX;
  
  return in_ECX + 4;
}



// ?$EditorIconSlider@M_vf2 @ 0x00413120

void __EditorIconSlider_M_vf2(void)

{
  int in_ECX;
  bool bVar1;
  
  bVar1 = DAT_00be76fc == 0;
  __EditorIconButton_VCreatureLessonChooser___vf2(0);
  if ((DAT_00be76fc != 0) && (bVar1)) {
    DAT_00be76fc = 0;
  }
  FUN_004fa070(in_ECX + 0x25c,in_ECX + 0x26c,*(undefined1 *)(in_ECX + 0x26f),0);
  return;
}



// ?$EditorIconSlider@M_vf1 @ 0x00413180

undefined4 __EditorIconSlider_M_vf1(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  undefined4 uVar5;
  float10 fVar6;
  float fStack_8;
  float fStack_4;
  
  uVar5 = 0;
  in_ECX[0xf] = 1;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  iVar2 = (**(code **)(*in_ECX + 0x48))();
  if (iVar2 != 0) {
    if ((DAT_00d5c400 & 1) != 0) {
      in_ECX[0xd] = 1;
      in_ECX[0x9d] = 1;
      fStack_8 = DAT_00d5c370;
      fStack_4 = DAT_00d5c374;
      iVar2 = FUN_007499b0(&fStack_8);
      if (iVar2 == 0) {
        iVar2 = FUN_004fb970();
        fVar1 = DAT_00d5c370;
        if (iVar2 != 0) {
          fVar1 = DAT_00d5c374;
        }
        fStack_4 = DAT_00d5c374;
        fStack_8 = (float)(int)fVar1;
        iVar3 = (**(code **)*in_ECX)();
        iVar2 = *(int *)(iVar3 + 0xc);
        iVar3 = *(int *)(iVar3 + 4);
        piVar4 = (int *)(**(code **)*in_ECX)();
        if ((piVar4[2] - *piVar4) + 1 < (iVar2 - iVar3) + 1) {
          if (in_ECX[0x9d] != 0) goto LAB_004132dd;
          if ((float)in_ECX[0x98] <= fStack_8) {
            iVar2 = in_ECX[0x9a];
LAB_004132bf:
            if (fStack_8 <= (float)iVar2) goto LAB_004132dd;
            fVar6 = (float10)(**(code **)(*in_ECX + 0x4c))();
            fStack_8 = (float)(fVar6 + (float10)(float)in_ECX[0x9c]);
          }
          else {
            fVar6 = (float10)(**(code **)(*in_ECX + 0x4c))();
            fStack_8 = (float)(fVar6 - (float10)(float)in_ECX[0x9c]);
          }
        }
        else {
          if (in_ECX[0x9d] == 0) {
            if ((float)in_ECX[0x97] <= fStack_8) {
              iVar2 = in_ECX[0x99];
              goto LAB_004132bf;
            }
            fVar6 = (float10)(**(code **)(*in_ECX + 0x4c))();
            fStack_8 = (float)(fVar6 - (float10)(float)in_ECX[0x9c]);
            goto LAB_0041333d;
          }
LAB_004132dd:
          fVar6 = (float10)FUN_00413aa0();
          fStack_8 = (float)((float10)fStack_8 - fVar6);
          fVar6 = (float10)FUN_004fb910();
          fVar6 = (float10)fStack_8 / fVar6;
          if ((float10)0.0 <= fVar6) {
            if ((float10)1.0 < fVar6) {
              fVar6 = (float10)1.0;
            }
          }
          else {
            fVar6 = (float10)0.0;
          }
          fStack_8 = (float)(((float10)(float)in_ECX[0x53] - (float10)(float)in_ECX[0x54]) * fVar6 +
                            (float10)(float)in_ECX[0x54]);
        }
LAB_0041333d:
        (**(code **)(*in_ECX + 0x50))(fStack_8);
      }
      else {
        DAT_00d5c400 = DAT_00d5c400 & 0xfe;
        in_ECX[0x9d] = 1;
      }
    }
    uVar5 = 1;
  }
  if (in_ECX[0x9d] == 0) {
    FUN_00413810();
    return uVar5;
  }
  in_ECX[0xd] = 1;
  iVar2 = FUN_004fb970();
  fVar1 = DAT_00d5c370;
  if (iVar2 != 0) {
    fVar1 = DAT_00d5c374;
  }
  fStack_4 = DAT_00d5c374;
  fStack_8 = (float)(int)fVar1;
  iVar2 = FUN_004fb970();
  if (iVar2 == 0) {
    if (in_ECX[0x9d] == 0) {
      if (fStack_8 < (float)in_ECX[0x97]) {
        fVar6 = (float10)(**(code **)(*in_ECX + 0x4c))();
        fStack_8 = (float)(fVar6 - (float10)(float)in_ECX[0x9c]);
        goto LAB_00413495;
      }
      iVar2 = in_ECX[0x99];
      goto LAB_00413417;
    }
  }
  else if (in_ECX[0x9d] == 0) {
    if (fStack_8 < (float)in_ECX[0x98]) {
      fVar6 = (float10)(**(code **)(*in_ECX + 0x4c))();
      fStack_8 = (float)(fVar6 - (float10)(float)in_ECX[0x9c]);
      goto LAB_00413495;
    }
    iVar2 = in_ECX[0x9a];
LAB_00413417:
    if ((float)iVar2 < fStack_8) {
      fVar6 = (float10)(**(code **)(*in_ECX + 0x4c))();
      fStack_8 = (float)(fVar6 + (float10)(float)in_ECX[0x9c]);
      goto LAB_00413495;
    }
  }
  fVar6 = (float10)FUN_00413aa0();
  fStack_8 = (float)((float10)fStack_8 - fVar6);
  fVar6 = (float10)FUN_004fb910();
  fVar6 = (float10)fStack_8 / fVar6;
  if ((float10)0.0 <= fVar6) {
    if ((float10)1.0 < fVar6) {
      fVar6 = (float10)1.0;
    }
  }
  else {
    fVar6 = (float10)0.0;
  }
  fStack_8 = (float)(((float10)(float)in_ECX[0x53] - (float10)(float)in_ECX[0x54]) * fVar6 +
                    (float10)(float)in_ECX[0x54]);
LAB_00413495:
  (**(code **)(*in_ECX + 0x50))(fStack_8);
  in_ECX[0x9d] = DAT_00d5c3b4 & 1;
  return 1;
}



// ??_GGAnimalInfo@@UAEPAXI@Z @ 0x00413c00

void ___GGAnimalInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGAnimalStateTableInfo@@UAEPAXI@Z @ 0x00413ce0

void ___GGAnimalStateTableInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GAnimal@@UAEPAXI@Z @ 0x004140b0

void ___GAnimal__UAEPAXI_Z(byte param_1)

{
  FUN_004143b0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GDove@@UAEPAXI@Z @ 0x004190d0

void ___GDove__UAEPAXI_Z(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &vftable_Dove;
  FUN_004143b0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GSpellDove@@UAEPAXI@Z @ 0x00419e20

void ___GSpellDove__UAEPAXI_Z(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &vftable_Dove;
  FUN_004143b0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GLion@@UAEPAXI@Z @ 0x0041b0b0

void ___GLion__UAEPAXI_Z(byte param_1)

{
  FUN_0041adb0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GSpellWolf@@UAEPAXI@Z @ 0x0041b7c0

void ___GSpellWolf__UAEPAXI_Z(byte param_1)

{
  FUN_0041adb0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GAnimatedStatic@@UAEPAXI@Z @ 0x0041cc90

void ___GAnimatedStatic__UAEPAXI_Z(byte param_1)

{
  FUN_0041d910();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GArenaSpellIcon@@UAEPAXI@Z @ 0x0041f960

void ___GArenaSpellIcon__UAEPAXI_Z(byte param_1)

{
  FUN_0041f980();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GTownArtifact@@UAEPAXI@Z @ 0x00420000

void ___GTownArtifact__UAEPAXI_Z(byte param_1)

{
  FUN_0053e780();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGAudio@@UAEPAXI@Z @ 0x004211d0

void ___GGAudio__UAEPAXI_Z(byte param_1)

{
  int in_ECX;
  
  LH_SamplePlayOptions::~LH_SamplePlayOptions((LH_SamplePlayOptions *)(in_ECX + 0x240));
  FUN_0053e780();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GThingMusicInfo@@UAEPAXI@Z @ 0x004232d0

void ___GThingMusicInfo__UAEPAXI_Z(byte param_1)

{
  FUN_0053e780();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGLeashSelectorInfo@@UAEPAXI@Z @ 0x004251c0

void ___GGLeashSelectorInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGBaseInfo@@UAEPAXI@Z @ 0x00428370

void ___GGBaseInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GLHReleasedOSFile@@UAEPAXI@Z @ 0x00429ab0

void ___GLHReleasedOSFile__UAEPAXI_Z(byte param_1)

{
  FUN_0072bc20();
  if ((param_1 & 1) != 0) {
    FUN_007290de();
  }
  return;
}



// ??_GGMagicHealInfo@@UAEPAXI@Z @ 0x0042f3f0

void ___GGMagicHealInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGMagicForestInfo@@UAEPAXI@Z @ 0x0042f430

void ___GGMagicForestInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGMagicShieldInfo@@UAEPAXI@Z @ 0x0042f470

void ___GGMagicShieldInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGMagicInfo@@UAEPAXI@Z @ 0x0042f490

void ___GGMagicInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGMagicFlockGroundInfo@@UAEPAXI@Z @ 0x0042f4b0

void ___GGMagicFlockGroundInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGMagicCreatureSpellInfo@@UAEPAXI@Z @ 0x0042f4d0

void ___GGMagicCreatureSpellInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGMagicTeleportInfo@@UAEPAXI@Z @ 0x0042f500

void ___GGMagicTeleportInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGMagicRadiusSpellInfo@@UAEPAXI@Z @ 0x0042f520

void ___GGMagicRadiusSpellInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GBall@@UAEPAXI@Z @ 0x0042f710

void ___GBall__UAEPAXI_Z(byte param_1)

{
  FUN_0042f740();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGBeliefInfo@@UAEPAXI@Z @ 0x00430ad0

void ___GGBeliefInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GBigForest@@UAEPAXI@Z @ 0x00431a00

void ___GBigForest__UAEPAXI_Z(byte param_1)

{
  FUN_00431a30();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GBonfire@@UAEPAXI@Z @ 0x00432210

void ___GBonfire__UAEPAXI_Z(byte param_1)

{
  FUN_005c3620();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GBuildingSite@@UAEPAXI@Z @ 0x00433fb0

void ___GBuildingSite__UAEPAXI_Z(byte param_1)

{
  FUN_004340d0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCitadelBuildingSite@@UAEPAXI@Z @ 0x00435840

void ___GCitadelBuildingSite__UAEPAXI_Z(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &vftable_CitadelBuildingSite;
  FUN_004340d0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GStandardBuildingSite@@UAEPAXI@Z @ 0x00435da0

void ___GStandardBuildingSite__UAEPAXI_Z(byte param_1)

{
  FUN_00435dd0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GWorkshopBuildingSite@@UAEPAXI@Z @ 0x00435ff0

void ___GWorkshopBuildingSite__UAEPAXI_Z(byte param_1)

{
  FUN_00436020();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGCamera@@UAEPAXI@Z @ 0x00439a50

void ___GGCamera__UAEPAXI_Z(byte param_1)

{
  FUN_0053e780();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCitadel@@UAEPAXI@Z @ 0x0044e3d0

void ___GCitadel__UAEPAXI_Z(byte param_1)

{
  FUN_0053e780();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGCitadelHeartInfo@@UAEPAXI@Z @ 0x0044f950

void ___GGCitadelHeartInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GLeashObj@@UAEPAXI@Z @ 0x0044fdc0

void ___GLeashObj__UAEPAXI_Z(byte param_1)

{
  FUN_005e8ba0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// CitadelHeart_vf548 @ 0x0044ffb0

undefined4 CitadelHeart_vf548(void)

{
  int *in_ECX;
  float10 fVar1;
  
  if ((*(byte *)(in_ECX + 0x16) & 2) == 0) {
    fVar1 = (float10)(**(code **)(*in_ECX + 0x880))();
    if ((float10)1.0 <= fVar1) {
      return 1;
    }
  }
  return 0;
}



// ??_GCitadelHeart@@UAEPAXI@Z @ 0x00450020

void ___GCitadelHeart__UAEPAXI_Z(byte param_1)

{
  FUN_00450050();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGArena@@UAEPAXI@Z @ 0x00450920

void ___GGArena__UAEPAXI_Z(byte param_1)

{
  FUN_0053e780();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GPSysBase@@UAEPAXI@Z @ 0x00451830

void ___GPSysBase__UAEPAXI_Z(byte param_1)

{
  FUN_0061ec30();
  if ((param_1 & 1) != 0) {
    FUN_0061ebb0();
  }
  return;
}



// ??_GUR_PlasmaInf@@UAEPAXI@Z @ 0x00451860

void ___GUR_PlasmaInf__UAEPAXI_Z(byte param_1)

{
  FUN_0061ec30();
  if ((param_1 & 1) != 0) {
    FUN_0061ebb0();
  }
  return;
}



// ??_GCitadelEntrance@@UAEPAXI@Z @ 0x004540a0

void ___GCitadelEntrance__UAEPAXI_Z(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &vftable_CitadelEntrance;
  FUN_005e8ba0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCitadelPart@@UAEPAXI@Z @ 0x004546a0

void ___GCitadelPart__UAEPAXI_Z(byte param_1)

{
  FUN_004546d0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGContainerInfo@@UAEPAXI@Z @ 0x00456850

void ___GGContainerInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// _LoadBinary_5CHandFPci @ 0x004580b0

undefined4 _LoadBinary_5CHandFPci(undefined4 param_1)

{
  int iVar1;
  undefined1 *puVar2;
  int *in_ECX;
  int unaff_EBX;
  int iVar3;
  int *piVar4;
  int iVar5;
  int unaff_retaddr;
  char *pcVar6;
  int *piStack_48;
  int *apiStack_44 [17];
  
  piVar4 = in_ECX + 3;
  piStack_48 = (int *)0x0;
  apiStack_44[0] = piVar4;
  FUN_0072c900(param_1);
  iVar1 = (**(code **)*piVar4)(2);
  if (iVar1 != 0) {
    FUN_005cfa00(s_Can_t_open_hand___008fd488,param_1);
    return 0;
  }
  iVar1 = FUN_0072d1b0(&DAT_008fd480);
  if (iVar1 == 0) {
    FUN_0072d2f0(&stack0x00000000,4,0xffffffff);
    if (unaff_retaddr < 1) {
      FUN_0072d2f0(&stack0x00000000,4,0xffffffff);
      if (unaff_retaddr < 6) {
        if (unaff_retaddr < 5) {
          FUN_00733e17(apiStack_44,s_data_hndspec_d_txt_008fd420,unaff_retaddr);
          unaff_EBX = FUN_00746d70(0x5468,s_C__dev_black_ControlHand_cpp_008fd3c0,0x473);
          if (unaff_EBX == 0) {
            unaff_EBX = 0;
          }
          else {
            puVar2 = (undefined1 *)(unaff_EBX + 8);
            iVar1 = 0x18;
            do {
              *puVar2 = 0;
              puVar2 = puVar2 + 0x20;
              iVar1 = iVar1 + -1;
            } while (iVar1 != 0);
            iVar1 = unaff_EBX + 0x30c;
            iVar3 = 0x18;
            do {
              FUN_00405cd0(iVar1,0x20,0x18,&LAB_004583d0);
              iVar1 = iVar1 + 0x364;
              iVar3 = iVar3 + -1;
              piVar4 = piStack_48;
            } while (iVar3 != 0);
          }
          iVar1 = FUN_004abd70(apiStack_44);
          if (iVar1 == 0) {
            FUN_005cfa00(s_Can_t_read___008fd410,apiStack_44);
            FUN_007290de(unaff_EBX);
            FUN_0072cf20();
            return 0;
          }
        }
        FUN_00733e17(apiStack_44,s_data_hndspec_d_txt_008fd420,5);
        iVar1 = FUN_00746d70(0x5468,s_C__dev_black_ControlHand_cpp_008fd3c0,0x47e);
        if (iVar1 == 0) {
          iVar1 = 0;
          piStack_48 = piVar4;
        }
        else {
          puVar2 = (undefined1 *)(iVar1 + 8);
          iVar3 = 0x18;
          do {
            *puVar2 = 0;
            puVar2 = puVar2 + 0x20;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
          iVar3 = iVar1 + 0x30c;
          iVar5 = 0x18;
          do {
            FUN_00405cd0(iVar3,0x20,0x18,&LAB_004583d0);
            iVar3 = iVar3 + 0x364;
            iVar5 = iVar5 + -1;
          } while (iVar5 != 0);
        }
        iVar3 = FUN_004abd70(apiStack_44);
        if (iVar3 != 0) {
          iVar3 = unaff_EBX;
          if (unaff_EBX == 0) {
            iVar3 = iVar1;
          }
          iVar3 = FUN_005d01a0(piStack_48,iVar3,iVar1);
          if (iVar3 != 0) {
            FUN_005d1bd0(0,1,0);
            FUN_005d1bd0(0,2,0);
            FUN_005d1bd0(0,3,0);
            FUN_005d1bd0(0,4,0);
            FUN_005d1bd0(0,5,0);
            FUN_005cfdb0(0);
            FUN_00457170();
            FUN_007290de(unaff_EBX);
            FUN_007290de(iVar1);
            (**(code **)(*in_ECX + 8))(0x3f800000);
            if (in_ECX[0x126b] != 0) {
              FUN_007290de(in_ECX[0x126b]);
            }
            iVar1 = FUN_00746d70(in_ECX[0x11ee] * 0x30,s_C__dev_black_ControlHand_cpp_008fd3c0,0x4a1
                                );
            in_ECX[0x126b] = iVar1;
            _Draw_PlannedMultiMapFixed__QAEXXZ();
            return 1;
          }
          FUN_007290de(unaff_EBX);
          FUN_007290de(iVar1);
          FUN_0072cf20();
          return 0;
        }
        FUN_005cfa00(s_Can_t_read___008fd410,apiStack_44);
        FUN_007290de(unaff_EBX);
        FUN_007290de(iVar1);
        FUN_0072cf20();
        return 0;
      }
      pcVar6 = s_Unknown_data_version___008fd434;
    }
    else {
      pcVar6 = s_Unknown_hand_version___008fd44c;
    }
  }
  else {
    pcVar6 = s_Can_t_open_segment_Hand___008fd464;
  }
  FUN_005cfa00(pcVar6,param_1);
  FUN_0072cf20();
  return 0;
}



// ??GCPUCheck@@UAE@XZ @ 0x0045c580

void __GCPUCheck__UAE_XZ(byte param_1)

{
  FUN_0045c5a0();
  if ((param_1 & 1) != 0) {
    FUN_007290de();
  }
  return;
}



// ??_GCreatureInfo@@UAEPAXI@Z @ 0x0045d780

void ___GCreatureInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreaturePlan@@UAEPAXI@Z @ 0x0045e580

void ___GCreaturePlan__UAEPAXI_Z(byte param_1)

{
  FUN_004d13a0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureSubActionAgenda@@UAEPAXI@Z @ 0x0045e7d0

void ___GCreatureSubActionAgenda__UAEPAXI_Z(byte param_1)

{
  int iVar1;
  
  iVar1 = 0x20;
  do {
    FUN_00430270();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreature@@UAEPAXI@Z @ 0x0045e870

void ___GCreature__UAEPAXI_Z(byte param_1)

{
  FUN_0045f4b0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GMobile@@UAEPAXI@Z @ 0x0045f030

void ___GMobile__UAEPAXI_Z(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &vftable_Mobile;
  FUN_005e8ba0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GMobileWallHug@@UAEPAXI@Z @ 0x0045f060

void ___GMobileWallHug__UAEPAXI_Z(byte param_1)

{
  FUN_005c8720();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GLiving@@UAEPAXI@Z @ 0x0045f090

void ___GLiving__UAEPAXI_Z(byte param_1)

{
  FUN_005c8720();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureInitialDesireInfo@@UAEPAXI@Z @ 0x004799a0

void ___GCreatureInitialDesireInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureDesireActionEntry@@UAEPAXI@Z @ 0x00479a80

void ___GCreatureDesireActionEntry__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureDesireAttributeEntry@@UAEPAXI@Z @ 0x00479c70

void ___GCreatureDesireAttributeEntry__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureAttitudeToPlayer@@UAEPAXI@Z @ 0x004aea90

void ___GCreatureAttitudeToPlayer__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GAttributeOnFire@@UAEPAXI@Z @ 0x004b1e90

void ___GAttributeOnFire__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureLearningEpisode@@UAEPAXI@Z @ 0x004b1f60

void ___GCreatureLearningEpisode__UAEPAXI_Z(byte param_1)

{
  FUN_004b7a30();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureContext@@UAEPAXI@Z @ 0x004b3740

void ___GCreatureContext__UAEPAXI_Z(byte param_1)

{
  FUN_004d13a0();
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGAlignmentInfo@@UAEPAXI@Z @ 0x004b3b80

void ___GGAlignmentInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureBeliefs@@UAEPAXI@Z @ 0x004b5cc0

void ___GCreatureBeliefs__UAEPAXI_Z(byte param_1)

{
  FUN_004bb010();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureMental@@UAEPAXI@Z @ 0x004b5cf0

void ___GCreatureMental__UAEPAXI_Z(byte param_1)

{
  FUN_004b5d20();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureCommandState@@UAEPAXI@Z @ 0x004b6be0

void ___GCreatureCommandState__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureAgenda@@UAEPAXI@Z @ 0x004b6c00

void ___GCreatureAgenda__UAEPAXI_Z(byte param_1)

{
  int iVar1;
  
  FUN_00430270();
  FUN_00430270();
  iVar1 = 0x20;
  do {
    FUN_00430270();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_00430270();
  FUN_004d13a0();
  FUN_004d13a0();
  iVar1 = 0x28;
  do {
    FUN_004d13a0();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureBeliefSmall@@UAEPAXI@Z @ 0x004b92b0

void ___GCreatureBeliefSmall__UAEPAXI_Z(byte param_1)

{
  FUN_004bce90();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureBeliefAboutVillager@@UAEPAXI@Z @ 0x004b92d0

void ___GCreatureBeliefAboutVillager__UAEPAXI_Z(byte param_1)

{
  FUN_004bcfd0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureBeliefAboutTown@@UAEPAXI@Z @ 0x004b92f0

void ___GCreatureBeliefAboutTown__UAEPAXI_Z(byte param_1)

{
  FUN_004bced0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureBeliefAboutFlock@@UAEPAXI@Z @ 0x004b9310

void ___GCreatureBeliefAboutFlock__UAEPAXI_Z(byte param_1)

{
  FUN_004bcf10();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureBeliefAboutCitadel@@UAEPAXI@Z @ 0x004b9330

void ___GCreatureBeliefAboutCitadel__UAEPAXI_Z(byte param_1)

{
  FUN_004bd050();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureBeliefAboutCreature@@UAEPAXI@Z @ 0x004b9350

void ___GCreatureBeliefAboutCreature__UAEPAXI_Z(byte param_1)

{
  FUN_004bcf50();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureBeliefAboutForest@@UAEPAXI@Z @ 0x004b9380

void ___GCreatureBeliefAboutForest__UAEPAXI_Z(byte param_1)

{
  FUN_004bcf90();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureBeliefAboutAbode@@UAEPAXI@Z @ 0x004b93b0

void ___GCreatureBeliefAboutAbode__UAEPAXI_Z(byte param_1)

{
  FUN_004bd010();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureBeliefAboutContext@@UAEPAXI@Z @ 0x004b93d0

void ___GCreatureBeliefAboutContext__UAEPAXI_Z(byte param_1)

{
  FUN_004bd090();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureBelief@@UAEPAXI@Z @ 0x004b9f20

void ___GCreatureBelief__UAEPAXI_Z(byte param_1)

{
  FUN_004bb110();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureDevelopmentPhaseEntry@@UAEPAXI@Z @ 0x004bd690

void ___GCreatureDevelopmentPhaseEntry__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureDesires@@UAEPAXI@Z @ 0x004be1c0

void ___GCreatureDesires__UAEPAXI_Z(byte param_1)

{
  FUN_004be1f0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureDesireSourceTable@@UAEPAXI@Z @ 0x004bf1c0

void ___GCreatureDesireSourceTable__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureSourceBoundsInfo@@UAEPAXI@Z @ 0x004bf3b0

void ___GCreatureSourceBoundsInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureGlobalExplorationMap@@UAEPAXI@Z @ 0x004c1220

void ___GCreatureGlobalExplorationMap__UAEPAXI_Z(byte param_1)

{
  int iVar1;
  
  iVar1 = 0x1000;
  do {
    FUN_00430270();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureExplorationMap@@UAEPAXI@Z @ 0x004c1390

void ___GCreatureExplorationMap__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreaturePreviousLesson@@UAEPAXI@Z @ 0x004c1d90

void ___GCreaturePreviousLesson__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureLearning@@UAEPAXI@Z @ 0x004c1dc0

void ___GCreatureLearning__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  FUN_004d2320();
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureLearningContext@@UAEPAXI@Z @ 0x004c3690

void ___GCreatureLearningContext__UAEPAXI_Z(byte param_1)

{
  FUN_004c36b0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureActionsKnownAbout@@UAEPAXI@Z @ 0x004c39b0

void ___GCreatureActionsKnownAbout__UAEPAXI_Z(byte param_1)

{
  FUN_004c39d0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureMimicInfo@@UAEPAXI@Z @ 0x004ca8e0

void ___GCreatureMimicInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureMimicState@@UAEPAXI@Z @ 0x004ca930

void ___GCreatureMimicState__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGCreaturePenInfo@@UAEPAXI@Z @ 0x004cf320

void ___GGCreaturePenInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreaturePen@@UAEPAXI@Z @ 0x004cf3c0

void ___GCreaturePen__UAEPAXI_Z(byte param_1)

{
  FUN_004cf3f0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// PlannedCreaturePen_vf320 @ 0x004cf540

int PlannedCreaturePen_vf320(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  float10 fVar3;
  int iVar4;
  
  iVar2 = in_ECX[10];
  iVar4 = in_ECX[0x12];
  fVar3 = (float10)(**(code **)(*in_ECX + 0x120))(iVar4);
  iVar2 = FUN_00454760(in_ECX + 5,iVar2,(float)fVar3,iVar4);
  if (iVar2 != 0) {
    iVar2 = in_ECX[10];
    iVar4 = in_ECX[0x12];
    iVar1 = in_ECX[0x10];
    fVar3 = (float10)(**(code **)(*in_ECX + 0x120))(param_1,1);
    iVar2 = FUN_004cf450(in_ECX + 5,iVar1,iVar4,iVar2,(float)fVar3);
    if (iVar2 != 0) {
      (**(code **)(*in_ECX + 0x508))(iVar2);
      return iVar2;
    }
  }
  return 0;
}



// ??_GCreaturePhysical@@UAEPAXI@Z @ 0x004cf940

void ___GCreaturePhysical__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreaturePreviousActions@@UAEPAXI@Z @ 0x004d20c0

void ___GCreaturePreviousActions__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureDesireDependency@@UAEPAXI@Z @ 0x004e9d90

void ___GCreatureDesireDependency__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GDance@@UAEPAXI@Z @ 0x004e9e60

void ___GDance__UAEPAXI_Z(byte param_1)

{
  FUN_004ea050();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GDanceGroup@@UAEPAXI@Z @ 0x004eb110

void ___GDanceGroup__UAEPAXI_Z(byte param_1)

{
  FUN_0053e780();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GDanceKeyAction@@UAEPAXI@Z @ 0x004ec2b0

void ___GDanceKeyAction__UAEPAXI_Z(byte param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar2 = *(int *)(in_ECX + 0x14);
  while (iVar2 != 0) {
    iVar1 = *(int *)(iVar2 + 4);
    FUN_007290de(iVar2);
    iVar2 = iVar1;
  }
  FUN_0053e780();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// DeadTree_vf432 @ 0x004ee470

void DeadTree_vf432(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x2c))();
  if (iVar1 != 0) {
    (**(code **)(*in_ECX + 0x1c))(0);
    FUN_0067efc0();
  }
  return;
}



// ??_GDeadTree@@UAEPAXI@Z @ 0x004eee50

void ___GDeadTree__UAEPAXI_Z(byte param_1)

{
  FUN_005c3620();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// EditorIconShow_vf1 @ 0x004f9a30

undefined4 EditorIconShow_vf1(void)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  iVar1 = in_ECX[0xc];
  in_ECX[0xe] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xf] = 1;
  iVar2 = (**(code **)(*in_ECX + 0x48))();
  if (iVar2 != 0) {
    if ((in_ECX[7] != 0) && (iVar1 == 0)) {
      FUN_004f9870(in_ECX[0x11],1);
    }
    if ((DAT_00d5c400 & 1) != 0) {
      in_ECX[0xd] = 1;
      DAT_00d5c400 = DAT_00d5c400 & 0xfe;
    }
    if ((DAT_00d5c400 & 2) != 0) {
      in_ECX[0xe] = 1;
      DAT_00d5c400 = DAT_00d5c400 & 0xfd;
    }
    return 1;
  }
  return 0;
}



// EditorIconBool_vf1 @ 0x004f9e00

undefined4 EditorIconBool_vf1(void)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  in_ECX[0xe] = 0;
  in_ECX[0xd] = 0;
  in_ECX[0xf] = 1;
  iVar1 = (**(code **)(*in_ECX + 0x48))();
  if (iVar1 == 0) {
    return 0;
  }
  if ((DAT_00d5c400 & 1) == 0) {
    if ((DAT_00d5c400 & 2) == 0) {
      return 1;
    }
    DAT_00d5c400 = DAT_00d5c400 & 0xfd;
    in_ECX[0xe] = 1;
  }
  else {
    DAT_00d5c400 = DAT_00d5c400 & 0xfe;
    in_ECX[0xd] = 1;
  }
  iVar1 = *in_ECX;
  iVar2 = (**(code **)(iVar1 + 0x4c))();
  (**(code **)(iVar1 + 0x50))(iVar2 == 0);
  return 1;
}



// EditorIconBase_vf4 @ 0x004fa410

undefined4 EditorIconBase_vf4(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int *in_ECX;
  float10 fVar2;
  
  uVar1 = (**(code **)(*in_ECX + 0x24))(param_1,DAT_00be76f0);
  uVar1 = (**(code **)(*in_ECX + 0x34))(1,uVar1);
  fVar2 = (float10)FUN_004fa0a0(param_2,uVar1);
  if (fVar2 != (float10)0.0) {
    return 1;
  }
  return 0;
}



// EditorIconPDM_vf1 @ 0x004fa920

uint EditorIconPDM_vf1(void)

{
  int *piVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  int in_ECX;
  int *piVar5;
  
  FUN_004fa9f0();
  uVar3 = EditorIconBool_vf1();
  if (*(int *)(in_ECX + 0x184) != 0) {
    piVar5 = (int *)0x0;
    while( true ) {
      puVar2 = *(undefined4 **)(in_ECX + 0x188);
      if (piVar5 != (int *)0x0) {
        do {
          if (puVar2 == (undefined4 *)0x0) {
            return uVar3;
          }
          piVar1 = puVar2 + 1;
          puVar2 = (undefined4 *)*puVar2;
        } while ((int *)*piVar1 != piVar5);
      }
      if ((puVar2 == (undefined4 *)0x0) || (piVar5 = (int *)puVar2[1], piVar5 == (int *)0x0)) break;
      uVar4 = (**(code **)(*piVar5 + 4))();
      uVar3 = uVar3 | uVar4;
    }
  }
  return uVar3;
}



// ?$EditorIconSlider@K_vf1 @ 0x004faf60

undefined4 __EditorIconSlider_K_vf1(void)

{
  float fVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *in_ECX;
  undefined4 uVar5;
  float10 fVar6;
  float fStack_8;
  float fStack_4;
  
  uVar5 = 0;
  in_ECX[0xf] = 1;
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  iVar2 = (**(code **)(*in_ECX + 0x48))();
  if (iVar2 != 0) {
    if ((DAT_00d5c400 & 1) != 0) {
      in_ECX[0xd] = 1;
      in_ECX[0x9d] = 1;
      fStack_8 = DAT_00d5c370;
      fStack_4 = DAT_00d5c374;
      iVar2 = FUN_007499b0(&fStack_8);
      if (iVar2 == 0) {
        iVar2 = FUN_004fb970();
        fVar1 = DAT_00d5c370;
        if (iVar2 != 0) {
          fVar1 = DAT_00d5c374;
        }
        fStack_4 = DAT_00d5c374;
        fStack_8 = (float)(int)fVar1;
        iVar3 = (**(code **)*in_ECX)();
        iVar2 = *(int *)(iVar3 + 0xc);
        iVar3 = *(int *)(iVar3 + 4);
        piVar4 = (int *)(**(code **)*in_ECX)();
        if ((piVar4[2] - *piVar4) + 1 < (iVar2 - iVar3) + 1) {
          if (in_ECX[0x9d] != 0) goto LAB_004fb0b6;
          if ((float)in_ECX[0x98] <= fStack_8) {
            iVar2 = in_ECX[0x9a];
LAB_004fb09c:
            if (fStack_8 <= (float)iVar2) goto LAB_004fb0b6;
            iVar2 = (**(code **)(*in_ECX + 0x4c))();
            iVar2 = iVar2 + in_ECX[0x9c];
          }
          else {
            iVar2 = (**(code **)(*in_ECX + 0x4c))();
            iVar2 = iVar2 - in_ECX[0x9c];
          }
        }
        else {
          if (in_ECX[0x9d] == 0) {
            if ((float)in_ECX[0x97] <= fStack_8) {
              iVar2 = in_ECX[0x99];
              goto LAB_004fb09c;
            }
            iVar2 = (**(code **)(*in_ECX + 0x4c))();
            iVar2 = iVar2 - in_ECX[0x9c];
            goto LAB_004fb12d;
          }
LAB_004fb0b6:
          fVar6 = (float10)FUN_00413aa0();
          fStack_8 = (float)((float10)fStack_8 - fVar6);
          FUN_004fb910();
          fStack_8 = (float)in_ECX[0x54];
          fStack_4 = 0.0;
          iVar2 = __ftol();
        }
LAB_004fb12d:
        (**(code **)(*in_ECX + 0x50))(iVar2);
      }
      else {
        DAT_00d5c400 = DAT_00d5c400 & 0xfe;
        in_ECX[0x9d] = 1;
      }
    }
    uVar5 = 1;
  }
  if (in_ECX[0x9d] == 0) {
    FUN_004fb630();
    return uVar5;
  }
  in_ECX[0xd] = 1;
  iVar2 = FUN_004fb970();
  fVar1 = DAT_00d5c370;
  if (iVar2 != 0) {
    fVar1 = DAT_00d5c374;
  }
  fStack_4 = DAT_00d5c374;
  fStack_8 = (float)(int)fVar1;
  iVar2 = FUN_004fb970();
  if (iVar2 == 0) {
    if (in_ECX[0x9d] == 0) {
      if (fStack_8 < (float)in_ECX[0x97]) {
        iVar2 = (**(code **)(*in_ECX + 0x4c))();
        iVar2 = iVar2 - in_ECX[0x9c];
        goto LAB_004fb288;
      }
      iVar2 = in_ECX[0x99];
      goto LAB_004fb1f9;
    }
  }
  else if (in_ECX[0x9d] == 0) {
    if (fStack_8 < (float)in_ECX[0x98]) {
      iVar2 = (**(code **)(*in_ECX + 0x4c))();
      iVar2 = iVar2 - in_ECX[0x9c];
      goto LAB_004fb288;
    }
    iVar2 = in_ECX[0x9a];
LAB_004fb1f9:
    if ((float)iVar2 < fStack_8) {
      iVar2 = (**(code **)(*in_ECX + 0x4c))();
      iVar2 = iVar2 + in_ECX[0x9c];
      goto LAB_004fb288;
    }
  }
  fVar6 = (float10)FUN_00413aa0();
  fStack_8 = (float)((float10)fStack_8 - fVar6);
  FUN_004fb910();
  fStack_8 = (float)in_ECX[0x54];
  fStack_4 = 0.0;
  iVar2 = __ftol();
LAB_004fb288:
  (**(code **)(*in_ECX + 0x50))(iVar2);
  in_ECX[0x9d] = DAT_00d5c3b4 & 1;
  return 1;
}



// PDMStrip_vf0 @ 0x004fb9a0

int PDMStrip_vf0(void)

{
  int in_ECX;
  
  return in_ECX + 0x40;
}



// ??_GGMagicEffectInfo@@UAEPAXI@Z @ 0x004fc490

void ___GGMagicEffectInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GEffectValues@@UAEPAXI@Z @ 0x004fc520

void ___GEffectValues__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GFeature@@UAEPAXI@Z @ 0x004fe720

void ___GFeature__UAEPAXI_Z(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &vftable_Feature;
  FUN_00504580();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGFieldInfo@@UAEPAXI@Z @ 0x004fea00

void ___GGFieldInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGFieldTypeInfo@@UAEPAXI@Z @ 0x004feae0

void ___GGFieldTypeInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GField@@UAEPAXI@Z @ 0x004fec90

void ___GField__UAEPAXI_Z(byte param_1)

{
  FUN_004018f0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GFireFly@@UAEPAXI@Z @ 0x00500b30

void ___GFireFly__UAEPAXI_Z(byte param_1)

{
  FUN_00500cb0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GFishFarm@@UAEPAXI@Z @ 0x00502a90

void ___GFishFarm__UAEPAXI_Z(byte param_1)

{
  FUN_00502ac0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??1Fixed@@UAE@XZ @ 0x005040e0

void __1Fixed__UAE_XZ(byte param_1)

{
  FUN_00504160();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_DMultiMapFixed@@QAEXXZ @ 0x005044c0

void ___DMultiMapFixed__QAEXXZ(byte param_1)

{
  FUN_00504580();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GSingleMapFixed@@UAEPAXI@Z @ 0x00504df0

void ___GSingleMapFixed__UAEPAXI_Z(byte param_1)

{
  FUN_00504db0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GFlock@@UAEPAXI@Z @ 0x00505a00

void ___GFlock__UAEPAXI_Z(byte param_1)

{
  FUN_0053e780();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GFootball@@UAEPAXI@Z @ 0x00507110

void ___GFootball__UAEPAXI_Z(byte param_1)

{
  FUN_004018f0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGFootpath@@UAEPAXI@Z @ 0x0050a150

void ___GGFootpath__UAEPAXI_Z(byte param_1)

{
  FUN_0050a1a0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GShowNeeds@@UAEPAXI@Z @ 0x0050b9a0

void ___GShowNeeds__UAEPAXI_Z(byte param_1)

{
  FUN_0053e780();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGFootpathFinder@@UAEPAXI@Z @ 0x0050d6c0

void ___GGFootpathFinder__UAEPAXI_Z(byte param_1)

{
  FUN_0050d6f0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GAllocatedBeliefList@@UAEPAXI@Z @ 0x0050e060

void ___GAllocatedBeliefList__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GForest@@UAEPAXI@Z @ 0x0050e150

void ___GForest__UAEPAXI_Z(byte param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int in_ECX;
  int *piVar4;
  
  do {
    do {
      piVar1 = *(int **)(in_ECX + 0x50);
      if (piVar1 == (int *)0x0) {
        do {
          do {
            piVar1 = *(int **)(in_ECX + 0x48);
            if (piVar1 == (int *)0x0) {
              FUN_0053e780();
              if ((param_1 & 1) != 0) {
                FUN_00430280();
              }
              return;
            }
            piVar2 = piVar1;
            piVar4 = (int *)0x0;
          } while (piVar1 == (int *)0x0);
          do {
            piVar3 = piVar2;
            if (*piVar3 == *piVar1) {
              if (piVar4 == (int *)0x0) {
                *(int *)(in_ECX + 0x48) = piVar1[1];
              }
              else {
                piVar4[1] = piVar3[1];
              }
              FUN_007290de(piVar3);
              *(int *)(in_ECX + 0x4c) = *(int *)(in_ECX + 0x4c) + -1;
              break;
            }
            piVar2 = (int *)piVar3[1];
            piVar4 = piVar3;
          } while ((int *)piVar3[1] != (int *)0x0);
        } while( true );
      }
      piVar2 = piVar1;
      piVar4 = (int *)0x0;
    } while (piVar1 == (int *)0x0);
    do {
      piVar3 = piVar2;
      if (*piVar3 == *piVar1) {
        if (piVar4 == (int *)0x0) {
          *(int *)(in_ECX + 0x50) = piVar1[1];
        }
        else {
          piVar4[1] = piVar3[1];
        }
        FUN_007290de(piVar3);
        *(int *)(in_ECX + 0x54) = *(int *)(in_ECX + 0x54) + -1;
        break;
      }
      piVar2 = (int *)piVar3[1];
      piVar4 = piVar3;
    } while ((int *)piVar3[1] != (int *)0x0);
  } while( true );
}



// Catch@0051918e @ 0x0051918e

undefined * Catch_0051918e(void)

{
  int iVar1;
  void *pvVar2;
  int unaff_EBP;
  
  *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + 8);
  iVar1 = *(int *)(unaff_EBP + 8) + 2;
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  pvVar2 = operator_new(iVar1 * 2);
  *(void **)(unaff_EBP + -0x18) = pvVar2;
  return &DAT_005191b2;
}



// ??_GGKeyBuffer@@UAEPAXI@Z @ 0x0051ec10

void ___GGKeyBuffer__UAEPAXI_Z(byte param_1)

{
  FUN_005a1650();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGlobalGameLists@@UAEPAXI@Z @ 0x0051ec30

void ___GGlobalGameLists__UAEPAXI_Z(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &vftable_GlobalGameLists;
  _Draw_PlannedMultiMapFixed__QAEXXZ();
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGSoundMap@@UAEPAXI@Z @ 0x0051ecc0

void ___GGSoundMap__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGestureSystemDataList@@UAEPAXI@Z @ 0x0051ed70

void ___GGestureSystemDataList__UAEPAXI_Z(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &vftable_GestureSystemDataList;
  FUN_005459a0();
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGestureSystem@@UAEPAXI@Z @ 0x0051ede0

void ___GGestureSystem__UAEPAXI_Z(byte param_1)

{
  undefined4 *in_ECX;
  
  *in_ECX = &vftable_GestureSystem;
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??1GGame@@UAE@XZ @ 0x0051ee20

void __1GGame__UAE_XZ(byte param_1)

{
  int in_ECX;
  int iVar1;
  
  _Draw_PlannedMultiMapFixed__QAEXXZ();
  FUN_005a1650();
  FUN_005a61c0();
  FUN_00430270();
  FUN_00401000(in_ECX + 0x24bf60,0x14,0xe,&LAB_0051f170);
  FUN_00430270();
  FUN_00401000(in_ECX + 0x201f50,0x128,0x400,&LAB_0051f0d0);
  FUN_00430270();
  FUN_0051ef30();
  FUN_005e7c10();
  FUN_00430270();
  thunk_FUN_00749b70();
  FUN_005be3a0();
  FUN_005e5dd0();
  FUN_005e5dd0();
  iVar1 = 8;
  do {
    FUN_005f6ff0();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_0053e780();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGTerrainMap@@UAEPAXI@Z @ 0x0051f040

void ___GGTerrainMap__UAEPAXI_Z(byte param_1)

{
  int in_ECX;
  int iVar1;
  int iVar2;
  
  iVar1 = 0xe;
  do {
    FUN_00430270();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_00430270();
  iVar1 = in_ECX + 0x4a018;
  iVar2 = 0x400;
  do {
    iVar1 = iVar1 + -0x128;
    FUN_00401000(iVar1,0x14,0xe,&LAB_0051f170);
    FUN_00430270();
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GTerrainMapInfo@@UAEPAXI@Z @ 0x0051f100

void ___GTerrainMapInfo__UAEPAXI_Z(byte param_1)

{
  int iVar1;
  
  iVar1 = 0xe;
  do {
    FUN_00430270();
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// Catch@005223a8 @ 0x005223a8

undefined * Catch_005223a8(void)

{
  DAT_00c22cb4 = 0;
  return &DAT_005223b5;
}



// ??_GGameArea@@UAEPAXI@Z @ 0x00528d30

void ___GGameArea__UAEPAXI_Z(byte param_1)

{
  FUN_00528d50();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGameOSFile@@UAEPAXI@Z @ 0x005298c0

void ___GGameOSFile__UAEPAXI_Z(byte param_1)

{
  FUN_005298e0();
  if ((param_1 & 1) != 0) {
    FUN_007290de();
  }
  return;
}



// ??_GReaction@@UAEPAXI@Z @ 0x0052dfe0

void ___GReaction__UAEPAXI_Z(byte param_1)

{
  FUN_0067ecb0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??1PlannedMultiMapFixed@@UAE@XZ @ 0x0052e370

void __1PlannedMultiMapFixed__UAE_XZ(byte param_1)

{
  FUN_0053e780();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GStoragePit@@UAEPAXI@Z @ 0x0052e440

void ___GStoragePit__UAEPAXI_Z(byte param_1)

{
  FUN_006c8e50();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GSpellResource@@UAEPAXI@Z @ 0x0052e570

void ___GSpellResource__UAEPAXI_Z(byte param_1)

{
  FUN_0053e780();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GMobileObject@@UAEPAXI@Z @ 0x0052e5f0

void ___GMobileObject__UAEPAXI_Z(byte param_1)

{
  FUN_005c23b0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GFieldCrop@@UAEPAXI@Z @ 0x0052e650

void ___GFieldCrop__UAEPAXI_Z(byte param_1)

{
  FUN_005c3200();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GOneOffSpellSeed@@UAEPAXI@Z @ 0x0052e690

void ___GOneOffSpellSeed__UAEPAXI_Z(byte param_1)

{
  FUN_005c23b0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GSpellHeal@@UAEPAXI@Z @ 0x0052e6d0

void ___GSpellHeal__UAEPAXI_Z(byte param_1)

{
  FUN_0053e780();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GSpellForest@@UAEPAXI@Z @ 0x0052e730

void ___GSpellForest__UAEPAXI_Z(byte param_1)

{
  FUN_0053e780();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GSpellFlock@@UAEPAXI@Z @ 0x0052e760

void ___GSpellFlock__UAEPAXI_Z(byte param_1)

{
  FUN_0053e780();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GSpellFlockFlying@@UAEPAXI@Z @ 0x0052e7b0

void ___GSpellFlockFlying__UAEPAXI_Z(byte param_1)

{
  FUN_006ba8b0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GPot@@UAEPAXI@Z @ 0x0052e990

void ___GPot__UAEPAXI_Z(byte param_1)

{
  FUN_00616e30();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GPileWood@@UAEPAXI@Z @ 0x0052ea70

void ___GPileWood__UAEPAXI_Z(byte param_1)

{
  FUN_00618d50();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GMobileStatic@@UAEPAXI@Z @ 0x0052eae0

void ___GMobileStatic__UAEPAXI_Z(byte param_1)

{
  FUN_005c3620();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GTree@@UAEPAXI@Z @ 0x0052ec20

void ___GTree__UAEPAXI_Z(byte param_1)

{
  FUN_006db4e0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GTownDesireFlags@@UAEPAXI@Z @ 0x0052ec60

void ___GTownDesireFlags__UAEPAXI_Z(byte param_1)

{
  FUN_006d8550();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GTownCentre@@UAEPAXI@Z @ 0x0052ecb0

void ___GTownCentre__UAEPAXI_Z(byte param_1)

{
  FUN_006d5c80();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GWorshipSite@@UAEPAXI@Z @ 0x0052ed60

void ___GWorshipSite__UAEPAXI_Z(byte param_1)

{
  FUN_00703b90();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GShowNeedsVisuals@@UAEPAXI@Z @ 0x0052ee00

void ___GShowNeedsVisuals__UAEPAXI_Z(byte param_1)

{
  FUN_005e8ba0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??1GameThingWithPos@@UAE@XZ @ 0x0052ee50

void __1GameThingWithPos__UAE_XZ(byte param_1)

{
  FUN_0053e780();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGWaterfall@@UAEPAXI@Z @ 0x0052ee90

void ___GGWaterfall__UAEPAXI_Z(byte param_1)

{
  FUN_006c9ff0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GWeatherThing@@UAEPAXI@Z @ 0x0052ef70

void ___GWeatherThing__UAEPAXI_Z(byte param_1)

{
  FUN_0053e780();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGraveyard@@UAEPAXI@Z @ 0x0052efc0

void ___GGraveyard__UAEPAXI_Z(byte param_1)

{
  FUN_004018f0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GTownSpellIcon@@UAEPAXI@Z @ 0x0052f020

void ___GTownSpellIcon__UAEPAXI_Z(byte param_1)

{
  FUN_006da4b0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GTownCentreSpellIcon@@UAEPAXI@Z @ 0x0052f070

void ___GTownCentreSpellIcon__UAEPAXI_Z(byte param_1)

{
  FUN_006da580();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GScaffold@@UAEPAXI@Z @ 0x0052f0c0

void ___GScaffold__UAEPAXI_Z(byte param_1)

{
  FUN_00682fe0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGComputerPlayer@@UAEPAXI@Z @ 0x0052f310

void ___GGComputerPlayer__UAEPAXI_Z(byte param_1)

{
  FUN_0053e780();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GMist@@UAEPAXI@Z @ 0x0052fac0

void ___GMist__UAEPAXI_Z(byte param_1)

{
  FUN_0053e780();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GInfluenceRing@@UAEPAXI@Z @ 0x0052fb30

void ___GInfluenceRing__UAEPAXI_Z(byte param_1)

{
  FUN_0053e780();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GSpecialVillager@@UAEPAXI@Z @ 0x00531330

void ___GSpecialVillager__UAEPAXI_Z(byte param_1)

{
  FUN_006b64d0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GTotemStatue@@UAEPAXI@Z @ 0x005313c0

void ___GTotemStatue__UAEPAXI_Z(byte param_1)

{
  FUN_006cba80();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GContainer@@UAEPAXI@Z @ 0x005314a0

void ___GContainer__UAEPAXI_Z(byte param_1)

{
  FUN_0053e780();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GRock@@UAEPAXI@Z @ 0x00531500

void ___GRock__UAEPAXI_Z(byte param_1)

{
  FUN_005c3620();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGStreetLight@@UAEPAXI@Z @ 0x00531560

void ___GGStreetLight__UAEPAXI_Z(byte param_1)

{
  FUN_0053e780();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGStreetLantern@@UAEPAXI@Z @ 0x005315a0

void ___GGStreetLantern__UAEPAXI_Z(byte param_1)

{
  FUN_006ca5c0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGFootpathLink@@UAEPAXI@Z @ 0x005315e0

void ___GGFootpathLink__UAEPAXI_Z(byte param_1)

{
  FUN_0053e780();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GTotem@@UAEPAXI@Z @ 0x00531670

void ___GTotem__UAEPAXI_Z(byte param_1)

{
  FUN_004018f0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GPuzzleLion@@UAEPAXI@Z @ 0x005316c0

void ___GPuzzleLion__UAEPAXI_Z(byte param_1)

{
  FUN_0041adb0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GHanoiBlock@@UAEPAXI@Z @ 0x00531790

void ___GHanoiBlock__UAEPAXI_Z(byte param_1)

{
  FUN_005c23b0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GPuzzleTotem@@UAEPAXI@Z @ 0x00531810

void ___GPuzzleTotem__UAEPAXI_Z(byte param_1)

{
  FUN_004018f0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GPuzzleGrain@@UAEPAXI@Z @ 0x005318b0

void ___GPuzzleGrain__UAEPAXI_Z(byte param_1)

{
  FUN_00617da0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreed@@UAEPAXI@Z @ 0x00531930

void ___GCreed__UAEPAXI_Z(byte param_1)

{
  FUN_005c23b0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GPuzzleGame@@UAEPAXI@Z @ 0x00531980

void ___GPuzzleGame__UAEPAXI_Z(byte param_1)

{
  FUN_0053e780();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGestureSystemData@@UAEPAXI@Z @ 0x005459c0

undefined4 * ___GGestureSystemData__UAEPAXI_Z(byte param_1)

{
  undefined4 *in_ECX;
  undefined4 *puVar1;
  int iVar2;
  
  if ((param_1 & 2) == 0) {
    *in_ECX = &vftable_GestureSystemData;
    FUN_00430270();
    if ((param_1 & 1) != 0) {
      FUN_00430280();
    }
    return in_ECX;
  }
  iVar2 = in_ECX[-1];
  puVar1 = in_ECX + iVar2 * 0x197;
  if (-1 < iVar2 + -1) {
    do {
      puVar1 = puVar1 + -0x197;
      *puVar1 = &vftable_GestureSystemData;
      FUN_00430270();
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  if ((param_1 & 1) != 0) {
    FUN_004302e0(in_ECX + -1,0x65c);
  }
  return in_ECX + -1;
}



// Catch@0054a07f @ 0x0054a07f

undefined * Catch_0054a07f(void)

{
  uint uVar1;
  void *pvVar2;
  int unaff_EBP;
  
  *(int *)(unaff_EBP + -0x1c) = *(int *)(unaff_EBP + 8);
  uVar1 = *(int *)(unaff_EBP + 8) + 2;
  if ((int)uVar1 < 0) {
    uVar1 = 0;
  }
  pvVar2 = operator_new(uVar1);
  *(void **)(unaff_EBP + -0x18) = pvVar2;
  return &DAT_0054a0a0;
}



// Catch@0054b438 @ 0x0054b438

undefined * Catch_0054b438(void)

{
  int unaff_EBP;
  
  FUN_007294f8(*(uint *)((int)*(int **)(unaff_EBP + -0xbc) +
                        *(int *)(**(int **)(unaff_EBP + -0xbc) + 4) + 4) | 4,1);
  return &DAT_0054b463;
}



// Catch@00550f08 @ 0x00550f08

undefined * Catch_00550f08(void)

{
  int unaff_EBP;
  
  FUN_007294f8(*(uint *)((int)*(int **)(unaff_EBP + -0xbc) +
                        *(int *)(**(int **)(unaff_EBP + -0xbc) + 4) + 4) | 4,1);
  return &DAT_00550f33;
}



// Catch@00551138 @ 0x00551138

undefined * Catch_00551138(void)

{
  int unaff_EBP;
  
  FUN_007294f8(*(uint *)((int)*(int **)(unaff_EBP + -0xbc) +
                        *(int *)(**(int **)(unaff_EBP + -0xbc) + 4) + 4) | 4,1);
  return &DAT_00551163;
}



// Catch@00551368 @ 0x00551368

undefined * Catch_00551368(void)

{
  int unaff_EBP;
  
  FUN_007294f8(*(uint *)((int)*(int **)(unaff_EBP + -0xbc) +
                        *(int *)(**(int **)(unaff_EBP + -0xbc) + 4) + 4) | 4,1);
  return &DAT_00551393;
}



// Catch@0055159e @ 0x0055159e

undefined * Catch_0055159e(void)

{
  int unaff_EBP;
  
  FUN_007294f8(*(uint *)((int)*(int **)(unaff_EBP + -0xbc) +
                        *(int *)(**(int **)(unaff_EBP + -0xbc) + 4) + 4) | 4,1);
  return &DAT_005515c9;
}



// Catch@00551817 @ 0x00551817

undefined * Catch_00551817(void)

{
  int unaff_EBP;
  
  FUN_007294f8(*(uint *)((int)*(int **)(unaff_EBP + -0xa8) +
                        *(int *)(**(int **)(unaff_EBP + -0xa8) + 4) + 4) | 4,1);
  return &DAT_00551842;
}



// Catch@00551a2a @ 0x00551a2a

undefined * Catch_00551a2a(void)

{
  int unaff_EBP;
  
  FUN_007294f8(*(uint *)((int)*(int **)(unaff_EBP + -0xac) +
                        *(int *)(**(int **)(unaff_EBP + -0xac) + 4) + 4) | 4,1);
  return &DAT_00551a55;
}



// Catch@00551c57 @ 0x00551c57

undefined * Catch_00551c57(void)

{
  int unaff_EBP;
  
  FUN_007294f8(*(uint *)((int)*(int **)(unaff_EBP + -0xa8) +
                        *(int *)(**(int **)(unaff_EBP + -0xa8) + 4) + 4) | 4,1);
  return &DAT_00551c82;
}



// Catch@00551e67 @ 0x00551e67

undefined * Catch_00551e67(void)

{
  int unaff_EBP;
  
  FUN_007294f8(*(uint *)((int)*(int **)(unaff_EBP + -0xa8) +
                        *(int *)(**(int **)(unaff_EBP + -0xa8) + 4) + 4) | 4,1);
  return &DAT_00551e92;
}



// Catch@00552367 @ 0x00552367

undefined * Catch_00552367(void)

{
  int unaff_EBP;
  
  FUN_007294f8(*(uint *)((int)*(int **)(unaff_EBP + -0xb4) +
                        *(int *)(**(int **)(unaff_EBP + -0xb4) + 4) + 4) | 4,1);
  return &DAT_00552392;
}



// Catch@00555f35 @ 0x00555f35

undefined * Catch_00555f35(void)

{
  int unaff_EBP;
  
  FUN_007294f8(*(uint *)((int)*(int **)(unaff_EBP + 8) + *(int *)(**(int **)(unaff_EBP + 8) + 4) + 4
                        ) | 4,1);
  return &DAT_00555f5d;
}



// Catch@00556298 @ 0x00556298

undefined * Catch_00556298(void)

{
  int unaff_EBP;
  
  FUN_00556330(*(uint *)((int)*(int **)(unaff_EBP + 8) + *(int *)(**(int **)(unaff_EBP + 8) + 4) + 4
                        ) | 4,1);
  return &DAT_005562b6;
}



// Catch@00556536 @ 0x00556536

undefined * Catch_00556536(void)

{
  int unaff_EBP;
  
  FUN_007294f8(*(uint *)((int)*(int **)(unaff_EBP + 8) + *(int *)(**(int **)(unaff_EBP + 8) + 4) + 4
                        ) | 4,1);
  return &DAT_0055655e;
}



// Catch@005591c1 @ 0x005591c1

undefined * Catch_005591c1(void)

{
  int unaff_EBP;
  
  FUN_007294f8(*(uint *)((int)*(int **)(unaff_EBP + 8) + *(int *)(**(int **)(unaff_EBP + 8) + 4) + 4
                        ) | 4,1);
  return &DAT_005591e9;
}



// Catch@005aa46f @ 0x005aa46f

undefined * Catch_005aa46f(void)

{
  DAT_00c22cb4 = 0;
  return &DAT_005aa47c;
}



// ??_GGCitadelInfo@@UAEPAXI@Z @ 0x005ef740

void ___GGCitadelInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGFeatureInfo@@UAEPAXI@Z @ 0x005f2ea0

void ___GGFeatureInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGFootballPositionInfo@@UAEPAXI@Z @ 0x005f2f70

void ___GGFootballPositionInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureActionInfo@@UAEPAXI@Z @ 0x0062b3b0

void ___GCreatureActionInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// Catch@00666a67 @ 0x00666a67

undefined * Catch_00666a67(void)

{
  int unaff_EBP;
  
  FUN_007294f8(*(uint *)((int)*(int **)(unaff_EBP + -0xa8) +
                        *(int *)(**(int **)(unaff_EBP + -0xa8) + 4) + 4) | 4,1);
  return &DAT_00666a92;
}



// ??_GPuzzleSheep@@UAEPAXI@Z @ 0x0067b6e0

void ___GPuzzleSheep__UAEPAXI_Z(byte param_1)

{
  FUN_004143b0();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGArrowInfo@@UAEPAXI@Z @ 0x00680640

void ___GGArrowInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGBigForestInfo@@UAEPAXI@Z @ 0x00682f70

void ___GGBigForestInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GCreatureMentalDebug@@UAEPAXI@Z @ 0x006b4aa0

void ___GCreatureMentalDebug__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GSpellWater@@UAEPAXI@Z @ 0x006b9220

void ___GSpellWater__UAEPAXI_Z(byte param_1)

{
  FUN_0053e780();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGAnimatedStaticInfo@@UAEPAXI@Z @ 0x006bcc00

void ___GGAnimatedStaticInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGEffectInfo@@UAEPAXI@Z @ 0x006c4590

void ___GGEffectInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGMagicResourceInfo@@UAEPAXI@Z @ 0x006cae40

void ___GGMagicResourceInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// PuzzleTotem_vf406 @ 0x006cb400

void PuzzleTotem_vf406(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  Creche_vf406(param_1);
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x40) + 0xf8))();
  *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) | 0x4000;
  return;
}



// TownCentre_vf523 @ 0x006d6270

int TownCentre_vf523(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int *in_ECX;
  char *pcVar7;
  undefined1 auStack_19c [12];
  char acStack_190 [200];
  undefined1 auStack_c8 [100];
  undefined1 auStack_64 [100];
  
  if ((*(byte *)(in_ECX + 0x16) & 2) != 0) {
    iVar2 = StoragePit_vf523(param_1,param_2);
    return iVar2;
  }
  iVar2 = FUN_0053eb80();
  if (iVar2 == 1) {
    if (param_2 != 0) {
      FUN_005c13b0(auStack_19c,param_2);
    }
    iVar2 = (**(code **)(*in_ECX + 0x48))();
    if (iVar2 == 0) {
      uVar6 = 0xffffffff;
    }
    else {
      iVar2 = (**(code **)(*in_ECX + 0x48))();
      uVar6 = *(undefined4 *)(iVar2 + 0x5b4);
    }
    (**(code **)(*in_ECX + 0x120))();
    (**(code **)(*in_ECX + 0x508))();
    uVar3 = __ftol();
    uVar3 = __ftol(uVar3);
    uVar3 = __ftol(uVar3);
    uVar4 = FUN_00404210(auStack_64);
    uVar5 = FUN_005bf290(auStack_c8);
    uVar6 = FUN_006ad590(9,uVar6,uVar5,uVar4,uVar3);
    FUN_00733e17(acStack_190,uVar6);
    iVar2 = -1;
    pcVar7 = acStack_190;
    do {
      if (iVar2 == 0) break;
      iVar2 = iVar2 + -1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar7 + 1;
    } while (cVar1 != '\0');
    FUN_006b10c0();
    iVar2 = 1;
  }
  return iVar2;
}



// PlannedTownCentre_vf321 @ 0x006d6600

int PlannedTownCentre_vf321(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *in_ECX;
  float10 fVar3;
  
  iVar2 = in_ECX[10];
  fVar3 = (float10)(**(code **)(*in_ECX + 0x120))(param_1,1);
  uVar1 = (**(code **)(*in_ECX + 0x48))(iVar2,(float)fVar3);
  uVar1 = FUN_00403e10(uVar1);
  iVar2 = FUN_006d5e20(in_ECX + 5,uVar1);
  if (iVar2 != 0) {
    (**(code **)(*in_ECX + 0x508))(iVar2);
    (**(code **)(*in_ECX + 0xc))(0);
    return iVar2;
  }
  return 0;
}



// ??_GGPlayerInfo@@UAEPAXI@Z @ 0x006d6a00

void ___GGPlayerInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// ??_GGBallInfo@@UAEPAXI@Z @ 0x006db3e0

void ___GGBallInfo__UAEPAXI_Z(byte param_1)

{
  FUN_00430270();
  if ((param_1 & 1) != 0) {
    FUN_00430280();
  }
  return;
}



// uflow @ 0x0072acff

/* Library Function - Multiple Matches With Same Base Name
    protected: virtual unsigned short __thiscall std::basic_streambuf<unsigned short,struct
   std::char_traits<unsigned short> >::uflow(void)
    protected: virtual unsigned short __thiscall std::basic_streambuf<wchar_t,struct
   std::char_traits<wchar_t> >::uflow(void)
   
   Library: Visual Studio 2003 Release */

undefined2 uflow(void)

{
  short sVar1;
  undefined2 *puVar2;
  int *in_ECX;
  
  sVar1 = (**(code **)(*in_ECX + 0x10))();
  if (sVar1 == -1) {
    return 0xffff;
  }
  puVar2 = (undefined2 *)Gninc();
  return *puVar2;
}



// Gninc @ 0x0072b4a3

/* Library Function - Multiple Matches With Same Base Name
    protected: unsigned short * __thiscall std::basic_streambuf<unsigned short,struct
   std::char_traits<unsigned short> >::_Gninc(void)
    protected: wchar_t * __thiscall std::basic_streambuf<wchar_t,struct std::char_traits<wchar_t>
   >::_Gninc(void)
   
   Library: Visual Studio 2003 Release */

void Gninc(void)

{
  int in_ECX;
  
  **(int **)(in_ECX + 0x2c) = **(int **)(in_ECX + 0x2c) + -1;
  **(int **)(in_ECX + 0x1c) = **(int **)(in_ECX + 0x1c) + 2;
  return;
}



// operator_new @ 0x0073445e

/* Library Function - Single Match
    void * __cdecl operator new(unsigned int)
   
   Library: Visual Studio 2003 Release */

void * __cdecl operator_new(uint param_1)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(param_1,1);
  return pvVar1;
}



// _malloc @ 0x00734984

/* Library Function - Single Match
    _malloc
   
   Library: Visual Studio 2003 Release */

void * __cdecl _malloc(size_t _Size)

{
  void *pvVar1;
  
  pvVar1 = __nh_malloc(_Size,DAT_00d5b370);
  return pvVar1;
}



// _rand @ 0x007364d1

/* Library Function - Single Match
    _rand
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release, Visual Studio 2008 Release */

int __cdecl _rand(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_0073e48d();
  uVar2 = *(int *)(iVar1 + 0x14) * 0x343fd + 0x269ec3;
  *(uint *)(iVar1 + 0x14) = uVar2;
  return uVar2 >> 0x10 & 0x7fff;
}



// ~exception @ 0x007368ef

/* Library Function - Single Match
    public: virtual __thiscall exception::~exception(void)
   
   Libraries: Visual Studio 2003 Release, Visual Studio 2005 Release */

void __thiscall exception::~exception(exception *this)

{
  *(undefined ***)this = &vftable_exception;
  if (*(int *)(this + 8) != 0) {
    FUN_007290de(*(undefined4 *)(this + 4));
  }
  return;
}



// _memchr @ 0x00736990

/* Library Function - Single Match
    _memchr
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

void * __cdecl _memchr(void *_Buf,int _Val,size_t _MaxCount)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  char cVar5;
  uint uVar6;
  bool bVar7;
  
  if (_MaxCount == 0) {
    return (void *)0x0;
  }
  uVar6 = _Val & 0xff;
  while (((uint)_Buf & 3) != 0) {
    uVar2 = *(uint *)_Buf;
    _Buf = (void *)((int)_Buf + 1);
    if ((char)uVar2 == (char)_Val) goto LAB_00736a1e;
    _MaxCount = _MaxCount - 1;
    if (_MaxCount == 0) {
      return (void *)0x0;
    }
  }
  uVar2 = _MaxCount - 4;
  if (3 < _MaxCount) {
    uVar6 = uVar6 * 0x1010101;
    puVar4 = _Buf;
    do {
      _Buf = puVar4 + 1;
      if (((*puVar4 ^ uVar6 ^ 0xffffffff ^ (*puVar4 ^ uVar6) + 0x7efefeff) & 0x81010100) != 0) {
        uVar1 = *puVar4;
        cVar5 = (char)uVar6;
        if ((char)uVar1 == cVar5) {
          return puVar4;
        }
        if ((char)(uVar1 >> 8) == cVar5) {
          return (char *)((int)puVar4 + 1);
        }
        if ((char)(uVar1 >> 0x10) == cVar5) {
          return (char *)((int)puVar4 + 2);
        }
        if ((char)(uVar1 >> 0x18) == cVar5) goto LAB_00736a1e;
      }
      bVar7 = 3 < uVar2;
      uVar2 = uVar2 - 4;
      puVar4 = _Buf;
    } while (bVar7);
  }
  iVar3 = uVar2 + 4;
  while( true ) {
    if (iVar3 == 0) {
      return (void *)0x0;
    }
    uVar2 = *(uint *)_Buf;
    _Buf = (void *)((int)_Buf + 1);
    if ((char)uVar2 == (char)uVar6) break;
    iVar3 = iVar3 + -1;
  }
LAB_00736a1e:
  return (char *)((int)_Buf + -1);
}



// _strncpy @ 0x00736d00

/* Library Function - Single Match
    _strncpy
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strncpy(char *_Dest,char *_Source,size_t _Count)

{
  uint uVar1;
  uint uVar2;
  char cVar3;
  uint uVar4;
  uint *puVar5;
  
  if (_Count == 0) {
    return _Dest;
  }
  puVar5 = (uint *)_Dest;
  if (((uint)_Source & 3) != 0) {
    while( true ) {
      uVar4 = *(uint *)_Source;
      _Source = (char *)((int)_Source + 1);
      *(char *)puVar5 = (char)uVar4;
      puVar5 = (uint *)((int)puVar5 + 1);
      _Count = _Count - 1;
      if (_Count == 0) {
        return _Dest;
      }
      if ((char)uVar4 == '\0') break;
      if (((uint)_Source & 3) == 0) {
        uVar4 = _Count >> 2;
        goto joined_r0x00736d3e;
      }
    }
    do {
      if (((uint)puVar5 & 3) == 0) {
        uVar4 = _Count >> 2;
        cVar3 = '\0';
        if (uVar4 == 0) goto LAB_00736d7b;
        goto LAB_00736de9;
      }
      *(char *)puVar5 = '\0';
      puVar5 = (uint *)((int)puVar5 + 1);
      _Count = _Count - 1;
    } while (_Count != 0);
    return _Dest;
  }
  uVar4 = _Count >> 2;
  if (uVar4 != 0) {
    do {
      uVar1 = *(uint *)_Source;
      uVar2 = *(uint *)_Source;
      _Source = (char *)((int)_Source + 4);
      if (((uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff) & 0x81010100) != 0) {
        if ((char)uVar2 == '\0') {
          *puVar5 = 0;
joined_r0x00736de5:
          while( true ) {
            uVar4 = uVar4 - 1;
            puVar5 = puVar5 + 1;
            if (uVar4 == 0) break;
LAB_00736de9:
            *puVar5 = 0;
          }
          cVar3 = '\0';
          _Count = _Count & 3;
          if (_Count != 0) goto LAB_00736d7b;
          return _Dest;
        }
        if ((char)(uVar2 >> 8) == '\0') {
          *puVar5 = uVar2 & 0xff;
          goto joined_r0x00736de5;
        }
        if ((uVar2 & 0xff0000) == 0) {
          *puVar5 = uVar2 & 0xffff;
          goto joined_r0x00736de5;
        }
        if ((uVar2 & 0xff000000) == 0) {
          *puVar5 = uVar2;
          goto joined_r0x00736de5;
        }
      }
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
      uVar4 = uVar4 - 1;
joined_r0x00736d3e:
    } while (uVar4 != 0);
    _Count = _Count & 3;
    if (_Count == 0) {
      return _Dest;
    }
  }
  do {
    cVar3 = (char)*(uint *)_Source;
    _Source = (char *)((int)_Source + 1);
    *(char *)puVar5 = cVar3;
    puVar5 = (uint *)((int)puVar5 + 1);
    if (cVar3 == '\0') {
      while (_Count = _Count - 1, _Count != 0) {
LAB_00736d7b:
        *(char *)puVar5 = cVar3;
        puVar5 = (uint *)((int)puVar5 + 1);
      }
      return _Dest;
    }
    _Count = _Count - 1;
  } while (_Count != 0);
  return _Dest;
}



// _strncmp @ 0x00736e00

/* Library Function - Single Match
    _strncmp
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl _strncmp(char *_Str1,char *_Str2,size_t _MaxCount)

{
  char cVar1;
  char cVar2;
  size_t sVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  
  uVar5 = 0;
  sVar3 = _MaxCount;
  pcVar6 = _Str1;
  if (_MaxCount != 0) {
    do {
      if (sVar3 == 0) break;
      sVar3 = sVar3 - 1;
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    iVar4 = _MaxCount - sVar3;
    do {
      pcVar6 = _Str2;
      pcVar7 = _Str1;
      if (iVar4 == 0) break;
      iVar4 = iVar4 + -1;
      pcVar7 = _Str1 + 1;
      pcVar6 = _Str2 + 1;
      cVar2 = *_Str1;
      cVar1 = *_Str2;
      _Str2 = pcVar6;
      _Str1 = pcVar7;
    } while (cVar1 == cVar2);
    uVar5 = 0;
    if ((byte)pcVar6[-1] <= (byte)pcVar7[-1]) {
      if (pcVar6[-1] == pcVar7[-1]) {
        return 0;
      }
      uVar5 = 0xfffffffe;
    }
    uVar5 = ~uVar5;
  }
  return uVar5;
}



// _strchr @ 0x00736e50

/* Library Function - Single Match
    _strchr
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strchr(char *_Str,int _Val)

{
  uint uVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  while (((uint)_Str & 3) != 0) {
    uVar1 = *(uint *)_Str;
    if ((char)uVar1 == (char)_Val) {
      return (char *)(uint *)_Str;
    }
    _Str = (char *)((int)_Str + 1);
    if ((char)uVar1 == '\0') {
      return (char *)0x0;
    }
  }
  while( true ) {
    while( true ) {
      uVar1 = *(uint *)_Str;
      uVar4 = uVar1 ^ CONCAT22(CONCAT11((char)_Val,(char)_Val),CONCAT11((char)_Val,(char)_Val));
      uVar3 = uVar1 ^ 0xffffffff ^ uVar1 + 0x7efefeff;
      puVar5 = (uint *)((int)_Str + 4);
      if (((uVar4 ^ 0xffffffff ^ uVar4 + 0x7efefeff) & 0x81010100) != 0) break;
      _Str = (char *)puVar5;
      if ((uVar3 & 0x81010100) != 0) {
        if ((uVar3 & 0x1010100) != 0) {
          return (char *)0x0;
        }
        if ((uVar1 + 0x7efefeff & 0x80000000) == 0) {
          return (char *)0x0;
        }
      }
    }
    uVar1 = *(uint *)_Str;
    if ((char)uVar1 == (char)_Val) {
      return (char *)(uint *)_Str;
    }
    if ((char)uVar1 == '\0') {
      return (char *)0x0;
    }
    cVar2 = (char)(uVar1 >> 8);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 1);
    }
    if (cVar2 == '\0') {
      return (char *)0x0;
    }
    cVar2 = (char)(uVar1 >> 0x10);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 2);
    }
    if (cVar2 == '\0') break;
    cVar2 = (char)(uVar1 >> 0x18);
    if (cVar2 == (char)_Val) {
      return (char *)((int)_Str + 3);
    }
    _Str = (char *)puVar5;
    if (cVar2 == '\0') {
      return (char *)0x0;
    }
  }
  return (char *)0x0;
}



// _strstr @ 0x00737180

/* Library Function - Single Match
    _strstr
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strstr(char *_Str,char *_SubStr)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  uint uVar4;
  char cVar5;
  uint uVar6;
  uint uVar7;
  char *pcVar8;
  uint *puVar9;
  char *pcVar10;
  
  cVar3 = *_SubStr;
  if (cVar3 == '\0') {
    return _Str;
  }
  if (_SubStr[1] == '\0') {
    while (((uint)_Str & 3) != 0) {
      uVar4 = *(uint *)_Str;
      if ((char)uVar4 == cVar3) {
        return (char *)(uint *)_Str;
      }
      _Str = (char *)((int)_Str + 1);
      if ((char)uVar4 == '\0') {
        return (char *)0x0;
      }
    }
    while( true ) {
      while( true ) {
        uVar4 = *(uint *)_Str;
        uVar7 = uVar4 ^ CONCAT22(CONCAT11(cVar3,cVar3),CONCAT11(cVar3,cVar3));
        uVar6 = uVar4 ^ 0xffffffff ^ uVar4 + 0x7efefeff;
        puVar9 = (uint *)((int)_Str + 4);
        if (((uVar7 ^ 0xffffffff ^ uVar7 + 0x7efefeff) & 0x81010100) != 0) break;
        _Str = (char *)puVar9;
        if ((uVar6 & 0x81010100) != 0) {
          if ((uVar6 & 0x1010100) != 0) {
            return (char *)0x0;
          }
          if ((uVar4 + 0x7efefeff & 0x80000000) == 0) {
            return (char *)0x0;
          }
        }
      }
      uVar4 = *(uint *)_Str;
      if ((char)uVar4 == cVar3) {
        return (char *)(uint *)_Str;
      }
      if ((char)uVar4 == '\0') {
        return (char *)0x0;
      }
      cVar5 = (char)(uVar4 >> 8);
      if (cVar5 == cVar3) {
        return (char *)((int)_Str + 1);
      }
      if (cVar5 == '\0') {
        return (char *)0x0;
      }
      cVar5 = (char)(uVar4 >> 0x10);
      if (cVar5 == cVar3) {
        return (char *)((int)_Str + 2);
      }
      if (cVar5 == '\0') break;
      cVar5 = (char)(uVar4 >> 0x18);
      if (cVar5 == cVar3) {
        return (char *)((int)_Str + 3);
      }
      _Str = (char *)puVar9;
      if (cVar5 == '\0') {
        return (char *)0x0;
      }
    }
    return (char *)0x0;
  }
  do {
    cVar5 = *_Str;
    do {
      while (_Str = _Str + 1, cVar5 != cVar3) {
        if (cVar5 == '\0') {
          return (char *)0x0;
        }
        cVar5 = *_Str;
      }
      cVar5 = *_Str;
      pcVar10 = _Str + 1;
      pcVar8 = _SubStr;
    } while (cVar5 != _SubStr[1]);
    do {
      if (pcVar8[2] == '\0') {
LAB_007371f3:
        return _Str + -1;
      }
      if (*pcVar10 != pcVar8[2]) break;
      pcVar1 = pcVar8 + 3;
      if (*pcVar1 == '\0') goto LAB_007371f3;
      pcVar2 = pcVar10 + 1;
      pcVar8 = pcVar8 + 2;
      pcVar10 = pcVar10 + 2;
    } while (*pcVar1 == *pcVar2);
  } while( true );
}



// _strrchr @ 0x007376c0

/* Library Function - Single Match
    _strrchr
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

char * __cdecl _strrchr(char *_Str,int _Ch)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  
  iVar2 = -1;
  do {
    pcVar4 = _Str;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar4 = _Str + 1;
    cVar1 = *_Str;
    _Str = pcVar4;
  } while (cVar1 != '\0');
  iVar2 = -(iVar2 + 1);
  pcVar4 = pcVar4 + -1;
  do {
    pcVar3 = pcVar4;
    if (iVar2 == 0) break;
    iVar2 = iVar2 + -1;
    pcVar3 = pcVar4 + -1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar3;
  } while ((char)_Ch != cVar1);
  pcVar3 = pcVar3 + 1;
  if (*pcVar3 != (char)_Ch) {
    pcVar3 = (char *)0x0;
  }
  return pcVar3;
}



// entry @ 0x00737b8e

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00ee516b) overlaps instruction at (ram,0x00ee516a)
    */
/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0x00ee51a9) */
/* WARNING: Removing unreachable block (ram,0x00ee5164) */
/* WARNING: Removing unreachable block (ram,0x00ee5144) */
/* WARNING: Removing unreachable block (ram,0x00ee5149) */
/* WARNING: Removing unreachable block (ram,0x00ee5147) */
/* WARNING: Removing unreachable block (ram,0x00ee5155) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 entry(void)

{
  uint *puVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  code *pcVar4;
  undefined6 uVar5;
  undefined1 uVar6;
  char cVar7;
  byte bVar8;
  byte bVar9;
  undefined3 uVar15;
  uint uVar10;
  uint uVar11;
  int *piVar13;
  int iVar14;
  int in_ECX;
  int extraout_ECX;
  undefined2 uVar16;
  byte *in_EDX;
  uint *puVar17;
  byte bVar19;
  uint *puVar18;
  undefined4 *puVar20;
  undefined4 *puVar21;
  undefined4 *puVar22;
  int *piVar23;
  short sVar24;
  int unaff_ESI;
  char *pcVar25;
  char *pcVar26;
  uint *unaff_EDI;
  char *pcVar27;
  char *pcVar28;
  undefined2 in_DS;
  bool bVar29;
  bool bVar30;
  byte in_AF;
  float10 extraout_ST0;
  float10 fVar31;
  undefined8 uVar32;
  void *pvStack_14;
  undefined1 *puStack_10;
  undefined *puStack_c;
  undefined4 uStack_8;
  int *piVar12;
  
  uStack_8 = 0xffffffff;
  puStack_c = &DAT_008d64f8;
  puStack_10 = &LAB_0073ae3c;
  pvStack_14 = ExceptionList;
  uVar15 = (undefined3)((uint)ExceptionList >> 8);
  uVar16 = SUB42(in_EDX,0);
  uVar6 = in(uVar16);
  uVar11 = CONCAT31(uVar15,uVar6);
  piVar23 = (int *)(unaff_ESI * -0x6c75ce6);
  puVar18 = (uint *)(in_ECX + 0x45 + (int)in_EDX * 2);
  ExceptionList = &pvStack_14;
  *puVar18 = *puVar18 >> 1;
  out(*(undefined4 *)(unaff_ESI + -1),uVar16);
  out(0xf1,uVar6);
  *(int *)(uVar11 + 0x8c051b12) = *(int *)(uVar11 + 0x8c051b12) << 0x13;
  sVar24 = (short)(unaff_ESI + 3);
  puVar2 = (undefined1 *)segment(in_DS,sVar24);
  iVar14 = CONCAT22((short)((uint)(unaff_ESI + 3) >> 0x10),sVar24 + 1);
  out(*puVar2,uVar16);
  bVar19 = (byte)((uint)unaff_EDI >> 8);
  bVar8 = (byte)in_ECX - bVar19;
  uVar6 = in(uVar16);
  uVar10 = CONCAT31(uVar15,uVar6);
  bVar9 = (bVar8 - (uVar11 < *unaff_EDI)) + 1;
  bVar29 = 0xe1072f34 < uVar10 ||
           CARRY4(uVar10 + 0x1ef8d0cb,(uint)((byte)in_ECX < bVar19 || bVar8 < (uVar11 < *unaff_EDI))
                 );
  bVar30 = CARRY1(*in_EDX,bVar9) || CARRY1(*in_EDX + bVar9,bVar29);
  *in_EDX = *in_EDX + bVar9 + bVar29;
  puVar18 = unaff_EDI;
  if (*in_EDX != 0) {
    pcVar4 = (code *)swi(0x51);
    uVar32 = (*pcVar4)();
    puVar18 = (uint *)uVar32;
    uVar5 = *(undefined6 *)(extraout_ECX + -0x6d);
    _DAT_a34f3d52 = (int)unaff_EDI + 5;
    *(char *)(iVar14 + -0x333e17e0) = (char)((ulonglong)uVar32 >> 8);
    uVar11 = CONCAT22((short)((ulonglong)uVar32 >> 0x30),
                      CONCAT11(0xec,(byte)((ulonglong)uVar32 >> 0x20) % 0xf9)) & _DAT_a34f3d52;
    cVar7 = (char)uVar11 + '=';
    piVar12 = (int *)CONCAT31((int3)(uVar11 >> 8),cVar7);
    _DAT_a34f3d56 = iVar14;
    if ((int)uVar5 != 1 && cVar7 != '\0') {
      *piVar12 = *piVar12 << 5;
      iVar14 = (int)piVar12 + -0x48fe6d53;
      uVar16 = _DAT_a34f3d52;
      puVar20 = (undefined4 *)&DAT_a34f3d56;
      fVar31 = extraout_ST0;
      do {
        *(undefined2 *)((int)puVar20 + -4) = uVar16;
        *(char *)(*piVar23 + 0x1839e613) =
             *(char *)(*piVar23 + 0x1839e613) - (char)((uint)iVar14 >> 8);
        *piVar23 = iVar14;
        uVar11 = puVar18[-0x12] & (uint)piVar23;
        puVar22 = (undefined4 *)*piVar23;
        pcVar27 = (char *)*puVar22;
        pcVar25 = (char *)puVar22[1];
        piVar23 = (int *)puVar22[2];
        puVar18 = (uint *)puVar22[4];
        puVar17 = (uint *)puVar22[5];
        iVar14 = puVar22[6];
        if (uVar11 != 0) {
          out(*(undefined4 *)pcVar25,(short)puVar17);
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        piVar12 = (int *)(puVar22[7] ^ 0xe0);
        *(uint *)((int)piVar12 + -0x37) = *(uint *)((int)piVar12 + -0x37) | (uint)(puVar22 + 8);
        puVar22[7] = piVar12;
        puVar22[6] = iVar14;
        puVar22[5] = puVar17;
        puVar22[4] = puVar18;
        puVar22[3] = puVar22 + 8;
        puVar22[2] = piVar23;
        puVar22[1] = pcVar25;
        *puVar22 = pcVar27;
        pcVar28 = pcVar27 + 1;
        pcVar26 = pcVar25 + 1;
        bVar8 = *pcVar25 - *pcVar27;
        if ((POPCOUNT(bVar8) & 1U) == 0) {
          fVar31 = (float10)*(float *)(pcVar25 + 0x49551229) / fVar31;
          piVar13 = piVar12;
        }
        else {
          while( true ) {
            if (iVar14 - 1U == 0 || bVar8 == 0) {
              return fVar31;
            }
            uVar11 = iVar14 - 1U & *puVar17;
            puVar18 = (uint *)CONCAT31((int3)((uint)puVar18 >> 8),0x91);
            puVar1 = (uint *)(uVar11 + 0x2ed90a23);
            *puVar1 = *puVar1 ^ (uint)puVar17;
            in_AF = 9 < ((byte)piVar12 & 0xf) | in_AF;
            bVar8 = (byte)piVar12 + in_AF * -6;
            bVar8 = bVar8 + (0x9f < bVar8 | in_AF * (bVar8 < 6)) * -0x60;
            puVar21 = (undefined4 *)((uint)puVar22 & (uint)pcVar26);
            uVar11 = CONCAT31((int3)(uVar11 >> 8),puVar21 != (undefined4 *)0x0);
            uVar15 = (undefined3)
                     (CONCAT22((short)((uint)piVar12 >> 0x10),CONCAT11(bVar8 / 0x56,bVar8)) >> 8);
            in_AF = 9 < (bVar8 % 0x56 & 0xf) | in_AF;
            bVar9 = bVar8 % 0x56 + in_AF * '\x06';
            bVar9 = bVar9 + (0x90 < (bVar9 & 0xf0) | in_AF * (0xf9 < bVar9)) * '`';
            piVar12 = (int *)*puVar21;
            puVar22 = puVar21 + 1;
            iVar14 = 0;
            piVar13 = (int *)CONCAT31(uVar15,bVar9);
            piVar23 = piVar12;
            if (uVar11 == 0) break;
            uVar11 = uVar11 ^ *(uint *)((int)puVar18 + -0x23f401c1);
            bVar29 = uVar11 != 0;
            pcVar26 = (char *)0x1f5dac1f;
            while (uVar11 != 0) {
              uVar11 = uVar11 - 1;
              uVar3 = in((short)puVar17);
              *(undefined4 *)pcVar28 = uVar3;
              pcVar28 = pcVar28 + 4;
            }
            puVar17 = (uint *)0x13c55b25;
            iVar14 = -1;
            if (bVar29) {
                    /* WARNING: Bad instruction - Truncating control flow here */
              halt_baddata();
            }
            bVar8 = bVar9 & 0x83;
            puVar22 = (undefined4 *)((CONCAT31(uVar15,bVar9) & 0xffffff83) + 4);
          }
        }
        iVar14 = CONCAT31((int3)((uint)piVar13 >> 8),
                          (char)piVar13 - *(char *)(iVar14 + 0x2d4f2520 + (int)piVar13 * 8));
        puVar20 = puVar22 + -1;
        puVar22[-1] = puVar18;
        uVar3 = in((short)puVar17);
        *(undefined4 *)(pcVar28 + 1) = uVar3;
        *(char *)(iVar14 + 0x17) = *(char *)(iVar14 + 0x17) + -1;
      } while( true );
    }
    bVar30 = false;
    bVar9 = (byte)_DAT_a34f3d52;
  }
  *(char *)((int)puVar18 + -0x25) = *(char *)((int)puVar18 + -0x25) + bVar9 + bVar30;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}



// _strlen @ 0x00737ce0

/* Library Function - Single Match
    _strlen
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

size_t __cdecl _strlen(char *_Str)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  
  puVar2 = (uint *)_Str;
  do {
    if (((uint)puVar2 & 3) == 0) goto LAB_00737d00;
    uVar1 = *puVar2;
    puVar2 = (uint *)((int)puVar2 + 1);
  } while ((char)uVar1 != '\0');
LAB_00737d33:
  return (size_t)((int)puVar2 + (-1 - (int)_Str));
LAB_00737d00:
  do {
    do {
      puVar3 = puVar2;
      puVar2 = puVar3 + 1;
    } while (((*puVar3 ^ 0xffffffff ^ *puVar3 + 0x7efefeff) & 0x81010100) == 0);
    uVar1 = *puVar3;
    if ((char)uVar1 == '\0') {
      return (int)puVar3 - (int)_Str;
    }
    if ((char)(uVar1 >> 8) == '\0') {
      return (size_t)((int)puVar3 + (1 - (int)_Str));
    }
    if ((uVar1 & 0xff0000) == 0) {
      return (size_t)((int)puVar3 + (2 - (int)_Str));
    }
  } while ((uVar1 & 0xff000000) != 0);
  goto LAB_00737d33;
}



// _memset @ 0x007387f0

/* Library Function - Single Match
    _memset
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

void * __cdecl _memset(void *_Dst,int _Val,size_t _Size)

{
  uint uVar1;
  uint uVar2;
  size_t sVar3;
  uint *puVar4;
  
  if (_Size == 0) {
    return _Dst;
  }
  uVar1 = _Val & 0xff;
  puVar4 = _Dst;
  if (3 < _Size) {
    uVar2 = -(int)_Dst & 3;
    sVar3 = _Size;
    if (uVar2 != 0) {
      sVar3 = _Size - uVar2;
      do {
        *(undefined1 *)puVar4 = (undefined1)_Val;
        puVar4 = (uint *)((int)puVar4 + 1);
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    uVar1 = uVar1 * 0x1010101;
    _Size = sVar3 & 3;
    uVar2 = sVar3 >> 2;
    if (uVar2 != 0) {
      for (; uVar2 != 0; uVar2 = uVar2 - 1) {
        *puVar4 = uVar1;
        puVar4 = puVar4 + 1;
      }
      if (_Size == 0) {
        return _Dst;
      }
    }
  }
  do {
    *(char *)puVar4 = (char)uVar1;
    puVar4 = (uint *)((int)puVar4 + 1);
    _Size = _Size - 1;
  } while (_Size != 0);
  return _Dst;
}



// _strcmp @ 0x00739b40

/* Library Function - Single Match
    _strcmp
   
   Libraries: Visual Studio 1998 Debug, Visual Studio 1998 Release */

int __cdecl _strcmp(char *_Str1,char *_Str2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  byte bVar3;
  byte bVar4;
  bool bVar5;
  
  if (((uint)_Str1 & 3) != 0) {
    if (((uint)_Str1 & 1) != 0) {
      bVar4 = *_Str1;
      _Str1 = _Str1 + 1;
      bVar5 = bVar4 < (byte)*_Str2;
      if (bVar4 != *_Str2) goto LAB_00739b84;
      _Str2 = _Str2 + 1;
      if (bVar4 == 0) {
        return 0;
      }
      if (((uint)_Str1 & 2) == 0) goto LAB_00739b50;
    }
    uVar1 = *(undefined2 *)_Str1;
    _Str1 = _Str1 + 2;
    bVar4 = (byte)uVar1;
    bVar5 = bVar4 < (byte)*_Str2;
    if (bVar4 != *_Str2) goto LAB_00739b84;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((ushort)uVar1 >> 8);
    bVar5 = bVar4 < (byte)_Str2[1];
    if (bVar4 != _Str2[1]) goto LAB_00739b84;
    if (bVar4 == 0) {
      return 0;
    }
    _Str2 = _Str2 + 2;
  }
LAB_00739b50:
  while( true ) {
    uVar2 = *(undefined4 *)_Str1;
    bVar4 = (byte)uVar2;
    bVar5 = bVar4 < (byte)*_Str2;
    if (bVar4 != *_Str2) break;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((uint)uVar2 >> 8);
    bVar5 = bVar4 < (byte)_Str2[1];
    if (bVar4 != _Str2[1]) break;
    if (bVar4 == 0) {
      return 0;
    }
    bVar4 = (byte)((uint)uVar2 >> 0x10);
    bVar5 = bVar4 < (byte)_Str2[2];
    if (bVar4 != _Str2[2]) break;
    bVar3 = (byte)((uint)uVar2 >> 0x18);
    if (bVar4 == 0) {
      return 0;
    }
    bVar5 = bVar3 < (byte)_Str2[3];
    if (bVar3 != _Str2[3]) break;
    _Str2 = _Str2 + 4;
    _Str1 = _Str1 + 4;
    if (bVar3 == 0) {
      return 0;
    }
  }
LAB_00739b84:
  return (uint)bVar5 * -2 + 1;
}



// Unwind@007e9440 @ 0x007e9440

void Unwind_007e9440(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Unwind@007e9458 @ 0x007e9458

void Unwind_007e9458(void)

{
  FUN_007294ae();
  return;
}



// Unwind@007e946c @ 0x007e946c

void Unwind_007e946c(void)

{
  int unaff_EBP;
  
  exception::~exception(*(exception **)(unaff_EBP + -0x14));
  return;
}



// Unwind@007e9480 @ 0x007e9480

void Unwind_007e9480(void)

{
  int unaff_EBP;
  
  exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Unwind@007e9494 @ 0x007e9494

void Unwind_007e9494(void)

{
  int unaff_EBP;
  
  exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Unwind@007e94a8 @ 0x007e94a8

void Unwind_007e94a8(void)

{
  int unaff_EBP;
  
  exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Unwind@007e94bc @ 0x007e94bc

void Unwind_007e94bc(void)

{
  FUN_007294ae();
  return;
}



// Unwind@007e94d0 @ 0x007e94d0

void Unwind_007e94d0(void)

{
  int unaff_EBP;
  
  exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Unwind@007e94e4 @ 0x007e94e4

void Unwind_007e94e4(void)

{
  FUN_007294ae();
  return;
}



// Unwind@007e94f8 @ 0x007e94f8

void Unwind_007e94f8(void)

{
  int unaff_EBP;
  
  exception::~exception(*(exception **)(unaff_EBP + -0x14));
  return;
}



// Unwind@007e950c @ 0x007e950c

void Unwind_007e950c(void)

{
  int unaff_EBP;
  
  exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Unwind@007e9520 @ 0x007e9520

void Unwind_007e9520(void)

{
  int unaff_EBP;
  
  exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Unwind@007e9534 @ 0x007e9534

void Unwind_007e9534(void)

{
  int unaff_EBP;
  
  exception::~exception(*(exception **)(unaff_EBP + -0x10));
  return;
}



// Unwind@007e9548 @ 0x007e9548

void Unwind_007e9548(void)

{
  FUN_0054bfc0();
  return;
}



// Unwind@007e9560 @ 0x007e9560

void Unwind_007e9560(void)

{
  FUN_00729185();
  return;
}



// Unwind@007e9568 @ 0x007e9568

void Unwind_007e9568(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x14));
  return;
}



// Unwind@007e957c @ 0x007e957c

void Unwind_007e957c(void)

{
  FUN_00729185();
  return;
}



// Unwind@007e9590 @ 0x007e9590

void Unwind_007e9590(void)

{
  FUN_00729afc();
  return;
}



// Unwind@007e95a4 @ 0x007e95a4

void Unwind_007e95a4(void)

{
  FUN_00729afc();
  return;
}



// Unwind@007e95ac @ 0x007e95ac

void Unwind_007e95ac(void)

{
  FUN_007294ae();
  return;
}



// Unwind@007e95b7 @ 0x007e95b7

void Unwind_007e95b7(void)

{
  FUN_00729185();
  return;
}



// Unwind@007e95cc @ 0x007e95cc

void Unwind_007e95cc(void)

{
  FUN_007294ae();
  return;
}



// Unwind@007e95d4 @ 0x007e95d4

void Unwind_007e95d4(void)

{
  FUN_007294ae();
  return;
}



// Unwind@007e95df @ 0x007e95df

void Unwind_007e95df(void)

{
  FUN_007294ae();
  return;
}



// Unwind@007e95ea @ 0x007e95ea

void Unwind_007e95ea(void)

{
  FUN_007294ae();
  return;
}



// Unwind@007e9600 @ 0x007e9600

void Unwind_007e9600(void)

{
  FUN_007294ae();
  return;
}



// Unwind@007e9608 @ 0x007e9608

void Unwind_007e9608(void)

{
  FUN_007294ae();
  return;
}



// Unwind@007e9613 @ 0x007e9613

void Unwind_007e9613(void)

{
  FUN_007294ae();
  return;
}



// Unwind@007e9628 @ 0x007e9628

void Unwind_007e9628(void)

{
  int unaff_EBP;
  
  FUN_0072a065(*(undefined4 *)(unaff_EBP + -0x10),&DAT_00d5ad90);
  return;
}



// Unwind@007e9638 @ 0x007e9638

void Unwind_007e9638(void)

{
  int unaff_EBP;
  
  FUN_0072a065(*(undefined4 *)(unaff_EBP + -0x10),&DAT_00d5ac68);
  return;
}



// Unwind@007e9648 @ 0x007e9648

void Unwind_007e9648(void)

{
  int unaff_EBP;
  
  FUN_0072a065(*(undefined4 *)(unaff_EBP + -0x10),&DAT_00d5ad50);
  return;
}



// Unwind@007e9658 @ 0x007e9658

void Unwind_007e9658(void)

{
  int unaff_EBP;
  
  FUN_0072a065(*(undefined4 *)(unaff_EBP + -0x10),&DAT_00d5acc0);
  return;
}



// Unwind@007e9668 @ 0x007e9668

void Unwind_007e9668(void)

{
  int unaff_EBP;
  
  FUN_0072a065(*(undefined4 *)(unaff_EBP + -0x10),&DAT_00d5acf8);
  return;
}



// Unwind@007e9678 @ 0x007e9678

void Unwind_007e9678(void)

{
  int unaff_EBP;
  
  FUN_0072a065(*(undefined4 *)(unaff_EBP + -0x10),&DAT_00d5ade8);
  return;
}



// Unwind@007e9688 @ 0x007e9688

void Unwind_007e9688(void)

{
  int unaff_EBP;
  
  FUN_0072a065(*(undefined4 *)(unaff_EBP + -0x10),&DAT_00d5ac30);
  return;
}



// Unwind@007e96a4 @ 0x007e96a4

void Unwind_007e96a4(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    FUN_00551690();
    return;
  }
  return;
}



// Unwind@007e96c8 @ 0x007e96c8

void Unwind_007e96c8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    FUN_00551690();
    return;
  }
  return;
}



// Unwind@007e96ec @ 0x007e96ec

void Unwind_007e96ec(void)

{
  FUN_0054bfc0();
  return;
}



// Unwind@007e96f7 @ 0x007e96f7

void Unwind_007e96f7(void)

{
  FUN_0054b660();
  return;
}



// Unwind@007e96ff @ 0x007e96ff

void Unwind_007e96ff(void)

{
  FUN_0054bfc0();
  return;
}



// Unwind@007e9714 @ 0x007e9714

void Unwind_007e9714(void)

{
  FUN_0054b660();
  return;
}



// Unwind@007e971c @ 0x007e971c

void Unwind_007e971c(void)

{
  FUN_0054bfc0();
  return;
}



// Unwind@007e9734 @ 0x007e9734

void Unwind_007e9734(void)

{
  int unaff_EBP;
  
  FUN_0072a065(*(undefined4 *)(unaff_EBP + -0x10),&DAT_00d5af30);
  return;
}



// Unwind@007e9744 @ 0x007e9744

void Unwind_007e9744(void)

{
  int unaff_EBP;
  
  FUN_0072a065(*(undefined4 *)(unaff_EBP + -0x10),&DAT_00d5aed8);
  return;
}



// Unwind@007e9754 @ 0x007e9754

void Unwind_007e9754(void)

{
  int unaff_EBP;
  
  FUN_0072a065(*(undefined4 *)(unaff_EBP + -0x10),&DAT_00d5afc0);
  return;
}



// Unwind@007e9764 @ 0x007e9764

void Unwind_007e9764(void)

{
  int unaff_EBP;
  
  FUN_0072a065(*(undefined4 *)(unaff_EBP + -0x10),&DAT_00d5ae98);
  return;
}



// Unwind@007e9774 @ 0x007e9774

void Unwind_007e9774(void)

{
  int unaff_EBP;
  
  FUN_0072a065(*(undefined4 *)(unaff_EBP + -0x10),&DAT_00d5af88);
  return;
}



// Unwind@007e9784 @ 0x007e9784

void Unwind_007e9784(void)

{
  int unaff_EBP;
  
  FUN_0072a065(*(undefined4 *)(unaff_EBP + -0x10),&DAT_00d5ae20);
  return;
}



// Unwind@007e9794 @ 0x007e9794

void Unwind_007e9794(void)

{
  int unaff_EBP;
  
  FUN_0072a065(*(undefined4 *)(unaff_EBP + -0x10),&DAT_00d5ae60);
  return;
}



// Unwind@007e97b0 @ 0x007e97b0

void Unwind_007e97b0(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    FUN_0072abb3();
    return;
  }
  return;
}



// Unwind@007e97d4 @ 0x007e97d4

void Unwind_007e97d4(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    FUN_0072abb3();
    return;
  }
  return;
}



// Unwind@007e97f8 @ 0x007e97f8

void Unwind_007e97f8(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    FUN_0072abb3();
    return;
  }
  return;
}



// Unwind@007e981c @ 0x007e981c

void Unwind_007e981c(void)

{
  int unaff_EBP;
  
  if ((*(uint *)(unaff_EBP + -0x10) & 1) != 0) {
    FUN_0072abb3();
    return;
  }
  return;
}



// Unwind@007e9840 @ 0x007e9840

void Unwind_007e9840(void)

{
  FUN_0054bfc0();
  return;
}



// Unwind@007e984b @ 0x007e984b

void Unwind_007e984b(void)

{
  FUN_0072ace5();
  return;
}



// Unwind@007e9853 @ 0x007e9853

void Unwind_007e9853(void)

{
  FUN_0054bfc0();
  return;
}



// Unwind@007e9868 @ 0x007e9868

void Unwind_007e9868(void)

{
  FUN_0072ace5();
  return;
}



// Unwind@007e9870 @ 0x007e9870

void Unwind_007e9870(void)

{
  FUN_0054bfc0();
  return;
}



// Unwind@007e9890 @ 0x007e9890

void Unwind_007e9890(void)

{
  FUN_0072c040();
  return;
}



// Unwind@007e98b0 @ 0x007e98b0

void Unwind_007e98b0(void)

{
  FUN_0072c040();
  return;
}



// Unwind@007e98d0 @ 0x007e98d0

void Unwind_007e98d0(void)

{
  FUN_0072c040();
  return;
}



// Unwind@007e98f0 @ 0x007e98f0

void Unwind_007e98f0(void)

{
  _CleanUpForSerialisation_Base__UAEXXZ();
  return;
}



// Unwind@007e9910 @ 0x007e9910

void Unwind_007e9910(void)

{
  FUN_00748a90();
  return;
}



// Unwind@007e9930 @ 0x007e9930

void Unwind_007e9930(void)

{
  int unaff_EBP;
  
  FUN_00746d80(*(undefined4 *)(unaff_EBP + 4),s_C__DEV_Libs_LIONHEAD_lhlib_VER5__00b536ac,0xc1);
  return;
}



// Unwind@007e9960 @ 0x007e9960

void Unwind_007e9960(void)

{
  _CleanUpForSerialisation_Base__UAEXXZ();
  return;
}



// Unwind@007e9980 @ 0x007e9980

void Unwind_007e9980(void)

{
  FUN_0074a590();
  return;
}



// Unwind@007e99a0 @ 0x007e99a0

void Unwind_007e99a0(void)

{
  int unaff_EBP;
  
  FUN_00746d80(*(undefined4 *)(unaff_EBP + 4),s_C__DEV_Libs_LIONHEAD_lhlib_VER5__00b562b0,0x1b9);
  return;
}



// Unwind@007e99d0 @ 0x007e99d0

void Unwind_007e99d0(void)

{
  int unaff_EBP;
  
  FUN_0074c580(*(undefined4 *)(unaff_EBP + 4),s_C__DEV_Libs_LIONHEAD_lhlib_VER5__00b562f4,0x14a);
  return;
}



// Unwind@007e9a00 @ 0x007e9a00

void Unwind_007e9a00(void)

{
  FUN_0072c040();
  return;
}



// Unwind@007e9a20 @ 0x007e9a20

void Unwind_007e9a20(void)

{
  int unaff_EBP;
  
  FUN_00746d80(*(undefined4 *)(unaff_EBP + 8),s_C__DEV_Libs_LIONHEAD_lhlib_VER5__00b56f0c,0x14d);
  return;
}



// Unwind@007e9a37 @ 0x007e9a37

void Unwind_007e9a37(void)

{
  int unaff_EBP;
  
  FUN_00746d80(*(undefined4 *)(unaff_EBP + 8),s_C__DEV_Libs_LIONHEAD_lhlib_VER5__00b56f0c,0x163);
  return;
}



// Unwind@007e9a60 @ 0x007e9a60

void Unwind_007e9a60(void)

{
  FUN_0072c040();
  return;
}



// Unwind@007e9a80 @ 0x007e9a80

void Unwind_007e9a80(void)

{
  int unaff_EBP;
  
  FUN_00746d80(*(undefined4 *)(unaff_EBP + 8),s_C__DEV_Libs_LIONHEAD_lhlib_VER5__00b56f0c,0x14d);
  return;
}



// Unwind@007e9a97 @ 0x007e9a97

void Unwind_007e9a97(void)

{
  int unaff_EBP;
  
  FUN_00746d80(*(undefined4 *)(unaff_EBP + 8),s_C__DEV_Libs_LIONHEAD_lhlib_VER5__00b56f0c,0x163);
  return;
}



// Unwind@007e9ac0 @ 0x007e9ac0

void Unwind_007e9ac0(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Unwind@007e9ae0 @ 0x007e9ae0

void Unwind_007e9ae0(void)

{
  FUN_007531a0();
  return;
}



// Unwind@007e9b00 @ 0x007e9b00

void Unwind_007e9b00(void)

{
  FUN_00754910();
  return;
}



// Unwind@007e9b20 @ 0x007e9b20

void Unwind_007e9b20(void)

{
  FUN_007531a0();
  return;
}



// Unwind@007e9b28 @ 0x007e9b28

void Unwind_007e9b28(void)

{
  FUN_00754040();
  return;
}



// Unwind@007e9b40 @ 0x007e9b40

void Unwind_007e9b40(void)

{
  FUN_007531a0();
  return;
}



// Unwind@007e9b48 @ 0x007e9b48

void Unwind_007e9b48(void)

{
  FUN_00754040();
  return;
}



// Unwind@007e9b60 @ 0x007e9b60

void Unwind_007e9b60(void)

{
  FUN_00754940();
  return;
}



// Unwind@007e9b68 @ 0x007e9b68

void Unwind_007e9b68(void)

{
  FUN_0072b998();
  return;
}



// Unwind@007e9b70 @ 0x007e9b70

void Unwind_007e9b70(void)

{
  FUN_0072b998();
  return;
}



// Unwind@007e9b90 @ 0x007e9b90

void Unwind_007e9b90(void)

{
  FUN_007531a0();
  return;
}



// Unwind@007e9bb0 @ 0x007e9bb0

void Unwind_007e9bb0(void)

{
  int unaff_EBP;
  
  FUN_0072a065(*(undefined4 *)(unaff_EBP + -0x14),*(undefined4 *)(unaff_EBP + 4));
  return;
}



// Unwind@007e9bc1 @ 0x007e9bc1

void Unwind_007e9bc1(void)

{
  int unaff_EBP;
  
  FUN_0072a065(*(undefined4 *)(unaff_EBP + -0x10),*(undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Unwind@007e9be0 @ 0x007e9be0

void Unwind_007e9be0(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Unwind@007e9c00 @ 0x007e9c00

void Unwind_007e9c00(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + 4));
  return;
}



// Unwind@007e9c20 @ 0x007e9c20

void Unwind_007e9c20(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + 0x10));
  return;
}



// Unwind@007e9c40 @ 0x007e9c40

void Unwind_007e9c40(void)

{
  FUN_00758950();
  return;
}



// Unwind@007e9c60 @ 0x007e9c60

void Unwind_007e9c60(void)

{
  FUN_007589f0();
  return;
}



// Unwind@007e9c80 @ 0x007e9c80

void Unwind_007e9c80(void)

{
  FUN_007589f0();
  return;
}



// Unwind@007e9ca0 @ 0x007e9ca0

void Unwind_007e9ca0(void)

{
  _CleanUpForSerialisation_Base__UAEXXZ();
  return;
}



// Unwind@007e9cab @ 0x007e9cab

void Unwind_007e9cab(void)

{
  FUN_0072ce10();
  return;
}



// Unwind@007e9cb6 @ 0x007e9cb6

void Unwind_007e9cb6(void)

{
  thunk_FUN_0072ce10();
  return;
}



// Unwind@007e9cd0 @ 0x007e9cd0

void Unwind_007e9cd0(void)

{
  FUN_007cd380();
  return;
}



// Unwind@007e9cf0 @ 0x007e9cf0

void Unwind_007e9cf0(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Unwind@007e9cfb @ 0x007e9cfb

void Unwind_007e9cfb(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Unwind@007e9d06 @ 0x007e9d06

void Unwind_007e9d06(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Unwind@007e9d11 @ 0x007e9d11

void Unwind_007e9d11(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Unwind@007e9d1c @ 0x007e9d1c

void Unwind_007e9d1c(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Unwind@007e9d27 @ 0x007e9d27

void Unwind_007e9d27(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Unwind@007e9d32 @ 0x007e9d32

void Unwind_007e9d32(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Unwind@007e9d3d @ 0x007e9d3d

void Unwind_007e9d3d(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Unwind@007e9d48 @ 0x007e9d48

void Unwind_007e9d48(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Unwind@007e9d60 @ 0x007e9d60

void Unwind_007e9d60(void)

{
  FUN_007589f0();
  return;
}



// Unwind@007e9d80 @ 0x007e9d80

void Unwind_007e9d80(void)

{
  FUN_00758950();
  return;
}



// Unwind@007e9d88 @ 0x007e9d88

void Unwind_007e9d88(void)

{
  FUN_007589f0();
  return;
}



// Unwind@007e9da0 @ 0x007e9da0

void Unwind_007e9da0(void)

{
  FUN_007719d0();
  return;
}



// Unwind@007e9da8 @ 0x007e9da8

void Unwind_007e9da8(void)

{
  FUN_007589f0();
  return;
}



// Unwind@007e9dc0 @ 0x007e9dc0

void Unwind_007e9dc0(void)

{
  FUN_007589f0();
  return;
}



// Unwind@007e9de0 @ 0x007e9de0

void Unwind_007e9de0(void)

{
  FUN_00758950();
  return;
}



// Unwind@007e9de8 @ 0x007e9de8

void Unwind_007e9de8(void)

{
  FUN_007589f0();
  return;
}



// Unwind@007e9e00 @ 0x007e9e00

void Unwind_007e9e00(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + 4));
  return;
}



// Unwind@007e9e0b @ 0x007e9e0b

void Unwind_007e9e0b(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + 4));
  return;
}



// Unwind@007e9e20 @ 0x007e9e20

void Unwind_007e9e20(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Unwind@007e9e40 @ 0x007e9e40

void Unwind_007e9e40(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x54));
  return;
}



// Unwind@007e9e60 @ 0x007e9e60

void Unwind_007e9e60(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Unwind@007e9e6b @ 0x007e9e6b

void Unwind_007e9e6b(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x4c));
  return;
}



// Unwind@007e9e80 @ 0x007e9e80

void Unwind_007e9e80(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Unwind@007e9e8b @ 0x007e9e8b

void Unwind_007e9e8b(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Unwind@007e9e96 @ 0x007e9e96

void Unwind_007e9e96(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x1c));
  return;
}



// Unwind@007e9ea1 @ 0x007e9ea1

void Unwind_007e9ea1(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + 4));
  return;
}



// Unwind@007e9ec0 @ 0x007e9ec0

void Unwind_007e9ec0(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + 4));
  return;
}



// Unwind@007e9ee0 @ 0x007e9ee0

void Unwind_007e9ee0(void)

{
  FUN_0072c040();
  return;
}



// Unwind@007e9eeb @ 0x007e9eeb

void Unwind_007e9eeb(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x21c));
  return;
}



// Unwind@007e9f10 @ 0x007e9f10

void Unwind_007e9f10(void)

{
  FUN_0072ce10();
  return;
}



// Unwind@007e9f30 @ 0x007e9f30

void Unwind_007e9f30(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x28));
  return;
}



// Unwind@007e9f50 @ 0x007e9f50

void Unwind_007e9f50(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Unwind@007e9f70 @ 0x007e9f70

void Unwind_007e9f70(void)

{
  FUN_00799030();
  return;
}



// Unwind@007e9f90 @ 0x007e9f90

void Unwind_007e9f90(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x10));
  return;
}



// Unwind@007e9fb0 @ 0x007e9fb0

void Unwind_007e9fb0(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x428));
  return;
}



// Unwind@007e9fbe @ 0x007e9fbe

void Unwind_007e9fbe(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x428));
  return;
}



// Unwind@007e9fe0 @ 0x007e9fe0

void Unwind_007e9fe0(void)

{
  FUN_0072c040();
  return;
}



// Unwind@007ea000 @ 0x007ea000

void Unwind_007ea000(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + 4));
  return;
}



// Unwind@007ea020 @ 0x007ea020

void Unwind_007ea020(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + 8));
  return;
}



// Unwind@007ea02b @ 0x007ea02b

void Unwind_007ea02b(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + 0x10));
  return;
}



// Unwind@007ea040 @ 0x007ea040

void Unwind_007ea040(void)

{
  thunk_FUN_007c0c40();
  return;
}



// Unwind@007ea048 @ 0x007ea048

void Unwind_007ea048(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x88));
  return;
}



// Unwind@007ea060 @ 0x007ea060

void Unwind_007ea060(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + 0x10));
  return;
}



// Unwind@007ea06b @ 0x007ea06b

void Unwind_007ea06b(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + 0x10));
  return;
}



// Unwind@007ea076 @ 0x007ea076

void Unwind_007ea076(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + 4));
  return;
}



// Unwind@007ea081 @ 0x007ea081

void Unwind_007ea081(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + 8));
  return;
}



// Unwind@007ea08c @ 0x007ea08c

void Unwind_007ea08c(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + 8));
  return;
}



// Unwind@007ea097 @ 0x007ea097

void Unwind_007ea097(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + 0x10));
  return;
}



// Unwind@007ea0a2 @ 0x007ea0a2

void Unwind_007ea0a2(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + 0x10));
  return;
}



// Unwind@007ea0ad @ 0x007ea0ad

void Unwind_007ea0ad(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + 0x10));
  return;
}



// Unwind@007ea0b8 @ 0x007ea0b8

void Unwind_007ea0b8(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + 0x10));
  return;
}



// Unwind@007ea0d0 @ 0x007ea0d0

void Unwind_007ea0d0(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Unwind@007ea0db @ 0x007ea0db

void Unwind_007ea0db(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Unwind@007ea0e6 @ 0x007ea0e6

void Unwind_007ea0e6(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Unwind@007ea0f1 @ 0x007ea0f1

void Unwind_007ea0f1(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Unwind@007ea0fc @ 0x007ea0fc

void Unwind_007ea0fc(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x40));
  return;
}



// Unwind@007ea107 @ 0x007ea107

void Unwind_007ea107(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Unwind@007ea112 @ 0x007ea112

void Unwind_007ea112(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Unwind@007ea11d @ 0x007ea11d

void Unwind_007ea11d(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x48));
  return;
}



// Unwind@007ea128 @ 0x007ea128

void Unwind_007ea128(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x3c));
  return;
}



// Unwind@007ea133 @ 0x007ea133

void Unwind_007ea133(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + 4));
  return;
}



// Unwind@007ea150 @ 0x007ea150

void Unwind_007ea150(void)

{
  thunk_FUN_007c0c40();
  return;
}



// Unwind@007ea158 @ 0x007ea158

void Unwind_007ea158(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x9c));
  return;
}



// Unwind@007ea166 @ 0x007ea166

void Unwind_007ea166(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x9c));
  return;
}



// Unwind@007ea174 @ 0x007ea174

void Unwind_007ea174(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x9c));
  return;
}



// Unwind@007ea182 @ 0x007ea182

void Unwind_007ea182(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x9c));
  return;
}



// Unwind@007ea1a0 @ 0x007ea1a0

void Unwind_007ea1a0(void)

{
  int unaff_EBP;
  
  FUN_007290de(*(undefined4 *)(unaff_EBP + -0x10));
  return;
}



// xtoa @ 0x00ee9592

/* Library Function - Single Match
    _xtoa
   
   Library: Visual Studio 2003 Debug */

void __cdecl xtoa(uint param_1,char *param_2,uint param_3,int param_4)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  char *local_c;
  char *local_8;
  
  local_8 = param_2;
  if (param_4 != 0) {
    *param_2 = '-';
    local_8 = param_2 + 1;
    param_1 = -param_1;
  }
  local_c = local_8;
  do {
    pcVar2 = local_8;
    uVar3 = param_1 % param_3;
    param_1 = param_1 / param_3;
    cVar1 = (char)uVar3;
    if (uVar3 < 10) {
      *local_8 = cVar1 + '0';
    }
    else {
      *local_8 = cVar1 + 'W';
    }
    local_8 = local_8 + 1;
  } while (param_1 != 0);
  *local_8 = '\0';
  local_8 = pcVar2;
  do {
    cVar1 = *local_8;
    *local_8 = *local_c;
    *local_c = cVar1;
    local_8 = local_8 + -1;
    local_c = local_c + 1;
  } while (local_c < local_8);
  return;
}



