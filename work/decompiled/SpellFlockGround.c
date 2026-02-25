// Decompiled functions for class: SpellFlockGround
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetDebugText@SpellFlockGround@@UAEPADXZ @ 0x0052e7e0

char * _GetDebugText_SpellFlockGround__UAEPADXZ(void)

{
  return s_SpellFlockGround__00b1a378;
}



// ?GetSaveType@SpellFlockGround@@UAEIXZ @ 0x005ba530

undefined4 _GetSaveType_SpellFlockGround__UAEIXZ(void)

{
  return 0xe;
}



// ?Process@SpellFlockGround@@UAEIXZ @ 0x006bb150

void _Process_SpellFlockGround__UAEIXZ(void)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  int *in_ECX;
  float10 fVar6;
  float fVar7;
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
  undefined4 local_3c;
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
  undefined4 local_10;
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
    fVar6 = (float10)(**(code **)(*in_ECX + 0x558))();
    local_48 = DAT_00c22d78;
    local_44 = (int *)0x0;
    local_54 = in_ECX[0x40];
    local_50 = in_ECX[0x41];
    local_4c = (float)in_ECX[0x42];
    in_ECX[0x3f] = (int)(float)(fVar6 * (float10)DAT_00c22d78 * (float10)0.001 +
                               (float10)(float)in_ECX[0x3f]);
    iVar1 = __ftol();
    in_ECX[0x40] = iVar1;
    iVar1 = __ftol();
    in_ECX[0x41] = iVar1;
    FUN_0043a5e0(in_ECX[0x1c],in_ECX[0x1e]);
    local_8 = (float)in_ECX[0x1d];
    fVar6 = (float10)FUN_00760fd0();
    in_ECX[0x42] = (int)(float)((float10)local_8 - fVar6);
    local_8 = (float)in_ECX[0x3e];
    if ((float)(int)local_8 < (float)in_ECX[0x3f]) {
      local_64 = &local_2c;
      local_44 = &local_28;
      do {
        in_ECX[0x3e] = (int)local_8 + 1;
        local_8 = ((float)((int)local_8 + 1) - local_40) / ((float)in_ECX[0x3f] - local_40);
        *local_64 = (int)ROUND((float)(in_ECX[0x40] - local_54) * local_8);
        local_24 = local_2c + local_54;
        local_c = (float)(in_ECX[0x41] - local_50) * local_8;
        *local_44 = (int)ROUND(local_c);
        local_20 = local_50 + local_28;
        local_1c = ((float)in_ECX[0x42] - local_4c) * local_8 + local_4c;
        local_18 = local_24;
        local_10 = 0;
        local_14 = local_20;
        if (in_ECX[0x3e] != 0) {
          FUN_0067bcb0(0x3e4ccccd,s_C__dev_black_SpellFlock_cpp_00b456c8,0x2a2);
          local_18 = __ftol();
          FUN_0067bcb0(0x3e4ccccd,s_C__dev_black_SpellFlock_cpp_00b456c8,0x2a3);
          local_14 = __ftol();
        }
        iVar1 = FUN_005c04c0();
        if (iVar1 != 0) {
          iVar1 = FUN_006b74b0();
          if (iVar1 != 0) {
            uVar2 = (**(code **)(*in_ECX + 0x1c))();
            fVar6 = (float10)FUN_0058ddc0(in_ECX + 5,uVar2,0,0,1);
            if (fVar6 <= (float10)0.0) goto LAB_006bb5fc;
          }
          local_38 = 0;
          local_34 = 0;
          local_30 = 0;
          iVar1 = FUN_006ba470(&local_24,&local_38);
          if (iVar1 == 1) {
            local_30 = 0;
            piVar3 = (int *)FUN_00416240(&local_18,&DAT_00b72678,0,in_ECX[0x3d],0);
            if (piVar3 != (int *)0x0) {
              iVar1 = *piVar3;
              uVar2 = (**(code **)(*in_ECX + 0x1c))();
              (**(code **)(iVar1 + 0x20))(uVar2);
              iVar1 = *piVar3;
              fVar6 = (float10)FUN_0067bcb0(0x3f000000,s_C__dev_black_SpellFlock_cpp_00b456c8,0x2bd)
              ;
              local_c = (float)fVar6;
              fVar6 = (float10)(**(code **)(*in_ECX + 0x120))();
              (**(code **)(iVar1 + 0x124))((float)(fVar6 * (float10)1.5 + (float10)local_c));
              uVar2 = FUN_006de3b0(&local_18,&local_38);
              FUN_005c86b0(uVar2);
              piVar4 = operator_new(8);
              if (piVar4 != (int *)0x0) {
                iVar1 = in_ECX[0x3b];
                piVar4[1] = (int)piVar3;
                *piVar4 = iVar1;
                in_ECX[0x3b] = (int)piVar4;
                in_ECX[0x3c] = in_ECX[0x3c] + 1;
              }
              FUN_005efc00(&local_18,9,0x3f800000,0);
              DAT_00b203d4 = 1;
              if ((int *)in_ECX[0x2c] != (int *)0x0) {
                (**(code **)(*(int *)in_ECX[0x2c] + 0x114))(piVar3);
              }
              local_8 = (float)FUN_007344da(piVar3,0,&Animal::RTTI_Type_Descriptor,
                                            &SpellWolf::RTTI_Type_Descriptor,0);
              if (((in_ECX[0x3d] != 0) && (iVar1 = *(int *)(in_ECX[0x3d] + 0x40), iVar1 != 0)) &&
                 ((piVar4 = *(int **)(iVar1 + 8), piVar4 != (int *)0x0 && (local_8 != 0.0)))) {
                if (piVar4 == piVar3) {
                  (**(code **)(*piVar4 + 0x168))(&local_60);
                  puVar5 = (undefined4 *)FUN_005c0400(local_98);
                  local_8c = 2;
                  local_88 = *puVar5;
                  local_84 = puVar5[1];
                  local_80 = puVar5[2];
                  local_78 = local_5c;
                  local_7c = local_60;
                  local_74 = local_58;
                  local_70 = 0x3f800000;
                  local_6c = 0;
                  local_68 = 0;
                  (**(code **)(*in_ECX + 0x52c))(&local_8c);
                  fVar6 = (float10)FUN_006ba090();
                  puVar5 = &local_38;
                  fVar7 = (float)fVar6;
                }
                else {
                  fVar6 = (float10)FUN_006ba090();
                  fVar7 = (float)fVar6;
                  puVar5 = (undefined4 *)(**(code **)(*piVar4 + 0x860))(fVar7);
                }
                FUN_0041bde0(&local_24,puVar5,fVar7);
              }
            }
          }
        }
LAB_006bb5fc:
        local_8 = (float)in_ECX[0x3e];
      } while ((float)(int)local_8 < (float)in_ECX[0x3f]);
    }
  }
  _Process_SpellFlock__UAEIXZ();
  return;
}



// ?Load@SpellFlockGround@@UAEIAAVGameOSFile@@@Z @ 0x006bba60

bool _Load_SpellFlockGround__UAEIAAVGameOSFile___Z(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _Load_SpellFlock__UAEIAAVGameOSFile___Z(param_1);
  return iVar1 != 0;
}



// ?Save@SpellFlockGround@@UAEIAAVGameOSFile@@@Z @ 0x006bba80

bool _Save_SpellFlockGround__UAEIAAVGameOSFile___Z(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = _Save_SpellFlock__UAEIAAVGameOSFile___Z(param_1);
  return iVar1 != 0;
}



