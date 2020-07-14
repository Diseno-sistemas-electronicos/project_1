#include <systemc.h>

#include "multiplex2.cpp"
#include "stim.h"

int sc_main(int argc, char* argv[])
{
		//-- Signals --//
		//-- In --//
		sc_clock clock("clock",10,SC_NS,0.5);	// Create a clock signal
	
		sc_signal<sc_uint<2> > seletor; 		// Select an input
		sc_signal<sc_uint<9> > opd;			// ULA input
		sc_signal<sc_uint<8> > of1;			// DM input
		sc_signal<sc_uint<9> > saida;		// Out
	
	
		sc_trace_file *fp;					// Create VCD file
		fp=sc_create_vcd_trace_file("wave");// open(fp), create wave.vcd file
		fp->set_time_unit(1, SC_NS);		// set tracing resolution to ns
		
		multiplex2 DUT("multiplex2");
		
		DUT.seletor(seletor);
		DUT.opd(opd);
		DUT.of1(of1);
		DUT.saida(saida);

		
		stim STIM("stimulus");				// Instantiate stimulus generator
		STIM.clock(clock);
		STIM.seletor(seletor);
		STIM.opd(opd);
		STIM.of1(of1);

		
		sc_trace(fp,clock,"clock");	
		sc_trace(fp,seletor,"seletor");
		sc_trace(fp,opd,"opd");
		sc_trace(fp,of1,"of1");
		sc_trace(fp,saida,"saida");
		
		sc_start(100, SC_NS);			   	// Run simulation

		sc_close_vcd_trace_file(fp);		// close(fp)

		return 0;							// Return OK, no errors.		

}