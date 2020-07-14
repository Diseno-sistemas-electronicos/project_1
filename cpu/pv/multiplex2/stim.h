#ifndef STIM_H
#define STIM_H

#include <systemc.h>
							    
SC_MODULE(stim) {
		sc_in<bool> clock;

		sc_out<sc_uint<2> > seletor; 		// Select an input
		sc_out<sc_uint<9> > opd;			// ULA input
		sc_out<sc_uint<8> > of1;			// DM input


  	void ps1() {	
		seletor.write("0b00");
		opd.write("0b000000000");
		of1.write("0b00000000");
		wait();
		
		seletor.write("0b00");
		opd.write("0b000000000");
		of1.write("0b00000000");
		wait();
		
		seletor.write("0b00");
		opd.write("0b000000000");
		of1.write("0b00000000");
		wait();

		sc_stop();							// End simulation
	}

	SC_CTOR(stim) {	 
      	SC_THREAD(ps1);						// Run ps1 only ones
		sensitive << clock.pos();
    }
};
#endif

