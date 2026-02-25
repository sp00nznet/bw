// Decompiled functions for class: Animal
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetMesh@Animal@@UBEHXZ @ 0x00413fd0

undefined4 _GetMesh_Animal__UBEHXZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x28) + 0x200);
}



// ?GetDetailMesh@Animal@@UAEHH@Z @ 0x00413fe0

undefined4 _GetDetailMesh_Animal__UAEHH_Z(int param_1)

{
  int in_ECX;
  
  return *(undefined4 *)(*(int *)(in_ECX + 0x28) + 0x1fc + param_1 * 4);
}



// ?IsScriptState@Animal@@UBE_NW4VILLAGER_STATES@@@Z @ 0x00414020

undefined4 _IsScriptState_Animal__UBE_NW4VILLAGER_STATES___Z(int param_1)

{
  return *(undefined4 *)(&DAT_00b73fd0 + param_1 * 0xb8);
}



// ?ProcessBySpell@Animal@@UAEIPAVSpell@@@Z @ 0x00414040

void _ProcessBySpell_Animal__UAEIPAVSpell___Z(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0xbd4))();
  return;
}



// ?GetCreatureBeliefType@Animal@@UAEIXZ @ 0x00414070

undefined4 _GetCreatureBeliefType_Animal__UAEIXZ(void)

{
  return 7;
}



// ?GetTastiness@Animal@@UAEIXZ @ 0x00414090

undefined4 _GetTastiness_Animal__UAEIXZ(void)

{
  return 2;
}



// ?GetDeathReason@Animal@@UAE?AW4DEATH_REASON@@XZ @ 0x004140a0

undefined1 _GetDeathReason_Animal__UAE_AW4DEATH_REASON__XZ(void)

{
  int in_ECX;
  
  return *(undefined1 *)(in_ECX + 0x10c);
}



// ?ToBeDeleted@Animal@@UAEXH@Z @ 0x00414390

void _ToBeDeleted_Animal__UAEXH_Z(undefined4 param_1)

{
  FUN_004143d0();
  _ToBeDeleted__6LivingFi(param_1);
  return;
}



// ?ProcessState@Animal@@UAEIXZ @ 0x00414700

undefined4 _ProcessState_Animal__UAEIXZ(void)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  *(short *)(in_ECX + 0x24) = (short)in_ECX[0x24] + 1;
  FUN_004146b0();
  if (*(int *)(&DAT_00b7405c + (uint)*(byte *)(in_ECX + 0x23) * 0xb8) != 0) {
    (**(code **)(*in_ECX + 0xb98))();
    FUN_00414220();
  }
  if ((int *)in_ECX[0x3f] != (int *)0x0) {
    iVar1 = (**(code **)(*(int *)in_ECX[0x3f] + 0x2c))();
    if ((iVar1 == 0) || ((*(byte *)(in_ECX[0x3f] + 0x24) & 4) != 0)) {
      in_ECX[0x3f] = 0;
      *(undefined2 *)(in_ECX + 0x16) = 0;
      (**(code **)(*in_ECX + 0x8e4))(0x2b);
      return 1;
    }
  }
  FUN_004146b0();
  uVar2 = (**(code **)(&DAT_00c33238 + (uint)*(byte *)(in_ECX + 0x23) * 0x90))();
  return uVar2;
}



// ?SetSpeed@Animal@@UAEXH@Z @ 0x00414800

void _SetSpeed_Animal__UAEXH_Z(undefined4 param_1)

{
  int *in_ECX;
  
  _SetSpeed_MobileWallHug__UAEXH_Z(param_1);
  if (in_ECX[0x10] != 0) {
    (**(code **)(*in_ECX + 0x8f8))(0);
  }
  return;
}



// ?MoveTo3D@Animal@@UAEXXZ @ 0x00415210

undefined4 _MoveTo3D_Animal__UAEXXZ(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *in_ECX;
  float10 fVar6;
  float fStack_20;
  float fStack_10;
  
  iVar3 = (**(code **)(*in_ECX + 0x860))();
  fVar1 = *(float *)(iVar3 + 8);
  if (2.0 <= fVar1) {
    fVar1 = (float)in_ECX[7];
    fVar6 = (float10)FUN_00760fd0();
    fStack_20 = (float)(fVar6 + (float10)fVar1);
    iVar3 = (**(code **)(*in_ECX + 0x860))();
    fVar1 = *(float *)(iVar3 + 8);
    fVar6 = (float10)FUN_00760fd0();
    fVar1 = (float)(fVar6 + (float10)fVar1);
    uVar4 = FUN_005c5ba0();
    if (*(char *)((int)in_ECX + 0x5e) == '\x04') {
      uVar4 = 10;
    }
    FUN_00760fd0();
    fVar2 = *(float *)(in_ECX[10] + 0x274);
    if (fStack_20 <= fVar1 + fVar2) {
      if (fStack_20 < fVar1 - fVar2) {
        fStack_20 = fVar2 + fStack_20;
      }
    }
    else {
      fStack_20 = -fVar2 + fStack_20;
    }
    iVar3 = __ftol();
    iVar5 = __ftol();
    __ftol();
    __ftol();
    fVar6 = (float10)FUN_00760fd0();
    fStack_10 = (float)((float10)fStack_20 - fVar6);
    if ((float10)fStack_20 - fVar6 < (float10)2.0) {
      fStack_10 = 2.0;
    }
    in_ECX[5] = iVar3;
    in_ECX[6] = iVar5;
    in_ECX[7] = (int)fStack_10;
    return uVar4;
  }
  fVar2 = *(float *)(in_ECX[10] + 0x274);
  if ((float)in_ECX[7] <= fVar2 + fVar1) {
    if (fVar1 - fVar2 <= (float)in_ECX[7]) goto LAB_00415281;
    fVar2 = fVar2 + (float)in_ECX[7];
  }
  else {
    fVar2 = (float)in_ECX[7] - fVar2;
  }
  in_ECX[7] = (int)fVar2;
LAB_00415281:
  uVar4 = FUN_005c5ba0();
  if (*(char *)((int)in_ECX + 0x5e) != '\x04') {
    return uVar4;
  }
  return 10;
}



