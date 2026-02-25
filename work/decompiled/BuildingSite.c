// Decompiled functions for class: BuildingSite
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?ToBeDeleted@BuildingSite@@UAEXH@Z @ 0x00434150

void _ToBeDeleted_BuildingSite__UAEXH_Z(void)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  int *in_ECX;
  int *piVar8;
  bool bVar9;
  float10 fVar10;
  float10 fVar11;
  undefined4 unaff_retaddr;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined1 auStack_c [12];
  
  iVar5 = DAT_00c22ca4;
  if ((*(byte *)((int)in_ECX + 10) & 1) == 0) {
    piVar7 = (int *)(DAT_00c22ca4 + 0x201d68);
    piVar8 = (int *)*piVar7;
    piVar4 = (int *)0x0;
    while (piVar3 = piVar4, piVar4 = piVar8, piVar4 != (int *)0x0) {
      piVar8 = (int *)*piVar4;
      if ((int *)piVar4[1] == in_ECX) {
        if (piVar4 == (int *)*piVar7) {
          *piVar7 = (int)piVar8;
        }
        else {
          *piVar3 = (int)piVar8;
        }
        *(int *)(iVar5 + 0x201d6c) = *(int *)(iVar5 + 0x201d6c) + -1;
        FUN_007290de(piVar4);
        piVar4 = piVar3;
      }
    }
    for (puVar1 = *(undefined4 **)(DAT_00c22ca4 + 0x201d40); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      for (puVar2 = *(undefined4 **)(puVar1[1] + 0x788); puVar2 != (undefined4 *)0x0;
          puVar2 = (undefined4 *)*puVar2) {
        if ((int *)puVar2[1] == in_ECX) {
          FUN_006ceb70(in_ECX);
          break;
        }
      }
    }
    puVar1 = (undefined4 *)in_ECX[6];
    while (puVar1 != (undefined4 *)0x0) {
      bVar9 = puVar1 != (undefined4 *)0x0;
      puVar2 = (undefined4 *)*puVar1;
      piVar7 = (int *)puVar1[1];
      puVar1 = puVar2;
      if ((bVar9) && (iVar5 = (**(code **)(*piVar7 + 0x2c))(), iVar5 != 0)) {
        fVar10 = (float10)(**(code **)(*(int *)in_ECX[5] + 100))();
        iVar5 = in_ECX[5];
        uStack_18 = *(undefined4 *)(iVar5 + 0x14);
        uStack_14 = *(undefined4 *)(iVar5 + 0x18);
        uStack_10 = *(undefined4 *)(iVar5 + 0x1c);
        fVar11 = (float10)FUN_006de0a0(piVar7 + 5,&uStack_18);
        if ((float10)(float)(fVar10 + (float10)2.0) <= fVar11) {
          (**(code **)(*piVar7 + 0x8e4))(0xa3);
        }
        else {
          fVar11 = (float10)FUN_006de3e0(in_ECX[5] + 0x14,piVar7 + 5);
          uVar6 = FUN_006de5a0(auStack_c,(float)fVar11,(float)(fVar10 + (float10)2.0));
          FUN_005c12d0(uVar6);
          FUN_005b0e40(&uStack_18,0xa3);
        }
      }
    }
    while (in_ECX[6] != 0) {
      FUN_00542c40(*(undefined4 *)(in_ECX[6] + 4),0);
    }
    if (in_ECX[8] == 0) {
      piVar7 = (int *)0x0;
    }
    else {
      piVar7 = *(int **)(in_ECX[8] + 4);
    }
    while (piVar7 != (int *)0x0) {
      piVar8 = (int *)in_ECX[8];
      do {
        if (piVar8 == (int *)0x0) goto LAB_004342ed;
        piVar4 = piVar8 + 1;
        piVar8 = (int *)*piVar8;
      } while ((int *)*piVar4 != piVar7);
      if (piVar8 == (int *)0x0) {
LAB_004342ed:
        piVar8 = (int *)0x0;
      }
      else {
        piVar8 = (int *)piVar8[1];
      }
      (**(code **)(*piVar7 + 0xc))(0);
      piVar7 = piVar8;
    }
    piVar7 = (int *)(**(code **)(*in_ECX + 0x108))(0);
    if (piVar7 != (int *)0x0) {
      if (((int *)in_ECX[5] == (int *)0x0) ||
         (iVar5 = (**(code **)(*(int *)in_ECX[5] + 0x310))(), iVar5 == 0)) {
        (**(code **)(*piVar7 + 0x868))(0);
        iVar5 = (**(code **)(*piVar7 + 0x94))(1,0,0);
        if ((iVar5 == 0) || ((*(uint *)(DAT_00c22ca4 + 0x14) & 0x8000) != 0)) {
          (**(code **)(*piVar7 + 0xc))(unaff_retaddr);
        }
        else {
          FUN_00617330();
        }
      }
      (**(code **)(*in_ECX + 0x10c))(0);
    }
    if (in_ECX[5] != 0) {
      FUN_005046f0(0);
      in_ECX[5] = 0;
    }
    _ToBeDeleted_GameThing__UAEXH_Z(unaff_retaddr);
  }
  return;
}



