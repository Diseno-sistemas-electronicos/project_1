#include <systemc.h>
#include "ram.cpp"
#include "stim.h"

// https://forums.accellera.org/topic/24-systemc-230-with-main/
int sc_main (int argc, char* argv[]) 
{
		int data;
		//-- In --//
		sc_clock clock("clock",10,SC_NS,0.5);	// Create a clock signal
	
		sc_signal<bool> enable;		// Available to read/write
		sc_signal<bool> write;		// write if true; read if false
		sc_signal<sc_uint<9> > address;	// Addressing the memory for write/read
		sc_signal<sc_uint<9> > dataIn; 		// Data to be written/read
		sc_signal<sc_uint<9> > dataOut;
	
		sc_trace_file *fp;					// Create VCD file
		fp=sc_create_vcd_trace_file("wave");// open(fp), create wave.vcd file
		fp->set_time_unit(1, SC_NS);		// set tracing resolution to ns
		
		ram mem("MEM", 1024);
		mem.clock(clock);
		mem.enable(enable);
		mem.write(write);
		mem.address(address);
		mem.dataIn(dataIn);
		mem.dataOut(dataOut);
  
		stim STIM("stimulus");				// Instantiate stimulus generator
		STIM.clock(clock);
		STIM.enable(enable);
		STIM.write(write);
		STIM.address(address);
		STIM.dataIn(dataIn);

	
		sc_trace(fp,clock,"clock");	
		sc_trace(fp,enable,"enable");
		sc_trace(fp,write,"write");
		sc_trace(fp,address,"address");
		sc_trace(fp,dataIn,"dataIn");
		sc_trace(fp,dataOut,"dataOut");
		
		
		sc_start(100, SC_NS);			   	// Run simulation

		sc_close_vcd_trace_file(fp);		// close(fp)

		return 0;							// Return OK, no errors.		

 }