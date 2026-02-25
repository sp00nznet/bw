// Decompiled functions for class: WorshipSite
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?RemoveDance@WorshipSite@@UAEXXZ @ 0x0052ed20

void _RemoveDance_WorshipSite__UAEXXZ(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xa0) = 0;
  return;
}



// ?ToBeDeleted@WorshipSite@@UAEXH@Z @ 0x00703bc0

void _ToBeDeleted_WorshipSite__UAEXH_Z(undefined4 param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *in_ECX;
  undefined4 unaff_retaddr;
  int *piVar5;
  
  while ((int *)in_ECX[0x38] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x38] + 0xc))(param_1);
  }
  if ((int *)in_ECX[0x28] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x28] + 0xc))(param_1);
  }
  if ((int *)in_ECX[0x24] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x24] + 0xc))(param_1);
  }
  if (((int *)in_ECX[0x37] != (int *)0x0) &&
     (iVar4 = (**(code **)(*(int *)in_ECX[0x37] + 0x2c))(), iVar4 != 0)) {
    *(undefined4 *)(in_ECX[0x37] + 0x100) = 0;
    (**(code **)(*(int *)in_ECX[0x37] + 0xc))(param_1);
  }
  for (puVar1 = (undefined4 *)in_ECX[0x29]; puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    *(undefined4 *)(puVar1[1] + 0x984) = 0;
  }
  iVar4 = (**(code **)(*in_ECX + 0x114))();
  if (iVar4 != 0) {
    piVar5 = in_ECX;
    (**(code **)(*in_ECX + 0x114))();
    FUN_0044ee50(piVar5);
  }
  while (piVar5 = (int *)in_ECX[0x29], piVar5 != (int *)0x0) {
    iVar4 = piVar5[1];
    piVar3 = (int *)0x0;
    while (piVar2 = piVar3, piVar3 = piVar5, piVar3 != (int *)0x0) {
      piVar5 = (int *)*piVar3;
      if (piVar3[1] == iVar4) {
        if (piVar3 == (int *)in_ECX[0x29]) {
          in_ECX[0x29] = (int)piVar5;
        }
        else {
          *piVar2 = (int)piVar5;
        }
        in_ECX[0x2a] = in_ECX[0x2a] + -1;
        FUN_007290de(piVar3);
        piVar3 = piVar2;
      }
    }
  }
  while (piVar5 = (int *)in_ECX[0x2b], piVar5 != (int *)0x0) {
    iVar4 = piVar5[1];
    piVar3 = (int *)0x0;
    while (piVar2 = piVar3, piVar3 = piVar5, piVar3 != (int *)0x0) {
      piVar5 = (int *)*piVar3;
      if (piVar3[1] == iVar4) {
        if (piVar3 == (int *)in_ECX[0x2b]) {
          in_ECX[0x2b] = (int)piVar5;
        }
        else {
          *piVar2 = (int)piVar5;
        }
        in_ECX[0x2c] = in_ECX[0x2c] + -1;
        FUN_007290de(piVar3);
        piVar3 = piVar2;
      }
    }
  }
  if ((int *)in_ECX[0x2d] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x2d] + 0x868))(0);
    (**(code **)(*(int *)in_ECX[0x2d] + 0xc))(unaff_retaddr);
    in_ECX[0x2d] = 0;
  }
  if ((int *)in_ECX[0x2e] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x2e] + 4))(1);
    in_ECX[0x2e] = 0;
  }
  _ToBeDeleted_CitadelPart__UAEXH_Z(param_1);
  return;
}



// ?GetMesh@WorshipSite@@UBEHXZ @ 0x00704310

undefined4 _GetMesh_WorshipSite__UBEHXZ(void)

{
  int iVar1;
  int in_ECX;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined1 uStack_4;
  
  if (*(int **)(in_ECX + 0xb8) != (int *)0x0) {
    uStack_3c = 0;
    uStack_38 = 0;
    uStack_34 = 0;
    uStack_30 = 0;
    uStack_2c = 0;
    uStack_28 = 0;
    uStack_24 = 0;
    uStack_20 = 0;
    uStack_1c = 0;
    uStack_18 = 0;
    uStack_14 = 0;
    uStack_10 = 0;
    uStack_8 = 0;
    uStack_4 = 1;
    uStack_c = 0x3f800000;
    iVar1 = (**(code **)(**(int **)(in_ECX + 0xb8) + 0xfc))(&uStack_3c,DAT_00c22d78);
    if (iVar1 == 5) {
      if (*(int **)(in_ECX + 0xb8) != (int *)0x0) {
        (**(code **)(**(int **)(in_ECX + 0xb8) + 4))(1);
      }
      *(undefined4 *)(in_ECX + 0xb8) = 0;
    }
  }
  if (*(int **)(in_ECX + 0xb4) != (int *)0x0) {
    iVar1 = (**(code **)(**(int **)(in_ECX + 0xb4) + 0x2c))();
    if (iVar1 != 1) {
      *(undefined4 *)(in_ECX + 0xb4) = 0;
    }
  }
  FUN_006b1410();
  return 1;
}



