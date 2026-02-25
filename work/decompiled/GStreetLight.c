// Decompiled functions for class: GStreetLight
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetText@GStreetLight@@UAEPBDXZ @ 0x00531530

char * _GetText_GStreetLight__UAEPBDXZ(void)

{
  return s_StreetLight_00b1b2fc;
}



// ?GetSaveType@GStreetLight@@UAEIXZ @ 0x00531540

undefined4 _GetSaveType_GStreetLight__UAEIXZ(void)

{
  return 0xff;
}



// ?GetDebugText@GStreetLight@@UAEPADXZ @ 0x00531550

char * _GetDebugText_GStreetLight__UAEPADXZ(void)

{
  return s_StreetLight__00b1b308;
}



// ?ResolveLoad@GStreetLight@@UAEXXZ @ 0x005c2090

void _ResolveLoad_GStreetLight__UAEXXZ(void)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x500))(in_ECX + 5);
  return;
}



// ?ToBeDeleted@GStreetLight@@UAEXH@Z @ 0x006cab50

void _ToBeDeleted_GStreetLight__UAEXH_Z(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  iVar2 = DAT_00c22ca4;
  iVar3 = *(int *)(DAT_00c22ca4 + 0x201ce8);
  if (iVar3 == in_ECX) {
    *(int *)(DAT_00c22ca4 + 0x201ce8) = *(int *)(in_ECX + 0x28);
  }
  else {
    if (iVar3 == 0) goto LAB_006cab98;
    while (iVar1 = *(int *)(iVar3 + 0x28), iVar1 != in_ECX) {
      iVar3 = iVar1;
      if (iVar1 == 0) {
        _ToBeDeleted_GameThingWithPos__UAEXH_Z(param_1);
        return;
      }
    }
    *(undefined4 *)(iVar3 + 0x28) = *(undefined4 *)(in_ECX + 0x28);
  }
  *(int *)(iVar2 + 0x201cec) = *(int *)(iVar2 + 0x201cec) + -1;
  *(undefined4 *)(in_ECX + 0x28) = 0;
LAB_006cab98:
  _ToBeDeleted_GameThingWithPos__UAEXH_Z(param_1);
  return;
}



// ?GetDistanceFromObject@GStreetLight@@UAEMPBUMapCoords@@@Z @ 0x006cad00

float10 _GetDistanceFromObject_GStreetLight__UAEMPBUMapCoords___Z(undefined4 param_1)

{
  int in_ECX;
  float10 fVar1;
  float10 fVar2;
  
  fVar1 = (float10)FUN_006de0a0(in_ECX + 0x14,param_1);
  fVar2 = (float10)FUN_006cacf0();
  return (float10)(float)fVar1 - fVar2;
}



// ?Save@GStreetLight@@UAEIAAVGameOSFile@@@Z @ 0x006cad30

bool _Save_GStreetLight__UAEIAAVGameOSFile___Z(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _Save_GameThingWithPos__UAEXPAUGameOSFile___Z(param_1);
  return iVar1 != 0;
}



// ?Load@GStreetLight@@UAEIAAVGameOSFile@@@Z @ 0x006cad50

bool _Load_GStreetLight__UAEIAAVGameOSFile___Z(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _Load_GameThingWithPos__QAEIAAVGameOSFile___Z(param_1);
  return iVar1 != 0;
}



