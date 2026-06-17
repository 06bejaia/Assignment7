// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vgpu.h for the primary calling header

#ifndef _VGPU_CORE__T8_H_
#define _VGPU_CORE__T8_H_  // guard

#include "verilated.h"

//==========

class Vgpu__Syms;

//----------

VL_MODULE(Vgpu_core__T8) {
  public:
    
    // PORTS
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(start,0,0);
    VL_OUT8(done,0,0);
    VL_IN8(block_id,7,0);
    VL_IN8(thread_count,3,0);
    VL_OUT8(program_mem_read_valid,0,0);
    VL_OUT8(program_mem_read_address,7,0);
    VL_IN8(program_mem_read_ready,0,0);
    VL_OUT8(data_mem_read_valid,7,0);
    VL_IN8(data_mem_read_ready,7,0);
    VL_OUT8(data_mem_write_valid,7,0);
    VL_IN8(data_mem_write_ready,7,0);
    VL_IN16(program_mem_read_data,15,0);
    VL_OUT8(data_mem_read_address[8],7,0);
    VL_IN8(data_mem_read_data[8],7,0);
    VL_OUT8(data_mem_write_address[8],7,0);
    VL_OUT8(data_mem_write_data[8],7,0);
    
    // LOCAL SIGNALS
    CData/*2:0*/ __PVT__core_state;
    CData/*2:0*/ __PVT__fetcher_state;
    CData/*7:0*/ __PVT__current_pc;
    CData/*3:0*/ __PVT__decoded_rd_address;
    CData/*3:0*/ __PVT__decoded_rs_address;
    CData/*3:0*/ __PVT__decoded_rt_address;
    CData/*2:0*/ __PVT__decoded_nzp;
    CData/*7:0*/ __PVT__decoded_immediate;
    CData/*0:0*/ __PVT__decoded_reg_write_enable;
    CData/*0:0*/ __PVT__decoded_mem_read_enable;
    CData/*0:0*/ __PVT__decoded_mem_write_enable;
    CData/*0:0*/ __PVT__decoded_nzp_write_enable;
    CData/*1:0*/ __PVT__decoded_reg_input_mux;
    CData/*1:0*/ __PVT__decoded_alu_arithmetic_mux;
    CData/*0:0*/ __PVT__decoded_alu_output_mux;
    CData/*0:0*/ __PVT__decoded_pc_mux;
    CData/*0:0*/ __PVT__decoded_ret;
    CData/*0:0*/ __PVT__scheduler_instance__DOT__unnamedblk1__DOT__any_lsu_waiting;
    CData/*7:0*/ __PVT__threads__BRA__0__KET____DOT__alu_instance__DOT__alu_out_reg;
    CData/*2:0*/ __PVT__threads__BRA__0__KET____DOT__pc_instance__DOT__nzp;
    CData/*7:0*/ __PVT__threads__BRA__1__KET____DOT__alu_instance__DOT__alu_out_reg;
    CData/*2:0*/ __PVT__threads__BRA__1__KET____DOT__pc_instance__DOT__nzp;
    CData/*7:0*/ __PVT__threads__BRA__2__KET____DOT__alu_instance__DOT__alu_out_reg;
    CData/*2:0*/ __PVT__threads__BRA__2__KET____DOT__pc_instance__DOT__nzp;
    CData/*7:0*/ __PVT__threads__BRA__3__KET____DOT__alu_instance__DOT__alu_out_reg;
    CData/*2:0*/ __PVT__threads__BRA__3__KET____DOT__pc_instance__DOT__nzp;
    CData/*7:0*/ __PVT__threads__BRA__4__KET____DOT__alu_instance__DOT__alu_out_reg;
    CData/*2:0*/ __PVT__threads__BRA__4__KET____DOT__pc_instance__DOT__nzp;
    CData/*7:0*/ __PVT__threads__BRA__5__KET____DOT__alu_instance__DOT__alu_out_reg;
    CData/*2:0*/ __PVT__threads__BRA__5__KET____DOT__pc_instance__DOT__nzp;
    CData/*7:0*/ __PVT__threads__BRA__6__KET____DOT__alu_instance__DOT__alu_out_reg;
    CData/*2:0*/ __PVT__threads__BRA__6__KET____DOT__pc_instance__DOT__nzp;
    CData/*7:0*/ __PVT__threads__BRA__7__KET____DOT__alu_instance__DOT__alu_out_reg;
    CData/*2:0*/ __PVT__threads__BRA__7__KET____DOT__pc_instance__DOT__nzp;
    SData/*15:0*/ __PVT__instruction;
    IData/*31:0*/ __PVT__scheduler_instance__DOT__unnamedblk1__DOT__unnamedblk2__DOT__i;
    CData/*7:0*/ __PVT__next_pc[8];
    CData/*7:0*/ __PVT__rs[8];
    CData/*7:0*/ __PVT__rt[8];
    CData/*1:0*/ __PVT__lsu_state[8];
    CData/*7:0*/ __PVT__lsu_out[8];
    CData/*7:0*/ __PVT__alu_out[8];
    CData/*7:0*/ __PVT__threads__BRA__0__KET____DOT__register_instance__DOT__registers[16];
    CData/*7:0*/ __PVT__threads__BRA__1__KET____DOT__register_instance__DOT__registers[16];
    CData/*7:0*/ __PVT__threads__BRA__2__KET____DOT__register_instance__DOT__registers[16];
    CData/*7:0*/ __PVT__threads__BRA__3__KET____DOT__register_instance__DOT__registers[16];
    CData/*7:0*/ __PVT__threads__BRA__4__KET____DOT__register_instance__DOT__registers[16];
    CData/*7:0*/ __PVT__threads__BRA__5__KET____DOT__register_instance__DOT__registers[16];
    CData/*7:0*/ __PVT__threads__BRA__6__KET____DOT__register_instance__DOT__registers[16];
    CData/*7:0*/ __PVT__threads__BRA__7__KET____DOT__register_instance__DOT__registers[16];
    
    // LOCAL VARIABLES
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*7:0*/ __Vcellout__threads__BRA__0__KET____DOT__lsu_instance__lsu_out;
        CData/*1:0*/ __Vcellout__threads__BRA__0__KET____DOT__lsu_instance__lsu_state;
        CData/*7:0*/ __Vcellout__threads__BRA__0__KET____DOT__lsu_instance__mem_write_data;
        CData/*7:0*/ __Vcellout__threads__BRA__0__KET____DOT__lsu_instance__mem_write_address;
        CData/*0:0*/ __Vcellout__threads__BRA__0__KET____DOT__lsu_instance__mem_write_valid;
        CData/*7:0*/ __Vcellout__threads__BRA__0__KET____DOT__lsu_instance__mem_read_address;
        CData/*0:0*/ __Vcellout__threads__BRA__0__KET____DOT__lsu_instance__mem_read_valid;
        CData/*7:0*/ __Vcellout__threads__BRA__0__KET____DOT__register_instance__rt;
        CData/*7:0*/ __Vcellout__threads__BRA__0__KET____DOT__register_instance__rs;
        CData/*7:0*/ __Vcellout__threads__BRA__0__KET____DOT__pc_instance__next_pc;
        CData/*7:0*/ __Vcellout__threads__BRA__1__KET____DOT__lsu_instance__lsu_out;
        CData/*1:0*/ __Vcellout__threads__BRA__1__KET____DOT__lsu_instance__lsu_state;
        CData/*7:0*/ __Vcellout__threads__BRA__1__KET____DOT__lsu_instance__mem_write_data;
        CData/*7:0*/ __Vcellout__threads__BRA__1__KET____DOT__lsu_instance__mem_write_address;
        CData/*0:0*/ __Vcellout__threads__BRA__1__KET____DOT__lsu_instance__mem_write_valid;
        CData/*7:0*/ __Vcellout__threads__BRA__1__KET____DOT__lsu_instance__mem_read_address;
        CData/*0:0*/ __Vcellout__threads__BRA__1__KET____DOT__lsu_instance__mem_read_valid;
        CData/*7:0*/ __Vcellout__threads__BRA__1__KET____DOT__register_instance__rt;
        CData/*7:0*/ __Vcellout__threads__BRA__1__KET____DOT__register_instance__rs;
        CData/*7:0*/ __Vcellout__threads__BRA__1__KET____DOT__pc_instance__next_pc;
        CData/*7:0*/ __Vcellout__threads__BRA__2__KET____DOT__lsu_instance__lsu_out;
        CData/*1:0*/ __Vcellout__threads__BRA__2__KET____DOT__lsu_instance__lsu_state;
        CData/*7:0*/ __Vcellout__threads__BRA__2__KET____DOT__lsu_instance__mem_write_data;
        CData/*7:0*/ __Vcellout__threads__BRA__2__KET____DOT__lsu_instance__mem_write_address;
        CData/*0:0*/ __Vcellout__threads__BRA__2__KET____DOT__lsu_instance__mem_write_valid;
        CData/*7:0*/ __Vcellout__threads__BRA__2__KET____DOT__lsu_instance__mem_read_address;
        CData/*0:0*/ __Vcellout__threads__BRA__2__KET____DOT__lsu_instance__mem_read_valid;
        CData/*7:0*/ __Vcellout__threads__BRA__2__KET____DOT__register_instance__rt;
        CData/*7:0*/ __Vcellout__threads__BRA__2__KET____DOT__register_instance__rs;
        CData/*7:0*/ __Vcellout__threads__BRA__2__KET____DOT__pc_instance__next_pc;
        CData/*7:0*/ __Vcellout__threads__BRA__3__KET____DOT__lsu_instance__lsu_out;
        CData/*1:0*/ __Vcellout__threads__BRA__3__KET____DOT__lsu_instance__lsu_state;
        CData/*7:0*/ __Vcellout__threads__BRA__3__KET____DOT__lsu_instance__mem_write_data;
        CData/*7:0*/ __Vcellout__threads__BRA__3__KET____DOT__lsu_instance__mem_write_address;
        CData/*0:0*/ __Vcellout__threads__BRA__3__KET____DOT__lsu_instance__mem_write_valid;
        CData/*7:0*/ __Vcellout__threads__BRA__3__KET____DOT__lsu_instance__mem_read_address;
        CData/*0:0*/ __Vcellout__threads__BRA__3__KET____DOT__lsu_instance__mem_read_valid;
        CData/*7:0*/ __Vcellout__threads__BRA__3__KET____DOT__register_instance__rt;
        CData/*7:0*/ __Vcellout__threads__BRA__3__KET____DOT__register_instance__rs;
        CData/*7:0*/ __Vcellout__threads__BRA__3__KET____DOT__pc_instance__next_pc;
        CData/*7:0*/ __Vcellout__threads__BRA__4__KET____DOT__lsu_instance__lsu_out;
        CData/*1:0*/ __Vcellout__threads__BRA__4__KET____DOT__lsu_instance__lsu_state;
        CData/*7:0*/ __Vcellout__threads__BRA__4__KET____DOT__lsu_instance__mem_write_data;
        CData/*7:0*/ __Vcellout__threads__BRA__4__KET____DOT__lsu_instance__mem_write_address;
        CData/*0:0*/ __Vcellout__threads__BRA__4__KET____DOT__lsu_instance__mem_write_valid;
        CData/*7:0*/ __Vcellout__threads__BRA__4__KET____DOT__lsu_instance__mem_read_address;
        CData/*0:0*/ __Vcellout__threads__BRA__4__KET____DOT__lsu_instance__mem_read_valid;
        CData/*7:0*/ __Vcellout__threads__BRA__4__KET____DOT__register_instance__rt;
        CData/*7:0*/ __Vcellout__threads__BRA__4__KET____DOT__register_instance__rs;
        CData/*7:0*/ __Vcellout__threads__BRA__4__KET____DOT__pc_instance__next_pc;
        CData/*7:0*/ __Vcellout__threads__BRA__5__KET____DOT__lsu_instance__lsu_out;
        CData/*1:0*/ __Vcellout__threads__BRA__5__KET____DOT__lsu_instance__lsu_state;
        CData/*7:0*/ __Vcellout__threads__BRA__5__KET____DOT__lsu_instance__mem_write_data;
        CData/*7:0*/ __Vcellout__threads__BRA__5__KET____DOT__lsu_instance__mem_write_address;
        CData/*0:0*/ __Vcellout__threads__BRA__5__KET____DOT__lsu_instance__mem_write_valid;
        CData/*7:0*/ __Vcellout__threads__BRA__5__KET____DOT__lsu_instance__mem_read_address;
        CData/*0:0*/ __Vcellout__threads__BRA__5__KET____DOT__lsu_instance__mem_read_valid;
        CData/*7:0*/ __Vcellout__threads__BRA__5__KET____DOT__register_instance__rt;
        CData/*7:0*/ __Vcellout__threads__BRA__5__KET____DOT__register_instance__rs;
        CData/*7:0*/ __Vcellout__threads__BRA__5__KET____DOT__pc_instance__next_pc;
        CData/*7:0*/ __Vcellout__threads__BRA__6__KET____DOT__lsu_instance__lsu_out;
        CData/*1:0*/ __Vcellout__threads__BRA__6__KET____DOT__lsu_instance__lsu_state;
        CData/*7:0*/ __Vcellout__threads__BRA__6__KET____DOT__lsu_instance__mem_write_data;
        CData/*7:0*/ __Vcellout__threads__BRA__6__KET____DOT__lsu_instance__mem_write_address;
    };
    struct {
        CData/*0:0*/ __Vcellout__threads__BRA__6__KET____DOT__lsu_instance__mem_write_valid;
        CData/*7:0*/ __Vcellout__threads__BRA__6__KET____DOT__lsu_instance__mem_read_address;
        CData/*0:0*/ __Vcellout__threads__BRA__6__KET____DOT__lsu_instance__mem_read_valid;
        CData/*7:0*/ __Vcellout__threads__BRA__6__KET____DOT__register_instance__rt;
        CData/*7:0*/ __Vcellout__threads__BRA__6__KET____DOT__register_instance__rs;
        CData/*7:0*/ __Vcellout__threads__BRA__6__KET____DOT__pc_instance__next_pc;
        CData/*7:0*/ __Vcellout__threads__BRA__7__KET____DOT__lsu_instance__lsu_out;
        CData/*1:0*/ __Vcellout__threads__BRA__7__KET____DOT__lsu_instance__lsu_state;
        CData/*7:0*/ __Vcellout__threads__BRA__7__KET____DOT__lsu_instance__mem_write_data;
        CData/*7:0*/ __Vcellout__threads__BRA__7__KET____DOT__lsu_instance__mem_write_address;
        CData/*0:0*/ __Vcellout__threads__BRA__7__KET____DOT__lsu_instance__mem_write_valid;
        CData/*7:0*/ __Vcellout__threads__BRA__7__KET____DOT__lsu_instance__mem_read_address;
        CData/*0:0*/ __Vcellout__threads__BRA__7__KET____DOT__lsu_instance__mem_read_valid;
        CData/*7:0*/ __Vcellout__threads__BRA__7__KET____DOT__register_instance__rt;
        CData/*7:0*/ __Vcellout__threads__BRA__7__KET____DOT__register_instance__rs;
        CData/*7:0*/ __Vcellout__threads__BRA__7__KET____DOT__pc_instance__next_pc;
        CData/*2:0*/ __Vdly__fetcher_state;
        CData/*7:0*/ __Vdly__current_pc;
        CData/*2:0*/ __Vdly__core_state;
        CData/*1:0*/ __Vdly____Vcellout__threads__BRA__0__KET____DOT__lsu_instance__lsu_state;
        CData/*0:0*/ __Vdlyvset__threads__BRA__0__KET____DOT__register_instance__DOT__registers__v0;
        CData/*7:0*/ __Vdlyvval__threads__BRA__0__KET____DOT__register_instance__DOT__registers__v16;
        CData/*0:0*/ __Vdlyvset__threads__BRA__0__KET____DOT__register_instance__DOT__registers__v16;
        CData/*3:0*/ __Vdlyvdim0__threads__BRA__0__KET____DOT__register_instance__DOT__registers__v17;
        CData/*7:0*/ __Vdlyvval__threads__BRA__0__KET____DOT__register_instance__DOT__registers__v17;
        CData/*0:0*/ __Vdlyvset__threads__BRA__0__KET____DOT__register_instance__DOT__registers__v17;
        CData/*3:0*/ __Vdlyvdim0__threads__BRA__0__KET____DOT__register_instance__DOT__registers__v18;
        CData/*7:0*/ __Vdlyvval__threads__BRA__0__KET____DOT__register_instance__DOT__registers__v18;
        CData/*0:0*/ __Vdlyvset__threads__BRA__0__KET____DOT__register_instance__DOT__registers__v18;
        CData/*3:0*/ __Vdlyvdim0__threads__BRA__0__KET____DOT__register_instance__DOT__registers__v19;
        CData/*7:0*/ __Vdlyvval__threads__BRA__0__KET____DOT__register_instance__DOT__registers__v19;
        CData/*0:0*/ __Vdlyvset__threads__BRA__0__KET____DOT__register_instance__DOT__registers__v19;
        CData/*1:0*/ __Vdly____Vcellout__threads__BRA__1__KET____DOT__lsu_instance__lsu_state;
        CData/*0:0*/ __Vdlyvset__threads__BRA__1__KET____DOT__register_instance__DOT__registers__v0;
        CData/*7:0*/ __Vdlyvval__threads__BRA__1__KET____DOT__register_instance__DOT__registers__v16;
        CData/*0:0*/ __Vdlyvset__threads__BRA__1__KET____DOT__register_instance__DOT__registers__v16;
        CData/*3:0*/ __Vdlyvdim0__threads__BRA__1__KET____DOT__register_instance__DOT__registers__v17;
        CData/*7:0*/ __Vdlyvval__threads__BRA__1__KET____DOT__register_instance__DOT__registers__v17;
        CData/*0:0*/ __Vdlyvset__threads__BRA__1__KET____DOT__register_instance__DOT__registers__v17;
        CData/*3:0*/ __Vdlyvdim0__threads__BRA__1__KET____DOT__register_instance__DOT__registers__v18;
        CData/*7:0*/ __Vdlyvval__threads__BRA__1__KET____DOT__register_instance__DOT__registers__v18;
        CData/*0:0*/ __Vdlyvset__threads__BRA__1__KET____DOT__register_instance__DOT__registers__v18;
        CData/*3:0*/ __Vdlyvdim0__threads__BRA__1__KET____DOT__register_instance__DOT__registers__v19;
        CData/*7:0*/ __Vdlyvval__threads__BRA__1__KET____DOT__register_instance__DOT__registers__v19;
        CData/*0:0*/ __Vdlyvset__threads__BRA__1__KET____DOT__register_instance__DOT__registers__v19;
        CData/*1:0*/ __Vdly____Vcellout__threads__BRA__2__KET____DOT__lsu_instance__lsu_state;
        CData/*0:0*/ __Vdlyvset__threads__BRA__2__KET____DOT__register_instance__DOT__registers__v0;
        CData/*7:0*/ __Vdlyvval__threads__BRA__2__KET____DOT__register_instance__DOT__registers__v16;
        CData/*0:0*/ __Vdlyvset__threads__BRA__2__KET____DOT__register_instance__DOT__registers__v16;
        CData/*3:0*/ __Vdlyvdim0__threads__BRA__2__KET____DOT__register_instance__DOT__registers__v17;
        CData/*7:0*/ __Vdlyvval__threads__BRA__2__KET____DOT__register_instance__DOT__registers__v17;
        CData/*0:0*/ __Vdlyvset__threads__BRA__2__KET____DOT__register_instance__DOT__registers__v17;
        CData/*3:0*/ __Vdlyvdim0__threads__BRA__2__KET____DOT__register_instance__DOT__registers__v18;
        CData/*7:0*/ __Vdlyvval__threads__BRA__2__KET____DOT__register_instance__DOT__registers__v18;
        CData/*0:0*/ __Vdlyvset__threads__BRA__2__KET____DOT__register_instance__DOT__registers__v18;
        CData/*3:0*/ __Vdlyvdim0__threads__BRA__2__KET____DOT__register_instance__DOT__registers__v19;
        CData/*7:0*/ __Vdlyvval__threads__BRA__2__KET____DOT__register_instance__DOT__registers__v19;
        CData/*0:0*/ __Vdlyvset__threads__BRA__2__KET____DOT__register_instance__DOT__registers__v19;
        CData/*1:0*/ __Vdly____Vcellout__threads__BRA__3__KET____DOT__lsu_instance__lsu_state;
        CData/*0:0*/ __Vdlyvset__threads__BRA__3__KET____DOT__register_instance__DOT__registers__v0;
        CData/*7:0*/ __Vdlyvval__threads__BRA__3__KET____DOT__register_instance__DOT__registers__v16;
        CData/*0:0*/ __Vdlyvset__threads__BRA__3__KET____DOT__register_instance__DOT__registers__v16;
        CData/*3:0*/ __Vdlyvdim0__threads__BRA__3__KET____DOT__register_instance__DOT__registers__v17;
        CData/*7:0*/ __Vdlyvval__threads__BRA__3__KET____DOT__register_instance__DOT__registers__v17;
    };
    struct {
        CData/*0:0*/ __Vdlyvset__threads__BRA__3__KET____DOT__register_instance__DOT__registers__v17;
        CData/*3:0*/ __Vdlyvdim0__threads__BRA__3__KET____DOT__register_instance__DOT__registers__v18;
        CData/*7:0*/ __Vdlyvval__threads__BRA__3__KET____DOT__register_instance__DOT__registers__v18;
        CData/*0:0*/ __Vdlyvset__threads__BRA__3__KET____DOT__register_instance__DOT__registers__v18;
        CData/*3:0*/ __Vdlyvdim0__threads__BRA__3__KET____DOT__register_instance__DOT__registers__v19;
        CData/*7:0*/ __Vdlyvval__threads__BRA__3__KET____DOT__register_instance__DOT__registers__v19;
        CData/*0:0*/ __Vdlyvset__threads__BRA__3__KET____DOT__register_instance__DOT__registers__v19;
        CData/*1:0*/ __Vdly____Vcellout__threads__BRA__4__KET____DOT__lsu_instance__lsu_state;
        CData/*0:0*/ __Vdlyvset__threads__BRA__4__KET____DOT__register_instance__DOT__registers__v0;
        CData/*7:0*/ __Vdlyvval__threads__BRA__4__KET____DOT__register_instance__DOT__registers__v16;
        CData/*0:0*/ __Vdlyvset__threads__BRA__4__KET____DOT__register_instance__DOT__registers__v16;
        CData/*3:0*/ __Vdlyvdim0__threads__BRA__4__KET____DOT__register_instance__DOT__registers__v17;
        CData/*7:0*/ __Vdlyvval__threads__BRA__4__KET____DOT__register_instance__DOT__registers__v17;
        CData/*0:0*/ __Vdlyvset__threads__BRA__4__KET____DOT__register_instance__DOT__registers__v17;
        CData/*3:0*/ __Vdlyvdim0__threads__BRA__4__KET____DOT__register_instance__DOT__registers__v18;
        CData/*7:0*/ __Vdlyvval__threads__BRA__4__KET____DOT__register_instance__DOT__registers__v18;
        CData/*0:0*/ __Vdlyvset__threads__BRA__4__KET____DOT__register_instance__DOT__registers__v18;
        CData/*3:0*/ __Vdlyvdim0__threads__BRA__4__KET____DOT__register_instance__DOT__registers__v19;
        CData/*7:0*/ __Vdlyvval__threads__BRA__4__KET____DOT__register_instance__DOT__registers__v19;
        CData/*0:0*/ __Vdlyvset__threads__BRA__4__KET____DOT__register_instance__DOT__registers__v19;
        CData/*1:0*/ __Vdly____Vcellout__threads__BRA__5__KET____DOT__lsu_instance__lsu_state;
        CData/*0:0*/ __Vdlyvset__threads__BRA__5__KET____DOT__register_instance__DOT__registers__v0;
        CData/*7:0*/ __Vdlyvval__threads__BRA__5__KET____DOT__register_instance__DOT__registers__v16;
        CData/*0:0*/ __Vdlyvset__threads__BRA__5__KET____DOT__register_instance__DOT__registers__v16;
        CData/*3:0*/ __Vdlyvdim0__threads__BRA__5__KET____DOT__register_instance__DOT__registers__v17;
        CData/*7:0*/ __Vdlyvval__threads__BRA__5__KET____DOT__register_instance__DOT__registers__v17;
        CData/*0:0*/ __Vdlyvset__threads__BRA__5__KET____DOT__register_instance__DOT__registers__v17;
        CData/*3:0*/ __Vdlyvdim0__threads__BRA__5__KET____DOT__register_instance__DOT__registers__v18;
        CData/*7:0*/ __Vdlyvval__threads__BRA__5__KET____DOT__register_instance__DOT__registers__v18;
        CData/*0:0*/ __Vdlyvset__threads__BRA__5__KET____DOT__register_instance__DOT__registers__v18;
        CData/*3:0*/ __Vdlyvdim0__threads__BRA__5__KET____DOT__register_instance__DOT__registers__v19;
        CData/*7:0*/ __Vdlyvval__threads__BRA__5__KET____DOT__register_instance__DOT__registers__v19;
        CData/*0:0*/ __Vdlyvset__threads__BRA__5__KET____DOT__register_instance__DOT__registers__v19;
        CData/*1:0*/ __Vdly____Vcellout__threads__BRA__6__KET____DOT__lsu_instance__lsu_state;
        CData/*0:0*/ __Vdlyvset__threads__BRA__6__KET____DOT__register_instance__DOT__registers__v0;
        CData/*7:0*/ __Vdlyvval__threads__BRA__6__KET____DOT__register_instance__DOT__registers__v16;
        CData/*0:0*/ __Vdlyvset__threads__BRA__6__KET____DOT__register_instance__DOT__registers__v16;
        CData/*3:0*/ __Vdlyvdim0__threads__BRA__6__KET____DOT__register_instance__DOT__registers__v17;
        CData/*7:0*/ __Vdlyvval__threads__BRA__6__KET____DOT__register_instance__DOT__registers__v17;
        CData/*0:0*/ __Vdlyvset__threads__BRA__6__KET____DOT__register_instance__DOT__registers__v17;
        CData/*3:0*/ __Vdlyvdim0__threads__BRA__6__KET____DOT__register_instance__DOT__registers__v18;
        CData/*7:0*/ __Vdlyvval__threads__BRA__6__KET____DOT__register_instance__DOT__registers__v18;
        CData/*0:0*/ __Vdlyvset__threads__BRA__6__KET____DOT__register_instance__DOT__registers__v18;
        CData/*3:0*/ __Vdlyvdim0__threads__BRA__6__KET____DOT__register_instance__DOT__registers__v19;
        CData/*7:0*/ __Vdlyvval__threads__BRA__6__KET____DOT__register_instance__DOT__registers__v19;
        CData/*0:0*/ __Vdlyvset__threads__BRA__6__KET____DOT__register_instance__DOT__registers__v19;
        CData/*1:0*/ __Vdly____Vcellout__threads__BRA__7__KET____DOT__lsu_instance__lsu_state;
        CData/*0:0*/ __Vdlyvset__threads__BRA__7__KET____DOT__register_instance__DOT__registers__v0;
        CData/*7:0*/ __Vdlyvval__threads__BRA__7__KET____DOT__register_instance__DOT__registers__v16;
        CData/*0:0*/ __Vdlyvset__threads__BRA__7__KET____DOT__register_instance__DOT__registers__v16;
        CData/*3:0*/ __Vdlyvdim0__threads__BRA__7__KET____DOT__register_instance__DOT__registers__v17;
        CData/*7:0*/ __Vdlyvval__threads__BRA__7__KET____DOT__register_instance__DOT__registers__v17;
        CData/*0:0*/ __Vdlyvset__threads__BRA__7__KET____DOT__register_instance__DOT__registers__v17;
        CData/*3:0*/ __Vdlyvdim0__threads__BRA__7__KET____DOT__register_instance__DOT__registers__v18;
        CData/*7:0*/ __Vdlyvval__threads__BRA__7__KET____DOT__register_instance__DOT__registers__v18;
        CData/*0:0*/ __Vdlyvset__threads__BRA__7__KET____DOT__register_instance__DOT__registers__v18;
        CData/*3:0*/ __Vdlyvdim0__threads__BRA__7__KET____DOT__register_instance__DOT__registers__v19;
        CData/*7:0*/ __Vdlyvval__threads__BRA__7__KET____DOT__register_instance__DOT__registers__v19;
        CData/*0:0*/ __Vdlyvset__threads__BRA__7__KET____DOT__register_instance__DOT__registers__v19;
        CData/*7:0*/ __Vcellinp__scheduler_instance__next_pc[8];
        CData/*1:0*/ __Vcellinp__scheduler_instance__lsu_state[8];
    };
    
    // INTERNAL VARIABLES
  private:
    Vgpu__Syms* __VlSymsp;  // Symbol table
  public:
    
    // CONSTRUCTORS
  private:
    VL_UNCOPYABLE(Vgpu_core__T8);  ///< Copying not allowed
  public:
    Vgpu_core__T8(const char* name = "TOP");
    ~Vgpu_core__T8();
    
    // INTERNAL METHODS
    void __Vconfigure(Vgpu__Syms* symsp, bool first);
  private:
    void _ctor_var_reset() VL_ATTR_COLD;
  public:
    void _sequent__TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance__1(Vgpu__Syms* __restrict vlSymsp);
    void _sequent__TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance__2(Vgpu__Syms* __restrict vlSymsp);
    void _settle__TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance__3(Vgpu__Syms* __restrict vlSymsp) VL_ATTR_COLD;
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

//----------


#endif  // guard
