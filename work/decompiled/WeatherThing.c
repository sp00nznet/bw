// Decompiled functions for class: WeatherThing
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetText@WeatherThing@@UAEPBDXZ @ 0x0052ef40

char * _GetText_WeatherThing__UAEPBDXZ(void)

{
  return s_Weather_Thing_00b1a4bc;
}



// ?GetSaveType@WeatherThing@@UAEIXZ @ 0x0052ef50

undefined4 _GetSaveType_WeatherThing__UAEIXZ(void)

{
  return 0x43;
}



// ?GetDebugText@WeatherThing@@UAEPADXZ @ 0x0052ef60

char * _GetDebugText_WeatherThing__UAEPADXZ(void)

{
  return s_WeatherThing__00b1a4cc;
}



// ?ToBeDeleted@WeatherThing@@UAEXH@Z @ 0x007010d0

void _ToBeDeleted_WeatherThing__UAEXH_Z(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int in_ECX;
  
  iVar3 = DAT_00c22ca4;
  iVar1 = *(int *)(DAT_00c22ca4 + 0x201d10);
  if (iVar1 == in_ECX) {
    *(int *)(DAT_00c22ca4 + 0x201d10) = *(int *)(in_ECX + 0x80);
  }
  else {
    do {
      iVar2 = iVar1;
      if (iVar2 == 0) goto LAB_0070111d;
      iVar1 = *(int *)(iVar2 + 0x80);
    } while (*(int *)(iVar2 + 0x80) != in_ECX);
    *(undefined4 *)(iVar2 + 0x80) = *(undefined4 *)(in_ECX + 0x80);
  }
  *(int *)(iVar3 + 0x201d14) = *(int *)(iVar3 + 0x201d14) + -1;
  *(undefined4 *)(in_ECX + 0x80) = 0;
LAB_0070111d:
  FUN_007010b0();
  _ToBeDeleted_GameThingWithPos__UAEXH_Z(param_1);
  return;
}



// ?SetPos@WeatherThing@@UAEXPBUMapCoords@@@Z @ 0x00701280

void _SetPos_WeatherThing__UAEXPBUMapCoords___Z(int *param_1)

{
  int iVar1;
  float fVar2;
  int in_ECX;
  float10 fVar3;
  
  iVar1 = *(int *)(in_ECX + 0x78);
  if (iVar1 != 0) {
    fVar2 = (float)param_1[2];
    fVar3 = (float10)FUN_00760fd0();
    *(float *)(iVar1 + 0xc) = (float)(fVar3 + (float10)fVar2);
    *(float *)(iVar1 + 8) = (float)*param_1 * 0.00015258789;
    *(float *)(iVar1 + 0x10) = (float)param_1[1] * 0.00015258789;
  }
  *(int *)(in_ECX + 0x14) = *param_1;
  *(int *)(in_ECX + 0x18) = param_1[1];
  *(int *)(in_ECX + 0x1c) = param_1[2];
  return;
}



// ?SetSpeedInMetres@WeatherThing@@UAEXMH@Z @ 0x00701510

void _SetSpeedInMetres_WeatherThing__UAEXMH_Z(undefined4 param_1)

{
  int in_ECX;
  
  if (*(int *)(in_ECX + 0x78) != 0) {
    *(undefined4 *)(*(int *)(in_ECX + 0x78) + 0x68) = param_1;
  }
  return;
}



// ?Save@WeatherThing@@UAEIAAVGameOSFile@@@Z @ 0x00701550

undefined4 _Save_WeatherThing__UAEIAAVGameOSFile___Z(uint param_1)

