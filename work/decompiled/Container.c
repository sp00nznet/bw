// Decompiled functions for class: Container
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetPlayer@Container@@UAEPAVGPlayer@@XZ @ 0x0044e390

undefined4 _GetPlayer_Container__UAEPAVGPlayer__XZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x2c);
}



// ?Save@Container@@UAEIAAVGameOSFile@@@Z @ 0x004568d0

undefined4 _Save_Container__UAEIAAVGameOSFile___Z(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_GameThingWithPos__UAEXPAUGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    FUN_00533b90(*(undefined4 *)(in_ECX + 0x28));
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x2c));
    return 1;
  }
  return 0;
}



// ?Load@Container@@UAEIAAVGameOSFile@@@Z @ 0x00456910

undefined4 _Load_Container__UAEIAAVGameOSFile___Z(undefined4 param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Load_GameThingWithPos__QAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    FUN_00533bf0(in_ECX + 0x28);
    FUN_00531f30(in_ECX + 0x2c);
    return 1;
  }
  return 0;
}



