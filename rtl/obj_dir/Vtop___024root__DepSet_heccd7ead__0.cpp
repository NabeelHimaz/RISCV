// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

VL_INLINE_OPT void Vtop___024root___sequent__TOP__1(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__1\n"); );
    // Init
    IData/*16:0*/ __Vdlyvdim0__top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array__v0;
    IData/*16:0*/ __Vdlyvdim0__top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array__v1;
    CData/*7:0*/ __Vdlyvval__top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array__v1;
    IData/*16:0*/ __Vdlyvdim0__top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array__v2;
    CData/*7:0*/ __Vdlyvval__top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array__v2;
    IData/*16:0*/ __Vdlyvdim0__top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array__v3;
    CData/*7:0*/ __Vdlyvval__top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array__v3;
    // Body
    __Vdlyvset__top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array__v0 = 0U;
    if ((0x23U == (0x7fU & vlSelf->top__DOT__Instr))) {
        __Vdlyvval__top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array__v0 
            = (0xffU & vlSelf->top__DOT__memory__DOT__datamem__DOT__Write_Data);
        __Vdlyvset__top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array__v0 = 1U;
        __Vdlyvdim0__top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array__v0 
            = (0x1fffcU & vlSelf->top__DOT__ALUResult);
        __Vdlyvval__top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array__v1 
            = (0xffU & (vlSelf->top__DOT__memory__DOT__datamem__DOT__Write_Data 
                        >> 8U));
        __Vdlyvdim0__top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array__v1 
            = (0x1ffffU & ((IData)(1U) + (0x1fffcU 
                                          & vlSelf->top__DOT__ALUResult)));
        __Vdlyvval__top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array__v2 
            = (0xffU & (vlSelf->top__DOT__memory__DOT__datamem__DOT__Write_Data 
                        >> 0x10U));
        __Vdlyvdim0__top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array__v2 
            = (0x1ffffU & ((IData)(2U) + (0x1fffcU 
                                          & vlSelf->top__DOT__ALUResult)));
        __Vdlyvval__top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array__v3 
            = (vlSelf->top__DOT__memory__DOT__datamem__DOT__Write_Data 
               >> 0x18U);
        __Vdlyvdim0__top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array__v3 
            = (0x1ffffU & ((IData)(3U) + (0x1fffcU 
                                          & vlSelf->top__DOT__ALUResult)));
    }
    if (__Vdlyvset__top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array__v0) {
        vlSelf->top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array[__Vdlyvdim0__top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array__v0] 
            = __Vdlyvval__top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array__v0;
        vlSelf->top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array[__Vdlyvdim0__top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array__v1] 
            = __Vdlyvval__top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array__v1;
        vlSelf->top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array[__Vdlyvdim0__top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array__v2] 
            = __Vdlyvval__top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array__v2;
        vlSelf->top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array[__Vdlyvdim0__top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array__v3] 
            = __Vdlyvval__top__DOT__memory__DOT__datamem__DOT__data_mem__DOT__ram_array__v3;
    }
}

