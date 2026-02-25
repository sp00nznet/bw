// Decompiled functions for class: Forest
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?IsFunctional@Forest@@UAE_NXZ @ 0x0050e100

undefined4 _IsFunctional_Forest__UAE_NXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x2c))();
  if ((iVar1 == 1) && (in_ECX[0x15] + in_ECX[0x13] != 0)) {
    return 1;
  }
  return 0;
}



// ?GetText@Forest@@UAEPBDXZ @ 0x0050e120

char * _GetText_Forest__UAEPBDXZ(void)

{
  return s_Forest_00b1747c;
}



// ?GetSaveType@Forest@@UAEIXZ @ 0x0050e130

undefined4 _GetSaveType_Forest__UAEIXZ(void)

{
  return 0x4e;
}



// ?GetDebugText@Forest@@UAEPADXZ @ 0x0050e140

char * _GetDebugText_Forest__UAEPADXZ(void)

{
  return s_Forest__00b17484;
}



// ?ToBeDeleted@Forest@@UAEXH@Z @ 0x0050e290

void _ToBeDeleted_Forest__UAEXH_Z(undefined4 param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int in_ECX;
  int *piVar8;
  
  while (piVar1 = *(int **)(in_ECX + 0x48), piVar1 != (int *)0x0) {
    piVar2 = (int *)*piVar1;
    piVar5 = piVar1;
    piVar8 = (int *)0x0;
    if (piVar1 == (int *)0x0) {
LAB_0050e2df:
      (**(code **)(*piVar2 + 0xc))(0);
    }
    else {
      do {
        piVar7 = piVar5;
        if ((int *)*piVar7 == piVar2) {
          if (piVar8 == (int *)0x0) {
            *(int *)(in_ECX + 0x48) = piVar1[1];
          }
          else {
            piVar8[1] = piVar7[1];
          }
          FUN_007290de(piVar7);
          *(int *)(in_ECX + 0x4c) = *(int *)(in_ECX + 0x4c) + -1;
          goto LAB_0050e2df;
        }
        piVar5 = (int *)piVar7[1];
        piVar8 = piVar7;
      } while ((int *)piVar7[1] != (int *)0x0);
      (**(code **)(*piVar2 + 0xc))(0);
    }
  }
  while (iVar4 = DAT_00c22ca4, piVar1 = *(int **)(in_ECX + 0x50), piVar1 != (int *)0x0) {
    piVar2 = (int *)*piVar1;
    piVar5 = piVar1;
    piVar8 = (int *)0x0;
    if (piVar1 == (int *)0x0) {
LAB_0050e335:
      (**(code **)(*piVar2 + 0xc))(0);
    }
    else {
      do {
        piVar7 = piVar5;
        if ((int *)*piVar7 == piVar2) {
          if (piVar8 == (int *)0x0) {
            *(int *)(in_ECX + 0x50) = piVar1[1];
          }
          else {
            piVar8[1] = piVar7[1];
          }
          FUN_007290de(piVar7);
          *(int *)(in_ECX + 0x54) = *(int *)(in_ECX + 0x54) + -1;
          goto LAB_0050e335;
        }
        piVar5 = (int *)piVar7[1];
        piVar8 = piVar7;
      } while ((int *)piVar7[1] != (int *)0x0);
      (**(code **)(*piVar2 + 0xc))(0);
    }
  }
  iVar6 = *(int *)(DAT_00c22ca4 + 0x201c70);
  if (*(int *)(DAT_00c22ca4 + 0x201c70) == in_ECX) {
    *(undefined4 *)(DAT_00c22ca4 + 0x201c70) = *(undefined4 *)(in_ECX + 0x44);
  }
  else {
    do {
      iVar3 = iVar6;
      if (iVar3 == 0) goto LAB_0050e380;
      iVar6 = *(int *)(iVar3 + 0x44);
    } while (*(int *)(iVar3 + 0x44) != in_ECX);
    *(undefined4 *)(iVar3 + 0x44) = *(undefined4 *)(in_ECX + 0x44);
  }
  *(int *)(iVar4 + 0x201c74) = *(int *)(iVar4 + 0x201c74) + -1;
  *(undefined4 *)(in_ECX + 0x44) = 0;
LAB_0050e380:
  FUN_0050efe0();
  _ToBeDeleted_GameThingWithPos__UAEXH_Z(param_1);
  return;
}