// ?GetHoldType@Animal@@UAE?AW4HOLD_TYPE@@XZ @ 0x004159d0

undefined4 _GetHoldType_Animal__UAE_AW4HOLD_TYPE__XZ(void)

{
  return 7;
}



// ?ValidForPlaceInHand@Animal@@UAEIPAVGInterfaceStatus@@@Z @ 0x00416070

bool _ValidForPlaceInHand_Animal__UAEIPAVGInterfaceStatus___Z(void)

{
  int in_ECX;
  
  return *(int *)(*(int *)(in_ECX + 0x28) + 0x228) != 0;
}



// ?InterfaceSetInMagicHand@Animal@@UAEIPAVGInterfaceStatus@@@Z @ 0x00416090

undefined4 _InterfaceSetInMagicHand_Animal__UAEIPAVGInterfaceStatus___Z(void)

{
  int iVar1;
  int *in_ECX;
  undefined4 uVar2;
  
  (**(code **)(*in_ECX + 0x8e8))();
  if (in_ECX[0x2e] != 0) {
    if ((*(byte *)(in_ECX[0x2e] + 0x25) & 4) == 0) {
      uVar2 = 1;
    }
    else {
      iVar1 = FUN_006a6640();
      if (iVar1 != 0) {
        FUN_006a66c0(iVar1);
      }
      uVar2 = 0;
    }
    FUN_00505ee0(in_ECX,uVar2);
  }
  (**(code **)(*in_ECX + 0x8e4))(0x18);
  return 1;
}



// ?CallVirtualFunctionsForCreation@Animal@@UAEXABUMapCoords@@@Z @ 0x00416570

void _CallVirtualFunctionsForCreation_Animal__UAEXABUMapCoords___Z(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x114) = 0;
  *(undefined4 *)(in_ECX + 0x110) = 0;
  *(undefined4 *)(in_ECX + 300) = 0;
  *(undefined4 *)(in_ECX + 0x128) = 0;
  *(undefined4 *)(in_ECX + 0x124) = 0;
  *(undefined4 *)(in_ECX + 0x13c) = 0;
  *(undefined4 *)(in_ECX + 0x138) = 0;
  *(undefined4 *)(in_ECX + 0x120) = 0;
  *(undefined4 *)(in_ECX + 0x134) = 0;
  *(undefined4 *)(in_ECX + 0x11c) = 0;
  *(undefined4 *)(in_ECX + 0x130) = 0;
  *(undefined4 *)(in_ECX + 0x118) = 0;
  _CallVirtualFunctionsForCreation_Living__UAEXABUMapCoords___Z(param_1);
  return;
}



// ?SaveObject@Animal@@UAEIAAULHOSFile@@ABUMapCoords@@@Z @ 0x00416660

int _SaveObject_Animal__UAEIAAULHOSFile__ABUMapCoords___Z(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int *in_ECX;
  undefined4 uVar7;
  char *pcVar8;
  undefined4 uVar9;
  undefined1 auStack_d4 [12];
  char acStack_c8 [100];
  undefined1 auStack_64 [100];
  
  iVar2 = FUN_0053eb80();
  if (iVar2 != 0) {
    if (param_2 != 0) {
      FUN_005c13b0(auStack_d4,param_2);
    }
    if (((int *)in_ECX[0x2e] == (int *)0x0) ||
       (iVar3 = (**(code **)(*(int *)in_ECX[0x2e] + 0x48))(), iVar3 == 0)) {
      uVar6 = 0xffffffff;
    }
    else {
      iVar3 = (**(code **)(*(int *)in_ECX[0x2e] + 0x48))();
      uVar6 = *(undefined4 *)(iVar3 + 0x5b4);
    }
    if (in_ECX[0x2e] == 0) {
      uVar7 = 0xffffffff;
    }
    else {
      uVar7 = *(undefined4 *)(in_ECX[0x2e] + 0x8c);
    }
    iVar3 = in_ECX[10];
    uVar4 = (**(code **)(*in_ECX + 0x8cc))();
    uVar9 = *(undefined4 *)(iVar3 + 500);
    uVar5 = FUN_005bf290(auStack_64);
    uVar6 = FUN_006ad590(0x19,uVar5,uVar9,uVar7,uVar6,uVar4);
    FUN_00733e17(acStack_c8,uVar6);
    iVar3 = -1;
    pcVar8 = acStack_c8;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      cVar1 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar1 != '\0');
    FUN_006b10c0();
  }
  return iVar2;
}



// ?GetAnimId@Animal@@UAE?AW4ANIM_LIST@@XZ @ 0x004167f0

undefined4 _GetAnimId_Animal__UAE_AW4ANIM_LIST__XZ(undefined4 param_1)

{
  byte bVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  bVar1 = (**(code **)(*in_ECX + 0xb00))();
  if (*(code **)(&DAT_00c33258 + (uint)bVar1 * 0x90) != (code *)0x0) {
    uVar2 = (**(code **)(&DAT_00c33258 + (uint)bVar1 * 0x90))(param_1);
    return uVar2;
  }
  return 1;
}



// ?CallEntryStateFunctionUcUc@Animal@@UAEIW4VILLAGER_STATES@@0@Z @ 0x00416840

undefined4 _CallEntryStateFunctionUcUc_Animal__UAEIW4VILLAGER_STATES__0_Z(uint param_1)

