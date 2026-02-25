// Decompiled functions for class: CreatureFalling
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?SetAnimTime@CreatureFalling@@UAEXHH@Z @ 0x00468d50

void _SetAnimTime_CreatureFalling__UAEXHH_Z(undefined4 param_1,int param_2)

{
  int in_ECX;
  int *piVar1;
  int iVar2;
  
  switch(param_1) {
  case 0x51:
  case 0x52:
  case 0x53:
  case 0x54:
    _SetAnimTime_Morphable__UAEXHH_Z(0x51,param_2);
    _SetAnimTime_Morphable__UAEXHH_Z(0x52,param_2);
    _SetAnimTime_Morphable__UAEXHH_Z(0x53,param_2);
    _SetAnimTime_Morphable__UAEXHH_Z(0x54,param_2);
    return;
  default:
    _SetAnimTime_Morphable__UAEXHH_Z(param_1,param_2);
    return;
  case 0x5b:
  case 0x5c:
    _SetAnimTime_Morphable__UAEXHH_Z(0x5b,param_2);
    _SetAnimTime_Morphable__UAEXHH_Z(0x5c,param_2);
    return;
  case 0x60:
  case 0x61:
    _SetAnimTime_Morphable__UAEXHH_Z(param_1,param_2);
    return;
  case 0x71:
  case 0x72:
  case 0x73:
  case 0x74:
    _SetAnimTime_Morphable__UAEXHH_Z(0x71,param_2);
    _SetAnimTime_Morphable__UAEXHH_Z(0x72,param_2);
    _SetAnimTime_Morphable__UAEXHH_Z(0x73,param_2);
    _SetAnimTime_Morphable__UAEXHH_Z(0x74,param_2);
    return;
  case 0x93:
    iVar2 = 0;
    piVar1 = (int *)(in_ECX + 0x51f8);
  }
  do {
    _SetAnimTime_Morphable__UAEXHH_Z(iVar2 + 0x93,*piVar1 * param_2);
    iVar2 = iVar2 + 1;
    piVar1 = piVar1 + 1;
  } while (iVar2 < 7);
  return;
}



