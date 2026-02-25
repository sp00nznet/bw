// Decompiled functions for class: Scaffold
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?CanBePickedUpByCreature@Scaffold@@UAEIPAVCreature@@@Z @ 0x004c5460

undefined4 _CanBePickedUpByCreature_Scaffold__UAEIPAVCreature___Z(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  undefined4 unaff_retaddr;
  
  iVar1 = (**(code **)(*in_ECX + 0x6fc))(0);
  if (iVar1 != 1) {
    return 0;
  }
  uVar2 = _CanBePickedUpByCreature_Object__UAE_NPAVCreature___Z(unaff_retaddr);
  return uVar2;
}



// ?CanBeStolenByCreature@Scaffold@@UAEIPAVCreature@@@Z @ 0x004c5490

undefined4 _CanBeStolenByCreature_Scaffold__UAEIPAVCreature___Z(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *in_ECX;
  int *unaff_retaddr;
  
  iVar1 = (**(code **)(*in_ECX + 0x6fc))(0);
  if (iVar1 != 1) {
    return 0;
  }
  iVar1 = (**(code **)(*in_ECX + 0x48))();
  if (iVar1 != 0) {
    piVar2 = (int *)(**(code **)(*in_ECX + 0x48))();
    iVar1 = (**(code **)(*piVar2 + 0x1c))();
    iVar3 = (**(code **)(*unaff_retaddr + 0x1c))();
    if (iVar1 == iVar3) {
      return 0;
    }
  }
  return 1;
}



// ?IsStealableScaffold@Scaffold@@UAEIPAVCreature@@@Z @ 0x004c5510

void _IsStealableScaffold_Scaffold__UAEIPAVCreature___Z(undefined4 param_1)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x390))(param_1);
  return;
}



// ?DrawInHand@Scaffold@@UAEXPAVGInterfaceStatus@@@Z @ 0x004f47e0

void _DrawInHand_Scaffold__UAEXPAVGInterfaceStatus___Z(int param_1)

