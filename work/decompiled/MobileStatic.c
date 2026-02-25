// Decompiled functions for class: MobileStatic
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?SetXYZAngles@MobileStatic@@UAEXMMM@Z @ 0x004321a0

float10 _SetXYZAngles_MobileStatic__UAEXMMM_Z(void)

{
  int in_ECX;
  
  return (float10)*(float *)(in_ECX + 0x80);
}



// ?GetHowMuchCreatureWantsToLookAtMe@MobileStatic@@UAEMXZ @ 0x004321c0

bool _GetHowMuchCreatureWantsToLookAtMe_MobileStatic__UAEMXZ(undefined4 param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x3b4))(param_1);
  return iVar1 == 0;
}



// ?IsToyCuddly@MobileStatic@@UAEIPAVCreature@@@Z @ 0x004c5f50

undefined4 _IsToyCuddly_MobileStatic__UAEIPAVCreature___Z(int param_1)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  
  iVar1 = (**(code **)(*in_ECX + 0x3b4))(param_1);
  if ((iVar1 != 0) && (param_1 != 0)) {
    fVar2 = (float10)FUN_006de0a0(param_1 + 0x1200,in_ECX + 5);
    if ((float10)50.0 < fVar2) {
      return 1;
    }
  }
  return 0;
}



// ?GetBoundingSphere@MobileStatic@@UAEXAAULHPoint@@AAM@Z @ 0x004ee6d0

char _GetBoundingSphere_MobileStatic__UAEXAAULHPoint__AAM_Z(void)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = 0x196;
  if (*DAT_00d76c64 < 0x197) {
    iVar1 = 0;
  }
  iVar1 = DAT_00d76c64[iVar1 + 1];
  iVar2 = (**(code **)(**(int **)(in_ECX + 0x40) + 0xf8))();
  return (-(iVar2 != iVar1) & 5U) + 1;
}



// ?ChecksVerticesVObjects@MobileStatic@@UAEIXZ @ 0x004ee9a0

undefined4 _ChecksVerticesVObjects_MobileStatic__UAEIXZ(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = _GetBoundingSphere_MobileStatic__UAEXAAULHPoint__AAM_Z(param_1,param_2);
  FUN_005f6180(0);
  FUN_0067efc0();
  return uVar1;
}



// ?GetBoundingSphere@MobileStatic@@UAEXAAULHPoint@@AAM@Z @ 0x004eee80

void _GetBoundingSphere_MobileStatic__UAEXAAULHPoint__AAM_Z(undefined4 param_1,undefined4 param_2)

{
  _EndPhysics_Fixed__UAEXPAVPhysicsObject___N_Z(param_1,param_2);
  return;
}



// ?ToBeDeleted@MobileStatic@@UAEXH@Z @ 0x005c3630

void _ToBeDeleted_MobileStatic__UAEXH_Z(undefined4 param_1)

{
  _ToBeDeleted_MultiMapFixed__UAEXH_Z(param_1);
  return;
}



// ?GetPlayer@MobileStatic@@UAEPAVGPlayer@@XZ @ 0x005c3780

int _GetPlayer_MobileStatic__UAEPAVGPlayer__XZ(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x7c) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x005c3789. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (**(code **)(**(int **)(in_ECX + 0x7c) + 0x1c))();
    return iVar1;
  }
  return DAT_00c22ca4 + 0x18 + (uint)*(byte *)(DAT_00c22ca4 + 0x201b17) * 0x278;
}



// ?IsSolidToNewAbode@MobileStatic@@UAEIXZ @ 0x005c3990

void _IsSolidToNewAbode_MobileStatic__UAEIXZ
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x3cc))();
  if (iVar1 != 0) {
    _AddToRoutePlan_Object__UAEXPAVRPHolder__PAVCreature__HP6AXHUPoint2D__MH_Z_Z
              (param_1,param_2,param_3,param_4);
    return;
  }
  FUN_005eaea0(param_1,param_2,param_3,param_4);
  return;
}



// ?IsFence@MobileStatic@@UAEIXZ @ 0x005c3de0

bool _IsFence_MobileStatic__UAEIXZ(void)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = (**(code **)(**(int **)(in_ECX + 0x28) + 0x2c))();
  return iVar1 == 0x192;
}



// ?AddToRoutePlan@MobileStatic@@UAEXPAURPHolder@@PAVCreature@@HP6AXHUPoint2D@@MH@Z@Z @ 0x005c3f80

undefined4 _AddToRoutePlan_MobileStatic__UAEXPAURPHolder__PAVCreature__HP6AXHUPoint2D__MH_Z_Z(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x788))();
  if ((iVar1 != 3) && (iVar1 != 0x14)) {
    return 0;
  }
  return 1;
}



// ?ChecksVerticesVObjects@MobileStatic@@UAEIXZ @ 0x005c3fd0

undefined4 _ChecksVerticesVObjects_MobileStatic__UAEIXZ(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  iVar1 = FUN_005c3ea0();
  if (((iVar1 == 0) && (iVar1 = FUN_005c3ef0(), iVar1 == 0)) && (*(int *)(in_ECX[10] + 0x128) != 2))
  {
    iVar1 = (**(code **)(*in_ECX + 0x3cc))();
    if (iVar1 != 0) {
      return 0x12;
    }
    iVar1 = (**(code **)(*in_ECX + 0x3b4))(0);
    if (iVar1 == 0) {
      uVar2 = _GetPhysicsConstantsType_Object__UAEIXZ();
      return uVar2;
    }
    uVar2 = (**(code **)(*(int *)in_ECX[10] + 0x2c))();
    switch(uVar2) {
    case 399:
      return 0xe;
    case 400:
      return 0x14;
    case 0x191:
      return 0x10;
    case 0x192:
      return 0xf;
    case 0x193:
      return 0x13;
    }
  }
  return 3;
}



// ?GetCreatureBeliefType@MobileStatic@@UAEIXZ @ 0x00682810

void _GetCreatureBeliefType_MobileStatic__UAEIXZ(void)

{
  int *in_ECX;
  int *piStack_30;
  undefined4 *puStack_2c;
  undefined4 *puStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  int aiStack_14 [2];
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_1c = 0;
  uStack_20 = 1;
  uStack_24 = 0;
  puStack_28 = &uStack_c;
  puStack_2c = &uStack_c;
  piStack_30 = aiStack_14;
  uStack_c = 0;
  uStack_8 = 0;
  uStack_4 = 0;
  piStack_30 = (int *)(**(code **)(*in_ECX + 0x784))();
  piStack_30 = (int *)*piStack_30;
  if (piStack_30 != (int *)0x0) {
    if (aiStack_14[0] == 0) {
      FUN_0075b1b0(0,1);
    }
    FUN_005f3550(&piStack_30);
  }
  return;
}



// ?IsCastShadowAtNight@MobileStatic@@UAEIXZ @ 0x006c1690

undefined4 _IsCastShadowAtNight_MobileStatic__UAEIXZ(void)

{
  return 0xef7;
}



