// Decompiled functions for class: SkirmishGameBox
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Init@SkirmishGameBox@@UAEXIIP6AXHPAVSetupBox@@PAVSetupControl@@HH@Z@Z @ 0x00517fb0

void _Init_SkirmishGameBox__UAEXIIP6AXHPAVSetupBox__PAVSetupControl__HH_Z_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  int in_ECX;
  
  _Init__13DialogBoxBaseFUlUlPFiP8SetupBoxP12SetupControlii_v(param_1,param_2,param_3);
  DAT_00bf1ed4 = in_ECX;
  uVar1 = FUN_00405ef0();
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0xac) = uVar1;
  puVar2 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_frontend_cpp_00b17740,0xd95);
  if (puVar2 == (undefined4 *)0x0) {
    puVar2 = (undefined4 *)0x0;
  }
  else {
    FUN_00407730(1,0x28,0x1e,0x2d0,0x28,&DAT_00b6e5f0);
    *puVar2 = &PTR_LAB_007ed4e8;
    puVar2[0x8f] = 4;
    *(undefined1 *)((int)puVar2 + 0x22a) = 0;
    puVar2[0x90] = 0;
  }
  *(undefined4 **)(in_ECX + 0x24) = puVar2;
  iVar3 = FUN_00746d70(0x25c,s_C__dev_black_frontend_cpp_00b17740,0xd97);
  if (iVar3 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_0040b4a0(999,0x1e,0x212,&DAT_00b6e5f0,0x28,0,2);
  }
  *(undefined4 *)(in_ECX + 0x28) = uVar1;
  iVar3 = FUN_00746d70(0x25c,s_C__dev_black_frontend_cpp_00b17740,0xd98);
  if (iVar3 == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = FUN_0040b4a0(0x3e6,0x2da,0x212,&DAT_00b6e5f0,0x28,1,3);
  }
  *(undefined4 *)(in_ECX + 0x2c) = uVar1;
  iVar3 = FUN_00746d70(0x2b0,s_C__dev_black_frontend_cpp_00b17740,0xd99);
  if (iVar3 != 0) {
    iVar3 = FUN_004087c0(0,100,0x6e,600,0x17c);
    *(int *)(in_ECX + 0x10) = iVar3;
    *(undefined1 *)(iVar3 + 0x291) = 1;
    return;
  }
  *(undefined4 *)(in_ECX + 0x10) = 0;
  uRam00000291 = 1;
  return;
}



// ?Destroy@SkirmishGameBox@@UAEXXZ @ 0x00518230

void _Destroy_SkirmishGameBox__UAEXXZ(void)

{
  _Destroy__13DialogBoxBaseFv();
  DAT_00bf1ed4 = 0;
  return;
}



// ?InitControls@SkirmishGameBox@@UAEXXZ @ 0x00518270

/* WARNING: Removing unreachable block (ram,0x00518337) */

void _InitControls_SkirmishGameBox__UAEXXZ(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int in_ECX;
  int iVar6;
  undefined1 auStack_140 [36];
  undefined1 auStack_11c [284];
  
  iVar2 = DAT_00c38db8;
  if (0xd7a < DAT_00c38dbc) {
    iVar2 = DAT_00c38db8 + 0xa1b8;
  }
  FUN_00733ff8(*(int *)(in_ECX + 0x28) + 0x24,*(undefined4 *)(iVar2 + 8));
  iVar2 = DAT_00c38db8;
  if (0xdb4 < DAT_00c38dbc) {
    iVar2 = DAT_00c38db8 + 0xa470;
  }
  FUN_00733ff8(*(int *)(in_ECX + 0x2c) + 0x24,*(undefined4 *)(iVar2 + 8));
  iVar2 = DAT_00c38db8;
  if (0x1a3c < DAT_00c38dbc) {
    iVar2 = DAT_00c38db8 + 0x13ad0;
  }
  FUN_00733ff8(*(int *)(in_ECX + 0x24) + 0x24,*(undefined4 *)(iVar2 + 8));
  iVar3 = (*(code *)0x4ab20a3)(s___scripts_playgrounds___txt_00b17928,auStack_140);
  iVar2 = *(int *)(in_ECX + 0x10);
  iVar1 = *(int *)(iVar2 + 0x250);
  while (0 < iVar1) {
    FUN_004090d0(iVar1 + -1);
    iVar1 = *(int *)(iVar2 + 0x250);
  }
  iVar1 = *(int *)(in_ECX + 0x1c);
  iVar2 = *(int *)(in_ECX + 0x18);
  for (iVar6 = iVar2; iVar6 != iVar1; iVar6 = iVar6 + 0x10) {
    FUN_005193f0(0);
  }
  *(int *)(in_ECX + 0x1c) = iVar2;
  if (iVar3 != -1) {
    do {
      uVar4 = FUN_00518240(auStack_11c);
      iVar2 = FUN_00734de0(s_TwoGods_00b17920,auStack_11c);
      if (iVar2 == 0) {
        iVar2 = DAT_00c38db8;
        if (0x1b36 < DAT_00c38dbc) {
          iVar2 = DAT_00c38db8 + 0x14688;
        }
LAB_00518426:
        uVar4 = *(undefined4 *)(iVar2 + 8);
      }
      else {
        iVar2 = FUN_00734de0(s_ThreeGods_00b17914,auStack_11c);
        if (iVar2 == 0) {
          iVar2 = DAT_00c38db8;
          if (0x1b37 < DAT_00c38dbc) {
            iVar2 = DAT_00c38db8 + 0x14694;
          }
          goto LAB_00518426;
        }
        iVar2 = FUN_00734de0(s_FourGods_00b17908,auStack_11c);
        if (iVar2 == 0) {
          iVar2 = DAT_00c38db8;
          if (0x1b38 < DAT_00c38dbc) {
            iVar2 = DAT_00c38db8 + 0x146a0;
          }
          goto LAB_00518426;
        }
      }
      uVar5 = FUN_00789090(auStack_11c);
      FUN_00518120(uVar4,uVar5);
      iVar2 = (*(code *)&DAT_04ab1377)(iVar3,&stack0xfffffeb8);
    } while (iVar2 != 0);
  }
  (*(code *)0x4aba7a6)(iVar3);
  (**(code **)(**(int **)(in_ECX + 0x2c) + 8))
            (CONCAT31((int3)((uint)*(int *)(in_ECX + 0x10) >> 8),
                      *(int *)(*(int *)(in_ECX + 0x10) + 0x248) == -1));
  return;
}



