// Decompiled functions for class: PuzzleHorse
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?IsMovingForAnimation@PuzzleHorse@@UAE_NXZ @ 0x004165d0

undefined4 _IsMovingForAnimation_PuzzleHorse__UAE_NXZ(void)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int *in_ECX;
  
  piVar1 = (int *)FUN_007344da(in_ECX[0x2f],0,&GameThingWithPos::RTTI_Type_Descriptor,
                               &Pot::RTTI_Type_Descriptor,0);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x690))();
    if (iVar2 == 0) {
      *(undefined2 *)(in_ECX + 0x39) = 0;
      uVar3 = (**(code **)(*piVar1 + 0x98))(0);
      if (uVar3 < 0x32) {
        uVar4 = (**(code **)(*piVar1 + 0x98))(0);
      }
      else {
        uVar4 = 0x32;
      }
      (**(code **)(*piVar1 + 0xa0))(0,uVar4,0,0);
    }
  }
  (**(code **)(*in_ECX + 0x998))();
  return 1;
}



// ?MoveInFlock@PuzzleHorse@@UAE_NXZ @ 0x00416f10

void _MoveInFlock_PuzzleHorse__UAE_NXZ(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x00416f12. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0xb44))();
  return;
}



// ?InHand@PuzzleHorse@@UAE_NXZ @ 0x004171e0

undefined4 _InHand_PuzzleHorse__UAE_NXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0xb9c))();
  if (iVar1 == 3) {
    *(undefined2 *)((int)in_ECX + 0xea) = 0;
    (**(code **)(*in_ECX + 0x8e4))(0x32);
    return 1;
  }
  (**(code **)(*in_ECX + 0x8e4))(0x1f);
  return 1;
}



// ?InHand@PuzzleHorse@@UAE_NXZ @ 0x00418a90

undefined4 _InHand_PuzzleHorse__UAE_NXZ(void)

{
  int iVar1;
  uint uVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0xb9c))();
  if (iVar1 == 3) {
    *(undefined2 *)((int)in_ECX + 0xea) = 0;
    (**(code **)(*in_ECX + 0x8e4))(0x32);
    return 1;
  }
  iVar1 = in_ECX[10];
  uVar2 = FUN_005aba00(*(undefined4 *)(iVar1 + 0x234));
  FUN_00416bb0(in_ECX + 5,iVar1,(uVar2 & 0xffff) << 1);
  if (in_ECX[0x2e] != 0) {
    if (*(int *)(in_ECX[0x2e] + 0x58) != 0) {
      iVar1 = FUN_004170d0();
      if (iVar1 == 0x23) {
        return 0x23;
      }
      (**(code **)(*in_ECX + 0x8e4))(0x20);
      return 0x23;
    }
    iVar1 = FUN_00416ff0();
    if (iVar1 == 0x23) {
      return 0x23;
    }
    iVar1 = FUN_004170d0();
    if (iVar1 == 0x23) {
      return 0x23;
    }
  }
  iVar1 = (**(code **)(*in_ECX + 3000))();
  if (iVar1 != 0x23) {
    (**(code **)(*in_ECX + 0x8e4))(0x1f);
  }
  return 1;
}



// ?Birthday@PuzzleHorse@@UAEXXZ @ 0x00419170

undefined4 _Birthday_PuzzleHorse__UAEXXZ(void)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *in_ECX;
  undefined4 uVar5;
  float fVar6;
  undefined1 auStack_c [12];
  
  iVar3 = in_ECX[0x2e];
  if (iVar3 != 0) {
    iVar2 = FUN_005ab9d0();
    if (iVar2 == 0) {
      iVar2 = FUN_00506580();
      if (iVar2 != 0) {
        FUN_006dea00(*(undefined2 *)(in_ECX[10] + 0x220));
        uVar1 = FUN_005aba20();
        fVar6 = (float)uVar1;
        uVar5 = 0;
        uVar4 = FUN_00506580(0,fVar6);
        FUN_005abae0(auStack_c,uVar4,uVar5,fVar6);
        FUN_005b0de0(auStack_c,0x2b);
        (**(code **)(*in_ECX + 0x864))(*(undefined4 *)(in_ECX[10] + 0x104));
        (**(code **)(*in_ECX + 0x934))(0,*(undefined4 *)(iVar3 + 0x78));
      }
    }
    else {
      iVar3 = (**(code **)(*in_ECX + 3000))();
      if (iVar3 != 0x23) {
        (**(code **)(*in_ECX + 0x8e4))(0x1f);
        (**(code **)(*in_ECX + 0xb44))();
        return 1;
      }
    }
  }
  return 1;
}



