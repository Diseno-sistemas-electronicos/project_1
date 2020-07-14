#ifndef STIM_H
#define STIM_H

#include <systemc.h>
							    
SC_MODULE(stim) {
		sc_in<bool> clock;

		sc_out<sc_uint<64> > inst;	// Instruction


  	void ps1() {	
		inst.write("0x0000000000000000");
		wait();
		
		inst.write("0x0000000000000001");
		wait();
		
		inst.write("0x2000000000000001");
		wait();

		sc_stop();							// End simulation
	}

	SC_CTOR(stim) {	 
      	SC_THREAD(ps1);						// Run ps1 only ones
		sensitive << clock.pos();
    }
};
#endif

