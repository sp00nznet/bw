// Decompiled functions for class: VCreatureLessonChooser
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// ?$EditorIconButton@VCreatureLessonChooser@@_vf1 @ 0x004b3a60

undefined4 __EditorIconButton_VCreatureLessonChooser___vf1(void)

{
  int iVar1;
  int *in_ECX;
  
  in_ECX[0xd] = 0;
  in_ECX[0xe] = 0;
  in_ECX[0xf] = 1;
  iVar1 = (**(code **)(*in_ECX + 0x48))();
  if (iVar1 != 0) {
    if ((code *)in_ECX[0x57] != (code *)0x0) {
      (*(code *)in_ECX[0x57])();
    }
    if ((DAT_00d5c400 & 1) != 0) {
      in_ECX[0xd] = 1;
      DAT_00d5c400 = DAT_00d5c400 & 0xfe;
      if (in_ECX[0x54] == 0) {
        (*(code *)in_ECX[0x55])(in_ECX[0x52]);
      }
      else {
        (*(code *)in_ECX[0x56])(in_ECX[0x52],in_ECX[0x58]);
      }
    }
    if ((DAT_00d5c400 & 2) != 0) {
      in_ECX[0xe] = 1;
      DAT_00d5c400 = DAT_00d5c400 & 0xfd;
    }
    return 1;
  }
  return 0;
}



// ?$EditorIconButton@VCreatureLessonChooser@@_vf2 @ 0x004f9aa0

void __EditorIconButton_VCreatureLessonChooser___vf2(void)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int *in_ECX;
  int *piVar4;
  
  iVar2 = (**(code **)(*in_ECX + 0xc))();
  piVar4 = in_ECX + 8;
  if (iVar2 == 0) {
    piVar4 = in_ECX + 9;
  }
  (**(code **)(*in_ECX + 0x3c))(0);
  puVar1 = (undefined4 *)*in_ECX;
  uVar3 = (*(code *)*puVar1)();
  (*(code *)puVar1[4])(piVar4,uVar3);
  if (in_ECX[0x11] != -1) {
    iVar2 = (**(code **)(*in_ECX + 0xc))();
    if ((iVar2 != 0) && (in_ECX[0x11] != 0x199)) {
      FUN_004f9870(in_ECX[0x11],1);
    }
  }
  return;
}