{
  float fVar1;
  uint uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int in_ECX;
  uint uVar9;
  float10 fVar10;
  float10 fVar11;
  float fStack_190;
  uint uStack_17c;
  undefined4 uStack_178;
  int iStack_174;
  int iStack_170;
  float fStack_16c;
  LH_SamplePlayOptions aLStack_168 [4];
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  undefined4 uStack_148;
  undefined4 uStack_144;
  int iStack_120;
  
  _DrawInHand_Object__UAEXPAVGInterfaceStatus___Z(param_1);
  iVar6 = FUN_00685500(0);
  if ((iVar6 != 0) && (iVar6 = FUN_00527d30(), param_1 == *(int *)(iVar6 + 0x39c))) {
    uVar9 = *(uint *)(DAT_00c22ca4 + 0x24c5e8) % 100;
    uVar2 = *(uint *)(in_ECX + 0x78);
    if (uVar2 <= uVar9) {
      uVar9 = uVar2;
    }
    iVar6 = uVar2 - uVar9;
    fStack_190 = *(float *)(in_ECX + 0x84);
    if (iVar6 < 1) {
      if ((*(byte *)(in_ECX + 0x88) & 1) == 0) {
        return;
      }
    }
    else if ((*(byte *)(in_ECX + 0x88) & 1) == 0) {
      if (DAT_00be7680 == 0) {
        DAT_00be767c = 0;
        FUN_00423ce0(0,0x32,2,0,0,0,1);
        DAT_00be7680 = 1;
      }
      fStack_190 = (float)iVar6 * fStack_190 * 0.0025;
    }
    else {
      if (DAT_00be767c == 0) {
        DAT_00be7680 = 0;
        piVar7 = (int *)FUN_00403e10();
        iVar8 = (**(code **)(*piVar7 + 0x44))();
        LH_SamplePlayOptions::LH_SamplePlayOptions(aLStack_168);
        if (iVar8 < 0) {
          iStack_120 = 100;
        }
        else {
          iStack_120 = iVar8 * -3 + 0x6e;
        }
        uStack_164 = *(undefined4 *)(DAT_00bf4e68 + 0x3ac);
        uStack_144 = 0x33;
        uStack_15c = 0;
        uStack_148 = 0;
        uStack_160 = 0;
        FUN_00423db0(aLStack_168);
        DAT_00be767c = 1;
        LH_SamplePlayOptions::~LH_SamplePlayOptions(aLStack_168);
      }
      fStack_190 = (1.0 - (float)iVar6 * 0.0025) * fStack_190;
    }
    if (*(int **)(in_ECX + 0x74) != (int *)0x0) {
      (**(code **)(**(int **)(in_ECX + 0x74) + 0x40))();
      iVar6 = FUN_00527d30();
      FUN_005bf830(*(int *)(*(int *)(iVar6 + 0x3a0) + 0x482c) + 0x38);
      iVar6 = *(int *)(in_ECX + 0x74);
      fVar3 = (float)(*(uint *)(DAT_00c22ca4 + 0x24c5e8) % 100) * 0.01 *
              *(float *)(*(int *)(in_ECX + 0x28) + 0x114) + *(float *)(in_ECX + 0x80);
      fVar10 = (float10)FUN_00760fd0();
      fVar1 = (float)(fVar10 + (float10)fStack_16c);
      fVar4 = (float)iStack_174 * 0.00015258789;
      fVar5 = (float)iStack_170 * 0.00015258789;
      if (fVar3 == 0.0) {
        if (fStack_190 == 1.0) {
          FUN_00402280();
          *(float *)(iVar6 + 0x38) = fVar4;
          *(float *)(iVar6 + 0x3c) = fVar1;
          *(float *)(iVar6 + 0x40) = fVar5;
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
          *(float *)(iVar6 + 0x34) = fStack_190;
          *(float *)(iVar6 + 0x24) = fStack_190;
          *(float *)(iVar6 + 0x14) = fStack_190;
          *(float *)(iVar6 + 0x38) = fVar4 + *(float *)(iVar6 + 0x38);
          *(float *)(iVar6 + 0x3c) = fVar1 + *(float *)(iVar6 + 0x3c);
          *(float *)(iVar6 + 0x40) = fVar5 + *(float *)(iVar6 + 0x40);
        }
      }
      else if (fStack_190 == 1.0) {
        fVar10 = (float10)fcos((float10)fVar3);
        *(undefined4 *)(iVar6 + 0x30) = 0;
        *(undefined4 *)(iVar6 + 0x2c) = 0;
        *(undefined4 *)(iVar6 + 0x28) = 0;
        *(undefined4 *)(iVar6 + 0x20) = 0;
        *(undefined4 *)(iVar6 + 0x1c) = 0;
        *(undefined4 *)(iVar6 + 0x18) = 0;
        *(float *)(iVar6 + 0x38) = fVar4;
        *(float *)(iVar6 + 0x3c) = fVar1;
        *(undefined4 *)(iVar6 + 0x34) = 0x3f800000;
        *(undefined4 *)(iVar6 + 0x24) = 0x3f800000;
        *(undefined4 *)(iVar6 + 0x14) = 0x3f800000;
        *(float *)(iVar6 + 0x40) = fVar5;
        fVar11 = (float10)fsin((float10)fVar3);
        fVar1 = *(float *)(iVar6 + 0x14);
        *(float *)(iVar6 + 0x14) =
             (float)(fVar10 * (float10)*(float *)(iVar6 + 0x14) +
                    fVar11 * (float10)*(float *)(iVar6 + 0x2c));
        *(float *)(iVar6 + 0x2c) =
             (float)(fVar10 * (float10)*(float *)(iVar6 + 0x2c) - fVar11 * (float10)fVar1);
        fVar1 = *(float *)(iVar6 + 0x18);
        *(float *)(iVar6 + 0x18) =
             (float)(fVar10 * (float10)*(float *)(iVar6 + 0x18) +
                    fVar11 * (float10)*(float *)(iVar6 + 0x30));
        *(float *)(iVar6 + 0x30) =
             (float)(fVar10 * (float10)*(float *)(iVar6 + 0x30) - fVar11 * (float10)fVar1);
        fVar1 = *(float *)(iVar6 + 0x1c);
        *(float *)(iVar6 + 0x1c) =
             (float)(fVar10 * (float10)*(float *)(iVar6 + 0x1c) +
                    fVar11 * (float10)*(float *)(iVar6 + 0x34));
        *(float *)(iVar6 + 0x34) =
             (float)(fVar10 * (float10)*(float *)(iVar6 + 0x34) -
                    (float10)(float)(fVar11 * (float10)fVar1));
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
        *(float *)(iVar6 + 0x34) = fStack_190;
        *(float *)(iVar6 + 0x24) = fStack_190;
        *(float *)(iVar6 + 0x14) = fStack_190;
        *(float *)(iVar6 + 0x38) = fVar4 + *(float *)(iVar6 + 0x38);
        *(float *)(iVar6 + 0x3c) = fVar1 + *(float *)(iVar6 + 0x3c);
        *(float *)(iVar6 + 0x40) = fVar5 + *(float *)(iVar6 + 0x40);
        fVar10 = (float10)fcos((float10)fVar3);
        fVar11 = (float10)fsin((float10)fVar3);
        fVar1 = *(float *)(iVar6 + 0x14);
        *(float *)(iVar6 + 0x14) =
             (float)(fVar10 * (float10)*(float *)(iVar6 + 0x14) +
                    fVar11 * (float10)*(float *)(iVar6 + 0x2c));
        *(float *)(iVar6 + 0x2c) =
             (float)(fVar10 * (float10)*(float *)(iVar6 + 0x2c) - fVar11 * (float10)fVar1);
        fVar1 = *(float *)(iVar6 + 0x18);
        *(float *)(iVar6 + 0x18) =
             (float)(fVar10 * (float10)*(float *)(iVar6 + 0x18) +
                    fVar11 * (float10)*(float *)(iVar6 + 0x30));
        *(float *)(iVar6 + 0x30) =
             (float)(fVar10 * (float10)*(float *)(iVar6 + 0x30) - fVar11 * (float10)fVar1);
        fVar1 = *(float *)(iVar6 + 0x1c);
        *(float *)(iVar6 + 0x1c) =
             (float)(fVar10 * (float10)*(float *)(iVar6 + 0x1c) +
                    fVar11 * (float10)*(float *)(iVar6 + 0x34));
        *(float *)(iVar6 + 0x34) =
             (float)(fVar10 * (float10)*(float *)(iVar6 + 0x34) -
                    (float10)(float)(fVar11 * (float10)fVar1));
      }
      *(float *)(iVar6 + 0x48) = fVar3;
      *(float *)(iVar6 + 0x44) = fStack_190;
      (**(code **)(**(int **)(in_ECX + 0x74) + 0x48))();
      uStack_17c = 0;
      uStack_178 = 0;
      FUN_00760090(&iStack_174,&uStack_17c,&uStack_178);
      uVar2 = uStack_17c;
      iVar6 = __ftol();
      uStack_17c = iVar6 << 0x18 | uVar2 & 0xffffff;
      (**(code **)(**(int **)(in_ECX + 0x74) + 0x2c))(uStack_178);
      FUN_005ed470();
    }
  }
  return;
}



