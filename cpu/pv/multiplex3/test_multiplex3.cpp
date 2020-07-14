#include <systemc.h>

#include "multiplex3.cpp"
#include "stim.h"

int sc_main(int argc, char* argv[])
{
		//-- Signals --//
		//-- In --//
		sc_clock clock("clock",10,SC_NS,0.5);	// Create a clock signal
	
		sc_signal<sc_uint<2> > seletor; 		// Select an input
		sc_signal<sc_int<32> > saidaULA;		// ULA input
		sc_signal<sc_int<32> > dataDM;		// DM input
		sc_signal<sc_uint<8> > immediateData; 	// Immediate input
		sc_signal<sc_int<32> > saida;		// Out
	
	
		sc_trace_file *fp;					// Create VCD file
		fp=sc_create_vcd_trace_file("wave");// open(fp), create wave.vcd file
		fp->set_time_unit(1, SC_NS);		// set tracing resolution to ns
		
		multiplex3 DUT("multiplex3");
		
		DUT.seletor(seletor);
		DUT.saidaULA(saidaULA);
		DUT.dataDM(dataDM);
		DUT.immediateData(immediateData);
		DUT.saida(saida);

		
		stim STIM("stimulus");				// Instantiate stimulus generator
		STIM.clock(clock);
		STIM.seletor(seletor);
		STIM.saidaULA(saidaULA);
		STIM.dataDM(dataDM);
		STIM.immediateData(immediateData);

		
		sc_trace(fp,clock,"clock");	
		sc_trace(fp,seletor,"seletor");
		sc_trace(fp,saidaULA,"saidaULA");
		sc_trace(fp,dataDM,"dataDM");
		sc_trace(fp,immediateData,"immediateData");
		sc_trace(fp,saida,"saida");
		
		sc_start(100, SC_NS);			   	// Run simulation

		sc_close_vcd_trace_file(fp);		// close(fp)

		return 0;							// Return OK, no errors.		

}