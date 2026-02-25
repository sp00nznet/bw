// Decompiled functions for class: StatsBox
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Init@StatsBox@@UAEXIIP6AXHPAVSetupBox@@PAVSetupControl@@HH@Z@Z @ 0x0053cce0

void _Init_StatsBox__UAEXIIP6AXHPAVSetupBox__PAVSetupControl__HH_Z_Z
               (uint param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int *piVar6;
  int in_ECX;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  undefined4 uVar11;
  uint uVar12;
  int local_8 [2];
  
  *(undefined4 *)(in_ECX + 0x6c) = 0;
  *(undefined4 *)(in_ECX + 0x70) = 0;
  _Init__13DialogBoxBaseFUlUlPFiP8SetupBoxP12SetupControlii_v(param_1,param_2,param_3);
  local_8[0] = 400 - (param_1 >> 1);
  local_8[1] = 0;
  DAT_00c273a4 = in_ECX;
  *(undefined4 *)(in_ECX + 0x10) = 1;
  iVar10 = 0;
  uVar9 = param_2;
  do {
    iVar1 = DAT_00c38db8;
    switch(iVar10) {
    case 0:
      if (*(char *)(in_ECX + 0x40) == '\0') {
        if (0x1a7a < DAT_00c38dbc) {
          iVar1 = DAT_00c38db8 + 0x13db8;
        }
      }
      else if (0x1a0e < DAT_00c38dbc) {
        iVar1 = DAT_00c38db8 + 0x138a8;
      }
      break;
    case 1:
      if (0x1a91 < DAT_00c38dbc) {
        iVar1 = DAT_00c38db8 + 0x13ecc;
      }
      break;
    case 2:
      if (0x1a50 < DAT_00c38dbc) {
        iVar1 = DAT_00c38db8 + 0x13bc0;
      }
      break;
    case 3:
      if (0x1aac < DAT_00c38dbc) {
        iVar1 = DAT_00c38db8 + 0x14010;
      }
      break;
    case 4:
      if (0x1a79 < DAT_00c38dbc) {
        iVar1 = DAT_00c38db8 + 0x13dac;
      }
      break;
    case 5:
      if (0x1a9e < DAT_00c38dbc) {
        iVar1 = DAT_00c38db8 + 0x13f68;
      }
      break;
    default:
      goto switchD_0053cd56_default;
    }
    uVar9 = *(uint *)(iVar1 + 8);
switchD_0053cd56_default:
    iVar1 = FUN_00746d70(0x254,s_C__dev_black_GameStatsFrontEnd_c_00b1c1e8,0xe9);
    if (iVar1 == 0) {
      uVar11 = 0;
    }
    else {
      iVar1 = __ftol();
      uVar7 = (uint)(iVar10 == 5);
      uVar8 = (uint)(iVar10 == 0);
      uVar2 = (uint)(iVar10 == *(int *)(in_ECX + 0x10));
      uVar11 = 0x28;
      uVar12 = uVar9;
      iVar3 = __ftol(0x28,uVar9,uVar2,uVar8,uVar7);
      uVar11 = FUN_0040d730(iVar10 + 0x8fc,iVar1,0x104 - (param_2 >> 1),iVar3 - iVar1,uVar11,uVar12,
                            uVar2,uVar8,uVar7);
    }
    *(undefined4 *)(in_ECX + 0x14 + iVar10 * 4) = uVar11;
    uVar11 = FUN_00405ee0();
    iVar1 = iVar10 * 4;
    iVar10 = iVar10 + 1;
    *(undefined4 *)(*(int *)(in_ECX + 0x14 + iVar1) + 0x20) = uVar11;
    if (5 < iVar10) {
      uVar11 = FUN_00405ed0();
      *(undefined4 *)(*(int *)(in_ECX + 4) + 0xac) = uVar11;
      puVar4 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_GameStatsFrontEnd_c_00b1c1e8,0xee);
      iVar10 = 0;
      if (puVar4 == (undefined4 *)0x0) {
        puVar4 = (undefined4 *)0x0;
      }
      else {
        iVar1 = DAT_00c38db8;
        if (0x1a5f < DAT_00c38dbc) {
          iVar1 = DAT_00c38db8 + 0x13c74;
        }
        FUN_00407730(1,0x28,0x3c,0x2d0,0x1c,*(undefined4 *)(iVar1 + 8));
        *puVar4 = &PTR_LAB_007ed4e8;
        puVar4[0x8f] = 1;
        *(undefined1 *)((int)puVar4 + 0x22a) = 0;
        puVar4[0x90] = 0;
      }
      *(undefined4 **)(in_ECX + 0x2c) = puVar4;
      iVar1 = FUN_00746d70(0x25c,s_C__dev_black_GameStatsFrontEnd_c_00b1c1e8,0xf3);
      if (iVar1 == 0) {
        uVar11 = 0;
      }
      else {
        iVar1 = DAT_00c38db8;
        if (0xd59 < DAT_00c38dbc) {
          iVar1 = DAT_00c38db8 + 0xa02c;
        }
        uVar11 = FUN_0040b4a0(999,0x14,0x212,*(undefined4 *)(iVar1 + 8),0x28,0,2);
      }
      *(undefined4 *)(in_ECX + 0x30) = uVar11;
      uVar11 = FUN_00405ed0();
      *(undefined4 *)(*(int *)(in_ECX + 0x30) + 0x20) = uVar11;
      puVar4 = (undefined4 *)(in_ECX + 0x58);
      do {
        puVar5 = (undefined4 *)FUN_00746d70(0x284,s_C__dev_black_GameStatsFrontEnd_c_00b1c1e8,0xf8);
        if (puVar5 == (undefined4 *)0x0) {
          puVar5 = (undefined4 *)0x0;
        }
        else {
          FUN_0040d090(0,0x15e,100,200,0x32,&DAT_00b6e5f0);
          *puVar5 = &PTR_LAB_0083dd3c;
        }
        *puVar4 = puVar5;
        if (-1 < iVar10) {
          iVar1 = iVar10 + 1;
          do {
            local_8[0] = -0x10000;
            local_8[1] = 0x3f800000;
            (**(code **)(*(int *)*puVar4 + 0x3c))(local_8);
            iVar1 = iVar1 + -1;
          } while (iVar1 != 0);
        }
        (**(code **)(*(int *)*puVar4 + 0x38))(0);
        (**(code **)(*(int *)*puVar4 + 8))(1);
        iVar10 = iVar10 + 1;
        puVar4 = puVar4 + 1;
      } while (iVar10 < 4);
      iVar10 = 0x28;
      puVar4 = (undefined4 *)(in_ECX + 0x44);
      do {
        iVar1 = FUN_00746d70(0x284,s_C__dev_black_GameStatsFrontEnd_c_00b1c1e8,0x101);
        if (iVar1 == 0) {
          piVar6 = (int *)0x0;
        }
        else {
          piVar6 = (int *)FUN_0040d090(0,iVar10,100,0xdc,0xe6,&DAT_00b6e5f0);
        }
        *puVar4 = piVar6;
        (**(code **)(*piVar6 + 0x38))(0);
        iVar10 = iVar10 + 0xfa;
        puVar4 = puVar4 + 1;
      } while (iVar10 < 0x316);
      iVar10 = FUN_00746d70(600,s_C__dev_black_GameStatsFrontEnd_c_00b1c1e8,0x105);
      if (iVar10 == 0) {
        uVar11 = 0;
      }
      else {
        iVar10 = DAT_00c38db8;
        if (0x1966 < DAT_00c38dbc) {
          iVar10 = DAT_00c38db8 + 0x130c8;
        }
        uVar11 = FUN_0040c6e0(0,0x28,100,0x1d6,100,*(undefined4 *)(iVar10 + 8),1);
      }
      *(undefined4 *)(in_ECX + 0x50) = uVar11;
      iVar10 = FUN_00746d70(600,s_C__dev_black_GameStatsFrontEnd_c_00b1c1e8,0x106);
      if (iVar10 == 0) {
        uVar11 = 0;
      }
      else {
        iVar10 = DAT_00c38db8;
        if (0x1967 < DAT_00c38dbc) {
          iVar10 = DAT_00c38db8 + 0x130d4;
        }
        uVar11 = FUN_0040c6e0(0,0x28,0xe6,0x1d6,100,*(undefined4 *)(iVar10 + 8),0);
      }
      *(undefined4 *)(in_ECX + 0x54) = uVar11;
      iVar10 = FUN_00746d70(0x2b0,s_C__dev_black_GameStatsFrontEnd_c_00b1c1e8,0x109);
      if (iVar10 == 0) {
        iVar10 = 0;
      }
      else {
        iVar10 = FUN_004087c0(999,0x28,0x16d,0x2d0,0x96);
      }
      *(int *)(in_ECX + 0x34) = iVar10;
      *(undefined1 *)(iVar10 + 0x23c) = 1;
      uVar11 = FUN_00405ee0();
      *(undefined4 *)(*(int *)(in_ECX + 0x34) + 0x20) = uVar11;
      iVar10 = FUN_00746d70(0x260,s_C__dev_black_GameStatsFrontEnd_c_00b1c1e8,0x10c);
      if (iVar10 == 0) {
        uVar11 = 0;
      }
      else {
        iVar10 = DAT_00c38db8;
        if (0x1968 < DAT_00c38dbc) {
          iVar10 = DAT_00c38db8 + 0x130e0;
        }
        uVar11 = FUN_0040ef70(999,0x122,0x212,1,1,*(undefined4 *)(iVar10 + 8),0x14);
      }
      *(undefined4 *)(in_ECX + 0x38) = uVar11;
      iVar10 = FUN_00746d70(0x260,s_C__dev_black_GameStatsFrontEnd_c_00b1c1e8,0x10d);
      if (iVar10 == 0) {
        iVar10 = 0;
      }
      else {
        iVar10 = DAT_00c38db8;
        if (0x1969 < DAT_00c38dbc) {
          iVar10 = DAT_00c38db8 + 0x130ec;
        }
        iVar10 = FUN_0040ef70(999,0x1ea,0x212,1,0,*(undefined4 *)(iVar10 + 8),0x14);
      }
      *(int *)(in_ECX + 0x3c) = iVar10;
      *(undefined4 *)(iVar10 + 0x244) = 1;
      *(undefined4 *)(*(int *)(in_ECX + 0x38) + 0x244) = 0;
      return;
    }
  } while( true );
}



// ?Destroy@StatsBox@@UAEXXZ @ 0x0053d2d0

void _Destroy_StatsBox__UAEXXZ(void)

{
  _Destroy__13DialogBoxBaseFv();
  DAT_00c273a4 = 0;
  return;
}



// ?InitControls@StatsBox@@UAEXXZ @ 0x0053d2e0

void _InitControls_StatsBox__UAEXXZ(void)

{
  undefined4 uVar1;
  int iVar2;
  int in_ECX;
  
  uVar1 = FUN_00536220();
  *(undefined4 *)(in_ECX + 0x6c) = uVar1;
  *(undefined4 *)(in_ECX + 0x10) = 1;
  FUN_0053cbe0(1);
  iVar2 = DAT_00c38db8;
  if (*(char *)(in_ECX + 0x40) == '\0') {
    if (0x1a7a < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0x13db8;
    }
  }
  else if (0x1a0e < DAT_00c38dbc) {
    iVar2 = DAT_00c38db8 + 0x138a8;
  }
  FUN_00733ff8(*(int *)(in_ECX + 0x14) + 0x24,*(undefined4 *)(iVar2 + 8));
  return;
}