// ?GetSaveType@Scaffold@@UAEIXZ @ 0x0052f0a0

undefined4 _GetSaveType_Scaffold__UAEIXZ(void)

{
  return 0x5f;
}



// ?GetDebugText@Scaffold@@UAEPADXZ @ 0x0052f0b0

char * _GetDebugText_Scaffold__UAEPADXZ(void)

{
  return s_Scaffold__00b1a510;
}



// ?ToBeDeleted@Scaffold@@UAEXH@Z @ 0x00682ff0

void _ToBeDeleted_Scaffold__UAEXH_Z(undefined4 param_1)

{
  int in_ECX;
  float10 fVar1;
  
  if (*(int *)(in_ECX + 0x68) != 0) {
    FUN_00434710(in_ECX);
    *(undefined4 *)(in_ECX + 0x68) = 0;
  }
  FUN_00683e00();
  (**(code **)(**(int **)(in_ECX + 0x74) + 4))();
  *(undefined4 *)(in_ECX + 0x74) = 0;
  if (*(int **)(in_ECX + 0x6c) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x6c) + 0xc))(param_1);
  }
  if (*(int **)(in_ECX + 0x70) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x70) + 0xc))(param_1);
  }
  if (*(int *)(in_ECX + 0x68) != 0) {
    fVar1 = (float10)FUN_004344a0();
    if (fVar1 == (float10)0.0) {
      (**(code **)(**(int **)(in_ECX + 0x68) + 0xc))(0);
    }
  }
  _ToBeDeleted_MobileObject__UAEXH_Z(param_1);
  return;
}



// ?CallVirtualFunctionsForCreation@Scaffold@@UAEXABUMapCoords@@@Z @ 0x00683150

void _CallVirtualFunctionsForCreation_Scaffold__UAEXABUMapCoords___Z(undefined4 param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  _CallVirtualFunctionsForCreation_MobileObject__UAEXABUMapCoords___Z(param_1);
  if ((*(byte *)(in_ECX + 10) & 1) == 0) {
    uVar1 = FUN_005ecd90(1);
    *(undefined4 *)(in_ECX + 0x74) = uVar1;
  }
  return;
}



// ?ProcessInHand@Scaffold@@UAE_NXZ @ 0x00683180

undefined4 _ProcessInHand_Scaffold__UAE_NXZ(void)

{
  float fVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  float10 fVar6;
  
  uVar2 = *(ushort *)(in_ECX + 0x88);
  if ((uVar2 & 0x3c) != 0) {
    *(ushort *)(in_ECX + 0x88) = (byte)(((byte)uVar2 & 0xfc) + 4 ^ (byte)uVar2) & 0x3c ^ uVar2;
  }
  if ((*(ushort *)(in_ECX + 0x88) & 0x200) == 0) {
    fVar1 = *(float *)(*(int *)(in_ECX + 0x28) + 0x114);
  }
  else {
    fVar1 = 0.0;
  }
  fVar1 = fVar1 + *(float *)(in_ECX + 0x80);
  *(float *)(in_ECX + 0x80) = fVar1;
  if (6.2831855 < fVar1) {
    *(float *)(in_ECX + 0x80) = fVar1 - 6.2831855;
  }
  iVar3 = *(int *)(in_ECX + 0x78);
  if (100 < iVar3) {
    iVar3 = 100;
  }
  iVar3 = *(int *)(in_ECX + 0x78) - iVar3;
  *(int *)(in_ECX + 0x78) = iVar3;
  if ((iVar3 < 1) && ((*(ushort *)(in_ECX + 0x88) & 1) == 0)) {
    FUN_00683860();
    FUN_00685560(1);
    iVar3 = FUN_00685500(0);
    if (iVar3 != 0) {
      fVar6 = (float10)(**(code **)(**(int **)(in_ECX + 0x6c) + 0x120))();
      *(float *)(in_ECX + 0x84) = (float)fVar6;
      if ((*(ushort *)(in_ECX + 0x88) & 0x200) == 0) {
        *(undefined4 *)(in_ECX + 0x80) = *(undefined4 *)(*(int *)(in_ECX + 0x6c) + 0x28);
      }
      *(ushort *)(in_ECX + 0x88) = *(ushort *)(in_ECX + 0x88) | 1;
      *(undefined4 *)(in_ECX + 0x78) = 400;
    }
  }
  iVar3 = FUN_005ec420();
  if (*(int *)(iVar3 + 0xa0) == 0) {
    *(ushort *)(in_ECX + 0x88) = *(ushort *)(in_ECX + 0x88) & 0xfffd;
    iVar3 = FUN_00683b70();
    if (((((iVar3 != 0) || (iVar5 = FUN_00685500(0), iVar5 == 0)) ||
         ((*(byte *)(in_ECX + 0x89) & 1) == 0)) &&
        (((iVar5 = FUN_00685500(0), iVar5 == 0 ||
          (iVar5 = (**(code **)(**(int **)(in_ECX + 0x74) + 0xf8))(), iVar5 == 0)) ||
         ((iVar5 = FUN_005c0000(*(undefined4 *)(in_ECX + 0x74),*(undefined4 *)(in_ECX + 0x80),
                                *(undefined4 *)(in_ECX + 0x84),0), iVar5 == 0 ||
          ((iVar3 == 0 || (iVar3 = FUN_006d2d20(in_ECX), iVar3 == 0)))))))) &&
       (*(int *)(in_ECX + 0x78) < 1)) {
      FUN_00683720();
    }
  }
  else {
    iVar3 = FUN_00685500(0);
    if ((iVar3 == 0) || ((*(byte *)(in_ECX + 0x88) & 2) == 0)) {
      uVar4 = FUN_00683b70();
      iVar3 = FUN_00683ab0(uVar4);
      if ((iVar3 == 0) && ((*(byte *)(in_ECX + 0x88) & 0x3e) == 0)) {
        FUN_005efc00(in_ECX + 0x14,4,0x3f800000,0);
        *(ushort *)(in_ECX + 0x88) = *(ushort *)(in_ECX + 0x88) & 0xffc7 | 4;
      }
      *(byte *)(in_ECX + 0x88) = *(byte *)(in_ECX + 0x88) | 2;
      return 1;
    }
  }
  return 1;
}



