// Decompiled functions for class: SpellTeleport
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetDebugText@SpellTeleport@@UAEPADXZ @ 0x0052ebc0

char * _GetDebugText_SpellTeleport__UAEPADXZ(void)

{
  return s_SpellTeleport__00b1a3f8;
}



// ?InitWithPos@SpellTeleport@@UAEHPAVGameThing@@ABUMapCoords@@PAVSpellCastData@@ABUPSysProcessInfo@@@Z @ 0x005b95f0

void _InitWithPos_SpellTeleport__UAEHPAVGameThing__ABUMapCoords__PAVSpellCastData__ABUPSysProcessInfo___Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  int in_ECX;
  
  iVar2 = FUN_005b9890(param_2);
  if (iVar2 != 0) {
    puVar3 = operator_new(8);
    if (puVar3 != (undefined4 *)0x0) {
      uVar1 = *(undefined4 *)(in_ECX + 0xec);
      puVar3[1] = iVar2;
      *puVar3 = uVar1;
      *(undefined4 **)(in_ECX + 0xec) = puVar3;
      *(int *)(in_ECX + 0xf0) = *(int *)(in_ECX + 0xf0) + 1;
    }
  }
  _InitWithPos_Spell__UAEHPAVGameThing__ABUMapCoords__PAVSpellCastData__ABUPSysProcessInfo___Z
            (param_1,param_2,param_3,param_4);
  return;
}



