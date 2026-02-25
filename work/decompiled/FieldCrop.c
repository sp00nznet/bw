// Decompiled functions for class: FieldCrop
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetSaveType@FieldCrop@@UAEIXZ @ 0x0052e630

undefined4 _GetSaveType_FieldCrop__UAEIXZ(void)

{
  return 0x6c;
}



// ?GetDebugText@FieldCrop@@UAEPADXZ @ 0x0052e640

char * _GetDebugText_FieldCrop__UAEPADXZ(void)

{
  return s_FieldCrop__00b1a328;
}



// ?ToBeDeleted@FieldCrop@@UAEXH@Z @ 0x005c3210

void _ToBeDeleted_FieldCrop__UAEXH_Z(undefined4 param_1)

{
  thunk_FUN_005c3230();
  _ToBeDeleted_MobileObject__UAEXH_Z(param_1);
  return;
}



// ?SetLife@FieldCrop@@UAEXM@Z @ 0x005c3250

void _SetLife_FieldCrop__UAEXM_Z(float param_1)

{
  int iVar1;
  int iVar2;
  int *in_ECX;
  float10 fVar3;
  
  if (param_1 <= 0.0) {
    (**(code **)(*in_ECX + 0xc))(0);
    return;
  }
  _SetLife_Object__UAEXM_Z(param_1);
  iVar1 = *in_ECX;
  iVar2 = in_ECX[10];
  fVar3 = (float10)(**(code **)(iVar1 + 0x11c))();
  (**(code **)(iVar1 + 0x124))((float)(fVar3 * (float10)*(float *)(iVar2 + 0x110)));
  return;
}



// ?ValidToApplyThisToObject@FieldCrop@@UAEIPAVGInterfaceStatus@@PAVObject@@@Z @ 0x005c32e0

undefined4
_ValidToApplyThisToObject_FieldCrop__UAEIPAVGInterfaceStatus__PAVObject___Z
          (undefined4 param_1,int *param_2)

{
  int iVar1;
  
  if (param_2 != (int *)0x0) {
    iVar1 = (**(code **)(*param_2 + 0x680))(0);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}



// ?InterfaceSetInMagicHand@FieldCrop@@UAEIPAVGInterfaceStatus@@@Z @ 0x005c3320

undefined4 _InterfaceSetInMagicHand_FieldCrop__UAEIPAVGInterfaceStatus___Z(void)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int *in_ECX;
  
  FUN_006169b0();
  uVar1 = __ftol();
  uVar2 = (**(code **)(*in_ECX + 0x48))(0,0,0x3f800000,0);
  iVar3 = FUN_00616c40(in_ECX + 5,&DAT_00c6e330,uVar1,0,uVar2);
  if (iVar3 != 0) {
    FUN_0059c850(iVar3);
  }
  (**(code **)(*in_ECX + 0xc))(0);
  return 0;
}



