// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_ATTR_COLD void Vtop___024root___initial__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___initial__TOP__0\n"); );
    // Init
    VlWide<3>/*95:0*/ __Vtemp_h889989c9__0;
    VlWide<3>/*95:0*/ __Vtemp_h3a032bfe__0;
    // Body
    __Vtemp_h889989c9__0[0U] = 0x2e6d656dU;
    __Vtemp_h889989c9__0[1U] = 0x5f6d656dU;
    __Vtemp_h889989c9__0[2U] = 0x64617461U;
    VL_READMEM_N(true, 8, 131072, 0, VL_CVT_PACK_STR_NW(3, __Vtemp_h889989c9__0)
                 ,  &(vlSelf->top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array)
                 , 0x10000U, ~0ULL);
    VL_WRITEF("Loaded data_mem.\n");
    __Vtemp_h3a032bfe__0[0U] = 0x2e686578U;
    __Vtemp_h3a032bfe__0[1U] = 0x6772616dU;
    __Vtemp_h3a032bfe__0[2U] = 0x70726fU;
    VL_READMEM_N(true, 8, 4096, 3217031168, VL_CVT_PACK_STR_NW(3, __Vtemp_h3a032bfe__0)
                 ,  &(vlSelf->top__DOT__fetch__DOT__instruction_memory__DOT__rom_mem)
                 , 3217031168, ~0ULL);
}

extern const VlUnpacked<CData/*2:0*/, 2048> Vtop__ConstPool__TABLE_h43fa18f1_0;
extern const VlUnpacked<CData/*5:0*/, 2048> Vtop__ConstPool__TABLE_h6b8065ff_0;
extern const VlUnpacked<CData/*3:0*/, 2048> Vtop__ConstPool__TABLE_h9b6298ff_0;
extern const VlUnpacked<CData/*0:0*/, 2048> Vtop__ConstPool__TABLE_h5bfeecf2_0;
extern const VlUnpacked<CData/*2:0*/, 2048> Vtop__ConstPool__TABLE_h6636ffea_0;
extern const VlUnpacked<CData/*0:0*/, 2048> Vtop__ConstPool__TABLE_h57bdf15b_0;
extern const VlUnpacked<CData/*1:0*/, 2048> Vtop__ConstPool__TABLE_h4155fb0e_0;