{
  undefined4 uVar1;
  int *in_ECX;
  int iVar2;
  
  iVar2 = (param_1 & 0xff) * 0x90;
  if (*(int *)(&DAT_00c33248 + iVar2) != 0) {
    uVar1 = (**(code **)(*in_ECX + 0xb00))(param_1);
    iVar2 = (**(code **)(&DAT_00c33248 + iVar2))(uVar1);
    if (iVar2 != 1) {
      return 0;
    }
  }
  (**(code **)(*in_ECX + 0x934))(0,param_1);
  return 1;
}



// ?CallExitStateFunction@Animal@@UAEIW4VILLAGER_STATES@@@Z @ 0x004168a0

int _CallExitStateFunction_Animal__UAEIW4VILLAGER_STATES___Z(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  int *in_ECX;
  int iVar2;
  
  iVar2 = (param_2 & 0xff) * 0x90;
  if (*(int *)(&DAT_00c33248 + iVar2) != 0) {
    uVar1 = (**(code **)(*in_ECX + 0xb00))(param_1);
    iVar2 = (**(code **)(&DAT_00c33248 + iVar2))(uVar1);
    if (iVar2 != 1) {
      return iVar2;
    }
  }
  if ((char)param_1 != (char)in_ECX[0x23]) {
    (**(code **)(*in_ECX + 0x934))(0,param_1);
  }
  (**(code **)(*in_ECX + 0x934))(1,param_2);
  return 1;
}



// ?SetNewWander@Animal@@UAEXABUMapCoords@@HH@Z @ 0x00416910

void _SetNewWander_Animal__UAEXABUMapCoords__HH_Z(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int in_ECX;
  uint uVar7;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  int local_4;
  
  local_10 = 0;
  local_c = 0;
  if (param_1 != 0) {
    iVar6 = in_ECX + 0x14;
    FUN_006de0a0(param_1,iVar6);
    iVar3 = __ftol();
    iVar5 = iVar6;
    if (((param_3 < iVar3) || (iVar5 = param_1, param_1 = iVar6, iVar3 < param_2)) &&
       (uVar4 = FUN_006de3b0(iVar5,param_1), uVar4 != 0)) {
      iVar6 = (&DAT_00b53a78)[uVar4 & 0xffff];
      uVar1 = *(ushort *)(in_ECX + 0x5a);
      iVar5 = FUN_00416ab0((int)((&DAT_00b54278)[uVar4 & 0xffff] * (uint)(uVar1 >> 4)) >> 0xc,
                           ((uint)uVar1 * 9) / 10,(uint)uVar1);
      local_4 = FUN_00416ab0((int)(iVar6 * (uint)(uVar1 >> 4)) >> 0xc,
                             ((uint)*(ushort *)(in_ECX + 0x5a) * 9) / 10,
                             (uint)*(ushort *)(in_ECX + 0x5a));
      local_8 = iVar5;
      FUN_00416ad0(&local_10,&local_8);
    }
  }
  iVar6 = FUN_00417230(&local_10);
  if (iVar6 != 1) {
    uVar1 = *(ushort *)(in_ECX + 0x5c);
    uVar2 = *(ushort *)(*(int *)(in_ECX + 0x28) + 0x220);
    iVar6 = FUN_0067bc90(uVar2,s_C__dev_black_Animal_cpp_008f7c84,0x6f7);
    uVar4 = iVar6 + ((uint)uVar1 - (uint)(uVar2 >> 1)) & 0x7ff;
    uVar7 = (uint)(*(ushort *)(in_ECX + 0x5a) >> 4);
    local_8 = (int)((&DAT_00b54278)[uVar4] * uVar7) >> 0xc;
    local_4 = (int)((&DAT_00b53a78)[uVar4] * uVar7) >> 0xc;
    FUN_00416ad0(&local_10,&local_8);
  }
  *(undefined4 *)(in_ECX + 0x6c) = local_c;
  *(undefined4 *)(in_ECX + 100) = local_10;
  *(undefined4 *)(in_ECX + 0x68) = 0;
  FUN_005c6c30();
  return;
}



// ?CallEntryStateFunctionUc@Animal@@UAEIW4VILLAGER_STATES@@@Z @ 0x00417630

undefined4 _CallEntryStateFunctionUc_Animal__UAEIW4VILLAGER_STATES___Z(undefined1 param_1)

{
  int iVar1;
  int *in_ECX;
  
  FUN_005c56b0(in_ECX);
  iVar1 = (**(code **)(*in_ECX + 0x968))(param_1);
  if (iVar1 == 0) {
    (**(code **)(*in_ECX + 0x994))();
  }
  return 1;
}



// ?DestroyedByEffect@Animal@@UAEIPAVGPlayer@@M@Z @ 0x00417670

undefined4 _DestroyedByEffect_Animal__UAEIPAVGPlayer__M_Z(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x6a4))();
  return 1;
}



// ?GetScriptObjectType@Animal@@UAEIXZ @ 0x004176a0

undefined4 _GetScriptObjectType_Animal__UAEIXZ(void)

{
  return 6;
}



// ?ValidToApplyThisToObject@Animal@@UAEIPAVGInterfaceStatus@@PAVObject@@@Z @ 0x004177c0

undefined4
_ValidToApplyThisToObject_Animal__UAEIPAVGInterfaceStatus__PAVObject___Z
          (undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_007344da(param_2,0,&Object::RTTI_Type_Descriptor,&StoragePit::RTTI_Type_Descriptor,0);
  if (iVar1 != 0) {
    return 1;
  }
  uVar2 = _ValidToApplyThisToObject_Living__UAEIPAVGInterfaceStatus__PAVObject___Z(param_1,param_2);
  return uVar2;
}



// ?ApplyThisToObject@Animal@@UAEIPAVGInterfaceStatus@@PAVObject@@PAUGestureSystemPacketData@@@Z @ 0x00417800

