// Decompiled functions for class: MobileWallHug
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetDestPos@MobileWallHug@@UAEPAUMapCoords@@XZ @ 0x00413db0

int _GetDestPos_MobileWallHug__UAEPAUMapCoords__XZ(void)

{
  int in_ECX;
  
  return in_ECX + 0x80;
}



// ?SetTowardsAngle@MobileWallHug@@UAEXG@Z @ 0x0045e820

void _SetTowardsAngle_MobileWallHug__UAEXG_Z(undefined4 param_1)

{
  FUN_005c86b0(param_1);
  return;
}



// ?AreWeThere@MobileWallHug@@UAE_NABUMapCoords@@M@Z @ 0x005c5a20

undefined4 _AreWeThere_MobileWallHug__UAE_NABUMapCoords__M_Z(int *param_1,float param_2)

{
  float fVar1;
  float fVar2;
  int in_ECX;
  
  fVar2 = (float)(*(int *)(in_ECX + 0x14) - *param_1);
  fVar1 = (float)(*(int *)(in_ECX + 0x18) - param_1[1]);
  param_2 = (float)*(ushort *)(in_ECX + 0x5a) + param_2;
  if (fVar2 * fVar2 + fVar1 * fVar1 < param_2 * param_2) {
    return 1;
  }
  return 0;
}



// ?MoveTo3D@MobileWallHug@@UAEXXZ @ 0x005c5b60

void _MoveTo3D_MobileWallHug__UAEXXZ(void)

{
  float fVar1;
  int in_ECX;
  
  if (*(float *)(in_ECX + 0x1c) <= *(float *)(in_ECX + 0x88)) {
    if (*(float *)(in_ECX + 0x88) <= *(float *)(in_ECX + 0x1c)) goto LAB_005c5b98;
    fVar1 = *(float *)(in_ECX + 0x1c) + 0.2;
  }
  else {
    fVar1 = *(float *)(in_ECX + 0x1c) - 0.2;
  }
  *(float *)(in_ECX + 0x1c) = fVar1;
LAB_005c5b98:
  FUN_005c5ba0();
  return;
}



// ?SetNewWander@MobileWallHug@@UAEXABUMapCoords@@HH@Z @ 0x005c68b0

void _SetNewWander_MobileWallHug__UAEXABUMapCoords__HH_Z(int param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  ushort uVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  int *in_ECX;
  undefined4 uVar7;
  
  iVar2 = in_ECX[0x17];
  if (param_1 == 0) {
    uVar7 = 0x435;
  }
  else {
    piVar1 = in_ECX + 5;
    FUN_006de0a0(param_1,piVar1);
    iVar5 = __ftol();
    if (param_3 < iVar5) {
      uVar3 = FUN_006de3b0(piVar1,param_1);
      goto LAB_005c691c;
    }
    if (iVar5 < param_2) {
      uVar3 = FUN_006de3b0(param_1,piVar1);
      goto LAB_005c691c;
    }
    uVar7 = 0x430;
  }
  sVar4 = FUN_0067bc90(0x80,s_C__dev_black_MobileWallHug_cpp_00b20e70,uVar7);
  uVar3 = (short)iVar2 + -0x40 + sVar4;
LAB_005c691c:
  (**(code **)(*in_ECX + 0x868))(uVar3 & 0x7ff);
  iVar2 = (&DAT_00b53a78)[*(ushort *)(in_ECX + 0x17)];
  uVar6 = (uint)(*(ushort *)((int)in_ECX + 0x5a) >> 4);
  in_ECX[0x19] = (int)((&DAT_00b54278)[*(ushort *)(in_ECX + 0x17)] * uVar6) >> 0xc;
  in_ECX[0x1b] = (int)(iVar2 * uVar6) >> 0xc;
  in_ECX[0x1a] = 0;
  return;
}



// ?GetFacingDirection@MobileWallHug@@UAEMXZ @ 0x005c6c50

void _GetFacingDirection_MobileWallHug__UAEMXZ(void)

