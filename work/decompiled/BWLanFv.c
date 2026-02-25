// Decompiled functions for class: BWLanFv
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// _Connect__5BWLanFv @ 0x00438aa0

undefined4 _Connect__5BWLanFv(void)

{
  code *pcVar1;
  char cVar2;
  LH_RETURN LVar3;
  int *in_ECX;
  LH_USER_ID *this;
  int iVar4;
  code **ppcVar5;
  undefined8 uVar6;
  char acStack_d3c [128];
  code *apcStack_cbc [783];
  LH_USER_ID aLStack_80 [128];
  
  DAT_00c61560 = 0xffffffff;
  LHSocket::Startup();
  gethostname(acStack_d3c,0x80);
  LHSocket::Startup();
  FUN_005a98b0();
  LVar3 = LHNetUser::Login((LHNetUser *)DAT_00c415e4,acStack_d3c,(char *)0x0);
  if (LVar3 != 0) {
    DAT_00b7b2a8 = 0;
    return 0;
  }
  FUN_005aa620();
  uVar6 = thunk_EXT_FUN_035e5331();
  DAT_00c6168c = (undefined4)((ulonglong)uVar6 >> 0x20);
  DAT_00c61688 = (undefined4)uVar6;
  uVar6 = FUN_005e0310();
  DAT_00c61694 = (undefined4)((ulonglong)uVar6 >> 0x20);
  DAT_00c61690 = (undefined4)uVar6;
  FUN_00733ff8(&DAT_00c61564,DAT_00c415e4 + 0xc);
  DAT_00c61560 = *(undefined4 *)DAT_00c415e4;
  this = aLStack_80;
  iVar4 = 0x20;
  do {
    LH_USER_ID::LH_USER_ID(this);
    pcVar1 = LH_LIONHEAD_DEFAULT_LISTNER_ADDRESS_exref;
    this = this + 4;
    iVar4 = iVar4 + -1;
  } while (iVar4 != 0);
  ppcVar5 = apcStack_cbc;
  for (iVar4 = 0x32f; iVar4 != 0; iVar4 = iVar4 + -1) {
    *ppcVar5 = (code *)0x0;
    ppcVar5 = ppcVar5 + 1;
  }
  apcStack_cbc[1] = LH_LIONHEAD_DEFAULT_LISTNER_ADDRESS_exref;
  apcStack_cbc[0] = DAT_00c415e4;
  if (&stack0x00000000 != (undefined1 *)0xd40) {
    *(undefined4 *)(LH_LIONHEAD_DEFAULT_LISTNER_ADDRESS_exref + 4) = 5;
    *(undefined4 *)(pcVar1 + 8) = 2;
    *(undefined2 *)(pcVar1 + 0xc) = 0xa35;
  }
  LVar3 = LHLobby::OpenLocalLobby(DAT_00c415b8,(LHMPServerStartInfo *)apcStack_cbc);
  if (LVar3 != 0) {
    DAT_00b7b2a8 = 0;
    return 0;
  }
  cVar2 = (**(code **)(*in_ECX + 0x1c))();
  if (cVar2 != '\0') {
    DAT_00b7b2a8 = 1;
  }
  return 1;
}



