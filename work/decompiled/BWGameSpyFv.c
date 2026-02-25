// Decompiled functions for class: BWGameSpyFv
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// _Connect__9BWGameSpyFv @ 0x00436420

void _Connect__9BWGameSpyFv(undefined4 param_1,char param_2,int param_3)

{
  undefined1 auStack_200 [512];
  
  if (param_2 == '\0') {
    FUN_007d0590(DAT_00c415f4,DAT_00b7b298,param_1,0);
  }
  else if (param_3 != 0) {
    FUN_00733e17(auStack_200,s_BNW__u_008fc1c8,*(undefined4 *)(param_3 + 0x120));
    FUN_007d06e0(DAT_00c415f4,auStack_200,param_1,0);
    return;
  }
  return;
}