{
  int in_ECX;
  
  FUN_006ded00(*(undefined2 *)(in_ECX + 0x5c));
  return;
}



// ?GetMovementDirection@MobileWallHug@@UAEXPAULHPoint@@@Z @ 0x005c6c60

void _GetMovementDirection_MobileWallHug__UAEXPAULHPoint___Z(float *param_1)

{
  int iVar1;
  int *in_ECX;
  
  if ((*(byte *)(in_ECX + 9) & 0x40) != 0) {
    (**(code **)(*in_ECX + 0x16c))(param_1);
    return;
  }
  *param_1 = (float)in_ECX[0x19];
  iVar1 = in_ECX[0x1b];
  param_1[1] = 0.0;
  param_1[2] = (float)iVar1;
  return;
}



// ?GetSpeedInMetres@MobileWallHug@@UBEMXZ @ 0x005c6c90

void _GetSpeedInMetres_MobileWallHug__UBEMXZ(void)

{
  int in_ECX;
  
  FUN_006dea50(*(undefined2 *)(in_ECX + 0x5a));
  return;
}



// ?SetSpeedInMetres@MobileWallHug@@UAEXMH@Z @ 0x005c6ca0

void _SetSpeedInMetres_MobileWallHug__UAEXMH_Z(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  int *in_ECX;
  
  iVar1 = *in_ECX;
  uVar2 = FUN_006dea70(param_1);
  (**(code **)(iVar1 + 0x864))(uVar2);
  return;
}



// ?GetRunningSpeedInMetres@MobileWallHug@@UAEMXZ @ 0x005c6cd0

void _GetRunningSpeedInMetres_MobileWallHug__UAEMXZ(void)

{
  int in_ECX;
  
  FUN_006dea50(*(undefined4 *)(*(int *)(in_ECX + 0x28) + 0x118));
  return;
}



// ?GetDefaultSpeedInMetres@MobileWallHug@@UAEMXZ @ 0x005c6cf0

void _GetDefaultSpeedInMetres_MobileWallHug__UAEMXZ(void)

{
  int in_ECX;
  
  FUN_006dea50(*(undefined4 *)(*(int *)(in_ECX + 0x28) + 0x104));
  return;
}



// ?GetSpeedInMetresPerSecond@MobileWallHug@@UBEMXZ @ 0x005c6d10

float10 _GetSpeedInMetresPerSecond_MobileWallHug__UBEMXZ(void)

{
  int in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)FUN_006dea50(*(undefined2 *)(in_ECX + 0x5a));
  return fVar1 * (float10)10.0;
}



// ?GetRunningSpeedInMetresPerSecond@MobileWallHug@@UAEMXZ @ 0x005c6d60

float10 _GetRunningSpeedInMetresPerSecond_MobileWallHug__UAEMXZ(void)

{
  int in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)FUN_006dea50(*(undefined4 *)(*(int *)(in_ECX + 0x28) + 0x118));
  return fVar1 * (float10)10.0;
}



// ?GetDefaultSpeedInMetresPerSecond@MobileWallHug@@UAEMXZ @ 0x005c6d80

float10 _GetDefaultSpeedInMetresPerSecond_MobileWallHug__UAEMXZ(void)

{
  int in_ECX;
  float10 fVar1;
  
  fVar1 = (float10)FUN_006dea50(*(undefined4 *)(*(int *)(in_ECX + 0x28) + 0x104));
  return fVar1 * (float10)10.0;
}



// ?Save@MobileWallHug@@UAEIAAVGameOSFile@@@Z @ 0x005c7040

