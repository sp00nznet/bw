// Decompiled functions for class: GSoundMap
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Dump@GSoundMap@@UAEXXZ @ 0x006b4d80

void _Dump_GSoundMap__UAEXXZ(void)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  int in_ECX;
  undefined2 uStack_c;
  undefined2 uStack_a;
  undefined2 uStack_8;
  undefined2 uStack_6;
  undefined2 uStack_4;
  undefined2 uStack_2;
  
  uVar1 = *(undefined2 *)(in_ECX + 0xfa);
  uVar2 = *(undefined2 *)(in_ECX + 0xfe);
  iVar3 = FUN_006b4cd0(in_ECX + 0xf8,*(undefined2 *)(in_ECX + 0xb0));
  FUN_004ef260(&DAT_00bf4e6c,1,s_Sound_Map_Calc_Update_X__d_Z__d___00b454f8,uVar1,uVar2,
               (&PTR_s_SOUND_SURFACE_TYPE_NONE_00b45334)[iVar3]);
  if (DAT_00c22ca4 != 0) {
    iVar3 = FUN_00527d30();
    if (iVar3 != 0) {
      iVar3 = FUN_00527d30();
      uStack_c = (undefined2)*(undefined4 *)(iVar3 + 0x3b8);
      uStack_a = (undefined2)((uint)*(undefined4 *)(iVar3 + 0x3b8) >> 0x10);
      uVar1 = uStack_a;
      uStack_8 = (undefined2)*(undefined4 *)(iVar3 + 0x3bc);
      uStack_6 = (undefined2)((uint)*(undefined4 *)(iVar3 + 0x3bc) >> 0x10);
      uVar2 = uStack_6;
      uStack_4 = (undefined2)*(undefined4 *)(iVar3 + 0x3c0);
      uStack_2 = (undefined2)((uint)*(undefined4 *)(iVar3 + 0x3c0) >> 0x10);
      iVar3 = FUN_006b4cd0(&uStack_c,*(undefined2 *)(in_ECX + 0xb0));
      FUN_004ef260(&DAT_00bf4e6c,1,s_Sound_Map_At_Hand_X__d_Z__d__s_C_00b454d0,uVar1,uVar2,
                   (&PTR_s_SOUND_SURFACE_TYPE_NONE_00b45334)[iVar3]);
    }
  }
  FUN_004ef260(&DAT_00bf4e6c,1,s_Sound_Radius__3_3f_Distance__3_3_00b45494,
               (double)*(float *)(in_ECX + 0x104),(double)*(float *)(in_ECX + 0x10c),
               (double)*(float *)(in_ECX + 0x108));
  return;
}



