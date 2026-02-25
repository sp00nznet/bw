// Decompiled functions for class: Dance
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetText@Dance@@UAEPBDXZ @ 0x0043e9e0

char * _GetText_Dance__UAEPBDXZ(void)

{
  return s_Dance_008fc8b0;
}



// ?GetFootpathLink@Dance@@UAEPAVGFootpathLink@@XZ @ 0x004e9e30

undefined4 _GetFootpathLink_Dance__UAEPAVGFootpathLink__XZ(void)

{
  int in_ECX;
  
  return *(undefined4 *)(in_ECX + 0xe8);
}



// ?GetSaveType@Dance@@UAEIXZ @ 0x004e9e40

undefined4 _GetSaveType_Dance__UAEIXZ(void)

{
  return 0x27;
}



// ?GetDebugText@Dance@@UAEPADXZ @ 0x004e9e50

char * _GetDebugText_Dance__UAEPADXZ(void)

{
  return s_Dance__00b145e4;
}



// ?ToBeDeleted@Dance@@UAEXH@Z @ 0x004ea060

void _ToBeDeleted_Dance__UAEXH_Z(void)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *puVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int in_ECX;
  
  if ((*(byte *)(in_ECX + 10) & 1) != 0) {
    return;
  }
  for (puVar1 = *(undefined4 **)(in_ECX + 0x78); puVar1 != (undefined4 *)0x0;
      puVar1 = (undefined4 *)*puVar1) {
    piVar2 = (int *)puVar1[1];
    puVar3 = (undefined4 *)piVar2[7];
    while (puVar3 != (undefined4 *)0x0) {
      piVar4 = (int *)puVar3[1];
      puVar3 = (undefined4 *)*puVar3;
      if ((*(byte *)((int)piVar4 + 10) & 1) == 0) {
        (**(code **)(*piVar4 + 0xb04))(1);
        (**(code **)(*piVar4 + 0xb08))();
      }
    }
    while (puVar3 = *(undefined4 **)(in_ECX + 0xa4), puVar3 != (undefined4 *)0x0) {
      iVar9 = puVar3[1];
      puVar8 = (undefined4 *)0x0;
      while (puVar6 = puVar8, puVar8 = puVar3, puVar8 != (undefined4 *)0x0) {
        puVar3 = (undefined4 *)*puVar8;
        if (puVar8[1] == iVar9) {
          if (puVar8 == *(undefined4 **)(in_ECX + 0xa4)) {
            *(undefined4 **)(in_ECX + 0xa4) = puVar3;
          }
          else {
            *puVar6 = puVar3;
          }
          *(int *)(in_ECX + 0xa8) = *(int *)(in_ECX + 0xa8) + -1;
          FUN_007290de(puVar8);
          puVar8 = puVar6;
        }
      }
    }
    (**(code **)(*piVar2 + 0xc))(0);
  }
  while (puVar1 = *(undefined4 **)(in_ECX + 0x78), puVar1 != (undefined4 *)0x0) {
    iVar9 = puVar1[1];
    puVar3 = (undefined4 *)0x0;
    while (puVar8 = puVar3, puVar3 = puVar1, puVar3 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*puVar3;
      if (puVar3[1] == iVar9) {
        if (puVar3 == *(undefined4 **)(in_ECX + 0x78)) {
          *(undefined4 **)(in_ECX + 0x78) = puVar1;
        }
        else {
          *puVar8 = puVar1;
        }
        *(int *)(in_ECX + 0x7c) = *(int *)(in_ECX + 0x7c) + -1;
        FUN_007290de(puVar3);
        puVar3 = puVar8;
      }
    }
  }
  if (*(int **)(in_ECX + 0xfc) != (int *)0x0) {
    (**(code **)(**(int **)(in_ECX + 0xfc) + 0x28))();
  }
  iVar7 = DAT_00c22ca4;
  iVar9 = *(int *)(DAT_00c22ca4 + 0x201c90);
  if (iVar9 == in_ECX) {
    *(int *)(DAT_00c22ca4 + 0x201c90) = *(int *)(in_ECX + 0xec);
  }
  else {
    if (iVar9 == 0) goto LAB_004ea1d0;
    while (iVar5 = *(int *)(iVar9 + 0xec), iVar5 != in_ECX) {
      iVar9 = iVar5;
      if (iVar5 == 0) {
        FUN_0055d2d0(0);
        return;
      }
    }
    *(undefined4 *)(iVar9 + 0xec) = *(undefined4 *)(in_ECX + 0xec);
  }
  *(int *)(iVar7 + 0x201c94) = *(int *)(iVar7 + 0x201c94) + -1;
  *(undefined4 *)(in_ECX + 0xec) = 0;
