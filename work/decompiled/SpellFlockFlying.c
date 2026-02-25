// Decompiled functions for class: SpellFlockFlying
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetSaveType@SpellFlockFlying@@UAEIXZ @ 0x0052e790

undefined4 _GetSaveType_SpellFlockFlying__UAEIXZ(void)

{
  return 0xd;
}



// ?GetDebugText@SpellFlockFlying@@UAEPADXZ @ 0x0052e7a0

char * _GetDebugText_SpellFlockFlying__UAEPADXZ(void)

{
  return s_SpellFlockFlying__00b1a364;
}



// ?GetParticleType@SpellFlockFlying@@UAEXXZ @ 0x006ba930

undefined4 _GetParticleType_SpellFlockFlying__UAEXXZ(void)

{
  float fVar1;
  int iVar2;
  int *in_ECX;
  
  iVar2 = (**(code **)(*in_ECX + 0x1c))();
  fVar1 = *(float *)(*(int *)(iVar2 + 0x60) + 8);
  iVar2 = FUN_006c4230();
  if (fVar1 < *(float *)(iVar2 + 0x5c)) {
    return 0x7d;
  }
  return 0x7c;
}



// ?Process@SpellFlockFlying@@UAEIXZ @ 0x006baac0

void _Process_SpellFlockFlying__UAEIXZ(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int *piVar6;
  undefined4 *puVar7;
  int *in_ECX;
  float10 fVar8;
  undefined4 uVar9;
  undefined1 local_98 [12];
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined1 local_6c;
  undefined4 local_68;
  int *local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int local_54;
  int local_50;
  float local_4c;
  int local_48;
  int *local_44;
  float local_40;
  int local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  float local_1c;
  int local_18;
  int local_14;
  float local_10;
  float local_c;
  float local_8;
  
  if (((in_ECX[0x3d] != 0) && (iVar1 = *(int *)(in_ECX[0x3d] + 0x40), iVar1 != 0)) &&
     (iVar1 = *(int *)(iVar1 + 8), iVar1 != 0)) {
    in_ECX[5] = *(int *)(iVar1 + 0x14);
    in_ECX[6] = *(int *)(iVar1 + 0x18);
    in_ECX[7] = *(int *)(iVar1 + 0x1c);
  }
  local_3c = FUN_006c4230();
  iVar1 = (**(code **)(*in_ECX + 0x55c))();
  if (in_ECX[0x3e] < iVar1) {
    local_40 = (float)in_ECX[0x3f];
    fVar8 = (float10)(**(code **)(*in_ECX + 0x558))();
    local_48 = DAT_00c22d78;
    local_44 = (int *)0x0;
    iVar1 = in_ECX[0x40];
    local_50 = in_ECX[0x41];
    local_4c = (float)in_ECX[0x42];
    in_ECX[0x3f] = (int)(float)(fVar8 * (float10)DAT_00c22d78 * (float10)0.001 +
                               (float10)(float)in_ECX[0x3f]);
    local_54 = iVar1;
    iVar2 = __ftol();
    in_ECX[0x40] = iVar2;
    iVar2 = __ftol();
    in_ECX[0x41] = iVar2;
    FUN_0043a5e0(in_ECX[0x1c],in_ECX[0x1e]);
    local_8 = (float)in_ECX[0x1d];
    fVar8 = (float10)FUN_00760fd0();
    in_ECX[0x42] = (int)(float)((float10)local_8 - fVar8);
    local_8 = (float)in_ECX[0x3e];
    if ((float)(int)local_8 < (float)in_ECX[0x3f]) {
      local_64 = &local_2c;
      local_44 = &local_28;
      do {
        in_ECX[0x3e] = (int)local_8 + 1;
        iVar2 = (**(code **)(*in_ECX + 0x1c))();
        iVar3 = 0x15;
        if (*(float *)(local_3c + 0x5c) <= *(float *)(*(int *)(iVar2 + 0x60) + 8)) {
          iVar3 = 0x14;
        }
        local_8 = ((float)in_ECX[0x3e] - local_40) / ((float)in_ECX[0x3f] - local_40);
        *local_64 = (int)ROUND((float)(in_ECX[0x40] - iVar1) * local_8);
        local_24 = local_2c + iVar1;
        local_c = (float)(in_ECX[0x41] - local_50) * local_8;
        *local_44 = (int)ROUND(local_c);
        local_20 = local_50 + local_28;
        local_18 = local_24;
        local_1c = ((float)in_ECX[0x42] - local_4c) * local_8 + local_4c;
        local_14 = local_20;
        local_10 = local_1c;
        if (in_ECX[0x3e] != 0) {
          FUN_0067bcb0(0x3e4ccccd,s_C__dev_black_SpellFlock_cpp_00b456c8,0x1cf);
          local_18 = __ftol();
          FUN_0067bcb0(0x3e4ccccd,s_C__dev_black_SpellFlock_cpp_00b456c8,0x1d0);
          local_14 = __ftol();
        }
        iVar1 = FUN_005c04c0();
        if (iVar1 != 0) {
          iVar1 = FUN_006b74b0();
          if (iVar1 != 0) {
            uVar4 = (**(code **)(*in_ECX + 0x1c))();
            fVar8 = (float10)FUN_0058ddc0(in_ECX + 5,uVar4,0,0,1);
            if (fVar8 <= (float10)0.0) goto LAB_006bafae;
          }
          local_38 = 0;
          local_34 = 0;
          local_30 = 0;
          iVar1 = FUN_006ba470(&local_24,&local_38);
          if (iVar1 == 1) {
            local_30 = *(undefined4 *)(iVar3 * 0x2cc + 0xb6eb68);
            piVar5 = (int *)FUN_00416240(&local_18,&DAT_00b6e8f0 + iVar3 * 0xb3,0,in_ECX[0x3d],0);
            if (piVar5 != (int *)0x0) {
              (**(code **)(*piVar5 + 0xfc))(&local_18);
              iVar1 = *piVar5;
              fVar8 = (float10)FUN_0067bcb0(0x3e4cccd0,s_C__dev_black_SpellFlock_cpp_00b456c8,0x1ea)
              ;
              local_c = (float)fVar8;
              fVar8 = (float10)(**(code **)(*in_ECX + 0x120))();
              (**(code **)(iVar1 + 0x124))((float)(fVar8 * (float10)2.8 + (float10)local_c));
              uVar4 = FUN_006de3b0(&local_18,&local_38);
              FUN_005c86b0(uVar4);
              piVar6 = operator_new(8);
              if (piVar6 != (int *)0x0) {
                iVar1 = in_ECX[0x3b];
                piVar6[1] = (int)piVar5;
                *piVar6 = iVar1;
                in_ECX[0x3b] = (int)piVar6;
                in_ECX[0x3c] = in_ECX[0x3c] + 1;
              }
              DAT_00b203d4 = 1;
              if ((in_ECX[0x2c] != 0) &&
                 (iVar1 = _AttitudeToCreatureEating_GameThingWithPos__UAEIXZ(),
                 in_ECX[0x3e] % iVar1 == 0)) {
                (**(code **)(*(int *)in_ECX[0x2c] + 0x114))(piVar5);
              }
            }
            if (((in_ECX[0x3d] != 0) && (iVar1 = *(int *)(in_ECX[0x3d] + 0x40), iVar1 != 0)) &&
               (piVar6 = *(int **)(iVar1 + 8), piVar6 != (int *)0x0)) {
              if (piVar6 == piVar5) {
                (**(code **)(*piVar6 + 0x168))(&local_60);
                puVar7 = (undefined4 *)FUN_005c0400(local_98);
                local_8c = 2;
                local_88 = *puVar7;
                local_84 = puVar7[1];
                local_80 = puVar7[2];
                local_74 = local_58;
                local_7c = local_60;
                local_78 = local_5c;
                local_70 = 0x3f800000;
                local_6c = 0;
                local_68 = 0;
                (**(code **)(*in_ECX + 0x52c))(&local_8c);
                FUN_005b0de0(&local_38,0x1f);
                (**(code **)(*piVar5 + 0x934))(0,0x2c);
                *(undefined4 *)(in_ECX[0x3d] + 0x78) = 0x2d;
                *(undefined4 *)(in_ECX[0x3d] + 0x80) = 3;
                *(undefined4 *)(in_ECX[0x3d] + 0x7c) = 0x2b;
              }
              else {
                uVar9 = 0x1f;
                uVar4 = (**(code **)(*piVar6 + 0x860))(0x1f);
                FUN_005b0de0(uVar4,uVar9);
                (**(code **)(*piVar5 + 0x934))(0,0x2c);
              }
            }
          }
        }
LAB_006bafae:
        local_8 = (float)in_ECX[0x3e];
        iVar1 = local_54;
        if ((float)in_ECX[0x3f] <= (float)(int)local_8) {
          _Process_SpellFlock__UAEIXZ();
          return;
        }
      } while( true );
    }
  }
  else if ((int *)in_ECX[0x44] != (int *)0x0) {
    (**(code **)(*(int *)in_ECX[0x44] + 0x118))();
  }
  _Process_SpellFlock__UAEIXZ();
  return;
}



