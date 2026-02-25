// Decompiled functions for class: Mobile
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?ApplyThisToMapCoord@Mobile@@UAEIPAVGInterfaceStatus@@ABUMapCoords@@PAUGestureSystemPacketData@@@Z @ 0x005c2140

undefined4
_ApplyThisToMapCoord_Mobile__UAEIPAVGInterfaceStatus__ABUMapCoords__PAUGestureSystemPacketData___Z
          (undefined4 param_1)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x758))(param_1,0);
  return 0x16;
}



// ?Save@Mobile@@UAEIAAVGameOSFile@@@Z @ 0x005c2160

undefined4 _Save_Mobile__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_Object__UAEIPAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x54),2,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x54) + 2;
    }
    return 1;
  }
  return 0;
}



// ?Load@Mobile@@UAEIAAVGameOSFile@@@Z @ 0x005c21c0

undefined4 _Load_Mobile__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Load__6ObjectFR10GameOSFile(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x54),2,0,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x54) + 2;
    }
    return 1;
  }
  return 0;
}



