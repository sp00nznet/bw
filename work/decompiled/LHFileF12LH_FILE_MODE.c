// Decompiled functions for class: LHFileF12LH_FILE_MODE
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// _Open__6LHFileF12LH_FILE_MODE @ 0x0072c990

undefined4 _Open__6LHFileF12LH_FILE_MODE(int param_1)

{
  char cVar1;
  byte bVar2;
  int in_ECX;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  byte *pbVar7;
  char *pcVar8;
  byte *pbVar9;
  char *pcVar10;
  bool bVar11;
  
  if (*(int *)(in_ECX + 0xc) != 0) {
    return 3;
  }
  if (((param_1 != 2) && (param_1 != 0)) && (param_1 != 3)) {
    return 3;
  }
  pcVar8 = *(char **)(in_ECX + 0x68);
  if (pcVar8 != (char *)0x0) {
    iVar3 = -1;
    pcVar10 = pcVar8;
    do {
      if (iVar3 == 0) break;
      iVar3 = iVar3 + -1;
      cVar1 = *pcVar10;
      pcVar10 = pcVar10 + 1;
    } while (cVar1 != '\0');
    if (iVar3 != -2) {
      if ((param_1 == 3) && (*(int *)(in_ECX + 0x40) != 0)) {
        return 3;
      }
      uVar6 = 2;
      iVar3 = (*(code *)0x4ab72f6)(pcVar8);
      if (iVar3 == -1) {
        if ((param_1 == 2) || (param_1 == 3)) {
          return 2;
        }
      }
      else {
        uVar6 = 5;
        if (param_1 == 3) {
          uVar6 = 3;
        }
      }
      if ((*(int *)(in_ECX + 0x40) == 0) && ((param_1 == 0 || (param_1 == 3)))) {
        uVar6 = (*(code *)0x4ac771b)(*(undefined4 *)(in_ECX + 0x68),0xc0000000,3,0,uVar6,0,0);
        *(undefined4 *)(in_ECX + 0x10) = uVar6;
      }
      if ((*(int *)(in_ECX + 0x44) == 0) && (param_1 == 2)) {
        uVar6 = (*(code *)0x4ac771b)(*(undefined4 *)(in_ECX + 0x68),0x80000000,1,0,4,0,0);
        *(undefined4 *)(in_ECX + 0x10) = uVar6;
      }
      if ((*(int *)(in_ECX + 0x40) == 0) && (*(int *)(in_ECX + 0x10) == -1)) {
        return 3;
      }
      *(undefined4 *)(in_ECX + 0xc) = 1;
      *(int *)(in_ECX + 0x50) = param_1;
      if ((param_1 == 2) || (param_1 == 3)) {
        FUN_0072d3d0(&stack0xfffffff0,8);
        pbVar9 = &stack0xfffffff0;
        pbVar7 = PTR_s_LiOnHeAd_00b4deec;
        do {
          bVar2 = *pbVar7;
          bVar11 = bVar2 < *pbVar9;
          if (bVar2 != *pbVar9) {
LAB_0072cb19:
            iVar3 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
            goto LAB_0072cb1e;
          }
          if (bVar2 == 0) break;
          bVar2 = pbVar7[1];
          bVar11 = bVar2 < pbVar9[1];
          if (bVar2 != pbVar9[1]) goto LAB_0072cb19;
          pbVar7 = pbVar7 + 2;
          pbVar9 = pbVar9 + 2;
        } while (bVar2 != 0);
        iVar3 = 0;
LAB_0072cb1e:
        if (iVar3 != 0) {
          FUN_0072cf20();
          return 2;
        }
        FUN_0072cc60();
      }
      if (param_1 == 0) {
        uVar4 = 0xffffffff;
        pcVar8 = PTR_s_LiOnHeAd_00b4deec;
        do {
          pcVar10 = pcVar8;
          if (uVar4 == 0) break;
          uVar4 = uVar4 - 1;
          pcVar10 = pcVar8 + 1;
          cVar1 = *pcVar8;
          pcVar8 = pcVar10;
        } while (cVar1 != '\0');
        uVar4 = ~uVar4;
        pcVar8 = pcVar10 + -uVar4;
        pcVar10 = &stack0xfffffff0;
        for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
          *(undefined4 *)pcVar10 = *(undefined4 *)pcVar8;
          pcVar8 = pcVar8 + 4;
          pcVar10 = pcVar10 + 4;
        }
        for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *pcVar10 = *pcVar8;
          pcVar8 = pcVar8 + 1;
          pcVar10 = pcVar10 + 1;
        }
        FUN_0072d340(&stack0xfffffff0,8);
      }
      *(undefined4 *)(in_ECX + 0x5c) = 8;
      if (param_1 == 3) {
        if (*(int *)(in_ECX + 4) == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = *(int *)(*(int *)(in_ECX + 4) + 4);
        }
        iVar3 = FUN_0072d030(iVar3,*(undefined4 *)(iVar3 + 0x28));
        if (iVar3 != 0) {
          return 3;
        }
      }
      return 0;
    }
  }
  return 3;
}



