// Decompiled functions for class: SpellIcon
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?SetPlayer@SpellIcon@@UAEXPAVGPlayer@@@Z @ 0x006bd140

void _SetPlayer_SpellIcon__UAEXPAVGPlayer___Z(undefined4 param_1)

{
  int in_ECX;
  
  _SetPlayer_GameThing__QAEXPAVGPlayer___Z(param_1);
  if (*(int **)(in_ECX + 0x7c) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x7c) + 0x20))(param_1);
  }
  return;
}



