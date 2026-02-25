// Decompiled functions for class: PileFood
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?ToBeDeleted@PileFood@@UAEXH@Z @ 0x00617dc0

void _ToBeDeleted_PileFood__UAEXH_Z(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0xb8) != (int *)0x0) {
    iVar2 = (**(code **)(**(int **)(in_ECX + 0xb8) + 0x2c))();
    if (iVar2 == 1) {
      (**(code **)(**(int **)(in_ECX + 0xb8) + 0xc))(0);
    }
  }
  iVar2 = DAT_00c22ca4;
  if ((*(byte *)(in_ECX + 10) & 1) == 0) {
    iVar3 = *(int *)(DAT_00c22ca4 + 0x201cf8);
    if (iVar3 == in_ECX) {
      *(int *)(DAT_00c22ca4 + 0x201cf8) = *(int *)(in_ECX + 0xb4);
    }
    else {
      if (iVar3 == 0) goto LAB_00617e42;
      while (iVar1 = *(int *)(iVar3 + 0xb4), iVar1 != in_ECX) {
        iVar3 = iVar1;
        if (iVar1 == 0) {
          _ToBeDeleted_PotStructure__UAEXH_Z(param_1);
          return;
        }
      }
      *(undefined4 *)(iVar3 + 0xb4) = *(undefined4 *)(in_ECX + 0xb4);
    }
    *(int *)(iVar2 + 0x201cfc) = *(int *)(iVar2 + 0x201cfc) + -1;
    *(undefined4 *)(in_ECX + 0xb4) = 0;
  }
LAB_00617e42:
  _ToBeDeleted_PotStructure__UAEXH_Z(param_1);
  return;
}



// ?GetQueryFirstEnumText@PileFood@@UAE?AW4HELP_TEXT@@XZ @ 0x00617f30

undefined4 _GetQueryFirstEnumText_PileFood__UAE_AW4HELP_TEXT__XZ(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x78) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(in_ECX + 0x78) + 0x300))(0);
    if (iVar1 != 0) {
      uVar2 = _GetQueryFirstEnumText_Object__UAE_AW4HELP_TEXT__XZ();
      return uVar2;
    }
  }
  return 0xb38;
}



// ?GetQueryLastEnumText@PileFood@@UAE?AW4HELP_TEXT@@XZ @ 0x00617f60

undefined4 _GetQueryLastEnumText_PileFood__UAE_AW4HELP_TEXT__XZ(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x78) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(in_ECX + 0x78) + 0x300))(0);
    if (iVar1 != 0) {
      uVar2 = _GetQueryLastEnumText_Object__UAE_AW4HELP_TEXT__XZ();
      return uVar2;
    }
  }
  return 0xb38;
}



// ?Get2DRadius@PileFood@@UAEMXZ @ 0x00618d30

float10 _Get2DRadius_PileFood__UAEMXZ(void)

{
  int *in_ECX;
  float10 fVar1;
  float10 fVar2;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 0x86c))();
  fVar2 = (float10)_Get2DRadius_Object__UAEMXZ();
  return fVar2 * (float10)(float)fVar1;
}



