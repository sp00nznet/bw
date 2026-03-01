#pragma once
// PSysGeom — particle system geometry function types
// Struct layout from bw1-decomp (PSysGeom.h)
//
// 3 FuncT subclasses (all 0x4 bytes)

#include "FuncT.h"

struct TestFunnel : public FuncT {
    void Eval(float param_1, float* param_2, float* param_3) const override;
};
static_assert(sizeof(TestFunnel) == 0x4, "TestFunnel size mismatch");

struct TestFunnelParab : public FuncT {
    void Eval(float param_1, float* param_2, float* param_3) const override;
};
static_assert(sizeof(TestFunnelParab) == 0x4, "TestFunnelParab size mismatch");

struct TestFunnelSpout : public FuncT {
    void Eval(float param_1, float* param_2, float* param_3) const override;
};
static_assert(sizeof(TestFunnelSpout) == 0x4, "TestFunnelSpout size mismatch");
