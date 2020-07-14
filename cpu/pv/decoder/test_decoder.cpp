#include <systemc.h>

#include "decoder.cpp"
#include "stim.h"

int sc_main(int argc, char* argv[])
{
		//-- Signals --//
		//-- In --//
		sc_clock clock("clock",10,SC_NS,0.5);	// Create a clock signal
	
		sc_signal<sc_uint<64> > inst;	// Instruction
		sc_signal<sc_uint<4> > opcode;	// OPCODE
		sc_signal<sc_uint<8> > of1;		// Operando Fuente 1
		sc_signal<sc_uint<8> > of2;		// Operando Fuente 2
		sc_signal<sc_uint<9> > od;		// Operando destino
	
		sc_trace_file *fp;					// Create VCD file
		fp=sc_create_vcd_trace_file("wave");// open(fp), create wave.vcd file
		fp->set_time_unit(1, SC_NS);		// set tracing resolution to ns
		
		decoder DUT("decoder");
		
		DUT.inst(inst);
		DUT.opcode(opcode);
		DUT.of1(of1);
		DUT.of2(of2);
		DUT.od(od);
		
		stim STIM("stimulus");				// Instantiate stimulus generator
		STIM.clock(clock);
		STIM.inst(inst);

		
		sc_trace(fp,clock,"clock");	
		sc_trace(fp,inst,"inst");
		sc_trace(fp,opcode,"opcode");
		sc_trace(fp,of1,"of1");
		sc_trace(fp,of2,"of2");
		sc_trace(fp,od,"od");
		
		sc_start(100, SC_NS);			   	// Run simulation

		sc_close_vcd_trace_file(fp);		// close(fp)

		return 0;							// Return OK, no errors.		

}