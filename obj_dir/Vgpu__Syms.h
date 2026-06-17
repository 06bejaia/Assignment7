// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef _VGPU__SYMS_H_
#define _VGPU__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODULE CLASSES
#include "Vgpu.h"
#include "Vgpu_core__T8.h"

// SYMS CLASS
class Vgpu__Syms : public VerilatedSyms {
  public:
    
    // LOCAL STATE
    const char* __Vm_namep;
    bool __Vm_didInit;
    
    // SUBCELL STATE
    Vgpu*                          TOPp;
    Vgpu_core__T8                  TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance;
    Vgpu_core__T8                  TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance;
    
    // CREATORS
    Vgpu__Syms(Vgpu* topp, const char* namep);
    ~Vgpu__Syms() {}
    
    // METHODS
    inline const char* name() { return __Vm_namep; }
    
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);

#endif  // guard
