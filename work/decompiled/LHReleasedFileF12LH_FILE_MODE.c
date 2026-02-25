// Decompiled functions for class: LHReleasedFileF12LH_FILE_MODE
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// _Open__14LHReleasedFileF12LH_FILE_MODE @ 0x0072cbc0

undefined4 _Open__14LHReleasedFileF12LH_FILE_MODE(int param_1)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  int in_ECX;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  char local_100 [256];
  
  iVar2 = _Open__6LHFileF12LH_FILE_MODE(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  if (param_1 != 2) {
    return 2;
  }
  FUN_00733e17(local_100,s__c___s_008f9c88,(int)DAT_00b4dee8,*(undefined4 *)(in_ECX + 0x68));
  uVar4 = 0xffffffff;
  pcVar6 = local_100;
  do {
    pcVar7 = pcVar6;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar7 = pcVar6 + 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar7;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  pcVar6 = pcVar7 + -uVar4;
  pcVar7 = *(char **)(in_ECX + 0x68);
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar7 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar3 = _Open__6LHFileF12LH_FILE_MODE(2);
  return uVar3;
}