LAB_004ea1d0:
  FUN_0055d2d0(0);
  return;
}



// ?CleanUpBeforeReset@Dance@@UAEXXZ @ 0x004ea220

void _CleanUpBeforeReset_Dance__UAEXXZ(void)

{
  int in_ECX;
  
  *(undefined4 *)(in_ECX + 0xfc) = 0;
  return;
}



// ?Process@Dance@@UAEXXZ @ 0x004ea280

void _Process_Dance__UAEXXZ(void)

{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int *in_ECX;
  float10 fVar8;
  
  if (((int *)in_ECX[0x3f] != (int *)0x0) &&
     (iVar5 = (**(code **)(*(int *)in_ECX[0x3f] + 0x2c))(), iVar5 == 0)) {
    iVar5 = (**(code **)(*in_ECX + 0x2c))();
    if (iVar5 == 0) {
      return;
    }
    iVar5 = (**(code **)(*(int *)in_ECX[0x3f] + 0xa4))();
    if (iVar5 != 0) {
      *(undefined4 *)(iVar5 + 0x1074) = 0;
    }
    in_ECX[0x3f] = 0;
    (**(code **)(*in_ECX + 0xc))(0);
    return;
  }
  if (in_ECX[0x4a] != 0) {
    iVar5 = in_ECX[0x3f];
    in_ECX[5] = *(int *)(iVar5 + 0x14);
    in_ECX[6] = *(int *)(iVar5 + 0x18);
    in_ECX[7] = *(int *)(iVar5 + 0x1c);
  }
  if (((in_ECX[0x40] == 1) && (*(int *)(&DAT_00be5f78 + in_ECX[0x3c] * 0xb0) != 0)) &&
     (iVar5 = FUN_004ea670(), iVar5 != 0)) {
    FUN_004ea230();
  }
  else if ((in_ECX[0x41] != 0) &&
          ((uint)in_ECX[0x41] < (uint)(*(int *)(DAT_00c22ca4 + 0x201afc) - in_ECX[0x42]))) {
    in_ECX[0x40] = 1;
  }
  if ((in_ECX[0x40] == 0) && (in_ECX[0x24] != 0)) {
    fVar2 = (float)in_ECX[7];
    fVar8 = (float10)FUN_00760fd0();
    iVar5 = in_ECX[5];
    iVar1 = in_ECX[6];
    iVar6 = FUN_00527d30();
    iVar6 = *(int *)(iVar6 + 0x39c);
    fVar3 = (float)iVar5 * 0.00015258789 - *(float *)(iVar6 + 200);
    fVar4 = (float)(fVar8 + (float10)fVar2) - *(float *)(iVar6 + 0xcc);
    fVar2 = (float)iVar1 * 0.00015258789 - *(float *)(iVar6 + 0xd0);
    if (100.0 <= fVar3 * fVar3 + fVar4 * fVar4 + fVar2 * fVar2) {
      in_ECX[0x31] = 0;
    }
    else {
      iVar5 = in_ECX[0x31];
      in_ECX[0x31] = iVar5 + 1U;
      if ((in_ECX[0x2d] == 0) && (uVar7 = __ftol(), uVar7 < iVar5 + 1U)) {
        in_ECX[0x2c] = 1;
        FUN_0055d450();
        return;
      }
    }
    FUN_0055d450();
  }
  return;
}



// ?GetAngle@Dance@@UAEMXZ @ 0x004ea6f0

float10 _GetAngle_Dance__UAEMXZ(void)

{
  int iVar1;
  int in_ECX;
  float10 fVar2;
  
  iVar1 = FUN_007344da(*(undefined4 *)(in_ECX + 0xfc),0,&GameThingWithPos::RTTI_Type_Descriptor,
                       &WorshipSite::RTTI_Type_Descriptor,0);
  if (iVar1 != 0) {
    fVar2 = (float10)FUN_00704e30();
    return fVar2;
  }
  return (float10)0.0;
}



// ?GetScriptObjectType@Dance@@UAEIXZ @ 0x004ea7a0

undefined4 _GetScriptObjectType_Dance__UAEIXZ(void)

{
  return 10;
}



// ?Save@Dance@@UAEIAAVGameOSFile@@@Z @ 0x004ea860

