// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"

class Vtop__Syms;

class Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    CData/*3:0*/ top__DOT__ALUCtrl;
    CData/*1:0*/ top__DOT__ResultSrc;
    CData/*1:0*/ top__DOT__MemType;
    CData/*0:0*/ top__DOT__MemSign;
    CData/*2:0*/ top__DOT__Branch;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*0:0*/ __Vclklast__TOP__rst;
    VL_OUT(a0,31,0);
    IData/*31:0*/ top__DOT__Instr;
    IData/*31:0*/ top__DOT__RD2;
    IData/*31:0*/ top__DOT__ALUResult;
    IData/*31:0*/ top__DOT__RDM;
    IData/*31:0*/ top__DOT__fetch__DOT__PC;
    IData/*31:0*/ top__DOT__fetch__DOT__pc__DOT__next_PC;
    IData/*31:0*/ top__DOT__execute__DOT__PC_TargetE;
    IData/*31:0*/ top__DOT__memory__DOT__datamem__DOT__Write_Data;
    VlUnpacked<CData/*7:0*/, 4096> top__DOT__fetch__DOT__instruction_memory__DOT__rom_mem;
    VlUnpacked<IData/*31:0*/, 32> top__DOT__decode__DOT__regfile__DOT__regs;
    VlUnpacked<CData/*7:0*/, 131072> top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
