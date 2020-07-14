#include <systemc.h>

#include "program_counter.cpp"
#include "stim.h"

int sc_main(int argc, char* argv[])
{
		//-- Signals --//
		//-- In --//
		sc_clock clock("clock",10,SC_NS,0.5);	// Create a clock signal
	
		sc_signal<bool> reset;
		sc_signal<bool> enable;
		sc_signal<bool> load;
		sc_signal<sc_uint<9> > counter_out;
		sc_signal<sc_uint<9> > counter_in;
	
		sc_trace_file *fp;					// Create VCD file
		fp=sc_create_vcd_trace_file("wave");// open(fp), create wave.vcd file
		fp->set_time_unit(1, SC_NS);		// set tracing resolution to ns
		
		program_counter DUT("program_counter");
		
		DUT.clock(clock);
		DUT.reset(reset);
		DUT.enable(enable);
		DUT.load(load);
		DUT.counter_out(counter_out);
		DUT.counter_in(counter_in);
		
		stim STIM("stimulus");				// Instantiate stimulus generator
		STIM.clock(clock);
		STIM.reset(reset);
		STIM.enable(enable);
		STIM.load(load);
		STIM.counter_in(counter_in);
		
		sc_trace(fp,clock,"clock");	
		sc_trace(fp,reset,"reset");
		sc_trace(fp,enable,"enable");
		sc_trace(fp,load,"load");
		sc_trace(fp,counter_out,"counter_out");
		sc_trace(fp,counter_in,"counter_in");
		
		sc_start(100, SC_NS);			   	// Run simulation

		sc_close_vcd_trace_file(fp);		// close(fp)

		return 0;							// Return OK, no errors.		

}