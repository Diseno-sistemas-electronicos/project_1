#include <systemc.h>

#include "instruction_register.cpp"
#include "stim.h"

int sc_main(int argc, char* argv[])
{
		//-- Signals --//
		//-- In --//
		sc_clock clock("clock",10,SC_NS,0.5);	// Create a clock signal
		sc_signal<sc_uint<64> > instructionIn;
		sc_signal<bool> enable;
		sc_signal<bool> write;
		sc_signal<sc_uint<64> > instructionOut;	
	
	
		sc_trace_file *fp;					// Create VCD file
		fp=sc_create_vcd_trace_file("wave");// open(fp), create wave.vcd file
		fp->set_time_unit(1, SC_NS);		// set tracing resolution to ns
		
		instruction_register DUT("instruction_register");
		
		DUT.clock(clock);
		DUT.instructionIn(instructionIn);
		DUT.enable(enable);
		DUT.write(write);
		DUT.instructionOut(instructionOut);
		
		stim STIM("stimulus");				// Instantiate stimulus generator
		STIM.clock(clock);
		STIM.instructionIn(instructionIn);
		STIM.enable(enable);
		STIM.write(write);
		
		sc_trace(fp,clock,"clock");	
		sc_trace(fp,instructionIn,"instructionIn");
		sc_trace(fp,enable,"enable");
		sc_trace(fp,write,"write");
		sc_trace(fp,instructionOut,"instructionOut");
		
		sc_start(100, SC_NS);			   	// Run simulation

		sc_close_vcd_trace_file(fp);		// close(fp)

		return 0;							// Return OK, no errors.		

}