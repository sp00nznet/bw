// Decompiled functions for class: GFootpathNode
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?GetDebugText@GFootpathNode@@UAEPADXZ @ 0x0050a0f0

char * _GetDebugText_GFootpathNode__UAEPADXZ(void)

{
  return s_Footpath_node__00b17384;
}



// ?ToBeDeleted@GFootpathNode@@UAEXH@Z @ 0x0050d060

void _ToBeDeleted_GFootpathNode__UAEXH_Z(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *in_ECX;
  
  while (puVar1 = (undefined4 *)in_ECX[10], puVar1 != (undefined4 *)0x0) {
    iVar2 = puVar1[1];
    puVar4 = (undefined4 *)0x0;
    while (puVar3 = puVar4, puVar4 = puVar1, puVar4 != (undefined4 *)0x0) {
      puVar1 = (undefined4 *)*puVar4;
      if (puVar4[1] == iVar2) {
        if (puVar4 == (undefined4 *)in_ECX[10]) {
          in_ECX[10] = (int)puVar1;
        }
        else {
          *puVar3 = puVar1;
        }
        in_ECX[0xb] = in_ECX[0xb] + -1;
        FUN_007290de(puVar4);
        puVar4 = puVar3;
      }
    }
  }
  (**(code **)(*in_ECX + 8))();
  return;
}



// ?Load@GFootpathNode@@UAEIAAVGameOSFile@@@Z @ 0x0050d300

undefined4 _Load_GFootpathNode__UAEIAAVGameOSFile___Z(int param_1)

{
  byte *pbVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  int in_ECX;
  undefined4 *puVar5;
  int in_stack_0000ba1e;
  uint in_stack_0000ba26;
  
  iVar3 = FUN_0053e9f0();
  if (iVar3 == 0) {
    return 0;
  }
  if (DAT_00b19acc != 0) {
    iVar3 = FUN_0072be50();
    if (iVar3 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x18) + 0xc;
  }
  pbVar1 = (byte *)(in_ECX + 0x14);
  if (DAT_00b19acc != 0) {
    iVar3 = FUN_0072be50();
    if (iVar3 == 3) {
      DAT_00b19acc = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *pbVar1 + 1;
  }
  if (*(int *)(param_1 + 0x10c) == 0) {
    if (DAT_00b19acc != 0) {
      iVar3 = FUN_0072be50();
      if (iVar3 == 3) {
        DAT_00b19acc = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + (in_stack_0000ba26 & 0xff) + 4;
      if (0 < (int)in_stack_0000ba26) {
        do {
          FUN_00531f30();
          if (in_stack_0000ba1e != 0) {
            puVar4 = operator_new(8);
            if (puVar4 != (undefined4 *)0x0) {
              puVar4[1] = in_stack_0000ba1e;
              *puVar4 = 0;
              puVar2 = *(undefined4 **)(in_ECX + 0x28);
              if (*(undefined4 **)(in_ECX + 0x28) == (undefined4 *)0x0) {
LAB_0050d42f:
                *(undefined4 **)(in_ECX + 0x28) = puVar4;
              }
              else {
                do {
                  puVar5 = puVar2;
                  puVar2 = (undefined4 *)*puVar5;
                } while ((undefined4 *)*puVar5 != (undefined4 *)0x0);
                if (puVar5 == (undefined4 *)0x0) goto LAB_0050d42f;
                *puVar5 = puVar4;
              }
              *(int *)(in_ECX + 0x2c) = *(int *)(in_ECX + 0x2c) + 1;
            }
          }
          in_stack_0000ba26 = in_stack_0000ba26 - 1;
          if ((int)in_stack_0000ba26 < 1) {
            return 1;
          }
        } while( true );
      }
    }
  }
  else {
    *pbVar1 = *pbVar1 & 0xf3;
  }
  return 1;
}



// ?Save@GFootpathNode@@UAEIAAVGameOSFile@@@Z @ 0x0050d460

undefined4 _Save_GFootpathNode__UAEIAAVGameOSFile___Z(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int in_ECX;
  
  iVar2 = FUN_0053e8e0(param_1);
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = 0;
  if (DAT_00b19ac8 != 0) {
    iVar3 = FUN_0072be90((byte *)(in_ECX + 0x18),0xc,0);
    if (iVar3 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x18) + 0xc;
    if (DAT_00b19ac8 != 0) {
      iVar3 = FUN_0072be90((byte *)(in_ECX + 0x14),1,0);
      if (iVar3 == 3) {
        DAT_00b19ac8 = 0;
      }
      *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x14) + 1;
    }
  }
  if ((*(int *)(param_1 + 0x10c) == 0) && (DAT_00b19ac8 != 0)) {
    iVar3 = *(int *)(in_ECX + 0x2c);
    iVar4 = FUN_0072be90((byte *)(in_ECX + 0x2c),4,0);
    if (iVar4 == 3) {
      DAT_00b19ac8 = 0;
    }
    *(uint *)(param_1 + 0x214) = *(int *)(param_1 + 0x214) + *(byte *)(in_ECX + 0x2c) + 4;
    for (puVar1 = *(undefined4 **)(in_ECX + 0x28); puVar1 != (undefined4 *)0x0;
        puVar1 = (undefined4 *)*puVar1) {
      iVar2 = iVar2 + 1;
      if (iVar3 < iVar2) goto LAB_0050d56d;
      if (DAT_00b19ac8 == 0) {
        return 1;
      }
      FUN_00531bc0(puVar1[1]);
    }
    if ((DAT_00b19ac8 != 0) && (iVar2 != iVar3)) {
LAB_0050d56d:
      DAT_00b19ac8 = 0;
    }
  }
  return 1;
}