undefined4
_ApplyThisToObject_Animal__UAEIPAVGInterfaceStatus__PAVObject__PAUGestureSystemPacketData___Z
          (int *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (param_2 != (int *)0x0) {
    iVar1 = (**(code **)(*param_2 + 0x680))(0);
    if (iVar1 != 0) {
      if ((*(byte *)(in_ECX + 0x25) & 0x40) == 0) {
        iVar1 = (**(code **)(*param_2 + 0x684))();
        if (iVar1 != 0) {
          return 3;
        }
      }
      return 0;
    }
  }
  iVar1 = FUN_007344da(param_2,0,&Object::RTTI_Type_Descriptor,&WorshipTotem::RTTI_Type_Descriptor,0
                      );
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*param_1 + 0x1c))();
    if (iVar1 != 0) {
      FUN_004cb260(param_1,0x28,in_ECX,0);
      *(int *)(*(int *)(iVar1 + 0x25c) + 0x1124) = *(int *)(*(int *)(iVar1 + 0x25c) + 0x1124) + 1;
      FUN_004122c0(iVar1,in_ECX,7);
    }
    *(undefined1 *)(in_ECX + 0x10c) = 7;
  }
  uVar2 = _ApplyThisToObject_Living__UAEIPAVGInterfaceStatus__PAVObject__PAUGestureSystemPacketData___Z
                    (param_1,param_2,param_3);
  return uVar2;
}



// ?SetStateSpeed@Animal@@UAEXXZ @ 0x004178d0

undefined4 _SetStateSpeed_Animal__UAEXXZ(uint param_1)

{
  return *(undefined4 *)(&DAT_00b73fc4 + (param_1 & 0xff) * 0xb8);
}



// ?Save@Animal@@UAEIAAVGameOSFile@@@Z @ 0x004178f0

undefined4 _Save_Animal__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_Living__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0xe0));
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0xe4),2,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xe4) + 2;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90((byte *)(in_ECX + 0xe8),2,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xe8) + 2;
        if (DAT_00b19ac8 != 0) {
          iVar1 = FUN_0072be90((byte *)(in_ECX + 0xea),2,0);
          if (iVar1 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xea) + 2;
          if (DAT_00b19ac8 != 0) {
            iVar1 = FUN_0072be90((byte *)(in_ECX + 0xec),2,0);
            if (iVar1 == 3) {
              DAT_00b19ac8 = 0;
            }
            *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xec) + 2;
            if (DAT_00b19ac8 != 0) {
              iVar1 = FUN_0072be90((byte *)(in_ECX + 0xf4),8,0);
              if (iVar1 == 3) {
                DAT_00b19ac8 = 0;
              }
              *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xf4) + 8;
            }
          }
        }
      }
    }
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0xfc));
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x100),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x100) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90((byte *)(in_ECX + 0x104),4,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x104) + 4;
        if (DAT_00b19ac8 != 0) {
          iVar1 = FUN_0072be90((byte *)(in_ECX + 0x108),4,0);
          if (iVar1 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x108) + 4;
          if (DAT_00b19ac8 != 0) {
            iVar1 = FUN_0072be90((byte *)(in_ECX + 0x10c),1,0);
            if (iVar1 == 3) {
              DAT_00b19ac8 = 0;
            }
            *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x10c) + 1;
            if (DAT_00b19ac8 != 0) {
              iVar1 = FUN_0072be90((byte *)(in_ECX + 0x110),0x30,0);
              if (iVar1 == 3) {
                DAT_00b19ac8 = 0;
              }
              *(uint *)(param_1 + 0x214) =
                   *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x110) + 0x30;
            }
          }
        }
      }
    }
    FUN_00417f20(param_1);
    return 1;
  }
  return 0;
}



// ?Load@Animal@@UAEIAAVGameOSFile@@@Z @ 0x00417ba0

undefined4 _Load_Animal__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Load_Living__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    FUN_00531f30(in_ECX + 0xe0);
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0xe4),2,0,unaff_EBP,unaff_EBX,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xe4) + 2;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xe8) + 2;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xea) + 2;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xec) + 2;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xf4) + 8;
    }
    FUN_00531f30();
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x100) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x104) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x108) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x10c) + 1;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x110) + 0x30;
    }
    FUN_00417f30();
    return 1;
  }
  return 0;
}



// ?IsPosValidForTurnAngle@Animal@@UAE_NABUMapCoords@@@Z @ 0x00417f40

undefined4 _IsPosValidForTurnAngle_Animal__UAE_NABUMapCoords___Z(void)

{
  FUN_005aae80();
  return 1;
}



// ?ReactToPhysicsImpact@Animal@@UAEXPAVPhysicsObject@@_N@Z @ 0x00417ff0

void _ReactToPhysicsImpact_Animal__UAEXPAVPhysicsObject___N_Z(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  
  piVar1 = (int *)FUN_005f3c50();
  if (((piVar1 != (int *)0x0) && (iVar2 = (**(code **)(*piVar1 + 0x2c))(), iVar2 == 1)) &&
     (iVar2 = (**(code **)(*in_ECX + 0x2c))(), iVar2 == 1)) {
    iVar2 = *piVar1;
    uVar3 = (**(code **)(*in_ECX + 0x690))();
    iVar2 = (**(code **)(iVar2 + 0x680))(uVar3);
    if ((iVar2 != 0) && (iVar2 = (**(code **)(*piVar1 + 0x684))(), iVar2 != 0)) {
      return;
    }
  }
  _ReactToPhysicsImpact_Living__UAEXPAVPhysicsObject___N_Z(param_1,param_2);
  return;
}



// ?GetDefaultResource@Animal@@UAEHXZ @ 0x00418060

void _GetDefaultResource_Animal__UAEHXZ(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x660))(3);
  __ftol();
  return;
}



// ?GetPhysicsConstantsType@Animal@@UAEIXZ @ 0x004180b0

undefined4 _GetPhysicsConstantsType_Animal__UAEIXZ(void)

{
  return 8;
}



// ?CallEntryStateFunctionUcUc@Animal@@UAEIW4VILLAGER_STATES@@0@Z @ 0x00419ad0