// ?EndPhysics@Scaffold@@UAEXPAVPhysicsObject@@_N@Z @ 0x00683380

undefined4 _EndPhysics_Scaffold__UAEXPAVPhysicsObject___N_Z(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined4 uVar6;
  
  iVar1 = (**(code **)(*in_ECX + 0x1c))();
  if ((iVar1 != 0) && (param_1 != 0)) {
    uVar2 = *(undefined4 *)(param_1 + 0x24);
    uVar6 = 0;
    uVar4 = 6;
    piVar5 = in_ECX;
    (**(code **)(*in_ECX + 0x1c))(uVar2,6);
    FUN_004cb260(uVar2,uVar4,piVar5,uVar6);
  }
  uVar2 = _EndPhysics_Object__UAEXPAVPhysicsObject___N_Z(param_1,param_2);
  if ((char)param_2 == '\0') goto LAB_00683440;
  iVar3 = 0;
  iVar1 = FUN_00683b70();
  if (iVar1 != 0) {
    iVar3 = FUN_006d2d60(in_ECX);
  }
  if (((*(byte *)(param_1 + 0x1d8) & 4) != 0) && (iVar3 == 0)) {
    if ((*(ushort *)(in_ECX + 0x22) & 0x400) != 0) {
      iVar1 = FUN_00683e50(in_ECX[0x1f],(*(ushort *)(in_ECX + 0x22) & 0x800) >> 0xb);
      if (iVar1 != 0) {
        FUN_00683490();
        goto LAB_00683427;
      }
    }
    FUN_005efc00(in_ECX + 5,4,0x3f800000,0);
  }
LAB_00683427:
  in_ECX[0x1f] = 0;
  in_ECX[0x25] = *(int *)(DAT_00c22ca4 + 0x201afc);
LAB_00683440:
  *(ushort *)(in_ECX + 0x22) = *(ushort *)(in_ECX + 0x22) & 0xfbff;
  return uVar2;
}



// ?ValidForPlaceInHand@Scaffold@@UAEIPAVGInterfaceStatus@@@Z @ 0x006842a0

undefined4 _ValidForPlaceInHand_Scaffold__UAEIPAVGInterfaceStatus___Z(void)

{
  int iVar1;
  float10 fVar2;
  
  iVar1 = FUN_00683710();
  if (iVar1 != 0) {
    return 1;
  }
  iVar1 = FUN_006855f0();
  if ((iVar1 != 0) && (fVar2 = (float10)FUN_004344a0(), fVar2 == (float10)0.0)) {
    return 1;
  }
  return 0;
}



// ?InterfaceSetInMagicHand@Scaffold@@UAEIPAVGInterfaceStatus@@@Z @ 0x006842e0

int _InterfaceSetInMagicHand_Scaffold__UAEIPAVGInterfaceStatus___Z(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int in_ECX;
  int *piVar4;
  bool bVar5;
  
  iVar1 = _NetworkFriendlyStartLockedSelect_Fixed__UAE_NPAVGInterfaceStatus___Z(param_1);
  piVar4 = (int *)0x0;
  if (iVar1 != 0) {
    uVar2 = (**(code **)(*param_1 + 0x1c))();
    *(undefined4 *)(in_ECX + 0x7c) = uVar2;
    *(undefined4 *)(in_ECX + 0x94) = 0;
    if (*(int *)(in_ECX + 0x68) != 0) {
      piVar4 = (int *)FUN_00434490();
    }
    bVar5 = false;
    if (piVar4 != (int *)0x0) {
      iVar3 = (**(code **)(*piVar4 + 0x8f8))();
      bVar5 = iVar3 == 0;
      (**(code **)(*piVar4 + 0x8fc))(1);
    }
    FUN_00684210();
    if (bVar5) {
      (**(code **)(*piVar4 + 0x8fc))(0);
    }
    if (*(int **)(in_ECX + 0x58) != (int *)0x0) {
      (**(code **)(**(int **)(in_ECX + 0x58) + 0x5e0))();
    }
  }
  return iVar1;
}



// ?InterfaceSetOutMagicHand@Scaffold@@UAEIPAVGInterfaceStatus@@@Z @ 0x00684370

