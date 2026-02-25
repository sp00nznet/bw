// Decompiled functions for class: TownArtifact
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetPlayer@TownArtifact@@UAEPAVGPlayer@@XZ @ 0x0041ffc0

undefined4 _GetPlayer_TownArtifact__UAEPAVGPlayer__XZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x24);
}



// ?SetPlayer@TownArtifact@@UAEXPAVGPlayer@@@Z @ 0x0041ffd0

void _SetPlayer_TownArtifact__UAEXPAVGPlayer___Z(undefined4 param_1)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0x24) = param_1;
  return;
}



// ?GetTown@TownArtifact@@UAEPAVTown@@XZ @ 0x0041ffe0

undefined4 _GetTown_TownArtifact__UAEPAVTown__XZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0x18);
}



// ?GetSaveType@TownArtifact@@UAEIXZ @ 0x0041fff0

undefined4 _GetSaveType_TownArtifact__UAEIXZ(void)

{
  return 0x103;
}



// ?ToBeDeleted@TownArtifact@@UAEXH@Z @ 0x004200f0

void _ToBeDeleted_TownArtifact__UAEXH_Z(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int in_ECX;
  
  FUN_004204b0();
  if (*(int **)(in_ECX + 0x2c) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x2c) + 0xc))(param_1);
    *(undefined4 *)(in_ECX + 0x2c) = 0;
  }
  if (*(int **)(in_ECX + 0x38) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0x38) + 0xc))(0);
    *(undefined4 *)(in_ECX + 0x38) = 0;
  }
  iVar5 = DAT_00c22ca4;
  piVar1 = (int *)(DAT_00c22ca4 + 0x201de0);
  piVar6 = (int *)0x0;
  piVar2 = *(int **)(DAT_00c22ca4 + 0x201de0);
  while (piVar4 = piVar2, piVar3 = piVar6, piVar4 != (int *)0x0) {
    piVar2 = (int *)*piVar4;
    piVar6 = piVar4;
    if (piVar4[1] == in_ECX) {
      if (piVar4 == (int *)*piVar1) {
        *piVar1 = (int)piVar2;
      }
      else {
        *piVar3 = (int)piVar2;
      }
      *(int *)(iVar5 + 0x201de4) = *(int *)(iVar5 + 0x201de4) + -1;
      FUN_007290de(piVar4);
      piVar6 = piVar3;
    }
  }
  _ToBeDeleted_GameThing__UAEXH_Z(param_1);
  return;
}



// ?GetVillagerActivityDesire@TownArtifact@@UAEMPAVVillager@@@Z @ 0x00420550

float10 _GetVillagerActivityDesire_TownArtifact__UAEMPAVVillager___Z(int param_1)

{
  int iVar1;
  uint uVar2;
  int in_ECX;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  undefined4 *puVar6;
  undefined4 auStack_c [3];
  
  if (*(int *)(in_ECX + 0x30) == 0) {
    puVar6 = auStack_c;
    (**(code **)(**(int **)(in_ECX + 0x14) + 0x170))(puVar6,param_1 + 0x14);
    fVar3 = (float10)FUN_005c18d0(puVar6);
    fVar3 = (float10)FUN_006df670((float)fVar3,0x437a0000);
    fVar4 = (float10)FUN_00420650();
    iVar1 = *(int *)(in_ECX + 0x2c);
    fVar5 = (float10)1.0;
    if (((iVar1 != 0) && (*(int *)(iVar1 + 0x100) != 1)) &&
       (iVar1 = *(int *)(iVar1 + 0x104), iVar1 != 0)) {
      uVar2 = FUN_004ea820();
      auStack_c[0] = 0;
      if ((float)uVar2 / (float)iVar1 <= 1.0) {
        fVar5 = (float10)1.0;
      }
      else {
        iVar1 = *(int *)(*(int *)(in_ECX + 0x2c) + 0x104);
        uVar2 = FUN_004ea820();
        fVar5 = (float10)uVar2 / (float10)iVar1;
      }
      fVar5 = (float10)1.0 - ((float10)1.0 - fVar5);
    }
    return fVar5 * (float10)(float)fVar4 * (float10)(float)fVar3;
  }
  return (float10)0.0;
}