void _CallEntryStateFunctionUcUc_Animal__UAEIW4VILLAGER_STATES__0_Z(void)

{
  _SetAnim__li_Living__UAEXHH_Z(0);
  return;
}



// ?GetFleeingPositionFromMovingObject@Animal@@UAEXPAUMapCoords@@PAVGameThingWithPos@@M@Z @ 0x0041a900

undefined4
_GetFleeingPositionFromMovingObject_Animal__UAEXPAUMapCoords__PAVGameThingWithPos__M_Z(void)

{
  float fVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  float10 extraout_ST0;
  int iStack00000004;
  float fStack_30;
  float fStack_28;
  
  fStack_30 = 0.0;
  fStack_28 = 0.0;
  FUN_00760fd0();
  iVar4 = __ftol();
  iVar5 = __ftol();
  FUN_00760fd0();
  __ftol();
  iVar6 = __ftol();
  fVar1 = (float)(extraout_ST0 - (float10)(((int)(iVar4 + (iVar4 >> 0x1f & 0xfU)) >> 4) * 0x10 + 8))
  ;
  fVar2 = (float)(((int)(iVar6 + (iVar6 >> 0x1f & 0xfU)) >> 4) * 0x10 + 8) -
          (float)(((int)(iVar5 + (iVar5 >> 0x1f & 0xfU)) >> 4) * 0x10 + 8);
  iStack00000004 = 1;
  if (fVar1 <= 0.0) {
    iStack00000004 = -1;
  }
  fVar3 = (float)iStack00000004;
  iStack00000004 = 1;
  fVar3 = fVar3 * fVar1;
  if (fVar2 <= 0.0) {
    iStack00000004 = -1;
  }
  fVar2 = (float)iStack00000004 * fVar2;
  do {
    if ((fVar3 <= fStack_30) && (fVar2 <= fStack_28)) {
      return 1;
    }
    fVar1 = fStack_28 * fVar3 - fStack_30 * fVar2;
    if (fVar1 == 0.0) {
      if (fVar3 <= fVar2) {
LAB_0041aaeb:
        fStack_28 = fStack_28 + 16.0;
      }
      else {
        fStack_30 = fStack_30 + 16.0;
      }
    }
    else {
      if (fVar1 <= 0.0) goto LAB_0041aaeb;
      fStack_30 = fStack_30 + 16.0;
    }
    iVar4 = __ftol();
    iVar5 = __ftol();
    if ((((iVar4 < 0) || (0x1ff < iVar4)) || (iVar5 < 0)) ||
       (((0x1ff < iVar5 || ((byte)(&DAT_00d73794)[(iVar5 >> 4) + (iVar4 >> 4) * 0x20] == 0)) ||
        ((&DAT_00d73394)[(byte)(&DAT_00d73794)[(iVar5 >> 4) + (iVar4 >> 4) * 0x20]] == 0)))) {
      return 0;
    }
  } while( true );
}



// ?ReactToBallPriority@Animal@@UAEEPAVReaction@@0@Z @ 0x0041b2f0

undefined1 _ReactToBallPriority_Animal__UAEEPAVReaction__0_Z(void)

{
  return DAT_00c70848;
}



// ?ReactToConfusedPriority@Animal@@UAEEPAVReaction@@0@Z @ 0x0041b300

undefined1 _ReactToConfusedPriority_Animal__UAEEPAVReaction__0_Z(void)

{
  return DAT_00c70eec;
}



// ?IsChild@Animal@@UAE_NXZ @ 0x0041b460

void _IsChild_Animal__UAE_NXZ(undefined4 param_1,int *param_2)

{
  int iVar1;
  int *in_ECX;
  float10 fVar2;
  int *unaff_retaddr;
  float fVar3;
  float fStack_30;
  float fStack_2c;
  float fStack_28;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_14;
  float fStack_10;
  
  (**(code **)(*param_2 + 0x168))(&fStack_24);
  if (0.0 < SQRT(fStack_20 * fStack_20 + fStack_24 * fStack_24 + fStack_28 * fStack_28)) {
    *unaff_retaddr = in_ECX[5];
    unaff_retaddr[1] = in_ECX[6];
    unaff_retaddr[2] = in_ECX[7];
    fStack_2c = fStack_28;
    fStack_1c = (float)in_ECX[5] * 10.0 * 1.5258789e-05 - (float)param_2[5] * 10.0 * 1.5258789e-05;
    fStack_14 = (float)in_ECX[6] * 10.0 * 1.5258789e-05 - (float)param_2[6] * 10.0 * 1.5258789e-05;
    fVar3 = -fStack_20;
    if (((fVar3 != 0.0) || (fStack_30 != 0.0)) || (fStack_28 != 0.0)) {
      fStack_2c = 1.0 / SQRT(fVar3 * fVar3 + fStack_30 * fStack_30 + fStack_28 * fStack_28);
      fVar3 = fStack_2c * fVar3;
      fStack_2c = fStack_2c * fStack_28;
    }
    fVar2 = (float10)FUN_0067bcb0(0x41000000,s_C__dev_black_AnimalReaction_cpp_008f8160,0xcc);
    fStack_10 = (float)(((float10)fVar3 * (float10)(float)param_2 + fVar2) - (float10)4.0);
    FUN_0067bcb0(0x41000000,s_C__dev_black_AnimalReaction_cpp_008f8160,0xcd);
    if (fVar3 * fStack_1c + fStack_2c * fStack_14 < 0.0) {
      iVar1 = __ftol();
      *unaff_retaddr = iVar1;
    }
    else {
      iVar1 = __ftol();
      *unaff_retaddr = iVar1;
    }
    iVar1 = __ftol();
    unaff_retaddr[1] = iVar1;
    return;
  }
  (**(code **)(*in_ECX + 0xafc))(unaff_retaddr,param_2,param_2);
  return;
}



