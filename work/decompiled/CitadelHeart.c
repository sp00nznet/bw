// Decompiled functions for class: CitadelHeart
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?ToBeDeleted@CitadelHeart@@UAEXH@Z @ 0x004500b0

void _ToBeDeleted_CitadelHeart__UAEXH_Z(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  int *in_ECX;
  int iVar3;
  
  if (in_ECX[0x37] != 0) {
    iVar3 = 0x58;
    do {
      if (*(int **)(iVar3 + in_ECX[0x37]) != (int *)0x0) {
        (**(code **)(**(int **)(iVar3 + in_ECX[0x37]) + 4))();
        *(undefined4 *)(iVar3 + in_ECX[0x37]) = 0;
      }
      if (*(int *)(iVar3 + 8 + in_ECX[0x37]) != 0) {
        FUN_0077d1a0();
        *(undefined4 *)(iVar3 + 8 + in_ECX[0x37]) = 0;
      }
      iVar3 = iVar3 + 4;
    } while (iVar3 < 0x60);
    if (*(int **)(in_ECX[0x37] + 0x40) != (int *)0x0) {
      (**(code **)(**(int **)(in_ECX[0x37] + 0x40) + 4))();
      *(undefined4 *)(in_ECX[0x37] + 0x40) = 0;
    }
    (**(code **)(*(int *)in_ECX[0x37] + 0xc))(param_1);
  }
  if (in_ECX[0x38] != 0) {
    FUN_00442050(in_ECX[0x38]);
    in_ECX[0x38] = 0;
  }
  iVar3 = (**(code **)(*in_ECX + 0x114))();
  if ((iVar3 != 0) && (iVar3 = (**(code **)(*in_ECX + 0x114))(), *(int **)(iVar3 + 0x30) == in_ECX))
  {
    iVar3 = (**(code **)(*in_ECX + 0x114))();
    *(undefined4 *)(iVar3 + 0x30) = 0;
  }
  piVar2 = (int *)0x0;
  for (piVar1 = DAT_00b7fc5c; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[0x36]) {
    if (piVar1 == in_ECX) goto LAB_0045019a;
    piVar2 = piVar1;
  }
  if (in_ECX == (int *)0x0) {
LAB_0045019a:
    if (piVar2 == (int *)0x0) {
      DAT_00b7fc5c = (int *)piVar1[0x36];
    }
    else {
      piVar2[0x36] = piVar1[0x36];
    }
  }
  FUN_004505f0();
  _ToBeDeleted_CitadelPart__UAEXH_Z(param_1);
  iVar3 = (**(code **)(*in_ECX + 0x114))();
  if ((iVar3 != 0) && (iVar3 = (**(code **)(*in_ECX + 0x114))(), (*(byte *)(iVar3 + 10) & 1) == 0))
  {
    piVar2 = (int *)(**(code **)(*in_ECX + 0x114))();
    (**(code **)(*piVar2 + 0xc))(0);
  }
  return;
}



// ?GetSaveType@CitadelHeart@@UAEIXZ @ 0x00450940

undefined4 _GetSaveType_CitadelHeart__UAEIXZ(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _GetSaveType_CitadelPart__UAEIXZ(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x8c),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x8c) + 4;
    }
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x94));
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x98));
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0xa0),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xa0) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90((byte *)(in_ECX + 0xa4),4,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xa4) + 4;
        if (DAT_00b19ac8 != 0) {
          iVar1 = FUN_0072be90((byte *)(in_ECX + 0xb8),1,0);
          if (iVar1 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xb8) + 1;
          if (DAT_00b19ac8 != 0) {
            iVar1 = FUN_0072be90((byte *)(in_ECX + 0xbc),4,0);
            if (iVar1 == 3) {
              DAT_00b19ac8 = 0;
            }
            *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xbc) + 4;
          }
        }
      }
    }
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0xc0));
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0xcc));
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0xd0),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xd0) + 4;
    }
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0xac));
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0xb0));
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0xb4),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xb4) + 4;
    }
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0xdc));
    return 1;
  }
  return 0;
}



// ?Save@CitadelHeart@@UAEIAAVGameOSFile@@@Z @ 0x00450b70

undefined4 _Save_CitadelHeart__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Save_CitadelPart__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x8c),4,0,unaff_EBP,unaff_EBX,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x8c) + 4;
    }
    FUN_00531f30();
    FUN_00531f30();
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xa0) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xa4) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xb8) + 1;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xbc) + 4;
    }
    FUN_00531f30();
    FUN_00531f30();
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xd0) + 4;
    }
    FUN_00531f30();
    FUN_00531f30();
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xb4) + 4;
    }
    FUN_00531f30();
    return 1;
  }
  return 0;
}



// ?ReactToPhysicsImpact@CitadelHeart@@UAEXPAVPhysicsObject@@_N@Z @ 0x00452e50

undefined4 _ReactToPhysicsImpact_CitadelHeart__UAEXPAVPhysicsObject___N_Z(void)

{
  int *in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)(**(code **)(*in_ECX + 0x880))();
  if ((float10)0.1 < fVar1) {
    return 1;
  }
  return 0;
}



// ?InteractsWithPhysicsObjects@CitadelHeart@@UAE_NXZ @ 0x00452e70

void _InteractsWithPhysicsObjects_CitadelHeart__UAE_NXZ(void)

{
  int iVar1;
  int *in_ECX;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = (**(code **)(*in_ECX + 0x788))(0);
  FUN_00759e40(0x461c4000,&DAT_00be7740 + iVar1 * 6,uVar2);
  FUN_0075a0f0();
  return;
}



// ?GetPlayer@CitadelHeart@@UAEPAVGPlayer@@XZ @ 0x00453290

undefined4 _GetPlayer_CitadelHeart__UAEPAVGPlayer__XZ(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x80) != 0) {
    uVar1 = _GetPlayer_CitadelPart__UAEPAVGPlayer__XZ();
    return uVar1;
  }
  if (*(int **)(in_ECX + 0x94) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x004532ab. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(**(int **)(in_ECX + 0x94) + 0x1c))();
    return uVar1;
  }
  return 0;
}