// ?Draw@SpellFlockFlying@@UAEXXZ @ 0x006bb000

void _Draw_SpellFlockFlying__UAEXXZ(void)

{
  int *piVar1;
  int iVar2;
  int in_ECX;
  int iVar3;
  
  if (*(int *)(in_ECX + 0x110) != 0) {
    iVar3 = DAT_00dc8d20;
    if (DAT_00dc8d20 < 2) {
      iVar3 = 1;
    }
    iVar2 = FUN_00527d30();
    (**(code **)(**(int **)(in_ECX + 0x110) + 0x11c))
              (*(undefined4 *)(*(int *)(iVar2 + 0x3a0) + 0x4834));
    iVar3 = (**(code **)(**(int **)(in_ECX + 0x110) + 0xfc))(&stack0xffffffc0,iVar3);
    piVar1 = *(int **)(in_ECX + 0x110);
    if (iVar3 == 5) {
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 4))(1);
      }
      *(undefined4 *)(in_ECX + 0x110) = 0;
      _Draw_Spell__UAEXXZ();
      return;
    }
    (**(code **)(*piVar1 + 0x104))(0x3f800000,1);
  }
  _Draw_Spell__UAEXXZ();
  return;
}



// ?Load@SpellFlockFlying@@UAEIAAVGameOSFile@@@Z @ 0x006bb880