undefined4 _InterfaceSetOutMagicHand_Scaffold__UAEIPAVGInterfaceStatus___Z(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *in_ECX;
  
  if (param_1 != (int *)0x0) {
    iVar1 = (**(code **)(*param_1 + 0x1c))();
    if (iVar1 != 0) {
      iVar1 = (**(code **)(*param_1 + 0x1c))();
      if (*(int *)(iVar1 + 0xf8) != 2) {
        iVar1 = FUN_00685500(0);
        if ((iVar1 != 0) && ((*(byte *)((int)in_ECX + 0x89) & 4) != 0)) {
          iVar1 = FUN_00403e10();
          iVar2 = FUN_006848f0();
          if (iVar2 != *(int *)(iVar1 + 0x10c) && -1 < iVar2 - *(int *)(iVar1 + 0x10c)) {
            iVar1 = FUN_00403e10();
            iVar2 = FUN_006848f0();
            iVar2 = iVar2 - *(int *)(iVar1 + 0x10c);
            if (0 < iVar2) {
              iVar1 = in_ECX[10];
              uVar3 = (**(code **)(*in_ECX + 0x48))(0,0,0x3f800000);
              iVar1 = FUN_00683070(in_ECX + 5,iVar1,uVar3);
              if (iVar1 != 0) {
                FUN_00684920(iVar2);
                iVar4 = FUN_006848f0();
                FUN_00684920(iVar4 - iVar2);
                FUN_0059c850(iVar1);
              }
            }
          }
        }
      }
    }
  }
  return 1;
}



// ?GetOverwriteDropToolTip@Scaffold@@UAEIXZ @ 0x00684460

undefined4 _GetOverwriteDropToolTip_Scaffold__UAEIXZ(void)

{
  int iVar1;
  
  iVar1 = FUN_00685500(0);
  if (iVar1 == 1) {
    iVar1 = FUN_00403e10();
    return *(undefined4 *)(iVar1 + 0x1bc);
  }
  return 0xef0;
}



// ?ActualMoveMapObject@Scaffold@@UAEXPBUMapCoords@@@Z @ 0x00684490

void _ActualMoveMapObject_Scaffold__UAEXPBUMapCoords___Z(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  _ActualMoveMapObject_Object__UAEXUMapCoords___Z(param_1);
  iVar1 = *(int *)(in_ECX + 0x40);
  if (iVar1 != 0) {
    FUN_00760fd0();
    FUN_004022b0();
    *(undefined4 *)(iVar1 + 0x44) = 0x3f800000;
    *(undefined4 *)(iVar1 + 0x48) = 0;
  }
  return;
}



// ?ValidToApplyThisToObject@Scaffold@@UAEIPAVGInterfaceStatus@@PAVObject@@@Z @ 0x00684500

undefined4
_ValidToApplyThisToObject_Scaffold__UAEIPAVGInterfaceStatus__PAVObject___Z
          (undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int in_ECX;
  float10 fVar5;
  
  iVar1 = (**(code **)(*param_2 + 0x49c))();
  if ((iVar1 == 0) || ((*(byte *)(param_2 + 9) & 0x40) != 0)) {
    iVar1 = (**(code **)(*param_2 + 0x300))(0);
    if ((iVar1 != 0) && (iVar1 = (**(code **)(*param_2 + 0x680))(1), iVar1 != 0)) {
      return 1;
    }
  }
  else {
    iVar1 = *(int *)(in_ECX + 0x28);
    iVar2 = FUN_006848f0();
    iVar3 = FUN_006848f0();
    if ((((uint)(iVar2 + iVar3) <= (uint)*(ushort *)(iVar1 + 0x124)) &&
        (*(int *)(in_ECX + 0x90) == -1)) && (param_2[0x24] == -1)) {
      iVar1 = FUN_00683710();
      if (iVar1 == 0) {
        piVar4 = (int *)FUN_00434460();
        fVar5 = (float10)(**(code **)(*piVar4 + 0x880))();
        if (fVar5 != (float10)0.0) {
          return 0;
        }
      }
      return 1;
    }
  }
  return 0;
}



// ?ApplyThisToObject@Scaffold@@UAEIPAVGInterfaceStatus@@PAVObject@@PAUGestureSystemPacketData@@@Z @ 0x006845c0

undefined4
_ApplyThisToObject_Scaffold__UAEIPAVGInterfaceStatus__PAVObject__PAUGestureSystemPacketData___Z
          (int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  LH_SamplePlayOptions aLStack_168 [4];
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  int iStack_144;
  int iStack_138;
  int iStack_134;
  int iStack_130;
  
  iVar3 = (**(code **)(*param_2 + 0x49c))();
  if ((iVar3 != 0) && ((*(byte *)(param_2 + 9) & 0xc) == 0)) {
    FUN_00684740(param_2);
    piVar4 = (int *)FUN_005efc00(param_2 + 5,0x1b,0x3f800000,0);
    if (param_1 != (int *)0x0) {
      iVar3 = param_1[0x32];
      iVar1 = param_1[0x33];
      iVar2 = param_1[0x34];
      LH_SamplePlayOptions::LH_SamplePlayOptions(aLStack_168);
      uStack_164 = *(undefined4 *)(DAT_00bf4e68 + 0x3ac);
      iStack_144 = DAT_00cb6898 + 0xc9;
      DAT_00cb6898 = DAT_00cb6898 + 1;
      if (DAT_00cb6898 == 4) {
        DAT_00cb6898 = 0;
      }
      uStack_160 = 1;
      uStack_15c = 0;
      iStack_138 = iVar3;
      iStack_134 = iVar1;
      iStack_130 = iVar2;
      FUN_00423db0(aLStack_168);
      LH_SamplePlayOptions::~LH_SamplePlayOptions(aLStack_168);
    }
    if (piVar4 != (int *)0x0) {
      iVar3 = *piVar4;
      uVar5 = (**(code **)(*param_1 + 0x1c))();
      (**(code **)(iVar3 + 0x20))(uVar5);
    }
    uVar6 = 0x80000000;
    uVar5 = 0x2c;
    FUN_00667ed0(0x2c,0x80000000);
    FUN_00598f00(uVar5,uVar6);
    return 1;
  }
  iVar3 = (**(code **)(*param_2 + 0x300))(0);
  if (iVar3 != 0) {
    iVar3 = (**(code **)(*param_2 + 0x684))();
    if (iVar3 != 0) {
      return 3;
    }
  }
  return 0;
}



