// Decompiled functions for class: Morphable
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?SetAnimTime@Morphable@@UAEXHH@Z @ 0x005d0570

void _SetAnimTime_Morphable__UAEXHH_Z(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    puVar1 = (undefined4 *)FUN_005d1bd0(param_1,iVar2,0);
    if (puVar1 != (undefined4 *)0x0) {
      *puVar1 = param_2;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 6);
  return;
}



// ?LoadBase@Morphable@@UAEIPAD@Z @ 0x005d0a20

undefined4 _LoadBase_Morphable__UAEIPAD_Z(char *param_1)

{
  char cVar1;
  undefined4 uVar2;
  int in_ECX;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  char *pcVar7;
  char *pcVar8;
  char *pcVar9;
  float10 fVar10;
  undefined4 local_80;
  int local_7c;
  undefined4 local_78;
  undefined1 local_74 [4];
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  char local_40 [64];
  
  uVar3 = 0xffffffff;
  pcVar7 = s_data_creaturemesh__00b20f08;
  do {
    pcVar9 = pcVar7;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  pcVar7 = pcVar9 + -uVar3;
  pcVar9 = local_40;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar3 = 0xffffffff;
  pcVar7 = param_1;
  do {
    pcVar9 = pcVar7;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  iVar5 = -1;
  pcVar7 = local_40;
  do {
    pcVar8 = pcVar7;
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  pcVar7 = pcVar9 + -uVar3;
  pcVar9 = pcVar8 + -1;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  uVar3 = 0xffffffff;
  pcVar7 = &DAT_00b20f00;
  do {
    pcVar9 = pcVar7;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar9 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar9;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  iVar5 = -1;
  pcVar7 = local_40;
  do {
    pcVar8 = pcVar7;
    if (iVar5 == 0) break;
    iVar5 = iVar5 + -1;
    pcVar8 = pcVar7 + 1;
    cVar1 = *pcVar7;
    pcVar7 = pcVar8;
  } while (cVar1 != '\0');
  pcVar7 = pcVar9 + -uVar3;
  pcVar9 = pcVar8 + -1;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
    pcVar7 = pcVar7 + 4;
    pcVar9 = pcVar9 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar9 = *pcVar7;
    pcVar7 = pcVar7 + 1;
    pcVar9 = pcVar9 + 1;
  }
  iVar5 = FUN_0072bed0(local_40,&local_80);
  if (iVar5 != 0) {
    FUN_005cfa00(s_Can_t_open_town___00b20eec,local_40);
    return 0;
  }
  uVar2 = FUN_0079a330(local_80);
  local_78 = uVar2;
  FUN_0072c360(local_40,uVar2,local_80,local_74);
  local_7c = 0;
  piVar6 = (int *)(in_ECX + 0xb4);
  do {
    iVar5 = FUN_007632b0(uVar2,0);
    if (iVar5 == 0) {
      FUN_005cfa00(s_Mesh_file_invalid___00b20ebc,local_40);
      FUN_0079a3b0(uVar2);
      return 0;
    }
    if (*(int *)(iVar5 + 0xc) != 1) {
      FUN_005cfa00(s_House_count_not_1___00b20ed4,local_40);
      FUN_0079a3b0(uVar2);
      FUN_00763b50();
      return 0;
    }
    if (*piVar6 != 0) {
      FUN_00763b50();
    }
    uVar3 = 0xffffffff;
    *piVar6 = iVar5;
    pcVar7 = param_1;
    do {
      pcVar9 = pcVar7;
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      pcVar9 = pcVar7 + 1;
      cVar1 = *pcVar7;
      pcVar7 = pcVar9;
    } while (cVar1 != '\0');
    uVar3 = ~uVar3;
    pcVar7 = pcVar9 + -uVar3;
    pcVar9 = (char *)(in_ECX + 0xf4);
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar9 = *(undefined4 *)pcVar7;
      pcVar7 = pcVar7 + 4;
      pcVar9 = pcVar9 + 4;
    }
    local_7c = local_7c + 1;
    piVar6 = piVar6 + 1;
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar9 = *pcVar7;
      pcVar7 = pcVar7 + 1;
      pcVar9 = pcVar9 + 1;
    }
    uVar2 = local_78;
    if (1 < local_7c) {
      FUN_0079a3b0(local_78);
      *(undefined4 *)(in_ECX + 0x47b8) =
           *(undefined4 *)(**(int **)(*(int *)(in_ECX + 0xb8) + 0x10) + 0xc);
      if (*(int *)(in_ECX + 0x47f0) != 0) {
        FUN_007290de(*(int *)(in_ECX + 0x47f0));
      }
      if (*(int *)(in_ECX + 0x47f4) != 0) {
        FUN_007290de(*(int *)(in_ECX + 0x47f4));
      }
      if (*(int *)(in_ECX + 0x47f8) != 0) {
        FUN_007290de(*(int *)(in_ECX + 0x47f8));
      }
      uVar2 = FUN_00746d70(*(int *)(in_ECX + 0x47b8) * 0x30,
                           s_C__dev_black_MorphableObject_cpp_00b20e98,0x313);
      *(undefined4 *)(in_ECX + 0x47f0) = uVar2;
      uVar2 = FUN_00746d70(*(int *)(in_ECX + 0x47b8) * 0x30,
                           s_C__dev_black_MorphableObject_cpp_00b20e98,0x314);
      *(undefined4 *)(in_ECX + 0x47f4) = uVar2;
      uVar2 = FUN_00746d70(*(int *)(in_ECX + 0x47b8) * 0x30,
                           s_C__dev_black_MorphableObject_cpp_00b20e98,0x315);
      *(undefined4 *)(in_ECX + 0x47f8) = uVar2;
      local_44 = 0;
      local_48 = 0;
      local_4c = 0;
      local_54 = 0;
      local_58 = 0;
      local_5c = 0;
      local_64 = 0;
      local_68 = 0;
      local_6c = 0;
      local_50 = 0x3f800000;
      local_60 = 0x3f800000;
      local_70 = 0x3f800000;
      fVar10 = (float10)FUN_0078f6e0(*(undefined4 *)(in_ECX + 0x47f4),*(undefined4 *)(in_ECX + 0xb8)
                                     ,&local_70);
      *(float *)(in_ECX + 0x8c) = (float)fVar10;
      iVar5 = 0;
      if (0 < *(int *)(in_ECX + 0x47b8)) {
        do {
          FUN_00759970();
          iVar5 = iVar5 + 1;
        } while (iVar5 < *(int *)(in_ECX + 0x47b8));
      }
      return 1;
    }
  } while( true );
}



// ?MorphAnims@Morphable@@UAEXXZ @ 0x005d1640

void _MorphAnims_Morphable__UAEXXZ(void)

{
  float *pfVar1;
  undefined4 *puVar2;
  int in_ECX;
  float *pfVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 *puVar7;
  uint uVar8;
  int iVar9;
  undefined4 *puVar10;
  int *piVar11;
  float local_38;
  float local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  if (0.0 <= *(float *)(in_ECX + 0xa0)) {
    local_34 = *(float *)(in_ECX + 0xa0);
    uVar8 = -(uint)(*(int *)(in_ECX + 0xc0) != 0) & 2;
  }
  else {
    local_34 = -*(float *)(in_ECX + 0xa0);
    uVar8 = (uint)(*(int *)(in_ECX + 0xbc) != 0);
  }
  if (0.0 <= *(float *)(in_ECX + 0xa8)) {
    local_38 = *(float *)(in_ECX + 0xa8);
    uVar5 = -(uint)(*(int *)(in_ECX + 200) != 0) & 4;
  }
  else {
    local_38 = -*(float *)(in_ECX + 0xa8);
    uVar5 = -(uint)(*(int *)(in_ECX + 0xc4) != 0) & 3;
  }
  local_4 = 0;
  local_8 = 0;
  local_c = 0;
  local_14 = 0;
  local_18 = 0;
  local_1c = 0;
  local_24 = 0;
  local_28 = 0;
  local_2c = 0;
  local_10 = 0x3f800000;
  local_20 = 0x3f800000;
  local_30 = 0x3f800000;
  FUN_0078f6e0(*(undefined4 *)(in_ECX + 0x47f0),*(undefined4 *)(in_ECX + 0xb8),&local_30);
  FUN_0078f6e0(*(undefined4 *)(in_ECX + 0x47f4),*(undefined4 *)(in_ECX + 0xb4 + (uVar8 + 1) * 4),
               &local_30);
  FUN_0078f6e0(*(undefined4 *)(in_ECX + 0x47f8),*(undefined4 *)(in_ECX + 0xb4 + (uVar5 + 1) * 4),
               &local_30);
  iVar9 = 0;
  if (0 < *(int *)(in_ECX + 0x47b8)) {
    iVar6 = 0;
    do {
      iVar4 = *(int *)(in_ECX + 0x47f4) + iVar6;
      pfVar3 = (float *)(*(int *)(in_ECX + 0x47f8) + iVar6);
      pfVar1 = (float *)(*(int *)(in_ECX + 0x47f0) + iVar6);
      *pfVar1 = (*pfVar3 - *pfVar1) * local_38 +
                (*(float *)(*(int *)(in_ECX + 0x47f4) + iVar6) -
                *(float *)(*(int *)(in_ECX + 0x47f0) + iVar6)) * local_34 + *pfVar1;
      pfVar1[1] = (*(float *)(iVar4 + 4) - pfVar1[1]) * local_34 +
                  (pfVar3[1] - pfVar1[1]) * local_38 + pfVar1[1];
      pfVar1[2] = (*(float *)(iVar4 + 8) - pfVar1[2]) * local_34 +
                  (pfVar3[2] - pfVar1[2]) * local_38 + pfVar1[2];
      pfVar1[3] = (*(float *)(iVar4 + 0xc) - pfVar1[3]) * local_34 +
                  (pfVar3[3] - pfVar1[3]) * local_38 + pfVar1[3];
      pfVar1[4] = (*(float *)(iVar4 + 0x10) - pfVar1[4]) * local_34 +
                  (pfVar3[4] - pfVar1[4]) * local_38 + pfVar1[4];
      pfVar1[5] = (*(float *)(iVar4 + 0x14) - pfVar1[5]) * local_34 +
                  (pfVar3[5] - pfVar1[5]) * local_38 + pfVar1[5];
      pfVar1[6] = (*(float *)(iVar4 + 0x18) - pfVar1[6]) * local_34 +
                  (pfVar3[6] - pfVar1[6]) * local_38 + pfVar1[6];
      pfVar1[7] = (*(float *)(iVar4 + 0x1c) - pfVar1[7]) * local_34 +
                  (pfVar3[7] - pfVar1[7]) * local_38 + pfVar1[7];
      pfVar1[8] = (*(float *)(iVar4 + 0x20) - pfVar1[8]) * local_34 +
                  (pfVar3[8] - pfVar1[8]) * local_38 + pfVar1[8];
      iVar9 = iVar9 + 1;
      iVar6 = iVar6 + 0x30;
      pfVar1[9] = (*(float *)(iVar4 + 0x24) - pfVar1[9]) * local_34 +
                  (pfVar3[9] - pfVar1[9]) * local_38 + pfVar1[9];
      pfVar1[10] = (*(float *)(iVar4 + 0x28) - pfVar1[10]) * local_34 +
                   (pfVar3[10] - pfVar1[10]) * local_38 + pfVar1[10];
      pfVar1[0xb] = (*(float *)(iVar4 + 0x2c) - pfVar1[0xb]) * local_34 +
                    (pfVar3[0xb] - pfVar1[0xb]) * local_38 + pfVar1[0xb];
    } while (iVar9 < *(int *)(in_ECX + 0x47b8));
  }
  FUN_0078f530(*(undefined4 *)(in_ECX + 0x47f0),*(undefined4 *)(in_ECX + 0xb4),&local_30);
  iVar9 = *(int *)(in_ECX + 0xb4);
  local_34 = 0.0;
  if (0 < *(int *)(iVar9 + 0xc)) {
    do {
      iVar6 = 0;
      if (0 < *(int *)(in_ECX + 0x47b8)) {
        iVar4 = 0;
        puVar2 = (undefined4 *)
                 (*(int *)(*(int *)(*(int *)(iVar9 + 0x10) + (int)local_34 * 4) + 0x10) + 0xc);
        do {
          puVar7 = (undefined4 *)(*(int *)(in_ECX + 0x47f0) + iVar4);
          puVar10 = puVar2;
          for (iVar9 = 0xc; iVar9 != 0; iVar9 = iVar9 + -1) {
            *puVar10 = *puVar7;
            puVar7 = puVar7 + 1;
            puVar10 = puVar10 + 1;
          }
          iVar6 = iVar6 + 1;
          iVar4 = iVar4 + 0x30;
          puVar2 = puVar2 + 0xf;
        } while (iVar6 < *(int *)(in_ECX + 0x47b8));
      }
      iVar9 = *(int *)(in_ECX + 0xb4);
      local_34 = (float)((int)local_34 + 1);
    } while ((int)local_34 < *(int *)(iVar9 + 0xc));
  }
  if (*(int *)(in_ECX + 0x98) == 0) {
    FUN_0078f6e0(*(undefined4 *)(in_ECX + 0x47f4),*(undefined4 *)(in_ECX + 0xb4),&local_30);
    iVar9 = 0;
    if (0 < *(int *)(in_ECX + 0x47b8)) {
      do {
        FUN_00759970();
        iVar9 = iVar9 + 1;
      } while (iVar9 < *(int *)(in_ECX + 0x47b8));
    }
  }
  piVar11 = (int *)(in_ECX + 0x1d4);
  iVar9 = 0xe8;
  do {
    iVar6 = *piVar11;
    if (iVar6 != 0) {
      thunk_FUN_007b3a40();
      FUN_007290de(iVar6);
      *piVar11 = 0;
    }
    piVar11 = piVar11 + 1;
    iVar9 = iVar9 + -1;
  } while (iVar9 != 0);
  iVar9 = FUN_005d1b90(0,0);
  if (iVar9 != 0) {
    *(undefined4 *)(in_ECX + 0x47fc) = **(undefined4 **)(iVar9 + 0x34);
  }
  return;
}



// ?MorphTexture@Morphable@@UAEXXZ @ 0x005d1a40

void _MorphTexture_Morphable__UAEXXZ(void)

{
  float fVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int in_ECX;
  int *piVar5;
  int iVar6;
  int iVar7;
  
  iVar7 = *(int *)(in_ECX + 0xb4);
  iVar6 = 0;
  if (0 < *(int *)(iVar7 + 0x38)) {
    __ftol();
    do {
      iVar7 = *(int *)(*(int *)(iVar7 + 0x3c) + iVar6 * 4);
      FUN_0078e550();
      uVar2 = FUN_0078e550();
      uVar3 = FUN_0078e550();
      FUN_007c2d90(uVar2,uVar3);
      uVar4 = *(uint *)(iVar7 + 0x10) & 0x3f;
      if ((uVar4 == 8) || (uVar4 == 4)) {
        *(undefined4 *)(iVar7 + 0x138) = 1;
      }
      iVar7 = *(int *)(in_ECX + 0xb4);
      iVar6 = iVar6 + 1;
    } while (iVar6 < *(int *)(iVar7 + 0x38));
  }
  iVar7 = 0;
  if (0 < *(int *)(in_ECX + 0x4800)) {
    piVar5 = (int *)(in_ECX + 0x4804);
    do {
      fVar1 = *(float *)(in_ECX + 0x9c);
      iVar6 = *piVar5;
      *(float *)(iVar6 + 100) = fVar1;
      if (-0.95 <= fVar1) {
        if (fVar1 <= 0.95) {
          *(undefined4 *)(iVar6 + 0x6c) = 0;
        }
        else {
          *(undefined4 *)(iVar6 + 0x6c) = 2;
        }
      }
      else {
        *(undefined4 *)(iVar6 + 0x6c) = 1;
      }
      iVar7 = iVar7 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar7 < *(int *)(in_ECX + 0x4800));
  }
  return;
}



