// Decompiled functions for class: DialogBoxBaseFUlUlPFiP8SetupBoxP12SetupControlii_v
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// _Init__13DialogBoxBaseFUlUlPFiP8SetupBoxP12SetupControlii_v @ 0x004eff40

void _Init__13DialogBoxBaseFUlUlPFiP8SetupBoxP12SetupControlii_v
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int in_ECX;
  
  puVar1 = (undefined4 *)FUN_00746d70(0xcc,s_C__dev_black_DialogBoxMain_cpp_00b167b0,0x26);
  if (puVar1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    *puVar1 = &PTR__UpdateSpellInfo_GameThing__QAEXPAVSpell__PAVPSysProcessInfo___Z_00816ee0;
    puVar1[0x30] = 0xffffffff;
    puVar1[0x26] = 0;
    puVar1[0x31] = 0x3f800000;
    puVar1[0x27] = param_1;
    puVar1[0x28] = param_2;
    puVar1[0x29] = 600;
    puVar1[0x2a] = 200;
    *(undefined1 *)(puVar1 + 0x19) = 0;
    *(undefined1 *)((int)puVar1 + 0x65) = 0;
    puVar1[0x1d] = 0;
    puVar1[0x1b] = 0;
    puVar1[0x1c] = 0;
    puVar1[0x1a] = 0;
    puVar1[0x2c] = 0;
    uVar2 = FUN_00405ef0();
    puVar1[0x2b] = uVar2;
    DAT_00b6e5dc = puVar1;
    puVar1[2] = 0;
    puVar1[1] = 0;
    puVar1[8] = 0;
    puVar1[7] = 0;
    puVar1[6] = 0;
    puVar1[0xc] = 0;
    puVar1[0xb] = 0;
    puVar1[5] = 0;
    puVar1[10] = 0;
    puVar1[4] = 0;
    puVar1[9] = 0;
    puVar1[3] = 0;
    puVar1[0xe] = 0;
    puVar1[0xd] = 0;
    puVar1[0x14] = 0;
    puVar1[0x13] = 0;
    puVar1[0x12] = 0;
    puVar1[0x18] = 0;
    puVar1[0x17] = 0;
    puVar1[0x11] = 0;
    puVar1[0x16] = 0;
    puVar1[0x10] = 0;
    puVar1[0x15] = 0;
    puVar1[0xf] = 0;
    FUN_00406240(0,0,0x3f000000);
    FUN_00406240(puVar1[0x31],0,0x3f000000);
    puVar1[0x22] = 0;
    puVar1[0x23] = 0;
    *(undefined1 *)(puVar1 + 0x1e) = 1;
    puVar1[0x1f] = 400;
    puVar1[0x20] = 300;
    puVar1[0x21] = 0x3f800000;
    puVar1[0x24] = 0;
    puVar1[0x25] = 1;
    puVar1[0x32] = 0;
    puVar1[0x2f] = 0;
  }
  *(undefined4 **)(in_ECX + 4) = puVar1;
  DAT_00b6e5dc = puVar1;
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0xb0) = param_3;
  return;
}