// ?GetDefaultResource@Scaffold@@UAEHXZ @ 0x00684910

int _GetDefaultResource_Scaffold__UAEHXZ(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x28);
  iVar2 = FUN_006848f0();
  return iVar2 * *(int *)(iVar1 + 0x6c);
}



// ?InterfaceValidToTap@Scaffold@@UAEIPAVGInterfaceStatus@@@Z @ 0x00684960

undefined4 _InterfaceValidToTap_Scaffold__UAEIPAVGInterfaceStatus___Z(void)

{
  uint uVar1;
  int iVar2;
  int in_ECX;
  
  uVar1 = FUN_006848f0();
  if ((1 < uVar1) && ((*(byte *)(in_ECX + 0x24) & 0x40) == 0)) {
    iVar2 = FUN_00683710();
    if ((iVar2 == 0) && (iVar2 = FUN_006855f0(), iVar2 == 0)) {
      return 0;
    }
    if (*(int *)(in_ECX + 0x90) == -1) {
      return 1;
    }
  }
  return 0;
}



// ?InterfaceTap@Scaffold@@UAEIPAVGInterfaceStatus@@@Z @ 0x006849b0

undefined4 _InterfaceTap_Scaffold__UAEIPAVGInterfaceStatus___Z(int param_1)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  LH_SamplePlayOptions aLStack_168 [4];
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_15c;
  int iStack_144;
  undefined4 uStack_138;
  undefined4 uStack_134;
  undefined4 uStack_130;
  
  iVar4 = FUN_00683710();
  if (iVar4 == 0) {
    FUN_00684210();
  }
  FUN_00684a80();
  uVar1 = *(undefined4 *)(param_1 + 200);
  uVar2 = *(undefined4 *)(param_1 + 0xcc);
  uVar3 = *(undefined4 *)(param_1 + 0xd0);
  LH_SamplePlayOptions::LH_SamplePlayOptions(aLStack_168);
  uStack_164 = *(undefined4 *)(DAT_00bf4e68 + 0x3ac);
  iStack_144 = DAT_00cb689c + 0x97;
  DAT_00cb689c = DAT_00cb689c + 1;
  if (DAT_00cb689c == 4) {
    DAT_00cb689c = 0;
  }
  uStack_15c = 0;
  uStack_160 = 1;
  uStack_138 = uVar1;
  uStack_134 = uVar2;
  uStack_130 = uVar3;
  FUN_00423db0(aLStack_168);
  LH_SamplePlayOptions::~LH_SamplePlayOptions(aLStack_168);
  return 1;
}



// ?Save@Scaffold@@UAEIAAVGameOSFile@@@Z @ 0x00684e20

undefined4 _Save_Scaffold__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_MobileObject__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x68));
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x6c));
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x70));
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x78),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x78) + 4;
    }
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
          iVar1 = FUN_0072be90((byte *)(in_ECX + 0x88),2,0);
          if (iVar1 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x88) + 2;
        }
      }
    }
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x8c));
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x90),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x90) + 4;
    }
    return 1;
  }
  return 0;
}



// ?Load@Scaffold@@UAEIAAVGameOSFile@@@Z @ 0x00684fb0

undefined4 _Load_Scaffold__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Load_MobileObject__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    FUN_00531f30(in_ECX + 0x68);
    FUN_00531f30(in_ECX + 0x6c);
    FUN_00531f30(in_ECX + 0x70);
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x78),4,0,unaff_EBP,unaff_EBX,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x78) + 4;
    }
    FUN_00531f30();
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
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
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x88) + 2;
    }
    FUN_00531f30();
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x90) + 4;
    }
    return 1;
  }
  return 0;
}



// ?ResolveLoad@Scaffold@@UAEXXZ @ 0x00685140

void _ResolveLoad_Scaffold__UAEXXZ(void)

{
  int iVar1;
  int *piVar2;
  int in_ECX;
  
  _ResolveLoad_Object__UAEXXZ();
  if ((*(byte *)(in_ECX + 10) & 1) == 0) {
    if (*(int *)(in_ECX + 0x68) != 0) {
      FUN_00683490();
      return;
    }
    iVar1 = FUN_00685500(0);
    if (iVar1 != 0) {
      piVar2 = (int *)FUN_00403e10();
      (**(code **)(*piVar2 + 0x2c))();
      (**(code **)(**(int **)(in_ECX + 0x74) + 0xf4))(0,0);
    }
  }
  return;
}



// ?Draw@Scaffold@@UAEXXZ @ 0x006851a0

void _Draw_Scaffold__UAEXXZ(void)