VL_INLINE_OPT void Vtop___024root___sequent__TOP__2(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__2\n"); );
    // Init
    CData/*4:0*/ __Vdlyvdim0__top__DOT__decode__DOT__regfile__DOT__regs__v0;
    IData/*31:0*/ __Vdlyvval__top__DOT__decode__DOT__regfile__DOT__regs__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__decode__DOT__regfile__DOT__regs__v0;
    // Body
    __Vdlyvset__top__DOT__decode__DOT__regfile__DOT__regs__v0 = 0U;
    if (((~ ((0x23U == (0x7fU & vlSelf->top__DOT__Instr)) 
             | (0x63U == (0x7fU & vlSelf->top__DOT__Instr)))) 
         & (0U != (0x1fU & (vlSelf->top__DOT__Instr 
                            >> 7U))))) {
        __Vdlyvval__top__DOT__decode__DOT__regfile__DOT__regs__v0 
            = ((0U == (IData)(vlSelf->top__DOT__ResultSrc))
                ? vlSelf->top__DOT__ALUResult : ((1U 
                                                  == (IData)(vlSelf->top__DOT__ResultSrc))
                                                  ? vlSelf->top__DOT__RDM
                                                  : 
                                                 ((2U 
                                                   == (IData)(vlSelf->top__DOT__ResultSrc))
                                                   ? 
                                                  ((IData)(4U) 
                                                   + vlSelf->top__DOT__fetch__DOT__PC)
                                                   : 0U)));
        __Vdlyvset__top__DOT__decode__DOT__regfile__DOT__regs__v0 = 1U;
        __Vdlyvdim0__top__DOT__decode__DOT__regfile__DOT__regs__v0 
            = (0x1fU & (vlSelf->top__DOT__Instr >> 7U));
    }
    if (__Vdlyvset__top__DOT__decode__DOT__regfile__DOT__regs__v0) {
        vlSelf->top__DOT__decode__DOT__regfile__DOT__regs[__Vdlyvdim0__top__DOT__decode__DOT__regfile__DOT__regs__v0] 
            = __Vdlyvval__top__DOT__decode__DOT__regfile__DOT__regs__v0;
    }
    vlSelf->a0 = vlSelf->top__DOT__decode__DOT__regfile__DOT__regs
        [0xaU];
}

extern const VlUnpacked<CData/*2:0*/, 2048> Vtop__ConstPool__TABLE_h43fa18f1_0;
extern const VlUnpacked<CData/*5:0*/, 2048> Vtop__ConstPool__TABLE_h6b8065ff_0;
extern const VlUnpacked<CData/*3:0*/, 2048> Vtop__ConstPool__TABLE_h9b6298ff_0;
extern const VlUnpacked<CData/*0:0*/, 2048> Vtop__ConstPool__TABLE_h5bfeecf2_0;
extern const VlUnpacked<CData/*2:0*/, 2048> Vtop__ConstPool__TABLE_h6636ffea_0;
extern const VlUnpacked<CData/*0:0*/, 2048> Vtop__ConstPool__TABLE_h57bdf15b_0;
extern const VlUnpacked<CData/*1:0*/, 2048> Vtop__ConstPool__TABLE_h4155fb0e_0;

VL_INLINE_OPT void Vtop___024root___sequent__TOP__3(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__3\n"); );
    // Init
    CData/*2:0*/ top__DOT__ImmSrc;
    CData/*0:0*/ top__DOT__PCSrc;
    IData/*31:0*/ top__DOT__ImmExt;
    IData/*31:0*/ top__DOT__execute__DOT__srcAE;
    IData/*31:0*/ top__DOT__execute__DOT__SrcBE;
    SData/*10:0*/ __Vtableidx1;
    // Body
    vlSelf->top__DOT__fetch__DOT__PC = ((IData)(vlSelf->rst)
                                         ? 0xbfc00000U
                                         : vlSelf->top__DOT__fetch__DOT__pc__DOT__next_PC);
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
}

VL_INLINE_OPT void Vtop___024root___multiclk__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___multiclk__TOP__0\n"); );
    // Init
    IData/*31:0*/ top__DOT__memory__DOT__datamem__DOT__Read_Data;
    // Body
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

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Body
    if (((~ (IData)(vlSelf->clk)) & (IData)(vlSelf->__Vclklast__TOP__clk))) {
        Vtop___024root___sequent__TOP__1(vlSelf);
    }
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vtop___024root___sequent__TOP__2(vlSelf);
    }
    if ((((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk))) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        Vtop___024root___sequent__TOP__3(vlSelf);
    }
    if ((((IData)(vlSelf->clk) ^ (IData)(vlSelf->__Vclklast__TOP__clk)) 
         | ((IData)(vlSelf->rst) & (~ (IData)(vlSelf->__Vclklast__TOP__rst))))) {
        Vtop___024root___multiclk__TOP__0(vlSelf);
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
    vlSelf->__Vclklast__TOP__rst = vlSelf->rst;
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
}
#endif  // VL_DEBUG