// ?AddResource@WorshipSite@@UAEIW4RESOURCE_TYPE@@IPAVGInterfaceStatus@@_NPBUMapCoords@@H@Z @ 0x00704e50

undefined4
_AddResource_WorshipSite__UAEIW4RESOURCE_TYPE__IPAVGInterfaceStatus___NPBUMapCoords__H_Z
          (int param_1)

{
  undefined4 uVar1;
  int in_ECX;
  
  if ((param_1 == 0) && (*(int **)(in_ECX + 0xb4) != (int *)0x0)) {
    uVar1 = (**(code **)(**(int **)(in_ECX + 0xb4) + 0x94))(0,0,0);
    return uVar1;
  }
  return 0;
}



// ?RemoveResource@WorshipSite@@UAEIW4RESOURCE_TYPE@@IPAVGInterfaceStatus@@PA_N@Z @ 0x00705600

undefined4
_RemoveResource_WorshipSite__UAEIW4RESOURCE_TYPE__IPAVGInterfaceStatus__PA_N_Z
          (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int in_ECX;
  
  if ((*(int **)(in_ECX + 0x74) != (int *)0x0) && ((param_1 == 1 || (param_1 == -2)))) {
    uVar1 = (**(code **)(**(int **)(in_ECX + 0x74) + 0x9c))(param_1,param_2,param_3,param_4,0,0);
    return uVar1;
  }
  if (param_1 == 0) {
    if (*(int *)(in_ECX + 0xb4) == 0) {
      FUN_00703ef0();
    }
    uVar1 = (**(code **)(**(int **)(in_ECX + 0xb4) + 0x8c))(0,param_2,param_4);
    return uVar1;
  }
  return 0;
}



// ?Load@WorshipSite@@UAEIAAVGameOSFile@@@Z @ 0x00705c90

void _Load_WorshipSite__UAEIAAVGameOSFile___Z(undefined4 param_1,undefined4 param_2)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x7f8))(param_1,param_2);
  return;
}



// ?GetSaveType@WorshipSite@@UAEIXZ @ 0x00706000

undefined4 _GetSaveType_WorshipSite__UAEIXZ(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  iVar2 = _GetSaveType_CitadelPart__UAEIXZ(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  FUN_00533b90(*(undefined4 *)(in_ECX + 0x8c));
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0x90));
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0xa0));
  iVar2 = 0;
  if (DAT_00b19ac8 != 0) {
    iVar3 = *(int *)(in_ECX + 0xa8);
    FUN_0066ee00(in_ECX + 0xa8);
    for (puVar1 = *(undefined4 **)(in_ECX + 0xa4); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      iVar2 = iVar2 + 1;
      if (iVar3 < iVar2) goto LAB_007060a2;
      if (DAT_00b19ac8 == 0) goto LAB_007060ae;
      FUN_00531bc0(puVar1[1]);
    }
    if ((DAT_00b19ac8 != 0) && (iVar2 != iVar3)) {
LAB_007060a2:
      DAT_00b19ac8 = 0;
    }
  }
LAB_007060ae:
  iVar2 = 0;
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0xb4));
  if (DAT_00b19ac8 != 0) {
    iVar3 = FUN_0072be90((byte *)(in_ECX + 0xbc),4,0);
    if (iVar3 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xbc) + 4;
    if (DAT_00b19ac8 != 0) {
      iVar3 = FUN_0072be90((byte *)(in_ECX + 0xc0),4,0);
      if (iVar3 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xc0) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar3 = FUN_0072be90((byte *)(in_ECX + 0xc4),1,0);
        if (iVar3 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xc4) + 1;
        if (DAT_00b19ac8 != 0) {
          iVar3 = FUN_0072be90((byte *)(in_ECX + 200),4,0);
          if (iVar3 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 200) + 4;
          if (DAT_00b19ac8 != 0) {
            iVar3 = FUN_0072be90((byte *)(in_ECX + 0xcc),4,0);
            if (iVar3 == 3) {
              DAT_00b19ac8 = 0;
            }
            *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xcc) + 4;
            if (DAT_00b19ac8 != 0) {
              iVar3 = FUN_0072be90((byte *)(in_ECX + 0xd0),4,0);
              if (iVar3 == 3) {
                DAT_00b19ac8 = 0;
              }
              *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xd0) + 4;
              if (DAT_00b19ac8 != 0) {
                iVar3 = *(int *)(in_ECX + 0xd8);
                FUN_0066ee00(in_ECX + 0xd8);
                for (puVar1 = *(undefined4 **)(in_ECX + 0xd4); puVar1 != (undefined4 *)0x0;
                    puVar1 = (undefined4 *)*puVar1) {
                  iVar2 = iVar2 + 1;
                  if (iVar3 < iVar2) goto LAB_0070628b;
                  if (DAT_00b19ac8 == 0) goto LAB_00706292;
                  FUN_00531bc0(puVar1[1]);
                }
                if ((DAT_00b19ac8 != 0) && (iVar2 != iVar3)) {
LAB_0070628b:
                  DAT_00b19ac8 = 0;
                }
              }
            }
          }
        }
      }
    }
  }
