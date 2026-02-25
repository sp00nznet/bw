// Decompiled functions for class: SpellResource
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetDebugText@SpellResource@@UAEPADXZ @ 0x0052e560

char * _GetDebugText_SpellResource__UAEPADXZ(void)

{
  return s_SpellFood__00b1a308;
}



// ?HasEnoughChantsAndLifeForRecast@SpellResource@@UAEXXZ @ 0x006bbb00

int _HasEnoughChantsAndLifeForRecast_SpellResource__UAEXXZ(void)

{
  float fVar1;
  float fVar2;
  int iVar3;
  int iVar4;
  uint3 uVar5;
  int in_ECX;
  
  fVar1 = *(float *)(in_ECX + 0x38);
  iVar3 = FUN_006c4230();
  iVar4 = FUN_006c4230();
  fVar2 = (float)(*(int *)(iVar3 + 0x68) * *(int *)(iVar4 + 0x60));
  uVar5 = (uint3)(CONCAT22((short)((uint)iVar4 >> 0x10),
                           (ushort)(fVar2 < fVar1) << 8 | (ushort)(NAN(fVar2) || NAN(fVar1)) << 10 |
                           (ushort)(fVar2 == fVar1) << 0xe) >> 8);
  if (fVar2 >= fVar1 && (fVar2 == fVar1) == 0) {
    return (uint)uVar5 << 8;
  }
  return CONCAT31(uVar5,1);
}



// ?SpellEvent@SpellResource@@UAEXABVSpellEventInfo@@@Z @ 0x006bbbf0

undefined4 _SpellEvent_SpellResource__UAEXABVSpellEventInfo___Z(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  float10 fVar4;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uVar1 = _SpellEvent_Spell__UAEXABVSpellEventInfo___Z(param_1);
  if (*param_1 != 1) {
    iVar2 = FUN_006c4230();
    uStack_c = __ftol();
    uStack_8 = __ftol();
    uStack_4 = 0;
    if (*(char *)(in_ECX + 0xec) == '\0') {
      iVar3 = *(int *)(iVar2 + 0x60);
    }
    else {
      iVar3 = *(int *)(iVar2 + 100);
    }
    FUN_006b7bd0((float)(uint)(*(int *)(iVar2 + 0x68) * iVar3),0);
    *(undefined1 *)(in_ECX + 0xec) = 1;
    iVar3 = FUN_005c04c0();
    if (iVar3 != 0) {
      iVar3 = FUN_005bfb70();
      if (iVar3 != 0) {
        fVar4 = (float10)FUN_006b79a0();
        if ((float10)0.0 < fVar4) {
          FUN_006b8870();
          __ftol();
          if (*(int *)(iVar2 + 0x5c) == 0) {
            FUN_006bbb50(&uStack_c);
            return uVar1;
          }
          FUN_006bbba0(&uStack_c);
        }
      }
    }
  }
  return uVar1;
}



// ?Load@SpellResource@@UAEIAAVGameOSFile@@@Z @ 0x006bc150

undefined4 _Load_SpellResource__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Load_Spell__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0xec),1,0,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xec) + 1;
    }
    return 1;
  }
  return 0;
}



// ?Save@SpellResource@@UAEIAAVGameOSFile@@@Z @ 0x006bc1b0

undefined4 _Save_SpellResource__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_Spell__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0xec),1,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xec) + 1;
    }
    return 1;
  }
  return 0;
}



