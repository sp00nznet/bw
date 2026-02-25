// Decompiled functions for class: GroupBehaviourFP10DanceGroup23DANCE_GROUP_ACTION_TYPERC24DanceGroupActionArgumentUl
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// _UpdateGroupBasedOnAction__14GroupBehaviourFP10DanceGroup23DANCE_GROUP_ACTION_TYPERC24DanceGroupActionArgumentUl @ 0x0055d6b0

int * _UpdateGroupBasedOnAction__14GroupBehaviourFP10DanceGroup23DANCE_GROUP_ACTION_TYPERC24DanceGroupActionArgumentUl
                (int *param_1,int *param_2,int *param_3,int param_4)

{
  uint uVar1;
  ulonglong uVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  int iVar12;
  undefined4 uVar13;
  int in_ECX;
  int iVar14;
  
  switch(param_2) {
  case (int *)0x0:
    param_1[0x11] = *param_3;
    return param_3;
  case (int *)0x1:
    param_1[0x12] = *param_3;
    piVar11 = (int *)param_3[1];
    param_1[0x13] = (int)piVar11;
    return piVar11;
  case (int *)0x2:
    param_1[0x14] = *param_3;
    return param_1;
  case (int *)0x3:
    uVar13 = __ftol();
    piVar11 = (int *)FUN_0055df80(param_1,param_3 + 4,uVar13);
    return piVar11;
  case (int *)0x4:
    iVar12 = FUN_0055f660(*param_3);
    param_2 = (int *)0x0;
    if (iVar12 != 0) {
      param_2 = *(int **)(iVar12 + 4);
    }
    if ((int *)param_1[0x1c] != param_2) {
      iVar14 = FUN_0055f660(*param_3);
      iVar12 = 0;
      if (iVar14 != 0) {
        iVar12 = *(int *)(iVar14 + 4);
      }
      param_1[0x1c] = iVar12;
      iVar14 = FUN_0055f660(*param_3);
      iVar12 = 0;
      if (iVar14 != 0) {
        iVar12 = *(int *)(iVar14 + 4);
      }
      *(char *)(param_1 + 0x1d) = (char)*(undefined4 *)(iVar12 + 0x174);
      iVar12 = FUN_0055f660(*param_3);
      piVar11 = (int *)0x0;
      if (iVar12 != 0) {
        piVar11 = *(int **)(iVar12 + 4);
      }
      piVar11[piVar11[0x5d] + 0x3d] = param_1[9];
      piVar11[0x5d] = piVar11[0x5d] + 1;
      return piVar11;
    }
    break;
  case (int *)0x5:
    iVar12 = param_1[0x1c];
    param_2 = (int *)0x0;
    if (iVar12 != 0) {
      uVar1 = *(uint *)(iVar12 + 0x174);
      uVar4 = 0;
      if (uVar1 != 0) {
        piVar11 = (int *)(iVar12 + 0xf4);
        while (*piVar11 != param_1[9]) {
          uVar4 = uVar4 + 1;
          piVar11 = piVar11 + 1;
          if (uVar1 <= uVar4) {
            piVar11 = (int *)FUN_004eb6c0();
            param_1[0x1c] = 0;
            return piVar11;
          }
        }
        if (uVar4 < uVar1 - 1) {
          piVar11 = (int *)(iVar12 + 0xf4) + uVar4;
          do {
            *piVar11 = piVar11[1];
            uVar4 = uVar4 + 1;
            piVar11 = piVar11 + 1;
          } while (uVar4 < *(int *)(iVar12 + 0x174) - 1U);
        }
        *(int *)(iVar12 + 0x174) = *(int *)(iVar12 + 0x174) + -1;
      }
      piVar11 = (int *)FUN_004eb6c0();
      param_1[0x1c] = 0;
      return piVar11;
    }
    break;
  case (int *)0x6:
    param_2 = (int *)param_1[0x10];
    if (param_2 == (int *)0x0) {
      iVar12 = *param_3;
      param_1[0x3a] = iVar12;
      if (iVar12 == 0) {
        param_1[0x3b] = param_3[1];
        piVar11 = *(int **)(in_ECX + 0x80);
        if (piVar11 != (int *)0x0) {
LAB_0055d9a0:
          if ((int *)piVar11[1] != param_1) goto code_r0x0055d9a5;
          puVar5 = *(undefined4 **)(in_ECX + 0x80);
          puVar6 = (undefined4 *)0x0;
          while (puVar3 = puVar6, puVar6 = puVar5, puVar6 != (undefined4 *)0x0) {
            puVar5 = (undefined4 *)*puVar6;
            if ((int *)puVar6[1] == param_1) {
              if (puVar6 == *(undefined4 **)(in_ECX + 0x80)) {
                *(undefined4 **)(in_ECX + 0x80) = puVar5;
              }
              else {
                *puVar3 = puVar5;
              }
              *(int *)(in_ECX + 0x84) = *(int *)(in_ECX + 0x84) + -1;
              FUN_007290de(puVar6);
              puVar6 = puVar3;
            }
          }
        }
LAB_0055d9f3:
        for (puVar5 = *(undefined4 **)(in_ECX + 0x88); puVar5 != (undefined4 *)0x0;
            puVar5 = (undefined4 *)*puVar5) {
          if ((int *)puVar5[1] == param_1) goto LAB_0055da5a;
        }
        if ((param_1 != (int *)0x0) && (puVar5 = operator_new(8), puVar5 != (undefined4 *)0x0)) {
          puVar5[1] = param_1;
          *puVar5 = 0;
          puVar6 = (undefined4 *)FUN_004ecf10();
          if (puVar6 != (undefined4 *)0x0) {
            *puVar6 = puVar5;
            *(int *)(in_ECX + 0x8c) = *(int *)(in_ECX + 0x8c) + 1;
            piVar11 = (int *)FUN_0055e140();
            return piVar11;
          }
          *(undefined4 **)(in_ECX + 0x88) = puVar5;
          *(int *)(in_ECX + 0x8c) = *(int *)(in_ECX + 0x8c) + 1;
        }
LAB_0055da5a:
        piVar11 = (int *)FUN_0055e140();
        return piVar11;
      }
      param_1[0x3b] = param_3[1];
      piVar11 = *(int **)(in_ECX + 0x88);
      if (piVar11 != (int *)0x0) {
LAB_0055d8c9:
        if ((int *)piVar11[1] != param_1) goto code_r0x0055d8ce;
        puVar5 = *(undefined4 **)(in_ECX + 0x88);
        puVar6 = (undefined4 *)0x0;
        while (puVar3 = puVar6, puVar6 = puVar5, puVar6 != (undefined4 *)0x0) {
          puVar5 = (undefined4 *)*puVar6;
          if ((int *)puVar6[1] == param_1) {
            if (puVar6 == *(undefined4 **)(in_ECX + 0x88)) {
              *(undefined4 **)(in_ECX + 0x88) = puVar5;
            }
            else {
              *puVar3 = puVar5;
            }
            *(int *)(in_ECX + 0x8c) = *(int *)(in_ECX + 0x8c) + -1;
            FUN_007290de(puVar6);
            puVar6 = puVar3;
          }
        }
      }
LAB_0055d91c:
      for (piVar11 = *(int **)(in_ECX + 0x80); piVar11 != (int *)0x0; piVar11 = (int *)*piVar11) {
        if ((int *)piVar11[1] == param_1) {
          return piVar11;
        }
      }
      param_2 = (int *)0x0;
      if (param_1 != (int *)0x0) {
        puVar5 = operator_new(8);
        param_2 = (int *)0x0;
        if (puVar5 != (undefined4 *)0x0) {
          puVar5[1] = param_1;
          *puVar5 = 0;
          piVar11 = (int *)FUN_004ecf10();
          if (piVar11 != (int *)0x0) {
            *piVar11 = (int)puVar5;
            *(int *)(in_ECX + 0x84) = *(int *)(in_ECX + 0x84) + 1;
            return piVar11;
          }
          piVar11 = (int *)(*(int *)(in_ECX + 0x84) + 1);
          *(undefined4 **)(in_ECX + 0x80) = puVar5;
          *(int **)(in_ECX + 0x84) = piVar11;
          return piVar11;
        }
      }
    }
    break;
  case (int *)0x7:
    iVar12 = param_1[9];
    iVar14 = *param_3;
    iVar7 = FUN_0055f660(iVar12);
    iVar8 = 0;
    if (iVar7 != 0) {
      iVar8 = *(int *)(iVar7 + 4);
    }
    uVar1 = *(int *)(iVar8 + 0x20) * param_3[1];
    param_2 = (int *)(uVar1 * 0x51eb851f);
    param_1 = (int *)(uVar1 / 100);
    if (param_1 != (int *)0x0) {
      do {
        iVar7 = FUN_0055f660(iVar12);
        iVar8 = 0;
        if (iVar7 != 0) {
          iVar8 = *(int *)(iVar7 + 4);
        }
        if (*(int *)(iVar8 + 0x1c) == 0) {
          iVar8 = 0;
        }
        else {
          iVar8 = *(int *)(*(int *)(iVar8 + 0x1c) + 4);
        }
        iVar7 = FUN_0055f660(iVar12);
        if (iVar7 == 0) {
          iVar7 = 0;
        }
        else {
          iVar7 = *(int *)(iVar7 + 4);
        }
        puVar5 = *(undefined4 **)(iVar7 + 0x1c);
        puVar6 = (undefined4 *)0x0;
        while (puVar3 = puVar6, puVar6 = puVar5, puVar6 != (undefined4 *)0x0) {
          puVar5 = (undefined4 *)*puVar6;
          if (puVar6[1] == iVar8) {
            if (puVar6 == *(undefined4 **)(iVar7 + 0x1c)) {
              *(undefined4 **)(iVar7 + 0x1c) = puVar5;
            }
            else {
              *puVar3 = puVar5;
            }
            *(int *)(iVar7 + 0x20) = *(int *)(iVar7 + 0x20) + -1;
            FUN_007290de(puVar6);
            puVar6 = puVar3;
          }
        }
        *(undefined4 *)(iVar8 + 0xd8) = 0;
        iVar8 = FUN_0055f660(iVar14);
        uVar13 = 0;
        if (iVar8 != 0) {
          uVar13 = *(undefined4 *)(iVar8 + 4);
        }
        piVar11 = (int *)FUN_005ae0b0(uVar13);
        param_1 = (int *)((int)param_1 - 1);
      } while (param_1 != (int *)0x0);
      return piVar11;
    }
    break;
  case (int *)0x9:
    piVar11 = (int *)param_1[7];
    param_2 = param_1;
    if (piVar11 != (int *)0x0) {
      do {
        piVar9 = (int *)(**(code **)(*(int *)piVar11[1] + 0x8e4))((char)*param_3);
        piVar11 = (int *)*piVar11;
      } while (piVar11 != (int *)0x0);
      return piVar9;
    }
    break;
  case (int *)0xa:
    piVar11 = (int *)param_1[7];
    if (piVar11 != (int *)0x0) {
      do {
        piVar9 = (int *)piVar11[1];
        piVar10 = (int *)FUN_0067bc90(100,s_C__dev_black_GroupBehaviour_cpp_00b1cf3c,0x104);
        if (piVar10 < (int *)param_3[1]) {
          piVar10 = (int *)(**(code **)(*piVar9 + 0x8e4))((char)*param_3);
        }
        piVar11 = (int *)*piVar11;
      } while (piVar11 != (int *)0x0);
      return piVar10;
    }
    break;
  case (int *)0xb:
    param_1[0x16] = *param_3;
    return param_3;
  case (int *)0xc:
    param_1[0xf] = 0;
    return param_1;
  case (int *)0xd:
    param_1[0xf] = 1;
    return param_2;
  case (int *)0xe:
    param_3 = (int *)*param_3;
    param_1[0x10] = (int)param_3;
    return param_3;
  case (int *)0xf:
    param_1[0x28] = *param_3;
    return param_1;
  case (int *)0x10:
    param_1[0x5e] = *param_3;
    return param_1;
  case (int *)0x11:
    iVar12 = *param_3;
    if (((*(int *)(in_ECX + 0x7c) != 0) &&
        (piVar11 = *(int **)(in_ECX + 0x78), piVar11 != (int *)0x0)) &&
       (iVar12 < *(int *)(in_ECX + 0x7c))) {
      if (0 < iVar12) {
        do {
          iVar12 = iVar12 + -1;
          piVar11 = (int *)*piVar11;
        } while (iVar12 != 0);
      }
      if (piVar11 != (int *)0x0) {
        iVar12 = piVar11[1];
        goto LAB_0055dc5a;
      }
    }
    iVar12 = 0;
LAB_0055dc5a:
    if (*(int *)(iVar12 + 0x20) != 0) {
      uVar2 = 0x800 / (ulonglong)(uint)(*(int *)(iVar12 + 0x20) * 2);
      param_1[0x16] = (int)(float)uVar2;
      return (int *)uVar2;
    }
    param_1[0x16] = 0;
    return param_1;
  case (int *)0x12:
    param_2 = *(int **)(in_ECX + 0xb4);
    if ((param_2 == (int *)0x0) && (param_2 = (int *)0x0, *(int *)(in_ECX + 0xb0) != 0)) {
      iVar12 = FUN_0051f3d0();
      param_2 = (int *)0x0;
      if (iVar12 != 0) {
        if (*(int *)(in_ECX + 0xb8) == 0) {
          uVar13 = FUN_0051f3d0();
          FUN_0043e960(uVar13);
          *(undefined4 *)(in_ECX + 0xb8) = 1;
        }
        piVar11 = (int *)FUN_00760fd0();
        return piVar11;
      }
    }
    break;
  case (int *)0x13:
    *(int *)(in_ECX + 0xc0) = *param_3;
    return param_2;
  case (int *)0x14:
    param_2 = *(int **)(in_ECX + 0x90);
    if (param_2 != (int *)0x0) {
      if (*param_3 != 0) {
        if (*(int *)(in_ECX + 0x4c + param_4 * 4) == 0) {
          iVar12 = FUN_00746d70(0x34,s_C__dev_black_GroupBehaviour_cpp_00b1cf3c,0x13b);
          if (iVar12 != 0) {
            piVar11 = (int *)FUN_004ecfd0(in_ECX);
            *(int **)(in_ECX + 0x4c + param_4 * 4) = piVar11;
            *piVar11 = *param_3;
            return piVar11;
          }
          *(undefined4 *)(in_ECX + 0x4c + param_4 * 4) = 0;
        }
        piVar11 = *(int **)(in_ECX + 0x4c + param_4 * 4);
        *piVar11 = *param_3;
        return piVar11;
      }
      iVar12 = *(int *)(in_ECX + 0x4c + param_4 * 4);
      if (iVar12 != 0) {
        FUN_004ed0a0();
        piVar11 = (int *)FUN_007290de(iVar12);
        *(undefined4 *)(in_ECX + 0x4c + param_4 * 4) = 0;
        return piVar11;
      }
    }
    break;
  case (int *)0x15:
    if (*(int *)(in_ECX + 0x90) == 0) {
      return (int *)0x0;
    }
    if (*(int *)(in_ECX + 0x4c + param_4 * 4) == 0) {
      iVar12 = FUN_00746d70(0x34,s_C__dev_black_GroupBehaviour_cpp_00b1cf3c,0x14e);
      if (iVar12 == 0) {
        uVar13 = 0;
      }
      else {
        uVar13 = FUN_004ecfd0(in_ECX);
      }
      *(undefined4 *)(in_ECX + 0x4c + param_4 * 4) = uVar13;
    }
    *(int *)(*(int *)(in_ECX + 0x4c + param_4 * 4) + 0x20) = *param_3;
    iVar12 = *(int *)(in_ECX + 0x4c + param_4 * 4);
    if (*(int *)(iVar12 + 0x24) != -1) {
      return param_3;
    }
    iVar14 = *param_3;
    if (((*(int *)(in_ECX + 0x7c) != 0) &&
        (piVar11 = *(int **)(in_ECX + 0x78), piVar11 != (int *)0x0)) &&
       (iVar14 < *(int *)(in_ECX + 0x7c))) {
      if (0 < iVar14) {
        do {
          iVar14 = iVar14 + -1;
          piVar11 = (int *)*piVar11;
        } while (iVar14 != 0);
      }
      if (piVar11 != (int *)0x0) {
        piVar11 = (int *)piVar11[1];
        goto LAB_0055de43;
      }
    }
    piVar11 = (int *)0x0;
LAB_0055de43:
    *(int *)(iVar12 + 0x24) = piVar11[0x29];
    piVar11[0x29] = piVar11[0x29] + 1;
    return piVar11;
  case (int *)0x16:
    param_2 = (int *)0x0;
    if (*(int *)(in_ECX + 0x90) != 0) {
      if (*(int *)(in_ECX + 0x4c + param_4 * 4) == 0) {
        iVar12 = FUN_00746d70(0x34,s_C__dev_black_GroupBehaviour_cpp_00b1cf3c,0x15c);
        if (iVar12 == 0) {
          uVar13 = 0;
        }
        else {
          uVar13 = FUN_004ecfd0(in_ECX);
        }
        *(undefined4 *)(in_ECX + 0x4c + param_4 * 4) = uVar13;
      }
      piVar11 = *(int **)(in_ECX + 0x4c + param_4 * 4);
      piVar11[10] = *param_3;
      return piVar11;
    }
    break;
  case (int *)0x17:
    param_2 = (int *)0x0;
    if (*(int *)(in_ECX + 0x90) != 0) {
      if (*(int *)(in_ECX + 0x4c + param_4 * 4) == 0) {
        iVar12 = FUN_00746d70(0x34,s_C__dev_black_GroupBehaviour_cpp_00b1cf3c,0x166);
        if (iVar12 == 0) {
          uVar13 = 0;
        }
        else {
          uVar13 = FUN_004ecfd0(in_ECX);
        }
        *(undefined4 *)(in_ECX + 0x4c + param_4 * 4) = uVar13;
      }
      param_2 = *(int **)(in_ECX + 0x4c + param_4 * 4);
      param_2[0xb] = *param_3;
    }
  }
  return param_2;
code_r0x0055d9a5:
  piVar11 = (int *)*piVar11;
  if (piVar11 == (int *)0x0) goto LAB_0055d9f3;
  goto LAB_0055d9a0;
code_r0x0055d8ce:
  piVar11 = (int *)*piVar11;
  if (piVar11 == (int *)0x0) goto LAB_0055d91c;
  goto LAB_0055d8c9;
}