// ?CallOutofAnimationFunction@PuzzleHorse@@UAEHW4VILLAGER_STATES@@@Z @ 0x00419d30

undefined4
_CallOutofAnimationFunction_PuzzleHorse__UAEHW4VILLAGER_STATES___Z
          (undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int *in_ECX;
  undefined4 unaff_retaddr;
  
  iVar1 = (**(code **)(*in_ECX + 0x900))(param_2);
  if (iVar1 == 0) {
    return 0x2e;
  }
  iVar1 = (**(code **)(*in_ECX + 0x904))(unaff_retaddr,param_2);
  if (iVar1 != 0) {
    (**(code **)(*in_ECX + 0x8ec))();
    return 1;
  }
  return 0x2f;
}



// ?Dead@PuzzleHorse@@UAE_NXZ @ 0x0041a280

undefined4 _Dead_PuzzleHorse__UAE_NXZ(void)

{
  int *in_ECX;
  float10 fVar1;
  float10 fVar2;
  float afStack_20 [2];
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  float afStack_c [3];
  
  fVar1 = (float10)FUN_006ded00((short)in_ECX[0x17]);
  afStack_20[0] = (float)fVar1;
  fVar1 = (float10)(**(code **)(*in_ECX + 0x154))();
  fVar2 = (float10)fsin((float10)afStack_20[0]);
  afStack_c[1] = 0.0;
  uStack_18 = 0x40a00000;
  uStack_14 = 0;
  uStack_10 = 0;
  afStack_c[0] = (float)(fVar2 * fVar1);
  fVar2 = (float10)fcos((float10)afStack_20[0]);
  afStack_c[2] = (float)-(fVar2 * fVar1);
  (**(code **)(*in_ECX + 0x784))(afStack_20,afStack_c,&uStack_18,0,1,0);
  return 1;
}



// ?InHand@PuzzleHorse@@UAE_NXZ @ 0x0041ae60

undefined4 _InHand_PuzzleHorse__UAE_NXZ(void)

{
  int iVar1;
  uint uVar2;
  int *in_ECX;
  float10 fVar3;
  
  iVar1 = (**(code **)(*in_ECX + 0xb9c))();
  if (iVar1 == 3) {
    (**(code **)(*in_ECX + 0x8e4))(0x32);
    return 1;
  }
  fVar3 = (float10)FUN_00528ef0();
  if ((float10)22.0 < fVar3) {
    (**(code **)(*in_ECX + 0x8e4))(0x22);
    *(undefined2 *)(in_ECX + 0x3a) = *(undefined2 *)(in_ECX[10] + 0x214);
    return 0x23;
  }
  iVar1 = in_ECX[10];
  uVar2 = FUN_005aba00(*(undefined4 *)(iVar1 + 0x234));
  FUN_00416bb0(in_ECX + 5,iVar1,(uVar2 & 0xffff) << 1);
  iVar1 = FUN_00416ff0();
  if (iVar1 == 0x23) {
    return 0x23;
  }
  iVar1 = FUN_004170d0();
  if (iVar1 == 0x23) {
    return 0x23;
  }
  iVar1 = (**(code **)(*in_ECX + 3000))();
  if (iVar1 != 0x23) {
    (**(code **)(*in_ECX + 0x8e4))(0x1f);
  }
  return 1;
}



// ?InHand@PuzzleHorse@@UAE_NXZ @ 0x0041b8b0

undefined4 _InHand_PuzzleHorse__UAE_NXZ(void)

{
  FUN_0041b870();
  return 1;
}



// ?InHand@PuzzleHorse@@UAE_NXZ @ 0x0041c470

undefined4 _InHand_PuzzleHorse__UAE_NXZ(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  undefined4 uVar3;
  uint auStack_c [3];
  
  if (in_ECX[0x2e] != 0) {
    iVar1 = (**(code **)(*in_ECX + 3000))();
    if (iVar1 != 0x23) {
      auStack_c[0] = *(uint *)(in_ECX[0x2e] + 0x48);
      uVar3 = 0x33;
      auStack_c[1] = 0;
      uVar2 = FUN_006df6f0(auStack_c,in_ECX[0x2e] + 0x14,(float)auStack_c[0],0x33);
      FUN_005b0de0(uVar2,uVar3);
      (**(code **)(*in_ECX + 0x864))(*(undefined4 *)(in_ECX[10] + 0x104));
    }
  }
  return 1;
}



