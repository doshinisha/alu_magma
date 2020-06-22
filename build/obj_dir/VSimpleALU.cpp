// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VSimpleALU.h for the primary calling header

#include "VSimpleALU.h"
#include "VSimpleALU__Syms.h"

//==========

VL_CTOR_IMP(VSimpleALU) {
    VSimpleALU__Syms* __restrict vlSymsp = __VlSymsp = new VSimpleALU__Syms(this, name());
    VSimpleALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void VSimpleALU::__Vconfigure(VSimpleALU__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

VSimpleALU::~VSimpleALU() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void VSimpleALU::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VSimpleALU::eval\n"); );
    VSimpleALU__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    VSimpleALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("SimpleALU.v", 247, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VSimpleALU::_eval_initial_loop(VSimpleALU__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("SimpleALU.v", 247, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void VSimpleALU::_initial__TOP__1(VSimpleALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimpleALU::_initial__TOP__1\n"); );
    VSimpleALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->SimpleALU__DOT__config_reg__DOT__conf_reg__DOT__value__DOT__outReg = 0U;
}

VL_INLINE_OPT void VSimpleALU::_sequent__TOP__2(VSimpleALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimpleALU::_sequent__TOP__2\n"); );
    VSimpleALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->SimpleALU__DOT__config_reg__DOT__conf_reg__DOT__value__DOT__outReg 
        = vlTOPp->SimpleALU__DOT__config_reg__DOT__conf_reg__DOT__enable_mux__DOT__coreir_commonlib_mux2x2_inst0__DOT___join_out;
}

VL_INLINE_OPT void VSimpleALU::_settle__TOP__3(VSimpleALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimpleALU::_settle__TOP__3\n"); );
    VSimpleALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->c = (0xffffU & ((2U & (IData)(vlTOPp->SimpleALU__DOT__config_reg__DOT__conf_reg__DOT__value__DOT__outReg))
                             ? ((1U & (IData)(vlTOPp->SimpleALU__DOT__config_reg__DOT__conf_reg__DOT__value__DOT__outReg))
                                 ? ((IData)(vlTOPp->a) 
                                    ^ (IData)(vlTOPp->b))
                                 : ((IData)(vlTOPp->a) 
                                    * (IData)(vlTOPp->b)))
                             : ((1U & (IData)(vlTOPp->SimpleALU__DOT__config_reg__DOT__conf_reg__DOT__value__DOT__outReg))
                                 ? ((IData)(vlTOPp->a) 
                                    - (IData)(vlTOPp->b))
                                 : ((IData)(vlTOPp->a) 
                                    + (IData)(vlTOPp->b)))));
    vlTOPp->SimpleALU__DOT__config_reg__DOT__conf_reg__DOT__enable_mux__DOT__coreir_commonlib_mux2x2_inst0__DOT___join_out 
        = ((IData)(vlTOPp->config_en) ? (IData)(vlTOPp->config_data)
            : (IData)(vlTOPp->SimpleALU__DOT__config_reg__DOT__conf_reg__DOT__value__DOT__outReg));
}

void VSimpleALU::_eval(VSimpleALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimpleALU::_eval\n"); );
    VSimpleALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->CLK) & (~ (IData)(vlTOPp->__Vclklast__TOP__CLK)))) {
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    vlTOPp->_settle__TOP__3(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
}

void VSimpleALU::_eval_initial(VSimpleALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimpleALU::_eval_initial\n"); );
    VSimpleALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_initial__TOP__1(vlSymsp);
    vlTOPp->__Vclklast__TOP__CLK = vlTOPp->CLK;
}

void VSimpleALU::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimpleALU::final\n"); );
    // Variables
    VSimpleALU__Syms* __restrict vlSymsp = this->__VlSymsp;
    VSimpleALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void VSimpleALU::_eval_settle(VSimpleALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimpleALU::_eval_settle\n"); );
    VSimpleALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
}

VL_INLINE_OPT QData VSimpleALU::_change_request(VSimpleALU__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimpleALU::_change_request\n"); );
    VSimpleALU* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void VSimpleALU::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimpleALU::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((config_data & 0xfcU))) {
        Verilated::overWidthError("config_data");}
    if (VL_UNLIKELY((config_en & 0xfeU))) {
        Verilated::overWidthError("config_en");}
    if (VL_UNLIKELY((CLK & 0xfeU))) {
        Verilated::overWidthError("CLK");}
}
#endif  // VL_DEBUG

void VSimpleALU::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VSimpleALU::_ctor_var_reset\n"); );
    // Body
    a = VL_RAND_RESET_I(16);
    b = VL_RAND_RESET_I(16);
    c = VL_RAND_RESET_I(16);
    config_data = VL_RAND_RESET_I(2);
    config_en = VL_RAND_RESET_I(1);
    CLK = VL_RAND_RESET_I(1);
    SimpleALU__DOT__config_reg__DOT__conf_reg__DOT__enable_mux__DOT__coreir_commonlib_mux2x2_inst0__DOT___join_out = VL_RAND_RESET_I(2);
    SimpleALU__DOT__config_reg__DOT__conf_reg__DOT__value__DOT__outReg = VL_RAND_RESET_I(2);
}
