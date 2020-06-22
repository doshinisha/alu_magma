#include "VSimpleALU.h"
#include "verilated.h"
#include <iostream>
#include <fstream>
#include <verilated_vcd_c.h>
#include <sys/types.h>
#include <sys/stat.h>
#include "VSimpleALU__Syms.h"
#include "VSimpleALU.h"

// Based on https://www.veripool.org/projects/verilator/wiki/Manual-verilator#CONNECTING-TO-C
vluint64_t main_time = 0;       // Current simulation time
// This is a 64-bit integer to reduce wrap over issues and
// allow modulus.  You can also use a double, if you wish.

double sc_time_stamp () {       // Called by $time in Verilog
    return main_time;           // converts to double, to match
                                // what SystemC does
}

// function to write_coverage
#ifdef _VERILATED_COV_H_
void write_coverage() {
     VerilatedCov::write("logs/coverage.dat");
}

#endif

#if VM_TRACE
VerilatedVcdC* tracer;
#endif

void my_assert(
    unsigned int got,
    unsigned int expected,
    int i,
    const char* port) {
  if (got != expected) {
    std::cerr << std::endl;  // end the current line
    std::cerr << "Got      : 0x" << std::hex << got << std::endl;
    std::cerr << "Expected : 0x" << std::hex << expected << std::endl;
    std::cerr << "i        : " << std::dec << i << std::endl;
    std::cerr << "Port     : " << port << std::endl;
#if VM_TRACE
    // Dump one more timestep so we see the current values
    main_time++;
    tracer->dump(main_time);
    tracer->close();
#endif
    
    exit(1);
  }
}

int main(int argc, char **argv) {
  Verilated::commandArgs(argc, argv);
  VSimpleALU* top = new VSimpleALU;
  
#if VM_TRACE
  Verilated::traceEverOn(true);
  tracer = new VerilatedVcdC;
  top->trace(tracer, 99);
  mkdir("logs", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
  tracer->open("logs/SimpleALU.vcd");
#endif

  top->CLK = 0;
  top->CLK = 0;
  top->config_en = 1;
  top->config_data = 3;
  top->eval();
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->CLK ^= 1;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  top->a = 3;
  top->b = 2;
  top->eval();
  main_time++;
  #if VM_TRACE
  tracer->dump(main_time);
  #endif
  my_assert(top->c, 1 & 65535, 8, "SimpleALU.c");


#if VM_TRACE
  tracer->close();
#endif
  

#ifdef _VERILATED_COV_H_
    write_coverage();
#endif

}
