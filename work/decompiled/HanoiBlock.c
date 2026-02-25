// Decompiled functions for class: HanoiBlock
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?CanBecomeAPhysicsObject@HanoiBlock@@UAE_NXZ @ 0x00531750

bool _CanBecomeAPhysicsObject_HanoiBlock__UAE_NXZ(void)

{
  int in_ECX;
  
  if (*(int *)(*(int *)(in_ECX + 0x28) + 0x104) != 0x1a) {
    return *(int *)(in_ECX + 0x78) == 0;
  }
  return false;
}



// ?GetSaveType@HanoiBlock@@UAEIXZ @ 0x00531770

undefined4 _GetSaveType_HanoiBlock__UAEIXZ(void)

{
  return 0x30;
}



// ?GetDebugText@HanoiBlock@@UAEPADXZ @ 0x00531780

char * _GetDebugText_HanoiBlock__UAEPADXZ(void)

{
  return s_Hanoi_block__00b1b378;
}



// ?Load@HanoiBlock@@UAEIAAVGameOSFile@@@Z @ 0x00679c10

undefined4 _Load_HanoiBlock__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Load_MobileObject__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x68),0xc,0,unaff_EDI,unaff_ESI,unaff_EBX);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x68) + 0xc;
    }
    FUN_00531f30();
    FUN_00531f30();
    FUN_00531f30();
    return 1;
  }
  return 0;
}



// ?Save@HanoiBlock@@UAEIAAVGameOSFile@@@Z @ 0x00679ca0

undefined4 _Save_HanoiBlock__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_MobileObject__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x68),0xc,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x68) + 0xc;
    }
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x74));
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x78));
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x7c));
    return 1;
  }
  return 0;
}



// ?InterfaceSetInMagicHand@HanoiBlock@@UAEIPAVGInterfaceStatus@@@Z @ 0x0067bc00

undefined4 _InterfaceSetInMagicHand_HanoiBlock__UAEIPAVGInterfaceStatus___Z(void)

{
  int iVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x78) != 0) {
    *(undefined4 *)(*(int *)(in_ECX + 0x78) + 0x74) = 0;
  }
  *(undefined4 *)(in_ECX + 0x74) = 0;
  *(undefined4 *)(in_ECX + 0x78) = 0;
  if (*(int *)(*(int *)(in_ECX + 0x28) + 0x104) == 0x1b) {
    iVar1 = FUN_0067bcf0(8);
    FUN_006a8d90(iVar1 + 0x1493,0,0,0);
  }
  return 1;
}



// ?IsCannotBePickedUp@HanoiBlock@@UBE_NXZ @ 0x0067bc50

uint _IsCannotBePickedUp_HanoiBlock__UBE_NXZ(void)

{
  int in_ECX;
  
  if ((((*(int *)(*(int *)(in_ECX + 0x28) + 0x104) != 0x1a) && (*(int *)(in_ECX + 0x74) == 0)) &&
      (*(int *)(in_ECX + 0x7c) != 0)) && (4 < *(int *)(*(int *)(in_ECX + 0x7c) + 0x40c))) {
    return (*(ushort *)(in_ECX + 0x24) & 0x2000) >> 0xd;
  }
  return 1;
}