// ?GetHowMuchCreatureWantsToLookAtMe@Animal@@UAEMXZ @ 0x004b5330

float10 _GetHowMuchCreatureWantsToLookAtMe_Animal__UAEMXZ(void)

{
  return (float10)0.7;
}



// ?IsAnimalBelongingToOtherPlayer@Animal@@UAEIPAVCreature@@@Z @ 0x004c54e0

bool _IsAnimalBelongingToOtherPlayer_Animal__UAEIPAVCreature___Z(int *param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  
  iVar1 = (**(code **)(*param_1 + 0x1c))();
  iVar2 = (**(code **)(*in_ECX + 0x1c))();
  return iVar2 != iVar1;
}



// ?GetCreatureMimicType@Animal@@UAEIXZ @ 0x004cb7a0

int _GetCreatureMimicType_Animal__UAEIXZ(void)

{
  int in_ECX;
  
  return 4 - (uint)(*(int *)(*(int *)(in_ECX + 0x28) + 0x14) != 1);
}



// ?Draw@Animal@@UAEXXZ @ 0x004f86e0

void _Draw_Animal__UAEXXZ(void)

{
  undefined4 *puVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  float *pfVar6;
  undefined4 uVar7;
  int *in_ECX;
  int iVar8;
  float *pfVar9;
  float *pfVar10;
  float10 fVar11;
  float10 fVar12;
  float afStack_30 [12];
  
  iVar5 = FUN_00527d30();
  if ((*(int *)(*(int *)(iVar5 + 0x3a0) + 0x4878) != 4) ||
     (*(int **)(*(int *)(iVar5 + 0x3a0) + 0x4904) != in_ECX)) {
    fVar11 = (float10)(**(code **)(*in_ECX + 0x120))();
    FUN_004f7510((float)fVar11);
    FUN_004f7830();
    fVar3 = (float)DAT_00dc8d20 * 0.001 + (float)in_ECX[0x49];
    in_ECX[0x49] = (int)fVar3;
    if (fVar3 < (float)in_ECX[0x4a]) {
      fVar2 = fVar3 * fVar3 * 0.5;
      fVar4 = fVar3 * fVar2 * 0.33333334;
      in_ECX[0x47] = (int)(fVar3 * (float)in_ECX[0x4d] +
                           fVar4 * (float)in_ECX[0x4f] + fVar2 * (float)in_ECX[0x4e] +
                          (float)in_ECX[0x4c]);
      in_ECX[0x44] = (int)((float)in_ECX[0x4c] * (float)in_ECX[0x49] +
                           fVar2 * (float)in_ECX[0x4d] +
                           fVar4 * (float)in_ECX[0x4e] +
                           fVar2 * fVar2 * 0.16666667 * (float)in_ECX[0x4f] + (float)in_ECX[0x4b]);
    }
    else {
      in_ECX[0x44] = in_ECX[0x45];
      in_ECX[0x47] = in_ECX[0x46];
      in_ECX[0x48] = 0;
      in_ECX[0x49] = in_ECX[0x4a];
    }
    fVar3 = (float)in_ECX[0x44];
    if (fVar3 != 0.0) {
      iVar5 = in_ECX[0x10];
      fVar11 = (float10)fcos((float10)fVar3);
      pfVar6 = (float *)(iVar5 + 0x14);
      pfVar9 = pfVar6;
      pfVar10 = afStack_30;
      for (iVar8 = 0xc; iVar8 != 0; iVar8 = iVar8 + -1) {
        *pfVar10 = *pfVar9;
        pfVar9 = pfVar9 + 1;
        pfVar10 = pfVar10 + 1;
      }
      fVar12 = (float10)fsin((float10)fVar3);
      fVar2 = *pfVar6;
      *pfVar6 = (float)(fVar11 * (float10)*pfVar6 - fVar12 * (float10)*(float *)(iVar5 + 0x20));
      *(float *)(iVar5 + 0x20) =
           (float)(fVar11 * (float10)*(float *)(iVar5 + 0x20) + fVar12 * (float10)fVar2);
      fVar2 = *(float *)(iVar5 + 0x18);
      *(float *)(iVar5 + 0x18) =
           (float)(fVar11 * (float10)*(float *)(iVar5 + 0x18) -
                  fVar12 * (float10)*(float *)(iVar5 + 0x24));
      *(float *)(iVar5 + 0x24) =
           (float)(fVar11 * (float10)*(float *)(iVar5 + 0x24) + fVar12 * (float10)fVar2);
      fVar2 = *(float *)(iVar5 + 0x1c);
      *(float *)(iVar5 + 0x1c) =
           (float)(fVar11 * (float10)*(float *)(iVar5 + 0x1c) -
                  fVar12 * (float10)*(float *)(iVar5 + 0x28));
      *(float *)(iVar5 + 0x28) =
           (float)(fVar11 * (float10)*(float *)(iVar5 + 0x28) +
                  (float10)(float)(fVar12 * (float10)fVar2));
    }
    if (in_ECX[0x11] == 0) {
      if (in_ECX[0x34] == 0) {
        iVar5 = in_ECX[0x10];
        puVar1 = (undefined4 *)(iVar5 + 0x50);
        FUN_0075fc20(iVar5 + 0x38,iVar5 + 0x4c,puVar1);
        uVar7 = FUN_0075d130(iVar5 + 0x38,*puVar1,iVar5 + 0x4c);
        *puVar1 = uVar7;
        FUN_005ed470();
      }
      else {
        FUN_00768080(in_ECX[0x34]);
        FUN_005ed470();
      }
    }
    else {
      FUN_004f46e0();
    }
    if (fVar3 != 0.0) {
      pfVar9 = afStack_30;
      pfVar10 = (float *)(in_ECX[0x10] + 0x14);
      for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
        *pfVar10 = *pfVar9;
        pfVar9 = pfVar9 + 1;
        pfVar10 = pfVar10 + 1;
      }
    }
    _Draw_PlannedMultiMapFixed__QAEXXZ();
  }
  return;
}