// ?SetVillagerActivity@TownArtifact@@UAEIPAVVillager@@@Z @ 0x004206f0

undefined4 _SetVillagerActivity_TownArtifact__UAEIPAVVillager___Z(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int in_ECX;
  int *unaff_retaddr;
  int *piVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined1 auStack_c [12];
  
  iVar1 = FUN_004eae00();
  if (iVar1 != -1) {
    if (*(int *)(in_ECX + 0x2c) != 0) goto LAB_00420774;
    iVar2 = FUN_004300a0(300,s_C__dev_black_Artifact_cpp_008f8478,0x134);
    if (iVar2 == 0) {
      uVar4 = 0;
    }
    else {
      uVar4 = *(undefined4 *)(in_ECX + 0x18);
      piVar6 = *(int **)(in_ECX + 0x14);
      uVar7 = *(undefined4 *)(&DAT_00be5ef0 + iVar1 * 0xb0);
      uVar8 = 0;
      puVar5 = &DAT_00be5ee0 + iVar1 * 0x2c;
      uVar3 = (**(code **)(*piVar6 + 0x170))(auStack_c,puVar5,piVar6,uVar7,0,uVar4);
      uVar4 = FUN_004e9dc0(uVar3,puVar5,piVar6,uVar7,uVar8,uVar4);
    }
    *(undefined4 *)(in_ECX + 0x2c) = uVar4;
  }
  if (*(int *)(in_ECX + 0x2c) == 0) {
    return 0;
  }
LAB_00420774:
  uVar4 = (**(code **)(**(int **)(in_ECX + 0x14) + 0x170))(auStack_c);
  iVar1 = FUN_005c1430(uVar4);
  if (iVar1 != 0) {
    puVar5 = (undefined4 *)(**(code **)(**(int **)(in_ECX + 0x14) + 0x170))(&stack0xfffffff0);
    iVar1 = *(int *)(in_ECX + 0x2c);
    *(undefined4 *)(iVar1 + 0x14) = *puVar5;
    *(undefined4 *)(iVar1 + 0x18) = puVar5[1];
    *(undefined4 *)(iVar1 + 0x1c) = puVar5[2];
    iVar1 = FUN_005beec0(0x7f7fffff);
    if ((iVar1 != 0) && (iVar1 = FUN_006ce860(), iVar1 != 0)) {
      FUN_0050a7c0(iVar1,*(undefined4 *)(in_ECX + 0x2c));
    }
  }
  iVar1 = FUN_0055e370(unaff_retaddr);
  if (iVar1 == 0) {
    return 0;
  }
  (**(code **)(*unaff_retaddr + 0x8e4))(0xfd);
  return 1;
}



// ?Save@TownArtifact@@UAEIAAVGameOSFile@@@Z @ 0x00420820

undefined4 _Save_TownArtifact__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_0053e8e0(param_1);
  if (iVar1 != 0) {
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x14));
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x18));
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x24));
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x28),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x28) + 4;
    }
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x2c));
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x38));
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x30),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x30) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90((byte *)(in_ECX + 0x34),4,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x34) + 4;
      }
    }
    return 1;
  }
  return 0;
}



// ?Load@TownArtifact@@UAEIAAVGameOSFile@@@Z @ 0x00420940

undefined4 _Load_TownArtifact__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = FUN_0053e9f0(param_1);
  if (iVar1 != 0) {
    FUN_00531f30(in_ECX + 0x14);
    FUN_00531f30(in_ECX + 0x18);
    FUN_00531f30(in_ECX + 0x24);
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x28),4,0,unaff_EBX,unaff_EDI,unaff_ESI);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x28) + 4;
    }
    FUN_00531f30();
    FUN_00531f30();
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x30) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x34) + 4;
    }
    return 1;
  }
  return 0;
}



