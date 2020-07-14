#include <systemc.h>

#include "ula.h"
#include "stim.h"

int sc_main(int argc, char* argv[])
{
		//-- Signals --//
		//-- In --//
		sc_clock clock("clock",10,SC_NS,0.5);	// Create a clock signal
	
		sc_signal<sc_int<32> > saida;
		sc_signal<bool> N;
		sc_signal<bool> Z;
		sc_signal<sc_int<32> > a;
		sc_signal<sc_int<32> > b;
		sc_signal<sc_uint<4> > operacao;
		sc_signal<bool> reset; // reset Z e N

	
		sc_trace_file *fp;					// Create VCD file
		fp=sc_create_vcd_trace_file("wave");// open(fp), create wave.vcd file
		fp->set_time_unit(1, SC_NS);		// set tracing resolution to ns
		
		ula DUT("ula");
		
		DUT.saida(saida);
		DUT.N(N);
		DUT.Z(Z);
		DUT.a(a);
		DUT.b(b);
		DUT.operacao(operacao);
		DUT.reset(reset);
		
		stim STIM("stimulus");				// Instantiate stimulus generator
		STIM.clock(clock);
		STIM.a(a);
		STIM.b(b);
		STIM.operacao(operacao);
		STIM.reset(reset);
		
		sc_trace(fp,clock,"clock");	
		sc_trace(fp,a,"a");
		sc_trace(fp,b,"b");
		sc_trace(fp,operacao,"operacao");
		sc_trace(fp,reset,"reset");
		
		sc_start(100, SC_NS);			   	// Run simulation

		sc_close_vcd_trace_file(fp);		// close(fp)

		return 0;							// Return OK, no errors.		

}