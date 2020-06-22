// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VSIMPLEALU_H_
#define _VSIMPLEALU_H_  // guard

#include "verilated.h"

//==========

class VSimpleALU__Syms;

//----------

VL_MODULE(VSimpleALU) {
  public:
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(CLK,0,0);
    VL_IN8(config_data,1,0);
    VL_IN8(config_en,0,0);
    VL_IN16(a,15,0);
    VL_IN16(b,15,0);
    VL_OUT16(c,15,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*1:0*/ SimpleALU__DOT__config_reg__DOT__conf_reg__DOT__enable_mux__DOT__coreir_commonlib_mux2x2_inst0__DOT___join_out;
    CData/*1:0*/ SimpleALU__DOT__config_reg__DOT__conf_reg__DOT__value__DOT__outReg;
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ __Vclklast__TOP__CLK;
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    VSimpleALU__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(VSimpleALU);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    VSimpleALU(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~VSimpleALU();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(VSimpleALU__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(VSimpleALU__Syms* symsp, bool first);
  private:
    static QData _change_request(VSimpleALU__Syms* __restrict vlSymsp);
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(VSimpleALU__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(VSimpleALU__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(VSimpleALU__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _initial__TOP__1(VSimpleALU__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__2(VSimpleALU__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(VSimpleALU__Syms* __restrict vlSymsp);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