// ?Birthday@PuzzleHorse@@UAEXXZ @ 0x00464da0

undefined4 _Birthday_PuzzleHorse__UAEXXZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x160) + 8);
}



// ?InHand@PuzzleHorse@@UAE_NXZ @ 0x004d0630

undefined4 _InHand_PuzzleHorse__UAE_NXZ(void)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  
  uVar2 = 0;
  if (DAT_00b0e2ec != 0) {
    do {
      if (*(int *)(*(int *)(in_ECX + 0x164) + 0xf44) == 0) break;
      FUN_004d06b0();
      uVar2 = uVar2 + 1;
    } while (uVar2 < DAT_00b0e2ec);
  }
  if (*(int *)(*(int *)(in_ECX + 0x164) + 0xf44) == 0) {
    FUN_004d14e0();
    if ((*(int *)(*(int *)(in_ECX + 0x164) + 0xe98) < 0x28) && (iVar1 = FUN_004d05d0(), iVar1 == 1))
    {
      return 1;
    }
    FUN_004d1550(in_ECX);
  }
  return 1;
}



// ?Dying@PuzzleHorse@@UAE_NXZ @ 0x005aaff0

undefined4 _Dying_PuzzleHorse__UAE_NXZ(void)

{
  FUN_005ab520(0xf,1);
  return 1;
}



// ?Dead@PuzzleHorse@@UAE_NXZ @ 0x005ab000

undefined4 _Dead_PuzzleHorse__UAE_NXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  if (in_ECX[0x2e] != 0) {
    FUN_00505c20(in_ECX,1);
    FUN_005acec0(0);
  }
  if ((*(byte *)((int)in_ECX + 0x25) & 4) == 0) {
    iVar1 = in_ECX[0x16];
    *(short *)(in_ECX + 0x16) = (short)iVar1 + -1;
    if ((short)iVar1 == 0) goto LAB_005ab045;
  }
  iVar1 = (**(code **)(*in_ECX + 0x444))();
  if (iVar1 != 7) {
    return 1;
  }
LAB_005ab045:
  FUN_005eca60(0,0x3f800000,0xffffffff);
  (**(code **)(*in_ECX + 0xc))(0);
  return 5;
}



// ?BeingEaten@PuzzleHorse@@UAE_NXZ @ 0x005ab0d0

undefined4 _BeingEaten_PuzzleHorse__UAE_NXZ(void)

{
  int *in_ECX;
  
  *(short *)(in_ECX + 0x16) = (short)in_ECX[0x16] + -1;
  if ((short)in_ECX[0x16] == 0) {
    *(undefined2 *)(in_ECX + 0x16) = 0x32;
    if ((*(byte *)((int)in_ECX + 0x25) & 0x40) != 0) {
      FUN_005ab520(0xb,1);
      return 1;
    }
    (**(code **)(*in_ECX + 0x5b0))(0);
    FUN_005ab520(0xf,1);
  }
  return 1;
}



// ?Birthday@PuzzleHorse@@UAEXXZ @ 0x005ab550

uint _Birthday_PuzzleHorse__UAEXXZ(void)

{
  int in_ECX;
  
  return (uint)(*(int *)(DAT_00c22ca4 + 0x201afc) - *(int *)(in_ECX + 0xa0)) / DAT_00c22d44;
}



// ?FleeingFromObjectReaction@PuzzleHorse@@UAE_NXZ @ 0x005b0330

undefined4 _FleeingFromObjectReaction_PuzzleHorse__UAE_NXZ(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  float10 fVar3;
  
  if (in_ECX[0x2f] == 0) {
    return 0;
  }
  iVar1 = FUN_005ab4c0();
  if (iVar1 != 0) {
    fVar3 = (float10)FUN_006de0a0(in_ECX + 5,in_ECX[0x2f] + 0x14);
    FUN_005ab4c0();
    iVar1 = FUN_0067f950();
    if ((float)fVar3 <= *(float *)(iVar1 + 0x44)) {
      uVar2 = FUN_005b03b0(in_ECX[0x2f],0x1e,0x1e);
      return uVar2;
    }
  }
  (**(code **)(*in_ECX + 0x998))();
  return 1;
}



// ?LookingAtObjectReaction@PuzzleHorse@@UAE_NXZ @ 0x005b09c0

