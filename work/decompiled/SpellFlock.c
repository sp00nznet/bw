// Decompiled functions for class: SpellFlock
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?NeedsContinualPackets@SpellFlock@@UAE_NPAVGInterfaceStatus@@@Z @ 0x006ba190

undefined4 _NeedsContinualPackets_SpellFlock__UAE_NPAVGInterfaceStatus___Z(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x55c))();
  if (in_ECX[0x3e] < iVar1) {
    iVar1 = FUN_006b74b0();
    if (iVar1 != 0) {
      iVar1 = (**(code **)(*param_1 + 0x1c))();
      iVar2 = (**(code **)(*in_ECX + 0x1c))();
      if (iVar1 == iVar2) {
        return 1;
      }
    }
  }
  uVar3 = _NeedsContinualPackets_Spell__UAE_NPAVGInterfaceStatus___Z(param_1);
  return uVar3;
}



// ?InitWithPos@SpellFlock@@UAEHPAVGameThing@@ABUMapCoords@@PAVSpellCastData@@ABUPSysProcessInfo@@@Z @ 0x006ba1e0

void _InitWithPos_SpellFlock__UAEHPAVGameThing__ABUMapCoords__PAVSpellCastData__ABUPSysProcessInfo___Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  float fVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  float10 fVar4;
  undefined4 uVar5;
  
  iVar2 = __ftol();
  in_ECX[0x40] = iVar2;
  iVar2 = __ftol();
  in_ECX[0x41] = iVar2;
  __ftol();
  __ftol();
  fVar1 = *(float *)(param_4 + 0x10);
  fVar4 = (float10)FUN_00760fd0();
  in_ECX[0x42] = (int)(float)((float10)fVar1 - fVar4);
  iVar2 = FUN_004300a0(0x90,s_C__dev_black_SpellFlock_cpp_00b456c8,0x90);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    uVar5 = 0xaba52;
    uVar3 = (**(code **)(*in_ECX + 0x1c))(0xaba52);
    iVar2 = FUN_005058f0(param_2,&DAT_00b7feac,uVar3,uVar5);
  }
  in_ECX[0x3d] = iVar2;
  *(undefined2 *)(iVar2 + 0x52) = *(undefined2 *)(iVar2 + 0x50);
  _InitWithPos_Spell__UAEHPAVGameThing__ABUMapCoords__PAVSpellCastData__ABUPSysProcessInfo___Z
            (param_1,param_2,param_3,param_4);
  return;
}



// ?Process@SpellFlock@@UAEIXZ @ 0x006ba2e0

undefined4 _Process_SpellFlock__UAEIXZ(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *in_ECX;
  float10 fVar6;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined1 local_34 [12];
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined1 uStack_8;
  undefined4 uStack_4;
  
  if (in_ECX[0x10] == 0) {
    for (puVar1 = (undefined4 *)in_ECX[0x3b]; puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      piVar2 = (int *)puVar1[1];
      FUN_005c0400(&local_40);
      FUN_005c0400(local_34);
      fVar6 = (float10)(**(code **)(*piVar2 + 0x60))();
      iVar4 = FUN_0066f2c0(local_34,&local_40,(float)fVar6);
      if (iVar4 != 0) {
        uStack_1c = uStack_38;
        uStack_28 = 4;
        uStack_24 = local_40;
        uStack_20 = uStack_3c;
        uStack_18 = 0;
        uStack_14 = 0;
        uStack_10 = 0;
        uStack_c = 0x3f800000;
        uStack_8 = 0;
        uStack_4 = 0;
        uStack_4 = FUN_0066f1b0();
        iVar4 = (**(code **)(*in_ECX + 0x52c))(&uStack_28);
        if (iVar4 == 0) {
          (**(code **)(*piVar2 + 0x6a4))();
        }
        FUN_0066f190(&local_40);
      }
    }
  }
  uVar5 = _Process_SpellWithObjects__UAEIXZ();
  if ((int *)in_ECX[0x3d] != (int *)0x0) {
    iVar4 = (**(code **)(*(int *)in_ECX[0x3d] + 0x2c))();
    if (iVar4 != 1) {
      in_ECX[0x3d] = 0;
      return uVar5;
    }
    iVar4 = in_ECX[0x3d];
    if ((*(int *)(iVar4 + 0x40) != 0) && (iVar3 = *(int *)(*(int *)(iVar4 + 0x40) + 8), iVar3 != 0))
    {
      *(undefined4 *)(iVar4 + 0x14) = *(undefined4 *)(iVar3 + 0x14);
      *(undefined4 *)(iVar4 + 0x18) = *(undefined4 *)(iVar3 + 0x18);
      *(undefined4 *)(iVar4 + 0x1c) = *(undefined4 *)(iVar3 + 0x1c);
    }
  }
  return uVar5;
}



// ?Load@SpellFlock@@UAEIAAVGameOSFile@@@Z @ 0x006bb630

undefined4 _Load_SpellFlock__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Load_SpellWithObjects__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    FUN_00531f30(in_ECX + 0xf4);
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0xf8),4,0,unaff_EDI,unaff_EBP,unaff_ESI,unaff_EBX);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xf8) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xfc) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x100) + 0xc;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x10c) + 4;
    }
    return 1;
  }
  return 0;
}



// ?Save@SpellFlock@@UAEIAAVGameOSFile@@@Z @ 0x006bb750

undefined4 _Save_SpellFlock__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_SpellWithObjects__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0xf4));
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0xf8),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xf8) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90((byte *)(in_ECX + 0xfc),4,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xfc) + 4;
        if (DAT_00b19ac8 != 0) {
          iVar1 = FUN_0072be90((byte *)(in_ECX + 0x100),0xc,0);
          if (iVar1 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x100) + 0xc;
          if (DAT_00b19ac8 != 0) {
            iVar1 = FUN_0072be90((byte *)(in_ECX + 0x10c),4,0);
            if (iVar1 == 3) {
              DAT_00b19ac8 = 0;
            }
            *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x10c) + 4;
          }
        }
      }
    }
    return 1;
  }
  return 0;
}



