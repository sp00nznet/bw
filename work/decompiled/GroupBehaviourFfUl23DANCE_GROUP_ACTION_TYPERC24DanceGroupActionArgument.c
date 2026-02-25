// Decompiled functions for class: GroupBehaviourFfUl23DANCE_GROUP_ACTION_TYPERC24DanceGroupActionArgument
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// _AddAction__14GroupBehaviourFfUl23DANCE_GROUP_ACTION_TYPERC24DanceGroupActionArgument @ 0x0055e1e0

void _AddAction__14GroupBehaviourFfUl23DANCE_GROUP_ACTION_TYPERC24DanceGroupActionArgument
               (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 **ppuVar1;
  undefined4 *puVar2;
  int *in_ECX;
  undefined4 **ppuVar3;
  undefined4 *puStack_8;
  int iStack_4;
  
  puStack_8 = (undefined4 *)0x0;
  iStack_4 = 0;
  puVar2 = operator_new(8);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    *puVar2 = param_2;
    puVar2[1] = puStack_8;
  }
  iStack_4 = iStack_4 + 1;
  ppuVar3 = &puStack_8;
  puStack_8 = puVar2;
  (**(code **)(*in_ECX + 0x508))(param_1,ppuVar3,param_3,param_4);
  while (ppuVar3 != (undefined4 **)0x0) {
    ppuVar1 = (undefined4 **)ppuVar3[1];
    FUN_007290de(ppuVar3);
    ppuVar3 = ppuVar1;
  }
  return;
}



