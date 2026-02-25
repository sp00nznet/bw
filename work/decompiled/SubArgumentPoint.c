// Decompiled functions for class: SubArgumentPoint
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?SetArgumentOfSubActionAgenda@SubArgumentPoint@@UAEXPAVCreatureSubActionAgenda@@I@Z @ 0x004deaf0

void _SetArgumentOfSubActionAgenda_SubArgumentPoint__UAEXPAVCreatureSubActionAgenda__I_Z
               (int param_1,int param_2)

{
  undefined4 *puVar1;
  int in_ECX;
  
  puVar1 = (undefined4 *)(param_2 * 0x60 + 0x3c + param_1);
  *puVar1 = *(undefined4 *)(in_ECX + 4);
  puVar1[1] = *(undefined4 *)(in_ECX + 8);
  puVar1[2] = *(undefined4 *)(in_ECX + 0xc);
  return;
}



// ?GetObject@SubArgumentPoint@@UAEPAVObject@@XZ @ 0x004deb20

void _GetObject_SubArgumentPoint__UAEPAVObject__XZ(int param_1,int param_2)

{
  int in_ECX;
  
  param_1 = param_2 * 0x60 + param_1;
  *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(in_ECX + 4);
  *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(in_ECX + 8);
  *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(in_ECX + 0xc);
  *(undefined4 *)(param_1 + 0x38) = *(undefined4 *)(in_ECX + 0x10);
  *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(in_ECX + 0x14);
  *(undefined4 *)(param_1 + 0x4c) = *(undefined4 *)(in_ECX + 0x18);
  return;
}



// ?GetObject@SubArgumentPoint@@UAEPAVObject@@XZ @ 0x004deb90

void _GetObject_SubArgumentPoint__UAEPAVObject__XZ(int param_1,int param_2)

{
  int in_ECX;
  
  param_1 = param_2 * 0x60 + param_1;
  *(undefined4 *)(param_1 + 0x3c) = *(undefined4 *)(in_ECX + 4);
  *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(in_ECX + 8);
  *(undefined4 *)(param_1 + 0x44) = *(undefined4 *)(in_ECX + 0xc);
  *(undefined4 *)(param_1 + 0x48) = *(undefined4 *)(in_ECX + 0x10);
  return;
}