{
  int iVar1;
  int *piVar2;
  int *in_ECX;
  uint uVar3;
  float10 fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  uint uStack_10;
  float fStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  _Draw_MobileObject__UAEXXZ();
  if ((in_ECX[0x1a] != 0) && ((int *)in_ECX[0x1d] != (int *)0x0)) {
    iVar1 = (**(code **)(*(int *)in_ECX[0x1d] + 0xf8))();
    if (iVar1 != 0) {
      (**(code **)(*(int *)in_ECX[0x1d] + 0x40))();
      piVar2 = (int *)FUN_00434460();
      fVar4 = (float10)(**(code **)(*piVar2 + 0x880))();
      if (((float10)1.0 - fVar4 * (float10)1.5) * (float10)(float)in_ECX[0x21] <= (float10)0.01) {
        fStack_c = 0.01;
      }
      else {
        piVar2 = (int *)FUN_00434460();
        fVar4 = (float10)(**(code **)(*piVar2 + 0x880))();
        fStack_c = (float)(((float10)1.0 - fVar4 * (float10)1.5) * (float10)(float)in_ECX[0x21]);
      }
      fVar7 = fStack_c;
      fVar4 = (float10)(**(code **)(*in_ECX + 0x50c))(fStack_c);
      fVar6 = (float)fVar4;
      fVar4 = (float10)(**(code **)(*in_ECX + 0x508))(fVar6);
      fVar5 = (float)fVar4;
      fVar4 = (float10)(**(code **)(*in_ECX + 0x504))(fVar5);
      FUN_005ed520((float)fVar4,fVar5,fVar6,fVar7);
      (**(code **)(*(int *)in_ECX[0x1d] + 0x48))();
      uStack_10 = 0;
      uStack_4 = 0;
      iVar1 = FUN_00434460(&uStack_10,&uStack_4);
      FUN_00760090(iVar1 + 0x14);
      uVar3 = uStack_10 >> 0x18;
      piVar2 = (int *)FUN_00434460();
      uStack_8 = 0;
      fStack_c = (float)uVar3;
      (**(code **)(*piVar2 + 0x880))();
      iVar1 = __ftol();
      uStack_10 = uStack_10 & 0xffffff | iVar1 << 0x18;
      (**(code **)(*(int *)in_ECX[0x1d] + 0x2c))(uStack_4);
      DAT_00de94b8 = 10;
      DAT_00de94b4 = 1;
      *(uint *)(in_ECX[0x1d] + 8) = *(uint *)(in_ECX[0x1d] + 8) | 0x20;
      FUN_005ed470();
      DAT_00de94b4 = 0;
    }
  }
  return;
}



// ?GetImpressiveValue@Scaffold@@UAEMPAVLiving@@PAVReaction@@@Z @ 0x00685350

float10 _GetImpressiveValue_Scaffold__UAEMPAVLiving__PAVReaction___Z
                  (undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int in_ECX;
  float10 fVar4;
  undefined4 uStack_c;
  
  uStack_c = 1.0;
  if (*(int *)(in_ECX + 0x68) != 0) {
    piVar1 = (int *)FUN_00434460();
    iVar2 = (**(code **)(*piVar1 + 0x208))();
    if (iVar2 == 0) {
      piVar1 = (int *)FUN_00434460();
      iVar2 = (**(code **)(*piVar1 + 0x48))();
      uStack_c = *(float *)(iVar2 + 0x1b4) + *(float *)(iVar2 + 0x120) + *(float *)(iVar2 + 0xdc);
    }
    else {
      piVar1 = (int *)FUN_00434460();
      iVar2 = (**(code **)(*piVar1 + 0x48))();
      uStack_c = *(float *)(iVar2 + 0x1b0) + *(float *)(iVar2 + 0x11c) + *(float *)(iVar2 + 0xd8);
    }
  }
  fVar4 = (float10)_GetImpressiveValue_Object__UAEMPAVLiving__PAVReaction___Z(param_1,param_2);
  uVar3 = FUN_006848f0();
  return (float10)uVar3 * (float10)(float)fVar4 * (float10)uStack_c;
}



// ?InitialisePhysics@Scaffold@@UAEIABULHPoint@@0PAVObject@@_NPAVGInterfaceStatus@@@Z @ 0x00685400

void _InitialisePhysics_Scaffold__UAEIABULHPoint__0PAVObject___NPAVGInterfaceStatus___Z
               (int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               undefined4 param_5,undefined4 param_6)

{
  int in_ECX;
  int iStack_8;
  int iStack_4;
  
  _InitialisePhysics_Object__UAEIPBULHPoint__0PAV1__NPAVGInterfaceStatus___Z
            (&iStack_8,param_2,param_3,param_4,param_5,param_6);
  if ((iStack_8 != 0) && (*(int **)(in_ECX + 0x58) != (int *)0x0)) {
    (**(code **)(**(int **)(in_ECX + 0x58) + 0x5e0))();
  }
  *param_1 = iStack_8;
  param_1[1] = iStack_4;
  return;
}



// ?InitialisePhysicsFromHand@Scaffold@@UAEIAAULHPoint@@0PAVGInterfaceStatus@@PAVObject@@H@Z @ 0x00685460

void _InitialisePhysicsFromHand_Scaffold__UAEIAAULHPoint__0PAVGInterfaceStatus__PAVObject__H_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
               int param_5)