// ?SetUpPhysOb@Animal@@UAEXPAUPhysOb@@@Z @ 0x005aec60

void _SetUpPhysOb_Animal__UAEXPAUPhysOb___Z(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  int iVar9;
  undefined4 *puVar10;
  int *in_ECX;
  float *pfVar11;
  float10 fVar12;
  float10 fVar13;
  undefined4 uVar14;
  float fStack_34;
  float fStack_2c;
  float fStack_24;
  float fStack_20;
  float fStack_1c;
  float fStack_14;
  float fStack_c;
  float fStack_8;
  float fStack_4;
  
  fVar12 = (float10)(**(code **)(*in_ECX + 0x638))();
  fStack_34 = (float)fVar12;
  if (fVar12 < (float10)0.01) {
    fStack_34 = 0.01;
  }
  uVar14 = 1;
  iVar9 = (**(code **)(*in_ECX + 0x788))(1);
  FUN_00759e40(fStack_34,&DAT_00be7740 + iVar9 * 6,uVar14);
  *(undefined4 *)(param_1 + 0x154) = 0xc;
  iVar9 = FUN_00746d70(0x3c0,s_C__dev_black_LivingProjectile_cp_00b207a4,0x121);
  if (iVar9 == 0) {
    iVar9 = 0;
  }
  else {
    fStack_34 = 1.68156e-44;
    do {
      _GetPtr_Object__UAEPAV1_XZ();
      fStack_34 = (float)((int)fStack_34 + -1);
    } while (fStack_34 != 0.0);
  }
  *(int *)(param_1 + 0x15c) = iVar9;
  fVar12 = (float10)(**(code **)(*in_ECX + 0x120))();
  fVar13 = (float10)(**(code **)(*in_ECX + 0x42c))();
  *(undefined4 *)(param_1 + 0xf8) = 0;
  *(undefined4 *)(param_1 + 0x100) = 0;
  *(float *)(param_1 + 0xfc) = (float)(fVar13 * (float10)(float)((float10)0.5 / fVar12));
  fVar12 = (float10)(**(code **)(*in_ECX + 0x42c))();
  fVar1 = (float)(fVar12 * (float10)0.5);
  fVar12 = (float10)(**(code **)(*in_ECX + 100))();
  puVar10 = *(undefined4 **)(param_1 + 0x15c);
  fVar2 = (float)(fVar12 * (float10)0.3);
  fVar3 = (float)(fVar12 * (float10)0.9);
  fVar4 = (float)(fVar12 * (float10)0.25);
  fVar5 = (float)(fVar12 * (float10)0.8);
  FUN_00402280();
  fVar12 = (float10)fcos((float10)1.5707963705062866);
  iVar9 = 0;
  fVar13 = (float10)fsin((float10)1.5707963705062866);
  if (0 < *(int *)(param_1 + 0x154)) {
    pfVar11 = (float *)(puVar10 + 5);
    do {
      *puVar10 = 0;
      pfVar11[-2] = 0.0;
      pfVar11[-3] = 0.0;
      pfVar11[-4] = 0.0;
      fVar6 = fVar3;
      switch(iVar9) {
      case 0:
        pfVar11[-1] = fVar4;
        *pfVar11 = fVar1;
        pfVar11[1] = fVar5;
        break;
      case 1:
        *pfVar11 = fVar1;
        pfVar11[-1] = -fVar4;
        fVar6 = fVar5;
        goto LAB_005aeede;
      case 2:
        *pfVar11 = fVar1;
        pfVar11[-1] = -fVar4;
        pfVar11[1] = fVar5;
        break;
      case 3:
        pfVar11[-1] = fVar4;
        *pfVar11 = fVar1;
        fVar6 = fVar5;
        goto LAB_005aeede;
      case 4:
        pfVar11[-1] = fVar2;
        *pfVar11 = 0.0;
        pfVar11[1] = fVar3;
        break;
      case 5:
        *pfVar11 = 0.0;
        pfVar11[-1] = -fVar2;
        goto LAB_005aeede;
      case 6:
        *pfVar11 = 0.0;
        pfVar11[-1] = -fVar2;
        pfVar11[1] = fVar3;
        break;
      case 7:
        pfVar11[-1] = fVar2;
        *pfVar11 = 0.0;
        goto LAB_005aeede;
      case 8:
        pfVar11[-1] = fVar4;
        *pfVar11 = -fVar1;
        pfVar11[1] = fVar5;
        break;
      case 9:
        pfVar11[-1] = -fVar4;
        goto LAB_005aeed2;
      case 10:
        pfVar11[1] = fVar5;
        pfVar11[-1] = -fVar4;
        *pfVar11 = -fVar1;
        break;
      case 0xb:
        pfVar11[-1] = fVar4;
LAB_005aeed2:
        *pfVar11 = -fVar1;
        fVar6 = fVar5;
LAB_005aeede:
        pfVar11[1] = -fVar6;
      }
      fVar6 = pfVar11[-1];
      fVar7 = *pfVar11;
      fVar8 = pfVar11[1];
      pfVar11[-1] = fVar6 * (float)fVar12 + fStack_24 * fVar7 + (float)-fVar13 * fVar8 + fStack_c;
      *pfVar11 = fStack_2c * fVar6 + fStack_20 * fVar7 + fStack_14 * fVar8 + fStack_8;
      pfVar11[1] = (float)fVar13 * fVar6 + (float)fVar12 * fVar8 + fStack_1c * fVar7 + fStack_4;
      if (*(float *)(param_1 + 0x150) <=
          SQRT(pfVar11[-1] * pfVar11[-1] + *pfVar11 * *pfVar11 + pfVar11[1] * pfVar11[1])) {
        fVar6 = SQRT(pfVar11[-1] * pfVar11[-1] + *pfVar11 * *pfVar11 + pfVar11[1] * pfVar11[1]);
      }
      else {
        fVar6 = *(float *)(param_1 + 0x150);
      }
      puVar10 = puVar10 + 0x14;
      pfVar11 = pfVar11 + 0x14;
      iVar9 = iVar9 + 1;
      *(float *)(param_1 + 0x150) = fVar6;
    } while (iVar9 < *(int *)(param_1 + 0x154));
  }
  *(undefined4 *)(param_1 + 0x160) = 0x14;
  puVar10 = (undefined4 *)FUN_00746d70(0x2d0,s_C__dev_black_LivingProjectile_cp_00b207a4,0x16a);
  *(undefined4 **)(param_1 + 0x164) = puVar10;
  puVar10[2] = 0;
  *puVar10 = 1;
  puVar10[1] = 2;
  puVar10[9] = 0;
  puVar10[0xb] = 1;
  puVar10[10] = 3;
  puVar10[0x14] = 3;
  puVar10[0x13] = 1;
  puVar10[0x12] = 5;
  puVar10[0x1d] = 3;
  puVar10[0x1c] = 5;
  puVar10[0x1b] = 7;
  puVar10[0x25] = 3;
  puVar10[0x24] = 7;
  puVar10[0x26] = 0;
  puVar10[0x2e] = 7;
  puVar10[0x2f] = 0;
  puVar10[0x2d] = 4;
  puVar10[0x38] = 0;
  puVar10[0x37] = 4;
  puVar10[0x36] = 6;
  puVar10[0x41] = 0;
  puVar10[0x40] = 6;
  puVar10[0x3f] = 2;
  puVar10[0x48] = 6;
  puVar10[0x49] = 2;
  puVar10[0x4a] = 1;
  puVar10[0x53] = 1;
  puVar10[0x52] = 6;
  puVar10[0x51] = 5;
  puVar10[0x5c] = 7;
  puVar10[0x5a] = 9;
  puVar10[0x5b] = 5;
  puVar10[0x65] = 7;
  puVar10[100] = 9;
  puVar10[99] = 0xb;
  puVar10[0x6d] = 7;
  puVar10[0x6c] = 0xb;
  puVar10[0x6e] = 4;
  puVar10[0x75] = 8;
  puVar10[0x76] = 0xb;
  puVar10[0x77] = 4;
  puVar10[0x7f] = 8;
  puVar10[0x80] = 4;
  puVar10[0x7e] = 10;
  puVar10[0x87] = 6;
  puVar10[0x88] = 10;
  puVar10[0x89] = 4;
  puVar10[0x91] = 6;
  puVar10[0x90] = 10;
  puVar10[0x92] = 5;
  puVar10[0x9a] = 10;
  puVar10[0x9b] = 5;
  puVar10[0x99] = 9;
  puVar10[0xa3] = 10;
  puVar10[0xa2] = 0xb;
  puVar10[0xa4] = 9;
  puVar10[0xac] = 10;
  puVar10[0xab] = 8;
  puVar10[0xad] = 0xb;
  FUN_00759eb0();
  *(float *)(param_1 + 0x14c) = *(float *)(param_1 + 0x14c) + *(float *)(param_1 + 0x14c);
  FUN_0075ad90();
  return;
}