// ?GetTown@BuildingSite@@UAEPAVTown@@XZ @ 0x00434760

undefined4 _GetTown_BuildingSite__UAEPAVTown__XZ(void)

{
  undefined4 uVar1;
  int in_ECX;
  
  if (*(int **)(in_ECX + 0x14) != (int *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00434769. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = (**(code **)(**(int **)(in_ECX + 0x14) + 0x48))();
    return uVar1;
  }
  return 0;
}



// ?AddResource@BuildingSite@@UAEIW4RESOURCE_TYPE@@IPAVGInterfaceStatus@@_NPBUMapCoords@@H@Z @ 0x00434b40

uint _AddResource_BuildingSite__UAEIW4RESOURCE_TYPE__IPAVGInterfaceStatus___NPBUMapCoords__H_Z
               (int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int *in_ECX;
  uint uVar3;
  
  uVar3 = 0;
  if (param_1 == 1) {
    iVar1 = (**(code **)(*in_ECX + 0x108))(0);
    if (iVar1 == 0) {
      (**(code **)(*in_ECX + 0x110))();
    }
    piVar2 = (int *)(**(code **)(*in_ECX + 0x108))(0);
    if (piVar2 != (int *)0x0) {
      iVar1 = (**(code **)(*piVar2 + 0x2c))();
      if (iVar1 != 0) {
        uVar3 = (**(code **)(*piVar2 + 0x8c))(1,param_2,param_4);
      }
    }
  }
  iVar1 = (**(code **)(*in_ECX + 0x48))();
  if (iVar1 != 0) {
    *(float *)(iVar1 + 0x708) = (float)uVar3 + *(float *)(iVar1 + 0x708);
  }
  return uVar3;
}



// ?RemoveResource@BuildingSite@@UAEIW4RESOURCE_TYPE@@IPAVGInterfaceStatus@@PA_N@Z @ 0x00434be0

uint _RemoveResource_BuildingSite__UAEIW4RESOURCE_TYPE__IPAVGInterfaceStatus__PA_N_Z
               (int param_1,undefined4 param_2,int *param_3)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int *in_ECX;
  uint uVar4;
  undefined1 local_c [12];
  
  uVar4 = 0;
  if (param_1 == 1) {
    if (param_3 == (int *)0x0) {
      uVar1 = 0;
    }
    else {
      uVar1 = (**(code **)(*param_3 + 0x100))(local_c);
    }
    piVar2 = (int *)(**(code **)(*in_ECX + 0x108))(uVar1);
    if (piVar2 != (int *)0x0) {
      uVar4 = (**(code **)(*piVar2 + 0x90))(1,param_2,0);
    }
  }
  iVar3 = (**(code **)(*in_ECX + 0x48))();
  if (iVar3 != 0) {
    *(float *)(iVar3 + 0x708) = *(float *)(iVar3 + 0x708) - (float)uVar4;
  }
  return uVar4;
}



// ?GetResource@BuildingSite@@UAEIW4RESOURCE_TYPE@@@Z @ 0x00434c60

undefined4 _GetResource_BuildingSite__UAEIW4RESOURCE_TYPE___Z(void)

{
  int *piVar1;
  undefined4 uVar2;
  int *in_ECX;
  undefined4 unaff_retaddr;
  
  piVar1 = (int *)(**(code **)(*in_ECX + 0x108))(0);
  if (piVar1 != (int *)0x0) {
    uVar2 = (**(code **)(*piVar1 + 0x94))(unaff_retaddr,0,0);
    return uVar2;
  }
  return 0;
}



// ?Save@BuildingSite@@UAEIAAVGameOSFile@@@Z @ 0x00434ee0

