#include <systemc.h>

#include "pipeline_reg.h"
#include "stim.h"

int sc_main(int argc, char* argv[])
{
		//-- Signals --//
		//-- In --//
		sc_clock clock("clock",10,SC_NS,0.5);	// Create a clock signal
		
		sc_signal<bool> enable;		// Available to read/write
		sc_signal<bool> write;		// write if 1; read if 0
		sc_signal<sc_uint<4> > opcodeIn;	// OPCODE
		sc_signal<sc_uint<8> > of1In;	// Operando Fuente 1
		sc_signal<sc_uint<8> > of2In;	// Operando Fuente 2
		sc_signal<sc_uint<9> > odIn;		// Operando destino
		sc_signal<sc_uint<4> > opcodeOut;	// OPCODE
		sc_signal<sc_uint<8> > of1Out;	// Operando Fuente 1
		sc_signal<sc_uint<8> > of2Out;	// Operando Fuente 2
		sc_signal<sc_uint<9> > odOut;	// Operando destino
	
		sc_trace_file *fp;					// Create VCD file
		fp=sc_create_vcd_trace_file("wave");// open(fp), create wave.vcd file
		fp->set_time_unit(1, SC_NS);		// set tracing resolution to ns
		
		pipeline_reg DUT("pipeline_reg");
		
		DUT.clock(clock);
		DUT.enable(enable);
		DUT.write(write);
		DUT.opcodeIn(opcodeIn);
		DUT.of1In(of1In);
		DUT.of2In(of2In);
		DUT.odIn(odIn);
		DUT.opcodeOut(opcodeOut);
		DUT.of1Out(of1Out);
		DUT.of2Out(of2Out);
		DUT.odOut(odOut);

		
		stim STIM("stimulus");				// Instantiate stimulus generator
		STIM.clock(clock);
		STIM.enable(enable);
		STIM.write(write);
		STIM.opcodeIn(opcodeIn);
		STIM.of1In(of1In);
		STIM.of2In(of2In);
		STIM.odIn(odIn);
	
		
		sc_trace(fp,clock,"clock");	
		sc_trace(fp,enable,"enable");
		sc_trace(fp,write,"write");
		sc_trace(fp,opcodeIn,"opcodeIn");
		sc_trace(fp,of1In,"of1In");
		sc_trace(fp,of2In,"of2In");
		sc_trace(fp,odIn,"odIn");
		sc_trace(fp,opcodeOut,"opcodeOut");
		sc_trace(fp,of1Out,"of1Out");
		sc_trace(fp,of2Out,"of2Out");
		sc_trace(fp,odOut,"odOut");
		
		sc_start(100, SC_NS);			   	// Run simulation

		sc_close_vcd_trace_file(fp);		// close(fp)

		return 0;							// Return OK, no errors.		

}