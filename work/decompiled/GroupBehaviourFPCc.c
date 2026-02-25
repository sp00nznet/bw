// Decompiled functions for class: GroupBehaviourFPCc
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// _LoadDance__14GroupBehaviourFPCc @ 0x0055e500

/* WARNING: Removing unreachable block (ram,0x0055ea7d) */

void _LoadDance__14GroupBehaviourFPCc(char *param_1)

{
  char cVar1;
  undefined4 uVar2;
  bool bVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int *piVar8;
  int in_ECX;
  uint uVar9;
  uint uVar10;
  int *piVar11;
  uint uVar12;
  int *piVar13;
  int unaff_EBP;
  int iVar14;
  char *pcVar15;
  char *pcVar16;
  uint uVar17;
  int in_stack_00005be9;
  uint uStack_658;
  uint uStack_654;
  uint uStack_650;
  uint uStack_64c;
  undefined4 uStack_648;
  int iStack_638;
  int iStack_130;
  
  FUN_0072bc10();
  iVar4 = (**(code **)(iStack_638 + 4))();
  if (iVar4 == 0) {
    bVar3 = true;
    iStack_130 = 2;
    FUN_0072be50();
    uVar9 = 0xffffffff;
    do {
      pcVar15 = param_1;
      if (uVar9 == 0) break;
      uVar9 = uVar9 - 1;
      pcVar15 = param_1 + 1;
      cVar1 = *param_1;
      param_1 = pcVar15;
    } while (cVar1 != '\0');
    uVar9 = ~uVar9;
    pcVar15 = pcVar15 + -uVar9;
    pcVar16 = &stack0x00005bf1;
    for (uVar10 = uVar9 >> 2; uVar10 != 0; uVar10 = uVar10 - 1) {
      *(undefined4 *)pcVar16 = *(undefined4 *)pcVar15;
      pcVar15 = pcVar15 + 4;
      pcVar16 = pcVar16 + 4;
    }
    for (uVar9 = uVar9 & 3; uVar9 != 0; uVar9 = uVar9 - 1) {
      *pcVar16 = *pcVar15;
      pcVar15 = pcVar15 + 1;
      pcVar16 = pcVar16 + 1;
    }
  }
  else {
    in_stack_00005be9 = 0;
    bVar3 = false;
  }
  if (in_stack_00005be9 == 0) {
    if (in_stack_00005be9 == 0) goto LAB_0055ea86;
  }
  else {
    for (piVar8 = *(int **)(in_ECX + 0x38); piVar8 != (int *)0x0; piVar8 = (int *)piVar8[1]) {
      if ((int *)*piVar8 != (int *)0x0) {
        (**(code **)(*(int *)*piVar8 + 4))();
      }
    }
    iVar4 = *(int *)(in_ECX + 0x3c);
    while (iVar4 != 0) {
      iVar4 = *(int *)(in_ECX + 0x38);
      while (iVar4 != 0) {
        iVar4 = *(int *)(iVar4 + 4);
        *(undefined4 *)(in_ECX + 0x38) = *(undefined4 *)(*(int *)(in_ECX + 0x38) + 4);
        FUN_007290de();
        *(int *)(in_ECX + 0x3c) = *(int *)(in_ECX + 0x3c) + -1;
      }
      iVar4 = *(int *)(in_ECX + 0x3c);
    }
    FUN_006ab530();
    FUN_006ab530();
    uVar9 = 0;
    if (uStack_654 != 0) {
      do {
        puVar5 = (undefined4 *)FUN_004300a0();
        if (puVar5 == (undefined4 *)0x0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          FUN_0053e720();
          puVar5[7] = 0;
          puVar5[6] = 0;
          *puVar5 = &vftable_DanceKeyFrame;
        }
        FUN_006ab530();
        FUN_006ab530();
        FUN_006ab530();
        uStack_650 = 0;
        if (uStack_658 != 0) {
          do {
            iVar4 = FUN_004300a0();
            if (iVar4 == 0) {
              iVar4 = 0;
            }
            else {
              iVar4 = FUN_004ec250();
            }
            FUN_006ab530();
            uVar10 = 0;
            if (uStack_64c != 0) {
              do {
                FUN_006ab530();
                puVar6 = operator_new(8);
                if (puVar6 == (undefined4 *)0x0) {
                  puVar6 = (undefined4 *)0x0;
                }
                else {
                  uVar2 = *(undefined4 *)(iVar4 + 0x14);
                  *puVar6 = uStack_648;
                  puVar6[1] = uVar2;
                }
                *(undefined4 **)(iVar4 + 0x14) = puVar6;
                *(int *)(iVar4 + 0x18) = *(int *)(iVar4 + 0x18) + 1;
                uVar10 = uVar10 + 1;
              } while (uVar10 < uStack_64c);
            }
            FUN_006ab530();
            iVar14 = 0x38;
            do {
              FUN_006ab4b0();
              iVar14 = iVar14 + -1;
            } while (iVar14 != 0);
            if ((iVar4 != 0) && (puVar6 = operator_new(8), puVar6 != (undefined4 *)0x0)) {
              puVar6[1] = iVar4;
              *puVar6 = 0;
              puVar7 = (undefined4 *)FUN_004ecf10();
              if (puVar7 == (undefined4 *)0x0) {
                puVar5[6] = puVar6;
              }
              else {
                *puVar7 = puVar6;
              }
              puVar5[7] = puVar5[7] + 1;
            }
            uStack_650 = uStack_650 + 1;
          } while (uStack_650 < uStack_658);
        }
        puVar6 = operator_new(8);
        if (puVar6 == (undefined4 *)0x0) {
          puVar6 = (undefined4 *)0x0;
        }
        else {
          *puVar6 = puVar5;
          puVar6[1] = 0;
        }
        piVar8 = *(int **)(in_ECX + 0x38);
        piVar13 = (int *)0x0;
        if (*(int **)(in_ECX + 0x38) == (int *)0x0) {
LAB_0055e818:
          *(undefined4 **)(in_ECX + 0x38) = puVar6;
        }
        else {
          do {
            piVar11 = piVar8;
            if ((float)puVar5[5] <= *(float *)(*piVar11 + 0x14)) {
              puVar6[1] = piVar11;
              if (piVar13 == (int *)0x0) {
                *(undefined4 **)(in_ECX + 0x38) = puVar6;
              }
              else {
                piVar13[1] = (int)puVar6;
              }
              if (piVar11 != (int *)0x0) goto LAB_0055e820;
              break;
            }
            piVar8 = (int *)piVar11[1];
            piVar13 = piVar11;
          } while ((int *)piVar11[1] != (int *)0x0);
          if (piVar13 == (int *)0x0) goto LAB_0055e818;
          piVar13[1] = (int)puVar6;
        }
LAB_0055e820:
        uVar9 = uVar9 + 1;
        *(int *)(in_ECX + 0x3c) = *(int *)(in_ECX + 0x3c) + 1;
      } while (uVar9 < uStack_654);
    }
    FUN_006ab530();
    FUN_006ab530();
    FUN_006ab530();
    FUN_006ab530();
    FUN_006ab530();
    if (1 < DAT_00c27c28) {
      FUN_006ab530();
    }
    uVar10 = 0;
    if (*(int *)(unaff_EBP + 0x40) != 0) {
      do {
        uVar17 = *(uint *)(unaff_EBP + 0x7c);
        while (uVar17 <= uVar10) {
          iVar4 = FUN_004300a0();
          if (iVar4 == 0) {
            iVar4 = 0;
          }
          else {
            iVar4 = FUN_004eb050();
          }
          *(int *)(iVar4 + 0x18) = unaff_EBP;
          iVar14 = FUN_007344da();
          if (iVar14 != 0) {
            *(int *)(iVar4 + 0x14) = iVar14;
          }
          *(undefined4 *)(iVar4 + 0x24) = *(undefined4 *)(unaff_EBP + 0x7c);
          if ((iVar4 != 0) && (puVar5 = operator_new(8), puVar5 != (undefined4 *)0x0)) {
            puVar5[1] = iVar4;
            *puVar5 = 0;
            puVar6 = (undefined4 *)FUN_004ecf10();
            if (puVar6 == (undefined4 *)0x0) {
              *(undefined4 **)(unaff_EBP + 0x78) = puVar5;
            }
            else {
              *puVar6 = puVar5;
            }
            *(int *)(unaff_EBP + 0x7c) = *(int *)(unaff_EBP + 0x7c) + 1;
          }
          uVar17 = *(uint *)(unaff_EBP + 0x7c);
        }
        FUN_0055f660();
        FUN_004eb140();
        uVar10 = uVar10 + 1;
      } while (uVar10 < *(uint *)(unaff_EBP + 0x40));
    }
    for (piVar8 = *(int **)(unaff_EBP + 0x38);
        (piVar8 != (int *)0x0 && (*(float *)(*piVar8 + 0x14) <= *(float *)(unaff_EBP + 0x28)));
        piVar8 = (int *)piVar8[1]) {
      FUN_0055d520();
    }
    FUN_0055e140();
    if ((DAT_00c27c28 != 0) && (uVar10 = 0, *(int *)(unaff_EBP + 0x40) != 0)) {
      do {
        FUN_006ab530();
        uVar17 = 0;
        if (uVar9 != 0) {
          do {
            if ((((*(int *)(unaff_EBP + 0x7c) != 0) && (*(int *)(unaff_EBP + 0x78) != 0)) &&
                ((int)uVar10 < *(int *)(unaff_EBP + 0x7c))) && (uVar12 = uVar10, 0 < (int)uVar10)) {
              do {
                uVar12 = uVar12 - 1;
              } while (uVar12 != 0);
            }
            FUN_006ab4b0();
            uVar17 = uVar17 + 1;
          } while (uVar17 < uVar9);
        }
        if (((*(int *)(unaff_EBP + 0x7c) == 0) ||
            (piVar8 = *(int **)(unaff_EBP + 0x78), piVar8 == (int *)0x0)) ||
           (*(int *)(unaff_EBP + 0x7c) <= (int)uVar10)) {
LAB_0055ea2b:
          iVar4 = 0;
        }
        else {
          uVar12 = uVar10;
          if (0 < (int)uVar10) {
            do {
              uVar12 = uVar12 - 1;
              piVar8 = (int *)*piVar8;
            } while (uVar12 != 0);
          }
          if (piVar8 == (int *)0x0) goto LAB_0055ea2b;
          iVar4 = piVar8[1];
        }
        *(undefined1 *)(iVar4 + 0xa8 + uVar17) = 0;
        uVar10 = uVar10 + 1;
      } while (uVar10 < *(uint *)(unaff_EBP + 0x40));
    }
    if (!bVar3) goto LAB_0055ea86;
  }
  if (iStack_130 != 2) {
    FUN_006ab1f0();
  }
  FUN_0072bdd0();
LAB_0055ea86:
  FUN_0072bc20();
  return;
}



