// Decompiled functions for class: DialogBoxBaseFv
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// _WantsKeyControl__13DialogBoxBaseFv @ 0x004ef3b0

bool _WantsKeyControl__13DialogBoxBaseFv(void)

{
  int iVar1;
  
  iVar1 = FUN_004f02b0();
  return iVar1 != 0;
}



// _CanESCOut__13DialogBoxBaseFv @ 0x004ef3c0

undefined4 _CanESCOut__13DialogBoxBaseFv(void)

{
  int in_ECX;
  
  return CONCAT31((int3)((uint)*(int *)(in_ECX + 4) >> 8),
                  *(char *)(*(int *)(in_ECX + 4) + 100) == '\0');
}



// _Destroy__13DialogBoxBaseFv @ 0x004f00d0

void _Destroy__13DialogBoxBaseFv(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int in_ECX;
  
  puVar1 = *(undefined4 **)(in_ECX + 4);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = &PTR__UpdateSpellInfo_GameThing__QAEXPAVSpell__PAVPSysProcessInfo___Z_00816ee0;
    DAT_00b6e5dc = 0;
    FUN_00406720();
    piVar2 = (int *)puVar1[0x1b];
    while (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x30))(1);
      piVar2 = (int *)puVar1[0x1b];
    }
    iVar3 = puVar1[0x1a];
    puVar1[0x1b] = iVar3;
    while (iVar3 != 0) {
      if ((int *)puVar1[0x1b] != (int *)0x0) {
        (**(code **)(*(int *)puVar1[0x1b] + 0x30))(1);
      }
      iVar3 = puVar1[0x1b];
    }
    FUN_007290de(puVar1);
  }
  return;
}



// _Show__13DialogBoxBaseFv @ 0x004f0130

void _Show__13DialogBoxBaseFv(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_ECX;
  
  if (DAT_00be7600 < 0xf) {
    iVar1 = FUN_004063b0();
    if (iVar1 != *(int *)(in_ECX + 4)) {
      uVar2 = FUN_004063b0();
      (&DAT_00be75b8)[DAT_00be7600] = uVar2;
      DAT_00be7600 = DAT_00be7600 + 1;
      FUN_00405f00(*(undefined4 *)(in_ECX + 4));
      (&DAT_00be75b8)[DAT_00be7600] = *(undefined4 *)(in_ECX + 4);
    }
  }
  return;
}