// ?EndPhysics@Animal@@UAEXPAVPhysicsObject@@_N@Z @ 0x005af4d0

undefined4 _EndPhysics_Animal__UAEXPAVPhysicsObject___N_Z(int param_1,undefined4 param_2)

{
  byte bVar1;
  undefined4 uVar2;
  int *in_ECX;
  short sVar3;
  float10 fVar4;
  
  sVar3 = 3;
  if (param_1 != 0) {
    if (*(float *)(param_1 + 0xd8) <= 0.5) {
      if (-0.5 <= *(float *)(param_1 + 0xd8)) {
        sVar3 = 0;
      }
      else {
        sVar3 = 2;
      }
    }
    else {
      sVar3 = 1;
    }
    fVar4 = (float10)FUN_00759180(param_1 + 0xbc);
    fVar4 = (float10)FUN_007591d0((float)(fVar4 + (float10)3.1415927));
    (**(code **)(*in_ECX + 0x524))((float)fVar4);
  }
  uVar2 = _EndPhysics_Object__UAEXPAVPhysicsObject___N_Z(param_1,param_2);
  *(ushort *)(in_ECX + 0x2d) = *(ushort *)(in_ECX + 0x2d) & 0xffcf | sVar3 << 4;
  in_ECX[7] = 0;
  fVar4 = (float10)(**(code **)(*in_ECX + 0x11c))();
  if ((float10)0.0 < fVar4) {
    (**(code **)(*in_ECX + 0x8e4))(0xb);
  }
  else {
    bVar1 = *(byte *)(in_ECX + 0x2d);
    (**(code **)(*in_ECX + 0x6a4))();
    *(ushort *)(in_ECX + 0x2d) = *(ushort *)(in_ECX + 0x2d) & 0xffcf | sVar3 << 4;
    if ((bVar1 & 1) == 1) {
      (**(code **)(*in_ECX + 0x8e4))(0xf);
      return uVar2;
    }
  }
  return uVar2;
}



// ?IsPosValidForTurnAngle@Animal@@UAE_NABUMapCoords@@@Z @ 0x0067b9c0

bool _IsPosValidForTurnAngle_Animal__UAE_NABUMapCoords___Z(int param_1,int param_2)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x148) == param_1) {
    return false;
  }
  return *(int *)(in_ECX + 0x14c) - param_2 == *(int *)(in_ECX + 0x150) * 2 + -1;
}



// ?GetHoldLoweringMultiplier@Animal@@UAEMXZ @ 0x006e0580

float10 _GetHoldLoweringMultiplier_Animal__UAEMXZ(void)

{
  return (float10)0.65;
}



