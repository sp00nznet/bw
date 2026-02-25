// Decompiled functions for class: TreeFv
// Source: Black & White v1.0 (runblack_decrypted.exe)
// Auto-decompiled by Ghidra 12.0.3

// _GetForest__4TreeFv @ 0x006dda00

void _GetForest__4TreeFv(void)

{
  int iVar1;
  int *in_ECX;
  undefined1 auStack_30 [32];
  undefined1 auStack_10 [16];
  
  FUN_00505840();
  (**(code **)(*in_ECX + 0x63c))(auStack_30);
  iVar1 = FUN_00746d70(4,s_C__dev_black_Tree_cpp_00b45f10,0x49a);
  if (iVar1 != 0) {
    iVar1 = FUN_00783040(auStack_10,0x3e99999a);
    in_ECX[0x16] = iVar1;
    return;
  }
  in_ECX[0x16] = 0;
  return;
}