undefined4 _Save_Dance__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = FUN_0055ee10(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0xf0),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xf0) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90((byte *)(in_ECX + 0xf4),4,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xf4) + 4;
        if (DAT_00b19ac8 != 0) {
          iVar1 = FUN_0072be90((byte *)(in_ECX + 0xf8),4,0);
          if (iVar1 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xf8) + 4;
        }
      }
    }
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0xfc));
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x100),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x100) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90((byte *)(in_ECX + 0x104),4,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x104) + 4;
        if (DAT_00b19ac8 != 0) {
          iVar1 = FUN_0072be90((byte *)(in_ECX + 0x108),4,0);
          if (iVar1 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x108) + 4;
          if (DAT_00b19ac8 != 0) {
            iVar1 = FUN_0072be90((byte *)(in_ECX + 0x10c),4,0);
            if (iVar1 == 3) {
              DAT_00b19ac8 = 0;
            }
            *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x10c) + 4;
            if (DAT_00b19ac8 != 0) {
              iVar1 = FUN_0072be90((byte *)(in_ECX + 0x110),4,0);
              if (iVar1 == 3) {
                DAT_00b19ac8 = 0;
              }
              *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x110) + 4
              ;
              if (DAT_00b19ac8 != 0) {
                iVar1 = FUN_0072be90((byte *)(in_ECX + 0x114),4,0);
                if (iVar1 == 3) {
                  DAT_00b19ac8 = 0;
                }
                *(uint *)(param_1 + 0x214) =
                     *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x114) + 4;
                if (DAT_00b19ac8 != 0) {
                  iVar1 = FUN_0072be90((byte *)(in_ECX + 0x118),0x10,0);
                  if (iVar1 == 3) {
                    DAT_00b19ac8 = 0;
                  }
                  *(uint *)(param_1 + 0x214) =
                       *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x118) + 0x10;
                  if (DAT_00b19ac8 != 0) {
                    iVar1 = FUN_0072be90((byte *)(in_ECX + 0x128),4,0);
                    if (iVar1 == 3) {
                      DAT_00b19ac8 = 0;
                    }
                    *(uint *)(param_1 + 0x214) =
                         *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x128) + 4;
                  }
                }
              }
            }
          }
        }
      }
    }
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0xe8));
    return 1;
  }
  return 0;
}



// ?Load@Dance@@UAEIAAVGameOSFile@@@Z @ 0x004eab40

undefined4 _Load_Dance__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_EBP;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = FUN_0055f190(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0xf0),4,0,unaff_EDI,unaff_EBP,unaff_ESI,unaff_EBX);
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xf0) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xf4) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0xf8) + 4;
    }
    FUN_00531f30();
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x100) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x104) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x108) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x10c) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x110) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x114) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x118) + 0x10;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x128) + 4;
    }
    FUN_00531f30();
    return 1;
  }
  return 0;
}



// ?AddFootpath@Dance@@UAEIPAVGFootpath@@@Z @ 0x004eae40

undefined4 _AddFootpath_Dance__UAEIPAVGFootpath___Z(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x74))();
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)FUN_004300a0(0x1c,s_C__dev_black_Dance_cpp_00b145f4,0x2d3);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      FUN_0053e720();
      puVar2[6] = 0;
      puVar2[5] = 0;
      *puVar2 = &vftable_GFootpathLink;
    }
    in_ECX[0x3a] = (int)puVar2;
  }
  piVar3 = (int *)(**(code **)(*in_ECX + 0x74))();
  (**(code **)(*piVar3 + 0x84))(param_1);
  return 1;
}



// ?RemoveFootpath@Dance@@UAEIPAVGFootpath@@@Z @ 0x004eaec0

undefined4 _RemoveFootpath_Dance__UAEIPAVGFootpath___Z(undefined4 param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x74))();
  if (iVar1 != 0) {
    (**(code **)(*(int *)in_ECX[0x3a] + 0x88))(param_1);
  }
  return 1;
}



// ?GetArrivePos@Dance@@UAEPAUMapCoords@@PAU2@@Z @ 0x004eaef0

void _GetArrivePos_Dance__UAEPAUMapCoords__PAU2__Z(int *param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  
  iVar1 = *(int *)(in_ECX + 0x18);
  iVar2 = *(int *)(in_ECX + 0x1c);
  *param_1 = *(int *)(in_ECX + 0x14) + 0x8000;
  param_1[1] = iVar1;
  param_1[2] = iVar2;
  return;
}