undefined4 _LookingAtObjectReaction_PuzzleHorse__UAE_NXZ(void)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  
  iVar1 = FUN_005ab4c0();
  if (iVar1 == 0) {
    return 0;
  }
  if (in_ECX[0x2f] == 0) {
    return 0;
  }
  fVar2 = (float10)FUN_006de0a0(in_ECX + 5,in_ECX[0x2f] + 0x14);
  FUN_005ab4c0();
  iVar1 = FUN_0067f950();
  if (*(float *)(iVar1 + 0x44) < (float)fVar2) {
    (**(code **)(*in_ECX + 0x998))();
    return 1;
  }
  FUN_005ab120(in_ECX[0x2f],1);
  return 1;
}



// ?FleeingAndLookingAtObjectReaction@PuzzleHorse@@UAE_NXZ @ 0x005b0a40

void _FleeingAndLookingAtObjectReaction_PuzzleHorse__UAE_NXZ(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005b0a42. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0x88c))();
  return;
}



// ?FollowingObjectReaction@PuzzleHorse@@UAE_NXZ @ 0x005b0a50

undefined4 _FollowingObjectReaction_PuzzleHorse__UAE_NXZ(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  int in_ECX;
  float10 fVar6;
  int iStack_c;
  int iStack_8;
  undefined4 uStack_4;
  
  if (*(int *)(in_ECX + 0xbc) == 0) {
    return 0;
  }
  piVar1 = (int *)(in_ECX + 0x14);
  fVar6 = (float10)FUN_006de0a0(piVar1,*(int *)(in_ECX + 0xbc) + 0x14);
  FUN_005ab4c0();
  iVar2 = FUN_0067f950();
  if (*(float *)(iVar2 + 0x44) < (float)fVar6) {
    uVar3 = FUN_006de3b0(piVar1,*(int *)(in_ECX + 0xbc) + 0x14);
    FUN_005ab4c0();
    iVar2 = FUN_0067f950();
    uVar4 = FUN_006dec60((float)fVar6 - *(float *)(iVar2 + 0x44));
    iVar2 = FUN_006de490(uVar3,uVar4);
    FUN_005ab4c0();
    iVar5 = FUN_0067f950();
    uVar4 = FUN_006dec90((float)fVar6 - *(float *)(iVar5 + 0x44));
    iStack_8 = FUN_006de4b0(uVar3,uVar4);
    uStack_4 = *(undefined4 *)(in_ECX + 0x1c);
    iStack_c = *piVar1 + iVar2;
    iStack_8 = *(int *)(in_ECX + 0x18) + iStack_8;
    FUN_005b0e40(&iStack_c,8);
    return 1;
  }
  FUN_005ab120(*(undefined4 *)(in_ECX + 0xbc),1);
  return 1;
}



// ?GotoFoodReaction@PuzzleHorse@@UAE_NXZ @ 0x005b0b60

undefined4 _GotoFoodReaction_PuzzleHorse__UAE_NXZ(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  undefined1 *puVar4;
  undefined1 auStack_c [12];
  
  piVar1 = (int *)FUN_007344da(in_ECX[0x2f],0,&GameThingWithPos::RTTI_Type_Descriptor,
                               &Object::RTTI_Type_Descriptor,0);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x2c))();
    if (iVar2 != 0) {
      puVar4 = auStack_c;
      uVar3 = (**(code **)(*piVar1 + 0x648))(puVar4);
      FUN_005b0e40(uVar3,puVar4);
      return 1;
    }
  }
  (**(code **)(*in_ECX + 0x998))();
  return 1;
}



// ?GotoWoodReaction@PuzzleHorse@@UAE_NXZ @ 0x005b0bd0

undefined4 _GotoWoodReaction_PuzzleHorse__UAE_NXZ(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  undefined1 *puVar4;
  undefined1 auStack_c [12];
  
  piVar1 = (int *)FUN_007344da(in_ECX[0x2f],0,&GameThingWithPos::RTTI_Type_Descriptor,
                               &Object::RTTI_Type_Descriptor,0);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x2c))();
    if (iVar2 != 0) {
      puVar4 = auStack_c;
      uVar3 = (**(code **)(*piVar1 + 0x648))(puVar4);
      FUN_005b0e40(uVar3,puVar4);
      return 1;
    }
  }
  (**(code **)(*in_ECX + 0x998))();
  return 1;
}



// ?IsMovingForAnimation@PuzzleHorse@@UAE_NXZ @ 0x005b0c40

undefined4 _IsMovingForAnimation_PuzzleHorse__UAE_NXZ(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x998))();
  return 1;
}



