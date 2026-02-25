// Decompiled functions for class: LeashObj
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?InterfaceValidToTap@LeashObj@@UAEIPAVGInterfaceStatus@@@Z @ 0x0044f9c0

bool _InterfaceValidToTap_LeashObj__UAEIPAVGInterfaceStatus___Z(void)

{
  int in_ECX;
  
  return (uint)*(byte *)(DAT_00c22ca4 + 0xcd + (uint)*(byte *)(DAT_00c22ca4 + 0x201b15) * 0x278) ==
         *(uint *)(in_ECX + 0x6c);
}



// ?InterfaceTap@LeashObj@@UAEIPAVGInterfaceStatus@@@Z @ 0x0044f9f0

undefined4 _InterfaceTap_LeashObj__UAEIPAVGInterfaceStatus___Z(int param_1)

{
  char cVar1;
  int iVar2;
  int in_ECX;
  LH_SamplePlayOptions aLStack_168 [4];
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_148;
  undefined4 uStack_144;
  
  if ((uint)*(byte *)(DAT_00c22ca4 + 0xcd + (uint)*(byte *)(DAT_00c22ca4 + 0x201b15) * 0x278) ==
      *(uint *)(in_ECX + 0x6c)) {
    if (**(int **)(in_ECX + 0x58) == *(int *)(in_ECX + 0x54)) {
      **(int **)(in_ECX + 0x58) = -1;
      return 1;
    }
    iVar2 = FUN_00527d60();
    if (param_1 == iVar2) {
      LH_SamplePlayOptions::LH_SamplePlayOptions(aLStack_168);
      uStack_164 = *(undefined4 *)(DAT_00bf4e68 + 0x3ac);
      uStack_144 = 0x2a;
      uStack_148 = 0;
      uStack_160 = 0;
      FUN_00423db0(aLStack_168);
      LH_SamplePlayOptions::~LH_SamplePlayOptions(aLStack_168);
    }
    **(undefined4 **)(in_ECX + 0x58) = *(undefined4 *)(in_ECX + 0x54);
    if (*(int *)(in_ECX + 0x54) == 0) {
      cVar1 = '\x01';
    }
    else {
      cVar1 = (*(int *)(in_ECX + 0x54) != 1) + '\x02';
    }
    FUN_005237a0(0x65,cVar1,0);
  }
  return 1;
}



// ?GetOverwriteInteractableToolTip@LeashObj@@UAEIXZ @ 0x0044fae0

undefined4 _GetOverwriteInteractableToolTip_LeashObj__UAEIXZ(void)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x54) == 0) {
    return 0xec8;
  }
  if (*(int *)(in_ECX + 0x54) != 1) {
    return 0xec9;
  }
  return 0xeca;
}



// ?GetText@LeashObj@@UAEPBDXZ @ 0x0044fda0

char * _GetText_LeashObj__UAEPBDXZ(void)

{
  return s_Leash_Obj_008fd098;
}



// ?GetQueryFirstEnumText@LeashObj@@UAE?AW4HELP_TEXT@@XZ @ 0x0044fdb0

void _GetQueryFirstEnumText_LeashObj__UAE_AW4HELP_TEXT__XZ(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x0044fdb2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0x194))();
  return;
}