{
  int iVar1;
  short sVar2;
  int in_ECX;
  
  if ((*(byte *)(in_ECX + 0x89) & 8) != 0) {
    FUN_00685740();
  }
  iVar1 = _InitialisePhysicsFromHand_Object__UAEIPAULHPoint__0PAVGInterfaceStatus__PAV1_H_Z
                    (param_1,param_2,param_3,param_4,param_5);
  if (iVar1 != 0) {
    if (((*(byte *)(iVar1 + 0x1d8) & 8) == 0) || (param_5 != 0)) {
      sVar2 = 0;
    }
    else {
      sVar2 = 1;
    }
    *(ushort *)(in_ECX + 0x88) = sVar2 << 10 | *(ushort *)(in_ECX + 0x88) & 0xfbff;
  }
  return;
}



// ?CanBecomeAPhysicsObject@Scaffold@@UAE_NXZ @ 0x006854d0

undefined4 _CanBecomeAPhysicsObject_Scaffold__UAE_NXZ(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (((*(int *)(in_ECX + 0x58) == 0) ||
      (*(char *)((*(byte *)(in_ECX + 0x88) >> 6) + 0xdc + *(int *)(in_ECX + 0x58)) != '\x02')) &&
     (*(int *)(in_ECX + 0x68) == 0)) {
    uVar1 = _AttitudeToCreatureEating_GameThingWithPos__UAEIXZ();
    return uVar1;
  }
  return 0;
}



// ?GetOverwritePickUpToolTip@Scaffold@@UAEIXZ @ 0x00685580

undefined4 _GetOverwritePickUpToolTip_Scaffold__UAEIXZ(void)

{
  return 0xee7;
}



// ?GetUpdateOfBoredomValue@Scaffold@@UAEMPAVReaction@@PAVGameThingWithPos@@@Z @ 0x00685590

float10 _GetUpdateOfBoredomValue_Scaffold__UAEMPAVReaction__PAVGameThingWithPos___Z(void)

{
  return (float10)-1.0;
}



// ?GetScriptObjectType@Scaffold@@UAEIXZ @ 0x00685710

undefined4 _GetScriptObjectType_Scaffold__UAEIXZ(void)

{
  return 0x27;
}



// ?ThrowObjectFromHand@Scaffold@@UAEIPAVGInterfaceStatus@@H@Z @ 0x00685720

void _ThrowObjectFromHand_Scaffold__UAEIPAVGInterfaceStatus__H_Z
               (undefined4 param_1,undefined4 param_2)

{
  _ThrowObjectFromHand_Object__UAEIPAVGInterfaceStatus__H_Z(param_1,param_2);
  return;
}



// ?IsResourceStore@Scaffold@@UAE_NW4RESOURCE_TYPE@@@Z @ 0x00685a50

undefined4 _IsResourceStore_Scaffold__UAE_NW4RESOURCE_TYPE___Z(int param_1)

{
  int iVar1;
  
  if (param_1 == 1) {
    iVar1 = FUN_00683710();
    if (iVar1 == 0) {
      return 1;
    }
  }
  return 0;
}



// ?DeleteObjectAndTakeResource@Scaffold@@UAE_NPAVObject@@PAVGInterfaceStatus@@@Z @ 0x00685a70

undefined4
_DeleteObjectAndTakeResource_Scaffold__UAE_NPAVObject__PAVGInterfaceStatus___Z
          (undefined4 param_1,undefined4 param_2)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x68) != 0) {
    FUN_005ecb70(param_1,param_2);
    return 1;
  }
  return 0;
}



// ?AddResource@Scaffold@@UAEIW4RESOURCE_TYPE@@IPAVGInterfaceStatus@@_NPBUMapCoords@@H@Z @ 0x00685aa0

undefined4
_AddResource_Scaffold__UAEIW4RESOURCE_TYPE__IPAVGInterfaceStatus___NPBUMapCoords__H_Z
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x68) != (int *)0x0) {
    uVar1 = (**(code **)(**(int **)(in_ECX + 0x68) + 0x9c))
                      (param_1,param_2,param_3,param_4,param_5,param_6);
    return uVar1;
  }
  return 0;
}



// ?SaveObject@Scaffold@@UAEIAAULHOSFile@@ABUMapCoords@@@Z @ 0x00685ae0

int _SaveObject_Scaffold__UAEIAAULHOSFile__ABUMapCoords___Z(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int *in_ECX;
  char *pcVar7;
  undefined1 auStack_138 [12];
  char acStack_12c [200];
  undefined1 auStack_64 [100];
  
  iVar2 = FUN_0053eb80();
  if (iVar2 == 0) {
    return 0;
  }
  if (param_2 != 0) {
    FUN_005c13b0(auStack_138,param_2);
  }
  if (in_ECX[0x16] != 0) {
    return 0;
  }
  iVar3 = (**(code **)(*in_ECX + 0x48))();
  if (iVar3 == 0) {
    uVar6 = 0xffffffff;
  }
  else {
    iVar3 = (**(code **)(*in_ECX + 0x48))();
    uVar6 = *(undefined4 *)(iVar3 + 0x5b4);
  }
  (**(code **)(*in_ECX + 0x120))();
  (**(code **)(*in_ECX + 0x508))();
  iVar3 = in_ECX[10];
  uVar4 = __ftol();
  uVar4 = __ftol(uVar4);
  iVar3 = (iVar3 + -0xcb6770) / 0x128;
  uVar5 = FUN_005bf290(auStack_64);
  uVar6 = FUN_006ad590(0x2c,uVar6,uVar5,iVar3,uVar4);
  FUN_00733e17(acStack_12c,uVar6);
  iVar3 = -1;
  pcVar7 = acStack_12c;
  do {
    if (iVar3 == 0) break;
    iVar3 = iVar3 + -1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar1 != '\0');
  FUN_006b10c0();
  return iVar2;
}