undefined4 _Save_BuildingSite__UAEIAAVGameOSFile___Z(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  int iVar4;
  
  iVar2 = FUN_0053e8e0(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0x14));
  if (DAT_00b19ac8 != 0) {
    iVar2 = *(int *)(in_ECX + 0x1c);
    iVar4 = 0;
    iVar3 = FUN_0072be90((byte *)(in_ECX + 0x1c),4,0);
    if (iVar3 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x1c) + 4;
    for (puVar1 = *(undefined4 **)(in_ECX + 0x18); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      iVar4 = iVar4 + 1;
      if (iVar2 < iVar4) goto LAB_00434f88;
      if (DAT_00b19ac8 == 0) goto LAB_00435146;
      FUN_00531bc0(puVar1[1]);
    }
    if (DAT_00b19ac8 != 0) {
      if (iVar4 != iVar2) {
LAB_00434f88:
        DAT_00b19ac8 = 0;
      }
      if (DAT_00b19ac8 != 0) {
        iVar2 = *(int *)(in_ECX + 0x24);
        iVar4 = 0;
        FUN_0066ee00(in_ECX + 0x24);
        for (puVar1 = *(undefined4 **)(in_ECX + 0x20); puVar1 != (undefined4 *)0x0;
            puVar1 = (undefined4 *)*puVar1) {
          iVar4 = iVar4 + 1;
          if (iVar2 < iVar4) goto LAB_00434fec;
          if (DAT_00b19ac8 == 0) goto LAB_00435146;
          FUN_00531bc0(puVar1[1]);
        }
        if (DAT_00b19ac8 != 0) {
          if (iVar4 != iVar2) {
LAB_00434fec:
            DAT_00b19ac8 = 0;
          }
          if (DAT_00b19ac8 != 0) {
            iVar2 = *(int *)(in_ECX + 0x2c);
            iVar4 = 0;
            FUN_0066ee00(in_ECX + 0x2c);
            for (puVar1 = *(undefined4 **)(in_ECX + 0x28); puVar1 != (undefined4 *)0x0;
                puVar1 = (undefined4 *)*puVar1) {
              iVar4 = iVar4 + 1;
              if (iVar2 < iVar4) goto LAB_00435050;
              if (DAT_00b19ac8 == 0) goto LAB_00435146;
              FUN_00531bc0(puVar1[1]);
            }
            if (DAT_00b19ac8 != 0) {
              if (iVar4 == iVar2) {
                iVar2 = FUN_0072be90((byte *)(in_ECX + 0x30),4,0);
                if (iVar2 == 3) {
                  DAT_00b19ac8 = 0;
                }
                *(uint *)(param_1 + 0x214) =
                     *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x30) + 4;
                if (DAT_00b19ac8 != 0) {
                  iVar2 = FUN_0072be90((byte *)(in_ECX + 0x34),0x600,0);
                  if (iVar2 == 3) {
                    DAT_00b19ac8 = 0;
                  }
                  *(uint *)(param_1 + 0x214) =
                       *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x34) + 0x600;
                  if (DAT_00b19ac8 != 0) {
                    iVar2 = FUN_0072be90((byte *)(in_ECX + 0x634),4,0);
                    if (iVar2 == 3) {
                      DAT_00b19ac8 = 0;
                    }
                    *(uint *)(param_1 + 0x214) =
                         *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x634) + 4;
                    if (DAT_00b19ac8 != 0) {
                      iVar2 = FUN_0072be90((byte *)(in_ECX + 0x638),4,0);
                      if (iVar2 == 3) {
                        DAT_00b19ac8 = 0;
                      }
                      *(uint *)(param_1 + 0x214) =
                           *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x638) + 4;
                    }
                  }
                }
              }
              else {
LAB_00435050:
                DAT_00b19ac8 = 0;
              }
            }
          }
        }
      }
    }
  }
LAB_00435146:
  FUN_0066ee00(in_ECX + 0x63c);
  FUN_0066ee00(in_ECX + 0x640);
  return 1;
}



// ?Load@BuildingSite@@UAEIAAVGameOSFile@@@Z @ 0x00435180

undefined4 _Load_BuildingSite__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  uint in_stack_00005d15;
  uint in_stack_0000ba26;
  uint in_stack_00011737;
  
  iVar1 = FUN_0053e9f0();
  if (iVar1 != 0) {
    FUN_00531f30();
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (in_stack_00005d15 & 0xff) + 4;
      for (; 0 < (int)in_stack_00005d15; in_stack_00005d15 = in_stack_00005d15 - 1) {
        FUN_00531f30();
        FUN_006d5810();
      }
      if (DAT_00b19acc != 0) {
        iVar1 = FUN_0072be50();
        if (iVar1 == 3) {
          DAT_00b19acc = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (in_stack_0000ba26 & 0xff) + 4;
        for (; 0 < (int)in_stack_0000ba26; in_stack_0000ba26 = in_stack_0000ba26 - 1) {
          FUN_00531f30();
          FUN_006d5810();
        }
        if (DAT_00b19acc != 0) {
          iVar1 = FUN_0072be50();
          if (iVar1 == 3) {
            DAT_00b19acc = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (in_stack_00011737 & 0xff) + 4;
          for (; 0 < (int)in_stack_00011737; in_stack_00011737 = in_stack_00011737 - 1) {
            FUN_00531f30();
            FUN_006d5810();
          }
        }
      }
    }
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
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x34) + 0x600;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x634) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x638) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x63c) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x640) + 4;
    }
    return 1;
  }
  return 0;
}



// ?GetRadius@BuildingSite@@UAEMXZ @ 0x00435700

float10 _GetRadius_BuildingSite__UAEMXZ(void)

{
  int iVar1;
  int *piVar2;
  float10 fVar3;
  
  iVar1 = FUN_00434460();
  if (iVar1 != 0) {
    piVar2 = (int *)FUN_00434460();
    fVar3 = (float10)(**(code **)(*piVar2 + 0x60))();
    return fVar3;
  }
  return (float10)0.0;
}



