// Decompiled functions for class: GatheringBox
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?Init@GatheringBox@@UAEXIIP6AXHPAVSetupBox@@PAVSetupControl@@HH@Z@Z @ 0x0053f0e0

void _Init_GatheringBox__UAEXIIP6AXHPAVSetupBox__PAVSetupControl__HH_Z_Z
               (undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  int in_ECX;
  uint uVar8;
  uint uVar9;
  undefined2 *puVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  
  *(undefined1 *)(in_ECX + 0x45) = 0;
  *(undefined4 *)(in_ECX + 0x48) = 0;
  *(undefined1 *)(in_ECX + 0x4c) = 1;
  iVar1 = DAT_00c38db8;
  if (0x19da < DAT_00c38dbc) {
    iVar1 = DAT_00c38db8 + 0x13638;
  }
  DAT_00c27450 = *(undefined4 *)(iVar1 + 8);
  iVar1 = DAT_00c38db8;
  if (0x19dc < DAT_00c38dbc) {
    iVar1 = DAT_00c38db8 + 0x13650;
  }
  DAT_00c2744c = *(undefined4 *)(iVar1 + 8);
  iVar1 = DAT_00c38db8;
  if (0xdd7 < DAT_00c38dbc) {
    iVar1 = DAT_00c38db8 + 0xa614;
  }
  DAT_00c27448 = *(undefined4 *)(iVar1 + 8);
  iVar1 = DAT_00c38db8;
  if (0x1a7c < DAT_00c38dbc) {
    iVar1 = DAT_00c38db8 + 0x13dd0;
  }
  DAT_00c27444 = *(undefined4 *)(iVar1 + 8);
  iVar1 = DAT_00c38db8;
  if (0x1a7b < DAT_00c38dbc) {
    iVar1 = DAT_00c38db8 + 0x13dc4;
  }
  DAT_00c27440 = *(undefined4 *)(iVar1 + 8);
  _Init__13DialogBoxBaseFUlUlPFiP8SetupBoxP12SetupControlii_v(param_1,param_2,param_3);
  DAT_00c2756c = in_ECX;
  *(undefined1 *)(in_ECX + 0x10) = 0;
  uVar8 = DAT_00d5c108 >> 0x10;
  uVar9 = DAT_00d5c108 & 0xffff;
  iVar1 = FUN_0040ff40(0x14);
  uVar2 = FUN_0040ff40(0x30);
  *(undefined4 *)(*(int *)(in_ECX + 4) + 0x94) = 0;
  iVar3 = FUN_00746d70(0x25c,s_C__dev_black_GatheringInterface__00b1c234,0x55);
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    uVar12 = 6;
    uVar11 = 0;
    puVar10 = &DAT_00b6e5f0;
    iVar3 = iVar1;
    uVar4 = FUN_0040fe90(0,&DAT_00b6e5f0,iVar1,0,6);
    uVar5 = FUN_0040fd50(uVar9 - 0x14,uVar4);
    uVar4 = FUN_0040b4a0(1,uVar5,uVar4,puVar10,iVar3,uVar11,uVar12);
  }
  *(undefined4 *)(in_ECX + 0x24) = uVar4;
  iVar3 = FUN_00746d70(0x25c,s_C__dev_black_GatheringInterface__00b1c234,0x56);
  if (iVar3 == 0) {
    uVar4 = 0;
  }
  else {
    uVar12 = 8;
    uVar11 = 0;
    puVar10 = &DAT_00b6e5f0;
    iVar3 = iVar1;
    uVar4 = FUN_0040fe90(0,&DAT_00b6e5f0,iVar1,0,8);
    uVar5 = FUN_0040fd50(uVar9 / 2,uVar4);
    uVar4 = FUN_0040b4a0(2,uVar5,uVar4,puVar10,iVar3,uVar11,uVar12);
  }
  *(undefined4 *)(in_ECX + 0x28) = uVar4;
  puVar6 = (undefined4 *)FUN_00746d70(0x244,s_C__dev_black_GatheringInterface__00b1c234,0x58);
  if (puVar6 == (undefined4 *)0x0) {
    puVar6 = (undefined4 *)0x0;
  }
  else {
    uVar4 = FUN_0040ff40(0x14);
    uVar5 = FUN_0040ff40(uVar9 - 0x35);
    uVar11 = FUN_0040fe90(uVar8 - 0x22);
    uVar12 = FUN_0040fd50(0x30);
    FUN_00407730(1000,uVar12,uVar11,uVar5,uVar4,&DAT_00b6e5f0);
    puVar6[0x8f] = 0;
    *(undefined1 *)((int)puVar6 + 0x22a) = 0;
    puVar6[0x90] = 0;
    *puVar6 = &PTR_LAB_0083deac;
  }
  *(undefined4 **)(in_ECX + 0x20) = puVar6;
  puVar6[8] = 0x12;
  iVar3 = FUN_00746d70(0x25c,s_C__dev_black_GatheringInterface__00b1c234,0x5a);
  if (iVar3 == 0) {
    uVar2 = 0;
  }
  else {
    uVar12 = 5;
    uVar11 = 0;
    puVar10 = &DAT_00b6e5f0;
    uVar4 = FUN_0040fe90(uVar8 - 0x30,&DAT_00b6e5f0,uVar2,0,5);
    uVar5 = FUN_0040fd50(0,uVar4);
    uVar2 = FUN_0040b4a0(0xb,uVar5,uVar4,puVar10,uVar2,uVar11,uVar12);
  }
  *(undefined4 *)(in_ECX + 0x2c) = uVar2;
  iVar3 = FUN_00746d70(0x25c,s_C__dev_black_GatheringInterface__00b1c234,0x5b);
  if (iVar3 == 0) {
    uVar2 = 0;
  }
  else {
    uVar11 = 5;
    uVar5 = 0;
    puVar10 = &DAT_00b6e5f0;
    iVar3 = iVar1;
    uVar2 = FUN_0040fe90(0,&DAT_00b6e5f0,iVar1,0,5);
    uVar4 = FUN_0040fd50(uVar9 - 0x14,uVar2);
    uVar2 = FUN_0040b4a0(0xc,uVar4,uVar2,puVar10,iVar3,uVar5,uVar11);
  }
  *(undefined4 *)(in_ECX + 0x30) = uVar2;
  iVar3 = FUN_00746d70(0x244,s_C__dev_black_GatheringInterface__00b1c234,0x5d);
  if (iVar3 == 0) {
    uVar2 = 0;
  }
  else {
    uVar12 = 0;
    puVar10 = &DAT_00b6e5f0;
    uVar2 = FUN_0040ff40(0x14,&DAT_00b6e5f0,0);
    uVar4 = FUN_0040ff40(0x82,uVar2);
    uVar5 = FUN_0040fe90(0,uVar4);
    uVar11 = FUN_0040fd50(uVar9 - 0x82,uVar5);
    uVar2 = FUN_00407d30(6,uVar11,uVar5,uVar4,uVar2,puVar10,uVar12);
  }
  *(undefined4 *)(in_ECX + 0x34) = uVar2;
  iVar3 = FUN_00746d70(0x468,s_C__dev_black_GatheringInterface__00b1c234,0x60);
  if (iVar3 == 0) {
    uVar2 = 0;
  }
  else {
    uVar12 = 1;
    puVar10 = &DAT_00b6e5f0;
    uVar2 = FUN_0040ff40(0x14,&DAT_00b6e5f0,1);
    uVar4 = FUN_0040ff40(uVar9 / 2 - 0x28,uVar2);
    uVar5 = FUN_0040fe90(0,uVar4);
    uVar11 = FUN_0040fd50(uVar9 / 2 + 0x14,uVar5);
    uVar2 = FUN_0040a590(4,uVar11,uVar5,uVar4,uVar2,puVar10,uVar12);
  }
  *(undefined4 *)(in_ECX + 0x14) = uVar2;
  uVar2 = FUN_0040ff40(0x12);
  *(undefined4 *)(*(int *)(in_ECX + 0x14) + 0x20) = uVar2;
  *(undefined4 *)(*(int *)(in_ECX + 0x34) + 0x20) = *(undefined4 *)(*(int *)(in_ECX + 0x14) + 0x20);
  iVar3 = FUN_00746d70(0x2b0,s_C__dev_black_GatheringInterface__00b1c234,100);
  if (iVar3 == 0) {
    iVar3 = 0;
  }
  else {
    uVar2 = FUN_0040ff40(100);
    uVar4 = FUN_0040ff40(0x82,uVar2);
    uVar5 = FUN_0040fe90(0x14,uVar4);
    uVar11 = FUN_0040fd50(uVar9 - 0x82,uVar5);
    iVar3 = FUN_004087c0(5,uVar11,uVar5,uVar4,uVar2);
  }
  *(int *)(in_ECX + 0x18) = iVar3;
  *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(*(int *)(in_ECX + 0x14) + 0x20);
  *(int *)(*(int *)(in_ECX + 0x18) + 0x240) = iVar1 + -2;
  *(undefined1 *)(*(int *)(in_ECX + 0x18) + 0x291) = 0;
  *(undefined4 **)(in_ECX + 0x38) = &DAT_00c27438;
  iVar7 = (DAT_00d5c108 & 0xffff) - 0x32;
  iVar3 = 0x208;
  if (iVar7 < 0x209) {
    iVar3 = iVar7;
  }
  iVar7 = FUN_00746d70(0x2b0,s_C__dev_black_GatheringInterface__00b1c234,0x6b);
  if (iVar7 == 0) {
    iVar3 = 0;
  }
  else {
    uVar2 = FUN_0040ff40(DAT_00d5c108 >> 0x11);
    uVar4 = FUN_0040ff40(iVar3,uVar2);
    uVar5 = FUN_0040fe90(0x14,uVar4);
    uVar11 = FUN_0040fd50(uVar9 - iVar3,uVar5);
    iVar3 = FUN_004087c0(5,uVar11,uVar5,uVar4,uVar2);
  }
  *(int *)(in_ECX + 0x1c) = iVar3;
  *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(*(int *)(in_ECX + 0x14) + 0x20);
  *(int *)(*(int *)(in_ECX + 0x1c) + 0x240) = iVar1 + -2;
  *(undefined1 *)(*(int *)(in_ECX + 0x1c) + 0x290) = 0;
  iVar1 = 0x642c;
  uVar8 = 0x859;
  do {
    iVar3 = DAT_00c38db8;
    if ((uVar8 < DAT_00c38dbc) && (uVar8 != 0)) {
      iVar3 = DAT_00c38db8 + iVar1;
    }
    iVar7 = *(int *)(in_ECX + 0x1c);
    FUN_004091e0(*(undefined4 *)(iVar7 + 0x250),*(undefined4 *)(iVar3 + 8));
    iVar3 = *(int *)(iVar7 + 0x250) + -1;
    if ((-1 < iVar3) && (iVar3 < *(int *)(iVar7 + 0x250))) {
      *(undefined4 *)(*(int *)(iVar7 + 0x268) + iVar3 * 4) = 0;
    }
    iVar1 = iVar1 + 0xc;
    iVar3 = uVar8 - 0x858;
    uVar8 = uVar8 + 1;
  } while (iVar3 < 0x1f);
  (**(code **)(**(int **)(in_ECX + 0x1c) + 8))(1);
  return;
}



// ?Destroy@GatheringBox@@UAEXXZ @ 0x0053fbd0

void _Destroy_GatheringBox__UAEXXZ(void)

{
  _Destroy__13DialogBoxBaseFv();
  DAT_00c2756c = 0;
  return;
}