undefined4 _Load_SpellFlockFlying__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  undefined4 unaff_EBX;
  undefined4 unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = _Load_SpellFlock__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50((byte *)(in_ECX + 0x114),4,0,unaff_EDI,unaff_ESI,unaff_EBX);
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
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x118) + 4;
    }
    if (DAT_00b19acc != 0) {
      iVar1 = FUN_0072be50();
      if (iVar1 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x11c) + 1;
    }
    return 1;
  }
  return 0;
}



// ?Save@SpellFlockFlying@@UAEIAAVGameOSFile@@@Z @ 0x006bb970

undefined4 _Save_SpellFlockFlying__UAEIAAVGameOSFile___Z(int param_1)

{
  int iVar1;
  int in_ECX;
  
  iVar1 = _Save_SpellFlock__UAEIAAVGameOSFile___Z(param_1);
  if (iVar1 != 0) {
    if (DAT_00b19ac8 != 0) {
      iVar1 = FUN_0072be90((byte *)(in_ECX + 0x114),4,0);
      if (iVar1 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x114) + 4;
      if (DAT_00b19ac8 != 0) {
        iVar1 = FUN_0072be90((byte *)(in_ECX + 0x118),4,0);
        if (iVar1 == 3) {
          DAT_00b19ac8 = 0;
        }
        *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x118) + 4;
        if (DAT_00b19ac8 != 0) {
          iVar1 = FUN_0072be90((byte *)(in_ECX + 0x11c),1,0);
          if (iVar1 == 3) {
            DAT_00b19ac8 = 0;
          }
          *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x11c) + 1;
        }
      }
    }
    return 1;
  }
  return 0;
}



