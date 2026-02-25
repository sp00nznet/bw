// Decompiled functions for class: BWLan
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?SendMessageA@BWLan@@UAEXPBD_NPAUMPFEPlayerDetails@@@Z @ 0x00438830

void _SendMessageA_BWLan__UAEXPBD_NPAUMPFEPlayerDetails___Z
               (undefined4 param_1,undefined4 param_2,char param_3,int param_4)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  LHSPrintf *extraout_ECX;
  LHSPrintf *extraout_ECX_00;
  LHSPrintf *this;
  undefined4 extraout_ECX_01;
  uint uVar4;
  char *pcVar5;
  undefined4 uStack_410;
  char acStack_404 [1028];
  
  uStack_410 = param_1;
  iVar2 = FUN_0055f930();
  uStack_410 = param_1;
  if (iVar2 == 0) {
    uStack_410 = FUN_0050f5e0();
    this = extraout_ECX_00;
  }
  else {
    uStack_410 = FUN_0055f9e0();
    this = extraout_ECX;
  }
  pcVar3 = (char *)LHSPrintf::LHSPrintf(this,acStack_404);
  if (param_3 == '\0') {
    uStack_410 = extraout_ECX_01;
    LH_USER_ID::LH_USER_ID((LH_USER_ID *)&uStack_410,0);
  }
  else {
    if (param_4 == 0) {
      return;
    }
    uStack_410 = *(undefined4 *)(param_4 + 0x120);
  }
  uVar4 = 0xffffffff;
  pcVar5 = pcVar3;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  LHLobbyChannel::ChatOnChannel(DAT_00c415d8,pcVar3,~uVar4);
  return;
}



// ?SendMessageW@BWLan@@UAEXPA_W_NPAUMPFEPlayerDetails@@@Z @ 0x004388d0

void _SendMessageW_BWLan__UAEXPA_W_NPAUMPFEPlayerDetails___Z(char *param_1,char param_2,int param_3)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  if (param_2 == '\0') {
    uStack_8 = 0;
    LH_USER_ID::LH_USER_ID((LH_USER_ID *)&uStack_c,0);
  }
  else {
    if (param_3 == 0) {
      return;
    }
    uStack_c = *(undefined4 *)(param_3 + 0x120);
    uStack_8 = 0;
  }
  uVar2 = 0xffffffff;
  pcVar3 = param_1;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  LHLobbyChannel::ChatOnChannel(DAT_00c415d8,param_1,~uVar2);
  return;
}



// ?LeaveGameChannel@BWLan@@UAEXXZ @ 0x00438920

void _LeaveGameChannel_BWLan__UAEXXZ(void)

{
  LHChannel *pLVar1;
  int iVar2;
  
  FUN_005d86e0();
  if (DAT_00c415d8 != 0) {
    if (DAT_00c415c0[1] == 0) {
      if (*(int *)(DAT_00c415b8 + 4) == 0) {
        return;
      }
      LHLobby::BootOtherUsersOffChannel
                ((LHLobby *)DAT_00c415b8,*(char **)LH_CHANNEL_DEFAULT_NAME_exref);
      iVar2 = DAT_00c60984;
      DAT_00c614ee = 0;
      if (DAT_00c60984 != 0) {
        _Draw_PlannedMultiMapFixed__QAEXXZ();
        FUN_007290de(iVar2);
      }
      DAT_00c60984 = 0;
    }
    else {
      pLVar1 = LHChannel::FindChannel
                         (*(char **)LH_CHANNEL_DEFAULT_NAME_exref,
                          (LHLinkedList<class_LHChannel*> *)(DAT_00c415c0 + 0x25));
      LHLobby::LeaveChannel((LHLobby *)DAT_00c415c0,(LHLobbyChannel *)pLVar1);
      DAT_00c415d8 = 0;
      (**(code **)(*DAT_00c415c0 + 8))();
    }
  }
  iVar2 = FUN_004f02b0();
  if (iVar2 == 0) {
    return;
  }
  FUN_004f0180();
  return;
}



// ?BeginPlayerEnumeration@BWLan@@UAEXXZ @ 0x004389e0

void _BeginPlayerEnumeration_BWLan__UAEXXZ(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  LHSPrintf *extraout_ECX;
  LHSPrintf *extraout_ECX_00;
  LHSPrintf *this;
  int iVar5;
  int aiStack_404 [257];
  
  puVar1 = (undefined4 *)(DAT_00c415d8 + 0x70);
  FUN_004ecf10();
  iVar5 = 0;
  for (puVar1 = (undefined4 *)*puVar1; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)*puVar1)
  {
    iVar3 = FUN_0055f930(puVar1[1] + 0x110);
    if (iVar3 == 0) {
      FUN_0050f5e0(puVar1[1] + 0x110);
      this = extraout_ECX_00;
    }
    else {
      FUN_0055f9e0(puVar1[1] + 0x110);
      this = extraout_ECX;
    }
    iVar3 = puVar1[1];
    uVar2 = *(undefined4 *)(iVar3 + 0x178);
    uVar4 = LHSPrintf::LHSPrintf(this,(char *)aiStack_404);
    FUN_005da7d0(uVar4,iVar3 == aiStack_404[0],uVar2);
    iVar5 = iVar5 + 1;
  }
  FUN_005da6d0(iVar5);
  return;
}



// ?PopulateChannelPlayers@BWLan@@UAEXPAUMPFEChannelDetails@@@Z @ 0x00439450

void _PopulateChannelPlayers_BWLan__UAEXPAUMPFEChannelDetails___Z(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *(int *)(param_1 + 0x4a0);
  param_1 = 1;
  LHLobby::GetNextLocalLobby((LHLocalLobbyInfo *)0x0);
  puVar2 = *(undefined4 **)(iVar1 + 0x138);
  while (puVar2 != (undefined4 *)0x0) {
    FUN_005dcd80(puVar2[1] + 0x110,param_1);
    puVar2 = (undefined4 *)*puVar2;
    param_1 = 0;
  }
  return;
}



// ?CreateOrJoinRoom@BWLan@@UAEXPA_W0PAUMPFEChannelDetails@@@Z @ 0x004394a0

void _CreateOrJoinRoom_BWLan__UAEXPA_W0PAUMPFEChannelDetails___Z
               (undefined4 param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  int iVar2;
  
  FUN_006cb0a0(param_1);
  FUN_006cb0a0(param_2);
  if ((param_3 == 0) || (DAT_00c614ee != '\0')) goto LAB_00439535;
  if (*(char *)(param_3 + 0x499) == '\0') {
LAB_0043951f:
    cVar1 = FUN_00439370(0,param_1);
    if (cVar1 != '\0') goto LAB_00439535;
  }
  else {
    iVar2 = FUN_007343d2(param_2);
    if (iVar2 != 0) goto LAB_0043951f;
    iVar2 = DAT_00c38db8;
    if (0xdb6 < DAT_00c38dbc) {
      iVar2 = DAT_00c38db8 + 0xa488;
    }
    FUN_0040f1d0(*(undefined4 *)(iVar2 + 8),0,0);
    DAT_00c60984 = 0;
  }
  DAT_00c614ee = '\0';
LAB_00439535:
  FUN_006cb190();
  FUN_006cb190();
  return;
}



// ?LeaveMainRoom@BWLan@@UAEXXZ @ 0x005c32d0

void _LeaveMainRoom_BWLan__UAEXXZ(void)

{
  int *in_ECX;
  
                    /* WARNING: Could not recover jumptable at 0x005c32d2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(*in_ECX + 0x2c))();
  return;
}



