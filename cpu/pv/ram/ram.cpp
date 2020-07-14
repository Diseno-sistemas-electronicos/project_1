//-----------------------------------------------------
#include "systemc.h"
#include <unistd.h>

SC_MODULE (ram) {
    
	//-- Signals --//
	sc_in_clk clock;		// Clock
	sc_in<bool> enable;		// Available to read/write
	sc_in<bool> write;		// write if true; read if false
	sc_in<sc_uint<9> > address;	// Addressing the memory for write/read
	sc_in<sc_uint<9> > dataIn; 		// Data to be written/read
	sc_out<sc_uint<9> > dataOut;
  //-----------Internal variables-------------------
  int * mem;
  
  // Constructor for memory
  //SC_CTOR(ram) {
  SC_HAS_PROCESS(ram);
    ram(sc_module_name ram, int size=8) : sc_module(ram) {
	
	SC_THREAD(ram_routine);		
	sensitive << clock.pos();
    mem = new int [size];
  } // End of Constructor

   //------------Code Starts Here-------------------------
  void updateMemory(int address, int data) {
    sleep(1); //will not move time stamp either
    mem [address] = data;
  }  
  
  void ram_routine() {
	while (true) {
		wait();
		if (enable.read() == 1) {
			if (write.read() == 1) {
				mem[address.read()] = dataIn.read();
			} else {
				dataOut.write(mem[address.read()]);
				}
			}
		}
	}

  
}; // End of Module memory