VL_ATTR_COLD void Vtop___024root___settle__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___settle__TOP__0\n"); );
    // Init
    CData/*2:0*/ top__DOT__ImmSrc;
    CData/*0:0*/ top__DOT__PCSrc;
    IData/*31:0*/ top__DOT__ImmExt;
    IData/*31:0*/ top__DOT__execute__DOT__srcAE;
    IData/*31:0*/ top__DOT__execute__DOT__SrcBE;
    IData/*31:0*/ top__DOT__memory__DOT__datamem__DOT__Read_Data;
    SData/*10:0*/ __Vtableidx1;
    // Body
    vlSelf->a0 = vlSelf->top__DOT__decode__DOT__regfile__DOT__regs
        [0xaU];
    vlSelf->top__DOT__Instr = ((vlSelf->top__DOT__fetch__DOT__instruction_memory__DOT__rom_mem
                                [(0xfffU & ((IData)(3U) 
                                            + vlSelf->top__DOT__fetch__DOT__PC))] 
                                << 0x18U) | ((vlSelf->top__DOT__fetch__DOT__instruction_memory__DOT__rom_mem
                                              [(0xfffU 
                                                & ((IData)(2U) 
                                                   + vlSelf->top__DOT__fetch__DOT__PC))] 
                                              << 0x10U) 
                                             | ((vlSelf->top__DOT__fetch__DOT__instruction_memory__DOT__rom_mem
                                                 [(0xfffU 
                                                   & ((IData)(1U) 
                                                      + vlSelf->top__DOT__fetch__DOT__PC))] 
                                                 << 8U) 
                                                | vlSelf->top__DOT__fetch__DOT__instruction_memory__DOT__rom_mem
                                                [(0xfffU 
                                                  & vlSelf->top__DOT__fetch__DOT__PC)])));
    vlSelf->top__DOT__ResultSrc = ((3U == (0x7fU & vlSelf->top__DOT__Instr))
                                    ? 1U : (((0x67U 
                                              == (0x7fU 
                                                  & vlSelf->top__DOT__Instr)) 
                                             | (0x6fU 
                                                == 
                                                (0x7fU 
                                                 & vlSelf->top__DOT__Instr)))
                                             ? 2U : 0U));
    top__DOT__execute__DOT__srcAE = ((0x17U == (0x7fU 
                                                & vlSelf->top__DOT__Instr))
                                      ? vlSelf->top__DOT__fetch__DOT__PC
                                      : ((0U == (0x1fU 
                                                 & (vlSelf->top__DOT__Instr 
                                                    >> 0xfU)))
                                          ? 0U : vlSelf->top__DOT__decode__DOT__regfile__DOT__regs
                                         [(0x1fU & 
                                           (vlSelf->top__DOT__Instr 
                                            >> 0xfU))]));
    vlSelf->top__DOT__RD2 = ((0U == (0x1fU & (vlSelf->top__DOT__Instr 
                                              >> 0x14U)))
                              ? 0U : vlSelf->top__DOT__decode__DOT__regfile__DOT__regs
                             [(0x1fU & (vlSelf->top__DOT__Instr 
                                        >> 0x14U))]);
    __Vtableidx1 = ((0x400U & (vlSelf->top__DOT__Instr 
                               >> 0x14U)) | ((0x380U 
                                              & (vlSelf->top__DOT__Instr 
                                                 >> 5U)) 
                                             | (0x7fU 
                                                & vlSelf->top__DOT__Instr)));
    top__DOT__ImmSrc = Vtop__ConstPool__TABLE_h43fa18f1_0
        [__Vtableidx1];
    if ((2U & Vtop__ConstPool__TABLE_h6b8065ff_0[__Vtableidx1])) {
        vlSelf->top__DOT__ALUCtrl = Vtop__ConstPool__TABLE_h9b6298ff_0
            [__Vtableidx1];
    }
    if ((4U & Vtop__ConstPool__TABLE_h6b8065ff_0[__Vtableidx1])) {
        top__DOT__PCSrc = Vtop__ConstPool__TABLE_h5bfeecf2_0
            [__Vtableidx1];
    }
    if ((8U & Vtop__ConstPool__TABLE_h6b8065ff_0[__Vtableidx1])) {
        vlSelf->top__DOT__Branch = Vtop__ConstPool__TABLE_h6636ffea_0
            [__Vtableidx1];
    }
    if ((0x10U & Vtop__ConstPool__TABLE_h6b8065ff_0
         [__Vtableidx1])) {
        vlSelf->top__DOT__MemSign = Vtop__ConstPool__TABLE_h57bdf15b_0
            [__Vtableidx1];
    }
    if ((0x20U & Vtop__ConstPool__TABLE_h6b8065ff_0
         [__Vtableidx1])) {
        vlSelf->top__DOT__MemType = Vtop__ConstPool__TABLE_h4155fb0e_0
            [__Vtableidx1];
    }
    top__DOT__ImmExt = ((4U & (IData)(top__DOT__ImmSrc))
                         ? ((2U & (IData)(top__DOT__ImmSrc))
                             ? 0U : ((1U & (IData)(top__DOT__ImmSrc))
                                      ? 0U : (((- (IData)(
                                                          (vlSelf->top__DOT__Instr 
                                                           >> 0x1fU))) 
                                               << 0x15U) 
                                              | ((0x100000U 
                                                  & (vlSelf->top__DOT__Instr 
                                                     >> 0xbU)) 
                                                 | ((0xff000U 
                                                     & vlSelf->top__DOT__Instr) 
                                                    | ((0x800U 
                                                        & (vlSelf->top__DOT__Instr 
                                                           >> 9U)) 
                                                       | (0x7feU 
                                                          & (vlSelf->top__DOT__Instr 
                                                             >> 0x14U))))))))
                         : ((2U & (IData)(top__DOT__ImmSrc))
                             ? ((1U & (IData)(top__DOT__ImmSrc))
                                 ? (0xfffff000U & vlSelf->top__DOT__Instr)
                                 : (((- (IData)((vlSelf->top__DOT__Instr 
                                                 >> 0x1fU))) 
                                     << 0xdU) | ((0x1000U 
                                                  & (vlSelf->top__DOT__Instr 
                                                     >> 0x13U)) 
                                                 | ((0x800U 
                                                     & (vlSelf->top__DOT__Instr 
                                                        << 4U)) 
                                                    | ((0x7e0U 
                                                        & (vlSelf->top__DOT__Instr 
                                                           >> 0x14U)) 
                                                       | (0x1eU 
                                                          & (vlSelf->top__DOT__Instr 
                                                             >> 7U)))))))
                             : ((1U & (IData)(top__DOT__ImmSrc))
                                 ? (((- (IData)((vlSelf->top__DOT__Instr 
                                                 >> 0x1fU))) 
                                     << 0xcU) | ((0xfe0U 
                                                  & (vlSelf->top__DOT__Instr 
                                                     >> 0x14U)) 
                                                 | (0x1fU 
                                                    & (vlSelf->top__DOT__Instr 
                                                       >> 7U))))
                                 : (((- (IData)((vlSelf->top__DOT__Instr 
                                                 >> 0x1fU))) 
                                     << 0xcU) | (vlSelf->top__DOT__Instr 
                                                 >> 0x14U)))));
    top__DOT__execute__DOT__SrcBE = ((0x33U != (0x7fU 
                                                & vlSelf->top__DOT__Instr))
                                      ? top__DOT__ImmExt
                                      : vlSelf->top__DOT__RD2);
    top__DOT__PCSrc = (((0x67U == (0x7fU & vlSelf->top__DOT__Instr)) 
                        | (0x6fU == (0x7fU & vlSelf->top__DOT__Instr))) 
                       | ((0x63U == (0x7fU & vlSelf->top__DOT__Instr)) 
                          & ((4U & (IData)(vlSelf->top__DOT__Branch))
                              ? ((2U & (IData)(vlSelf->top__DOT__Branch))
                                  ? ((1U & (IData)(vlSelf->top__DOT__Branch))
                                      ? (top__DOT__execute__DOT__srcAE 
                                         >= top__DOT__execute__DOT__SrcBE)
                                      : (top__DOT__execute__DOT__srcAE 
                                         < top__DOT__execute__DOT__SrcBE))
                                  : ((1U & (IData)(vlSelf->top__DOT__Branch))
                                      ? VL_GTES_III(32, top__DOT__execute__DOT__srcAE, top__DOT__execute__DOT__SrcBE)
                                      : VL_LTS_III(32, top__DOT__execute__DOT__srcAE, top__DOT__execute__DOT__SrcBE)))
                              : ((~ ((IData)(vlSelf->top__DOT__Branch) 
                                     >> 1U)) & ((1U 
                                                 & (IData)(vlSelf->top__DOT__Branch))
                                                 ? 
                                                (top__DOT__execute__DOT__srcAE 
                                                 != top__DOT__execute__DOT__SrcBE)
                                                 : 
                                                (top__DOT__execute__DOT__srcAE 
                                                 == top__DOT__execute__DOT__SrcBE))))));
    vlSelf->top__DOT__ALUResult = ((8U & (IData)(vlSelf->top__DOT__ALUCtrl))
                                    ? ((4U & (IData)(vlSelf->top__DOT__ALUCtrl))
                                        ? 0U : ((2U 
                                                 & (IData)(vlSelf->top__DOT__ALUCtrl))
                                                 ? 0U
                                                 : 
                                                ((1U 
                                                  & (IData)(vlSelf->top__DOT__ALUCtrl))
                                                  ? 
                                                 VL_SHIFTRS_III(32,32,5, top__DOT__execute__DOT__srcAE, 
                                                                (0x1fU 
                                                                 & top__DOT__execute__DOT__SrcBE))
                                                  : 
                                                 (top__DOT__execute__DOT__srcAE 
                                                  << 
                                                  (0x1fU 
                                                   & top__DOT__execute__DOT__SrcBE)))))
                                    : ((4U & (IData)(vlSelf->top__DOT__ALUCtrl))
                                        ? ((2U & (IData)(vlSelf->top__DOT__ALUCtrl))
                                            ? ((1U 
                                                & (IData)(vlSelf->top__DOT__ALUCtrl))
                                                ? (top__DOT__execute__DOT__srcAE 
                                                   >> 
                                                   (0x1fU 
                                                    & top__DOT__execute__DOT__SrcBE))
                                                : (
                                                   (top__DOT__execute__DOT__srcAE 
                                                    < top__DOT__execute__DOT__SrcBE)
                                                    ? 1U
                                                    : 0U))
                                            : ((1U 
                                                & (IData)(vlSelf->top__DOT__ALUCtrl))
                                                ? (
                                                   VL_LTS_III(32, top__DOT__execute__DOT__srcAE, top__DOT__execute__DOT__SrcBE)
                                                    ? 1U
                                                    : 0U)
                                                : (top__DOT__execute__DOT__srcAE 
                                                   ^ top__DOT__execute__DOT__SrcBE)))
                                        : ((2U & (IData)(vlSelf->top__DOT__ALUCtrl))
                                            ? ((1U 
                                                & (IData)(vlSelf->top__DOT__ALUCtrl))
                                                ? (top__DOT__execute__DOT__srcAE 
                                                   | top__DOT__execute__DOT__SrcBE)
                                                : (top__DOT__execute__DOT__srcAE 
                                                   & top__DOT__execute__DOT__SrcBE))
                                            : ((1U 
                                                & (IData)(vlSelf->top__DOT__ALUCtrl))
                                                ? (top__DOT__execute__DOT__srcAE 
                                                   - top__DOT__execute__DOT__SrcBE)
                                                : (top__DOT__execute__DOT__srcAE 
                                                   + top__DOT__execute__DOT__SrcBE)))));
    vlSelf->top__DOT__fetch__DOT__pc__DOT__next_PC 
        = ((IData)(top__DOT__PCSrc) ? (((0x6fU == (0x7fU 
                                                   & vlSelf->top__DOT__Instr)) 
                                        | (0x67U == 
                                           (0x7fU & vlSelf->top__DOT__Instr)))
                                        ? vlSelf->top__DOT__execute__DOT__PC_TargetE
                                        : vlSelf->top__DOT__ALUResult)
            : ((IData)(4U) + vlSelf->top__DOT__fetch__DOT__PC));
    top__DOT__memory__DOT__datamem__DOT__Read_Data 
        = ((vlSelf->top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array
            [(0x1ffffU & ((IData)(3U) + (0x1fffcU & vlSelf->top__DOT__ALUResult)))] 
            << 0x18U) | ((vlSelf->top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array
                          [(0x1ffffU & ((IData)(2U) 
                                        + (0x1fffcU 
                                           & vlSelf->top__DOT__ALUResult)))] 
                          << 0x10U) | ((vlSelf->top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array
                                        [(0x1ffffU 
                                          & ((IData)(1U) 
                                             + (0x1fffcU 
                                                & vlSelf->top__DOT__ALUResult)))] 
                                        << 8U) | vlSelf->top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array
                                       [(0x1fffcU & vlSelf->top__DOT__ALUResult)])));
    if ((1U == (IData)(vlSelf->top__DOT__MemType))) {
        vlSelf->top__DOT__memory__DOT__datamem__DOT__Write_Data 
            = ((0xffffff00U & top__DOT__memory__DOT__datamem__DOT__Read_Data) 
               | (0xffU & vlSelf->top__DOT__RD2));
        if (vlSelf->top__DOT__MemSign) {
            if (vlSelf->top__DOT__MemSign) {
                vlSelf->top__DOT__RDM = (0xffU & top__DOT__memory__DOT__datamem__DOT__Read_Data);
            }
        } else {
            vlSelf->top__DOT__RDM = (((- (IData)((1U 
                                                  & (top__DOT__memory__DOT__datamem__DOT__Read_Data 
                                                     >> 7U)))) 
                                      << 8U) | (0xffU 
                                                & top__DOT__memory__DOT__datamem__DOT__Read_Data));
        }
    } else if ((2U == (IData)(vlSelf->top__DOT__MemType))) {
        vlSelf->top__DOT__memory__DOT__datamem__DOT__Write_Data 
            = ((0xffff0000U & top__DOT__memory__DOT__datamem__DOT__Read_Data) 
               | (0xffffU & vlSelf->top__DOT__RD2));
        if (vlSelf->top__DOT__MemSign) {
            if (vlSelf->top__DOT__MemSign) {
                vlSelf->top__DOT__RDM = (0xffffU & top__DOT__memory__DOT__datamem__DOT__Read_Data);
            }
        } else {
            vlSelf->top__DOT__RDM = (((- (IData)((1U 
                                                  & (top__DOT__memory__DOT__datamem__DOT__Read_Data 
                                                     >> 0xfU)))) 
                                      << 0x10U) | (0xffffU 
                                                   & top__DOT__memory__DOT__datamem__DOT__Read_Data));
        }
    } else {
        vlSelf->top__DOT__memory__DOT__datamem__DOT__Write_Data 
            = vlSelf->top__DOT__RD2;
        vlSelf->top__DOT__RDM = top__DOT__memory__DOT__datamem__DOT__Read_Data;
    }
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    Vtop___024root___initial__TOP__0(vlSelf);
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Body
    Vtop___024root___settle__TOP__0(vlSelf);
}

VL_ATTR_COLD void Vtop___024root___final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___final\n"); );
}

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->a0 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ALUCtrl = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__ResultSrc = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__MemType = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__MemSign = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__Branch = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__Instr = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__RD2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__ALUResult = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__RDM = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__fetch__DOT__PC = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__fetch__DOT__pc__DOT__next_PC = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<4096; ++__Vi0) {
        vlSelf->top__DOT__fetch__DOT__instruction_memory__DOT__rom_mem[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        vlSelf->top__DOT__decode__DOT__regfile__DOT__regs[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->top__DOT__execute__DOT__PC_TargetE = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__memory__DOT__datamem__DOT__Write_Data = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<131072; ++__Vi0) {
        vlSelf->top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array[__Vi0] = VL_RAND_RESET_I(8);
    }
}
