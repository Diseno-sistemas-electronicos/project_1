#ifndef STIM_H
#define STIM_H

#include <systemc.h>
							    
SC_MODULE(stim) {
		sc_in<bool> clock;
	
		sc_out<sc_uint<2> > seletor; 		// Select an input
		sc_out<sc_int<32> > saidaULA;		// ULA input
		sc_out<sc_int<32> > dataDM;		// DM input
		sc_out<sc_uint<8> > immediateData; 	// Immediate input


  	void ps1() {	
		seletor.write("0b00");
		saidaULA.write("0x000000000");
		dataDM.write("0x000000000");
		immediateData.write("0b00000000");
		wait();
		
		seletor.write("0b00");
		saidaULA.write("0x000000000");
		dataDM.write("0x000000000");
		immediateData.write("0b00000000");
		wait();
		
		seletor.write("0b00");
		saidaULA.write("0x000000000");
		dataDM.write("0x000000000");
		immediateData.write("0b00000000");
		wait();

		sc_stop();							// End simulation
	}

	SC_CTOR(stim) {	 
      	SC_THREAD(ps1);						// Run ps1 only ones
		sensitive << clock.pos();
    }
};
#endif

