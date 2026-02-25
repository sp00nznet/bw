// Decompiled functions for class: GObjectInfo
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetAlignmentType@GObjectInfo@@UBE?AW4ALIGNMENT_TYPE@@XZ @ 0x00401170

undefined4 _GetAlignmentType_GObjectInfo__UBE_AW4ALIGNMENT_TYPE__XZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x14);
}



// ?GetFoodType@GObjectInfo@@UBE?AW4FOOD_TYPE@@XZ @ 0x00401180

undefined4 _GetFoodType_GObjectInfo__UBE_AW4FOOD_TYPE__XZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x70);
}



// ?GetDebugText@GObjectInfo@@UBEPBDXZ @ 0x00401190

int _GetDebugText_GObjectInfo__UBEPBDXZ(void)

{
  int in_ECX;
  
  return in_ECX + 0x18;
}



// ?GetBaseInfo@GObjectInfo@@UAEPAVGBaseInfo@@AAI@Z @ 0x00425170

undefined4 * _GetBaseInfo_GObjectInfo__UAEPAVGBaseInfo__AAI_Z(undefined4 *param_1)

{
  *param_1 = 0x2d;
  return &DAT_00c62418;
}



