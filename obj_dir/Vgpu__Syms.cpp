// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vgpu__Syms.h"
#include "Vgpu.h"
#include "Vgpu_core__T8.h"



// FUNCTIONS
Vgpu__Syms::Vgpu__Syms(Vgpu* topp, const char* namep)
    // Setup locals
    : __Vm_namep(namep)
    , __Vm_didInit(false)
    // Setup submodule names
    , TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance(Verilated::catName(topp->name(), "gpu.cores[0].core_instance"))
    , TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance(Verilated::catName(topp->name(), "gpu.cores[1].core_instance"))
{
    // Pointer to top level
    TOPp = topp;
    // Setup each module's pointers to their submodules
    TOPp->__PVT__gpu__DOT__cores__BRA__0__KET____DOT__core_instance = &TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance;
    TOPp->__PVT__gpu__DOT__cores__BRA__1__KET____DOT__core_instance = &TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance;
    // Setup each module's pointer back to symbol table (for public functions)
    TOPp->__Vconfigure(this, true);
    TOP__gpu__DOT__cores__BRA__0__KET____DOT__core_instance.__Vconfigure(this, true);
    TOP__gpu__DOT__cores__BRA__1__KET____DOT__core_instance.__Vconfigure(this, false);
}