{
  int iVar1;
  int iVar2;
  int in_ECX;
  byte *pbVar3;
  
  iVar1 = param_1;
  iVar2 = _Save_GameThingWithPos__UAEXPAUGameOSFile___Z(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  if (DAT_00b19ac8 != 0) {
    iVar2 = FUN_0072be90((byte *)(in_ECX + 0x28),0x50,0);
    if (iVar2 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x28) + 0x50;
  }
  param_1 = (uint)(*(int *)(in_ECX + 0x78) != 0);
  if (DAT_00b19ac8 != 0) {
    iVar2 = FUN_0072be90(&param_1,4,0);
    if (iVar2 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + (param_1 & 0xff) + 4;
  }
  if (*(int *)(in_ECX + 0x78) != 0) {
    if (DAT_00b19ac8 == 0) {
      return 1;
    }
    pbVar3 = (byte *)(*(int *)(in_ECX + 0x78) + 8);
    iVar2 = FUN_0072be90(pbVar3,0xc,0);
    if (iVar2 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *pbVar3 + 0xc;
    if (DAT_00b19ac8 == 0) {
      return 1;
    }
    pbVar3 = (byte *)(*(int *)(in_ECX + 0x78) + 8);
    iVar2 = FUN_0072be90(pbVar3,0x50,0);
    if (iVar2 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *pbVar3 + 0x50;
    if (DAT_00b19ac8 == 0) {
      return 1;
    }
    pbVar3 = (byte *)(*(int *)(in_ECX + 0x78) + 0x58);
    iVar2 = FUN_0072be90(pbVar3,4,0);
    if (iVar2 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *pbVar3 + 4;
    if (DAT_00b19ac8 == 0) {
      return 1;
    }
    pbVar3 = (byte *)(*(int *)(in_ECX + 0x78) + 0x68);
    iVar2 = FUN_0072be90(pbVar3,4,0);
    if (iVar2 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *pbVar3 + 4;
    if (DAT_00b19ac8 == 0) {
      return 1;
    }
    pbVar3 = (byte *)(*(int *)(in_ECX + 0x78) + 0x5c);
    iVar2 = FUN_0072be90(pbVar3,0xc,0);
    if (iVar2 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *pbVar3 + 0xc;
  }
  if (DAT_00b19ac8 != 0) {
    iVar2 = FUN_0072be90((byte *)(in_ECX + 0x7c),4,0);
    if (iVar2 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(iVar1 + 0x214) = *(int *)(iVar1 + 0x214) + *(byte *)(in_ECX + 0x7c) + 4;
  }
  return 1;
}



// ?Load@WeatherThing@@UAEIAAVGameOSFile@@@Z @ 0x00701770

undefined4 _Load_WeatherThing__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int in_ECX;
  int in_stack_00005d0d;
  uint in_stack_0000ba26;
  
  iVar1 = _Load_GameThingWithPos__QAEIAAVGameOSFile___Z();
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x28) + 0x50;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (in_stack_0000ba26 & 0xff) + 4;
      if (in_stack_0000ba26 != 0) {
        puVar2 = (undefined4 *)FUN_00746d70();
        if (puVar2 == (undefined4 *)0x0) {
          puVar2 = (undefined4 *)0x0;
        }
        else {
          FUN_00794160();
          *puVar2 = &vftable_GWeather;
        }
        if (DAT_00b19acc != 0) {
          iVar1 = FUN_0072be50();
          if (iVar1 == 3) {
            DAT_00b19acc = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(puVar2 + 2) + 0xc;
          if (DAT_00b19acc != 0) {
            iVar1 = FUN_0072be50();
            if (iVar1 == 3) {
              DAT_00b19acc = 0;
            }
            *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(puVar2 + 2) + 0x50;
          }
        }
        if (DAT_00b19acc != 0) {
          iVar1 = FUN_0072be50();
          if (iVar1 == 3) {
            DAT_00b19acc = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(puVar2 + 0x16) + 4;
        }
        if (DAT_00b19acc != 0) {
          iVar1 = FUN_0072be50();
          if (iVar1 == 3) {
            DAT_00b19acc = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(puVar2 + 0x1a) + 4;
        }
        if (DAT_00b19acc != 0) {
          iVar1 = FUN_0072be50();
          if (iVar1 == 3) {
            DAT_00b19acc = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(puVar2 + 0x17) + 0xc;
        }
        *(undefined4 **)(in_stack_00005d0d + 0x78) = puVar2;
        in_ECX = in_stack_00005d0d;
      }
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x7c) + 4;
    }
    return 1;
  }
  return 0;
}



