// Decompiled functions for class: SpellWater
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetSaveType@SpellWater@@UAEIXZ @ 0x0052e5a0

undefined4 _GetSaveType_SpellWater__UAEIXZ(void)

{
  return 0xc;
}



// ?GetDebugText@SpellWater@@UAEPADXZ @ 0x0052e5b0

char * _GetDebugText_SpellWater__UAEPADXZ(void)

{
  return s_SpellWater__00b1a314;
}



// ?Process@SpellWater@@UAEIXZ @ 0x006bbd30

undefined4 _Process_SpellWater__UAEIXZ(void)

{
  float fVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  float fVar5;
  byte *pbVar6;
  int *in_ECX;
  undefined4 unaff_EBX;
  float10 fVar7;
  unkbyte10 Var8;
  float10 fVar9;
  float10 fVar10;
  float fStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  float fStack_4c;
  float fStack_48;
  float fStack_44;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  float fStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  int *piStack_2c;
  float fStack_28;
  undefined4 uStack_24;
  int *piStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined1 uStack_8;
  undefined4 uStack_4;
  
  uVar3 = _Process_Spell__UAEIXZ();
  if (((int *)in_ECX[0x3c] != (int *)0x0) &&
     (iVar4 = (**(code **)(*(int *)in_ECX[0x3c] + 0x2c))(), iVar4 != 1)) {
    in_ECX[0x3c] = 0;
  }
  if (in_ECX[0x10] == 0) {
    fStack_58 = (float)in_ECX[0x35];
    fVar7 = (float10)FUN_00760fd0();
    fStack_4c = (float)in_ECX[0x33] * 0.00015258789;
    fStack_44 = (float)in_ECX[0x34] * 0.00015258789;
    fStack_48 = (float)(fVar7 + (float10)fStack_58);
    piStack_20 = (int *)fStack_44;
    thunk_FUN_006c4230(s_C__dev_black_SpellFood_cpp_00b456e4,0xac);
    fVar7 = (float10)FUN_005b8600();
    fVar7 = (float10)FUN_0067bcb0((float)fVar7);
    fStack_58 = (float)(fVar7 * (float10)0.7 + (float10)0.3);
    Var8 = FUN_0067bcb0(0x40c90fdb,s_C__dev_black_SpellFood_cpp_00b456e4,0xad);
    fVar7 = (float10)fcos(Var8);
    uStack_24 = 0;
    fVar9 = (float10)fsin(Var8);
    fStack_28 = (float)fVar7 * fStack_58;
    fStack_4c = fStack_28 + fStack_4c;
    fStack_48 = fStack_48 + 0.0;
    fStack_44 = (float)((float10)fStack_44 + fVar9 * (float10)fStack_58);
    fStack_28 = (float)__ftol();
    uStack_24 = __ftol();
    piStack_20 = (int *)0x0;
    fVar7 = (float10)FUN_00760fd0();
    fStack_28 = 2.8026e-45;
    fStack_48 = (float)(fVar7 + (float10)0.2);
    FUN_004402a0(&fStack_4c);
    uStack_18 = 0;
    uStack_14 = 0;
    uStack_10 = 0;
    uStack_c = 0x3f800000;
    uStack_8 = 0;
    uStack_4 = 0;
    (**(code **)(*in_ECX + 0x52c))(&fStack_28);
    FUN_00548330();
    fVar5 = (float)__ftol();
    fStack_44 = fVar5;
    uStack_40 = __ftol();
    uStack_3c = 0;
    uStack_30 = 0;
    uStack_54 = 1;
    fStack_58 = 1.4013e-45;
    iVar4 = 9;
    fStack_38 = fVar5;
    uStack_34 = uStack_40;
    do {
      FUN_005bfab0(&piStack_2c);
      piVar2 = piStack_2c;
      while (piStack_2c = piVar2, piVar2 != (int *)0x0) {
        fVar7 = (float10)FUN_005c18d0(&fStack_44);
        fVar9 = (float10)(**(code **)(*piVar2 + 0x60))();
        fVar10 = (float10)(**(code **)(*in_ECX + 0x128))();
        if ((float10)(float)((float10)(float)fVar7 - fVar9) < fVar10 * (float10)2.5) {
          (**(code **)(*piStack_2c + 0x67c))();
        }
        piStack_2c = piStack_20;
        if (piStack_20 != (int *)0x0) {
          piStack_20 = (int *)(**(code **)(*piStack_20 + 0x53c))(uStack_24);
        }
        FUN_006bc130();
        piVar2 = piStack_2c;
      }
      uVar3 = FUN_006de790(&uStack_54,&fStack_58);
      FUN_005c1300(uVar3);
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    fVar5 = (float)in_ECX[0x2e];
    fVar1 = (float)in_ECX[0x3b];
    thunk_FUN_006c4230();
    fVar7 = (float10)FUN_005b8620();
    if (fVar7 < (float10)(fVar5 - fVar1)) {
      in_ECX[0x3b] = in_ECX[0x2e];
      piStack_2c = (int *)0xff80cbc5;
      fStack_28 = -NAN;
      uStack_24 = 0xffba97b2;
      piStack_20 = (int *)0xffb9ca86;
      uStack_1c = 0xffbd9c8a;
      iVar4 = FUN_0067bc90(5,s_C__dev_black_SpellFood_cpp_00b456e4,0xd1);
      piVar2 = (&piStack_2c)[iVar4];
      fVar7 = (float10)FUN_0067bcb0(0x40c90fdb,s_C__dev_black_SpellFood_cpp_00b456e4,0xd1);
      thunk_FUN_006c4230();
      fVar9 = (float10)FUN_005b85e0();
      iVar4 = 0;
      pbVar6 = &DAT_00dca634;
      do {
        if ((*pbVar6 & 1) == 0) {
          *(uint *)(&DAT_00dca634 + iVar4 * 0x38) = *(uint *)(&DAT_00dca634 + iVar4 * 0x38) | 1;
          (&DAT_00dca628)[iVar4 * 0xe] = uStack_50;
          (&DAT_00dca62c)[iVar4 * 0xe] = fStack_4c;
          (&DAT_00dca630)[iVar4 * 0xe] = fStack_48;
          (&DAT_00dca640)[iVar4 * 0xe] = (float)fVar9;
          (&DAT_00dca638)[iVar4 * 0xe] = 0;
          (&DAT_00dca64c)[iVar4 * 0xe] = 0x3f800000;
          (&DAT_00dca650)[iVar4 * 0xe] = 0x3f800000;
          (&DAT_00dca658)[iVar4 * 0xe] = 0x30;
          (&DAT_00dca648)[iVar4 * 0xe] = (float)fVar7;
          (&DAT_00dca65c)[iVar4 * 0xe] = piVar2;
          (&DAT_00dca654)[iVar4 * 0xe] = 0x3f800000;
          DAT_00dd8918 = DAT_00dd8918 + 1;
          return unaff_EBX;
        }
        pbVar6 = pbVar6 + 0x38;
        iVar4 = iVar4 + 1;
      } while (pbVar6 < &DAT_00dd8634);
    }
    return unaff_EBX;
  }
  return uVar3;
}



// ?Load@SpellWater@@UAEIAAVGameOSFile@@@Z @ 0x006bc210

undefined4 _Load_SpellWater__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Load_Spell__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0xec),4,0,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xec) + 4;
    }
    return 1;
  }
  return 0;
}



// ?Save@SpellWater@@UAEIAAVGameOSFile@@@Z @ 0x006bc280

undefined4 _Save_SpellWater__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_Spell__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0xec),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xec) + 4;
    }
    return 1;
  }
  return 0;
}



