// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Primary design header
//
// This header should be included by all source files instantiating the design.
// The class here is then constructed to instantiate the design.
// See the Verilator manual for examples.

#ifndef _VGPU_H_
#define _VGPU_H_  // guard

#include "verilated.h"

//==========

class Vgpu__Syms;
class Vgpu_core__T8;


//----------

VL_MODULE(Vgpu) {
  public:
    // CELLS
    // Public to allow access to /*verilator_public*/ items;
    // otherwise the application code can consider these internals.
    Vgpu_core__T8* __PVT__gpu__DOT__cores__BRA__0__KET____DOT__core_instance;
    Vgpu_core__T8* __PVT__gpu__DOT__cores__BRA__1__KET____DOT__core_instance;
    
    // PORTS
    // The application code writes and reads these signals to
    // propagate new values into/out from the Verilated model.
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(start,0,0);
    VL_OUT8(done,0,0);
    VL_IN8(device_control_write_enable,0,0);
    VL_IN8(device_control_data,7,0);
    VL_OUT8(program_mem_read_valid,0,0);
    VL_IN8(program_mem_read_ready,0,0);
    VL_OUT8(data_mem_read_valid,7,0);
    VL_IN8(data_mem_read_ready,7,0);
    VL_OUT8(data_mem_write_valid,7,0);
    VL_IN8(data_mem_write_ready,7,0);
    VL_OUT8(program_mem_read_address[1],7,0);
    VL_IN16(program_mem_read_data[1],15,0);
    VL_OUT8(data_mem_read_address[8],7,0);
    VL_IN8(data_mem_read_data[8],7,0);
    VL_OUT8(data_mem_write_address[8],7,0);
    VL_OUT8(data_mem_write_data[8],7,0);
    
    // LOCAL SIGNALS
    // Internals; generally not touched by application code
    CData/*1:0*/ gpu__DOT__core_start;
    CData/*1:0*/ gpu__DOT__core_reset;
    CData/*1:0*/ gpu__DOT__core_done;
    CData/*1:0*/ gpu__DOT__fetcher_read_valid;
    CData/*1:0*/ gpu__DOT__fetcher_read_ready;
    CData/*7:0*/ gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready;
    CData/*7:0*/ gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready;
    CData/*7:0*/ gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready;
    CData/*7:0*/ gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready;
    CData/*7:0*/ gpu__DOT__dcr_instance__DOT__device_conrol_register;
    CData/*1:0*/ gpu__DOT__program_memory_controller__DOT__consumer_write_valid;
    CData/*1:0*/ gpu__DOT__program_memory_controller__DOT__consumer_write_ready;
    CData/*0:0*/ gpu__DOT__program_memory_controller__DOT__mem_write_ready;
    CData/*1:0*/ gpu__DOT__program_memory_controller__DOT__channel_serving_consumer;
    CData/*7:0*/ gpu__DOT__dispatch_instance__DOT__blocks_dispatched;
    CData/*7:0*/ gpu__DOT__dispatch_instance__DOT__blocks_done;
    CData/*0:0*/ gpu__DOT__dispatch_instance__DOT__start_execution;
    SData/*15:0*/ gpu__DOT__lsu_read_valid;
    SData/*15:0*/ gpu__DOT__lsu_read_ready;
    SData/*15:0*/ gpu__DOT__lsu_write_valid;
    SData/*15:0*/ gpu__DOT__lsu_write_ready;
    SData/*15:0*/ gpu__DOT__data_memory_controller__DOT__channel_serving_consumer;
    IData/*31:0*/ gpu__DOT__data_memory_controller__DOT__j;
    IData/*31:0*/ gpu__DOT__program_memory_controller__DOT__j;
    CData/*7:0*/ gpu__DOT__core_block_id[2];
    CData/*3:0*/ gpu__DOT__core_thread_count[2];
    CData/*7:0*/ gpu__DOT__lsu_read_address[16];
    CData/*7:0*/ gpu__DOT__lsu_read_data[16];
    CData/*7:0*/ gpu__DOT__lsu_write_address[16];
    CData/*7:0*/ gpu__DOT__lsu_write_data[16];
    CData/*7:0*/ gpu__DOT__fetcher_read_address[2];
    SData/*15:0*/ gpu__DOT__fetcher_read_data[2];
    CData/*7:0*/ gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address[8];
    CData/*7:0*/ gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data[8];
    CData/*7:0*/ gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address[8];
    CData/*7:0*/ gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data[8];
    CData/*7:0*/ gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address[8];
    CData/*7:0*/ gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data[8];
    CData/*7:0*/ gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address[8];
    CData/*7:0*/ gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data[8];
    CData/*2:0*/ gpu__DOT__data_memory_controller__DOT__controller_state[8];
    CData/*3:0*/ gpu__DOT__data_memory_controller__DOT__current_consumer[8];
    CData/*2:0*/ gpu__DOT__program_memory_controller__DOT__controller_state[1];
    CData/*0:0*/ gpu__DOT__program_memory_controller__DOT__current_consumer[1];
    
    // LOCAL VARIABLES
    // Internals; generally not touched by application code
    CData/*0:0*/ gpu__DOT__program_memory_controller__DOT____Vlvbound6;
    CData/*7:0*/ gpu__DOT__program_memory_controller__DOT____Vlvbound8;
    CData/*1:0*/ __Vdly__gpu__DOT__core_start;
    CData/*1:0*/ __Vdly__gpu__DOT__core_reset;
    CData/*0:0*/ __Vclklast__TOP__clk;
    CData/*7:0*/ gpu__DOT____Vcellout__data_memory_controller__mem_write_data[8];
    CData/*7:0*/ gpu__DOT____Vcellout__data_memory_controller__mem_write_address[8];
    CData/*7:0*/ gpu__DOT____Vcellinp__data_memory_controller__mem_read_data[8];
    CData/*7:0*/ gpu__DOT____Vcellout__data_memory_controller__mem_read_address[8];
    CData/*7:0*/ gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[16];
    CData/*7:0*/ gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[16];
    CData/*7:0*/ gpu__DOT____Vcellout__data_memory_controller__consumer_read_data[16];
    CData/*7:0*/ gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[16];
    SData/*15:0*/ gpu__DOT____Vcellinp__program_memory_controller__mem_read_data[1];
    CData/*7:0*/ gpu__DOT____Vcellout__program_memory_controller__mem_read_address[1];
    SData/*15:0*/ gpu__DOT____Vcellout__program_memory_controller__consumer_read_data[2];
    CData/*7:0*/ gpu__DOT____Vcellinp__program_memory_controller__consumer_read_address[2];
    CData/*3:0*/ gpu__DOT____Vcellout__dispatch_instance__core_thread_count[2];
    CData/*7:0*/ gpu__DOT____Vcellout__dispatch_instance__core_block_id[2];
    CData/*7:0*/ gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data[8];
    CData/*7:0*/ gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address[8];
    CData/*7:0*/ gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data[8];
    CData/*7:0*/ gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address[8];
    CData/*7:0*/ gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data[8];
    CData/*7:0*/ gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address[8];
    CData/*7:0*/ gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data[8];
    CData/*7:0*/ gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address[8];
    
    // INTERNAL VARIABLES
    // Internals; generally not touched by application code
    Vgpu__Syms* __VlSymsp;  // Symbol table
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vgpu);  ///< Copying not allowed
  public:
    /// Construct the model; called by application code
    /// The special name  may be used to make a wrapper with a
    /// single model invisible with respect to DPI scope names.
    Vgpu(const char* name = "TOP");
    /// Destroy the model; called (often implicitly) by application code
    ~Vgpu();
    
    // API METHODS
    /// Evaluate the model.  Application must call when inputs change.
    void eval();
    /// Simulation complete, run final blocks.  Application must call on completion.
    void final();
    
    // INTERNAL METHODS
  private:
    static void _eval_initial_loop(Vgpu__Syms* __restrict vlSymsp);
  public:
    void __Vconfigure(Vgpu__Syms* symsp, bool first);
  private:
    static QData _change_request(Vgpu__Syms* __restrict vlSymsp);
  public:
    static void _combo__TOP__5(Vgpu__Syms* __restrict vlSymsp);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    static void _eval(Vgpu__Syms* __restrict vlSymsp);
  private:
#ifdef VL_DEBUG
    void _eval_debug_assertions();
#endif  // VL_DEBUG
  public:
    static void _eval_initial(Vgpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _eval_settle(Vgpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _sequent__TOP__1(Vgpu__Syms* __restrict vlSymsp);
    static void _sequent__TOP__2(Vgpu__Syms* __restrict vlSymsp);
    static void _settle__TOP__3(Vgpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
    static void _settle__TOP__4(Vgpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