LAB_00706292:
  if (DAT_00b19ac8 != 0) {
    iVar2 = *(int *)(in_ECX + 0xe4);
    param_1 = 0;
    FUN_0066ee00(in_ECX + 0xe4);
    for (iVar3 = FUN_00707490(0); iVar3 != 0; iVar3 = FUN_00707490(iVar3)) {
      param_1 = param_1 + 1;
      if (iVar2 < param_1) {
        DAT_00b19ac8 = 0;
        break;
      }
      if (DAT_00b19ac8 == 0) break;
      FUN_00531bc0(iVar3);
    }
  }
  FUN_005341d0(in_ECX + 0xe8,2);
  FUN_0066ee00(in_ECX + 0xf0);
  FUN_0066ee00(in_ECX + 0xf4);
  FUN_0066ee00(in_ECX + 0xf8);
  FUN_0066ee00(in_ECX + 0xfc);
  FUN_0066ee00(in_ECX + 0x100);
  FUN_0066ee00(in_ECX + 0x104);
  FUN_0066ee00(in_ECX + 0x108);
  FUN_0066ee00(in_ECX + 0x10c);
  FUN_00604120(in_ECX + 0x110);
  FUN_00604120(in_ECX + 0x111);
  FUN_00707270(in_ECX + 0x120);
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0xdc));
  FUN_0066ee00(in_ECX + 0x114);
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0xb8));
  FUN_0066ee00(in_ECX + 0x118);
  FUN_0066ee00(in_ECX + 0x11c);
  return 1;
}



// ?Save@WorshipSite@@UAEIAAVGameOSFile@@@Z @ 0x00706410

undefined4 _Save_WorshipSite__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  uint uVar2;
  int in_stack_0000ba1e;
  uint in_stack_0000ba26;
  
  iVar1 = _Save_CitadelPart__UAEIAAVGameOSFile___Z();
  if (iVar1 != 0) {
    FUN_00533bf0();
    FUN_00531f30();
    FUN_00531f30();
    uVar2 = 0;
    if (DAT_00b19acc != 0) {
      FUN_00589540();
      for (iVar1 = param_1; 0 < iVar1; iVar1 = iVar1 + -1) {
        FUN_00531f30();
        FUN_006d5810();
      }
    }
    FUN_00531f30();
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xbc) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xc0) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xc4) + 1;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 200) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xcc) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xd0) + 4;
      if (DAT_00b19acc != 0) {
        FUN_00589540();
        for (; 0 < (int)in_stack_0000ba26; in_stack_0000ba26 = in_stack_0000ba26 - 1) {
          FUN_00531f30();
          FUN_006d5810();
        }
        if (DAT_00b19acc != 0) {
          FUN_00589540();
          for (; 0 < (int)in_stack_0000ba26; in_stack_0000ba26 = in_stack_0000ba26 - 1) {
            FUN_00531f30();
            *(undefined4 *)(in_stack_0000ba1e + 0x110) = 0;
            FUN_00707440();
          }
          if ((DAT_00b19acc != 0) && (FUN_00589540(), in_stack_0000ba26 != 0)) {
            do {
              FUN_00589540();
              uVar2 = uVar2 + 1;
            } while (uVar2 < in_stack_0000ba26);
          }
        }
      }
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xf0) + 4;
    }
    FUN_00589540();
    FUN_00589540();
    FUN_00589540();
    FUN_00589540();
    FUN_00589540();
    FUN_00589540();
    FUN_00589540();
    FUN_00604170();
    FUN_00604170();
    FUN_00707310();
    FUN_00531f30();
    FUN_00589540();
    FUN_00531f30();
    FUN_00589540();
    FUN_00589540();
    return 1;
  }
  return 0;
}



// ?Process@WorshipSite@@UAEIXZ @ 0x00706ae0

void _Process_WorshipSite__UAEIXZ(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined1 auStack_c [12];
  
  puVar1 = (undefined4 *)FUN_00706a40(auStack_c);
  *param_1 = *puVar1;
  param_1[1] = puVar1[1];
  param_1[2] = puVar1[2];
  return;
}



// ?DoCreatureMimicAfterAddingResource@WorshipSite@@UAE_NW4RESOURCE_TYPE@@AAVGInterfaceStatus@@@Z @ 0x00706bc0

undefined4
_DoCreatureMimicAfterAddingResource_WorshipSite__UAE_NW4RESOURCE_TYPE__AAVGInterfaceStatus___Z
          (int param_1)

{
  int iVar1;
  
  iVar1 = _IsResourceStore_MultiMapFixed__UAE_NW4RESOURCE_TYPE___Z(param_1);
  if (((iVar1 == 0) && (param_1 != 0)) && (param_1 != -2)) {
    return 0;
  }
  return 1;
}



// ?Built@WorshipSite@@UAE_NXZ @ 0x00706e60

undefined4 _Built_WorshipSite__UAE_NXZ(undefined4 param_1)

{
  int *in_ECX;
  
  (**(code **)(*in_ECX + 0x864))(param_1);
  return param_1;
}