undefined4 _Save_MobileWallHug__UAEIAAVGameOSFile___Z(uint param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  int in_ECX;
  undefined4 *puVar6;
  undefined1 local_24 [4];
  undefined4 local_20;
  undefined1 local_1c [8];
  undefined4 local_14;
  uint local_10;
  uint local_c [3];
  
  uVar2 = param_1;
  iVar3 = _Save_Mobile__UAEIAAVGameOSFile___Z(param_1);
  if (iVar3 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar3 = FUN_0072be90((byte *)(in_ECX + 0x58),2,0);
      if (iVar3 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(uVar2 + 0x214) = *(int *)(uVar2 + 0x214) + *(byte *)(in_ECX + 0x58) + 2;
      if (DAT_00b19ac8 != 0) {
        iVar3 = FUN_0072be90((byte *)(in_ECX + 0x5a),2,0);
        if (iVar3 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(uVar2 + 0x214) = *(int *)(uVar2 + 0x214) + *(byte *)(in_ECX + 0x5a) + 2;
        if (DAT_00b19ac8 != 0) {
          iVar3 = FUN_0072be90((byte *)(in_ECX + 0x5c),2,0);
          if (iVar3 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(uVar2 + 0x214) = *(int *)(uVar2 + 0x214) + *(byte *)(in_ECX + 0x5c) + 2;
          if (DAT_00b19ac8 != 0) {
            iVar3 = FUN_0072be90((byte *)(in_ECX + 0x5e),1,0);
            if (iVar3 == 3) {
              DAT_00b19ac8 = 0;
            }
            *(uint *)(uVar2 + 0x214) = *(int *)(uVar2 + 0x214) + *(byte *)(in_ECX + 0x5e) + 1;
          }
        }
      }
    }
    bVar1 = *(byte *)(in_ECX + 0x5e);
    if (bVar1 == 0xb) {
      if (DAT_00b19ac8 != 0) {
        iVar3 = FUN_0072be90((byte *)(in_ECX + 0x78),1,0);
        if (iVar3 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(uVar2 + 0x214) = *(int *)(uVar2 + 0x214) + *(byte *)(in_ECX + 0x78) + 1;
      }
    }
    else if ((0xb < bVar1) && (bVar1 < 0x13)) {
      if (DAT_00b19ac8 != 0) {
        iVar3 = FUN_0072be90((byte *)(in_ECX + 0x74),1,0);
        if (iVar3 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(uVar2 + 0x214) = *(int *)(uVar2 + 0x214) + *(byte *)(in_ECX + 0x74) + 1;
      }
      if (*(ushort *)(in_ECX + 0x76) == 0xffff) {
        local_20 = 0;
        piVar4 = (int *)FUN_005c9400(local_1c,local_24);
        param_1 = *(uint *)(*piVar4 + 0x10);
      }
      else {
        param_1 = (uint)*(ushort *)(in_ECX + 0x76);
      }
      if (DAT_00b19ac8 != 0) {
        iVar3 = FUN_0072be90(&param_1,4,0);
        if (iVar3 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(uVar2 + 0x214) = *(int *)(uVar2 + 0x214) + (param_1 & 0xff) + 4;
      }
      FUN_00548330();
      puVar6 = &local_14;
      uVar5 = FUN_005c5320(puVar6);
      FUN_005c5110(uVar5,puVar6);
      FUN_00531bc0(local_14);
      if (DAT_00b19ac8 != 0) {
        iVar3 = FUN_0072be90(&local_10,4,0);
        if (iVar3 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(uVar2 + 0x214) = *(int *)(uVar2 + 0x214) + (local_10 & 0xff) + 4;
        if (DAT_00b19ac8 != 0) {
          iVar3 = FUN_0072be90(local_c,0xc,0);
          if (iVar3 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(uVar2 + 0x214) = *(int *)(uVar2 + 0x214) + (local_c[0] & 0xff) + 0xc;
        }
      }
    }
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x7c));
    if (DAT_00b19ac8 != 0) {
      iVar3 = FUN_0072be90((byte *)(in_ECX + 0x80),0xc,0);
      if (iVar3 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(uVar2 + 0x214) = *(int *)(uVar2 + 0x214) + *(byte *)(in_ECX + 0x80) + 0xc;
    }
    FUN_00531bc0(*(undefined4 *)(in_ECX + 0x60));
    FUN_004ebf70(in_ECX + 100);
    return 1;
  }
  return 0;
}



// ?Load@MobileWallHug@@UAEIAAVGameOSFile@@@Z @ 0x005c7360

undefined4 _Load_MobileWallHug__UAEIAAVGameOSFile___Z(int param_1)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int in_ECX;
  uint in_stack_00005d15;
  uint in_stack_0000b9fe;
  uint in_stack_00011727;
  uint in_stack_00011737;
  
  iVar2 = _Load_Mobile__UAEIAAVGameOSFile___Z();
  if (iVar2 != 0) {
    if (DAT_00b19acc != 0) {
      iVar2 = FUN_0072be50();
      if (iVar2 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x58) + 2;
    }
    if (DAT_00b19acc != 0) {
      iVar2 = FUN_0072be50();
      if (iVar2 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x5a) + 2;
    }
    if (DAT_00b19acc != 0) {
      iVar2 = FUN_0072be50();
      if (iVar2 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x5c) + 2;
    }
    if (DAT_00b19acc != 0) {
      iVar2 = FUN_0072be50();
      if (iVar2 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x5e) + 1;
    }
    bVar1 = *(byte *)(in_ECX + 0x5e);
    if (bVar1 == 0xb) {
      if (DAT_00b19acc != 0) {
        iVar2 = FUN_0072be50();
        if (iVar2 == 3) {
          DAT_00b19acc = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x78) + 1;
      }
    }
    else if ((0xb < bVar1) && (bVar1 < 0x13)) {
      uVar3 = in_stack_00005d15;
      if (DAT_00b19acc != 0) {
        iVar2 = FUN_0072be50();
        if (iVar2 == 3) {
          DAT_00b19acc = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x74) + 1;
        if (DAT_00b19acc != 0) {
          iVar2 = FUN_0072be50();
          if (iVar2 == 3) {
            DAT_00b19acc = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (in_stack_00011737 & 0xff) + 4;
          uVar3 = in_stack_00011737;
        }
      }
      if (uVar3 < 0xffff) {
        *(short *)(in_ECX + 0x76) = (short)uVar3;
      }
      else {
        piVar4 = (int *)FUN_005c9400();
        *(uint *)(*piVar4 + 0x10) = in_stack_00005d15;
        *(undefined2 *)(in_ECX + 0x76) = 0xffff;
      }
      FUN_00548330();
      FUN_00531f30();
      if (DAT_00b19acc != 0) {
        iVar2 = FUN_0072be50();
        if (iVar2 == 3) {
          DAT_00b19acc = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (in_stack_0000b9fe & 0xff) + 4;
        if (DAT_00b19acc != 0) {
          iVar2 = FUN_0072be50();
          if (iVar2 == 3) {
            DAT_00b19acc = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (in_stack_00011727 & 0xff) + 0xc;
        }
      }
      FUN_005c52a0();
    }
    FUN_00531f30();
    if (DAT_00b19acc != 0) {
      iVar2 = FUN_0072be50();
      if (iVar2 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x80) + 0xc;
    }
    FUN_00531f30();
    FUN_004ec100();
    return 1;
  }
  return 0;
}



// ?SetYAngle@MobileWallHug@@UAEXM@Z @ 0x005c86e0

void _SetYAngle_MobileWallHug__UAEXM_Z(undefined4 param_1)

{
  undefined2 uVar1;
  int in_ECX;
  
  _SetYAngle_Object__UAEXM_Z(param_1);
  uVar1 = FUN_006de9e0(param_1);
  *(undefined2 *)(in_ECX + 0x5c) = uVar1;
  return;
}



// ?SetSpeed@MobileWallHug@@UAEXH@Z @ 0x005c8c60

void _SetSpeed_MobileWallHug__UAEXH_Z(int param_1)

{
  int in_ECX;
  
  if (param_1 < 0) {
    *(undefined2 *)(in_ECX + 0x5a) = 0;
    return;
  }
  if (0xffff < param_1) {
    param_1 = 0xffff;
  }
  *(short *)(in_ECX + 0x5a) = (short)param_1;
  return;
}



