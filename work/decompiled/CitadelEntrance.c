// Decompiled functions for class: CitadelEntrance
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetSaveType@CitadelEntrance@@UAEIXZ @ 0x00454080

undefined4 _GetSaveType_CitadelEntrance__UAEIXZ(void)

{
  return 0x110;
}



// ?GetDebugText@CitadelEntrance@@UAEPADXZ @ 0x00454090

char * _GetDebugText_CitadelEntrance__UAEPADXZ(void)

{
  return s_CitadelEntrance__008fd1c8;
}



// ?InterfaceTap@CitadelEntrance@@UAEIPAVGInterfaceStatus@@@Z @ 0x00454110

undefined4 _InterfaceTap_CitadelEntrance__UAEIPAVGInterfaceStatus___Z(int param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x54) != (int *)0x0) {
    bVar1 = *(byte *)(DAT_00c22ca4 + 0x201b15);
    iVar3 = DAT_00c22ca4 + 0x18;
    iVar2 = (**(code **)(**(int **)(in_ECX + 0x54) + 0x1c))();
    if (iVar2 == iVar3 + (uint)bVar1 * 0x278) {
      iVar3 = FUN_00527d60();
      if (param_1 == iVar3) {
        FUN_005263f0(0,0);
      }
    }
  }
  return 1;
}



// ?InterfaceValidToTap@CitadelEntrance@@UAEIPAVGInterfaceStatus@@@Z @ 0x00454170

bool _InterfaceValidToTap_CitadelEntrance__UAEIPAVGInterfaceStatus___Z(void)

{
  int iVar1;
  
  iVar1 = FUN_005256a0();
  if (iVar1 == 0) {
    return *(int *)(*(int *)(DAT_00c22ca4 + 0x24c13c) + 0xa0) != 0;
  }
  return true;
}



// ?GetQueryFirstEnumText@CitadelEntrance@@UAE?AW4HELP_TEXT@@XZ @ 0x004541b0

undefined4 _GetQueryFirstEnumText_CitadelEntrance__UAE_AW4HELP_TEXT__XZ(void)

{
  return 2000;
}



// ?GetQueryLastEnumText@CitadelEntrance@@UAE?AW4HELP_TEXT@@XZ @ 0x004541c0

void _GetQueryLastEnumText_CitadelEntrance__UAE_AW4HELP_TEXT__XZ(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x004541c2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0x4d8))();
  return;
}



// ?ResolveLoad@CitadelEntrance@@UAEXXZ @ 0x004545a0

void _ResolveLoad_CitadelEntrance__UAEXXZ(void)

{
  int in_ECX;
  
  *(undefined **)(in_ECX + 0x28) = &DAT_00c62d18;
  return;
}



