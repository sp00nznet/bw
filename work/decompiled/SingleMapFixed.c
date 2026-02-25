// Decompiled functions for class: SingleMapFixed
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?RemoveMapObject@SingleMapFixed@@UAEXXZ @ 0x005048f0

void _RemoveMapObject_SingleMapFixed__UAEXXZ(void)

{
  _RemoveMapObject_Fixed__UAEXXZ();
  FUN_00505840();
  return;
}



// ?InsertMapObject@SingleMapFixed@@UAEXXZ @ 0x00504910

void _InsertMapObject_SingleMapFixed__UAEXXZ(void)

{
  int iVar1;
  int *in_ECX;
  
  iVar1 = (**(code **)(*in_ECX + 0x178))();
  if (iVar1 == 0) {
    (**(code **)(*in_ECX + 0x864))();
  }
  _InsertMapObject_Fixed__UAEXXZ();
  return;
}



// ?InsertMapObjectToCell@SingleMapFixed@@UAEXPAUMapCell@@@Z @ 0x005055f0

void _InsertMapObjectToCell_SingleMapFixed__UAEXPAUMapCell___Z(undefined4 param_1)

{
  _InsertMapObjectToCell_Fixed__UAEXPAUMapCell___Z(param_1);
  return;
}



// ?ValidToApplyThisToMapCoord@SingleMapFixed@@UAEIPAVGInterfaceStatus@@ABUMapCoords@@@Z @ 0x006dd200

undefined4
_ValidToApplyThisToMapCoord_SingleMapFixed__UAEIPAVGInterfaceStatus__ABUMapCoords___Z
          (undefined4 param_1,int *param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int *in_ECX;
  float unaff_EBX;
  float10 fVar6;
  float10 fVar7;
  int unaff_retaddr;
  undefined1 *puVar8;
  undefined1 auStack_17c [16];
  LH_SamplePlayOptions aLStack_16c [4];
  undefined4 uStack_168;
  undefined4 uStack_164;
  undefined4 uStack_160;
  undefined4 uStack_148;
  undefined4 uStack_13c;
  undefined4 uStack_138;
  undefined4 uStack_134;
  
  iVar2 = FUN_007344da(param_2,0,&Object::RTTI_Type_Descriptor,&WorshipTotem::RTTI_Type_Descriptor,0
                      );
  if (iVar2 == 0) {
    if (((param_2 != (int *)0x0) && (iVar2 = (**(code **)(*param_2 + 0x680))(1), iVar2 != 0)) &&
       (iVar2 = (**(code **)(*param_2 + 0x684))(), iVar2 != 0)) {
      return 3;
    }
  }
  else if ((*(byte *)((int)in_ECX + 0x25) & 0x40) == 0) {
    fVar6 = (float10)(**(code **)(*in_ECX + 0x5c0))();
    iVar2 = *(int *)(iVar2 + 0x100);
    fVar7 = (float10)(**(code **)(*in_ECX + 0x11c))();
    *(float *)(iVar2 + 0xf0) =
         (float)(fVar7 * (float10)(float)fVar6 + (float10)*(float *)(iVar2 + 0xf0));
    *(float *)(iVar2 + 0xf4) = (float)(fVar7 * (float10)(float)fVar6) + *(float *)(iVar2 + 0xf4);
    FUN_005a5fa0();
    (**(code **)(*in_ECX + 0xc))(0);
    if (unaff_retaddr != 0) {
      uVar4 = *(undefined4 *)(unaff_retaddr + 200);
      uVar5 = *(undefined4 *)(unaff_retaddr + 0xcc);
      uVar1 = *(undefined4 *)(unaff_retaddr + 0xd0);
      LH_SamplePlayOptions::LH_SamplePlayOptions(aLStack_16c);
      uStack_168 = *(undefined4 *)(DAT_00bf4e68 + 0x3ac);
      uStack_148 = 0xb3;
      uStack_164 = 1;
      uStack_160 = 0;
      uStack_13c = uVar4;
      uStack_138 = uVar5;
      uStack_134 = uVar1;
      FUN_00423db0();
      LH_SamplePlayOptions::~LH_SamplePlayOptions(aLStack_16c);
    }
    iVar2 = FUN_00527d60();
    if (unaff_retaddr == iVar2) {
      puVar3 = (undefined4 *)FUN_00746d70(0xa0,s_C__dev_black_Tree_cpp_00b45f10,0x3d0);
      if (puVar3 != (undefined4 *)0x0) {
        *puVar3 = &PTR_LAB_008049b4;
        puVar3[5] = 0;
        puVar3[6] = 0;
        puVar3[1] = DAT_00df8148;
        DAT_00df8148 = puVar3;
      }
      FUN_00733e17(auStack_17c,s__3_0f_00b20738,(double)unaff_EBX);
      FUN_00527d30();
      uVar4 = FUN_005c0400();
      puVar8 = &stack0xfffffe74;
      uVar5 = FUN_00789090(auStack_17c,puVar8);
      FUN_0078c9f0(uVar4,uVar5,puVar8);
    }
    return 3;
  }
  return 0;
}



