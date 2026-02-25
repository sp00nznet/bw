// Decompiled functions for class: SpellHeal
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetDebugText@SpellHeal@@UAEPADXZ @ 0x0052e6c0

char * _GetDebugText_SpellHeal__UAEPADXZ(void)

{
  return s_SpellHeal__00b1a348;
}



// ?InitWithPos@SpellHeal@@UAEHPAVGameThing@@ABUMapCoords@@PAVSpellCastData@@ABUPSysProcessInfo@@@Z @ 0x006c3f90

int _InitWithPos_SpellHeal__UAEHPAVGameThing__ABUMapCoords__PAVSpellCastData__ABUPSysProcessInfo___Z
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 extraout_var;
  
  iVar1 = _InitWithPos_Spell__UAEHPAVGameThing__ABUMapCoords__PAVSpellCastData__ABUPSysProcessInfo___Z
                    (param_1,param_2,param_3,param_4);
  if (iVar1 == 1) {
    thunk_FUN_006c4230(param_2);
    FUN_005b9270(param_2,extraout_var);
  }
  return iVar1;
}



