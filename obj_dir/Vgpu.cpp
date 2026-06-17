// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vgpu.h for the primary calling header

#include "Vgpu.h"
#include "Vgpu__Syms.h"

//==========

VL_CTOR_IMP(Vgpu) {
    Vgpu__Syms* __restrict vlSymsp = __VlSymsp = new Vgpu__Syms(this, name());
    Vgpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    VL_CELL(__PVT__gpu__DOT__cores__BRA__0__KET____DOT__core_instance, Vgpu_core__T8);
    VL_CELL(__PVT__gpu__DOT__cores__BRA__1__KET____DOT__core_instance, Vgpu_core__T8);
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vgpu::__Vconfigure(Vgpu__Syms* vlSymsp, bool first) {
    if (0 && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
}

Vgpu::~Vgpu() {
    delete __VlSymsp; __VlSymsp=NULL;
}

void Vgpu::eval() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vgpu::eval\n"); );
    Vgpu__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vgpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
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
            VL_FATAL_MT("rtl/gpu.sv", 6, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vgpu::_eval_initial_loop(Vgpu__Syms* __restrict vlSymsp) {
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
            VL_FATAL_MT("rtl/gpu.sv", 6, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vgpu::_sequent__TOP__1(Vgpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgpu::_sequent__TOP__1\n"); );
    Vgpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    CData/*0:0*/ __Vdly__gpu__DOT__dispatch_instance__DOT__start_execution;
    CData/*0:0*/ __Vdlyvset__gpu__DOT____Vcellout__dispatch_instance__core_block_id__v0;
    CData/*0:0*/ __Vdlyvset__gpu__DOT____Vcellout__dispatch_instance__core_block_id__v1;
    CData/*7:0*/ __Vdlyvval__gpu__DOT____Vcellout__dispatch_instance__core_block_id__v2;
    CData/*0:0*/ __Vdlyvset__gpu__DOT____Vcellout__dispatch_instance__core_block_id__v2;
    CData/*3:0*/ __Vdlyvval__gpu__DOT____Vcellout__dispatch_instance__core_thread_count__v2;
    CData/*7:0*/ __Vdlyvval__gpu__DOT____Vcellout__dispatch_instance__core_block_id__v3;
    CData/*0:0*/ __Vdlyvset__gpu__DOT____Vcellout__dispatch_instance__core_block_id__v3;
    CData/*3:0*/ __Vdlyvval__gpu__DOT____Vcellout__dispatch_instance__core_thread_count__v3;
    // Body
    vlTOPp->__Vdly__gpu__DOT__core_reset = vlTOPp->gpu__DOT__core_reset;
    vlTOPp->__Vdly__gpu__DOT__core_start = vlTOPp->gpu__DOT__core_start;
    __Vdly__gpu__DOT__dispatch_instance__DOT__start_execution 
        = vlTOPp->gpu__DOT__dispatch_instance__DOT__start_execution;
    __Vdlyvset__gpu__DOT____Vcellout__dispatch_instance__core_block_id__v0 = 0U;
    __Vdlyvset__gpu__DOT____Vcellout__dispatch_instance__core_block_id__v1 = 0U;
    __Vdlyvset__gpu__DOT____Vcellout__dispatch_instance__core_block_id__v2 = 0U;
    __Vdlyvset__gpu__DOT____Vcellout__dispatch_instance__core_block_id__v3 = 0U;
    if (vlTOPp->reset) {
        vlTOPp->program_mem_read_valid = 0U;
        vlTOPp->gpu__DOT__fetcher_read_ready = 0U;
        vlTOPp->gpu__DOT__program_memory_controller__DOT__consumer_write_ready = 0U;
        vlTOPp->gpu__DOT__program_memory_controller__DOT__channel_serving_consumer = 0U;
        vlTOPp->gpu__DOT____Vcellout__program_memory_controller__mem_read_address[0U] = 0U;
        vlTOPp->gpu__DOT__program_memory_controller__DOT__current_consumer[0U] = 0U;
        vlTOPp->gpu__DOT__program_memory_controller__DOT__controller_state[0U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__program_memory_controller__consumer_read_data[0U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__program_memory_controller__consumer_read_data[1U] = 0U;
    } else {
        if ((4U & vlTOPp->gpu__DOT__program_memory_controller__DOT__controller_state
             [0U])) {
            if ((2U & vlTOPp->gpu__DOT__program_memory_controller__DOT__controller_state
                 [0U])) {
                vlTOPp->gpu__DOT__program_memory_controller__DOT__controller_state[0U] = 0U;
            } else {
                if ((1U & vlTOPp->gpu__DOT__program_memory_controller__DOT__controller_state
                     [0U])) {
                    if ((1U & (~ ((IData)(vlTOPp->gpu__DOT__program_memory_controller__DOT__consumer_write_valid) 
                                  >> vlTOPp->gpu__DOT__program_memory_controller__DOT__current_consumer
                                  [0U])))) {
                        vlTOPp->gpu__DOT__program_memory_controller__DOT__channel_serving_consumer 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__program_memory_controller__DOT__current_consumer
                                   [0U])) & (IData)(vlTOPp->gpu__DOT__program_memory_controller__DOT__channel_serving_consumer));
                        vlTOPp->gpu__DOT__program_memory_controller__DOT__consumer_write_ready 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__program_memory_controller__DOT__current_consumer
                                   [0U])) & (IData)(vlTOPp->gpu__DOT__program_memory_controller__DOT__consumer_write_ready));
                        vlTOPp->gpu__DOT__program_memory_controller__DOT__controller_state[0U] = 0U;
                    }
                } else {
                    if ((1U & (~ ((IData)(vlTOPp->gpu__DOT__fetcher_read_valid) 
                                  >> vlTOPp->gpu__DOT__program_memory_controller__DOT__current_consumer
                                  [0U])))) {
                        vlTOPp->gpu__DOT__program_memory_controller__DOT__channel_serving_consumer 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__program_memory_controller__DOT__current_consumer
                                   [0U])) & (IData)(vlTOPp->gpu__DOT__program_memory_controller__DOT__channel_serving_consumer));
                        vlTOPp->gpu__DOT__fetcher_read_ready 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__program_memory_controller__DOT__current_consumer
                                   [0U])) & (IData)(vlTOPp->gpu__DOT__fetcher_read_ready));
                        vlTOPp->gpu__DOT__program_memory_controller__DOT__controller_state[0U] = 0U;
                    }
                }
            }
        } else {
            if ((2U & vlTOPp->gpu__DOT__program_memory_controller__DOT__controller_state
                 [0U])) {
                if ((1U & vlTOPp->gpu__DOT__program_memory_controller__DOT__controller_state
                     [0U])) {
                    if (vlTOPp->gpu__DOT__program_memory_controller__DOT__mem_write_ready) {
                        vlTOPp->gpu__DOT__program_memory_controller__DOT__consumer_write_ready 
                            = ((IData)(vlTOPp->gpu__DOT__program_memory_controller__DOT__consumer_write_ready) 
                               | ((IData)(1U) << vlTOPp->gpu__DOT__program_memory_controller__DOT__current_consumer
                                  [0U]));
                        vlTOPp->gpu__DOT__program_memory_controller__DOT__controller_state[0U] = 5U;
                    }
                } else {
                    if (vlTOPp->program_mem_read_ready) {
                        vlTOPp->program_mem_read_valid = 0U;
                        vlTOPp->gpu__DOT__fetcher_read_ready 
                            = ((IData)(vlTOPp->gpu__DOT__fetcher_read_ready) 
                               | ((IData)(1U) << vlTOPp->gpu__DOT__program_memory_controller__DOT__current_consumer
                                  [0U]));
                        vlTOPp->gpu__DOT____Vcellout__program_memory_controller__consumer_read_data[vlTOPp->gpu__DOT__program_memory_controller__DOT__current_consumer[0U]] 
                            = vlTOPp->gpu__DOT____Vcellinp__program_memory_controller__mem_read_data
                            [0U];
                        vlTOPp->gpu__DOT__program_memory_controller__DOT__controller_state[0U] = 4U;
                    }
                }
            } else {
                if ((1U & vlTOPp->gpu__DOT__program_memory_controller__DOT__controller_state
                     [0U])) {
                    vlTOPp->gpu__DOT__program_memory_controller__DOT__controller_state[0U] = 0U;
                } else {
                    vlTOPp->gpu__DOT__program_memory_controller__DOT__j = 0U;
                    while (VL_GTS_III(1,32,32, 2U, vlTOPp->gpu__DOT__program_memory_controller__DOT__j)) {
                        if ((1U & (((IData)(vlTOPp->gpu__DOT__fetcher_read_valid) 
                                    >> (1U & vlTOPp->gpu__DOT__program_memory_controller__DOT__j)) 
                                   & (~ ((IData)(vlTOPp->gpu__DOT__program_memory_controller__DOT__channel_serving_consumer) 
                                         >> (1U & vlTOPp->gpu__DOT__program_memory_controller__DOT__j)))))) {
                            vlTOPp->gpu__DOT__program_memory_controller__DOT__channel_serving_consumer 
                                = ((IData)(vlTOPp->gpu__DOT__program_memory_controller__DOT__channel_serving_consumer) 
                                   | ((IData)(1U) << 
                                      (1U & vlTOPp->gpu__DOT__program_memory_controller__DOT__j)));
                            vlTOPp->program_mem_read_valid = 1U;
                            vlTOPp->gpu__DOT__program_memory_controller__DOT__controller_state[0U] = 2U;
                            vlTOPp->gpu__DOT__program_memory_controller__DOT____Vlvbound6 
                                = (1U & vlTOPp->gpu__DOT__program_memory_controller__DOT__j);
                            vlTOPp->gpu__DOT__program_memory_controller__DOT__current_consumer[0U] 
                                = vlTOPp->gpu__DOT__program_memory_controller__DOT____Vlvbound6;
                            vlTOPp->gpu__DOT__program_memory_controller__DOT____Vlvbound8 
                                = vlTOPp->gpu__DOT____Vcellinp__program_memory_controller__consumer_read_address
                                [(1U & vlTOPp->gpu__DOT__program_memory_controller__DOT__j)];
                            vlTOPp->gpu__DOT____Vcellout__program_memory_controller__mem_read_address[0U] 
                                = vlTOPp->gpu__DOT__program_memory_controller__DOT____Vlvbound8;
                            vlTOPp->gpu__DOT__program_memory_controller__DOT__j = 2U;
                        }
                        vlTOPp->gpu__DOT__program_memory_controller__DOT__j 
                            = ((IData)(1U) + vlTOPp->gpu__DOT__program_memory_controller__DOT__j);
                    }
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->data_mem_read_valid = 0U;
        vlTOPp->data_mem_write_valid = 0U;
        vlTOPp->gpu__DOT__lsu_read_ready = 0U;
        vlTOPp->gpu__DOT__lsu_write_ready = 0U;
        vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_read_address[0U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_address[0U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_data[0U] = 0U;
        vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer[0U] = 0U;
        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[0U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data[0U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_read_address[1U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_address[1U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_data[1U] = 0U;
        vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer[1U] = 0U;
        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[1U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data[1U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_read_address[2U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_address[2U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_data[2U] = 0U;
        vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer[2U] = 0U;
        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[2U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data[2U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_read_address[3U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_address[3U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_data[3U] = 0U;
        vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer[3U] = 0U;
        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[3U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data[3U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_read_address[4U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_address[4U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_data[4U] = 0U;
        vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer[4U] = 0U;
        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[4U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data[4U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_read_address[5U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_address[5U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_data[5U] = 0U;
        vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer[5U] = 0U;
        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[5U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data[5U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_read_address[6U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_address[6U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_data[6U] = 0U;
        vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer[6U] = 0U;
        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[6U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data[6U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_read_address[7U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_address[7U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_data[7U] = 0U;
        vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer[7U] = 0U;
        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[7U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data[7U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data[8U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data[9U] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data[0xaU] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data[0xbU] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data[0xcU] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data[0xdU] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data[0xeU] = 0U;
        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data[0xfU] = 0U;
    } else {
        if ((4U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
             [0U])) {
            if ((2U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                 [0U])) {
                vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[0U] = 0U;
            } else {
                if ((1U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                     [0U])) {
                    if ((1U & (~ ((IData)(vlTOPp->gpu__DOT__lsu_write_valid) 
                                  >> vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                  [0U])))) {
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                   [0U])) & (IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer));
                        vlTOPp->gpu__DOT__lsu_write_ready 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                   [0U])) & (IData)(vlTOPp->gpu__DOT__lsu_write_ready));
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[0U] = 0U;
                    }
                } else {
                    if ((1U & (~ ((IData)(vlTOPp->gpu__DOT__lsu_read_valid) 
                                  >> vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                  [0U])))) {
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                   [0U])) & (IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer));
                        vlTOPp->gpu__DOT__lsu_read_ready 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                   [0U])) & (IData)(vlTOPp->gpu__DOT__lsu_read_ready));
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[0U] = 0U;
                    }
                }
            }
        } else {
            if ((2U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                 [0U])) {
                if ((1U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                     [0U])) {
                    if ((1U & (IData)(vlTOPp->data_mem_write_ready))) {
                        vlTOPp->data_mem_write_valid 
                            = (0xfeU & (IData)(vlTOPp->data_mem_write_valid));
                        vlTOPp->gpu__DOT__lsu_write_ready 
                            = ((IData)(vlTOPp->gpu__DOT__lsu_write_ready) 
                               | ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                  [0U]));
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[0U] = 5U;
                    }
                } else {
                    if ((1U & (IData)(vlTOPp->data_mem_read_ready))) {
                        vlTOPp->data_mem_read_valid 
                            = (0xfeU & (IData)(vlTOPp->data_mem_read_valid));
                        vlTOPp->gpu__DOT__lsu_read_ready 
                            = ((IData)(vlTOPp->gpu__DOT__lsu_read_ready) 
                               | ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                  [0U]));
                        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data[vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer[0U]] 
                            = vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__mem_read_data
                            [0U];
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[0U] = 4U;
                    }
                }
            } else {
                if ((1U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                     [0U])) {
                    vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[0U] = 0U;
                } else {
                    vlTOPp->gpu__DOT__data_memory_controller__DOT__j = 0U;
                    while (VL_GTS_III(1,32,32, 0x10U, vlTOPp->gpu__DOT__data_memory_controller__DOT__j)) {
                        if ((1U & (((IData)(vlTOPp->gpu__DOT__lsu_read_valid) 
                                    >> (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)) 
                                   & (~ ((IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer) 
                                         >> (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)))))) {
                            vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer 
                                = ((IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer) 
                                   | ((IData)(1U) << 
                                      (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)));
                            vlTOPp->data_mem_read_valid 
                                = (1U | (IData)(vlTOPp->data_mem_read_valid));
                            vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[0U] = 2U;
                            vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer[0U] 
                                = (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j);
                            vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_read_address[0U] 
                                = vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address
                                [(0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)];
                            vlTOPp->gpu__DOT__data_memory_controller__DOT__j = 0x10U;
                        } else {
                            if ((1U & (((IData)(vlTOPp->gpu__DOT__lsu_write_valid) 
                                        >> (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)) 
                                       & (~ ((IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer) 
                                             >> (0xfU 
                                                 & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)))))) {
                                vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer 
                                    = ((IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer) 
                                       | ((IData)(1U) 
                                          << (0xfU 
                                              & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)));
                                vlTOPp->data_mem_write_valid 
                                    = (1U | (IData)(vlTOPp->data_mem_write_valid));
                                vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[0U] = 3U;
                                vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer[0U] 
                                    = (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j);
                                vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_address[0U] 
                                    = vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address
                                    [(0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)];
                                vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_data[0U] 
                                    = vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data
                                    [(0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)];
                                vlTOPp->gpu__DOT__data_memory_controller__DOT__j = 0x10U;
                            }
                        }
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__j 
                            = ((IData)(1U) + vlTOPp->gpu__DOT__data_memory_controller__DOT__j);
                    }
                }
            }
        }
        if ((4U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
             [1U])) {
            if ((2U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                 [1U])) {
                vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[1U] = 0U;
            } else {
                if ((1U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                     [1U])) {
                    if ((1U & (~ ((IData)(vlTOPp->gpu__DOT__lsu_write_valid) 
                                  >> vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                  [1U])))) {
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                   [1U])) & (IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer));
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[1U] = 0U;
                        vlTOPp->gpu__DOT__lsu_write_ready 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                   [1U])) & (IData)(vlTOPp->gpu__DOT__lsu_write_ready));
                    }
                } else {
                    if ((1U & (~ ((IData)(vlTOPp->gpu__DOT__lsu_read_valid) 
                                  >> vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                  [1U])))) {
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                   [1U])) & (IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer));
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[1U] = 0U;
                        vlTOPp->gpu__DOT__lsu_read_ready 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                   [1U])) & (IData)(vlTOPp->gpu__DOT__lsu_read_ready));
                    }
                }
            }
        } else {
            if ((2U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                 [1U])) {
                if ((1U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                     [1U])) {
                    if ((2U & (IData)(vlTOPp->data_mem_write_ready))) {
                        vlTOPp->data_mem_write_valid 
                            = (0xfdU & (IData)(vlTOPp->data_mem_write_valid));
                        vlTOPp->gpu__DOT__lsu_write_ready 
                            = ((IData)(vlTOPp->gpu__DOT__lsu_write_ready) 
                               | ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                  [1U]));
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[1U] = 5U;
                    }
                } else {
                    if ((2U & (IData)(vlTOPp->data_mem_read_ready))) {
                        vlTOPp->data_mem_read_valid 
                            = (0xfdU & (IData)(vlTOPp->data_mem_read_valid));
                        vlTOPp->gpu__DOT__lsu_read_ready 
                            = ((IData)(vlTOPp->gpu__DOT__lsu_read_ready) 
                               | ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                  [1U]));
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[1U] = 4U;
                        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data[vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer[1U]] 
                            = vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__mem_read_data
                            [1U];
                    }
                }
            } else {
                if ((1U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                     [1U])) {
                    vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[1U] = 0U;
                } else {
                    vlTOPp->gpu__DOT__data_memory_controller__DOT__j = 0U;
                    while (VL_GTS_III(1,32,32, 0x10U, vlTOPp->gpu__DOT__data_memory_controller__DOT__j)) {
                        if ((1U & (((IData)(vlTOPp->gpu__DOT__lsu_read_valid) 
                                    >> (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)) 
                                   & (~ ((IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer) 
                                         >> (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)))))) {
                            vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer 
                                = ((IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer) 
                                   | ((IData)(1U) << 
                                      (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)));
                            vlTOPp->data_mem_read_valid 
                                = (2U | (IData)(vlTOPp->data_mem_read_valid));
                            vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[1U] = 2U;
                            vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer[1U] 
                                = (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j);
                            vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_read_address[1U] 
                                = vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address
                                [(0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)];
                            vlTOPp->gpu__DOT__data_memory_controller__DOT__j = 0x10U;
                        } else {
                            if ((1U & (((IData)(vlTOPp->gpu__DOT__lsu_write_valid) 
                                        >> (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)) 
                                       & (~ ((IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer) 
                                             >> (0xfU 
                                                 & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)))))) {
                                vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer 
                                    = ((IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer) 
                                       | ((IData)(1U) 
                                          << (0xfU 
                                              & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)));
                                vlTOPp->data_mem_write_valid 
                                    = (2U | (IData)(vlTOPp->data_mem_write_valid));
                                vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[1U] = 3U;
                                vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer[1U] 
                                    = (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j);
                                vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_address[1U] 
                                    = vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address
                                    [(0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)];
                                vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_data[1U] 
                                    = vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data
                                    [(0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)];
                                vlTOPp->gpu__DOT__data_memory_controller__DOT__j = 0x10U;
                            }
                        }
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__j 
                            = ((IData)(1U) + vlTOPp->gpu__DOT__data_memory_controller__DOT__j);
                    }
                }
            }
        }
        if ((4U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
             [2U])) {
            if ((2U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                 [2U])) {
                vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[2U] = 0U;
            } else {
                if ((1U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                     [2U])) {
                    if ((1U & (~ ((IData)(vlTOPp->gpu__DOT__lsu_write_valid) 
                                  >> vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                  [2U])))) {
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                   [2U])) & (IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer));
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[2U] = 0U;
                        vlTOPp->gpu__DOT__lsu_write_ready 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                   [2U])) & (IData)(vlTOPp->gpu__DOT__lsu_write_ready));
                    }
                } else {
                    if ((1U & (~ ((IData)(vlTOPp->gpu__DOT__lsu_read_valid) 
                                  >> vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                  [2U])))) {
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                   [2U])) & (IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer));
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[2U] = 0U;
                        vlTOPp->gpu__DOT__lsu_read_ready 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                   [2U])) & (IData)(vlTOPp->gpu__DOT__lsu_read_ready));
                    }
                }
            }
        } else {
            if ((2U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                 [2U])) {
                if ((1U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                     [2U])) {
                    if ((4U & (IData)(vlTOPp->data_mem_write_ready))) {
                        vlTOPp->data_mem_write_valid 
                            = (0xfbU & (IData)(vlTOPp->data_mem_write_valid));
                        vlTOPp->gpu__DOT__lsu_write_ready 
                            = ((IData)(vlTOPp->gpu__DOT__lsu_write_ready) 
                               | ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                  [2U]));
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[2U] = 5U;
                    }
                } else {
                    if ((4U & (IData)(vlTOPp->data_mem_read_ready))) {
                        vlTOPp->data_mem_read_valid 
                            = (0xfbU & (IData)(vlTOPp->data_mem_read_valid));
                        vlTOPp->gpu__DOT__lsu_read_ready 
                            = ((IData)(vlTOPp->gpu__DOT__lsu_read_ready) 
                               | ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                  [2U]));
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[2U] = 4U;
                        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data[vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer[2U]] 
                            = vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__mem_read_data
                            [2U];
                    }
                }
            } else {
                if ((1U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                     [2U])) {
                    vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[2U] = 0U;
                } else {
                    vlTOPp->gpu__DOT__data_memory_controller__DOT__j = 0U;
                    while (VL_GTS_III(1,32,32, 0x10U, vlTOPp->gpu__DOT__data_memory_controller__DOT__j)) {
                        if ((1U & (((IData)(vlTOPp->gpu__DOT__lsu_read_valid) 
                                    >> (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)) 
                                   & (~ ((IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer) 
                                         >> (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)))))) {
                            vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer 
                                = ((IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer) 
                                   | ((IData)(1U) << 
                                      (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)));
                            vlTOPp->data_mem_read_valid 
                                = (4U | (IData)(vlTOPp->data_mem_read_valid));
                            vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[2U] = 2U;
                            vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer[2U] 
                                = (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j);
                            vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_read_address[2U] 
                                = vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address
                                [(0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)];
                            vlTOPp->gpu__DOT__data_memory_controller__DOT__j = 0x10U;
                        } else {
                            if ((1U & (((IData)(vlTOPp->gpu__DOT__lsu_write_valid) 
                                        >> (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)) 
                                       & (~ ((IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer) 
                                             >> (0xfU 
                                                 & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)))))) {
                                vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer 
                                    = ((IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer) 
                                       | ((IData)(1U) 
                                          << (0xfU 
                                              & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)));
                                vlTOPp->data_mem_write_valid 
                                    = (4U | (IData)(vlTOPp->data_mem_write_valid));
                                vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[2U] = 3U;
                                vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer[2U] 
                                    = (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j);
                                vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_address[2U] 
                                    = vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address
                                    [(0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)];
                                vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_data[2U] 
                                    = vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data
                                    [(0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)];
                                vlTOPp->gpu__DOT__data_memory_controller__DOT__j = 0x10U;
                            }
                        }
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__j 
                            = ((IData)(1U) + vlTOPp->gpu__DOT__data_memory_controller__DOT__j);
                    }
                }
            }
        }
        if ((4U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
             [3U])) {
            if ((2U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                 [3U])) {
                vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[3U] = 0U;
            } else {
                if ((1U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                     [3U])) {
                    if ((1U & (~ ((IData)(vlTOPp->gpu__DOT__lsu_write_valid) 
                                  >> vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                  [3U])))) {
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                   [3U])) & (IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer));
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[3U] = 0U;
                        vlTOPp->gpu__DOT__lsu_write_ready 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                   [3U])) & (IData)(vlTOPp->gpu__DOT__lsu_write_ready));
                    }
                } else {
                    if ((1U & (~ ((IData)(vlTOPp->gpu__DOT__lsu_read_valid) 
                                  >> vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                  [3U])))) {
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                   [3U])) & (IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer));
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[3U] = 0U;
                        vlTOPp->gpu__DOT__lsu_read_ready 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                   [3U])) & (IData)(vlTOPp->gpu__DOT__lsu_read_ready));
                    }
                }
            }
        } else {
            if ((2U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                 [3U])) {
                if ((1U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                     [3U])) {
                    if ((8U & (IData)(vlTOPp->data_mem_write_ready))) {
                        vlTOPp->data_mem_write_valid 
                            = (0xf7U & (IData)(vlTOPp->data_mem_write_valid));
                        vlTOPp->gpu__DOT__lsu_write_ready 
                            = ((IData)(vlTOPp->gpu__DOT__lsu_write_ready) 
                               | ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                  [3U]));
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[3U] = 5U;
                    }
                } else {
                    if ((8U & (IData)(vlTOPp->data_mem_read_ready))) {
                        vlTOPp->data_mem_read_valid 
                            = (0xf7U & (IData)(vlTOPp->data_mem_read_valid));
                        vlTOPp->gpu__DOT__lsu_read_ready 
                            = ((IData)(vlTOPp->gpu__DOT__lsu_read_ready) 
                               | ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                  [3U]));
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[3U] = 4U;
                        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data[vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer[3U]] 
                            = vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__mem_read_data
                            [3U];
                    }
                }
            } else {
                if ((1U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                     [3U])) {
                    vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[3U] = 0U;
                } else {
                    vlTOPp->gpu__DOT__data_memory_controller__DOT__j = 0U;
                    while (VL_GTS_III(1,32,32, 0x10U, vlTOPp->gpu__DOT__data_memory_controller__DOT__j)) {
                        if ((1U & (((IData)(vlTOPp->gpu__DOT__lsu_read_valid) 
                                    >> (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)) 
                                   & (~ ((IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer) 
                                         >> (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)))))) {
                            vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer 
                                = ((IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer) 
                                   | ((IData)(1U) << 
                                      (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)));
                            vlTOPp->data_mem_read_valid 
                                = (8U | (IData)(vlTOPp->data_mem_read_valid));
                            vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[3U] = 2U;
                            vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer[3U] 
                                = (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j);
                            vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_read_address[3U] 
                                = vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address
                                [(0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)];
                            vlTOPp->gpu__DOT__data_memory_controller__DOT__j = 0x10U;
                        } else {
                            if ((1U & (((IData)(vlTOPp->gpu__DOT__lsu_write_valid) 
                                        >> (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)) 
                                       & (~ ((IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer) 
                                             >> (0xfU 
                                                 & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)))))) {
                                vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer 
                                    = ((IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer) 
                                       | ((IData)(1U) 
                                          << (0xfU 
                                              & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)));
                                vlTOPp->data_mem_write_valid 
                                    = (8U | (IData)(vlTOPp->data_mem_write_valid));
                                vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[3U] = 3U;
                                vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer[3U] 
                                    = (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j);
                                vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_address[3U] 
                                    = vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address
                                    [(0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)];
                                vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_data[3U] 
                                    = vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data
                                    [(0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)];
                                vlTOPp->gpu__DOT__data_memory_controller__DOT__j = 0x10U;
                            }
                        }
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__j 
                            = ((IData)(1U) + vlTOPp->gpu__DOT__data_memory_controller__DOT__j);
                    }
                }
            }
        }
        if ((4U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
             [4U])) {
            if ((2U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                 [4U])) {
                vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[4U] = 0U;
            } else {
                if ((1U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                     [4U])) {
                    if ((1U & (~ ((IData)(vlTOPp->gpu__DOT__lsu_write_valid) 
                                  >> vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                  [4U])))) {
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                   [4U])) & (IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer));
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[4U] = 0U;
                        vlTOPp->gpu__DOT__lsu_write_ready 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                   [4U])) & (IData)(vlTOPp->gpu__DOT__lsu_write_ready));
                    }
                } else {
                    if ((1U & (~ ((IData)(vlTOPp->gpu__DOT__lsu_read_valid) 
                                  >> vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                  [4U])))) {
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                   [4U])) & (IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer));
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[4U] = 0U;
                        vlTOPp->gpu__DOT__lsu_read_ready 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                   [4U])) & (IData)(vlTOPp->gpu__DOT__lsu_read_ready));
                    }
                }
            }
        } else {
            if ((2U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                 [4U])) {
                if ((1U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                     [4U])) {
                    if ((0x10U & (IData)(vlTOPp->data_mem_write_ready))) {
                        vlTOPp->data_mem_write_valid 
                            = (0xefU & (IData)(vlTOPp->data_mem_write_valid));
                        vlTOPp->gpu__DOT__lsu_write_ready 
                            = ((IData)(vlTOPp->gpu__DOT__lsu_write_ready) 
                               | ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                  [4U]));
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[4U] = 5U;
                    }
                } else {
                    if ((0x10U & (IData)(vlTOPp->data_mem_read_ready))) {
                        vlTOPp->data_mem_read_valid 
                            = (0xefU & (IData)(vlTOPp->data_mem_read_valid));
                        vlTOPp->gpu__DOT__lsu_read_ready 
                            = ((IData)(vlTOPp->gpu__DOT__lsu_read_ready) 
                               | ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                  [4U]));
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[4U] = 4U;
                        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data[vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer[4U]] 
                            = vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__mem_read_data
                            [4U];
                    }
                }
            } else {
                if ((1U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                     [4U])) {
                    vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[4U] = 0U;
                } else {
                    vlTOPp->gpu__DOT__data_memory_controller__DOT__j = 0U;
                    while (VL_GTS_III(1,32,32, 0x10U, vlTOPp->gpu__DOT__data_memory_controller__DOT__j)) {
                        if ((1U & (((IData)(vlTOPp->gpu__DOT__lsu_read_valid) 
                                    >> (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)) 
                                   & (~ ((IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer) 
                                         >> (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)))))) {
                            vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer 
                                = ((IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer) 
                                   | ((IData)(1U) << 
                                      (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)));
                            vlTOPp->data_mem_read_valid 
                                = (0x10U | (IData)(vlTOPp->data_mem_read_valid));
                            vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[4U] = 2U;
                            vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer[4U] 
                                = (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j);
                            vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_read_address[4U] 
                                = vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address
                                [(0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)];
                            vlTOPp->gpu__DOT__data_memory_controller__DOT__j = 0x10U;
                        } else {
                            if ((1U & (((IData)(vlTOPp->gpu__DOT__lsu_write_valid) 
                                        >> (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)) 
                                       & (~ ((IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer) 
                                             >> (0xfU 
                                                 & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)))))) {
                                vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer 
                                    = ((IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer) 
                                       | ((IData)(1U) 
                                          << (0xfU 
                                              & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)));
                                vlTOPp->data_mem_write_valid 
                                    = (0x10U | (IData)(vlTOPp->data_mem_write_valid));
                                vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[4U] = 3U;
                                vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer[4U] 
                                    = (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j);
                                vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_address[4U] 
                                    = vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address
                                    [(0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)];
                                vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_data[4U] 
                                    = vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data
                                    [(0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)];
                                vlTOPp->gpu__DOT__data_memory_controller__DOT__j = 0x10U;
                            }
                        }
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__j 
                            = ((IData)(1U) + vlTOPp->gpu__DOT__data_memory_controller__DOT__j);
                    }
                }
            }
        }
        if ((4U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
             [5U])) {
            if ((2U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                 [5U])) {
                vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[5U] = 0U;
            } else {
                if ((1U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                     [5U])) {
                    if ((1U & (~ ((IData)(vlTOPp->gpu__DOT__lsu_write_valid) 
                                  >> vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                  [5U])))) {
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                   [5U])) & (IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer));
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[5U] = 0U;
                        vlTOPp->gpu__DOT__lsu_write_ready 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                   [5U])) & (IData)(vlTOPp->gpu__DOT__lsu_write_ready));
                    }
                } else {
                    if ((1U & (~ ((IData)(vlTOPp->gpu__DOT__lsu_read_valid) 
                                  >> vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                  [5U])))) {
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                   [5U])) & (IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer));
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[5U] = 0U;
                        vlTOPp->gpu__DOT__lsu_read_ready 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                   [5U])) & (IData)(vlTOPp->gpu__DOT__lsu_read_ready));
                    }
                }
            }
        } else {
            if ((2U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                 [5U])) {
                if ((1U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                     [5U])) {
                    if ((0x20U & (IData)(vlTOPp->data_mem_write_ready))) {
                        vlTOPp->data_mem_write_valid 
                            = (0xdfU & (IData)(vlTOPp->data_mem_write_valid));
                        vlTOPp->gpu__DOT__lsu_write_ready 
                            = ((IData)(vlTOPp->gpu__DOT__lsu_write_ready) 
                               | ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                  [5U]));
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[5U] = 5U;
                    }
                } else {
                    if ((0x20U & (IData)(vlTOPp->data_mem_read_ready))) {
                        vlTOPp->data_mem_read_valid 
                            = (0xdfU & (IData)(vlTOPp->data_mem_read_valid));
                        vlTOPp->gpu__DOT__lsu_read_ready 
                            = ((IData)(vlTOPp->gpu__DOT__lsu_read_ready) 
                               | ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                  [5U]));
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[5U] = 4U;
                        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data[vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer[5U]] 
                            = vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__mem_read_data
                            [5U];
                    }
                }
            } else {
                if ((1U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                     [5U])) {
                    vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[5U] = 0U;
                } else {
                    vlTOPp->gpu__DOT__data_memory_controller__DOT__j = 0U;
                    while (VL_GTS_III(1,32,32, 0x10U, vlTOPp->gpu__DOT__data_memory_controller__DOT__j)) {
                        if ((1U & (((IData)(vlTOPp->gpu__DOT__lsu_read_valid) 
                                    >> (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)) 
                                   & (~ ((IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer) 
                                         >> (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)))))) {
                            vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer 
                                = ((IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer) 
                                   | ((IData)(1U) << 
                                      (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)));
                            vlTOPp->data_mem_read_valid 
                                = (0x20U | (IData)(vlTOPp->data_mem_read_valid));
                            vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[5U] = 2U;
                            vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer[5U] 
                                = (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j);
                            vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_read_address[5U] 
                                = vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address
                                [(0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)];
                            vlTOPp->gpu__DOT__data_memory_controller__DOT__j = 0x10U;
                        } else {
                            if ((1U & (((IData)(vlTOPp->gpu__DOT__lsu_write_valid) 
                                        >> (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)) 
                                       & (~ ((IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer) 
                                             >> (0xfU 
                                                 & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)))))) {
                                vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer 
                                    = ((IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer) 
                                       | ((IData)(1U) 
                                          << (0xfU 
                                              & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)));
                                vlTOPp->data_mem_write_valid 
                                    = (0x20U | (IData)(vlTOPp->data_mem_write_valid));
                                vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[5U] = 3U;
                                vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer[5U] 
                                    = (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j);
                                vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_address[5U] 
                                    = vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address
                                    [(0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)];
                                vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_data[5U] 
                                    = vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data
                                    [(0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)];
                                vlTOPp->gpu__DOT__data_memory_controller__DOT__j = 0x10U;
                            }
                        }
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__j 
                            = ((IData)(1U) + vlTOPp->gpu__DOT__data_memory_controller__DOT__j);
                    }
                }
            }
        }
        if ((4U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
             [6U])) {
            if ((2U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                 [6U])) {
                vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[6U] = 0U;
            } else {
                if ((1U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                     [6U])) {
                    if ((1U & (~ ((IData)(vlTOPp->gpu__DOT__lsu_write_valid) 
                                  >> vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                  [6U])))) {
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                   [6U])) & (IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer));
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[6U] = 0U;
                        vlTOPp->gpu__DOT__lsu_write_ready 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                   [6U])) & (IData)(vlTOPp->gpu__DOT__lsu_write_ready));
                    }
                } else {
                    if ((1U & (~ ((IData)(vlTOPp->gpu__DOT__lsu_read_valid) 
                                  >> vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                  [6U])))) {
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                   [6U])) & (IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer));
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[6U] = 0U;
                        vlTOPp->gpu__DOT__lsu_read_ready 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                   [6U])) & (IData)(vlTOPp->gpu__DOT__lsu_read_ready));
                    }
                }
            }
        } else {
            if ((2U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                 [6U])) {
                if ((1U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                     [6U])) {
                    if ((0x40U & (IData)(vlTOPp->data_mem_write_ready))) {
                        vlTOPp->data_mem_write_valid 
                            = (0xbfU & (IData)(vlTOPp->data_mem_write_valid));
                        vlTOPp->gpu__DOT__lsu_write_ready 
                            = ((IData)(vlTOPp->gpu__DOT__lsu_write_ready) 
                               | ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                  [6U]));
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[6U] = 5U;
                    }
                } else {
                    if ((0x40U & (IData)(vlTOPp->data_mem_read_ready))) {
                        vlTOPp->data_mem_read_valid 
                            = (0xbfU & (IData)(vlTOPp->data_mem_read_valid));
                        vlTOPp->gpu__DOT__lsu_read_ready 
                            = ((IData)(vlTOPp->gpu__DOT__lsu_read_ready) 
                               | ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                  [6U]));
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[6U] = 4U;
                        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data[vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer[6U]] 
                            = vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__mem_read_data
                            [6U];
                    }
                }
            } else {
                if ((1U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                     [6U])) {
                    vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[6U] = 0U;
                } else {
                    vlTOPp->gpu__DOT__data_memory_controller__DOT__j = 0U;
                    while (VL_GTS_III(1,32,32, 0x10U, vlTOPp->gpu__DOT__data_memory_controller__DOT__j)) {
                        if ((1U & (((IData)(vlTOPp->gpu__DOT__lsu_read_valid) 
                                    >> (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)) 
                                   & (~ ((IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer) 
                                         >> (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)))))) {
                            vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer 
                                = ((IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer) 
                                   | ((IData)(1U) << 
                                      (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)));
                            vlTOPp->data_mem_read_valid 
                                = (0x40U | (IData)(vlTOPp->data_mem_read_valid));
                            vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[6U] = 2U;
                            vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer[6U] 
                                = (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j);
                            vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_read_address[6U] 
                                = vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address
                                [(0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)];
                            vlTOPp->gpu__DOT__data_memory_controller__DOT__j = 0x10U;
                        } else {
                            if ((1U & (((IData)(vlTOPp->gpu__DOT__lsu_write_valid) 
                                        >> (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)) 
                                       & (~ ((IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer) 
                                             >> (0xfU 
                                                 & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)))))) {
                                vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer 
                                    = ((IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer) 
                                       | ((IData)(1U) 
                                          << (0xfU 
                                              & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)));
                                vlTOPp->data_mem_write_valid 
                                    = (0x40U | (IData)(vlTOPp->data_mem_write_valid));
                                vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[6U] = 3U;
                                vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer[6U] 
                                    = (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j);
                                vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_address[6U] 
                                    = vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address
                                    [(0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)];
                                vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_data[6U] 
                                    = vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data
                                    [(0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)];
                                vlTOPp->gpu__DOT__data_memory_controller__DOT__j = 0x10U;
                            }
                        }
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__j 
                            = ((IData)(1U) + vlTOPp->gpu__DOT__data_memory_controller__DOT__j);
                    }
                }
            }
        }
        if ((4U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
             [7U])) {
            if ((2U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                 [7U])) {
                vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[7U] = 0U;
            } else {
                if ((1U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                     [7U])) {
                    if ((1U & (~ ((IData)(vlTOPp->gpu__DOT__lsu_write_valid) 
                                  >> vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                  [7U])))) {
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                   [7U])) & (IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer));
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[7U] = 0U;
                        vlTOPp->gpu__DOT__lsu_write_ready 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                   [7U])) & (IData)(vlTOPp->gpu__DOT__lsu_write_ready));
                    }
                } else {
                    if ((1U & (~ ((IData)(vlTOPp->gpu__DOT__lsu_read_valid) 
                                  >> vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                  [7U])))) {
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                   [7U])) & (IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer));
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[7U] = 0U;
                        vlTOPp->gpu__DOT__lsu_read_ready 
                            = ((~ ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                   [7U])) & (IData)(vlTOPp->gpu__DOT__lsu_read_ready));
                    }
                }
            }
        } else {
            if ((2U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                 [7U])) {
                if ((1U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                     [7U])) {
                    if ((0x80U & (IData)(vlTOPp->data_mem_write_ready))) {
                        vlTOPp->data_mem_write_valid 
                            = (0x7fU & (IData)(vlTOPp->data_mem_write_valid));
                        vlTOPp->gpu__DOT__lsu_write_ready 
                            = ((IData)(vlTOPp->gpu__DOT__lsu_write_ready) 
                               | ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                  [7U]));
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[7U] = 5U;
                    }
                } else {
                    if ((0x80U & (IData)(vlTOPp->data_mem_read_ready))) {
                        vlTOPp->data_mem_read_valid 
                            = (0x7fU & (IData)(vlTOPp->data_mem_read_valid));
                        vlTOPp->gpu__DOT__lsu_read_ready 
                            = ((IData)(vlTOPp->gpu__DOT__lsu_read_ready) 
                               | ((IData)(1U) << vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer
                                  [7U]));
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[7U] = 4U;
                        vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data[vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer[7U]] 
                            = vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__mem_read_data
                            [7U];
                    }
                }
            } else {
                if ((1U & vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state
                     [7U])) {
                    vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[7U] = 0U;
                } else {
                    vlTOPp->gpu__DOT__data_memory_controller__DOT__j = 0U;
                    while (VL_GTS_III(1,32,32, 0x10U, vlTOPp->gpu__DOT__data_memory_controller__DOT__j)) {
                        if ((1U & (((IData)(vlTOPp->gpu__DOT__lsu_read_valid) 
                                    >> (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)) 
                                   & (~ ((IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer) 
                                         >> (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)))))) {
                            vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer 
                                = ((IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer) 
                                   | ((IData)(1U) << 
                                      (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)));
                            vlTOPp->data_mem_read_valid 
                                = (0x80U | (IData)(vlTOPp->data_mem_read_valid));
                            vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[7U] = 2U;
                            vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer[7U] 
                                = (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j);
                            vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_read_address[7U] 
                                = vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address
                                [(0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)];
                            vlTOPp->gpu__DOT__data_memory_controller__DOT__j = 0x10U;
                        } else {
                            if ((1U & (((IData)(vlTOPp->gpu__DOT__lsu_write_valid) 
                                        >> (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)) 
                                       & (~ ((IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer) 
                                             >> (0xfU 
                                                 & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)))))) {
                                vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer 
                                    = ((IData)(vlTOPp->gpu__DOT__data_memory_controller__DOT__channel_serving_consumer) 
                                       | ((IData)(1U) 
                                          << (0xfU 
                                              & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)));
                                vlTOPp->data_mem_write_valid 
                                    = (0x80U | (IData)(vlTOPp->data_mem_write_valid));
                                vlTOPp->gpu__DOT__data_memory_controller__DOT__controller_state[7U] = 3U;
                                vlTOPp->gpu__DOT__data_memory_controller__DOT__current_consumer[7U] 
                                    = (0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j);
                                vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_address[7U] 
                                    = vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address
                                    [(0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)];
                                vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_data[7U] 
                                    = vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data
                                    [(0xfU & vlTOPp->gpu__DOT__data_memory_controller__DOT__j)];
                                vlTOPp->gpu__DOT__data_memory_controller__DOT__j = 0x10U;
                            }
                        }
                        vlTOPp->gpu__DOT__data_memory_controller__DOT__j 
                            = ((IData)(1U) + vlTOPp->gpu__DOT__data_memory_controller__DOT__j);
                    }
                }
            }
        }
    }
    if (vlTOPp->reset) {
        vlTOPp->gpu__DOT__dispatch_instance__DOT__blocks_dispatched = 0U;
        vlTOPp->gpu__DOT__dispatch_instance__DOT__blocks_done = 0U;
        vlTOPp->done = 0U;
        __Vdly__gpu__DOT__dispatch_instance__DOT__start_execution = 0U;
        vlTOPp->__Vdly__gpu__DOT__core_start = (2U 
                                                & (IData)(vlTOPp->__Vdly__gpu__DOT__core_start));
        vlTOPp->__Vdly__gpu__DOT__core_reset = (1U 
                                                | (IData)(vlTOPp->__Vdly__gpu__DOT__core_reset));
        __Vdlyvset__gpu__DOT____Vcellout__dispatch_instance__core_block_id__v0 = 1U;
        vlTOPp->__Vdly__gpu__DOT__core_start = (1U 
                                                & (IData)(vlTOPp->__Vdly__gpu__DOT__core_start));
        vlTOPp->__Vdly__gpu__DOT__core_reset = (2U 
                                                | (IData)(vlTOPp->__Vdly__gpu__DOT__core_reset));
        __Vdlyvset__gpu__DOT____Vcellout__dispatch_instance__core_block_id__v1 = 1U;
    } else {
        if (vlTOPp->start) {
            if ((1U & (~ (IData)(vlTOPp->gpu__DOT__dispatch_instance__DOT__start_execution)))) {
                __Vdly__gpu__DOT__dispatch_instance__DOT__start_execution = 1U;
                vlTOPp->__Vdly__gpu__DOT__core_reset 
                    = (1U | (IData)(vlTOPp->__Vdly__gpu__DOT__core_reset));
                vlTOPp->__Vdly__gpu__DOT__core_reset 
                    = (2U | (IData)(vlTOPp->__Vdly__gpu__DOT__core_reset));
            }
            if (((IData)(vlTOPp->gpu__DOT__dispatch_instance__DOT__blocks_done) 
                 == (0xffU & (((IData)(7U) + (IData)(vlTOPp->gpu__DOT__dcr_instance__DOT__device_conrol_register)) 
                              >> 3U)))) {
                vlTOPp->done = 1U;
            }
            if ((1U & (IData)(vlTOPp->gpu__DOT__core_reset))) {
                vlTOPp->__Vdly__gpu__DOT__core_reset 
                    = (2U & (IData)(vlTOPp->__Vdly__gpu__DOT__core_reset));
                if (((IData)(vlTOPp->gpu__DOT__dispatch_instance__DOT__blocks_dispatched) 
                     < (0xffU & (((IData)(7U) + (IData)(vlTOPp->gpu__DOT__dcr_instance__DOT__device_conrol_register)) 
                                 >> 3U)))) {
                    vlTOPp->__Vdly__gpu__DOT__core_start 
                        = (1U | (IData)(vlTOPp->__Vdly__gpu__DOT__core_start));
                    __Vdlyvval__gpu__DOT____Vcellout__dispatch_instance__core_block_id__v2 
                        = vlTOPp->gpu__DOT__dispatch_instance__DOT__blocks_dispatched;
                    __Vdlyvset__gpu__DOT____Vcellout__dispatch_instance__core_block_id__v2 = 1U;
                    __Vdlyvval__gpu__DOT____Vcellout__dispatch_instance__core_thread_count__v2 
                        = (((IData)(vlTOPp->gpu__DOT__dispatch_instance__DOT__blocks_dispatched) 
                            == ((0xffU & (((IData)(7U) 
                                           + (IData)(vlTOPp->gpu__DOT__dcr_instance__DOT__device_conrol_register)) 
                                          >> 3U)) - (IData)(1U)))
                            ? (0xfU & ((IData)(vlTOPp->gpu__DOT__dcr_instance__DOT__device_conrol_register) 
                                       - ((IData)(vlTOPp->gpu__DOT__dispatch_instance__DOT__blocks_dispatched) 
                                          << 3U))) : 8U);
                    vlTOPp->gpu__DOT__dispatch_instance__DOT__blocks_dispatched 
                        = (0xffU & ((IData)(1U) + (IData)(vlTOPp->gpu__DOT__dispatch_instance__DOT__blocks_dispatched)));
                }
            }
            if ((2U & (IData)(vlTOPp->gpu__DOT__core_reset))) {
                vlTOPp->__Vdly__gpu__DOT__core_reset 
                    = (1U & (IData)(vlTOPp->__Vdly__gpu__DOT__core_reset));
                if (((IData)(vlTOPp->gpu__DOT__dispatch_instance__DOT__blocks_dispatched) 
                     < (0xffU & (((IData)(7U) + (IData)(vlTOPp->gpu__DOT__dcr_instance__DOT__device_conrol_register)) 
                                 >> 3U)))) {
                    vlTOPp->__Vdly__gpu__DOT__core_start 
                        = (2U | (IData)(vlTOPp->__Vdly__gpu__DOT__core_start));
                    __Vdlyvval__gpu__DOT____Vcellout__dispatch_instance__core_block_id__v3 
                        = vlTOPp->gpu__DOT__dispatch_instance__DOT__blocks_dispatched;
                    __Vdlyvset__gpu__DOT____Vcellout__dispatch_instance__core_block_id__v3 = 1U;
                    __Vdlyvval__gpu__DOT____Vcellout__dispatch_instance__core_thread_count__v3 
                        = (((IData)(vlTOPp->gpu__DOT__dispatch_instance__DOT__blocks_dispatched) 
                            == ((0xffU & (((IData)(7U) 
                                           + (IData)(vlTOPp->gpu__DOT__dcr_instance__DOT__device_conrol_register)) 
                                          >> 3U)) - (IData)(1U)))
                            ? (0xfU & ((IData)(vlTOPp->gpu__DOT__dcr_instance__DOT__device_conrol_register) 
                                       - ((IData)(vlTOPp->gpu__DOT__dispatch_instance__DOT__blocks_dispatched) 
                                          << 3U))) : 8U);
                    vlTOPp->gpu__DOT__dispatch_instance__DOT__blocks_dispatched 
                        = (0xffU & ((IData)(1U) + (IData)(vlTOPp->gpu__DOT__dispatch_instance__DOT__blocks_dispatched)));
                }
            }
            if ((1U & ((IData)(vlTOPp->gpu__DOT__core_start) 
                       & (IData)(vlTOPp->gpu__DOT__core_done)))) {
                vlTOPp->gpu__DOT__dispatch_instance__DOT__blocks_done 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->gpu__DOT__dispatch_instance__DOT__blocks_done)));
                vlTOPp->__Vdly__gpu__DOT__core_reset 
                    = (1U | (IData)(vlTOPp->__Vdly__gpu__DOT__core_reset));
                vlTOPp->__Vdly__gpu__DOT__core_start 
                    = (2U & (IData)(vlTOPp->__Vdly__gpu__DOT__core_start));
            }
            if ((2U & ((IData)(vlTOPp->gpu__DOT__core_start) 
                       & (IData)(vlTOPp->gpu__DOT__core_done)))) {
                vlTOPp->gpu__DOT__dispatch_instance__DOT__blocks_done 
                    = (0xffU & ((IData)(1U) + (IData)(vlTOPp->gpu__DOT__dispatch_instance__DOT__blocks_done)));
                vlTOPp->__Vdly__gpu__DOT__core_reset 
                    = (2U | (IData)(vlTOPp->__Vdly__gpu__DOT__core_reset));
                vlTOPp->__Vdly__gpu__DOT__core_start 
                    = (1U & (IData)(vlTOPp->__Vdly__gpu__DOT__core_start));
            }
        }
    }
    vlTOPp->program_mem_read_address[0U] = vlTOPp->gpu__DOT____Vcellout__program_memory_controller__mem_read_address
        [0U];
    vlTOPp->data_mem_read_address[7U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_read_address
        [7U];
    vlTOPp->data_mem_read_address[6U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_read_address
        [6U];
    vlTOPp->data_mem_read_address[5U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_read_address
        [5U];
    vlTOPp->data_mem_read_address[4U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_read_address
        [4U];
    vlTOPp->data_mem_read_address[3U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_read_address
        [3U];
    vlTOPp->data_mem_read_address[2U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_read_address
        [2U];
    vlTOPp->data_mem_read_address[1U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_read_address
        [1U];
    vlTOPp->data_mem_read_address[0U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_read_address
        [0U];
    vlTOPp->data_mem_write_address[7U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_address
        [7U];
    vlTOPp->data_mem_write_address[6U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_address
        [6U];
    vlTOPp->data_mem_write_address[5U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_address
        [5U];
    vlTOPp->data_mem_write_address[4U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_address
        [4U];
    vlTOPp->data_mem_write_address[3U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_address
        [3U];
    vlTOPp->data_mem_write_address[2U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_address
        [2U];
    vlTOPp->data_mem_write_address[1U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_address
        [1U];
    vlTOPp->data_mem_write_address[0U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_address
        [0U];
    vlTOPp->data_mem_write_data[7U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_data
        [7U];
    vlTOPp->data_mem_write_data[6U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_data
        [6U];
    vlTOPp->data_mem_write_data[5U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_data
        [5U];
    vlTOPp->data_mem_write_data[4U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_data
        [4U];
    vlTOPp->data_mem_write_data[3U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_data
        [3U];
    vlTOPp->data_mem_write_data[2U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_data
        [2U];
    vlTOPp->data_mem_write_data[1U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_data
        [1U];
    vlTOPp->data_mem_write_data[0U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_data
        [0U];
    vlTOPp->gpu__DOT__lsu_read_data[0xfU] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data
        [0xfU];
    vlTOPp->gpu__DOT__lsu_read_data[0xeU] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data
        [0xeU];
    vlTOPp->gpu__DOT__lsu_read_data[0xdU] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data
        [0xdU];
    vlTOPp->gpu__DOT__lsu_read_data[0xcU] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data
        [0xcU];
    vlTOPp->gpu__DOT__lsu_read_data[0xbU] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data
        [0xbU];
    vlTOPp->gpu__DOT__lsu_read_data[0xaU] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data
        [0xaU];
    vlTOPp->gpu__DOT__lsu_read_data[9U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data
        [9U];
    vlTOPp->gpu__DOT__lsu_read_data[8U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data
        [8U];
    vlTOPp->gpu__DOT__lsu_read_data[7U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data
        [7U];
    vlTOPp->gpu__DOT__lsu_read_data[6U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data
        [6U];
    vlTOPp->gpu__DOT__lsu_read_data[5U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data
        [5U];
    vlTOPp->gpu__DOT__lsu_read_data[4U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data
        [4U];
    vlTOPp->gpu__DOT__lsu_read_data[3U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data
        [3U];
    vlTOPp->gpu__DOT__lsu_read_data[2U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data
        [2U];
    vlTOPp->gpu__DOT__lsu_read_data[1U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data
        [1U];
    vlTOPp->gpu__DOT__lsu_read_data[0U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data
        [0U];
    vlTOPp->gpu__DOT__dispatch_instance__DOT__start_execution 
        = __Vdly__gpu__DOT__dispatch_instance__DOT__start_execution;
    if (__Vdlyvset__gpu__DOT____Vcellout__dispatch_instance__core_block_id__v0) {
        vlTOPp->gpu__DOT____Vcellout__dispatch_instance__core_thread_count[0U] = 8U;
    }
    if (__Vdlyvset__gpu__DOT____Vcellout__dispatch_instance__core_block_id__v1) {
        vlTOPp->gpu__DOT____Vcellout__dispatch_instance__core_thread_count[1U] = 8U;
    }
    if (__Vdlyvset__gpu__DOT____Vcellout__dispatch_instance__core_block_id__v2) {
        vlTOPp->gpu__DOT____Vcellout__dispatch_instance__core_thread_count[0U] 
            = __Vdlyvval__gpu__DOT____Vcellout__dispatch_instance__core_thread_count__v2;
    }
    if (__Vdlyvset__gpu__DOT____Vcellout__dispatch_instance__core_block_id__v3) {
        vlTOPp->gpu__DOT____Vcellout__dispatch_instance__core_thread_count[1U] 
            = __Vdlyvval__gpu__DOT____Vcellout__dispatch_instance__core_thread_count__v3;
    }
    if (__Vdlyvset__gpu__DOT____Vcellout__dispatch_instance__core_block_id__v0) {
        vlTOPp->gpu__DOT____Vcellout__dispatch_instance__core_block_id[0U] = 0U;
    }
    if (__Vdlyvset__gpu__DOT____Vcellout__dispatch_instance__core_block_id__v1) {
        vlTOPp->gpu__DOT____Vcellout__dispatch_instance__core_block_id[1U] = 0U;
    }
    if (__Vdlyvset__gpu__DOT____Vcellout__dispatch_instance__core_block_id__v2) {
        vlTOPp->gpu__DOT____Vcellout__dispatch_instance__core_block_id[0U] 
            = __Vdlyvval__gpu__DOT____Vcellout__dispatch_instance__core_block_id__v2;
    }
    if (__Vdlyvset__gpu__DOT____Vcellout__dispatch_instance__core_block_id__v3) {
        vlTOPp->gpu__DOT____Vcellout__dispatch_instance__core_block_id[1U] 
            = __Vdlyvval__gpu__DOT____Vcellout__dispatch_instance__core_block_id__v3;
    }
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data[0U] 
        = vlTOPp->gpu__DOT__lsu_read_data[0U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data[1U] 
        = vlTOPp->gpu__DOT__lsu_read_data[1U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data[2U] 
        = vlTOPp->gpu__DOT__lsu_read_data[2U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data[3U] 
        = vlTOPp->gpu__DOT__lsu_read_data[3U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data[4U] 
        = vlTOPp->gpu__DOT__lsu_read_data[4U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data[5U] 
        = vlTOPp->gpu__DOT__lsu_read_data[5U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data[6U] 
        = vlTOPp->gpu__DOT__lsu_read_data[6U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data[7U] 
        = vlTOPp->gpu__DOT__lsu_read_data[7U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data[0U] 
        = vlTOPp->gpu__DOT__lsu_read_data[8U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data[1U] 
        = vlTOPp->gpu__DOT__lsu_read_data[9U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data[2U] 
        = vlTOPp->gpu__DOT__lsu_read_data[0xaU];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data[3U] 
        = vlTOPp->gpu__DOT__lsu_read_data[0xbU];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data[4U] 
        = vlTOPp->gpu__DOT__lsu_read_data[0xcU];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data[5U] 
        = vlTOPp->gpu__DOT__lsu_read_data[0xdU];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data[6U] 
        = vlTOPp->gpu__DOT__lsu_read_data[0xeU];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data[7U] 
        = vlTOPp->gpu__DOT__lsu_read_data[0xfU];
    if (vlTOPp->reset) {
        vlTOPp->gpu__DOT__dcr_instance__DOT__device_conrol_register = 0U;
    } else {
        if (vlTOPp->device_control_write_enable) {
            vlTOPp->gpu__DOT__dcr_instance__DOT__device_conrol_register 
                = vlTOPp->device_control_data;
        }
    }
    vlTOPp->gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data[7U] 
        = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data
        [7U];
    vlTOPp->gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data[6U] 
        = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data
        [6U];
    vlTOPp->gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data[5U] 
        = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data
        [5U];
    vlTOPp->gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data[4U] 
        = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data
        [4U];
    vlTOPp->gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data[3U] 
        = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data
        [3U];
    vlTOPp->gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data[2U] 
        = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data
        [2U];
    vlTOPp->gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data[1U] 
        = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data
        [1U];
    vlTOPp->gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data[0U] 
        = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data
        [0U];
    vlTOPp->gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data[7U] 
        = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data
        [7U];
    vlTOPp->gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data[6U] 
        = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data
        [6U];
    vlTOPp->gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data[5U] 
        = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data
        [5U];
    vlTOPp->gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data[4U] 
        = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data
        [4U];
    vlTOPp->gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data[3U] 
        = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data
        [3U];
    vlTOPp->gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data[2U] 
        = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data
        [2U];
    vlTOPp->gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data[1U] 
        = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data
        [1U];
    vlTOPp->gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data[0U] 
        = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data
        [0U];
}

VL_INLINE_OPT void Vgpu::_sequent__TOP__2(Vgpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgpu::_sequent__TOP__2\n"); );
    Vgpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready 
        = ((0xfeU & (IData)(vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready)) 
           | (1U & (IData)(vlTOPp->gpu__DOT__lsu_read_ready)));
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready 
        = ((0xfdU & (IData)(vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready)) 
           | (2U & (IData)(vlTOPp->gpu__DOT__lsu_read_ready)));
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready 
        = ((0xfbU & (IData)(vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready)) 
           | (4U & (IData)(vlTOPp->gpu__DOT__lsu_read_ready)));
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready 
        = ((0xf7U & (IData)(vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready)) 
           | (8U & (IData)(vlTOPp->gpu__DOT__lsu_read_ready)));
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready 
        = ((0xefU & (IData)(vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready)) 
           | (0x10U & (IData)(vlTOPp->gpu__DOT__lsu_read_ready)));
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready 
        = ((0xdfU & (IData)(vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready)) 
           | (0x20U & (IData)(vlTOPp->gpu__DOT__lsu_read_ready)));
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready 
        = ((0xbfU & (IData)(vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready)) 
           | (0x40U & (IData)(vlTOPp->gpu__DOT__lsu_read_ready)));
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready 
        = ((0x7fU & (IData)(vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready)) 
           | (0x80U & (IData)(vlTOPp->gpu__DOT__lsu_read_ready)));
    vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_data[7U] 
        = vlTOPp->gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data
        [7U];
    vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_data[6U] 
        = vlTOPp->gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data
        [6U];
    vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_data[5U] 
        = vlTOPp->gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data
        [5U];
    vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_data[4U] 
        = vlTOPp->gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data
        [4U];
    vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_data[3U] 
        = vlTOPp->gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data
        [3U];
    vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_data[2U] 
        = vlTOPp->gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data
        [2U];
    vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_data[1U] 
        = vlTOPp->gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data
        [1U];
    vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_data[0U] 
        = vlTOPp->gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data
        [0U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready 
        = ((0xfeU & (IData)(vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready)) 
           | (1U & (IData)(vlTOPp->gpu__DOT__lsu_write_ready)));
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready 
        = ((0xfdU & (IData)(vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready)) 
           | (2U & (IData)(vlTOPp->gpu__DOT__lsu_write_ready)));
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready 
        = ((0xfbU & (IData)(vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready)) 
           | (4U & (IData)(vlTOPp->gpu__DOT__lsu_write_ready)));
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready 
        = ((0xf7U & (IData)(vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready)) 
           | (8U & (IData)(vlTOPp->gpu__DOT__lsu_write_ready)));
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready 
        = ((0xefU & (IData)(vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready)) 
           | (0x10U & (IData)(vlTOPp->gpu__DOT__lsu_write_ready)));
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready 
        = ((0xdfU & (IData)(vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready)) 
           | (0x20U & (IData)(vlTOPp->gpu__DOT__lsu_write_ready)));
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready 
        = ((0xbfU & (IData)(vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready)) 
           | (0x40U & (IData)(vlTOPp->gpu__DOT__lsu_write_ready)));
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready 
        = ((0x7fU & (IData)(vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready)) 
           | (0x80U & (IData)(vlTOPp->gpu__DOT__lsu_write_ready)));
    vlTOPp->gpu__DOT__core_done = ((2U & (IData)(vlTOPp->gpu__DOT__core_done)) 
                                   | (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.done));
    vlTOPp->gpu__DOT__lsu_read_valid = ((0xfffeU & (IData)(vlTOPp->gpu__DOT__lsu_read_valid)) 
                                        | (1U & (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_valid)));
    vlTOPp->gpu__DOT__lsu_read_valid = ((0xfffdU & (IData)(vlTOPp->gpu__DOT__lsu_read_valid)) 
                                        | (2U & (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_valid)));
    vlTOPp->gpu__DOT__lsu_read_valid = ((0xfffbU & (IData)(vlTOPp->gpu__DOT__lsu_read_valid)) 
                                        | (4U & (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_valid)));
    vlTOPp->gpu__DOT__lsu_read_valid = ((0xfff7U & (IData)(vlTOPp->gpu__DOT__lsu_read_valid)) 
                                        | (8U & (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_valid)));
    vlTOPp->gpu__DOT__lsu_read_valid = ((0xffefU & (IData)(vlTOPp->gpu__DOT__lsu_read_valid)) 
                                        | (0x10U & (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_valid)));
    vlTOPp->gpu__DOT__lsu_read_valid = ((0xffdfU & (IData)(vlTOPp->gpu__DOT__lsu_read_valid)) 
                                        | (0x20U & (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_valid)));
    vlTOPp->gpu__DOT__lsu_read_valid = ((0xffbfU & (IData)(vlTOPp->gpu__DOT__lsu_read_valid)) 
                                        | (0x40U & (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_valid)));
    vlTOPp->gpu__DOT__lsu_read_valid = ((0xff7fU & (IData)(vlTOPp->gpu__DOT__lsu_read_valid)) 
                                        | (0x80U & (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_valid)));
    vlTOPp->gpu__DOT__lsu_write_valid = ((0xfffeU & (IData)(vlTOPp->gpu__DOT__lsu_write_valid)) 
                                         | (1U & (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_valid)));
    vlTOPp->gpu__DOT__lsu_write_valid = ((0xfffdU & (IData)(vlTOPp->gpu__DOT__lsu_write_valid)) 
                                         | (2U & (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_valid)));
    vlTOPp->gpu__DOT__lsu_write_valid = ((0xfffbU & (IData)(vlTOPp->gpu__DOT__lsu_write_valid)) 
                                         | (4U & (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_valid)));
    vlTOPp->gpu__DOT__lsu_write_valid = ((0xfff7U & (IData)(vlTOPp->gpu__DOT__lsu_write_valid)) 
                                         | (8U & (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_valid)));
    vlTOPp->gpu__DOT__lsu_write_valid = ((0xffefU & (IData)(vlTOPp->gpu__DOT__lsu_write_valid)) 
                                         | (0x10U & (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_valid)));
    vlTOPp->gpu__DOT__lsu_write_valid = ((0xffdfU & (IData)(vlTOPp->gpu__DOT__lsu_write_valid)) 
                                         | (0x20U & (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_valid)));
    vlTOPp->gpu__DOT__lsu_write_valid = ((0xffbfU & (IData)(vlTOPp->gpu__DOT__lsu_write_valid)) 
                                         | (0x40U & (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_valid)));
    vlTOPp->gpu__DOT__lsu_write_valid = ((0xff7fU & (IData)(vlTOPp->gpu__DOT__lsu_write_valid)) 
                                         | (0x80U & (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_valid)));
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address[7U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_address
        [7U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address[6U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_address
        [6U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address[5U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_address
        [5U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address[4U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_address
        [4U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address[3U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_address
        [3U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address[2U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_address
        [2U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address[1U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_address
        [1U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address[0U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_address
        [0U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address[7U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_address
        [7U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address[6U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_address
        [6U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address[5U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_address
        [5U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address[4U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_address
        [4U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address[3U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_address
        [3U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address[2U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_address
        [2U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address[1U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_address
        [1U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address[0U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_address
        [0U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data[7U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_data
        [7U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data[6U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_data
        [6U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data[5U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_data
        [5U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data[4U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_data
        [4U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data[3U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_data
        [3U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data[2U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_data
        [2U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data[1U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_data
        [1U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data[0U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_data
        [0U];
    vlTOPp->gpu__DOT__fetcher_read_valid = ((2U & (IData)(vlTOPp->gpu__DOT__fetcher_read_valid)) 
                                            | (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.program_mem_read_valid));
    vlTOPp->gpu__DOT__fetcher_read_address[0U] = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.program_mem_read_address;
    vlTOPp->gpu__DOT__core_start = vlTOPp->__Vdly__gpu__DOT__core_start;
    vlTOPp->gpu__DOT__core_block_id[1U] = vlTOPp->gpu__DOT____Vcellout__dispatch_instance__core_block_id
        [1U];
    vlTOPp->gpu__DOT__core_block_id[0U] = vlTOPp->gpu__DOT____Vcellout__dispatch_instance__core_block_id
        [0U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready 
        = ((0xfeU & (IData)(vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready)) 
           | (1U & ((IData)(vlTOPp->gpu__DOT__lsu_read_ready) 
                    >> 8U)));
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready 
        = ((0xfdU & (IData)(vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready)) 
           | (2U & ((IData)(vlTOPp->gpu__DOT__lsu_read_ready) 
                    >> 8U)));
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready 
        = ((0xfbU & (IData)(vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready)) 
           | (4U & ((IData)(vlTOPp->gpu__DOT__lsu_read_ready) 
                    >> 8U)));
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready 
        = ((0xf7U & (IData)(vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready)) 
           | (8U & ((IData)(vlTOPp->gpu__DOT__lsu_read_ready) 
                    >> 8U)));
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready 
        = ((0xefU & (IData)(vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready)) 
           | (0x10U & ((IData)(vlTOPp->gpu__DOT__lsu_read_ready) 
                       >> 8U)));
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready 
        = ((0xdfU & (IData)(vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready)) 
           | (0x20U & ((IData)(vlTOPp->gpu__DOT__lsu_read_ready) 
                       >> 8U)));
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready 
        = ((0xbfU & (IData)(vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready)) 
           | (0x40U & ((IData)(vlTOPp->gpu__DOT__lsu_read_ready) 
                       >> 8U)));
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready 
        = ((0x7fU & (IData)(vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready)) 
           | (0x80U & ((IData)(vlTOPp->gpu__DOT__lsu_read_ready) 
                       >> 8U)));
    vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_data[7U] 
        = vlTOPp->gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data
        [7U];
    vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_data[6U] 
        = vlTOPp->gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data
        [6U];
    vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_data[5U] 
        = vlTOPp->gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data
        [5U];
    vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_data[4U] 
        = vlTOPp->gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data
        [4U];
    vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_data[3U] 
        = vlTOPp->gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data
        [3U];
    vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_data[2U] 
        = vlTOPp->gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data
        [2U];
    vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_data[1U] 
        = vlTOPp->gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data
        [1U];
    vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_data[0U] 
        = vlTOPp->gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data
        [0U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready 
        = ((0xfeU & (IData)(vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready)) 
           | (1U & ((IData)(vlTOPp->gpu__DOT__lsu_write_ready) 
                    >> 8U)));
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready 
        = ((0xfdU & (IData)(vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready)) 
           | (2U & ((IData)(vlTOPp->gpu__DOT__lsu_write_ready) 
                    >> 8U)));
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready 
        = ((0xfbU & (IData)(vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready)) 
           | (4U & ((IData)(vlTOPp->gpu__DOT__lsu_write_ready) 
                    >> 8U)));
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready 
        = ((0xf7U & (IData)(vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready)) 
           | (8U & ((IData)(vlTOPp->gpu__DOT__lsu_write_ready) 
                    >> 8U)));
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready 
        = ((0xefU & (IData)(vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready)) 
           | (0x10U & ((IData)(vlTOPp->gpu__DOT__lsu_write_ready) 
                       >> 8U)));
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready 
        = ((0xdfU & (IData)(vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready)) 
           | (0x20U & ((IData)(vlTOPp->gpu__DOT__lsu_write_ready) 
                       >> 8U)));
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready 
        = ((0xbfU & (IData)(vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready)) 
           | (0x40U & ((IData)(vlTOPp->gpu__DOT__lsu_write_ready) 
                       >> 8U)));
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready 
        = ((0x7fU & (IData)(vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready)) 
           | (0x80U & ((IData)(vlTOPp->gpu__DOT__lsu_write_ready) 
                       >> 8U)));
    vlTOPp->gpu__DOT__core_done = ((1U & (IData)(vlTOPp->gpu__DOT__core_done)) 
                                   | ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.done) 
                                      << 1U));
    vlTOPp->gpu__DOT__core_thread_count[1U] = vlTOPp->gpu__DOT____Vcellout__dispatch_instance__core_thread_count
        [1U];
    vlTOPp->gpu__DOT__core_thread_count[0U] = vlTOPp->gpu__DOT____Vcellout__dispatch_instance__core_thread_count
        [0U];
    vlTOPp->gpu__DOT__lsu_read_valid = ((0xfeffU & (IData)(vlTOPp->gpu__DOT__lsu_read_valid)) 
                                        | (0x100U & 
                                           ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_valid) 
                                            << 8U)));
    vlTOPp->gpu__DOT__lsu_read_valid = ((0xfdffU & (IData)(vlTOPp->gpu__DOT__lsu_read_valid)) 
                                        | (0x200U & 
                                           ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_valid) 
                                            << 8U)));
    vlTOPp->gpu__DOT__lsu_read_valid = ((0xfbffU & (IData)(vlTOPp->gpu__DOT__lsu_read_valid)) 
                                        | (0x400U & 
                                           ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_valid) 
                                            << 8U)));
    vlTOPp->gpu__DOT__lsu_read_valid = ((0xf7ffU & (IData)(vlTOPp->gpu__DOT__lsu_read_valid)) 
                                        | (0x800U & 
                                           ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_valid) 
                                            << 8U)));
    vlTOPp->gpu__DOT__lsu_read_valid = ((0xefffU & (IData)(vlTOPp->gpu__DOT__lsu_read_valid)) 
                                        | (0x1000U 
                                           & ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_valid) 
                                              << 8U)));
    vlTOPp->gpu__DOT__lsu_read_valid = ((0xdfffU & (IData)(vlTOPp->gpu__DOT__lsu_read_valid)) 
                                        | (0x2000U 
                                           & ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_valid) 
                                              << 8U)));
    vlTOPp->gpu__DOT__lsu_read_valid = ((0xbfffU & (IData)(vlTOPp->gpu__DOT__lsu_read_valid)) 
                                        | (0x4000U 
                                           & ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_valid) 
                                              << 8U)));
    vlTOPp->gpu__DOT__lsu_read_valid = ((0x7fffU & (IData)(vlTOPp->gpu__DOT__lsu_read_valid)) 
                                        | (0x8000U 
                                           & ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_valid) 
                                              << 8U)));
    vlTOPp->gpu__DOT__lsu_write_valid = ((0xfeffU & (IData)(vlTOPp->gpu__DOT__lsu_write_valid)) 
                                         | (0x100U 
                                            & ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_valid) 
                                               << 8U)));
    vlTOPp->gpu__DOT__lsu_write_valid = ((0xfdffU & (IData)(vlTOPp->gpu__DOT__lsu_write_valid)) 
                                         | (0x200U 
                                            & ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_valid) 
                                               << 8U)));
    vlTOPp->gpu__DOT__lsu_write_valid = ((0xfbffU & (IData)(vlTOPp->gpu__DOT__lsu_write_valid)) 
                                         | (0x400U 
                                            & ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_valid) 
                                               << 8U)));
    vlTOPp->gpu__DOT__lsu_write_valid = ((0xf7ffU & (IData)(vlTOPp->gpu__DOT__lsu_write_valid)) 
                                         | (0x800U 
                                            & ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_valid) 
                                               << 8U)));
    vlTOPp->gpu__DOT__lsu_write_valid = ((0xefffU & (IData)(vlTOPp->gpu__DOT__lsu_write_valid)) 
                                         | (0x1000U 
                                            & ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_valid) 
                                               << 8U)));
    vlTOPp->gpu__DOT__lsu_write_valid = ((0xdfffU & (IData)(vlTOPp->gpu__DOT__lsu_write_valid)) 
                                         | (0x2000U 
                                            & ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_valid) 
                                               << 8U)));
    vlTOPp->gpu__DOT__lsu_write_valid = ((0xbfffU & (IData)(vlTOPp->gpu__DOT__lsu_write_valid)) 
                                         | (0x4000U 
                                            & ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_valid) 
                                               << 8U)));
    vlTOPp->gpu__DOT__lsu_write_valid = ((0x7fffU & (IData)(vlTOPp->gpu__DOT__lsu_write_valid)) 
                                         | (0x8000U 
                                            & ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_valid) 
                                               << 8U)));
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address[7U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_address
        [7U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address[6U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_address
        [6U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address[5U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_address
        [5U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address[4U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_address
        [4U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address[3U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_address
        [3U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address[2U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_address
        [2U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address[1U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_address
        [1U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address[0U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_address
        [0U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address[7U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_address
        [7U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address[6U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_address
        [6U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address[5U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_address
        [5U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address[4U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_address
        [4U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address[3U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_address
        [3U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address[2U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_address
        [2U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address[1U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_address
        [1U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address[0U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_address
        [0U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data[7U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_data
        [7U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data[6U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_data
        [6U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data[5U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_data
        [5U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data[4U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_data
        [4U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data[3U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_data
        [3U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data[2U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_data
        [2U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data[1U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_data
        [1U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data[0U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_data
        [0U];
    vlTOPp->gpu__DOT__fetcher_read_data[1U] = vlTOPp->gpu__DOT____Vcellout__program_memory_controller__consumer_read_data
        [1U];
    vlTOPp->gpu__DOT__fetcher_read_data[0U] = vlTOPp->gpu__DOT____Vcellout__program_memory_controller__consumer_read_data
        [0U];
    vlTOPp->gpu__DOT__core_reset = vlTOPp->__Vdly__gpu__DOT__core_reset;
    vlTOPp->gpu__DOT__fetcher_read_valid = ((1U & (IData)(vlTOPp->gpu__DOT__fetcher_read_valid)) 
                                            | ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.program_mem_read_valid) 
                                               << 1U));
    vlTOPp->gpu__DOT__fetcher_read_address[1U] = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.program_mem_read_address;
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address[7U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address
        [7U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address[6U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address
        [6U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address[5U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address
        [5U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address[4U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address
        [4U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address[3U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address
        [3U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address[2U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address
        [2U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address[1U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address
        [1U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address[0U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address
        [0U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address[7U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address
        [7U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address[6U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address
        [6U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address[5U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address
        [5U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address[4U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address
        [4U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address[3U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address
        [3U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address[2U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address
        [2U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address[1U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address
        [1U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address[0U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address
        [0U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data[7U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data
        [7U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data[6U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data
        [6U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data[5U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data
        [5U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data[4U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data
        [4U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data[3U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data
        [3U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data[2U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data
        [2U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data[1U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data
        [1U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data[0U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data
        [0U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address[7U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address
        [7U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address[6U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address
        [6U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address[5U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address
        [5U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address[4U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address
        [4U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address[3U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address
        [3U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address[2U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address
        [2U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address[1U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address
        [1U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address[0U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address
        [0U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address[7U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address
        [7U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address[6U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address
        [6U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address[5U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address
        [5U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address[4U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address
        [4U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address[3U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address
        [3U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address[2U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address
        [2U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address[1U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address
        [1U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address[0U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address
        [0U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data[7U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data
        [7U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data[6U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data
        [6U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data[5U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data
        [5U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data[4U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data
        [4U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data[3U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data
        [3U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data[2U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data
        [2U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data[1U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data
        [1U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data[0U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data
        [0U];
    vlTOPp->gpu__DOT____Vcellinp__program_memory_controller__consumer_read_address[1U] 
        = vlTOPp->gpu__DOT__fetcher_read_address[1U];
    vlTOPp->gpu__DOT____Vcellinp__program_memory_controller__consumer_read_address[0U] 
        = vlTOPp->gpu__DOT__fetcher_read_address[0U];
    vlTOPp->gpu__DOT__lsu_read_address[0U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address
        [0U];
    vlTOPp->gpu__DOT__lsu_read_address[1U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address
        [1U];
    vlTOPp->gpu__DOT__lsu_read_address[2U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address
        [2U];
    vlTOPp->gpu__DOT__lsu_read_address[3U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address
        [3U];
    vlTOPp->gpu__DOT__lsu_read_address[4U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address
        [4U];
    vlTOPp->gpu__DOT__lsu_read_address[5U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address
        [5U];
    vlTOPp->gpu__DOT__lsu_read_address[6U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address
        [6U];
    vlTOPp->gpu__DOT__lsu_read_address[7U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address
        [7U];
    vlTOPp->gpu__DOT__lsu_write_address[0U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address
        [0U];
    vlTOPp->gpu__DOT__lsu_write_address[1U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address
        [1U];
    vlTOPp->gpu__DOT__lsu_write_address[2U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address
        [2U];
    vlTOPp->gpu__DOT__lsu_write_address[3U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address
        [3U];
    vlTOPp->gpu__DOT__lsu_write_address[4U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address
        [4U];
    vlTOPp->gpu__DOT__lsu_write_address[5U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address
        [5U];
    vlTOPp->gpu__DOT__lsu_write_address[6U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address
        [6U];
    vlTOPp->gpu__DOT__lsu_write_address[7U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address
        [7U];
    vlTOPp->gpu__DOT__lsu_write_data[0U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data
        [0U];
    vlTOPp->gpu__DOT__lsu_write_data[1U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data
        [1U];
    vlTOPp->gpu__DOT__lsu_write_data[2U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data
        [2U];
    vlTOPp->gpu__DOT__lsu_write_data[3U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data
        [3U];
    vlTOPp->gpu__DOT__lsu_write_data[4U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data
        [4U];
    vlTOPp->gpu__DOT__lsu_write_data[5U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data
        [5U];
    vlTOPp->gpu__DOT__lsu_write_data[6U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data
        [6U];
    vlTOPp->gpu__DOT__lsu_write_data[7U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data
        [7U];
    vlTOPp->gpu__DOT__lsu_read_address[8U] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address
        [0U];
    vlTOPp->gpu__DOT__lsu_read_address[9U] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address
        [1U];
    vlTOPp->gpu__DOT__lsu_read_address[0xaU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address
        [2U];
    vlTOPp->gpu__DOT__lsu_read_address[0xbU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address
        [3U];
    vlTOPp->gpu__DOT__lsu_read_address[0xcU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address
        [4U];
    vlTOPp->gpu__DOT__lsu_read_address[0xdU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address
        [5U];
    vlTOPp->gpu__DOT__lsu_read_address[0xeU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address
        [6U];
    vlTOPp->gpu__DOT__lsu_read_address[0xfU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address
        [7U];
    vlTOPp->gpu__DOT__lsu_write_address[8U] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address
        [0U];
    vlTOPp->gpu__DOT__lsu_write_address[9U] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address
        [1U];
    vlTOPp->gpu__DOT__lsu_write_address[0xaU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address
        [2U];
    vlTOPp->gpu__DOT__lsu_write_address[0xbU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address
        [3U];
    vlTOPp->gpu__DOT__lsu_write_address[0xcU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address
        [4U];
    vlTOPp->gpu__DOT__lsu_write_address[0xdU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address
        [5U];
    vlTOPp->gpu__DOT__lsu_write_address[0xeU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address
        [6U];
    vlTOPp->gpu__DOT__lsu_write_address[0xfU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address
        [7U];
    vlTOPp->gpu__DOT__lsu_write_data[8U] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data
        [0U];
    vlTOPp->gpu__DOT__lsu_write_data[9U] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data
        [1U];
    vlTOPp->gpu__DOT__lsu_write_data[0xaU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data
        [2U];
    vlTOPp->gpu__DOT__lsu_write_data[0xbU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data
        [3U];
    vlTOPp->gpu__DOT__lsu_write_data[0xcU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data
        [4U];
    vlTOPp->gpu__DOT__lsu_write_data[0xdU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data
        [5U];
    vlTOPp->gpu__DOT__lsu_write_data[0xeU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data
        [6U];
    vlTOPp->gpu__DOT__lsu_write_data[0xfU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data
        [7U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[0xfU] 
        = vlTOPp->gpu__DOT__lsu_read_address[0xfU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[0xeU] 
        = vlTOPp->gpu__DOT__lsu_read_address[0xeU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[0xdU] 
        = vlTOPp->gpu__DOT__lsu_read_address[0xdU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[0xcU] 
        = vlTOPp->gpu__DOT__lsu_read_address[0xcU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[0xbU] 
        = vlTOPp->gpu__DOT__lsu_read_address[0xbU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[0xaU] 
        = vlTOPp->gpu__DOT__lsu_read_address[0xaU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[9U] 
        = vlTOPp->gpu__DOT__lsu_read_address[9U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[8U] 
        = vlTOPp->gpu__DOT__lsu_read_address[8U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[7U] 
        = vlTOPp->gpu__DOT__lsu_read_address[7U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[6U] 
        = vlTOPp->gpu__DOT__lsu_read_address[6U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[5U] 
        = vlTOPp->gpu__DOT__lsu_read_address[5U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[4U] 
        = vlTOPp->gpu__DOT__lsu_read_address[4U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[3U] 
        = vlTOPp->gpu__DOT__lsu_read_address[3U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[2U] 
        = vlTOPp->gpu__DOT__lsu_read_address[2U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[1U] 
        = vlTOPp->gpu__DOT__lsu_read_address[1U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[0U] 
        = vlTOPp->gpu__DOT__lsu_read_address[0U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[0xfU] 
        = vlTOPp->gpu__DOT__lsu_write_address[0xfU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[0xeU] 
        = vlTOPp->gpu__DOT__lsu_write_address[0xeU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[0xdU] 
        = vlTOPp->gpu__DOT__lsu_write_address[0xdU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[0xcU] 
        = vlTOPp->gpu__DOT__lsu_write_address[0xcU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[0xbU] 
        = vlTOPp->gpu__DOT__lsu_write_address[0xbU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[0xaU] 
        = vlTOPp->gpu__DOT__lsu_write_address[0xaU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[9U] 
        = vlTOPp->gpu__DOT__lsu_write_address[9U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[8U] 
        = vlTOPp->gpu__DOT__lsu_write_address[8U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[7U] 
        = vlTOPp->gpu__DOT__lsu_write_address[7U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[6U] 
        = vlTOPp->gpu__DOT__lsu_write_address[6U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[5U] 
        = vlTOPp->gpu__DOT__lsu_write_address[5U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[4U] 
        = vlTOPp->gpu__DOT__lsu_write_address[4U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[3U] 
        = vlTOPp->gpu__DOT__lsu_write_address[3U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[2U] 
        = vlTOPp->gpu__DOT__lsu_write_address[2U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[1U] 
        = vlTOPp->gpu__DOT__lsu_write_address[1U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[0U] 
        = vlTOPp->gpu__DOT__lsu_write_address[0U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[0xfU] 
        = vlTOPp->gpu__DOT__lsu_write_data[0xfU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[0xeU] 
        = vlTOPp->gpu__DOT__lsu_write_data[0xeU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[0xdU] 
        = vlTOPp->gpu__DOT__lsu_write_data[0xdU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[0xcU] 
        = vlTOPp->gpu__DOT__lsu_write_data[0xcU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[0xbU] 
        = vlTOPp->gpu__DOT__lsu_write_data[0xbU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[0xaU] 
        = vlTOPp->gpu__DOT__lsu_write_data[0xaU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[9U] 
        = vlTOPp->gpu__DOT__lsu_write_data[9U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[8U] 
        = vlTOPp->gpu__DOT__lsu_write_data[8U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[7U] 
        = vlTOPp->gpu__DOT__lsu_write_data[7U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[6U] 
        = vlTOPp->gpu__DOT__lsu_write_data[6U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[5U] 
        = vlTOPp->gpu__DOT__lsu_write_data[5U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[4U] 
        = vlTOPp->gpu__DOT__lsu_write_data[4U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[3U] 
        = vlTOPp->gpu__DOT__lsu_write_data[3U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[2U] 
        = vlTOPp->gpu__DOT__lsu_write_data[2U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[1U] 
        = vlTOPp->gpu__DOT__lsu_write_data[1U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[0U] 
        = vlTOPp->gpu__DOT__lsu_write_data[0U];
}

void Vgpu::_settle__TOP__3(Vgpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgpu::_settle__TOP__3\n"); );
    Vgpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->gpu__DOT____Vcellinp__program_memory_controller__mem_read_data[0U] 
        = vlTOPp->program_mem_read_data[0U];
    vlTOPp->program_mem_read_address[0U] = vlTOPp->gpu__DOT____Vcellout__program_memory_controller__mem_read_address
        [0U];
    vlTOPp->data_mem_write_data[7U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_data
        [7U];
    vlTOPp->data_mem_write_data[6U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_data
        [6U];
    vlTOPp->data_mem_write_data[5U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_data
        [5U];
    vlTOPp->data_mem_write_data[4U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_data
        [4U];
    vlTOPp->data_mem_write_data[3U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_data
        [3U];
    vlTOPp->data_mem_write_data[2U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_data
        [2U];
    vlTOPp->data_mem_write_data[1U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_data
        [1U];
    vlTOPp->data_mem_write_data[0U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_data
        [0U];
    vlTOPp->data_mem_write_address[7U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_address
        [7U];
    vlTOPp->data_mem_write_address[6U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_address
        [6U];
    vlTOPp->data_mem_write_address[5U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_address
        [5U];
    vlTOPp->data_mem_write_address[4U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_address
        [4U];
    vlTOPp->data_mem_write_address[3U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_address
        [3U];
    vlTOPp->data_mem_write_address[2U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_address
        [2U];
    vlTOPp->data_mem_write_address[1U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_address
        [1U];
    vlTOPp->data_mem_write_address[0U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_write_address
        [0U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__mem_read_data[7U] 
        = vlTOPp->data_mem_read_data[7U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__mem_read_data[6U] 
        = vlTOPp->data_mem_read_data[6U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__mem_read_data[5U] 
        = vlTOPp->data_mem_read_data[5U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__mem_read_data[4U] 
        = vlTOPp->data_mem_read_data[4U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__mem_read_data[3U] 
        = vlTOPp->data_mem_read_data[3U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__mem_read_data[2U] 
        = vlTOPp->data_mem_read_data[2U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__mem_read_data[1U] 
        = vlTOPp->data_mem_read_data[1U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__mem_read_data[0U] 
        = vlTOPp->data_mem_read_data[0U];
    vlTOPp->data_mem_read_address[7U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_read_address
        [7U];
    vlTOPp->data_mem_read_address[6U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_read_address
        [6U];
    vlTOPp->data_mem_read_address[5U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_read_address
        [5U];
    vlTOPp->data_mem_read_address[4U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_read_address
        [4U];
    vlTOPp->data_mem_read_address[3U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_read_address
        [3U];
    vlTOPp->data_mem_read_address[2U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_read_address
        [2U];
    vlTOPp->data_mem_read_address[1U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_read_address
        [1U];
    vlTOPp->data_mem_read_address[0U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__mem_read_address
        [0U];
    vlTOPp->gpu__DOT__lsu_read_data[0xfU] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data
        [0xfU];
    vlTOPp->gpu__DOT__lsu_read_data[0xeU] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data
        [0xeU];
    vlTOPp->gpu__DOT__lsu_read_data[0xdU] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data
        [0xdU];
    vlTOPp->gpu__DOT__lsu_read_data[0xcU] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data
        [0xcU];
    vlTOPp->gpu__DOT__lsu_read_data[0xbU] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data
        [0xbU];
    vlTOPp->gpu__DOT__lsu_read_data[0xaU] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data
        [0xaU];
    vlTOPp->gpu__DOT__lsu_read_data[9U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data
        [9U];
    vlTOPp->gpu__DOT__lsu_read_data[8U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data
        [8U];
    vlTOPp->gpu__DOT__lsu_read_data[7U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data
        [7U];
    vlTOPp->gpu__DOT__lsu_read_data[6U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data
        [6U];
    vlTOPp->gpu__DOT__lsu_read_data[5U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data
        [5U];
    vlTOPp->gpu__DOT__lsu_read_data[4U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data
        [4U];
    vlTOPp->gpu__DOT__lsu_read_data[3U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data
        [3U];
    vlTOPp->gpu__DOT__lsu_read_data[2U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data
        [2U];
    vlTOPp->gpu__DOT__lsu_read_data[1U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data
        [1U];
    vlTOPp->gpu__DOT__lsu_read_data[0U] = vlTOPp->gpu__DOT____Vcellout__data_memory_controller__consumer_read_data
        [0U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready 
        = ((0xfeU & (IData)(vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready)) 
           | (1U & (IData)(vlTOPp->gpu__DOT__lsu_read_ready)));
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready 
        = ((0xfeU & (IData)(vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready)) 
           | (1U & (IData)(vlTOPp->gpu__DOT__lsu_write_ready)));
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready 
        = ((0xfdU & (IData)(vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready)) 
           | (2U & (IData)(vlTOPp->gpu__DOT__lsu_read_ready)));
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready 
        = ((0xfdU & (IData)(vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready)) 
           | (2U & (IData)(vlTOPp->gpu__DOT__lsu_write_ready)));
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready 
        = ((0xfbU & (IData)(vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready)) 
           | (4U & (IData)(vlTOPp->gpu__DOT__lsu_read_ready)));
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready 
        = ((0xfbU & (IData)(vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready)) 
           | (4U & (IData)(vlTOPp->gpu__DOT__lsu_write_ready)));
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready 
        = ((0xf7U & (IData)(vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready)) 
           | (8U & (IData)(vlTOPp->gpu__DOT__lsu_read_ready)));
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready 
        = ((0xf7U & (IData)(vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready)) 
           | (8U & (IData)(vlTOPp->gpu__DOT__lsu_write_ready)));
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready 
        = ((0xefU & (IData)(vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready)) 
           | (0x10U & (IData)(vlTOPp->gpu__DOT__lsu_read_ready)));
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready 
        = ((0xefU & (IData)(vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready)) 
           | (0x10U & (IData)(vlTOPp->gpu__DOT__lsu_write_ready)));
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready 
        = ((0xdfU & (IData)(vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready)) 
           | (0x20U & (IData)(vlTOPp->gpu__DOT__lsu_read_ready)));
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready 
        = ((0xdfU & (IData)(vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready)) 
           | (0x20U & (IData)(vlTOPp->gpu__DOT__lsu_write_ready)));
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready 
        = ((0xbfU & (IData)(vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready)) 
           | (0x40U & (IData)(vlTOPp->gpu__DOT__lsu_read_ready)));
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready 
        = ((0xbfU & (IData)(vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready)) 
           | (0x40U & (IData)(vlTOPp->gpu__DOT__lsu_write_ready)));
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready 
        = ((0x7fU & (IData)(vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready)) 
           | (0x80U & (IData)(vlTOPp->gpu__DOT__lsu_read_ready)));
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready 
        = ((0x7fU & (IData)(vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready)) 
           | (0x80U & (IData)(vlTOPp->gpu__DOT__lsu_write_ready)));
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready 
        = ((0xfeU & (IData)(vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready)) 
           | (1U & ((IData)(vlTOPp->gpu__DOT__lsu_read_ready) 
                    >> 8U)));
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready 
        = ((0xfeU & (IData)(vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready)) 
           | (1U & ((IData)(vlTOPp->gpu__DOT__lsu_write_ready) 
                    >> 8U)));
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready 
        = ((0xfdU & (IData)(vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready)) 
           | (2U & ((IData)(vlTOPp->gpu__DOT__lsu_read_ready) 
                    >> 8U)));
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready 
        = ((0xfdU & (IData)(vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready)) 
           | (2U & ((IData)(vlTOPp->gpu__DOT__lsu_write_ready) 
                    >> 8U)));
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready 
        = ((0xfbU & (IData)(vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready)) 
           | (4U & ((IData)(vlTOPp->gpu__DOT__lsu_read_ready) 
                    >> 8U)));
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready 
        = ((0xfbU & (IData)(vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready)) 
           | (4U & ((IData)(vlTOPp->gpu__DOT__lsu_write_ready) 
                    >> 8U)));
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready 
        = ((0xf7U & (IData)(vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready)) 
           | (8U & ((IData)(vlTOPp->gpu__DOT__lsu_read_ready) 
                    >> 8U)));
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready 
        = ((0xf7U & (IData)(vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready)) 
           | (8U & ((IData)(vlTOPp->gpu__DOT__lsu_write_ready) 
                    >> 8U)));
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready 
        = ((0xefU & (IData)(vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready)) 
           | (0x10U & ((IData)(vlTOPp->gpu__DOT__lsu_read_ready) 
                       >> 8U)));
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready 
        = ((0xefU & (IData)(vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready)) 
           | (0x10U & ((IData)(vlTOPp->gpu__DOT__lsu_write_ready) 
                       >> 8U)));
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready 
        = ((0xdfU & (IData)(vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready)) 
           | (0x20U & ((IData)(vlTOPp->gpu__DOT__lsu_read_ready) 
                       >> 8U)));
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready 
        = ((0xdfU & (IData)(vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready)) 
           | (0x20U & ((IData)(vlTOPp->gpu__DOT__lsu_write_ready) 
                       >> 8U)));
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready 
        = ((0xbfU & (IData)(vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready)) 
           | (0x40U & ((IData)(vlTOPp->gpu__DOT__lsu_read_ready) 
                       >> 8U)));
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready 
        = ((0xbfU & (IData)(vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready)) 
           | (0x40U & ((IData)(vlTOPp->gpu__DOT__lsu_write_ready) 
                       >> 8U)));
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready 
        = ((0x7fU & (IData)(vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready)) 
           | (0x80U & ((IData)(vlTOPp->gpu__DOT__lsu_read_ready) 
                       >> 8U)));
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready 
        = ((0x7fU & (IData)(vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready)) 
           | (0x80U & ((IData)(vlTOPp->gpu__DOT__lsu_write_ready) 
                       >> 8U)));
    vlTOPp->gpu__DOT__core_block_id[1U] = vlTOPp->gpu__DOT____Vcellout__dispatch_instance__core_block_id
        [1U];
    vlTOPp->gpu__DOT__core_block_id[0U] = vlTOPp->gpu__DOT____Vcellout__dispatch_instance__core_block_id
        [0U];
    vlTOPp->gpu__DOT__core_done = ((2U & (IData)(vlTOPp->gpu__DOT__core_done)) 
                                   | (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.done));
    vlTOPp->gpu__DOT__core_done = ((1U & (IData)(vlTOPp->gpu__DOT__core_done)) 
                                   | ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.done) 
                                      << 1U));
    vlTOPp->gpu__DOT__core_thread_count[1U] = vlTOPp->gpu__DOT____Vcellout__dispatch_instance__core_thread_count
        [1U];
    vlTOPp->gpu__DOT__core_thread_count[0U] = vlTOPp->gpu__DOT____Vcellout__dispatch_instance__core_thread_count
        [0U];
    vlTOPp->gpu__DOT__fetcher_read_data[1U] = vlTOPp->gpu__DOT____Vcellout__program_memory_controller__consumer_read_data
        [1U];
    vlTOPp->gpu__DOT__fetcher_read_data[0U] = vlTOPp->gpu__DOT____Vcellout__program_memory_controller__consumer_read_data
        [0U];
    vlTOPp->gpu__DOT__fetcher_read_valid = ((2U & (IData)(vlTOPp->gpu__DOT__fetcher_read_valid)) 
                                            | (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.program_mem_read_valid));
    vlTOPp->gpu__DOT__fetcher_read_valid = ((1U & (IData)(vlTOPp->gpu__DOT__fetcher_read_valid)) 
                                            | ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.program_mem_read_valid) 
                                               << 1U));
    vlTOPp->gpu__DOT__fetcher_read_address[0U] = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.program_mem_read_address;
    vlTOPp->gpu__DOT__fetcher_read_address[1U] = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.program_mem_read_address;
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data[0U] 
        = vlTOPp->gpu__DOT__lsu_read_data[0U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data[1U] 
        = vlTOPp->gpu__DOT__lsu_read_data[1U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data[2U] 
        = vlTOPp->gpu__DOT__lsu_read_data[2U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data[3U] 
        = vlTOPp->gpu__DOT__lsu_read_data[3U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data[4U] 
        = vlTOPp->gpu__DOT__lsu_read_data[4U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data[5U] 
        = vlTOPp->gpu__DOT__lsu_read_data[5U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data[6U] 
        = vlTOPp->gpu__DOT__lsu_read_data[6U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data[7U] 
        = vlTOPp->gpu__DOT__lsu_read_data[7U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data[0U] 
        = vlTOPp->gpu__DOT__lsu_read_data[8U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data[1U] 
        = vlTOPp->gpu__DOT__lsu_read_data[9U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data[2U] 
        = vlTOPp->gpu__DOT__lsu_read_data[0xaU];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data[3U] 
        = vlTOPp->gpu__DOT__lsu_read_data[0xbU];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data[4U] 
        = vlTOPp->gpu__DOT__lsu_read_data[0xcU];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data[5U] 
        = vlTOPp->gpu__DOT__lsu_read_data[0xdU];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data[6U] 
        = vlTOPp->gpu__DOT__lsu_read_data[0xeU];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data[7U] 
        = vlTOPp->gpu__DOT__lsu_read_data[0xfU];
    vlTOPp->gpu__DOT____Vcellinp__program_memory_controller__consumer_read_address[1U] 
        = vlTOPp->gpu__DOT__fetcher_read_address[1U];
    vlTOPp->gpu__DOT____Vcellinp__program_memory_controller__consumer_read_address[0U] 
        = vlTOPp->gpu__DOT__fetcher_read_address[0U];
    vlTOPp->gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data[7U] 
        = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data
        [7U];
    vlTOPp->gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data[6U] 
        = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data
        [6U];
    vlTOPp->gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data[5U] 
        = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data
        [5U];
    vlTOPp->gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data[4U] 
        = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data
        [4U];
    vlTOPp->gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data[3U] 
        = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data
        [3U];
    vlTOPp->gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data[2U] 
        = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data
        [2U];
    vlTOPp->gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data[1U] 
        = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data
        [1U];
    vlTOPp->gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data[0U] 
        = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data
        [0U];
    vlTOPp->gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data[7U] 
        = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data
        [7U];
    vlTOPp->gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data[6U] 
        = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data
        [6U];
    vlTOPp->gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data[5U] 
        = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data
        [5U];
    vlTOPp->gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data[4U] 
        = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data
        [4U];
    vlTOPp->gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data[3U] 
        = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data
        [3U];
    vlTOPp->gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data[2U] 
        = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data
        [2U];
    vlTOPp->gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data[1U] 
        = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data
        [1U];
    vlTOPp->gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data[0U] 
        = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data
        [0U];
    vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_data[7U] 
        = vlTOPp->gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data
        [7U];
    vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_data[6U] 
        = vlTOPp->gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data
        [6U];
    vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_data[5U] 
        = vlTOPp->gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data
        [5U];
    vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_data[4U] 
        = vlTOPp->gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data
        [4U];
    vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_data[3U] 
        = vlTOPp->gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data
        [3U];
    vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_data[2U] 
        = vlTOPp->gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data
        [2U];
    vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_data[1U] 
        = vlTOPp->gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data
        [1U];
    vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_data[0U] 
        = vlTOPp->gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data
        [0U];
    vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_data[7U] 
        = vlTOPp->gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data
        [7U];
    vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_data[6U] 
        = vlTOPp->gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data
        [6U];
    vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_data[5U] 
        = vlTOPp->gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data
        [5U];
    vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_data[4U] 
        = vlTOPp->gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data
        [4U];
    vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_data[3U] 
        = vlTOPp->gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data
        [3U];
    vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_data[2U] 
        = vlTOPp->gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data
        [2U];
    vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_data[1U] 
        = vlTOPp->gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data
        [1U];
    vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_data[0U] 
        = vlTOPp->gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data
        [0U];
}

void Vgpu::_settle__TOP__4(Vgpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgpu::_settle__TOP__4\n"); );
    Vgpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->gpu__DOT__lsu_write_valid = ((0xfffeU & (IData)(vlTOPp->gpu__DOT__lsu_write_valid)) 
                                         | (1U & (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_valid)));
    vlTOPp->gpu__DOT__lsu_write_valid = ((0xfffdU & (IData)(vlTOPp->gpu__DOT__lsu_write_valid)) 
                                         | (2U & (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_valid)));
    vlTOPp->gpu__DOT__lsu_write_valid = ((0xfffbU & (IData)(vlTOPp->gpu__DOT__lsu_write_valid)) 
                                         | (4U & (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_valid)));
    vlTOPp->gpu__DOT__lsu_write_valid = ((0xfff7U & (IData)(vlTOPp->gpu__DOT__lsu_write_valid)) 
                                         | (8U & (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_valid)));
    vlTOPp->gpu__DOT__lsu_write_valid = ((0xffefU & (IData)(vlTOPp->gpu__DOT__lsu_write_valid)) 
                                         | (0x10U & (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_valid)));
    vlTOPp->gpu__DOT__lsu_write_valid = ((0xffdfU & (IData)(vlTOPp->gpu__DOT__lsu_write_valid)) 
                                         | (0x20U & (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_valid)));
    vlTOPp->gpu__DOT__lsu_write_valid = ((0xffbfU & (IData)(vlTOPp->gpu__DOT__lsu_write_valid)) 
                                         | (0x40U & (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_valid)));
    vlTOPp->gpu__DOT__lsu_write_valid = ((0xff7fU & (IData)(vlTOPp->gpu__DOT__lsu_write_valid)) 
                                         | (0x80U & (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_valid)));
    vlTOPp->gpu__DOT__lsu_read_valid = ((0xfffeU & (IData)(vlTOPp->gpu__DOT__lsu_read_valid)) 
                                        | (1U & (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_valid)));
    vlTOPp->gpu__DOT__lsu_read_valid = ((0xfffdU & (IData)(vlTOPp->gpu__DOT__lsu_read_valid)) 
                                        | (2U & (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_valid)));
    vlTOPp->gpu__DOT__lsu_read_valid = ((0xfffbU & (IData)(vlTOPp->gpu__DOT__lsu_read_valid)) 
                                        | (4U & (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_valid)));
    vlTOPp->gpu__DOT__lsu_read_valid = ((0xfff7U & (IData)(vlTOPp->gpu__DOT__lsu_read_valid)) 
                                        | (8U & (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_valid)));
    vlTOPp->gpu__DOT__lsu_read_valid = ((0xffefU & (IData)(vlTOPp->gpu__DOT__lsu_read_valid)) 
                                        | (0x10U & (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_valid)));
    vlTOPp->gpu__DOT__lsu_read_valid = ((0xffdfU & (IData)(vlTOPp->gpu__DOT__lsu_read_valid)) 
                                        | (0x20U & (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_valid)));
    vlTOPp->gpu__DOT__lsu_read_valid = ((0xffbfU & (IData)(vlTOPp->gpu__DOT__lsu_read_valid)) 
                                        | (0x40U & (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_valid)));
    vlTOPp->gpu__DOT__lsu_read_valid = ((0xff7fU & (IData)(vlTOPp->gpu__DOT__lsu_read_valid)) 
                                        | (0x80U & (IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_valid)));
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data[7U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_data
        [7U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data[6U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_data
        [6U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data[5U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_data
        [5U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data[4U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_data
        [4U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data[3U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_data
        [3U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data[2U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_data
        [2U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data[1U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_data
        [1U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data[0U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_data
        [0U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address[7U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_address
        [7U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address[6U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_address
        [6U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address[5U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_address
        [5U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address[4U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_address
        [4U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address[3U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_address
        [3U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address[2U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_address
        [2U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address[1U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_address
        [1U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address[0U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_write_address
        [0U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address[7U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_address
        [7U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address[6U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_address
        [6U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address[5U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_address
        [5U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address[4U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_address
        [4U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address[3U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_address
        [3U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address[2U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_address
        [2U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address[1U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_address
        [1U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address[0U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.data_mem_read_address
        [0U];
    vlTOPp->gpu__DOT__lsu_write_valid = ((0xfeffU & (IData)(vlTOPp->gpu__DOT__lsu_write_valid)) 
                                         | (0x100U 
                                            & ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_valid) 
                                               << 8U)));
    vlTOPp->gpu__DOT__lsu_write_valid = ((0xfdffU & (IData)(vlTOPp->gpu__DOT__lsu_write_valid)) 
                                         | (0x200U 
                                            & ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_valid) 
                                               << 8U)));
    vlTOPp->gpu__DOT__lsu_write_valid = ((0xfbffU & (IData)(vlTOPp->gpu__DOT__lsu_write_valid)) 
                                         | (0x400U 
                                            & ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_valid) 
                                               << 8U)));
    vlTOPp->gpu__DOT__lsu_write_valid = ((0xf7ffU & (IData)(vlTOPp->gpu__DOT__lsu_write_valid)) 
                                         | (0x800U 
                                            & ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_valid) 
                                               << 8U)));
    vlTOPp->gpu__DOT__lsu_write_valid = ((0xefffU & (IData)(vlTOPp->gpu__DOT__lsu_write_valid)) 
                                         | (0x1000U 
                                            & ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_valid) 
                                               << 8U)));
    vlTOPp->gpu__DOT__lsu_write_valid = ((0xdfffU & (IData)(vlTOPp->gpu__DOT__lsu_write_valid)) 
                                         | (0x2000U 
                                            & ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_valid) 
                                               << 8U)));
    vlTOPp->gpu__DOT__lsu_write_valid = ((0xbfffU & (IData)(vlTOPp->gpu__DOT__lsu_write_valid)) 
                                         | (0x4000U 
                                            & ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_valid) 
                                               << 8U)));
    vlTOPp->gpu__DOT__lsu_write_valid = ((0x7fffU & (IData)(vlTOPp->gpu__DOT__lsu_write_valid)) 
                                         | (0x8000U 
                                            & ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_valid) 
                                               << 8U)));
    vlTOPp->gpu__DOT__lsu_read_valid = ((0xfeffU & (IData)(vlTOPp->gpu__DOT__lsu_read_valid)) 
                                        | (0x100U & 
                                           ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_valid) 
                                            << 8U)));
    vlTOPp->gpu__DOT__lsu_read_valid = ((0xfdffU & (IData)(vlTOPp->gpu__DOT__lsu_read_valid)) 
                                        | (0x200U & 
                                           ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_valid) 
                                            << 8U)));
    vlTOPp->gpu__DOT__lsu_read_valid = ((0xfbffU & (IData)(vlTOPp->gpu__DOT__lsu_read_valid)) 
                                        | (0x400U & 
                                           ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_valid) 
                                            << 8U)));
    vlTOPp->gpu__DOT__lsu_read_valid = ((0xf7ffU & (IData)(vlTOPp->gpu__DOT__lsu_read_valid)) 
                                        | (0x800U & 
                                           ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_valid) 
                                            << 8U)));
    vlTOPp->gpu__DOT__lsu_read_valid = ((0xefffU & (IData)(vlTOPp->gpu__DOT__lsu_read_valid)) 
                                        | (0x1000U 
                                           & ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_valid) 
                                              << 8U)));
    vlTOPp->gpu__DOT__lsu_read_valid = ((0xdfffU & (IData)(vlTOPp->gpu__DOT__lsu_read_valid)) 
                                        | (0x2000U 
                                           & ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_valid) 
                                              << 8U)));
    vlTOPp->gpu__DOT__lsu_read_valid = ((0xbfffU & (IData)(vlTOPp->gpu__DOT__lsu_read_valid)) 
                                        | (0x4000U 
                                           & ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_valid) 
                                              << 8U)));
    vlTOPp->gpu__DOT__lsu_read_valid = ((0x7fffU & (IData)(vlTOPp->gpu__DOT__lsu_read_valid)) 
                                        | (0x8000U 
                                           & ((IData)(vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_valid) 
                                              << 8U)));
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data[7U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_data
        [7U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data[6U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_data
        [6U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data[5U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_data
        [5U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data[4U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_data
        [4U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data[3U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_data
        [3U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data[2U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_data
        [2U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data[1U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_data
        [1U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data[0U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_data
        [0U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address[7U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_address
        [7U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address[6U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_address
        [6U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address[5U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_address
        [5U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address[4U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_address
        [4U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address[3U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_address
        [3U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address[2U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_address
        [2U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address[1U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_address
        [1U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address[0U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_write_address
        [0U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address[7U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_address
        [7U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address[6U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_address
        [6U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address[5U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_address
        [5U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address[4U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_address
        [4U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address[3U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_address
        [3U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address[2U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_address
        [2U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address[1U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_address
        [1U];
    vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address[0U] 
        = vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.data_mem_read_address
        [0U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data[7U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data
        [7U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data[6U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data
        [6U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data[5U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data
        [5U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data[4U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data
        [4U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data[3U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data
        [3U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data[2U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data
        [2U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data[1U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data
        [1U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data[0U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data
        [0U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address[7U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address
        [7U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address[6U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address
        [6U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address[5U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address
        [5U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address[4U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address
        [4U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address[3U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address
        [3U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address[2U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address
        [2U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address[1U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address
        [1U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address[0U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address
        [0U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address[7U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address
        [7U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address[6U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address
        [6U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address[5U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address
        [5U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address[4U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address
        [4U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address[3U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address
        [3U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address[2U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address
        [2U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address[1U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address
        [1U];
    vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address[0U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address
        [0U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data[7U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data
        [7U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data[6U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data
        [6U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data[5U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data
        [5U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data[4U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data
        [4U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data[3U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data
        [3U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data[2U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data
        [2U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data[1U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data
        [1U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data[0U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data
        [0U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address[7U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address
        [7U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address[6U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address
        [6U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address[5U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address
        [5U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address[4U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address
        [4U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address[3U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address
        [3U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address[2U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address
        [2U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address[1U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address
        [1U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address[0U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address
        [0U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address[7U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address
        [7U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address[6U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address
        [6U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address[5U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address
        [5U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address[4U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address
        [4U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address[3U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address
        [3U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address[2U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address
        [2U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address[1U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address
        [1U];
    vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address[0U] 
        = vlTOPp->gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address
        [0U];
    vlTOPp->gpu__DOT__lsu_write_data[0U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data
        [0U];
    vlTOPp->gpu__DOT__lsu_write_data[1U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data
        [1U];
    vlTOPp->gpu__DOT__lsu_write_data[2U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data
        [2U];
    vlTOPp->gpu__DOT__lsu_write_data[3U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data
        [3U];
    vlTOPp->gpu__DOT__lsu_write_data[4U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data
        [4U];
    vlTOPp->gpu__DOT__lsu_write_data[5U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data
        [5U];
    vlTOPp->gpu__DOT__lsu_write_data[6U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data
        [6U];
    vlTOPp->gpu__DOT__lsu_write_data[7U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data
        [7U];
    vlTOPp->gpu__DOT__lsu_write_address[0U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address
        [0U];
    vlTOPp->gpu__DOT__lsu_write_address[1U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address
        [1U];
    vlTOPp->gpu__DOT__lsu_write_address[2U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address
        [2U];
    vlTOPp->gpu__DOT__lsu_write_address[3U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address
        [3U];
    vlTOPp->gpu__DOT__lsu_write_address[4U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address
        [4U];
    vlTOPp->gpu__DOT__lsu_write_address[5U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address
        [5U];
    vlTOPp->gpu__DOT__lsu_write_address[6U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address
        [6U];
    vlTOPp->gpu__DOT__lsu_write_address[7U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address
        [7U];
    vlTOPp->gpu__DOT__lsu_read_address[0U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address
        [0U];
    vlTOPp->gpu__DOT__lsu_read_address[1U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address
        [1U];
    vlTOPp->gpu__DOT__lsu_read_address[2U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address
        [2U];
    vlTOPp->gpu__DOT__lsu_read_address[3U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address
        [3U];
    vlTOPp->gpu__DOT__lsu_read_address[4U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address
        [4U];
    vlTOPp->gpu__DOT__lsu_read_address[5U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address
        [5U];
    vlTOPp->gpu__DOT__lsu_read_address[6U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address
        [6U];
    vlTOPp->gpu__DOT__lsu_read_address[7U] = vlTOPp->gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address
        [7U];
    vlTOPp->gpu__DOT__lsu_write_data[8U] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data
        [0U];
    vlTOPp->gpu__DOT__lsu_write_data[9U] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data
        [1U];
    vlTOPp->gpu__DOT__lsu_write_data[0xaU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data
        [2U];
    vlTOPp->gpu__DOT__lsu_write_data[0xbU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data
        [3U];
    vlTOPp->gpu__DOT__lsu_write_data[0xcU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data
        [4U];
    vlTOPp->gpu__DOT__lsu_write_data[0xdU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data
        [5U];
    vlTOPp->gpu__DOT__lsu_write_data[0xeU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data
        [6U];
    vlTOPp->gpu__DOT__lsu_write_data[0xfU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data
        [7U];
    vlTOPp->gpu__DOT__lsu_write_address[8U] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address
        [0U];
    vlTOPp->gpu__DOT__lsu_write_address[9U] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address
        [1U];
    vlTOPp->gpu__DOT__lsu_write_address[0xaU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address
        [2U];
    vlTOPp->gpu__DOT__lsu_write_address[0xbU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address
        [3U];
    vlTOPp->gpu__DOT__lsu_write_address[0xcU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address
        [4U];
    vlTOPp->gpu__DOT__lsu_write_address[0xdU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address
        [5U];
    vlTOPp->gpu__DOT__lsu_write_address[0xeU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address
        [6U];
    vlTOPp->gpu__DOT__lsu_write_address[0xfU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address
        [7U];
    vlTOPp->gpu__DOT__lsu_read_address[8U] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address
        [0U];
    vlTOPp->gpu__DOT__lsu_read_address[9U] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address
        [1U];
    vlTOPp->gpu__DOT__lsu_read_address[0xaU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address
        [2U];
    vlTOPp->gpu__DOT__lsu_read_address[0xbU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address
        [3U];
    vlTOPp->gpu__DOT__lsu_read_address[0xcU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address
        [4U];
    vlTOPp->gpu__DOT__lsu_read_address[0xdU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address
        [5U];
    vlTOPp->gpu__DOT__lsu_read_address[0xeU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address
        [6U];
    vlTOPp->gpu__DOT__lsu_read_address[0xfU] = vlTOPp->gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address
        [7U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[0xfU] 
        = vlTOPp->gpu__DOT__lsu_write_data[0xfU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[0xeU] 
        = vlTOPp->gpu__DOT__lsu_write_data[0xeU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[0xdU] 
        = vlTOPp->gpu__DOT__lsu_write_data[0xdU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[0xcU] 
        = vlTOPp->gpu__DOT__lsu_write_data[0xcU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[0xbU] 
        = vlTOPp->gpu__DOT__lsu_write_data[0xbU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[0xaU] 
        = vlTOPp->gpu__DOT__lsu_write_data[0xaU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[9U] 
        = vlTOPp->gpu__DOT__lsu_write_data[9U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[8U] 
        = vlTOPp->gpu__DOT__lsu_write_data[8U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[7U] 
        = vlTOPp->gpu__DOT__lsu_write_data[7U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[6U] 
        = vlTOPp->gpu__DOT__lsu_write_data[6U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[5U] 
        = vlTOPp->gpu__DOT__lsu_write_data[5U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[4U] 
        = vlTOPp->gpu__DOT__lsu_write_data[4U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[3U] 
        = vlTOPp->gpu__DOT__lsu_write_data[3U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[2U] 
        = vlTOPp->gpu__DOT__lsu_write_data[2U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[1U] 
        = vlTOPp->gpu__DOT__lsu_write_data[1U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[0U] 
        = vlTOPp->gpu__DOT__lsu_write_data[0U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[0xfU] 
        = vlTOPp->gpu__DOT__lsu_write_address[0xfU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[0xeU] 
        = vlTOPp->gpu__DOT__lsu_write_address[0xeU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[0xdU] 
        = vlTOPp->gpu__DOT__lsu_write_address[0xdU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[0xcU] 
        = vlTOPp->gpu__DOT__lsu_write_address[0xcU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[0xbU] 
        = vlTOPp->gpu__DOT__lsu_write_address[0xbU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[0xaU] 
        = vlTOPp->gpu__DOT__lsu_write_address[0xaU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[9U] 
        = vlTOPp->gpu__DOT__lsu_write_address[9U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[8U] 
        = vlTOPp->gpu__DOT__lsu_write_address[8U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[7U] 
        = vlTOPp->gpu__DOT__lsu_write_address[7U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[6U] 
        = vlTOPp->gpu__DOT__lsu_write_address[6U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[5U] 
        = vlTOPp->gpu__DOT__lsu_write_address[5U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[4U] 
        = vlTOPp->gpu__DOT__lsu_write_address[4U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[3U] 
        = vlTOPp->gpu__DOT__lsu_write_address[3U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[2U] 
        = vlTOPp->gpu__DOT__lsu_write_address[2U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[1U] 
        = vlTOPp->gpu__DOT__lsu_write_address[1U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[0U] 
        = vlTOPp->gpu__DOT__lsu_write_address[0U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[0xfU] 
        = vlTOPp->gpu__DOT__lsu_read_address[0xfU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[0xeU] 
        = vlTOPp->gpu__DOT__lsu_read_address[0xeU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[0xdU] 
        = vlTOPp->gpu__DOT__lsu_read_address[0xdU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[0xcU] 
        = vlTOPp->gpu__DOT__lsu_read_address[0xcU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[0xbU] 
        = vlTOPp->gpu__DOT__lsu_read_address[0xbU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[0xaU] 
        = vlTOPp->gpu__DOT__lsu_read_address[0xaU];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[9U] 
        = vlTOPp->gpu__DOT__lsu_read_address[9U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[8U] 
        = vlTOPp->gpu__DOT__lsu_read_address[8U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[7U] 
        = vlTOPp->gpu__DOT__lsu_read_address[7U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[6U] 
        = vlTOPp->gpu__DOT__lsu_read_address[6U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[5U] 
        = vlTOPp->gpu__DOT__lsu_read_address[5U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[4U] 
        = vlTOPp->gpu__DOT__lsu_read_address[4U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[3U] 
        = vlTOPp->gpu__DOT__lsu_read_address[3U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[2U] 
        = vlTOPp->gpu__DOT__lsu_read_address[2U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[1U] 
        = vlTOPp->gpu__DOT__lsu_read_address[1U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[0U] 
        = vlTOPp->gpu__DOT__lsu_read_address[0U];
}

VL_INLINE_OPT void Vgpu::_combo__TOP__5(Vgpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgpu::_combo__TOP__5\n"); );
    Vgpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->gpu__DOT____Vcellinp__program_memory_controller__mem_read_data[0U] 
        = vlTOPp->program_mem_read_data[0U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__mem_read_data[7U] 
        = vlTOPp->data_mem_read_data[7U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__mem_read_data[6U] 
        = vlTOPp->data_mem_read_data[6U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__mem_read_data[5U] 
        = vlTOPp->data_mem_read_data[5U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__mem_read_data[4U] 
        = vlTOPp->data_mem_read_data[4U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__mem_read_data[3U] 
        = vlTOPp->data_mem_read_data[3U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__mem_read_data[2U] 
        = vlTOPp->data_mem_read_data[2U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__mem_read_data[1U] 
        = vlTOPp->data_mem_read_data[1U];
    vlTOPp->gpu__DOT____Vcellinp__data_memory_controller__mem_read_data[0U] 
        = vlTOPp->data_mem_read_data[0U];
}

void Vgpu::_eval(Vgpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgpu::_eval\n"); );
    Vgpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    if (((IData)(vlTOPp->clk) & (~ (IData)(vlTOPp->__Vclklast__TOP__clk)))) {
        vlTOPp->_sequent__TOP__1(vlSymsp);
        vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance._sequent__TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance__1(vlSymsp);
        vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance._sequent__TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance__2(vlSymsp);
        vlTOPp->_sequent__TOP__2(vlSymsp);
    }
    vlTOPp->_combo__TOP__5(vlSymsp);
    // Final
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vgpu::_eval_initial(Vgpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgpu::_eval_initial\n"); );
    Vgpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->__Vclklast__TOP__clk = vlTOPp->clk;
}

void Vgpu::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgpu::final\n"); );
    // Variables
    Vgpu__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vgpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vgpu::_eval_settle(Vgpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgpu::_eval_settle\n"); );
    Vgpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_settle__TOP__3(vlSymsp);
    vlSymsp->TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance._settle__TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance__3(vlSymsp);
    vlSymsp->TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance._settle__TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance__3(vlSymsp);
    vlTOPp->_settle__TOP__4(vlSymsp);
}

VL_INLINE_OPT QData Vgpu::_change_request(Vgpu__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgpu::_change_request\n"); );
    Vgpu* __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vgpu::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgpu::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((reset & 0xfeU))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY((start & 0xfeU))) {
        Verilated::overWidthError("start");}
    if (VL_UNLIKELY((device_control_write_enable & 0xfeU))) {
        Verilated::overWidthError("device_control_write_enable");}
    if (VL_UNLIKELY((program_mem_read_ready & 0xfeU))) {
        Verilated::overWidthError("program_mem_read_ready");}
}
#endif  // VL_DEBUG

void Vgpu::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vgpu::_ctor_var_reset\n"); );
    // Body
    clk = VL_RAND_RESET_I(1);
    reset = VL_RAND_RESET_I(1);
    start = VL_RAND_RESET_I(1);
    done = VL_RAND_RESET_I(1);
    device_control_write_enable = VL_RAND_RESET_I(1);
    device_control_data = VL_RAND_RESET_I(8);
    program_mem_read_valid = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<1; ++__Vi0) {
            program_mem_read_address[__Vi0] = VL_RAND_RESET_I(8);
    }}
    program_mem_read_ready = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<1; ++__Vi0) {
            program_mem_read_data[__Vi0] = VL_RAND_RESET_I(16);
    }}
    data_mem_read_valid = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            data_mem_read_address[__Vi0] = VL_RAND_RESET_I(8);
    }}
    data_mem_read_ready = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            data_mem_read_data[__Vi0] = VL_RAND_RESET_I(8);
    }}
    data_mem_write_valid = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            data_mem_write_address[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            data_mem_write_data[__Vi0] = VL_RAND_RESET_I(8);
    }}
    data_mem_write_ready = VL_RAND_RESET_I(8);
    gpu__DOT__core_start = VL_RAND_RESET_I(2);
    gpu__DOT__core_reset = VL_RAND_RESET_I(2);
    gpu__DOT__core_done = VL_RAND_RESET_I(2);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            gpu__DOT__core_block_id[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            gpu__DOT__core_thread_count[__Vi0] = VL_RAND_RESET_I(4);
    }}
    gpu__DOT__lsu_read_valid = VL_RAND_RESET_I(16);
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
            gpu__DOT__lsu_read_address[__Vi0] = VL_RAND_RESET_I(8);
    }}
    gpu__DOT__lsu_read_ready = VL_RAND_RESET_I(16);
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
            gpu__DOT__lsu_read_data[__Vi0] = VL_RAND_RESET_I(8);
    }}
    gpu__DOT__lsu_write_valid = VL_RAND_RESET_I(16);
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
            gpu__DOT__lsu_write_address[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
            gpu__DOT__lsu_write_data[__Vi0] = VL_RAND_RESET_I(8);
    }}
    gpu__DOT__lsu_write_ready = VL_RAND_RESET_I(16);
    gpu__DOT__fetcher_read_valid = VL_RAND_RESET_I(2);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            gpu__DOT__fetcher_read_address[__Vi0] = VL_RAND_RESET_I(8);
    }}
    gpu__DOT__fetcher_read_ready = VL_RAND_RESET_I(2);
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            gpu__DOT__fetcher_read_data[__Vi0] = VL_RAND_RESET_I(16);
    }}
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            gpu__DOT____Vcellout__data_memory_controller__mem_write_data[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            gpu__DOT____Vcellout__data_memory_controller__mem_write_address[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            gpu__DOT____Vcellinp__data_memory_controller__mem_read_data[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            gpu__DOT____Vcellout__data_memory_controller__mem_read_address[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
            gpu__DOT____Vcellinp__data_memory_controller__consumer_write_data[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
            gpu__DOT____Vcellinp__data_memory_controller__consumer_write_address[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
            gpu__DOT____Vcellout__data_memory_controller__consumer_read_data[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<16; ++__Vi0) {
            gpu__DOT____Vcellinp__data_memory_controller__consumer_read_address[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<1; ++__Vi0) {
            gpu__DOT____Vcellinp__program_memory_controller__mem_read_data[__Vi0] = VL_RAND_RESET_I(16);
    }}
    { int __Vi0=0; for (; __Vi0<1; ++__Vi0) {
            gpu__DOT____Vcellout__program_memory_controller__mem_read_address[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            gpu__DOT____Vcellout__program_memory_controller__consumer_read_data[__Vi0] = VL_RAND_RESET_I(16);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            gpu__DOT____Vcellinp__program_memory_controller__consumer_read_address[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            gpu__DOT____Vcellout__dispatch_instance__core_thread_count[__Vi0] = VL_RAND_RESET_I(4);
    }}
    { int __Vi0=0; for (; __Vi0<2; ++__Vi0) {
            gpu__DOT____Vcellout__dispatch_instance__core_block_id[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_address[__Vi0] = VL_RAND_RESET_I(8);
    }}
    gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_ready = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_read_data[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_address[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_data[__Vi0] = VL_RAND_RESET_I(8);
    }}
    gpu__DOT__cores__BRA__0__KET____DOT__core_lsu_write_ready = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_data[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_write_address[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            gpu__DOT____Vcellinp__cores__BRA__0__KET____DOT__core_instance__data_mem_read_data[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            gpu__DOT____Vcellout__cores__BRA__0__KET____DOT__core_instance__data_mem_read_address[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_address[__Vi0] = VL_RAND_RESET_I(8);
    }}
    gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_ready = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_read_data[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_address[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_data[__Vi0] = VL_RAND_RESET_I(8);
    }}
    gpu__DOT__cores__BRA__1__KET____DOT__core_lsu_write_ready = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_data[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_write_address[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            gpu__DOT____Vcellinp__cores__BRA__1__KET____DOT__core_instance__data_mem_read_data[__Vi0] = VL_RAND_RESET_I(8);
    }}
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            gpu__DOT____Vcellout__cores__BRA__1__KET____DOT__core_instance__data_mem_read_address[__Vi0] = VL_RAND_RESET_I(8);
    }}
    gpu__DOT__dcr_instance__DOT__device_conrol_register = VL_RAND_RESET_I(8);
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            gpu__DOT__data_memory_controller__DOT__controller_state[__Vi0] = VL_RAND_RESET_I(3);
    }}
    { int __Vi0=0; for (; __Vi0<8; ++__Vi0) {
            gpu__DOT__data_memory_controller__DOT__current_consumer[__Vi0] = VL_RAND_RESET_I(4);
    }}
    gpu__DOT__data_memory_controller__DOT__channel_serving_consumer = VL_RAND_RESET_I(16);
    gpu__DOT__data_memory_controller__DOT__j = VL_RAND_RESET_I(32);
    gpu__DOT__program_memory_controller__DOT__consumer_write_valid = VL_RAND_RESET_I(2);
    gpu__DOT__program_memory_controller__DOT__consumer_write_ready = VL_RAND_RESET_I(2);
    gpu__DOT__program_memory_controller__DOT__mem_write_ready = VL_RAND_RESET_I(1);
    { int __Vi0=0; for (; __Vi0<1; ++__Vi0) {
            gpu__DOT__program_memory_controller__DOT__controller_state[__Vi0] = VL_RAND_RESET_I(3);
    }}
    { int __Vi0=0; for (; __Vi0<1; ++__Vi0) {
            gpu__DOT__program_memory_controller__DOT__current_consumer[__Vi0] = VL_RAND_RESET_I(1);
    }}
    gpu__DOT__program_memory_controller__DOT__channel_serving_consumer = VL_RAND_RESET_I(2);
    gpu__DOT__program_memory_controller__DOT__j = VL_RAND_RESET_I(32);
    gpu__DOT__program_memory_controller__DOT____Vlvbound6 = VL_RAND_RESET_I(1);
    gpu__DOT__program_memory_controller__DOT____Vlvbound8 = VL_RAND_RESET_I(8);
    gpu__DOT__dispatch_instance__DOT__blocks_dispatched = VL_RAND_RESET_I(8);
    gpu__DOT__dispatch_instance__DOT__blocks_done = VL_RAND_RESET_I(8);
    gpu__DOT__dispatch_instance__DOT__start_execution = VL_RAND_RESET_I(1);
    __Vdly__gpu__DOT__core_start = VL_RAND_RESET_I(2);
    __Vdly__gpu__DOT__core_reset = VL_RAND_RESET_I(2);
}