// ?AddFootpath@Forest@@UAEIPAVGFootpath@@@Z @ 0x0050ee30

undefined4 _AddFootpath_Forest__UAEIPAVGFootpath___Z(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x74))();
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)FUN_004300a0(0x1c,s_C__dev_black_Forest_cpp_00b1748c,0x238);
    if (puVar2 == (undefined4 *)0x0) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      FUN_0053e720();
      puVar2[6] = 0;
      puVar2[5] = 0;
      *puVar2 = &vftable_GFootpathLink;
    }
    in_ECX[0xc] = (int)puVar2;
  }
  piVar3 = (int *)(**(code **)(*in_ECX + 0x74))();
  (**(code **)(*piVar3 + 0x84))(param_1);
  return 1;
}



// ?RemoveFootpath@Forest@@UAEIPAVGFootpath@@@Z @ 0x0050eea0

undefined4 _RemoveFootpath_Forest__UAEIPAVGFootpath___Z(undefined4 param_1)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x74))();
  if (iVar1 == 0) {
    (**(code **)(*(int *)in_ECX[0xc] + 0x88))(param_1);
    return 1;
  }
  return 0;
}



// ?Save@Forest@@UAEIAAVGameOSFile@@@Z @ 0x0050f010

undefined4 _Save_Forest__UAEIAAVGameOSFile___Z(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  
  iVar2 = _Save_Container__UAEIAAVGameOSFile___Z(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = 0;
  if (DAT_00b19ac8 != 0) {
    iVar3 = FUN_0072be90((byte *)(in_ECX + 0x3c),4,0);
    if (iVar3 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x3c) + 4;
  }
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0x30));
  if (DAT_00b19ac8 != 0) {
    iVar3 = FUN_0072be90((byte *)(in_ECX + 0x40),4,0);
    if (iVar3 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x40) + 4;
    if (DAT_00b19ac8 != 0) {
      iVar3 = *(int *)(in_ECX + 0x4c);
      iVar4 = FUN_0072be90((byte *)(in_ECX + 0x4c),4,0);
      if (iVar4 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x4c) + 4;
      for (puVar1 = *(undefined4 **)(in_ECX + 0x48); puVar1 != (undefined4 *)0x0;
          puVar1 = (undefined4 *)puVar1[1]) {
        iVar2 = iVar2 + 1;
        if (iVar3 < iVar2) {
          DAT_00b19ac8 = 0;
          break;
        }
        if (DAT_00b19ac8 == 0) goto LAB_0050f198;
        FUN_00531bc0(*puVar1);
      }
    }
  }
  if (DAT_00b19ac8 != 0) {
    iVar2 = *(int *)(in_ECX + 0x54);
    iVar3 = 0;
    iVar4 = FUN_0072be90((byte *)(in_ECX + 0x54),4,0);
    if (iVar4 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x54) + 4;
    for (puVar1 = *(undefined4 **)(in_ECX + 0x50); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)puVar1[1]) {
      iVar3 = iVar3 + 1;
      if (iVar2 < iVar3) {
        DAT_00b19ac8 = 0;
        break;
      }
      if (DAT_00b19ac8 == 0) break;
      FUN_00531bc0(*puVar1);
    }
  }
LAB_0050f198:
  FUN_00531bc0(*(undefined4 *)(in_ECX + 0x38));
  if (DAT_00b19ac8 != 0) {
    iVar2 = FUN_0072be90(&DAT_00bf1828,4,0);
    if (iVar2 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (DAT_00bf1828 & 0xff) + 4;
    if (DAT_00b19ac8 != 0) {
      iVar2 = FUN_0072be90(&DAT_00b17458,4,0);
      if (iVar2 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (DAT_00b17458 & 0xff) + 4;
    }
  }
  return 1;
}



