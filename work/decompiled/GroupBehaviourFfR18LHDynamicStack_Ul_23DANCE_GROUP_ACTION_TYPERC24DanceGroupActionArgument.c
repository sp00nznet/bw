// Decompiled functions for class: GroupBehaviourFfR18LHDynamicStack_Ul_23DANCE_GROUP_ACTION_TYPERC24DanceGroupActionArgument
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// _AddAction__14GroupBehaviourFfR18LHDynamicStack_Ul_23DANCE_GROUP_ACTION_TYPERC24DanceGroupActionArgument @ 0x0055e270

int _AddAction__14GroupBehaviourFfR18LHDynamicStack_Ul_23DANCE_GROUP_ACTION_TYPERC24DanceGroupActionArgument
              (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int in_ECX;
  int *piVar5;
  int *piVar6;
  
  for (piVar4 = *(int **)(in_ECX + 0x38); piVar4 != (int *)0x0; piVar4 = (int *)piVar4[1]) {
    iVar2 = FUN_004ec770(param_1);
    if (iVar2 != 0) {
      iVar2 = *piVar4;
      if (iVar2 != 0) {
        FUN_004ec990(param_2,param_3,param_4);
        return iVar2;
      }
      break;
    }
  }
  iVar2 = FUN_004300a0(0x24,s_C__dev_black_GroupBehaviour_cpp_00b1cf3c,0x20f);
  if (iVar2 == 0) {
    iVar2 = 0;
  }
  else {
    uVar3 = __ftol(param_2,param_3,param_4);
    iVar2 = FUN_004ec680(uVar3,param_2,param_3,param_4);
  }
  piVar4 = operator_new(8);
  if (piVar4 == (int *)0x0) {
    piVar4 = (int *)0x0;
  }
  else {
    *piVar4 = iVar2;
    piVar4[1] = 0;
  }
  piVar1 = *(int **)(in_ECX + 0x38);
  piVar6 = (int *)0x0;
  if (*(int **)(in_ECX + 0x38) != (int *)0x0) {
    do {
      piVar5 = piVar1;
      if (*(float *)(iVar2 + 0x14) <= *(float *)(*piVar5 + 0x14)) {
        piVar4[1] = (int)piVar5;
        if (piVar6 == (int *)0x0) {
          *(int **)(in_ECX + 0x38) = piVar4;
        }
        else {
          piVar6[1] = (int)piVar4;
        }
        if (piVar5 != (int *)0x0) goto LAB_0055e35f;
        break;
      }
      piVar1 = (int *)piVar5[1];
      piVar6 = piVar5;
    } while ((int *)piVar5[1] != (int *)0x0);
    if (piVar6 != (int *)0x0) {
      piVar6[1] = (int)piVar4;
LAB_0055e35f:
      *(int *)(in_ECX + 0x3c) = *(int *)(in_ECX + 0x3c) + 1;
      return iVar2;
    }
  }
  *(int *)(in_ECX + 0x3c) = *(int *)(in_ECX + 0x3c) + 1;
  *(int **)(in_ECX + 0x38) = piVar4;
  return iVar2;
}



