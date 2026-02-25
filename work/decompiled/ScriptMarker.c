// Decompiled functions for class: ScriptMarker
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetText@ScriptMarker@@UAEPBDXZ @ 0x00531360

char * _GetText_ScriptMarker__UAEPBDXZ(void)

{
  return s_Script_Marker_00b1b280;
}



// ?GetSaveType@ScriptMarker@@UAEIXZ @ 0x00531370

undefined4 _GetSaveType_ScriptMarker__UAEIXZ(void)

{
  return 0x7c;
}



// ?GetDebugText@ScriptMarker@@UAEPADXZ @ 0x00531380

char * _GetDebugText_ScriptMarker__UAEPADXZ(void)

{
  return s_ScriptMarker__00b1b290;
}



// ?ToBeDeleted@ScriptMarker@@UAEXH@Z @ 0x006a6ff0

void _ToBeDeleted_ScriptMarker__UAEXH_Z(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int in_ECX;
  
  iVar4 = DAT_00c22ca4;
  piVar1 = (int *)(DAT_00c22ca4 + 0x201d48);
  piVar2 = (int *)*piVar1;
  piVar5 = (int *)0x0;
  while (piVar3 = piVar5, piVar5 = piVar2, piVar5 != (int *)0x0) {
    piVar2 = (int *)*piVar5;
    if (piVar5[1] == in_ECX) {
      if (piVar5 == (int *)*piVar1) {
        *piVar1 = (int)piVar2;
      }
      else {
        *piVar3 = (int)piVar2;
      }
      *(int *)(iVar4 + 0x201d4c) = *(int *)(iVar4 + 0x201d4c) + -1;
      FUN_007290de(piVar5);
      piVar5 = piVar3;
    }
  }
  _ToBeDeleted_GameThingWithPos__UAEXH_Z(param_1);
  return;
}



